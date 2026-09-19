/*
 * IOATIR500GLContext_RegularMethods.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for most of this
 * base class's own 20 regular external methods (selectors 0-19) - the
 * ones NOT already covered by their own dedicated file
 * (page_off_texture, start, stop, freeAllContextBuffers,
 * init_context_buffer_header, freeCommandBuffer, add_texture_to_stream/
 * remove_texture_from_stream/map_transfer_to_GART - all already
 * committed elsewhere). `clientMemoryForType` and `get_data_buffer`
 * (the two largest, most complex real bodies in this table) are handled
 * in their own file, IOATIR500GLContext_ClientMemory.cpp.
 *
 * Every field offset below is raw pointer arithmetic against `this`
 * because this base class's real compiled code reaches fields this
 * project models as declared on the concrete ATIR500GLContext subclass
 * (`boundSurface` +0x290, `mipLevel` +0x29c, etc.) - C++ base-class code
 * cannot name a derived-only member, but the real ABI places these
 * fields at the same absolute offset regardless of which class "owns"
 * the C++ declaration, exactly matching every other base-class function
 * already in this project that touches these same fields.
 *
 * Confidence: CONFIRMED for control flow and every real offset (direct
 * Ghidra decompile of the real kext, no analysis re-run needed - this
 * project's own existing headless-decompile project already has the
 * binary imported). Several vtable slot call targets are already
 * independently named elsewhere in this project's own headers
 * (IOATIR500Accelerator.h / IOATIR500Surface.h) and are called by name
 * below; slots this project has NOT independently confirmed elsewhere
 * are called via this project's own established raw-vtable-cast idiom,
 * flagged individually.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIRadeonX1000.h"
#include <IOKit/IOLocks.h>

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* Same real commandLock lock/unlock pair every external method in this
 * project brackets its own body with - see
 * IOATIR500GLContext_PageOffTexture.cpp's own copy of this declaration
 * for the full note (gcc-4.0.1 rejects a local `extern "C"`, so this
 * lives at file scope, redeclared here rather than shared via a header
 * since it's a tiny, self-contained real-symbol pin). */
extern "C" void GLContext_mutex_lock(void *) asm("_IOLockLock");
extern "C" void GLContext_mutex_unlock(void *) asm("_IOLockUnlock");

/*
 * finish - CONFIRMED. Real body: a single real accelerator vtable call
 * at +0x55c (own real identity not independently confirmed elsewhere in
 * this project - called with this context's own +0x7c "current tag"
 * field), accumulating the real returned delta into the accelerator's
 * own +0x7a8 field (the same real "completion-stamp accumulator"
 * pattern this project already established for `waitForTimeStamp`
 * itself, just a different accelerator-relative slot).
 */
IOReturn IOATIR500GLContext::finish() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *accel = *reinterpret_cast<void **>(self + 0xc8);
    typedef SInt32 (*Fn0x55c)(void *, UInt32);
    SInt32 delta = (*reinterpret_cast<Fn0x55c *>(*reinterpret_cast<void ***>(accel) + (0x55c / 4)))(accel, U32At(self, 0x7c));
    if (delta == -1) {
        return 0xe00002d6;
    }
    U32At(accel, 0x7a8) += delta;
    return 0;
}

/*
 * wait_for_stamp - CONFIRMED to exist and its own real control flow -
 * structurally identical to `finish()` above, one accelerator vtable
 * call (+0x550) accumulated into the accelerator's own +0x768 field.
 * Real decompile shows the vtable call rendered with ZERO visible
 * arguments (the same real Ghidra calling-convention-inference artifact
 * this project already documents elsewhere, e.g.
 * ATIR500GLContext_TextureLoad.cpp's own `load_texture` note) - this
 * function's own declared signature (`wait_for_stamp(UInt32 tag)`,
 * already established elsewhere in this project) is trusted over the
 * raw decompile's apparent zero-argument call, passing `tag` through.
 */
IOReturn IOATIR500GLContext::wait_for_stamp(UInt32 tag) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *accel = *reinterpret_cast<void **>(self + 0xc8);
    typedef SInt32 (*Fn0x550)(void *, UInt32);
    SInt32 delta = (*reinterpret_cast<Fn0x550 *>(*reinterpret_cast<void ***>(accel) + (0x550 / 4)))(accel, tag);
    if (delta == -1) {
        return 0xe00002d6;
    }
    U32At(accel, 0x768) += delta;
    return 0;
}

