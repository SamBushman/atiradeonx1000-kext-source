#!/usr/bin/env python3
"""decomp_vs_source.py WORKDIR LIST.tsv  (#85 static audit)

For every method in LIST.tsv (`ADDR<TAB>size<TAB>Class::name<TAB>symbol`, e.g. the hand-written ones) compare the constants of the fresh Ghidra decompile
(WORKDIR/0xADDR.txt) with the constants of the C++ body in Sources/: every hex literal >= 0x10 (field offsets, masks, magic numbers) and every called function name.
Reports what the decompile has and the source lacks. This catches omitted statements that size / callee / displacement metrics blur (a missing block that
reuses constants shows nothing, a block with its own constants shows up here). The decompile itself can omit code, so a clean result is not proof (see the DVD
clientMemoryForType block): the shipped disassembly stays the oracle."""
import sys, re, glob, os, collections
work, lst = sys.argv[1], sys.argv[2]
src = {f: open(f).read() for f in glob.glob('Sources/*.cpp')}
def body(cls, fn):
    out = []
    for f, s in src.items():
        for m in re.finditer(r'(?m)^[\w:<>\*& ]*\b%s::%s\s*\(' % (re.escape(cls), re.escape(fn)), s):
            j = s.find('{', m.end())
            if j < 0 or j - m.end() > 600: continue
            d = 0; k = j
            while k < len(s):
                if s[k] == '{': d += 1
                elif s[k] == '}':
                    d -= 1
                    if d == 0: break
                k += 1
            out.append(s[m.start():k + 1])
    return '\n'.join(out)
def freefn(name):
    out = []
    for f, s in src.items():
        for m in re.finditer(r'(?m)^[\w:<>\*& ]*\b%s\s*\(' % re.escape(name), s):
            j = s.find('{', m.end())
            if j < 0 or j - m.end() > 600: continue
            d = 0; k = j
            while k < len(s):
                if s[k] == '{': d += 1
                elif s[k] == '}':
                    d -= 1
                    if d == 0: break
                k += 1
            out.append(s[m.start():k + 1])
    return '\n'.join(out)
def hexes(t):
    t = re.sub(r'/\*.*?\*/', '', t, flags=re.S); t = re.sub(r'//[^\n]*', '', t)
    c = collections.Counter()
    for m in re.finditer(r'\b0x([0-9a-fA-F]+)\b', t):
        v = int(m.group(1), 16)
        if v >= 0x10: c[v] += 1
    return c
rows = []
for l in open(lst):
    f = l.rstrip('\n').split('\t')
    if len(f) < 4: continue
    addr, size, name = f[0], int(f[1]), f[2]
    p = '%s/0x%x.txt' % (work, int(addr, 16))
    if not os.path.exists(p): continue
    d = open(p).read()
    if 'completed=true' not in d.split('\n')[0]: continue
    if '::' in name: b = body(*name.split('::')[-2:])
    else: b = freefn(name)
    if not b: continue
    D, H = hexes(d), hexes(b)
    missing = {v: n for v, n in D.items() if v not in H}
    # constants the source has but the decompile lacks are not interesting (hand-added knowledge)
    rows.append((len(missing), size, name, sorted(missing)[:14]))
rows.sort(reverse=True)
for n, size, name, miss in rows:
    if n: print('%3d missing  %5dB  %-52s %s' % (n, size, name, ' '.join('0x%x' % v for v in miss)))
print('%d methods compared, %d with decompile constants absent from the source' % (len(rows), sum(1 for r in rows if r[0])))
