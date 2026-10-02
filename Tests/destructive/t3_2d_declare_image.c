/* T3 test for the declare_image part of #119 (2D declare_image, sel 8), issue #100 / protocol #87. Traced (IOATIR5002DContext_declare_image_Port.cpp -> IOATIR500Shared_new_agp_texture_Port.cpp, shipped
 * 0xd020 / 0x17150): declare_image(p1 [unused by the body], p2, p3, &out) calls Shared::new_agp_texture(p2, p3, &out) where p2 is a USER ADDRESS (0 = let the kernel allocate, which declare_image
 * forbids: both p2 and p3 must be non-zero, else BadArgument) and p3 the length: the body wraps [p2 & -page, p3 + offset] of the caller's task in an IOMemoryDescriptor
 * (withAddress, direction 0x10002) and registers it as a client-shared texture (a "declared" image). The address is our OWN page-aligned 64 KB buffer, length 0x1000; nothing foreign is
 * touched. The new image's id is found by probing wait_image(i) (this connection's own table; valid id -> bounded wait on an already retired stamp -> 0), then delete_image(id) releases the
 * descriptor. The buffer is freed only after the connection is closed. */
#include "t3common.h"
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, id = -1, h = -1, changed = 0; unsigned char *buf = (unsigned char *)valloc(0x10000);
    if (!buf) return "DIVERGENCE";
    memset(buf, 0xAA, 0x10000);
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "2D declare_image(sel8, 0, addr = 64 KB user buffer, 0x1000)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, (int)buf, 0x1000, &h));
    dtest_note(t, "declare_image -> r=0x%08x out=0x%x", (unsigned)r, (unsigned)h); bad += t3_expect(t, "declare_image", r, 0);
    if (r == 0) {
        for (i = 0; i < 16 && id < 0; i++) {
            char m[64]; snprintf(m, sizeof m, "2D wait_image(%d) probe", i);
            T3CALL(t, r, m, IOConnectMethodScalarIStructureI(d, 12, 1, 0, i, NULL));
            if (r == 0) id = i;
        }
        dtest_note(t, "declared image id found by probe: %d", id);
        if (id < 0) bad++;
        else { T3CALL(t, r, "2D delete_image(id)", IOConnectMethodScalarIStructureI(d, 11, 1, 0, id, NULL)); bad += t3_expect(t, "delete_image", r, 0); }
    }
    IOServiceClose(d);
    usleep(300000);
    for (i = 0; i < 0x10000; i++) if (buf[i] != 0xAA) changed++;
    dtest_note(t, "user buffer bytes changed: %d (expected 0: declaring a buffer never writes it)", changed);
    if (changed) bad++;
    free(buf);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_declare_image", 0, body); }
