/*
 * ATIR500GLContext_submit_context_buffer_Port.cpp
 *
 * ATIR500GLContext::submit_context_buffer (real addr 0x2a8b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x2a8b0 */
void ATIR500GLContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 *puVar2;
  SInt32 iVar3;
  UInt8 *pVVar4;
  UInt32 *puVar5;
  UInt32 uVar6;
  UInt32 *puVar7;
  UInt32 uVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  UInt32 uVar12;
  UInt32 *puVar13;
  SInt32 *piVar14;
  UInt8 *pAVar15;
  SInt32 iVar16;
  UInt8 *pAVar17;
  UInt32 uVar18;
  
  M<UInt32>(M<SInt32>(self + 200) + 0xb90) = 0;
  pAVar15 = self;
  do {
    pVVar4 = M<UInt8 *>(pAVar15 + 0x2a4);
    if (pVVar4 != (UInt8 *)0x0) {
      if (M<char>(M<SInt32>(pVVar4 + 0x14) + 0x14) != '\0') {
        this->alloc_and_load_texture((VendorTextureBuffer *)(pVVar4));
        VCALL(M<SInt32>(self), 0x5a4)(self);
        pVVar4 = M<UInt8 *>(pAVar15 + 0x2a4);
      }
      if (M<SInt32>(pVVar4 + 0x48) != 0) {
        M<UInt32>(M<SInt32>(pVVar4 + 0x24) + 0x28) = M<UInt32>(pVVar4 + 0x28);
        M<UInt32>(M<SInt32>(M<SInt32>(pAVar15 + 0x2a4) + 0x28) + 0x24) =
             M<UInt32>(M<SInt32>(pAVar15 + 0x2a4) + 0x24);
        M<UInt32>(M<SInt32>(pAVar15 + 0x2a4) + 0x24) =
             M<UInt32>(M<SInt32>(self + 200) + 0x600);
        M<SInt32>(M<SInt32>(pAVar15 + 0x2a4) + 0x28) = M<SInt32>(self + 200) + 0x5dc;
        M<UInt32>(M<SInt32>(self + 200) + 0x600) = M<UInt32>(pAVar15 + 0x2a4);
        M<SInt32>(M<SInt32>(M<SInt32>(pAVar15 + 0x2a4) + 0x24) + 0x28) = M<SInt32>(pAVar15 + 0x2a4);
      }
    }
    pAVar15 = pAVar15 + 4;
  } while (self + 0xa8 != pAVar15);
  if ((M<UInt32>(M<SInt32>(self + 0x108) + 0x1c) & 1) == 0) {
    pAVar15 = self + M<SInt32>(self + 0x28c) * 0x18;
  }
  else {
    piVar14 = M<SInt32 *>(self + 200);
    uVar12 = M<SInt32>(self + 0x28c) + 1U & 0xf;
    M<UInt32>(self + 0x28c) = uVar12;
    pAVar15 = self + uVar12 * 0x18;
    iVar16 = piVar14[0x1e0];
    iVar3 = VCALL(*piVar14, 0x54c)(piVar14,M<UInt32>(pAVar15 + 0x11c));
    piVar14[0x1e0] = iVar16 + iVar3;
    puVar2 = M<UInt32 *>(self + 0x108);
    puVar7 = M<UInt32 *>(pAVar15 + 0x120);
    uVar9 = puVar2[1];
    uVar8 = puVar2[2];
    uVar6 = puVar2[3];
    *puVar7 = *puVar2;
    puVar7[1] = uVar9;
    puVar7[2] = uVar8;
    puVar7[3] = uVar6;
    uVar9 = puVar2[4];
    uVar8 = puVar2[5];
    uVar6 = puVar2[6];
    puVar7[7] = puVar2[7];
    puVar7[4] = uVar9;
    puVar7[5] = uVar8;
    puVar7[6] = uVar6;
    puVar5 = M<UInt32 *>(self + 0x108);
    uVar10 = puVar5[5];
    puVar13 = (UInt32 *)(M<SInt32>(pAVar15 + 0x120) + 0x20);
    uVar18 = 0;
    if (uVar10 != 0) {
      iVar3 = 0;
      uVar18 = uVar10;
      do {
        M<UInt32>((SInt32)puVar13 + iVar3) = M<UInt32>((SInt32)puVar5 + iVar3 + 0x20);
        iVar3 = iVar3 + 4;
        uVar18 = uVar18 - 1;
      } while (uVar18 != 0);
      puVar5 = M<UInt32 *>(self + 0x108);
      uVar18 = uVar10;
    }
    uVar10 = 0;
    uVar18 = this->write_kernel_context_buffer_regs((UInt32 *)(puVar13),uVar18,*puVar5,puVar5[1]);
    pAVar17 = self;
    do {
      if (M<UInt8 *>(pAVar17 + 0x2a4) != (UInt8 *)0x0) {
        iVar3 = this->WriteTextureOffset(uVar10,(UInt32 *)(puVar13),uVar18,
                                   (VendorTextureBuffer *)(M<UInt8 *>(pAVar17 + 0x2a4)));
        uVar18 = uVar18 + iVar3;
      }
      bVar1 = uVar10 != 0xf;
      pAVar17 = pAVar17 + 4;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    iVar3 = this->WriteVertexArrayOffset((UInt32 *)(puVar13),uVar18);
    iVar3 = uVar18 + iVar3;
    puVar13[iVar3] = 0x1040;
    uVar11 = iVar3 + 2;
    puVar13[iVar3 + 1] = 0;
    uVar12 = uVar11;
    if ((uVar11 & 1) != 0) {
      uVar12 = iVar3 + 3;
      puVar13[uVar11] = 0x80000000;
    }
    M<UInt32>(M<SInt32>(pAVar15 + 0x120) + 0x14) = uVar12;
    M<UInt32>(M<SInt32>(self + 0x108) + 0x1c) = M<UInt32>(M<SInt32>(self + 0x108) + 0x1c) & 0xfffffffe
    ;
  }
  if (M<SInt32>(pAVar15 + 0x110) == 0) {
    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(pAVar15 + 0x10c)));
  }
  M<SInt32>(M<SInt32>(self + 200) + 0x704) =
       M<SInt32>(M<SInt32>(pAVar15 + 0x120) + 0x14) * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
  uVar6 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)(M<SInt32>(pAVar15 + 0x120) + 0x20),
                     M<SInt32>(pAVar15 + 0x110) + 0x20,M<UInt32>(M<SInt32>(pAVar15 + 0x120) + 0x14));
  M<UInt32>(pAVar15 + 0x11c) = uVar6;
  M<UInt32>(self + 0x7c) = uVar6;
  return;
}
