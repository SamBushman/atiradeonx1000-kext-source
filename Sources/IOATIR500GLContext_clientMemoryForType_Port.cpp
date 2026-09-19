/*
 * IOATIR500GLContext_clientMemoryForType_Port.cpp
 *
 * IOATIR500GLContext::clientMemoryForType (real addr 0xa160, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(...) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");
extern "C" UInt32 GH_memcpy(...) asm("_memcpy");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0xa160 */
IOReturn IOATIR500GLContext::clientMemoryForType(UInt32 param_1, UInt32*param_2, IOMemoryDescriptor**param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  unsigned int uVar2;
  int iVar3;
  unsigned int uVar4;
  UInt8 uVar7;
  int *piVar5;
  UInt32 uVar6;
  unsigned int uVar8;
  int iVar9;
  int iVar10;
  unsigned int uVar11;
  UInt32 uVar12;
  UInt8 *pIVar13;
  UInt8 *this_00;
  UInt8 *pIVar14;
  unsigned int uVar15;
  int *piVar16;
  UInt8 auStack_68 [8];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  
  iVar3 = GH_page_size;
  switch(param_1) {
  case 0:
    if (M<int *>(M<int>(self + 200) + 0xac) != (int *)0x0) {
      VCALL(*M<int *>(M<int>(self + 200) + 0xac), 0x14)(M<int *>(M<int>(self + 200) + 0xac));
      *param_2 = 0;
      *param_3 = (IOMemoryDescriptor *)(M<UInt8 *>(M<int>(self + 200) + 0xac));
      return 0;
    }
    break;
  case 1:
    uVar11 = 0;
    uVar15 = 0;
    uVar7 = 0;
LAB_0000a1e0:
    do {
      GH_IOLockLock(M<UInt32>(M<int>(self + 200) + 0x840));
      this_00 = M<UInt8 *>(self + 0x290);
      if (this_00 == (UInt8 *)0x0) {
LAB_0000a480:
        uVar12 = 0;
LAB_0000a484:
        bVar1 = false;
        VCALL(M<int>(self), 0x5b8)(self);
        M<UInt32>(M<int>(self + 200) + 0x78) = 0;
LAB_0000ab68:
        iVar3 = M<int>(self + 0xe8);
        if (M<int>(self + 0xe8) != M<int>(self + 0xec)) {
          do {
            iVar10 = M<int>(iVar3 + 0x3c);
            iVar9 = M<int>(M<int>(self + 200) + 0x5d0);
            if (iVar9 == 0) {
              M<int>(M<int>(self + 200) + 0x5cc) = iVar3;
              M<int>(M<int>(self + 200) + 0x5d0) = iVar3;
              M<UInt32>(iVar3 + 0x3c) = 0;
            }
            else {
              M<int>(iVar9 + 0x3c) = iVar3;
              M<int>(M<int>(self + 200) + 0x5d0) = iVar3;
              M<UInt32>(iVar3 + 0x3c) = 0;
            }
            M<int>(M<int>(self + 200) + 0x5d4) = M<int>(M<int>(self + 200) + 0x5d4) + 1;
            M<UInt8>(iVar3 + 0x54) = 0;
            iVar3 = iVar10;
          } while (M<int>(self + 0xec) != iVar10);
          M<int>(self + 0xe8) = iVar10;
          M<UInt32>(iVar10 + 0x3c) = 0;
          M<UInt32>(self + 0xf0) = 1;
        }
        VCALL(*M<int *>(self + 0xd4), 0x14)(M<int *>(self + 0xd4));
        *param_2 = 0;
        *param_3 = (IOMemoryDescriptor *)(M<UInt8 *>(self + 0xd4));
        this->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + 0xe0)),M<UInt32>(self + 0xe4),uVar12)
        ;
        GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
        if (!bVar1) {
          return 0;
        }
        piVar5 = M<int *>(self + 200);
        iVar9 = piVar5[0x1e6];
        iVar3 = VCALL(*piVar5, 0x55c)
                          (piVar5,M<UInt32>(self + M<int>(self + 0xa8) * 4 + 0x9c));
        piVar5[0x1e6] = iVar9 + iVar3;
        return 0;
      }
      if (M<unsigned int>(this_00 + 0xa4) < 0x100) {
LAB_0000a250:
        iVar3 = M<int>(self + 200);
      }
      else {
        iVar3 = M<int>(self + 200);
        if (M<char>(iVar3 + 0x80) == '\0') {
          do {
            GH_IOLockSleep(M<UInt32>(iVar3 + 0x840),iVar3,0);
          } while (M<char>(iVar3 + 0x80) == '\0');
          this_00 = M<UInt8 *>(self + 0x290);
          if (this_00 != (UInt8 *)0x0) goto LAB_0000a250;
          goto LAB_0000a480;
        }
      }
      if (M<char>(iVar3 + 0x80) == '\0') goto LAB_0000a480;
      if (this_00[0xbf6] == 0x0) {
        uVar12 = M<UInt32>(this_00 + 0xbfc);
        if ((M<SInt16>(self + 0x98) != 0) && ((M<unsigned int>(this_00 + 0xbe8) & 0x20) != 0)) {
          uVar12 = uVar12 | 2;
        }
        if ((this_00[0xbd0] == 0x0) || (uVar15 == 999)) {
          uVar8 = M<unsigned int>(this_00 + 0xbf8);
          if (((M<unsigned int>(self + 0x8c) | M<unsigned int>(this_00 + 0xc1c)) & uVar8) != 0) {
            if ((uVar8 & 0x20000000) != 0) goto LAB_0000a484;
            uVar2 = (M<unsigned int>(self + 0x8c) | M<unsigned int>(this_00 + 0xc1c)) & 0x7fffff;
            uVar4 = uVar8 & uVar2;
            if (uVar4 == 0) {
              iVar3 = M<int>(this_00);
            }
            else {
              if ((((uVar4 & 1) != 0) && (M<int>(this_00 + 0xcc) == 0)) &&
                 (((uVar8 & 2) == 0 || (M<int>(this_00 + 0x144) != 0)))) {
                uVar11 = uVar11 | 1;
              }
              if (((M<unsigned int>(this_00 + 0xbe8) & 0x20) == 0) && ((uVar4 & 0x20) != 0)) {
                uVar11 = uVar11 | 2;
              }
              uVar7 = ((IOATIR500Surface *)(this_00))->convert_surface_bits(M<UInt32>(M<int>(self + 0xe0) + 0xc));
              iVar3 = ((IOATIR500Surface *)(M<UInt32>(self + 0x290)))->alloc_surfaces_pageq(uVar2,uVar7,false);   /* r6 = 0: the decompile drops the register args after the mask; checked against the disassembly at 0xa3c4 */
              if (iVar3 != 0) {
                if (iVar3 != 2) goto LAB_0000a408;
                goto LAB_0000a484;
              }
              this_00 = M<UInt8 *>(self + 0x290);
              if ((M<unsigned int>(this_00 + 0xbf8) & M<unsigned int>(this_00 + 0xc1c) & 0x10000000) == 0)
              goto LAB_0000a354;
              iVar3 = M<int>(this_00);
            }
            VCALL(iVar3, 0x5c0)(this_00);
            M<unsigned int>(M<int>(self + 0x290) + 0xbf8) =
                 M<unsigned int>(M<int>(self + 0x290) + 0xbf8) & 0xefffffff;
          }
LAB_0000a354:
          if (999 < uVar15) {
            if (uVar15 < 0x3e9) goto LAB_0000a43c;
            goto LAB_0000a484;
          }
        }
        else {
LAB_0000a408:
          if (uVar15 != 1000) {
            uVar15 = uVar15 + 1;
            GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
            GH_thread_block(0);
            GH_IOSleep(1);
            goto LAB_0000a1e0;
          }
LAB_0000a43c:
          iVar3 = ((IOATIR500Surface *)(M<UInt32>(self + 0x290)))->alloc_surfaces_pageq((M<unsigned int>(self + 0x8c) | M<unsigned int>(M<UInt32>(self + 0x290) + 0xc1c))
                             & 0x7fffff,uVar7,true);   /* r6 = 1 (disassembly 0xa448) */
          if (iVar3 != 0) goto LAB_0000a484;
          piVar5 = M<int *>(self + 0x290);
          if ((piVar5[0x2fe] & piVar5[0x307] & 0x10000000U) != 0) {
            VCALL(*piVar5, 0x5c0)(piVar5);
            M<unsigned int>(M<int>(self + 0x290) + 0xbf8) =
                 M<unsigned int>(M<int>(self + 0x290) + 0xbf8) & 0xefffffff;
          }
        }
        if (uVar11 != 0) {
          if ((uVar11 & 1) != 0) {
            VCALL(*M<int *>(self + 0x290), 0x5d8)(M<int *>(self + 0x290),0,1,self);
            M<int>(M<int>(self + 200) + 0x74c) = M<int>(M<int>(self + 200) + 0x74c) + 1;
          }
          if ((uVar11 & 2) != 0) {
            piVar5 = M<int *>(self + 0x290);
            if ((1 << (piVar5[0x305] & 0x3fU) & M<unsigned int>(M<int>(self + 200) + 0xd0)) != 0) {
              VCALL(*piVar5, 0x5e0)(piVar5,piVar5[0x305],self,0);
              M<int>(M<int>(self + 200) + 0x74c) = M<int>(M<int>(self + 200) + 0x74c) + 1;
            }
          }
        }
        pIVar14 = self;
        do {
          if (M<UInt8 *>(pIVar14 + 0x2a4) != (UInt8 *)0x0) {
            this->add_texture_to_stream((VendorTextureBuffer *)(M<UInt8 *>(pIVar14 + 0x2a4)));
          }
          pIVar14 = pIVar14 + 4;
        } while (self + 0xa8 != pIVar14);
        if (self != M<UInt8 *>(M<int>(self + 200) + 0x78)) {
          VCALL(M<int>(self), 0x5b0)(self);
          M<int>(M<int>(self + 200) + 0x740) = M<int>(M<int>(self + 200) + 0x740) + 1;
          M<UInt8 *>(M<int>(self + 200) + 0x78) = self;
        }
        VCALL(*M<int *>(self + 0x290), 0x5b8)
                  (M<int *>(self + 0x290),M<UInt32>(self + 0x8c));
        if (M<int>(self + 0xd0) == 0) {
          this->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
        }
        uVar11 = VCALL(M<int>(self), 0x5b4)(self,auStack_68);
        pIVar14 = self;
        do {
          if (M<UInt8 *>(pIVar14 + 0x2a4) != (UInt8 *)0x0) {
            this->remove_texture_from_stream((VendorTextureBuffer *)(M<UInt8 *>(pIVar14 + 0x2a4)));
          }
          pIVar14 = pIVar14 + 4;
        } while (self + 0xa8 != pIVar14);
        if (((unsigned int)(M<int>(M<int>(self + 0xe0) + 0x10) * 4 - GH_page_size) <
             (unsigned int)(local_5c - (M<int>(self + 0xe0) + 0x20))) &&
           (M<unsigned int>(self + 0xb0) < 0x80000)) {
          M<unsigned int>(self + 0xb0) = M<unsigned int>(self + 0xb0) << 1;
        }
        if (local_60 == 0) {
          iVar3 = M<int>(M<int>(self + 200) + 0x50) + -1;
        }
        else {
          M<int>(M<int>(self + 200) + 0x704) =
               local_60 * 4 + M<int>(M<int>(self + 200) + 0x704);
          iVar3 = VCALL(*M<int *>(self + 200), 0x560)(M<int *>(self + 200),auStack_68);
        }
        piVar5 = M<int *>(self + 0x290);
        iVar3 = VCALL(*piVar5, 0x5b4)(piVar5,iVar3,M<UInt32>(self + 0x8c));
        piVar5[0x1f] = iVar3;
        M<int>(self + 0x7c) = iVar3;
        M<int>(self + 0xdc) = iVar3;
        piVar5 = M<int *>(self + 0x290);
        if (piVar5 != M<int *>(M<int>(self + 200) + 0x5c)) {
          M<int>(piVar5[0x27] + 0xa0) = piVar5[0x28];
          M<UInt32>(M<int>(M<int>(self + 0x290) + 0xa0) + 0x9c) =
               M<UInt32>(M<int>(self + 0x290) + 0x9c);
          iVar3 = M<int>(M<int>(self + 200) + 0x5c);
          M<int>(M<int>(self + 0x290) + 0x9c) = iVar3;
          iVar9 = M<int>(iVar3 + 0xa0);
          M<int>(M<int>(self + 0x290) + 0xa0) = iVar9;
          M<UInt32>(iVar3 + 0xa0) = M<UInt32>(self + 0x290);
          M<UInt32>(iVar9 + 0x9c) = M<UInt32>(self + 0x290);
          M<UInt32>(M<int>(self + 200) + 0x5c) = M<UInt32>(self + 0x290);
          piVar5 = M<int *>(self + 0x290);
        }
        VCALL(*piVar5, 0x5bc)(piVar5,M<UInt32>(self + 0x8c));
        if ((uVar12 & 2) != 0) {
          uVar11 = uVar11 & 1;
        }
        if (uVar11 == 0) {
          piVar5 = M<int *>(self + 200);
LAB_0000a8f4:
          bVar1 = false;
        }
        else {
          M<UInt32>(M<int>(self + 0x290) + 0x84) =
               M<UInt32>(M<int>(self + 0x290) + 0x80);
          piVar5 = M<int *>(self + 0x290);
          if ((piVar5[0x2fa] & 0x20U) == 0) {
            iVar3 = VCALL(*piVar5, 0x5dc)(piVar5);
            if (iVar3 == 0) {
              piVar5 = M<int *>(self + 0x290);
              goto LAB_0000a7f8;
            }
            iVar3 = M<int>(self + 0x290);
            uVar6 = M<UInt32>(iVar3 + 0xb74);
            uVar11 = M<unsigned int>(iVar3 + 0xc14);
            M<UInt32>(iVar3 + 0xb74) = M<UInt32>(iVar3 + 0xb70);
            M<UInt32>(M<int>(self + 0x290) + 0xb70) = uVar6;
            iVar3 = M<int>(self + 0x290);
            uVar6 = M<UInt32>(iVar3 + 0xb80);
            M<UInt32>(iVar3 + 0xb80) = M<UInt32>(iVar3 + 0xb84);
            M<UInt32>(M<int>(self + 0x290) + 0xb84) = uVar6;
            piVar5 = M<int *>(self + 200);
            if ((1 << (uVar11 & 0x3f) & piVar5[0x34]) != 0) {
              VCALL(*M<int *>(self + 0x290), 0x5e0)(M<int *>(self + 0x290),uVar11,self,0)
              ;
              M<int>(M<int>(self + 200) + 0x74c) = M<int>(M<int>(self + 200) + 0x74c) + 1;
              piVar5 = M<int *>(self + 200);
            }
          }
          else {
LAB_0000a7f8:
            uVar15 = 0;
            iVar3 = 0;
            while( true ) {
              uVar8 = uVar11;
              if ((M<char>((int)piVar5 + iVar3 + 0xcac) != '\0') ||
                 (uVar8 = uVar11 & 1, uVar8 != 0)) {
                VCALL(*piVar5, 0x5d8)(piVar5,uVar15,uVar8,self);
                M<int>(M<int>(self + 200) + 0x74c) = M<int>(M<int>(self + 200) + 0x74c) + 1;
              }
              piVar5 = M<int *>(self + 200);
              uVar15 = uVar15 + 1;
              iVar3 = iVar3 + 0x94;
              if (((unsigned int)piVar5[0x33] <= uVar15) || (uVar11 = uVar11 & 0xfffffffe, uVar11 == 0))
              break;
              piVar5 = M<int *>(self + 0x290);
            }
          }
          if (M<SInt16>(self + 0x9a) == 0) goto LAB_0000a8f4;
          iVar3 = M<int>(self + 0xa8);
          bVar1 = true;
          M<UInt32>(self + iVar3 * 4 + 0x9c) = M<UInt32>(M<int>(self + 0x290) + 0x84);
          M<unsigned int>(self + 0xa8) = (iVar3 + 1U) % 3;
        }
        if ((unsigned int)piVar5[0x172] < M<unsigned int>(self + 0xb0)) {
          piVar5[0x172] = M<unsigned int>(self + 0xb0);
          piVar5 = M<int *>(self + 200);
        }
        piVar16 = piVar5 + (unsigned int)M<UInt16>(piVar5 + 0x100) * 7 + 0x90;
        iVar3 = VCALL(*piVar5, 0x554)(piVar5,piVar16[4]);
        if (iVar3 == 0) {
          pIVar13 = M<UInt8 *>(self + 200);
          if (M<UInt16>(pIVar13 + 0x402) < 0x10) {
            iVar3 = ((IOATIR500Accelerator *)(pIVar13))->allocMoreCommandBuffers(0,M<UInt32>(pIVar13 + 0x5c8));
            if (iVar3 != 0) {
              iVar3 = M<int>(self + 200);
              piVar16 = (int *)(iVar3 + (unsigned int)M<UInt16>(iVar3 + 0x400) * 0x1c + 0x240);
              goto LAB_0000a9bc;
            }
            pIVar13 = M<UInt8 *>(self + 200);
          }
          iVar9 = M<int>(pIVar13 + 0x770);
          iVar3 = VCALL(M<int>(pIVar13), 0x54c)(pIVar13,piVar16[4]);
          M<int>(pIVar13 + 0x770) = iVar9 + iVar3;
          iVar3 = M<int>(self + 200);
        }
        else {
          iVar3 = M<int>(self + 200);
        }
LAB_0000a9bc:
        M<UInt16>(iVar3 + 0x400) = M<SInt16>(iVar3 + 0x400) + 1U & M<SInt16>(iVar3 + 0x402) - 1U
        ;
        local_4c = M<int>(self + 0xd8);
        local_48 = M<int>(self + 0xdc);
        local_44 = M<int>(self + 0xe0);
        local_40 = M<int>(self + 0xe4);
        local_58 = M<int>(self + 0xcc);
        local_54 = M<int>(self + 0xd0);
        local_50 = M<int>(self + 0xd4);
        iVar3 = piVar16[1];
        iVar9 = piVar16[2];
        iVar10 = piVar16[3];
        M<int>(self + 0xcc) = *piVar16;
        M<int>(self + 0xd0) = iVar3;
        M<int>(self + 0xd4) = iVar9;
        M<int>(self + 0xd8) = iVar10;
        iVar3 = piVar16[5];
        iVar9 = piVar16[6];
        M<int>(self + 0xdc) = piVar16[4];
        M<int>(self + 0xe0) = iVar3;
        M<int>(self + 0xe4) = iVar9;
        *piVar16 = local_58;
        piVar16[1] = local_54;
        piVar16[2] = local_50;
        piVar16[3] = local_4c;
        piVar16[4] = local_48;
        piVar16[5] = local_44;
        piVar16[6] = local_40;
        pIVar13 = M<UInt8 *>(self + 200);
        if (M<int>(self + 0xe4) != M<int>(pIVar13 + 0x5c8)) {
          local_4c = 0x10000;
          local_40 = 0;
          local_58 = 0;
          local_54 = 0;
          local_50 = 0;
          local_48 = 0;
          local_44 = 0;
          iVar3 = ((IOATIR500Accelerator *)(pIVar13))->allocCommandBuffer((VendorCommandBuffer *)((UInt8 *)&local_58),M<UInt32>(pIVar13 + 0x5c8));
          if (iVar3 == 0) {
            pIVar13 = M<UInt8 *>(self + 200);
          }
          else {
            this->freeCommandBuffer();
            ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + 0xcc)));
            pIVar13 = M<UInt8 *>(self + 200);
            M<int>(self + 0xd0) = local_54;
            M<int>(self + 0xd4) = local_50;
            M<int>(self + 0xd8) = local_4c;
            M<int>(self + 0xdc) = local_48;
            M<int>(self + 0xe0) = local_44;
            M<int>(self + 0xe4) = local_40;
            M<int>(self + 0xcc) = local_58;
          }
        }
        M<UInt32>(self + 0xdc) = M<UInt32>(self + 0x7c);
        if (pIVar13[0x88] == 0x0) {
          VCALL(*M<int *>(pIVar13 + 0xc0), 300)
                    (M<int *>(pIVar13 + 0xc0),M<UInt32>(pIVar13 + 0x8c));
          M<UInt8>(M<int>(self + 200) + 0x88) = 1;
        }
        else {
          pIVar13[0x89] = 0x1;
        }
        goto LAB_0000ab68;
      }
      VCALL(M<int>(this_00), 0x14)(this_00);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
      ((IOATIR500Surface *)(this_00))->sleep_blocked();
      VCALL(M<int>(this_00), 0x18)(this_00);
    } while( true );
  case 2:
    GH_IOLockLock(M<UInt32>(M<int>(self + 200) + 0x840));
    VCALL(*M<int *>(self + 0xfc), 0x14)(M<int *>(self + 0xfc));
    *param_2 = 0;
    *param_3 = (IOMemoryDescriptor *)(M<UInt8 *>(self + 0xfc));
    this->init_context_buffer_header((VendorContextBufferHeader *)(M<VendorContextBufferHeader *>(self + 0x108)),0x8000);
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
    return 0;
  case 3:
    if (M<int *>(M<int>(self + 200) + 0xb0) != (int *)0x0) {
      VCALL(*M<int *>(M<int>(self + 200) + 0xb0), 0x14)(M<int *>(M<int>(self + 200) + 0xb0));
      *param_2 = 0;
      *param_3 = (IOMemoryDescriptor *)(M<UInt8 *>(M<int>(self + 200) + 0xb0));
      return 0;
    }
    break;
  case 4:
    if (M<int>(self + 0xb8) == 0) {
      M<int>(self + 0xbc) = GH_page_size;
      piVar5 = (int *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,iVar3,GH_page_size);
      M<int *>(self + 0xb8) = piVar5;
      if (piVar5 != (int *)0x0) {
        uVar6 = VCALL(*piVar5, 0x1cc)(piVar5);
        M<UInt32>(self + 0xc0) = uVar6;
LAB_0000ae2c:
        VCALL(*M<int *>(self + 0xb8), 0x14)(M<int *>(self + 0xb8));
        *param_2 = 0;
        *param_3 = (IOMemoryDescriptor *)(M<UInt8 *>(self + 0xb8));
        return 0;
      }
    }
    else {
      iVar3 = M<int>(self + 0xbc);
      piVar5 = (int *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,iVar3 << 1,GH_page_size);
      if (piVar5 != (int *)0x0) {
        uVar6 = VCALL(*piVar5, 0x1cc)(piVar5);
        GH_memcpy(uVar6,M<UInt32>(self + 0xc0),M<UInt32>(self + 0xbc));
        VCALL(*M<int *>(self + 0xb8), 0x18)(M<int *>(self + 0xb8));
        M<int *>(self + 0xb8) = piVar5;
        M<int>(self + 0xbc) = iVar3 << 1;
        M<UInt32>(self + 0xc0) = uVar6;
        goto LAB_0000ae2c;
      }
    }
    break;
  default:
    return 0xe00002c2;
  }
  return 0xe00002be;
}
