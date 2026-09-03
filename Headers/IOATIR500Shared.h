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
    /* Real size CONFIRMED (0x28 bytes, from its allocation site). */

    /*
     * init - RESOLVED, issue #20 (partial). Real vtable slot `+0x48`,
     * real addr `0x16aa0` - found by reading this class's own vtable
     * (`__ZTV15IOATIR500Shared`, `0x48f28`) directly, the same technique
     * that resolved issues #6/#18/#19. Real return type INFERRED as the
     * conventional IOKit `bool` (`IOATIR500GLContext_Start.cpp`'s own
     * call site checks the result against 0 for failure) - own body not
     * independently decompiled this pass.
     *
     * The paired real `+0x18` (release-like) vtable call this class's
     * own real constructor-site failure path also makes is STILL
     * genuinely unresolved - confirmed genuine placeholder content
     * (raw 0) on this class's own vtable, the SAME real category issue
     * #6 established for the accelerator's factory slots. This class has
     * no known subclass in this project (unlike Surface/Accelerator), so
     * there is no further subclass vtable to check - issue #20 stays
     * open for this slot.
     */
    bool init();

    /*
     * delete_texture - CONFIRMED real name/signature (real mangled
     * symbol __ZN15IOATIR500Shared14delete_textureEP19VendorTextureBuffer,
     * kext offset 0x17950), found this pass (issue #7) as a real call
     * site in ATIR500DVDContext::process_command_buffer's texture-
     * unbind family. Real gating pattern at every call site: only
     * invoked after a real refcount-style helper (this project's
     * FUN_0003911c) returns exactly 1, i.e. "this was the last
     * reference". Own body NOT independently decompiled this pass. Also
     * declared (not yet reconstructed) elsewhere in this project's
     * comments: new_agp_texture/new_texture - the same real allocator
     * GL/2D's declare_image/create_image call through.
     */
    void delete_texture(VendorTextureBuffer *texture);
};

#endif /* IOATIR500SHARED_H */
