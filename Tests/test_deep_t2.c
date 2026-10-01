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


/* T2 row 2 (issue #100): bind a real Surface-registered surface to a GL context, read it back, detach.
 * Sequence = three calls proven live in the #42 harness (Surface set_id_mode(1,0x0), set_id_mode(1,0x20), set_shape(0,1,4x4 region)) then GL set_surface(1, modeBits 0, 0, 0).
 * Traced offline (Tests/deep_paths_notes.tsv, GL 0): with modeBits 0 and no other context on the surface the body takes the first branch (no setCompatibleSurfaceMode), then
 * req-bits / add_gl_context_to_list / prune_buffers / update_surface (build_scissor + invalidate): memory only. find_surface_for_id matches surface+0xa4 == id. */
static void gl_bind_round_trip(io_service_t service) {
    int before[NCLS], after[NCLS], i, same = 1, k0, k1; io_connect_t s = IO_OBJECT_NULL, g = IO_OBJECT_NULL; kern_return_t r;
    unsigned char region[20]; int sz[4] = {-1, -1, -1, -1}, sz2[4] = {-1, -1, -1, -1}, info[3] = {-1, -1, -1};
    printf("-- GL T2: bind a registered surface, read it back, detach --\n");
    class_counts(before); k0 = kext_count();
    if (open_user_client(service, CLIENT_TYPE_SURFACE, &s) != TEST_kIOReturnSuccess) { printf("[FAIL] Surface open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x0);
    check("Surface set_id_mode(1,0x0) [precondition]", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    if (r == TEST_kIOReturnSuccess) r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x20);
    check("Surface set_id_mode(1,0x20) [precondition]", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    if (r == TEST_kIOReturnSuccess) {
        memset(region, 0, sizeof region);
        *(UInt32 *)(region + 0) = 1; *(SInt16 *)(region + 8) = 4; *(SInt16 *)(region + 10) = 4; *(SInt16 *)(region + 16) = 4; *(SInt16 *)(region + 18) = 4;
        r = IOConnectMethodScalarIStructureI(s, 9, 2, sizeof region, 0, 1, region);
        check("Surface set_shape(sel 9) [precondition]", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    }
    if (r == TEST_kIOReturnSuccess && open_user_client(service, CLIENT_TYPE_GL, &g) == TEST_kIOReturnSuccess) {
        r = IOConnectMethodScalarIScalarO(g, 5, 0, 4, &sz[0], &sz[1], &sz[2], &sz[3]);
        check("GL get_surface_size before binding -> Error (stock baseline)", r == TEST_kIOReturnError, "r=0x%08x", (unsigned int)r);
        r = IOConnectMethodScalarIStructureI(g, 0, 4, 0, 1, 0, 0, 0, NULL);
        check("GL set_surface(1, modeBits 0) binds the registered surface", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
        if (r == TEST_kIOReturnSuccess) {
            r = IOConnectMethodScalarIScalarO(g, 5, 0, 4, &sz[0], &sz[1], &sz[2], &sz[3]);
            check("GL get_surface_size with a surface bound == the 4x4 shape set by set_shape (stock: {4,4,4,4})", r == TEST_kIOReturnSuccess && sz[0] == 4 && sz[1] == 4 && sz[2] == 4 && sz[3] == 4, "r=0x%08x size={%d,%d,%d,%d}", (unsigned int)r, sz[0], sz[1], sz[2], sz[3]);
            r = IOConnectMethodScalarIScalarO(g, 5, 0, 4, &sz2[0], &sz2[1], &sz2[2], &sz2[3]);
            check("GL get_surface_size is repeatable", r == TEST_kIOReturnSuccess && !memcmp(sz, sz2, sizeof sz), NULL);
            r = IOConnectMethodScalarIScalarO(g, 6, 1, 3, 1, &info[0], &info[1], &info[2]);
            check("GL get_surface_info(sel 6, id 1) == {32,4,4} (stock observed: 32 = bits per pixel, then the 4x4 shape)", r == TEST_kIOReturnSuccess && info[0] == 32 && info[1] == 4 && info[2] == 4, "r=0x%08x info={%d,%d,%d}", (unsigned int)r, info[0], info[1], info[2]);
            r = IOConnectMethodScalarIStructureI(g, 0, 4, 0, 0, 0, 0, 0, NULL);
            check("GL set_surface(0) detaches", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIScalarO(g, 5, 0, 4, &sz[0], &sz[1], &sz[2], &sz[3]);
            check("GL get_surface_size after detaching -> Error again", r == TEST_kIOReturnError, "r=0x%08x", (unsigned int)r);
        }
        IOServiceClose(g);
    } else if (r == TEST_kIOReturnSuccess) { printf("[FAIL] GL open\n"); g_testsUnexpected++; }
    IOServiceClose(s);
    usleep(300000);
    class_counts(after); k1 = kext_count();
    for (i = 0; i < NCLS; i++) if (before[i] != after[i]) same = 0;
    check("leak check: driver class instance counts identical before/after", same, "before={%d,%d,%d,%d,%d,%d} after={%d,%d,%d,%d,%d,%d}", before[0], before[1], before[2], before[3], before[4], before[5], after[0], after[1], after[2], after[3], after[4], after[5]);
    check("leak check: the ATI kext list is unchanged", k0 == k1, "%d vs %d", k0, k1);
}

/* T2 row 3 (issue #100): the DVD twin of row 2. IOATIR500DVDContext::set_surface (0xfa40) was traced: find_surface_for_id, remove_dvd_context / set_dvd_context,
 * reset_req_bits, prune_buffers, update_surface = ATIR500DVDContext::build_scissor (a 16-byte tail call; reads surface fields only). The bound-surface rows reached
 * afterwards - show_buffer, dvd_enable_overlay, dvd_setup_subpicture - end in ATIR500Surface::showbuffer / enable_overlay / disable_overlay / dvd_setup_subpicture,
 * which are `blr` stubs in the shipped kext (size_compare: stock 16 B padded, no instructions but the return), so they only run their lock + guard. */
static void dvd_bind_round_trip(io_service_t service) {
    int before[NCLS], after[NCLS], i, same = 1, k0, k1; io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r;
    unsigned char region[20]; int d0 = -1, d1 = -1, e0 = -1, e1 = -1;
    printf("-- DVD T2: bind a registered surface, bound-surface rows, detach --\n");
    class_counts(before); k0 = kext_count();
    if (open_user_client(service, CLIENT_TYPE_SURFACE, &s) != TEST_kIOReturnSuccess) { printf("[FAIL] Surface open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x0);
    if (r == TEST_kIOReturnSuccess) r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x20);
    if (r == TEST_kIOReturnSuccess) {
        memset(region, 0, sizeof region);
        *(UInt32 *)(region + 0) = 1; *(SInt16 *)(region + 8) = 4; *(SInt16 *)(region + 10) = 4; *(SInt16 *)(region + 16) = 4; *(SInt16 *)(region + 18) = 4;
        r = IOConnectMethodScalarIStructureI(s, 9, 2, sizeof region, 0, 1, region);
    }
    check("Surface preconditions (set_id_mode x2, set_shape)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    if (r == TEST_kIOReturnSuccess && open_user_client(service, CLIENT_TYPE_DVD, &d) == TEST_kIOReturnSuccess) {
        r = IOConnectMethodScalarIScalarO(d, 10, 2, 0, 0, 0);
        check("DVD show_buffer(sel 10) unbound -> Error (stock baseline)", r == TEST_kIOReturnError, "r=0x%08x", (unsigned int)r);
        r = IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL);
        check("DVD set_surface(1, modeBits 0, 0) binds the registered surface", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
        if (r == TEST_kIOReturnSuccess) {
            r = IOConnectMethodScalarIScalarO(d, 3, 0, 2, &d0, &d1);
            check("DVD get_surface_size with a surface bound == {768,576} (stock observed: the default 768x576 buffer record at surface+0xa8/+0x120, not the 4x4 shape)", r == TEST_kIOReturnSuccess && d0 == 768 && d1 == 576, "r=0x%08x size={%d,%d}", (unsigned int)r, d0, d1);
            r = IOConnectMethodScalarIScalarO(d, 3, 0, 2, &e0, &e1);
            check("DVD get_surface_size is repeatable", r == TEST_kIOReturnSuccess && d0 == e0 && d1 == e1, NULL);
            r = IOConnectMethodScalarIScalarO(d, 10, 2, 0, 0, 0);
            check("DVD show_buffer(sel 10) bound -> success (stub body)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIScalarO(d, 12, 1, 0, 0);
            check("DVD dvd_enable_overlay(sel 12, 0) bound -> success (stub body)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIScalarO(d, 15, 4, 0, 0, 0, 0, 0);
            check("DVD dvd_setup_subpicture(sel 15, 0,0,0,0) bound -> success (stub body)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL);
            check("DVD set_surface(0) detaches", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIScalarO(d, 3, 0, 2, &e0, &e1);
            check("DVD get_surface_size after detaching -> Error again", r == TEST_kIOReturnError, "r=0x%08x", (unsigned int)r);
        }
        IOServiceClose(d);
    } else if (r == TEST_kIOReturnSuccess) { printf("[FAIL] DVD open\n"); g_testsUnexpected++; }
    IOServiceClose(s);
    usleep(300000);
    class_counts(after); k1 = kext_count();
    for (i = 0; i < NCLS; i++) if (before[i] != after[i]) same = 0;
    check("leak check: driver class instance counts identical before/after", same, "before={%d,%d,%d,%d,%d,%d} after={%d,%d,%d,%d,%d,%d}", before[0], before[1], before[2], before[3], before[4], before[5], after[0], after[1], after[2], after[3], after[4], after[5]);
    check("leak check: the ATI kext list is unchanged", k0 == k1, "%d vs %d", k0, k1);
}

void run_deep_t2_tests(io_service_t service) {
    lock_round_trip(service);
    gl_bind_round_trip(service);
    dvd_bind_round_trip(service);
}
