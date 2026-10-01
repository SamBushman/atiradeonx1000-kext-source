#!/usr/bin/env python3
"""uninit_local_scan.py [FILES...]  (#85) - find the "Ghidra split one stack object into scalars" defect class in the ported sources.

Ghidra names every stack slot separately (`local_54`, `auStack_f0[156]`...). When a callee fills a struct through `&auStack_f0`, the
fields that follow it in memory (`local_54`, `local_50`) are written by the callee but, in the C++ port, are plain scalars the compiler sees
as UNINITIALISED; gcc then treats `if (local_54 != 0)` as undefined and may delete the branch (a whole call tree vanishes from the rebuild).
Reports, per function, locals that are read but never assigned and never have their address taken (the stack slot the callee filled
through a neighbouring `&auStack_*` / `&local_*`; the layout is encoded in the hex suffixes: local_f8 is at -0xf8).
Defaults to Sources/*.cpp.  Exit status 1 if anything is reported."""
import sys, re, glob
files = sys.argv[1:] or sorted(glob.glob('Sources/*.cpp'))
bad = 0
for f in files:
    src = open(f).read()
    parts = re.split(r'(?m)^(?=/\* real addr )', src)
    for p in parts[1:] if len(parts) > 1 else parts:
        head = p.split('\n', 1)[0]
        body = re.sub(r'/\*.*?\*/', '', p, flags=re.S)
        body = re.sub(r'//[^\n]*', '', body)
        locs = {}                                    # name -> (stack offset, size)
        for m in re.finditer(r'^\s*(?:UInt8|UInt16|UInt32|SInt8|SInt16|SInt32|int|unsigned int|char|short|float|double|[A-Za-z_]\w*\s*\*)\s+((?:local|auStack|stack)_?(?:0x)?([0-9a-f]+))\s*(?:\[(\d+)\])?\s*;', body, re.M):
            name, off, n = m.group(1), int(m.group(2), 16), m.group(3)
            size = int(n) if n else 4
            if re.search(r'UInt16|SInt16|short', m.group(0)) and not n: size = 2
            if re.search(r'UInt8|SInt8|char', m.group(0)) and not n: size = 1
            locs[name] = (off, size, bool(n))
        if not locs: continue
        for name, (off, size, isarr) in locs.items():
            uses = [m.start() for m in re.finditer(r'(?<![\w.])%s(?!\w)' % re.escape(name), body)]
            decl = uses[0] if uses else 0
            rest = body[decl + len(name):]
            assigned = bool(re.search(r'(?<![\w.])%s\s*(\[[^\]]*\])?\s*=[^=]' % re.escape(name), rest)) or \
                       bool(re.search(r'&\s*%s(?!\w)' % re.escape(name), rest)) or isarr and bool(re.search(r'(?<![\w&.])%s(?!\w)\s*[,)]|\(\s*(?:int|SInt32|UInt32|unsigned int)\s*\)\s*%s(?![\w\[])|=\s*%s\s*;' % ((re.escape(name),) * 3), rest))
            reads = len(re.findall(r'(?<![\w.&])%s(?!\w)(?!\s*=[^=])' % re.escape(name), rest))
            if reads and not assigned:
                bad += 1; print('%s  %s: `%s` (stack -0x%x) is read but never assigned and its address is never taken' % (f, head[:60], name, off))
print('uninit_local_scan: %d findings' % bad)
sys.exit(1 if bad else 0)
