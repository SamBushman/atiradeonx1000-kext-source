/*
 * ATIRadeonX1000_HardwareInit.cpp
 *
 * RESOLVED (ledger pass): R520 pipe setup, display mode/VRAM setup, PM4 (promo4) microcode load/start/stop, R500 internal space, initialize_hardware.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); real addresses in the markers.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 gl_assert_wait_timeout_event;
extern "C" UInt32 global_dummy_read_back_a_register;
extern "C" UInt32 GH_IODelay(...) asm("_IODelay");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOLog(...) asm("_IOLog");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");

extern "C" UInt32 aPM4_Microcode_R520[513];

/* real addr 0x1bd20 */
void ATIRadeonX1000::setupR520Pipes() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 bVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  
  enforceInOrderExecutionIO();
  iVar3 = M<SInt32>(self + 0x860);
  do {
    do {
    } while ((SInt32)((UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 |
                   (UInt32)M<UInt8>(iVar3 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar3 + 0xe40)) < 0);
  } while (((((M<UInt8>(iVar3 + 0x1722) & 1) == 0) || ((M<UInt8>(iVar3 + 0xe42) & 6) != 0)) ||
           ((M<UInt8>(iVar3 + 0x1722) & 2) == 0)) || ((M<UInt8>(iVar3 + 0xe42) & 0x38) != 0));
  M<UInt32>(iVar3 + 0x402c) =
       (UInt32)M<UInt8>(iVar3 + 0x402c) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0x402d) << 0x10 |
       ((UInt32)M<UInt8>(iVar3 + 0x402e) << 0x10 | 0x40000) >> 8 | (UInt32)M<UInt8>(iVar3 + 0x402f);
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)((UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 |
                   (UInt32)M<UInt8>(iVar3 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar3 + 0xe40)) < 0);
  } while ((((M<UInt8>(iVar3 + 0x1722) & 1) == 0) || ((M<UInt8>(iVar3 + 0xe42) & 6) != 0)) ||
          (((M<UInt8>(iVar3 + 0x1722) & 2) == 0 || ((M<UInt8>(iVar3 + 0xe42) & 0x38) != 0))));
  bVar1 = M<UInt8>(iVar3 + 0x402d) >> 4;
  uVar4 = bVar1 & 3;
  uVar2 = (1 << uVar4 + 1) - 1;
  M<UInt32>(iVar3 + 0x42c8) =
       uVar2 * 0x1000000 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)((UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 |
                   (UInt32)M<UInt8>(iVar3 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar3 + 0xe40)) < 0);
  } while ((((M<UInt8>(iVar3 + 0x1722) & 1) == 0) || ((M<UInt8>(iVar3 + 0xe42) & 6) != 0)) ||
          (((M<UInt8>(iVar3 + 0x1722) & 2) == 0 || ((M<UInt8>(iVar3 + 0xe42) & 0x38) != 0))));
  if (uVar4 == 1) {
    uVar2 = 6;
    M<UInt32>(self + 0xb98) = 2;
  }
  else if ((bVar1 & 3) == 0) {
LAB_0001bea0:
    uVar2 = 0;
    M<UInt32>(self + 0xb98) = 1;
  }
  else if (uVar4 == 2) {
    uVar2 = 0xc;
    M<UInt32>(self + 0xb98) = 3;
  }
  else {
    if (uVar4 != 3) goto LAB_0001bea0;
    uVar2 = 0xe;
    M<UInt32>(self + 0xb98) = 4;
  }
  M<UInt32>(self + 0xb74) = uVar2 | 0xc00011;
  M<UInt32>(iVar3 + 0x4018) = (uVar2 | 0xc00011) << 0x18 | 0xc000;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)((UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 |
                   (UInt32)M<UInt8>(iVar3 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar3 + 0xe40)) < 0);
  } while (((((M<UInt8>(iVar3 + 0x1722) & 1) == 0) || ((M<UInt8>(iVar3 + 0xe42) & 6) != 0)) ||
           ((M<UInt8>(iVar3 + 0x1722) & 2) == 0)) || ((M<UInt8>(iVar3 + 0xe42) & 0x38) != 0));
  M<UInt32>(iVar3 + 0x170c) =
       (UInt32)M<UInt8>(iVar3 + 0x170c) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0x170d) << 0x10 |
       (UInt32)M<UInt8>(iVar3 + 0x170e) << 8 |
       ((UInt32)M<UInt8>(iVar3 + 0x170f) << 0x18 | 0x80000000) >> 0x18;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)((UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 |
                   (UInt32)M<UInt8>(iVar3 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar3 + 0xe40)) < 0);
  } while ((((M<UInt8>(iVar3 + 0x1722) & 1) == 0) || ((M<UInt8>(iVar3 + 0xe42) & 6) != 0)) ||
          (((M<UInt8>(iVar3 + 0x1722) & 2) == 0 || ((M<UInt8>(iVar3 + 0xe42) & 0x38) != 0))));
  M<UInt32>(iVar3 + 0x429c) = 0x40000;
  enforceInOrderExecutionIO();
  GH_IOSleep(1);
  enforceInOrderExecutionIO();
  iVar3 = M<SInt32>(self + 0x860);
  do {
    do {
    } while ((SInt32)((UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 |
                   (UInt32)M<UInt8>(iVar3 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar3 + 0xe40)) < 0);
  } while ((((M<UInt8>(iVar3 + 0x1722) & 1) == 0) || ((M<UInt8>(iVar3 + 0xe42) & 6) != 0)) ||
          (((M<UInt8>(iVar3 + 0x1722) & 2) == 0 || ((M<UInt8>(iVar3 + 0xe42) & 0x38) != 0))));
  M<UInt32>(self + 0xb9c) = 1;
  if ((M<UInt32>(self + 0x98) & 0x200000) == 0) {
    return;
  }
  bVar1 = M<UInt8>(iVar3 + 8);
  M<UInt32>(iVar3 + 8) =
       (bVar1 & 0xffffff40 | 0x34) << 0x18 | (UInt32)M<UInt8>(iVar3 + 9) << 0x10 |
       (UInt32)M<UInt8>(iVar3 + 10) << 8 | (UInt32)M<UInt8>(iVar3 + 0xb);
  M<UInt32>(iVar3 + 8) =
       (UInt32)bVar1 << 0x18 | (UInt32)M<UInt8>(iVar3 + 9) << 0x10 | (UInt32)M<UInt8>(iVar3 + 10) << 8 |
       (UInt32)M<UInt8>(iVar3 + 0xb);
  uVar2 = ((UInt32)M<UInt8>(iVar3 + 0xf) << 0x18 ^ 0x30000000) >> 0x1c & 3;
  if (uVar2 != 0) {
    if (uVar2 < 3) {
      M<UInt32>(self + 0xb9c) = 1;
      goto LAB_0001c040;
    }
    if (uVar2 == 3) {
      if (M<UInt32>(self + 0xc54) < 4) {
        uVar2 = 1;
        M<UInt32>(self + 0xb9c) = 1;
      }
      else {
        uVar2 = 3;
        M<UInt32>(self + 0xb9c) = 2;
      }
      goto LAB_0001c040;
    }
  }
  M<UInt32>(self + 0xb9c) = 1;
  uVar2 = 1;
LAB_0001c040:
  M<UInt32>(iVar3 + 0x4124) = uVar2 << 0x18;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)((UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 |
                   (UInt32)M<UInt8>(iVar3 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar3 + 0xe40)) < 0);
  } while (((((M<UInt8>(iVar3 + 0x1722) & 1) == 0) || ((M<UInt8>(iVar3 + 0xe42) & 6) != 0)) ||
           ((M<UInt8>(iVar3 + 0x1722) & 2) == 0)) || ((M<UInt8>(iVar3 + 0xe42) & 0x38) != 0));
  M<UInt32>(iVar3 + 0x4be8) = uVar2 << 0x18;
  enforceInOrderExecutionIO();
  return;
}

