/*
 * ATIRadeonX1000_TimeStampWait.cpp
 *
 * RESOLVED (issue #23): the real bodies of `waitForTimeStamp`/
 * `sleepForTimeStamp`/`waitForConsumedIDCTTimeStamp` - three real,
 * independently-compiled instances of the exact same real algorithm: a
 * real hardware-fence busy-wait-with-periodic-block loop (real cap
 * `0xc351` = 50001 iterations), timed via real kernel clock calls and
 * accumulating real elapsed wall-clock time into a shared per-accelerator
 * statistics field (`this+0x760`, the same field for all three real
 * variants).
 *
 * The three real variants differ only in: (1) which real hardware
 * timestamp they poll, and (2) which real per-call-site lazy-binding
 * stub instances (issue #15's catalog, extended here with 12 more) they
 * call for the shared timing/scheduling primitives - the algorithm
 * itself, transcribed once below via a shared static helper, is
 * byte-for-byte identical across all three real decompiles.
 *
 * Real hardware timestamp sources (each cached into its own real
 * per-variant field, checked against the caller's own `tag` argument
 * before doing any real work at all):
 *   - `waitForTimeStamp`/`sleepForTimeStamp`: cache at `this+0x54`, real
 *     value read as a big-endian-byte-order 32-bit word from
 *     `*(this+0x864) + *(this+0x86c)` (a real MMIO base+offset pair,
 *     matching the same real byte-reversed-MMIO-read idiom already
 *     established elsewhere in this project, e.g.
 *     `IOATIR500Surface_LockShape.cpp`'s own set_id_mode).
 *   - `waitForConsumedIDCTTimeStamp`: cache at `this+0x85c`, real value
 *     read the same byte-reversed way from a FIXED offset
 *     (`this+0x860`, then `+0x1fa8..+0x1fab`) - a real, distinct
 *     IDCT-specific hardware counter, matching this method's own real
 *     name.
 *
 * Real per-call-site stub instances (all CONFIRMED, via direct
 * disassembly, to be the same 4-instruction lazy-binding trampoline
 * shape already documented for the other real stubs - added to issue
 * #15's catalog, `ATIRadeonX1000Registers.h`, without changing that
 * issue's own open status):
 *   - "get current time" (called twice per real invocation, start and
 *     end): `waitForTimeStamp`/`sleepForTimeStamp` share `0x25344`;
 *     `waitForConsumedIDCTTimeStamp` uses `0x25644`;
 *     `sleepForTimeStamp` alone uses a separate instance, `0x25ac4`.
 *     Real call shape (one pointer argument, fills a real two-word
 *     `{int sec, uint frac}`-shaped pair at that address) strongly
 *     resembles the standard XNU `clock_get_uptime`-family API - a
 *     real, plausible INFERENCE from argument shape and this driver's
 *     own real usage pattern, NOT a confirmed real name (this project
 *     has no way to verify the real external symbol these lazy-binding
 *     stubs resolve to, per issue #15's own standing limitation).
 *   - "arm a timeout and block" pair, called together inside the real
 *     retry loop: `waitForTimeStamp` uses `0x25324`/`0x25314`;
 *     `sleepForTimeStamp` uses `0x25aa4`/`0x25a94`;
 *     `waitForConsumedIDCTTimeStamp` uses `0x25624`/`0x25614`. Real call
 *     shape (`(event*, 0, 100, 1000)` then `(0)`) strongly resembles the
 *     standard XNU `assert_wait_timeout`/`thread_block` pair - same
 *     INFERRED, not confirmed, caveat as above.
 *   - "convert elapsed (sec,frac) into an accumulator delta":
 *     `waitForTimeStamp` uses `0x25334`; `sleepForTimeStamp` uses
 *     `0x25ab4`; `waitForConsumedIDCTTimeStamp` uses `0x25634`. Same
 *     INFERRED/not-confirmed caveat.
 *
 * Real, previously-undocumented global: `_gl_assert_wait_timeout_event`
 * - a real event/wait-channel object all three real variants share,
 * passed to the "arm a timeout" call.
 *
 * One real ambiguity worth flagging explicitly: the raw decompile never
 * shows an explicit assignment to the accumulator-delta local
 * (`local_34`) anywhere in its own visible code - only the initial
 * `= 0` and the final `accum += local_34`. Since the "convert elapsed
 * time" call is itself an opaque, unprototyped indirect call, Ghidra's
 * own static analysis can't see (or can't show) that call writing
 * through the output pointer it's passed, the same real limitation this
 * project has already documented for other opaque-call output
 * parameters (e.g. `tmpAllocVRAM`'s own real return value, issue #23).
 * Transcribed here on the INFERENCE that it does (matching this
 * function's own obvious structural intent - capture start/end time,
 * compute elapsed, convert, accumulate - a real "always adds zero"
 * design would be a strange thing to compile in) - not iron-clad proof.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant - three real, complete, structurally-identical decompiles.
 * The specific real external identities of the timing/scheduling stub
 * calls are INFERRED from argument shape and standard XNU convention,
 * not confirmed - flagged accordingly rather than asserted as fact. No
 * C++ compiler was available in the sandboxed environment this was
 * written in (same standing limitation as every other file in this
 * project) - checked by careful, repeated manual re-reading against
 * each raw decompile instead.
 */

