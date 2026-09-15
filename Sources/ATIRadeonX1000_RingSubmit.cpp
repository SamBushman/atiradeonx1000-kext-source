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
 *   `FUN_00020cc4`/`FUN_0001d7ec` - real, address-pinned, single-
 *   UInt32-arg, no-return short-delay helpers between poll iterations -
 *   own exact identity NOT independently confirmed (plausibly
 *   `IODelay`, matching this project's own already-documented
 *   `FUN_000037dc` precedent in `IOATIR500Accelerator_
 *   FreeOrphanTexture.cpp`), but NOT asserted as such here.
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

extern "C" void enforceInOrderExecutionIO(void);
extern "C" void dataCacheBlockStore(UInt32 addr);
extern "C" void dataCacheBlockFlush(UInt32 addr);
extern "C" void sync(int);
extern "C" void instructionSynchronize(void);

/* real, address-pinned - own identity NOT independently confirmed;
 * plausibly IODelay by shape (single UInt32 arg, no return, used as a
 * short between-poll-iterations yield). */
extern "C" void RingSubmit_FUN_00020cc4(UInt32 arg);
extern "C" void RingSubmit_FUN_0001d7ec(UInt32 arg);

/* real varargs logger - shape (format string + values, no return used)
 * matches Apple's standard kernel IOLog exactly. */
extern "C" void RingSubmit_IOLog(const char *fmt, ...) asm("_IOLog");

/* real Mach kernel primitives - exact argument shapes match Apple's
 * published API. */
extern "C" void RingSubmit_assert_wait_timeout(void *event, int interruptible, UInt32 interval, UInt32 scaleFactor) asm("_assert_wait_timeout");
extern "C" void RingSubmit_thread_block(void *continuation) asm("_thread_block");
extern "C" void *_gl_assert_wait_timeout_event;

void ATIRadeonX1000::submit_ring_data() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 pending = U32At(self, 0x914);
    UInt32 committed = U32At(self, 0x918);
    if (pending == committed) {
        return;
    }

    if ((pending & 7) != 0) {
        UInt8 *ring = reinterpret_cast<UInt8 *>(U32At(self, 0x900));
        do {
            UInt32 next = pending + 1;
            U32At(ring, pending * 4) = 0x80000000;
            pending = next & 0x7ff;
        } while ((pending & 7) != 0);
        U32At(self, 0x914) = pending;
    }

    UInt8 lineSize = U8At(self, 0x84);
    UInt8 *ringBase = reinterpret_cast<UInt8 *>(U32At(self, 0x900));

    if ((U32At(self, 0x98) & 0x80u) == 0) {
        sync(0);
        instructionSynchronize();
    } else if (committed < pending) {
        UInt32 base = (~static_cast<UInt32>(lineSize) + 1) & (reinterpret_cast<UInt32>(ringBase) + committed * 4);
        SInt32 span = static_cast<SInt32>(((pending - committed) * 4 + ((reinterpret_cast<UInt32>(ringBase) + committed * 4) & (lineSize - 1))) - lineSize);
        SInt32 off = 0;
        if (span > 0) {
            do {
                dataCacheBlockStore(base + off);
                off += lineSize;
            } while (off < span);
        }
        sync(0);
        instructionSynchronize();
        dataCacheBlockFlush(base + off);
        sync(0);
        instructionSynchronize();
        instructionSynchronize();
    } else {
        UInt32 ringBaseVal = reinterpret_cast<UInt32>(ringBase);
        UInt32 tailBase = (~static_cast<UInt32>(lineSize) + 1) & (ringBaseVal + committed * 4);
        SInt32 tailSpan = static_cast<SInt32>(((0x800u - committed) * 4 + ((ringBaseVal + committed * 4) & (lineSize - 1))) - lineSize);
        SInt32 off = 0;
        if (tailSpan > 0) {
            do {
                dataCacheBlockStore(tailBase + off);
                off += lineSize;
            } while (off < tailSpan);
        }
        sync(0);
        instructionSynchronize();
        dataCacheBlockFlush(tailBase + off);
        sync(0);
        instructionSynchronize();
        instructionSynchronize();

        UInt32 headBase = (~static_cast<UInt32>(lineSize) + 1) & ringBaseVal;
        SInt32 headSpan = static_cast<SInt32>((pending * 4 + ((lineSize - 1) & ringBaseVal)) - lineSize);
        off = 0;
        if (headSpan > 0) {
            do {
                dataCacheBlockStore(headBase + off);
                off += lineSize;
            } while (off < headSpan);
        }
        sync(0);
        instructionSynchronize();
        dataCacheBlockFlush(headBase + off);
        sync(0);
        instructionSynchronize();
        instructionSynchronize();
    }

    UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    U32At(mmio, CP_RB_WPTR) = (pending << 0x18) | ((pending & 0x700u) << 8);
    enforceInOrderExecutionIO();
    U32At(self, 0x918) = pending;
}

