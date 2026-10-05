/* T3 test for #102 (DVD lock_all_buffers, sel 4) and DVD unlock_memory (sel 5), issue #100 / protocol #87. Traced (IOATIR500DVDContext_lock_all_buffers_Port.cpp, shipped 0xfdb0..): with a bound
 * surface the body copies 13 {address, pitch} pairs from the surface's buffers[10..22] (surface+0xb70 + idx*4 -> +8 / +0x18) into the 256-byte output; those pointers exist ONLY after
 * Surface::alloc_surfaces has run for those slots. alloc_surfaces runs inside lock_all_buffers when (surface+0xbf8 & this+0x88 & 0x207ffc00) != 0. this+0x88 is set by setup_buffers
 * (sel 21) as (param5 & 0xfffffc00) | 0x20000002, and surface+0xbf8 starts as 0x307fffff (IOATIR500Surface::start). So the call is only SAFE after setup_buffers with bits 10..22 set in
 * param5 (0x7ffc00): then the pending bits select the allocation. WITHOUT setup_buffers this+0x88 is 0, the allocation is skipped and the copy would dereference never-allocated buffer
 * pointers (a kernel NULL dereference): the test therefore never calls lock_all_buffers before setup_buffers, and checks the unbound / not-set-up forms only through the proven guards.
 * Sequence: bind the registered 4x4 surface, setup_buffers(0,0,16,16, 0x7ffc00), lock_all_buffers(0) -> 0 (13 pairs), a REPEAT lock_all_buffers while still locked (new, 2026-10-05 - #102's
 * other missing criterion), unlock_memory(0) -> 0, unlock_memory again -> the shipped code does not guard a second unlock beyond the surface pointer (it decrements the lock count again):
 * NOT called (unchanged from the original reasoning - a plausible real counter-corruption hazard, deliberately left untried rather than forced). Detach, with ioreg class-instance counts
 * before/after as the leak check #102 also asks for.
 * *** CORRECTION 2026-10-05: this file already ran once (phaseS log, 2026-10-02T04:14:11Z) and got rc=0 with EVERY buffer descriptor all-zero (address=0, pitch=0 for all 13 slots) -
 * success in the sense of a return code, but the allocation evidently did not happen for real. idct_engine_findings.md section 9d got genuine non-zero descriptors (slots 10-14 pitch
 * 0x100 etc.) using a real 64x48 surface and TWO setup_buffers calls (masks 0x27c00 then 0x37c00, matching the actual VA driver's own tail sequence) - this file's smaller 16x16/single-mask
 * setup never gave the allocator real work to do. Updated the surface size and setup_buffers calls below to match 9d's proven-real parameters, so the repeat-lock/leak-check additions
 * below are actually exercising a real allocation, not another all-zero no-op. */
#include "t3common.h"
#include <unistd.h>

#define NCLS 2
static const char *kClasses[NCLS] = { "ATIR500DVDContext", "ATIR500Surface" };
static int class_counts(int *out) {
    FILE *p = popen("/usr/sbin/ioreg -w0 -c ATIR500DVDContext -c ATIR500Surface 2>/dev/null", "r");
    char line[512]; int i;
    for (i = 0; i < NCLS; i++) out[i] = 0;
    if (!p) return -1;
    while (fgets(line, sizeof line, p)) {
        for (i = 0; i < NCLS; i++) { char tag[64]; snprintf(tag, sizeof tag, "<class %s", kClasses[i]); if (strstr(line, tag)) out[i]++; }
    }
    pclose(p); return 0;
}
static void log_counts(dtest_t *t, const char *label, int *c) {
    dtest_note(t, "class counts %s: ATIR500DVDContext=%d ATIR500Surface=%d", label, c[0], c[1]);
}

static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, tag = -1; IOByteCount osz; UInt32 out[64], out2[64];
    int before[NCLS], after[NCLS];
    class_counts(before); log_counts(t, "BEFORE", before);
    if (t3_surface(t, svc, &s, 64, 48) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    osz = sizeof out; memset(out, 0, sizeof out);
    T3CALL(t, r, "DVD lock_all_buffers(0) UNBOUND", IOConnectMethodScalarIStructureO(d, 4, 1, &osz, 0, out)); bad += t3_expect(t, "lock unbound", r, TEST_kIOReturnCannotLock);
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r == 0) {
        /* idct_engine_findings.md 9b/9c's proven-real sequence: two setup_buffers calls (0x27c00 then 0x37c00), 64x48 - gives the allocator real slots to fill. */
        T3CALL(t, r, "DVD setup_buffers(0,64,48,0,0x27c00)", IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 64, 48, 0, 0x27c00)); bad += t3_expect(t, "setup_buffers #1", r, 0);
        if (r == 0) { T3CALL(t, r, "DVD setup_buffers(0,64,48,0,0x37c00)", IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 64, 48, 0, 0x37c00)); bad += t3_expect(t, "setup_buffers #2", r, 0); }
        if (r == 0) {
            osz = sizeof out; memset(out, 0, sizeof out);
            T3CALL(t, r, "DVD lock_all_buffers(0) bound + set up", IOConnectMethodScalarIStructureO(d, 4, 1, &osz, 0, out));
            dtest_note(t, "lock_all_buffers #1 -> r=0x%08x outSize=%u", (unsigned)r, (unsigned)osz);
            for (i = 0; i < 13; i++) dtest_note(t, "buffer[%d] address=0x%x pitch=0x%x", 10 + i, (unsigned)out[i * 2], (unsigned)out[i * 2 + 1]);
            if (r == 0) {
                osz = sizeof out2; memset(out2, 0, sizeof out2);
                T3CALL(t, r, "DVD lock_all_buffers(0) REPEAT, already locked", IOConnectMethodScalarIStructureO(d, 4, 1, &osz, 0, out2));
                dtest_note(t, "lock_all_buffers #2 (repeat) -> r=0x%08x outSize=%u; same descriptors as #1: %s",
                           (unsigned)r, (unsigned)osz, memcmp(out, out2, sizeof out) == 0 ? "YES" : "NO (see buffer dumps)");
                if (memcmp(out, out2, sizeof out) != 0) for (i = 0; i < 13; i++) dtest_note(t, "repeat buffer[%d] address=0x%x pitch=0x%x", 10 + i, (unsigned)out2[i * 2], (unsigned)out2[i * 2 + 1]);
                if (r != 0 && r != TEST_kIOReturnCannotLock) bad++;
                T3CALL(t, r, "DVD unlock_memory(0)", IOConnectMethodScalarIScalarO(d, 5, 1, 1, 0, &tag)); bad += t3_expect(t, "unlock", r, 0);
            }
            else if (r != TEST_kIOReturnCannotLock) bad++;
        }
        T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    }
    IOServiceClose(d); IOServiceClose(s);
    usleep(300000);
    class_counts(after); log_counts(t, "AFTER (connection closed)", after);
    { int leaked = 0; for (i = 0; i < NCLS; i++) if (after[i] != before[i]) leaked = 1;
      dtest_note(t, "leak check (after vs before): %s", leaked ? "MISMATCH - see counts above" : "MATCH, nothing leaked");
      if (leaked) bad++;
    }
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_lock_buffers", 0, body); }
