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
static inline void dataCacheBlockTouch(UInt32 addr) { __asm__ __volatile__("dcbt 0,%0" : : "r"(addr) : "memory"); }
static inline void dataCacheBlockTouch(const void *addr) { dataCacheBlockTouch(reinterpret_cast<UInt32>(addr)); }
static inline void dataCacheBlockStore(UInt32 addr) { __asm__ __volatile__("dcbst 0,%0" : : "r"(addr) : "memory"); }
/* lwbrx: ONE byte-reversed 32-bit load (the shipped code reads little-endian hardware registers this way). Ghidra expands it to
 * four byte loads at A+3,A+2,A+1,A shifted together, which on MMIO is four bus transactions instead of one (#172). */
static inline UInt32 loadWordByteReversed(const volatile void *addr) { UInt32 v; __asm__ __volatile__("lwbrx %0,0,%1" : "=r"(v) : "r"(addr) : "memory"); return v; }
/* stwbrx / lhbrx / sthbrx: the byte-reversed store and the byte-reversed halfword load/store (little-endian hardware registers). One bus transaction each;
 * the Ghidra expansion into per-byte accesses is not equivalent for MMIO (Tools/difftest finds it as a different register access pattern). */
static inline void storeWordByteReversed(volatile void *addr, UInt32 v) { __asm__ __volatile__("stwbrx %0,0,%1" : : "r"(v), "r"(addr) : "memory"); }
static inline UInt32 loadHalfByteReversed(const volatile void *addr) { UInt32 v; __asm__ __volatile__("lhbrx %0,0,%1" : "=r"(v) : "r"(addr) : "memory"); return v; }
static inline void storeHalfByteReversed(volatile void *addr, UInt32 v) { __asm__ __volatile__("sthbrx %0,0,%1" : : "r"(v), "r"(addr) : "memory"); }
static inline void enforceInOrderExecutionIO(void) { __asm__ __volatile__("eieio" : : : "memory"); }
static inline void ppcSync(void) { __asm__ __volatile__("sync" : : : "memory"); }
static inline void instructionSynchronize(void) { __asm__ __volatile__("isync" : : : "memory"); }

/* lwarx / stwcx. read-modify-write loop: Ghidra shows it as
 *     do { old = *p; if (in_RESERVE) { new = storeWordConditionalIndexed(old + K, 0, p); *p = new; in_cr0 = 2; } } while (!cr0.eq);
 * Returns the value read by lwarx (the value before the add). */
static inline SInt32 atomicAddReturningOld(SInt32 *p, SInt32 delta) {
    SInt32 old, updated;
    __asm__ __volatile__("1: lwarx %0,0,%3\n\tadd %1,%0,%2\n\tstwcx. %1,0,%3\n\tbne- 1b"
                         : "=&r"(old), "=&r"(updated) : "r"(delta), "r"(p) : "cr0", "memory");
    return old;
}

#endif /* ATIRADEONX1000PPCINTRINSICS_H */
