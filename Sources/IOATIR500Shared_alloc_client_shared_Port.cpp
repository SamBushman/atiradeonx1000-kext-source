/*
 * IOATIR500Shared_alloc_client_shared_Port.cpp
 *
 * IOATIR500Shared::alloc_client_shared (real addr 0x16d50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFree(...) asm("_IOFree");
extern "C" UInt32 GH_IOMalloc(...) asm("_IOMalloc");
extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(...) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");


/* real addr 0x16d50 */
bool IOATIR500Shared::alloc_client_shared(UInt32 param_1, sIOClientShared**param_2, unsigned int*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 *puVar4;
  UInt32 *puVar5;
  
  puVar4 = (UInt32 *)0x0;
  puVar5 = M<UInt32 *>(self + 0x20);
  while (puVar5 != (UInt32 *)0x0) {
LAB_00016f00:
    puVar4 = puVar5;
    if (param_1 < (UInt32)puVar4[6]) {
      *param_2 = (sIOClientShared *)(param_1 * 0x40 + puVar4[4]);
      *param_3 = param_1 * 0x40 + puVar4[5];
      *(UInt32 *)(UInt8 *)*param_2 = 0;
      M<UInt32>((UInt8 *)*param_2 + 4) = 0;
      M<UInt32>((UInt8 *)*param_2 + 8) = 0;
      M<UInt32>((UInt8 *)*param_2 + 0xc) = 0;
      M<UInt32>((UInt8 *)*param_2 + 0x10) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x1c) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x1e) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x20) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x22) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x24) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x26) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x28) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x2a) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x2c) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x2e) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x30) = 0;
      M<UInt16>((UInt8 *)*param_2 + 0x32) = 0;
      ((UInt8 *)*param_2)[0x14] = 0x1;
      ((UInt8 *)*param_2)[0x15] = 0x0;
      ((UInt8 *)*param_2)[0x16] = 0x0;
      ((UInt8 *)*param_2)[0x34] = 0x0;
      ((UInt8 *)*param_2)[0x35] = 0x0;
      ((UInt8 *)*param_2)[0x17] = 0x0;
      M<UInt16>((UInt8 *)*param_2 + 0x36) = 0;
      return 1;
    }
    param_1 = param_1 - puVar4[6];
    puVar5 = (UInt32 *)*puVar4;
  }
  puVar5 = (UInt32 *)GH_IOMalloc(0x1c);
  if (puVar5 == (UInt32 *)0x0) {
    return 0;
  }
  piVar1 = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(self + 8),0x10022,0x2000,GH_page_size);
  puVar5[1] = (UInt32)(piVar1);
  if (piVar1 == (SInt32 *)0x0) goto LAB_00016e80;
  piVar1 = (SInt32 *)VCALL(*piVar1, 0x14c)(piVar1,M<UInt32>(self + 8),0,1,0,0);
  puVar5[2] = (UInt32)(piVar1);
  if (piVar1 != (SInt32 *)0x0) {
    uVar2 = VCALL(*piVar1, 0xd0)(piVar1);
    puVar5[5] = uVar2;
    iVar3 = VCALL(*(SInt32 *)puVar5[1], 0x14c)((SInt32 *)puVar5[1],GH_kernel_task,0,1,0,0);
    puVar5[3] = iVar3;
    if (iVar3 != 0) {
      iVar3 = M<SInt32>(self + 0xc);
      if (iVar3 != 0) {
        M<SInt32>(iVar3 + 0x808) = M<SInt32>(iVar3 + 0x808) + 0x1c;
      }
      uVar2 = VCALL(*(SInt32 *)puVar5[3], 0xd0)(puVar5[3]);
      *puVar5 = 0;
      puVar5[4] = uVar2;
      puVar5[6] = 0x80;
      if (puVar4 == (UInt32 *)0x0) {
        M<UInt32 *>(self + 0x20) = puVar5;
      }
      else {
        *puVar4 = (UInt32)(puVar5);
      }
      goto LAB_00016f00;
    }
    VCALL(*(SInt32 *)puVar5[2], 0x18)(puVar5[2]);
  }
  VCALL(*(SInt32 *)puVar5[1], 0x18)(puVar5[1]);
LAB_00016e80:
  GH_IOFree(puVar5,0x1c);
  return 0;
}
