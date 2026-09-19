/*
 * ATIRadeonX1000_SWDS.cpp
 *
 * RESOLVED (ledger pass): the software display scaler: SWDSShutdown, SWDSFunc (timer), SWDSInit.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); real addresses in the markers.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 gl_assert_wait_timeout_event;
extern "C" UInt32 global_dummy_read_back_a_register;
extern "C" UInt32 GH_IODelay(...) asm("_IODelay");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOLog(...) asm("_IOLog");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x1d350 */
bool ATIRadeonX1000::SWDSShutdown() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  SInt32 iVar7;
  UInt8 *pGVar8;
  UInt8 *pAVar9;
  UInt8 *pAVar10;
  
  if (M<SInt32 *>(self + 0x9b8) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0x9b8), 0xf0)(M<SInt32 *>(self + 0x9b8));
  }
  if (self[0x9b0] != 0x0) {
    iVar7 = 0;
    self[0x9b0] = 0x0;
    pGVar8 = (self + 0x9bc);
    pAVar9 = self;
    pAVar10 = self;
    do {
      if (M<SInt32>(pAVar10 + 0xb10) != 0) {
        M<UInt32>(pAVar10 + 0xb10) = 0;
        if (iVar7 == 1) {
          iVar6 = 0xb64;
          iVar5 = 0xb68;
          iVar3 = 0xb6c;
        }
        else {
          iVar6 = 0xb74;
          iVar5 = 0xb78;
          iVar3 = 0xb7c;
        }
        iVar4 = M<SInt32>(self + 0x860);
        uVar2 = M<UInt32>(pAVar10 + 0xafc);
        M<UInt32>(iVar4 + iVar6) =
             uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
        enforceInOrderExecutionIO();
        uVar2 = M<UInt32>(pAVar10 + 0xb00);
        M<UInt32>(iVar4 + iVar5) =
             uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
        enforceInOrderExecutionIO();
        uVar2 = M<UInt32>(pAVar10 + 0xb04);
        M<UInt32>(iVar4 + iVar3) =
             uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
        enforceInOrderExecutionIO();
        if ((M<SInt32>(pAVar9 + 0x9c0) != 0) && (M<SInt32>(pAVar9 + 0x9bc) != 0)) {
          ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)pGVar8);
        }
      }
      bVar1 = iVar7 != 1;
      pGVar8 = pGVar8 + 0x78;
      pAVar10 = pAVar10 + 0x18;
      pAVar9 = pAVar9 + 0x78;
      iVar7 = iVar7 + 1;
    } while (bVar1);
  }
  return 1;
}

