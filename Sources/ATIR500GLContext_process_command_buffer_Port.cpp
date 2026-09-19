/*
 * ATIR500GLContext_process_command_buffer_Port.cpp
 *
 * ATIR500GLContext::process_command_buffer (real addr 0x2b820, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x2b820 */
IOReturn ATIR500GLContext::process_command_buffer(VendorCommandDescriptor *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  bool bVar2;
  UInt32 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  UInt8 AVar10;
  UInt8 AVar11;
  UInt8 AVar12;
  UInt8 AVar13;
  UInt16 uVar14;
  UInt16 uVar15;
  SInt32 iVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  double dVar31;
  UInt32 uVar32;
  SInt32 iVar33;
  UInt32 uVar34;
  UInt32 uVar35;
  SInt32 *piVar36;
  UInt32 uVar37;
  UInt32 uVar38;
  SInt32 iVar39;
  UInt32 uVar40;
  UInt32 uVar41;
  UInt32 *puVar42;
  UInt8 *pAVar43;
  UInt32 uVar44;
  UInt8 *pAVar45;
  UInt32 uVar46;
  UInt32 uVar47;
  SInt32 iVar48;
  SInt32 iVar49;
  UInt32 uVar50;
  UInt8 *pVVar51;
  SInt32 iVar52;
  UInt32 uVar53;
  UInt32 *puVar54;
  UInt32 uVar55;
  UInt32 uVar56;
  UInt32 uVar57;
  UInt32 uVar58;
  SInt32 iVar59;
  UInt32 uVar60;
  UInt32 uVar61;
  UInt32 uVar62;
  UInt32 uVar63;
  UInt32 uVar64;
  UInt32 *puVar65;
  UInt8 *pIVar66;
  UInt32 *puVar67;
  UInt8 *pAVar68;
  UInt32 *puVar69;
  UInt8 *pVVar70;
  UInt32 uVar71;
  UInt8 *pAVar72;
  UInt32 uVar73;
  SInt32 iVar74;
  UInt32 uVar75;
  UInt8 *pAVar76;
  UInt8 *pAVar77;
  UInt32 uVar78;
  UInt8 *pVVar79;
  char in_RESERVE;
  UInt8 in_cr0;
  UInt8 bVar80;
  UInt32 uVar81;
  UInt32 local_388;
  UInt32 local_384;
  UInt32 local_380;
  UInt8 *local_37c;
  UInt8 *local_378;
  UInt8 local_374 [0x80];   /* the ATIR500SurfaceBuffer on the shipped stack (Ghidra shows 0x2c bytes here + M<UInt32>(local_374 + 0x2c) = its +0x2c word) */
  register_tracking_state arStack_2fc [1];   /* one 24-byte record on the shipped stack */
  UInt32 local_2e4;
  UInt32 local_2e0;
  UInt32 *local_1c8;
  UInt32 *local_1c4;
  SInt32 local_1c0;
  UInt32 *local_1bc;
  UInt32 local_1b8;
  SInt32 iStack_1b4;
  UInt32 local_1b0;
  SInt32 iStack_1ac;
  UInt32 local_1a8;
  UInt32 uStack_1a4;
  UInt32 local_1a0;
  UInt32 uStack_19c;
  UInt32 local_198;
  UInt32 uStack_194;
  UInt32 local_190;
  SInt32 iStack_18c;
  UInt32 local_188;
  SInt32 iStack_184;
  UInt32 local_180;
  UInt32 uStack_17c;
  UInt32 local_178;
  UInt32 uStack_174;
  SInt64 local_170;
  SInt64 local_168;
  SInt64 local_160;
  UInt32 local_158;
  UInt32 uStack_154;
  SInt64 local_150;
  UInt32 local_148;
  UInt32 uStack_144;
  UInt32 local_140;
  UInt32 uStack_13c;
  UInt32 local_138;
  UInt32 uStack_134;
  SInt64 local_130;
  SInt64 local_128;
  UInt32 local_120;
  UInt32 uStack_11c;
  UInt32 local_118;
  UInt32 uStack_114;
  UInt32 local_110;
  UInt32 uStack_10c;
  UInt32 local_108;
  UInt32 uStack_104;
  UInt32 local_100;
  UInt32 uStack_fc;
  UInt32 local_f8;
  UInt32 uStack_f4;
  UInt32 local_f0;
  UInt32 uStack_ec;
  SInt64 local_e8;
  SInt64 local_e0;
  UInt32 local_d8;
  UInt32 uStack_d4;
  UInt32 *local_d0;
  UInt32 local_cc;
  UInt32 local_c8;
  UInt32 local_c4;
  UInt8 *local_c0;
  UInt32 *local_bc;
  
  puVar69 = M<UInt32 *>(self + 0x108);
  local_388 = 0;
  local_384 = 0xffffffff;
  local_380 = 0;
  local_1c8 = puVar69 + 8;
  local_c8 = 0;
  local_c4 = 0;
  local_cc = 0;
  local_1c0 = M<SInt32>(self + 0xe0) + 0x20;
  puVar65 = (UInt32 *)(M<SInt32>(self + 0xe0) + 0x1c);
  local_1c4 = local_1c8 + puVar69[5];
  local_2e4 = this->compute_sc_hyperz_en(*puVar69);
  local_2e0 = this->compute_zb_bw_cntl(puVar69[1]);
  uVar55 = local_384;
  do {
    local_384 = uVar55;
    uVar73 = *puVar65;
    uVar63 = uVar73 & 0xffffff;
    iVar52 = uVar63 * 4;
    dataCacheBlockTouch(puVar65 + uVar63);
    uVar38 = uVar73 & 0xff000000;
    uVar75 = (uVar73 >> 0x18) - 6;
    if (uVar75 < 0x10) {
      iVar59 = uVar75 * 4;
      pVVar70 = M<UInt8 *>(self + iVar59 + 0x2a4);
      if (pVVar70 != (UInt8 *)0x0) {
        ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(pVVar70));
        piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
        iVar48 = atomicAddReturningOld((SInt32 *)piVar36, -1);
        if (iVar48 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
        }
        M<UInt32>(self + iVar59 + 0x2a4) = 0;
      }
      if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar65[1]) ||
         (pVVar70 = *(UInt8 **)
                     (puVar65[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
         pVVar70 == (UInt8 *)0x0)) goto LAB_00030d40;
      local_378 = pVVar70;
      ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(pVVar70));
      iVar48 = M<SInt32>(pVVar70 + 0x14);
      if (M<char>(iVar48 + 0x14) != '\0') {
        if (local_384 != 0) {
          uVar38 = puVar65[-1] >> 2;
          if (4 < uVar38) {
            uVar73 = 0x80000000;
            if (uVar38 != 5) {
              uVar73 = (uVar38 - 6) * 0x10000 | 0xc0001000;
            }
            puVar65[-uVar38] = uVar73;
          }
          puVar65[-4] = 0x1393;
          puVar65[-3] = 0;
          puVar65[-2] = 0x5c8;
          puVar65[-1] = 0x20000;
          M<UInt32>(M<SInt32>(self + 200) + 0x704) =
               local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
          M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
          uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) + 0x20),
                              local_388 + M<SInt32>(self + 0xd0) + 0x20,local_384);
          uVar55 = local_384;
          M<UInt32>(self + 0xdc) = uVar40;
          local_380 = 0;
          local_384 = 0;
          local_388 = uVar55 * 4 + local_388;
        }
        this->alloc_and_load_texture((VendorTextureBuffer *)(pVVar70));
        if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
          local_1bc = puVar65;
          this->restore_state_destroyed_by_pageoff((register_tracking_state *)(arStack_2fc));
        }
        if (M<SInt32>(self + 0xd0) == 0) {
          ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
        }
      }
      uVar37 = M<UInt32>(pVVar70 + 0x68);
      uVar38 = puVar65[2] >> 0x1e;
      uVar73 = uVar38 << 0x1e;
      M<UInt32>(pVVar70 + 0x68) = uVar73 | uVar37 & 0x3fffffff;
      if (uVar38 != 0) {
        bVar80 = M<UInt8>(puVar65 + 3);
        uVar53 = (UInt32)bVar80 << 0x16;
        M<UInt32>(pVVar70 + 0x68) = uVar53 | uVar73 | uVar37 & 0x3fffff;
        if (uVar38 == 1) {
          iVar33 = (UInt32)bVar80 * 0x1c;
          bVar1 = (M<UInt8>(M<SInt32>(pVVar70 + 0x14) + 0x15) & 0x18) == 0;
          in_cr0 = bVar1 << 1;
          if (bVar1) {
            uVar38 = FormatTableLookup_0x0004d2dc(iVar33);
            iVar33 = 0;
          }
          else {
            uVar38 = FormatTableLookup_0x0004d2dc(iVar33);
            iVar33 = -(uVar38 >> 8 & 3);
          }
          iVar33 = (SInt32)(puVar65[3] & 0xffffff) >> ((iVar33 - (uVar38 >> 0xc & 7)) + 5 & 0x3f);
          uVar38 = iVar33 << 5;
          if ((M<UInt8>(M<SInt32>(pVVar70 + 0x14) + 0x15) & 4) != 0) {
            uVar38 = (iVar33 << 0xc) >> 3;
          }
          M<UInt32>(pVVar70 + 0x68) =
               uVar38 >> 5 & 0x3fffff | M<UInt32>(pVVar70 + 0x68) & 0xffc00000;
        }
        else if (pVVar70[0x20] == 0x0) {
          pIVar66 = M<UInt8 *>(pVVar70 + 0x50);
          uVar38 = 0;
          if (pIVar66 != (UInt8 *)0x0) {
            iVar33 = ((IOATIR500Surface *)(pIVar66))->surface_buffer_idx_mask(M<UInt32>(pVVar70 + 0x58),(UInt32 *)&local_378);
            uVar38 = (UInt32)M<UInt16>(M<SInt32>(pIVar66 + iVar33 * 4 + 0xb70) + 0x14) *
                     (UInt32)M<UInt16>(M<SInt32>(pIVar66 + iVar33 * 4 + 0xb70) + 0x16);
            if (uVar38 < 0x20) {
              uVar38 = 0x20;
            }
          }
          M<UInt32>(pVVar70 + 0x68) =
               uVar38 * (puVar65[3] & 0xffffff) >> 5 & 0x3fffff |
               M<UInt32>(pVVar70 + 0x68) & 0xffc00000;
        }
        else {
          M<UInt32>(pVVar70 + 0x68) = puVar65[3] & 0x3fffff | uVar53 | uVar73;
        }
      }
      piVar36 = (SInt32 *)(iVar48 + 0x10);
      M<UInt32>(pVVar70 + 0x60) = puVar65[2] & 0x3fffffff;
      atomicAddReturningOld((SInt32 *)piVar36, -0xffff);
      if (M<SInt32>(pVVar70 + 0x48) != 0) {
        iVar48 = M<SInt32>(pVVar70 + 0x24);
        M<UInt32>(iVar48 + 0x28) = M<UInt32>(pVVar70 + 0x28);
        M<SInt32>(M<SInt32>(pVVar70 + 0x28) + 0x24) = iVar48;
        M<UInt32>(pVVar70 + 0x24) = M<UInt32>(M<SInt32>(self + 200) + 0x600);
        M<SInt32>(pVVar70 + 0x28) = M<SInt32>(self + 200) + 0x5dc;
        M<UInt8 *>(M<SInt32>(self + 200) + 0x600) = pVVar70;
        M<UInt8 *>(M<SInt32>(pVVar70 + 0x24) + 0x28) = pVVar70;
      }
      this->WriteTextureOffset(uVar75,(UInt32 *)(puVar65),0,(VendorTextureBuffer *)(pVVar70));
      M<UInt8 *>(self + iVar59 + 0x2a4) = pVVar70;
    }
    else if (uVar38 == 0x39000000) {
      uVar38 = puVar65[1];
      uVar71 = puVar65[2];
      uVar61 = puVar65[3];
      uVar55 = puVar65[4];
      uVar64 = puVar65[5];
      uVar62 = puVar65[6];
      uVar58 = puVar65[7];
      *puVar65 = 0xc0061000;
      M<UInt32>(self + 0x364) = uVar71;
      iVar52 = uVar61 + ((uVar38 & -uVar71) - uVar71) + 1;
      in_cr0 = (iVar52 == 0) << 1;
      if (iVar52 != 0) {
        bVar80 = (uVar61 == 0) << 1;
        iVar48 = 0;
        local_bc = puVar65 + -1;
        iVar59 = 0x10;
        iVar33 = 0;
        iVar74 = 0x20;
        pAVar45 = local_374;
        do {
          if ((!(bool)(bVar80 >> 1 & 1)) && (iVar48 == iVar52 + -1)) {
            iVar59 = 0x20;
          }
          uVar73 = M<UInt32>((SInt32)puVar65 + iVar33 + 0x20);
          if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= uVar73) ||
             (iVar49 = M<SInt32>(uVar73 * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)), iVar49 == 0))
          {
            bVar1 = true;
            uVar63 = 0;
            local_384 = 0;
            M<UInt32>(M<SInt32>(self + 200) + 0x50) =
                 M<SInt32>(M<SInt32>(self + 200) + 0x50) - local_380;
            goto LAB_0002c0b4;
          }
          M<SInt32>(pAVar45) = iVar49;
          iVar49 = iVar59 * 4;
          if (M<UInt8 *>(self + iVar49 + 0x2a4) != (UInt8 *)0x0) {
            ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + iVar49 + 0x2a4)));
            pVVar70 = M<UInt8 *>(self + iVar49 + 0x2a4);
            piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
            iVar39 = atomicAddReturningOld((SInt32 *)piVar36, -1);
            if (iVar39 == 1) {
              ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
            }
            M<UInt32>(self + iVar49 + 0x2a4) = 0;
          }
          if (((iVar59 == 0x20) &&
              (iVar39 = M<SInt32>(local_374 + iVar33), M<char>(iVar39 + 0x20) == '\a')) &&
             (uVar55 != M<UInt32>(iVar39 + 100))) {
            M<UInt32>(iVar39 + 100) = uVar55;
            M<UInt8>(M<SInt32>(M<SInt32>(local_374 + iVar33) + 0x14) + 0x14) = 1;
          }
          pAVar76 = local_374 + iVar33;
          ((IOATIR500GLContext *)((UInt8 *)self))->add_texture_to_stream((VendorTextureBuffer *)(M<UInt8 *>(local_374 + iVar33)));
          if (M<char>(M<SInt32>(M<SInt32>(local_374 + iVar33) + 0x14) + 0x14) != '\0') {
            if (local_384 != 0) {
              uVar73 = puVar65[-1] >> 2;
              if (4 < uVar73) {
                uVar75 = 0x80000000;
                if (uVar73 != 5) {
                  uVar75 = (uVar73 - 6) * 0x10000 | 0xc0001000;
                }
                puVar65[-uVar73] = uVar75;
              }
              puVar65[-4] = 0x1393;
              puVar65[-2] = 0x5c8;
              puVar65[-3] = 0;
              *local_bc = 0x20000;
              M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                   local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
              M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
              uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) + 0x20)
                                  ,local_388 + M<SInt32>(self + 0xd0) + 0x20,local_384);
              uVar32 = local_384;
              M<UInt32>(self + 0xdc) = uVar40;
              local_380 = 0;
              local_384 = 0;
              local_388 = uVar32 * 4 + local_388;
            }
            this->alloc_and_load_texture((VendorTextureBuffer *)(M<UInt8 *>(pAVar76)));
            if (M<SInt32>(self + 0xd0) == 0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
            }
          }
          iVar39 = M<SInt32>(pAVar76);
          piVar36 = (SInt32 *)(M<SInt32>(iVar39 + 0x14) + 0x10);
          atomicAddReturningOld((SInt32 *)piVar36, -0xffff);
          if (M<SInt32>(iVar39 + 0x48) != 0) {
            M<UInt32>(M<SInt32>(iVar39 + 0x24) + 0x28) = M<UInt32>(iVar39 + 0x28);
            M<UInt32>(M<SInt32>(M<SInt32>(pAVar76) + 0x28) + 0x24) =
                 M<UInt32>(M<SInt32>(pAVar76) + 0x24);
            M<UInt32>(M<SInt32>(pAVar76) + 0x24) = M<UInt32>(M<SInt32>(self + 200) + 0x600);
            M<SInt32>(M<SInt32>(pAVar76) + 0x28) = M<SInt32>(self + 200) + 0x5dc;
            M<UInt32>(M<SInt32>(self + 200) + 0x600) = M<UInt32>(pAVar76);
            M<SInt32>(M<SInt32>(M<SInt32>(pAVar76) + 0x24) + 0x28) = M<SInt32>(pAVar76);
            iVar39 = M<SInt32>(pAVar76);
          }
          M<SInt32>(self + iVar49 + 0x2a4) = iVar39;
          M<UInt32>((SInt32)puVar65 + iVar74) = 0x80000000;
          iVar48 = iVar48 + 1;
          pAVar45 = pAVar45 + 4;
          iVar74 = iVar74 + 4;
          iVar59 = iVar59 + 1;
          iVar33 = iVar33 + 4;
        } while (iVar52 != iVar48);
      }
      bVar1 = false;
