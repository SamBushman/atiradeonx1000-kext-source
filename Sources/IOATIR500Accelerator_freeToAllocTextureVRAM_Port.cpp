/*
 * IOATIR500Accelerator_freeToAllocTextureVRAM_Port.cpp
 *
 * IOATIR500Accelerator::freeToAllocTextureVRAM (real addr 0x3f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3f60 */
UInt32 IOATIR500Accelerator::freeToAllocTextureVRAM(IOATIR500Surface *surface, VendorTextureBuffer**excludeList, SInt32 excludeCount, VendorTextureBuffer *needed) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *surfaceBytes = reinterpret_cast<UInt8 *>(surface);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  UInt16 *puVar1;
  UInt16 *puVar2;
  bool bVar3;
  bool secondPass;
  SInt32 iVar5;
  UInt8 *node;
  UInt32 uVar7;
  UInt32 uVar8;
  SInt32 iVar9;
  UInt8 *pIVar10;
  UInt8 *pIVar11;
  UInt8 bVar12;
  UInt8 bVar13;
  long excludeLeft;
  UInt32 uVar15;
  
  if (((M<SInt32>(self + 0x21c) == 0) ||
      (iVar5 = VCALL(M<SInt32>(self), 0x528)(self,neededBytes), iVar5 != 0)) ||
     (iVar5 = this->tossSurfacesForVRAM((IOATIR500Surface *)(surfaceBytes),(VendorTextureBuffer **)(excludeList),excludeCount,(VendorTextureBuffer *)(neededBytes),true), iVar5 == 0)) {
    secondPass = false;
LAB_00004450:
    iVar5 = VCALL(M<SInt32>(self), 0x528)(self,neededBytes);
    if (iVar5 == 0) {
      M<SInt32>(self + 0x7cc) = M<SInt32>(self + 0x7cc) + 1;
      if (surfaceBytes == (UInt8 *)0x0) {
        node = M<UInt8 *>(self + 0x604);
      }
      else {
        node = M<UInt8 *>(self + 0x604);
        pIVar10 = self + 0x5dc;
        if ((node == pIVar10) ||
           (M<SInt32>(surfaceBytes + 0x84) - M<SInt32>(M<SInt32>(node + 0x14) + 8) < 1)) {
          pIVar11 = M<UInt8 *>(self + 0x600);
          bVar12 = !secondPass << 1;
          node = (UInt8 *)0x0;
          bVar3 = pIVar11 == pIVar10;
LAB_00004294:
          if ((!bVar3) && (bVar13 = (pIVar11 == node) << 1, pIVar11 != node)) {
            M<SInt32>(self + 0x7e4) = M<SInt32>(self + 0x7e4) + 1;
            if (excludeCount < 1) goto code_r0x00004264;
            if (pIVar11 != (UInt8 *)*excludeList) {
              iVar5 = 0;
              excludeLeft = excludeCount;
              do {
                iVar5 = iVar5 + 1;
                excludeLeft = excludeLeft + -1;
                if (excludeLeft == 0) goto LAB_000042b8;
              } while ((UInt8 *)excludeList[iVar5] != pIVar11);
            }
            M<SInt32>(self + 0x7e8) = M<SInt32>(self + 0x7e8) + 1;
            goto LAB_0000428c;
          }
          goto LAB_00004448;
        }
      }
      pIVar11 = self + 0x5dc;
      bVar12 = !secondPass << 1;
      pIVar10 = (UInt8 *)0x0;
LAB_00004040:
      do {
        if ((node == pIVar11) || (bVar13 = (pIVar10 == node) << 1, pIVar10 == node))
        goto LAB_00004448;
        M<SInt32>(self + 2000) = M<SInt32>(self + 2000) + 1;
        if (excludeCount < 1) {
          if (excludeCount == 0) {
LAB_000040b8:
            if ((bool)(bVar12 >> 1 & 1)) {
              iVar5 = M<SInt32>(node + 0x14);
              if ((iVar5 == 0) || (uVar7 = (UInt32)M<UInt8>(iVar5 + 0x34), uVar7 == 0))
              goto LAB_00004124;
              if ((M<UInt16>(iVar5 + 0x28) & ~M<UInt16>(iVar5 + 0x1c)) == 0) {
                uVar15 = 0;
                iVar9 = iVar5;
                uVar8 = uVar7;
                if (uVar7 == 0) {
                  uVar8 = 1;
                }
                do {
                  uVar15 = uVar15 + 1;
                  uVar8 = uVar8 - 1;
                  if (uVar8 == 0) {
                    if (uVar7 == uVar15) goto LAB_00004124;
                    goto LAB_00004040;
                  }
                  puVar1 = (UInt16 *)(iVar9 + 0x1e);
                  puVar2 = (UInt16 *)(iVar9 + 0x2a);
                  iVar9 = iVar9 + 2;
                } while ((*puVar2 & ~*puVar1) == 0);
              }
              M<SInt32>(self + 0x7d8) = M<SInt32>(self + 0x7d8) + 1;
            }
            else {
              iVar5 = M<SInt32>(node + 0x14);
LAB_00004124:
              iVar5 = VCALL(M<SInt32>(self), 0x554)(self,M<UInt32>(iVar5 + 0xc));
              if (iVar5 != 0) {
                if (M<SInt32>(node + 0x48) != 0) {
                  VCALL(M<SInt32>(self), 0x524)(self,node);
                  M<UInt8>(M<SInt32>(node + 0x14) + 0x14) = 1;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x28) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x2a) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x2c) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x2e) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x30) = 0;
                  M<UInt16>(M<SInt32>(node + 0x14) + 0x32) = 0;
                }
                iVar9 = M<SInt32>(node + 0x24);
                M<UInt32>(iVar9 + 0x28) = M<UInt32>(node + 0x28);
                iVar5 = M<SInt32>(node + 0x28);
                M<UInt8 *>(node + 0x28) = node;
                M<SInt32>(iVar5 + 0x24) = iVar9;
                M<UInt8 *>(node + 0x24) = node;
                M<SInt32>(self + 0x7e0) = M<SInt32>(self + 0x7e0) + 1;
                if (pIVar11 != node) goto LAB_00004430;
                goto LAB_00004448;
              }
              M<SInt32>(self + 0x7dc) = M<SInt32>(self + 0x7dc) + 1;
            }
            if (pIVar10 == (UInt8 *)0x0) {
              pIVar10 = node;
            }
            if (M<SInt32>(node + 0x48) != 0) {
              iVar9 = M<SInt32>(node + 0x24);
              M<UInt32>(iVar9 + 0x28) = M<UInt32>(node + 0x28);
              iVar5 = M<SInt32>(node + 0x28);
              M<UInt8 *>(node + 0x28) = pIVar11;
              M<SInt32>(iVar5 + 0x24) = iVar9;
              M<UInt32>(node + 0x24) = M<UInt32>(self + 0x600);
              M<UInt8 *>(self + 0x600) = node;
              M<UInt8 *>(M<SInt32>(node + 0x24) + 0x28) = node;
            }
            node = M<UInt8 *>(node + 0x28);
          }
          goto LAB_00004040;
        }
        if ((UInt8 *)*excludeList != node) {
          iVar5 = 0;
          excludeLeft = excludeCount;
          do {
            iVar5 = iVar5 + 1;
            excludeLeft = excludeLeft + -1;
            if (excludeLeft == 0) goto LAB_000040b8;
          } while ((UInt8 *)excludeList[iVar5] != node);
        }
        M<SInt32>(self + 0x7d4) = M<SInt32>(self + 0x7d4) + 1;
        node = M<UInt8 *>(node + 0x28);
      } while( true );
    }
