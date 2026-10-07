/* perf_dvd_idct.c - issue #44 criterion 1: DVD/video decode performance, the one domain the existing perf suite (perf_methods.c/perf_baseline.c, GL only)
 * didn't cover - "no safe workload" until #93/#140/#141 derived and live-verified the real doIDCT stream format and the real, safe call sequence below.
 *
 * Scope, deliberately narrow: intra/residual reconstruction only (stream 0, planeSelector 0). This is the ONLY part of DVD hardware decode this project's
 * own #44 scope decision (2026-10-05) and known_vendor_deviations.md's V-series call measurable: the forward-predicted (P/B) macroblock composite (opcode
 * 0x12, #142) never posts a completion stamp on stock hardware - the project's own standing decision is to preserve that hang faithfully, not route a
 * benchmark through it, and #44's banner explicitly excludes P/B throughput as permanently unmeasurable, not a gap. Do not add a P/B-composite path here.
 *
 * Safety / destination choice: this deliberately does NOT call setup_buffers/lock_all_buffers to get a "real" VRAM slot. Section 10 of
 * idct_engine_findings.md (the #92/#145 session) found that path gated on surface+0xbf8's 0x20000000 bit, which starts set on every fresh surface and
 * was never reliably cleared by anything this project's own client code can call - chasing it cost THREE G5 crashes (#145, still open/unresolved) and
 * produced all-zero slot descriptors most of the time even without a crash. Sections 9e-9l's entire successful, repeated, crash-free investigation
 * (dozens of real doIDCT submissions) used destPlaneIndex = -10 instead, which lands on the surface's OWN built-in slot-0 record (surface+0xa8) -
 * always present after basic surface creation, no allocator gate, no setup_buffers/lock_all_buffers involved at all. This file does the same and never
 * calls setup_buffers/lock_all_buffers. The one real G5 crash hazard in this general area (#145) needs a SECOND kext loaded/unloaded concurrently while
 * a DVD connection like this one is held open - this program never loads a kext, so it does not touch that hazard either way. planeSelector is NEVER
 * anything but 0 here (2 is the confirmed #98 lock-leak bug; 1 is stream-1/motion, out of this benchmark's intra-only scope).
 *
 * Macroblock stream format (Tests/idct_engine_findings.md sections 5-7, derived + hardware-confirmed, not guessed):
 *   stream buffer (memType 4): 0x20-byte header (+0x10 = capacity in dwords, +0x18 = a client tag), data from +0x20.
 *   per macroblock (only emitted if at least one block is coded): dword0 = CBP<<6 (Y0=bit11..Cr=bit6; this file always codes Y0 only, CBP=0x20<<6=0x800),
 *   dword1 = (mbRow<<20)|(mbCol<<4), then one coefficient dword per coded block: level<<16 | run<<1 | last (DC-only Y0: run=0, last=1).
 *   doIDCT params (0x38 bytes, client-filled subset): +0x00 fieldPictureFlag=0, +0x04 bottomFieldFlag=0, +0x08 destPlaneIndex=-10 (surface's own
 *   slot-0 record, section 9e's proven CPU-independent destination - this benchmark only times submission, it never reads pixels back), +0x0c
 *   planeSelector=0, +0x10 dmaDwordCount (2 + codedBlocks per MB, no padding, summed over all MBs in the submission), +0x14 engineFlagWord=0x100a0
 *   (0x10080 | plane0 0x20, matching section 9d's live-confirmed 0x1fbc value exactly), +0x18 planeModeWord=0 (stream 0), +0x24 dimensionsHeightWidth
 *   = (48<<16)|64 for this test's fixed 64x48 picture.
 *
 * Escalation discipline (incremental-repro-bisection skill): starts at 1 macroblock (the exact size #140/#141 already ran dozens of times), then only
 * proceeds to 4 and 12 (a quarter-picture and the full 64x48 picture, 4 cols x 3 rows of 16x16 MBs) if every smaller size returned rc=0 and a liveness
 * check still succeeds - each step is "more of the same already-specified format", not a structurally new operation, but this still stops at the first
 * sign of trouble rather than plowing ahead.
 *
 * Usage: perf_dvd_idct [calls per metric, default 2000] [max macroblocks per submission: 1, 4, or 12, default 12] [hold seconds after bind, default 0]
 * The optional 3rd arg sleeps after the DVD bind (before any doIDCT call) - for attaching a read-only diagnostic (e.g. Tools/vram_peek/VRAMPeek.cpp)
 * to inspect the live gate state (accel+0x80/+0x8bc, dvdCtx+0xf8) while the connection is actually open, same pattern ava_drive.c's --hold-after uses.
 * Output (same stable format as perf_methods.c/perf_baseline.c, parsed by Tools/perf_compare.py):
 *   METRIC <name> n=<n> min_us=<> p10_us=<> median_us=<> p90_us=<> max_us=<>
 * Build on the G5:  gcc -arch ppc -std=gnu99 -w -o perf_dvd_idct perf_dvd_idct.c -framework IOKit -framework CoreFoundation
 */