LAB_0002c0b4:
      if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
        local_1bc = puVar65;
        this->restore_state_destroyed_by_pageoff((register_tracking_state *)(arStack_2fc));
      }
      if (!bVar1) {
        uVar73 = uVar38 + 1 >> 1;
        in_cr0 = (uVar73 == 0) << 1;
        if (uVar73 != 0) {
          bVar80 = (uVar71 == 0) << 1;
          uVar37 = 0;
          puVar69 = puVar65 + uVar64;
          uVar75 = 0;
          pAVar77 = self;
          do {
            uVar71 = *puVar69;
            M<UInt32>(pAVar77 + 0x368) = uVar71;
            if (uVar71 == 0xffffffff) {
              iVar59 = uVar62 * 4;
              uVar62 = uVar62 + 4;
              uVar71 = (SInt32)puVar65 +
                       M<SInt32>(M<SInt32>(self + 200) + 0x8a4) + M<SInt32>(self + 0xd0) +
                       (iVar59 - (M<SInt32>(self + 0xe0) + 0x20)) + 0x20;
            }
            else {
              uVar71 = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(local_374 + uVar37 * 4)),uVar71);
            }
            puVar65[uVar64] = uVar71;
            if (!(bool)(bVar80 >> 1 & 1)) {
              uVar37 = uVar37 + 1;
            }
            if (uVar37 == uVar38) break;
            uVar71 = puVar69[1];
            M<UInt32>(pAVar77 + 0x36c) = uVar71;
            if (uVar71 == 0xffffffff) {
              iVar59 = uVar62 * 4;
              uVar62 = uVar62 + 4;
              uVar71 = (SInt32)puVar65 +
                       M<SInt32>(M<SInt32>(self + 200) + 0x8a4) + M<SInt32>(self + 0xd0) +
                       (iVar59 - (M<SInt32>(self + 0xe0) + 0x20)) + 0x20;
            }
            else {
              uVar71 = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(local_374 + uVar37 * 4)),uVar71);
            }
            puVar65[uVar64 + 1] = uVar71;
            uVar64 = uVar64 + 3;
            if (!(bool)(bVar80 >> 1 & 1)) {
              uVar37 = uVar37 + 1;
            }
            uVar75 = uVar75 + 1;
            puVar69 = puVar69 + 3;
            pAVar77 = pAVar77 + 8;
          } while (uVar73 != uVar75);
        }
        if (uVar61 != 0) {
          iVar52 = M<SInt32>(local_374 + iVar52 * 4 + -4);
          if (M<char>(iVar52 + 0x20) == '\x06') {
            iVar52 = M<SInt32>(M<SInt32>(self + 200) + 0x8a4) + M<SInt32>(iVar52 + 0x50) +
                     M<SInt32>(M<SInt32>(iVar52 + 0x54) + 4);
          }
          else {
            iVar52 = M<SInt32>(iVar52 + 0x48);
          }
          uVar38 = puVar65[uVar58 + 2] + iVar52;
          bVar1 = (uVar38 & 2) == 0;
          in_cr0 = bVar1 << 1;
          uVar61 = puVar65[uVar58 + 3];
          if ((!bVar1) && (uVar55 == 2)) {
            uVar61 = uVar61 + 1;
          }
          uVar73 = uVar38 >> 2 & 7;
          puVar65[uVar58 + 1] = puVar65[uVar58 + 1] | uVar73 << 0x10;
          puVar65[uVar58 + 2] = uVar38 & 0xffffffe3;
          puVar65[uVar58 + 3] = uVar61 + uVar73;
        }
      }
      iVar52 = uVar63 << 2;
    }
    else if (uVar38 == 0x2a000000) {
      switch(puVar65[1]) {
      default:
        iVar59 = 1;
        break;
      case 1:
        iVar59 = 0;
        break;
      case 2:
        iVar59 = 4;
        break;
      case 3:
        iVar59 = 5;
        break;
      case 4:
        iVar59 = 6;
        break;
      case 7:
        iVar59 = 2;
        break;
      case 8:
        iVar59 = 3;
        break;
      case 10:
        iVar59 = 7;
        break;
      case 0xb:
        iVar59 = 8;
      }
      iVar48 = M<SInt32>(self + 0x3bc);
      if (iVar48 == 0) {
        iVar74 = M<SInt32>(self + 0x29c);
        iVar33 = M<SInt32>(self + 0x298);
        iVar49 = iVar74 + 1;
        pAVar77 = M<UInt8 *>(iVar59 * 4 + M<SInt32>(self + 0x290) + 0xb70);
      }
      else {
        iVar33 = 0;
        iVar74 = 0;
        iVar49 = 1;
        pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
      }
      uVar38 = 0;
      if ((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) != 0) {
        uVar38 = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
      }
      uVar73 = 0x20 / M<UInt16>(pAVar77 + 0x16);
      if (uVar73 <= uVar38) {
        uVar73 = uVar38;
      }
      uVar38 = 0x80000000;
      if ((UInt8)pAVar77[0x38] < 2) {
        uVar38 = 0;
      }
      *puVar65 = uVar38 | M<SInt32>(pAVar77 + iVar74 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar77 + 0x20)
                          + iVar33 * (M<SInt32>(pAVar77 + iVar49 * 4 + 0x40) -
                                     M<SInt32>(pAVar77 + iVar74 * 4 + 0x40)) + M<SInt32>(pAVar77 + 8)
                          >> 10 | uVar73 * M<UInt16>(pAVar77 + 0x16) * 0x10000 & 0x3fc00000 |
                          ((UInt8)pAVar77[0x38] & 1) << 0x1e;
      if (iVar48 == 0) {
        pAVar77 = *(UInt8 **)
                   ((UInt32)M<UInt16>(self + 0xac) * 4 + M<SInt32>(self + 0x290) + 0xb70);
      }
      else {
        pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
      }
      uVar38 = 0;
      bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
      in_cr0 = bVar1 << 1;
      if (!bVar1) {
        uVar38 = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
      }
      uVar73 = 0x20 / M<UInt16>(pAVar77 + 0x16);
      if (uVar73 <= uVar38) {
        uVar73 = uVar38;
      }
      uVar38 = 0x80000000;
      if ((UInt8)pAVar77[0x38] < 2) {
        uVar38 = 0;
      }
      puVar65[1] = uVar38 | M<SInt32>(pAVar77 + iVar74 * 4 + 0x40) *
                            (UInt32)M<UInt16>(pAVar77 + 0x20) +
                            iVar33 * (M<SInt32>(pAVar77 + iVar49 * 4 + 0x40) -
                                     M<SInt32>(pAVar77 + iVar74 * 4 + 0x40)) + M<SInt32>(pAVar77 + 8)
                            >> 10 | uVar73 * M<UInt16>(pAVar77 + 0x16) * 0x10000 & 0x3fc00000 |
                            ((UInt8)pAVar77[0x38] & 1) << 0x1e;
      uVar55 = M<UInt32>(self + 0x358);
      puVar65[2] = uVar55;
      puVar65[3] = M<UInt32>(self + 0x354);
      puVar65[4] = uVar55;
    }
    else if (uVar38 < 0x2a000001) {
      if (uVar38 != 0x1d000000) {
        if (uVar38 < 0x1d000001) {
          if (uVar38 != 0x17000000) {
            if (uVar38 < 0x17000001) {
              if (uVar38 == 0x4000000) {
                if (M<SInt32>(self + 0x3bc) == 0) {
                  pAVar77 = (UInt8 *)
                            ((UInt32)M<UInt16>(self + 0xac) * 0x78 + M<SInt32>(self + 0x290) + 0xa8);
                }
                else {
                  pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
                }
                uVar58 = puVar65[1];
                uVar55 = puVar65[2];
                *puVar65 = 0xc0011000;
                if ((M<UInt32>(pAVar77 + 0x28) & 0x3ff00000) == 0x3ff00000) {
                  *puVar65 = 0xc00b1000;
                }
                else {
                  uVar61 = HZMEM_GetBlockOffset
                                     ((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                      M<UInt32>(pAVar77 + 0x28),2);
                  uVar38 = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                               M<UInt32>(pAVar77 + 0x28),2);
                  bVar1 = (M<UInt32>(M<SInt32>(self + 0x290) + 0xbe8) & 0x700000) == 0;
                  in_cr0 = bVar1 << 1;
                  if ((bVar1) || (M<SInt16>(self + 0xac) != 9)) {
                    puVar65[0xc] = 0;
                  }
                  else {
                    puVar65[0xc] = 0x600;
                  }
                  puVar65[8] = uVar61;
                  iVar59 = M<SInt32>(self + 200);
                  puVar65[9] = uVar38 / (UInt32)(M<SInt32>(iVar59 + 0xb98) << 4);
                  iVar59 = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(iVar59 + 0x870)),M<UInt32>(pAVar77 + 0x28),2)
                  ;
                  if (iVar59 == 0) {
                    puVar65[0xd] = (uVar58 - 2) * 0x10000 | 0xc0001000;
                  }
                  else {
                    iVar59 = M<SInt32>(self + 200);
                    uVar15 = M<UInt16>(pAVar77 + 0x1e);
                    iVar48 = 0x10;
                    if ((M<UInt32>(iVar59 + 0xb74) & 0x10000) == 0) {
                      iVar48 = 0xc;
                    }
                    uVar38 = 0;
                    bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
                    in_cr0 = bVar1 << 1;
                    if (!bVar1) {
                      uVar38 = (UInt32)M<UInt16>(pAVar77 + 0x14) /
                               (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
                    }
                    uVar73 = 0x20 / M<UInt16>(pAVar77 + 0x16);
                    if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar38) {
                      uVar73 = uVar38;
                    }
                    iVar33 = 0x20;
                    if (M<SInt32>(iVar59 + 0xb98) == 4) {
LAB_0002c898:
                      uVar38 = iVar33 * ((SInt32)(iVar33 + uVar73 + -1) / iVar33);
                    }
                    else {
                      iVar33 = M<SInt32>(iVar59 + 0xb98) << 4;
                      in_cr0 = (iVar33 == 0) << 1;
                      uVar38 = 0;
                      if (iVar33 != 0) goto LAB_0002c898;
                    }
                    iVar59 = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(iVar59 + 0x870)),
                                                 M<UInt32>(pAVar77 + 0x28),2);
                    dVar31 = DOUBLE_0004c3b8;
                    uVar38 = (UInt32)(iVar59 << 4) / uVar38 & 0xfffffff0;
                    iStack_1b4 = uVar15 + uVar38;
                    puVar65[uVar55 + 1] =
                         iVar48 * (uVar15 - uVar38) >> 1 | puVar65[uVar55 + 1] & 0xffff0000;
                    local_1b8 = 0x43300000;
                    puVar65[uVar55 + 7] =
                         (UInt32)(float)(((double)CONCAT44d(0x43300000,iStack_1b4) - DOUBLE_0004c3b0)
                                       * dVar31);
                  }
                  pAVar77[0x36] = 0x1;
                }
                M<UInt32>(pAVar77 + 0x30) = puVar65[6];
                iVar59 = M<SInt32>(self);
LAB_0002cd2c:
                VCALL(iVar59, 0x5a4)(self);
              }
              else if (uVar38 < 0x4000001) {
                if (uVar38 == 0x2000000) {
                  local_cc = 3;
                }
                else if (uVar38 == 0x3000000) {
                  local_cc = 2;
                }
              }
              else {
                if (uVar38 == 0x5000000) {
                  pAVar77 = self + 0x5a0;
                  if (M<SInt32>(self + 0x3bc) == 0) {
                    pAVar77 = (UInt8 *)
                              ((UInt32)M<UInt16>(self + 0xae) * 0x78 + M<SInt32>(self + 0x290) + 0xa8
                              );
                  }
                  uVar55 = M<UInt32>(pAVar77 + 0x28);
                  uVar58 = puVar65[1];
                  uVar64 = puVar65[2];
                  uVar61 = puVar65[3];
                  uVar62 = puVar65[5];
                  if (((uVar55 & 0x3ff) == 0x3ff) || ((uVar55 & 0xffc00) == 0xffc00)) {
                    *puVar65 = (puVar65[4] - 2) * 0x10000 | 0xc0001000;
                    pAVar77[0x35] = 0x0;
                    pAVar77[0x34] = 0x0;
                  }
                  else {
                    *puVar65 = 0xc0041000;
                    uVar55 = HZMEM_GetBlockOffset
                                       ((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),uVar55,0);
                    uVar38 = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                                 M<UInt32>(pAVar77 + 0x28),0);
                    iVar59 = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                             M<UInt32>(pAVar77 + 0x28),0);
                    uVar71 = HZMEM_GetBlockOffset
                                       ((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                        M<UInt32>(pAVar77 + 0x28),1);
                    uVar73 = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                                 M<UInt32>(pAVar77 + 0x28),1);
                    iVar48 = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                             M<UInt32>(pAVar77 + 0x28),1);
                    iVar33 = M<SInt32>(M<SInt32>(self + 200) + 0xb98) *
                             M<SInt32>(M<SInt32>(self + 200) + 0xb9c);
                    puVar65[9] = uVar55;
                    puVar65[10] = uVar38 / (UInt32)(iVar33 * 0x10);
                    pAVar77[0x34] = 0x1;
                    if (uVar58 == 0) {
                      pAVar77[0x35] = 0x0;
                    }
                    else if ((M<UInt32>(pAVar77 + 0x28) & 0xffc00) == 0xffc00) {
                      M<UInt32>((SInt32)puVar65 + uVar64) = 0xc0021000;
                      pAVar77[0x35] = 0x0;
                    }
                    else {
                      puVar65[uVar64 + 1] = uVar71;
                      puVar65[uVar64 + 2] = uVar73 / (UInt32)(iVar33 * 4);
                      pAVar77[0x35] = 0x1;
                    }
                    if ((iVar59 == 0) && (iVar48 == 0)) {
                      puVar65[uVar62 + 1] = puVar65[uVar62 + 1] & 0xffff0000;
                    }
                    else {
                      uVar75 = 0;
                      iVar48 = M<SInt32>(M<SInt32>(self + 200) + 0xb98);
                      iVar59 = (UInt32)M<UInt16>(self + 0xae) * 0x78 + M<SInt32>(self + 0x290);
                      if ((M<UInt32>(iVar59 + 0xe4) & 0xf00000) != 0) {
                        uVar75 = (UInt32)M<UInt16>(iVar59 + 0xbc) /
                                 (M<UInt32>(iVar59 + 0xe4) >> 0x14 & 0xf);
                      }
                      uVar37 = 0x20 / M<UInt16>(iVar59 + 0xbe);
                      if (uVar37 <= uVar75) {
                        uVar37 = uVar75;
                      }
                      if (iVar48 == 4) {
                        iVar59 = 0x20;
LAB_0002cb94:
                        uVar75 = iVar59 * ((SInt32)(iVar59 + uVar37 + -1) / iVar59);
                      }
                      else {
                        iVar59 = iVar48 << 4;
                        uVar75 = 0;
                        if (iVar59 != 0) goto LAB_0002cb94;
                      }
                      uVar53 = (UInt32)M<UInt16>(pAVar77 + 0x1e);
                      uVar37 = M<UInt32>(M<SInt32>(self + 200) + 0xb74) >> 4 & 3;
                      iVar59 = uVar37 * 0x10;
                      iVar33 = iVar59;
                      if (iVar48 == 4) {
                        iVar33 = uVar37 << 5;
                      }
                      if (uVar73 < uVar38) {
                        uVar38 = uVar73;
                      }
                      uVar73 = 0;
                      if (uVar75 != 0) {
                        uVar73 = (uVar38 * iVar59) / uVar75 & -iVar33;
                      }
                      uVar38 = 0;
                      if (uVar53 != 0) {
                        uVar38 = ((puVar65[uVar62 + 1] & 0xffff) / uVar53) * (uVar53 - uVar73);
                      }
                      local_378 = (UInt8 *)0x0;
                      bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf000) == 0;
                      in_cr0 = bVar1 << 1;
                      if (!bVar1) {
                        iStack_1ac = uVar73 + uVar53;
                        local_1b0 = 0x43300000;
                        local_1a8 = 0x43300000;
                        uStack_1a4 = M<UInt32>(pAVar77 + 0x3c) >> 0xc & 0xf ^ 0x80000000;
                        fVar4 = (float)((double)CONCAT44d(0x43300000,uStack_1a4) - DOUBLE_0004c3a8);
                        local_378 = (UInt8 *)FBITS((float)((double)CONCAT44d(0x43300000,iStack_1ac) - DOUBLE_0004c3b0) / (fVar4 + fVar4));   /* a float kept in a pointer-typed stack slot */
                      }
                      puVar65[uVar62 + 1] = uVar38 | puVar65[uVar62 + 1] & 0xffff0000;
                      puVar65[uVar62 + 7] = (UInt32)local_378;
                    }
                  }
                  M<UInt32>(pAVar77 + 0x2c) = puVar65[uVar61];
                  if ((M<SInt32>(self + 0x3bc) != 0) && (M<SInt32>(self + 0x348) != 0)) {
                    M<UInt32>(M<SInt32>(self + 0x348) + 0x7c) = puVar65[uVar61];
                    M<UInt16>(M<SInt32>(self + 0x348) + 0x7a) =
                         CONCAT11(pAVar77[0x35],pAVar77[0x34]);
                  }
                  iVar59 = M<SInt32>(self);
                  goto LAB_0002cd2c;
                }
                if (uVar38 == 0x16000000) goto LAB_0002e820;
              }
              goto LAB_00031340;
            }
            if (uVar38 != 0x1a000000) {
              if (uVar38 < 0x1a000001) {
                if ((uVar38 == 0x18000000) || (uVar38 == 0x19000000)) goto LAB_0002e820;
              }
              else if ((uVar38 == 0x1b000000) || (uVar38 == 0x1c000000)) goto LAB_0002e820;
              goto LAB_00031340;
            }
          }
        }
        else if (uVar38 != 0x23000000) {
          if (0x23000000 < uVar38) {
            if (uVar38 == 0x26000000) {
              if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar65[1]) ||
                 (pVVar70 = *(UInt8 **)
                             (puVar65[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                 pVVar70 == (UInt8 *)0x0)) goto LAB_00030d40;
              pVVar51 = M<UInt8 *>(self + 0x328);
              local_378 = pVVar70;
              if (pVVar51 != pVVar70) {
                if (pVVar51 != (UInt8 *)0x0) {
                  M<UInt32>(M<SInt32>(pVVar51 + 0x14) + 8) =
                       M<UInt32>(M<SInt32>(self + 200) + 0x50);
                  M<SInt16>(M<SInt32>(self + 0x328) + 0xe) =
                       M<SInt16>(M<SInt32>(self + 0x328) + 0xe) + -1;
                }
                M<SInt16>(pVVar70 + 0xe) = M<SInt16>(pVVar70 + 0xe) + 1;
                M<UInt8 *>(self + 0x328) = pVVar70;
              }
              if (M<SInt32>(pVVar70 + 4) == 0) {
                if (local_384 != 0) {
                  uVar38 = puVar65[-1] >> 2;
                  if (4 < uVar38) {
                    uVar73 = 0x80000000;
                    if (uVar38 != 5) {
                      uVar73 = (uVar38 - 6) * 0x10000 | 0xc0001000;
                    }
                    puVar65[-uVar38] = uVar73;
                  }
                  puVar65[-4] = 0x1393;
                  puVar65[-3] = 0;
                  puVar65[-2] = 0x5c8;
                  puVar65[-1] = 0x20000;
                  M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                       local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
                  M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
                  uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) +
                                               0x20),local_388 + M<SInt32>(self + 0xd0) + 0x20,
                                      local_384);
                  uVar55 = local_384;
                  M<UInt32>(self + 0xdc) = uVar40;
                  local_380 = 0;
                  local_384 = 0;
                  local_388 = uVar55 * 4 + local_388;
                }
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)local_378));
                if (M<SInt32>(self + 0xd0) == 0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
                }
              }
              *puVar65 = 0x80000000;
              puVar65[1] = 0x80000000;
              puVar65[5] = M<SInt32>(local_378 + 4) + M<SInt32>(M<SInt32>(self + 200) + 0x8a4) +
                           puVar65[5] + 0x80;
            }
            else if (uVar38 < 0x26000001) {
              if ((uVar38 == 0x24000000) || (uVar38 == 0x25000000)) goto LAB_0002e820;
            }
            else if (uVar38 == 0x28000000) {
              if (M<SInt32>(self + 0x3bc) == 0) {
                iVar33 = M<SInt32>(self + 0x29c);
                iVar59 = M<SInt32>(self + 0x298);
                iVar48 = iVar33 + 1;
                pAVar77 = *(UInt8 **)
                           ((UInt32)M<UInt16>(self + 0xac) * 4 + M<SInt32>(self + 0x290) + 0xb70);
              }
              else {
                iVar59 = 0;
                iVar33 = 0;
                iVar48 = 1;
                pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
              }
              *puVar65 = 0x105bb;
              puVar65[1] = M<UInt32>(self + 0x354);
              puVar65[2] = M<UInt32>(self + 0x358);
              uVar38 = 0;
              iVar33 = M<SInt32>(pAVar77 + iVar33 * 4 + 0x40);
              iVar74 = M<SInt32>(pAVar77 + iVar48 * 4 + 0x40);
              uVar15 = M<UInt16>(pAVar77 + 0x20);
              iVar48 = M<SInt32>(pAVar77 + 8);
              bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                uVar38 = (UInt32)M<UInt16>(pAVar77 + 0x14) /
                         (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
              }
              uVar14 = M<UInt16>(pAVar77 + 0x16);
              uVar73 = 0x20 / uVar14;
              if (uVar73 <= uVar38) {
                uVar73 = uVar38;
              }
              AVar10 = pAVar77[0x38];
              uVar38 = 0x80000000;
              if ((UInt8)AVar10 < 2) {
                uVar38 = 0;
              }
              puVar65[3] = 0x50b;
              puVar65[4] = uVar38 | iVar33 * (UInt32)uVar15 + iVar59 * (iVar74 - iVar33) + iVar48 >>
                                    10 | uVar73 * uVar14 * 0x10000 & 0x3fc00000 |
                                    ((UInt8)AVar10 & 1) << 0x1e;
            }
            else if (uVar38 == 0x29000000) {
              if (M<SInt32>(self + 0x3bc) != 0) {
                M<UInt32>(self + 0x3bc) = 0;
              }
              uVar38 = 0;
              iVar59 = 4;
              M<UInt16>(self + 0x3a8) = 0;
              pAVar77 = self;
              puVar69 = puVar65;
              do {
                switch(puVar69[1]) {
                case 0:
                  uVar73 = uVar38 & 0xffff;
                  uVar38 = uVar73 + 1;
                  M<SInt16>(self + 0x3a8) = (SInt16)uVar38;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 1;
                  break;
                case 1:
                  uVar73 = uVar38 & 0xffff;
                  uVar38 = uVar73 + 1;
                  M<SInt16>(self + 0x3a8) = (SInt16)uVar38;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 0;
                  break;
                case 2:
                  uVar73 = uVar38 & 0xffff;
                  uVar38 = uVar73 + 1;
                  M<SInt16>(self + 0x3a8) = (SInt16)uVar38;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 4;
                  break;
                case 3:
                  uVar73 = uVar38 & 0xffff;
                  uVar38 = uVar73 + 1;
                  M<SInt16>(self + 0x3a8) = (SInt16)uVar38;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 5;
                  break;
                case 7:
                  uVar73 = uVar38 & 0xffff;
                  uVar38 = uVar73 + 1;
                  M<SInt16>(self + 0x3a8) = (SInt16)uVar38;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 2;
                  break;
                case 8:
                  uVar73 = uVar38 & 0xffff;
                  uVar38 = uVar73 + 1;
                  M<SInt16>(self + 0x3a8) = (SInt16)uVar38;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 3;
                  break;
                case 0x10:
                  uVar73 = uVar38 & 0xffff;
                  uVar38 = uVar73 + 1;
                  M<SInt16>(self + 0x3a8) = (SInt16)uVar38;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 9;
                  break;
                case 0x11:
                  M<UInt16>(pAVar77 + 0x3aa) = 0x17;
                }
                iVar59 = iVar59 + -1;
                puVar69 = puVar69 + 1;
                pAVar77 = pAVar77 + 2;
              } while (iVar59 != 0);
              if ((uVar38 & 0xffff) == 0) {
                M<UInt16>(self + 0x3a8) = 1;
                M<UInt16>(self + 0x3aa) = 1;
              }
              M<UInt16>(self + 0xac) = M<UInt16>(self + 0x3aa);
              M<UInt32>(self + 0x35c) = (UInt32)M<UInt16>(self + 0x3aa);
              if (puVar65[5] == 0x10) {
                M<UInt16>(self + 0x3aa) = 9;
                M<UInt16>(self + 0xac) = 9;
              }
              bVar1 = (M<UInt32>(self + 0x8c) & 0x80) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                uVar55 = puVar65[1];
                if ((uVar55 == 7) || (uVar55 == 8)) {
                  M<SInt16>(self + 0xae) = (SInt16)uVar55;
                }
                else {
                  M<UInt16>(self + 0xae) = 6;
                }
              }
              VCALL(M<SInt32>(self), 0x5a4)(self);
              this->build_scissor();
              this->write_kernel_context_buffer_regs((UInt32 *)(puVar65),0,puVar65[6],puVar65[7]);
            }
            else if (uVar38 == 0x27000000) {
              if (M<SInt32>(self + 0x328) != 0) {
                M<UInt32>(M<SInt32>(M<SInt32>(self + 0x328) + 0x14) + 8) =
                     M<UInt32>(M<SInt32>(self + 200) + 0x50);
                M<SInt16>(M<SInt32>(self + 0x328) + 0xe) =
                     M<SInt16>(M<SInt32>(self + 0x328) + 0xe) + -1;
                M<UInt32>(self + 0x328) = 0;
              }
              goto LAB_0002eae8;
            }
            goto LAB_00031340;
          }
          if (uVar38 != 0x20000000) {
            if (uVar38 < 0x20000001) {
              if ((uVar38 == 0x1e000000) || (uVar38 == 0x1f000000)) goto LAB_0002e820;
            }
            else if ((uVar38 == 0x21000000) || (uVar38 == 0x22000000)) goto LAB_0002e820;
            goto LAB_00031340;
          }
        }
      }
