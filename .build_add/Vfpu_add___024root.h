// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfpu_add.h for the primary calling header

#ifndef VERILATED_VFPU_ADD___024ROOT_H_
#define VERILATED_VFPU_ADD___024ROOT_H_  // guard

#include "verilated.h"


class Vfpu_add__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfpu_add___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(valid_i,0,0);
    VL_IN8(op_i,2,0);
    VL_OUT8(valid_o,0,0);
    VL_OUT8(flags_o,4,0);
    VL_OUT8(bypass_valid_o,0,0);
    VL_OUT8(cmp_lt_o,0,0);
    VL_OUT8(cmp_eq_o,0,0);
    CData/*0:0*/ fpu_add__DOT__is_pipelined_op;
    CData/*0:0*/ fpu_add__DOT__a_is_inf;
    CData/*0:0*/ fpu_add__DOT__a_is_snan;
    CData/*0:0*/ fpu_add__DOT__sign_b_eff;
    CData/*0:0*/ fpu_add__DOT__b_is_snan;
    CData/*0:0*/ fpu_add__DOT__a_ge_b_s0;
    CData/*7:0*/ fpu_add__DOT__exp_big_s0;
    CData/*4:0*/ fpu_add__DOT__algn_shift_s0;
    CData/*0:0*/ fpu_add__DOT__result_is_nan_s0;
    CData/*0:0*/ fpu_add__DOT__result_is_inf_s0;
    CData/*0:0*/ fpu_add__DOT__valid_s1;
    CData/*0:0*/ fpu_add__DOT__eff_add_s1;
    CData/*7:0*/ fpu_add__DOT__exp_big_s1;
    CData/*0:0*/ fpu_add__DOT__sign_result_s1;
    CData/*0:0*/ fpu_add__DOT__result_is_nan_s1;
    CData/*0:0*/ fpu_add__DOT__result_is_inf_s1;
    CData/*0:0*/ fpu_add__DOT__invalid_nan_in_s1;
    CData/*0:0*/ fpu_add__DOT__inf_result_sign_s1;
    CData/*4:0*/ fpu_add__DOT__nlz28_s1;
    CData/*0:0*/ fpu_add__DOT__valid_s2;
    CData/*0:0*/ fpu_add__DOT__eff_add_s2;
    CData/*4:0*/ fpu_add__DOT__nlz28_s2;
    CData/*0:0*/ fpu_add__DOT__is_exact_zero_s2;
    CData/*7:0*/ fpu_add__DOT__exp_big_s2;
    CData/*0:0*/ fpu_add__DOT__sign_result_s2;
    CData/*0:0*/ fpu_add__DOT__result_is_nan_s2;
    CData/*0:0*/ fpu_add__DOT__result_is_inf_s2;
    CData/*0:0*/ fpu_add__DOT__invalid_nan_in_s2;
    CData/*0:0*/ fpu_add__DOT__inf_result_sign_s2;
    CData/*4:0*/ fpu_add__DOT__flags_comb_s3;
    CData/*0:0*/ fpu_add__DOT__cmp_lt_comb;
    CData/*0:0*/ fpu_add__DOT__cmp_eq_comb;
    CData/*0:0*/ fpu_add__DOT__cmp_lt_hold;
    CData/*0:0*/ fpu_add__DOT__cmp_eq_hold;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(a_i,31,0);
    VL_IN(b_i,31,0);
    VL_OUT(result_o,31,0);
    VL_OUT(bypass_result_o,31,0);
    IData/*23:0*/ fpu_add__DOT__mant_big_s0;
    IData/*23:0*/ fpu_add__DOT__mant_small_s0;
    IData/*26:0*/ fpu_add__DOT__small27_shifted_raw_s0;
    IData/*26:0*/ fpu_add__DOT__big27_s1;
    IData/*26:0*/ fpu_add__DOT__small27_shifted_s1;
    IData/*27:0*/ fpu_add__DOT__valword28_s1;
    IData/*27:0*/ fpu_add__DOT__valword28_s2;
    IData/*31:0*/ fpu_add__DOT__result_comb_s3;
    IData/*31:0*/ fpu_add__DOT__bypass_result_comb;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfpu_add__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfpu_add___024root(Vfpu_add__Syms* symsp, const char* v__name);
    ~Vfpu_add___024root();
    VL_UNCOPYABLE(Vfpu_add___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
