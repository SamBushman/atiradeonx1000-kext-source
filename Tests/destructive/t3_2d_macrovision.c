/* Test for #89 (2D set_macrovision, sel 15, 1 scalar: enable), issue #87 protocol. Traced (IOATIR5002DContext_Surface.cpp, shipped 0xc2e0): under the accelerator lock, for each of the accelerator's
 * panels (+0xcc) whose framebuffer (accelerator+0xd4+i*0x20) safe-casts to IONDRVFramebuffer, calls its vtable +0x70c with attribute 0x92 and a pointer to `enable`; returns 0 if ANY display accepted it,
 * else 0xe00002c0; nothing is written in the kext itself. Attribute 0x92 is the same one the vendor VA bundle sends for DVD macrovision (ATIRadeonX1000VADriver, wrapper at 0x5280: attribute 0x92 in
 * scalar 0, caller value in scalar 1). Phase A: enable = 0 (disable something already off). Phase B/C only if A returned 0 (a display accepts the attribute): enable = 1 then immediately 0 again to restore;
 * the main display's pixels must be identical before/after (the runner's screenshots). */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0;
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != 0) return "DIVERGENCE";
    T3CALL(t, r, "2D set_macrovision(sel15, 0) Phase A", IOConnectMethodScalarIStructureI(d, 15, 1, 0, 0, NULL));
    dtest_note(t, "Phase A -> 0x%08x (0 = a display accepted attribute 0x92; 0xe00002c0 = none did)", (unsigned)r);
    if (r != 0 && r != 0xe00002c0) bad++;
    if (r == 0) {
        T3CALL(t, r, "2D set_macrovision(sel15, 1) Phase B", IOConnectMethodScalarIStructureI(d, 15, 1, 0, 1, NULL)); dtest_note(t, "Phase B -> 0x%08x", (unsigned)r);
        T3CALL(t, r, "2D set_macrovision(sel15, 0) Phase C restore", IOConnectMethodScalarIStructureI(d, 15, 1, 0, 0, NULL)); bad += t3_expect(t, "Phase C", r, 0);
    }
    IOServiceClose(d);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_macrovision", 0, body); }
