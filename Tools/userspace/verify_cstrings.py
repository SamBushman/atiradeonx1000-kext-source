#!/usr/bin/env python3
"""verify_cstrings.py MACHO CSTRINGS.c - rebuild every string section from the generated C string literals and compare with the binary's bytes."""
import re, struct, sys
d = open(sys.argv[1], 'rb').read()
if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
    for i in range(struct.unpack('>I', d[4:8])[0]):
        cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
        if cpu == 18: d = d[off:off + size]; break
nc = struct.unpack('>I', d[16:20])[0]; q = 28; secs = []
for _ in range(nc):
    c, cs = struct.unpack('>II', d[q:q + 8])
    if c == 1:
        ns = struct.unpack('>I', d[q + 48:q + 52])[0]; r = q + 56
        for _ in range(ns):
            a, sz, off = struct.unpack('>3I', d[r + 32:r + 44]); fl = struct.unpack(">I", d[r + 56:r + 60])[0]; r += 68
            if (fl & 0xff) == 2: secs.append((a, d[off:off + sz]))
    q += cs
txt = open(sys.argv[2]).read(); got = {}
for m in re.finditer(r'const char cstr_([0-9a-f]+)\[(\d+)\] = "((?:[^"\\]|\\.)*)";', txt):
    s = m.group(3); b = bytearray(); i = 0
    while i < len(s):
        if s[i] == '\\':
            c = s[i + 1]
            if c in '01234567': b.append(int(s[i + 1:i + 4], 8)); i += 4; continue
            b.append({'n': 10, 't': 9, '"': 34, '\\': 92}[c]); i += 2
        else: b.append(ord(s[i])); i += 1
    got[int(m.group(1), 16)] = bytes(b) + b'\0'
ok = all(b''.join(got[k] for k in sorted(got) if a <= k < a + len(body)) == body for a, body in secs)
print('%s: %d string bytes, byte-identical: %s' % (sys.argv[2].split('/')[-4] if '/' in sys.argv[2] else sys.argv[2], sum(len(b) for a, b in secs), ok))
sys.exit(0 if ok else 1)
