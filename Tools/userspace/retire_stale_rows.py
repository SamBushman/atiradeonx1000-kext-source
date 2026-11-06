#!/usr/bin/env python3
"""retire_stale_rows.py DIR REWRITTEN_LIST OUT_NOTES [--max N] : after a corpus rewrite (e.g. atomic_add_fix.py), remove the names_*.tsv rows
that `apply_names.py --check DIR` reports as stale (anchor not found / variable no longer present), but ONLY rows whose function is one of the
rewritten functions (REWRITTEN_LIST: one corpus function name per line; the row's function may also be its old FUN_<addr> name, matched by the
address in the part header). Any error for another function aborts untouched (something else broke). Every removed row is appended to OUT_NOTES
(use a file name starting with `notes`, apply_names scans other .tsv/.txt files for old names). Repeats until --check is clean."""
import re, sys, subprocess, glob, os, collections

def main():
    d, lst, out = sys.argv[1:4]
    mx = int(sys.argv[sys.argv.index('--max') + 1]) if '--max' in sys.argv else 8
    here = os.path.dirname(os.path.abspath(__file__))
    ALL = lst == '--all'      # retire every stale local/use row of the corpus (not only the rewritten functions'): `retire_stale_rows.py DIR --all OUT_NOTES`; data/func/target rows are never touched
    names = set() if ALL else set(x.strip() for x in open(lst) if x.strip())
    addr = set()
    hdr = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \(')
    for f in glob.glob(d + '/part_*.c') + glob.glob(d + '/unowned_code/part_*.c') + glob.glob(d + '/landing_pads/*.c'):
        for l in open(f):
            m = hdr.match(l)
            if m and m.group(1) in names:
                addr.add(int(m.group(2), 16))
    def allowed(fn):
        if ALL: return True
        if fn in names: return True
        m = re.match(r'^_?FUN_([0-9a-f]+)$', fn)
        return bool(m and int(m.group(1), 16) in addr)
    o = open(out, 'a')
    total = 0
    for it in range(mx):
        r = subprocess.run([sys.executable, os.path.join(here, 'apply_names.py'), '--check', d], capture_output=True, text=True)
        errs = [l for l in r.stdout.split('\n') + r.stderr.split('\n') if re.match(r'^\./?[^:\s]+\.tsv:\d+: ', l)]
        print('pass %d: %d errors; %s' % (it + 1, len(errs), (r.stdout.strip().split('\n') or [''])[-1]), flush=True)
        if not errs:
            break
        rows = collections.defaultdict(set)
        bad = []; kept = []
        for l in errs:
            m = re.match(r'^\.?/?([^:\s]+\.tsv):(\d+): ([^:]+): (.*)$', l)
            if not m:
                (kept if ALL else bad).append(l); continue
            f, ln, fn, why = m.groups()
            if not allowed(fn): bad.append(l); continue
            rows[f].add(int(ln))
        if ALL and not rows:
            print('%d errors left that are not local/use rows (left alone):' % len(kept)); print('\n'.join(kept[:40])); break
        if bad:
            print('ABORT: errors outside the rewritten functions:'); print('\n'.join(bad[:20])); sys.exit(2)
        for f, lns in rows.items():
            p = os.path.join(d, f)
            L = open(p).read().split('\n')
            for ln in sorted(lns, reverse=True):
                o.write('%s:%d\t%s\n' % (f, ln, L[ln - 1]))
                del L[ln - 1]
                total += 1
            open(p, 'w').write('\n'.join(L))
        o.flush()
    print('removed rows total', total)

main()
