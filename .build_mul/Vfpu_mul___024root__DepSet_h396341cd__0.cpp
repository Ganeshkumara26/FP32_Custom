// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_mul.h for the primary calling header

#include "Vfpu_mul__pch.h"
#include "Vfpu_mul___024root.h"

VL_INLINE_OPT void Vfpu_mul___024root___ico_sequent__TOP__0(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ fpu_mul__DOT__exp_a_raw;
    fpu_mul__DOT__exp_a_raw = 0;
    CData/*7:0*/ fpu_mul__DOT__exp_b_raw;
    fpu_mul__DOT__exp_b_raw = 0;
    IData/*22:0*/ fpu_mul__DOT__frac_a;
    fpu_mul__DOT__frac_a = 0;
    IData/*22:0*/ fpu_mul__DOT__frac_b;
    fpu_mul__DOT__frac_b = 0;
    CData/*0:0*/ fpu_mul__DOT__a_is_nan;
    fpu_mul__DOT__a_is_nan = 0;
    CData/*0:0*/ fpu_mul__DOT__b_is_nan;
    fpu_mul__DOT__b_is_nan = 0;
    CData/*0:0*/ fpu_mul__DOT__a_is_sub;
    fpu_mul__DOT__a_is_sub = 0;
    CData/*0:0*/ fpu_mul__DOT__b_is_sub;
    fpu_mul__DOT__b_is_sub = 0;
    CData/*0:0*/ fpu_mul__DOT__any_nan_s0;
    fpu_mul__DOT__any_nan_s0 = 0;
    // Body
    fpu_mul__DOT__exp_a_raw = (0xffU & (vlSelf->a_i 
                                        >> 0x17U));
    fpu_mul__DOT__frac_a = (0x7fffffU & vlSelf->a_i);
    vlSelf->fpu_mul__DOT__a_is_zero = ((0U == (IData)(fpu_mul__DOT__exp_a_raw)) 
                                       & (0U == fpu_mul__DOT__frac_a));
    vlSelf->fpu_mul__DOT__a_is_inf = ((0xffU == (IData)(fpu_mul__DOT__exp_a_raw)) 
                                      & (0U == fpu_mul__DOT__frac_a));
    fpu_mul__DOT__a_is_nan = ((0xffU == (IData)(fpu_mul__DOT__exp_a_raw)) 
                              & (0U != fpu_mul__DOT__frac_a));
    vlSelf->fpu_mul__DOT__a_is_snan = ((IData)(fpu_mul__DOT__a_is_nan) 
                                       & (~ (fpu_mul__DOT__frac_a 
                                             >> 0x16U)));
    fpu_mul__DOT__a_is_sub = ((0U == (IData)(fpu_mul__DOT__exp_a_raw)) 
                              & (0U != fpu_mul__DOT__frac_a));
    if (fpu_mul__DOT__a_is_sub) {
        vlSelf->fpu_mul__DOT__mant_a = fpu_mul__DOT__frac_a;
        vlSelf->fpu_mul__DOT__exp_a = 1U;
    } else {
        vlSelf->fpu_mul__DOT__mant_a = (0x800000U | fpu_mul__DOT__frac_a);
        vlSelf->fpu_mul__DOT__exp_a = fpu_mul__DOT__exp_a_raw;
    }
    fpu_mul__DOT__exp_b_raw = (0xffU & (vlSelf->b_i 
                                        >> 0x17U));
    fpu_mul__DOT__frac_b = (0x7fffffU & vlSelf->b_i);
    vlSelf->fpu_mul__DOT__b_is_zero = ((0U == (IData)(fpu_mul__DOT__exp_b_raw)) 
                                       & (0U == fpu_mul__DOT__frac_b));
    vlSelf->fpu_mul__DOT__b_is_inf = ((0xffU == (IData)(fpu_mul__DOT__exp_b_raw)) 
                                      & (0U == fpu_mul__DOT__frac_b));
    fpu_mul__DOT__b_is_nan = ((0xffU == (IData)(fpu_mul__DOT__exp_b_raw)) 
                              & (0U != fpu_mul__DOT__frac_b));
    vlSelf->fpu_mul__DOT__b_is_snan = ((IData)(fpu_mul__DOT__b_is_nan) 
                                       & (~ (fpu_mul__DOT__frac_b 
                                             >> 0x16U)));
    fpu_mul__DOT__b_is_sub = ((0U == (IData)(fpu_mul__DOT__exp_b_raw)) 
                              & (0U != fpu_mul__DOT__frac_b));
    if (fpu_mul__DOT__b_is_sub) {
        vlSelf->fpu_mul__DOT__mant_b = fpu_mul__DOT__frac_b;
        vlSelf->fpu_mul__DOT__exp_b = 1U;
    } else {
        vlSelf->fpu_mul__DOT__mant_b = (0x800000U | fpu_mul__DOT__frac_b);
        vlSelf->fpu_mul__DOT__exp_b = fpu_mul__DOT__exp_b_raw;
    }
    fpu_mul__DOT__any_nan_s0 = ((IData)(fpu_mul__DOT__a_is_nan) 
                                | (IData)(fpu_mul__DOT__b_is_nan));
    vlSelf->fpu_mul__DOT__result_is_nan_s0 = (((IData)(fpu_mul__DOT__any_nan_s0) 
                                               | ((IData)(vlSelf->fpu_mul__DOT__a_is_inf) 
                                                  & (IData)(vlSelf->fpu_mul__DOT__b_is_zero))) 
                                              | ((IData)(vlSelf->fpu_mul__DOT__a_is_zero) 
                                                 & (IData)(vlSelf->fpu_mul__DOT__b_is_inf)));
    vlSelf->fpu_mul__DOT__result_is_inf_s0 = ((~ (IData)(vlSelf->fpu_mul__DOT__result_is_nan_s0)) 
                                              & ((IData)(vlSelf->fpu_mul__DOT__a_is_inf) 
                                                 | (IData)(vlSelf->fpu_mul__DOT__b_is_inf)));
    vlSelf->fpu_mul__DOT__result_is_zero_s0 = (((~ (IData)(vlSelf->fpu_mul__DOT__result_is_nan_s0)) 
                                                & (~ (IData)(vlSelf->fpu_mul__DOT__result_is_inf_s0))) 
                                               & ((IData)(vlSelf->fpu_mul__DOT__a_is_zero) 
                                                  | (IData)(vlSelf->fpu_mul__DOT__b_is_zero)));
}

