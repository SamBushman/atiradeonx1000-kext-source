/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Shared_AllocHandles.cpp
 *
 * RESOLVED (issue #28): `IOATIR500Shared::alloc_handles()`'s real body.
 * Real kext offset 0x16910.
 *
 * A real growable "handle table": a combined single allocation holding a
 * primary per-handle array (4 bytes/handle) immediately followed by a
 * secondary bitmap (1 bit/handle, byte size = handle count / 8) - real
 * fields `this+0x10` (combined buffer base), `this+0x14` (handle
 * capacity), `this+0x18` (secondary bitmap base, = primary base +
 * primary size). First call (`this+0x14 == 0`): allocates a fixed
 * initial capacity of `0x400` handles (`0x1000`-byte primary + `0x80`-byte
 * bitmap). Later calls: DOUBLES the existing capacity, computing the new
 * primary/bitmap sizes from the new (doubled) count.
 *
 * On growth, allocates the new combined buffer, zeroes it, copies the
 * OLD primary array and OLD bitmap into their new (larger) locations,
 * frees the old combined buffer, and - if a real "owner" object exists
 * at `this+0xc` (role UNKNOWN beyond this byte-accounting use) -
 * maintains a real running byte-accounting field at `owner+0x808`
 * (added on growth, subtracted back by the freed old buffer's size).
 * Real return: `bool` success/failure (fails only if the new allocation
 * itself fails).
 *
 * Four real, previously-uncatalogued lazy-binding stubs surfaced while
 * decompiling this body - RESOLVED, issue #27/#28 (live kxld-resolved
 * memory read on real G5/Tiger hardware, cross-referenced against the
 * running kernel's own symbol table, same technique as issues #15/#20):
 * `FUN_00016a88` -> `IOMalloc`, `FUN_00016a78` -> `memset`,
 * `FUN_00016a68` -> `memmove`, `FUN_00016a58` -> `IOFree`.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant - a real, complete, standalone decompile. No C++ compiler was
 * available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project) - checked by
 * careful, repeated manual re-reading against the raw decompile instead.
 */

#include "../Headers/IOATIR500Shared.h"

extern "C" void *FUN_00016a88(UInt32 size) asm("_IOMalloc");
extern "C" void  FUN_00016a78(void *ptr, UInt32 zero, UInt32 size) asm("_memset");
extern "C" void  FUN_00016a68(void *dest, const void *src, UInt32 size) asm("_memmove");
extern "C" void  FUN_00016a58(void *ptr, UInt32 size) asm("_IOFree");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see IOATIR500Shared_alloc_handles_Port.cpp) */