/* real addr 0x1c120 */
bool ATIRadeonX1000::set_display_mode_and_vram() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 bVar1;
  UInt8 bVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  UInt8 AVar6;
  UInt8 AVar7;
  UInt16 uVar9;
  UInt32 uVar8;
  SInt32 iVar10;
  UInt32 uVar11;
  UInt32 uVar12;
  UInt32 uVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 local_f8;
  UInt32 local_f4;
  UInt8 auStack_f0 [156];
  UInt32 local_54;
  UInt32 local_50;
  
  self[0x168] = 0x0;
  M<UInt16>(self + 0x14e) = 1;
  self[0x167] = 0x6;
  M<UInt16>(self + 0x14c) = 1;
  self[0x160] = 0x0;
  self[0x163] = 0xff;
  M<UInt32>(self + 0x170) = 0;
  M<UInt32>(self + 300) = 0;
  M<UInt32>(self + 0x130) = 0;
  M<UInt32>(self + 0x134) = 0;
  M<UInt32>(self + 0x138) = 0;
  M<UInt32>(self + 0x13c) = 0;
  M<UInt16>(self + 0x140) = 0;
  M<UInt16>(self + 0x142) = 0;
  M<UInt16>(self + 0x144) = 0;
  M<UInt16>(self + 0x148) = 0;
  M<UInt16>(self + 0x14a) = 0;
  M<UInt32>(self + 0x150) = 0;
  M<UInt32>(self + 0x154) = 0xffffffff;
  M<UInt32>(self + 0x158) = 0;
  M<UInt32>(self + 0x15c) = 0;
  self[0x161] = 0x0;
  self[0x162] = 0x0;
  self[0x164] = 0x0;
  self[0x165] = 0x0;
  M<UInt32>(self + 0x16c) = 0;
  iVar10 = M<SInt32>(self + 0x860);
  M<UInt32>(self + 0x168) = M<UInt32>(self + 0x168) & 0xff0007ff | 0x111000;
  uVar4 = (UInt32)M<UInt8>(iVar10 + 0xfb) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0xfa) << 0x10 |
          (UInt32)M<UInt8>(iVar10 + 0xf9) << 8 | (UInt32)M<UInt8>(iVar10 + 0xf8);
  M<UInt32>(self + 0x9c) = uVar4;
  if (uVar4 == 0) {
    M<UInt32>(self + 0x9c) = 0x800000;
  }
  uVar5 = M<UInt32>(self + 0x9c);
  if (uVar5 < 0x8000001) {
    M<UInt32>(self + 0x84c) = uVar5;
  }
  else {
    M<UInt32>(self + 0x84c) = 0x8000000;
  }
  uVar4 = M<UInt32>(self + 0x84c);
  M<UInt32>(self + 0xd0) = 0;
  uVar12 = (uVar4 >> 1) - 1;
  if (uVar5 == uVar4) {
    iVar10 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->init_pool(uVar4);
    if (iVar10 == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->init_pool(M<UInt32>(self + 0x9c));
  }
  else {
    iVar10 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->init_pool(uVar5, uVar4, 0);
    if (iVar10 == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->init_pool(M<UInt32>(self + 0x9c),M<UInt32>(self + 0x84c),0)
    ;
  }
  if (M<UInt32>(self + 0xbb4) != 0) {
    iVar10 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->reserve((GLKMemoryElement *)(self + 0xbc4),
                        M<UInt32>(self + 0xbb4),M<UInt32>(self + 0xbac));
    if (iVar10 == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->reserve((GLKMemoryElement *)(self + 0xc3c),
               M<UInt32>(self + 0xbb4),M<UInt32>(self + 0xbac));
  }
  iVar10 = M<SInt32>(self + 0x860);
  if (((UInt32)M<UInt8>(iVar10 + 0x6113) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x6112) << 0x10 |
       (UInt32)M<UInt8>(iVar10 + 0x6111) << 8 | (UInt32)M<UInt8>(iVar10 + 0x6110)) !=
      M<UInt32>(self + 0xb6c)) {
    M<UInt32>(self + 0xb08) =
         (UInt32)M<UInt8>(iVar10 + 0x6113) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x6112) << 0x10 |
         (UInt32)M<UInt8>(iVar10 + 0x6111) << 8 | (UInt32)M<UInt8>(iVar10 + 0x6110);
    M<UInt32>(self + 0xb0c) =
         (UInt32)M<UInt8>(iVar10 + 0x6123) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x6122) << 0x10 |
         (UInt32)M<UInt8>(iVar10 + 0x6121) << 8 | (UInt32)M<UInt8>(iVar10 + 0x6120);
  }
  uVar4 = M<UInt32>(self + 0xb08);
  uVar14 = M<UInt32>(self + 0xb0c);
  iVar10 = VCALL(*M<SInt32 *>(self + 0xd4), 0x5f0)
                     (M<SInt32 *>(self + 0xd4),&local_f4,&local_f8);
  if (iVar10 != 0) {
    GH_IOLog("ERROR: VendorAccelerator::set_display_mode_and_vram() call to fFramebuffers[0].framebuffer->getCurrentDisplayMode() result:%lX\n"
                 ,iVar10);
    GH_IOSleep(10);
  }
  iVar10 = VCALL(*M<SInt32 *>(self + 0xd4), 0x5ec)
                     (M<SInt32 *>(self + 0xd4),local_f4,local_f8,0,auStack_f0);
  if (iVar10 != 0) {
    GH_IOLog("ERROR: VendorAccelerator::set_display_mode_and_vram() call to fFramebuffers[0].framebuffer->getPixelInformation() result:%lX\n"
                 ,iVar10);
    GH_IOSleep(10);
  }
  if (local_54 != 0) {
    uVar14 = local_54;
  }
  iVar10 = M<SInt32>(self + 0x860);
  uVar11 = (UInt32)M<UInt8>(iVar10 + 0x16c7) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x16c6) << 0x10 |
           (UInt32)M<UInt8>(iVar10 + 0x16c5) << 8 | M<UInt8>(iVar10 + 0x16c4) & 0xfffffff0;
  if ((M<UInt8>(iVar10 + 0x6080) & 1) == 0) {
    uVar5 = 0;
    uVar11 = 0;
    uVar14 = 0;
  }
  else {
    bVar1 = M<UInt8>(iVar10 + 0x6104) & 3;
    bVar2 = M<UInt8>(iVar10 + 0x6105) & 7;
    if (bVar1 == 1) {
      uVar16 = 4;
      if (((bVar2 != 1) && (uVar16 = 3, bVar2 != 0)) && (uVar16 = 0xf, bVar2 != 2))
      goto LAB_0001c414;
    }
    else {
      if ((M<UInt8>(iVar10 + 0x6104) & 3) == 0) {
        uVar16 = 9;
joined_r0x0001c43c:
        if (bVar2 == 0) goto LAB_0001c418;
      }
      else if (bVar1 == 2) {
        uVar16 = 6;
        if ((bVar2 == 0) || (uVar16 = 5, bVar2 == 1)) goto LAB_0001c418;
      }
      else if (bVar1 == 3) {
        uVar16 = 10;
        goto joined_r0x0001c43c;
      }
LAB_0001c414:
      uVar16 = 0xff;
    }
LAB_0001c418:
    M<UInt32>(self + 0x898) = M<UInt8>(iVar10 + 0x6088) & 1;
    if (uVar16 == 6) {
      uVar11 = uVar11 | 6;
      M<UInt32>(iVar10 + 0x15d4) = 0x2000000;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar10 + 0x15d0) = 0x2000000;
      enforceInOrderExecutionIO();
      AVar6 = 0xb;
      uVar13 = 4;
      uVar9 = 4;
    }
    else {
      if (uVar16 < 7) {
        if (uVar16 - 3 < 2) {
          uVar11 = uVar11 | 3;
          M<UInt32>(iVar10 + 0x15d4) = 0x1000000;
          enforceInOrderExecutionIO();
          M<UInt32>(iVar10 + 0x15d0) = 0x1000000;
          enforceInOrderExecutionIO();
          AVar6 = 0x7;
          uVar13 = 2;
          uVar9 = 2;
          goto LAB_0001c54c;
        }
      }
      else if (uVar16 == 9) {
        uVar11 = uVar11 | 2;
        M<UInt32>(iVar10 + 0x15d4) = 0;
        enforceInOrderExecutionIO();
        M<UInt32>(iVar10 + 0x15d0) = 0;
        enforceInOrderExecutionIO();
      }
      AVar6 = 0x1;
      uVar13 = 1;
      uVar9 = 1;
    }
