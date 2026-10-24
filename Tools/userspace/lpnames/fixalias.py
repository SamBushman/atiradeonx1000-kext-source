#!/usr/bin/env python3
"""fixalias.py DIR PART_LO PART_HI OUT.tsv [--dry] : whole-function rows that name a reused variable `arena` / `allocation` although some of its
def-use webs are something else (an element reference, a fetch result, a constant ...) are split per web: the webs that really are the arena
(defined from compiler+0x374/0x378 / COMP_arena*) or an allocation (defined by the bump allocator FUN_00193e18 / Arena__alloc) get `use` rows in OUT,
the whole-function row is deleted from its table, and the other webs return to Ghidra's placeholder so they can be named for what they are."""
import sys, os, re, glob, collections, subprocess, tempfile
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, lo, hi, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
dry = '--dry' in sys.argv
H = re.compile(r'^/\* (\S+) @ 0x')
mine = set()
for p in range(lo, hi + 1):
    for l in open('%s/part_%03d.c' % (d, p), errors='replace'):
        m = H.match(l)
        if m: mine.add(m.group(1))
GOOD = {'arena': re.compile(r'COMP_arena[AB]|\+ 0x37[48]\)'), 'allocation': re.compile(r'FUN_00193e18\(|Arena__alloc\(')}
cands = []
for f in sorted(glob.glob(d + '/names*.tsv')):
    for ln, l in enumerate(open(f)):
        c = l.rstrip('\n').split('\t')
        if c[0] == 'local' and c[1] in mine and c[3] in GOOD and len(c) >= 6:
            cands.append((f, ln, c))
by = collections.defaultdict(list)
for f, ln, c in cands: by[c[1]].append((f, ln, c))
delete = collections.defaultdict(set); specs = []
for fn, rs in by.items():
    try:
        body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException as e:
        print('SKIP', fn, str(e)[:60]); continue
    for f, ln, c in rs:
        old, new = c[2], c[3]
        try: ws, er = F.webs(nodes, entry, old)
        except BaseException as e:
            print('SKIP', fn, old, str(e)[:60]); continue
        good = []; other = 0
        for k, w in enumerate(ws):
            ls = sorted(w)
            df = [l for l in ls if re.search(r'(?<![\w.>*\]])%s\s*=(?!=)' % re.escape(old), body[l])]
            txt = ' '.join(body[l].split('=', 1)[1] for l in df if '=' in body[l]) if df else ''
            if df and all(GOOD[new].search(body[l].split('=', 1)[1]) for l in df if '=' in body[l]): good.append(k)
            else: other += 1
        if not other: continue
        print('%s %s->%s: %d good webs, %d other (%s)' % (fn, old, new, len(good), other, os.path.basename(f)))
        delete[f].add(c[0:3] and tuple(c[:3]))
        if good: specs.append((fn, '%s\t%s\t%s\t%s\t%s' % (old, ','.join(map(str, good)), new, c[4], c[5])))
if dry: sys.exit(0)
for f, keys in delete.items():
    kept = []
    for l in open(f):
        c = l.rstrip('\n').split('\t')
        if c[0] == 'local' and tuple(c[:3]) in keys: continue
        kept.append(l)
    open(f, 'w').writelines(kept)
rows = []
bf = collections.defaultdict(list)
for fn, s in specs: bf[fn].append(s)
for fn, ss in bf.items():
    tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(ss) + '\n'); tf.close()
    r = subprocess.run([sys.executable, '-I', os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'emit_webs.py'), d, fn, tf.name], capture_output=True, text=True)
    if r.returncode: print('EMIT FAILED', fn, r.stderr[-200:]); continue
    rows.append(r.stdout)
open(out, 'a').write(''.join(rows))
