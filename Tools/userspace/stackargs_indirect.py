#!/usr/bin/env python3
"""stackargs_indirect.py STOCK_DIS RANGES_TSV DUMP_DIR CORPUS_DIR SLOT [--apply]      (issue #70, indirect calls: stack-passed arguments)

Darwin passes argument words 9.. on the stack at 0x38(r1).. (0x38 = 24 linkage + 32 register spill). A call through a function pointer whose callee reads
them - GLDriver's `ctx+0x240 + 0x12e4` slot is FUN_000840d0 (12 parameters: two groups of four, the stencil-style front / back state) - needs those words in
the C call, but the decompile prints only the register arguments (the four `stw rS,0x38..0x44(r1)` stores are dead locals to Ghidra).
For every `bctrl` through struct offset SLOT that stores four stack words in its block, this tool
  * derives the symbolic value of each stored register (reaching definitions over the function, `or` copies followed, `lwz` / `addi` / `li` trees; a `multi` /
    call-clobbered / unknown value is left unresolved), and either points it at the register argument (5..8) with the same value or prints it as a C expression
    over the function's own parameters (`*(int *)((int)param_1 + 0x3ec)`);
  * pairs the stock's calls with the C calls of the function through that slot by order, checking the PIC-constant argument (`&DAT_...`) against the address the
    stock computes (`addis rN,r31,K; addi rN,rN,L` from the `bcl` anchor);
  * appends the four arguments to every 8-argument C call (a value used by consecutive calls without control flow in between is computed once into a new local
    before the first call, like the stock's callee-saved register: the callee-saved copy is loaded once, the C must not reload it after an intervening call).
Without --apply it only reports. Sites it cannot resolve or pair are reported and left alone."""
import sys, re, io, importlib.util, contextlib, collections, glob, os
ARGV = sys.argv[:]
dis, rng, dump, corpus = ARGV[1], ARGV[2], ARGV[3], ARGV[4]
_sl = ARGV[5].split(':')
slot = int(_sl[0], 0)
NWORDS = int(_sl[1]) if len(_sl) > 1 else 4        # SLOT[:N] - stack words (arguments 9..8+N) the slot's callee takes
APPLY = '--apply' in ARGV
sys.argv = ['reg_supply.py', dis, rng, dump, '--terminals', '0', '3']          # reg_supply.py's module code reads argv; only its definitions are used
src = open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'reg_supply.py')).read().split('if mode_term:')[0]
__file__ = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'reg_supply.py')
exec(src)

# hand-written expressions for phi words the tool cannot tie to a C variable: {"<function entry hex>": {"<word offset hex>@<call address hex>": "<C expression>"}} - the C must
# already contain the variable (added by hand at the merge point, see Userspace/README.md)
import json as _json
_ovp = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'stackargs_overrides.json')
OVERRIDES = _json.load(open(_ovp)) if os.path.exists(_ovp) else {}

# ---- symbolic values -----------------------------------------------------------------------------------------------------
_rd = {}
def reaching(g):
    """{addr: {reg: frozenset(def addrs, or 'E' = the entry value)}} at the input of each instruction of function g"""
    if g in _rd: return _rd[g]
    lr, lt, la, info, succ = il.cls(g)
    addrs = sorted(info); IN = {a: {} for a in addrs}
    IN[g if g in IN else addrs[0]] = {r: frozenset(['E']) for r in range(32)}
    changed = True
    while changed:
        changed = False
        for a in addrs:
            d = info[a][0]; out = dict(IN[a])
            for r in d: out[r] = frozenset([a])
            for s_ in succ[a]:
                cur = IN[s_]; new = dict(cur); ch = False
                for r, v in out.items():
                    nv = cur.get(r, frozenset()) | v
                    if nv != cur.get(r): new[r] = nv; ch = True
                if ch: IN[s_] = new; changed = True
    _rd[g] = IN
    return IN
def _n(x):
    try: return int(x, 0) & 0xffff
    except ValueError: return x
def key_of_def(g, d, depth):
    """the symbolic value the definition at d produces"""
    op, arg = ins[d]; p = [x.strip() for x in arg.split(';')[0].split(',')]
    return key_at_def(g, d, int(p[0][1:]), depth)
