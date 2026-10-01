/*
 * ATIR500Surface_submit_swap_buffer_Port.cpp
 *
 * ATIR500Surface::submit_swap_buffer (real addr 0x3ba80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3ba80 */
void ATIR500Surface::submit_swap_buffer(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  int iVar1;
  UInt32 uVar2;
  int iVar3;
  UInt32 *puVar4;
  UInt32 *puVar5;
  int iVar6;
  UInt8 *pAVar7;
  int iVar8;
  unsigned int uVar9;
  unsigned int uVar10;
  UInt32 uVar11;
  int iVar12;
  UInt32 *puVar13;
  UInt32 *puVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  int *piVar17;
  UInt32 *puVar18;
  UInt8 *pVVar19;
  
  if (M<SInt16>(self + 0xdb4) != 0) {
    M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
  }
  if (M<int>(self + 0xd54) != 0) {
    M<UInt32>(self + 0xd54) = 0;
    M<unsigned int>(M<int>(self + param_1 * 0x94 + 0xc34) + 0x1c) =
         M<unsigned int>(M<int>(self + param_1 * 0x94 + 0xc34) + 0x1c) | 1;
  }
  iVar8 = param_1 * 0x94;
  if ((M<unsigned int>(M<int>(self + iVar8 + 0xc34) + 0x1c) & 1) == 0) {
    iVar3 = (unsigned int)M<UInt16>(self + iVar8 + 0xcae) * 0x1c + iVar8;
    pVVar19 = (UInt8 *)(self + iVar3 + 0xc3c);
    if ((M<int>(self + iVar3 + 0xc44) == 0) &&
       (iVar8 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(param_1,M<UInt32>(self + iVar8 + 0xcb0)),
       iVar8 == 0)) {
      return;
    }
    goto LAB_0003be90;
  }
  uVar9 = M<UInt16>(self + iVar8 + 0xcae) + 1 & 3;
  M<SInt16>(self + iVar8 + 0xcae) = (SInt16)uVar9;
  iVar3 = uVar9 * 0x1c + iVar8;
  pVVar19 = (UInt8 *)(self + iVar3 + 0xc3c);
  if (M<int>(self + iVar3 + 0xc44) == 0) {
    iVar6 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(param_1,M<UInt32>(self + iVar8 + 0xcb0));
    if (iVar6 == 0) {
      return;
    }
  }
  else {
    piVar17 = M<int *>(self + 0xd50);
    iVar12 = piVar17[0x1e2];
    iVar6 = VCALL(*piVar17, 0x54c)(piVar17,M<UInt32>(self + iVar3 + 0xc4c));
    piVar17[0x1e2] = iVar12 + iVar6;
  }
  puVar13 = M<UInt32 *>(self + iVar3 + 0xc50);
  puVar4 = M<UInt32 *>(self + iVar8 + 0xc34);
  uVar16 = puVar4[1];
  uVar15 = puVar4[2];
  uVar11 = puVar4[3];
  *puVar13 = *puVar4;
  puVar13[1] = uVar16;
  puVar13[2] = uVar15;
  puVar13[3] = uVar11;
  uVar16 = puVar4[4];
  uVar15 = puVar4[5];
  uVar11 = puVar4[6];
  puVar13[7] = puVar4[7];
  puVar13[4] = uVar16;
  puVar13[5] = uVar15;
  puVar13[6] = uVar11;
  iVar6 = M<int>(self + iVar3 + 0xc50);
  puVar18 = (UInt32 *)(iVar6 + 0x20);
  if ((((param_2 & 0x18) == 0) || (M<SInt16>(self + 0xbee) != 0)) ||
     ((iVar12 = M<int>(self + 0xd50), M<char>(iVar12 + 0x9b0) != '\0' &&
      (M<int>(param_1 * 0x18 + iVar12 + 0xb10) != 0)))) {
    uVar9 = 0;
  }
  else {
    uVar10 = M<UInt16>(param_1 * 0x78 + iVar12 + 0x14a) & 0xfff;
    *puVar18 = 0x1393;
    M<UInt32>(iVar6 + 0x24) = 10;
    M<UInt32>(iVar6 + 0x28) = 0xd0b;
    M<UInt32>(iVar6 + 0x2c) = 5;
    M<UInt32>(iVar6 + 0x30) = 0x5c8;
    M<UInt32>(iVar6 + 0x34) = 0x70000;
    if (param_1 == 0) {
      iVar1 = M<int>(iVar12 + 0x894);
      if (iVar1 == 0) {
        M<UInt32>(iVar6 + 0x38) = 0x194e;
        M<unsigned int>(iVar6 + 0x3c) = (uVar10 & ~M<unsigned int>(iVar12 + 0x898)) << 0x10 | 0x80000000;
        M<UInt32>(iVar6 + 0x40) = 0x5c8;
        M<UInt32>(iVar6 + 0x44) = 8;
        uVar9 = 10;
      }
      else {
LAB_0003bcbc:
        uVar9 = 6;
        if (iVar1 != 0) goto LAB_0003bcc8;
      }
    }
    else {
      if (param_1 != 1) {
        iVar1 = M<int>(iVar12 + 0x894);
        goto LAB_0003bcbc;
      }
LAB_0003bcc8:
      uVar9 = 10;
      M<UInt32>(iVar6 + 0x38) = 0x1b4e;
      M<unsigned int>(iVar6 + 0x3c) = (uVar10 & ~M<unsigned int>(iVar12 + 0x89c)) << 0x10 | 0x80000000;
      M<UInt32>(iVar6 + 0x40) = 0x5c8;
      M<UInt32>(iVar6 + 0x44) = 0x80000008;
    }
  }
  iVar6 = M<int>(self + iVar8 + 0xc34);
  iVar12 = M<int>(iVar6 + 0x14) - M<int>(iVar6 + 0x18);
  puVar14 = (UInt32 *)(iVar6 + 0x20 + M<int>(iVar6 + 0x18) * 4);
  if (iVar12 != 0) {
    iVar6 = 0;
    puVar5 = puVar18 + uVar9;
    do {
      uVar2 = *puVar14;
      iVar6 = iVar6 + 1;
      puVar14 = puVar14 + 1;
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    uVar9 = uVar9 + iVar6;
  }
  pAVar7 = M<UInt8 *>(self + 0xd50);
  if (pAVar7[0x9b0] == 0x0) {
    uVar11 = 0;
  }
  else if ((M<int>(pAVar7 + 0x894) == 0) || (M<int>(pAVar7 + 0xb28) == 0)) {
    if (M<int>(pAVar7 + param_1 * 0x18 + 0xb10) == 0) {
      uVar9 = ((ATIRadeonX1000 *)(pAVar7))->SWDSWriteBlitToCmdBuf((UInt32 *)(puVar18), uVar9, true, (unsigned int)(param_1 == 0));
      uVar11 = 1;
    }
    else {
      uVar9 = ((ATIRadeonX1000 *)(pAVar7))->SWDSWriteBlitToCmdBuf((UInt32 *)(puVar18), uVar9, true, param_1);
      uVar11 = 1;
    }
  }
  else {
    uVar9 = ((ATIRadeonX1000 *)(pAVar7))->SWDSWriteBlitToCmdBuf((UInt32 *)(puVar18), uVar9, true, 1);
    uVar11 = 1;
  }
  *M<UInt32 *>(self + iVar3 + 0xc50) = uVar11;
  uVar10 = uVar9;
  if ((uVar9 & 1) != 0) {
    uVar10 = uVar9 + 1;
    puVar18[uVar9] = 0x80000000;
  }
  M<unsigned int>(M<int>(self + iVar3 + 0xc50) + 0x14) = uVar10;
  M<unsigned int>(M<int>(self + iVar8 + 0xc34) + 0x1c) =
       M<unsigned int>(M<int>(self + iVar8 + 0xc34) + 0x1c) & 0xfffffffe;
LAB_0003be90:
  if (M<int>(pVVar19 + 4) == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar19));
  }
  M<int>(M<int>(self + 0xd50) + 0x710) =
       M<int>(M<int>(pVVar19 + 0x14) + 0x14) * 4 + M<int>(M<int>(self + 0xd50) + 0x710);
  pAVar7 = M<UInt8 *>(self + 0xd50);
  uVar11 = ((ATIRadeonX1000 *)(pAVar7))->submit_buffer((UInt32 *)(M<int>(pVVar19 + 0x14) + 0x20),M<int>(pVVar19 + 4) + 0x20
                      ,M<UInt32>(M<int>(pVVar19 + 0x14) + 0x14));
  M<UInt32>(pVVar19 + 0x10) = uVar11;
  M<UInt32>(self + 0x80) = uVar11;
  M<UInt32>(pAVar7 + param_1 * 0x20 + 0xec) = uVar11;
  iVar8 = M<int>(self + 0xd50);
  if ((M<char>(iVar8 + 0x9b0) != '\0') && (*M<int *>(pVVar19 + 0x14) != 0)) {
    if (M<int>(param_1 * 0x18 + iVar8 + 0xb10) == 0) {
      if ((M<int>(iVar8 + 0x894) != 0) &&
         (M<int>((unsigned int)(param_1 == 0) * 0x18 + iVar8 + 0xb10) != 0)) {
        M<UInt32>((unsigned int)(param_1 == 0) * 4 + iVar8 + 0xad4) = M<UInt32>(self + 0x80);
        M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
      }
    }
    else {
      M<UInt32>(param_1 * 4 + iVar8 + 0xad4) = M<UInt32>(self + 0x80);
      M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
    }
  }
  return;
}
