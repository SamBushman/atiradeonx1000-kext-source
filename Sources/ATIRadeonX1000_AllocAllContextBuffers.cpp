/*
 * ATIRadeonX1000_AllocAllContextBuffers.cpp
 *
 * RESOLVED (issue #33): `allocAllContextBuffers`'s real bodies for all
 * three context classes - `IOATIR500GLContext` (real addr 0x74d0),
 * `IOATIR5002DContext` (real addr 0xbee0), `IOATIR500DVDContext` (real
 * addr 0xeab0). All three are structurally identical real methods
 * (same real per-class pattern this project had already documented by
 * name), differing only in field offsets and a real per-class loop
 * count - transcribed together in one file for that reason, matching
 * this project's convention for tight same-shaped families (e.g.
 * `MapTransferToGART_RemainingContexts.cpp`).
 *
 * ALSO FIXED this pass: `IOATIR500DVDContext::allocAllContextBuffers`
 * was wrongly declared on `ATIR500DVDContext` (the SUBCLASS) - that
 * declaration's own comment already correctly named the real mangled
 * symbol as a member of `IOATIR500DVDContext` (the BASE class). Moved
 * to `Headers/IOATIR500DVDContext.h`. `IOATIR5002DContext`'s own
 * version was a real, previously-undeclared gap (GL/DVD's were already
 * documented; 2D's never was) - added there too.
 *
 * Real body (identical shape across all three, only offsets/counts
 * differ - GL shown, others use their own per-class field offsets and
 * loop bound per the table below): allocates a real "primary" command
 * buffer via `IOBufferMemoryDescriptor::withOptions` (this project's
 * already-RESOLVED `FUN_withOptions`, issue #27/`IOATIR500Accelerator_
 * DataBufferPool.cpp` - the raw decompile's own per-class `FUN_xxxx`
 * call thunks for this, `FUN_0000c088`/`FUN_00007678`/`FUN_0000ec48`,
 * are the SAME real external symbol via three different local call
 * thunks, matching this project's established "same external target,
 * different local thunk address per translation unit" pattern), sized
 * `size`, flags `0x10023 | (a real per-accelerator flag field, GL/2D
 * only - DVD always passes plain `0x10023`)`. Gets that buffer's own
 * real hardware-mappable header via vtable `+0x1cc` (already-established
 * real slot, matches `allocCommandBuffer`'s own use of it -
 * `Headers/IOATIR500Accelerator.h`), calls the real, per-class
 * `init_context_buffer_header` (own body not decompiled this pass) to
 * initialize it, then repeats the SAME allocate+header-init pattern a
 * real fixed number of additional times into a per-class array (stride
 * `0x18` real bytes per entry: buffer pointer, header pointer, plus a
 * real 2-word gap this project hasn't independently named). On any
 * allocation failure partway through, rolls back every buffer
 * successfully allocated so far in this call (releases each via vtable
 * `+0x18` - `OSObject::release()` - and zeroes its slot), releases the
 * primary buffer the same way, zeroes every one of this class's own
 * "context buffer" fields, and returns `false`. On full success returns
 * `true`.
 *
 * Real per-class differences:
 *   GL:  primary fields `this+0xfc`/`+0x108`; array base `this+0x114`
 *        (stride 0x18); loop runs while `count != 0xf` (16 additional
 *        buffers, 17 total) - GL needs far more command buffers than
 *        2D/DVD, matching `allocMoreCommandBuffers`'s own 0x10-capacity
 *        cap (`Headers/IOATIR500Accelerator.h`); flag OR's in
 *        `*(uint*)(this+200's own +0x82c)` (a real per-accelerator flag
 *        field, same `+0x82c` offset this project's own
 *        `IOATIR500Accelerator_DataBufferPool.cpp` already uses for an
 *        analogous flag OR).
 *   2D:  primary fields `this+0xbc`/`this+200` (0xc8); array base
 *        `this+0xd4` (stride 0x18); loop runs while `count != 1` (2
 *        additional buffers, 3 total); same `+0x82c`-flag-OR pattern
 *        (via `this+0x94`, 2D's own accelerator field).
 *   DVD:  primary fields `this+0xb4`/`this+0xc0`; array base `this+0xcc`
 *        (stride 0x18); loop runs while `count != 1` (2 additional
 *        buffers, 3 total); REAL DIFFERENCE FROM GL/2D - every
 *        allocation (primary AND all repeats) uses the plain literal
 *        `0x10023` flag, with NO per-accelerator flag OR at all
 *        (transcribed exactly as decompiled, not assumed to match its
 *        siblings).
 *
 * Confidence: CONFIRMED for control flow and every real offset/loop
 * bound (all three independently decompiled and cross-checked against
 * each other for consistency). `init_context_buffer_header`'s own real
 * per-class body remains a genuine gap (declared, not decompiled). No
 * C++ compiler was available in the sandboxed environment this was
 * written in (same standing limitation as every other file in this
 * project).
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000Types.h"

/* RESOLVED, issue #27 - real IOBufferMemoryDescriptor::withOptions, same
   real external target these three classes' own local call thunks
   (FUN_0000c088/FUN_00007678/FUN_0000ec48 in the raw per-class decompile)
   all resolve to - see Sources/IOATIR500Accelerator_DataBufferPool.cpp
   for the original resolution. */
