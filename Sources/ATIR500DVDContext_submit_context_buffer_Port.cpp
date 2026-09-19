/*
 * ATIR500DVDContext_submit_context_buffer_Port.cpp
 *
 * ATIR500DVDContext::submit_context_buffer (real addr 0x34440, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x34440 */
void ATIR500DVDContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 *puVar2;
  SInt32 iVar3;
  UInt8 *pVVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  UInt32 *puVar9;
  SInt32 iVar10;
  UInt32 uVar11;
  SInt32 iVar12;
  UInt32 uVar13;
  SInt32 iVar14;
  SInt32 iVar15;
  SInt32 iVar16;
  SInt32 iVar17;
  UInt8 *pAVar18;
  SInt32 *piVar19;
  SInt32 iVar20;
  UInt8 *pAVar21;
  SInt32 iVar22;
  SInt32 iVar23;
  
  pAVar21 = self;
  do {
    pVVar4 = M<UInt8 *>(pAVar21 + 0x104);
    pAVar18 = pAVar21 + 0x104;
    if (pVVar4 != (UInt8 *)0x0) {
      if (M<char>(M<SInt32>(pVVar4 + 0x14) + 0x14) != '\0') {
        if (M<SInt32>(pVVar4 + 4) == 0) {
          ((IOATIR500DVDContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar4));
          pVVar4 = M<UInt8 *>(pAVar21 + 0x104);
          if (M<SInt32>(pVVar4 + 4) != 0) goto LAB_000344b0;
        }
        else {
LAB_000344b0:
          GH_IOGetTime(pVVar4 + 0x2c);
          M<UInt32>(M<SInt32>(M<SInt32>(pAVar21 + 0x104) + 0x34) + 0x38) =
               M<UInt32>(M<SInt32>(pAVar21 + 0x104) + 0x38);
          M<UInt32>(M<SInt32>(M<SInt32>(pAVar21 + 0x104) + 0x38) + 0x34) =
               M<UInt32>(M<SInt32>(pAVar21 + 0x104) + 0x34);
          M<UInt32>(M<SInt32>(pAVar21 + 0x104) + 0x34) =
               M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0);
          M<SInt32>(M<SInt32>(pAVar21 + 0x104) + 0x38) = M<SInt32>(self + 0x8c) + 0x69c;
          M<UInt32>(M<SInt32>(self + 0x8c) + 0x6d0) = M<UInt32>(pAVar21 + 0x104);
          M<SInt32>(M<SInt32>(M<SInt32>(pAVar21 + 0x104) + 0x34) + 0x38) = M<SInt32>(pAVar21 + 0x104);
        }
        M<UInt8>(M<SInt32>(M<SInt32>(pAVar18) + 0x14) + 0x14) = 0;
        M<UInt32>(M<SInt32>(self + 0xc0) + 0x1c) = M<UInt32>(M<SInt32>(self + 0xc0) + 0x1c) | 1;
      }
      iVar1 = M<SInt32>(pAVar18);
      if (M<SInt32>(iVar1 + 0x48) != 0) {
        M<UInt32>(M<SInt32>(iVar1 + 0x24) + 0x28) = M<UInt32>(iVar1 + 0x28);
        M<UInt32>(M<SInt32>(M<SInt32>(pAVar18) + 0x28) + 0x24) =
             M<UInt32>(M<SInt32>(pAVar18) + 0x24);
        M<UInt32>(M<SInt32>(pAVar18) + 0x24) = M<UInt32>(M<SInt32>(self + 0x8c) + 0x600);
        M<SInt32>(M<SInt32>(pAVar18) + 0x28) = M<SInt32>(self + 0x8c) + 0x5dc;
        M<SInt32>(M<SInt32>(self + 0x8c) + 0x600) = M<SInt32>(pAVar18);
        M<SInt32>(M<SInt32>(M<SInt32>(pAVar18) + 0x24) + 0x28) = M<SInt32>(pAVar18);
      }
    }
    pAVar21 = pAVar21 + 4;
    if (pAVar21 == self + 0x48) {
      if ((M<UInt32>(M<SInt32>(self + 0xc0) + 0x1c) & 1) == 0) {
        pAVar21 = self + M<SInt32>(self + 0xf4) * 0x18;
      }
      else {
        piVar19 = M<SInt32 *>(self + 0x8c);
        uVar7 = M<SInt32>(self + 0xf4) + 1U & 1;
        M<UInt32>(self + 0xf4) = uVar7;
        pAVar21 = self + uVar7 * 0x18;
        iVar22 = piVar19[0x1e1];
        iVar1 = VCALL(*piVar19, 0x54c)(piVar19,M<UInt32>(pAVar21 + 0xd4));
        piVar19[0x1e1] = iVar22 + iVar1;
        puVar2 = M<UInt32 *>(self + 0xc0);
        puVar9 = M<UInt32 *>(pAVar21 + 0xd8);
        uVar13 = puVar2[1];
        uVar11 = puVar2[2];
        uVar8 = puVar2[3];
        *puVar9 = *puVar2;
        puVar9[1] = uVar13;
        puVar9[2] = uVar11;
        puVar9[3] = uVar8;
        uVar8 = puVar2[7];
        uVar13 = puVar2[4];
        uVar11 = puVar2[6];
        puVar9[5] = puVar2[5];
        puVar9[7] = uVar8;
        puVar9[4] = uVar13;
        puVar9[6] = uVar11;
        iVar1 = M<SInt32>(self + 0xc0);
        iVar22 = M<SInt32>(pAVar21 + 0xd8);
        iVar10 = M<SInt32>(iVar1 + 0x14);
        iVar12 = iVar22 + 0x20;
        if (iVar10 == 0) {
          iVar10 = 0;
          iVar1 = 0;
          iVar5 = 1;
          iVar14 = 2;
          iVar6 = 3;
          iVar17 = 4;
          iVar15 = 5;
          iVar20 = 6;
          iVar23 = 7;
          iVar3 = 8;
          iVar16 = 9;
          uVar7 = 10;
        }
        else {
          iVar3 = 0;
          iVar22 = iVar10;
          do {
            M<UInt32>(iVar12 + iVar3) = M<UInt32>(iVar1 + 0x20 + iVar3);
            iVar3 = iVar3 + 4;
            iVar22 = iVar22 + -1;
          } while (iVar22 != 0);
          iVar22 = M<SInt32>(pAVar21 + 0xd8);
          iVar1 = iVar10 << 2;
          iVar5 = iVar10 + 1;
          iVar14 = iVar10 + 2;
          iVar6 = iVar10 + 3;
          iVar17 = iVar10 + 4;
          iVar15 = iVar10 + 5;
          iVar20 = iVar10 + 6;
          iVar23 = iVar10 + 7;
          iVar3 = iVar10 + 8;
          iVar16 = iVar10 + 9;
          uVar7 = iVar10 + 10;
        }
        M<UInt32>(iVar12 + iVar1) = 0x1393;
        M<UInt32>(iVar12 + iVar5 * 4) = 10;
        M<UInt32>(iVar12 + iVar14 * 4) = 0xd0b;
        M<UInt32>(iVar12 + iVar6 * 4) = 5;
        M<UInt32>(iVar12 + iVar17 * 4) = 0x13c6;
        M<UInt32>(iVar12 + iVar15 * 4) = 3;
        M<UInt32>(iVar12 + iVar20 * 4) = 0x5c8;
        M<UInt32>(iVar12 + iVar23 * 4) = 0x70000;
        M<UInt32>(iVar12 + iVar3 * 4) = 0x1006;
        M<UInt32>(iVar12 + iVar16 * 4) =
             M<UInt32>(M<SInt32>(self + 0x8c) + 0xb74) & 0xfffeffff | 0x10000;
        iVar1 = 0x12;
        do {
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        if ((uVar7 & 7) != 0) {
          iVar1 = uVar7 * 4;
          uVar7 = iVar10 + 0xb;
          M<UInt32>(iVar12 + iVar1) = 0x80000000;
        }
        M<UInt32>(iVar22 + 0x14) = uVar7;
        M<UInt32>(M<SInt32>(self + 0xc0) + 0x1c) =
             M<UInt32>(M<SInt32>(self + 0xc0) + 0x1c) & 0xfffffffe;
      }
      if (M<SInt32>(pAVar21 + 200) == 0) {
        ((IOATIR500DVDContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(pAVar21 + 0xc4)));
      }
      M<SInt32>(M<SInt32>(self + 0x8c) + 0x708) =
           M<SInt32>(M<SInt32>(pAVar21 + 0xd8) + 0x14) * 4 + M<SInt32>(M<SInt32>(self + 0x8c) + 0x708);
      uVar8 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x8c)))->submit_buffer((UInt32 *)(M<SInt32>(pAVar21 + 0xd8) + 0x20),M<SInt32>(pAVar21 + 200) + 0x20,
                         M<UInt32>(M<SInt32>(pAVar21 + 0xd8) + 0x14));
      M<UInt32>(pAVar21 + 0xd4) = uVar8;
      M<UInt32>(self + 0x7c) = uVar8;
      return;
    }
  } while( true );
}