/*
 * set_surface_volatile_state - CONFIRMED, simple: stores the raw bits
 * at this+0xc4, then forwards to the bound surface's own
 * set_volatile_state if one is bound. Real decompile shows the forward
 * call with zero visible arguments (the same real Ghidra calling-
 * convention-inference artifact this project documents elsewhere) -
 * `set_volatile_state`'s own real confirmed signature takes the state
 * value directly (issue #1, get-it-linking pass - see
 * IOATIR500Surface.h's own signature correction), so `state` itself is
 * the natural, obvious argument passed through here.
 */
IOReturn IOATIR500GLContext::set_surface_volatile_state(UInt32 state) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(self, 0xc4) = state;
    IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(self + 0x290);
    if (surface != nullptr) {
        surface->set_volatile_state(static_cast<eSurfaceVolatileState>(state));
    }
    return 0;
}

/*
 * set_swap_rect / set_swap_interval - CONFIRMED, both simple: store 4
 * (or 2) raw SInt16 fields, then invalidate() the bound surface if one
 * is bound.
 */
IOReturn IOATIR500GLContext::set_swap_rect(SInt32 x, SInt32 y, SInt32 w, SInt32 h) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    S16At(self, 0x90) = static_cast<SInt16>(x);
    S16At(self, 0x92) = static_cast<SInt16>(y);
    S16At(self, 0x94) = static_cast<SInt16>(w);
    S16At(self, 0x96) = static_cast<SInt16>(h);
    IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(self + 0x290);
    if (surface != nullptr) {
        surface->invalidate();
    }
    return 0;
}

IOReturn IOATIR500GLContext::set_swap_interval(SInt32 a, SInt32 b) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    S16At(self, 0x98) = static_cast<SInt16>(a);
    S16At(self, 0x9a) = static_cast<SInt16>(b);
    IOATIR500Surface *surface = *reinterpret_cast<IOATIR500Surface **>(self + 0x290);
    if (surface != nullptr) {
        surface->invalidate();
    }
    return 0;
}

/*
 * delete_texture - CONFIRMED: bounds-checked lookup in the client
 * handle's own texture table (the same real table shape every other
 * context class's own texture lookups already use), then forwards to
 * IOATIR500Shared::delete_texture.
 */
/* (re-ported mechanically: see IOATIR500GLContext_delete_texture_Port.cpp) */


/*
 * become_global_shared - CONFIRMED. Real body: a real mutual-exclusion
 * gate on the accelerator's own single "global shared" slot (+0x6c) -
 * `param==0` releases this context's own claim if it currently holds
 * it (and the claimant's own +0x24 field is clear), `param!=0` claims
 * it if free (and clear). The paired accelerator "generation" flag at
 * +0x70 mirrors which state (claimed/free) is current.
 */
/* (re-ported mechanically: see IOATIR500GLContext_become_global_shared_Port.cpp) */


/*
 * purge_texture - CONFIRMED. Real body: bounds-checked texture lookup
 * (same client-handle table shape as delete_texture above), and if the
 * texture is currently marked resident (+0x48 != 0) calls the
 * accelerator's own real `deallocate_texture` (+0x524, already named
 * elsewhere in this project) then resets the texture's own per-face-mip
 * dirty/loaded-bits header (+0x14, six real UInt16 fields zeroed) and
 * unlinks it from whichever doubly-linked list it's currently on
 * (+0x24/+0x28 real prev/next pointers, self-linked to mark empty).
 */
/* (re-ported mechanically: see IOATIR500GLContext_purge_texture_Port.cpp) */


/*
 * scale_surface - CONFIRMED. Real body: forwards to the bound surface's
 * own `set_scaling`, packing the real scaling-parameters struct from
 * the caller's raw x/y-scale arguments. Requires a bound surface and
 * bit 0 of `param1` set (a real "scaling enabled" flag).
 */
/* (re-ported mechanically: see IOATIR500GLContext_scale_surface_Port.cpp) */


