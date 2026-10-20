/*
 * ATIRadeonX1000_SWDS.cpp
 *
 * RESOLVED (ledger pass): the software display scaler: SWDSShutdown, SWDSFunc (timer), SWDSInit.
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
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x1d350 */
bool ATIRadeonX1000::SWDSShutdown() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool morePanels;
  UInt32 savedValue;
  SInt32 regOffset2;
  SInt32 registers;
  SInt32 regOffset1;
  SInt32 regOffset0;
  SInt32 panel;
  UInt8 *bufferCursor;
  UInt8 *recordCursor;
  UInt8 *stateCursor;
  
  if (M<SInt32 *>(self + kIOATIR500Accelerator_swdsTimer) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_swdsTimer), 0xf0)(M<SInt32 *>(self + kIOATIR500Accelerator_swdsTimer));
  }
  if (self[0x9b0] != 0x0) {
    panel = 0;
    self[0x9b0] = 0x0;
    bufferCursor = (self + kIOATIR500Accelerator_swdsBuffer0);
    recordCursor = self;
    stateCursor = self;
    do {
      if (M<SInt32>(stateCursor + 0xb10) != 0) {
        M<UInt32>(stateCursor + 0xb10) = 0;
        if (panel == 1) {
          regOffset0 = 0xb64;
          regOffset1 = 0xb68;
          regOffset2 = 0xb6c;
        }
        else {
          regOffset0 = 0xb74;
          regOffset1 = 0xb78;
          regOffset2 = 0xb7c;
        }
        registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
        savedValue = M<UInt32>(stateCursor + 0xafc);
        M<UInt32>(registers + regOffset0) =
             savedValue << 0x18 | (savedValue & 0xff00) << 8 | savedValue >> 8 & 0xff00 | savedValue >> 0x18;
        enforceInOrderExecutionIO();
        savedValue = M<UInt32>(stateCursor + 0xb00);
        M<UInt32>(registers + regOffset1) =
             savedValue << 0x18 | (savedValue & 0xff00) << 8 | savedValue >> 8 & 0xff00 | savedValue >> 0x18;
        enforceInOrderExecutionIO();
        savedValue = M<UInt32>(stateCursor + 0xb04);
        M<UInt32>(registers + regOffset2) =
             savedValue << 0x18 | (savedValue & 0xff00) << 8 | savedValue >> 8 & 0xff00 | savedValue >> 0x18;
        enforceInOrderExecutionIO();
        if ((M<SInt32>(recordCursor + 0x9c0) != 0) && (M<SInt32>(recordCursor + 0x9bc) != 0)) {
          ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->dealloc((GLKMemoryElement *)bufferCursor);
        }
      }
      morePanels = panel != 1;
      bufferCursor = bufferCursor + 0x78;
      stateCursor = stateCursor + 0x18;
      recordCursor = recordCursor + 0x78;
      panel = panel + 1;
    } while (morePanels);
  }
  return 1;
}

