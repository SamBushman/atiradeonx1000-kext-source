/* Test for #95 (Surface surface_read_lock, sel 12 = surface_lock_options(this, 1, 2, data, size): read lock, lockOptions 2), issue #87 protocol. Same call shape and surface state as the
 * #123 panic (t3_surface_locks state A: set_id_mode(0, 0x4) only, lockOptions 0 on the baseline surface); this test makes ONE call, sel 12 on that state, and nothing else, so that if
 * the stock kernel panics (expected: the move_buffer_to_backing_store -> dealloc_surface -> ATIR500Memory::dealloc NULL deref of #123; corrected, see Tools/panic_symbolicate.py) the panic log is attributable to this selector alone.
 * The call is written to the write-ahead log (and the UDP mirror) before it is made. If it returns, an unlock (sel 1) is issued when it was granted and query_lock must report available. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL; kern_return_t r; int bad = 0, o; unsigned char data[0x44]; IOByteCount sz = sizeof data;
    T3CALL(t, r, "open Surface connection", open_user_client(svc, CLIENT_TYPE_SURFACE, &s));
    if (r != 0) return "DIVERGENCE";
    T3CALL(t, r, "Surface set_id_mode(0, 0x4) [harness baseline state A]", IOConnectMethodScalarIScalarO(s, 7, 2, 0, 0, 0x4)); bad += t3_expect(t, "state A", r, 0);
    memset(data, 0, sizeof data);
    T3CALL(t, r, "Surface sel12 surface_read_lock (lockOptions 2) [PANIC PATH, #123]", IOConnectMethodScalarIStructureO(s, 12, 0, &sz, data));
    dtest_note(t, "sel12 -> 0x%08x data[0]=0x%x data[4]=0x%x", (unsigned)r, ((UInt32 *)data)[0], ((UInt32 *)data)[4]);
    if (r == 0) { T3CALL(t, r, "Surface sel1 unlock", IOConnectMethodScalarIScalarO(s, 1, 1, 0, 0)); bad += t3_expect(t, "unlock", r, 0); }
    else if (r != TEST_kIOReturnCannotLock) { dtest_note(t, "unexpected lock code 0x%08x", (unsigned)r); bad++; }
    T3CALL(t, r, "Surface query_lock", IOConnectMethodScalarIScalarO(s, 11, 0, 0)); o = r; bad += t3_expect(t, "query_lock", o, 0);
    IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_surface_read_lock", 0, body); }
