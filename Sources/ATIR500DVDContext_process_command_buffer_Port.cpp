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
  UInt32 firstBlockAddresses [4];
  UInt32 secondBlockAddresses [7];
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
  double zero;
  double half;
  double intToFloatBias;
  UInt32 targetWidth;
  UInt32 targetHeight;
  UInt32 targetPitch;
  UInt32 targetOffsetWord;
  SInt32 targetBuffer;
  UInt32 secondBufferPitch;
  UInt32 secondPlane0Address;
  SInt32 fieldBytes;
  SInt32 frameEndAddress;
  UInt32 texOffset0;
  UInt32 texOffset1;
  UInt32 texOffset2;
  UInt32 texOffset3;
  UInt32 texOffset4;
  UInt32 texOffset5;
  UInt32 colorOffset;
  UInt32 firstBlockOffset;
  UInt32 secondBlockOffset;
  UInt32 gartStep;
  UInt32 destBufferIndex;
  UInt32 overlayHeight;
  SInt16 overlayRight;
  SInt16 overlayLeft;
  SInt32 blockAddress;
  SInt32 blockStride;
  SInt32 destBufferInfo;
  UInt32 transferGartAddress;
  UInt32 destPitch;
  UInt32 destPlane0Address;
  UInt32 buffer17PitchBytes;
  UInt32 buffer17Address;
  UInt32 tilingBits;
  UInt32 *firstBlockWords;
  UInt32 *secondBlockWords;
  UInt32 clearByte;
  UInt32 sizeWord;
  UInt32 targetAddress;
  UInt8 tilingByte;
  UInt32 macroTileBit;
  SInt32 slotOffset;
  SInt32 previousRefCount;
  UInt32 fillValue;
  UInt32 buffer15Address;
  UInt32 buffer15PitchBytes;
  UInt32 selectFlags;
  UInt32 texOffsetWord;
  SInt16 overlayTop;
  SInt16 overlayBottom;
  UInt32 lumaBytes;
  UInt32 sourceBufferIndex;
  UInt32 targetBufferIndex;
  SInt32 targetBufferInfo;
  SInt32 sourceBufferInfo;
  
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
              targetWidth = recordCursor[3];
              targetHeight = recordCursor[4];
              targetPitch = recordCursor[5];
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
                targetOffsetWord = 0;
                M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
                if (M<SInt32>(texture + 4) != 0) {
                  targetOffsetWord = (UInt32)(M<SInt32>(texture + 4) +
                                 M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4))
                           >> 10;
                }
                targetBuffer = 0;
                targetOffsetWord = targetOffsetWord | (targetPitch & 0xff0) << 0x12;
              }
              else {
                iVar18 = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                targetBuffer = iVar18 + 0x828;
                targetOffsetWord = M<UInt32>(iVar18 + 0x830) >> 10 |
                         (M<UInt16>(iVar18 + 0x840) & 0x3fc0) << 0x10;
              }
              *recordCursor = 0x1393;
              recordCursor[1] = 10;
              recordCursor[2] = 0x5c8;
              recordCursor[3] = 0x20000;
              recordCursor[4] = 0xc0069a00;
              recordCursor[5] = 0x52f036da;
              recordCursor[6] = targetOffsetWord;
              recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
              recordCursor[8] = M<UInt32>(self + kATIR500DVDContext_scissorBottomRight);
              recordCursor[9] = 0;
              recordCursor[10] = 0;
              if ((bool)(bVar44 >> 1 & 1)) {
                recordCursor[0xb] = targetHeight | targetWidth << 0x10;
              }
              else {
                recordCursor[0xb] = M<UInt32>(targetBuffer + 0x1c);
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
                    fieldHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
                    if ((M<SInt16>(surfaceInfo + kATIR500Surface_overlayRight) != M<SInt16>(surfaceInfo + kATIR500Surface_overlayLeft)) && (fieldHeight != 0)) {
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
                      recordCursor[0xb] = M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1GpuBase) & 0xffffffe0;
                      recordCursor[0xc] = 0x138e;
                      widthUnits = 0;
                      formatOffset = (UInt32)M<UInt8>(surfaceInfo + 0x15a) * 0x1c;
                      if ((M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) & 0xf00000) != 0) {
                        widthUnits = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1Width) /
                                 (M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) >> 0x14 & 0xf);
                      }
                      pitchUnits = 0x20 / M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1BytesPerRow);
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
              recordCursor[5] = M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1GpuBase) & 0xffffffe0;
              recordCursor[6] = 0x138e;
              widthUnits = 0;
              formatOffset = (UInt32)M<UInt8>(surfaceInfo + 0x15a) * 0x1c;
              if ((M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) & 0xf00000) != 0) {
                widthUnits = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1Width) /
                         (M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) >> 0x14 & 0xf);
              }
              pitchUnits = 0x20 / M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1BytesPerRow);
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
              plane0Address = M<UInt32>(bufferInfo + 0x560);
              pitch = M<UInt16>(bufferInfo + 0x570);
              *recordCursor = 0x1087;
              recordCursor[1] = (M<UInt16>(bufferInfo + 0x576) & 0x3fff) << 2 | (UInt32)pitch << 0x11;
              recordCursor[2] = 0x1150;
              recordCursor[3] = plane0Address & 0xffffffe0;
              recordCursor[4] = 0x1393;
              recordCursor[5] = 10;
              recordCursor[6] = 0x138a;
              recordCursor[7] = plane0Address + (((SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) -
                                     (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop)) * (UInt32)pitch * 3 >> 1) &
                           0xffffffe0;
              recordCursor[8] = 0x138e;
              recordCursor[9] = pitch >> 2 & 0x3ffe | (M<UInt8>(bufferInfo + 0x590) & 1) << 0x10 |
                           (M<UInt8>(bufferInfo + 0x590) & 6) << 0x10 |
                           (M<UInt8>(bufferInfo + 0x591) & 3) << 0x13 | 0xc00000;
              zero = DOUBLE_0004c3c0;
              half = DOUBLE_0004c3b8;
              intToFloatBias = DOUBLE_0004c3a8;
              uStack_84 = pitch >> 2 ^ 0x80000000;
              local_88 = 0x43300000;
              recordCursor[0x61] =
                   FBITS((float)((((double)CONCAT44d(0x43300000,uStack_84) - DOUBLE_0004c3a8) +
                                 DOUBLE_0004c3c0) * DOUBLE_0004c3b8));
              local_80 = 0x43300000;
              uStack_7c = M<UInt16>(bufferInfo + 0x576) >> 1 ^ 0x80000000;
              recordCursor[0x62] =
                   FBITS((float)((((double)CONCAT44d(0x43300000,uStack_7c) - intToFloatBias) + zero) * half))
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
                  surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                  uVar17 = recordCursor[2];
                  uVar21 = recordCursor[3];
                  firstBlockOffset = recordCursor[6];
                  secondBlockOffset = recordCursor[7];
                  gartStep = recordCursor[8];
                  destBufferIndex = recordCursor[9];
                  uVar35 = recordCursor[10];
                  overlayRight = M<SInt16>(surfaceInfo + kATIR500Surface_overlayRight);
                  overlayLeft = M<SInt16>(surfaceInfo + kATIR500Surface_overlayLeft);
                  uVar36 = recordCursor[0xb];
                  uVar28 = recordCursor[0xc];
                  texture = M<UInt8 *>(self + recordCursor[1] * 4 + 0x104);
                  overlayHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
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
                  blockAddress = 0;
                  M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
                  if (M<SInt32>(texture + 4) != 0) {
                    blockAddress = M<SInt32>(texture + 4) +
                             M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4);
                  }
                  iVar12 = 0;
                  iVar45 = 4;
                  blockStride = (((UInt32)((SInt32)overlayRight - (SInt32)overlayLeft) >> 2 & 0x3ffffffc) + 0xff & 0xffffff00)
                           * (overlayHeight >> 4);
                  blockAddress = blockAddress + destBufferIndex * blockStride * 8;
                  do {
                    M<SInt32>((SInt32)firstBlockAddresses + iVar12) = blockAddress;
                    blockAddress = blockAddress + blockStride;
                    iVar12 = iVar12 + 4;
                    iVar45 = iVar45 + -1;
                  } while (iVar45 != 0);
                  iVar12 = 0;
                  iVar45 = 4;
                  do {
                    M<SInt32>((SInt32)secondBlockAddresses + iVar12) = blockAddress;
                    blockAddress = blockAddress + blockStride;
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
                  transferGartAddress = 0;
                  M<UInt8>(M<SInt32>(texture + 0x14) + 0x14) = 0;
                  if (M<SInt32>(texture + 4) != 0) {
                    transferGartAddress = M<SInt32>(texture + 4) +
                             M<SInt32>(texture + 0x50) + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x8a4);
                  }
                  surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                  destBufferInfo = destBufferIndex * 0x78 + surfaceInfo;
                  buffer17PitchBytes = (UInt32)M<UInt16>(surfaceInfo + 0x8b8);
                  firstBlockWords = recordCursor + firstBlockOffset;
                  destPitch = (UInt32)M<UInt16>(destBufferInfo + 0x570);
                  uVar36 = M<UInt32>(uVar36 * 0x78 + surfaceInfo + 0x560);
                  uVar30 = M<UInt32>(uVar35 * 0x78 + surfaceInfo + 0x560);
                  destPlane0Address = M<UInt32>(destBufferInfo + 0x560);
                  tilingBit0 = M<UInt8>(destBufferInfo + 0x590) & 1;
                  tilingByte0Shifted = (UInt32)(M<UInt8>(destBufferInfo + 0x590) >> 1);
                  iVar12 = overlayHeight * destPitch;
                  buffer17Address = M<UInt32>(surfaceInfo + 0x8a8);
                  tilingBits = tilingBit0 << 2 | (tilingByte0Shifted & 3) << 3;
                  firstBlockWords[-0xe] = 0x832;
                  firstBlockWords[-0xd] = transferGartAddress;
                  firstBlockWords[-0xc] = 0x833;
                  firstBlockWords[-0xb] = transferGartAddress;
                  firstBlockWords[-10] = 0x1150;
                  firstBlockWords[-9] = firstBlockAddresses[0] & 0xffffffe0 | 2;
                  firstBlockWords[-8] = 0x1151;
                  firstBlockWords[-7] = firstBlockAddresses[1] & 0xffffffe0 | 2;
                  firstBlockWords[-6] = 0x1152;
                  firstBlockWords[-5] = firstBlockAddresses[2] & 0xffffffe0 | 2;
                  firstBlockWords[-4] = 0x1153;
                  firstBlockWords[-3] = firstBlockAddresses[3] & 0xffffffe0 | 2;
                  firstBlockWords[-2] = 0x1154;
                  uVar35 = tilingBits | uVar30 & 0xffffffe0;
                  firstBlockWords[-1] = uVar35;
                  if ((uVar17 == 0) || (uVar28 != 0)) {
                    *firstBlockWords = 0x1155;
                    firstBlockWords[1] = uVar35;
                    firstBlockWords[2] = 0x1156;
                    firstBlockWords[3] = tilingBits | destPitch + uVar30 & 0xffffffe0;
                  }
                  else if (uVar21 == 0) {
                    *firstBlockWords = 0x1155;
                    firstBlockWords[1] = uVar35;
                    firstBlockWords[2] = 0x1156;
                    firstBlockWords[3] = tilingBits | destPlane0Address + destPitch & 0xffffffe0;
                  }
                  else {
                    *firstBlockWords = 0x1155;
                    firstBlockWords[1] = tilingBits | destPlane0Address & 0xffffffe0;
                    firstBlockWords[2] = 0x1156;
                    firstBlockWords[3] = tilingBits | destPitch + uVar30 & 0xffffffe0;
                  }
                  bVar43 = uVar21 == 0;
                  firstBlockWords[4] = 0x1157;
                  uVar21 = tilingBits | uVar36 & 0xffffffe0;
                  firstBlockWords[5] = uVar21;
                  firstBlockWords[6] = 0x1158;
                  firstBlockWords[7] = uVar21;
                  firstBlockWords[8] = 0x1159;
                  firstBlockWords[9] = tilingBits | destPitch + uVar36 & 0xffffffe0;
                  firstBlockWords[10] = 0x115a;
                  uVar21 = tilingBits | buffer17Address & 0xffffffe0;
                  firstBlockWords[0xb] = uVar21;
                  if (bVar43) {
                    firstBlockWords[0xc] = 0x115b;
                    firstBlockWords[0xd] = uVar21;
                    uVar21 = buffer17Address + buffer17PitchBytes & 0xffffffe0 | tilingBits;
                  }
                  else {
                    firstBlockWords[0xc] = 0x115b;
                    uVar21 = tilingBits | buffer17Address + buffer17PitchBytes & 0xffffffe0;
                    firstBlockWords[0xd] = uVar21;
                  }
                  firstBlockWords[0xe] = 0x115c;
                  firstBlockWords[0xf] = uVar21;
                  buffer17Address = buffer17Address + overlayHeight * buffer17PitchBytes;
                  secondBlockWords = recordCursor + secondBlockOffset;
                  uVar30 = iVar12 + uVar30;
                  uVar11 = destPlane0Address + iVar12;
                  secondBlockWords[-0xe] = 0x832;
                  transferGartAddress = transferGartAddress + gartStep * 4;
                  secondBlockWords[-0xd] = transferGartAddress;
                  secondBlockWords[-0xc] = 0x833;
                  secondBlockWords[-0xb] = transferGartAddress;
                  secondBlockWords[-10] = 0x1150;
                  secondBlockWords[-9] = secondBlockAddresses[0] & 0xffffffe0 | 2;
                  secondBlockWords[-8] = 0x1151;
                  secondBlockWords[-7] = secondBlockAddresses[1] & 0xffffffe0 | 2;
                  secondBlockWords[-6] = 0x1152;
                  secondBlockWords[-5] = secondBlockAddresses[2] & 0xffffffe0 | 2;
                  secondBlockWords[-4] = 0x1153;
                  secondBlockWords[-3] = secondBlockAddresses[3] & 0xffffffe0 | 2;
                  secondBlockWords[-2] = 0x1154;
                  uVar21 = tilingBits | uVar30 & 0xffffffe0;
                  secondBlockWords[-1] = uVar21;
                  if ((uVar17 == 0) || (uVar28 != 0)) {
                    *secondBlockWords = 0x1155;
                    secondBlockWords[1] = uVar21;
                    secondBlockWords[2] = 0x1156;
                    secondBlockWords[3] = tilingBits | destPitch + uVar30 & 0xffffffe0;
                  }
                  else if (bVar43) {
                    *secondBlockWords = 0x1155;
                    secondBlockWords[1] = uVar21;
                    secondBlockWords[2] = 0x1156;
                    secondBlockWords[3] = tilingBits | destPitch + uVar11 & 0xffffffe0;
                  }
                  else {
                    *secondBlockWords = 0x1155;
                    secondBlockWords[1] = tilingBits | uVar11 & 0xffffffe0;
                    secondBlockWords[2] = 0x1156;
                    secondBlockWords[3] = tilingBits | destPitch + uVar30 & 0xffffffe0;
                  }
                  secondBlockWords[4] = 0x1157;
                  uVar17 = tilingBits | iVar12 + uVar36 & 0xffffffe0;
                  secondBlockWords[5] = uVar17;
                  secondBlockWords[6] = 0x1158;
                  secondBlockWords[7] = uVar17;
                  secondBlockWords[8] = 0x1159;
                  secondBlockWords[9] = tilingBits | destPitch + iVar12 + uVar36 & 0xffffffe0;
                  secondBlockWords[10] = 0x115a;
                  uVar17 = tilingBits | buffer17Address & 0xffffffe0;
                  secondBlockWords[0xb] = uVar17;
                  if (bVar43) {
                    secondBlockWords[0xc] = 0x115b;
                    secondBlockWords[0xd] = uVar17;
                    tilingBits = buffer17PitchBytes + buffer17Address & 0xffffffe0 | tilingBits;
                  }
                  else {
                    secondBlockWords[0xc] = 0x115b;
                    tilingBits = tilingBits | buffer17PitchBytes + buffer17Address & 0xffffffe0;
                    secondBlockWords[0xd] = tilingBits;
                  }
                  secondBlockWords[0xe] = 0x115c;
                  secondBlockWords[0xf] = tilingBits;
                  puVar20 = firstBlockWords + 0x10;
                  if (firstBlockWords[0x10] != 0) {
                    bVar44 = M<UInt8>(destBufferInfo + 0x591);
                    uVar17 = firstBlockWords[0x10];
                    do {
                      *puVar20 = 0x80000000;
                      puVar20[1] = 0x80000000;
                      puVar26 = puVar20 + puVar20[1] + 2;
                      uVar21 = destPlane0Address;
                      if (puVar20[puVar20[1] + 2] != 0) {
                        uVar21 = destPlane0Address + destPitch;
                      }
                      *puVar26 = uVar21 & 0xffffffe0;
                      puVar26[1] = (tilingByte0Shifted & 3) << 0x11 | tilingBit0 << 0x10 | puVar26[1] & 0x3ffe |
                                   (bVar44 & 3) << 0x13 | 0x1200000;
                      puVar26 = puVar20 + uVar17 + 2;
                      puVar20 = puVar20 + uVar17 + 2;
                      uVar17 = *puVar26;
                    } while (*puVar26 != 0);
                  }
                  *puVar20 = 0x80000000;
                  puVar26 = secondBlockWords + 0x10;
                  if (secondBlockWords[0x10] != 0) {
                    bVar44 = M<UInt8>(destBufferInfo + 0x591);
                    uVar17 = secondBlockWords[0x10];
                    do {
                      *puVar26 = 0x80000000;
                      puVar26[1] = 0x80000000;
                      puVar16 = puVar26 + puVar26[1] + 2;
                      uVar21 = uVar11;
                      if (puVar26[puVar26[1] + 2] != 0) {
                        uVar21 = destPitch + uVar11;
                      }
                      *puVar16 = uVar21 & 0xffffffe0;
                      puVar16[1] = (tilingByte0Shifted & 3) << 0x11 | tilingBit0 << 0x10 | puVar16[1] & 0x3ffe |
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
              fieldHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
              uVar17 = recordCursor[4];
              pitch = M<UInt16>(secondBufferInfo + 0x570);
              secondBufferPitch = (UInt32)pitch;
              secondPlane0Address = M<UInt32>(secondBufferInfo + 0x560);
              fieldBytes = fieldHeight * secondBufferPitch;
              frameEndAddress = secondPlane0Address + ((UInt32)(fieldBytes * 3) >> 1);
              if (recordCursor[1] == 2) {
                if (uVar17 == 0) {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  texOffset0 = secondPlane0Address + fieldBytes;
                  colorOffset = secondBufferPitch + fieldBytes + frameEndAddress;
                  texOffset3 = fieldHeight * (UInt32)otherPitch + M<SInt32>(bufferInfo + 0x560);
                  texOffset4 = texOffset3 + (otherPitch >> 1);
                  uVar17 = fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) + M<SInt32>(surfaceInfo + 0x7b8);
                  texOffset1 = texOffset0 + (pitch >> 1);
                  texOffset2 = texOffset0 + ((SInt32)(secondBufferPitch * 3) >> 1);
                  texOffset5 = texOffset3 + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                }
                else {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  texOffset1 = secondPlane0Address + fieldBytes;
                  texOffset4 = fieldHeight * (UInt32)otherPitch + M<SInt32>(bufferInfo + 0x560);
                  uVar17 = fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) + M<SInt32>(surfaceInfo + 0x7b8) +
                           (UInt32)(M<UInt16>(surfaceInfo + 0x7c8) >> 1);
                  texOffset5 = otherPitch + texOffset4;
                  colorOffset = (UInt32)(pitch >> 1) + fieldBytes + frameEndAddress;
                  texOffset3 = texOffset4 + (otherPitch >> 1);
                  texOffset2 = secondBufferPitch + texOffset1;
                  texOffset0 = texOffset1 + (pitch >> 1);
                }
              }
              else if (recordCursor[1] == 3) {
                if (uVar17 == 0) {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  uVar17 = (UInt32)(fieldBytes * 5) >> 2;
                  texOffset0 = secondPlane0Address + uVar17;
                  texOffset3 = (fieldHeight * (UInt32)otherPitch * 5 >> 2) + M<SInt32>(bufferInfo + 0x560);
                  colorOffset = secondBufferPitch + frameEndAddress + uVar17;
                  texOffset2 = texOffset0 + ((SInt32)(secondBufferPitch * 3) >> 1);
                  texOffset4 = texOffset3 + (otherPitch >> 1);
                  uVar17 = (fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) * 5 >> 2) +
                           M<SInt32>(surfaceInfo + 0x7b8);
                  texOffset5 = texOffset3 + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                  texOffset1 = texOffset0 + (pitch >> 1);
                }
                else {
                  otherPitch = M<UInt16>(bufferInfo + 0x570);
                  texOffset0 = (UInt32)(fieldBytes * 5) >> 2;
                  texOffset1 = secondPlane0Address + texOffset0;
                  texOffset4 = (fieldHeight * (UInt32)otherPitch * 5 >> 2) + M<SInt32>(bufferInfo + 0x560);
                  uVar17 = (fieldHeight * (UInt32)M<UInt16>(surfaceInfo + 0x7c8) * 5 >> 2) +
                           M<SInt32>(surfaceInfo + 0x7b8) + (UInt32)(M<UInt16>(surfaceInfo + 0x7c8) >> 1);
                  texOffset5 = otherPitch + texOffset4;
                  colorOffset = (UInt32)(pitch >> 1) + frameEndAddress + texOffset0;
                  texOffset3 = texOffset4 + (otherPitch >> 1);
                  texOffset2 = secondBufferPitch + texOffset1;
                  texOffset0 = texOffset1 + (pitch >> 1);
                }
              }
              else if (uVar17 == 0) {
                texOffset3 = M<UInt32>(bufferInfo + 0x560);
                uVar17 = M<UInt32>(surfaceInfo + 0x7b8);
                texOffset1 = secondPlane0Address + secondBufferPitch;
                colorOffset = frameEndAddress + secondBufferPitch * 2;
                texOffset2 = secondPlane0Address + secondBufferPitch * 3;
                texOffset4 = texOffset3 + M<UInt16>(bufferInfo + 0x570);
                texOffset5 = texOffset3 + (UInt32)M<UInt16>(bufferInfo + 0x570) * 3;
                texOffset0 = secondPlane0Address;
              }
              else {
                texOffset4 = M<UInt32>(bufferInfo + 0x560);
                colorOffset = secondBufferPitch + frameEndAddress;
                texOffset2 = secondPlane0Address + secondBufferPitch * 2;
                texOffset3 = texOffset4 + M<UInt16>(bufferInfo + 0x570);
                uVar17 = (UInt32)M<UInt16>(surfaceInfo + 0x7c8) + M<SInt32>(surfaceInfo + 0x7b8);
                texOffset5 = texOffset4 + (UInt32)M<UInt16>(bufferInfo + 0x570) * 2;
                texOffset0 = secondPlane0Address + secondBufferPitch;
                texOffset1 = secondPlane0Address;
              }
              *recordCursor = 0x1150;
              tilingBit0At2 = (M<UInt8>(secondBufferInfo + 0x590) & 1) << 2;
              tilingBitsAt3 = (M<UInt8>(secondBufferInfo + 0x590) & 6) << 2;
              recordCursor[1] = texOffset0 & 0xffffffe0 | tilingBit0At2 | tilingBitsAt3;
              recordCursor[2] = 0x1151;
              recordCursor[3] = tilingBitsAt3 | tilingBit0At2 | texOffset1 & 0xffffffe0;
              recordCursor[4] = 0x1152;
              recordCursor[5] = tilingBitsAt3 | tilingBit0At2 | texOffset2 & 0xffffffe0;
              recordCursor[6] = 0x1153;
              tilingBit0At2 = (M<UInt8>(bufferInfo + 0x590) & 1) << 2;
              tilingBitsAt3 = (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
              recordCursor[7] = texOffset3 & 0xffffffe0 | tilingBit0At2 | tilingBitsAt3;
              recordCursor[8] = 0x1154;
              recordCursor[9] = tilingBitsAt3 | tilingBit0At2 | texOffset4 & 0xffffffe0;
              recordCursor[10] = 0x1155;
              recordCursor[0xb] = tilingBitsAt3 | tilingBit0At2 | texOffset5 & 0xffffffe0;
              recordCursor[0xc] = 0x1156;
              uVar17 = uVar17 & 0xffffffe0;
              recordCursor[0xd] = uVar17 | (M<UInt8>(surfaceInfo + 0x7e8) & 1) << 2 |
                             (M<UInt8>(surfaceInfo + 0x7e8) & 6) << 2;
              recordCursor[0xe] = 0x1393;
              recordCursor[0xf] = 10;
              recordCursor[0x10] = 0x138a;
              recordCursor[0x11] = colorOffset & 0xffffffe0;
              recordCursor[0x12] = 0x138b;
              recordCursor[0x13] = uVar17;
              recordCursor[0x14] = 0x138c;
              recordCursor[0x15] = colorOffset & 0xffffffe0;
              recordCursor[0x16] = 0x138d;
              recordCursor[0x17] = uVar17;
              recordWord = recordWord & 0xffffff;
            }
            goto LAB_0003903c;
          }
          if (uVar17 == 0x5000000) {
            clearByte = (UInt32)M<UInt8>((SInt32)recordCursor + 0xf);
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            overlayHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
            if (recordCursor[2] == 0) {
              targetAddress = M<UInt32>(bufferInfo + 0x560);
              pitch = M<UInt16>(bufferInfo + 0x570);
            }
            else {
              pitch = M<UInt16>(bufferInfo + 0x570);
              targetAddress = (overlayHeight * pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
            }
            tilingByte = M<UInt8>(bufferInfo + 0x590);
            macroTileBit = 0x80000000;
            if (tilingByte < 2) {
              macroTileBit = 0;
            }
            *recordCursor = 0x1393;
            recordCursor[1] = 10;
            recordCursor[2] = 0x5c8;
            recordCursor[3] = 0x20000;
            recordCursor[4] = 0xc0069a00;
            recordCursor[5] = 0x52f036da;
            recordCursor[6] = macroTileBit | targetAddress >> 10 | (pitch & 0x3fc0) << 0x10 | (tilingByte & 1) << 0x1e;
            recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
            recordCursor[8] = CONCAT22(M<UInt16>(bufferInfo + 0x576),M<UInt16>(bufferInfo + 0x574));
            recordCursor[9] = clearByte | clearByte << 0x18 | clearByte << 0x10 |
                                  clearByte << 8;   /* the byte replicated four times: clearByte holds the byte read BEFORE the packet rewrite overwrote the command (re-reading it here read the rewritten word: 0x20200020) */
            recordCursor[10] = 0;
            sizeWord = overlayHeight | (pitch & 0xfffc) << 0xe;
LAB_00037c4c:
            recordCursor[0xb] = sizeWord;
            recordCursor[0xc] = 0xd0b;
            recordCursor[0xd] = 5;
            recordCursor[0xe] = 0x5c8;
            recordCursor[0xf] = 0x10000;
            goto LAB_00039028;
          }
          if (0x5000000 < uVar17) {
            if ((uVar17 == 0x7000000) || (uVar17 == 0x8000000)) goto LAB_00039030;
            if (uVar17 != 0x6000000) goto LAB_00039028;
            clearByte = (UInt32)M<UInt8>((SInt32)recordCursor + 0xf);
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            overlayHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
            if (recordCursor[2] == 0) {
              pitch = M<UInt16>(bufferInfo + 0x570);
              targetAddress = overlayHeight * pitch + M<SInt32>(bufferInfo + 0x560);
            }
            else {
              pitch = M<UInt16>(bufferInfo + 0x570);
              targetAddress = overlayHeight * pitch + (overlayHeight * pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
            }
            tilingByte = M<UInt8>(bufferInfo + 0x590);
            macroTileBit = 0x80000000;
            if (tilingByte < 2) {
              macroTileBit = 0;
            }
            *recordCursor = 0x1393;
            recordCursor[1] = 10;
            recordCursor[2] = 0x5c8;
            recordCursor[3] = 0x20000;
            recordCursor[4] = 0xc0069a00;
            recordCursor[5] = 0x52f036da;
            recordCursor[6] = macroTileBit | targetAddress >> 10 | (pitch & 0x3fc0) << 0x10 | (tilingByte & 1) << 0x1e;
            recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
            recordCursor[8] = CONCAT22(M<UInt16>(bufferInfo + 0x576),M<UInt16>(bufferInfo + 0x574));
            recordCursor[9] = clearByte | clearByte << 0x18 | clearByte << 0x10 |
                                  clearByte << 8;   /* the byte replicated four times: clearByte holds the byte read BEFORE the packet rewrite overwrote the command (re-reading it here read the rewritten word: 0x20200020) */
            recordCursor[10] = 0;
            sizeWord = (pitch & 0xfffc) << 0xe | overlayHeight >> 1;
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
            slotOffset = (uVar17 + 0xe7000000 >> 0x18) * 4;
            if (M<UInt8 *>(self + slotOffset + 0x104) != (UInt8 *)0x0) {
              ((IOATIR500DVDContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + slotOffset + 0x104)));
              previousRefCount = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(self + slotOffset + 0x104) + 0x14) + 0x10);
              if (previousRefCount == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500DVDContext_sharedAllocator)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + slotOffset + 0x104)));
              }
              M<UInt32>(self + slotOffset + 0x104) = 0;
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
            M<UInt8 *>(self + slotOffset + 0x104) = texture;
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
      surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
      fillValue = recordCursor[1];
      buffer15Address = M<UInt32>(surfaceInfo + 0x7b8);
      if (buffer15Address != 0) {
        tilingByte = M<UInt8>(surfaceInfo + 0x7e8);
        pitch = M<UInt16>(surfaceInfo + 0x7c8);
        macroTileBit = 0x80000000;
        if (tilingByte < 2) {
          macroTileBit = 0;
        }
        *recordCursor = 0x1393;
        recordCursor[1] = 10;
        recordCursor[2] = 0x5c8;
        recordCursor[3] = 0x20000;
        recordCursor[4] = 0xc0069a00;
        recordCursor[5] = 0x52f036da;
        recordCursor[6] = macroTileBit | buffer15Address >> 10 | (pitch & 0x3fc0) << 0x10 | (tilingByte & 1) << 0x1e;
        recordCursor[7] = M<UInt32>(self + kATIR500DVDContext_scissorTopLeft);
        otherPitch = M<UInt16>(surfaceInfo + 0x7ce);
        recordCursor[8] = CONCAT22(otherPitch,M<UInt16>(surfaceInfo + 0x7cc));
        recordCursor[9] = fillValue;
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
            secondBlockOffset = recordCursor[6];
            fieldHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
            pitch = M<UInt16>(bufferInfo + 0x570);
            bufferPitch = (UInt32)pitch;
            uVar31 = M<UInt32>(bufferInfo + 0x560);
            fieldBytes = fieldHeight * bufferPitch;
            uVar35 = uVar31 + ((UInt32)(fieldBytes * 3) >> 1);
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordCursor[2] = 0x80000000;
            recordCursor[3] = 0x80000000;
            recordCursor[4] = 0x80000000;
            recordCursor[5] = 0x80000000;
            recordCursor[6] = 0x80000000;
            buffer15PitchBytes = (UInt32)M<UInt16>(surfaceInfo + 0x7c8);
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
                uVar19 = bufferPitch + uVar35;
                uVar13 = uVar31 + bufferPitch;
                uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
                uVar29 = uVar32 + buffer15PitchBytes;
                uVar41 = uVar32;
                uVar30 = uVar34;
              }
              else {
                uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
                uVar32 = M<UInt32>(surfaceInfo + 0x7b8);
                uVar34 = M<UInt32>(secondBufferInfo + 0x560);
                uVar13 = uVar31;
                uVar41 = uVar32 + buffer15PitchBytes;
                uVar29 = uVar32;
                uVar21 = bufferPitch + uVar35;
                uVar11 = uVar31 + bufferPitch;
                uVar30 = M<UInt16>(secondBufferInfo + 0x570) + uVar34;
              }
            }
            else if (uVar38 == 0) {
              uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
              uVar34 = M<UInt32>(secondBufferInfo + 0x560);
              uVar32 = M<UInt32>(surfaceInfo + 0x7b8);
              uVar13 = uVar34;
              uVar41 = uVar32 + buffer15PitchBytes;
              uVar29 = uVar32;
              uVar21 = bufferPitch + uVar35;
              uVar11 = uVar31 + bufferPitch;
              uVar30 = uVar34 + M<UInt16>(secondBufferInfo + 0x570);
            }
            else {
              uVar39 = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
              uVar34 = M<UInt32>(secondBufferInfo + 0x560);
              uVar32 = M<UInt32>(surfaceInfo + 0x7b8);
              uVar13 = uVar34 + M<UInt16>(secondBufferInfo + 0x570);
              uVar41 = uVar32;
              uVar29 = uVar32 + buffer15PitchBytes;
              uVar30 = uVar34;
              uVar19 = bufferPitch + uVar35;
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
            puVar26 = recordCursor + secondBlockOffset;
            if (uVar33 != 1) {
              if (uVar38 == 0) {
                uVar19 = fieldBytes + uVar35;
                uVar35 = bufferPitch + uVar19;
                uVar21 = buffer15PitchBytes * fieldHeight + uVar32;
                uVar31 = uVar31 + fieldBytes;
                uVar34 = fieldHeight * uVar39 + uVar34;
                uVar32 = buffer15PitchBytes + uVar21;
                uVar33 = bufferPitch + uVar31;
              }
              else {
                uVar35 = fieldBytes + uVar35;
                uVar33 = uVar31 + fieldBytes;
                uVar32 = buffer15PitchBytes * fieldHeight + uVar32;
                uVar19 = bufferPitch + uVar35;
                uVar31 = bufferPitch + uVar33;
                uVar21 = buffer15PitchBytes + uVar32;
                uVar34 = uVar39 + fieldHeight * uVar39 + uVar34;
              }
            }
            else if (uVar38 == 0) {
              uVar35 = fieldBytes + uVar35;
              uVar19 = bufferPitch + uVar35;
              uVar32 = buffer15PitchBytes * fieldHeight + uVar32;
              uVar33 = fieldHeight * uVar39 + uVar34;
              uVar21 = buffer15PitchBytes + uVar32;
              uVar31 = bufferPitch + uVar31 + fieldBytes;
              uVar34 = uVar39 + uVar33;
            }
            else {
              uVar19 = fieldBytes + uVar35;
              uVar35 = bufferPitch + uVar19;
              uVar21 = buffer15PitchBytes * fieldHeight + uVar32;
              uVar31 = uVar31 + fieldBytes;
              uVar34 = fieldHeight * uVar39 + uVar34;
              uVar32 = buffer15PitchBytes + uVar21;
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
            selectFlags = recordCursor[4];
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            texture = M<UInt8 *>(self + recordCursor[2] * 4 + 0x104);
            fieldHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
            bVar43 = recordCursor[3] != 0;
            if ((selectFlags & 2) == 0) {
              if (bVar43) {
                bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
                plane0Address = (fieldHeight * (UInt32)M<UInt16>(bufferInfo + 0x570) * 3 >> 1) +
                         M<SInt32>(bufferInfo + 0x560);
              }
              else {
                plane0Address = M<UInt32>(bufferInfo + 0x560);
                bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
              }
            }
            else {
              plane0Address = M<UInt32>(surfaceInfo + 0x998);
              bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
            }
joined_r0x000381c4:
            if ((selectFlags & 4) == 0) {
              if (bVar43) {
                plane1Address = fieldHeight * bufferPitch + (fieldHeight * bufferPitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
              }
              else {
                plane1Address = fieldHeight * bufferPitch + M<SInt32>(bufferInfo + 0x560);
              }
            }
            else {
              plane1Address = fieldHeight * bufferPitch + M<SInt32>(surfaceInfo + 0x998);
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
            tilingBit0At2 = (M<UInt8>(bufferInfo + 0x590) & 1) << 2;
            tilingBitsAt3 = (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
            recordCursor[1] = plane0Address & 0xffffffe0 | tilingBit0At2 | tilingBitsAt3;
            recordCursor[2] = 0x1151;
            recordCursor[3] = tilingBitsAt3 | tilingBit0At2 | plane1Address & 0xffffffe0;
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
                plane0Address = M<UInt32>(bufferInfo + 0x560);
                pitch = M<UInt16>(bufferInfo + 0x570);
              }
              else {
                pitch = M<UInt16>(bufferInfo + 0x570);
                plane0Address = (((SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop)) *
                          (UInt32)pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
              }
              *recordCursor = 0x1150;
              recordCursor[1] = plane0Address & 0xffffffe0 | (M<UInt8>(bufferInfo + 0x590) & 1) << 2 |
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
              fieldHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
              if (recordCursor[2] == 0) {
                pitch = M<UInt16>(bufferInfo + 0x570);
                plane0Address = fieldHeight * (UInt32)pitch + M<SInt32>(bufferInfo + 0x560);
              }
              else {
                pitch = M<UInt16>(bufferInfo + 0x570);
                plane0Address = fieldHeight * (UInt32)pitch +
                         (fieldHeight * (UInt32)pitch * 3 >> 1) + M<SInt32>(bufferInfo + 0x560);
              }
              *recordCursor = 0x1150;
              texOffsetWord = plane0Address & 0xffffffe0 | (M<UInt8>(bufferInfo + 0x590) & 1) << 2 |
                       (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
              recordCursor[1] = texOffsetWord;
              recordCursor[2] = 0x1151;
              recordCursor[3] = texOffsetWord;
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
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              targetPitch = recordCursor[3];
              overlayTop = M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
              overlayBottom = M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom);
              texture = M<UInt8 *>(self + recordCursor[2] * 4 + 0x104);
              bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
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
              plane0Address = M<UInt32>(bufferInfo + 0x560);
              lumaBytes = ((SInt32)overlayBottom - (SInt32)overlayTop) * (UInt32)M<UInt16>(bufferInfo + 0x570);
              plane1Address = plane0Address + lumaBytes;
              *recordCursor = 0x1150;
              tilingBit0At2 = (M<UInt8>(bufferInfo + 0x590) & 1) << 2;
              tilingBitsAt3 = (M<UInt8>(bufferInfo + 0x590) & 6) << 2;
              recordCursor[1] = plane0Address & 0xffffffe0 | tilingBit0At2 | tilingBitsAt3;
              recordCursor[2] = 0x1151;
              recordCursor[3] = tilingBitsAt3 | tilingBit0At2 | plane1Address & 0xffffffe0;
              recordCursor[4] = 0x1152;
              recordCursor[5] = tilingBitsAt3 | tilingBit0At2 | plane1Address + (lumaBytes >> 2) & 0xffffffe0;
              recordCursor[6] = 0x1393;
              recordCursor[7] = 10;
              recordCursor[8] = 0x138a;
              recordCursor[9] = gartBlock32 << 5;
              recordCursor[10] = 0x138e;
              recordCursor[0xb] = targetPitch >> 2 & 0x3ffe | 0xd00000;
              recordWord = recordWord & 0xffffff;
            }
          }
          else {
            if (uVar17 != 0x46000000) {
              if (uVar17 == 0x47000000) {
                sourceBufferIndex = recordCursor[1];
                targetBufferIndex = recordCursor[2];
                if (sourceBufferIndex == 0) {
                  sourceBufferIndex = 1;
                }
                else if (0xc < sourceBufferIndex - 10) goto LAB_00039030;
                if (targetBufferIndex == 0) {
                  targetBufferIndex = 1;
                }
                else if (0xc < targetBufferIndex - 10) goto LAB_00039030;
                targetBufferInfo = targetBufferIndex * 0x78 + M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                sourceBufferInfo = sourceBufferIndex * 0x78 + M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
                *recordCursor = 0x1140;
                recordCursor[1] = (M<UInt16>(sourceBufferInfo + 0xc0) >> 2) - 1;
                recordCursor[2] = 0x1150;
                recordCursor[3] = M<UInt32>(sourceBufferInfo + 0xb0) & 0xffffffe0 |
                             (M<UInt8>(sourceBufferInfo + 0xe0) & 1) << 2 |
                             (M<UInt8>(sourceBufferInfo + 0xe0) & 6) << 2;
                recordCursor[4] = 0x1393;
                recordCursor[5] = 10;
                recordCursor[6] = 0x138a;
                recordCursor[7] = M<UInt32>(targetBufferInfo + 0xb0) & 0xffffffe0;
                recordCursor[8] = 0x138e;
                bVar44 = M<UInt8>(targetBufferInfo + 0xe1);
                uVar17 = M<UInt16>(targetBufferInfo + 0xc0) >> 2 & 0x3ffe |
                         (M<UInt8>(targetBufferInfo + 0xe0) & 1) << 0x10 |
                         (M<UInt8>(targetBufferInfo + 0xe0) & 6) << 0x10;
                goto LAB_00038870;
              }
              if (uVar17 != 0x44000000) goto LAB_00039028;
              selectFlags = recordCursor[4];
              surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
              texture = M<UInt8 *>(self + recordCursor[2] * 4 + 0x104);
              fieldHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
              bVar43 = recordCursor[3] != 0;
              if ((selectFlags & 2) == 0) {
                if (bVar43) {
                  bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
                  plane0Address = (fieldHeight * (UInt32)M<UInt16>(bufferInfo + 0x570) * 3 >> 1) +
                           M<SInt32>(bufferInfo + 0x560);
                }
                else {
                  plane0Address = M<UInt32>(bufferInfo + 0x560);
                  bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
                }
              }
              else {
                plane0Address = M<UInt32>(surfaceInfo + 0x998);
                bufferPitch = (UInt32)M<UInt16>(bufferInfo + 0x570);
              }
              goto joined_r0x000381c4;
            }
            surfaceInfo = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
            *recordCursor = 0x1140;
            uVar17 = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1BytesPerRow);
            if (uVar17 == 0) {
              recordCursor[1] = 0;
            }
            else {
              recordCursor[1] = M<UInt16>(surfaceInfo + 0x138) / uVar17 - 1;
            }
            recordCursor[2] = 0x1150;
            uVar28 = M<UInt8>(surfaceInfo + 0x158) & 1;
            uVar11 = M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1GpuBase) & 0xffffffe0;
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
            if ((M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) & 0xf00000) != 0) {
              uVar11 = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1Width) / (M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) >> 0x14 & 0xf)
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
