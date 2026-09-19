/*
 * ATIRadeonX1000_RingSubmit.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): the real command-ring
 * submission subsystem - `submit_buffer` (real addr 0x20980),
 * `submit_ring_data` (real addr 0x1f030), `submit_empty_buffer` (real
 * addr 0x1bca0), `DumpASICHangState` (real addr 0x1d480),
 * `enable_GPUSensor`/`disable_GPUSensor` (real addrs 0x19f30/0x19fd0).
 * See each method's own header comment in `Headers/ATIRadeonX1000.h`
 * for the full real-structure summary.
 *
 * Real external symbols used here:
 *   `FUN_00020cc4`/`FUN_0001d7ec` - RESOLVED (issue #58 follow-up): both
 *   are kxld-patched stubs whose live target is `IOSleep` (kernel
 *   0x2b255c, exact nm match); the real args (1 and 10) are milliseconds.
 *   `FUN_00020c94`/`FUN_0001d7dc` - real varargs logging calls (format-
 *   string-plus-values shape) - declared here as `IOLog` by strong
 *   shape match (Apple's standard kernel varargs logger), consistent
 *   with this project's existing confidence conventions for well-known
 *   KPI shapes.
 *   `FUN_0001d80c`/`FUN_0001d7fc` - the real Mach `assert_wait_timeout`/
 *   `thread_block` pair (exact real argument shapes match Apple's
 *   published kernel API precisely), used for a real timed wait while
 *   polling for ASIC responsiveness.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - five real, complete, standalone decompiles, each cross-
 * checked against this project's own already-established MMIO/cache-
 * intrinsic conventions (`ATIRadeonX1000_TexturePageoff.cpp`).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h" /* dcbf/dcbst/eieio/isync, see that header */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
/* real: this hardware register pair is read byte-by-byte and
 * reconstructed low-byte-first (CONCAT11(byte[1],byte[0]) in the raw
 * decompile) - a real little-endian register on a big-endian PowerPC
 * host, matching this project's own established byte-swap conventions
 * elsewhere. A plain `UInt16*` dereference would read it as big-endian
 * and silently invert the FIFO-space comparison, so this explicit
 * reconstruction is required, not stylistic. */
inline UInt32 ReadLE16(void *addr) { return static_cast<UInt32>(U8At(addr, 0)) | (static_cast<UInt32>(U8At(addr, 1)) << 8); }
} // namespace


/* FUN_00020cc4 and FUN_0001d7ec: two separate stubs, same target. */
extern "C" void RingSubmit_IOSleep(UInt32 milliseconds) asm("_IOSleep");

/* real varargs logger - shape (format string + values, no return used)
 * matches Apple's standard kernel IOLog exactly. */
extern "C" void RingSubmit_IOLog(const char *fmt, ...) asm("_IOLog");

/* real Mach kernel primitives - exact argument shapes match Apple's
 * published API. */
extern "C" void RingSubmit_assert_wait_timeout(void *event, int interruptible, UInt32 interval, UInt32 scaleFactor) asm("_assert_wait_timeout");
extern "C" void RingSubmit_thread_block(void *continuation) asm("_thread_block");
extern "C" UInt32 gl_assert_wait_timeout_event;

/* (re-ported mechanically: see ATIRadeonX1000_submit_ring_data_Port.cpp) */


/* (re-ported mechanically: see ATIRadeonX1000_submit_buffer_Port.cpp) */


/* (re-ported mechanically: see ATIRadeonX1000_submit_idct_buffer_consumed_Port.cpp) */


void ATIRadeonX1000::submit_empty_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U8At(self, 0x80) == 0) {
        return;
    }

    UInt32 cfg = U32At(self, 0xbbc);
    U32At(self, 0x8a0) = 0;
    UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(self, 0x860));

    UInt32 tries = 0x2711;
    do {
        U32At(mmio, 0x30) = 0x10000000;
        enforceInOrderExecutionIO();
        U32At(mmio, 0x34) = (cfg << 0x18) | ((cfg & 0xff00u | 0x100u) << 8) | ((cfg & 0xff0000u) >> 8) | (cfg >> 0x18);
        enforceInOrderExecutionIO();
        U32At(mmio, 0x30) = 0x10000000;
        enforceInOrderExecutionIO();
        U32At(mmio, 0x34) = (cfg << 0x18) | ((cfg & 0xff00u) << 8) | ((cfg >> 8) & 0xff00u) | (cfg >> 0x18);
        enforceInOrderExecutionIO();
        U32At(mmio, 0x30) = 0x22000000;
        enforceInOrderExecutionIO();
        if (U8At(mmio, 0x37) == 0 && U8At(mmio, 0x36) == 0 && U8At(mmio, 0x35) == 0 && U8At(mmio, 0x34) == 0) {
            return;
        }
        tries--;
    } while (tries != 0);
}

void ATIRadeonX1000::enable_GPUSensor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(self, 0x9a0) = 0;
    U32At(self, 0x99c) = 0;
    UInt8 *src = reinterpret_cast<UInt8 *>(U32At(self, 0x9a8));
    if (src != nullptr) {
        typedef void (*ArmFn)(void *, UInt32);
        typedef void (*EnableFn)(void *);
        (*reinterpret_cast<ArmFn *>(*reinterpret_cast<void ***>(src) + (300 / 4)))(src, U32At(self, 0x998));
        (*reinterpret_cast<EnableFn *>(*reinterpret_cast<void ***>(src) + (0xec / 4)))(src);
    }
}

void ATIRadeonX1000::disable_GPUSensor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *src = reinterpret_cast<UInt8 *>(U32At(self, 0x9a8));
    if (src != nullptr) {
        typedef void (*DisableFn)(void *);
        (*reinterpret_cast<DisableFn *>(*reinterpret_cast<void ***>(src) + (0x158 / 4)))(src);
        (*reinterpret_cast<DisableFn *>(*reinterpret_cast<void ***>(src) + (0xf0 / 4)))(src);
    }
}

/* (re-ported mechanically: see ATIRadeonX1000_DumpASICHangState_Port.cpp) */

