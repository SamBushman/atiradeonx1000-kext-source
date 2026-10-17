/*
 * ATIR500GLContext_get_texture_Port.cpp
 *
 * ATIR500GLContext::get_texture (real addr 0x2b5f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x2b5f0 */
void ATIR500GLContext::get_texture(UInt32*record, VendorTextureBuffer *texture, UInt32*streamOffset, UInt32*pendingWords, UInt32*reservedWords, register_tracking_state *scratch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);
    UInt8 *scratchBytes = reinterpret_cast<UInt8 *>(scratch);

  UInt32 blockWords;
  SInt32 *countField;
  SInt32 header;
  SInt32 prev;
  UInt32 stamp;
  UInt32 blockHeader;
  char in_RESERVE;
  UInt8 in_cr0;
  
  header = M<SInt32>(textureBytes + 0x14);
  if (M<char>(header + 0x14) != '\0') {
    if (*pendingWords != 0) {
      blockWords = record[-1] >> 2;
      if (4 < blockWords) {
        blockHeader = 0x80000000;
        if (blockWords != 5) {
          blockHeader = (blockWords - 6) * 0x10000 | 0xc0001000;
        }
        record[-blockWords] = blockHeader;
      }
      record[-4] = 0x1393;
      record[-3] = 0;
      record[-2] = 0x5c8;
      record[-1] = 0x20000;
      M<UInt32>(M<SInt32>(self + 200) + 0x704) =
           *pendingWords * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
      M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
      stamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((*streamOffset & 0xfffffffc) + M<SInt32>(self + 0xe0) + 0x20),
                         *streamOffset + M<SInt32>(self + 0xd0) + 0x20,*pendingWords);
      M<UInt32>(self + 0xdc) = stamp;
      *streamOffset = *pendingWords * 4 + *streamOffset;
      *pendingWords = 0;
      *reservedWords = 0;
    }
    this->alloc_and_load_texture((VendorTextureBuffer *)(textureBytes));
    if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
      M<UInt32 *>(scratchBytes + 0x140) = record;
      this->restore_state_destroyed_by_pageoff((register_tracking_state *)(scratchBytes));
    }
    if (M<SInt32>(self + 0xd0) == 0) {
      ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
      header = M<SInt32>(textureBytes + 0x14);
    }
    else {
      header = M<SInt32>(textureBytes + 0x14);
    }
  }
  countField = (SInt32 *)(header + 0x10);
  atomicAddReturningOld((SInt32 *)countField, -0xffff);
  if (M<SInt32>(textureBytes + 0x48) != 0) {
    prev = M<SInt32>(textureBytes + 0x24);
    M<UInt32>(prev + 0x28) = M<UInt32>(textureBytes + 0x28);
    M<SInt32>(M<SInt32>(textureBytes + 0x28) + 0x24) = prev;
    M<UInt32>(textureBytes + 0x24) = M<UInt32>(M<SInt32>(self + 200) + 0x600);
    M<SInt32>(textureBytes + 0x28) = M<SInt32>(self + 200) + 0x5dc;
    M<UInt8 *>(M<SInt32>(self + 200) + 0x600) = textureBytes;
    M<UInt8 *>(M<SInt32>(textureBytes + 0x24) + 0x28) = textureBytes;
  }
  return;
}
