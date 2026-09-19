/*
 * ATIR500GLContext_compact_current_textures_Port.cpp
 *
 * ATIR500GLContext::compact_current_textures (real addr 0x29dd0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x29dd0 */
IOReturn ATIR500GLContext::compact_current_textures(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  UInt8 VVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 *puVar7;
  UInt8 *pAVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  SInt32 *piVar11;
  UInt32 uVar12;
  SInt32 iVar13;
  UInt8 *pAVar14;
  UInt8 *pIVar15;
  UInt8 *pVVar16;
  UInt32 uVar17;
  UInt32 auStack_48 [7];
  
  iVar6 = 0;
  pAVar8 = self;
  do {
    iVar13 = M<SInt32>(pAVar8 + 0x2a4);
    if (iVar13 != 0) {
      if (M<SInt32>(iVar13 + 0x48) == 0) {
        if (M<char>(iVar13 + 0x20) != '\0') goto LAB_00029f5c;
        pIVar15 = M<UInt8 *>(iVar13 + 0x50);
        uVar12 = 0;
        pAVar14 = (UInt8 *)(pIVar15 + 0xa8);
        do {
          if ((((M<SInt32>(pIVar15 + 0xc14) == 0xffff) || ((1 < uVar12 && (1 < uVar12 - 4)))) &&
              (M<SInt32>(pAVar14 + 8) != 0)) &&
             (((M<UInt32>(pIVar15 + 0xbd0) & 0xffff0000) == 0 ||
              (pAVar14 != M<UInt8 *>(pIVar15 + 0xb70))))) {
            if (M<SInt32>(pIVar15 + 0xd48) == 0) {
              ((IOATIR500Surface *)(pIVar15))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(pAVar14));
            }
            else {
              VCALL(M<SInt32>(pIVar15), 0x5cc)(pIVar15,iVar6);
            }
          }
          bVar1 = uVar12 != 0x16;
          pAVar14 = pAVar14 + 0x78;
          uVar12 = uVar12 + 1;
        } while (bVar1);
        VCALL(M<SInt32>(pIVar15), 0x5c4)(pIVar15);
      }
      else {
        VCALL(*M<SInt32 *>(self + 200), 0x524)(M<SInt32 *>(self + 200),iVar13);
      }
      M<UInt8>(M<SInt32>(iVar13 + 0x14) + 0x14) = 1;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x28) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x2a) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x2c) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x2e) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x30) = 0;
      M<UInt16>(M<SInt32>(iVar13 + 0x14) + 0x32) = 0;
      iVar5 = M<SInt32>(iVar13 + 0x24);
      M<UInt32>(iVar5 + 0x28) = M<UInt32>(iVar13 + 0x28);
      iVar3 = M<SInt32>(iVar13 + 0x28);
      M<SInt32>(iVar13 + 0x28) = iVar13;
      M<SInt32>(iVar3 + 0x24) = iVar5;
      M<SInt32>(iVar13 + 0x24) = iVar13;
    }