#include "../Headers/ATIRadeonX1000.h"

extern "C" UInt32 _gl_assert_wait_timeout_event; /* real global, real identity/purpose beyond "a wait-channel object" not independently confirmed */

namespace {

/* real: reads a real MMIO word at `base`, byte-reversed (big-endian
 * PPC MMIO convention already established elsewhere in this project). */
inline UInt32 ReadTimestampBE(void *base) {
    UInt8 *p = reinterpret_cast<UInt8 *>(base);
    return (static_cast<UInt32>(p[3]) << 0x18) | (static_cast<UInt32>(p[2]) << 0x10) |
           (static_cast<UInt32>(p[1]) << 8) | static_cast<UInt32>(p[0]);
}

/*
 * Shared real algorithm behind all three real waitFor.../sleepFor...
 * variants - see this file's own header comment for the full account.
 * `getTime`/`armTimeout`/`block`/`convertDelta` are each variant's own
 * real per-call-site stub instance (INFERRED role, not confirmed
 * identity); `readTimestamp` is the variant's own real hardware-counter
 * read; `cacheField`/`accumField` are the variant's own real per-object
 * fields.
 */
SInt32 PollForTimeStamp(void *self, UInt32 tag, UInt32 cacheOffset,
                         void (*getTime)(UInt32 *outSec, UInt32 *outFrac),
                         void (*armTimeout)(UInt32 *event, UInt32 interruptType, UInt32 interval, UInt32 scale),
                         void (*block)(UInt32 continuation),
                         void (*convertDelta)(UInt32 sec, UInt32 frac, UInt32 *outDelta),
                         UInt32 (*readTimestamp)(void *self)) {
    UInt8 *base = reinterpret_cast<UInt8 *>(self);
    UInt32 *cache = reinterpret_cast<UInt32 *>(base + cacheOffset);

    if (static_cast<SInt32>(tag - *cache) < 1) {
        return 0;
    }

    UInt32 startSec, startFrac;
    getTime(&startSec, &startFrac);

    UInt32 current = readTimestamp(self);
    *cache = current;

    SInt32 iterations = 0;
    if (static_cast<SInt32>(tag - current) > 0) {
        iterations = 1;
        do {
            armTimeout(&_gl_assert_wait_timeout_event, 0, 100, 1000);
            block(0);
            current = readTimestamp(self);
            *cache = current;
            if (static_cast<SInt32>(tag - current) < 1) break;
            iterations++;
        } while (iterations != 0xc351);
    }

    UInt32 endSec, endFrac;
    getTime(&endSec, &endFrac);
    bool borrow = endFrac < startFrac;
    UInt32 deltaFrac = endFrac - startFrac;
    UInt32 deltaSec = endSec - (startSec + (borrow ? 1u : 0u));

    UInt32 unusedDelta, accumDelta = 0;
    (void)unusedDelta;
    convertDelta(deltaSec, deltaFrac, &accumDelta);
    *reinterpret_cast<UInt32 *>(base + 0x760) += accumDelta;

    if (iterations == 0xc351) return -1;
    return 0;
}

} // namespace

