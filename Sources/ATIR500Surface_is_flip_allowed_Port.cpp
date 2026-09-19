/*
 * ATIR500Surface_is_flip_allowed_Port.cpp
 *
 * ATIR500Surface::is_flip_allowed (real addr 0x3ae30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3ae30 */
SInt32 ATIR500Surface::is_flip_allowed() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  
  uVar2 = IOATIR500Surface::is_flip_allowed();
  iVar4 = M<SInt32>(self + 0xd50);
  if (M<char>(iVar4 + 0x9b0) == '\0') goto LAB_0003aec0;
  if (M<SInt32>(M<SInt32>(self + 0xc14) * 0x18 + iVar4 + 0xb10) == 0) {
    if (M<SInt32>(iVar4 + 0x894) == 0) goto LAB_0003aec0;
    iVar1 = 0xb18;
    if (M<SInt32>(self + 0xc14) != 0) {
      iVar1 = 0xb00;
    }
    if (M<SInt32>(iVar4 + iVar1 + 0x10) == 0) goto LAB_0003aec0;
  }
  uVar2 = 0;
LAB_0003aec0:
  uVar3 = 0;
  if (-1 < M<SInt32>(self + 0xbe8)) {
    uVar3 = uVar2;
  }
  return uVar3;
}
