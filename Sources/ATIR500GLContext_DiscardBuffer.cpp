/*
 * ATIR500GLContext_DiscardBuffer.cpp
 *
 * ATIR500GLContext::discard_command_buffer (real addr 0x27580, 2228 bytes): walks the not-yet-submitted command
 * buffer's embedded-opcode stream and drops every texture / vertex-buffer / query reference it had bound (an atomic
 * lwarx/stwcx. decrement of the record's outstanding count at texture->+0x14->+0x10; at 1 -> 0 it calls
 * IOATIR500Shared::delete_texture), takes the references the discarded stream would have taken, and rebuilds the
 * vertex-format state for opcode 0x29.
 *
 * Mechanically re-ported from the Ghidra decompile (Tools/port_fn.py, atomics via Tools/ghidra2cpp.py's lwarx idiom
 * rewrite) - replaces the earlier interpretive transcription, which used non-atomic stand-ins for the refcount ops and
 * left the delete_texture / set_volatile_state calls as comments. Verified with Tools/callee_compare.py.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"



/* real addr 0x27580 */
void ATIR500GLContext::discard_command_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 *piVar3;
  UInt32 uVar4;
  SInt32 *piVar5;
  UInt8 *pIVar6;
  UInt8 *pVVar7;
  SInt32 iVar8;
  SInt32 iVar9;
  UInt32 uVar10;
  SInt32 iVar11;
  UInt32 uVar12;
  UInt32 uVar13;
  SInt32 iVar14;
  UInt32 uVar15;
  UInt32 *puVar16;
  UInt8 *pAVar17;
  char in_RESERVE;
  UInt8 in_cr0;
  UInt8 bVar18;
  SInt32 local_94 [22];
  
  puVar16 = (UInt32 *)(M<SInt32>(self + 0xe0) + 0x1c);
  do {
    uVar15 = *puVar16;
    uVar4 = uVar15 & 0xff000000;
    if (uVar4 == 0x19000000) {
LAB_00027ab0:
      uVar12 = uVar15 & 0xffffff;
      uVar4 = uVar4 + 0xea000000 >> 0x16;
      pVVar7 = M<UInt8 *>(self + uVar4 + 0x2a4);
      if (pVVar7 != (UInt8 *)0x0) {
        piVar3 = (SInt32 *)(M<SInt32>(pVVar7 + 0x14) + 0x10);
        iVar8 = atomicAddReturningOld((SInt32 *)piVar3, -1);
        if (iVar8 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)pVVar7);
        }
        uVar12 = uVar15 & 0xffffff;
        M<UInt32>(self + uVar4 + 0x2a4) = 0;
      }
    }
    else {
      if (0x19000000 < uVar4) {
        if (uVar4 != 0x23000000) {
          if (uVar4 < 0x23000001) {
            if (uVar4 != 0x1e000000) {
              if (uVar4 < 0x1e000001) {
                if (uVar4 != 0x1b000000) {
                  if (uVar4 < 0x1b000001) {
                    if (uVar4 == 0x1a000000) goto LAB_00027ab0;
                  }
                  else if ((uVar4 == 0x1c000000) || (uVar4 == 0x1d000000)) goto LAB_00027ab0;
                  goto LAB_00027e70;
                }
              }
              else if (uVar4 != 0x20000000) {
                if (uVar4 < 0x20000001) {
                  if (uVar4 == 0x1f000000) goto LAB_00027ab0;
                }
                else if ((uVar4 == 0x21000000) || (uVar4 == 0x22000000)) goto LAB_00027ab0;
                goto LAB_00027e70;
              }
            }
          }
          else {
            if (uVar4 == 0x29000000) {
              iVar8 = 0;
              iVar14 = 4;
              M<UInt32>(self + 0x3bc) = 0;
              pAVar17 = self;
              do {
                switch(M<UInt32>((SInt32)puVar16 + iVar8 + 4)) {
                default:
                  M<UInt16>(pAVar17 + 0x3aa) = 1;
                  break;
                case 1:
                  M<UInt16>(pAVar17 + 0x3aa) = 0;
                  break;
                case 2:
                  M<UInt16>(pAVar17 + 0x3aa) = 4;
                  break;
                case 3:
                  M<UInt16>(pAVar17 + 0x3aa) = 5;
                  break;
                case 7:
                  M<UInt16>(pAVar17 + 0x3aa) = 2;
                  break;
                case 8:
                  M<UInt16>(pAVar17 + 0x3aa) = 3;
                  break;
                case 0x10:
                  M<UInt16>(pAVar17 + 0x3aa) = 9;
                  break;
                case 0x11:
                  M<UInt16>(pAVar17 + 0x3aa) = 0x17;
                }
                iVar14 = iVar14 + -1;
                iVar8 = iVar8 + 4;
                pAVar17 = pAVar17 + 2;
              } while (iVar14 != 0);
              M<UInt16>(self + 0xac) = M<UInt16>(self + 0x3aa);
              M<UInt32>(self + 0x35c) = (UInt32)M<UInt16>(self + 0x3aa);
              if (puVar16[5] == 0x10) {
                M<UInt16>(self + 0x3aa) = 9;
                M<UInt16>(self + 0xac) = 9;
              }
              uVar12 = uVar15 & 0xffffff;
              bVar1 = (M<UInt32>(self + 0x8c) & 0x80) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                uVar4 = puVar16[1];
                if ((uVar4 == 7) || (uVar4 == 8)) {
                  uVar12 = uVar15 & 0xffffff;
                  M<SInt16>(self + 0xae) = (SInt16)uVar4;
                }
                else {
                  M<UInt16>(self + 0xae) = 6;
                }
              }
              goto LAB_00027e90;
            }
            if (0x29000000 < uVar4) {
              if (uVar4 == 0x3a000000) {
                bVar18 = (puVar16[1] == 0) << 1;
                pAVar17 = self;
                do {
                  pVVar7 = M<UInt8 *>(pAVar17 + 0x2e4);
                  if (pVVar7 != (UInt8 *)0x0) {
                    piVar3 = (SInt32 *)(M<SInt32>(pVVar7 + 0x14) + 0x10);
                    iVar8 = atomicAddReturningOld((SInt32 *)piVar3, -1);
                    if (iVar8 == 1) {
                      ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)pVVar7);
                    }
                    M<UInt32>(pAVar17 + 0x2e4) = 0;
                  }
                } while ((!(bool)(bVar18 >> 1 & 1)) &&
                        (pAVar17 = pAVar17 + 4, pAVar17 != self + 0x44));
              }
              else if (uVar4 < 0x3a000001) {
                if (uVar4 == 0x36000000) {
                  iVar8 = M<SInt32>(self + 0x334);
                  uVar4 = puVar16[1];
                  if ((iVar8 != 0) && (M<SInt32>(iVar8 + 0x48) == 0)) {
                    M<SInt16>(iVar8 + 0xe) = M<SInt16>(iVar8 + 0xe) + -1;
                  }
                  if (M<SInt32>(uVar4 + 0x48) == 0) {
                    M<SInt16>(uVar4 + 0xe) = M<SInt16>(uVar4 + 0xe) + 1;
                  }
                  uVar12 = uVar15 & 0xffffff;
                  M<UInt32>(self + 0x334) = uVar4;
                  goto LAB_00027e90;
                }
                if (uVar4 == 0x39000000) {
                  uVar4 = puVar16[1];
                  uVar13 = puVar16[4];
                  if (puVar16[2] == 0) {
                    uVar4 = 1;
                  }
                  bVar18 = (puVar16[3] == 0) << 1;
                  if (puVar16[3] != 0) {
                    uVar4 = uVar4 + 1;
                  }
                  uVar12 = uVar15 & 0xffffff;
                  if (uVar4 == 0) goto LAB_00027e90;
                  uVar12 = 0;
                  iVar8 = 0x10;
                  iVar14 = 0;
                  piVar3 = local_94;
                  do {
                    if ((!(bool)(bVar18 >> 1 & 1)) && (uVar12 == uVar4 - 1)) {
                      iVar8 = 0x20;
                    }
                    pIVar6 = M<UInt8 *>(self + 0x88);
                    uVar10 = M<UInt32>((SInt32)puVar16 + iVar14 + 0x20);
                    if ((M<UInt32>(pIVar6 + 0x14) <= uVar10) ||
                       (iVar9 = M<SInt32>(uVar10 * 4 + M<SInt32>(pIVar6 + 0x10)), iVar9 == 0))
                    goto LAB_00027e80;
                    *piVar3 = iVar9;
                    iVar9 = iVar8 * 4;
                    pVVar7 = M<UInt8 *>(self + iVar9 + 0x2a4);
                    if (pVVar7 != (UInt8 *)0x0) {
                      piVar5 = (SInt32 *)(M<SInt32>(pVVar7 + 0x14) + 0x10);
                      iVar11 = atomicAddReturningOld((SInt32 *)piVar5, -1);
                      if (iVar11 == 1) {
                        ((IOATIR500Shared *)(pIVar6))->delete_texture((VendorTextureBuffer *)pVVar7);
                      }
                      M<UInt32>(self + iVar9 + 0x2a4) = 0;
                    }
                    if (((iVar8 == 0x20) &&
                        (iVar11 = M<SInt32>(iVar14 + (SInt32)(unsigned long)local_94), M<char>(iVar11 + 0x20) == '\a'
                        )) && (uVar13 != M<UInt32>(iVar11 + 100))) {
                      M<UInt32>(iVar11 + 100) = uVar13;
                      M<UInt8>(M<SInt32>(M<SInt32>(iVar14 + (SInt32)(unsigned long)local_94) + 0x14) + 0x14) = 1;
                    }
                    iVar11 = M<SInt32>(iVar14 + (SInt32)(unsigned long)local_94);
                    piVar5 = (SInt32 *)(M<SInt32>(iVar11 + 0x14) + 0x10);
                    atomicAddReturningOld((SInt32 *)piVar5, -0xffff);
                    uVar12 = uVar12 + 1;
                    piVar3 = piVar3 + 1;
                    iVar8 = iVar8 + 1;
                    M<SInt32>(self + iVar9 + 0x2a4) = iVar11;
                    iVar14 = iVar14 + 4;
                  } while (uVar4 != uVar12);
                }
              }
              else if (uVar4 == 0x3b000000) {
                pIVar6 = M<UInt8 *>(self + 0x88);
                uVar4 = puVar16[3];
                if ((M<UInt32>(pIVar6 + 0x14) <= puVar16[1]) ||
                   (iVar8 = M<SInt32>(puVar16[1] * 4 + M<SInt32>(pIVar6 + 0x10)), iVar8 == 0))
                goto LAB_00027e80;
                pVVar7 = M<UInt8 *>(self + 0x32c);
                if (pVVar7 != (UInt8 *)0x0) {
                  piVar3 = (SInt32 *)(M<SInt32>(pVVar7 + 0x14) + 0x10);
                  iVar14 = atomicAddReturningOld((SInt32 *)piVar3, -1);
                  if (iVar14 == 1) {
                    ((IOATIR500Shared *)(pIVar6))->delete_texture((VendorTextureBuffer *)pVVar7);
                  }
                }
                piVar3 = (SInt32 *)(M<SInt32>(iVar8 + 0x14) + 0x10);
                atomicAddReturningOld((SInt32 *)piVar3, -0xffff);
                M<SInt32>(self + 0x32c) = iVar8;
                piVar3 = (SInt32 *)0x0;
                if (M<SInt32>(iVar8 + 0x54) != 0) {
                  piVar3 = M<SInt32 *>(M<SInt32>(iVar8 + 0x54) + 8);
                  piVar3 = (SInt32 *)VCALL(*piVar3, 0x14c)(piVar3,GH_kernel_task,0,1,0,0);
                  in_cr0 = (piVar3 == (SInt32 *)0x0) << 1;
                  if (piVar3 != (SInt32 *)0x0) {
                    iVar8 = VCALL(*piVar3, 0xd0)(piVar3);
                    iVar8 = uVar4 * 0x20 + iVar8;
                    M<UInt32>(iVar8 + 0x21c) = 0;
                    M<UInt32>(iVar8 + 0x210) = 0;
                    M<UInt32>(iVar8 + 0x220) = 0;
                    M<UInt32>(iVar8 + 0x218) = 0;
                  }
                }
                VCALL(*piVar3, 0x18)(piVar3);
              }
              else if (uVar4 == 0x3d000000) {
                uVar12 = uVar15 & 0xffffff;
                if (puVar16[1] == 0x132) {
                  if (M<UInt8 *>(self + 0x290) != (UInt8 *)0x0) {
                    ((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)))->set_volatile_state((eSurfaceVolatileState)puVar16[2]);
                    goto LAB_00027e70;
                  }
                }
                goto LAB_00027e90;
              }
              goto LAB_00027e70;
            }
            if (uVar4 != 0x25000000) {
              if (0x25000000 < uVar4) {
                if (uVar4 == 0x26000000) {
                  if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar16[1]) ||
                     (iVar8 = M<SInt32>(puVar16[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                     iVar8 == 0)) goto LAB_00027e80;
                  uVar12 = uVar15 & 0xffffff;
                  M<SInt32>(self + 0x328) = iVar8;
                }
                else {
                  if (uVar4 != 0x27000000) goto LAB_00027e70;
                  uVar12 = uVar15 & 0xffffff;
                  M<UInt32>(self + 0x328) = 0;
                }
                goto LAB_00027e90;
              }
              if (uVar4 != 0x24000000) goto LAB_00027e70;
            }
          }
        }
        goto LAB_00027ab0;
      }
      if (uVar4 != 0xf000000) {
        if (uVar4 < 0xf000001) {
          if (uVar4 != 0xa000000) {
            if (uVar4 < 0xa000001) {
              if (uVar4 != 0x7000000) {
                if (uVar4 < 0x7000001) {
                  if (uVar4 != 0x6000000) {
LAB_00027e70:
                    uVar12 = uVar15 & 0xffffff;
                    goto LAB_00027e90;
                  }
                }
                else if ((uVar4 != 0x8000000) && (uVar4 != 0x9000000)) goto LAB_00027e70;
              }
            }
            else if (uVar4 != 0xc000000) {
              if (uVar4 < 0xc000001) {
                if (uVar4 != 0xb000000) goto LAB_00027e70;
              }
              else if ((uVar4 != 0xd000000) && (uVar4 != 0xe000000)) goto LAB_00027e70;
            }
          }
        }
        else if (uVar4 != 0x14000000) {
          if (0x14000000 < uVar4) {
            if (uVar4 == 0x16000000) goto LAB_00027ab0;
            if (uVar4 < 0x16000001) {
              if (uVar4 == 0x15000000) goto LAB_00027a00;
            }
            else if ((uVar4 == 0x17000000) || (uVar4 == 0x18000000)) goto LAB_00027ab0;
            goto LAB_00027e70;
          }
          if (uVar4 != 0x11000000) {
            if (uVar4 < 0x11000001) {
              if (uVar4 != 0x10000000) goto LAB_00027e70;
            }
            else if ((uVar4 != 0x12000000) && (uVar4 != 0x13000000)) goto LAB_00027e70;
          }
        }
      }
