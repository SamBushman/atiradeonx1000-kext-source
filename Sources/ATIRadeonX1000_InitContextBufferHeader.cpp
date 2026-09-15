/*
 * ATIRadeonX1000_InitContextBufferHeader.cpp
 *
 * RESOLVED (issue #46): `init_context_buffer_header`'s real bodies for
 * all three context classes - `IOATIR500GLContext` (real addr 0x7490),
 * `IOATIR5002DContext` (real addr 0xbaf0), `IOATIR500DVDContext` (real
 * addr 0xe7d0). Called from each class's own `allocAllContextBuffers`
 * (issue #33, `Sources/ATIRadeonX1000_AllocAllContextBuffers.cpp`) once
 * per allocated buffer. All three are structurally IDENTICAL real
 * methods, differing only in one per-class constant - transcribed
 * together in one file, matching this project's convention for tight
 * same-shaped families.
 *
 * Real body (identical shape across all three): zeroes the whole real
 * 0x20-byte `VendorContextBufferHeader` one word at a time (8 real
 * `stwx`-in-a-`bdnz`-loop iterations - CONFIRMED via raw disassembly
 * this is a flat BYTE-offset loop, not scaled by any assumed pointee
 * size, since `stwx r0,rHeader,rOffset` is an indexed store with a
 * literal register offset), then overwrites two of the just-zeroed
 * fields: `capacityField` (+0x10) = `((size - 0x20) >> 2) - K` for a
 * real per-class constant `K`, and `formatTag` (+0x1c) = the literal
 * `1`. See `Headers/ATIRadeonX1000Types.h` for the full struct writeup
 * and the honest INFERRED/CONFIRMED split on field roles.
 *
 * Real per-class K: GL 0x91 (145), 2D 4, DVD 0x16 (22) - independently
 * decompiled per class and cross-checked; no other real differences
 * exist between the three bodies.
 *
 * Confidence: CONFIRMED for control flow, real struct size, and both
 * written fields' real offsets/values (all three independently
 * decompiled AND independently cross-checked against raw PPC
 * disassembly for the GL body, which settled the byte-vs-scaled-offset
 * question directly rather than trusting Ghidra's C-level pointer
 * arithmetic on the still only partially-understood
 * `VendorContextBufferHeader*` parameter type - see the project's own
 * "opaque struct pointer arithmetic" caution). `capacityField`'s and
 * `formatTag`'s real SEMANTIC role beyond their confirmed values is
 * INFERRED, not confirmed - no other code in this project reads either
 * field yet. No C++ compiler was available in the sandboxed environment
 * this was written in (same standing limitation as every other file in
 * this project).
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline void ZeroHeader(VendorContextBufferHeader *header) {
    UInt32 *words = reinterpret_cast<UInt32 *>(header);
    for (int i = 0; i < 8; i++) {
        words[i] = 0;
    }
}
} // namespace

void IOATIR500GLContext::init_context_buffer_header(VendorContextBufferHeader *header, UInt32 size) {
    ZeroHeader(header);
    header->formatTag = 1;
    header->capacityField = ((size - 0x20) >> 2) - 0x91;
}

void IOATIR5002DContext::init_context_buffer_header(VendorContextBufferHeader *header, UInt32 size) {
    ZeroHeader(header);
    header->formatTag = 1;
    header->capacityField = ((size - 0x20) >> 2) - 4;
}

void IOATIR500DVDContext::init_context_buffer_header(VendorContextBufferHeader *header, UInt32 size) {
    ZeroHeader(header);
    header->formatTag = 1;
    header->capacityField = ((size - 0x20) >> 2) - 0x16;
}
