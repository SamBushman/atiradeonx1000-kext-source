#!/usr/bin/env python3
"""idct_dryrun.py - issue #140 rung 0: run the STOCK kext's real machine code for ATIR500DVDContext::doIDCT (0x35540) and
ATIRadeonX1000::submit_idct_buffer_consumed (0x1eb30) in the unicorn PPC emulator against a hand-built context, accelerator, ring, MMIO window and surface,
and compare what it does with an INDEPENDENT model of the derived behaviour (Tests/idct_engine_findings.md sections 2 and 5).
Zero hardware risk: the emulator's sandboxed memory is the only thing that can be touched. Same unlinked-image / stub conventions as kemu.py (read its docstring).

Usage: idct_dryrun.py            run every scenario, print a report, exit 1 on any mismatch
What is modelled: this = DVD context (fields +0x7c +0x8c +0xf8 +0x150 +0x154 +0x164..+0x1c0), accelerator (+0x80 +0x854 +0x860 +0x8a0 +0x8a4 +0x8bc +0x91c
+0x928 +0x92c +0x930 +0x98 +0x84 and a vtable whose slot 0x54c is the waitForTimeStamp stub), a surface (+0x94 +0x9a heights, plane records at +0x558+idx*0x78 and +0x8a0),
a VendorTransferBuffer (+4 GART address nonzero so map_transfer_to_GART is not entered, +0x14 CPU address), a 0x800-dword ring and a 0x4000-byte MMIO window.
What is NOT modelled: the GART mapping call itself (map_transfer_to_GART), the cache-maintenance branch (accel+0x98 & 0x80 left clear), the hardware."""
import sys, os, struct
sys.path.insert(0, '/tmp/upkgs')
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))   # machoutil lives in Tools/userspace
from unicorn import *
from unicorn.ppc_const import *
import kemu
from kemu import Runner, STOP, STACK, STACK_SIZE, SELF, ACCEL, addr_of

VT, SURF, RING, STATUS, MMIO, TB0, TB1, PARAMS = 0x22000000, 0x25000000, 0x23000000, 0x23100000, 0x24000000, 0x26000000, 0x26100000, 0x27000000
GART0, GART1, GART_OFF, STAMP0 = 0x00100000, 0x00200000, 0x40, 5
DO_IDCT = '__ZN17ATIR500DVDContext6doIDCTEP15sATIDVDIDCTInfom'


def be(a, v, uc): uc.mem_write(a, struct.pack('>I', v & 0xffffffff))


def w16(a, v, uc): uc.mem_write(a, struct.pack('>H', v & 0xffff))


class R(Runner):
    def __init__(self):
        super().__init__()
        self.stub_calls = []          # (target, lr) of every call into the stub area (< 0x1000): externals and the vtable slot
        self.mmio_writes = []

    def _code_hook(self, uc, addr, size, ud):
        if addr < 0x1000 and addr != STOP:
            self.stub_calls.append((addr, uc.reg_read(UC_PPC_REG_LR)))
        return super()._code_hook(uc, addr, size, ud)

    def call3(self, entry, r3, r4, r5, limit=200000):
        uc = self.uc; self.n = 0; self.limit = limit; self.status = '?'; self.outside_calls = []; self.stub_calls = []
        for i in range(32):
            uc.reg_write(UC_PPC_REG_0 + i, 0)
        uc.reg_write(UC_PPC_REG_1, STACK + STACK_SIZE - 0x2000)
        uc.reg_write(UC_PPC_REG_MSR, 0x2000)
        uc.reg_write(UC_PPC_REG_3, r3); uc.reg_write(UC_PPC_REG_4, r4); uc.reg_write(UC_PPC_REG_5, r5)
        uc.reg_write(UC_PPC_REG_LR, STOP)
        try:
            uc.emu_start(entry, STOP, count=limit + 10)
            if self.status == '?': self.status = 'RET'
        except UcError as e:
            self.status = 'ERR:%s' % e
        return self.status, uc.reg_read(UC_PPC_REG_3)


