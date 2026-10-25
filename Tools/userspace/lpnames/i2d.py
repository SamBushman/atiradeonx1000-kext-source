#!/usr/bin/env python3
"""i2d.py DIR OUT.tsv PARTLO PARTHI : whole-function rows for the compiler's int->float scratch pairs ({0x43300000, x ^ 0x80000000} = double 2^52+x) and
float->int (fctiwz) stack slots:  local_H = 0x43300000 / uStack_L (L = H-4) -> i2dHiK / i2dLoK;  local_X = (longlong)... -> fctiwzSlotK."""
import sys, re, glob, collections
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
EV1 = 'int-to-float scratch: the word pair {0x43300000, x^0x80000000} is the double 2^52+x that the compiler builds on the stack to convert an int (the CONCAT44 with 4503601774854144.0 subtracts the bias)'
EV2 = '(longlong) store of a float->int conversion (fctiwz) kept in a stack pair by the compiler'
rows = []
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    L = open(pf, errors='replace').read().split('\n')
    spans = [(i, m.group(1)) for i, l in enumerate(L) for m in [H.match(l)] if m] + [(len(L), None)]
    for (a, fn), (b, _) in zip(spans, spans[1:]):
        body = L[a:b]; txt = '\n'.join(body); idents = set(re.findall(r'[A-Za-z_]\w*', txt))
        k = 0; f = 0
        decl = lambda v: any(re.match(r'^\s*[\w ]+[\s\*]+%s;$' % v, x) for x in body[:200])
        for x in body:
            m = re.match(r'^\s*(local_([0-9a-f]+)) = 0x43300000;$', x)
            if m:
                hv = m.group(1); lv = 'uStack_%x' % (int(m.group(2), 16) - 4)
                if not (decl(hv) and decl(lv)): continue
                k += 1; n1, n2 = 'i2dHi%d' % k, 'i2dLo%d' % k
                if n1 in idents or n2 in idents: continue
                rows.append('local\t%s\t%s\t%s\tCONFIRMED\t%s' % (fn, hv, n1, EV1)); rows.append('local\t%s\t%s\t%s\tCONFIRMED\t%s' % (fn, lv, n2, EV1))
                idents |= {n1, n2}
                continue
            m = re.match(r'^\s*(local_[0-9a-f]+) = \(longlong\)', x)
            if m and decl(m.group(1)):
                f += 1; n = 'fctiwzSlot%d' % (f - 1)
                if n in idents: continue
                rows.append('local\t%s\t%s\t%s\tCONFIRMED\t%s' % (fn, m.group(1), n, EV2)); idents.add(n)
open(out, 'a').write('\n'.join(rows) + '\n')
print(len(rows), file=sys.stderr)
