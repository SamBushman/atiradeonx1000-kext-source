#!/usr/bin/env python3
"""const_ptr.py KEXT ADDR... - resolve pointer-table words (Ghidra PTR_/DAT_ names) in __const/__data: the relocation on the
word names an external symbol, or (local reloc) the word itself holds a local address."""
import struct, sys, subprocess
d = open(sys.argv[1], 'rb').read()
n = struct.unpack('>I', d[4:8])[0]
for i in range(n):
    cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
    if cpu == 18: d = d[off:off+size]; break
nc = struct.unpack('>I', d[16:20])[0]; p = 28; secs = []
for _ in range(nc):
    c, cs = struct.unpack('>II', d[p:p+8])
    if c == 1:
        ns = struct.unpack('>I', d[p+48:p+52])[0]; q = p+56
        for _ in range(ns):
            name = d[q:q+16].rstrip(b'\0').decode()
            a, s, o, al, ro, nr = struct.unpack('>6I', d[q+32:q+56]); secs.append((name, a, s, o, ro, nr)); q += 68
    elif c == 2: symoff, nsyms, stroff, strsize = struct.unpack('>4I', d[p+8:p+24])
    p += cs
syms = []
for i in range(nsyms):
    strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff+12*i:symoff+12*i+12])
    syms.append(d[stroff+strx:d.index(b'\0', stroff+strx)].decode('latin1'))
def dm(x):
    return subprocess.run(['c++filt'], input=x[1:] if x.startswith('__Z') else x, capture_output=True, text=True).stdout.strip() if x.startswith('__Z') else x
for a in sys.argv[2:]:
    addr = int(a, 16)
    for name, sa, ss, so, ro, nr in secs:
        if sa <= addr < sa + ss:
            val = struct.unpack('>I', d[so+addr-sa:so+addr-sa+4])[0]
            hit = None
            for i in range(nr):
                w0, w1 = struct.unpack('>II', d[ro+8*i:ro+8*i+8])
                if not (w0 & 0x80000000) and w0 == addr - sa:
                    hit = (w1 >> 4) & 1, w1 >> 8
            if hit and hit[0]:
                print('%s -> %s' % (a, dm(syms[hit[1]])))
            else:
                print('%s -> local 0x%x' % (a, val))
            break
