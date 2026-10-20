/*
 * IOATIR500Surface_stop_Port.cpp
 *
 * IOATIR500Surface::stop (real addr 0x134b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x134b0 */
void IOATIR500Surface::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  bool notLast;
  UInt8 lockState;
  UInt8 *contextGL;
  UInt8 *context2D;
  UInt8 *nextGL;
  UInt8 *next2D;
  SInt32 *backingMemory;
  UInt32 panelIndex;
  UInt8 *cursor;
  UInt8 *regionSlot;
  PanelRecord *panel;
  SInt32 nextSurface;
  SInt32 volatileCount;
  SInt32 backingNode;
  SInt32 attachment;
  SInt32 bufferIndex;
  SInt32 acceleratorBytes;
  SInt32 accelerator;
  SInt32 transferBuffer;
  
  M<UInt32>(self + kIOATIR500Surface_vramInitSucceeded) = 0;
  nextSurface = M<SInt32>(self + kIOATIR500Surface_surfaceListNext);
  accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
  M<UInt32>(nextSurface + kIOATIR500Surface_surfaceListPrev) = M<UInt32>(self + kIOATIR500Surface_surfaceListPrev);
  M<SInt32>(M<SInt32>(self + kIOATIR500Surface_surfaceListPrev) + 0x9c) = nextSurface;
  if (self == M<UInt8 *>(accelerator + kIOATIR500Accelerator_liveSurfaceListHead)) {
    if (self == M<UInt8 *>(self + kIOATIR500Surface_surfaceListNext)) {
      M<UInt32>(accelerator + kIOATIR500Accelerator_liveSurfaceListHead) = 0;
      accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
    }
    else {
      M<UInt8 *>(accelerator + kIOATIR500Accelerator_liveSurfaceListHead) = M<UInt8 *>(self + kIOATIR500Surface_surfaceListNext);
      accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
    }
  }
  M<SInt32>(accelerator + kIOATIR500Accelerator_surfaceCount) = M<SInt32>(accelerator + kIOATIR500Accelerator_surfaceCount) + -1;
  if (M<SInt32>(self + kIOATIR500Surface_volatileState) != 0) {
    volatileCount = M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x21c);
    if (volatileCount != 0) {
      M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x21c) = volatileCount + -1;
    }
  }
  backingNode = M<SInt32>(self + kIOATIR500Surface_backingStoreList);
  while (backingNode != 0) {
    M<UInt32>(backingNode + 0x50) = 0;
    M<UInt8>(M<SInt32>(backingNode + 0x14) + 0x14) = 1;
    M<UInt32>(self + kIOATIR500Surface_backingStoreList) = M<UInt32>(backingNode + 0x54);
    M<UInt32>(backingNode + 0x54) = 0;
    backingNode = M<SInt32>(self + kIOATIR500Surface_backingStoreList);
  }
  if ((M<SInt32>(self + kIOATIR500Surface_panel) != 0xffff) &&
     (self == M<UInt8 *>(M<SInt32>(self + kIOATIR500Surface_panel) * 0x20 + M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xe8))
     ) {
    VCALL(M<SInt32>(self), 0x5a8)(self);
    M<UInt32>(M<SInt32>(self + kIOATIR500Surface_panel) * 0x20 + M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xe8) = 0;
    M<UInt32>(self + kIOATIR500Surface_panel) = 0xffff;
  }
  lockState = self[0xbd0];
  if (lockState != 0x0) {
    if (lockState == 0x3) {
      attachment = M<SInt32>(self + kIOATIR500Surface_attachmentBuffers);
      if (M<SInt32>(self + kIOATIR500Surface_orphanedBacking) == 0) {
        transferBuffer = M<SInt32>(attachment + 0x24);
        if ((transferBuffer != 0) && (backingMemory = M<SInt32 *>(transferBuffer + 0x10), backingMemory != (SInt32 *)0x0)) {
          VCALL(*backingMemory, 0x18)(backingMemory);
          M<UInt32>(M<SInt32>(attachment + 0x24) + 0x10) = 0;
        }
      }
      else {
        this->free_buffer_backing_orphans();
      }
    }
    else if (lockState == 0x1) {
      VCALL(M<SInt32>(self), 0x600)(self,M<UInt32>(self + kIOATIR500Surface_attachmentBuffers));
    }
    self[0xbd0] = 0x0;
  }
  if (M<SInt32 *>(self + kIOATIR500Surface_userMap) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Surface_userMap), 0x18)(M<SInt32 *>(self + kIOATIR500Surface_userMap));
    M<UInt32>(self + kIOATIR500Surface_userMap) = 0;
  }
  if (M<SInt32 *>(self + kIOATIR500Surface_kernelMap) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Surface_kernelMap), 0x18)(M<SInt32 *>(self + kIOATIR500Surface_kernelMap));
    M<UInt32>(self + kIOATIR500Surface_kernelMap) = 0;
  }
  contextGL = M<UInt8 *>(self + kIOATIR500Surface_glContextList);
  while (contextGL != (UInt8 *)0x0) {
    ((IOATIR500GLContext *)(contextGL))->remove_surface();
    nextGL = M<UInt8 *>(contextGL + 0x84);
    M<UInt32>(contextGL + 0x84) = 0;
    contextGL = nextGL;
  }
  context2D = M<UInt8 *>(self + kIOATIR500Surface_context2DList);
  while (context2D != (UInt8 *)0x0) {
    ((IOATIR5002DContext *)(context2D))->remove_surface();
    next2D = M<UInt8 *>(context2D + 0x84);
    M<UInt32>(context2D + 0x84) = 0;
    context2D = next2D;
  }
  if (M<UInt8 *>(self + kIOATIR500Surface_boundDVDContext) != (UInt8 *)0x0) {
    ((IOATIR500DVDContext *)(M<UInt8 *>(self + kIOATIR500Surface_boundDVDContext)))->remove_surface();
  }
  bufferIndex = 0;
  cursor = self;
  do {
    VCALL(M<SInt32>(self), 0x5cc)(self,bufferIndex);
    if (M<UInt8 *>(cursor + 0xcc) != (UInt8 *)0x0) {
      this->delete_buffer_backing((IOTextureBuffer *)(M<UInt8 *>(cursor + 0xcc)));
      M<UInt32>(cursor + 0xcc) = 0;
    }
    notLast = bufferIndex != 0x16;
    cursor = cursor + 0x78;
    bufferIndex = bufferIndex + 1;
  } while (notLast);
  if (M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xcc) != 0) {
    panelIndex = 0;
    panel = PANEL_RECORD(self, 0);
    regionSlot = self;
    do {
      if (panel->entries[0].memory != 0) {
        this->freeAllSwapBuffers(panelIndex);
      }
      if (M<SInt32>(regionSlot + 0xd60) != 0) {
        GH_IOFreeAligned(M<SInt32>(regionSlot + 0xd60),M<UInt32>(regionSlot + 0xd64));
        acceleratorBytes = M<SInt32>(self + kIOATIR500Surface_accelerator);
        if (acceleratorBytes != 0) {
          M<SInt32>(acceleratorBytes + 0x804) = M<SInt32>(acceleratorBytes + 0x804) - M<SInt32>(regionSlot + 0xd64);
        }
        M<UInt32>(regionSlot + 0xd64) = 0;
        M<UInt32>(regionSlot + 0xd60) = 0;
      }
      panelIndex = panelIndex + 1;
      panel = panel + 1;
      regionSlot = regionSlot + 8;
    } while (panelIndex < M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xcc));
  }
  if (M<SInt32>(self + kIOATIR500Surface_orphanedBacking) != 0) {
    this->free_buffer_backing_orphans();
  }
  IOUserClient::stop(provider);
  return;
}
