/*
 * ATIR500GLContext_alloc_and_load_texture_Port.cpp
 *
 * ATIR500GLContext::alloc_and_load_texture (real addr 0x2a3d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x2a3d0 */
void ATIR500GLContext::alloc_and_load_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt8 type;
  bool compacted;
  SInt32 result;
  SInt32 prev;
  SInt32 nextNode;
  SInt32 next;
  UInt8 *surface;
  UInt8 *linked;
  UInt32 bufferMask [6];
  
  type = textureBytes[0x20];
  if (type == 0x3) {
    if ((((M<SInt32>(textureBytes + 0x48) == 0) &&
         (result = VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x528)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),textureBytes) /* #171: stock 0x2a40c: r4 = the texture buffer (incoming), allocate_texture(VendorTextureBuffer*) */, result == 0)) &&
        (result = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeToAllocTextureVRAM((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)),
                            (VendorTextureBuffer **)((UInt8 **)(self + kATIR500GLContext_textureSlots)),0x2a,(VendorTextureBuffer *)(textureBytes)), result == 0)) &&
       (result = this->compact_current_textures((VendorTextureBuffer *)(textureBytes)), result == 0)) {
      return;
    }
    goto loadTexture;
  }
  if (type == 0x2) {
    if ((M<SInt32>(textureBytes + 4) != 0) ||
       (((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)textureBytes)),
       M<SInt32>(textureBytes + 4) != 0)) {
      GH_IOGetTime(textureBytes + 0x2c);
      nextNode = M<SInt32>(textureBytes + 0x34);
      M<UInt32>(nextNode + 0x38) = M<UInt32>(textureBytes + 0x38);
      M<SInt32>(M<SInt32>(textureBytes + 0x38) + 0x34) = nextNode;
      M<UInt32>(textureBytes + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0);
      M<SInt32>(textureBytes + 0x38) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x69c;
      M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0) = textureBytes;
      M<UInt8 *>(M<SInt32>(textureBytes + 0x34) + 0x38) = textureBytes;
    }
    goto clearDirtyFlag;
  }
  if (type == 0x6) {
    linked = M<UInt8 *>(textureBytes + 0x54);
    if ((M<SInt32>(linked + 4) != 0) ||
       (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(linked)),
       M<SInt32>(linked + 4) != 0)) {
      GH_IOGetTime(linked + 0x2c);
      nextNode = M<SInt32>(linked + 0x34);
      M<UInt32>(nextNode + 0x38) = M<UInt32>(linked + 0x38);
      M<SInt32>(M<SInt32>(linked + 0x38) + 0x34) = nextNode;
      M<UInt32>(linked + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0);
      M<SInt32>(linked + 0x38) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x69c;
      M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0) = linked;
      M<UInt8 *>(M<SInt32>(linked + 0x34) + 0x38) = linked;
    }
    M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) = 0;
    M<UInt8>(M<SInt32>(linked + 0x14) + 0x14) = 0;
    return;
  }
  if (type != 0x7) {
    if (type == 0x0) {
      surface = M<UInt8 *>(textureBytes + 0x50);
      if (surface == (UInt8 *)0x0) {
        surface = (UInt8 *)
                  ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->find_surface_for_id(M<UInt32>(textureBytes + 0x5c));
        M<UInt8 *>(textureBytes + 0x50) = surface;
        if (surface == (UInt8 *)0x0) {
          return;
        }
        M<UInt32>(textureBytes + 0x54) = M<UInt32>(surface + 0xbcc);
        M<UInt8 *>(surface + 0xbcc) = textureBytes;
      }
      if ((M<UInt32>(surface + 0xbf8) & 0x20000000) != 0) {
        return;
      }
      ((IOATIR500Surface *)(surface))->surface_buffer_idx_mask(M<UInt32>(textureBytes + 0x58), (UInt32 *)(bufferMask));
      M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) = 0;
      if ((bufferMask[0] & M<UInt32>(surface + 0xc18) & M<UInt32>(surface + 0xbf8)) == 0) {
        return;
      }
      result = ((IOATIR500Surface *)(surface))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)),
                         (VendorTextureBuffer **)((UInt8 **)(self + kATIR500GLContext_textureSlots)),0x2a,bufferMask[0]);
      compacted = false;
      if (result != 0) {
        result = this->compact_current_textures((VendorTextureBuffer *)(textureBytes));
        compacted = result == 0;
      }
      M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) =
           1U - !compacted | M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14);
      return;
    }
    if (type == 0x1) {
      if (M<UInt8 *>(textureBytes + 0x50) == (UInt8 *)0x0) {
        return;
      }
      this->alloc_and_load_texture((VendorTextureBuffer *)(M<UInt8 *>(textureBytes + 0x50)));
      return;
    }
    if (type != 0x8) {
      return;
    }
    if ((M<SInt32>(textureBytes + 0x48) == 0) && (M<SInt32>(textureBytes + 8) != 0)) {
      if (M<SInt32>(textureBytes + 4) != 0) goto moveToListHead;
      ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)textureBytes));
    }
    if (M<SInt32>(textureBytes + 4) == 0) {
      return;
    }
moveToListHead:
    GH_IOGetTime(textureBytes + 0x2c);
    nextNode = M<SInt32>(textureBytes + 0x34);
    M<UInt32>(nextNode + 0x38) = M<UInt32>(textureBytes + 0x38);
    M<SInt32>(M<SInt32>(textureBytes + 0x38) + 0x34) = nextNode;
    M<UInt32>(textureBytes + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0);
    M<SInt32>(textureBytes + 0x38) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x69c;
    M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x6d0) = textureBytes;
    M<UInt8 *>(M<SInt32>(textureBytes + 0x34) + 0x38) = textureBytes;
    return;
  }
  if (M<SInt32>(textureBytes + 0x48) == 0) {
allocTextureMemory:
    result = VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x528)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),textureBytes);
    if (((result == 0) &&
        (result = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeToAllocTextureVRAM((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)),
                            (VendorTextureBuffer **)((UInt8 **)(self + kATIR500GLContext_textureSlots)),0x2a,(VendorTextureBuffer *)(textureBytes)), result == 0)) &&
       (result = this->compact_current_textures((VendorTextureBuffer *)(textureBytes)), result == 0)) {
      prev = M<SInt32>(textureBytes + 0x24);
      M<UInt32>(prev + 0x28) = M<UInt32>(textureBytes + 0x28);
      next = M<SInt32>(textureBytes + 0x28);
      M<UInt8 *>(textureBytes + 0x28) = textureBytes;
      M<SInt32>(next + 0x24) = prev;
      M<UInt8 *>(textureBytes + 0x24) = textureBytes;
      return;
    }
  }
  else if ((M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) & 2) != 0) {
    /* #171: stock 0x2a58c: r4 = the texture buffer (incoming), deallocate_texture(VendorTextureBuffer*) */
    VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x524)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),textureBytes);
    M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) = 1;
    M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x28) = 0;
    M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2a) = 0;
    M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2c) = 0;
    M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2e) = 0;
    M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x30) = 0;
    M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x32) = 0;
    M<UInt32>(textureBytes + 0x50) = M<UInt32>(M<SInt32>(textureBytes + 0x14) + 0x18);
    if (M<SInt32>(textureBytes + 0x48) == 0) goto allocTextureMemory;
  }
loadTexture:
  this->load_texture((VendorTextureBuffer *)(textureBytes));
clearDirtyFlag:
  M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) = 0;
  return;
}
