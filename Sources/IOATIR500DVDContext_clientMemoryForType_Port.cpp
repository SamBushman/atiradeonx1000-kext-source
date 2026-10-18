/*
 * IOATIR500DVDContext_clientMemoryForType_Port.cpp
 *
 * IOATIR500DVDContext::clientMemoryForType (real addr 0xf0c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* label addresses in the shipped code: surfaceReady 0xf180, afterAllocation 0xf264, retryOrGiveUp 0xf2b8, forceAllocation 0xf2ec, noSurface 0xf330, abortSetup 0xf334,
 * submitCommandBuffer 0xf380, advanceRing 0xf6bc, finishCommandBuffer 0xf800 */
/* real addr 0xf0c0 */
IOReturn IOATIR500DVDContext::clientMemoryForType(UInt32 type, UInt32*options, IOMemoryDescriptor**memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  unsigned int neededMask;
  int *piVar2;
  unsigned int allocatedMask;
  int iVar4;
  int iVar5;
  UInt32 commandBufferFlags;
  unsigned int retryCount;
  UInt8 *surface;
  int iVar8;
  UInt8 *textureSlot;
  int *accelWords;
  UInt8 *accelBytes;
  int *surfaceWords;
  int *bufferEntry;
  /* one 16-byte stack object filled by the +0x5ac/+0x5b4/+0x560 callees (Ghidra named its words auStack_58 and local_50; #85) */
  int auStack_58[4];
  SInt32 rv5b4 = 0;
  /* one real 7-word VendorCommandBuffer (mirror of the 0x1c-byte slot at self+0x90). allocCommandBuffer fills it by address, so it must be ONE contiguous object - seven separate int locals only worked in stock by stack-adjacency luck (same bug class as #164/#160); in our gcc 4.0.1 build they scatter and the alloc result never reached the copy-back (#168) */
  int cmdBufBlock[7];
  
  if (type != 1) {
    if (type == 0) {
      if (M<int *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xac) != (int *)0x0) {
        VCALL(*M<int *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xac), 0x14)(M<int *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xac));
        *options = 0;
        *memory = M<IOMemoryDescriptor *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xac);
        return 0;
      }
    }
    else {
      if (type == 2) {
        GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
        VCALL(*M<int *>(self + kIOATIR500DVDContext_contextBufferDescriptor), 0x14)(M<int *>(self + kIOATIR500DVDContext_contextBufferDescriptor));
        *options = 0;
        *memory = M<IOMemoryDescriptor *>(self + kIOATIR500DVDContext_contextBufferDescriptor);
        this->init_context_buffer_header((VendorContextBufferHeader *)(M<VendorContextBufferHeader *>(self + kIOATIR500DVDContext_contextBufferHeader)),0x1000);
        GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
        return 0;
      }
      if (type != 3) {
        return 0xe00002c2;
      }
      if (M<int *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xb0) != (int *)0x0) {
        VCALL(*M<int *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xb0), 0x14)(M<int *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xb0));
        *options = 0;
        *memory = M<IOMemoryDescriptor *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0xb0);
        return 0;
      }
    }
    return 0xe00002be;
  }
  retryCount = 0;
  do {
    GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
    surface = M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface);
    if (surface == (UInt8 *)0x0) {
noSurface:
      commandBufferFlags = 0;
abortSetup:
      VCALL(M<int>(self), 0x5b8)(self);
      M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x78) = 0;