LAB_0001c54c:
    M<UInt32>(iVar10 + 0x16c4) =
         uVar11 << 0x18 | (uVar11 & 0xff00) << 8 | uVar11 >> 8 & 0xff00 | uVar11 >> 0x18;
    enforceInOrderExecutionIO();
    uVar11 = uVar14 * uVar13 + 0xff & 0xffffff00;
    if (uVar13 != 0) {
      uVar14 = uVar11 / uVar13;
    }
    uVar8 = local_50;
    if ((local_50 & 0xf) != 0) {
      uVar8 = (local_50 & 0xfffffff0) + 0x10;
    }
    uVar5 = uVar8 * uVar11;
    M<UInt16>(self + 0x142) = uVar9;
    M<SInt16>(self + 0x140) = (SInt16)uVar14;
    M<SInt16>(self + 0x148) = (SInt16)local_54;
    M<SInt16>(self + 0x14a) = (SInt16)local_50;
    self[0x163] = 0xff;
    M<UInt32>(self + 0x134) = uVar4;
    M<SInt16>(self + 0x144) = (SInt16)uVar11;
    M<UInt32>(self + 0x13c) = uVar5;
    if ((M<UInt8>(iVar10 + 0x6106) & 0x10) == 0) {
      self[0x164] = (M<UInt8>(iVar10 + 0x6106) >> 5 & 1);
    }
    else {
      self[0x164] = 0x3;
    }
    self[0x167] = SUB41m(uVar16,0);
    self[0x166] = AVar6;
    M<UInt32>(self + 0xd0) = 1;
    uVar14 = 0xff;
    self[0x165] = ('\x01' - (char)((SInt32)-(uVar13 ^ 2) >> 0x1f));
  }
  if (((M<UInt32>(self + 0x98) & 0x10000) == 0) || (M<UInt32>(self + 0xcc) < 2)) {
    uVar16 = 0;
    uVar14 = 0x200000;
    goto LAB_0001c9b0;
  }
  bVar1 = M<UInt8>(iVar10 + 0x6880);
  M<UInt32>(self + 0x894) = 0;
  if (((UInt32)M<UInt8>(iVar10 + 0x6913) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x6912) << 0x10 |
       (UInt32)M<UInt8>(iVar10 + 0x6911) << 8 | (UInt32)M<UInt8>(iVar10 + 0x6910)) !=
      M<UInt32>(self + 0xb70)) {
    M<UInt32>(self + 0xb20) =
         (UInt32)M<UInt8>(iVar10 + 0x6913) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x6912) << 0x10 |
         (UInt32)M<UInt8>(iVar10 + 0x6911) << 8 | (UInt32)M<UInt8>(iVar10 + 0x6910);
    M<UInt32>(self + 0xb24) =
         (UInt32)M<UInt8>(iVar10 + 0x6923) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x6922) << 0x10 |
         (UInt32)M<UInt8>(iVar10 + 0x6921) << 8 | (UInt32)M<UInt8>(iVar10 + 0x6920);
  }
  uVar16 = M<UInt32>(self + 0xb20);
  uVar13 = M<UInt32>(self + 0xb24);
  if (((((bVar1 & 1) == 0) || (M<UInt32>(self + 0x9c) <= uVar16)) ||
      (iVar10 = VCALL(*M<SInt32 *>(self + 0xf4), 0x5f0)
                          (M<SInt32 *>(self + 0xf4),&local_f8,&local_f4), iVar10 != 0)) ||
     (iVar10 = VCALL(*M<SInt32 *>(self + 0xf4), 0x5ec)
                         (M<SInt32 *>(self + 0xf4),local_f8,local_f4,0,auStack_f0), iVar10 != 0)) {
    uVar16 = 0;
    uVar14 = 0x200000;
    M<UInt32>(self + 0x1b4) = 0;
    M<UInt32>(self + 0x1ac) = 0;
    goto LAB_0001c9b0;
  }
  if (local_54 != 0) {
    uVar13 = local_54;
  }
  iVar10 = M<SInt32>(self + 0x860);
  bVar1 = M<UInt8>(iVar10 + 0x6904) & 3;
  bVar2 = M<UInt8>(iVar10 + 0x6905) & 7;
  if (bVar1 == 1) {
    if (bVar2 == 1) {
      uVar8 = 4;
      AVar6 = 0x4;
    }
    else if (bVar2 == 0) {
      uVar8 = 3;
      AVar6 = 0x3;
    }
    else {
      if (bVar2 != 2) goto LAB_0001c710;
      uVar8 = 0xf;
      AVar6 = 0xf;
    }
  }
  else if ((M<UInt8>(iVar10 + 0x6904) & 3) == 0) {
    if (bVar2 == 0) {
      uVar8 = 9;
      AVar6 = 0x9;
    }
    else {
LAB_0001c710:
      uVar8 = 0xff;
      AVar6 = 0xff;
    }
  }
  else if (bVar1 == 2) {
    if (bVar2 == 0) {
      uVar8 = 6;
      AVar6 = 0x6;
    }
    else {
      if (bVar2 != 1) goto LAB_0001c710;
      uVar8 = 5;
      AVar6 = 0x5;
    }
  }
  else {
    if ((bVar1 != 3) || (bVar2 != 0)) goto LAB_0001c710;
    uVar8 = 10;
    AVar6 = 0xa;
  }
  M<UInt32>(self + 0x89c) = M<UInt8>(iVar10 + 0x6888) & 1;
  if (uVar8 < 3) {
LAB_0001c7d0:
    AVar7 = 0x1;
    uVar8 = 1;
    uVar9 = 1;
  }
  else if (uVar8 < 5) {
    AVar7 = 0x7;
    uVar8 = 2;
    uVar9 = 2;
  }
  else {
    if (uVar8 != 6) goto LAB_0001c7d0;
    AVar7 = 0xb;
    uVar8 = 4;
    uVar9 = 4;
  }
  uVar14 = uVar14 + uVar13 * uVar8 & ~uVar14;
  if (uVar8 != 0) {
    uVar13 = uVar14 / uVar8;
  }
  uVar3 = local_50;
  if ((local_50 & 0xf) != 0) {
    uVar3 = (local_50 & 0xfffffff0) + 0x10;
  }
  uVar15 = uVar3 * uVar14;
  M<SInt16>(self + 0x1bc) = (SInt16)uVar14;
  M<UInt16>(self + 0x1ba) = uVar9;
  M<SInt16>(self + 0x1b8) = (SInt16)uVar13;
  M<SInt16>(self + 0x1c0) = (SInt16)local_54;
  M<SInt16>(self + 0x1c2) = (SInt16)local_50;
  self[0x1db] = 0xff;
  M<UInt32>(self + 0x1ac) = uVar16;
  M<UInt32>(self + 0x1b4) = uVar15;
  if ((M<UInt8>(iVar10 + 0x6906) & 0x10) == 0) {
    self[0x1dc] = (M<UInt8>(iVar10 + 0x6906) >> 5 & 1);
  }
  else {
    self[0x1dc] = 0x3;
  }
  self[0x1df] = AVar6;
  self[0x1de] = AVar7;
  M<UInt32>(self + 0xd0) = M<UInt32>(self + 0xd0) | 2;
  self[0x1dd] = ('\x01' - (char)((SInt32)-(uVar8 ^ 2) >> 0x1f));
  if ((uVar16 < uVar4) || (uVar5 + uVar4 <= uVar16)) {
    if ((uVar16 <= uVar4) && (uVar4 < uVar16 + uVar15)) {
      if (uVar16 + uVar15 < uVar5 + uVar4) {
        uVar15 = (uVar5 + uVar4) - uVar16;
      }
      uVar5 = 0;
      M<UInt32>(self + 0x894) = 1;
    }
    if (uVar15 != 0) {
      iVar10 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->reserve((GLKMemoryElement *)(self + 0x1a4),uVar16
                          ,uVar15);
      if (iVar10 == 0) {
        return 0;
      }
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->reserve((GLKMemoryElement *)(self + 0x960),uVar16,uVar15)
      ;
      uVar13 = uVar12 & uVar16;
      if (uVar13 != 0) {
        iVar10 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->reserve((GLKMemoryElement *)(self + 0x8dc),
                            uVar16 - uVar13,uVar13);
        if (iVar10 == 0) {
          return 0;
        }
        uVar14 = 0xa00000;
        ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->reserve((GLKMemoryElement *)(self + 0x970),
                   uVar16 - uVar13,uVar13);
        goto LAB_0001c9b0;
      }
    }
    uVar14 = 0xa00000;
  }
  else {
    if (uVar5 + uVar4 < uVar16 + uVar15) {
      uVar5 = (uVar16 + uVar15) - uVar4;
    }
    uVar14 = 0xa00000;
    M<UInt32>(self + 0x894) = 1;
  }
