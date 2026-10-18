/*
 * ATIR5002DContext_process_command_buffer_Port.cpp
 *
 * ATIR5002DContext::process_command_buffer (real addr 0x326d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x326d0 */
IOReturn ATIR5002DContext::process_command_buffer(VendorCommandDescriptor *descriptor) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *descriptorBytes = reinterpret_cast<UInt8 *>(descriptor);

  UInt8 bVar1;
  UInt8 bVar2;
  UInt16 uVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt8 *texture;
  UInt32 stamp;
  UInt8 *surface;
  SInt32 iVar11;
  SInt32 iVar12;
  UInt32 result;
  SInt32 streamOffset;
  UInt32 pendingWords;
  UInt32 submitWords;
  UInt32 header;
  UInt32 *recordCursor;
  UInt8 *bindTexture;
  
  result = 0;
  streamOffset = 0;
  pendingWords = 0xffffffff;
  recordCursor = (UInt32 *)(M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader) + 0x1c);
  do {
    header = *recordCursor;
    uVar6 = header & 0xff000000;
    if (uVar6 == 0xa000000) {
LAB_00032d30:
      uVar7 = recordCursor[1];
      if (M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0xcc) <= uVar7) {
        uVar7 = 0;
      }
      iVar12 = uVar7 * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
      if (uVar6 != 0x9000000) {
LAB_00032f30:
        *recordCursor = 0x1150;
        uVar6 = M<UInt32>(iVar12 + 8);
        bVar1 = M<UInt8>(iVar12 + 0x38);
LAB_00032f3c:
        recordCursor[1] = uVar6 & 0xffffffe0 | (bVar1 & 1) << 2 | (bVar1 & 6) << 2;
        goto LAB_00032f54;
      }
LAB_00032ee0:
      *recordCursor = 0x80000000;
      recordCursor[1] = 0x575;
      bVar1 = M<UInt8>(iVar12 + 0x38);
      uVar3 = M<UInt16>(iVar12 + 0x18);
      uVar6 = M<UInt32>(iVar12 + 8);
LAB_00032ef4:
      uVar7 = 0x80000000;
      if (bVar1 < 2) {
        uVar7 = 0;
      }
      recordCursor[5] = uVar7 | uVar6 >> 10 | (uVar3 & 0x3fc0) << 0x10 | (bVar1 & 1) << 0x1e;
      header = header & 0xffffff;
    }
    else if (uVar6 < 0xa000001) {
      if (uVar6 == 0x5000000) {
        if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
          M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
        }
        *recordCursor = 0x80000000;
        goto LAB_00032f54;
      }
      if (uVar6 < 0x5000001) {
        if ((uVar6 == 0x3000000) || (uVar6 == 0x4000000)) {
          if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
            M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
                 M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
            M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
          }
          if ((M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x14) <= recordCursor[1]) ||
             (texture = *(UInt8 **)
                        (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x10)),
             texture == (UInt8 *)0x0)) goto LAB_00033420;
          if (M<char>(M<SInt32>(texture + 0x14) + 0x14) != '\0') {
            submitWords = pendingWords;
            if (pendingWords != 0) {
              submitWords = 0;
              M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
              iVar12 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
              iVar11 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
              streamOffset = streamOffset + pendingWords * 4;
              stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                  iVar11 + 0x20,pendingWords);
              M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
            }
            this->alloc_and_load_image((VendorTextureBuffer *)(texture));
            pendingWords = submitWords;
            if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
              ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
            }
          }
          if (M<SInt32>(texture + 0x48) != 0) {
            M<UInt32>(M<SInt32>(texture + 0x24) + 0x28) = M<UInt32>(texture + 0x28);
            M<UInt32>(M<SInt32>(texture + 0x28) + 0x24) = M<UInt32>(texture + 0x24);
            M<UInt32>(texture + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x600);
            M<SInt32>(texture + 0x28) = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x5dc;
            M<UInt8 *>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x600) = texture;
            M<UInt8 *>(M<SInt32>(texture + 0x24) + 0x28) = texture;
          }
          if (M<SInt32>(texture + 4) != 0) {
            GH_IOGetTime(texture + 0x2c);
            M<UInt32>(M<SInt32>(texture + 0x34) + 0x38) = M<UInt32>(texture + 0x38);
            M<UInt32>(M<SInt32>(texture + 0x38) + 0x34) = M<UInt32>(texture + 0x34);
            M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0);
            M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0) = texture;
            M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
          }
          uVar7 = M<UInt32>(texture + 0x48);
          if (uVar6 == 0x4000000) {
            *recordCursor = 0x1150;
            recordCursor[1] = -(M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) >> 3 & 3) >> 0x1c & 8 |
                         uVar7 & 0xffffffe0 | M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 4;
          }
          else {
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x575;
            recordCursor[5] = uVar7 >> 10 | (recordCursor[5] & 0x3fc0) << 0x10;
          }
          header = header & 0xffffff;
          M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture) = texture;
        }
        else {
          if (uVar6 != 0x2000000) goto LAB_00032f54;
          *recordCursor = 0x80000000;
          result = 1;
          header = header & 0xffffff;
        }
        goto LAB_00033430;
      }
      if (uVar6 == 0x7000000) {
LAB_00032a78:
        M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) | 1;
        if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
          M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
        }
        if ((M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x14) <= recordCursor[1]) ||
           (bindTexture = *(UInt8 **)
                        (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x10)),
           bindTexture == (UInt8 *)0x0)) goto LAB_00033420;
        if (M<char>(M<SInt32>(bindTexture + 0x14) + 0x14) == '\0') {
          if (M<SInt32>(bindTexture + 4) != 0) {
            GH_IOGetTime(bindTexture + 0x2c);
            M<UInt32>(M<SInt32>(bindTexture + 0x34) + 0x38) = M<UInt32>(bindTexture + 0x38);
            M<UInt32>(M<SInt32>(bindTexture + 0x38) + 0x34) = M<UInt32>(bindTexture + 0x34);
            M<UInt32>(bindTexture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0);
            M<SInt32>(bindTexture + 0x38) = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0) = bindTexture;
            M<UInt8 *>(M<SInt32>(bindTexture + 0x34) + 0x38) = bindTexture;
          }
        }
        else {
          submitWords = pendingWords;
          if (pendingWords != 0) {
            submitWords = 0;
            M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
                 pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
            iVar12 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
            iVar11 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
            streamOffset = streamOffset + pendingWords * 4;
            stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                iVar11 + 0x20,pendingWords);
            M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(bindTexture));
          pendingWords = submitWords;
          if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
          }
        }
        iVar12 = M<SInt32>(self + kIOATIR5002DContext_accelerator);
        uVar7 = M<SInt32>(bindTexture + 4) + M<SInt32>(iVar12 + 0x8a4);
        if (uVar6 == 0x7000000) {
          *recordCursor = 0x80000000;
          recordCursor[1] = 0x575;
          recordCursor[5] = uVar7 >> 10 | (recordCursor[5] & 0x3fc0) << 0x10;
        }
        else {
          uVar6 = recordCursor[2];
          if ((recordCursor[4] == 0) || (recordCursor[5] == 0)) {
            iVar11 = M<SInt32>(bindTexture + 0x14);
          }
          else {
            iVar11 = M<SInt32>(bindTexture + 0x14);
            iVar4 = (recordCursor[4] & 0xff) * 0x1c;
            if ((M<UInt8>(iVar11 + 0x15) & 0x18) == 0) {
              uVar8 = FormatTableLookup_0x0004d2dc(iVar4);
              iVar4 = 0;
            }
            else {
              uVar8 = FormatTableLookup_0x0004d2dc(iVar4);
              iVar4 = -(uVar8 >> 8 & 3);
            }
            iVar5 = (SInt32)recordCursor[5] >> ((iVar4 - (uVar8 >> 0xc & 7)) + 5 & 0x3f);
            iVar4 = iVar5 << 5;
            if ((M<UInt8>(iVar11 + 0x15) >> 2 & 1) != 0) {
              iVar4 = (iVar5 << 0xc) >> 3;
            }
            uVar7 = uVar7 + iVar4;
          }
          if (recordCursor[3] != 0) {
            uVar7 = uVar7 + recordCursor[3];
          }
          *recordCursor = 0x80000000;
          recordCursor[1] = 0x80000000;
          recordCursor[2] = 0x80000000;
          recordCursor[3] = 0x80000000;
          recordCursor[4] = 0x1150;
          recordCursor[5] = -(M<UInt8>(iVar11 + 0x15) >> 3 & 3) >> 0x1c & 8 |
                       uVar6 & 3 | uVar7 & 0xffffffe0 | M<UInt8>(iVar11 + 0x15) & 4;
        }
