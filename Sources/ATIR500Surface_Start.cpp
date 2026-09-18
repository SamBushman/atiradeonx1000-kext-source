/*
 * ATIR500Surface_Start.cpp
 *
 * RESOLVED (issue #58): real body for `ATIR500Surface::start`, real addr
 * 0x3d3f0. A real, thin wrapper: takes the accelerator's own real
 * commandLock, calls the base class's own real `IOATIR500Surface::start`
 * (via a real vtable pointer in the raw decompile, `PTR_start_00048a20` -
 * transcribed as an ordinary `IOATIR500Surface::start(provider)` call,
 * matching every other context class's own identical subclass-calls-base
 * pattern), and on success zeroes 7 more real subclass-only fields plus
 * sets a real "started" flag (`+0xdb8`).
 *
 * Confidence: CONFIRMED for control flow and every real offset - a real,
 * complete, standalone decompile.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void ATIR500SurfStart_mutex_lock(void *) asm("_IOLockLock");
extern "C" void ATIR500SurfStart_mutex_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

bool ATIR500Surface::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

    ATIR500SurfStart_mutex_lock(*reinterpret_cast<void **>(providerBytes + 0x840));
    bool ok = IOATIR500Surface::start(provider);
    if (ok) {
        U16At(self, 0xdb4) = 0;
        U8At(self, 0xdb7) = 0;
        U8At(self, 0xdb6) = 0;
        U32At(self, 0xd90) = 0;
        U32At(self, 0xd94) = 0;
        U32At(self, 0xda4) = 0;
        U32At(self, 0xda8) = 0;
        U32At(self, 0xdac) = 0;
        U32At(self, 0xdb8) = 1;
    }
    ATIR500SurfStart_mutex_unlock(*reinterpret_cast<void **>(providerBytes + 0x840));
    return ok;
}
