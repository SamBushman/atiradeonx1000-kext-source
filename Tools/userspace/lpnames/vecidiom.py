#!/usr/bin/env python3
"""vecidiom.py DIR OUT.tsv PARTLO PARTHI : whole-function rows for the stack word-vector triple (count, capacity, data) of the growable word buffers:
    if (CAP <= CNT) { NEW = hook(CAP * 4 + 0x200); if (DATA != 0) { _memcpy(NEW, DATA, CNT << 2); free(DATA) } CAP = CAP + 0x80; DATA = NEW; }
    *(T *)(CNT * 4 + DATA) = word; CNT = CNT + 1;
CNT/CAP/DATA that are still placeholders (single simple declaration) become wordCount / wordCapacity / wordData (suffix 2, 3 ... per further triple)."""
import sys, re, glob, collections
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
PH = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+)$')
rows = []
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    L = open(pf, errors='replace').read().split('\n')
    spans = [(i, m.group(1)) for i, l in enumerate(L) for m in [H.match(l)] if m] + [(len(L), None)]
    for (a, fn), (b, _) in zip(spans, spans[1:]):
        body = L[a:b]; txt = '\n'.join(body); idents = set(re.findall(r'[A-Za-z_]\w*', txt))
        seen = {}
        for m in re.finditer(r'if \((\w+) <= (\w+)\) \{\s*\n\s*\w+ = \(\*\*\(code \*\*\)\(\w+ \+ 0xc\)\)\(\1 \* 4 \+ 0x200\);\s*\n\s*if \((\w+) != 0\) \{\s*\n\s*_memcpy\(\w+,\3,\2 << 2\);', txt):
            cap, cnt, data = m.group(1), m.group(2), m.group(3)
            if all(PH.match(v) for v in (cap, cnt, data)): seen[(cap, cnt, data)] = 1
        k = 0
        for (cap, cnt, data) in seen:
            if len({cap, cnt, data}) < 3: continue
            if any(sum(1 for x in body[:250] if re.match(r'^\s*[\w ]+[\s\*]+%s(\[\d+\])?;$' % v, x)) != 1 for v in (cap, cnt, data)): continue
            k += 1; sfx = '' if k == 1 else str(k)
            for v, nm, ev in ((cnt, 'wordCount' + sfx, 'number of words appended so far'), (cap, 'wordCapacity' + sfx, 'allocated capacity in words (grows by 0x80)'), (data, 'wordData' + sfx, 'pointer to the word array (reallocated through the context hooks at +0xc / +0x18)')):
                if nm in idents: continue
                rows.append('local\t%s\t%s\t%s\tINFERRED\tgrowable word buffer idiom (count/capacity/data): %s' % (fn, v, nm, ev)); idents.add(nm)
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(len(rows), file=sys.stderr)
