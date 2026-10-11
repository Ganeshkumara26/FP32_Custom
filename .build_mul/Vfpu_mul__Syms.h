// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFPU_MUL__SYMS_H_
#define VERILATED_VFPU_MUL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfpu_mul.h"

// INCLUDE MODULE CLASSES
#include "Vfpu_mul___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vfpu_mul__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfpu_mul* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfpu_mul___024root             TOP;

    // CONSTRUCTORS
    Vfpu_mul__Syms(VerilatedContext* contextp, const char* namep, Vfpu_mul* modelp);
    ~Vfpu_mul__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
