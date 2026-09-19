/*
 * IOATIR500Surface_alloc_surfaces_retry_Port.cpp
 *
 * IOATIR500Surface::alloc_surfaces_retry (real addr 0x14860, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x14860 */
IOReturn IOATIR500Surface::alloc_surfaces_retry(UInt32 param_1, eLockType param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 IVar1;
  int iVar2;
  UInt32 uVar3;
  int iVar4;
  UInt8 bVar5;
  UInt8 bVar6;
  UInt8 bVar7;
  
  bVar7 = (param_3 == 0) << 1;
  bVar5 = (param_3 == 2) << 1;
  bVar6 = (param_3 == 1) << 1;
  iVar4 = 0x3e9;
  do {
    if ((bool)(bVar7 >> 1 & 1)) {
      if (M<char>(M<int>(self + 0xd50) + 0x80) == '\0') {
        return 0xe00002be;
      }
    }
    else {
      if ((bool)(bVar6 >> 1 & 1)) {
        IVar1 = self[0xbd0];
      }
      else {
        if (!(bool)(bVar5 >> 1 & 1)) goto LAB_000148e0;
        IVar1 = self[0xbd1];
      }
      if (IVar1 != 0x0) goto LAB_00014970;
    }
LAB_000148e0:
    if ((M<unsigned int>(self + 0xbf8) & 0x20000000) != 0) goto LAB_00014970;
    if ((M<unsigned int>(self + 0xbf8) & param_1) == 0) goto LAB_00014968;
    if ((!(bool)(bVar7 >> 1 & 1)) && (M<char>(M<int>(self + 0xd50) + 0x80) == '\0')) {
      return 0xe00002be;
    }
    iVar2 = alloc_surfaces_pageq((UInt32)self,param_1,false);
    if (iVar2 == 0) goto LAB_00014968;
    if (iVar2 == 2) goto LAB_00014970;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      iVar4 = alloc_surfaces_pageq((UInt32)self,M<unsigned int>(self + 0xc1c) & 3,false);
      if (iVar4 == 0) {
LAB_00014968:
        uVar3 = 0;
      }
      else {
LAB_00014970:
        uVar3 = 0xe00002cc;
      }
      return uVar3;
    }
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
    GH_thread_block(0);
    GH_IOSleep(1);
    GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  } while( true );
}