def setup(r, sel, surf_h, pitch, plane_base, resid_base, resid_pitch, with_lock_ok=True):
    uc = r.uc
    for base, size in ((VT, 0x1000), (SURF, 0x2000), (RING, 0x2000), (STATUS, 0x1000), (MMIO, 0x4000), (TB0, 0x1000), (TB1, 0x1000), (PARAMS, 0x1000)):
        try: uc.mem_map(base, size)
        except Exception: pass
    for base, size in ((SELF, 0x4000), (ACCEL, 0x4000), (VT, 0x1000), (SURF, 0x2000), (RING, 0x2000), (STATUS, 0x1000), (MMIO, 0x4000), (TB0, 0x1000), (TB1, 0x1000), (PARAMS, 0x1000)):
        uc.mem_write(base, bytes(size))
    be(VT + 0x54c, 0x20, uc)                       # accelerator vtable slot 0x54c (waitForTimeStamp): stub (returns 0)
    be(ACCEL + 0x00, VT, uc)                       # *accel = vtable
    uc.mem_write(ACCEL + 0x80, b'\x01')            # accel up
    be(ACCEL + 0x854, STAMP0, uc); be(ACCEL + 0x860, MMIO, uc); be(ACCEL + 0x8a0, 0, uc); be(ACCEL + 0x8a4, GART_OFF, uc)
    be(ACCEL + 0x8bc, 1, uc); be(ACCEL + 0x91c, RING, uc); be(ACCEL + 0x928, STATUS, uc); be(ACCEL + 0x92c, 0, uc); be(ACCEL + 0x930, 0, uc)
    be(ACCEL + 0x98, 0, uc); uc.mem_write(ACCEL + 0x84, b'\x20'); be(ACCEL + 0x840, 0xdead0840, uc)
    be(SELF + 0x8c, ACCEL, uc); be(SELF + 0xf8, SURF, uc); be(SELF + 0x7c, 0x1234, uc)
    be(SELF + 0x164, 0, uc); be(SELF + 0x1a0, 0, uc)
    for tb, cpu, gart in ((SELF + 0x168, TB0, GART0), (SELF + 0x1a4, TB1, GART1)):
        be(tb + 4, gart, uc); be(tb + 0x14, cpu, uc)
    w16(SURF + 0x94, 0, uc); w16(SURF + 0x9a, surf_h, uc)
    rec0 = SURF + 0x558 + 0 * 0x78                  # dest surface index 0
    be(rec0 + 8, plane_base, uc); w16(rec0 + 0x18, pitch, uc)
    rec1 = SURF + 0x8a0
    be(rec1 + 8, resid_base, uc); w16(rec1 + 0x18, resid_pitch, uc)


def client_params(field_pic, bottom, dest_idx, stream, dwords, alt_scan, w, h):
    """what the VA driver's FUN_00005fd0 puts in the 0x38-byte block (the kext fills +0x1c..+0x30 itself)"""
    p = [0] * 14
    p[0] = field_pic; p[1] = bottom; p[2] = dest_idx; p[3] = stream; p[4] = dwords
    p[5] = 0x10080 | ((alt_scan & 3) << 3) | (0x20 if stream == 0 else 0)
    p[6] = 0x8000 if stream == 1 else 0
    hh = h if not field_pic else h >> 1
    p[9] = (hh << 16) | w
    return p


def model(p, surf_h, pitch, plane_base, resid_base, resid_pitch):
    """independent model of doIDCT + submit_idct_buffer_consumed from Tests/idct_engine_findings.md (written before running the emulator)"""
    stream = p[3]
    if stream == 0: base, pt = plane_base, pitch
    else: base, pt = resid_base, resid_pitch
    h = surf_h
    pitch_used = pt << 1 if p[0] else pt            # kext: chromaFlag/fieldPictureFlag != 0 doubles the pitch
    start = base if p[1] == 0 else base + pt
    end = (base + h * pt) if p[1] == 0 else (pt + h * pt + base)
    gart = GART0 if stream == 0 else GART1
    out = dict(p1c=pitch_used * h - 1, p20=pitch_used * (h >> 1) - 1, p28=(pitch_used & 0xffff) | (pitch_used << 16), p2c=start, p30=end)
    ring = []
    def pair(reg, val): ring.extend([0x80000000 | reg, val & 0xffffffff])
    pair(0x1fe0, start); pair(0x1fe4, end); pair(0x1fec, out['p1c']); pair(0x1ff0, out['p20']); pair(0x1f8c, p[4]); pair(0x1ffc, p[9]); pair(0x1ff8, out['p28'])
    ring.extend([(((gart + 0x20) + GART_OFF) >> 1) & 0x7ffffff0, p[5]])
    pair(0x1fa8, STAMP0); pair(0x1fac, p[6])
    for _ in range(6): pair(0x1fb4, 0)
    wptr = len(ring)
    kick = ((wptr << 24) | ((wptr & 0x700) << 8)) & 0xffffffff
    return out, ring, kick


