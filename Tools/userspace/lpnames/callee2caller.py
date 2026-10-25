#!/usr/bin/env python3
"""callee2caller.py DIR OUT.tsv PARTLO PARTHI : name placeholder parameters of the functions in parts LO..HI from the real parameter names of the callees they are
forwarded to unchanged (`G(..., param_k, ...)`).  Unanimous votes only (>= 1); the mirror of caller2callee.py (which votes from the call sites)."""
import sys, re, glob, collections
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
PHN = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_\w+|fparam_\d+|extraout_\w+|unaff_\w+|\w*Stack_[0-9a-f]+|FUN_[0-9a-f]+|iVarS\w*)$')
POSN = re.compile(r'(?:Word|Ptr|Float|Byte|Short)(?:Neg)?[0-9a-f]+(?:_\d+)?$')
sig = {}; body = collections.OrderedDict(); inrange = set()
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1)); L = open(pf, errors='replace').read().split('\n'); cur = None
    for i, l in enumerate(L):
        m = H.match(l)
        if m:
            cur = m.group(1); body[cur] = []
            mm = re.match(r'^[\w \*]*?(\w+)\((.*)\)\s*$', L[i + 1])
            ps = [p.strip() for p in mm.group(2).split(',')] if mm and mm.group(2).strip() else []
            sig[cur] = [re.split(r'[\s\*]+', p)[-1] for p in ps]
            if lo <= pn <= hi: inrange.add(cur)
        elif cur: body[cur].append(l)
def split_args(s):
    o = []; dd = 0; c = ''
    for ch in s:
        if ch in '([': dd += 1
        if ch in ')]': dd -= 1
        if ch == ',' and dd == 0: o.append(c.strip()); c = ''
        else: c += ch
    o.append(c.strip()); return o
call = re.compile(r'\b(' + '|'.join(map(re.escape, sig)) + r')\)?\(')
rows = []; stat = collections.Counter()
for fn in inrange:
    ps = sig[fn]
    want = [p for p in ps if re.match(r'^param_\d+$', p)]
    if not want: continue
    txt = '\n'.join(body[fn]); idents = set(re.findall(r'[A-Za-z_]\w*', txt)) | set(ps)
    votes = collections.defaultdict(list)
    flat = ' '.join(body[fn])
    for m in call.finditer(flat):
        g = m.group(1); j = m.end(); dd = 1; k = j
        while k < len(flat) and dd:
            if flat[k] == '(': dd += 1
            elif flat[k] == ')': dd -= 1
            k += 1
        for pos, a in enumerate(split_args(flat[j:k - 1])):
            a2 = re.sub(r'^\((?:[\w \*]+)\)', '', a).strip()
            if a2 in want and pos < len(sig[g]):
                nm = sig[g][pos]
                if nm and not PHN.match(nm):
                    nm = re.sub(r'(?<=[0-9a-f])_\d+$', '', nm) if POSN.search(nm) else nm
                    votes[a2].append((nm, g))
    used = collections.Counter()
    for p in want:
        v = votes.get(p)
        if not v: continue
        c = collections.Counter(n for n, _ in v)
        if len(c) > 1: stat['disagree'] += 1; continue
        base = v[0][0]; nm2 = base
        while nm2 in idents: used[base] += 1; nm2 = '%s%d' % (base, used[base] + 1)
        idents.add(nm2)
        rows.append('local\t%s\t%s\t%s\tINFERRED\tforwarded unchanged to parameter `%s` of %s (%d call(s), unanimous)' % (fn, p, nm2, base, v[0][1], len(v)))
        stat['named'] += 1
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(dict(stat), len(inrange), file=sys.stderr)
