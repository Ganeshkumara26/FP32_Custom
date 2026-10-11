// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfpu_divsqrt.h for the primary calling header

#ifndef VERILATED_VFPU_DIVSQRT___024ROOT_H_
#define VERILATED_VFPU_DIVSQRT___024ROOT_H_  // guard

#include "verilated.h"


class Vfpu_divsqrt__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfpu_divsqrt___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_i,0,0);
        VL_IN8(rst_ni,0,0);
        VL_IN8(start_i,0,0);
        VL_IN8(op_i,0,0);
        VL_OUT8(busy_o,0,0);
        VL_OUT8(done_o,0,0);
        VL_OUT8(flags_o,4,0);
        CData/*0:0*/ fpu_divsqrt__DOT__a_is_inf;
        CData/*0:0*/ fpu_divsqrt__DOT__b_is_inf;
        CData/*0:0*/ fpu_divsqrt__DOT__a_is_nan;
        CData/*0:0*/ fpu_divsqrt__DOT__a_is_snan;
        CData/*0:0*/ fpu_divsqrt__DOT__b_is_snan;
        CData/*0:0*/ fpu_divsqrt__DOT__a_is_zero_raw;
        CData/*0:0*/ fpu_divsqrt__DOT__b_is_zero_raw;
        CData/*0:0*/ fpu_divsqrt__DOT__div_result_is_nan;
        CData/*0:0*/ fpu_divsqrt__DOT__div_result_is_inf;
        CData/*0:0*/ fpu_divsqrt__DOT__div_dbz;
        CData/*0:0*/ fpu_divsqrt__DOT__div_result_is_zero;
        CData/*0:0*/ fpu_divsqrt__DOT__div_special_sign;
        CData/*0:0*/ fpu_divsqrt__DOT__sqrt_result_is_nan;
        CData/*0:0*/ fpu_divsqrt__DOT__sqrt_passthrough;
        CData/*0:0*/ fpu_divsqrt__DOT__busy_r;
        CData/*0:0*/ fpu_divsqrt__DOT__done_r;
        CData/*4:0*/ fpu_divsqrt__DOT__cnt_r;
        CData/*4:0*/ fpu_divsqrt__DOT__total_r;
        CData/*0:0*/ fpu_divsqrt__DOT__finalize_r;
        CData/*0:0*/ fpu_divsqrt__DOT__op_r;
        CData/*0:0*/ fpu_divsqrt__DOT__sign_result_r;
        CData/*0:0*/ fpu_divsqrt__DOT__special_active_r;
        CData/*4:0*/ fpu_divsqrt__DOT__special_flags_r;
        CData/*4:0*/ fpu_divsqrt__DOT__flags_r;
        CData/*0:0*/ fpu_divsqrt__DOT__setup_div_ge;
        CData/*0:0*/ fpu_divsqrt__DOT__div_bit;
        CData/*4:0*/ fpu_divsqrt__DOT__final_flags_comb;
        CData/*4:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz;
        CData/*4:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ fpu_divsqrt__DOT__exp_result_r;
        VL_IN(a_i,31,0);
        VL_IN(b_i,31,0);
        VL_OUT(result_o,31,0);
        IData/*31:0*/ fpu_divsqrt__DOT__special_result_r;
        IData/*25:0*/ fpu_divsqrt__DOT__div_R_r;
        IData/*23:0*/ fpu_divsqrt__DOT__div_B_r;
        IData/*26:0*/ fpu_divsqrt__DOT__div_Q_r;
        IData/*29:0*/ fpu_divsqrt__DOT__sqrt_R_r;
        IData/*25:0*/ fpu_divsqrt__DOT__sqrt_Q_r;
        IData/*31:0*/ fpu_divsqrt__DOT__result_r;
        IData/*25:0*/ fpu_divsqrt__DOT__div_R_next;
        IData/*29:0*/ fpu_divsqrt__DOT__sqrt_R_next;
        IData/*25:0*/ fpu_divsqrt__DOT__sqrt_Q_next;
        IData/*31:0*/ fpu_divsqrt__DOT__final_result_comb;
        IData/*23:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp;
        IData/*23:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp;
        IData/*31:0*/ __VactIterCount;
        QData/*34:0*/ fpu_divsqrt__DOT__norm_a;
        QData/*34:0*/ fpu_divsqrt__DOT__norm_b;
        QData/*53:0*/ fpu_divsqrt__DOT__sqrt_rad_r;
        QData/*53:0*/ fpu_divsqrt__DOT__setup_sqrt_rad_full;
        QData/*34:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r;
    };
    struct {
        QData/*34:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfpu_divsqrt__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfpu_divsqrt___024root(Vfpu_divsqrt__Syms* symsp, const char* v__name);
    ~Vfpu_divsqrt___024root();
    VL_UNCOPYABLE(Vfpu_divsqrt___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
