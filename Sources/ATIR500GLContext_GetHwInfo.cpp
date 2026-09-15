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

extern "C" void GetHwInfo_mutex_lock(void *lockPtr) asm("_mutex_lock");
extern "C" void GetHwInfo_mutex_unlock(void *lockPtr) asm("_mutex_unlock");

UInt32 ATIRadeonX1000::getNumPipes() { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(this) + 0xb98); }
UInt32 ATIRadeonX1000::getChipID() { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(this) + 0xc50); }
UInt32 ATIRadeonX1000::getChipRev() { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(this) + 0xc54); }
UInt32 ATIRadeonX1000::getNumZPipes() { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(this) + 0xb9c); }

IOReturn ATIR500GLContext::get_hw_info(UInt32 *out0, UInt32 *out1, UInt32 *out2, UInt32 *out3, UInt32 *out4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    ATIRadeonX1000 *accel = *reinterpret_cast<ATIRadeonX1000 **>(self + 0xc8);
    void *commandLock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accel) + 0x840);

    GetHwInfo_mutex_lock(commandLock);
    *out0 = accel->getNumPipes();
    *out1 = accel->getChipID();
    *out2 = accel->getChipRev();
    *out3 = accel->getNumZPipes();
    *out4 = 0;
    GetHwInfo_mutex_unlock(commandLock);
    return 0;
}
