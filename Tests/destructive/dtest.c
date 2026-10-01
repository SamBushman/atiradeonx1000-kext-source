/* Tests/destructive/dtest.c - see dtest.h (issue #87). Plain userspace Tiger C, built with the stock gcc 4.0.1. */
#include "dtest.h"
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>

/* the counters common.h declares extern (the parity harness defines them in main.c, which is not linked here) */
int g_testsRun = 0, g_testsUnexpected = 0, g_testsSkipped = 0, g_testsRecorded = 0;

static void utc(char *buf, size_t n, int compact) {
    time_t now = time(NULL); struct tm *g = gmtime(&now);
    strftime(buf, n, compact ? "%Y%m%dT%H%M%SZ" : "%Y-%m-%dT%H:%M:%SZ", g);
}

static void emit(dtest_t *t, const char *tag, const char *msg) {
    char ts[32], line[1400]; int n;
    utc(ts, sizeof ts, 0);
    n = snprintf(line, sizeof line, "%s [%s/%s/%s] %s %s\n", ts, t->method, t->kext, t->phase, tag, msg);
    if (n < 0) return;
    if (n >= (int)sizeof line) n = sizeof line - 1;
    if (t->logfd >= 0) { write(t->logfd, line, n); fsync(t->logfd); }       /* write-ahead: on disk before the caller proceeds */
    fputs(line, stdout); fflush(stdout);                                    /* second terminal: ssh G5 ... | tee */
    if (t->mirrorfd >= 0) send(t->mirrorfd, line, n, 0);                   /* second machine: fire-and-forget UDP, never blocks */
}

void dtest_note(dtest_t *t, const char *fmt, ...) {
    char msg[1200]; va_list ap; va_start(ap, fmt); vsnprintf(msg, sizeof msg, fmt, ap); va_end(ap); emit(t, "NOTE", msg);
}
void dtest_about(dtest_t *t, const char *fmt, ...) {
    char msg[1200]; va_list ap; va_start(ap, fmt); vsnprintf(msg, sizeof msg, fmt, ap); va_end(ap);
    t->calls++; emit(t, "ABOUT TO CALL", msg);
}
void dtest_result(dtest_t *t, kern_return_t r, const char *fmt, ...) {
    char msg[1200], full[1300]; va_list ap; va_start(ap, fmt); vsnprintf(msg, sizeof msg, fmt, ap); va_end(ap);
    snprintf(full, sizeof full, "-> 0x%08x (%s) %s", (unsigned int)r, ioreturn_name(r), msg); emit(t, "RESULT", full);
}

static void write_state(dtest_t *t, const char *what, const char *extra) {
    char ts[32]; FILE *f = fopen(t->statepath, "w");
    utc(ts, sizeof ts, 0);
    if (!f) { fprintf(stderr, "cannot write %s: %s\n", t->statepath, strerror(errno)); return; }
    fprintf(f, "%s %s phase=%s kext=%s log=%s %s\n", what, ts, t->phase, t->kext, t->logpath, extra ? extra : "");
    fflush(f); fsync(fileno(f)); fclose(f);
}

static int file_age_ok(const char *path, int max_seconds) {
    struct stat st; if (stat(path, &st) != 0) return 0;
    return (time(NULL) - st.st_mtime) <= max_seconds;
}

/* number of live instances of an IOKit class: `ioreg -c CLASS` prints one block per instance; counted by the registry-entry lines */
static int count_instances(const char *cls) {
    char cmd[200], line[512]; int n = 0; FILE *p;
    snprintf(cmd, sizeof cmd, "/usr/sbin/ioreg -w0 -c %s 2>/dev/null", cls);
    p = popen(cmd, "r"); if (!p) return -1;
    while (fgets(line, sizeof line, p)) if (strstr(line, "<class ") && strstr(line, cls)) n++;
    pclose(p); return n;
}

static int mirror_connect(const char *spec) {
    char host[200], *colon; struct hostent *h; struct sockaddr_in sa; int fd;
    strncpy(host, spec, sizeof host - 1); host[sizeof host - 1] = 0;
    colon = strrchr(host, ':'); if (!colon) return -1; *colon++ = 0;
    h = gethostbyname(host); if (!h) return -1;
    fd = socket(AF_INET, SOCK_DGRAM, 0); if (fd < 0) return -1;
    memset(&sa, 0, sizeof sa); sa.sin_family = AF_INET; sa.sin_port = htons(atoi(colon)); memcpy(&sa.sin_addr, h->h_addr_list[0], h->h_length);
    if (connect(fd, (struct sockaddr *)&sa, sizeof sa) != 0) { close(fd); return -1; }
    return fd;
}

