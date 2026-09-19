/*
 * IOATIR500GLContext_get_status_Port.cpp
 *
 * IOATIR500GLContext::get_status (real addr 0xb250, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xb250 */
IOReturn IOATIR500GLContext::get_status(UInt32*param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  UInt32 *puVar6;
  UInt32 local_198 [94];
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  iVar2 = M<SInt32>(self + 0x290);
  if (iVar2 != 0) {
    if ((0xff < M<UInt32>(iVar2 + 0xa4)) &&
       (iVar5 = M<SInt32>(self + 200), M<char>(iVar5 + 0x80) == '\0')) {
      do {
        GH_IOLockSleep(M<UInt32>(iVar5 + 0x840),iVar5,0);
      } while (M<char>(iVar5 + 0x80) == '\0');
      iVar2 = M<SInt32>(self + 0x290);
      if (iVar2 == 0) goto LAB_0000b3e4;
    }
    if ((M<UInt32>(iVar2 + 0xbf8) & 0x20000000) == 0) {
      uVar3 = 0;
      iVar2 = 0;
      puVar6 = local_198;
      do {
        if ((1 << (uVar3 & 0x3f) & M<UInt32>(self + 0x8c)) != 0) {
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          puVar6[3] = 0;
          iVar5 = VCALL(*M<SInt32 *>(self + 200), 0x540)
                            (M<SInt32 *>(self + 200),puVar6,
                             M<UInt32>(iVar2 + M<SInt32>(self + 0x290) + 0xb8),0x1000);
          if (iVar5 == 0) {
            iVar2 = uVar3 - 1;
            *param_1 = 0;
            if (iVar2 < 0) goto LAB_0000b3ec;
            goto LAB_0000b38c;
          }
        }
        bVar1 = uVar3 != 0x16;
        iVar2 = iVar2 + 0x78;
        puVar6 = puVar6 + 4;
        uVar3 = uVar3 + 1;
      } while (bVar1);
      iVar2 = 0x16;
      *param_1 = 1;
LAB_0000b38c:
      iVar5 = iVar2 << 4;
      iVar4 = 0;
      do {
        if ((1 << (iVar2 - iVar4 & 0x3fU) & M<UInt32>(self + 0x8c)) != 0) {
          VCALL(*M<SInt32 *>(self + 200), 0x544)
                    (M<SInt32 *>(self + 200),(SInt32)local_198 + iVar5);
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + -0x10;
      } while (iVar2 + 1 != iVar4);
      goto LAB_0000b3ec;
    }
  }
LAB_0000b3e4:
  *param_1 = 0;
LAB_0000b3ec:
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  return 0;
}
