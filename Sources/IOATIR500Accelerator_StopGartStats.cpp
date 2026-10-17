/*
 * IOATIR500Accelerator_StopGartStats.cpp
 *
 * RESOLVED (ledger pass): IOATIR500Accelerator::stop (0x65c0, vtable +0x34c), addToMinMaxGART (0x5fe0, +0x590) and
 * writePerformanceStats (0xac0, +0x568), transcribed mechanically from the shipped kext's decompile (Tools/port_fn.py,
 * Headers/GhidraCompat.h; conventions as in ATIR500Surface_BuildSwap.cpp). The `_ASICSupportsAGP` labels in
 * addToMinMaxGART are page_shift / page_size loads (relocation table). `stop` ends by chaining to IOAccelerator::stop.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/GhidraExterns.h"

#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

static inline void GH_FreeTexvert(void *accelerator, void *texture) { IOATIR500Shared::free_texvert(reinterpret_cast<IOATIR500Accelerator *>(accelerator), reinterpret_cast<IOTextureBuffer *>(texture)); }

extern "C" UInt32 GH_IOLockFree(...) asm("_IOLockFree");
extern "C" UInt32 GH_ZN8OSNumber10withNumberEyj(...) asm("__ZN8OSNumber10withNumberEyj");

/* real addr 0x65c0 */
void IOATIR500Accelerator::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool notLastRecord;
  
  SInt32 nextNode;
  SInt32 *commandBufferMemory;
  SInt32 prevNode;
  UInt8 *texvert;
  UInt32 panelIndex;
  UInt32 recordIndex;
  UInt8 *panelRecordCursor;
  
  VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + 0x50) + -1);
  if (M<SInt32>(self + 0xbc) != 0) {
    /* #155 FIX: IOWorkLoop::removeEventSource() at vtable+0xe8 takes (this, toRemove) - see the
     * matching comment in ATIRadeonX1000_stop_Port.cpp for the full ground-truth derivation. */
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4), M<SInt32 *>(self + 0xbc));
    VCALL(*M<SInt32 *>(self + 0xbc), 0x18)(M<SInt32 *>(self + 0xbc));
    M<UInt32>(self + 0xbc) = 0;
  }
  if (M<SInt32>(self + 0xb8) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4), M<SInt32 *>(self + 0xb8));
    VCALL(*M<SInt32 *>(self + 0xb8), 0x18)(M<SInt32 *>(self + 0xb8));
    M<UInt32>(self + 0xb8) = 0;
  }
  texvert = M<UInt8 *>(self + 0x664);
  while (texvert != (UInt8 *)(self + 0x63c)) {
    prevNode = M<SInt32>(texvert + 0x24);
    M<UInt32>(prevNode + 0x28) = M<UInt32>(texvert + 0x28);
    nextNode = M<SInt32>(texvert + 0x28);
    M<UInt8 *>(texvert + 0x28) = texvert;
    M<SInt32>(nextNode + 0x24) = prevNode;
    M<UInt8 *>(texvert + 0x24) = texvert;
    GH_FreeTexvert(self,texvert);
    texvert = M<UInt8 *>(self + 0x664);
  }
  self[0x89] = 0x0;
  if (M<SInt32>(self + 0xc4) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4), M<SInt32 *>(self + 0xc4));
    VCALL(*M<SInt32 *>(self + 0xc4), 0x18)(M<SInt32 *>(self + 0xc4));
    M<UInt32>(self + 0xc4) = 0;
  }
  if (M<SInt32>(self + 0xc0) != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe8)(M<SInt32 *>(self + 0xb4), M<SInt32 *>(self + 0xc0));
    VCALL(*M<SInt32 *>(self + 0xc0), 0x18)(M<SInt32 *>(self + 0xc0));
    M<UInt32>(self + 0xc0) = 0;
  }
  if (M<SInt32 *>(self + 0xb4) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0x18)(M<SInt32 *>(self + 0xb4));
    M<UInt32>(self + 0xb4) = 0;
  }
  recordIndex = 0;
  do {
    ((IOATIR500Accelerator *)(self))->freeAllCommandBuffers(recordIndex);
    notLastRecord = recordIndex != 1;
    recordIndex = recordIndex + 1;
  } while (notLastRecord);
  ((IOATIR500Accelerator *)(self))->freeAllDataBuffers();
  if ((M<UInt32>(self + 0x98) & 1) != 0) {
    commandBufferMemory = M<SInt32 *>(self + 0x22c);
    if (commandBufferMemory == (SInt32 *)0x0) goto LAB_000067e8;
    VCALL(*commandBufferMemory, 0x148)(commandBufferMemory,3);
  }
  if (M<SInt32>(self + 0x22c) != 0) {
    ((IOATIR500Accelerator *)(self))->freeCommandBuffer((VendorCommandBuffer *)(self + 0x224));
  }