extern "C" void *FUN_withOptions(UInt32 options, UInt32 capacity, int align) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");
extern "C" int _ASICSupportsAGP;

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }

typedef void *(*GetHeaderFn)(void *);
inline void *GetHardwareMappableHeader(void *bufferObj) {
    void **vtable = *reinterpret_cast<void ***>(bufferObj);
    return reinterpret_cast<GetHeaderFn>(vtable[0x1cc / 4])(bufferObj);
}
inline void ReleaseObj(void *obj) {
    typedef void (*ReleaseFn)(void *);
    void **vtable = *reinterpret_cast<void ***>(obj);
    reinterpret_cast<ReleaseFn>(vtable[0x18 / 4])(obj);
}

/* Shared real rollback helper: releases `count` already-allocated repeat-
   array entries, in reverse. `entry` is this project's own reference point
   (the buffer-pointer field, matching where the allocation loop below
   writes it) - the real per-entry struct actually starts 8 bytes BEFORE
   that (two real UNKNOWN dwords this project hasn't independently named),
   confirmed by the real rollback code's own negative offsets
   (`pIVar7[-8]`/`pIVar7[-4]`) relative to this same reference point;
   the header pointer field sits at `entry+0xc`, with two more real
   UNKNOWN UInt16 fields between them (`entry+4`/`entry+6`) - full real
   0x18-byte struct: `[entry-8, entry+0x10)`. Per-class field zeroing (the
   primary buffer/header/etc.) is done separately at each call site since
   the real field offsets differ per class. */
void ReleaseAndZeroEntries(UInt8 *arrayBase, int stride, int count) {
    for (int i = count - 1; i >= 0; i--) {
        UInt8 *entry = arrayBase + i * stride;
        void *buf = *reinterpret_cast<void **>(entry);
        ReleaseObj(buf);
        U32At(entry, -8) = 0;
        U32At(entry, -4) = 0;
        U32At(entry, 0) = 0;
        U16At(entry, 4) = 0;
        U16At(entry, 6) = 0;
        U32At(entry, 8) = 0;
        U32At(entry, 0xc) = 0;
    }
}
} // namespace

bool IOATIR500GLContext::allocAllContextBuffers(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 flags = 0x10023 | U32At(*reinterpret_cast<UInt8 **>(self + 200), 0x82c);

    void *primaryBuf = FUN_withOptions(flags, size, _ASICSupportsAGP);
    *reinterpret_cast<void **>(self + 0xfc) = primaryBuf;
    if (primaryBuf == nullptr) {
        return false;
    }

    void *primaryHeader = GetHardwareMappableHeader(primaryBuf);
    *reinterpret_cast<void **>(self + 0x108) = primaryHeader;
    init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(primaryHeader), size);

    UInt8 *entry = self + 0x114;
    int count = 0;
    for (;;) {
        UInt32 flags2 = 0x10023 | U32At(*reinterpret_cast<UInt8 **>(self + 200), 0x82c);
        void *buf = FUN_withOptions(flags2, size, _ASICSupportsAGP);
        *reinterpret_cast<void **>(entry) = buf;
        if (buf == nullptr) {
            ReleaseAndZeroEntries(self + 0x114, 0x18, count);
            ReleaseObj(primaryBuf);
            U32At(self, 0x108) = 0;
            U32At(self, 0xf4) = 0;
            U32At(self, 0xf8) = 0;
            U32At(self, 0xfc) = 0;
            U16At(self, 0x102) = 0;
            U16At(self, 0x100) = 0;
            U32At(self, 0x104) = 0;
            return false;
        }
        void *header = GetHardwareMappableHeader(buf);
        *reinterpret_cast<void **>(entry + 0xc) = header;
        entry += 0x18;
        init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(header), size);
        count++;
        if (count == 0x10) {
            break; /* real: loop while (count != 0xf), i.e. runs for count 0..15 -> 16 repeats */
        }
    }
    return true;
}

