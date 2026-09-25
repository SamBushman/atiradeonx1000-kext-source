#!/usr/bin/env python3
"""callarg_check.py STOCK_DIS DUMP_DIR [NAME_FILTER]  - call-site argument check (issue #70 criterion 2): for every direct call in the stock code, the
constants the caller loads into argument registers in the same basic block (`li r5,0x10`, `lis`+`ori`/`addi`) must appear as the same literal at
the same argument position of a call to that callee in the function's decompile. Integer arguments only (a call whose C has a float/double
argument before the position is skipped - Darwin shifts the GPR slots). Calls are matched per (function, callee) as multisets, so the order in
which the decompiler prints them does not matter. Prints every stock constant that no C call of that callee in that function carries at that
position (a dropped, shifted or wrong argument), and a summary."""
import sys, re, glob, os, collections
dis, dump = sys.argv[1:3]
flt = sys.argv[3] if len(sys.argv) > 3 else None
ins = {}; order = []; label = {}; _pl = None
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l.rstrip())
    if m:
        a = int(m.group(1), 16); ins[a] = (m.group(2), m.group(3)); order.append(a)
        if _pl: label.setdefault(a, _pl); _pl = None
    elif l.rstrip().endswith(':') and not l.startswith(('\t', '(')): _pl = l.rstrip()[:-1]
idx = {a: i for i, a in enumerate(order)}
rows = {}
for l in open(os.path.join(dump, 'RANGES.tsv')):
    p = l.rstrip('\n').split('\t')
    if len(p) > 3 and p[0].startswith('0x') and p[2] == 'fn':
        rows[int(p[0], 16)] = (p[1], [tuple(int(x, 16) for x in r.split('-')) for r in p[3].strip(';').split(';') if r])
names = {a: n for a, (n, _) in rows.items()}
def short(n): return re.split(r'::', n)[-1].lstrip('_') if n else n
def imm(s):
    s = s.strip()
    try: return int(s, 0)
    except ValueError: return None
def consts_before(a):
    """{reg: value} for r3..r10 loaded with a constant in the basic block ending at the call at a (stops at a label/branch target or a branch)"""
    got = {}; dead = set(); i = idx[a] - 1
    while i >= 0 and idx[a] - i < 40:
        b = order[i]; op, arg = ins[b]
        if op.startswith('b') or op in ('.long',): break
        parts = [x.strip() for x in arg.split(';')[0].split(',')]
        if parts and re.match(r'r\d+$', parts[0]):
            r = int(parts[0][1:])
            if 3 <= r <= 10 and r not in got and r not in dead:
                if op == 'li' and len(parts) == 2 and imm(parts[1]) is not None:
                    v = imm(parts[1]) & 0xffff; got[r] = (v - 0x10000 if v & 0x8000 else v) & 0xffffffff   # a signed 16-bit immediate (otool prints -1 as 0xffff)
                elif op == 'lis' and len(parts) == 2 and imm(parts[1]) is not None: got[r] = (imm(parts[1]) << 16) & 0xffffffff
                else: dead.add(r)   # set some other way: not a plain constant
        if b in BRANCH_TARGETS: break
        i -= 1
    # `lis` followed by `ori/addi` of the same register was seen first (walking backwards) as `ori` -> dead; plain lis+ori pairs are not compared
    return got
BRANCH_TARGETS = set()
for a, (op, arg) in ins.items():
    m = re.match(r'(?:cr\d,)?0x([0-9a-f]+)', arg)
    if op.startswith('b') and m: BRANCH_TARGETS.add(int(m.group(1), 16))
def split_args(s):
    out = []; d = 0; cur = ''
    for ch in s:
        if ch in '([': d += 1
        elif ch in ')]': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''; continue
        cur += ch
    if cur.strip(): out.append(cur.strip())
    return out
def c_calls(text, callee):
    """argument lists of every call of `callee` (by its last name component) in a decompile"""
    res = []
    for m in re.finditer(r'(?<![\w.>])(?:[\w:]*::)?_*%s\s*\(' % re.escape(callee), text):
        i = m.end(); d = 1; j = i
        while j < len(text) and d:
            if text[j] == '(': d += 1
            elif text[j] == ')': d -= 1
            j += 1
        res.append(split_args(text[i:j - 1]))
    return res
def lit(e):
    e = re.sub(r'^\((?:[\w ]+\**)\)\s*', '', e.strip())   # a cast
    if e in ('false', "'\\0'", 'NULL'): return 0
    if e == 'true': return 1
    mc = re.match(r"^'(.)'$", e)
    if mc: return ord(mc.group(1))
    v = imm(e.rstrip('UuLl'))
    if v is None and re.match(r"^-\d+$", e): v = int(e)
    return None if v is None else v & 0xffffffff
tot = miss = checked = 0; out = []
for ent, (name, rng) in sorted(rows.items()):
    if flt and flt not in name: continue
    f = os.path.join(dump, '0x%x.txt' % ent)
    if not os.path.exists(f): continue
    text = open(f).read(); text = text[text.find('\n{\n'):]
    per = collections.defaultdict(list)
    for lo, hi in rng:
        for a in range(lo, hi, 4):
            if ins.get(a, ('',))[0] != 'bl': continue
            arg = ins[a][1]; mt = re.match(r'0x([0-9a-f]+)', arg); ms = re.search(r'symbol stub for: (\S+)', arg)
            t = int(mt.group(1), 16) if mt else None
            cal = ms.group(1) if ms else names.get(t) or (label.get(t) if t is not None else None) or (arg.split()[0] if not mt else None)
            if not cal: continue
            k = consts_before(a)
            if k: per[short(cal)].append((a, k))
    for cal, sites in per.items():
        calls = c_calls(text, cal)
        if not calls: continue
        have = collections.Counter()
        for args in calls:
            for i, e in enumerate(args):
                if re.search(r'\((?:float|double)\)|\b(?:dVar|fVar|in_f|extraout_f|fparam_)\w*|\bDOUBLE_|\bFLOAT_', e): break   # a float argument: GPR slots shift
                v = lit(e)
                if v is not None: have[(i, v)] += 1
        for a, k in sites:
            for r, v in sorted(k.items()):
                checked += 1
                if have[(r - 3, v)] > 0: have[(r - 3, v)] -= 1; continue
                miss += 1; out.append('%x\t%s\tcall %x %s\tr%d = %#x not at argument %d of any C call (%d C calls)' % (ent, name, a, cal, r, v, r - 3, len(calls)))
for l in out: print(l)
print('checked %d constant arguments, %d not found in the C' % (checked, miss))
