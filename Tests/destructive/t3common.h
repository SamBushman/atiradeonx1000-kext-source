/* Tests/destructive/t3common.h - shared set-up for the T3 tests of issue #100 (protocol #87). Every call here is one already proven live on stock (Tests/test_deep_t2.c):
 * Surface set_id_mode(1,0), set_id_mode(1,0x20), set_shape(4x4 region). */
#ifndef T3COMMON_H
#define T3COMMON_H
#include "dtest.h"
#include <unistd.h>

#define T3CALL(t, r, desc, expr) do { dtest_about((t), "%s", (desc)); (r) = (expr); dtest_result((t), (r), "%s", (desc)); } while (0)

/* open a Surface connection and register a w x h surface with id 1; returns KERN_SUCCESS or the first failing code */
static kern_return_t t3_surface(dtest_t *t, io_service_t svc, io_connect_t *s, int w, int h) {
    unsigned char region[20]; kern_return_t r;
    T3CALL(t, r, "open Surface connection", open_user_client(svc, CLIENT_TYPE_SURFACE, s));
    if (r != KERN_SUCCESS) return r;
    T3CALL(t, r, "Surface set_id_mode(1,0x0)", IOConnectMethodScalarIScalarO(*s, 7, 2, 0, 1, 0x0));
    if (r == KERN_SUCCESS) T3CALL(t, r, "Surface set_id_mode(1,0x20)", IOConnectMethodScalarIScalarO(*s, 7, 2, 0, 1, 0x20));
    if (r == KERN_SUCCESS) {
        memset(region, 0, sizeof region);
        *(UInt32 *)(region + 0) = 1; *(SInt16 *)(region + 8) = w; *(SInt16 *)(region + 10) = h; *(SInt16 *)(region + 16) = w; *(SInt16 *)(region + 18) = h;
        T3CALL(t, r, "Surface set_shape(region WxH)", IOConnectMethodScalarIStructureI(*s, 9, 2, sizeof region, 0, 1, region));
    }
    return r;
}
/* expectation helper: logs the verdict; returns 0 when the code matched */
static int t3_expect(dtest_t *t, const char *what, kern_return_t got, kern_return_t want) {
    dtest_note(t, "%s: got 0x%08x want 0x%08x -> %s", what, (unsigned)got, (unsigned)want, got == want ? "MATCH" : "MISMATCH");
    return got == want ? 0 : 1;
}
#endif