def key_at_def(g, d, reg, depth):
    """key() of the register a definition writes, evaluated as the value defined AT d (the output of d)"""
    op, arg = ins[d]; p = [x.strip() for x in arg.split(';')[0].split(',')]
    if op in ('or', 'or.') and len(p) == 3 and p[1] == p[2]: return key(g, d, int(p[1][1:]), depth - 1)
    if op == 'li': return ('li', p[1])
    m = re.match(r'(-?0x[0-9a-f]+|-?\d+)\(r(\d+)\)$', p[1]) if len(p) == 2 else None
    if op in ('lwz', 'lbz', 'lhz') and m: return (op, int(m.group(1), 0), key(g, d, int(m.group(2)), depth - 1))
    if op == 'addi' and len(p) == 3 and p[1] != 'r0': return ('addi', _n(p[2]), key(g, d, int(p[1][1:]), depth - 1))
    if op == 'addi' and len(p) == 3: return ('li', p[2])
    return ('def', d)
def key(g, a, reg, depth=6):
    """symbolic value of reg at the input of the instruction at a"""
    if depth == 0: return ('deep',)
    ds = reaching(g).get(a, {}).get(reg, frozenset())
    if len(ds) != 1:
        # several reaching definitions: if every one has the same symbolic value (two loads of the same field through copies of one pointer) that is the value
        if 'E' not in ds:
            ks = {key_of_def(g, d, depth) for d in ds}
            if len(ks) == 1 and next(iter(ks))[0] not in ('multi', 'deep', 'def'): return next(iter(ks))
        return ('multi', tuple(sorted(str(x) for x in ds)))
    d = next(iter(ds))
    if d == 'E': return ('entry', reg)
    op, arg = ins[d]; p = [x.strip() for x in arg.split(';')[0].split(',')]
    if op in ('or', 'or.') and len(p) == 3 and p[1] == p[2]: return key(g, d, int(p[1][1:]), depth - 1)
    if op == 'li': return ('li', p[1])
    m = re.match(r'(-?0x[0-9a-f]+|-?\d+)\(r(\d+)\)$', p[1]) if len(p) == 2 else None
    if op in ('lwz', 'lbz', 'lhz') and m: return (op, int(m.group(1), 0), key(g, d, int(m.group(2)), depth - 1))
    if op == 'addi' and len(p) == 3 and p[1] != 'r0': return ('addi', _n(p[2]), key(g, d, int(p[1][1:]), depth - 1))
    if op == 'addi' and len(p) == 3: return ('li', p[2])
    return ('def', d)
def same_multi(g, a, r1, r2):
    """two registers that merge several definitions at a: the same value if their definitions pair up one to one in the same places (within 3 instructions of each
    other) with equal symbolic values - two registers loaded in parallel on every path"""
    d1 = reaching(g).get(a, {}).get(r1, frozenset()); d2 = reaching(g).get(a, {}).get(r2, frozenset())
    if 'E' in d1 or 'E' in d2 or len(d1) != len(d2) or len(d1) < 2: return False
    rest = sorted(int(x) for x in d2)
    for x in sorted(int(x) for x in d1):
        m = [y for y in rest if abs(y - x) <= 12 and key_of_def(g, x, 6) == key_of_def(g, y, 6) and key_of_def(g, x, 6)[0] not in ('multi', 'deep', 'def')]
        if len(m) != 1: return False
        rest.remove(m[0])
    return not rest
def has_call_between(g, d, a):
    return any(ins[x][0] in ('bl', 'bctrl') for x in range(d, a, 4) if x in ins) if d < a else False
