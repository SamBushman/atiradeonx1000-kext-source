/*
 * ATIR500GLContext_compact_current_textures_Port.cpp
 *
 * ATIR500GLContext::compact_current_textures (real addr 0x29dd0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x29dd0 */
IOReturn ATIR500GLContext::compact_current_textures(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  bool more;
  UInt8 type;
  SInt32 nextNode;
  UInt32 stamp;
  UInt32 result;
  SInt32 prevNode;
  SInt32 slotIndex;
  SInt32 copied;
  SInt32 ready;
  SInt32 vertexWords;
  SInt32 written;
  SInt32 maskIndex;
  SInt32 loaded;
  SInt32 next;
  SInt32 waited;
  UInt32 *record;
  UInt8 *slotCursor;
  UInt32 wordCount;
  UInt32 slot;
  UInt32 paddedWords;
  SInt32 *accelerator;
  UInt32 ringIndex;
  UInt32 bufferIndex;
  SInt32 slotTexture;
  SInt32 waitTotal;
  SInt32 prev;
  UInt8 *surfaceBuffer;
  UInt8 *surface;
  UInt8 *boundTexture;
  UInt32 totalWords;
  UInt32 bufferMask [7];
  
  slotIndex = 0;
  slotCursor = self;
  do {
    slotTexture = M<SInt32>(slotCursor + 0x2a4);
    if (slotTexture != 0) {
      if (M<SInt32>(slotTexture + 0x48) == 0) {
        if (M<char>(slotTexture + 0x20) != '\0') goto nextSlot;
        surface = M<UInt8 *>(slotTexture + 0x50);
        bufferIndex = 0;
        surfaceBuffer = (UInt8 *)(surface + 0xa8);
        do {
          if ((((M<SInt32>(surface + 0xc14) == 0xffff) || ((1 < bufferIndex && (1 < bufferIndex - 4)))) &&
              (M<SInt32>(surfaceBuffer + 8) != 0)) &&
             (((M<UInt32>(surface + 0xbd0) & 0xffff0000) == 0 ||
              (surfaceBuffer != M<UInt8 *>(surface + 0xb70))))) {
            if (M<SInt32>(surface + 0xd48) == 0) {
              ((IOATIR500Surface *)(surface))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            else {
              VCALL(M<SInt32>(surface), 0x5cc)(surface,slotIndex);
            }
          }
          more = bufferIndex != 0x16;
          surfaceBuffer = surfaceBuffer + 0x78;
          bufferIndex = bufferIndex + 1;
        } while (more);
        VCALL(M<SInt32>(surface), 0x5c4)(surface);
      }
      else {
        VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x524)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),slotTexture);
      }
      M<UInt8>(M<SInt32>(slotTexture + 0x14) + 0x14) = 1;
      M<UInt16>(M<SInt32>(slotTexture + 0x14) + 0x28) = 0;
      M<UInt16>(M<SInt32>(slotTexture + 0x14) + 0x2a) = 0;
      M<UInt16>(M<SInt32>(slotTexture + 0x14) + 0x2c) = 0;
      M<UInt16>(M<SInt32>(slotTexture + 0x14) + 0x2e) = 0;
      M<UInt16>(M<SInt32>(slotTexture + 0x14) + 0x30) = 0;
      M<UInt16>(M<SInt32>(slotTexture + 0x14) + 0x32) = 0;
      prevNode = M<SInt32>(slotTexture + 0x24);
      M<UInt32>(prevNode + 0x28) = M<UInt32>(slotTexture + 0x28);
      nextNode = M<SInt32>(slotTexture + 0x28);
      M<SInt32>(slotTexture + 0x28) = slotTexture;
      M<SInt32>(nextNode + 0x24) = prevNode;
      M<SInt32>(slotTexture + 0x24) = slotTexture;
    }
