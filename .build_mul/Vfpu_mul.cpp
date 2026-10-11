// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfpu_mul__pch.h"

//============================================================
// Constructors

Vfpu_mul::Vfpu_mul(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfpu_mul__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , valid_i{vlSymsp->TOP.valid_i}
    , valid_o{vlSymsp->TOP.valid_o}
    , flags_o{vlSymsp->TOP.flags_o}
    , a_i{vlSymsp->TOP.a_i}
    , b_i{vlSymsp->TOP.b_i}
    , result_o{vlSymsp->TOP.result_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vfpu_mul::Vfpu_mul(const char* _vcname__)
    : Vfpu_mul(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfpu_mul::~Vfpu_mul() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfpu_mul___024root___eval_debug_assertions(Vfpu_mul___024root* vlSelf);
#endif  // VL_DEBUG
void Vfpu_mul___024root___eval_static(Vfpu_mul___024root* vlSelf);
void Vfpu_mul___024root___eval_initial(Vfpu_mul___024root* vlSelf);
void Vfpu_mul___024root___eval_settle(Vfpu_mul___024root* vlSelf);
void Vfpu_mul___024root___eval(Vfpu_mul___024root* vlSelf);

void Vfpu_mul::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfpu_mul::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfpu_mul___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfpu_mul___024root___eval_static(&(vlSymsp->TOP));
        Vfpu_mul___024root___eval_initial(&(vlSymsp->TOP));
        Vfpu_mul___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfpu_mul___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfpu_mul::eventsPending() { return false; }

uint64_t Vfpu_mul::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfpu_mul::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfpu_mul___024root___eval_final(Vfpu_mul___024root* vlSelf);

VL_ATTR_COLD void Vfpu_mul::final() {
    Vfpu_mul___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfpu_mul::hierName() const { return vlSymsp->name(); }
const char* Vfpu_mul::modelName() const { return "Vfpu_mul"; }
unsigned Vfpu_mul::threads() const { return 1; }
void Vfpu_mul::prepareClone() const { contextp()->prepareClone(); }
void Vfpu_mul::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vfpu_mul::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfpu_mul::trace()' called on model that was Verilated without --trace option");
}