/*
 * reclaim_resources - CONFIRMED. Real body: resets the accelerator's
 * own GART/data-buffer pool size thresholds (+0x5c8/+0x5d8, real
 * literal 0x20000/0x10000) then walks this context's own pending
 * data-buffer list (+0xe8), moving every entry with fewer than 0x10
 * live buffers back onto the accelerator's own free list (+0x5cc head/
 * +0x5d0 tail/+0x5d4 count, the same real free-list shape this
 * project's own IOATIR500Accelerator_DataBufferPool.cpp already
 * established), releasing each entry's own backing descriptor (+0x10,
 * real vtable +0x18 release) along the way; anything over the 0x10
 * threshold instead goes straight to `freeOneDataBuffer`. Finally
 * drains the free list itself back down to the 0x10 threshold via
 * `freeOneDataBuffer` too.
 */
/* (re-ported mechanically: see IOATIR500GLContext_reclaim_resources_Port.cpp) */


/*
 * set_stereo - CONFIRMED, simple forward to
 * IOATIR500Accelerator::setup_stereo with its own two arguments
 * swapped (real decompile: `setup_stereo(accel, param2, param1)`).
 */
IOReturn IOATIR500GLContext::set_stereo(UInt32 param1, UInt32 param2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    IOATIR500Accelerator *accel = *reinterpret_cast<IOATIR500Accelerator **>(self + 0xc8);
    GLContext_mutex_lock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accel) + 0x840));
    IOReturn result = accel->setup_stereo(param2, param1);
    GLContext_mutex_unlock(*reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accel) + 0x840));
    return result;
}

/*
 * connectClient - CONFIRMED real behavior (kext offset 0x86d0, already
 * cited by this project's own header comment). Only permitted between
 * two contexts sharing the same real owning-task identity (+0x78);
 * releases this context's own previous client handle and takes a real
 * retained reference to the other context's handle instead. The real
 * decompile calls vtable+0x14 on the new handle right before storing
 * its pointer as this context's own live reference, immediately after
 * a vtable+0x18 release on the old one - `+0x18` is already this
 * project's own independently-confirmed `OSObject::release()` slot
 * elsewhere (issue #20), and `+0x14` sitting immediately before it,
 * called in the same acquire-a-live-reference role, is almost
 * certainly `OSObject::retain()` (the standard adjacent pair in
 * Apple's real vtable layout) - not independently re-confirmed via a
 * live read the way `release` was, but the standard, expected pairing.
 */
/* (re-ported mechanically: see IOATIR500GLContext_connectClient_Port.cpp) */


/*
 * get_surface_size - CONFIRMED. No bound surface -> real error
 * kIOReturnNotAttached-family (0xe00002bc). Real body reads the bound
 * surface's own +0xbd4/+0xbd8 real mip-tracking fields; if equal (a
 * real "single fixed size, compute this context's own current mip
 * level by repeated halving" case), starts from the surface's own
 * real base UInt16 width/height (at `*(surface+0xb70)+0x1c`/`+0x1e`)
 * and halves both `mipLevel` (this+0x29c) times, floor-clamped at 1;
 * otherwise reads four already-distinct real SInt16 fields directly
 * (+0xbd4/+0xbd6/+0xbd8/+0xbda). Real output order is NOT the same as
 * the internal compute order - transcribed exactly as decompiled.
 */
/* (re-ported mechanically: see IOATIR500GLContext_get_surface_size_Port.cpp) */


/*
 * get_surface_info - CONFIRMED. Real body: bounds-checked
 * find_surface_for_id lookup, then reports a real "surface config"
 * bitmask (+0xbe8) with real bits 0x100/0x200 folded in depending on
 * two real flag bits at +0xc18 (bit 3 -> 0x200, else bit 2 -> 0x100),
 * plus the same real "current vs. base size" pair get_surface_size
 * above already establishes (+0xbd4/+0xbd8 equal -> read from the
 * base UInt16 record at `*(surface+0xb70)+0x1c/+0x1e`, else real
 * SInt16 fields directly at +0xbd8/+0xbda).
 */
/* (re-ported mechanically: see IOATIR500GLContext_get_surface_info_Port.cpp) */


