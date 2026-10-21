/*
 * ATIR500GLContext_process_command_buffer_Port.cpp
 *
 * ATIR500GLContext::process_command_buffer (real addr 0x2b820, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* PERF NOTE (NOT APPLIED: kept named locals). Estimated cycles rebuilt/stock: 1.10-1.17 on the short opcodes (worst 1.17: 0x09, 0x0b-0x0f, 0x39 with
 * high-bit operands); the long opcodes 0x2d/0x31/0x32/0x33/0x3f are at 1.03-1.10. Cause: the prologue saves f15-f31 where stock saves f21-f31 (about 13 extra
 * instructions per call), nop padding falls elsewhere, and the 38 float locals (srcTopF, srcMinX, scaleY, dstXMax ...) that the variable splits created keep more
 * values live than stock. Closing it: merge the float temporaries of different opcode handlers back into a few shared variables (stock reuses f0-f13);
 * the cost is losing those names, for 5-8% on a short path. Details and measurements: Tests/difftest/cycle_notes.md. */
/* real addr 0x2b820 */
IOReturn ATIR500GLContext::process_command_buffer(VendorCommandDescriptor *descriptor) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *descriptorBytes = reinterpret_cast<UInt8 *>(descriptor);

  UInt32 opcode;
  UInt32 *recordCursor;
  UInt8 cr0Bits;
  UInt32 streamOffset;
  UInt32 pendingWords;
  UInt32 reservedWords;
  UInt32 nopHeader;
  UInt32 gapWords;
  UInt8 *boundTexture;
  SInt32 *refCountPtr;
  SInt32 previousRefCount;
  UInt32 submittedWords;
  SInt32 textureOffset;
  SInt32 vertexArrayOffset;
  SInt32 accel;
  UInt8 *texture;
  UInt32 hzBlockCount;
  SInt32 hzIsPartial;
  SInt32 formatByteOffset;
  UInt32 formatFieldE0;
  UInt32 formatFieldE4;
  UInt32 hzBlockOffset;
  UInt32 widthPerSample;
  UInt32 pitchPixels;
  UInt32 maxY;
  UInt16 levelBit;
  UInt32 faceOffset;
  UInt8 *surfaceBuffer;
  UInt32 formatFieldDC;
  bool singleSample;
  SInt32 alignment;
  UInt8 *selfAlias;
  UInt16 bufferPitch;
  UInt32 formatBits3000;
  UInt32 formatBitsC00;
  UInt32 bufferHeight;
  UInt32 formatBits300;
  UInt32 bufferWidth;
  UInt32 hzBlockField;
  UInt32 queryOffset;
  UInt32 volatileState;
  UInt32 offsetWord;
  UInt32 stamp;
  UInt32 hyperzEnable;
  UInt32 zbBwCntl;
  UInt32 accelFlags;
  UInt32 wordCount;
  UInt32 attachmentId;
  UInt32 pairCount;
  UInt32 stateIndex;
  UInt32 textureUnit;
  SInt32 dataByteOffset;
  SInt32 attachment;
  SInt32 hzTotalBlocks;
  SInt32 vtable;
  SInt32 levelEntry;
  SInt32 currentTexture;
  SInt32 emittedWords;
  SInt32 nextLevel;
  SInt32 mipHeight;
  SInt32 mipOffset;
  SInt32 surfaceBase;
  SInt32 pendingBytes;
  SInt32 remainingBytes;
  UInt8 bufferFlagsOp28;
  UInt8 bufferFormatId;
  UInt8 bufferFlagsOp32;
  UInt8 bufferFormatIdOp31;
  UInt8 bufferFlags;
  bool noMacroTile;
  bool lookupFailed;
  bool addressBit1Clear;
  bool zFormatBitsClear;
  bool sampleBitsClear;
  bool noDepthFlag;
  bool usesSurfaceBuffer;
  bool heightIsAligned;
  bool flagBit1Clear;
  bool singleQuad;
  bool noSampleBits;
  UInt8 formatId;
  UInt8 indexedFlagZeroBit;
  UInt8 paramZeroBit;
  UInt8 texFormatFlags;
  double hzScaleFactor;
  double fpMagicBias;
  float srcTopF;
  float srcMinX;
  float srcMaxY;
  float bottomCand;
  float dstYMax;
  float srcLeftF;
  float clipBottom;
  float dstXMin;
  float topCand;
  float srcYAtDstMax;
  float srcMinY;
  float scaleY;
  float srcMaxX;
  float leftCand;
  float dstLeftClip;
  float invQuadWidth;
  float dstXMax;
  float clipRight;
  float invQuadHeight;
  float scaleX;
  float dstYMin;
  float subpixelScale;
  float sampleCountF;
  float dstTopF;
  float centerYF;
  float rowYF;
  float xOffsetF;
  float centerXF;
  float dstLeftF;
  float clipLeft;
  float dstRightF;
  float clipTop;
  float tileXF;
  float dstBottomF;
  float winRight;
  float dstTopClip;
  float srcXAtDstMax;
  float yOffsetF;
  SInt32 formatTableOffset;
  SInt32 sizeShiftAdjust;
  SInt32 scaledSize;
  SInt32 surfaceBufferIndex;
  SInt32 texturePtrOffset;
  SInt32 surfaceIndex;
  SInt32 pipeBlocks;
  SInt32 blockAlign;
  SInt32 mipLevelOp28;
  SInt32 levelOffset0;
  SInt32 levelEntryPtr;
  SInt32 entryByteOffset;
  SInt32 numPipesOp41;
  SInt32 scaledOffset;
  SInt32 levelOffset1Op32;
  SInt32 nextMipLevelOp33;
  SInt32 tileCol;
  SInt32 surfaceBaseAddressOp2d;
  SInt32 streamTexture;
  SInt32 sizeShiftAdjustOp2d;
  SInt32 scaledOffsetOp2d;
  SInt32 textureInfo;
  SInt32 lruPrev;
  SInt32 textureIndex;
  SInt32 renderToTexture;
  SInt32 tileRowsScale;
  SInt32 hzPartial1;
  SInt32 numPipes;
  SInt32 nextMipLevelOp28;
  SInt32 surfaceBaseAddress;
  SInt32 surfaceBufferPtr;
  SInt32 levelInfoPtr;
  SInt32 entryWordIndex;
  SInt32 unitTextureInfo;
  SInt32 hzAlignment;
  SInt32 levelIndexOffset;
  SInt32 levelEntryPtrOp44;
  SInt32 surfaceIndexOp32;
  SInt32 streamTexturePtr;
  SInt32 slotArrayOffset;
  SInt32 nextMipLevel;
  SInt32 sizeShiftAdjustOp32;
  SInt32 scaledOffsetOp32;
  SInt32 blockCount;
  SInt32 recordBytes;
  SInt32 textureCount;
  SInt32 lastTexture;
  SInt32 lastTextureAddress;
  SInt32 slotsLeft;
  SInt32 entryByteOffsetOp41;
  SInt32 textureInfoOp41;
  SInt32 levelInfoPtrOp41;
  SInt32 descriptorGartOffset;
  SInt32 slotByteOffset;
  SInt32 streamTextureSlot;
  SInt32 surfaceIndexOp28;
  SInt32 attachmentsLeft;
  SInt32 slotTexture;
  SInt32 bufferIndex;
  SInt32 bufferBase;
  SInt32 levelOffset0Op37;
  SInt32 recordGartAddress;
  SInt32 entryWordIndexOp41;
  SInt32 levelEntryPtrOp32;
  SInt32 previousPinned;
  SInt32 bufferGartBase;
  SInt32 attachmentIndex;
  SInt32 mipWidthOp2d;
  SInt32 quadWidthFixed;
  SInt32 rowOffsetY;
  SInt32 clearOffset;
  SInt32 mipLevel;
  SInt32 levelOffset1;
  SInt32 surfaceBaseAddressOp32;
  SInt32 quadWidthFixedOp2d;
  UInt8 *hzScaleBits;
  UInt8 *activeTexture;
  UInt8 *bufferMaskOut;
  UInt8 *bufferIndexOut;
  UInt8 *depthTexture;
  UInt32 texModeBits;
  UInt32 texSizeBits;
  UInt32 bufferStride;
  UInt32 vertexArrayCount;
  UInt32 fixupAddress;
  UInt32 tiledFlagBit;
  UInt32 hzBlockCount0;
  UInt32 hzRowsWord;
  UInt32 attachmentsDone;
  UInt32 slotByteOffsetUnbind;
  UInt32 tiledPatchCount;
  UInt32 maxX;
  UInt32 pipeCount;
  UInt32 pairCountOp38;
  UInt32 levelWordOp3e;
  UInt32 nopHeaderNop;
  UInt32 sampleInfo;
  UInt32 depthHandle;
  UInt32 flushedWords;
  UInt32 attachmentType;
  UInt32 attachmentSlot;
  UInt32 statusOffset;
  UInt32 mipLevelOp32;
  UInt32 levelIndexOffsetOp35;
  UInt32 recordYHi;
  UInt32 texelShift;
  UInt32 dstX;
  UInt32 srcMinXMinus1;
  UInt32 srcMinXAligned;
  UInt32 tileYLimit;
  UInt32 tileXMin;
  UInt32 tileYMin;
  UInt32 tileCount;
  UInt32 gapWordsBind;
  UInt32 heightRegWord;
  UInt8 *surfaceObject;
  UInt8 *texturePtrCursor;
  UInt8 *selectedBuffer;
  UInt8 *depthBufferOp33;
  UInt8 *unitTextureSlot;
  UInt8 *colorBuffer;
  UInt8 *attachmentBuffer;
  UInt8 *texturePtrSlot;
  UInt8 *depthBufferOp31;
  UInt8 *targetBuffer;
  UInt8 *colorBufferRecord;
  UInt8 *renderBuffer;
  UInt8 *depthBuffer;
  UInt8 *ownerSurface;
  UInt8 *currentTransferBuffer;
  UInt8 *hzTexture;
  UInt8 *unboundTexture;
  UInt8 *transferBuffer;
  SInt32 *textureRefCountPtr;
  UInt32 *patchIndexPtr;
  UInt32 *colorEntry;
  UInt32 *renderTargetEntry;
  UInt32 *resolvedEnd;
  UInt32 *tailCursor;
  UInt32 *depthEntry;
  UInt32 *quadCursor;
  UInt32 *blockCursor;
  UInt32 *tiledPatchList;
  UInt32 *contextHeader;
  UInt32 *arrayWordCursor;
  UInt32 *attachmentCursor;
  UInt32 *plainPatchCursor;
  UInt32 *tiledPatchEntry;
  UInt32 *entryCursor;
  UInt32 *stateWordCursor;
  UInt16 bytesPerPixel;
  UInt16 surfaceHeight;
  UInt16 attachmentCount;
  UInt16 hzHeight;
  UInt32 mergedYLo;
  UInt32 savedFormatRegOp2d;
  UInt32 tileXEnd;
  UInt32 heightMinus1;
  UInt32 srcBottomInt;
  UInt32 tileRows;
  UInt32 savedFormatRegOp31;
  UInt32 mergedXLo;
  UInt32 formatBitsC00Op2d;
  UInt32 textureWord68;
  UInt32 arrayTextureIndex;
  UInt32 minPitchPixels;
  UInt32 gbPipeConfig;
  UInt32 mipWidth;
  UInt32 mergedXHi;
  UInt32 widthPerSampleOp2d;
  UInt32 sampleInfoOp2d;
  UInt32 maxXOp2d;
  UInt32 bufferHeightOp2d;
  UInt32 submitStamp;
  UInt32 hzMemHandle;
  UInt32 textureWord7c;
  UInt32 tileYEnd;
  UInt32 quadY;
  UInt32 rowY;
  UInt32 colWidthLeft;
  UInt32 tileX;
  UInt32 quadWidth;
  UInt32 quadHeightFixedOp2d;
  UInt32 formatIdShifted;
  UInt32 savedFormatReg;
  UInt32 formatBits3000Op31;
  UInt32 widthPerSampleOp31;
  UInt32 recordXLo;
  UInt32 maxYOp2d;
  UInt32 mipHeightMinus1;
  UInt32 nextPendingWords;
  UInt32 vertexStreamType;
  UInt32 scissorX;
  UInt32 statePacketIndex;
  UInt32 hzBlockOffset0;
  UInt32 depthAttachment;
  UInt32 patchRecordIndex;
  UInt32 offsetInTexture;
  UInt32 queryParam1;
  UInt32 colorTargetCount;
  UInt32 hzAllocWidthOp41;
  UInt32 hzAllocHeight;
  UInt32 bufferOffset;
  UInt32 layerCount;
  UInt32 flushRegionWords;
  UInt32 savedWord2Op32;
  UInt32 baseOffset;
  UInt32 srcX;
  UInt32 alignedPitchOp33;
  UInt32 quadHeight;
  UInt32 recordYLo;
  UInt32 formatBits3000Op2d;
  UInt32 tileYStart;
  UInt32 fixupWordIndex;
  UInt32 packetWords;
  UInt32 hizEnable;
  UInt32 queryParam2;
  UInt32 bufferIndexOp40;
  UInt32 headerWord0;
  UInt32 bufferAddress;
  UInt32 flushedWordsOp31;
  UInt32 savedWord2;
  UInt32 entryCount;
  UInt32 srcY;
  UInt32 tileRow;
  UInt32 indexedFlag;
  UInt32 fixupWord3;
  UInt32 zbWordIndex;
  UInt32 headerWord1;
  UInt32 blitWidth;
  UInt32 dataCursorWords;
  UInt32 hzCtlIndex;
  UInt32 colorIndex;
  UInt32 hzAllocWidth;
  UInt32 blitHeight;
  UInt32 recordWords;
  UInt32 hzAllocHeightOp41;
  UInt32 textureHandle;
  UInt32 faceByteOffset;
  UInt32 depthTextureHandle;
  UInt32 levelWordOp41;
  UInt32 offsetsStartWord;
  UInt32 hizPacketWord;
  UInt32 vertexArrayParam;
  UInt32 arrayWord;
  UInt32 arrayAddress;
  UInt32 recordHeader;
  UInt32 texModeShifted;
  UInt32 streamTextureHandle;
  UInt32 dwordInBlock;
  UInt32 minPitchPixelsOp28;
  UInt32 addressPatchCount;
  UInt32 widthPerSampleOp40;
  UInt32 packetEndWord;
  UInt32 packetWordsOp31;
  UInt32 attachmentTypeOp32;
  UInt32 maxXOp32;
  UInt32 sampleInfoOp32;
  UInt32 mergedYHi;
  UInt32 dstY;
  UInt32 quadHeightFixed;
  UInt32 tileXStart;
  UInt32 heightRegWordOp2d;
  UInt32 texelShiftOp2d;
  UInt32 pairIndex;
  UInt32 widthPerSampleOp05;
  UInt32 alignedPitch;
  UInt32 levelWord;
  UInt32 patchWord;
  UInt32 maxYOp32;
  UInt32 recordFlags;
  UInt32 recordXHi;
  UInt32 mipLevelOp2d;
  UInt32 savedWord2Op2d;
  UInt32 rowHeightLeft;
  UInt32 colsLeft;
  UInt8 scratchArea [0x80];   /* the ATIR500SurfaceBuffer on the shipped stack (Ghidra shows 0x2c bytes here + M<UInt32>(scratchArea + 0x2c) = its +0x2c word) */
  /* #170: ONE real 0x144-byte stack object (shipped frame -0x2fc..-0x1b8): the 0x134-byte register_tracking_state
   * plus four range words at +0x134..+0x140 that restore_state_destroyed_by_pageoff hands to track_regs_written_by_pm4.
   * Ghidra split it into trackingState plus separate locals (local_2e4/local_2e0 = +0x18/+0x1c; local_1c8, local_1c4,
   * local_1c0, local_1bc = +0x134/+0x138/+0x13c/+0x140), which only works if the compiler lays those locals out
   * contiguously after the array; our gcc 4.0.1 build scatters them, so the callee read garbage ranges and ran off
   * the end of a buffer. */
  struct { register_tracking_state s; UInt32 rangeWords[4]; } trackBlk;
  register_tracking_state *trackingState = &trackBlk.s;
  UInt32 *recordPayloadEnd;
  UInt32 result;
  UInt32 *trailerLastWord;
  SInt32 dstBottomCvtLo;
  SInt32 dstRightCvtLo;
  SInt32 hzHeightSumCvtLo;
  SInt32 hzExtentCvtLo;
  UInt32 quadWidthCvtHi;
  UInt32 winBottomCvtHi;
  UInt32 winRightCvtHi;
  UInt32 winTopCvtHi;
  UInt32 winLeftCvtHi;
  SInt64 quadHeightSpill;
  SInt64 quadWidthSpill;
  UInt32 heightCvtHi;
  UInt32 widthCvtHi;
  UInt32 srcBottomIntCvtHi;
  SInt64 srcBottomSpill;
  UInt32 srcRightIntCvtHi;
  SInt64 srcRightSpill;
  SInt64 srcMinYSpill;
  SInt64 srcMinXSpill;
  UInt32 yOffsetCvtHi;
  UInt32 xOffsetCvtHi;
  UInt32 dstBottomCvtHi;
  UInt32 dstRightCvtHi;
  UInt32 dstYCvtHi;
  UInt32 dstXCvtHi;
  UInt32 sampleBitsCvtHi;
  UInt32 hzHeightSumCvtHi;
  UInt32 hzExtentCvtHi;
  UInt8 *unitBuffer;
  UInt32 depthPitchRegWord;
  UInt32 pitchRegWord;
  UInt32 rowYCvtHi;
  SInt64 quadHeightFixSpill;
  SInt64 quadWidthFixSpill;
  UInt32 tileXCvtHi;
  UInt32 quadHeightCvtHi;
  UInt32 winBottomCvtLo;
  UInt32 winRightCvtLo;
  UInt32 winTopCvtLo;
  UInt32 winLeftCvtLo;
  UInt32 heightCvtLo;
  UInt32 widthCvtLo;
  UInt32 srcBottomIntCvtLo;
  UInt32 srcRightIntCvtLo;
  UInt32 yOffsetCvtLo;
  UInt32 xOffsetCvtLo;
  UInt32 dstYCvtLo;
  UInt32 dstXCvtLo;
  UInt32 sampleBitsCvtLo;
  UInt32 rowYCvtLo;
  UInt32 tileXCvtLo;
  UInt32 quadHeightCvtLo;
  UInt32 quadWidthCvtLo;
  
  contextHeader = M<UInt32 *>(self + kIOATIR500GLContext_contextBufferHeader);
  streamOffset = 0;
  pendingWords = 0xffffffff;
  reservedWords = 0;
  M<UInt32 *>((UInt8 *)&trackBlk + 0x134) = contextHeader + 8;
  pitchRegWord = 0;
  depthPitchRegWord = 0;
  result = 0;
  M<SInt32>((UInt8 *)&trackBlk + 0x13c) = M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20;
  recordCursor = (UInt32 *)(M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x1c);
  M<UInt32 *>((UInt8 *)&trackBlk + 0x138) = M<UInt32 *>((UInt8 *)&trackBlk + 0x134) + contextHeader[5];
  M<UInt32>((UInt8 *)&trackBlk + 0x18) = this->compute_sc_hyperz_en(*contextHeader);
  M<UInt32>((UInt8 *)&trackBlk + 0x1c) = this->compute_zb_bw_cntl(contextHeader[1]);
  nextPendingWords = pendingWords;
  do {
    pendingWords = nextPendingWords;
    recordHeader = *recordCursor;
    recordWords = recordHeader & 0xffffff;
    recordBytes = recordWords * 4;
    dataCacheBlockTouch(recordCursor + recordWords);
    opcode = recordHeader & 0xff000000;
    textureUnit = (recordHeader >> 0x18) - 6;
    if (textureUnit < 0x10) {
      slotByteOffset = textureUnit * 4;
      boundTexture = M<UInt8 *>(self + slotByteOffset + 0x2a4);
      if (boundTexture != (UInt8 *)0x0) {
        ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(boundTexture));
        refCountPtr = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
        previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
        if (previousRefCount == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(boundTexture));
        }
        M<UInt32>(self + slotByteOffset + 0x2a4) = 0;
      }
      if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[1]) ||
         (texture = *(UInt8 **)
                     (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
         texture == (UInt8 *)0x0)) goto abortStreamUnreserve;
      activeTexture = texture;
      ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
      textureInfo = M<SInt32>(texture + 0x14);
      if (M<char>(textureInfo + 0x14) != '\0') {
        if (pendingWords != 0) {
          gapWordsBind = recordCursor[-1] >> 2;
          if (4 < gapWordsBind) {
            nopHeader = 0x80000000;
            if (gapWordsBind != 5) {
              nopHeader = (gapWordsBind - 6) * 0x10000 | 0xc0001000;
            }
            recordCursor[-gapWordsBind] = nopHeader;
          }
          recordCursor[-4] = 0x1393;
          recordCursor[-3] = 0;
          recordCursor[-2] = 0x5c8;
          recordCursor[-1] = 0x20000;
          M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
               pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
          M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
          submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20),
                              streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
          submittedWords = pendingWords;
          M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
          reservedWords = 0;
          pendingWords = 0;
          streamOffset = submittedWords * 4 + streamOffset;
        }
        this->alloc_and_load_texture((VendorTextureBuffer *)(texture));
        if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
          M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
          this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
        }
        if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
          ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
        }
      }
      textureWord68 = M<UInt32>(texture + 0x68);
      texModeBits = recordCursor[2] >> 0x1e;
      texModeShifted = texModeBits << 0x1e;
      M<UInt32>(texture + 0x68) = texModeShifted | textureWord68 & 0x3fffffff;
      if (texModeBits != 0) {
        formatId = M<UInt8>(recordCursor + 3);
        formatIdShifted = (UInt32)formatId << 0x16;
        M<UInt32>(texture + 0x68) = formatIdShifted | texModeShifted | textureWord68 & 0x3fffff;
        if (texModeBits == 1) {
          formatTableOffset = (UInt32)formatId * 0x1c;
          noMacroTile = (M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 0x18) == 0;
          cr0Bits = noMacroTile << 1;
          if (noMacroTile) {
            formatFieldDC = FormatTableLookup_0x0004d2dc(formatTableOffset);
            sizeShiftAdjust = 0;
          }
          else {
            formatFieldDC = FormatTableLookup_0x0004d2dc(formatTableOffset);
            sizeShiftAdjust = -(formatFieldDC >> 8 & 3);
          }
          scaledSize = (SInt32)(recordCursor[3] & 0xffffff) >> ((sizeShiftAdjust - (formatFieldDC >> 0xc & 7)) + 5 & 0x3f);
          texSizeBits = scaledSize << 5;
          if ((M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 4) != 0) {
            texSizeBits = (scaledSize << 0xc) >> 3;
          }
          M<UInt32>(texture + 0x68) =
               texSizeBits >> 5 & 0x3fffff | M<UInt32>(texture + 0x68) & 0xffc00000;
        }
        else if (texture[0x20] == 0x0) {
          ownerSurface = M<UInt8 *>(texture + 0x50);
          bufferStride = 0;
          if (ownerSurface != (UInt8 *)0x0) {
            surfaceBufferIndex = ((IOATIR500Surface *)(ownerSurface))->surface_buffer_idx_mask(M<UInt32>(texture + 0x58),(UInt32 *)&bufferMaskOut);
            bufferStride = (UInt32)M<UInt16>(M<SInt32>(ownerSurface + surfaceBufferIndex * 4 + 0xb70) + 0x14) *
                     (UInt32)M<UInt16>(M<SInt32>(ownerSurface + surfaceBufferIndex * 4 + 0xb70) + 0x16);
            if (bufferStride < 0x20) {
              bufferStride = 0x20;
            }
          }
          M<UInt32>(texture + 0x68) =
               bufferStride * (recordCursor[3] & 0xffffff) >> 5 & 0x3fffff |
               M<UInt32>(texture + 0x68) & 0xffc00000;
        }
        else {
          M<UInt32>(texture + 0x68) = recordCursor[3] & 0x3fffff | formatIdShifted | texModeShifted;
        }
      }
      textureRefCountPtr = (SInt32 *)(textureInfo + 0x10);
      M<UInt32>(texture + 0x60) = recordCursor[2] & 0x3fffffff;
      atomicAddReturningOld((SInt32 *)textureRefCountPtr, -0xffff);
      if (M<SInt32>(texture + 0x48) != 0) {
        lruPrev = M<SInt32>(texture + 0x24);
        M<UInt32>(lruPrev + 0x28) = M<UInt32>(texture + 0x28);
        M<SInt32>(M<SInt32>(texture + 0x28) + 0x24) = lruPrev;
        M<UInt32>(texture + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600);
        M<SInt32>(texture + 0x28) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
        M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600) = texture;
        M<UInt8 *>(M<SInt32>(texture + 0x24) + 0x28) = texture;
      }
      this->WriteTextureOffset(textureUnit,(UInt32 *)(recordCursor),0,(VendorTextureBuffer *)(texture));
      M<UInt8 *>(self + slotByteOffset + 0x2a4) = texture;
    }
    else if (opcode == 0x39000000) {
      vertexArrayCount = recordCursor[1];
      vertexArrayParam = recordCursor[2];
      indexedFlag = recordCursor[3];
      vertexStreamType = recordCursor[4];
      offsetsStartWord = recordCursor[5];
      dataCursorWords = recordCursor[6];
      fixupWordIndex = recordCursor[7];
      *recordCursor = 0xc0061000;
      M<UInt32>(self + kATIR500GLContext_vertexArrayParam) = vertexArrayParam;
      textureCount = indexedFlag + ((vertexArrayCount & -vertexArrayParam) - vertexArrayParam) + 1;
      cr0Bits = (textureCount == 0) << 1;
      if (textureCount != 0) {
        indexedFlagZeroBit = (indexedFlag == 0) << 1;
        textureIndex = 0;
        trailerLastWord = recordCursor + -1;
        streamTextureSlot = 0x10;
        texturePtrOffset = 0;
        clearOffset = 0x20;
        texturePtrCursor = scratchArea;
        do {
          if ((!(bool)(indexedFlagZeroBit >> 1 & 1)) && (textureIndex == textureCount + -1)) {
            streamTextureSlot = 0x20;
          }
          streamTextureHandle = M<UInt32>((SInt32)recordCursor + texturePtrOffset + 0x20);
          if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= streamTextureHandle) ||
             (streamTexturePtr = M<SInt32>(streamTextureHandle * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)), streamTexturePtr == 0))
          {
            lookupFailed = true;
            recordWords = 0;
            pendingWords = 0;
            M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) =
                 M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) - reservedWords;
            goto vertexArraysDone;
          }
          M<SInt32>(texturePtrCursor) = streamTexturePtr;
          slotArrayOffset = streamTextureSlot * 4;
          if (M<UInt8 *>(self + slotArrayOffset + 0x2a4) != (UInt8 *)0x0) {
            ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + slotArrayOffset + 0x2a4)));
            boundTexture = M<UInt8 *>(self + slotArrayOffset + 0x2a4);
            refCountPtr = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
            previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
            if (previousRefCount == 1) {
              ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(boundTexture));
            }
            M<UInt32>(self + slotArrayOffset + 0x2a4) = 0;
          }
          if (((streamTextureSlot == 0x20) &&
              (streamTexture = M<SInt32>(scratchArea + texturePtrOffset), M<char>(streamTexture + 0x20) == '\a')) &&
             (vertexStreamType != M<UInt32>(streamTexture + 100))) {
            M<UInt32>(streamTexture + 100) = vertexStreamType;
            M<UInt8>(M<SInt32>(M<SInt32>(scratchArea + texturePtrOffset) + 0x14) + 0x14) = 1;
          }
          texturePtrSlot = scratchArea + texturePtrOffset;
          ((IOATIR500GLContext *)((UInt8 *)self))->add_texture_to_stream((VendorTextureBuffer *)(M<UInt8 *>(scratchArea + texturePtrOffset)));
          if (M<char>(M<SInt32>(M<SInt32>(scratchArea + texturePtrOffset) + 0x14) + 0x14) != '\0') {
            if (pendingWords != 0) {
              gapWords = recordCursor[-1] >> 2;
              if (4 < gapWords) {
                nopHeader = 0x80000000;
                if (gapWords != 5) {
                  nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                }
                recordCursor[-gapWords] = nopHeader;
              }
              recordCursor[-4] = 0x1393;
              recordCursor[-2] = 0x5c8;
              recordCursor[-3] = 0;
              *trailerLastWord = 0x20000;
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
              submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)
                                  ,streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
              submittedWords = pendingWords;
              M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
              reservedWords = 0;
              pendingWords = 0;
              streamOffset = submittedWords * 4 + streamOffset;
            }
            this->alloc_and_load_texture((VendorTextureBuffer *)(M<UInt8 *>(texturePtrSlot)));
            if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
            }
          }
          streamTexture = M<SInt32>(texturePtrSlot);
          refCountPtr = (SInt32 *)(M<SInt32>(streamTexture + 0x14) + 0x10);
          atomicAddReturningOld((SInt32 *)refCountPtr, -0xffff);
          if (M<SInt32>(streamTexture + 0x48) != 0) {
            M<UInt32>(M<SInt32>(streamTexture + 0x24) + 0x28) = M<UInt32>(streamTexture + 0x28);
            M<UInt32>(M<SInt32>(M<SInt32>(texturePtrSlot) + 0x28) + 0x24) =
                 M<UInt32>(M<SInt32>(texturePtrSlot) + 0x24);
            M<UInt32>(M<SInt32>(texturePtrSlot) + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600);
            M<SInt32>(M<SInt32>(texturePtrSlot) + 0x28) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
            M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600) = M<UInt32>(texturePtrSlot);
            M<SInt32>(M<SInt32>(M<SInt32>(texturePtrSlot) + 0x24) + 0x28) = M<SInt32>(texturePtrSlot);
            streamTexture = M<SInt32>(texturePtrSlot);
          }
          M<SInt32>(self + slotArrayOffset + 0x2a4) = streamTexture;
          M<UInt32>((SInt32)recordCursor + clearOffset) = 0x80000000;
          textureIndex = textureIndex + 1;
          texturePtrCursor = texturePtrCursor + 4;
          clearOffset = clearOffset + 4;
          streamTextureSlot = streamTextureSlot + 1;
          texturePtrOffset = texturePtrOffset + 4;
        } while (textureCount != textureIndex);
      }
      lookupFailed = false;