CTX = [None, None]          # (function entry, C body of the function being edited): lets cexpr name a load from the function's own stack frame
def cexpr(k):
    """a C expression for a symbolic value over the parameters (or the function's stack locals), or None"""
    if k[0] in ('lwz',) and k[2][0] == 'def' and ins[k[2][1]][0] == 'stwu' and CTX[0] is not None:
        off = k[1] if k[1] < 0x8000 else k[1] - 0x10000
        nm = stack_local(CTX[0], off, CTX[1])
        if nm is None: return None
        return '*(int *)%s' % nm if not nm.startswith('&') else nm[1:]
    if k[0] == 'entry': return 'param_%d' % (k[1] - 2) if 3 <= k[1] <= 10 else None
    if k[0] == 'li':
        try: return str(int(k[1], 0))
        except ValueError: return None
    if k[0] in ('lwz', 'lbz', 'lhz'):
        b = cexpr(k[2])
        if b is None: return None
        t = {'lwz': '*(int *)', 'lbz': '(uint)*(byte *)', 'lhz': '(uint)*(ushort *)'}[k[0]]
        return '%s((int)%s + %d)' % (t, b, k[1] if k[1] < 0x8000 else k[1] - 0x10000)
    if k[0] == 'addi':
        b = cexpr(k[2]); o = k[1] if isinstance(k[1], int) else None
        if b is None or o is None: return None
        return '(int)%s + %d' % (b, o if o < 0x8000 else o - 0x10000)
    return None
def pic_abs(g, a, reg):
    """absolute address of `addis rN,r31,K` + `addi rN,rN,L` in reg at a (the PIC constant), or None"""
    ds = reaching(g).get(a, {}).get(reg, frozenset())
    if len(ds) != 1 or 'E' in ds: return None
    d = next(iter(ds)); op, arg = ins[d]; p = [x.strip() for x in arg.split(',')]
    if op != 'addi' or len(p) != 3: return None
    imm = _n(p[2])
    if not isinstance(imm, int): return None
    imm = imm - 0x10000 if imm & 0x8000 else imm
    ds2 = reaching(g).get(d, {}).get(int(p[1][1:]), frozenset())
    if len(ds2) != 1 or 'E' in ds2: return None
    d2 = next(iter(ds2)); op2, arg2 = ins[d2]; q = [x.strip() for x in arg2.split(',')]
    if op2 != 'addis' or q[1] != 'r31': return None
    k_ = _n(q[2])
    if not isinstance(k_, int): return None
    k_ = k_ - 0x10000 if k_ & 0x8000 else k_
    anchor = None
    for x in range(g, g + 0x80, 4):
        if x in ins and ins[x][0] == 'bcl':
            m = re.search(r'0x([0-9a-f]+)', ins[x][1])
            if m: anchor = int(m.group(1), 16); break
    return None if anchor is None else (anchor + (k_ << 16) + imm) & 0xffffffff

# ---- the stock's calls ---------------------------------------------------------------------------------------------------
def pic_expr_for_word(g, a, store_addr, reg):
    """the symbol name of the PIC constant held in reg at the store instruction"""
    ab = pic_abs(g, store_addr, reg)
    return None if ab is None else sym_for(ab)
BTARGETS = set()
for _a, (_op, _arg) in ins.items():
    if _op.startswith('b') and not _op.startswith(('bl', 'blr', 'bctr')) or _op in ('b',):
        _m = re.match(r'(?:cr\d,)?0x([0-9a-f]+)', _arg)
        if _m: BTARGETS.add(int(_m.group(1), 16))
_stk = {}
def stack_reaching(g):
    """{addr: {word offset: frozenset(store addresses)}} at the input of each instruction: which `stw rS,0x38..(r1)` stores reach it (a call kills them: the callee owns
    the outgoing area, and a branch merges the paths)"""
    if g in _stk: return _stk[g]
    lr, lt, la, info, succ = il.cls(g)
    addrs = sorted(info); IN = {a: {} for a in addrs}
    changed = True
    while changed:
        changed = False
        for a in addrs:
            op, arg = ins[a]; out = dict(IN[a])
            if op in ('bl', 'bctrl', 'blrl'): out = {}
            else:
                m = re.match(r'(r\d+),(0x[0-9a-f]+)\(r1\)$', arg.replace(' ', ''))
                if op == 'stw' and m and 0x38 <= int(m.group(2), 16) < 0x38 + 4 * NWORDS: out[int(m.group(2), 16)] = frozenset([a])
            for s_ in succ[a]:
                cur = IN[s_]; new = dict(cur); ch = False
                for o, v in out.items():
                    nv = cur.get(o, frozenset()) | v
                    if nv != cur.get(o): new[o] = nv; ch = True
                if ch: IN[s_] = new; changed = True
    _stk[g] = IN
    return IN
