/*
 * ATIR500Surface.h
 *
 * RESOLVED (issue #16): the real concrete subclass of `IOATIR500Surface`,
 * matching the same real Darwin/IOKit base/subclass pattern already
 * established for the other three context classes
 * (`IOATIR500GLContext`/`ATIR500GLContext`,
 * `IOATIR500DVDContext`/`ATIR500DVDContext`, and the 2D equivalent) -
 * Surface was the one outlier, everything previously declared on a
 * single unified `IOATIR500Surface`.
 *
 * Real split determined the same way this project determines every
 * other base/subclass boundary: each already-declared method's own real
 * mangled symbol name in the kext's symbol table directly names its real
 * receiver class - not guessed, not inferred from role. Checked EVERY
 * method this project had declared on the old unified class; only the
 * eight below are real `ATIR500Surface::` (subclass) receivers -
 * everything else this project had already declared stays correctly on
 * `IOATIR500Surface` (the base).
 *
 * Real, previously-unknown finding from this same symbol sweep: the
 * whole real overlay/subpicture/deinterlace family (`disable_overlay`,
 * `enable_overlay`, `showbuffer`, `dvd_setup_subpicture`,
 * `dvd_setup_overlay`, `enable_deint`) is on the SUBCLASS, not the base
 * as this project's earlier, unified-class model had them - this project
 * already had every one of these six real bodies fully transcribed
 * (`Sources/ATIR500Surface_Overlay.cpp`), just filed under the wrong
 * class qualifier until now. `resolve_fsaa_buffer` (issue #13) and
 * `decompress_and_flush_depth_buffer` were already independently
 * confirmed subclass members before this issue - now formally reflected
 * in the class hierarchy instead of living as an inline caveat on the
 * base class.
 *
 * Also confirmed on the subclass from the same symbol sweep, but
 * deliberately NOT added below since this project never declared or
 * decompiled either before this issue (real scope of issue #16 is
 * re-homing already-declared members correctly, not new decompilation):
 * `getTargetAndMethodForIndex` (real kext offset `0x3ac80` - the
 * external-method dispatch function itself, matching the same real
 * subclass-owns-dispatch pattern GL/DVD/2D already established) and
 * `invalidate` (real kext offset `0x3acb0` - the same real per-context
 * dirty-bit override every sibling class already has, per `invalidate`'s
 * own existing header note on `ATIR500GLContext.h`). Both real addresses
 * are recorded here for whoever picks up a future decompile pass.
 */

#ifndef ATIR500SURFACE_H
#define ATIR500SURFACE_H

#include "IOATIR500Surface.h"

class ATIR500Surface : public IOATIR500Surface {
    OSDeclareDefaultStructors(ATIR500Surface)

public:
    /*
     * ---- Real overlay/subpicture/deinterlace family - RE-HOMED, issue
     * #16. Bodies unchanged (still fully transcribed, CONFIRMED), moved
     * here from the base class purely because that's where their real
     * mangled symbols say they live - see
     * Sources/ATIR500Surface_Overlay.cpp for all six bodies and this
     * project's own significant "hardware overlay path is mostly
     * vestigial" finding (three of five are real empty no-ops).
     */
    void     disable_overlay(void);   /* CONFIRMED: real empty no-op */
    void     enable_overlay(void);    /* CONFIRMED: real empty no-op */
    void     showbuffer(UInt32 bufferIndex, UInt32 param2); /* CONFIRMED: real empty no-op */
    void     dvd_setup_subpicture(UInt32 param1, UInt32 param2, UInt32 param3); /* CONFIRMED: real empty no-op */
    void     dvd_setup_overlay(UInt32 x, UInt32 y, UInt32 w, UInt32 h); /* CONFIRMED: the one real, non-stub member of this family */
    void     enable_deint(UInt32 mode); /* CONFIRMED: real, stores mode into this+0xdac */

    /*
     * resolve_fsaa_buffer - RESOLVED (issue #13), RE-HOMED (issue #16).
     * Full real body in Sources/ATIR500Surface_ResolveFSAABuffer.cpp -
     * see that file for the complete transcription and header comment.
     */
    void    *resolve_fsaa_buffer(UInt32 surfaceIndex, UInt32 formatCode, void *paramBlock,
                                  bool clearFlag, UInt32 param5, UInt32 param6, UInt32 param7,
                                  UInt32 param8);

    /*
     * decompress_and_flush_depth_buffer - CONFIRMED real name/signature/
     * receiver class, RE-HOMED (issue #16). Real call shape:
     * `decompress_and_flush_depth_buffer(surface, surfaceBufferScratch,
     * 0, record)` returning a real UInt32 (used as a record-dword
     * count/index at every real call site). Own body NOT independently
     * decompiled - same standing gap as before this issue, only the
     * class placement changed.
     */
    UInt32 decompress_and_flush_depth_buffer(ATIR500SurfaceBuffer *scratch, UInt32 param2, UInt32 *record);

    /*
     * back_resolve_fsaa_buffer - RESOLVED (issue #17). Full real body in
     * Sources/ATIR500Surface_BackResolveFSAABuffer.cpp - see that file for
     * the complete transcription and header comment. Real signature: the
     * first parameter is real but genuinely unused; the second indexes
     * `surfaceBuffersByFormat`, matching `resolve_fsaa_buffer`'s own
     * `formatCode` parameter; the third is the same real output record
     * pointer convention `resolve_fsaa_buffer` uses.
     */
    void *back_resolve_fsaa_buffer(UInt32 unusedParam1, UInt32 formatCode, void *paramBlock);
};

#endif /* ATIR500SURFACE_H */