LAB_00027a00:
      pIVar6 = M<UInt8 *>(self + 0x88);
      if ((puVar16[1] < M<UInt32>(pIVar6 + 0x14)) &&
         (iVar8 = M<SInt32>(puVar16[1] * 4 + M<SInt32>(pIVar6 + 0x10)), iVar8 != 0)) {
        iVar14 = (uVar4 + 0xfa000000 >> 0x18) * 4;
        pVVar7 = M<UInt8 *>(self + iVar14 + 0x2a4);
        if (pVVar7 != (UInt8 *)0x0) {
          piVar3 = (SInt32 *)(M<SInt32>(pVVar7 + 0x14) + 0x10);
          iVar9 = atomicAddReturningOld((SInt32 *)piVar3, -1);
          if (iVar9 == 1) {
            ((IOATIR500Shared *)(pIVar6))->delete_texture((VendorTextureBuffer *)pVVar7);
          }
        }
        piVar3 = (SInt32 *)(M<SInt32>(iVar8 + 0x14) + 0x10);
        atomicAddReturningOld((SInt32 *)piVar3, -0xffff);
        uVar12 = uVar15 & 0xffffff;
        M<SInt32>(self + iVar14 + 0x2a4) = iVar8;
      }
      else {
LAB_00027e80:
        uVar12 = 0;
      }
    }
LAB_00027e90:
    puVar16 = puVar16 + uVar12;
    if (uVar12 == 0) {
      return;
    }
  } while( true );
}
