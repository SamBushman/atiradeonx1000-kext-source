/*
 * IOATIR500DVDContext_clientMemoryForType_Port.cpp
 *
 * IOATIR500DVDContext::clientMemoryForType (real addr 0xf0c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0xf0c0 */
IOReturn IOATIR500DVDContext::clientMemoryForType(UInt32 param_1, UInt32*param_2, IOMemoryDescriptor**param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  unsigned int uVar1;
  int *piVar2;
  unsigned int uVar3;
  int iVar4;
  int iVar5;
  UInt32 uVar6;
  unsigned int uVar7;
  UInt8 *this_00;
  int iVar8;
  UInt8 *pIVar9;
  int *piVar10;
  UInt8 *pIVar11;
  /* one 16-byte stack object filled by the +0x5ac/+0x5b4/+0x560 callees (Ghidra named its words auStack_58 and local_50; #85) */
  int auStack_58[4];
  SInt32 rv5b4 = 0;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  if (param_1 != 1) {
    if (param_1 == 0) {
      if (M<int *>(M<int>(self + 0x8c) + 0xac) != (int *)0x0) {
        VCALL(*M<int *>(M<int>(self + 0x8c) + 0xac), 0x14)(M<int *>(M<int>(self + 0x8c) + 0xac));
        *param_2 = 0;
        *param_3 = M<IOMemoryDescriptor *>(M<int>(self + 0x8c) + 0xac);
        return 0;
      }
    }
    else {
      if (param_1 == 2) {
        GH_IOLockLock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
        VCALL(*M<int *>(self + 0xb4), 0x14)(M<int *>(self + 0xb4));
        *param_2 = 0;
        *param_3 = M<IOMemoryDescriptor *>(self + 0xb4);
        this->init_context_buffer_header((VendorContextBufferHeader *)(M<VendorContextBufferHeader *>(self + 0xc0)),0x1000);
        GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
        return 0;
      }
      if (param_1 != 3) {
        return 0xe00002c2;
      }
      if (M<int *>(M<int>(self + 0x8c) + 0xb0) != (int *)0x0) {
        VCALL(*M<int *>(M<int>(self + 0x8c) + 0xb0), 0x14)(M<int *>(M<int>(self + 0x8c) + 0xb0));
        *param_2 = 0;
        *param_3 = M<IOMemoryDescriptor *>(M<int>(self + 0x8c) + 0xb0);
        return 0;
      }
    }
    return 0xe00002be;
  }
  uVar7 = 0;
  do {
    GH_IOLockLock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
    this_00 = M<UInt8 *>(self + 0xf8);
    if (this_00 == (UInt8 *)0x0) {
LAB_0000f330:
      uVar6 = 0;
LAB_0000f334:
      VCALL(M<int>(self), 0x5b8)(self);
      M<UInt32>(M<int>(self + 0x8c) + 0x78) = 0;
LAB_0000f800:
      VCALL(*M<int *>(self + 0x98), 0x14)(M<int *>(self + 0x98));
      *param_2 = 0;
      *param_3 = M<IOMemoryDescriptor *>(self + 0x98);
      this->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + 0xa4)),M<UInt32>(self + 0xa8),uVar6);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
      return 0;
    }
    if (M<unsigned int>(this_00 + 0xa4) < 0x100) {
LAB_0000f180:
      iVar8 = M<int>(self + 0x8c);
    }
    else {
      iVar8 = M<int>(self + 0x8c);
      if (M<char>(iVar8 + 0x80) == '\0') {
        do {
          GH_IOLockSleep(M<UInt32>(iVar8 + 0x840),iVar8,0);
        } while (M<char>(iVar8 + 0x80) == '\0');
        this_00 = M<UInt8 *>(self + 0xf8);
        if (this_00 != (UInt8 *)0x0) goto LAB_0000f180;
        goto LAB_0000f330;
      }
    }
    if (M<char>(iVar8 + 0x80) == '\0') goto LAB_0000f330;
    if (this_00[0xbf6] == 0x0) {
      uVar6 = M<unsigned int>(this_00 + 0xbfc) | 2;
      if ((this_00[0xbd0] == 0x0) || (uVar7 == 999)) {
        uVar3 = M<unsigned int>(this_00 + 0xbf8);
        if (((M<unsigned int>(self + 0x88) | M<unsigned int>(this_00 + 0xc1c)) & uVar3) != 0) {
          if ((uVar3 & 0x20000000) != 0) goto LAB_0000f334;
          uVar1 = (M<unsigned int>(self + 0x88) | M<unsigned int>(this_00 + 0xc1c)) & 0x7fffff;
          if ((uVar3 & uVar1) == 0) {
            iVar8 = M<int>(this_00);
          }
          else {
            iVar8 = ((IOATIR500Surface *)((UInt32)this_00))->alloc_surfaces(uVar1, false);
            if (iVar8 != 0) {
              if (iVar8 != 2) goto LAB_0000f2b8;
              goto LAB_0000f334;
            }
            this_00 = M<UInt8 *>(self + 0xf8);
            if ((M<unsigned int>(this_00 + 0xbf8) & M<unsigned int>(this_00 + 0xc1c) & 0x10000000) == 0)
            goto LAB_0000f264;
            iVar8 = M<int>(this_00);
          }
          VCALL(iVar8, 0x5c0)(this_00);
          M<unsigned int>(M<int>(self + 0xf8) + 0xbf8) =
               M<unsigned int>(M<int>(self + 0xf8) + 0xbf8) & 0xefffffff;
        }
LAB_0000f264:
        if (uVar7 < 1000) {
LAB_0000f380:
          pIVar9 = self;
          do {
            if (M<UInt8 *>(pIVar9 + 0x104) != (UInt8 *)0x0) {
              this->add_texture_to_stream((VendorTextureBuffer *)(M<UInt8 *>(pIVar9 + 0x104)));
            }
            pIVar9 = pIVar9 + 4;
          } while (self + 0x48 != pIVar9);
          if (self != M<UInt8 *>(M<int>(self + 0x8c) + 0x78)) {
            VCALL(M<int>(self), 0x5b0)(self);
            M<int>(M<int>(self + 0x8c) + 0x748) = M<int>(M<int>(self + 0x8c) + 0x748) + 1;
            M<UInt8 *>(M<int>(self + 0x8c) + 0x78) = self;
          }
          if (M<int>(self + 0x94) == 0) {
            this->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0x90)));
          }
          /* the decompile dropped this call's result (shipped: `or r28,r3,r3` at 0xf428, tested at 0xf534) */
          rv5b4 = VCALL(M<int>(self), 0x5b4)(self,auStack_58);
          pIVar9 = self;
          do {
            if (M<UInt8 *>(pIVar9 + 0x104) != (UInt8 *)0x0) {
              this->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(pIVar9 + 0x104)));
            }
            pIVar9 = pIVar9 + 4;
          } while (self + 0x48 != pIVar9);
          if (auStack_58[2] == 0) {
            iVar8 = M<int>(M<int>(self + 0x8c) + 0x50) + -1;
          }
          else {
            M<int>(M<int>(self + 0x8c) + 0x708) =
                 auStack_58[2] * 4 + M<int>(M<int>(self + 0x8c) + 0x708);
            iVar8 = VCALL(*M<int *>(self + 0x8c), 0x560)
                              (M<int *>(self + 0x8c),auStack_58);
          }
          piVar2 = M<int *>(self + 0xf8);
          iVar8 = VCALL(*piVar2, 0x5b4)(piVar2,iVar8,M<UInt32>(self + 0x88));
          piVar2[0x1f] = iVar8;
          M<int>(self + 0x7c) = iVar8;
          M<int>(self + 0xa0) = iVar8;
          iVar8 = M<int>(self + 0xf8);
          if (iVar8 != M<int>(M<int>(self + 0x8c) + 0x5c)) {
            M<UInt32>(M<int>(iVar8 + 0x9c) + 0xa0) = M<UInt32>(iVar8 + 0xa0);
            M<UInt32>(M<int>(M<int>(self + 0xf8) + 0xa0) + 0x9c) =
                 M<UInt32>(M<int>(self + 0xf8) + 0x9c);
            iVar8 = M<int>(M<int>(self + 0x8c) + 0x5c);
            M<int>(M<int>(self + 0xf8) + 0x9c) = iVar8;
            iVar4 = M<int>(iVar8 + 0xa0);
            M<int>(M<int>(self + 0xf8) + 0xa0) = iVar4;
            M<UInt32>(iVar8 + 0xa0) = M<UInt32>(self + 0xf8);
            M<UInt32>(iVar4 + 0x9c) = M<UInt32>(self + 0xf8);
            M<UInt32>(M<int>(self + 0x8c) + 0x5c) = M<UInt32>(self + 0xf8);
          }
          /* RECOVERED from the shipped disassembly (0xf534-0xf5e8): Ghidra's decompile omitted this whole block (no 0xcac / 0x5d4 / 0x74c / 0x79c / 0x558
           * anywhere in it; the 2D twin of this method has it). Runs only when the +0x5b4 call above returned non-zero and this path took the
           * `uVar6 = 0` exit (the other path ORs 2 into uVar6). #85 */
          if ((rv5b4 != 0) && ((uVar6 & 2) == 0)) {
            UInt8 *surf = M<UInt8 *>(self + 0xf8);
            UInt32 savedField = M<UInt32>(surf + 0x84);
            UInt8 *accel = M<UInt8 *>(self + 0x8c);
            UInt32 idx = 0, off = 0;
            M<UInt32>(surf + 0x84) = M<UInt32>(surf + 0x80);
            if (M<UInt32>(accel + 0xcc) != 0) {
              do {
                UInt8 *s2 = M<UInt8 *>(self + 0xf8);
                if (M<UInt8>(s2 + off + 0xcac) != 0) {
                  VCALL(*M<SInt32 *>(s2), 0x5d4)(s2, idx, 0);
                  M<UInt32>(M<UInt8 *>(self + 0x8c) + 0x74c) = M<UInt32>(M<UInt8 *>(self + 0x8c) + 0x74c) + 1;
                  accel = M<UInt8 *>(self + 0x8c);
                }
                idx = idx + 1;
                off = off + 0x94;
              } while (idx < M<UInt32>(accel + 0xcc));
            }
            {
              UInt32 acc = M<UInt32>(accel + 0x79c);
              acc = acc + VCALL(*M<SInt32 *>(accel), 0x558)(accel, savedField);
              M<UInt32>(accel + 0x79c) = acc;
            }
          }
          piVar10 = M<int *>(self + 0x8c);
          piVar2 = piVar10 + (unsigned int)M<UInt16>(piVar10 + 0x100) * 7 + 0x90;
          if ((unsigned int)piVar10[0x172] < 0x80000) {
            piVar10[0x172] = 0x80000;
            piVar10 = M<int *>(self + 0x8c);
          }
          iVar8 = VCALL(*piVar10, 0x554)(piVar10,piVar2[4]);
          if (iVar8 == 0) {
            pIVar11 = M<UInt8 *>(self + 0x8c);
            if (M<UInt16>(pIVar11 + 0x402) < 0x10) {
              iVar8 = ((IOATIR500Accelerator *)(pIVar11))->allocMoreCommandBuffers(0, 0x80000);
              if (iVar8 != 0) {
                iVar8 = M<int>(self + 0x8c);
                piVar2 = (int *)(iVar8 + (unsigned int)M<UInt16>(iVar8 + 0x400) * 0x1c + 0x240);
                goto LAB_0000f6bc;
              }
              pIVar11 = M<UInt8 *>(self + 0x8c);
            }
            iVar4 = M<int>(pIVar11 + 0x774);
            iVar8 = VCALL(M<int>(pIVar11), 0x54c)(pIVar11,piVar2[4]);
            M<int>(pIVar11 + 0x774) = iVar4 + iVar8;
            iVar8 = M<int>(self + 0x8c);
          }
          else {
            iVar8 = M<int>(self + 0x8c);
          }
