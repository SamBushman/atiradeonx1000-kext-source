/*
 * ATIR500Memory_Lifecycle.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::init()`/`free()`'s real bodies,
 * real addrs `0x18d50`/`0x19120`.
 *
 * Both gate on this class's own real vtable slot `+0x48` (`init`) - a
 * genuine virtual call through `this`'s own vtable. `free()` additionally
 * calls this object's own real vtable slot `+0x4c` as its final action.
 *
 * Both slots RESOLVED, issue #52 (live kxld-resolved `/dev/kmem` read on
 * real G5/Tiger hardware, cross-referenced against the running kernel's
 * own symbol table - this class has no known subclass in this project to
 * fall back on for the usual static subclass-vtable technique, so this
 * genuinely needed live hardware): `+0x48` = `OSObject::
 * _RESERVEDOSObject0()`, `+0x4c` = `OSObject::_RESERVEDOSObject1()` -
 * both genuine standard IOKit reserved-for-future-binary-compatibility
 * slots, real signature `virtual void _RESERVEDOSObjectN()` (no real
 * return value), inherited unmodified since `ATIR500Memory` never
 * overrides either. NOT a real custom init/free virtual pair as this
 * project's own prior (pre-#52) account had speculated - both are
 * genuine no-ops. `init()`'s own `bool ok = ...` read of the `+0x48`
 * call's result is almost certainly a decompiler/ABI artifact (the
 * "implicit self-return, r3 still holds `this`" pattern already
 * documented elsewhere in this project) rather than a real signal, since
 * a real no-op never touches r3.
 *
 * Then walk and free the real `chunkList` (see `Headers/ATIR500Memory.h`)
 * via a real per-chunk kernel-free wrapper - RESOLVED, issue #27: real
 * target `IOFreeAligned`, same real category issue #15 established for
 * the alloc/free pair elsewhere; `init` and `free` each call their own
 * distinct per-call-site stub instance (`FUN_00018de8`/`FUN_00019198`)
 * resolving to the same real target.
 *
 * `init()`'s real behavior (tearing down `chunkList` rather than
 * building it) is a genuine oddity - see `Headers/ATIR500Memory.h`'s
 * own header comment for this project's best real account. No real
 * caller of `init()` exists anywhere else in this project's own
 * reconstruction; only `init_pool`'s two overloads
 * (`ATIR500Memory_Pool.cpp`) are ever actually called.
 *
 * Confidence: CONFIRMED for control flow and every field offset - both
 * real, complete, standalone decompiles.
 */

#include "../Headers/ATIR500Memory.h"

extern "C" void FUN_00018de8(void *chunk, UInt32 size) asm("_IOFreeAligned"); /* init()'s own stub instance */
extern "C" void FUN_00019198(void *chunk, UInt32 size) asm("_IOFreeAligned"); /* free()'s own stub instance (distinct real address, same real target) */

bool ATIR500Memory::init() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    /* +0x48 = OSObject::_RESERVEDOSObject0(), RESOLVED issue #52 - a real
       no-op; `ok` is effectively always true (implicit self-return artifact). */
    typedef bool (*Fn0x48)(void *);
    void **vtable = *reinterpret_cast<void ***>(self);
    bool ok = reinterpret_cast<Fn0x48>(vtable[0x48 / 4])(this);
    if (!ok) {
        return false;
    }

    UInt32 *chunk = *reinterpret_cast<UInt32 **>(self + 0x10);
    while (chunk != 0) {
        UInt32 *nextChunk = reinterpret_cast<UInt32 *>(chunk[0]);
        FUN_00018de8(chunk, 0x204);
        *reinterpret_cast<UInt32 **>(self + 0x10) = nextChunk;
        chunk = nextChunk;
    }
    return true;
}

void ATIR500Memory::free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    UInt32 *chunk = *reinterpret_cast<UInt32 **>(self + 0x10);
    while (chunk != 0) {
        UInt32 *nextChunk = reinterpret_cast<UInt32 *>(chunk[0]);
        FUN_00019198(chunk, 0x204);
        *reinterpret_cast<UInt32 **>(self + 0x10) = nextChunk;
        chunk = nextChunk;
    }

    /* +0x4c = OSObject::_RESERVEDOSObject1(), RESOLVED issue #52 - a real no-op. */
    typedef void (*Fn0x4c)(void *);
    void **vtable = *reinterpret_cast<void ***>(self);
    reinterpret_cast<Fn0x4c>(vtable[0x4c / 4])(this);
}
