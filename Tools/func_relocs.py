#!/usr/bin/env python3
"""func_relocs.py KEXT_BIN START END - list every __text relocation in [START,END) (hex): reloc type, the ext symbol it
names (c++filt'd) or, for scattered/local ones, the section-relative target value. Resolves Ghidra's per-site
`_ASICSupportsAGP` mislabel of zero-immediate data relocs (the real target is the symbol here)."""
import struct, sys, subprocess
def load(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if cpu == 18: return d[off:off+size]
    return d
d = load(sys.argv[1]); lo = int(sys.argv[2], 16); hi = int(sys.argv[3], 16)
nc = struct.unpack('>I', d[16:20])[0]; p = 28
for _ in range(nc):
    c, cs = struct.unpack('>II', d[p:p+8])
    if c == 1:
        ns = struct.unpack('>I', d[p+48:p+52])[0]; q = p+56
        for _ in range(ns):
            name = d[q:q+16].rstrip(b'\0').decode()
            a, s, o, al, ro, nr = struct.unpack('>6I', d[q+32:q+56])
            if name == '__text': tro, tnr = ro, nr
            q += 68
    elif c == 2: symoff, nsyms, stroff, strsize = struct.unpack('>4I', d[p+8:p+24])
    p += cs
syms = []
for i in range(nsyms):
    strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff+12*i:symoff+12*i+12])
    syms.append(d[stroff+strx:d.index(b'\0', stroff+strx)].decode('latin1'))
def dm(n):
    if n.startswith('__Z'):
        return subprocess.run(['c++filt'], input=n[1:], capture_output=True, text=True).stdout.strip()
    return n
names = {4: 'HI16', 5: 'LO16', 6: 'HA16', 1: 'PAIR', 3: 'BR24', 2: 'BR14', 0: 'VANILLA'}
i = 0
while i < tnr:
    w0, w1 = struct.unpack('>II', d[tro+8*i:tro+8*i+8]); i += 1
    if w0 & 0x80000000:
        a = w0 & 0xffffff; t = (w0 >> 24) & 0xf
        if lo <= a < hi: print('%x %s scattered value=0x%x' % (a, names.get(t, t), w1))
    else:
        t = w1 & 0xf; ext = (w1 >> 4) & 1
        if lo <= w0 < hi and t != 1:
            print('%x %s %s' % (w0, names.get(t, t), dm(syms[w1 >> 8]) if ext else 'local sect %d' % (w1 >> 8)))
