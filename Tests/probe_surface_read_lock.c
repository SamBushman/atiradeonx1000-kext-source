/*
 * Tests/probe_surface_read_lock.c -- single, deliberate, fully-reasoned
 * live call to surface_read_lock_options (selector 0), after extensive
 * static + read-only-ish live groundwork:
 *
 *   1. Full line-by-line trace of surface_lock_options' real body
 *      (Sources/IOATIR500Surface_LockOptions.cpp, the existing correct
 *      committed transcription - cross-checked against an independent
 *      from-scratch re-decompile this pass, which caught 2 bugs in the
 *      re-decompile and confirmed the committed version is right).
 *   2. Real, byte-dumped confirmation (this pass, via the newly-found
 *      real static method table @ 0x48d60) of every one of Surface's 19
 *      selector->function mappings, including selector 0 itself
 *      (surface_read_lock_options @ 0x16500, real table entry
 *      c0=2/c1=1/c2=0xffffffff - read as scalarInputCount=1 with a
 *      struct-output shape, matching the IOAccelSurfaceData output
 *      parameter).
 *   3. A read-only-ish live check (probe_readonly_checklock.c,
 *      already run without incident) confirming surface_query_lock -
 *      itself CONFIRMED to consult the SAME internal readiness bits
 *      surface_lock_options checks early on - reports this surface as
 *      lockable after set_id_mode(0, 0x4), NOT in the kind of
 *      uninitialized-pointer state that caused the #43 incident.
 *
 * lockOptions=0 is chosen deliberately as the simplest real path traced:
 * with lockType=1 (read) and lockOptions masking to 0, and this
 * surface's own real state (freshly id-assigned, no GL/2D/DVD context
 * ever linked), the real control flow reaches the "granted-pending, no
 * allocation" tail (this project's own LAB_00015e70-equivalent) without
 * calling alloc_surfaces_retry/prepare_vram/any GART-mapping code at
 * all - the least amount of real driver machinery this family can
 * exercise while still returning a real, meaningful result.
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
    if (kr != TEST_kIOReturnSuccess) { printf("open failed 0x%x\n", (unsigned int)kr); fflush(stdout); return 1; }

    printf("set_id_mode(0, 0x4): "); fflush(stdout);
    kern_return_t r1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 0, 0x4);
    printf("0x%08x (%s)\n", (unsigned int)r1, ioreturn_name(r1)); fflush(stdout);
    if (r1 != TEST_kIOReturnSuccess) {
        printf("precondition failed, stopping.\n"); fflush(stdout);
        IOServiceClose(connect); IOObjectRelease(service);
        return 1;
    }

    printf("surface_read_lock_options(lockOptions=0): "); fflush(stdout);
    unsigned char data[0x44];
    memset(data, 0xAA, sizeof(data));
    IOByteCount structSize = sizeof(data);
    UInt32 lockOptions = 0;
    kern_return_t r2 = IOConnectMethodScalarIStructureO(connect, 0, 1, &structSize, lockOptions, data);
    printf("0x%08x (%s) structSize=%u\n", (unsigned int)r2, ioreturn_name(r2), (unsigned int)structSize); fflush(stdout);
    if (r2 == TEST_kIOReturnSuccess) {
        UInt32 *d = (UInt32 *)data;
        printf("    data[0..4]={0x%x,0x%x,0x%x,0x%x,0x%x}\n", d[0], d[1], d[2], d[3], d[4]); fflush(stdout);
    }

    printf("surface_read_unlock_options: "); fflush(stdout);
    kern_return_t r3 = IOConnectMethodScalarIScalarO(connect, 1, 0, 0);
    printf("0x%08x (%s)\n", (unsigned int)r3, ioreturn_name(r3)); fflush(stdout);

    IOServiceClose(connect);
    IOObjectRelease(service);
    printf("done, clean exit.\n"); fflush(stdout);
    return 0;
}
