/*
 * IOATIR500Surface_CopyBufferToBackingStore.cpp
 *
 * RESOLVED (issue #36): `IOATIR500Surface::copy_buffer_to_backing_store`'s
 * real body, real addr 0x11110.
 *
 * REAL RETURN TYPE CORRECTED: the real decompile returns a genuine `1`/
 * `0` result (`bool` here), not `void` as this project had previously
 * declared it by analogy with the sibling `free_buffer_backing_store`.
 *
 * Real body (dense, several vtable slots and fields with no established
 * name elsewhere in this project - transcribed via raw vtable-offset
 * calls/byte offsets, same convention this project uses everywhere a
 * slot/field hasn't been independently named yet):
 *
 * - `buffer+0x24` is a real nested "buffer record" pointer. If null,
 *   calls a real, UNNAMED `this` vtable slot (`+0x5e4`, no arguments) -
 *   if that returns `0`, bails out returning `false` immediately;
 *   otherwise re-reads `buffer+0x24` (now populated).
 * - If `this[0xc09]==0 && this[0xbf7]!=0` (two real `this`-relative byte
 *   flags, per this project's established "class-typed pointer already
 *   byte-scaled" convention - real roles UNKNOWN) AND the buffer
 *   record's own `+8` nested pointer is non-null: calls that nested
 *   object's own UNNAMED vtable slot `+0xdc` with a real in/out
 *   parameter (passed in as `2`); if it returns `0` AND the out-param
 *   came back `4`:
 *   - if the buffer record's own `+4` field is nonzero: real
 *     `commandLock` (`accel+0x840`, CONFIRMED field - see
 *     `Headers/ATIRadeonX1000.h`) sequence RESOLVED, issue #50 (live
 *     kxld-resolved `/dev/kmem` read on real G5/Tiger hardware) as
 *     `_lck_mtx_unlock`/`_mutex_unlock_rwcmb` (`FUN_00011410`) THEN
 *     `_mutex_lock`/`_lck_mtx_lock` (`FUN_00011400`) - the REVERSE of
 *     this project's own prior "acquire then release" assumption for
 *     these two calls (their names/roles were never independently
 *     confirmed before this pass). Real order is a genuine "drop an
 *     already-held lock, update the counter below, then reacquire it"
 *     idiom - the SAME real unlock-then-lock shape this project already
 *     documented for `ATIR500GLContext::start`'s own `FUN_000286dc/ec`
 *     pair (`Headers/ATIR500GLContext.h`), now confirmed to recur here
 *     with a completely different pair of local stub addresses. Updates
 *     a real accelerator-owned counter at `accel+0x7b4` (`piVar2[0x1ed]`
 *     on a real `int*`-typed local - DWORD-indexed, `0x1ed*4=0x7b4`, NOT
 *     a raw `0x1ed` byte offset - this project's own well-known
 *     `int*`-scaling trap, applied correctly here) by a real delta
 *     returned from another UNNAMED accelerator vtable slot (`+0x55c`,
 *     called with `this+0x7c`) BETWEEN the unlock and the relock, then
 *     (now back under the lock) calls the accelerator's real, ALREADY-
 *     NAMED `removeTransferFromGART` (`+0x5ac`, RESOLVED issue
 *     #33/OneDataBuffer work) on the buffer record itself, clears the
 *     record's own `+4` field, and re-reads `buffer+0x24` once more.
 *   - either way, updates the buffer record's own `+0x54`/`+0x58`
 *     "generation stamp" fields against `this+0x7c` (the same real
 *     per-surface stamp counter this project has seen govern similar
 *     "generation"/staleness bookkeeping elsewhere).
 * - If the buffer record's own `+0x54` no longer equals `this+0x7c`, OR
 *   its `+0x58` flag is clear: does the real "actual copy" work -
 *   accumulates the buffer's own `+0x10` byte count into a real
 *   accelerator-owned running total (`accel+0x728`), then - for every
 *   real tile in the buffer's own `+0x20`x`+0x22` (width x height) tile
 *   grid - calls two more real, UNNAMED `this` vtable slots per tile
 *   (`+0x5f0`, a getter populating two out-params; `+0x5e8`, the actual
 *   per-tile blit/submit call taking the buffer, `this+0x7c`, and the
 *   tile x/y), writing `this+0x7c` into a nested field
 *   (`*(int*)(buffer[0x24]+0x14)+8`) after each tile. Finally stamps the
 *   buffer record's own `+0x54` with `this+0x7c`, then walks a real,
 *   fixed 23-entry array of framebuffer-ish slot pointers at `this+0xcc`
 *   (stride `0x78`, real UNKNOWN array - matches no previously-
 *   documented array in this project), updating any slot whose own
 *   `+0x54` still matches the OLD `this+0x7c` value to the NEW one (a
 *   real "propagate this generation bump to any other cached slot on
 *   the same buffer" step).
 * - Always returns `true` on reaching the end (the only real `false`
 *   return is the early vtable-`+0x5e4`-failure bailout above).
 *
 * Confidence: CONFIRMED for control flow and every real offset/field
 * access (checked against Ghidra's own decompile of this `IOATIR500Surface`-
 * typed `this`, byte-scaled per this project's established convention).
 * Several vtable slots and fields have no established real name/role
 * beyond what's directly inferable from this one call site - flagged
 * UNKNOWN above rather than guessed. No C++ compiler was available in
 * the sandboxed environment this was written in (same standing
 * limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Types.h"

/* real addrs 0x11400/0x11410 - RESOLVED, issue #50 (live kxld-resolved
   /dev/kmem read on real G5/Tiger hardware, cross-referenced against the
   running kernel's own symbol table): FUN_00011410 = _lck_mtx_unlock
   (aka _mutex_unlock_rwcmb), FUN_00011400 = _mutex_lock (aka
   _lck_mtx_lock) - the REVERSE of this project's own prior "acquire/
   release" labels, see this function's own header comment above. */