LAB_0002e820:
      uVar38 = uVar38 + 0xea000000 >> 0x16;
      if (M<UInt8 *>(self + uVar38 + 0x2a4) != (UInt8 *)0x0) {
        ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + uVar38 + 0x2a4)));
        pVVar70 = M<UInt8 *>(self + uVar38 + 0x2a4);
        piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
        iVar59 = atomicAddReturningOld((SInt32 *)piVar36, -1);
        if (iVar59 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
        }
        M<UInt32>(self + uVar38 + 0x2a4) = 0;
      }
LAB_0002eae8:
      *puVar65 = 0x80000000;
    }
    else {
      if (uVar38 == 0x37000000) {
        iVar59 = M<SInt32>(self + 0x2a4);
        if (iVar59 != 0) {
          if (M<char>(iVar59 + 0x20) == '\0') {
            pIVar66 = M<UInt8 *>(iVar59 + 0x50);
            if (pIVar66 == (UInt8 *)0x0) goto LAB_0002f978;
            iVar59 = ((IOATIR500Surface *)(pIVar66))->surface_buffer_idx_mask(M<UInt32>(iVar59 + 0x58),(UInt32 *)&local_378);
            bVar1 = true;
            iVar48 = M<SInt32>(pIVar66 + iVar59 * 4 + 0xb70);
            iVar59 = M<SInt32>(iVar48 + 8);
          }
          else {
            iVar59 = M<SInt32>(iVar59 + 0x48);
            bVar1 = false;
            iVar48 = 0;
          }
          if (iVar59 != 0) {
            uVar73 = puVar65[3] & 0xffff;
            uVar38 = puVar65[3] >> 0x10;
            puVar67 = puVar65 + uVar73;
            uVar75 = puVar65[2];
            *puVar65 = (uVar38 + uVar73 + 2) * 0x10000 | 0xc0001000;
            puVar67[uVar38 + 0xf] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
            puVar69 = puVar65;
            if (bVar1) {
              for (; uVar73 != 0; uVar73 = uVar73 - 1) {
                uVar55 = puVar69[4];
                uVar37 = 0;
                uVar75 = puVar65[uVar55];
                iVar33 = (uVar75 & 0xffff) * 4 + iVar48;
                iVar59 = M<SInt32>(iVar33 + 0x40);
                puVar65[uVar55] =
                     iVar59 * (UInt32)M<UInt16>(iVar48 + 0x20) +
                     (uVar75 >> 0x10) * (M<SInt32>(iVar33 + 0x44) - iVar59) + M<SInt32>(iVar48 + 8);
                bVar1 = (M<UInt32>(iVar48 + 0x3c) & 0xf00000) == 0;
                in_cr0 = bVar1 << 1;
                iVar59 = (UInt32)M<UInt8>(iVar48 + 0x3a) * 0x1c;
                if (!bVar1) {
                  uVar37 = (SInt32)((UInt32)M<UInt16>(iVar48 + 0x14) /
                                (M<UInt32>(iVar48 + 0x3c) >> 0x14 & 0xf)) >> (uVar75 & 0x3f);
                }
                uVar75 = 0x20 / M<UInt16>(iVar48 + 0x16);
                if (uVar75 <= uVar37) {
                  uVar75 = uVar37;
                }
                local_c8 = FormatTableLookup_0x0004d2e0(iVar59) >> 1 & 0x1e00000 |
                           (FormatTableLookup_0x0004d2dc(iVar59) & 0xc00) << 9 |
                           (M<UInt8>(iVar48 + 0x38) & 6) << 0x10 |
                           (M<UInt8>(iVar48 + 0x38) & 1) << 0x10 |
                           uVar75 & 0x3ffe | local_c8 & 0xfe00c001;
                puVar65[uVar55 + 2] = local_c8;
                puVar69 = puVar69 + 1;
              }
              for (; uVar38 != 0; uVar38 = uVar38 - 1) {
                puVar69 = puVar67 + 4;
                puVar67 = puVar67 + 1;
                iVar33 = (puVar65[*puVar69] & 0xffff) * 4 + iVar48;
                iVar59 = M<SInt32>(iVar33 + 0x40);
                puVar65[*puVar69] =
                     M<UInt8>(M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14) + 0x15) & 0x1f |
                     iVar59 * (UInt32)M<UInt16>(iVar48 + 0x20) +
                     (puVar65[*puVar69] >> 0x10) * (M<SInt32>(iVar33 + 0x44) - iVar59) +
                     M<SInt32>(iVar48 + 8) & 0xffffffe0;
              }
            }
            else {
              iVar59 = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + 0x2a4)),true);
              for (; uVar73 != 0; uVar73 = uVar73 - 1) {
                puVar3 = puVar69 + 4;
                puVar69 = puVar69 + 1;
                puVar65[*puVar3] = iVar59 + puVar65[*puVar3];
              }
              for (; uVar38 != 0; uVar38 = uVar38 - 1) {
                puVar69 = puVar67 + 4;
                puVar67 = puVar67 + 1;
                puVar65[*puVar69] =
                     M<UInt8>(M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14) + 0x15) & 0x1f |
                     iVar59 + puVar65[*puVar69] & 0xffffffe0;
              }
              iVar59 = (uVar75 >> 0x10) * 2;
              iVar48 = iVar59 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
              uVar15 = (UInt16)((1 << (uVar75 & 0x3f)) + -1 << (uVar75 >> 8 & 0x3f));
              M<UInt16>(iVar48 + 0x28) = uVar15 | M<UInt16>(iVar48 + 0x28);
              iVar59 = iVar59 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
              M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~uVar15;
              M<UInt32>(M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14) + 0xc) =
                   M<UInt32>(M<SInt32>(self + 200) + 0x50);
            }
            goto LAB_00031340;
          }
        }
LAB_0002f978:
        *puVar65 = (puVar65[1] - 2) * 0x10000 | 0xc0001000;
        goto LAB_00031340;
      }
      if (0x37000000 < uVar38) {
        if (uVar38 == 0x3f000000) {
          uVar55 = puVar65[3];
          if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar65[2]) ||
             (pVVar70 = *(UInt8 **)
                         (puVar65[2] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
             pVVar70 == (UInt8 *)0x0)) goto LAB_00030fe0;
          local_378 = pVVar70;
          ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(pVVar70));
          if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
            if (local_384 != 0) {
              uVar38 = puVar65[-1] >> 2;
              if (4 < uVar38) {
                uVar73 = 0x80000000;
                if (uVar38 != 5) {
                  uVar73 = (uVar38 - 6) * 0x10000 | 0xc0001000;
                }
                puVar65[-uVar38] = uVar73;
              }
              puVar65[-4] = 0x1393;
              puVar65[-3] = 0;
              puVar65[-2] = 0x5c8;
              puVar65[-1] = 0x20000;
              M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                   local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
              uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) + 0x20)
                                  ,local_388 + M<SInt32>(self + 0xd0) + 0x20,local_384);
              uVar58 = local_384;
              M<UInt32>(self + 0xdc) = uVar40;
              local_384 = 0;
              local_388 = uVar58 * 4 + local_388;
            }
            this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
            if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
              local_1bc = puVar65;
              this->restore_state_destroyed_by_pageoff((register_tracking_state *)(arStack_2fc));
            }
            if (M<SInt32>(self + 0xd0) == 0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
            }
          }
          *puVar65 = 0xc0021000;
          puVar65[0xf] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
          if (M<SInt32>(self + 0x3bc) == 0) {
            pAVar77 = *(UInt8 **)
                       (M<SInt32>(self + 0x35c) * 4 + M<SInt32>(self + 0x290) + 0xb70);
          }
          else {
            pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
          }
          uVar38 = 0;
          iVar59 = (UInt32)(UInt8)pAVar77[0x3a] * 0x1c;
          puVar65[0x9e] =
               (UInt32)M<UInt16>(pAVar77 + 0x20) * M<SInt32>(pAVar77 + 0x40) + M<SInt32>(pAVar77 + 8)
               & 0xffffffe0;
          if ((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) != 0) {
            uVar38 = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
          }
          uVar73 = 0x20 / M<UInt16>(pAVar77 + 0x16);
          if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar38) {
            uVar73 = uVar38;
          }
          uVar53 = puVar65[0x8e];
          puVar65[0xa0] =
               uVar73 & 0x3ffe | ((UInt8)pAVar77[0x38] & 1) << 0x10 |
               ((UInt8)pAVar77[0x38] & 6) << 0x10 | ((UInt8)pAVar77[0x39] & 3) << 0x13 |
               FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar77[0x3a] * 0x1c) >> 1 & 0x1e00000;
          uVar38 = FormatTableLookup_0x0004d2e0(iVar59) >> 0x11 & 0x1f;
          puVar65[0x8e] = uVar38 | uVar53 & 0xffffffe0;
          uVar73 = FormatTableLookup_0x0004d2e0(iVar59) >> 7 & 0x300;
          puVar65[0x8e] = uVar73 | uVar38 | uVar53 & 0xfffffce0;
          uVar75 = FormatTableLookup_0x0004d2e0(iVar59) >> 3 & 0xc00;
          puVar65[0x8e] = uVar75 | uVar73 | uVar38 | uVar53 & 0xfffff0e0;
          uVar37 = (FormatTableLookup_0x0004d2e0(iVar59) & 0x1800) << 1;
          puVar65[0x8e] = uVar37 | uVar75 | uVar73 | uVar38 | uVar53 & 0xffffc0e0;
          puVar65[0x8e] =
               (FormatTableLookup_0x0004d2e0(iVar59) & 0x600) << 5 |
               uVar37 | uVar75 | uVar73 | uVar38 | uVar53 & 0xffff00e0;
          bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
          in_cr0 = bVar1 << 1;
          if ((bVar1) ||
             (uVar73 = (UInt32)M<UInt16>(pAVar77 + 0x1c) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)
             , uVar38 = uVar73 - 1, uVar73 == 0)) {
            uVar38 = 0;
          }
          uVar73 = 0;
          if (M<UInt16>(pAVar77 + 0x1e) != 0) {
            uVar73 = M<UInt16>(pAVar77 + 0x1e) - 1;
          }
          puVar65[0xb7] = uVar38 & 0x1fff | (uVar73 & 0x1fff) << 0xd;
          iVar59 = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
          puVar65[0xa4] =
               iVar59 + (puVar65[0xa4] >> 3 & 0x1ffffffc) & 0xffffffe0 | puVar65[0xa4] & 0x1f;
