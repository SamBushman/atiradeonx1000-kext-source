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

/* (re-ported mechanically: see ATIR500Surface_start_Port.cpp) */

