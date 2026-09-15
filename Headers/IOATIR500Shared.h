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
    /*
     * FIXED (issue #1, first real link attempt): was declared with no
     * definition anywhere - a real undefined-symbol link error the
     * moment anything (IOATIR500GLContext::start) actually instantiated
     * one. Defined inline as empty: this class's own real field layout
     * is genuinely UNKNOWN (see class header comment) so there is
     * nothing honest to initialize by name; `init()` (below) is the
     * real function that does the real work, matching the real
     * decompile's own two-step alloc-then-init IOKit pattern.
     */
    IOATIR500Shared() {}
    /*
     * Real size CONFIRMED (0x28 bytes, from its allocation site). FIXED
     * (issue #1): this class declares zero real C++ data members (every
     * real field is accessed by raw offset elsewhere, not by name - see
     * Sources/IOATIR500Shared_Init.cpp/_AllocHandles.cpp), which without
     * this trailing pad would make `sizeof(IOATIR500Shared)` far smaller
     * than the real 0x28-byte object - a real heap-corruption risk the
     * moment `init()`'s own raw writes up to `self+0x24` ran against an
     * undersized `new`allocation. Matches this project's own established
     * "confirmed size, unconfirmed field breakdown" pad convention
     * (e.g. ATIRadeonX1000Types.h's `_trailer_unconfirmed`).
     */
    UInt8 _pad_confirmed_size[0x28];

    /*
     * init - RESOLVED, issue #20/#24. Real vtable slot `+0x48`, real
     * addr `0x16aa0` - found by reading this class's own vtable
     * (`__ZTV15IOATIR500Shared`, `0x48f28`) directly, the same technique
     * that resolved issues #6/#18/#19. Real body (issue #24): calls a
     * real external symbol first (almost certainly `OSObject::init()`,
     * conventional for a real IOKit `init()` override - own real target
     * unresolved, same kxld-patched-at-load-time category issue #6
     * established before ITS OWN resolution, except this class has no
     * known subclass to try that same fix on), then zeroes six real
     * fields and calls `alloc_handles()` - see
     * `Sources/IOATIR500Shared_Init.cpp` for the full transcription.
     *
     * The paired real `+0x18` (release-like) vtable call this class's
     * own real constructor-site failure path also makes is RESOLVED,
     * issue #20: a live kxld-resolved memory read on real G5/Tiger
     * hardware (the exact kext loaded and running, `kextstat` giving the
     * real load address, the loaded image's own live Mach-O load
     * commands giving the real per-segment slide) showed the real,
     * kxld-patched runtime pointer value at this slot - an EXACT
     * (offset-0) match, in `nm /mach_kernel`'s own symbol table, to
     * `OSObject::release() const` (`__ZNK8OSObject7releaseEv`). This
     * class inherits `release()` unoverridden from `OSObject`, exactly
     * as expected for a lightweight IOKit-derived allocator with no
     * special teardown of its own. No custom kext code was written or
     * loaded to obtain this - a plain, read-only userspace `/dev/kmem`
     * reader, validated against the already-CONFIRMED `init()` slot
     * before being trusted on this one.
     */
    bool init();

    /*
     * alloc_handles - RESOLVED, issue #28. Real mangled symbol
     * __ZN15IOATIR500Shared13alloc_handlesEv, kext offset 0x16910,
     * called unconditionally from `init()` above (return value discarded
     * there). Real body: grows a combined handle-array+bitmap allocation,
     * doubling capacity each call - see
     * `Sources/IOATIR500Shared_AllocHandles.cpp` for the full
     * transcription. REAL RETURN TYPE CORRECTED to `bool` (was declared
     * `void`) - the real decompiled body returns a real success/failure
     * boolean, simply never checked at its one known call site.
     */
    bool alloc_handles();

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
    IOReturn delete_texture(VendorTextureBuffer *texture); /* RETURN TYPE CORRECTED (issue #1, get-it-linking pass): was declared void, but the real confirmed call site (IOATIR500GLContext::delete_texture) assigns and returns its result - a real, checked IOReturn value, not void. */

    /*
     * new_surface_texture / new_global_texture / new_texture /
     * new_agpref_texture - CONFIRMED to exist (real call sites in
     * IOATIR500GLContext::new_texture, issue #1 get-it-linking pass -
     * this class's own real allocator family, anticipated but not
     * previously declared - see delete_texture's own comment above).
     * Real signatures INFERRED from their call sites' own argument
     * shapes (own bodies NOT independently decompiled this pass -
     * genuine gap, tracked for follow-up, not guessed at beyond what
     * the call sites themselves establish). All four return what the
     * real call sites treat as a `VendorTextureBuffer*`-shaped handle
     * (non-null on success, passed straight into further vtable calls
     * taking that exact type elsewhere in this project).
     */
    VendorTextureBuffer *new_surface_texture(UInt32 param2, UInt32 param3, UInt32 param4, UInt32 *outParam);
    VendorTextureBuffer *new_global_texture(UInt32 param2, UInt32 *outParam);
    VendorTextureBuffer *new_texture(UInt32 param2, UInt32 param3, UInt32 param4, UInt32 param5, UInt32 *out1, UInt32 *out2);
    VendorTextureBuffer *new_agpref_texture(UInt32 param2, UInt32 param3, UInt32 param4, UInt32 *outParam);
};

#endif /* IOATIR500SHARED_H */
