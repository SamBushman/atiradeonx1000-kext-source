/* NOTE 2026-09-19: 4 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500GLContext_SmallMethods.cpp
 *
 * RESOLVED (ledger pass): the ATIR500GLContext (GL subclass) members that had no body in the rebuild:
 *   set_texture_flags (0x26fd0, vtable +0x5c0)   clientMemoryForType (0x27000, +0x580)
 *   setCompatibleSurfaceMode (0x270a0, +0x5ac)   update_surface (0x27fd0, +0x5a8)
 * Field offsets: this+0xc8 accelerator, +0x290 bound surface, +0x35c and +0x3aa / +0xac: surface-mode fields.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*RetainFn)(void *);
} // namespace

/* Real: for a plain texture (kind byte +0x20 == 0) that belongs to a surface (+0x50), copy bits 0-2 of the
 * surface's first buffer record byte +0x38, shifted left 2, into the texture record's flag byte +0x15. */
/* (re-ported mechanically: see ATIR500GLContext_set_texture_flags_Port.cpp) */


/* Real: type 0 hands out (and retains) the accelerator's shared 0x1000-byte client-memory descriptor; every other
 * type defers to the base class. */
/* (re-ported mechanically: see ATIR500GLContext_clientMemoryForType_Port.cpp) */


/* Real: the base class's own check first; if the modes are not already compatible, try to merge the per-context
 * bits (0x30000 = stereo/quad bits, 0x700000 / 0xc0000 = multisample fields) into *modeBits, failing (false) if
 * two different non-zero values collide. */
/* (re-ported mechanically: see ATIR500GLContext_setCompatibleSurfaceMode_Port.cpp) */


/* Real: recompute the two effective-mode halfwords (this+0x3aa / this+0xac) from this context's mode word
 * (+0x35c) and the bound surface's mode bits, rebuild the scissor, then invalidate and clear the accelerator's
 * "last hardware context" marker. */
/* (re-ported mechanically: see ATIR500GLContext_update_surface_Port.cpp) */

