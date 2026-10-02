/* T3 test for #108 (GL set_surface_volatile_state, sel 16) and #118 (Surface surface_control / surface_control_alias, sel 16 and 18), issue #100 / protocol #87.
 * Traced (IOATIR500Surface::set_volatile_state 0xd48.., surface_control 0x15cb0): selector 4 stores the state at surface+0xd48 and moves the surface to the head of the
 * accelerator's circular surface list (accel+0x5c), +/-1 on the volatile counter accel+0x21c (never below 0). Selector 1 (set_surface_blocking) only sets surface+0xbf6 and
 * wakes sleepers when the value is 0 (it never sleeps itself; the issue text's "value 0 sleeps" was wrong). Any other selector -> BadArgument. Sequence: 1 then 0 for every
 * entry point, the surface registered with the proven set-up; state is restored to 0 at the end. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, g = IO_OBJECT_NULL; kern_return_t r; int out = -1, bad = 0, st = -1;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "Surface surface_control(sel16, selector 1 set_surface_blocking, 1)", IOConnectMethodScalarIScalarO(s, 16, 2, 1, 1, 1, &out)); bad += t3_expect(t, "blocking=1", r, 0);
    T3CALL(t, r, "Surface surface_control(sel16, selector 1, 0) wakes sleepers", IOConnectMethodScalarIScalarO(s, 16, 2, 1, 1, 0, &out)); bad += t3_expect(t, "blocking=0", r, 0);
    T3CALL(t, r, "Surface surface_control(sel16, selector 2) unknown", IOConnectMethodScalarIScalarO(s, 16, 2, 1, 2, 0, &out)); bad += t3_expect(t, "selector 2", r, TEST_kIOReturnBadArgument);
    T3CALL(t, r, "Surface surface_control(sel16, selector 4 set_volatile_state, 1)", IOConnectMethodScalarIScalarO(s, 16, 2, 1, 4, 1, &out)); bad += t3_expect(t, "volatile=1", r, 0);
    T3CALL(t, r, "Surface get_state after volatile=1", IOConnectMethodScalarIScalarO(s, 2, 0, 1, &st)); dtest_note(t, "get_state=0x%x", st);
    T3CALL(t, r, "Surface surface_control(sel16, selector 4, 0)", IOConnectMethodScalarIScalarO(s, 16, 2, 1, 4, 0, &out)); bad += t3_expect(t, "volatile=0", r, 0);
    T3CALL(t, r, "Surface surface_control_alias(sel18, selector 4, 1)", IOConnectMethodScalarIScalarO(s, 18, 2, 1, 4, 1, &out)); bad += t3_expect(t, "alias volatile=1", r, 0);
    T3CALL(t, r, "Surface surface_control_alias(sel18, selector 4, 0)", IOConnectMethodScalarIScalarO(s, 18, 2, 1, 4, 0, &out)); bad += t3_expect(t, "alias volatile=0", r, 0);
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r == KERN_SUCCESS) {
        T3CALL(t, r, "GL set_surface(1,0,0,0) binds", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 1, 0, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
        if (r == KERN_SUCCESS) {
            T3CALL(t, r, "GL set_surface_volatile_state(sel16, 1)", IOConnectMethodScalarIStructureI(g, 16, 1, 0, 1, NULL)); bad += t3_expect(t, "GL volatile=1", r, 0);
            T3CALL(t, r, "GL set_surface_volatile_state(sel16, 0)", IOConnectMethodScalarIStructureI(g, 16, 1, 0, 0, NULL)); bad += t3_expect(t, "GL volatile=0", r, 0);
            T3CALL(t, r, "GL set_surface(0) detaches", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 0, 0, 0, 0, NULL));
        }
        IOServiceClose(g);
    }
    IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_volatile_state", 0, body); }
