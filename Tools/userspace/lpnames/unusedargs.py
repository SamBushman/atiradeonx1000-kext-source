#!/usr/bin/env python3
"""unusedargs.py DIR OUT.tsv PARTLO PARTHI : placeholder parameters param_N (N <= 8, GPR r(N+2)) that the body never mentions -> unusedArgR<N+2>."""
import sys, re, glob
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
rows = []
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    L = open(pf, errors='replace').read().split('\n')
    spans = [(i, m.group(1)) for i, l in enumerate(L) for m in [H.match(l)] if m] + [(len(L), None)]
    for (a, fn), (b, _) in zip(spans, spans[1:]):
        body = '\n'.join(L[a + 2:b])
        # header + K&R declarations end at the first line that is exactly '{'
        k = next((i for i in range(a + 1, b) if L[i] == '{'), None)
        if k is None: continue
        decl = '\n'.join(L[a + 1:k]); rest = '\n'.join(L[k:b]); idents = set(re.findall(r'[A-Za-z_]\w*', rest + decl))
        for p in sorted(set(re.findall(r'\bparam_(\d+)\b', decl)), key=int):
            n = int(p)
            if n > 8 or re.search(r'\bparam_%s\b' % p, rest): continue
            nm = 'unusedArgR%d' % (n + 2)
            if nm in idents: continue
            rows.append('local\t%s\tparam_%s\t%s\tINFERRED\tparameter %s (register r%d) is never read by the body; callers pass whatever the register held' % (fn, p, nm, p, n + 2)); idents.add(nm)
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(len(rows), file=sys.stderr)
