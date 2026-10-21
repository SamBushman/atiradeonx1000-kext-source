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

  UInt16 pitchBytes;
  SInt32 tileUnits;
  UInt8 *texture;
  UInt32 stamp;
  UInt8 *surface;
  UInt32 result;
  SInt32 streamOffset;
  UInt32 pendingWords;
  UInt32 submitWords;
  UInt32 header;
  UInt32 *recordCursor;
  UInt8 *bindTexture;
  SInt32 submitHeaderAddress;
  SInt32 gartOffset;
  SInt32 bufferEntryBase;
  SInt32 surfaceBuffer;
  UInt8 tilingConfigByte1;
  UInt8 formatSubShift;
  UInt32 pitchTilingWord;
  SInt32 accel;
  UInt32 textureAddress;
  SInt32 textureInfo;
  UInt32 recordWord2;
  UInt32 formatEntry;
  UInt32 recordWord3;
  UInt32 bufferIndex;
  UInt32 bufferGpuAddress;
  UInt32 tilingEnableBit;
  UInt32 stateBits;
  UInt32 contextReqBits;
  SInt32 formatTableOffset;
  SInt32 subsampleShift;
  SInt32 tileOffset;
  UInt8 tilingByte;
  SInt32 submitGartAddress;
  UInt32 opcode;
  
  result = 0;
  streamOffset = 0;
  pendingWords = 0xffffffff;
  recordCursor = (UInt32 *)(M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader) + 0x1c);
  do {
    header = *recordCursor;
    opcode = header & 0xff000000;
    if (opcode == 0xa000000) {
lookupBufferEntry:
      bufferIndex = recordCursor[1];
      if (M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0xcc) <= bufferIndex) {
        bufferIndex = 0;
      }
      surfaceBuffer = bufferIndex * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
      if (opcode != 0x9000000) {
emitOffsetRegisterRecord:
        *recordCursor = 0x1150;
        bufferGpuAddress = M<UInt32>(surfaceBuffer + 8);
        tilingByte = M<UInt8>(surfaceBuffer + 0x38);
storeOffsetWord:
        recordCursor[1] = bufferGpuAddress & 0xffffffe0 | (tilingByte & 1) << 2 | (tilingByte & 6) << 2;
        goto finishRecord;
      }
emitTiledPacketRecord:
      *recordCursor = 0x80000000;
      recordCursor[1] = 0x575;
      tilingByte = M<UInt8>(surfaceBuffer + 0x38);
      pitchBytes = M<UInt16>(surfaceBuffer + 0x18);
      bufferGpuAddress = M<UInt32>(surfaceBuffer + 8);
storeTiledPitchWord:
      tilingEnableBit = 0x80000000;
      if (tilingByte < 2) {
        tilingEnableBit = 0;
      }
      recordCursor[5] = tilingEnableBit | bufferGpuAddress >> 10 | (pitchBytes & 0x3fc0) << 0x10 | (tilingByte & 1) << 0x1e;
      header = header & 0xffffff;
    }
    else if (opcode < 0xa000001) {
      if (opcode == 0x5000000) {
        if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
          M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
        }
        *recordCursor = 0x80000000;
        goto finishRecord;
      }
      if (opcode < 0x5000001) {
        if ((opcode == 0x3000000) || (opcode == 0x4000000)) {
          if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
            M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
                 M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
            M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
          }
          if ((M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x14) <= recordCursor[1]) ||
             (texture = *(UInt8 **)
                        (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x10)),
             texture == (UInt8 *)0x0)) goto abortStream;
          if (M<char>(M<SInt32>(texture + 0x14) + 0x14) != '\0') {
            submitWords = pendingWords;
            if (pendingWords != 0) {
              submitWords = 0;
              M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
              submitHeaderAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
              submitGartAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
              streamOffset = streamOffset + pendingWords * 4;
              stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(submitHeaderAddress + 0x20),
                                  submitGartAddress + 0x20,pendingWords);
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
          textureAddress = M<UInt32>(texture + 0x48);
          if (opcode == 0x4000000) {
            *recordCursor = 0x1150;
            recordCursor[1] = -(M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) >> 3 & 3) >> 0x1c & 8 |
                         textureAddress & 0xffffffe0 | M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 4;
          }
          else {
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x575;
            recordCursor[5] = textureAddress >> 10 | (recordCursor[5] & 0x3fc0) << 0x10;
          }
          header = header & 0xffffff;
          M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture) = texture;
        }
        else {
          if (opcode != 0x2000000) goto finishRecord;
          *recordCursor = 0x80000000;
          result = 1;
          header = header & 0xffffff;
        }
        goto advanceRecord;
      }
      if (opcode == 0x7000000) {
bindTextureRecord:
        M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) | 1;
        if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
          M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
        }
        if ((M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x14) <= recordCursor[1]) ||
           (bindTexture = *(UInt8 **)
                        (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x10)),
           bindTexture == (UInt8 *)0x0)) goto abortStream;
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
            submitHeaderAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
            submitGartAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
            streamOffset = streamOffset + pendingWords * 4;
            stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(submitHeaderAddress + 0x20),
                                submitGartAddress + 0x20,pendingWords);
            M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(bindTexture));
          pendingWords = submitWords;
          if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
          }
        }
        accel = M<SInt32>(self + kIOATIR5002DContext_accelerator);
        textureAddress = M<SInt32>(bindTexture + 4) + M<SInt32>(accel + kIOATIR500Accelerator_vramSizeProgrammed);
        if (opcode == 0x7000000) {
          *recordCursor = 0x80000000;
          recordCursor[1] = 0x575;
          recordCursor[5] = textureAddress >> 10 | (recordCursor[5] & 0x3fc0) << 0x10;
        }
        else {
          recordWord2 = recordCursor[2];
          if ((recordCursor[4] == 0) || (recordCursor[5] == 0)) {
            textureInfo = M<SInt32>(bindTexture + 0x14);
          }
          else {
            textureInfo = M<SInt32>(bindTexture + 0x14);
            formatTableOffset = (recordCursor[4] & 0xff) * 0x1c;
            if ((M<UInt8>(textureInfo + 0x15) & 0x18) == 0) {
              formatEntry = FormatTableLookup_0x0004d2dc(formatTableOffset);
              subsampleShift = 0;
            }
            else {
              formatEntry = FormatTableLookup_0x0004d2dc(formatTableOffset);
              subsampleShift = -(formatEntry >> 8 & 3);
            }
            tileUnits = (SInt32)recordCursor[5] >> ((subsampleShift - (formatEntry >> 0xc & 7)) + 5 & 0x3f);
            tileOffset = tileUnits << 5;
            if ((M<UInt8>(textureInfo + 0x15) >> 2 & 1) != 0) {
              tileOffset = (tileUnits << 0xc) >> 3;
            }
            textureAddress = textureAddress + tileOffset;
          }
          if (recordCursor[3] != 0) {
            textureAddress = textureAddress + recordCursor[3];
          }
          *recordCursor = 0x80000000;
          recordCursor[1] = 0x80000000;
          recordCursor[2] = 0x80000000;
          recordCursor[3] = 0x80000000;
          recordCursor[4] = 0x1150;
          recordCursor[5] = -(M<UInt8>(textureInfo + 0x15) >> 3 & 3) >> 0x1c & 8 |
                       recordWord2 & 3 | textureAddress & 0xffffffe0 | M<UInt8>(textureInfo + 0x15) & 4;
        }
