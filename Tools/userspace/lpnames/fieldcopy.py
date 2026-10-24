#!/usr/bin/env python3
"""fieldcopy.py DIR FN [VAR...] [--base NAME] [--min N] : webs whose every definition is a load of a known GLDContext field,
`VAR = *(T *)(BASE + 0xOFF);` (BASE default param_1 / ctx / glContext), are named after the field (fields_gld.tsv).
Prints `VAR<TAB>webs<TAB>fieldname<TAB>INFERRED<TAB>evidence` lines (emit_webs input) on stdout, skipping names already used in FN
and a second variable asking for an already taken name (suffix 2, 3...).  A web is also skipped when it has no definition line."""
import sys, os, re
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
args = sys.argv[1:]
d, fn = args[0], args[1]
rest = args[2:]
base = r'(?:param_1|ctx|glContext)'
vars_ = []
i = 0
while i < len(rest):
    if rest[i] == '--base': base = re.escape(rest[i+1]); i += 2
    else: vars_.append(rest[i]); i += 1
FLD = {}
for l in open(os.path.join(d, 'fields_gld.tsv')):
    c = l.rstrip('\n').split('\t')
    if len(c) > 5 and c[0] == 'field' and c[1] == 'GLD': FLD[int(c[2], 16)] = (c[3], c[4])
body, brace = F.load(d, fn)
nodes, entry = F.build_cfg(body, brace)
text = '\n'.join(body)
if not vars_:
    vars_ = sorted(set(re.findall(r'\b(?:[a-z]{1,3}Var\d+)\b', text)), key=lambda v: int(re.sub(r'\D', '', v)))
DEFRX = lambda v: re.compile(r'(?<![\w.>])%s\s*=(?!=)\s*(.*)' % re.escape(v))
LOAD = re.compile(r'^\(?\*\(\s*[\w ]+\s*\*+\s*\)\(\s*(?:' + base + r'\s*\+\s*(0x[0-9a-f]+)|(0x[0-9a-f]+)\s*\+\s*' + base + r')\s*\)\)?;?$')
LOAD2 = re.compile(r'^\*\(\s*[\w ]+\s*\*+\s*\)\(\s*(?:' + base + r'\s*\+\s*(0x[0-9a-f]+)|(0x[0-9a-f]+)\s*\+\s*' + base + r')\s*\);')
used = set(re.findall(r'\b[A-Za-z_]\w*\b', text))
out = []
for v in vars_:
    ws, er = F.webs(nodes, entry, v)
    byname = {}
    for k, ls in enumerate(ws):
        defs = []
        for x in ls:
            for m in DEFRX(v).finditer(body[x]): defs.append(m.group(1).strip())
        if not defs: continue
        names = set()
        for t in defs:
            m = LOAD2.match(t) or LOAD.match(t)
            if not m: names = None; break
            off = int(m.group(1) or m.group(2), 16)
            if off not in FLD: names = None; break
            names.add(FLD[off][0])
        if not names or len(names) != 1: continue
        byname.setdefault(names.pop(), []).append(k)
    for nm, wl in byname.items():
        new = nm; n = 2
        while new in used: new = '%s%d' % (nm, n); n += 1
        used.add(new)
        out.append('%s\t%s\t%s\tINFERRED\tcopy of GLDContext field %s read from the context (fields_gld.tsv)' % (v, ','.join(map(str, wl)), new, nm))
print('\n'.join(out))