vertexArraysDone:
      if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
        M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
        this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
      }
      if (!lookupFailed) {
        pairCount = vertexArrayCount + 1 >> 1;
        cr0Bits = (pairCount == 0) << 1;
        if (pairCount != 0) {
          paramZeroBit = (vertexArrayParam == 0) << 1;
          arrayTextureIndex = 0;
          arrayWordCursor = recordCursor + offsetsStartWord;
          pairIndex = 0;
          selfAlias = self;
          do {
            arrayWord = *arrayWordCursor;
            M<UInt32>(selfAlias + 0x368) = arrayWord;
            if (arrayWord == 0xffffffff) {
              dataByteOffset = dataCursorWords * 4;
              dataCursorWords = dataCursorWords + 4;
              arrayAddress = (SInt32)recordCursor +
                       M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
                       (dataByteOffset - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)) + 0x20;
            }
            else {
              arrayAddress = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(scratchArea + arrayTextureIndex * 4)),arrayWord);
            }
            recordCursor[offsetsStartWord] = arrayAddress;
            if (!(bool)(paramZeroBit >> 1 & 1)) {
              arrayTextureIndex = arrayTextureIndex + 1;
            }
            if (arrayTextureIndex == vertexArrayCount) break;
            arrayWord = arrayWordCursor[1];
            M<UInt32>(selfAlias + 0x36c) = arrayWord;
            if (arrayWord == 0xffffffff) {
              dataByteOffset = dataCursorWords * 4;
              dataCursorWords = dataCursorWords + 4;
              arrayAddress = (SInt32)recordCursor +
                       M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
                       (dataByteOffset - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)) + 0x20;
            }
            else {
              arrayAddress = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(scratchArea + arrayTextureIndex * 4)),arrayWord);
            }
            recordCursor[offsetsStartWord + 1] = arrayAddress;
            offsetsStartWord = offsetsStartWord + 3;
            if (!(bool)(paramZeroBit >> 1 & 1)) {
              arrayTextureIndex = arrayTextureIndex + 1;
            }
            pairIndex = pairIndex + 1;
            arrayWordCursor = arrayWordCursor + 3;
            selfAlias = selfAlias + 8;
          } while (pairCount != pairIndex);
        }
        if (indexedFlag != 0) {
          lastTexture = M<SInt32>(scratchArea + textureCount * 4 + -4);
          if (M<char>(lastTexture + 0x20) == '\x06') {
            lastTextureAddress = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(lastTexture + 0x50) +
                     M<SInt32>(M<SInt32>(lastTexture + 0x54) + 4);
          }
          else {
            lastTextureAddress = M<SInt32>(lastTexture + 0x48);
          }
          fixupAddress = recordCursor[fixupWordIndex + 2] + lastTextureAddress;
          addressBit1Clear = (fixupAddress & 2) == 0;
          cr0Bits = addressBit1Clear << 1;
          fixupWord3 = recordCursor[fixupWordIndex + 3];
          if ((!addressBit1Clear) && (vertexStreamType == 2)) {
            fixupWord3 = fixupWord3 + 1;
          }
          dwordInBlock = fixupAddress >> 2 & 7;
          recordCursor[fixupWordIndex + 1] = recordCursor[fixupWordIndex + 1] | dwordInBlock << 0x10;
          recordCursor[fixupWordIndex + 2] = fixupAddress & 0xffffffe3;
          recordCursor[fixupWordIndex + 3] = fixupWord3 + dwordInBlock;
        }
      }
      recordBytes = recordWords << 2;
    }
    else if (opcode == 0x2a000000) {
      switch(recordCursor[1]) {
      default:
        attachment = 1;
        break;
      case 1:
        attachment = 0;
        break;
      case 2:
        attachment = 4;
        break;
      case 3:
        attachment = 5;
        break;
      case 4:
        attachment = 6;
        break;
      case 7:
        attachment = 2;
        break;
      case 8:
        attachment = 3;
        break;
      case 10:
        attachment = 7;
        break;
      case 0xb:
        attachment = 8;
      }
      renderToTexture = M<SInt32>(self + kATIR500GLContext_renderToTexture);
      if (renderToTexture == 0) {
        mipLevel = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
        surfaceIndex = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
        nextMipLevel = mipLevel + 1;
        targetBuffer = M<UInt8 *>(attachment * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
      }
      else {
        surfaceIndex = 0;
        mipLevel = 0;
        nextMipLevel = 1;
        targetBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
      }
      widthPerSample = 0;
      if ((M<UInt32>(targetBuffer + 0x3c) & 0xf00000) != 0) {
        widthPerSample = (UInt32)M<UInt16>(targetBuffer + 0x14) / (M<UInt32>(targetBuffer + 0x3c) >> 0x14 & 0xf);
      }
      pitchPixels = 0x20 / M<UInt16>(targetBuffer + 0x16);
      if (pitchPixels <= widthPerSample) {
        pitchPixels = widthPerSample;
      }
      tiledFlagBit = 0x80000000;
      if ((UInt8)targetBuffer[0x38] < 2) {
        tiledFlagBit = 0;
      }
      *recordCursor = tiledFlagBit | M<SInt32>(targetBuffer + mipLevel * 4 + 0x40) * (UInt32)M<UInt16>(targetBuffer + 0x20)
                          + surfaceIndex * (M<SInt32>(targetBuffer + nextMipLevel * 4 + 0x40) -
                                     M<SInt32>(targetBuffer + mipLevel * 4 + 0x40)) + M<SInt32>(targetBuffer + 8)
                          >> 10 | pitchPixels * M<UInt16>(targetBuffer + 0x16) * 0x10000 & 0x3fc00000 |
                          ((UInt8)targetBuffer[0x38] & 1) << 0x1e;
      if (renderToTexture == 0) {
        targetBuffer = *(UInt8 **)
                   ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
      }
      else {
        surfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
      }
      widthPerSample = 0;
      singleSample = (M<UInt32>(targetBuffer + 0x3c) & 0xf00000) == 0;
      cr0Bits = singleSample << 1;
      if (!singleSample) {
        widthPerSample = (UInt32)M<UInt16>(targetBuffer + 0x14) / (M<UInt32>(targetBuffer + 0x3c) >> 0x14 & 0xf);
      }
      pitchPixels = 0x20 / M<UInt16>(targetBuffer + 0x16);
      if (pitchPixels <= widthPerSample) {
        pitchPixels = widthPerSample;
      }
      tiledFlagBit = 0x80000000;
      if ((UInt8)targetBuffer[0x38] < 2) {
        tiledFlagBit = 0;
      }
      recordCursor[1] = tiledFlagBit | M<SInt32>(targetBuffer + mipLevel * 4 + 0x40) *
                            (UInt32)M<UInt16>(targetBuffer + 0x20) +
                            surfaceIndex * (M<SInt32>(targetBuffer + nextMipLevel * 4 + 0x40) -
                                     M<SInt32>(targetBuffer + mipLevel * 4 + 0x40)) + M<SInt32>(targetBuffer + 8)
                            >> 10 | pitchPixels * M<UInt16>(targetBuffer + 0x16) * 0x10000 & 0x3fc00000 |
                            ((UInt8)targetBuffer[0x38] & 1) << 0x1e;
      scissorX = M<UInt32>(self + kATIR500GLContext_scissorX);
      recordCursor[2] = scissorX;
      recordCursor[3] = M<UInt32>(self + kATIR500GLContext_scissorY);
      recordCursor[4] = scissorX;
    }
    else if (opcode < 0x2a000001) {
      if (opcode != 0x1d000000) {
        if (opcode < 0x1d000001) {
          if (opcode != 0x17000000) {
            if (opcode < 0x17000001) {
              if (opcode == 0x4000000) {
                if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                  surfaceBuffer = (UInt8 *)
                            ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 0x78 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xa8);
                }
                else {
                  surfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
                }
                packetWords = recordCursor[1];
                statePacketIndex = recordCursor[2];
                *recordCursor = 0xc0011000;
                if ((M<UInt32>(surfaceBuffer + 0x28) & 0x3ff00000) == 0x3ff00000) {
                  *recordCursor = 0xc00b1000;
                }
                else {
                  hzBlockOffset = HZMEM_GetBlockOffset
                                     ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                      M<UInt32>(surfaceBuffer + 0x28),2);
                  hzBlockCount = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                               M<UInt32>(surfaceBuffer + 0x28),2);
                  zFormatBitsClear = (M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xbe8) & 0x700000) == 0;
                  cr0Bits = zFormatBitsClear << 1;
                  if ((zFormatBitsClear) || (M<SInt16>(self + kIOATIR500GLContext_colorBufferIndex) != 9)) {
                    recordCursor[0xc] = 0;
                  }
                  else {
                    recordCursor[0xc] = 0x600;
                  }
                  recordCursor[8] = hzBlockOffset;
                  accel = M<SInt32>(self + kIOATIR500GLContext_accelerator);
                  recordCursor[9] = hzBlockCount / (UInt32)(M<SInt32>(accel + kIOATIR500Accelerator_numPipes) << 4);
                  hzIsPartial = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(accel + kIOATIR500Accelerator_hzmem)),M<UInt32>(surfaceBuffer + 0x28),2)
                  ;
                  if (hzIsPartial == 0) {
                    recordCursor[0xd] = (packetWords - 2) * 0x10000 | 0xc0001000;
                  }
                  else {
                    accel = M<SInt32>(self + kIOATIR500GLContext_accelerator);
                    surfaceHeight = M<UInt16>(surfaceBuffer + 0x1e);
                    tileRowsScale = 0x10;
                    if ((M<UInt32>(accel + kIOATIR500Accelerator_gbTileConfig) & 0x10000) == 0) {
                      tileRowsScale = 0xc;
                    }
                    hzBlockCount = 0;
                    singleSample = (M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0;
                    cr0Bits = singleSample << 1;
                    if (!singleSample) {
                      hzBlockCount = (UInt32)M<UInt16>(surfaceBuffer + 0x14) /
                               (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf);
                    }
                    pitchPixels = 0x20 / M<UInt16>(surfaceBuffer + 0x16);
                    if (0x20 / M<UInt16>(surfaceBuffer + 0x16) <= hzBlockCount) {
                      pitchPixels = hzBlockCount;
                    }
                    alignment = 0x20;
                    if (M<SInt32>(accel + kIOATIR500Accelerator_numPipes) == 4) {
alignHzPitchOp04:
                      hzBlockCount = alignment * ((SInt32)(alignment + pitchPixels + -1) / alignment);
                    }
                    else {
                      alignment = M<SInt32>(accel + kIOATIR500Accelerator_numPipes) << 4;
                      cr0Bits = (alignment == 0) << 1;
                      hzBlockCount = 0;
                      if (alignment != 0) goto alignHzPitchOp04;
                    }
                    hzTotalBlocks = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(accel + kIOATIR500Accelerator_hzmem)),
                                                 M<UInt32>(surfaceBuffer + 0x28),2);
                    hzScaleFactor = DOUBLE_0004c3b8;
                    hzBlockCount = (UInt32)(hzTotalBlocks << 4) / hzBlockCount & 0xfffffff0;
                    hzExtentCvtLo = surfaceHeight + hzBlockCount;
                    recordCursor[statePacketIndex + 1] =
                         tileRowsScale * (surfaceHeight - hzBlockCount) >> 1 | recordCursor[statePacketIndex + 1] & 0xffff0000;
                    hzExtentCvtHi = 0x43300000;
                    recordCursor[statePacketIndex + 7] =
                         FBITS((float)(((double)CONCAT44d(0x43300000,hzExtentCvtLo) - DOUBLE_0004c3b0)
                                       * hzScaleFactor));
                  }
                  surfaceBuffer[0x36] = 0x1;
                }
                M<UInt32>(surfaceBuffer + 0x30) = recordCursor[6];
                vtable = M<SInt32>(self);
