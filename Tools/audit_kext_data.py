#!/usr/bin/env python3
"""audit_kext_data.py STOCK_KEXT OURS_KEXT - compare the data symbols (in __const/__data/__common/__bss/__literal*) of the shipped kext and our build:
symbols only one side defines, and size differences (distance to the next symbol in the same section)."""
import sys, struct, subprocess, re
def load(p):
    d = open(p, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        for i in range(struct.unpack('>I', d[4:8])[0]):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
            if cpu == 18: d = d[off:off + size]; break
    nc = struct.unpack('>I', d[16:20])[0]; q = 28; secs = []; symoff = nsyms = stroff = 0
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[q:q + 8])
        if c == 1:
            ns = struct.unpack('>I', d[q + 48:q + 52])[0]; r = q + 56
            for _ in range(ns):
                nm = d[r:r + 16].rstrip(b'\0').decode(); a, sz, off = struct.unpack('>3I', d[r + 32:r + 44]); r += 68; secs.append((nm, a, sz, off))
        elif c == 2: symoff, nsyms, stroff, _s = struct.unpack('>4I', d[q + 8:q + 24])
        q += cs
    out = {}
    for i in range(nsyms):
        n_strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff + 12 * i:symoff + 12 * i + 12])
        if (t & 0x0e) == 0x0e and sect and sect <= len(secs):
            nm = d[stroff + n_strx:d.index(b'\0', stroff + n_strx)].decode('latin1'); out[nm] = (secs[sect - 1][0], val)
        elif (t & 0x0e) == 0 and (t & 1) and val:   # common symbol: size in value
            nm = d[stroff + n_strx:d.index(b'\0', stroff + n_strx)].decode('latin1'); out[nm] = ('__common', -val)
    return out, secs, d
def sizes(syms, secs):
    bysec = {}
    for nm, (s, v) in syms.items():
        if v >= 0: bysec.setdefault(s, []).append((v, nm))
    res = {}
    for s, lst in bysec.items():
        lst.sort(); end = [x for x in secs if x[0] == s][0]; e = end[1] + end[2]
        for i, (v, nm) in enumerate(lst): res[nm] = (s, (lst[i + 1][0] if i + 1 < len(lst) else e) - v)
    for nm, (s, v) in syms.items():
        if v < 0: res[nm] = (s, -v)
    return res
sa, seca, _ = load(sys.argv[1]); sb, secb, _ = load(sys.argv[2])
DATA = ('__const', '__data', '__common', '__bss', '__literal4', '__literal8', '__cstring', '__constructor', '__destructor')
za = {k: v for k, v in sizes(sa, seca).items() if v[0] in DATA}; zb = {k: v for k, v in sizes(sb, secb).items() if v[0] in DATA}
only_a = sorted(set(za) - set(zb)); only_b = sorted(set(zb) - set(za)); diff = [(k, za[k], zb[k]) for k in za if k in zb and za[k][1] != zb[k][1]]
print('stock defines %d data symbols, ours %d; stock-only %d, ours-only %d, size differs %d' % (len(za), len(zb), len(only_a), len(only_b), len(diff)))
for k in only_a: print('STOCK-ONLY %-70s %s %d' % (k[:70], za[k][0], za[k][1]))
for k in only_b: print('OURS-ONLY  %-70s %s %d' % (k[:70], zb[k][0], zb[k][1]))
for k, a, b in diff: print('SIZE %-70s stock %s %d ours %s %d' % (k[:70], a[0], a[1], b[0], b[1]))

# ---- content match: is a stock-only data symbol's content present in our build under another name? (pointer words = relocations are wildcards)
def relocwords(d, secs):
    w = set()
    for nm, a, sz, off in secs:
        pass
    return w
def raw(p):
    d = open(p, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        for i in range(struct.unpack('>I', d[4:8])[0]):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
            if cpu == 18: d = d[off:off + size]; break
    return d
def sect_bytes_and_relocs(d, secs_full):
    out = {}
    for (nm, a, sz, off, reloff, nreloc) in secs_full:
        b = bytearray(d[off:off + sz]) if nm not in ('__bss', '__common') else bytearray(sz)
        mask = bytearray(sz)
        for i in range(nreloc):
            w0, w1 = struct.unpack('>II', d[reloff + 8 * i:reloff + 8 * i + 8])
            if w0 & 0x80000000: addr = w0 & 0xffffff; length = 4
            else: addr = w0; length = 4
            for k in range(4):
                if addr + k < sz: mask[addr + k] = 1
        out[nm] = (a, bytes(b), bytes(mask))
    return out
def full_secs(d):
    nc = struct.unpack('>I', d[16:20])[0]; q = 28; res = []
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[q:q + 8])
        if c == 1:
            ns = struct.unpack('>I', d[q + 48:q + 52])[0]; r = q + 56
            for _ in range(ns):
                nm = d[r:r + 16].rstrip(b'\0').decode(); a, sz, off, al, reloff, nreloc = struct.unpack('>6I', d[r + 32:r + 56]); r += 68
                res.append((nm, a, sz, off, reloff, nreloc))
        q += cs
    return res
da = raw(sys.argv[1]); db = raw(sys.argv[2]); sba = sect_bytes_and_relocs(da, full_secs(da)); sbb = sect_bytes_and_relocs(db, full_secs(db))
print('\n-- content search for stock-only data symbols (relocated words are wildcards):')
missing = 0
for k in only_a:
    s, sz = za[k]
    if s not in ('__const', '__data') or sz < 8 or k not in sa: continue
    a0, b0, m0 = sba[s]; off = sa[k][1] - a0; pat = b0[off:off + sz]; pm = m0[off:off + sz]
    found = None
    for sec2, (a2, b2, m2) in sbb.items():
        if sec2 not in ('__const', '__data'): continue
        for i in range(0, len(b2) - sz + 1, 4):
            if all(pm[j] or m2[i + j] or pat[j] == b2[i + j] for j in range(sz)) and any(not pm[j] for j in range(sz)):
                found = (sec2, i); break
        if found: break
    if found:
        ours = [n for n, (ss, v) in sb.items() if ss == found[0] and v - sbb[found[0]][0] <= found[1] < v - sbb[found[0]][0] + 4096]
        print('  %-62s %5d bytes: present in ours at %s+0x%x' % (k[:62], sz, found[0], found[1]))
    else:
        missing += 1; print('  %-62s %5d bytes: NOT FOUND in our build' % (k[:62], sz))
print('%d stock data symbols with content not found' % missing)
