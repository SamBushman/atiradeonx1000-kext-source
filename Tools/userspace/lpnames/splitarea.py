#!/usr/bin/env python3
"""splitarea.py DIR FN OUT VAR=JOINED[:SUFFIX] ... : TEST split of overlay words. For each VAR (Ghidra name): revert the whole-function row of JOINED (text + row),
then write `use` rows for ALL webs that have a definition: the biggest web keeps JOINED, every other web gets JOINED-independent test name VAR_wK (K = web number).
Rows go to OUT (appended)."""
import sys, os, re, subprocess
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, fn, out = sys.argv[1:4]
S = os.path.dirname(os.path.abspath(__file__))
pairs = [a.split('=') for a in sys.argv[4:]]
import json
NAMEMAP = json.load(open(os.environ['NAMEMAP'])) if os.environ.get('NAMEMAP') else None
spec = []; star = []; SMALL = int(os.environ.get('SMALL', '3'))
for var, joined in pairs:
    r = subprocess.run([sys.executable, S + '/rn.py', d, 'revert', fn, joined], capture_output=True, text=True); print(r.stdout.strip(), r.stderr.strip()[:100])
for var, joined in pairs:
    body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    ws, _ = F.webs(nodes, entry, var)
    DEF = re.compile(r'(?<![\w.>])%s\s*=(?!=)' % re.escape(var))
    OPENV = re.compile(r'\b%s\b' % re.escape(var))
    cand = [k for k, ls in enumerate(ws) if any(DEF.search(body[x]) for x in ls) and any(OPENV.search(F.CURRENT[x]) for x in ls)]
    big = max(cand, key=lambda k: len(ws[k]))
    star.append('use\t%s\t%s\t%s\tINFERRED\tTEST split: every other web keeps the joined name\t*\t\tall\tnone' % (fn, var, joined))
    for k in cand:
        if NAMEMAP is not None:
            nm = NAMEMAP.get(var, {}).get(str(k))
            if nm: spec.append('%s\t%d\t%s\tINFERRED\t%s' % (var, k, nm[0], nm[1]))
            continue
        if k != big and len(ws[k]) <= SMALL: spec.append('%s\t%d\t%s_w%d\tINFERRED\tTEST split: separate web %d' % (var, k, var, k, k))
import tempfile
tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(spec) + '\n'); tf.close()
r = subprocess.run([sys.executable, '-I', os.path.join(S, '..', 'emit_webs.py'), d, fn, tf.name], capture_output=True, text=True)
if r.returncode: print('EMIT FAILED', r.stderr[-300:]); sys.exit(1)
open(out, 'a').write(r.stdout.rstrip('\n') + '\n' + '\n'.join(star) + '\n'); print(len(spec), 'web specs ->', len(r.stdout.strip().split('\n')), 'rows')
