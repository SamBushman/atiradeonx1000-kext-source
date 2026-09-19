/*
 * IOATIR500Accelerator_freeToAllocSurfaceVRAM_Port.cpp
 *
 * IOATIR500Accelerator::freeToAllocSurfaceVRAM (real addr 0x45a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45a0 */
UInt32 IOATIR500Accelerator::freeToAllocSurfaceVRAM(IOATIR500Surface *real_param_1, IOATIR500Surface *real_param_2, VendorTextureBuffer**param_3, SInt32 param_4, ATIR500SurfaceBuffer *real_param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);
    UInt8 *param_5 = reinterpret_cast<UInt8 *>(real_param_5);

  UInt16 *puVar1;
  UInt16 *puVar2;
  bool bVar3;
  UInt8 *pVVar4;
  int iVar5;
  int iVar6;
  UInt8 **ppVVar7;
  unsigned int uVar8;
  UInt8 *pIVar9;
  unsigned int uVar10;
  UInt8 *pAVar11;
  UInt8 *pIVar12;
  UInt8 *this_00;
  UInt8 bVar13;
  UInt8 bVar14;
  long lVar15;
  unsigned int uVar16;
  
  bVar13 = (param_1 == (UInt8 *)0x0) << 1;
  bVar3 = false;
  do {
    while( true ) {
      if ((bool)(bVar13 >> 1 & 1)) {
        iVar5 = VCALL(M<int>(self), 0x56c)(self,param_5);
      }
      else {
        iVar5 = VCALL(M<int>(param_1), 0x5d0)(param_1,param_5);
      }
      if (iVar5 == 1) break;
      pIVar12 = M<UInt8 *>(self + 0x604);
      do {
        do {
          while( true ) {
            if (self + 0x5dc == pIVar12) goto LAB_00004794;
            if (param_4 < 1) break;
            if (pIVar12 != (UInt8 *)*param_3) {
              iVar5 = 0;
              lVar15 = param_4;
              do {
                iVar5 = iVar5 + 1;
                lVar15 = lVar15 + -1;
                if (lVar15 == 0) goto LAB_00004654;
              } while (pIVar12 != (UInt8 *)param_3[iVar5]);
            }
LAB_000046a0:
            pIVar12 = M<UInt8 *>(pIVar12 + 0x28);
          }
        } while (param_4 != 0);
LAB_00004654:
        if ((bVar3) || (iVar5 = M<int>(pIVar12 + 0x14), iVar5 == 0)) break;
        uVar10 = (unsigned int)M<UInt8>(iVar5 + 0x34);
        uVar8 = 0;
        if (uVar10 != 0) {
          if ((M<UInt16>(iVar5 + 0x28) & ~M<UInt16>(iVar5 + 0x1c)) == 0) {
            uVar8 = 0;
            uVar16 = uVar10;
            if (uVar10 == 0) {
              uVar16 = 1;
            }
            do {
              uVar8 = uVar8 + 1;
              uVar16 = uVar16 - 1;
              if (uVar16 == 0) goto LAB_000046b8;
              puVar1 = (UInt16 *)(iVar5 + 0x1e);
              puVar2 = (UInt16 *)(iVar5 + 0x2a);
              iVar5 = iVar5 + 2;
            } while ((*puVar2 & ~*puVar1) == 0);
          }
          goto LAB_000046a0;
        }
LAB_000046b8: ;
      } while (uVar8 != uVar10);
      if (M<int>(pIVar12 + 0x48) != 0) {
        VCALL(M<int>(self), 0x524)(self,pIVar12);
        M<UInt8>(M<int>(pIVar12 + 0x14) + 0x14) = 1;
        M<UInt16>(M<int>(pIVar12 + 0x14) + 0x28) = 0;
        M<UInt16>(M<int>(pIVar12 + 0x14) + 0x2a) = 0;
        M<UInt16>(M<int>(pIVar12 + 0x14) + 0x2c) = 0;
        M<UInt16>(M<int>(pIVar12 + 0x14) + 0x2e) = 0;
        M<UInt16>(M<int>(pIVar12 + 0x14) + 0x30) = 0;
        M<UInt16>(M<int>(pIVar12 + 0x14) + 0x32) = 0;
      }
      iVar5 = M<int>(pIVar12 + 0x24);
      M<UInt32>(iVar5 + 0x28) = M<UInt32>(pIVar12 + 0x28);
      iVar6 = M<int>(pIVar12 + 0x28);
      M<UInt8 *>(pIVar12 + 0x28) = pIVar12;
      M<int>(iVar6 + 0x24) = iVar5;
      M<UInt8 *>(pIVar12 + 0x24) = pIVar12;
    }
LAB_00004794:
    if (M<int>(param_5 + 8) != 0) {
      return 1;
    }
    if (bVar3) {
      return 0;
    }
    pIVar9 = M<UInt8 *>(self + 0x5c);
    if (pIVar9 != (UInt8 *)0x0) {
      bVar14 = (0 < param_4) << 2 | (param_4 == 0) << 1;
      this_00 = pIVar9;
      do {
        this_00 = M<UInt8 *>(this_00 + 0xa0);
        if ((param_1 != this_00) && (this_00 != param_2)) {
          ppVVar7 = (UInt8 **)param_3;
          lVar15 = param_4;
          if ((bool)(bVar14 >> 2 & 1)) {
            do {
              pVVar4 = *ppVVar7;
              ppVVar7 = ppVVar7 + 1;
              if (((pVVar4 != (UInt8 *)0x0) &&
                  (pVVar4[0x20] == 0x0)) &&
                 (this_00 == M<UInt8 *>(pVVar4 + 0x50))) goto LAB_0000492c;
              lVar15 = lVar15 + -1;
            } while (lVar15 != 0);
          }
          else if (!(bool)(bVar14 >> 1 & 1)) goto LAB_0000492c;
          uVar10 = 0;
          pAVar11 = (UInt8 *)(this_00 + 0xa8);
          do {
            if ((((M<int>(this_00 + 0xc14) == 0xffff) || ((1 < uVar10 && (1 < uVar10 - 4)))) &&
                (M<int>(pAVar11 + 8) != 0)) &&
               (((M<unsigned int>(this_00 + 0xbd0) & 0xffff0000) == 0 ||
                (pAVar11 != M<UInt8 *>(this_00 + 0xb70))))) {
              if (M<int>(this_00 + 0xd48) == 0) {
                ((IOATIR500Surface *)(this_00))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(pAVar11));
              }
              else {
                VCALL(M<int>(this_00), 0x5cc)(this_00,uVar10);
              }
              if ((bool)(bVar13 >> 1 & 1)) {
                VCALL(M<int>(self), 0x56c)(self,param_5);
              }
              else {
                VCALL(M<int>(param_1), 0x5d0)(param_1,param_5);
              }
              if (M<int>(param_5 + 8) != 0) {
                return 1;
              }
            }
            bVar3 = uVar10 != 0x16;
            pAVar11 = pAVar11 + 0x78;
            uVar10 = uVar10 + 1;
          } while (bVar3);
          pIVar9 = M<UInt8 *>(self + 0x5c);
        }
LAB_0000492c: ;
      } while (this_00 != pIVar9);
    }
    bVar3 = true;
  } while( true );
}
