/*
 * IOATIR500Surface_set_id_mode_Port.cpp
 *
 * IOATIR500Surface::set_id_mode (real addr 0x142b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* real addr 0x142b0 */
IOReturn IOATIR500Surface::set_id_mode(UInt32 param_1, eIOSurfaceModeBits real_param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 param_3 = real_param_3;   /* the body edits the mode bits as a plain integer */

  UInt16 uVar1;
  UInt8 *pIVar2;
  unsigned int uVar3;
  SInt16 sVar4;
  int iVar5;
  int iVar6;
  unsigned int uVar7;
  UInt32 uVar8;
  UInt32 local_38;
  UInt32 local_34;
  UInt32 local_30;
  UInt32 local_2c;
  
  if ((param_3 & 0xffff7fc0) != 0) {
    return 0xe00002c2;
  }
  GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  if ((M<unsigned int>(self + 0xbd0) & 0xffff0000) != 0) {
    iVar5 = M<int>(self + 0xd50);
    uVar8 = 0xe00002cc;
    goto LAB_000147d0;
  }
  if (((M<int>(self + 0x90) == 0) && (M<int>(self + 0x88) == 0)) && (M<int>(self + 0x8c) == 0)
     ) {
LAB_00014370:
    if ((param_3 & 0x20) != 0) {
      uVar7 = param_1;
      param_1 = 0xffff;
LAB_00014454:
      uVar3 = M<unsigned int>(self + 0xc14);
      if (((uVar3 != 0xffff) && (param_1 != uVar3)) &&
         (self == M<UInt8 *>(uVar3 * 0x20 + M<int>(self + 0xd50) + 0xe8))) {
        VCALL(M<int>(self), 0x5a8)(self);
        M<UInt32>(M<int>(self + 0xc14) * 0x20 + M<int>(self + 0xd50) + 0xe8) = 0;
      }
      M<unsigned int>(self + 0xa4) = uVar7;
      M<unsigned int>(self + 0xbe8) = param_3;
      M<unsigned int>(self + 0xc14) = param_1;
      if ((param_1 != 0xffff) && ((param_3 & 0x8000) != 0)) {
        M<UInt8 *>(param_1 * 0x20 + M<int>(self + 0xd50) + 0xe8) = self;
      }
      M<UInt32>(self + 0xc1c) = 0x20000000;
      if ((M<unsigned int>(self + 0xbe8) & 0x20) != 0) {
        M<UInt32>(self + 0xc1c) = 0x30000000;
      }
      if ((M<unsigned int>(self + 0xbe8) & 0x30) == 0x10) {
        M<unsigned int>(self + 0xc1c) = M<unsigned int>(self + 0xc1c) | 0x20;
      }
      uVar8 = 0;
      this->reset_req_bits();
      this->reset_access();
      if ((M<unsigned int>(self + 0xbe8) & 0x20) == 0) {
        M<UInt32>(self + 0xbfc) = 0;
        iVar5 = M<int>(self + 0xc14);
        if (M<int>(self + iVar5 * 8 + 0xd64) == 0xc) {
LAB_0001460c:
          uVar8 = 0;
        }
        else {
          iVar5 = GH_IOMallocAligned(0xc,0x20);
          if (iVar5 == 0) {
            iVar5 = M<int>(self + 0xc14);
            uVar8 = 0xe00002be;
          }
          else {
            GH_IOFreeAligned(M<UInt32>(self + M<int>(self + 0xc14) * 8 + 0xd60),
                         M<UInt32>(self + M<int>(self + 0xc14) * 8 + 0xd64));
            iVar6 = M<int>(self + 0xd50);
            if (iVar6 != 0) {
              M<int>(iVar6 + 0x804) =
                   M<int>(iVar6 + 0x804) - M<int>(self + M<int>(self + 0xc14) * 8 + 0xd64);
            }
            M<int>(self + M<int>(self + 0xc14) * 8 + 0xd60) = iVar5;
            M<UInt32>(self + M<int>(self + 0xc14) * 8 + 0xd64) = 0xc;
            iVar5 = M<int>(self + 0xd50);
            if (iVar5 == 0) {
              iVar5 = M<int>(self + 0xc14);
              goto LAB_0001460c;
            }
            uVar8 = 0;
            M<int>(iVar5 + 0x804) = M<int>(iVar5 + 0x804) + 0xc;
            iVar5 = M<int>(self + 0xc14);
          }
        }
        *M<UInt32 *>(self + iVar5 * 8 + 0xd60) = 0;
        M<UInt16>(M<int>(self + M<int>(self + 0xc14) * 8 + 0xd60) + 4) = 0;
        M<UInt16>(M<int>(self + M<int>(self + 0xc14) * 8 + 0xd60) + 6) = 0;
        uVar1 = M<UInt16>(M<int>(self + 0xc14) * 0x78 + M<int>(self + 0xd50) + 0x148);
        M<UInt16>(M<int>(self + M<int>(self + 0xc14) * 8 + 0xd60) + 8) = uVar1;
        M<UInt16>(self + 0xbd4) = uVar1;
        M<UInt16>(self + 0xbd8) = uVar1;
        uVar1 = M<UInt16>(M<int>(self + 0xc14) * 0x78 + M<int>(self + 0xd50) + 0x14a);
        M<UInt16>(M<int>(self + M<int>(self + 0xc14) * 8 + 0xd60) + 10) = uVar1;
        M<UInt16>(self + 0xbd6) = uVar1;
        M<UInt16>(self + 0xbda) = uVar1;
        iVar5 = VCALL(M<int>(self), 0x5dc)(self);
        if (iVar5 == 0) {
          self[M<int>(self + 0xc14) * 0x94 + 0xcac] = 0x1;
          M<unsigned int>(self + 0xbf8) = M<unsigned int>(self + 0xbf8) | 0x10000000;
          M<unsigned int>(self + 0xc1c) = M<unsigned int>(self + 0xc1c) | 0x10000000;
        }
      }
      this->prune_buffers();
      if ((M<unsigned int>(self + 0xc1c) & 1) == 0) {
        iVar5 = 0;
        if ((M<unsigned int>(self + 0xc1c) & 2) != 0) {
          iVar5 = M<int>(self + 0x130);
        }
      }
      else {
        iVar5 = M<int>(self + 0xb8);
      }
      M<unsigned int>(self + 0xbf8) = M<unsigned int>(self + 0xbf8) & 0xdfffffff;
      if (iVar5 == 0) {
        iVar5 = M<int>(self + 0xd50);
      }
      else {
        local_2c = 0;
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        iVar5 = VCALL(*M<int *>(self + 0xd50), 0x540)
                          (M<int *>(self + 0xd50),&local_38,iVar5,0x1000);
        if (iVar5 == 0) {
          iVar5 = M<int>(self + 0xd50);
          uVar8 = 0xe00002be;
          M<unsigned int>(self + 0xbf8) = M<unsigned int>(self + 0xbf8) | 0x20000000;
        }
        else {
          VCALL(*M<int *>(self + 0xd50), 0x544)(M<int *>(self + 0xd50),&local_38);
          iVar5 = M<int>(self + 0xd50);
        }
      }
      goto LAB_000147d0;
    }
    iVar5 = M<int>(self + 0xd50);
    if (param_1 < M<unsigned int>(iVar5 + 0xcc)) {
      uVar7 = ~param_1;
      pIVar2 = M<UInt8 *>(param_1 * 0x20 + iVar5 + 0xe8);
      if (((pIVar2 == (UInt8 *)0x0) || (self == pIVar2)) || ((param_3 & 0x8000) == 0)) {
        switch(param_3 & 0xf) {
        case 3:
          sVar4 = 2;
          break;
        case 4:
          sVar4 = 4;
          break;
        default:
          sVar4 = 0;
          break;
        case 0xb:
        case 0xc:
          sVar4 = 8;
          break;
        case 0xd:
          sVar4 = 0x10;
        }
        if (M<SInt16>(param_1 * 0x78 + iVar5 + 0x142) == sVar4) goto LAB_00014454;
      }
    }
  }
  else {
    if (((param_3 ^ M<unsigned int>(self + 0xbe8)) & 0x803f) == 0) {
      param_3 = param_3 | M<unsigned int>(self + 0xbe8) & 0xffff7fc0;
      goto LAB_00014370;
    }
    iVar5 = M<int>(self + 0xd50);
  }
  uVar8 = 0xe00002bc;
LAB_000147d0:
  GH_IOLockUnlock(M<UInt32>(iVar5 + 0x840));
  return uVar8;
}