LAB_00030964:
          ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(local_378));
          piVar36 = (SInt32 *)(M<SInt32>(local_378 + 0x14) + 0x10);
          iVar59 = atomicAddReturningOld((SInt32 *)piVar36, -0x10000);
          if (iVar59 == 1) {
LAB_00030994:
            ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(local_378));
          }
          goto LAB_00031340;
        }
        if (uVar38 < 0x3f000001) {
          if (uVar38 == 0x3b000000) {
            uVar55 = puVar65[2];
            uVar58 = puVar65[3];
            uVar38 = M<UInt32>(M<SInt32>(self + 200) + 0xb98);
            if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar65[1]) ||
               (pVVar70 = *(UInt8 **)
                           (puVar65[1] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
               pVVar70 == (UInt8 *)0x0)) goto LAB_00030fe0;
            local_378 = pVVar70;
            if (M<UInt8 *>(self + 0x32c) != (UInt8 *)0x0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + 0x32c)));
              pVVar70 = M<UInt8 *>(self + 0x32c);
              piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
              iVar59 = atomicAddReturningOld((SInt32 *)piVar36, -1);
              if (iVar59 == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
              }
            }
            ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(local_378));
            if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
              if (local_384 != 0) {
                uVar73 = puVar65[-1] >> 2;
                if (4 < uVar73) {
                  uVar75 = 0x80000000;
                  if (uVar73 != 5) {
                    uVar75 = (uVar73 - 6) * 0x10000 | 0xc0001000;
                  }
                  puVar65[-uVar73] = uVar75;
                }
                puVar65[-4] = 0x1393;
                puVar65[-3] = 0;
                puVar65[-2] = 0x5c8;
                puVar65[-1] = 0x20000;
                M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                     local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
                uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) +
                                             0x20),local_388 + M<SInt32>(self + 0xd0) + 0x20,
                                    local_384);
                uVar61 = local_384;
                M<UInt32>(self + 0xdc) = uVar40;
                local_384 = 0;
                local_388 = uVar61 * 4 + local_388;
              }
              this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
              if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
                local_1bc = puVar65;
                this->restore_state_destroyed_by_pageoff((register_tracking_state *)(arStack_2fc));
              }
              if (M<SInt32>(self + 0xd0) == 0) {
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
              }
            }
            pVVar70 = local_378;
            uVar55 = this->GetQueryOffset((VendorTextureBuffer *)(local_378),uVar58,uVar55);
            *puVar65 = 0x80000000;
            puVar65[1] = 0x80000000;
            puVar65[2] = 0x80000000;
            puVar65[3] = 0x80000000;
            if ((uVar38 == 1) && (M<SInt32>(M<SInt32>(self + 200) + 0xb9c) == 2)) {
              puVar65[9] = uVar55;
              puVar65[0xd] = uVar55 + 0x10;
            }
            else {
              puVar65[7] = uVar55;
              if (1 < uVar38) {
                puVar65[0xb] = uVar55 + 0x10;
              }
              if (2 < uVar38) {
                puVar65[0xf] = uVar55 + 8;
              }
              if (3 < uVar38) {
                puVar65[0x13] = uVar55 + 0xc;
              }
            }
            piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
            atomicAddReturningOld((SInt32 *)piVar36, -0xffff);
            if (M<SInt32>(pVVar70 + 0x48) != 0) {
              M<UInt32>(M<SInt32>(pVVar70 + 0x24) + 0x28) = M<UInt32>(pVVar70 + 0x28);
              M<UInt32>(M<SInt32>(local_378 + 0x28) + 0x24) = M<UInt32>(local_378 + 0x24)
              ;
              M<UInt32>(local_378 + 0x24) = M<UInt32>(M<SInt32>(self + 200) + 0x600);
              M<SInt32>(local_378 + 0x28) = M<SInt32>(self + 200) + 0x5dc;
              M<UInt8 *>(M<SInt32>(self + 200) + 0x600) = local_378;
              M<UInt8 *>(M<SInt32>(local_378 + 0x24) + 0x28) = local_378;
              pVVar70 = local_378;
            }
            M<UInt8 *>(self + 0x32c) = pVVar70;
          }
          else if (uVar38 < 0x3b000001) {
            if (uVar38 == 0x38000000) {
              uVar38 = puVar65[1] + 1 >> 1;
              *puVar65 = 0x80000000;
              puVar65[1] = 0x80000000;
              puVar65[2] = 0x80000000;
              puVar65[3] = 0x80000000;
              iVar59 = M<SInt32>(M<SInt32>(self + 200) + 0x8a4) + M<SInt32>(self + 0xd0) +
                       (puVar65[2] * 4 - (M<SInt32>(self + 0xe0) + 0x20)) + 0x20;
              if (uVar38 != 0) {
                iVar48 = 6;
                iVar33 = 0x1c;
                puVar69 = puVar65;
                do {
                  puVar65[iVar48] = (SInt32)puVar65 + puVar69[6] * 4 + iVar59;
                  M<UInt32>((SInt32)puVar65 + iVar33) = (SInt32)puVar65 + puVar69[7] * 4 + iVar59;
                  puVar69 = puVar69 + 3;
                  iVar48 = iVar48 + 3;
                  iVar33 = iVar33 + 0xc;
                  uVar38 = uVar38 - 1;
                } while (uVar38 != 0);
              }
            }
            else if (uVar38 == 0x3a000000) {
              pAVar77 = self;
              do {
                if (M<UInt8 *>(pAVar77 + 0x2e4) != (UInt8 *)0x0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(pAVar77 + 0x2e4)));
                  pVVar70 = M<UInt8 *>(pAVar77 + 0x2e4);
                  piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
                  iVar59 = atomicAddReturningOld((SInt32 *)piVar36, -1);
                  if (iVar59 == 1) {
                    ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
                  }
                  M<UInt32>(pAVar77 + 0x2e4) = 0;
                }
                pAVar77 = pAVar77 + 4;
              } while (self + 0x44 != pAVar77);
              goto LAB_0002eae8;
            }
          }
          else if (uVar38 == 0x3d000000) {
            if (puVar65[1] == 0x132) {
              uVar55 = puVar65[2];
              *puVar65 = 0x80000000;
              puVar65[1] = 0x80000000;
              puVar65[2] = 0x80000000;
              puVar65[3] = 0x80000000;
              if (M<UInt8 *>(self + 0x290) != (UInt8 *)0x0) {
                ((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)))->set_volatile_state((eSurfaceVolatileState)(uVar55));
              }
            }
            else {
              *puVar65 = 0x80000000;
              puVar65[1] = 0x80000000;
            }
          }
          else if (uVar38 == 0x3e000000) {
            iVar59 = M<SInt32>(self + 0x2a4);
            if ((iVar59 != 0) &&
               ((M<char>(iVar59 + 0x20) == '\x06' || (M<SInt32>(iVar59 + 0x48) != 0)))) {
              uVar38 = puVar65[4];
              uVar55 = puVar65[3];
              if ((puVar65[2] < M<UInt32>(M<SInt32>(self + 0x88) + 0x14)) &&
                 (pVVar70 = *(UInt8 **)
                             (puVar65[2] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                 pVVar70 != (UInt8 *)0x0)) {
                local_378 = pVVar70;
                ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(pVVar70));
                if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
                  if (local_384 != 0) {
                    uVar73 = puVar65[-1] >> 2;
                    if (4 < uVar73) {
                      uVar75 = 0x80000000;
                      if (uVar73 != 5) {
                        uVar75 = (uVar73 - 6) * 0x10000 | 0xc0001000;
                      }
                      puVar65[-uVar73] = uVar75;
                    }
                    puVar65[-4] = 0x1393;
                    puVar65[-3] = 0;
                    puVar65[-2] = 0x5c8;
                    puVar65[-1] = 0x20000;
                    M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                         local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
                    uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) +
                                                 0x20),local_388 + M<SInt32>(self + 0xd0) + 0x20,
                                        local_384);
                    uVar58 = local_384;
                    M<UInt32>(self + 0xdc) = uVar40;
                    local_384 = 0;
                    local_388 = uVar58 * 4 + local_388;
                  }
                  this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
                  if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
                    local_1bc = puVar65;
                    this->restore_state_destroyed_by_pageoff((register_tracking_state *)(arStack_2fc));
                  }
                  if (M<SInt32>(self + 0xd0) == 0) {
                    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
                  }
                }
                iVar59 = (uVar38 >> 0x10) * 2;
                uVar15 = (UInt16)(1 << (uVar38 & 0x3f));
                iVar48 = iVar59 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
                M<UInt16>(iVar48 + 0x28) = uVar15 | M<UInt16>(iVar48 + 0x28);
                iVar59 = iVar59 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
                M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~uVar15;
                *puVar65 = 0xc0031000;
                uVar58 = puVar65[0x9f];
                puVar65[0x10] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
                iVar59 = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + 0x2a4)),true);
                puVar65[0x9f] = uVar58 + iVar59;
                iVar59 = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
                puVar65[0xa5] =
                     iVar59 + (puVar65[0xa5] >> 3 & 0x1ffffffc) & 0xffffffe0 | puVar65[0xa5] & 0x1f;
                M<UInt32>(M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14) + 0xc) =
                     M<UInt32>(M<SInt32>(self + 200) + 0x50);
                goto LAB_00030318;
              }
              goto LAB_00030fe0;
            }
LAB_000300b8:
            uVar38 = 0x80000000;
            if (puVar65[1] != 1) {
              uVar38 = (puVar65[1] - 2) * 0x10000 | 0xc0001000;
            }
            *puVar65 = uVar38;
          }
        }
        else {
          if (uVar38 == 0x43000000) {
            uVar55 = puVar65[3];
            *puVar65 = 0xc0021000;
            if ((puVar65[2] < M<UInt32>(M<SInt32>(self + 0x88) + 0x14)) &&
               (pVVar70 = *(UInt8 **)
                           (puVar65[2] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
               pVVar70 != (UInt8 *)0x0)) {
              local_378 = pVVar70;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(pVVar70));
              if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
                if (local_384 != 0) {
                  uVar38 = puVar65[-1] >> 2;
                  if (4 < uVar38) {
                    uVar73 = 0x80000000;
                    if (uVar38 != 5) {
                      uVar73 = (uVar38 - 6) * 0x10000 | 0xc0001000;
                    }
                    puVar65[-uVar38] = uVar73;
                  }
                  puVar65[-4] = 0x1393;
                  puVar65[-3] = 0;
                  puVar65[-2] = 0x5c8;
                  puVar65[-1] = 0x20000;
                  M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                       local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
                  uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) +
                                               0x20),local_388 + M<SInt32>(self + 0xd0) + 0x20,
                                      local_384);
                  uVar58 = local_384;
                  M<UInt32>(self + 0xdc) = uVar40;
                  local_384 = 0;
                  local_388 = uVar58 * 4 + local_388;
                }
                this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
                if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
                  local_1bc = puVar65;
                  this->restore_state_destroyed_by_pageoff((register_tracking_state *)(arStack_2fc));
                }
                if (M<SInt32>(self + 0xd0) == 0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
                }
              }
              M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x28) =
                   M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x28) | 1;
              M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x1c) =
                   M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x1c) & 0xfffe;
              iVar59 = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
              puVar65[0x15] = iVar59 + puVar65[0x15];
              M<UInt32>(M<SInt32>(local_378 + 0x14) + 0xc) =
                   M<UInt32>(M<SInt32>(self + 200) + 0x50);
              if (local_378[0x20] == 0x7) {
                M<UInt32>(M<SInt32>(M<SInt32>(local_378 + 0x58) + 0x14) + 8) =
                     M<UInt32>(M<SInt32>(local_378 + 0x14) + 0xc);
              }
LAB_00030318:
              ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(local_378));
              piVar36 = (SInt32 *)(M<SInt32>(local_378 + 0x14) + 0x10);
              iVar59 = atomicAddReturningOld((SInt32 *)piVar36, -0x10000);
              if (iVar59 == 0x10000) goto LAB_00030994;
            }
            else {
LAB_00030fe0:
              local_384 = 0;
              uVar63 = 0;
              iVar52 = 0;
            }
            goto LAB_00031340;
          }
          if (uVar38 < 0x43000001) {
            if (uVar38 == 0x40000000) {
              uVar55 = puVar65[3];
              uVar58 = puVar65[4];
              if ((puVar65[2] < M<UInt32>(M<SInt32>(self + 0x88) + 0x14)) &&
                 (pVVar70 = *(UInt8 **)
                             (puVar65[2] * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                 pVVar70 != (UInt8 *)0x0)) {
                local_378 = pVVar70;
                ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(pVVar70));
                if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
                  if (local_384 != 0) {
                    uVar38 = puVar65[-1] >> 2;
                    if (4 < uVar38) {
                      uVar73 = 0x80000000;
                      if (uVar38 != 5) {
                        uVar73 = (uVar38 - 6) * 0x10000 | 0xc0001000;
                      }
                      puVar65[-uVar38] = uVar73;
                    }
                    puVar65[-4] = 0x1393;
                    puVar65[-3] = 0;
                    puVar65[-2] = 0x5c8;
                    puVar65[-1] = 0x20000;
                    M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                         local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
                    uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) +
                                                 0x20),local_388 + M<SInt32>(self + 0xd0) + 0x20,
                                        local_384);
                    uVar61 = local_384;
                    M<UInt32>(self + 0xdc) = uVar40;
                    local_384 = 0;
                    local_388 = uVar61 * 4 + local_388;
                  }
                  this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
                  if (M<SInt32>(self + 0xd0) == 0) {
                    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
                  }
                }
                *puVar65 = 0xc0031000;
                puVar65[0x10] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
                if (M<SInt32>(self + 0x3bc) == 0) {
                  pAVar77 = M<UInt8 *>(uVar58 * 4 + M<SInt32>(self + 0x290) + 0xb70);
                }
                else {
                  pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
                }
                AVar10 = pAVar77[0x3a];
                puVar65[0xa5] =
                     ((UInt8)pAVar77[0x38] & 7) << 2 |
                     (UInt32)M<UInt16>(pAVar77 + 0x20) * M<SInt32>(pAVar77 + 0x40) +
                     M<SInt32>(pAVar77 + 8) & 0xffffffe0;
                if (((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0) ||
                   (uVar73 = (UInt32)M<UInt16>(pAVar77 + 0x1c) /
                             (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf), uVar38 = uVar73 - 1,
                   uVar73 == 0)) {
                  uVar38 = 0;
                }
                uVar73 = 0;
                if (M<UInt16>(pAVar77 + 0x1e) != 0) {
                  uVar73 = M<UInt16>(pAVar77 + 0x1e) - 1;
                }
                puVar65[0xab] = uVar38 & 0x7ff | (uVar73 & 0x7ff) << 0xb | 0x80000000;
                uVar38 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar10 * 0x1c);
                puVar65[0xad] =
                     uVar38 >> 0x13 & 0x1f | (uVar38 & 0x40) << 0x10 | uVar38 >> 7 & 0xe00 |
                     uVar38 >> 1 & 0x7000 | (uVar38 & 0x1c00) << 5 | (uVar38 & 0x380) << 0xb;
                uVar38 = M<UInt32>(pAVar77 + 0x3c);
                bVar1 = (uVar38 & 0xf00000) == 0;
                in_cr0 = bVar1 << 1;
                if (bVar1) {
                  uVar73 = 0;
                }
                else {
                  uVar73 = (UInt32)M<UInt16>(pAVar77 + 0x14) / (uVar38 >> 0x14 & 0xf);
                }
                uVar75 = 0x20 / M<UInt16>(pAVar77 + 0x16);
                if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar73) {
                  uVar75 = uVar73;
                }
                if ((bVar1) ||
                   (uVar73 = (UInt32)M<UInt16>(pAVar77 + 0x1c) / (uVar38 >> 0x14 & 0xf),
                   uVar38 = uVar73 - 1, uVar73 == 0)) {
                  uVar38 = 0;
                }
                uVar73 = 0;
                if (M<UInt16>(pAVar77 + 0x1e) != 0) {
                  uVar73 = M<UInt16>(pAVar77 + 0x1e) - 1;
                }
                puVar65[0xaf] = uVar75 - 1 & 0x3fff | (uVar38 & 0x800) << 4 | (uVar73 & 0x800) << 5;
                iVar59 = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
                puVar65[0x9f] = iVar59 + puVar65[0x9f];
                goto LAB_00030964;
              }
              goto LAB_00030fe0;
            }
            if (uVar38 != 0x41000000) goto LAB_00031340;
            uVar55 = puVar65[1];
            iVar52 = 4;
            pAVar77 = self;
            do {
              M<UInt16>(pAVar77 + 0x3b2) = 0;
              pAVar77 = pAVar77 + 2;
              iVar52 = iVar52 + -1;
            } while (iVar52 != 0);
            uVar58 = puVar65[4];
            uVar61 = puVar65[5];
            M<UInt16>(self + 0x3a8) = 0;
            if (uVar55 == 0) {
              puVar54 = puVar65 + 6;
              iVar59 = 6;
              iVar52 = 0x18;
            }
            else {
              local_c0 = self + 0x3c0;
              uVar62 = 0;
              iVar59 = 6;
              iVar52 = 0x18;
              pAVar77 = self;
              pAVar72 = self;
              puVar42 = puVar65;
              do {
                puVar54 = puVar42 + 6;
                local_37c = (UInt8 *)0x0;
                M<SInt16>(pAVar77 + 0x3dc) = (SInt16)puVar65[2];
                M<SInt16>(pAVar77 + 0x3de) = (SInt16)puVar65[3];
                if (M<SInt32>(pAVar72 + 0x338) != 0) {
                  iVar48 = M<SInt32>(M<SInt32>(pAVar72 + 0x338) + 0x14);
                  M<SInt16>(iVar48 + 0x36) = M<SInt16>(iVar48 + 0x36) + -1;
                  ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(pAVar72 + 0x338)));
                  pVVar70 = M<UInt8 *>(pAVar72 + 0x338);
                  piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
                  iVar48 = atomicAddReturningOld((SInt32 *)piVar36, -1);
                  if (iVar48 == 1) {
                    ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
                  }
                  M<UInt32>(pAVar72 + 0x338) = 0;
                }
                uVar63 = M<UInt32>((SInt32)puVar65 + iVar52);
                if (uVar63 != 0xffffffff) {
                  uVar15 = M<UInt16>(self + 0x3a8);
                  if (uVar15 < 4) {
                    M<UInt16>(self + 0x3a8) = uVar15 + 1;
                    M<SInt16>(self + (UInt32)uVar15 * 2 + 0x3b2) = (SInt16)uVar62;
                    uVar63 = M<UInt32>((SInt32)puVar65 + iVar52);
                  }
                  if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= uVar63) ||
                     (local_37c = *(UInt8 **)
                                   (uVar63 * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                     local_37c == (UInt8 *)0x0)) {
                    uVar73 = 0;
                    local_384 = 0;
                    M<UInt32>(M<SInt32>(self + 200) + 0x50) =
                         M<SInt32>(M<SInt32>(self + 200) + 0x50) - local_380;
                    goto LAB_0002e114;
                  }
                  ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(local_37c));
                  this->get_texture((UInt32 *)(puVar65),(VendorTextureBuffer *)(local_37c),(UInt32 *)(&local_388),(UInt32 *)(&local_384),(UInt32 *)(&local_380),(register_tracking_state *)(arStack_2fc));
                  uVar63 = puVar42[10] >> 0xf & 0x1fffe;
                  uVar15 = (UInt16)(1 << (puVar42[10] & 0x3f));
                  M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) =
                       M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) + 1;
                  iVar48 = uVar63 + M<SInt32>(local_37c + 0x14);
                  M<UInt16>(iVar48 + 0x28) = uVar15 | M<UInt16>(iVar48 + 0x28);
                  iVar48 = uVar63 + M<SInt32>(local_37c + 0x14);
                  M<UInt16>(iVar48 + 0x1c) = M<UInt16>(iVar48 + 0x1c) & ~uVar15;
                  this->build_surface_from_texture((VendorTextureBuffer *)(local_37c),(ATIR500SurfaceBuffer *)((UInt8 *)local_c0),
                             M<UInt16>((SInt32)puVar65 + 10),M<UInt16>((SInt32)puVar65 + 0xe),
                             M<UInt8>((SInt32)puVar42 + 0x2f),puVar42[7],
                             M<UInt16>((SInt32)puVar42 + 0x22));
                  M<UInt8 *>(pAVar72 + 0x338) = local_37c;
                }
                uVar62 = uVar62 + 1;
                iVar59 = iVar59 + 6;
                pAVar77 = pAVar77 + 0x78;
                pAVar72 = pAVar72 + 4;
                iVar52 = iVar52 + 0x18;
                local_c0 = local_c0 + 0x78;
                puVar42 = puVar54;
              } while (uVar55 != uVar62);
              iVar52 = iVar59 * 4;
              puVar54 = puVar65 + iVar59;
            }
