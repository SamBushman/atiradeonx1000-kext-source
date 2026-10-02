/* T3 test for the swap half of #112 (2D unlock_memory, sel 6, negative lockType), issue #100 / protocol #87. Traced (IOATIR5002DContext_Surface.cpp, shipped 0xcf30): after a successful
 * write unlock, a NEGATIVE lockType makes unlock_memory call swap_surface(lockType, &tag) (the display flip of t3_2d_swap, #110, which passed with a screenshot-identical result).
 * Sequence: bind the registered 4x4 surface, lock_memory(0), unlock_memory(0x80000000), detach. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; IOByteCount osz; unsigned char out[0x30]; int addr = -1, size = -1, tag = -1;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    osz = sizeof out;
    T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
    if (r == KERN_SUCCESS) {
        T3CALL(t, r, "2D lock_memory(0)", IOConnectMethodScalarIScalarO(d, 5, 1, 2, 0, &addr, &size)); bad += t3_expect(t, "lock", r, 0);
        if (r == 0) {
            T3CALL(t, r, "2D unlock_memory(0x80000000) -> unlock then swap_surface", IOConnectMethodScalarIScalarO(d, 6, 1, 1, (int)0x80000000, &tag));
            dtest_note(t, "unlock+swap -> r=0x%08x tag=0x%x", (unsigned)r, (unsigned)tag);
            if (r != 0) bad++;
        }
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    }
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_unlock_swap", 0, body); }
