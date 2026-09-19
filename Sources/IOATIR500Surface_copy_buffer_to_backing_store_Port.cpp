/*
 * IOATIR500Surface_copy_buffer_to_backing_store_Port.cpp
 *
 * IOATIR500Surface::copy_buffer_to_backing_store (real addr 0x11110, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x11110 */
bool IOATIR500Surface::copy_buffer_to_backing_store(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt16 uVar1;
  SInt32 *piVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt8 *pIVar5;
  UInt32 uVar6;
  SInt32 iVar7;
  UInt32 uVar8;
  SInt32 iVar9;
  SInt32 local_38;
  UInt32 local_34;
  UInt32 local_30 [5];
  
  iVar3 = M<SInt32>(param_1 + 0x24);
  local_38 = 2;
  if (iVar3 == 0) {
    iVar3 = VCALL(M<SInt32>(self), 0x5e4)(self);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = M<SInt32>(param_1 + 0x24);
  }
  if (((self[0xc09] == 0x0) && (self[0xbf7] != 0x0)) &&
     (piVar2 = M<SInt32 *>(iVar3 + 8), piVar2 != (SInt32 *)0x0)) {
    iVar3 = VCALL(*piVar2, 0xdc)(piVar2,2,&local_38);
    if ((iVar3 == 0) && (local_38 == 4)) {
      iVar3 = M<SInt32>(param_1 + 0x24);
      if (M<SInt32>(iVar3 + 4) != 0) {
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
        piVar2 = M<SInt32 *>(self + 0xd50);
        iVar7 = piVar2[0x1ed];
        iVar3 = VCALL(*piVar2, 0x55c)(piVar2,M<UInt32>(self + 0x7c));
        piVar2[0x1ed] = iVar7 + iVar3;
        GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
        VCALL(*M<SInt32 *>(self + 0xd50), 0x5ac)
                  (M<SInt32 *>(self + 0xd50),M<UInt32>(param_1 + 0x24));
        M<UInt32>(M<SInt32>(param_1 + 0x24) + 4) = 0;
        iVar3 = M<SInt32>(param_1 + 0x24);
      }
      if (M<SInt32>(iVar3 + 0x54) == M<SInt32>(self + 0x7c)) {
        M<UInt8>(iVar3 + 0x58) = 0;
        iVar3 = M<SInt32>(param_1 + 0x24);
      }
      else {
        M<SInt32>(iVar3 + 0x54) = M<SInt32>(self + 0x7c) + -1;
        iVar3 = M<SInt32>(param_1 + 0x24);
      }
    }
    else {
      iVar3 = M<SInt32>(param_1 + 0x24);
    }
  }
  if ((M<SInt32>(iVar3 + 0x54) != M<SInt32>(self + 0x7c)) || (M<char>(iVar3 + 0x58) == '\0')) {
    M<SInt32>(M<SInt32>(self + 0xd50) + 0x728) =
         M<SInt32>(M<SInt32>(self + 0xd50) + 0x728) + M<SInt32>(param_1 + 0x10);
    uVar4 = (UInt32)M<UInt16>(param_1 + 0x20);
    iVar7 = M<SInt32>(self + 0x7c);
    iVar3 = iVar7;
    if (uVar4 != 0) {
      uVar1 = M<UInt16>(param_1 + 0x22);
      uVar6 = 0;
      do {
        if (uVar1 != 0) {
          uVar4 = 0;
          do {
            VCALL(M<SInt32>(self), 0x5f0)(self,param_1,uVar6,uVar4,&local_34,local_30,0);
            uVar8 = uVar4 + 1;
            VCALL(M<SInt32>(self), 0x5e8)
                      (self,0,0,local_34,local_30[0],uVar6,uVar4,param_1,iVar7,0,0,0,1);
            M<UInt32>(M<SInt32>(M<SInt32>(param_1 + 0x24) + 0x14) + 8) =
                 M<UInt32>(self + 0x7c);
            uVar1 = M<UInt16>(param_1 + 0x22);
            uVar4 = uVar8;
          } while (uVar8 < uVar1);
          uVar4 = (UInt32)M<UInt16>(param_1 + 0x20);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
      iVar3 = M<SInt32>(self + 0x7c);
    }
    pIVar5 = self + 0xcc;
    iVar9 = 0x17;
    M<SInt32>(M<SInt32>(param_1 + 0x24) + 0x54) = iVar3;
    do {
      iVar3 = M<SInt32>(pIVar5);
      pIVar5 = pIVar5 + 0x78;
      if ((iVar3 != 0) && (iVar7 == M<SInt32>(iVar3 + 0x54))) {
        M<UInt32>(iVar3 + 0x54) = M<UInt32>(self + 0x7c);
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  return 1;
}
