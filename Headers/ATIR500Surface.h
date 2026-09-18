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
 * `getTargetAndMethodForIndex` (real kext offset `0x3ac80`) - flagged
 * here at issue #16 time as deliberately deferred, now RESOLVED (issue
 * #42 test-harness pass, see this class's own declaration below) - this
 * was a real, previously-uncaught gap: without it, and without the base
 * class's own `start()` setting up the real method-table pointer it
 * reads, this project's rebuilt kext had NO working external-method
 * dispatch for ANY of Surface's 19 real methods at all, despite every
 * one of those 19 methods already having a real, decompiled body -
 * confirmed by a full clean rebuild linking successfully (0 project-own
 * undefined symbols) with the dispatch function simply absent, since
 * nothing in the rebuilt kext's own code took its address without a
 * real method table to populate.
 * `invalidate` (real kext offset `0x3acb0`) - the OTHER method noted
 * here at issue #16 time - IS now declared as of issue #18, but on
 * `IOATIR500Surface` (the base), not here: every real call site reaches
 * it through a base-typed pointer/virtual dispatch, not a
 * subclass-typed one, so C++ requires the declaration live on the base
 * for those call sites to compile, even though the base's own copy of
 * this vtable slot is genuine placeholder content and only this
 * subclass provides a real override. See `IOATIR500Surface.h`'s own
 * updated note for the full account, and four more real subclass
 * overrides (`dealloc_surface`/`alloc_surface_buffer`/`prepare_vram`/
 * `complete_vram`) found and declared there the same way.
 */

#ifndef ATIR500SURFACE_H
#define ATIR500SURFACE_H

#include "IOATIR500Surface.h"

class ATIR500Surface : public IOATIR500Surface {
    OSDeclareDefaultStructors(ATIR500Surface)

public:
    /*
     * stop - CONFIRMED to exist (real mangled
     * __ZN14ATIR500Surface4stopEP9IOService, real addr 0x3b0c0) - found
     * while resolving issue #52 (a partial decompile of this function is
     * what independently confirmed `ATIRadeonX1000::scratchHeader`/
     * `pendingTimeStamp`, see `Headers/ATIRadeonX1000.h`). Own body
     * RESOLVED, issue #55 - see Sources/ATIR500Surface_Stop.cpp.
     */
    virtual void stop(IOService *provider) override;

    /*
     * start - RESOLVED (issue #58). Real addr 0x3d3f0. A real, thin
     * wrapper: takes the accelerator's own real commandLock, calls the
     * base class's own real `IOATIR500Surface::start` (via a real vtable
     * pointer in the raw decompile, `PTR_start_00048a20` - an ordinary
     * C++ `IOATIR500Surface::start(provider)` call here), and on success
     * zeroes 7 more real subclass-only fields plus sets a real "started"
     * flag (`+0xdb8`). See Sources/ATIR500Surface_Start.cpp.
     */
    virtual bool start(IOService *provider) override;

    /*
     * getTargetAndMethodForIndex - RESOLVED (issue #42 test-harness
     * pass): the real external-method dispatch function this file's own
     * top comment already flagged as a known, deliberately-deferred gap
     * (real addr 0x3ac80). Real body: `*target = this; if (selector >
     * 0x12) return 0; return selector*0x18 + this->methodTable;` -
     * exactly the same real shape as GL/2D/DVD's own dispatch functions,
     * confirmed valid for all 19 real selectors (0-18, matching Surface's
     * own real 19-method table). `methodTable` (Headers/IOATIR500Surface.h,
     * `this+0xd5c`) is set by the base class's own `start()` to the real
     * static table's absolute address - see
     * Sources/ATIR500Surface_ExternalMethods.cpp for both the dispatch
     * function and the real, byte-dumped table itself (real addr
     * 0x48d60, CONFIRMED via direct memory read - every one of the 19
     * real function-pointer entries resolves to this project's own
     * already-established real method, by real symbol name, not
     * guessed).
     */
    virtual IOExternalMethod *getTargetAndMethodForIndex(IOService **target, UInt32 selector);

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
     * getFramebufferIndex / alloc_overlay / setup_overlay - RESOLVED
     * (real linkage fix): all three are real member functions on THIS
     * class taking no explicit parameters (implicit `this` only) - real
     * mangled symbols confirmed via `nm`
     * (`__ZN14ATIR500Surface19getFramebufferIndexEv`/
     * `13alloc_overlayEv`/`13setup_overlayEv`). Previously declared in
     * `Sources/ATIR500Surface_ShapeSurface.cpp` as plain `extern "C"`
     * free functions taking an explicit surface pointer - a real linkage
     * bug (the true symbols are C++-mangled member functions, not plain
     * C names; an `extern "C"` declaration with no `asm()` alias would
     * never have linked against the real symbol) caught while resolving
     * an unrelated question (`ATIR500DVDContext::set_macrovision`'s own
     * call to this exact function). Own bodies RESOLVED, issue #48 - see
     * Sources/ATIR500Surface_Overlay2.cpp.
     */
    UInt32   getFramebufferIndex(void);
    UInt32   alloc_overlay(void);
    void     setup_overlay(void);

