// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_add.h for the primary calling header

#include "Vfpu_add__pch.h"
#include "Vfpu_add___024root.h"

VL_ATTR_COLD void Vfpu_add___024root___eval_static(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfpu_add___024root___eval_initial(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = vlSelf->clk_i;
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = vlSelf->rst_ni;
}

VL_ATTR_COLD void Vfpu_add___024root___eval_final(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__stl(Vfpu_add___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfpu_add___024root___eval_phase__stl(Vfpu_add___024root* vlSelf);

VL_ATTR_COLD void Vfpu_add___024root___eval_settle(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vfpu_add___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_add.sv", 22, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfpu_add___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__stl(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpu_add___024root___stl_sequent__TOP__0(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ fpu_add__DOT__exp_a_raw;
    fpu_add__DOT__exp_a_raw = 0;
    IData/*22:0*/ fpu_add__DOT__frac_a;
    fpu_add__DOT__frac_a = 0;
    CData/*0:0*/ fpu_add__DOT__a_is_zero;
    fpu_add__DOT__a_is_zero = 0;
    CData/*0:0*/ fpu_add__DOT__a_is_nan;
    fpu_add__DOT__a_is_nan = 0;
    CData/*0:0*/ fpu_add__DOT__a_is_sub;
    fpu_add__DOT__a_is_sub = 0;
    CData/*7:0*/ fpu_add__DOT__exp_b_raw;
    fpu_add__DOT__exp_b_raw = 0;
    IData/*22:0*/ fpu_add__DOT__frac_b;
    fpu_add__DOT__frac_b = 0;
    CData/*0:0*/ fpu_add__DOT__b_is_zero;
    fpu_add__DOT__b_is_zero = 0;
    CData/*0:0*/ fpu_add__DOT__b_is_inf;
    fpu_add__DOT__b_is_inf = 0;
    CData/*0:0*/ fpu_add__DOT__b_is_nan;
    fpu_add__DOT__b_is_nan = 0;
    CData/*0:0*/ fpu_add__DOT__b_is_sub;
    fpu_add__DOT__b_is_sub = 0;
    IData/*23:0*/ fpu_add__DOT__mant_a;
    fpu_add__DOT__mant_a = 0;
    IData/*23:0*/ fpu_add__DOT__mant_b;
    fpu_add__DOT__mant_b = 0;
    CData/*7:0*/ fpu_add__DOT__exp_a_eff;
    fpu_add__DOT__exp_a_eff = 0;
    CData/*7:0*/ fpu_add__DOT__exp_b_eff;
    fpu_add__DOT__exp_b_eff = 0;
    SData/*8:0*/ fpu_add__DOT__exp_diff9_s0;
    fpu_add__DOT__exp_diff9_s0 = 0;
    CData/*0:0*/ fpu_add__DOT__any_nan_s0;
    fpu_add__DOT__any_nan_s0 = 0;
    CData/*0:0*/ fpu_add__DOT__inf_opp_sign_s0;
    fpu_add__DOT__inf_opp_sign_s0 = 0;
    IData/*27:0*/ fpu_add__DOT__shifted28_s3;
    fpu_add__DOT__shifted28_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__sticky_norm_s3;
    fpu_add__DOT__sticky_norm_s3 = 0;
    SData/*11:0*/ fpu_add__DOT__tent_exp_s3;
    fpu_add__DOT__tent_exp_s3 = 0;
    CData/*6:0*/ fpu_add__DOT__subshift_s3;
    fpu_add__DOT__subshift_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__is_subnormal_path_s3;
    fpu_add__DOT__is_subnormal_path_s3 = 0;
    IData/*25:0*/ fpu_add__DOT__wide_shifted_s3;
    fpu_add__DOT__wide_shifted_s3 = 0;
    IData/*23:0*/ fpu_add__DOT__mant24_pre_s3;
    fpu_add__DOT__mant24_pre_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__guard_pre_s3;
    fpu_add__DOT__guard_pre_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__round_pre_s3;
    fpu_add__DOT__round_pre_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__sticky_pre_s3;
    fpu_add__DOT__sticky_pre_s3 = 0;
    IData/*24:0*/ fpu_add__DOT__mant25_s3;
    fpu_add__DOT__mant25_s3 = 0;
    SData/*8:0*/ fpu_add__DOT__exp_final9_s3;
    fpu_add__DOT__exp_final9_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__inexact_s3;
    fpu_add__DOT__inexact_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__overflow_s3;
    fpu_add__DOT__overflow_s3 = 0;
    IData/*31:0*/ fpu_add__DOT__computed_result_s3;
    fpu_add__DOT__computed_result_s3 = 0;
    CData/*4:0*/ fpu_add__DOT__computed_flags_s3;
    fpu_add__DOT__computed_flags_s3 = 0;
    CData/*0:0*/ fpu_add__DOT__a_nan_c;
    fpu_add__DOT__a_nan_c = 0;
    CData/*0:0*/ fpu_add__DOT__b_nan_c;
    fpu_add__DOT__b_nan_c = 0;
    CData/*0:0*/ fpu_add__DOT__mag_lt_c;
    fpu_add__DOT__mag_lt_c = 0;
    CData/*0:0*/ fpu_add__DOT__mag_eq_c;
    fpu_add__DOT__mag_eq_c = 0;
    CData/*0:0*/ fpu_add__DOT____VdfgExtracted_h6f67c843__0;
    fpu_add__DOT____VdfgExtracted_h6f67c843__0 = 0;
    CData/*0:0*/ fpu_add__DOT____VdfgExtracted_h96747cd1__0;
    fpu_add__DOT____VdfgExtracted_h96747cd1__0 = 0;
    CData/*0:0*/ fpu_add__DOT____VdfgExtracted_h6fb5d5e2__0;
    fpu_add__DOT____VdfgExtracted_h6fb5d5e2__0 = 0;
    CData/*4:0*/ __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout;
    __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0;
    IData/*27:0*/ __Vfunc_fpu_add__DOT__lzc28__0__v;
    __Vfunc_fpu_add__DOT__lzc28__0__v = 0;
    // Body
    vlSelf->fpu_add__DOT__is_pipelined_op = ((0U == (IData)(vlSelf->op_i)) 
                                             | (1U 
                                                == (IData)(vlSelf->op_i)));
    vlSelf->cmp_lt_o = vlSelf->fpu_add__DOT__cmp_lt_hold;
    vlSelf->cmp_eq_o = vlSelf->fpu_add__DOT__cmp_eq_hold;
    vlSelf->fpu_add__DOT__valword28_s1 = (0xfffffffU 
                                          & ((IData)(vlSelf->fpu_add__DOT__eff_add_s1)
                                              ? (vlSelf->fpu_add__DOT__big27_s1 
                                                 + vlSelf->fpu_add__DOT__small27_shifted_s1)
                                              : (0x7ffffffU 
                                                 & (vlSelf->fpu_add__DOT__big27_s1 
                                                    - vlSelf->fpu_add__DOT__small27_shifted_s1))));
    vlSelf->fpu_add__DOT__sign_b_eff = (1U & ((1U == (IData)(vlSelf->op_i))
                                               ? (~ 
                                                  (vlSelf->b_i 
                                                   >> 0x1fU))
                                               : (vlSelf->b_i 
                                                  >> 0x1fU)));
    fpu_add__DOT__mag_lt_c = ((0x7fffffffU & vlSelf->a_i) 
                              < (0x7fffffffU & vlSelf->b_i));
    fpu_add__DOT__mag_eq_c = ((0x7fffffffU & vlSelf->a_i) 
                              == (0x7fffffffU & vlSelf->b_i));
    fpu_add__DOT____VdfgExtracted_h96747cd1__0 = ((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelf->a_i)) 
                                                  & (0U 
                                                     == 
                                                     (0x7fffffffU 
                                                      & vlSelf->b_i)));
    fpu_add__DOT__a_nan_c = (IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSelf->a_i)) 
                                     & (0U != (0x7fffffU 
                                               & vlSelf->a_i))));
    fpu_add__DOT__b_nan_c = (IData)(((0x7f800000U == 
                                      (0x7f800000U 
                                       & vlSelf->b_i)) 
                                     & (0U != (0x7fffffU 
                                               & vlSelf->b_i))));
    fpu_add__DOT__exp_a_raw = (0xffU & (vlSelf->a_i 
                                        >> 0x17U));
    fpu_add__DOT__frac_a = (0x7fffffU & vlSelf->a_i);
    fpu_add__DOT__a_is_zero = ((0U == (IData)(fpu_add__DOT__exp_a_raw)) 
                               & (0U == fpu_add__DOT__frac_a));
    vlSelf->fpu_add__DOT__a_is_inf = ((0xffU == (IData)(fpu_add__DOT__exp_a_raw)) 
                                      & (0U == fpu_add__DOT__frac_a));
    fpu_add__DOT__a_is_nan = ((0xffU == (IData)(fpu_add__DOT__exp_a_raw)) 
                              & (0U != fpu_add__DOT__frac_a));
    vlSelf->fpu_add__DOT__a_is_snan = ((IData)(fpu_add__DOT__a_is_nan) 
                                       & (~ (fpu_add__DOT__frac_a 
                                             >> 0x16U)));
    fpu_add__DOT__a_is_sub = ((0U == (IData)(fpu_add__DOT__exp_a_raw)) 
                              & (0U != fpu_add__DOT__frac_a));
    fpu_add__DOT__exp_b_raw = (0xffU & (vlSelf->b_i 
                                        >> 0x17U));
    fpu_add__DOT__frac_b = (0x7fffffU & vlSelf->b_i);
    fpu_add__DOT__b_is_zero = ((0U == (IData)(fpu_add__DOT__exp_b_raw)) 
                               & (0U == fpu_add__DOT__frac_b));
    fpu_add__DOT__b_is_inf = ((0xffU == (IData)(fpu_add__DOT__exp_b_raw)) 
                              & (0U == fpu_add__DOT__frac_b));
    fpu_add__DOT__b_is_nan = ((0xffU == (IData)(fpu_add__DOT__exp_b_raw)) 
                              & (0U != fpu_add__DOT__frac_b));
    vlSelf->fpu_add__DOT__b_is_snan = ((IData)(fpu_add__DOT__b_is_nan) 
                                       & (~ (fpu_add__DOT__frac_b 
                                             >> 0x16U)));
    fpu_add__DOT__b_is_sub = ((0U == (IData)(fpu_add__DOT__exp_b_raw)) 
                              & (0U != fpu_add__DOT__frac_b));
    fpu_add__DOT__shifted28_s3 = (0xfffffffU & (vlSelf->fpu_add__DOT__valword28_s2 
                                                << (IData)(vlSelf->fpu_add__DOT__nlz28_s2)));
    fpu_add__DOT__tent_exp_s3 = (0xfffU & (((IData)(1U) 
                                            + (IData)(vlSelf->fpu_add__DOT__exp_big_s2)) 
                                           - (IData)(vlSelf->fpu_add__DOT__nlz28_s2)));
    __Vfunc_fpu_add__DOT__lzc28__0__v = vlSelf->fpu_add__DOT__valword28_s1;
    __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x1cU;
    if ((0x8000000U & __Vfunc_fpu_add__DOT__lzc28__0__v)) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x1aU) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 1U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x19U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 2U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x18U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 3U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x17U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 4U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x16U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 5U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x15U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 6U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x14U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 7U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x13U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 8U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x12U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 9U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x11U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0xaU;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0x10U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0xbU;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0xfU) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0xcU;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0xeU) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0xdU;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0xdU) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0xeU;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0xcU) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0xfU;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0xbU) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x10U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 0xaU) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x11U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 9U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x12U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 8U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x13U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 7U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x14U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 6U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x15U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 5U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x16U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 4U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x17U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 3U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x18U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 2U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x19U;
    }
    if (((__Vfunc_fpu_add__DOT__lzc28__0__v >> 1U) 
         & (0x1cU == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x1aU;
    }
    if ((__Vfunc_fpu_add__DOT__lzc28__0__v & (0x1cU 
                                              == (IData)(__Vfunc_fpu_add__DOT__lzc28__0__Vfuncout)))) {
        __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0x1bU;
    }
    vlSelf->fpu_add__DOT__nlz28_s1 = __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout;
    fpu_add__DOT____VdfgExtracted_h6fb5d5e2__0 = ((IData)(fpu_add__DOT__a_nan_c) 
                                                  & (IData)(fpu_add__DOT__b_nan_c));
    fpu_add__DOT____VdfgExtracted_h6f67c843__0 = ((IData)(fpu_add__DOT__a_nan_c) 
                                                  | (IData)(fpu_add__DOT__b_nan_c));
    fpu_add__DOT__mant_a = ((IData)(fpu_add__DOT__a_is_zero)
                             ? 0U : ((IData)(fpu_add__DOT__a_is_sub)
                                      ? fpu_add__DOT__frac_a
                                      : (0x800000U 
                                         | fpu_add__DOT__frac_a)));
    fpu_add__DOT__exp_a_eff = (((IData)(fpu_add__DOT__a_is_zero) 
                                | (IData)(fpu_add__DOT__a_is_sub))
                                ? 1U : (IData)(fpu_add__DOT__exp_a_raw));
    fpu_add__DOT__any_nan_s0 = ((IData)(fpu_add__DOT__a_is_nan) 
                                | (IData)(fpu_add__DOT__b_is_nan));
    fpu_add__DOT__inf_opp_sign_s0 = (((IData)(vlSelf->fpu_add__DOT__a_is_inf) 
                                      & (IData)(fpu_add__DOT__b_is_inf)) 
                                     & ((vlSelf->a_i 
                                         >> 0x1fU) 
                                        != (IData)(vlSelf->fpu_add__DOT__sign_b_eff)));
    vlSelf->fpu_add__DOT__result_is_nan_s0 = ((IData)(fpu_add__DOT__any_nan_s0) 
                                              | (IData)(fpu_add__DOT__inf_opp_sign_s0));
    vlSelf->fpu_add__DOT__result_is_inf_s0 = ((~ (IData)(vlSelf->fpu_add__DOT__result_is_nan_s0)) 
                                              & ((IData)(vlSelf->fpu_add__DOT__a_is_inf) 
                                                 | (IData)(fpu_add__DOT__b_is_inf)));
    fpu_add__DOT__mant_b = ((IData)(fpu_add__DOT__b_is_zero)
                             ? 0U : ((IData)(fpu_add__DOT__b_is_sub)
                                      ? fpu_add__DOT__frac_b
                                      : (0x800000U 
                                         | fpu_add__DOT__frac_b)));
    fpu_add__DOT__exp_b_eff = (((IData)(fpu_add__DOT__b_is_zero) 
                                | (IData)(fpu_add__DOT__b_is_sub))
                                ? 1U : (IData)(fpu_add__DOT__exp_b_raw));
    fpu_add__DOT__sticky_norm_s3 = (1U & ((fpu_add__DOT__shifted28_s3 
                                           >> 1U) | 
                                          (vlSelf->fpu_add__DOT__valword28_s2 
                                           << (IData)(vlSelf->fpu_add__DOT__nlz28_s2))));
    fpu_add__DOT__subshift_s3 = (VL_LTS_III(12, 0U, (IData)(fpu_add__DOT__tent_exp_s3))
                                  ? 0U : (VL_LTS_III(12, 0x26U, 
                                                     (0xfffU 
                                                      & ((IData)(1U) 
                                                         - (IData)(fpu_add__DOT__tent_exp_s3))))
                                           ? 0x26U : 
                                          (0x7fU & 
                                           ((IData)(1U) 
                                            - (IData)(fpu_add__DOT__tent_exp_s3)))));
    fpu_add__DOT__is_subnormal_path_s3 = (VL_GTS_III(12, 0xffU, (IData)(fpu_add__DOT__tent_exp_s3)) 
                                          & VL_GTES_III(12, 0U, (IData)(fpu_add__DOT__tent_exp_s3)));
    vlSelf->fpu_add__DOT__cmp_eq_comb = ((1U & (~ (IData)(fpu_add__DOT____VdfgExtracted_h6f67c843__0))) 
                                         && ((IData)(fpu_add__DOT____VdfgExtracted_h96747cd1__0) 
                                             || (((vlSelf->a_i 
                                                   >> 0x1fU) 
                                                  == 
                                                  (vlSelf->b_i 
                                                   >> 0x1fU)) 
                                                 && (IData)(fpu_add__DOT__mag_eq_c))));
    vlSelf->fpu_add__DOT__cmp_lt_comb = ((1U & (~ (IData)(fpu_add__DOT____VdfgExtracted_h6f67c843__0))) 
                                         && ((1U & 
                                              (~ (IData)(fpu_add__DOT____VdfgExtracted_h96747cd1__0))) 
                                             && (1U 
                                                 & (((vlSelf->a_i 
                                                      >> 0x1fU) 
                                                     != 
                                                     (vlSelf->b_i 
                                                      >> 0x1fU))
                                                     ? 
                                                    (vlSelf->a_i 
                                                     >> 0x1fU)
                                                     : 
                                                    ((vlSelf->a_i 
                                                      >> 0x1fU)
                                                      ? 
                                                     (~ 
                                                      ((IData)(fpu_add__DOT__mag_eq_c) 
                                                       | (IData)(fpu_add__DOT__mag_lt_c)))
                                                      : (IData)(fpu_add__DOT__mag_lt_c))))));
    vlSelf->fpu_add__DOT__a_ge_b_s0 = (((IData)(fpu_add__DOT__exp_a_eff) 
                                        > (IData)(fpu_add__DOT__exp_b_eff)) 
                                       | (((IData)(fpu_add__DOT__exp_a_eff) 
                                           == (IData)(fpu_add__DOT__exp_b_eff)) 
                                          & (fpu_add__DOT__mant_a 
                                             >= fpu_add__DOT__mant_b)));
    fpu_add__DOT__wide_shifted_s3 = (0x3ffffffU & VL_SHIFTR_III(26,26,7, 
                                                                (0x3ffffffU 
                                                                 & (fpu_add__DOT__shifted28_s3 
                                                                    >> 2U)), (IData)(fpu_add__DOT__subshift_s3)));
    if (fpu_add__DOT__is_subnormal_path_s3) {
        fpu_add__DOT__sticky_pre_s3 = ((IData)(fpu_add__DOT__sticky_norm_s3) 
                                       | ((0U != (IData)(fpu_add__DOT__subshift_s3)) 
                                          & (0U != 
                                             (0x3ffffffU 
                                              & ((~ 
                                                  VL_SHIFTL_III(26,26,7, (IData)(0x3ffffffU), (IData)(fpu_add__DOT__subshift_s3))) 
                                                 & (fpu_add__DOT__shifted28_s3 
                                                    >> 2U))))));
        fpu_add__DOT__mant24_pre_s3 = (0xffffffU & 
                                       (fpu_add__DOT__wide_shifted_s3 
                                        >> 2U));
        fpu_add__DOT__guard_pre_s3 = (1U & (fpu_add__DOT__wide_shifted_s3 
                                            >> 1U));
        fpu_add__DOT__round_pre_s3 = (1U & fpu_add__DOT__wide_shifted_s3);
    } else {
        fpu_add__DOT__sticky_pre_s3 = fpu_add__DOT__sticky_norm_s3;
        fpu_add__DOT__mant24_pre_s3 = (0xffffffU & 
                                       (fpu_add__DOT__shifted28_s3 
                                        >> 4U));
        fpu_add__DOT__guard_pre_s3 = (1U & (fpu_add__DOT__shifted28_s3 
                                            >> 3U));
        fpu_add__DOT__round_pre_s3 = (1U & (fpu_add__DOT__shifted28_s3 
                                            >> 2U));
    }
    vlSelf->fpu_add__DOT__bypass_result_comb = ((4U 
                                                 & (IData)(vlSelf->op_i))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->op_i))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->op_i))
                                                   ? vlSelf->a_i
                                                   : 
                                                  ((IData)(fpu_add__DOT__a_nan_c)
                                                    ? 0xffc00000U
                                                    : 
                                                   (((~ 
                                                      (vlSelf->a_i 
                                                       >> 0x1fU)) 
                                                     << 0x1fU) 
                                                    | (0x7fffffffU 
                                                       & vlSelf->a_i))))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->op_i))
                                                   ? 
                                                  ((IData)(fpu_add__DOT__a_nan_c)
                                                    ? 0x7fc00000U
                                                    : 
                                                   (0x7fffffffU 
                                                    & vlSelf->a_i))
                                                   : 
                                                  ((IData)(fpu_add__DOT____VdfgExtracted_h6fb5d5e2__0)
                                                    ? 0x7fc00000U
                                                    : 
                                                   ((IData)(fpu_add__DOT__a_nan_c)
                                                     ? vlSelf->b_i
                                                     : 
                                                    ((IData)(fpu_add__DOT__b_nan_c)
                                                      ? vlSelf->a_i
                                                      : 
                                                     ((IData)(fpu_add__DOT____VdfgExtracted_h96747cd1__0)
                                                       ? 
                                                      ((1U 
                                                        & ((~ 
                                                            (vlSelf->a_i 
                                                             >> 0x1fU)) 
                                                           | (~ 
                                                              (vlSelf->b_i 
                                                               >> 0x1fU))))
                                                        ? 
                                                       ((vlSelf->a_i 
                                                         >> 0x1fU)
                                                         ? vlSelf->b_i
                                                         : vlSelf->a_i)
                                                        : vlSelf->a_i)
                                                       : 
                                                      ((IData)(vlSelf->fpu_add__DOT__cmp_lt_comb)
                                                        ? vlSelf->b_i
                                                        : vlSelf->a_i)))))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->op_i))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->op_i))
                                                   ? 
                                                  ((IData)(fpu_add__DOT____VdfgExtracted_h6fb5d5e2__0)
                                                    ? 0x7fc00000U
                                                    : 
                                                   ((IData)(fpu_add__DOT__a_nan_c)
                                                     ? vlSelf->b_i
                                                     : 
                                                    ((IData)(fpu_add__DOT__b_nan_c)
                                                      ? vlSelf->a_i
                                                      : 
                                                     ((IData)(fpu_add__DOT____VdfgExtracted_h96747cd1__0)
                                                       ? 
                                                      (((vlSelf->a_i 
                                                         | vlSelf->b_i) 
                                                        >> 0x1fU)
                                                        ? 
                                                       ((vlSelf->a_i 
                                                         >> 0x1fU)
                                                         ? vlSelf->a_i
                                                         : vlSelf->b_i)
                                                        : vlSelf->a_i)
                                                       : 
                                                      ((IData)(vlSelf->fpu_add__DOT__cmp_lt_comb)
                                                        ? vlSelf->a_i
                                                        : vlSelf->b_i)))))
                                                   : (IData)(vlSelf->fpu_add__DOT__cmp_lt_comb))
                                                  : 0U));
    if (vlSelf->fpu_add__DOT__a_ge_b_s0) {
        vlSelf->fpu_add__DOT__exp_big_s0 = fpu_add__DOT__exp_a_eff;
        vlSelf->fpu_add__DOT__mant_big_s0 = fpu_add__DOT__mant_a;
        vlSelf->fpu_add__DOT__mant_small_s0 = fpu_add__DOT__mant_b;
        fpu_add__DOT__exp_diff9_s0 = (0x1ffU & ((IData)(fpu_add__DOT__exp_a_eff) 
                                                - (IData)(fpu_add__DOT__exp_b_eff)));
    } else {
        vlSelf->fpu_add__DOT__exp_big_s0 = fpu_add__DOT__exp_b_eff;
        vlSelf->fpu_add__DOT__mant_big_s0 = fpu_add__DOT__mant_b;
        vlSelf->fpu_add__DOT__mant_small_s0 = fpu_add__DOT__mant_a;
        fpu_add__DOT__exp_diff9_s0 = (0x1ffU & ((IData)(fpu_add__DOT__exp_b_eff) 
                                                - (IData)(fpu_add__DOT__exp_a_eff)));
    }
    vlSelf->fpu_add__DOT__algn_shift_s0 = ((0x1bU < (IData)(fpu_add__DOT__exp_diff9_s0))
                                            ? 0x1bU
                                            : (0x1fU 
                                               & (IData)(fpu_add__DOT__exp_diff9_s0)));
    fpu_add__DOT__inexact_s3 = ((IData)(fpu_add__DOT__guard_pre_s3) 
                                | ((IData)(fpu_add__DOT__round_pre_s3) 
                                   | ((IData)(fpu_add__DOT__sticky_pre_s3) 
                                      | VL_LTES_III(12, 0xffU, (IData)(fpu_add__DOT__tent_exp_s3)))));
    fpu_add__DOT__mant25_s3 = (0x1ffffffU & (fpu_add__DOT__mant24_pre_s3 
                                             + ((IData)(fpu_add__DOT__guard_pre_s3) 
                                                & ((IData)(fpu_add__DOT__round_pre_s3) 
                                                   | ((IData)(fpu_add__DOT__sticky_pre_s3) 
                                                      | fpu_add__DOT__mant24_pre_s3)))));
    vlSelf->fpu_add__DOT__small27_shifted_raw_s0 = 
        (0x7ffffffU & ((0U == (IData)(vlSelf->fpu_add__DOT__algn_shift_s0))
                        ? (vlSelf->fpu_add__DOT__mant_small_s0 
                           << 3U) : ((vlSelf->fpu_add__DOT__mant_small_s0 
                                      << 3U) >> (IData)(vlSelf->fpu_add__DOT__algn_shift_s0))));
    fpu_add__DOT__exp_final9_s3 = (0x1ffU & (((IData)(fpu_add__DOT__is_subnormal_path_s3)
                                               ? 0U
                                               : (0xffU 
                                                  & (IData)(fpu_add__DOT__tent_exp_s3))) 
                                             + (1U 
                                                & (fpu_add__DOT__mant25_s3 
                                                   >> 0x18U))));
    fpu_add__DOT__overflow_s3 = (VL_LTES_III(12, 0xffU, (IData)(fpu_add__DOT__tent_exp_s3)) 
                                 | (0xffU <= (IData)(fpu_add__DOT__exp_final9_s3)));
    if (vlSelf->fpu_add__DOT__is_exact_zero_s2) {
        fpu_add__DOT__computed_flags_s3 = 0U;
        fpu_add__DOT__computed_result_s3 = (((IData)(vlSelf->fpu_add__DOT__eff_add_s2) 
                                             & (IData)(vlSelf->fpu_add__DOT__sign_result_s2)) 
                                            << 0x1fU);
    } else if (fpu_add__DOT__overflow_s3) {
        fpu_add__DOT__computed_flags_s3 = 5U;
        fpu_add__DOT__computed_result_s3 = (0x7f800000U 
                                            | ((IData)(vlSelf->fpu_add__DOT__sign_result_s2) 
                                               << 0x1fU));
    } else {
        fpu_add__DOT__computed_flags_s3 = ((((IData)(fpu_add__DOT__is_subnormal_path_s3) 
                                             & (IData)(fpu_add__DOT__inexact_s3)) 
                                            << 1U) 
                                           | (IData)(fpu_add__DOT__inexact_s3));
        fpu_add__DOT__computed_result_s3 = (((IData)(vlSelf->fpu_add__DOT__sign_result_s2) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & ((IData)(fpu_add__DOT__exp_final9_s3) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & ((0x1000000U 
                                                      & fpu_add__DOT__mant25_s3)
                                                      ? 
                                                     (fpu_add__DOT__mant25_s3 
                                                      >> 1U)
                                                      : fpu_add__DOT__mant25_s3))));
    }
    if (vlSelf->fpu_add__DOT__result_is_nan_s2) {
        vlSelf->fpu_add__DOT__flags_comb_s3 = ((IData)(vlSelf->fpu_add__DOT__invalid_nan_in_s2) 
                                               << 4U);
        vlSelf->fpu_add__DOT__result_comb_s3 = 0x7fc00000U;
    } else if (vlSelf->fpu_add__DOT__result_is_inf_s2) {
        vlSelf->fpu_add__DOT__flags_comb_s3 = 0U;
        vlSelf->fpu_add__DOT__result_comb_s3 = (0x7f800000U 
                                                | ((IData)(vlSelf->fpu_add__DOT__inf_result_sign_s2) 
                                                   << 0x1fU));
    } else {
        vlSelf->fpu_add__DOT__flags_comb_s3 = fpu_add__DOT__computed_flags_s3;
        vlSelf->fpu_add__DOT__result_comb_s3 = fpu_add__DOT__computed_result_s3;
    }
}

