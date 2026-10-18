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
IOReturn ATIR500DVDContext::process_command_buffer(VendorCommandDescriptor *descriptor) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *descriptorBytes = reinterpret_cast<UInt8 *>(descriptor);

  SInt16 sVar1;
  SInt16 sVar2;
  UInt16 otherPitch;
  UInt16 pitch;
  UInt32 tilingByte0Shifted;
  UInt32 tilingBit0At2;
  double dVar7;
  double dVar8;
  double dVar9;
  UInt32 wordsToSubmit;
  UInt32 uVar11;
  SInt32 iVar12;
  UInt32 uVar13;
  SInt32 *accelerator;
  UInt32 stamp;
  UInt32 *puVar16;
  UInt32 uVar17;
  SInt32 iVar18;
  UInt32 uVar19;
  UInt32 *puVar20;
  UInt32 uVar21;
  SInt32 iVar22;
  SInt32 iVar23;
  UInt32 tilingBit0;
  SInt32 iVar25;
  UInt32 *puVar26;
  UInt32 tilingBitsAt3;
  UInt32 uVar28;
  UInt32 uVar29;
  UInt32 uVar30;
  UInt32 uVar31;
  UInt32 uVar32;
  UInt32 uVar33;
  UInt32 uVar34;
  UInt32 uVar35;
  UInt32 uVar36;
  UInt32 recordWord;
  UInt32 uVar38;
  UInt32 uVar39;
  UInt32 *recordCursor;
  UInt32 uVar41;
  UInt8 *texture;
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
  UInt32 streamOffset;
  UInt32 pendingWords;
  UInt32 result;
  UInt32 local_64;
  UInt32 local_60;
  UInt32 local_5c;
  UInt32 local_58;
  SInt32 prevNode;
  SInt32 submitBytes;
  UInt32 alignedOffset;
  SInt32 gartOffset;
  SInt32 surfaceInfo;
  SInt32 fieldHeight;
  SInt32 formatOffset;
  SInt32 bufferInfo;
  UInt32 gartBlock32;
  SInt32 textureAddress;
  SInt32 secondBufferInfo;
  UInt32 plane0Address;
  UInt32 bufferPitch;
  UInt32 plane1Address;
  UInt32 widthUnits;
  UInt32 pitchUnits;
  
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  result = 0;
  streamOffset = 0;
  recordCursor = (UInt32 *)(M<SInt32>(self + kIOATIR500DVDContext_commandBufferHeader) + 0x1c);
  pendingWords = 0xffffffff;
  do {
    wordsToSubmit = pendingWords;
    recordWord = *recordCursor;
    uVar17 = recordWord & 0xff000000;
    if (uVar17 == 0x25000000) goto LAB_00037620;
    if (uVar17 < 0x25000001) {
      if (uVar17 != 0x15000000) {
        if (uVar17 < 0x15000001) {
          if (uVar17 == 0x9000000) goto LAB_00039030;
          if (0x9000000 < uVar17) {
            if (uVar17 == 0xd000000) {
              uVar17 = recordCursor[3];
              uVar21 = recordCursor[4];
              uVar11 = recordCursor[5];
              bVar44 = (recordCursor[2] == 0) << 1;
              if (recordCursor[2] == 0) {
                texture = M<UInt8 *>(self + recordCursor[1] * 4 + 0x104);
                if ((M<SInt32>(texture + 4) != 0) ||
                   (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture)),
                   M<SInt32>(texture + 4) != 0)) {
                  GH_IOGetTime(texture + 0x2c);
                  prevNode = M<SInt32>(texture + 0x34);
                  M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
                  M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
                  M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
                  M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                  M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                  M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
                }
                uVar19 = 0;
                M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
                if (M<SInt32>(texture + 4) != 0) {
                  uVar19 = (UInt32)(M<SInt32>(texture + 4) +
                                 M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4))
                           >> 10;
                }
                iVar23 = 0;
                uVar19 = uVar19 | (uVar11 & 0xff0) << 0x12;
              }
              else {
                iVar18 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                iVar23 = iVar18 + 0x828;
                uVar19 = M<UInt32>(iVar18 + 0x830) >> 10 |
                         (M<UInt16>(iVar18 + 0x840) & 0x3fc0) << 0x10;
              }
              *recordCursor = 0x1393;
              recordCursor[1] = 10;
              recordCursor[2] = 0x5c8;
              recordCursor[3] = 0x20000;
              recordCursor[4] = 0xc0069a00;
              recordCursor[5] = 0x52f036da;
              recordCursor[6] = uVar19;
              recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
              recordCursor[8] = M<UInt32>(self + kATIR500DVDContext_scissorBottomRight);
              recordCursor[9] = 0;
              recordCursor[10] = 0;
              if ((bool)(bVar44 >> 1 & 1)) {
                recordCursor[0xb] = uVar21 | uVar17 << 0x10;
              }
              else {
                recordCursor[0xb] = M<UInt32>(iVar23 + 0x1c);
              }
              goto LAB_00038f80;
            }
            if (uVar17 < 0xd000001) {
              if (uVar17 != 0xb000000) {
                if (uVar17 != 0xc000000) {
                  if (uVar17 != 0xa000000) goto LAB_00039028;
                  accelerator = M<SInt32 *>(self + kIOATIR500DVDContext_accelerator);
                  if (accelerator[0x22f] != 0) {
                    VCALL(*accelerator, 0x5ec)(accelerator,M<UInt32>(self + kATIR500DVDContext_idctTimeStamp));
                    M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_boundSurface) + 0xd90) = recordCursor[1];
                    surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                    fieldHeight = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
                    if ((M<SInt16>(surfaceInfo + 0x98) != M<SInt16>(surfaceInfo + 0x96)) && (fieldHeight != 0)) {
                      bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
                      if ((recordCursor[3] & 2) == 0) {
                        if (recordCursor[2] == 0) {
                          plane0Address = M<UInt32>(bufferInfo + 0x560);
                          bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
                        }
                        else {
                          bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
                          plane0Address = (fieldHeight * (UInt32)M<UInt16>(bufferInfo + 0x570) * 3 >> 1) +
                                   M<SInt32>(bufferInfo + 0x560);
                        }
                      }
                      else {
                        plane0Address = M<UInt32>(surfaceInfo + 0x998);
                        bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
                      }
                      if ((recordCursor[3] & 4) == 0) {
                        if (recordCursor[2] == 0) {
                          plane1Address = fieldHeight * bufferPitch + M<SInt32>(bufferInfo + 0x560);
                        }
                        else {
                          plane1Address = fieldHeight * bufferPitch +
                                   (fieldHeight * bufferPitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
                        }
                      }
                      else {
                        plane1Address = fieldHeight * bufferPitch + M<SInt32>(surfaceInfo + 0x998);
                      }
                      *recordCursor = 0x1140;
                      recordCursor[1] = bufferPitch - 1;
                      recordCursor[2] = 0x1150;
                      uVar19 = (M<UInt8>(bufferInfo + 0x590) & 1) << 2;
                      uVar28 = (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
                      recordCursor[3] = plane0Address & 0xffffffe0 | uVar19 | uVar28;
                      recordCursor[4] = 0x1141;
                      recordCursor[5] = (bufferPitch >> 1) - 1;
                      recordCursor[6] = 0x1151;
                      recordCursor[7] = uVar28 | uVar19 | plane1Address & 0xffffffe0;
                      recordCursor[8] = 0x1393;
                      recordCursor[9] = 10;
                      recordCursor[10] = 0x138a;
                      recordCursor[0xb] = M<UInt32>(surfaceInfo + 0x128) & 0xffffffe0;
                      recordCursor[0xc] = 0x138e;
                      widthUnits = 0;
                      formatOffset = (UInt32)M<UInt8>(surfaceInfo + 0x15a) * 0x1c;
                      if ((M<UInt32>(surfaceInfo + 0x15c) & 0xf00000) != 0) {
                        widthUnits = (UInt32)M<UInt16>(surfaceInfo + 0x134) /
                                 (M<UInt32>(surfaceInfo + 0x15c) >> 0x14 & 0xf);
                      }
                      pitchUnits = 0x20 / M<UInt16>(surfaceInfo + 0x136);
                      if (pitchUnits <= widthUnits) {
                        pitchUnits = widthUnits;
                      }
                      local_64 = FormatTableLookup_0x0004d2e0(formatOffset) >> 1 & 0x1e00000 |
                                 (FormatTableLookup_0x0004d2dc(formatOffset) & 0xc00) << 9 |
                                 (M<UInt8>(surfaceInfo + 0x158) & 6) << 0x10 |
                                 (M<UInt8>(surfaceInfo + 0x158) & 1) << 0x10 |
                                 pitchUnits & 0x3ffe | local_64 & 0xfe00c001;
                      recordCursor[0xd] = local_64;
                      recordWord = recordWord & 0xffffff;
                      goto LAB_0003903c;
                    }
                  }
                }
                goto LAB_00039030;
              }
              if (recordCursor[2] == 0) {
                texture = M<UInt8 *>(self + recordCursor[1] * 4 + 0x104);
                if ((M<SInt32>(texture + 4) != 0) ||
                   (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture)),
                   M<SInt32>(texture + 4) != 0)) {
                  GH_IOGetTime(texture + 0x2c);
                  prevNode = M<SInt32>(texture + 0x34);
                  M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
                  M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
                  M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
                  M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                  M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                  M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
                }
                M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
                if (M<SInt32>(texture + 4) == 0) {
                  surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                  gartBlock32 = 0;
                }
                else {
                  surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                  gartBlock32 = (UInt32)(M<SInt32>(texture + 4) +
                                 M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4))
                           >> 5;
                }
              }
              else {
                surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                gartBlock32 = M<UInt32>(surfaceInfo + 0x830) >> 5;
              }
              *recordCursor = 0x1150;
              recordCursor[1] = gartBlock32 << 5;
              recordCursor[2] = 0x1393;
              recordCursor[3] = 10;
              recordCursor[4] = 0x138a;
              recordCursor[5] = M<UInt32>(surfaceInfo + 0x128) & 0xffffffe0;
              recordCursor[6] = 0x138e;
              widthUnits = 0;
              formatOffset = (UInt32)M<UInt8>(surfaceInfo + 0x15a) * 0x1c;
              if ((M<UInt32>(surfaceInfo + 0x15c) & 0xf00000) != 0) {
                widthUnits = (UInt32)M<UInt16>(surfaceInfo + 0x134) /
                         (M<UInt32>(surfaceInfo + 0x15c) >> 0x14 & 0xf);
              }
              pitchUnits = 0x20 / M<UInt16>(surfaceInfo + 0x136);
              if (pitchUnits <= widthUnits) {
                pitchUnits = widthUnits;
              }
              local_58 = FormatTableLookup_0x0004d2e0(formatOffset) >> 1 & 0x1e00000 |
                         (FormatTableLookup_0x0004d2dc(formatOffset) & 0xc00) << 9 |
                         (M<UInt8>(surfaceInfo + 0x158) & 6) << 0x10 |
                         (M<UInt8>(surfaceInfo + 0x158) & 1) << 0x10 |
                         pitchUnits & 0x3ffe | local_58 & 0xfe00c001;
              recordCursor[7] = local_58;
              recordWord = recordWord & 0xffffff;
            }
            else if (uVar17 == 0x13000000) {
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
              uVar17 = M<UInt32>(bufferInfo + 0x560);
              pitch = M<UInt16>(bufferInfo + 0x570);
              *recordCursor = 0x1087;
              recordCursor[1] = (M<UInt16>(bufferInfo + 0x576) & 0x3fff) << 2 | (UInt32)pitch << 0x11;
              recordCursor[2] = 0x1150;
              recordCursor[3] = uVar17 & 0xffffffe0;
              recordCursor[4] = 0x1393;
              recordCursor[5] = 10;
              recordCursor[6] = 0x138a;
              recordCursor[7] = uVar17 + (((SInt32)M<SInt16>(surfaceInfo + 0x9a) -
                                     (SInt32)M<SInt16>(surfaceInfo + 0x94)) * (UInt32)pitch * 3 >> 1) &
                           0xffffffe0;
              recordCursor[8] = 0x138e;
              recordCursor[9] = pitch >> 2 & 0x3ffe | (M<UInt8>(bufferInfo + 0x590) & 1) << 0x10 |
                           (M<UInt8>(bufferInfo + 0x590) & 6) << 0x10 |
                           (M<UInt8>(bufferInfo + 0x591) & 3) << 0x13 | 0xc00000;
              dVar9 = DOUBLE_0004c3c0;
              dVar8 = DOUBLE_0004c3b8;
              dVar7 = DOUBLE_0004c3a8;
              uStack_84 = pitch >> 2 ^ 0x80000000;
              local_88 = 0x43300000;
              recordCursor[0x61] =
                   FBITS((float)((((double)CONCAT44d(0x43300000,uStack_84) - DOUBLE_0004c3a8) +
                                 DOUBLE_0004c3c0) * DOUBLE_0004c3b8));
              local_80 = 0x43300000;
              uStack_7c = M<UInt16>(bufferInfo + 0x576) >> 1 ^ 0x80000000;
              recordCursor[0x62] =
                   FBITS((float)((((double)CONCAT44d(0x43300000,uStack_7c) - dVar7) + dVar9) * dVar8))
              ;
              recordWord = recordWord & 0xffffff;
            }
            else {
              if (uVar17 != 0x14000000) {
                if (uVar17 == 0x12000000) {
                  accelerator = M<SInt32 *>(self + kIOATIR500DVDContext_accelerator);
                  if ((accelerator[0x22f] == 0) ||
                     (VCALL(*accelerator, 0x5ec)(accelerator,M<UInt32>(self + kATIR500DVDContext_idctTimeStamp)),
                     recordCursor[0xd] == 0)) goto LAB_00039030;
                  iVar23 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                  uVar17 = recordCursor[2];
                  uVar21 = recordCursor[3];
                  uVar31 = recordCursor[6];
                  uVar11 = recordCursor[7];
                  uVar19 = recordCursor[8];
                  uVar33 = recordCursor[9];
                  uVar35 = recordCursor[10];
                  sVar1 = M<SInt16>(iVar23 + 0x98);
                  sVar2 = M<SInt16>(iVar23 + 0x96);
                  uVar36 = recordCursor[0xb];
                  uVar28 = recordCursor[0xc];
                  texture = M<UInt8 *>(self + recordCursor[1] * 4 + 0x104);
                  uVar38 = (SInt32)M<SInt16>(iVar23 + 0x9a) - (SInt32)M<SInt16>(iVar23 + 0x94);
                  if ((M<SInt32>(texture + 4) != 0) ||
                     (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture))
                     , M<SInt32>(texture + 4) != 0)) {
                    GH_IOGetTime(texture + 0x2c);
                    prevNode = M<SInt32>(texture + 0x34);
                    M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
                    M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
                    M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0)
                    ;
                    M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                    M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                    M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
                  }
                  iVar23 = 0;
                  M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
                  if (M<SInt32>(texture + 4) != 0) {
                    iVar23 = M<SInt32>(texture + 4) +
                             M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4);
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
                  texture = M<UInt8 *>(self + recordCursor[5] * 4 + 0x104);
                  if ((M<SInt32>(texture + 4) != 0) ||
                     (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture))
                     , M<SInt32>(texture + 4) != 0)) {
                    GH_IOGetTime(texture + 0x2c);
                    prevNode = M<SInt32>(texture + 0x34);
                    M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
                    M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
                    M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0)
                    ;
                    M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                    M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                    M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
                  }
                  uVar13 = 0;
                  M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
                  if (M<SInt32>(texture + 4) != 0) {
                    uVar13 = M<SInt32>(texture + 4) +
                             M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4);
                  }
                  iVar18 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                  iVar23 = uVar33 * 0x78 + iVar18;
                  uVar34 = (UInt32)M<UInt16>(iVar18 + 0x8b8);
                  puVar26 = recordCursor + uVar31;
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
                  puVar16 = recordCursor + uVar11;
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
                  *recordCursor = 0xc00c1000;
                }
                goto LAB_00039028;
              }
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              secondBufferInfo = recordCursor[2] * 0x78 + surfaceInfo;
              bufferInfo = recordCursor[3] * 0x78 + surfaceInfo;
              fieldHeight = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
              uVar17 = recordCursor[4];
              pitch = M<UInt16>(secondBufferInfo + 0x570);
              uVar11 = (UInt32)pitch;
              uVar21 = M<UInt32>(secondBufferInfo + 0x560);
              iVar18 = fieldHeight * uVar11;
              iVar45 = uVar21 + ((UInt32)(iVar18 * 3) >> 1);
              if (recordCursor[1] == 2) {
                if (uVar17 == 0) {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  uVar19 = uVar21 + iVar18;
                  uVar33 = uVar11 + iVar18 + iVar45;
                  uVar36 = fieldHeight * (UInt32)otherPitch + M<SInt32>(bufferInfo + 0x560);
                  uVar38 = uVar36 + (otherPitch >> 1);
                  uVar17 = fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) + M<SInt32>(surfaceInfo + 0x7b8);
                  uVar28 = uVar19 + (pitch >> 1);
                  uVar35 = uVar19 + ((SInt32)(uVar11 * 3) >> 1);
                  uVar31 = uVar36 + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                }
                else {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  uVar28 = uVar21 + iVar18;
                  uVar38 = fieldHeight * (UInt32)otherPitch + M<SInt32>(bufferInfo + 0x560);
                  uVar17 = fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) + M<SInt32>(surfaceInfo + 0x7b8) +
                           (UInt32)(M<UInt16>(surfaceInfo + 0x7c8) >> 1);
                  uVar31 = otherPitch + uVar38;
                  uVar33 = (UInt32)(pitch >> 1) + iVar18 + iVar45;
                  uVar36 = uVar38 + (otherPitch >> 1);
                  uVar35 = uVar11 + uVar28;
                  uVar19 = uVar28 + (pitch >> 1);
                }
              }
              else if (recordCursor[1] == 3) {
                if (uVar17 == 0) {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  uVar17 = (UInt32)(iVar18 * 5) >> 2;
                  uVar19 = uVar21 + uVar17;
                  uVar36 = (fieldHeight * (UInt32)otherPitch * 5 >> 2) + M<SInt32>(bufferInfo + 0x560);
                  uVar33 = uVar11 + iVar45 + uVar17;
                  uVar35 = uVar19 + ((SInt32)(uVar11 * 3) >> 1);
                  uVar38 = uVar36 + (otherPitch >> 1);
                  uVar17 = (fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) * 5 >> 2) +
                           M<SInt32>(surfaceInfo + 0x7b8);
                  uVar31 = uVar36 + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                  uVar28 = uVar19 + (pitch >> 1);
                }
                else {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  uVar19 = (UInt32)(iVar18 * 5) >> 2;
                  uVar28 = uVar21 + uVar19;
                  uVar38 = (fieldHeight * (UInt32)otherPitch * 5 >> 2) + M<SInt32>(bufferInfo + 0x560);
                  uVar17 = (fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) * 5 >> 2) +
                           M<SInt32>(surfaceInfo + 0x7b8) + (UInt32)(M<UInt16>(surfaceInfo + 0x7c8) >> 1);
                  uVar31 = otherPitch + uVar38;
                  uVar33 = (UInt32)(pitch >> 1) + iVar45 + uVar19;
                  uVar36 = uVar38 + (otherPitch >> 1);
                  uVar35 = uVar11 + uVar28;
                  uVar19 = uVar28 + (pitch >> 1);
                }
              }
              else if (uVar17 == 0) {
                uVar36 = M<UInt32>(bufferInfo + 0x560);
                uVar17 = M<UInt32>(surfaceInfo + 0x7b8);
                uVar28 = uVar21 + uVar11;
                uVar33 = iVar45 + uVar11 * 2;
                uVar35 = uVar21 + uVar11 * 3;
                uVar38 = uVar36 + M<UInt16>(bufferInfo + 0x570);
                uVar31 = uVar36 + (UInt32)M<UInt16>(bufferInfo + 0x570) * 3;
                uVar19 = uVar21;
              }
              else {
                uVar38 = M<UInt32>(bufferInfo + 0x560);
                uVar33 = uVar11 + iVar45;
                uVar35 = uVar21 + uVar11 * 2;
                uVar36 = uVar38 + M<UInt16>(bufferInfo + 0x570);
                uVar17 = (UInt32)M<UInt16>(surfaceInfo + 0x7c8) + M<SInt32>(surfaceInfo + 0x7b8);
                uVar31 = uVar38 + (UInt32)M<UInt16>(bufferInfo + 0x570) * 2;
                uVar19 = uVar21 + uVar11;
                uVar28 = uVar21;
              }
              *recordCursor = 0x1150;
              uVar21 = (M<UInt8>(secondBufferInfo + 0x590) & 1) << 2;
              uVar11 = (M<UInt8>(secondBufferInfo + 0x590) & 6) << 2;
              recordCursor[1] = uVar19 & 0xffffffe0 | uVar21 | uVar11;
              recordCursor[2] = 0x1151;
              recordCursor[3] = uVar11 | uVar21 | uVar28 & 0xffffffe0;
              recordCursor[4] = 0x1152;
              recordCursor[5] = uVar11 | uVar21 | uVar35 & 0xffffffe0;
              recordCursor[6] = 0x1153;
              uVar21 = (M<UInt8>(bufferInfo + 0x590) & 1) << 2;
              uVar11 = (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
              recordCursor[7] = uVar36 & 0xffffffe0 | uVar21 | uVar11;
              recordCursor[8] = 0x1154;
              recordCursor[9] = uVar11 | uVar21 | uVar38 & 0xffffffe0;
              recordCursor[10] = 0x1155;
              recordCursor[0xb] = uVar11 | uVar21 | uVar31 & 0xffffffe0;
              recordCursor[0xc] = 0x1156;
              uVar17 = uVar17 & 0xffffffe0;
              recordCursor[0xd] = uVar17 | (M<UInt8>(surfaceInfo + 0x7e8) & 1) << 2 |
                             (M<UInt8>(surfaceInfo + 0x7e8) & 6) << 2;
              recordCursor[0xe] = 0x1393;
              recordCursor[0xf] = 10;
              recordCursor[0x10] = 0x138a;
              recordCursor[0x11] = uVar33 & 0xffffffe0;
              recordCursor[0x12] = 0x138b;
              recordCursor[0x13] = uVar17;
              recordCursor[0x14] = 0x138c;
              recordCursor[0x15] = uVar33 & 0xffffffe0;
              recordCursor[0x16] = 0x138d;
              recordCursor[0x17] = uVar17;
              recordWord = recordWord & 0xffffff;
            }
            goto LAB_0003903c;
          }
          if (uVar17 == 0x5000000) {
            uVar21 = (UInt32)M<UInt8>((SInt32)recordCursor + 0xf);
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            uVar17 = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
            if (recordCursor[2] == 0) {
              uVar11 = M<UInt32>(bufferInfo + 0x560);
              pitch = M<UInt16>(bufferInfo + 0x570);
            }
            else {
              pitch = M<UInt16>(bufferInfo + 0x570);
              uVar11 = (uVar17 * pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
            }
            bVar44 = M<UInt8>(bufferInfo + 0x590);
            uVar19 = 0x80000000;
            if (bVar44 < 2) {
              uVar19 = 0;
            }
            *recordCursor = 0x1393;
            recordCursor[1] = 10;
            recordCursor[2] = 0x5c8;
            recordCursor[3] = 0x20000;
            recordCursor[4] = 0xc0069a00;
            recordCursor[5] = 0x52f036da;
            recordCursor[6] = uVar19 | uVar11 >> 10 | (pitch & 0x3fc0) << 0x10 | (bVar44 & 1) << 0x1e;
            recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
            recordCursor[8] = CONCAT22(M<UInt16>(bufferInfo + 0x576),M<UInt16>(bufferInfo + 0x574));
            recordCursor[9] = uVar21 | uVar21 << 0x18 | uVar21 << 0x10 |
                                  uVar21 << 8;   /* the byte replicated four times: uVar21 holds the byte read BEFORE the packet rewrite overwrote the command (re-reading it here read the rewritten word: 0x20200020) */
            recordCursor[10] = 0;
            uVar17 = uVar17 | (pitch & 0xfffc) << 0xe;
LAB_00037c4c:
            recordCursor[0xb] = uVar17;
            recordCursor[0xc] = 0xd0b;
            recordCursor[0xd] = 5;
            recordCursor[0xe] = 0x5c8;
            recordCursor[0xf] = 0x10000;
            goto LAB_00039028;
          }
          if (0x5000000 < uVar17) {
            if ((uVar17 == 0x7000000) || (uVar17 == 0x8000000)) goto LAB_00039030;
            if (uVar17 != 0x6000000) goto LAB_00039028;
            uVar21 = (UInt32)M<UInt8>((SInt32)recordCursor + 0xf);
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            uVar17 = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
            if (recordCursor[2] == 0) {
              pitch = M<UInt16>(bufferInfo + 0x570);
              uVar11 = uVar17 * pitch + M<SInt32>(bufferInfo + 0x560);
            }
            else {
              pitch = M<UInt16>(bufferInfo + 0x570);
              uVar11 = uVar17 * pitch + (uVar17 * pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
            }
            bVar44 = M<UInt8>(bufferInfo + 0x590);
            uVar19 = 0x80000000;
            if (bVar44 < 2) {
              uVar19 = 0;
            }
            *recordCursor = 0x1393;
            recordCursor[1] = 10;
            recordCursor[2] = 0x5c8;
            recordCursor[3] = 0x20000;
            recordCursor[4] = 0xc0069a00;
            recordCursor[5] = 0x52f036da;
            recordCursor[6] = uVar19 | uVar11 >> 10 | (pitch & 0x3fc0) << 0x10 | (bVar44 & 1) << 0x1e;
            recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
            recordCursor[8] = CONCAT22(M<UInt16>(bufferInfo + 0x576),M<UInt16>(bufferInfo + 0x574));
            recordCursor[9] = uVar21 | uVar21 << 0x18 | uVar21 << 0x10 |
                                  uVar21 << 8;   /* the byte replicated four times: uVar21 holds the byte read BEFORE the packet rewrite overwrote the command (re-reading it here read the rewritten word: 0x20200020) */
            recordCursor[10] = 0;
            uVar17 = (pitch & 0xfffc) << 0xe | uVar17 >> 1;
            goto LAB_00037c4c;
          }
          if (uVar17 == 0x2000000) {
            recordWord = recordWord & 0xffffff;
            result = 3;
            goto LAB_0003903c;
          }
          if (uVar17 != 0x4000000) goto LAB_00039028;
          if (pendingWords != 0) {
            submitBytes = pendingWords * 4;
            pendingWords = 0;
            alignedOffset = streamOffset & 0xfffffffc;
            M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x708) =
                 submitBytes + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x708);
            gartOffset = streamOffset + M<SInt32>(self + kIOATIR500DVDContext_commandBufferGartOffset);
            streamOffset = streamOffset + submitBytes;
            stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->submit_buffer((UInt32 *)(alignedOffset + M<SInt32>(self + kIOATIR500DVDContext_commandBufferHeader) + 0x20),gartOffset + 0x20,
                                wordsToSubmit);
            M<UInt32>(self + kIOATIR500DVDContext_commandBufferStamp) = stamp;
          }
          goto LAB_00039020;
        }
        if (uVar17 == 0x1d000000) {
LAB_00037620:
          if ((recordCursor[1] < M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_sharedAllocator) + 0x14)) &&
             (texture = *(UInt8 **)
                         (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_sharedAllocator) + 0x10)),
             texture != (UInt8 *)0x0)) {
            iVar23 = (uVar17 + 0xe7000000 >> 0x18) * 4;
            if (M<UInt8 *>(self + iVar23 + 0x104) != (UInt8 *)0x0) {
              ((IOATIR500DVDContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + iVar23 + 0x104)));
              iVar18 = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(self + iVar23 + 0x104) + 0x14) + 0x10);
              if (iVar18 == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500DVDContext_sharedAllocator)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + iVar23 + 0x104)));
              }
              M<UInt32>(self + iVar23 + 0x104) = 0;
            }
            ((IOATIR500DVDContext *)((UInt8 *)self))->add_texture_to_stream((VendorTextureBuffer *)((UInt8 *)texture));
            wordsToSubmit = pendingWords;
            if (M<char>(M<SInt32>(texture + 0x14) + 0x14) != '\0') {
              if (pendingWords != 0) {
                submitBytes = pendingWords * 4;
                pendingWords = 0;
                alignedOffset = streamOffset & 0xfffffffc;
                M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x708) =
                     submitBytes + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x708);
                gartOffset = streamOffset + M<SInt32>(self + kIOATIR500DVDContext_commandBufferGartOffset);
                streamOffset = streamOffset + submitBytes;
                stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->submit_buffer((UInt32 *)(alignedOffset + M<SInt32>(self + kIOATIR500DVDContext_commandBufferHeader) + 0x20),gartOffset + 0x20,
                                    wordsToSubmit);
                M<UInt32>(self + kIOATIR500DVDContext_commandBufferStamp) = stamp;
              }
              if ((M<SInt32>(texture + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture)),
                 M<SInt32>(texture + 4) != 0)) {
                GH_IOGetTime(texture + 0x2c);
                M<UInt32>(M<SInt32>(texture + 0x34) + 0x38) = M<UInt32>(texture + 0x38);
                M<UInt32>(M<SInt32>(texture + 0x38) + 0x34) = M<UInt32>(texture + 0x34);
                M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
                M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
              }
              M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
              if (M<SInt32>(self + kIOATIR500DVDContext_commandBufferGartOffset) == 0) {
                ((IOATIR500DVDContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500DVDContext_commandBuffer)));
              }
            }
            GH_OSAddAtomic(0xffff0001,M<SInt32>(texture + 0x14) + 0x10);
            if (M<SInt32>(texture + 0x48) != 0) {
              M<UInt32>(M<SInt32>(texture + 0x24) + 0x28) = M<UInt32>(texture + 0x28);
              M<UInt32>(M<SInt32>(texture + 0x28) + 0x24) = M<UInt32>(texture + 0x24);
              M<UInt32>(texture + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x600);
              M<SInt32>(texture + 0x28) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x5dc;
              M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x600) = texture;
              M<UInt8 *>(M<SInt32>(texture + 0x24) + 0x28) = texture;
            }
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordWord = recordWord & 0xffffff;
            M<UInt8 *>(self + iVar23 + 0x104) = texture;
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
              texture = M<UInt8 *>(self + recordCursor[1] * 4 + 0x104);
              if ((M<SInt32>(texture + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture)),
                 M<SInt32>(texture + 4) != 0)) {
                GH_IOGetTime(texture + 0x2c);
                prevNode = M<SInt32>(texture + 0x34);
                M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
                M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
                M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
                M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
              }
              gartBlock32 = 0;
              M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
              if (M<SInt32>(texture + 4) != 0) {
                gartBlock32 = (UInt32)(M<SInt32>(texture + 4) +
                               M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4))
                         >> 5;
              }
              texture = M<UInt8 *>(self + recordCursor[2] * 4 + 0x104);
              if ((M<SInt32>(texture + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture)),
                 M<SInt32>(texture + 4) != 0)) {
                GH_IOGetTime(texture + 0x2c);
                prevNode = M<SInt32>(texture + 0x34);
                M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
                M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
                M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
                M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
              }
              textureAddress = 0;
              M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
              if (M<SInt32>(texture + 4) != 0) {
                textureAddress = M<SInt32>(texture + 4) +
                         M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4);
              }
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              *recordCursor = 0x1150;
              recordCursor[1] = gartBlock32 << 5;
              recordCursor[2] = 0x1151;
              recordCursor[3] = textureAddress + recordCursor[3] * 0x80 & 0xffffffe0;
              recordCursor[4] = 0x1393;
              recordCursor[5] = 10;
              recordCursor[6] = 0x138a;
              recordCursor[7] = M<UInt32>(surfaceInfo + 0x830) & 0xffffffe0;
              recordCursor[8] = 0x138e;
              if (M<UInt16>(surfaceInfo + 0x83e) == 0) {
                recordCursor[9] = 0x1400000;
                recordWord = recordWord & 0xffffff;
              }
              else {
                recordCursor[9] = (SInt32)((UInt32)M<UInt16>(surfaceInfo + 0x840) /
                                  (UInt32)M<UInt16>(surfaceInfo + 0x83e)) >> 1 & 0x3ffeU | 0x1400000;
                recordWord = recordWord & 0xffffff;
              }
            }
            else {
              if (uVar17 != 0x16000000) goto LAB_00039028;
              iVar12 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              uVar21 = recordCursor[1];
              uVar17 = recordCursor[4];
              iVar18 = recordCursor[2] * 0x78 + iVar12;
              iVar23 = iVar18;
              if (recordCursor[5] != 1) {
                iVar23 = recordCursor[3] * 0x78 + iVar12;
              }
              pitch = M<UInt16>(iVar18 + 0x570);
              uVar11 = (UInt32)pitch;
              uVar19 = M<UInt32>(iVar18 + 0x560);
              iVar12 = (SInt32)M<SInt16>(iVar12 + 0x9a) - (SInt32)M<SInt16>(iVar12 + 0x94);
              iVar45 = iVar12 * uVar11;
              iVar22 = uVar19 + ((UInt32)(iVar45 * 3) >> 1);
              if (recordCursor[5] != 1) {
                if (uVar21 == 2) {
                  uVar21 = (UInt32)(pitch >> 2);
                  if (uVar17 == 0) {
                    iVar25 = uVar19 + iVar45;
                    uVar33 = uVar11 + iVar45 + iVar22;
                    uVar19 = iVar25 + (UInt32)(pitch >> 1);
                    uVar17 = iVar25 + ((SInt32)(uVar11 * 3) >> 1);
                    uVar31 = iVar12 * (UInt32)M<UInt16>(iVar23 + 0x570) + M<SInt32>(iVar23 + 0x560);
                    uVar28 = M<UInt16>(iVar23 + 0x570) + uVar31;
                  }
                  else {
                    otherPitch = M<UInt16>(iVar23 + 0x570);
                    uVar19 = uVar19 + iVar45;
                    uVar33 = iVar45 + iVar22 + (UInt32)(pitch >> 1);
                    uVar17 = uVar11 + uVar19;
                    iVar12 = iVar12 * (UInt32)otherPitch + M<SInt32>(iVar23 + 0x560);
                    uVar31 = iVar12 + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                    uVar28 = iVar12 + (UInt32)(otherPitch >> 1);
                  }
                }
                else if (uVar21 == 3) {
                  uVar21 = (UInt32)(pitch >> 2);
                  if (uVar17 == 0) {
                    uVar17 = (UInt32)(iVar45 * 5) >> 2;
                    iVar45 = uVar19 + uVar17;
                    uVar33 = uVar11 + iVar22 + uVar17;
                    uVar17 = iVar45 + ((SInt32)(uVar11 * 3) >> 1);
                    uVar19 = iVar45 + (UInt32)(pitch >> 1);
                    uVar31 = (iVar12 * (UInt32)M<UInt16>(iVar23 + 0x570) * 5 >> 2) +
                             M<SInt32>(iVar23 + 0x560);
                    uVar28 = M<UInt16>(iVar23 + 0x570) + uVar31;
                  }
                  else {
                    otherPitch = M<UInt16>(iVar23 + 0x570);
                    uVar17 = (UInt32)(iVar45 * 5) >> 2;
                    uVar19 = uVar19 + uVar17;
                    uVar33 = iVar22 + uVar17 + (UInt32)(pitch >> 1);
                    uVar17 = uVar11 + uVar19;
                    iVar12 = (iVar12 * (UInt32)otherPitch * 5 >> 2) + M<SInt32>(iVar23 + 0x560);
                    uVar31 = iVar12 + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                    uVar28 = iVar12 + (UInt32)(otherPitch >> 1);
                  }
                }
                else {
                  uVar21 = pitch >> 1 & 0x7ffe;
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
                uVar21 = (UInt32)(pitch >> 2);
                if (uVar17 == 0) {
                  uVar17 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar33 = iVar45 + iVar22 + (UInt32)(pitch >> 1);
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
                uVar21 = (UInt32)(pitch >> 2);
                if (uVar17 == 0) {
                  uVar17 = (UInt32)M<UInt16>(iVar23 + 0x570);
                  uVar33 = iVar22 + ((UInt32)(iVar45 * 5) >> 2) + (UInt32)(pitch >> 1);
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
                uVar21 = pitch >> 1 & 0x7ffe;
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
              *recordCursor = 0x1150;
              uVar38 = M<UInt8>(iVar18 + 0x590) & 1;
              uVar11 = (UInt32)(M<UInt8>(iVar18 + 0x590) >> 1);
              uVar13 = (uVar11 & 3) << 3;
              uVar35 = uVar38 << 2;
              recordCursor[1] = uVar19 & 0xffffffe0 | uVar35 | uVar13;
              recordCursor[2] = 0x1151;
              uVar19 = (M<UInt8>(iVar23 + 0x590) & 1) << 2;
              uVar36 = (M<UInt8>(iVar23 + 0x590) & 6) << 2;
              recordCursor[3] = uVar28 & 0xffffffe0 | uVar19 | uVar36;
              recordCursor[4] = 0x1152;
              recordCursor[5] = uVar13 | uVar35 | uVar17 & 0xffffffe0;
              recordCursor[6] = 0x1153;
              recordCursor[7] = uVar36 | uVar19 | uVar31 & 0xffffffe0;
              recordCursor[8] = 0x1393;
              recordCursor[9] = 10;
              recordCursor[10] = 0x138a;
              recordCursor[0xb] = uVar33 & 0xffffffe0;
              recordCursor[0xc] = 0x138e;
              recordCursor[0xd] = uVar21 & 0x3ffe | uVar38 << 0x10 | (uVar11 & 3) << 0x11 |
                             (M<UInt8>(iVar18 + 0x591) & 3) << 0x13 | 0xc00000;
              recordWord = recordWord & 0xffffff;
            }
            goto LAB_0003903c;
          }
          iVar12 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
          uVar17 = recordCursor[1];
          uVar21 = recordCursor[4];
          iVar18 = recordCursor[2] * 0x78 + iVar12;
          iVar23 = iVar18;
          if (recordCursor[5] != 1) {
            iVar23 = recordCursor[3] * 0x78 + iVar12;
          }
          pitch = M<UInt16>(iVar18 + 0x570);
          uVar11 = (UInt32)pitch;
          uVar19 = M<UInt32>(iVar18 + 0x560);
          iVar45 = (SInt32)M<SInt16>(iVar12 + 0x9a) - (SInt32)M<SInt16>(iVar12 + 0x94);
          iVar22 = iVar45 * uVar11;
          iVar12 = uVar19 + ((UInt32)(iVar22 * 3) >> 1);
          if (recordCursor[5] != 1) {
            if (uVar17 == 2) {
              uVar17 = (UInt32)(pitch >> 2);
              if (uVar21 == 0) {
                iVar23 = uVar19 + iVar22;
                uVar21 = uVar11 + iVar22 + iVar12;
                uVar19 = iVar23 + (UInt32)(pitch >> 1);
                uVar28 = iVar23 + ((SInt32)(uVar11 * 3) >> 1);
              }
              else {
                uVar19 = uVar19 + iVar22;
                uVar28 = uVar11 + uVar19;
                uVar21 = iVar22 + iVar12 + (UInt32)(pitch >> 1);
              }
            }
            else if (uVar17 == 3) {
              uVar17 = (UInt32)(pitch >> 2);
              if (uVar21 == 0) {
                uVar21 = (UInt32)(iVar22 * 5) >> 2;
                iVar23 = uVar19 + uVar21;
                uVar21 = uVar11 + iVar12 + uVar21;
                uVar28 = iVar23 + ((SInt32)(uVar11 * 3) >> 1);
                uVar19 = iVar23 + (UInt32)(pitch >> 1);
              }
              else {
                uVar21 = (UInt32)(iVar22 * 5) >> 2;
                uVar19 = uVar19 + uVar21;
                uVar21 = iVar12 + uVar21 + (UInt32)(pitch >> 1);
                uVar28 = uVar11 + uVar19;
              }
            }
            else {
              uVar17 = pitch >> 1 & 0x7ffe;
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
            uVar17 = (UInt32)(pitch >> 2);
            if (uVar21 == 0) {
              uVar21 = iVar22 + iVar12 + (UInt32)(pitch >> 1);
              uVar19 = iVar45 * (UInt32)M<UInt16>(iVar23 + 0x570) + M<SInt32>(iVar23 + 0x560);
              uVar28 = M<UInt16>(iVar23 + 0x570) + uVar19;
            }
            else {
              pitch = M<UInt16>(iVar23 + 0x570);
              uVar21 = uVar11 + iVar22 + iVar12;
              iVar23 = iVar45 * (UInt32)pitch + M<SInt32>(iVar23 + 0x560);
              uVar28 = iVar23 + ((SInt32)((UInt32)pitch * 3) >> 1);
              uVar19 = iVar23 + (UInt32)(pitch >> 1);
            }
          }
          else if (uVar17 == 3) {
            uVar17 = (UInt32)(pitch >> 2);
            if (uVar21 == 0) {
              uVar21 = iVar12 + ((UInt32)(iVar22 * 5) >> 2) + (UInt32)(pitch >> 1);
              uVar19 = (iVar45 * (UInt32)M<UInt16>(iVar23 + 0x570) * 5 >> 2) +
                       M<SInt32>(iVar23 + 0x560);
              uVar28 = M<UInt16>(iVar23 + 0x570) + uVar19;
            }
            else {
              pitch = M<UInt16>(iVar23 + 0x570);
              uVar21 = uVar11 + iVar12 + ((UInt32)(iVar22 * 5) >> 2);
              iVar23 = (iVar45 * (UInt32)pitch * 5 >> 2) + M<SInt32>(iVar23 + 0x560);
              uVar28 = iVar23 + ((SInt32)((UInt32)pitch * 3) >> 1);
              uVar19 = iVar23 + (UInt32)(pitch >> 1);
            }
          }
          else {
            uVar17 = pitch >> 1 & 0x7ffe;
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
          *recordCursor = 0x1150;
          uVar33 = M<UInt8>(iVar18 + 0x590) & 1;
          uVar11 = (UInt32)(M<UInt8>(iVar18 + 0x590) >> 1);
          uVar35 = (uVar11 & 3) << 3;
          uVar31 = uVar33 << 2;
          recordCursor[1] = uVar19 & 0xffffffe0 | uVar31 | uVar35;
          recordCursor[2] = 0x1151;
          recordCursor[3] = uVar35 | uVar31 | uVar28 & 0xffffffe0;
          recordCursor[4] = 0x1393;
          recordCursor[5] = 10;
          recordCursor[6] = 0x138a;
          recordCursor[7] = uVar21 & 0xffffffe0;
          recordCursor[8] = 0x138e;
          bVar44 = M<UInt8>(iVar18 + 0x591);
          uVar17 = uVar17 & 0x3ffe | uVar33 << 0x10 | (uVar11 & 3) << 0x11;
LAB_00038870:
          recordCursor[9] = uVar17 | (bVar44 & 3) << 0x13 | 0xc00000;
        }
        else if (((uVar17 == 0x1b000000) || (uVar17 == 0x1c000000)) || (uVar17 == 0x1a000000))
        goto LAB_00037620;
        goto LAB_00039028;
      }
      iVar23 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
      uVar21 = recordCursor[1];
      uVar17 = M<UInt32>(iVar23 + 0x7b8);
      if (uVar17 != 0) {
        bVar44 = M<UInt8>(iVar23 + 0x7e8);
        pitch = M<UInt16>(iVar23 + 0x7c8);
        uVar11 = 0x80000000;
        if (bVar44 < 2) {
          uVar11 = 0;
        }
        *recordCursor = 0x1393;
        recordCursor[1] = 10;
        recordCursor[2] = 0x5c8;
        recordCursor[3] = 0x20000;
        recordCursor[4] = 0xc0069a00;
        recordCursor[5] = 0x52f036da;
        recordCursor[6] = uVar11 | uVar17 >> 10 | (pitch & 0x3fc0) << 0x10 | (bVar44 & 1) << 0x1e;
        recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
        otherPitch = M<UInt16>(iVar23 + 0x7ce);
        recordCursor[8] = CONCAT22(otherPitch,M<UInt16>(iVar23 + 0x7cc));
        recordCursor[9] = uVar21;
        recordCursor[10] = 0;
        recordCursor[0xb] = (UInt32)otherPitch | (pitch & 0xfffc) << 0xe;
LAB_00038f80:
        recordCursor[0xc] = 0xd0b;
        recordCursor[0xd] = 5;
        recordCursor[0xe] = 0x5c8;
        recordCursor[0xf] = 0x10000;
        recordWord = recordWord & 0xffffff;
        goto LAB_0003903c;
      }
LAB_00039030:
      recordWord = 0;
      pendingWords = 0;
    }
    else {
      if (uVar17 != 0x35000000) {
        if (0x35000000 < uVar17) {
          if (uVar17 == 0x3d000000) {
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            uVar38 = recordCursor[3];
            uVar33 = recordCursor[4];
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            secondBufferInfo = recordCursor[2] * 0x78 + surfaceInfo;
            local_74 = recordCursor[6];
            fieldHeight = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
            pitch = M<UInt16>(bufferInfo + 0x570);
            uVar28 = (UInt32)pitch;
            uVar31 = M<UInt32>(bufferInfo + 0x560);
            iVar45 = fieldHeight * uVar28;
            uVar35 = uVar31 + ((UInt32)(iVar45 * 3) >> 1);
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordCursor[2] = 0x80000000;
            recordCursor[3] = 0x80000000;
            recordCursor[4] = 0x80000000;
            recordCursor[5] = 0x80000000;
            recordCursor[6] = 0x80000000;
            uVar36 = (UInt32)M<UInt16>(surfaceInfo + 0x7c8);
            puVar26 = recordCursor + recordCursor[5];
            uVar17 = (UInt32)(M<UInt16>(surfaceInfo + 0x7c8) >> 1);
            local_78 = uVar17 & 0x7ffe;
            uVar21 = uVar35;
            uVar11 = uVar31;
            uVar19 = uVar35;
            if (uVar33 != 1) {
              if (uVar38 == 0) {
                uVar32 = M<UInt32>(surfaceInfo + 0x7b8);
                uVar34 = M<UInt32>(secondBufferInfo + 0x560);
                uVar19 = uVar28 + uVar35;
                uVar13 = uVar31 + uVar28;
                uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
                uVar29 = uVar32 + uVar36;
                uVar41 = uVar32;
                uVar30 = uVar34;
              }
              else {
                uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
                uVar32 = M<UInt32>(surfaceInfo + 0x7b8);
                uVar34 = M<UInt32>(secondBufferInfo + 0x560);
                uVar13 = uVar31;
                uVar41 = uVar32 + uVar36;
                uVar29 = uVar32;
                uVar21 = uVar28 + uVar35;
                uVar11 = uVar31 + uVar28;
                uVar30 = M<UInt16>(secondBufferInfo + 0x570) + uVar34;
              }
            }
            else if (uVar38 == 0) {
              uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
              uVar34 = M<UInt32>(secondBufferInfo + 0x560);
              uVar32 = M<UInt32>(surfaceInfo + 0x7b8);
              uVar13 = uVar34;
              uVar41 = uVar32 + uVar36;
              uVar29 = uVar32;
              uVar21 = uVar28 + uVar35;
              uVar11 = uVar31 + uVar28;
              uVar30 = uVar34 + M<UInt16>(secondBufferInfo + 0x570);
            }
            else {
              uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
              uVar34 = M<UInt32>(secondBufferInfo + 0x560);
              uVar32 = M<UInt32>(surfaceInfo + 0x7b8);
              uVar13 = uVar34 + M<UInt16>(secondBufferInfo + 0x570);
              uVar41 = uVar32;
              uVar29 = uVar32 + uVar36;
              uVar30 = uVar34;
              uVar19 = uVar28 + uVar35;
            }
            *puVar26 = 0x1150;
            tilingBit0 = M<UInt8>(bufferInfo + 0x590) & 1;
            tilingByte0Shifted = (UInt32)(M<UInt8>(bufferInfo + 0x590) >> 1);
            tilingBitsAt3 = (tilingByte0Shifted & 3) << 3;
            tilingBit0At2 = tilingBit0 << 2;
            puVar26[1] = uVar41 & 0xffffffe0 | tilingBit0At2 | tilingBitsAt3;
            puVar26[2] = 0x1151;
            puVar26[3] = tilingBitsAt3 | tilingBit0At2 | uVar29 & 0xffffffe0;
            puVar26[4] = 0x1152;
            puVar26[5] = tilingBitsAt3 | tilingBit0At2 | uVar13 & 0xffffffe0;
            puVar26[6] = 0x1153;
            uVar13 = (M<UInt8>(secondBufferInfo + 0x590) & 1) << 2;
            uVar29 = (M<UInt8>(secondBufferInfo + 0x590) & 6) << 2;
            puVar26[7] = uVar30 & 0xffffffe0 | uVar13 | uVar29;
            puVar26[8] = 0x1154;
            puVar26[9] = uVar29 | uVar13 | uVar11 & 0xffffffe0;
            puVar26[10] = 0x1393;
            puVar26[0xb] = 10;
            puVar26[0xc] = 0x138e;
            uVar11 = pitch >> 1 & 0x3ffe | tilingBit0 << 0x10 | (tilingByte0Shifted & 3) << 0x11 |
                     (M<UInt8>(bufferInfo + 0x591) & 3) << 0x13 | 0xc00000;
            puVar26[0xd] = uVar11;
            puVar26[0xe] = 0x138a;
            puVar26[0xf] = uVar21 & 0xffffffe0;
            puVar26[0x10] = 0x138f;
            puVar26[0x11] = uVar11;
            puVar26[0x12] = 0x138b;
            puVar26[0x13] = uVar19 & 0xffffffe0;
            puVar26[0x14] = 0x1390;
            uVar17 = uVar17 & 0x3ffe | (M<UInt8>(surfaceInfo + 0x7e8) & 1) << 0x10 |
                     (M<UInt8>(surfaceInfo + 0x7e8) & 6) << 0x10 |
                     (M<UInt8>(surfaceInfo + 0x7e9) & 3) << 0x13 | 0xc00000;
            puVar26[0x15] = uVar17;
            puVar26[0x16] = 0x138c;
            puVar26[0x17] = uVar41 & 0xffffffe0;
            puVar26 = recordCursor + local_74;
            if (uVar33 != 1) {
              if (uVar38 == 0) {
                uVar19 = iVar45 + uVar35;
                uVar35 = uVar28 + uVar19;
                uVar21 = uVar36 * fieldHeight + uVar32;
                uVar31 = uVar31 + iVar45;
                uVar34 = fieldHeight * uVar39 + uVar34;
                uVar32 = uVar36 + uVar21;
                uVar33 = uVar28 + uVar31;
              }
              else {
                uVar35 = iVar45 + uVar35;
                uVar33 = uVar31 + iVar45;
                uVar32 = uVar36 * fieldHeight + uVar32;
                uVar19 = uVar28 + uVar35;
                uVar31 = uVar28 + uVar33;
                uVar21 = uVar36 + uVar32;
                uVar34 = uVar39 + fieldHeight * uVar39 + uVar34;
              }
            }
            else if (uVar38 == 0) {
              uVar35 = iVar45 + uVar35;
              uVar19 = uVar28 + uVar35;
              uVar32 = uVar36 * fieldHeight + uVar32;
              uVar33 = fieldHeight * uVar39 + uVar34;
              uVar21 = uVar36 + uVar32;
              uVar31 = uVar28 + uVar31 + iVar45;
              uVar34 = uVar39 + uVar33;
            }
            else {
              uVar19 = iVar45 + uVar35;
              uVar35 = uVar28 + uVar19;
              uVar21 = uVar36 * fieldHeight + uVar32;
              uVar31 = uVar31 + iVar45;
              uVar34 = fieldHeight * uVar39 + uVar34;
              uVar32 = uVar36 + uVar21;
              uVar33 = uVar39 + uVar34;
            }
            *puVar26 = 0x1150;
            puVar26[1] = tilingBitsAt3 | tilingBit0At2 | uVar21 & 0xffffffe0;
            puVar26[2] = 0x1151;
            puVar26[3] = tilingBitsAt3 | tilingBit0At2 | uVar32 & 0xffffffe0;
            puVar26[4] = 0x1152;
            puVar26[5] = tilingBitsAt3 | tilingBit0At2 | uVar33 & 0xffffffe0;
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
            recordWord = recordWord & 0xffffff;
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
            uVar17 = recordCursor[4];
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            texture = M<UInt8 *>(self + recordCursor[2] * 4 + 0x104);
            fieldHeight = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
            bVar43 = recordCursor[3] != 0;
            if ((uVar17 & 2) == 0) {
              if (bVar43) {
                uVar21 = (UInt32)M<UInt16>(bufferInfo + 0x570);
                uVar11 = (fieldHeight * (UInt32)M<UInt16>(bufferInfo + 0x570) * 3 >> 1) +
                         M<SInt32>(bufferInfo + 0x560);
              }
              else {
                uVar11 = M<UInt32>(bufferInfo + 0x560);
                uVar21 = (UInt32)M<UInt16>(bufferInfo + 0x570);
              }
            }
            else {
              uVar11 = M<UInt32>(surfaceInfo + 0x998);
              uVar21 = (UInt32)M<UInt16>(bufferInfo + 0x570);
            }
joined_r0x000381c4:
            if ((uVar17 & 4) == 0) {
              if (bVar43) {
                uVar17 = fieldHeight * uVar21 + (fieldHeight * uVar21 * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
              }
              else {
                uVar17 = fieldHeight * uVar21 + M<SInt32>(bufferInfo + 0x560);
              }
            }
            else {
              uVar17 = fieldHeight * uVar21 + M<SInt32>(surfaceInfo + 0x998);
            }
            if ((M<SInt32>(texture + 4) != 0) ||
               (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture)),
               M<SInt32>(texture + 4) != 0)) {
              GH_IOGetTime(texture + 0x2c);
              prevNode = M<SInt32>(texture + 0x34);
              M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
              M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
              M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
              M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
              M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
              M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
            }
            gartBlock32 = 0;
            M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
            if (M<SInt32>(texture + 4) != 0) {
              gartBlock32 = (UInt32)(M<SInt32>(texture + 4) +
                             M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4)) >>
                       5;
            }
            *recordCursor = 0x1150;
            uVar19 = (M<UInt8>(bufferInfo + 0x590) & 1) << 2;
            uVar28 = (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
            recordCursor[1] = uVar11 & 0xffffffe0 | uVar19 | uVar28;
            recordCursor[2] = 0x1151;
            recordCursor[3] = uVar28 | uVar19 | uVar17 & 0xffffffe0;
            recordCursor[4] = 0x1393;
            recordCursor[5] = 10;
            recordCursor[6] = 0x138a;
            recordCursor[7] = gartBlock32 << 5;
            recordWord = recordWord & 0xffffff;
          }
          else if (uVar17 < 0x43000001) {
            if (uVar17 == 0x3f000000) {
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
              if (recordCursor[2] == 0) {
                uVar17 = M<UInt32>(bufferInfo + 0x560);
                pitch = M<UInt16>(bufferInfo + 0x570);
              }
              else {
                pitch = M<UInt16>(bufferInfo + 0x570);
                uVar17 = (((SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94)) *
                          (UInt32)pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
              }
              *recordCursor = 0x1150;
              recordCursor[1] = uVar17 & 0xffffffe0 | (M<UInt8>(bufferInfo + 0x590) & 1) << 2 |
                           (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
              recordCursor[2] = 0x1393;
              recordCursor[3] = 10;
              recordCursor[4] = 0x138a;
              recordCursor[5] = M<UInt32>(surfaceInfo + 0x998) & 0xffffffe0;
              recordCursor[6] = 0x138e;
              recordCursor[7] = pitch >> 2 & 0x3ffe | (M<UInt8>(surfaceInfo + 0x9c9) & 3) << 0x13 | 0xc00000;
              recordWord = recordWord & 0xffffff;
            }
            else if (uVar17 == 0x42000000) {
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
              fieldHeight = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
              if (recordCursor[2] == 0) {
                pitch = M<UInt16>(bufferInfo + 0x570);
                uVar17 = fieldHeight * (UInt32)pitch + M<SInt32>(bufferInfo + 0x560);
              }
              else {
                pitch = M<UInt16>(bufferInfo + 0x570);
                uVar17 = fieldHeight * (UInt32)pitch +
                         (fieldHeight * (UInt32)pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
              }
              *recordCursor = 0x1150;
              uVar17 = uVar17 & 0xffffffe0 | (M<UInt8>(bufferInfo + 0x590) & 1) << 2 |
                       (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
              recordCursor[1] = uVar17;
              recordCursor[2] = 0x1151;
              recordCursor[3] = uVar17;
              recordCursor[4] = 0x1393;
              recordCursor[5] = 10;
              recordCursor[6] = 0x138a;
              recordCursor[7] = fieldHeight * (UInt32)pitch + M<SInt32>(surfaceInfo + 0x998) & 0xffffffe0;
              recordCursor[8] = 0x138e;
              recordCursor[9] = pitch >> 2 & 0x3ffe | (M<UInt8>(surfaceInfo + 0x9c9) & 3) << 0x13 | 0xc00000;
              recordWord = recordWord & 0xffffff;
            }
            else {
              if (uVar17 != 0x3e000000) goto LAB_00039028;
              iVar23 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              uVar17 = recordCursor[3];
              sVar1 = M<SInt16>(iVar23 + 0x94);
              sVar2 = M<SInt16>(iVar23 + 0x9a);
              texture = M<UInt8 *>(self + recordCursor[2] * 4 + 0x104);
              iVar23 = recordCursor[1] * 0x78 + iVar23;
              if ((M<SInt32>(texture + 4) != 0) ||
                 (((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture)),
                 M<SInt32>(texture + 4) != 0)) {
                GH_IOGetTime(texture + 0x2c);
                prevNode = M<SInt32>(texture + 0x34);
                M<UInt32>(prevNode + 0x38) = M<UInt32>(texture + 0x38);
                M<SInt32>(M<SInt32>(texture + 0x38) + 0x34) = prevNode;
                M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
                M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
                M<UInt8 *>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = texture;
                M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
              }
              gartBlock32 = 0;
              M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
              if (M<SInt32>(texture + 4) != 0) {
                gartBlock32 = (UInt32)(M<SInt32>(texture + 4) +
                               M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4))
                         >> 5;
              }
              uVar28 = M<UInt32>(iVar23 + 0x560);
              uVar33 = ((SInt32)sVar2 - (SInt32)sVar1) * (UInt32)M<UInt16>(iVar23 + 0x570);
              uVar31 = uVar28 + uVar33;
              *recordCursor = 0x1150;
              uVar11 = (M<UInt8>(iVar23 + 0x590) & 1) << 2;
              uVar19 = (M<UInt8>(iVar23 + 0x590) & 6) << 2;
              recordCursor[1] = uVar28 & 0xffffffe0 | uVar11 | uVar19;
              recordCursor[2] = 0x1151;
              recordCursor[3] = uVar19 | uVar11 | uVar31 & 0xffffffe0;
              recordCursor[4] = 0x1152;
              recordCursor[5] = uVar19 | uVar11 | uVar31 + (uVar33 >> 2) & 0xffffffe0;
              recordCursor[6] = 0x1393;
              recordCursor[7] = 10;
              recordCursor[8] = 0x138a;
              recordCursor[9] = gartBlock32 << 5;
              recordCursor[10] = 0x138e;
              recordCursor[0xb] = uVar17 >> 2 & 0x3ffe | 0xd00000;
              recordWord = recordWord & 0xffffff;
            }
          }
          else {
            if (uVar17 != 0x46000000) {
              if (uVar17 == 0x47000000) {
                uVar21 = recordCursor[1];
                uVar17 = recordCursor[2];
                if (uVar21 == 0) {
                  uVar21 = 1;
                }
                else if (0xc < uVar21 - 10) goto LAB_00039030;
                if (uVar17 == 0) {
                  uVar17 = 1;
                }
                else if (0xc < uVar17 - 10) goto LAB_00039030;
                iVar23 = uVar17 * 0x78 + M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                iVar18 = uVar21 * 0x78 + M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                *recordCursor = 0x1140;
                recordCursor[1] = (M<UInt16>(iVar18 + 0xc0) >> 2) - 1;
                recordCursor[2] = 0x1150;
                recordCursor[3] = M<UInt32>(iVar18 + 0xb0) & 0xffffffe0 |
                             (M<UInt8>(iVar18 + 0xe0) & 1) << 2 |
                             (M<UInt8>(iVar18 + 0xe0) & 6) << 2;
                recordCursor[4] = 0x1393;
                recordCursor[5] = 10;
                recordCursor[6] = 0x138a;
                recordCursor[7] = M<UInt32>(iVar23 + 0xb0) & 0xffffffe0;
                recordCursor[8] = 0x138e;
                bVar44 = M<UInt8>(iVar23 + 0xe1);
                uVar17 = M<UInt16>(iVar23 + 0xc0) >> 2 & 0x3ffe |
                         (M<UInt8>(iVar23 + 0xe0) & 1) << 0x10 |
                         (M<UInt8>(iVar23 + 0xe0) & 6) << 0x10;
                goto LAB_00038870;
              }
              if (uVar17 != 0x44000000) goto LAB_00039028;
              uVar17 = recordCursor[4];
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
              texture = M<UInt8 *>(self + recordCursor[2] * 4 + 0x104);
              fieldHeight = (SInt32)M<SInt16>(surfaceInfo + 0x9a) - (SInt32)M<SInt16>(surfaceInfo + 0x94);
              bVar43 = recordCursor[3] != 0;
              if ((uVar17 & 2) == 0) {
                if (bVar43) {
                  uVar21 = (UInt32)M<UInt16>(bufferInfo + 0x570);
                  uVar11 = (fieldHeight * (UInt32)M<UInt16>(bufferInfo + 0x570) * 3 >> 1) +
                           M<SInt32>(bufferInfo + 0x560);
                }
                else {
                  uVar11 = M<UInt32>(bufferInfo + 0x560);
                  uVar21 = (UInt32)M<UInt16>(bufferInfo + 0x570);
                }
              }
              else {
                uVar11 = M<UInt32>(surfaceInfo + 0x998);
                uVar21 = (UInt32)M<UInt16>(bufferInfo + 0x570);
              }
              goto joined_r0x000381c4;
            }
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            *recordCursor = 0x1140;
            uVar17 = (UInt32)M<UInt16>(surfaceInfo + 0x136);
            if (uVar17 == 0) {
              recordCursor[1] = 0;
            }
            else {
              recordCursor[1] = M<UInt16>(surfaceInfo + 0x138) / uVar17 - 1;
            }
            recordCursor[2] = 0x1150;
            uVar28 = M<UInt8>(surfaceInfo + 0x158) & 1;
            uVar11 = M<UInt32>(surfaceInfo + 0x128) & 0xffffffe0;
            uVar21 = (UInt32)(M<UInt8>(surfaceInfo + 0x158) >> 1);
            recordCursor[3] = uVar11 | uVar28 << 2 | (uVar21 & 3) << 3;
            recordCursor[4] = 0x1141;
            uVar19 = (UInt32)M<UInt16>(surfaceInfo + 0x92e);
            if (uVar19 == 0) {
              recordCursor[5] = 0;
            }
            else {
              recordCursor[5] = M<UInt16>(surfaceInfo + 0x930) / uVar19 - 1;
            }
            recordCursor[6] = 0x1151;
            uVar35 = M<UInt8>(surfaceInfo + 0x950) & 1;
            uVar33 = M<UInt32>(surfaceInfo + 0x920) & 0xffffffe0;
            uVar31 = (UInt32)(M<UInt8>(surfaceInfo + 0x950) >> 1);
            recordCursor[7] = uVar33 | uVar35 << 2 | (uVar31 & 3) << 3;
            recordCursor[8] = 0x1393;
            recordCursor[9] = 10;
            recordCursor[10] = 0x138a;
            recordCursor[0xb] = uVar11;
            recordCursor[0xc] = 0x138e;
            uVar11 = 0;
            formatOffset = (UInt32)M<UInt8>(surfaceInfo + 0x15a) * 0x1c;
            if ((M<UInt32>(surfaceInfo + 0x15c) & 0xf00000) != 0) {
              uVar11 = (UInt32)M<UInt16>(surfaceInfo + 0x134) / (M<UInt32>(surfaceInfo + 0x15c) >> 0x14 & 0xf)
              ;
            }
            uVar36 = 0x20 / uVar17;
            if (0x20 / uVar17 <= uVar11) {
              uVar36 = uVar11;
            }
            local_60 = FormatTableLookup_0x0004d2e0(formatOffset) >> 1 & 0x1e00000 |
                       (FormatTableLookup_0x0004d2dc(formatOffset) & 0xc00) << 9 |
                       (uVar21 & 3) << 0x11 |
                       uVar28 << 0x10 | uVar36 & 0x3ffe | local_60 & 0xfe00c001;
            recordCursor[0xd] = local_60;
            recordCursor[0xe] = 0x138b;
            recordCursor[0xf] = uVar33;
            recordCursor[0x10] = 0x138f;
            uVar17 = 0;
            formatOffset = (UInt32)M<UInt8>(surfaceInfo + 0x952) * 0x1c;
            if ((M<UInt32>(surfaceInfo + 0x954) & 0xf00000) != 0) {
              uVar17 = (UInt32)M<UInt16>(surfaceInfo + 0x92c) / (M<UInt32>(surfaceInfo + 0x954) >> 0x14 & 0xf)
              ;
            }
            uVar21 = 0x20 / uVar19;
            if (0x20 / uVar19 <= uVar17) {
              uVar21 = uVar17;
            }
            local_5c = FormatTableLookup_0x0004d2e0(formatOffset) >> 1 & 0x1e00000 |
                       (FormatTableLookup_0x0004d2dc(formatOffset) & 0xc00) << 9 |
                       (uVar31 & 3) << 0x11 |
                       uVar35 << 0x10 | uVar21 & 0x3ffe | local_5c & 0xfe00c001;
            recordCursor[0x11] = local_5c;
            recordWord = recordWord & 0xffffff;
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
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500DVDContext_sharedAllocator)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + uVar17 + 0x104)));
        }
        M<UInt32>(self + uVar17 + 0x104) = 0;
      }
LAB_00039020:
      *recordCursor = 0x80000000;
LAB_00039028:
      recordWord = recordWord & 0xffffff;
    }
LAB_0003903c:
    recordCursor = recordCursor + recordWord;
    pendingWords = pendingWords + recordWord;
    if (recordWord == 0) {
      if ((pendingWords & 1) != 0) {
        *recordCursor = 0x80000000;
        recordCursor = recordCursor + 1;
        pendingWords = pendingWords + 1;
      }
      M<UInt32>(descriptorBytes) = (streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500DVDContext_commandBufferHeader) + 0x20;
      iVar23 = M<SInt32>(self + kIOATIR500DVDContext_commandBufferGartOffset);
      M<UInt32 *>(descriptorBytes + 0xc) = recordCursor;
      M<UInt32>(descriptorBytes + 8) = pendingWords;
      M<UInt32>(descriptorBytes + 4) = streamOffset + iVar23 + 0x20;
      return result;
    }
  } while( true );
}
