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

/* CORRECTED (issue #42 pass, against the stock decompiles at 0x33660/0x33740/0x325d0):
 *  1. All three take the accelerator's command lock (IOLockLock/IOLockUnlock at accelerator+0x840)
 *     around the register access; the earlier transcription omitted it ("lock names unknown").
 *  2. The write loops advance their counter by 2 per iteration but compare it with byteCount>>3, so
 *     they perform ceil((byteCount>>3)/2) iterations, NOT byteCount>>3: a request for 2 or more
 *     pairs writes only about half of them. That is a quirk of the shipped code; reproduced as is. */
extern "C" void RawRegs2D_lock(void *) asm("_IOLockLock");
extern "C" void RawRegs2D_unlock(void *) asm("_IOLockUnlock");

static inline UInt32 SwapLE32(UInt32 v) {
    return ((v & 0x000000ffu) << 24) | ((v & 0x0000ff00u) << 8) |
           ((v & 0x00ff0000u) >> 8)  | ((v & 0xff000000u) >> 24);
}

IOReturn ATIR5002DContext::read_regs(UInt32 *offsets, UInt32 *outValues,
                                      UInt32 requestedByteCount, UInt32 *actualByteCount) {
    UInt8 *accel = reinterpret_cast<UInt8 *>(this->accelerator);
    UInt32 count = *actualByteCount;
    UInt8 *mmioBase = *reinterpret_cast<UInt8 **>(accel + 0x860);
    /* real caller-size-vs-actual-size validation plus 4-byte alignment, BEFORE the lock */
    if (count != requestedByteCount || (count & 3) != 0) {
        return kIOReturnBadArgument; /* 0xe00002c2 */
    }
    RawRegs2D_lock(*reinterpret_cast<void **>(accel + 0x840));
    IOReturn result;
    if (*(accel + 0x80) == 0) {
        result = kIOReturnNotOpen; /* 0xe00002d8 */
    } else {
        for (UInt32 i = 0; i < (count >> 2); ++i) {
            UInt8 *reg = mmioBase + (offsets[i] & REGISTER_ACCESS_WINDOW_MASK);
            outValues[i] = SwapLE32(*reinterpret_cast<UInt32 *>(reg));
        }
        result = kIOReturnSuccess;
    }
    RawRegs2D_unlock(*reinterpret_cast<void **>(accel + 0x840));
    return result;
}

IOReturn ATIR5002DContext::write_regs(UInt32 *offsetValuePairs, UInt32 pairByteCount) {
    UInt8 *accel = reinterpret_cast<UInt8 *>(this->accelerator);
    UInt8 *mmioBase = *reinterpret_cast<UInt8 **>(accel + 0x860);
    if ((pairByteCount & 7) != 0) {
        return kIOReturnBadArgument;
    }
    RawRegs2D_lock(*reinterpret_cast<void **>(accel + 0x840));
    IOReturn result;
    if (*(accel + 0x80) == 0) {
        result = kIOReturnNotOpen;
    } else {
        /* real loop shape: counter += 2 per iteration, compared with byteCount>>3 (see note above) */
        UInt32 *pair = offsetValuePairs;
        for (UInt32 counter = 0; (pairByteCount >> 3) != 0; ) {
            UInt8 *reg = mmioBase + (pair[0] & REGISTER_ACCESS_WINDOW_MASK);
            *reinterpret_cast<UInt32 *>(reg) = SwapLE32(pair[1]);
            counter += 2;
            pair += 2;
            if (!(counter < (pairByteCount >> 3))) break;
        }
        result = kIOReturnSuccess;
    }
    RawRegs2D_unlock(*reinterpret_cast<void **>(accel + 0x840));
    return result;
}

IOReturn ATIR5002DContext::write_2_regs(UInt32 offset1, UInt32 offset2, UInt32 *values, UInt32 byteCount) {
    UInt8 *accel = reinterpret_cast<UInt8 *>(this->accelerator);
    UInt8 *mmioBase = *reinterpret_cast<UInt8 **>(accel + 0x860);
    if ((byteCount & 7) != 0) {
        return kIOReturnBadArgument;
    }
    RawRegs2D_lock(*reinterpret_cast<void **>(accel + 0x840));
    IOReturn result;
    if (*(accel + 0x80) == 0) {
        result = kIOReturnNotOpen;
    } else {
        /* every iteration writes the SAME two registers (offset1, offset2) with the next pair of values;
         * same counter += 2 loop shape as write_regs */
        UInt32 *pair = values;
        for (UInt32 counter = 0; (byteCount >> 3) != 0; ) {
            *reinterpret_cast<UInt32 *>(mmioBase + (offset1 & REGISTER_ACCESS_WINDOW_MASK)) = SwapLE32(pair[0]);
            *reinterpret_cast<UInt32 *>(mmioBase + (offset2 & REGISTER_ACCESS_WINDOW_MASK)) = SwapLE32(pair[1]);
            counter += 2;
            pair += 2;
            if (!(counter < (byteCount >> 3))) break;
        }
        result = kIOReturnSuccess;
    }
    RawRegs2D_unlock(*reinterpret_cast<void **>(accel + 0x840));
    return result;
}
