/* Diagnostic probe for #126's unresolved second crash: does opcode 0x1d crash on the VERY FIRST flush after declare_image (self+0x84 never actually readable for it),
 * or only after other texture-bind-family opcodes (0x19-0x1c) have already run (something degrades self+0x84 across flushes)? Isolates one variable: N = how many
 * of {0x19,0x1a,0x1b,0x1c} run before 0x1d. Crashes are an acceptable, expected outcome here - the goal is understanding exactly where the behavior changes, not
 * avoiding a crash. Each stage's own flush is logged via the write-ahead log before it runs, so a crash still pins down exactly which stage caused it. */
#include "t3common.h"
#include <mach/mach.h>
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; unsigned i;
    unsigned imgId = 0xffffffff; vm_address_t addr = 0; vm_size_t size = 0;
    const char *probeEnv = getenv("PROBE_N"); int PROBE_N = probeEnv ? atoi(probeEnv) : 0; /* how many of the FULL real pre-opcode sequence (0x02..0x17 then 0x19..0x1c, matching the original crashing run exactly) to run before the real 0x1d probe */
    static const unsigned pre[] = {0x02,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0c,0x13,0x15,0x16,0x17,0x19,0x1a,0x1b,0x1c};
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD declare_image(4,4)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, 4, 4, &imgId));
    bad += t3_expect(t, "declare_image", r, 0);
    dtest_note(t, "declare_image -> r=0x%08x imgId=0x%x PROBE_N=%d", (unsigned)r, imgId, PROBE_N);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "map the initial/flush command buffer (DVD memType 1)", IOConnectMapMemory(d, 1, mach_task_self(), &addr, &size, kIOMapAnywhere));
    bad += t3_expect(t, "map buffer", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    for (i = 0; i < (unsigned)PROBE_N; i++) {
        volatile unsigned *p = (volatile unsigned *)(addr + 0x1c); vm_address_t oldaddr = addr; vm_size_t nsz = 0; unsigned j;
        p[0] = (pre[i] << 24) | 16; for (j = 1; j < 16; j++) p[j] = 0; p[16] = 0;
        dtest_about(t, "pre-stage %u: inject 0x%02x then flush", i, pre[i]);
        addr = 0; r = IOConnectMapMemory(d, 1, mach_task_self(), &addr, &nsz, kIOMapAnywhere);
        dtest_result(t, r, "flush after pre-stage 0x%02x", pre[i]);
        { char line[200]; int k, o = 0; for (k = 0; k < 17 && o < 180; k++) o += snprintf(line+o, sizeof line-o, " %08x", ((volatile unsigned *)(oldaddr+0x1c))[k]);
          dtest_note(t, "pre-stage 0x%02x: flush r=0x%08x; words:%s", pre[i], (unsigned)r, line); }
        if (r != 0) { bad++; dtest_note(t, "pre-stage failed, stopping before the real probe"); IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
        size = nsz ? nsz : size;
    }
    {
        volatile unsigned *p = (volatile unsigned *)(addr + 0x1c); vm_address_t oldaddr = addr; vm_size_t nsz = 0; unsigned j;
        p[0] = (0x1d << 24) | 16; for (j = 1; j < 16; j++) p[j] = 0; p[16] = 0;
        dtest_about(t, "THE PROBE: inject 0x1d then flush, after %d pre-stage opcode(s)", PROBE_N);
        addr = 0; r = IOConnectMapMemory(d, 1, mach_task_self(), &addr, &nsz, kIOMapAnywhere);
        dtest_result(t, r, "flush after injecting 0x1d (PROBE_N=%d)", PROBE_N);
        { char line[200]; int k, o = 0; for (k = 0; k < 17 && o < 180; k++) o += snprintf(line+o, sizeof line-o, " %08x", ((volatile unsigned *)(oldaddr+0x1c))[k]);
          dtest_note(t, "0x1d (PROBE_N=%d): flush r=0x%08x; words:%s", PROBE_N, (unsigned)r, line); }
        if (r != 0) bad++;
    }
    T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_probe_1d", 0, body); }