recordLastBoundTexture:
        header = header & 0xffffff;
        M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture) = bindTexture;
        if (bindTexture != (UInt8 *)0x0) {
          M<UInt32>(M<SInt32>(bindTexture + 0x14) + 8) = M<UInt32>(accel + kIOATIR500Accelerator_submitStamp);
        }
      }
      else {
        if (opcode < 0x7000001) {
          if (opcode == 0x6000000) {
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordCursor[2] = 0x80000000;
            recordCursor[3] = 0x80000000;
            recordCursor[4] = 0x80000000;
            recordCursor[5] = 0x80000000;
            recordCursor[6] = 0x80000000;
            recordCursor[7] = 0x80000000;
            header = header & 0xffffff;
            goto advanceRecord;
          }
        }
        else {
          if (opcode == 0x8000000) goto bindTextureRecord;
          if (opcode == 0x9000000) goto lookupBufferEntry;
        }
finishRecord:
        header = header & 0xffffff;
      }
    }
    else {
      if (opcode == 0xe000000) {
selectCurrentSurface:
        if (M<SInt32>(self + kIOATIR5002DContext_boundSurface) == 0) {
          surfaceBuffer = M<SInt32>(self + kIOATIR5002DContext_panelIndex) * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
        }
        else {
          surfaceBuffer = M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_boundSurface) + 0xb70);
        }
        if (opcode != 0xd000000) goto emitOffsetRegisterRecord;
        goto emitTiledPacketRecord;
      }
      if (opcode < 0xe000001) {
        if (opcode != 0xc000000) {
          if (opcode == 0xd000000) goto selectCurrentSurface;
          if (opcode != 0xb000000) goto finishRecord;
        }
        surface = (UInt8 *)
                  ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->find_surface_for_id(recordCursor[1]);
        submitWords = pendingWords;
        if (surface == (UInt8 *)0x0) {
useDefaultSurfaceBuffer:
          surfaceBuffer = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
          pendingWords = submitWords;
        }
        else {
          stateBits = M<UInt32>(surface + 0xbf8);
          if ((stateBits & 0x20000000) == 0) {
            contextReqBits = M<UInt32>(surface + 0xc18);
            if ((stateBits & contextReqBits & 3) != 0) {
              if (pendingWords != 0) {
                submitWords = 0;
                M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
                     pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
                submitHeaderAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
                submitGartAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
                streamOffset = streamOffset + pendingWords * 4;
                stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(submitHeaderAddress + 0x20),
                                    submitGartAddress + 0x20,pendingWords);
                M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
                stateBits = M<UInt32>(surface + 0xbf8);
                contextReqBits = M<UInt32>(surface + 0xc18);
              }
              if ((contextReqBits & stateBits & 1) != 0) {
                ((IOATIR500Surface *)(surface))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR5002DContext_boundSurface)),(VendorTextureBuffer **)((UInt8 **)0x0),
                           0,1);
                stateBits = M<UInt32>(surface + 0xbf8);
                contextReqBits = M<UInt32>(surface + 0xc18);
              }
              if ((contextReqBits & stateBits & 2) != 0) {
                ((IOATIR500Surface *)(surface))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR5002DContext_boundSurface)),(VendorTextureBuffer **)((UInt8 **)0x0),
                           0,2);
              }
              if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
                ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
              }
            }
            surfaceBuffer = M<SInt32>(surface + 0xb70);
            pendingWords = submitWords;
            if (M<SInt32>(surfaceBuffer + 8) == 0) goto useDefaultSurfaceBuffer;
          }
          else {
            surfaceBuffer = M<SInt32>(surface + 0xb70);
          }
        }
        if (opcode != 0xb000000) {
          *recordCursor = 0x1150;
          bufferGpuAddress = M<UInt32>(surfaceBuffer + 8);
          tilingByte = M<UInt8>(surfaceBuffer + 0x38);
          goto storeOffsetWord;
        }
        *recordCursor = 0x80000000;
        recordCursor[1] = 0x575;
        tilingByte = M<UInt8>(surfaceBuffer + 0x38);
        pitchBytes = M<UInt16>(surfaceBuffer + 0x18);
        bufferGpuAddress = M<UInt32>(surfaceBuffer + 8);
        goto storeTiledPitchWord;
      }
      if (opcode == 0x11000000) {
        bufferEntryBase = recordCursor[1] * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator);
        *recordCursor = 0x138a;
        recordCursor[1] = M<UInt32>(bufferEntryBase + 0x134) & 0xffffffe0;
        recordCursor[2] = 0x138e;
        tilingConfigByte1 = M<UInt8>(bufferEntryBase + 0x165);
        formatSubShift = M<UInt8>(bufferEntryBase + 0x167);
        pitchTilingWord = M<UInt16>(bufferEntryBase + 0x140) & 0x3ffe | (M<UInt8>(bufferEntryBase + 0x164) & 1) << 0x10 |
                (M<UInt8>(bufferEntryBase + 0x164) & 6) << 0x10;
