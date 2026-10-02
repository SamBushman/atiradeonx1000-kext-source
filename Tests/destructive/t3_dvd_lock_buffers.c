/* T3 test for #102 (DVD lock_all_buffers, sel 4) and DVD unlock_memory (sel 5), issue #100 / protocol #87. Traced (IOATIR500DVDContext_lock_all_buffers_Port.cpp, shipped 0xfdb0..): with a bound
 * surface the body copies 13 {address, pitch} pairs from the surface's buffers[10..22] (surface+0xb70 + idx*4 -> +8 / +0x18) into the 256-byte output; those pointers exist ONLY after
 * Surface::alloc_surfaces has run for those slots. alloc_surfaces runs inside lock_all_buffers when (surface+0xbf8 & this+0x88 & 0x207ffc00) != 0. this+0x88 is set by setup_buffers
 * (sel 21) as (param5 & 0xfffffc00) | 0x20000002, and surface+0xbf8 starts as 0x307fffff (IOATIR500Surface::start). So the call is only SAFE after setup_buffers with bits 10..22 set in
 * param5 (0x7ffc00): then the pending bits select the allocation. WITHOUT setup_buffers this+0x88 is 0, the allocation is skipped and the copy would dereference never-allocated buffer
 * pointers (a kernel NULL dereference): the test therefore never calls lock_all_buffers before setup_buffers, and checks the unbound / not-set-up forms only through the proven guards.
 * Sequence: bind the registered 4x4 surface, setup_buffers(0,0,16,16, 0x7ffc00), lock_all_buffers(0) -> 0 (13 pairs), unlock_memory(0) -> 0, unlock_memory again -> the shipped code does not guard a
 * second unlock beyond the surface pointer (it decrements the lock count again): NOT called. Detach. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, tag = -1; IOByteCount osz; UInt32 out[64];
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    osz = sizeof out; memset(out, 0, sizeof out);
    T3CALL(t, r, "DVD lock_all_buffers(0) UNBOUND", IOConnectMethodScalarIStructureO(d, 4, 1, &osz, 0, out)); bad += t3_expect(t, "lock unbound", r, TEST_kIOReturnCannotLock);
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r == 0) {
        T3CALL(t, r, "DVD setup_buffers(0,0,16,16, 0x7ffc00)", IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 0, 16, 16, 0x7ffc00)); bad += t3_expect(t, "setup_buffers", r, 0);
        if (r == 0) {
            osz = sizeof out; memset(out, 0, sizeof out);
            T3CALL(t, r, "DVD lock_all_buffers(0) bound + set up", IOConnectMethodScalarIStructureO(d, 4, 1, &osz, 0, out));
            dtest_note(t, "lock_all_buffers -> r=0x%08x outSize=%u", (unsigned)r, (unsigned)osz);
            for (i = 0; i < 13; i++) dtest_note(t, "buffer[%d] address=0x%x pitch=0x%x", 10 + i, (unsigned)out[i * 2], (unsigned)out[i * 2 + 1]);
            if (r == 0) { T3CALL(t, r, "DVD unlock_memory(0)", IOConnectMethodScalarIScalarO(d, 5, 1, 1, 0, &tag)); bad += t3_expect(t, "unlock", r, 0); }
            else if (r != TEST_kIOReturnCannotLock) bad++;
        }
        T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    }
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_lock_buffers", 0, body); }
