/*
 * IOATIR500Surface_allocAllSlaveSwapBuffers_Port.cpp
 *
 * IOATIR500Surface::allocAllSlaveSwapBuffers (real addr 0x11e50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(...) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");


/* real addr 0x11e50 */
UInt32 IOATIR500Surface::allocAllSlaveSwapBuffers(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  VendorSwapBufferHeader *pVVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  SInt32 *piVar8;
  UInt32 uVar9;
  UInt8 *pIVar10;
  UInt8 *pIVar11;
  UInt8 *pIVar12;
  UInt8 *pIVar13;
  
  piVar8 = (SInt32 *)0x0;
  uVar9 = 0;
  iVar2 = param_1 * 4;
  iVar6 = 0;
  iVar5 = M<SInt32>(self + 0xd50);
  do {
    if (M<SInt32>(iVar2 + iVar5 + 0x114) == 0) {
      if (piVar8 == (SInt32 *)0x0) {
LAB_00011f54:
        iVar6 = (uVar9 - 1) * 0x1c + param_1 * 0x94;
        pIVar11 = self + iVar6 + 0xc30;
        pIVar12 = self + iVar6 + 0xc40;
        do {
          if (M<SInt32>(iVar2 + iVar5 + 0x114) != 0) {
            pIVar13 = pIVar11 + 0x14;
            pIVar10 = pIVar12 + 0xc;
            uVar9 = 0;
            do {
              if (M<SInt32 *>(pIVar13) != (SInt32 *)0x0) {
                VCALL(*M<SInt32 *>(pIVar13), 0x18)(M<SInt32 *>(pIVar13));
              }
              M<UInt16>(pIVar13 + 6) = 0;
              M<UInt16>(pIVar13 + 4) = 2;
              uVar9 = uVar9 + 1;
              M<UInt32>(pIVar13 + -8) = 0;
              M<UInt32>(pIVar13 + -4) = 0;
              M<UInt32>(pIVar13) = 0;
              M<UInt32>(pIVar10) = 0;
              M<UInt32>(pIVar10 + 4) = 0;
              M<UInt32>(pIVar10 + 8) = 0;
              pIVar13 = pIVar13 + 0x1c;
              pIVar10 = pIVar10 + 0x1c;
              iVar5 = M<SInt32>(self + 0xd50);
            } while (uVar9 < M<UInt32>(iVar2 + iVar5 + 0x114));
          }
          pIVar11 = pIVar11 + -0x1c;
          pIVar12 = pIVar12 + -0x1c;
        } while( true );
      }
    }
    else {
      iVar3 = iVar6 + param_1 * 0x94;
      uVar7 = 0;
      pIVar12 = self + iVar3 + 0xc50;
      pIVar11 = self + iVar3 + 0xc44;
      do {
        piVar8 = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(iVar5 + 0x82c) | 0x10023,param_2,GH_page_size);
        M<SInt32 *>(pIVar11) = piVar8;
        if (piVar8 == (SInt32 *)0x0) {
          if (3 < uVar9) {
            return 1;
          }
          iVar5 = M<SInt32>(self + 0xd50);
          goto LAB_00011f54;
        }
        pIVar11 = pIVar11 + 0x1c;
        uVar7 = uVar7 + 1;
        pVVar4 = (VendorSwapBufferHeader *)VCALL(*piVar8, 0x1cc)(piVar8);
        M<VendorSwapBufferHeader *>(pIVar12) = pVVar4;
        pIVar12 = pIVar12 + 0x1c;
        this->init_swap_buffer_header((VendorSwapBufferHeader *)(pVVar4),param_2);
        iVar5 = M<SInt32>(self + 0xd50);
      } while (uVar7 < M<UInt32>(iVar2 + iVar5 + 0x114));
    }
    bVar1 = uVar9 == 3;
    iVar6 = iVar6 + 0x1c;
    uVar9 = uVar9 + 1;
    if (bVar1) {
      return 1;
    }
  } while( true );
}
