#!/usr/bin/env python3
"""
run_verify.py — verification runner for the FPU project
(fpu_mul, fpu_add, fpu_divsqrt, fpu_intalu).

Usage:
    python tb/run_verify.py [--vectors N] [--skip-directed] [--skip-random]
                             [--modules MUL ADD DIVSQRT INTALU]

Runs two independent layers of verification:
  1. RANDOM (primary acceptance criterion): builds each RTL module with
     Verilator, links against Berkeley SoftFloat, and runs N random vectors
     per module, checking bit-exactness against SoftFloat's reference
     result.
  2. DIRECTED (secondary layer): builds and runs the hand-written
     SystemVerilog directed testbenches (tb/tb_fpu_*.sv) under Icarus
     Verilog, covering the special-case tables in
     docs/06_verification_plan.md plus the comparison/select operation
     family (which the random layer does not cover, since Berkeley
     SoftFloat doesn't implement those operations).

Requires: verilator, iverilog, g++, and a built Berkeley SoftFloat library.
If the library isn't found under --softfloat-dir, this script clones and
builds it (requires network access to github.com).

Exit code 0 iff every module passes every layer that was run.
"""
import argparse
import os
import subprocess
import sys
import shutil
import time

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RTL_DIR = os.path.join(REPO_ROOT, "rtl")
TB_DIR = os.path.join(REPO_ROOT, "tb")

MODULES = ["MUL", "ADD", "DIVSQRT", "INTALU"]
MODULE_TOP = {
    "MUL": "fpu_mul",
    "ADD": "fpu_add",
    "DIVSQRT": "fpu_divsqrt",
    "INTALU": "fpu_intalu",
}
TB_NAME = {
    "MUL": "tb_fpu_mul.sv",
    "ADD": "tb_fpu_add.sv",
    "DIVSQRT": "tb_fpu_divsqrt.sv",
    "INTALU": "tb_fpu_intalu.sv",
}


def run(cmd, cwd=None, check=True):
    print(f"    $ {' '.join(cmd)}")
    result = subprocess.run(cmd, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if result.returncode != 0 and check:
        print(result.stdout)
        raise RuntimeError(f"Command failed ({result.returncode}): {' '.join(cmd)}")
    return result


def ensure_softfloat(softfloat_dir):
    lib = os.path.join(softfloat_dir, "build", "Linux-x86_64-GCC", "softfloat.a")
    if os.path.exists(lib):
        return softfloat_dir, lib
    print(f"[setup] Berkeley SoftFloat not found at {lib}; cloning + building...")
    parent = os.path.dirname(softfloat_dir)
    os.makedirs(parent, exist_ok=True)
    if not os.path.exists(softfloat_dir):
        run(["git", "clone", "--depth", "1",
             "https://github.com/ucb-bar/berkeley-softfloat-3.git", softfloat_dir])
    build_dir = os.path.join(softfloat_dir, "build", "Linux-x86_64-GCC")
    run(["make", "SPECIALIZE_TYPE=RISCV"], cwd=build_dir)
    if not os.path.exists(lib):
        raise RuntimeError("SoftFloat build did not produce softfloat.a")
    return softfloat_dir, lib


def build_verilator(mod, softfloat_dir, obj_dir):
    top = MODULE_TOP[mod]
    sf_build = os.path.join(softfloat_dir, "build", "Linux-x86_64-GCC")
    sf_inc = os.path.join(softfloat_dir, "source", "include")
    sf_lib = os.path.join(sf_build, "softfloat.a")
    if os.path.exists(obj_dir):
        shutil.rmtree(obj_dir)
    os.makedirs(obj_dir, exist_ok=True)
    run([
        "verilator", "--cc", "--exe", "--build", "-j", "4",
        "-CFLAGS", f"-DDUT_{mod} -I{sf_build} -I{sf_inc}",
        "-LDFLAGS", sf_lib,
        "-Wno-fatal",
        "--top-module", top,
        "-Mdir", obj_dir,
        os.path.join(RTL_DIR, f"{top}.sv"),
        os.path.join(TB_DIR, "tb_fpu_random.cpp"),
    ])
    return os.path.join(obj_dir, f"V{top}")


def run_random(mod, exe, vectors):
    t0 = time.time()
    result = run([exe, "--vectors", str(vectors)], check=False)
    dt = time.time() - t0
    out = result.stdout
    print(out.strip())
    ok = result.returncode == 0
    return ok, dt, out


def run_directed(mod):
    top = MODULE_TOP[mod]
    tb_path = os.path.join(TB_DIR, TB_NAME[mod])
    vvp_path = os.path.join(REPO_ROOT, f"{TB_NAME[mod]}.vvp")
    run(["iverilog", "-g2012", "-o", vvp_path,
         os.path.join(RTL_DIR, f"{top}.sv"), tb_path], check=True)
    result = run(["vvp", vvp_path], check=False)
    print(result.stdout.strip())
    return result.returncode == 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--vectors", type=int, default=5_000_000,
                     help="Random vectors per module (default 5,000,000)")
    ap.add_argument("--softfloat-dir", default=os.path.expanduser("~/berkeley-softfloat-3"))
    ap.add_argument("--skip-directed", action="store_true")
    ap.add_argument("--skip-random", action="store_true")
    ap.add_argument("--modules", nargs="+", default=MODULES, choices=MODULES,
                     help="Subset of modules to test (default: all)")
    args = ap.parse_args()

    print("=" * 72)
    print("FPU PROJECT VERIFICATION")
    print("=" * 72)

    overall_ok = True
    summary = []

    if not args.skip_random:
        softfloat_dir, sf_lib = ensure_softfloat(args.softfloat_dir)
        print(f"[setup] Using SoftFloat: {sf_lib}\n")

        for mod in args.modules:
            print(f"--- RANDOM: {mod} ({args.vectors:,} vectors) ---")
            obj_dir = os.path.join(REPO_ROOT, f".build_{mod.lower()}")
            exe = build_verilator(mod, softfloat_dir, obj_dir)
            ok, dt, out = run_random(mod, exe, args.vectors)
            overall_ok &= ok
            summary.append((f"RANDOM/{mod}", ok, f"{args.vectors:,} vectors in {dt:.1f}s"))
            print()

    if not args.skip_directed:
        for mod in args.modules:
            print(f"--- DIRECTED: {mod} ---")
            ok = run_directed(mod)
            overall_ok &= ok
            summary.append((f"DIRECTED/{mod}", ok, ""))
            print()

    print("=" * 72)
    print("SUMMARY")
    print("=" * 72)
    for name, ok, note in summary:
        status = "PASS" if ok else "FAIL"
        print(f"  [{status}] {name:24s} {note}")
    print("=" * 72)
    print("RESULT: " + ("ALL TESTS PASSED" if overall_ok else "FAILURES DETECTED"))
    print("=" * 72)

    sys.exit(0 if overall_ok else 1)


if __name__ == "__main__":
    main()