updateStateAfterHz:
                VCALL(vtable, 0x5a4)(self);
              }
              else if (opcode < 0x4000001) {
                if (opcode == 0x2000000) {
                  result = 3;
                }
                else if (opcode == 0x3000000) {
                  result = 2;
                }
              }
              else {
                if (opcode == 0x5000000) {
                  depthBuffer = self + kATIR500GLContext_textureDepthBuffer;
                  if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                    depthBuffer = (UInt8 *)
                              ((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xa8
                              );
                  }
                  hzBlockField = M<UInt32>(depthBuffer + 0x28);
                  hizEnable = recordCursor[1];
                  hizPacketWord = recordCursor[2];
                  zbWordIndex = recordCursor[3];
                  hzCtlIndex = recordCursor[5];
                  if (((hzBlockField & 0x3ff) == 0x3ff) || ((hzBlockField & 0xffc00) == 0xffc00)) {
                    *recordCursor = (recordCursor[4] - 2) * 0x10000 | 0xc0001000;
                    depthBuffer[0x35] = 0x0;
                    depthBuffer[0x34] = 0x0;
                  }
                  else {
                    *recordCursor = 0xc0041000;
                    hzBlockOffset0 = HZMEM_GetBlockOffset
                                       ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),hzBlockField,0);
                    hzBlockCount0 = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                                 M<UInt32>(depthBuffer + 0x28),0);
                    hzIsPartial = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                             M<UInt32>(depthBuffer + 0x28),0);
                    hzBlockOffset = HZMEM_GetBlockOffset
                                       ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                        M<UInt32>(depthBuffer + 0x28),1);
                    hzBlockCount = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                                 M<UInt32>(depthBuffer + 0x28),1);
                    hzPartial1 = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                             M<UInt32>(depthBuffer + 0x28),1);
                    pipeBlocks = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) *
                             M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb9c);
                    recordCursor[9] = hzBlockOffset0;
                    recordCursor[10] = hzBlockCount0 / (UInt32)(pipeBlocks * 0x10);
                    depthBuffer[0x34] = 0x1;
                    if (hizEnable == 0) {
                      depthBuffer[0x35] = 0x0;
                    }
                    else if ((M<UInt32>(depthBuffer + 0x28) & 0xffc00) == 0xffc00) {
                      M<UInt32>((SInt32)recordCursor + hizPacketWord) = 0xc0021000;
                      depthBuffer[0x35] = 0x0;
                    }
                    else {
                      recordCursor[hizPacketWord + 1] = hzBlockOffset;
                      recordCursor[hizPacketWord + 2] = hzBlockCount / (UInt32)(pipeBlocks * 4);
                      depthBuffer[0x35] = 0x1;
                    }
                    if ((hzIsPartial == 0) && (hzPartial1 == 0)) {
                      recordCursor[hzCtlIndex + 1] = recordCursor[hzCtlIndex + 1] & 0xffff0000;
                    }
                    else {
                      widthPerSampleOp05 = 0;
                      numPipes = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
                      hzIsPartial = (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + M<SInt32>(self + kIOATIR500GLContext_boundSurface);
                      if ((M<UInt32>(hzIsPartial + 0xe4) & 0xf00000) != 0) {
                        widthPerSampleOp05 = (UInt32)M<UInt16>(hzIsPartial + 0xbc) /
                                 (M<UInt32>(hzIsPartial + 0xe4) >> 0x14 & 0xf);
                      }
                      minPitchPixels = 0x20 / M<UInt16>(hzIsPartial + 0xbe);
                      if (minPitchPixels <= widthPerSampleOp05) {
                        minPitchPixels = widthPerSampleOp05;
                      }
                      if (numPipes == 4) {
                        hzIsPartial = 0x20;
alignHzPitchOp05:
                        alignedPitch = hzIsPartial * ((SInt32)(hzIsPartial + minPitchPixels + -1) / hzIsPartial);
                      }
                      else {
                        hzIsPartial = numPipes << 4;
                        alignedPitch = 0;
                        if (hzIsPartial != 0) goto alignHzPitchOp05;
                      }
                      bufferHeight = (UInt32)M<UInt16>(depthBuffer + 0x1e);
                      gbPipeConfig = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74) >> 4 & 3;
                      hzIsPartial = gbPipeConfig * 0x10;
                      blockAlign = hzIsPartial;
                      if (numPipes == 4) {
                        blockAlign = gbPipeConfig << 5;
                      }
                      if (hzBlockCount < hzBlockCount0) {
                        hzBlockCount0 = hzBlockCount;
                      }
                      hzBlockCount = 0;
                      if (alignedPitch != 0) {
                        hzBlockCount = (hzBlockCount0 * hzIsPartial) / alignedPitch & -blockAlign;
                      }
                      hzRowsWord = 0;
                      if (bufferHeight != 0) {
                        hzRowsWord = ((recordCursor[hzCtlIndex + 1] & 0xffff) / bufferHeight) * (bufferHeight - hzBlockCount);
                      }
                      hzScaleBits = (UInt8 *)0x0;
                      sampleBitsClear = (M<UInt32>(depthBuffer + 0x3c) & 0xf000) == 0;
                      cr0Bits = sampleBitsClear << 1;
                      if (!sampleBitsClear) {
                        hzHeightSumCvtLo = hzBlockCount + bufferHeight;
                        hzHeightSumCvtHi = 0x43300000;
                        sampleBitsCvtHi = 0x43300000;
                        sampleBitsCvtLo = M<UInt32>(depthBuffer + 0x3c) >> 0xc & 0xf ^ 0x80000000;
                        sampleCountF = (float)((double)CONCAT44d(0x43300000,sampleBitsCvtLo) - DOUBLE_0004c3a8);
                        hzScaleBits = (UInt8 *)FBITS((float)((double)CONCAT44d(0x43300000,hzHeightSumCvtLo) - DOUBLE_0004c3b0) / (sampleCountF + sampleCountF));   /* a float kept in a pointer-typed stack slot */
                      }
                      recordCursor[hzCtlIndex + 1] = hzRowsWord | recordCursor[hzCtlIndex + 1] & 0xffff0000;
                      recordCursor[hzCtlIndex + 7] = (UInt32)hzScaleBits;
                    }
                  }
                  M<UInt32>(depthBuffer + 0x2c) = recordCursor[zbWordIndex];
                  if ((M<SInt32>(self + kATIR500GLContext_renderToTexture) != 0) && (M<SInt32>(self + kATIR500GLContext_renderTargetTexture) != 0)) {
                    M<UInt32>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x7c) = recordCursor[zbWordIndex];
                    M<UInt16>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x7a) =
                         CONCAT11(depthBuffer[0x35],depthBuffer[0x34]);
                  }
                  vtable = M<SInt32>(self);
                  goto updateStateAfterHz;
                }
                if (opcode == 0x16000000) goto unbindSlotAndNop;
              }
              goto nextRecord;
            }
            if (opcode != 0x1a000000) {
              if (opcode < 0x1a000001) {
                if ((opcode == 0x18000000) || (opcode == 0x19000000)) goto unbindSlotAndNop;
              }
              else if ((opcode == 0x1b000000) || (opcode == 0x1c000000)) goto unbindSlotAndNop;
              goto nextRecord;
            }
          }
        }
        else if (opcode != 0x23000000) {
          if (0x23000000 < opcode) {
            if (opcode == 0x26000000) {
              if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[1]) ||
                 (texture = *(UInt8 **)
                             (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture == (UInt8 *)0x0)) goto abortStreamUnreserve;
              currentTransferBuffer = M<UInt8 *>(self + kATIR500GLContext_transferBufferSlot);
              activeTexture = texture;
              if (currentTransferBuffer != texture) {
                if (currentTransferBuffer != (UInt8 *)0x0) {
                  M<UInt32>(M<SInt32>(currentTransferBuffer + 0x14) + 8) =
                       M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
                  M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) =
                       M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) + -1;
                }
                M<SInt16>(texture + 0xe) = M<SInt16>(texture + 0xe) + 1;
                M<UInt8 *>(self + kATIR500GLContext_transferBufferSlot) = texture;
              }
              if (M<SInt32>(texture + 4) == 0) {
                if (pendingWords != 0) {
                  gapWords = recordCursor[-1] >> 2;
                  if (4 < gapWords) {
                    nopHeader = 0x80000000;
                    if (gapWords != 5) {
                      nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                    }
                    recordCursor[-gapWords] = nopHeader;
                  }
                  recordCursor[-4] = 0x1393;
                  recordCursor[-3] = 0;
                  recordCursor[-2] = 0x5c8;
                  recordCursor[-1] = 0x20000;
                  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                       pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
                  submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                               0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                      pendingWords);
                  submittedWords = pendingWords;
                  M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
                  reservedWords = 0;
                  pendingWords = 0;
                  streamOffset = submittedWords * 4 + streamOffset;
                }
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)activeTexture));
                if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                }
              }
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
              recordCursor[5] = M<SInt32>(activeTexture + 4) + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) +
                           recordCursor[5] + 0x80;
            }
            else if (opcode < 0x26000001) {
              if ((opcode == 0x24000000) || (opcode == 0x25000000)) goto unbindSlotAndNop;
            }
            else if (opcode == 0x28000000) {
              if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                mipLevelOp28 = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
                surfaceIndexOp28 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
                nextMipLevelOp28 = mipLevelOp28 + 1;
                surfaceBuffer = *(UInt8 **)
                           ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
              }
              else {
                surfaceIndexOp28 = 0;
                mipLevelOp28 = 0;
                nextMipLevelOp28 = 1;
                surfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
              }
              *recordCursor = 0x105bb;
              recordCursor[1] = M<UInt32>(self + kATIR500GLContext_scissorY);
              recordCursor[2] = M<UInt32>(self + kATIR500GLContext_scissorX);
              widthPerSample = 0;
              levelOffset0 = M<SInt32>(surfaceBuffer + mipLevelOp28 * 4 + 0x40);
              levelOffset1 = M<SInt32>(surfaceBuffer + nextMipLevelOp28 * 4 + 0x40);
              bufferPitch = M<UInt16>(surfaceBuffer + 0x20);
              surfaceBaseAddress = M<SInt32>(surfaceBuffer + 8);
              singleSample = (M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0;
              cr0Bits = singleSample << 1;
              if (!singleSample) {
                widthPerSample = (UInt32)M<UInt16>(surfaceBuffer + 0x14) /
                         (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf);
              }
              bytesPerPixel = M<UInt16>(surfaceBuffer + 0x16);
              minPitchPixelsOp28 = 0x20 / bytesPerPixel;
              if (minPitchPixelsOp28 <= widthPerSample) {
                minPitchPixelsOp28 = widthPerSample;
              }
              bufferFlagsOp28 = surfaceBuffer[0x38];
              tiledFlagBit = 0x80000000;
              if ((UInt8)bufferFlagsOp28 < 2) {
                tiledFlagBit = 0;
              }
              recordCursor[3] = 0x50b;
              recordCursor[4] = tiledFlagBit | levelOffset0 * (UInt32)bufferPitch + surfaceIndexOp28 * (levelOffset1 - levelOffset0) + surfaceBaseAddress >>
                                    10 | minPitchPixelsOp28 * bytesPerPixel * 0x10000 & 0x3fc00000 |
                                    ((UInt8)bufferFlagsOp28 & 1) << 0x1e;
            }
            else if (opcode == 0x29000000) {
              if (M<SInt32>(self + kATIR500GLContext_renderToTexture) != 0) {
                M<UInt32>(self + kATIR500GLContext_renderToTexture) = 0;
              }
              attachmentsDone = 0;
              attachmentsLeft = 4;
              M<UInt16>(self + kATIR500GLContext_attachmentCount) = 0;
              selfAlias = self;
              attachmentCursor = recordCursor;
              do {
                switch(attachmentCursor[1]) {
                case 0:
                  stateIndex = attachmentsDone & 0xffff;
                  attachmentsDone = stateIndex + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)attachmentsDone;
                  M<UInt16>(self + stateIndex * 2 + 0x3aa) = 1;
                  break;
                case 1:
                  stateIndex = attachmentsDone & 0xffff;
                  attachmentsDone = stateIndex + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)attachmentsDone;
                  M<UInt16>(self + stateIndex * 2 + 0x3aa) = 0;
                  break;
                case 2:
                  stateIndex = attachmentsDone & 0xffff;
                  attachmentsDone = stateIndex + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)attachmentsDone;
                  M<UInt16>(self + stateIndex * 2 + 0x3aa) = 4;
                  break;
                case 3:
                  stateIndex = attachmentsDone & 0xffff;
                  attachmentsDone = stateIndex + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)attachmentsDone;
                  M<UInt16>(self + stateIndex * 2 + 0x3aa) = 5;
                  break;
                case 7:
                  stateIndex = attachmentsDone & 0xffff;
                  attachmentsDone = stateIndex + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)attachmentsDone;
                  M<UInt16>(self + stateIndex * 2 + 0x3aa) = 2;
                  break;
                case 8:
                  stateIndex = attachmentsDone & 0xffff;
                  attachmentsDone = stateIndex + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)attachmentsDone;
                  M<UInt16>(self + stateIndex * 2 + 0x3aa) = 3;
                  break;
                case 0x10:
                  stateIndex = attachmentsDone & 0xffff;
                  attachmentsDone = stateIndex + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)attachmentsDone;
                  M<UInt16>(self + stateIndex * 2 + 0x3aa) = 9;
                  break;
                case 0x11:
                  M<UInt16>(selfAlias + 0x3aa) = 0x17;
                }
                attachmentsLeft = attachmentsLeft + -1;
                attachmentCursor = attachmentCursor + 1;
                selfAlias = selfAlias + 2;
              } while (attachmentsLeft != 0);
              if ((attachmentsDone & 0xffff) == 0) {
                M<UInt16>(self + kATIR500GLContext_attachmentCount) = 1;
                M<UInt16>(self + kATIR500GLContext_attachmentBufferIds) = 1;
              }
              M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = M<UInt16>(self + kATIR500GLContext_attachmentBufferIds);
              M<UInt32>(self + kATIR500GLContext_renderBufferIndex) = (UInt32)M<UInt16>(self + kATIR500GLContext_attachmentBufferIds);
              if (recordCursor[5] == 0x10) {
                M<UInt16>(self + kATIR500GLContext_attachmentBufferIds) = 9;
                M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = 9;
              }
              noDepthFlag = (M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) & 0x80) == 0;
              cr0Bits = noDepthFlag << 1;
              if (!noDepthFlag) {
                depthAttachment = recordCursor[1];
                if ((depthAttachment == 7) || (depthAttachment == 8)) {
                  M<SInt16>(self + kIOATIR500GLContext_depthBufferIndex) = (SInt16)depthAttachment;
                }
                else {
                  M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) = 6;
                }
              }
              VCALL(M<SInt32>(self), 0x5a4)(self);
              this->build_scissor();
              this->write_kernel_context_buffer_regs((UInt32 *)(recordCursor),0,recordCursor[6],recordCursor[7]);
            }
            else if (opcode == 0x27000000) {
              if (M<SInt32>(self + kATIR500GLContext_transferBufferSlot) != 0) {
                M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0x14) + 8) =
                     M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
                M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) =
                     M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) + -1;
                M<UInt32>(self + kATIR500GLContext_transferBufferSlot) = 0;
              }
              goto nopRecord;
            }
            goto nextRecord;
          }
          if (opcode != 0x20000000) {
            if (opcode < 0x20000001) {
              if ((opcode == 0x1e000000) || (opcode == 0x1f000000)) goto unbindSlotAndNop;
            }
            else if ((opcode == 0x21000000) || (opcode == 0x22000000)) goto unbindSlotAndNop;
            goto nextRecord;
          }
        }
      }
unbindSlotAndNop:
      slotByteOffsetUnbind = opcode + 0xea000000 >> 0x16;
      if (M<UInt8 *>(self + slotByteOffsetUnbind + 0x2a4) != (UInt8 *)0x0) {
        ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + slotByteOffsetUnbind + 0x2a4)));
        boundTexture = M<UInt8 *>(self + slotByteOffsetUnbind + 0x2a4);
        refCountPtr = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
        previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
        if (previousRefCount == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(boundTexture));
        }
        M<UInt32>(self + slotByteOffsetUnbind + 0x2a4) = 0;
      }
nopRecord:
      *recordCursor = 0x80000000;
    }
    else {
      if (opcode == 0x37000000) {
        slotTexture = M<SInt32>(self + kATIR500GLContext_textureSlots);
        if (slotTexture != 0) {
          if (M<char>(slotTexture + 0x20) == '\0') {
            ownerSurface = M<UInt8 *>(slotTexture + 0x50);
            if (ownerSurface == (UInt8 *)0x0) goto nopRecordCounted;
            bufferIndex = ((IOATIR500Surface *)(ownerSurface))->surface_buffer_idx_mask(M<UInt32>(slotTexture + 0x58),(UInt32 *)&bufferMaskOut);
            usesSurfaceBuffer = true;
            surfaceBufferPtr = M<SInt32>(ownerSurface + bufferIndex * 4 + 0xb70);
            bufferBase = M<SInt32>(surfaceBufferPtr + 8);
          }
          else {
            bufferBase = M<SInt32>(slotTexture + 0x48);
            usesSurfaceBuffer = false;
            surfaceBufferPtr = 0;
          }
          if (bufferBase != 0) {
            addressPatchCount = recordCursor[3] & 0xffff;
            tiledPatchCount = recordCursor[3] >> 0x10;
            tiledPatchList = recordCursor + addressPatchCount;
            levelWord = recordCursor[2];
            *recordCursor = (tiledPatchCount + addressPatchCount + 2) * 0x10000 | 0xc0001000;
            tiledPatchList[tiledPatchCount + 0xf] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
            plainPatchCursor = recordCursor;
            if (usesSurfaceBuffer) {
              for (; addressPatchCount != 0; addressPatchCount = addressPatchCount - 1) {
                patchRecordIndex = plainPatchCursor[4];
                mipWidth = 0;
                patchWord = recordCursor[patchRecordIndex];
                levelEntryPtr = (patchWord & 0xffff) * 4 + surfaceBufferPtr;
                levelOffset0Op37 = M<SInt32>(levelEntryPtr + 0x40);
                recordCursor[patchRecordIndex] =
                     levelOffset0Op37 * (UInt32)M<UInt16>(surfaceBufferPtr + 0x20) +
                     (patchWord >> 0x10) * (M<SInt32>(levelEntryPtr + 0x44) - levelOffset0Op37) + M<SInt32>(surfaceBufferPtr + 8);
                singleSample = (M<UInt32>(surfaceBufferPtr + 0x3c) & 0xf00000) == 0;
                cr0Bits = singleSample << 1;
                formatByteOffset = (UInt32)M<UInt8>(surfaceBufferPtr + 0x3a) * 0x1c;
                if (!singleSample) {
                  mipWidth = (SInt32)((UInt32)M<UInt16>(surfaceBufferPtr + 0x14) /
                                (M<UInt32>(surfaceBufferPtr + 0x3c) >> 0x14 & 0xf)) >> (patchWord & 0x3f);
                }
                pitchPixels = 0x20 / M<UInt16>(surfaceBufferPtr + 0x16);
                if (pitchPixels <= mipWidth) {
                  pitchPixels = mipWidth;
                }
                pitchRegWord = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 1 & 0x1e00000 |
                           (FormatTableLookup_0x0004d2dc(formatByteOffset) & 0xc00) << 9 |
                           (M<UInt8>(surfaceBufferPtr + 0x38) & 6) << 0x10 |
                           (M<UInt8>(surfaceBufferPtr + 0x38) & 1) << 0x10 |
                           pitchPixels & 0x3ffe | pitchRegWord & 0xfe00c001;
                recordCursor[patchRecordIndex + 2] = pitchRegWord;
                plainPatchCursor = plainPatchCursor + 1;
              }
              for (; tiledPatchCount != 0; tiledPatchCount = tiledPatchCount - 1) {
                tiledPatchEntry = tiledPatchList + 4;
                tiledPatchList = tiledPatchList + 1;
                levelEntryPtr = (recordCursor[*tiledPatchEntry] & 0xffff) * 4 + surfaceBufferPtr;
                levelOffset0Op37 = M<SInt32>(levelEntryPtr + 0x40);
                recordCursor[*tiledPatchEntry] =
                     M<UInt8>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0x15) & 0x1f |
                     levelOffset0Op37 * (UInt32)M<UInt16>(surfaceBufferPtr + 0x20) +
                     (recordCursor[*tiledPatchEntry] >> 0x10) * (M<SInt32>(levelEntryPtr + 0x44) - levelOffset0Op37) +
                     M<SInt32>(surfaceBufferPtr + 8) & 0xffffffe0;
              }
            }
            else {
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
              for (; addressPatchCount != 0; addressPatchCount = addressPatchCount - 1) {
                patchIndexPtr = plainPatchCursor + 4;
                plainPatchCursor = plainPatchCursor + 1;
                recordCursor[*patchIndexPtr] = textureOffset + recordCursor[*patchIndexPtr];
              }
              for (; tiledPatchCount != 0; tiledPatchCount = tiledPatchCount - 1) {
                tiledPatchEntry = tiledPatchList + 4;
                tiledPatchList = tiledPatchList + 1;
                recordCursor[*tiledPatchEntry] =
                     M<UInt8>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0x15) & 0x1f |
                     textureOffset + recordCursor[*tiledPatchEntry] & 0xffffffe0;
              }
              levelEntry = (levelWord >> 0x10) * 2;
              levelInfoPtr = levelEntry + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              levelBit = (UInt16)((1 << (levelWord & 0x3f)) + -1 << (levelWord >> 8 & 0x3f));
              M<UInt16>(levelInfoPtr + 0x28) = levelBit | M<UInt16>(levelInfoPtr + 0x28);
              levelEntry = levelEntry + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(levelEntry + 0x1c) = M<UInt16>(levelEntry + 0x1c) & ~levelBit;
              M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0xc) =
                   M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
            }
            goto nextRecord;
          }
        }
