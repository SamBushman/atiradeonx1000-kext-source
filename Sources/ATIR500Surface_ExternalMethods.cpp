/*
 * ATIR500Surface_ExternalMethods.cpp
 *
 * RESOLVED (issue #42 test-harness pass): the real, static external-method
 * table for the Surface context - transcribed dword-for-dword from a raw
 * memory dump of the shipped kext (real absolute address 0x48d60, the
 * literal value `ATIR500Surface::start`'s own `lis r2,0x5 / subi
 * r2,r2,0x72a0` instruction pair materializes and stores into this
 * object's own `this+0xd5c` field - see Headers/IOATIR500Surface.h's
 * `methodTable` comment), plus the real dispatch function
 * `ATIR500Surface::getTargetAndMethodForIndex` that reads it.
 *
 * This is the SAME real table shape this project already established for
 * GL (Sources/IOATIR500GLContext_ExternalMethods.cpp) - see that file's
 * own header comment for the full VendorExternalMethod struct rationale
 * and the OSMemberFunctionCast requirement. Unlike GL, Surface has no
 * split "regular table + one extended selector" - all 19 real selectors
 * (0-18) live in this one contiguous table.
 *
 * CONFIRMED: every one of the 19 real function-pointer entries below was
 * resolved (via a live Ghidra memory read cross-referenced against the
 * program's own function/symbol table) to this project's own
 * already-established, already-implemented real method, by real symbol
 * name - not guessed, not assumed from selector position. This
 * independently confirms every selector<->method mapping this project's
 * test harness (Tests/test_surface_context.c) had been using is correct.
 *
 * The trailing three dwords per entry (count0/count1/count2) are real,
 * correctly-read raw bytes - see Headers/ATIRadeonX1000Types.h's own
 * `VendorExternalMethod` comment for why their semantic role (which one
 * is a real scalar/structure input vs. output count) is NOT assumed
 * positionally without real client call-site cross-reference, per this
 * project's own hard-won lesson from the GL wire-shape investigation
 * this same pass.
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIR500Surface.h"
#include <libkern/c++/OSMetaClass.h>

/*
 * Real table, real addr 0x48d60. `target` is 0 in the real static
 * template (patched live to the real target object pointer by
 * getTargetAndMethodForIndex at call time), matching the same real
 * pattern GL's own table uses.
 */
extern const VendorExternalMethod kSurfaceMethods[19] asm("__ZZN16IOATIR500Surface5startEP9IOServiceE11methodDescs");   /* stock: the function-local static `methodDescs` of start(IOService*) */
extern const VendorExternalMethod kSurfaceMethods[19] = {
    /*  0 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_read_lock_options),   2, 1, 0xffffffff },
    /*  1 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_read_unlock_options),  0, 1, 0 },
    /*  2 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::get_state),                    0, 0, 1 },
    /*  3 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_write_lock_options),   2, 1, 0xffffffff },
    /*  4 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_write_unlock_options), 0, 1, 0 },
    /*  5 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_read),                 3, 0xffffffff, 0 },
    /*  6 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::set_shape_backing),             4, 4, 0xffffffff },
    /*  7 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::set_id_mode),                  0, 2, 0 },
    /*  8 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::set_scale),                    4, 1, 0xffffffff },
    /*  9 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::set_shape),                    4, 2, 0xffffffff },
    /* 10 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_flush),                0, 2, 0 },
    /* 11 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_query_lock),           0, 0, 0 },
    /* 12 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_read_lock),            2, 0, 0xffffffff },
    /* 13 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_read_unlock),          0, 0, 0 },
    /* 14 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_write_lock),           2, 0, 0xffffffff },
    /* 15 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_write_unlock),         0, 0, 0 },
    /* 16 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_control),              0, 2, 1 },
    /* 17 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::set_shape_backing_length),     4, 5, 0xffffffff },
    /* 18 */ { 0, 0xffff, OSMemberFunctionCast(void *, static_cast<IOATIR500Surface *>(0), &IOATIR500Surface::surface_control),              0, 2, 1 }, /* CONFIRMED real, deliberate alias of selector 16 - same real function address in the raw dump, not two implementations (matches this project's own already-declared surface_control_alias, which shares surface_control's own real body) */
};

/*
 * getTargetAndMethodForIndex - CONFIRMED, transcribed directly from the
 * real decompile (kext offset 0x3ac80):
 *
 *     int ATIR500Surface::getTargetAndMethodForIndex(IOService **target, unsigned long selector) {
 *         *target = (IOService *)this;
 *         if (selector > 0x12) return 0;
 *         return selector * 0x18 + *(int *)(this + 0xd5c);
 *     }
 *
 * Reconstructed below operating on the real named table instead of raw
 * offsets, using this project's own already-established real base-class-
 * compatible return type correction (see GL's own getTargetAndMethodForIndex
 * for the full rationale - the real override must return the same real
 * `IOExternalMethod*`-shaped pointer IOUserClient's own base declaration
 * uses, not this project's own richer `VendorExternalMethod*`).
 */
/* (re-ported mechanically: see ATIR500Surface_getTargetAndMethodForIndex_Port.cpp) */

