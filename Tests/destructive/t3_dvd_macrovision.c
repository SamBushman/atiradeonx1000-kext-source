/* Test for #90 (DVD set_macrovision, sel 16, scalars attribute, value), issue #87 protocol. Traced (ATIR500DVDContext_set_macrovision_Port.cpp, shipped 0x35010): needs a BOUND surface (the unbound call
 * is the #43 NULL-dereference panic and is NEVER made here); getFramebufferIndex() returns 0 or 1 (loop over two panels, never out of range), the panel's framebuffer is safe-cast to IONDRVFramebuffer
 * (NULL -> 0xe00002c0) and its vtable +0x70c is called with (attribute, &value). The pair comes from the real vendor client: ATIRadeonX1000VADriver.bundle (tiger-hd-pull) wrapper at 0x5280 sends
 * selector 16 with attribute 0x92 in scalar 0 and the caller's value in scalar 1 (disassembly in issue #90). Value 0 = macrovision off, so the call only restores the default. Phase A only: bound to the
 * registered 4x4 surface (proven set_surface(1,0,0)); no enable phase. Expected 0 or 0xe00002c0. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0;
    if (t3_surface(t, svc, &s, 4, 4) != 0) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != 0) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r == 0) {
        T3CALL(t, r, "DVD set_macrovision(sel16, attribute 0x92, value 0) bound", IOConnectMethodScalarIScalarO(d, 16, 2, 0, 0x92, 0));
        dtest_note(t, "set_macrovision -> 0x%08x (0 = accepted; 0xe00002c0 = the framebuffer is not an NDRV one)", (unsigned)r);
        if (r != 0 && r != 0xe00002c0) bad++;
        T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    }
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_macrovision", 0, body); }
