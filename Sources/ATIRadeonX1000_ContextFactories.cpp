/*
 * ATIRadeonX1000_ContextFactories.cpp
 *
 * RESOLVED (issue #21): the real bodies of `ATIRadeonX1000`'s four
 * context-factory vtable overrides. Names/addresses/roles already
 * resolved (issue #6); this pass decompiled the actual function bodies.
 *
 * All four are structurally identical and trivially simple: allocate a
 * fixed real byte size via a real lazy-binding stub - RESOLVED, issue #15
 * (live kxld-resolved memory read on real G5/Tiger hardware): the real
 * target is `OSObject::operator new(unsigned long)`
 * (`__ZN8OSObjectnwEm`), refining the prior "almost certainly
 * `operator new`" guess to the exact real symbol.
 * `FUN_0001a194`/`FUN_0001a274`/`FUN_0001a2e4`/`FUN_0001a204` are each
 * their own per-call-site stub instance, all resolving to the same real
 * target - and if the allocation succeeded, placement-construct the
 * real concrete class and return it - otherwise return null.
 *
 * Real per-class allocation sizes (a new real finding this pass, not
 * previously known anywhere in this project): `ATIR500Surface` `0xdbc`
 * (3516) bytes, `ATIR5002DContext` `300` (`0x12c`) bytes,
 * `ATIR500DVDContext` `0x1e0` (480) bytes, `ATIR500GLContext` `0x690`
 * (1680) bytes. Written below as plain `new ClassName()` expressions,
 * matching this project's own existing precedent for the identical
 * allocate-then-construct pattern (`IOATIR500GLContext::start`'s real
 * `IOATIR500Shared` allocation, `Sources/IOATIR500GLContext_Start.cpp`) -
 * `sizeof()` on this project's own (necessarily incomplete) class models
 * will not equal these real observed byte counts, the same known,
 * already-accepted gap that precedent carries; the real sizes are
 * recorded here as a documented fact, not modeled via padding fields.
 *
 * Real covariant return types: this project's own earlier placeholder
 * return type for these four (`IOUserClient*`, still correct for the
 * base class's own declaration, `IOATIR500Accelerator.h`) turns out to
 * be the generic interface type only - the real compiled return type on
 * THIS class is the concrete subclass pointer, confirmed directly from
 * each real decompile's own signature.
 *
 * The construct step (`ATIR500Surface::ATIR500Surface(this)` etc.) calls
 * each real class's already-known default constructor - not
 * re-transcribed here, already covered by this project's existing
 * construction/initialization work (issue #10).
 *
 * Confidence: CONFIRMED for every literal constant and the complete
 * control flow - four real, standalone, structurally-identical
 * functions, no brace-nesting-unreliability risk. No C++ compiler was
 * available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project) - checked by
 * careful, repeated manual re-reading against each raw decompile
 * instead.
 */

#include "../Headers/ATIRadeonX1000.h"


/* gcc 4.0.1 emits no null test after an unconditional `new T()` here, the shipped code tests the allocation (difftest: with a failed allocation the
 * rebuilt code ran the constructor on a null pointer). So the allocation is made by hand and tested; the object is built in the block by placement new. */
inline void *operator new(size_t, void *where) { return where; }

ATIR500Surface *ATIRadeonX1000::new_surface(void) {
    void *mem = OSObject::operator new(0xdbc);   /* real allocation size 0xdbc bytes - see this file's own header comment */
    return mem ? ::new (mem) ATIR500Surface() : 0;
}



ATIR5002DContext *ATIRadeonX1000::new_2d_context(void) {
    void *mem = OSObject::operator new(300);     /* real allocation size 300 (0x12c) bytes */
    return mem ? ::new (mem) ATIR5002DContext() : 0;
}



ATIR500DVDContext *ATIRadeonX1000::new_dvd_context(void) {
    void *mem = OSObject::operator new(0x1e0);   /* real allocation size 0x1e0 bytes */
    return mem ? ::new (mem) ATIR500DVDContext() : 0;
}



ATIR500GLContext *ATIRadeonX1000::new_gl_context(void) {
    void *mem = OSObject::operator new(0x690);   /* real allocation size 0x690 bytes */
    return mem ? ::new (mem) ATIR500GLContext() : 0;
}
