#!/usr/bin/env python3
"""reg_supply.py STOCK_DIS RANGES_TSV DUMP_DIR ENTRY_HEX REG [DEPTH]      (issue #70, the caller-side half of criterion 2)
   reg_supply.py STOCK_DIS RANGES_TSV DUMP_DIR --all OUT.tsv [DEPTH]     every PASS-indirect / PASS-yes row of inreg_liveness.py

For a function F whose entry register rN is only forwarded (inreg_liveness.py: PASS-*), decide who actually SUPPLIES rN, by walking the direct call
graph upwards. At every direct call site (`bl F`, or a tail `b F` from another function G) a forward may-analysis over G's own RANGES says whether rN
holds
  DEF    a value G wrote itself (li / mr / lwz / a call result ...) on every path to the site: a real argument, the callee's read of it is a real read
  ENTRY  G's own entry value on every path (G never touched rN): the argument is whatever G's caller put there, so the question moves up one level
  MIXED  both, depending on the path
A chain ends at a root (G has no direct caller: only reached through a pointer / table / export): the root supplies rN for real only if G itself reads
the register (inreg_liveness 'real' liveness at G's entry = G has that parameter); otherwise it is leftover garbage.
Verdict for (F, rN):
  SUPPLIED  some path defines it locally (the sites are listed): the C must pass that value - a candidate lost argument
  GARBAGE   every path reaches a root that does not read rN (or a site where nothing ever defined it): the stock forwards leftover register contents;
            the callee's `in_rN` read is not a lost argument
  ROOT-PARAM the only source is a root's own declared parameter (a real argument of an externally called function that F's chain forwards)
Depth-limited (default 6); a truncated chain is reported as DEEP."""
import sys, re, io, importlib.util, contextlib, collections
ARGV = sys.argv[:]
dis, rng, dump = ARGV[1:4]
mode_all = ARGV[4] == '--all'
mode_term = ARGV[4] == '--terminals'
sys.argv = ['inreg_liveness.py', dis, rng, dump]
spec = importlib.util.spec_from_file_location('inreg_liveness', __file__.rsplit('/', 1)[0] + '/inreg_liveness.py')
il = importlib.util.module_from_spec(spec)
with contextlib.redirect_stdout(io.StringIO()): spec.loader.exec_module(il)
ins, rows, ENTRIES = il.ins, il.rows, il.ENTRIES
_VS = None
def _variadic():
    global _VS
    if _VS is None: _VS = {a for n, a in il.label.items() if re.match(r'^__Z.*z$', n)}
    return _VS
il.VARIADIC_SET = _variadic

def call_target(arg):
    """the address a direct call / branch argument names: `0x1234`, or a symbol (an unstripped image prints `_name`) - None for a stub / unknown"""
    a = arg.split(';')[0].strip()
    m = re.match(r'0x([0-9a-f]+)\s*$', a)
    if m: return int(m.group(1), 16)
    if a in il.label: return il.label[a]
    return None

# ---- call-site index: callee entry -> [(site address, calling function entry)]
owner = {}
for ent, iv in rows.items():
    for lo, hi in iv:
        for a in range(lo, hi, 4): owner.setdefault(a, ent)
SITES = collections.defaultdict(list)
for a, (op, arg) in ins.items():
    if op not in ('bl', 'b') or a not in owner: continue
    t = call_target(arg)
    if t is None: continue
    g = owner[a]
    if t in ENTRIES and t != g:          # a `b` into the middle of a function is a branch, into another entry a tail call
        SITES[t].append((a, g))

_fw = {}
def forward(g, r):
    """{site address: (may_entry, may_realdef, may_clobber)} for register r over function g's body, at the instruction's input:
    entry = untouched since g's entry; realdef = written by an ordinary instruction (li / mr / lwz ...; a call's r3 / r4 result counts);
    clobber = last written by a call's clobber of the volatile registers (r5.. hold garbage after a call, the callee's leftovers)"""
    if (g, r) in _fw: return _fw[(g, r)]
    c = il.cls(g)
    if c is None: _fw[(g, r)] = {}; return {}
    lr, lt, la, info, succ = c
    addrs = sorted(info)
    st = {a: [False, False, False] for a in addrs}
    if addrs: st[g if g in st else addrs[0]][0] = True
    changed = True
    while changed:
        changed = False
        for a in addrs:
            d, u, cu, k = info[a]
            if r in d:
                if k == 'call' and r >= 5: o = [False, False, True]        # a call's clobber of r5..r12: leftovers
                else: o = [False, True, False]                              # ordinary write (or a call's r3 / r4 result)
            else: o = st[a]
            for s_ in succ[a]:
                n = [st[s_][i] or o[i] for i in range(3)]
                if n != st[s_]: st[s_] = n; changed = True
    out = {a: tuple(st[a]) for a in addrs}
    _fw[(g, r)] = out
    return out

