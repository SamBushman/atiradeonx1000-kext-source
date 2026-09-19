/*
 * ATIR5002DContext_submit_context_buffer_Port.cpp
 *
 * ATIR5002DContext::submit_context_buffer (real addr 0x31e90, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x31e90 */
void ATIR5002DContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 bVar1;
  UInt8 *pAVar2;
  UInt32 *puVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  UInt8 *pVVar7;
  SInt32 iVar8;
  SInt32 iVar9;
  UInt32 uVar10;
  SInt32 iVar11;
  UInt32 *puVar12;
  UInt32 uVar13;
  SInt32 iVar14;
  UInt32 uVar15;
  SInt32 iVar16;
  UInt32 uVar17;
  SInt32 iVar18;
  SInt32 iVar19;
  SInt32 iVar20;
  SInt32 iVar21;
  SInt32 iVar22;
  SInt32 iVar23;
  SInt32 iVar24;
  SInt32 iVar25;
  SInt32 iVar26;
  SInt32 iVar27;
  SInt32 iVar28;
  SInt32 iVar29;
  SInt32 iVar30;
  SInt32 iVar31;
  SInt32 iVar32;
  SInt32 iVar33;
  SInt32 *piVar34;
  SInt32 iVar35;
  SInt32 iVar36;
  SInt32 iVar37;
  SInt32 iVar38;
  SInt32 iVar39;
  SInt32 local_98;
  SInt32 local_94;
  SInt32 local_90;
  SInt32 local_8c;
  SInt32 local_88;
  SInt32 local_84;
  SInt32 local_80;
  SInt32 local_7c;
  SInt32 local_78;
  SInt32 local_74;
  SInt32 local_70;
  SInt32 local_6c;
  SInt32 local_68;
  SInt32 local_64;
  SInt32 local_60;
  SInt32 local_5c;
  SInt32 local_58;
  SInt32 local_54;
  
  pVVar7 = M<UInt8 *>(self + 0x114);
  if (pVVar7 != (UInt8 *)0x0) {
    if (M<char>(M<SInt32>(pVVar7 + 0x14) + 0x14) != '\0') {
      this->alloc_and_load_image((VendorTextureBuffer *)(pVVar7));
      pVVar7 = M<UInt8 *>(self + 0x114);
    }
    if (M<SInt32>(pVVar7 + 0x48) != 0) {
      M<UInt32>(M<SInt32>(pVVar7 + 0x24) + 0x28) = M<UInt32>(pVVar7 + 0x28);
      M<UInt32>(M<SInt32>(M<SInt32>(self + 0x114) + 0x28) + 0x24) =
           M<UInt32>(M<SInt32>(self + 0x114) + 0x24);
      M<UInt32>(M<SInt32>(self + 0x114) + 0x24) =
           M<UInt32>(M<SInt32>(self + 0x94) + 0x600);
      M<SInt32>(M<SInt32>(self + 0x114) + 0x28) = M<SInt32>(self + 0x94) + 0x5dc;
      M<UInt32>(M<SInt32>(self + 0x94) + 0x600) = M<UInt32>(self + 0x114);
      M<SInt32>(M<SInt32>(M<SInt32>(self + 0x114) + 0x24) + 0x28) = M<SInt32>(self + 0x114);
    }
  }
  if ((M<UInt32>(M<SInt32>(self + 200) + 0x1c) & 1) == 0) {
    pAVar2 = self + M<SInt32>(self + 0xfc) * 0x18;
  }
  else {
    piVar34 = M<SInt32 *>(self + 0x94);
    uVar6 = M<SInt32>(self + 0xfc) + 1U & 1;
    M<UInt32>(self + 0xfc) = uVar6;
    pAVar2 = self + uVar6 * 0x18;
    iVar36 = piVar34[0x1df];
    iVar5 = VCALL(*piVar34, 0x54c)(piVar34,M<UInt32>(pAVar2 + 0xdc));
    piVar34[0x1df] = iVar36 + iVar5;
    puVar3 = M<UInt32 *>(self + 200);
    puVar12 = M<UInt32 *>(pAVar2 + 0xe0);
    uVar15 = puVar3[1];
    uVar13 = puVar3[2];
    uVar10 = puVar3[3];
    *puVar12 = *puVar3;
    puVar12[1] = uVar15;
    puVar12[2] = uVar13;
    puVar12[3] = uVar10;
    uVar10 = puVar3[7];
    uVar15 = puVar3[4];
    uVar13 = puVar3[5];
    puVar12[6] = puVar3[6];
    puVar12[7] = uVar10;
    puVar12[4] = uVar15;
    puVar12[5] = uVar13;
    iVar5 = M<SInt32>(self + 200);
    iVar36 = M<SInt32>(pAVar2 + 0xe0);
    local_98 = M<SInt32>(iVar5 + 0x14);
    iVar11 = iVar36 + 0x20;
    if (local_98 == 0) {
      iVar5 = 0;
      iVar35 = 1;
      local_98 = 0;
      local_54 = 0x11;
      iVar38 = 0x12;
      iVar16 = 2;
      iVar39 = 0x13;
      iVar37 = 3;
      local_58 = 0x18;
      iVar8 = 4;
      local_5c = 0x19;
      local_60 = 0x1a;
      local_64 = 0x1b;
      local_68 = 0x1c;
      local_6c = 0x1d;
      local_70 = 0x1e;
      local_74 = 0x1f;
      local_78 = 0x20;
      local_7c = 0x21;
      local_80 = 0x22;
      local_84 = 0x23;
      local_88 = 0x24;
      iVar31 = 5;
      local_8c = 0x25;
      iVar32 = 6;
      iVar33 = 7;
      local_90 = 0x26;
      iVar18 = 8;
      local_94 = 0x27;
      iVar23 = 9;
      iVar24 = 10;
      iVar25 = 0xb;
      iVar26 = 0xc;
      iVar27 = 0xd;
      iVar28 = 0xe;
      iVar29 = 0xf;
      iVar30 = 0x10;
      iVar19 = 0x14;
      iVar20 = 0x15;
      iVar21 = 0x16;
      iVar22 = 0x17;
      uVar6 = 0x28;
    }
    else {
      iVar38 = 0;
      iVar36 = local_98;
      do {
        M<UInt32>(iVar11 + iVar38) = M<UInt32>(iVar5 + 0x20 + iVar38);
        iVar38 = iVar38 + 4;
        iVar36 = iVar36 + -1;
      } while (iVar36 != 0);
      local_54 = local_98 + 0x11;
      iVar36 = M<SInt32>(pAVar2 + 0xe0);
      iVar38 = local_98 + 0x12;
      iVar5 = local_98 << 2;
      iVar39 = local_98 + 0x13;
      local_58 = local_98 + 0x18;
      iVar35 = local_98 + 1;
      local_5c = local_98 + 0x19;
      local_60 = local_98 + 0x1a;
      iVar16 = local_98 + 2;
      local_64 = local_98 + 0x1b;
      local_68 = local_98 + 0x1c;
      local_6c = local_98 + 0x1d;
      local_70 = local_98 + 0x1e;
      local_74 = local_98 + 0x1f;
      local_78 = local_98 + 0x20;
      local_7c = local_98 + 0x21;
      local_80 = local_98 + 0x22;
      local_84 = local_98 + 0x23;
      local_88 = local_98 + 0x24;
      local_8c = local_98 + 0x25;
      local_90 = local_98 + 0x26;
      local_94 = local_98 + 0x27;
      iVar37 = local_98 + 3;
      iVar8 = local_98 + 4;
      iVar31 = local_98 + 5;
      iVar32 = local_98 + 6;
      iVar33 = local_98 + 7;
      iVar18 = local_98 + 8;
      iVar23 = local_98 + 9;
      iVar24 = local_98 + 10;
      iVar25 = local_98 + 0xb;
      iVar26 = local_98 + 0xc;
      iVar27 = local_98 + 0xd;
      iVar28 = local_98 + 0xe;
      iVar29 = local_98 + 0xf;
      iVar30 = local_98 + 0x10;
      iVar19 = local_98 + 0x14;
      iVar20 = local_98 + 0x15;
      iVar21 = local_98 + 0x16;
      iVar22 = local_98 + 0x17;
      uVar6 = local_98 + 0x28;
    }
    if (M<SInt32>(self + 0x100) == 0) {
      iVar14 = M<SInt32>(self + 0x94);
      iVar9 = M<SInt32>(self + 0x110) * 0x78 + iVar14 + 300;
    }
    else {
      iVar14 = M<SInt32>(self + 0x94);
      iVar9 = M<SInt32>(self + 0x100) + 0xa8;
    }
    M<UInt32>(iVar11 + iVar5) = 0x1393;
    M<UInt32>(iVar11 + iVar35 * 4) = 10;
    M<UInt32>(iVar11 + iVar16 * 4) = 0xd0b;
    M<UInt32>(iVar11 + iVar37 * 4) = 5;
    M<UInt32>(iVar11 + iVar8 * 4) = 0x13c6;
    M<UInt32>(iVar11 + iVar31 * 4) = 3;
    M<UInt32>(iVar11 + iVar32 * 4) = 0x5c8;
    M<UInt32>(iVar11 + iVar33 * 4) = 0x70000;
    M<UInt32>(iVar11 + iVar18 * 4) = 0x1006;
    M<UInt32>(iVar11 + iVar23 * 4) = M<UInt32>(iVar14 + 0xb74);
    M<UInt32>(iVar11 + iVar24 * 4) = 0x1008;
    M<UInt32>(iVar11 + iVar25 * 4) = 0;
    M<UInt32>(iVar11 + iVar26 * 4) = 0x1380;
    M<UInt32>(iVar11 + iVar27 * 4) = 0;
    M<UInt32>(iVar11 + iVar28 * 4) = 0x13c7;
    M<UInt32>(iVar11 + iVar29 * 4) = 0;
    M<UInt32>(iVar11 + iVar30 * 4) = 0x10e9;
    M<UInt32>(iVar11 + local_54 * 4) = 0;
    M<UInt32>(iVar11 + iVar38 * 4) = 0x13de;
    M<UInt32>(iVar11 + iVar39 * 4) = 0;
    M<UInt32>(iVar11 + iVar19 * 4) = 0x13ad;
    M<UInt32>(iVar11 + iVar20 * 4) = 0;
    M<UInt32>(iVar11 + iVar21 * 4) = 0x105bb;
    M<UInt32>(iVar11 + iVar22 * 4) = 0;
    M<UInt32>(iVar11 + local_58 * 4) =
         CONCAT22(M<UInt16>(iVar9 + 0x1e),M<UInt16>(iVar9 + 0x1c));
    M<UInt32>(iVar11 + local_5c * 4) = 0x11004;
    M<UInt32>(iVar11 + local_60 * 4) = 0x66666666;
    M<UInt32>(iVar11 + local_64 * 4) = 0x6666666;
    M<UInt32>(iVar11 + local_68 * 4) = 0x5b8;
    bVar1 = M<UInt8>(iVar9 + 0x38);
    uVar17 = M<UInt32>(iVar9 + 8);
    uVar4 = 0x80000000;
    if (bVar1 < 2) {
      uVar4 = 0;
    }
    M<UInt32>(iVar11 + local_6c * 4) =
         uVar4 | uVar17 >> 10 | (M<UInt16>(iVar9 + 0x18) & 0x3fc0) << 0x10 | (bVar1 & 1) << 0x1e;
    M<UInt32>(iVar11 + local_70 * 4) = 0x138a;
    M<UInt32>(iVar11 + local_74 * 4) = uVar17 & 0xffffffe0;
    M<UInt32>(iVar11 + local_78 * 4) = 0x138e;
    M<UInt32>(iVar11 + local_7c * 4) =
         M<UInt16>(iVar9 + 0x14) & 0x3ffe | (bVar1 & 1) << 0x10 | (bVar1 & 6) << 0x10 |
         (M<UInt8>(iVar9 + 0x39) & 3) << 0x13 | (M<UInt8>(iVar9 + 0x3b) & 0xf) << 0x15;
    M<UInt32>(iVar11 + local_80 * 4) = 0xd0a;
    M<UInt32>(iVar11 + local_84 * 4) = 0x100;
    M<UInt32>(iVar11 + local_88 * 4) = 0x1383;
    M<UInt32>(iVar11 + local_8c * 4) = 0xf;
    M<UInt32>(iVar11 + local_90 * 4) = 0x1386;
    M<UInt32>(iVar11 + local_94 * 4) = 0;
    if ((uVar6 & 1) != 0) {
      iVar5 = uVar6 * 4;
      uVar6 = local_98 + 0x29;
      M<UInt32>(iVar11 + iVar5) = 0x80000000;
    }
    M<UInt32>(iVar36 + 0x14) = uVar6;
    M<UInt32>(M<SInt32>(self + 200) + 0x1c) = M<UInt32>(M<SInt32>(self + 200) + 0x1c) & 0xfffffffe;
  }
  if (M<SInt32>(pAVar2 + 0xd0) == 0) {
    ((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(pAVar2 + 0xcc)));
  }
  M<SInt32>(M<SInt32>(self + 0x94) + 0x700) =
       M<SInt32>(M<SInt32>(pAVar2 + 0xe0) + 0x14) * 4 + M<SInt32>(M<SInt32>(self + 0x94) + 0x700);
  uVar10 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0x94)))->submit_buffer((UInt32 *)(M<SInt32>(pAVar2 + 0xe0) + 0x20),
                      M<SInt32>(pAVar2 + 0xd0) + 0x20,M<UInt32>(M<SInt32>(pAVar2 + 0xe0) + 0x14));
  M<UInt32>(pAVar2 + 0xdc) = uVar10;
  M<UInt32>(self + 0x7c) = uVar10;
  return;
}
