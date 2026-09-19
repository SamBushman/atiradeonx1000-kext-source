/*
 * ATIRadeonX1000_submit_empty_buffer_Port.cpp
 *
 * ATIRadeonX1000::submit_empty_buffer (real addr 0x1bca0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1bca0 */
void ATIRadeonX1000::submit_empty_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  
  if (self[0x80] == 0x0) {
    return;
  }
  uVar2 = M<UInt32>(self + 0xbbc);
  M<UInt32>(self + 0x8a0) = 0;
  iVar1 = M<SInt32>(self + 0x860);
  iVar3 = 0x2711;
  do {
    M<UInt32>(iVar1 + 0x30) = 0x10000000;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar1 + 0x34) =
         uVar2 << 0x18 | (uVar2 & 0xff00 | 0x100) << 8 | (uVar2 & 0xff0000) >> 8 | uVar2 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar1 + 0x30) = 0x10000000;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar1 + 0x34) =
         uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(iVar1 + 0x30) = 0x22000000;
    enforceInOrderExecutionIO();
    if (((M<char>(iVar1 + 0x37) == '\0' && M<char>(iVar1 + 0x36) == '\0') &&
        M<char>(iVar1 + 0x35) == '\0') && M<char>(iVar1 + 0x34) == '\0') {
      return;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