LAB_0001c9b0:
  if (uVar5 != 0) {
    iVar10 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->reserve((GLKMemoryElement *)(self + 300),uVar4,
                        uVar5);
    if (iVar10 == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->reserve((GLKMemoryElement *)(self + 0x940),uVar4,uVar5);
    uVar12 = uVar12 & uVar4;
    if (uVar12 != 0) {
      iVar10 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->reserve((GLKMemoryElement *)(self + 0x8ec),
                          uVar4 - uVar12,uVar12);
      if (iVar10 == 0) {
        return 0;
      }
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->reserve((GLKMemoryElement *)(self + 0x950),uVar4 - uVar12
                 ,uVar12);
    }
  }
  iVar10 = M<SInt32>(self + 0x860);
  M<UInt32>(iVar10 + 0xb00) = uVar14 >> 8 | 0x1000000;
  uVar12 = (uVar11 & 0x3f00) << 0x10;
  uVar4 = uVar4 >> 10;
  M<UInt32>(iVar10 + 0x16e0) =
       uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | (uVar4 & 0x3f0000) >> 8 |
       (uVar12 | 0x40000000) >> 0x18;
  enforceInOrderExecutionIO();
  if (uVar16 != 0) {
    uVar16 = uVar16 >> 10;
    M<UInt32>(iVar10 + 0x16f8) =
         uVar16 << 0x18 | (uVar16 & 0xff00) << 8 | (uVar16 & 0x3f0000) >> 8 |
         (uVar12 | 0x40000000) >> 0x18;
    enforceInOrderExecutionIO();
    return 1;
  }
  return 1;
}