UInt32 ATIRadeonX1000::submit_buffer(UInt32 *bufferStart, UInt32 bufferOffsetOrEnd, UInt32 dwordCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    for (; (dwordCount & 7) != 0; dwordCount++) {
        bufferStart[dwordCount] = 0x80000000;
    }

    UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(self, 0x90c));
    UInt8 *mmioOff = reinterpret_cast<UInt8 *>(U32At(self, 0x910));
    UInt32 wptr = U32At(self, 0x914);
    SInt32 fifoMargin = static_cast<SInt32>(((ReadLE16(mmio + reinterpret_cast<UInt32>(mmioOff)) - wptr) - 1) & 0x7ff) - 7;

    if (fifoMargin >= 5) {
        goto haveFifoSpace;
    }
    {
        UInt32 tries = 0;
        do {
            tries++;
            RingSubmit_FUN_00020cc4(1);
            mmio = reinterpret_cast<UInt8 *>(U32At(self, 0x90c));
            mmioOff = reinterpret_cast<UInt8 *>(U32At(self, 0x910));
            wptr = U32At(self, 0x914);
            fifoMargin = static_cast<SInt32>(((ReadLE16(mmio + reinterpret_cast<UInt32>(mmioOff)) - wptr) - 1) & 0x7ff) - 7;
            if (fifoMargin > 4) {
                goto haveFifoSpace;
            }
        } while (tries != 1000);
    }
    goto fifoTimedOut;

haveFifoSpace:
    U32At(self, 0x6fc) += dwordCount * 4;

    if ((U32At(self, 0x98) & 0x80u) == 0) {
        sync(0);
        instructionSynchronize();
    } else {
        UInt32 lineSize = U8At(self, 0x84);
        UInt32 base = (~lineSize + 1) & reinterpret_cast<UInt32>(bufferStart);
        SInt32 off = 0;
        SInt32 span = static_cast<SInt32>((dwordCount * 4 + (reinterpret_cast<UInt32>(bufferStart) & (lineSize - 1))) - lineSize);
        if (span > 0) {
            do {
                dataCacheBlockStore(base + off);
                off += lineSize;
            } while (off < span);
        }
        sync(0);
        instructionSynchronize();
        dataCacheBlockFlush(base + off);
        sync(0);
        instructionSynchronize();
        instructionSynchronize();
    }

    if (U32At(self, 0x8a0) != 0) {
        submit_empty_buffer();
        mmio = reinterpret_cast<UInt8 *>(U32At(self, 0x90c));
        mmioOff = reinterpret_cast<UInt8 *>(U32At(self, 0x910));
        wptr = U32At(self, 0x914);
    }

    fifoMargin = static_cast<SInt32>(((ReadLE16(mmio + reinterpret_cast<UInt32>(mmioOff)) - wptr) - 1) & 0x7ff) - 7;
    if (fifoMargin > 4) {
        goto haveRingSpace;
    }
    {
        UInt32 tries2 = 0;
        do {
            tries2++;
            RingSubmit_FUN_00020cc4(1);
            wptr = U32At(self, 0x914);
            fifoMargin = static_cast<SInt32>(((ReadLE16(reinterpret_cast<UInt8 *>(U32At(self, 0x90c)) + U32At(self, 0x910)) - wptr) - 1) & 0x7ff) - 7;
            if (fifoMargin > 4) {
                goto haveRingSpace;
            }
        } while (tries2 != 1000);
    }
    goto fifoTimedOut;

