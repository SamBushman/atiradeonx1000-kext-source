/*
 * ATIR500Memory_Ctor.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::ATIR500Memory()`'s real body -
 * two real, nearly-identical decompiled bodies exist (real addrs
 * `0x18c00`/`0x18ce0`), each calling a different real pair of
 * unidentified helpers before stamping the real vtable pointer. See
 * `Headers/ATIR500Memory.h`'s own header comment for why this project
 * treats these as the GCC PPC ABI's real complete-object/base-object
 * constructor pair rather than two genuinely different constructors,
 * matching the same real pattern already established for this
 * project's other OSObject-derived classes' own constructors.
 *
 * Confidence: CONFIRMED for control flow - both real decompiled bodies
 * are trivial and identical in shape. The two called real helper pairs
 * (`FUN_00018c60`/`FUN_00018c50`, `FUN_00018d40`/`FUN_00018d30`) are
 * RESOLVED, issue #27 (live kxld-resolved memory read on real G5/Tiger
 * hardware, cross-referenced against the running kernel's own symbol
 * table): `OSObject::OSObject(OSMetaClass const*)` (the real base-class
 * constructor call) followed by `OSMetaClass::instanceConstructed()
 * const` (real IOKit bookkeeping every OSObject-derived class's
 * constructor makes) - both pairs (`0x18c60`/`0x18c50` and
 * `0x18d40`/`0x18d30`) resolve to the exact same two real targets,
 * confirming they really are the same logical constructor's two ABI
 * variants, not two different real call sequences.
 */

#include "../Headers/ATIR500Memory.h"

extern "C" void FUN_00018c60(void *self, void *metaClass) asm("__ZN8OSObjectC2EPK11OSMetaClass"); /* real target: OSObject::OSObject(OSMetaClass const*) */
extern "C" void FUN_00018c50(void *metaClass) asm("__ZNK11OSMetaClass19instanceConstructedEv");    /* real target: OSMetaClass::instanceConstructed() const */
extern void *ATIR500Memory_gMetaClass; /* real global data symbol (Ghidra's own "gMetaClass" label) - own real identity unresolved, same category as every other class's own metaclass global in this project */

ATIR500Memory::ATIR500Memory() {
    FUN_00018c60(this, &ATIR500Memory_gMetaClass);
    FUN_00018c50(&ATIR500Memory_gMetaClass);
}