void Vfpu_mul___024root___eval_ico(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vfpu_mul___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfpu_mul___024root___eval_triggers__ico(Vfpu_mul___024root* vlSelf);

bool Vfpu_mul___024root___eval_phase__ico(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfpu_mul___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vfpu_mul___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfpu_mul___024root___eval_act(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfpu_mul___024root___nba_sequent__TOP__0(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*5:0*/ fpu_mul__DOT__nlz_s2;
    fpu_mul__DOT__nlz_s2 = 0;
    QData/*47:0*/ fpu_mul__DOT__norm48_s2;
    fpu_mul__DOT__norm48_s2 = 0;
    CData/*0:0*/ fpu_mul__DOT__sticky_norm_s2;
    fpu_mul__DOT__sticky_norm_s2 = 0;
    SData/*11:0*/ fpu_mul__DOT__tent_exp_s2;
    fpu_mul__DOT__tent_exp_s2 = 0;
    CData/*6:0*/ fpu_mul__DOT__subshift_s2;
    fpu_mul__DOT__subshift_s2 = 0;
    CData/*0:0*/ fpu_mul__DOT__is_subnormal_path_s2;
    fpu_mul__DOT__is_subnormal_path_s2 = 0;
    IData/*25:0*/ fpu_mul__DOT__wide_shifted_s2;
    fpu_mul__DOT__wide_shifted_s2 = 0;
    IData/*23:0*/ fpu_mul__DOT__mant24_pre_s2;
    fpu_mul__DOT__mant24_pre_s2 = 0;
    CData/*0:0*/ fpu_mul__DOT__guard_pre_s2;
    fpu_mul__DOT__guard_pre_s2 = 0;
    CData/*0:0*/ fpu_mul__DOT__round_pre_s2;
    fpu_mul__DOT__round_pre_s2 = 0;
    CData/*0:0*/ fpu_mul__DOT__sticky_pre_s2;
    fpu_mul__DOT__sticky_pre_s2 = 0;
    IData/*24:0*/ fpu_mul__DOT__mant25_s2;
    fpu_mul__DOT__mant25_s2 = 0;
    SData/*8:0*/ fpu_mul__DOT__exp_final9_s2;
    fpu_mul__DOT__exp_final9_s2 = 0;
    CData/*0:0*/ fpu_mul__DOT__inexact_s2;
    fpu_mul__DOT__inexact_s2 = 0;
    CData/*0:0*/ fpu_mul__DOT__overflow_s2;
    fpu_mul__DOT__overflow_s2 = 0;
    IData/*31:0*/ fpu_mul__DOT__computed_result_s2;
    fpu_mul__DOT__computed_result_s2 = 0;
    CData/*4:0*/ fpu_mul__DOT__computed_flags_s2;
    fpu_mul__DOT__computed_flags_s2 = 0;
    CData/*5:0*/ __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout;
    __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0;
    QData/*47:0*/ __Vfunc_fpu_mul__DOT__lzc48__0__v;
    __Vfunc_fpu_mul__DOT__lzc48__0__v = 0;
    // Body
    if (vlSelf->rst_ni) {
        vlSelf->flags_o = vlSelf->fpu_mul__DOT__flags_comb_s2;
        vlSelf->result_o = vlSelf->fpu_mul__DOT__result_comb_s2;
        vlSelf->fpu_mul__DOT__exp_sum_s1 = (0x7ffU 
                                            & (((IData)(vlSelf->fpu_mul__DOT__exp_a) 
                                                + (IData)(vlSelf->fpu_mul__DOT__exp_b)) 
                                               - (IData)(0x7fU)));
        vlSelf->fpu_mul__DOT__prod_s1 = (0xffffffffffffULL 
                                         & ((QData)((IData)(vlSelf->fpu_mul__DOT__mant_a)) 
                                            * (QData)((IData)(vlSelf->fpu_mul__DOT__mant_b))));
    } else {
        vlSelf->flags_o = 0U;
        vlSelf->result_o = 0U;
        vlSelf->fpu_mul__DOT__exp_sum_s1 = 0U;
        vlSelf->fpu_mul__DOT__prod_s1 = 0ULL;
    }
    vlSelf->valid_o = ((IData)(vlSelf->rst_ni) && (IData)(vlSelf->fpu_mul__DOT__valid_s1));
    vlSelf->fpu_mul__DOT__result_is_inf_s1 = ((IData)(vlSelf->rst_ni) 
                                              && (IData)(vlSelf->fpu_mul__DOT__result_is_inf_s0));
    vlSelf->fpu_mul__DOT__result_is_nan_s1 = ((IData)(vlSelf->rst_ni) 
                                              && (IData)(vlSelf->fpu_mul__DOT__result_is_nan_s0));
    vlSelf->fpu_mul__DOT__sign_r_s1 = ((IData)(vlSelf->rst_ni) 
                                       && ((vlSelf->a_i 
                                            ^ vlSelf->b_i) 
                                           >> 0x1fU));
    vlSelf->fpu_mul__DOT__result_is_zero_s1 = ((IData)(vlSelf->rst_ni) 
                                               && (IData)(vlSelf->fpu_mul__DOT__result_is_zero_s0));
    vlSelf->fpu_mul__DOT__invalid_s1 = ((IData)(vlSelf->rst_ni) 
                                        && ((((IData)(vlSelf->fpu_mul__DOT__a_is_snan) 
                                              | (IData)(vlSelf->fpu_mul__DOT__b_is_snan)) 
                                             | ((IData)(vlSelf->fpu_mul__DOT__a_is_inf) 
                                                & (IData)(vlSelf->fpu_mul__DOT__b_is_zero))) 
                                            | ((IData)(vlSelf->fpu_mul__DOT__a_is_zero) 
                                               & (IData)(vlSelf->fpu_mul__DOT__b_is_inf))));
    vlSelf->fpu_mul__DOT__valid_s1 = ((IData)(vlSelf->rst_ni) 
                                      && (IData)(vlSelf->valid_i));
    __Vfunc_fpu_mul__DOT__lzc48__0__v = vlSelf->fpu_mul__DOT__prod_s1;
    __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x30U;
    if ((1U & (IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                       >> 0x2fU)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x2eU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 1U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x2dU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 2U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x2cU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 3U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x2bU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 4U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x2aU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 5U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x29U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 6U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x28U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 7U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x27U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 8U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x26U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 9U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x25U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0xaU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x24U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0xbU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x23U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0xcU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x22U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0xdU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x21U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0xeU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x20U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0xfU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x1fU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x10U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x1eU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x11U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x1dU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x12U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x1cU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x13U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x1bU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x14U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x1aU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x15U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x19U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x16U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x18U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x17U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x17U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x18U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x16U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x19U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x15U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x1aU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x14U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x1bU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x13U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x1cU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x12U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x1dU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x11U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x1eU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0x10U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x1fU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0xfU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x20U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0xeU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x21U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0xdU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x22U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0xcU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x23U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0xbU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x24U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 0xaU)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x25U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 9U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x26U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 8U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x27U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 7U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x28U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 6U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x29U;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 5U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x2aU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 4U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x2bU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 3U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x2cU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 2U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x2dU;
    }
    if (((IData)((__Vfunc_fpu_mul__DOT__lzc48__0__v 
                  >> 1U)) & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x2eU;
    }
    if (((IData)(__Vfunc_fpu_mul__DOT__lzc48__0__v) 
         & (0x30U == (IData)(__Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout)))) {
        __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout = 0x2fU;
    }
    fpu_mul__DOT__nlz_s2 = __Vfunc_fpu_mul__DOT__lzc48__0__Vfuncout;
    fpu_mul__DOT__sticky_norm_s2 = (0U != (0x3fffffU 
                                           & VL_SHIFTL_III(22,22,6, (IData)(vlSelf->fpu_mul__DOT__prod_s1), (IData)(fpu_mul__DOT__nlz_s2))));
    fpu_mul__DOT__norm48_s2 = (0xffffffffffffULL & 
                               (vlSelf->fpu_mul__DOT__prod_s1 
                                << (IData)(fpu_mul__DOT__nlz_s2)));
    fpu_mul__DOT__tent_exp_s2 = (0xfffU & (((IData)(1U) 
                                            + ((0x800U 
                                                & ((IData)(vlSelf->fpu_mul__DOT__exp_sum_s1) 
                                                   << 1U)) 
                                               | (IData)(vlSelf->fpu_mul__DOT__exp_sum_s1))) 
                                           - (IData)(fpu_mul__DOT__nlz_s2)));
    fpu_mul__DOT__subshift_s2 = (VL_LTS_III(12, 0U, (IData)(fpu_mul__DOT__tent_exp_s2))
                                  ? 0U : (VL_LTS_III(12, 0x26U, 
                                                     (0xfffU 
                                                      & ((IData)(1U) 
                                                         - (IData)(fpu_mul__DOT__tent_exp_s2))))
                                           ? 0x26U : 
                                          (0x7fU & 
                                           ((IData)(1U) 
                                            - (IData)(fpu_mul__DOT__tent_exp_s2)))));
    fpu_mul__DOT__is_subnormal_path_s2 = (VL_GTS_III(12, 0xffU, (IData)(fpu_mul__DOT__tent_exp_s2)) 
                                          & VL_GTES_III(12, 0U, (IData)(fpu_mul__DOT__tent_exp_s2)));
    fpu_mul__DOT__wide_shifted_s2 = (0x3ffffffU & VL_SHIFTR_III(26,26,7, 
                                                                (0x3ffffffU 
                                                                 & (IData)(
                                                                           (fpu_mul__DOT__norm48_s2 
                                                                            >> 0x16U))), (IData)(fpu_mul__DOT__subshift_s2)));
    if (fpu_mul__DOT__is_subnormal_path_s2) {
        fpu_mul__DOT__sticky_pre_s2 = ((IData)(fpu_mul__DOT__sticky_norm_s2) 
                                       | ((0U != (IData)(fpu_mul__DOT__subshift_s2)) 
                                          & (0U != 
                                             (0x3ffffffU 
                                              & ((~ 
                                                  VL_SHIFTL_III(26,26,7, (IData)(0x3ffffffU), (IData)(fpu_mul__DOT__subshift_s2))) 
                                                 & (IData)(
                                                           (fpu_mul__DOT__norm48_s2 
                                                            >> 0x16U)))))));
        fpu_mul__DOT__mant24_pre_s2 = (0xffffffU & 
                                       (fpu_mul__DOT__wide_shifted_s2 
                                        >> 2U));
        fpu_mul__DOT__guard_pre_s2 = (1U & (fpu_mul__DOT__wide_shifted_s2 
                                            >> 1U));
        fpu_mul__DOT__round_pre_s2 = (1U & fpu_mul__DOT__wide_shifted_s2);
    } else {
        fpu_mul__DOT__sticky_pre_s2 = fpu_mul__DOT__sticky_norm_s2;
        fpu_mul__DOT__mant24_pre_s2 = (0xffffffU & (IData)(
                                                           (fpu_mul__DOT__norm48_s2 
                                                            >> 0x18U)));
        fpu_mul__DOT__guard_pre_s2 = (1U & (IData)(
                                                   (fpu_mul__DOT__norm48_s2 
                                                    >> 0x17U)));
        fpu_mul__DOT__round_pre_s2 = (1U & (IData)(
                                                   (fpu_mul__DOT__norm48_s2 
                                                    >> 0x16U)));
    }
    fpu_mul__DOT__inexact_s2 = ((IData)(fpu_mul__DOT__guard_pre_s2) 
                                | ((IData)(fpu_mul__DOT__round_pre_s2) 
                                   | ((IData)(fpu_mul__DOT__sticky_pre_s2) 
                                      | VL_LTES_III(12, 0xffU, (IData)(fpu_mul__DOT__tent_exp_s2)))));
    fpu_mul__DOT__mant25_s2 = (0x1ffffffU & (fpu_mul__DOT__mant24_pre_s2 
                                             + ((IData)(fpu_mul__DOT__guard_pre_s2) 
                                                & ((IData)(fpu_mul__DOT__round_pre_s2) 
                                                   | ((IData)(fpu_mul__DOT__sticky_pre_s2) 
                                                      | fpu_mul__DOT__mant24_pre_s2)))));
    fpu_mul__DOT__exp_final9_s2 = (0x1ffU & (((IData)(fpu_mul__DOT__is_subnormal_path_s2)
                                               ? 0U
                                               : (0xffU 
                                                  & (IData)(fpu_mul__DOT__tent_exp_s2))) 
                                             + (1U 
                                                & (fpu_mul__DOT__mant25_s2 
                                                   >> 0x18U))));
    fpu_mul__DOT__overflow_s2 = (VL_LTES_III(12, 0xffU, (IData)(fpu_mul__DOT__tent_exp_s2)) 
                                 | (0xffU <= (IData)(fpu_mul__DOT__exp_final9_s2)));
    if (fpu_mul__DOT__overflow_s2) {
        fpu_mul__DOT__computed_flags_s2 = 5U;
        fpu_mul__DOT__computed_result_s2 = (0x7f800000U 
                                            | ((IData)(vlSelf->fpu_mul__DOT__sign_r_s1) 
                                               << 0x1fU));
    } else {
        fpu_mul__DOT__computed_flags_s2 = ((((IData)(fpu_mul__DOT__is_subnormal_path_s2) 
                                             & (IData)(fpu_mul__DOT__inexact_s2)) 
                                            << 1U) 
                                           | (IData)(fpu_mul__DOT__inexact_s2));
        fpu_mul__DOT__computed_result_s2 = (((IData)(vlSelf->fpu_mul__DOT__sign_r_s1) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & ((IData)(fpu_mul__DOT__exp_final9_s2) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & ((0x1000000U 
                                                      & fpu_mul__DOT__mant25_s2)
                                                      ? 
                                                     (fpu_mul__DOT__mant25_s2 
                                                      >> 1U)
                                                      : fpu_mul__DOT__mant25_s2))));
    }
    if (vlSelf->fpu_mul__DOT__result_is_nan_s1) {
        vlSelf->fpu_mul__DOT__flags_comb_s2 = ((IData)(vlSelf->fpu_mul__DOT__invalid_s1) 
                                               << 4U);
        vlSelf->fpu_mul__DOT__result_comb_s2 = 0x7fc00000U;
    } else if (vlSelf->fpu_mul__DOT__result_is_inf_s1) {
        vlSelf->fpu_mul__DOT__flags_comb_s2 = 0U;
        vlSelf->fpu_mul__DOT__result_comb_s2 = (0x7f800000U 
                                                | ((IData)(vlSelf->fpu_mul__DOT__sign_r_s1) 
                                                   << 0x1fU));
    } else if (vlSelf->fpu_mul__DOT__result_is_zero_s1) {
        vlSelf->fpu_mul__DOT__flags_comb_s2 = 0U;
        vlSelf->fpu_mul__DOT__result_comb_s2 = ((IData)(vlSelf->fpu_mul__DOT__sign_r_s1) 
                                                << 0x1fU);
    } else {
        vlSelf->fpu_mul__DOT__flags_comb_s2 = fpu_mul__DOT__computed_flags_s2;
        vlSelf->fpu_mul__DOT__result_comb_s2 = fpu_mul__DOT__computed_result_s2;
    }
}

void Vfpu_mul___024root___eval_nba(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfpu_mul___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vfpu_mul___024root___eval_triggers__act(Vfpu_mul___024root* vlSelf);

bool Vfpu_mul___024root___eval_phase__act(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfpu_mul___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfpu_mul___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfpu_mul___024root___eval_phase__nba(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfpu_mul___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_mul___024root___dump_triggers__ico(Vfpu_mul___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_mul___024root___dump_triggers__nba(Vfpu_mul___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_mul___024root___dump_triggers__act(Vfpu_mul___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpu_mul___024root___eval(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vfpu_mul___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_mul.sv", 13, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfpu_mul___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfpu_mul___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_mul.sv", 13, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfpu_mul___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_mul.sv", 13, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfpu_mul___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfpu_mul___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfpu_mul___024root___eval_debug_assertions(Vfpu_mul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_mul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_mul___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->valid_i & 0xfeU))) {
        Verilated::overWidthError("valid_i");}
}
#endif  // VL_DEBUG
