/* Test for #97 (Surface surface_flush, sel 10: panelMask a, b), issue #87 protocol. Traced (IOATIR500Surface_surface_flush_Port.cpp, flush_surface_Port.cpp): surface_flush takes the accelerator
 * lock, calls alloc_surfaces_retry(surface+0xc1c & 3, 0) - ALLOCATES only when a bound context requires a buffer that is still pending ((bf8 & 0xc1c&3) != 0), which is not the case for a
 * surface no context is bound to or whose buffer is already allocated - then flush_surface(a, b): for each panel whose bit is set in `a` and whose per-panel flag (surface+0xcac+i*0x94) is set, vtable +0x5d4(panel, b)
 * (the flush of the surface into that panel's framebuffer: display-visible); a == 0 flushes nothing. Then an accelerator stamp wait (+0x54c, bounded). Phase A: a = 0 on a fresh registered 4x4 surface
 * (no allocation, no panel). Phase B: a = 1, b = 0 on the surface state of t3_2d_swap (2D-bound, buffer memory allocated by lock/unlock), i.e. the same flush_surface(.., 0) that swap_surface already ran
 * live with identical screenshots. The allocation-requesting Phase C of the issue is not needed: the allocating path (alloc_surfaces_retry) is the 2D lock path that passed in t3_2d_lock_unlock. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, addr, size, tag; IOByteCount osz; unsigned char out[0x30];
    if (t3_surface(t, svc, &s, 4, 4) != 0) return "DIVERGENCE";
    T3CALL(t, r, "Surface surface_flush(sel10, a=0, b=0) Phase A", IOConnectMethodScalarIScalarO(s, 10, 2, 0, 0, 0)); bad += t3_expect(t, "flush A", r, 0);
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r == 0) {
        osz = sizeof out;
        T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
        T3CALL(t, r, "2D lock_memory(0) allocates the surface memory", IOConnectMethodScalarIScalarO(d, 5, 1, 2, 0, &addr, &size)); bad += t3_expect(t, "2D lock", r, 0);
        if (r == 0) { T3CALL(t, r, "2D unlock_memory(0)", IOConnectMethodScalarIScalarO(d, 6, 1, 1, 0, &tag)); bad += t3_expect(t, "2D unlock", r, 0); }
        T3CALL(t, r, "Surface surface_flush(sel10, a=1, b=0) Phase B", IOConnectMethodScalarIScalarO(s, 10, 2, 0, 1, 0)); bad += t3_expect(t, "flush B", r, 0);
        T3CALL(t, r, "Surface surface_flush(sel10, a=0, b=0) again", IOConnectMethodScalarIScalarO(s, 10, 2, 0, 0, 0)); bad += t3_expect(t, "flush again", r, 0);
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
        IOServiceClose(d);
    }
    IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_surface_flush", 0, body); }
