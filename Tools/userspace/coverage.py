#!/usr/bin/env python3
"""coverage.py SLICE RANGES.tsv - uncovered parts of __text (union of all Ghidra function body ranges); prints the biggest gaps."""
import sys, struct
d = open(sys.argv[1], 'rb').read(); be = struct.unpack('>I', d[:4])[0] == 0xfeedface; e = '>' if be else '<'
nc = struct.unpack(e + 'I', d[16:20])[0]; p = 28; text = []
for _ in range(nc):
    c, cs = struct.unpack(e + 'II', d[p:p + 8])
    if c == 1:
        ns = struct.unpack(e + 'I', d[p + 48:p + 52])[0]; q = p + 56
        for _ in range(ns):
            nm = d[q:q + 16].rstrip(b'\0').decode(); a, sz = struct.unpack(e + '2I', d[q + 32:q + 40]); q += 68
            if nm == '__text': text.append((a, a + sz))
    p += cs
rs = []
for l in open(sys.argv[2]):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3 and f[2] == 'fn':
        for r in f[3].split(';'):
            if r: a, b = r.split('-'); rs.append((int(a, 16), int(b, 16)))
rs.sort(); gaps = []
for lo, hi in text:
    cur = lo
    for a, b in rs:
        if b <= cur or a >= hi: continue
        if a > cur: gaps.append((cur, a))
        cur = max(cur, b)
    if cur < hi: gaps.append((cur, hi))
tot = sum(hi - lo for lo, hi in text); gt = sum(b - a for a, b in gaps)
print('text %d bytes, uncovered %d (%.1f%%), %d gaps' % (tot, gt, 100 * gt / tot, len(gaps)))
for a, b in sorted(gaps, key=lambda g: g[0] - g[1])[:int(sys.argv[3]) if len(sys.argv) > 3 else 10]:
    n_ = min(4, (b - a) // 4); w = struct.unpack(e + '%dI' % n_, d[a:a + 4 * n_]) if n_ else ()
    print('  %x-%x %d bytes' % (a, b, b - a), [hex(x) for x in w])
