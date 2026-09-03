/*
 * ATIRadeonX1000_ContextFactories.cpp
 *
 * RESOLVED (issue #21): the real bodies of `ATIRadeonX1000`'s four
 * context-factory vtable overrides. Names/addresses/roles already
 * resolved (issue #6); this pass decompiled the actual function bodies.
 *
 * All four are structurally identical and trivially simple: allocate a
 * fixed real byte size via a real lazy-binding stub (almost certainly
 * `operator new(unsigned long)` - CONFIRMED via direct disassembly to
 * have the same 4-instruction trampoline shape already documented for
 * the 24 real stubs in issue #15's catalog, `ATIRadeonX1000Registers.h`;
 * `FUN_0001a194`/`FUN_0001a274`/`FUN_0001a2e4`/`FUN_0001a204`, a separate
 * per-call-site stub instance each - does not change issue #15's own
 * open status), and if the allocation succeeded, placement-construct the
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

ATIR500Surface *ATIRadeonX1000::new_surface(void) {
    return new ATIR500Surface(); /* real allocation size 0xdbc bytes - see this file's own header comment */
}

ATIR5002DContext *ATIRadeonX1000::new_2d_context(void) {
    return new ATIR5002DContext(); /* real allocation size 300 (0x12c) bytes - see this file's own header comment */
}

ATIR500DVDContext *ATIRadeonX1000::new_dvd_context(void) {
    return new ATIR500DVDContext(); /* real allocation size 0x1e0 bytes - see this file's own header comment */
}

ATIR500GLContext *ATIRadeonX1000::new_gl_context(void) {
    return new ATIR500GLContext(); /* real allocation size 0x690 bytes - see this file's own header comment */
}