VL_ATTR_COLD void Vfpu_add___024root___eval_stl(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfpu_add___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfpu_add___024root___eval_triggers__stl(Vfpu_add___024root* vlSelf);

VL_ATTR_COLD bool Vfpu_add___024root___eval_phase__stl(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfpu_add___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfpu_add___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__ico(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__act(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__nba(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpu_add___024root___ctor_var_reset(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->valid_i = VL_RAND_RESET_I(1);
    vlSelf->op_i = VL_RAND_RESET_I(3);
    vlSelf->a_i = VL_RAND_RESET_I(32);
    vlSelf->b_i = VL_RAND_RESET_I(32);
    vlSelf->valid_o = VL_RAND_RESET_I(1);
    vlSelf->result_o = VL_RAND_RESET_I(32);
    vlSelf->flags_o = VL_RAND_RESET_I(5);
    vlSelf->bypass_valid_o = VL_RAND_RESET_I(1);
    vlSelf->bypass_result_o = VL_RAND_RESET_I(32);
    vlSelf->cmp_lt_o = VL_RAND_RESET_I(1);
    vlSelf->cmp_eq_o = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__is_pipelined_op = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__a_is_inf = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__a_is_snan = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__sign_b_eff = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__b_is_snan = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__a_ge_b_s0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__exp_big_s0 = VL_RAND_RESET_I(8);
    vlSelf->fpu_add__DOT__mant_big_s0 = VL_RAND_RESET_I(24);
    vlSelf->fpu_add__DOT__mant_small_s0 = VL_RAND_RESET_I(24);
    vlSelf->fpu_add__DOT__algn_shift_s0 = VL_RAND_RESET_I(5);
    vlSelf->fpu_add__DOT__small27_shifted_raw_s0 = VL_RAND_RESET_I(27);
    vlSelf->fpu_add__DOT__result_is_nan_s0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__result_is_inf_s0 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__valid_s1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__eff_add_s1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__big27_s1 = VL_RAND_RESET_I(27);
    vlSelf->fpu_add__DOT__small27_shifted_s1 = VL_RAND_RESET_I(27);
    vlSelf->fpu_add__DOT__exp_big_s1 = VL_RAND_RESET_I(8);
    vlSelf->fpu_add__DOT__sign_result_s1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__result_is_nan_s1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__result_is_inf_s1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__invalid_nan_in_s1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__inf_result_sign_s1 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__valword28_s1 = VL_RAND_RESET_I(28);
    vlSelf->fpu_add__DOT__nlz28_s1 = VL_RAND_RESET_I(5);
    vlSelf->fpu_add__DOT__valid_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__eff_add_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__valword28_s2 = VL_RAND_RESET_I(28);
    vlSelf->fpu_add__DOT__nlz28_s2 = VL_RAND_RESET_I(5);
    vlSelf->fpu_add__DOT__is_exact_zero_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__exp_big_s2 = VL_RAND_RESET_I(8);
    vlSelf->fpu_add__DOT__sign_result_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__result_is_nan_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__result_is_inf_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__invalid_nan_in_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__inf_result_sign_s2 = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__result_comb_s3 = VL_RAND_RESET_I(32);
    vlSelf->fpu_add__DOT__flags_comb_s3 = VL_RAND_RESET_I(5);
    vlSelf->fpu_add__DOT__cmp_lt_comb = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__cmp_eq_comb = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__cmp_lt_hold = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__cmp_eq_hold = VL_RAND_RESET_I(1);
    vlSelf->fpu_add__DOT__bypass_result_comb = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = VL_RAND_RESET_I(1);
}
