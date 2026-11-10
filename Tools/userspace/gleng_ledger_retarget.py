#!/usr/bin/env python3
"""gleng_ledger_retarget.py LEDGER.tsv REBUILT.nm > OUT.tsv - rewrite the rebuilt-address column (column 4) of an fnfuzz/ctxfuzz ledger for another rebuilt image.
A ledger row is `id<TAB>C name<TAB>stock addr<TAB>rebuilt addr<TAB>size<TAB>params<TAB>ret[<TAB>...]`; the rebuilt address is the function's address in the image the ledger was
made for (nm), so a ledger is valid for ONE image only (a row pointing at the wrong function makes the harness compare unrelated code). Retargeting looks every name up in the nm of the new
image (the `#anchor` row too: its rebuilt column is the address of the anchor function, the harness derives the image's load bias from it). A name missing from the nm is reported on stderr
and its row dropped."""
import sys
led, nmf = sys.argv[1:3]
nm = {}
for l in open(nmf):
    p = l.split()
    if len(p) == 3 and p[1] in 'tT': nm.setdefault(p[2], p[0].lstrip('0') or '0')
miss = 0
for l in open(led):
    p = l.rstrip('\n').split('\t')
    if l.startswith('#anchor'):
        n = p[1]
    elif len(p) >= 4 and not l.startswith('#'):
        n = p[1]
    else:
        print(l, end=''); continue
    if n not in nm: sys.stderr.write('retarget: %s not in nm, row dropped\n' % n); miss += 1; continue
    p[3] = nm[n]; print('\t'.join(p))
sys.stderr.write('retargeted %s (%d dropped)\n' % (led, miss))
