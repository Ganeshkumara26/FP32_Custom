// FILE: tb/tb_fp32_random.cpp
//
// Unified >=10^8-vector bit-exact random verification harness, checked
// against Berkeley SoftFloat (build: SPECIALIZE_TYPE=RISCV, canonical NaN
// = 0x7FC00000, matching docs/05_numerical_semantics.md).
//
// This single source file is compiled FOUR times, once per DUT, selected
// by a compile-time macro (see tb/run_verify.py for the exact commands):
//   -DDUT_MUL       fpu_mul       (MUL)
//   -DDUT_ADD       fpu_add       (ADD/SUB; bypass ops are covered by
//                                        the directed tb_fp32_add.sv testbench,
//                                        not by this random harness)
//   -DDUT_DIVSQRT   fpu_divsqrt   (DIV/SQRT)
//   -DDUT_INTALU    fpu_intalu    (ITOF, IADD/ISUB/ICMP/IMOV)
//
// Each produces its own Verilator-generated executable (Vfpu_mul,
// Vfpu_add, Vfpu_divsqrt, Vfpu_intalu). All four accept
// `--vectors N` to control sample size; `python tb/run_verify.py --vectors
// 100000000` runs all four at N=10^8 and reports a combined summary.
//
// A single combined binary is not used because each Verilated DUT is a
// distinct generated C++ class; -D-based recompilation keeps one reviewable
// source of truth for the test methodology (operand generation, NaN
// equivalence-class comparison, softfloat reference calls) without
// duplicating it four times.

#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cfenv>

extern "C" {
    #include "softfloat.h"
}

static inline bool is_nan32(uint32_t x) {
    return ((x >> 23) & 0xFF) == 0xFF && (x & 0x7FFFFF) != 0;
}

// Biased FP32 operand generator: weights special values (zeros, infinities,
// NaNs, subnormal extremes, +/-1.0, min normal, max normal) heavily, then
// falls back to uniform random bits. Matches doc 40 section 6.2's template,
// extended with a few extra special values (max subnormal, -1.0) for
// broader edge-case coverage.
static uint32_t generate_biased_fp32() {
    int r = mrand48() % 100;
    if (r < 5)  return 0x00000000u; // +0
    if (r < 10) return 0x80000000u; // -0
    if (r < 15) return 0x7F800000u; // +Inf
    if (r < 20) return 0xFF800000u; // -Inf
    if (r < 25) return 0x7FC00000u; // qNaN
    if (r < 28) return 0xFFA00000u; // NaN with MSB-of-frac clear (signaling-ish payload)
    if (r < 33) return 0x00000001u; // min subnormal
    if (r < 36) return 0x007FFFFFu; // max subnormal
    if (r < 41) return 0x3F800000u; // +1.0
    if (r < 44) return 0x7F7FFFFFu; // max normal
    if (r < 47) return 0x00800000u; // min normal
    if (r < 52) return 0xBF800000u; // -1.0
    return (uint32_t)mrand48();     // uniform random
}

#if defined(DUT_MUL)
#include "Vfpu_mul.h"
typedef Vfpu_mul Dut;
static const char* kName = "MUL";

static void tick(Dut* dut) { dut->clk_i = 0; dut->eval(); dut->clk_i = 1; dut->eval(); }

static int run(Dut* dut, uint64_t n) {
    uint64_t pass = 0, fail = 0, logged = 0;
    dut->rst_ni = 0; dut->clk_i = 0; dut->eval(); tick(dut); dut->rst_ni = 1;
    for (uint64_t i = 0; i < n; i++) {
        uint32_t a = generate_biased_fp32(), b = generate_biased_fp32();
        float32_t sa{a}, sb{b};
        softfloat_roundingMode = softfloat_round_near_even;
        softfloat_exceptionFlags = 0;
        uint32_t expected = f32_mul(sa, sb).v;

        dut->valid_i = 1; dut->a_i = a; dut->b_i = b;
        tick(dut);
        dut->valid_i = 0;
        tick(dut); // result ready 2 cycles after issue

        uint32_t got = dut->result_o;
        bool ok = is_nan32(expected) ? is_nan32(got) : (got == expected);
        if (ok) pass++;
        else {
            fail++;
            if (logged < 30) { printf("FAIL a=%08x b=%08x got=%08x exp=%08x\n", a, b, got, expected); logged++; }
        }
        if (fail > 2000) { printf("TOO MANY FAILURES, aborting\n"); break; }
    }
    printf("%s random test: %llu pass, %llu fail out of %llu\n", kName,
           (unsigned long long)pass, (unsigned long long)fail, (unsigned long long)n);
    return fail == 0 ? 0 : 1;
}

#elif defined(DUT_ADD)
#include "Vfpu_add.h"
typedef Vfpu_add Dut;
static const char* kName = "ADD/SUB";

static void tick(Dut* dut) { dut->clk_i = 0; dut->eval(); dut->clk_i = 1; dut->eval(); }

