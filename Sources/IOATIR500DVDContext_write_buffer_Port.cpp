/*
 * IOATIR500DVDContext_write_buffer_Port.cpp
 *
 * IOATIR500DVDContext::write_buffer (real addr 0xffe0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");


/* real addr 0xffe0 */
IOReturn IOATIR500DVDContext::write_buffer(sIODVDContextWriteBufferData *data, UInt32 byteCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *dataBytes = reinterpret_cast<UInt8 *>(data);

  UInt8 *surface;
  int rectBottom;
  int srcPitch;
  int rectY;
  int rectX;
  UInt32 result;
  int bufferSlotOffset;
  int rectRight;
  int surfaceBuffer;
  int retryResult;
  unsigned int bufferIndex;
  unsigned int bufferBit;
  int rectWidth;
  int *surfaceWords;
  int *accelWords;
  int skipBytes;
  int rectHeight;
  int buffersLeft;
  int oldWaitCounter;
  unsigned int bufferHeight;
  unsigned int pageOffset;
  unsigned int bufferWidth;
  unsigned int sourceAddress;
  int bufferOffset;
  int waited;
  int sourceBase;
  int savedStamp;
  int sourceOffset;
  int bufferStamp;
  /* Ghidra split one 16-byte stack record (r1+0x58, the 3rd-from-last argument of the +0x5e8/+0x5ac calls) into five scalars; the callee
   * writes local_s.f44 through `&local_s`, so as separate scalars the `local_s.f44 != 0` branch (unlock / +0x55c / relock / +0x5ac) was
   * folded away as dead code (#86/#85: the stock-only IOLockLock/IOLockUnlock/indirect calls). Keep it one object. */
  struct { UInt32 f48; int f44; int *f40; UInt16 f3c; UInt16 f3a; } local_s;
  
  local_s.f3a = 0;
  local_s.f3c = 3;
  local_s.f48 = 0;
  local_s.f44 = 0;
  local_s.f40 = (int *)0x0;
  rectX = M<int>(dataBytes);
  rectY = M<int>(dataBytes + 4);
  rectWidth = M<int>(dataBytes + 8);
  rectHeight = M<int>(dataBytes + 0xc);
  sourceBase = M<int>(dataBytes + 0x14);
  bufferSlotOffset = (0x10 - (unsigned int)(M<int>(dataBytes + 0x10) == 0)) * 4;
  GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  surface = M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface);
  bufferBit = 0x40000000;
  surfaceBuffer = M<int>(surface + bufferSlotOffset + 0xb70);
  bufferIndex = (surfaceBuffer - (int)(surface + kIOATIR500Surface_buffers) >> 3) * -0x11111111;
  if (bufferIndex < 0x17) {
    bufferBit = 1 << (bufferIndex & 0x3f) & M<unsigned int>(self + kIOATIR500DVDContext_surfaceFlagsBitmask);
  }
  if ((surface == (UInt8 *)0x0) || (bufferBit == 0)) goto unlockAndFail;
  if ((bufferBit & M<unsigned int>(surface + kIOATIR500Surface_stateBits)) == 0) {
checkBufferUsable:
    if (((M<unsigned int>(surface + kIOATIR500Surface_stateBits) & 0x20000000) != 0) || (M<int>(surfaceBuffer + 0x10) == 0)) {
unlockAndFail:
      GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
      return 0xe00002cc;
    }
  }
  else {
    if (M<int>(surfaceBuffer + 0x24) == 0) goto unlockAndSucceed;
    if ((M<char>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x80) == '\0') ||
       (M<char>(M<int>(surfaceBuffer + 0x24) + 0x58) != '\0')) goto checkBufferUsable;
    retryResult = ((IOATIR500Surface *)(surface))->alloc_surfaces_retry(bufferBit, (eLockType)(0));
    if (retryResult != 0) goto unlockAndFail;
    surfaceBuffer = M<int>(bufferSlotOffset + M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xb70);
  }
  rectRight = rectX + rectWidth;
  if ((((0 < rectRight) && (rectBottom = rectY + rectHeight, 0 < rectBottom)) &&
      (bufferWidth = (unsigned int)M<UInt16>(surfaceBuffer + 0x1c), rectX < (int)bufferWidth)) &&
     (bufferHeight = (unsigned int)M<UInt16>(surfaceBuffer + 0x1e), rectY < (int)bufferHeight)) {
    srcPitch = M<int>(dataBytes + 0x18);
    sourceOffset = 0;
    if (rectX < 0) {
      sourceOffset = (unsigned int)M<UInt16>(surfaceBuffer + 0x16) * rectX;
      rectX = 0;
      sourceOffset = -sourceOffset;
      rectWidth = rectRight;
    }
    if (rectY < 0) {
      skipBytes = srcPitch * rectY;
      rectY = 0;
      sourceOffset = sourceOffset - skipBytes;
      rectHeight = rectBottom;
    }
    if ((int)bufferWidth < rectRight) {
      rectWidth = bufferWidth - rectX;
    }
    if ((int)bufferHeight < rectBottom) {
      rectHeight = bufferHeight - rectY;
    }
    sourceAddress = sourceBase + sourceOffset;
    pageOffset = sourceAddress & GH_page_size - 1U;
    local_s.f40 = (int *)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(sourceAddress & -GH_page_size,
                                   -GH_page_size &
                                   (GH_page_size +
                                   srcPitch * (rectHeight + -1) + (unsigned int)M<UInt16>(surfaceBuffer + 0x16) * rectWidth
                                   + pageOffset) - 1,0,M<UInt32>(self + kIOATIR500DVDContext_task));
    if (local_s.f40 == (int *)0x0) {
      result = 0xe00002be;
    }
    else {
      surfaceWords = M<int *>(self + kIOATIR500DVDContext_boundSurface);
      savedStamp = surfaceWords[0x1f];
      VCALL(*surfaceWords, 0x5ec)
                (surfaceWords,rectX,rectY,rectWidth,rectHeight,0,0,surfaceBuffer,
                 M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x50) + -1,&local_s,pageOffset,srcPitch,0);
      bufferOffset = 0xa0;
      buffersLeft = 0x17;
      do {
        bufferStamp = M<int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + bufferOffset + 0x2c);
        if ((bufferStamp != 0) && (savedStamp == M<int>(bufferStamp + 0x54))) {
          M<UInt32>(bufferStamp + 0x54) = M<UInt32>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0x7c);
        }
        bufferOffset = bufferOffset + 0x78;
        buffersLeft = buffersLeft + -1;
      } while (buffersLeft != 0);
      if (local_s.f44 != 0) {
        GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
        accelWords = M<int *>(self + kIOATIR500DVDContext_accelerator);
        oldWaitCounter = accelWords[0x1ec];
        waited = VCALL(*accelWords, 0x55c)
                          (accelWords,M<UInt32>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0x7c));
        accelWords[0x1ec] = oldWaitCounter + waited;
        GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
        VCALL(*M<int *>(self + kIOATIR500DVDContext_accelerator), 0x5ac)(M<int *>(self + kIOATIR500DVDContext_accelerator),&local_s);
      }
      result = 0;
      VCALL(*local_s.f40, 0x18)(local_s.f40);
    }
    local_s.f40 = (int *)0x0;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
    return result;
  }
unlockAndSucceed:
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  return 0;
}
