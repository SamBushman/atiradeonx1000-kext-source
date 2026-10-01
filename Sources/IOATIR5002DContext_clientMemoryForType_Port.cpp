/*
 * IOATIR5002DContext_clientMemoryForType_Port.cpp
 *
 * IOATIR5002DContext::clientMemoryForType (real addr 0xd6f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0xd6f0 */
IOReturn IOATIR5002DContext::clientMemoryForType(UInt32 param_1, UInt32*param_2, IOMemoryDescriptor**param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt16 uVar1;
  unsigned int uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  unsigned int uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  UInt32 uVar13;
  UInt32 uVar14;
  unsigned int uVar15;
  UInt8 *this_00;
  int iVar16;
  UInt8 *this_01;
  /* one 16-byte stack object filled by the +0x5ac/+0x5b4/+0x560 callees (Ghidra named its words auStack_38 and local_30; #85) */
  int auStack_38[4];
  
  if (param_1 == 1) {
    GH_IOLockLock(M<UInt32>(M<int>(self + 0x94) + 0x840));
    VCALL(*M<int *>(self + 0xbc), 0x14)(M<int *>(self + 0xbc));
    *param_2 = 0;
    *param_3 = M<IOMemoryDescriptor *>(self + 0xbc);
    this->init_context_buffer_header((VendorContextBufferHeader *)(M<VendorContextBufferHeader *>(self + 200)),0x1000);
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
    return 0;
  }
  uVar15 = 0;
  if (param_1 != 0) {
    if (param_1 != 2) {
      return 0xe00002c2;
    }
    if (M<int *>(M<int>(self + 0x94) + 0xac) == (int *)0x0) {
      return 0xe00002be;
    }
    VCALL(*M<int *>(M<int>(self + 0x94) + 0xac), 0x14)(M<int *>(M<int>(self + 0x94) + 0xac));
    *param_2 = 0;
    *param_3 = M<IOMemoryDescriptor *>(M<int>(self + 0x94) + 0xac);
    return 0;
  }
  do {
    while( true ) {
      GH_IOLockLock(M<UInt32>(M<int>(self + 0x94) + 0x840));
      this_00 = M<UInt8 *>(self + 0x100);
      if ((this_00 == (UInt8 *)0x0) || (M<unsigned int>(this_00 + 0xa4) < 0x100)) {
        iVar16 = M<int>(self + 0x94);
      }
      else {
        iVar16 = M<int>(self + 0x94);
        if (M<char>(iVar16 + 0x80) == '\0') {
          do {
            GH_IOLockSleep(M<UInt32>(iVar16 + 0x840),iVar16,0);
          } while (M<char>(iVar16 + 0x80) == '\0');
          iVar16 = M<int>(self + 0x94);
          this_00 = M<UInt8 *>(self + 0x100);
        }
      }
      if (M<char>(iVar16 + 0x80) == '\0') {
        uVar15 = 0x3e9;
        uVar14 = 0;
        goto LAB_0000d930;
      }
      if (this_00 == (UInt8 *)0x0) {
        this_00 = (UInt8 *)0x0;
        uVar14 = 0;
        goto LAB_0000d93c;
      }
      if (this_00[0xbf6] == 0x0) break;
      VCALL(M<int>(this_00), 0x14)(this_00);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
      ((IOATIR500Surface *)(this_00))->sleep_blocked();
      VCALL(M<int>(this_00), 0x18)(this_00);
    }
    uVar14 = M<UInt32>(this_00 + 0xbfc);
    if ((M<unsigned int>(this_00 + 0xbec) & 0xffffff) != 0) {
      uVar14 = uVar14 | 2;
    }
    if ((this_00[0xbd0] == 0x0) || (uVar15 == 999)) {
      uVar8 = M<unsigned int>(this_00 + 0xbf8);
      if (((M<unsigned int>(self + 0x8c) | M<unsigned int>(this_00 + 0xc1c)) & uVar8) == 0) goto LAB_0000d950;
      if ((uVar8 & 0x20000000) != 0) {
        uVar15 = 0x3e9;
        goto LAB_0000d950;
      }
      uVar2 = (M<unsigned int>(self + 0x8c) | M<unsigned int>(this_00 + 0xc1c)) & 0x7fffff;
      if ((uVar8 & uVar2) != 0) {
        iVar16 = ((IOATIR500Surface *)((UInt32)this_00))->alloc_surfaces(uVar2, false);
        if (iVar16 != 0) {
          if (iVar16 != 2) goto LAB_0000d8b8;
          this_00 = M<UInt8 *>(self + 0x100);
          uVar15 = 0x3e9;
          goto LAB_0000d930;
        }
        this_00 = M<UInt8 *>(self + 0x100);
        if ((M<unsigned int>(this_00 + 0xbf8) & M<unsigned int>(this_00 + 0xc1c) & 0x10000000) == 0)
        goto LAB_0000d950;
      }
      VCALL(M<int>(this_00), 0x5c0)(this_00);
      M<unsigned int>(M<int>(self + 0x100) + 0xbf8) =
           M<unsigned int>(M<int>(self + 0x100) + 0xbf8) & 0xefffffff;
      this_00 = M<UInt8 *>(self + 0x100);
      goto LAB_0000d930;
    }
LAB_0000d8b8:
    if (uVar15 == 1000) break;
    uVar15 = uVar15 + 1;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
    GH_thread_block(0);
    GH_IOSleep(1);
  } while( true );
  this_00 = M<UInt8 *>(self + 0x100);
LAB_0000d930:
  if (this_00 == (UInt8 *)0x0) {
LAB_0000d93c:
    if (M<int>(self + 0x110) == 0xffff) goto LAB_0000de0c;
  }
LAB_0000d950:
  if (999 < uVar15) {
    if ((1000 < uVar15) ||
       (iVar16 = ((IOATIR500Surface *)((UInt32)this_00))->alloc_surfaces((M<UInt32>(self + 0x8c) | M<UInt32>(this_00 + 0xc1c)) & 0x7fffff, true), iVar16 != 0))
    goto LAB_0000de0c;
    piVar3 = M<int *>(self + 0x100);
    if ((piVar3[0x2fe] & piVar3[0x307] & 0x10000000U) != 0) {
      VCALL(*piVar3, 0x5c0)(piVar3);
      M<unsigned int>(M<int>(self + 0x100) + 0xbf8) =
           M<unsigned int>(M<int>(self + 0x100) + 0xbf8) & 0xefffffff;
    }
  }
  if (self != M<UInt8 *>(M<int>(self + 0x94) + 0x78)) {
    VCALL(M<int>(self), 0x5a8)(self);
    M<int>(M<int>(self + 0x94) + 0x744) = M<int>(M<int>(self + 0x94) + 0x744) + 1;
    M<UInt8 *>(M<int>(self + 0x94) + 0x78) = self;
  }
  piVar3 = M<int *>(self + 0x100);
  if (piVar3 != (int *)0x0) {
    VCALL(*piVar3, 0x5b8)(piVar3,M<UInt32>(self + 0x8c));
  }
  if (M<int>(self + 0x9c) == 0) {
    this->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)));
  }
  iVar16 = VCALL(M<int>(self), 0x5ac)(self,auStack_38);
  if (M<int>(self + 0x114) != 0) {
    M<UInt32>(M<int>(M<int>(self + 0x114) + 0x14) + 8) =
         M<UInt32>(M<int>(self + 0x94) + 0x50);
  }
  if (auStack_38[2] == 0) {
    iVar4 = M<int>(M<int>(self + 0x94) + 0x50) + -1;
  }
  else {
    M<int>(M<int>(self + 0x94) + 0x700) = auStack_38[2] * 4 + M<int>(M<int>(self + 0x94) + 0x700)
    ;
    iVar4 = VCALL(*M<int *>(self + 0x94), 0x560)(M<int *>(self + 0x94),auStack_38);
  }
  piVar3 = M<int *>(self + 0x100);
  M<int>(self + 0x7c) = iVar4;
  M<int>(self + 0xa8) = iVar4;
  if (piVar3 == (int *)0x0) {
LAB_0000dc70:
    M<UInt32>(M<int>(self + 0x110) * 0x20 + M<int>(self + 0x94) + 0xec) =
         M<UInt32>(self + 0x7c);
  }
  else {
    VCALL(*piVar3, 0x5bc)(piVar3,M<UInt32>(self + 0x8c));
    piVar3 = M<int *>(self + 0x100);
    if (piVar3 == (int *)0x0) goto LAB_0000dc70;
    iVar4 = VCALL(*piVar3, 0x5b4)
                      (piVar3,M<UInt32>(self + 0x7c),M<UInt32>(self + 0x8c));
    piVar3[0x1f] = iVar4;
    if (self[0x92] != 0x0) {
      M<UInt32>(M<int>(M<int>(M<int>(self + 0x100) + 0xb70) + 0x24) + 0x54) =
           M<UInt32>(M<int>(self + 0x100) + 0x7c);
    }
    iVar4 = M<int>(self + 0x100);
    if (iVar4 != M<int>(M<int>(self + 0x94) + 0x5c)) {
      M<UInt32>(M<int>(iVar4 + 0x9c) + 0xa0) = M<UInt32>(iVar4 + 0xa0);
      M<UInt32>(M<int>(M<int>(self + 0x100) + 0xa0) + 0x9c) =
           M<UInt32>(M<int>(self + 0x100) + 0x9c);
      iVar4 = M<int>(M<int>(self + 0x94) + 0x5c);
      M<int>(M<int>(self + 0x100) + 0x9c) = iVar4;
      iVar11 = M<int>(iVar4 + 0xa0);
      M<int>(M<int>(self + 0x100) + 0xa0) = iVar11;
      M<UInt32>(iVar4 + 0xa0) = M<UInt32>(self + 0x100);
      M<UInt32>(iVar11 + 0x9c) = M<UInt32>(self + 0x100);
      M<UInt32>(M<int>(self + 0x94) + 0x5c) = M<UInt32>(self + 0x100);
    }
    if ((iVar16 != 0) && ((uVar14 & 2) == 0)) {
      iVar16 = M<int>(self + 0x100);
      uVar13 = M<UInt32>(iVar16 + 0x84);
      M<UInt32>(iVar16 + 0x84) = M<UInt32>(iVar16 + 0x80);
      piVar3 = M<int *>(self + 0x94);
      if (piVar3[0x33] != 0) {
        uVar15 = 0;
        iVar16 = 0;
        do {
          piVar5 = M<int *>(self + 0x100);
          if (M<char>((int)piVar5 + iVar16 + 0xcac) != '\0') {
            VCALL(*piVar5, 0x5d4)(piVar5,uVar15,0);
            M<int>(M<int>(self + 0x94) + 0x74c) = M<int>(M<int>(self + 0x94) + 0x74c) + 1;
            piVar3 = M<int *>(self + 0x94);
          }
          uVar15 = uVar15 + 1;
          iVar16 = iVar16 + 0x94;
        } while (uVar15 < (unsigned int)piVar3[0x33]);
      }
      iVar4 = piVar3[0x1e5];
      iVar16 = VCALL(*piVar3, 0x558)(piVar3,uVar13);
      piVar3[0x1e5] = iVar4 + iVar16;
    }
  }
  piVar3 = M<int *>(self + 0x94);
  piVar5 = piVar3 + (unsigned int)M<UInt16>(piVar3 + 0x171) * 7 + 0x101;
  iVar16 = VCALL(*piVar3, 0x554)(piVar3,piVar5[4]);
  if (iVar16 == 0) {
    this_01 = M<UInt8 *>(self + 0x94);
    if (M<UInt16>(this_01 + 0x5c6) < 8) {
      iVar16 = ((IOATIR500Accelerator *)(this_01))->allocMoreCommandBuffers(1, 0x1000);
      if (iVar16 != 0) {
        iVar16 = M<int>(self + 0x94);
        piVar5 = (int *)(iVar16 + (unsigned int)M<UInt16>(iVar16 + 0x5c4) * 0x1c + 0x404);
        goto LAB_0000dd38;
      }
      this_01 = M<UInt8 *>(self + 0x94);
    }
    iVar4 = M<int>(this_01 + 0x76c);
    iVar16 = VCALL(M<int>(this_01), 0x54c)(this_01,piVar5[4]);
    M<int>(this_01 + 0x76c) = iVar4 + iVar16;
    iVar16 = M<int>(self + 0x94);
  }
  else {
    iVar16 = M<int>(self + 0x94);
  }
