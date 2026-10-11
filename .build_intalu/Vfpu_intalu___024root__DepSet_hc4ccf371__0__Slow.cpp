// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_intalu.h for the primary calling header

#include "Vfpu_intalu__pch.h"
#include "Vfpu_intalu___024root.h"

VL_ATTR_COLD void Vfpu_intalu___024root___eval_static(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfpu_intalu___024root___eval_initial(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_initial\n"); );
}

VL_ATTR_COLD void Vfpu_intalu___024root___eval_final(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__stl(Vfpu_intalu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfpu_intalu___024root___eval_phase__stl(Vfpu_intalu___024root* vlSelf);

VL_ATTR_COLD void Vfpu_intalu___024root___eval_settle(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_settle\n"); );
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
            Vfpu_intalu___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/claude/work/fpu_project/rtl/fpu_intalu.sv", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfpu_intalu___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__stl(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vfpu_intalu___024root___ico_sequent__TOP__0(Vfpu_intalu___024root* vlSelf);

VL_ATTR_COLD void Vfpu_intalu___024root___eval_stl(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfpu_intalu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfpu_intalu___024root___eval_triggers__stl(Vfpu_intalu___024root* vlSelf);

VL_ATTR_COLD bool Vfpu_intalu___024root___eval_phase__stl(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfpu_intalu___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfpu_intalu___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__ico(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__act(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_intalu___024root___dump_triggers__nba(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpu_intalu___024root___ctor_var_reset(Vfpu_intalu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_intalu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_intalu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->valid_i = VL_RAND_RESET_I(1);
    vlSelf->op_i = VL_RAND_RESET_I(4);
    vlSelf->a_i = VL_RAND_RESET_I(32);
    vlSelf->b_i = VL_RAND_RESET_I(32);
    vlSelf->imm_i = VL_RAND_RESET_I(13);
    vlSelf->valid_o = VL_RAND_RESET_I(1);
    vlSelf->result_o = VL_RAND_RESET_I(32);
    vlSelf->cmp_result_o = VL_RAND_RESET_I(1);
    vlSelf->zero_o = VL_RAND_RESET_I(1);
}
