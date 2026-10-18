/*
 * IOATIR500GLContext_clientMemoryForType_Port.cpp
 *
 * IOATIR500GLContext::clientMemoryForType (real addr 0xa160, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(...) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");
extern "C" UInt32 GH_memcpy(...) asm("_memcpy");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* label addresses in the shipped code: retryAllocation 0xa1e0, surfaceReady 0xa250, afterPageQueue 0xa354, retryOrGiveUp 0xa408, forceAllocation 0xa43c, noSurface 0xa480,
 * abortSetup 0xa484, submitFlips 0xa7f8, noStampRecord 0xa8f4, advanceRing 0xa9bc, finishCommandBuffer 0xab68, retainDescriptor 0xae2c */
/* real addr 0xa160 */
IOReturn IOATIR500GLContext::clientMemoryForType(UInt32 type, UInt32*options, IOMemoryDescriptor**memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool recordSwapStamp;
  unsigned int neededMask;
  int iVar3;
  unsigned int presentNeeded;
  UInt8 surfaceBits;
  int *piVar5;
  UInt32 uVar6;
  unsigned int uVar8;
  unsigned int swapArg;
  unsigned int allocatedMask;
  int iVar9;
  int iVar10;
  unsigned int uVar11;
  unsigned int swapRequest;
  unsigned int flipPanel;
  unsigned int pendingSubmits;
  UInt32 commandBufferFlags;
  UInt8 *accel;
  UInt8 *surface;
  UInt8 *textureSlot;
  unsigned int uVar15;
  unsigned int panel;
  unsigned int retryCount;
  int *ringSlot;
  /* one 16-byte stack object filled by the +0x5b4 / +0x560 callees (Ghidra named its words descriptor / descriptor[2] / descriptor[3]; #85) */
  int descriptor[4];
  /* one real 7-word VendorCommandBuffer (mirror of the 0x1c-byte slot at self+0xcc/0x90). allocCommandBuffer fills it by address, so it must be ONE contiguous object - seven separate int locals only worked in stock by stack-adjacency luck (same bug class as #164/#160); in our gcc 4.0.1 build they scatter and the alloc result never reached the copy-back (#168) */
  int cmdBufBlock[7];
  
  iVar3 = GH_page_size;
  switch(type) {
  case 0:
    if (M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xac) != (int *)0x0) {
      VCALL(*M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xac), 0x14)(M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xac));
      *options = 0;
      *memory = (IOMemoryDescriptor *)(M<UInt8 *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xac));
      return 0;
    }
    break;
  case 1:
    pendingSubmits = 0;
    retryCount = 0;
    surfaceBits = 0;
