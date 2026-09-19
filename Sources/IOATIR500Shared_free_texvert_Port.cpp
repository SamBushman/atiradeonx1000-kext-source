/*
 * IOATIR500Shared_free_texvert_Port.cpp
 *
 * IOATIR500Shared::free_texvert (real addr 0x18710, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x18710 */
void IOATIR500Shared::free_texvert(IOATIR500Accelerator *real_param_1, IOTextureBuffer *real_param_2) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  SInt32 iVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt8 IVar4;
  SInt32 iVar5;
  
  iVar5 = M<SInt32>(param_2 + 0x24);
  iVar1 = M<SInt32>(param_2 + 4);
  M<UInt32>(iVar5 + 0x28) = M<UInt32>(param_2 + 0x28);
  iVar3 = M<SInt32>(param_2 + 0x28);
  M<UInt8 *>(param_2 + 0x28) = param_2;
  M<SInt32>(iVar3 + 0x24) = iVar5;
  M<UInt8 *>(param_2 + 0x24) = param_2;
  if (iVar1 != 0) {
    VCALL(M<SInt32>(param_1), 0x5ac)(param_1);
  }
  if (M<UInt8 *>(param_2 + 0x1c) != (UInt8 *)0x0) {
    ((IOATIR500Shared *)(M<UInt8 *>(param_2 + 0x1c)))->free_buf_handle(param_2,*M<UInt32 *>(param_2 + 0x14));   /* record, handle - the owner is `this` of the call */
  }
  IVar4 = param_2[0x20];
  if (((UInt8)IVar4 - 3 < 5) && (M<SInt32 *>(param_2 + 8) != (SInt32 *)0x0)) {
    VCALL(*M<SInt32 *>(param_2 + 8), 0x18)(M<SInt32 *>(param_2 + 8));
    IVar4 = param_2[0x20];
    M<UInt32>(param_2 + 8) = 0;
  }
  uVar2 = 0xc0;
  if (IVar4 != 0x5) {
    uVar2 = 0x80;
  }
  VCALL(M<SInt32>(param_1), 0x574)(param_1,param_2,uVar2);
  return;
}
