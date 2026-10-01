/*
 * ATIR500Surface_copy_to_buffer_Port.cpp
 *
 * ATIR500Surface::copy_to_buffer (real addr 0x43340, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


int get_offset_of_sample_0(ATIR500SurfaceBuffer *buffer, int x, int y);   /* Sources/ATIR500Surface_CopyBuffers.cpp */

/* real addr 0x43340 */
void ATIR500Surface::copy_to_buffer(SInt32 param_1, SInt32 param_2, SInt32 param_3, SInt32 param_4, UInt32 param_5, UInt32 param_6, ATIR500SurfaceBuffer *real_param_7, UInt32 param_8, VendorTransferBuffer *real_param_9, UInt32 param_10, UInt32 param_11, UInt32 param_12) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_7 = reinterpret_cast<UInt8 *>(real_param_7);
    UInt8 *param_9 = reinterpret_cast<UInt8 *>(real_param_9);

  UInt16 uVar1;
  bool bVar2;
  UInt32 uVar3;
  unsigned int uVar4;
  unsigned int uVar5;
  int iVar6;
  int *piVar7;
  UInt32 *puVar8;
  UInt32 *puVar9;
  int *piVar10;
  int iVar11;
  UInt32 *puVar12;
  UInt8 *pVVar13;
  UInt32 *puVar14;
  UInt8 bVar15;
  UInt8 bVar16;
  
  uVar3 = param_12;
  pVVar13 = M<UInt8 *>(param_7 + 0x24);
  bVar2 = (param_12 & 1) == 0;
  bVar15 = bVar2 << 1;
  if (bVar2) {
    if ((pVVar13 == (UInt8 *)0x0) ||
       (M<int>(pVVar13 + 0x54) != M<int>(self + 0x7c))) goto LAB_00043444;
LAB_00043494:
    piVar7 = M<int *>(param_9 + 8);
  }
  else {
    param_11 = (UInt32)M<UInt16>(pVVar13 + 0x52);
    param_10 = (UInt32)M<UInt16>(pVVar13 + 0x50);
    uVar5 = VCALL(*M<int *>(pVVar13 + 8), 0x128)(M<int *>(pVVar13 + 8));
    uVar4 = 0;
    if (param_11 != 0) {
      uVar4 = uVar5 / param_11;
    }
    if ((int)uVar4 < param_4) {
      param_4 = uVar4;
    }
    param_9 = pVVar13;
    if ((M<unsigned int>(self + 0xbe8) & 0x70000000) != 0) {
      iVar6 = VCALL(M<int>(self), 0x5f0)(self,param_7,param_5,param_6,0,0,&param_11);
      param_10 = param_10 + iVar6;
    }
LAB_00043444:
    iVar6 = this->copy_buffer_using_DMA(param_1,param_2,param_3,param_4,param_5,param_6,(ATIR500SurfaceBuffer *)(param_7),(VendorTransferBuffer *)(param_9),param_10
                       ,param_11,(IODirection)2,uVar3);
    if (iVar6 != 0) {
      return;
    }
    if ((bool)(bVar15 >> 1 & 1)) goto LAB_00043494;
    piVar7 = M<int *>(pVVar13 + 8);
  }
  piVar7 = (int *)VCALL(*piVar7, 0x150)
                            (piVar7,M<unsigned int>(M<int>(self + 0xd50) + 0x82c) | 1);
  if (piVar7 == (int *)0x0) {
    return;
  }
  iVar6 = VCALL(*piVar7, 0xd0)(piVar7);
  piVar10 = M<int *>(self + 0xd50);
  puVar14 = (UInt32 *)(iVar6 + param_10);
  iVar11 = piVar10[0x1ec];
  iVar6 = VCALL(*piVar10, 0x558)(piVar10,param_8);
  piVar10[0x1ec] = iVar11 + iVar6;
  if ((((bool)(bVar15 >> 1 & 1)) && (pVVar13 != (UInt8 *)0x0)) &&
     (M<int>(pVVar13 + 0x54) == M<int>(self + 0x7c))) {
    piVar10 = (int *)VCALL(*M<int *>(pVVar13 + 8), 0x150)
                               (M<int *>(pVVar13 + 8),M<unsigned int>(M<int>(self + 0xd50) + 0x82c) | 1
                               );
    bVar15 = (piVar10 == (int *)0x0) << 1;
    if (piVar10 == (int *)0x0) goto LAB_000436cc;
    iVar6 = VCALL(*piVar10, 0xd0)(piVar10);
    bVar2 = false;
    iVar6 = iVar6 + (unsigned int)M<UInt16>(pVVar13 + 0x50);
  }
  else {
    piVar10 = (int *)0x0;
    bVar2 = true;
    bVar15 = 2;
    iVar6 = M<int>(param_7 + 8) + M<int>(self + 0xc10);
  }
  uVar1 = M<UInt16>(param_7 + 0x14);
  uVar4 = (unsigned int)M<UInt16>(param_7 + 0x16);
  puVar12 = (UInt32 *)(iVar6 + uVar4 * ((unsigned int)uVar1 * param_2 + param_1));
  if (uVar4 == 2) {
    param_3 = param_3 + 7 >> 3;
  }
  else if (uVar4 < 3) {
    if (uVar4 == 1) {
      param_3 = param_3 + 0xf >> 4;
    }
    else {
LAB_000435cc:
      param_3 = param_3 + 3 >> 2;
    }
  }
  else if (uVar4 == 8) {
    param_3 = param_3 + 1 >> 1;
  }
  else if (uVar4 != 0x10) goto LAB_000435cc;
  bVar16 = !bVar2 << 1;
  if (bVar2) {
    VCALL(M<int>(self), 0x5fc)(self,param_7);
  }
  if (0 < param_4) {
    uVar5 = 0;
    do {
      puVar8 = puVar14;
      puVar9 = puVar12;
      iVar6 = param_3;
      if (0 < param_3) {
        do {
          *puVar9 = *puVar8;
          puVar9[1] = puVar8[1];
          puVar9[2] = puVar8[2];
          puVar9[3] = puVar8[3];
          iVar6 = iVar6 + -1;
          puVar8 = puVar8 + 4;
          puVar9 = puVar9 + 4;
        } while (iVar6 != 0);
      }
      uVar5 = uVar5 + 1;
      puVar12 = (UInt32 *)((int)puVar12 + uVar1 * uVar4);
      puVar14 = (UInt32 *)((int)puVar14 + param_11);
    } while (uVar5 != param_4);
  }
  if (!(bool)(bVar16 >> 1 & 1)) {
    VCALL(M<int>(self), 0x600)(self,param_7);
  }
LAB_000436cc:
  VCALL(*piVar7, 0x18)(piVar7);
  if (!(bool)(bVar15 >> 1 & 1)) {
    VCALL(*piVar10, 0x18)(piVar10);
  }
  return;
}
