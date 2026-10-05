/* *** STATUS 2026-10-03 (see #126/#127) *** The opcode sequence and declare_image fix below are PROVEN CORRECT: this exact test, run unmodified on a G5 settled for 1h+ uptime, completed all 53
 * opcodes cleanly (PASS). Every crash since (at 0x1d, then at 0x07, then at 0x1d again, no consistent instruction) happened only on a FRESHLY-OPENED DVD connection, and is now explained by a
 * real vendor bug found in ATIRadeonX1000::start_xdct_engine() (issue #127): it runs on every DVD connection open, polls the IDCT ring for readiness, but reports success UNCONDITIONALLY even on
 * its own poll timeout. This experiment: open/close the DVD connection 3 throwaway times first (the IDCT ring hardware programming might genuinely settle after repeated attempts even though the
 * poll itself can't be trusted), THEN open the real connection and run the full sequence - testing whether warm-up avoids the race. Crashes remain an accepted, expected cost of this investigation
 * (standing instruction) - this is not marked HAZARD; proceed. */
/* T3 test for #42 criterion 2 (DVD process_command_buffer opcodes - no real player ever opens a DVD context on this machine, #93), issue #100 protocol #87.
 * Exercises the 53 of 62 DVD opcodes whose stock handler was confirmed, via Tools/userspace/emu/kemu.py (PPC emulation of the real stock machine code, zero
 * hardware risk), to terminate safely and boundedly with a generous zero-filled 16-word record - no wild pointer advance, no self+0x104 touch, or (for 0x02/
 * 0x12 etc.) harmlessly bounded. NOT included here (left for future work, see Tests/pm4_opcode_gaps.md "DVD" section):
 *   - 0xb, 0xd, 0x18, 0x43, 0x44: read the context's 18-slot bound-texture array (self+0x104) with no null-check (same class as #125/V13) - needs a real
 *     declare_image (sel 8) + a slot-binding opcode (0x1b/0x1c/0x2a) first; real per-opcode slot/constant values cross-referenced from the VA driver's own
 *     emitter (Userspace/ATIRadeonX1000VADriver/ppc/part_001.c), not yet built into a live test.
 *   - 0x12: gated behind the accelerator's ring-active flag (self+0x8c, offset 0x22f*4) - a fresh connection never sets it, so it safely falls through; not
 *     separately verified live here, matching the established GL/2D precedent for hardware-gated paths.
 *   - 0x14, 0x3d, 0x3e, 0x46: RESOLVED by static trace, not a record-shape guessing problem (idct_engine_findings.md 9x, pm4_opcode_gaps.md "resolved by
 *     static trace" section). All four write the identical register signature as 0x12's composite (0x1150-range offset/pitch, RB3D_DSTCACHE_CTLSTAT=10,
 *     0x138a-range) - they are syntactic variants (single-forward/single-backward/two-source-average) of the exact #142 firmware defect (completion stamp
 *     never posts). Permanently excluded, same reason as 0x12 itself: live-testing any of them would only reproduce the known hang for zero new information.
 *     0x3e additionally has no real emitter anywhere in the VA driver (ppc or i386) - unreachable from real software, like 0x36 (#125), though its kernel
 *     handler (unlike 0x36's) is real code in this same family, not dead code.
 * Each opcode gets its own flush (memType 1, both the initial buffer and the flush for DVD - IOATIR500DVDContext_ClientMemoryForType.cpp "type 1: the DVD
 * flush... path", same convention as GL, NOT 2D's split memType 0/1 bug), one at a time, with full readback. */
#include "t3common.h"
#include <mach/mach.h>
static const unsigned ops[] = {
    0x02,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0c,0x13,0x15,0x16,0x17,
    0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,
    0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,
    0x3f,0x42,0x47,
};
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; unsigned i, j;
    vm_address_t addr = 0; vm_size_t size = 0;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    { /* #127 experiment: warm up the IDCT ring (start_xdct_engine runs on every DVD-connection open) with a few throwaway open/close cycles before the real connection, in case its own readiness poll needs more than one attempt to genuinely settle - its own poll is known to report success unconditionally (issue #127), so this is testing whether REPEATED hardware programming helps even though the poll itself can't be trusted. */
      int w; io_connect_t warm;
      for (w = 0; w < 3; w++) {
          T3CALL(t, r, "warm-up: open DVD connection (throwaway)", open_user_client(svc, CLIENT_TYPE_DVD, &warm));
          if (r == KERN_SUCCESS) { dtest_about(t, "warm-up %d: close", w); IOServiceClose(warm); dtest_result(t, 0, "warm-up %d: closed", w); }
      }
    }
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    /* #126 fix: establish self+0x84 (shared allocator) BEFORE any opcode in the 0x19-0x2a texture-bind family. declare_image (sel 8): 3 scalar in (unused, width, height), 1 scalar out (image id). */
    { unsigned imgId = 0xffffffff;
      T3CALL(t, r, "DVD declare_image(4,4) - lazily creates the shared allocator (self+0x84)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, 4, 4, &imgId));
      bad += t3_expect(t, "declare_image", r, 0);
      dtest_note(t, "declare_image -> r=0x%08x imgId=0x%x", (unsigned)r, imgId);
      if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    }
    T3CALL(t, r, "map the initial/flush command buffer (DVD memType 1)", IOConnectMapMemory(d, 1, mach_task_self(), &addr, &size, kIOMapAnywhere));
    bad += t3_expect(t, "map buffer", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    for (i = 0; i < sizeof ops / sizeof ops[0]; i++) {
        volatile unsigned *p = (volatile unsigned *)(addr + 0x1c); vm_address_t oldaddr = addr; vm_size_t nsz = 0;
        p[0] = (ops[i] << 24) | 16;                 /* emulator-validated shape: n=16 words, zero-filled payload */
        for (j = 1; j < 16; j++) p[j] = 0;
        p[16] = 0;                                   /* terminator */
        dtest_about(t, "inject 0x%02x then flush (DVD memType 1)", ops[i]);
        addr = 0; r = IOConnectMapMemory(d, 1, mach_task_self(), &addr, &nsz, kIOMapAnywhere);
        dtest_result(t, r, "flush after injecting 0x%02x", ops[i]);
        { char line[300]; int k, o = 0;
          for (k = 0; k < 17 && o < 280; k++) o += snprintf(line + o, sizeof line - o, " %08x", ((volatile unsigned *)(oldaddr + 0x1c))[k]);
          dtest_note(t, "0x%02x: flush r=0x%08x; words after the kernel ran the buffer:%s", ops[i], (unsigned)r, line); }
        if (r != 0) { bad++; dtest_note(t, "flush failed, stopping"); break; }
        size = nsz ? nsz : size;
    }
    T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_inject", 0, body); }