LAB_000067e8:
  if (M<SInt32>(self + 0xcc) != 0) {
    panelIndex = 0;
    panelRecordCursor = self;
    do {
      if (M<SInt32 *>(panelRecordCursor + 0xd8) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(panelRecordCursor + 0xd8), 0xd0)(M<SInt32 *>(panelRecordCursor + 0xd8));
      }
      if (M<SInt32 *>(panelRecordCursor + 0xe0) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(panelRecordCursor + 0xe0), 0x18)(M<SInt32 *>(panelRecordCursor + 0xe0));
      }
      if (M<SInt32 *>(panelRecordCursor + 0xdc) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(panelRecordCursor + 0xdc), 0x18)(M<SInt32 *>(panelRecordCursor + 0xdc));
      }
      panelIndex = panelIndex + 1;
      panelRecordCursor = panelRecordCursor + 0x20;
    } while (panelIndex < M<UInt32>(self + 0xcc));
  }
  if (M<SInt32 *>(self + 0x7c) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x7c), 0x18)(M<SInt32 *>(self + 0x7c));
    M<UInt32>(self + 0x7c) = 0;
  }
  VCALL(M<SInt32>(self), 0x584)(self,provider);
  if (M<SInt32>(self + 0x840) != 0) {
    /* #155 FIX (2026-10-10): _IOLockFree(lock_t) takes the lock pointer as its one argument -
     * confirmed via stock's own disassembly (0x68b8: `lwz r3,0x840(r30)` loads self+0x840 into r3
     * immediately before the `bl` to IOLockFree). GH_IOLockFree is a bare variadic declaration, so
     * this call site compiled with zero explicit arguments - the real kernel function received
     * whatever garbage happened to be in r3. Same dropped-argument defect class as the
     * removeEventSource() fix earlier in this issue; a real bug regardless of whether it's also
     * the cause of this issue's remaining teardown hang (live-tested: fixing this alone did not
     * resolve the hang - see the issue comments for the checkpoint-panic localization that followed). */
    GH_IOLockFree(M<SInt32>(self + 0x840));
    M<UInt32>(self + 0x840) = 0;
  }
  
  M<UInt32>(self + 0x74) = 0;
  IOAccelerator::stop(provider);
  return;
}

/* real addr 0x5fe0 */
IOReturn IOATIR500Accelerator::addToMinMaxGART(IOMemoryDescriptor *memory, UInt32 *outOffset, UInt32 minOffset, UInt32 maxOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *memoryBytes = reinterpret_cast<UInt8 *>(memory);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 pageCount;
  UInt32 result;
  UInt32 physAddress;
  SInt32 iVar6;
  UInt32 firstEntry;
  UInt32 freeRun;
  UInt32 segmentLength [9];
  
  *outOffset = 0;
  pageCount = VCALL(M<SInt32>(memoryBytes), 0x128)(memoryBytes);
  pageCount = pageCount >> (GH_page_shift & 0x3f);
  firstEntry = minOffset >> (GH_page_shift & 0x3f);
  uVar1 = (M<UInt32>(self + 0x830) >> 2) << (GH_page_shift & 0x3f);
  if (uVar1 <= maxOffset) {
    maxOffset = uVar1 - GH_page_size;
  }
  uVar1 = maxOffset >> (GH_page_shift & 0x3f);
  iVar6 = firstEntry << 2;
  freeRun = 0;
  iVar2 = (uVar1 - firstEntry) + 1;
  if ((uVar1 < firstEntry) || (uVar1 == 0)) {
    iVar2 = 1;
  }
  do {
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      if (pageCount != freeRun) {
        return 0;
      }
      goto LAB_000060d8;
    }
    if ((M<SInt32>(iVar6 + M<SInt32>(self + 0x83c)) == M<SInt32>(self + 0x844)) &&
       ((freeRun != 0 || ((firstEntry & 1) == 0)))) {
      freeRun = freeRun + 1;
    }
    else {
      freeRun = 0;
    }
    firstEntry = firstEntry + 1;
    iVar6 = iVar6 + 4;
  } while (freeRun != pageCount);
  firstEntry = firstEntry - pageCount;
