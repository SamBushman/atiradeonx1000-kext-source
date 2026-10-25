#!/usr/bin/env python3
"""artifacts.py DIR OUT.tsv PARTLO PARTHI : whole-function `local` rows for Ghidra pseudo-registers, with the project's conventions:
extraout_rN[_NN] -> rNAfterCall[N]; extraout_fN[_NN] -> fNAfterCall[N]; in_rN -> staleArgRN; in_fN -> staleArgFN; in_stack_X -> staleStackArg_X;
in_crN -> crNBits; unaff_rN -> calleeSavedRN; fparam_N (parameters) -> fpPassThroughN.  Names already used in the function get a numeric suffix."""
import sys, re, glob, collections
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
rules = [
 (re.compile(r'^extraout_([rf]\d+)(?:_(\d+))?$'), lambda m: '%sAfterCall%s' % (m.group(1), '' if m.group(2) is None else str(int(m.group(2)) + 2))),
 (re.compile(r'^in_r(\d+)$'), lambda m: 'staleArgR' + m.group(1)),
 (re.compile(r'^in_f(\d+)$'), lambda m: 'staleArgF' + m.group(1)),
 (re.compile(r'^in_stack_([0-9a-f]+)$'), lambda m: 'staleStackArg_' + m.group(1)),
 (re.compile(r'^in_cr(\d)$'), lambda m: 'cr%sBits' % m.group(1)),
 (re.compile(r'^unaff_r(\d+)$'), lambda m: 'calleeSavedR' + m.group(1)),
 (re.compile(r'^fparam_(\d+)$'), lambda m: 'fpPassThrough' + m.group(1)),
]
EV = 'Ghidra pseudo-register: %s (a register the function reads without having written it, or the value a call left behind; no source-level role)'
rows = []
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    L = open(pf, errors='replace').read().split('\n'); i = 0
    spans = [(i, m.group(1)) for i, l in enumerate(L) for m in [H.match(l)] if m] + [(len(L), None)]
    for (a, fn), (b, _) in zip(spans, spans[1:]):
        txt = '\n'.join(L[a:b]); idents = set(re.findall(r'[A-Za-z_]\w*', txt)); used = collections.Counter()
        for v in sorted(set(re.findall(r'\b(?:extraout_\w+|in_\w+|unaff_\w+|fparam_\d+)\b', txt)), key=lambda s: (len(s), s)):
            for rx, f in rules:
                m = rx.match(v)
                if m:
                    nm = f(m); base = nm
                    while nm in idents: used[base] += 1; nm = '%s%d' % (base, used[base] + 1)
                    idents.add(nm); rows.append('local\t%s\t%s\t%s\tINFERRED\t%s' % (fn, v, nm, EV % v)); break
open(out, 'a').write('\n'.join(rows) + '\n')
print(len(rows), file=sys.stderr)