def stack_stores(a):
    """{offset: (source register, store address)}: every word reached by exactly one store, or by several stores that store registers holding the same symbolic
    value (then the first); a word reached by different values, or by no store, is left out (the site is then reported and left alone)"""
    g = owner[a]; st = {}
    for off, stores in stack_reaching(g).get(a, {}).items():
        regs = []
        for sa in stores:
            m = re.match(r'(r\d+),', ins[sa][1]); regs.append((int(m.group(1)[1:]), sa))
        ks = {key(g, sa, r) for r, sa in regs}
        if len(ks) == 1 and next(iter(ks))[0] not in ('multi', 'deep'): st[off] = regs[0]
        elif len(regs) == 1: st[off] = regs[0]
    return st
sites = collections.defaultdict(list); JOINS = []
for a, (op, arg) in sorted(ins.items()):
    if op == 'bctrl' and a in owner and slot_of(a) == slot:
        st = stack_stores(a)
        if len(st) == NWORDS: sites[owner[a]].append((a, st))
        else: JOINS.append((a, owner[a], sorted(hex(k) for k in st)))

SYMS = {}
for l in open(os.path.join(corpus, 'link', 'symbol_map.tsv')):
    p_ = l.split('\t')
    if len(p_) > 1 and p_[1].startswith('0x') and re.match(r'(DAT|UNK|PTR_\w*?|LAB)_', p_[0]): SYMS.setdefault(int(p_[1], 16), p_[0])
def numset(text):
    n = set()
    for x in re.findall(r'-?0x[0-9a-fA-F]+|-?\b\d+\b', text):
        try: n.add(int(x, 0))
        except ValueError: pass
    return n
def phi_var(g, a, reg, body):
    """the C variable that carries a register's merged value: every reaching definition is a simple load (or li) whose offset appears in an assignment to the variable
    (or, for `li`, a literal assignment); returns the unique such variable or None"""
    ds = reaching(g).get(a, {}).get(reg, frozenset())
    if 'E' in ds or len(ds) < 2: return None
    need = []
    for d in ds:
        k = key_of_def(g, d, 6)
        if k[0] in ('lwz', 'lbz', 'lhz'): need.append(('off', k[1]))
        elif k[0] == 'li':
            try: need.append(('lit', int(k[1], 0)))
            except ValueError: return None
        else: return None
    assigns = collections.defaultdict(list)
    for m in re.finditer(r'(?m)^\s*(\w+)\s*=\s*([^;=][^;]*);', body): assigns[m.group(1)].append(m.group(2))
    cands = []
    for v, rhss in assigns.items():
        if not re.match(r'^(?:[iu]|p|pp|a|l|f)?(?:Var|Stack|local|param)', v) and not v.startswith('in_'): continue
        ok = True
        for kind, val in need:
            hit = False
            for r_ in rhss:
                ns = numset(r_)
                if kind == 'lit' and re.fullmatch(r'(?:\([^)]*\))?\s*(0x0*%x|%d)' % (val, val), r_.strip()): hit = True
                if kind == 'off' and val != 0 and any(val == n * z for n in ns for z in (1, 2, 4, 8)): hit = True
                if kind == 'off' and val == 0 and re.search(r'\*\s*\(?[\w(). ]*param_\d', r_): hit = True
            if not hit: ok = False; break
        if ok: cands.append(v)
    return cands[0] if len(cands) == 1 else None
RANGES_SYM = []
for l in open(os.path.join(corpus, 'link', 'symbol_map.tsv')):
    p_ = l.split('\t')
    if len(p_) > 4 and p_[1].startswith('0x') and re.match(r'(DAT|UNK)_', p_[0]) and p_[4].isdigit(): RANGES_SYM.append((int(p_[1], 16), int(p_[4]), p_[0]))
def sym_for(ab):
    if ab in SYMS: return '&' + SYMS[ab]
    for a0, ln, nm in RANGES_SYM:
        if a0 <= ab < a0 + ln: return '((unsigned char *)&%s + %d)' % (nm, ab - a0)
    # an address in an unsymbolised gap of the data section: relative to the nearest preceding symbol (the rebuilt data.s keeps the stock's layout)
    best = None
    for a0, ln, nm in RANGES_SYM:
        if a0 <= ab and ab - a0 < 0x100 and (best is None or a0 > best[0]): best = (a0, nm)
    return None if best is None else '((unsigned char *)&%s + %d)' % (best[1], ab - best[0])
