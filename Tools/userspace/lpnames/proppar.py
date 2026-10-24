#!/usr/bin/env python3
"""proppar.py DIR PARTLO PARTHI OUT.spec [--min-votes N] : name still-unnamed parameters (param_k) of the functions in parts LO..HI after the parameter of a
callee they are passed on unchanged (`G(..., param_k, ...)` where G's own parameter at that position has a real name). All calls of one function to named callees
must agree on the name; a name that already exists in the function (or is a generic placeholder such as unusedArgN) is skipped. Emits gspec L rows."""
import sys, os, re, glob, collections
d, lo, hi, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
minv = int(sys.argv[sys.argv.index('--min-votes') + 1]) if '--min-votes' in sys.argv else 1
H = re.compile(r'^/\* (\S+) @ 0x[0-9a-f]+')
PLACEHOLDER = re.compile(r'^(param_\d+|[a-z]{0,3}Var\d+|local_[0-9a-f]+|in_\w+|unusedArg\d+|unused|forwardedArg\d+|a\d(_\d+)?|this_\d+|extraout_\w+)$')
sig = {}; body = {}; order = []; part = {}
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    p = int(re.search(r'part_(\d+)', pf).group(1))
    cur = None; lines = open(pf, errors='replace').read().split('\n')
    for i, l in enumerate(lines):
        m = H.match(l)
        if m:
            cur = m.group(1); body[cur] = []; part[cur] = p
            hdr = lines[i + 1]
            hm = re.match(r'\S[^(]*\b\w+\(([^)]*)\)', hdr)
            names = [x.strip() for x in hm.group(1).split(',')] if hm and hm.group(1).strip() else []
            # K&R style: declarations on the following lines give the names; ANSI style 'type name' in the header
            pn = []
            for x in names:
                pn.append(re.split(r'[\s*]+', x.strip())[-1] if ' ' in x or '*' in x else x)
            sig[cur] = pn; order.append(cur); continue
        if cur: body[cur].append(l)
CALL = re.compile(r'(?:\(\(int \(\*\)\(\)\)(\w+)\)|\b(\w+))\(([^;{}]*)\)')
rows = []
for fn in order:
    if not (lo <= part[fn] <= hi): continue
    ps = sig[fn]
    if not any(re.match(r'param_\d+$', x) for x in ps): continue
    t = '\n'.join(body[fn])
    vote = {x: collections.Counter() for x in ps if re.match(r'param_\d+$', x)}
    for m in CALL.finditer(t):
        g = m.group(1) or m.group(2)
        if g not in sig or g == fn: continue
        args = [a.strip() for a in re.split(r',(?![^()]*\))', m.group(3))]
        for k, a in enumerate(args):
            a2 = re.sub(r'^\(\w[\w ]*\*?\)\s*', '', a)
            if a2 in vote and k < len(sig[g]):
                nm = sig[g][k]
                if not PLACEHOLDER.match(nm) and nm != 'void': vote[a2][nm] += 1
    used = set(re.findall(r'\b\w+\b', t)) | set(ps)
    for x, c in vote.items():
        if len(c) != 1: continue
        nm, n = next(iter(c.items()))
        if n < minv or nm in used: continue
        rows.append('L|%s|%s|%s|passed unchanged to the %s parameter of a callee (callee signature)' % (fn, x, nm, nm))
        used.add(nm)
open(out, 'w').write('\n'.join(rows) + '\n'); print(len(rows), 'rows')
