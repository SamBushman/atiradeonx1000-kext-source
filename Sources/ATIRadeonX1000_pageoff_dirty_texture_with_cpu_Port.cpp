/*
 * ATIRadeonX1000_pageoff_dirty_texture_with_cpu_Port.cpp
 *
 * ATIRadeonX1000::pageoff_dirty_texture_with_cpu (real addr 0x1e500, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 global_dummy_read_back_a_register;   /* ATIRadeonX1000_DataTables.cpp */

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x1e500 */
void ATIRadeonX1000::pageoff_dirty_texture_with_cpu(VendorTextureBuffer *real_param_1, ATITextureBufferHeader *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  UInt8 bVar1;
  UInt8 *pbVar2;
  UInt8 bVar3;
  UInt8 bVar4;
  UInt8 bVar5;
  UInt8 bVar6;
  UInt8 bVar7;
  UInt8 bVar8;
  UInt8 bVar9;
  UInt8 bVar10;
  UInt8 bVar11;
  UInt8 bVar12;
  UInt8 bVar13;
  UInt8 bVar14;
  SInt32 iVar15;
  SInt32 iVar16;
  bool bVar17;
  UInt8 bVar18;
  UInt32 uVar19;
  SInt32 iVar20;
  UInt32 uVar21;
  UInt32 uVar22;
  UInt8 *pAVar23;
  SInt32 iVar24;
  UInt8 AVar25;
  SInt32 iVar26;
  SInt32 iVar27;
  SInt32 iVar28;
  SInt32 iVar29;
  UInt32 uVar30;
  SInt32 iVar31;
  UInt32 uVar32;
  SInt32 iVar33;
  UInt32 uVar34;
  UInt32 uVar35;
  SInt32 iVar36;
  UInt32 uVar37;
  SInt32 iVar38;
  UInt8 *pAVar39;
  UInt32 uVar40;
  UInt32 local_88;
  SInt32 local_84;
  SInt32 local_7c;
  SInt32 *local_6c;
  
  iVar26 = M<SInt32>(param_1 + 0x14);
  uVar30 = (UInt32)M<UInt8>(iVar26 + 0x17);
  uVar21 = (uVar30 + M<UInt8>(iVar26 + 0x35)) - 1;
  bVar1 = M<UInt8>(iVar26 + 0x34);
  VCALL(M<SInt32>(self), 0x558)(self,M<SInt32>(self + 0x50) + -1);
  uVar19 = (UInt32)(UInt8)self[0x990];
  if ((uVar19 == 0) || ((M<UInt32>(self + 0x890) & 1) == 0)) {
LAB_0001e594:
    iVar26 = 0;
  }
  else {
    uVar35 = 0;
    do {
      uVar35 = uVar35 + 1;
      uVar19 = uVar19 - 1;
      if (uVar19 == 0) goto LAB_0001e594;
    } while ((M<UInt32>(self + 0x890) & 1 << (uVar35 & 0x3f)) != 0);
    iVar26 = uVar35 * 4;
  }
  iVar31 = M<SInt32>(self + 0x860);
  iVar15 = (iVar26 + 0x2c3) * 4;
  pbVar2 = (UInt8 *)(iVar31 + iVar15);
  bVar3 = pbVar2[3];
  bVar6 = pbVar2[2];
  bVar9 = pbVar2[1];
  bVar12 = *pbVar2;
  iVar16 = (iVar26 + 0x2c1) * 4;
  pbVar2 = (UInt8 *)(iVar31 + iVar16);
  bVar4 = pbVar2[3];
  bVar7 = pbVar2[2];
  bVar10 = pbVar2[1];
  bVar13 = *pbVar2;
  iVar26 = (iVar26 + 0x2c2) * 4;
  pbVar2 = (UInt8 *)(iVar31 + iVar26);
  bVar5 = pbVar2[3];
  bVar8 = pbVar2[2];
  bVar11 = pbVar2[1];
  bVar14 = *pbVar2;
  bVar18 = M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x15) >> 3;
  iVar20 = -(bVar18 & 3);
  if ((bVar18 & 2) == 0) {
    if (-1 < iVar20) {
      bVar17 = false;
      goto LAB_0001e61c;
    }
    AVar25 = param_2[0x1a];
    bVar17 = AVar25 == 0x0;
LAB_0001e624:
    if ((UInt8)AVar25 < 4) {
      if (bVar17) {
        iVar20 = 2;
        iVar33 = 3;
        local_7c = 2;
      }
      else {
        iVar20 = 1;
        iVar33 = 4;
        local_7c = 1;
      }
      goto LAB_0001e668;
    }
  }
  else {
    bVar17 = true;
LAB_0001e61c:
    if (iVar20 < 0) {
      AVar25 = param_2[0x1a];
      goto LAB_0001e624;
    }
  }
  iVar20 = 0;
  iVar33 = 5;
  local_7c = 0;