def supply(f, r, depth, path):
    """set of (kind, detail) leaves for register r at the entry of f"""
    if depth == 0: return {('DEEP', '%x' % f)}
    sites = SITES.get(f, [])
    res = set()
    if not sites:
        c = il.cls(f)
        if c is not None and (r in c[0] or r in c[1]): res.add(('ROOT-PARAM', '%x' % f))
        else: res.add(('ROOT-GARBAGE', '%x' % f))
        return res
    for a, g in sites:
        fw = forward(g, r).get(a)
        if fw is None: res.add(('UNKNOWN', '%x' % a)); continue
        me, md, mc = fw
        if md: res.add(('DEF', '%x in %x' % (a, g)))
        if mc: res.add(('CLOBBER', '%x in %x' % (a, g)))
        if me:
            if g in path: res.add(('ROOT-GARBAGE', '%x (recursive)' % g)); continue
            res |= supply(g, r, depth - 1, path | {f})
    return res

def verdict(leaves):
    kinds = {k for k, _ in leaves}
    if 'DEF' in kinds: return 'SUPPLIED'
    if 'ROOT-PARAM' in kinds: return 'ROOT-PARAM'
    if 'DEEP' in kinds or 'UNKNOWN' in kinds: return 'DEEP'
    return 'GARBAGE'

def block_sets(a):
    """argument registers r3..r10 the straight-line code just before the call at a writes FOR the call: the last write of the register in the block with
    no read of it between that write and the call (a base register a store used, a leftover, is not an argument)"""
    seq = []; b = a - 4; n = 0
    while b in ins and n < 80:
        op, arg = ins[b]
        if op.startswith('b') or op == '.long': break
        seq.append(b); b -= 4; n += 1
    got = set()
    for r in range(3, 11):
        for b in seq:                       # nearest instruction first
            d, u, cu, k = il.du(b)
            if r in d: got.add(r); break    # the last write (an instruction that reads and writes r, `lwz r3,0x354(r3)`, is a write)
            if r in u: break                # read after its last write (walking backwards: a read before we met the write): a temp
    return got

def declared_untouched(g, a):
    """declared parameters of g (read by g's own body) whose entry value is untouched on every path to the call at a"""
    c = il.cls(g)
    if c is None: return set()
    lr, lt, la, info, succ = c
    out = set()
    for r in range(3, 11):
        if (r in lr or r in lt):
            fw = forward(g, r).get(a)
            if fw and fw[0] and not fw[1] and not fw[2]: out.add(r)
    return out

def arity_hint(a, skip=None):
    """the highest argument register the call at a can carry as an argument: set for the call, or a declared parameter forwarded untouched"""
    g = owner.get(a)
    regs = block_sets(a) | (declared_untouched(g, a) if g else set())
    regs.discard(skip)
    return max(regs) if regs else 2

_slot_of = {}
def slot_of(a):
    """the struct offset a call through a pointer loads its target from (`lwz rD,OFF(rB)` ... `mtspr ctr,rD` ... `bctrl`), or None (a computed target)"""
    if a in _slot_of: return _slot_of[a]
    key = None; b = a - 4; n = 0; rd = None
    while b in ins and n < 24:
        op, arg = ins[b]
        if op in ('bl', 'bctrl', 'blr', 'b', 'bctr'): break
        if rd is None and op in ('mtspr', 'mtctr'):
            m = re.match(r'ctr,r(\d+)', arg.replace(' ', ''))
            if m: rd = int(m.group(1))
        elif rd is not None:
            m = re.match(r'r%d,(-?0x[0-9a-f]+|-?\d+)\(r\d+\)' % rd, arg.replace(' ', ''))
            if op == 'lwz' and m: key = int(m.group(1), 0) & 0xffff; break
            if il.du(b)[0] & {rd}: break
        b -= 4; n += 1
    _slot_of[a] = key
    return key

