/*
 * IOATIR5002DContext_create_shared_Port.cpp
 *
 * IOATIR5002DContext::create_shared (real addr 0xbc90, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");


inline void *operator new(size_t, void *where) { return where; }   /* placement new (the same inline definition as ATIRadeonX1000_ContextFactories.cpp) */

/* real addr 0xbc90 */
bool IOATIR5002DContext::create_shared() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *this_00;
  UInt32 uVar1;
  SInt32 iVar2;
  UInt8 bVar3;
  
  /* gcc 4.0.1 emits no null test after an unconditional `new T()` here; the shipped code tests the allocation before running the constructor (difftest:
   * with a failed allocation the rebuilt code ran the constructor on a null pointer). So the allocation is made by hand and tested. */
  void *mem = OSObject::operator new(0x28);
  this_00 = (UInt8 *)(mem ? ::new (mem) IOATIR500Shared() : 0);
  bVar3 = (this_00 == (UInt8 *)0x0) << 1;
  M<UInt8 *>(self + kIOATIR5002DContext_sharedAllocator) = this_00;
  if ((bool)(bVar3 >> 1 & 1)) {
    uVar1 = 0;
  }
  else {
    iVar2 = VCALL(M<SInt32>(this_00), 0x48)(this_00);
    if (iVar2 == 0) {
      VCALL(*M<SInt32 *>(self + kIOATIR5002DContext_sharedAllocator), 0x18)(M<SInt32 *>(self + kIOATIR5002DContext_sharedAllocator));
      uVar1 = 0;
      M<UInt32>(self + kIOATIR5002DContext_sharedAllocator) = 0;
    }
    else {
      uVar1 = 1;
      M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0xc) = M<UInt32>(self + kIOATIR5002DContext_accelerator);
      M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 8) = M<UInt32>(self + kIOATIR5002DContext_task);
    }
  }
  return uVar1;
}
