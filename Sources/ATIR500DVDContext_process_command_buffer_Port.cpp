/*
 * ATIR500DVDContext_process_command_buffer_Port.cpp
 *
 * ATIR500DVDContext::process_command_buffer (real addr 0x357c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");
extern "C" UInt32 GH_OSAddAtomic(...) asm("_OSAddAtomic");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");


/* real addr 0x357c0 */
IOReturn ATIR500DVDContext::process_command_buffer(VendorCommandDescriptor *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt16 sVar1;
  SInt16 sVar2;
  UInt16 uVar3;
  UInt16 uVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  SInt32 iVar12;
  UInt32 uVar13;
  SInt32 *piVar14;
  UInt32 uVar15;
  UInt32 *puVar16;
  UInt32 uVar17;
  SInt32 iVar18;
  UInt32 uVar19;
  UInt32 *puVar20;
  UInt32 uVar21;
  SInt32 iVar22;
  SInt32 iVar23;
  UInt32 uVar24;
  SInt32 iVar25;
  UInt32 *puVar26;
  UInt32 uVar27;
  UInt32 uVar28;
  UInt32 uVar29;
  UInt32 uVar30;
  UInt32 uVar31;
  UInt32 uVar32;
  UInt32 uVar33;
  UInt32 uVar34;
  UInt32 uVar35;
  UInt32 uVar36;
  UInt32 uVar37;
  UInt32 uVar38;
  UInt32 uVar39;
  UInt32 *puVar40;
  UInt32 uVar41;
  UInt8 *pVVar42;
  bool bVar43;
  UInt8 bVar44;
  SInt32 iVar45;
  UInt32 local_b4 [4];
  UInt32 local_a4 [7];
  UInt32 local_88;
  UInt32 uStack_84;
  UInt32 local_80;
  UInt32 uStack_7c;
  UInt32 local_78;
  UInt32 local_74;
  UInt32 local_70;
  UInt32 local_6c;
  UInt32 local_68;
  UInt32 local_64;
  UInt32 local_60;
  UInt32 local_5c;
  UInt32 local_58;
  
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_68 = 0;
  local_70 = 0;
  puVar40 = (UInt32 *)(M<SInt32>(self + 0xa4) + 0x1c);
  local_6c = 0xffffffff;
  do {
    uVar10 = local_6c;
    uVar37 = *puVar40;
    uVar17 = uVar37 & 0xff000000;
    if (uVar17 == 0x25000000) goto LAB_00037620;
    if (uVar17 < 0x25000001) {
      if (uVar17 != 0x15000000) {
        if (uVar17 < 0x15000001) {
          if (uVar17 == 0x9000000) goto LAB_00039030;
          if (0x9000000 < uVar17) {
            if (uVar17 == 0xd000000) {
              uVar17 = puVar40[3];
              uVar21 = puVar40[4];
              uVar11 = puVar40[5];
              bVar44 = (puVar40[2] == 0) << 1;
              if (puVar40[2] == 0) {
                pVVar42 = M<UInt8 *>(self + puVar40[1] * 4 + 0x104);
                if ((M<SInt32>(pVVar42 + 4) != 0) ||
                   (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42)),
                   M<SInt32>(pVVar42 + 4) != 0)) {
                  GH_IOGetTime(pVVar42 + 0x2c);
                  iVar23 = M<SInt32>(pVVar42 + 0x34);
                  M<UInt32>(iVar23 + 0x38) = M<UInt32>(pVVar42 + 0x38);
                  M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar23;
                  M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
                  M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                  M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                  M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
                }
                uVar19 = 0;
                M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
                if (M<SInt32>(pVVar42 + 4) != 0) {
                  uVar19 = (UInt32)(M<SInt32>(pVVar42 + 4) +
                                 M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4))
                           >> 10;
                }
                iVar23 = 0;
                uVar19 = uVar19 | (uVar11 & 0xff0) << 0x12;
              }
              else {
                iVar18 = M<SInt32>(self + 0xf8);
                iVar23 = iVar18 + 0x828;
                uVar19 = M<UInt32>(iVar18 + 0x830) >> 10 |
                         (M<UInt16>(iVar18 + 0x840) & 0x3fc0) << 0x10;
              }
              *puVar40 = 0x1393;
              puVar40[1] = 10;
              puVar40[2] = 0x5c8;
              puVar40[3] = 0x20000;
              puVar40[4] = 0xc0069a00;
              puVar40[5] = 0x52f036da;
              puVar40[6] = uVar19;
              puVar40[7] = M<UInt32>(self + 0x158);
              puVar40[8] = M<UInt32>(self + 0x15c);
              puVar40[9] = 0;
              puVar40[10] = 0;
              if ((bool)(bVar44 >> 1 & 1)) {
                puVar40[0xb] = uVar21 | uVar17 << 0x10;
              }
              else {
                puVar40[0xb] = M<UInt32>(iVar23 + 0x1c);
              }
              goto LAB_00038f80;
            }
            if (uVar17 < 0xd000001) {
              if (uVar17 != 0xb000000) {
                if (uVar17 != 0xc000000) {
                  if (uVar17 != 0xa000000) goto LAB_00039028;
                  piVar14 = M<SInt32 *>(self + 0x8c);
                  if (piVar14[0x22f] != 0) {
                    VCALL(*piVar14, 0x5ec)(piVar14,M<UInt32>(self + 0x154));
                    M<UInt32>(M<SInt32>(self + 0xf8) + 0xd90) = puVar40[1];
                    iVar18 = M<SInt32>(self + 0xf8);
                    iVar23 = (SInt32)M<SInt16>(iVar18 + 0x9a) - (SInt32)M<SInt16>(iVar18 + 0x94);
                    if ((M<SInt16>(iVar18 + 0x98) != M<SInt16>(iVar18 + 0x96)) && (iVar23 != 0)) {
                      iVar12 = puVar40[1] * 0x78 + iVar18;
                      if ((puVar40[3] & 2) == 0) {
                        if (puVar40[2] == 0) {
                          uVar17 = M<UInt32>(iVar12 + 0x560);
                          uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
                        }
                        else {
                          uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
                          uVar17 = (iVar23 * (UInt32)M<UInt16>(iVar12 + 0x570) * 3 >> 1) +
                                   M<SInt32>(iVar12 + 0x560);
                        }
                      }
                      else {
                        uVar17 = M<UInt32>(iVar18 + 0x998);
                        uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
                      }
                      if ((puVar40[3] & 4) == 0) {
                        if (puVar40[2] == 0) {
                          uVar11 = iVar23 * uVar21 + M<SInt32>(iVar12 + 0x560);
                        }
                        else {
                          uVar11 = iVar23 * uVar21 +
                                   (iVar23 * uVar21 * 3 >> 1) + M<SInt32>(iVar12 + 0x560);
                        }
                      }
                      else {
                        uVar11 = iVar23 * uVar21 + M<SInt32>(iVar18 + 0x998);
                      }
                      *puVar40 = 0x1140;
                      puVar40[1] = uVar21 - 1;
                      puVar40[2] = 0x1150;
                      uVar19 = (M<UInt8>(iVar12 + 0x590) & 1) << 2;
                      uVar28 = (M<UInt8>(iVar12 + 0x590) & 6) << 2;
                      puVar40[3] = uVar17 & 0xffffffe0 | uVar19 | uVar28;
                      puVar40[4] = 0x1141;
                      puVar40[5] = (uVar21 >> 1) - 1;
                      puVar40[6] = 0x1151;
                      puVar40[7] = uVar28 | uVar19 | uVar11 & 0xffffffe0;
                      puVar40[8] = 0x1393;
                      puVar40[9] = 10;
                      puVar40[10] = 0x138a;
                      puVar40[0xb] = M<UInt32>(iVar18 + 0x128) & 0xffffffe0;
                      puVar40[0xc] = 0x138e;
                      uVar17 = 0;
                      iVar23 = (UInt32)M<UInt8>(iVar18 + 0x15a) * 0x1c;
                      if ((M<UInt32>(iVar18 + 0x15c) & 0xf00000) != 0) {
                        uVar17 = (UInt32)M<UInt16>(iVar18 + 0x134) /
                                 (M<UInt32>(iVar18 + 0x15c) >> 0x14 & 0xf);
                      }
                      uVar21 = 0x20 / M<UInt16>(iVar18 + 0x136);
                      if (uVar21 <= uVar17) {
                        uVar21 = uVar17;
                      }
                      local_64 = FormatTableLookup_0x0004d2e0(iVar23) >> 1 & 0x1e00000 |
                                 (FormatTableLookup_0x0004d2dc(iVar23) & 0xc00) << 9 |
                                 (M<UInt8>(iVar18 + 0x158) & 6) << 0x10 |
                                 (M<UInt8>(iVar18 + 0x158) & 1) << 0x10 |
                                 uVar21 & 0x3ffe | local_64 & 0xfe00c001;
                      puVar40[0xd] = local_64;
                      uVar37 = uVar37 & 0xffffff;
                      goto LAB_0003903c;
                    }
                  }
                }
                goto LAB_00039030;
              }
              if (puVar40[2] == 0) {
                pVVar42 = M<UInt8 *>(self + puVar40[1] * 4 + 0x104);
                if ((M<SInt32>(pVVar42 + 4) != 0) ||
                   (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42)),
                   M<SInt32>(pVVar42 + 4) != 0)) {
                  GH_IOGetTime(pVVar42 + 0x2c);
                  iVar23 = M<SInt32>(pVVar42 + 0x34);
                  M<UInt32>(iVar23 + 0x38) = M<UInt32>(pVVar42 + 0x38);
                  M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar23;
                  M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
                  M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                  M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                  M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
                }
                M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
                if (M<SInt32>(pVVar42 + 4) == 0) {
                  iVar23 = M<SInt32>(self + 0xf8);
                  uVar17 = 0;
                }
                else {
                  iVar23 = M<SInt32>(self + 0xf8);
                  uVar17 = (UInt32)(M<SInt32>(pVVar42 + 4) +
                                 M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4))
                           >> 5;
                }
              }
              else {
                iVar23 = M<SInt32>(self + 0xf8);
                uVar17 = M<UInt32>(iVar23 + 0x830) >> 5;
              }
              *puVar40 = 0x1150;
              puVar40[1] = uVar17 << 5;
              puVar40[2] = 0x1393;
              puVar40[3] = 10;
              puVar40[4] = 0x138a;
              puVar40[5] = M<UInt32>(iVar23 + 0x128) & 0xffffffe0;
              puVar40[6] = 0x138e;
              uVar17 = 0;
              iVar18 = (UInt32)M<UInt8>(iVar23 + 0x15a) * 0x1c;
              if ((M<UInt32>(iVar23 + 0x15c) & 0xf00000) != 0) {
                uVar17 = (UInt32)M<UInt16>(iVar23 + 0x134) /
                         (M<UInt32>(iVar23 + 0x15c) >> 0x14 & 0xf);
              }
              uVar21 = 0x20 / M<UInt16>(iVar23 + 0x136);
              if (uVar21 <= uVar17) {
                uVar21 = uVar17;
              }
              local_58 = FormatTableLookup_0x0004d2e0(iVar18) >> 1 & 0x1e00000 |
                         (FormatTableLookup_0x0004d2dc(iVar18) & 0xc00) << 9 |
                         (M<UInt8>(iVar23 + 0x158) & 6) << 0x10 |
                         (M<UInt8>(iVar23 + 0x158) & 1) << 0x10 |
                         uVar21 & 0x3ffe | local_58 & 0xfe00c001;
              puVar40[7] = local_58;
              uVar37 = uVar37 & 0xffffff;
            }
            else if (uVar17 == 0x13000000) {
              iVar23 = M<SInt32>(self + 0xf8);
              iVar18 = puVar40[1] * 0x78 + iVar23;
              uVar17 = M<UInt32>(iVar18 + 0x560);
              uVar4 = M<UInt16>(iVar18 + 0x570);
              *puVar40 = 0x1087;
              puVar40[1] = (M<UInt16>(iVar18 + 0x576) & 0x3fff) << 2 | (UInt32)uVar4 << 0x11;
              puVar40[2] = 0x1150;
              puVar40[3] = uVar17 & 0xffffffe0;
              puVar40[4] = 0x1393;
              puVar40[5] = 10;
              puVar40[6] = 0x138a;
              puVar40[7] = uVar17 + (((SInt32)M<SInt16>(iVar23 + 0x9a) -
                                     (SInt32)M<SInt16>(iVar23 + 0x94)) * (UInt32)uVar4 * 3 >> 1) &
                           0xffffffe0;
              puVar40[8] = 0x138e;
              puVar40[9] = uVar4 >> 2 & 0x3ffe | (M<UInt8>(iVar18 + 0x590) & 1) << 0x10 |
                           (M<UInt8>(iVar18 + 0x590) & 6) << 0x10 |
                           (M<UInt8>(iVar18 + 0x591) & 3) << 0x13 | 0xc00000;
              dVar9 = DOUBLE_0004c3c0;
              dVar8 = DOUBLE_0004c3b8;
              dVar7 = DOUBLE_0004c3a8;
              uStack_84 = uVar4 >> 2 ^ 0x80000000;
              local_88 = 0x43300000;
              puVar40[0x61] =
                   (UInt32)(float)((((double)CONCAT44d(0x43300000,uStack_84) - DOUBLE_0004c3a8) +
                                 DOUBLE_0004c3c0) * DOUBLE_0004c3b8);
              local_80 = 0x43300000;
              uStack_7c = M<UInt16>(iVar18 + 0x576) >> 1 ^ 0x80000000;
              puVar40[0x62] =
                   (UInt32)(float)((((double)CONCAT44d(0x43300000,uStack_7c) - dVar7) + dVar9) * dVar8)
              ;
              uVar37 = uVar37 & 0xffffff;
            }
            else {
              if (uVar17 != 0x14000000) {
                if (uVar17 == 0x12000000) {
                  piVar14 = M<SInt32 *>(self + 0x8c);
                  if ((piVar14[0x22f] == 0) ||
                     (VCALL(*piVar14, 0x5ec)(piVar14,M<UInt32>(self + 0x154)),
                     puVar40[0xd] == 0)) goto LAB_00039030;
                  iVar23 = M<SInt32>(self + 0xf8);
                  uVar17 = puVar40[2];
                  uVar21 = puVar40[3];
                  uVar31 = puVar40[6];
                  uVar11 = puVar40[7];
                  uVar19 = puVar40[8];
                  uVar33 = puVar40[9];
                  uVar35 = puVar40[10];
                  sVar1 = M<SInt16>(iVar23 + 0x98);
                  sVar2 = M<SInt16>(iVar23 + 0x96);
                  uVar36 = puVar40[0xb];
                  uVar28 = puVar40[0xc];
                  pVVar42 = M<UInt8 *>(self + puVar40[1] * 4 + 0x104);
                  uVar38 = (SInt32)M<SInt16>(iVar23 + 0x9a) - (SInt32)M<SInt16>(iVar23 + 0x94);
                  if ((M<SInt32>(pVVar42 + 4) != 0) ||
                     (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42))
                     , M<SInt32>(pVVar42 + 4) != 0)) {
                    GH_IOGetTime(pVVar42 + 0x2c);
                    iVar23 = M<SInt32>(pVVar42 + 0x34);
                    M<UInt32>(iVar23 + 0x38) = M<UInt32>(pVVar42 + 0x38);
                    M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar23;
                    M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0)
                    ;
                    M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                    M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                    M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
                  }
                  iVar23 = 0;
                  M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
                  if (M<SInt32>(pVVar42 + 4) != 0) {
                    iVar23 = M<SInt32>(pVVar42 + 4) +
                             M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4);
                  }
                  iVar12 = 0;
                  iVar45 = 4;
                  iVar18 = (((UInt32)((SInt32)sVar1 - (SInt32)sVar2) >> 2 & 0x3ffffffc) + 0xff & 0xffffff00)
                           * (uVar38 >> 4);
                  iVar23 = iVar23 + uVar33 * iVar18 * 8;
                  do {
                    M<SInt32>((SInt32)local_b4 + iVar12) = iVar23;
                    iVar23 = iVar23 + iVar18;
                    iVar12 = iVar12 + 4;
                    iVar45 = iVar45 + -1;
                  } while (iVar45 != 0);
                  iVar12 = 0;
                  iVar45 = 4;
                  do {
                    M<SInt32>((SInt32)local_a4 + iVar12) = iVar23;
                    iVar23 = iVar23 + iVar18;
                    iVar12 = iVar12 + 4;
                    iVar45 = iVar45 + -1;
                  } while (iVar45 != 0);
                  pVVar42 = M<UInt8 *>(self + puVar40[5] * 4 + 0x104);
                  if ((M<SInt32>(pVVar42 + 4) != 0) ||
                     (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42))
                     , M<SInt32>(pVVar42 + 4) != 0)) {
                    GH_IOGetTime(pVVar42 + 0x2c);
                    iVar23 = M<SInt32>(pVVar42 + 0x34);
                    M<UInt32>(iVar23 + 0x38) = M<UInt32>(pVVar42 + 0x38);
                    M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar23;
                    M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0)
                    ;
                    M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                    M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                    M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
                  }
                  uVar13 = 0;
                  M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
                  if (M<SInt32>(pVVar42 + 4) != 0) {
                    uVar13 = M<SInt32>(pVVar42 + 4) +
                             M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4);
                  }
                  iVar18 = M<SInt32>(self + 0xf8);
                  iVar23 = uVar33 * 0x78 + iVar18;
                  uVar34 = (UInt32)M<UInt16>(iVar18 + 0x8b8);
                  puVar26 = puVar40 + uVar31;
                  uVar32 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar36 = M<UInt32>(uVar36 * 0x78 + iVar18 + 0x560);
                  uVar30 = M<UInt32>(uVar35 * 0x78 + iVar18 + 0x560);
                  uVar29 = M<UInt32>(iVar23 + 0x560);
                  uVar33 = M<UInt8>(iVar23 + 0x590) & 1;
                  uVar31 = (UInt32)(M<UInt8>(iVar23 + 0x590) >> 1);
                  iVar12 = uVar38 * uVar32;
                  uVar39 = M<UInt32>(iVar18 + 0x8a8);
                  uVar41 = uVar33 << 2 | (uVar31 & 3) << 3;
                  puVar26[-0xe] = 0x832;
                  puVar26[-0xd] = uVar13;
                  puVar26[-0xc] = 0x833;
                  puVar26[-0xb] = uVar13;
                  puVar26[-10] = 0x1150;
                  puVar26[-9] = local_b4[0] & 0xffffffe0 | 2;
                  puVar26[-8] = 0x1151;
                  puVar26[-7] = local_b4[1] & 0xffffffe0 | 2;
                  puVar26[-6] = 0x1152;
                  puVar26[-5] = local_b4[2] & 0xffffffe0 | 2;
                  puVar26[-4] = 0x1153;
                  puVar26[-3] = local_b4[3] & 0xffffffe0 | 2;
                  puVar26[-2] = 0x1154;
                  uVar35 = uVar41 | uVar30 & 0xffffffe0;
                  puVar26[-1] = uVar35;
                  if ((uVar17 == 0) || (uVar28 != 0)) {
                    *puVar26 = 0x1155;
                    puVar26[1] = uVar35;
                    puVar26[2] = 0x1156;
                    puVar26[3] = uVar41 | uVar32 + uVar30 & 0xffffffe0;
                  }
                  else if (uVar21 == 0) {
                    *puVar26 = 0x1155;
                    puVar26[1] = uVar35;
                    puVar26[2] = 0x1156;
                    puVar26[3] = uVar41 | uVar29 + uVar32 & 0xffffffe0;
                  }
                  else {
                    *puVar26 = 0x1155;
                    puVar26[1] = uVar41 | uVar29 & 0xffffffe0;
                    puVar26[2] = 0x1156;
                    puVar26[3] = uVar41 | uVar32 + uVar30 & 0xffffffe0;
                  }
                  bVar43 = uVar21 == 0;
                  puVar26[4] = 0x1157;
                  uVar21 = uVar41 | uVar36 & 0xffffffe0;
                  puVar26[5] = uVar21;
                  puVar26[6] = 0x1158;
                  puVar26[7] = uVar21;
                  puVar26[8] = 0x1159;
                  puVar26[9] = uVar41 | uVar32 + uVar36 & 0xffffffe0;
                  puVar26[10] = 0x115a;
                  uVar21 = uVar41 | uVar39 & 0xffffffe0;
                  puVar26[0xb] = uVar21;
                  if (bVar43) {
                    puVar26[0xc] = 0x115b;
                    puVar26[0xd] = uVar21;
                    uVar21 = uVar39 + uVar34 & 0xffffffe0 | uVar41;
                  }
                  else {
                    puVar26[0xc] = 0x115b;
                    uVar21 = uVar41 | uVar39 + uVar34 & 0xffffffe0;
                    puVar26[0xd] = uVar21;
                  }
                  puVar26[0xe] = 0x115c;
                  puVar26[0xf] = uVar21;
                  uVar39 = uVar39 + uVar38 * uVar34;
                  puVar16 = puVar40 + uVar11;
                  uVar30 = iVar12 + uVar30;
                  uVar11 = uVar29 + iVar12;
                  puVar16[-0xe] = 0x832;
                  uVar13 = uVar13 + uVar19 * 4;
                  puVar16[-0xd] = uVar13;
                  puVar16[-0xc] = 0x833;
                  puVar16[-0xb] = uVar13;
                  puVar16[-10] = 0x1150;
                  puVar16[-9] = local_a4[0] & 0xffffffe0 | 2;
                  puVar16[-8] = 0x1151;
                  puVar16[-7] = local_a4[1] & 0xffffffe0 | 2;
                  puVar16[-6] = 0x1152;
                  puVar16[-5] = local_a4[2] & 0xffffffe0 | 2;
                  puVar16[-4] = 0x1153;
                  puVar16[-3] = local_a4[3] & 0xffffffe0 | 2;
                  puVar16[-2] = 0x1154;
                  uVar21 = uVar41 | uVar30 & 0xffffffe0;
                  puVar16[-1] = uVar21;
                  if ((uVar17 == 0) || (uVar28 != 0)) {
                    *puVar16 = 0x1155;
                    puVar16[1] = uVar21;
                    puVar16[2] = 0x1156;
                    puVar16[3] = uVar41 | uVar32 + uVar30 & 0xffffffe0;
                  }
                  else if (bVar43) {
                    *puVar16 = 0x1155;
                    puVar16[1] = uVar21;
                    puVar16[2] = 0x1156;
                    puVar16[3] = uVar41 | uVar32 + uVar11 & 0xffffffe0;
                  }
                  else {
                    *puVar16 = 0x1155;
                    puVar16[1] = uVar41 | uVar11 & 0xffffffe0;
                    puVar16[2] = 0x1156;
                    puVar16[3] = uVar41 | uVar32 + uVar30 & 0xffffffe0;
                  }
                  puVar16[4] = 0x1157;
                  uVar17 = uVar41 | iVar12 + uVar36 & 0xffffffe0;
                  puVar16[5] = uVar17;
                  puVar16[6] = 0x1158;
                  puVar16[7] = uVar17;
                  puVar16[8] = 0x1159;
                  puVar16[9] = uVar41 | uVar32 + iVar12 + uVar36 & 0xffffffe0;
                  puVar16[10] = 0x115a;
                  uVar17 = uVar41 | uVar39 & 0xffffffe0;
                  puVar16[0xb] = uVar17;
                  if (bVar43) {
                    puVar16[0xc] = 0x115b;
                    puVar16[0xd] = uVar17;
                    uVar41 = uVar34 + uVar39 & 0xffffffe0 | uVar41;
                  }
                  else {
                    puVar16[0xc] = 0x115b;
                    uVar41 = uVar41 | uVar34 + uVar39 & 0xffffffe0;
                    puVar16[0xd] = uVar41;
                  }
                  puVar16[0xe] = 0x115c;
                  puVar16[0xf] = uVar41;
                  puVar20 = puVar26 + 0x10;
                  if (puVar26[0x10] != 0) {
                    bVar44 = M<UInt8>(iVar23 + 0x591);
                    uVar17 = puVar26[0x10];
                    do {
                      *puVar20 = 0x80000000;
                      puVar20[1] = 0x80000000;
                      puVar26 = puVar20 + puVar20[1] + 2;
                      uVar21 = uVar29;
                      if (puVar20[puVar20[1] + 2] != 0) {
                        uVar21 = uVar29 + uVar32;
                      }
                      *puVar26 = uVar21 & 0xffffffe0;
                      puVar26[1] = (uVar31 & 3) << 0x11 | uVar33 << 0x10 | puVar26[1] & 0x3ffe |
                                   (bVar44 & 3) << 0x13 | 0x1200000;
                      puVar26 = puVar20 + uVar17 + 2;
                      puVar20 = puVar20 + uVar17 + 2;
                      uVar17 = *puVar26;
                    } while (*puVar26 != 0);
                  }
                  *puVar20 = 0x80000000;
                  puVar26 = puVar16 + 0x10;
                  if (puVar16[0x10] != 0) {
                    bVar44 = M<UInt8>(iVar23 + 0x591);
                    uVar17 = puVar16[0x10];
                    do {
                      *puVar26 = 0x80000000;
                      puVar26[1] = 0x80000000;
                      puVar16 = puVar26 + puVar26[1] + 2;
                      uVar21 = uVar11;
                      if (puVar26[puVar26[1] + 2] != 0) {
                        uVar21 = uVar32 + uVar11;
                      }
                      *puVar16 = uVar21 & 0xffffffe0;
                      puVar16[1] = (uVar31 & 3) << 0x11 | uVar33 << 0x10 | puVar16[1] & 0x3ffe |
                                   (bVar44 & 3) << 0x13 | 0x1a00000;
                      puVar16 = puVar26 + uVar17 + 2;
                      puVar26 = puVar26 + uVar17 + 2;
                      uVar17 = *puVar16;
                    } while (*puVar16 != 0);
                  }
                  *puVar26 = 0x80000000;
                  *puVar40 = 0xc00c1000;
                }
                goto LAB_00039028;
              }
              iVar25 = M<SInt32>(self + 0xf8);
              iVar23 = puVar40[2] * 0x78 + iVar25;
              iVar22 = puVar40[3] * 0x78 + iVar25;
              iVar12 = (SInt32)M<SInt16>(iVar25 + 0x9a) - (SInt32)M<SInt16>(iVar25 + 0x94);
              uVar17 = puVar40[4];
              uVar4 = M<UInt16>(iVar23 + 0x570);
              uVar11 = (UInt32)uVar4;
              uVar21 = M<UInt32>(iVar23 + 0x560);
              iVar18 = iVar12 * uVar11;
              iVar45 = uVar21 + ((UInt32)(iVar18 * 3) >> 1);
              if (puVar40[1] == 2) {
                if (uVar17 == 0) {
                  uVar3 = M<UInt16>(iVar22 + 0x570);
                  uVar19 = uVar21 + iVar18;
                  uVar33 = uVar11 + iVar18 + iVar45;
                  uVar36 = iVar12 * (UInt32)uVar3 + M<SInt32>(iVar22 + 0x560);
                  uVar38 = uVar36 + (uVar3 >> 1);
                  uVar17 = iVar12 * (UInt32)M<UInt16>(iVar25 + 0x7c8) + M<SInt32>(iVar25 + 0x7b8);
                  uVar28 = uVar19 + (uVar4 >> 1);
                  uVar35 = uVar19 + ((SInt32)(uVar11 * 3) >> 1);
                  uVar31 = uVar36 + ((SInt32)((UInt32)uVar3 * 3) >> 1);
                }
                else {
                  uVar3 = M<UInt16>(iVar22 + 0x570);
                  uVar28 = uVar21 + iVar18;
                  uVar38 = iVar12 * (UInt32)uVar3 + M<SInt32>(iVar22 + 0x560);
                  uVar17 = iVar12 * (UInt32)M<UInt16>(iVar25 + 0x7c8) + M<SInt32>(iVar25 + 0x7b8) +
                           (UInt32)(M<UInt16>(iVar25 + 0x7c8) >> 1);
                  uVar31 = uVar3 + uVar38;
                  uVar33 = (UInt32)(uVar4 >> 1) + iVar18 + iVar45;
                  uVar36 = uVar38 + (uVar3 >> 1);
                  uVar35 = uVar11 + uVar28;
                  uVar19 = uVar28 + (uVar4 >> 1);
                }
              }
              else if (puVar40[1] == 3) {
                if (uVar17 == 0) {
                  uVar3 = M<UInt16>(iVar22 + 0x570);
                  uVar17 = (UInt32)(iVar18 * 5) >> 2;
                  uVar19 = uVar21 + uVar17;
                  uVar36 = (iVar12 * (UInt32)uVar3 * 5 >> 2) + M<SInt32>(iVar22 + 0x560);
                  uVar33 = uVar11 + iVar45 + uVar17;
                  uVar35 = uVar19 + ((SInt32)(uVar11 * 3) >> 1);
                  uVar38 = uVar36 + (uVar3 >> 1);
                  uVar17 = (iVar12 * (UInt32)M<UInt16>(iVar25 + 0x7c8) * 5 >> 2) +
                           M<SInt32>(iVar25 + 0x7b8);
                  uVar31 = uVar36 + ((SInt32)((UInt32)uVar3 * 3) >> 1);
                  uVar28 = uVar19 + (uVar4 >> 1);
                }
                else {
                  uVar3 = M<UInt16>(iVar22 + 0x570);
                  uVar19 = (UInt32)(iVar18 * 5) >> 2;
                  uVar28 = uVar21 + uVar19;
                  uVar38 = (iVar12 * (UInt32)uVar3 * 5 >> 2) + M<SInt32>(iVar22 + 0x560);
                  uVar17 = (iVar12 * (UInt32)M<UInt16>(iVar25 + 0x7c8) * 5 >> 2) +
                           M<SInt32>(iVar25 + 0x7b8) + (UInt32)(M<UInt16>(iVar25 + 0x7c8) >> 1);
                  uVar31 = uVar3 + uVar38;
                  uVar33 = (UInt32)(uVar4 >> 1) + iVar45 + uVar19;
                  uVar36 = uVar38 + (uVar3 >> 1);
                  uVar35 = uVar11 + uVar28;
                  uVar19 = uVar28 + (uVar4 >> 1);
                }
              }
              else if (uVar17 == 0) {
                uVar36 = M<UInt32>(iVar22 + 0x560);
                uVar17 = M<UInt32>(iVar25 + 0x7b8);
                uVar28 = uVar21 + uVar11;
                uVar33 = iVar45 + uVar11 * 2;
                uVar35 = uVar21 + uVar11 * 3;
                uVar38 = uVar36 + M<UInt16>(iVar22 + 0x570);
                uVar31 = uVar36 + (UInt32)M<UInt16>(iVar22 + 0x570) * 3;
                uVar19 = uVar21;
              }
              else {
                uVar38 = M<UInt32>(iVar22 + 0x560);
                uVar33 = uVar11 + iVar45;
                uVar35 = uVar21 + uVar11 * 2;
                uVar36 = uVar38 + M<UInt16>(iVar22 + 0x570);
                uVar17 = (UInt32)M<UInt16>(iVar25 + 0x7c8) + M<SInt32>(iVar25 + 0x7b8);
                uVar31 = uVar38 + (UInt32)M<UInt16>(iVar22 + 0x570) * 2;
                uVar19 = uVar21 + uVar11;
                uVar28 = uVar21;
              }
              *puVar40 = 0x1150;
              uVar21 = (M<UInt8>(iVar23 + 0x590) & 1) << 2;
              uVar11 = (M<UInt8>(iVar23 + 0x590) & 6) << 2;
              puVar40[1] = uVar19 & 0xffffffe0 | uVar21 | uVar11;
              puVar40[2] = 0x1151;
              puVar40[3] = uVar11 | uVar21 | uVar28 & 0xffffffe0;
              puVar40[4] = 0x1152;
              puVar40[5] = uVar11 | uVar21 | uVar35 & 0xffffffe0;
              puVar40[6] = 0x1153;
              uVar21 = (M<UInt8>(iVar22 + 0x590) & 1) << 2;
              uVar11 = (M<UInt8>(iVar22 + 0x590) & 6) << 2;
              puVar40[7] = uVar36 & 0xffffffe0 | uVar21 | uVar11;
              puVar40[8] = 0x1154;
              puVar40[9] = uVar11 | uVar21 | uVar38 & 0xffffffe0;
              puVar40[10] = 0x1155;
              puVar40[0xb] = uVar11 | uVar21 | uVar31 & 0xffffffe0;
              puVar40[0xc] = 0x1156;
              uVar17 = uVar17 & 0xffffffe0;
              puVar40[0xd] = uVar17 | (M<UInt8>(iVar25 + 0x7e8) & 1) << 2 |
                             (M<UInt8>(iVar25 + 0x7e8) & 6) << 2;
              puVar40[0xe] = 0x1393;
              puVar40[0xf] = 10;
              puVar40[0x10] = 0x138a;
              puVar40[0x11] = uVar33 & 0xffffffe0;
              puVar40[0x12] = 0x138b;
              puVar40[0x13] = uVar17;
              puVar40[0x14] = 0x138c;
              puVar40[0x15] = uVar33 & 0xffffffe0;
              puVar40[0x16] = 0x138d;
              puVar40[0x17] = uVar17;
              uVar37 = uVar37 & 0xffffff;
            }
            goto LAB_0003903c;
          }
          if (uVar17 == 0x5000000) {
            uVar21 = (UInt32)M<UInt8>((SInt32)puVar40 + 0xf);
            iVar18 = M<SInt32>(self + 0xf8);
            iVar23 = puVar40[1] * 0x78 + iVar18;
            uVar17 = (SInt32)M<SInt16>(iVar18 + 0x9a) - (SInt32)M<SInt16>(iVar18 + 0x94);
            if (puVar40[2] == 0) {
              uVar11 = M<UInt32>(iVar23 + 0x560);
              uVar4 = M<UInt16>(iVar23 + 0x570);
            }
            else {
              uVar4 = M<UInt16>(iVar23 + 0x570);
              uVar11 = (uVar17 * uVar4 * 3 >> 1) + M<SInt32>(iVar23 + 0x560);
            }
            bVar44 = M<UInt8>(iVar23 + 0x590);
            uVar19 = 0x80000000;
            if (bVar44 < 2) {
              uVar19 = 0;
            }
            *puVar40 = 0x1393;
            puVar40[1] = 10;
            puVar40[2] = 0x5c8;
            puVar40[3] = 0x20000;
            puVar40[4] = 0xc0069a00;
            puVar40[5] = 0x52f036da;
            puVar40[6] = uVar19 | uVar11 >> 10 | (uVar4 & 0x3fc0) << 0x10 | (bVar44 & 1) << 0x1e;
            puVar40[7] = M<UInt32>(self + 0x158);
            puVar40[8] = CONCAT22(M<UInt16>(iVar23 + 0x576),M<UInt16>(iVar23 + 0x574));
            puVar40[9] = uVar21 | uVar21 << 0x18 | uVar21 << 0x10 |
                                  (UInt32)M<UInt8>((SInt32)puVar40 + 0xf) << 8;
            puVar40[10] = 0;
            uVar17 = uVar17 | (uVar4 & 0xfffc) << 0xe;
LAB_00037c4c:
            puVar40[0xb] = uVar17;
            puVar40[0xc] = 0xd0b;
            puVar40[0xd] = 5;
            puVar40[0xe] = 0x5c8;
            puVar40[0xf] = 0x10000;
            goto LAB_00039028;
          }
          if (0x5000000 < uVar17) {
            if ((uVar17 == 0x7000000) || (uVar17 == 0x8000000)) goto LAB_00039030;
            if (uVar17 != 0x6000000) goto LAB_00039028;
            uVar21 = (UInt32)M<UInt8>((SInt32)puVar40 + 0xf);
            iVar23 = M<SInt32>(self + 0xf8);
            iVar18 = puVar40[1] * 0x78 + iVar23;
            uVar17 = (SInt32)M<SInt16>(iVar23 + 0x9a) - (SInt32)M<SInt16>(iVar23 + 0x94);
            if (puVar40[2] == 0) {
              uVar4 = M<UInt16>(iVar18 + 0x570);
              uVar11 = uVar17 * uVar4 + M<SInt32>(iVar18 + 0x560);
            }
            else {
              uVar4 = M<UInt16>(iVar18 + 0x570);
              uVar11 = uVar17 * uVar4 + (uVar17 * uVar4 * 3 >> 1) + M<SInt32>(iVar18 + 0x560);
            }
            bVar44 = M<UInt8>(iVar18 + 0x590);
            uVar19 = 0x80000000;
            if (bVar44 < 2) {
              uVar19 = 0;
            }
            *puVar40 = 0x1393;
            puVar40[1] = 10;
            puVar40[2] = 0x5c8;
            puVar40[3] = 0x20000;
            puVar40[4] = 0xc0069a00;
            puVar40[5] = 0x52f036da;
            puVar40[6] = uVar19 | uVar11 >> 10 | (uVar4 & 0x3fc0) << 0x10 | (bVar44 & 1) << 0x1e;
            puVar40[7] = M<UInt32>(self + 0x158);
            puVar40[8] = CONCAT22(M<UInt16>(iVar18 + 0x576),M<UInt16>(iVar18 + 0x574));
            puVar40[9] = uVar21 | uVar21 << 0x18 | uVar21 << 0x10 |
                                  (UInt32)M<UInt8>((SInt32)puVar40 + 0xf) << 8;
            puVar40[10] = 0;
            uVar17 = (uVar4 & 0xfffc) << 0xe | uVar17 >> 1;
            goto LAB_00037c4c;
          }
          if (uVar17 == 0x2000000) {
            uVar37 = uVar37 & 0xffffff;
            local_68 = 3;
            goto LAB_0003903c;
          }
          if (uVar17 != 0x4000000) goto LAB_00039028;
          if (local_6c != 0) {
            iVar23 = local_6c * 4;
            local_6c = 0;
            uVar17 = local_70 & 0xfffffffc;
            M<SInt32>(M<SInt32>(self + 0x8c) + 0x708) =
                 iVar23 + M<SInt32>(M<SInt32>(self + 0x8c) + 0x708);
            iVar18 = local_70 + M<SInt32>(self + 0x94);
            local_70 = local_70 + iVar23;
            uVar15 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x8c)))->submit_buffer((UInt32 *)(uVar17 + M<SInt32>(self + 0xa4) + 0x20),iVar18 + 0x20,
                                uVar10);
            M<UInt32>(self + 0xa0) = uVar15;
          }
          goto LAB_00039020;
        }
        if (uVar17 == 0x1d000000) {
LAB_00037620:
          if ((puVar40[1] < M<UInt32>(M<SInt32>(self + 0x84) + 0x14)) &&
             (pVVar42 = *(UInt8 **)
                         (puVar40[1] * 4 + M<SInt32>(M<SInt32>(self + 0x84) + 0x10)),
             pVVar42 != (UInt8 *)0x0)) {
            iVar23 = (uVar17 + 0xe7000000 >> 0x18) * 4;
            if (M<UInt8 *>(self + iVar23 + 0x104) != (UInt8 *)0x0) {
              ((IOATIR500DVDContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + iVar23 + 0x104)));
              iVar18 = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(self + iVar23 + 0x104) + 0x14) + 0x10);
              if (iVar18 == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + 0x84)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + iVar23 + 0x104)));
              }
              M<UInt32>(self + iVar23 + 0x104) = 0;
            }
            ((IOATIR500DVDContext *)((UInt8 *)self))->add_texture_to_stream((VendorTextureBuffer *)((UInt8 *)pVVar42));
            uVar10 = local_6c;
            if (M<char>(M<SInt32>(pVVar42 + 0x14) + 0x14) != '\0') {
              if (local_6c != 0) {
                iVar18 = local_6c * 4;
                local_6c = 0;
                uVar17 = local_70 & 0xfffffffc;
                M<SInt32>(M<SInt32>(self + 0x8c) + 0x708) =
                     iVar18 + M<SInt32>(M<SInt32>(self + 0x8c) + 0x708);
                iVar12 = local_70 + M<SInt32>(self + 0x94);
                local_70 = local_70 + iVar18;
                uVar15 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x8c)))->submit_buffer((UInt32 *)(uVar17 + M<SInt32>(self + 0xa4) + 0x20),iVar12 + 0x20,
                                    uVar10);
                M<UInt32>(self + 0xa0) = uVar15;
              }
              if ((M<SInt32>(pVVar42 + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42)),
                 M<SInt32>(pVVar42 + 4) != 0)) {
                GH_IOGetTime(pVVar42 + 0x2c);
                M<UInt32>(M<SInt32>(pVVar42 + 0x34) + 0x38) = M<UInt32>(pVVar42 + 0x38);
                M<UInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = M<UInt32>(pVVar42 + 0x34);
                M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
                M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
              }
              M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
              if (M<SInt32>(self + 0x94) == 0) {
                ((IOATIR500DVDContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x90)));
              }
            }
            GH_OSAddAtomic(0xffff0001,M<SInt32>(pVVar42 + 0x14) + 0x10);
            if (M<SInt32>(pVVar42 + 0x48) != 0) {
              M<UInt32>(M<SInt32>(pVVar42 + 0x24) + 0x28) = M<UInt32>(pVVar42 + 0x28);
              M<UInt32>(M<SInt32>(pVVar42 + 0x28) + 0x24) = M<UInt32>(pVVar42 + 0x24);
              M<UInt32>(pVVar42 + 0x24) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x600);
              M<SInt32>(pVVar42 + 0x28) = M<SInt32>(self + 0x8c) + 0x5dc;
              M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x600) = pVVar42;
              M<UInt8 *>(M<SInt32>(pVVar42 + 0x24) + 0x28) = pVVar42;
            }
            *puVar40 = 0x80000000;
            puVar40[1] = 0x80000000;
            uVar37 = uVar37 & 0xffffff;
            M<UInt8 *>(self + iVar23 + 0x104) = pVVar42;
            goto LAB_0003903c;
          }
          goto LAB_00039030;
        }
        if (0x1d000000 < uVar17) {
          if (uVar17 != 0x21000000) {
            if (uVar17 < 0x21000001) {
              if (((uVar17 == 0x1f000000) || (uVar17 == 0x20000000)) || (uVar17 == 0x1e000000))
              goto LAB_00037620;
            }
            else if (((uVar17 == 0x23000000) || (uVar17 == 0x24000000)) || (uVar17 == 0x22000000))
            goto LAB_00037620;
            goto LAB_00039028;
          }
          goto LAB_00037620;
        }
        if (uVar17 == 0x19000000) goto LAB_00037620;
        if (uVar17 < 0x19000001) {
          if (uVar17 != 0x17000000) {
            if (uVar17 == 0x18000000) {
              pVVar42 = M<UInt8 *>(self + puVar40[1] * 4 + 0x104);
              if ((M<SInt32>(pVVar42 + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42)),
                 M<SInt32>(pVVar42 + 4) != 0)) {
                GH_IOGetTime(pVVar42 + 0x2c);
                iVar23 = M<SInt32>(pVVar42 + 0x34);
                M<UInt32>(iVar23 + 0x38) = M<UInt32>(pVVar42 + 0x38);
                M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar23;
                M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
                M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
              }
              uVar17 = 0;
              M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
              if (M<SInt32>(pVVar42 + 4) != 0) {
                uVar17 = (UInt32)(M<SInt32>(pVVar42 + 4) +
                               M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4))
                         >> 5;
              }
              pVVar42 = M<UInt8 *>(self + puVar40[2] * 4 + 0x104);
              if ((M<SInt32>(pVVar42 + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42)),
                 M<SInt32>(pVVar42 + 4) != 0)) {
                GH_IOGetTime(pVVar42 + 0x2c);
                iVar23 = M<SInt32>(pVVar42 + 0x34);
                M<UInt32>(iVar23 + 0x38) = M<UInt32>(pVVar42 + 0x38);
                M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar23;
                M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
                M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
              }
              iVar23 = 0;
              M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
              if (M<SInt32>(pVVar42 + 4) != 0) {
                iVar23 = M<SInt32>(pVVar42 + 4) +
                         M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4);
              }
              iVar18 = M<SInt32>(self + 0xf8);
              *puVar40 = 0x1150;
              puVar40[1] = uVar17 << 5;
              puVar40[2] = 0x1151;
              puVar40[3] = iVar23 + puVar40[3] * 0x80 & 0xffffffe0;
              puVar40[4] = 0x1393;
              puVar40[5] = 10;
              puVar40[6] = 0x138a;
              puVar40[7] = M<UInt32>(iVar18 + 0x830) & 0xffffffe0;
              puVar40[8] = 0x138e;
              if (M<UInt16>(iVar18 + 0x83e) == 0) {
                puVar40[9] = 0x1400000;
                uVar37 = uVar37 & 0xffffff;
              }
              else {
                puVar40[9] = (SInt32)((UInt32)M<UInt16>(iVar18 + 0x840) /
                                  (UInt32)M<UInt16>(iVar18 + 0x83e)) >> 1 & 0x3ffeU | 0x1400000;
                uVar37 = uVar37 & 0xffffff;
              }
            }
            else {
              if (uVar17 != 0x16000000) goto LAB_00039028;
              iVar12 = M<SInt32>(self + 0xf8);
              uVar21 = puVar40[1];
              uVar17 = puVar40[4];
              iVar18 = puVar40[2] * 0x78 + iVar12;
              iVar23 = iVar18;
              if (puVar40[5] != 1) {
                iVar23 = puVar40[3] * 0x78 + iVar12;
              }
              uVar4 = M<UInt16>(iVar18 + 0x570);
              uVar11 = (UInt32)uVar4;
              uVar19 = M<UInt32>(iVar18 + 0x560);
              iVar12 = (SInt32)M<SInt16>(iVar12 + 0x9a) - (SInt32)M<SInt16>(iVar12 + 0x94);
              iVar45 = iVar12 * uVar11;
              iVar22 = uVar19 + ((UInt32)(iVar45 * 3) >> 1);
              if (puVar40[5] != 1) {
                if (uVar21 == 2) {
                  uVar21 = (UInt32)(uVar4 >> 2);
                  if (uVar17 == 0) {
                    iVar25 = uVar19 + iVar45;
                    uVar33 = uVar11 + iVar45 + iVar22;
                    uVar19 = iVar25 + (UInt32)(uVar4 >> 1);
                    uVar17 = iVar25 + ((SInt32)(uVar11 * 3) >> 1);
                    uVar31 = iVar12 * (UInt32)M<UInt16>(iVar23 + 0x570) + M<SInt32>(iVar23 + 0x560);
                    uVar28 = M<UInt16>(iVar23 + 0x570) + uVar31;
                  }
                  else {
                    uVar3 = M<UInt16>(iVar23 + 0x570);
                    uVar19 = uVar19 + iVar45;
                    uVar33 = iVar45 + iVar22 + (UInt32)(uVar4 >> 1);
                    uVar17 = uVar11 + uVar19;
                    iVar12 = iVar12 * (UInt32)uVar3 + M<SInt32>(iVar23 + 0x560);
                    uVar31 = iVar12 + ((SInt32)((UInt32)uVar3 * 3) >> 1);
                    uVar28 = iVar12 + (UInt32)(uVar3 >> 1);
                  }
                }
                else if (uVar21 == 3) {
                  uVar21 = (UInt32)(uVar4 >> 2);
                  if (uVar17 == 0) {
                    uVar17 = (UInt32)(iVar45 * 5) >> 2;
                    iVar45 = uVar19 + uVar17;
                    uVar33 = uVar11 + iVar22 + uVar17;
                    uVar17 = iVar45 + ((SInt32)(uVar11 * 3) >> 1);
                    uVar19 = iVar45 + (UInt32)(uVar4 >> 1);
                    uVar31 = (iVar12 * (UInt32)M<UInt16>(iVar23 + 0x570) * 5 >> 2) +
                             M<SInt32>(iVar23 + 0x560);
                    uVar28 = M<UInt16>(iVar23 + 0x570) + uVar31;
                  }
                  else {
                    uVar3 = M<UInt16>(iVar23 + 0x570);
                    uVar17 = (UInt32)(iVar45 * 5) >> 2;
                    uVar19 = uVar19 + uVar17;
                    uVar33 = iVar22 + uVar17 + (UInt32)(uVar4 >> 1);
                    uVar17 = uVar11 + uVar19;
                    iVar12 = (iVar12 * (UInt32)uVar3 * 5 >> 2) + M<SInt32>(iVar23 + 0x560);
                    uVar31 = iVar12 + ((SInt32)((UInt32)uVar3 * 3) >> 1);
                    uVar28 = iVar12 + (UInt32)(uVar3 >> 1);
                  }
                }
                else {
                  uVar21 = uVar4 >> 1 & 0x7ffe;
                  if (uVar17 == 0) {
                    uVar31 = M<UInt32>(iVar23 + 0x560);
                    uVar33 = iVar22 + uVar11 * 2;
                    uVar17 = uVar19 + uVar11 * 3;
                    uVar19 = uVar19 + uVar11;
                    uVar28 = uVar31 + (UInt32)M<UInt16>(iVar23 + 0x570) * 2;
                  }
                  else {
                    uVar33 = uVar11 + iVar22;
                    uVar17 = uVar19 + uVar11 * 2;
                    uVar28 = M<SInt32>(iVar23 + 0x560) + (UInt32)M<UInt16>(iVar23 + 0x570);
                    uVar31 = M<SInt32>(iVar23 + 0x560) + (UInt32)M<UInt16>(iVar23 + 0x570) * 3;
                  }
                }
              }
              else if (uVar21 == 2) {
                uVar21 = (UInt32)(uVar4 >> 2);
                if (uVar17 == 0) {
                  uVar17 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar33 = iVar45 + iVar22 + (UInt32)(uVar4 >> 1);
                  uVar19 = iVar12 * uVar17 + M<SInt32>(iVar23 + 0x560);
                  uVar28 = uVar19 + (M<UInt16>(iVar23 + 0x570) >> 1);
                  uVar31 = uVar19 + ((SInt32)(uVar17 * 3) >> 1);
                  uVar17 = uVar17 + uVar19;
                }
                else {
                  uVar28 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar33 = uVar11 + iVar45 + iVar22;
                  uVar31 = iVar12 * uVar28 + M<SInt32>(iVar23 + 0x560);
                  uVar19 = uVar31 + (M<UInt16>(iVar23 + 0x570) >> 1);
                  uVar17 = uVar31 + ((SInt32)(uVar28 * 3) >> 1);
                  uVar28 = uVar28 + uVar31;
                }
              }
              else if (uVar21 == 3) {
                uVar21 = (UInt32)(uVar4 >> 2);
                if (uVar17 == 0) {
                  uVar17 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar33 = iVar22 + ((UInt32)(iVar45 * 5) >> 2) + (UInt32)(uVar4 >> 1);
                  uVar19 = (iVar12 * uVar17 * 5 >> 2) + M<SInt32>(iVar23 + 0x560);
                  uVar28 = uVar19 + (M<UInt16>(iVar23 + 0x570) >> 1);
                  uVar31 = uVar19 + ((SInt32)(uVar17 * 3) >> 1);
                  uVar17 = uVar17 + uVar19;
                }
                else {
                  uVar28 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar33 = uVar11 + iVar22 + ((UInt32)(iVar45 * 5) >> 2);
                  uVar31 = (iVar12 * uVar28 * 5 >> 2) + M<SInt32>(iVar23 + 0x560);
                  uVar19 = uVar31 + (M<UInt16>(iVar23 + 0x570) >> 1);
                  uVar17 = uVar31 + ((SInt32)(uVar28 * 3) >> 1);
                  uVar28 = uVar28 + uVar31;
                }
              }
              else {
                uVar21 = uVar4 >> 1 & 0x7ffe;
                if (uVar17 == 0) {
                  uVar31 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar19 = M<UInt32>(iVar23 + 0x560);
                  uVar33 = uVar11 + iVar22;
                  uVar28 = uVar19 + uVar31;
                  uVar17 = uVar19 + uVar31 * 2;
                  uVar31 = uVar19 + uVar31 * 3;
                }
                else {
                  uVar17 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar31 = M<UInt32>(iVar23 + 0x560);
                  uVar33 = iVar22 + uVar11 * 2;
                  uVar19 = uVar31 + uVar17;
                  uVar28 = uVar31 + uVar17 * 2;
                  uVar17 = uVar31 + uVar17 * 3;
                }
              }
              *puVar40 = 0x1150;
              uVar38 = M<UInt8>(iVar18 + 0x590) & 1;
              uVar11 = (UInt32)(M<UInt8>(iVar18 + 0x590) >> 1);
              uVar13 = (uVar11 & 3) << 3;
              uVar35 = uVar38 << 2;
              puVar40[1] = uVar19 & 0xffffffe0 | uVar35 | uVar13;
              puVar40[2] = 0x1151;
              uVar19 = (M<UInt8>(iVar23 + 0x590) & 1) << 2;
              uVar36 = (M<UInt8>(iVar23 + 0x590) & 6) << 2;
              puVar40[3] = uVar28 & 0xffffffe0 | uVar19 | uVar36;
              puVar40[4] = 0x1152;
              puVar40[5] = uVar13 | uVar35 | uVar17 & 0xffffffe0;
              puVar40[6] = 0x1153;
              puVar40[7] = uVar36 | uVar19 | uVar31 & 0xffffffe0;
              puVar40[8] = 0x1393;
              puVar40[9] = 10;
              puVar40[10] = 0x138a;
              puVar40[0xb] = uVar33 & 0xffffffe0;
              puVar40[0xc] = 0x138e;
              puVar40[0xd] = uVar21 & 0x3ffe | uVar38 << 0x10 | (uVar11 & 3) << 0x11 |
                             (M<UInt8>(iVar18 + 0x591) & 3) << 0x13 | 0xc00000;
              uVar37 = uVar37 & 0xffffff;
            }
            goto LAB_0003903c;
          }
          iVar12 = M<SInt32>(self + 0xf8);
          uVar17 = puVar40[1];
          uVar21 = puVar40[4];
          iVar18 = puVar40[2] * 0x78 + iVar12;
          iVar23 = iVar18;
          if (puVar40[5] != 1) {
            iVar23 = puVar40[3] * 0x78 + iVar12;
          }
          uVar4 = M<UInt16>(iVar18 + 0x570);
          uVar11 = (UInt32)uVar4;
          uVar19 = M<UInt32>(iVar18 + 0x560);
          iVar45 = (SInt32)M<SInt16>(iVar12 + 0x9a) - (SInt32)M<SInt16>(iVar12 + 0x94);
          iVar22 = iVar45 * uVar11;
          iVar12 = uVar19 + ((UInt32)(iVar22 * 3) >> 1);
          if (puVar40[5] != 1) {
            if (uVar17 == 2) {
              uVar17 = (UInt32)(uVar4 >> 2);
              if (uVar21 == 0) {
                iVar23 = uVar19 + iVar22;
                uVar21 = uVar11 + iVar22 + iVar12;
                uVar19 = iVar23 + (UInt32)(uVar4 >> 1);
                uVar28 = iVar23 + ((SInt32)(uVar11 * 3) >> 1);
              }
              else {
                uVar19 = uVar19 + iVar22;
                uVar28 = uVar11 + uVar19;
                uVar21 = iVar22 + iVar12 + (UInt32)(uVar4 >> 1);
              }
            }
            else if (uVar17 == 3) {
              uVar17 = (UInt32)(uVar4 >> 2);
              if (uVar21 == 0) {
                uVar21 = (UInt32)(iVar22 * 5) >> 2;
                iVar23 = uVar19 + uVar21;
                uVar21 = uVar11 + iVar12 + uVar21;
                uVar28 = iVar23 + ((SInt32)(uVar11 * 3) >> 1);
                uVar19 = iVar23 + (UInt32)(uVar4 >> 1);
              }
              else {
                uVar21 = (UInt32)(iVar22 * 5) >> 2;
                uVar19 = uVar19 + uVar21;
                uVar21 = iVar12 + uVar21 + (UInt32)(uVar4 >> 1);
                uVar28 = uVar11 + uVar19;
              }
            }
            else {
              uVar17 = uVar4 >> 1 & 0x7ffe;
              if (uVar21 == 0) {
                uVar21 = iVar12 + uVar11 * 2;
                uVar28 = uVar19 + uVar11 * 3;
                uVar19 = uVar19 + uVar11;
              }
              else {
                uVar21 = uVar11 + iVar12;
                uVar28 = uVar19 + uVar11 * 2;
              }
            }
          }
          else if (uVar17 == 2) {
            uVar17 = (UInt32)(uVar4 >> 2);
            if (uVar21 == 0) {
              uVar21 = iVar22 + iVar12 + (UInt32)(uVar4 >> 1);
              uVar19 = iVar45 * (UInt32)M<UInt16>(iVar23 + 0x570) + M<SInt32>(iVar23 + 0x560);
              uVar28 = M<UInt16>(iVar23 + 0x570) + uVar19;
            }
            else {
              uVar4 = M<UInt16>(iVar23 + 0x570);
              uVar21 = uVar11 + iVar22 + iVar12;
              iVar23 = iVar45 * (UInt32)uVar4 + M<SInt32>(iVar23 + 0x560);
              uVar28 = iVar23 + ((SInt32)((UInt32)uVar4 * 3) >> 1);
              uVar19 = iVar23 + (UInt32)(uVar4 >> 1);
            }
          }
          else if (uVar17 == 3) {
            uVar17 = (UInt32)(uVar4 >> 2);
            if (uVar21 == 0) {
              uVar21 = iVar12 + ((UInt32)(iVar22 * 5) >> 2) + (UInt32)(uVar4 >> 1);
              uVar19 = (iVar45 * (UInt32)M<UInt16>(iVar23 + 0x570) * 5 >> 2) +
                       M<SInt32>(iVar23 + 0x560);
              uVar28 = M<UInt16>(iVar23 + 0x570) + uVar19;
            }
            else {
              uVar4 = M<UInt16>(iVar23 + 0x570);
              uVar21 = uVar11 + iVar12 + ((UInt32)(iVar22 * 5) >> 2);
              iVar23 = (iVar45 * (UInt32)uVar4 * 5 >> 2) + M<SInt32>(iVar23 + 0x560);
              uVar28 = iVar23 + ((SInt32)((UInt32)uVar4 * 3) >> 1);
              uVar19 = iVar23 + (UInt32)(uVar4 >> 1);
            }
          }
          else {
            uVar17 = uVar4 >> 1 & 0x7ffe;
            if (uVar21 == 0) {
              uVar19 = M<UInt32>(iVar23 + 0x560);
              uVar21 = uVar11 + iVar12;
              uVar28 = uVar19 + (UInt32)M<UInt16>(iVar23 + 0x570) * 2;
            }
            else {
              uVar21 = iVar12 + uVar11 * 2;
              uVar19 = M<SInt32>(iVar23 + 0x560) + (UInt32)M<UInt16>(iVar23 + 0x570);
              uVar28 = M<SInt32>(iVar23 + 0x560) + (UInt32)M<UInt16>(iVar23 + 0x570) * 3;
            }
          }
          *puVar40 = 0x1150;
          uVar33 = M<UInt8>(iVar18 + 0x590) & 1;
          uVar11 = (UInt32)(M<UInt8>(iVar18 + 0x590) >> 1);
          uVar35 = (uVar11 & 3) << 3;
          uVar31 = uVar33 << 2;
          puVar40[1] = uVar19 & 0xffffffe0 | uVar31 | uVar35;
          puVar40[2] = 0x1151;
          puVar40[3] = uVar35 | uVar31 | uVar28 & 0xffffffe0;
          puVar40[4] = 0x1393;
          puVar40[5] = 10;
          puVar40[6] = 0x138a;
          puVar40[7] = uVar21 & 0xffffffe0;
          puVar40[8] = 0x138e;
          bVar44 = M<UInt8>(iVar18 + 0x591);
          uVar17 = uVar17 & 0x3ffe | uVar33 << 0x10 | (uVar11 & 3) << 0x11;