LAB_00033400:
        header = header & 0xffffff;
        M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture) = bindTexture;
        if (bindTexture != (UInt8 *)0x0) {
          M<UInt32>(M<SInt32>(bindTexture + 0x14) + 8) = M<UInt32>(iVar12 + 0x50);
        }
      }
      else {
        if (uVar6 < 0x7000001) {
          if (uVar6 == 0x6000000) {
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordCursor[2] = 0x80000000;
            recordCursor[3] = 0x80000000;
            recordCursor[4] = 0x80000000;
            recordCursor[5] = 0x80000000;
            recordCursor[6] = 0x80000000;
            recordCursor[7] = 0x80000000;
            header = header & 0xffffff;
            goto LAB_00033430;
          }
        }
        else {
          if (uVar6 == 0x8000000) goto LAB_00032a78;
          if (uVar6 == 0x9000000) goto LAB_00032d30;
        }
LAB_00032f54:
        header = header & 0xffffff;
      }
    }
    else {
      if (uVar6 == 0xe000000) {
LAB_00032ea0:
        if (M<SInt32>(self + kIOATIR5002DContext_boundSurface) == 0) {
          iVar12 = M<SInt32>(self + kIOATIR5002DContext_panelIndex) * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
        }
        else {
          iVar12 = M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_boundSurface) + 0xb70);
        }
        if (uVar6 != 0xd000000) goto LAB_00032f30;
        goto LAB_00032ee0;
      }
      if (uVar6 < 0xe000001) {
        if (uVar6 != 0xc000000) {
          if (uVar6 == 0xd000000) goto LAB_00032ea0;
          if (uVar6 != 0xb000000) goto LAB_00032f54;
        }
        surface = (UInt8 *)
                  ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->find_surface_for_id(recordCursor[1]);
        submitWords = pendingWords;
        if (surface == (UInt8 *)0x0) {
LAB_00032e64:
          iVar12 = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
          pendingWords = submitWords;
        }
        else {
          uVar7 = M<UInt32>(surface + 0xbf8);
          if ((uVar7 & 0x20000000) == 0) {
            uVar8 = M<UInt32>(surface + 0xc18);
            if ((uVar7 & uVar8 & 3) != 0) {
              if (pendingWords != 0) {
                submitWords = 0;
                M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
                     pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
                iVar12 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
                iVar11 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
                streamOffset = streamOffset + pendingWords * 4;
                stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                    iVar11 + 0x20,pendingWords);
                M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
                uVar7 = M<UInt32>(surface + 0xbf8);
                uVar8 = M<UInt32>(surface + 0xc18);
              }
              if ((uVar8 & uVar7 & 1) != 0) {
                ((IOATIR500Surface *)(surface))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR5002DContext_boundSurface)),(VendorTextureBuffer **)((UInt8 **)0x0),
                           0,1);
                uVar7 = M<UInt32>(surface + 0xbf8);
                uVar8 = M<UInt32>(surface + 0xc18);
              }
              if ((uVar8 & uVar7 & 2) != 0) {
                ((IOATIR500Surface *)(surface))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR5002DContext_boundSurface)),(VendorTextureBuffer **)((UInt8 **)0x0),
                           0,2);
              }
              if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
                ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
              }
            }
            iVar12 = M<SInt32>(surface + 0xb70);
            pendingWords = submitWords;
            if (M<SInt32>(iVar12 + 8) == 0) goto LAB_00032e64;
          }
          else {
            iVar12 = M<SInt32>(surface + 0xb70);
          }
        }
        if (uVar6 != 0xb000000) {
          *recordCursor = 0x1150;
          uVar6 = M<UInt32>(iVar12 + 8);
          bVar1 = M<UInt8>(iVar12 + 0x38);
          goto LAB_00032f3c;
        }
        *recordCursor = 0x80000000;
        recordCursor[1] = 0x575;
        bVar1 = M<UInt8>(iVar12 + 0x38);
        uVar3 = M<UInt16>(iVar12 + 0x18);
        uVar6 = M<UInt32>(iVar12 + 8);
        goto LAB_00032ef4;
      }
      if (uVar6 == 0x11000000) {
        iVar12 = recordCursor[1] * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator);
        *recordCursor = 0x138a;
        recordCursor[1] = M<UInt32>(iVar12 + 0x134) & 0xffffffe0;
        recordCursor[2] = 0x138e;
        bVar1 = M<UInt8>(iVar12 + 0x165);
        bVar2 = M<UInt8>(iVar12 + 0x167);
        uVar6 = M<UInt16>(iVar12 + 0x140) & 0x3ffe | (M<UInt8>(iVar12 + 0x164) & 1) << 0x10 |
                (M<UInt8>(iVar12 + 0x164) & 6) << 0x10;
