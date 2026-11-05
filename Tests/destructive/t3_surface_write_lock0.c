/* Live confirmation of the #123 fix (issue #87 protocol; Phase R only - on STOCK this exact call panics: ATIR500Memory::dealloc, DAR 0xc, Tests/destructive/phaseS/panics/t3_surface_locks_panic_20261002.log).
 * State A (the harness baseline, set_id_mode(0, 0x4)): a panel surface whose attachment buffer is the accelerator's scanout record. write_lock_options(3) + unlock reproduce the earlier clean prefix, then ONE
 * write_lock_options(lockOptions 0) - the call that freed a bogus slot. Expected on the fixed rebuilt kext: no panic; the lock either succeeds (it maps a system-memory backing store copy of the scanout buffer,
 * ~8 MB, via copy_buffer_to_backing_store: a GPU DMA path never run live on this surface before) or returns CannotLock/NoResources. Whatever it returns, a granted lock is unlocked and query_lock must report available. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL; kern_return_t r; int bad = 0; unsigned char data[0x44]; IOByteCount sz;
    T3CALL(t, r, "open Surface connection", open_user_client(svc, CLIENT_TYPE_SURFACE, &s));
    if (r != 0) return "DIVERGENCE";
    T3CALL(t, r, "Surface set_id_mode(0, 0x4) [harness baseline state A]", IOConnectMethodScalarIScalarO(s, 7, 2, 0, 0, 0x4)); bad += t3_expect(t, "state A", r, 0);
    if (r == 0) {
        sz = sizeof data; memset(data, 0, sizeof data);
        T3CALL(t, r, "Surface sel3 write_lock_options(3)", IOConnectMethodScalarIStructureO(s, 3, 1, &sz, 3, data)); bad += t3_expect(t, "lock(3)", r, 0);
        dtest_note(t, "lock(3): data[5..7]=%x,%x,%x", ((UInt32 *)data)[5], ((UInt32 *)data)[6], ((UInt32 *)data)[7]);
        if (r == 0) { T3CALL(t, r, "unlock for sel3 write_lock_options(3)", IOConnectMethodScalarIScalarO(s, 4, 1, 0, 0)); bad += t3_expect(t, "unlock", r, 0); }
        sz = sizeof data; memset(data, 0, sizeof data);
        T3CALL(t, r, "Surface sel3 write_lock_options(0) - THE #123 CALL", IOConnectMethodScalarIStructureO(s, 3, 1, &sz, 0, data));
        dtest_note(t, "write_lock_options(0) -> 0x%08x data[0]=0x%x data[4]=0x%x data[5..7]=%x,%x,%x", (unsigned)r, ((UInt32 *)data)[0], ((UInt32 *)data)[4], ((UInt32 *)data)[5], ((UInt32 *)data)[6], ((UInt32 *)data)[7]);
        if (r == 0) { T3CALL(t, r, "unlock for sel3 write_lock_options(0)", IOConnectMethodScalarIScalarO(s, 4, 1, 0, 0)); bad += t3_expect(t, "unlock", r, 0); }
        else if (r != TEST_kIOReturnCannotLock) dtest_note(t, "non-zero lock code 0x%08x (recorded, not a panic)", (unsigned)r);
        T3CALL(t, r, "query_lock afterwards", IOConnectMethodScalarIScalarO(s, 11, 0, 0)); bad += t3_expect(t, "query_lock", r, 0);
    }
    IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_surface_write_lock0", 0, body); }
