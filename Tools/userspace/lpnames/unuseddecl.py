#!/usr/bin/env python3
"""unuseddecl.py FILE [--fix] : declarations of Ghidra placeholder names (iVarN, local_x, ...) that nothing in the function uses any more (left behind by prep.py + web rows)"""
import sys, re
f = sys.argv[1]; fix = '--fix' in sys.argv
L = open(f, errors='surrogateescape').read().split('\n')
H = re.compile(r'^/\* (\S+) @ 0x'); PH = re.compile(r'^\s+[\w ]+?[ *]+((?:[a-z]{0,3}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_\w+))(\[\w+\])?;$')
starts = [i for i, l in enumerate(L) if H.match(l)] + [len(L)]
drop = []
for a, b in zip(starts, starts[1:]):
    for i in range(a, b):
        m = PH.match(L[i])
        if not m: continue
        n = m.group(1); rx = re.compile(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(n))
        if not any(rx.search(L[j]) for j in range(a, b) if j != i and not PH.match(L[j])):
            print('%s:%d: %s unused in %s' % (f, i + 1, n, H.match(L[a]).group(1))); drop.append(i)
if fix and drop:
    for i in sorted(set(drop), reverse=True): del L[i]
    open(f, 'w', errors='surrogateescape').write('\n'.join(L))
