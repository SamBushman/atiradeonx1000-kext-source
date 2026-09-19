/*
 * ATIR500DVDContext_SetMacrovision.cpp
 *
 * RESOLVED: `ATIR500DVDContext::set_macrovision`'s real body, real addr
 * 0x35010 - the DVD-context-local counterpart to `IOATIR5002DContext::
 * set_macrovision` (already fully resolved). Confirms this project's own
 * prior inference that it's "the DVD-context-local equivalent" - now
 * independently verified rather than assumed.
 *
 * Real body: locks `accelerator->commandLock` (RESOLVED via live memory
 * read, real targets `mutex_lock`/`mutex_unlock_rwcmb`). If the
 * accelerator's own real "display active" flag (`+0x80`, the SAME real
 * byte `IOATIR500Surface_LockShape.cpp`'s own `+0x80`-spin-wait already
 * establishes) is clear, returns a real `kIOReturnNotOpen`-family error
 * (`0xe00002d8`) immediately. Otherwise: resolves this context's own
 * bound surface's real framebuffer index via
 * `ATIR500Surface::getFramebufferIndex` (a real, previously-unknown
 * name this pass found - own body not decompiled), uses it to index a
 * real per-framebuffer accelerator table (`accelerator+index*0x20+0xd4`)
 * to get a real value, then calls a real external kernel/IOKit routine -
 * RESOLVED via live kxld-resolved memory read:
 * `OSMetaClassBase::safeMetaCast(OSMetaClassBase const*, OSMetaClass
 * const*)`. HONEST FLAG: the real call's second argument is `_ASICSupportsAGP`
 * (the same global this project already knows gets reused for
 * unrelated purposes elsewhere - a real task ID, a shift count) - using
 * it here as an `OSMetaClass*` argument to `safeMetaCast` is a plausible
 * but NOT independently confirmed reading; this could equally be a real,
 * different global at the same Ghidra-assigned placeholder name (this
 * project has already seen Ghidra collide unrelated globals under one
 * label - see the "WARNING: Globals starting with '_' overlap smaller
 * symbols" notes elsewhere). If the cast result is null, returns a real
 * `kIOReturnNoDevice`-family error (`0xe00002c0`); otherwise calls the
 * resulting object's own real vtable `+0x70c` method with
 * `(param2, &stack_scratch)` and returns its result.
 *
 * Confidence: CONFIRMED for control flow and every real offset except
 * the `safeMetaCast` argument identity flagged above. No C++ compiler
 * was available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project).
 */

#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIR500Surface.h"

extern "C" void DVD_mutex_lock(void *) asm("_IOLockLock");
extern "C" void DVD_mutex_unlock(void *) asm("_IOLockUnlock");
extern "C" void *FUN_safeMetaCast(void *obj, void *metaClass) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
/* CORRECTED (issue #58 follow-up): the Ghidra label "_ASICSupportsAGP" here hid a relocation whose
 * real target (from the Mach-O relocation table; site 0x35060 is `lis/lwz`, a VALUE load) is
 * `IONDRVFramebuffer::metaClass` - i.e. this is `OSDynamicCast(IONDRVFramebuffer, tableEntry)`.
 * The old transcription passed the ADDRESS of a page-size variable. */
extern "C" void *IONDRVFramebuffer_metaClass asm("__ZN17IONDRVFramebuffer9metaClassE");

/* CORRECTED (ledger pass, checked against the disassembly): the shipped signature is (unsigned long, unsigned long),
 * and the vtable +0x70c call is (display, attribute, &value) - the second scalar's ADDRESS is passed. The earlier
 * transcription passed a scratch local and described the second scalar as "silently unused". The 2D context's
 * set_macrovision (IOATIR5002DContext_Surface.cpp) has the same shape with the attribute fixed at 0x92. */
IOReturn ATIR500DVDContext::set_macrovision(UInt32 attribute, UInt32 value) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    DVD_mutex_lock(*reinterpret_cast<void **>(accel + 0x840));

    IOReturn result;
    if (*reinterpret_cast<SInt8 *>(accel + 0x80) == 0) {
        result = 0xe00002d8;
    } else {
        UInt32 fbIndex = boundSurface->getFramebufferIndex();
        void *tableEntry = *reinterpret_cast<void **>(accel + fbIndex * 0x20 + 0xd4);
        void *casted = FUN_safeMetaCast(tableEntry, IONDRVFramebuffer_metaClass);
        *reinterpret_cast<void **>(self + 0x160) = casted;
        if (casted == nullptr) {
            result = 0xe00002c0;
        } else {
            typedef IOReturn (*Fn0x70c)(void *, UInt32, UInt32 *);
            result = (*reinterpret_cast<Fn0x70c *>(*reinterpret_cast<void ***>(casted) + (0x70c / 4)))(
                casted, attribute, &value);
        }
    }

    DVD_mutex_unlock(*reinterpret_cast<void **>(accel + 0x840));
    return result;
}