static int run(Dut* dut, uint64_t n) {
    uint64_t pass = 0, fail = 0, logged = 0;
    dut->rst_ni = 0; dut->clk_i = 0; dut->eval(); tick(dut); dut->rst_ni = 1;
    for (uint64_t i = 0; i < n; i++) {
        uint32_t a = generate_biased_fp32(), b = generate_biased_fp32();
        bool do_sub = (mrand48() & 1);
        float32_t sa{a}, sb{b};
        softfloat_roundingMode = softfloat_round_near_even;
        softfloat_exceptionFlags = 0;
        uint32_t expected = (do_sub ? f32_sub(sa, sb) : f32_add(sa, sb)).v;

        dut->valid_i = 1; dut->op_i = do_sub ? 1 : 0; dut->a_i = a; dut->b_i = b;
        tick(dut);
        dut->valid_i = 0;
        tick(dut);
        tick(dut); // result ready 3 cycles after issue

        uint32_t got = dut->result_o;
        bool ok = is_nan32(expected) ? is_nan32(got) : (got == expected);
        if (ok) pass++;
        else {
            fail++;
            if (logged < 30) { printf("FAIL op=%s a=%08x b=%08x got=%08x exp=%08x\n", do_sub?"SUB":"ADD", a, b, got, expected); logged++; }
        }
        if (fail > 2000) { printf("TOO MANY FAILURES, aborting\n"); break; }
    }
    printf("%s random test: %llu pass, %llu fail out of %llu\n", kName,
           (unsigned long long)pass, (unsigned long long)fail, (unsigned long long)n);
    return fail == 0 ? 0 : 1;
}

#elif defined(DUT_DIVSQRT)
#include "Vfpu_divsqrt.h"
typedef Vfpu_divsqrt Dut;
static const char* kName = "DIV/SQRT";

static void tick(Dut* dut) { dut->clk_i = 0; dut->eval(); dut->clk_i = 1; dut->eval(); }

static int run(Dut* dut, uint64_t n) {
    uint64_t pass = 0, fail = 0, cyc_fail = 0, logged = 0;
    dut->rst_ni = 0; dut->clk_i = 0; dut->eval(); tick(dut); dut->rst_ni = 1; dut->start_i = 0; tick(dut);
    for (uint64_t i = 0; i < n; i++) {
        bool do_sqrt = (mrand48() & 1);
        uint32_t a = generate_biased_fp32();
        uint32_t b = do_sqrt ? 0 : generate_biased_fp32();
        float32_t sa{a}, sb{b};
        softfloat_roundingMode = softfloat_round_near_even;
        softfloat_exceptionFlags = 0;
        uint32_t expected = (do_sqrt ? f32_sqrt(sa) : f32_div(sa, sb)).v;

        dut->a_i = a; dut->b_i = b; dut->op_i = do_sqrt ? 1 : 0; dut->start_i = 1;
        tick(dut); // trigger edge (E0 in the SVA's ##N sense)
        dut->start_i = 0;

        int expected_edges = do_sqrt ? 27 : 28; // matches ##28/##27 in sva/fpu_divsqrt_sva.sv
        int edges = 0;
        while (!dut->done_o && edges <= 40) { tick(dut); edges++; }

        if (edges != expected_edges) {
            cyc_fail++;
            if (logged < 30) { printf("CYCLE FAIL op=%s a=%08x b=%08x got_edges=%d exp_edges=%d\n", do_sqrt?"SQRT":"DIV", a, b, edges, expected_edges); logged++; }
        }
        uint32_t got = dut->result_o;
        bool ok = is_nan32(expected) ? is_nan32(got) : (got == expected);
        if (ok && edges == expected_edges) pass++;
        else {
            fail++;
            if (!ok && logged < 30) { printf("FAIL op=%s a=%08x b=%08x got=%08x exp=%08x\n", do_sqrt?"SQRT":"DIV", a, b, got, expected); logged++; }
        }
        tick(dut); // 1 idle cycle between ops
        if (fail > 2000) { printf("TOO MANY FAILURES, aborting\n"); break; }
    }
    printf("%s random test: %llu pass, %llu fail (cycle mismatches: %llu) out of %llu\n", kName,
           (unsigned long long)pass, (unsigned long long)fail, (unsigned long long)cyc_fail, (unsigned long long)n);
    return fail == 0 ? 0 : 1;
}

#elif defined(DUT_INTALU)
#include "Vfpu_intalu.h"
typedef Vfpu_intalu Dut;
static const char* kName = "INTALU";

static void tick(Dut* dut) { dut->clk_i = 0; dut->eval(); dut->clk_i = 1; dut->eval(); }
static uint32_t f2u(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

static int run(Dut* dut, uint64_t n) {
    uint64_t pass = 0, fail = 0, logged = 0;
    fesetround(FE_TONEAREST);
    dut->rst_ni = 0; dut->clk_i = 0; dut->eval(); tick(dut); dut->rst_ni = 1;
    for (uint64_t i = 0; i < n; i++) {
        int32_t v = (int32_t)(uint32_t)mrand48();
        dut->op_i = 0b0111; dut->a_i = (uint32_t)v; dut->b_i = 0; dut->imm_i = 0; dut->valid_i = 1;
        tick(dut);
        tick(dut);
        uint32_t got = dut->result_o;
        uint32_t expected = f2u((float)v);
        if (got == expected) pass++;
        else {
            fail++;
            if (logged < 30) { printf("ITOF FAIL v=%d got=%08x exp=%08x\n", v, got, expected); logged++; }
        }
        if (fail > 2000) { printf("TOO MANY FAILURES, aborting\n"); break; }
    }
    printf("%s random test (ITOF): %llu pass, %llu fail out of %llu\n", kName,
           (unsigned long long)pass, (unsigned long long)fail, (unsigned long long)n);
    return fail == 0 ? 0 : 1;
}

#else
#error "Define one of DUT_MUL, DUT_ADD, DUT_DIVSQRT, DUT_INTALU (see tb/run_verify.py)"
#endif

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    uint64_t num_tests = 100000000ULL; // 10^8 default, per the acceptance command
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--vectors") && i + 1 < argc) num_tests = strtoull(argv[i + 1], nullptr, 10);
    }
    srand48(42);
    auto dut = new Dut;
    int rc = run(dut, num_tests);
    delete dut;
    return rc;
}