finishCommandBuffer:
      VCALL(*M<int *>(self + kIOATIR500DVDContext_commandBufferDescriptor), 0x14)(M<int *>(self + kIOATIR500DVDContext_commandBufferDescriptor));
      *options = 0;
      *memory = M<IOMemoryDescriptor *>(self + kIOATIR500DVDContext_commandBufferDescriptor);
      this->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + kIOATIR500DVDContext_commandBufferHeader)),M<UInt32>(self + kIOATIR500DVDContext_commandBufferSize),commandBufferFlags);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
      return 0;
    }
    if (M<unsigned int>(surface + 0xa4) < 0x100) {
surfaceReady:
      iVar8 = M<int>(self + kIOATIR500DVDContext_accelerator);
    }
    else {
      iVar8 = M<int>(self + kIOATIR500DVDContext_accelerator);
      if (M<char>(iVar8 + 0x80) == '\0') {
        do {
          GH_IOLockSleep(M<UInt32>(iVar8 + 0x840),iVar8,0);
        } while (M<char>(iVar8 + 0x80) == '\0');
        surface = M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface);
        if (surface != (UInt8 *)0x0) goto surfaceReady;
        goto noSurface;
      }
    }
    if (M<char>(iVar8 + 0x80) == '\0') goto noSurface;
    if (surface[0xbf6] == 0x0) {
      commandBufferFlags = M<unsigned int>(surface + 0xbfc) | 2;
      if ((surface[0xbd0] == 0x0) || (retryCount == 999)) {
        allocatedMask = M<unsigned int>(surface + 0xbf8);
        if (((M<unsigned int>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) | M<unsigned int>(surface + 0xc1c)) & allocatedMask) != 0) {
          if ((allocatedMask & 0x20000000) != 0) goto abortSetup;
          neededMask = (M<unsigned int>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) | M<unsigned int>(surface + 0xc1c)) & 0x7fffff;
          if ((allocatedMask & neededMask) == 0) {
            iVar8 = M<int>(surface);
          }
          else {
            iVar8 = ((IOATIR500Surface *)((UInt32)surface))->alloc_surfaces(neededMask, false);
            if (iVar8 != 0) {
              if (iVar8 != 2) goto retryOrGiveUp;
              goto abortSetup;
            }
            surface = M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface);
            if ((M<unsigned int>(surface + 0xbf8) & M<unsigned int>(surface + 0xc1c) & 0x10000000) == 0)
            goto afterAllocation;
            iVar8 = M<int>(surface);
          }
          VCALL(iVar8, 0x5c0)(surface);
          M<unsigned int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xbf8) =
               M<unsigned int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xbf8) & 0xefffffff;
        }
