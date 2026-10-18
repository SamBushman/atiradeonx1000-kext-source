/*
 * IOATIR500Accelerator_freeToAllocSurfaceVRAM_Port.cpp
 *
 * IOATIR500Accelerator::freeToAllocSurfaceVRAM (real addr 0x45a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45a0 */
UInt32 IOATIR500Accelerator::freeToAllocSurfaceVRAM(IOATIR500Surface *excludeA, IOATIR500Surface *excludeB, VendorTextureBuffer**excludeList, SInt32 excludeCount, ATIR500SurfaceBuffer *needed) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *excludeABytes = reinterpret_cast<UInt8 *>(excludeA);
    UInt8 *excludeBBytes = reinterpret_cast<UInt8 *>(excludeB);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  UInt16 *puVar1;
  UInt16 *puVar2;
  bool secondPass;
  UInt8 *excludedTexture;
  int iVar5;
  int iVar6;
  UInt8 **excludeCursor;
  unsigned int faceIndex;
  UInt8 *surfaceListHead;
  unsigned int uVar10;
  UInt8 *surfaceBuffer;
  UInt8 *texture;
  UInt8 *surface;
  UInt8 excludeAIsNull;
  UInt8 bVar14;
  long excludeLeft;
  unsigned int uVar16;
  
  excludeAIsNull = (excludeABytes == (UInt8 *)0x0) << 1;
  secondPass = false;
  do {
    while( true ) {
      if ((bool)(excludeAIsNull >> 1 & 1)) {
        iVar5 = VCALL(M<int>(self), 0x56c)(self,neededBytes);
      }
      else {
        iVar5 = VCALL(M<int>(excludeABytes), 0x5d0)(excludeABytes,neededBytes);
      }
      if (iVar5 == 1) break;
      texture = M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_next);
      do {
        do {
          while( true ) {
            if (self + kIOATIR500Accelerator_vramBufferList == texture) goto LAB_00004794;
            if (excludeCount < 1) break;
            if (texture != (UInt8 *)*excludeList) {
              iVar5 = 0;
              excludeLeft = excludeCount;
              do {
                iVar5 = iVar5 + 1;
                excludeLeft = excludeLeft + -1;
                if (excludeLeft == 0) goto LAB_00004654;
              } while (texture != (UInt8 *)excludeList[iVar5]);
            }
LAB_000046a0:
            texture = M<UInt8 *>(texture + 0x28);
          }
        } while (excludeCount != 0);
LAB_00004654:
        if ((secondPass) || (iVar5 = M<int>(texture + 0x14), iVar5 == 0)) break;
        uVar10 = (unsigned int)M<UInt8>(iVar5 + 0x34);
        faceIndex = 0;
        if (uVar10 != 0) {
          if ((M<UInt16>(iVar5 + 0x28) & ~M<UInt16>(iVar5 + 0x1c)) == 0) {
            faceIndex = 0;
            uVar16 = uVar10;
            if (uVar10 == 0) {
              uVar16 = 1;
            }
            do {
              faceIndex = faceIndex + 1;
              uVar16 = uVar16 - 1;
              if (uVar16 == 0) goto LAB_000046b8;
              puVar1 = (UInt16 *)(iVar5 + 0x1e);
              puVar2 = (UInt16 *)(iVar5 + 0x2a);
              iVar5 = iVar5 + 2;
            } while ((*puVar2 & ~*puVar1) == 0);
          }
          goto LAB_000046a0;
        }
LAB_000046b8: ;
      } while (faceIndex != uVar10);
      if (M<int>(texture + 0x48) != 0) {
        VCALL(M<int>(self), 0x524)(self,texture);
        M<UInt8>(M<int>(texture + 0x14) + 0x14) = 1;
        M<UInt16>(M<int>(texture + 0x14) + 0x28) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x2a) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x2c) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x2e) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x30) = 0;
        M<UInt16>(M<int>(texture + 0x14) + 0x32) = 0;
      }
      iVar5 = M<int>(texture + 0x24);
      M<UInt32>(iVar5 + 0x28) = M<UInt32>(texture + 0x28);
      iVar6 = M<int>(texture + 0x28);
      M<UInt8 *>(texture + 0x28) = texture;
      M<int>(iVar6 + 0x24) = iVar5;
      M<UInt8 *>(texture + 0x24) = texture;
    }
LAB_00004794:
    if (M<int>(neededBytes + 8) != 0) {
      return 1;
    }
    if (secondPass) {
      return 0;
    }
    surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
    if (surfaceListHead != (UInt8 *)0x0) {
      bVar14 = (0 < excludeCount) << 2 | (excludeCount == 0) << 1;
      surface = surfaceListHead;
      do {
        surface = M<UInt8 *>(surface + 0xa0);
        if ((excludeABytes != surface) && (surface != excludeBBytes)) {
          excludeCursor = (UInt8 **)excludeList;
          excludeLeft = excludeCount;
          if ((bool)(bVar14 >> 2 & 1)) {
            do {
              excludedTexture = *excludeCursor;
              excludeCursor = excludeCursor + 1;
              if (((excludedTexture != (UInt8 *)0x0) &&
                  (excludedTexture[0x20] == 0x0)) &&
                 (surface == M<UInt8 *>(excludedTexture + 0x50))) goto LAB_0000492c;
              excludeLeft = excludeLeft + -1;
            } while (excludeLeft != 0);
          }
          else if (!(bool)(bVar14 >> 1 & 1)) goto LAB_0000492c;
          uVar10 = 0;
          surfaceBuffer = (UInt8 *)(surface + 0xa8);
          do {
            if ((((M<int>(surface + 0xc14) == 0xffff) || ((1 < uVar10 && (1 < uVar10 - 4)))) &&
                (M<int>(surfaceBuffer + 8) != 0)) &&
               (((M<unsigned int>(surface + 0xbd0) & 0xffff0000) == 0 ||
                (surfaceBuffer != M<UInt8 *>(surface + 0xb70))))) {
              if (M<int>(surface + 0xd48) == 0) {
                ((IOATIR500Surface *)(surface))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
              }
              else {
                VCALL(M<int>(surface), 0x5cc)(surface,uVar10);
              }
              if ((bool)(excludeAIsNull >> 1 & 1)) {
                VCALL(M<int>(self), 0x56c)(self,neededBytes);
              }
              else {
                VCALL(M<int>(excludeABytes), 0x5d0)(excludeABytes,neededBytes);
              }
              if (M<int>(neededBytes + 8) != 0) {
                return 1;
              }
            }
            secondPass = uVar10 != 0x16;
            surfaceBuffer = surfaceBuffer + 0x78;
            uVar10 = uVar10 + 1;
          } while (secondPass);
          surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
        }
LAB_0000492c: ;
      } while (surface != surfaceListHead);
    }
    secondPass = true;
  } while( true );
}