LAB_0000dd38:
  M<UInt16>(iVar16 + 0x5c4) = M<SInt16>(iVar16 + 0x5c4) + 1U & M<SInt16>(iVar16 + 0x5c6) - 1U;
  uVar1 = M<UInt16>(self + 0xa4);
  iVar16 = piVar5[3];
  iVar9 = piVar5[1];
  iVar4 = piVar5[2];
  iVar6 = M<int>(self + 0xa0);
  iVar11 = M<int>(self + 0x9c);
  iVar7 = M<int>(self + 0x98);
  iVar10 = M<int>(self + 0xb0);
  M<int>(self + 0x98) = *piVar5;
  M<int>(self + 0xa4) = iVar16;
  M<int>(self + 0xa0) = iVar4;
  M<int>(self + 0x9c) = iVar9;
  iVar12 = M<int>(self + 0xac);
  iVar4 = M<int>(self + 0xa8);
  iVar16 = piVar5[4];
  iVar9 = piVar5[6];
  M<int>(self + 0xac) = piVar5[5];
  M<int>(self + 0xa8) = iVar16;
  M<int>(self + 0xb0) = iVar9;
  M<UInt16>((int)piVar5 + 0xe) = M<UInt16>(self + 0xa6);
  M<UInt16>(piVar5 + 3) = uVar1;
  *piVar5 = iVar7;
  piVar5[6] = iVar10;
  piVar5[5] = iVar12;
  piVar5[4] = iVar4;
  piVar5[2] = iVar6;
  piVar5[1] = iVar11;
  iVar16 = M<int>(self + 0x94);
  if (M<char>(iVar16 + 0x88) == '\0') {
    VCALL(*M<int *>(iVar16 + 0xc0), 300)
              (M<int *>(iVar16 + 0xc0),M<UInt32>(iVar16 + 0x8c));
    M<UInt8>(M<int>(self + 0x94) + 0x88) = 1;
  }
  else {
    M<UInt8>(iVar16 + 0x89) = 1;
  }
LAB_0000de0c:
  VCALL(*M<int *>(self + 0xa0), 0x14)(M<int *>(self + 0xa0));
  *param_2 = 0;
  *param_3 = M<IOMemoryDescriptor *>(self + 0xa0);
  this->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + 0xac)),M<UInt32>(self + 0xb0),uVar14);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  return 0;
}