LAB_00029f5c:
    bVar1 = iVar6 == 0x29;
    pAVar8 = pAVar8 + 4;
    iVar6 = iVar6 + 1;
    if (bVar1) {
      if (param_1[0x20] == 0x0) {
        pIVar15 = M<UInt8 *>(param_1 + 0x50);
        uVar12 = 0;
        pAVar14 = (UInt8 *)(pIVar15 + 0xa8);
        do {
          if (((M<SInt32>(pIVar15 + 0xc14) == 0xffff) || ((1 < uVar12 && (1 < uVar12 - 4)))) &&
             ((M<SInt32>(pAVar14 + 8) != 0 &&
              (((M<UInt32>(pIVar15 + 0xbd0) & 0xffff0000) == 0 ||
               (pAVar14 != M<UInt8 *>(pIVar15 + 0xb70))))))) {
            if (M<SInt32>(pIVar15 + 0xd48) == 0) {
              ((IOATIR500Surface *)(pIVar15))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(pAVar14));
            }
            else {
              VCALL(M<SInt32>(pIVar15), 0x5cc)(pIVar15,0x2a);
            }
          }
          bVar1 = uVar12 != 0x16;
          pAVar14 = pAVar14 + 0x78;
          uVar12 = uVar12 + 1;
        } while (bVar1);
        VCALL(M<SInt32>(pIVar15), 0x5c4)(pIVar15);
        M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x14) = 1;
        M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x28) = 0;
        M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x2a) = 0;
        M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x2c) = 0;
        M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x2e) = 0;
        M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x30) = 0;
        M<UInt16>(M<SInt32>(param_1 + 0x14) + 0x32) = 0;
        iVar13 = M<SInt32>(param_1 + 0x24);
        M<UInt32>(iVar13 + 0x28) = M<UInt32>(param_1 + 0x28);
        iVar6 = M<SInt32>(param_1 + 0x28);
        M<UInt8 *>(param_1 + 0x28) = param_1;
        M<SInt32>(iVar6 + 0x24) = iVar13;
        M<UInt8 *>(param_1 + 0x24) = param_1;
      }
      uVar10 = 0;
      uVar9 = 0;
      VCALL(M<SInt32>(self), 0x5a4)(self);
      piVar11 = M<SInt32 *>(self + 200);
      uVar12 = M<SInt32>(self + 0x28c) + 1U & 0xf;
      M<UInt32>(self + 0x28c) = uVar12;
      iVar13 = piVar11[0x1e0];
      iVar6 = VCALL(*piVar11, 0x54c)(piVar11,M<UInt32>(self + uVar12 * 0x18 + 0x11c))
      ;
      piVar11[0x1e0] = iVar13 + iVar6;
      puVar7 = (UInt32 *)(M<SInt32>(self + uVar12 * 0x18 + 0x120) + 0x20);
      pAVar8 = self;
      do {
        pVVar16 = M<UInt8 *>(pAVar8 + 0x2a4);
        if ((pVVar16 != (UInt8 *)0x0) &&
           (((VVar2 = pVVar16[0x20], VVar2 == 0x3 ||
             (VVar2 == 0x0)) || (VVar2 == 0x7)))) {
          if (M<SInt32>(pVVar16 + 0x48) == 0) {
            if (VVar2 == 0x0) {
              pIVar15 = M<UInt8 *>(pVVar16 + 0x50);
              iVar6 = ((IOATIR500Surface *)(pIVar15))->surface_buffer_idx_mask(M<UInt32>(pVVar16 + 0x58),(UInt32 *)(auStack_48));
              pAVar14 = M<UInt8 *>(pIVar15 + iVar6 * 4 + 0xb70);
              VCALL(M<SInt32>(pIVar15), 0x5d0)(pIVar15,pAVar14);
              ((IOATIR500Surface *)(pIVar15))->copy_buffer_from_backing_store((ATIR500SurfaceBuffer *)(pAVar14));
            }
            else {
              iVar6 = VCALL(*M<SInt32 *>(self + 200), 0x528)(M<SInt32 *>(self + 200),pVVar16);
              if (iVar6 != 0) {
                this->load_texture((VendorTextureBuffer *)(pVVar16));
              }
            }
            M<UInt8>(M<SInt32>(pVVar16 + 0x14) + 0x14) = 0;
          }
          if (uVar10 < 0x10) {
            iVar6 = this->WriteTextureOffset(uVar10,(UInt32 *)(puVar7),uVar9,(VendorTextureBuffer *)(pVVar16));
            uVar9 = uVar9 + iVar6;
          }
        }
        bVar1 = uVar10 != 0x29;
        pAVar8 = pAVar8 + 4;
        uVar10 = uVar10 + 1;
      } while (bVar1);
      iVar6 = this->WriteVertexArrayOffset((UInt32 *)(puVar7),uVar9);
      uVar17 = iVar6 + uVar9;
      uVar10 = uVar17;
      if ((uVar17 & 1) != 0) {
        uVar10 = uVar17 + 1;
        puVar7[uVar17] = 0x80000000;
      }
      if (M<SInt32>(self + uVar12 * 0x18 + 0x110) == 0) {
        ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + uVar12 * 0x18 + 0x10c)));
      }
      M<UInt32>(M<SInt32>(self + 200) + 0x704) = uVar10 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
      M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
      uVar4 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)(puVar7),
                         M<SInt32>(self + uVar12 * 0x18 + 0x110) + 0x20,uVar10);
      M<UInt32>(self + uVar12 * 0x18 + 0x11c) = uVar4;
      if (param_1[0x20] == 0x0) {
        pIVar15 = M<UInt8 *>(param_1 + 0x50);
        iVar6 = ((IOATIR500Surface *)(pIVar15))->surface_buffer_idx_mask(M<UInt32>(param_1 + 0x58),(UInt32 *)(auStack_48));
        pAVar14 = M<UInt8 *>(pIVar15 + iVar6 * 4 + 0xb70);
        iVar6 = VCALL(M<SInt32>(pIVar15), 0x5d0)(pIVar15,pAVar14);
        if ((iVar6 != 0) &&
           (iVar6 = ((IOATIR500Surface *)(pIVar15))->copy_buffer_from_backing_store((ATIR500SurfaceBuffer *)(pAVar14)), iVar6 != 0))
        {
          return 1;
        }
        uVar4 = 0;
      }
      else {
        uVar4 = VCALL(*M<SInt32 *>(self + 200), 0x528)(M<SInt32 *>(self + 200),param_1);
      }
      return uVar4;
    }
  } while( true );
}
