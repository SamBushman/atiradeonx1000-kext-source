/*
 * IOATIR500Surface_copy_buffer_from_backing_store_Port.cpp
 *
 * IOATIR500Surface::copy_buffer_from_backing_store (real addr 0x12a00, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12a00 */
UInt32 IOATIR500Surface::copy_buffer_from_backing_store(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  UInt16 uVar3;
  SInt32 iVar2;
  SInt32 *piVar4;
  UInt8 *pIVar5;
  UInt32 uVar6;
  SInt32 iVar7;
  UInt32 uVar8;
  UInt32 uVar9;
  UInt32 local_38;
  UInt32 local_34 [6];
  
  if (M<SInt32>(M<SInt32>(param_1 + 0x24) + 0x54) == M<SInt32>(self + 0x7c)) {
    M<SInt32>(M<SInt32>(self + 0xd50) + 0x724) =
         M<SInt32>(M<SInt32>(self + 0xd50) + 0x724) + M<SInt32>(param_1 + 0x10);
    uVar6 = (UInt32)M<UInt16>(param_1 + 0x20);
    iVar7 = M<SInt32>(self + 0x7c);
    iVar1 = M<SInt32>(M<SInt32>(self + 0xd50) + 0x50);
    if (uVar6 != 0) {
      uVar3 = M<UInt16>(param_1 + 0x22);
      uVar8 = 0;
      do {
        if (uVar3 != 0) {
          uVar6 = 0;
          do {
            VCALL(M<SInt32>(self), 0x5f0)(self,param_1,uVar8,uVar6,&local_38,local_34,0);
            uVar9 = uVar6 + 1;
            VCALL(M<SInt32>(self), 0x5ec)
                      (self,0,0,local_38,local_34[0],uVar8,uVar6,param_1,iVar1 + -1,0,0,0,1);
            M<UInt32>(M<SInt32>(M<SInt32>(param_1 + 0x24) + 0x14) + 8) =
                 M<UInt32>(self + 0x7c);
            uVar3 = M<UInt16>(param_1 + 0x22);
            uVar6 = uVar9;
          } while (uVar9 < uVar3);
          uVar6 = (UInt32)M<UInt16>(param_1 + 0x20);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar6);
    }
    pIVar5 = self + 0xcc;
    iVar1 = 0x17;
    do {
      iVar2 = M<SInt32>(pIVar5);
      pIVar5 = pIVar5 + 0x78;
      if ((iVar2 != 0) && (iVar7 == M<SInt32>(iVar2 + 0x54))) {
        M<UInt32>(iVar2 + 0x54) = M<UInt32>(self + 0x7c);
      }
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if ((((self[0xc09] == 0x0) && ((M<UInt32>(self + 0xbd0) & 0xffff0000) == 0)) &&
      (self[0xc08] == 0x0)) &&
     (((self[0xbf7] != 0x0 && (M<SInt32>(param_1 + 0x24) != 0)) &&
      (piVar4 = M<SInt32 *>(M<SInt32>(param_1 + 0x24) + 8), piVar4 != (SInt32 *)0x0)))) {
    VCALL(*piVar4, 0xdc)(piVar4,3,0);
  }
  return 1;
}
