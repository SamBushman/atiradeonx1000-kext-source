#!/usr/bin/env python3
"""gspec.py DIR SPEC OUT : compact naming spec -> table rows (appended to OUT).
Lines ('|' separated, '#' comments):
  L|FN|old|new|evidence[|TIER]          whole-function `local` row (skipped with a warning when FN has no `old`)
  W|FN|old|webs|new|evidence[|TIER]     per-web row(s) through emit_webs (webs = comma list of find_webs/lw2 web numbers)
  F|OLDNAME|NEW|evidence[|TIER]         `func` row
  P|FN|new1,new2,...|evidence           names for param_1..param_n of FN (skip with '-')
TIER defaults to INFERRED."""
import sys, os, re, glob, subprocess, tempfile
d, spec, out = sys.argv[1:4]
S = os.path.dirname(os.path.abspath(__file__))
funcs = {}
H = re.compile(r'^/\* (\S+) @ 0x[0-9a-f]+')
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    cur = None
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m: cur = m.group(1); funcs[cur] = []
        elif cur: funcs[cur].append(l)
rows = []; webs = {}
for line in open(spec):
    line = line.rstrip('\n')
    if not line.strip() or line.startswith('#'): continue
    c = [x.strip() for x in line.split('|')]
    k = c[0]
    if k == 'L':
        fn, old, new, ev = c[1:5]; tier = c[5] if len(c) > 5 else 'INFERRED'
        if fn not in funcs: print('# unknown function', fn, file=sys.stderr); continue
        if not re.search(r'\b%s\b' % re.escape(old), ''.join(funcs[fn])): print('# %s has no %s' % (fn, old), file=sys.stderr); continue
        rows.append('local\t%s\t%s\t%s\t%s\t%s' % (fn, old, new, tier, ev))
    elif k == 'P':
        fn, names, ev = c[1:4]
        if fn not in funcs: print('# unknown function', fn, file=sys.stderr); continue
        for i, n in enumerate(names.split(','), 1):
            n = n.strip()
            if n == '-' or not n: continue
            old = 'param_%d' % i
            if not re.search(r'\b%s\b' % old, ''.join(funcs[fn])): print('# %s has no %s' % (fn, old), file=sys.stderr); continue
            rows.append('local\t%s\t%s\t%s\tINFERRED\t%s' % (fn, old, n, ev))
    elif k == 'F':
        old, new, ev = c[1:4]; tier = c[4] if len(c) > 4 else 'INFERRED'
        rows.append('func\t%s\t%s\t%s\t%s' % (old, new, tier, ev))
    elif k == 'W':
        fn, old, ws, new, ev = c[1:6]; tier = c[6] if len(c) > 6 else 'INFERRED'
        webs.setdefault(fn, []).append('%s\t%s\t%s\t%s\t%s' % (old, ws, new, tier, ev))
    else: print('# bad line', line[:60], file=sys.stderr)
for fn, ss in webs.items():
    tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(ss) + '\n'); tf.close()
    r = subprocess.run([sys.executable, '-I', os.path.join(S, '..', 'emit_webs.py'), d, fn, tf.name], capture_output=True, text=True)
    if r.returncode: print('EMIT FAILED', fn, r.stderr[-300:], file=sys.stderr); continue
    rows.append(r.stdout.rstrip('\n'))
open(out, 'a').write('\n'.join(rows) + '\n')
