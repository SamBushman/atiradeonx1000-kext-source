/*
 * IOATIR500Surface_surface_read_Port.cpp
 *
 * IOATIR500Surface::surface_read (real addr 0x14a30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");


/* real addr 0x14a30 */
IOReturn IOATIR500Surface::surface_read(IOAccelSurfaceReadData *readData, UInt32 structSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *readDataBytes = reinterpret_cast<UInt8 *>(readData);

  int iVar1;
  int iVar2;
  unsigned int uVar3;
  int *piVar4;
  int iVar5;
  UInt8 *pIVar6;
  int iVar7;
  int iVar8;
  unsigned int uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  UInt32 uVar16;
  int iVar17;
  /*
   * #164 root cause: the shipped code uses ONE real contiguous stack structure here (a
   * stand-in VendorTransferBuffer, as proven by real stock disassembly - see the issue for
   * the full derivation). Ghidra's decompile didn't recognize the struct and emitted five
   * separate-looking "local variables" (local_58[0..2], local_4c, local_48, local_46) that
   * only work because stock's own compiler happened to place them at contiguous, adjacent
   * stack offsets - something C++ never guarantees between independently-declared locals.
   * Our compiler does NOT reproduce that adjacency, so `local_58 + 1` (passed to
   * copy_from_buffer as the fake VendorTransferBuffer*) read garbage 8 bytes in - where
   * stock's real layout puts the IOMemoryDescriptor* - instead of the real descriptor,
   * crashing on the garbage vtable dispatch deep in the GART-mapping chain. Fixed by backing
   * all five with one real byte block and explicit offset accessors, guaranteeing the layout
   * stock's call chain actually depends on:
   *   +0x00 local_58[0]  (getPhysicalSegment-style output, unrelated to the fake buffer below)
   *   +0x04 "param_9" base = local_58[1]  (the VendorTransferBuffer* passed onward)
   *   +0x08 local_58[2]  (param_9+4: real-backing/GART-offset-style field)
   *   +0x0c local_4c     (param_9+8: the real IOMemoryDescriptor* - CONFIRMED via disasm)
   *   +0x10 local_48     (param_9+0xc)
   *   +0x12 local_46     (param_9+0xe: lock count, SInt16)
   */
  UInt8 xferBufBlock[0x14];

  M<UInt16>(xferBufBlock + 0x12) = 0;        /* local_46 = 0 */
  M<UInt16>(xferBufBlock + 0x10) = 3;        /* local_48 = 3 */
  M<SInt32>(xferBufBlock + 4) = 0;           /* local_58[1] = 0 */
  M<SInt32>(xferBufBlock + 8) = 0;           /* local_58[2] = 0 */
  M<SInt32>(xferBufBlock + 0xc) = 0;         /* local_4c = 0 */
  iVar14 = M<int>(readDataBytes);
  iVar13 = M<int>(readDataBytes + 4);
  iVar12 = M<int>(readDataBytes + 8);
  iVar11 = M<int>(readDataBytes + 0xc);
  iVar15 = M<int>(readDataBytes + 0x10);
  GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  iVar17 = M<int>(self + 0xb70);
  if ((M<unsigned int>(self + 0xc1c) & 3 & M<unsigned int>(self + 0xbf8)) == 0) {
LAB_00014ae0:
    if (((M<unsigned int>(self + 0xbf8) & 0x20000000) != 0) || (M<int>(iVar17 + 0x10) == 0)) {
LAB_00014af4:
      GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
      return 0xe00002cc;
    }
  }
  else {
    if (M<int>(iVar17 + 0x24) == 0) goto LAB_00014b30;
    if (M<char>(M<int>(iVar17 + 0x24) + 0x58) != '\0') goto LAB_00014ae0;
    iVar17 = this->alloc_surfaces_retry(M<unsigned int>(self + 0xc1c) & 3,(eLockType)(0));
    if (iVar17 != 0) goto LAB_00014af4;
    iVar17 = M<int>(self + 0xb70);
  }
  iVar7 = iVar14 + iVar12;
  if ((((0 < iVar7) && (iVar5 = iVar13 + iVar11, 0 < iVar5)) &&
      (iVar1 = (int)M<SInt16>(self + 0xbd4), iVar14 < iVar1)) &&
     (iVar8 = (int)M<SInt16>(self + 0xbd6), iVar13 < iVar8)) {
    iVar10 = M<int>(readDataBytes + 0x14);
    iVar2 = 0;
    if (iVar14 < 0) {
      iVar2 = (unsigned int)M<UInt16>(iVar17 + 0x16) * iVar14;
      iVar14 = 0;
      iVar2 = -iVar2;
      iVar12 = iVar7;
    }
    if (iVar13 < 0) {
      iVar11 = iVar10 * iVar13;
      iVar13 = 0;
      iVar2 = iVar2 - iVar11;
      iVar11 = iVar5;
    }
    if (iVar1 < iVar7) {
      iVar12 = iVar1 - iVar14;
    }
    if (iVar8 < iVar5) {
      iVar11 = iVar8 - iVar13;
    }
    uVar3 = iVar15 + iVar2;
    uVar9 = uVar3 & GH_page_size - 1U;
    M<SInt32>(xferBufBlock + 0xc) = (SInt32)GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(uVar3 & -GH_page_size,
                                   -GH_page_size &
                                   (GH_page_size +
                                   iVar10 * (iVar11 + -1) +
                                   (unsigned int)M<UInt16>(iVar17 + 0x16) * iVar12 + uVar9) - 1,0,
                                   M<UInt32>(self + 0x78));
    if (M<SInt32>(xferBufBlock + 0xc) == 0) {
      uVar16 = 0xe00002be;
    }
    else {
      if (((self[0xbf7] != 0) && (M<int>(iVar17 + 0x24) != 0)) &&
         ((piVar4 = M<int *>(M<int>(iVar17 + 0x24) + 8), piVar4 != (int *)0x0 &&
          ((iVar15 = VCALL(*piVar4, 0xdc)(piVar4,2,xferBufBlock), iVar15 == 0 &&
           (M<SInt32>(xferBufBlock) == 4)))))) {
        iVar15 = M<int>(iVar17 + 0x24);
        if (M<int>(iVar15 + 4) != 0) {
          GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
          piVar4 = M<int *>(self + 0xd50);
          iVar7 = piVar4[0x1ed];
          iVar15 = VCALL(*piVar4, 0x55c)(piVar4,M<UInt32>(self + 0x7c));
          piVar4[0x1ed] = iVar7 + iVar15;
          GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
          VCALL(*M<int *>(self + 0xd50), 0x5ac)
                    (M<int *>(self + 0xd50),M<UInt32>(iVar17 + 0x24));
          M<UInt32>(M<int>(iVar17 + 0x24) + 4) = 0;
          iVar15 = M<int>(iVar17 + 0x24);
        }
        M<int>(iVar15 + 0x54) = M<int>(self + 0x7c) + -1;
      }
      iVar15 = M<int>(self + 0x7c);
      VCALL(M<int>(self), 0x5e8)
                (self,iVar14,iVar13,iVar12,iVar11,0,0,iVar17,iVar15,xferBufBlock + 4,uVar9,iVar10,0);
      pIVar6 = self + 0xcc;
      iVar11 = 0x17;
      do {
        iVar12 = M<int>(pIVar6);
        pIVar6 = pIVar6 + 0x78;
        if ((iVar12 != 0) && (iVar15 == M<int>(iVar12 + 0x54))) {
          M<UInt32>(iVar12 + 0x54) = M<UInt32>(self + 0x7c);
        }
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      if (M<SInt32>(xferBufBlock + 8) != 0) {
        GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
        piVar4 = M<int *>(self + 0xd50);
        iVar12 = piVar4[0x1ed];
        iVar11 = VCALL(*piVar4, 0x55c)(piVar4,M<UInt32>(self + 0x7c));
        piVar4[0x1ed] = iVar12 + iVar11;
        GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
        VCALL(*M<int *>(self + 0xd50), 0x5ac)(M<int *>(self + 0xd50),xferBufBlock + 4);
      }
      uVar16 = 0;
      {
        SInt32 *desc = (SInt32 *)M<SInt32>(xferBufBlock + 0xc);
        VCALL(*desc, 0x18)(desc);
      }
    }
    M<SInt32>(xferBufBlock + 0xc) = 0;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
    return uVar16;
  }
LAB_00014b30:
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  return 0;
}
