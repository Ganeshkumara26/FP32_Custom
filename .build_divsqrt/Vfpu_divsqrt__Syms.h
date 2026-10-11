// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFPU_DIVSQRT__SYMS_H_
#define VERILATED_VFPU_DIVSQRT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfpu_divsqrt.h"

// INCLUDE MODULE CLASSES
#include "Vfpu_divsqrt___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vfpu_divsqrt__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfpu_divsqrt* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfpu_divsqrt___024root         TOP;

    // CONSTRUCTORS
    Vfpu_divsqrt__Syms(VerilatedContext* contextp, const char* namep, Vfpu_divsqrt* modelp);
    ~Vfpu_divsqrt__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
