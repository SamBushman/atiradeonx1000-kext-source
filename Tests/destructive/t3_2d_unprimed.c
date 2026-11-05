/* Live confirmation of the #152 fix (issue #87 protocol; Phase R only - on STOCK the first image record panics the kernel: self+0x88 (sharedAllocator) is NULL until declare_image/create_image/create_transfer, DAR 0x14).
 * t3_2d_inject without its declare_image priming: the six affected image opcodes 0x03/0x04/0x07/0x08/0x13/0x10 with an invalid id (0xdead), each followed by the 0x07 discard guard. Expected on the fixed rebuilt kernel: each stream is
 * aborted through the vendor's own invalid-reference exit; no panic. */
#include "t3common.h"
#include <mach/mach.h>
typedef struct { const char *name; unsigned nw; unsigned w[8]; } rec_t;
static const rec_t recs[] = {
    { "0x03 (image, invalid id)",          2, { 0x03000002, 0xdead } },
    { "0x04 (image, invalid id)",          2, { 0x04000002, 0xdead } },
    { "0x07 (image, invalid id)",          2, { 0x07000002, 0xdead } },   /* the sixth affected opcode (#152); here it is also the trailing guard, so the stream is 0x07,0x07 */
    { "0x08 (image, invalid id)",          2, { 0x08000002, 0xdead } },
    { "0x13 (image, invalid id)",          6, { 0x13000006, 0xdead, 0, 0, 0, 0 } },
    { "0x10 (image, invalid id)",          4, { 0x10000004, 0xdead, 0, 0 } },
};
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; unsigned i, j; IOByteCount osz; unsigned char out[0x30];
    vm_address_t addr = 0; vm_size_t size = 0;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    osz = sizeof out;
    T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    /* #152: deliberately NO declare_image - self+0x88 (sharedAllocator) stays NULL, the state that panicked the stock kernel (DAR 0x14). */
    /* (removed for #152) establish self+0x88 (sharedAllocator) BEFORE any flush can reach an image-record opcode. declare_image(sel 8): 3 scalar in (unused, width, height), 1 scalar out (image id). */
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
        if (r != 0) { bad++; dtest_note(t, "flush returned 0x%08x (recorded; the stream was aborted)", (unsigned)r); }
        size = nsz ? nsz : oldsize;
    }
    T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_unprimed", 0, body); }
