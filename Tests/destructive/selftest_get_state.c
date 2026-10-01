/*
 * Tests/destructive/selftest_get_state.c - protocol self-test (issue #87). Exercises dtest_main()'s gates, the write-ahead log, the state file
 * and the mirror with the ONE call that is already proven safe on the stock driver (Surface get_state, sel 2: 0 in / 1 out, global,
 * "returned kIOReturnSuccess, outState=0x1 without incident", Tests/test_surface_context.c). It is NOT a destructive test; it exists so the
 * framework itself can be validated on the real machine before any real destructive test relies on it.
 */
#include "dtest.h"

static const char *body(dtest_t *t, io_service_t service) {
    io_connect_t c; kern_return_t r; int outState = -1;
    dtest_about(t, "IOServiceOpen type=%d (Surface)", CLIENT_TYPE_SURFACE);
    r = open_user_client(service, CLIENT_TYPE_SURFACE, &c);
    dtest_result(t, r, "IOServiceOpen");
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    dtest_about(t, "Surface get_state(sel 2) IOConnectMethodScalarIScalarO(connect, 2, 0, 1, &outState)");
    r = IOConnectMethodScalarIScalarO(c, 2, 0, 1, &outState);
    dtest_result(t, r, "outState=0x%x", outState);
    IOServiceClose(c);
    dtest_note(t, "closed");
    return (r == TEST_kIOReturnSuccess) ? "PASS" : "DIVERGENCE";
}

int main(int argc, char **argv) { return dtest_main(argc, argv, "selftest_get_state", 0, body); }
