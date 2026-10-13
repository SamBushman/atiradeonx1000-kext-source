/*
 * klog_udp_mirror.c - reusable live kernel-log capture for crash debugging on the G5.
 *
 * Why this exists: IOLog/kprintf output only reliably lands in two places - the kernel's
 * in-memory message buffer (dmesg; pure RAM, gone on reboot) and /var/log/system.log (relayed by
 * syslogd, but NOT durably on disk until syslogd's own buffered write actually reaches the
 * platter - plain fsync() is insufficient on Darwin for that guarantee, F_FULLFSYNC is needed, and
 * syslogd doesn't do that per line). A kernel panic a few instructions after a diagnostic log line
 * routinely loses that exact line before it's ever durably written anywhere on the G5's own disk.
 * This has already cost a full investigation once (see atiradeonx1000-kext-source issue #153's
 * thread: "no diagnostic IOLog line from either kext made it to system.log for any of the four"
 * panics that session) and was rediscovered a second time chasing #167 before this tool existed.
 *
 * The fix: read /dev/klog directly (the same raw stream syslogd itself consumes) and forward each
 * line over UDP to a receiver on a DIFFERENT machine, as it arrives - not written to the G5's own
 * disk at all, so the G5's own fsync/journal/disk-at-panic-time reliability is irrelevant. UDP has
 * no retry/ack handshake to block on, so a send either lands before the panic or doesn't; either
 * way it never holds up the kernel. Pair with Tools/udp_log_receiver.py running on another machine
 * BEFORE starting any crash-prone test.
 *
 * Usage (on the G5, background it before a risky test): build/stage under ~/rung3, NOT /tmp - /tmp
 * is wiped on every reboot, same rule as every other G5 artifact (see
 * feedback_g5_crash_evidence_capture memory - this bit a kext build staged in /tmp once already).
 *   mkdir -p ~/rung3 && cc -o ~/rung3/klog_udp_mirror Tools/klog_udp_mirror.c
 *   nohup ~/rung3/klog_udp_mirror <receiver_ip> <receiver_port> > ~/rung3/klog_mirror.log 2>&1 < /dev/null &
 *   disown -a
 * Stop it with: pkill klog_udp_mirror   (harmless to leave running across reboots/crashes - it's
 * read-only on /dev/klog and reconnecting after a reboot just means restarting it).
 *
 * This is the general-purpose counterpart to the GUARD_MIRROR funopen hook in
 * Tools/userspace/va_capture/comp_run.sh: GUARD_MIRROR mirrors a specific userspace test
 * harness's own stdout; this tool mirrors the kernel's /dev/klog stream directly, so it catches
 * IOLog/kprintf from ANY kext (including diagnostics added straight to the driver under test, as
 * in issue #167) with no per-harness instrumentation needed. Reach for this one first for kext-
 * side diagnostics; use GUARD_MIRROR when the thing you need visibility into is a userspace test
 * program's own output instead.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <receiver_ip> <receiver_port>\n", argv[0]);
        return 2;
    }
    const char *host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { perror("socket"); return 1; }
    struct sockaddr_in dst;
    memset(&dst, 0, sizeof(dst));
    dst.sin_family = AF_INET;
    dst.sin_port = htons(port);
    if (inet_aton(host, &dst.sin_addr) == 0) {
        fprintf(stderr, "bad address: %s\n", host);
        return 2;
    }

    int klog = open("/dev/klog", O_RDONLY);
    if (klog < 0) { perror("open /dev/klog"); return 1; }

    fprintf(stderr, "klog_udp_mirror: forwarding /dev/klog to %s:%d\n", host, port);

    char buf[2048];
    size_t buflen = 0;
    char readbuf[1024];
    char hostname[64];
    gethostname(hostname, sizeof(hostname));

    for (;;) {
        ssize_t n = read(klog, readbuf, sizeof(readbuf));
        if (n < 0) { perror("read /dev/klog"); break; }
        if (n == 0) { usleep(50000); continue; }
        for (ssize_t i = 0; i < n; i++) {
            char c = readbuf[i];
            if (c == '\n' || buflen >= sizeof(buf) - 1) {
                buf[buflen] = '\0';
                if (buflen > 0) {
                    char packet[2200];
                    int plen = snprintf(packet, sizeof(packet), "[%s] %s", hostname, buf);
                    sendto(sock, packet, plen, 0, (struct sockaddr *)&dst, sizeof(dst));
                }
                buflen = 0;
            } else {
                buf[buflen++] = c;
            }
        }
    }
    close(klog);
    return 1;
}
