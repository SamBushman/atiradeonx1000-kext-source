/* NOTE 2026-09-19: 3 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
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

/* (re-ported mechanically: see ATIR5002DContext_read_regs_Port.cpp) */


/* (re-ported mechanically: see ATIR5002DContext_write_regs_Port.cpp) */


/* (re-ported mechanically: see ATIR5002DContext_write_2_regs_Port.cpp) */

