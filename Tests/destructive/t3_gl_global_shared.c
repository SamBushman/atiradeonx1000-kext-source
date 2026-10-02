/* T3 test for #105 (GL become_global_shared, sel 12), issue #100 / protocol #87. Traced (IOATIR500GLContext_become_global_shared_Port.cpp, shipped 0x9640, 216 bytes): a mutual-exclusion
 * gate on the accelerator's single "global shared" slot (accel+0x6c, flag accel+0x70) under the accelerator lock. makeShared != 0: if the slot is empty AND this context's shared object
 * has an empty list (shared+0x24 == 0) the slot takes this context's shared object (flag 1), return 0; otherwise CannotLock 0xe00002cc. makeShared == 0: if the slot holds THIS context's
 * shared object (and its list is empty) the slot is cleared, return 0; otherwise CannotLock. Nothing else is read or written, so the effect is exactly one pointer in the accelerator,
 * restored by the release. The earlier correction of #105's text: the claim "makes this context the global shared owner" is confirmed by this trace.
 * Sequence on a fresh GL connection (no texture ever created, so shared+0x24 == 0): release without owning -> CannotLock; claim -> 0; claim again -> CannotLock; release -> 0; release again -> CannotLock.
 * If another client already owns the slot the first claim returns CannotLock: recorded as EXPECTED-REJECT and nothing was changed. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t g = IO_OBJECT_NULL; kern_return_t r; int bad = 0; const char *outcome = "PASS";
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "GL become_global_shared(0) without owning", IOConnectMethodScalarIStructureI(g, 12, 1, 0, 0, NULL)); bad += t3_expect(t, "release unowned", r, TEST_kIOReturnCannotLock);
    T3CALL(t, r, "GL become_global_shared(1)", IOConnectMethodScalarIStructureI(g, 12, 1, 0, 1, NULL));
    if (r == TEST_kIOReturnCannotLock) { dtest_note(t, "slot already owned by another client (or list not empty): nothing changed"); outcome = "EXPECTED-REJECT"; }
    else {
        bad += t3_expect(t, "claim", r, 0);
        if (r == 0) {
            T3CALL(t, r, "GL become_global_shared(1) again", IOConnectMethodScalarIStructureI(g, 12, 1, 0, 1, NULL)); bad += t3_expect(t, "claim twice", r, TEST_kIOReturnCannotLock);
            T3CALL(t, r, "GL become_global_shared(0) releases", IOConnectMethodScalarIStructureI(g, 12, 1, 0, 0, NULL)); bad += t3_expect(t, "release", r, 0);
            T3CALL(t, r, "GL become_global_shared(0) again", IOConnectMethodScalarIStructureI(g, 12, 1, 0, 0, NULL)); bad += t3_expect(t, "release twice", r, TEST_kIOReturnCannotLock);
        }
    }
    IOServiceClose(g);
    return bad ? "DIVERGENCE" : outcome;
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_global_shared", 0, body); }
