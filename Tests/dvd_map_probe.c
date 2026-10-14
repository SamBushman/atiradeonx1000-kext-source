/*
 * Tests/dvd_map_probe.c - IOConnectMapMemory coverage for the DVD context (type 3). Found missing 2026-10-14: the parity suite never calls IOConnectMapMemory, but a real client
 * (DVD Player on the hot-swapped rebuilt kext) opened a DVD connection, called get_config, then mapped memory and the whole G5 died (no panic text).
 *   dvd_map_probe IP PORT TYPE [TYPE...]       (build: gcc -std=gnu99 -o dvd_map_probe dvd_map_probe.c -framework IOKit -framework CoreFoundation)
 * Opens one DVD connection, get_config (sel 1), then for each TYPE: PRE line, IOConnectMapMemory(TYPE), POST line (rc, address, size), IOConnectUnmapMemory.
 * Every line goes to stdout AND as a UDP datagram to IP:PORT (Tools/udp_log_receiver.py), because a hang loses the disk log; the last PRE with no POST is the call that never returned.
 * Run STOCK (hot-swapped, same unstick state) first as the control; never run on the rebuilt kext before that.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CoreFoundation.h>

static int g_s = -1; static struct sockaddr_in g_a;
static void say(const char *fmt, ...) {
    char b[300]; va_list ap; va_start(ap, fmt); int n = vsnprintf(b, sizeof b, fmt, ap); va_end(ap);
    fputs(b, stdout); fflush(stdout);
    if (g_s >= 0) sendto(g_s, b, n, 0, (struct sockaddr *)&g_a, sizeof g_a);
    usleep(150000);   /* let the datagram leave before the next call can wedge the machine */
}
int main(int argc, char **argv) {
    if (argc < 4) { fprintf(stderr, "usage: %s IP PORT TYPE...\n", argv[0]); return 2; }
    memset(&g_a, 0, sizeof g_a); g_a.sin_family = AF_INET; g_a.sin_port = htons((unsigned short)atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &g_a.sin_addr) == 1) g_s = socket(AF_INET, SOCK_DGRAM, 0);
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("ATIRadeonX1000"));
    if (!svc) { say("no ATIRadeonX1000\n"); return 1; }
    io_connect_t c; kern_return_t r = IOServiceOpen(svc, mach_task_self(), 3, &c);
    say("open DVD ctx rc=0x%x\n", r); if (r) return 1;
    uint32_t o0 = 0, o1 = 0; uint32_t oc = 2;
    r = IOConnectMethodScalarIScalarO(c, 1, 0, 2, &o0, &o1);
    say("get_config rc=0x%x out={%u,%u}\n", r, o0, o1);
    for (int i = 3; i < argc; i++) {
        uint32_t t = (uint32_t)atoi(argv[i]); vm_address_t a = 0; vm_size_t sz = 0;
        say("PRE map type=%u\n", t);
        r = IOConnectMapMemory(c, t, mach_task_self(), &a, &sz, kIOMapAnywhere);
        say("POST map type=%u rc=0x%x addr=0x%lx size=0x%lx\n", t, r, (unsigned long)a, (unsigned long)sz);
        if (r == 0) { r = IOConnectUnmapMemory(c, t, mach_task_self(), a); say("unmap type=%u rc=0x%x\n", t, r); }
    }
    r = IOServiceClose(c); say("close rc=0x%x\nDONE\n", r);
    (void)oc; return 0;
}
