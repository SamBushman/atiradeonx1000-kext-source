/* T3 test for #117 (Surface set_scale, sel 8), #107 (GL scale_surface, sel 14) and #111 (2D scale_surface, sel 4), issue #100 / protocol #87.
 * Layout: Headers/IOAccelWireLayouts.h (IOAccelSurfaceScaling = 0x2c bytes {buffer bounds, source size, 8 reserved}; Apple's public IOAccelTypes.h cross-checked against
 * IOATIR500Surface::set_scaling). Only the IDENTITY scale is used: buffer = {0,0,4,4} and source = {4,4} on the registered 4x4 surface, so the surface keeps its size and
 * the display is not scaled; flags 2 = enable (set_scaling: (flags>>1)&1 == 0 means "disable and restore the default shape"). GL/2D scale_surface(flags, w, h) build the same
 * struct from the scalars and need flags bit 0 set (else Unsupported). The test ends by disabling the scaling again (flags 0, size 0). */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, g = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; IOByteCount osz; unsigned char out[0x30]; UInt32 *info = (UInt32 *)out;
    unsigned char sc[0x2c];
    memset(sc, 0, sizeof sc);
    *(SInt16 *)(sc + 0) = 0; *(SInt16 *)(sc + 2) = 0; *(SInt16 *)(sc + 4) = 4; *(SInt16 *)(sc + 6) = 4; *(SInt16 *)(sc + 8) = 4; *(SInt16 *)(sc + 10) = 4;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "Surface set_scale(flags 0, no struct) = disabled path", IOConnectMethodScalarIStructureI(s, 8, 1, 0, 0, NULL)); bad += t3_expect(t, "disabled", r, 0);
    T3CALL(t, r, "Surface set_scale(flags 2, identity IOAccelSurfaceScaling 0x2c bytes)", IOConnectMethodScalarIStructureI(s, 8, 1, sizeof sc, 2, sc)); bad += t3_expect(t, "enable identity", r, 0);
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r == KERN_SUCCESS) {
        osz = sizeof out; memset(out, 0, sizeof out);
        T3CALL(t, r, "2D get_surface_info(id 1, mode 0x800)", IOConnectMethodScalarIStructureO(d, 2, 2, &osz, 1, 0x800, out));
        dtest_note(t, "info d[2]=%u d[3]=%u (4x4 expected)", (unsigned)info[2], (unsigned)info[3]);
        T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "2D bind", r, 0);
        if (r == KERN_SUCCESS) {
            T3CALL(t, r, "2D scale_surface(sel4, flags 3, 4, 4)", IOConnectMethodScalarIScalarO(d, 4, 3, 0, 3, 4, 4)); bad += t3_expect(t, "2D scale", r, 0);
            T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
        }
        IOServiceClose(d);
    }
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r == KERN_SUCCESS) {
        T3CALL(t, r, "GL scale_surface(sel14, flags 3, 4, 4) UNBOUND", IOConnectMethodScalarIStructureI(g, 14, 3, 0, 3, 4, 4, NULL)); bad += t3_expect(t, "GL scale unbound", r, TEST_kIOReturnUnsupported);
        T3CALL(t, r, "GL set_surface(1,0,0,0) binds", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 1, 0, 0, 0, NULL)); bad += t3_expect(t, "GL bind", r, 0);
        if (r == KERN_SUCCESS) {
            T3CALL(t, r, "GL scale_surface(sel14, flags 3, 4, 4)", IOConnectMethodScalarIStructureI(g, 14, 3, 0, 3, 4, 4, NULL)); bad += t3_expect(t, "GL scale", r, 0);
            T3CALL(t, r, "GL set_surface(0) detaches", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 0, 0, 0, 0, NULL));
        }
        IOServiceClose(g);
    }
    T3CALL(t, r, "Surface set_scale(flags 0, no struct) disables again", IOConnectMethodScalarIStructureI(s, 8, 1, 0, 0, NULL)); bad += t3_expect(t, "disable", r, 0);
    IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_scaling", 0, body); }
