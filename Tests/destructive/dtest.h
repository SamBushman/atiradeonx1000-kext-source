/*
 * Tests/destructive/dtest.h - the protocol of issue #87 as a library.
 *
 * Every destructive / interruptible external-method test (issues #88-#97 and the T3 rows of #100) is ONE binary: its own main() calls
 * dtest_main() with a name and a body. dtest_main() enforces, before the body runs:
 *   - --phase <name> and --i-understand-this-may-hang-the-machine are both required;
 *   - --kext <stock|rebuilt> (default stock) is recorded in every log line and file name;
 *   - results/<method>.state must not say IN PROGRESS (an interrupted run needs --acknowledge-interrupted after the reset procedure);
 *   - no GL context and no DVD context may exist (a GL application or DVD Player is running) unless the test says it needs one;
 *   - Tests/destructive/preflight.sh has run successfully within the last 15 minutes (results/preflight.ok), and
 *     results/peer_ack was touched from a SECOND machine (peer_ack.sh) within the last 15 minutes.
 * and provides the write-ahead log: dtest_about() appends "ABOUT TO CALL ..." to results/<method>_<kext>_<UTC>.log and fsync()s BEFORE
 * the risky call (the line is also mirrored to stdout and, with --mirror HOST:PORT, to a UDP listener on another machine), so a hang or
 * panic always leaves the exact last call on disk and on the second machine. dtest_result() logs the outcome the same way.
 * dtest_finish() records one of PASS / EXPECTED-REJECT / DIVERGENCE / HANG / PANIC / CORRUPTION in the state file.
 */
#ifndef ATI_DTEST_H
#define ATI_DTEST_H

#include "../common.h"
#include <stdarg.h>

typedef struct dtest {
    const char *method;      /* e.g. "dvd_write_regs" */
    const char *phase;       /* --phase */
    const char *kext;        /* "stock" or "rebuilt" */
    int logfd;
    int mirrorfd;            /* UDP socket or -1 */
    char logpath[512];
    char statepath[512];
    char resultsdir[512];
    int calls;
} dtest_t;

/* body returns the outcome string for the state file ("PASS", "EXPECTED-REJECT", "DIVERGENCE") or NULL for PASS */
typedef const char *(*dtest_body_fn)(dtest_t *t, io_service_t service);

/* needs_gl_or_dvd_client: 0 = refuse when a GL/DVD client exists (default), 1 = the test needs one */
int dtest_main(int argc, char **argv, const char *method, int needs_gl_or_dvd_client, dtest_body_fn body);

void dtest_note(dtest_t *t, const char *fmt, ...);                     /* a free-form log line (fsync'd) */
void dtest_about(dtest_t *t, const char *fmt, ...);                    /* "ABOUT TO CALL ..." (fsync'd BEFORE the call) */
void dtest_result(dtest_t *t, kern_return_t r, const char *fmt, ...);  /* the outcome of the call that was announced */

#endif
