#!/usr/bin/env python3
"""callarg_check.py STOCK_DIS DUMP_DIR [NAME_FILTER]  - call-site argument check (issue #70 criterion 2): for every direct call in the stock code, the
constants the caller loads into argument registers in the same basic block (`li r5,0x10`, `lis`+`ori`/`addi`) must appear as the same literal at
the same argument position of a call to that callee in the function's decompile. Integer arguments only (a call whose C has a float/double
argument before the position is skipped - Darwin shifts the GPR slots). Computed sources (issue #70 criterion 2, order/source): an argument register loaded
`addi rK,rP,off` / `lwz|lbz|lhz|lha rK,off(rP)` from a register rP that is a prologue copy of an incoming parameter is matched by parameter AND offset
against the C argument, resolved through the function's own `var = expr;` assignments (3 levels): the C text must mention that parameter and the offset. Calls are matched per (function, callee) as multisets, so the order in
which the decompiler prints them does not matter. Prints every stock constant that no C call of that callee in that function carries at that
position (a dropped, shifted or wrong argument), and a summary. A constant the decompiler printed as the symbol at that address is reported
apart: SYMBOLIZED-FUNCTION (`FUN_00001740` for the size 0x1740 - the rebuilt code passes the rebuilt function's address) is a real defect,
a text address (`&UNK_00003754`) is harmless (ghidra2c turns it back into the number)."""
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
    out = []; d = 0; cur = ''; q = None; esc = False
    for ch in s:
        if q:   # inside a string / char literal: commas and parentheses are text
            cur += ch
            if esc: esc = False
            elif ch == '\\': esc = True
            elif ch == q: q = None
            continue
        if ch in '"\'': q = ch
        elif ch in '([': d += 1
        elif ch in ')]': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''; continue
        cur += ch
    if cur.strip(): out.append(cur.strip())
    return out
def c_calls(text, callee):
    """argument lists of every call of `callee` (by its last name component) in a decompile"""
    res = []
    for m in re.finditer(r'(?<![\w.>])(?:[\w:]*::)?_*%s\s*\(' % re.escape(callee), text):
        i = m.end(); d = 1; j = i; q = None
        while j < len(text) and d:
            c = text[j]
            if q:
                if c == '\\': j += 1
                elif c == q: q = None
            elif c in '"\'': q = c
            elif c == '(': d += 1
            elif c == ')': d -= 1
            j += 1
        res.append(split_args(text[i:j - 1]))
    return res
def c_defs(text):
    """{variable: [right-hand sides]} of the `var = expr;` assignments of a decompile (casts kept), for resolving an argument through its locals"""
    d = collections.defaultdict(list)
    for m in re.finditer(r'(?m)^\s*(?:\*\s*\(\w[\w ]*\*\)\s*)?(\w+)\s*=\s*([^;=][^;]*);', text):
        d[m.group(1)].append(m.group(2))
    return d
def c_resolve(e, defs, depth=2, seen=None):
    """the text of e with every variable in it replaced by the right-hand sides assigned to it (transitively, `depth` levels)"""
    seen = seen if seen is not None else set(); out = [e]
    if depth == 0: return e
    for v in set(re.findall(r'\b[A-Za-z_]\w*\b', e)):
        if v in defs and v not in seen:
            for r in defs[v][:80]: out.append(c_resolve(r, defs, depth - 1, seen | {v}))
    return ' '.join(out)