SCEN = [
    # name, params args, surface h, pitch, plane_base, resid_base, resid_pitch
    ('stream0 frame 16x16 I-picture MB', (0, 0, 0, 0, 3, 0, 16, 16), 16, 0x40, 0x100000, 0x200000, 0x40),
    ('stream0 frame, alt-scan, 4 dwords', (0, 0, 0, 0, 4, 1, 16, 16), 16, 0x40, 0x100000, 0x200000, 0x40),
    ('stream0 bottom field of a 32-line frame', (1, 1, 0, 0, 3, 0, 16, 32), 16, 0x40, 0x100000, 0x200000, 0x40),
    ('stream0 top field', (1, 0, 0, 0, 3, 0, 16, 32), 16, 0x40, 0x100000, 0x200000, 0x40),
    ('stream1 residual frame', (0, 0, 0, 1, 7, 0, 16, 16), 16, 0x40, 0x100000, 0x200000, 0x80),
]


def run_one(name, args, surf_h, pitch, pb, rb, rp):
    r = R(); uc = r.uc
    uc.mem_map(STOP & ~0xfff, 0x1000)
    setup(r, args[3], surf_h, pitch, pb, rb, rp)
    params = client_params(*args)
    uc.mem_write(PARAMS, b''.join(struct.pack('>I', x) for x in params))
    entry = addr_of(r.m, DO_IDCT)
    status, rv = r.call3(entry, SELF, PARAMS, 0x38)
    got_p = [r.word(PARAMS + 4 * i) for i in range(14)]
    wptr = r.word(ACCEL + 0x930)
    ring = [r.word(RING + 4 * i) for i in range(wptr)]
    kick = r.word(MMIO + 0x1fa0)
    exp_out, exp_ring, exp_kick = model(params, surf_h, pitch, pb, rb, rp)
    errs = []
    if status != 'RET': errs.append('emulator status %s' % status)
    if rv != 0: errs.append('doIDCT returned 0x%08x (model: 0)' % rv)
    for k, idx in (('p1c', 7), ('p20', 8), ('p28', 10), ('p2c', 11), ('p30', 12)):
        if got_p[idx] != exp_out[k] & 0xffffffff: errs.append('params+0x%x = %08x, model %08x' % (idx * 4, got_p[idx], exp_out[k] & 0xffffffff))
    if ring != exp_ring: errs.append('ring differs: got %s | model %s' % (' '.join('%08x' % x for x in ring), ' '.join('%08x' % x for x in exp_ring)))
    if kick != exp_kick: errs.append('kick %08x, model %08x' % (kick, exp_kick))
    if r.word(ACCEL + 0x854) != STAMP0 + 1: errs.append('stamp counter %d' % r.word(ACCEL + 0x854))
    tbfield = r.word(SELF + (0x168 if args[3] == 0 else 0x1a4) + 0x10)
    if tbfield != STAMP0: errs.append('transfer buffer +0x10 = %d, expected the returned tag %d' % (tbfield, STAMP0))
    if args[3] == 0 and r.word(SELF + 0x150) != STAMP0: errs.append('this+0x150 = %d' % r.word(SELF + 0x150))
    if args[3] == 0 and r.word(SELF + 0x154) != STAMP0: errs.append('this+0x154 = %d' % r.word(SELF + 0x154))
    stubs = [hex(t) + '@' + hex(l) for t, l in r.stub_calls]
    return errs, dict(insns=r.n, stub_calls=stubs, wptr=wptr, kick=kick, ring=ring, params=got_p)


