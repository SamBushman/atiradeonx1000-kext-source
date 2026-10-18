/*
 * IOATIR500GLContext_get_data_buffer_Port.cpp
 *
 * IOATIR500GLContext::get_data_buffer (real addr 0x9a30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x9a30 */
IOReturn IOATIR500GLContext::get_data_buffer(unsigned int*outHandle, UInt32*outAddress) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  int iVar1;
  UInt8 *accel;
  unsigned int commandBytes;
  int *piVar4;
  int iVar5;
  UInt8 *buffer;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
  if (M<int>(self + kIOATIR500GLContext_dataBufferListTail) != 0) {
    commandBytes = M<int>(M<int>(self + kIOATIR500GLContext_contextBufferHeader) + 0xc) * 4;
    if (((unsigned int)(M<int>(M<int>(self + kIOATIR500GLContext_dataBufferListTail) + 0x50) - GH_page_size) < commandBytes) &&
       (M<unsigned int>(self + kIOATIR500GLContext_dataBufferSizeHint) < 0x80000)) {
      M<unsigned int>(self + kIOATIR500GLContext_dataBufferSizeHint) = M<unsigned int>(self + kIOATIR500GLContext_dataBufferSizeHint) << 1;
    }
    M<unsigned int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x70c) = commandBytes + M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x70c);
  }
  accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
  if (M<unsigned int>(accel + kIOATIR500Accelerator_dataBufferSizeThreshold) < M<unsigned int>(self + kIOATIR500GLContext_dataBufferSizeHint)) {
    M<unsigned int>(accel + kIOATIR500Accelerator_dataBufferSizeThreshold) = M<unsigned int>(self + kIOATIR500GLContext_dataBufferSizeHint);
    accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
  }
  buffer = M<UInt8 *>(accel + kIOATIR500Accelerator_dataBufferCacheHead);
  if (buffer == (UInt8 *)0x0) {
    buffer = (UInt8 *)
             ((IOATIR500Accelerator *)(accel))->allocOneDataBuffer(M<UInt32>(accel + kIOATIR500Accelerator_dataBufferSizeThreshold), true);
    if (buffer == (UInt8 *)0x0) {
      GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
      *outHandle = 0;
      *outAddress = 0;
      return 0xe00002be;
    }
  }
  else {
    iVar1 = VCALL(M<int>(accel), 0x554)(accel,M<UInt32>(buffer + 0x5c));
    if ((iVar1 == 0) &&
       (buffer = (UInt8 *)
                 ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->allocOneDataBuffer(M<UInt32>(M<UInt8 *>(self + kIOATIR500GLContext_accelerator) + 0x5d8),true),
       buffer == (UInt8 *)0x0)) {
      piVar4 = M<int *>(self + kIOATIR500GLContext_accelerator);
      buffer = (UInt8 *)piVar4[0x173];
      iVar5 = piVar4[0x1de];
      iVar1 = VCALL(*piVar4, 0x54c)(piVar4,M<UInt32>(buffer + 0x5c));
      piVar4[0x1de] = iVar5 + iVar1;
    }
  }
  if (buffer != M<UInt8 *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5cc)) goto LAB_00009fd0;
  M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5cc) = M<UInt32>(buffer + 0x3c);
  if (M<int>(buffer + 0x3c) == 0) {
    M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d0) = 0;
  }
  else {
    M<UInt32>(buffer + 0x3c) = 0;
  }
  M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d4) = M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d4) + -1;
  accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
  if (M<int>(buffer + 0x50) != M<int>(accel + kIOATIR500Accelerator_dataBufferSizeThreshold)) {
    piVar4 = M<int *>(buffer + 8);
    if (piVar4 != (int *)0x0) {
      if (M<int>(buffer + 4) != 0) {
        VCALL(M<int>(accel), 0x5ac)(accel,buffer);
        piVar4 = M<int *>(buffer + 8);
      }
      VCALL(*piVar4, 0x18)(piVar4);
      M<UInt32>(buffer + 8) = 0;
    }
    if (M<int>(buffer + 0x48) != 0) {
      VCALL(*M<int *>(self + kIOATIR500GLContext_accelerator), 0x524)(M<int *>(self + kIOATIR500GLContext_accelerator),buffer);
      iVar5 = M<int>(buffer + 0x24);
      M<UInt32>(iVar5 + 0x28) = M<UInt32>(buffer + 0x28);
      iVar1 = M<int>(buffer + 0x28);
      M<UInt8 *>(buffer + 0x28) = buffer;
      M<int>(iVar1 + 0x24) = iVar5;
      M<UInt8 *>(buffer + 0x24) = buffer;
    }
    if (M<int *>(buffer + 0x10) != (int *)0x0) {
      VCALL(*M<int *>(buffer + 0x10), 0x18)(M<int *>(buffer + 0x10));
      M<UInt32>(buffer + 0x10) = 0;
    }
    M<UInt32>(buffer + 0x50) = M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x5d8);
    accel = M<UInt8 *>(self + kIOATIR500GLContext_accelerator);
  }
  if (accel[0x80] == 0x0) {
    if (M<int>(buffer + 8) == 0) {
      iVar1 = ((IOATIR500Accelerator *)(accel))->allocDataBufferBacking((VendorTextureBuffer *)(buffer));
      if (iVar1 == 0) {
LAB_00009e94:
        ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeOneDataBuffer((VendorTextureBuffer *)(buffer));
        GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
        *outHandle = 0;
        *outAddress = 0;
        return 0xe00002be;
      }
      if (M<int>(buffer + 0x48) != 0) {
        if (M<int *>(buffer + 0x10) != (int *)0x0) {
          iVar1 = VCALL(*M<int *>(buffer + 0x10), 0xdc)(M<int *>(buffer + 0x10));
          if (iVar1 == M<int>(self + kIOATIR500GLContext_task)) {
            VCALL(*M<int *>(buffer + 0x10), 0xf0)
                      (M<int *>(buffer + 0x10),M<UInt32>(buffer + 8),0x400,0);
          }
          else {
            VCALL(*M<int *>(buffer + 0x10), 0x18)(M<int *>(buffer + 0x10));
            M<UInt32>(buffer + 0x10) = 0;
          }
        }
        VCALL(*M<int *>(self + kIOATIR500GLContext_accelerator), 0x524)(M<int *>(self + kIOATIR500GLContext_accelerator),buffer);
        iVar5 = M<int>(buffer + 0x24);
        M<UInt32>(iVar5 + 0x28) = M<UInt32>(buffer + 0x28);
        iVar1 = M<int>(buffer + 0x28);
        M<UInt8 *>(buffer + 0x28) = buffer;
        M<int>(iVar1 + 0x24) = iVar5;
        M<UInt8 *>(buffer + 0x24) = buffer;
      }
      goto LAB_00009fd0;
    }
  }
  else if (M<int>(buffer + 0x48) == 0) {
    iVar1 = VCALL(M<int>(accel), 0x528)(accel,buffer);
    if (iVar1 != 0) {
      if (M<int>(buffer + 0x48) != 0) {
        iVar1 = M<int>(buffer + 0x24);
        M<UInt32>(iVar1 + 0x28) = M<UInt32>(buffer + 0x28);
        M<int>(M<int>(buffer + 0x28) + 0x24) = iVar1;
        M<UInt32>(buffer + 0x24) = M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x600);
        M<int>(buffer + 0x28) = M<int>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
        M<UInt8 *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x600) = buffer;
        M<UInt8 *>(M<int>(buffer + 0x24) + 0x28) = buffer;
      }
      piVar4 = M<int *>(self + kIOATIR500GLContext_accelerator);
      VCALL(*piVar4, 0x54c)(piVar4,piVar4[0x14] + -1);
      if (M<int>(buffer + 8) != 0) {
        if (M<int *>(buffer + 0x10) != (int *)0x0) {
          iVar1 = VCALL(*M<int *>(buffer + 0x10), 0xdc)(M<int *>(buffer + 0x10));
          if (iVar1 == M<int>(self + kIOATIR500GLContext_task)) {
            VCALL(*M<int *>(buffer + 0x10), 0xf0)
                      (M<int *>(buffer + 0x10),M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xdc),0x400,
                       M<UInt32>(buffer + 0x48));
          }
          else {
            VCALL(*M<int *>(buffer + 0x10), 0x18)(M<int *>(buffer + 0x10));
            M<UInt32>(buffer + 0x10) = 0;
          }
        }
        if (M<int>(buffer + 4) != 0) {
          VCALL(*M<int *>(self + kIOATIR500GLContext_accelerator), 0x5ac)(M<int *>(self + kIOATIR500GLContext_accelerator),buffer);
        }
        VCALL(*M<int *>(buffer + 8), 0x18)(M<int *>(buffer + 8));
        M<UInt32>(buffer + 8) = 0;
      }
      goto LAB_00009fd0;
    }
    if (M<int>(buffer + 8) == 0) {
      iVar1 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->allocDataBufferBacking((VendorTextureBuffer *)(buffer));
      if (iVar1 == 0) goto LAB_00009e94;
      goto LAB_00009fd0;
    }
  }
  if ((M<int *>(buffer + 0x10) != (int *)0x0) &&
     (iVar1 = VCALL(*M<int *>(buffer + 0x10), 0xdc)(M<int *>(buffer + 0x10)), iVar1 != M<int>(self + kIOATIR500GLContext_task))) {
    VCALL(*M<int *>(buffer + 0x10), 0x18)(M<int *>(buffer + 0x10));
    M<UInt32>(buffer + 0x10) = 0;
  }