bool IOATIR5002DContext::allocAllContextBuffers(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 flags = 0x10023 | U32At(*reinterpret_cast<UInt8 **>(self + 0x94), 0x82c);

    void *primaryBuf = FUN_withOptions(flags, size, _ASICSupportsAGP);
    *reinterpret_cast<void **>(self + 0xbc) = primaryBuf;
    if (primaryBuf == nullptr) {
        return false;
    }

    void *primaryHeader = GetHardwareMappableHeader(primaryBuf);
    *reinterpret_cast<void **>(self + 200) = primaryHeader;
    init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(primaryHeader), size);

    UInt8 *entry = self + 0xd4;
    int count = 0;
    for (;;) {
        UInt32 flags2 = 0x10023 | U32At(*reinterpret_cast<UInt8 **>(self + 0x94), 0x82c);
        void *buf = FUN_withOptions(flags2, size, _ASICSupportsAGP);
        *reinterpret_cast<void **>(entry) = buf;
        if (buf == nullptr) {
            ReleaseAndZeroEntries(self + 0xd4, 0x18, count);
            ReleaseObj(primaryBuf);
            U32At(self, 200) = 0;
            U32At(self, 0xb4) = 0;
            U32At(self, 0xb8) = 0;
            U32At(self, 0xbc) = 0;
            U16At(self, 0xc2) = 0;
            U16At(self, 0xc0) = 0;
            U32At(self, 0xc4) = 0;
            return false;
        }
        void *header = GetHardwareMappableHeader(buf);
        *reinterpret_cast<void **>(entry + 0xc) = header;
        entry += 0x18;
        init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(header), size);
        count++;
        if (count == 2) {
            break; /* real: loop while (count != 1), i.e. runs for count 0..1 -> 2 repeats */
        }
    }
    return true;
}

bool IOATIR500DVDContext::allocAllContextBuffers(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    /* real: DVD, unlike GL/2D, passes the plain literal 0x10023 with NO
       per-accelerator flag OR - transcribed exactly as decompiled. */
    void *primaryBuf = FUN_withOptions(0x10023, size, _ASICSupportsAGP);
    *reinterpret_cast<void **>(self + 0xb4) = primaryBuf;
    if (primaryBuf == nullptr) {
        return false;
    }

    void *primaryHeader = GetHardwareMappableHeader(primaryBuf);
    *reinterpret_cast<void **>(self + 0xc0) = primaryHeader;
    init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(primaryHeader), size);

    UInt8 *entry = self + 0xcc;
    int count = 0;
    for (;;) {
        void *buf = FUN_withOptions(0x10023, size, _ASICSupportsAGP);
        *reinterpret_cast<void **>(entry) = buf;
        if (buf == nullptr) {
            ReleaseAndZeroEntries(self + 0xcc, 0x18, count);
            ReleaseObj(primaryBuf);
            U32At(self, 0xc0) = 0;
            U32At(self, 0xac) = 0;
            U32At(self, 0xb0) = 0;
            U32At(self, 0xb4) = 0;
            U16At(self, 0xba) = 0;
            U16At(self, 0xb8) = 0;
            U32At(self, 0xbc) = 0;
            return false;
        }
        void *header = GetHardwareMappableHeader(buf);
        *reinterpret_cast<void **>(entry + 0xc) = header;
        entry += 0x18;
        init_context_buffer_header(reinterpret_cast<VendorContextBufferHeader *>(header), size);
        count++;
        if (count == 2) {
            break; /* real: loop while (count != 1), i.e. runs for count 0..1 -> 2 repeats */
        }
    }
    return true;
}
