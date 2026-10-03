/* *** HAZARD - DO NOT RE-RUN AS IS *** Run 1 (no declare_image) crashed on self+0x84 == NULL at ATIR500DVDContext::process_command_buffer+0x1e70 (DAR=0x14) - diagnosed and "fixed" by adding a
 * declare_image call (see the superseded note this replaces, still in git history). Run 2 (WITH declare_image, imgId 0xb000 returned) crashed AGAIN, at the EXACT SAME instruction (PC=0x5c0630,
 * DAR=0x14) - but this time self+0x84 is provably valid: 0x19, 0x1a, 0x1b and 0x1c all flushed successfully through that identical check first (confirmed via the reliable local .out log, not
 * the lossy UDP mirror: Tests/baseline/opcode/inject/panic_2026-10-03_t3_dvd_inject_run2.log). The crash happened on 0x1d specifically. Current understanding: either (a) this shared code
 * address computes a different base pointer per entry path and I haven't isolated which, or (b) 0x1d is the first of this group whose all-zero test record (index 0) now matches a REAL texture
 * (declare_image's imgId 0xb000 likely IS index 0) and proceeds deeper into real texture-bind/GART logic that 0x19-0x1c's same index-0 lookup never reached - not yet statically confirmed either
 * way. This is the fourth real G5 crash this session from DVD/GL/2D live testing. DO NOT RE-RUN until this is understood with actual disassembly of the divergent paths, not another guess. */
/* T3 test for #42 criterion 2 (DVD process_command_buffer opcodes - no real player ever opens a DVD context on this machine, #93), issue #100 protocol #87.
 * Exercises the 53 of 62 DVD opcodes whose stock handler was confirmed, via Tools/userspace/emu/kemu.py (PPC emulation of the real stock machine code, zero
 * hardware risk), to terminate safely and boundedly with a generous zero-filled 16-word record - no wild pointer advance, no self+0x104 touch, or (for 0x02/
 * 0x12 etc.) harmlessly bounded. NOT included here (left for future work, see Tests/pm4_opcode_gaps.md "DVD" section):
 *   - 0xb, 0xd, 0x18, 0x43, 0x44: read the context's 18-slot bound-texture array (self+0x104) with no null-check (same class as #125/V13) - needs a real
 *     declare_image (sel 8) + a slot-binding opcode (0x1b/0x1c/0x2a) first; real per-opcode slot/constant values cross-referenced from the VA driver's own
 *     emitter (Userspace/ATIRadeonX1000VADriver/ppc/part_001.c), not yet built into a live test.
 *   - 0x12: gated behind the accelerator's ring-active flag (self+0x8c, offset 0x22f*4) - a fresh connection never sets it, so it safely falls through; not
 *     separately verified live here, matching the established GL/2D precedent for hardware-gated paths.
 *   - 0x14, 0x3d, 0x46: the emulator sweep showed a wild buffer-pointer advance with a naive 16-word record - the real record shape for these is NOT what
 *     was guessed; left unexercised rather than retry a guess (see the "wrong record length" lesson from the GL/2D sessions - a wrong n, not necessarily a
 *     kext defect, and not safe to just try a bigger n blind).
 *   - 0x3e: no real emitter found anywhere in the VA driver (ppc or i386) - likely dead code, same resolution as GL's 0x36 (#125); not exercised.
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