LAB_0000f6bc:
          M<UInt16>(iVar8 + 0x400) =
               M<SInt16>(iVar8 + 0x400) + 1U & M<SInt16>(iVar8 + 0x402) - 1U;
          local_3c = M<int>(self + 0x9c);
          local_38 = M<int>(self + 0xa0);
          local_34 = M<int>(self + 0xa4);
          local_30 = M<int>(self + 0xa8);
          local_48 = M<int>(self + 0x90);
          local_44 = M<int>(self + 0x94);
          local_40 = M<int>(self + 0x98);
          iVar8 = piVar2[1];
          iVar4 = piVar2[2];
          iVar5 = piVar2[3];
          M<int>(self + 0x90) = *piVar2;
          M<int>(self + 0x94) = iVar8;
          M<int>(self + 0x98) = iVar4;
          M<int>(self + 0x9c) = iVar5;
          iVar8 = piVar2[5];
          iVar4 = piVar2[6];
          M<int>(self + 0xa0) = piVar2[4];
          M<int>(self + 0xa4) = iVar8;
          M<int>(self + 0xa8) = iVar4;
          *piVar2 = local_48;
          piVar2[1] = local_44;
          piVar2[2] = local_40;
          piVar2[3] = local_3c;
          piVar2[4] = local_38;
          piVar2[5] = local_34;
          piVar2[6] = local_30;
          pIVar11 = M<UInt8 *>(self + 0x8c);
          if (M<int>(self + 0xa8) != M<int>(pIVar11 + 0x5c8)) {
            local_3c = 0x10000;
            local_30 = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            local_38 = 0;
            local_34 = 0;
            iVar8 = ((IOATIR500Accelerator *)(pIVar11))->allocCommandBuffer((VendorCommandBuffer *)((UInt8 *)&local_48),M<UInt32>(pIVar11 + 0x5c8))
            ;
            if (iVar8 != 0) {
              ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x8c)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + 0x90)));
              M<int>(self + 0x94) = local_44;
              M<int>(self + 0x98) = local_40;
              M<int>(self + 0x9c) = local_3c;
              M<int>(self + 0xa0) = local_38;
              M<int>(self + 0xa4) = local_34;
              M<int>(self + 0xa8) = local_30;
              M<int>(self + 0x90) = local_48;
            }
          }
          goto LAB_0000f800;
        }
        if (uVar7 < 0x3e9) goto LAB_0000f2ec;
        goto LAB_0000f334;
      }
LAB_0000f2b8:
      if (uVar7 == 1000) {
LAB_0000f2ec:
        iVar8 = ((IOATIR500Surface *)(M<UInt32>(self + 0xf8)))->alloc_surfaces((M<UInt32>(self + 0x88) | M<UInt32>(M<UInt32>(self + 0xf8) + 0xc1c)) & 0x7fffff, true);
        if (iVar8 == 0) {
          piVar2 = M<int *>(self + 0xf8);
          if ((piVar2[0x2fe] & piVar2[0x307] & 0x10000000U) != 0) {
            VCALL(*piVar2, 0x5c0)(piVar2);
            M<unsigned int>(M<int>(self + 0xf8) + 0xbf8) =
                 M<unsigned int>(M<int>(self + 0xf8) + 0xbf8) & 0xefffffff;
          }
          goto LAB_0000f380;
        }
        goto LAB_0000f334;
      }
      uVar7 = uVar7 + 1;
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
      GH_thread_block(0);
      GH_IOSleep(1);
    }
    else {
      VCALL(M<int>(this_00), 0x14)(this_00);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
      ((IOATIR500Surface *)(this_00))->sleep_blocked();
      VCALL(M<int>(this_00), 0x18)(this_00);
    }
  } while( true );
}