def run_badsel():
    r = R(); uc = r.uc
    uc.mem_map(STOP & ~0xfff, 0x1000)
    setup(r, 2, 16, 0x40, 0x100000, 0x200000, 0x40)
    params = [0, 0, 0, 2] + [0] * 10
    uc.mem_write(PARAMS, b''.join(struct.pack('>I', x) for x in params))
    status, rv = r.call3(addr_of(r.m, DO_IDCT), SELF, PARAMS, 0x38)
    return status, rv, r.stub_calls, r.word(ACCEL + 0x930)


def run_oversize():
    """the kext never checks dmaDwordCount against the buffer: with the cache-flush branch on, a 0x40000-dword count over a 0x1000-byte buffer is accepted and the flush loop
    walks ~1 MB past it (the emulator auto-maps those pages; on hardware they would be whatever is there)"""
    r = R(); uc = r.uc
    uc.mem_map(STOP & ~0xfff, 0x1000)
    setup(r, 0, 16, 0x40, 0x100000, 0x200000, 0x40)
    be(ACCEL + 0x98, 0x80, uc)
    big = 0x40000
    uc.mem_write(PARAMS, b''.join(struct.pack('>I', x) for x in client_params(0, 0, 0, 0, big, 0, 16, 16)))
    status, rv = r.call3(addr_of(r.m, DO_IDCT), SELF, PARAMS, 0x38, limit=2000000)
    ring = [r.word(RING + 4 * i) for i in range(r.word(ACCEL + 0x930))]
    return status, rv, ring, len(r.autopages)


def selftest():
    """negative control: a deliberately corrupted model must be reported as a mismatch (otherwise the comparison is vacuous)"""
    global model
    orig = model
    def bad(*a):
        o, ring, k = orig(*a); ring = list(ring); ring[1] ^= 0x10; return o, ring, k
    model = bad
    try: errs, _ = run_one(*SCEN[0])
    finally: model = orig
    return bool(errs)


def main():
    bad = 0
    if not selftest(): print('! selftest: corrupted model NOT detected - harness is vacuous'); sys.exit(2)
    print('selftest: corrupted model is detected')
    for sc in SCEN:
        errs, info = run_one(*sc)
        print('%-45s %s  (insns %d, stub calls %d, wptr %d, kick %08x)' % (sc[0], 'MATCH' if not errs else 'MISMATCH', info['insns'], len(info['stub_calls']), info['wptr'], info['kick']))
        for e in errs: print('    !', e)
        bad += bool(errs)
    status, rv, stubs, wptr = run_badsel()
    # a normal call makes exactly three stub calls (waitForTimeStamp, IOLockLock, IOLockUnlock); the bad selector must stop after lock with no unlock and write nothing
    print('%-45s status=%s rv=0x%08x stub calls=%d wptr=%d  (BadArgument 0xe00002c2 expected, lock leaked = one fewer stub call than a normal run)' % ('planeSelector 2 (bad)', status, rv, len(stubs), wptr))
    _, ok_info = run_one(*SCEN[0])[0:2]
    if rv != 0xe00002c2 or wptr != 0: bad += 1; print('    ! unexpected bad-selector behaviour')
    if len(stubs) != len(ok_info['stub_calls']) - 1: bad += 1; print('    ! lock-leak signature missing: %d stub calls vs %d in a normal run' % (len(stubs), len(ok_info['stub_calls'])))
    status, rv, ring, pages = run_oversize()
    print('%-45s status=%s rv=0x%x ring dmaDwordCount=%s, flush loop touched %d pages beyond the buffer (accepted = no bounds check, as in the decompile)' % ('oversize dmaDwordCount 0x40000', status, rv, hex(ring[9]) if len(ring) > 9 else '?', pages))
    if status != 'RET' or rv != 0 or ring[9] != 0x40000: bad += 1; print('    ! oversize count was not accepted as predicted')
    print('RESULT:', 'all scenarios match the model' if not bad else '%d mismatch(es)' % bad)
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
