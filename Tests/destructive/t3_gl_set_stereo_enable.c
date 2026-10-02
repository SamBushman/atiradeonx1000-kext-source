/* Test for #88 enable (GL set_stereo, sel 19: scalar 0 = mode, scalar 1 = panel), issue #87 protocol. Wire order from the vendor call site (see t3_gl_set_stereo.c). Run on the user's
 * instruction: enable stereo on panel 0 (mode 1), then restore it at once (mode 0) and confirm the main display is unchanged (the runner's screenshots). Return codes are recorded. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t g = IO_OBJECT_NULL; kern_return_t r, r2; int bad = 0;
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r != 0) return "DIVERGENCE";
    T3CALL(t, r, "GL set_stereo(sel19, mode 1, panel 0) enable", IOConnectMethodScalarIStructureI(g, 19, 2, 0, 1, 0, NULL));
    dtest_note(t, "enable -> 0x%08x", (unsigned)r);
    T3CALL(t, r2, "GL set_stereo(sel19, mode 0, panel 0) restore", IOConnectMethodScalarIStructureI(g, 19, 2, 0, 0, 0, NULL));
    bad += t3_expect(t, "restore", r2, 0);
    if (r != 0) bad++;
    IOServiceClose(g);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_set_stereo_enable", 0, body); }
