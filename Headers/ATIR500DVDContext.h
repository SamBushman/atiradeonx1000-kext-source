/*
 * ATIR500DVDContext.h
 *
 * The DVD/video subclass adding selectors 10-21 on top of
 * IOATIR500DVDContext's base 0-9 - the richest extra-selector block of
 * any context class, and the one most directly relevant to this
 * project's H.264 GPU-decode goal (owns doIDCT).
 */

#ifndef ATIR500DVDCONTEXT_H
#define ATIR500DVDCONTEXT_H

#include "IOATIR500DVDContext.h"
#include "ATIRadeonX1000Registers.h"

class ATIR500DVDContext : public IOATIR500DVDContext {
    OSDeclareDefaultStructors(ATIR500DVDContext)

public:
    /*
     * Virtual slots in the stock vtable's order (Ledger/kext_ppc_vtables.txt): start +0x348, stop +0x34c,
     * clientMemoryForType +0x580, getTargetAndMethodForIndex +0x594, invalidate +0x5a4, update_surface +0x5a8,
     * (setCompatibleSurfaceMode +0x5ac is the base class's), submit_context_buffer +0x5b0,
     * process_command_buffer +0x5b4, discard_command_buffer +0x5b8.
     */
    virtual bool     start(IOService *provider) override;                                     /* +0x348, real addr 0x34860 */
    virtual void     stop(IOService *provider) override;                                      /* +0x34c, real addr 0x34ac0 */
    virtual IOReturn clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) override; /* +0x580, real addr 0x352a0 */
    virtual IOExternalMethod *getTargetAndMethodForIndex(IOService **target, UInt32 selector); /* +0x594, real addr 0x33bf0 */
    virtual void     invalidate() override;                                                   /* +0x5a4, real addr 0x34100 */
    virtual void     update_surface() override;                                               /* +0x5a8, real addr 0x34060 */
    virtual void     submit_context_buffer() override;                                        /* +0x5b0, real addr 0x34440 */
    virtual IOReturn process_command_buffer(VendorCommandDescriptor *descriptor) override;    /* +0x5b4, real addr 0x357c0 */
    virtual void     discard_command_buffer() override;                                        /* +0x5b8, real addr 0x33c30 */

    void     build_scissor(void);                                                             /* real addr 0x34020 */
    IOReturn finish(void);                                                                    /* real addr 0x340a0: shadows the base class's finish() */

    IOReturn show_buffer(int bufferIndex, int param2); /* 10, CONFIRMED body (stage8): thin lock wrapper delegating to ATIR500Surface::showbuffer, which is a REAL EMPTY NO-OP in this exact kext build */
    IOReturn dvd_setup_overlay(int x, int y, int w, int h, int param5); /* 11, CONFIRMED body (stage8): delegates to ATIR500Surface::dvd_setup_overlay - real, stores geometry into the surface's shared this+0x94/0x96/0x98/0x9a fields plus a dirty flag at +0xd94 */
    IOReturn dvd_enable_overlay(int enable); /* 12, CONFIRMED body (stage8): delegates to ATIR500Surface::enable_overlay/disable_overlay, BOTH real empty no-ops in this exact kext build */
    IOReturn read_regs(UInt32 *offsets, UInt32 *outValues, UInt32 byteCount, UInt32 *inOutCount); /* 13, CONFIRMED body: identical masking/validation shape to the 2D context's read_regs - see Sources/ATIR500DVDContext_RawRegs.cpp */
    IOReturn write_regs(UInt32 offset, UInt32 value); /* 14, CONFIRMED body: this DVD variant's real decompiled signature takes a single scalar (offset, value) pair, not an array like the 2D context's write_regs */
    IOReturn dvd_setup_subpicture(int param1, int param2, int param3, int param4); /* REAL SIGNATURE CORRECTED (issue #42 pass): the shipped symbol has FOUR ints and the dispatch table says 4 scalars; the 4th is passed straight through to ATIR500Surface::dvd_setup_subpicture (also 4 ints, all unused). */ /* /* 15, CONFIRMED body (stage8): delegates to ATIR500Surface::dvd_setup_subpicture, a REAL EMPTY NO-OP in this exact kext build */
    IOReturn set_macrovision(UInt32 attribute, UInt32 value); /* 16, RESOLVED - real body confirms this project's own prior inference (Sources/ATIR500DVDContext_SetMacrovision.cpp), no longer just inferred from the 2D context's own version. Real wire-shape evidence (VA bundle, offset 0x52b8) shows the client actually sends 2 real scalar inputs, not 1 - the real decompiled body itself only ever reads the first (`enable`), matching this project's own well-established "argument-dropped" decompiler artifact (see e.g. GL's finish()/wait_for_stamp() and page_off_texture) rather than being a signature error: the C++ signature here correctly reflects what the function actually uses, the wire's 2nd scalar is real but silently unused by the compiled body. */
    IOReturn dvd_enable_deint(int mode); /* 17, CONFIRMED body (stage8): delegates to ATIR500Surface::enable_deint - real, stores the mode into the surface's +0xdac field; nothing observed reading it back anywhere this project decompiled */

    /*
     * doIDCT - CONFIRMED, fully decoded (real kext offset 0x35540). THE
     * real external entry point for hardware-accelerated IDCT - directly
     * relevant to this project's H.264 goal. Full reconstruction in
     * Sources/ATIR500DVDContext_IDCT.cpp.
     */
    IOReturn doIDCT(sATIDVDIDCTInfo *info, UInt32 infoSize);   /* 18 */
    IOReturn wait_for_stamps(UInt32 waitMain, UInt32 waitIDCT);                /* 19, CONFIRMED body (stage5): calls two distinct vtable methods (0x5fc/0x558) depending on which flags are set - mirrors the GL side's fence pair, confirming the IDCT path uses the same stamp architecture */
    IOReturn check_stamps(UInt32 checkMain, UInt32 checkIDCT, UInt32 *outBothDone); /* 20, CONFIRMED body (stage5): non-blocking poll counterpart to wait_for_stamps */
    IOReturn setup_buffers(UInt32 topHeight, UInt32 leftWidth, UInt32 bottomHeight, UInt32 rightWidth, UInt32 controlFlags); /* 21, CONFIRMED body (stage5): real per-plane geometry setup for the IDCT working surface, writes a control dword combining caller flags with a fixed 0x20000002 base */

    /*
     * map_transfer_to_GART - FIXED (issue #1, get-it-linking pass): this
     * redeclaration was a real header bug, not a genuine gap. A direct
     * Ghidra symbol-table check (`__ZN17ATIR500DVDContext20map_transfer_
     * to_GARTEP20VendorTransferBuffer`) found NO such mangled symbol
     * anywhere in the real binary - this subclass never actually
     * overrides the method at all; it simply inherits the base
     * `IOATIR500DVDContext::map_transfer_to_GART` unchanged (already
     * fully implemented, see Sources/MapTransferToGART_
     * RemainingContexts.cpp). Removed the phantom redeclaration, which
     * was creating an undefined-symbol link error for a function the
     * real binary never actually defines.
     */

    /*
     * submit_context_buffer - CONFIRMED real name/signature (real
     * mangled symbol __ZN17ATIR500DVDContext21submit_context_bufferEv).
     * Own body NOT independently decompiled this pass.
     *
     * allocAllContextBuffers - REAL-CLASS-PLACEMENT FIXED, issue #33
     * sweep: this was wrongly declared here - its own real mangled
     * symbol (__ZN19IOATIR500DVDContext22allocAllContextBuffersEm) is a
     * member of the BASE class, `IOATIR500DVDContext`, not this
     * subclass. Moved to Headers/IOATIR500DVDContext.h; own body
     * RESOLVED there, issue #33.
     */
protected:
    /*
     * FIXED (issue #56): `idctInfo` was declared as its OWN data member
     * here, which is wrong - it is not a distinct field, it is the SAME
     * real storage as the base class's own `boundSurface` (both are
     * `*(int*)(this+0xf8)` in the real decompile; this project already
     * confirmed the two are literally the same object, just viewed
     * through two different pointer types depending on what the
     * surrounding code is doing - see MapTransferToGART_
     * RemainingContexts.cpp's own note on this same ambiguity).
     * Declaring it as a second field would have silently added 4 bytes
     * of nonexistent storage after the real object and left boundSurface
     * and idctInfo permanently out of sync. Replaced with an accessor
     * that reinterprets the existing `boundSurface` storage instead -
     * not accessed by name anywhere in this project's own `.cpp` files
     * today (grep-confirmed), so this doesn't change any call site.
     */
    sATIDVDIDCTInfo *idctInfo() const { return reinterpret_cast<sATIDVDIDCTInfo *>(boundSurface); }
};

#endif /* ATIR500DVDCONTEXT_H */
