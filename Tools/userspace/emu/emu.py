#!/usr/bin/env python3
"""differential emulation of stock vs rebuilt GLDriver functions: same fake context, hooked dispatch table, compare every call's args + stack words"""
import sys, struct, random, re, bisect
sys.path.insert(0, '/tmp/upkgs')
from unicorn import *
from unicorn.ppc_const import *

def load(path):
    d = open(path, 'rb').read()
    if d[:4] == bytes.fromhex('cafebabe'):
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            ct, cs, o, sz, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if ct == 18: d = d[o:o+sz]; break
    magic, ct, cs, ft, ncmds, socm, flags = struct.unpack('>7I', d[:28])
    p = 28; segs = []; stubs = []; zero = []; symtab = None; indirect = None; ptrsecs = []
    for i in range(ncmds):
        cmd, size = struct.unpack('>2I', d[p:p+8])
        if cmd == 1:
            name = d[p+8:p+24].rstrip(b'\0').decode(); vm, vs, fo, fs, mp, ip, ns, fl = struct.unpack('>8I', d[p+24:p+56])
            q = p + 56
            for j in range(ns):
                sn = d[q:q+16].rstrip(b'\0').decode(); a, s, o, al, ro, nr, f = struct.unpack('>7I', d[q+32:q+60])
                if 'stub' in sn: stubs.append((a, a + s))
                if (f & 0xff) in (1, 0xc, 0x12): zero.append((a, s))
                if (f & 0xff) in (6, 7): ptrsecs.append((a, s, struct.unpack('>I', d[q+60:q+64])[0]))
                q += 68
            if name != '__LINKEDIT': segs.append((name, vm, vs, d[fo:fo+fs]))
        elif cmd == 2: symtab = struct.unpack('>4I', d[p+8:p+24])
        elif cmd == 11: indirect = struct.unpack('>2I', d[p+56:p+64])
        p += size
    fill = []
    if symtab and indirect:
        symoff, nsyms, stroff, strsize = symtab; ioff, ni = indirect
        for a, sz, r1 in ptrsecs:
            for k in range(sz // 4):
                idx = struct.unpack('>I', d[ioff + 4 * (r1 + k):ioff + 4 * (r1 + k) + 4])[0]
                if idx >= 0x40000000 or idx >= nsyms: continue
                nt, ns_, ndesc, nval = struct.unpack('>BBHI', d[symoff + 12 * idx + 4:symoff + 12 * idx + 12])
                if (nt & 0x0e) == 0x0e and nval: fill.append((a + 4 * k, nval))
    return segs, stubs, zero, fill

class Image:
    def __init__(self, path, nm_syms):
        self.segs, self.stubs, self.zero, self.fill = load(path)
        self.syms = nm_syms

STACK = 0x7f000000; STACK_SIZE = 0x100000
CTXA = 0x20000000; CTX_SIZE = 0x4000
AA = 0x28000000; A_SIZE = 0x4000
HEAP = 0x30000000; HEAP_SIZE = 0x100000
HOOK = 0x40000000
STOP = 0x50000000
SLOTS = [0x12e4, 0x12e8, 0x12ec, 0x12f0, 0x12f4, 0x12f8, 0x12fc, 0x1300, 0x1304, 0x1308, 0x130c, 0x1310, 0x1314, 0x1318, 0x131c, 0x1320, 0x1324, 0x1328, 0x132c]

class Runner:
    def __init__(self, img):
        self.img = img
        uc = Uc(UC_ARCH_PPC, UC_MODE_PPC32 | UC_MODE_BIG_ENDIAN); self.uc = uc
        for name, vm, vs, data in img.segs:
            uc.mem_map(vm, (vs + 0xfff) & ~0xfff)
            uc.mem_write(vm, data)
        for za, zs in img.zero: uc.mem_write(za, bytes(zs))
        for fa, fv in img.fill: uc.mem_write(fa, struct.pack('>I', fv))
        self.snap = [(vm, uc.mem_read(vm, len(data))) for name, vm, vs, data in img.segs if name == '__DATA']
        self.snap = [(vm, bytes(b)) for vm, b in self.snap]
        for base, size in ((STACK, STACK_SIZE), (CTXA, CTX_SIZE), (AA, A_SIZE), (HEAP, HEAP_SIZE), (HOOK, 0x1000), (STOP, 0x1000)):
            uc.mem_map(base, size)
        self.log = []; self.n = 0
        uc.hook_add(UC_HOOK_CODE, self.code_hook)
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self.unmapped)
        self.stubranges = img.stubs

    def unmapped(self, uc, access, addr, size, value, ud):
        base = addr & ~0xfff
        try: uc.mem_map(base, 0x1000)
        except Exception: return False
        self.autopages.append(base)
        return True

    def word(self, a): return struct.unpack('>I', bytes(self.uc.mem_read(a, 4)))[0]

    def code_hook(self, uc, addr, size, ud):
        self.n += 1
        if self.n > self.limit: self.status = 'TIMEOUT'; uc.emu_stop(); return
        if addr == STOP: self.status = 'RET'; uc.emu_stop(); return
        if HOOK <= addr < HOOK + 0x1000:
            slot = SLOTS[(addr - HOOK) // 16]
            r = [uc.reg_read(UC_PPC_REG_0 + i) for i in range(3, 11)]
            sp = uc.reg_read(UC_PPC_REG_1)
            st = [self.word(sp + 0x38 + 4*i) for i in range(8)]
            self.log.append((slot, r, st, self.snapshotptrs(r + st), uc.reg_read(UC_PPC_REG_LR)))
            uc.reg_write(UC_PPC_REG_3, 0)
            uc.reg_write(UC_PPC_REG_PC, uc.reg_read(UC_PPC_REG_LR)); return
        if addr < 0x1000 or any(lo <= addr < hi for lo, hi in self.stubranges):
            # dyld stub / null extern: return 0
            uc.reg_write(UC_PPC_REG_3, 0)
            uc.reg_write(UC_PPC_REG_PC, uc.reg_read(UC_PPC_REG_LR)); return

    def snapshotptrs(self, ws):
        out = []
        for w in ws:
            if STACK <= w < STACK + STACK_SIZE - 64:
                out.append(tuple(self.word(w + 4*i) for i in range(8)))
            else: out.append(None)
        return out

    def reset(self, ctxbytes, heapbytes, abytes):
        uc = self.uc
        for vm, b in self.snap: uc.mem_write(vm, b)
        uc.mem_write(CTXA, ctxbytes); uc.mem_write(HEAP, heapbytes); uc.mem_write(AA, abytes)
        uc.mem_write(STACK, bytes(STACK_SIZE))
        for p in getattr(self, 'autopages', []):
            try: uc.mem_unmap(p, 0x1000)
            except Exception: pass
        self.autopages = []
        # hook code area: nothing to write (hooked by address)

    def call(self, entry, args, limit=300000):
        uc = self.uc; self.log = []; self.n = 0; self.limit = limit; self.status = '?'
        for i in range(32): uc.reg_write(UC_PPC_REG_0 + i, 0)
        sp = STACK + STACK_SIZE - 0x1000
        uc.reg_write(UC_PPC_REG_1, sp)
        for i, a in enumerate(args): uc.reg_write(UC_PPC_REG_0 + 3 + i, a)
        uc.reg_write(UC_PPC_REG_LR, STOP)
        try:
            uc.emu_start(entry, STOP, count=limit + 10)
            if self.status == '?': self.status = 'RET'
        except UcError as e:
            self.status = 'ERR:%s' % e
        return self.status, uc.reg_read(UC_PPC_REG_3)

def mkmem(rng, entries):
    """entries: dict addr->value overrides; returns (ctx, heap, A) bytes"""
    def pool():
        x = rng.random()
        if x < 0.5: return HEAP + (rng.randrange(0, 0x40000) & ~0xf)
        if x < 0.68: return 0xffffffff
        if x < 0.76: return 0
        return rng.randrange(1, 10)
    def block(n):
        return b''.join(struct.pack('>I', pool()) for _ in range(n // 4))
    ctx = bytearray(block(CTX_SIZE)); heap = bytearray(block(HEAP_SIZE)); a = bytearray(block(A_SIZE))
    struct.pack_into('>I', ctx, 0x3d4, AA)
    for k in (0x3ec, 0x3f0):
        struct.pack_into('>I', ctx, k, HEAP + (rng.randrange(0, 0x40000) & ~0xf))
    for i, s in enumerate(SLOTS): struct.pack_into('>I', a, s, HOOK + 16 * i)
    for off in (4,): struct.pack_into('>I', a, off, HEAP + (rng.randrange(0, 0x40000) & ~0xf))
    return bytes(ctx), bytes(heap), bytes(a)
