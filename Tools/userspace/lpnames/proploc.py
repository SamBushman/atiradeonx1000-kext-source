#!/usr/bin/env python3
"""proploc.py DIR PARTLO PARTHI OUT.spec : name placeholder LOCALS that have exactly one def-use web after the parameter of the callee they are passed to
(`G(..., v, ...)` with G's own parameter at that position named). All uses of v as a bare argument to named callee parameters must agree.
Single-web variables only: a whole-function rename adds no declaration, so the frame layout (fake-struct adjacency) cannot change."""
import sys, os, re, glob, collections
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, lo, hi, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
H = re.compile(r'^/\* (\S+) @ 0x[0-9a-f]+')
PLACEHOLDER = re.compile(r'^(param_\d+|[a-z]{0,3}Var\d+|local_[0-9a-f]+|in_\w+|unusedArg\d+|unused|forwardedArg\d+|a\d(_\d+)?|this_\d+|extraout_\w+|index|indexValue)$')
PH = re.compile(r'\b([a-z]{0,3}Var\d+|p+[A-Z]\w*Var\d+|local_[0-9a-f]+)\b')
sig = {}; part = {}; order = []
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    p = int(re.search(r'part_(\d+)', pf).group(1)); lines = open(pf, errors='replace').read().split('\n')
    for i, l in enumerate(lines):
        m = H.match(l)
        if m:
            fn = m.group(1); part[fn] = p; order.append(fn)
            hm = re.match(r'\S[^(]*\b\w+\(([^)]*)\)', lines[i + 1])
            names = [x.strip() for x in hm.group(1).split(',')] if hm and hm.group(1).strip() else []
            sig[fn] = [re.split(r'[\s*]+', x)[-1] if (' ' in x or '*' in x) else x for x in names]
CALL = re.compile(r'(?:\(\(int \(\*\)\(\)\)(\w+)\)|\b(\w+))\(([^;{}]*)\)')
rows = []
for fn in order:
    if not (lo <= part[fn] <= hi): continue
    try: body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException: continue
    txt = '\n'.join(body[brace + 1:])
    vars_ = []
    for m in PH.finditer(txt):
        if m.group(1) not in vars_: vars_.append(m.group(1))
    used = set(re.findall(r'\b\w+\b', '\n'.join(body))) | set(sig.get(fn, []))
    cand = {}
    for m in CALL.finditer(txt):
        g = m.group(1) or m.group(2)
        if g not in sig or g == fn: continue
        args = [a.strip() for a in re.split(r',(?![^()]*\))', m.group(3))]
        for k, a in enumerate(args):
            a2 = re.sub(r'^\(\w[\w ]*\*?\)\s*', '', a)
            if re.match(r'(?:[a-z]{0,3}Var\d+|p+[A-Z]\w*Var\d+|local_[0-9a-f]+)$', a2) and k < len(sig[g]):
                nm = sig[g][k]
                if not PLACEHOLDER.match(nm) and nm != 'void': cand.setdefault(a2, collections.Counter())[nm] += 1
    for v, c in cand.items():
        if len(c) != 1 or v not in vars_: continue
        nm = next(iter(c))
        if nm in used: continue
        try: ws = F.webs(nodes, entry, v)[0]
        except BaseException: continue
        if len(ws) != 1: continue
        rows.append('L|%s|%s|%s|single web; passed to the %s parameter of a callee (callee signature)' % (fn, v, nm, nm)); used.add(nm)
open(out, 'w').write('\n'.join(rows) + '\n'); print(len(rows), 'rows')
