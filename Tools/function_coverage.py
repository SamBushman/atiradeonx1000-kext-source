#!/usr/bin/env python3
"""
function_coverage.py - which of the shipped kext's C++ methods have a body in the rebuilt kext?

The shipped ATIRadeonX1000.kext still carries its symbol table, so every real method is
named. This compares those names (by class + method name, ignoring parameter encoding,
because this project declares Apple enum parameters as plain integers so the full mangled
names differ) with the symbols defined by the rebuilt kext.

Caveats: overloads collapse to one name (an overload present counts the name as present);
file-local helpers and compiler-generated members (constructors, destructors, MetaClass,
getMetaClass) are excluded.

Usage:
  (on the G5)  nm /tmp/kext_build/ATIRadeonX1000 | awk '$2=="T"||$2=="t"{print $3}' > defined.txt
  function_coverage.py SHIPPED_KEXT_BIN defined.txt
"""
import struct, re, sys
from collections import defaultdict

def shipped_names(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if cpu == 18: d = d[off:off+size]; break
    nc = struct.unpack('>I', d[16:20])[0]; p = 28
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[p:p+8])
        if c == 2: symoff, nsyms, stroff, strsize = struct.unpack('>4I', d[p+8:p+24])
        p += cs
    out = []
    for i in range(nsyms):
        strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff+12*i:symoff+12*i+12])
        if sect == 1: out.append(d[stroff+strx:d.index(b'\0', stroff+strx)].decode('latin1'))
    return out

def cm(s):
    m = re.match(r'__ZNK?(\d+)', s)
    if not m: return None
    n = int(m.group(1)); pos = m.end(); cls = s[pos:pos+n]; pos += n
    m2 = re.match(r'(\d+)', s[pos:])
    if not m2: return (cls, s[pos:pos+2])
    k = int(m2.group(1)); a = pos+len(m2.group(1)); return (cls, s[a:a+k])

SKIP = re.compile(r'^(C[12]|D[012]|MetaClass|getMetaClass)')
def main():
    real = defaultdict(set); ours = defaultdict(set)
    for n in shipped_names(sys.argv[1]):
        r = cm(n)
        if r and not SKIP.match(r[1]): real[r[0]].add(r[1])
    for l in open(sys.argv[2]):
        r = cm(l.strip())
        if r and not SKIP.match(r[1]): ours[r[0]].add(r[1])
    classes = [c for c in sorted(real) if c.startswith(('IOATIR500', 'ATIR500', 'ATIRadeon'))]
    tr = th = 0
    print('| class | shipped | rebuilt | missing |\n|---|---:|---:|---:|')
    for c in classes:
        r, o = real[c], ours[c]
        print('| %s | %d | %d | %d |' % (c, len(r), len(r & o), len(r - o))); tr += len(r); th += len(r & o)
    print('| **total** | **%d** | **%d** | **%d** |\n' % (tr, th, tr - th))
    for c in classes:
        miss = sorted(real[c] - ours[c])
        if miss: print('### %s (%d missing)\n%s\n' % (c, len(miss), ', '.join('`%s`' % m for m in miss)))
main()
