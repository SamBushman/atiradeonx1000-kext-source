/* Test for #91 Phases B+C (DVD write_regs, sel 14), issue #87 protocol: flip the bits of ONE scratch register and restore it. Register choice with evidence: SCRATCH_REG5 = 0x15f4 (R5xx CP scratch
 * register, R/W 32-bit storage; AMD R5xx_Acceleration v1.5 sec. 5.9). Read live on stock: SCRATCH_UMSK (0x0770) = 0xff (all eight registers enabled for CP write-back), SCRATCH_ADDR (0x0774) =
 * 0x10005000, SCRATCH_REG0 = 0xc471 (the kext's retired-stamp register, in continuous use), SCRATCH_REG1 = 1 (the GL driver's), REG2-5 = 0. Evidence that nothing uses REG5: the kext writes
 * 0x15e0..0x15f4 only in hardware init (zeroing) and reads 0x15e0/0x15e4 for stamps; a scan of the immediates in ATIRadeonX1000GLDriver.bundle / VADriver.bundle finds only 0x15e4. A host write to the register
 * makes the CP mirror its value to the write-back slot SCRATCH_ADDR + 5*4 - the same page the CP already writes for REG0 with every stamp (so it is mapped), a slot nobody reads. Sequence: read REG5
 * (expect 0), write 0 (identity), write 0x5a5a5a5a, read back (expect exactly that), write 0, read back (expect 0); abort at the first mismatch, restoring 0 first. Also re-reads REG0 to show it kept counting.
 * Phase C (added 2026-10-05): offset masking per the body's own `offset & 0x1ffc` - write_regs(0x15f4 | 0x10000, pattern) and write_regs(0x15f4 | 3, pattern) must both land on the SAME register
 * (verified via a plain read_regs(0x15f4) after each), confirming the high bits above 0x1ffc and the low 2 bits are both dropped as documented, not validated/rejected. */
#include "t3common.h"
static kern_return_t rd(dtest_t *t, io_connect_t d, UInt32 off, UInt32 *val) {
    UInt32 in = off, out = 0; IOByteCount osz = sizeof out; kern_return_t r;
    dtest_about(t, "DVD read_regs(sel13, 0x%04x)", (unsigned)off);
    r = IOConnectMethodStructureIStructureO(d, 13, sizeof in, &osz, &in, &out);
    dtest_result(t, r, "read_regs 0x%04x -> 0x%08x", (unsigned)off, (unsigned)out);
    *val = out; return r;
}
static kern_return_t wr(dtest_t *t, io_connect_t d, UInt32 off, UInt32 v) {
    kern_return_t r; char m[96]; snprintf(m, sizeof m, "DVD write_regs(sel14, 0x%04x, 0x%08x)", (unsigned)off, (unsigned)v);
    T3CALL(t, r, m, IOConnectMethodScalarIScalarO(d, 14, 2, 0, (int)off, (int)v)); return r;
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t d = IO_OBJECT_NULL; kern_return_t r; int bad = 0; UInt32 v = 1, umsk = 0, s0a = 0, s0b = 0;
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) return "DIVERGENCE";
    r = rd(t, d, 0x0770, &umsk); if (r || umsk != 0xff) { dtest_note(t, "SCRATCH_UMSK 0x%08x is not the evidence value 0xff: NOT writing", (unsigned)umsk); IOServiceClose(d); return "DIVERGENCE"; }
    r = rd(t, d, 0x15f4, &v); if (r || v != 0) { dtest_note(t, "SCRATCH_REG5 0x%08x is not 0: NOT writing", (unsigned)v); IOServiceClose(d); return "DIVERGENCE"; }
    rd(t, d, 0x15e0, &s0a);
    bad += t3_expect(t, "write identity", wr(t, d, 0x15f4, 0), 0);
    bad += t3_expect(t, "write pattern", wr(t, d, 0x15f4, 0x5a5a5a5a), 0);
    r = rd(t, d, 0x15f4, &v); bad += t3_expect(t, "read-back pattern code", r, 0);
    if (v != 0x5a5a5a5a) { dtest_note(t, "read-back 0x%08x != 0x5a5a5a5a", (unsigned)v); bad++; }
    bad += t3_expect(t, "restore 0", wr(t, d, 0x15f4, 0), 0);
    r = rd(t, d, 0x15f4, &v); bad += t3_expect(t, "read-back restored code", r, 0);
    if (v != 0) { dtest_note(t, "restored read-back 0x%08x != 0", (unsigned)v); bad++; }

    /* Phase C: offset masking (0x1ffc) - both aliases must hit the real register 0x15f4 */
    bad += t3_expect(t, "Phase C write via high-bit alias (0x115f4)", wr(t, d, 0x15f4 | 0x10000, 0x5a5a5a5a), 0);
    r = rd(t, d, 0x15f4, &v); bad += t3_expect(t, "Phase C read-back via real offset after high-bit alias", r, 0);
    if (v != 0x5a5a5a5a) { dtest_note(t, "Phase C high-bit alias: read-back 0x%08x != 0x5a5a5a5a (alias did NOT hit the same register)", (unsigned)v); bad++; }
    bad += t3_expect(t, "Phase C restore 0", wr(t, d, 0x15f4, 0), 0);
    bad += t3_expect(t, "Phase C write via low-bit alias (0x15f7)", wr(t, d, 0x15f4 | 3, 0x5a5a5a5a), 0);
    r = rd(t, d, 0x15f4, &v); bad += t3_expect(t, "Phase C read-back via real offset after low-bit alias", r, 0);
    if (v != 0x5a5a5a5a) { dtest_note(t, "Phase C low-bit alias: read-back 0x%08x != 0x5a5a5a5a (alias did NOT hit the same register)", (unsigned)v); bad++; }
    bad += t3_expect(t, "Phase C final restore 0", wr(t, d, 0x15f4, 0), 0);
    r = rd(t, d, 0x15f4, &v); bad += t3_expect(t, "Phase C final read-back", r, 0);
    if (v != 0) { dtest_note(t, "Phase C final read-back 0x%08x != 0", (unsigned)v); bad++; }

    rd(t, d, 0x15e0, &s0b);
    dtest_note(t, "SCRATCH_REG0 before 0x%08x after 0x%08x (stamp register, must not go backwards)", (unsigned)s0a, (unsigned)s0b);
    if ((SInt32)(s0b - s0a) < 0) bad++;
    IOServiceClose(d);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_write_regs_scratch", 0, body); }
