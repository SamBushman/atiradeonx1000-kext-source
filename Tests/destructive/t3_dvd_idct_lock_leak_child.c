/* Standalone helper for #98's lock-leak check (t3_dvd_idct_lock_leak.c): a genuinely exec()'d process, NOT fork()'d, so it gets a clean IOKit/Mach
 * bootstrap context of its own. The first live attempt (fork(), no logging) was ambiguous; the second (fork() + a pipe back to the parent) proved the
 * real problem - the forked child's own open_user_client call fails, because a fork()'d child inherits a broken/stale bootstrap port reference, not
 * a usable one. This binary is launched via posix_spawn from the parent test, with its stdout piped back; each line is flushed immediately so the
 * parent can tell "still trying to open" from "opened, now calling swap_surface (which may block forever if the accelerator lock leaked)" even if
 * this process itself never returns. */
#include "../common.h"
#include <stdio.h>
int g_testsRun = 0, g_testsUnexpected = 0, g_testsSkipped = 0, g_testsRecorded = 0;   /* common.h declares these extern; this standalone binary doesn't link dtest.c */
int main(void) {
    io_connect_t c = IO_OBJECT_NULL; kern_return_t r; int tag = -1;
    io_service_t svc = find_accelerator_service();
    if (!svc) { printf("NOSVC\n"); fflush(stdout); return 1; }
    r = open_user_client(svc, CLIENT_TYPE_2D, &c);
    printf("OPEN=0x%08x\n", (unsigned)r); fflush(stdout);
    if (r != 0) return 1;
    r = IOConnectMethodScalarIScalarO(c, 3, 1, 1, 0, &tag);
    printf("SWAP=0x%08x\n", (unsigned)r); fflush(stdout);
    return 0;
}
