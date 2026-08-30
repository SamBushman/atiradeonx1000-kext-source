/*
 * IOATIR500Shared.h
 *
 * A real class this project has not reconstructed - found this pass only
 * as IOATIR500GLContext::start's real allocation site (`new`'d as a
 * 0x28-byte object, default-constructed, then a real vtable call at
 * +0x48 that must succeed or the object is released via another real
 * vtable call at +0x18). Forward-declared and referenced elsewhere in
 * this project (e.g. IOATIR500Accelerator.h) as the concrete type behind
 * every context class's `clientHandle` field, but its own real method
 * set, field layout, and base class are all UNKNOWN. Left as a minimal
 * shell rather than inventing an interface this project hasn't actually
 * decompiled - see GAPS.md.
 */

#ifndef IOATIR500SHARED_H
#define IOATIR500SHARED_H

#include "ATIRadeonX1000Types.h"

class IOATIR500Shared {
public:
    IOATIR500Shared();
    /* Real size CONFIRMED (0x28 bytes, from its allocation site).
     * Real vtable calls at +0x48 (init-like, must succeed) and +0x18
     * (release-like) are known to exist - see IOATIR500GLContext_Start.cpp -
     * but not independently named or decompiled this pass. */
};

#endif /* IOATIR500SHARED_H */
