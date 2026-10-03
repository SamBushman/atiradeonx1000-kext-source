/* *** FIXED 2026-10-03, see issue #124 *** Run 1 made the G5 stop answering ssh/ping: panic.log showed ATIR5002DContext::process_command_buffer+0x3e0 null-dereferencing self+0x88 (sharedAllocator),
 * which this project's own headers already documented as "lazily created via create_shared() on first texture/transfer allocation" (Headers/IOATIR5002DContext.h:146) - a connection that never
 * calls declare_image/create_image has a null self+0x88 for its whole life, and process_command_buffer's image-record handlers (0x03/0x04/0x07/0x08/0x10/0x13, including this test's own 0x07
 * discard guard) dereference it unconditionally. Fix: call declare_image (selector 8) ONCE right after binding, before any flush - it lazily calls create_shared() when self+0x88 is null
 * (Sources/IOATIR5002DContext_declare_image_Port.cpp:40-47), a plain `new IOATIR500Shared()` + init wired to the already-valid self+0x94/self+0x78, no further hazard. Also fixed the secondary bug:
 * memType 1 returns self+0xbc (a separate, unrelated per-connection descriptor, re-initialised to 0x1000 - IOATIR5002DContext_clientMemoryForType_Port.cpp:61-63), NOT the buffer
 * process_command_buffer scans (self+0xac, returned only by memType 0's ping-pong swap); the first buffer to write into now comes from memType 0 directly. */
/* T3 test for #42 criterion 2 (2D process_command_buffer opcodes no real consumer emits on this machine), issue #100 protocol #87.
 * A 2D connection bound to a 4x4 surface (as t3_2d_swap) gets its command buffer from IOConnectMapMemory(2D, memType 1); this test writes ONE hand-built record at buffer+0x1c, the
 * discard guard behind it, and submits with the flush map (memType 0), then reads the first words back from the (still mapped) old buffer: the kernel rewrites every record in place,
 * so the rewritten words are the observable result, compared with the dispatcher's source (Sources/ATIR5002DContext_process_command_buffer_Port.cpp).
 * DISCARD GUARD: record 0x07 with an out-of-range image id jumps to LAB_00033420 (pending word count := 0, loop ends), so the kernel runs the handler of the record before it but submits 0 words to
 * the GPU; nothing hand-built ever reaches the ring. Records whose handler never reaches the guard themselves (0x02 returns 1) are still followed by it.
 * Ids are deliberately invalid (0xdead): 0x03/0x04/0x07/0x08/0x13/0x10 take the invalid-image branch, 0x0b/0x0c use find_surface_for_id (NULL for 0xdead -> display surface 0), 0x09/0x0a/0x11 use index 0,
 * 0x0d/0x0e/0x12 the context's current surface. Valid-image branches need a declared image and are not covered here. */
#include "t3common.h"
#include <mach/mach.h>
typedef struct { const char *name; unsigned nw; unsigned w[8]; } rec_t;
static const rec_t recs[] = {
    { "0x05 (nop + clear image ref)",      1, { 0x05000001 } },
    { "0x06 (8 nops)",                     8, { 0x06000008 } },
    { "0x03 (image, invalid id)",          2, { 0x03000002, 0xdead } },
    { "0x04 (image, invalid id)",          2, { 0x04000002, 0xdead } },
    { "0x08 (image, invalid id)",          2, { 0x08000002, 0xdead } },
    { "0x13 (image, invalid id)",          6, { 0x13000006, 0xdead, 0, 0, 0, 0 } },
    { "0x10 (image, invalid id)",          4, { 0x10000004, 0xdead, 0, 0 } },
    { "0x09 (surface index 0, 6 words)",   6, { 0x09000006, 0, 0, 0, 0, 0 } },
    { "0x0a (surface index 0, 2 words)",   2, { 0x0a000002, 0 } },
    { "0x0b (surface id 0xdead, 6 words)", 6, { 0x0b000006, 0xdead, 0, 0, 0, 0 } },
    { "0x0c (surface id 0xdead, 2 words)", 2, { 0x0c000002, 0xdead } },
    { "0x0d (current surface, 6 words)",   6, { 0x0d000006, 0, 0, 0, 0, 0 } },
    { "0x0e (current surface, 2 words)",   2, { 0x0e000002, 0 } },
    { "0x11 (surface index 0, 4 words)",   4, { 0x11000004, 0, 0, 0 } },
    { "0x12 (current surface, 4 words)",   4, { 0x12000004, 0, 0, 0 } },
    { "0x02 (end marker, returns 1)",      1, { 0x02000001 } },
};
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; unsigned i, j; IOByteCount osz; unsigned char out[0x30]; unsigned imgId = 0xffffffff;
    vm_address_t addr = 0; vm_size_t size = 0;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    osz = sizeof out;
    T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    /* #124 fix: establish self+0x88 (sharedAllocator) BEFORE any flush can reach an image-record opcode. declare_image(sel 8): 3 scalar in (unused, width, height), 1 scalar out (image id). */
    T3CALL(t, r, "2D declare_image(4,4) - lazily creates sharedAllocator (self+0x88)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, 4, 4, &imgId));
    bad += t3_expect(t, "declare_image", r, 0);
    dtest_note(t, "declare_image -> r=0x%08x imgId=0x%x", (unsigned)r, imgId);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    /* #124 fix: memType 1 returns self+0xbc, NOT the buffer process_command_buffer scans - get the real one (self+0xac) from memType 0 directly. */
    T3CALL(t, r, "map the initial command buffer (memType 0)", IOConnectMapMemory(d, 0, mach_task_self(), &addr, &size, kIOMapAnywhere)); bad += t3_expect(t, "map buffer", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    dtest_note(t, "initial buffer addr=0x%lx size=0x%lx header words: %08x %08x %08x %08x %08x %08x %08x then stream %08x %08x", (unsigned long)addr, (unsigned long)size,
               ((unsigned *)addr)[0], ((unsigned *)addr)[1], ((unsigned *)addr)[2], ((unsigned *)addr)[3], ((unsigned *)addr)[4], ((unsigned *)addr)[5], ((unsigned *)addr)[6], ((unsigned *)addr)[7], ((unsigned *)addr)[8]);
    for (i = 0; i < sizeof recs / sizeof recs[0]; i++) {
        volatile unsigned *p = (volatile unsigned *)(addr + 0x1c); vm_address_t oldaddr = addr; vm_size_t nsz = 0, oldsize = size; unsigned n = recs[i].w[0] & 0xffffff;
        for (j = 0; j < n; j++) p[j] = j < recs[i].nw ? recs[i].w[j] : 0;
        p[n] = 0x07000002; p[n + 1] = 0xdead; p[n + 2] = 0;                    /* the discard guard, then the terminator */
        dtest_about(t, "inject %s then flush (2D memType 0)", recs[i].name);
        addr = 0; r = IOConnectMapMemory(d, 0, mach_task_self(), &addr, &nsz, kIOMapAnywhere);
        dtest_result(t, r, "flush after injecting %s", recs[i].name);
        { char line[400]; int k, o = 0;
          for (k = 0; k < (int)n + 2 && k < 12 && o < 360; k++) o += snprintf(line + o, sizeof line - o, " %08x", ((volatile unsigned *)(oldaddr + 0x1c))[k]);
          dtest_note(t, "%s: flush r=0x%08x; words after the kernel ran the buffer:%s", recs[i].name, (unsigned)r, line); }
        if (r != 0) { bad++; dtest_note(t, "flush failed, stopping"); break; }
        size = nsz ? nsz : oldsize;
    }
    T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_inject", 0, body); }
