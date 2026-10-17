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
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 *record;
  UInt8 *slotCursor;
  UInt32 wordCount;
  UInt32 uVar10;
  SInt32 *accelerator;
  UInt32 uVar12;
  SInt32 iVar13;
  UInt8 *surfaceBuffer;
  UInt8 *surface;
  UInt8 *boundTexture;
  UInt32 totalWords;
  UInt32 bufferMask [7];
  
  iVar6 = 0;
  slotCursor = self;
  do {
    iVar13 = M<SInt32>(slotCursor + 0x2a4);
    if (iVar13 != 0) {
      if (M<SInt32>(iVar13 + 0x48) == 0) {
        if (M<char>(iVar13 + 0x20) != '\0') goto LAB_00029f5c;
        surface = M<UInt8 *>(iVar13 + 0x50);
        uVar12 = 0;
        surfaceBuffer = (UInt8 *)(surface + 0xa8);
        do {
          if ((((M<SInt32>(surface + 0xc14) == 0xffff) || ((1 < uVar12 && (1 < uVar12 - 4)))) &&
              (M<SInt32>(surfaceBuffer + 8) != 0)) &&
             (((M<UInt32>(surface + 0xbd0) & 0xffff0000) == 0 ||
              (surfaceBuffer != M<UInt8 *>(surface + 0xb70))))) {
            if (M<SInt32>(surface + 0xd48) == 0) {
              ((IOATIR500Surface *)(surface))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            else {
              VCALL(M<SInt32>(surface), 0x5cc)(surface,iVar6);
            }
          }
          more = uVar12 != 0x16;
          surfaceBuffer = surfaceBuffer + 0x78;
          uVar12 = uVar12 + 1;
        } while (more);
        VCALL(M<SInt32>(surface), 0x5c4)(surface);
      }
      else {
        VCALL(*M<SInt32 *>(self + 200), 0x524)(M<SInt32 *>(self + 200),iVar13);
      }
      M<UInt8>(M<SInt32>(iVar13 + 0x14) + 0x14) = 1;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x28) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x2a) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x2c) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x2e) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x30) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x32) = 0;
      iVar5 = M<SInt32>(iVar13 + 0x24);
      M<UInt32>(iVar5 + 0x28) = M<UInt32>(iVar13 + 0x28);
      iVar3 = M<SInt32>(iVar13 + 0x28);
      M<SInt32>(iVar13 + 0x28) = iVar13;
      M<SInt32>(iVar3 + 0x24) = iVar5;
      M<SInt32>(iVar13 + 0x24) = iVar13;
    }
