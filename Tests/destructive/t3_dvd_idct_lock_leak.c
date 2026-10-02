/* Test for #93 Phase C and #98 (DVD doIDCT, sel 18, invalid planeSelector), issue #87 protocol. THIS TEST IS EXPECTED TO LEAVE THE ACCELERATOR COMMAND LOCK HELD: the reboot afterwards is part of
 * the test. Traced (ATIR500DVDContext_doIDCT_Port.cpp, shipped doIDCT): with a bound surface, hardware up and the ring valid (accelerator+0x8bc != 0) the body takes the accelerator lock, and for
 * sATIDVDIDCTParams.planeSelector (+0xc) other than 0/1 it returns kIOReturnBadArgument WITHOUT unlocking (the same leak on the success-less exit is the other half of the issue). It returns before
 * touching any buffer, the GART, the ring or the hardware: no stream, no address, no DMA is involved, so nothing is submitted. The params block is 0x40 zero bytes except planeSelector = 2.
 * After the call every other client that needs the accelerator lock blocks: confirmed with a forked child that issues 2D swap_surface(0) (unbound: takes the lock, then fails) and is given 15 s.
 * The valid doIDCT path (Phase A/B: real IDCT hardware submission) is NOT run: it programs the GPU with caller-supplied coefficient/destination addresses and needs a real macroblock stream. */
#include "t3common.h"
#include <sys/wait.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, st = 0; IOByteCount osz; UInt32 in[16], out[16]; pid_t pid;
    if (t3_surface(t, svc, &s, 4, 4) != 0) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != 0) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r == 0) {
        memset(in, 0, sizeof in); in[3] = 2; osz = sizeof out;
        T3CALL(t, r, "DVD doIDCT(sel18, planeSelector 2) -> BadArgument with the accelerator lock still held", IOConnectMethodStructureIStructureO(d, 18, sizeof in, &osz, in, out));
        dtest_note(t, "doIDCT planeSelector 2 -> 0x%08x (BadArgument 0xe00002c2 predicted; NotReady 0xe00002d8 if the ring is not active: nothing leaked)", (unsigned)r);
        if (r == TEST_kIOReturnBadArgument) {
            dtest_about(t, "forked child: 2D swap_surface(0) unbound, must BLOCK on the leaked lock (15 s)");
            fflush(stdout);
            pid = fork();
            if (pid == 0) { io_connect_t c; if (open_user_client(svc, CLIENT_TYPE_2D, &c) == 0) { int tag; IOConnectMethodScalarIScalarO(c, 3, 1, 1, 0, &tag); } _exit(0); }
            for (i = 0; i < 15; i++) { if (waitpid(pid, &st, WNOHANG) == pid) break; sleep(1); }
            if (i == 15) dtest_note(t, "LOCK LEAK CONFIRMED: the child is still blocked after 15 s (accelerator lock never released); reboot required");
            else { dtest_note(t, "child returned: no lock leak observed"); bad++; }
        }
    }
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_idct_lock_leak", 0, body); }
