/*
 * Tests/destructive/regsnap.c - register snapshot for preflight.sh / postflight.sh (issue #87, criterion 3).
 * Reads the registers listed one per line (hex or decimal, '#' comments) in regs.list - default 0x00f8 (CONFIG_MEMSIZE) and 0x0e40 (RBBM_STATUS) -
 * through the 2D context's read_regs (sel 16): a READ-ONLY path (offset & 0x1ffc into the MMIO window, nothing written; Tests/deep_paths.md). A per-test
 * issue names the ranges it cares about by putting them in its own results/<method>/regs.list (copy it next to the binary before running preflight).
 * Prints "0xOFFSET 0xVALUE" per line; exit status 1 on any failure.
 */
#include "../common.h"
#include <stdlib.h>

int g_testsRun = 0, g_testsUnexpected = 0, g_testsSkipped = 0, g_testsRecorded = 0;

int main(void) {
    UInt32 offs[256], vals[256]; int n = 0, i; char line[200]; FILE *f = fopen("regs.list", "r");
    io_service_t svc; io_connect_t c; IOByteCount outSize; kern_return_t r;
    if (f) { while (n < 256 && fgets(line, sizeof line, f)) { char *p = line; while (*p == ' ' || *p == '\t') p++; if (*p == '#' || *p == '\n' || !*p) continue; offs[n++] = (UInt32)strtoul(p, NULL, 0); } fclose(f); }
    if (n == 0) { offs[0] = 0x00f8; offs[1] = 0x0e40; n = 2; }
    svc = find_accelerator_service(); if (svc == IO_OBJECT_NULL) { printf("no accelerator\n"); return 1; }
    if (open_user_client(svc, CLIENT_TYPE_2D, &c) != KERN_SUCCESS) { printf("cannot open 2D client\n"); return 1; }
    outSize = n * 4;
    r = IOConnectMethodStructureIStructureO(c, 16, n * 4, &outSize, offs, vals);
    if (r != TEST_kIOReturnSuccess) { printf("read_regs failed: 0x%08x\n", (unsigned int)r); IOServiceClose(c); return 1; }
    for (i = 0; i < n; i++) printf("0x%04x 0x%08x\n", (unsigned int)offs[i], (unsigned int)vals[i]);
    IOServiceClose(c); IOObjectRelease(svc);
    return 0;
}
