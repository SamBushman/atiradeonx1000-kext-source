/* hwup_sampler.c - issue #43: log every window in which the stock accelerator reports "hardware not up" (accelerator+0x80 == 0), so transient NotReady results seen by the soak
 * (2026-10-02 13:00:58, 6 DVD calls returned 0xe00002d8) can be measured instead of inferred: how long each window lasts, how often it happens, and what else happened then.
 * Mechanism: the DVD guarded wrappers return NotReady (0xe00002d8) while the flag is 0 and Error (0xe00002bc) when it is 1 but no surface is bound. dvd_enable_deint (DVD sel 17, 1 scalar
 * in, none out) on a fresh, unbound DVD connection is exactly the call Tests/test_deep_t2.c already asserts returns Error on stock, so it is safe: UP = Error, DOWN = NotReady, anything else = OTHER.
 * Usage: hwup_sampler [interval_ms=50] [heartbeat_s=60]     Runs until killed. One line per state change (and one per heartbeat), timestamped, flushed:
 *   <time> STATE UP|DOWN|OTHER(0x..) after <ms> ms in the previous state
 * Build on the G5:  gcc -arch ppc -std=gnu99 -w -o hwup_sampler hwup_sampler.c -framework IOKit -framework CoreFoundation
 */
#include "common.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
int g_testsRun = 0, g_testsUnexpected = 0, g_testsSkipped = 0, g_testsRecorded = 0;
static double now_ms(void) { struct timeval tv; gettimeofday(&tv, NULL); return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0; }
static void stamp(char *b, size_t n) { struct timeval tv; struct tm t; gettimeofday(&tv, NULL); localtime_r(&tv.tv_sec, &t); snprintf(b, n, "%04d-%02d-%02dT%02d:%02d:%02d.%03d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, (int)(tv.tv_usec / 1000)); }
int main(int argc, char **argv) {
    int iv = argc > 1 ? atoi(argv[1]) : 50, hb = argc > 2 ? atoi(argv[2]) : 60; io_service_t svc; io_connect_t c; char ts[40];
    kern_return_t r; int state = -1, nchg = 0; double t_state = now_ms(), t_hb = now_ms(); long calls = 0, downs = 0;
    setvbuf(stdout, NULL, _IOLBF, 0);
    svc = find_accelerator_service();
    if (svc == IO_OBJECT_NULL || open_user_client(svc, CLIENT_TYPE_DVD, &c) != 0) { printf("cannot open the DVD context\n"); return 1; }
    for (;;) {
        int s; double t = now_ms();
        r = IOConnectMethodScalarIScalarO(c, 17, 1, 0, 0);
        calls++;
        s = (r == (kern_return_t)0xe00002bc) ? 1 : (r == (kern_return_t)0xe00002d8) ? 0 : 2;
        if (s == 0) downs++;
        if (s != state) {
            stamp(ts, sizeof ts);
            if (s == 2) printf("%s STATE OTHER(0x%08x) after %.0f ms in %s\n", ts, (unsigned)r, t - t_state, state == 1 ? "UP" : state == 0 ? "DOWN" : "start");
            else printf("%s STATE %s after %.0f ms in %s\n", ts, s ? "UP" : "DOWN", t - t_state, state == 1 ? "UP" : state == 0 ? "DOWN" : state == 2 ? "OTHER" : "start");
            state = s; t_state = t; nchg++;
        }
        if (t - t_hb >= hb * 1000.0) { stamp(ts, sizeof ts); printf("%s HEARTBEAT state=%s calls=%ld down_samples=%ld changes=%d\n", ts, state == 1 ? "UP" : state == 0 ? "DOWN" : "OTHER", calls, downs, nchg); t_hb = t; }
        usleep(iv * 1000);
    }
}
