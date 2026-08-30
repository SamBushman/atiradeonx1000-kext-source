/*
 * ATIR500GLContext_Invalidate.cpp
 *
 * ATIR500GLContext::invalidate - CONFIRMED, fully transcribed (real kext
 * offset 0x26fb0). RESOLVED (issue #12.1): the real name of the
 * previously-unnamed vtable+0x5a4 virtual method - see
 * Headers/ATIR500GLContext.h's declaration for the full resolution
 * writeup and the vtable-slot verification method used.
 */

#include "../Headers/ATIR500GLContext.h"

void ATIR500GLContext::invalidate() {
    /* Real: sets a dirty/invalidate bit (bit 0) on the object allocated
     * and zeroed at this+0x108 by start() - that object's own type and
     * the meaning of its +0x1c field are UNKNOWN. */
    UInt8 *linked = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(this) + 0x108);
    *reinterpret_cast<UInt32 *>(linked + 0x1c) |= 1;
}