retryAllocation:
    do {
      GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
      surface = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
      if (surface == (UInt8 *)0x0) {
noSurface:
        commandBufferFlags = 0;
abortSetup:
        recordSwapStamp = false;
        VCALL(M<int>(self), 0x5b8)(self);
        M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
finishCommandBuffer:
        iVar3 = M<int>(self + kIOATIR500GLContext_dataBufferListHead);
        if (M<int>(self + kIOATIR500GLContext_dataBufferListHead) != M<int>(self + kIOATIR500GLContext_dataBufferListTail)) {
          do {
            iVar10 = M<int>(iVar3 + 0x3c);
            iVar9 = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d0);
            if (iVar9 == 0) {
              M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5cc) = iVar3;
              M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d0) = iVar3;
              M<UInt32>(iVar3 + 0x3c) = 0;
            }
            else {
              M<int>(iVar9 + 0x3c) = iVar3;
              M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d0) = iVar3;
              M<UInt32>(iVar3 + 0x3c) = 0;
            }
            M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d4) = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d4) + 1;
            M<UInt8>(iVar3 + 0x54) = 0;
            iVar3 = iVar10;
          } while (M<int>(self + kIOATIR500GLContext_dataBufferListTail) != iVar10);
          M<int>(self + kIOATIR500GLContext_dataBufferListHead) = iVar10;
          M<UInt32>(iVar10 + 0x3c) = 0;
          M<UInt32>(self + kIOATIR500GLContext_dataBufferCount) = 1;
        }
        VCALL(*M<int *>(self + kIOATIR500GLContext_commandBufferDescriptor), 0x14)(M<int *>(self + kIOATIR500GLContext_commandBufferDescriptor));
        *options = 0;
        *memory = (IOMemoryDescriptor *)(M<UInt8 *>(self + kIOATIR500GLContext_commandBufferDescriptor));
        this->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + kIOATIR500GLContext_commandBufferHeader)),M<UInt32>(self + kIOATIR500GLContext_commandBufferSize),commandBufferFlags)
        ;
        GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
        if (!recordSwapStamp) {
          return 0;
        }
        piVar5 = M<int *>(self + kIOATIR500GLContext_accelerator);
        iVar9 = piVar5[0x1e6];
        iVar3 = VCALL(*piVar5, 0x55c)
                          (piVar5,M<UInt32>(self + M<int>(self + 0xa8) * 4 + 0x9c));
        piVar5[0x1e6] = iVar9 + iVar3;
        return 0;
      }
      if (M<unsigned int>(surface + 0xa4) < 0x100) {
surfaceReady:
        iVar3 = M<int>(self + kIOATIR500GLContext_accelerator);
      }
      else {
        iVar3 = M<int>(self + kIOATIR500GLContext_accelerator);
        if (M<char>(iVar3 + 0x80) == '\0') {
          do {
            GH_IOLockSleep(M<UInt32>(iVar3 + 0x840),iVar3,0);
          } while (M<char>(iVar3 + 0x80) == '\0');
          surface = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
          if (surface != (UInt8 *)0x0) goto surfaceReady;
          goto noSurface;
        }
      }
      if (M<char>(iVar3 + 0x80) == '\0') goto noSurface;
      if (surface[0xbf6] == 0x0) {
        commandBufferFlags = M<UInt32>(surface + 0xbfc);
        if ((M<SInt16>(self + kIOATIR500GLContext_swapIntervalNumerator) != 0) && ((M<unsigned int>(surface + 0xbe8) & 0x20) != 0)) {
          commandBufferFlags = commandBufferFlags | 2;
        }
        if ((surface[0xbd0] == 0x0) || (retryCount == 999)) {
          allocatedMask = M<unsigned int>(surface + 0xbf8);
          if (((M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) | M<unsigned int>(surface + 0xc1c)) & allocatedMask) != 0) {
            if ((allocatedMask & 0x20000000) != 0) goto abortSetup;
            neededMask = (M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) | M<unsigned int>(surface + 0xc1c)) & 0x7fffff;
            presentNeeded = allocatedMask & neededMask;
            if (presentNeeded == 0) {
              iVar3 = M<int>(surface);
            }
            else {
              if ((((presentNeeded & 1) != 0) && (M<int>(surface + 0xcc) == 0)) &&
                 (((allocatedMask & 2) == 0 || (M<int>(surface + 0x144) != 0)))) {
                pendingSubmits = pendingSubmits | 1;
              }
              if (((M<unsigned int>(surface + 0xbe8) & 0x20) == 0) && ((presentNeeded & 0x20) != 0)) {
                pendingSubmits = pendingSubmits | 2;
              }
              surfaceBits = ((IOATIR500Surface *)(surface))->convert_surface_bits(M<UInt32>(M<int>(self + kIOATIR500GLContext_commandBufferHeader) + 0xc));
              iVar3 = ((IOATIR500Surface *)(M<UInt32>(self + kIOATIR500GLContext_boundSurface)))->alloc_surfaces_pageq(neededMask,surfaceBits,false);   /* r6 = 0: the decompile drops the register args after the mask; checked against the disassembly at 0xa3c4 */
              if (iVar3 != 0) {
                if (iVar3 != 2) goto retryOrGiveUp;
                goto abortSetup;
              }
              surface = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
              if ((M<unsigned int>(surface + 0xbf8) & M<unsigned int>(surface + 0xc1c) & 0x10000000) == 0)
              goto afterPageQueue;
              iVar3 = M<int>(surface);
            }
            VCALL(iVar3, 0x5c0)(surface);
            M<unsigned int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xbf8) =
                 M<unsigned int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xbf8) & 0xefffffff;
          }
