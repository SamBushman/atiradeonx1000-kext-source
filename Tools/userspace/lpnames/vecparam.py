#!/usr/bin/env python3
"""vecparam.py DIR OUT.tsv PARTLO PARTHI : a placeholder parameter P used as the growable word buffer {count, capacity, data} (the idiom
`P[1] * 4 + 0x200` allocation, `P[2] = new data`, `P[1] = P[1] + 0x80`) -> wordVector."""
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
        txt = '\n'.join(L[a:b]); idents = set(re.findall(r'[A-Za-z_]\w*', txt)); k = 0
        for p in sorted(set(re.findall(r'\bparam_\d+\b', txt))):
            if re.search(r'\b%s\[1\] \* 4 \+ 0x200' % p, txt) and re.search(r'\b%s\[2\] = ' % p, txt) and re.search(r'\b%s\[1\] = %s\[1\] \+ 0x80' % (p, p), txt):
                k += 1; nm = 'wordVector' + ('' if k == 1 else str(k))
                if nm in idents: continue
                rows.append('local\t%s\t%s\t%s\tINFERRED\tgrowable word buffer {count, capacity, data}: P[1]*4+0x200 allocation through the context hook (+0xc), P[2] = new data, P[1] += 0x80' % (fn, p, nm)); idents.add(nm)
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(len(rows), file=sys.stderr)
