/* NOTE 2026-09-19: 5 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500GLContext_GetHwInfo.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `ATIR500GLContext::get_hw_info` - real addr 0x27210 - plus four
 * genuinely trivial real accessors it calls through, added to
 * `ATIRadeonX1000.h` this pass: `getNumPipes`/`getChipID`/`getChipRev`/
 * `getNumZPipes` (each a single raw field read, real addrs 0x1aba0/
 * 0x1abb0/0x1abc0/0x1abd0).
 *
 * Real body: locks the accelerator's already-established `commandLock`
 * (`accel+0x840`, same real mutex this project already uses throughout,
 * e.g. `IOATIR500GLContext_RegularMethods.cpp`), reads the four
 * accessors into the four out-parameters, zeroes a fifth (real purpose
 * unconfirmed - always zero in this real decompile), unlocks, returns 0.
 *
 * Confidence: CONFIRMED for control flow and every real offset - a
 * real, complete, standalone decompile.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void GetHwInfo_mutex_lock(void *lockPtr) asm("_IOLockLock");
extern "C" void GetHwInfo_mutex_unlock(void *lockPtr) asm("_IOLockUnlock");

/* (re-ported mechanically: see ATIRadeonX1000_getNumPipes_Port.cpp) */

/* (re-ported mechanically: see ATIRadeonX1000_getChipID_Port.cpp) */

/* (re-ported mechanically: see ATIRadeonX1000_getChipRev_Port.cpp) */

/* (re-ported mechanically: see ATIRadeonX1000_getNumZPipes_Port.cpp) */


/* (re-ported mechanically: see ATIR500GLContext_get_hw_info_Port.cpp) */

