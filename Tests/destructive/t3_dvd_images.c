/* T3 test for #120 (DVD declare_image sel 8 / delete_image sel 9), issue #100 / protocol #87. Same body shape as the 2D pair (shipped 0x103e0 / 0x104f0: create_shared, then
 * Shared::new_agp_texture(p2 = user address, p3 = length, &out); delete_image(id) -> Shared::delete_texture): see t3_2d_declare_image.c for the trace of new_agp_texture. The DVD context has
 * no wait_image, so the id is found by probing delete_image(i) itself (BadArgument for an id with no texture, 0 for ours: it deletes the ONLY image this connection created, which is the
 * intended cleanup). Our own 64 KB page-aligned buffer, length 0x1000, nothing foreign touched. */
#include "t3common.h"
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, id = -1, h = -1, changed = 0; unsigned char *buf = (unsigned char *)valloc(0x10000);
    if (!buf) return "DIVERGENCE";
    memset(buf, 0xAA, 0x10000);
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD delete_image(0) before any declare", IOConnectMethodScalarIStructureI(d, 9, 1, 0, 0, NULL)); bad += t3_expect(t, "delete before declare", r, TEST_kIOReturnNoResources);
    T3CALL(t, r, "DVD declare_image(sel8, 0, addr = 64 KB user buffer, 0x1000)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, (int)buf, 0x1000, &h));
    dtest_note(t, "declare_image -> r=0x%08x out=0x%x", (unsigned)r, (unsigned)h); bad += t3_expect(t, "declare_image", r, 0);
    if (r == 0) {
        for (i = 0; i < 16 && id < 0; i++) {
            char m[64]; snprintf(m, sizeof m, "DVD delete_image(%d) probe", i);
            T3CALL(t, r, m, IOConnectMethodScalarIStructureI(d, 9, 1, 0, i, NULL));
            if (r == 0) id = i;
        }
        dtest_note(t, "declared image id (deleted by the probe): %d", id);
        if (id < 0) bad++;
        else { T3CALL(t, r, "DVD delete_image(id) again", IOConnectMethodScalarIStructureI(d, 9, 1, 0, id, NULL)); bad += t3_expect(t, "delete twice", r, TEST_kIOReturnBadArgument); }
    }
    IOServiceClose(d);
    usleep(300000);
    for (i = 0; i < 0x10000; i++) if (buf[i] != 0xAA) changed++;
    dtest_note(t, "user buffer bytes changed: %d (expected 0)", changed);
    if (changed) bad++;
    free(buf);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_images", 0, body); }
