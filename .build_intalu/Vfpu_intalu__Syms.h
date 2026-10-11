// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFPU_INTALU__SYMS_H_
#define VERILATED_VFPU_INTALU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfpu_intalu.h"

// INCLUDE MODULE CLASSES
#include "Vfpu_intalu___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vfpu_intalu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfpu_intalu* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfpu_intalu___024root          TOP;

    // CONSTRUCTORS
    Vfpu_intalu__Syms(VerilatedContext* contextp, const char* namep, Vfpu_intalu* modelp);
    ~Vfpu_intalu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
