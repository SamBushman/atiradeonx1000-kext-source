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
IOReturn IOATIR500Surface::surface_lock_options(eLockType param_2, UInt32 param_3, IOAccelSurfaceData *real_param_4, UInt32 param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    int *param_4 = reinterpret_cast<int *>(real_param_4);

  bool bVar1;
  bool bVar2;
  unsigned int uVar3;
  int *piVar4;
  UInt32 uVar5;
  unsigned int uVar6;
  UInt8 IVar7;
  int iVar8;
  UInt8 *pAVar9;
  int iVar10;
  UInt8 bVar11;
  int local_38 [7];
  
  bVar11 = (param_2 == 1) << 1;
  GH_bzero(param_4,0x44);
  GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  if ((bool)(bVar11 >> 1 & 1)) {
    IVar7 = self[0xbd0];
  }
  else {
    IVar7 = self[0xbd1];
  }
  pAVar9 = M<UInt8 *>(self + 0xb70);
  if (IVar7 != 0x0) {
    bVar2 = false;
    iVar10 = -0x1ffffd34;
    goto LAB_00016360;
  }
  uVar6 = M<unsigned int>(self + 0xbf8);
  if ((uVar6 & 0x20000000) != 0) {
LAB_00016330:
    bVar2 = false;
    IVar7 = 0x0;
    iVar10 = -0x1ffffd34;
    goto LAB_00016360;
  }
  if (((((bool)(bVar11 >> 1 & 1)) && ((M<unsigned int>(self + 0xc18) & 0x7ffc00) != 0)) &&
      (M<int>(self + 0x90) != 0)) && (self[0xbf0] != 0x0)) {
    param_3 = param_3 | 3;
  }
  else if (M<int>(pAVar9 + 0x10) == 0) goto LAB_00016330;
  iVar8 = M<int>(pAVar9 + 0x24);
  uVar3 = M<unsigned int>(self + 0xc1c) & 3;
  if ((iVar8 == 0) || (bVar2 = true, M<int>(iVar8 + 0x54) != M<int>(self + 0x7c))) {
    bVar2 = false;
  }
  param_3 = param_3 & 3;
  bVar1 = (uVar6 & uVar3) == 0;
  if (param_3 == 1) {
    if ((((param_2 != 2) && (!bVar1)) && (!bVar2)) || (self[0xbf4] == 0x0))
    goto LAB_00015e70;
LAB_00015ec8:
    self[0xc08] = 0x1;
    if ((uVar3 & uVar6) == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = this->alloc_surfaces_retry(uVar3,(eLockType)(param_2));
      if (iVar10 != 0) {
LAB_00016344:
        bVar2 = false;
        IVar7 = 0x0;
        goto LAB_00016360;
      }
    }
    param_4[4] = (unsigned int)M<UInt16>(pAVar9 + 0x18);
    *param_4 = M<int>(pAVar9 + 8) + M<int>(self + 0xc0c);
    VCALL(M<int>(self), 0x5fc)(self,pAVar9);
    if ((bool)(bVar11 >> 1 & 1)) {
      bVar2 = false;
      iVar8 = VCALL(*M<int *>(self + 0xd50), 0x558)
                        (M<int *>(self + 0xd50),M<UInt32>(self + 0x7c));
      IVar7 = 0x1;
      M<int>(M<int>(self + 0xd50) + 0x7b8) =
           iVar8 + M<int>(M<int>(self + 0xd50) + 0x7b8);
    }
    else {
      piVar4 = M<int *>(self + 0xd50);
      bVar2 = false;
      iVar8 = VCALL(*piVar4, 0x558)(piVar4,piVar4[0x14] + -1);
      IVar7 = 0x1;
      M<int>(M<int>(self + 0xd50) + 0x7bc) =
           iVar8 + M<int>(M<int>(self + 0xd50) + 0x7bc);
    }
  }
  else {
    if (param_3 == 0) {
      if (((param_2 == 2) || (bVar1)) || (bVar2)) goto LAB_00015fe4;
    }
    else {
      if (param_3 == 2) {
        if ((!bVar2) || (M<char>(iVar8 + 0x58) == '\0')) {
          if ((bVar1) && (self[0xbf4] != 0x0)) goto LAB_00015ec8;
          if (((param_2 != 2) && (!bVar1)) && (!bVar2)) goto LAB_00015e70;
        }
LAB_00015fe4:
        if ((self[0xbf7] == 0x0) || (self[0xc08] != 0x0))
        goto LAB_000160bc;
        if (iVar8 == 0) {
LAB_00016170:
          iVar10 = 0;
LAB_00016174:
          if (M<int>(pAVar9 + 8) != 0) {
            if ((bool)(bVar11 >> 1 & 1)) {
              iVar8 = this->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)(pAVar9));
            }
            else {
              iVar8 = this->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(pAVar9));
            }
            if (iVar8 == 0) {
              bVar2 = false;
              IVar7 = 0x3;
              iVar10 = -0x1ffffd38;
              goto LAB_00016360;
            }
          }
          bVar2 = true;
        }
        else {
          if (M<int>(iVar8 + 8) != 0) {
            local_38[0] = 2;
            iVar10 = VCALL(*M<int *>(M<int>(pAVar9 + 0x24) + 8), 0xdc)
                               (M<int *>(M<int>(pAVar9 + 0x24) + 8),2,local_38);
            if (iVar10 == 0) {
              if ((bVar1) && (local_38[0] == 4)) {
                iVar8 = M<int>(pAVar9 + 0x24);
                if (M<int>(iVar8 + 0x54) == M<int>(self + 0x7c)) {
                  M<UInt8>(iVar8 + 0x58) = 0;
                  iVar8 = M<int>(pAVar9 + 0x24);
                }
              }
              else {
                iVar8 = M<int>(pAVar9 + 0x24);
              }
              if (M<int *>(iVar8 + 0x10) == (int *)0x0) goto LAB_000160c4;
              VCALL(*M<int *>(iVar8 + 0x10), 0x18)(M<int *>(iVar8 + 0x10));
              M<UInt32>(M<int>(pAVar9 + 0x24) + 0x10) = 0;
              iVar8 = M<int>(pAVar9 + 0x24);
            }
            else {
              iVar8 = M<int>(pAVar9 + 0x24);
            }
LAB_000160bc:
            if (iVar8 == 0) goto LAB_00016170;
          }
LAB_000160c4:
          if ((M<int>(iVar8 + 0x54) == M<int>(self + 0x7c)) &&
             (M<char>(iVar8 + 0x58) == '\0')) {
            if ((bool)(bVar11 >> 1 & 1)) {
              self[0xbd0] = 0x3;
            }
            else {
              self[0xbd1] = 0x3;
            }
            iVar10 = this->alloc_surfaces_retry(uVar3,(eLockType)(param_2));
            if ((bool)(bVar11 >> 1 & 1)) {
              self[0xbd0] = 0x0;
            }
            else {
              self[0xbd1] = 0x0;
            }
            if (iVar10 != 0) goto LAB_00016344;
            iVar8 = M<int>(pAVar9 + 0x24);
          }
          else {
            iVar10 = 0;
          }
          if (((iVar8 == 0) || (M<int>(iVar8 + 0x54) != M<int>(self + 0x7c))) ||
             (bVar2 = false, M<char>(iVar8 + 0x58) == '\0')) goto LAB_00016174;
        }
        if (param_2 == 2) {
          VCALL(M<int>(self), 0x5cc)
                    (self,((int)pAVar9 - (int)(self + 0xa8) >> 3) * -0x11111111);
        }
        iVar8 = M<int>(pAVar9 + 0x24);
        if (iVar8 == 0) {
LAB_00016350:
          IVar7 = 0x0;
          iVar10 = -0x1ffffd43;
          goto LAB_00016360;
        }
        if (M<int>(iVar8 + 0x10) == 0) {
          uVar5 = VCALL(*M<int *>(iVar8 + 8), 0x14c)
                            (M<int *>(iVar8 + 8),M<UInt32>(self + 0x78),0,1,0,0);
          M<UInt32>(iVar8 + 0x10) = uVar5;
          iVar8 = M<int>(pAVar9 + 0x24);
          if (M<int>(iVar8 + 0x10) == 0) goto LAB_00016350;
          if (M<char>(iVar8 + 0x59) == '\0') {
            self[0xc09] = 0x1;
            iVar8 = M<int>(pAVar9 + 0x24);
          }
        }
        param_4[4] = (unsigned int)M<UInt16>(iVar8 + 0x52);
        iVar8 = VCALL(*M<int *>(M<int>(pAVar9 + 0x24) + 0x10), 0xd0)(M<int *>(M<int>(pAVar9 + 0x24) + 0x10));
        IVar7 = 0x3;
        *param_4 = iVar8 + (unsigned int)M<UInt16>(M<int>(pAVar9 + 0x24) + 0x50);
        goto LAB_00015e7c;
      }
      if (param_3 != 3) {
        bVar2 = false;
        IVar7 = 0x0;
        iVar10 = -0x1ffffd3e;
        goto LAB_00016360;
      }
    }
