#!/usr/bin/env python3
"""slice_ranges.py SLICE_FILE - print the code-section address ranges (lo-hi hex) ghidra2c needs, exactly as build_corpus.py derives them."""
import sys, struct
d = open(sys.argv[1], 'rb').read()
be = struct.unpack('>I', d[:4])[0] == 0xfeedface
e = '>' if be else '<'
ncmds = struct.unpack(e + 'I', d[16:20])[0]; p = 28; rng = []
for _ in range(ncmds):
    c, cs = struct.unpack(e + 'II', d[p:p + 8])
    if c == 1:
        ns = struct.unpack(e + 'I', d[p + 48:p + 52])[0]; q = p + 56
        for _ in range(ns):
            name = d[q:q + 16].rstrip(b'\0').decode(); a, sz = struct.unpack(e + '2I', d[q + 32:q + 40]); q += 68
            if name in ('__text', '__picsymbol_stub', '__picsymbolstub1', '__symbol_stub', '__symbol_stub1', '__textcoal_nt', '__StaticInit'):
                rng.append('%x-%x' % (a, a + sz))
    p += cs
first = min(int(r.split('-')[0], 16) for r in rng)
rng = ['0-%x' % first] + rng if first else rng
print(' '.join(rng))