def c_carries(e, defs, pname, off):
    """could the C argument e carry parameter `pname` plus (or loaded at) offset off: its resolved text mentions the parameter and the offset value"""
    t = c_resolve(e, defs)
    if not re.search(r'\b%s\b' % re.escape(pname), t): return False
    if off == 0: return True
    nums = set(int(x, 16) for x in re.findall(r'\b(?:UNK|DAT|FUN|LAB|PTR_\w*?)_?([0-9a-f]{8})\b', t))   # an offset the decompiler printed as the symbol at that address (`&DAT_000011d1`)
    for x in re.findall(r'-?0x[0-9a-fA-F]+|-?\b\d+\b', t):
        try: nums.add(int(x, 0))
        except ValueError: pass
    # `param_1[2]` / `param_1 + 2` on a typed pointer scale the literal by the element size (int / short / double, byte)
    scaled = {n * z for n in nums for z in (1, 2, 4, 8)}
    return off in scaled or -off in scaled or (off & 0xffff) in scaled
def lit(e):
    e = re.sub(r'^\((?:[\w ]+\**)\)\s*', '', e.strip())   # a cast
    if e in ('false', "'\\0'", 'NULL'): return 0
    if e == 'true': return 1
    mc = re.match(r"^'(.)'$", e)
    if mc: return ord(mc.group(1))
    v = imm(e.rstrip('UuLl'))
    if v is None and re.match(r"^-\d+$", e): v = int(e)
    return None if v is None else v & 0xffffffff
def param_copies(rng):
    """{callee-saved reg: incoming argument index} for registers whose only definition in the function is a prologue copy `or rX,rY,rY` of an
    argument register rY that nothing overwrote before the copy"""
    defs = collections.defaultdict(list); first_call = None; seq = []
    for lo, hi in rng:
        for a in range(lo, hi, 4):
            if a not in ins: continue
            op, arg = ins[a]; seq.append(a)
            if op in ('bl', 'bctrl') and first_call is None: first_call = a
            p = [x.strip() for x in arg.split(';')[0].split(',')]
            if op == 'lmw' or op == 'lwz' and len(p) > 1 and p[1].endswith('(r1)') and int(p[0][1:]) >= 13: continue   # the epilogue's restore
            if p and re.match(r'r\d+$', p[0]) and not op.startswith(('st', 'cmp', 'b', 'tw', 'mt')): defs[int(p[0][1:])].append((a, op, p))
    out = {}
    for r, ds in defs.items():
        if r < 13 or len(ds) != 1: continue
        a, op, p = ds[0]
        if op == 'or' and len(p) == 3 and p[1] == p[2] and re.match(r'r([3-9]|10)$', p[1]) and (first_call is None or a < first_call):
            y = int(p[1][1:])
            if not any(d[0] < a for d in defs.get(y, [])): out[r] = y - 3
    return out
def _reads(op, parts, r):
    """does the instruction read register r (any operand except a plain destination)"""
    regs_ = [int(x) for x in re.findall(r'\br(\d+)\b', ','.join(parts))]
    if op.startswith(('st', 'cmp', 'tw', 'mt', 'bc', 'b')): return r in regs_
    # dest first: only the source operands count (rlwimi also reads its destination)
    src = [int(x) for x in re.findall(r'\br(\d+)\b', ','.join(parts[1:]))]
    return r in src or (op.startswith('rlwimi') and parts and parts[0] == 'r%d' % r)
def arg_source(a, r, pc):
    """the source of argument register r at the call at a, within its basic block: ('param', k), ('stack', off), ('addr'|'field', k, off) or None.
    A computed source (addr / field) counts only when nothing between the load and the call reads r again: a register read afterwards is a temporary
    the compiler left behind (a base pointer, a compare operand), not an argument."""
    i = idx[a] - 1; reread = False
    while i >= 0 and idx[a] - i < 40:
        b = order[i]; op, arg = ins[b]
        if op.startswith('b') or b in BRANCH_TARGETS and b != order[idx[a] - 1]: break
        p = [x.strip() for x in arg.split(';')[0].split(',')]
        if p and p[0] == 'r%d' % r and not op.startswith(('st', 'cmp')):
            if op == 'or' and len(p) == 3 and p[1] == p[2] and int(p[1][1:]) in pc: return ('param', pc[int(p[1][1:])])
            if op == 'addi' and len(p) == 3 and p[1] == 'r1': return ('stack', int(p[2], 0))
            if reread: return None
            if op == 'addi' and len(p) == 3 and re.match(r'r\d+$', p[1]) and int(p[1][1:]) in pc and imm(p[2]) is not None:
                o = imm(p[2]) & 0xffff; return ('addr', pc[int(p[1][1:])], o - 0x10000 if o & 0x8000 else o)
            mm = re.match(r'(-?0x[0-9a-f]+|-?\d+)\(r(\d+)\)$', p[1]) if len(p) == 2 else None
            if op in ('lwz', 'lbz', 'lhz', 'lha') and mm and int(mm.group(2)) in pc:
                o = int(mm.group(1), 0) & 0xffff; return ('field', pc[int(mm.group(2))], o - 0x10000 if o & 0x8000 else o)
            return None
        if _reads(op, p, r): reread = True
        i -= 1
    return None
