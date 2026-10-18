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
IOReturn ATIR500GLContext::process_command_buffer(VendorCommandDescriptor *descriptor) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *descriptorBytes = reinterpret_cast<UInt8 *>(descriptor);

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
  UInt32 opcode;
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
  UInt32 *recordCursor;
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
  UInt32 streamOffset;
  UInt32 pendingWords;
  UInt32 reservedWords;
  UInt8 *local_37c;
  UInt8 *local_378;
  UInt32 nopHeader;
  UInt32 gapWords;
  UInt8 *boundTexture;
  SInt32 *refCountPtr;
  SInt32 previousRefCount;
  UInt32 submittedWords;
  SInt32 textureOffset;
  SInt32 vertexArrayOffset;
  SInt32 accel;
  UInt8 *texture;
  UInt32 hzBlockCount;
  SInt32 hzIsPartial;
  SInt32 formatByteOffset;
  UInt32 formatFieldE0;
  UInt32 formatFieldE4;
  UInt32 hzBlockOffset;
  UInt32 widthPerSample;
  UInt32 pitchPixels;
  UInt32 maxY;
  UInt16 levelBit;
  UInt32 faceOffset;
  UInt8 *surfaceBuffer;
  UInt32 formatFieldDC;
  UInt8 local_374 [0x80];   /* the ATIR500SurfaceBuffer on the shipped stack (Ghidra shows 0x2c bytes here + M<UInt32>(local_374 + 0x2c) = its +0x2c word) */
  /* #170: ONE real 0x144-byte stack object (shipped frame -0x2fc..-0x1b8): the 0x134-byte register_tracking_state
   * plus four range words at +0x134..+0x140 that restore_state_destroyed_by_pageoff hands to track_regs_written_by_pm4.
   * Ghidra split it into trackingState plus separate locals (local_2e4/local_2e0 = +0x18/+0x1c; local_1c8, local_1c4,
   * local_1c0, local_1bc = +0x134/+0x138/+0x13c/+0x140), which only works if the compiler lays those locals out
   * contiguously after the array; our gcc 4.0.1 build scatters them, so the callee read garbage ranges and ran off
   * the end of a buffer. */
  struct { register_tracking_state s; UInt32 rangeWords[4]; } trackBlk;
  register_tracking_state *trackingState = &trackBlk.s;
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
  UInt32 *recordPayloadEnd;
  UInt32 result;
  UInt32 local_c8;
  UInt32 local_c4;
  UInt8 *local_c0;
  UInt32 *trailerLastWord;
  
  puVar69 = M<UInt32 *>(self + kIOATIR500GLContext_contextBufferHeader);
  streamOffset = 0;
  pendingWords = 0xffffffff;
  reservedWords = 0;
  M<UInt32 *>((UInt8 *)&trackBlk + 0x134) = puVar69 + 8;
  local_c8 = 0;
  local_c4 = 0;
  result = 0;
  M<SInt32>((UInt8 *)&trackBlk + 0x13c) = M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20;
  recordCursor = (UInt32 *)(M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x1c);
  M<UInt32 *>((UInt8 *)&trackBlk + 0x138) = M<UInt32 *>((UInt8 *)&trackBlk + 0x134) + puVar69[5];
  M<UInt32>((UInt8 *)&trackBlk + 0x18) = this->compute_sc_hyperz_en(*puVar69);
  M<UInt32>((UInt8 *)&trackBlk + 0x1c) = this->compute_zb_bw_cntl(puVar69[1]);
  uVar55 = pendingWords;
  do {
    pendingWords = uVar55;
    uVar73 = *recordCursor;
    uVar63 = uVar73 & 0xffffff;
    iVar52 = uVar63 * 4;
    dataCacheBlockTouch(recordCursor + uVar63);
    opcode = uVar73 & 0xff000000;
    uVar75 = (uVar73 >> 0x18) - 6;
    if (uVar75 < 0x10) {
      iVar59 = uVar75 * 4;
      boundTexture = M<UInt8 *>(self + iVar59 + 0x2a4);
      if (boundTexture != (UInt8 *)0x0) {
        ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(boundTexture));
        refCountPtr = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
        previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
        if (previousRefCount == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(boundTexture));
        }
        M<UInt32>(self + iVar59 + 0x2a4) = 0;
      }
      if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[1]) ||
         (texture = *(UInt8 **)
                     (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
         texture == (UInt8 *)0x0)) goto LAB_00030d40;
      local_378 = texture;
      ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
      iVar48 = M<SInt32>(texture + 0x14);
      if (M<char>(iVar48 + 0x14) != '\0') {
        if (pendingWords != 0) {
          opcode = recordCursor[-1] >> 2;
          if (4 < opcode) {
            nopHeader = 0x80000000;
            if (opcode != 5) {
              nopHeader = (opcode - 6) * 0x10000 | 0xc0001000;
            }
            recordCursor[-opcode] = nopHeader;
          }
          recordCursor[-4] = 0x1393;
          recordCursor[-3] = 0;
          recordCursor[-2] = 0x5c8;
          recordCursor[-1] = 0x20000;
          M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
               pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
          M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
          uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20),
                              streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
          submittedWords = pendingWords;
          M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
          reservedWords = 0;
          pendingWords = 0;
          streamOffset = submittedWords * 4 + streamOffset;
        }
        this->alloc_and_load_texture((VendorTextureBuffer *)(texture));
        if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
          M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
          this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
        }
        if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
          ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
        }
      }
      uVar37 = M<UInt32>(texture + 0x68);
      opcode = recordCursor[2] >> 0x1e;
      uVar73 = opcode << 0x1e;
      M<UInt32>(texture + 0x68) = uVar73 | uVar37 & 0x3fffffff;
      if (opcode != 0) {
        bVar80 = M<UInt8>(recordCursor + 3);
        uVar53 = (UInt32)bVar80 << 0x16;
        M<UInt32>(texture + 0x68) = uVar53 | uVar73 | uVar37 & 0x3fffff;
        if (opcode == 1) {
          iVar33 = (UInt32)bVar80 * 0x1c;
          bVar1 = (M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 0x18) == 0;
          in_cr0 = bVar1 << 1;
          if (bVar1) {
            formatFieldDC = FormatTableLookup_0x0004d2dc(iVar33);
            iVar33 = 0;
          }
          else {
            formatFieldDC = FormatTableLookup_0x0004d2dc(iVar33);
            iVar33 = -(formatFieldDC >> 8 & 3);
          }
          iVar33 = (SInt32)(recordCursor[3] & 0xffffff) >> ((iVar33 - (opcode >> 0xc & 7)) + 5 & 0x3f);
          opcode = iVar33 << 5;
          if ((M<UInt8>(M<SInt32>(texture + 0x14) + 0x15) & 4) != 0) {
            opcode = (iVar33 << 0xc) >> 3;
          }
          M<UInt32>(texture + 0x68) =
               opcode >> 5 & 0x3fffff | M<UInt32>(texture + 0x68) & 0xffc00000;
        }
        else if (texture[0x20] == 0x0) {
          pIVar66 = M<UInt8 *>(texture + 0x50);
          opcode = 0;
          if (pIVar66 != (UInt8 *)0x0) {
            iVar33 = ((IOATIR500Surface *)(pIVar66))->surface_buffer_idx_mask(M<UInt32>(texture + 0x58),(UInt32 *)&local_378);
            opcode = (UInt32)M<UInt16>(M<SInt32>(pIVar66 + iVar33 * 4 + 0xb70) + 0x14) *
                     (UInt32)M<UInt16>(M<SInt32>(pIVar66 + iVar33 * 4 + 0xb70) + 0x16);
            if (opcode < 0x20) {
              opcode = 0x20;
            }
          }
          M<UInt32>(texture + 0x68) =
               opcode * (recordCursor[3] & 0xffffff) >> 5 & 0x3fffff |
               M<UInt32>(texture + 0x68) & 0xffc00000;
        }
        else {
          M<UInt32>(texture + 0x68) = recordCursor[3] & 0x3fffff | uVar53 | uVar73;
        }
      }
      piVar36 = (SInt32 *)(iVar48 + 0x10);
      M<UInt32>(texture + 0x60) = recordCursor[2] & 0x3fffffff;
      atomicAddReturningOld((SInt32 *)piVar36, -0xffff);
      if (M<SInt32>(texture + 0x48) != 0) {
        iVar48 = M<SInt32>(texture + 0x24);
        M<UInt32>(iVar48 + 0x28) = M<UInt32>(texture + 0x28);
        M<SInt32>(M<SInt32>(texture + 0x28) + 0x24) = iVar48;
        M<UInt32>(texture + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600);
        M<SInt32>(texture + 0x28) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
        M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600) = texture;
        M<UInt8 *>(M<SInt32>(texture + 0x24) + 0x28) = texture;
      }
      this->WriteTextureOffset(uVar75,(UInt32 *)(recordCursor),0,(VendorTextureBuffer *)(texture));
      M<UInt8 *>(self + iVar59 + 0x2a4) = texture;
    }
    else if (opcode == 0x39000000) {
      opcode = recordCursor[1];
      uVar71 = recordCursor[2];
      uVar61 = recordCursor[3];
      uVar55 = recordCursor[4];
      uVar64 = recordCursor[5];
      uVar62 = recordCursor[6];
      uVar58 = recordCursor[7];
      *recordCursor = 0xc0061000;
      M<UInt32>(self + kATIR500GLContext_vertexArrayParam) = uVar71;
      iVar52 = uVar61 + ((opcode & -uVar71) - uVar71) + 1;
      in_cr0 = (iVar52 == 0) << 1;
      if (iVar52 != 0) {
        bVar80 = (uVar61 == 0) << 1;
        iVar48 = 0;
        trailerLastWord = recordCursor + -1;
        iVar59 = 0x10;
        iVar33 = 0;
        iVar74 = 0x20;
        pAVar45 = local_374;
        do {
          if ((!(bool)(bVar80 >> 1 & 1)) && (iVar48 == iVar52 + -1)) {
            iVar59 = 0x20;
          }
          uVar73 = M<UInt32>((SInt32)recordCursor + iVar33 + 0x20);
          if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= uVar73) ||
             (iVar49 = M<SInt32>(uVar73 * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)), iVar49 == 0))
          {
            bVar1 = true;
            uVar63 = 0;
            pendingWords = 0;
            M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) =
                 M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) - reservedWords;
            goto LAB_0002c0b4;
          }
          M<SInt32>(pAVar45) = iVar49;
          iVar49 = iVar59 * 4;
          if (M<UInt8 *>(self + iVar49 + 0x2a4) != (UInt8 *)0x0) {
            ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + iVar49 + 0x2a4)));
            boundTexture = M<UInt8 *>(self + iVar49 + 0x2a4);
            refCountPtr = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
            previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
            if (previousRefCount == 1) {
              ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(boundTexture));
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
            if (pendingWords != 0) {
              gapWords = recordCursor[-1] >> 2;
              if (4 < gapWords) {
                nopHeader = 0x80000000;
                if (gapWords != 5) {
                  nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                }
                recordCursor[-gapWords] = nopHeader;
              }
              recordCursor[-4] = 0x1393;
              recordCursor[-2] = 0x5c8;
              recordCursor[-3] = 0;
              *trailerLastWord = 0x20000;
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
              uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)
                                  ,streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
              submittedWords = pendingWords;
              M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
              reservedWords = 0;
              pendingWords = 0;
              streamOffset = submittedWords * 4 + streamOffset;
            }
            this->alloc_and_load_texture((VendorTextureBuffer *)(M<UInt8 *>(pAVar76)));
            if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
            }
          }
          iVar39 = M<SInt32>(pAVar76);
          refCountPtr = (SInt32 *)(M<SInt32>(iVar39 + 0x14) + 0x10);
          atomicAddReturningOld((SInt32 *)refCountPtr, -0xffff);
          if (M<SInt32>(iVar39 + 0x48) != 0) {
            M<UInt32>(M<SInt32>(iVar39 + 0x24) + 0x28) = M<UInt32>(iVar39 + 0x28);
            M<UInt32>(M<SInt32>(M<SInt32>(pAVar76) + 0x28) + 0x24) =
                 M<UInt32>(M<SInt32>(pAVar76) + 0x24);
            M<UInt32>(M<SInt32>(pAVar76) + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600);
            M<SInt32>(M<SInt32>(pAVar76) + 0x28) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
            M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600) = M<UInt32>(pAVar76);
            M<SInt32>(M<SInt32>(M<SInt32>(pAVar76) + 0x24) + 0x28) = M<SInt32>(pAVar76);
            iVar39 = M<SInt32>(pAVar76);
          }
          M<SInt32>(self + iVar49 + 0x2a4) = iVar39;
          M<UInt32>((SInt32)recordCursor + iVar74) = 0x80000000;
          iVar48 = iVar48 + 1;
          pAVar45 = pAVar45 + 4;
          iVar74 = iVar74 + 4;
          iVar59 = iVar59 + 1;
          iVar33 = iVar33 + 4;
        } while (iVar52 != iVar48);
      }
      bVar1 = false;
