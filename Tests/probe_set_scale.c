/*
 * Tests/probe_set_scale.c -- deliberate, single, fully-reasoned live call
 * to IOATIR500Surface::set_scale (selector 8), the "scaling disabled"
 * path specifically.
 *
 * Full reasoning (Sources/IOATIR500Surface_LockShape.cpp's set_scale,
 * Sources/IOATIR500Surface_ScalingAndState.cpp's set_scaling,
 * Sources/IOATIR500Surface_ContextTracking.cpp's prune_buffers):
 *
 * set_scale(flags=0, scaling=<any, unread>, param3=0):
 *   - param3==0 passes the top gate (param3 must be 0 or 0x2c).
 *   - passedScaling = (param3!=0) = false, so set_scaling is called with
 *     a null scaling pointer regardless of what we pass on the wire.
 *   - set_scaling(flags=0, nullptr): scalingDisabled = ((0>>1)&1)==0 =
 *     true. The `!scalingDisabled && scaling==null` reject check is
 *     false (scalingDisabled is true), so it proceeds into the
 *     "disabled" branch, which dereferences self+0xd60 (id=0's own
 *     hardcoded record - set_scale/set_scaling take no `id` parameter
 *     at all) to read a real width/height, then eventually reads
 *     self+0xb70 (as *(void**)(self+0xb70)) and calls the accelerator's
 *     real, already-CONFIRMED tmpAllocVRAM/+0x540 vtable pair.
 *
 * Precondition: self+0xd60 (id=0's record) and self+0xb70 must both be
 * real, valid, non-null pointers. BOTH are already established by a
 * single already-proven-safe call: set_id_mode(mode=0, modeBits=0x4)
 * (confirmed live success in probe_set_id_mode.c's bounded scan). That
 * call's own real body (traced in full) unconditionally calls
 * prune_buffers() on success, which - for a fresh surface with no linked
 * GL/2D/DVD contexts (self+0xc18 requirement bits stay 0) - sets
 * self+0xb70 to `accelerator + 0*0x78 + 300`, a real, valid pointer into
 * the (definitely large, definitely allocated) accelerator object. No
 * new setup call is needed beyond the one we've already run and verified
 * multiple times.
 *
 * Wire shape for set_scale has no call-site evidence (2 scalars + 1
 * struct pointer, guessed as scalarInputCount=2/structureSize=0x2c via
 * IOConnectMethodScalarIStructureI, matching this project's own
 * documented "plausible real IOAccelSurfaceScaling size" note) - if
 * wrong, expect a safe kIOReturnBadArgument from the kernel's own
 * argument-count check, not a crash, per every other shape-guess this
 * session.
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

    printf("step 1: set_id_mode(0, 0x4) [precondition: id=0 record + prune_buffers -> self+0xb70]...\n"); fflush(stdout);
    kern_return_t r1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 0, 0x4);
    printf("  -> 0x%08x (%s)\n", (unsigned int)r1, ioreturn_name(r1)); fflush(stdout);
    if (r1 != TEST_kIOReturnSuccess) {
        printf("step 1 did not succeed, stopping before step 2.\n"); fflush(stdout);
        IOServiceClose(connect); IOObjectRelease(service);
        return 1;
    }

    printf("step 2: set_scale(flags=0, scaling=<unread>, param3=0)...\n"); fflush(stdout);
    unsigned char scaling[0x2c];
    memset(scaling, 0, sizeof(scaling));
    IOByteCount structSize = sizeof(scaling);
    UInt32 flags = 0, param3 = 0;
    kern_return_t r2 = IOConnectMethodScalarIStructureI(connect, 8, 2, structSize, flags, param3, scaling);
    printf("  -> 0x%08x (%s)\n", (unsigned int)r2, ioreturn_name(r2)); fflush(stdout);

    printf("closing connection...\n"); fflush(stdout);
    IOServiceClose(connect);
    IOObjectRelease(service);
    printf("done, clean exit.\n"); fflush(stdout);
    return 0;
}