/* real addr 0x24340 */
void ATIRadeonX1000::SWDSFunc(OSObject *real_param_1, IOTimerEventSource *param_2) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 bVar1;
  bool bVar2;
  UInt8 bVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  UInt8 *pOVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  SInt32 iVar11;
  UInt32 *puVar12;
  UInt32 uVar13;
  UInt8 bVar14;
  UInt8 bVar15;
  
  GH_IOLockLock(M<UInt32>(param_1 + 0x840));
  if ((param_1[0x80] != 0x0) && (param_1[0x9b0] != 0x0)) {
    bVar1 = M<UInt8>(M<SInt32>(param_1 + 0x860) + 0xbf8);
    if ((M<SInt32>(param_1 + 0xb10) == 0) || (bVar2 = true, M<SInt32>(param_1 + 0xb28) == 0)) {
      bVar2 = false;
    }
    iVar11 = 0;
    pOVar8 = (UInt8 *)0x0;
    uVar9 = 0;
    puVar12 = (UInt32 *)0x0;
    bVar14 = 2;
    uVar7 = 0;
    uVar10 = 0;
    uVar13 = 0;
    do {
      if (M<SInt32>(param_1 + uVar13 * 0x18 + 0xb10) != 0) {
        bVar15 = (uVar13 == 0) << 1;
        if (uVar13 == 0) {
          bVar3 = 0x80;
        }
        else {
          bVar3 = 0x40;
        }
        if ((bVar1 & bVar3) == 0) {
          if (M<SInt32>(param_1 + uVar13 * 4 + 0xacc) - M<SInt32>(param_1 + uVar13 * 4 + 0xad4) < 1) {
            if (M<SInt32>(param_1 + 0x894) == 1) {
              iVar5 = M<SInt32>(param_1 + 0xec);
              if (iVar5 - M<SInt32>(param_1 + 0x10c) < 1) {
                M<SInt32>(param_1 + uVar13 * 4 + 0xacc) = M<SInt32>(param_1 + 0x10c);
                goto LAB_00024480;
              }
            }
            else {
              iVar5 = M<SInt32>(param_1 + uVar13 * 0x20 + 0xec);
            }
            M<SInt32>(param_1 + uVar13 * 4 + 0xacc) = iVar5;
          }
          else {
            uVar4 = VCALL(M<SInt32>(param_1), 0x554)(param_1);
            uVar9 = uVar9 | uVar4;
          }
LAB_00024480:
          if (uVar9 == 0) goto LAB_00024584;
        }
        else {
          uVar9 = 1;
        }
        if ((bool)(bVar14 >> 1 & 1)) {
          pOVar8 = param_1 + M<SInt32>(param_1 + 0xadc) * 0x1c + 0xae0;
          iVar5 = VCALL(M<SInt32>(param_1), 0x554)(param_1,M<UInt32>(pOVar8 + 0x10));
          if (iVar5 != 0) {
            puVar12 = (UInt32 *)(M<SInt32>(pOVar8 + 0x14) + 0x20);
            uVar7 = M<SInt32>(pOVar8 + 4) + 0x20;
            iVar11 = ((ATIRadeonX1000 *)param_1)->SWDSWriteBlitToCmdBuf(puVar12,0,false,uVar13);
            if ((bool)(bVar15 >> 1 & 1)) {
              puVar12[iVar11] = 0x2ff;
              puVar12[iVar11 + 1] = 0x80;
            }
            else {
              puVar12[iVar11] = 0x2ff;
              puVar12[iVar11 + 1] = 0x40;
            }
            uVar10 = iVar11 + 2;
            iVar11 = uVar13 + 1;
            bVar14 = (iVar11 == 0) << 1;
          }
        }
        else {
          iVar5 = ((ATIRadeonX1000 *)param_1)->SWDSWriteBlitToCmdBuf(puVar12,uVar10,false,uVar13);
          puVar12[iVar5] = 0x2ff;
          uVar10 = iVar5 + 2;
          puVar12[iVar5 + 1] = 0x40;
        }
      }
LAB_00024584:
      uVar13 = uVar13 + 1;
    } while (uVar13 < 2);
    if (!(bool)(bVar14 >> 1 & 1)) {
      if (bVar2) {
        uVar6 = ((ATIRadeonX1000 *)param_1)->submit_buffer(puVar12,uVar7,uVar10);
        M<UInt32>(pOVar8 + 0x10) = uVar6;
        M<UInt32>(param_1 + 0xad4) = uVar6;
        M<UInt32>(param_1 + 0xad8) = uVar6;
      }
      else {
        uVar6 = ((ATIRadeonX1000 *)param_1)->submit_buffer(puVar12,uVar7,uVar10);
        M<UInt32>(pOVar8 + 0x10) = uVar6;
        M<UInt32>(param_1 + iVar11 * 4 + 0xad0) = uVar6;
      }
    }
    VCALL(*M<SInt32 *>(param_1 + 0x9b8), 300)
              (M<SInt32 *>(param_1 + 0x9b8),M<UInt32>(param_1 + 0x9b4));
  }
  GH_IOLockUnlock(M<UInt32>(param_1 + 0x840));
  return;
}

