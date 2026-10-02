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

/* T2 row 4 (issue #100): the other unlock selectors after a read lock. Traced (IOATIR500Surface::surface_unlock_options, 0x14f60): the READ lock lives in the byte at
 * surface+0xbd0, the WRITE lock in +0xbd1; unlock(type) looks at its own byte only: zero -> CannotLock, state untouched; the wrappers sel 13 (surface_read_unlock) /
 * sel 1 (surface_read_unlock_options) use type 1, sel 15 (surface_write_unlock) / sel 4 (surface_write_unlock_options) type 2. */
static void lock_unlock_variants(io_service_t service) {
    int before[NCLS], after[NCLS], i, same = 1; io_connect_t c = IO_OBJECT_NULL; kern_return_t r; unsigned char data[0x44]; IOByteCount sz = sizeof data;
    printf("-- Surface T2: unlock variants after a read lock --\n");
    class_counts(before);
    if (open_user_client(service, CLIENT_TYPE_SURFACE, &c) != TEST_kIOReturnSuccess) { printf("[FAIL] Surface open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(c, 7, 2, 0, 0, 0x4);
    check("Surface set_id_mode(0,0x4) [precondition]", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIStructureO(c, 0, 1, &sz, 0, data);
    check("Surface read lock (lockOptions 0)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 4, 1, 0, 0);
    check("Surface write_unlock_options(sel 4) while only the READ lock is held -> CannotLock", r == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 15, 0, 0);
    check("Surface surface_write_unlock(sel 15) while only the READ lock is held -> CannotLock", r == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 11, 0, 0);
    check("Surface query_lock: the read lock is still held after the two refused write unlocks -> CannotLock", r == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 13, 0, 0);
    check("Surface surface_read_unlock(sel 13) releases the read lock", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 11, 0, 0);
    check("Surface query_lock after sel 13 -> available", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 13, 0, 0);
    check("Surface surface_read_unlock(sel 13) a second time -> CannotLock", r == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)r);
    sz = sizeof data;
    r = IOConnectMethodScalarIStructureO(c, 0, 1, &sz, 0, data);
    check("Surface read lock again", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 1, 1, 0, 0);
    check("Surface read_unlock_options(sel 1) releases it (cleanup)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    IOServiceClose(c);
    usleep(300000);
    class_counts(after);
    for (i = 0; i < NCLS; i++) if (before[i] != after[i]) same = 0;
    check("leak check: driver class instance counts identical before/after", same, "before={%d,%d,%d,%d,%d,%d} after={%d,%d,%d,%d,%d,%d}", before[0], before[1], before[2], before[3], before[4], before[5], after[0], after[1], after[2], after[3], after[4], after[5]);
}

/* T2 row 5 (issue #100): set_id_mode (sel 7) error paths. Traced (IOATIR500Surface::set_id_mode, 0x142b0): (a) mode bits with any of 0xffff7fc0 set -> BadArgument BEFORE the lock is taken;
 * (b) a read or write lock held (surface+0xbd0/+0xbd1 non-zero) -> CannotLock, state untouched; otherwise the success path the harness already uses. */
static void set_id_mode_errors(io_service_t service) {
    io_connect_t c = IO_OBJECT_NULL; kern_return_t r; unsigned char data[0x44]; IOByteCount sz = sizeof data;
    printf("-- Surface T2: set_id_mode error paths --\n");
    if (open_user_client(service, CLIENT_TYPE_SURFACE, &c) != TEST_kIOReturnSuccess) { printf("[FAIL] Surface open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(c, 7, 2, 0, 0, 0x40);
    check("Surface set_id_mode(0, 0x40): a mode bit outside the accepted set -> BadArgument", r == TEST_kIOReturnBadArgument, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 7, 2, 0, 0, 0x80000000);
    check("Surface set_id_mode(0, 0x80000000) -> BadArgument", r == TEST_kIOReturnBadArgument, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 7, 2, 0, 0, 0x4);
    check("Surface set_id_mode(0, 0x4) [precondition]", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIStructureO(c, 0, 1, &sz, 0, data);
    check("Surface read lock (lockOptions 0)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 7, 2, 0, 0, 0x4);
    check("Surface set_id_mode(0, 0x4) while the read lock is held -> CannotLock", r == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 1, 1, 0, 0);
    check("Surface read_unlock_options releases the lock", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 7, 2, 0, 0, 0x4);
    check("Surface set_id_mode(0, 0x4) after the unlock succeeds again", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    IOServiceClose(c);
}

/* T2 row 6 (issue #100): set_swap_rect (sel 1) / set_swap_interval (sel 2) with a surface bound. Each stores shorts in the context (this+0x90..0x9a) and, with a bound
 * surface, calls vtable 0x5c4 = ATIR500Surface::invalidate, which ORs 1 into word +0x1c of the swap-buffer header at surface+0xc34+i*0x94 for every panel i < accelerator+0xcc.
 * Hazard analysis (Tests/deep_paths_notes.tsv, GL 1): that header pointer is set by IOATIR500Surface::start -> allocMasterSwapBuffer(panel, 0x9000) whenever the
 * accelerator's per-panel swap-buffer count (+0x114+4*panel) is non-zero; the count is written only with 1 (IOATIR500Accelerator::start, teardown3D, disp_mode_did_change)
 * or 2 (setup_stereo), never 0 - so every panel's header is valid after a successful surface start. */
static void gl_swap_params_bound(io_service_t service) {
    io_connect_t s = IO_OBJECT_NULL, g = IO_OBJECT_NULL; kern_return_t r; unsigned char region[20];
    printf("-- GL T2: set_swap_rect / set_swap_interval with a bound surface --\n");
    if (open_user_client(service, CLIENT_TYPE_SURFACE, &s) != TEST_kIOReturnSuccess) { printf("[FAIL] Surface open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x0);
    if (r == TEST_kIOReturnSuccess) r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x20);
    if (r == TEST_kIOReturnSuccess) {
        memset(region, 0, sizeof region);
        *(UInt32 *)(region + 0) = 1; *(SInt16 *)(region + 8) = 4; *(SInt16 *)(region + 10) = 4; *(SInt16 *)(region + 16) = 4; *(SInt16 *)(region + 18) = 4;
        r = IOConnectMethodScalarIStructureI(s, 9, 2, sizeof region, 0, 1, region);
    }
    check("Surface preconditions (set_id_mode x2, set_shape)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    if (r == TEST_kIOReturnSuccess && open_user_client(service, CLIENT_TYPE_GL, &g) == TEST_kIOReturnSuccess) {
        r = IOConnectMethodScalarIStructureI(g, 0, 4, 0, 1, 0, 0, 0, NULL);
        check("GL set_surface(1, 0, 0, 0) binds", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
        if (r == TEST_kIOReturnSuccess) {
            r = IOConnectMethodScalarIStructureI(g, 1, 4, 0, 0, 0, 4, 4, NULL);
            check("GL set_swap_rect(0,0,4,4) with a surface bound -> success", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIStructureI(g, 2, 2, 0, 1, 0, NULL);
            check("GL set_swap_interval(1,0) with a surface bound -> success", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIStructureI(g, 1, 4, 0, 0, 0, 0, 0, NULL);
            check("GL set_swap_rect(0,0,0,0) restores the defaults", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIStructureI(g, 2, 2, 0, 0, 0, NULL);
            check("GL set_swap_interval(0,0) restores the defaults", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIStructureI(g, 0, 4, 0, 0, 0, 0, 0, NULL);
            check("GL set_surface(0) detaches", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
        }
        IOServiceClose(g);
    } else if (r == TEST_kIOReturnSuccess) { printf("[FAIL] GL open\n"); g_testsUnexpected++; }
    IOServiceClose(s);
}

/* T2 row 7 (issue #100): the 2D twin. IOATIR5002DContext::set_surface (0xc570) with mode bit 0x800 resolves a registered surface id (find_surface_for_id), links the context
 * (add_2d_context_to_list), prune_buffers, calls vtable 0x5a4 = ATIR5002DContext::invalidate (ORs 1 into word +0x1c of *(this+0xc8), already executed by the panel-mode
 * baseline call) and vtable 0x5b0 = set_destination -> get_buffer_info(surface, ...) whose surface path only READS the surface's record (+0xb70, +0xbe4/+0xbe6). With bit
 * 0x800 clear the id is a panel index (the #42 baseline); set_surface(0, 0x800) detaches and returns the panel-0 info. */
static void twod_bind_round_trip(io_service_t service) {
    int before[NCLS], after[NCLS], i, same = 1; io_connect_t s = IO_OBJECT_NULL, t = IO_OBJECT_NULL; kern_return_t r;
    unsigned char region[20], out[0x30], out2[0x30], base[0x30]; IOByteCount osz;
    printf("-- 2D T2: bind a registered surface by id, read its info, detach --\n");
    class_counts(before);
    if (open_user_client(service, CLIENT_TYPE_SURFACE, &s) != TEST_kIOReturnSuccess) { printf("[FAIL] Surface open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x0);
    if (r == TEST_kIOReturnSuccess) r = IOConnectMethodScalarIScalarO(s, 7, 2, 0, 1, 0x20);
    if (r == TEST_kIOReturnSuccess) {
        memset(region, 0, sizeof region);
        *(UInt32 *)(region + 0) = 1; *(SInt16 *)(region + 8) = 4; *(SInt16 *)(region + 10) = 4; *(SInt16 *)(region + 16) = 4; *(SInt16 *)(region + 18) = 4;
        r = IOConnectMethodScalarIStructureI(s, 9, 2, sizeof region, 0, 1, region);
    }
    check("Surface preconditions (set_id_mode x2, set_shape)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    if (r == TEST_kIOReturnSuccess && open_user_client(service, CLIENT_TYPE_2D, &t) == TEST_kIOReturnSuccess) {
        UInt32 *d = (UInt32 *)out;
        osz = sizeof base; memset(base, 0xAA, sizeof base);
        r = IOConnectMethodScalarIStructureO(t, 0, 2, &osz, 0, 0, base);
        check("2D set_surface(panel 0) [the #42 baseline call] succeeds", r == TEST_kIOReturnSuccess && osz == 0x30, "r=0x%08x", (unsigned int)r);
        osz = sizeof out; memset(out, 0xAA, sizeof out);
        r = IOConnectMethodScalarIStructureO(t, 0, 2, &osz, 1, 0x800, out);
        check("2D set_surface(id 1, mode 0x800) binds the registered surface, 0x30-byte info", r == TEST_kIOReturnSuccess && osz == 0x30, "r=0x%08x size=%u", (unsigned int)r, (unsigned int)osz);
        if (r == TEST_kIOReturnSuccess) {
            printf("[INFO] bound info d[2..7]={%u,%u,0x%x,%u,%u,%u}\n", (unsigned)d[2], (unsigned)d[3], (unsigned)d[4], (unsigned)d[5], (unsigned)d[6], (unsigned)d[7]);
            check("2D bound info d[2], d[3] are the surface's recorded size (the 4x4 shape)", d[2] == 4 && d[3] == 4, "d[2]=%u d[3]=%u", (unsigned)d[2], (unsigned)d[3]);
            osz = sizeof out2; memset(out2, 0x55, sizeof out2);
            r = IOConnectMethodScalarIStructureO(t, 2, 2, &osz, 1, 0x800, out2);
            check("2D get_surface_info(id 1, mode 0x800) returns the same info", r == TEST_kIOReturnSuccess && osz == 0x30 && !memcmp(out, out2, sizeof out), "r=0x%08x", (unsigned int)r);
            osz = sizeof out2; memset(out2, 0x55, sizeof out2);
            r = IOConnectMethodScalarIStructureO(t, 0, 2, &osz, 0, 0x800, out2);
            check("2D set_surface(0, mode 0x800) detaches and returns the panel info of the baseline call", r == TEST_kIOReturnSuccess && osz == 0x30 && !memcmp(base, out2, sizeof base), "r=0x%08x", (unsigned int)r);
        }
        IOServiceClose(t);
    } else if (r == TEST_kIOReturnSuccess) { printf("[FAIL] 2D open\n"); g_testsUnexpected++; }
    IOServiceClose(s);
    usleep(300000);
    class_counts(after);
    for (i = 0; i < NCLS; i++) if (before[i] != after[i]) same = 0;
    check("leak check: driver class instance counts identical before/after", same, "before={%d,%d,%d,%d,%d,%d} after={%d,%d,%d,%d,%d,%d}", before[0], before[1], before[2], before[3], before[4], before[5], after[0], after[1], after[2], after[3], after[4], after[5]);
}

/* T2 row 8 (issue #100): GL wait_for_stamp (sel 9) / finish (sel 8). Shipped wait_for_stamp (0x7de0): `r = accelerator->vtable[0x550](accelerator, stamp)`; r == -1 -> Timeout (0xe00002d6),
 * else accelerator[0x768] += r. The stamp reaches the callee because r4 is left untouched (a decompile-dropped argument: the first #86 fix wrongly called it unused and this
 * test's first run caught it: a stamp that was never submitted times out). finish (0x7d60) is the same with this+0x7c (the last submitted stamp) as the argument. */
static void gl_wait_finish(io_service_t service) {
    io_connect_t g = IO_OBJECT_NULL; kern_return_t r;
    printf("-- GL T2: wait_for_stamp / finish --\n");
    g = IO_OBJECT_NULL;
    if (open_user_client(service, CLIENT_TYPE_GL, &g) != TEST_kIOReturnSuccess) { printf("[FAIL] GL open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIStructureI(g, 9, 1, 0, 0, NULL);
    check("GL wait_for_stamp(0) -> 0 (baseline)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIStructureI(g, 9, 1, 0, 5, NULL);
    check("GL wait_for_stamp(5) -> 0 (a stamp the GPU has already passed)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIStructureI(g, 9, 1, 0, 0x7fffffff, NULL);
    check("GL wait_for_stamp(0x7fffffff) -> Timeout 0xe00002d6 (a stamp that was never submitted; bounded wait)", r == 0xe00002d6, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIStructureI(g, 8, 0, 0, NULL);
    check("GL finish -> 0", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    IOServiceClose(g);
}

/* T2 row 9 (issue #100): DVD check_stamps (sel 20, stamps a, b -> bothDone). Shipped 0x341a0: a != 0 -> accelerator vtable +0x5f4 with r4 (= a, left untouched: forwarded; the
 * decompile dropped it), b != 0 -> vtable +0x554(b); zero counts as done; bothDone = both results non-zero. Read-only stamp comparisons. */
static void dvd_check_stamps_values(io_service_t service) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int both = -1;
    printf("-- DVD T2: check_stamps with real values --\n");
    if (open_user_client(service, CLIENT_TYPE_DVD, &d) != TEST_kIOReturnSuccess) { printf("[FAIL] DVD open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIScalarO(d, 20, 2, 1, 5, 5, &both);
    /* live result on stock: both=0 - ATIRadeonX1000::checkForTimeStamp (0x1e090) is done iff stamp <= the counter cached at +0x54 / read from the GPU (+0x864/+0x86c); an idle counter below 5 explains both=0, but the counter value itself is not read here */
    check("DVD check_stamps(5,5) call succeeds and writes a 0/1 result", r == TEST_kIOReturnSuccess && (both == 0 || both == 1), "r=0x%08x both=%d (recorded: 0 on stock)", (unsigned int)r, both);
    r = IOConnectMethodScalarIScalarO(d, 20, 2, 1, 0x7fffffff, 0, &both);
    check("DVD check_stamps(0x7fffffff,0) -> not done (first stamp never submitted)", r == TEST_kIOReturnSuccess && both == 0, "r=0x%08x both=%d", (unsigned int)r, both);
    r = IOConnectMethodScalarIScalarO(d, 20, 2, 1, 0, 0x7fffffff, &both);
    check("DVD check_stamps(0,0x7fffffff) -> not done (second stamp never submitted)", r == TEST_kIOReturnSuccess && both == 0, "r=0x%08x both=%d", (unsigned int)r, both);
    IOServiceClose(d);
}

/* T2 row 10 (issue #100): DVD bound-surface setters. Traced (Sources/ATIR500DVDContext_dvd_setup_overlay/enable_deint/setup_buffers_Port.cpp, shipped 0x34d50/0x34c90/0x34260):
 * all three only write fields of the bound surface (+0x94..+0x9a overlay geometry, +0xbed/+0xbee dirty flags, +0xda4, the deinterlace mode) and the context's own +0x88;
 * no hardware access, no allocation. Unbound -> Error (setup_buffers -> NotReady, it has no unbound check of its own: 0xe00002d8 when +0xf8 == NULL). The overlay-enable
 * value (param 5) is kept 0: that path only sets the two dirty flags. State is private to the registered surface and dies with the connections. */
static void dvd_bound_setters(io_service_t service) {
    int before[NCLS], after[NCLS], i, same = 1, k0, k1; io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r;
    unsigned char region[20];
    printf("-- DVD T2: setup_overlay / enable_deint / setup_buffers on a bound surface --\n");
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
        r = IOConnectMethodScalarIScalarO(d, 11, 5, 0, 0, 0, 0, 0, 0);
        check("DVD dvd_setup_overlay unbound -> Error (stock: 0xe00002bc)", r == TEST_kIOReturnError, "r=0x%08x", (unsigned int)r);
        r = IOConnectMethodScalarIScalarO(d, 17, 1, 0, 0);
        check("DVD dvd_enable_deint unbound -> Error", r == TEST_kIOReturnError, "r=0x%08x", (unsigned int)r);
        r = IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 0, 0, 0, 0);
        check("DVD setup_buffers unbound -> NotReady (0xe00002d8: no surface = same code as hardware-down)", r == (kern_return_t)0xe00002d8, "r=0x%08x", (unsigned int)r);
        r = IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL);
        check("DVD set_surface(1,0,0) binds", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
        if (r == TEST_kIOReturnSuccess) {
            r = IOConnectMethodScalarIScalarO(d, 11, 5, 0, 0, 0, 16, 16, 0, 0);
            check("DVD dvd_setup_overlay(0,0,16,16, enable 0) bound -> success", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIScalarO(d, 17, 1, 0, 1);
            check("DVD dvd_enable_deint(1) bound -> success", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIScalarO(d, 17, 1, 0, 0);
            check("DVD dvd_enable_deint(0) bound -> success", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 0, 16, 16, 0);
            check("DVD setup_buffers(0,0,16,16,0) bound -> success", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
            r = IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL);
            check("DVD set_surface(0) detaches", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
        }
        IOServiceClose(d);
    } else if (r == TEST_kIOReturnSuccess) { printf("[FAIL] DVD open\n"); g_testsUnexpected++; }
    IOServiceClose(s);
    usleep(300000);
    class_counts(after); k1 = kext_count();
    for (i = 0; i < NCLS; i++) if (before[i] != after[i]) same = 0;
    check("leak check: driver class instance counts identical before/after", same, NULL);
    check("leak check: the ATI kext list is unchanged", k0 == k1, "%d vs %d", k0, k1);
}

/* T2 row 11 (issue #100): 2D finish modes. Traced (IOATIR5002DContext_finish_Port.cpp, shipped 0xbdc0): mode 0 waits on this context's own last stamp (+0x7c), mode 1 / mode 2
 * wait on accelerator +0x50 - 1 through accelerator vtable +0x55c / +0x558 (the same bounded wait primitives the GL wait_for_stamp row uses: success, or Timeout 0xe00002d6),
 * any other mode -> BadArgument before touching anything. The only state changed is the accelerator's wait statistics (+0x7a0/+0x7a4). The stamp state is not controlled here,
 * so modes 1 and 2 accept success or Timeout; the invalid mode is asserted exactly. */
static void twod_finish_modes(io_service_t service) {
    io_connect_t c = IO_OBJECT_NULL; kern_return_t r; int m;
    printf("-- 2D T2: finish modes --\n");
    if (open_user_client(service, CLIENT_TYPE_2D, &c) != TEST_kIOReturnSuccess) { printf("[FAIL] 2D open\n"); g_testsUnexpected++; return; }
    r = IOConnectMethodScalarIStructureI(c, 7, 1, 0, 3, NULL);
    check("2D finish(3) -> BadArgument (stock)", r == TEST_kIOReturnBadArgument, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIStructureI(c, 7, 1, 0, 0, NULL);
    check("2D finish(0) -> 0 (baseline)", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    for (m = 1; m <= 2; m++) {
        r = IOConnectMethodScalarIStructureI(c, 7, 1, 0, m, NULL);
        check(m == 1 ? "2D finish(1) -> success or Timeout (bounded wait on the accelerator's last stamp)" : "2D finish(2) -> success or Timeout (bounded wait on the accelerator's last stamp)",
              r == TEST_kIOReturnSuccess || r == 0xe00002d6, "r=0x%08x", (unsigned int)r);
    }
    IOServiceClose(c);
}

void run_deep_t2_tests(io_service_t service) {
    lock_round_trip(service);
    gl_bind_round_trip(service);
    dvd_bind_round_trip(service);
    lock_unlock_variants(service);
    set_id_mode_errors(service);
    gl_swap_params_bound(service);
    twod_bind_round_trip(service);
    gl_wait_finish(service);
    dvd_check_stamps_values(service);
    dvd_bound_setters(service);
    twod_finish_modes(service);
}
