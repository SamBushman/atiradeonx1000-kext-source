/*
 * ATIRadeonX1000PPCIntrinsics.h
 *
 * RESOLVED (issue #58 follow-up): Ghidra's PowerPC decompiler renders four
 * single instructions as function calls to its own p-code operations. They
 * were transcribed into this project as `extern "C"` function declarations,
 * which never had a definition (and, in the real kext, are not calls at all).
 * Mapping, from Ghidra's own SLEIGH definitions (ppc_instructions.sinc /
 * ppc_embedded.sinc):
 *
 *   dataCacheBlockFlush(ea)       ->  dcbf   (flush a cache block to memory)
 *   dataCacheBlockStore(ea)       ->  dcbst  (write a cache block back)
 *   enforceInOrderExecutionIO()   ->  eieio  (order device-memory accesses)
 *   instructionSynchronize()      ->  isync  (context-synchronise)
 *   sync(0)                       ->  sync   (heavyweight memory barrier; SLEIGH `sync L`, L=0)
 *
 * The C++ names are kept so existing call sites read the same as the raw
 * decompile they were transcribed from.
 */

#ifndef ATIRADEONX1000PPCINTRINSICS_H
#define ATIRADEONX1000PPCINTRINSICS_H

#include "ATIRadeonX1000Types.h"

static inline void dataCacheBlockFlush(UInt32 addr) { __asm__ __volatile__("dcbf 0,%0" : : "r"(addr) : "memory"); }
static inline void dataCacheBlockStore(UInt32 addr) { __asm__ __volatile__("dcbst 0,%0" : : "r"(addr) : "memory"); }
static inline void enforceInOrderExecutionIO(void) { __asm__ __volatile__("eieio" : : : "memory"); }
static inline void ppcSync(void) { __asm__ __volatile__("sync" : : : "memory"); }
static inline void instructionSynchronize(void) { __asm__ __volatile__("isync" : : : "memory"); }

#endif /* ATIRADEONX1000PPCINTRINSICS_H */