/* real addr 0x1cb00 */
bool ATIRadeonX1000::stop_promo4_engine() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  UInt8 bVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  
  self[0x80] = 0x0;
  iVar4 = M<SInt32>(self + 0x860);
  if (iVar4 != 0) {
    enforceInOrderExecutionIO();
    iVar5 = 1000;
    while ((((((SInt32)((UInt32)M<UInt8>(iVar4 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar4 + 0xe42) << 0x10
                     | (UInt32)M<UInt8>(iVar4 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar4 + 0xe40)) < 0 ||
              ((M<UInt8>(iVar4 + 0x1722) & 1) == 0)) || ((M<UInt8>(iVar4 + 0xe42) & 6) != 0)) ||
            (((M<UInt8>(iVar4 + 0x1722) & 2) == 0 || ((M<UInt8>(iVar4 + 0xe42) & 0x38) != 0)))) &&
           (bVar1 = iVar5 != 0, iVar5 = iVar5 + -1, bVar1))) {
      GH_IODelay(100);
      iVar4 = M<SInt32>(self + 0x860);
    }
    M<UInt32>(iVar4 + 0x770) = 0;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar4 + 0x704) =
         (UInt32)M<UInt8>(iVar4 + 0x704) << 0x18 | (UInt32)M<UInt8>(iVar4 + 0x705) << 0x10 |
         (UInt32)M<UInt8>(iVar4 + 0x706) << 8 |
         ((UInt32)M<UInt8>(iVar4 + 0x707) << 0x18 | 0x8000000) >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar4 + 0x744) = 0;
    enforceInOrderExecutionIO();
    uVar2 = (UInt32)M<UInt8>(iVar4 + 0x707) << 0x18;
    bVar3 = M<UInt8>(iVar4 + 0x704);
    M<UInt32>(iVar4 + 0x704) =
         (UInt32)bVar3 << 0x18 | (UInt32)M<UInt8>(iVar4 + 0x705) << 0x10 |
         (UInt32)M<UInt8>(iVar4 + 0x706) << 8 | (uVar2 | 0x80000000) >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar4 + 0x71c) = 0;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar4 + 0x714) = 0;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar4 + 0x704) =
         (UInt32)bVar3 << 0x18 | (UInt32)M<UInt8>(iVar4 + 0x705) << 0x10 |
         (UInt32)M<UInt8>(iVar4 + 0x706) << 8 | (uVar2 & 0x7fffffff) >> 0x18;
    enforceInOrderExecutionIO();
    enforceInOrderExecutionIO();
    iVar5 = 1000;
    while (((((SInt32)((UInt32)M<UInt8>(iVar4 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar4 + 0xe42) << 0x10
                    | (UInt32)M<UInt8>(iVar4 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar4 + 0xe40)) < 0 ||
             ((M<UInt8>(iVar4 + 0x1722) & 1) == 0)) ||
            (((M<UInt8>(iVar4 + 0xe42) & 6) != 0 ||
             (((M<UInt8>(iVar4 + 0x1722) & 2) == 0 || ((M<UInt8>(iVar4 + 0xe42) & 0x38) != 0))))))
           && (bVar1 = iVar5 != 0, iVar5 = iVar5 + -1, bVar1))) {
      GH_IODelay(100);
      iVar4 = M<SInt32>(self + 0x860);
    }
    enforceInOrderExecutionIO();
    iVar5 = 1000;
    while ((((((SInt32)((UInt32)M<UInt8>(iVar4 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar4 + 0xe42) << 0x10
                     | (UInt32)M<UInt8>(iVar4 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar4 + 0xe40)) < 0 ||
              ((M<UInt8>(iVar4 + 0x1722) & 1) == 0)) || ((M<UInt8>(iVar4 + 0xe42) & 6) != 0)) ||
            (((M<UInt8>(iVar4 + 0x1722) & 2) == 0 || ((M<UInt8>(iVar4 + 0xe42) & 0x38) != 0)))) &&
           (bVar1 = iVar5 != 0, iVar5 = iVar5 + -1, bVar1))) {
      GH_IODelay(100);
      iVar4 = M<SInt32>(self + 0x860);
    }
  }
  return 1;
}

