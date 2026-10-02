/* T3 test for #109 (GL reclaim_resources, sel 17) with real data buffers outstanding, issue #100 / protocol #87. Traced (IOATIR500GLContext_reclaim_resources_Port.cpp, shipped 0x83c0):
 * it sets the accelerator's data-buffer pool limits to the constants 0x20000 / 0x10000 (+0x5c8 / +0x5d8; the same values GL get_data_buffer reports as out[1] = 0x10000), walks THIS
 * context's data-buffer list (this+0xe8), returning up to 16 buffers to the accelerator's free pool and freeing the rest (freeOneDataBuffer), then trims the pool to 15. The list is
 * per-context, so only buffers this connection allocated are touched. Sequence on one fresh GL connection: get_data_buffer x3 (allocates data buffers for this context), reclaim_resources,
 * get_data_buffer again (must still report out[1] = 0x10000 and a non-zero page-multiple out[0]); close. */
#include "t3common.h"
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t g = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, o0 = -1, o1 = -1;
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    for (i = 0; i < 3; i++) {
        T3CALL(t, r, "GL get_data_buffer(sel18)", IOConnectMethodScalarIScalarO(g, 18, 0, 2, &o0, &o1)); bad += t3_expect(t, "get_data_buffer", r, 0);
        dtest_note(t, "get_data_buffer #%d: out0=0x%x out1=0x%x", i, (unsigned)o0, (unsigned)o1);
    }
    T3CALL(t, r, "GL reclaim_resources(sel17)", IOConnectMethodScalarIStructureI(g, 17, 0, 0, NULL)); bad += t3_expect(t, "reclaim", r, 0);
    T3CALL(t, r, "GL get_data_buffer(sel18) after reclaim", IOConnectMethodScalarIScalarO(g, 18, 0, 2, &o0, &o1)); bad += t3_expect(t, "get_data_buffer after", r, 0);
    dtest_note(t, "after reclaim: out0=0x%x out1=0x%x (expect out1 0x10000, out0 a non-zero multiple of 0x1000)", (unsigned)o0, (unsigned)o1);
    if (o1 != 0x10000 || o0 == 0 || (o0 & 0xfff)) bad++;
    IOServiceClose(g);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_reclaim", 0, body); }
