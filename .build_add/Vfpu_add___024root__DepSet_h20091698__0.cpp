// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_add.h for the primary calling header

#include "Vfpu_add__pch.h"
#include "Vfpu_add___024root.h"

VL_INLINE_OPT void Vfpu_add___024root___ico_sequent__TOP__0(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___ico_sequent__TOP__0\n"); );
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
    // Body
    vlSelf->fpu_add__DOT__is_pipelined_op = ((0U == (IData)(vlSelf->op_i)) 
                                             | (1U 
                                                == (IData)(vlSelf->op_i)));
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
    vlSelf->fpu_add__DOT__small27_shifted_raw_s0 = 
        (0x7ffffffU & ((0U == (IData)(vlSelf->fpu_add__DOT__algn_shift_s0))
                        ? (vlSelf->fpu_add__DOT__mant_small_s0 
                           << 3U) : ((vlSelf->fpu_add__DOT__mant_small_s0 
                                      << 3U) >> (IData)(vlSelf->fpu_add__DOT__algn_shift_s0))));
}

void Vfpu_add___024root___eval_ico(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vfpu_add___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfpu_add___024root___eval_triggers__ico(Vfpu_add___024root* vlSelf);

bool Vfpu_add___024root___eval_phase__ico(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfpu_add___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vfpu_add___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfpu_add___024root___eval_act(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfpu_add___024root___nba_sequent__TOP__0(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___nba_sequent__TOP__0\n"); );
    // Init
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
    CData/*4:0*/ __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout;
    __Vfunc_fpu_add__DOT__lzc28__0__Vfuncout = 0;
    IData/*27:0*/ __Vfunc_fpu_add__DOT__lzc28__0__v;
    __Vfunc_fpu_add__DOT__lzc28__0__v = 0;
    // Body
    if (vlSelf->rst_ni) {
        vlSelf->flags_o = vlSelf->fpu_add__DOT__flags_comb_s3;
        vlSelf->result_o = vlSelf->fpu_add__DOT__result_comb_s3;
        vlSelf->bypass_result_o = vlSelf->fpu_add__DOT__bypass_result_comb;
        if (((IData)(vlSelf->valid_i) & (2U == (IData)(vlSelf->op_i)))) {
            vlSelf->fpu_add__DOT__cmp_eq_hold = vlSelf->fpu_add__DOT__cmp_eq_comb;
            vlSelf->fpu_add__DOT__cmp_lt_hold = vlSelf->fpu_add__DOT__cmp_lt_comb;
        }
        vlSelf->fpu_add__DOT__big27_s1 = (vlSelf->fpu_add__DOT__mant_big_s0 
                                          << 3U);
        vlSelf->fpu_add__DOT__small27_shifted_s1 = 
            ((0x7fffffeU & vlSelf->fpu_add__DOT__small27_shifted_raw_s0) 
             | (1U & (vlSelf->fpu_add__DOT__small27_shifted_raw_s0 
                      | ((0U != (IData)(vlSelf->fpu_add__DOT__algn_shift_s0)) 
                         & (0U != ((~ ((IData)(0x7ffffffU) 
                                       << (IData)(vlSelf->fpu_add__DOT__algn_shift_s0))) 
                                   & (vlSelf->fpu_add__DOT__mant_small_s0 
                                      << 3U)))))));
        vlSelf->fpu_add__DOT__valword28_s2 = vlSelf->fpu_add__DOT__valword28_s1;
        vlSelf->fpu_add__DOT__exp_big_s2 = vlSelf->fpu_add__DOT__exp_big_s1;
        vlSelf->fpu_add__DOT__nlz28_s2 = vlSelf->fpu_add__DOT__nlz28_s1;
        vlSelf->fpu_add__DOT__exp_big_s1 = vlSelf->fpu_add__DOT__exp_big_s0;
    } else {
        vlSelf->flags_o = 0U;
        vlSelf->result_o = 0U;
        vlSelf->bypass_result_o = 0U;
        vlSelf->fpu_add__DOT__cmp_eq_hold = 0U;
        vlSelf->fpu_add__DOT__big27_s1 = 0U;
        vlSelf->fpu_add__DOT__cmp_lt_hold = 0U;
        vlSelf->fpu_add__DOT__small27_shifted_s1 = 0U;
        vlSelf->fpu_add__DOT__valword28_s2 = 0U;
        vlSelf->fpu_add__DOT__exp_big_s2 = 0U;
        vlSelf->fpu_add__DOT__nlz28_s2 = 0U;
        vlSelf->fpu_add__DOT__exp_big_s1 = 0U;
    }
    vlSelf->bypass_valid_o = ((IData)(vlSelf->rst_ni) 
                              && ((IData)(vlSelf->valid_i) 
                                  & (~ (IData)(vlSelf->fpu_add__DOT__is_pipelined_op))));
    vlSelf->fpu_add__DOT__is_exact_zero_s2 = ((IData)(vlSelf->rst_ni) 
                                              && (0U 
                                                  == vlSelf->fpu_add__DOT__valword28_s1));
    vlSelf->fpu_add__DOT__result_is_inf_s2 = ((IData)(vlSelf->rst_ni) 
                                              && (IData)(vlSelf->fpu_add__DOT__result_is_inf_s1));
    vlSelf->fpu_add__DOT__result_is_nan_s2 = ((IData)(vlSelf->rst_ni) 
                                              && (IData)(vlSelf->fpu_add__DOT__result_is_nan_s1));
    vlSelf->valid_o = ((IData)(vlSelf->rst_ni) && (IData)(vlSelf->fpu_add__DOT__valid_s2));
    vlSelf->fpu_add__DOT__eff_add_s2 = ((IData)(vlSelf->rst_ni) 
                                        && (IData)(vlSelf->fpu_add__DOT__eff_add_s1));
    vlSelf->fpu_add__DOT__sign_result_s2 = ((IData)(vlSelf->rst_ni) 
                                            && (IData)(vlSelf->fpu_add__DOT__sign_result_s1));
    vlSelf->fpu_add__DOT__inf_result_sign_s2 = ((IData)(vlSelf->rst_ni) 
                                                && (IData)(vlSelf->fpu_add__DOT__inf_result_sign_s1));
    vlSelf->fpu_add__DOT__invalid_nan_in_s2 = ((IData)(vlSelf->rst_ni) 
                                               && (IData)(vlSelf->fpu_add__DOT__invalid_nan_in_s1));
    vlSelf->cmp_eq_o = vlSelf->fpu_add__DOT__cmp_eq_hold;
    vlSelf->cmp_lt_o = vlSelf->fpu_add__DOT__cmp_lt_hold;
    vlSelf->fpu_add__DOT__result_is_inf_s1 = ((IData)(vlSelf->rst_ni) 
                                              && (IData)(vlSelf->fpu_add__DOT__result_is_inf_s0));
    vlSelf->fpu_add__DOT__result_is_nan_s1 = ((IData)(vlSelf->rst_ni) 
                                              && (IData)(vlSelf->fpu_add__DOT__result_is_nan_s0));
    vlSelf->fpu_add__DOT__valid_s2 = ((IData)(vlSelf->rst_ni) 
                                      && (IData)(vlSelf->fpu_add__DOT__valid_s1));
    vlSelf->fpu_add__DOT__eff_add_s1 = ((IData)(vlSelf->rst_ni) 
                                        && ((vlSelf->a_i 
                                             >> 0x1fU) 
                                            == (IData)(vlSelf->fpu_add__DOT__sign_b_eff)));
    vlSelf->fpu_add__DOT__sign_result_s1 = ((IData)(vlSelf->rst_ni) 
                                            && (1U 
                                                & ((IData)(vlSelf->fpu_add__DOT__a_ge_b_s0)
                                                    ? 
                                                   (vlSelf->a_i 
                                                    >> 0x1fU)
                                                    : (IData)(vlSelf->fpu_add__DOT__sign_b_eff))));
    vlSelf->fpu_add__DOT__inf_result_sign_s1 = ((IData)(vlSelf->rst_ni) 
                                                && (1U 
                                                    & ((IData)(vlSelf->fpu_add__DOT__a_is_inf)
                                                        ? 
                                                       (vlSelf->a_i 
                                                        >> 0x1fU)
                                                        : (IData)(vlSelf->fpu_add__DOT__sign_b_eff))));
    vlSelf->fpu_add__DOT__invalid_nan_in_s1 = ((IData)(vlSelf->rst_ni) 
                                               && ((IData)(vlSelf->fpu_add__DOT__a_is_snan) 
                                                   | (IData)(vlSelf->fpu_add__DOT__b_is_snan)));
    fpu_add__DOT__shifted28_s3 = (0xfffffffU & (vlSelf->fpu_add__DOT__valword28_s2 
                                                << (IData)(vlSelf->fpu_add__DOT__nlz28_s2)));
    fpu_add__DOT__tent_exp_s3 = (0xfffU & (((IData)(1U) 
                                            + (IData)(vlSelf->fpu_add__DOT__exp_big_s2)) 
                                           - (IData)(vlSelf->fpu_add__DOT__nlz28_s2)));
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
    vlSelf->fpu_add__DOT__valid_s1 = ((IData)(vlSelf->rst_ni) 
                                      && ((IData)(vlSelf->valid_i) 
                                          & (IData)(vlSelf->fpu_add__DOT__is_pipelined_op)));
    vlSelf->fpu_add__DOT__valword28_s1 = (0xfffffffU 
                                          & ((IData)(vlSelf->fpu_add__DOT__eff_add_s1)
                                              ? (vlSelf->fpu_add__DOT__big27_s1 
                                                 + vlSelf->fpu_add__DOT__small27_shifted_s1)
                                              : (0x7ffffffU 
                                                 & (vlSelf->fpu_add__DOT__big27_s1 
                                                    - vlSelf->fpu_add__DOT__small27_shifted_s1))));
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
    fpu_add__DOT__inexact_s3 = ((IData)(fpu_add__DOT__guard_pre_s3) 
                                | ((IData)(fpu_add__DOT__round_pre_s3) 
                                   | ((IData)(fpu_add__DOT__sticky_pre_s3) 
                                      | VL_LTES_III(12, 0xffU, (IData)(fpu_add__DOT__tent_exp_s3)))));
    fpu_add__DOT__mant25_s3 = (0x1ffffffU & (fpu_add__DOT__mant24_pre_s3 
                                             + ((IData)(fpu_add__DOT__guard_pre_s3) 
                                                & ((IData)(fpu_add__DOT__round_pre_s3) 
                                                   | ((IData)(fpu_add__DOT__sticky_pre_s3) 
                                                      | fpu_add__DOT__mant24_pre_s3)))));
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

void Vfpu_add___024root___eval_nba(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfpu_add___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vfpu_add___024root___eval_triggers__act(Vfpu_add___024root* vlSelf);

bool Vfpu_add___024root___eval_phase__act(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfpu_add___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfpu_add___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfpu_add___024root___eval_phase__nba(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfpu_add___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__ico(Vfpu_add___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__nba(Vfpu_add___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_add___024root___dump_triggers__act(Vfpu_add___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpu_add___024root___eval(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval\n"); );
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
            Vfpu_add___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_add.sv", 22, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfpu_add___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfpu_add___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_add.sv", 22, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfpu_add___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_add.sv", 22, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfpu_add___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfpu_add___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfpu_add___024root___eval_debug_assertions(Vfpu_add___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_add__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_add___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->valid_i & 0xfeU))) {
        Verilated::overWidthError("valid_i");}
    if (VL_UNLIKELY((vlSelf->op_i & 0xf8U))) {
        Verilated::overWidthError("op_i");}
}
#endif  // VL_DEBUG
