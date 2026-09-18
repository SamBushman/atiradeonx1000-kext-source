/*
 * ATIR500Memory_Lifecycle.cpp
 *
 * RESOLVED (issue #25): `ATIR500Memory::init()`/`free()`'s real bodies,
 * real addrs `0x18d50`/`0x19120`.
 *
 * CORRECTED (issue #58 follow-up; supersedes the issue #52 account): `init()`
 * begins with the qualified base-class call `OSObject::init()` and `free()`
 * ends with `OSObject::free()`. The raw decompile shows them as
 * `(*pcRam00000048)()` / `(*pcRam0000004c)(this)` - indirect calls through the
 * OSObject vtable symbol (Mach-O relocations at 0x18d54/0x1916c both target
 * `__ZTV8OSObject`; `-fapple-kext` compiles qualified base calls this way).
 * Slot +0x48 of the real kernel's OSObject vtable, read statically from
 * /mach_kernel, is `OSObject::init()`, and +0x4c is `OSObject::free()`. The
 * earlier issue #52 reading (`_RESERVEDOSObject0/1`, "genuine no-ops", "`ok` is
 * a decompiler artifact") was wrong - those reserved slots are +0x50/+0x54.
 *
 * Then walk and free the real `chunkList` (see `Headers/ATIR500Memory.h`)
 * via a real per-chunk kernel-free wrapper - RESOLVED, issue #27: real
 * target `IOFreeAligned`, same real category issue #15 established for
 * the alloc/free pair elsewhere; `init` and `free` each call their own
 * distinct per-call-site stub instance (`FUN_00018de8`/`FUN_00019198`)
 * resolving to the same real target.
 *
 * `init()`'s post-super behavior (tearing down any existing `chunkList`) is a
 * re-initialisation reset. `init_pool`'s two overloads
 * (`ATIR500Memory_Pool.cpp`) call it virtually through `this` first.
 *
 * Confidence: CONFIRMED for control flow and every field offset - both
 * real, complete, standalone decompiles.
 */

#include "../Headers/ATIR500Memory.h"

/* real object size, from its allocation site (issue #23) */
static_assert(sizeof(ATIR500Memory) == 0x28, "ATIR500Memory must be 0x28 bytes");

extern "C" void FUN_00018de8(void *chunk, UInt32 size) asm("_IOFreeAligned"); /* init()'s own stub instance */
extern "C" void FUN_00019198(void *chunk, UInt32 size) asm("_IOFreeAligned"); /* free()'s own stub instance (distinct real address, same real target) */

bool ATIR500Memory::init() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    /* real: OSObject::init() (raw decompile: `(*pcRam00000048)()`, see header comment) */
    if (!OSObject::init()) {
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

    /* real: OSObject::free() (raw decompile: `(*pcRam0000004c)(this)`, see header comment) */
    OSObject::free();
}
