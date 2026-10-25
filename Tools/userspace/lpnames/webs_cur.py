#!/usr/bin/env python3
"""webs_cur.py DIR FN [VAR ...] : the webs of FN's placeholder variables that still carry the placeholder in the CURRENT text, with web numbers
(= emit_webs.py / specs.py numbering), the PART-FILE line range and the current text of the first definitions and (when the web has no definition) of the first use."""
import sys, re, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, fn = sys.argv[1:3]; want = sys.argv[3:]
body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
cur = F.CURRENT
import glob
first = 0
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    for i, l in enumerate(open(pf, errors='replace').read().split('\n')):
        m = re.match(r'^/\* (\S+) @ 0x', l)
        if m and m.group(1) == fn: first = i + 1
    if first: break
P = re.compile(r'\b([A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_[a-z]+\d*|extraout_\w+|\w*Stack_[0-9a-f]+|fparam_\w+|in_stack_\w+)\b')
names = want or sorted({m for l in cur[brace + 1:] if not re.match(r'\s*(/\*|\*|//)', l) for m in P.findall(l)})
for var in names:
    try: ws, er = F.webs(nodes, entry, var)
    except BaseException as e: print('%s: refused (%s)' % (var, str(e)[:70])); continue
    rx = re.compile(r'(?<![\w])%s(?![\w])' % re.escape(var))
    for k, ls in enumerate(ws):
        if not any(rx.search(cur[x]) for x in ls): continue
        defs = [x for x in ls if re.search(r'(?<![\w.>*])%s\s*=(?!=)' % re.escape(var), cur[x]) and rx.search(cur[x])]
        sh = defs[:2] if defs else sorted(ls)[:1]
        print('%-9s w%-2d L%d-%d n=%d | %s' % (var, k, first + min(ls), first + max(ls), len(ls), ' || '.join(cur[x].strip()[:70] for x in sh)))