/* real addr 0x24340 */
void ATIRadeonX1000::SWDSFunc(OSObject *owner, IOTimerEventSource *source) {
    UInt8 *ownerBytes = reinterpret_cast<UInt8 *>(owner);

  UInt8 statusBits;
  bool dualPanel;
  UInt8 panelStatusMask;
  UInt32 stampBusy;
  SInt32 appendWordCount;
  UInt32 stamp;
  UInt32 bufferOffset;
  UInt8 *entry;
  UInt32 stampPending;
  UInt32 cmdWordCount;
  SInt32 nextPanel;
  UInt32 *cmdBuffer;
  UInt32 panel;
  UInt8 noBlitYet;
  UInt8 isPanel0Flag;
  SInt32 latestStamp;
  SInt32 entryRetired;
  SInt32 blitWordCount;
  
  GH_IOLockLock(M<UInt32>(ownerBytes + 0x840));
  if ((ownerBytes[0x80] != 0x0) && (ownerBytes[0x9b0] != 0x0)) {
    statusBits = (UInt8)loadWordByteReversed(&M<UInt8>(M<SInt32>(ownerBytes + 0x860) + 0xbf8));      /* one word read; only the masks 0x80/0x40 are tested */
    if ((M<SInt32>(ownerBytes + 0xb10) == 0) || (dualPanel = true, M<SInt32>(ownerBytes + 0xb28) == 0)) {
      dualPanel = false;
    }
    nextPanel = 0;
    entry = (UInt8 *)0x0;
    stampPending = 0;
    cmdBuffer = (UInt32 *)0x0;
    noBlitYet = 2;
    bufferOffset = 0;
    cmdWordCount = 0;
    panel = 0;
    do {
      if (M<SInt32>(ownerBytes + panel * 0x18 + 0xb10) != 0) {
        isPanel0Flag = (panel == 0) << 1;
        if (panel == 0) {
          panelStatusMask = 0x80;
        }
        else {
          panelStatusMask = 0x40;
        }
        if ((statusBits & panelStatusMask) == 0) {
          if (M<SInt32>(ownerBytes + panel * 4 + 0xacc) - M<SInt32>(ownerBytes + panel * 4 + 0xad4) < 1) {
            if (M<SInt32>(ownerBytes + 0x894) == 1) {
              latestStamp = M<SInt32>(ownerBytes + 0xec);
              if (latestStamp - M<SInt32>(ownerBytes + 0x10c) < 1) {
                M<SInt32>(ownerBytes + panel * 4 + 0xacc) = M<SInt32>(ownerBytes + 0x10c);
                goto LAB_00024480;
              }
            }
            else {
              latestStamp = M<SInt32>(ownerBytes + panel * 0x20 + 0xec);
            }
            M<SInt32>(ownerBytes + panel * 4 + 0xacc) = latestStamp;
          }
          else {
            /* #171: stock 0x2442c: r4 = lwz 0xacc(r9) = this[panel*4+0xacc], the stamp to check (checkForTimeStamp(unsigned long)); the port dropped it */
            stampBusy = VCALL(M<SInt32>(ownerBytes), 0x554)(ownerBytes,M<UInt32>(ownerBytes + panel * 4 + 0xacc));
            stampPending = stampPending | stampBusy;
          }
LAB_00024480:
          if (stampPending == 0) goto LAB_00024584;
        }
        else {
          stampPending = 1;
        }
        if ((bool)(noBlitYet >> 1 & 1)) {
          entry = ownerBytes + M<SInt32>(ownerBytes + 0xadc) * 0x1c + 0xae0;
          entryRetired = VCALL(M<SInt32>(ownerBytes), 0x554)(ownerBytes,M<UInt32>(entry + 0x10));
          if (entryRetired != 0) {
            cmdBuffer = (UInt32 *)(M<SInt32>(entry + 0x14) + 0x20);
            bufferOffset = M<SInt32>(entry + 4) + 0x20;
            blitWordCount = ((ATIRadeonX1000 *)ownerBytes)->SWDSWriteBlitToCmdBuf(cmdBuffer,0,false,panel);
            if ((bool)(isPanel0Flag >> 1 & 1)) {
              cmdBuffer[blitWordCount] = 0x2ff;
              cmdBuffer[blitWordCount + 1] = 0x80;
            }
            else {
              cmdBuffer[blitWordCount] = 0x2ff;
              cmdBuffer[blitWordCount + 1] = 0x40;
            }
            cmdWordCount = blitWordCount + 2;
            nextPanel = panel + 1;
            noBlitYet = (nextPanel == 0) << 1;
          }
        }
        else {
          appendWordCount = ((ATIRadeonX1000 *)ownerBytes)->SWDSWriteBlitToCmdBuf(cmdBuffer,cmdWordCount,false,panel);
          cmdBuffer[appendWordCount] = 0x2ff;
          cmdWordCount = appendWordCount + 2;
          cmdBuffer[appendWordCount + 1] = 0x40;
        }
      }
LAB_00024584:
      panel = panel + 1;
    } while (panel < 2);
    if (!(bool)(noBlitYet >> 1 & 1)) {
      if (dualPanel) {
        stamp = ((ATIRadeonX1000 *)ownerBytes)->submit_buffer(cmdBuffer,bufferOffset,cmdWordCount);
        M<UInt32>(entry + 0x10) = stamp;
        M<UInt32>(ownerBytes + 0xad4) = stamp;
        M<UInt32>(ownerBytes + 0xad8) = stamp;
      }
      else {
        stamp = ((ATIRadeonX1000 *)ownerBytes)->submit_buffer(cmdBuffer,bufferOffset,cmdWordCount);
        M<UInt32>(entry + 0x10) = stamp;
        M<UInt32>(ownerBytes + nextPanel * 4 + 0xad0) = stamp;
      }
    }
    VCALL(*M<SInt32 *>(ownerBytes + 0x9b8), 300)
              (M<SInt32 *>(ownerBytes + 0x9b8),M<UInt32>(ownerBytes + 0x9b4));
  }
  GH_IOLockUnlock(M<UInt32>(ownerBytes + 0x840));
  return;
}

