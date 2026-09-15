/*
 * IOATIR500Accelerator_SetupStereo.cpp
 *
 * RESOLVED: `IOATIR500Accelerator::setup_stereo`'s real body, real addr
 * 0x5460. Real per-panel (`param1`) stereo-mode state machine.
 *
 * Real structure: if a real "already initialized" flag (`this+0x81`,
 * a single byte) is set, just stores the new mode bits into a real
 * per-panel array (`this+param1*4+0x124`) and returns - a real
 * fast-path once the subsystem is up. Otherwise: no-ops if the new mode
 * already equals the current one (`this+param1*4+0x11c`). If the
 * requested mode doesn't have its own real "stereo enabled" bit (bit 0)
 * clear... [bit 1 gets force-cleared]; if it DOES have bit 0 set and a
 * real per-panel scratch record (`this+param1*0x78+0x1ac`) isn't already
 * allocated, copies a real per-panel default template into it
 * (`FUN_000056f8`, RESOLVED issue #50 via live kxld-resolved `/dev/kmem`
 * read - real target `_memmove`/`_memcpy`; NOT a zero-init as this
 * project's prior account had guessed from the call shape alone - the
 * real second argument is a source POINTER, `self+param1*0x78+300`, not
 * a fill value) and allocates real backing VRAM for it via a real
 * vtable `+0x56c` call then `freeToAllocSurfaceVRAM` (own body not
 * decompiled this pass, real addr `0x45a0`) as a fallback. If the real
 * "stereo bit" of old vs. new mode differs, calls `waitForTimeStamp`
 * then a real vtable `+0x5cc` method (own identity UNKNOWN - not the
 * already-resolved `IOATIR500Surface::+0x5cc`, a DIFFERENT class's
 * vtable); on failure, force-clears stereo mode and frees the scratch
 * record's VRAM via `ATIR500Memory::dealloc` (RESOLVED elsewhere).
 * Finally, if the real per-panel STATE (not just requested mode) changed,
 * walks every live surface (`liveSurfaceListHead`, `+0x5c`) calling three
 * real, already-named-but-undecompiled methods:
 * `IOATIR500Surface::freeAllSwapBuffers`,
 * `IOATIR500Surface::allocMasterSwapBuffer`,
 * `IOATIR500Surface::allocAllSlaveSwapBuffers` (RESOLVED, issue #28 - the
 * one with the confirmed real infinite-loop bug in its own failure path).
 *
 * Confidence: CONFIRMED for control flow and every real offset - a real,
 * complete, standalone decompile. `freeToAllocSurfaceVRAM` (RESOLVED,
 * issue #31, and its own call here FIXED from a placeholder free
 * function taking an explicit accelerator pointer to a real member call
 * - see Sources/IOATIR500Accelerator_VRAMReclaim.cpp),
 * `freeAllSwapBuffers`/`allocMasterSwapBuffer` (also RESOLVED, issue #31
 * - see Sources/IOATIR500Surface_SwapBuffers.cpp), and the real `+0x56c`/
 * `+0x5cc` vtable slot identities remain otherwise as documented. No C++
 * compiler was available in the sandboxed environment this was written
 * in (same standing limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"
#include "../Headers/ATIR500Memory.h"

extern "C" void FUN_000056f8(void *dest, const void *src, UInt32 size) asm("_memmove"); /* RESOLVED, issue #50 */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

SInt32 IOATIR500Accelerator::setup_stereo(UInt32 param1, UInt32 param2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void **vtable = *reinterpret_cast<void ***>(self);

    if (U8At(self, 0x81) != 0) {
        U32At(self, param1 * 4 + 0x124) = param2;
        return 0;
    }

    UInt32 stateOff = param1 * 4;
    if (U32At(self, stateOff + 0x11c) == param2) {
        return 0;
    }

    UInt32 oldState = U32At(self, stateOff + 0x114);
    if ((param2 & 1) == 0) {
        param2 &= 0xfffffffdu;
    } else {
        UInt8 *scratch = self + param1 * 0x78 + 0x1a4;
        if (U32At(self, param1 * 0x78 + 0x1ac) == 0) {
            FUN_000056f8(scratch, self + param1 * 0x78 + 300, 0x78);
            U32At(self, param1 * 0x78 + 0x1b0) = 0;
            U32At(self, param1 * 0x78 + 0x1a4) = 0;
            U32At(self, param1 * 0x78 + 0x1a8) = 0;
            U32At(self, param1 * 0x78 + 0x1ac) = 0;

            typedef SInt32 (*Fn0x56c)(void *, ATIR500SurfaceBuffer *);
            SInt32 result = (*reinterpret_cast<Fn0x56c *>(vtable + (0x56c / 4)))(
                self, reinterpret_cast<ATIR500SurfaceBuffer *>(scratch));
            if (result == 0) {
                result = freeToAllocSurfaceVRAM(nullptr, nullptr, nullptr, 0,
                                                 reinterpret_cast<ATIR500SurfaceBuffer *>(scratch));
                if (result == 0) {
                    return -0x1ffffd43; /* real: literal SInt32 error constant */
                }
            }
        }
        U32At(self, stateOff + 0x114) = 2;
    }

    SInt32 result;
    if (((param2 ^ U32At(self, stateOff + 0x11c)) & 2) == 0) {
        result = 0;
        if ((param2 & 1) != 0) goto store_and_notify;
    } else {
        waitForTimeStamp(U32At(self, 0x50) - 1);
        typedef SInt32 (*Fn0x5cc)(void *, UInt32, UInt32);
        result = (*reinterpret_cast<Fn0x5cc *>(vtable + (0x5cc / 4)))(self, param1, param2);
        if (result != 0) {
            param2 = 0;
        } else {
            if ((param2 & 1) != 0) goto store_and_notify;
        }
    }
    if (U32At(self, param1 * 0x78 + 0x1ac) != 0) {
        /* real: ATIR500Memory::dealloc on the accelerator's own "main" GART pool */
        reinterpret_cast<ATIR500Memory *>(*reinterpret_cast<void **>(self + 0x7c))->dealloc(
            reinterpret_cast<GLKMemoryElement *>(self + param1 * 0x78 + 0x1a4));
    }
    U32At(self, stateOff + 0x114) = 1;

store_and_notify:
    U32At(self, stateOff + 0x11c) = param2;

    if (oldState != U32At(self, stateOff + 0x114)) {
        IOATIR500Surface *surf = *reinterpret_cast<IOATIR500Surface **>(self + 0x5c);
        if (surf != nullptr) {
            IOATIR500Surface *head = surf;
            do {
                surf->freeAllSwapBuffers(param1); /* RESOLVED, issue #31 */
                surf->allocMasterSwapBuffer(param1, 0x9000); /* RESOLVED, issue #31 */
                surf->allocAllSlaveSwapBuffers(param1, 0x9000); /* RESOLVED, issue #28 */
                surf = *reinterpret_cast<IOATIR500Surface **>(reinterpret_cast<UInt8 *>(surf) + 0x9c);
            } while (surf != head);
        }
    }
    return result;
}
