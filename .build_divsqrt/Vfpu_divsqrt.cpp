// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfpu_divsqrt__pch.h"

//============================================================
// Constructors

Vfpu_divsqrt::Vfpu_divsqrt(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfpu_divsqrt__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , start_i{vlSymsp->TOP.start_i}
    , op_i{vlSymsp->TOP.op_i}
    , busy_o{vlSymsp->TOP.busy_o}
    , done_o{vlSymsp->TOP.done_o}
    , flags_o{vlSymsp->TOP.flags_o}
    , a_i{vlSymsp->TOP.a_i}
    , b_i{vlSymsp->TOP.b_i}
    , result_o{vlSymsp->TOP.result_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vfpu_divsqrt::Vfpu_divsqrt(const char* _vcname__)
    : Vfpu_divsqrt(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfpu_divsqrt::~Vfpu_divsqrt() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfpu_divsqrt___024root___eval_debug_assertions(Vfpu_divsqrt___024root* vlSelf);
#endif  // VL_DEBUG
void Vfpu_divsqrt___024root___eval_static(Vfpu_divsqrt___024root* vlSelf);
void Vfpu_divsqrt___024root___eval_initial(Vfpu_divsqrt___024root* vlSelf);
void Vfpu_divsqrt___024root___eval_settle(Vfpu_divsqrt___024root* vlSelf);
void Vfpu_divsqrt___024root___eval(Vfpu_divsqrt___024root* vlSelf);

void Vfpu_divsqrt::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfpu_divsqrt::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfpu_divsqrt___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfpu_divsqrt___024root___eval_static(&(vlSymsp->TOP));
        Vfpu_divsqrt___024root___eval_initial(&(vlSymsp->TOP));
        Vfpu_divsqrt___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfpu_divsqrt___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfpu_divsqrt::eventsPending() { return false; }

uint64_t Vfpu_divsqrt::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfpu_divsqrt::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfpu_divsqrt___024root___eval_final(Vfpu_divsqrt___024root* vlSelf);

VL_ATTR_COLD void Vfpu_divsqrt::final() {
    Vfpu_divsqrt___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfpu_divsqrt::hierName() const { return vlSymsp->name(); }
const char* Vfpu_divsqrt::modelName() const { return "Vfpu_divsqrt"; }
unsigned Vfpu_divsqrt::threads() const { return 1; }
void Vfpu_divsqrt::prepareClone() const { contextp()->prepareClone(); }
void Vfpu_divsqrt::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vfpu_divsqrt::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfpu_divsqrt::trace()' called on model that was Verilated without --trace option");
}