LAB_000060d8:
  iVar6 = VCALL(M<SInt32>(memoryBytes), 0x144)(memoryBytes,3);
  if (iVar6 == 0) {
    if (((M<UInt32>(self + 0x98) & 2) == 0) ||
       (iVar6 = VCALL(M<SInt32>(self), 0x588)
                          (self,memoryBytes,firstEntry << (GH_page_shift & 0x3f),0), iVar6 == 0)) {
      iVar6 = 0;
      *outOffset = firstEntry << (GH_page_shift & 0x3f);
      while (physAddress = VCALL(M<SInt32>(memoryBytes), 0x13c)(memoryBytes,iVar6,segmentLength),
            uVar1 = GH_page_size, physAddress != 0) {
        iVar6 = iVar6 + segmentLength[0];
        if (GH_page_size <= segmentLength[0]) {
          iVar2 = M<SInt32>(self + 0x83c);
          do {
            M<UInt32>(iVar2 + firstEntry * 4) =
                 physAddress << 0x18 | (physAddress & 0xff00) << 8 | physAddress >> 8 & 0xff00 | physAddress >> 0x18;
            segmentLength[0] = segmentLength[0] - uVar1;
            physAddress = physAddress + uVar1;
            firstEntry = firstEntry + 1;
          } while (uVar1 <= segmentLength[0]);
        }
      }
      VCALL(M<SInt32>(self), 0x59c)(self,firstEntry - freeRun,pageCount);
      result = 1;
      M<UInt32>(self + 0x714) = (pageCount << (GH_page_shift & 0x3f)) + M<SInt32>(self + 0x714);
      M<UInt32>(self + 0xa0) = (pageCount << (GH_page_shift & 0x3f)) + M<SInt32>(self + 0xa0);
    }
    else {
      VCALL(M<SInt32>(memoryBytes), 0x148)(memoryBytes,3);
      result = 0;
    }
  }
  else {
    result = 1;
  }
  return result;
}

/* real addr 0xac0 */
void IOATIR500Accelerator::writePerformanceStats(OSDictionary *dictionary) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *dictionaryBytes = reinterpret_cast<UInt8 *>(dictionary);

  SInt32 *number;
  
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x6fc),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"commandBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x6fc) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x700),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"command2DBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x700) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x704),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"commandGLBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x704) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x708),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"commandDVDBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x708) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x70c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"dataGLBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x70c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x710),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"swapBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x710) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x714),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"gartMapInBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x714) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x718),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"gartMapOutBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x718) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x71c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"texturePageInBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x71c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x720),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"texturePageOutBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x720) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x724),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfacePageInBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x724) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x728),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfacePageOutBytesPerSample",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x728) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x72c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"textureCount",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x730),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfaceCount",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x734),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"context2DCount",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x738),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"contextGLCount",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x73c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"contextDVDCount",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x740),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"contextGLSwitchCount",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x740) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x744),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"context2DSwitchCount",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x744) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x748),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"contextDVDSwitchCount",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x748) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x74c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"bufferSwapCount",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x74c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x750),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"dataBufferCount",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x750) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x754),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"texturePageInWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x754) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x758),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"texturePageOutWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x758) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x75c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"textureWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x75c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x760),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"hardwareWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x760) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x764),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"hardwareSubmitWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x764) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x768),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"clientGLWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x768) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x76c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeCommandBuffer2DWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x76c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x770),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeCommandBufferGLWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x770) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x774),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeCommandBufferDVDWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x774) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x778),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeDataBufferGLWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x778) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x77c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeContextBuffer2DWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x77c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x780),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeContextBufferGLWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x780) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x784),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeContextBufferDVDWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x784) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x788),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeSurfaceSwapBufferWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x788) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x78c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"freeSurfaceBackingWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x78c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x790),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"removeFromGARTWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x790) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x794),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"swapComplete2DWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x794) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x798),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"swapCompleteGLWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x798) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x79c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"swapCompleteDVDWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x79c) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7a0),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"finishAll2DWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7a0) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7a4),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"finish2DWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7a4) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7a8),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"finishGLWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7a8) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7ac),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"finishDVDWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7ac) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7b0),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfaceCopyInWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7b0) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7b4),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfaceCopyOutWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7b4) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7b8),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfaceReadLockIdleWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7b8) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7bc),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfaceWriteLockIdleWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7bc) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x7c0),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"surfaceSetShapeIdleWaitTime",number);
    VCALL(*number, 0x18)(number);
  }
  M<UInt32>(self + 0x7c0) = 0;
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x21c),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"volatileSurfaceCount",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0xa0),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"gartUsedBytes",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<SInt32>(self + 0x830) * 0x400 - M<SInt32>(self + 0xa0),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"gartFreeBytes",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<SInt32>(self + 0x830) << 10,0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"gartSizeBytes",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0xa4),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"gartCacheBytes",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x50),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"submitStamp",number);
    VCALL(*number, 0x18)(number);
  }
  number = (SInt32 *)GH_ZN8OSNumber10withNumberEyj(0,M<UInt32>(self + 0x54),0x20);
  if (number != (SInt32 *)0x0) {
    VCALL(M<SInt32>(dictionaryBytes), 300)(dictionaryBytes,"lastReadStamp",number);
    VCALL(*number, 0x18)(number);
  }
  return;
}
