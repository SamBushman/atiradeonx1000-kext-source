/* T3 test for #101 (2D lock_memory, sel 5) and the lock/unlock half of #112 (2D unlock_memory, sel 6), issue #100 / protocol #87.
 * Traced (IOATIR5002DContext_Surface.cpp, shipped 0xcc80 / 0xcf30): lock_memory(lockType) -> alloc_surfaces retry loop (<= 1000 tries with IOSleep(1)), maps the surface's
 * memory descriptor into the caller's task, takes the surface write lock; outputs (address, size); CannotLock 0xe00002cc when no buffer is ready. unlock_memory(lockType)
 * releases the write lock and ONLY swaps (flips the display) when lockType is negative: lockType 0 never reaches swap_surface (that is t3_2d_swap, #110). Registered
 * 4x4 surface bound through 2D set_surface(1, 0x800). The test never writes to the mapped address. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i; IOByteCount osz; unsigned char out[0x30]; int addr = -1, size = -1, tag = -1;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    osz = sizeof out;
    T3CALL(t, r, "2D lock_memory(0) UNBOUND", IOConnectMethodScalarIScalarO(d, 5, 1, 2, 0, &addr, &size)); bad += t3_expect(t, "lock unbound", r, TEST_kIOReturnCannotLock);
    T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
    if (r == KERN_SUCCESS) {
        for (i = 0; i < 2; i++) {
            addr = -1; size = -1;
            T3CALL(t, r, "2D lock_memory(0) bound", IOConnectMethodScalarIScalarO(d, 5, 1, 2, 0, &addr, &size));
            dtest_note(t, "lock #%d -> r=0x%08x addr=0x%x size=0x%x (CannotLock 0xe00002cc is the predicted reject when the surface has no ready buffer)", i, (unsigned)r, (unsigned)addr, (unsigned)size);
            if (r == 0) {
                T3CALL(t, r, "2D unlock_memory(0) after a successful lock", IOConnectMethodScalarIScalarO(d, 6, 1, 1, 0, &tag)); bad += t3_expect(t, "unlock", r, 0);
            } else if (r != TEST_kIOReturnCannotLock) { bad++; break; }
            else break;
        }
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    }
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_lock_unlock", 0, body); }
