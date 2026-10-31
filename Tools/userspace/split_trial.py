#!/usr/bin/env python3
"""split_trial.py DIR FN ROWS.tsv OUTDIR [OLD=CURRENT ...]  (OLD=CURRENT: first take the whole-variable rename OLD->CURRENT back, i.e. un-name the variable that ROWS split)

Original doc:
split_trial.py DIR FN ROWS.tsv OUTDIR - apply `use`/`local` rows (ROWS.tsv, names-table format, e.g. find_webs.py --emit output) to ONE function of
a userspace corpus WITHOUT touching DIR: the part file that holds FN is rewritten into OUTDIR/<part>.c (the unmodified part is OUTDIR/base_<part>.c). The
rows of FN already committed in DIR/names_*.tsv are taken as the existing renames, as apply_names.py main() does, so the result equals what apply_names.py
would write for this one function (USE_DECL from the environment, default 'beside'). Fast replacement for the 2-3 minute full apply_names run.
Prints: PART <name>."""
import os, sys, glob, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import apply_names as A
os.environ.setdefault('USE_DECL', 'beside')


def main():
    args = sys.argv[1:]
    unn = [a.split('=') for a in args if '=' in a and not a.startswith('/') and not os.path.exists(a)]
    args = [a for a in args if not ('=' in a and not os.path.exists(a))]
    d, fn, rowsf, out = args[:4]
    A.FIELD_DIR = d
    old_rows = A.load_rows(d)
    new_rows = []
    for n, l in enumerate(open(rowsf), 1):
        if not l.strip() or l.startswith('#'): continue
        c = l.rstrip('\n').split('\t')
        new_rows.append((rowsf, n, c[1], c[2], c[3], c[4]) if c[0] == 'local' else (rowsf, n, c[1], c[2], c[3], c[4], c[6], c[7] if len(c) > 7 else '', c[8] if len(c) > 8 and c[8] else 'all', c[9] if len(c) > 9 and c[9] else 'none'))
    dtext = re.sub(r'/\*.*?\*/|//[^\n]*', ' ', open(os.path.join(d, 'decls.h')).read(), flags=re.S)
    decl = set(A.IDENT.findall(dtext))
    funcs = A.load_funcs(d)
    A.FUNCBACK.clear(); A.FUNCBACK.update(A.func_roots(funcs))
    root = A.FUNCBACK.get(fn, fn)
    drop = {o for o, _ in unn}
    rws = [r for r in old_rows if A.FUNCBACK.get(r[2], r[2]) == root and not (r[3] in drop)] + new_rows
    os.makedirs(out, exist_ok=True)
    for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        text = open(pf).read()
        if fn not in text: continue
        lines, fns = A.split_functions(text)
        for name, s, e in fns:
            if name != fn: continue
            body = '\n'.join(lines[s:e])
            for o, cur in unn: body = re.sub(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(cur), o, body)
            lines[s:e] = body.split('\n')
            uses = [r for r in new_rows if len(r) == 10]
            for (f, n, fnn, old, new, tier) in [r for r in new_rows if len(r) == 6]:
                body = '\n'.join(lines[s:e])
                body = re.sub(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(old), new, body)
                lines[s:e] = body.split('\n')
            if uses:
                a2, p2, e2 = A.apply_uses(lines, s, e, name, uses, rws, decl)
                print('apply_uses: %d already, %d new, %d errors' % (a2, p2, e2))
                if e2: sys.exit(2)
            b = os.path.basename(pf)
            open(os.path.join(out, b), 'w').write('\n'.join(lines))
            open(os.path.join(out, 'base_' + b), 'w').write(text)
            print('PART', b); return
    sys.exit('function %s not found' % fn)


main()