def frame_size(g):
    for x in range(g, g + 0x40, 4):
        if x in ins and ins[x][0] == 'stwu':
            m = re.match(r'r1,(0x[0-9a-f]+)\(r1\)', ins[x][1].replace(' ', ''))
            if m: return 0x10000 - int(m.group(1), 16) if int(m.group(1), 16) >= 0x8000 else None
    return None
def stack_local(g, off, body):
    """the C name for the local at r1+off: Ghidra names it by its offset below the entry stack pointer (F - off)"""
    F = frame_size(g)
    if F is None: return None
    suf = '%x' % (F - off)
    m = re.search(r'\b((?:[a-z]*Stack_|local_)%s)\b(\[)?' % suf, body)
    if not m: return None
    nm = m.group(1)
    isarr = re.search(r'\b%s\[' % re.escape(nm), body) is not None and 'Stack' in nm and nm.startswith('a')
    return nm if isarr else '&' + nm
def pic_expr(g, a, reg):
    ab = pic_abs(g, a, reg)
    return None if ab is None else sym_for(ab)

def c_defs_of(body):
    d = collections.defaultdict(list)
    for m in re.finditer(r'(?m)^\s*(?:\*\s*\(\w[\w ]*\*\)\s*)?(\w+)\s*=\s*([^;=][^;]*);', body): d[m.group(1)].append(m.group(2))
    return d
def c_resolve_text(e, defs, depth=2, seen=None):
    seen = seen if seen is not None else set(); out = [e]
    if depth == 0: return e
    for v in set(re.findall(r'\b[A-Za-z_]\w*\b', e)):
        if v in defs and v not in seen:
            for r_ in defs[v][:80]: out.append(c_resolve_text(r_, defs, depth - 1, seen | {v}))
    return ' '.join(out)
def key_offsets(k):
    """the offsets of a load / addi chain rooted at an entry register, or None if the tree is not of that shape"""
    offs = []
    while k[0] in ('lwz', 'lbz', 'lhz', 'addi'):
        o = k[1]
        if not isinstance(o, int): return None
        offs.append(o if o < 0x8000 else o - 0x10000); k = k[2]
    return (offs, k[1]) if k[0] == 'entry' else None
def arg_consistent(argkey, arg_text, defs):
    """does the C argument mention the parameter and every offset of the stock's load chain (a check that the pairing is right)?"""
    ko = key_offsets(argkey)
    if ko is None: return True                     # a constant / phi / PIC: nothing to compare
    offs, reg = ko
    t = c_resolve_text(arg_text, defs)
    if not re.search(r'\bparam_%d\b' % (reg - 2), t): return True    # reached through an unrelated local: cannot say
    nums = set()
    for x in re.findall(r'-?0x[0-9a-fA-F]+|-?\b\d+\b', t):
        try: nums.add(int(x, 0))
        except ValueError: pass
    sc = {n * z for n in nums for z in (1, 2, 4, 8)} | nums
    return all(o == 0 or o in sc or -o in sc for o in offs)

# ---- the C side ----------------------------------------------------------------------------------------------------------
ledger = {}
for l in open(os.path.join(corpus, 'ledger.tsv')):
    p = l.rstrip('\n').split('\t')
    if len(p) >= 5 and p[0].startswith('0x'): ledger[int(p[0], 16)] = (p[2], p[3])
def split_args(s):
    out = []; d = 0; cur = ''
    for ch in s:
        if ch in '([': d += 1
        elif ch in ')]': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''; continue
        cur += ch
    if cur.strip(): out.append(cur.strip())
    return out
