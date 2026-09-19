/*
 * ATIR500Surface_shape_surface_Port.cpp
 *
 * ATIR500Surface::shape_surface (real addr 0x3c130, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


extern "C" UInt32 window_mode_to_ati_format(UInt32 windowModeBits) asm("__Z25window_mode_to_ati_formatm");
extern const UInt32 kShapeSurfaceDefaultMipTable[14];   /* shape_surface()::C.146 (real 0x4c284, 0x38 bytes, all zero), defined in ATIR500Surface_ShapeSurface.cpp */

/* real addr 0x3c130 */
void ATIR500Surface::shape_surface() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt16 sVar2;
  UInt16 uVar3;
  UInt16 uVar4;
  UInt8 AVar5;
  UInt16 uVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  SInt32 iVar9;
  UInt32 uVar10;
  SInt32 *piVar11;
  UInt8 AVar12;
  UInt32 uVar13;
  SInt32 iVar14;
  UInt8 *pAVar15;
  SInt32 iVar16;
  SInt16 sVar18;
  UInt32 uVar17;
  UInt32 uVar19;
  UInt16 uVar20;
  UInt16 uVar21;
  UInt8 AVar22;
  SInt32 iVar23;
  UInt32 uVar24;
  SInt32 iVar25;
  UInt32 uVar26;
  SInt32 iVar27;
  UInt32 uVar28;
  UInt32 uVar29;
  UInt8 local_98 [8];
  SInt32 local_90 [14];
  UInt32 local_58;
  
  M<UInt32>(M<SInt32>(self + 0xd50) + 0xb94) = 1;
  uVar29 = M<UInt32>(self + 0xbe8);
  if ((uVar29 & 0x70000000) == 0) {
    uVar28 = M<UInt32>(self + 0xc18);
  }
  else {
    uVar29 = uVar29 & 0xff83ffff;
    M<UInt32>(self + 0xbe8) = uVar29;
    uVar28 = M<UInt32>(self + 0xc18) & 0xfffffdff;
    M<UInt32>(self + 0xc18) = uVar28;
  }
  if ((uVar29 & 0x7c0000) == 0) {
LAB_0003c260:
    iVar23 = 1;
    local_58 = 1;
  }
  else {
    uVar7 = uVar29 & 0x700000;
    if (uVar7 == 0) {
      uVar7 = uVar29 & 0xc0000;
      if (uVar7 == 0) goto LAB_0003c260;
      if (uVar7 == 0x40000) {
        iVar23 = 1;
        local_58 = 2;
      }
      else if (uVar7 == 0x80000) {
        iVar23 = 2;
        local_58 = 2;
      }
      else {
        iVar23 = 1;
        local_58 = 1;
      }
      if (0x1000 < (UInt32)(iVar23 * M<SInt16>(self + 0xbd4))) {
        iVar23 = 1;
      }
      if (0x1000 < local_58 * (SInt32)M<SInt16>(self + 0xbd6)) {
        local_58 = 1;
      }
    }
    else if (uVar7 == 0x200000) {
      iVar23 = 4;
      local_58 = 1;
    }
    else if (uVar7 == 0x400000) {
      iVar23 = 6;
      local_58 = 1;
    }
    else {
      if (uVar7 != 0x100000) goto LAB_0003c260;
      iVar23 = 2;
      local_58 = 1;
    }
  }
  if ((uVar28 & 0x1c0) != 0) {
    if (((uVar29 & 0x30000) == 0x20000) || ((uVar29 & 0x30000) == 0x30000)) {
      AVar12 = 0x29;
      AVar22 = 0x3;
      iVar16 = 0x29;
    }
    else {
      AVar12 = 0x10;
      AVar22 = 0x5;
      iVar16 = 0x10;
    }
    uVar7 = FormatTableLookup_0x0004d2dc(iVar16 * 0x1c);
    uVar24 = 1 << (uVar7 >> 0xc & 7);
    if (M<SInt16>(self + 0xbd6) < 0x20) {
      if (AVar22 == 0x5) {
        AVar22 = 0x4;
      }
      else {
        AVar22 = 0x2;
      }
    }
    iVar16 = 0;
    local_98[0] = 6;
    local_98[1] = 7;
    local_98[2] = 8;
    do {
      uVar26 = (UInt32)local_98[iVar16];
      if ((uVar28 >> (uVar26 & 0x3f) & 1) != 0) {
        uVar28 = local_58;
        iVar9 = iVar23;
        if (uVar26 != 6) {
          uVar28 = 1;
          iVar9 = 1;
        }
        iVar14 = (SInt32)M<SInt16>(self + 0xbd4);
        iVar25 = iVar14;
        if (((uVar29 & 0x700000) != 0) && (uVar26 == 6)) {
          iVar25 = iVar14 + 0x18;
        }
        uVar29 = iVar25 * uVar24;
        if ((uVar29 & 0xff) != 0) {
          uVar29 = (uVar29 & 0xffffff00) + 0x100;
        }
        uVar19 = (UInt32)M<SInt16>(self + 0xbd6);
        uVar29 = iVar9 * uVar29;
        uVar8 = uVar19;
        if ((uVar19 & 0x1f) != 0) {
          uVar8 = (uVar19 - (SInt32)(SInt16)(M<SInt16>(self + 0xbd6) +
                                        (SInt16)(((SInt32)uVar19 >> 5) +
                                               (UInt32)((SInt32)uVar19 < 0 && (uVar19 & 0x1f) != 0)) *
                                        -0x20)) + 0x20;
        }
        iVar27 = uVar26 * 0x78;
        iVar25 = uVar28 * uVar8 * uVar29;
        if (((uVar24 != M<UInt16>(self + iVar27 + 0xbe)) ||
            ((UInt32)M<UInt16>(self + iVar27 + 0xc4) != iVar9 * iVar14)) ||
           ((UInt32)M<UInt16>(self + iVar27 + 0xc6) != uVar28 * uVar19)) {
          if (M<SInt32>(self + iVar27 + 0xcc) != 0) {
            ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + iVar27 + 0xa8)));
          }
          if (iVar25 != M<SInt32>(self + iVar27 + 0xb8)) {
            VCALL(M<SInt32>(self), 0x5cc)(self,uVar26);
            M<SInt32>(self + iVar27 + 0xb8) = iVar25;
          }
          if (uVar24 == 0) {
            M<UInt16>(self + iVar27 + 0xbc) = 0;
          }
          else {
            M<SInt16>(self + iVar27 + 0xbc) = (SInt16)(uVar29 / uVar24);
          }
          M<SInt16>(self + iVar27 + 0xc0) = (SInt16)uVar29;
          M<SInt16>(self + iVar27 + 0xbe) = (SInt16)uVar24;
          M<SInt16>(self + iVar27 + 0xc4) = (SInt16)iVar9 * M<SInt16>(self + 0xbd4);
          M<SInt16>(self + iVar27 + 0xc6) = (SInt16)uVar28 * M<SInt16>(self + 0xbd6);
        }
        self[iVar27 + 0xe0] = AVar22;
        self[iVar27 + 0xe1] = ((UInt8)(uVar7 >> 10) & 3);
        self[iVar27 + 0xe3] = ((UInt8)(uVar7 >> 3) & 0x1f);
        self[iVar27 + 0xe2] = AVar12;
        if ((M<UInt32>(self + 0xbe8) & 0x700000) == 0) {
          if ((M<UInt32>(self + 0xbe8) & 0xc0000) == 0) {
            M<UInt32>(self + iVar27 + 0xe4) =
                 M<UInt32>(self + iVar27 + 0xe4) & 0xff000fff | 0x111000;
          }
          else {
            M<UInt32>(self + iVar27 + 0xe4) =
                 (uVar28 & 0xf) << 0xc |
                 iVar9 << 0x10 | M<UInt32>(self + iVar27 + 0xe4) & 0xff000fff | 0x100000;
          }
        }
        else {
          M<UInt32>(self + iVar27 + 0xe4) =
               iVar9 << 0x14 | M<UInt32>(self + iVar27 + 0xe4) & 0xff000fff | 0x11000;
        }
        M<UInt32>(self + iVar27 + 0xe4) = M<UInt32>(self + iVar27 + 0xe4) | 0x800;
        uVar29 = M<UInt32>(self + 0xbe8);
        uVar28 = M<UInt32>(self + 0xc18);
      }
      bVar1 = iVar16 != 2;
      iVar16 = iVar16 + 1;
    } while (bVar1);
  }
  if ((uVar29 & 0xf) < 0xe) {
    uVar29 = 1 << (uVar29 & 0xf);
    if ((uVar29 & 0x1c18) == 0) {
      if (((uVar29 & 0x2000) == 0) ||
         (AVar12 = 0x1, M<SInt16>(self + 0xbd6) < 0x10)) goto LAB_0003c52c;
    }
    else {
      AVar12 = ((0xf < M<SInt16>(self + 0xbd6)) + '\x02');
    }
  }
  else {
LAB_0003c52c:
    AVar12 = 0x0;
  }
  if ((M<SInt32>(self + 0xc14) != 0xffff) && ((uVar28 & 2) != 0)) {
    M<UInt8>(M<SInt32>(self + 0xc14) * 0x78 + M<SInt32>(self + 0xd50) + 0x164) = AVar12;
    uVar28 = M<UInt32>(self + 0xc18);
  }
  if (M<SInt32>(self + 0x90) == 0) {
    uVar29 = uVar28 & 0x23f;
  }
  else {
    uVar29 = uVar28 & 0x7ffc03;
  }
  if (uVar29 == 0) {
    return;
  }
  uVar7 = M<UInt32>(self + 0xbe8);
  iVar16 = window_mode_to_ati_format(uVar7 & 0xf);
  uVar29 = FormatTableLookup_0x0004d2dc(iVar16 * 0x1c);
  AVar22 = ((UInt8)(uVar29 >> 10) & 3);
  AVar5 = ((UInt8)(uVar29 >> 3) & 0x1f);
  uVar29 = 1 << (uVar29 >> 0xc & 7);
  if ((uVar28 & 0x200) != 0) {
    if (((uVar29 != M<UInt16>(self + 0x4f6)) ||
        ((UInt32)M<UInt16>(self + 0x4fc) != iVar23 * M<SInt16>(self + 0xbd4))) ||
       ((UInt32)M<UInt16>(self + 0x4fe) != local_58 * (SInt32)M<SInt16>(self + 0xbd6))) {
      if (M<SInt32>(self + 0x504) != 0) {
        ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + 0x4e0)));
        uVar7 = M<UInt32>(self + 0xbe8);
      }
      sVar2 = M<SInt16>(self + 0xbd4);
      iVar9 = (SInt32)sVar2;
      if ((uVar7 & 0x700000) != 0) {
        iVar9 = iVar9 + 0x18;
      }
      uVar28 = iVar9 * uVar29;
      if ((uVar28 & 0xff) != 0) {
        uVar28 = (uVar28 & 0xffffff00) + 0x100;
      }
      sVar18 = M<SInt16>(self + 0xbd6);
      uVar28 = iVar23 * uVar28;
      uVar24 = (UInt32)sVar18;
      if ((uVar24 & 0x1f) != 0) {
        uVar24 = (uVar24 - (SInt32)(SInt16)(sVar18 + (SInt16)(((SInt32)uVar24 >> 5) +
                                                        (UInt32)((SInt32)uVar24 < 0 &&
                                                              (uVar24 & 0x1f) != 0)) * -0x20)) +
                 0x20;
      }
      iVar9 = uVar28 * local_58 * uVar24;
      if (iVar9 != M<SInt32>(self + 0x4f0)) {
        VCALL(M<SInt32>(self), 0x5cc)(self,9);
        M<SInt32>(self + 0x4f0) = iVar9;
        uVar7 = M<UInt32>(self + 0xbe8);
        sVar2 = M<SInt16>(self + 0xbd4);
        sVar18 = M<SInt16>(self + 0xbd6);
      }
      if (uVar29 == 0) {
        M<UInt16>(self + 0x4f4) = 0;
      }
      else {
        M<SInt16>(self + 0x4f4) = (SInt16)(uVar28 / uVar29);
      }
      M<SInt16>(self + 0x4f8) = (SInt16)uVar28;
      M<SInt16>(self + 0x4f6) = (SInt16)uVar29;
      M<SInt16>(self + 0x4fc) = (SInt16)iVar23 * sVar2;
      M<SInt16>(self + 0x4fe) = (SInt16)local_58 * sVar18;
    }
    self[0x518] = AVar12;
    self[0x519] = AVar22;
    self[0x51b] = AVar5;
    self[0x51a] = SUB41m(iVar16,0);
    if ((uVar7 & 0x700000) == 0) {
      if ((uVar7 & 0xc0000) == 0) {
        M<UInt32>(self + 0x51c) = M<UInt32>(self + 0x51c) & 0xff000fff | 0x111000;
      }
      else {
        M<UInt32>(self + 0x51c) =
             (local_58 & 0xf) << 0xc |
             iVar23 << 0x10 | M<UInt32>(self + 0x51c) & 0xff000fff | 0x100000;
      }
    }
    else {
      M<UInt32>(self + 0x51c) = iVar23 << 0x14 | M<UInt32>(self + 0x51c) & 0xff000fff | 0x11000;
    }
  }
  GH_memcpy(local_90,kShapeSurfaceDefaultMipTable,0x38);
  uVar28 = M<UInt32>(self + 0xbe8);
  if ((uVar28 & 0x20) == 0) {
    uVar26 = 0;
    uVar7 = 1;
    uVar8 = 1;
    iVar23 = M<SInt32>(self + 0xc14) * 0x78 + M<SInt32>(self + 0xd50);
    iVar9 = M<SInt32>(iVar23 + 0x13c);
    uVar24 = (UInt32)M<UInt16>(iVar23 + 0x144);
  }
  else if ((uVar28 & 0x70000000) == 0) {
    uVar24 = uVar29 * (SInt32)M<SInt16>(self + 0xbd4);
    if ((uVar24 & 0xff) != 0) {
      uVar24 = (uVar24 & 0xffffff00) + 0x100;
    }
    uVar28 = (UInt32)M<SInt16>(self + 0xbd6);
    if ((uVar28 & 0x1f) != 0) {
      uVar28 = (uVar28 - (SInt32)(SInt16)(M<SInt16>(self + 0xbd6) +
                                     (SInt16)(((SInt32)uVar28 >> 5) +
                                            (UInt32)((SInt32)uVar28 < 0 && (uVar28 & 0x1f) != 0)) * -0x20
                                     )) + 0x20;
    }
    iVar9 = uVar24 * uVar28;
    uVar26 = 0;
    uVar7 = 1;
    uVar8 = 1;
  }
  else {
    uVar7 = (UInt32)M<SInt16>(self + 0xbd4);
    uVar8 = uVar29 * uVar7;
    uVar24 = uVar8;
    if ((uVar8 & 0xff) != 0) {
      uVar24 = (uVar8 & 0xffffff00) + 0x100;
    }
    uVar13 = (UInt32)M<SInt16>(self + 0xbd6);
    uVar26 = uVar28 >> 0x18 & 0xf;
    iVar9 = 0;
    uVar17 = 0;
    uVar19 = uVar13;
    while( true ) {
      bVar1 = uVar17 != 0;
      local_90[uVar17] = iVar9;
      if (bVar1) {
        uVar10 = 0x20;
      }
      else {
        uVar10 = 0x100;
      }
      if (uVar8 != (uVar8 / uVar10) * uVar10) {
        if (bVar1) {
          uVar10 = 0x20;
          iVar23 = 0x20;
        }
        else {
          uVar10 = 0x100;
          iVar23 = 0x100;
        }
        uVar8 = iVar23 + (uVar8 / uVar10) * uVar10;
      }
      uVar10 = uVar19;
      if ((!bVar1) && ((uVar19 & 0x1f) != 0)) {
        uVar10 = (uVar19 & 0xffffffe0) + 0x20;
      }
      iVar9 = iVar9 + uVar8 * uVar10;
      if (1 < uVar7) {
        uVar7 = uVar7 >> 1;
      }
      if (1 < uVar19) {
        uVar19 = uVar19 >> 1;
      }
      uVar17 = uVar17 + 1;
      if (uVar26 < uVar17) break;
      uVar8 = uVar29 * uVar7;
    }
    uVar8 = uVar26 + 1;
    uVar7 = 6;
    local_90[uVar17] = iVar9;
    if ((uVar28 & 0x70000000) != 0x30000000) {
      uVar7 = 1;
    }
    iVar9 = iVar9 * uVar7;
    if (uVar29 == 0x10) {
      if (uVar8 == 1) {
        if (uVar7 == 1) {
          if ((SInt32)uVar13 < 0x10) {
            AVar12 = 0x0;
            uVar7 = 1;
          }
          else {
            AVar12 = 0x1;
            uVar7 = 1;
            uVar8 = 1;
          }
        }
        else {
LAB_0003c9c4:
          AVar12 = 0x0;
          uVar8 = 1;
        }
      }
      else {
LAB_0003c9d0:
        AVar12 = 0x0;
      }
    }
    else {
      if (uVar8 != 1) goto LAB_0003c9d0;
      if (uVar7 != 1) goto LAB_0003c9c4;
      if ((SInt32)uVar13 < 0x10) {
        AVar12 = 0x2;
        uVar7 = 1;
      }
      else {
        AVar12 = 0x3;
        uVar7 = 1;
      }
    }
  }
  local_98[0] = 0;
  local_98[1] = 1;
  if (M<SInt32>(self + 0x90) == 0) {
    uVar28 = 6;
    local_98[2] = 5;
    local_98[3] = 4;
    local_98[4] = 2;
    local_98[5] = 3;
  }
  else {
    iVar23 = (SInt32)M<SInt16>(self + 0x98) - (SInt32)M<SInt16>(self + 0x96);
    uVar28 = (SInt32)M<SInt16>(self + 0x9a) - (SInt32)M<SInt16>(self + 0x94);
    if (iVar23 == 0) {
      iVar23 = 0x300;
      uVar6 = 0x300;
    }
    else {
      uVar6 = (UInt16)iVar23;
    }
    if (uVar28 == 0) {
      uVar28 = 0x240;
      uVar19 = 0;
      uVar21 = 0x240;
    }
    else {
      uVar19 = uVar28 & 0xf;
      uVar21 = (UInt16)uVar28;
    }
    uVar24 = iVar23 * uVar29;
    if ((uVar24 & 0xff) != 0) {
      uVar24 = (uVar24 & 0xffffff00) + 0x100;
    }
    if (uVar19 != 0) {
      uVar28 = (uVar28 & 0xfffffff0) + 0x10;
    }
    iVar9 = uVar24 * uVar28;
    M<UInt16>(self + 0xbe0) = uVar6;
    M<UInt16>(self + 0xbe2) = uVar21;
    self[0xbec] = 0x1;
    M<UInt16>(self + 0xbd4) = uVar6;
    M<UInt16>(self + 0xbd6) = uVar21;
    uVar28 = 2;
  }
  uVar13 = M<UInt32>(self + 0xc18);
  uVar19 = 0;
  do {
    uVar17 = (UInt32)local_98[uVar19];
    if ((uVar13 >> (uVar17 & 0x3f) & 1) != 0) {
      iVar23 = uVar17 * 0x78;
      if (((uVar29 != M<UInt16>(self + iVar23 + 0xbe)) ||
          ((UInt32)M<UInt16>(self + iVar23 + 0xc4) != (SInt32)M<SInt16>(self + 0xbd4))) ||
         (((UInt32)M<UInt16>(self + iVar23 + 0xc6) != (SInt32)M<SInt16>(self + 0xbd6) ||
          ((uVar7 != M<UInt16>(self + iVar23 + 200) ||
           (uVar8 != M<UInt16>(self + iVar23 + 0xca))))))) {
        if (M<SInt32>(self + iVar23 + 0xcc) != 0) {
          ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + iVar23 + 0xa8)));
        }
        if (iVar9 != M<SInt32>(self + iVar23 + 0xb8)) {
          VCALL(M<SInt32>(self), 0x5cc)(self,uVar17);
          M<SInt32>(self + iVar23 + 0xb8) = iVar9;
        }
        if (uVar29 == 0) {
          M<UInt16>(self + iVar23 + 0xbc) = 0;
        }
        else {
          M<SInt16>(self + iVar23 + 0xbc) = (SInt16)(uVar24 / uVar29);
        }
        uVar13 = 0;
        M<SInt16>(self + iVar23 + 0xbe) = (SInt16)uVar29;
        M<SInt16>(self + iVar23 + 0xc0) = (SInt16)uVar24;
        pAVar15 = self + iVar23 + 0xe8;
        M<UInt16>(self + iVar23 + 0xc4) = M<UInt16>(self + 0xbd4);
        uVar6 = M<UInt16>(self + 0xbd6);
        M<SInt16>(self + iVar23 + 0xca) = (SInt16)uVar8;
        M<SInt16>(self + iVar23 + 200) = (SInt16)uVar7;
        M<UInt16>(self + iVar23 + 0xc6) = uVar6;
        piVar11 = local_90;
        do {
          uVar13 = uVar13 + 1;
          iVar25 = *piVar11;
          piVar11 = piVar11 + 1;
          M<SInt32>(pAVar15) = iVar25;
          pAVar15 = pAVar15 + 4;
        } while (uVar13 <= uVar26 + 1);
      }
      self[iVar23 + 0xe2] = SUB41m(iVar16,0);
      self[iVar23 + 0xe0] = AVar12;
      self[iVar23 + 0xe1] = AVar22;
      self[iVar23 + 0xe3] = AVar5;
      uVar13 = M<UInt32>(self + 0xc18);
    }
    uVar19 = uVar19 + 1;
  } while (uVar19 < uVar28);
  if ((uVar13 & 0x7ffc00) == 0) {
    return;
  }
  if (M<SInt32>(self + 0x90) == 0) {
    return;
  }
  sVar2 = M<SInt16>(self + 0x98);
  sVar18 = M<SInt16>(self + 0x96);
  uVar28 = 10;
  iVar23 = (SInt32)M<SInt16>(self + 0x9a) - (SInt32)M<SInt16>(self + 0x94);
  uVar29 = iVar23 * 3;
  uVar6 = (UInt16)uVar29;
  uVar21 = (UInt16)(uVar29 >> 1);
  pAVar15 = self;
  while( true ) {
    if ((1 << (uVar28 & 0x3f) & uVar13) != 0) {
      if (M<SInt32>(pAVar15 + 0x57c) != 0) {
        ((IOATIR500Surface *)((UInt8 *)self))->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + uVar28 * 0x78 + 0xa8)));
      }
      M<SInt16>(pAVar15 + 0x574) = sVar2 - sVar18;
      uVar20 = uVar21;
      if ((((M<SInt32>(self + 0xdac) != 0) && (9 < uVar28)) && (uVar28 < 0xf)) &&
         ((uVar20 = uVar6, M<SInt32>(pAVar15 + 0x560) != 0 &&
          ((UInt32)M<UInt16>(pAVar15 + 0x576) != (uVar29 & 0xffff))))) {
        ((IOATIR500Surface *)((UInt8 *)self))->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + uVar28 * 0x78 + 0xa8)));
      }
      M<UInt16>(pAVar15 + 0x576) = uVar20;
      if (uVar28 == 0x11) {
        self[0x8da] = 0x2e;
      }
      else if (uVar28 == 0x10) {
        M<UInt16>(self + 0x844) = 0x2d0;
        if ((iVar23 == 0x240) || (iVar23 == 0x120)) {
          M<UInt16>(self + 0x846) = 0x240;
        }
        else {
          M<UInt16>(self + 0x846) = 0x1e0;
        }
        self[0x862] = 0xb;
      }
      else if (uVar28 == 0x12) {
        M<SInt16>(self + 0x936) = (SInt16)iVar23;
        self[0x952] = 0xb;
      }
      else {
        pAVar15[0x592] = 0x2d;
      }
      uVar3 = M<UInt16>(pAVar15 + 0x574);
      uVar24 = (UInt32)uVar3;
      iVar16 = (UInt32)(UInt8)pAVar15[0x592] * 0x1c;
      pAVar15[0x593] = ((UInt8)(FormatTableLookup_0x0004d2dc(iVar16) >> 3) & 0x1f);
      uVar7 = 1 << (FormatTableLookup_0x0004d2dc(iVar16) >> 0xc & 7);
      uVar20 = (UInt16)uVar7;
      M<UInt16>(pAVar15 + 0x56e) = uVar20;
      pAVar15[0x591] = ((UInt8)(FormatTableLookup_0x0004d2dc(iVar16) >> 10) & 3);
      if ((uVar3 & 0xff) != 0) {
        uVar24 = (uVar3 & 0xffffff00) + 0x100;
      }
      uVar7 = uVar7 & 0xffff;
      M<SInt16>(pAVar15 + 0x570) = (SInt16)(uVar24 * uVar7);
      if (uVar7 == 0) {
        M<UInt16>(pAVar15 + 0x56c) = uVar20;
      }
      else {
        M<SInt16>(pAVar15 + 0x56c) = (SInt16)((uVar24 * uVar7 & 0xffff) / uVar7);
      }
      if (uVar28 == 0x12) {
        self[0x950] = AVar12;
      }
      else {
        pAVar15[0x590] = 0x0;
      }
      uVar3 = M<UInt16>(pAVar15 + 0x570);
      uVar4 = M<UInt16>(pAVar15 + 0x576);
      if ((UInt32)uVar3 * (UInt32)uVar4 != M<SInt32>(pAVar15 + 0x568)) {
        VCALL(M<SInt32>(self), 0x5cc)(self,uVar28);
        M<UInt32>(pAVar15 + 0x568) = (UInt32)uVar3 * (UInt32)uVar4;
      }
    }
    bVar1 = uVar28 == 0x16;
    pAVar15 = pAVar15 + 0x78;
    uVar28 = uVar28 + 1;
    if (bVar1) break;
    uVar13 = M<UInt32>(self + 0xc18);
  }
  if (M<SInt32>(self + 0xda4) != 0) {
    if (self[0xbf0] != 0x0) goto LAB_0003ce90;
    AVar12 = this->alloc_overlay();
    self[0xbf0] = AVar12;
  }
  if (self[0xbf0] == 0x0) {
    return;
  }
LAB_0003ce90:
  iVar23 = this->getFramebufferIndex();
  piVar11 = M<SInt32 *>(self + iVar23 * 8 + 0xd60);
  if (((*piVar11 != 0) && (M<SInt16>(piVar11 + 4) != 0)) && (M<SInt16>((SInt32)piVar11 + 0x12) != 0))
  {
    setup_overlay();
  }
  return;
}
