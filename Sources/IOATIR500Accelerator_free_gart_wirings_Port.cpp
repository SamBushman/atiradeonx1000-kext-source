/*
 * IOATIR500Accelerator_free_gart_wirings_Port.cpp
 *
 * IOATIR500Accelerator::free_gart_wirings (real addr 0x4a90, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");
extern "C" UInt32 GH_IOPanic(...) asm("_IOPanic");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x4a90 */
void IOATIR500Accelerator::free_gart_wirings() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 IVar1;
  bool bVar2;
  int iVar3;
  UInt32 uVar4;
  UInt8 *pIVar5;
  UInt8 *pIVar6;
  unsigned int local_38;
  int local_34;
  
  GH_IOGetTime(&local_38);
  local_34 = local_34 - M<int>(self + 0x94);
  if (local_34 < 0) {
    local_34 = local_34 + 1000000000;
    local_38 = local_38 - 1;
  }
  pIVar6 = M<UInt8 *>(self + 0x6d4);
  pIVar5 = self + 0x69c;
  local_38 = local_38 - M<int>(self + 0x90);
  if (pIVar6 != pIVar5) {
    bVar2 = false;
    do {
      if (M<UInt8 *>(pIVar6 + 0x34) != pIVar5) {
        GH_IOPanic("transfer buffer poorly linked\n");
      }
      if (M<int>(pIVar6 + 4) == 0) {
        GH_IOPanic("transfer on list but not in GART");
      }
      if (M<UInt16>(pIVar6 + 0xc) == 4) {
        IVar1 = pIVar6[0x20];
        if ((IVar1 == 0x3) || (IVar1 == 0x7)) {
          uVar4 = M<UInt32>(M<int>(pIVar6 + 0x14) + 0xc);
        }
        else {
          if (((IVar1 != 0x4) && (IVar1 != 0x2)) &&
             (IVar1 != 0x5)) {
            return;
          }
          uVar4 = M<UInt32>(M<int>(pIVar6 + 0x14) + 8);
        }
        iVar3 = VCALL(M<int>(self), 0x554)(self,uVar4);
        if (iVar3 == 0) {
          self[0x89] = 0x1;
          return;
        }
        if (M<SInt16>(pIVar6 + 0xe) != 0) {
          return;
        }
        if ((local_38 < M<unsigned int>(pIVar6 + 0x2c)) ||
           ((local_38 <= M<unsigned int>(pIVar6 + 0x2c) && (0 < M<int>(pIVar6 + 0x30) - local_34)))) {
          self[0x89] = 0x1;
          return;
        }
        if (pIVar6[0x20] == 0x4) {
          M<UInt8>(M<int>(pIVar6 + 0x14) + 0x14) = 1;
        }
        if (bVar2) {
          GH_thread_block(0);
        }
        bVar2 = true;
        if (M<int>(pIVar6 + 4) != 0) {
          VCALL(M<int>(self), 0x5ac)(self,pIVar6);
        }
      }
      else if (M<UInt16>(pIVar6 + 0xc) < 5) {
        GH_IOPanic("non texture transfer buffer found in gart garbage collection list\n");
      }
      else {
        GH_IOPanic("vendor private transfer buffer found in gart garbage collection list\n");
      }
      pIVar6 = M<UInt8 *>(self + 0x6d4);
    } while (pIVar6 != pIVar5);
  }
  return;
}
