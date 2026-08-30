/*
 * ATIR5002DContext_RawRegs.cpp
 *
 * Faithful reconstruction of read_regs/write_regs/write_2_regs - CONFIRMED
 * directly from Ghidra decompilation this session (real kext offsets
 * 0x33660/0x33740/0x325d0). These are the one place in this driver's
 * entire external API where userspace gets kernel-validated, but genuinely
 * raw, MMIO access - see Headers/ATIRadeonX1000Registers.h for the
 * REGISTER_ACCESS_WINDOW_MASK constant every one of these masks against,
 * and the honest note there about how little of the confirmed register
 * map (mostly 0x2000-0x5000) is actually reachable through this narrow
 * 0x0-0x1ffc window.
 */

#include "../Headers/ATIR5002DContext.h"

/* Real byte-swap helper - CONFIRMED shape (`b3<<24|b2<<16|b1<<8|b0`-style
 * reconstruction in both read_regs and write_regs) - the card's registers
 * are little-endian, the PowerPC kext is big-endian. */
static inline UInt32 SwapLE32(UInt32 v) {
    return ((v & 0x000000ffu) << 24) | ((v & 0x0000ff00u) << 8) |
           ((v & 0x00ff0000u) >> 8)  | ((v & 0xff000000u) >> 24);
}

IOReturn ATIR5002DContext::read_regs(UInt32 *offsets, UInt32 *outValues,
                                      UInt32 requestedByteCount, UInt32 *actualByteCount) {
    /* CONFIRMED: real caller-size-vs-actual-size validation, plus a real
     * 4-byte-alignment check, BEFORE the lock is even taken. */
    if (*actualByteCount != requestedByteCount || (*actualByteCount & 3) != 0) {
        return kIOReturnBadArgument; /* real value 0xe00002c2 */
    }

    UInt8 *mmioBase = static_cast<UInt8 *>(this->accelerator ? *reinterpret_cast<void **>(
        reinterpret_cast<UInt8 *>(this->accelerator) + 0x860) : nullptr);

    /* lock(accelerator) - CONFIRMED bracketing pattern, real lock/unlock
     * function names UNKNOWN (referenced only as FUN_xxxx in the
     * decompile). */

    if (!*reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(this->accelerator) + 0x80)) {
        /* unlock(accelerator) */
        return kIOReturnNotOpen; /* real value 0xe00002d8 */
    }

    UInt32 count = *actualByteCount >> 2;
    for (UInt32 i = 0; i < count; ++i) {
        UInt8 *reg = mmioBase + (offsets[i] & REGISTER_ACCESS_WINDOW_MASK);
        outValues[i] = SwapLE32(*reinterpret_cast<UInt32 *>(reg));
    }

    /* unlock(accelerator) */
    return kIOReturnSuccess;
}

IOReturn ATIR5002DContext::write_regs(UInt32 *offsetValuePairs, UInt32 pairByteCount) {
    /* CONFIRMED: real 8-byte (one offset dword + one value dword per
     * pair) alignment check. */
    if ((pairByteCount & 7) != 0) {
        return kIOReturnBadArgument;
    }

    UInt8 *mmioBase = static_cast<UInt8 *>(*reinterpret_cast<void **>(
        reinterpret_cast<UInt8 *>(this->accelerator) + 0x860));

    if (!*reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(this->accelerator) + 0x80)) {
        return kIOReturnNotOpen;
    }

    UInt32 pairCount = pairByteCount >> 3;
    for (UInt32 i = 0; i < pairCount; ++i) {
        UInt32 offset = offsetValuePairs[i * 2 + 0];
        UInt32 value  = offsetValuePairs[i * 2 + 1];
        UInt8 *reg = mmioBase + (offset & REGISTER_ACCESS_WINDOW_MASK);
        *reinterpret_cast<UInt32 *>(reg) = SwapLE32(value);
    }

    return kIOReturnSuccess;
}

IOReturn ATIR5002DContext::write_2_regs(UInt32 offset1, UInt32 offset2, UInt32 *values, UInt32 byteCount) {
    /* CONFIRMED: same 8-byte alignment check as write_regs, but here each
     * "pair" of dwords in `values` is written to the SAME two fixed
     * offsets (offset1, offset2) every iteration - a real batch-write
     * variant, not a per-pair-addressed write like write_regs. */
    if ((byteCount & 7) != 0) {
        return kIOReturnBadArgument;
    }

    UInt8 *mmioBase = static_cast<UInt8 *>(*reinterpret_cast<void **>(
        reinterpret_cast<UInt8 *>(this->accelerator) + 0x860));

    if (!*reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(this->accelerator) + 0x80)) {
        return kIOReturnNotOpen;
    }

    UInt32 iterations = byteCount >> 3;
    UInt8 *reg1 = mmioBase + (offset1 & REGISTER_ACCESS_WINDOW_MASK);
    UInt8 *reg2 = mmioBase + (offset2 & REGISTER_ACCESS_WINDOW_MASK);
    for (UInt32 i = 0; i < iterations; ++i) {
        *reinterpret_cast<UInt32 *>(reg1) = SwapLE32(values[i * 2 + 0]);
        *reinterpret_cast<UInt32 *>(reg2) = SwapLE32(values[i * 2 + 1]);
    }

    return kIOReturnSuccess;
}
