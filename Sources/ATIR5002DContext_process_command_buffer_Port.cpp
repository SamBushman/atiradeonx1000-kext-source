/*
 * ATIR5002DContext_process_command_buffer_Port.cpp
 *
 * ATIR5002DContext::process_command_buffer (real addr 0x326d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");


/* real addr 0x326d0 */
IOReturn ATIR5002DContext::process_command_buffer(VendorCommandDescriptor *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 bVar1;
  UInt8 bVar2;
  UInt16 uVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt8 *pVVar9;
  UInt32 uVar10;
  UInt8 *this_00;
  SInt32 iVar11;
  SInt32 iVar12;
  UInt32 uVar13;
  SInt32 iVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 uVar17;
  UInt32 *puVar18;
  UInt8 *local_68;
  
  uVar13 = 0;
  iVar14 = 0;
  uVar15 = 0xffffffff;
  puVar18 = (UInt32 *)(M<SInt32>(self + 0xac) + 0x1c);
  do {
    uVar17 = *puVar18;
    uVar6 = uVar17 & 0xff000000;
    if (uVar6 == 0xa000000) {
LAB_00032d30:
      uVar7 = puVar18[1];
      if (M<UInt32>(M<SInt32>(self + 0x94) + 0xcc) <= uVar7) {
        uVar7 = 0;
      }
      iVar12 = uVar7 * 0x78 + M<SInt32>(self + 0x94) + 300;
      if (uVar6 != 0x9000000) {
LAB_00032f30:
        *puVar18 = 0x1150;
        uVar6 = M<UInt32>(iVar12 + 8);
        bVar1 = M<UInt8>(iVar12 + 0x38);
LAB_00032f3c:
        puVar18[1] = uVar6 & 0xffffffe0 | (bVar1 & 1) << 2 | (bVar1 & 6) << 2;
        goto LAB_00032f54;
      }
LAB_00032ee0:
      *puVar18 = 0x80000000;
      puVar18[1] = 0x575;
      bVar1 = M<UInt8>(iVar12 + 0x38);
      uVar3 = M<UInt16>(iVar12 + 0x18);
      uVar6 = M<UInt32>(iVar12 + 8);
LAB_00032ef4:
      uVar7 = 0x80000000;
      if (bVar1 < 2) {
        uVar7 = 0;
      }
      puVar18[5] = uVar7 | uVar6 >> 10 | (uVar3 & 0x3fc0) << 0x10 | (bVar1 & 1) << 0x1e;
      uVar17 = uVar17 & 0xffffff;
    }
    else if (uVar6 < 0xa000001) {
      if (uVar6 == 0x5000000) {
        if (M<SInt32>(self + 0x114) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + 0x114) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + 0x94) + 0x50);
          M<UInt32>(self + 0x114) = 0;
        }
        *puVar18 = 0x80000000;
        goto LAB_00032f54;
      }
      if (uVar6 < 0x5000001) {
        if ((uVar6 == 0x3000000) || (uVar6 == 0x4000000)) {
          if (M<SInt32>(self + 0x114) != 0) {
            M<UInt32>(M<SInt32>(M<SInt32>(self + 0x114) + 0x14) + 8) =
                 M<UInt32>(M<SInt32>(self + 0x94) + 0x50);
            M<UInt32>(self + 0x114) = 0;
          }
          if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar18[1]) ||
             (pVVar9 = *(UInt8 **)
                        (puVar18[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
             pVVar9 == (UInt8 *)0x0)) goto LAB_00033420;
          if (M<char>(M<SInt32>(pVVar9 + 0x14) + 0x14) != '\0') {
            uVar16 = uVar15;
            if (uVar15 != 0) {
              uVar16 = 0;
              M<UInt32>(M<SInt32>(self + 0x94) + 0x700) =
                   uVar15 * 4 + M<SInt32>(M<SInt32>(self + 0x94) + 0x700);
              iVar12 = iVar14 + M<SInt32>(self + 0xac);
              iVar11 = iVar14 + M<SInt32>(self + 0x9c);
              iVar14 = iVar14 + uVar15 * 4;
              uVar10 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x94)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                  iVar11 + 0x20,uVar15);
              M<UInt32>(self + 0xa8) = uVar10;
            }
            this->alloc_and_load_image((VendorTextureBuffer *)(pVVar9));
            uVar15 = uVar16;
            if (M<SInt32>(self + 0x9c) == 0) {
              ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)));
            }
          }
          if (M<SInt32>(pVVar9 + 0x48) != 0) {
            M<UInt32>(M<SInt32>(pVVar9 + 0x24) + 0x28) = M<UInt32>(pVVar9 + 0x28);
            M<UInt32>(M<SInt32>(pVVar9 + 0x28) + 0x24) = M<UInt32>(pVVar9 + 0x24);
            M<UInt32>(pVVar9 + 0x24) = M<UInt32>(M<SInt32>(self + 0x94) + 0x600);
            M<SInt32>(pVVar9 + 0x28) = M<SInt32>(self + 0x94) + 0x5dc;
            M<UInt8 *>(M<SInt32>(self + 0x94) + 0x600) = pVVar9;
            M<UInt8 *>(M<SInt32>(pVVar9 + 0x24) + 0x28) = pVVar9;
          }
          if (M<SInt32>(pVVar9 + 4) != 0) {
            GH_IOGetTime(pVVar9 + 0x2c);
            M<UInt32>(M<SInt32>(pVVar9 + 0x34) + 0x38) = M<UInt32>(pVVar9 + 0x38);
            M<UInt32>(M<SInt32>(pVVar9 + 0x38) + 0x34) = M<UInt32>(pVVar9 + 0x34);
            M<UInt32>(pVVar9 + 0x34) = M<UInt32>(M<SInt32>(self + 0x94) + 0x6d0);
            M<SInt32>(pVVar9 + 0x38) = M<SInt32>(self + 0x94) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + 0x94) + 0x6d0) = pVVar9;
            M<UInt8 *>(M<SInt32>(pVVar9 + 0x34) + 0x38) = pVVar9;
          }
          uVar7 = M<UInt32>(pVVar9 + 0x48);
          if (uVar6 == 0x4000000) {
            *puVar18 = 0x1150;
            puVar18[1] = -(M<UInt8>(M<SInt32>(pVVar9 + 0x14) + 0x15) >> 3 & 3) >> 0x1c & 8 |
                         uVar7 & 0xffffffe0 | M<UInt8>(M<SInt32>(pVVar9 + 0x14) + 0x15) & 4;
          }
          else {
            *puVar18 = 0x80000000;
            puVar18[1] = 0x575;
            puVar18[5] = uVar7 >> 10 | (puVar18[5] & 0x3fc0) << 0x10;
          }
          uVar17 = uVar17 & 0xffffff;
          M<UInt8 *>(self + 0x114) = pVVar9;
        }
        else {
          if (uVar6 != 0x2000000) goto LAB_00032f54;
          *puVar18 = 0x80000000;
          uVar13 = 1;
          uVar17 = uVar17 & 0xffffff;
        }
        goto LAB_00033430;
      }
      if (uVar6 == 0x7000000) {
LAB_00032a78:
        M<UInt32>(M<SInt32>(self + 200) + 0x1c) = M<UInt32>(M<SInt32>(self + 200) + 0x1c) | 1;
        if (M<SInt32>(self + 0x114) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + 0x114) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + 0x94) + 0x50);
          M<UInt32>(self + 0x114) = 0;
        }
        if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar18[1]) ||
           (local_68 = *(UInt8 **)
                        (puVar18[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
           local_68 == (UInt8 *)0x0)) goto LAB_00033420;
        if (M<char>(M<SInt32>(local_68 + 0x14) + 0x14) == '\0') {
          if (M<SInt32>(local_68 + 4) != 0) {
            GH_IOGetTime(local_68 + 0x2c);
            M<UInt32>(M<SInt32>(local_68 + 0x34) + 0x38) = M<UInt32>(local_68 + 0x38);
            M<UInt32>(M<SInt32>(local_68 + 0x38) + 0x34) = M<UInt32>(local_68 + 0x34);
            M<UInt32>(local_68 + 0x34) = M<UInt32>(M<SInt32>(self + 0x94) + 0x6d0);
            M<SInt32>(local_68 + 0x38) = M<SInt32>(self + 0x94) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + 0x94) + 0x6d0) = local_68;
            M<UInt8 *>(M<SInt32>(local_68 + 0x34) + 0x38) = local_68;
          }
        }
        else {
          uVar16 = uVar15;
          if (uVar15 != 0) {
            uVar16 = 0;
            M<UInt32>(M<SInt32>(self + 0x94) + 0x700) =
                 uVar15 * 4 + M<SInt32>(M<SInt32>(self + 0x94) + 0x700);
            iVar12 = iVar14 + M<SInt32>(self + 0xac);
            iVar11 = iVar14 + M<SInt32>(self + 0x9c);
            iVar14 = iVar14 + uVar15 * 4;
            uVar10 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x94)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                iVar11 + 0x20,uVar15);
            M<UInt32>(self + 0xa8) = uVar10;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(local_68));
          uVar15 = uVar16;
          if (M<SInt32>(self + 0x9c) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)));
          }
        }
        iVar12 = M<SInt32>(self + 0x94);
        uVar7 = M<SInt32>(local_68 + 4) + M<SInt32>(iVar12 + 0x8a4);
        if (uVar6 == 0x7000000) {
          *puVar18 = 0x80000000;
          puVar18[1] = 0x575;
          puVar18[5] = uVar7 >> 10 | (puVar18[5] & 0x3fc0) << 0x10;
        }
        else {
          uVar6 = puVar18[2];
          if ((puVar18[4] == 0) || (puVar18[5] == 0)) {
            iVar11 = M<SInt32>(local_68 + 0x14);
          }
          else {
            iVar11 = M<SInt32>(local_68 + 0x14);
            iVar4 = (puVar18[4] & 0xff) * 0x1c;
            if ((M<UInt8>(iVar11 + 0x15) & 0x18) == 0) {
              uVar8 = FormatTableLookup_0x0004d2dc(iVar4);
              iVar4 = 0;
            }
            else {
              uVar8 = FormatTableLookup_0x0004d2dc(iVar4);
              iVar4 = -(uVar8 >> 8 & 3);
            }
            iVar5 = (SInt32)puVar18[5] >> ((iVar4 - (uVar8 >> 0xc & 7)) + 5 & 0x3f);
            iVar4 = iVar5 << 5;
            if ((M<UInt8>(iVar11 + 0x15) >> 2 & 1) != 0) {
              iVar4 = (iVar5 << 0xc) >> 3;
            }
            uVar7 = uVar7 + iVar4;
          }
          if (puVar18[3] != 0) {
            uVar7 = uVar7 + puVar18[3];
          }
          *puVar18 = 0x80000000;
          puVar18[1] = 0x80000000;
          puVar18[2] = 0x80000000;
          puVar18[3] = 0x80000000;
          puVar18[4] = 0x1150;
          puVar18[5] = -(M<UInt8>(iVar11 + 0x15) >> 3 & 3) >> 0x1c & 8 |
                       uVar6 & 3 | uVar7 & 0xffffffe0 | M<UInt8>(iVar11 + 0x15) & 4;
        }
