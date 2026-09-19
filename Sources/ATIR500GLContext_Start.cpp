/*
 * ATIR500GLContext_Start.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `ATIR500GLContext::start` - real addr 0x28540, the 3D subclass's own
 * `start()` override (a DISTINCT real function from the already-
 * transcribed `IOATIR500GLContext::start`, `Sources/
 * IOATIR500GLContext_Start.cpp` - see that file's own header comment
 * for the disambiguation).
 *
 * Real body: locks the accelerator's commandLock, calls the base
 * class's own `IOATIR500GLContext::start(provider)` (a real explicit-
 * base-qualified call in the source, compiled as an indirect call
 * through a lazy pointer in the raw decompile), and on success zeroes
 * a real block of subclass-only state (`+0x3bc`/`+0x34c..+0x358`),
 * initializes a real 6-entry, 0x78-byte-stride per-unit array
 * (`+0x3c0..+0x400`, real per-field defaults including a real masked
 * tiling-config reset at each slot's own `+0xc` sub-field) - the SAME
 * real "alt unit" array `write_r500_3d_blit_state_packet` already
 * reads via `this+0x3c0`/`this+0x3b2` (this function is the real
 * initializer for that array), a real 4-entry `altUnitSelector`
 * mirror array, sets two real fields on the buffer object the base
 * class's own `start()` already allocated at `this+0xe0`, and finally
 * points this class's own `+0x360` extended-external-method-table
 * field at the already-fully-extracted `kGLSpecialMethod20` (real
 * content CONFIRMED via raw memory dump, not a gap - see
 * `IOATIR500GLContext_ExternalMethods.cpp`).
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile. Most individual
 * zeroed/defaulted fields' semantic roles beyond "reset at subclass
 * start" are UNKNOWN, matching this project's own established
 * convention for the base class's own analogous zero-init block.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

extern "C" void Start3D_mutex_lock(void *lockPtr) asm("_IOLockLock");
extern "C" void Start3D_mutex_unlock(void *lockPtr) asm("_IOLockUnlock");
extern const VendorExternalMethod kGLSpecialMethod20;

/* (re-ported mechanically: see ATIR500GLContext_start_Port.cpp) */