LAB_0003323c:
        recordCursor[3] = uVar6 | (bVar1 & 3) << 0x13 | (bVar2 & 0xf) << 0x15;
        goto LAB_00032f54;
      }
      if (0x11000000 < uVar6) {
        if (uVar6 == 0x12000000) {
          if (M<SInt32>(self + kIOATIR5002DContext_boundSurface) == 0) {
            iVar12 = M<SInt32>(self + kIOATIR5002DContext_panelIndex) * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
          }
          else {
            iVar12 = M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_boundSurface) + 0xb70);
          }
          *recordCursor = 0x138a;
          recordCursor[1] = M<UInt32>(iVar12 + 8) & 0xffffffe0;
          recordCursor[2] = 0x138e;
          bVar1 = M<UInt8>(iVar12 + 0x39);
          bVar2 = M<UInt8>(iVar12 + 0x3b);
          uVar6 = M<UInt16>(iVar12 + 0x14) & 0x3ffe | (M<UInt8>(iVar12 + 0x38) & 1) << 0x10 |
                  (M<UInt8>(iVar12 + 0x38) & 6) << 0x10;
          goto LAB_0003323c;
        }
        if (uVar6 != 0x13000000) goto LAB_00032f54;
        M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) | 1;
        if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
          M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
        }
        if ((M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x14) <= recordCursor[1]) ||
           (bindTexture = *(UInt8 **)
                        (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x10)),
           bindTexture == (UInt8 *)0x0)) goto LAB_00033420;
        if (M<char>(M<SInt32>(bindTexture + 0x14) + 0x14) == '\0') {
          if (M<SInt32>(bindTexture + 4) != 0) {
            GH_IOGetTime(bindTexture + 0x2c);
            M<UInt32>(M<SInt32>(bindTexture + 0x34) + 0x38) = M<UInt32>(bindTexture + 0x38);
            M<UInt32>(M<SInt32>(bindTexture + 0x38) + 0x34) = M<UInt32>(bindTexture + 0x34);
            M<UInt32>(bindTexture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0);
            M<SInt32>(bindTexture + 0x38) = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0) = bindTexture;
            M<UInt8 *>(M<SInt32>(bindTexture + 0x34) + 0x38) = bindTexture;
          }
        }
        else {
          submitWords = pendingWords;
          if (pendingWords != 0) {
            submitWords = 0;
            M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
                 pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
            iVar12 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
            iVar11 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
            streamOffset = streamOffset + pendingWords * 4;
            stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                iVar11 + 0x20,pendingWords);
            M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(bindTexture));
          pendingWords = submitWords;
          if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
          }
        }
        uVar6 = recordCursor[2];
        *recordCursor = 0x80000000;
        recordCursor[1] = 0x80000000;
        recordCursor[2] = 0x1151;
        iVar12 = M<SInt32>(self + kIOATIR5002DContext_accelerator);
        recordCursor[3] = -(M<UInt8>(M<SInt32>(bindTexture + 0x14) + 0x15) >> 3 & 3) >> 0x1c & 8 |
                     uVar6 & 3 | M<SInt32>(bindTexture + 4) + M<SInt32>(iVar12 + 0x8a4) & 0xffffffe0U |
                     M<UInt8>(M<SInt32>(bindTexture + 0x14) + 0x15) & 4;
        goto LAB_00033400;
      }
      if (uVar6 != 0x10000000) goto LAB_00032f54;
      M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) | 1;
      uVar6 = recordCursor[2];
      uVar7 = recordCursor[3];
      if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
        M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
             M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
        M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
      }
      if ((recordCursor[1] < M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x14)) &&
         (texture = *(UInt8 **)
                    (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x10)),
         texture != (UInt8 *)0x0)) {
        if (M<char>(M<SInt32>(texture + 0x14) + 0x14) == '\0') {
          if (M<SInt32>(texture + 4) != 0) {
            GH_IOGetTime(texture + 0x2c);
            M<UInt32>(M<SInt32>(texture + 0x34) + 0x38) = M<UInt32>(texture + 0x38);
            M<UInt32>(M<SInt32>(texture + 0x38) + 0x34) = M<UInt32>(texture + 0x34);
            M<UInt32>(texture + 0x34) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0);
            M<SInt32>(texture + 0x38) = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x6d0) = texture;
            M<UInt8 *>(M<SInt32>(texture + 0x34) + 0x38) = texture;
          }
        }
        else {
          submitWords = pendingWords;
          if (pendingWords != 0) {
            submitWords = 0;
            M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
                 pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
            iVar12 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
            iVar11 = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
            streamOffset = streamOffset + pendingWords * 4;
            stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                iVar11 + 0x20,pendingWords);
            M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(texture));
          pendingWords = submitWords;
          if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
          }
        }
        *recordCursor = 0x138a;
        recordCursor[1] = M<UInt32>(texture + 0x48) & 0xffffffe0;
        recordCursor[2] = 0x138e;
        recordCursor[3] = -(M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) >> 3 & 3) >> 0xe & 0x20000 |
                     uVar6 & 0x3ffe | (M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 4) << 0xe |
                     (uVar7 & 0xf) << 0x15;
        header = header & 0xffffff;
        M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture) = texture;
        if (texture != (UInt8 *)0x0) {
          M<UInt32>(M<SInt32>(texture + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
        }
        goto LAB_00033430;
      }
LAB_00033420:
      pendingWords = 0;
      header = 0;
    }
LAB_00033430:
    pendingWords = pendingWords + header;
    recordCursor = recordCursor + header;
    if (header == 0) {
      if ((pendingWords & 1) != 0) {
        *recordCursor = 0x80000000;
        pendingWords = pendingWords + 1;
        recordCursor = recordCursor + 1;
      }
      M<SInt32>(descriptorBytes) = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader) + 0x20;
      iVar12 = M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
      M<UInt32 *>(descriptorBytes + 0xc) = recordCursor;
      M<UInt32>(descriptorBytes + 8) = pendingWords;
      M<SInt32>(descriptorBytes + 4) = streamOffset + iVar12 + 0x20;
      return result;
    }
  } while( true );
}