nopRecordCounted:
        *recordCursor = (recordCursor[1] - 2) * 0x10000 | 0xc0001000;
        goto nextRecord;
      }
      if (0x37000000 < opcode) {
        if (opcode == 0x3f000000) {
          offsetInTexture = recordCursor[3];
          if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[2]) ||
             (texture = *(UInt8 **)
                         (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
             texture == (UInt8 *)0x0)) goto abortStream;
          activeTexture = texture;
          ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
          if (M<char>(M<SInt32>(activeTexture + 0x14) + 0x14) != '\0') {
            if (pendingWords != 0) {
              gapWords = recordCursor[-1] >> 2;
              if (4 < gapWords) {
                nopHeader = 0x80000000;
                if (gapWords != 5) {
                  nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                }
                recordCursor[-gapWords] = nopHeader;
              }
              recordCursor[-4] = 0x1393;
              recordCursor[-3] = 0;
              recordCursor[-2] = 0x5c8;
              recordCursor[-1] = 0x20000;
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
              submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)
                                  ,streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
              submittedWords = pendingWords;
              M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
              pendingWords = 0;
              streamOffset = submittedWords * 4 + streamOffset;
            }
            this->alloc_and_load_texture((VendorTextureBuffer *)(activeTexture));
            if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
              M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
              this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
            }
            if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
            }
          }
          *recordCursor = 0xc0021000;
          recordCursor[0xf] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
          if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
            surfaceBuffer = *(UInt8 **)
                       (M<SInt32>(self + kATIR500GLContext_renderBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
          }
          else {
            surfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
          }
          widthPerSample = 0;
          formatByteOffset = (UInt32)(UInt8)surfaceBuffer[0x3a] * 0x1c;
          recordCursor[0x9e] =
               (UInt32)M<UInt16>(surfaceBuffer + 0x20) * M<SInt32>(surfaceBuffer + 0x40) + M<SInt32>(surfaceBuffer + 8)
               & 0xffffffe0;
          if ((M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) != 0) {
            widthPerSample = (UInt32)M<UInt16>(surfaceBuffer + 0x14) / (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf);
          }
          pitchPixels = 0x20 / M<UInt16>(surfaceBuffer + 0x16);
          if (0x20 / M<UInt16>(surfaceBuffer + 0x16) <= widthPerSample) {
            pitchPixels = widthPerSample;
          }
          savedFormatReg = recordCursor[0x8e];
          recordCursor[0xa0] =
               pitchPixels & 0x3ffe | ((UInt8)surfaceBuffer[0x38] & 1) << 0x10 |
               ((UInt8)surfaceBuffer[0x38] & 6) << 0x10 | ((UInt8)surfaceBuffer[0x39] & 3) << 0x13 |
               FormatTableLookup_0x0004d2e0((UInt32)(UInt8)surfaceBuffer[0x3a] * 0x1c) >> 1 & 0x1e00000;
          formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
          recordCursor[0x8e] = formatFieldE0 | savedFormatReg & 0xffffffe0;
          formatBits300 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
          recordCursor[0x8e] = formatBits300 | formatFieldE0 | savedFormatReg & 0xfffffce0;
          formatBitsC00 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
          recordCursor[0x8e] = formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatReg & 0xfffff0e0;
          formatBits3000 = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
          recordCursor[0x8e] = formatBits3000 | formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatReg & 0xffffc0e0;
          recordCursor[0x8e] =
               (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
               formatBits3000 | formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatReg & 0xffff00e0;
          singleSample = (M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0;
          cr0Bits = singleSample << 1;
          if ((singleSample) ||
             (formatBits300 = (UInt32)M<UInt16>(surfaceBuffer + 0x1c) / (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf)
             , maxX = formatBits300 - 1, formatBits300 == 0)) {
            maxX = 0;
          }
          maxY = 0;
          if (M<UInt16>(surfaceBuffer + 0x1e) != 0) {
            maxY = M<UInt16>(surfaceBuffer + 0x1e) - 1;
          }
          recordCursor[0xb7] = maxX & 0x1fff | (maxY & 0x1fff) << 0xd;
          vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(activeTexture),offsetInTexture);
          recordCursor[0xa4] =
               vertexArrayOffset + (recordCursor[0xa4] >> 3 & 0x1ffffffc) & 0xffffffe0 | recordCursor[0xa4] & 0x1f;
releaseActiveTexture:
          ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(activeTexture));
          refCountPtr = (SInt32 *)(M<SInt32>(activeTexture + 0x14) + 0x10);
          previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -0x10000);
          if (previousRefCount == 1) {
deleteActiveTexture:
            ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(activeTexture));
          }
          goto nextRecord;
        }
        if (opcode < 0x3f000001) {
          if (opcode == 0x3b000000) {
            queryParam1 = recordCursor[2];
            queryParam2 = recordCursor[3];
            pipeCount = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
            if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[1]) ||
               (texture = *(UInt8 **)
                           (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
               texture == (UInt8 *)0x0)) goto abortStream;
            activeTexture = texture;
            if (M<UInt8 *>(self + kATIR500GLContext_streamedTexture) != (UInt8 *)0x0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_streamedTexture)));
              texture = M<UInt8 *>(self + kATIR500GLContext_streamedTexture);
              refCountPtr = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
              previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
              if (previousRefCount == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(texture));
              }
            }
            ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(activeTexture));
            if (M<char>(M<SInt32>(activeTexture + 0x14) + 0x14) != '\0') {
              if (pendingWords != 0) {
                gapWords = recordCursor[-1] >> 2;
                if (4 < gapWords) {
                  nopHeader = 0x80000000;
                  if (gapWords != 5) {
                    nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                  }
                  recordCursor[-gapWords] = nopHeader;
                }
                recordCursor[-4] = 0x1393;
                recordCursor[-3] = 0;
                recordCursor[-2] = 0x5c8;
                recordCursor[-1] = 0x20000;
                M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                     pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                             0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                    pendingWords);
                submittedWords = pendingWords;
                M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
                pendingWords = 0;
                streamOffset = submittedWords * 4 + streamOffset;
              }
              this->alloc_and_load_texture((VendorTextureBuffer *)(activeTexture));
              if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
                M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
                this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
              }
              if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
              }
            }
            texture = activeTexture;
            queryOffset = this->GetQueryOffset((VendorTextureBuffer *)(activeTexture),queryParam2,queryParam1);
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordCursor[2] = 0x80000000;
            recordCursor[3] = 0x80000000;
            if ((pipeCount == 1) && (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb9c) == 2)) {
              recordCursor[9] = queryOffset;
              recordCursor[0xd] = queryOffset + 0x10;
            }
            else {
              recordCursor[7] = queryOffset;
              if (1 < pipeCount) {
                recordCursor[0xb] = queryOffset + 0x10;
              }
              if (2 < pipeCount) {
                recordCursor[0xf] = queryOffset + 8;
              }
              if (3 < pipeCount) {
                recordCursor[0x13] = queryOffset + 0xc;
              }
            }
            refCountPtr = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
            atomicAddReturningOld((SInt32 *)refCountPtr, -0xffff);
            if (M<SInt32>(texture + 0x48) != 0) {
              M<UInt32>(M<SInt32>(texture + 0x24) + 0x28) = M<UInt32>(texture + 0x28);
              M<UInt32>(M<SInt32>(activeTexture + 0x28) + 0x24) = M<UInt32>(activeTexture + 0x24)
              ;
              M<UInt32>(activeTexture + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600);
              M<SInt32>(activeTexture + 0x28) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
              M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600) = activeTexture;
              M<UInt8 *>(M<SInt32>(activeTexture + 0x24) + 0x28) = activeTexture;
              texture = activeTexture;
            }
            M<UInt8 *>(self + kATIR500GLContext_streamedTexture) = texture;
          }
          else if (opcode < 0x3b000001) {
            if (opcode == 0x38000000) {
              pairCountOp38 = recordCursor[1] + 1 >> 1;
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
              recordCursor[2] = 0x80000000;
              recordCursor[3] = 0x80000000;
              recordGartAddress = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
                       (recordCursor[2] * 4 - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)) + 0x20;
              if (pairCountOp38 != 0) {
                entryWordIndex = 6;
                entryByteOffset = 0x1c;
                entryCursor = recordCursor;
                do {
                  recordCursor[entryWordIndex] = (SInt32)recordCursor + entryCursor[6] * 4 + recordGartAddress;
                  M<UInt32>((SInt32)recordCursor + entryByteOffset) = (SInt32)recordCursor + entryCursor[7] * 4 + recordGartAddress;
                  entryCursor = entryCursor + 3;
                  entryWordIndex = entryWordIndex + 3;
                  entryByteOffset = entryByteOffset + 0xc;
                  pairCountOp38 = pairCountOp38 - 1;
                } while (pairCountOp38 != 0);
              }
            }
            else if (opcode == 0x3a000000) {
              selfAlias = self;
              do {
                if (M<UInt8 *>(selfAlias + 0x2e4) != (UInt8 *)0x0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(selfAlias + 0x2e4)));
                  unboundTexture = M<UInt8 *>(selfAlias + 0x2e4);
                  refCountPtr = (SInt32 *)(M<SInt32>(unboundTexture + 0x14) + 0x10);
                  previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
                  if (previousRefCount == 1) {
                    ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(unboundTexture));
                  }
                  M<UInt32>(selfAlias + 0x2e4) = 0;
                }
                selfAlias = selfAlias + 4;
              } while (self + 0x44 != selfAlias);
              goto nopRecord;
            }
          }
          else if (opcode == 0x3d000000) {
            if (recordCursor[1] == 0x132) {
              volatileState = recordCursor[2];
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
              recordCursor[2] = 0x80000000;
              recordCursor[3] = 0x80000000;
              if (M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) != (UInt8 *)0x0) {
                ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->set_volatile_state((eSurfaceVolatileState)(volatileState));
              }
            }
            else {
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
            }
          }
          else if (opcode == 0x3e000000) {
            currentTexture = M<SInt32>(self + kATIR500GLContext_textureSlots);
            if ((currentTexture != 0) &&
               ((M<char>(currentTexture + 0x20) == '\x06' || (M<SInt32>(currentTexture + 0x48) != 0)))) {
              levelWordOp3e = recordCursor[4];
              offsetInTexture = recordCursor[3];
              if ((recordCursor[2] < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
                 (texture = *(UInt8 **)
                             (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture != (UInt8 *)0x0)) {
                activeTexture = texture;
                ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
                if (M<char>(M<SInt32>(activeTexture + 0x14) + 0x14) != '\0') {
                  if (pendingWords != 0) {
                    gapWords = recordCursor[-1] >> 2;
                    if (4 < gapWords) {
                      nopHeader = 0x80000000;
                      if (gapWords != 5) {
                        nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                      }
                      recordCursor[-gapWords] = nopHeader;
                    }
                    recordCursor[-4] = 0x1393;
                    recordCursor[-3] = 0;
                    recordCursor[-2] = 0x5c8;
                    recordCursor[-1] = 0x20000;
                    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                         pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                    submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                                 0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                        pendingWords);
                    submittedWords = pendingWords;
                    M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
                    pendingWords = 0;
                    streamOffset = submittedWords * 4 + streamOffset;
                  }
                  this->alloc_and_load_texture((VendorTextureBuffer *)(activeTexture));
                  if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
                    M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
                    this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
                  }
                  if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                  }
                }
                levelEntry = (levelWordOp3e >> 0x10) * 2;
                levelBit = (UInt16)(1 << (levelWordOp3e & 0x3f));
                levelInfoPtr = levelEntry + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
                M<UInt16>(levelInfoPtr + 0x28) = levelBit | M<UInt16>(levelInfoPtr + 0x28);
                levelEntry = levelEntry + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
                M<UInt16>(levelEntry + 0x1c) = M<UInt16>(levelEntry + 0x1c) & ~levelBit;
                *recordCursor = 0xc0031000;
                offsetWord = recordCursor[0x9f];
                recordCursor[0x10] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
                textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
                recordCursor[0x9f] = offsetWord + textureOffset;
                vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(activeTexture),offsetInTexture);
                recordCursor[0xa5] =
                     vertexArrayOffset + (recordCursor[0xa5] >> 3 & 0x1ffffffc) & 0xffffffe0 | recordCursor[0xa5] & 0x1f;
                M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0xc) =
                     M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
                goto releaseActiveTextureBound;
              }
              goto abortStream;
            }
nopRecordCountedOrSingle:
            nopHeaderNop = 0x80000000;
            if (recordCursor[1] != 1) {
              nopHeaderNop = (recordCursor[1] - 2) * 0x10000 | 0xc0001000;
            }
            *recordCursor = nopHeaderNop;
          }
        }
        else {
          if (opcode == 0x43000000) {
            offsetInTexture = recordCursor[3];
            *recordCursor = 0xc0021000;
            if ((recordCursor[2] < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
               (texture = *(UInt8 **)
                           (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
               texture != (UInt8 *)0x0)) {
              activeTexture = texture;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
              if (M<char>(M<SInt32>(activeTexture + 0x14) + 0x14) != '\0') {
                if (pendingWords != 0) {
                  gapWords = recordCursor[-1] >> 2;
                  if (4 < gapWords) {
                    nopHeader = 0x80000000;
                    if (gapWords != 5) {
                      nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                    }
                    recordCursor[-gapWords] = nopHeader;
                  }
                  recordCursor[-4] = 0x1393;
                  recordCursor[-3] = 0;
                  recordCursor[-2] = 0x5c8;
                  recordCursor[-1] = 0x20000;
                  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                       pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                  submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                               0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                      pendingWords);
                  submittedWords = pendingWords;
                  M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
                  pendingWords = 0;
                  streamOffset = submittedWords * 4 + streamOffset;
                }
                this->alloc_and_load_texture((VendorTextureBuffer *)(activeTexture));
                if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
                  M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
                  this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
                }
                if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                }
              }
              M<UInt16>(M<SInt32>(activeTexture + 0x14) + 0x28) =
                   M<UInt16>(M<SInt32>(activeTexture + 0x14) + 0x28) | 1;
              M<UInt16>(M<SInt32>(activeTexture + 0x14) + 0x1c) =
                   M<UInt16>(M<SInt32>(activeTexture + 0x14) + 0x1c) & 0xfffe;
              vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(activeTexture),offsetInTexture);
              recordCursor[0x15] = vertexArrayOffset + recordCursor[0x15];
              M<UInt32>(M<SInt32>(activeTexture + 0x14) + 0xc) =
                   M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
              if (activeTexture[0x20] == 0x7) {
                M<UInt32>(M<SInt32>(M<SInt32>(activeTexture + 0x58) + 0x14) + 8) =
                     M<UInt32>(M<SInt32>(activeTexture + 0x14) + 0xc);
              }
releaseActiveTextureBound:
              ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(activeTexture));
              refCountPtr = (SInt32 *)(M<SInt32>(activeTexture + 0x14) + 0x10);
              previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -0x10000);
              if (previousRefCount == 0x10000) goto deleteActiveTexture;
            }
            else {
abortStream:
              pendingWords = 0;
              recordWords = 0;
              recordBytes = 0;
            }
            goto nextRecord;
          }
          if (opcode < 0x43000001) {
            if (opcode == 0x40000000) {
              offsetInTexture = recordCursor[3];
              bufferIndexOp40 = recordCursor[4];
              if ((recordCursor[2] < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
                 (texture = *(UInt8 **)
                             (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture != (UInt8 *)0x0)) {
                activeTexture = texture;
                ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
                if (M<char>(M<SInt32>(activeTexture + 0x14) + 0x14) != '\0') {
                  if (pendingWords != 0) {
                    gapWords = recordCursor[-1] >> 2;
                    if (4 < gapWords) {
                      nopHeader = 0x80000000;
                      if (gapWords != 5) {
                        nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                      }
                      recordCursor[-gapWords] = nopHeader;
                    }
                    recordCursor[-4] = 0x1393;
                    recordCursor[-3] = 0;
                    recordCursor[-2] = 0x5c8;
                    recordCursor[-1] = 0x20000;
                    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                         pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                    submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                                 0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                        pendingWords);
                    submittedWords = pendingWords;
                    M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
                    pendingWords = 0;
                    streamOffset = submittedWords * 4 + streamOffset;
                  }
                  this->alloc_and_load_texture((VendorTextureBuffer *)(activeTexture));
                  if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                  }
                }
                *recordCursor = 0xc0031000;
                recordCursor[0x10] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
                if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                  targetBuffer = M<UInt8 *>(bufferIndexOp40 * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
                }
                else {
                  targetBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
                }
                bufferFormatId = targetBuffer[0x3a];
                recordCursor[0xa5] =
                     ((UInt8)targetBuffer[0x38] & 7) << 2 |
                     (UInt32)M<UInt16>(targetBuffer + 0x20) * M<SInt32>(targetBuffer + 0x40) +
                     M<SInt32>(targetBuffer + 8) & 0xffffffe0;
                if (((M<UInt32>(targetBuffer + 0x3c) & 0xf00000) == 0) ||
                   (widthPerSampleOp40 = (UInt32)M<UInt16>(targetBuffer + 0x1c) /
                             (M<UInt32>(targetBuffer + 0x3c) >> 0x14 & 0xf), maxX = widthPerSampleOp40 - 1,
                   widthPerSampleOp40 == 0)) {
                  maxX = 0;
                }
                maxY = 0;
                if (M<UInt16>(targetBuffer + 0x1e) != 0) {
                  maxY = M<UInt16>(targetBuffer + 0x1e) - 1;
                }
                recordCursor[0xab] = maxX & 0x7ff | (maxY & 0x7ff) << 0xb | 0x80000000;
                formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)bufferFormatId * 0x1c);
                recordCursor[0xad] =
                     formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
                     formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
                sampleInfo = M<UInt32>(targetBuffer + 0x3c);
                singleSample = (sampleInfo & 0xf00000) == 0;
                cr0Bits = singleSample << 1;
                if (singleSample) {
                  maxY = 0;
                }
                else {
                  maxY = (UInt32)M<UInt16>(targetBuffer + 0x14) / (sampleInfo >> 0x14 & 0xf);
                }
                pitchPixels = 0x20 / M<UInt16>(targetBuffer + 0x16);
                if (0x20 / M<UInt16>(targetBuffer + 0x16) <= maxY) {
                  pitchPixels = maxY;
                }
                if ((singleSample) ||
                   (widthPerSampleOp40 = (UInt32)M<UInt16>(targetBuffer + 0x1c) / (sampleInfo >> 0x14 & 0xf),
                   maxX = widthPerSampleOp40 - 1, widthPerSampleOp40 == 0)) {
                  maxX = 0;
                }
                maxY = 0;
                if (M<UInt16>(targetBuffer + 0x1e) != 0) {
                  maxY = M<UInt16>(targetBuffer + 0x1e) - 1;
                }
                recordCursor[0xaf] = pitchPixels - 1 & 0x3fff | (maxX & 0x800) << 4 | (maxY & 0x800) << 5;
                vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(activeTexture),offsetInTexture);
                recordCursor[0x9f] = vertexArrayOffset + recordCursor[0x9f];
                goto releaseActiveTexture;
              }
              goto abortStream;
            }
            if (opcode != 0x41000000) goto nextRecord;
            colorTargetCount = recordCursor[1];
            slotsLeft = 4;
            selfAlias = self;
            do {
              M<UInt16>(selfAlias + 0x3b2) = 0;
              selfAlias = selfAlias + 2;
              slotsLeft = slotsLeft + -1;
            } while (slotsLeft != 0);
            headerWord0 = recordCursor[4];
            headerWord1 = recordCursor[5];
            M<UInt16>(self + kATIR500GLContext_attachmentCount) = 0;
            if (colorTargetCount == 0) {
              depthEntry = recordCursor + 6;
              entryWordIndexOp41 = 6;
              entryByteOffsetOp41 = 0x18;
            }
            else {
              unitBuffer = self + kATIR500GLContext_unitBuffers;
              colorIndex = 0;
              entryWordIndexOp41 = 6;
              entryByteOffsetOp41 = 0x18;
              selfAlias = self;
              unitTextureSlot = self;
              colorEntry = recordCursor;
              do {
                depthEntry = colorEntry + 6;
                depthTexture = (UInt8 *)0x0;
                M<SInt16>(selfAlias + 0x3dc) = (SInt16)recordCursor[2];
                M<SInt16>(selfAlias + 0x3de) = (SInt16)recordCursor[3];
                if (M<SInt32>(unitTextureSlot + 0x338) != 0) {
                  unitTextureInfo = M<SInt32>(M<SInt32>(unitTextureSlot + 0x338) + 0x14);
                  M<SInt16>(unitTextureInfo + 0x36) = M<SInt16>(unitTextureInfo + 0x36) + -1;
                  ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(unitTextureSlot + 0x338)));
                  unboundTexture = M<UInt8 *>(unitTextureSlot + 0x338);
                  refCountPtr = (SInt32 *)(M<SInt32>(unboundTexture + 0x14) + 0x10);
                  previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
                  if (previousRefCount == 1) {
                    ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(unboundTexture));
                  }
                  M<UInt32>(unitTextureSlot + 0x338) = 0;
                }
                textureHandle = M<UInt32>((SInt32)recordCursor + entryByteOffsetOp41);
                if (textureHandle != 0xffffffff) {
                  attachmentCount = M<UInt16>(self + kATIR500GLContext_attachmentCount);
                  if (attachmentCount < 4) {
                    M<UInt16>(self + kATIR500GLContext_attachmentCount) = attachmentCount + 1;
                    M<SInt16>(self + (UInt32)attachmentCount * 2 + 0x3b2) = (SInt16)colorIndex;
                    textureHandle = M<UInt32>((SInt32)recordCursor + entryByteOffsetOp41);
                  }
                  if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= textureHandle) ||
                     (texture = *(UInt8 **)
                                   (textureHandle * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                     texture == (UInt8 *)0x0)) {
                    recordHeader = 0;
                    pendingWords = 0;
                    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) =
                         M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) - reservedWords;
                    goto renderTargetsBound;
                  }
                  ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
                  this->get_texture((UInt32 *)(recordCursor),(VendorTextureBuffer *)(texture),(UInt32 *)(&streamOffset),(UInt32 *)(&pendingWords),(UInt32 *)(&reservedWords),(register_tracking_state *)(trackingState));
                  faceByteOffset = colorEntry[10] >> 0xf & 0x1fffe;
                  levelBit = (UInt16)(1 << (colorEntry[10] & 0x3f));
                  M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) =
                       M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) + 1;
                  levelInfoPtr = faceByteOffset + M<SInt32>(texture + 0x14);
                  M<UInt16>(levelInfoPtr + 0x28) = levelBit | M<UInt16>(levelInfoPtr + 0x28);
                  levelInfoPtr = faceByteOffset + M<SInt32>(texture + 0x14);
                  M<UInt16>(levelInfoPtr + 0x1c) = M<UInt16>(levelInfoPtr + 0x1c) & ~levelBit;
                  this->build_surface_from_texture((VendorTextureBuffer *)(texture),(ATIR500SurfaceBuffer *)((UInt8 *)unitBuffer),
                             M<UInt16>((SInt32)recordCursor + 10),M<UInt16>((SInt32)recordCursor + 0xe),
                             M<UInt8>((SInt32)colorEntry + 0x2f),colorEntry[7],
                             M<UInt16>((SInt32)colorEntry + 0x22));
                  M<UInt8 *>(unitTextureSlot + 0x338) = texture;
                }
                colorIndex = colorIndex + 1;
                entryWordIndexOp41 = entryWordIndexOp41 + 6;
                selfAlias = selfAlias + 0x78;
                unitTextureSlot = unitTextureSlot + 4;
                entryByteOffsetOp41 = entryByteOffsetOp41 + 0x18;
                unitBuffer = unitBuffer + 0x78;
                colorEntry = depthEntry;
              } while (colorTargetCount != colorIndex);
              entryByteOffsetOp41 = entryWordIndexOp41 * 4;
              depthEntry = recordCursor + entryWordIndexOp41;
            }
