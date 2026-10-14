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
#ifdef LWBRX_OFF
/* #174 bisect build switch (Tools/build_kext.sh LWBRX_OFF_FILES): the pre-#172 behaviour, four byte loads, for files named in the list. Not for production. */
static inline UInt32 loadWordByteReversed(const volatile void *addr) { const volatile UInt8 *p = static_cast<const volatile UInt8 *>(addr); UInt32 b3 = p[3], b2 = p[2], b1 = p[1], b0 = p[0]; return b3 << 24 | b2 << 16 | b1 << 8 | b0; }
#else
static inline UInt32 loadWordByteReversed(const volatile void *addr) { UInt32 v; __asm__ __volatile__("lwbrx %0,0,%1" : "=r"(v) : "r"(addr) : "memory"); return v; }
#endif
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
