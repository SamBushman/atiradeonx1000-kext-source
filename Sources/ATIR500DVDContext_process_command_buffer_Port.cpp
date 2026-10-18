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
  UInt32 fieldParity;
  UInt32 modeFlag;
  UInt32 secondTexOffset2;
  UInt32 bufferAddress;
  UInt32 secondTexOffset4;
  UInt32 nextFieldAddress;
  UInt32 secondColorOffset1;
  UInt32 firstColorOffset0;
  UInt32 secondTexOffset0;
  UInt32 firstColorOffset1;
  UInt32 secondColorOffset0;
  UInt32 firstTexOffset4;
  UInt32 pitchWord;
  UInt32 buffer15Base;
  UInt32 secondTexOffset1;
  UInt32 secondBufferAddress;
  UInt32 secondTexOffset3;
  UInt32 secondRowPitch;
  UInt32 firstTexOffset1;
  UInt32 secondTilingBitsAt3;
  UInt32 firstTexOffset2;
  UInt32 secondTilingBit0At2;
  UInt32 firstTexOffset0;
  UInt32 firstTexOffset3;
  UInt32 *firstBlock;
  UInt32 *secondBlock;
  UInt32 buffer15HalfPitch;
  UInt32 buffer15PitchWord;
  SInt32 boundSurface;
  SInt32 rectHeight;
  SInt32 secondFieldBase;
  SInt32 firstBufferInfo;
  SInt32 otherBufferInfo;
  SInt32 fieldEndAddress;
  SInt32 fieldSizeBytes;
  SInt32 chromaBase;
  SInt32 chromaBase2;
  UInt32 firstPitch;
  UInt32 tilingByteHalf;
  UInt32 sourceOffset0;
  UInt32 otherTilingBitZeroAt2;
  UInt32 chromaFormat;
  UInt32 colorPitch;
  UInt32 parityFlag;
  UInt32 fieldBytes5Over4;
  UInt32 otherRowPitch;
  UInt32 sourceOffset2;
  UInt32 sourceOffset1;
  UInt32 otherRowPitch2;
  UInt32 sourceOffset3;
  UInt32 otherRowPitch3;
  UInt32 destOffset;
  UInt32 tilingBitZero;
  UInt32 tilingBitsShifted3;
  UInt32 tilingBitZeroAt2;
  UInt32 otherTilingBitsShifted3;
  SInt32 fieldEndAddress17;
  SInt32 chromaBase17;
  SInt32 secondFieldBase17;
  UInt32 chromaFormat17;
  UInt32 colorPitch17;
  UInt32 colorPitchWord;
  UInt32 parityFlag17;
  UInt32 fieldBytes5Over4For17;
  UInt32 destOffset17;
  SInt32 rectHeight17;
  SInt32 fieldSizeBytes17;
  UInt32 tilingBitZero17;
  UInt32 tilingBitsShifted317;
  UInt32 tilingBitZeroAt217;
  UInt8 tilingByte1;
  
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
                        widthUnits = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1PitchPixels) /
                                 (M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) >> 0x14 & 0xf);
                      }
                      pitchUnits = 0x20 / M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1BytesPerPixel);
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
                widthUnits = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1PitchPixels) /
                         (M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) >> 0x14 & 0xf);
              }
              pitchUnits = 0x20 / M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1BytesPerPixel);
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
              boundSurface = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
              chromaFormat = recordCursor[1];
              parityFlag = recordCursor[4];
              firstBufferInfo = recordCursor[2] * 0x78 + boundSurface;
              otherBufferInfo = firstBufferInfo;
              if (recordCursor[5] != 1) {
                otherBufferInfo = recordCursor[3] * 0x78 + boundSurface;
              }
              pitch = M<UInt16>(firstBufferInfo + 0x570);
              firstPitch = (UInt32)pitch;
              sourceOffset0 = M<UInt32>(firstBufferInfo + 0x560);
              rectHeight = (SInt32)M<SInt16>(boundSurface + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(boundSurface + kATIR500Surface_overlayTop);
              fieldSizeBytes = rectHeight * firstPitch;
              fieldEndAddress = sourceOffset0 + ((UInt32)(fieldSizeBytes * 3) >> 1);
              if (recordCursor[5] != 1) {
                if (chromaFormat == 2) {
                  colorPitch = (UInt32)(pitch >> 2);
                  if (parityFlag == 0) {
                    chromaBase2 = sourceOffset0 + fieldSizeBytes;
                    destOffset = firstPitch + fieldSizeBytes + fieldEndAddress;
                    sourceOffset0 = chromaBase2 + (UInt32)(pitch >> 1);
                    sourceOffset2 = chromaBase2 + ((SInt32)(firstPitch * 3) >> 1);
                    sourceOffset3 = rectHeight * (UInt32)M<UInt16>(otherBufferInfo + 0x570) + M<SInt32>(otherBufferInfo + 0x560);
                    sourceOffset1 = M<UInt16>(otherBufferInfo + 0x570) + sourceOffset3;
                  }
                  else {
                    otherPitch = M<UInt16>(otherBufferInfo + 0x570);
                    sourceOffset0 = sourceOffset0 + fieldSizeBytes;
                    destOffset = fieldSizeBytes + fieldEndAddress + (UInt32)(pitch >> 1);
                    sourceOffset2 = firstPitch + sourceOffset0;
                    secondFieldBase = rectHeight * (UInt32)otherPitch + M<SInt32>(otherBufferInfo + 0x560);
                    sourceOffset3 = secondFieldBase + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                    sourceOffset1 = secondFieldBase + (UInt32)(otherPitch >> 1);
                  }
                }
                else if (chromaFormat == 3) {
                  colorPitch = (UInt32)(pitch >> 2);
                  if (parityFlag == 0) {
                    fieldBytes5Over4 = (UInt32)(fieldSizeBytes * 5) >> 2;
                    chromaBase = sourceOffset0 + fieldBytes5Over4;
                    destOffset = firstPitch + fieldEndAddress + fieldBytes5Over4;
                    sourceOffset2 = chromaBase + ((SInt32)(firstPitch * 3) >> 1);
                    sourceOffset0 = chromaBase + (UInt32)(pitch >> 1);
                    sourceOffset3 = (rectHeight * (UInt32)M<UInt16>(otherBufferInfo + 0x570) * 5 >> 2) +
                             M<SInt32>(otherBufferInfo + 0x560);
                    sourceOffset1 = M<UInt16>(otherBufferInfo + 0x570) + sourceOffset3;
                  }
                  else {
                    otherPitch = M<UInt16>(otherBufferInfo + 0x570);
                    fieldBytes5Over4 = (UInt32)(fieldSizeBytes * 5) >> 2;
                    sourceOffset0 = sourceOffset0 + fieldBytes5Over4;
                    destOffset = fieldEndAddress + fieldBytes5Over4 + (UInt32)(pitch >> 1);
                    sourceOffset2 = firstPitch + sourceOffset0;
                    secondFieldBase = (rectHeight * (UInt32)otherPitch * 5 >> 2) + M<SInt32>(otherBufferInfo + 0x560);
                    sourceOffset3 = secondFieldBase + ((SInt32)((UInt32)otherPitch * 3) >> 1);
                    sourceOffset1 = secondFieldBase + (UInt32)(otherPitch >> 1);
                  }
                }
                else {
                  colorPitch = pitch >> 1 & 0x7ffe;
                  if (parityFlag == 0) {
                    sourceOffset3 = M<UInt32>(otherBufferInfo + 0x560);
                    destOffset = fieldEndAddress + firstPitch * 2;
                    sourceOffset2 = sourceOffset0 + firstPitch * 3;
                    sourceOffset0 = sourceOffset0 + firstPitch;
                    sourceOffset1 = sourceOffset3 + (UInt32)M<UInt16>(otherBufferInfo + 0x570) * 2;
                  }
                  else {
                    destOffset = firstPitch + fieldEndAddress;
                    sourceOffset2 = sourceOffset0 + firstPitch * 2;
                    sourceOffset1 = M<SInt32>(otherBufferInfo + 0x560) + (UInt32)M<UInt16>(otherBufferInfo + 0x570);
                    sourceOffset3 = M<SInt32>(otherBufferInfo + 0x560) + (UInt32)M<UInt16>(otherBufferInfo + 0x570) * 3;
                  }
                }
              }
              else if (chromaFormat == 2) {
                colorPitch = (UInt32)(pitch >> 2);
                if (parityFlag == 0) {
                  otherRowPitch = (UInt32)M<UInt16>(otherBufferInfo + 0x570);
                  destOffset = fieldSizeBytes + fieldEndAddress + (UInt32)(pitch >> 1);
                  sourceOffset0 = rectHeight * otherRowPitch + M<SInt32>(otherBufferInfo + 0x560);
                  sourceOffset1 = sourceOffset0 + (M<UInt16>(otherBufferInfo + 0x570) >> 1);
                  sourceOffset3 = sourceOffset0 + ((SInt32)(otherRowPitch * 3) >> 1);
                  sourceOffset2 = otherRowPitch + sourceOffset0;
                }
                else {
                  otherRowPitch2 = (UInt32)M<UInt16>(otherBufferInfo + 0x570);
                  destOffset = firstPitch + fieldSizeBytes + fieldEndAddress;
                  sourceOffset3 = rectHeight * otherRowPitch2 + M<SInt32>(otherBufferInfo + 0x560);
                  sourceOffset0 = sourceOffset3 + (M<UInt16>(otherBufferInfo + 0x570) >> 1);
                  sourceOffset2 = sourceOffset3 + ((SInt32)(otherRowPitch2 * 3) >> 1);
                  sourceOffset1 = otherRowPitch2 + sourceOffset3;
                }
              }
              else if (chromaFormat == 3) {
                colorPitch = (UInt32)(pitch >> 2);
                if (parityFlag == 0) {
                  otherRowPitch = (UInt32)M<UInt16>(otherBufferInfo + 0x570);
                  destOffset = fieldEndAddress + ((UInt32)(fieldSizeBytes * 5) >> 2) + (UInt32)(pitch >> 1);
                  sourceOffset0 = (rectHeight * otherRowPitch * 5 >> 2) + M<SInt32>(otherBufferInfo + 0x560);
                  sourceOffset1 = sourceOffset0 + (M<UInt16>(otherBufferInfo + 0x570) >> 1);
                  sourceOffset3 = sourceOffset0 + ((SInt32)(otherRowPitch * 3) >> 1);
                  sourceOffset2 = otherRowPitch + sourceOffset0;
                }
                else {
                  otherRowPitch2 = (UInt32)M<UInt16>(otherBufferInfo + 0x570);
                  destOffset = firstPitch + fieldEndAddress + ((UInt32)(fieldSizeBytes * 5) >> 2);
                  sourceOffset3 = (rectHeight * otherRowPitch2 * 5 >> 2) + M<SInt32>(otherBufferInfo + 0x560);
                  sourceOffset0 = sourceOffset3 + (M<UInt16>(otherBufferInfo + 0x570) >> 1);
                  sourceOffset2 = sourceOffset3 + ((SInt32)(otherRowPitch2 * 3) >> 1);
                  sourceOffset1 = otherRowPitch2 + sourceOffset3;
                }
              }
              else {
                colorPitch = pitch >> 1 & 0x7ffe;
                if (parityFlag == 0) {
                  otherRowPitch3 = (UInt32)M<UInt16>(otherBufferInfo + 0x570);
                  sourceOffset0 = M<UInt32>(otherBufferInfo + 0x560);
                  destOffset = firstPitch + fieldEndAddress;
                  sourceOffset1 = sourceOffset0 + otherRowPitch3;
                  sourceOffset2 = sourceOffset0 + otherRowPitch3 * 2;
                  sourceOffset3 = sourceOffset0 + otherRowPitch3 * 3;
                }
                else {
                  otherRowPitch = (UInt32)M<UInt16>(otherBufferInfo + 0x570);
                  sourceOffset3 = M<UInt32>(otherBufferInfo + 0x560);
                  destOffset = fieldEndAddress + firstPitch * 2;
                  sourceOffset0 = sourceOffset3 + otherRowPitch;
                  sourceOffset1 = sourceOffset3 + otherRowPitch * 2;
                  sourceOffset2 = sourceOffset3 + otherRowPitch * 3;
                }
              }
              *recordCursor = 0x1150;
              tilingBitZero = M<UInt8>(firstBufferInfo + 0x590) & 1;
              tilingByteHalf = (UInt32)(M<UInt8>(firstBufferInfo + 0x590) >> 1);
              tilingBitsShifted3 = (tilingByteHalf & 3) << 3;
              tilingBitZeroAt2 = tilingBitZero << 2;
              recordCursor[1] = sourceOffset0 & 0xffffffe0 | tilingBitZeroAt2 | tilingBitsShifted3;
              recordCursor[2] = 0x1151;
              otherTilingBitZeroAt2 = (M<UInt8>(otherBufferInfo + 0x590) & 1) << 2;
              otherTilingBitsShifted3 = (M<UInt8>(otherBufferInfo + 0x590) & 6) << 2;
              recordCursor[3] = sourceOffset1 & 0xffffffe0 | otherTilingBitZeroAt2 | otherTilingBitsShifted3;
              recordCursor[4] = 0x1152;
              recordCursor[5] = tilingBitsShifted3 | tilingBitZeroAt2 | sourceOffset2 & 0xffffffe0;
              recordCursor[6] = 0x1153;
              recordCursor[7] = otherTilingBitsShifted3 | otherTilingBitZeroAt2 | sourceOffset3 & 0xffffffe0;
              recordCursor[8] = 0x1393;
              recordCursor[9] = 10;
              recordCursor[10] = 0x138a;
              recordCursor[0xb] = destOffset & 0xffffffe0;
              recordCursor[0xc] = 0x138e;
              recordCursor[0xd] = colorPitch & 0x3ffe | tilingBitZero << 0x10 | (tilingByteHalf & 3) << 0x11 |
                             (M<UInt8>(firstBufferInfo + 0x591) & 3) << 0x13 | 0xc00000;
              recordWord = recordWord & 0xffffff;
            }
            goto LAB_0003903c;
          }
          boundSurface = M<SInt32>(self + kIOATIR500DVDContext_boundSurface);
          chromaFormat17 = recordCursor[1];
          parityFlag17 = recordCursor[4];
          firstBufferInfo = recordCursor[2] * 0x78 + boundSurface;
          otherBufferInfo = firstBufferInfo;
          if (recordCursor[5] != 1) {
            otherBufferInfo = recordCursor[3] * 0x78 + boundSurface;
          }
          pitch = M<UInt16>(firstBufferInfo + 0x570);
          firstPitch = (UInt32)pitch;
          sourceOffset0 = M<UInt32>(firstBufferInfo + 0x560);
          rectHeight17 = (SInt32)M<SInt16>(boundSurface + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(boundSurface + kATIR500Surface_overlayTop);
          fieldSizeBytes17 = rectHeight17 * firstPitch;
          fieldEndAddress17 = sourceOffset0 + ((UInt32)(fieldSizeBytes17 * 3) >> 1);
          if (recordCursor[5] != 1) {
            if (chromaFormat17 == 2) {
              colorPitch17 = (UInt32)(pitch >> 2);
              if (parityFlag17 == 0) {
                chromaBase17 = sourceOffset0 + fieldSizeBytes17;
                destOffset17 = firstPitch + fieldSizeBytes17 + fieldEndAddress17;
                sourceOffset0 = chromaBase17 + (UInt32)(pitch >> 1);
                sourceOffset1 = chromaBase17 + ((SInt32)(firstPitch * 3) >> 1);
              }
              else {
                sourceOffset0 = sourceOffset0 + fieldSizeBytes17;
                sourceOffset1 = firstPitch + sourceOffset0;
                destOffset17 = fieldSizeBytes17 + fieldEndAddress17 + (UInt32)(pitch >> 1);
              }
            }
            else if (chromaFormat17 == 3) {
              colorPitch17 = (UInt32)(pitch >> 2);
              if (parityFlag17 == 0) {
                fieldBytes5Over4For17 = (UInt32)(fieldSizeBytes17 * 5) >> 2;
                chromaBase17 = sourceOffset0 + fieldBytes5Over4For17;
                destOffset17 = firstPitch + fieldEndAddress17 + fieldBytes5Over4For17;
                sourceOffset1 = chromaBase17 + ((SInt32)(firstPitch * 3) >> 1);
                sourceOffset0 = chromaBase17 + (UInt32)(pitch >> 1);
              }
              else {
                fieldBytes5Over4For17 = (UInt32)(fieldSizeBytes17 * 5) >> 2;
                sourceOffset0 = sourceOffset0 + fieldBytes5Over4For17;
                destOffset17 = fieldEndAddress17 + fieldBytes5Over4For17 + (UInt32)(pitch >> 1);
                sourceOffset1 = firstPitch + sourceOffset0;
              }
            }
            else {
              colorPitch17 = pitch >> 1 & 0x7ffe;
              if (parityFlag17 == 0) {
                destOffset17 = fieldEndAddress17 + firstPitch * 2;
                sourceOffset1 = sourceOffset0 + firstPitch * 3;
                sourceOffset0 = sourceOffset0 + firstPitch;
              }
              else {
                destOffset17 = firstPitch + fieldEndAddress17;
                sourceOffset1 = sourceOffset0 + firstPitch * 2;
              }
            }
          }
          else if (chromaFormat17 == 2) {
            colorPitch17 = (UInt32)(pitch >> 2);
            if (parityFlag17 == 0) {
              destOffset17 = fieldSizeBytes17 + fieldEndAddress17 + (UInt32)(pitch >> 1);
              sourceOffset0 = rectHeight17 * (UInt32)M<UInt16>(otherBufferInfo + 0x570) + M<SInt32>(otherBufferInfo + 0x560);
              sourceOffset1 = M<UInt16>(otherBufferInfo + 0x570) + sourceOffset0;
            }
            else {
              pitch = M<UInt16>(otherBufferInfo + 0x570);
              destOffset17 = firstPitch + fieldSizeBytes17 + fieldEndAddress17;
              secondFieldBase17 = rectHeight17 * (UInt32)pitch + M<SInt32>(otherBufferInfo + 0x560);
              sourceOffset1 = secondFieldBase17 + ((SInt32)((UInt32)pitch * 3) >> 1);
              sourceOffset0 = secondFieldBase17 + (UInt32)(pitch >> 1);
            }
          }
          else if (chromaFormat17 == 3) {
            colorPitch17 = (UInt32)(pitch >> 2);
            if (parityFlag17 == 0) {
              destOffset17 = fieldEndAddress17 + ((UInt32)(fieldSizeBytes17 * 5) >> 2) + (UInt32)(pitch >> 1);
              sourceOffset0 = (rectHeight17 * (UInt32)M<UInt16>(otherBufferInfo + 0x570) * 5 >> 2) +
                       M<SInt32>(otherBufferInfo + 0x560);
              sourceOffset1 = M<UInt16>(otherBufferInfo + 0x570) + sourceOffset0;
            }
            else {
              pitch = M<UInt16>(otherBufferInfo + 0x570);
              destOffset17 = firstPitch + fieldEndAddress17 + ((UInt32)(fieldSizeBytes17 * 5) >> 2);
              secondFieldBase17 = (rectHeight17 * (UInt32)pitch * 5 >> 2) + M<SInt32>(otherBufferInfo + 0x560);
              sourceOffset1 = secondFieldBase17 + ((SInt32)((UInt32)pitch * 3) >> 1);
              sourceOffset0 = secondFieldBase17 + (UInt32)(pitch >> 1);
            }
          }
          else {
            colorPitch17 = pitch >> 1 & 0x7ffe;
            if (parityFlag17 == 0) {
              sourceOffset0 = M<UInt32>(otherBufferInfo + 0x560);
              destOffset17 = firstPitch + fieldEndAddress17;
              sourceOffset1 = sourceOffset0 + (UInt32)M<UInt16>(otherBufferInfo + 0x570) * 2;
            }
            else {
              destOffset17 = fieldEndAddress17 + firstPitch * 2;
              sourceOffset0 = M<SInt32>(otherBufferInfo + 0x560) + (UInt32)M<UInt16>(otherBufferInfo + 0x570);
              sourceOffset1 = M<SInt32>(otherBufferInfo + 0x560) + (UInt32)M<UInt16>(otherBufferInfo + 0x570) * 3;
            }
          }
          *recordCursor = 0x1150;
          tilingBitZero17 = M<UInt8>(firstBufferInfo + 0x590) & 1;
          tilingByteHalf = (UInt32)(M<UInt8>(firstBufferInfo + 0x590) >> 1);
          tilingBitsShifted317 = (tilingByteHalf & 3) << 3;
          tilingBitZeroAt217 = tilingBitZero17 << 2;
          recordCursor[1] = sourceOffset0 & 0xffffffe0 | tilingBitZeroAt217 | tilingBitsShifted317;
          recordCursor[2] = 0x1151;
          recordCursor[3] = tilingBitsShifted317 | tilingBitZeroAt217 | sourceOffset1 & 0xffffffe0;
          recordCursor[4] = 0x1393;
          recordCursor[5] = 10;
          recordCursor[6] = 0x138a;
          recordCursor[7] = destOffset17 & 0xffffffe0;
          recordCursor[8] = 0x138e;
          tilingByte1 = M<UInt8>(firstBufferInfo + 0x591);
          colorPitchWord = colorPitch17 & 0x3ffe | tilingBitZero17 << 0x10 | (tilingByteHalf & 3) << 0x11;
LAB_00038870:
          recordCursor[9] = colorPitchWord | (tilingByte1 & 3) << 0x13 | 0xc00000;
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
            fieldParity = recordCursor[3];
            modeFlag = recordCursor[4];
            bufferInfo = recordCursor[1] * 0x78 + surfaceInfo;
            secondBufferInfo = recordCursor[2] * 0x78 + surfaceInfo;
            secondBlockOffset = recordCursor[6];
            fieldHeight = (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayBottom) - (SInt32)M<SInt16>(surfaceInfo + kATIR500Surface_overlayTop);
            pitch = M<UInt16>(bufferInfo + 0x570);
            bufferPitch = (UInt32)pitch;
            bufferAddress = M<UInt32>(bufferInfo + 0x560);
            fieldBytes = fieldHeight * bufferPitch;
            nextFieldAddress = bufferAddress + ((UInt32)(fieldBytes * 3) >> 1);
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordCursor[2] = 0x80000000;
            recordCursor[3] = 0x80000000;
            recordCursor[4] = 0x80000000;
            recordCursor[5] = 0x80000000;
            recordCursor[6] = 0x80000000;
            buffer15PitchBytes = (UInt32)M<UInt16>(surfaceInfo + 0x7c8);
            firstBlock = recordCursor + recordCursor[5];
            buffer15HalfPitch = (UInt32)(M<UInt16>(surfaceInfo + 0x7c8) >> 1);
            local_78 = buffer15HalfPitch & 0x7ffe;
            firstColorOffset0 = nextFieldAddress;
            firstTexOffset4 = bufferAddress;
            firstColorOffset1 = nextFieldAddress;
            if (modeFlag != 1) {
              if (fieldParity == 0) {
                buffer15Base = M<UInt32>(surfaceInfo + 0x7b8);
                secondBufferAddress = M<UInt32>(secondBufferInfo + 0x560);
                firstColorOffset1 = bufferPitch + nextFieldAddress;
                firstTexOffset2 = bufferAddress + bufferPitch;
                secondRowPitch = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
                firstTexOffset1 = buffer15Base + buffer15PitchBytes;
                firstTexOffset0 = buffer15Base;
                firstTexOffset3 = secondBufferAddress;
              }
              else {
                secondRowPitch = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
                buffer15Base = M<UInt32>(surfaceInfo + 0x7b8);
                secondBufferAddress = M<UInt32>(secondBufferInfo + 0x560);
                firstTexOffset2 = bufferAddress;
                firstTexOffset0 = buffer15Base + buffer15PitchBytes;
                firstTexOffset1 = buffer15Base;
                firstColorOffset0 = bufferPitch + nextFieldAddress;
                firstTexOffset4 = bufferAddress + bufferPitch;
                firstTexOffset3 = M<UInt16>(secondBufferInfo + 0x570) + secondBufferAddress;
              }
            }
            else if (fieldParity == 0) {
              secondRowPitch = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
              secondBufferAddress = M<UInt32>(secondBufferInfo + 0x560);
              buffer15Base = M<UInt32>(surfaceInfo + 0x7b8);
              firstTexOffset2 = secondBufferAddress;
              firstTexOffset0 = buffer15Base + buffer15PitchBytes;
              firstTexOffset1 = buffer15Base;
              firstColorOffset0 = bufferPitch + nextFieldAddress;
              firstTexOffset4 = bufferAddress + bufferPitch;
              firstTexOffset3 = secondBufferAddress + M<UInt16>(secondBufferInfo + 0x570);
            }
            else {
              secondRowPitch = (UInt32)M<UInt16>(secondBufferInfo + 0x570);
              secondBufferAddress = M<UInt32>(secondBufferInfo + 0x560);
              buffer15Base = M<UInt32>(surfaceInfo + 0x7b8);
              firstTexOffset2 = secondBufferAddress + M<UInt16>(secondBufferInfo + 0x570);
              firstTexOffset0 = buffer15Base;
              firstTexOffset1 = buffer15Base + buffer15PitchBytes;
              firstTexOffset3 = secondBufferAddress;
              firstColorOffset1 = bufferPitch + nextFieldAddress;
            }
            *firstBlock = 0x1150;
            tilingBit0 = M<UInt8>(bufferInfo + 0x590) & 1;
            tilingByte0Shifted = (UInt32)(M<UInt8>(bufferInfo + 0x590) >> 1);
            tilingBitsAt3 = (tilingByte0Shifted & 3) << 3;
            tilingBit0At2 = tilingBit0 << 2;
            firstBlock[1] = firstTexOffset0 & 0xffffffe0 | tilingBit0At2 | tilingBitsAt3;
            firstBlock[2] = 0x1151;
            firstBlock[3] = tilingBitsAt3 | tilingBit0At2 | firstTexOffset1 & 0xffffffe0;
            firstBlock[4] = 0x1152;
            firstBlock[5] = tilingBitsAt3 | tilingBit0At2 | firstTexOffset2 & 0xffffffe0;
            firstBlock[6] = 0x1153;
            secondTilingBit0At2 = (M<UInt8>(secondBufferInfo + 0x590) & 1) << 2;
            secondTilingBitsAt3 = (M<UInt8>(secondBufferInfo + 0x590) & 6) << 2;
            firstBlock[7] = firstTexOffset3 & 0xffffffe0 | secondTilingBit0At2 | secondTilingBitsAt3;
            firstBlock[8] = 0x1154;
            firstBlock[9] = secondTilingBitsAt3 | secondTilingBit0At2 | firstTexOffset4 & 0xffffffe0;
            firstBlock[10] = 0x1393;
            firstBlock[0xb] = 10;
            firstBlock[0xc] = 0x138e;
            pitchWord = pitch >> 1 & 0x3ffe | tilingBit0 << 0x10 | (tilingByte0Shifted & 3) << 0x11 |
                     (M<UInt8>(bufferInfo + 0x591) & 3) << 0x13 | 0xc00000;
            firstBlock[0xd] = pitchWord;
            firstBlock[0xe] = 0x138a;
            firstBlock[0xf] = firstColorOffset0 & 0xffffffe0;
            firstBlock[0x10] = 0x138f;
            firstBlock[0x11] = pitchWord;
            firstBlock[0x12] = 0x138b;
            firstBlock[0x13] = firstColorOffset1 & 0xffffffe0;
            firstBlock[0x14] = 0x1390;
            buffer15PitchWord = buffer15HalfPitch & 0x3ffe | (M<UInt8>(surfaceInfo + 0x7e8) & 1) << 0x10 |
                     (M<UInt8>(surfaceInfo + 0x7e8) & 6) << 0x10 |
                     (M<UInt8>(surfaceInfo + 0x7e9) & 3) << 0x13 | 0xc00000;
            firstBlock[0x15] = buffer15PitchWord;
            firstBlock[0x16] = 0x138c;
            firstBlock[0x17] = firstTexOffset0 & 0xffffffe0;
            secondBlock = recordCursor + secondBlockOffset;
            if (modeFlag != 1) {
              if (fieldParity == 0) {
                secondColorOffset0 = fieldBytes + nextFieldAddress;
                secondColorOffset1 = bufferPitch + secondColorOffset0;
                secondTexOffset0 = buffer15PitchBytes * fieldHeight + buffer15Base;
                secondTexOffset4 = bufferAddress + fieldBytes;
                secondTexOffset3 = fieldHeight * secondRowPitch + secondBufferAddress;
                secondTexOffset1 = buffer15PitchBytes + secondTexOffset0;
                secondTexOffset2 = bufferPitch + secondTexOffset4;
              }
              else {
                secondColorOffset1 = fieldBytes + nextFieldAddress;
                secondTexOffset2 = bufferAddress + fieldBytes;
                secondTexOffset1 = buffer15PitchBytes * fieldHeight + buffer15Base;
                secondColorOffset0 = bufferPitch + secondColorOffset1;
                secondTexOffset4 = bufferPitch + secondTexOffset2;
                secondTexOffset0 = buffer15PitchBytes + secondTexOffset1;
                secondTexOffset3 = secondRowPitch + fieldHeight * secondRowPitch + secondBufferAddress;
              }
            }
            else if (fieldParity == 0) {
              secondColorOffset1 = fieldBytes + nextFieldAddress;
              secondColorOffset0 = bufferPitch + secondColorOffset1;
              secondTexOffset1 = buffer15PitchBytes * fieldHeight + buffer15Base;
              secondTexOffset2 = fieldHeight * secondRowPitch + secondBufferAddress;
              secondTexOffset0 = buffer15PitchBytes + secondTexOffset1;
              secondTexOffset4 = bufferPitch + bufferAddress + fieldBytes;
              secondTexOffset3 = secondRowPitch + secondTexOffset2;
            }
            else {
              secondColorOffset0 = fieldBytes + nextFieldAddress;
              secondColorOffset1 = bufferPitch + secondColorOffset0;
              secondTexOffset0 = buffer15PitchBytes * fieldHeight + buffer15Base;
              secondTexOffset4 = bufferAddress + fieldBytes;
              secondTexOffset3 = fieldHeight * secondRowPitch + secondBufferAddress;
              secondTexOffset1 = buffer15PitchBytes + secondTexOffset0;
              secondTexOffset2 = secondRowPitch + secondTexOffset3;
            }
            *secondBlock = 0x1150;
            secondBlock[1] = tilingBitsAt3 | tilingBit0At2 | secondTexOffset0 & 0xffffffe0;
            secondBlock[2] = 0x1151;
            secondBlock[3] = tilingBitsAt3 | tilingBit0At2 | secondTexOffset1 & 0xffffffe0;
            secondBlock[4] = 0x1152;
            secondBlock[5] = tilingBitsAt3 | tilingBit0At2 | secondTexOffset2 & 0xffffffe0;
            secondBlock[6] = 0x1153;
            secondBlock[7] = secondTilingBitsAt3 | secondTilingBit0At2 | secondTexOffset3 & 0xffffffe0;
            secondBlock[8] = 0x1154;
            secondBlock[9] = secondTilingBitsAt3 | secondTilingBit0At2 | secondTexOffset4 & 0xffffffe0;
            secondBlock[10] = 0x1393;
            secondBlock[0xb] = 10;
            secondBlock[0xc] = 0x138e;
            secondBlock[0xd] = pitchWord;
            secondBlock[0xe] = 0x138a;
            secondBlock[0xf] = secondColorOffset0 & 0xffffffe0;
            secondBlock[0x10] = 0x138f;
            secondBlock[0x11] = pitchWord;
            secondBlock[0x12] = 0x138b;
            secondBlock[0x13] = secondColorOffset1 & 0xffffffe0;
            secondBlock[0x14] = 0x1390;
            secondBlock[0x15] = buffer15PitchWord;
            secondBlock[0x16] = 0x138c;
            secondBlock[0x17] = secondTexOffset0 & 0xffffffe0;
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
                tilingByte1 = M<UInt8>(targetBufferInfo + 0xe1);
                colorPitchWord = M<UInt16>(targetBufferInfo + 0xc0) >> 2 & 0x3ffe |
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
            uVar17 = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1BytesPerPixel);
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
              uVar11 = (UInt32)M<UInt16>(surfaceInfo + kIOATIR500Surface_buffer1PitchPixels) / (M<UInt32>(surfaceInfo + kIOATIR500Surface_buffer1TilingDegreeBits) >> 0x14 & 0xf)
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
