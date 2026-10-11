// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_intalu.h for the primary calling header

#include "Vfpu_intalu__pch.h"
#include "Vfpu_intalu___024root.h"

VL_INLINE_OPT void Vfpu_intalu___024root___ico_sequent__TOP__0(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___ico_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ fpu_intalu__DOT__imm_sext;
    fpu_intalu__DOT__imm_sext = 0;
    IData/*31:0*/ fpu_intalu__DOT__itof_abs;
    fpu_intalu__DOT__itof_abs = 0;
    CData/*5:0*/ fpu_intalu__DOT__itof_lz;
    fpu_intalu__DOT__itof_lz = 0;
    IData/*31:0*/ fpu_intalu__DOT__itof_shifted;
    fpu_intalu__DOT__itof_shifted = 0;
    IData/*23:0*/ fpu_intalu__DOT__itof_mant24;
    fpu_intalu__DOT__itof_mant24 = 0;
    IData/*31:0*/ fpu_intalu__DOT__result_comb;
    fpu_intalu__DOT__result_comb = 0;
    CData/*5:0*/ __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout;
    __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fpu_intalu__DOT__clz32__0__v;
    __Vfunc_fpu_intalu__DOT__clz32__0__v = 0;
    // Body
    vlSelf->valid_o = vlSelf->valid_i;
    fpu_intalu__DOT__imm_sext = (((- (IData)((1U & 
                                              ((IData)(vlSelf->imm_i) 
                                               >> 0xcU)))) 
                                  << 0xdU) | (IData)(vlSelf->imm_i));
    vlSelf->cmp_result_o = VL_LTS_III(32, vlSelf->a_i, vlSelf->b_i);
    fpu_intalu__DOT__itof_abs = ((vlSelf->a_i >> 0x1fU)
                                  ? ((IData)(1U) + 
                                     (~ vlSelf->a_i))
                                  : vlSelf->a_i);
    __Vfunc_fpu_intalu__DOT__clz32__0__v = fpu_intalu__DOT__itof_abs;
    __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x20U;
    if ((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x1fU)) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x1eU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 1U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x1dU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 2U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x1cU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 3U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x1bU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 4U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x1aU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 5U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x19U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 6U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x18U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 7U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x17U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 8U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x16U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 9U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x15U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0xaU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x14U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0xbU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x13U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0xcU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x12U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0xdU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x11U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0xeU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0x10U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0xfU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0xfU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x10U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0xeU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x11U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0xdU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x12U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0xcU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x13U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0xbU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x14U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 0xaU) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x15U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 9U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x16U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 8U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x17U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 7U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x18U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 6U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x19U;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 5U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x1aU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 4U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x1bU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 3U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x1cU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 2U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x1dU;
    }
    if (((__Vfunc_fpu_intalu__DOT__clz32__0__v >> 1U) 
         & (0x20U == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x1eU;
    }
    if ((__Vfunc_fpu_intalu__DOT__clz32__0__v & (0x20U 
                                                 == (IData)(__Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout)))) {
        __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout = 0x1fU;
    }
    fpu_intalu__DOT__itof_lz = __Vfunc_fpu_intalu__DOT__clz32__0__Vfuncout;
    fpu_intalu__DOT__itof_shifted = VL_SHIFTL_III(32,32,6, fpu_intalu__DOT__itof_abs, (IData)(fpu_intalu__DOT__itof_lz));
    fpu_intalu__DOT__itof_mant24 = (0xffffffU & ((0x7fffffU 
                                                  & (fpu_intalu__DOT__itof_shifted 
                                                     >> 8U)) 
                                                 + 
                                                 (1U 
                                                  & ((fpu_intalu__DOT__itof_shifted 
                                                      >> 7U) 
                                                     & (IData)(
                                                               ((0U 
                                                                 != 
                                                                 (0x140U 
                                                                  & fpu_intalu__DOT__itof_shifted)) 
                                                                | (0U 
                                                                   != 
                                                                   (0x3fU 
                                                                    & VL_SHIFTL_III(6,6,6, fpu_intalu__DOT__itof_abs, (IData)(fpu_intalu__DOT__itof_lz))))))))));
    fpu_intalu__DOT__result_comb = ((8U & (IData)(vlSelf->op_i))
                                     ? ((4U & (IData)(vlSelf->op_i))
                                         ? 0U : ((2U 
                                                  & (IData)(vlSelf->op_i))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->op_i))
                                                   ? fpu_intalu__DOT__imm_sext
                                                   : 0U)
                                                  : 0U))
                                     : ((4U & (IData)(vlSelf->op_i))
                                         ? ((2U & (IData)(vlSelf->op_i))
                                             ? ((1U 
                                                 & (IData)(vlSelf->op_i))
                                                 ? 
                                                ((0U 
                                                  == vlSelf->a_i)
                                                  ? 0U
                                                  : 
                                                 ((0x80000000U 
                                                   & vlSelf->a_i) 
                                                  | ((0x7f800000U 
                                                      & ((((IData)(0x9eU) 
                                                           - (IData)(fpu_intalu__DOT__itof_lz)) 
                                                          + 
                                                          (1U 
                                                           & (fpu_intalu__DOT__itof_mant24 
                                                              >> 0x17U))) 
                                                         << 0x17U)) 
                                                     | ((0x800000U 
                                                         & fpu_intalu__DOT__itof_mant24)
                                                         ? 0U
                                                         : 
                                                        (0x7fffffU 
                                                         & fpu_intalu__DOT__itof_mant24)))))
                                                 : (IData)(vlSelf->cmp_result_o))
                                             : ((1U 
                                                 & (IData)(vlSelf->op_i))
                                                 ? 
                                                (vlSelf->a_i 
                                                 - vlSelf->b_i)
                                                 : 
                                                (vlSelf->a_i 
                                                 + fpu_intalu__DOT__imm_sext)))
                                         : 0U));
    vlSelf->result_o = fpu_intalu__DOT__result_comb;
    vlSelf->zero_o = (0U == fpu_intalu__DOT__result_comb);
}

void Vfpu_intalu___024root___eval_ico(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vfpu_intalu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfpu_intalu___024root___eval_triggers__ico(Vfpu_intalu___024root* vlSelf);

bool Vfpu_intalu___024root___eval_phase__ico(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfpu_intalu___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vfpu_intalu___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfpu_intalu___024root___eval_act(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_act\n"); );
}

void Vfpu_intalu___024root___eval_nba(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_nba\n"); );
}

void Vfpu_intalu___024root___eval_triggers__act(Vfpu_intalu___024root* vlSelf);

bool Vfpu_intalu___024root___eval_phase__act(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfpu_intalu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfpu_intalu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfpu_intalu___024root___eval_phase__nba(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfpu_intalu___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__ico(Vfpu_intalu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__nba(Vfpu_intalu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__act(Vfpu_intalu___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpu_intalu___024root___eval(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval\n"); );
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
            Vfpu_intalu___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_intalu.sv", 20, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfpu_intalu___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfpu_intalu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_intalu.sv", 20, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfpu_intalu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_intalu.sv", 20, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfpu_intalu___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfpu_intalu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfpu_intalu___024root___eval_debug_assertions(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->valid_i & 0xfeU))) {
        Verilated::overWidthError("valid_i");}
    if (VL_UNLIKELY((vlSelf->op_i & 0xf0U))) {
        Verilated::overWidthError("op_i");}
    if (VL_UNLIKELY((vlSelf->imm_i & 0xe000U))) {
        Verilated::overWidthError("imm_i");}
}
#endif  // VL_DEBUG
