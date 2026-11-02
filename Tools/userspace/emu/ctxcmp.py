#!/usr/bin/env python3
"""ctxcmp.py DUMP_A DUMP_B [SECTION ...] - compare two ctxdump_prog.sh dumps (A = stock). Sections: CTX (the 11160-byte context), TEX (texture object bound at ctx+0x18c), RES (its resident backing, tex+0x34), FMT (its format descriptor, tex+0x30).
Words are normalised before comparing: inside the section itself -> ('self', off); a heap-looking word (0x01000000..0x10000000) or a driver-image word (0x00400000..0x00500000) -> class only; everything else exact.
Prints `SECTION +off  stock  rebuilt` for every differing word."""
import re, sys
SECS = ['CTX', 'TEX', 'RES', 'FMT', 'CAPS']
def load(f):
    out = {}; cur = None; base = {}
    for l in open(f, errors='replace'):
        l = l.replace('(gdb) ', '')
        m = re.match(r'^(CTX|TEX|RES|FMT|CAPS) ([0-9a-f]+)', l)
        if m:
            cur = m.group(1); base[cur] = int(m.group(2), 16); out[cur] = []; continue
        m = re.match(r'^0x[0-9a-f]+[^:]*:\s*(.*)$', l)
        if m and cur: out[cur] += [int(x, 16) for x in re.findall(r'0x([0-9a-f]+)', m.group(1))]
    return base, out
ba, A = load(sys.argv[1]); bb, B = load(sys.argv[2])
want = sys.argv[3:] or SECS
def norm(base, n, v):
    if base <= v < base + 4 * n: return ('self', v - base)
    if 0x01000000 <= v < 0x10000000: return ('heap',)
    if 0x00400000 <= v < 0x00500000: return ('img',)
    return ('v', v)
tot = 0
for s in want:
    if s not in A or s not in B: continue
    n = min(len(A[s]), len(B[s]))
    for i in range(n):
        if norm(ba[s], n, A[s][i]) != norm(bb[s], n, B[s][i]):
            tot += 1; print('%s +%04x  %08x  %08x' % (s, i * 4, A[s][i], B[s][i]))
print(tot, 'differing words')
