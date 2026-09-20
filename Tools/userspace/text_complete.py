#!/usr/bin/env python3
"""text_complete.py SLICE RANGES.tsv OUT.txt EXTENTS.tsv... - byte-level accounting of __text: how many bytes lie in (a) a function body Ghidra defined,
(b) a companion function (landing pad / orphan), (c) a raw block (data or asm), and how many in none of them (must be 0)."""
import sys, struct
sl, rng, out = sys.argv[1:4]; ext = sys.argv[4:]
d = open(sl, 'rb').read(); SECS = ('__text', '__picsymbolstub1', '__symbol_stub1', '__textcoal_nt', '__StaticInit')
nc = struct.unpack('>I', d[16:20])[0]; q = 28; text = []
for _ in range(nc):
    c, cs = struct.unpack('>II', d[q:q + 8])
    if c == 1:
        ns = struct.unpack('>I', d[q + 48:q + 52])[0]; r = q + 56
        for _ in range(ns):
            nm = d[r:r + 16].rstrip(b'\0').decode(); a, sz = struct.unpack('>2I', d[r + 32:r + 40]); r += 68
            if nm in SECS: text.append((nm, a, a + sz))
    q += cs
cls = {nm: bytearray(hi - lo) for nm, lo, hi in text}
def mark(a, b, v):
    for nm, lo, hi in text:
        for x in range(max(a, lo), min(b, hi)):
            if cls[nm][x - lo] == 0: cls[nm][x - lo] = v
for l in open(rng):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3 and f[2] in ('fn', 'thunk'):
        for r in f[3].split(';'):
            if r: a, b = r.split('-'); mark(int(a, 16), int(b, 16), 1)
names = {1: 'function bodies', 2: 'companion functions (landing pads, orphans)', 3: 'raw blocks (tables/padding as data, millicode/case code as asm)'}
for e in ext:
    v = 3 if '/raw/' in e or e.endswith(('.data.tsv', '.mill.tsv', '.code.tsv')) else 2
    for l in open(e):
        a, b = l.split('\t')[:2]; mark(int(a, 16), int(b, 16), v)
with open(out, 'w') as f:
    tot0 = 0
    for nm, lo, hi in text:
        c = cls[nm]; n = [c.count(i) for i in range(4)]; tot0 += n[0]
        f.write('%s (%d bytes)\n' % (nm, len(c)))
        for i in (1, 2, 3): f.write('  %-70s %d bytes\n' % (names[i], n[i]))
        f.write('  %-70s %d bytes\n' % ('in none of them', n[0]))
    f.write('TOTAL bytes of code sections in none of them: %d\n' % tot0)
print(open(out).read())