LAB_00038870:
          puVar40[9] = uVar17 | (bVar44 & 3) << 0x13 | 0xc00000;
        }
        else if (((uVar17 == 0x1b000000) || (uVar17 == 0x1c000000)) || (uVar17 == 0x1a000000))
        goto LAB_00037620;
        goto LAB_00039028;
      }
      iVar23 = M<SInt32>(self + 0xf8);
      uVar21 = puVar40[1];
      uVar17 = M<UInt32>(iVar23 + 0x7b8);
      if (uVar17 != 0) {
        bVar44 = M<UInt8>(iVar23 + 0x7e8);
        uVar4 = M<UInt16>(iVar23 + 0x7c8);
        uVar11 = 0x80000000;
        if (bVar44 < 2) {
          uVar11 = 0;
        }
        *puVar40 = 0x1393;
        puVar40[1] = 10;
        puVar40[2] = 0x5c8;
        puVar40[3] = 0x20000;
        puVar40[4] = 0xc0069a00;
        puVar40[5] = 0x52f036da;
        puVar40[6] = uVar11 | uVar17 >> 10 | (uVar4 & 0x3fc0) << 0x10 | (bVar44 & 1) << 0x1e;
        puVar40[7] = M<UInt32>(self + 0x158);
        uVar3 = M<UInt16>(iVar23 + 0x7ce);
        puVar40[8] = CONCAT22(uVar3,M<UInt16>(iVar23 + 0x7cc));
        puVar40[9] = uVar21;
        puVar40[10] = 0;
        puVar40[0xb] = (UInt32)uVar3 | (uVar4 & 0xfffc) << 0xe;
LAB_00038f80:
        puVar40[0xc] = 0xd0b;
        puVar40[0xd] = 5;
        puVar40[0xe] = 0x5c8;
        puVar40[0xf] = 0x10000;
        uVar37 = uVar37 & 0xffffff;
        goto LAB_0003903c;
      }
