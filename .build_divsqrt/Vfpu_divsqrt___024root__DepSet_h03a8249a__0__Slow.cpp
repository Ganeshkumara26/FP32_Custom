// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu_divsqrt.h for the primary calling header

#include "Vfpu_divsqrt__pch.h"
#include "Vfpu_divsqrt__Syms.h"
#include "Vfpu_divsqrt___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu_divsqrt___024root___dump_triggers__stl(Vfpu_divsqrt___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpu_divsqrt___024root___eval_triggers__stl(Vfpu_divsqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu_divsqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu_divsqrt___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpu_divsqrt___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