LAB_0002e114:
            if (M<SInt16>(self + 0x3a8) == 0) {
              M<UInt16>(self + 0x3b2) = 0;
              M<UInt16>(self + 0x3a8) = 1;
            }
            local_37c = (UInt8 *)0x0;
            M<UInt32>(self + 0x5c8) = 0xffffffff;
            if (M<SInt32>(self + 0x348) != 0) {
              iVar48 = M<SInt32>(M<SInt32>(self + 0x348) + 0x14);
              M<SInt16>(iVar48 + 0x36) = M<SInt16>(iVar48 + 0x36) + -1;
              ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + 0x348)));
              pVVar70 = M<UInt8 *>(self + 0x348);
              piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
              iVar48 = atomicAddReturningOld((SInt32 *)piVar36, -1);
              if (iVar48 == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
              }
              M<UInt32>(self + 0x348) = 0;
            }
            uVar63 = *puVar54;
            if (uVar63 != 0xffffffff) {
              if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= uVar63) ||
                 (pVVar70 = *(UInt8 **)
                             (uVar63 * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                 pVVar70 == (UInt8 *)0x0)) goto LAB_00030d40;
              local_37c = pVVar70;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(pVVar70));
              this->get_texture((UInt32 *)(puVar65),(VendorTextureBuffer *)(local_37c),(UInt32 *)(&local_388),(UInt32 *)(&local_384),(UInt32 *)(&local_380),(register_tracking_state *)(arStack_2fc));
              uVar63 = M<UInt32>((SInt32)puVar65 + iVar52 + 0x10);
              uVar38 = uVar63 >> 0xf & 0x1fffe;
              uVar15 = (UInt16)(1 << (uVar63 & 0x3f));
              M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) =
                   M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) + 1;
              iVar48 = uVar38 + M<SInt32>(local_37c + 0x14);
              M<UInt16>(iVar48 + 0x28) = uVar15 | M<UInt16>(iVar48 + 0x28);
              iVar48 = uVar38 + M<SInt32>(local_37c + 0x14);
              M<UInt16>(iVar48 + 0x1c) = M<UInt16>(iVar48 + 0x1c) & ~uVar15;
              this->build_surface_from_texture((VendorTextureBuffer *)(local_37c),(ATIR500SurfaceBuffer *)((UInt8 *)(self + 0x5a0)),
                         M<UInt16>((SInt32)puVar65 + 10),M<UInt16>((SInt32)puVar65 + 0xe),
                         M<UInt8>((SInt32)puVar65 + iVar52 + 0x17),
                         M<UInt32>((SInt32)puVar65 + iVar52 + 4),
                         M<UInt16>((SInt32)puVar65 + iVar52 + 10));
            }
            pVVar70 = local_37c;
            if (local_37c != (UInt8 *)0x0) {
              if ((M<SInt32>(local_37c + 0x6c) == -1) && (0x20 < M<UInt16>(self + 0x5bc))) {
                uVar15 = M<UInt16>(self + 0x5be);
                uVar55 = (UInt32)uVar15;
                if (0x10 < uVar55) {
                  iVar48 = 0x20;
                  iVar33 = M<SInt32>(M<SInt32>(self + 200) + 0xb98);
                  if (iVar33 == 4) {
LAB_0002e2d4:
                    uVar62 = ((SInt32)((UInt32)M<UInt16>(self + 0x5b4) + iVar48 + -1) / iVar48) *
                             iVar48;
                  }
                  else {
                    iVar48 = iVar33 << 4;
                    uVar62 = 0;
                    if (iVar48 != 0) goto LAB_0002e2d4;
                  }
                  bVar1 = (uVar15 & 0x1f) == 0;
                  in_cr0 = bVar1 << 1;
                  if (!bVar1) {
                    uVar55 = (uVar15 & 0xffffffe0) + 0x20;
                  }
                  uVar40 = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),0xffffffff,0,uVar62
                                       ,uVar55);
                  pVVar51 = local_37c;
                  M<UInt32>(pVVar70 + 0x6c) = uVar40;
                  if ((M<UInt32>(local_37c + 0x6c) & 0xffc00) == 0xffc00) {
                    iVar48 = 0x20;
                    iVar33 = M<SInt32>(M<SInt32>(self + 200) + 0xb98);
                    if (iVar33 == 4) {
LAB_0002e34c:
                      uVar55 = ((SInt32)((UInt32)M<UInt16>(self + 0x5b4) + iVar48 + -1) / iVar48) *
                               iVar48;
                    }
                    else {
                      iVar48 = iVar33 << 4;
                      uVar55 = 0;
                      if (iVar48 != 0) goto LAB_0002e34c;
                    }
                    uVar15 = M<UInt16>(self + 0x5be);
                    uVar63 = (UInt32)uVar15;
                    bVar1 = (uVar15 & 0x1f) == 0;
                    in_cr0 = bVar1 << 1;
                    if (!bVar1) {
                      uVar63 = (uVar15 & 0xffffffe0) + 0x20;
                    }
                    uVar40 = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                         M<UInt32>(local_37c + 0x6c),1,uVar55,uVar63);
                    M<UInt32>(pVVar51 + 0x6c) = uVar40;
                  }
                  M<UInt16>(local_37c + 0x70) = M<UInt16>(self + 0x5bc);
                  M<UInt16>(local_37c + 0x72) = M<UInt16>(self + 0x5be);
                  M<UInt16>(local_37c + 0x78) = M<UInt16>(self + 0x5b8);
                  M<UInt16>(local_37c + 0x7a) = 0;
                  M<UInt32>(local_37c + 0x74) = M<UInt32>((SInt32)puVar65 + iVar52 + 4);
                }
              }
              M<UInt32>(self + 0x5c8) = M<UInt32>(local_37c + 0x6c);
              self[0x5d4] = SUB21(M<UInt16>(local_37c + 0x7a),0);
              self[0x5d5] = SUB21((UInt16)M<UInt16>(local_37c + 0x7a) >> 8,0);
              uVar40 = M<UInt32>(local_37c + 0x7c);
              M<UInt8 *>(self + 0x348) = local_37c;
              M<UInt32>(self + 0x5cc) = uVar40;
            }
            local_37c = (UInt8 *)0x0;
            puVar42 = puVar65 + iVar59 + 6;
            if (puVar65[iVar59 + 6] != 0xffffffff) {
              if (M<SInt32>(self + 0x348) != 0) {
                iVar52 = M<SInt32>(M<SInt32>(self + 0x348) + 0x14);
                M<SInt16>(iVar52 + 0x36) = M<SInt16>(iVar52 + 0x36) + -1;
                ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + 0x348)));
                pVVar70 = M<UInt8 *>(self + 0x348);
                piVar36 = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
                iVar52 = atomicAddReturningOld((SInt32 *)piVar36, -1);
                if (iVar52 == 1) {
                  ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(pVVar70));
                }
                M<UInt32>(self + 0x348) = 0;
              }
              if ((M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= *puVar42) ||
                 (pVVar70 = *(UInt8 **)
                             (*puVar42 * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                 pVVar70 == (UInt8 *)0x0)) {
LAB_00030d40:
                uVar63 = 0;
                iVar52 = 0;
                M<UInt32>(M<SInt32>(self + 200) + 0x50) =
                     M<SInt32>(M<SInt32>(self + 200) + 0x50) - local_380;
                local_384 = 0;
                goto LAB_00031340;
              }
              local_37c = pVVar70;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(pVVar70));
              this->get_texture((UInt32 *)(puVar65),(VendorTextureBuffer *)(local_37c),(UInt32 *)(&local_388),(UInt32 *)(&local_384),(UInt32 *)(&local_380),(register_tracking_state *)(arStack_2fc));
              uVar63 = puVar42[4] >> 0xf & 0x1fffe;
              uVar15 = (UInt16)(1 << (puVar42[4] & 0x3f));
              M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) =
                   M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) + 1;
              iVar52 = uVar63 + M<SInt32>(local_37c + 0x14);
              M<UInt16>(iVar52 + 0x28) = uVar15 | M<UInt16>(iVar52 + 0x28);
              iVar52 = uVar63 + M<SInt32>(local_37c + 0x14);
              M<UInt16>(iVar52 + 0x1c) = M<UInt16>(iVar52 + 0x1c) & ~uVar15;
              this->build_surface_from_texture((VendorTextureBuffer *)(local_37c),(ATIR500SurfaceBuffer *)((UInt8 *)(self + 0x618)),
                         M<UInt16>((SInt32)puVar65 + 10),M<UInt16>((SInt32)puVar65 + 0xe),
                         M<UInt8>((SInt32)puVar42 + 0x17),puVar42[1],M<UInt16>((SInt32)puVar42 + 10));
              M<UInt8 *>(self + 0x348) = local_37c;
            }
            M<UInt32>(self + 0x3bc) = 1;
            this->build_scissor();
            VCALL(M<SInt32>(self), 0x5a4)(self);
            M<UInt32>(M<SInt32>(self + 200) + 0x78) = 0;
            *puVar65 = (iVar59 + 10) * 0x10000 | 0xc0001000;
            uVar63 = uVar73 & 0xffffff;
            this->write_kernel_context_buffer_regs((UInt32 *)(puVar65 + iVar59 + 0xc),0,uVar58,uVar61);
            iVar52 = uVar63 << 2;
          }
          else if (uVar38 == 0x45000000) {
            uVar38 = puVar65[3];
            uVar73 = puVar65[1];
            local_378 = (UInt8 *)0x0;
            if (uVar38 != 0xffffffff) {
              if ((uVar38 < M<UInt32>(M<SInt32>(self + 0x88) + 0x14)) &&
                 (pVVar70 = *(UInt8 **)
                             (uVar38 * 4 + M<SInt32>(M<SInt32>(self + 0x88) + 0x10)),
                 pVVar70 != (UInt8 *)0x0)) {
                local_378 = pVVar70;
                if (M<SInt32>(pVVar70 + 0x6c) != -1) {
                  this->build_surface_from_texture((VendorTextureBuffer *)(pVVar70),(ATIR500SurfaceBuffer *)(local_374),M<UInt16>(pVVar70 + 0x70),
                             M<UInt16>(pVVar70 + 0x72),M<UInt8>((SInt32)puVar65 + 0x13),
                             M<UInt32>(pVVar70 + 0x74),M<UInt16>(pVVar70 + 0x78));
                  M<UInt32>(local_374 + 0x2c) = M<UInt32>(local_378 + 0x7c);
                  uVar38 = ((ATIR500Surface *)(M<UInt8 *>(self + 0x290)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(local_374),0,(UInt32 *)(puVar65));
                  M<UInt16>(local_378 + 0x7a) = 0;
                  goto LAB_0002eed0;
                }
                uVar73 = uVar73 + puVar65[2];
                uVar38 = 0;
                goto LAB_0002eed8;
              }
              goto LAB_00030d40;
            }
            uVar38 = ((ATIR500Surface *)(M<UInt8 *>(self + 0x290)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)((UInt8 *)
                                (M<UInt8 *>(self + 0x290) +
                                (UInt32)M<UInt16>(self + 0xae) * 0x78 + 0xa8)),0,(UInt32 *)(puVar65));
LAB_0002eed0:
            if (uVar38 <= uVar73) {
LAB_0002eed8:
              if (uVar38 < uVar73) {
                uVar75 = 0x80000000;
                if (uVar73 - uVar38 != 1) {
                  uVar75 = ((uVar73 - uVar38) + -2) * 0x10000 | 0xc0001000;
                }
                puVar65[uVar38] = uVar75;
              }
            }
          }
          else if (uVar38 == 0x46000000) {
            this->process_kATIGLStreamFastClearColor((UInt32 *)(puVar65));
          }
          else if (uVar38 == 0x44000000) {
            iVar59 = M<SInt32>(self + 0x2a4);
            if ((iVar59 != 0) &&
               ((M<char>(iVar59 + 0x20) == '\x06' || (M<SInt32>(iVar59 + 0x48) != 0)))) {
              pVVar79 = (UInt8 *)puVar65[3];
              uVar38 = puVar65[2];
              uVar55 = puVar65[4];
              if ((M<SInt32>(pVVar79 + 0x48) == 0) &&
                 ((M<SInt32>(pVVar79 + 4) == 0 &&
                  (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar79)),
                  M<SInt32>(self + 0xd0) == 0)))) {
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
              }
              *puVar65 = 0xc0031000;
              uVar58 = uVar55 + M<SInt32>(pVVar79 + 0x48);
              if (M<SInt32>(pVVar79 + 0x48) == 0) {
                *puVar65 = 0xc0011000;
                puVar65[3] = 0x575;
                puVar65[4] = 2;
                uVar58 = uVar55 + M<SInt32>(pVVar79 + 4) + M<SInt32>(M<SInt32>(self + 200) + 0x8a4);
              }
              iVar59 = (uVar38 >> 0x10) * 2;
              uVar15 = (UInt16)(1 << (uVar38 & 0x3f));
              iVar48 = iVar59 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
              M<UInt16>(iVar48 + 0x28) = uVar15 | M<UInt16>(iVar48 + 0x28);
              iVar59 = iVar59 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
              M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~uVar15;
              puVar65[0x10] = uVar58;
              uVar55 = puVar65[0x16];
              iVar59 = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + 0x2a4)),true);
              puVar65[0x16] = uVar55 + iVar59;
              M<UInt32>(pVVar79 + 0x5c) = M<UInt32>(M<SInt32>(self + 200) + 0x50);
              goto LAB_0002fe70;
            }
            goto LAB_000300b8;
          }
        }
        goto LAB_00031340;
      }
      if (uVar38 == 0x31000000) {
        uVar38 = puVar65[2];
        uVar73 = puVar65[1];
        uVar55 = puVar65[3];
        if (uVar38 == 8) {
LAB_0002ef74:
          uVar38 = 8;
        }
        else {
          if (uVar38 < 9) {
            if (uVar38 == 7) {
LAB_0002ef6c:
              uVar38 = 7;
              goto LAB_0002ef48;
            }
          }
          else {
            if (uVar38 == 10) goto LAB_0002ef6c;
            if (uVar38 == 0xb) goto LAB_0002ef74;
          }
          uVar38 = 6;
        }
LAB_0002ef48:
        if ((M<UInt32>(self + 0x8c) & 0x80) == 0) {
          uVar38 = 6;
        }
        if (M<SInt32>(self + 0x3bc) == 0) {
          pAVar43 = M<UInt8 *>(self + 0x290);
          pAVar45 = M<UInt8 *>(pAVar43 + uVar38 * 4 + 0xb70);
          pAVar76 = (UInt8 *)(pAVar43 + (UInt32)M<UInt16>(self + 0xae) * 0x78 + 0xa8)
          ;
        }
        else {
          pAVar43 = M<UInt8 *>(self + 0x290);
          pAVar45 = (UInt8 *)(self + 0x5a0);
          pAVar76 = (UInt8 *)(self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0);
        }
        uVar58 = ((ATIR500Surface *)(pAVar43))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(pAVar45), 0, (UInt32 *)(puVar65));
        if (((M<SInt32>(self + 0x3bc) == 0) && (uVar38 != M<UInt16>(self + 0xae))) &&
           (pAVar76[0x34] != 0x0)) {
          uVar58 = ((ATIR500Surface *)(M<UInt8 *>(self + 0x290)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(pAVar76),uVar58,(UInt32 *)(puVar65));
        }
        pAVar76[0x35] = 0x0;
        pAVar76[0x34] = 0x0;
        if ((uVar58 <= uVar73) && (uVar58 < uVar73)) {
          uVar38 = 0x80000000;
          if (uVar73 - uVar58 != 1) {
            uVar38 = ((uVar73 - uVar58) + -2) * 0x10000 | 0xc0001000;
          }
          puVar65[uVar58] = uVar38;
        }
        uVar38 = 0;
        iVar59 = (UInt32)(UInt8)pAVar76[0x3a] * 0x1c;
        puVar65[uVar73 + 0x9a] =
             (UInt32)M<UInt16>(pAVar76 + 0x20) * M<SInt32>(pAVar76 + 0x40) + M<SInt32>(pAVar76 + 8) &
             0xffffffe0;
        if ((M<UInt32>(pAVar76 + 0x3c) & 0xf00000) != 0) {
          uVar38 = (UInt32)M<UInt16>(pAVar76 + 0x14) / (M<UInt32>(pAVar76 + 0x3c) >> 0x14 & 0xf);
        }
        uVar75 = 0x20 / M<UInt16>(pAVar76 + 0x16);
        if (0x20 / M<UInt16>(pAVar76 + 0x16) <= uVar38) {
          uVar75 = uVar38;
        }
        uVar35 = puVar65[uVar73 + 0x8a];
        puVar65[uVar73 + 0x9c] =
             uVar75 & 0x3ffe | ((UInt8)pAVar76[0x38] & 1) << 0x10 | ((UInt8)pAVar76[0x38] & 6) << 0x10
             | ((UInt8)pAVar76[0x39] & 3) << 0x13 |
             FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar76[0x3a] * 0x1c) >> 1 & 0x1e00000;
        uVar38 = FormatTableLookup_0x0004d2e0(iVar59) >> 0x11 & 0x1f;
        puVar65[uVar73 + 0x8a] = uVar38 | uVar35 & 0xffffffe0;
        uVar75 = FormatTableLookup_0x0004d2e0(iVar59) >> 7 & 0x300;
        puVar65[uVar73 + 0x8a] = uVar75 | uVar38 | uVar35 & 0xfffffce0;
        uVar37 = FormatTableLookup_0x0004d2e0(iVar59) >> 3 & 0xc00;
        puVar65[uVar73 + 0x8a] = uVar37 | uVar75 | uVar38 | uVar35 & 0xfffff0e0;
        uVar53 = (FormatTableLookup_0x0004d2e0(iVar59) & 0x1800) << 1;
        puVar65[uVar73 + 0x8a] = uVar53 | uVar37 | uVar75 | uVar38 | uVar35 & 0xffffc0e0;
        puVar65[uVar73 + 0x8a] =
             (FormatTableLookup_0x0004d2e0(iVar59) & 0x600) << 5 |
             uVar53 | uVar37 | uVar75 | uVar38 | uVar35 & 0xffff00e0;
        if (((M<UInt32>(pAVar76 + 0x3c) & 0xf00000) == 0) ||
           (uVar75 = (UInt32)M<UInt16>(pAVar76 + 0x1c) / (M<UInt32>(pAVar76 + 0x3c) >> 0x14 & 0xf),
           uVar38 = uVar75 - 1, uVar75 == 0)) {
          uVar38 = 0;
        }
        uVar75 = 0;
        if (M<UInt16>(pAVar76 + 0x1e) != 0) {
          uVar75 = M<UInt16>(pAVar76 + 0x1e) - 1;
        }
        puVar65[uVar73 + 0xb3] = uVar38 & 0x1fff | (uVar75 & 0x1fff) << 0xd;
        AVar12 = pAVar45[0x3a];
        puVar65[uVar73 + 0xa0] =
             ((UInt8)pAVar45[0x38] & 7) << 2 |
             (UInt32)M<UInt16>(pAVar45 + 0x20) * M<SInt32>(pAVar45 + 0x40) + M<SInt32>(pAVar45 + 8) &
             0xffffffe0;
        if (((M<UInt32>(pAVar45 + 0x3c) & 0xf00000) == 0) ||
           (uVar75 = (UInt32)M<UInt16>(pAVar45 + 0x1c) / (M<UInt32>(pAVar45 + 0x3c) >> 0x14 & 0xf),
           uVar38 = uVar75 - 1, uVar75 == 0)) {
          uVar38 = 0;
        }
        uVar75 = 0;
        if (M<UInt16>(pAVar45 + 0x1e) != 0) {
          uVar75 = M<UInt16>(pAVar45 + 0x1e) - 1;
        }
        puVar65[uVar73 + 0xa6] = uVar38 & 0x7ff | (uVar75 & 0x7ff) << 0xb | 0x80000000;
        uVar38 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar12 * 0x1c);
        puVar65[uVar73 + 0xa8] =
             uVar38 >> 0x13 & 0x1f | (uVar38 & 0x40) << 0x10 | uVar38 >> 7 & 0xe00 |
             uVar38 >> 1 & 0x7000 | (uVar38 & 0x1c00) << 5 | (uVar38 & 0x380) << 0xb;
        uVar38 = M<UInt32>(pAVar45 + 0x3c);
        bVar1 = (uVar38 & 0xf00000) == 0;
        if (bVar1) {
          uVar75 = 0;
        }
        else {
          uVar75 = (UInt32)M<UInt16>(pAVar45 + 0x14) / (uVar38 >> 0x14 & 0xf);
        }
        uVar37 = 0x20 / M<UInt16>(pAVar45 + 0x16);
        if (0x20 / M<UInt16>(pAVar45 + 0x16) <= uVar75) {
          uVar37 = uVar75;
        }
        if ((bVar1) ||
           (uVar75 = (UInt32)M<UInt16>(pAVar45 + 0x1c) / (uVar38 >> 0x14 & 0xf), uVar38 = uVar75 - 1
           , uVar75 == 0)) {
          uVar38 = 0;
        }
        uVar75 = 0;
        if (M<UInt16>(pAVar45 + 0x1e) != 0) {
          uVar75 = M<UInt16>(pAVar45 + 0x1e) - 1;
        }
        puVar69 = puVar65 + uVar73 + 0xbd;
        uVar53 = 0;
        puVar65[uVar73 + 0xaa] = uVar37 - 1 & 0x3fff | (uVar38 & 0x800) << 4 | (uVar75 & 0x800) << 5
        ;
        puVar65[uVar73 + 0xb] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
        AVar12 = pAVar45[0x3a];
        bVar1 = (M<UInt32>(pAVar45 + 0x3c) & 0xf00000) == 0;
        in_cr0 = bVar1 << 1;
        if (!bVar1) {
          uVar53 = (UInt32)M<UInt16>(pAVar45 + 0x14) / (M<UInt32>(pAVar45 + 0x3c) >> 0x14 & 0xf);
        }
        uVar38 = 0x20 / M<UInt16>(pAVar45 + 0x16);
        if (0x20 / M<UInt16>(pAVar45 + 0x16) <= uVar53) {
          uVar38 = uVar53;
        }
        iVar59 = M<SInt32>(pAVar45 + 0x40);
        uVar15 = M<UInt16>(pAVar45 + 0x20);
        AVar13 = pAVar45[0x38];
        iVar48 = M<SInt32>(pAVar45 + 8);
        if ((uVar55 != 0) && (0 < (SInt32)uVar55)) {
          do {
            if ((UInt8)AVar13 >> 1 == 0) {
              uVar75 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar12 * 0x1c);
              iVar33 = 0;
            }
            else {
              uVar75 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar12 * 0x1c);
              iVar33 = -(uVar75 >> 8 & 3);
            }
            uVar75 = uVar75 >> 0xc & 7;
            iVar33 = (SInt32)*puVar69 >> ((iVar33 - uVar75) + 5 & 0x3f);
            if (((UInt8)AVar13 & 1) == 0) {
              iVar33 = iVar33 << 5;
            }
            else {
              iVar33 = (iVar33 << 0xc) >> 3;
            }
            *puVar69 = 0x1150;
            puVar69[1] = (UInt32)uVar15 * iVar59 + iVar48 + iVar33 + (uVar38 * puVar69[1] << uVar75) &
                         0xffffffe0 | ((UInt8)AVar13 >> 1 & 3) << 3 | ((UInt8)AVar13 & 1) << 2;
            uVar58 = puVar69[2];
            uVar75 = puVar65[uVar73 + 0xa6];
            puVar69[2] = 0x1120;
            puVar69[3] = (puVar69[3] - 1) * 0x800 & 0x3ff800 |
                         uVar58 - 1 & 0x7ff | uVar75 & 0xffc00000;
            puVar69 = puVar69 + 0x10;
            uVar55 = uVar55 - 1;
          } while (uVar55 != 0);
        }
        goto LAB_00031340;
      }
      if (0x31000000 < uVar38) {
        if (uVar38 == 0x34000000) {
          uVar38 = puVar65[1] * 8;
          if (M<UInt32>(self + 0xbc) <= uVar38) goto LAB_00030d40;
          *puVar65 = 0x578;
          iVar59 = M<SInt32>(self + 200);
          uVar55 = M<UInt32>(iVar59 + 0x50);
          puVar65[1] = uVar55;
          M<UInt32>(M<SInt32>(self + 0xc0) + uVar38) = uVar55;
          M<UInt32>(iVar59 + 0x50) = uVar55 + 1;
          M<UInt32>(uVar38 + M<SInt32>(self + 0xc0) + 4) = 0;
          local_380 = local_380 + 1;
        }
        else if (uVar38 < 0x34000001) {
          if (uVar38 == 0x32000000) {
            iVar59 = M<SInt32>(self + 0x2a4);
            uVar55 = puVar65[2];
            if ((iVar59 != 0) &&
               ((M<char>(iVar59 + 0x20) == '\x06' || (M<SInt32>(iVar59 + 0x48) != 0)))) {
              uVar38 = puVar65[4];
              uVar58 = puVar65[5];
              if (uVar55 != 0) {
                uVar73 = puVar65[3];
                if (uVar73 == 8) {
LAB_0002f4c8:
                  iVar59 = 8;
                }
                else {
                  if (uVar73 < 9) {
                    if (uVar73 == 7) {
LAB_0002f4c0:
                      iVar59 = 7;
                      goto LAB_0002f498;
                    }
                  }
                  else {
                    if (uVar73 == 10) goto LAB_0002f4c0;
                    if (uVar73 == 0xb) goto LAB_0002f4c8;
                  }
                  iVar59 = 6;
                }
LAB_0002f498:
                if (M<SInt32>(self + 0x3bc) == 0) {
                  pAVar43 = M<UInt8 *>(self + 0x290);
                  pAVar45 = M<UInt8 *>(pAVar43 + iVar59 * 4 + 0xb70);
                }
                else {
                  pAVar43 = M<UInt8 *>(self + 0x290);
                  pAVar45 = (UInt8 *)(self + 0x5a0);
                }
                iVar59 = ((ATIR500Surface *)(pAVar43))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(pAVar45),0,(UInt32 *)(puVar65 + -uVar55));
                uVar73 = 0x80000000;
                if (uVar55 - iVar59 != 1) {
                  uVar73 = ((uVar55 - iVar59) + -2) * 0x10000 | 0xc0001000;
                }
                (puVar65 + -uVar55)[iVar59] = uVar73;
                iVar59 = M<SInt32>(self + 0x2a4);
              }
              iVar48 = (uVar38 >> 0x10) * 2;
              iVar59 = iVar48 + M<SInt32>(iVar59 + 0x14);
              uVar15 = (UInt16)(1 << (uVar38 & 0x3f));
              M<UInt16>(iVar59 + 0x28) = uVar15 | M<UInt16>(iVar59 + 0x28);
              iVar48 = iVar48 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
              M<UInt16>(iVar48 + 0x1c) = M<UInt16>(iVar48 + 0x1c) & ~uVar15;
              *puVar65 = 0xc0051000;
              convertIOGLBufferToBufIdx(puVar65[3],(UInt32 *)&local_378);
              if (M<SInt32>(self + 0x3bc) == 0) {
                uVar38 = M<UInt32>(self + 0x29c);
                iVar48 = M<SInt32>(self + 0x298);
                iVar59 = uVar38 + 1;
                pAVar77 = *(UInt8 **)
                           ((SInt32)local_378 * 4 + M<SInt32>(self + 0x290) + 0xb70);
              }
              else if (puVar65[3] == 4) {
                pAVar77 = self + 0x5a0;
                iVar59 = 1;
                uVar38 = 0;
                iVar48 = 0;
              }
              else {
                iVar59 = 1;
                uVar38 = 0;
                iVar48 = 0;
                pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
              }
              AVar10 = pAVar77[0x3a];
              puVar65[0xa7] =
                   ((UInt8)pAVar77[0x38] & 7) << 2 |
                   M<SInt32>(pAVar77 + uVar38 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar77 + 0x20) +
                   iVar48 * (M<SInt32>(pAVar77 + iVar59 * 4 + 0x40) -
                            M<SInt32>(pAVar77 + uVar38 * 4 + 0x40)) + M<SInt32>(pAVar77 + 8) &
                   0xffffffe0;
              if (((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0) ||
                 (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x1c) /
                                (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)) >> (uVar38 & 0x3f),
                 iVar59 == 0)) {
                uVar73 = 0;
              }
              else {
                uVar73 = iVar59 - 1;
              }
              uVar75 = 0;
              iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar77 + 0x1e) >> (uVar38 & 0x3f);
              if (iVar59 != 0) {
                uVar75 = iVar59 - 1;
              }
              puVar65[0xad] = uVar73 & 0x7ff | (uVar75 & 0x7ff) << 0xb | 0x80000000;
              uVar73 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar10 * 0x1c);
              puVar65[0xaf] =
                   uVar73 >> 0x13 & 0x1f | (uVar73 & 0x40) << 0x10 | uVar73 >> 7 & 0xe00 |
                   uVar73 >> 1 & 0x7000 | (uVar73 & 0x1c00) << 5 | (uVar73 & 0x380) << 0xb;
              uVar73 = M<UInt32>(pAVar77 + 0x3c);
              bVar1 = (uVar73 & 0xf00000) == 0;
              if (bVar1) {
                uVar75 = 0;
              }
              else {
                uVar75 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x14) / (uVar73 >> 0x14 & 0xf)) >>
                         (uVar38 & 0x3f);
              }
              uVar37 = 0x20 / M<UInt16>(pAVar77 + 0x16);
              if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar75) {
                uVar37 = uVar75;
              }
              if ((bVar1) ||
                 (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x1c) / (uVar73 >> 0x14 & 0xf)) >>
                           (uVar38 & 0x3f), iVar59 == 0)) {
                uVar73 = 0;
              }
              else {
                uVar73 = iVar59 - 1;
              }
              uVar75 = 0;
              iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar77 + 0x1e) >> (uVar38 & 0x3f);
              if (iVar59 != 0) {
                uVar75 = iVar59 - 1;
              }
              uVar55 = puVar65[0xa1];
              puVar65[0xb1] = uVar37 - 1 & 0x3fff | (uVar73 & 0x800) << 4 | (uVar75 & 0x800) << 5;
              puVar65[0x12] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
              iVar59 = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + 0x2a4)),true);
              puVar69 = puVar65 + 0xc4;
              uVar73 = 0;
              puVar65[0xa1] = uVar55 + iVar59;
              AVar10 = pAVar77[0x3a];
              bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                uVar73 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x14) /
                              (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)) >> (uVar38 & 0x3f);
              }
              uVar75 = 0x20 / M<UInt16>(pAVar77 + 0x16);
              if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar73) {
                uVar75 = uVar73;
              }
              uVar15 = M<UInt16>(pAVar77 + 0x20);
              iVar74 = M<SInt32>(pAVar77 + 8);
              iVar59 = M<SInt32>(pAVar77 + uVar38 * 4 + 0x40);
              iVar33 = M<SInt32>(pAVar77 + uVar38 * 4 + 0x44);
              AVar11 = pAVar77[0x38];
              if ((uVar58 != 0) && (0 < (SInt32)uVar58)) {
                do {
                  if ((UInt8)AVar11 >> 1 == 0) {
                    uVar38 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
                    iVar49 = 0;
                  }
                  else {
                    uVar38 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
                    iVar49 = -(uVar38 >> 8 & 3);
                  }
                  uVar38 = uVar38 >> 0xc & 7;
                  iVar49 = (SInt32)*puVar69 >> ((iVar49 - uVar38) + 5 & 0x3f);
                  if (((UInt8)AVar11 & 1) == 0) {
                    iVar49 = iVar49 << 5;
                  }
                  else {
                    iVar49 = (iVar49 << 0xc) >> 3;
                  }
                  *puVar69 = 0x1150;
                  puVar69[1] = ((UInt8)AVar11 >> 1 & 3) << 3 | ((UInt8)AVar11 & 1) << 2 |
                               iVar59 * (UInt32)uVar15 + iVar48 * (iVar33 - iVar59) + iVar74 +
                               iVar49 + (uVar75 * puVar69[1] << uVar38) & 0xffffffe0;
                  uVar55 = puVar69[2];
                  uVar38 = puVar65[0xad];
                  puVar69[2] = 0x1120;
                  puVar69[3] = (puVar69[3] - 1) * 0x800 & 0x3ff800 |
                               uVar55 - 1 & 0x7ff | uVar38 & 0xffc00000;
                  puVar69 = puVar69 + 0x10;
                  uVar58 = uVar58 - 1;
                } while (uVar58 != 0);
              }
              M<UInt32>(M<SInt32>(self + 0x290) + 0x80) =
                   M<UInt32>(M<SInt32>(self + 200) + 0x50);
              goto LAB_0002fe70;
            }
            puVar65[-uVar55] = (uVar55 + puVar65[1] + -2) * 0x10000 | 0xc0001000;
          }
          else if (uVar38 == 0x33000000) {
            if (M<SInt32>(self + 0x3bc) == 0) {
              iVar59 = M<SInt32>(self + 0x290);
              uVar38 = M<UInt32>(self + 0x29c);
              iVar48 = M<SInt32>(self + 0x298);
              pAVar68 = M<UInt8 *>((UInt32)M<UInt16>(self + 0xae) * 4 + iVar59 + 0xb70);
              pAVar72 = M<UInt8 *>((UInt32)M<UInt16>(self + 0xac) * 4 + iVar59 + 0xb70);
              iVar33 = uVar38 + 1;
              pAVar77 = (UInt8 *)((UInt32)M<UInt16>(self + 0xac) * 0x78 + iVar59 + 0xa8);
            }
            else {
              pAVar68 = self + 0x5a0;
              iVar48 = 0;
              uVar38 = 0;
              iVar33 = 1;
              pAVar72 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
              pAVar77 = pAVar72;
            }
            uVar75 = puVar65[1];
            *puVar65 = 0xc0001000;
            uVar73 = 0;
            iVar59 = (UInt32)(UInt8)pAVar72[0x3a] * 0x1c;
            puVar65[0x9c] =
                 M<SInt32>(pAVar72 + uVar38 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar72 + 0x20) +
                 iVar48 * (M<SInt32>(pAVar72 + iVar33 * 4 + 0x40) -
                          M<SInt32>(pAVar72 + uVar38 * 4 + 0x40)) + M<SInt32>(pAVar72 + 8) &
                 0xffffffe0;
            if ((M<UInt32>(pAVar72 + 0x3c) & 0xf00000) != 0) {
              uVar73 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x14) /
                            (M<UInt32>(pAVar72 + 0x3c) >> 0x14 & 0xf)) >> (uVar38 & 0x3f);
            }
            uVar38 = 0x20 / M<UInt16>(pAVar72 + 0x16);
            if (0x20 / M<UInt16>(pAVar72 + 0x16) <= uVar73) {
              uVar38 = uVar73;
            }
            uVar35 = puVar65[0x8c];
            puVar65[0x9e] =
                 uVar38 & 0x3ffe | ((UInt8)pAVar72[0x38] & 1) << 0x10 |
                 ((UInt8)pAVar72[0x38] & 6) << 0x10 | ((UInt8)pAVar72[0x39] & 3) << 0x13 |
                 FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar72[0x3a] * 0x1c) >> 1 & 0x1e00000;
            uVar38 = FormatTableLookup_0x0004d2e0(iVar59) >> 0x11 & 0x1f;
            puVar65[0x8c] = uVar38 | uVar35 & 0xffffffe0;
            uVar73 = FormatTableLookup_0x0004d2e0(iVar59) >> 7 & 0x300;
            puVar65[0x8c] = uVar73 | uVar38 | uVar35 & 0xfffffce0;
            uVar37 = FormatTableLookup_0x0004d2e0(iVar59) >> 3 & 0xc00;
            puVar65[0x8c] = uVar37 | uVar73 | uVar38 | uVar35 & 0xfffff0e0;
            uVar53 = (FormatTableLookup_0x0004d2e0(iVar59) & 0x1800) << 1;
            puVar65[0x8c] = uVar53 | uVar37 | uVar73 | uVar38 | uVar35 & 0xffffc0e0;
            puVar65[0x8c] =
                 (FormatTableLookup_0x0004d2e0(iVar59) & 0x600) << 5 |
                 uVar53 | uVar37 | uVar73 | uVar38 | uVar35 & 0xffff00e0;
            uVar55 = this->compute_sc_hyperz_en(puVar65[0x14]);
            puVar65[0x14] = uVar55;
            uVar55 = this->compute_zb_bw_cntl(puVar65[0x16]);
            puVar65[0x16] = uVar55;
            uVar55 = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
            puVar65[0xae] = 0xaaaa;
            puVar65[0xd] = uVar55;
            if ((((M<UInt32>(pAVar77 + 0x28) & 0x3ff00000) == 0x3ff00000) ||
                (pAVar77[0x36] == 0x0)) ||
               (((M<UInt32>(M<SInt32>(self + 0x290) + 0xbe8) & 0x700000) == 0 ||
                (M<SInt16>(self + 0xac) != 9)))) {
              puVar65[0x22] = 0;
            }
            else {
              puVar65[0x22] = 0x600;
            }
            pVVar70 = M<UInt8 *>(self + 0x2a4);
            if (pVVar70 == (UInt8 *)0x0) {
              puVar65[0xa1] = 0xc0001000;
            }
            else {
              bVar80 = M<UInt8>(M<SInt32>(pVVar70 + 0x14) + 0x15);
              uVar38 = this->GetTextureOffset((VendorTextureBuffer *)(pVVar70),false);
              puVar65[0xa2] = bVar80 & 0x1f | uVar38 & 0xffffffe0;
            }
            bVar1 = (uVar75 & 2) == 0;
            in_cr0 = bVar1 << 1;
            if (!bVar1) {
              uVar38 = 0;
              puVar65[0xc0] = -((UInt8)pAVar68[0x3a] ^ 0x10) >> 0x1e & 2;
              puVar65[0xc2] = M<UInt32>(pAVar68 + 8);
              if ((M<UInt32>(pAVar68 + 0x3c) & 0xf00000) != 0) {
                uVar38 = (UInt32)M<UInt16>(pAVar68 + 0x14) /
                         (M<UInt32>(pAVar68 + 0x3c) >> 0x14 & 0xf);
              }
              uVar73 = 0x20 / M<UInt16>(pAVar68 + 0x16);
              if (0x20 / M<UInt16>(pAVar68 + 0x16) <= uVar38) {
                uVar73 = uVar38;
              }
              uVar38 = 0;
              local_c4 = ((UInt8)pAVar68[0x38] & 6) << 0x10 |
                         ((UInt8)pAVar68[0x38] & 1) << 0x10 |
                         ((UInt8)pAVar68[0x39] & 3) << 0x13 | uVar73 & 0x3ffc | local_c4 & 0xffe0c003
              ;
              puVar65[0xc3] = local_c4;
              bVar1 = (M<UInt32>(pAVar68 + 0x3c) & 0xf00000) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                uVar38 = (UInt32)M<UInt16>(pAVar68 + 0x14) /
                         (M<UInt32>(pAVar68 + 0x3c) >> 0x14 & 0xf);
              }
              uVar73 = 0x20 / M<UInt16>(pAVar68 + 0x16);
              if (0x20 / M<UInt16>(pAVar68 + 0x16) <= uVar38) {
                uVar73 = uVar38;
              }
              iVar59 = 0x20;
              if (M<SInt32>(M<SInt32>(self + 200) + 0xb98) == 4) {
LAB_00030cec:
                uVar55 = iVar59 * ((SInt32)(iVar59 + uVar73 + -1) / iVar59);
              }
              else {
                iVar59 = M<SInt32>(M<SInt32>(self + 200) + 0xb98) << 4;
                in_cr0 = (iVar59 == 0) << 1;
                uVar55 = 0;
                if (iVar59 != 0) goto LAB_00030cec;
              }
              puVar65[0xc5] = uVar55;
              uVar55 = HZMEM_GetBlockOffset
                                 ((_HZDATA *)((UInt8 *)(M<SInt32>(self + 200) + 0x870)),
                                  M<UInt32>(pAVar68 + 0x28),0);
              puVar65[199] = uVar55;
              puVar65[0xc9] = M<UInt32>(pAVar68 + 0x2c);
            }
          }
        }
        else if (uVar38 == 0x35000000) {
          iVar59 = M<SInt32>(self + 0x2a4);
          if ((iVar59 == 0) ||
             ((M<char>(iVar59 + 0x20) != '\x06' && (M<SInt32>(iVar59 + 0x48) == 0))))
          goto LAB_000300b8;
          uVar38 = puVar65[2] >> 0xf & 0x1fffe;
          iVar59 = uVar38 + M<SInt32>(iVar59 + 0x14);
          uVar15 = (UInt16)(1 << (puVar65[2] & 0x3f));
          M<UInt16>(iVar59 + 0x28) = uVar15 | M<UInt16>(iVar59 + 0x28);
          iVar59 = uVar38 + M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14);
          M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~uVar15;
          *puVar65 = 0xc0011000;
          uVar55 = puVar65[0x9d];
          puVar65[0xe] = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
          iVar59 = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + 0x2a4)),true);
          puVar65[0x9d] = uVar55 + iVar59;
          puVar65[0xa3] =
               M<SInt32>(M<SInt32>(self + 200) + 0x8a4) + M<SInt32>(self + 0xd0) +
               ((SInt32)puVar65 - (M<SInt32>(self + 0xe0) + 0x20) & 0xfffffffcU) + 0x20 +
               (puVar65[0xa3] >> 3 & 0x1ffffffc) & 0xffffffe0 | puVar65[0xa3] & 0x1f;
