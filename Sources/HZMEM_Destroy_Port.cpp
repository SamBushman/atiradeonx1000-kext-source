/*
 * HZMEM_Destroy_Port.cpp
 *
 * HZMEM_Destroy (real addr 0x45280, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreePageable(...) asm("_IOFreePageable");
extern "C" UInt32 GH_bzero(...) asm("_bzero");


/* real addr 0x45280 */
UInt32 HZMEM_Destroy(_HZDATA *hizData) {
    UInt8 *hizDataBytes = reinterpret_cast<UInt8 *>(hizData);

  unsigned int poolCount;
  UInt32 result;
  UInt32 *pool;
  unsigned int kind;
  UInt8 *poolSlot;
  
  result = 1;
  if (hizDataBytes != (UInt8 *)0x0) {
    poolCount = M<unsigned int>(hizDataBytes + 0xc);
    if (poolCount != 0) {
      kind = 0;
      poolSlot = hizDataBytes;
      do {
        pool = M<UInt32 *>(poolSlot + 0x10);
        if (pool != (UInt32 *)0x0) {
          if (pool[3] != 0) {
            GH_IOFreePageable(pool[3],*pool);
            pool = M<UInt32 *>(poolSlot + 0x10);
          }
          GH_IOFreePageable(pool,0x1014);
          poolCount = M<unsigned int>(hizDataBytes + 0xc);
        }
        kind = kind + 1;
        poolSlot = poolSlot + 4;
      } while (kind < poolCount);
    }
    GH_bzero(hizDataBytes,0x1c);
    result = 0;
  }
  return result;
}
