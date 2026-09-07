/*
 * ATIR500Memory_Lifecycle.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::init()`/`free()`'s real bodies,
 * real addrs `0x18d50`/`0x19120`.
 *
 * Both gate on this class's own real vtable slot `+0x48` (`init`) - a
 * genuine virtual call through `this`'s own vtable, own real target
 * unresolved (this class's base/hierarchy was never established - left
 * as a raw vtable-indirect call, matching this project's own "Fn0xNNN"
 * convention for unidentified vtable slots elsewhere, e.g.
 * `ATIR500Surface_ResetFullScreen.cpp`'s own `+0x5e0` call) - then walk
 * and free the real `chunkList` (see `Headers/ATIR500Memory.h`) via a
 * real opaque per-chunk kernel-free wrapper (own body not decompiled,
 * same category as issue #15's own alloc/free pair; `init` and `free`
 * each call a DIFFERENT real address for this, `FUN_00018de8` vs
 * `FUN_00019198` - two distinct real stubs, not the same function
 * reused). `free()` additionally calls this object's own real vtable
 * slot `+0x4c` (own target/role unresolved) as its final action - a
 * real "continue teardown"/self-free call, consistent with `+0x48`/
 * `+0x4c` being a real init/free virtual pair on this class's own base.
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

extern "C" void FUN_00018de8(void *chunk, UInt32 size); /* real opaque per-chunk free wrapper, init()'s own */
extern "C" void FUN_00019198(void *chunk, UInt32 size); /* real opaque per-chunk free wrapper, free()'s own (distinct real address) */

bool ATIR500Memory::init() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

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

    typedef void (*Fn0x4c)(void *);
    void **vtable = *reinterpret_cast<void ***>(self);
    reinterpret_cast<Fn0x4c>(vtable[0x4c / 4])(this);
}
