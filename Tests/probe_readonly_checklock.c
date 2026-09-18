/*
 * Tests/probe_readonly_checklock.c -- read-only-ish safety probe before
 * attempting surface_read_lock_options live. surface_query_lock (real
 * addr 0x151a0, selector 11) is CONFIRMED (per this project's own
 * decompile) to be "a pure availability CHECK that does not acquire
 * anything" - already extensively verified live this session without
 * incident. Calling it after establishing id=0 via set_id_mode(0, 0x4)
 * tells us whether the surface's own internal readiness state (which
 * surface_lock_options' own real body also consults via the same
 * pending-GPU-flush bits) looks lockable, WITHOUT touching any of
 * surface_lock_options' own deeper alloc/GART logic ourselves.
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

    printf("query_lock BEFORE any setup: "); fflush(stdout);
    kern_return_t r0 = IOConnectMethodScalarIScalarO(connect, 11, 0, 0);
    printf("0x%08x (%s)\n", (unsigned int)r0, ioreturn_name(r0)); fflush(stdout);

    printf("set_id_mode(0, 0x4): "); fflush(stdout);
    kern_return_t r1 = IOConnectMethodScalarIScalarO(connect, 7, 2, 0, 0, 0x4);
    printf("0x%08x (%s)\n", (unsigned int)r1, ioreturn_name(r1)); fflush(stdout);

    printf("query_lock AFTER set_id_mode: "); fflush(stdout);
    kern_return_t r2 = IOConnectMethodScalarIScalarO(connect, 11, 0, 0);
    printf("0x%08x (%s)\n", (unsigned int)r2, ioreturn_name(r2)); fflush(stdout);

    printf("get_state AFTER set_id_mode: "); fflush(stdout);
    int state = -1;
    kern_return_t r3 = IOConnectMethodScalarIScalarO(connect, 2, 0, 1, &state);
    printf("0x%08x (%s) state=0x%x\n", (unsigned int)r3, ioreturn_name(r3), state); fflush(stdout);

    IOServiceClose(connect);
    IOObjectRelease(service);
    printf("done, clean exit.\n"); fflush(stdout);
    return 0;
}
