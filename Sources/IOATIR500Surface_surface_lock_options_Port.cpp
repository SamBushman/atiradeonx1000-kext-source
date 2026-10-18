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
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    int *dataRaw = reinterpret_cast<int *>(data);

  bool buffersResident;
  bool stampPending;
  unsigned int neededBuffers;
  int *accelerator;
  UInt32 mapping;
  unsigned int uVar6;
  UInt8 newLockState;
  int iVar8;
  UInt8 *surfaceBuffer;
  int result;
  UInt8 isReadLock;
  int memoryState [7];
  
  isReadLock = (lockType == 1) << 1;
  GH_bzero(dataRaw,0x44);
  GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
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
    goto LAB_00016360;
  }
  uVar6 = M<unsigned int>(self + 0xbf8);
  if ((uVar6 & 0x20000000) != 0) {
LAB_00016330:
    stampPending = false;
    newLockState = 0x0;
    result = -0x1ffffd34;
    goto LAB_00016360;
  }
  if (((((bool)(isReadLock >> 1 & 1)) && ((M<unsigned int>(self + 0xc18) & 0x7ffc00) != 0)) &&
      (M<int>(self + 0x90) != 0)) && (self[0xbf0] != 0x0)) {
    lockOptions = lockOptions | 3;
  }
  else if (M<int>(surfaceBuffer + 0x10) == 0) goto LAB_00016330;
  iVar8 = M<int>(surfaceBuffer + 0x24);
  neededBuffers = M<unsigned int>(self + 0xc1c) & 3;
  if ((iVar8 == 0) || (stampPending = true, M<int>(iVar8 + 0x54) != M<int>(self + 0x7c))) {
    stampPending = false;
  }
  lockOptions = lockOptions & 3;
  buffersResident = (uVar6 & neededBuffers) == 0;
  if (lockOptions == 1) {
    if ((((lockType != 2) && (!buffersResident)) && (!stampPending)) || (self[0xbf4] == 0x0))
    goto LAB_00015e70;
LAB_00015ec8:
    self[0xc08] = 0x1;
    if ((neededBuffers & uVar6) == 0) {
      result = 0;
    }
    else {
      result = this->alloc_surfaces_retry(neededBuffers,(eLockType)(lockType));
      if (result != 0) {
LAB_00016344:
        stampPending = false;
        newLockState = 0x0;
        goto LAB_00016360;
      }
    }
    dataRaw[4] = (unsigned int)M<UInt16>(surfaceBuffer + 0x18);
    *dataRaw = M<int>(surfaceBuffer + 8) + M<int>(self + 0xc0c);
    VCALL(M<int>(self), 0x5fc)(self,surfaceBuffer);
    if ((bool)(isReadLock >> 1 & 1)) {
      stampPending = false;
      iVar8 = VCALL(*M<int *>(self + 0xd50), 0x558)
                        (M<int *>(self + 0xd50),M<UInt32>(self + 0x7c));
      newLockState = 0x1;
      M<int>(M<int>(self + 0xd50) + 0x7b8) =
           iVar8 + M<int>(M<int>(self + 0xd50) + 0x7b8);
    }
    else {
      accelerator = M<int *>(self + 0xd50);
      stampPending = false;
      iVar8 = VCALL(*accelerator, 0x558)(accelerator,accelerator[0x14] + -1);
      newLockState = 0x1;
      M<int>(M<int>(self + 0xd50) + 0x7bc) =
           iVar8 + M<int>(M<int>(self + 0xd50) + 0x7bc);
    }
  }
  else {
    if (lockOptions == 0) {
      if (((lockType == 2) || (buffersResident)) || (stampPending)) goto LAB_00015fe4;
    }
    else {
      if (lockOptions == 2) {
        if ((!stampPending) || (M<char>(iVar8 + 0x58) == '\0')) {
          if ((buffersResident) && (self[0xbf4] != 0x0)) goto LAB_00015ec8;
          if (((lockType != 2) && (!buffersResident)) && (!stampPending)) goto LAB_00015e70;
        }
LAB_00015fe4:
        if ((self[0xbf7] == 0x0) || (self[0xc08] != 0x0))
        goto LAB_000160bc;
        if (iVar8 == 0) {
LAB_00016170:
          result = 0;
LAB_00016174:
          if (M<int>(surfaceBuffer + 8) != 0) {
            if ((bool)(isReadLock >> 1 & 1)) {
              iVar8 = this->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            else {
              iVar8 = this->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
            }
            if (iVar8 == 0) {
              stampPending = false;
              newLockState = 0x3;
              result = -0x1ffffd38;
              goto LAB_00016360;
            }
          }
          stampPending = true;
        }
        else {
          if (M<int>(iVar8 + 8) != 0) {
            memoryState[0] = 2;
            result = VCALL(*M<int *>(M<int>(surfaceBuffer + 0x24) + 8), 0xdc)
                               (M<int *>(M<int>(surfaceBuffer + 0x24) + 8),2,memoryState);
            if (result == 0) {
              if ((buffersResident) && (memoryState[0] == 4)) {
                iVar8 = M<int>(surfaceBuffer + 0x24);
                if (M<int>(iVar8 + 0x54) == M<int>(self + 0x7c)) {
                  M<UInt8>(iVar8 + 0x58) = 0;
                  iVar8 = M<int>(surfaceBuffer + 0x24);
                }
              }
              else {
                iVar8 = M<int>(surfaceBuffer + 0x24);
              }
              if (M<int *>(iVar8 + 0x10) == (int *)0x0) goto LAB_000160c4;
              VCALL(*M<int *>(iVar8 + 0x10), 0x18)(M<int *>(iVar8 + 0x10));
              M<UInt32>(M<int>(surfaceBuffer + 0x24) + 0x10) = 0;
              iVar8 = M<int>(surfaceBuffer + 0x24);
            }
            else {
              iVar8 = M<int>(surfaceBuffer + 0x24);
            }
LAB_000160bc:
            if (iVar8 == 0) goto LAB_00016170;
          }
LAB_000160c4:
          if ((M<int>(iVar8 + 0x54) == M<int>(self + 0x7c)) &&
             (M<char>(iVar8 + 0x58) == '\0')) {
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
            if (result != 0) goto LAB_00016344;
            iVar8 = M<int>(surfaceBuffer + 0x24);
          }
          else {
            result = 0;
          }
          if (((iVar8 == 0) || (M<int>(iVar8 + 0x54) != M<int>(self + 0x7c))) ||
             (stampPending = false, M<char>(iVar8 + 0x58) == '\0')) goto LAB_00016174;
        }
        if (lockType == 2) {
          VCALL(M<int>(self), 0x5cc)
                    (self,((int)surfaceBuffer - (int)(self + 0xa8) >> 3) * -0x11111111);
        }
        iVar8 = M<int>(surfaceBuffer + 0x24);
        if (iVar8 == 0) {
LAB_00016350:
          newLockState = 0x0;
          result = -0x1ffffd43;
          goto LAB_00016360;
        }
        if (M<int>(iVar8 + 0x10) == 0) {
          mapping = VCALL(*M<int *>(iVar8 + 8), 0x14c)
                            (M<int *>(iVar8 + 8),M<UInt32>(self + 0x78),0,1,0,0);
          M<UInt32>(iVar8 + 0x10) = mapping;
          iVar8 = M<int>(surfaceBuffer + 0x24);
          if (M<int>(iVar8 + 0x10) == 0) goto LAB_00016350;
          if (M<char>(iVar8 + 0x59) == '\0') {
            self[0xc09] = 0x1;
            iVar8 = M<int>(surfaceBuffer + 0x24);
          }
        }
        dataRaw[4] = (unsigned int)M<UInt16>(iVar8 + 0x52);
        iVar8 = VCALL(*M<int *>(M<int>(surfaceBuffer + 0x24) + 0x10), 0xd0)(M<int *>(M<int>(surfaceBuffer + 0x24) + 0x10));
        newLockState = 0x3;
        *dataRaw = iVar8 + (unsigned int)M<UInt16>(M<int>(surfaceBuffer + 0x24) + 0x50);
        goto LAB_00015e7c;
      }
      if (lockOptions != 3) {
        stampPending = false;
        newLockState = 0x0;
        result = -0x1ffffd3e;
        goto LAB_00016360;
      }
    }
LAB_00015e70:
    stampPending = false;
    result = 0;
    newLockState = 0x2;
  }
LAB_00015e7c:
  dataRaw[5] = (unsigned int)M<UInt16>(surfaceBuffer + 0x1c);
  dataRaw[6] = (unsigned int)M<UInt16>(surfaceBuffer + 0x1e);
  uVar6 = M<unsigned int>(self + 0xbe8) & 0xf;
  dataRaw[7] = uVar6;
  if (uVar6 == 6) {
    dataRaw[7] = 0x79757673;
  }
  else if (uVar6 == 9) {
    dataRaw[7] = 0x32767579;
  }
  else if (uVar6 == 10) {
    dataRaw[7] = 4;
  }
  dataRaw[8] = M<int>(self + 0xd70);
  dataRaw[0xd] = M<int>(self + 0xd74);
  dataRaw[0xe] = M<int>(self + 0xd78);
  dataRaw[0xf] = M<int>(self + 0xd7c);
  iVar8 = M<int>(self + 0xd80);
  dataRaw[9] = 0x1cccc;
  dataRaw[0x10] = iVar8;
LAB_00016360:
  if ((bool)(isReadLock >> 1 & 1)) {
    self[0xbd0] = newLockState;
  }
  else {
    self[0xbd1] = newLockState;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  if (stampPending) {
    VCALL(*M<int *>(self + 0xd50), 0x558)
              (M<int *>(self + 0xd50),M<UInt32>(self + 0x7c));
  }
  return result;
}