extern "C" {
void FUN_00025344(void *); void FUN_00025324(void *, UInt32, UInt32, UInt32); void FUN_00025314(UInt32); void FUN_00025334(UInt32, UInt32, void *);
void FUN_00025ac4(void *); void FUN_00025aa4(void *, UInt32, UInt32, UInt32); void FUN_00025a94(UInt32); void FUN_00025ab4(UInt32, UInt32, void *);
void FUN_00025644(void *); void FUN_00025624(void *, UInt32, UInt32, UInt32); void FUN_00025614(UInt32); void FUN_00025634(UInt32, UInt32, void *);
}

namespace {
inline void GetTime_25344(UInt32 *sec, UInt32 *frac) { struct P { UInt32 s, f; } p; FUN_00025344(&p); *sec = p.s; *frac = p.f; }
inline void ArmTimeout_25324(UInt32 *e, UInt32 a, UInt32 b, UInt32 c) { FUN_00025324(e, a, b, c); }
inline void Block_25314(UInt32 c) { FUN_00025314(c); }
inline void ConvertDelta_25334(UInt32 sec, UInt32 frac, UInt32 *out) { struct P { UInt32 unused, delta; } p; FUN_00025334(sec, frac, &p); *out = p.delta; }

inline void GetTime_25ac4(UInt32 *sec, UInt32 *frac) { struct P { UInt32 s, f; } p; FUN_00025ac4(&p); *sec = p.s; *frac = p.f; }
inline void ArmTimeout_25aa4(UInt32 *e, UInt32 a, UInt32 b, UInt32 c) { FUN_00025aa4(e, a, b, c); }
inline void Block_25a94(UInt32 c) { FUN_00025a94(c); }
inline void ConvertDelta_25ab4(UInt32 sec, UInt32 frac, UInt32 *out) { struct P { UInt32 unused, delta; } p; FUN_00025ab4(sec, frac, &p); *out = p.delta; }

inline void GetTime_25644(UInt32 *sec, UInt32 *frac) { struct P { UInt32 s, f; } p; FUN_00025644(&p); *sec = p.s; *frac = p.f; }
inline void ArmTimeout_25624(UInt32 *e, UInt32 a, UInt32 b, UInt32 c) { FUN_00025624(e, a, b, c); }
inline void Block_25614(UInt32 c) { FUN_00025614(c); }
inline void ConvertDelta_25634(UInt32 sec, UInt32 frac, UInt32 *out) { struct P { UInt32 unused, delta; } p; FUN_00025634(sec, frac, &p); *out = p.delta; }

UInt32 ReadTimestamp_waitForTimeStamp(void *self) {
    UInt8 *base = reinterpret_cast<UInt8 *>(self);
    return ReadTimestampBE(reinterpret_cast<void *>(*reinterpret_cast<UInt32 *>(base + 0x864) + *reinterpret_cast<UInt32 *>(base + 0x86c)));
}

UInt32 ReadTimestamp_waitForConsumedIDCTTimeStamp(void *self) {
    UInt8 *base = reinterpret_cast<UInt8 *>(self);
    UInt8 *mmio = reinterpret_cast<UInt8 *>(*reinterpret_cast<UInt32 *>(base + 0x860));
    return ReadTimestampBE(mmio + 0x1fa8);
}
} // namespace

UInt32 ATIRadeonX1000::waitForTimeStamp(UInt32 tag) {
    return static_cast<UInt32>(PollForTimeStamp(this, tag, 0x54, GetTime_25344, ArmTimeout_25324, Block_25314, ConvertDelta_25334, ReadTimestamp_waitForTimeStamp));
}

UInt32 ATIRadeonX1000::sleepForTimeStamp(UInt32 tag) {
    return static_cast<UInt32>(PollForTimeStamp(this, tag, 0x54, GetTime_25ac4, ArmTimeout_25aa4, Block_25a94, ConvertDelta_25ab4, ReadTimestamp_waitForTimeStamp));
}

IOReturn ATIRadeonX1000::waitForConsumedIDCTTimeStamp(UInt32 tag) {
    return static_cast<IOReturn>(PollForTimeStamp(this, tag, 0x85c, GetTime_25644, ArmTimeout_25624, Block_25614, ConvertDelta_25634, ReadTimestamp_waitForConsumedIDCTTimeStamp));
}
