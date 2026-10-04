/* guard_selftest.c - issue #140 rung 2: proves iokit_guard_va.dylib interposes and swallows, using only calls the stock kext has already answered live (baseline + T3):
 * Surface get_state (forward); DVD open, get_config (forward), a first map of type 1 (forward, proven by t3_dvd_inject), a SECOND map of type 1 (must be swallowed: same address, no kernel call),
 * dvd_enable_deint (sel 17, swallowed: an unbound-surface error if it ever reached the kernel) and check_stamps (sel 20, swallowed with synthetic out[0]=1; the kernel would answer 0). No doIDCT, no
 * command buffer. If interposition failed the extra calls would reach the kernel and return their (baseline-known, harmless) unbound-surface results, which this test detects. */
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <mach/mach.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/iokitmig_c.h>
int main(void) {
    long (*gs)(int) = (long (*)(int))dlsym(RTLD_DEFAULT, "guard_stat"); int bad = 0;
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("ATIRadeonX1000"));
    io_connect_t s, d; kern_return_t r; int out[2] = {-1, -1}, in[2] = {0, 0}; mach_msg_type_number_t oc = 1;
    vm_address_t a1 = 0, a2 = 0; vm_size_t z1 = 0, z2 = 0;
    if (!gs) { printf("guard NOT loaded\n"); return 2; }
    if (!svc) { printf("no ATIRadeonX1000 service\n"); return 2; }
    if (IOServiceOpen(svc, mach_task_self(), 0, &s)) return 3;
    r = io_connect_method_scalarI_scalarO(s, 2, NULL, 0, out, &oc); printf("surface get_state -> 0x%x out=0x%x\n", r, out[0]);
    if (IOServiceOpen(svc, mach_task_self(), 3, &d)) { printf("DVD open failed\n"); return 3; }
    oc = 2; out[0] = out[1] = -1; r = io_connect_method_scalarI_scalarO(d, 1, NULL, 0, out, &oc); printf("DVD get_config (forwarded) -> 0x%x out=%d,%d\n", r, out[0], out[1]);
    r = IOConnectMapMemory(d, 1, mach_task_self(), &a1, &z1, 1); printf("map type 1 #1 (forwarded) -> 0x%x addr=0x%lx size=0x%lx\n", r, (unsigned long)a1, (unsigned long)z1);
    a2 = 0; z2 = 0; r = IOConnectMapMemory(d, 1, mach_task_self(), &a2, &z2, 1); printf("map type 1 #2 (must be swallowed) -> 0x%x addr=0x%lx size=0x%lx\n", r, (unsigned long)a2, (unsigned long)z2);
    if (r != 0 || a2 != a1 || z2 != z1) { printf("FAIL: second map was not swallowed with the existing mapping\n"); bad++; }
    r = io_connect_method_scalarI_scalarO(d, 17, in, 1, NULL, &oc); /* dvd_enable_deint(0): oc is ignored for 0 outputs below */
    printf("sel 17 (must be swallowed) -> 0x%x\n", r); if (r != 0) { printf("FAIL: sel 17 reached the kernel (unbound-surface error)\n"); bad++; }
    oc = 1; out[0] = -1; r = io_connect_method_scalarI_scalarO(d, 20, in, 2, out, &oc); printf("sel 20 check_stamps (swallowed, synthetic done) -> 0x%x out=%d\n", r, out[0]);
    if (out[0] != 1) { printf("FAIL: sel 20 was not answered by the guard\n"); bad++; }
    printf("guard stats: fwd=%ld swallow=%ld dvd_opens=%ld sel18=%ld remaps=%ld\n", gs(0), gs(1), gs(2), gs(3), gs(4));
    if (gs(2) != 1 || gs(4) != 1 || gs(1) < 3) { printf("FAIL: unexpected guard counters\n"); bad++; }
    IOServiceClose(d); IOServiceClose(s);
    printf(bad ? "SELFTEST FAIL\n" : "SELFTEST OK\n"); return bad != 0;
}
