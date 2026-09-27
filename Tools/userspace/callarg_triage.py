#!/usr/bin/env python3
"""callarg_triage.py STOCK_DIS RANGES_TSV DUMP_DIR CALLARG_OUTPUT OUT.tsv  (issue #70 criterion 2)
Classifies every residual row of callarg_check.py (a register the caller sets at a call that the C call does not carry at that position) by asking
the callee - with inreg_liveness.py's liveness (3 levels deep) - whether it reads that argument register at all:
  BENIGN-CALLEE-IGNORES  the callee never reads the register: a leftover value of the caller, the stock passes it by accident
  BENIGN-IMPORT-ARITY    an import that takes fewer arguments (memset(p, v, n) with r9 set for an earlier use)
  BENIGN-SYMBOLIZED      the constant is printed as the symbol at that address (a text / data address: ghidra2c turns it back into the number)
  BENIGN-DOUBLE-SLOT     the C carries the argument but at a position shifted by a double (Darwin gives a double two GPR slots; callarg_check counts slots)
  CHECK                  the callee reads it (or it is unknown): needs a manual look
Output: one row per residual row with its class."""
import sys, re, io, importlib.util, contextlib
dis, rng, dump, ca, out = sys.argv[1:6]
corpus = sys.argv[6] if len(sys.argv) > 6 else None      # Userspace/<bin>/ppc: the C, for the alias check below
sys.argv = ['inreg_liveness.py', dis, rng, dump]
spec = importlib.util.spec_from_file_location('inreg_liveness', __file__.rsplit('/', 1)[0] + '/inreg_liveness.py'); il = importlib.util.module_from_spec(spec)
with contextlib.redirect_stdout(io.StringIO()): spec.loader.exec_module(il)
import glob
BODY = {}
if corpus:
    for f_ in sorted(glob.glob(corpus + '/part_*.c')):
        t_ = open(f_, errors='replace').read()
        for m_ in re.finditer(r'(?m)^/\* (\S+) @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n(.*?)(?=^/\* \S+ @ 0x|\Z)', t_, re.S): BODY[m_.group(1)] = m_.group(2)
def split_args(a):
    o = []; d = 0; c = ''
    for ch in a:
        if ch in '([': d += 1
        if ch in ')]': d -= 1
        if ch == ',' and d == 0: o.append(c.strip()); c = ''
        else: c += ch
    if c.strip(): o.append(c.strip())
    return o
def c_calls(body, callee):
    out = []
    for nm in {callee, '_' + callee, callee.lstrip('_')}:
        for m in re.finditer(r'(?<![\w])%s\)?\s*\(' % re.escape(nm), body):
            i = m.end(); d = 1; j = i
            while j < len(body) and d:
                d += {'(': 1, ')': -1}.get(body[j], 0); j += 1
            out.append(split_args(body[i:j - 1]))
    return out
def alias_ok(body, arg, want):
    """does the C argument stand for what the stock passes: `want` = ('param', N) / ('const', K) / ('addr',)"""
    a = re.sub(r'^\((?:[\w ]+\s*\*?)\)\s*', '', arg.strip()).strip('() ')
    if want[0] == 'param': return a == 'param_%d' % want[1] or any(re.search(r'\b%s = (?:\([^)]*\))?param_%d;' % (re.escape(a), want[1]), body) for _ in [0])
    if want[0] == 'const':
        if re.fullmatch(r'0x0*%x|%d' % (want[1], want[1]), a) or a == ('0' if want[1] == 0 else '?'): return True
        asg = re.findall(r'\b%s = ([^;]+);' % re.escape(a), body) if re.fullmatch(r'\w+', a) else []
        return bool(asg) and all(re.fullmatch(r'(?:\([^)]*\))?\s*(0x0*%x|%d)' % (want[1], want[1]), x.strip()) for x in asg)
    if want[0] == 'addr': return '&' in arg or bool(re.fullmatch(r'\w+', a) and re.search(r'\b%s = (?:\([^)]*\))?\s*&' % re.escape(a), body)) or a.startswith('local_') or a.startswith('auStack')
    return False
rows = []
for l in open(ca):
    m = re.match(r'([0-9a-f]+)\t(\S+)\tcall ([0-9a-f]+) (\S+)\tr(\d+) = (.*)$', l.rstrip('\n'))
    if m: rows.append(m.groups())
cnt = {}
with open(out, 'w') as f:
    f.write('# owner entry\towner\tcall site\tcallee\tregister\tvalue\tclass\n')
    for ent, owner, site, callee, reg, rest in rows:
        reg = int(reg); cl = 'CHECK'
        if 'symbolized' in rest: cl = 'BENIGN-SYMBOLIZED'
        else:
            op, arg = il.ins.get(int(site, 16), ('', ''))
            t = None; ms = re.search(r'symbol stub for: (\S+)', arg)
            if ms:
                sym = ms.group(1)
                if sym in il.label: t = il.label[sym]
                elif sym in il.ARITY: cl = 'BENIGN-IMPORT-ARITY' if reg >= 3 + il.ARITY[sym] else 'CHECK'
                elif sym in il.FARITY: cl = 'BENIGN-DOUBLE-SLOT'
            else:
                mt = re.match(r'0x([0-9a-f]+)', arg)
                if mt: t = int(mt.group(1), 16)
                elif arg.split() and arg.split()[0] in il.label: t = il.label[arg.split()[0]]     # in-image call by label (`bl __ZNSsD4Ev`)
            if t is not None:
                c_ = il.cls(t)
                r = 'ret' if (c_ and reg in c_[1] and reg not in c_[0]) else il.callee_reads(t, reg, 3)      # `ret`: the register is only read by the callee's return (r3 / r4 echoed back)
                cl = {'no': 'BENIGN-CALLEE-IGNORES', 'ret': 'BENIGN-CALLEE-ONLY-RETURNS-IT'}.get(r, 'CHECK' + ('' if r == 'yes' else '-' + r))
            if cl.startswith('CHECK') and corpus and owner in BODY:
                mm = re.search(r'not at argument (\d+)', rest); pos = int(mm.group(1)) if mm else None
                mp = re.match(r'incoming param_(\d+)', rest); mc = re.match(r'(0x[0-9a-f]+|\d+) ', rest); ma = re.match(r'r1\+', rest)
                want = ('param', int(mp.group(1))) if mp else ('const', int(mc.group(1), 0)) if mc else ('addr',) if ma else None
                calls = c_calls(BODY[owner], callee) if want and pos is not None else []
                if calls and all(len(c) > pos and alias_ok(BODY[owner], c[pos], want) for c in calls[:1] if True) and any(len(c) > pos and alias_ok(BODY[owner], c[pos], want) for c in calls):
                    cl = 'BENIGN-ALIAS (the C argument is a copy / the same constant / an address)'
                elif calls: cl = cl + ' (C arg%d: %s)' % (pos, '; '.join((c[pos] if len(c) > pos else '-')[:30] for c in calls[:2]))
        cnt[cl] = cnt.get(cl, 0) + 1
        f.write('0x%s\t%s\t0x%s\t%s\tr%d\t%s\t%s\n' % (ent, owner, site, callee, reg, rest, cl))
print(len(rows), 'rows:', cnt)