renderTargetsBound:
            if (M<SInt16>(self + kATIR500GLContext_attachmentCount) == 0) {
              M<UInt16>(self + kATIR500GLContext_currentAttachment) = 0;
              M<UInt16>(self + kATIR500GLContext_attachmentCount) = 1;
            }
            depthTexture = (UInt8 *)0x0;
            M<UInt32>(self + kATIR500GLContext_hzMemoryHandle) = 0xffffffff;
            if (M<SInt32>(self + kATIR500GLContext_renderTargetTexture) != 0) {
              textureInfo = M<SInt32>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x14);
              M<SInt16>(textureInfo + 0x36) = M<SInt16>(textureInfo + 0x36) + -1;
              ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture)));
              unboundTexture = M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture);
              refCountPtr = (SInt32 *)(M<SInt32>(unboundTexture + 0x14) + 0x10);
              previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
              if (previousRefCount == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(unboundTexture));
              }
              M<UInt32>(self + kATIR500GLContext_renderTargetTexture) = 0;
            }
            depthTextureHandle = *depthEntry;
            if (depthTextureHandle != 0xffffffff) {
              if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= depthTextureHandle) ||
                 (texture = *(UInt8 **)
                             (depthTextureHandle * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture == (UInt8 *)0x0)) goto abortStreamUnreserve;
              depthTexture = texture;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
              this->get_texture((UInt32 *)(recordCursor),(VendorTextureBuffer *)(depthTexture),(UInt32 *)(&streamOffset),(UInt32 *)(&pendingWords),(UInt32 *)(&reservedWords),(register_tracking_state *)(trackingState));
              levelWordOp41 = M<UInt32>((SInt32)recordCursor + entryByteOffsetOp41 + 0x10);
              faceOffset = levelWordOp41 >> 0xf & 0x1fffe;
              levelBit = (UInt16)(1 << (levelWordOp41 & 0x3f));
              M<SInt16>(M<SInt32>(depthTexture + 0x14) + 0x36) =
                   M<SInt16>(M<SInt32>(depthTexture + 0x14) + 0x36) + 1;
              levelInfoPtr = faceOffset + M<SInt32>(depthTexture + 0x14);
              M<UInt16>(levelInfoPtr + 0x28) = levelBit | M<UInt16>(levelInfoPtr + 0x28);
              levelInfoPtr = faceOffset + M<SInt32>(depthTexture + 0x14);
              M<UInt16>(levelInfoPtr + 0x1c) = M<UInt16>(levelInfoPtr + 0x1c) & ~levelBit;
              this->build_surface_from_texture((VendorTextureBuffer *)(depthTexture),(ATIR500SurfaceBuffer *)((UInt8 *)(self + kATIR500GLContext_textureDepthBuffer)),
                         M<UInt16>((SInt32)recordCursor + 10),M<UInt16>((SInt32)recordCursor + 0xe),
                         M<UInt8>((SInt32)recordCursor + entryByteOffsetOp41 + 0x17),
                         M<UInt32>((SInt32)recordCursor + entryByteOffsetOp41 + 4),
                         M<UInt16>((SInt32)recordCursor + entryByteOffsetOp41 + 10));
            }
            texture = depthTexture;
            if (depthTexture != (UInt8 *)0x0) {
              if ((M<SInt32>(depthTexture + 0x6c) == -1) && (0x20 < M<UInt16>(self + kATIR500GLContext_unknown_0x5bc))) {
                hzHeight = M<UInt16>(self + kATIR500GLContext_unknown_0x5be);
                hzAllocHeight = (UInt32)hzHeight;
                if (0x10 < hzAllocHeight) {
                  hzAlignment = 0x20;
                  numPipesOp41 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
                  if (numPipesOp41 == 4) {
hzAllocWidthAligned:
                    hzAllocWidth = ((SInt32)((UInt32)M<UInt16>(self + kATIR500GLContext_unknown_0x5b4) + hzAlignment + -1) / hzAlignment) *
                             hzAlignment;
                  }
                  else {
                    hzAlignment = numPipesOp41 << 4;
                    hzAllocWidth = 0;
                    if (hzAlignment != 0) goto hzAllocWidthAligned;
                  }
                  heightIsAligned = (hzHeight & 0x1f) == 0;
                  cr0Bits = heightIsAligned << 1;
                  if (!heightIsAligned) {
                    hzAllocHeight = (hzHeight & 0xffffffe0) + 0x20;
                  }
                  hzMemHandle = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),0xffffffff,0,hzAllocWidth
                                       ,hzAllocHeight);
                  hzTexture = depthTexture;
                  M<UInt32>(texture + 0x6c) = hzMemHandle;
                  if ((M<UInt32>(depthTexture + 0x6c) & 0xffc00) == 0xffc00) {
                    hzAlignment = 0x20;
                    numPipesOp41 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
                    if (numPipesOp41 == 4) {
hzAllocWidthAligned2:
                      hzAllocWidthOp41 = ((SInt32)((UInt32)M<UInt16>(self + kATIR500GLContext_unknown_0x5b4) + hzAlignment + -1) / hzAlignment) *
                               hzAlignment;
                    }
                    else {
                      hzAlignment = numPipesOp41 << 4;
                      hzAllocWidthOp41 = 0;
                      if (hzAlignment != 0) goto hzAllocWidthAligned2;
                    }
                    hzHeight = M<UInt16>(self + kATIR500GLContext_unknown_0x5be);
                    hzAllocHeightOp41 = (UInt32)hzHeight;
                    heightIsAligned = (hzHeight & 0x1f) == 0;
                    cr0Bits = heightIsAligned << 1;
                    if (!heightIsAligned) {
                      hzAllocHeightOp41 = (hzHeight & 0xffffffe0) + 0x20;
                    }
                    hzMemHandle = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                         M<UInt32>(depthTexture + 0x6c),1,hzAllocWidthOp41,hzAllocHeightOp41);
                    M<UInt32>(hzTexture + 0x6c) = hzMemHandle;
                  }
                  M<UInt16>(depthTexture + 0x70) = M<UInt16>(self + kATIR500GLContext_unknown_0x5bc);
                  M<UInt16>(depthTexture + 0x72) = M<UInt16>(self + kATIR500GLContext_unknown_0x5be);
                  M<UInt16>(depthTexture + 0x78) = M<UInt16>(self + kATIR500GLContext_unknown_0x5b8);
                  M<UInt16>(depthTexture + 0x7a) = 0;
                  M<UInt32>(depthTexture + 0x74) = M<UInt32>((SInt32)recordCursor + entryByteOffsetOp41 + 4);
                }
              }
              M<UInt32>(self + kATIR500GLContext_hzMemoryHandle) = M<UInt32>(depthTexture + 0x6c);
              self[0x5d4] = SUB21(M<UInt16>(depthTexture + 0x7a),0);
              self[0x5d5] = SUB21((UInt16)M<UInt16>(depthTexture + 0x7a) >> 8,0);
              textureWord7c = M<UInt32>(depthTexture + 0x7c);
              M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture) = depthTexture;
              M<UInt32>(self + kATIR500GLContext_unknown_0x5cc) = textureWord7c;
            }
            depthTexture = (UInt8 *)0x0;
            renderTargetEntry = recordCursor + entryWordIndexOp41 + 6;
            if (recordCursor[entryWordIndexOp41 + 6] != 0xffffffff) {
              if (M<SInt32>(self + kATIR500GLContext_renderTargetTexture) != 0) {
                textureInfoOp41 = M<SInt32>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x14);
                M<SInt16>(textureInfoOp41 + 0x36) = M<SInt16>(textureInfoOp41 + 0x36) + -1;
                ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture)));
                texture = M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture);
                refCountPtr = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
                previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
                if (previousRefCount == 1) {
                  ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(texture));
                }
                M<UInt32>(self + kATIR500GLContext_renderTargetTexture) = 0;
              }
              if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= *renderTargetEntry) ||
                 (texture = *(UInt8 **)
                             (*renderTargetEntry * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture == (UInt8 *)0x0)) {
abortStreamUnreserve:
                recordWords = 0;
                recordBytes = 0;
                M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) =
                     M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) - reservedWords;
                pendingWords = 0;
                goto nextRecord;
              }
              texture = texture;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
              this->get_texture((UInt32 *)(recordCursor),(VendorTextureBuffer *)(texture),(UInt32 *)(&streamOffset),(UInt32 *)(&pendingWords),(UInt32 *)(&reservedWords),(register_tracking_state *)(trackingState));
              faceByteOffset = renderTargetEntry[4] >> 0xf & 0x1fffe;
              levelBit = (UInt16)(1 << (renderTargetEntry[4] & 0x3f));
              M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) =
                   M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) + 1;
              levelInfoPtrOp41 = faceByteOffset + M<SInt32>(texture + 0x14);
              M<UInt16>(levelInfoPtrOp41 + 0x28) = levelBit | M<UInt16>(levelInfoPtrOp41 + 0x28);
              levelInfoPtrOp41 = faceByteOffset + M<SInt32>(texture + 0x14);
              M<UInt16>(levelInfoPtrOp41 + 0x1c) = M<UInt16>(levelInfoPtrOp41 + 0x1c) & ~levelBit;
              this->build_surface_from_texture((VendorTextureBuffer *)(texture),(ATIR500SurfaceBuffer *)((UInt8 *)(self + kATIR500GLContext_textureSurfaceBuffer)),
                         M<UInt16>((SInt32)recordCursor + 10),M<UInt16>((SInt32)recordCursor + 0xe),
                         M<UInt8>((SInt32)renderTargetEntry + 0x17),renderTargetEntry[1],M<UInt16>((SInt32)renderTargetEntry + 10));
              M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture) = texture;
            }
            M<UInt32>(self + kATIR500GLContext_renderToTexture) = 1;
            this->build_scissor();
            VCALL(M<SInt32>(self), 0x5a4)(self);
            M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
            *recordCursor = (entryWordIndexOp41 + 10) * 0x10000 | 0xc0001000;
            recordWords = recordHeader & 0xffffff;
            this->write_kernel_context_buffer_regs((UInt32 *)(recordCursor + entryWordIndexOp41 + 0xc),0,headerWord0,headerWord1);
            recordBytes = recordWords << 2;
          }
          else if (opcode == 0x45000000) {
            depthHandle = recordCursor[3];
            packetEndWord = recordCursor[1];
            activeTexture = (UInt8 *)0x0;
            if (depthHandle != 0xffffffff) {
              if ((depthHandle < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
                 (texture = *(UInt8 **)
                             (depthHandle * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture != (UInt8 *)0x0)) {
                activeTexture = texture;
                if (M<SInt32>(texture + 0x6c) != -1) {
                  this->build_surface_from_texture((VendorTextureBuffer *)(texture),(ATIR500SurfaceBuffer *)(scratchArea),M<UInt16>(texture + 0x70),
                             M<UInt16>(texture + 0x72),M<UInt8>((SInt32)recordCursor + 0x13),
                             M<UInt32>(texture + 0x74),M<UInt16>(texture + 0x78));
                  M<UInt32>(scratchArea + 0x2c) = M<UInt32>(activeTexture + 0x7c);
                  flushedWords = ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(scratchArea),0,(UInt32 *)(recordCursor));
                  M<UInt16>(activeTexture + 0x7a) = 0;
                  goto depthFlushed;
                }
                packetEndWord = packetEndWord + recordCursor[2];
                flushedWords = 0;
                goto padPacketWithNop;
              }
              goto abortStreamUnreserve;
            }
            flushedWords = ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)((UInt8 *)
                                (M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) +
                                (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + 0xa8)),0,(UInt32 *)(recordCursor));
