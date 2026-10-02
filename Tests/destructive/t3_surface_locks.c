/* Test for #94 (Surface surface_write_lock_options, sel 3), #95 (surface_read_lock, sel 12) and #96 (surface_write_lock, sel 14), plus the lockOptions variants of the already-proven
 * surface_read_lock_options (sel 0), issue #87 protocol. Traced (IOATIR500Surface_surface_lock_options_Port.cpp / surface_unlock_options_Port.cpp, shipped 0x15d.. - 0x16360):
 *  - the lock state lives in surface+0xbd0 (read) / +0xbd1 (write); a second lock while held -> CannotLock 0xe00002cc; unlock (sel 1/4/13/15, options ignored) clears it, CannotLock when none.
 *  - without buffer memory (buffer+0x10 == 0) every lock returns CannotLock (the baseline reject). With memory: lockOptions 3 -> the "granted, pending" tail (state 2, no allocation);
 *    lockOptions 1 -> data[4] = pitch, data[0] = buffer address (+0xc0c), vtable +0x5fc and a bounded stamp wait; allocation (alloc_surfaces_retry) happens ONLY when
 *    (surface+0xc1c & 3) & surface+0xbf8 != 0, i.e. a bound context requires a buffer that is still pending; lockOptions 0 / 2 take the plain grant unless the surface has a backing store
 *    (surface+0xbf7, set only by set_shape_backing with an address: not done here), which is the only way into copy/move_buffer_to_backing_store (the GPU DMA path, left to #121 / a later run).
 * Two surface states: A = set_id_mode(0, 0x4) only (the harness baseline state); B = registered id 1 with a 4x4 shape whose buffer memory was allocated by a 2D lock_memory/unlock_memory(0)
 * (t3_2d_lock_unlock passed), the 2D connection still bound. Every lock that returns 0 is unlocked with the matching unlock selector and query_lock must then report available. Codes are
 * recorded (they are the observation); DIVERGENCE only for: an unlock that fails after a granted lock, or a lock state that does not clear. */
#include "t3common.h"
static int battery(dtest_t *t, io_connect_t s, const char *tag) {
    int bad = 0, k, o; kern_return_t r; unsigned char data[0x44]; IOByteCount sz; char m[160];
    /* lockOptions 0 / 2 on a surface with VRAM but no backing store reach move/copy_buffer_to_backing_store -> alloc_buffer_backing_store and PANICKED the stock kernel (#123, Tests/destructive/phaseS/panics/):
     * only the non-backing lockOptions 3 and 1 and the baseline read lock (shortcut path) remain; sel 12 (read_lock, lockOptions 2) is the same panic path and is not run. */
    struct { int sel; int opts; int scalarsIn; int unlockSel; int unlockScalars; const char *name; } c[] = {
        { 3, 3, 1, 4, 1, "sel3 write_lock_options(3)" }, { 3, 1, 1, 4, 1, "sel3 write_lock_options(1)" },
        { 14, 0, 0, 15, 0, "sel14 write_lock" },
        { 0, 3, 1, 1, 1, "sel0 read_lock_options(3)" }, { 0, 1, 1, 1, 1, "sel0 read_lock_options(1)" } };
    for (k = 0; k < (int)(sizeof c / sizeof c[0]); k++) {
        sz = sizeof data; memset(data, 0, sizeof data);
        snprintf(m, sizeof m, "[%s] Surface %s", tag, c[k].name); dtest_about(t, "%s", m);
        r = c[k].scalarsIn ? IOConnectMethodScalarIStructureO(s, c[k].sel, 1, &sz, c[k].opts, data) : IOConnectMethodScalarIStructureO(s, c[k].sel, 0, &sz, data);
        dtest_result(t, r, "%s", m);
        dtest_note(t, "%s -> 0x%08x data[0]=0x%x data[4]=0x%x data[5..7]=%x,%x,%x data[8]=0x%x", m, (unsigned)r, ((UInt32 *)data)[0], ((UInt32 *)data)[4], ((UInt32 *)data)[5], ((UInt32 *)data)[6], ((UInt32 *)data)[7], ((UInt32 *)data)[8]);
        if (r == 0) {
            snprintf(m, sizeof m, "[%s] unlock for %s", tag, c[k].name);
            T3CALL(t, r, m, c[k].unlockScalars ? IOConnectMethodScalarIScalarO(s, c[k].unlockSel, 1, 0, 0) : IOConnectMethodScalarIScalarO(s, c[k].unlockSel, 0, 0));
            bad += t3_expect(t, m, r, 0);
        } else if (r != TEST_kIOReturnCannotLock) { dtest_note(t, "unexpected lock code 0x%08x", (unsigned)r); bad++; }
        snprintf(m, sizeof m, "[%s] query_lock after %s", tag, c[k].name);
        T3CALL(t, r, m, IOConnectMethodScalarIScalarO(s, 11, 0, 0)); o = r; bad += t3_expect(t, m, o, 0);
    }
    return bad;
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, s2 = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, addr, size, tag; IOByteCount osz; unsigned char out[0x30];
    T3CALL(t, r, "open Surface connection A", open_user_client(svc, CLIENT_TYPE_SURFACE, &s));
    if (r != 0) return "DIVERGENCE";
    T3CALL(t, r, "Surface set_id_mode(0, 0x4) [harness baseline state A]", IOConnectMethodScalarIScalarO(s, 7, 2, 0, 0, 0x4)); bad += t3_expect(t, "state A", r, 0);
    if (r == 0) bad += battery(t, s, "A");
    IOServiceClose(s);
    if (t3_surface(t, svc, &s2, 4, 4) != 0) return "DIVERGENCE";
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r == 0) {
        osz = sizeof out;
        T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
        T3CALL(t, r, "2D lock_memory(0) allocates the surface memory", IOConnectMethodScalarIScalarO(d, 5, 1, 2, 0, &addr, &size)); bad += t3_expect(t, "2D lock", r, 0);
        if (r == 0) { T3CALL(t, r, "2D unlock_memory(0)", IOConnectMethodScalarIScalarO(d, 6, 1, 1, 0, &tag)); bad += t3_expect(t, "2D unlock", r, 0); }
        bad += battery(t, s2, "B");
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
        IOServiceClose(d);
    }
    IOServiceClose(s2);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_surface_locks", 0, body); }
