// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfpu_mul.h for the primary calling header

#ifndef VERILATED_VFPU_MUL___024ROOT_H_
#define VERILATED_VFPU_MUL___024ROOT_H_  // guard

#include "verilated.h"


class Vfpu_mul__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfpu_mul___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(valid_i,0,0);
    VL_OUT8(valid_o,0,0);
    VL_OUT8(flags_o,4,0);
    CData/*0:0*/ fpu_mul__DOT__a_is_zero;
    CData/*0:0*/ fpu_mul__DOT__b_is_zero;
    CData/*0:0*/ fpu_mul__DOT__a_is_inf;
    CData/*0:0*/ fpu_mul__DOT__b_is_inf;
    CData/*0:0*/ fpu_mul__DOT__a_is_snan;
    CData/*0:0*/ fpu_mul__DOT__b_is_snan;
    CData/*7:0*/ fpu_mul__DOT__exp_a;
    CData/*7:0*/ fpu_mul__DOT__exp_b;
    CData/*0:0*/ fpu_mul__DOT__result_is_nan_s0;
    CData/*0:0*/ fpu_mul__DOT__result_is_inf_s0;
    CData/*0:0*/ fpu_mul__DOT__result_is_zero_s0;
    CData/*0:0*/ fpu_mul__DOT__valid_s1;
    CData/*0:0*/ fpu_mul__DOT__sign_r_s1;
    CData/*0:0*/ fpu_mul__DOT__result_is_nan_s1;
    CData/*0:0*/ fpu_mul__DOT__result_is_inf_s1;
    CData/*0:0*/ fpu_mul__DOT__result_is_zero_s1;
    CData/*0:0*/ fpu_mul__DOT__invalid_s1;
    CData/*4:0*/ fpu_mul__DOT__flags_comb_s2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    SData/*10:0*/ fpu_mul__DOT__exp_sum_s1;
    VL_IN(a_i,31,0);
    VL_IN(b_i,31,0);
    VL_OUT(result_o,31,0);
    IData/*23:0*/ fpu_mul__DOT__mant_a;
    IData/*23:0*/ fpu_mul__DOT__mant_b;
    IData/*31:0*/ fpu_mul__DOT__result_comb_s2;
    IData/*31:0*/ __VactIterCount;
    QData/*47:0*/ fpu_mul__DOT__prod_s1;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfpu_mul__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfpu_mul___024root(Vfpu_mul__Syms* symsp, const char* v__name);
    ~Vfpu_mul___024root();
    VL_UNCOPYABLE(Vfpu_mul___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
