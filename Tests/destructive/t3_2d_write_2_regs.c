/* T3 test for #115 (2D write_2_regs, sel 18), issue #100 / protocol #87: the GPU register write through the 2D context. Traced (ATIR5002DContext_write_2_regs_Port.cpp, shipped 0x325d0):
 * the two register offsets are scalars (param_1, param_2); the struct = n pairs {value for register 1, value for register 2} (8 bytes each, byte count a multiple of 8), each stored byte-swapped (to little endian) at MMIO base + (offset & 0x1ffc); NotReady when the
 * hardware is down. The inverse read, 2D read_regs (sel 16, read-only, confirmed live), assembles the little-endian register bytes into a host value, so writing back the value just read is the
 * identity. The ONLY register written is 0x00f8 CONFIG_MEMSIZE (the VRAM size, 0x10000000 on this X1900; read-only configuration register), always with its own current value, so even if the
 * register were writable the machine state cannot change; the test aborts before writing if the value read is not the 0x10000000 the baseline reports (guards against an unexpected
 * endianness/layout). Read-back after the write must equal the value. */
#include "t3common.h"
static kern_return_t rd(dtest_t *t, io_connect_t d, UInt32 off, UInt32 *val) {
    UInt32 in = off, out = 0; IOByteCount osz = sizeof out; kern_return_t r;
    dtest_about(t, "2D read_regs(sel16, 0x%04x)", (unsigned)off);
    r = IOConnectMethodStructureIStructureO(d, 16, sizeof in, &osz, &in, &out);
    dtest_result(t, r, "read_regs 0x%04x -> 0x%08x", (unsigned)off, (unsigned)out);
    *val = out; return r;
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; UInt32 v0 = 0, v1 = 0, pair[2];
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    r = rd(t, d, 0x00f8, &v0); bad += t3_expect(t, "read CONFIG_MEMSIZE", r, 0);
    if (r != 0 || v0 != 0x10000000) { dtest_note(t, "CONFIG_MEMSIZE=0x%08x is not the baseline 0x10000000: NOT writing", (unsigned)v0); IOServiceClose(d); return "DIVERGENCE"; }
    pair[0] = v0; pair[1] = v0;
    T3CALL(t, r, "2D write_2_regs(sel18, 0x00f8, 0x00f8, byte count 4)", IOConnectMethodScalarIStructureI(d, 18, 2, 4, 0x00f8, 0x00f8, pair)); bad += t3_expect(t, "bad byte count", r, TEST_kIOReturnBadArgument);
    T3CALL(t, r, "2D write_2_regs(sel18, 0x00f8, 0x00f8, {0x10000000, 0x10000000})", IOConnectMethodScalarIStructureI(d, 18, 2, sizeof pair, 0x00f8, 0x00f8, pair)); bad += t3_expect(t, "write_2_regs", r, 0);
    r = rd(t, d, 0x00f8, &v1); bad += t3_expect(t, "read-back", r, 0);
    if (v1 != v0) { dtest_note(t, "read-back 0x%08x != 0x%08x", (unsigned)v1, (unsigned)v0); bad++; }
    IOServiceClose(d);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_2d_write_2_regs", 0, body); }
