// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfpu_intalu.h for the primary calling header

#ifndef VERILATED_VFPU_INTALU___024ROOT_H_
#define VERILATED_VFPU_INTALU___024ROOT_H_  // guard

#include "verilated.h"


class Vfpu_intalu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfpu_intalu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(valid_i,0,0);
    VL_IN8(op_i,3,0);
    VL_OUT8(valid_o,0,0);
    VL_OUT8(cmp_result_o,0,0);
    VL_OUT8(zero_o,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN16(imm_i,12,0);
    VL_IN(a_i,31,0);
    VL_IN(b_i,31,0);
    VL_OUT(result_o,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfpu_intalu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfpu_intalu___024root(Vfpu_intalu__Syms* symsp, const char* v__name);
    ~Vfpu_intalu___024root();
    VL_UNCOPYABLE(Vfpu_intalu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
