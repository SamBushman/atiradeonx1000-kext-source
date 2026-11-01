#!/usr/bin/env python3
"""split_apply.py DIR DECISIONS.json [--only FN] - turn a reviewed hybrid variable of a userspace corpus into one name per def-use web (or one better name), in the
part file AND the names tables, without the 2-3 minute full apply_names run.

DECISIONS.json: [{"fn": current function name, "old": Ghidra variable (e.g. "uVar4"), "webs": {"0": "name", "1": "name", ...}, "tier": "INFERRED", "ev": {"name": "evidence"}}
                 | {"fn": ..., "old": ..., "rename": "newname", "ev": "..."}]
Several web numbers may share one name ("1": "x", "2": "x" = one variable). Per decision it
  1. asks find_webs.py (--emit) for the `use` rows of the webs (web numbers as `find_webs.py DIR FN VAR` prints them),
  2. split_trial.py rewrites the function (the variable's committed rows are taken back first),
  3. deletes the variable's committed local/use rows from the tables and appends the new rows to names_r16_splits.tsv, writes the part file.
`apply_names.py --check DIR` must then say 0 pending / 0 errors, and the compile gate decides (fastgate.py / gate.sh)."""
import sys, os, json, re, subprocess, glob, tempfile
H = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, H)
import apply_names as A


def main():
    d, dec = sys.argv[1], json.load(open(sys.argv[2]))
    only = sys.argv[sys.argv.index('--only') + 1] if '--only' in sys.argv else None
    funcs = A.load_funcs(d); roots = A.func_roots(funcs)
    out_tbl = os.path.join(d, 'names_r16_splits.tsv')
    for x in dec:
        fn, old = x['fn'], x['old']
        if only and fn != only: continue
        root = roots.get(fn, fn)
        rows = A.load_rows(d)
        cur = sorted({r[4] for r in rows if roots.get(r[2], r[2]) == root and r[3] == old})
        tmp = tempfile.mkdtemp(prefix='sa_', dir=os.environ.get('TMPDIR', '/tmp'))
        if 'rename' in x:
            if len(cur) > 1: sys.exit('%s %s: rename needs at most one committed name, found %s' % (fn, old, cur))
            if not cur: cur = [old]; newrow = True
            else: newrow = False
            spec_rows = None
        else:
            spec = open(tmp + '/spec.tsv', 'w')
            for w, nm in sorted(x['webs'].items(), key=lambda kv: int(kv[0])):
                spec.write('%s\t%s\t%s\t%s\t%s\n' % (old, w, nm, x.get('tier', 'INFERRED'), x['ev'][nm]))
            spec.close()
            r = subprocess.run([sys.executable, os.path.join(H, 'find_webs.py'), d, fn, '--emit', tmp + '/spec.tsv'], capture_output=True, text=True)
            if r.returncode: sys.exit('find_webs failed for %s %s: %s' % (fn, old, r.stderr[-400:]))
            open(tmp + '/rows.tsv', 'w').write(r.stdout)
        # 1) the function text
        if 'rename' in x:
            nm = x['rename']; part = None
            for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
                text = open(pf).read()
                lines, fns = A.split_functions(text)
                for name, s, e in fns:
                    if name == fn:
                        body = '\n'.join(lines[s:e])
                        if re.search(r'\b%s\b' % re.escape(nm), body): sys.exit('%s: %s already used' % (fn, nm))
                        body = re.sub(r'\b%s\b' % re.escape(cur[0]), nm, body)
                        lines[s:e] = body.split('\n'); open(pf, 'w').write('\n'.join(lines)); part = pf
                if part: break
        else:
            args = [sys.executable, os.path.join(H, 'split_trial.py'), d, fn, tmp + '/rows.tsv', tmp] + ['%s=%s' % (old, c) for c in cur]
            r = subprocess.run(args, capture_output=True, text=True, env=dict(os.environ, USE_DECL='beside'))
            m = re.search(r'PART (\S+)', r.stdout)
            if not m: sys.exit('split_trial failed for %s %s:\n%s%s' % (fn, old, r.stdout[-600:], r.stderr[-600:]))
            part = os.path.join(d, m.group(1))
            open(part, 'w').write(open(os.path.join(tmp, m.group(1))).read())
        # 2) the tables
        for t in sorted(glob.glob(os.path.join(d, 'names_*.tsv'))):
            ls = open(t, errors='surrogateescape').read().split('\n'); keep = []; ch = False
            for l in ls:
                c = l.split('\t')
                if len(c) >= 6 and c[0] in ('local', 'use') and roots.get(c[1], c[1]) == root and c[2] == old:
                    if 'rename' in x and c[0] == 'local': c[3] = x['rename']; l = '\t'.join(c[:5] + [x['ev']] + c[6:]) if len(c) > 5 else '\t'.join(c); keep.append(l); ch = True; continue
                    ch = True; continue
                keep.append(l)
            if ch: open(t, 'w', errors='surrogateescape').write('\n'.join(keep))
        if 'rename' not in x:
            with open(out_tbl, 'a') as f: f.write(open(tmp + '/rows.tsv').read())
        elif newrow:
            with open(out_tbl, 'a') as f: f.write('local\t%s\t%s\t%s\t%s\t%s\n' % (fn, old, x['rename'], x.get('tier', 'INFERRED'), x['ev']))
        print('applied', fn, old, '->', x.get('rename') or sorted(set(x['webs'].values())), '(was %s) in %s' % (cur, os.path.basename(part)))


main()
