/*
 * IOATIR500DVDContext_write_buffer_Port.cpp
 *
 * IOATIR500DVDContext::write_buffer (real addr 0xffe0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");


/* real addr 0xffe0 */
IOReturn IOATIR500DVDContext::write_buffer(sIODVDContextWriteBufferData *real_param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  int iVar2;
  int *piVar3;
  unsigned int uVar4;
  int iVar5;
  unsigned int uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  UInt32 uVar15;
  UInt32 local_48;
  int local_44;
  int *local_40;
  UInt16 local_3c;
  UInt16 local_3a;
  
  local_3a = 0;
  local_3c = 3;
  local_48 = 0;
  local_44 = 0;
  local_40 = (int *)0x0;
  iVar13 = M<int>(param_2);
  iVar12 = M<int>(param_2 + 4);
  iVar11 = M<int>(param_2 + 8);
  iVar10 = M<int>(param_2 + 0xc);
  iVar9 = M<int>(param_2 + 0x14);
  iVar7 = (0x10 - (unsigned int)(M<int>(param_2 + 0x10) == 0)) * 4;
  GH_IOLockLock(M<UInt32>(M<int>(param_1 + 0x8c) + 0x840));
  pIVar1 = M<UInt8 *>(param_1 + 0xf8);
  uVar4 = 0x40000000;
  iVar14 = M<int>(pIVar1 + iVar7 + 0xb70);
  uVar6 = (iVar14 - (int)(pIVar1 + 0xa8) >> 3) * -0x11111111;
  if (uVar6 < 0x17) {
    uVar4 = 1 << (uVar6 & 0x3f) & M<unsigned int>(param_1 + 0x88);
  }
  if ((pIVar1 == (UInt8 *)0x0) || (uVar4 == 0)) goto LAB_00010120;
  if ((uVar4 & M<unsigned int>(pIVar1 + 0xbf8)) == 0) {
LAB_00010100:
    if (((M<unsigned int>(pIVar1 + 0xbf8) & 0x20000000) != 0) || (M<int>(iVar14 + 0x10) == 0)) {
LAB_00010120:
      GH_IOLockUnlock(M<UInt32>(M<int>(param_1 + 0x8c) + 0x840));
      return 0xe00002cc;
    }
  }
  else {
    if (M<int>(iVar14 + 0x24) == 0) goto LAB_00010160;
    if ((M<char>(M<int>(param_1 + 0x8c) + 0x80) == '\0') ||
       (M<char>(M<int>(iVar14 + 0x24) + 0x58) != '\0')) goto LAB_00010100;
    iVar14 = ((IOATIR500Surface *)(pIVar1))->alloc_surfaces_retry(uVar4, (eLockType)(0));
    if (iVar14 != 0) goto LAB_00010120;
    iVar14 = M<int>(iVar7 + M<int>(param_1 + 0xf8) + 0xb70);
  }
  iVar7 = iVar13 + iVar11;
  if ((((0 < iVar7) && (iVar5 = iVar12 + iVar10, 0 < iVar5)) &&
      (uVar4 = (unsigned int)M<UInt16>(iVar14 + 0x1c), iVar13 < (int)uVar4)) &&
     (uVar6 = (unsigned int)M<UInt16>(iVar14 + 0x1e), iVar12 < (int)uVar6)) {
    iVar8 = M<int>(param_2 + 0x18);
    iVar2 = 0;
    if (iVar13 < 0) {
      iVar2 = (unsigned int)M<UInt16>(iVar14 + 0x16) * iVar13;
      iVar13 = 0;
      iVar2 = -iVar2;
      iVar11 = iVar7;
    }
    if (iVar12 < 0) {
      iVar10 = iVar8 * iVar12;
      iVar12 = 0;
      iVar2 = iVar2 - iVar10;
      iVar10 = iVar5;
    }
    if ((int)uVar4 < iVar7) {
      iVar11 = uVar4 - iVar13;
    }
    if ((int)uVar6 < iVar5) {
      iVar10 = uVar6 - iVar12;
    }
    uVar4 = iVar9 + iVar2;
    uVar6 = uVar4 & GH_page_size - 1U;
    local_40 = (int *)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(uVar4 & -GH_page_size,
                                   -GH_page_size &
                                   (GH_page_size +
                                   iVar8 * (iVar10 + -1) + (unsigned int)M<UInt16>(iVar14 + 0x16) * iVar11
                                   + uVar6) - 1,0,M<UInt32>(param_1 + 0x78));
    if (local_40 == (int *)0x0) {
      uVar15 = 0xe00002be;
    }
    else {
      piVar3 = M<int *>(param_1 + 0xf8);
      iVar9 = piVar3[0x1f];
      VCALL(*piVar3, 0x5ec)
                (piVar3,iVar13,iVar12,iVar11,iVar10,0,0,iVar14,
                 M<int>(M<int>(param_1 + 0x8c) + 0x50) + -1,&local_48,uVar6,iVar8,0);
      iVar7 = 0xa0;
      iVar10 = 0x17;
      do {
        iVar11 = M<int>(M<int>(param_1 + 0xf8) + iVar7 + 0x2c);
        if ((iVar11 != 0) && (iVar9 == M<int>(iVar11 + 0x54))) {
          M<UInt32>(iVar11 + 0x54) = M<UInt32>(M<int>(param_1 + 0xf8) + 0x7c);
        }
        iVar7 = iVar7 + 0x78;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      if (local_44 != 0) {
        GH_IOLockUnlock(M<UInt32>(M<int>(param_1 + 0x8c) + 0x840));
        piVar3 = M<int *>(param_1 + 0x8c);
        iVar10 = piVar3[0x1ec];
        iVar7 = VCALL(*piVar3, 0x55c)
                          (piVar3,M<UInt32>(M<int>(param_1 + 0xf8) + 0x7c));
        piVar3[0x1ec] = iVar10 + iVar7;
        GH_IOLockLock(M<UInt32>(M<int>(param_1 + 0x8c) + 0x840));
        VCALL(*M<int *>(param_1 + 0x8c), 0x5ac)(M<int *>(param_1 + 0x8c),&local_48);
      }
      uVar15 = 0;
      VCALL(*local_40, 0x18)(local_40);
    }
    local_40 = (int *)0x0;
    GH_IOLockUnlock(M<UInt32>(M<int>(param_1 + 0x8c) + 0x840));
    return uVar15;
  }
LAB_00010160:
  GH_IOLockUnlock(M<UInt32>(M<int>(param_1 + 0x8c) + 0x840));
  return 0;
}
