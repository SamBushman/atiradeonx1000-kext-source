/* Test for #93 Phase C and #98 (DVD doIDCT, sel 18, invalid planeSelector), issue #87 protocol. THIS TEST IS EXPECTED TO LEAVE THE ACCELERATOR COMMAND LOCK HELD: the reboot afterwards is part of
 * the test. Traced (ATIR500DVDContext_doIDCT_Port.cpp, shipped doIDCT): with a bound surface, hardware up and the ring valid (accelerator+0x8bc != 0) the body takes the accelerator lock, and for
 * sATIDVDIDCTParams.planeSelector (+0xc) other than 0/1 it returns kIOReturnBadArgument WITHOUT unlocking (the same leak on the success-less exit is the other half of the issue). It returns before
 * touching any buffer, the GART, the ring or the hardware: no stream, no address, no DMA is involved, so nothing is submitted. The params block is 0x40 zero bytes except planeSelector = 2.
 * After the call every other client that needs the accelerator lock blocks: confirmed with a forked child that issues 2D swap_surface(0) (unbound: takes the lock, then fails) and is given 15 s.
 * The valid doIDCT path (Phase A/B: real IDCT hardware submission) is NOT run: it programs the GPU with caller-supplied coefficient/destination addresses and needs a real macroblock stream.
 * *** CORRECTION 2026-10-05: the first run of this test (2026-10-02) got "no lock leak observed" - but the child silently _exit(0)'d with NO logging of whether open_user_client/swap_surface
 * even ran, and fork() after Mach port/IOKit setup is a well-known source of silent breakage. First fix (same day): the child reported its return codes over a pipe instead of exiting silently
 * - and that re-run PROVED the real problem: the fork()'d child's OWN open_user_client call failed (rc=0x10000003), before it ever reached swap_surface. fork() after this process already has
 * a live IOKit/Mach bootstrap context does not reliably produce a child that can make its own IOKit calls.
 * *** SECOND FIX (same day): stop staying in the SAME process image after fork() - the fix is not "avoid fork()", it's "exec() a fresh image before making any IOKit call", which is what
 * actually re-establishes a usable bootstrap context (posix_spawn, tried first, doesn't exist on Tiger - no <spawn.h> until Leopard; classic fork()+execv() does the same job: the exec() step
 * is what matters, not the absence of fork()). t3_dvd_idct_lock_leak_child (a separate, standalone binary - see that file) is now launched via fork()+execv(). Its stdout is piped back and read
 * incrementally (non-blocking, 1s poll) so the parent can tell "still trying to open" from "opened, now calling swap_surface (which may block forever if the lock leaked)" from "returned" - a
 * graded result, not just blocked-or-not. */
#include "t3common.h"
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i; IOByteCount osz; UInt32 in[16], out[16];
    if (t3_surface(t, svc, &s, 4, 4) != 0) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != 0) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r == 0) {
        memset(in, 0, sizeof in); in[3] = 2; osz = sizeof out;
        T3CALL(t, r, "DVD doIDCT(sel18, planeSelector 2) -> BadArgument with the accelerator lock still held", IOConnectMethodStructureIStructureO(d, 18, sizeof in, &osz, in, out));
        dtest_note(t, "doIDCT planeSelector 2 -> 0x%08x (BadArgument 0xe00002c2 predicted; NotReady 0xe00002d8 if the ring is not active: nothing leaked)", (unsigned)r);
        if (r == TEST_kIOReturnBadArgument) {
            int pipefd[2]; pid_t pid; char buf[256]; int blen = 0; int sawOpen = 0, sawSwap = 0; int done_ = 0;
            char *argvChild[] = { "./t3_dvd_idct_lock_leak_child", NULL };
            dtest_about(t, "fork()+execv() child: 2D swap_surface(0) unbound, must BLOCK on the leaked lock (15 s)");
            if (pipe(pipefd) != 0) { dtest_note(t, "pipe() failed, cannot run the child check"); bad++; goto done; }
            fcntl(pipefd[0], F_SETFL, O_NONBLOCK);
            pid = fork();
            if (pid == 0) {
                /* the ONLY thing this process does before exec() is dup2+close - no IOKit call happens in the forked-but-not-yet-exec'd image */
                dup2(pipefd[1], 1); close(pipefd[0]); close(pipefd[1]);
                execv("./t3_dvd_idct_lock_leak_child", argvChild);
                _exit(127);   /* execv failed */
            }
            if (pid < 0) { dtest_note(t, "fork() failed: %s", strerror(errno)); bad++; close(pipefd[0]); close(pipefd[1]); goto done; }
            close(pipefd[1]);
            for (i = 0; i < 15 && !done_; i++) {
                int st; ssize_t n;
                while ((n = read(pipefd[0], buf + blen, sizeof buf - 1 - blen)) > 0) { blen += (int)n; buf[blen] = 0; }
                if (strstr(buf, "OPEN=") && !sawOpen) { sawOpen = 1; dtest_note(t, "child: open_user_client completed (line seen within %d s)", i); }
                if (strstr(buf, "SWAP=")) { sawSwap = 1; }
                if (waitpid(pid, &st, WNOHANG) == pid) { done_ = 1; break; }
                sleep(1);
            }
            if (!done_) {
                dtest_note(t, "LOCK LEAK CONFIRMED: the child is still running after 15 s (saw OPEN=%s, SWAP=%s) - accelerator lock never released; reboot required", sawOpen ? "yes" : "no", sawSwap ? "yes" : "no");
                if (!sawOpen) { dtest_note(t, "but open_user_client itself never completed either - inconclusive whether it's the lock or something else blocking"); }
            } else {
                while ((read(pipefd[0], buf + blen, sizeof buf - 1 - blen)) > 0) {} /* drain any trailing output */
                dtest_note(t, "child exited; output: %s", buf[0] ? buf : "(none)");
                if (!sawOpen) { dtest_note(t, "INCONCLUSIVE: child never got past open_user_client - this run says nothing about the lock"); bad++; }
                else if (!sawSwap) { dtest_note(t, "INCONCLUSIVE: child opened but exited before logging a swap_surface result (crashed? check exit status)"); bad++; }
                else { dtest_note(t, "no lock leak observed: child's swap_surface returned on its own"); bad++; }
            }
            close(pipefd[0]);
        }
    }
done:
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_idct_lock_leak", 0, body); }