haveRingSpace: {
    UInt32 idctPending = U32At(self, 0x8a4);
    UInt32 *ring;
    UInt32 stamp;
    if (U32At(self, 0x8d0) == 0) {
        ring = reinterpret_cast<UInt32 *>(U32At(self, 0x900));
        ring[wptr] = 0x57f;
        stamp = U32At(self, 0x50);
        UInt32 next = (wptr + 1) & 0x7ff;
        wptr = next + 1;
        U32At(self, 0x914) = wptr;
        ring[next] = stamp;
        wptr &= 0x7ff;
        U32At(self, 0x914) = wptr;
    } else {
        ring = reinterpret_cast<UInt32 *>(U32At(self, 0x900));
        stamp = U32At(self, 0x50);
    }

    ring[wptr] = 0x101ce;
    wptr = (wptr + 1) & 0x7ff;
    U32At(self, 0x914) = wptr;
    ring[wptr] = (bufferOffsetOrEnd + idctPending) & 0xfffffffcu;
    wptr = (wptr + 1) & 0x7ff;
    U32At(self, 0x914) = wptr;
    ring[wptr] = dwordCount & 0x7fffffu;
    wptr = (wptr + 1) & 0x7ff;
    U32At(self, 0x914) = wptr;
    ring[wptr] = 0x578;
    wptr = (wptr + 1) & 0x7ff;
    UInt32 next2 = wptr + 1;
    U32At(self, 0x914) = next2;
    ring[wptr] = stamp;
    U32At(self, 0x914) = next2 & 0x7ff;

    submit_ring_data();

    if (U32At(self, 0x8d0) != 0) {
        U32At(reinterpret_cast<void *>(U32At(self, 0x8d0)), 0x20) = U32At(self, 0x50);
    }
    UInt32 result = U32At(self, 0x50);
    U32At(self, 0x50) = result + 1;
    return result;
}

fifoTimedOut : {
    UInt8 *mmioBase = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    UInt32 rbbmStatus = (static_cast<UInt32>(U8At(mmioBase, 0xe43)) << 0x18) |
                        (static_cast<UInt32>(U8At(mmioBase, 0xe42)) << 0x10) |
                        (static_cast<UInt32>(U8At(mmioBase, 0xe41)) << 8) |
                        static_cast<UInt32>(U8At(mmioBase, 0xe40));
    RingSubmit_IOLog("ATIRadeon::wait_for_rb_space: Overflowed block waiting for FIFO space.   Have %lu, need %lu. RBBM_STATUS 0x%08x\n",
                      static_cast<unsigned long>(fifoMargin), 5ul, rbbmStatus);
    DumpASICHangState();
    return U32At(self, 0x50) - 1;
}
}

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

