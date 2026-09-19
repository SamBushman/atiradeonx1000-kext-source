#!/usr/bin/env python3
"""coverage.py SLICE RANGES.tsv [N] - which parts of __text are NOT inside any Ghidra function body, classified:
  padding  every word is a nop (0x60000000) or zero (alignment between functions)
  table    every word is a small 4-aligned offset (Darwin embedded switch tables / the words after a `bctr`)
  other    anything else - listed, these are the candidates for code Ghidra did not turn into a function"""
import sys, struct
d = open(sys.argv[1], 'rb').read(); be = struct.unpack('>I', d[:4])[0] == 0xfeedface; e = '>' if be else '<'
nc = struct.unpack(e + 'I', d[16:20])[0]; p = 28; text = []
for _ in range(nc):
    c, cs = struct.unpack(e + 'II', d[p:p + 8])
    if c == 1:
        ns = struct.unpack(e + 'I', d[p + 48:p + 52])[0]; q = p + 56
        for _ in range(ns):
            nm = d[q:q + 16].rstrip(b'\0').decode(); a, sz, off = struct.unpack(e + '3I', d[q + 32:q + 44]); q += 68
            if nm == '__text': text.append((a, a + sz, off))
    p += cs
rs = []
for l in open(sys.argv[2]):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3 and f[2] == 'fn':
        for r in f[3].split(';'):
            if r: a, b = r.split('-'); rs.append((int(a, 16), int(b, 16)))
rs.sort(); gaps = []
for lo, hi, off in text:
    cur = lo
    for a, b in rs:
        if b <= cur or a >= hi: continue
        if a > cur: gaps.append((cur, a, off - lo))
        cur = max(cur, b)
    if cur < hi: gaps.append((cur, hi, off - lo))
tot = sum(hi - lo for lo, hi, _ in text); gt = sum(b - a for a, b, _ in gaps)
kinds = {'padding': [0, 0], 'table': [0, 0], 'other': [0, 0]}; other = []
for a, b, delta in gaps:
    w = struct.unpack(e + '%dI' % ((b - a) // 4), d[a + delta:a + delta + 4 * ((b - a) // 4)])
    if all(x in (0x60000000, 0) for x in w): k = 'padding'
    elif all(((x + 0x80000) & 0xffffffff) < 0x100000 and x % 4 == 0 for x in w): k = 'table'   # small signed offsets
    else: k = 'other'; other.append((a, b, w[:4]))
    kinds[k][0] += 1; kinds[k][1] += b - a
print('text %d bytes, uncovered %d (%.1f%%) in %d gaps: %s' % (tot, gt, 100 * gt / tot, len(gaps), ', '.join('%s %d gaps/%d bytes' % (k, v[0], v[1]) for k, v in kinds.items())))
for a, b, w in sorted(other, key=lambda g: g[0] - g[1])[:int(sys.argv[3]) if len(sys.argv) > 3 else 20]:
    print('  OTHER %x-%x %d bytes' % (a, b, b - a), [hex(x) for x in w])
