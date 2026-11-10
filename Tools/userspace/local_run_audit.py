#!/usr/bin/env python3
"""local_run_audit.py CORPUS_DIR [--list]  - stack locals whose ADDRESS is taken and that sit in a run of adjacent scalar locals (Ghidra's separate `local_110`, `local_10c`, ... of one stack struct).

Ghidra declares a stack structure that the code fills word by word and then hands to a callee by address (`memcpy(p, &local_110, 0x3c)`, `PPStreamAddOperation(s, &local_d0, 0, 0)`) as one scalar
local per stored word. The C compiler is free to place separate locals anywhere, so the callee reads whatever the rebuilt frame has after `&local_110`, not the fifteen words the code stored (class #20:
_glePPParse, found by the graph mock: the parser's +0x450 block held stack residue in the rebuilt image). Output: per function, the address-taken local, the run of adjacent scalar locals above it (the
words a callee can read) and the callee. Gaps of at most one word are bridged (a member the code never touches). Names are Ghidra's `local_<hex>` = stack offset -<hex>; adjacent = offset + size."""
import sys, re, glob, os
corpus = sys.argv[1]
FN = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
DECL = re.compile(r'^\s+(?:(?:undefined\d?|uint|int|short|ushort|char|byte|float|double|long|bool|undefined|size_t|code \*|unsigned \w+|\w+ \*+|\w+)\s+)+\*?local_([0-9a-f]+)(?:\s*\[(\d+)\])?;')
SZ = {'undefined1': 1, 'undefined2': 2, 'undefined4': 4, 'undefined8': 8, 'char': 1, 'byte': 1, 'short': 2, 'ushort': 2, 'int': 4, 'uint': 4, 'float': 4, 'double': 8, 'bool': 1, 'long': 4}
out = []
for path in sorted(glob.glob(os.path.join(corpus, 'part_*.c'))):
    lines = open(path, errors='replace').read().split('\n')
    i = 0
    while i < len(lines):
        m = FN.match(lines[i])
        if not m: i += 1; continue
        name = m.group(1); j = i + 1
        while j < len(lines) and not lines[j].startswith('/* '): j += 1
        body = lines[i:j]; i = j
        loc = {}   # offset(-hex) -> (name, size)
        for l in body:
            d = DECL.match(l)
            if not d: continue
            t = l.strip().split()[0]
            n = int(d.group(1), 16)
            arr = int(d.group(2)) if d.group(2) else 1
            ptr = '*' in l.split('local_')[0]
            sz = 4 if ptr else SZ.get(t, 4)
            loc[-n] = (('local_' + d.group(1)), sz * arr, bool(d.group(2)))
        text = '\n'.join(body)
        taken = set()
        for mm in re.finditer(r'&local_([0-9a-f]+)', text):
            taken.add(-int(mm.group(1), 16))
        # maximal runs of adjacent scalar locals (a gap of one word is bridged) that contain at least one address-taken local: the memory a callee can read from any of those addresses
        offs = sorted(o for o in loc if not loc[o][2]); k = 0
        while k < len(offs):
            run = [offs[k]]; e = offs[k] + loc[offs[k]][1]; k += 1
            while k < len(offs) and offs[k] <= e + 4 and offs[k] >= e: run.append(offs[k]); e = offs[k] + loc[offs[k]][1]; k += 1
            tk = [o for o in run if o in taken]
            if len(run) < 2 or not tk: continue
            kinds = set(l[0] for l in (body[i0] for i0 in []))  # placeholder, types below
            call = [l.strip() for l in body if '&local_%x' % -tk[0] in l][:1]
            out.append((os.path.basename(path), name, loc[run[0]][0], len(run), e - run[0], len(tk), call[0][:100] if call else ''))
print('%d address-taken locals followed by a run of adjacent scalar locals' % len(out))
for o in out: print('%s %s first=%s words=%d bytes=%d addrtaken=%d  %s' % o)
