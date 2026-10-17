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
UInt32 IOATIR500Surface::allocAllSlaveSwapBuffers(UInt32 panel, UInt32 swapBufferSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    PanelRecord *rec = PANEL_RECORD(self, panel);

  bool bVar1;
  SInt32 iVar2;
  VendorSwapBufferHeader *pVVar4;
  SInt32 iVar5;
  UInt32 uVar7;
  SInt32 *piVar8;
  UInt32 uVar9;
  SwapBufferEntry *slot;
  SwapBufferEntry *victim;
  
  /* The four submit slots are entries[1..4]; slot number uVar9 (0..3) allocates one descriptor per buffer of the panel, into entries[uVar9 + 1 + uVar7]
     (with more than one buffer per panel that runs past the record into the next one - stock behaviour, kept). */
  piVar8 = (SInt32 *)0x0;
  uVar9 = 0;
  iVar2 = panel * 4;
  iVar5 = M<SInt32>(self + 0xd50);
  do {
    if (M<SInt32>(iVar2 + iVar5 + 0x114) == 0) {
      if (piVar8 == (SInt32 *)0x0) {
LAB_00011f54:
        /* Failure unwind: release the slots allocated so far, walking backwards from entries[uVar9]. The shipped code has no exit condition here
           (issue #32: it keeps walking down through memory until it faults); the loop is kept exactly that way. */
        victim = &rec->entries[uVar9];
        do {
          if (M<SInt32>(iVar2 + iVar5 + 0x114) != 0) {
            SwapBufferEntry *v = victim;
            uVar9 = 0;
            do {
              if (v->memory != (void *)0x0) {
                VCALL(*(SInt32 *)v->memory, 0x18)((SInt32 *)v->memory);
              }
              v->unknown_0x0e = 0;
              v->unknown_0x0c = 2;
              uVar9 = uVar9 + 1;
              v->unknown_0x00 = 0;
              v->gartOffset = 0;
              v->memory = (void *)0x0;
              v->stamp = 0;
              v->header = (VendorSwapBufferHeader *)0x0;
              v->rectWordIndex = 0;
              v = v + 1;
              iVar5 = M<SInt32>(self + 0xd50);
            } while (uVar9 < M<UInt32>(iVar2 + iVar5 + 0x114));
          }
          victim = victim - 1;
        } while( true );
      }
    }
    else {
      uVar7 = 0;
      slot = &rec->entries[uVar9 + 1];
      do {
        piVar8 = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(iVar5 + 0x82c) | 0x10023,swapBufferSize,GH_page_size);
        slot->memory = piVar8;
        if (piVar8 == (SInt32 *)0x0) {
          if (3 < uVar9) {
            return 1;
          }
          iVar5 = M<SInt32>(self + 0xd50);
          goto LAB_00011f54;
        }
        uVar7 = uVar7 + 1;
        pVVar4 = (VendorSwapBufferHeader *)VCALL(*piVar8, 0x1cc)(piVar8);
        slot->header = pVVar4;
        slot = slot + 1;
        this->init_swap_buffer_header((VendorSwapBufferHeader *)(pVVar4),swapBufferSize);
        iVar5 = M<SInt32>(self + 0xd50);
      } while (uVar7 < M<UInt32>(iVar2 + iVar5 + 0x114));
    }
    bVar1 = uVar9 == 3;
    uVar9 = uVar9 + 1;
    if (bVar1) {
      return 1;
    }
  } while( true );
}