/*
 * get_config / get_status - CONFIRMED, transcribed faithfully
 * (preserving the real decompile's own control flow, including its
 * mid-loop early-exit jump, rather than restructuring it) since both
 * involve a genuine early-exit-into-a-second-loop shape that's easy to
 * get subtly wrong by "cleaning up". Both real bodies: if a surface is
 * bound and its own +0xa4 field exceeds 0xff, spin-wait on the
 * accelerator's own +0x80 ready flag (real vtable +0x548-adjacent
 * wait call - own identity NOT independently confirmed elsewhere in
 * this project, called via this project's own established raw-vtable
 * idiom). Then walks a real 23-entry (0..0x16) per-unit table rooted
 * at the bound surface's own +0xb8 field, stride 0x78, testing bit N
 * of this context's own +0x8c texture-unit-dirty mask for each; the
 * first dirty unit whose real vtable +0x540 "resolve" call returns 0
 * short-circuits the whole scan (get_config only - get_status instead
 * short-circuits by writing 0 to its own out-param and jumping to the
 * shared unlock tail). After the scan (or the short-circuit), a second
 * pass walks backwards from the scan's own stopping point calling a
 * real vtable +0x544 "commit" call for every unit that was dirty.
 */
/* (re-ported mechanically: see IOATIR500GLContext_get_config_Port.cpp) */


/*
 * get_status - CONFIRMED, same real shape as get_config immediately
 * above (a real 0x20000000 "already known" bit on the bound surface's
 * own +0xbf8 field gates whether the scan even runs at all here,
 * unlike get_config), same real wait/resolve/commit vtable slots.
 */
/* (re-ported mechanically: see IOATIR500GLContext_get_status_Port.cpp) */


/*
 * set_surface - CONFIRMED, transcribed faithfully. Real body: looks up
 * the target surface by ID (0 -> unbind), unlinks this context from
 * whatever surface it was previously bound to (real
 * remove_gl_context_from_list + prune_buffers pair), then either
 * clears the binding (unbind path) or negotiates a real per-format
 * "surface config" bitmask against the new surface's own +0xbe8 field
 * (three real cases: a fast-path direct mask merge when nothing else
 * currently touches the surface incompatibly, a real "requires
 * hyperz-state-agreement" vtable-gated reject at this context's own
 * +0x5ac, or unconditional acceptance), computes this context's own
 * real +0x8c render-target-config flags from the caller's mode bits,
 * commits via this context's own +0x5bc vtable call, links into the
 * new surface's context list, and finally invalidates the OLD bound
 * surface via this context's own +0x5a8 vtable call regardless of
 * which path was taken. This context's own +0x5ac/+0x5a8/+0x5bc vtable
 * slots are not independently named elsewhere in this project (this
 * class's OWN vtable, distinct from IOATIR500Accelerator's/
 * IOATIR500Surface's) - called via this project's established raw
 * vtable-cast idiom, flagged honestly rather than guessed at.
 */
/* (re-ported mechanically: see IOATIR500GLContext_set_surface_Port.cpp) */


/*
 * new_texture - CONFIRMED real dispatch shape (switch on the input
 * struct's own type-tag field, real cases 0/1/2/3/6/7 already
 * established by this project's own header comments for the sibling
 * `sIOGLNewTextureData` struct). Real decompile shows only 3 usable
 * parameters (Ghidra's own calling-convention-inference artifact
 * absorbed `this` as if it were the first typed argument, shifting
 * everything - the same category this project already documents
 * elsewhere, e.g. `load_texture`'s own note) - trusted mapping:
 * Ghidra's own param_1 is really `this`, param_2 is the real
 * `sIOGLNewTextureData*`, param_3 is the real
 * `sIOGLNewTextureReturnData*`. This class's own already-declared
 * trailing `UInt32 param3, UInt32 *param4` are never referenced inside
 * this function body at all - modeled as real, confirmed-unused
 * parameters, matching this project's own established precedent for
 * that exact situation elsewhere (e.g. `pageoff_dirty_texture`'s own
 * trailing `long` parameters).
 */
/* (re-ported mechanically: see IOATIR500GLContext_new_texture_Port.cpp) */