afterAllocation:
        if (retryCount < 1000) {
submitCommandBuffer:
          textureSlot = self;
          do {
            if (M<UInt8 *>(textureSlot + 0x104) != (UInt8 *)0x0) {
              this->add_texture_to_stream((VendorTextureBuffer *)(M<UInt8 *>(textureSlot + 0x104)));
            }
            textureSlot = textureSlot + 4;
          } while (self + 0x48 != textureSlot);
          if (self != M<UInt8 *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x78)) {
            VCALL(M<int>(self), 0x5b0)(self);
            M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x748) = M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x748) + 1;
            M<UInt8 *>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x78) = self;
          }
          if (M<int>(self + kIOATIR500DVDContext_commandBufferGartOffset) == 0) {
            this->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500DVDContext_commandBuffer)));
          }
          /* the decompile dropped this call's result (shipped: `or r28,r3,r3` at 0xf428, tested at 0xf534) */
          rv5b4 = VCALL(M<int>(self), 0x5b4)(self,auStack_58);
          textureSlot = self;
          do {
            if (M<UInt8 *>(textureSlot + 0x104) != (UInt8 *)0x0) {
              this->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(textureSlot + 0x104)));
            }
            textureSlot = textureSlot + 4;
          } while (self + 0x48 != textureSlot);
          if (auStack_58[2] == 0) {
            iVar8 = M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x50) + -1;
          }
          else {
            M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x708) =
                 auStack_58[2] * 4 + M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x708);
            iVar8 = VCALL(*M<int *>(self + kIOATIR500DVDContext_accelerator), 0x560)
                              (M<int *>(self + kIOATIR500DVDContext_accelerator),auStack_58);
          }
          surfaceWords = M<int *>(self + kIOATIR500DVDContext_boundSurface);
          iVar8 = VCALL(*surfaceWords, 0x5b4)(surfaceWords,iVar8,M<UInt32>(self + kIOATIR500DVDContext_surfaceFlagsBitmask));
          surfaceWords[0x1f] = iVar8;
          M<int>(self + kIOATIR500DVDContext_lastSubmitStamp) = iVar8;
          M<int>(self + kIOATIR500DVDContext_commandBufferStamp) = iVar8;
          iVar8 = M<int>(self + kIOATIR500DVDContext_boundSurface);
          if (iVar8 != M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x5c)) {
            M<UInt32>(M<int>(iVar8 + 0x9c) + 0xa0) = M<UInt32>(iVar8 + 0xa0);
            M<UInt32>(M<int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xa0) + 0x9c) =
                 M<UInt32>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0x9c);
            iVar8 = M<int>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x5c);
            M<int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0x9c) = iVar8;
            iVar4 = M<int>(iVar8 + 0xa0);
            M<int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xa0) = iVar4;
            M<UInt32>(iVar8 + 0xa0) = M<UInt32>(self + kIOATIR500DVDContext_boundSurface);
            M<UInt32>(iVar4 + 0x9c) = M<UInt32>(self + kIOATIR500DVDContext_boundSurface);
            M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x5c) = M<UInt32>(self + kIOATIR500DVDContext_boundSurface);
          }
          /* RECOVERED from the shipped disassembly (0xf534-0xf5e8): Ghidra's decompile omitted this whole block (no 0xcac / 0x5d4 / 0x74c / 0x79c / 0x558
           * anywhere in it; the 2D twin of this method has it). Runs only when the +0x5b4 call above returned non-zero and this path took the
           * `commandBufferFlags = 0` exit (the other path ORs 2 into commandBufferFlags). #85 */
          if ((rv5b4 != 0) && ((commandBufferFlags & 2) == 0)) {
            UInt8 *surf = M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface);
            UInt32 savedField = M<UInt32>(surf + 0x84);
            UInt8 *accel = M<UInt8 *>(self + kIOATIR500DVDContext_accelerator);
            UInt32 idx = 0, off = 0;
            M<UInt32>(surf + 0x84) = M<UInt32>(surf + 0x80);
            if (M<UInt32>(accel + 0xcc) != 0) {
              do {
                UInt8 *s2 = M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface);
                if (M<UInt8>(s2 + off + 0xcac) != 0) {
                  VCALL(*M<SInt32 *>(s2), 0x5d4)(s2, idx, 0);
                  M<UInt32>(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator) + 0x74c) = M<UInt32>(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator) + 0x74c) + 1;
                  accel = M<UInt8 *>(self + kIOATIR500DVDContext_accelerator);
                }
                idx = idx + 1;
                off = off + 0x94;
              } while (idx < M<UInt32>(accel + 0xcc));
            }
            {
              UInt32 acc = M<UInt32>(accel + 0x79c);
              acc = acc + VCALL(*M<SInt32 *>(accel), 0x558)(accel, savedField);
              M<UInt32>(accel + 0x79c) = acc;
            }
          }
          accelWords = M<int *>(self + kIOATIR500DVDContext_accelerator);
          bufferEntry = accelWords + (unsigned int)M<UInt16>(accelWords + 0x100) * 7 + 0x90;
          if ((unsigned int)accelWords[0x172] < 0x80000) {
            accelWords[0x172] = 0x80000;
            accelWords = M<int *>(self + kIOATIR500DVDContext_accelerator);
          }
          iVar8 = VCALL(*accelWords, 0x554)(accelWords,bufferEntry[4]);
          if (iVar8 == 0) {
            accelBytes = M<UInt8 *>(self + kIOATIR500DVDContext_accelerator);
            if (M<UInt16>(accelBytes + 0x402) < 0x10) {
              iVar8 = ((IOATIR500Accelerator *)(accelBytes))->allocMoreCommandBuffers(0, 0x80000);
              if (iVar8 != 0) {
                iVar8 = M<int>(self + kIOATIR500DVDContext_accelerator);
                bufferEntry = (int *)(iVar8 + (unsigned int)M<UInt16>(iVar8 + 0x400) * 0x1c + 0x240);
                goto advanceRing;
              }
              accelBytes = M<UInt8 *>(self + kIOATIR500DVDContext_accelerator);
            }
            iVar4 = M<int>(accelBytes + 0x774);
            iVar8 = VCALL(M<int>(accelBytes), 0x54c)(accelBytes,bufferEntry[4]);
            M<int>(accelBytes + 0x774) = iVar4 + iVar8;
            iVar8 = M<int>(self + kIOATIR500DVDContext_accelerator);
          }
          else {
            iVar8 = M<int>(self + kIOATIR500DVDContext_accelerator);
          }
