/* T3 test for #120 (DVD declare_image sel 8 / delete_image sel 9), issue #100 / protocol #87. Same body shape as the 2D pair (shipped 0x103e0 / 0x104f0: create_shared, then
 * Shared::new_agp_texture(p2 = user address, p3 = length, &out); delete_image(id) -> Shared::delete_texture): see t3_2d_declare_image.c for the trace of new_agp_texture. The DVD context has
 * no wait_image, so the id is found by probing delete_image(i) itself (BadArgument for an id with no texture, 0 for ours: it deletes the ONLY image this connection created, which is the
 * intended cleanup). Our own 64 KB page-aligned buffer, length 0x1000, nothing foreign touched.
 * *** This file already ran once (phaseS log, 2026-10-02T04:42:57Z, outcome=PASS) but was never reported to #120. Added 2026-10-05: ioreg class-instance counts (IOATIR500Shared,
 * ATIR500Memory) before/after - the specific "GART accounting and class counts" check #120's success criteria ask for, which the original run's "user buffer unchanged" proxy didn't cover. */
#include "t3common.h"
#include <stdlib.h>
#include <unistd.h>

#define NCLS 2
static const char *kClasses[NCLS] = { "IOATIR500Shared", "ATIR500Memory" };
static int class_counts(int *out) {
    FILE *p = popen("/usr/sbin/ioreg -w0 -c IOATIR500Shared -c ATIR500Memory 2>/dev/null", "r");
    char line[512]; int i;
    for (i = 0; i < NCLS; i++) out[i] = 0;
    if (!p) return -1;
    while (fgets(line, sizeof line, p)) {
        for (i = 0; i < NCLS; i++) { char tag[64]; snprintf(tag, sizeof tag, "<class %s", kClasses[i]); if (strstr(line, tag)) out[i]++; }
    }
    pclose(p); return 0;
}
static void log_counts(dtest_t *t, const char *label, int *c) { dtest_note(t, "class counts %s: IOATIR500Shared=%d ATIR500Memory=%d", label, c[0], c[1]); }

static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, id = -1, h = -1, changed = 0; unsigned char *buf = (unsigned char *)valloc(0x10000);
    int before[NCLS], afterDeclare[NCLS], afterClose[NCLS];
    if (!buf) return "DIVERGENCE";
    memset(buf, 0xAA, 0x10000);
    class_counts(before); log_counts(t, "BEFORE (no connection open)", before);
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD delete_image(0) before any declare", IOConnectMethodScalarIStructureI(d, 9, 1, 0, 0, NULL)); bad += t3_expect(t, "delete before declare", r, TEST_kIOReturnNoResources);
    T3CALL(t, r, "DVD declare_image(sel8, 0, addr = 64 KB user buffer, 0x1000)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, (int)buf, 0x1000, &h));
    dtest_note(t, "declare_image -> r=0x%08x out=0x%x", (unsigned)r, (unsigned)h); bad += t3_expect(t, "declare_image", r, 0);
    class_counts(afterDeclare); log_counts(t, "AFTER declare_image", afterDeclare);
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
    class_counts(afterClose); log_counts(t, "AFTER connection close", afterClose);
    { int leaked = 0; for (i = 0; i < NCLS; i++) if (afterClose[i] != before[i]) leaked = 1;
      dtest_note(t, "leak check (close vs before): %s", leaked ? "MISMATCH - see counts above" : "MATCH, nothing leaked");
      if (leaked) bad++;
    }
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_images", 0, body); }