LAB_00033400:
        uVar17 = uVar17 & 0xffffff;
        M<UInt8 *>(self + 0x114) = local_68;
        if (local_68 != (UInt8 *)0x0) {
          M<UInt32>(M<SInt32>(local_68 + 0x14) + 8) = M<UInt32>(iVar12 + 0x50);
        }
      }
      else {
        if (uVar6 < 0x7000001) {
          if (uVar6 == 0x6000000) {
            *puVar18 = 0x80000000;
            puVar18[1] = 0x80000000;
            puVar18[2] = 0x80000000;
            puVar18[3] = 0x80000000;
            puVar18[4] = 0x80000000;
            puVar18[5] = 0x80000000;
            puVar18[6] = 0x80000000;
            puVar18[7] = 0x80000000;
            uVar17 = uVar17 & 0xffffff;
            goto LAB_00033430;
          }
        }
        else {
          if (uVar6 == 0x8000000) goto LAB_00032a78;
          if (uVar6 == 0x9000000) goto LAB_00032d30;
        }
LAB_00032f54:
        uVar17 = uVar17 & 0xffffff;
      }
    }
    else {
      if (uVar6 == 0xe000000) {
LAB_00032ea0:
        if (M<SInt32>(self + 0x100) == 0) {
          iVar12 = M<SInt32>(self + 0x110) * 0x78 + M<SInt32>(self + 0x94) + 300;
        }
        else {
          iVar12 = M<SInt32>(M<SInt32>(self + 0x100) + 0xb70);
        }
        if (uVar6 != 0xd000000) goto LAB_00032f30;
        goto LAB_00032ee0;
      }
      if (uVar6 < 0xe000001) {
        if (uVar6 != 0xc000000) {
          if (uVar6 == 0xd000000) goto LAB_00032ea0;
          if (uVar6 != 0xb000000) goto LAB_00032f54;
        }
        this_00 = (UInt8 *)
                  ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->find_surface_for_id(puVar18[1]);
        uVar16 = uVar15;
        if (this_00 == (UInt8 *)0x0) {
LAB_00032e64:
          iVar12 = M<SInt32>(self + 0x94) + 300;
          uVar15 = uVar16;
        }
        else {
          uVar7 = M<UInt32>(this_00 + 0xbf8);
          if ((uVar7 & 0x20000000) == 0) {
            uVar8 = M<UInt32>(this_00 + 0xc18);
            if ((uVar7 & uVar8 & 3) != 0) {
              if (uVar15 != 0) {
                uVar16 = 0;
                M<UInt32>(M<SInt32>(self + 0x94) + 0x700) =
                     uVar15 * 4 + M<SInt32>(M<SInt32>(self + 0x94) + 0x700);
                iVar12 = iVar14 + M<SInt32>(self + 0xac);
                iVar11 = iVar14 + M<SInt32>(self + 0x9c);
                iVar14 = iVar14 + uVar15 * 4;
                uVar10 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x94)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                    iVar11 + 0x20,uVar15);
                M<UInt32>(self + 0xa8) = uVar10;
                uVar7 = M<UInt32>(this_00 + 0xbf8);
                uVar8 = M<UInt32>(this_00 + 0xc18);
              }
              if ((uVar8 & uVar7 & 1) != 0) {
                ((IOATIR500Surface *)(this_00))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + 0x100)),(VendorTextureBuffer **)((UInt8 **)0x0),
                           0,1);
                uVar7 = M<UInt32>(this_00 + 0xbf8);
                uVar8 = M<UInt32>(this_00 + 0xc18);
              }
              if ((uVar8 & uVar7 & 2) != 0) {
                ((IOATIR500Surface *)(this_00))->alloc_surfaces_keep((IOATIR500Surface *)(M<UInt8 *>(self + 0x100)),(VendorTextureBuffer **)((UInt8 **)0x0),
                           0,2);
              }
              if (M<SInt32>(self + 0x9c) == 0) {
                ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)));
              }
            }
            iVar12 = M<SInt32>(this_00 + 0xb70);
            uVar15 = uVar16;
            if (M<SInt32>(iVar12 + 8) == 0) goto LAB_00032e64;
          }
          else {
            iVar12 = M<SInt32>(this_00 + 0xb70);
          }
        }
        if (uVar6 != 0xb000000) {
          *puVar18 = 0x1150;
          uVar6 = M<UInt32>(iVar12 + 8);
          bVar1 = M<UInt8>(iVar12 + 0x38);
          goto LAB_00032f3c;
        }
        *puVar18 = 0x80000000;
        puVar18[1] = 0x575;
        bVar1 = M<UInt8>(iVar12 + 0x38);
        uVar3 = M<UInt16>(iVar12 + 0x18);
        uVar6 = M<UInt32>(iVar12 + 8);
        goto LAB_00032ef4;
      }
      if (uVar6 == 0x11000000) {
        iVar12 = puVar18[1] * 0x78 + M<SInt32>(self + 0x94);
        *puVar18 = 0x138a;
        puVar18[1] = M<UInt32>(iVar12 + 0x134) & 0xffffffe0;
        puVar18[2] = 0x138e;
        bVar1 = M<UInt8>(iVar12 + 0x165);
        bVar2 = M<UInt8>(iVar12 + 0x167);
        uVar6 = M<UInt16>(iVar12 + 0x140) & 0x3ffe | (M<UInt8>(iVar12 + 0x164) & 1) << 0x10 |
                (M<UInt8>(iVar12 + 0x164) & 6) << 0x10;
LAB_0003323c:
        puVar18[3] = uVar6 | (bVar1 & 3) << 0x13 | (bVar2 & 0xf) << 0x15;
        goto LAB_00032f54;
      }
      if (0x11000000 < uVar6) {
        if (uVar6 == 0x12000000) {
          if (M<SInt32>(self + 0x100) == 0) {
            iVar12 = M<SInt32>(self + 0x110) * 0x78 + M<SInt32>(self + 0x94) + 300;
          }
          else {
            iVar12 = M<SInt32>(M<SInt32>(self + 0x100) + 0xb70);
          }
          *puVar18 = 0x138a;
          puVar18[1] = M<UInt32>(iVar12 + 8) & 0xffffffe0;
          puVar18[2] = 0x138e;
          bVar1 = M<UInt8>(iVar12 + 0x39);
          bVar2 = M<UInt8>(iVar12 + 0x3b);
          uVar6 = M<UInt16>(iVar12 + 0x14) & 0x3ffe | (M<UInt8>(iVar12 + 0x38) & 1) << 0x10 |
                  (M<UInt8>(iVar12 + 0x38) & 6) << 0x10;
          goto LAB_0003323c;
        }
        if (uVar6 != 0x13000000) goto LAB_00032f54;
        M<UInt32>(M<SInt32>(self + 200) + 0x1c) = M<UInt32>(M<SInt32>(self + 200) + 0x1c) | 1;
        if (M<SInt32>(self + 0x114) != 0) {
          M<UInt32>(M<SInt32>(M<SInt32>(self + 0x114) + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + 0x94) + 0x50);
          M<UInt32>(self + 0x114) = 0;
        }
        if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar18[1]) ||
           (local_68 = *(UInt8 **)
                        (puVar18[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
           local_68 == (UInt8 *)0x0)) goto LAB_00033420;
        if (M<char>(M<SInt32>(local_68 + 0x14) + 0x14) == '\0') {
          if (M<SInt32>(local_68 + 4) != 0) {
            GH_IOGetTime(local_68 + 0x2c);
            M<UInt32>(M<SInt32>(local_68 + 0x34) + 0x38) = M<UInt32>(local_68 + 0x38);
            M<UInt32>(M<SInt32>(local_68 + 0x38) + 0x34) = M<UInt32>(local_68 + 0x34);
            M<UInt32>(local_68 + 0x34) = M<UInt32>(M<SInt32>(self + 0x94) + 0x6d0);
            M<SInt32>(local_68 + 0x38) = M<SInt32>(self + 0x94) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + 0x94) + 0x6d0) = local_68;
            M<UInt8 *>(M<SInt32>(local_68 + 0x34) + 0x38) = local_68;
          }
        }
        else {
          uVar16 = uVar15;
          if (uVar15 != 0) {
            uVar16 = 0;
            M<UInt32>(M<SInt32>(self + 0x94) + 0x700) =
                 uVar15 * 4 + M<SInt32>(M<SInt32>(self + 0x94) + 0x700);
            iVar12 = iVar14 + M<SInt32>(self + 0xac);
            iVar11 = iVar14 + M<SInt32>(self + 0x9c);
            iVar14 = iVar14 + uVar15 * 4;
            uVar10 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x94)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                iVar11 + 0x20,uVar15);
            M<UInt32>(self + 0xa8) = uVar10;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(local_68));
          uVar15 = uVar16;
          if (M<SInt32>(self + 0x9c) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)));
          }
        }
        uVar6 = puVar18[2];
        *puVar18 = 0x80000000;
        puVar18[1] = 0x80000000;
        puVar18[2] = 0x1151;
        iVar12 = M<SInt32>(self + 0x94);
        puVar18[3] = -(M<UInt8>(M<SInt32>(local_68 + 0x14) + 0x15) >> 3 & 3) >> 0x1c & 8 |
                     uVar6 & 3 | M<SInt32>(local_68 + 4) + M<SInt32>(iVar12 + 0x8a4) & 0xffffffe0U |
                     M<UInt8>(M<SInt32>(local_68 + 0x14) + 0x15) & 4;
        goto LAB_00033400;
      }
      if (uVar6 != 0x10000000) goto LAB_00032f54;
      M<UInt32>(M<SInt32>(self + 200) + 0x1c) = M<UInt32>(M<SInt32>(self + 200) + 0x1c) | 1;
      uVar6 = puVar18[2];
      uVar7 = puVar18[3];
      if (M<SInt32>(self + 0x114) != 0) {
        M<UInt32>(M<SInt32>(M<SInt32>(self + 0x114) + 0x14) + 8) =
             M<UInt32>(M<SInt32>(self + 0x94) + 0x50);
        M<UInt32>(self + 0x114) = 0;
      }
      if ((puVar18[1] < M<UInt32>(M<SInt32>(self + 0x88) + 0x14)) &&
         (pVVar9 = *(UInt8 **)
                    (puVar18[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
         pVVar9 != (UInt8 *)0x0)) {
        if (M<char>(M<SInt32>(pVVar9 + 0x14) + 0x14) == '\0') {
          if (M<SInt32>(pVVar9 + 4) != 0) {
            GH_IOGetTime(pVVar9 + 0x2c);
            M<UInt32>(M<SInt32>(pVVar9 + 0x34) + 0x38) = M<UInt32>(pVVar9 + 0x38);
            M<UInt32>(M<SInt32>(pVVar9 + 0x38) + 0x34) = M<UInt32>(pVVar9 + 0x34);
            M<UInt32>(pVVar9 + 0x34) = M<UInt32>(M<SInt32>(self + 0x94) + 0x6d0);
            M<SInt32>(pVVar9 + 0x38) = M<SInt32>(self + 0x94) + 0x69c;
            M<UInt8 *>(M<SInt32>(self + 0x94) + 0x6d0) = pVVar9;
            M<UInt8 *>(M<SInt32>(pVVar9 + 0x34) + 0x38) = pVVar9;
          }
        }
        else {
          uVar16 = uVar15;
          if (uVar15 != 0) {
            uVar16 = 0;
            M<UInt32>(M<SInt32>(self + 0x94) + 0x700) =
                 uVar15 * 4 + M<SInt32>(M<SInt32>(self + 0x94) + 0x700);
            iVar12 = iVar14 + M<SInt32>(self + 0xac);
            iVar11 = iVar14 + M<SInt32>(self + 0x9c);
            iVar14 = iVar14 + uVar15 * 4;
            uVar10 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x94)))->submit_buffer((UInt32 *)(iVar12 + 0x20),
                                iVar11 + 0x20,uVar15);
            M<UInt32>(self + 0xa8) = uVar10;
          }
          this->alloc_and_load_image((VendorTextureBuffer *)(pVVar9));
          uVar15 = uVar16;
          if (M<SInt32>(self + 0x9c) == 0) {
            ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)));
          }
        }
        *puVar18 = 0x138a;
        puVar18[1] = M<UInt32>(pVVar9 + 0x48) & 0xffffffe0;
        puVar18[2] = 0x138e;
        puVar18[3] = -(M<UInt8>(M<SInt32>(pVVar9 + 0x14) + 0x15) >> 3 & 3) >> 0xe & 0x20000 |
                     uVar6 & 0x3ffe | (M<UInt8>(M<SInt32>(pVVar9 + 0x14) + 0x15) & 4) << 0xe |
                     (uVar7 & 0xf) << 0x15;
        uVar17 = uVar17 & 0xffffff;
        M<UInt8 *>(self + 0x114) = pVVar9;
        if (pVVar9 != (UInt8 *)0x0) {
          M<UInt32>(M<SInt32>(pVVar9 + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + 0x94) + 0x50);
        }
        goto LAB_00033430;
      }
LAB_00033420:
      uVar15 = 0;
      uVar17 = 0;
    }
LAB_00033430:
    uVar15 = uVar15 + uVar17;
    puVar18 = puVar18 + uVar17;
    if (uVar17 == 0) {
      if ((uVar15 & 1) != 0) {
        *puVar18 = 0x80000000;
        uVar15 = uVar15 + 1;
        puVar18 = puVar18 + 1;
      }
      M<SInt32>(param_1) = iVar14 + M<SInt32>(self + 0xac) + 0x20;
      iVar12 = M<SInt32>(self + 0x9c);
      M<UInt32 *>(param_1 + 0xc) = puVar18;
      M<UInt32>(param_1 + 8) = uVar15;
      M<SInt32>(param_1 + 4) = iVar14 + iVar12 + 0x20;
      return uVar13;
    }
  } while( true );
}