nextSlot:
    more = slotIndex == 0x29;
    slotCursor = slotCursor + 4;
    slotIndex = slotIndex + 1;
    if (more) {
      if (textureBytes[0x20] == 0x0) {
        surface = M<UInt8 *>(textureBytes + 0x50);
        bufferIndex = 0;
        surfaceBuffer = (UInt8 *)(surface + 0xa8);
        do {
          if (((M<SInt32>(surface + 0xc14) == 0xffff) || ((1 < bufferIndex && (1 < bufferIndex - 4)))) &&
             ((M<SInt32>(surfaceBuffer + 8) != 0 &&
              (((M<UInt32>(surface + 0xbd0) & 0xffff0000) == 0 ||
               (surfaceBuffer != M<UInt8 *>(surface + 0xb70))))))) {
            if (M<SInt32>(surface + 0xd48) == 0) {
              ((IOATIR500Surface *)(surface))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            else {
              VCALL(M<SInt32>(surface), 0x5cc)(surface,0x2a);
            }
          }
          more = bufferIndex != 0x16;
          surfaceBuffer = surfaceBuffer + 0x78;
          bufferIndex = bufferIndex + 1;
        } while (more);
        VCALL(M<SInt32>(surface), 0x5c4)(surface);
        M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) = 1;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x28) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2a) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2c) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2e) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x30) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x32) = 0;
        prev = M<SInt32>(textureBytes + 0x24);
        M<UInt32>(prev + 0x28) = M<UInt32>(textureBytes + 0x28);
        next = M<SInt32>(textureBytes + 0x28);
        M<UInt8 *>(textureBytes + 0x28) = textureBytes;
        M<SInt32>(next + 0x24) = prev;
        M<UInt8 *>(textureBytes + 0x24) = textureBytes;
      }
      slot = 0;
      wordCount = 0;
      VCALL(M<SInt32>(self), 0x5a4)(self);
      accelerator = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
      ringIndex = M<SInt32>(self + kIOATIR500GLContext_contextBufferRingIndex) + 1U & 0xf;
      M<UInt32>(self + kIOATIR500GLContext_contextBufferRingIndex) = ringIndex;
      waitTotal = accelerator[0x1e0];
      waited = VCALL(*accelerator, 0x54c)(accelerator,M<UInt32>(self + ringIndex * 0x18 + 0x11c))
      ;
      accelerator[0x1e0] = waitTotal + waited;
      record = (UInt32 *)(M<SInt32>(self + ringIndex * 0x18 + 0x120) + 0x20);
      slotCursor = self;
      do {
        boundTexture = M<UInt8 *>(slotCursor + 0x2a4);
        if ((boundTexture != (UInt8 *)0x0) &&
           (((type = boundTexture[0x20], type == 0x3 ||
             (type == 0x0)) || (type == 0x7)))) {
          if (M<SInt32>(boundTexture + 0x48) == 0) {
            if (type == 0x0) {
              surface = M<UInt8 *>(boundTexture + 0x50);
              maskIndex = ((IOATIR500Surface *)(surface))->surface_buffer_idx_mask(M<UInt32>(boundTexture + 0x58),(UInt32 *)(bufferMask));
              surfaceBuffer = M<UInt8 *>(surface + maskIndex * 4 + 0xb70);
              VCALL(M<SInt32>(surface), 0x5d0)(surface,surfaceBuffer);
              ((IOATIR500Surface *)(surface))->copy_buffer_from_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            else {
              loaded = VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x528)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),boundTexture);
              if (loaded != 0) {
                this->load_texture((VendorTextureBuffer *)(boundTexture));
              }
            }
            M<UInt8>(M<SInt32>(boundTexture + 0x14) + 0x14) = 0;
          }
          if (slot < 0x10) {
            written = this->WriteTextureOffset(slot,(UInt32 *)(record),wordCount,(VendorTextureBuffer *)(boundTexture));
            wordCount = wordCount + written;
          }
        }
        more = slot != 0x29;
        slotCursor = slotCursor + 4;
        slot = slot + 1;
      } while (more);
      vertexWords = this->WriteVertexArrayOffset((UInt32 *)(record),wordCount);
      totalWords = vertexWords + wordCount;
      paddedWords = totalWords;
      if ((totalWords & 1) != 0) {
        paddedWords = totalWords + 1;
        record[totalWords] = 0x80000000;
      }
      if (M<SInt32>(self + ringIndex * 0x18 + 0x110) == 0) {
        ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + ringIndex * 0x18 + 0x10c)));
      }
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) = paddedWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
      stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)(record),
                         M<SInt32>(self + ringIndex * 0x18 + 0x110) + 0x20,paddedWords);
      M<UInt32>(self + ringIndex * 0x18 + 0x11c) = stamp;
      if (textureBytes[0x20] == 0x0) {
        surface = M<UInt8 *>(textureBytes + 0x50);
        maskIndex = ((IOATIR500Surface *)(surface))->surface_buffer_idx_mask(M<UInt32>(textureBytes + 0x58),(UInt32 *)(bufferMask));
        surfaceBuffer = M<UInt8 *>(surface + maskIndex * 4 + 0xb70);
        ready = VCALL(M<SInt32>(surface), 0x5d0)(surface,surfaceBuffer);
        if ((ready != 0) &&
           (copied = ((IOATIR500Surface *)(surface))->copy_buffer_from_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer)), copied != 0))
        {
          return 1;
        }
        result = 0;
      }
      else {
        result = VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x528)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),textureBytes);
      }
      return result;
    }
  } while( true );
}