tot = miss = checked = symd = 0; out = []
pmiss = pchecked = smiss = schecked = fmiss = fchecked = 0
for ent, (name, rng) in sorted(rows.items()):
    if flt and flt not in name: continue
    f = os.path.join(dump, '0x%x.txt' % ent)
    if not os.path.exists(f): continue
    text = open(f).read(); text = text[text.find('\n{\n'):]
    per = collections.defaultdict(list)
    pcs = param_copies(rng)
    _sg = re.search(r'// Signature: .*', open(f).read(2000))
    # the parameters' names in order (`this`, `param_2`, a demangled name...): an incoming argument is matched by its name
    pnames = [re.search(r'(\w+)\s*$', x.strip()).group(1) for x in split_args(re.search(r'\((.*)\)', _sg.group(0)).group(1))
              if x.strip() and x.strip() != 'void' and re.search(r'(\w+)\s*$', x.strip())] if _sg and re.search(r'\((.*)\)', _sg.group(0)) else []
    for lo, hi in rng:
        for a in range(lo, hi, 4):
            if ins.get(a, ('',))[0] != 'bl': continue
            arg = ins[a][1]; mt = re.match(r'0x([0-9a-f]+)', arg); ms = re.search(r'symbol stub for: (\S+)', arg)
            t = int(mt.group(1), 16) if mt else None
            cal = ms.group(1) if ms else names.get(t) or (label.get(t) if t is not None else None) or (arg.split()[0] if not mt else None)
            if not cal: continue
            k = consts_before(a)
            src_ = {}
            for r in range(3, 11):
                sv = arg_source(a, r, pcs)
                if sv: src_[r] = sv
            if k or src_: per[short(cal)].append((a, k, src_))
    for cal, sites in per.items():
        calls = c_calls(text, cal)
        if not calls: continue
        have = collections.Counter(); sym = {}
        for args in calls:
            for i, e in enumerate(args):
                if re.search(r'\((?:float|double)\)|\b(?:dVar|fVar|in_f|extraout_f|fparam_)\w*|\bDOUBLE_|\bFLOAT_', e): break   # a float argument: GPR slots shift
                v = lit(e)
                if v is not None: have[(i, v)] += 1
                ms_ = re.match(r'^(?:\([^()]*\)\s*)?&?(FUN|LAB|DAT|UNK|PTR_\w*)_([0-9a-f]{8})$', e)
                if ms_: sym[(i, int(ms_.group(2), 16))] = e   # a constant the decompiler printed as a symbol at that address
        haveP = collections.Counter(); haveS = collections.Counter()
        defs_ = c_defs(text)
        fneed = collections.Counter(); fsites = collections.defaultdict(list)
        addrvars = set(re.findall(r'\b(\w+)\s*=\s*(?:\([^()]*\)\s*)?(?:&|a[a-z]?Stack_\w+\s*[;+])', text))   # variables the function assigns an address to (`&x`, or a stack array, which decays: `a5 = auStack_5c;`)
        for args in calls:
            slot = 0
            for i_, e_ in enumerate(args):
                i0 = slot   # the GPR slot of this argument: a double before it takes two (Darwin)
                slot += 2 if re.search(r'\((?:double)\)|\bdVar\d+|\bDOUBLE_|\bfparam_', e_) else 1
                i_ = i0
                e2 = re.sub(r'^(?:\((?:[\w ]+\**)\)\s*)+', '', e_.strip())
                if e2 in addrvars: haveS[i_] += 1
                if e2 in pnames: haveP[(i_, pnames.index(e2))] += 1
                if '&' in e2 or re.match(r'^(?:a[uc]Stack|local_|[a-z]*Stack)\w*', e2) or 'STACKARG' in e2 or 'frame_address' in e2 or 'ghidra_frame' in e2: haveS[i_] += 1
        for a, k, src_ in sites:
            for r, sv in sorted(src_.items()):
                if sv[0] in ('addr', 'field'):
                    if sv[1] >= len(pnames): continue
                    fneed[(r - 3, sv[1], sv[2], sv[0])] += 1; fsites[(r - 3, sv[1], sv[2], sv[0])].append(a); continue
                if sv[0] == 'param':
                    if sv[1] >= len(pnames): continue   # an undeclared incoming register (in_rN, see inreg_liveness.py)
                    pchecked += 1
                    if haveP[(r - 3, sv[1])] > 0: haveP[(r - 3, sv[1])] -= 1; continue
                    pmiss += 1; out.append('%x\t%s\tcall %x %s\tr%d = incoming param_%d not at argument %d of any C call (%d C calls)' % (ent, name, a, cal, r, sv[1] + 1, r - 3, len(calls)))   # param_N: the Nth incoming
                else:
                    schecked += 1
                    if haveS[r - 3] > 0: haveS[r - 3] -= 1; continue
                    smiss += 1; out.append('%x\t%s\tcall %x %s\tr%d = r1+%#x (a stack address) not at argument %d of any C call (%d C calls)' % (ent, name, a, cal, r, sv[1], r - 3, len(calls)))
            for r, v in sorted(k.items()):
                checked += 1
                if have[(r - 3, v)] > 0: have[(r - 3, v)] -= 1; continue
                if (r - 3, v) in sym:
                    symd += 1
                    kind = 'SYMBOLIZED-FUNCTION' if re.match(r'^(?:\([^()]*\)\s*)?FUN_', sym[(r - 3, v)]) else 'symbolized-text-address'
                    out.append('%x\t%s\tcall %x %s\tr%d = %#x printed as %s (%s)' % (ent, name, a, cal, r, v, sym[(r - 3, v)], kind)); continue
                miss += 1; out.append('%x\t%s\tcall %x %s\tr%d = %#x not at argument %d of any C call (%d C calls)' % (ent, name, a, cal, r, v, r - 3, len(calls)))
        for (pos, k_, off, kind), need in fneed.items():
            have_n = 0
            for args in calls:
                if pos < len(args) and c_carries(args[pos], defs_, pnames[k_], off): have_n += 1
            fchecked += need
            if have_n < need:
                fmiss += need - have_n
                out.append('%x\t%s\tcall %x %s\tr%d = %s %s%+#x: %d stock site(s), %d C call(s) carry it at argument %d (%d C calls)' % (ent, name, fsites[(pos, k_, off, kind)][0], cal, pos + 3, 'field at' if kind == 'field' else 'address', pnames[k_], off, need, have_n, pos, len(calls)))
for l in out: print(l)
print('checked %d constant arguments, %d not found in the C, %d printed as a symbol at that address' % (checked, miss, symd))
print('checked %d computed-source arguments (addr / field of a parameter), %d not carried by the C at their position' % (fchecked, fmiss))
print('checked %d incoming-parameter arguments, %d not at their position; %d stack-address arguments, %d not an address at their position' % (pchecked, pmiss, schecked, smiss))
