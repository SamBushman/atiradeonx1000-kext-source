/* NOTE 2026-09-19: 2 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Surface_AllocSurfacesPageq.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `IOATIR500Surface::invalidate_contexts` (real addr 0x12050) and
 * `IOATIR500Surface::alloc_surfaces_pageq` (real addr 0x12110) - see
 * each method's own header comment in `Headers/IOATIR500Surface.h` for
 * full detail on real offsets/return-value meanings.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - two real, complete, standalone decompiles.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*InvalidateFn)(void *);
typedef UInt32 (*Fn0x5f4)(void *, UInt32, UInt32);
} // namespace

/* (re-ported mechanically: see IOATIR500Surface_invalidate_contexts_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_alloc_surfaces_pageq_Port.cpp) */

