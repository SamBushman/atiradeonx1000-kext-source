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
 * left opaque - own real identity unresolved, matching this project's
 * standing "OSMetaClassBase association" category for every other
 * class's own constructor helpers.
 */

#include "../Headers/ATIR500Memory.h"

extern "C" void FUN_00018c60(void *self, void *metaClass); /* real external-looking helper */
extern "C" void FUN_00018c50(void *metaClass);              /* real external-looking helper */
extern void *ATIR500Memory_gMetaClass; /* real global data symbol (Ghidra's own "gMetaClass" label) - own real identity unresolved, same category as every other class's own metaclass global in this project */

ATIR500Memory::ATIR500Memory() {
    FUN_00018c60(this, &ATIR500Memory_gMetaClass);
    FUN_00018c50(&ATIR500Memory_gMetaClass);
}