/* real addr 0x1cd30 */
void ATIRadeonX1000::load_promo4_micro_code() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 *puVar2;
  SInt32 iVar3;
  SInt32 iVar4;
  
  iVar3 = M<SInt32>(self + 0x860);
  M<UInt32>(iVar3 + 0x7d4) = 0;
  enforceInOrderExecutionIO();
  iVar4 = 0x100;
  puVar2 = aPM4_Microcode_R520 + 1;
  do {
    uVar1 = *puVar2;
    M<UInt32>(iVar3 + 0x7dc) =
         uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
    enforceInOrderExecutionIO();
    uVar1 = puVar2[-1];
    M<UInt32>(iVar3 + 0x7e0) =
         uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
    enforceInOrderExecutionIO();
    puVar2 = puVar2 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

/* real addr 0x1cd90 */
bool ATIRadeonX1000::start_promo4_engine(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  UInt8 *pAVar8;
  UInt32 uVar9;
  SInt32 iVar10;
  SInt32 iVar11;
  UInt32 uVar12;
  
  enforceInOrderExecutionIO();
  iVar11 = M<SInt32>(self + 0x860);
  uVar4 = (UInt32)M<UInt8>(iVar11 + 0x705) << 8;
  uVar6 = ((UInt32)M<UInt8>(iVar11 + 0x707) << 0x18 | (UInt32)M<UInt8>(iVar11 + 0x706) << 0x10) &
          0x77f0c0ff;
  uVar12 = uVar6 | M<UInt8>(iVar11 + 0x704) | 0xa000a;
  M<UInt32>(iVar11 + 0x704) =
       uVar12 << 0x18 | (uVar4 & 0xc000) << 8 | uVar12 >> 8 & 0xff00 | uVar6 >> 0x18;
  enforceInOrderExecutionIO();
  load_promo4_micro_code();
  if (param_1 == 4) {
    iVar10 = M<SInt32>(self + 0x860);
    M<UInt32>(iVar10 + 0x718) = 0x23000000;
    enforceInOrderExecutionIO();
    uVar7 = (UInt32)M<UInt8>(iVar10 + 0x711) << 8;
    uVar5 = (UInt32)M<UInt8>(iVar10 + 0x710);
    uVar9 = (UInt32)M<UInt8>(iVar10 + 0x713) << 0x18 | (UInt32)M<UInt8>(iVar10 + 0x712) << 0x10 |
            uVar7 | uVar5;
    M<UInt32>(self + 0x914) = uVar9;
    M<UInt32>(iVar10 + 0x714) = uVar5 << 0x18 | (uVar7 & 0x700) << 8;
    enforceInOrderExecutionIO();
    M<UInt32>(self + 0x918) = uVar9;
    iVar11 = M<SInt32>(self + 0x90c);
    M<UInt32>(iVar11 + M<SInt32>(self + 0x910)) = uVar5 << 0x18 | (uVar7 & 0x700) << 8;
    enforceInOrderExecutionIO();
    if ((M<UInt32>(self + 0x98) & 0x80000) == 0) {
      uVar7 = M<SInt32>(self + 0x8a4) + M<SInt32>(self + 0x228) + (iVar11 - M<SInt32>(self + 0x238));
      M<UInt32>(iVar10 + 0x70c) =
           (uVar7 & 0xfffffffc) << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
           uVar7 >> 0x18;
      enforceInOrderExecutionIO();
    }
    M<UInt32>(iVar10 + 0x740) = 0x40;
    enforceInOrderExecutionIO();
    iVar11 = 0;
    while( true ) {
      bVar2 = M<UInt8>(iVar10 + 0xe42);
      bVar3 = M<UInt8>(iVar10 + 0xe41);
      iVar11 = iVar11 + 1;
      GH_IOSleep(1);
      if ((((UInt32)bVar2 << 0x10 | (UInt32)bVar3 << 8) & 0x10200) == 0) break;
      if (iVar11 == 0xf4241) {
        return 0;
      }
      iVar10 = M<SInt32>(self + 0x860);
    }
    if (iVar11 != 0xf4241) {
      M<UInt32>(M<SInt32>(self + 0x860) + 0x704) =
           uVar12 << 0x18 | (uVar4 & 0xc000) << 8 | uVar12 >> 8 & 0xff00 | uVar6 >> 0x18;
      enforceInOrderExecutionIO();
      iVar11 = 0;
      pAVar8 = self;
      do {
        if (M<SInt32>(pAVar8 + 0xe4) != 0) {
          self[0x80] = 0x1;
          return 1;
        }
        bVar1 = iVar11 != 1;
        pAVar8 = pAVar8 + 0x20;
        iVar11 = iVar11 + 1;
      } while (bVar1);
      return 1;
    }
  }
  return 0;
}

/* real addr 0x1cf70 */
void ATIRadeonX1000::setup_R500_internal_space() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  
  enforceInOrderExecutionIO();
  ppcSync();
  instructionSynchronize();
  iVar5 = M<SInt32>(self + 0x860);
  M<UInt32>(iVar5 + 0x740) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x744) = 0;
  enforceInOrderExecutionIO();
  uVar7 = M<UInt32>(self + 0x98);
  M<UInt32>(self + 0x8fc) = 0;
  if ((uVar7 & 0x400000) == 0) {
    M<UInt32>(iVar5 + 0x70) = 0x4007f00;
    enforceInOrderExecutionIO();
  }
  else {
    M<UInt32>(iVar5 + 0x70) = 0x1007f00;
    enforceInOrderExecutionIO();
  }
  uVar4 = (UInt32)CONCAT11(M<UInt8>(iVar5 + 0x75),M<UInt8>(iVar5 + 0x74));
  if (uVar4 != 0) {
    uVar8 = (UInt32)M<UInt8>(iVar5 + 0xfb) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0xfa) << 0x10 |
            (UInt32)M<UInt8>(iVar5 + 0xf9) << 8 | (UInt32)M<UInt8>(iVar5 + 0xf8);
    if (uVar8 == 0) {
      uVar8 = 0x8000000;
    }
    uVar11 = (UInt32)M<UInt8>(iVar5 + 0x133) << 0x18;
    uVar2 = (UInt32)M<UInt8>(iVar5 + 0x132) << 0x10;
    uVar3 = (UInt32)M<UInt8>(iVar5 + 0x131) << 8;
    uVar9 = (UInt32)M<UInt8>(iVar5 + 0x10b) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x10a) << 0x10 |
            (UInt32)M<UInt8>(iVar5 + 0x109) << 8 | (UInt32)M<UInt8>(iVar5 + 0x108);
    uVar10 = uVar11 | uVar2 & 0xff7fffff | uVar3 | (UInt32)M<UInt8>(iVar5 + 0x130);
    if (((UInt32)M<UInt8>(iVar5 + 0x107) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x106) << 0x10 |
         (UInt32)M<UInt8>(iVar5 + 0x105) << 8 | (UInt32)M<UInt8>(iVar5 + 0x104)) ==
        uVar9 + ((UInt32)M<UInt8>(iVar5 + 0x103) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x102) << 0x10 |
                 (UInt32)M<UInt8>(iVar5 + 0x101) << 8 | (UInt32)M<UInt8>(iVar5 + 0x100))) {
      uVar9 = uVar9 << 1;
      uVar10 = uVar11 | uVar2 | uVar3 | (UInt32)M<UInt8>(iVar5 + 0x130) | 0x800000;
    }
    if (uVar9 < uVar8) {
      M<UInt32>(iVar5 + 0xf8) =
           uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18;
      enforceInOrderExecutionIO();
      M<UInt32>(self + 0x8a4) =
           (UInt32)M<UInt8>(iVar5 + 0xfb) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0xfa) << 0x10 |
           (UInt32)M<UInt8>(iVar5 + 0xf9) << 8 | (UInt32)M<UInt8>(iVar5 + 0xf8);
      uVar8 = uVar9;
    }
    M<UInt32>(iVar5 + 0x130) =
         uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18;
    enforceInOrderExecutionIO();
    bVar1 = (uVar7 & 0x400000) == 0;
    uVar11 = ((UInt32)M<UInt8>(iVar5 + 0x6913) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x6912) << 0x10 |
              (UInt32)M<UInt8>(iVar5 + 0x6911) << 8 | (UInt32)M<UInt8>(iVar5 + 0x6910)) +
             uVar4 * -0x10000;
    uVar4 = ((UInt32)M<UInt8>(iVar5 + 0x6113) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x6112) << 0x10 |
             (UInt32)M<UInt8>(iVar5 + 0x6111) << 8 | (UInt32)M<UInt8>(iVar5 + 0x6110)) +
            uVar4 * -0x10000;
    if (bVar1) {
      M<UInt32>(iVar5 + 0x70) = 0x400ff00;
      enforceInOrderExecutionIO();
    }
    else {
      M<UInt32>(iVar5 + 0x70) = 0x100ff00;
      enforceInOrderExecutionIO();
    }
    M<UInt32>(iVar5 + 0x74) = 0xffff;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar5 + 0x134) = 0;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar5 + 0x6110) =
         (UInt32)M<UInt8>(iVar5 + 0x6110) * 0x1000000 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 |
         uVar4 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar5 + 0x6910) =
         (UInt32)M<UInt8>(iVar5 + 0x6910) * 0x1000000 | (uVar11 & 0xff00) << 8 | uVar11 >> 8 & 0xff00
         | uVar11 >> 0x18;
    enforceInOrderExecutionIO();
    if (bVar1) {
      M<UInt32>(iVar5 + 0x70) = 0x400ff00;
      enforceInOrderExecutionIO();
    }
    else {
      M<UInt32>(iVar5 + 0x70) = 0x100ff00;
      enforceInOrderExecutionIO();
    }
    M<UInt32>(iVar5 + 0x74) = (uVar8 - 1 & 0xffff0000) >> 8 & 0xff00 | uVar8 - 1 >> 0x18;
    enforceInOrderExecutionIO();
  }
  if ((uVar7 & 0x400000) == 0) {
    M<UInt32>(iVar5 + 0x70) = 0x4007f00;
    enforceInOrderExecutionIO();
  }
  else {
    M<UInt32>(iVar5 + 0x70) = 0x1007f00;
    enforceInOrderExecutionIO();
  }
  iVar6 = M<SInt32>(self + 0x8d4);
  uVar8 = ((UInt32)M<UInt8>(iVar5 + 0x77) << 0x18 | (UInt32)M<UInt8>(iVar5 + 0x76) << 0x10) + 0x10000;
  M<UInt32>(self + 0x8a4) = uVar8;
  uVar4 = uVar8 + iVar6;
  M<UInt32>(iVar5 + 0x30) = 0x13000000;
  enforceInOrderExecutionIO();
  uVar7 = M<UInt32>(self + 0xbb0);
  M<UInt32>(iVar5 + 0x34) =
       uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x30) = 0x17000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x30) = 0x16000000;
  enforceInOrderExecutionIO();
  uVar7 = uVar8 + M<SInt32>(self + 0x830) * 0x400;
  M<UInt32>(iVar5 + 0x34) = (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x30) = 0x15000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x30) = 0x14000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x34) = uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x30) = 0x12000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x30) = 0x11000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x34) = uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(self + 0xbbc) = 0x47;
  M<UInt32>(iVar5 + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x34) = 0x10000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x34) = 0x47000000;
  enforceInOrderExecutionIO();
  uVar8 = uVar8 + M<SInt32>(self + 0x904);
  M<UInt32>(iVar5 + 0x700) =
       M<SInt32>(self + 0x904) << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15e0) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15e4) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15e8) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15ec) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15f0) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15f4) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15f8) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x15fc) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x1fa8) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar5 + 0x774) =
       iVar6 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
  enforceInOrderExecutionIO();
  if (M<SInt32>(self + 0x8d0) != 0) {
    M<UInt32>(iVar5 + 0x770) = 0xff000000;
    enforceInOrderExecutionIO();
    return;
  }
  M<UInt32>(iVar5 + 0x770) = 0;
  enforceInOrderExecutionIO();
  return;
}