LAB_00039030:
      uVar37 = 0;
      local_6c = 0;
    }
    else {
      if (uVar17 != 0x35000000) {
        if (0x35000000 < uVar17) {
          if (uVar17 == 0x3d000000) {
            iVar12 = M<SInt32>(self + 0xf8);
            uVar38 = puVar40[3];
            uVar33 = puVar40[4];
            iVar23 = puVar40[1] * 0x78 + iVar12;
            iVar18 = puVar40[2] * 0x78 + iVar12;
            local_74 = puVar40[6];
            iVar22 = (SInt32)M<SInt16>(iVar12 + 0x9a) - (SInt32)M<SInt16>(iVar12 + 0x94);
            uVar4 = M<UInt16>(iVar23 + 0x570);
            uVar28 = (UInt32)uVar4;
            uVar31 = M<UInt32>(iVar23 + 0x560);
            iVar45 = iVar22 * uVar28;
            uVar35 = uVar31 + ((UInt32)(iVar45 * 3) >> 1);
            *puVar40 = 0x80000000;
            puVar40[1] = 0x80000000;
            puVar40[2] = 0x80000000;
            puVar40[3] = 0x80000000;
            puVar40[4] = 0x80000000;
            puVar40[5] = 0x80000000;
            puVar40[6] = 0x80000000;
            uVar36 = (UInt32)M<UInt16>(iVar12 + 0x7c8);
            puVar26 = puVar40 + puVar40[5];
            uVar17 = (UInt32)(M<UInt16>(iVar12 + 0x7c8) >> 1);
            local_78 = uVar17 & 0x7ffe;
            uVar21 = uVar35;
            uVar11 = uVar31;
            uVar19 = uVar35;
            if (uVar33 != 1) {
              if (uVar38 == 0) {
                uVar32 = M<UInt32>(iVar12 + 0x7b8);
                uVar34 = M<UInt32>(iVar18 + 0x560);
                uVar19 = uVar28 + uVar35;
                uVar13 = uVar31 + uVar28;
                uVar39 = (UInt32)M<UInt16>(iVar18 + 0x570);
                uVar29 = uVar32 + uVar36;
                uVar41 = uVar32;
                uVar30 = uVar34;
              }
              else {
                uVar39 = (UInt32)M<UInt16>(iVar18 + 0x570);
                uVar32 = M<UInt32>(iVar12 + 0x7b8);
                uVar34 = M<UInt32>(iVar18 + 0x560);
                uVar13 = uVar31;
                uVar41 = uVar32 + uVar36;
                uVar29 = uVar32;
                uVar21 = uVar28 + uVar35;
                uVar11 = uVar31 + uVar28;
                uVar30 = M<UInt16>(iVar18 + 0x570) + uVar34;
              }
            }
            else if (uVar38 == 0) {
              uVar39 = (UInt32)M<UInt16>(iVar18 + 0x570);
              uVar34 = M<UInt32>(iVar18 + 0x560);
              uVar32 = M<UInt32>(iVar12 + 0x7b8);
              uVar13 = uVar34;
              uVar41 = uVar32 + uVar36;
              uVar29 = uVar32;
              uVar21 = uVar28 + uVar35;
              uVar11 = uVar31 + uVar28;
              uVar30 = uVar34 + M<UInt16>(iVar18 + 0x570);
            }
            else {
              uVar39 = (UInt32)M<UInt16>(iVar18 + 0x570);
              uVar34 = M<UInt32>(iVar18 + 0x560);
              uVar32 = M<UInt32>(iVar12 + 0x7b8);
              uVar13 = uVar34 + M<UInt16>(iVar18 + 0x570);
              uVar41 = uVar32;
              uVar29 = uVar32 + uVar36;
              uVar30 = uVar34;
              uVar19 = uVar28 + uVar35;
            }
            *puVar26 = 0x1150;
            uVar24 = M<UInt8>(iVar23 + 0x590) & 1;
            uVar5 = (UInt32)(M<UInt8>(iVar23 + 0x590) >> 1);
            uVar27 = (uVar5 & 3) << 3;
            uVar6 = uVar24 << 2;
            puVar26[1] = uVar41 & 0xffffffe0 | uVar6 | uVar27;
            puVar26[2] = 0x1151;
            puVar26[3] = uVar27 | uVar6 | uVar29 & 0xffffffe0;
            puVar26[4] = 0x1152;
            puVar26[5] = uVar27 | uVar6 | uVar13 & 0xffffffe0;
            puVar26[6] = 0x1153;
            uVar13 = (M<UInt8>(iVar18 + 0x590) & 1) << 2;
            uVar29 = (M<UInt8>(iVar18 + 0x590) & 6) << 2;
            puVar26[7] = uVar30 & 0xffffffe0 | uVar13 | uVar29;
            puVar26[8] = 0x1154;
            puVar26[9] = uVar29 | uVar13 | uVar11 & 0xffffffe0;
            puVar26[10] = 0x1393;
            puVar26[0xb] = 10;
            puVar26[0xc] = 0x138e;
            uVar11 = uVar4 >> 1 & 0x3ffe | uVar24 << 0x10 | (uVar5 & 3) << 0x11 |
                     (M<UInt8>(iVar23 + 0x591) & 3) << 0x13 | 0xc00000;
            puVar26[0xd] = uVar11;
            puVar26[0xe] = 0x138a;
            puVar26[0xf] = uVar21 & 0xffffffe0;
            puVar26[0x10] = 0x138f;
            puVar26[0x11] = uVar11;
            puVar26[0x12] = 0x138b;
            puVar26[0x13] = uVar19 & 0xffffffe0;
            puVar26[0x14] = 0x1390;
            uVar17 = uVar17 & 0x3ffe | (M<UInt8>(iVar12 + 0x7e8) & 1) << 0x10 |
                     (M<UInt8>(iVar12 + 0x7e8) & 6) << 0x10 |
                     (M<UInt8>(iVar12 + 0x7e9) & 3) << 0x13 | 0xc00000;
            puVar26[0x15] = uVar17;
            puVar26[0x16] = 0x138c;
            puVar26[0x17] = uVar41 & 0xffffffe0;
            puVar26 = puVar40 + local_74;
            if (uVar33 != 1) {
              if (uVar38 == 0) {
                uVar19 = iVar45 + uVar35;
                uVar35 = uVar28 + uVar19;
                uVar21 = uVar36 * iVar22 + uVar32;
                uVar31 = uVar31 + iVar45;
                uVar34 = iVar22 * uVar39 + uVar34;
                uVar32 = uVar36 + uVar21;
                uVar33 = uVar28 + uVar31;
              }
              else {
                uVar35 = iVar45 + uVar35;
                uVar33 = uVar31 + iVar45;
                uVar32 = uVar36 * iVar22 + uVar32;
                uVar19 = uVar28 + uVar35;
                uVar31 = uVar28 + uVar33;
                uVar21 = uVar36 + uVar32;
                uVar34 = uVar39 + iVar22 * uVar39 + uVar34;
              }
            }
            else if (uVar38 == 0) {
              uVar35 = iVar45 + uVar35;
              uVar19 = uVar28 + uVar35;
              uVar32 = uVar36 * iVar22 + uVar32;
              uVar33 = iVar22 * uVar39 + uVar34;
              uVar21 = uVar36 + uVar32;
              uVar31 = uVar28 + uVar31 + iVar45;
              uVar34 = uVar39 + uVar33;
            }
            else {
              uVar19 = iVar45 + uVar35;
              uVar35 = uVar28 + uVar19;
              uVar21 = uVar36 * iVar22 + uVar32;
              uVar31 = uVar31 + iVar45;
              uVar34 = iVar22 * uVar39 + uVar34;
              uVar32 = uVar36 + uVar21;
              uVar33 = uVar39 + uVar34;
            }
            *puVar26 = 0x1150;
            puVar26[1] = uVar27 | uVar6 | uVar21 & 0xffffffe0;
            puVar26[2] = 0x1151;
            puVar26[3] = uVar27 | uVar6 | uVar32 & 0xffffffe0;
            puVar26[4] = 0x1152;
            puVar26[5] = uVar27 | uVar6 | uVar33 & 0xffffffe0;
            puVar26[6] = 0x1153;
            puVar26[7] = uVar29 | uVar13 | uVar34 & 0xffffffe0;
            puVar26[8] = 0x1154;
            puVar26[9] = uVar29 | uVar13 | uVar31 & 0xffffffe0;
            puVar26[10] = 0x1393;
            puVar26[0xb] = 10;
            puVar26[0xc] = 0x138e;
            puVar26[0xd] = uVar11;
            puVar26[0xe] = 0x138a;
            puVar26[0xf] = uVar19 & 0xffffffe0;
            puVar26[0x10] = 0x138f;
            puVar26[0x11] = uVar11;
            puVar26[0x12] = 0x138b;
            puVar26[0x13] = uVar35 & 0xffffffe0;
            puVar26[0x14] = 0x1390;
            puVar26[0x15] = uVar17;
            puVar26[0x16] = 0x138c;
            puVar26[0x17] = uVar21 & 0xffffffe0;
            uVar37 = uVar37 & 0xffffff;
            goto LAB_0003903c;
          }
          if (uVar17 < 0x3d000001) {
            if (uVar17 != 0x39000000) {
              if (uVar17 < 0x39000001) {
                if (((uVar17 == 0x37000000) || (uVar17 == 0x38000000)) || (uVar17 == 0x36000000))
                goto LAB_00037880;
              }
              else if (((uVar17 == 0x3b000000) || (uVar17 == 0x3c000000)) || (uVar17 == 0x3a000000))
              goto LAB_00037880;
              goto LAB_00039028;
            }
            goto LAB_00037880;
          }
          if (uVar17 == 0x43000000) {
            uVar17 = puVar40[4];
            iVar23 = M<SInt32>(self + 0xf8);
            iVar12 = puVar40[1] * 0x78 + iVar23;
            pVVar42 = M<UInt8 *>(self + puVar40[2] * 4 + 0x104);
            iVar18 = (SInt32)M<SInt16>(iVar23 + 0x9a) - (SInt32)M<SInt16>(iVar23 + 0x94);
            bVar43 = puVar40[3] != 0;
            if ((uVar17 & 2) == 0) {
              if (bVar43) {
                uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
                uVar11 = (iVar18 * (UInt32)M<UInt16>(iVar12 + 0x570) * 3 >> 1) +
                         M<SInt32>(iVar12 + 0x560);
              }
              else {
                uVar11 = M<UInt32>(iVar12 + 0x560);
                uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
              }
            }
            else {
              uVar11 = M<UInt32>(iVar23 + 0x998);
              uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
            }
joined_r0x000381c4:
            if ((uVar17 & 4) == 0) {
              if (bVar43) {
                uVar17 = iVar18 * uVar21 + (iVar18 * uVar21 * 3 >> 1) + M<SInt32>(iVar12 + 0x560);
              }
              else {
                uVar17 = iVar18 * uVar21 + M<SInt32>(iVar12 + 0x560);
              }
            }
            else {
              uVar17 = iVar18 * uVar21 + M<SInt32>(iVar23 + 0x998);
            }
            if ((M<SInt32>(pVVar42 + 4) != 0) ||
               (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42)),
               M<SInt32>(pVVar42 + 4) != 0)) {
              GH_IOGetTime(pVVar42 + 0x2c);
              iVar23 = M<SInt32>(pVVar42 + 0x34);
              M<UInt32>(iVar23 + 0x38) = M<UInt32>(pVVar42 + 0x38);
              M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar23;
              M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
              M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
              M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
              M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
            }
            uVar21 = 0;
            M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
            if (M<SInt32>(pVVar42 + 4) != 0) {
              uVar21 = (UInt32)(M<SInt32>(pVVar42 + 4) +
                             M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4)) >>
                       5;
            }
            *puVar40 = 0x1150;
            uVar19 = (M<UInt8>(iVar12 + 0x590) & 1) << 2;
            uVar28 = (M<UInt8>(iVar12 + 0x590) & 6) << 2;
            puVar40[1] = uVar11 & 0xffffffe0 | uVar19 | uVar28;
            puVar40[2] = 0x1151;
            puVar40[3] = uVar28 | uVar19 | uVar17 & 0xffffffe0;
            puVar40[4] = 0x1393;
            puVar40[5] = 10;
            puVar40[6] = 0x138a;
            puVar40[7] = uVar21 << 5;
            uVar37 = uVar37 & 0xffffff;
          }
          else if (uVar17 < 0x43000001) {
            if (uVar17 == 0x3f000000) {
              iVar18 = M<SInt32>(self + 0xf8);
              iVar23 = puVar40[1] * 0x78 + iVar18;
              if (puVar40[2] == 0) {
                uVar17 = M<UInt32>(iVar23 + 0x560);
                uVar4 = M<UInt16>(iVar23 + 0x570);
              }
              else {
                uVar4 = M<UInt16>(iVar23 + 0x570);
                uVar17 = (((SInt32)M<SInt16>(iVar18 + 0x9a) - (SInt32)M<SInt16>(iVar18 + 0x94)) *
                          (UInt32)uVar4 * 3 >> 1) + M<SInt32>(iVar23 + 0x560);
              }
              *puVar40 = 0x1150;
              puVar40[1] = uVar17 & 0xffffffe0 | (M<UInt8>(iVar23 + 0x590) & 1) << 2 |
                           (M<UInt8>(iVar23 + 0x590) & 6) << 2;
              puVar40[2] = 0x1393;
              puVar40[3] = 10;
              puVar40[4] = 0x138a;
              puVar40[5] = M<UInt32>(iVar18 + 0x998) & 0xffffffe0;
              puVar40[6] = 0x138e;
              puVar40[7] = uVar4 >> 2 & 0x3ffe | (M<UInt8>(iVar18 + 0x9c9) & 3) << 0x13 | 0xc00000;
              uVar37 = uVar37 & 0xffffff;
            }
            else if (uVar17 == 0x42000000) {
              iVar18 = M<SInt32>(self + 0xf8);
              iVar23 = puVar40[1] * 0x78 + iVar18;
              iVar12 = (SInt32)M<SInt16>(iVar18 + 0x9a) - (SInt32)M<SInt16>(iVar18 + 0x94);
              if (puVar40[2] == 0) {
                uVar4 = M<UInt16>(iVar23 + 0x570);
                uVar17 = iVar12 * (UInt32)uVar4 + M<SInt32>(iVar23 + 0x560);
              }
              else {
                uVar4 = M<UInt16>(iVar23 + 0x570);
                uVar17 = iVar12 * (UInt32)uVar4 +
                         (iVar12 * (UInt32)uVar4 * 3 >> 1) + M<SInt32>(iVar23 + 0x560);
              }
              *puVar40 = 0x1150;
              uVar17 = uVar17 & 0xffffffe0 | (M<UInt8>(iVar23 + 0x590) & 1) << 2 |
                       (M<UInt8>(iVar23 + 0x590) & 6) << 2;
              puVar40[1] = uVar17;
              puVar40[2] = 0x1151;
              puVar40[3] = uVar17;
              puVar40[4] = 0x1393;
              puVar40[5] = 10;
              puVar40[6] = 0x138a;
              puVar40[7] = iVar12 * (UInt32)uVar4 + M<SInt32>(iVar18 + 0x998) & 0xffffffe0;
              puVar40[8] = 0x138e;
              puVar40[9] = uVar4 >> 2 & 0x3ffe | (M<UInt8>(iVar18 + 0x9c9) & 3) << 0x13 | 0xc00000;
              uVar37 = uVar37 & 0xffffff;
            }
            else {
              if (uVar17 != 0x3e000000) goto LAB_00039028;
              iVar23 = M<SInt32>(self + 0xf8);
              uVar17 = puVar40[3];
              sVar1 = M<SInt16>(iVar23 + 0x94);
              sVar2 = M<SInt16>(iVar23 + 0x9a);
              pVVar42 = M<UInt8 *>(self + puVar40[2] * 4 + 0x104);
              iVar23 = puVar40[1] * 0x78 + iVar23;
              if ((M<SInt32>(pVVar42 + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar42)),
                 M<SInt32>(pVVar42 + 4) != 0)) {
                GH_IOGetTime(pVVar42 + 0x2c);
                iVar18 = M<SInt32>(pVVar42 + 0x34);
                M<UInt32>(iVar18 + 0x38) = M<UInt32>(pVVar42 + 0x38);
                M<SInt32>(M<SInt32>(pVVar42 + 0x38) + 0x34) = iVar18;
                M<UInt32>(pVVar42 + 0x34) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
                M<SInt32>(pVVar42 + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + 0x8c) + 0x6d0) = pVVar42;
                M<UInt8 *>(M<SInt32>(pVVar42 + 0x34) + 0x38) = pVVar42;
              }
              uVar21 = 0;
              M<UInt8>(M<SInt32>(pVVar42 + 0x14) + 0x14) = 0;
              if (M<SInt32>(pVVar42 + 4) != 0) {
                uVar21 = (UInt32)(M<SInt32>(pVVar42 + 4) +
                               M<SInt32>(pVVar42 + 0x50) + M<SInt32>(M<SInt32>(self + 0x8c) + 0x8a4))
                         >> 5;
              }
              uVar28 = M<UInt32>(iVar23 + 0x560);
              uVar33 = ((SInt32)sVar2 - (SInt32)sVar1) * (UInt32)M<UInt16>(iVar23 + 0x570);
              uVar31 = uVar28 + uVar33;
              *puVar40 = 0x1150;
              uVar11 = (M<UInt8>(iVar23 + 0x590) & 1) << 2;
              uVar19 = (M<UInt8>(iVar23 + 0x590) & 6) << 2;
              puVar40[1] = uVar28 & 0xffffffe0 | uVar11 | uVar19;
              puVar40[2] = 0x1151;
              puVar40[3] = uVar19 | uVar11 | uVar31 & 0xffffffe0;
              puVar40[4] = 0x1152;
              puVar40[5] = uVar19 | uVar11 | uVar31 + (uVar33 >> 2) & 0xffffffe0;
              puVar40[6] = 0x1393;
              puVar40[7] = 10;
              puVar40[8] = 0x138a;
              puVar40[9] = uVar21 << 5;
              puVar40[10] = 0x138e;
              puVar40[0xb] = uVar17 >> 2 & 0x3ffe | 0xd00000;
              uVar37 = uVar37 & 0xffffff;
            }
          }
          else {
            if (uVar17 != 0x46000000) {
              if (uVar17 == 0x47000000) {
                uVar21 = puVar40[1];
                uVar17 = puVar40[2];
                if (uVar21 == 0) {
                  uVar21 = 1;
                }
                else if (0xc < uVar21 - 10) goto LAB_00039030;
                if (uVar17 == 0) {
                  uVar17 = 1;
                }
                else if (0xc < uVar17 - 10) goto LAB_00039030;
                iVar23 = uVar17 * 0x78 + M<SInt32>(self + 0xf8);
                iVar18 = uVar21 * 0x78 + M<SInt32>(self + 0xf8);
                *puVar40 = 0x1140;
                puVar40[1] = (M<UInt16>(iVar18 + 0xc0) >> 2) - 1;
                puVar40[2] = 0x1150;
                puVar40[3] = M<UInt32>(iVar18 + 0xb0) & 0xffffffe0 |
                             (M<UInt8>(iVar18 + 0xe0) & 1) << 2 |
                             (M<UInt8>(iVar18 + 0xe0) & 6) << 2;
                puVar40[4] = 0x1393;
                puVar40[5] = 10;
                puVar40[6] = 0x138a;
                puVar40[7] = M<UInt32>(iVar23 + 0xb0) & 0xffffffe0;
                puVar40[8] = 0x138e;
                bVar44 = M<UInt8>(iVar23 + 0xe1);
                uVar17 = M<UInt16>(iVar23 + 0xc0) >> 2 & 0x3ffe |
                         (M<UInt8>(iVar23 + 0xe0) & 1) << 0x10 |
                         (M<UInt8>(iVar23 + 0xe0) & 6) << 0x10;
                goto LAB_00038870;
              }
              if (uVar17 != 0x44000000) goto LAB_00039028;
              uVar17 = puVar40[4];
              iVar23 = M<SInt32>(self + 0xf8);
              iVar12 = puVar40[1] * 0x78 + iVar23;
              pVVar42 = M<UInt8 *>(self + puVar40[2] * 4 + 0x104);
              iVar18 = (SInt32)M<SInt16>(iVar23 + 0x9a) - (SInt32)M<SInt16>(iVar23 + 0x94);
              bVar43 = puVar40[3] != 0;
              if ((uVar17 & 2) == 0) {
                if (bVar43) {
                  uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
                  uVar11 = (iVar18 * (UInt32)M<UInt16>(iVar12 + 0x570) * 3 >> 1) +
                           M<SInt32>(iVar12 + 0x560);
                }
                else {
                  uVar11 = M<UInt32>(iVar12 + 0x560);
                  uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
                }
              }
              else {
                uVar11 = M<UInt32>(iVar23 + 0x998);
                uVar21 = (UInt32)M<UInt16>(iVar12 + 0x570);
              }
              goto joined_r0x000381c4;
            }
            iVar23 = M<SInt32>(self + 0xf8);
            *puVar40 = 0x1140;
            uVar17 = (UInt32)M<UInt16>(iVar23 + 0x136);
            if (uVar17 == 0) {
              puVar40[1] = 0;
            }
            else {
              puVar40[1] = M<UInt16>(iVar23 + 0x138) / uVar17 - 1;
            }
            puVar40[2] = 0x1150;
            uVar28 = M<UInt8>(iVar23 + 0x158) & 1;
            uVar11 = M<UInt32>(iVar23 + 0x128) & 0xffffffe0;
            uVar21 = (UInt32)(M<UInt8>(iVar23 + 0x158) >> 1);
            puVar40[3] = uVar11 | uVar28 << 2 | (uVar21 & 3) << 3;
            puVar40[4] = 0x1141;
            uVar19 = (UInt32)M<UInt16>(iVar23 + 0x92e);
            if (uVar19 == 0) {
              puVar40[5] = 0;
            }
            else {
              puVar40[5] = M<UInt16>(iVar23 + 0x930) / uVar19 - 1;
            }
            puVar40[6] = 0x1151;
            uVar35 = M<UInt8>(iVar23 + 0x950) & 1;
            uVar33 = M<UInt32>(iVar23 + 0x920) & 0xffffffe0;
            uVar31 = (UInt32)(M<UInt8>(iVar23 + 0x950) >> 1);
            puVar40[7] = uVar33 | uVar35 << 2 | (uVar31 & 3) << 3;
            puVar40[8] = 0x1393;
            puVar40[9] = 10;
            puVar40[10] = 0x138a;
            puVar40[0xb] = uVar11;
            puVar40[0xc] = 0x138e;
            uVar11 = 0;
            iVar18 = (UInt32)M<UInt8>(iVar23 + 0x15a) * 0x1c;
            if ((M<UInt32>(iVar23 + 0x15c) & 0xf00000) != 0) {
              uVar11 = (UInt32)M<UInt16>(iVar23 + 0x134) / (M<UInt32>(iVar23 + 0x15c) >> 0x14 & 0xf)
              ;
            }
            uVar36 = 0x20 / uVar17;
            if (0x20 / uVar17 <= uVar11) {
              uVar36 = uVar11;
            }
            local_60 = FormatTableLookup_0x0004d2e0(iVar18) >> 1 & 0x1e00000 |
                       (FormatTableLookup_0x0004d2dc(iVar18) & 0xc00) << 9 |
                       (uVar21 & 3) << 0x11 |
                       uVar28 << 0x10 | uVar36 & 0x3ffe | local_60 & 0xfe00c001;
            puVar40[0xd] = local_60;
            puVar40[0xe] = 0x138b;
            puVar40[0xf] = uVar33;
            puVar40[0x10] = 0x138f;
            uVar17 = 0;
            iVar18 = (UInt32)M<UInt8>(iVar23 + 0x952) * 0x1c;
            if ((M<UInt32>(iVar23 + 0x954) & 0xf00000) != 0) {
              uVar17 = (UInt32)M<UInt16>(iVar23 + 0x92c) / (M<UInt32>(iVar23 + 0x954) >> 0x14 & 0xf)
              ;
            }
            uVar21 = 0x20 / uVar19;
            if (0x20 / uVar19 <= uVar17) {
              uVar21 = uVar17;
            }
            local_5c = FormatTableLookup_0x0004d2e0(iVar18) >> 1 & 0x1e00000 |
                       (FormatTableLookup_0x0004d2dc(iVar18) & 0xc00) << 9 |
                       (uVar31 & 3) << 0x11 |
                       uVar35 << 0x10 | uVar21 & 0x3ffe | local_5c & 0xfe00c001;
            puVar40[0x11] = local_5c;
            uVar37 = uVar37 & 0xffffff;
          }
          goto LAB_0003903c;
        }
        if (uVar17 != 0x2d000000) {
          if (uVar17 < 0x2d000001) {
            if (uVar17 != 0x29000000) {
              if (uVar17 < 0x29000001) {
                if (((uVar17 == 0x27000000) || (uVar17 == 0x28000000)) || (uVar17 == 0x26000000))
                goto LAB_00037620;
              }
              else {
                if ((uVar17 == 0x2b000000) || (uVar17 == 0x2c000000)) goto LAB_00037880;
                if (uVar17 == 0x2a000000) goto LAB_00037620;
              }
              goto LAB_00039028;
            }
            goto LAB_00037620;
          }
          if (uVar17 != 0x31000000) {
            if (uVar17 < 0x31000001) {
              if (((uVar17 == 0x2f000000) || (uVar17 == 0x30000000)) || (uVar17 == 0x2e000000))
              goto LAB_00037880;
            }
            else if (((uVar17 == 0x33000000) || (uVar17 == 0x34000000)) || (uVar17 == 0x32000000))
            goto LAB_00037880;
            goto LAB_00039028;
          }
        }
      }
