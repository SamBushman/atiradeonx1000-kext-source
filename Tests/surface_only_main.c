/* surface_only_main.c - #153 isolation test: open the Surface user client WITHOUT first
 * running the full GL/2D/DVD test suites, to check whether the Surface-path crash in
 * newUserClient depends on accumulated state from earlier context tests, or happens standalone. */
#include "common.h"

int g_testsRun = 0;
int g_testsUnexpected = 0;
int g_testsSkipped = 0;
int g_testsRecorded = 0;

int main(int argc, char **argv) {
    io_service_t service = find_accelerator_service();
    if (service == IO_OBJECT_NULL) {
        printf("[FAIL] ATIRadeonX1000 service not found in the IORegistry\n");
        return 1;
    }
    printf("ISOLATION: running Surface context tests ALONE (no GL/2D/DVD first)\n");
    run_surface_context_tests(service);
    IOObjectRelease(service);
    printf("\n%d calls made, %d unexpected\n", g_testsRun, g_testsUnexpected);
    return 0;
}