/* real addr 0x24670 */
bool ATIRadeonX1000::SWDSInit() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 AVar2;
  UInt16 uVar3;
  UInt8 *pbVar4;
  bool bVar5;
  bool bVar6;
  UInt32 uVar7;
  SInt32 iVar8;
  SInt32 iVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  UInt32 uVar12;
  SInt32 iVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 uVar17;
  UInt32 uVar18;
  SInt32 iVar19;
  UInt8 *pGVar20;
  UInt8 *pAVar21;
  UInt32 uVar22;
  UInt8 *pGVar23;
  UInt8 *pAVar24;
  UInt32 uVar25;
  SInt32 iVar26;
  UInt32 *puVar27;
  UInt8 *pAVar28;
  
  if (self[0x80] != 0x0) {
    uVar7 = M<UInt32>(self + 0x84c);
    bVar6 = false;
    bVar5 = false;
    uVar18 = 0;
    uVar22 = 1;
    pGVar20 = (self + 0xabc);
    pGVar23 = (self + 0xa34);
    iVar19 = 0x78;
    pAVar21 = self;
    pAVar24 = self;
    pAVar28 = self;
    do {
      if (M<SInt32>(pAVar24 + 0xb30) != 0) {
        uVar12 = M<UInt32>(pAVar24 + 0xb38);
        uVar14 = M<UInt32>(pAVar24 + 0xb40);
        if (((uVar12 != M<UInt16>(pAVar28 + 0x1c0)) || (uVar14 != M<UInt16>(pAVar28 + 0x1c2)))
           || (M<SInt32>(pAVar24 + 0xb60) != 0)) {
          uVar3 = M<UInt16>(pAVar28 + 0x1ba);
          uVar16 = (UInt32)uVar3;
          uVar11 = uVar12 * uVar16 + 0xff & 0xffffff00;
          if (uVar16 != 0) {
            uVar18 = uVar11 / uVar16;
          }
          uVar16 = uVar14;
          if ((uVar14 & 0xf) != 0) {
            uVar16 = (uVar14 & 0xfffffff0) + 0x10;
          }
          uVar17 = M<UInt32>(self + 0x84c);
          uVar15 = M<UInt32>(self + 0x9c);
          uVar25 = uVar16 * uVar11;
          if (uVar17 < uVar15) {
            if ((uVar22 == 1) ||
               ((((M<SInt32>(self + 0x894) == 1 && (M<SInt32>(self + 0xb2c) != 0)) &&
                 (M<SInt32>(self + 0xb30) != 0)) &&
                ((M<SInt32>(self + 0xb34) == M<SInt32>(self + 0xb38) ||
                 (M<SInt32>(self + 0xb3c) == M<SInt32>(self + 0xb40))))))) {
              iVar8 = uVar15 - uVar25;
              bVar6 = uVar22 == 1;
            }
            else {
              if (bVar6) {
                uVar15 = M<UInt32>(self + 0xa3c);
              }
              iVar8 = uVar15 - uVar25;
            }
            uVar16 = iVar8 - 0x8000U & 0xffff8000;
            if (uVar17 <= uVar16) {
LAB_00024750:
              M<UInt16>(pAVar28 + 0xa48) = 0;
              M<UInt16>(pAVar28 + 0xa4a) = 0;
              M<UInt16>(pAVar28 + 0xa4c) = 0;
              M<UInt16>(pAVar28 + 0xa50) = 0;
              pAVar28[0xa6f] = 0x6;
              M<UInt16>(pAVar28 + 0xa56) = 1;
              M<UInt16>(pAVar28 + 0xa54) = 1;
              M<UInt16>(pAVar28 + 0xa52) = 0;
              pAVar28[0xa68] = 0x0;
              pAVar28[0xa69] = 0x0;
              pAVar28[0xa6a] = 0x0;
              pAVar28[0xa6c] = 0x0;
              pAVar28[0xa6d] = 0x0;
              pAVar28[0xa70] = 0x0;
              M<UInt32>(pAVar28 + 0xa3c) = 0;
              M<UInt32>(pAVar28 + 0xa44) = 0;
              M<UInt32>(pAVar28 + 0xa34) = 0;
              M<UInt32>(pAVar28 + 0xa38) = 0;
              M<UInt32>(pAVar28 + 0xa40) = 0;
              M<UInt32>(pAVar28 + 0xa58) = 0;
              M<UInt32>(pAVar28 + 0xa60) = 0;
              M<UInt32>(pAVar28 + 0xa64) = 0;
              pAVar28[0xa6b] = 0xff;
              M<UInt32>(pAVar28 + 0xa5c) = 0xffffffff;
              M<UInt32>(pGVar23 + 0x3c) = M<UInt32>(pGVar23 + 0x3c) & 0xff0007ff | 0x111000;
              M<UInt16>(pAVar28 + 0xa4a) = uVar3;
              M<SInt16>(pAVar28 + 0xa4c) = (SInt16)uVar11;
              M<UInt32>(pAVar28 + 0xa74) = 0;
              M<UInt32>(pAVar28 + 0xa78) = 0;
              M<UInt32>(pAVar28 + 0xa3c) = uVar16;
              M<UInt32>(pAVar28 + 0xa44) = uVar25;
              M<SInt16>(pAVar28 + 0xa48) = (SInt16)uVar18;
              M<SInt16>(pAVar28 + 0xa50) = (SInt16)uVar12;
              M<SInt16>(pAVar28 + 0xa52) = (SInt16)uVar14;
              pAVar28[0xa6b] = pAVar28[0x1db];
              pAVar28[0xa6c] = pAVar28[0x1dc];
              pAVar28[0xa6d] = pAVar28[0x1dd];
              pAVar28[0xa6e] = pAVar28[0x1de];
              pAVar28[0xa6f] = pAVar28[0x1df];
              uVar12 = M<UInt32>(pGVar23 + -0x854);
              M<UInt32>(pGVar23 + 0x3c) =
                   uVar12 & 0x800 |
                   uVar12 & 0xf000 |
                   uVar12 & 0xf0000 | uVar12 & 0xf00000 | M<UInt32>(pGVar23 + 0x3c) & 0xff0007ff;
              iVar8 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->reserve((GLKMemoryElement *)pGVar23, uVar16, uVar25)
              ;
              if (iVar8 != 0) {
                iVar8 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x93c)))->reserve((GLKMemoryElement *)pGVar20,uVar16,uVar25);
                if (iVar8 == 0) {
                  ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)pGVar23);
                }
                else {
                  iVar8 = M<SInt32>(self + 0xadc) * 0x1c;
                  iVar9 = VCALL(M<SInt32>(self), 0x554)
                                    (self,M<UInt32>(self + iVar8 + 0xaf0));
                  if (iVar9 != 0) {
                    iVar9 = M<SInt32>(self + iVar8 + 0xaf4);
                    iVar26 = M<SInt32>(self + iVar8 + 0xae4);
                    puVar27 = (UInt32 *)(iVar9 + 0x20);
                    *puVar27 = 0xd0b;
                    M<UInt32>(iVar9 + 0x24) = 5;
                    M<UInt32>(iVar9 + 0x28) = 0x1393;
                    M<UInt32>(iVar9 + 0x2c) = 10;
                    M<UInt32>(iVar9 + 0x30) = 0x5c8;
                    M<UInt32>(iVar9 + 0x34) = 0x30000;
                    iVar9 = this->SWDSWriteBlitToCmdBuf(puVar27,6,false,uVar22);
                    puVar27[iVar9] = 0x2ff;
                    puVar27[iVar9 + 1] = 0xc0;
                    puVar27[iVar9 + 2] = 0x5c8;
                    puVar27[iVar9 + 3] = 0x30000;
                    uVar10 = this->submit_buffer(puVar27,iVar26 + 0x20,iVar9 + 4);
                    M<UInt32>(self + iVar8 + 0xaf0) = uVar10;
                    M<UInt32>(pAVar24 + 0xad8) = uVar10;
                    VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(self + iVar8 + 0xaf0));
                  }
                  if (((M<SInt32>(self + 0x894) == 1) && (M<SInt32>(self + 0xb2c) != 0)) &&
                     ((M<SInt32>(self + 0xb30) != 0 &&
                      ((M<SInt32>(self + 0xb34) == M<SInt32>(self + 0xb38) &&
                       (M<SInt32>(self + 0xb3c) == M<SInt32>(self + 0xb40))))))) {
                    iVar8 = M<SInt32>(self + 0x860);
                    uVar14 = M<UInt32>(pAVar28 + 0xa3c);
                    M<UInt32>(iVar8 + 0x6110) =
                         uVar14 << 0x18 | (uVar14 & 0xff00) << 8 | uVar14 >> 8 & 0xff00 |
                         uVar14 >> 0x18;
                    enforceInOrderExecutionIO();
                    uVar12 = (UInt32)M<UInt16>(pAVar28 + 0xa48);
                    M<UInt32>(iVar8 + 0x6120) = uVar12 << 0x18 | (uVar12 & 0xff00) << 8;
                    enforceInOrderExecutionIO();
                    M<UInt32>(iVar8 + 0x6910) =
                         uVar14 << 0x18 | (uVar14 & 0xff00) << 8 | uVar14 >> 8 & 0xff00 |
                         uVar14 >> 0x18;
                    enforceInOrderExecutionIO();
                    M<UInt32>(iVar8 + 0x6920) = uVar12 << 0x18 | (uVar12 & 0xff00) << 8;
                    enforceInOrderExecutionIO();
                    M<UInt32>(self + 0xb6c) = uVar14;
                    M<UInt32>(self + 0xb70) = M<UInt32>(pAVar28 + 0xa3c);
                  }
                  else {
                    if (uVar22 == 0) {
                      iVar8 = M<SInt32>(self + 0x860);
                      uVar12 = M<UInt32>(self + 0x9c4);
                      M<UInt32>(iVar8 + 0x6110) =
                           uVar12 << 0x18 | (uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00 |
                           uVar12 >> 0x18;
                      enforceInOrderExecutionIO();
                      M<UInt32>(iVar8 + 0x6120) =
                           (UInt32)M<UInt16>(self + 0x9d0) << 0x18 |
                           (M<UInt16>(self + 0x9d0) & 0xff00) << 8;
                      enforceInOrderExecutionIO();
                      uVar12 = M<UInt32>(pAVar28 + 0xa3c);
                    }
                    else {
                      uVar12 = M<UInt32>(pAVar28 + 0xa3c);
                      iVar8 = M<SInt32>(self + 0x860);
                      M<UInt32>(iVar8 + 0x6910) =
                           uVar12 << 0x18 | (uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00 |
                           uVar12 >> 0x18;
                      enforceInOrderExecutionIO();
                      M<UInt32>(iVar8 + 0x6920) =
                           (UInt32)M<UInt16>(pAVar28 + 0xa48) << 0x18 |
                           (M<UInt16>(pAVar28 + 0xa48) & 0xff00) << 8;
                      enforceInOrderExecutionIO();
                    }
                    M<UInt32>(pAVar24 + 0xb70) = uVar12;
                  }
                  uVar12 = 0;
                  AVar2 = self[iVar19 + 0x164];
                  uVar11 = M<UInt32>(self + iVar19 + 0x134);
                  uVar14 = 0;
                  if (AVar2 != 0x0) {
                    uVar12 = (UInt32)(M<UInt16>(self + iVar19 + 0x144) >> 3);
                    if (AVar2 == 0x2) {
                      uVar14 = 0x20000;
                    }
                    else if (AVar2 == 0x3) {
                      uVar14 = 0x30000;
                    }
                    else if (AVar2 == 0x1) {
                      uVar14 = 0x10000;
                    }
                    else {
                      uVar14 = 0;
                    }
                  }
                  if (uVar22 == 1) {
                    iVar26 = 0xb64;
                    iVar9 = 0xb68;
                    iVar13 = 0xb6c;
                    uVar12 = uVar12 | uVar14 | ((UInt8)self[iVar19 + 0x165] & 3) << 0x14 |
                             ((UInt8)self[iVar19 + 0x165] & 3) << 0x16;
                  }
                  else {
                    iVar26 = 0xb74;
                    iVar9 = 0xb78;
                    iVar13 = 0xb7c;
                    uVar12 = uVar12 | uVar14 | ((UInt8)self[iVar19 + 0x165] & 3) << 0x14 |
                             ((UInt8)self[iVar19 + 0x165] & 3) << 0x16;
                  }
                  pbVar4 = (UInt8 *)(iVar8 + iVar26);
                  M<UInt32>(pAVar21 + 0xb14) =
                       (UInt32)pbVar4[3] << 0x18 | (UInt32)pbVar4[2] << 0x10 | (UInt32)pbVar4[1] << 8 |
                       (UInt32)*pbVar4;
                  pbVar4 = (UInt8 *)(M<SInt32>(self + 0x860) + iVar9);
                  M<UInt32>(pAVar21 + 0xb18) =
                       (UInt32)pbVar4[3] << 0x18 | (UInt32)pbVar4[2] << 0x10 | (UInt32)pbVar4[1] << 8 |
                       (UInt32)*pbVar4;
                  pbVar4 = (UInt8 *)(M<SInt32>(self + 0x860) + iVar13);
                  M<UInt32>(pAVar21 + 0xb1c) =
                       (UInt32)pbVar4[3] << 0x18 | (UInt32)pbVar4[2] << 0x10 | (UInt32)pbVar4[1] << 8 |
                       (UInt32)*pbVar4;
                  iVar8 = M<SInt32>(self + 0x860);
                  M<UInt32>(iVar8 + iVar26) =
                       uVar11 << 0x18 | (uVar11 & 0xff00) << 8 | uVar11 >> 8 & 0xff00 |
                       uVar11 >> 0x18;
                  enforceInOrderExecutionIO();
                  uVar14 = (uVar11 + M<SInt32>(self + iVar19 + 0x13c)) - 1;
                  M<UInt32>(iVar8 + iVar9) =
                       uVar14 * 0x1000000 | (uVar14 & 0xff00) << 8 | uVar14 >> 8 & 0xff00 |
                       uVar14 >> 0x18;
                  enforceInOrderExecutionIO();
                  M<UInt32>(iVar8 + iVar13) =
                       uVar12 << 0x18 | (uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00;
                  enforceInOrderExecutionIO();
                  bVar5 = true;
                  M<UInt32>(pAVar21 + 0xb28) = 1;
                }
              }
            }
          }
          else if (((M<SInt32>(self + 0x894) == 1) && (M<SInt32>(self + 0xb2c) != 0)) &&
                  ((M<SInt32>(self + 0xb30) != 0 &&
                   ((M<SInt32>(self + 0xb34) != M<SInt32>(self + 0xb38) ||
                    (M<SInt32>(self + 0xb3c) != M<SInt32>(self + 0xb40))))))) {
            if (uVar22 == 1) {
              iVar9 = M<SInt32>(self + 0xbac);
              iVar8 = M<SInt32>(self + 0x1ac);
              iVar26 = M<SInt32>(self + 0x1b4);
LAB_00024a0c:
              uVar16 = ((uVar17 - iVar9) - uVar25) - 0x8000 & 0xffff8000;
              if ((UInt32)(iVar8 + iVar26) < uVar16) goto LAB_00024750;
            }
            else {
              uVar16 = (M<SInt32>(self + 0xa3c) - uVar25) - 0x8000 & 0xffff8000;
              if ((UInt32)(M<SInt32>(pAVar28 + 0x1ac) + M<SInt32>(pAVar28 + 0x1b4)) < uVar16)
              goto LAB_00024750;
            }
          }
          else {
            if ((uVar22 != 0) || ((M<SInt32>(self + 0x1b4) == 0 || (M<SInt32>(self + 0x894) != 0)))) {
              iVar9 = M<SInt32>(self + 0xbac);
              iVar8 = M<SInt32>(pAVar28 + 0x1ac);
              iVar26 = M<SInt32>(pAVar28 + 0x1b4);
              goto LAB_00024a0c;
            }
            uVar16 = M<SInt32>(self + 0x134) + M<SInt32>(self + 0x13c) + 0x8000U & 0xffff8000;
            if (uVar25 + uVar16 < (M<UInt32>(self + 0x1ac) & ~((uVar7 >> 1) - 1)))
            goto LAB_00024750;
          }
        }
      }
      bVar1 = uVar22 != 0;
      iVar19 = iVar19 + -0x78;
      pGVar23 = pGVar23 + -0x78;
      pGVar20 = pGVar20 + -0x10;
      pAVar24 = pAVar24 + -4;
      pAVar21 = pAVar21 + -0x18;
      pAVar28 = pAVar28 + -0x78;
      uVar22 = uVar22 - 1;
    } while (bVar1);
    if (bVar5) {
      VCALL(*M<SInt32 *>(self + 0x9b8), 300)
                (M<SInt32 *>(self + 0x9b8),M<UInt32>(self + 0x9b4));
      VCALL(*M<SInt32 *>(self + 0x9b8), 0xec)(M<SInt32 *>(self + 0x9b8));
      self[0x9b0] = 0x1;
      return 1;
    }
  }
  return 0;
}

