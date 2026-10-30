#!/usr/bin/env python3
"""q07_gen.py DIR RULES.py OUT FN... : per function, name every web the rule module classifies (autoweb logic), make names unique against the identifiers already in the function (suffix 2,3,..) and append `@FN` spec blocks to OUT for specs.py."""
import sys, os, re, glob, importlib.util
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import find_webs as F
PH = re.compile(r'\b(?:[a-z]{0,3}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|[a-z]?Stack_[0-9a-f]+|param_\d+|fparam_\d+|in_stack_\w+|in_[a-z]+\d+)\b')
CASE = re.compile(r'^\s*case (0x[0-9a-f]+|\d+):')
class Ctx:
    def __init__(self, body):
        self.body = body; self.cases = []
        for i, l in enumerate(body):
            m = CASE.match(l)
            if m: self.cases.append((i, int(m.group(1), 0)))
    def case_of(self, line):
        c = None
        for i, n in self.cases:
            if i <= line: c = n
            else: break
        return c
class A: pass
A.PH = PH; A.Ctx = Ctx
d, rules, out = sys.argv[1:4]; fns = sys.argv[4:]
spec = importlib.util.spec_from_file_location('rules', rules); R = importlib.util.module_from_spec(spec); spec.loader.exec_module(R)
H = re.compile(r'^/\* (\S+) @ 0x')
text = {}
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    cur = None; buf = []
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m:
            if cur in fns: text[cur] = ''.join(buf)
            cur = m.group(1); buf = []; continue
        buf.append(l)
    if cur in fns: text[cur] = ''.join(buf)
FUNCMAP = {}
for t in glob.glob(os.path.join(d, 'names*.tsv')):
    for l in open(t, errors='surrogateescape'):
        c = l.rstrip('\n').split('\t')
        if len(c) > 3 and c[0] == 'func': FUNCMAP[c[1]] = c[2]
R.FUNCMAP = FUNCMAP
blocks = []
for fn in fns:
    try:
        body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except SystemExit as e:
        print('skip', fn, e); continue
    ctx = A.Ctx(body)
    idents = set(re.findall(r'[A-Za-z_]\w*', text.get(fn, '')))
    vars_ = sorted({m.group(0) for l in body[brace:] for m in A.PH.finditer(l)})
    rows = []
    for var in vars_:
        try: ws, er = F.webs(nodes, entry, var)
        except SystemExit: continue
        DEF = re.compile(r'(?<![\w.>])%s\s*=(?!=)\s*(.*)' % re.escape(var))
        by = {}
        for k, ls in enumerate(ws):
            defs = [m.group(1) for x in ls for m in DEF.finditer(body[x])]
            nm = R.name(var, k, defs, sorted(ls), ctx)
            if nm: by.setdefault(nm, []).append(k)
        for nm, ks in by.items(): rows.append((var, ks, nm))
    used = set(); res = []
    for var, ks, nm in rows:
        base = nm; j = 1
        while nm in idents or nm in used:
            j += 1; nm = base + (chr(ord('A') + j - 1) if base.startswith('savedField') else str(j))
        used.add(nm); res.append('%s\t%s\t%s\tINFERRED\t%s' % (var, ','.join(map(str, ks)), nm, R.EVIDENCE))
    if res: blocks.append('@FN %s\n%s\n' % (fn, '\n'.join(res)))
    print(fn, len(res))
with open(out, 'a') as f: f.write(''.join(blocks))
