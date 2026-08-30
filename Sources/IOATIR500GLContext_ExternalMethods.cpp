/*
 * IOATIR500GLContext_ExternalMethods.cpp
 *
 * The real, static external-method table for the GL context - transcribed
 * dword-for-dword from a raw memory dump of the shipped kext
 * (IOATIR500GLContext::start(IOService*)::methodDescs, kext offset
 * 0x47618, and ATIR500GLContext::start(IOService*)::methodDescs, kext
 * offset 0x49e88, for the special selector-20 entry). See
 * Headers/ATIRadeonX1000Types.h for the VendorExternalMethod struct this
 * is built from, and stage5-iouserclient-external-method-api-complete.md
 * for the dump this was read from.
 *
 * CONFIDENCE: CONFIRMED. Every non-zero, non-0xffff dword below is a
 * literal value read directly from the real binary - this file is a
 * transcription, not a reconstruction. The `target` field of every entry
 * is 0 in the real static template (patched live to the real object
 * pointer by getTargetAndMethodForIndex at call time - see
 * IOATIR500GLContext.h).
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIR500GLContext.h"

/*
 * The 20-entry regular table (selectors 0-19), base class
 * IOATIR500GLContext. Real kext address: 0x47618. External linkage
 * (not `static`) so IOATIR500GLContext::start (Sources/
 * IOATIR500GLContext_Start.cpp) can point regularMethodTable at it
 * directly, matching the real decompile.
 */
const VendorExternalMethod kGLRegularMethods[20] = {
    /*  0 */ { 0, 0xffff, (void *)&IOATIR500GLContext::set_surface,                 4, 4, 0 },
    /*  1 */ { 0, 0xffff, (void *)&IOATIR500GLContext::set_swap_rect,               4, 4, 0 },
    /*  2 */ { 0, 0xffff, (void *)&IOATIR500GLContext::set_swap_interval,           4, 2, 0 },
    /*  3 */ { 0, 0xffff, (void *)&IOATIR500GLContext::get_config,                  0, 0, 3 },
    /*  4 */ { 0, 0xffff, (void *)&IOATIR500GLContext::get_status,                  0, 0, 1 },
    /*  5 */ { 0, 0xffff, (void *)&IOATIR500GLContext::get_surface_size,            0, 0, 4 },
    /*  6 */ { 0, 0xffff, (void *)&IOATIR500GLContext::get_surface_info,            0, 1, 3 },
    /*  7 */ { 0, 0xffff, (void *)&IOATIR500GLContext::read_buffer,                 3, 0xffffffff, 0 },
    /*  8 */ { 0, 0xffff, (void *)&IOATIR500GLContext::finish,                      4, 0, 0 },
    /*  9 */ { 0, 0xffff, (void *)&IOATIR500GLContext::wait_for_stamp,              4, 1, 0 }, /* CONFIRMED == the fence-wait selector found client-side in stage3-fence-mechanism.md */
    /* 10 */ { 0, 0xffff, (void *)&IOATIR500GLContext::new_texture,                 3, 0xffffffff, 0xffffffff },
    /* 11 */ { 0, 0xffff, (void *)&IOATIR500GLContext::delete_texture,              4, 1, 0 },
    /* 12 */ { 0, 0xffff, (void *)&IOATIR500GLContext::become_global_shared,        4, 1, 0 },
    /* 13 */ { 0, 0xffff, (void *)&IOATIR500GLContext::page_off_texture,            4, 2, 0 },
    /* 14 */ { 0, 0xffff, (void *)&IOATIR500GLContext::scale_surface,               4, 3, 0 },
    /* 15 */ { 0, 0xffff, (void *)&IOATIR500GLContext::purge_texture,               4, 1, 0 },
    /* 16 */ { 0, 0xffff, (void *)&IOATIR500GLContext::set_surface_volatile_state,  4, 1, 0 },
    /* 17 */ { 0, 0xffff, (void *)&IOATIR500GLContext::reclaim_resources,           4, 0, 0 },
    /* 18 */ { 0, 0xffff, (void *)&IOATIR500GLContext::get_data_buffer,             0, 0, 2 },
    /* 19 */ { 0, 0xffff, (void *)&IOATIR500GLContext::set_stereo,                  4, 2, 0 },
};

/*
 * The special, singular 21st method (selector 20) - a distinct, one-entry
 * table on the SUBCLASS (ATIR500GLContext), reached via
 * getTargetAndMethodForIndex's own hardcoded `selector == 20` special case
 * rather than being indexed into kGLRegularMethods. Real kext address:
 * 0x49e88. CONFIRMED to be get_hw_info, NOT a "submit command buffer"
 * trap as originally guessed when this table's existence was first
 * inferred from the dispatch structure - see
 * stage5-iouserclient-external-method-api-complete.md's "negative result"
 * discussion for why that matters (there is no explicit submit/flush
 * external method anywhere in this driver; ring submission is a pure
 * shared-memory write-pointer update).
 */
static const VendorExternalMethod kGLSpecialMethod20 = {
    0, 0xffff, (void *)&ATIR500GLContext::get_hw_info, 0, 0, 5
};

/*
 * getTargetAndMethodForIndex - CONFIRMED, transcribed directly from the
 * real decompile (kext offset 0x26db0):
 *
 *     int ATIR500GLContext::getTargetAndMethodForIndex(IOService **target, unsigned long selector) {
 *         *target = (IOService *)this;
 *         if (selector < 0x14) return selector * 0x18 + *(int *)(this + 0x2a0);
 *         if (selector != 0x14) return 0;
 *         return *(int *)(this + 0x360);
 *     }
 *
 * Reconstructed below operating on the real named table instead of raw
 * offsets.
 */
const VendorExternalMethod *ATIR500GLContext::getTargetAndMethodForIndex(IOService **target, UInt32 selector) {
    *target = this;
    if (selector < 20) {
        return &kGLRegularMethods[selector];
    }
    if (selector != 20) {
        return nullptr;
    }
    return &kGLSpecialMethod20;
}
