/*
 * IOATIR500Shared_alloc_buf_handle_Port.cpp
 *
 * IOATIR500Shared::alloc_buf_handle (real addr 0x16bb0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x16bb0 */
bool IOATIR500Shared::alloc_buf_handle(void*param_1, UInt32*param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 *puVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  
  uVar7 = M<UInt32>(self + 0x1c) >> 5;
  do {
    if (uVar7 < M<UInt32>(self + 0x14) >> 5) {
      iVar4 = uVar7 * 4;
      uVar2 = M<UInt32>(M<SInt32>(self + 0x18) + iVar4);
      if (uVar2 != 0xffffffff) {
LAB_00016c4c:
        uVar3 = 0;
        iVar1 = 0x20;
        break;
      }
      iVar1 = (M<UInt32>(self + 0x14) >> 5) - uVar7;
      puVar5 = (UInt32 *)(M<SInt32>(self + 0x18) + iVar4);
      while( true ) {
        iVar4 = iVar4 + 4;
        uVar7 = uVar7 + 1;
        iVar1 = iVar1 + -1;
        if (iVar1 == 0) break;
        puVar5 = puVar5 + 1;
        uVar2 = *puVar5;
        if (uVar2 != 0xffffffff) goto LAB_00016c4c;
      }
    }
    iVar4 = this->alloc_handles();
    if (iVar4 == 0) {
      return 0;
    }
  } while( true );
  while( true ) {
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) break;
    uVar6 = uVar3;
    if ((uVar2 >> (uVar3 & 0x3f) & 1) == 0) goto LAB_00016c7c;
  }
  uVar6 = 0x20;
LAB_00016c7c:
  uVar8 = uVar7 * 0x20 + uVar3;
  M<UInt32>(self + 0x1c) = uVar8 + 1;
  M<void *>(uVar8 * 4 + M<SInt32>(self + 0x10)) = param_1;
  M<UInt32>(iVar4 + M<SInt32>(self + 0x18)) =
       1 << (uVar6 & 0x3f) | M<UInt32>(iVar4 + M<SInt32>(self + 0x18));
  *param_2 = uVar8;
  return 1;
}
