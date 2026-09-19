#!/usr/bin/env python3
"""stub_target.py KEXT_BIN HEXADDR... - name the symbol each lazy-binding stub / long-branch island jumps to,
straight from the kext's Mach-O relocation table (`lis r12` carries an ext HI16 relocation naming the symbol; a
long-branch island to a function in the kext carries a local relocation and the target is read from the table)."""
import struct, sys, subprocess
sys.path.insert(0, __file__.rsplit('/', 1)[0])
def load(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if cpu == 18: d = d[off:off+size]; break
    return d
d = load(sys.argv[1])
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
    syms.append((d[stroff+strx:d.index(b'\0', stroff+strx)].decode('latin1'), sect, val))
hi = {}
for i in range(tnr):
    w0, w1 = struct.unpack('>II', d[tro+8*i:tro+8*i+8])
    if not (w0 & 0x80000000) and (w1 >> 4) & 1 and (w1 & 0xf) in (4, 6): hi[w0] = syms[w1 >> 8][0]
for a in sys.argv[2:]:
    n = hi.get(int(a, 16), '?')
    dn = subprocess.run(['c++filt'], input=n[1:] if n.startswith('__Z') else n, capture_output=True, text=True).stdout.strip()
    print('%s -> %s' % (a, dn if n.startswith('__Z') else n))
