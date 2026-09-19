/*
 * IOATIR500GLContext_page_off_texture_Port.cpp
 *
 * IOATIR500GLContext::page_off_texture (real addr 0x9740, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x9740 */
IOReturn IOATIR500GLContext::page_off_texture(UInt32 param_1, UInt32 param_2, unsigned int param_3, unsigned int param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(param_1 + 200) + 0x840));
  piVar1 = M<SInt32 *>(param_1 + 200);
  if (M<char>(piVar1 + 0x20) == '\0') {
LAB_00009800:
    GH_IOLockUnlock(piVar1[0x210]);
    uVar2 = 0;
  }
  else {
    if (param_2 < M<UInt32>(M<SInt32>(param_1 + 0x88) + 0x14)) {
      iVar3 = M<SInt32>(param_2 * 4 + M<SInt32>(M<SInt32>(param_1 + 0x88) + 0x10));
      if (iVar3 != 0) {
        iVar3 = (param_3 >> 0x10) * 2 + M<SInt32>(iVar3 + 0x14);
        if ((((UInt32)M<UInt16>(iVar3 + 0x28) & ~(UInt32)M<UInt16>(iVar3 + 0x1c)) >>
             (param_3 & 0x3f) & 1) != 0) {
          VCALL(*piVar1, 0x52c)(piVar1);
          piVar1 = M<SInt32 *>(param_1 + 200);
        }
        goto LAB_00009800;
      }
    }
    GH_IOLockUnlock(piVar1[0x210]);
    uVar2 = 0xe00002c2;
  }
  return uVar2;
}