_slot_stats = None
def slot_stats(key):
    """(max, median, number of calling functions) of the argument registers the calls through the struct offset `key` set FOR the call (block_sets;
    the forwarded declared parameters over-count). A slot offset is shared by unrelated structs, so the maximum can only lower a bound (a superset never
    under-counts) and the median is what may raise one."""
    global _slot_stats
    if _slot_stats is None:
        acc = {}
        for a, (op, arg) in ins.items():
            if op == 'bctrl' and a in owner:
                k = slot_of(a)
                if k is not None:
                    bs = block_sets(a); acc.setdefault(k, []).append((max(bs) if bs else 2, owner[a]))
        _slot_stats = {}
        for k, v in acc.items():
            ar = sorted(x for x, _ in v)
            _slot_stats[k] = (ar[-1], ar[len(ar) // 2], len({g for _, g in v}))
    return _slot_stats.get(key)

# GPR slots taken by imports il.ARITY does not know (a double takes two)
EXTRA_ARITY = {'__keymgr_get_and_lock_processwide_ptr': 1, '__keymgr_set_and_unlock_processwide_ptr': 2, '___keymgr_get_and_lock_processwide_ptr': 1,
               '_ecvt': 5, '_fcvt': 5}
def terminals(f, r, depth=10, seen=None):
    """the calls the entry value of r reaches from f, through direct callees that only forward it: (address, text, can_read)
    can_read: the terminal could take r as an argument - a call through a pointer whose argument registers (set for the call, or declared parameters
    forwarded untouched) reach r or above; an import of known arity; a direct callee whose own body reads r; a variadic / unknown callee is 'maybe'"""
    seen = seen if seen is not None else set()
    if f in seen: return []                 # its terminals are already listed
    if depth == 0: return [(f, 'depth limit at %x' % f, 'maybe')]
    seen.add(f)
    c = il.cls(f)
    if c is None: return [(f, 'no ranges for %x' % f, 'maybe')]
    lr, lt, la, info, succ = c
    out = []
    if r in lr: out.append((f, 'READ by the body itself', 'yes'))
    for a in il.sites(f, r, info, succ):
        op, arg = ins[a]
        if op in ('bctrl', 'bctr'):
            k = slot_of(a) if op == 'bctrl' else None
            st = slot_stats(k) if k is not None and slot_stats(k)[2] >= 3 else None      # < 3 calling functions: too few sites to say anything
            h = arity_hint(a, skip=r)
            top = h + 1                                            # r = h+1 is the next argument slot: a forwarded value the callee may take
            if st is not None:
                if st[1] >= r: top = max(top, st[1])              # the typical call through this slot passes r
                top = min(top, st[0])                             # no call through it passes more than st[0] (a superset of this struct's callers)
            out.append((a, '%s%s (argument registers up to r%d)' % (op, ' via +0x%x' % k if k is not None else '', top), 'yes' if r <= top else 'no')); continue
        if 'symbol stub for:' in arg:
            sym = arg.split('symbol stub for:')[1].strip()
            if sym in il.label: out += terminals(il.label[sym], r, depth - 1, seen); continue
            n = EXTRA_ARITY.get(sym, il.ARITY.get(sym))
            out.append((a, '%s %s' % (op, sym), 'maybe' if n is None else ('yes' if r < 3 + n else 'no'))); continue
        t = call_target(arg)
        if t in il.rows:
            if t in il.VARIADIC_SET(): out.append((a, '%s %x variadic' % (op, t), 'maybe'))
            else: out += terminals(t, r, depth - 1, seen)
        else: out.append((a, '%s %s' % (op, arg[:30]), 'maybe'))
    return out

def term_verdict(ts):
    k = {c for _, _, c in ts}
    return 'POSSIBLE-READ' if 'yes' in k else 'POSSIBLE-UNKNOWN' if 'maybe' in k else 'GARBAGE'

if mode_term:
    ent, reg = int(ARGV[5], 16), int(ARGV[6].lstrip('r'))
    ts = terminals(ent, reg)
    print('%x r%d: %s' % (ent, reg, term_verdict(ts)))
    for a, t, c in ts: print('  %s\t%s\t%s' % (a if isinstance(a, str) else '%x' % a, t, c))
elif mode_all:
    out_f, depth = ARGV[5], int(ARGV[6]) if len(ARGV) > 6 else 6
    lv = ARGV[7]      # inreg_liveness.tsv of the image
    n = collections.Counter()
    with open(out_f, 'w') as o:
        for l in open(lv):
            p = l.rstrip('\n').split('\t')
            if len(p) < 4 or not p[3].startswith('PASS') or p[3] in ('PASS-no', 'PASS-vararg'): continue
            f, r = int(p[0], 16), int(p[2].lstrip('r'))
            ts = terminals(f, r)
            v = term_verdict(ts)
            det = '; '.join('%s %s' % ('%x' % a if not isinstance(a, str) else a, t) for a, t, c in ts if c != 'no')
            if v != 'GARBAGE':
                leaves = supply(f, r, depth, frozenset()); sv = verdict(leaves)
                det = 'supply=%s [%s]; %s' % (sv, ' '.join(sorted('%s:%s' % kd for kd in leaves if kd[0] in ('DEF', 'ROOT-PARAM')))[:160], det)
                v = 'GARBAGE-UNSUPPLIED' if sv == 'GARBAGE' else 'CHECK'
            n[v] += 1
            o.write('%s\t%s\tr%d\t%s\t%s\t%s\n' % (p[0], p[1], r, p[3], v, det[:400]))
    print(dict(n))
else:
    ent, reg = int(ARGV[4], 16), int(ARGV[5].lstrip('r'))
    depth = int(ARGV[6]) if len(ARGV) > 6 else 6
    leaves = supply(ent, reg, depth, frozenset())
    print('%x r%d: %s' % (ent, reg, verdict(leaves)))
    for kd in sorted(leaves): print('  %s %s' % kd)