extern "C" void FUN_00011410(void *lockPtr) asm("_lck_mtx_unlock");
extern "C" void FUN_00011400(void *lockPtr) asm("_mutex_lock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

bool IOATIR500Surface::copy_buffer_to_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *buf = reinterpret_cast<UInt8 *>(buffer);

    UInt8 *bufferRecord = *reinterpret_cast<UInt8 **>(buf + 0x24);
    if (bufferRecord == nullptr) {
        typedef UInt32 (*Fn0)(void *);
        void **vtable = *reinterpret_cast<void ***>(self);
        UInt32 ok = reinterpret_cast<Fn0>(vtable[0x5e4 / 4])(this);
        if (ok == 0) {
            return false;
        }
        bufferRecord = *reinterpret_cast<UInt8 **>(buf + 0x24);
    }

    if (U8At(self, 0xc09) == 0 && U8At(self, 0xbf7) != 0) {
        UInt8 *nested = *reinterpret_cast<UInt8 **>(bufferRecord + 8);
        if (nested != nullptr) {
            SInt32 outParam = 2;
            typedef SInt32 (*GetFn)(void *, SInt32, SInt32 *);
            void **nestedVtable = *reinterpret_cast<void ***>(nested);
            SInt32 rc = reinterpret_cast<GetFn>(nestedVtable[0xdc / 4])(nested, 2, &outParam);
            if (rc == 0 && outParam == 4) {
                bufferRecord = *reinterpret_cast<UInt8 **>(buf + 0x24);
                if (U32At(bufferRecord, 4) != 0) {
                    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
                    FUN_00011410(*reinterpret_cast<void **>(accel + 0x840)); /* real: unlocks commandLock (issue #50 identity correction) */
                    SInt32 prevCounter = *reinterpret_cast<SInt32 *>(accel + 0x7b4);
                    typedef SInt32 (*Fn1)(void *, UInt32);
                    void **accelVtable = *reinterpret_cast<void ***>(accel);
                    SInt32 delta = reinterpret_cast<Fn1>(accelVtable[0x55c / 4])(accel, U32At(self, 0x7c));
                    *reinterpret_cast<SInt32 *>(accel + 0x7b4) = prevCounter + delta;
                    FUN_00011400(*reinterpret_cast<void **>(accel + 0x840)); /* real: re-locks commandLock (issue #50 identity correction) */
                    reinterpret_cast<ATIRadeonX1000 *>(accel)->removeTransferFromGART(
                        reinterpret_cast<VendorTransferBuffer *>(bufferRecord));
                    U32At(bufferRecord, 4) = 0;
                    bufferRecord = *reinterpret_cast<UInt8 **>(buf + 0x24);
                }
                if (U32At(bufferRecord, 0x54) == U32At(self, 0x7c)) {
                    U8At(bufferRecord, 0x58) = 0;
                } else {
                    U32At(bufferRecord, 0x54) = U32At(self, 0x7c) - 1;
                }
            }
            bufferRecord = *reinterpret_cast<UInt8 **>(buf + 0x24);
        }
    }

    if (U32At(bufferRecord, 0x54) != U32At(self, 0x7c) || U8At(bufferRecord, 0x58) == 0) {
        U32At(*reinterpret_cast<UInt8 **>(self + 0xd50), 0x728) += U32At(buf, 0x10);

        UInt32 width = U16At(buf, 0x20);
        UInt32 stampBefore = U32At(self, 0x7c);
        UInt32 stamp = stampBefore;
        if (width != 0) {
            UInt16 height = U16At(buf, 0x22);
            for (UInt32 x = 0; x < width; x++) {
                for (UInt32 y = 0; y < height; y++) {
                    UInt32 out0, out1;
                    typedef void (*GetTileFn)(void *, void *, UInt32, UInt32, UInt32 *, UInt32 *, UInt32);
                    void **vtable = *reinterpret_cast<void ***>(self);
                    reinterpret_cast<GetTileFn>(vtable[0x5f0 / 4])(this, buffer, x, y, &out0, &out1, 0);
                    typedef void (*BlitTileFn)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, void *, UInt32, UInt32, UInt32, UInt32, UInt32);
                    reinterpret_cast<BlitTileFn>(vtable[0x5e8 / 4])(this, 0, 0, out0, out1, x, y, buffer, stampBefore, 0, 0, 0, 1);
                    U32At(*reinterpret_cast<UInt8 **>(*reinterpret_cast<UInt32 *>(buf + 0x24) + 0x14), 8) = U32At(self, 0x7c);
                    height = U16At(buf, 0x22);
                }
                width = U16At(buf, 0x20);
            }
            stamp = U32At(self, 0x7c);
        }

        UInt8 *rec = *reinterpret_cast<UInt8 **>(buf + 0x24);
        U32At(rec, 0x54) = stamp;

        UInt8 *slot = self + 0xcc;
        for (int i = 0; i < 0x17; i++) {
            UInt8 *slotPtr = *reinterpret_cast<UInt8 **>(slot);
            if (slotPtr != nullptr && U32At(slotPtr, 0x54) == stampBefore) {
                U32At(slotPtr, 0x54) = U32At(self, 0x7c);
            }
            slot += 0x78;
        }
    }

    return true;
}
