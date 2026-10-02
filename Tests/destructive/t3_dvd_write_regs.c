/* Test for #91 (DVD write_regs, sel 14: scalars offset, value), issue #87 protocol. Traced (ATIR500DVDContext_write_regs_Port.cpp): one register, the value stored byte-swapped (to little endian) at
 * MMIO base + (offset & 0x1ffc) under the accelerator lock; NotReady when the hardware is down; no surface needed. Phase A ONLY (write back the value just read): the issue's Phase B (flip bits of a
 * scratch register) is NOT run: no register in 0x0-0x1ffc has been proven side-effect-free, and the obvious candidates, SCRATCH_REG0-5 at 0x15e0-0x15f4, are the stamp registers the kext itself reads
 * (accelerator+0x86c = 0x15e0 is the retired-stamp register of checkForTimeStamp), so flipping them would corrupt every stamp wait. The inverse read, 2D read_regs (sel 16, read-only, confirmed live), assembles the little-endian register bytes into a host value, so writing back the value just read is the
 * identity. The ONLY register written is 0x00f8 CONFIG_MEMSIZE (the VRAM size, 0x10000000 on this X1900; read-only configuration register), always with its own current value, so even if the
 * register were writable the machine state cannot change; the test aborts before writing if the value read is not the 0x10000000 the baseline reports (guards against an unexpected
 * endianness/layout). Read-back after the write must equal the value. */
#include "t3common.h"
static kern_return_t rd(dtest_t *t, io_connect_t d, UInt32 off, UInt32 *val) {
    UInt32 in = off, out = 0; IOByteCount osz = sizeof out; kern_return_t r;
    dtest_about(t, "DVD read_regs(sel13, 0x%04x)", (unsigned)off);
    r = IOConnectMethodStructureIStructureO(d, 13, sizeof in, &osz, &in, &out);
    dtest_result(t, r, "read_regs 0x%04x -> 0x%08x", (unsigned)off, (unsigned)out);
    *val = out; return r;
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; UInt32 v0 = 0, v1 = 0;
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    r = rd(t, d, 0x00f8, &v0); bad += t3_expect(t, "read CONFIG_MEMSIZE", r, 0);
    if (r != 0 || v0 != 0x10000000) { dtest_note(t, "CONFIG_MEMSIZE=0x%08x is not the baseline 0x10000000: NOT writing", (unsigned)v0); IOServiceClose(d); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD write_regs(sel14, 0x00f8, 0x10000000)", IOConnectMethodScalarIScalarO(d, 14, 2, 0, 0x00f8, (int)v0)); bad += t3_expect(t, "write_regs", r, 0);
    r = rd(t, d, 0x00f8, &v1); bad += t3_expect(t, "read-back", r, 0);
    if (v1 != v0) { dtest_note(t, "read-back 0x%08x != 0x%08x", (unsigned)v1, (unsigned)v0); bad++; }
    IOServiceClose(d);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_write_regs", 0, body); }