storePitchTilingRecord:
        recordCursor[3] = pitchTilingWord | (tilingConfigByte1 & 3) << 0x13 | (formatSubShift & 0xf) << 0x15;
        goto finishRecord;
      }
      if (0x11000000 < opcode) {
        if (opcode == 0x12000000) {
          if (M<SInt32>(self + kIOATIR5002DContext_boundSurface) == 0) {
            surfaceBuffer = M<SInt32>(self + kIOATIR5002DContext_panelIndex) * 0x78 + M<SInt32>(self + kIOATIR5002DContext_accelerator) + 300;
          }
          else {
            surfaceBuffer = M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_boundSurface) + 0xb70);
          }
          *recordCursor = 0x138a;
          recordCursor[1] = M<UInt32>(surfaceBuffer + 8) & 0xffffffe0;
          recordCursor[2] = 0x138e;
          tilingConfigByte1 = M<UInt8>(surfaceBuffer + 0x39);
          formatSubShift = M<UInt8>(surfaceBuffer + 0x3b);
          pitchTilingWord = M<UInt16>(surfaceBuffer + 0x14) & 0x3ffe | (M<UInt8>(surfaceBuffer + 0x38) & 1) << 0x10 |
                  (M<UInt8>(surfaceBuffer + 0x38) & 6) << 0x10;
          goto storePitchTilingRecord;
        }
        if (opcode != 0x13000000) goto finishRecord;
        M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) | 1;
        if (M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
          M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture) = 0;
        }
        if ((M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x14) <= recordCursor[1]) ||
           (bindTexture = *(UInt8 **)
                        (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_sharedAllocator) + 0x10)),
           bindTexture == (UInt8 *)0x0)) goto abortStream;
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
            submitHeaderAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
            submitGartAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
            streamOffset = streamOffset + pendingWords * 4;
            stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(submitHeaderAddress + 0x20),
                                submitGartAddress + 0x20,pendingWords);
            M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp) = stamp;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(bindTexture));
          pendingWords = submitWords;
          if (M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
          }
        }
        recordWord2 = recordCursor[2];
        *recordCursor = 0x80000000;
        recordCursor[1] = 0x80000000;
        recordCursor[2] = 0x1151;
        accel = M<SInt32>(self + kIOATIR5002DContext_accelerator);
        recordCursor[3] = -(M<UInt8>(M<SInt32>(bindTexture + 0x14) + 0x15) >> 3 & 3) >> 0x1c & 8 |
                     recordWord2 & 3 | M<SInt32>(bindTexture + 4) + M<SInt32>(accel + kIOATIR500Accelerator_vramSizeProgrammed) & 0xffffffe0U |
                     M<UInt8>(M<SInt32>(bindTexture + 0x14) + 0x15) & 4;
        goto recordLastBoundTexture;
      }
      if (opcode != 0x10000000) goto finishRecord;
      M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) | 1;
      recordWord2 = recordCursor[2];
      recordWord3 = recordCursor[3];
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
            submitHeaderAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader);
            submitGartAddress = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
            streamOffset = streamOffset + pendingWords * 4;
            stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(submitHeaderAddress + 0x20),
                                submitGartAddress + 0x20,pendingWords);
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
                     recordWord2 & 0x3ffe | (M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 4) << 0xe |
                     (recordWord3 & 0xf) << 0x15;
        header = header & 0xffffff;
        M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture) = texture;
        if (texture != (UInt8 *)0x0) {
          M<UInt32>(M<SInt32>(texture + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x50);
        }
        goto advanceRecord;
      }
abortStream:
      pendingWords = 0;
      header = 0;
    }
advanceRecord:
    pendingWords = pendingWords + header;
    recordCursor = recordCursor + header;
    if (header == 0) {
      if ((pendingWords & 1) != 0) {
        *recordCursor = 0x80000000;
        pendingWords = pendingWords + 1;
        recordCursor = recordCursor + 1;
      }
      M<SInt32>(descriptorBytes) = streamOffset + M<SInt32>(self + kIOATIR5002DContext_commandBufferHeader) + 0x20;
      gartOffset = M<SInt32>(self + kIOATIR5002DContext_commandBufferGartOffset);
      M<UInt32 *>(descriptorBytes + 0xc) = recordCursor;
      M<UInt32>(descriptorBytes + 8) = pendingWords;
      M<SInt32>(descriptorBytes + 4) = streamOffset + gartOffset + 0x20;
      return result;
    }
  } while( true );
}
