/*
 * Tests/test_deep_t2.c - T2 deep paths of issue #100: isolated tests that allocate or change state PRIVATE to the connection / surface and undo it on close,
 * each on its own fresh connection, with a leak check around it (the IOKitDiagnostics instance counts of the driver's classes and the loaded-kext list must be
 * identical before and after). Run with `./parity_test_harness --deep` (after the T1 tests); oracle: baseline/stock_4.1.9_g5_tiger_deep.txt.
 *
 * Every call below is one the earlier probes made live on the stock kext without incident (Tests/probe_surface_read_lock.c, probe_readonly_checklock.c):
 * the only new element is asserting the whole sequence. The path of each call was traced in the stock body (Tests/deep_paths.md, Sources/IOATIR500Surface_*):
 *   set_id_mode(0, 0x4)        creates the id-0 record (no VRAM) - the precondition of every call below
 *   surface_query_lock         "availability check": CannotLock while a lock byte (+0xbd0/+0xbd1) is set or the record has no buffer, else success
 *   surface_read_lock_options  lockOptions 0: the 'granted-pending, no allocation' tail (no alloc_surfaces_retry / prepare_vram / GART mapping)
 *   surface_read_unlock_options (sel 1: ONE scalar in - a call with zero scalars is rejected by IOKit's dispatch with BadArgument before the body runs)
 *                              clears the lock byte; the vtable-0x600 completion call only runs when the buffer already owns VRAM (+8 != 0), not here
 */
#include "common.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

extern int g_testsRun, g_testsUnexpected, g_testsRecorded;

static void check(const char *name, int cond, const char *fmt, ...) {
    char msg[200]; va_list ap; msg[0] = 0;
    if (fmt) { va_start(ap, fmt); vsnprintf(msg, sizeof msg, fmt, ap); va_end(ap); }
    g_testsRun++; printf("[%s] %s%s%s\n", cond ? "OK" : "UNEXPECTED", name, msg[0] ? " " : "", msg); if (!cond) g_testsUnexpected++;
}

#define NCLS 6
static const char *kClasses[NCLS] = { "ATIR500Surface", "ATIR5002DContext", "ATIR500GLContext", "ATIR500DVDContext", "IOATIR500Shared", "ATIR500Memory" };

/* instance counts of the driver's classes from the IOKitDiagnostics property (`"Name"=N` inside "Classes") */
static int class_counts(int *out) {
    FILE *p = popen("/usr/sbin/ioreg -l -w0 | grep IOKitDiagnostics", "r"); char *buf = malloc(200000); size_t n; int i;
    if (!p || !buf) return -1;
    n = fread(buf, 1, 199999, p); buf[n] = 0; pclose(p);
    for (i = 0; i < NCLS; i++) {
        char key[80]; char *q; snprintf(key, sizeof key, "\"%s\"=", kClasses[i]);
        q = strstr(buf, key); out[i] = q ? atoi(q + strlen(key)) : -1;
    }
    free(buf); return 0;
}
static int kext_count(void) {
    FILE *p = popen("kextstat | grep -c -i ATIRadeonX1000", "r"); int n = -1; char l[64];
    if (p) { if (fgets(l, sizeof l, p)) n = atoi(l); pclose(p); } return n;
}

static void lock_round_trip(io_service_t service) {
    int before[NCLS], after[NCLS], i, same = 1, k0, k1; io_connect_t c = IO_OBJECT_NULL; kern_return_t r, rq0, rq1, rq2, rq3, rl, ru, ru2;
    unsigned char data[0x44], data2[0x44]; IOByteCount sz = sizeof data;
    printf("-- Surface T2: read-lock round trip (lockOptions 0) --\n");
    class_counts(before); k0 = kext_count();
    r = open_user_client(service, CLIENT_TYPE_SURFACE, &c);
    if (r != TEST_kIOReturnSuccess) { printf("[FAIL] Surface open 0x%08x\n", (unsigned int)r); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(c, 7, 2, 0, 0, 0x4);
    check("Surface set_id_mode(0,0x4) [precondition]", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    rq0 = IOConnectMethodScalarIScalarO(c, 11, 0, 0);
    check("Surface query_lock after set_id_mode: available (0) - the record is valid and nothing is held", rq0 == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)rq0);
    memset(data, 0xAA, sizeof data);
    rl = IOConnectMethodScalarIStructureO(c, 0, 1, &sz, 0, data);
    check("Surface surface_read_lock_options(lockOptions=0) succeeds, 0x44 bytes", rl == TEST_kIOReturnSuccess && sz == 0x44, "r=0x%08x size=%u", (unsigned int)rl, (unsigned int)sz);
    rq1 = IOConnectMethodScalarIScalarO(c, 11, 0, 0);
    check("Surface query_lock while the read lock is held -> CannotLock", rq1 == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)rq1);
    { int again; unsigned char d2[0x44]; IOByteCount s2 = sizeof d2; memset(d2, 0, sizeof d2);
      again = IOConnectMethodScalarIStructureO(c, 0, 1, &s2, 0, d2);
      check("Surface second read lock on the same connection while held -> CannotLock (lock byte already set)", again == (int)TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)again); }
    ru = IOConnectMethodScalarIScalarO(c, 1, 1, 0, 0);
    check("Surface surface_read_unlock_options after the lock succeeds", ru == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)ru);
    rq2 = IOConnectMethodScalarIScalarO(c, 11, 0, 0);
    check("Surface query_lock after the unlock: available again", rq2 == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)rq2);
    ru2 = IOConnectMethodScalarIScalarO(c, 1, 1, 0, 0);
    check("Surface surface_read_unlock_options a second time -> CannotLock (nothing held)", ru2 == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)ru2);
    sz = sizeof data2; memset(data2, 0xBB, sizeof data2);
    r = IOConnectMethodScalarIStructureO(c, 0, 1, &sz, 0, data2);
    check("Surface read lock again after unlock: same output struct as the first lock (deterministic)", r == TEST_kIOReturnSuccess && memcmp(data, data2, sizeof data) == 0, "r=0x%08x", (unsigned int)r);
    rq3 = IOConnectMethodScalarIScalarO(c, 1, 1, 0, 0);
    check("Surface read unlock (cleanup, so close leaves no lock)", rq3 == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)rq3);
    IOServiceClose(c);
    usleep(300000);   /* the user client is torn down asynchronously */
    class_counts(after); k1 = kext_count();
    for (i = 0; i < NCLS; i++) if (before[i] != after[i]) same = 0;
    check("leak check: driver class instance counts identical before/after (Surface/2D/GL/DVD/Shared/Memory)", same, "before={%d,%d,%d,%d,%d,%d} after={%d,%d,%d,%d,%d,%d}", before[0], before[1], before[2], before[3], before[4], before[5], after[0], after[1], after[2], after[3], after[4], after[5]);
    check("leak check: the ATI kext list is unchanged", k0 == k1, "%d vs %d", k0, k1);
}

void run_deep_t2_tests(io_service_t service) {
    lock_round_trip(service);
}