LAB_0002fe70:
          M<UInt32>(M<SInt32>(M<SInt32>(self + 0x2a4) + 0x14) + 0xc) =
               M<UInt32>(M<SInt32>(self + 200) + 0x50);
        }
        else if (uVar38 == 0x36000000) {
          iVar59 = M<SInt32>(self + 0x334);
          pVVar79 = (UInt8 *)puVar65[1];
          if ((iVar59 != 0) && (M<SInt32>(iVar59 + 0x48) == 0)) {
            M<SInt16>(iVar59 + 0xe) = M<SInt16>(iVar59 + 0xe) + -1;
          }
          if (((M<SInt32>(pVVar79 + 0x48) == 0) &&
              (M<SInt16>(pVVar79 + 0xe) = M<SInt16>(pVVar79 + 0xe) + 1, M<SInt32>(pVVar79 + 4) == 0
              )) && (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar79)),
                    M<SInt32>(self + 0xd0) == 0)) {
            ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
          }
          M<UInt32>(pVVar79 + 0x5c) = M<UInt32>(M<SInt32>(self + 200) + 0x50);
          M<UInt8 *>(self + 0x334) = pVVar79;
          iVar59 = M<SInt32>(pVVar79 + 0x48);
          uVar55 = puVar65[3];
          uVar38 = puVar65[2] + 1 >> 1;
          if (iVar59 == 0) {
            iVar59 = M<SInt32>(M<SInt32>(self + 200) + 0x8a4) + M<SInt32>(pVVar79 + 4);
          }
          *puVar65 = 0x80000000;
          puVar65[1] = 0x80000000;
          puVar65[2] = 0x80000000;
          puVar65[3] = 0x80000000;
          if (uVar38 != 0) {
            iVar48 = 6;
            iVar33 = 0x1c;
            puVar69 = puVar65;
            do {
              puVar65[iVar48] = uVar55 + iVar59 + puVar69[6] * 4;
              M<UInt32>((SInt32)puVar65 + iVar33) = uVar55 + iVar59 + puVar69[7] * 4;
              puVar69 = puVar69 + 3;
              iVar48 = iVar48 + 3;
              iVar33 = iVar33 + 0xc;
              uVar38 = uVar38 - 1;
            } while (uVar38 != 0);
          }
        }
        goto LAB_00031340;
      }
      if (uVar38 != 0x2d000000) {
        if (uVar38 < 0x2d000001) {
          if (uVar38 == 0x2b000000) {
            if (local_384 != 0) {
              M<UInt32>(M<SInt32>(self + 200) + 0x704) =
                   local_384 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
              M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
              uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) + 0x20)
                                  ,local_388 + M<SInt32>(self + 0xd0) + 0x20,local_384);
              M<UInt32>(self + 0xdc) = uVar40;
              iVar59 = local_384 * 4;
              local_384 = 0;
              local_388 = iVar59 + local_388;
              local_380 = 0;
            }
            *puVar65 = 0x80000000;
          }
          else if (uVar38 == 0x2c000000) {
            if (M<SInt32>(self + 0x3bc) == 0) {
              iVar33 = M<SInt32>(self + 0x29c);
              iVar59 = M<SInt32>(self + 0x298);
              iVar48 = iVar33 + 1;
              pAVar77 = *(UInt8 **)
                         ((UInt32)M<UInt16>(self + 0xac) * 4 + M<SInt32>(self + 0x290) + 0xb70);
            }
            else {
              iVar59 = 0;
              iVar33 = 0;
              iVar48 = 1;
              pAVar77 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
            }
            bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
            in_cr0 = bVar1 << 1;
            uVar38 = 0;
            if (!bVar1) {
              uVar38 = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)
              ;
            }
            uVar73 = 0x20 / M<UInt16>(pAVar77 + 0x16);
            if (uVar73 <= uVar38) {
              uVar73 = uVar38;
            }
            uVar38 = 0x80000000;
            if ((UInt8)pAVar77[0x38] < 2) {
              uVar38 = 0;
            }
            *puVar65 = uVar38 | M<SInt32>(pAVar77 + iVar33 * 4 + 0x40) *
                                (UInt32)M<UInt16>(pAVar77 + 0x20) +
                                iVar59 * (M<SInt32>(pAVar77 + iVar48 * 4 + 0x40) -
                                         M<SInt32>(pAVar77 + iVar33 * 4 + 0x40)) +
                                M<SInt32>(pAVar77 + 8) >> 10 |
                                uVar73 * M<UInt16>(pAVar77 + 0x16) * 0x10000 & 0x3fc00000 |
                                ((UInt8)pAVar77[0x38] & 1) << 0x1e;
            uVar38 = puVar65[1] >> 0x10;
            uVar73 = M<UInt32>(self + 0x354) >> 0x10;
            uVar53 = puVar65[2] & 0xffff;
            uVar35 = M<UInt32>(self + 0x358) & 0xffff;
            uVar57 = puVar65[1] & 0xffff;
            uVar34 = M<UInt32>(self + 0x354) & 0xffff;
            uVar75 = puVar65[2] >> 0x10;
            uVar37 = M<UInt32>(self + 0x358) >> 0x10;
            if (uVar73 < uVar38) {
              uVar73 = uVar38;
            }
            if (uVar34 < uVar57) {
              uVar34 = uVar57;
            }
            if (uVar75 < uVar37) {
              uVar37 = uVar75;
            }
            if (uVar53 < uVar35) {
              uVar35 = uVar53;
            }
            puVar65[1] = uVar34 | uVar73 << 0x10;
            puVar65[2] = uVar35 | uVar37 << 0x10;
          }
        }
        else if (uVar38 == 0x2f000000) {
          *puVar65 = 0x80000000;
          uVar55 = this->compute_sc_hyperz_en(puVar65[2]);
          puVar65[2] = uVar55;
          uVar55 = this->compute_zb_bw_cntl(puVar65[4]);
          puVar65[4] = uVar55;
          VCALL(M<SInt32>(self), 0x5a4)(self);
        }
        else if (uVar38 == 0x30000000) {
          uVar55 = puVar65[1];
          switch(puVar65[2]) {
          default:
            uVar58 = 1;
            break;
          case 1:
            uVar58 = 0;
            break;
          case 2:
            uVar58 = 4;
            break;
          case 3:
            uVar58 = 5;
            break;
          case 7:
            uVar58 = 2;
            break;
          case 8:
            uVar58 = 3;
          }
          puVar42 = (UInt32 *)((ATIR500Surface *)(M<UInt8 *>(self + 0x290)))->resolve_fsaa_buffer((UInt32)M<UInt16>(self + 0xac),uVar58,(UInt32 *)(puVar65),
                                       (bool)('\x01' - (puVar65[3] == 0)),puVar65[4],puVar65[5],
                                       puVar65[6],puVar65[7]);
          if (puVar42 < puVar65 + uVar55) {
            iVar59 = (SInt32)(puVar65 + uVar55) - (SInt32)puVar42;
            if (iVar59 - 4U < 4) {
              *puVar42 = 0x80000000;
            }
            else {
              *puVar42 = ((iVar59 >> 2) + -2) * 0x10000 | 0xc0001000;
            }
          }
        }
        goto LAB_00031340;
      }
      local_d0 = puVar65 + puVar65[1];
      switch(puVar65[2]) {
      default:
        iVar59 = 1;
        break;
      case 1:
        iVar59 = 0;
        break;
      case 2:
        iVar59 = 4;
        break;
      case 3:
        iVar59 = 5;
        break;
      case 4:
        iVar59 = 6;
        break;
      case 7:
        iVar59 = 2;
        break;
      case 8:
        iVar59 = 3;
        break;
      case 10:
        iVar59 = 7;
        break;
      case 0xb:
        iVar59 = 8;
      }
      uVar55 = puVar65[3];
      uVar58 = puVar65[4];
      uVar61 = puVar65[5];
      uVar62 = puVar65[6];
      uVar38 = puVar65[7];
      uVar73 = puVar65[8];
      *puVar65 = (puVar65[1] - 2) * 0x10000 | 0xc0001000;
      if (M<SInt32>(self + 0x3bc) == 0) {
        uVar75 = M<UInt32>(self + 0x29c);
        iVar48 = M<SInt32>(self + 0x298);
        iVar33 = uVar75 + 1;
        pAVar72 = M<UInt8 *>(iVar59 * 4 + M<SInt32>(self + 0x290) + 0xb70);
        pAVar77 = *(UInt8 **)
                   (M<SInt32>(self + 0x35c) * 4 + M<SInt32>(self + 0x290) + 0xb70);
      }
      else {
        iVar48 = 0;
        uVar75 = 0;
        iVar33 = 1;
        pAVar72 = self + (UInt32)M<UInt16>(self + 0x3b2) * 0x78 + 0x3c0;
        pAVar77 = pAVar72;
      }
      puVar42 = puVar65 + 0xbd;
      GH_memcpy(puVar65,&g_r500_3d_blit_state_packet,0x2f4);
      iVar59 = (UInt32)(UInt8)pAVar77[0x3a] * 0x1c;
      uVar37 = 0;
      puVar65[0x9a] =
           M<SInt32>(pAVar77 + uVar75 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar77 + 0x20) +
           iVar48 * (M<SInt32>(pAVar77 + iVar33 * 4 + 0x40) - M<SInt32>(pAVar77 + uVar75 * 4 + 0x40))
           + M<SInt32>(pAVar77 + 8) & 0xffffffe0;
      if ((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) != 0) {
        uVar37 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)
                      ) >> (uVar75 & 0x3f);
      }
      uVar53 = 0x20 / M<UInt16>(pAVar77 + 0x16);
      if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar37) {
        uVar53 = uVar37;
      }
      uVar34 = puVar65[0x8a];
      puVar65[0x9c] =
           uVar53 & 0x3ffe | ((UInt8)pAVar77[0x38] & 1) << 0x10 | ((UInt8)pAVar77[0x38] & 6) << 0x10 |
           ((UInt8)pAVar77[0x39] & 3) << 0x13 |
           FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar77[0x3a] * 0x1c) >> 1 & 0x1e00000;
      uVar37 = FormatTableLookup_0x0004d2e0(iVar59) >> 0x11 & 0x1f;
      puVar65[0x8a] = uVar37 | uVar34 & 0xffffffe0;
      uVar53 = FormatTableLookup_0x0004d2e0(iVar59) >> 7 & 0x300;
      puVar65[0x8a] = uVar53 | uVar37 | uVar34 & 0xfffffce0;
      uVar35 = FormatTableLookup_0x0004d2e0(iVar59) >> 3 & 0xc00;
      puVar65[0x8a] = uVar35 | uVar53 | uVar37 | uVar34 & 0xfffff0e0;
      uVar57 = (FormatTableLookup_0x0004d2e0(iVar59) & 0x1800) << 1;
      puVar65[0x8a] = uVar57 | uVar35 | uVar53 | uVar37 | uVar34 & 0xffffc0e0;
      puVar65[0x8a] =
           (FormatTableLookup_0x0004d2e0(iVar59) & 0x600) << 5 |
           uVar57 | uVar35 | uVar53 | uVar37 | uVar34 & 0xffff00e0;
      if (((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0) ||
         (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x1c) /
                        (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)) >> (uVar75 & 0x3f), iVar59 == 0))
      {
        uVar37 = 0;
      }
      else {
        uVar37 = iVar59 - 1;
      }
      uVar53 = 0;
      iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar77 + 0x1e) >> (uVar75 & 0x3f);
      if (iVar59 != 0) {
        uVar53 = iVar59 - 1;
      }
      puVar65[0xb3] = uVar37 & 0x1fff | (uVar53 & 0x1fff) << 0xd;
      AVar10 = pAVar72[0x3a];
      puVar65[0xa0] =
           ((UInt8)pAVar72[0x38] & 7) << 2 |
           M<SInt32>(pAVar72 + uVar75 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar72 + 0x20) +
           iVar48 * (M<SInt32>(pAVar72 + iVar33 * 4 + 0x40) - M<SInt32>(pAVar72 + uVar75 * 4 + 0x40))
           + M<SInt32>(pAVar72 + 8) & 0xffffffe0;
      if (((M<UInt32>(pAVar72 + 0x3c) & 0xf00000) == 0) ||
         (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x1c) /
                        (M<UInt32>(pAVar72 + 0x3c) >> 0x14 & 0xf)) >> (uVar75 & 0x3f), iVar59 == 0))
      {
        uVar37 = 0;
      }
      else {
        uVar37 = iVar59 - 1;
      }
      uVar53 = 0;
      iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar72 + 0x1e) >> (uVar75 & 0x3f);
      if (iVar59 != 0) {
        uVar53 = iVar59 - 1;
      }
      puVar65[0xa6] = uVar37 & 0x7ff | (uVar53 & 0x7ff) << 0xb | 0x80000000;
      uVar37 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar10 * 0x1c);
      puVar65[0xa8] =
           uVar37 >> 0x13 & 0x1f | (uVar37 & 0x40) << 0x10 | uVar37 >> 7 & 0xe00 |
           uVar37 >> 1 & 0x7000 | (uVar37 & 0x1c00) << 5 | (uVar37 & 0x380) << 0xb;
      uVar37 = M<UInt32>(pAVar72 + 0x3c);
      bVar1 = (uVar37 & 0xf00000) == 0;
      if (bVar1) {
        uVar53 = 0;
      }
      else {
        uVar53 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x14) / (uVar37 >> 0x14 & 0xf)) >>
                 (uVar75 & 0x3f);
      }
      uVar35 = 0x20 / M<UInt16>(pAVar72 + 0x16);
      if (0x20 / M<UInt16>(pAVar72 + 0x16) <= uVar53) {
        uVar35 = uVar53;
      }
      if ((bVar1) ||
         (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x1c) / (uVar37 >> 0x14 & 0xf)) >>
                   (uVar75 & 0x3f), iVar59 == 0)) {
        uVar37 = 0;
      }
      else {
        uVar37 = iVar59 - 1;
      }
      uVar53 = 0;
      iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar72 + 0x1e) >> (uVar75 & 0x3f);
      if (iVar59 != 0) {
        uVar53 = iVar59 - 1;
      }
      uStack_17c = uVar55 - uVar38 ^ 0x80000000;
      puVar65[0xaa] = uVar35 - 1 & 0x3fff | (uVar37 & 0x800) << 4 | (uVar53 & 0x800) << 5;
      uVar55 = M<UInt32>(M<SInt32>(self + 200) + 0xb74);
      puVar65[0xaf] = 0xc0001000;
      puVar65[0x11] = 0xc0001000;
      puVar65[0x13] = 0xc0001000;
      puVar65[0x15] = 0xc0001000;
      puVar65[0x1d] = 0xc0001000;
      puVar65[0x2d] = 0xc0001000;
      puVar65[0x2f] = 0xc0001000;
      puVar65[0xb] = uVar55;
      puVar65[0x31] = 0xc0001000;
      puVar65[0x33] = 0xc0001000;
      puVar65[0x35] = 0xc0001000;
      puVar65[0xad] = 0xc0001000;
      puVar65[0xb1] = 0xc0011000;
      puVar65[0xa2] = puVar65[0xa2] & 0xffffe600 | 0x11b6;
      dVar31 = DOUBLE_0004c3a8;
      fVar23 = FLOAT_0004c380;
      fVar30 = FLOAT_0004c37c;
      fVar28 = FLOAT_0004c374;
      uStack_194 = uVar73 ^ 0x80000000;
      local_198 = 0x43300000;
      local_180 = 0x43300000;
      iStack_18c = uVar61 + uVar38;
      uStack_19c = uVar38 ^ 0x80000000;
      iStack_184 = uVar62 + uVar73;
      local_1a0 = 0x43300000;
      local_190 = 0x43300000;
      local_188 = 0x43300000;
      local_178 = 0x43300000;
      uStack_174 = uVar58 - uVar73 ^ 0x80000000;
      uVar53 = (UInt32)M<UInt16>(pAVar72 + 0x1c);
      uVar37 = (UInt32)M<UInt16>(pAVar72 + 0x1e);
      fVar4 = (float)((double)CONCAT44d(0x43300000,uVar73 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar5 = (float)((double)CONCAT44d(0x43300000,uStack_17c) - DOUBLE_0004c3a8);
      fVar6 = (float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar7 = (float)((double)CONCAT44d(0x43300000,uVar61 + uVar38) - DOUBLE_0004c3b0);
      fVar8 = (float)((double)CONCAT44d(0x43300000,uVar62 + uVar73) - DOUBLE_0004c3b0);
      fVar9 = (float)((double)CONCAT44d(0x43300000,uStack_174) - DOUBLE_0004c3a8);
      if ((uVar53 < 0x1001) && (uVar37 < 0x1001)) {
LAB_0002d820:
        fVar28 = FLOAT_0004c370;
        if (uVar53 != 0) {
          local_140 = 0x43300000;
          uStack_13c = uVar53 ^ 0x80000000;
          fVar28 = FLOAT_0004c374 /
                   (float)((double)CONCAT44d(0x43300000,uVar53 ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        fVar23 = FLOAT_0004c370;
        if (uVar37 != 0) {
          uStack_134 = uVar37 ^ 0x80000000;
          local_138 = 0x43300000;
          fVar23 = FLOAT_0004c374 /
                   (float)((double)CONCAT44d(0x43300000,uVar37 ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        bVar1 = true;
        *puVar42 = 0x31080;
        puVar65[0xc2] = 0x1087;
        uVar38 = 0;
        puVar65[0xbe] = (UInt32)(fVar28 * (fVar6 + fVar5));
        puVar65[0xc0] = (UInt32)(fVar28 * (fVar7 + fVar5));
        puVar65[0xbf] = (UInt32)(fVar23 * (fVar8 + fVar9));
        puVar65[0xc1] = (UInt32)(fVar23 * (fVar4 + fVar9));
        iVar59 = (SInt32)((fVar7 - fVar6) * fVar30);
        uVar73 = (UInt32)((fVar8 - fVar4) * fVar30);
        local_130 = (SInt64)iVar59;
        local_128 = (SInt64)(SInt32)uVar73;
        fVar5 = (fVar6 + fVar7) * FLOAT_0004c380;
        fVar4 = (fVar4 + fVar8) * FLOAT_0004c380;
        puVar65[0xc4] = 0xc0033500;
        puVar65[0xc5] = 0x10031;
        puVar65[0xc6] = (UInt32)fVar5;
        puVar65[199] = (UInt32)fVar4;
        puVar65[0xc3] = iVar59 << 0x10 | uVar73;
        puVar65[200] = 0;
      }
      else {
        fVar17 = fVar4 + fVar9;
        fVar18 = fVar8 + fVar9;
        fVar20 = fVar6 + fVar5;
        fVar24 = fVar7 + fVar5;
        fVar22 = fVar17;
        if (fVar18 < fVar17) {
          fVar22 = fVar18;
          fVar18 = fVar17;
        }
        fVar17 = fVar20;
        if (fVar24 < fVar20) {
          fVar17 = fVar24;
          fVar24 = fVar20;
        }
        uVar35 = M<UInt16>(pAVar72 + 0x1c) & 0xfe00;
        local_170 = (SInt64)(SInt32)fVar17;
        uVar38 = (SInt32)fVar17 - 1;
        uVar38 = (((SInt32)uVar38 >> 9) + (UInt32)((SInt32)uVar38 < 0 && (uVar38 & 0x1ff) != 0)) * 0x200;
        uVar73 = 0;
        if ((-1 < (SInt32)uVar38) && (uVar73 = uVar35, (SInt32)uVar38 <= (SInt32)uVar35)) {
          uVar73 = uVar38 & 0xfe00;
        }
        uVar38 = 0x40;
        if ((0x40 < uVar37) &&
           (uVar38 = M<UInt16>(pAVar72 + 0x1e) & 0xffc0, (SInt32)(uVar37 - uVar38) < 0x40)) {
          uVar38 = uVar38 - 0x40;
        }
        uVar57 = 0;
        local_168 = (SInt64)(SInt32)fVar22;
        uVar35 = (SInt32)fVar22 - 1;
        uVar35 = (((SInt32)uVar35 >> 6) + (UInt32)((SInt32)uVar35 < 0 && (uVar35 & 0x3f) != 0)) * 0x40;
        if ((-1 < (SInt32)uVar35) && (uVar57 = uVar38 & 0xffff, (SInt32)uVar35 <= (SInt32)uVar38)) {
          uVar57 = uVar35 & 0xffc0;
        }
        uVar38 = 0x200;
        if (0x1ff < uVar73) {
          uVar38 = uVar73;
        }
        uVar35 = uVar53 - 1;
        uVar34 = (((SInt32)uVar35 >> 9) + (UInt32)((SInt32)uVar35 < 0 && (uVar35 & 0x1ff) != 0)) * 0x200;
        uVar35 = (UInt32)fVar24;
        local_160 = (SInt64)(SInt32)uVar35;
        if (FLOAT_0004c370 < fVar24) {
          uStack_154 = uVar35 ^ 0x80000000;
          local_158 = 0x43300000;
          if ((float)((double)CONCAT44d(0x43300000,uVar35 ^ 0x80000000) - DOUBLE_0004c3a8) < fVar24)
          {
            uVar35 = uVar35 + 1;
          }
        }
        if ((SInt32)uVar35 <= (SInt32)uVar34) {
          uVar34 = uVar35;
        }
        uVar35 = 1;
        if ((SInt32)uVar38 < (SInt32)uVar34) {
          uVar35 = (SInt32)((uVar34 - uVar38) + 0xbff) / 0xc00 & 0xff;
        }
        uVar38 = 0x40;
        if (0x3f < uVar57) {
          uVar38 = uVar57;
        }
        uVar34 = uVar37 - 1;
        uVar41 = (((SInt32)uVar34 >> 6) + (UInt32)((SInt32)uVar34 < 0 && (uVar34 & 0x3f) != 0)) * 0x40;
        uVar34 = (UInt32)fVar18;
        local_150 = (SInt64)(SInt32)uVar34;
        if (FLOAT_0004c370 < fVar18) {
          local_148 = 0x43300000;
          uStack_144 = uVar34 ^ 0x80000000;
          if ((float)((double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8) < fVar18)
          {
            uVar34 = uVar34 + 1;
          }
        }
        if ((SInt32)uVar34 <= (SInt32)uVar41) {
          uVar41 = uVar34;
        }
        uVar34 = 1;
        if ((SInt32)uVar38 < (SInt32)uVar41) {
          uVar34 = (SInt32)((uVar41 - uVar38) + 0xf7f) / 0xf80 & 0xff;
        }
        uVar38 = uVar35 * uVar34 & 0xff;
        if (uVar38 == 0) goto LAB_0002d820;
        bVar1 = false;
        if (uVar34 != 0) {
          uVar78 = uVar37 - uVar57;
          uVar60 = 0;
          iVar59 = 0;
          uVar41 = uVar57;
          puVar54 = puVar42;
          do {
            if (uVar35 != 0) {
              uVar44 = iVar59 + uVar57;
              local_d8 = 0x43300000;
              uVar46 = uVar53 - uVar73;
              iVar33 = 0;
              uStack_d4 = uVar44 ^ 0x80000000;
              fVar4 = (float)((double)CONCAT44d(0x43300000,uVar44 ^ 0x80000000) - dVar31);
              uVar47 = uVar73;
              uVar81 = uVar35;
              do {
                *puVar54 = uVar47;
                puVar54[1] = uVar41;
                uVar50 = uVar46;
                if ((SInt32)(uVar47 + 0x1000) <= (SInt32)uVar53) {
                  uVar50 = 0x1000;
                }
                uVar56 = uVar78;
                if ((SInt32)(uVar44 + 0x1000) <= (SInt32)uVar37) {
                  uVar56 = 0x1000;
                }
                puVar54[2] = uVar50;
                puVar54[3] = uVar56;
                fVar6 = fVar17;
                if (iVar33 != 0) {
                  local_120 = 0x43300000;
                  uStack_11c = uVar47 + 0x200 ^ 0x80000000;
                  fVar6 = (float)((double)CONCAT44d(0x43300000,uStack_11c) - dVar31);
                }
                fVar7 = fVar22;
                if (uVar60 != 0) {
                  local_118 = 0x43300000;
                  uStack_114 = uVar44 + 0x40 ^ 0x80000000;
                  fVar7 = (float)((double)CONCAT44d(0x43300000,uStack_114) - dVar31);
                }
                fVar8 = fVar24;
                if (iVar33 != uVar35 - 1) {
                  local_110 = 0x43300000;
                  uStack_10c = uVar47 + 0xe00 ^ 0x80000000;
                  fVar8 = (float)((double)CONCAT44d(0x43300000,uStack_10c) - dVar31);
                }
                fVar20 = fVar18;
                if (uVar60 != uVar34 - 1) {
                  local_108 = 0x43300000;
                  uStack_104 = uVar44 + 0xfc0 ^ 0x80000000;
                  fVar20 = (float)((double)CONCAT44d(0x43300000,uStack_104) - dVar31);
                }
                fVar19 = fVar18;
                if (fVar20 - fVar18 < 0.0) {
                  fVar19 = fVar20;
                }
                fVar21 = fVar22;
                if (fVar22 - fVar7 < 0.0) {
                  fVar21 = fVar7;
                }
                fVar25 = fVar17;
                if (fVar17 - fVar6 < 0.0) {
                  fVar25 = fVar6;
                }
                fVar27 = fVar8;
                if (fVar24 - fVar8 < 0.0) {
                  fVar27 = fVar24;
                }
                if (-(fVar22 - fVar7) < 0.0) {
                  fVar7 = fVar21;
                }
                if (-(fVar20 - fVar18) < 0.0) {
                  fVar20 = fVar19;
                }
                if (-(fVar17 - fVar6) < 0.0) {
                  fVar6 = fVar25;
                }
                if (-(fVar24 - fVar8) < 0.0) {
                  fVar27 = fVar8;
                }
                fVar8 = fVar7 + -fVar9;
                fVar19 = fVar20 + -fVar9;
                fVar25 = fVar6 + -fVar5;
                fVar26 = fVar27 + -fVar5;
                fVar21 = fVar20;
                fVar29 = fVar8;
                if (fVar19 < fVar8) {
                  fVar21 = fVar7;
                  fVar7 = fVar20;
                  fVar29 = fVar19;
                  fVar19 = fVar8;
                }
                fVar8 = fVar27;
                fVar20 = fVar25;
                if (fVar26 < fVar25) {
                  fVar8 = fVar6;
                  fVar6 = fVar27;
                  fVar20 = fVar26;
                  fVar26 = fVar25;
                }
                fVar25 = FLOAT_0004c370;
                if (uVar50 != 0) {
                  local_100 = 0x43300000;
                  uStack_fc = uVar50 ^ 0x80000000;
                  fVar25 = fVar28 / (float)((double)CONCAT44d(0x43300000,uVar50 ^ 0x80000000) -
                                           dVar31);
                }
                fVar27 = FLOAT_0004c370;
                if (uVar56 != 0) {
                  local_f8 = 0x43300000;
                  uStack_f4 = uVar56 ^ 0x80000000;
                  fVar27 = fVar28 / (float)((double)CONCAT44d(0x43300000,uVar56 ^ 0x80000000) -
                                           dVar31);
                }
                uStack_ec = uVar47 ^ 0x80000000;
                local_f0 = 0x43300000;
                iVar33 = iVar33 + 1;
                uVar47 = uVar47 + 0xc00;
                uVar46 = uVar46 - 0xc00;
                iVar74 = (SInt32)((fVar26 - fVar20) * fVar30);
                uVar50 = (UInt32)((fVar19 - fVar29) * fVar30);
                puVar54[4] = 0x31080;
                puVar54[6] = (UInt32)(fVar27 * (fVar21 - fVar4));
                puVar54[8] = (UInt32)(fVar27 * (fVar7 - fVar4));
                puVar54[9] = 0x1087;
                fVar7 = (float)((double)CONCAT44d(0x43300000,uStack_ec) - dVar31);
                puVar54[7] = (UInt32)(fVar25 * (fVar8 - fVar7));
                puVar54[5] = (UInt32)(fVar25 * (fVar6 - fVar7));
                local_e8 = (SInt64)iVar74;
                local_e0 = (SInt64)(SInt32)uVar50;
                puVar54[0xb] = 0xc0033500;
                puVar54[0xc] = 0x10031;
                puVar54[0xd] = (UInt32)((fVar20 + fVar26) * fVar23);
                puVar54[0xe] = (UInt32)((fVar29 + fVar19) * fVar23);
                puVar54[10] = iVar74 << 0x10 | uVar50;
                puVar54[0xf] = 0;
                puVar54 = puVar54 + 0x10;
                uVar81 = uVar81 - 1;
              } while (uVar81 != 0);
            }
            uVar60 = uVar60 + 1;
            iVar59 = iVar59 + 0xf80;
            uVar78 = uVar78 - 0xf80;
            uVar41 = uVar41 + 0xf80;
          } while (uVar34 != uVar60);
        }
      }
      AVar10 = pAVar72[0x3a];
      uVar73 = 0;
      bVar2 = (M<UInt32>(pAVar72 + 0x3c) & 0xf00000) == 0;
      in_cr0 = bVar2 << 1;
      if (!bVar2) {
        uVar73 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x14) / (M<UInt32>(pAVar72 + 0x3c) >> 0x14 & 0xf)
                      ) >> (uVar75 & 0x3f);
      }
      uVar37 = 0x20 / M<UInt16>(pAVar72 + 0x16);
      if (0x20 / M<UInt16>(pAVar72 + 0x16) <= uVar73) {
        uVar37 = uVar73;
      }
      uVar15 = M<UInt16>(pAVar72 + 0x20);
      AVar11 = pAVar72[0x38];
      iVar33 = M<SInt32>(pAVar72 + 8);
      iVar59 = M<SInt32>(pAVar72 + uVar75 * 4 + 0x40);
      iVar74 = M<SInt32>(pAVar72 + uVar75 * 4 + 0x44);
      if (bVar1) {
        puVar42 = puVar65 + 0xc9;
      }
      else {
        iVar49 = 0;
        if (uVar38 != 0) {
          iVar49 = 0;
          puVar54 = puVar42;
          do {
            if ((UInt8)AVar11 >> 1 == 0) {
              uVar73 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
              iVar39 = 0;
            }
            else {
              uVar73 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
              iVar39 = -(uVar73 >> 8 & 3);
            }
            uVar73 = uVar73 >> 0xc & 7;
            iVar39 = (SInt32)*puVar54 >> ((iVar39 - uVar73) + 5 & 0x3f);
            if (((UInt8)AVar11 & 1) == 0) {
              iVar39 = iVar39 << 5;
            }
            else {
              iVar39 = (iVar39 << 0xc) >> 3;
            }
            iVar49 = iVar49 + 1;
            *puVar54 = 0x1150;
            puVar54[1] = iVar59 * (UInt32)uVar15 + iVar48 * (iVar74 - iVar59) + iVar33 +
                         iVar39 + (uVar37 * puVar54[1] << uVar73) & 0xffffffe0 |
                         ((UInt8)AVar11 & 1) << 2 | ((UInt8)AVar11 >> 1 & 3) << 3;
            uVar75 = puVar54[2];
            uVar73 = puVar65[0xa6];
            puVar54[2] = 0x1120;
            puVar54[3] = (puVar54[3] - 1) * 0x800 & 0x3ff800 |
                         uVar75 - 1 & 0x7ff | uVar73 & 0xffc00000;
            puVar54 = puVar54 + 0x10;
            uVar38 = uVar38 - 1;
          } while (uVar38 != 0);
          iVar49 = iVar49 * 0x10;
        }
        puVar42 = puVar42 + iVar49;
      }
      if (puVar42 < local_d0) {
        uVar38 = 0x80000000;
        if (3 < ((SInt32)local_d0 - (SInt32)puVar42) - 4U) {
          uVar38 = (((SInt32)local_d0 - (SInt32)puVar42 >> 2) + -2) * 0x10000 | 0xc0001000;
        }
        *puVar42 = uVar38;
      }
      M<UInt32>(M<SInt32>(self + 200) + 0x78) = 0;
    }
LAB_00031340:
    uVar55 = local_384 + uVar63;
    puVar65 = (UInt32 *)((SInt32)puVar65 + iVar52);
    if (uVar63 == 0) {
      if ((uVar55 & 1) != 0) {
        *puVar65 = 0x80000000;
        uVar55 = local_384 + 1;
        puVar65 = puVar65 + 1;
      }
      M<UInt32>(param_1) = (local_388 & 0xfffffffc) + M<SInt32>(self + 0xe0) + 0x20;
      iVar52 = M<SInt32>(self + 0xd0);
      M<UInt32 *>(param_1 + 0xc) = puVar65;
      M<UInt32>(param_1 + 8) = uVar55;
      M<UInt32>(param_1 + 4) = iVar52 + local_388 + 0x20;
      M<UInt32>(M<SInt32>(self + 200) + 0x78) = 0;
      return local_cc;
    }
  } while( true );
}
