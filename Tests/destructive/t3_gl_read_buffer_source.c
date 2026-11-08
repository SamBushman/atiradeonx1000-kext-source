/* EXPERIMENT (not one of the 27 T3 checklist tests; Nov 7 2026): where do the bytes that GL read_buffer (sel 7) and Surface surface_read (sel 5) write come from, and are they stable?
 * Gap recorded in phaseS_rerun/EVIDENCE.md: t3_gl_read_buffer / t3_surface_read only print the first 8 bytes and only once, immediately after the call returns; the #158 comment says the call does NOT wait for the GPU copy,
 * so a sample taken at return time may be partial, and nothing shows what the bytes are. This test records, in ONE session on the same surface (set-up identical to t3_gl_read_buffer: Surface 4x4 id 1, 2D bind mode 0x800,
 * lock_memory(0)/unlock_memory(0), GL bind mode 0x800):
 *   c1 read_buffer prefill 0xAA, c2 read_buffer prefill 0x55, c3 surface_read prefill 0xAA, c4 surface_read prefill 0x55, c5 read_buffer prefill 0xAA again.
 * After each call the 64 KB destination is sampled at 0, 50, 500 and 2000 ms and every changed byte is logged as offset:value (a byte equal to its prefill is invisible, hence two prefills; the analyser unions them).
 * Questions it answers (Tools/t3_read_buffer_source_analyze.py reads the log and the before/after screenshots that Tools/t3_experiment_one.sh takes on the G5):
 *   1. Does the content change after the call returns (async GPU copy)?  -> samples at 0/50/500/2000 ms differ.
 *   2. Is it repeatable inside one session?  -> c1 vs c2 vs c5 (read_buffer), c3 vs c4 (surface_read).
 *   3. Do read_buffer and surface_read return the same bytes (same buffer record)?  -> c1/c2/c5 vs c3/c4.
 *   4. Are the bytes pixels of the screen?  -> the analyser searches the before/after screenshots for the written byte runs (both channel orders).
 *   5. Does the answer depend on the kext?  -> run on stock and on rebuilt, 2 boots each (one test per boot).
 * Nothing is dereferenced through lock_memory's returned address (its type/validity as a user pointer is not established); addr/size are only logged. No write to the surface, same calls as the two existing tests. */
#include "t3common.h"
#include <stdlib.h>
#define SZ 0x10000
static int g_fail;
/* log every changed byte (up to 64) of buf against fill; returns the number of changed bytes */
static int sample(dtest_t *t, int call, const char *kind, unsigned fill, int ms, kern_return_t r, const unsigned char *buf) {
    int i, n = 0, inside = 0, outside = 0, listed = 0; char list[900]; size_t used = 0; list[0] = 0;
    for (i = 0; i < SZ; i++) if (buf[i] != fill) {
        n++; if (i < 4 * 64) inside++; else outside++;
        if (listed < 64 && used + 12 < sizeof list) { used += (size_t)snprintf(list + used, sizeof list - used, "%x:%02x,", (unsigned)i, buf[i]); listed++; }
    }
    dtest_note(t, "obs call=%d kind=%s fill=%02x t=%dms r=0x%08x changed=%d inside=%d outside=%d list=%s", call, kind, fill, ms, (unsigned)r, n, inside, outside, list);
    if (outside) g_fail++;
    return n;
}
static void sample_over_time(dtest_t *t, int call, const char *kind, unsigned fill, kern_return_t r, const unsigned char *buf) {
    sample(t, call, kind, fill, 0, r, buf); usleep(50 * 1000);
    sample(t, call, kind, fill, 50, r, buf); usleep(450 * 1000);
    sample(t, call, kind, fill, 500, r, buf); usleep(1500 * 1000);
    sample(t, call, kind, fill, 2000, r, buf);
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL, g = IO_OBJECT_NULL; kern_return_t r; int addr = -1, size = -1, tag = -1, k;
    IOByteCount osz, zero = 0; unsigned char out[0x30]; UInt32 inrb[7], insr[6]; unsigned char *buf = (unsigned char *)valloc(SZ);
    static const struct { const char *kind; unsigned fill; } plan[5] = { { "read_buffer", 0xAA }, { "read_buffer", 0x55 }, { "surface_read", 0xAA }, { "surface_read", 0x55 }, { "read_buffer", 0xAA } };
    if (!buf) return "DIVERGENCE";
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) { free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); free(buf); return "DIVERGENCE"; }
    osz = sizeof out;
    T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out));
    if (r == 0) {
        T3CALL(t, r, "2D lock_memory(0) allocates the surface memory", IOConnectMethodScalarIScalarO(d, 5, 1, 2, 0, &addr, &size));
        dtest_note(t, "lock_memory(0) -> r=0x%08x addr=0x%x size=0x%x (logged only, never dereferenced)", (unsigned)r, (unsigned)addr, (unsigned)size);
        if (r == 0) T3CALL(t, r, "2D unlock_memory(0)", IOConnectMethodScalarIScalarO(d, 6, 1, 1, 0, &tag));
        T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
        T3CALL(t, r, "GL set_surface(1, modeBits 0x800, 0, 0) binds", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 1, 0x800, 0, 0, NULL));
        for (k = 0; k < 5; k++) {
            memset(buf, (int)plan[k].fill, SZ);
            if (plan[k].kind[0] == 'r') {
                inrb[0] = 0; inrb[1] = 0; inrb[2] = 4; inrb[3] = 4; inrb[4] = 1; inrb[5] = (UInt32)buf; inrb[6] = 64;
                T3CALL(t, r, "GL read_buffer(sel7, rect {0,0,4,4}, selector 1, row_bytes 64)", IOConnectMethodStructureIStructureO(g, 7, sizeof inrb, &zero, inrb, NULL));
            } else {
                insr[0] = 0; insr[1] = 0; insr[2] = 4; insr[3] = 4; insr[4] = (UInt32)buf; insr[5] = 64;
                T3CALL(t, r, "Surface surface_read(sel5, rect {0,0,4,4}, row_bytes 64)", IOConnectMethodStructureIStructureO(s, 5, sizeof insr, &zero, insr, NULL));
            }
            if (r != 0 && r != TEST_kIOReturnCannotLock) g_fail++;
            sample_over_time(t, k + 1, plan[k].kind, plan[k].fill, r, buf);
        }
        T3CALL(t, r, "GL set_surface(0) detaches", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 0, 0, 0, 0, NULL));
        IOServiceClose(g);
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    }
    IOServiceClose(d); IOServiceClose(s); free(buf);
    return g_fail ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_read_buffer_source", 0, body); }