LAB_0002c0b4:
      if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
        M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
        this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
      }
      if (!bVar1) {
        uVar73 = opcode + 1 >> 1;
        in_cr0 = (uVar73 == 0) << 1;
        if (uVar73 != 0) {
          bVar80 = (uVar71 == 0) << 1;
          uVar37 = 0;
          puVar69 = recordCursor + uVar64;
          uVar75 = 0;
          pAVar77 = self;
          do {
            uVar71 = *puVar69;
            M<UInt32>(pAVar77 + 0x368) = uVar71;
            if (uVar71 == 0xffffffff) {
              iVar59 = uVar62 * 4;
              uVar62 = uVar62 + 4;
              uVar71 = (SInt32)recordCursor +
                       M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
                       (iVar59 - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)) + 0x20;
            }
            else {
              uVar71 = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(local_374 + uVar37 * 4)),uVar71);
            }
            recordCursor[uVar64] = uVar71;
            if (!(bool)(bVar80 >> 1 & 1)) {
              uVar37 = uVar37 + 1;
            }
            if (uVar37 == opcode) break;
            uVar71 = puVar69[1];
            M<UInt32>(pAVar77 + 0x36c) = uVar71;
            if (uVar71 == 0xffffffff) {
              iVar59 = uVar62 * 4;
              uVar62 = uVar62 + 4;
              uVar71 = (SInt32)recordCursor +
                       M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
                       (iVar59 - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)) + 0x20;
            }
            else {
              uVar71 = this->GetVertexArrayOffset((VendorTextureBuffer *)(M<UInt8 *>(local_374 + uVar37 * 4)),uVar71);
            }
            recordCursor[uVar64 + 1] = uVar71;
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
            iVar52 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(iVar52 + 0x50) +
                     M<SInt32>(M<SInt32>(iVar52 + 0x54) + 4);
          }
          else {
            iVar52 = M<SInt32>(iVar52 + 0x48);
          }
          opcode = recordCursor[uVar58 + 2] + iVar52;
          bVar1 = (opcode & 2) == 0;
          in_cr0 = bVar1 << 1;
          uVar61 = recordCursor[uVar58 + 3];
          if ((!bVar1) && (uVar55 == 2)) {
            uVar61 = uVar61 + 1;
          }
          uVar73 = opcode >> 2 & 7;
          recordCursor[uVar58 + 1] = recordCursor[uVar58 + 1] | uVar73 << 0x10;
          recordCursor[uVar58 + 2] = opcode & 0xffffffe3;
          recordCursor[uVar58 + 3] = uVar61 + uVar73;
        }
      }
      iVar52 = uVar63 << 2;
    }
    else if (opcode == 0x2a000000) {
      switch(recordCursor[1]) {
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
      iVar48 = M<SInt32>(self + kATIR500GLContext_renderToTexture);
      if (iVar48 == 0) {
        iVar74 = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
        iVar33 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
        iVar49 = iVar74 + 1;
        pAVar77 = M<UInt8 *>(iVar59 * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
      }
      else {
        iVar33 = 0;
        iVar74 = 0;
        iVar49 = 1;
        pAVar77 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
      }
      widthPerSample = 0;
      if ((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) != 0) {
        widthPerSample = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
      }
      pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
      if (pitchPixels <= widthPerSample) {
        pitchPixels = widthPerSample;
      }
      opcode = 0x80000000;
      if ((UInt8)pAVar77[0x38] < 2) {
        opcode = 0;
      }
      *recordCursor = opcode | M<SInt32>(pAVar77 + iVar74 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar77 + 0x20)
                          + iVar33 * (M<SInt32>(pAVar77 + iVar49 * 4 + 0x40) -
                                     M<SInt32>(pAVar77 + iVar74 * 4 + 0x40)) + M<SInt32>(pAVar77 + 8)
                          >> 10 | pitchPixels * M<UInt16>(pAVar77 + 0x16) * 0x10000 & 0x3fc00000 |
                          ((UInt8)pAVar77[0x38] & 1) << 0x1e;
      if (iVar48 == 0) {
        pAVar77 = *(UInt8 **)
                   ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
      }
      else {
        surfaceBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
      }
      opcode = 0;
      bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
      in_cr0 = bVar1 << 1;
      if (!bVar1) {
        opcode = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
      }
      pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
      if (pitchPixels <= opcode) {
        pitchPixels = opcode;
      }
      opcode = 0x80000000;
      if ((UInt8)pAVar77[0x38] < 2) {
        opcode = 0;
      }
      recordCursor[1] = opcode | M<SInt32>(pAVar77 + iVar74 * 4 + 0x40) *
                            (UInt32)M<UInt16>(pAVar77 + 0x20) +
                            iVar33 * (M<SInt32>(pAVar77 + iVar49 * 4 + 0x40) -
                                     M<SInt32>(pAVar77 + iVar74 * 4 + 0x40)) + M<SInt32>(pAVar77 + 8)
                            >> 10 | pitchPixels * M<UInt16>(pAVar77 + 0x16) * 0x10000 & 0x3fc00000 |
                            ((UInt8)pAVar77[0x38] & 1) << 0x1e;
      uVar55 = M<UInt32>(self + kATIR500GLContext_scissorX);
      recordCursor[2] = uVar55;
      recordCursor[3] = M<UInt32>(self + kATIR500GLContext_scissorY);
      recordCursor[4] = uVar55;
    }
    else if (opcode < 0x2a000001) {
      if (opcode != 0x1d000000) {
        if (opcode < 0x1d000001) {
          if (opcode != 0x17000000) {
            if (opcode < 0x17000001) {
              if (opcode == 0x4000000) {
                if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                  pAVar77 = (UInt8 *)
                            ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 0x78 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xa8);
                }
                else {
                  pAVar77 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
                }
                uVar58 = recordCursor[1];
                uVar55 = recordCursor[2];
                *recordCursor = 0xc0011000;
                if ((M<UInt32>(pAVar77 + 0x28) & 0x3ff00000) == 0x3ff00000) {
                  *recordCursor = 0xc00b1000;
                }
                else {
                  hzBlockOffset = HZMEM_GetBlockOffset
                                     ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                      M<UInt32>(pAVar77 + 0x28),2);
                  hzBlockCount = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                               M<UInt32>(pAVar77 + 0x28),2);
                  bVar1 = (M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xbe8) & 0x700000) == 0;
                  in_cr0 = bVar1 << 1;
                  if ((bVar1) || (M<SInt16>(self + kIOATIR500GLContext_colorBufferIndex) != 9)) {
                    recordCursor[0xc] = 0;
                  }
                  else {
                    recordCursor[0xc] = 0x600;
                  }
                  recordCursor[8] = hzBlockOffset;
                  iVar59 = M<SInt32>(self + kIOATIR500GLContext_accelerator);
                  recordCursor[9] = hzBlockCount / (UInt32)(M<SInt32>(iVar59 + 0xb98) << 4);
                  iVar59 = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(iVar59 + 0x870)),M<UInt32>(pAVar77 + 0x28),2)
                  ;
                  if (iVar59 == 0) {
                    recordCursor[0xd] = (uVar58 - 2) * 0x10000 | 0xc0001000;
                  }
                  else {
                    iVar59 = M<SInt32>(self + kIOATIR500GLContext_accelerator);
                    uVar15 = M<UInt16>(pAVar77 + 0x1e);
                    iVar48 = 0x10;
                    if ((M<UInt32>(iVar59 + 0xb74) & 0x10000) == 0) {
                      iVar48 = 0xc;
                    }
                    hzBlockCount = 0;
                    bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
                    in_cr0 = bVar1 << 1;
                    if (!bVar1) {
                      hzBlockCount = (UInt32)M<UInt16>(pAVar77 + 0x14) /
                               (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
                    }
                    pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
                    if (0x20 / M<UInt16>(pAVar77 + 0x16) <= hzBlockCount) {
                      pitchPixels = hzBlockCount;
                    }
                    iVar33 = 0x20;
                    if (M<SInt32>(iVar59 + 0xb98) == 4) {
LAB_0002c898:
                      hzBlockCount = iVar33 * ((SInt32)(iVar33 + pitchPixels + -1) / iVar33);
                    }
                    else {
                      iVar33 = M<SInt32>(iVar59 + 0xb98) << 4;
                      in_cr0 = (iVar33 == 0) << 1;
                      hzBlockCount = 0;
                      if (iVar33 != 0) goto LAB_0002c898;
                    }
                    iVar59 = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(iVar59 + 0x870)),
                                                 M<UInt32>(pAVar77 + 0x28),2);
                    dVar31 = DOUBLE_0004c3b8;
                    hzBlockCount = (UInt32)(iVar59 << 4) / hzBlockCount & 0xfffffff0;
                    iStack_1b4 = uVar15 + hzBlockCount;
                    recordCursor[uVar55 + 1] =
                         iVar48 * (uVar15 - hzBlockCount) >> 1 | recordCursor[uVar55 + 1] & 0xffff0000;
                    local_1b8 = 0x43300000;
                    recordCursor[uVar55 + 7] =
                         FBITS((float)(((double)CONCAT44d(0x43300000,iStack_1b4) - DOUBLE_0004c3b0)
                                       * dVar31));
                  }
                  pAVar77[0x36] = 0x1;
                }
                M<UInt32>(pAVar77 + 0x30) = recordCursor[6];
                iVar59 = M<SInt32>(self);
LAB_0002cd2c:
                VCALL(iVar59, 0x5a4)(self);
              }
              else if (opcode < 0x4000001) {
                if (opcode == 0x2000000) {
                  result = 3;
                }
                else if (opcode == 0x3000000) {
                  result = 2;
                }
              }
              else {
                if (opcode == 0x5000000) {
                  pAVar77 = self + kATIR500GLContext_textureDepthBuffer;
                  if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                    pAVar77 = (UInt8 *)
                              ((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xa8
                              );
                  }
                  uVar55 = M<UInt32>(pAVar77 + 0x28);
                  uVar58 = recordCursor[1];
                  uVar64 = recordCursor[2];
                  uVar61 = recordCursor[3];
                  uVar62 = recordCursor[5];
                  if (((uVar55 & 0x3ff) == 0x3ff) || ((uVar55 & 0xffc00) == 0xffc00)) {
                    *recordCursor = (recordCursor[4] - 2) * 0x10000 | 0xc0001000;
                    pAVar77[0x35] = 0x0;
                    pAVar77[0x34] = 0x0;
                  }
                  else {
                    *recordCursor = 0xc0041000;
                    uVar55 = HZMEM_GetBlockOffset
                                       ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),uVar55,0);
                    opcode = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                                 M<UInt32>(pAVar77 + 0x28),0);
                    hzIsPartial = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                             M<UInt32>(pAVar77 + 0x28),0);
                    hzBlockOffset = HZMEM_GetBlockOffset
                                       ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                        M<UInt32>(pAVar77 + 0x28),1);
                    hzBlockCount = HZMEM_GetBlockCount((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                                 M<UInt32>(pAVar77 + 0x28),1);
                    iVar48 = HZMEM_IsPartial((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                             M<UInt32>(pAVar77 + 0x28),1);
                    iVar33 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) *
                             M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb9c);
                    recordCursor[9] = uVar55;
                    recordCursor[10] = opcode / (UInt32)(iVar33 * 0x10);
                    pAVar77[0x34] = 0x1;
                    if (uVar58 == 0) {
                      pAVar77[0x35] = 0x0;
                    }
                    else if ((M<UInt32>(pAVar77 + 0x28) & 0xffc00) == 0xffc00) {
                      M<UInt32>((SInt32)recordCursor + uVar64) = 0xc0021000;
                      pAVar77[0x35] = 0x0;
                    }
                    else {
                      recordCursor[uVar64 + 1] = hzBlockOffset;
                      recordCursor[uVar64 + 2] = hzBlockCount / (UInt32)(iVar33 * 4);
                      pAVar77[0x35] = 0x1;
                    }
                    if ((hzIsPartial == 0) && (iVar48 == 0)) {
                      recordCursor[uVar62 + 1] = recordCursor[uVar62 + 1] & 0xffff0000;
                    }
                    else {
                      uVar75 = 0;
                      iVar48 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
                      hzIsPartial = (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + M<SInt32>(self + kIOATIR500GLContext_boundSurface);
                      if ((M<UInt32>(hzIsPartial + 0xe4) & 0xf00000) != 0) {
                        uVar75 = (UInt32)M<UInt16>(hzIsPartial + 0xbc) /
                                 (M<UInt32>(hzIsPartial + 0xe4) >> 0x14 & 0xf);
                      }
                      uVar37 = 0x20 / M<UInt16>(hzIsPartial + 0xbe);
                      if (uVar37 <= uVar75) {
                        uVar37 = uVar75;
                      }
                      if (iVar48 == 4) {
                        hzIsPartial = 0x20;
LAB_0002cb94:
                        uVar75 = hzIsPartial * ((SInt32)(hzIsPartial + uVar37 + -1) / hzIsPartial);
                      }
                      else {
                        hzIsPartial = iVar48 << 4;
                        uVar75 = 0;
                        if (hzIsPartial != 0) goto LAB_0002cb94;
                      }
                      uVar53 = (UInt32)M<UInt16>(pAVar77 + 0x1e);
                      uVar37 = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74) >> 4 & 3;
                      hzIsPartial = uVar37 * 0x10;
                      iVar33 = hzIsPartial;
                      if (iVar48 == 4) {
                        iVar33 = uVar37 << 5;
                      }
                      if (hzBlockCount < opcode) {
                        opcode = hzBlockCount;
                      }
                      hzBlockCount = 0;
                      if (uVar75 != 0) {
                        hzBlockCount = (opcode * hzIsPartial) / uVar75 & -iVar33;
                      }
                      opcode = 0;
                      if (uVar53 != 0) {
                        opcode = ((recordCursor[uVar62 + 1] & 0xffff) / uVar53) * (uVar53 - hzBlockCount);
                      }
                      local_378 = (UInt8 *)0x0;
                      bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf000) == 0;
                      in_cr0 = bVar1 << 1;
                      if (!bVar1) {
                        iStack_1ac = hzBlockCount + uVar53;
                        local_1b0 = 0x43300000;
                        local_1a8 = 0x43300000;
                        uStack_1a4 = M<UInt32>(pAVar77 + 0x3c) >> 0xc & 0xf ^ 0x80000000;
                        fVar4 = (float)((double)CONCAT44d(0x43300000,uStack_1a4) - DOUBLE_0004c3a8);
                        local_378 = (UInt8 *)FBITS((float)((double)CONCAT44d(0x43300000,iStack_1ac) - DOUBLE_0004c3b0) / (fVar4 + fVar4));   /* a float kept in a pointer-typed stack slot */
                      }
                      recordCursor[uVar62 + 1] = opcode | recordCursor[uVar62 + 1] & 0xffff0000;
                      recordCursor[uVar62 + 7] = (UInt32)local_378;
                    }
                  }
                  M<UInt32>(pAVar77 + 0x2c) = recordCursor[uVar61];
                  if ((M<SInt32>(self + kATIR500GLContext_renderToTexture) != 0) && (M<SInt32>(self + kATIR500GLContext_renderTargetTexture) != 0)) {
                    M<UInt32>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x7c) = recordCursor[uVar61];
                    M<UInt16>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x7a) =
                         CONCAT11(pAVar77[0x35],pAVar77[0x34]);
                  }
                  iVar59 = M<SInt32>(self);
                  goto LAB_0002cd2c;
                }
                if (opcode == 0x16000000) goto LAB_0002e820;
              }
              goto LAB_00031340;
            }
            if (opcode != 0x1a000000) {
              if (opcode < 0x1a000001) {
                if ((opcode == 0x18000000) || (opcode == 0x19000000)) goto LAB_0002e820;
              }
              else if ((opcode == 0x1b000000) || (opcode == 0x1c000000)) goto LAB_0002e820;
              goto LAB_00031340;
            }
          }
        }
        else if (opcode != 0x23000000) {
          if (0x23000000 < opcode) {
            if (opcode == 0x26000000) {
              if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[1]) ||
                 (texture = *(UInt8 **)
                             (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture == (UInt8 *)0x0)) goto LAB_00030d40;
              pVVar51 = M<UInt8 *>(self + kATIR500GLContext_transferBufferSlot);
              local_378 = texture;
              if (pVVar51 != texture) {
                if (pVVar51 != (UInt8 *)0x0) {
                  M<UInt32>(M<SInt32>(pVVar51 + 0x14) + 8) =
                       M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
                  M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) =
                       M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) + -1;
                }
                M<SInt16>(texture + 0xe) = M<SInt16>(texture + 0xe) + 1;
                M<UInt8 *>(self + kATIR500GLContext_transferBufferSlot) = texture;
              }
              if (M<SInt32>(texture + 4) == 0) {
                if (pendingWords != 0) {
                  gapWords = recordCursor[-1] >> 2;
                  if (4 < gapWords) {
                    nopHeader = 0x80000000;
                    if (gapWords != 5) {
                      nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                    }
                    recordCursor[-gapWords] = nopHeader;
                  }
                  recordCursor[-4] = 0x1393;
                  recordCursor[-3] = 0;
                  recordCursor[-2] = 0x5c8;
                  recordCursor[-1] = 0x20000;
                  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                       pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
                  uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                               0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                      pendingWords);
                  submittedWords = pendingWords;
                  M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
                  reservedWords = 0;
                  pendingWords = 0;
                  streamOffset = submittedWords * 4 + streamOffset;
                }
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)local_378));
                if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                }
              }
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
              recordCursor[5] = M<SInt32>(local_378 + 4) + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) +
                           recordCursor[5] + 0x80;
            }
            else if (opcode < 0x26000001) {
              if ((opcode == 0x24000000) || (opcode == 0x25000000)) goto LAB_0002e820;
            }
            else if (opcode == 0x28000000) {
              if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                iVar33 = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
                iVar59 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
                iVar48 = iVar33 + 1;
                pAVar77 = *(UInt8 **)
                           ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
              }
              else {
                iVar59 = 0;
                iVar33 = 0;
                iVar48 = 1;
                pAVar77 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
              }
              *recordCursor = 0x105bb;
              recordCursor[1] = M<UInt32>(self + kATIR500GLContext_scissorY);
              recordCursor[2] = M<UInt32>(self + kATIR500GLContext_scissorX);
              opcode = 0;
              iVar33 = M<SInt32>(pAVar77 + iVar33 * 4 + 0x40);
              iVar74 = M<SInt32>(pAVar77 + iVar48 * 4 + 0x40);
              uVar15 = M<UInt16>(pAVar77 + 0x20);
              iVar48 = M<SInt32>(pAVar77 + 8);
              bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                opcode = (UInt32)M<UInt16>(pAVar77 + 0x14) /
                         (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
              }
              uVar14 = M<UInt16>(pAVar77 + 0x16);
              uVar73 = 0x20 / uVar14;
              if (uVar73 <= opcode) {
                uVar73 = opcode;
              }
              AVar10 = pAVar77[0x38];
              opcode = 0x80000000;
              if ((UInt8)AVar10 < 2) {
                opcode = 0;
              }
              recordCursor[3] = 0x50b;
              recordCursor[4] = opcode | iVar33 * (UInt32)uVar15 + iVar59 * (iVar74 - iVar33) + iVar48 >>
                                    10 | uVar73 * uVar14 * 0x10000 & 0x3fc00000 |
                                    ((UInt8)AVar10 & 1) << 0x1e;
            }
            else if (opcode == 0x29000000) {
              if (M<SInt32>(self + kATIR500GLContext_renderToTexture) != 0) {
                M<UInt32>(self + kATIR500GLContext_renderToTexture) = 0;
              }
              opcode = 0;
              iVar59 = 4;
              M<UInt16>(self + kATIR500GLContext_attachmentCount) = 0;
              pAVar77 = self;
              puVar69 = recordCursor;
              do {
                switch(puVar69[1]) {
                case 0:
                  uVar73 = opcode & 0xffff;
                  opcode = uVar73 + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)opcode;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 1;
                  break;
                case 1:
                  uVar73 = opcode & 0xffff;
                  opcode = uVar73 + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)opcode;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 0;
                  break;
                case 2:
                  uVar73 = opcode & 0xffff;
                  opcode = uVar73 + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)opcode;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 4;
                  break;
                case 3:
                  uVar73 = opcode & 0xffff;
                  opcode = uVar73 + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)opcode;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 5;
                  break;
                case 7:
                  uVar73 = opcode & 0xffff;
                  opcode = uVar73 + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)opcode;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 2;
                  break;
                case 8:
                  uVar73 = opcode & 0xffff;
                  opcode = uVar73 + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)opcode;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 3;
                  break;
                case 0x10:
                  uVar73 = opcode & 0xffff;
                  opcode = uVar73 + 1;
                  M<SInt16>(self + kATIR500GLContext_attachmentCount) = (SInt16)opcode;
                  M<UInt16>(self + uVar73 * 2 + 0x3aa) = 9;
                  break;
                case 0x11:
                  M<UInt16>(pAVar77 + 0x3aa) = 0x17;
                }
                iVar59 = iVar59 + -1;
                puVar69 = puVar69 + 1;
                pAVar77 = pAVar77 + 2;
              } while (iVar59 != 0);
              if ((opcode & 0xffff) == 0) {
                M<UInt16>(self + kATIR500GLContext_attachmentCount) = 1;
                M<UInt16>(self + kATIR500GLContext_attachmentBufferIds) = 1;
              }
              M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = M<UInt16>(self + kATIR500GLContext_attachmentBufferIds);
              M<UInt32>(self + kATIR500GLContext_renderBufferIndex) = (UInt32)M<UInt16>(self + kATIR500GLContext_attachmentBufferIds);
              if (recordCursor[5] == 0x10) {
                M<UInt16>(self + kATIR500GLContext_attachmentBufferIds) = 9;
                M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = 9;
              }
              bVar1 = (M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) & 0x80) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                uVar55 = recordCursor[1];
                if ((uVar55 == 7) || (uVar55 == 8)) {
                  M<SInt16>(self + kIOATIR500GLContext_depthBufferIndex) = (SInt16)uVar55;
                }
                else {
                  M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) = 6;
                }
              }
              VCALL(M<SInt32>(self), 0x5a4)(self);
              this->build_scissor();
              this->write_kernel_context_buffer_regs((UInt32 *)(recordCursor),0,recordCursor[6],recordCursor[7]);
            }
            else if (opcode == 0x27000000) {
              if (M<SInt32>(self + kATIR500GLContext_transferBufferSlot) != 0) {
                M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0x14) + 8) =
                     M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
                M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) =
                     M<SInt16>(M<SInt32>(self + kATIR500GLContext_transferBufferSlot) + 0xe) + -1;
                M<UInt32>(self + kATIR500GLContext_transferBufferSlot) = 0;
              }
              goto LAB_0002eae8;
            }
            goto LAB_00031340;
          }
          if (opcode != 0x20000000) {
            if (opcode < 0x20000001) {
              if ((opcode == 0x1e000000) || (opcode == 0x1f000000)) goto LAB_0002e820;
            }
            else if ((opcode == 0x21000000) || (opcode == 0x22000000)) goto LAB_0002e820;
            goto LAB_00031340;
          }
        }
      }
