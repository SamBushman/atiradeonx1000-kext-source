/*
 * ATIR500Memory_add_to_stack_Port.cpp
 *
 * ATIR500Memory::add_to_stack (real addr 0x191b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* PERF NOTE (NOT APPLIED). Estimated cycles rebuilt/stock 1.10 (2238 against 2462). Cause: loads and stores are identical to stock; the rebuilt loop runs 232
 * more register-to-register and arithmetic instructions plus 8 branches, so the loop body is shaped differently (probably extra moves of the loop pointers/counters; not traced to a line).
 * Closing it, if so: rewrite the element loop with a pointer walk instead of the decompile's index copies (keeps the names). */
/* real addr 0x191b0 */
bool ATIR500Memory::add_to_stack() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 result;
  UInt32 *chunk;
  UInt32 *linkWord;
  UInt32 *node;
  SInt32 nodesLeft;
  
  chunk = (UInt32 *)GH_IOMallocAligned(0x204,0x20);
  result = 0;
  if (chunk != (UInt32 *)0x0) {
    node = chunk + 1;
    *chunk = M<UInt32>(self + kATIR500Memory_chunkList);
    M<UInt32 *>(self + kATIR500Memory_spareNodeStack) = node;
    M<UInt32 *>(self + kATIR500Memory_chunkList) = chunk;
    chunk[2] = 0;
    chunk[3] = 0;
    chunk[4] = 0;
    if (node != chunk + 0x7d) {
      linkWord = chunk + 7;
      nodesLeft = 0x1f;
      do {
        *linkWord = 0;
        linkWord[1] = 0;
        linkWord[-1] = 0;
        *node = (UInt32)(node + 4);
        linkWord = linkWord + 4;
        nodesLeft = nodesLeft + -1;
        node = node + 4;
      } while (nodesLeft != 0);
    }
    result = 1;
    chunk[0x7d] = 0;
  }
  return result;
}
