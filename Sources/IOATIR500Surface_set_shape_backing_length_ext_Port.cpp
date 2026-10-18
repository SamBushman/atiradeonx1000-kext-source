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

  int *piVar1;
  char hardwareUp;
  UInt16 regionWidth;
  UInt16 regionHeight;
  UInt8 IVar5;
  int iVar6;
  int iVar7;
  int rectIndex;
  bool reshape;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  UInt32 result;
  UInt8 *surfaceBuffer;
  UInt8 noBacking;
  UInt8 keepBacking;
  UInt8 notReshaped;
  UInt32 local_48;
  UInt32 local_44;
  UInt32 local_40;
  UInt32 local_3c;
  
  iVar10 = M<int>(self + kIOATIR500Surface_accelerator);
  if (((M<unsigned int>(iVar10 + 0xcc) <= id) || (M<SInt16>(regionRaw + 2) < 0)) ||
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
    iVar10 = M<int>(self + kIOATIR500Surface_accelerator);
  }
  GH_IOLockLock(M<UInt32>(iVar10 + 0x840));
  if ((shapeBits & 0x80) != 0) {
    iVar10 = M<int>(self + kIOATIR500Surface_accelerator);
    hardwareUp = M<char>(iVar10 + 0x80);
    while (hardwareUp == '\0') {
      GH_IOLockSleep(M<UInt32>(iVar10 + 0x840),iVar10,0);
      hardwareUp = M<char>(iVar10 + 0x80);
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
  iVar10 = id * 8;
  M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) | 0x10000000;
  if ((reshape) ||
     ((self[0xbec] == 0x0 &&
      (M<int>(M<int>(self + iVar10 + 0xd60) + 8) != regionRaw[2])))) {
    reshape = true;
  }
  else {
    reshape = false;
  }
  if ((M<unsigned int>(self + iVar10 + 0xd64) < regionSize) ||
     ((regionSize & 0xffffff00) != (M<unsigned int>(self + iVar10 + 0xd64) & 0xffffff00))) {
    iVar13 = GH_IOMallocAligned(regionSize,0x20);
    if (iVar13 == 0) {
      result = 0xe00002be;
      goto LAB_000157b4;
    }
    iVar6 = M<int>(self + kIOATIR500Surface_accelerator);
    if (iVar6 != 0) {
      M<unsigned int>(iVar6 + 0x804) = regionSize + M<int>(iVar6 + 0x804);
    }
    GH_IOFreeAligned(M<UInt32>(self + iVar10 + 0xd60),M<UInt32>(self + iVar10 + 0xd64));
    iVar6 = M<int>(self + kIOATIR500Surface_accelerator);
    if (iVar6 != 0) {
      M<int>(iVar6 + 0x804) = M<int>(iVar6 + 0x804) - M<int>(self + iVar10 + 0xd64);
    }
    M<unsigned int>(self + iVar10 + 0xd64) = regionSize;
    M<int>(self + iVar10 + 0xd60) = iVar13;
  }
  iVar13 = regionRaw[1];
  iVar6 = regionRaw[2];
  piVar12 = M<int *>(self + iVar10 + 0xd60);
  *piVar12 = *regionRaw;
  piVar12[1] = iVar13;
  piVar12[2] = iVar6;
  iVar13 = *regionRaw;
  if (iVar13 != 0) {
    rectIndex = 0;
    piVar12 = regionRaw;
    iVar6 = iVar13;
    if (iVar13 == 0) {
      iVar6 = 1;
    }
    do {
      iVar11 = piVar12[3];
      iVar7 = rectIndex * 8;
      rectIndex = rectIndex + 1;
      piVar1 = piVar12 + 4;
      piVar12 = piVar12 + 2;
      iVar7 = iVar7 + M<int>(self + iVar10 + 0xd60);
      M<int>(iVar7 + 0x10) = *piVar1;
      M<int>(iVar7 + 0xc) = iVar11;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (((1 << (id & 0x3f) & M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xd0)) == 0) ||
     ((iVar13 == 1 && ((M<SInt16>(regionRaw + 4) == 0 || (M<SInt16>((int)regionRaw + 0x12) == 0))))))
  {
    IVar5 = 0x0;
  }
  else {
    IVar5 = 0x1;
  }
  PANEL_RECORD(self, id)->active = IVar5;
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
  iVar10 = VCALL(M<int>(self), 0x5b0)
                     (self,(int)M<SInt16>(self + kIOATIR500Surface_width),(int)M<SInt16>(self + kIOATIR500Surface_height));
  if (iVar10 == 0) {
LAB_00015720:
    result = 0xe00002be;
    M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) | 0x20000000;
  }
  else {
    if (!(bool)(notReshaped >> 1 & 1)) {
      local_3c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      iVar10 = VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x540)
                         (M<int *>(self + kIOATIR500Surface_accelerator),&local_48,
                          M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x10),0x1000);
      if (iVar10 == 0) goto LAB_00015720;
      M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) & 0xdfffffff;
      VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x544)(M<int *>(self + kIOATIR500Surface_accelerator),&local_48);
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
       (iVar10 = this->connect_buffer_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer),backingAddress,backingPitch), iVar10 == 0)) {
      result = 0;
    }
    else {
      if ((shapeBits & 0x20) == 0) {
        iVar10 = M<int>(self + kIOATIR500Surface_stamp);
      }
      else {
        iVar10 = M<int>(self + kIOATIR500Surface_stamp) + -1;
      }
      result = 0;
      M<int>(M<int>(surfaceBuffer + 0x24) + 0x54) = iVar10;
    }
  }
LAB_000157b4:
  self[0xbef] = ((UInt8)(shapeBits >> 3) & 1);
  if ((M<SInt16>(self + kIOATIR500Surface_scalingFlags) != 0) || (IVar5 = 0x0, (shapeBits & 0x10) != 0)) {
    IVar5 = 0x1;
  }
  self[0xbed] = IVar5;
  if ((shapeBits & 1) == 0) {
    piVar12 = M<int *>(self + kIOATIR500Surface_accelerator);
    iVar13 = piVar12[0x1f0];
    iVar10 = VCALL(*piVar12, 0x558)(piVar12,M<UInt32>(self + kIOATIR500Surface_submittedStamp));
    piVar12[0x1f0] = iVar13 + iVar10;
    self[0xbf2] = 0x0;
  }
  else {
    self[0xbf2] = 0x1;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x840));
  return result;
}