LAB_0001e668:
  if (bVar1 == 0) {
    local_6c = (SInt32 *)0x0;
    local_84 = 0;
  }
  else {
    local_88 = 0;
    local_6c = (SInt32 *)0x0;
    local_84 = 0;
    do {
      uVar37 = (UInt32)M<UInt16>(param_2 + 0x14);
      uVar35 = (UInt32)M<UInt16>(param_2 + 0x16);
      uVar19 = (UInt32)M<UInt16>(param_2 + 0x18);
      uVar40 = M<UInt32>(param_2 + 0xc);
      iVar31 = M<SInt32>(param_2 + 0x10);
      if (uVar30 <= uVar21) {
        pAVar39 = param_2 + (local_88 * 0xd + uVar30) * 0x20 + 0x42;
        uVar34 = uVar30;
        do {
          uVar22 = (UInt32)M<UInt16>(pAVar39);
          if ((uVar22 != 0) && (iVar38 = (SInt32)(uVar35 * uVar19) / (SInt32)uVar22, uVar22 != 0)) {
            iVar36 = 0;
            do {
              if (param_1[0x20] == 0x7) {
                local_6c = (SInt32 *)VCALL(*M<SInt32 *>(M<SInt32>(param_1 + 0x58) + 8), 0x14c)
                                            (M<SInt32 *>(M<SInt32>(param_1 + 0x58) + 8),
                                             GH_kernel_task,0,1,0,0);
                if (local_6c == (SInt32 *)0x0) {
                  return;
                }
                pAVar23 = (UInt8 *)VCALL(*local_6c, 0xd0)(local_6c);
              }
              else {
                pAVar23 = param_2 + M<SInt32>(pAVar39 + 2);
              }
              pAVar23 = pAVar23 + iVar36 * M<SInt32>(pAVar39 + 10);
              iVar24 = M<SInt32>(self + 0xe4) + M<SInt32>(param_1 + 0x48) + M<SInt32>(pAVar39 + 6) +
                       iVar36 * M<SInt32>(pAVar39 + 0xe);
              if ((((SInt32)uVar40 < 1 << iVar33 + 3) || ((SInt32)uVar35 < 1 << local_7c + 3)) ||
                 ((M<UInt8>(M<SInt32>(param_1 + 0x14) + 0x15) & 4) == 0)) {
                bVar17 = false;
                uVar22 = 0;
              }
              else {
                bVar17 = true;
                uVar22 = 1;
              }
              switch(local_7c << 1 | uVar22) {
              default:
                uVar22 = 0;
                break;
              case 1:
                uVar22 = 0x10000;
                break;
              case 2:
                uVar22 = 0x20000;
                break;
              case 3:
                uVar22 = 0x30000;
                break;
              case 4:
                uVar22 = 0x60000;
                break;
              case 5:
                uVar22 = 0x70000;
              }
              iVar28 = 8;
              if (!bVar17) {
                iVar28 = 1;
              }
              iVar28 = iVar28 * (1 << iVar20);
              uVar32 = iVar24 - M<SInt32>(self + 0xe4);
              iVar27 = M<SInt32>(self + 0x860);
              M<UInt32>(iVar27 + iVar15) =
                   (uVar40 >> 3) << 0x18 | (uVar40 >> 3 & 0x1f00) << 8 |
                   (uVar22 | ((UInt8)param_2[0x1b] & 3) << 0x14 | ((UInt8)param_2[0x1b] & 3) << 0x16)
                   >> 8;
              enforceInOrderExecutionIO();
              M<UInt32>(iVar27 + iVar16) =
                   uVar32 * 0x1000000 | (uVar32 & 0xff00) << 8 | uVar32 >> 8 & 0xff00 |
                   uVar32 >> 0x18;
              enforceInOrderExecutionIO();
              uVar22 = (uVar32 + iVar28 * uVar40 * ((iVar38 + iVar28 + -1) / iVar28)) - 1;
              M<UInt32>(iVar27 + iVar26) =
                   uVar22 * 0x1000000 | (uVar22 & 0xff00) << 8 | uVar22 >> 8 & 0xff00 |
                   uVar22 >> 0x18;
              enforceInOrderExecutionIO();
              pbVar2 = (UInt8 *)(iVar27 + iVar26);
              global_dummy_read_back_a_register =
                   (UInt32)pbVar2[3] << 0x18 | (UInt32)pbVar2[2] << 0x10 | (UInt32)pbVar2[1] << 8 |
                   (UInt32)*pbVar2;
              if (iVar38 < 1) {
                uVar22 = (UInt32)(UInt8)param_2[0x1a];
              }
              else {
                uVar22 = (UInt32)(UInt8)param_2[0x1a];
                iVar28 = 0;
                do {
                  GH_memcpy(pAVar23,iVar24,uVar37 << (uVar22 & 0x3f));
                  if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
                    AVar25 = param_2[0x1a];
                  }
                  else {
                    uVar22 = (UInt32)(UInt8)self[0x84];
                    AVar25 = param_2[0x1a];
                    iVar27 = 0;
                    iVar29 = ((uVar37 << ((UInt8)AVar25 & 0x3f)) + ((UInt32)pAVar23 & uVar22 - 1)) -
                             uVar22;
                    if (0 < iVar29) {
                      iVar27 = 0;
                      do {
                        dataCacheBlockStore((-uVar22 & (UInt32)pAVar23) + iVar27);
                        iVar27 = iVar27 + uVar22;
                      } while (iVar27 < iVar29);
                    }
                    ppcSync();
                    instructionSynchronize();
                    dataCacheBlockFlush((-uVar22 & (UInt32)pAVar23) + iVar27);
                    ppcSync();
                    instructionSynchronize();
                    instructionSynchronize();
                  }
                  uVar22 = (UInt32)(UInt8)AVar25;
                  iVar28 = iVar28 + 1;
                  pAVar23 = pAVar23 + iVar31;
                  iVar24 = iVar24 + uVar40;
                } while (iVar38 != iVar28);
              }
              iVar36 = iVar36 + 1;
              local_84 = local_84 + iVar38 * (uVar37 << (uVar22 & 0x3f));
            } while (iVar36 < (SInt32)(UInt32)M<UInt16>(pAVar39));
          }
          if (((1 >= uVar37) && (uVar35 < 2)) && (uVar19 < 2)) break;
          if (0x20 < iVar31) {
            iVar31 = iVar31 >> 1;
          }
          if (1 << iVar33 < (SInt32)uVar40) {
            uVar40 = (SInt32)uVar40 >> 1;
          }
          if (1 < uVar37) {
            uVar37 = (SInt32)uVar37 >> 1;
          }
          if (1 < uVar35) {
            uVar35 = (SInt32)uVar35 >> 1;
          }
          if (1 < uVar19) {
            uVar19 = (SInt32)uVar19 >> 1;
          }
          uVar34 = uVar34 + 1;
          pAVar39 = pAVar39 + 0x20;
        } while (uVar34 <= uVar21);
      }
      local_88 = local_88 + 1;
    } while (local_88 < bVar1);
    iVar31 = M<SInt32>(self + 0x860);
  }
  M<SInt32>(self + 0x720) = local_84 + M<SInt32>(self + 0x720);
  M<UInt32>(iVar31 + iVar15) =
       (UInt32)bVar12 << 0x18 | (UInt32)bVar9 << 0x10 | (UInt32)bVar6 << 8 | (UInt32)bVar3;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar31 + iVar16) =
       (UInt32)bVar13 << 0x18 | (UInt32)bVar10 << 0x10 | (UInt32)bVar7 << 8 | (UInt32)bVar4;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar31 + iVar26) =
       (UInt32)bVar14 << 0x18 | (UInt32)bVar11 << 0x10 | (UInt32)bVar8 << 8 | (UInt32)bVar5;
  enforceInOrderExecutionIO();
  if (local_6c != (SInt32 *)0x0) {
    VCALL(*local_6c, 0x18)(local_6c);
  }
  return;
}
