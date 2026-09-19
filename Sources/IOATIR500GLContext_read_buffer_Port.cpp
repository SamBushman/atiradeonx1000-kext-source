/*
 * IOATIR500GLContext_read_buffer_Port.cpp
 *
 * IOATIR500GLContext::read_buffer (real addr 0x8d10, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");


/* real addr 0x8d10 */
IOReturn IOATIR500GLContext::read_buffer(sIOGLContextReadBufferData *real_param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  SInt32 iVar2;
  UInt8 *pIVar3;
  SInt32 iVar4;
  SInt32 *piVar5;
  UInt32 uVar6;
  SInt32 iVar7;
  UInt32 uVar8;
  SInt32 iVar9;
  SInt32 iVar10;
  SInt32 iVar11;
  SInt32 iVar12;
  SInt32 iVar13;
  SInt32 iVar14;
  SInt32 iVar15;
  SInt32 iVar16;
  UInt32 uVar17;
  SInt32 iVar18;
  UInt32 local_48;
  SInt32 local_44;
  SInt32 *local_40;
  UInt16 local_3c;
  UInt16 local_3a;
  
  local_3a = 0;
  local_3c = 3;
  local_48 = 0;
  local_44 = 0;
  local_40 = (SInt32 *)0x0;
  iVar18 = M<SInt32>(param_2);
  iVar15 = M<SInt32>(param_2 + 4);
  iVar13 = M<SInt32>(param_2 + 8);
  iVar12 = M<SInt32>(param_2 + 0xc);
  iVar11 = M<SInt32>(param_2 + 0x14);
  switch(M<UInt32>(param_2 + 0x10)) {
  case 0:
    iVar14 = 1;
    break;
  case 1:
    iVar14 = 0;
    break;
  case 2:
    iVar14 = 4;
    break;
  case 3:
    iVar14 = 5;
    break;
  case 4:
    iVar14 = 6;
    break;
  default:
    return 0xe00002c2;
  case 7:
    iVar14 = 2;
    break;
  case 8:
    iVar14 = 3;
    break;
  case 10:
    iVar14 = 7;
    break;
  case 0xb:
    iVar14 = 8;
  }
  GH_IOLockLock(M<UInt32>(M<SInt32>(param_1 + 200) + 0x840));
  pIVar3 = M<UInt8 *>(param_1 + 0x290);
  if (pIVar3 == (UInt8 *)0x0) goto LAB_00008f74;
  if ((0xff < M<UInt32>(pIVar3 + 0xa4)) &&
     (iVar16 = M<SInt32>(param_1 + 200), M<char>(iVar16 + 0x80) == '\0')) {
    do {
      GH_IOLockSleep(M<UInt32>(iVar16 + 0x840),iVar16,0);
    } while (M<char>(iVar16 + 0x80) == '\0');
    pIVar3 = M<UInt8 *>(param_1 + 0x290);
    if (pIVar3 == (UInt8 *)0x0) goto LAB_00008f74;
  }
  if ((((iVar14 != 0) || (M<SInt32>(pIVar3 + 0xc14) == 0xffff)) ||
      (pIVar1 = *(UInt8 **)
                 (M<SInt32>(pIVar3 + 0xc14) * 0x20 + M<SInt32>(param_1 + 200) + 0xe8),
      pIVar1 == (UInt8 *)0x0)) || (pIVar3 == pIVar1)) {
    pIVar1 = pIVar3 + iVar14 * 4;
  }
  iVar16 = M<SInt32>(pIVar1 + 0xb70);
  uVar6 = 0x40000000;
  uVar8 = (iVar16 - (SInt32)(pIVar3 + 0xa8) >> 3) * -0x11111111;
  if ((uVar8 < 0x17) && (uVar6 = 1 << (uVar8 & 0x3f) & M<UInt32>(param_1 + 0x8c), uVar6 == 0))
  goto LAB_00008f74;
  if ((M<UInt32>(pIVar3 + 0xbf8) & uVar6) == 0) {
LAB_00008f60:
    if (((M<UInt32>(pIVar3 + 0xbf8) & 0x20000000) != 0) || (M<SInt32>(iVar16 + 0x10) == 0)) {
LAB_00008f74:
      GH_IOLockUnlock(M<UInt32>(M<SInt32>(param_1 + 200) + 0x840));
      return 0xe00002cc;
    }
  }
  else {
    if (M<SInt32>(iVar16 + 0x24) == 0) goto LAB_00008fb0;
    if ((M<char>(M<SInt32>(param_1 + 200) + 0x80) == '\0') ||
       (M<char>(M<SInt32>(iVar16 + 0x24) + 0x58) != '\0')) goto LAB_00008f60;
    iVar16 = ((IOATIR500Surface *)(pIVar3))->alloc_surfaces_retry(uVar6, (eLockType)(0));
    if (iVar16 != 0) goto LAB_00008f74;
    pIVar3 = M<UInt8 *>(param_1 + 0x290);
    iVar16 = M<SInt32>(pIVar3 + iVar14 * 4 + 0xb70);
  }
  iVar14 = iVar18 + iVar13;
  if ((((0 < iVar14) && (iVar9 = iVar15 + iVar12, 0 < iVar9)) &&
      (iVar2 = (SInt32)M<SInt16>(pIVar3 + 0xbd4), iVar18 < iVar2)) &&
     (iVar4 = (SInt32)M<SInt16>(pIVar3 + 0xbd6), iVar15 < iVar4)) {
    iVar10 = M<SInt32>(param_2 + 0x18);
    iVar7 = 0;
    if (iVar18 < 0) {
      iVar7 = (UInt32)M<UInt16>(iVar16 + 0x16) * iVar18;
      iVar18 = 0;
      iVar7 = -iVar7;
      iVar13 = iVar14;
    }
    if (iVar15 < 0) {
      iVar12 = iVar10 * iVar15;
      iVar15 = 0;
      iVar7 = iVar7 - iVar12;
      iVar12 = iVar9;
    }
    if (iVar2 < iVar14) {
      iVar13 = iVar2 - iVar18;
    }
    if (iVar4 < iVar9) {
      iVar12 = iVar4 - iVar15;
    }
    uVar6 = iVar11 + iVar7;
    uVar8 = uVar6 & GH_page_size - 1U;
    local_40 = (SInt32 *)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(uVar6 & -GH_page_size,
                                   -GH_page_size &
                                   (GH_page_size +
                                   iVar10 * (iVar12 + -1) +
                                   (UInt32)M<UInt16>(iVar16 + 0x16) * iVar13 + uVar8) - 1,0,
                                   M<UInt32>(param_1 + 0x78));
    if (local_40 == (SInt32 *)0x0) {
      uVar17 = 0xe00002be;
    }
    else {
      piVar5 = M<SInt32 *>(param_1 + 0x290);
      iVar11 = piVar5[0x1f];
      VCALL(*piVar5, 0x5e8)
                (piVar5,iVar18,iVar15,iVar13,iVar12,M<UInt32>(param_1 + 0x298),
                 M<UInt32>(param_1 + 0x29c),iVar16,M<UInt32>(param_1 + 0x7c),&local_48,
                 uVar8,iVar10,2);
      iVar12 = 0xa0;
      iVar13 = 0x17;
      do {
        iVar15 = M<SInt32>(M<SInt32>(param_1 + 0x290) + iVar12 + 0x2c);
        if ((iVar15 != 0) && (iVar11 == M<SInt32>(iVar15 + 0x54))) {
          M<UInt32>(iVar15 + 0x54) = M<UInt32>(M<SInt32>(param_1 + 0x290) + 0x7c);
        }
        iVar12 = iVar12 + 0x78;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      if (local_44 != 0) {
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(param_1 + 200) + 0x840));
        piVar5 = M<SInt32 *>(param_1 + 200);
        iVar13 = piVar5[0x1ed];
        iVar12 = VCALL(*piVar5, 0x55c)
                           (piVar5,M<UInt32>(M<SInt32>(param_1 + 0x290) + 0x7c));
        piVar5[0x1ed] = iVar13 + iVar12;
        GH_IOLockLock(M<UInt32>(M<SInt32>(param_1 + 200) + 0x840));
        VCALL(*M<SInt32 *>(param_1 + 200), 0x5ac)(M<SInt32 *>(param_1 + 200),&local_48);
      }
      uVar17 = 0;
      VCALL(*local_40, 0x18)(local_40);
    }
    local_40 = (SInt32 *)0x0;
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(param_1 + 200) + 0x840));
    return uVar17;
  }
LAB_00008fb0:
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(param_1 + 200) + 0x840));
  return 0;
}
