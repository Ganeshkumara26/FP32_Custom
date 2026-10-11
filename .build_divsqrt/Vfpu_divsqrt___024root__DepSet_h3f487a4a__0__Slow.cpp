// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_divsqrt.h for the primary calling header

#include "Vfpu_divsqrt__pch.h"
#include "Vfpu_divsqrt___024root.h"

VL_ATTR_COLD void Vfpu_divsqrt___024root___eval_static(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfpu_divsqrt___024root___eval_initial(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = vlSelf->clk_i;
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = vlSelf->rst_ni;
}

VL_ATTR_COLD void Vfpu_divsqrt___024root___eval_final(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_divsqrt___024root___dump_triggers__stl(Vfpu_divsqrt___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfpu_divsqrt___024root___eval_phase__stl(Vfpu_divsqrt___024root* vlSelf);

VL_ATTR_COLD void Vfpu_divsqrt___024root___eval_settle(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___eval_settle\n"); );
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
            Vfpu_divsqrt___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_divsqrt.sv", 22, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfpu_divsqrt___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_divsqrt___024root___dump_triggers__stl(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpu_divsqrt___024root___stl_sequent__TOP__0(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ fpu_divsqrt__DOT__exp_a_raw;
    fpu_divsqrt__DOT__exp_a_raw = 0;
    CData/*7:0*/ fpu_divsqrt__DOT__exp_b_raw;
    fpu_divsqrt__DOT__exp_b_raw = 0;
    IData/*22:0*/ fpu_divsqrt__DOT__frac_a;
    fpu_divsqrt__DOT__frac_a = 0;
    IData/*22:0*/ fpu_divsqrt__DOT__frac_b;
    fpu_divsqrt__DOT__frac_b = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__b_is_nan;
    fpu_divsqrt__DOT__b_is_nan = 0;
    IData/*29:0*/ fpu_divsqrt__DOT__sqrt_R_ext;
    fpu_divsqrt__DOT__sqrt_R_ext = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__sqrt_bit;
    fpu_divsqrt__DOT__sqrt_bit = 0;
    IData/*26:0*/ fpu_divsqrt__DOT__div_shifted;
    fpu_divsqrt__DOT__div_shifted = 0;
    IData/*23:0*/ fpu_divsqrt__DOT__fin_mant24;
    fpu_divsqrt__DOT__fin_mant24 = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__fin_guard;
    fpu_divsqrt__DOT__fin_guard = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__fin_round;
    fpu_divsqrt__DOT__fin_round = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__fin_sticky;
    fpu_divsqrt__DOT__fin_sticky = 0;
    SData/*11:0*/ fpu_divsqrt__DOT__fin_tent_exp;
    fpu_divsqrt__DOT__fin_tent_exp = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__fin_sign;
    fpu_divsqrt__DOT__fin_sign = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__pre_overflow;
    fpu_divsqrt__DOT__pre_overflow = 0;
    CData/*6:0*/ fpu_divsqrt__DOT__subshift;
    fpu_divsqrt__DOT__subshift = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__is_subnormal_path;
    fpu_divsqrt__DOT__is_subnormal_path = 0;
    IData/*25:0*/ fpu_divsqrt__DOT__wide_norm;
    fpu_divsqrt__DOT__wide_norm = 0;
    IData/*25:0*/ fpu_divsqrt__DOT__wide_shifted;
    fpu_divsqrt__DOT__wide_shifted = 0;
    IData/*23:0*/ fpu_divsqrt__DOT__mant24_pre;
    fpu_divsqrt__DOT__mant24_pre = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__guard_pre;
    fpu_divsqrt__DOT__guard_pre = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__round_pre;
    fpu_divsqrt__DOT__round_pre = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__sticky_pre;
    fpu_divsqrt__DOT__sticky_pre = 0;
    CData/*7:0*/ fpu_divsqrt__DOT__exp_pre;
    fpu_divsqrt__DOT__exp_pre = 0;
    IData/*24:0*/ fpu_divsqrt__DOT__mant25;
    fpu_divsqrt__DOT__mant25 = 0;
    SData/*8:0*/ fpu_divsqrt__DOT__exp_final9;
    fpu_divsqrt__DOT__exp_final9 = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__inexact;
    fpu_divsqrt__DOT__inexact = 0;
    CData/*0:0*/ fpu_divsqrt__DOT__overflow;
    fpu_divsqrt__DOT__overflow = 0;
    IData/*31:0*/ fpu_divsqrt__DOT__computed_result;
    fpu_divsqrt__DOT__computed_result = 0;
    CData/*4:0*/ fpu_divsqrt__DOT__computed_flags;
    fpu_divsqrt__DOT__computed_flags = 0;
    QData/*34:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__Vfuncout;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__exp_raw;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__exp_raw = 0;
    IData/*22:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__frac;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__frac = 0;
    QData/*34:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__Vfuncout;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__exp_raw;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__exp_raw = 0;
    IData/*22:0*/ __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__frac;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__frac = 0;
    // Body
    vlSelf->busy_o = vlSelf->fpu_divsqrt__DOT__busy_r;
    vlSelf->done_o = vlSelf->fpu_divsqrt__DOT__done_r;
    vlSelf->result_o = vlSelf->fpu_divsqrt__DOT__result_r;
    vlSelf->flags_o = vlSelf->fpu_divsqrt__DOT__flags_r;
    vlSelf->fpu_divsqrt__DOT__div_special_sign = ((vlSelf->a_i 
                                                   ^ vlSelf->b_i) 
                                                  >> 0x1fU);
    vlSelf->fpu_divsqrt__DOT__div_bit = ((0x3ffffffU 
                                          & VL_SHIFTL_III(26,26,32, vlSelf->fpu_divsqrt__DOT__div_R_r, 1U)) 
                                         >= vlSelf->fpu_divsqrt__DOT__div_B_r);
    fpu_divsqrt__DOT__fin_sign = ((1U & (~ (IData)(vlSelf->fpu_divsqrt__DOT__op_r))) 
                                  && (IData)(vlSelf->fpu_divsqrt__DOT__sign_result_r));
    fpu_divsqrt__DOT__sqrt_R_ext = ((0x3ffffffcU & 
                                     (vlSelf->fpu_divsqrt__DOT__sqrt_R_r 
                                      << 2U)) | (3U 
                                                 & (IData)(
                                                           (vlSelf->fpu_divsqrt__DOT__sqrt_rad_r 
                                                            >> 0x34U))));
    fpu_divsqrt__DOT__exp_b_raw = (0xffU & (vlSelf->b_i 
                                            >> 0x17U));
    fpu_divsqrt__DOT__frac_b = (0x7fffffU & vlSelf->b_i);
    vlSelf->fpu_divsqrt__DOT__b_is_zero_raw = ((0U 
                                                == (IData)(fpu_divsqrt__DOT__exp_b_raw)) 
                                               & (0U 
                                                  == fpu_divsqrt__DOT__frac_b));
    vlSelf->fpu_divsqrt__DOT__b_is_inf = ((0xffU == (IData)(fpu_divsqrt__DOT__exp_b_raw)) 
                                          & (0U == fpu_divsqrt__DOT__frac_b));
    fpu_divsqrt__DOT__b_is_nan = ((0xffU == (IData)(fpu_divsqrt__DOT__exp_b_raw)) 
                                  & (0U != fpu_divsqrt__DOT__frac_b));
    vlSelf->fpu_divsqrt__DOT__b_is_snan = ((IData)(fpu_divsqrt__DOT__b_is_nan) 
                                           & (~ (fpu_divsqrt__DOT__frac_b 
                                                 >> 0x16U)));
    fpu_divsqrt__DOT__exp_a_raw = (0xffU & (vlSelf->a_i 
                                            >> 0x17U));
    fpu_divsqrt__DOT__frac_a = (0x7fffffU & vlSelf->a_i);
    vlSelf->fpu_divsqrt__DOT__a_is_zero_raw = ((0U 
                                                == (IData)(fpu_divsqrt__DOT__exp_a_raw)) 
                                               & (0U 
                                                  == fpu_divsqrt__DOT__frac_a));
    vlSelf->fpu_divsqrt__DOT__a_is_inf = ((0xffU == (IData)(fpu_divsqrt__DOT__exp_a_raw)) 
                                          & (0U == fpu_divsqrt__DOT__frac_a));
    vlSelf->fpu_divsqrt__DOT__a_is_nan = ((0xffU == (IData)(fpu_divsqrt__DOT__exp_a_raw)) 
                                          & (0U != fpu_divsqrt__DOT__frac_a));
    vlSelf->fpu_divsqrt__DOT__a_is_snan = ((IData)(vlSelf->fpu_divsqrt__DOT__a_is_nan) 
                                           & (~ (fpu_divsqrt__DOT__frac_a 
                                                 >> 0x16U)));
    fpu_divsqrt__DOT__div_shifted = (0x7ffffffU & (vlSelf->fpu_divsqrt__DOT__div_Q_r 
                                                   << 
                                                   ((0x4000000U 
                                                     & vlSelf->fpu_divsqrt__DOT__div_Q_r)
                                                     ? 0U
                                                     : 1U)));
    if (vlSelf->fpu_divsqrt__DOT__op_r) {
        fpu_divsqrt__DOT__fin_sticky = (1U & (0U != vlSelf->fpu_divsqrt__DOT__sqrt_R_r));
        fpu_divsqrt__DOT__fin_tent_exp = (0xfffU & (IData)(vlSelf->fpu_divsqrt__DOT__exp_result_r));
        fpu_divsqrt__DOT__fin_mant24 = (0xffffffU & 
                                        (vlSelf->fpu_divsqrt__DOT__sqrt_Q_r 
                                         >> 2U));
        fpu_divsqrt__DOT__fin_guard = (1U & (vlSelf->fpu_divsqrt__DOT__sqrt_Q_r 
                                             >> 1U));
        fpu_divsqrt__DOT__fin_round = (1U & vlSelf->fpu_divsqrt__DOT__sqrt_Q_r);
    } else {
        fpu_divsqrt__DOT__fin_sticky = (1U & ((vlSelf->fpu_divsqrt__DOT__div_Q_r 
                                               << (
                                                   (0x4000000U 
                                                    & vlSelf->fpu_divsqrt__DOT__div_Q_r)
                                                    ? 0U
                                                    : 1U)) 
                                              | (0U 
                                                 != vlSelf->fpu_divsqrt__DOT__div_R_r)));
        fpu_divsqrt__DOT__fin_tent_exp = (0xfffU & 
                                          ((IData)(vlSelf->fpu_divsqrt__DOT__exp_result_r) 
                                           - ((0x4000000U 
                                               & vlSelf->fpu_divsqrt__DOT__div_Q_r)
                                               ? 0U
                                               : 1U)));
        fpu_divsqrt__DOT__fin_mant24 = (0xffffffU & 
                                        (fpu_divsqrt__DOT__div_shifted 
                                         >> 3U));
        fpu_divsqrt__DOT__fin_guard = (1U & (fpu_divsqrt__DOT__div_shifted 
                                             >> 2U));
        fpu_divsqrt__DOT__fin_round = (1U & (fpu_divsqrt__DOT__div_shifted 
                                             >> 1U));
    }
    vlSelf->fpu_divsqrt__DOT__div_R_next = (0x3ffffffU 
                                            & ((IData)(vlSelf->fpu_divsqrt__DOT__div_bit)
                                                ? (
                                                   VL_SHIFTL_III(26,26,32, vlSelf->fpu_divsqrt__DOT__div_R_r, 1U) 
                                                   - vlSelf->fpu_divsqrt__DOT__div_B_r)
                                                : VL_SHIFTL_III(26,26,32, vlSelf->fpu_divsqrt__DOT__div_R_r, 1U)));
    fpu_divsqrt__DOT__sqrt_bit = (fpu_divsqrt__DOT__sqrt_R_ext 
                                  >= (1U | (vlSelf->fpu_divsqrt__DOT__sqrt_Q_r 
                                            << 2U)));
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__frac 
        = fpu_divsqrt__DOT__frac_b;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__exp_raw 
        = fpu_divsqrt__DOT__exp_b_raw;
    if (((0U == (IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__exp_raw)) 
         & (0U == __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__frac))) {
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r = 1ULL;
    } else if ((0U == (IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__exp_raw))) {
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
            = __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__frac;
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x18U;
        if ((0x800000U & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp)) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0x16U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 1U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0x15U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 2U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0x14U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 3U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0x13U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 4U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0x12U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 5U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0x11U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 6U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0x10U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 7U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0xfU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 8U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0xeU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 9U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0xdU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0xaU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0xcU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0xbU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0xbU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0xcU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 0xaU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0xdU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 9U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0xeU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 8U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0xfU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 7U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x10U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 6U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x11U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 5U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x12U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 4U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x13U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 3U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x14U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 2U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x15U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
              >> 1U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x16U;
        }
        if ((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
             & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = 0x17U;
        }
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r 
            = ((0x7ffULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r) 
               | ((QData)((IData)((0xffffffU & (vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp 
                                                << (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz))))) 
                  << 0xbU));
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r 
            = ((0x7fffff800ULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r) 
               | (IData)((IData)((0x7feU & (((IData)(1U) 
                                             - (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz)) 
                                            << 1U)))));
    } else {
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r 
            = ((1ULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r) 
               | (0x400000000ULL | (((QData)((IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__frac)) 
                                     << 0xbU) | ((QData)((IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__exp_raw)) 
                                                 << 1U))));
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r 
            = (0x7fffffffeULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r);
    }
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__Vfuncout 
        = vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r;
    vlSelf->fpu_divsqrt__DOT__norm_b = __Vfunc_fpu_divsqrt__DOT__normalize_operand__1__Vfuncout;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__frac 
        = fpu_divsqrt__DOT__frac_a;
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__exp_raw 
        = fpu_divsqrt__DOT__exp_a_raw;
    if (((0U == (IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__exp_raw)) 
         & (0U == __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__frac))) {
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r = 1ULL;
    } else if ((0U == (IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__exp_raw))) {
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
            = __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__frac;
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x18U;
        if ((0x800000U & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp)) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0x16U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 1U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0x15U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 2U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0x14U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 3U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0x13U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 4U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0x12U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 5U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0x11U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 6U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0x10U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 7U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0xfU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 8U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0xeU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 9U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0xdU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0xaU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0xcU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0xbU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0xbU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0xcU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 0xaU) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0xdU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 9U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0xeU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 8U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0xfU;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 7U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x10U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 6U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x11U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 5U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x12U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 4U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x13U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 3U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x14U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 2U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x15U;
        }
        if (((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
              >> 1U) & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x16U;
        }
        if ((vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
             & (0x18U == (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)))) {
            vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = 0x17U;
        }
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r 
            = ((0x7ffULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r) 
               | ((QData)((IData)((0xffffffU & (vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp 
                                                << (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz))))) 
                  << 0xbU));
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r 
            = ((0x7fffff800ULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r) 
               | (IData)((IData)((0x7feU & (((IData)(1U) 
                                             - (IData)(vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz)) 
                                            << 1U)))));
    } else {
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r 
            = ((1ULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r) 
               | (0x400000000ULL | (((QData)((IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__frac)) 
                                     << 0xbU) | ((QData)((IData)(__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__exp_raw)) 
                                                 << 1U))));
        vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r 
            = (0x7fffffffeULL & vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r);
    }
    __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__Vfuncout 
        = vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r;
    vlSelf->fpu_divsqrt__DOT__norm_a = __Vfunc_fpu_divsqrt__DOT__normalize_operand__0__Vfuncout;
    vlSelf->fpu_divsqrt__DOT__sqrt_passthrough = ((IData)(vlSelf->fpu_divsqrt__DOT__a_is_zero_raw) 
                                                  | (IData)(vlSelf->fpu_divsqrt__DOT__a_is_inf));
    vlSelf->fpu_divsqrt__DOT__sqrt_result_is_nan = 
        (1U & ((IData)(vlSelf->fpu_divsqrt__DOT__a_is_nan) 
               | ((vlSelf->a_i >> 0x1fU) & (~ (IData)(vlSelf->fpu_divsqrt__DOT__a_is_zero_raw)))));
    vlSelf->fpu_divsqrt__DOT__div_result_is_nan = (
                                                   (((IData)(vlSelf->fpu_divsqrt__DOT__a_is_nan) 
                                                     | (IData)(fpu_divsqrt__DOT__b_is_nan)) 
                                                    | ((IData)(vlSelf->fpu_divsqrt__DOT__a_is_inf) 
                                                       & (IData)(vlSelf->fpu_divsqrt__DOT__b_is_inf))) 
                                                   | ((IData)(vlSelf->fpu_divsqrt__DOT__a_is_zero_raw) 
                                                      & (IData)(vlSelf->fpu_divsqrt__DOT__b_is_zero_raw)));
    vlSelf->fpu_divsqrt__DOT__div_result_is_inf = (
                                                   (~ (IData)(vlSelf->fpu_divsqrt__DOT__div_result_is_nan)) 
                                                   & ((IData)(vlSelf->fpu_divsqrt__DOT__a_is_inf) 
                                                      | (IData)(vlSelf->fpu_divsqrt__DOT__b_is_zero_raw)));
    vlSelf->fpu_divsqrt__DOT__div_dbz = (((~ (IData)(vlSelf->fpu_divsqrt__DOT__div_result_is_nan)) 
                                          & (~ (IData)(vlSelf->fpu_divsqrt__DOT__a_is_zero_raw))) 
                                         & (IData)(vlSelf->fpu_divsqrt__DOT__b_is_zero_raw));
    vlSelf->fpu_divsqrt__DOT__div_result_is_zero = 
        (((~ (IData)(vlSelf->fpu_divsqrt__DOT__div_result_is_nan)) 
          & (~ (IData)(vlSelf->fpu_divsqrt__DOT__div_result_is_inf))) 
         & ((IData)(vlSelf->fpu_divsqrt__DOT__a_is_zero_raw) 
            | (IData)(vlSelf->fpu_divsqrt__DOT__b_is_inf)));
    fpu_divsqrt__DOT__subshift = (VL_LTS_III(12, 0U, (IData)(fpu_divsqrt__DOT__fin_tent_exp))
                                   ? 0U : (VL_LTS_III(12, 0x26U, 
                                                      (0xfffU 
                                                       & ((IData)(1U) 
                                                          - (IData)(fpu_divsqrt__DOT__fin_tent_exp))))
                                            ? 0x26U
                                            : (0x7fU 
                                               & ((IData)(1U) 
                                                  - (IData)(fpu_divsqrt__DOT__fin_tent_exp)))));
    fpu_divsqrt__DOT__pre_overflow = ((~ (IData)(vlSelf->fpu_divsqrt__DOT__op_r)) 
                                      & VL_LTES_III(12, 0xffU, (IData)(fpu_divsqrt__DOT__fin_tent_exp)));
    vlSelf->fpu_divsqrt__DOT__sqrt_Q_next = ((0x3fffffeU 
                                              & (vlSelf->fpu_divsqrt__DOT__sqrt_Q_r 
                                                 << 1U)) 
                                             | (IData)(fpu_divsqrt__DOT__sqrt_bit));
    vlSelf->fpu_divsqrt__DOT__sqrt_R_next = (0x3fffffffU 
                                             & ((IData)(fpu_divsqrt__DOT__sqrt_bit)
                                                 ? 
                                                (fpu_divsqrt__DOT__sqrt_R_ext 
                                                 - 
                                                 (1U 
                                                  | (vlSelf->fpu_divsqrt__DOT__sqrt_Q_r 
                                                     << 2U)))
                                                 : fpu_divsqrt__DOT__sqrt_R_ext));
    vlSelf->fpu_divsqrt__DOT__setup_sqrt_rad_full = 
        ((1U & ((IData)((vlSelf->fpu_divsqrt__DOT__norm_a 
                         >> 1U)) - (IData)(1U))) ? 
         ((QData)((IData)((0xffffffU & (IData)((vlSelf->fpu_divsqrt__DOT__norm_a 
                                                >> 0xbU))))) 
          << 0x1eU) : ((QData)((IData)((0xffffffU & (IData)(
                                                            (vlSelf->fpu_divsqrt__DOT__norm_a 
                                                             >> 0xbU))))) 
                       << 0x1dU));
    vlSelf->fpu_divsqrt__DOT__setup_div_ge = ((0xffffffU 
                                               & (IData)(
                                                         (vlSelf->fpu_divsqrt__DOT__norm_a 
                                                          >> 0xbU))) 
                                              >= (0xffffffU 
                                                  & (IData)(
                                                            (vlSelf->fpu_divsqrt__DOT__norm_b 
                                                             >> 0xbU))));
    fpu_divsqrt__DOT__is_subnormal_path = ((~ (IData)(fpu_divsqrt__DOT__pre_overflow)) 
                                           & VL_GTES_III(12, 0U, (IData)(fpu_divsqrt__DOT__fin_tent_exp)));
    fpu_divsqrt__DOT__wide_norm = ((fpu_divsqrt__DOT__fin_mant24 
                                    << 2U) | (((IData)(fpu_divsqrt__DOT__fin_guard) 
                                               << 1U) 
                                              | (IData)(fpu_divsqrt__DOT__fin_round)));
    fpu_divsqrt__DOT__wide_shifted = (0x3ffffffU & 
                                      VL_SHIFTR_III(26,26,7, fpu_divsqrt__DOT__wide_norm, (IData)(fpu_divsqrt__DOT__subshift)));
    if (fpu_divsqrt__DOT__is_subnormal_path) {
        fpu_divsqrt__DOT__exp_pre = 0U;
        fpu_divsqrt__DOT__sticky_pre = ((IData)(fpu_divsqrt__DOT__fin_sticky) 
                                        | ((0U != (IData)(fpu_divsqrt__DOT__subshift)) 
                                           & (0U != 
                                              ((~ VL_SHIFTL_III(26,26,7, (IData)(0x3ffffffU), (IData)(fpu_divsqrt__DOT__subshift))) 
                                               & fpu_divsqrt__DOT__wide_norm))));
        fpu_divsqrt__DOT__mant24_pre = (0xffffffU & 
                                        (fpu_divsqrt__DOT__wide_shifted 
                                         >> 2U));
        fpu_divsqrt__DOT__guard_pre = (1U & (fpu_divsqrt__DOT__wide_shifted 
                                             >> 1U));
        fpu_divsqrt__DOT__round_pre = (1U & fpu_divsqrt__DOT__wide_shifted);
    } else {
        fpu_divsqrt__DOT__exp_pre = (0xffU & (IData)(fpu_divsqrt__DOT__fin_tent_exp));
        fpu_divsqrt__DOT__sticky_pre = fpu_divsqrt__DOT__fin_sticky;
        fpu_divsqrt__DOT__mant24_pre = (0xffffffU & fpu_divsqrt__DOT__fin_mant24);
        fpu_divsqrt__DOT__guard_pre = (1U & (IData)(fpu_divsqrt__DOT__fin_guard));
        fpu_divsqrt__DOT__round_pre = (1U & (IData)(fpu_divsqrt__DOT__fin_round));
    }
    fpu_divsqrt__DOT__inexact = ((IData)(fpu_divsqrt__DOT__guard_pre) 
                                 | ((IData)(fpu_divsqrt__DOT__round_pre) 
                                    | ((IData)(fpu_divsqrt__DOT__sticky_pre) 
                                       | (IData)(fpu_divsqrt__DOT__pre_overflow))));
    fpu_divsqrt__DOT__mant25 = (0x1ffffffU & (fpu_divsqrt__DOT__mant24_pre 
                                              + ((IData)(fpu_divsqrt__DOT__guard_pre) 
                                                 & ((IData)(fpu_divsqrt__DOT__round_pre) 
                                                    | ((IData)(fpu_divsqrt__DOT__sticky_pre) 
                                                       | fpu_divsqrt__DOT__mant24_pre)))));
    fpu_divsqrt__DOT__exp_final9 = (0x1ffU & ((IData)(fpu_divsqrt__DOT__exp_pre) 
                                              + (1U 
                                                 & (fpu_divsqrt__DOT__mant25 
                                                    >> 0x18U))));
    fpu_divsqrt__DOT__overflow = ((IData)(fpu_divsqrt__DOT__pre_overflow) 
                                  | (0xffU <= (IData)(fpu_divsqrt__DOT__exp_final9)));
    if (fpu_divsqrt__DOT__overflow) {
        fpu_divsqrt__DOT__computed_flags = 5U;
        fpu_divsqrt__DOT__computed_result = (0x7f800000U 
                                             | ((IData)(fpu_divsqrt__DOT__fin_sign) 
                                                << 0x1fU));
    } else {
        fpu_divsqrt__DOT__computed_flags = ((((IData)(fpu_divsqrt__DOT__is_subnormal_path) 
                                              & (IData)(fpu_divsqrt__DOT__inexact)) 
                                             << 1U) 
                                            | (IData)(fpu_divsqrt__DOT__inexact));
        fpu_divsqrt__DOT__computed_result = (((IData)(fpu_divsqrt__DOT__fin_sign) 
                                              << 0x1fU) 
                                             | ((0x7f800000U 
                                                 & ((IData)(fpu_divsqrt__DOT__exp_final9) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((0x1000000U 
                                                       & fpu_divsqrt__DOT__mant25)
                                                       ? 
                                                      (fpu_divsqrt__DOT__mant25 
                                                       >> 1U)
                                                       : fpu_divsqrt__DOT__mant25))));
    }
    if (vlSelf->fpu_divsqrt__DOT__special_active_r) {
        vlSelf->fpu_divsqrt__DOT__final_flags_comb 
            = vlSelf->fpu_divsqrt__DOT__special_flags_r;
        vlSelf->fpu_divsqrt__DOT__final_result_comb 
            = vlSelf->fpu_divsqrt__DOT__special_result_r;
    } else {
        vlSelf->fpu_divsqrt__DOT__final_flags_comb 
            = fpu_divsqrt__DOT__computed_flags;
        vlSelf->fpu_divsqrt__DOT__final_result_comb 
            = fpu_divsqrt__DOT__computed_result;
    }
}

VL_ATTR_COLD void Vfpu_divsqrt___024root___eval_stl(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfpu_divsqrt___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfpu_divsqrt___024root___eval_triggers__stl(Vfpu_divsqrt___024root* vlSelf);

VL_ATTR_COLD bool Vfpu_divsqrt___024root___eval_phase__stl(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfpu_divsqrt___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfpu_divsqrt___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_divsqrt___024root___dump_triggers__ico(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vfpu_divsqrt___024root___dump_triggers__act(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vfpu_divsqrt___024root___dump_triggers__nba(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpu_divsqrt___024root___ctor_var_reset(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->start_i = VL_RAND_RESET_I(1);
    vlSelf->a_i = VL_RAND_RESET_I(32);
    vlSelf->b_i = VL_RAND_RESET_I(32);
    vlSelf->op_i = VL_RAND_RESET_I(1);
    vlSelf->busy_o = VL_RAND_RESET_I(1);
    vlSelf->done_o = VL_RAND_RESET_I(1);
    vlSelf->result_o = VL_RAND_RESET_I(32);
    vlSelf->flags_o = VL_RAND_RESET_I(5);
    vlSelf->fpu_divsqrt__DOT__a_is_inf = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__b_is_inf = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__a_is_nan = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__a_is_snan = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__b_is_snan = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__a_is_zero_raw = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__b_is_zero_raw = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__norm_a = VL_RAND_RESET_Q(35);
    vlSelf->fpu_divsqrt__DOT__norm_b = VL_RAND_RESET_Q(35);
    vlSelf->fpu_divsqrt__DOT__div_result_is_nan = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__div_result_is_inf = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__div_dbz = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__div_result_is_zero = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__div_special_sign = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__sqrt_result_is_nan = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__sqrt_passthrough = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__busy_r = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__done_r = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__cnt_r = VL_RAND_RESET_I(5);
    vlSelf->fpu_divsqrt__DOT__total_r = VL_RAND_RESET_I(5);
    vlSelf->fpu_divsqrt__DOT__finalize_r = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__op_r = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__sign_result_r = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__exp_result_r = VL_RAND_RESET_I(12);
    vlSelf->fpu_divsqrt__DOT__special_active_r = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__special_result_r = VL_RAND_RESET_I(32);
    vlSelf->fpu_divsqrt__DOT__special_flags_r = VL_RAND_RESET_I(5);
    vlSelf->fpu_divsqrt__DOT__div_R_r = VL_RAND_RESET_I(26);
    vlSelf->fpu_divsqrt__DOT__div_B_r = VL_RAND_RESET_I(24);
    vlSelf->fpu_divsqrt__DOT__div_Q_r = VL_RAND_RESET_I(27);
    vlSelf->fpu_divsqrt__DOT__sqrt_rad_r = VL_RAND_RESET_Q(54);
    vlSelf->fpu_divsqrt__DOT__sqrt_R_r = VL_RAND_RESET_I(30);
    vlSelf->fpu_divsqrt__DOT__sqrt_Q_r = VL_RAND_RESET_I(26);
    vlSelf->fpu_divsqrt__DOT__result_r = VL_RAND_RESET_I(32);
    vlSelf->fpu_divsqrt__DOT__flags_r = VL_RAND_RESET_I(5);
    vlSelf->fpu_divsqrt__DOT__setup_div_ge = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__setup_sqrt_rad_full = VL_RAND_RESET_Q(54);
    vlSelf->fpu_divsqrt__DOT__div_bit = VL_RAND_RESET_I(1);
    vlSelf->fpu_divsqrt__DOT__div_R_next = VL_RAND_RESET_I(26);
    vlSelf->fpu_divsqrt__DOT__sqrt_R_next = VL_RAND_RESET_I(30);
    vlSelf->fpu_divsqrt__DOT__sqrt_Q_next = VL_RAND_RESET_I(26);
    vlSelf->fpu_divsqrt__DOT__final_result_comb = VL_RAND_RESET_I(32);
    vlSelf->fpu_divsqrt__DOT__final_flags_comb = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__r = VL_RAND_RESET_Q(35);
    vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__tmp = VL_RAND_RESET_I(24);
    vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__0__lz = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__r = VL_RAND_RESET_Q(35);
    vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__tmp = VL_RAND_RESET_I(24);
    vlSelf->__Vfunc_fpu_divsqrt__DOT__normalize_operand__1__lz = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = VL_RAND_RESET_I(1);
}
