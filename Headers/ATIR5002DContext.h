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
};

#endif /* ATIR5002DCONTEXT_H */