    /*
     * free_overlay - CONFIRMED to exist (real mangled
     * __ZN14ATIR500Surface12free_overlayEv, real addr 0x391a0), the real
     * inverse of `alloc_overlay` above - found while resolving issue #55
     * (`stop`'s own real call). Own body RESOLVED, issue #55 - see
     * Sources/ATIR500Surface_Stop.cpp: clears the overlay handle at
     * `this+0xd94` if set (without releasing it through a vtable call -
     * transcribed exactly as decompiled) and clears bit `0x2` of
     * `this+0xd70`, the exact inverse of `alloc_overlay`'s own real
     * `|= 2`.
     */
    void     free_overlay(void);

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
     * count/index at every real call site). Own body RESOLVED, issue
     * #38 - see Sources/ATIR500Surface_DecompressAndFlushDepthBuffer.cpp.
     */
    UInt32 decompress_and_flush_depth_buffer(ATIR500SurfaceBuffer *scratch, UInt32 param2, UInt32 *record);

    /*
     * load_3d_blit - CONFIRMED real name/signature (mangled
     * `__ZN14ATIR500Surface12load_3d_blitEPmP20ATIR500SurfaceBuffer`,
     * real addr 0x3d4c0), only real caller `decompress_and_flush_depth_
     * buffer` above. Own body RESOLVED, issue #47 - see
     * Sources/ATIR500Surface_Load3DBlit.cpp.
     * Real return value is the real BYTE pointer one past the last dword
     * this function wrote (`dest + 0x72` dwords, always) - the caller's
     * own `(end - record) >> 2` conversion already established this.
     */
    UInt32 *load_3d_blit(UInt32 *dest, ATIR500SurfaceBuffer *scratch);

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

    /*
     * FIXED (issue #1, first build attempt): these nine are all real
     * subclass overrides of base-declared virtuals (see
     * IOATIR500Surface.h's own notes on each - `invalidate`/
     * `dealloc_surface`/`alloc_surface_buffer`/`prepare_vram`/
     * `complete_vram`/`resetFullScreen`/`is_flip_allowed`/
     * `shape_surface`/`is_surface_size_supported`), but this class never
     * redeclared them - a prior session's reasoning ("every real call
     * site reaches it through a base-typed pointer, so C++ doesn't need
     * the subclass declaration") is true for CALL sites, but doesn't
     * apply to DEFINING the override's own body: an out-of-line
     * `ATIR500Surface::method() {...}` definition requires `method` to
     * be declared in `ATIR500Surface`'s own class body regardless of how
     * callers reach it - real compile errors ("no such member function
     * declared in class") on every one of these until redeclared here.
     * Signatures copied exactly from the base's own declarations.
     */
    virtual void   invalidate();
    virtual UInt32 dealloc_surface(UInt32 surfaceIndex);
    virtual UInt32 alloc_surface_buffer(ATIR500SurfaceBuffer *buffer);
    virtual UInt32 prepare_vram(ATIR500SurfaceBuffer *buffer);
    virtual UInt32 complete_vram(ATIR500SurfaceBuffer *buffer);
    virtual void   resetFullScreen();
    virtual SInt32 is_flip_allowed();
    virtual void   shape_surface();
    virtual SInt32 is_surface_size_supported(SInt16 width, SInt16 height);

    /*
     * submit_flip_buffer - real subclass override, real addr 0x3e5c0
     * (issue #1, get-it-linking pass - see IOATIR500Surface.h's own
     * updated note: the base's own copy is a confirmed genuine
     * placeholder, pure virtual). Own body: see
     * Sources/ATIR500Surface_SubmitFlipBuffer.cpp.
     */
    virtual void submit_flip_buffer(UInt32 id, IOATIR500GLContext *context, UInt32 flag);
};

#endif /* ATIR500SURFACE_H */
