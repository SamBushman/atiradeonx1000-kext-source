/*
 * IOATIR500Surface_set_shape_backing_length_ext_Port.cpp
 *
 * IOATIR500Surface::set_shape_backing_length_ext (real addr 0x152d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* real addr 0x152d0 */
IOReturn IOATIR500Surface::set_shape_backing_length_ext(eIOAccelSurfaceShapeBits shapeBits, UInt32 id, unsigned int backingAddress, UInt32 backingPitch, IOAccelDeviceRegion *region, UInt32 regionSize, UInt32 backingLength) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    int *regionRaw = reinterpret_cast<int *>(region);

  int *rectWordBPtr;
  char hardwareUp;
  UInt16 regionWidth;
  UInt16 regionHeight;
  int rectIndex;
  bool reshape;
  UInt32 result;
  UInt8 *surfaceBuffer;
  UInt8 noBacking;
  UInt8 keepBacking;
  UInt8 notReshaped;
  UInt32 vramElement[4];   /* ONE real 16-byte GLKMemoryElement: the decompile showed four separate locals and stock passes vramElement (stock's compiler placed them adjacently) */
  UInt8 panelActive;
  UInt8 scalingFlag;
  int acceleratorBytes;
  int regionBounds;
  int rectsLeft;
  int rectRecord;
  int rectWordA;
  int accelerator;
  int idOffset;
  int shapeOk;
  int vramAllocOk;
  int connectOk;
  int stampValue;
  int waitTime;
  int newRegion;
  int regionWord1;
  int rectCount;
  int waitBefore;
  int *regionRecord;
  int *rectCursor;
  int *acceleratorObject;
  
  accelerator = M<int>(self + kIOATIR500Surface_accelerator);
  if (((M<unsigned int>(accelerator + kIOATIR500Accelerator_displayCount) <= id) || (M<SInt16>(regionRaw + 2) < 0)) ||
     (M<SInt16>((int)regionRaw + 10) < 0)) {
    return 0xe00002bc;
  }
  if (regionSize == 0) {
    regionSize = *regionRaw * 8 + 0xc;
  }
  else if (regionSize != *regionRaw * 8 + 0xcU) {
    return 0xe00002bc;
  }
  if ((M<SInt16>(regionRaw + 2) == 0) || (M<SInt16>((int)regionRaw + 10) == 0)) {
    backingAddress = 0;
    backingPitch = 0;
    M<UInt16>((int)regionRaw + 10) = 1;
    M<UInt16>(regionRaw + 2) = 1;
    accelerator = M<int>(self + kIOATIR500Surface_accelerator);
  }
  GH_IOLockLock(M<UInt32>(accelerator + kIOATIR500Accelerator_commandLock));
  if ((shapeBits & 0x80) != 0) {
    accelerator = M<int>(self + kIOATIR500Surface_accelerator);
    hardwareUp = M<char>(accelerator + kIOATIR500Accelerator_active);
    while (hardwareUp == '\0') {
      GH_IOLockSleep(M<UInt32>(accelerator + kIOATIR500Accelerator_commandLock),accelerator,0);
      hardwareUp = M<char>(accelerator + kIOATIR500Accelerator_active);
    }
  }
  keepBacking = (backingPitch == 0xffffffff) << 1;
  if ((backingPitch != 0xffffffff) && (backingLength != 0)) {
    M<int>(self + kIOATIR500Surface_backingLength) = backingLength;
  }
  if ((M<unsigned int>(self + kIOATIR500Surface_lockFlags) & 0xffff0000) != 0) {
    result = 0xe00002cc;
    goto LAB_000157b4;
  }
  if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x20) == 0) {
    result = 0xe00002bc;
    goto LAB_000157b4;
  }
  M<unsigned int>(self + kIOATIR500Surface_shapeBits) = shapeBits;
  if ((self[0xbec] == 0x0) || ((shapeBits & 4) == 0)) {
    reshape = false;
  }
  else {
    reshape = true;
    self[0xbec] = 0x0;
  }
  idOffset = id * 8;
  M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) | 0x10000000;
  if ((reshape) ||
     ((self[0xbec] == 0x0 &&
      (M<int>(M<int>(self + idOffset + 0xd60) + 8) != regionRaw[2])))) {
    reshape = true;
  }
  else {
    reshape = false;
  }
  if ((M<unsigned int>(self + idOffset + 0xd64) < regionSize) ||
     ((regionSize & 0xffffff00) != (M<unsigned int>(self + idOffset + 0xd64) & 0xffffff00))) {
    newRegion = GH_IOMallocAligned(regionSize,0x20);
    if (newRegion == 0) {
      result = 0xe00002be;
      goto LAB_000157b4;
    }
    acceleratorBytes = M<int>(self + kIOATIR500Surface_accelerator);
    if (acceleratorBytes != 0) {
      M<unsigned int>(acceleratorBytes + 0x804) = regionSize + M<int>(acceleratorBytes + 0x804);
    }
    GH_IOFreeAligned(M<UInt32>(self + idOffset + 0xd60),M<UInt32>(self + idOffset + 0xd64));
    acceleratorBytes = M<int>(self + kIOATIR500Surface_accelerator);
    if (acceleratorBytes != 0) {
      M<int>(acceleratorBytes + 0x804) = M<int>(acceleratorBytes + 0x804) - M<int>(self + idOffset + 0xd64);
    }
    M<unsigned int>(self + idOffset + 0xd64) = regionSize;
    M<int>(self + idOffset + 0xd60) = newRegion;
  }
  regionWord1 = regionRaw[1];
  regionBounds = regionRaw[2];
  regionRecord = M<int *>(self + idOffset + 0xd60);
  *regionRecord = *regionRaw;
  regionRecord[1] = regionWord1;
  regionRecord[2] = regionBounds;
  rectCount = *regionRaw;
  if (rectCount != 0) {
    rectIndex = 0;
    rectCursor = regionRaw;
    rectsLeft = rectCount;
    if (rectCount == 0) {
      rectsLeft = 1;
    }
    do {
      rectWordA = rectCursor[3];
      rectRecord = rectIndex * 8;
      rectIndex = rectIndex + 1;
      rectWordBPtr = rectCursor + 4;
      rectCursor = rectCursor + 2;
      rectRecord = rectRecord + M<int>(self + idOffset + 0xd60);
      M<int>(rectRecord + 0x10) = *rectWordBPtr;
      M<int>(rectRecord + 0xc) = rectWordA;
      rectsLeft = rectsLeft + -1;
    } while (rectsLeft != 0);
  }
  if (((1 << (id & 0x3f) & M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xd0)) == 0) ||
     ((rectCount == 1 && ((M<SInt16>(regionRaw + 4) == 0 || (M<SInt16>((int)regionRaw + 0x12) == 0))))))
  {
    panelActive = 0x0;
  }
  else {
    panelActive = 0x1;
  }
  PANEL_RECORD(self, id)->active = panelActive;
  if (self[0xbec] == 0x0) {
    regionWidth = M<UInt16>(regionRaw + 2);
    M<UInt16>(self + kIOATIR500Surface_width) = regionWidth;
    regionHeight = M<UInt16>((int)regionRaw + 10);
    M<UInt16>(self + kIOATIR500Surface_scalingBufferY) = 0;
    M<UInt16>(self + kIOATIR500Surface_scalingSourceWidth) = regionWidth;
    M<UInt16>(self + kIOATIR500Surface_scalingBufferX) = 0;
    M<UInt16>(self + kIOATIR500Surface_scalingSourceHeight) = regionHeight;
    M<UInt16>(self + kIOATIR500Surface_height) = regionHeight;
  }
  noBacking = (backingAddress == 0) << 1;
  M<UInt16>(self + kIOATIR500Surface_regionWidth) = M<UInt16>(regionRaw + 2);
  M<UInt16>(self + kIOATIR500Surface_regionHeight) = M<UInt16>((int)regionRaw + 10);
  if ((backingAddress == 0) || (*regionRaw != 1)) {
    M<UInt16>(self + kIOATIR500Surface_committedWidth) = M<UInt16>(self + kIOATIR500Surface_width);
    M<UInt16>(self + kIOATIR500Surface_committedHeight) = M<UInt16>(self + kIOATIR500Surface_height);
  }
  else {
    M<UInt16>(self + kIOATIR500Surface_committedWidth) = M<UInt16>(regionRaw + 4);
    M<UInt16>(self + kIOATIR500Surface_committedHeight) = M<UInt16>((int)regionRaw + 0x12);
  }
  notReshaped = !reshape << 1;
  if ((reshape) || ((M<unsigned int>(self + kIOATIR500Surface_lockDataFlags) & 2) != 0)) {
    VCALL(M<int>(self), 0x5c8)(self);
    this->update_contexts();
  }
  shapeOk = VCALL(M<int>(self), 0x5b0)
                     (self,(int)M<SInt16>(self + kIOATIR500Surface_width),(int)M<SInt16>(self + kIOATIR500Surface_height));
  if (shapeOk == 0) {
LAB_00015720:
    result = 0xe00002be;
    M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) | 0x20000000;
  }
  else {
    if (!(bool)(notReshaped >> 1 & 1)) {
      vramElement[3] = 0;
      vramElement[0] = 0;
      vramElement[1] = 0;
      vramElement[2] = 0;
      vramAllocOk = VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x540)
                         (M<int *>(self + kIOATIR500Surface_accelerator),vramElement,
                          M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x10),0x1000);
      if (vramAllocOk == 0) goto LAB_00015720;
      M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) & 0xdfffffff;
      VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x544)(M<int *>(self + kIOATIR500Surface_accelerator),vramElement);
    }
    surfaceBuffer = M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffers);
    if ((bool)(keepBacking >> 1 & 1)) {
      backingPitch = 0;
    }
    else if (M<UInt8 *>(surfaceBuffer + 0x24) != (UInt8 *)0x0) {
      this->delete_buffer_backing((IOTextureBuffer *)(M<UInt8 *>(surfaceBuffer + 0x24)));
      M<UInt32>(surfaceBuffer + 0x24) = 0;
    }
    if ((((bool)(noBacking >> 1 & 1)) || (backingPitch == 0)) ||
       (connectOk = this->connect_buffer_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer),backingAddress,backingPitch), connectOk == 0)) {
      result = 0;
    }
    else {
      if ((shapeBits & 0x20) == 0) {
        stampValue = M<int>(self + kIOATIR500Surface_stamp);
      }
      else {
        stampValue = M<int>(self + kIOATIR500Surface_stamp) + -1;
      }
      result = 0;
      M<int>(M<int>(surfaceBuffer + 0x24) + 0x54) = stampValue;
    }
  }
LAB_000157b4:
  self[0xbef] = ((UInt8)(shapeBits >> 3) & 1);
  if ((M<SInt16>(self + kIOATIR500Surface_scalingFlags) != 0) || (scalingFlag = 0x0, (shapeBits & 0x10) != 0)) {
    scalingFlag = 0x1;
  }
  self[0xbed] = scalingFlag;
  if ((shapeBits & 1) == 0) {
    acceleratorObject = M<int *>(self + kIOATIR500Surface_accelerator);
    waitBefore = acceleratorObject[0x1f0];
    waitTime = VCALL(*acceleratorObject, 0x558)(acceleratorObject,M<UInt32>(self + kIOATIR500Surface_submittedStamp));
    acceleratorObject[0x1f0] = waitBefore + waitTime;
    self[0xbf2] = 0x0;
  }
  else {
    self[0xbf2] = 0x1;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x840));
  return result;
}