#include "common.h"
#include <stdlib.h>
#include <string.h>
#include <mach/mach_time.h>
#include <mach/mach.h>
#include <unistd.h>

int g_testsRun = 0, g_testsUnexpected = 0, g_testsSkipped = 0, g_testsRecorded = 0;

static double ticks_to_us;
static double now_us(void) { return (double)mach_absolute_time() * ticks_to_us; }
/* same warm-up as perf_methods.c/perf_baseline.c: ~0.7 s of CPU burn so the G5's dynamic power stepping is at full speed before anything is timed. */
static void warmup(void) { double t0 = now_us(); volatile double x = 1.0; while (now_us() - t0 < 700000.0) { int k; for (k = 0; k < 1000; k++) x = x * 1.0000001 + 0.5; } }
static int cmp_d(const void *a, const void *b) { double x = *(const double *)a, y = *(const double *)b; return x < y ? -1 : x > y; }

static void report_metric(const char *name, double *s, int n) {
    qsort(s, n, sizeof(double), cmp_d);
    printf("METRIC %s n=%d min_us=%.2f p10_us=%.2f median_us=%.2f p90_us=%.2f max_us=%.2f\n", name, n, s[0], s[(int)(n * 0.1)], s[n / 2], s[(int)(n * 0.9)], s[n - 1]);
}

/* Fills `buf` (a mapped memType-4 stream buffer, at least 0x20 + mbCount*3*4 bytes) with mbCount flat, DC-only, Y0-only-coded intra macroblocks at
 * sequential (row, col) addresses in a 4-column grid (this test's fixed 64x48 picture = 4 MB columns x 3 MB rows). Returns the stream length in dwords
 * (dmaDwordCount), i.e. the macroblock data only, not the header. */
static UInt32 build_intra_stream(UInt32 *w, int mbCount) {
    UInt32 *buf = w;
    int i;
    w[4] = 0x1fff8;  /* +0x10: capacity in dwords, matches the real capture's own buffer header (section 9b) */
    w[6] = 1;        /* +0x18: client tag, arbitrary */
    {
        UInt32 *p = (UInt32 *)(buf + 8); /* data starts at +0x20 = word index 8 */
        for (i = 0; i < mbCount; i++) {
            int mbRow = i / 4, mbCol = i % 4;
            *p++ = 0x800;                              /* dword0: CBP<<6, Y0 only (bit 11 = 0x800) */
            *p++ = (UInt32)((mbRow << 20) | (mbCol << 4)); /* dword1: macroblock address */
            *p++ = (UInt32)((1024 << 16) | (0 << 1) | 1);  /* coefficient dword: DC level 1024, run 0, last=1 - same probe value as section 9d/9f */
        }
    }
    return (UInt32)(mbCount * 3);
}

