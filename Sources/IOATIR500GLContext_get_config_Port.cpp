/*
 * IOATIR500GLContext_get_config_Port.cpp
 *
 * IOATIR500GLContext::get_config (real addr 0xb010, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xb010 */
IOReturn IOATIR500GLContext::get_config(UInt32*param_1, UInt32*param_2, UInt32*param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 *puVar7;
  UInt32 local_1a8 [97];
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  if ((M<SInt32>(self + 0x290) != 0) && (0xff < M<UInt32>(M<SInt32>(self + 0x290) + 0xa4))) {
    iVar6 = M<SInt32>(self + 200);
    if (M<char>(iVar6 + 0x80) != '\0') goto LAB_0000b08c;
    do {
      GH_IOLockSleep(M<UInt32>(iVar6 + 0x840),iVar6,0);
    } while (M<char>(iVar6 + 0x80) == '\0');
  }
  iVar6 = M<SInt32>(self + 200);
LAB_0000b08c:
  *param_1 = M<UInt32>(iVar6 + 0x98);
  *param_3 = M<UInt32>(M<SInt32>(self + 200) + 0x9c);
  if (M<SInt32>(self + 0x290) == 0) {
    uVar3 = VCALL(*M<SInt32 *>(self + 200), 0x548)(M<SInt32 *>(self + 200));
  }
  else {
    uVar4 = 0;
    iVar6 = 0;
    puVar7 = local_1a8;
    do {
      if ((1 << (uVar4 & 0x3f) & M<UInt32>(self + 0x8c)) != 0) {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        iVar2 = VCALL(*M<SInt32 *>(self + 200), 0x540)
                          (M<SInt32 *>(self + 200),puVar7,
                           M<UInt32>(iVar6 + M<SInt32>(self + 0x290) + 0xb8),0x1000);
        if (iVar2 == 0) {
          iVar6 = uVar4 - 1;
          uVar3 = 0;
          if (iVar6 < 0) goto LAB_0000b1f0;
          goto LAB_0000b174;
        }
      }
      bVar1 = uVar4 != 0x16;
      iVar6 = iVar6 + 0x78;
      puVar7 = puVar7 + 4;
      uVar4 = uVar4 + 1;
    } while (bVar1);
    iVar6 = 0x16;
    uVar3 = VCALL(*M<SInt32 *>(self + 200), 0x548)(M<SInt32 *>(self + 200));
LAB_0000b174:
    iVar2 = iVar6 << 4;
    iVar5 = 0;
    do {
      if ((1 << (iVar6 - iVar5 & 0x3fU) & M<UInt32>(self + 0x8c)) != 0) {
        VCALL(*M<SInt32 *>(self + 200), 0x544)(M<SInt32 *>(self + 200),(SInt32)local_1a8 + iVar2);
      }
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + -0x10;
    } while (iVar5 != iVar6 + 1);
  }
LAB_0000b1f0:
  *param_2 = uVar3;
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  return 0;
}
