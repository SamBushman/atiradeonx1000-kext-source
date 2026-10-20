/*
 * IOATIR500Surface_set_id_mode_Port.cpp
 *
 * IOATIR500Surface::set_id_mode (real addr 0x142b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* real addr 0x142b0 */
IOReturn IOATIR500Surface::set_id_mode(UInt32 mode, eIOSurfaceModeBits modeBits) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 modeBitsValue = modeBits;   /* the body edits the mode bits as a plain integer */

  UInt8 *owner;
  unsigned int currentPanel;
  SInt16 requiredKind;
  int accelerator;
  unsigned int requestedId;
  UInt32 result;
  UInt32 vramElement[4];   /* ONE real 16-byte GLKMemoryElement: the decompile showed four separate locals and stock passes vramElement (stock's compiler placed them adjacently) */
  int acceleratorPtr;
  int panelNo;
  int newRegion;
  int shapeStatus;
  int storageBytes;
  int vramAllocOk;
  UInt16 panelWidth;
  UInt16 panelHeight;
  
  if ((modeBitsValue & 0xffff7fc0) != 0) {
    return 0xe00002c2;
  }
  GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x840));
  if ((M<unsigned int>(self + kIOATIR500Surface_lockFlags) & 0xffff0000) != 0) {
    acceleratorPtr = M<int>(self + kIOATIR500Surface_accelerator);
    result = 0xe00002cc;
    goto LAB_000147d0;
  }
  if (((M<int>(self + kIOATIR500Surface_boundDVDContext) == 0) && (M<int>(self + kIOATIR500Surface_glContextList) == 0)) && (M<int>(self + kIOATIR500Surface_context2DList) == 0)
     ) {
LAB_00014370:
    if ((modeBitsValue & 0x20) != 0) {
      requestedId = mode;
      mode = 0xffff;
LAB_00014454:
      currentPanel = M<unsigned int>(self + kIOATIR500Surface_panel);
      if (((currentPanel != 0xffff) && (mode != currentPanel)) &&
         (self == M<UInt8 *>(currentPanel * 0x20 + M<int>(self + kIOATIR500Surface_accelerator) + 0xe8))) {
        VCALL(M<int>(self), 0x5a8)(self);
        M<UInt32>(M<int>(self + kIOATIR500Surface_panel) * 0x20 + M<int>(self + kIOATIR500Surface_accelerator) + 0xe8) = 0;
      }
      M<unsigned int>(self + kIOATIR500Surface_requestedId) = requestedId;
      M<unsigned int>(self + kIOATIR500Surface_modeBits) = modeBitsValue;
      M<unsigned int>(self + kIOATIR500Surface_panel) = mode;
      if ((mode != 0xffff) && ((modeBitsValue & 0x8000) != 0)) {
        M<UInt8 *>(mode * 0x20 + M<int>(self + kIOATIR500Surface_accelerator) + 0xe8) = self;
      }
      M<UInt32>(self + kIOATIR500Surface_reqBits) = 0x20000000;
      if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x20) != 0) {
        M<UInt32>(self + kIOATIR500Surface_reqBits) = 0x30000000;
      }
      if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x30) == 0x10) {
        M<unsigned int>(self + kIOATIR500Surface_reqBits) = M<unsigned int>(self + kIOATIR500Surface_reqBits) | 0x20;
      }
      result = 0;
      this->reset_req_bits();
      this->reset_access();
      if ((M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0x20) == 0) {
        M<UInt32>(self + kIOATIR500Surface_shapeBits) = 0;
        panelNo = M<int>(self + kIOATIR500Surface_panel);
        if (M<int>(self + panelNo * 8 + 0xd64) == 0xc) {
LAB_0001460c:
          result = 0;
        }
        else {
          newRegion = GH_IOMallocAligned(0xc,0x20);
          if (newRegion == 0) {
            panelNo = M<int>(self + kIOATIR500Surface_panel);
            result = 0xe00002be;
          }
          else {
            GH_IOFreeAligned(M<UInt32>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd60),
                         M<UInt32>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd64));
            accelerator = M<int>(self + kIOATIR500Surface_accelerator);
            if (accelerator != 0) {
              M<int>(accelerator + 0x804) =
                   M<int>(accelerator + 0x804) - M<int>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd64);
            }
            M<int>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd60) = newRegion;
            M<UInt32>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd64) = 0xc;
            acceleratorPtr = M<int>(self + kIOATIR500Surface_accelerator);
            if (acceleratorPtr == 0) {
              panelNo = M<int>(self + kIOATIR500Surface_panel);
              goto LAB_0001460c;
            }
            result = 0;
            M<int>(acceleratorPtr + 0x804) = M<int>(acceleratorPtr + 0x804) + 0xc;
            panelNo = M<int>(self + kIOATIR500Surface_panel);
          }
        }
        *M<UInt32 *>(self + panelNo * 8 + 0xd60) = 0;
        M<UInt16>(M<int>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd60) + 4) = 0;
        M<UInt16>(M<int>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd60) + 6) = 0;
        panelWidth = M<UInt16>(M<int>(self + kIOATIR500Surface_panel) * 0x78 + M<int>(self + kIOATIR500Surface_accelerator) + 0x148);
        M<UInt16>(M<int>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd60) + 8) = panelWidth;
        M<UInt16>(self + kIOATIR500Surface_width) = panelWidth;
        M<UInt16>(self + kIOATIR500Surface_committedWidth) = panelWidth;
        panelHeight = M<UInt16>(M<int>(self + kIOATIR500Surface_panel) * 0x78 + M<int>(self + kIOATIR500Surface_accelerator) + 0x14a);
        M<UInt16>(M<int>(self + M<int>(self + kIOATIR500Surface_panel) * 8 + 0xd60) + 10) = panelHeight;
        M<UInt16>(self + kIOATIR500Surface_height) = panelHeight;
        M<UInt16>(self + kIOATIR500Surface_committedHeight) = panelHeight;
        shapeStatus = VCALL(M<int>(self), 0x5dc)(self);
        if (shapeStatus == 0) {
          PANEL_RECORD(self, M<int>(self + kIOATIR500Surface_panel))->active = 0x1;
          M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) | 0x10000000;
          M<unsigned int>(self + kIOATIR500Surface_reqBits) = M<unsigned int>(self + kIOATIR500Surface_reqBits) | 0x10000000;
        }
      }
      this->prune_buffers();
      if ((M<unsigned int>(self + kIOATIR500Surface_reqBits) & 1) == 0) {
        storageBytes = 0;
        if ((M<unsigned int>(self + kIOATIR500Surface_reqBits) & 2) != 0) {
          storageBytes = M<int>(self + kIOATIR500Surface_buffer1StorageBytes);
        }
      }
      else {
        storageBytes = M<int>(self + kIOATIR500Surface_buffer0StorageBytes);
      }
      M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) & 0xdfffffff;
      if (storageBytes == 0) {
        acceleratorPtr = M<int>(self + kIOATIR500Surface_accelerator);
      }
      else {
        vramElement[3] = 0;
        vramElement[0] = 0;
        vramElement[1] = 0;
        vramElement[2] = 0;
        vramAllocOk = VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x540)
                          (M<int *>(self + kIOATIR500Surface_accelerator),vramElement,storageBytes,0x1000);
        if (vramAllocOk == 0) {
          acceleratorPtr = M<int>(self + kIOATIR500Surface_accelerator);
          result = 0xe00002be;
          M<unsigned int>(self + kIOATIR500Surface_stateBits) = M<unsigned int>(self + kIOATIR500Surface_stateBits) | 0x20000000;
        }
        else {
          VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x544)(M<int *>(self + kIOATIR500Surface_accelerator),vramElement);
          acceleratorPtr = M<int>(self + kIOATIR500Surface_accelerator);
        }
      }
      goto LAB_000147d0;
    }
    acceleratorPtr = M<int>(self + kIOATIR500Surface_accelerator);
    if (mode < M<unsigned int>(acceleratorPtr + kIOATIR500Accelerator_displayCount)) {
      requestedId = ~mode;
      owner = M<UInt8 *>(mode * 0x20 + acceleratorPtr + 0xe8);
      if (((owner == (UInt8 *)0x0) || (self == owner)) || ((modeBitsValue & 0x8000) == 0)) {
        switch(modeBitsValue & 0xf) {
        case 3:
          requiredKind = 2;
          break;
        case 4:
          requiredKind = 4;
          break;
        default:
          requiredKind = 0;
          break;
        case 0xb:
        case 0xc:
          requiredKind = 8;
          break;
        case 0xd:
          requiredKind = 0x10;
        }
        if (M<SInt16>(mode * 0x78 + acceleratorPtr + kIOATIR500Accelerator_scanout1BufferBytesPerPixel) == requiredKind) goto LAB_00014454;
      }
    }
  }
  else {
    if (((modeBitsValue ^ M<unsigned int>(self + kIOATIR500Surface_modeBits)) & 0x803f) == 0) {
      modeBitsValue = modeBitsValue | M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0xffff7fc0;
      goto LAB_00014370;
    }
    acceleratorPtr = M<int>(self + kIOATIR500Surface_accelerator);
  }
  result = 0xe00002bc;
LAB_000147d0:
  GH_IOLockUnlock(M<UInt32>(acceleratorPtr + kIOATIR500Accelerator_commandLock));
  return result;
}
