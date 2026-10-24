#!/usr/bin/env python3
"""mkrows.py DIR SPEC > names_X.tsv : turn a '|'-separated spec into whole-function `local` rows.
SPEC line:  FN-or-glob | old | new | evidence [| TIER]     (TIER defaults to INFERRED; '#' lines and blanks skipped)
FN may be a shell glob (fnmatch) over the function names of DIR/part_*.c; a row is emitted for every matching function that still contains `old`
(a function without `old` is skipped silently only when FN is a glob)."""
import sys, os, re, glob, fnmatch
d, spec = sys.argv[1:3]
funcs = {}
H = re.compile(r'^/\* (\S+) @ 0x[0-9a-f]+')
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    cur = None
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m: cur = m.group(1); funcs[cur] = []
        elif cur: funcs[cur].append(l)
for line in open(spec):
    line = line.rstrip('\n')
    if not line.strip() or line.startswith('#'): continue
    c = [x.strip() for x in line.split('|')]
    fn, old, new, ev = c[:4]; tier = c[4] if len(c) > 4 else 'INFERRED'
    glob_ = any(ch in fn for ch in '*?[')
    names = [f for f in funcs if fnmatch.fnmatchcase(f, fn)] if glob_ else [fn]
    n = 0
    for f in names:
        if f not in funcs: print('# unknown function', f, file=sys.stderr); continue
        if not re.search(r'\b%s\b' % re.escape(old), ''.join(funcs[f])):
            if not glob_: print('# %s has no %s' % (f, old), file=sys.stderr)
            continue
        print('local\t%s\t%s\t%s\t%s\t%s' % (f, old, new, tier, ev)); n += 1
    if not n: print('# no match:', line[:80], file=sys.stderr)