LAB_0002e820:
      opcode = opcode + 0xea000000 >> 0x16;
      if (M<UInt8 *>(self + opcode + 0x2a4) != (UInt8 *)0x0) {
        ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + opcode + 0x2a4)));
        boundTexture = M<UInt8 *>(self + opcode + 0x2a4);
        refCountPtr = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
        previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
        if (previousRefCount == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(boundTexture));
        }
        M<UInt32>(self + opcode + 0x2a4) = 0;
      }
LAB_0002eae8:
      *recordCursor = 0x80000000;
    }
    else {
      if (opcode == 0x37000000) {
        iVar59 = M<SInt32>(self + kATIR500GLContext_textureSlots);
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
            uVar73 = recordCursor[3] & 0xffff;
            opcode = recordCursor[3] >> 0x10;
            puVar67 = recordCursor + uVar73;
            uVar75 = recordCursor[2];
            *recordCursor = (opcode + uVar73 + 2) * 0x10000 | 0xc0001000;
            puVar67[opcode + 0xf] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
            puVar69 = recordCursor;
            if (bVar1) {
              for (; uVar73 != 0; uVar73 = uVar73 - 1) {
                uVar55 = puVar69[4];
                uVar37 = 0;
                uVar75 = recordCursor[uVar55];
                iVar33 = (uVar75 & 0xffff) * 4 + iVar48;
                iVar59 = M<SInt32>(iVar33 + 0x40);
                recordCursor[uVar55] =
                     iVar59 * (UInt32)M<UInt16>(iVar48 + 0x20) +
                     (uVar75 >> 0x10) * (M<SInt32>(iVar33 + 0x44) - iVar59) + M<SInt32>(iVar48 + 8);
                bVar1 = (M<UInt32>(iVar48 + 0x3c) & 0xf00000) == 0;
                in_cr0 = bVar1 << 1;
                iVar59 = (UInt32)M<UInt8>(iVar48 + 0x3a) * 0x1c;
                if (!bVar1) {
                  uVar37 = (SInt32)((UInt32)M<UInt16>(iVar48 + 0x14) /
                                (M<UInt32>(iVar48 + 0x3c) >> 0x14 & 0xf)) >> (uVar75 & 0x3f);
                }
                pitchPixels = 0x20 / M<UInt16>(iVar48 + 0x16);
                if (pitchPixels <= uVar37) {
                  pitchPixels = uVar37;
                }
                local_c8 = FormatTableLookup_0x0004d2e0(iVar59) >> 1 & 0x1e00000 |
                           (FormatTableLookup_0x0004d2dc(iVar59) & 0xc00) << 9 |
                           (M<UInt8>(iVar48 + 0x38) & 6) << 0x10 |
                           (M<UInt8>(iVar48 + 0x38) & 1) << 0x10 |
                           pitchPixels & 0x3ffe | local_c8 & 0xfe00c001;
                recordCursor[uVar55 + 2] = local_c8;
                puVar69 = puVar69 + 1;
              }
              for (; opcode != 0; opcode = opcode - 1) {
                puVar69 = puVar67 + 4;
                puVar67 = puVar67 + 1;
                iVar33 = (recordCursor[*puVar69] & 0xffff) * 4 + iVar48;
                iVar59 = M<SInt32>(iVar33 + 0x40);
                recordCursor[*puVar69] =
                     M<UInt8>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0x15) & 0x1f |
                     iVar59 * (UInt32)M<UInt16>(iVar48 + 0x20) +
                     (recordCursor[*puVar69] >> 0x10) * (M<SInt32>(iVar33 + 0x44) - iVar59) +
                     M<SInt32>(iVar48 + 8) & 0xffffffe0;
              }
            }
            else {
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
              for (; uVar73 != 0; uVar73 = uVar73 - 1) {
                puVar3 = puVar69 + 4;
                puVar69 = puVar69 + 1;
                recordCursor[*puVar3] = textureOffset + recordCursor[*puVar3];
              }
              for (; opcode != 0; opcode = opcode - 1) {
                puVar69 = puVar67 + 4;
                puVar67 = puVar67 + 1;
                recordCursor[*puVar69] =
                     M<UInt8>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0x15) & 0x1f |
                     textureOffset + recordCursor[*puVar69] & 0xffffffe0;
              }
              iVar59 = (uVar75 >> 0x10) * 2;
              iVar48 = iVar59 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              uVar15 = (UInt16)((1 << (uVar75 & 0x3f)) + -1 << (uVar75 >> 8 & 0x3f));
              M<UInt16>(iVar48 + 0x28) = uVar15 | M<UInt16>(iVar48 + 0x28);
              iVar59 = iVar59 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~uVar15;
              M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0xc) =
                   M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
            }
            goto LAB_00031340;
          }
        }
LAB_0002f978:
        *recordCursor = (recordCursor[1] - 2) * 0x10000 | 0xc0001000;
        goto LAB_00031340;
      }
      if (0x37000000 < opcode) {
        if (opcode == 0x3f000000) {
          uVar55 = recordCursor[3];
          if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[2]) ||
             (texture = *(UInt8 **)
                         (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
             texture == (UInt8 *)0x0)) goto LAB_00030fe0;
          local_378 = texture;
          ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
          if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
            if (pendingWords != 0) {
              gapWords = recordCursor[-1] >> 2;
              if (4 < gapWords) {
                nopHeader = 0x80000000;
                if (gapWords != 5) {
                  nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                }
                recordCursor[-gapWords] = nopHeader;
              }
              recordCursor[-4] = 0x1393;
              recordCursor[-3] = 0;
              recordCursor[-2] = 0x5c8;
              recordCursor[-1] = 0x20000;
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
              uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)
                                  ,streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
              submittedWords = pendingWords;
              M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
              pendingWords = 0;
              streamOffset = submittedWords * 4 + streamOffset;
            }
            this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
            if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
              M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
              this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
            }
            if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
            }
          }
          *recordCursor = 0xc0021000;
          recordCursor[0xf] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
          if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
            pAVar77 = *(UInt8 **)
                       (M<SInt32>(self + kATIR500GLContext_renderBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
          }
          else {
            pAVar77 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
          }
          opcode = 0;
          formatByteOffset = (UInt32)(UInt8)pAVar77[0x3a] * 0x1c;
          recordCursor[0x9e] =
               (UInt32)M<UInt16>(pAVar77 + 0x20) * M<SInt32>(pAVar77 + 0x40) + M<SInt32>(pAVar77 + 8)
               & 0xffffffe0;
          if ((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) != 0) {
            opcode = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf);
          }
          pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
          if (0x20 / M<UInt16>(pAVar77 + 0x16) <= opcode) {
            pitchPixels = opcode;
          }
          uVar53 = recordCursor[0x8e];
          recordCursor[0xa0] =
               pitchPixels & 0x3ffe | ((UInt8)pAVar77[0x38] & 1) << 0x10 |
               ((UInt8)pAVar77[0x38] & 6) << 0x10 | ((UInt8)pAVar77[0x39] & 3) << 0x13 |
               FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar77[0x3a] * 0x1c) >> 1 & 0x1e00000;
          formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
          recordCursor[0x8e] = formatFieldE0 | uVar53 & 0xffffffe0;
          uVar73 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
          recordCursor[0x8e] = uVar73 | formatFieldE0 | uVar53 & 0xfffffce0;
          uVar75 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
          recordCursor[0x8e] = uVar75 | uVar73 | formatFieldE0 | uVar53 & 0xfffff0e0;
          uVar37 = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
          recordCursor[0x8e] = uVar37 | uVar75 | uVar73 | formatFieldE0 | uVar53 & 0xffffc0e0;
          recordCursor[0x8e] =
               (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
               uVar37 | uVar75 | uVar73 | formatFieldE0 | uVar53 & 0xffff00e0;
          bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
          in_cr0 = bVar1 << 1;
          if ((bVar1) ||
             (uVar73 = (UInt32)M<UInt16>(pAVar77 + 0x1c) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)
             , opcode = uVar73 - 1, uVar73 == 0)) {
            opcode = 0;
          }
          maxY = 0;
          if (M<UInt16>(pAVar77 + 0x1e) != 0) {
            maxY = M<UInt16>(pAVar77 + 0x1e) - 1;
          }
          recordCursor[0xb7] = opcode & 0x1fff | (maxY & 0x1fff) << 0xd;
          vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
          recordCursor[0xa4] =
               vertexArrayOffset + (recordCursor[0xa4] >> 3 & 0x1ffffffc) & 0xffffffe0 | recordCursor[0xa4] & 0x1f;
