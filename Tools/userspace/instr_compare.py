#!/usr/bin/env python3
"""instr_compare.py STOCK REBUILT REBUILT.nm LEDGER NAME... - instruction-level comparison of functions of the stock and the rebuilt image (Capstone, PPC32 big endian).
Every instruction is compared by mnemonic and operands; a relative branch (b, bl, bc*) is compared by the name of its target (stock: ledger / symbol map, rebuilt: nm; an address inside a function is
function+offset), a lis/addi/ori/lwz... pair that builds an image address is reported as 'addr' when only the address differs. Output per function: IDENTICAL, EQUIVALENT (only symbolic addresses
differ), or the first differing instructions."""
import sys, struct, bisect, re
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN
def sections(d):
    magic, = struct.unpack('>I', d[:4]); assert magic == 0xfeedface
    ncmds, = struct.unpack('>I', d[16:20]); o = 28; out = []
    for _ in range(ncmds):
        cmd, sz = struct.unpack('>2I', d[o:o+8])
        if cmd == 1:
            nsect, = struct.unpack('>I', d[o+48:o+52]); q = o + 56
            for k in range(nsect):
                sn = d[q:q+16].split(b'\0')[0].decode(); addr, size, off = struct.unpack('>3I', d[q+32:q+44]); out.append((sn, addr, size, off)); q += 68
        o += sz
    return out
def word_reader(path):
    d = open(path, 'rb').read(); secs = sections(d)
    def rd(a, n):
        for sn, ad, sz, off in secs:
            if ad <= a and a + n <= ad + sz and off: return d[off + a - ad: off + a - ad + n]
        return None
    return rd
stock, reb, nmf, ledger = sys.argv[1:5]; names = sys.argv[5:]
srd, rrd = word_reader(stock), word_reader(reb)
sn = {}; sa = []   # stock addr -> name
for l in open(ledger):
    p = l.rstrip('\n').split('\t')
    if len(p) >= 3: sn[int(p[0], 16)] = (p[2], int(p[1]))
rn = {}; ra = []
for l in open(nmf):
    p = l.split()
    if len(p) == 3 and p[1] in 'tT': rn.setdefault(p[2], int(p[0], 16))
sa = sorted(sn); ras = sorted((a, n) for n, a in rn.items()); raa = [a for a, n in ras]
def sname(a):
    i = bisect.bisect_right(sa, a) - 1
    if i < 0: return '?'
    b = sa[i]; n, sz = sn[b]; return n if a == b else '%s+%x' % (n, a - b) if a < b + sz else '?%x' % a
def rname(a):
    i = bisect.bisect_right(raa, a) - 1
    if i < 0: return '?'
    b, n = ras[i]; return n if a == b else '%s+%x' % (n, a - b)
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN); md.detail = False
def dis(rd, a, size):
    b = rd(a, size)
    if b is None: return None
    return [(i.address, i.mnemonic, i.op_str) for i in md.disasm(b, a)] if len(list(md.disasm(b, a))) == size // 4 else [(a + 4 * k, '.long', '%08x' % struct.unpack('>I', b[4*k:4*k+4])[0]) for k in range(size // 4)]
bybase = {n: a for a, (n, s) in sn.items()}
for n in names:
    if n not in bybase: print(n, 'NOT IN LEDGER'); continue
    a = bybase[n]; size = sn[a][1]
    r = rn.get(n)
    if r is None: print(n, 'NO REBUILT SYMBOL'); continue
    si, ri = dis(srd, a, size), dis(rrd, r, size)
    diffs = []; eq = True; ident = True
    for k, ((xa, xm, xo), (ya, ym, yo)) in enumerate(zip(si, ri)):
        if (xm, xo) == (ym, yo): continue
        ident = False
        bx, by = None, None
        if xm in ('b', 'bl', 'bla', 'bc', 'bdnz', 'bdz', 'beq', 'bne', 'blt', 'bgt', 'ble', 'bge', 'bso', 'bns') or xm.startswith('b'):
            mx = re.search(r'0x([0-9a-f]+)$', xo); my = re.search(r'0x([0-9a-f]+)$', yo)
            if mx and my and xm == ym:
                tx, ty = int(mx.group(1), 16), int(my.group(1), 16)
                # branch inside the function: same relative offset; else same target name
                if a <= tx < a + size and r <= ty < r + size and tx - a == ty - r and xo.replace(mx.group(0), '') == yo.replace(my.group(0), ''): continue
                if sname(tx) == rname(ty) and xo.replace(mx.group(0), '') == yo.replace(my.group(0), ''): continue
        diffs.append((xa - a, '%s %s' % (xm, xo), '%s %s' % (ym, yo)))
    print('%-40s %s' % (n, 'IDENTICAL (%d instructions)' % len(si) if ident else 'EQUIVALENT (branch targets by name)' if not diffs else '%d DIFFERENT of %d: %s' % (len(diffs), len(si), '; '.join('+%x [%s | %s]' % d for d in diffs[:8]))))