void ATIRadeonX1000::DumpASICHangState() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    disable_GPUSensor();

    UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    UInt8 b0 = U8At(mmio, 0x7fb), b1 = U8At(mmio, 0x7fa), b2 = U8At(mmio, 0x7f9), b3 = U8At(mmio, 0x7f8);
    UInt32 tries = 0;
    UInt8 *mmio2;
    do {
        RingSubmit_assert_wait_timeout(&_gl_assert_wait_timeout_event, 0, 100, 1000);
        RingSubmit_thread_block(nullptr);
        mmio2 = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
        UInt32 cur = (static_cast<UInt32>(U8At(mmio2, 0x7fb)) << 0x18) | (static_cast<UInt32>(U8At(mmio2, 0x7fa)) << 0x10) |
                     (static_cast<UInt32>(U8At(mmio2, 0x7f9)) << 8) | static_cast<UInt32>(U8At(mmio2, 0x7f8));
        UInt32 orig = (static_cast<UInt32>(b0) << 0x18) | (static_cast<UInt32>(b1) << 0x10) |
                      (static_cast<UInt32>(b2) << 8) | static_cast<UInt32>(b3);
        if (orig != cur) {
            enable_GPUSensor();
            return;
        }
        tries++;
    } while (tries != 0x186a1);

    UInt8 hi = U8At(mmio2, 0x5003), lo = U8At(mmio2, 0x5002);
    RingSubmit_FUN_0001d7ec(10);
    UInt32 header = (static_cast<UInt32>(hi) << 8 | static_cast<UInt32>(lo)) | 0x1000000;
    RingSubmit_IOLog("** ASIC Hang Log Start **\n");
    RingSubmit_FUN_0001d7ec(10);

    UInt8 *m = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    U32At(m, 0x30) = 0x21000000; enforceInOrderExecutionIO();
    UInt32 v1 = (static_cast<UInt32>(U8At(m, 0x37)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x36)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x35)) << 8) | U8At(m, 0x34);
    U32At(m, 0x30) = 0x18000000; enforceInOrderExecutionIO();
    UInt32 v2 = (static_cast<UInt32>(U8At(m, 0x37)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x36)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x35)) << 8) | U8At(m, 0x34);
    UInt32 v3 = (static_cast<UInt32>(U8At(m, 0x7ff)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x7fe)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x7fd)) << 8) | U8At(m, 0x7fc);
    RingSubmit_IOLog("0x%08lx %08lx %08lx %08lx\n", static_cast<unsigned long>(header), static_cast<unsigned long>(v1), static_cast<unsigned long>(v2), static_cast<unsigned long>(v3));
    RingSubmit_FUN_0001d7ec(10);

    m = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    UInt32 v4 = (static_cast<UInt32>(U8At(m, 0x7fb)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x7fa)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x7f9)) << 8) | U8At(m, 0x7f8);
    UInt32 v5 = (static_cast<UInt32>(U8At(m, 0x7c3)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x7c2)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x7c1)) << 8) | U8At(m, 0x7c0);
    UInt32 v6 = (static_cast<UInt32>(U8At(m, 0x793)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x792)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x791)) << 8) | U8At(m, 0x790);
    UInt32 v7 = (static_cast<UInt32>(U8At(m, 0x7b3)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x7b2)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x7b1)) << 8) | U8At(m, 0x7b0);
    RingSubmit_IOLog("0x%08lx %08lx %08lx %08lx\n", static_cast<unsigned long>(v4), static_cast<unsigned long>(v5), static_cast<unsigned long>(v6), static_cast<unsigned long>(v7));
    RingSubmit_FUN_0001d7ec(10);

    m = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    U32At(m, 0x30) = 0x10000000; enforceInOrderExecutionIO();
    UInt32 v8 = (static_cast<UInt32>(U8At(m, 0x37)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x36)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x35)) << 8) | U8At(m, 0x34);
    if ((U32At(self, 0x98) & 0x400000u) == 0) {
        U32At(m, 0x70) = 0; enforceInOrderExecutionIO();
    } else {
        U32At(m, 0x70) = 0x8000000; enforceInOrderExecutionIO();
    }
    UInt32 v9 = (static_cast<UInt32>(U8At(m, 0x77)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x76)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x75)) << 8) | U8At(m, 0x74);
    UInt32 v10 = (static_cast<UInt32>(U8At(m, 0xe7f)) << 0x18) | (static_cast<UInt32>(U8At(m, 0xe7e)) << 0x10) | (static_cast<UInt32>(U8At(m, 0xe7d)) << 8) | U8At(m, 0xe7c);
    UInt32 v11 = (static_cast<UInt32>(U8At(m, 0xe43)) << 0x18) | (static_cast<UInt32>(U8At(m, 0xe42)) << 0x10) | (static_cast<UInt32>(U8At(m, 0xe41)) << 8) | U8At(m, 0xe40);
    RingSubmit_IOLog("0x%08lx %08lx %08lx %08lx\n", static_cast<unsigned long>(v8), static_cast<unsigned long>(v9), static_cast<unsigned long>(v10), static_cast<unsigned long>(v11));
    RingSubmit_FUN_0001d7ec(10);

    m = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    UInt32 v12 = (static_cast<UInt32>(U8At(m, 0x2143)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x2142)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x2141)) << 8) | U8At(m, 0x2140);
    U32At(m, 0x30) = 0x4010000; enforceInOrderExecutionIO();
    UInt32 v13 = (static_cast<UInt32>(U8At(m, 0x37)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x36)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x35)) << 8) | U8At(m, 0x34);
    UInt32 v14 = (static_cast<UInt32>(U8At(m, 0x4f)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x4e)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x4d)) << 8) | U8At(m, 0x4c);
    UInt32 v15 = (static_cast<UInt32>(U8At(m, 0x743)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x742)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x741)) << 8) | U8At(m, 0x740);
    RingSubmit_IOLog("0x%08lx %08lx %08lx %08lx\n", static_cast<unsigned long>(v12), static_cast<unsigned long>(v13), static_cast<unsigned long>(v14), static_cast<unsigned long>(v15));
    RingSubmit_FUN_0001d7ec(10);

    m = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    UInt32 v16 = (static_cast<UInt32>(U8At(m, 0x7d3)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x7d2)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x7d1)) << 8) | U8At(m, 2000);
    UInt32 v17 = (static_cast<UInt32>(U8At(m, 0x707)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x706)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x705)) << 8) | U8At(m, 0x704);
    U32At(m, 0x30) = 0xb4000000; enforceInOrderExecutionIO();
    UInt32 v18 = (static_cast<UInt32>(U8At(m, 0x37)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x36)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x35)) << 8) | U8At(m, 0x34);
    UInt32 v19 = (static_cast<UInt32>(U8At(m, 0x133)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x132)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x131)) << 8) | U8At(m, 0x130);
    RingSubmit_IOLog("0x%08lx %08lx %08lx %08lx\n", static_cast<unsigned long>(v16), static_cast<unsigned long>(v17), static_cast<unsigned long>(v18), static_cast<unsigned long>(v19));
    RingSubmit_FUN_0001d7ec(10);

    m = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
    UInt32 v20 = (static_cast<UInt32>(U8At(m, 0x1727)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x1726)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x1725)) << 8) | U8At(m, 0x1724);
    UInt32 v21 = (static_cast<UInt32>(U8At(m, 0xef)) << 0x18) | (static_cast<UInt32>(U8At(m, 0xee)) << 0x10) | (static_cast<UInt32>(U8At(m, 0xed)) << 8) | U8At(m, 0xec);
    UInt32 v22 = (static_cast<UInt32>(U8At(m, 0x7bb)) << 0x18) | (static_cast<UInt32>(U8At(m, 0x7ba)) << 0x10) | (static_cast<UInt32>(U8At(m, 0x7b9)) << 8) | U8At(m, 0x7b8);

    UInt32 total = header + v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8 + v9 + v10 + v11 + v12 + v13 + v14 + v15 + v16 + v17 + v18 + v19 + v20 + v21 + v22;

    RingSubmit_IOLog("0x%08lx %08lx %08lx\n", static_cast<unsigned long>(v20), static_cast<unsigned long>(v21), static_cast<unsigned long>(v22));
    RingSubmit_FUN_0001d7ec(10);

    UInt32 idx = 0;
    do {
        UInt8 *m2 = reinterpret_cast<UInt8 *>(U32At(self, 0x860));
        U32At(m2, 0x7f0) = (idx << 0x18) | ((idx & 0xff00u) << 8) | ((idx >> 8) & 0xff00u) | (idx >> 0x18);
        enforceInOrderExecutionIO();
        UInt32 word = (static_cast<UInt32>(U8At(m2, 0x7f7)) << 0x18) | (static_cast<UInt32>(U8At(m2, 0x7f6)) << 0x10) |
                      (static_cast<UInt32>(U8At(m2, 0x7f5)) << 8) | U8At(m2, 0x7f4);
        total += word;
        RingSubmit_IOLog("%ld:0x%08lx\n", static_cast<long>(idx >> 2), static_cast<unsigned long>(word));
        RingSubmit_FUN_0001d7ec(10);
        bool cont = (idx != 0xffc);
        idx += 4;
        if (!cont) break;
    } while (true);

    RingSubmit_IOLog("0x%08lx\n", static_cast<unsigned long>(total));
    RingSubmit_FUN_0001d7ec(10);
    RingSubmit_IOLog("** ASIC Hang Log End **\n");
    RingSubmit_FUN_0001d7ec(10);
}
