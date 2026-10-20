/*
 * ATIR500DVDContext_submit_context_buffer_Port.cpp
 *
 * ATIR500DVDContext::submit_context_buffer (real addr 0x34440, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x34440 */
void ATIR500DVDContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 *header;
  SInt32 iVar3;
  UInt8 *texture;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt32 *slotHeader;
  SInt32 dwordCount;
  UInt32 uVar11;
  SInt32 payload;
  UInt32 uVar13;
  SInt32 iVar14;
  SInt32 iVar15;
  SInt32 iVar16;
  SInt32 iVar17;
  UInt8 *textureSlot;
  SInt32 *accel;
  SInt32 iVar20;
  UInt8 *pAVar21;
  SInt32 iVar22;
  SInt32 iVar23;
  UInt8 *slotCursor;
  UInt8 *ringEntry;
  SInt32 slotTexture;
  UInt32 nextRingIndex;
  SInt32 oldWaitCounter;
  SInt32 counterAdvance;
  UInt32 headerWord1;
  UInt32 headerWord2;
  UInt32 headerWord3;
  UInt32 headerWord7;
  UInt32 headerWord4;
  UInt32 headerWord6;
  SInt32 pendingHeader;
  SInt32 entryHeaderBase;
  SInt32 trailerByteOffset0;
  SInt32 trailerIdx8;
  SInt32 copyByteOffset;
  SInt32 copyRemaining;
  SInt32 delayCount;
  SInt32 padByteOffset;
  UInt32 submitStamp;
  UInt32 packetWordCount;
  SInt32 trailerIdx1;
  SInt32 trailerIdx2;
  SInt32 trailerIdx3;
  SInt32 trailerIdx4;
  SInt32 trailerIdx5;
  SInt32 trailerIdx6;
  SInt32 trailerIdx7;
  SInt32 trailerIdx9;
  
  slotCursor = self;
  do {
    texture = M<UInt8 *>(slotCursor + 0x104);
    textureSlot = slotCursor + 0x104;
    if (texture != (UInt8 *)0x0) {
      if (M<char>(M<SInt32>(texture + 0x14) + 0x14) != '\0') {
        if (M<SInt32>(texture + 4) == 0) {
          ((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(texture));
          texture = M<UInt8 *>(slotCursor + 0x104);
          if (M<SInt32>(texture + 4) != 0) goto LAB_000344b0;
        }
        else {
LAB_000344b0:
          GH_IOGetTime(texture + 0x2c);
          M<UInt32>(M<SInt32>(M<SInt32>(slotCursor + 0x104) + 0x34) + 0x38) =
               M<UInt32>(M<SInt32>(slotCursor + 0x104) + 0x38);
          M<UInt32>(M<SInt32>(M<SInt32>(slotCursor + 0x104) + 0x38) + 0x34) =
               M<UInt32>(M<SInt32>(slotCursor + 0x104) + 0x34);
          M<UInt32>(M<SInt32>(slotCursor + 0x104) + 0x34) =
               M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0);
          M<SInt32>(M<SInt32>(slotCursor + 0x104) + 0x38) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x69c;
          M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x6d0) = M<UInt32>(slotCursor + 0x104);
          M<SInt32>(M<SInt32>(M<SInt32>(slotCursor + 0x104) + 0x34) + 0x38) = M<SInt32>(slotCursor + 0x104);
        }
        M<UInt8>(M<SInt32>(M<SInt32>(textureSlot) + 0x14) + 0x14) = 0;
        M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_contextBufferHeader) + 0x1c) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_contextBufferHeader) + 0x1c) | 1;
      }
      slotTexture = M<SInt32>(textureSlot);
      if (M<SInt32>(slotTexture + 0x48) != 0) {
        M<UInt32>(M<SInt32>(slotTexture + 0x24) + 0x28) = M<UInt32>(slotTexture + 0x28);
        M<UInt32>(M<SInt32>(M<SInt32>(textureSlot) + 0x28) + 0x24) =
             M<UInt32>(M<SInt32>(textureSlot) + 0x24);
        M<UInt32>(M<SInt32>(textureSlot) + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x600);
        M<SInt32>(M<SInt32>(textureSlot) + 0x28) = M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x5dc;
        M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x600) = M<SInt32>(textureSlot);
        M<SInt32>(M<SInt32>(M<SInt32>(textureSlot) + 0x24) + 0x28) = M<SInt32>(textureSlot);
      }
    }
    slotCursor = slotCursor + 4;
    if (slotCursor == self + 0x48) {
      if ((M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_contextBufferHeader) + 0x1c) & 1) == 0) {
        ringEntry = self + M<SInt32>(self + kIOATIR500DVDContext_contextBufferRingIndex) * 0x18;
      }
      else {
        accel = M<SInt32 *>(self + kIOATIR500DVDContext_accelerator);
        nextRingIndex = M<SInt32>(self + kIOATIR500DVDContext_contextBufferRingIndex) + 1U & 1;
        M<UInt32>(self + kIOATIR500DVDContext_contextBufferRingIndex) = nextRingIndex;
        ringEntry = self + nextRingIndex * 0x18;
        oldWaitCounter = accel[0x1e1];
        counterAdvance = VCALL(*accel, 0x54c)(accel,M<UInt32>(ringEntry + 0xd4));
        accel[0x1e1] = oldWaitCounter + counterAdvance;
        header = M<UInt32 *>(self + kIOATIR500DVDContext_contextBufferHeader);
        slotHeader = M<UInt32 *>(ringEntry + 0xd8);
        headerWord1 = header[1];
        headerWord2 = header[2];
        headerWord3 = header[3];
        *slotHeader = *header;
        slotHeader[1] = headerWord1;
        slotHeader[2] = headerWord2;
        slotHeader[3] = headerWord3;
        headerWord7 = header[7];
        headerWord4 = header[4];
        headerWord6 = header[6];
        slotHeader[5] = header[5];
        slotHeader[7] = headerWord7;
        slotHeader[4] = headerWord4;
        slotHeader[6] = headerWord6;
        pendingHeader = M<SInt32>(self + kIOATIR500DVDContext_contextBufferHeader);
        entryHeaderBase = M<SInt32>(ringEntry + 0xd8);
        dwordCount = M<SInt32>(pendingHeader + 0x14);
        payload = entryHeaderBase + 0x20;
        if (dwordCount == 0) {
          dwordCount = 0;
          trailerByteOffset0 = 0;
          trailerIdx1 = 1;
          trailerIdx2 = 2;
          trailerIdx3 = 3;
          trailerIdx4 = 4;
          trailerIdx5 = 5;
          trailerIdx6 = 6;
          trailerIdx7 = 7;
          trailerIdx8 = 8;
          trailerIdx9 = 9;
          packetWordCount = 10;
        }
        else {
          copyByteOffset = 0;
          copyRemaining = dwordCount;
          do {
            M<UInt32>(payload + copyByteOffset) = M<UInt32>(pendingHeader + 0x20 + copyByteOffset);
            copyByteOffset = copyByteOffset + 4;
            copyRemaining = copyRemaining + -1;
          } while (copyRemaining != 0);
          entryHeaderBase = M<SInt32>(ringEntry + 0xd8);
          trailerByteOffset0 = dwordCount << 2;
          trailerIdx1 = dwordCount + 1;
          trailerIdx2 = dwordCount + 2;
          trailerIdx3 = dwordCount + 3;
          trailerIdx4 = dwordCount + 4;
          trailerIdx5 = dwordCount + 5;
          trailerIdx6 = dwordCount + 6;
          trailerIdx7 = dwordCount + 7;
          trailerIdx8 = dwordCount + 8;
          trailerIdx9 = dwordCount + 9;
          packetWordCount = dwordCount + 10;
        }
        M<UInt32>(payload + trailerByteOffset0) = 0x1393;
        M<UInt32>(payload + trailerIdx1 * 4) = 10;
        M<UInt32>(payload + trailerIdx2 * 4) = 0xd0b;
        M<UInt32>(payload + trailerIdx3 * 4) = 5;
        M<UInt32>(payload + trailerIdx4 * 4) = 0x13c6;
        M<UInt32>(payload + trailerIdx5 * 4) = 3;
        M<UInt32>(payload + trailerIdx6 * 4) = 0x5c8;
        M<UInt32>(payload + trailerIdx7 * 4) = 0x70000;
        M<UInt32>(payload + trailerIdx8 * 4) = 0x1006;
        M<UInt32>(payload + trailerIdx9 * 4) =
             M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0xb74) & 0xfffeffff | 0x10000;
        delayCount = 0x12;
        do {
          delayCount = delayCount + -1;
        } while (delayCount != 0);
        if ((packetWordCount & 7) != 0) {
          padByteOffset = packetWordCount * 4;
          packetWordCount = dwordCount + 0xb;
          M<UInt32>(payload + padByteOffset) = 0x80000000;
        }
        M<UInt32>(entryHeaderBase + 0x14) = packetWordCount;
        M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_contextBufferHeader) + 0x1c) =
             M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_contextBufferHeader) + 0x1c) & 0xfffffffe;
      }
      if (M<SInt32>(ringEntry + 200) == 0) {
        ((IOATIR500DVDContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(ringEntry + 0xc4)));
      }
      M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x708) =
           M<SInt32>(M<SInt32>(ringEntry + 0xd8) + 0x14) * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x708);
      submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->submit_buffer((UInt32 *)(M<SInt32>(ringEntry + 0xd8) + 0x20),M<SInt32>(ringEntry + 200) + 0x20,
                         M<UInt32>(M<SInt32>(ringEntry + 0xd8) + 0x14));
      M<UInt32>(ringEntry + 0xd4) = submitStamp;
      M<UInt32>(self + kIOATIR500DVDContext_lastSubmitStamp) = submitStamp;
      return;
    }
  } while( true );
}
