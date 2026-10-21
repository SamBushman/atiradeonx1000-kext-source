/*
 * IOATIR500Surface_surface_lock_options_Port.cpp
 *
 * IOATIR500Surface::surface_lock_options (real addr 0x15d30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_bzero(...) asm("_bzero");


/* real addr 0x15d30 */
IOReturn IOATIR500Surface::surface_lock_options(eLockType lockType, UInt32 lockOptions, IOAccelSurfaceData *data, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *selfBytes = reinterpret_cast<UInt8 *>(this);
    int *dataRaw = reinterpret_cast<int *>(data);

  bool buffersResident;
  bool stampPending;
  unsigned int neededBuffers;
  int *accelerator;
  UInt32 mapping;
  UInt8 newLockState;
  UInt8 *surfaceBuffer;
  int result;
  UInt8 isReadLock;
  int memoryState [7];
  unsigned int stateBits;
  unsigned int pixelFormat;
  int transferBuffer;
  int waitTime;
  int copyOk;
  int mapAddress;
  int dataWord16;
  
  isReadLock = (lockType == 1) << 1;
  GH_bzero(dataRaw,0x44);
  GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x840));
  if ((bool)(isReadLock >> 1 & 1)) {
    newLockState = self[0xbd0];
  }
  else {
    newLockState = self[0xbd1];
  }
  surfaceBuffer = M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffers);
  if (newLockState != 0x0) {
    stampPending = false;
    result = -0x1ffffd34;
    goto unlockAndReturn;
  }
  stateBits = M<unsigned int>(self + kIOATIR500Surface_stateBits);
  if ((stateBits & 0x20000000) != 0) {
rejectLock:
    stampPending = false;
    newLockState = 0x0;
    result = -0x1ffffd34;
    goto unlockAndReturn;
  }
  if (((((bool)(isReadLock >> 1 & 1)) && ((M<unsigned int>(self + kIOATIR500Surface_contextReqBits) & 0x7ffc00) != 0)) &&
      (M<int>(self + kIOATIR500Surface_boundDVDContext) != 0)) && (self[0xbf0] != 0x0)) {
    lockOptions = lockOptions | 3;
  }
  else if (M<int>(surfaceBuffer + 0x10) == 0) goto rejectLock;
  transferBuffer = M<int>(surfaceBuffer + 0x24);
  neededBuffers = M<unsigned int>(self + kIOATIR500Surface_reqBits) & 3;
  if ((transferBuffer == 0) || (stampPending = true, M<int>(transferBuffer + 0x54) != M<int>(self + kIOATIR500Surface_stamp))) {
    stampPending = false;
  }
  lockOptions = lockOptions & 3;
  buffersResident = (stateBits & neededBuffers) == 0;
  if (lockOptions == 1) {
    if ((((lockType != 2) && (!buffersResident)) && (!stampPending)) || (self[0xbf4] == 0x0))
    goto lockWithoutMapping;
lockResidentBuffer:
    self[0xc08] = 0x1;
    if ((neededBuffers & stateBits) == 0) {
      result = 0;
    }
    else {
      result = this->alloc_surfaces_retry(neededBuffers,(eLockType)(lockType));
      if (result != 0) {
allocFailed:
        stampPending = false;
        newLockState = 0x0;
        goto unlockAndReturn;
      }
    }
    dataRaw[4] = (unsigned int)M<UInt16>(surfaceBuffer + 0x18);
    *dataRaw = M<int>(surfaceBuffer + 8) + M<int>(self + kIOATIR500Surface_userMapAddress);
    VCALL(M<int>(self), 0x5fc)(self,surfaceBuffer);
    if ((bool)(isReadLock >> 1 & 1)) {
      stampPending = false;
      waitTime = VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x558)
                        (M<int *>(self + kIOATIR500Surface_accelerator),M<UInt32>(self + kIOATIR500Surface_stamp));
      newLockState = 0x1;
      M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x7b8) =
           waitTime + M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x7b8);
    }
    else {
      accelerator = M<int *>(self + kIOATIR500Surface_accelerator);
      stampPending = false;
      waitTime = VCALL(*accelerator, 0x558)(accelerator,accelerator[0x14] + -1);
      newLockState = 0x1;
      M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x7bc) =
           waitTime + M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x7bc);
    }
  }
  else {
    if (lockOptions == 0) {
      if (((lockType == 2) || (buffersResident)) || (stampPending)) goto lockViaTransferBuffer;
    }
    else {
      if (lockOptions == 2) {
        if ((!stampPending) || (M<char>(transferBuffer + 0x58) == '\0')) {
          if ((buffersResident) && (self[0xbf4] != 0x0)) goto lockResidentBuffer;
          if (((lockType != 2) && (!buffersResident)) && (!stampPending)) goto lockWithoutMapping;
        }
lockViaTransferBuffer:
        if ((self[0xbf7] == 0x0) || (self[0xc08] != 0x0))
        goto checkTransferBuffer;
        if (transferBuffer == 0) {
noTransferBuffer:
          result = 0;
moveToBackingStore:
          if (M<int>(surfaceBuffer + 8) != 0) {
            if ((bool)(isReadLock >> 1 & 1)) {
              copyOk = this->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            else {
              copyOk = this->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            if (copyOk == 0) {
              stampPending = false;
              newLockState = 0x3;
              result = -0x1ffffd38;
              goto unlockAndReturn;
            }
          }
          stampPending = true;
        }
        else {
          if (M<int>(transferBuffer + 8) != 0) {
            memoryState[0] = 2;
            result = VCALL(*M<int *>(M<int>(surfaceBuffer + 0x24) + 8), 0xdc)
                               (M<int *>(M<int>(surfaceBuffer + 0x24) + 8),2,memoryState);
            if (result == 0) {
              if ((buffersResident) && (memoryState[0] == 4)) {
                transferBuffer = M<int>(surfaceBuffer + 0x24);
                if (M<int>(transferBuffer + 0x54) == M<int>(self + kIOATIR500Surface_stamp)) {
                  M<UInt8>(transferBuffer + 0x58) = 0;
                  transferBuffer = M<int>(surfaceBuffer + 0x24);
                }
              }
              else {
                transferBuffer = M<int>(surfaceBuffer + 0x24);
              }
              if (M<int *>(transferBuffer + 0x10) == (int *)0x0) goto checkTransferStamp;
              VCALL(*M<int *>(transferBuffer + 0x10), 0x18)(M<int *>(transferBuffer + 0x10));
              M<UInt32>(M<int>(surfaceBuffer + 0x24) + 0x10) = 0;
              transferBuffer = M<int>(surfaceBuffer + 0x24);
            }
            else {
              transferBuffer = M<int>(surfaceBuffer + 0x24);
            }
checkTransferBuffer:
            if (transferBuffer == 0) goto noTransferBuffer;
          }
checkTransferStamp:
          if ((M<int>(transferBuffer + 0x54) == M<int>(self + kIOATIR500Surface_stamp)) &&
             (M<char>(transferBuffer + 0x58) == '\0')) {
            if ((bool)(isReadLock >> 1 & 1)) {
              self[0xbd0] = 0x3;
            }
            else {
              self[0xbd1] = 0x3;
            }
            result = this->alloc_surfaces_retry(neededBuffers,(eLockType)(lockType));
            if ((bool)(isReadLock >> 1 & 1)) {
              self[0xbd0] = 0x0;
            }
            else {
              self[0xbd1] = 0x0;
            }
            if (result != 0) goto allocFailed;
            transferBuffer = M<int>(surfaceBuffer + 0x24);
          }
          else {
            result = 0;
          }
          if (((transferBuffer == 0) || (M<int>(transferBuffer + 0x54) != M<int>(self + kIOATIR500Surface_stamp))) ||
             (stampPending = false, M<char>(transferBuffer + 0x58) == '\0')) goto moveToBackingStore;
        }
        if (lockType == 2) {
          VCALL(M<int>(self), 0x5cc)
                    (self,((int)surfaceBuffer - (int)(self + kIOATIR500Surface_buffers) >> 3) * -0x11111111);
        }
        transferBuffer = M<int>(surfaceBuffer + 0x24);
        if (transferBuffer == 0) {
failNoTransferBuffer:
          newLockState = 0x0;
          result = -0x1ffffd43;
          goto unlockAndReturn;
        }
        if (M<int>(transferBuffer + 0x10) == 0) {
          mapping = VCALL(*M<int *>(transferBuffer + 8), 0x14c)
                            (M<int *>(transferBuffer + 8),M<UInt32>(self + kIOATIR500Surface_task),0,1,0,0);
          M<UInt32>(transferBuffer + 0x10) = mapping;
          transferBuffer = M<int>(surfaceBuffer + 0x24);
          if (M<int>(transferBuffer + 0x10) == 0) goto failNoTransferBuffer;
          if (M<char>(transferBuffer + 0x59) == '\0') {
            self[0xc09] = 0x1;
            transferBuffer = M<int>(surfaceBuffer + 0x24);
          }
        }
        dataRaw[4] = (unsigned int)M<UInt16>(transferBuffer + 0x52);
        mapAddress = VCALL(*M<int *>(M<int>(surfaceBuffer + 0x24) + 0x10), 0xd0)(M<int *>(M<int>(surfaceBuffer + 0x24) + 0x10));
        newLockState = 0x3;
        *dataRaw = mapAddress + (unsigned int)M<UInt16>(M<int>(surfaceBuffer + 0x24) + 0x50);
        goto fillLockData;
      }
      if (lockOptions != 3) {
        stampPending = false;
        newLockState = 0x0;
        result = -0x1ffffd3e;
        goto unlockAndReturn;
      }
    }
lockWithoutMapping:
    stampPending = false;
    result = 0;
    newLockState = 0x2;
  }
fillLockData:
  dataRaw[5] = (unsigned int)M<UInt16>(surfaceBuffer + 0x1c);
  dataRaw[6] = (unsigned int)M<UInt16>(surfaceBuffer + 0x1e);
  pixelFormat = M<unsigned int>(self + kIOATIR500Surface_modeBits) & 0xf;
  dataRaw[7] = pixelFormat;
  if (pixelFormat == 6) {
    dataRaw[7] = 0x79757673;
  }
  else if (pixelFormat == 9) {
    dataRaw[7] = 0x32767579;
  }
  else if (pixelFormat == 10) {
    dataRaw[7] = 4;
  }
  dataRaw[8] = M<int>(self + kIOATIR500Surface_lockDataFlags);
  dataRaw[0xd] = M<int>(self + kIOATIR500Surface_lockDataWord13);
  dataRaw[0xe] = M<int>(self + kIOATIR500Surface_lockDataWord14);
  dataRaw[0xf] = M<int>(self + kIOATIR500Surface_lockDataWord15);
  dataWord16 = M<int>(self + kIOATIR500Surface_lockDataWord16);
  dataRaw[9] = 0x1cccc;
  dataRaw[0x10] = dataWord16;
unlockAndReturn:
  if ((bool)(isReadLock >> 1 & 1)) {
    self[0xbd0] = newLockState;
  }
  else {
    self[0xbd1] = newLockState;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x840));
  if (stampPending) {
    VCALL(*M<int *>(self + kIOATIR500Surface_accelerator), 0x558)
              (M<int *>(self + kIOATIR500Surface_accelerator),M<UInt32>(self + kIOATIR500Surface_stamp));
  }
  return result;
}