CALL = re.compile(r'\(\*\*\(code \*\*\)\(\(\(unsigned char \*\)0x0*%x\) \+ \w+\)\)\s*\(' % slot)
report = []; edits = {}
for g in sorted(sites):
    name, part = ledger.get(g, (None, None))
    if not part: report.append('%x: not in the ledger' % g); continue
    path = os.path.join(corpus, part + '.c'); text = edits.get(part) or open(path).read()
    m0 = re.search(r'(?m)^/\* %s @ 0x%x \(\d+ bytes\) \*/\n' % (re.escape(name), g), text)
    if not m0: report.append('%x: %s not found in %s.c' % (g, name, part)); continue
    m1 = re.search(r'(?m)^/\* \S+ @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n', text[m0.end():])
    fs, fe = m0.end(), m0.end() + (m1.start() if m1 else len(text) - m0.end())
    body = text[fs:fe]
    calls = []
    for m in CALL.finditer(body):
        i = m.end(); d = 1; j = i
        while j < len(body) and d:
            d += {'(': 1, ')': -1}.get(body[j], 0); j += 1
        calls.append((m.start(), i, j - 1, split_args(body[i:j - 1])))
    ss = sites[g]
    if calls and all(len(c[3]) >= 8 + NWORDS for c in calls): continue        # nothing left to add here
    fdefs = c_defs_of(body); CTX[0] = g; CTX[1] = body
    def compatible(a, args, strict=True):
        for reg in (6, 9, 10):
            ab = pic_abs(g, a, reg)
            if ab is not None and len(args) >= reg - 2 and re.search(r'_[0-9a-f]{8}\b', args[reg - 3]):
                if int(re.search(r'_([0-9a-f]{8})\b', args[reg - 3]).group(1), 16) != ab: return False
        for p_ in range(2, min(len(args), 8) + 1):
            k_ = key(g, a, 2 + p_)
            if not arg_consistent(k_, args[p_ - 1], fdefs): return False
            # a stack local: the stock's `addi rN,r1,off` / `lwz rN,off(r1)` must be the local Ghidra names by that offset (F - off below the entry SP)
            if strict and k_[0] in ('addi', 'lwz') and k_[2][0] == 'def' and ins[k_[2][1]][0] == 'stwu' and isinstance(k_[1], int):
                nm_ = stack_local(g, k_[1] if k_[1] < 0x8000 else k_[1] - 0x10000, body)
                if nm_ is not None and nm_.lstrip('&') not in c_resolve_text(args[p_ - 1], fdefs): return False
        return True
    # pair by order when the counts agree and that is consistent; otherwise each C call takes the stock call it is compatible with (Ghidra may lay the code
    # out in another order, or repeat a block: several C calls may then stand for one stock call)
    comp = [[compatible(a, c[3]) for c in calls] for a, st in ss]
    # C calls compatible with no stock call (code the stock does not have there) and stock calls compatible with no C call are set aside
    ok_c = [j for j in range(len(calls)) if any(comp[i][j] for i in range(len(ss)))]
    ok_s = [i for i in range(len(ss)) if any(comp[i][j] for j in range(len(calls)))]
    if (len(ok_c) != len(calls) or len(ok_s) != len(ss)) and len(ok_c) == len(ok_s) and ok_c:
        report.append('%x %s: %d C call(s) and %d stock call(s) set aside as incompatible with every counterpart' % (g, name, len(calls) - len(ok_c), len(ss) - len(ok_s)))
        calls = [calls[j] for j in ok_c]; ss = [ss[i] for i in ok_s]
        comp = [[compatible(a, c[3]) for c in calls] for a, st in ss]
    order = list(range(len(ss)))
    pairs = None
    # anchors: a stock call with exactly one compatible C call takes it; no other stock call can (the C's block order differs from the address order, so no
    # positional narrowing is done)
    def narrow(comp_):
        comp2 = [row[:] for row in comp_]; changed = True
        while changed:
            changed = False
            anchors = {i: [j for j in range(len(calls)) if comp2[i][j]] for i in range(len(ss))}
            fixed = {i: v[0] for i, v in anchors.items() if len(v) == 1}
            # a C call taken by an anchor is not available to the others
            for i, j in fixed.items():
                for k in range(len(ss)):
                    if k != i and comp2[k][j]: comp2[k][j] = False; changed = True
        return comp2
    comp = narrow(comp)
    def sig_of(i):
        a_, st_ = ss[i]
        # the words as symbolic values, and which of the call's own register arguments (r3..r10) hold the same value: a swap of two look-alike calls changes neither
        wk = [key(g, st_[0x38 + 4 * k][1], st_[0x38 + 4 * k][0]) for k in range(NWORDS)]
        return tuple((str(w), tuple(r_ for r_ in range(3, 11) if key(g, a_, r_) == w)) for w in wk)
    if pairs is None and len(calls) >= len(ss):
        # every stock call takes a distinct compatible C call (the C may have extra calls); when several matchings exist they must give every C call the same
        # words (look-alike calls), otherwise the function is left alone unless a human checked the pairing (pairing_ok)
        sols = []
        def dfs2(i, used, cur):
            if len(sols) > 3000: return
            if i == len(ss): sols.append(list(cur)); return
            for j in range(len(calls)):
                if comp[i][j] and j not in used:
                    used.add(j); cur.append((i, j)); dfs2(i + 1, used, cur); cur.pop(); used.discard(j)
        dfs2(0, set(), [])
        if not sols:
            # the stack-local naming evidence may be wrong (a differently named alias): retry without it
            comp = [[compatible(a, c[3], False) for c in calls] for a, st in ss]
            sols.clear(); dfs2(0, set(), [])
        if sols:
            maps = {tuple(sorted((j, sig_of(i)) for i, j in m)) for m in sols}
            if len(maps) == 1 or '%x' % g in OVERRIDES.get('pairing_ok', []):
                pairs = min(sols, key=lambda m: sum(abs(i - j) for i, j in m))
                extra = sorted(set(range(len(calls))) - {j for i, j in pairs})
                report.append('%x %s: %d matching(s), %s%s' % (g, name, len(sols), 'all give the same words' if len(maps) == 1 else 'closest to address order (checked by hand)', (', C call(s) %s have no stock counterpart (left alone)' % ','.join(map(str, extra))) if extra else ''))
    if pairs is None:
        # (a many-to-one pairing was tried and rejected: the C calls a stock site does not have are not copies of it - the other stock calls have their stores before a join)
        report.append('%x %s: %d stock sites vs %d C calls, no consistent one-to-one pairing - skipped' % (g, name, len(ss), len(calls))); continue
    both = sorted(((ss[i], calls[j]) for i, j in pairs), key=lambda x: x[1][0])      # process in the C's textual order
    ss = [x[0] for x in both]; calls = [x[1] for x in both]
    newbody = []; pos = 0; decls = []; last_group = {}
    nvar = max([int(x) for x in re.findall(r'\biVarS(\d+)\b', body)] + [0])      # earlier runs (other slots) already declared some
    for (a, st), (cs, ai, aj, args) in zip(ss, calls):
        if len(args) == 8 + NWORDS: continue
        if len(args) != 8: report.append('%x %s call at %x: %d C arguments' % (g, name, a, len(args))); continue
        argkeys = {p_: key(g, a, 2 + p_) for p_ in range(1, 9)}
        new = []; ok = True; pre = []
        for k in range(NWORDS):
            off = 0x38 + 4 * k; sr, sa = st[off]
            kk = key(g, sa, sr)          # the value at the store, not at the call: the register may be redefined in between
            ov = OVERRIDES.get('%x' % g, {}).get('%x@%x' % (off, a))
            if ov: new.append(ov); continue
            hit = [p_ for p_, ak in argkeys.items() if ak == kk and ak[0] not in ('deep',)]
            if not hit and kk[0] == 'multi':
                hit = [p_ for p_ in argkeys if argkeys[p_][0] == 'multi' and same_multi(g, a, sr, 2 + p_)]
            if hit: new.append(args[hit[0] - 1]); continue
            e = None
            if kk[0] == 'addi' and kk[2][0] == 'def' and ins[kk[2][1]][0] == 'stwu':
                e = stack_local(g, kk[1] if kk[1] < 0x8000 else kk[1] - 0x10000, body)
            elif kk[0] == 'addi' and kk[2][0] == 'def':
                # a PIC constant: the address the stock computes, named by the symbol map
                for r_ in range(3, 32):
                    pass
                e = pic_expr_for_word(g, a, sa, sr)
            elif kk[0] not in ('multi', 'deep', 'def'):
                e = cexpr(kk)
            elif kk[0] == 'multi':
                pv = phi_var(g, sa, sr, body)
                if pv: new.append(pv); continue
            if e is None: ok = False; report.append('%x %s call %x word %#x: no C expression for %s' % (g, name, a, off, kk)); break
            new.append(('EXPR', kk, e))
        if not ok: continue
        # a computed word becomes a local assigned right before the call; a word whose stock value comes from the same definition(s) as one already
        # computed for an earlier call, with no control flow in the C between the two calls, reuses that local (the stock loads its callee-saved register
        # once; reloading after the intervening calls could see different memory)
        outs = []
        for k, w in enumerate(new):
            if isinstance(w, str): outs.append(w); continue
            _, kk, e = w
            off = 0x38 + 4 * k; sr, sa = st[off]
            ident = (sr, tuple(sorted(str(x) for x in reaching(g).get(sa, {}).get(sr, frozenset()))))
            prev = last_group.get(ident)
            if prev and not re.search(r'[{}]|\b(?:if|else|goto|switch|case|while|for|do|return)\b|LAB_', body[prev[1]:cs]):
                outs.append(prev[0]); continue
            nvar += 1; vn = 'iVarS%d' % nvar; decls.append(vn); pre.append('%s = %s;' % (vn, e)); outs.append(vn)
            last_group[ident] = (vn, aj)
        newbody.append((cs, ai, aj, outs, pre))
    if not newbody: continue
    b2 = body; shift = 0
    ok_nb = []
    for cs, ai, aj, outs, pre in newbody:
        # the call must start a statement (the assignments go right before it): the previous significant character is `;`, `{`, `}` or the `)` / `else` of an unbraced header
        before = re.sub(r'/\*.*?\*/', '', body[:cs], flags=re.S).rstrip()
        pl = before[before.rfind('\n') + 1:]
        if before[-1:] in ';{}' or re.match(r'\s*(?:\}\s*)?(?:else\s*(?:if\b.*\))?|(?:if|while|for)\b.*\))\s*$', pl) or before.endswith('else'): ok_nb.append((cs, ai, aj, outs, pre))
        else: report.append('%x %s: a call inside an expression at C offset %d - left at 8 arguments' % (g, name, cs))
    newbody = ok_nb
    for cs, ai, aj, outs, pre in newbody:
        # the statement start: the beginning of the call's line
        ls = b2.rfind('\n', 0, cs + shift) + 1
        indent = re.match(r'\s*', b2[ls:]).group(0)
        prev_line = b2[b2.rfind('\n', 0, max(ls - 1, 0)) + 1:ls - 1] if ls > 0 else ''
        unbraced = bool(re.match(r'\s*(?:\}\s*)?(?:else\s*(?:if\b.*\))?|(?:if|while|for)\b.*\))\s*$', prev_line)) and not prev_line.rstrip().endswith('{')
        add = ',' + ','.join(outs)
        b2 = b2[:aj + shift] + add + b2[aj + shift:]
        end = b2.index(';', aj + shift + len(add)) + 1 if unbraced else None
        ins_txt = ''.join('%s%s\n' % (indent, s_) for s_ in pre)
        if unbraced:
            b2 = b2[:end] + '\n%s}' % indent + b2[end:]
            ins_txt = '%s{\n' % indent + ins_txt
        b2 = b2[:ls] + ins_txt + b2[ls:]
        shift += len(ins_txt) + len(add) + (len('\n%s}' % indent) if unbraced else 0)
    # declarations: after the last existing local declaration line of the function header
    hm = re.search(r'\{\n((?:  [^\n]*;\n)*)', b2)
    if hm and decls:
        pos_ = hm.end()
        b2 = b2[:pos_] + ''.join('  int %s;\n' % d_ for d_ in decls) + b2[pos_:]
    edits[part] = text[:fs] + b2 + text[fe:]
    report.append('%x %s: %d calls extended, %d new locals' % (g, name, len(newbody), len(decls)))
for l in report: print(l)
if APPLY:
    for part, t in edits.items(): open(os.path.join(corpus, part + '.c'), 'w').write(t)
    print('applied to', sorted(edits))
