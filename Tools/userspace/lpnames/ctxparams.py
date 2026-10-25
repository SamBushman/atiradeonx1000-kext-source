#!/usr/bin/env python3
"""ctxparams.py DIR OUT.tsv PARTLO PARTHI : a placeholder parameter used as the GL context in the command-stream idiom
(`(**(code **)(P + 0x2758))(P, n)` reserve hook, `*(code **)(P + 0x275c)` commit hook, `0x00002748 + P + 4` write cursor) -> glContext."""
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
        txt = '\n'.join(L[a:b]); idents = set(re.findall(r'[A-Za-z_]\w*', txt))
        for p in sorted(set(re.findall(r'\bparam_\d+\b', txt))):
            if re.search(r'\(%s \+ 0x275[8c]\)|0x00002748 \+ %s' % (p, p), txt):
                nm = 'glContext'
                if nm in idents: continue
                rows.append('local\t%s\t%s\t%s\tINFERRED\tused as the GL context of the command-stream idiom: reserve hook at +0x2758, commit hook at +0x275c, write cursor at +0x2748+4' % (fn, p, nm)); idents.add(nm)
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(len(rows), file=sys.stderr)
