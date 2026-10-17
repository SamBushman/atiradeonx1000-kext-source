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

  UInt8 bufferType;
  bool blockedOnce;
  int iVar3;
  UInt32 stamp;
  UInt8 *listHead;
  UInt8 *transfer;
  unsigned int cutoffSeconds;
  int cutoffNanos;
  
  GH_IOGetTime(&cutoffSeconds);
  cutoffNanos = cutoffNanos - M<int>(self + 0x94);
  if (cutoffNanos < 0) {
    cutoffNanos = cutoffNanos + 1000000000;
    cutoffSeconds = cutoffSeconds - 1;
  }
  transfer = M<UInt8 *>(self + 0x6d4);
  listHead = self + 0x69c;
  cutoffSeconds = cutoffSeconds - M<int>(self + 0x90);
  if (transfer != listHead) {
    blockedOnce = false;
    do {
      if (M<UInt8 *>(transfer + 0x34) != listHead) {
        GH_IOPanic("transfer buffer poorly linked\n");
      }
      if (M<int>(transfer + 4) == 0) {
        GH_IOPanic("transfer on list but not in GART");
      }
      if (M<UInt16>(transfer + 0xc) == 4) {
        bufferType = transfer[0x20];
        if ((bufferType == 0x3) || (bufferType == 0x7)) {
          stamp = M<UInt32>(M<int>(transfer + 0x14) + 0xc);
        }
        else {
          if (((bufferType != 0x4) && (bufferType != 0x2)) &&
             (bufferType != 0x5)) {
            return;
          }
          stamp = M<UInt32>(M<int>(transfer + 0x14) + 8);
        }
        iVar3 = VCALL(M<int>(self), 0x554)(self,stamp);
        if (iVar3 == 0) {
          self[0x89] = 0x1;
          return;
        }
        if (M<SInt16>(transfer + 0xe) != 0) {
          return;
        }
        if ((cutoffSeconds < M<unsigned int>(transfer + 0x2c)) ||
           ((cutoffSeconds <= M<unsigned int>(transfer + 0x2c) && (0 < M<int>(transfer + 0x30) - cutoffNanos)))) {
          self[0x89] = 0x1;
          return;
        }
        if (transfer[0x20] == 0x4) {
          M<UInt8>(M<int>(transfer + 0x14) + 0x14) = 1;
        }
        if (blockedOnce) {
          GH_thread_block(0);
        }
        blockedOnce = true;
        if (M<int>(transfer + 4) != 0) {
          VCALL(M<int>(self), 0x5ac)(self,transfer);
        }
      }
      else if (M<UInt16>(transfer + 0xc) < 5) {
        GH_IOPanic("non texture transfer buffer found in gart garbage collection list\n");
      }
      else {
        GH_IOPanic("vendor private transfer buffer found in gart garbage collection list\n");
      }
      transfer = M<UInt8 *>(self + 0x6d4);
    } while (transfer != listHead);
  }
  return;
}
