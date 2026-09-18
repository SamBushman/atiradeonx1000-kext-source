/*
 * Tests/probe_shape_backing.c -- deliberate, single, carefully-reasoned
 * live sequence to establish a real, validly-shaped surface and exercise
 * set_shape_backing (selector 6) - NOT a sweep, one fully-traced attempt.
 *
 * Full reasoning (see Sources/IOATIR500Surface_LockShape.cpp's own header
 * comments for set_id_mode/set_shape_backing_length_ext):
 *
 * 1. set_id_mode(id=1, modeBits=0) - already empirically confirmed safe
 *    and successful (probe_set_id_mode.c). Takes the SLOW/validated path
 *    (modeBits bit 0x20 clear), which allocates a real per-ID record at
 *    self+id*8+0xd60 (IOMallocAligned, 12 bytes) and sets self+0xbe8=0.
 * 2. set_id_mode(id=1, modeBits=0x20) - SAME already-traced function,
 *    fast path this time (bit 0x20 set in the CALLER's argument). Fast
 *    path unconditionally succeeds and sets self+0xbe8=0x20, but its own
 *    record-(re)allocation block is gated on `(self+0xbe8 & 0x20) == 0`
 *    - since that bit is now becoming SET, this block is skipped, so the
 *    record allocated in step 1 is left untouched and still valid. Net
 *    effect: self+0xbe8 now has bit 0x20 set AND the record is valid -
 *    both preconditions set_shape_backing_length_ext's own gate and its
 *    unguarded record dereference need.
 * 3. set_shape_backing(shapeBits=0, id=1, param3=0, param4=0, region,
 *    param6=0) - a real forward into set_shape_backing_length_ext with
 *    param7=0. With shapeBits=0: no retag, no spin-wait, degenerate
 *    checks are benign, param3=0/param4=0 means the backing-store
 *    (re)connect branch is skipped (param3Zero short-circuits it,
 *    avoiding a real allocation call this project hasn't separately
 *    verified), region validates cleanly, no swap/lock-family code is
 *    touched at all. The 20-byte `region` buffer below matches this
 *    project's own reconstructed byte layout exactly: count=1 (bytes
 *    0-3), unused (4-7), dims 4x4 packed as two SInt16 (8-11), one rect
 *    entry: value_a=0 (12-15), value_b packed as two SInt16 4x4 (16-19) -
 *    real structSize = 1*8+0xc = 20, matching param6=0's auto-compute.
 *
 * Wire shape for set_shape_backing itself has NO real call-site evidence
 * (flagged UNVERIFIED in Tests/test_surface_context.c) - this uses
 * IOConnectMethodScalarIStructureI with scalarInputCount=5 (matching the
 * function's 5 non-struct params) and structureSize=20. If this guess is
 * wrong, the kernel's own argument-count check rejects it with
 * kIOReturnBadArgument BEFORE the function body ever runs (already
 * empirically established behavior for every mismatched shape tried
 * earlier this session) - a safe failure mode, not a crash risk.
 */
#include "common.h"

int g_testsRun = 0;
int g_testsUnexpected = 0;
int g_testsSkipped = 0;

int main(void) {
    io_service_t service = find_accelerator_service();
    if (service == IO_OBJECT_NULL) { printf("no service\n"); fflush(stdout); return 1; }

    io_connect_t connect = IO_OBJECT_NULL;
    kern_return_t kr = open_user_client(service, CLIENT_TYPE_SURFACE, &connect);
    if (kr != TEST_kIOReturnSuccess) {
        printf("open failed: 0x%08x\n", (unsigned int)kr); fflush(stdout);
        return 1;
    }
    printf("opened Surface connect=0x%x\n", connect); fflush(stdout);

    printf("step 1: set_id_mode(1, 0x0) [slow path, allocates record]...\n"); fflush(stdout);
    kern_return_t r1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x0);
    printf("  -> 0x%08x (%s)\n", (unsigned int)r1, ioreturn_name(r1)); fflush(stdout);
    if (r1 != TEST_kIOReturnSuccess) {
        printf("step 1 did not succeed, stopping before step 2/3.\n"); fflush(stdout);
        IOServiceClose(connect); IOObjectRelease(service);
        return 1;
    }

    printf("step 2: set_id_mode(1, 0x20) [fast path, sets bit without touching record]...\n"); fflush(stdout);
    kern_return_t r2 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 1, 0x20);
    printf("  -> 0x%08x (%s)\n", (unsigned int)r2, ioreturn_name(r2)); fflush(stdout);
    if (r2 != TEST_kIOReturnSuccess) {
        printf("step 2 did not succeed, stopping before step 3.\n"); fflush(stdout);
        IOServiceClose(connect); IOObjectRelease(service);
        return 1;
    }

    printf("step 3: set_shape_backing(shapeBits=0, id=1, 0, 0, region, param6=0)...\n"); fflush(stdout);
    unsigned char region[20];
    memset(region, 0, sizeof(region));
    *(UInt32 *)(region + 0) = 1;      /* count = 1 rect */
    *(UInt32 *)(region + 4) = 0;      /* unused/unknown */
    *(SInt16 *)(region + 8) = 4;      /* dim1 */
    *(SInt16 *)(region + 10) = 4;     /* dim2 */
    *(SInt32 *)(region + 12) = 0;     /* rect0 value_a */
    *(SInt16 *)(region + 16) = 4;     /* rect0 value_b low */
    *(SInt16 *)(region + 18) = 4;     /* rect0 value_b high */

    IOByteCount structSize = sizeof(region);
    UInt32 shapeBits = 0, id = 1, param3 = 0, param4 = 0, param6 = 0;
    kern_return_t r3 = IOConnectMethodScalarIStructureI(connect, 6, 5, structSize,
                                                          shapeBits, id, param3, param4, param6, region);
    printf("  -> 0x%08x (%s)\n", (unsigned int)r3, ioreturn_name(r3)); fflush(stdout);

    printf("closing connection...\n"); fflush(stdout);
    IOServiceClose(connect);
    IOObjectRelease(service);
    printf("done, clean exit.\n"); fflush(stdout);
    return 0;
}