LAB_00004474:
    if ((M<SInt32>(neededBytes + 0x48) == 0) &&
       (iVar5 = this->tossSurfacesForVRAM((IOATIR500Surface *)(surfaceBytes),(VendorTextureBuffer **)(excludeList),excludeCount,(VendorTextureBuffer *)(neededBytes),false), iVar5 == 0)) {
      return 0;
    }
  }
  return 1;
code_r0x00004264:
  if (excludeCount != 0) goto LAB_00004294;
LAB_000042b8:
  if ((bool)(bVar12 >> 1 & 1)) {
    iVar5 = M<SInt32>(pIVar11 + 0x14);
    if (iVar5 != 0) {
      uVar7 = (UInt32)M<UInt8>(iVar5 + 0x34);
      uVar8 = 0;
      if (uVar7 != 0) {
        if ((M<UInt16>(iVar5 + 0x28) & ~M<UInt16>(iVar5 + 0x1c)) == 0) {
          uVar8 = 0;
          iVar9 = iVar5;
          uVar15 = uVar7;
          if (uVar7 == 0) {
            uVar15 = 1;
          }
          do {
            uVar8 = uVar8 + 1;
            uVar15 = uVar15 - 1;
            if (uVar15 == 0) goto LAB_00004314;
            puVar1 = (UInt16 *)(iVar9 + 0x1e);
            puVar2 = (UInt16 *)(iVar9 + 0x2a);
            iVar9 = iVar9 + 2;
          } while ((*puVar2 & ~*puVar1) == 0);
        }
        M<SInt32>(self + 0x7ec) = M<SInt32>(self + 0x7ec) + 1;
        goto joined_r0x00004360;
      }
LAB_00004314:
      if (uVar8 != uVar7) goto LAB_00004294;
    }
    iVar5 = VCALL(M<SInt32>(self), 0x554)(self,M<UInt32>(iVar5 + 0xc));
    if (iVar5 == 0) {
      M<SInt32>(self + 0x7f0) = M<SInt32>(self + 0x7f0) + 1;
joined_r0x00004360:
      if (node == (UInt8 *)0x0) {
        node = pIVar11;
      }
      if (M<SInt32>(pIVar11 + 0x48) != 0) {
        iVar9 = M<SInt32>(pIVar11 + 0x24);
        M<UInt32>(iVar9 + 0x28) = M<UInt32>(pIVar11 + 0x28);
        iVar5 = M<SInt32>(pIVar11 + 0x28);
        M<UInt32>(pIVar11 + 0x28) = M<UInt32>(self + 0x604);
        M<UInt8 *>(self + 0x604) = pIVar11;
        M<SInt32>(iVar5 + 0x24) = iVar9;
        M<UInt8 *>(pIVar11 + 0x24) = pIVar10;
        M<UInt8 *>(M<SInt32>(pIVar11 + 0x28) + 0x24) = pIVar11;
      }
LAB_0000428c:
      pIVar11 = M<UInt8 *>(pIVar11 + 0x24);
      bVar3 = pIVar11 == pIVar10;
      goto LAB_00004294;
    }
  }
  if (M<SInt32>(pIVar11 + 0x48) != 0) {
    VCALL(M<SInt32>(self), 0x524)(self,pIVar11);
    M<UInt8>(M<SInt32>(pIVar11 + 0x14) + 0x14) = 1;
    M<UInt16>(M<SInt32>(pIVar11 + 0x14) + 0x28) = 0;
    M<UInt16>(M<SInt32>(pIVar11 + 0x14) + 0x2a) = 0;
    M<UInt16>(M<SInt32>(pIVar11 + 0x14) + 0x2c) = 0;
    M<UInt16>(M<SInt32>(pIVar11 + 0x14) + 0x2e) = 0;
    M<UInt16>(M<SInt32>(pIVar11 + 0x14) + 0x30) = 0;
    M<UInt16>(M<SInt32>(pIVar11 + 0x14) + 0x32) = 0;
  }
  iVar9 = M<SInt32>(pIVar11 + 0x24);
  M<UInt32>(iVar9 + 0x28) = M<UInt32>(pIVar11 + 0x28);
  iVar5 = M<SInt32>(pIVar11 + 0x28);
  M<UInt8 *>(pIVar11 + 0x28) = pIVar11;
  M<SInt32>(iVar5 + 0x24) = iVar9;
  M<UInt8 *>(pIVar11 + 0x24) = pIVar11;
  M<SInt32>(self + 0x7f4) = M<SInt32>(self + 0x7f4) + 1;
  if (pIVar10 != pIVar11) goto LAB_00004430;
  goto LAB_00004448;
LAB_00004430:
  if ((bool)(bVar13 >> 1 & 1)) {
LAB_00004448:
    if (!(bool)(bVar12 >> 1 & 1)) goto LAB_00004474;
    secondPass = true;
  }
  goto LAB_00004450;
}