LAB_00030964:
          ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(local_378));
          refCountPtr = (SInt32 *)(M<SInt32>(local_378 + 0x14) + 0x10);
          previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -0x10000);
          if (previousRefCount == 1) {
LAB_00030994:
            ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(local_378));
          }
          goto LAB_00031340;
        }
        if (opcode < 0x3f000001) {
          if (opcode == 0x3b000000) {
            uVar55 = recordCursor[2];
            uVar58 = recordCursor[3];
            opcode = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
            if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= recordCursor[1]) ||
               (texture = *(UInt8 **)
                           (recordCursor[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
               texture == (UInt8 *)0x0)) goto LAB_00030fe0;
            local_378 = texture;
            if (M<UInt8 *>(self + kATIR500GLContext_streamedTexture) != (UInt8 *)0x0) {
              ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_streamedTexture)));
              texture = M<UInt8 *>(self + kATIR500GLContext_streamedTexture);
              refCountPtr = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
              previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
              if (previousRefCount == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(texture));
              }
            }
            ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(local_378));
            if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
              if (pendingWords != 0) {
                gapWords = recordCursor[-1] >> 2;
                if (4 < gapWords) {
                  nopHeader = 0x80000000;
                  if (gapWords != 5) {
                    nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                  }
                  recordCursor[-gapWords] = nopHeader;
                }
                recordCursor[-4] = 0x1393;
                recordCursor[-3] = 0;
                recordCursor[-2] = 0x5c8;
                recordCursor[-1] = 0x20000;
                M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                     pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                             0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                    pendingWords);
                submittedWords = pendingWords;
                M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
                pendingWords = 0;
                streamOffset = submittedWords * 4 + streamOffset;
              }
              this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
              if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
                M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
                this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
              }
              if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
              }
            }
            texture = local_378;
            uVar55 = this->GetQueryOffset((VendorTextureBuffer *)(local_378),uVar58,uVar55);
            *recordCursor = 0x80000000;
            recordCursor[1] = 0x80000000;
            recordCursor[2] = 0x80000000;
            recordCursor[3] = 0x80000000;
            if ((opcode == 1) && (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb9c) == 2)) {
              recordCursor[9] = uVar55;
              recordCursor[0xd] = uVar55 + 0x10;
            }
            else {
              recordCursor[7] = uVar55;
              if (1 < opcode) {
                recordCursor[0xb] = uVar55 + 0x10;
              }
              if (2 < opcode) {
                recordCursor[0xf] = uVar55 + 8;
              }
              if (3 < opcode) {
                recordCursor[0x13] = uVar55 + 0xc;
              }
            }
            refCountPtr = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
            atomicAddReturningOld((SInt32 *)refCountPtr, -0xffff);
            if (M<SInt32>(texture + 0x48) != 0) {
              M<UInt32>(M<SInt32>(texture + 0x24) + 0x28) = M<UInt32>(texture + 0x28);
              M<UInt32>(M<SInt32>(local_378 + 0x28) + 0x24) = M<UInt32>(local_378 + 0x24)
              ;
              M<UInt32>(local_378 + 0x24) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600);
              M<SInt32>(local_378 + 0x28) = M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x5dc;
              M<UInt8 *>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x600) = local_378;
              M<UInt8 *>(M<SInt32>(local_378 + 0x24) + 0x28) = local_378;
              texture = local_378;
            }
            M<UInt8 *>(self + kATIR500GLContext_streamedTexture) = texture;
          }
          else if (opcode < 0x3b000001) {
            if (opcode == 0x38000000) {
              opcode = recordCursor[1] + 1 >> 1;
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
              recordCursor[2] = 0x80000000;
              recordCursor[3] = 0x80000000;
              iVar59 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
                       (recordCursor[2] * 4 - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)) + 0x20;
              if (opcode != 0) {
                iVar48 = 6;
                iVar33 = 0x1c;
                puVar69 = recordCursor;
                do {
                  recordCursor[iVar48] = (SInt32)recordCursor + puVar69[6] * 4 + iVar59;
                  M<UInt32>((SInt32)recordCursor + iVar33) = (SInt32)recordCursor + puVar69[7] * 4 + iVar59;
                  puVar69 = puVar69 + 3;
                  iVar48 = iVar48 + 3;
                  iVar33 = iVar33 + 0xc;
                  opcode = opcode - 1;
                } while (opcode != 0);
              }
            }
            else if (opcode == 0x3a000000) {
              pAVar77 = self;
              do {
                if (M<UInt8 *>(pAVar77 + 0x2e4) != (UInt8 *)0x0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(pAVar77 + 0x2e4)));
                  pVVar70 = M<UInt8 *>(pAVar77 + 0x2e4);
                  refCountPtr = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
                  previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
                  if (previousRefCount == 1) {
                    ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(pVVar70));
                  }
                  M<UInt32>(pAVar77 + 0x2e4) = 0;
                }
                pAVar77 = pAVar77 + 4;
              } while (self + 0x44 != pAVar77);
              goto LAB_0002eae8;
            }
          }
          else if (opcode == 0x3d000000) {
            if (recordCursor[1] == 0x132) {
              uVar55 = recordCursor[2];
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
              recordCursor[2] = 0x80000000;
              recordCursor[3] = 0x80000000;
              if (M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) != (UInt8 *)0x0) {
                ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->set_volatile_state((eSurfaceVolatileState)(uVar55));
              }
            }
            else {
              *recordCursor = 0x80000000;
              recordCursor[1] = 0x80000000;
            }
          }
          else if (opcode == 0x3e000000) {
            iVar59 = M<SInt32>(self + kATIR500GLContext_textureSlots);
            if ((iVar59 != 0) &&
               ((M<char>(iVar59 + 0x20) == '\x06' || (M<SInt32>(iVar59 + 0x48) != 0)))) {
              opcode = recordCursor[4];
              uVar55 = recordCursor[3];
              if ((recordCursor[2] < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
                 (texture = *(UInt8 **)
                             (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture != (UInt8 *)0x0)) {
                local_378 = texture;
                ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
                if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
                  if (pendingWords != 0) {
                    gapWords = recordCursor[-1] >> 2;
                    if (4 < gapWords) {
                      nopHeader = 0x80000000;
                      if (gapWords != 5) {
                        nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                      }
                      recordCursor[-gapWords] = nopHeader;
                    }
                    recordCursor[-4] = 0x1393;
                    recordCursor[-3] = 0;
                    recordCursor[-2] = 0x5c8;
                    recordCursor[-1] = 0x20000;
                    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                         pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                    uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                                 0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                        pendingWords);
                    submittedWords = pendingWords;
                    M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
                    pendingWords = 0;
                    streamOffset = submittedWords * 4 + streamOffset;
                  }
                  this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
                  if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
                    M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
                    this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
                  }
                  if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                  }
                }
                iVar59 = (opcode >> 0x10) * 2;
                levelBit = (UInt16)(1 << (opcode & 0x3f));
                iVar48 = iVar59 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
                M<UInt16>(iVar48 + 0x28) = levelBit | M<UInt16>(iVar48 + 0x28);
                iVar59 = iVar59 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
                M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~levelBit;
                *recordCursor = 0xc0031000;
                uVar58 = recordCursor[0x9f];
                recordCursor[0x10] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
                textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
                recordCursor[0x9f] = uVar58 + textureOffset;
                vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
                recordCursor[0xa5] =
                     vertexArrayOffset + (recordCursor[0xa5] >> 3 & 0x1ffffffc) & 0xffffffe0 | recordCursor[0xa5] & 0x1f;
                M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0xc) =
                     M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
                goto LAB_00030318;
              }
              goto LAB_00030fe0;
            }
LAB_000300b8:
            opcode = 0x80000000;
            if (recordCursor[1] != 1) {
              opcode = (recordCursor[1] - 2) * 0x10000 | 0xc0001000;
            }
            *recordCursor = opcode;
          }
        }
        else {
          if (opcode == 0x43000000) {
            uVar55 = recordCursor[3];
            *recordCursor = 0xc0021000;
            if ((recordCursor[2] < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
               (texture = *(UInt8 **)
                           (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
               texture != (UInt8 *)0x0)) {
              local_378 = texture;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
              if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
                if (pendingWords != 0) {
                  gapWords = recordCursor[-1] >> 2;
                  if (4 < gapWords) {
                    nopHeader = 0x80000000;
                    if (gapWords != 5) {
                      nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                    }
                    recordCursor[-gapWords] = nopHeader;
                  }
                  recordCursor[-4] = 0x1393;
                  recordCursor[-3] = 0;
                  recordCursor[-2] = 0x5c8;
                  recordCursor[-1] = 0x20000;
                  M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                       pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                  uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                               0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                      pendingWords);
                  submittedWords = pendingWords;
                  M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
                  pendingWords = 0;
                  streamOffset = submittedWords * 4 + streamOffset;
                }
                this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
                if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb90) != 0) {
                  M<UInt32 *>((UInt8 *)&trackBlk + 0x140) = recordCursor;
                  this->restore_state_destroyed_by_pageoff((register_tracking_state *)(trackingState));
                }
                if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                  ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                }
              }
              M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x28) =
                   M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x28) | 1;
              M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x1c) =
                   M<UInt16>(M<SInt32>(local_378 + 0x14) + 0x1c) & 0xfffe;
              vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
              recordCursor[0x15] = vertexArrayOffset + recordCursor[0x15];
              M<UInt32>(M<SInt32>(local_378 + 0x14) + 0xc) =
                   M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
              if (local_378[0x20] == 0x7) {
                M<UInt32>(M<SInt32>(M<SInt32>(local_378 + 0x58) + 0x14) + 8) =
                     M<UInt32>(M<SInt32>(local_378 + 0x14) + 0xc);
              }
LAB_00030318:
              ((IOATIR500GLContext *)(self))->remove_texture_from_stream((VendorTextureBuffer *)(local_378));
              refCountPtr = (SInt32 *)(M<SInt32>(local_378 + 0x14) + 0x10);
              previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -0x10000);
              if (previousRefCount == 0x10000) goto LAB_00030994;
            }
            else {
LAB_00030fe0:
              pendingWords = 0;
              uVar63 = 0;
              iVar52 = 0;
            }
            goto LAB_00031340;
          }
          if (opcode < 0x43000001) {
            if (opcode == 0x40000000) {
              uVar55 = recordCursor[3];
              uVar58 = recordCursor[4];
              if ((recordCursor[2] < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
                 (texture = *(UInt8 **)
                             (recordCursor[2] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture != (UInt8 *)0x0)) {
                local_378 = texture;
                ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
                if (M<char>(M<SInt32>(local_378 + 0x14) + 0x14) != '\0') {
                  if (pendingWords != 0) {
                    gapWords = recordCursor[-1] >> 2;
                    if (4 < gapWords) {
                      nopHeader = 0x80000000;
                      if (gapWords != 5) {
                        nopHeader = (gapWords - 6) * 0x10000 | 0xc0001000;
                      }
                      recordCursor[-gapWords] = nopHeader;
                    }
                    recordCursor[-4] = 0x1393;
                    recordCursor[-3] = 0;
                    recordCursor[-2] = 0x5c8;
                    recordCursor[-1] = 0x20000;
                    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                         pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
                    uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) +
                                                 0x20),streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,
                                        pendingWords);
                    submittedWords = pendingWords;
                    M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
                    pendingWords = 0;
                    streamOffset = submittedWords * 4 + streamOffset;
                  }
                  this->alloc_and_load_texture((VendorTextureBuffer *)(local_378));
                  if (M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0) {
                    ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
                  }
                }
                *recordCursor = 0xc0031000;
                recordCursor[0x10] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
                if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                  pAVar77 = M<UInt8 *>(uVar58 * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
                }
                else {
                  pAVar77 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
                }
                AVar10 = pAVar77[0x3a];
                recordCursor[0xa5] =
                     ((UInt8)pAVar77[0x38] & 7) << 2 |
                     (UInt32)M<UInt16>(pAVar77 + 0x20) * M<SInt32>(pAVar77 + 0x40) +
                     M<SInt32>(pAVar77 + 8) & 0xffffffe0;
                if (((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0) ||
                   (uVar73 = (UInt32)M<UInt16>(pAVar77 + 0x1c) /
                             (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf), opcode = uVar73 - 1,
                   uVar73 == 0)) {
                  opcode = 0;
                }
                maxY = 0;
                if (M<UInt16>(pAVar77 + 0x1e) != 0) {
                  maxY = M<UInt16>(pAVar77 + 0x1e) - 1;
                }
                recordCursor[0xab] = opcode & 0x7ff | (maxY & 0x7ff) << 0xb | 0x80000000;
                formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar10 * 0x1c);
                recordCursor[0xad] =
                     formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
                     formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
                opcode = M<UInt32>(pAVar77 + 0x3c);
                bVar1 = (opcode & 0xf00000) == 0;
                in_cr0 = bVar1 << 1;
                if (bVar1) {
                  maxY = 0;
                }
                else {
                  maxY = (UInt32)M<UInt16>(pAVar77 + 0x14) / (opcode >> 0x14 & 0xf);
                }
                pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
                if (0x20 / M<UInt16>(pAVar77 + 0x16) <= maxY) {
                  pitchPixels = maxY;
                }
                if ((bVar1) ||
                   (uVar73 = (UInt32)M<UInt16>(pAVar77 + 0x1c) / (opcode >> 0x14 & 0xf),
                   opcode = uVar73 - 1, uVar73 == 0)) {
                  opcode = 0;
                }
                maxY = 0;
                if (M<UInt16>(pAVar77 + 0x1e) != 0) {
                  maxY = M<UInt16>(pAVar77 + 0x1e) - 1;
                }
                recordCursor[0xaf] = pitchPixels - 1 & 0x3fff | (opcode & 0x800) << 4 | (maxY & 0x800) << 5;
                vertexArrayOffset = this->GetVertexArrayOffset((VendorTextureBuffer *)(local_378),uVar55);
                recordCursor[0x9f] = vertexArrayOffset + recordCursor[0x9f];
                goto LAB_00030964;
              }
              goto LAB_00030fe0;
            }
            if (opcode != 0x41000000) goto LAB_00031340;
            uVar55 = recordCursor[1];
            iVar52 = 4;
            pAVar77 = self;
            do {
              M<UInt16>(pAVar77 + 0x3b2) = 0;
              pAVar77 = pAVar77 + 2;
              iVar52 = iVar52 + -1;
            } while (iVar52 != 0);
            uVar58 = recordCursor[4];
            uVar61 = recordCursor[5];
            M<UInt16>(self + kATIR500GLContext_attachmentCount) = 0;
            if (uVar55 == 0) {
              puVar54 = recordCursor + 6;
              iVar59 = 6;
              iVar52 = 0x18;
            }
            else {
              local_c0 = self + kATIR500GLContext_unitBuffers;
              uVar62 = 0;
              iVar59 = 6;
              iVar52 = 0x18;
              pAVar77 = self;
              pAVar72 = self;
              puVar42 = recordCursor;
              do {
                puVar54 = puVar42 + 6;
                local_37c = (UInt8 *)0x0;
                M<SInt16>(pAVar77 + 0x3dc) = (SInt16)recordCursor[2];
                M<SInt16>(pAVar77 + 0x3de) = (SInt16)recordCursor[3];
                if (M<SInt32>(pAVar72 + 0x338) != 0) {
                  iVar48 = M<SInt32>(M<SInt32>(pAVar72 + 0x338) + 0x14);
                  M<SInt16>(iVar48 + 0x36) = M<SInt16>(iVar48 + 0x36) + -1;
                  ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(pAVar72 + 0x338)));
                  pVVar70 = M<UInt8 *>(pAVar72 + 0x338);
                  refCountPtr = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
                  previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
                  if (previousRefCount == 1) {
                    ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(pVVar70));
                  }
                  M<UInt32>(pAVar72 + 0x338) = 0;
                }
                uVar63 = M<UInt32>((SInt32)recordCursor + iVar52);
                if (uVar63 != 0xffffffff) {
                  uVar15 = M<UInt16>(self + kATIR500GLContext_attachmentCount);
                  if (uVar15 < 4) {
                    M<UInt16>(self + kATIR500GLContext_attachmentCount) = uVar15 + 1;
                    M<SInt16>(self + (UInt32)uVar15 * 2 + 0x3b2) = (SInt16)uVar62;
                    uVar63 = M<UInt32>((SInt32)recordCursor + iVar52);
                  }
                  if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= uVar63) ||
                     (texture = *(UInt8 **)
                                   (uVar63 * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                     texture == (UInt8 *)0x0)) {
                    uVar73 = 0;
                    pendingWords = 0;
                    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) =
                         M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) - reservedWords;
                    goto LAB_0002e114;
                  }
                  ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
                  this->get_texture((UInt32 *)(recordCursor),(VendorTextureBuffer *)(texture),(UInt32 *)(&streamOffset),(UInt32 *)(&pendingWords),(UInt32 *)(&reservedWords),(register_tracking_state *)(trackingState));
                  uVar63 = puVar42[10] >> 0xf & 0x1fffe;
                  uVar15 = (UInt16)(1 << (puVar42[10] & 0x3f));
                  M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) =
                       M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) + 1;
                  iVar48 = uVar63 + M<SInt32>(texture + 0x14);
                  M<UInt16>(iVar48 + 0x28) = uVar15 | M<UInt16>(iVar48 + 0x28);
                  iVar48 = uVar63 + M<SInt32>(texture + 0x14);
                  M<UInt16>(iVar48 + 0x1c) = M<UInt16>(iVar48 + 0x1c) & ~uVar15;
                  this->build_surface_from_texture((VendorTextureBuffer *)(texture),(ATIR500SurfaceBuffer *)((UInt8 *)local_c0),
                             M<UInt16>((SInt32)recordCursor + 10),M<UInt16>((SInt32)recordCursor + 0xe),
                             M<UInt8>((SInt32)puVar42 + 0x2f),puVar42[7],
                             M<UInt16>((SInt32)puVar42 + 0x22));
                  M<UInt8 *>(pAVar72 + 0x338) = texture;
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
              puVar54 = recordCursor + iVar59;
            }
