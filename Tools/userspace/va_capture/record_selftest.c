/* record_selftest.c - proves iokit_record_va.dylib records without disturbing the call: calls the already-proven-safe Surface get_state (selector 2, 0 in / 1 out) through the MIG routine
 * the VA bundle uses, and a scalarI_structureO call (Surface surface_read_lock_options, lockOptions 3 = pending tail, then its unlock) is NOT made here; only get_state. */
#include <stdio.h>
#include <mach/mach.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/iokitmig_c.h>
int main(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("ATIRadeonX1000"));
    io_connect_t c; kern_return_t r; int out[1] = { -1 }; mach_msg_type_number_t oc = 1;
    if (!svc) { printf("no ATIRadeonX1000 service\n"); return 2; }
    r = IOServiceOpen(svc, mach_task_self(), 0 /* Surface */, &c);
    if (r) { printf("open failed 0x%x\n", r); return 3; }
    r = io_connect_method_scalarI_scalarO(c, 2, NULL, 0, out, &oc);
    printf("get_state -> 0x%x out=0x%x\n", r, out[0]);
    IOServiceClose(c);
    return r != 0;
}
