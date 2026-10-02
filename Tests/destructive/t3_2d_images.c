/* T3 test for #113 (2D create_transfer, sel 10) and the create/wait/delete half of #119 (2D create_image sel 9, wait_image sel 12, delete_image sel 11), issue #100 / protocol #87.
 * Traced (IOATIR5002DContext_Surface.cpp / *_create_image_Port.cpp, shipped 0xd260 / 0xd130 / 0xd5c0 / 0xd450): every one first calls create_shared (this context's IOATIR500Shared, wired
 * to the accelerator), then Shared::new_agp_texture(0, bytes, &addr) (create_transfer) or Shared::new_texture(p1, p2, 0, 0, &lo, &hi) (create_image: p1 = bytes, p2 = 0 -> a plain texture,
 * the same kind GL new_texture typeTag 2 makes in t3_gl_textures). Ids index this connection's own texture table, found by probing wait_image(i) (valid id: a bounded wait on an
 * already retired stamp -> 0; otherwise BadArgument). Unbound surface, so create_transfer does not touch any surface backing. declare_image's first two arguments are NOT proven
 * (it needs both non-zero; the vendor meaning of new_agp_texture's first argument is unknown), so declare_image (and the DVD copy, #120) are deliberately not exercised here.
 * Cleanup: delete_image for each id; a second delete -> BadArgument. */
#include "t3common.h"
static int find_id(dtest_t *t, io_connect_t d, int from) {
    int i; kern_return_t r;
    for (i = from; i < from + 16; i++) {
        char m[64]; snprintf(m, sizeof m, "2D wait_image(%d) probe", i);
        T3CALL(t, r, m, IOConnectMethodScalarIStructureI(d, 12, 1, 0, i, NULL));
        if (r == 0) return i;
    }
    return -1;
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, id, lo = -1, hi = -1, h = -1, addr = -1;
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "2D wait_image(0) with no shared allocator", IOConnectMethodScalarIStructureI(d, 12, 1, 0, 0, NULL)); bad += t3_expect(t, "wait before create", r, TEST_kIOReturnNoResources);
    T3CALL(t, r, "2D create_image(sel9, 0x1000, 0)", IOConnectMethodScalarIScalarO(d, 9, 2, 2, 0x1000, 0, &lo, &hi));
    dtest_note(t, "create_image -> r=0x%08x lo=0x%x hi=0x%x", (unsigned)r, (unsigned)lo, (unsigned)hi); bad += t3_expect(t, "create_image", r, 0);
    if (r == 0) {
        id = find_id(t, d, 0); dtest_note(t, "image id found by probe: %d", id);
        if (id < 0) bad++;
        else {
            T3CALL(t, r, "2D delete_image(id)", IOConnectMethodScalarIStructureI(d, 11, 1, 0, id, NULL)); bad += t3_expect(t, "delete_image", r, 0);
            T3CALL(t, r, "2D delete_image(id) again", IOConnectMethodScalarIStructureI(d, 11, 1, 0, id, NULL)); bad += t3_expect(t, "delete twice", r, TEST_kIOReturnBadArgument);
            T3CALL(t, r, "2D wait_image(id) after delete", IOConnectMethodScalarIStructureI(d, 12, 1, 0, id, NULL)); bad += t3_expect(t, "wait deleted", r, TEST_kIOReturnBadArgument);
        }
    }
    T3CALL(t, r, "2D create_transfer(sel10, mode 0, 0x1000 bytes)", IOConnectMethodScalarIScalarO(d, 10, 2, 2, 0, 0x1000, &h, &addr));
    dtest_note(t, "create_transfer -> r=0x%08x handle=0x%x addr=0x%x", (unsigned)r, (unsigned)h, (unsigned)addr); bad += t3_expect(t, "create_transfer", r, 0);
    if (r == 0) {
        id = find_id(t, d, 0); dtest_note(t, "transfer id found by probe: %d", id);
        if (id >= 0) { T3CALL(t, r, "2D delete_image(transfer id)", IOConnectMethodScalarIStructureI(d, 11, 1, 0, id, NULL)); bad += t3_expect(t, "delete transfer", r, 0); }
    }
    IOServiceClose(d);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_images", 0, body); }
