/* T3 test for #110 (2D swap_surface, sel 3) and the swap half of #112 (unlock_memory with a negative lockType), issue #100 / protocol #87.
 * Traced (IOATIR5002DContext_Surface.cpp, shipped 0xc960): swap_surface retries alloc_surfaces like lock_memory, then flush_surface(0xffffffff, 0) when surface+0xbfc bit 1 is
 * clear (a 4x4 blit into the displayed framebuffer region at the surface's origin - display-visible, hence T3) and returns the surface's tag (+0xbfc); NoResources
 * 0xe00002be when no buffer can be allocated. Run AFTER a screencapture (the runner takes one before and after). Registered 4x4 surface, bound through 2D set_surface. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; IOByteCount osz; unsigned char out[0x30]; int tag = -1;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    osz = sizeof out;
    T3CALL(t, r, "2D swap_surface(0) UNBOUND", IOConnectMethodScalarIScalarO(d, 3, 1, 1, 0, &tag)); bad += t3_expect(t, "swap unbound", r, 0xe00002be);
    T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
    if (r == KERN_SUCCESS) {
        tag = -1;
        T3CALL(t, r, "2D swap_surface(0) bound", IOConnectMethodScalarIScalarO(d, 3, 1, 1, 0, &tag));
        dtest_note(t, "swap -> r=0x%08x tag=0x%x (0 = success; NoResources 0xe00002be is the predicted reject)", (unsigned)r, (unsigned)tag);
        if (r != 0 && r != 0xe00002be) bad++;
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    }
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_swap", 0, body); }