depthFlushed:
            if (flushedWords <= packetEndWord) {
padPacketWithNop:
              if (flushedWords < packetEndWord) {
                nopHeader = 0x80000000;
                if (packetEndWord - flushedWords != 1) {
                  nopHeader = ((packetEndWord - flushedWords) + -2) * 0x10000 | 0xc0001000;
                }
                recordCursor[flushedWords] = nopHeader;
              }
            }
          }
          else if (opcode == 0x46000000) {
            this->process_kATIGLStreamFastClearColor((UInt32 *)(recordCursor));
          }
          else if (opcode == 0x44000000) {
            currentTexture = M<SInt32>(self + kATIR500GLContext_textureSlots);
            if ((currentTexture != 0) &&
               ((M<char>(currentTexture + 0x20) == '\x06' || (M<SInt32>(currentTexture + 0x48) != 0)))) {
              transferBuffer = (UInt8 *)recordCursor[3];
              levelWordOp3e = recordCursor[2];
              bufferOffset = recordCursor[4];
              if ((M<SInt32>(transferBuffer + 0x48) == 0) &&
                 ((M<SInt32>(transferBuffer + 4) == 0 &&
                  (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(transferBuffer)),
                  M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0)))) {
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
              }
              *recordCursor = 0xc0031000;
              bufferAddress = bufferOffset + M<SInt32>(transferBuffer + 0x48);
              if (M<SInt32>(transferBuffer + 0x48) == 0) {
                *recordCursor = 0xc0011000;
                recordCursor[3] = 0x575;
                recordCursor[4] = 2;
                bufferAddress = bufferOffset + M<SInt32>(transferBuffer + 4) + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4);
              }
              levelEntry = (levelWordOp3e >> 0x10) * 2;
              levelBit = (UInt16)(1 << (levelWordOp3e & 0x3f));
              levelEntryPtrOp44 = levelEntry + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(levelEntryPtrOp44 + 0x28) = levelBit | M<UInt16>(levelEntryPtrOp44 + 0x28);
              levelEntry = levelEntry + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(levelEntry + 0x1c) = M<UInt16>(levelEntry + 0x1c) & ~levelBit;
              recordCursor[0x10] = bufferAddress;
              offsetWord = recordCursor[0x16];
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
              recordCursor[0x16] = offsetWord + textureOffset;
              M<UInt32>(transferBuffer + 0x5c) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
              goto markTextureUsed;
            }
            goto nopRecordCountedOrSingle;
          }
        }
        goto nextRecord;
      }
      if (opcode == 0x31000000) {
        attachmentType = recordCursor[2];
        packetWordsOp31 = recordCursor[1];
        layerCount = recordCursor[3];
        if (attachmentType == 8) {
slotIsDepth8:
          attachmentSlot = 8;
        }
        else {
          if (attachmentType < 9) {
            if (attachmentType == 7) {
slotIsDepth7:
              attachmentSlot = 7;
              goto slotSelected;
            }
          }
          else {
            if (attachmentType == 10) goto slotIsDepth7;
            if (attachmentType == 0xb) goto slotIsDepth8;
          }
          attachmentSlot = 6;
        }
slotSelected:
        if ((M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) & 0x80) == 0) {
          attachmentSlot = 6;
        }
        if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
          surfaceObject = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
          selectedBuffer = M<UInt8 *>(surfaceObject + attachmentSlot * 4 + kIOATIR500Surface_attachmentBuffers);
          depthBufferOp31 = (UInt8 *)(surfaceObject + (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + 0xa8)
          ;
        }
        else {
          surfaceObject = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
          selectedBuffer = (UInt8 *)(self + kATIR500GLContext_textureDepthBuffer);
          depthBufferOp31 = (UInt8 *)(self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0);
        }
        flushedWordsOp31 = ((ATIR500Surface *)(surfaceObject))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(selectedBuffer), 0, (UInt32 *)(recordCursor));
        if (((M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) && (attachmentSlot != M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex))) &&
           (depthBufferOp31[0x34] != 0x0)) {
          flushedWordsOp31 = ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(depthBufferOp31),flushedWordsOp31,(UInt32 *)(recordCursor));
        }
        depthBufferOp31[0x35] = 0x0;
        depthBufferOp31[0x34] = 0x0;
        if ((flushedWordsOp31 <= packetWordsOp31) && (flushedWordsOp31 < packetWordsOp31)) {
          nopHeaderNop = 0x80000000;
          if (packetWordsOp31 - flushedWordsOp31 != 1) {
            nopHeaderNop = ((packetWordsOp31 - flushedWordsOp31) + -2) * 0x10000 | 0xc0001000;
          }
          recordCursor[flushedWordsOp31] = nopHeaderNop;
        }
        widthPerSample = 0;
        formatByteOffset = (UInt32)(UInt8)depthBufferOp31[0x3a] * 0x1c;
        recordCursor[packetWordsOp31 + 0x9a] =
             (UInt32)M<UInt16>(depthBufferOp31 + 0x20) * M<SInt32>(depthBufferOp31 + 0x40) + M<SInt32>(depthBufferOp31 + 8) &
             0xffffffe0;
        if ((M<UInt32>(depthBufferOp31 + 0x3c) & 0xf00000) != 0) {
          widthPerSample = (UInt32)M<UInt16>(depthBufferOp31 + 0x14) / (M<UInt32>(depthBufferOp31 + 0x3c) >> 0x14 & 0xf);
        }
        pitchPixels = 0x20 / M<UInt16>(depthBufferOp31 + 0x16);
        if (0x20 / M<UInt16>(depthBufferOp31 + 0x16) <= widthPerSample) {
          pitchPixels = widthPerSample;
        }
        savedFormatRegOp31 = recordCursor[packetWordsOp31 + 0x8a];
        recordCursor[packetWordsOp31 + 0x9c] =
             pitchPixels & 0x3ffe | ((UInt8)depthBufferOp31[0x38] & 1) << 0x10 | ((UInt8)depthBufferOp31[0x38] & 6) << 0x10
             | ((UInt8)depthBufferOp31[0x39] & 3) << 0x13 |
             FormatTableLookup_0x0004d2e0((UInt32)(UInt8)depthBufferOp31[0x3a] * 0x1c) >> 1 & 0x1e00000;
        formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
        recordCursor[packetWordsOp31 + 0x8a] = formatFieldE0 | savedFormatRegOp31 & 0xffffffe0;
        formatBits300 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
        recordCursor[packetWordsOp31 + 0x8a] = formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xfffffce0;
        formatBitsC00 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
        recordCursor[packetWordsOp31 + 0x8a] = formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xfffff0e0;
        formatBits3000Op31 = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
        recordCursor[packetWordsOp31 + 0x8a] = formatBits3000Op31 | formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xffffc0e0;
        recordCursor[packetWordsOp31 + 0x8a] =
             (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
             formatBits3000Op31 | formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xffff00e0;
        if (((M<UInt32>(depthBufferOp31 + 0x3c) & 0xf00000) == 0) ||
           (formatBits300 = (UInt32)M<UInt16>(depthBufferOp31 + 0x1c) / (M<UInt32>(depthBufferOp31 + 0x3c) >> 0x14 & 0xf),
           maxX = formatBits300 - 1, formatBits300 == 0)) {
          maxX = 0;
        }
        maxY = 0;
        if (M<UInt16>(depthBufferOp31 + 0x1e) != 0) {
          maxY = M<UInt16>(depthBufferOp31 + 0x1e) - 1;
        }
        recordCursor[packetWordsOp31 + 0xb3] = maxX & 0x1fff | (maxY & 0x1fff) << 0xd;
        bufferFormatIdOp31 = selectedBuffer[0x3a];
        recordCursor[packetWordsOp31 + 0xa0] =
             ((UInt8)selectedBuffer[0x38] & 7) << 2 |
             (UInt32)M<UInt16>(selectedBuffer + 0x20) * M<SInt32>(selectedBuffer + 0x40) + M<SInt32>(selectedBuffer + 8) &
             0xffffffe0;
        if (((M<UInt32>(selectedBuffer + 0x3c) & 0xf00000) == 0) ||
           (widthPerSampleOp05 = (UInt32)M<UInt16>(selectedBuffer + 0x1c) / (M<UInt32>(selectedBuffer + 0x3c) >> 0x14 & 0xf),
           maxX = widthPerSampleOp05 - 1, widthPerSampleOp05 == 0)) {
          maxX = 0;
        }
        maxY = 0;
        if (M<UInt16>(selectedBuffer + 0x1e) != 0) {
          maxY = M<UInt16>(selectedBuffer + 0x1e) - 1;
        }
        recordCursor[packetWordsOp31 + 0xa6] = maxX & 0x7ff | (maxY & 0x7ff) << 0xb | 0x80000000;
        formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)bufferFormatIdOp31 * 0x1c);
        recordCursor[packetWordsOp31 + 0xa8] =
             formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
             formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
        sampleInfo = M<UInt32>(selectedBuffer + 0x3c);
        singleSample = (sampleInfo & 0xf00000) == 0;
        if (singleSample) {
          maxY = 0;
        }
        else {
          maxY = (UInt32)M<UInt16>(selectedBuffer + 0x14) / (sampleInfo >> 0x14 & 0xf);
        }
        pitchPixels = 0x20 / M<UInt16>(selectedBuffer + 0x16);
        if (0x20 / M<UInt16>(selectedBuffer + 0x16) <= maxY) {
          pitchPixels = maxY;
        }
        if ((singleSample) ||
           (widthPerSampleOp05 = (UInt32)M<UInt16>(selectedBuffer + 0x1c) / (sampleInfo >> 0x14 & 0xf), maxX = widthPerSampleOp05 - 1
           , widthPerSampleOp05 == 0)) {
          maxX = 0;
        }
        maxY = 0;
        if (M<UInt16>(selectedBuffer + 0x1e) != 0) {
          maxY = M<UInt16>(selectedBuffer + 0x1e) - 1;
        }
        stateWordCursor = recordCursor + packetWordsOp31 + 0xbd;
        widthPerSampleOp31 = 0;
        recordCursor[packetWordsOp31 + 0xaa] = pitchPixels - 1 & 0x3fff | (maxX & 0x800) << 4 | (maxY & 0x800) << 5
        ;
        recordCursor[packetWordsOp31 + 0xb] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
        bufferFormatIdOp31 = selectedBuffer[0x3a];
        singleSample = (M<UInt32>(selectedBuffer + 0x3c) & 0xf00000) == 0;
        cr0Bits = singleSample << 1;
        if (!singleSample) {
          widthPerSampleOp31 = (UInt32)M<UInt16>(selectedBuffer + 0x14) / (M<UInt32>(selectedBuffer + 0x3c) >> 0x14 & 0xf);
        }
        pitchPixels = 0x20 / M<UInt16>(selectedBuffer + 0x16);
        if (0x20 / M<UInt16>(selectedBuffer + 0x16) <= widthPerSampleOp31) {
          pitchPixels = widthPerSampleOp31;
        }
        levelOffset0Op37 = M<SInt32>(selectedBuffer + 0x40);
        bufferPitch = M<UInt16>(selectedBuffer + 0x20);
        bufferFlags = selectedBuffer[0x38];
        surfaceBaseAddress = M<SInt32>(selectedBuffer + 8);
        if ((layerCount != 0) && (0 < (SInt32)layerCount)) {
          do {
            if ((UInt8)bufferFlags >> 1 == 0) {
              maxY = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)bufferFormatIdOp31 * 0x1c);
              sizeShiftAdjust = 0;
            }
            else {
              maxY = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)bufferFormatIdOp31 * 0x1c);
              sizeShiftAdjust = -(maxY >> 8 & 3);
            }
            maxY = maxY >> 0xc & 7;
            scaledOffset = (SInt32)*stateWordCursor >> ((sizeShiftAdjust - maxY) + 5 & 0x3f);
            if (((UInt8)bufferFlags & 1) == 0) {
              scaledOffset = scaledOffset << 5;
            }
            else {
              scaledOffset = (scaledOffset << 0xc) >> 3;
            }
            *stateWordCursor = 0x1150;
            stateWordCursor[1] = (UInt32)bufferPitch * levelOffset0Op37 + surfaceBaseAddress + scaledOffset + (pitchPixels * stateWordCursor[1] << maxY) &
                         0xffffffe0 | ((UInt8)bufferFlags >> 1 & 3) << 3 | ((UInt8)bufferFlags & 1) << 2;
            savedWord2 = stateWordCursor[2];
            maxY = recordCursor[packetWordsOp31 + 0xa6];
            stateWordCursor[2] = 0x1120;
            stateWordCursor[3] = (stateWordCursor[3] - 1) * 0x800 & 0x3ff800 |
                         savedWord2 - 1 & 0x7ff | maxY & 0xffc00000;
            stateWordCursor = stateWordCursor + 0x10;
            layerCount = layerCount - 1;
          } while (layerCount != 0);
        }
        goto nextRecord;
      }
      if (0x31000000 < opcode) {
        if (opcode == 0x34000000) {
          statusOffset = recordCursor[1] * 8;
          if (M<UInt32>(self + kIOATIR500GLContext_statusRegionSize) <= statusOffset) goto abortStreamUnreserve;
          *recordCursor = 0x578;
          accel = M<SInt32>(self + kIOATIR500GLContext_accelerator);
          stamp = M<UInt32>(accel + kIOATIR500Accelerator_submitStamp);
          recordCursor[1] = stamp;
          M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_statusRegion) + statusOffset) = stamp;
          M<UInt32>(accel + kIOATIR500Accelerator_submitStamp) = stamp + 1;
          M<UInt32>(statusOffset + M<SInt32>(self + kIOATIR500GLContext_statusRegion) + 4) = 0;
          reservedWords = reservedWords + 1;
        }
        else if (opcode < 0x34000001) {
          if (opcode == 0x32000000) {
            slotTexture = M<SInt32>(self + kATIR500GLContext_textureSlots);
            flushRegionWords = recordCursor[2];
            if ((slotTexture != 0) &&
               ((M<char>(slotTexture + 0x20) == '\x06' || (M<SInt32>(slotTexture + 0x48) != 0)))) {
              levelWordOp3e = recordCursor[4];
              entryCount = recordCursor[5];
              if (flushRegionWords != 0) {
                attachmentTypeOp32 = recordCursor[3];
                if (attachmentTypeOp32 == 8) {
slotIsDepth8Op32:
                  attachment = 8;
                }
                else {
                  if (attachmentTypeOp32 < 9) {
                    if (attachmentTypeOp32 == 7) {
slotIsDepth7Op32:
                      attachment = 7;
                      goto slotSelectedOp32;
                    }
                  }
                  else {
                    if (attachmentTypeOp32 == 10) goto slotIsDepth7Op32;
                    if (attachmentTypeOp32 == 0xb) goto slotIsDepth8Op32;
                  }
                  attachment = 6;
                }
slotSelectedOp32:
                if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                  surfaceObject = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
                  selectedBuffer = M<UInt8 *>(surfaceObject + attachment * 4 + kIOATIR500Surface_attachmentBuffers);
                }
                else {
                  surfaceObject = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
                  selectedBuffer = (UInt8 *)(self + kATIR500GLContext_textureDepthBuffer);
                }
                emittedWords = ((ATIR500Surface *)(surfaceObject))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(selectedBuffer),0,(UInt32 *)(recordCursor + -flushRegionWords));
                nopHeader = 0x80000000;
                if (flushRegionWords - emittedWords != 1) {
                  nopHeader = ((flushRegionWords - emittedWords) + -2) * 0x10000 | 0xc0001000;
                }
                (recordCursor + -flushRegionWords)[emittedWords] = nopHeader;
                slotTexture = M<SInt32>(self + kATIR500GLContext_textureSlots);
              }
              levelIndexOffset = (levelWordOp3e >> 0x10) * 2;
              levelEntryPtrOp32 = levelIndexOffset + M<SInt32>(slotTexture + 0x14);
              levelBit = (UInt16)(1 << (levelWordOp3e & 0x3f));
              M<UInt16>(levelEntryPtrOp32 + 0x28) = levelBit | M<UInt16>(levelEntryPtrOp32 + 0x28);
              levelEntryPtrOp44 = levelIndexOffset + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(levelEntryPtrOp44 + 0x1c) = M<UInt16>(levelEntryPtrOp44 + 0x1c) & ~levelBit;
              *recordCursor = 0xc0051000;
              convertIOGLBufferToBufIdx(recordCursor[3],(UInt32 *)&bufferIndexOut);
              if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                mipLevelOp32 = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
                surfaceIndexOp32 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
                nextLevel = mipLevelOp32 + 1;
                surfaceBuffer = *(UInt8 **)
                           ((SInt32)bufferIndexOut * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
              }
              else if (recordCursor[3] == 4) {
                surfaceBuffer = self + kATIR500GLContext_textureDepthBuffer;
                nextLevel = 1;
                mipLevelOp32 = 0;
                surfaceIndexOp32 = 0;
              }
              else {
                nextLevel = 1;
                mipLevelOp32 = 0;
                surfaceIndexOp32 = 0;
                surfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
              }
              bufferFormatId = surfaceBuffer[0x3a];
              recordCursor[0xa7] =
                   ((UInt8)surfaceBuffer[0x38] & 7) << 2 |
                   M<SInt32>(surfaceBuffer + mipLevelOp32 * 4 + 0x40) * (UInt32)M<UInt16>(surfaceBuffer + 0x20) +
                   surfaceIndexOp32 * (M<SInt32>(surfaceBuffer + nextLevel * 4 + 0x40) -
                            M<SInt32>(surfaceBuffer + mipLevelOp32 * 4 + 0x40)) + M<SInt32>(surfaceBuffer + 8) &
                   0xffffffe0;
              if (((M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0) ||
                 (nextLevel = (SInt32)((UInt32)M<UInt16>(surfaceBuffer + 0x1c) /
                                (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf)) >> (mipLevelOp32 & 0x3f),
                 nextLevel == 0)) {
                maxXOp32 = 0;
              }
              else {
                maxXOp32 = nextLevel - 1;
              }
              maxYOp32 = 0;
              mipHeight = (SInt32)(UInt32)M<UInt16>(surfaceBuffer + 0x1e) >> (mipLevelOp32 & 0x3f);
              if (mipHeight != 0) {
                maxYOp32 = mipHeight - 1;
              }
              recordCursor[0xad] = maxXOp32 & 0x7ff | (maxYOp32 & 0x7ff) << 0xb | 0x80000000;
              formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)bufferFormatId * 0x1c);
              recordCursor[0xaf] =
                   formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
                   formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
              sampleInfoOp32 = M<UInt32>(surfaceBuffer + 0x3c);
              singleSample = (sampleInfoOp32 & 0xf00000) == 0;
              if (singleSample) {
                widthPerSampleOp05 = 0;
              }
              else {
                widthPerSampleOp05 = (SInt32)((UInt32)M<UInt16>(surfaceBuffer + 0x14) / (sampleInfoOp32 >> 0x14 & 0xf)) >>
                         (mipLevelOp32 & 0x3f);
              }
              pitchPixels = 0x20 / M<UInt16>(surfaceBuffer + 0x16);
              if (0x20 / M<UInt16>(surfaceBuffer + 0x16) <= widthPerSampleOp05) {
                pitchPixels = widthPerSampleOp05;
              }
              if ((singleSample) ||
                 (mipHeight = (SInt32)((UInt32)M<UInt16>(surfaceBuffer + 0x1c) / (sampleInfoOp32 >> 0x14 & 0xf)) >>
                           (mipLevelOp32 & 0x3f), mipHeight == 0)) {
                maxXOp32 = 0;
              }
              else {
                maxXOp32 = mipHeight - 1;
              }
              maxYOp32 = 0;
              mipHeight = (SInt32)(UInt32)M<UInt16>(surfaceBuffer + 0x1e) >> (mipLevelOp32 & 0x3f);
              if (mipHeight != 0) {
                maxYOp32 = mipHeight - 1;
              }
              offsetWord = recordCursor[0xa1];
              recordCursor[0xb1] = pitchPixels - 1 & 0x3fff | (maxXOp32 & 0x800) << 4 | (maxYOp32 & 0x800) << 5;
              recordCursor[0x12] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
              stateWordCursor = recordCursor + 0xc4;
              widthPerSampleOp40 = 0;
              recordCursor[0xa1] = offsetWord + textureOffset;
              bufferFormatId = surfaceBuffer[0x3a];
              singleSample = (M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0;
              cr0Bits = singleSample << 1;
              if (!singleSample) {
                widthPerSampleOp40 = (SInt32)((UInt32)M<UInt16>(surfaceBuffer + 0x14) /
                              (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf)) >> (mipLevelOp32 & 0x3f);
              }
              pitchPixels = 0x20 / M<UInt16>(surfaceBuffer + 0x16);
              if (0x20 / M<UInt16>(surfaceBuffer + 0x16) <= widthPerSampleOp40) {
                pitchPixels = widthPerSampleOp40;
              }
              bufferPitch = M<UInt16>(surfaceBuffer + 0x20);
              surfaceBaseAddressOp32 = M<SInt32>(surfaceBuffer + 8);
              mipOffset = M<SInt32>(surfaceBuffer + mipLevelOp32 * 4 + 0x40);
              levelOffset1Op32 = M<SInt32>(surfaceBuffer + mipLevelOp32 * 4 + 0x44);
              bufferFlagsOp32 = surfaceBuffer[0x38];
              if ((entryCount != 0) && (0 < (SInt32)entryCount)) {
                do {
                  if ((UInt8)bufferFlagsOp32 >> 1 == 0) {
                    formatFieldDC = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)bufferFormatId * 0x1c);
                    sizeShiftAdjustOp32 = 0;
                  }
                  else {
                    formatFieldDC = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)bufferFormatId * 0x1c);
                    sizeShiftAdjustOp32 = -(formatFieldDC >> 8 & 3);
                  }
                  texelShift = formatFieldDC >> 0xc & 7;
                  scaledOffsetOp32 = (SInt32)*stateWordCursor >> ((sizeShiftAdjustOp32 - texelShift) + 5 & 0x3f);
                  if (((UInt8)bufferFlagsOp32 & 1) == 0) {
                    scaledOffsetOp32 = scaledOffsetOp32 << 5;
                  }
                  else {
                    scaledOffsetOp32 = (scaledOffsetOp32 << 0xc) >> 3;
                  }
                  *stateWordCursor = 0x1150;
                  stateWordCursor[1] = ((UInt8)bufferFlagsOp32 >> 1 & 3) << 3 | ((UInt8)bufferFlagsOp32 & 1) << 2 |
                               mipOffset * (UInt32)bufferPitch + surfaceIndexOp32 * (levelOffset1Op32 - mipOffset) + surfaceBaseAddressOp32 +
                               scaledOffsetOp32 + (pitchPixels * stateWordCursor[1] << texelShift) & 0xffffffe0;
                  savedWord2Op32 = stateWordCursor[2];
                  heightRegWord = recordCursor[0xad];
                  stateWordCursor[2] = 0x1120;
                  stateWordCursor[3] = (stateWordCursor[3] - 1) * 0x800 & 0x3ff800 |
                               savedWord2Op32 - 1 & 0x7ff | heightRegWord & 0xffc00000;
                  stateWordCursor = stateWordCursor + 0x10;
                  entryCount = entryCount - 1;
                } while (entryCount != 0);
              }
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0x80) =
                   M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
              goto markTextureUsed;
            }
            recordCursor[-flushRegionWords] = (flushRegionWords + recordCursor[1] + -2) * 0x10000 | 0xc0001000;
          }
          else if (opcode == 0x33000000) {
            if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
              surfaceBase = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
              mipLevelOp32 = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
              surfaceIndexOp32 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
              depthBufferOp33 = M<UInt8 *>((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + surfaceBase + kIOATIR500Surface_attachmentBuffers);
              colorBuffer = M<UInt8 *>((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + surfaceBase + kIOATIR500Surface_attachmentBuffers);
              nextMipLevelOp33 = mipLevelOp32 + 1;
              colorBufferRecord = (UInt8 *)((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 0x78 + surfaceBase + kIOATIR500Surface_buffers);
            }
            else {
              depthBufferOp33 = self + kATIR500GLContext_textureDepthBuffer;
              surfaceIndexOp32 = 0;
              mipLevelOp32 = 0;
              nextMipLevelOp33 = 1;
              colorBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
              colorBufferRecord = colorBuffer;
            }
            recordFlags = recordCursor[1];
            *recordCursor = 0xc0001000;
            widthPerSampleOp40 = 0;
            formatByteOffset = (UInt32)(UInt8)colorBuffer[0x3a] * 0x1c;
            recordCursor[0x9c] =
                 M<SInt32>(colorBuffer + mipLevelOp32 * 4 + 0x40) * (UInt32)M<UInt16>(colorBuffer + 0x20) +
                 surfaceIndexOp32 * (M<SInt32>(colorBuffer + nextMipLevelOp33 * 4 + 0x40) -
                          M<SInt32>(colorBuffer + mipLevelOp32 * 4 + 0x40)) + M<SInt32>(colorBuffer + 8) &
                 0xffffffe0;
            if ((M<UInt32>(colorBuffer + 0x3c) & 0xf00000) != 0) {
              widthPerSampleOp40 = (SInt32)((UInt32)M<UInt16>(colorBuffer + 0x14) /
                            (M<UInt32>(colorBuffer + 0x3c) >> 0x14 & 0xf)) >> (mipLevelOp32 & 0x3f);
            }
            pitchPixels = 0x20 / M<UInt16>(colorBuffer + 0x16);
            if (0x20 / M<UInt16>(colorBuffer + 0x16) <= widthPerSampleOp40) {
              pitchPixels = widthPerSampleOp40;
            }
            savedFormatRegOp31 = recordCursor[0x8c];
            recordCursor[0x9e] =
                 pitchPixels & 0x3ffe | ((UInt8)colorBuffer[0x38] & 1) << 0x10 |
                 ((UInt8)colorBuffer[0x38] & 6) << 0x10 | ((UInt8)colorBuffer[0x39] & 3) << 0x13 |
                 FormatTableLookup_0x0004d2e0((UInt32)(UInt8)colorBuffer[0x3a] * 0x1c) >> 1 & 0x1e00000;
            formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
            recordCursor[0x8c] = formatFieldE0 | savedFormatRegOp31 & 0xffffffe0;
            formatBits300 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
            recordCursor[0x8c] = formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xfffffce0;
            formatBitsC00 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
            recordCursor[0x8c] = formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xfffff0e0;
            formatBits3000 = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
            recordCursor[0x8c] = formatBits3000 | formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xffffc0e0;
            recordCursor[0x8c] =
                 (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
                 formatBits3000 | formatBitsC00 | formatBits300 | formatFieldE0 | savedFormatRegOp31 & 0xffff00e0;
            hyperzEnable = this->compute_sc_hyperz_en(recordCursor[0x14]);
            recordCursor[0x14] = hyperzEnable;
            zbBwCntl = this->compute_zb_bw_cntl(recordCursor[0x16]);
            recordCursor[0x16] = zbBwCntl;
            accelFlags = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
            recordCursor[0xae] = 0xaaaa;
            recordCursor[0xd] = accelFlags;
            if ((((M<UInt32>(colorBufferRecord + 0x28) & 0x3ff00000) == 0x3ff00000) ||
                (colorBufferRecord[0x36] == 0x0)) ||
               (((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xbe8) & 0x700000) == 0 ||
                (M<SInt16>(self + kIOATIR500GLContext_colorBufferIndex) != 9)))) {
              recordCursor[0x22] = 0;
            }
            else {
              recordCursor[0x22] = 0x600;
            }
            boundTexture = M<UInt8 *>(self + kATIR500GLContext_textureSlots);
            if (boundTexture == (UInt8 *)0x0) {
              recordCursor[0xa1] = 0xc0001000;
            }
            else {
              texFormatFlags = M<UInt8>(M<SInt32>(boundTexture + 0x14) + 0x15);
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(boundTexture),false);
              recordCursor[0xa2] = texFormatFlags & 0x1f | textureOffset & 0xffffffe0;
            }
            flagBit1Clear = (recordFlags & 2) == 0;
            cr0Bits = flagBit1Clear << 1;
            if (!flagBit1Clear) {
              formatFieldE0 = 0;
              recordCursor[0xc0] = -((UInt8)depthBufferOp33[0x3a] ^ 0x10) >> 0x1e & 2;
              recordCursor[0xc2] = M<UInt32>(depthBufferOp33 + 8);
              if ((M<UInt32>(depthBufferOp33 + 0x3c) & 0xf00000) != 0) {
                formatFieldE0 = (UInt32)M<UInt16>(depthBufferOp33 + 0x14) /
                         (M<UInt32>(depthBufferOp33 + 0x3c) >> 0x14 & 0xf);
              }
              pitchPixels = 0x20 / M<UInt16>(depthBufferOp33 + 0x16);
              if (0x20 / M<UInt16>(depthBufferOp33 + 0x16) <= formatFieldE0) {
                pitchPixels = formatFieldE0;
              }
              formatFieldE0 = 0;
              depthPitchRegWord = ((UInt8)depthBufferOp33[0x38] & 6) << 0x10 |
                         ((UInt8)depthBufferOp33[0x38] & 1) << 0x10 |
                         ((UInt8)depthBufferOp33[0x39] & 3) << 0x13 | pitchPixels & 0x3ffc | depthPitchRegWord & 0xffe0c003
              ;
              recordCursor[0xc3] = depthPitchRegWord;
              singleSample = (M<UInt32>(depthBufferOp33 + 0x3c) & 0xf00000) == 0;
              cr0Bits = singleSample << 1;
              if (!singleSample) {
                formatFieldE0 = (UInt32)M<UInt16>(depthBufferOp33 + 0x14) /
                         (M<UInt32>(depthBufferOp33 + 0x3c) >> 0x14 & 0xf);
              }
              pitchPixels = 0x20 / M<UInt16>(depthBufferOp33 + 0x16);
              if (0x20 / M<UInt16>(depthBufferOp33 + 0x16) <= formatFieldE0) {
                pitchPixels = formatFieldE0;
              }
              formatByteOffset = 0x20;
              if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) == 4) {
alignColorPitch:
                alignedPitchOp33 = formatByteOffset * ((SInt32)(formatByteOffset + pitchPixels + -1) / formatByteOffset);
              }
              else {
                formatByteOffset = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) << 4;
                cr0Bits = (formatByteOffset == 0) << 1;
                alignedPitchOp33 = 0;
                if (formatByteOffset != 0) goto alignColorPitch;
              }
              recordCursor[0xc5] = alignedPitchOp33;
              hzBlockOffset = HZMEM_GetBlockOffset
                                 ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                  M<UInt32>(depthBufferOp33 + 0x28),0);
              recordCursor[199] = hzBlockOffset;
              recordCursor[0xc9] = M<UInt32>(depthBufferOp33 + 0x2c);
            }
          }
        }
        else if (opcode == 0x35000000) {
          currentTexture = M<SInt32>(self + kATIR500GLContext_textureSlots);
          if ((currentTexture == 0) ||
             ((M<char>(currentTexture + 0x20) != '\x06' && (M<SInt32>(currentTexture + 0x48) == 0))))
          goto nopRecordCountedOrSingle;
          levelIndexOffsetOp35 = recordCursor[2] >> 0xf & 0x1fffe;
          levelEntryPtrOp32 = levelIndexOffsetOp35 + M<SInt32>(currentTexture + 0x14);
          levelBit = (UInt16)(1 << (recordCursor[2] & 0x3f));
          M<UInt16>(levelEntryPtrOp32 + 0x28) = levelBit | M<UInt16>(levelEntryPtrOp32 + 0x28);
          levelEntryPtrOp32 = levelIndexOffsetOp35 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
          M<UInt16>(levelEntryPtrOp32 + 0x1c) = M<UInt16>(levelEntryPtrOp32 + 0x1c) & ~levelBit;
          *recordCursor = 0xc0011000;
          offsetWord = recordCursor[0x9d];
          recordCursor[0xe] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
          textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
          recordCursor[0x9d] = offsetWord + textureOffset;
          recordCursor[0xa3] =
               M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
               ((SInt32)recordCursor - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20) & 0xfffffffcU) + 0x20 +
               (recordCursor[0xa3] >> 3 & 0x1ffffffc) & 0xffffffe0 | recordCursor[0xa3] & 0x1f;
