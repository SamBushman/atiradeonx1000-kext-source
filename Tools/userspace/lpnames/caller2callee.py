#!/usr/bin/env python3
"""caller2callee.py DIR OUT.tsv PARTLO PARTHI : name placeholder parameters of the functions in parts LO..HI from the real names of the
variables every call site passes (identifier arguments only).  A parameter gets a name when all call sites that pass an identifier at that position
agree (>= MINV votes); names already in use in the callee get a numeric suffix.  Writes `local` rows (apply_names.py)."""
import sys, re, glob, collections
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
MINV = 1
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
PH = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_\w+|fparam_\d+|extraout_\w+|unaff_\w+|\w*Stack_[0-9a-f]+|FUN_[0-9a-f]+|DAT_\w+|PTR_\w+|iVarS\w*)$')
GEN = {'this', 'i', 'j', 'k', 'n', 'x', 'p', 'v', 'a', 'b', 'tmp', 'result', 'value', 'val', 'zero', 'one'}
funcs = collections.OrderedDict(); parts = {}
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    L = open(pf, errors='replace').read().split('\n'); parts[pf] = L
    for i, l in enumerate(L):
        m = H.match(l)
        if m and lo <= pn <= hi:
            sig = L[i + 1]
            mm = re.match(r'^[\w \*]*?(\w+)\((.*)\)\s*$', sig)
            if not mm: continue
            ps = [p.strip() for p in mm.group(2).split(',')] if mm.group(2).strip() else []
            names = [re.split(r'[\s\*]+', p)[-1] for p in ps]
            funcs[m.group(1)] = (names, i)
def split_args(s):
    o = []; dd = 0; c = ''
    for ch in s:
        if ch in '([': dd += 1
        if ch in ')]': dd -= 1
        if ch == ',' and dd == 0: o.append(c.strip()); c = ''
        else: c += ch
    o.append(c.strip()); return o
votes = collections.defaultdict(lambda: collections.defaultdict(list))
callre = re.compile(r'\b(' + '|'.join(map(re.escape, funcs)) + r')\)?\(')
for pf, L in parts.items():
    cur = None
    for i, l in enumerate(L):
        m = H.match(l)
        if m: cur = m.group(1); continue
        if re.match(r'^\s*(?:/\*|\*|//)', l): continue
        # join continuation lines of a call
        for m in callre.finditer(l):
            fn = m.group(1)
            txt = l[m.end():]; j = i
            depth = 1; buf = ''
            k = 0
            while True:
                for ch in txt:
                    if ch == '(': depth += 1
                    elif ch == ')':
                        depth -= 1
                        if depth == 0: break
                    buf += ch
                if depth == 0 or j + 1 >= len(L) or j - i > 6: break
                j += 1; txt = L[j]; buf += ' '
            if depth: continue
            if re.match(r'^\s*(?:[\w \*]+\s+)?%s\s*\(' % fn, l) and not l.startswith(' '): continue   # definition line
            args = split_args(buf)
            for pos, a in enumerate(args):
                a2 = re.sub(r'^\((?:[\w \*]+)\)', '', a).strip()
                a2 = re.sub(r'(?<=[0-9a-f])_\d+$', '', a2) if re.search(r'(?:Word|Ptr|Float|Byte|Short)(?:Neg)?[0-9a-f]+_\d+$', a2) else a2   # uniqueness suffix of a positional name is the caller's business
                if re.match(r'^[A-Za-z_]\w*$', a2) and not PH.match(a2) and a2 not in GEN:
                    votes[fn][pos].append((a2, cur))
rows = []; stat = collections.Counter()
for fn, (names, ln) in funcs.items():
    body = '\n'.join(parts[[p for p in parts if int(re.search(r'part_(\d+)', p).group(1)) <= hi][0]][0:0])
idents_cache = {}
def fn_idents(fn):
    pass
# gather identifiers per function (text between header and next header)
text = {}
for pf, L in parts.items():
    cur = None; buf = []
    for l in L:
        m = H.match(l)
        if m:
            if cur: text[cur] = ' '.join(buf)
            cur = m.group(1); buf = []
        else: buf.append(l)
    if cur: text[cur] = ' '.join(buf)
for fn, (names, ln) in funcs.items():
    idents = set(re.findall(r'[A-Za-z_]\w*', text.get(fn, ''))); used = collections.Counter()
    for pos, nm in enumerate(names):
        if not PH.match(nm) or not re.match(r'^(?:param_\d+)$', nm): continue
        vs = votes[fn].get(pos, [])
        if len(vs) < MINV: continue
        c = collections.Counter(v for v, _ in vs)
        top, n = c.most_common(1)[0]
        if len(c) > 1 and n < len(vs): 
            stat['disagree'] += 1; continue
        base = top; nm2 = base
        while nm2 in idents: used[base] += 1; nm2 = base + str(used[base] + 1)
        idents.add(nm2)
        rows.append('local\t%s\t%s\t%s\tINFERRED\tcallers pass their variable `%s` here (%d call site(s), e.g. in %s)' % (fn, nm, nm2, top, len(vs), vs[0][1]))
        stat['named'] += 1
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(dict(stat), len(funcs), file=sys.stderr)
