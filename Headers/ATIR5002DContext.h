/*
 * ATIR5002DContext.h
 *
 * The 2D subclass adding selectors 16-18 (the raw register-access family)
 * on top of IOATIR5002DContext's base 0-15. Real class split confirmed by
 * the real decompiled signatures: read_regs/write_regs/write_2_regs are
 * `ATIR5002DContext::`, not `IOATIR5002DContext::` - the same subclassing
 * pattern already established for the GL context.
 *
 * Confidence: CONFIRMED bodies for all three (directly decompiled this
 * session - see stage5-iouserclient-external-method-api-complete.md).
 * This is the one place in the whole class hierarchy where a raw,
 * kernel-validated register read/write is exposed to userspace.
 */

#ifndef ATIR5002DCONTEXT_H
#define ATIR5002DCONTEXT_H

#include "IOATIR5002DContext.h"
#include "ATIRadeonX1000Registers.h"

class ATIR5002DContext : public IOATIR5002DContext {
    OSDeclareDefaultStructors(ATIR5002DContext)

public:
    /*
     * read_regs - CONFIRMED, fully decoded (real kext offset 0x33660).
     * Real behavior, transcribed faithfully below: validates the caller's
     * claimed transfer size against the actual requested size AND
     * 4-byte alignment, checks the device-active flag, then reads each
     * requested offset (masked to REGISTER_ACCESS_WINDOW_MASK) from the
     * accelerator's real MMIO base, byte-swapping from the card's
     * little-endian register layout.
     */
    IOReturn read_regs(UInt32 *offsets, UInt32 *outValues, UInt32 requestedByteCount, UInt32 *actualByteCount);

    /*
     * write_regs - CONFIRMED, fully decoded (real kext offset 0x33740).
     * Real behavior: validates 8-byte (offset,value pair) alignment,
     * checks the device-active flag, writes each (offset, value) pair
     * with the same REGISTER_ACCESS_WINDOW_MASK masking and byte-swap as
     * read_regs.
     */
    IOReturn write_regs(UInt32 *offsetValuePairs, UInt32 pairByteCount);

    /*
     * write_2_regs - CONFIRMED, fully decoded (real kext offset 0x325d0).
     * Real behavior: identical validation to write_regs, but writes TWO
     * independently-addressed registers per iteration from a flat value
     * array - a real, deliberate batch-write variant.
     */
    IOReturn write_2_regs(UInt32 offset1, UInt32 offset2, UInt32 *values, UInt32 byteCount);

    /*
     * process_command_buffer - RESOLVED (issue #7), fully transcribed
     * from a complete real decompile (kext offset 0x326d0). The 2D
     * context's own embedded command-buffer opcode language - same
     * underlying mechanism as ATIR500GLContext's (top-byte opcode
     * dispatch over a `this+0xac+0x1c`-based record stream, self-
     * consuming low-24-bit distance fields, `0x80000000`-sentinel exit
     * write), but a real, distinct, much smaller opcode set (real
     * confirmed range 0x2-0xe, 0x10-0x13). See
     * Sources/ATIR5002DContext_ProcessCommandBuffer.cpp.
     *
     * Real, notable findings:
     *   - `this+200` (0xc8) carries the SAME real "pending write batch"
     *     dirty-bit mechanism (its own +0x1c, bit 0) that GL's
     *     `invalidate()`/`submit_context_buffer` use on `this+0x108` -
     *     same real idiom, different per-class field offset.
     *   - `this+0x88` (`sharedAllocator`, already declared on
     *     IOATIR5002DContext) owns the real texture-lookup-by-index
     *     table this function bounds-checks against
     *     (`sharedAllocator+0x10`/`+0x14`) - the same real layout this
     *     project already found on `IOATIR500Shared` instances via
     *     DVD's own `this+0x84` (issue #7's DVD skeleton pass) and
     *     GL's texture/transfer lists - now confirmed from a THIRD
     *     independent context class.
     *   - Real texture-bind opcodes (0x3/0x4, 0x7/0x8) splice into the
     *     SAME two real accelerator-level lists (`+0x600`/`+0x5dc` and
     *     `+0x6d0`/`+0x69c`) this project already fully reconstructed
     *     for GL (issue #5) - directly reused understanding, not
     *     re-derived from scratch.
     *   - `FUN_000334cc` is the SAME real "ensure GART-mapped" pattern
     *     as GL's `FUN_0002a864` and DVD's `FUN_0003913c` - a real,
     *     per-class-compiled instance of the identical idiom, not
     *     independently decompiled this pass.
     */
    IOReturn process_command_buffer(VendorCommandDescriptor *descriptor);

    /*
     * alloc_and_load_image - CONFIRMED real name/signature (real mangled
     * symbol __ZN16ATIR5002DContext20alloc_and_load_imageEP19VendorTextureBuffer,
     * kext offset 0x31b70), the 2D context's own analog of
     * ATIR500GLContext::alloc_and_load_texture (issue #5) - found this
     * pass as a real call site in process_command_buffer. Own body NOT
     * independently decompiled this pass.
     */
    void alloc_and_load_image(VendorTextureBuffer *texture);
};

#endif /* ATIR5002DCONTEXT_H */