afterPageQueue:
          if (999 < retryCount) {
            if (retryCount < 0x3e9) goto forceAllocation;
            goto abortSetup;
          }
        }
        else {
retryOrGiveUp:
          if (retryCount != 1000) {
            retryCount = retryCount + 1;
            GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
            GH_thread_block(0);
            GH_IOSleep(1);
            goto retryAllocation;
          }
forceAllocation:
          iVar3 = ((IOATIR500Surface *)(M<UInt32>(self + kIOATIR500GLContext_boundSurface)))->alloc_surfaces_pageq((M<unsigned int>(self + kIOATIR500GLContext_surfaceFlagsBitmask) | M<unsigned int>(M<UInt32>(self + kIOATIR500GLContext_boundSurface) + 0xc1c))
                             & 0x7fffff,surfaceBits,true);   /* r6 = 1 (disassembly 0xa448) */
          if (iVar3 != 0) goto abortSetup;
          piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
          if ((piVar5[0x2fe] & piVar5[0x307] & 0x10000000U) != 0) {
            VCALL(*piVar5, 0x5c0)(piVar5);
            M<unsigned int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xbf8) =
                 M<unsigned int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xbf8) & 0xefffffff;
          }
        }
        if (pendingSubmits != 0) {
          if ((pendingSubmits & 1) != 0) {
            VCALL(*M<int *>(self + kIOATIR500GLContext_boundSurface), 0x5d8)(M<int *>(self + kIOATIR500GLContext_boundSurface),0,1,self);
            M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) + 1;
          }
          if ((pendingSubmits & 2) != 0) {
            piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
            if ((1 << (piVar5[0x305] & 0x3fU) & M<unsigned int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xd0)) != 0) {
              VCALL(*piVar5, 0x5e0)(piVar5,piVar5[0x305],self,0);
              M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) + 1;
            }
          }
        }
        textureSlot = self;
        do {
          if (M<UInt8 *>(textureSlot + 0x2a4) != (UInt8 *)0x0) {
            this->add_texture_to_stream((VendorTextureBuffer *)(M<UInt8 *>(textureSlot + 0x2a4)));
          }
          textureSlot = textureSlot + 4;
        } while (self + 0xa8 != textureSlot);
        if (self != M<UInt8 *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x78)) {
          VCALL(M<int>(self), 0x5b0)(self);
          M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x740) = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x740) + 1;
          M<UInt8 *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x78) = self;
        }
        VCALL(*M<int *>(self + kIOATIR500GLContext_boundSurface), 0x5b8)
                  (M<int *>(self + kIOATIR500GLContext_boundSurface),M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask));
        if (M<int>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
          this->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
        }
        swapRequest = VCALL(M<int>(self), 0x5b4)(self,descriptor);
        textureSlot = self;
        do {
          if (M<UInt8 *>(textureSlot + 0x2a4) != (UInt8 *)0x0) {
            this->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(textureSlot + 0x2a4)));
          }
          textureSlot = textureSlot + 4;
        } while (self + 0xa8 != textureSlot);
        if (((unsigned int)(M<int>(M<int>(self + kIOATIR500GLContext_commandBufferHeader) + 0x10) * 4 - GH_page_size) <
             (unsigned int)(descriptor[3] - (M<int>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20))) &&
           (M<unsigned int>(self + kIOATIR500GLContext_commandBufferSizeHint) < 0x80000)) {
          M<unsigned int>(self + kIOATIR500GLContext_commandBufferSizeHint) = M<unsigned int>(self + kIOATIR500GLContext_commandBufferSizeHint) << 1;
        }
        if (descriptor[2] == 0) {
          iVar3 = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x50) + -1;
        }
        else {
          M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x704) =
               descriptor[2] * 4 + M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x704);
          iVar3 = VCALL(*M<int *>(self + kIOATIR500GLContext_accelerator), 0x560)(M<int *>(self + kIOATIR500GLContext_accelerator),descriptor);
        }
        piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
        iVar3 = VCALL(*piVar5, 0x5b4)(piVar5,iVar3,M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask));
        piVar5[0x1f] = iVar3;
        M<int>(self + kIOATIR500GLContext_lastSubmitStamp) = iVar3;
        M<int>(self + kIOATIR500GLContext_commandBufferStamp) = iVar3;
        piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
        if (piVar5 != M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5c)) {
          M<int>(piVar5[0x27] + 0xa0) = piVar5[0x28];
          M<UInt32>(M<int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xa0) + 0x9c) =
               M<UInt32>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0x9c);
          iVar3 = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5c);
          M<int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0x9c) = iVar3;
          iVar9 = M<int>(iVar3 + 0xa0);
          M<int>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xa0) = iVar9;
          M<UInt32>(iVar3 + 0xa0) = M<UInt32>(self + kIOATIR500GLContext_boundSurface);
          M<UInt32>(iVar9 + 0x9c) = M<UInt32>(self + kIOATIR500GLContext_boundSurface);
          M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5c) = M<UInt32>(self + kIOATIR500GLContext_boundSurface);
          piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
        }
        VCALL(*piVar5, 0x5bc)(piVar5,M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask));
        if ((commandBufferFlags & 2) != 0) {
          swapRequest = swapRequest & 1;
        }
        if (swapRequest == 0) {
          piVar5 = M<int *>(self + kIOATIR500GLContext_accelerator);
noStampRecord:
          recordSwapStamp = false;
        }
        else {
          M<UInt32>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0x84) =
               M<UInt32>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0x80);
          piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
          if ((piVar5[0x2fa] & 0x20U) == 0) {
            iVar3 = VCALL(*piVar5, 0x5dc)(piVar5);
            if (iVar3 == 0) {
              piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
              goto submitFlips;
            }
            iVar3 = M<int>(self + kIOATIR500GLContext_boundSurface);
            uVar6 = M<UInt32>(iVar3 + 0xb74);
            flipPanel = M<unsigned int>(iVar3 + 0xc14);
            M<UInt32>(iVar3 + 0xb74) = M<UInt32>(iVar3 + 0xb70);
            M<UInt32>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xb70) = uVar6;
            iVar3 = M<int>(self + kIOATIR500GLContext_boundSurface);
            uVar6 = M<UInt32>(iVar3 + 0xb80);
            M<UInt32>(iVar3 + 0xb80) = M<UInt32>(iVar3 + 0xb84);
            M<UInt32>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0xb84) = uVar6;
            piVar5 = M<int *>(self + kIOATIR500GLContext_accelerator);
            if ((1 << (flipPanel & 0x3f) & piVar5[0x34]) != 0) {
              VCALL(*M<int *>(self + kIOATIR500GLContext_boundSurface), 0x5e0)(M<int *>(self + kIOATIR500GLContext_boundSurface),flipPanel,self,0)
              ;
              M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) + 1;
              piVar5 = M<int *>(self + kIOATIR500GLContext_accelerator);
            }
          }
          else {
submitFlips:
            panel = 0;
            iVar3 = 0;
            while( true ) {
              swapArg = swapRequest;
              if ((M<char>((int)piVar5 + iVar3 + 0xcac) != '\0') ||
                 (swapArg = swapRequest & 1, swapArg != 0)) {
                VCALL(*piVar5, 0x5d8)(piVar5,panel,swapArg,self);
                M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x74c) + 1;
              }
              piVar5 = M<int *>(self + kIOATIR500GLContext_accelerator);
              panel = panel + 1;
              iVar3 = iVar3 + 0x94;
              if (((unsigned int)piVar5[0x33] <= panel) || (swapRequest = swapRequest & 0xfffffffe, swapRequest == 0))
              break;
              piVar5 = M<int *>(self + kIOATIR500GLContext_boundSurface);
            }
          }
          if (M<SInt16>(self + kIOATIR500GLContext_swapIntervalDenominator) == 0) goto noStampRecord;
          iVar3 = M<int>(self + 0xa8);
          recordSwapStamp = true;
          M<UInt32>(self + iVar3 * 4 + 0x9c) = M<UInt32>(M<int>(self + kIOATIR500GLContext_boundSurface) + 0x84);
          M<unsigned int>(self + 0xa8) = (iVar3 + 1U) % 3;
        }
        if ((unsigned int)piVar5[0x172] < M<unsigned int>(self + kIOATIR500GLContext_commandBufferSizeHint)) {
          piVar5[0x172] = M<unsigned int>(self + kIOATIR500GLContext_commandBufferSizeHint);
          piVar5 = M<int *>(self + kIOATIR500GLContext_accelerator);
        }
        ringSlot = piVar5 + (unsigned int)M<UInt16>(piVar5 + 0x100) * 7 + 0x90;
        iVar3 = VCALL(*piVar5, 0x554)(piVar5,ringSlot[4]);
        if (iVar3 == 0) {
          accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
          if (M<UInt16>(accel + 0x402) < 0x10) {
            iVar3 = ((IOATIR500Accelerator *)(accel))->allocMoreCommandBuffers(0,M<UInt32>(accel + 0x5c8));
            if (iVar3 != 0) {
              iVar3 = M<int>(self + kIOATIR500GLContext_accelerator);
              ringSlot = (int *)(iVar3 + (unsigned int)M<UInt16>(iVar3 + 0x400) * 0x1c + 0x240);
              goto advanceRing;
            }
            accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
          }
          iVar9 = M<int>(accel + 0x770);
          iVar3 = VCALL(M<int>(accel), 0x54c)(accel,ringSlot[4]);
          M<int>(accel + 0x770) = iVar9 + iVar3;
          iVar3 = M<int>(self + kIOATIR500GLContext_accelerator);
        }
        else {
          iVar3 = M<int>(self + kIOATIR500GLContext_accelerator);
        }