LAB_00015e70:
    bVar2 = false;
    iVar10 = 0;
    IVar7 = 0x2;
  }
LAB_00015e7c:
  param_4[5] = (unsigned int)M<UInt16>(pAVar9 + 0x1c);
  param_4[6] = (unsigned int)M<UInt16>(pAVar9 + 0x1e);
  uVar6 = M<unsigned int>(self + 0xbe8) & 0xf;
  param_4[7] = uVar6;
  if (uVar6 == 6) {
    param_4[7] = 0x79757673;
  }
  else if (uVar6 == 9) {
    param_4[7] = 0x32767579;
  }
  else if (uVar6 == 10) {
    param_4[7] = 4;
  }
  param_4[8] = M<int>(self + 0xd70);
  param_4[0xd] = M<int>(self + 0xd74);
  param_4[0xe] = M<int>(self + 0xd78);
  param_4[0xf] = M<int>(self + 0xd7c);
  iVar8 = M<int>(self + 0xd80);
  param_4[9] = 0x1cccc;
  param_4[0x10] = iVar8;
LAB_00016360:
  if ((bool)(bVar11 >> 1 & 1)) {
    self[0xbd0] = IVar7;
  }
  else {
    self[0xbd1] = IVar7;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  if (bVar2) {
    VCALL(*M<int *>(self + 0xd50), 0x558)
              (M<int *>(self + 0xd50),M<UInt32>(self + 0x7c));
  }
  return iVar10;
}
