/*
 * ATIR500DVDContext_discard_command_buffer_Port.cpp
 *
 * ATIR500DVDContext::discard_command_buffer (real addr 0x33c30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_OSAddAtomic(...) asm("_OSAddAtomic");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");


/* real addr 0x33c30 */
void ATIR500DVDContext::discard_command_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 slotOffset;
  SInt32 oldRefCount;
  SInt32 iVar4;
  UInt32 recordLength;
  UInt32 recordWord;
  UInt32 *record;
  
  record = (UInt32 *)(M<SInt32>(self + kIOATIR500DVDContext_commandBufferHeader) + 0x1c);
  do {
    recordWord = *record;
    uVar1 = recordWord & 0xff000000;
    if (uVar1 == 0x2a000000) {
LAB_00033ed0:
      if ((record[1] < M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_sharedAllocator) + 0x14)) &&
         (iVar4 = M<SInt32>(record[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_sharedAllocator) + 0x10)), iVar4 != 0)) {
        slotOffset = (uVar1 + 0xe7000000 >> 0x18) * 4;
        if ((M<SInt32>(self + slotOffset + 0x104) != 0) &&
           (oldRefCount = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(self + slotOffset + 0x104) + 0x14) + 0x10), oldRefCount == 1
           )) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500DVDContext_sharedAllocator)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + slotOffset + 0x104)));
        }
        GH_OSAddAtomic(0xffff0001,M<SInt32>(iVar4 + 0x14) + 0x10);
        recordLength = recordWord & 0xffffff;
        M<SInt32>(self + slotOffset + 0x104) = iVar4;
      }
      else {
        recordLength = 0;
      }
    }
    else {
      if (uVar1 < 0x2a000001) {
        if (uVar1 != 0x21000000) {
          if (uVar1 < 0x21000001) {
            if (uVar1 != 0x1c000000) {
              if (uVar1 < 0x1c000001) {
                if (((uVar1 != 0x1a000000) && (uVar1 != 0x1b000000)) && (uVar1 != 0x19000000))
                goto LAB_00033ec0;
              }
              else if (uVar1 != 0x1e000000) {
                if (uVar1 < 0x1e000001) {
                  if (uVar1 == 0x1d000000) goto LAB_00033ed0;
                }
                else if ((uVar1 == 0x1f000000) || (uVar1 == 0x20000000)) goto LAB_00033ed0;
                goto LAB_00033ec0;
              }
            }
          }
          else if (uVar1 != 0x25000000) {
            if (uVar1 < 0x25000001) {
              if (((uVar1 != 0x23000000) && (uVar1 != 0x24000000)) && (uVar1 != 0x22000000))
              goto LAB_00033ec0;
            }
            else if (uVar1 != 0x27000000) {
              if (uVar1 < 0x27000001) {
                if (uVar1 == 0x26000000) goto LAB_00033ed0;
              }
              else if ((uVar1 == 0x28000000) || (uVar1 == 0x29000000)) goto LAB_00033ed0;
              goto LAB_00033ec0;
            }
          }
        }
        goto LAB_00033ed0;
      }
      if (uVar1 == 0x33000000) {
LAB_00033f70:
        recordLength = recordWord & 0xffffff;
        uVar1 = uVar1 + 0xd5000000 >> 0x16;
        if (M<SInt32>(self + uVar1 + 0x104) != 0) {
          iVar4 = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(self + uVar1 + 0x104) + 0x14) + 0x10);
          if (iVar4 == 1) {
            ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500DVDContext_sharedAllocator)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + uVar1 + 0x104)));
          }
          recordLength = recordWord & 0xffffff;
          M<UInt32>(self + uVar1 + 0x104) = 0;
        }
      }
      else {
        if (uVar1 < 0x33000001) {
          if (uVar1 != 0x2e000000) {
            if (uVar1 < 0x2e000001) {
              if (((uVar1 != 0x2c000000) && (uVar1 != 0x2d000000)) && (uVar1 != 0x2b000000))
              goto LAB_00033ec0;
            }
            else if (uVar1 != 0x30000000) {
              if (uVar1 < 0x30000001) {
                if (uVar1 == 0x2f000000) goto LAB_00033f70;
              }
              else if ((uVar1 == 0x31000000) || (uVar1 == 0x32000000)) goto LAB_00033f70;
              goto LAB_00033ec0;
            }
          }
          goto LAB_00033f70;
        }
        if (uVar1 == 0x38000000) goto LAB_00033f70;
        if (uVar1 < 0x38000001) {
          if (uVar1 != 0x35000000) {
            if (uVar1 < 0x35000001) {
              if (uVar1 == 0x34000000) goto LAB_00033f70;
            }
            else if ((uVar1 == 0x36000000) || (uVar1 == 0x37000000)) goto LAB_00033f70;
            goto LAB_00033ec0;
          }
          goto LAB_00033f70;
        }
        if (uVar1 == 0x3a000000) goto LAB_00033f70;
        if (uVar1 < 0x3a000001) {
          if (uVar1 == 0x39000000) goto LAB_00033f70;
        }
        else if ((uVar1 == 0x3b000000) || (uVar1 == 0x3c000000)) goto LAB_00033f70;
LAB_00033ec0:
        recordLength = recordWord & 0xffffff;
      }
    }
    record = record + recordLength;
    if (recordLength == 0) {
      return;
    }
  } while( true );
}
