/* rbbm_softreset_probe.c - issue #141: AMD's own documented GPU-hang recovery procedure (R5xx_Acceleration_v1.5.pdf section 10.1.9),
 * the RBBM_SOFTRESET part only (0x00f0, within the already-proven-safe write_regs mask & 0x1ffc). GA_SOFT_RESET (0x429c) and GA_IDLE
 * (0x425c) are OUTSIDE that mask and are deliberately not attempted here - reaching them would need a new raw-MMIO path, the same class
 * of access already flagged unsafe in this project (see Tests/idct_engine_findings.md section 9k). Uses the existing 2D write_regs/read_regs
 * (sel 17 / sel 16) - the same proven-safe mechanism as t3_2d_write_regs.c, just with a real (non-identity) value this time. Read-only
 * elsewhere in this project; this is the first genuine register WRITE beyond "write back what you just read".
 */
#include "../common.h"
#include <stdlib.h>

int g_testsRun = 0, g_testsUnexpected = 0, g_testsSkipped = 0, g_testsRecorded = 0;

static kern_return_t rd(io_connect_t d, UInt32 off, UInt32 *val) {
    UInt32 in = off, out = 0; IOByteCount osz = sizeof out;
    kern_return_t r = IOConnectMethodStructureIStructureO(d, 16, sizeof in, &osz, &in, &out);
    *val = out; return r;
}
static kern_return_t wr(io_connect_t d, UInt32 off, UInt32 val) {
    UInt32 pair[2] = { off, val };
    return IOConnectMethodScalarIStructureI(d, 17, 0, sizeof pair, pair);
}
int main(void) {
    io_service_t svc; io_connect_t d; kern_return_t r; UInt32 v;
    svc = find_accelerator_service(); if (svc == IO_OBJECT_NULL) { printf("no accelerator\n"); return 1; }
    if (open_user_client(svc, CLIENT_TYPE_2D, &d) != KERN_SUCCESS) { printf("cannot open 2D client\n"); return 1; }

    r = rd(d, 0x0e40, &v); printf("RBBM_STATUS before: rc=0x%x val=0x%08x\n", r, v);
    r = rd(d, 0x00f0, &v); printf("RBBM_SOFTRESET before: rc=0x%x val=0x%08x\n", r, v);

    r = wr(d, 0x00f0, 0x32005); printf("write RBBM_SOFTRESET=0x32005: rc=0x%x\n", r);
    r = rd(d, 0x00f0, &v); printf("RBBM_SOFTRESET after write: rc=0x%x val=0x%08x\n", r, v);
    r = rd(d, 0x0e40, &v); printf("RBBM_STATUS after reset-asserted: rc=0x%x val=0x%08x\n", r, v);

    r = wr(d, 0x00f0, 0); printf("write RBBM_SOFTRESET=0: rc=0x%x\n", r);
    r = rd(d, 0x00f0, &v); printf("RBBM_SOFTRESET after clear: rc=0x%x val=0x%08x\n", r, v);
    r = rd(d, 0x0e40, &v); printf("RBBM_STATUS after reset-cleared: rc=0x%x val=0x%08x\n", r, v);
    r = rd(d, 0x00f8, &v); printf("CONFIG_MEMSIZE sanity: rc=0x%x val=0x%08x\n", r, v);

    IOServiceClose(d); IOObjectRelease(svc);
    return 0;
}
