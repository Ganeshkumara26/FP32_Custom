// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFPU_ADD__SYMS_H_
#define VERILATED_VFPU_ADD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfpu_add.h"

// INCLUDE MODULE CLASSES
#include "Vfpu_add___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vfpu_add__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfpu_add* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfpu_add___024root             TOP;

    // CONSTRUCTORS
    Vfpu_add__Syms(VerilatedContext* contextp, const char* namep, Vfpu_add* modelp);
    ~Vfpu_add__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