markTextureUsed:
          M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0xc) =
               M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
        }
        else if (opcode == 0x36000000) {
          previousPinned = M<SInt32>(self + kATIR500GLContext_pinnedTexture);
          transferBuffer = (UInt8 *)recordCursor[1];
          if ((previousPinned != 0) && (M<SInt32>(previousPinned + 0x48) == 0)) {
            M<SInt16>(previousPinned + 0xe) = M<SInt16>(previousPinned + 0xe) + -1;
          }
          if (((M<SInt32>(transferBuffer + 0x48) == 0) &&
              (M<SInt16>(transferBuffer + 0xe) = M<SInt16>(transferBuffer + 0xe) + 1, M<SInt32>(transferBuffer + 4) == 0
              )) && (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(transferBuffer)),
                    M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0)) {
            ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
          }
          M<UInt32>(transferBuffer + 0x5c) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
          M<UInt8 *>(self + kATIR500GLContext_pinnedTexture) = transferBuffer;
          bufferGartBase = M<SInt32>(transferBuffer + 0x48);
          baseOffset = recordCursor[3];
          pairCountOp38 = recordCursor[2] + 1 >> 1;
          if (bufferGartBase == 0) {
            bufferGartBase = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(transferBuffer + 4);
          }
          *recordCursor = 0x80000000;
          recordCursor[1] = 0x80000000;
          recordCursor[2] = 0x80000000;
          recordCursor[3] = 0x80000000;
          if (pairCountOp38 != 0) {
            entryWordIndex = 6;
            entryByteOffset = 0x1c;
            entryCursor = recordCursor;
            do {
              recordCursor[entryWordIndex] = baseOffset + bufferGartBase + entryCursor[6] * 4;
              M<UInt32>((SInt32)recordCursor + entryByteOffset) = baseOffset + bufferGartBase + entryCursor[7] * 4;
              entryCursor = entryCursor + 3;
              entryWordIndex = entryWordIndex + 3;
              entryByteOffset = entryByteOffset + 0xc;
              pairCountOp38 = pairCountOp38 - 1;
            } while (pairCountOp38 != 0);
          }
        }
        goto nextRecord;
      }
      if (opcode != 0x2d000000) {
        if (opcode < 0x2d000001) {
          if (opcode == 0x2b000000) {
            if (pendingWords != 0) {
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
              submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)
                                  ,streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
              M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = submitStamp;
              pendingBytes = pendingWords * 4;
              pendingWords = 0;
              streamOffset = pendingBytes + streamOffset;
              reservedWords = 0;
            }
            *recordCursor = 0x80000000;
          }
          else if (opcode == 0x2c000000) {
            if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
              mipLevelOp28 = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
              surfaceIndexOp28 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
              nextMipLevelOp28 = mipLevelOp28 + 1;
              surfaceBuffer = *(UInt8 **)
                         ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
            }
            else {
              surfaceIndexOp28 = 0;
              mipLevelOp28 = 0;
              nextMipLevelOp28 = 1;
              surfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
            }
            singleSample = (M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0;
            cr0Bits = singleSample << 1;
            widthPerSample = 0;
            if (!singleSample) {
              widthPerSample = (UInt32)M<UInt16>(surfaceBuffer + 0x14) / (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf)
              ;
            }
            pitchPixels = 0x20 / M<UInt16>(surfaceBuffer + 0x16);
            if (pitchPixels <= widthPerSample) {
              pitchPixels = widthPerSample;
            }
            tiledFlagBit = 0x80000000;
            if ((UInt8)surfaceBuffer[0x38] < 2) {
              tiledFlagBit = 0;
            }
            *recordCursor = tiledFlagBit | M<SInt32>(surfaceBuffer + mipLevelOp28 * 4 + 0x40) *
                                (UInt32)M<UInt16>(surfaceBuffer + 0x20) +
                                surfaceIndexOp28 * (M<SInt32>(surfaceBuffer + nextMipLevelOp28 * 4 + 0x40) -
                                         M<SInt32>(surfaceBuffer + mipLevelOp28 * 4 + 0x40)) +
                                M<SInt32>(surfaceBuffer + 8) >> 10 |
                                pitchPixels * M<UInt16>(surfaceBuffer + 0x16) * 0x10000 & 0x3fc00000 |
                                ((UInt8)surfaceBuffer[0x38] & 1) << 0x1e;
            recordYHi = recordCursor[1] >> 0x10;
            mergedYHi = M<UInt32>(self + kATIR500GLContext_scissorY) >> 0x10;
            recordXLo = recordCursor[2] & 0xffff;
            mergedXLo = M<UInt32>(self + kATIR500GLContext_scissorX) & 0xffff;
            recordYLo = recordCursor[1] & 0xffff;
            mergedYLo = M<UInt32>(self + kATIR500GLContext_scissorY) & 0xffff;
            recordXHi = recordCursor[2] >> 0x10;
            mergedXHi = M<UInt32>(self + kATIR500GLContext_scissorX) >> 0x10;
            if (mergedYHi < recordYHi) {
              mergedYHi = recordYHi;
            }
            if (mergedYLo < recordYLo) {
              mergedYLo = recordYLo;
            }
            if (recordXHi < mergedXHi) {
              mergedXHi = recordXHi;
            }
            if (recordXLo < mergedXLo) {
              mergedXLo = recordXLo;
            }
            recordCursor[1] = mergedYLo | mergedYHi << 0x10;
            recordCursor[2] = mergedXLo | mergedXHi << 0x10;
          }
        }
        else if (opcode == 0x2f000000) {
          *recordCursor = 0x80000000;
          hyperzEnable = this->compute_sc_hyperz_en(recordCursor[2]);
          recordCursor[2] = hyperzEnable;
          zbBwCntl = this->compute_zb_bw_cntl(recordCursor[4]);
          recordCursor[4] = zbBwCntl;
          VCALL(M<SInt32>(self), 0x5a4)(self);
        }
        else if (opcode == 0x30000000) {
          wordCount = recordCursor[1];
          switch(recordCursor[2]) {
          default:
            attachmentId = 1;
            break;
          case 1:
            attachmentId = 0;
            break;
          case 2:
            attachmentId = 4;
            break;
          case 3:
            attachmentId = 5;
            break;
          case 7:
            attachmentId = 2;
            break;
          case 8:
            attachmentId = 3;
          }
          resolvedEnd = (UInt32 *)((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->resolve_fsaa_buffer((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex),attachmentId,(UInt32 *)(recordCursor),
                                       (bool)('\x01' - (recordCursor[3] == 0)),recordCursor[4],recordCursor[5],
                                       recordCursor[6],recordCursor[7]);
          if (resolvedEnd < recordCursor + wordCount) {
            remainingBytes = (SInt32)(recordCursor + wordCount) - (SInt32)resolvedEnd;
            if (remainingBytes - 4U < 4) {
              *resolvedEnd = 0x80000000;
            }
            else {
              *resolvedEnd = ((remainingBytes >> 2) + -2) * 0x10000 | 0xc0001000;
            }
          }
        }
        goto nextRecord;
      }
      recordPayloadEnd = recordCursor + recordCursor[1];
      switch(recordCursor[2]) {
      default:
        attachmentIndex = 1;
        break;
      case 1:
        attachmentIndex = 0;
        break;
      case 2:
        attachmentIndex = 4;
        break;
      case 3:
        attachmentIndex = 5;
        break;
      case 4:
        attachmentIndex = 6;
        break;
      case 7:
        attachmentIndex = 2;
        break;
      case 8:
        attachmentIndex = 3;
        break;
      case 10:
        attachmentIndex = 7;
        break;
      case 0xb:
        attachmentIndex = 8;
      }
      srcX = recordCursor[3];
      srcY = recordCursor[4];
      blitWidth = recordCursor[5];
      blitHeight = recordCursor[6];
      dstX = recordCursor[7];
      dstY = recordCursor[8];
      *recordCursor = (recordCursor[1] - 2) * 0x10000 | 0xc0001000;
      if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
        mipLevelOp2d = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
        surfaceIndexOp32 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
        nextMipLevelOp33 = mipLevelOp2d + 1;
        attachmentBuffer = M<UInt8 *>(attachmentIndex * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
        renderBuffer = *(UInt8 **)
                   (M<SInt32>(self + kATIR500GLContext_renderBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
      }
      else {
        surfaceIndexOp32 = 0;
        mipLevelOp2d = 0;
        nextMipLevelOp33 = 1;
        attachmentBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
        renderBuffer = attachmentBuffer;
      }
      tailCursor = recordCursor + 0xbd;
      GH_memcpy(recordCursor,&g_r500_3d_blit_state_packet,0x2f4);
      formatByteOffset = (UInt32)(UInt8)renderBuffer[0x3a] * 0x1c;
      widthPerSampleOp2d = 0;
      recordCursor[0x9a] =
           M<SInt32>(renderBuffer + mipLevelOp2d * 4 + 0x40) * (UInt32)M<UInt16>(renderBuffer + 0x20) +
           surfaceIndexOp32 * (M<SInt32>(renderBuffer + nextMipLevelOp33 * 4 + 0x40) - M<SInt32>(renderBuffer + mipLevelOp2d * 4 + 0x40))
           + M<SInt32>(renderBuffer + 8) & 0xffffffe0;
      if ((M<UInt32>(renderBuffer + 0x3c) & 0xf00000) != 0) {
        widthPerSampleOp2d = (SInt32)((UInt32)M<UInt16>(renderBuffer + 0x14) / (M<UInt32>(renderBuffer + 0x3c) >> 0x14 & 0xf)
                      ) >> (mipLevelOp2d & 0x3f);
      }
      pitchPixels = 0x20 / M<UInt16>(renderBuffer + 0x16);
      if (0x20 / M<UInt16>(renderBuffer + 0x16) <= widthPerSampleOp2d) {
        pitchPixels = widthPerSampleOp2d;
      }
      savedFormatRegOp2d = recordCursor[0x8a];
      recordCursor[0x9c] =
           pitchPixels & 0x3ffe | ((UInt8)renderBuffer[0x38] & 1) << 0x10 | ((UInt8)renderBuffer[0x38] & 6) << 0x10 |
           ((UInt8)renderBuffer[0x39] & 3) << 0x13 |
           FormatTableLookup_0x0004d2e0((UInt32)(UInt8)renderBuffer[0x3a] * 0x1c) >> 1 & 0x1e00000;
      formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
      recordCursor[0x8a] = formatFieldE0 | savedFormatRegOp2d & 0xffffffe0;
      formatBits300 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
      recordCursor[0x8a] = formatBits300 | formatFieldE0 | savedFormatRegOp2d & 0xfffffce0;
      formatBitsC00Op2d = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
      recordCursor[0x8a] = formatBitsC00Op2d | formatBits300 | formatFieldE0 | savedFormatRegOp2d & 0xfffff0e0;
      formatBits3000Op2d = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
      recordCursor[0x8a] = formatBits3000Op2d | formatBitsC00Op2d | formatBits300 | formatFieldE0 | savedFormatRegOp2d & 0xffffc0e0;
      recordCursor[0x8a] =
           (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
           formatBits3000Op2d | formatBitsC00Op2d | formatBits300 | formatFieldE0 | savedFormatRegOp2d & 0xffff00e0;
      if (((M<UInt32>(renderBuffer + 0x3c) & 0xf00000) == 0) ||
         (mipWidthOp2d = (SInt32)((UInt32)M<UInt16>(renderBuffer + 0x1c) /
                        (M<UInt32>(renderBuffer + 0x3c) >> 0x14 & 0xf)) >> (mipLevelOp2d & 0x3f), mipWidthOp2d == 0))
      {
        formatFieldE0 = 0;
      }
      else {
        formatFieldE0 = mipWidthOp2d - 1;
      }
      maxYOp2d = 0;
      mipHeight = (SInt32)(UInt32)M<UInt16>(renderBuffer + 0x1e) >> (mipLevelOp2d & 0x3f);
      if (mipHeight != 0) {
        maxYOp2d = mipHeight - 1;
      }
      recordCursor[0xb3] = formatFieldE0 & 0x1fff | (maxYOp2d & 0x1fff) << 0xd;
      bufferFormatId = attachmentBuffer[0x3a];
      recordCursor[0xa0] =
           ((UInt8)attachmentBuffer[0x38] & 7) << 2 |
           M<SInt32>(attachmentBuffer + mipLevelOp2d * 4 + 0x40) * (UInt32)M<UInt16>(attachmentBuffer + 0x20) +
           surfaceIndexOp32 * (M<SInt32>(attachmentBuffer + nextMipLevelOp33 * 4 + 0x40) - M<SInt32>(attachmentBuffer + mipLevelOp2d * 4 + 0x40))
           + M<SInt32>(attachmentBuffer + 8) & 0xffffffe0;
      if (((M<UInt32>(attachmentBuffer + 0x3c) & 0xf00000) == 0) ||
         (mipWidthOp2d = (SInt32)((UInt32)M<UInt16>(attachmentBuffer + 0x1c) /
                        (M<UInt32>(attachmentBuffer + 0x3c) >> 0x14 & 0xf)) >> (mipLevelOp2d & 0x3f), mipWidthOp2d == 0))
      {
        formatFieldE0 = 0;
      }
      else {
        formatFieldE0 = mipWidthOp2d - 1;
      }
      maxYOp2d = 0;
      mipHeight = (SInt32)(UInt32)M<UInt16>(attachmentBuffer + 0x1e) >> (mipLevelOp2d & 0x3f);
      if (mipHeight != 0) {
        maxYOp2d = mipHeight - 1;
      }
      recordCursor[0xa6] = formatFieldE0 & 0x7ff | (maxYOp2d & 0x7ff) << 0xb | 0x80000000;
      formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)bufferFormatId * 0x1c);
      recordCursor[0xa8] =
           formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
           formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
      sampleInfoOp2d = M<UInt32>(attachmentBuffer + 0x3c);
      singleSample = (sampleInfoOp2d & 0xf00000) == 0;
      if (singleSample) {
        widthPerSampleOp31 = 0;
      }
      else {
        widthPerSampleOp31 = (SInt32)((UInt32)M<UInt16>(attachmentBuffer + 0x14) / (sampleInfoOp2d >> 0x14 & 0xf)) >>
                 (mipLevelOp2d & 0x3f);
      }
      pitchPixels = 0x20 / M<UInt16>(attachmentBuffer + 0x16);
      if (0x20 / M<UInt16>(attachmentBuffer + 0x16) <= widthPerSampleOp31) {
        pitchPixels = widthPerSampleOp31;
      }
      if ((singleSample) ||
         (mipWidthOp2d = (SInt32)((UInt32)M<UInt16>(attachmentBuffer + 0x1c) / (sampleInfoOp2d >> 0x14 & 0xf)) >>
                   (mipLevelOp2d & 0x3f), mipWidthOp2d == 0)) {
        maxXOp2d = 0;
      }
      else {
        maxXOp2d = mipWidthOp2d - 1;
      }
      mipHeightMinus1 = 0;
      mipHeight = (SInt32)(UInt32)M<UInt16>(attachmentBuffer + 0x1e) >> (mipLevelOp2d & 0x3f);
      if (mipHeight != 0) {
        mipHeightMinus1 = mipHeight - 1;
      }
      xOffsetCvtLo = srcX - dstX ^ 0x80000000;
      recordCursor[0xaa] = pitchPixels - 1 & 0x3fff | (maxXOp2d & 0x800) << 4 | (mipHeightMinus1 & 0x800) << 5;
      accelFlags = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
      recordCursor[0xaf] = 0xc0001000;
      recordCursor[0x11] = 0xc0001000;
      recordCursor[0x13] = 0xc0001000;
      recordCursor[0x15] = 0xc0001000;
      recordCursor[0x1d] = 0xc0001000;
      recordCursor[0x2d] = 0xc0001000;
      recordCursor[0x2f] = 0xc0001000;
      recordCursor[0xb] = accelFlags;
      recordCursor[0x31] = 0xc0001000;
      recordCursor[0x33] = 0xc0001000;
      recordCursor[0x35] = 0xc0001000;
      recordCursor[0xad] = 0xc0001000;
      recordCursor[0xb1] = 0xc0011000;
      recordCursor[0xa2] = recordCursor[0xa2] & 0xffffe600 | 0x11b6;
      fpMagicBias = DOUBLE_0004c3a8;
      scaleY = FLOAT_0004c380;
      subpixelScale = FLOAT_0004c37c;
      scaleX = FLOAT_0004c374;
      dstYCvtLo = dstY ^ 0x80000000;
      dstYCvtHi = 0x43300000;
      xOffsetCvtHi = 0x43300000;
      dstRightCvtLo = blitWidth + dstX;
      dstXCvtLo = dstX ^ 0x80000000;
      dstBottomCvtLo = blitHeight + dstY;
      dstXCvtHi = 0x43300000;
      dstRightCvtHi = 0x43300000;
      dstBottomCvtHi = 0x43300000;
      yOffsetCvtHi = 0x43300000;
      yOffsetCvtLo = srcY - dstY ^ 0x80000000;
      bufferWidth = (UInt32)M<UInt16>(attachmentBuffer + 0x1c);
      bufferHeightOp2d = (UInt32)M<UInt16>(attachmentBuffer + 0x1e);
      dstTopF = (float)((double)CONCAT44d(0x43300000,dstY ^ 0x80000000) - DOUBLE_0004c3a8);
      xOffsetF = (float)((double)CONCAT44d(0x43300000,xOffsetCvtLo) - DOUBLE_0004c3a8);
      dstLeftF = (float)((double)CONCAT44d(0x43300000,dstX ^ 0x80000000) - DOUBLE_0004c3a8);
      dstRightF = (float)((double)CONCAT44d(0x43300000,blitWidth + dstX) - DOUBLE_0004c3b0);
      dstBottomF = (float)((double)CONCAT44d(0x43300000,blitHeight + dstY) - DOUBLE_0004c3b0);
      yOffsetF = (float)((double)CONCAT44d(0x43300000,yOffsetCvtLo) - DOUBLE_0004c3a8);
      if ((bufferWidth < 0x1001) && (bufferHeightOp2d < 0x1001)) {
singleQuadPath:
        scaleX = FLOAT_0004c370;
        if (bufferWidth != 0) {
          widthCvtHi = 0x43300000;
          widthCvtLo = bufferWidth ^ 0x80000000;
          scaleX = FLOAT_0004c374 /
                   (float)((double)CONCAT44d(0x43300000,bufferWidth ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        scaleY = FLOAT_0004c370;
        if (bufferHeightOp2d != 0) {
          heightCvtLo = bufferHeightOp2d ^ 0x80000000;
          heightCvtHi = 0x43300000;
          scaleY = FLOAT_0004c374 /
                   (float)((double)CONCAT44d(0x43300000,bufferHeightOp2d ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        singleQuad = true;
        *tailCursor = 0x31080;
        recordCursor[0xc2] = 0x1087;
        tileCount = 0;
        recordCursor[0xbe] = FBITS(scaleX * (dstLeftF + xOffsetF));
        recordCursor[0xc0] = FBITS(scaleX * (dstRightF + xOffsetF));
        recordCursor[0xbf] = FBITS(scaleY * (dstBottomF + yOffsetF));
        recordCursor[0xc1] = FBITS(scaleY * (dstTopF + yOffsetF));
        quadWidthFixed = (SInt32)((dstRightF - dstLeftF) * subpixelScale);
        quadHeightFixed = (UInt32)(SInt32)((dstBottomF - dstTopF) * subpixelScale);
        quadWidthSpill = (SInt64)quadWidthFixed;
        quadHeightSpill = (SInt64)(SInt32)quadHeightFixed;
        centerXF = (dstLeftF + dstRightF) * FLOAT_0004c380;
        centerYF = (dstTopF + dstBottomF) * FLOAT_0004c380;
        recordCursor[0xc4] = 0xc0033500;
        recordCursor[0xc5] = 0x10031;
        recordCursor[0xc6] = FBITS(centerXF);
        recordCursor[199] = FBITS(centerYF);
        recordCursor[0xc3] = quadWidthFixed << 0x10 | quadHeightFixed;
        recordCursor[200] = 0;
      }
      else {
        srcTopF = dstTopF + yOffsetF;
        srcMaxY = dstBottomF + yOffsetF;
        srcLeftF = dstLeftF + xOffsetF;
        srcMaxX = dstRightF + xOffsetF;
        srcMinY = srcTopF;
        if (srcMaxY < srcTopF) {
          srcMinY = srcMaxY;
          srcMaxY = srcTopF;
        }
        srcMinX = srcLeftF;
        if (srcMaxX < srcLeftF) {
          srcMinX = srcMaxX;
          srcMaxX = srcLeftF;
        }
        pitchPixels = M<UInt16>(attachmentBuffer + 0x1c) & 0xfe00;
        srcMinXSpill = (SInt64)(SInt32)srcMinX;
        srcMinXMinus1 = (SInt32)srcMinX - 1;
        srcMinXAligned = (((SInt32)srcMinXMinus1 >> 9) + (UInt32)((SInt32)srcMinXMinus1 < 0 && (srcMinXMinus1 & 0x1ff) != 0)) * 0x200;
        tileXStart = 0;
        if ((-1 < (SInt32)srcMinXAligned) && (tileXStart = pitchPixels, (SInt32)srcMinXAligned <= (SInt32)pitchPixels)) {
          tileXStart = srcMinXAligned & 0xfe00;
        }
        tileYLimit = 0x40;
        if ((0x40 < bufferHeightOp2d) &&
           (tileYLimit = M<UInt16>(attachmentBuffer + 0x1e) & 0xffc0, (SInt32)(bufferHeightOp2d - tileYLimit) < 0x40)) {
          tileYLimit = tileYLimit - 0x40;
        }
        tileYStart = 0;
        srcMinYSpill = (SInt64)(SInt32)srcMinY;
        pitchPixels = (SInt32)srcMinY - 1;
        pitchPixels = (((SInt32)pitchPixels >> 6) + (UInt32)((SInt32)pitchPixels < 0 && (pitchPixels & 0x3f) != 0)) * 0x40;
        if ((-1 < (SInt32)pitchPixels) && (tileYStart = tileYLimit & 0xffff, (SInt32)pitchPixels <= (SInt32)tileYLimit)) {
          tileYStart = pitchPixels & 0xffc0;
        }
        tileXMin = 0x200;
        if (0x1ff < tileXStart) {
          tileXMin = tileXStart;
        }
        pitchPixels = bufferWidth - 1;
        tileXEnd = (((SInt32)pitchPixels >> 9) + (UInt32)((SInt32)pitchPixels < 0 && (pitchPixels & 0x1ff) != 0)) * 0x200;
        pitchPixels = (UInt32)(SInt32)srcMaxX;
        srcRightSpill = (SInt64)(SInt32)pitchPixels;
        if (FLOAT_0004c370 < srcMaxX) {
          srcRightIntCvtLo = pitchPixels ^ 0x80000000;
          srcRightIntCvtHi = 0x43300000;
          if ((float)((double)CONCAT44d(0x43300000,pitchPixels ^ 0x80000000) - DOUBLE_0004c3a8) < srcMaxX)
          {
            pitchPixels = pitchPixels + 1;
          }
        }
        if ((SInt32)pitchPixels <= (SInt32)tileXEnd) {
          tileXEnd = pitchPixels;
        }
        pitchPixels = 1;
        if ((SInt32)tileXMin < (SInt32)tileXEnd) {
          pitchPixels = (SInt32)((tileXEnd - tileXMin) + 0xbff) / 0xc00 & 0xff;
        }
        tileYMin = 0x40;
        if (0x3f < tileYStart) {
          tileYMin = tileYStart;
        }
        heightMinus1 = bufferHeightOp2d - 1;
        tileYEnd = (((SInt32)heightMinus1 >> 6) + (UInt32)((SInt32)heightMinus1 < 0 && (heightMinus1 & 0x3f) != 0)) * 0x40;
        srcBottomInt = (UInt32)(SInt32)srcMaxY;
        srcBottomSpill = (SInt64)(SInt32)srcBottomInt;
        if (FLOAT_0004c370 < srcMaxY) {
          srcBottomIntCvtHi = 0x43300000;
          srcBottomIntCvtLo = srcBottomInt ^ 0x80000000;
          if ((float)((double)CONCAT44d(0x43300000,srcBottomInt ^ 0x80000000) - DOUBLE_0004c3a8) < srcMaxY)
          {
            srcBottomInt = srcBottomInt + 1;
          }
        }
        if ((SInt32)srcBottomInt <= (SInt32)tileYEnd) {
          tileYEnd = srcBottomInt;
        }
        tileRows = 1;
        if ((SInt32)tileYMin < (SInt32)tileYEnd) {
          tileRows = (SInt32)((tileYEnd - tileYMin) + 0xf7f) / 0xf80 & 0xff;
        }
        tileCount = pitchPixels * tileRows & 0xff;
        if (tileCount == 0) goto singleQuadPath;
        singleQuad = false;
        if (tileRows != 0) {
          rowHeightLeft = bufferHeightOp2d - tileYStart;
          tileRow = 0;
          rowOffsetY = 0;
          quadY = tileYStart;
          quadCursor = tailCursor;
          do {
            if (pitchPixels != 0) {
              rowY = rowOffsetY + tileYStart;
              rowYCvtHi = 0x43300000;
              colWidthLeft = bufferWidth - tileXStart;
              tileCol = 0;
              rowYCvtLo = rowY ^ 0x80000000;
              rowYF = (float)((double)CONCAT44d(0x43300000,rowY ^ 0x80000000) - fpMagicBias);
              tileX = tileXStart;
              colsLeft = pitchPixels;
              do {
                *quadCursor = tileX;
                quadCursor[1] = quadY;
                quadWidth = colWidthLeft;
                if ((SInt32)(tileX + 0x1000) <= (SInt32)bufferWidth) {
                  quadWidth = 0x1000;
                }
                quadHeight = rowHeightLeft;
                if ((SInt32)(rowY + 0x1000) <= (SInt32)bufferHeightOp2d) {
                  quadHeight = 0x1000;
                }
                quadCursor[2] = quadWidth;
                quadCursor[3] = quadHeight;
                clipLeft = srcMinX;
                if (tileCol != 0) {
                  winLeftCvtHi = 0x43300000;
                  winLeftCvtLo = tileX + 0x200 ^ 0x80000000;
                  clipLeft = (float)((double)CONCAT44d(0x43300000,winLeftCvtLo) - fpMagicBias);
                }
                clipTop = srcMinY;
                if (tileRow != 0) {
                  winTopCvtHi = 0x43300000;
                  winTopCvtLo = rowY + 0x40 ^ 0x80000000;
                  clipTop = (float)((double)CONCAT44d(0x43300000,winTopCvtLo) - fpMagicBias);
                }
                winRight = srcMaxX;
                if (tileCol != pitchPixels - 1) {
                  winRightCvtHi = 0x43300000;
                  winRightCvtLo = tileX + 0xe00 ^ 0x80000000;
                  winRight = (float)((double)CONCAT44d(0x43300000,winRightCvtLo) - fpMagicBias);
                }
                clipBottom = srcMaxY;
                if (tileRow != tileRows - 1) {
                  winBottomCvtHi = 0x43300000;
                  winBottomCvtLo = rowY + 0xfc0 ^ 0x80000000;
                  clipBottom = (float)((double)CONCAT44d(0x43300000,winBottomCvtLo) - fpMagicBias);
                }
                bottomCand = srcMaxY;
                if (clipBottom - srcMaxY < 0.0) {
                  bottomCand = clipBottom;
                }
                topCand = srcMinY;
                if (srcMinY - clipTop < 0.0) {
                  topCand = clipTop;
                }
                leftCand = srcMinX;
                if (srcMinX - clipLeft < 0.0) {
                  leftCand = clipLeft;
                }
                clipRight = winRight;
                if (srcMaxX - winRight < 0.0) {
                  clipRight = srcMaxX;
                }
                if (-(srcMinY - clipTop) < 0.0) {
                  clipTop = topCand;
                }
                if (-(clipBottom - srcMaxY) < 0.0) {
                  clipBottom = bottomCand;
                }
                if (-(srcMinX - clipLeft) < 0.0) {
                  clipLeft = leftCand;
                }
                if (-(srcMaxX - winRight) < 0.0) {
                  clipRight = winRight;
                }
                dstTopClip = clipTop + -yOffsetF;
                dstYMax = clipBottom + -yOffsetF;
                dstLeftClip = clipLeft + -xOffsetF;
                dstXMax = clipRight + -xOffsetF;
                srcYAtDstMax = clipBottom;
                dstYMin = dstTopClip;
                if (dstYMax < dstTopClip) {
                  srcYAtDstMax = clipTop;
                  clipTop = clipBottom;
                  dstYMin = dstYMax;
                  dstYMax = dstTopClip;
                }
                srcXAtDstMax = clipRight;
                dstXMin = dstLeftClip;
                if (dstXMax < dstLeftClip) {
                  srcXAtDstMax = clipLeft;
                  clipLeft = clipRight;
                  dstXMin = dstXMax;
                  dstXMax = dstLeftClip;
                }
                invQuadWidth = FLOAT_0004c370;
                if (quadWidth != 0) {
                  quadWidthCvtHi = 0x43300000;
                  quadWidthCvtLo = quadWidth ^ 0x80000000;
                  invQuadWidth = scaleX / (float)((double)CONCAT44d(0x43300000,quadWidth ^ 0x80000000) -
                                           fpMagicBias);
                }
                invQuadHeight = FLOAT_0004c370;
                if (quadHeight != 0) {
                  quadHeightCvtHi = 0x43300000;
                  quadHeightCvtLo = quadHeight ^ 0x80000000;
                  invQuadHeight = scaleX / (float)((double)CONCAT44d(0x43300000,quadHeight ^ 0x80000000) -
                                           fpMagicBias);
                }
                tileXCvtLo = tileX ^ 0x80000000;
                tileXCvtHi = 0x43300000;
                tileCol = tileCol + 1;
                tileX = tileX + 0xc00;
                colWidthLeft = colWidthLeft - 0xc00;
                quadWidthFixedOp2d = (SInt32)((dstXMax - dstXMin) * subpixelScale);
                quadHeightFixedOp2d = (UInt32)(SInt32)((dstYMax - dstYMin) * subpixelScale);
                quadCursor[4] = 0x31080;
                quadCursor[6] = FBITS(invQuadHeight * (srcYAtDstMax - rowYF));
                quadCursor[8] = FBITS(invQuadHeight * (clipTop - rowYF));
                quadCursor[9] = 0x1087;
                tileXF = (float)((double)CONCAT44d(0x43300000,tileXCvtLo) - fpMagicBias);
                quadCursor[7] = FBITS(invQuadWidth * (srcXAtDstMax - tileXF));
                quadCursor[5] = FBITS(invQuadWidth * (clipLeft - tileXF));
                quadWidthFixSpill = (SInt64)quadWidthFixedOp2d;
                quadHeightFixSpill = (SInt64)(SInt32)quadHeightFixedOp2d;
                quadCursor[0xb] = 0xc0033500;
                quadCursor[0xc] = 0x10031;
                quadCursor[0xd] = FBITS((dstXMin + dstXMax) * scaleY);
                quadCursor[0xe] = FBITS((dstYMin + dstYMax) * scaleY);
                quadCursor[10] = quadWidthFixedOp2d << 0x10 | quadHeightFixedOp2d;
                quadCursor[0xf] = 0;
                quadCursor = quadCursor + 0x10;
                colsLeft = colsLeft - 1;
              } while (colsLeft != 0);
            }
            tileRow = tileRow + 1;
            rowOffsetY = rowOffsetY + 0xf80;
            rowHeightLeft = rowHeightLeft - 0xf80;
            quadY = quadY + 0xf80;
          } while (tileRows != tileRow);
        }
      }
      bufferFormatId = attachmentBuffer[0x3a];
      widthPerSampleOp40 = 0;
      noSampleBits = (M<UInt32>(attachmentBuffer + 0x3c) & 0xf00000) == 0;
      cr0Bits = noSampleBits << 1;
      if (!noSampleBits) {
        widthPerSampleOp40 = (SInt32)((UInt32)M<UInt16>(attachmentBuffer + 0x14) / (M<UInt32>(attachmentBuffer + 0x3c) >> 0x14 & 0xf)
                      ) >> (mipLevelOp2d & 0x3f);
      }
      pitchPixels = 0x20 / M<UInt16>(attachmentBuffer + 0x16);
      if (0x20 / M<UInt16>(attachmentBuffer + 0x16) <= widthPerSampleOp40) {
        pitchPixels = widthPerSampleOp40;
      }
      bufferPitch = M<UInt16>(attachmentBuffer + 0x20);
      bufferFlagsOp32 = attachmentBuffer[0x38];
      surfaceBaseAddressOp2d = M<SInt32>(attachmentBuffer + 8);
      levelOffset0Op37 = M<SInt32>(attachmentBuffer + mipLevelOp2d * 4 + 0x40);
      levelOffset1 = M<SInt32>(attachmentBuffer + mipLevelOp2d * 4 + 0x44);
      if (singleQuad) {
        tailCursor = recordCursor + 0xc9;
      }
      else {
        blockCount = 0;
        if (tileCount != 0) {
          blockCount = 0;
          blockCursor = tailCursor;
          do {
            if ((UInt8)bufferFlagsOp32 >> 1 == 0) {
              formatFieldDC = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)bufferFormatId * 0x1c);
              sizeShiftAdjustOp2d = 0;
            }
            else {
              formatFieldDC = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)bufferFormatId * 0x1c);
              sizeShiftAdjustOp2d = -(formatFieldDC >> 8 & 3);
            }
            texelShiftOp2d = formatFieldDC >> 0xc & 7;
            scaledOffsetOp2d = (SInt32)*blockCursor >> ((sizeShiftAdjustOp2d - texelShiftOp2d) + 5 & 0x3f);
            if (((UInt8)bufferFlagsOp32 & 1) == 0) {
              scaledOffsetOp2d = scaledOffsetOp2d << 5;
            }
            else {
              scaledOffsetOp2d = (scaledOffsetOp2d << 0xc) >> 3;
            }
            blockCount = blockCount + 1;
            *blockCursor = 0x1150;
            blockCursor[1] = levelOffset0Op37 * (UInt32)bufferPitch + surfaceIndexOp32 * (levelOffset1 - levelOffset0Op37) + surfaceBaseAddressOp2d +
                         scaledOffsetOp2d + (pitchPixels * blockCursor[1] << texelShiftOp2d) & 0xffffffe0 |
                         ((UInt8)bufferFlagsOp32 & 1) << 2 | ((UInt8)bufferFlagsOp32 >> 1 & 3) << 3;
            savedWord2Op2d = blockCursor[2];
            heightRegWordOp2d = recordCursor[0xa6];
            blockCursor[2] = 0x1120;
            blockCursor[3] = (blockCursor[3] - 1) * 0x800 & 0x3ff800 |
                         savedWord2Op2d - 1 & 0x7ff | heightRegWordOp2d & 0xffc00000;
            blockCursor = blockCursor + 0x10;
            tileCount = tileCount - 1;
          } while (tileCount != 0);
          blockCount = blockCount * 0x10;
        }
        tailCursor = tailCursor + blockCount;
      }
      if (tailCursor < recordPayloadEnd) {
        nopHeaderNop = 0x80000000;
        if (3 < ((SInt32)recordPayloadEnd - (SInt32)tailCursor) - 4U) {
          nopHeaderNop = (((SInt32)recordPayloadEnd - (SInt32)tailCursor >> 2) + -2) * 0x10000 | 0xc0001000;
        }
        *tailCursor = nopHeaderNop;
      }
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
    }
nextRecord:
    nextPendingWords = pendingWords + recordWords;
    recordCursor = (UInt32 *)((SInt32)recordCursor + recordBytes);
    if (recordWords == 0) {
      if ((nextPendingWords & 1) != 0) {
        *recordCursor = 0x80000000;
        nextPendingWords = pendingWords + 1;
        recordCursor = recordCursor + 1;
      }
      M<UInt32>(descriptorBytes) = (streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20;
      descriptorGartOffset = M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset);
      M<UInt32 *>(descriptorBytes + 0xc) = recordCursor;
      M<UInt32>(descriptorBytes + 8) = nextPendingWords;
      M<UInt32>(descriptorBytes + 4) = descriptorGartOffset + streamOffset + 0x20;
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
      return result;
    }
  } while( true );
}