LAB_00009fd0:
  buffer[0x54] = 0x1;
  if (M<int>(self + kIOATIR500GLContext_dataBufferListTail) == 0) {
    M<UInt8 *>(self + kIOATIR500GLContext_dataBufferListHead) = buffer;
    M<UInt8 *>(self + kIOATIR500GLContext_dataBufferListTail) = buffer;
  }
  else {
    M<UInt8 *>(M<int>(self + kIOATIR500GLContext_dataBufferListTail) + 0x3c) = buffer;
    M<UInt8 *>(self + kIOATIR500GLContext_dataBufferListTail) = buffer;
  }
  M<int>(self + kIOATIR500GLContext_dataBufferCount) = M<int>(self + kIOATIR500GLContext_dataBufferCount) + 1;
  M<UInt32>(buffer + 0x5c) = M<UInt32>(self + kIOATIR500GLContext_lastSubmitStamp);
  M<UInt8 *>(M<int>(self + kIOATIR500GLContext_contextBufferHeader) + 8) = buffer;
  piVar4 = M<int *>(buffer + 0x10);
  if (piVar4 == (int *)0x0) {
    if (M<int>(buffer + 0x48) == 0) {
      piVar4 = (int *)VCALL(*M<int *>(buffer + 8), 0x14c)
                                (M<int *>(buffer + 8),M<UInt32>(self + kIOATIR500GLContext_task),0,0x4000401,0,
                                 M<UInt32>(buffer + 0x50));
    }
    else {
      piVar4 = (int *)VCALL(*M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xdc), 0x14c)
                                (M<int *>(M<int>(self + kIOATIR500GLContext_accelerator) + 0xdc),M<UInt32>(self + kIOATIR500GLContext_task)
                                 ,0,0x4000401,M<int>(buffer + 0x48),M<UInt32>(buffer + 0x50)
                                );
    }
    if (piVar4 == (int *)0x0) {
      *outHandle = 0;
      *outAddress = 0;
      return 0xe00002be;
    }
    M<int *>(buffer + 0x10) = piVar4;
  }
  commandBytes = VCALL(*piVar4, 0xd0)(piVar4);
  *outHandle = commandBytes;
  *outAddress = M<UInt32>(buffer + 0x50);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x840));
  return 0;
}
