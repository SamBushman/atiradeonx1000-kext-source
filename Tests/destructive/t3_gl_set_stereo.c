/* Test for #88 (GL set_stereo, sel 19: scalar 0 = stereo mode, scalar 1 = panel), issue #87 protocol. Wire order from the real vendor call site (ATIRadeonX1000GLDriver.bundle, _gldSetInteger
 * at 0x5a00-0x5a18: li r4,0x13; r5 = {p[0], p[1]}, 2 scalars in, 0 out; p[0] != 0 sets the context's stereo flag 0x10 and byte +0x26, p[0] == 0 clears them), consistent with the kext's own order swap
 * (IOATIR500GLContext_set_stereo_Port.cpp: setup_stereo(param2 = panel, param1 = mode)). Traced (IOATIR500Accelerator::setup_stereo): "no-op if new mode == current"; an ENABLE (mode bit 0) allocates a
 * per-panel scratch record and VRAM and walks every live surface with freeAllSwapBuffers / allocMasterSwapBuffer / allocAllSlaveSwapBuffers, whose allocation-failure path is the stock infinite
 * loop of #32: the enable is NOT run here. Only mode 0 for each of the two panels (the current mode is 0 on this single-GL-client machine: the call is a no-op and changes no accelerator state).
 * Out-of-range panels are not tried (the panel indexes accelerator arrays). */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t g = IO_OBJECT_NULL; kern_return_t r; int bad = 0, p;
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r != 0) return "DIVERGENCE";
    for (p = 0; p < 2; p++) {
        char m[96]; snprintf(m, sizeof m, "GL set_stereo(sel19, mode 0, panel %d)", p);
        T3CALL(t, r, m, IOConnectMethodScalarIStructureI(g, 19, 2, 0, 0, p, NULL));
        dtest_note(t, "%s -> 0x%08x", m, (unsigned)r);
        if (r != 0) bad++;
    }
    IOServiceClose(g);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_set_stereo", 0, body); }
