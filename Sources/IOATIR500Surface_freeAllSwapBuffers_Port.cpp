/*
 * IOATIR500Surface_freeAllSwapBuffers_Port.cpp
 *
 * IOATIR500Surface::freeAllSwapBuffers (real addr 0x10860, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10860 */
void IOATIR500Surface::freeAllSwapBuffers(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  UInt8 *pIVar3;
  SInt32 iVar4;
  UInt8 *pIVar5;
  UInt8 *pIVar6;
  UInt8 *pIVar7;
  UInt8 *pIVar8;
  SInt32 iVar9;
  UInt8 *pIVar10;
  UInt32 uVar11;
  UInt8 *pIVar12;
  SInt32 *piVar13;
  
  piVar13 = M<SInt32 *>(self + 0xd50);
  if (piVar13[param_1 + 0x45] != 0) {
    iVar4 = param_1 * 0x94;
    uVar11 = 0;
    do {
      iVar9 = piVar13[0x1e2];
      iVar2 = M<UInt16>(self + iVar4 + 0xcae) + uVar11;
      uVar11 = uVar11 + 1;
      iVar2 = VCALL(*piVar13, 0x54c)
                        (piVar13,M<UInt32>(self + iVar2 * 0x1c + iVar4 + 0xc4c));
      piVar13[0x1e2] = iVar9 + iVar2;
      piVar13 = M<SInt32 *>(self + 0xd50);
    } while (uVar11 < (UInt32)piVar13[param_1 + 0x45]);
    if (piVar13[param_1 + 0x45] != 0) {
      pIVar3 = self + iVar4;
      uVar11 = 0;
      pIVar7 = self + iVar4 + 0xc20;
      pIVar5 = pIVar3 + 0xc40;
      pIVar6 = pIVar3 + 0xc30;
      do {
        pIVar10 = pIVar6 + 0x10;
        pIVar12 = pIVar5 + 0xc;
        iVar4 = 0;
        pIVar8 = pIVar3 + 0xc3c;
        do {
          if (M<SInt32>(pIVar10) != 0) {
            VCALL(*M<SInt32 *>(self + 0xd50), 0x5ac)(M<SInt32 *>(self + 0xd50),pIVar8);
          }
          if (M<SInt32 *>(pIVar10 + 4) != (SInt32 *)0x0) {
            VCALL(*M<SInt32 *>(pIVar10 + 4), 0x18)(M<SInt32 *>(pIVar10 + 4));
          }
          bVar1 = iVar4 != 3;
          pIVar8 = pIVar8 + 0x1c;
          M<SInt32>(pIVar10 + -4) = 0;
          M<SInt32>(pIVar10) = 0;
          iVar4 = iVar4 + 1;
          M<SInt32>(pIVar10 + 4) = 0;
          M<UInt16>(pIVar10 + 10) = 0;
          M<UInt16>(pIVar10 + 8) = 2;
          M<UInt32>(pIVar12) = 0;
          M<UInt32>(pIVar12 + 4) = 0;
          M<UInt32>(pIVar12 + 8) = 0;
          pIVar10 = pIVar10 + 0x1c;
          pIVar12 = pIVar12 + 0x1c;
        } while (bVar1);
        if (M<SInt32 *>(pIVar7 + 8) != (SInt32 *)0x0) {
          VCALL(*M<SInt32 *>(pIVar7 + 8), 0x18)(M<SInt32 *>(pIVar7 + 8));
        }
        M<UInt16>(pIVar7 + 0xc) = 2;
        M<UInt16>(pIVar7 + 0xe) = 0;
        uVar11 = uVar11 + 1;
        pIVar3 = pIVar3 + 0x1c;
        M<UInt32>(pIVar7 + 0x18) = 0;
        M<UInt32>(pIVar7) = 0;
        M<UInt32>(pIVar7 + 4) = 0;
        M<UInt32>(pIVar7 + 8) = 0;
        M<UInt32>(pIVar7 + 0x10) = 0;
        M<UInt32>(pIVar7 + 0x14) = 0;
        pIVar6 = pIVar6 + 0x1c;
        pIVar5 = pIVar5 + 0x1c;
        pIVar7 = pIVar7 + 0x1c;
      } while (uVar11 < M<UInt32>(param_1 * 4 + M<SInt32>(self + 0xd50) + 0x114));
    }
  }
  M<UInt32>(self + param_1 * 0x94 + 0xcb0) = 0;
  return;
}