/* real addr 0x24670 */
bool ATIRadeonX1000::SWDSInit() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool morePanels;
  UInt8 tilingMode;
  UInt16 bytesPerPixel16;
  UInt8 *regPtr;
  bool swdsStarted;
  bool panel1Placed;
  UInt32 usableVramAtEntry;
  SInt32 mmioBase;
  SInt32 regOffset1;
  UInt32 stamp;
  UInt32 recordBase;
  UInt32 tilingRegValue;
  SInt32 regOffset2;
  UInt32 endAddress;
  UInt32 placementLimit;
  UInt32 bufferBase;
  UInt32 usableVram;
  UInt32 paddedWidth;
  SInt32 recordOffset;
  UInt8 *elementB;
  UInt8 *savedRegCursor;
  UInt32 panel;
  UInt8 *element;
  UInt8 *stateCursor;
  UInt32 bufferSize;
  SInt32 regOffset0;
  UInt32 *cmdWords;
  UInt8 *recordCursor;
  UInt32 swdsWidth;
  UInt32 tileBits;
  UInt32 secondaryWord;
  UInt32 buffer0Base;
  UInt32 newRecordBase;
  UInt32 swdsHeight;
  UInt32 baseWord;
  UInt32 tilingBits;
  UInt32 pitch;
  UInt32 bytesPerPixel32;
  UInt32 alignedHeight;
  SInt32 unalignedBase;
  SInt32 reserveResult;
  SInt32 entryOffset;
  SInt32 otherBufferBase;
  SInt32 entryRetired;
  SInt32 cmdBufferAddr;
  SInt32 blitWordCount;
  SInt32 reserveBelow;
  SInt32 cmdBufferOffset;
  SInt32 otherBufferSize;
  
  if (self[0x80] != 0x0) {
    usableVramAtEntry = M<UInt32>(self + kIOATIR500Accelerator_usableVramSize);
    panel1Placed = false;
    swdsStarted = false;
    paddedWidth = 0;
    panel = 1;
    elementB = (self + kIOATIR500Accelerator_swdsScratchElement);
    element = (self + kIOATIR500Accelerator_swdsBuffer1);
    recordOffset = 0x78;
    savedRegCursor = self;
    stateCursor = self;
    recordCursor = self;
    do {
      if (M<SInt32>(stateCursor + 0xb30) != 0) {
        swdsWidth = M<UInt32>(stateCursor + 0xb38);
        swdsHeight = M<UInt32>(stateCursor + 0xb40);
        if (((swdsWidth != M<UInt16>(recordCursor + 0x1c0)) || (swdsHeight != M<UInt16>(recordCursor + 0x1c2)))
           || (M<SInt32>(stateCursor + 0xb60) != 0)) {
          bytesPerPixel16 = M<UInt16>(recordCursor + 0x1ba);
          bytesPerPixel32 = (UInt32)bytesPerPixel16;
          pitch = swdsWidth * bytesPerPixel32 + 0xff & 0xffffff00;
          if (bytesPerPixel32 != 0) {
            paddedWidth = pitch / bytesPerPixel32;
          }
          alignedHeight = swdsHeight;
          if ((swdsHeight & 0xf) != 0) {
            alignedHeight = (swdsHeight & 0xfffffff0) + 0x10;
          }
          usableVram = M<UInt32>(self + kIOATIR500Accelerator_usableVramSize);
          placementLimit = M<UInt32>(self + kIOATIR500Accelerator_vramSize);
          bufferSize = alignedHeight * pitch;
          if (usableVram < placementLimit) {
            if ((panel == 1) ||
               ((((M<SInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) == 1 && (M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb2c) != 0)) &&
                 (M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb30) != 0)) &&
                ((M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb34) == M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb38) ||
                 (M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb3c) == M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb40))))))) {
              unalignedBase = placementLimit - bufferSize;
              panel1Placed = panel == 1;
            }
            else {
              if (panel1Placed) {
                placementLimit = M<UInt32>(self + kIOATIR500Accelerator_swdsBuffer1GpuBaseAddress);
              }
              unalignedBase = placementLimit - bufferSize;
            }
            bufferBase = unalignedBase - 0x8000U & 0xffff8000;
            if (usableVram <= bufferBase) {
LAB_00024750:
              M<UInt16>(recordCursor + 0xa48) = 0;
              M<UInt16>(recordCursor + 0xa4a) = 0;
              M<UInt16>(recordCursor + 0xa4c) = 0;
              M<UInt16>(recordCursor + 0xa50) = 0;
              recordCursor[0xa6f] = 0x6;
              M<UInt16>(recordCursor + 0xa56) = 1;
              M<UInt16>(recordCursor + 0xa54) = 1;
              M<UInt16>(recordCursor + 0xa52) = 0;
              recordCursor[0xa68] = 0x0;
              recordCursor[0xa69] = 0x0;
              recordCursor[0xa6a] = 0x0;
              recordCursor[0xa6c] = 0x0;
              recordCursor[0xa6d] = 0x0;
              recordCursor[0xa70] = 0x0;
              M<UInt32>(recordCursor + 0xa3c) = 0;
              M<UInt32>(recordCursor + 0xa44) = 0;
              M<UInt32>(recordCursor + 0xa34) = 0;
              M<UInt32>(recordCursor + 0xa38) = 0;
              M<UInt32>(recordCursor + 0xa40) = 0;
              M<UInt32>(recordCursor + 0xa58) = 0;
              M<UInt32>(recordCursor + 0xa60) = 0;
              M<UInt32>(recordCursor + 0xa64) = 0;
              recordCursor[0xa6b] = 0xff;
              M<UInt32>(recordCursor + 0xa5c) = 0xffffffff;
              M<UInt32>(element + 0x3c) = M<UInt32>(element + 0x3c) & 0xff0007ff | 0x111000;
              M<UInt16>(recordCursor + 0xa4a) = bytesPerPixel16;
              M<SInt16>(recordCursor + 0xa4c) = (SInt16)pitch;
              M<UInt32>(recordCursor + 0xa74) = 0;
              M<UInt32>(recordCursor + 0xa78) = 0;
              M<UInt32>(recordCursor + 0xa3c) = bufferBase;
              M<UInt32>(recordCursor + 0xa44) = bufferSize;
              M<SInt16>(recordCursor + 0xa48) = (SInt16)paddedWidth;
              M<SInt16>(recordCursor + 0xa50) = (SInt16)swdsWidth;
              M<SInt16>(recordCursor + 0xa52) = (SInt16)swdsHeight;
              recordCursor[0xa6b] = recordCursor[0x1db];
              recordCursor[0xa6c] = recordCursor[0x1dc];
              recordCursor[0xa6d] = recordCursor[0x1dd];
              recordCursor[0xa6e] = recordCursor[0x1de];
              recordCursor[0xa6f] = recordCursor[0x1df];
              tileBits = M<UInt32>(element + -0x854);
              M<UInt32>(element + 0x3c) =
                   tileBits & 0x800 |
                   tileBits & 0xf000 |
                   tileBits & 0xf0000 | tileBits & 0xf00000 | M<UInt32>(element + 0x3c) & 0xff0007ff;
              reserveResult = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->reserve((GLKMemoryElement *)element, bufferBase, bufferSize)
              ;
              if (reserveResult != 0) {
                reserveResult = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)elementB,bufferBase,bufferSize);
                if (reserveResult == 0) {
                  ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->dealloc((GLKMemoryElement *)element);
                }
                else {
                  entryOffset = M<SInt32>(self + kIOATIR500Accelerator_swdsEntryIndex) * 0x1c;
                  entryRetired = VCALL(M<SInt32>(self), 0x554)
                                    (self,M<UInt32>(self + entryOffset + 0xaf0));
                  if (entryRetired != 0) {
                    cmdBufferAddr = M<SInt32>(self + entryOffset + 0xaf4);
                    cmdBufferOffset = M<SInt32>(self + entryOffset + 0xae4);
                    cmdWords = (UInt32 *)(cmdBufferAddr + 0x20);
                    *cmdWords = 0xd0b;
                    M<UInt32>(cmdBufferAddr + 0x24) = 5;
                    M<UInt32>(cmdBufferAddr + 0x28) = 0x1393;
                    M<UInt32>(cmdBufferAddr + 0x2c) = 10;
                    M<UInt32>(cmdBufferAddr + 0x30) = 0x5c8;
                    M<UInt32>(cmdBufferAddr + 0x34) = 0x30000;
                    blitWordCount = this->SWDSWriteBlitToCmdBuf(cmdWords,6,false,panel);
                    cmdWords[blitWordCount] = 0x2ff;
                    cmdWords[blitWordCount + 1] = 0xc0;
                    cmdWords[blitWordCount + 2] = 0x5c8;
                    cmdWords[blitWordCount + 3] = 0x30000;
                    stamp = this->submit_buffer(cmdWords,cmdBufferOffset + 0x20,blitWordCount + 4);
                    M<UInt32>(self + entryOffset + 0xaf0) = stamp;
                    M<UInt32>(stateCursor + 0xad8) = stamp;
                    VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(self + entryOffset + 0xaf0));
                  }
                  if (((M<SInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) == 1) && (M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb2c) != 0)) &&
                     ((M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb30) != 0 &&
                      ((M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb34) == M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb38) &&
                       (M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb3c) == M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb40))))))) {
                    mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
                    baseWord = M<UInt32>(recordCursor + 0xa3c);
                    M<UInt32>(mmioBase + 0x6110) =
                         baseWord << 0x18 | (baseWord & 0xff00) << 8 | baseWord >> 8 & 0xff00 |
                         baseWord >> 0x18;
                    enforceInOrderExecutionIO();
                    secondaryWord = (UInt32)M<UInt16>(recordCursor + 0xa48);
                    M<UInt32>(mmioBase + 0x6120) = secondaryWord << 0x18 | (secondaryWord & 0xff00) << 8;
                    enforceInOrderExecutionIO();
                    M<UInt32>(mmioBase + 0x6910) =
                         baseWord << 0x18 | (baseWord & 0xff00) << 8 | baseWord >> 8 & 0xff00 |
                         baseWord >> 0x18;
                    enforceInOrderExecutionIO();
                    M<UInt32>(mmioBase + 0x6920) = secondaryWord << 0x18 | (secondaryWord & 0xff00) << 8;
                    enforceInOrderExecutionIO();
                    M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddressSeen) = baseWord;
                    M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressSeen) = M<UInt32>(recordCursor + 0xa3c);
                  }
                  else {
                    if (panel == 0) {
                      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
                      buffer0Base = M<UInt32>(self + kIOATIR500Accelerator_swdsBuffer0GpuBaseAddress);
                      M<UInt32>(mmioBase + 0x6110) =
                           buffer0Base << 0x18 | (buffer0Base & 0xff00) << 8 | buffer0Base >> 8 & 0xff00 |
                           buffer0Base >> 0x18;
                      enforceInOrderExecutionIO();
                      M<UInt32>(mmioBase + 0x6120) =
                           (UInt32)M<UInt16>(self + kIOATIR500Accelerator_swdsBuffer0Width) << 0x18 |
                           (M<UInt16>(self + kIOATIR500Accelerator_swdsBuffer0Width) & 0xff00) << 8;
                      enforceInOrderExecutionIO();
                      newRecordBase = M<UInt32>(recordCursor + 0xa3c);
                    }
                    else {
                      newRecordBase = M<UInt32>(recordCursor + 0xa3c);
                      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
                      M<UInt32>(mmioBase + 0x6910) =
                           newRecordBase << 0x18 | (newRecordBase & 0xff00) << 8 | newRecordBase >> 8 & 0xff00 |
                           newRecordBase >> 0x18;
                      enforceInOrderExecutionIO();
                      M<UInt32>(mmioBase + 0x6920) =
                           (UInt32)M<UInt16>(recordCursor + 0xa48) << 0x18 |
                           (M<UInt16>(recordCursor + 0xa48) & 0xff00) << 8;
                      enforceInOrderExecutionIO();
                    }
                    M<UInt32>(stateCursor + 0xb70) = newRecordBase;
                  }
                  tilingRegValue = 0;
                  tilingMode = self[recordOffset + 0x164];
                  recordBase = M<UInt32>(self + recordOffset + 0x134);
                  tilingBits = 0;
                  if (tilingMode != 0x0) {
                    tilingRegValue = (UInt32)(M<UInt16>(self + recordOffset + 0x144) >> 3);
                    if (tilingMode == 0x2) {
                      tilingBits = 0x20000;
                    }
                    else if (tilingMode == 0x3) {
                      tilingBits = 0x30000;
                    }
                    else if (tilingMode == 0x1) {
                      tilingBits = 0x10000;
                    }
                    else {
                      tilingBits = 0;
                    }
                  }
                  if (panel == 1) {
                    regOffset0 = 0xb64;
                    regOffset1 = 0xb68;
                    regOffset2 = 0xb6c;
                    tilingRegValue = tilingRegValue | tilingBits | ((UInt8)self[recordOffset + 0x165] & 3) << 0x14 |
                             ((UInt8)self[recordOffset + 0x165] & 3) << 0x16;
                  }
                  else {
                    regOffset0 = 0xb74;
                    regOffset1 = 0xb78;
                    regOffset2 = 0xb7c;
                    tilingRegValue = tilingRegValue | tilingBits | ((UInt8)self[recordOffset + 0x165] & 3) << 0x14 |
                             ((UInt8)self[recordOffset + 0x165] & 3) << 0x16;
                  }
                  regPtr = (UInt8 *)(mmioBase + regOffset0);
                  M<UInt32>(savedRegCursor + 0xb14) =
                       loadWordByteReversed(regPtr);
                  regPtr = (UInt8 *)(M<SInt32>(self + kIOATIR500Accelerator_mmioBase) + regOffset1);
                  M<UInt32>(savedRegCursor + 0xb18) =
                       loadWordByteReversed(regPtr);
                  regPtr = (UInt8 *)(M<SInt32>(self + kIOATIR500Accelerator_mmioBase) + regOffset2);
                  M<UInt32>(savedRegCursor + 0xb1c) =
                       loadWordByteReversed(regPtr);
                  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
                  M<UInt32>(mmioBase + regOffset0) =
                       recordBase << 0x18 | (recordBase & 0xff00) << 8 | recordBase >> 8 & 0xff00 |
                       recordBase >> 0x18;
                  enforceInOrderExecutionIO();
                  endAddress = (recordBase + M<SInt32>(self + recordOffset + 0x13c)) - 1;
                  M<UInt32>(mmioBase + regOffset1) =
                       endAddress * 0x1000000 | (endAddress & 0xff00) << 8 | endAddress >> 8 & 0xff00 |
                       endAddress >> 0x18;
                  enforceInOrderExecutionIO();
                  M<UInt32>(mmioBase + regOffset2) =
                       tilingRegValue << 0x18 | (tilingRegValue & 0xff00) << 8 | tilingRegValue >> 8 & 0xff00;
                  enforceInOrderExecutionIO();
                  swdsStarted = true;
                  M<UInt32>(savedRegCursor + 0xb28) = 1;
                }
              }
            }
          }
          else if (((M<SInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) == 1) && (M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb2c) != 0)) &&
                  ((M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb30) != 0 &&
                   ((M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb34) != M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb38) ||
                    (M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb3c) != M<SInt32>(self + kIOATIR500Accelerator_swdsState_0xb40))))))) {
            if (panel == 1) {
              reserveBelow = M<SInt32>(self + kIOATIR500Accelerator_gartReserveSize);
              otherBufferBase = M<SInt32>(self + kIOATIR500Accelerator_scanout2BufferGpuBaseAddress);
              otherBufferSize = M<SInt32>(self + kIOATIR500Accelerator_scanout2BufferSize);
LAB_00024a0c:
              bufferBase = ((usableVram - reserveBelow) - bufferSize) - 0x8000 & 0xffff8000;
              if ((UInt32)(otherBufferBase + otherBufferSize) < bufferBase) goto LAB_00024750;
            }
            else {
              bufferBase = (M<SInt32>(self + kIOATIR500Accelerator_swdsBuffer1GpuBaseAddress) - bufferSize) - 0x8000 & 0xffff8000;
              if ((UInt32)(M<SInt32>(recordCursor + 0x1ac) + M<SInt32>(recordCursor + 0x1b4)) < bufferBase)
              goto LAB_00024750;
            }
          }
          else {
            if ((panel != 0) || ((M<SInt32>(self + kIOATIR500Accelerator_scanout2BufferSize) == 0 || (M<SInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) != 0)))) {
              reserveBelow = M<SInt32>(self + kIOATIR500Accelerator_gartReserveSize);
              otherBufferBase = M<SInt32>(recordCursor + 0x1ac);
              otherBufferSize = M<SInt32>(recordCursor + 0x1b4);
              goto LAB_00024a0c;
            }
            bufferBase = M<SInt32>(self + kIOATIR500Accelerator_scanout1BufferGpuBaseAddress) + M<SInt32>(self + kIOATIR500Accelerator_scanout1BufferSize) + 0x8000U & 0xffff8000;
            if (bufferSize + bufferBase < (M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferGpuBaseAddress) & ~((usableVramAtEntry >> 1) - 1)))
            goto LAB_00024750;
          }
        }
      }
      morePanels = panel != 0;
      recordOffset = recordOffset + -0x78;
      element = element + -0x78;
      elementB = elementB + -0x10;
      stateCursor = stateCursor + -4;
      savedRegCursor = savedRegCursor + -0x18;
      recordCursor = recordCursor + -0x78;
      panel = panel - 1;
    } while (morePanels);
    if (swdsStarted) {
      VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_swdsTimer), 300)
                (M<SInt32 *>(self + kIOATIR500Accelerator_swdsTimer),M<UInt32>(self + kIOATIR500Accelerator_swdsPeriodMs));
      VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_swdsTimer), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_swdsTimer));
      self[0x9b0] = 0x1;
      return 1;
    }
  }
  return 0;
}

