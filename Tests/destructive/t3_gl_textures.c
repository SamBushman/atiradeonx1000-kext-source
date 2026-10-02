/* T3 test for #104 (GL new_texture, sel 10) with its dependants GL 13 page_off_texture (#106), GL 15 purge_texture and GL 11 delete_texture, issue #100 / protocol #87.
 * Traced (IOATIR500GLContext_new_texture_Port.cpp, IOATIR500Shared_new_texture_Port.cpp): sIOGLNewTextureData {typeTag, p1..p4} (0x14 bytes in), return {out0, out1} (8 bytes). typeTag 2
 * calls Shared::new_texture(p1, 0, 0, 0, &out0, &out1): a PLAIN texture buffer (no AGP ref, no surface texture): an IOBufferMemoryDescriptor of (0x80 + p1 + header) rounded to pages,
 * mapped into the caller (out0 = the mapped address). The texture table (shared+0x10) belongs to THIS connection's IOATIR500Shared (create_shared), so ids are ours alone; the id of the
 * new texture is found by probing purge_texture(i) (0 = exists, BadArgument = no such id; purge only relinks that texture's own list node) so no id is guessed blindly.
 * Smallest useful size 0x1000. page_off_texture(id, 0): nothing to page (bit test of the texture's dirty mask is 0 on a fresh texture) so it is a probe of the valid path only.
 * Cleanup: delete_texture(id); a second delete and purge must now be BadArgument. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t g = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, id = -1; UInt32 in[5], out[2]; IOByteCount osz;
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    memset(in, 0, sizeof in); in[0] = 2; in[1] = 0x1000; memset(out, 0, sizeof out); osz = sizeof out;
    T3CALL(t, r, "GL new_texture(sel10, typeTag 2, p1 0x1000)", IOConnectMethodStructureIStructureO(g, 10, sizeof in, &osz, in, out));
    dtest_note(t, "new_texture -> r=0x%08x out0=0x%x out1=0x%x outSize=%u", (unsigned)r, (unsigned)out[0], (unsigned)out[1], (unsigned)osz);
    bad += t3_expect(t, "new_texture", r, 0);
    if (r == 0) {
        for (i = 0; i < 16 && id < 0; i++) {
            char d[64]; snprintf(d, sizeof d, "GL purge_texture(%d) probe", i);
            T3CALL(t, r, d, IOConnectMethodScalarIStructureI(g, 15, 1, 0, i, NULL));
            if (r == 0) id = i;
        }
        dtest_note(t, "texture id found by probe: %d", id);
        if (id < 0) bad++;
        else {
            T3CALL(t, r, "GL page_off_texture(id, 0)", IOConnectMethodScalarIStructureI(g, 13, 2, 0, id, 0, NULL)); bad += t3_expect(t, "page_off", r, 0);
            T3CALL(t, r, "GL delete_texture(id)", IOConnectMethodScalarIStructureI(g, 11, 1, 0, id, NULL)); bad += t3_expect(t, "delete", r, 0);
            T3CALL(t, r, "GL delete_texture(id) again", IOConnectMethodScalarIStructureI(g, 11, 1, 0, id, NULL)); bad += t3_expect(t, "delete twice", r, TEST_kIOReturnBadArgument);
            T3CALL(t, r, "GL purge_texture(id) after delete", IOConnectMethodScalarIStructureI(g, 15, 1, 0, id, NULL)); bad += t3_expect(t, "purge deleted", r, TEST_kIOReturnBadArgument);
        }
    }
    IOServiceClose(g);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_textures", 0, body); }
