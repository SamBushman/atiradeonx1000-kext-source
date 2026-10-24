#!/usr/bin/env python3
"""specs.py DIR SPEC OUT : multi-function spec -> rows for apply_names.py (appended to OUT).

SPEC is a text file of blocks:
    @FN <function name>
    <VAR>\t<WEBS>\t<new>\t<TIER>\t<evidence>      (exactly emit_webs.py's columns; WEBS = `*` whole function, or web numbers `1,2`, or `3<200` filters, or `L1220-1221,1228` = explicit part-file line ranges (orig.py numbering; goes through rng.py))
Blank lines and `#` lines are skipped. Rows for every block are produced by emit_webs.py (web numbers = `lw2.py DIR FN` numbering).
Any block that fails is reported with its function name and nothing from that block is written (the other blocks still are)."""
import sys, os, subprocess, tempfile
d, spec, out = sys.argv[1:4]
S = os.path.dirname(os.path.abspath(__file__))
blocks = []; cur = None
for l in open(spec):
    if l.startswith('@FN '):
        cur = [l.split()[1], []]; blocks.append(cur)
    elif cur and l.strip() and not l.startswith('#'):
        cur[1].append(l.rstrip('\n'))
bad = 0; n = 0
for fn, lines in blocks:
    res = ''; failed = False
    for kind, script, pick in (('webs', os.path.join(S, '..', 'emit_webs.py'), lambda c: not c[1].startswith('L')),
                               ('ranges', os.path.join(S, 'rng.py'), lambda c: c[1].startswith('L'))):
        sel = []
        for ln in lines:
            c = ln.split('\t')
            if pick(c):
                if kind == 'ranges': c[1] = c[1][1:]
                sel.append('\t'.join(c))
        if not sel: continue
        tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False)
        tf.write('\n'.join(sel) + '\n'); tf.close()
        r = subprocess.run([sys.executable, '-I', script, d, fn, tf.name], capture_output=True, text=True)
        os.unlink(tf.name)
        if r.returncode:
            print('FAILED', fn, kind, r.stderr.strip()[-300:]); failed = True; break
        res += r.stdout
    if failed: bad += 1; continue
    open(out, 'a').write(res); n += len(res.splitlines())
print('%d rows written to %s, %d block(s) failed' % (n, out, bad))
sys.exit(1 if bad else 0)