LAB_0002e114:
            if (M<SInt16>(self + kATIR500GLContext_attachmentCount) == 0) {
              M<UInt16>(self + kATIR500GLContext_currentAttachment) = 0;
              M<UInt16>(self + kATIR500GLContext_attachmentCount) = 1;
            }
            local_37c = (UInt8 *)0x0;
            M<UInt32>(self + kATIR500GLContext_hzMemoryHandle) = 0xffffffff;
            if (M<SInt32>(self + kATIR500GLContext_renderTargetTexture) != 0) {
              iVar48 = M<SInt32>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x14);
              M<SInt16>(iVar48 + 0x36) = M<SInt16>(iVar48 + 0x36) + -1;
              ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture)));
              pVVar70 = M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture);
              refCountPtr = (SInt32 *)(M<SInt32>(pVVar70 + 0x14) + 0x10);
              previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
              if (previousRefCount == 1) {
                ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(pVVar70));
              }
              M<UInt32>(self + kATIR500GLContext_renderTargetTexture) = 0;
            }
            uVar63 = *puVar54;
            if (uVar63 != 0xffffffff) {
              if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= uVar63) ||
                 (texture = *(UInt8 **)
                             (uVar63 * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture == (UInt8 *)0x0)) goto LAB_00030d40;
              local_37c = texture;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
              this->get_texture((UInt32 *)(recordCursor),(VendorTextureBuffer *)(local_37c),(UInt32 *)(&streamOffset),(UInt32 *)(&pendingWords),(UInt32 *)(&reservedWords),(register_tracking_state *)(trackingState));
              uVar63 = M<UInt32>((SInt32)recordCursor + iVar52 + 0x10);
              faceOffset = uVar63 >> 0xf & 0x1fffe;
              levelBit = (UInt16)(1 << (uVar63 & 0x3f));
              M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) =
                   M<SInt16>(M<SInt32>(local_37c + 0x14) + 0x36) + 1;
              iVar48 = faceOffset + M<SInt32>(local_37c + 0x14);
              M<UInt16>(iVar48 + 0x28) = levelBit | M<UInt16>(iVar48 + 0x28);
              iVar48 = faceOffset + M<SInt32>(local_37c + 0x14);
              M<UInt16>(iVar48 + 0x1c) = M<UInt16>(iVar48 + 0x1c) & ~levelBit;
              this->build_surface_from_texture((VendorTextureBuffer *)(local_37c),(ATIR500SurfaceBuffer *)((UInt8 *)(self + kATIR500GLContext_textureDepthBuffer)),
                         M<UInt16>((SInt32)recordCursor + 10),M<UInt16>((SInt32)recordCursor + 0xe),
                         M<UInt8>((SInt32)recordCursor + iVar52 + 0x17),
                         M<UInt32>((SInt32)recordCursor + iVar52 + 4),
                         M<UInt16>((SInt32)recordCursor + iVar52 + 10));
            }
            texture = local_37c;
            if (local_37c != (UInt8 *)0x0) {
              if ((M<SInt32>(local_37c + 0x6c) == -1) && (0x20 < M<UInt16>(self + kATIR500GLContext_unknown_0x5bc))) {
                uVar15 = M<UInt16>(self + kATIR500GLContext_unknown_0x5be);
                uVar55 = (UInt32)uVar15;
                if (0x10 < uVar55) {
                  iVar48 = 0x20;
                  iVar33 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
                  if (iVar33 == 4) {
LAB_0002e2d4:
                    uVar62 = ((SInt32)((UInt32)M<UInt16>(self + kATIR500GLContext_unknown_0x5b4) + iVar48 + -1) / iVar48) *
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
                  uVar40 = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),0xffffffff,0,uVar62
                                       ,uVar55);
                  pVVar51 = local_37c;
                  M<UInt32>(texture + 0x6c) = uVar40;
                  if ((M<UInt32>(local_37c + 0x6c) & 0xffc00) == 0xffc00) {
                    iVar48 = 0x20;
                    iVar33 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98);
                    if (iVar33 == 4) {
LAB_0002e34c:
                      uVar55 = ((SInt32)((UInt32)M<UInt16>(self + kATIR500GLContext_unknown_0x5b4) + iVar48 + -1) / iVar48) *
                               iVar48;
                    }
                    else {
                      iVar48 = iVar33 << 4;
                      uVar55 = 0;
                      if (iVar48 != 0) goto LAB_0002e34c;
                    }
                    uVar15 = M<UInt16>(self + kATIR500GLContext_unknown_0x5be);
                    uVar63 = (UInt32)uVar15;
                    bVar1 = (uVar15 & 0x1f) == 0;
                    in_cr0 = bVar1 << 1;
                    if (!bVar1) {
                      uVar63 = (uVar15 & 0xffffffe0) + 0x20;
                    }
                    uVar40 = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                         M<UInt32>(local_37c + 0x6c),1,uVar55,uVar63);
                    M<UInt32>(pVVar51 + 0x6c) = uVar40;
                  }
                  M<UInt16>(local_37c + 0x70) = M<UInt16>(self + kATIR500GLContext_unknown_0x5bc);
                  M<UInt16>(local_37c + 0x72) = M<UInt16>(self + kATIR500GLContext_unknown_0x5be);
                  M<UInt16>(local_37c + 0x78) = M<UInt16>(self + kATIR500GLContext_unknown_0x5b8);
                  M<UInt16>(local_37c + 0x7a) = 0;
                  M<UInt32>(local_37c + 0x74) = M<UInt32>((SInt32)recordCursor + iVar52 + 4);
                }
              }
              M<UInt32>(self + kATIR500GLContext_hzMemoryHandle) = M<UInt32>(local_37c + 0x6c);
              self[0x5d4] = SUB21(M<UInt16>(local_37c + 0x7a),0);
              self[0x5d5] = SUB21((UInt16)M<UInt16>(local_37c + 0x7a) >> 8,0);
              uVar40 = M<UInt32>(local_37c + 0x7c);
              M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture) = local_37c;
              M<UInt32>(self + kATIR500GLContext_unknown_0x5cc) = uVar40;
            }
            local_37c = (UInt8 *)0x0;
            puVar42 = recordCursor + iVar59 + 6;
            if (recordCursor[iVar59 + 6] != 0xffffffff) {
              if (M<SInt32>(self + kATIR500GLContext_renderTargetTexture) != 0) {
                iVar52 = M<SInt32>(M<SInt32>(self + kATIR500GLContext_renderTargetTexture) + 0x14);
                M<SInt16>(iVar52 + 0x36) = M<SInt16>(iVar52 + 0x36) + -1;
                ((IOATIR500GLContext *)((UInt8 *)self))->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture)));
                texture = M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture);
                refCountPtr = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
                previousRefCount = atomicAddReturningOld((SInt32 *)refCountPtr, -1);
                if (previousRefCount == 1) {
                  ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)(texture));
                }
                M<UInt32>(self + kATIR500GLContext_renderTargetTexture) = 0;
              }
              if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= *puVar42) ||
                 (texture = *(UInt8 **)
                             (*puVar42 * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture == (UInt8 *)0x0)) {
LAB_00030d40:
                uVar63 = 0;
                iVar52 = 0;
                M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) =
                     M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50) - reservedWords;
                pendingWords = 0;
                goto LAB_00031340;
              }
              texture = texture;
              ((IOATIR500GLContext *)(self))->add_texture_to_stream((VendorTextureBuffer *)(texture));
              this->get_texture((UInt32 *)(recordCursor),(VendorTextureBuffer *)(texture),(UInt32 *)(&streamOffset),(UInt32 *)(&pendingWords),(UInt32 *)(&reservedWords),(register_tracking_state *)(trackingState));
              uVar63 = puVar42[4] >> 0xf & 0x1fffe;
              uVar15 = (UInt16)(1 << (puVar42[4] & 0x3f));
              M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) =
                   M<SInt16>(M<SInt32>(texture + 0x14) + 0x36) + 1;
              iVar52 = uVar63 + M<SInt32>(texture + 0x14);
              M<UInt16>(iVar52 + 0x28) = uVar15 | M<UInt16>(iVar52 + 0x28);
              iVar52 = uVar63 + M<SInt32>(texture + 0x14);
              M<UInt16>(iVar52 + 0x1c) = M<UInt16>(iVar52 + 0x1c) & ~uVar15;
              this->build_surface_from_texture((VendorTextureBuffer *)(texture),(ATIR500SurfaceBuffer *)((UInt8 *)(self + kATIR500GLContext_textureSurfaceBuffer)),
                         M<UInt16>((SInt32)recordCursor + 10),M<UInt16>((SInt32)recordCursor + 0xe),
                         M<UInt8>((SInt32)puVar42 + 0x17),puVar42[1],M<UInt16>((SInt32)puVar42 + 10));
              M<UInt8 *>(self + kATIR500GLContext_renderTargetTexture) = texture;
            }
            M<UInt32>(self + kATIR500GLContext_renderToTexture) = 1;
            this->build_scissor();
            VCALL(M<SInt32>(self), 0x5a4)(self);
            M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
            *recordCursor = (iVar59 + 10) * 0x10000 | 0xc0001000;
            uVar63 = uVar73 & 0xffffff;
            this->write_kernel_context_buffer_regs((UInt32 *)(recordCursor + iVar59 + 0xc),0,uVar58,uVar61);
            iVar52 = uVar63 << 2;
          }
          else if (opcode == 0x45000000) {
            opcode = recordCursor[3];
            uVar73 = recordCursor[1];
            local_378 = (UInt8 *)0x0;
            if (opcode != 0xffffffff) {
              if ((opcode < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) &&
                 (texture = *(UInt8 **)
                             (opcode * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                 texture != (UInt8 *)0x0)) {
                local_378 = texture;
                if (M<SInt32>(texture + 0x6c) != -1) {
                  this->build_surface_from_texture((VendorTextureBuffer *)(texture),(ATIR500SurfaceBuffer *)(local_374),M<UInt16>(texture + 0x70),
                             M<UInt16>(texture + 0x72),M<UInt8>((SInt32)recordCursor + 0x13),
                             M<UInt32>(texture + 0x74),M<UInt16>(texture + 0x78));
                  M<UInt32>(local_374 + 0x2c) = M<UInt32>(local_378 + 0x7c);
                  opcode = ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(local_374),0,(UInt32 *)(recordCursor));
                  M<UInt16>(local_378 + 0x7a) = 0;
                  goto LAB_0002eed0;
                }
                uVar73 = uVar73 + recordCursor[2];
                opcode = 0;
                goto LAB_0002eed8;
              }
              goto LAB_00030d40;
            }
            opcode = ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)((UInt8 *)
                                (M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) +
                                (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + 0xa8)),0,(UInt32 *)(recordCursor));