advanceRing:
        M<UInt16>(iVar3 + 0x400) = M<SInt16>(iVar3 + 0x400) + 1U & M<SInt16>(iVar3 + 0x402) - 1U
        ;
        cmdBufBlock[3] = M<int>(self + kIOATIR500GLContext_commandBufferState);
        cmdBufBlock[4] = M<int>(self + kIOATIR500GLContext_commandBufferStamp);
        cmdBufBlock[5] = M<int>(self + kIOATIR500GLContext_commandBufferHeader);
        cmdBufBlock[6] = M<int>(self + kIOATIR500GLContext_commandBufferSize);
        cmdBufBlock[0] = M<int>(self + kIOATIR500GLContext_commandBuffer);
        cmdBufBlock[1] = M<int>(self + kIOATIR500GLContext_commandBufferGartOffset);
        cmdBufBlock[2] = M<int>(self + kIOATIR500GLContext_commandBufferDescriptor);
        iVar3 = ringSlot[1];
        iVar9 = ringSlot[2];
        iVar10 = ringSlot[3];
        M<int>(self + kIOATIR500GLContext_commandBuffer) = *ringSlot;
        M<int>(self + kIOATIR500GLContext_commandBufferGartOffset) = iVar3;
        M<int>(self + kIOATIR500GLContext_commandBufferDescriptor) = iVar9;
        M<int>(self + kIOATIR500GLContext_commandBufferState) = iVar10;
        iVar3 = ringSlot[5];
        iVar9 = ringSlot[6];
        M<int>(self + kIOATIR500GLContext_commandBufferStamp) = ringSlot[4];
        M<int>(self + kIOATIR500GLContext_commandBufferHeader) = iVar3;
        M<int>(self + kIOATIR500GLContext_commandBufferSize) = iVar9;
        *ringSlot = cmdBufBlock[0];
        ringSlot[1] = cmdBufBlock[1];
        ringSlot[2] = cmdBufBlock[2];
        ringSlot[3] = cmdBufBlock[3];
        ringSlot[4] = cmdBufBlock[4];
        ringSlot[5] = cmdBufBlock[5];
        ringSlot[6] = cmdBufBlock[6];
        accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
        if (M<int>(self + kIOATIR500GLContext_commandBufferSize) != M<int>(accel + 0x5c8)) {
          cmdBufBlock[3] = 0x10000;
          cmdBufBlock[6] = 0;
          cmdBufBlock[0] = 0;
          cmdBufBlock[1] = 0;
          cmdBufBlock[2] = 0;
          cmdBufBlock[4] = 0;
          cmdBufBlock[5] = 0;
          iVar3 = ((IOATIR500Accelerator *)(accel))->allocCommandBuffer((VendorCommandBuffer *)((UInt8 *)&cmdBufBlock[0]),M<UInt32>(accel + 0x5c8));
          if (iVar3 == 0) {
            accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
          }
          else {
            this->freeCommandBuffer();
            ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
            accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
            M<int>(self + kIOATIR500GLContext_commandBufferGartOffset) = cmdBufBlock[1];
            M<int>(self + kIOATIR500GLContext_commandBufferDescriptor) = cmdBufBlock[2];
            M<int>(self + kIOATIR500GLContext_commandBufferState) = cmdBufBlock[3];
            M<int>(self + kIOATIR500GLContext_commandBufferStamp) = cmdBufBlock[4];
            M<int>(self + kIOATIR500GLContext_commandBufferHeader) = cmdBufBlock[5];
            M<int>(self + kIOATIR500GLContext_commandBufferSize) = cmdBufBlock[6];
            M<int>(self + kIOATIR500GLContext_commandBuffer) = cmdBufBlock[0];
          }
        }
        M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = M<UInt32>(self + kIOATIR500GLContext_lastSubmitStamp);
        if (accel[0x88] == 0x0) {
          VCALL(*M<int *>(accel + 0xc0), 300)
                    (M<int *>(accel + 0xc0),M<UInt32>(accel + 0x8c));
          M<UInt8>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x88) = 1;
        }
        else {
          accel[0x89] = 0x1;
        }
        goto finishCommandBuffer;
      }
      VCALL(M<int>(surface), 0x14)(surface);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
      ((IOATIR500Surface *)(surface))->sleep_blocked();
      VCALL(M<int>(surface), 0x18)(surface);
    } while( true );
  case 2:
    GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
    VCALL(*M<int *>(self + kIOATIR500GLContext_contextBufferDescriptor), 0x14)(M<int *>(self + kIOATIR500GLContext_contextBufferDescriptor));
    *options = 0;
    *memory = (IOMemoryDescriptor *)(M<UInt8 *>(self + kIOATIR500GLContext_contextBufferDescriptor));
    this->init_context_buffer_header((VendorContextBufferHeader *)(M<VendorContextBufferHeader *>(self + kIOATIR500GLContext_contextBufferHeader)),0x8000);
    GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
    return 0;
  case 3:
    if (M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xb0) != (int *)0x0) {
      VCALL(*M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xb0), 0x14)(M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xb0));
      *options = 0;
      *memory = (IOMemoryDescriptor *)(M<UInt8 *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xb0));
      return 0;
    }
    break;
  case 4:
    if (M<int>(self + kIOATIR500GLContext_statusDescriptor) == 0) {
      M<int>(self + kIOATIR500GLContext_statusRegionSize) = GH_page_size;
      piVar5 = (int *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,iVar3,GH_page_size);
      M<int *>(self + kIOATIR500GLContext_statusDescriptor) = piVar5;
      if (piVar5 != (int *)0x0) {
        uVar6 = VCALL(*piVar5, 0x1cc)(piVar5);
        M<UInt32>(self + kIOATIR500GLContext_statusRegion) = uVar6;
retainDescriptor:
        VCALL(*M<int *>(self + kIOATIR500GLContext_statusDescriptor), 0x14)(M<int *>(self + kIOATIR500GLContext_statusDescriptor));
        *options = 0;
        *memory = (IOMemoryDescriptor *)(M<UInt8 *>(self + kIOATIR500GLContext_statusDescriptor));
        return 0;
      }
    }
    else {
      iVar3 = M<int>(self + kIOATIR500GLContext_statusRegionSize);
      piVar5 = (int *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,iVar3 << 1,GH_page_size);
      if (piVar5 != (int *)0x0) {
        uVar6 = VCALL(*piVar5, 0x1cc)(piVar5);
        GH_memcpy(uVar6,M<UInt32>(self + kIOATIR500GLContext_statusRegion),M<UInt32>(self + kIOATIR500GLContext_statusRegionSize));
        VCALL(*M<int *>(self + kIOATIR500GLContext_statusDescriptor), 0x18)(M<int *>(self + kIOATIR500GLContext_statusDescriptor));
        M<int *>(self + kIOATIR500GLContext_statusDescriptor) = piVar5;
        M<int>(self + kIOATIR500GLContext_statusRegionSize) = iVar3 << 1;
        M<UInt32>(self + kIOATIR500GLContext_statusRegion) = uVar6;
        goto retainDescriptor;
      }
    }
    break;
  default:
    return 0xe00002c2;
  }
  return 0xe00002be;
}
