/*
 * IOATIR500GLContext_read_buffer_Port.cpp
 *
 * IOATIR500GLContext::read_buffer (real addr 0x8d10, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");


/* real addr 0x8d10 */
IOReturn IOATIR500GLContext::read_buffer(sIOGLContextReadBufferData *readData, UInt32 structSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *readDataBytes = reinterpret_cast<UInt8 *>(readData);

  SInt32 surfaceWidth;
  UInt8 *surface;
  SInt32 surfaceHeight;
  UInt32 bufferIndex;
  SInt32 rowBytes;
  SInt32 destAddress;
  SInt32 height;
  SInt32 width;
  SInt32 attachment;
  SInt32 y;
  SInt32 sourceBuffer;
  UInt32 result;
  SInt32 x;
  SInt32 *surfaceObject;
  SInt32 *acceleratorObject;
  UInt32 attachmentMask;
  UInt32 userAddress;
  SInt32 destOffset;
  SInt32 bottomEdge;
  UInt8 *attachmentSurface;
  /* Ghidra split one 16-byte stack record (r1+0x58, the 3rd-from-last argument of the +0x5e8/+0x5ac calls) into five scalars; the callee
   * writes local_s.f44 through `&local_s`, so as separate scalars the `local_s.f44 != 0` branch (unlock / +0x55c / relock / +0x5ac) was
   * folded away as dead code (#86/#85: the stock-only IOLockLock/IOLockUnlock/indirect calls). Keep it one object. */
  struct { UInt32 f48; SInt32 f44; SInt32 *f40; UInt16 f3c; UInt16 f3a; } local_s;
  
  local_s.f3a = 0;
  local_s.f3c = 3;
  local_s.f48 = 0;
  local_s.f44 = 0;
  local_s.f40 = (SInt32 *)0x0;
  x = M<SInt32>(readDataBytes);
  y = M<SInt32>(readDataBytes + 4);
  width = M<SInt32>(readDataBytes + 8);
  height = M<SInt32>(readDataBytes + 0xc);
  destAddress = M<SInt32>(readDataBytes + 0x14);
  switch(M<UInt32>(readDataBytes + 0x10)) {
  case 0:
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
  default:
    return 0xe00002c2;
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
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  surface = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
  if (surface == (UInt8 *)0x0) goto LAB_00008f74;
  if ((0xff < M<UInt32>(surface + kIOATIR500Surface_requestedId)) &&
     (sourceBuffer = M<SInt32>(self + kIOATIR500GLContext_accelerator), M<char>(sourceBuffer + 0x80) == '\0')) {
    do {
      GH_IOLockSleep(M<UInt32>(sourceBuffer + 0x840),sourceBuffer,0);
    } while (M<char>(sourceBuffer + 0x80) == '\0');
    surface = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
    if (surface == (UInt8 *)0x0) goto LAB_00008f74;
  }
  if ((((attachment != 0) || (M<SInt32>(surface + kIOATIR500Surface_panel) == 0xffff)) ||
      (attachmentSurface = *(UInt8 **)
                 (M<SInt32>(surface + kIOATIR500Surface_panel) * 0x20 + M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xe8),
      attachmentSurface == (UInt8 *)0x0)) || (surface == attachmentSurface)) {
    attachmentSurface = surface + attachment * 4;
  }
  sourceBuffer = M<SInt32>(attachmentSurface + 0xb70);
  attachmentMask = 0x40000000;
  bufferIndex = (sourceBuffer - (SInt32)(surface + kIOATIR500Surface_buffers) >> 3) * -0x11111111;
  if ((bufferIndex < 0x17) && (attachmentMask = 1 << (bufferIndex & 0x3f) & M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask), attachmentMask == 0))
  goto LAB_00008f74;
  if ((M<UInt32>(surface + kIOATIR500Surface_stateBits) & attachmentMask) == 0) {
LAB_00008f60:
    if (((M<UInt32>(surface + kIOATIR500Surface_stateBits) & 0x20000000) != 0) || (M<SInt32>(sourceBuffer + 0x10) == 0)) {
LAB_00008f74:
      GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
      return 0xe00002cc;
    }
  }
  else {
    if (M<SInt32>(sourceBuffer + 0x24) == 0) goto LAB_00008fb0;
    if ((M<char>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x80) == '\0') ||
       (M<char>(M<SInt32>(sourceBuffer + 0x24) + 0x58) != '\0')) goto LAB_00008f60;
    sourceBuffer = ((IOATIR500Surface *)(surface))->alloc_surfaces_retry(attachmentMask, (eLockType)(0));
    if (sourceBuffer != 0) goto LAB_00008f74;
    surface = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
    sourceBuffer = M<SInt32>(surface + attachment * 4 + kIOATIR500Surface_attachmentBuffers);
  }
  attachment = x + width;
  if ((((0 < attachment) && (bottomEdge = y + height, 0 < bottomEdge)) &&
      (surfaceWidth = (SInt32)M<SInt16>(surface + kIOATIR500Surface_width), x < surfaceWidth)) &&
     (surfaceHeight = (SInt32)M<SInt16>(surface + kIOATIR500Surface_height), y < surfaceHeight)) {
    rowBytes = M<SInt32>(readDataBytes + 0x18);
    destOffset = 0;
    if (x < 0) {
      destOffset = (UInt32)M<UInt16>(sourceBuffer + 0x16) * x;
      x = 0;
      destOffset = -destOffset;
      width = attachment;
    }
    if (y < 0) {
      height = rowBytes * y;
      y = 0;
      destOffset = destOffset - height;
      height = bottomEdge;
    }
    if (surfaceWidth < attachment) {
      width = surfaceWidth - x;
    }
    if (surfaceHeight < bottomEdge) {
      height = surfaceHeight - y;
    }
    userAddress = destAddress + destOffset;
    bufferIndex = userAddress & GH_page_size - 1U;
    local_s.f40 = (SInt32 *)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(userAddress & -GH_page_size,
                                   -GH_page_size &
                                   (GH_page_size +
                                   rowBytes * (height + -1) +
                                   (UInt32)M<UInt16>(sourceBuffer + 0x16) * width + bufferIndex) - 1,0,
                                   M<UInt32>(self + kIOATIR500GLContext_task));
    if (local_s.f40 == (SInt32 *)0x0) {
      result = 0xe00002be;
    }
    else {
      surfaceObject = M<SInt32 *>(self + kIOATIR500GLContext_boundSurface);
      destAddress = surfaceObject[0x1f];
      /* +0x5e8 is copy_from_buffer -> copy_buffer_using_DMA (ATIR500Surface_copy_buffer_using_DMA_Port.cpp):
       * this is NOT a memcpy of sourceBuffer's backing bytes. It builds a real GPU 3D-render command
       * (write_3dtexquad_cmds_for_copy_buffer_using_DMA - the function issue #158's root-cause fix
       * touched) that samples sourceBuffer as a texture and renders a quad into local_s.f40, then submits
       * it to the GPU and returns without waiting here. Confirmed live (#158 follow-up, 2026-10-13):
       * a CPU write made through a separately-locked mapping of this same buffer record had no
       * observable effect on what came back - don't assume a CPU-side write to the source surface
       * is visible to this call, and don't assume the returned content is a literal byte copy. */
      VCALL(*surfaceObject, 0x5e8)
                (surfaceObject,x,y,width,height,M<UInt32>(self + kIOATIR500GLContext_surfaceIndex),
                 M<UInt32>(self + kIOATIR500GLContext_mipLevel),sourceBuffer,M<UInt32>(self + kIOATIR500GLContext_lastSubmitStamp),&local_s,
                 bufferIndex,rowBytes,2);
      height = 0xa0;
      width = 0x17;
      do {
        y = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + height + 0x2c);
        if ((y != 0) && (destAddress == M<SInt32>(y + 0x54))) {
          M<UInt32>(y + 0x54) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0x7c);
        }
        height = height + 0x78;
        width = width + -1;
      } while (width != 0);
      if (local_s.f44 != 0) {
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
        acceleratorObject = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
        width = acceleratorObject[0x1ed];
        height = VCALL(*acceleratorObject, 0x55c)
                           (acceleratorObject,M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0x7c));
        acceleratorObject[0x1ed] = width + height;
        GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
        VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x5ac)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),&local_s);
      }
      result = 0;
      VCALL(*local_s.f40, 0x18)(local_s.f40);
    }
    local_s.f40 = (SInt32 *)0x0;
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
    return result;
  }
LAB_00008fb0:
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  return 0;
}