LAB_0002eed0:
            if (opcode <= uVar73) {
LAB_0002eed8:
              if (opcode < uVar73) {
                uVar75 = 0x80000000;
                if (uVar73 - opcode != 1) {
                  uVar75 = ((uVar73 - opcode) + -2) * 0x10000 | 0xc0001000;
                }
                recordCursor[opcode] = uVar75;
              }
            }
          }
          else if (opcode == 0x46000000) {
            this->process_kATIGLStreamFastClearColor((UInt32 *)(recordCursor));
          }
          else if (opcode == 0x44000000) {
            iVar59 = M<SInt32>(self + kATIR500GLContext_textureSlots);
            if ((iVar59 != 0) &&
               ((M<char>(iVar59 + 0x20) == '\x06' || (M<SInt32>(iVar59 + 0x48) != 0)))) {
              pVVar79 = (UInt8 *)recordCursor[3];
              opcode = recordCursor[2];
              uVar55 = recordCursor[4];
              if ((M<SInt32>(pVVar79 + 0x48) == 0) &&
                 ((M<SInt32>(pVVar79 + 4) == 0 &&
                  (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar79)),
                  M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0)))) {
                ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
              }
              *recordCursor = 0xc0031000;
              uVar58 = uVar55 + M<SInt32>(pVVar79 + 0x48);
              if (M<SInt32>(pVVar79 + 0x48) == 0) {
                *recordCursor = 0xc0011000;
                recordCursor[3] = 0x575;
                recordCursor[4] = 2;
                uVar58 = uVar55 + M<SInt32>(pVVar79 + 4) + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4);
              }
              iVar59 = (opcode >> 0x10) * 2;
              levelBit = (UInt16)(1 << (opcode & 0x3f));
              iVar48 = iVar59 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(iVar48 + 0x28) = levelBit | M<UInt16>(iVar48 + 0x28);
              iVar59 = iVar59 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~levelBit;
              recordCursor[0x10] = uVar58;
              uVar55 = recordCursor[0x16];
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
              recordCursor[0x16] = uVar55 + textureOffset;
              M<UInt32>(pVVar79 + 0x5c) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
              goto LAB_0002fe70;
            }
            goto LAB_000300b8;
          }
        }
        goto LAB_00031340;
      }
      if (opcode == 0x31000000) {
        opcode = recordCursor[2];
        uVar73 = recordCursor[1];
        uVar55 = recordCursor[3];
        if (opcode == 8) {
LAB_0002ef74:
          opcode = 8;
        }
        else {
          if (opcode < 9) {
            if (opcode == 7) {
LAB_0002ef6c:
              opcode = 7;
              goto LAB_0002ef48;
            }
          }
          else {
            if (opcode == 10) goto LAB_0002ef6c;
            if (opcode == 0xb) goto LAB_0002ef74;
          }
          opcode = 6;
        }
LAB_0002ef48:
        if ((M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) & 0x80) == 0) {
          opcode = 6;
        }
        if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
          pAVar43 = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
          pAVar45 = M<UInt8 *>(pAVar43 + opcode * 4 + 0xb70);
          pAVar76 = (UInt8 *)(pAVar43 + (UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 0x78 + 0xa8)
          ;
        }
        else {
          pAVar43 = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
          pAVar45 = (UInt8 *)(self + kATIR500GLContext_textureDepthBuffer);
          pAVar76 = (UInt8 *)(self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0);
        }
        uVar58 = ((ATIR500Surface *)(pAVar43))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(pAVar45), 0, (UInt32 *)(recordCursor));
        if (((M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) && (opcode != M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex))) &&
           (pAVar76[0x34] != 0x0)) {
          uVar58 = ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(pAVar76),uVar58,(UInt32 *)(recordCursor));
        }
        pAVar76[0x35] = 0x0;
        pAVar76[0x34] = 0x0;
        if ((uVar58 <= uVar73) && (uVar58 < uVar73)) {
          opcode = 0x80000000;
          if (uVar73 - uVar58 != 1) {
            opcode = ((uVar73 - uVar58) + -2) * 0x10000 | 0xc0001000;
          }
          recordCursor[uVar58] = opcode;
        }
        opcode = 0;
        formatByteOffset = (UInt32)(UInt8)pAVar76[0x3a] * 0x1c;
        recordCursor[uVar73 + 0x9a] =
             (UInt32)M<UInt16>(pAVar76 + 0x20) * M<SInt32>(pAVar76 + 0x40) + M<SInt32>(pAVar76 + 8) &
             0xffffffe0;
        if ((M<UInt32>(pAVar76 + 0x3c) & 0xf00000) != 0) {
          opcode = (UInt32)M<UInt16>(pAVar76 + 0x14) / (M<UInt32>(pAVar76 + 0x3c) >> 0x14 & 0xf);
        }
        pitchPixels = 0x20 / M<UInt16>(pAVar76 + 0x16);
        if (0x20 / M<UInt16>(pAVar76 + 0x16) <= opcode) {
          pitchPixels = opcode;
        }
        uVar35 = recordCursor[uVar73 + 0x8a];
        recordCursor[uVar73 + 0x9c] =
             pitchPixels & 0x3ffe | ((UInt8)pAVar76[0x38] & 1) << 0x10 | ((UInt8)pAVar76[0x38] & 6) << 0x10
             | ((UInt8)pAVar76[0x39] & 3) << 0x13 |
             FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar76[0x3a] * 0x1c) >> 1 & 0x1e00000;
        formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
        recordCursor[uVar73 + 0x8a] = formatFieldE0 | uVar35 & 0xffffffe0;
        uVar75 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
        recordCursor[uVar73 + 0x8a] = uVar75 | formatFieldE0 | uVar35 & 0xfffffce0;
        uVar37 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
        recordCursor[uVar73 + 0x8a] = uVar37 | uVar75 | formatFieldE0 | uVar35 & 0xfffff0e0;
        uVar53 = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
        recordCursor[uVar73 + 0x8a] = uVar53 | uVar37 | uVar75 | formatFieldE0 | uVar35 & 0xffffc0e0;
        recordCursor[uVar73 + 0x8a] =
             (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
             uVar53 | uVar37 | uVar75 | formatFieldE0 | uVar35 & 0xffff00e0;
        if (((M<UInt32>(pAVar76 + 0x3c) & 0xf00000) == 0) ||
           (uVar75 = (UInt32)M<UInt16>(pAVar76 + 0x1c) / (M<UInt32>(pAVar76 + 0x3c) >> 0x14 & 0xf),
           opcode = uVar75 - 1, uVar75 == 0)) {
          opcode = 0;
        }
        maxY = 0;
        if (M<UInt16>(pAVar76 + 0x1e) != 0) {
          maxY = M<UInt16>(pAVar76 + 0x1e) - 1;
        }
        recordCursor[uVar73 + 0xb3] = opcode & 0x1fff | (maxY & 0x1fff) << 0xd;
        AVar12 = pAVar45[0x3a];
        recordCursor[uVar73 + 0xa0] =
             ((UInt8)pAVar45[0x38] & 7) << 2 |
             (UInt32)M<UInt16>(pAVar45 + 0x20) * M<SInt32>(pAVar45 + 0x40) + M<SInt32>(pAVar45 + 8) &
             0xffffffe0;
        if (((M<UInt32>(pAVar45 + 0x3c) & 0xf00000) == 0) ||
           (uVar75 = (UInt32)M<UInt16>(pAVar45 + 0x1c) / (M<UInt32>(pAVar45 + 0x3c) >> 0x14 & 0xf),
           opcode = uVar75 - 1, uVar75 == 0)) {
          opcode = 0;
        }
        maxY = 0;
        if (M<UInt16>(pAVar45 + 0x1e) != 0) {
          maxY = M<UInt16>(pAVar45 + 0x1e) - 1;
        }
        recordCursor[uVar73 + 0xa6] = opcode & 0x7ff | (maxY & 0x7ff) << 0xb | 0x80000000;
        formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar12 * 0x1c);
        recordCursor[uVar73 + 0xa8] =
             formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
             formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
        opcode = M<UInt32>(pAVar45 + 0x3c);
        bVar1 = (opcode & 0xf00000) == 0;
        if (bVar1) {
          maxY = 0;
        }
        else {
          maxY = (UInt32)M<UInt16>(pAVar45 + 0x14) / (opcode >> 0x14 & 0xf);
        }
        pitchPixels = 0x20 / M<UInt16>(pAVar45 + 0x16);
        if (0x20 / M<UInt16>(pAVar45 + 0x16) <= maxY) {
          pitchPixels = maxY;
        }
        if ((bVar1) ||
           (uVar75 = (UInt32)M<UInt16>(pAVar45 + 0x1c) / (opcode >> 0x14 & 0xf), opcode = uVar75 - 1
           , uVar75 == 0)) {
          opcode = 0;
        }
        maxY = 0;
        if (M<UInt16>(pAVar45 + 0x1e) != 0) {
          maxY = M<UInt16>(pAVar45 + 0x1e) - 1;
        }
        puVar69 = recordCursor + uVar73 + 0xbd;
        uVar53 = 0;
        recordCursor[uVar73 + 0xaa] = pitchPixels - 1 & 0x3fff | (opcode & 0x800) << 4 | (maxY & 0x800) << 5
        ;
        recordCursor[uVar73 + 0xb] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
        AVar12 = pAVar45[0x3a];
        bVar1 = (M<UInt32>(pAVar45 + 0x3c) & 0xf00000) == 0;
        in_cr0 = bVar1 << 1;
        if (!bVar1) {
          uVar53 = (UInt32)M<UInt16>(pAVar45 + 0x14) / (M<UInt32>(pAVar45 + 0x3c) >> 0x14 & 0xf);
        }
        pitchPixels = 0x20 / M<UInt16>(pAVar45 + 0x16);
        if (0x20 / M<UInt16>(pAVar45 + 0x16) <= uVar53) {
          pitchPixels = uVar53;
        }
        iVar59 = M<SInt32>(pAVar45 + 0x40);
        uVar15 = M<UInt16>(pAVar45 + 0x20);
        AVar13 = pAVar45[0x38];
        iVar48 = M<SInt32>(pAVar45 + 8);
        if ((uVar55 != 0) && (0 < (SInt32)uVar55)) {
          do {
            if ((UInt8)AVar13 >> 1 == 0) {
              maxY = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar12 * 0x1c);
              iVar33 = 0;
            }
            else {
              maxY = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar12 * 0x1c);
              iVar33 = -(maxY >> 8 & 3);
            }
            maxY = maxY >> 0xc & 7;
            iVar33 = (SInt32)*puVar69 >> ((iVar33 - maxY) + 5 & 0x3f);
            if (((UInt8)AVar13 & 1) == 0) {
              iVar33 = iVar33 << 5;
            }
            else {
              iVar33 = (iVar33 << 0xc) >> 3;
            }
            *puVar69 = 0x1150;
            puVar69[1] = (UInt32)uVar15 * iVar59 + iVar48 + iVar33 + (pitchPixels * puVar69[1] << maxY) &
                         0xffffffe0 | ((UInt8)AVar13 >> 1 & 3) << 3 | ((UInt8)AVar13 & 1) << 2;
            uVar58 = puVar69[2];
            maxY = recordCursor[uVar73 + 0xa6];
            puVar69[2] = 0x1120;
            puVar69[3] = (puVar69[3] - 1) * 0x800 & 0x3ff800 |
                         uVar58 - 1 & 0x7ff | maxY & 0xffc00000;
            puVar69 = puVar69 + 0x10;
            uVar55 = uVar55 - 1;
          } while (uVar55 != 0);
        }
        goto LAB_00031340;
      }
      if (0x31000000 < opcode) {
        if (opcode == 0x34000000) {
          opcode = recordCursor[1] * 8;
          if (M<UInt32>(self + kIOATIR500GLContext_statusRegionSize) <= opcode) goto LAB_00030d40;
          *recordCursor = 0x578;
          accel = M<SInt32>(self + kIOATIR500GLContext_accelerator);
          uVar55 = M<UInt32>(accel + 0x50);
          recordCursor[1] = uVar55;
          M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_statusRegion) + opcode) = uVar55;
          M<UInt32>(accel + 0x50) = uVar55 + 1;
          M<UInt32>(opcode + M<SInt32>(self + kIOATIR500GLContext_statusRegion) + 4) = 0;
          reservedWords = reservedWords + 1;
        }
        else if (opcode < 0x34000001) {
          if (opcode == 0x32000000) {
            iVar59 = M<SInt32>(self + kATIR500GLContext_textureSlots);
            uVar55 = recordCursor[2];
            if ((iVar59 != 0) &&
               ((M<char>(iVar59 + 0x20) == '\x06' || (M<SInt32>(iVar59 + 0x48) != 0)))) {
              opcode = recordCursor[4];
              uVar58 = recordCursor[5];
              if (uVar55 != 0) {
                uVar73 = recordCursor[3];
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
                if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                  pAVar43 = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
                  pAVar45 = M<UInt8 *>(pAVar43 + iVar59 * 4 + 0xb70);
                }
                else {
                  pAVar43 = M<UInt8 *>(self + kIOATIR500GLContext_boundSurface);
                  pAVar45 = (UInt8 *)(self + kATIR500GLContext_textureDepthBuffer);
                }
                iVar59 = ((ATIR500Surface *)(pAVar43))->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(pAVar45),0,(UInt32 *)(recordCursor + -uVar55));
                uVar73 = 0x80000000;
                if (uVar55 - iVar59 != 1) {
                  uVar73 = ((uVar55 - iVar59) + -2) * 0x10000 | 0xc0001000;
                }
                (recordCursor + -uVar55)[iVar59] = uVar73;
                iVar59 = M<SInt32>(self + kATIR500GLContext_textureSlots);
              }
              iVar48 = (opcode >> 0x10) * 2;
              iVar59 = iVar48 + M<SInt32>(iVar59 + 0x14);
              levelBit = (UInt16)(1 << (opcode & 0x3f));
              M<UInt16>(iVar59 + 0x28) = levelBit | M<UInt16>(iVar59 + 0x28);
              iVar48 = iVar48 + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
              M<UInt16>(iVar48 + 0x1c) = M<UInt16>(iVar48 + 0x1c) & ~levelBit;
              *recordCursor = 0xc0051000;
              convertIOGLBufferToBufIdx(recordCursor[3],(UInt32 *)&local_378);
              if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
                opcode = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
                iVar48 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
                iVar59 = opcode + 1;
                pAVar77 = *(UInt8 **)
                           ((SInt32)local_378 * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
              }
              else if (recordCursor[3] == 4) {
                pAVar77 = self + kATIR500GLContext_textureDepthBuffer;
                iVar59 = 1;
                opcode = 0;
                iVar48 = 0;
              }
              else {
                iVar59 = 1;
                opcode = 0;
                iVar48 = 0;
                pAVar77 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
              }
              AVar10 = pAVar77[0x3a];
              recordCursor[0xa7] =
                   ((UInt8)pAVar77[0x38] & 7) << 2 |
                   M<SInt32>(pAVar77 + opcode * 4 + 0x40) * (UInt32)M<UInt16>(pAVar77 + 0x20) +
                   iVar48 * (M<SInt32>(pAVar77 + iVar59 * 4 + 0x40) -
                            M<SInt32>(pAVar77 + opcode * 4 + 0x40)) + M<SInt32>(pAVar77 + 8) &
                   0xffffffe0;
              if (((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0) ||
                 (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x1c) /
                                (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)) >> (opcode & 0x3f),
                 iVar59 == 0)) {
                uVar73 = 0;
              }
              else {
                uVar73 = iVar59 - 1;
              }
              uVar75 = 0;
              iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar77 + 0x1e) >> (opcode & 0x3f);
              if (iVar59 != 0) {
                uVar75 = iVar59 - 1;
              }
              recordCursor[0xad] = uVar73 & 0x7ff | (uVar75 & 0x7ff) << 0xb | 0x80000000;
              formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar10 * 0x1c);
              recordCursor[0xaf] =
                   formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
                   formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
              uVar73 = M<UInt32>(pAVar77 + 0x3c);
              bVar1 = (uVar73 & 0xf00000) == 0;
              if (bVar1) {
                uVar75 = 0;
              }
              else {
                uVar75 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x14) / (uVar73 >> 0x14 & 0xf)) >>
                         (opcode & 0x3f);
              }
              pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
              if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar75) {
                pitchPixels = uVar75;
              }
              if ((bVar1) ||
                 (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x1c) / (uVar73 >> 0x14 & 0xf)) >>
                           (opcode & 0x3f), iVar59 == 0)) {
                uVar73 = 0;
              }
              else {
                uVar73 = iVar59 - 1;
              }
              uVar75 = 0;
              iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar77 + 0x1e) >> (opcode & 0x3f);
              if (iVar59 != 0) {
                uVar75 = iVar59 - 1;
              }
              uVar55 = recordCursor[0xa1];
              recordCursor[0xb1] = pitchPixels - 1 & 0x3fff | (uVar73 & 0x800) << 4 | (uVar75 & 0x800) << 5;
              recordCursor[0x12] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
              puVar69 = recordCursor + 0xc4;
              uVar73 = 0;
              recordCursor[0xa1] = uVar55 + textureOffset;
              AVar10 = pAVar77[0x3a];
              bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                uVar73 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x14) /
                              (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)) >> (opcode & 0x3f);
              }
              pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
              if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar73) {
                pitchPixels = uVar73;
              }
              uVar15 = M<UInt16>(pAVar77 + 0x20);
              iVar74 = M<SInt32>(pAVar77 + 8);
              iVar59 = M<SInt32>(pAVar77 + opcode * 4 + 0x40);
              iVar33 = M<SInt32>(pAVar77 + opcode * 4 + 0x44);
              AVar11 = pAVar77[0x38];
              if ((uVar58 != 0) && (0 < (SInt32)uVar58)) {
                do {
                  if ((UInt8)AVar11 >> 1 == 0) {
                    formatFieldDC = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
                    iVar49 = 0;
                  }
                  else {
                    opcode = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
                    iVar49 = -(opcode >> 8 & 3);
                  }
                  opcode = opcode >> 0xc & 7;
                  iVar49 = (SInt32)*puVar69 >> ((iVar49 - opcode) + 5 & 0x3f);
                  if (((UInt8)AVar11 & 1) == 0) {
                    iVar49 = iVar49 << 5;
                  }
                  else {
                    iVar49 = (iVar49 << 0xc) >> 3;
                  }
                  *puVar69 = 0x1150;
                  puVar69[1] = ((UInt8)AVar11 >> 1 & 3) << 3 | ((UInt8)AVar11 & 1) << 2 |
                               iVar59 * (UInt32)uVar15 + iVar48 * (iVar33 - iVar59) + iVar74 +
                               iVar49 + (pitchPixels * puVar69[1] << opcode) & 0xffffffe0;
                  uVar55 = puVar69[2];
                  opcode = recordCursor[0xad];
                  puVar69[2] = 0x1120;
                  puVar69[3] = (puVar69[3] - 1) * 0x800 & 0x3ff800 |
                               uVar55 - 1 & 0x7ff | opcode & 0xffc00000;
                  puVar69 = puVar69 + 0x10;
                  uVar58 = uVar58 - 1;
                } while (uVar58 != 0);
              }
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0x80) =
                   M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
              goto LAB_0002fe70;
            }
            recordCursor[-uVar55] = (uVar55 + recordCursor[1] + -2) * 0x10000 | 0xc0001000;
          }
          else if (opcode == 0x33000000) {
            if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
              iVar59 = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
              opcode = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
              iVar48 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
              pAVar68 = M<UInt8 *>((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + iVar59 + 0xb70);
              pAVar72 = M<UInt8 *>((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + iVar59 + 0xb70);
              iVar33 = opcode + 1;
              pAVar77 = (UInt8 *)((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 0x78 + iVar59 + 0xa8);
            }
            else {
              pAVar68 = self + kATIR500GLContext_textureDepthBuffer;
              iVar48 = 0;
              opcode = 0;
              iVar33 = 1;
              pAVar72 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
              pAVar77 = pAVar72;
            }
            uVar75 = recordCursor[1];
            *recordCursor = 0xc0001000;
            uVar73 = 0;
            formatByteOffset = (UInt32)(UInt8)pAVar72[0x3a] * 0x1c;
            recordCursor[0x9c] =
                 M<SInt32>(pAVar72 + opcode * 4 + 0x40) * (UInt32)M<UInt16>(pAVar72 + 0x20) +
                 iVar48 * (M<SInt32>(pAVar72 + iVar33 * 4 + 0x40) -
                          M<SInt32>(pAVar72 + opcode * 4 + 0x40)) + M<SInt32>(pAVar72 + 8) &
                 0xffffffe0;
            if ((M<UInt32>(pAVar72 + 0x3c) & 0xf00000) != 0) {
              uVar73 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x14) /
                            (M<UInt32>(pAVar72 + 0x3c) >> 0x14 & 0xf)) >> (opcode & 0x3f);
            }
            pitchPixels = 0x20 / M<UInt16>(pAVar72 + 0x16);
            if (0x20 / M<UInt16>(pAVar72 + 0x16) <= uVar73) {
              pitchPixels = uVar73;
            }
            uVar35 = recordCursor[0x8c];
            recordCursor[0x9e] =
                 pitchPixels & 0x3ffe | ((UInt8)pAVar72[0x38] & 1) << 0x10 |
                 ((UInt8)pAVar72[0x38] & 6) << 0x10 | ((UInt8)pAVar72[0x39] & 3) << 0x13 |
                 FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar72[0x3a] * 0x1c) >> 1 & 0x1e00000;
            formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
            recordCursor[0x8c] = formatFieldE0 | uVar35 & 0xffffffe0;
            uVar73 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
            recordCursor[0x8c] = uVar73 | formatFieldE0 | uVar35 & 0xfffffce0;
            uVar37 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
            recordCursor[0x8c] = uVar37 | uVar73 | formatFieldE0 | uVar35 & 0xfffff0e0;
            uVar53 = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
            recordCursor[0x8c] = uVar53 | uVar37 | uVar73 | formatFieldE0 | uVar35 & 0xffffc0e0;
            recordCursor[0x8c] =
                 (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
                 uVar53 | uVar37 | uVar73 | formatFieldE0 | uVar35 & 0xffff00e0;
            uVar55 = this->compute_sc_hyperz_en(recordCursor[0x14]);
            recordCursor[0x14] = uVar55;
            uVar55 = this->compute_zb_bw_cntl(recordCursor[0x16]);
            recordCursor[0x16] = uVar55;
            uVar55 = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
            recordCursor[0xae] = 0xaaaa;
            recordCursor[0xd] = uVar55;
            if ((((M<UInt32>(pAVar77 + 0x28) & 0x3ff00000) == 0x3ff00000) ||
                (pAVar77[0x36] == 0x0)) ||
               (((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xbe8) & 0x700000) == 0 ||
                (M<SInt16>(self + kIOATIR500GLContext_colorBufferIndex) != 9)))) {
              recordCursor[0x22] = 0;
            }
            else {
              recordCursor[0x22] = 0x600;
            }
            boundTexture = M<UInt8 *>(self + kATIR500GLContext_textureSlots);
            if (boundTexture == (UInt8 *)0x0) {
              recordCursor[0xa1] = 0xc0001000;
            }
            else {
              bVar80 = M<UInt8>(M<SInt32>(boundTexture + 0x14) + 0x15);
              textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(boundTexture),false);
              recordCursor[0xa2] = bVar80 & 0x1f | textureOffset & 0xffffffe0;
            }
            bVar1 = (uVar75 & 2) == 0;
            in_cr0 = bVar1 << 1;
            if (!bVar1) {
              formatFieldE0 = 0;
              recordCursor[0xc0] = -((UInt8)pAVar68[0x3a] ^ 0x10) >> 0x1e & 2;
              recordCursor[0xc2] = M<UInt32>(pAVar68 + 8);
              if ((M<UInt32>(pAVar68 + 0x3c) & 0xf00000) != 0) {
                formatFieldE0 = (UInt32)M<UInt16>(pAVar68 + 0x14) /
                         (M<UInt32>(pAVar68 + 0x3c) >> 0x14 & 0xf);
              }
              pitchPixels = 0x20 / M<UInt16>(pAVar68 + 0x16);
              if (0x20 / M<UInt16>(pAVar68 + 0x16) <= formatFieldE0) {
                pitchPixels = formatFieldE0;
              }
              formatFieldE0 = 0;
              local_c4 = ((UInt8)pAVar68[0x38] & 6) << 0x10 |
                         ((UInt8)pAVar68[0x38] & 1) << 0x10 |
                         ((UInt8)pAVar68[0x39] & 3) << 0x13 | pitchPixels & 0x3ffc | local_c4 & 0xffe0c003
              ;
              recordCursor[0xc3] = local_c4;
              bVar1 = (M<UInt32>(pAVar68 + 0x3c) & 0xf00000) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                formatFieldE0 = (UInt32)M<UInt16>(pAVar68 + 0x14) /
                         (M<UInt32>(pAVar68 + 0x3c) >> 0x14 & 0xf);
              }
              pitchPixels = 0x20 / M<UInt16>(pAVar68 + 0x16);
              if (0x20 / M<UInt16>(pAVar68 + 0x16) <= formatFieldE0) {
                pitchPixels = formatFieldE0;
              }
              formatByteOffset = 0x20;
              if (M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) == 4) {
LAB_00030cec:
                uVar55 = formatByteOffset * ((SInt32)(formatByteOffset + pitchPixels + -1) / formatByteOffset);
              }
              else {
                formatByteOffset = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb98) << 4;
                in_cr0 = (formatByteOffset == 0) << 1;
                uVar55 = 0;
                if (formatByteOffset != 0) goto LAB_00030cec;
              }
              recordCursor[0xc5] = uVar55;
              hzBlockOffset = HZMEM_GetBlockOffset
                                 ((_HZDATA *)((UInt8 *)(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x870)),
                                  M<UInt32>(pAVar68 + 0x28),0);
              recordCursor[199] = hzBlockOffset;
              recordCursor[0xc9] = M<UInt32>(pAVar68 + 0x2c);
            }
          }
        }
        else if (opcode == 0x35000000) {
          iVar59 = M<SInt32>(self + kATIR500GLContext_textureSlots);
          if ((iVar59 == 0) ||
             ((M<char>(iVar59 + 0x20) != '\x06' && (M<SInt32>(iVar59 + 0x48) == 0))))
          goto LAB_000300b8;
          opcode = recordCursor[2] >> 0xf & 0x1fffe;
          iVar59 = opcode + M<SInt32>(iVar59 + 0x14);
          uVar15 = (UInt16)(1 << (recordCursor[2] & 0x3f));
          M<UInt16>(iVar59 + 0x28) = uVar15 | M<UInt16>(iVar59 + 0x28);
          iVar59 = opcode + M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14);
          M<UInt16>(iVar59 + 0x1c) = M<UInt16>(iVar59 + 0x1c) & ~uVar15;
          *recordCursor = 0xc0011000;
          uVar55 = recordCursor[0x9d];
          recordCursor[0xe] = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
          textureOffset = this->GetTextureOffset((VendorTextureBuffer *)(M<UInt8 *>(self + kATIR500GLContext_textureSlots)),true);
          recordCursor[0x9d] = uVar55 + textureOffset;
          recordCursor[0xa3] =
               M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) +
               ((SInt32)recordCursor - (M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20) & 0xfffffffcU) + 0x20 +
               (recordCursor[0xa3] >> 3 & 0x1ffffffc) & 0xffffffe0 | recordCursor[0xa3] & 0x1f;
