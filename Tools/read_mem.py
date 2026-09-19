#!/usr/bin/env python3
"""read_mem.py KEXT_BIN HEXADDR LEN [f|d|w|b] - dump bytes of the stock PPC image at a Ghidra address (object-file
section addresses are contiguous, so Ghidra address == section address). Formats: w = 32-bit big-endian words
(default), f = floats, d = doubles, b = bytes."""
import struct, sys
d = open(sys.argv[1], 'rb').read()
if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
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
            a, s, o, al, ro, nr = struct.unpack('>6I', d[q+32:q+56]); secs.append((name, a, s, o)); q += 68
    p += cs
addr = int(sys.argv[2], 16); ln = int(sys.argv[3], 0); fmt = sys.argv[4] if len(sys.argv) > 4 else 'w'
for name, a, s, o in secs:
    if a <= addr < a + s:
        b = d[o+addr-a:o+addr-a+ln]
        print('section', name)
        if fmt == 'b':
            for i in range(0, len(b), 16): print('%x: %s' % (addr+i, ' '.join('%02x' % x for x in b[i:i+16])))
        elif fmt == 'f':
            for i in range(0, len(b)-3, 4): print('%x: %r' % (addr+i, struct.unpack('>f', b[i:i+4])[0]))
        elif fmt == 'd':
            for i in range(0, len(b)-7, 8): print('%x: %r' % (addr+i, struct.unpack('>d', b[i:i+8])[0]))
        else:
            for i in range(0, len(b)-3, 4): print('%x: %08x' % (addr+i, struct.unpack('>I', b[i:i+4])[0]))
        break
else:
    print('not mapped')