int main(int argc, char **argv) {
    int N = argc > 1 ? atoi(argv[1]) : 2000;
    int maxMB = argc > 2 ? atoi(argv[2]) : 12;
    int holdSec = argc > 3 ? atoi(argv[3]) : 0;
    int warm = 20, bad = 0, i;
    mach_timebase_info_data_t tb; double *samp;
    io_service_t svc; io_connect_t surf = IO_OBJECT_NULL, dvd = IO_OBJECT_NULL;
    kern_return_t r; IOByteCount osz;
    vm_address_t streamAddr = 0; vm_size_t streamSize = 0;
    unsigned char region[20];
    int sizes[3] = { 1, 4, 12 }, nSizes = 0, s;

    mach_timebase_info(&tb); ticks_to_us = (double)tb.numer / tb.denom / 1000.0;
    setvbuf(stdout, NULL, _IONBF, 0);
    samp = malloc(N * sizeof(double));
    for (s = 0; s < 3 && sizes[s] <= maxMB; s++) nSizes++;

    svc = find_accelerator_service();
    if (svc == IO_OBJECT_NULL) { printf("no accelerator service\n"); return 1; }
    printf("perf_dvd_idct: %d calls/metric, macroblock sizes up to %d, timer tick %.4f us\n", N, maxMB, ticks_to_us);

    /* Surface setup - identical sequence to Tests/destructive/t3common.h's t3_surface(), 64x48 (the size section 9b/9d's live sequence used). */
    r = open_user_client(svc, CLIENT_TYPE_SURFACE, &surf);
    if (r != 0) { printf("open Surface connection failed: 0x%08x\n", (unsigned)r); return 1; }
    r = IOConnectMethodScalarIScalarO(surf, 7, 2, 0, 1, 0x0);
    if (r == 0) r = IOConnectMethodScalarIScalarO(surf, 7, 2, 0, 1, 0x20);
    if (r != 0) { printf("Surface set_id_mode failed: 0x%08x\n", (unsigned)r); IOServiceClose(surf); return 1; }
    memset(region, 0, sizeof region);
    *(UInt32 *)(region + 0) = 1; *(SInt16 *)(region + 8) = 64; *(SInt16 *)(region + 10) = 48; *(SInt16 *)(region + 16) = 64; *(SInt16 *)(region + 18) = 48;
    r = IOConnectMethodScalarIStructureI(surf, 9, 2, sizeof region, 0, 1, region);
    if (r != 0) { printf("Surface set_shape failed: 0x%08x\n", (unsigned)r); IOServiceClose(surf); return 1; }

    /* Prime the surface's slot-0 record with real backing memory - Tests/destructive/t3_gl_read_buffer.c's proven sequence (a 2D client binds
     * with the front-buffer requirement bit and locks/unlocks once). Without this, doIDCT's destPlaneIndex=-10 destination record's own base-
     * address field stays zero, which doIDCT reads back as NotReady (0xe00002d8) from a DIFFERENT check than the outer gate - confirmed via a
     * live VRAMPeek read (2026-10-06) showing the outer gate (boundSurface/hwUp/ringReady) was already fully satisfied while this still failed. */
    {
        io_connect_t twod = IO_OBJECT_NULL; UInt32 primeOut[0x30 / 4]; IOByteCount primeOsz = sizeof primeOut; int addr, size, tag;
        r = open_user_client(svc, CLIENT_TYPE_2D, &twod);
        if (r == 0) r = IOConnectMethodScalarIStructureO(twod, 0, 2, &primeOsz, 1, 0x800, primeOut);
        if (r == 0) r = IOConnectMethodScalarIScalarO(twod, 5, 1, 2, 0, &addr, &size);
        if (r == 0) r = IOConnectMethodScalarIScalarO(twod, 6, 1, 1, 0, &tag);
        if (r == 0) printf("surface primed via 2D lock_memory: addr=0x%x size=0x%x\n", addr, size);
        else printf("surface priming failed: 0x%08x\n", (unsigned)r);
        if (twod != IO_OBJECT_NULL) IOServiceClose(twod);
        if (r != 0) { IOServiceClose(surf); return 1; }
    }
    /* Empirically required (2026-10-06): calling doIDCT immediately after priming returned NotReady (0xe00002d8) consistently, even though a live
     * VRAMPeek read confirmed every gate doIDCT's source checks (bound surface, hardware-up, ring-ready, destination record populated) was already
     * satisfied - so something needs a moment to settle after the 2D priming call that isn't visible in any of those fields. A 20 s diagnostic hold
     * made it work every time; 1 s here is a deliberately generous, cheap margin, not the minimal delay (not worth more live cycles to shave down). */
    sleep(1);

    /* DVD bind only - deliberately no setup_buffers/lock_all_buffers, see the header comment. set_surface's bind is what starts the XDCT ring
     * (ATIR500DVDContext::start -> start_xdct_engine) and gives this connection a boundSurface, both of which doIDCT itself requires. */
    r = open_user_client(svc, CLIENT_TYPE_DVD, &dvd);
    if (r != 0) { printf("open DVD connection failed: 0x%08x\n", (unsigned)r); IOServiceClose(surf); return 1; }
    r = IOConnectMethodScalarIStructureI(dvd, 0, 3, 0, 1, 0, 0, NULL);
    if (r != 0) { printf("DVD set_surface bind failed: 0x%08x\n", (unsigned)r); goto cleanup; }

    if (holdSec > 0) { printf("HOLD %d s after bind (pid=%d) - attach a diagnostic now\n", holdSec, (int)getpid()); fflush(stdout); sleep(holdSec); }

    r = IOConnectMapMemory(dvd, 4, mach_task_self(), &streamAddr, &streamSize, kIOMapAnywhere);
    if (r != 0) { printf("map stream-0 buffer (memType 4) failed: 0x%08x\n", (unsigned)r); goto cleanup; }
    printf("stream-0 buffer mapped: addr=0x%lx size=%lu\n", (unsigned long)streamAddr, (unsigned long)streamSize);

    for (s = 0; s < nSizes && !bad; s++) {
        int mbCount = sizes[s];
        UInt32 in[16], out[16]; UInt32 dmaDwords; char name[64]; int liveBad = 0;

        dmaDwords = build_intra_stream((UInt32 *)streamAddr, mbCount);
        memset(in, 0, sizeof in);
        in[2] = (UInt32)-10;       /* destPlaneIndex: surface's own slot-0 record (section 9e), not a lock_all_buffers-allocated slot */
        in[3] = 0;                 /* planeSelector: stream 0 (intra), never anything else in this file */
        in[4] = dmaDwords;         /* dmaDwordCount */
        in[5] = 0x100a0;           /* engineFlagWord: 0x10080 | plane0 0x20, live-confirmed section 9d */
        in[6] = 0;                 /* planeModeWord: stream 0 */
        in[9] = (UInt32)((48 << 16) | 64); /* dimensionsHeightWidth */

        warmup();
        for (i = 0; i < warm; i++) { osz = 0; IOConnectMethodStructureIStructureO(dvd, 18, sizeof in, &osz, in, out); }
        for (i = 0; i < N; i++) {
            double t0, t1; osz = 0;
            t0 = now_us();
            r = IOConnectMethodStructureIStructureO(dvd, 18, sizeof in, &osz, in, out);
            t1 = now_us();
            samp[i] = t1 - t0;
            if (r != 0) { if (!liveBad) printf("doIDCT (%d MB) first unexpected code: 0x%08x\n", mbCount, (unsigned)r); liveBad++; }
        }
        if (liveBad) {
            printf("doIDCT (%d MB) returned an unexpected code %d of %d times - stopping the escalation here, not trying a larger size\n", mbCount, liveBad, N);
            bad++;
        } else {
            snprintf(name, sizeof name, "dvd.doIDCT.intra.%dmb", mbCount);
            report_metric(name, samp, N);
            /* liveness check after each size step before escalating - DVD check_stamps (sel 20), same convention as #87's measurement toolkit */
            {
                int both; r = IOConnectMethodScalarIScalarO(dvd, 20, 2, 1, 0, 0, &both);
                if (r != 0) { printf("post-%dmb liveness check (check_stamps) failed: 0x%08x - stopping here\n", mbCount, (unsigned)r); bad++; }
            }
        }
    }

cleanup:
    if (streamAddr) IOConnectUnmapMemory(dvd, 4, mach_task_self(), streamAddr);
    IOConnectMethodScalarIStructureI(dvd, 0, 3, 0, 0, 0, 0, NULL); /* detach */
    if (dvd != IO_OBJECT_NULL) IOServiceClose(dvd);
    if (surf != IO_OBJECT_NULL) IOServiceClose(surf);
    printf("%s (%d size step(s) failed)\n", bad ? "RESULT: FAIL" : "RESULT: PASS", bad);
    return bad ? 1 : 0;
}