LAB_00029f5c:
    more = iVar6 == 0x29;
    slotCursor = slotCursor + 4;
    iVar6 = iVar6 + 1;
    if (more) {
      if (textureBytes[0x20] == 0x0) {
        surface = M<UInt8 *>(textureBytes + 0x50);
        uVar12 = 0;
        surfaceBuffer = (UInt8 *)(surface + 0xa8);
        do {
          if (((M<SInt32>(surface + 0xc14) == 0xffff) || ((1 < uVar12 && (1 < uVar12 - 4)))) &&
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
          more = uVar12 != 0x16;
          surfaceBuffer = surfaceBuffer + 0x78;
          uVar12 = uVar12 + 1;
        } while (more);
        VCALL(M<SInt32>(surface), 0x5c4)(surface);
        M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x14) = 1;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x28) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2a) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2c) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x2e) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x30) = 0;
        M<UInt16>(M<SInt32>(textureBytes + 0x14) + 0x32) = 0;
        iVar13 = M<SInt32>(textureBytes + 0x24);
        M<UInt32>(iVar13 + 0x28) = M<UInt32>(textureBytes + 0x28);
        iVar6 = M<SInt32>(textureBytes + 0x28);
        M<UInt8 *>(textureBytes + 0x28) = textureBytes;
        M<SInt32>(iVar6 + 0x24) = iVar13;
        M<UInt8 *>(textureBytes + 0x24) = textureBytes;
      }
      uVar10 = 0;
      wordCount = 0;
      VCALL(M<SInt32>(self), 0x5a4)(self);
      accelerator = M<SInt32 *>(self + 200);
      uVar12 = M<SInt32>(self + 0x28c) + 1U & 0xf;
      M<UInt32>(self + 0x28c) = uVar12;
      iVar13 = accelerator[0x1e0];
      iVar6 = VCALL(*accelerator, 0x54c)(accelerator,M<UInt32>(self + uVar12 * 0x18 + 0x11c))
      ;
      accelerator[0x1e0] = iVar13 + iVar6;
      record = (UInt32 *)(M<SInt32>(self + uVar12 * 0x18 + 0x120) + 0x20);
      slotCursor = self;
      do {
        boundTexture = M<UInt8 *>(slotCursor + 0x2a4);
        if ((boundTexture != (UInt8 *)0x0) &&
           (((type = boundTexture[0x20], type == 0x3 ||
             (type == 0x0)) || (type == 0x7)))) {
          if (M<SInt32>(boundTexture + 0x48) == 0) {
            if (type == 0x0) {
              surface = M<UInt8 *>(boundTexture + 0x50);
              iVar6 = ((IOATIR500Surface *)(surface))->surface_buffer_idx_mask(M<UInt32>(boundTexture + 0x58),(UInt32 *)(bufferMask));
              surfaceBuffer = M<UInt8 *>(surface + iVar6 * 4 + 0xb70);
              VCALL(M<SInt32>(surface), 0x5d0)(surface,surfaceBuffer);
              ((IOATIR500Surface *)(surface))->copy_buffer_from_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            else {
              iVar6 = VCALL(*M<SInt32 *>(self + 200), 0x528)(M<SInt32 *>(self + 200),boundTexture);
              if (iVar6 != 0) {
                this->load_texture((VendorTextureBuffer *)(boundTexture));
              }
            }
            M<UInt8>(M<SInt32>(boundTexture + 0x14) + 0x14) = 0;
          }
          if (uVar10 < 0x10) {
            iVar6 = this->WriteTextureOffset(uVar10,(UInt32 *)(record),wordCount,(VendorTextureBuffer *)(boundTexture));
            wordCount = wordCount + iVar6;
          }
        }
        more = uVar10 != 0x29;
        slotCursor = slotCursor + 4;
        uVar10 = uVar10 + 1;
      } while (more);
      iVar6 = this->WriteVertexArrayOffset((UInt32 *)(record),wordCount);
      totalWords = iVar6 + wordCount;
      uVar10 = totalWords;
      if ((totalWords & 1) != 0) {
        uVar10 = totalWords + 1;
        record[totalWords] = 0x80000000;
      }
      if (M<SInt32>(self + uVar12 * 0x18 + 0x110) == 0) {
        ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + uVar12 * 0x18 + 0x10c)));
      }
      M<UInt32>(M<SInt32>(self + 200) + 0x704) = uVar10 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
      M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
      uVar4 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)(record),
                         M<SInt32>(self + uVar12 * 0x18 + 0x110) + 0x20,uVar10);
      M<UInt32>(self + uVar12 * 0x18 + 0x11c) = uVar4;
      if (textureBytes[0x20] == 0x0) {
        surface = M<UInt8 *>(textureBytes + 0x50);
        iVar6 = ((IOATIR500Surface *)(surface))->surface_buffer_idx_mask(M<UInt32>(textureBytes + 0x58),(UInt32 *)(bufferMask));
        surfaceBuffer = M<UInt8 *>(surface + iVar6 * 4 + 0xb70);
        iVar6 = VCALL(M<SInt32>(surface), 0x5d0)(surface,surfaceBuffer);
        if ((iVar6 != 0) &&
           (iVar6 = ((IOATIR500Surface *)(surface))->copy_buffer_from_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer)), iVar6 != 0))
        {
          return 1;
        }
        uVar4 = 0;
      }
      else {
        uVar4 = VCALL(*M<SInt32 *>(self + 200), 0x528)(M<SInt32 *>(self + 200),textureBytes);
      }
      return uVar4;
    }
  } while( true );
}
