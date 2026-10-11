// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfpu_intalu__pch.h"

//============================================================
// Constructors

Vfpu_intalu::Vfpu_intalu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfpu_intalu__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , valid_i{vlSymsp->TOP.valid_i}
    , op_i{vlSymsp->TOP.op_i}
    , valid_o{vlSymsp->TOP.valid_o}
    , cmp_result_o{vlSymsp->TOP.cmp_result_o}
    , zero_o{vlSymsp->TOP.zero_o}
    , imm_i{vlSymsp->TOP.imm_i}
    , a_i{vlSymsp->TOP.a_i}
    , b_i{vlSymsp->TOP.b_i}
    , result_o{vlSymsp->TOP.result_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vfpu_intalu::Vfpu_intalu(const char* _vcname__)
    : Vfpu_intalu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfpu_intalu::~Vfpu_intalu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfpu_intalu___024root___eval_debug_assertions(Vfpu_intalu___024root* vlSelf);
#endif  // VL_DEBUG
void Vfpu_intalu___024root___eval_static(Vfpu_intalu___024root* vlSelf);
void Vfpu_intalu___024root___eval_initial(Vfpu_intalu___024root* vlSelf);
void Vfpu_intalu___024root___eval_settle(Vfpu_intalu___024root* vlSelf);
void Vfpu_intalu___024root___eval(Vfpu_intalu___024root* vlSelf);

void Vfpu_intalu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfpu_intalu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfpu_intalu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfpu_intalu___024root___eval_static(&(vlSymsp->TOP));
        Vfpu_intalu___024root___eval_initial(&(vlSymsp->TOP));
        Vfpu_intalu___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfpu_intalu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfpu_intalu::eventsPending() { return false; }

uint64_t Vfpu_intalu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfpu_intalu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfpu_intalu___024root___eval_final(Vfpu_intalu___024root* vlSelf);

VL_ATTR_COLD void Vfpu_intalu::final() {
    Vfpu_intalu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfpu_intalu::hierName() const { return vlSymsp->name(); }
const char* Vfpu_intalu::modelName() const { return "Vfpu_intalu"; }
unsigned Vfpu_intalu::threads() const { return 1; }
void Vfpu_intalu::prepareClone() const { contextp()->prepareClone(); }
void Vfpu_intalu::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vfpu_intalu::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfpu_intalu::trace()' called on model that was Verilated without --trace option");
}