/* real addr 0x1f3c0 */
bool ATIRadeonX1000::initialize_hardware() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 bVar1;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt8 bVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  SInt32 iVar7;
  SInt32 iVar8;
  
  if ((M<UInt32>(self + 0x98) & 0xf00000) != 0) {
    setupR520Pipes();
  }
  setup_R500_internal_space();
  this->initialize_GUI();
  iVar7 = start_promo4_engine(4);
  uVar5 = 0;
  if (iVar7 != 0) {
    iVar7 = set_display_mode_and_vram();
    if (iVar7 == 0) {
      GH_IOLog("set_display_mode_and_vram failed\n");
      uVar5 = 0;
    }
    else {
      iVar7 = M<SInt32>(self + 0x860);
      uVar6 = M<SInt32>(self + 0x50) - 1;
      M<UInt32>(iVar7 + 0x15e0) =
           uVar6 * 0x1000000 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
      enforceInOrderExecutionIO();
      uVar6 = M<UInt32>(self + 0x850);
      M<UInt32>(iVar7 + 0x15e4) =
           uVar6 << 0x18 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x16e8) = 0xff1fff1f;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x16cc) = 0xffffffff;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x2284) = 0;
      enforceInOrderExecutionIO();
      uVar6 = M<UInt32>(self + 0x98);
      if ((uVar6 & 0x200000) == 0) {
        if ((uVar6 & 0x400000) == 0) {
          M<UInt32>(iVar7 + 0x2080) = 0x56083000;
          enforceInOrderExecutionIO();
          if ((uVar6 & 0x800000) != 0) {
            M<UInt32>(iVar7 + 0x4614) = 0x1040000;
            enforceInOrderExecutionIO();
          }
        }
        else {
          M<UInt32>(iVar7 + 0x2080) = 0x56023000;
          enforceInOrderExecutionIO();
          M<UInt32>(iVar7 + 0x47c8) = 0;
          enforceInOrderExecutionIO();
        }
      }
      else {
        M<UInt32>(iVar7 + 0x2080) = 0x56053000;
        enforceInOrderExecutionIO();
        M<UInt32>(iVar7 + 0x4bec) = 0x1000000;
        enforceInOrderExecutionIO();
        M<UInt32>(iVar7 + 0x4398) = 0;
        enforceInOrderExecutionIO();
        M<UInt32>(iVar7 + 0x47c8) = 0;
        enforceInOrderExecutionIO();
        M<UInt32>(iVar7 + 0x4614) = 0x1040000;
        enforceInOrderExecutionIO();
      }
      M<UInt32>(iVar7 + 0x43b0) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43b4) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43b8) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43bc) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43c0) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43c4) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43c8) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43cc) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(iVar7 + 0x43d0) = 0xffff0000;
      enforceInOrderExecutionIO();
      if (self[0x85] != 0x0) {
        this->submit_empty_buffer();
        iVar7 = M<SInt32>(self + 0x860);
      }
      M<UInt32>(self + 0xb78) =
           (UInt32)M<UInt8>(iVar7 + 0x6107) << 0x18 | (UInt32)M<UInt8>(iVar7 + 0x6106) << 0x10 |
           (UInt32)M<UInt8>(iVar7 + 0x6105) << 8 | (UInt32)M<UInt8>(iVar7 + 0x6104);
      M<UInt32>(self + 0xb7c) =
           (UInt32)M<UInt8>(iVar7 + 0x6907) << 0x18 | (UInt32)M<UInt8>(iVar7 + 0x6906) << 0x10 |
           (UInt32)M<UInt8>(iVar7 + 0x6905) << 8 | (UInt32)M<UInt8>(iVar7 + 0x6904);
      M<UInt32>(self + 0xb80) =
           (UInt32)M<UInt8>(iVar7 + 0x614b) << 0x18 | (UInt32)M<UInt8>(iVar7 + 0x614a) << 0x10 |
           (UInt32)M<UInt8>(iVar7 + 0x6149) << 8 | (UInt32)M<UInt8>(iVar7 + 0x6148);
      M<UInt32>(self + 0xb84) =
           (UInt32)M<UInt8>(iVar7 + 0x694b) << 0x18 | (UInt32)M<UInt8>(iVar7 + 0x694a) << 0x10 |
           (UInt32)M<UInt8>(iVar7 + 0x6949) << 8 | (UInt32)M<UInt8>(iVar7 + 0x6948);
      M<UInt32>(self + 0xb88) =
           (UInt32)M<UInt8>(iVar7 + 0x60c7) << 0x18 | (UInt32)M<UInt8>(iVar7 + 0x60c6) << 0x10 |
           (UInt32)M<UInt8>(iVar7 + 0x60c5) << 8 | (UInt32)M<UInt8>(iVar7 + 0x60c4);
      M<UInt32>(self + 0xb8c) =
           (UInt32)M<UInt8>(iVar7 + 0x68c7) << 0x18 | (UInt32)M<UInt8>(iVar7 + 0x68c6) << 0x10 |
           (UInt32)M<UInt8>(iVar7 + 0x68c5) << 8 | (UInt32)M<UInt8>(iVar7 + 0x68c4);
      uVar5 = 1;
      if (M<SInt32>(self + 3000) != 0) {
        enforceInOrderExecutionIO();
        bVar1 = M<UInt8>(iVar7 + 0x1727);
        bVar2 = M<UInt8>(iVar7 + 0x1726);
        bVar3 = M<UInt8>(iVar7 + 0x1725);
        bVar4 = M<UInt8>(iVar7 + 0x1724);
        iVar7 = M<SInt32>(self + 0x914);
        iVar8 = M<SInt32>(self + 0x900);
        M<UInt32>(iVar8 + iVar7 * 4) = 0x5c9;
        uVar6 = iVar7 + 1U & 0x7ff;
        M<UInt32>(self + 0x914) = uVar6;
        M<UInt32>(iVar8 + uVar6 * 4) =
             (UInt32)bVar1 << 0x18 | (UInt32)bVar2 << 0x10 | (UInt32)bVar3 << 8 | (UInt32)bVar4 | 3;
        M<UInt32>(self + 0x914) = uVar6 + 1 & 0x7ff;
        this->submit_ring_data();
        uVar5 = 1;
      }
    }
  }
  return uVar5;
}