advanceRing:
          M<UInt16>(iVar8 + 0x400) =
               M<SInt16>(iVar8 + 0x400) + 1U & M<SInt16>(iVar8 + 0x402) - 1U;
          cmdBufBlock[3] = M<int>(self + kIOATIR500DVDContext_commandBufferState);
          cmdBufBlock[4] = M<int>(self + kIOATIR500DVDContext_commandBufferStamp);
          cmdBufBlock[5] = M<int>(self + kIOATIR500DVDContext_commandBufferHeader);
          cmdBufBlock[6] = M<int>(self + kIOATIR500DVDContext_commandBufferSize);
          cmdBufBlock[0] = M<int>(self + kIOATIR500DVDContext_commandBuffer);
          cmdBufBlock[1] = M<int>(self + kIOATIR500DVDContext_commandBufferGartOffset);
          cmdBufBlock[2] = M<int>(self + kIOATIR500DVDContext_commandBufferDescriptor);
          iVar8 = bufferEntry[1];
          iVar4 = bufferEntry[2];
          iVar5 = bufferEntry[3];
          M<int>(self + kIOATIR500DVDContext_commandBuffer) = *bufferEntry;
          M<int>(self + kIOATIR500DVDContext_commandBufferGartOffset) = iVar8;
          M<int>(self + kIOATIR500DVDContext_commandBufferDescriptor) = iVar4;
          M<int>(self + kIOATIR500DVDContext_commandBufferState) = iVar5;
          iVar8 = bufferEntry[5];
          iVar4 = bufferEntry[6];
          M<int>(self + kIOATIR500DVDContext_commandBufferStamp) = bufferEntry[4];
          M<int>(self + kIOATIR500DVDContext_commandBufferHeader) = iVar8;
          M<int>(self + kIOATIR500DVDContext_commandBufferSize) = iVar4;
          *bufferEntry = cmdBufBlock[0];
          bufferEntry[1] = cmdBufBlock[1];
          bufferEntry[2] = cmdBufBlock[2];
          bufferEntry[3] = cmdBufBlock[3];
          bufferEntry[4] = cmdBufBlock[4];
          bufferEntry[5] = cmdBufBlock[5];
          bufferEntry[6] = cmdBufBlock[6];
          accelBytes = M<UInt8 *>(self + kIOATIR500DVDContext_accelerator);
          if (M<int>(self + kIOATIR500DVDContext_commandBufferSize) != M<int>(accelBytes + 0x5c8)) {
            cmdBufBlock[3] = 0x10000;
            cmdBufBlock[6] = 0;
            cmdBufBlock[0] = 0;
            cmdBufBlock[1] = 0;
            cmdBufBlock[2] = 0;
            cmdBufBlock[4] = 0;
            cmdBufBlock[5] = 0;
            iVar8 = ((IOATIR500Accelerator *)(accelBytes))->allocCommandBuffer((VendorCommandBuffer *)((UInt8 *)&cmdBufBlock[0]),M<UInt32>(accelBytes + 0x5c8))
            ;
            if (iVar8 != 0) {
              ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + kIOATIR500DVDContext_commandBuffer)));
              M<int>(self + kIOATIR500DVDContext_commandBufferGartOffset) = cmdBufBlock[1];
              M<int>(self + kIOATIR500DVDContext_commandBufferDescriptor) = cmdBufBlock[2];
              M<int>(self + kIOATIR500DVDContext_commandBufferState) = cmdBufBlock[3];
              M<int>(self + kIOATIR500DVDContext_commandBufferStamp) = cmdBufBlock[4];
              M<int>(self + kIOATIR500DVDContext_commandBufferHeader) = cmdBufBlock[5];
              M<int>(self + kIOATIR500DVDContext_commandBufferSize) = cmdBufBlock[6];
              M<int>(self + kIOATIR500DVDContext_commandBuffer) = cmdBufBlock[0];
            }
          }
          goto finishCommandBuffer;
        }
        if (retryCount < 0x3e9) goto forceAllocation;
        goto abortSetup;
      }
retryOrGiveUp:
      if (retryCount == 1000) {
forceAllocation:
        iVar8 = ((IOATIR500Surface *)(M<UInt32>(self + kIOATIR500DVDContext_boundSurface)))->alloc_surfaces((M<UInt32>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) | M<UInt32>(M<UInt32>(self + kIOATIR500DVDContext_boundSurface) + 0xc1c)) & 0x7fffff, true);
        if (iVar8 == 0) {
          surfaceWords = M<int *>(self + kIOATIR500DVDContext_boundSurface);
          if ((surfaceWords[0x2fe] & surfaceWords[0x307] & 0x10000000U) != 0) {
            VCALL(*surfaceWords, 0x5c0)(surfaceWords);
            M<unsigned int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xbf8) =
                 M<unsigned int>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xbf8) & 0xefffffff;
          }
          goto submitCommandBuffer;
        }
        goto abortSetup;
      }
      retryCount = retryCount + 1;
      GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
      GH_thread_block(0);
      GH_IOSleep(1);
    }
    else {
      VCALL(M<int>(surface), 0x14)(surface);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
      ((IOATIR500Surface *)(surface))->sleep_blocked();
      VCALL(M<int>(surface), 0x18)(surface);
    }
  } while( true );
}
