/*
 * ATIR5002DContext_submit_context_buffer_Port.cpp
 *
 * ATIR5002DContext::submit_context_buffer (real addr 0x31e90, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* PERF NOTE (NOT APPLIED). Estimated cycles rebuilt/stock 1.12-1.15. Cause: +74 loads and +76 stores over the sampled seeds: every object field the Ghidra text
 * touches is a volatile M<T> access, so fields the shipped code keeps in registers (and repeated stores it folds) are reloaded and rewritten. Closing it: a
 * non-volatile field accessor for the self + k... forms, as -DGH_PLAIN_MEMORY does for other files, after reviewing this function's loops for polled
 * fields; this file stays volatile because it also programs registers (Tools/volatile_memory_sources.txt). */
/* real addr 0x31e90 */
void ATIR5002DContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 tilingByte0;
  UInt8 *entry;
  UInt32 *pendingWrites;
  UInt32 tilingEnableBit;
  UInt8 *texture;
  SInt32 trailerIdx4;
  SInt32 surfaceBuffer;
  SInt32 packet;
  UInt32 *entryHeader;
  SInt32 accel;
  SInt32 trailerIdx2;
  UInt32 gpuBase;
  SInt32 trailerIdx8;
  SInt32 trailerIdx20;
  SInt32 trailerIdx21;
  SInt32 trailerIdx22;
  SInt32 trailerIdx23;
  SInt32 trailerIdx9;
  SInt32 trailerIdx10;
  SInt32 trailerIdx11;
  SInt32 trailerIdx12;
  SInt32 trailerIdx13;
  SInt32 trailerIdx14;
  SInt32 trailerIdx15;
  SInt32 trailerIdx16;
  SInt32 trailerIdx5;
  SInt32 trailerIdx6;
  SInt32 trailerIdx7;
  SInt32 *accelWords;
  SInt32 trailerIdx1;
  SInt32 trailerIdx3;
  SInt32 trailerIdx19;
  SInt32 pendingWordCount;
  SInt32 trailerIdx39;
  SInt32 trailerIdx38;
  SInt32 trailerIdx37;
  SInt32 trailerIdx36;
  SInt32 trailerIdx35;
  SInt32 trailerIdx34;
  SInt32 trailerIdx33;
  SInt32 trailerIdx32;
  SInt32 trailerIdx31;
  SInt32 trailerIdx30;
  SInt32 trailerIdx29;
  SInt32 trailerIdx28;
  SInt32 trailerIdx27;
  SInt32 trailerIdx26;
  SInt32 trailerIdx25;
  SInt32 trailerIdx24;
  SInt32 trailerIdx17;
  UInt32 headerWord1;
  UInt32 headerWord2;
  UInt32 headerWord3;
  UInt32 headerWord7;
  UInt32 headerWord4;
  UInt32 headerWord5;
  UInt32 nextRingIndex;
  SInt32 oldWaitCounter;
  SInt32 counterAdvance;
  SInt32 pendingHeader;
  SInt32 copyByteOffset;
  SInt32 copyRemaining;
  SInt32 padByteOffset;
  SInt32 entryHeaderBase;
  UInt32 packetWordCount;
  SInt32 trailerIdx18;
  SInt32 trailerByteOffset0;
  UInt32 submitStamp;
  
  texture = M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture);
  if (texture != (UInt8 *)0x0) {
    if (M<char>(M<SInt32>(texture + 0x14) + 0x14) != '\0') {
      this->alloc_and_load_image((VendorTextureBuffer *)(texture));
      texture = M<UInt8 *>(self + kIOATIR5002DContext_lastBoundTexture);
    }
    if (M<SInt32>(texture + 0x48) != 0) {
      M<UInt32>(M<SInt32>(texture + 0x24) + 0x28) = M<UInt32>(texture + 0x28);
      M<UInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x28) + 0x24) =
           M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x24);
      M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x24) =
           M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x600);
      M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x28) = M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x5dc;
      M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x600) = M<UInt32>(self + kIOATIR5002DContext_lastBoundTexture);
      M<SInt32>(M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture) + 0x24) + 0x28) = M<SInt32>(self + kIOATIR5002DContext_lastBoundTexture);
    }
  }
  if ((M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) & 1) == 0) {
    entry = self + M<SInt32>(self + kIOATIR5002DContext_contextBufferRingIndex) * 0x18;
  }
  else {
    accelWords = M<SInt32 *>(self + kIOATIR5002DContext_accelerator);
    nextRingIndex = M<SInt32>(self + kIOATIR5002DContext_contextBufferRingIndex) + 1U & 1;
    M<UInt32>(self + kIOATIR5002DContext_contextBufferRingIndex) = nextRingIndex;
    entry = self + nextRingIndex * 0x18;
    oldWaitCounter = accelWords[0x1df];
    counterAdvance = VCALL(*accelWords, 0x54c)(accelWords,M<UInt32>(entry + 0xdc));
    accelWords[0x1df] = oldWaitCounter + counterAdvance;
    pendingWrites = M<UInt32 *>(self + kIOATIR5002DContext_contextBufferHeader);
    entryHeader = M<UInt32 *>(entry + 0xe0);
    headerWord1 = pendingWrites[1];
    headerWord2 = pendingWrites[2];
    headerWord3 = pendingWrites[3];
    *entryHeader = *pendingWrites;
    entryHeader[1] = headerWord1;
    entryHeader[2] = headerWord2;
    entryHeader[3] = headerWord3;
    headerWord7 = pendingWrites[7];
    headerWord4 = pendingWrites[4];
    headerWord5 = pendingWrites[5];
    entryHeader[6] = pendingWrites[6];
    entryHeader[7] = headerWord7;
    entryHeader[4] = headerWord4;
    entryHeader[5] = headerWord5;
    pendingHeader = M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader);
    entryHeaderBase = M<SInt32>(entry + 0xe0);
    pendingWordCount = M<SInt32>(pendingHeader + 0x14);
    packet = entryHeaderBase + 0x20;
    if (pendingWordCount == 0) {
      trailerByteOffset0 = 0;
      trailerIdx1 = 1;
      pendingWordCount = 0;
      trailerIdx17 = 0x11;
      trailerIdx18 = 0x12;
      trailerIdx2 = 2;
      trailerIdx19 = 0x13;
      trailerIdx3 = 3;
      trailerIdx24 = 0x18;
      trailerIdx4 = 4;
      trailerIdx25 = 0x19;
      trailerIdx26 = 0x1a;
      trailerIdx27 = 0x1b;
      trailerIdx28 = 0x1c;
      trailerIdx29 = 0x1d;
      trailerIdx30 = 0x1e;
      trailerIdx31 = 0x1f;
      trailerIdx32 = 0x20;
      trailerIdx33 = 0x21;
      trailerIdx34 = 0x22;
      trailerIdx35 = 0x23;
      trailerIdx36 = 0x24;
      trailerIdx5 = 5;
      trailerIdx37 = 0x25;
      trailerIdx6 = 6;
      trailerIdx7 = 7;
      trailerIdx38 = 0x26;
      trailerIdx8 = 8;
      trailerIdx39 = 0x27;
      trailerIdx9 = 9;
      trailerIdx10 = 10;
      trailerIdx11 = 0xb;
      trailerIdx12 = 0xc;
      trailerIdx13 = 0xd;
      trailerIdx14 = 0xe;
      trailerIdx15 = 0xf;
      trailerIdx16 = 0x10;
      trailerIdx20 = 0x14;
      trailerIdx21 = 0x15;
      trailerIdx22 = 0x16;
      trailerIdx23 = 0x17;
      packetWordCount = 0x28;
    }
    else {
      copyByteOffset = 0;
      copyRemaining = pendingWordCount;
      do {
        M<UInt32>(packet + copyByteOffset) = M<UInt32>(pendingHeader + 0x20 + copyByteOffset);
        copyByteOffset = copyByteOffset + 4;
        copyRemaining = copyRemaining + -1;
      } while (copyRemaining != 0);
      trailerIdx17 = pendingWordCount + 0x11;
      entryHeaderBase = M<SInt32>(entry + 0xe0);
      trailerIdx18 = pendingWordCount + 0x12;
      trailerByteOffset0 = pendingWordCount << 2;
      trailerIdx19 = pendingWordCount + 0x13;
      trailerIdx24 = pendingWordCount + 0x18;
      trailerIdx1 = pendingWordCount + 1;
      trailerIdx25 = pendingWordCount + 0x19;
      trailerIdx26 = pendingWordCount + 0x1a;
      trailerIdx2 = pendingWordCount + 2;
      trailerIdx27 = pendingWordCount + 0x1b;
      trailerIdx28 = pendingWordCount + 0x1c;
      trailerIdx29 = pendingWordCount + 0x1d;
      trailerIdx30 = pendingWordCount + 0x1e;
      trailerIdx31 = pendingWordCount + 0x1f;
      trailerIdx32 = pendingWordCount + 0x20;
      trailerIdx33 = pendingWordCount + 0x21;
      trailerIdx34 = pendingWordCount + 0x22;
      trailerIdx35 = pendingWordCount + 0x23;
      trailerIdx36 = pendingWordCount + 0x24;
      trailerIdx37 = pendingWordCount + 0x25;
      trailerIdx38 = pendingWordCount + 0x26;
      trailerIdx39 = pendingWordCount + 0x27;
      trailerIdx3 = pendingWordCount + 3;
      trailerIdx4 = pendingWordCount + 4;
      trailerIdx5 = pendingWordCount + 5;
      trailerIdx6 = pendingWordCount + 6;
      trailerIdx7 = pendingWordCount + 7;
      trailerIdx8 = pendingWordCount + 8;
      trailerIdx9 = pendingWordCount + 9;
      trailerIdx10 = pendingWordCount + 10;
      trailerIdx11 = pendingWordCount + 0xb;
      trailerIdx12 = pendingWordCount + 0xc;
      trailerIdx13 = pendingWordCount + 0xd;
      trailerIdx14 = pendingWordCount + 0xe;
      trailerIdx15 = pendingWordCount + 0xf;
      trailerIdx16 = pendingWordCount + 0x10;
      trailerIdx20 = pendingWordCount + 0x14;
      trailerIdx21 = pendingWordCount + 0x15;
      trailerIdx22 = pendingWordCount + 0x16;
      trailerIdx23 = pendingWordCount + 0x17;
      packetWordCount = pendingWordCount + 0x28;
    }
    if (M<SInt32>(self + kIOATIR5002DContext_boundSurface) == 0) {
      accel = M<SInt32>(self + kIOATIR5002DContext_accelerator);
      surfaceBuffer = M<SInt32>(self + kIOATIR5002DContext_panelIndex) * 0x78 + accel + kIOATIR500Accelerator_scanout1Buffer;
    }
    else {
      accel = M<SInt32>(self + kIOATIR5002DContext_accelerator);
      surfaceBuffer = M<SInt32>(self + kIOATIR5002DContext_boundSurface) + 0xa8;
    }
    M<UInt32>(packet + trailerByteOffset0) = 0x1393;
    M<UInt32>(packet + trailerIdx1 * 4) = 10;
    M<UInt32>(packet + trailerIdx2 * 4) = 0xd0b;
    M<UInt32>(packet + trailerIdx3 * 4) = 5;
    M<UInt32>(packet + trailerIdx4 * 4) = 0x13c6;
    M<UInt32>(packet + trailerIdx5 * 4) = 3;
    M<UInt32>(packet + trailerIdx6 * 4) = 0x5c8;
    M<UInt32>(packet + trailerIdx7 * 4) = 0x70000;
    M<UInt32>(packet + trailerIdx8 * 4) = 0x1006;
    M<UInt32>(packet + trailerIdx9 * 4) = M<UInt32>(accel + kIOATIR500Accelerator_gbTileConfig);
    M<UInt32>(packet + trailerIdx10 * 4) = 0x1008;
    M<UInt32>(packet + trailerIdx11 * 4) = 0;
    M<UInt32>(packet + trailerIdx12 * 4) = 0x1380;
    M<UInt32>(packet + trailerIdx13 * 4) = 0;
    M<UInt32>(packet + trailerIdx14 * 4) = 0x13c7;
    M<UInt32>(packet + trailerIdx15 * 4) = 0;
    M<UInt32>(packet + trailerIdx16 * 4) = 0x10e9;
    M<UInt32>(packet + trailerIdx17 * 4) = 0;
    M<UInt32>(packet + trailerIdx18 * 4) = 0x13de;
    M<UInt32>(packet + trailerIdx19 * 4) = 0;
    M<UInt32>(packet + trailerIdx20 * 4) = 0x13ad;
    M<UInt32>(packet + trailerIdx21 * 4) = 0;
    M<UInt32>(packet + trailerIdx22 * 4) = 0x105bb;
    M<UInt32>(packet + trailerIdx23 * 4) = 0;
    M<UInt32>(packet + trailerIdx24 * 4) =
         CONCAT22(M<UInt16>(surfaceBuffer + 0x1e),M<UInt16>(surfaceBuffer + 0x1c));
    M<UInt32>(packet + trailerIdx25 * 4) = 0x11004;
    M<UInt32>(packet + trailerIdx26 * 4) = 0x66666666;
    M<UInt32>(packet + trailerIdx27 * 4) = 0x6666666;
    M<UInt32>(packet + trailerIdx28 * 4) = 0x5b8;
    tilingByte0 = M<UInt8>(surfaceBuffer + 0x38);
    gpuBase = M<UInt32>(surfaceBuffer + 8);
    tilingEnableBit = 0x80000000;
    if (tilingByte0 < 2) {
      tilingEnableBit = 0;
    }
    M<UInt32>(packet + trailerIdx29 * 4) =
         tilingEnableBit | gpuBase >> 10 | (M<UInt16>(surfaceBuffer + 0x18) & 0x3fc0) << 0x10 | (tilingByte0 & 1) << 0x1e;
    M<UInt32>(packet + trailerIdx30 * 4) = 0x138a;
    M<UInt32>(packet + trailerIdx31 * 4) = gpuBase & 0xffffffe0;
    M<UInt32>(packet + trailerIdx32 * 4) = 0x138e;
    M<UInt32>(packet + trailerIdx33 * 4) =
         M<UInt16>(surfaceBuffer + 0x14) & 0x3ffe | (tilingByte0 & 1) << 0x10 | (tilingByte0 & 6) << 0x10 |
         (M<UInt8>(surfaceBuffer + 0x39) & 3) << 0x13 | (M<UInt8>(surfaceBuffer + 0x3b) & 0xf) << 0x15;
    M<UInt32>(packet + trailerIdx34 * 4) = 0xd0a;
    M<UInt32>(packet + trailerIdx35 * 4) = 0x100;
    M<UInt32>(packet + trailerIdx36 * 4) = 0x1383;
    M<UInt32>(packet + trailerIdx37 * 4) = 0xf;
    M<UInt32>(packet + trailerIdx38 * 4) = 0x1386;
    M<UInt32>(packet + trailerIdx39 * 4) = 0;
    if ((packetWordCount & 1) != 0) {
      padByteOffset = packetWordCount * 4;
      packetWordCount = pendingWordCount + 0x29;
      M<UInt32>(packet + padByteOffset) = 0x80000000;
    }
    M<UInt32>(entryHeaderBase + 0x14) = packetWordCount;
    M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_contextBufferHeader) + 0x1c) & 0xfffffffe;
  }
  if (M<SInt32>(entry + 0xd0) == 0) {
    ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(entry + 0xcc)));
  }
  M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700) =
       M<SInt32>(M<SInt32>(entry + 0xe0) + 0x14) * 4 + M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x700);
  submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->submit_buffer((UInt32 *)(M<SInt32>(entry + 0xe0) + 0x20),
                      M<SInt32>(entry + 0xd0) + 0x20,M<UInt32>(M<SInt32>(entry + 0xe0) + 0x14));
  M<UInt32>(entry + 0xdc) = submitStamp;
  M<UInt32>(self + kIOATIR5002DContext_lastSubmitStamp) = submitStamp;
  return;
}
