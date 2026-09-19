/*
 * IOATIR500GLContext_SmallMethods.cpp
 *
 * RESOLVED (ledger pass): the IOATIR500GLContext (GL base class) members that had no body in the rebuild, all
 * transcribed from the shipped kext's decompile:
 *   clientClose (0x7130, vtable +0x568)                 remove_surface (0x79c0)
 *   setCompatibleSurfaceMode (0x7b70, vtable +0x5ac)    set_texture_flags (0x7e60, +0x5c0): empty
 *   add_vendor_surface_required_bits (0x83b0, +0x5bc): empty
 * Field offsets: this+0xc8 accelerator, this+0x290 bound surface, this+0x294 "started" flag.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* Real: if the started flag is set, stop() then detach() from the accelerator (vtable +0x34c / +0x3a8). */
/* (re-ported mechanically: see IOATIR500GLContext_clientClose_Port.cpp) */


/* (re-ported mechanically: see IOATIR500GLContext_remove_surface_Port.cpp) */


/* Real: true iff the surface's current mode bits, ignoring the per-context bits, equal the requested mode. */
/* Real: true iff the surface's current mode bits, ignoring the per-context bits, equal the requested mode. */
bool IOATIR500GLContext::setCompatibleSurfaceMode(SInt32 *modeBits, eIOGLContextModeBits mode, SInt32 flags) {
    (void)flags;
    return (static_cast<UInt32>(*modeBits) & 0xffff7fc0u) == (static_cast<UInt32>(mode) & 0xffffc03fu);
}


/* (re-ported mechanically: see IOATIR500GLContext_set_texture_flags_Port.cpp) */


/* (re-ported mechanically: see IOATIR500GLContext_add_vendor_surface_required_bits_Port.cpp) */