LAB_0002fe70:
          M<UInt32>(M<SInt32>(M<SInt32>(self + kATIR500GLContext_textureSlots) + 0x14) + 0xc) =
               M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
        }
        else if (opcode == 0x36000000) {
          iVar59 = M<SInt32>(self + kATIR500GLContext_pinnedTexture);
          pVVar79 = (UInt8 *)recordCursor[1];
          if ((iVar59 != 0) && (M<SInt32>(iVar59 + 0x48) == 0)) {
            M<SInt16>(iVar59 + 0xe) = M<SInt16>(iVar59 + 0xe) + -1;
          }
          if (((M<SInt32>(pVVar79 + 0x48) == 0) &&
              (M<SInt16>(pVVar79 + 0xe) = M<SInt16>(pVVar79 + 0xe) + 1, M<SInt32>(pVVar79 + 4) == 0
              )) && (((IOATIR500GLContext *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar79)),
                    M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) == 0)) {
            ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)));
          }
          M<UInt32>(pVVar79 + 0x5c) = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
          M<UInt8 *>(self + kATIR500GLContext_pinnedTexture) = pVVar79;
          iVar59 = M<SInt32>(pVVar79 + 0x48);
          uVar55 = recordCursor[3];
          opcode = recordCursor[2] + 1 >> 1;
          if (iVar59 == 0) {
            iVar59 = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4) + M<SInt32>(pVVar79 + 4);
          }
          *recordCursor = 0x80000000;
          recordCursor[1] = 0x80000000;
          recordCursor[2] = 0x80000000;
          recordCursor[3] = 0x80000000;
          if (opcode != 0) {
            iVar48 = 6;
            iVar33 = 0x1c;
            puVar69 = recordCursor;
            do {
              recordCursor[iVar48] = uVar55 + iVar59 + puVar69[6] * 4;
              M<UInt32>((SInt32)recordCursor + iVar33) = uVar55 + iVar59 + puVar69[7] * 4;
              puVar69 = puVar69 + 3;
              iVar48 = iVar48 + 3;
              iVar33 = iVar33 + 0xc;
              opcode = opcode - 1;
            } while (opcode != 0);
          }
        }
        goto LAB_00031340;
      }
      if (opcode != 0x2d000000) {
        if (opcode < 0x2d000001) {
          if (opcode == 0x2b000000) {
            if (pendingWords != 0) {
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704) =
                   pendingWords * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x704);
              M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb94) = 1;
              uVar40 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->submit_buffer((UInt32 *)((streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20)
                                  ,streamOffset + M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) + 0x20,pendingWords);
              M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = uVar40;
              iVar59 = pendingWords * 4;
              pendingWords = 0;
              streamOffset = iVar59 + streamOffset;
              reservedWords = 0;
            }
            *recordCursor = 0x80000000;
          }
          else if (opcode == 0x2c000000) {
            if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
              iVar33 = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
              iVar59 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
              iVar48 = iVar33 + 1;
              pAVar77 = *(UInt8 **)
                         ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
            }
            else {
              iVar59 = 0;
              iVar33 = 0;
              iVar48 = 1;
              pAVar77 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
            }
            bVar1 = (M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0;
            in_cr0 = bVar1 << 1;
            opcode = 0;
            if (!bVar1) {
              opcode = (UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)
              ;
            }
            pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
            if (pitchPixels <= opcode) {
              pitchPixels = opcode;
            }
            opcode = 0x80000000;
            if ((UInt8)pAVar77[0x38] < 2) {
              opcode = 0;
            }
            *recordCursor = opcode | M<SInt32>(pAVar77 + iVar33 * 4 + 0x40) *
                                (UInt32)M<UInt16>(pAVar77 + 0x20) +
                                iVar59 * (M<SInt32>(pAVar77 + iVar48 * 4 + 0x40) -
                                         M<SInt32>(pAVar77 + iVar33 * 4 + 0x40)) +
                                M<SInt32>(pAVar77 + 8) >> 10 |
                                pitchPixels * M<UInt16>(pAVar77 + 0x16) * 0x10000 & 0x3fc00000 |
                                ((UInt8)pAVar77[0x38] & 1) << 0x1e;
            opcode = recordCursor[1] >> 0x10;
            uVar73 = M<UInt32>(self + kATIR500GLContext_scissorY) >> 0x10;
            uVar53 = recordCursor[2] & 0xffff;
            uVar35 = M<UInt32>(self + kATIR500GLContext_scissorX) & 0xffff;
            uVar57 = recordCursor[1] & 0xffff;
            uVar34 = M<UInt32>(self + kATIR500GLContext_scissorY) & 0xffff;
            uVar75 = recordCursor[2] >> 0x10;
            uVar37 = M<UInt32>(self + kATIR500GLContext_scissorX) >> 0x10;
            if (uVar73 < opcode) {
              uVar73 = opcode;
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
            recordCursor[1] = uVar34 | uVar73 << 0x10;
            recordCursor[2] = uVar35 | uVar37 << 0x10;
          }
        }
        else if (opcode == 0x2f000000) {
          *recordCursor = 0x80000000;
          uVar55 = this->compute_sc_hyperz_en(recordCursor[2]);
          recordCursor[2] = uVar55;
          uVar55 = this->compute_zb_bw_cntl(recordCursor[4]);
          recordCursor[4] = uVar55;
          VCALL(M<SInt32>(self), 0x5a4)(self);
        }
        else if (opcode == 0x30000000) {
          uVar55 = recordCursor[1];
          switch(recordCursor[2]) {
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
          puVar42 = (UInt32 *)((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->resolve_fsaa_buffer((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex),uVar58,(UInt32 *)(recordCursor),
                                       (bool)('\x01' - (recordCursor[3] == 0)),recordCursor[4],recordCursor[5],
                                       recordCursor[6],recordCursor[7]);
          if (puVar42 < recordCursor + uVar55) {
            iVar59 = (SInt32)(recordCursor + uVar55) - (SInt32)puVar42;
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
      recordPayloadEnd = recordCursor + recordCursor[1];
      switch(recordCursor[2]) {
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
      uVar55 = recordCursor[3];
      uVar58 = recordCursor[4];
      uVar61 = recordCursor[5];
      uVar62 = recordCursor[6];
      opcode = recordCursor[7];
      uVar73 = recordCursor[8];
      *recordCursor = (recordCursor[1] - 2) * 0x10000 | 0xc0001000;
      if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
        uVar75 = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
        iVar48 = M<SInt32>(self + kIOATIR500GLContext_surfaceIndex);
        iVar33 = uVar75 + 1;
        pAVar72 = M<UInt8 *>(iVar59 * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
        pAVar77 = *(UInt8 **)
                   (M<SInt32>(self + kATIR500GLContext_renderBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
      }
      else {
        iVar48 = 0;
        uVar75 = 0;
        iVar33 = 1;
        pAVar72 = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
        pAVar77 = pAVar72;
      }
      puVar42 = recordCursor + 0xbd;
      GH_memcpy(recordCursor,&g_r500_3d_blit_state_packet,0x2f4);
      formatByteOffset = (UInt32)(UInt8)pAVar77[0x3a] * 0x1c;
      uVar37 = 0;
      recordCursor[0x9a] =
           M<SInt32>(pAVar77 + uVar75 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar77 + 0x20) +
           iVar48 * (M<SInt32>(pAVar77 + iVar33 * 4 + 0x40) - M<SInt32>(pAVar77 + uVar75 * 4 + 0x40))
           + M<SInt32>(pAVar77 + 8) & 0xffffffe0;
      if ((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) != 0) {
        uVar37 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x14) / (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)
                      ) >> (uVar75 & 0x3f);
      }
      pitchPixels = 0x20 / M<UInt16>(pAVar77 + 0x16);
      if (0x20 / M<UInt16>(pAVar77 + 0x16) <= uVar37) {
        pitchPixels = uVar37;
      }
      uVar34 = recordCursor[0x8a];
      recordCursor[0x9c] =
           pitchPixels & 0x3ffe | ((UInt8)pAVar77[0x38] & 1) << 0x10 | ((UInt8)pAVar77[0x38] & 6) << 0x10 |
           ((UInt8)pAVar77[0x39] & 3) << 0x13 |
           FormatTableLookup_0x0004d2e0((UInt32)(UInt8)pAVar77[0x3a] * 0x1c) >> 1 & 0x1e00000;
      formatFieldE0 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 0x11 & 0x1f;
      recordCursor[0x8a] = formatFieldE0 | uVar34 & 0xffffffe0;
      uVar53 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 7 & 0x300;
      recordCursor[0x8a] = uVar53 | formatFieldE0 | uVar34 & 0xfffffce0;
      uVar35 = FormatTableLookup_0x0004d2e0(formatByteOffset) >> 3 & 0xc00;
      recordCursor[0x8a] = uVar35 | uVar53 | formatFieldE0 | uVar34 & 0xfffff0e0;
      uVar57 = (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x1800) << 1;
      recordCursor[0x8a] = uVar57 | uVar35 | uVar53 | formatFieldE0 | uVar34 & 0xffffc0e0;
      recordCursor[0x8a] =
           (FormatTableLookup_0x0004d2e0(formatByteOffset) & 0x600) << 5 |
           uVar57 | uVar35 | uVar53 | formatFieldE0 | uVar34 & 0xffff00e0;
      if (((M<UInt32>(pAVar77 + 0x3c) & 0xf00000) == 0) ||
         (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar77 + 0x1c) /
                        (M<UInt32>(pAVar77 + 0x3c) >> 0x14 & 0xf)) >> (uVar75 & 0x3f), iVar59 == 0))
      {
        formatFieldE0 = 0;
      }
      else {
        formatFieldE0 = iVar59 - 1;
      }
      uVar53 = 0;
      iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar77 + 0x1e) >> (uVar75 & 0x3f);
      if (iVar59 != 0) {
        uVar53 = iVar59 - 1;
      }
      recordCursor[0xb3] = formatFieldE0 & 0x1fff | (uVar53 & 0x1fff) << 0xd;
      AVar10 = pAVar72[0x3a];
      recordCursor[0xa0] =
           ((UInt8)pAVar72[0x38] & 7) << 2 |
           M<SInt32>(pAVar72 + uVar75 * 4 + 0x40) * (UInt32)M<UInt16>(pAVar72 + 0x20) +
           iVar48 * (M<SInt32>(pAVar72 + iVar33 * 4 + 0x40) - M<SInt32>(pAVar72 + uVar75 * 4 + 0x40))
           + M<SInt32>(pAVar72 + 8) & 0xffffffe0;
      if (((M<UInt32>(pAVar72 + 0x3c) & 0xf00000) == 0) ||
         (iVar59 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x1c) /
                        (M<UInt32>(pAVar72 + 0x3c) >> 0x14 & 0xf)) >> (uVar75 & 0x3f), iVar59 == 0))
      {
        formatFieldE0 = 0;
      }
      else {
        formatFieldE0 = iVar59 - 1;
      }
      uVar53 = 0;
      iVar59 = (SInt32)(UInt32)M<UInt16>(pAVar72 + 0x1e) >> (uVar75 & 0x3f);
      if (iVar59 != 0) {
        uVar53 = iVar59 - 1;
      }
      recordCursor[0xa6] = formatFieldE0 & 0x7ff | (uVar53 & 0x7ff) << 0xb | 0x80000000;
      formatFieldE4 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar10 * 0x1c);
      recordCursor[0xa8] =
           formatFieldE4 >> 0x13 & 0x1f | (formatFieldE4 & 0x40) << 0x10 | formatFieldE4 >> 7 & 0xe00 |
           formatFieldE4 >> 1 & 0x7000 | (formatFieldE4 & 0x1c00) << 5 | (formatFieldE4 & 0x380) << 0xb;
      uVar37 = M<UInt32>(pAVar72 + 0x3c);
      bVar1 = (uVar37 & 0xf00000) == 0;
      if (bVar1) {
        uVar53 = 0;
      }
      else {
        uVar53 = (SInt32)((UInt32)M<UInt16>(pAVar72 + 0x14) / (uVar37 >> 0x14 & 0xf)) >>
                 (uVar75 & 0x3f);
      }
      pitchPixels = 0x20 / M<UInt16>(pAVar72 + 0x16);
      if (0x20 / M<UInt16>(pAVar72 + 0x16) <= uVar53) {
        pitchPixels = uVar53;
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
      uStack_17c = uVar55 - opcode ^ 0x80000000;
      recordCursor[0xaa] = pitchPixels - 1 & 0x3fff | (uVar37 & 0x800) << 4 | (uVar53 & 0x800) << 5;
      uVar55 = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0xb74);
      recordCursor[0xaf] = 0xc0001000;
      recordCursor[0x11] = 0xc0001000;
      recordCursor[0x13] = 0xc0001000;
      recordCursor[0x15] = 0xc0001000;
      recordCursor[0x1d] = 0xc0001000;
      recordCursor[0x2d] = 0xc0001000;
      recordCursor[0x2f] = 0xc0001000;
      recordCursor[0xb] = uVar55;
      recordCursor[0x31] = 0xc0001000;
      recordCursor[0x33] = 0xc0001000;
      recordCursor[0x35] = 0xc0001000;
      recordCursor[0xad] = 0xc0001000;
      recordCursor[0xb1] = 0xc0011000;
      recordCursor[0xa2] = recordCursor[0xa2] & 0xffffe600 | 0x11b6;
      dVar31 = DOUBLE_0004c3a8;
      fVar23 = FLOAT_0004c380;
      fVar30 = FLOAT_0004c37c;
      fVar28 = FLOAT_0004c374;
      uStack_194 = uVar73 ^ 0x80000000;
      local_198 = 0x43300000;
      local_180 = 0x43300000;
      iStack_18c = uVar61 + opcode;
      uStack_19c = opcode ^ 0x80000000;
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
      fVar6 = (float)((double)CONCAT44d(0x43300000,opcode ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar7 = (float)((double)CONCAT44d(0x43300000,uVar61 + opcode) - DOUBLE_0004c3b0);
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
        recordCursor[0xc2] = 0x1087;
        opcode = 0;
        recordCursor[0xbe] = FBITS(fVar28 * (fVar6 + fVar5));
        recordCursor[0xc0] = FBITS(fVar28 * (fVar7 + fVar5));
        recordCursor[0xbf] = FBITS(fVar23 * (fVar8 + fVar9));
        recordCursor[0xc1] = FBITS(fVar23 * (fVar4 + fVar9));
        iVar59 = (SInt32)((fVar7 - fVar6) * fVar30);
        uVar73 = (UInt32)(SInt32)((fVar8 - fVar4) * fVar30);
        local_130 = (SInt64)iVar59;
        local_128 = (SInt64)(SInt32)uVar73;
        fVar5 = (fVar6 + fVar7) * FLOAT_0004c380;
        fVar4 = (fVar4 + fVar8) * FLOAT_0004c380;
        recordCursor[0xc4] = 0xc0033500;
        recordCursor[0xc5] = 0x10031;
        recordCursor[0xc6] = FBITS(fVar5);
        recordCursor[199] = FBITS(fVar4);
        recordCursor[0xc3] = iVar59 << 0x10 | uVar73;
        recordCursor[200] = 0;
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
        pitchPixels = M<UInt16>(pAVar72 + 0x1c) & 0xfe00;
        local_170 = (SInt64)(SInt32)fVar17;
        opcode = (SInt32)fVar17 - 1;
        opcode = (((SInt32)opcode >> 9) + (UInt32)((SInt32)opcode < 0 && (opcode & 0x1ff) != 0)) * 0x200;
        uVar73 = 0;
        if ((-1 < (SInt32)opcode) && (uVar73 = pitchPixels, (SInt32)opcode <= (SInt32)pitchPixels)) {
          uVar73 = opcode & 0xfe00;
        }
        opcode = 0x40;
        if ((0x40 < uVar37) &&
           (opcode = M<UInt16>(pAVar72 + 0x1e) & 0xffc0, (SInt32)(uVar37 - opcode) < 0x40)) {
          opcode = opcode - 0x40;
        }
        uVar57 = 0;
        local_168 = (SInt64)(SInt32)fVar22;
        pitchPixels = (SInt32)fVar22 - 1;
        pitchPixels = (((SInt32)pitchPixels >> 6) + (UInt32)((SInt32)pitchPixels < 0 && (pitchPixels & 0x3f) != 0)) * 0x40;
        if ((-1 < (SInt32)pitchPixels) && (uVar57 = opcode & 0xffff, (SInt32)pitchPixels <= (SInt32)opcode)) {
          uVar57 = pitchPixels & 0xffc0;
        }
        opcode = 0x200;
        if (0x1ff < uVar73) {
          opcode = uVar73;
        }
        pitchPixels = uVar53 - 1;
        uVar34 = (((SInt32)pitchPixels >> 9) + (UInt32)((SInt32)pitchPixels < 0 && (pitchPixels & 0x1ff) != 0)) * 0x200;
        pitchPixels = (UInt32)(SInt32)fVar24;
        local_160 = (SInt64)(SInt32)pitchPixels;
        if (FLOAT_0004c370 < fVar24) {
          uStack_154 = pitchPixels ^ 0x80000000;
          local_158 = 0x43300000;
          if ((float)((double)CONCAT44d(0x43300000,pitchPixels ^ 0x80000000) - DOUBLE_0004c3a8) < fVar24)
          {
            pitchPixels = pitchPixels + 1;
          }
        }
        if ((SInt32)pitchPixels <= (SInt32)uVar34) {
          uVar34 = pitchPixels;
        }
        pitchPixels = 1;
        if ((SInt32)opcode < (SInt32)uVar34) {
          pitchPixels = (SInt32)((uVar34 - opcode) + 0xbff) / 0xc00 & 0xff;
        }
        opcode = 0x40;
        if (0x3f < uVar57) {
          opcode = uVar57;
        }
        uVar34 = uVar37 - 1;
        uVar41 = (((SInt32)uVar34 >> 6) + (UInt32)((SInt32)uVar34 < 0 && (uVar34 & 0x3f) != 0)) * 0x40;
        uVar34 = (UInt32)(SInt32)fVar18;
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
        if ((SInt32)opcode < (SInt32)uVar41) {
          uVar34 = (SInt32)((uVar41 - opcode) + 0xf7f) / 0xf80 & 0xff;
        }
        opcode = pitchPixels * uVar34 & 0xff;
        if (opcode == 0) goto LAB_0002d820;
        bVar1 = false;
        if (uVar34 != 0) {
          uVar78 = uVar37 - uVar57;
          uVar60 = 0;
          iVar59 = 0;
          uVar41 = uVar57;
          puVar54 = puVar42;
          do {
            if (pitchPixels != 0) {
              uVar44 = iVar59 + uVar57;
              local_d8 = 0x43300000;
              uVar46 = uVar53 - uVar73;
              iVar33 = 0;
              uStack_d4 = uVar44 ^ 0x80000000;
              fVar4 = (float)((double)CONCAT44d(0x43300000,uVar44 ^ 0x80000000) - dVar31);
              uVar47 = uVar73;
              uVar81 = pitchPixels;
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
                if (iVar33 != pitchPixels - 1) {
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
                uVar50 = (UInt32)(SInt32)((fVar19 - fVar29) * fVar30);
                puVar54[4] = 0x31080;
                puVar54[6] = FBITS(fVar27 * (fVar21 - fVar4));
                puVar54[8] = FBITS(fVar27 * (fVar7 - fVar4));
                puVar54[9] = 0x1087;
                fVar7 = (float)((double)CONCAT44d(0x43300000,uStack_ec) - dVar31);
                puVar54[7] = FBITS(fVar25 * (fVar8 - fVar7));
                puVar54[5] = FBITS(fVar25 * (fVar6 - fVar7));
                local_e8 = (SInt64)iVar74;
                local_e0 = (SInt64)(SInt32)uVar50;
                puVar54[0xb] = 0xc0033500;
                puVar54[0xc] = 0x10031;
                puVar54[0xd] = FBITS((fVar20 + fVar26) * fVar23);
                puVar54[0xe] = FBITS((fVar29 + fVar19) * fVar23);
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
      pitchPixels = 0x20 / M<UInt16>(pAVar72 + 0x16);
      if (0x20 / M<UInt16>(pAVar72 + 0x16) <= uVar73) {
        pitchPixels = uVar73;
      }
      uVar15 = M<UInt16>(pAVar72 + 0x20);
      AVar11 = pAVar72[0x38];
      iVar33 = M<SInt32>(pAVar72 + 8);
      iVar59 = M<SInt32>(pAVar72 + uVar75 * 4 + 0x40);
      iVar74 = M<SInt32>(pAVar72 + uVar75 * 4 + 0x44);
      if (bVar1) {
        puVar42 = recordCursor + 0xc9;
      }
      else {
        iVar49 = 0;
        if (opcode != 0) {
          iVar49 = 0;
          puVar54 = puVar42;
          do {
            if ((UInt8)AVar11 >> 1 == 0) {
              formatFieldDC = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
              iVar39 = 0;
            }
            else {
              formatFieldDC = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)AVar10 * 0x1c);
              iVar39 = -(formatFieldDC >> 8 & 3);
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
                         iVar39 + (pitchPixels * puVar54[1] << uVar73) & 0xffffffe0 |
                         ((UInt8)AVar11 & 1) << 2 | ((UInt8)AVar11 >> 1 & 3) << 3;
            uVar75 = puVar54[2];
            uVar73 = recordCursor[0xa6];
            puVar54[2] = 0x1120;
            puVar54[3] = (puVar54[3] - 1) * 0x800 & 0x3ff800 |
                         uVar75 - 1 & 0x7ff | uVar73 & 0xffc00000;
            puVar54 = puVar54 + 0x10;
            opcode = opcode - 1;
          } while (opcode != 0);
          iVar49 = iVar49 * 0x10;
        }
        puVar42 = puVar42 + iVar49;
      }
      if (puVar42 < recordPayloadEnd) {
        opcode = 0x80000000;
        if (3 < ((SInt32)recordPayloadEnd - (SInt32)puVar42) - 4U) {
          opcode = (((SInt32)recordPayloadEnd - (SInt32)puVar42 >> 2) + -2) * 0x10000 | 0xc0001000;
        }
        *puVar42 = opcode;
      }
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
    }
LAB_00031340:
    uVar55 = pendingWords + uVar63;
    recordCursor = (UInt32 *)((SInt32)recordCursor + iVar52);
    if (uVar63 == 0) {
      if ((uVar55 & 1) != 0) {
        *recordCursor = 0x80000000;
        uVar55 = pendingWords + 1;
        recordCursor = recordCursor + 1;
      }
      M<UInt32>(descriptorBytes) = (streamOffset & 0xfffffffc) + M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x20;
      iVar52 = M<SInt32>(self + kIOATIR500GLContext_commandBufferGartOffset);
      M<UInt32 *>(descriptorBytes + 0xc) = recordCursor;
      M<UInt32>(descriptorBytes + 8) = uVar55;
      M<UInt32>(descriptorBytes + 4) = iVar52 + streamOffset + 0x20;
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x78) = 0;
      return result;
    }
  } while( true );
}
