/* accel_idle_sample.c - sample the accelerator's idle state (Surface user client selector 2 = get_state: 1 = accelerator idle, 0 = busy) N times, INTERVAL_MS apart,
 * and print the histogram plus the transitions. Read-only (the same call the parity harness makes, proven safe).
 * usage: ./accel_idle_sample [N=400] [INTERVAL_MS=50]      build on the Tiger machine:  gcc -arch ppc -o accel_idle_sample accel_idle_sample.c -framework IOKit -framework CoreFoundation
 * Why: the display-sleep harness showed get_state 0 (busy) before the sleep on the rebuilt-userspace (KU) side and 1 (idle) on the stock sides (Phase 4, Nov 7); this tells whether the GPU is genuinely busy at an idle desktop. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CoreFoundation.h>
int main(int argc, char **argv) {
    int n = argc > 1 ? atoi(argv[1]) : 400, ms = argc > 2 ? atoi(argv[2]) : 50, i, idle = 0, busy = 0, trans = 0, prev = -1;
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("ATIRadeonX1000"));
    io_connect_t c = 0;
    if (!svc || IOServiceOpen(svc, mach_task_self(), 0, &c) != KERN_SUCCESS) { printf("cannot open the Surface user client\n"); return 1; }
    for (i = 0; i < n; i++) {
        int st = -1;
        kern_return_t r = IOConnectMethodScalarIScalarO(c, 2, 0, 1, &st);
        if (r != KERN_SUCCESS) { printf("get_state failed 0x%x\n", r); return 1; }
        if (st) idle++; else busy++;
        if (prev != -1 && prev != st) trans++;
        prev = st; usleep(ms * 1000);
    }
    printf("samples=%d interval=%dms idle=%d busy=%d (busy %.1f%%) transitions=%d\n", n, ms, idle, busy, 100.0 * busy / n, trans);
    IOServiceClose(c);
    return 0;
}