LAB_00037880:
      uVar17 = uVar17 + 0xd5000000 >> 0x16;
      if (M<UInt8 *>(self + uVar17 + 0x104) != (UInt8 *)0x0) {
        ((IOATIR500DVDContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + uVar17 + 0x104)));
        iVar23 = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(self + uVar17 + 0x104) + 0x14) + 0x10);
        if (iVar23 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + 0x84)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + uVar17 + 0x104)));
        }
        M<UInt32>(self + uVar17 + 0x104) = 0;
      }
LAB_00039020:
      *puVar40 = 0x80000000;
LAB_00039028:
      uVar37 = uVar37 & 0xffffff;
    }
LAB_0003903c:
    puVar40 = puVar40 + uVar37;
    local_6c = local_6c + uVar37;
    if (uVar37 == 0) {
      if ((local_6c & 1) != 0) {
        *puVar40 = 0x80000000;
        puVar40 = puVar40 + 1;
        local_6c = local_6c + 1;
      }
      M<UInt32>(param_1) = (local_70 & 0xfffffffc) + M<SInt32>(self + 0xa4) + 0x20;
      iVar23 = M<SInt32>(self + 0x94);
      M<UInt32 *>(param_1 + 0xc) = puVar40;
      M<UInt32>(param_1 + 8) = local_6c;
      M<UInt32>(param_1 + 4) = local_70 + iVar23 + 0x20;
      return local_68;
    }
  } while( true );
}