int dtest_main(int argc, char **argv, const char *method, int needs_gl_or_dvd_client, dtest_body_fn body) {
    dtest_t t; int i, understand = 0, ack = 0; const char *mirror = NULL; char ts[32], path[600];
    const char *outcome; io_service_t service;
    memset(&t, 0, sizeof t); t.method = method; t.kext = "stock"; t.phase = NULL; t.logfd = -1; t.mirrorfd = -1;
    strcpy(t.resultsdir, "results");
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--phase") && i + 1 < argc) t.phase = argv[++i];
        else if (!strcmp(argv[i], "--kext") && i + 1 < argc) t.kext = argv[++i];
        else if (!strcmp(argv[i], "--results") && i + 1 < argc) { strncpy(t.resultsdir, argv[++i], sizeof t.resultsdir - 1); }
        else if (!strcmp(argv[i], "--mirror") && i + 1 < argc) mirror = argv[++i];
        else if (!strcmp(argv[i], "--i-understand-this-may-hang-the-machine")) understand = 1;
        else if (!strcmp(argv[i], "--acknowledge-interrupted")) ack = 1;
        else { fprintf(stderr, "unknown argument %s\n", argv[i]); return 2; }
    }
    if (!t.phase || !understand) {
        fprintf(stderr, "%s: refusing to run. A destructive test needs --phase <name> --i-understand-this-may-hang-the-machine [--kext stock|rebuilt] [--mirror HOST:PORT] [--acknowledge-interrupted] (protocol: Tests/destructive/README.md, issue #87)\n", method);
        return 2;
    }
    if (strcmp(t.kext, "stock") && strcmp(t.kext, "rebuilt")) { fprintf(stderr, "--kext must be stock or rebuilt\n"); return 2; }
    mkdir(t.resultsdir, 0755);
    snprintf(t.statepath, sizeof t.statepath, "%s/%s.state", t.resultsdir, method);
    { /* an interrupted previous run must be acknowledged after the reset procedure */
        FILE *f = fopen(t.statepath, "r");
        if (f) {
            char first[256] = "";
            fgets(first, sizeof first, f); fclose(f);
            if (!strncmp(first, "IN PROGRESS", 11)) {
                if (!ack) { fprintf(stderr, "%s: the previous run is still marked IN PROGRESS (%s) - it was interrupted. Follow the reset procedure in Tests/destructive/README.md, then re-run with --acknowledge-interrupted.\n", method, first); return 3; }
                rename(t.statepath, (snprintf(path, sizeof path, "%s.interrupted.acknowledged", t.statepath), path));
            }
        }
    }
    snprintf(path, sizeof path, "%s/preflight.ok", t.resultsdir);
    if (!file_age_ok(path, 900)) { fprintf(stderr, "%s: no successful preflight in the last 15 minutes (run Tests/destructive/preflight.sh %s)\n", method, method); return 4; }
    snprintf(path, sizeof path, "%s/peer_ack", t.resultsdir);
    if (!file_age_ok(path, 900)) { fprintf(stderr, "%s: no peer acknowledgement in the last 15 minutes: from a SECOND machine run  sh Tests/destructive/peer_ack.sh <ssh-host>  (a hung G5 keeps the last log line on that machine)\n", method); return 4; }
    if (!needs_gl_or_dvd_client) {
        int gl = count_instances("ATIR500GLContext"), dvd = count_instances("ATIR500DVDContext");
        if (gl != 0 || dvd != 0) { fprintf(stderr, "%s: refusing: %d GL context(s) and %d DVD context(s) exist - a GL application or DVD Player is running. Quit it first.\n", method, gl, dvd); return 5; }
    }
    utc(ts, sizeof ts, 1);
    snprintf(t.logpath, sizeof t.logpath, "%s/%s_%s_%s.log", t.resultsdir, method, t.kext, ts);
    t.logfd = open(t.logpath, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (t.logfd < 0) { fprintf(stderr, "cannot open %s: %s\n", t.logpath, strerror(errno)); return 6; }
    if (mirror) { t.mirrorfd = mirror_connect(mirror); if (t.mirrorfd < 0) { fprintf(stderr, "cannot reach --mirror %s\n", mirror); return 6; } }
    write_state(&t, "IN PROGRESS", NULL);
    dtest_note(&t, "start: method=%s phase=%s kext=%s mirror=%s", method, t.phase, t.kext, mirror ? mirror : "(none)");
    service = find_accelerator_service();
    if (service == IO_OBJECT_NULL) { dtest_note(&t, "ATIRadeonX1000 service not found"); write_state(&t, "DONE", "outcome=ERROR-no-service"); return 7; }
    outcome = body(&t, service);
    IOObjectRelease(service);
    if (!outcome) outcome = "PASS";
    dtest_note(&t, "finish: outcome=%s calls=%d", outcome, t.calls);
    { char extra[200]; snprintf(extra, sizeof extra, "outcome=%s calls=%d", outcome, t.calls); write_state(&t, "DONE", extra); }
    return (!strcmp(outcome, "PASS") || !strcmp(outcome, "EXPECTED-REJECT")) ? 0 : 1;
}
