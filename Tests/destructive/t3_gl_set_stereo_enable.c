/* Test for #88 enable (GL set_stereo, sel 19: scalar 0 = mode, scalar 1 = panel), issue #87 protocol. Wire order from the vendor call site (see t3_gl_set_stereo.c). Run on the user's
 * instruction: enable stereo on panel 0 (mode 1), then restore it at once (mode 0) and confirm the main display is unchanged (the runner's screenshots). Return codes are recorded.
 *
 * 2026-10-06 rewrite: adds the GPU-liveness check (wait_for_stamp, sel 9, stamp=0 - CONFIRMED always-immediately-satisfied shape, see Tests/test_gl_context.c) this issue's own
 * "Measurements" section asks for and the first run skipped, taken before the enable call and after each of the enable/restore calls so a hang shows up as this call itself
 * failing to return rather than only as the outer harness timing out. Also classifies 0xe00002bd specifically as EXPECTED-REJECT rather than blind DIVERGENCE: static analysis of
 * IOATIR500Accelerator::setup_stereo (issue #88, 2026-10-06 comment) confirmed this exact value is a hard-coded sentinel on one specific real branch (both of the function's own
 * allocation sub-steps reporting success), not a generic error - so matching it exactly is itself evidence about which vendor code path ran, worth distinguishing from any other
 * nonzero return. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t g = IO_OBJECT_NULL; kern_return_t r, r2; int bad = 0; const char *outcome = "PASS";
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r != 0) return "DIVERGENCE";
    T3CALL(t, r, "GL wait_for_stamp(sel9, stamp=0) baseline liveness", IOConnectMethodScalarIStructureI(g, 9, 1, 0, 0, NULL));
    bad += t3_expect(t, "baseline liveness", r, 0);
    T3CALL(t, r, "GL set_stereo(sel19, mode 1, panel 0) enable", IOConnectMethodScalarIStructureI(g, 19, 2, 0, 1, 0, NULL));
    dtest_note(t, "enable -> 0x%08x", (unsigned)r);
    T3CALL(t, r2, "GL wait_for_stamp(sel9, stamp=0) post-enable liveness", IOConnectMethodScalarIStructureI(g, 9, 1, 0, 0, NULL));
    bad += t3_expect(t, "post-enable liveness", r2, 0);
    if (r == TEST_kIOReturnNoMemory) {
        dtest_note(t, "NoMemory matches setup_stereo's confirmed force-return sentinel on the double-allocation-success branch (issue #88, 2026-10-06 comment) - not a generic failure");
        outcome = "EXPECTED-REJECT";
    } else if (r != 0) {
        bad++;
    }
    T3CALL(t, r2, "GL set_stereo(sel19, mode 0, panel 0) restore", IOConnectMethodScalarIStructureI(g, 19, 2, 0, 0, 0, NULL));
    bad += t3_expect(t, "restore", r2, 0);
    T3CALL(t, r2, "GL wait_for_stamp(sel9, stamp=0) post-restore liveness", IOConnectMethodScalarIStructureI(g, 9, 1, 0, 0, NULL));
    bad += t3_expect(t, "post-restore liveness", r2, 0);
    IOServiceClose(g);
    return bad ? "DIVERGENCE" : outcome;
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_set_stereo_enable", 0, body); }
