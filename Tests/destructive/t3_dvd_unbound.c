/* Live confirmation of the #146 fix (issue #87 protocol; Phase R only - on STOCK both calls panic the kernel: NULL boundSurface, DAR 0xd64 / 0xb70+). A registered 4x4 surface, a DVD connection that NEVER calls
 * set_surface, then set_macrovision (sel 16) and write_buffer (sel 6). Expected on the fixed rebuilt kernel: set_macrovision -> 0xe00002bc (the siblings' unbound answer), write_buffer -> 0xe00002cc (CannotLock), no panic. */
#include "t3common.h"
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; IOByteCount zero = 0; UInt32 in[7];
    unsigned char *buf = (unsigned char *)valloc(0x10000);
    if (!buf) return "DIVERGENCE";
    memset(buf, 0x55, 0x10000);
    if (t3_surface(t, svc, &s, 4, 4) != 0) { free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "open DVD connection (no set_surface)", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != 0) { IOServiceClose(s); free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_macrovision(sel16, 0x92, 0) on an UNBOUND connection - THE #146 CALL", IOConnectMethodScalarIScalarO(d, 16, 2, 0, 0x92, 0)); bad += t3_expect(t, "set_macrovision unbound", r, 0xe00002bc);
    in[0] = 0; in[1] = 0; in[2] = 4; in[3] = 4; in[4] = 0; in[5] = (UInt32)buf; in[6] = 64;
    T3CALL(t, r, "DVD write_buffer(sel6) on an UNBOUND connection - THE #146 CALL", IOConnectMethodStructureIStructureO(d, 6, sizeof in, &zero, in, NULL)); bad += t3_expect(t, "write_buffer unbound", r, 0xe00002cc);
    IOServiceClose(d); IOServiceClose(s);
    free(buf);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_unbound", 0, body); }
