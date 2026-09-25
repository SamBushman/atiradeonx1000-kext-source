#!/usr/bin/env python3
"""callee_compare_c.py STOCK_DIS OURS_DIS LEDGER_TSV - per function, compare the multiset of direct callees (functions by name via the
ledger address map, dyld stubs by imported name) and the number of indirect calls (bctrl) between the stock PPC binary and the
corpus compiled -O0. Tail calls (b to another function/stub) in stock count as calls."""
import sys, re, bisect, collections, os
sdis, odis, ledger = sys.argv[1:4]
franges = {}; thunknames = {}
if len(sys.argv) > 4:
    for l in open(sys.argv[4]):
        f = l.rstrip('\n').split('\t')
        if len(f) > 3 and f[2] == 'thunk': thunknames[int(f[0], 16)] = f[1]
        if len(f) > 3 and f[2] == 'fn': franges[int(f[0], 16)] = [tuple(int(x, 16) for x in r.split('-')) for r in f[3].split(';') if r]
funcs = []   # (addr, size, name, status)
for l in open(ledger):
    f = l.rstrip('\n').split('\t')
    funcs.append((int(f[0], 16), int(f[1]), f[2], f[4]))
funcs.sort()
next_start = {funcs[i][0]: (funcs[i+1][0] if i + 1 < len(funcs) else funcs[i][0] + funcs[i][1]) for i in range(len(funcs))}
starts = {a: n for a, sz, n, st in funcs}
stubname = {}
LOOSE_NAMES = bool(os.environ.get('LOOSE_NAMES'))
def loose(n):
    """C++ corpus: Ghidra prints a member call without its class (`error(...)`) and constructors/overloads share one printed name, so compare
    callees by their final component with the per-address disambiguation suffix removed"""
    n = re.sub(r'_[0-9a-f]{8}$', '', n)
    n = re.sub(r'^_+', '', n)
    parts = [x for x in re.split(r'__+', n) if x]
    return parts[-1] if parts else n
def norm(n):
    n = re.sub(r'^L?_*', '', n); n = re.sub(r'^thunk_', '', n); n = re.sub(r'^L?_*', '', n); n = re.sub(r'\$(stub|non_lazy_ptr|lazy_ptr)$', '', n); return re.sub(r'[^A-Za-z0-9_]', '_', n)
ins = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
srows = []; label_addr = {}; _pl = None
for l in open(sdis):
    m = ins.match(l)
    if m:
        srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
        if _pl: label_addr.setdefault(_pl, int(m.group(1), 16)); _pl = None
    else:
        s_ = l.strip()
        if s_.endswith(':') and not s_.startswith(('/', '(')) and ' ' not in s_: _pl = s_[:-1]
srows.sort(key=lambda r: r[0])
for k, v in thunknames.items(): stubname.setdefault(k, re.sub(r'^thunk_', '', re.sub(r'^<EXTERNAL>::', '', v)))
for _, op, rest in srows:
    m = re.match(r'0x([0-9a-f]+)\s*;\s*symbol stub for:\s*(\S+)', rest)
    if m: stubname[int(m.group(1), 16)] = m.group(2)
saddr = [r[0] for r in srows]
fsz = {a: sz for a, sz, n, st in funcs}
_mc = {}
def is_millicode(t):
    if t in _mc: return _mc[t]
    sz = fsz.get(t, 0); res = False
    if 0 < sz <= 0x120:
        i = bisect.bisect_left(saddr, t); j = bisect.bisect_left(saddr, t + sz); ops = srows[i:j]
        saves = [1 for _, op, r in ops if op in ('stfd', 'lfd', 'stw', 'lwz', 'stmw', 'lmw') and re.match(r'^[rf](1[3-9]|2\d|3[01])', r)]
        bad = [1 for _, op, r in ops if op in ('bl', 'bc', 'bdnz', 'cmpwi', 'cmplwi', 'cmpw', 'beq', 'bne', 'blt', 'bgt', 'ble', 'bge', 'bctrl')]
        res = len(saves) >= 3 and not bad
        # a mid-entry piece of saveFP/restFP that Ghidra split off (GLDriver FUN_001a3254 = `stfd f24,-0x40(r1)`, 4 bytes, falling into the next
        # piece): nothing but callee-saved register saves/restores, the LR word and the return
        if not res and ops and all((op in ('stfd', 'lfd') and re.match(r'^f(1[4-9]|2\d|3[01]),', r)) or (op in ('stw', 'lwz') and r.startswith('r0,0x8(r1)'))
                                   or (op == 'mtspr' and r.startswith('lr,')) or op == 'blr' for _, op, r in ops):
            res = True
    _mc[t] = res; return res
def stock_callees(a, sz):
    return count_range(franges.get(a) or [(a, a + sz)])
import bisect as _bs
_own = None
def in_owned(t):
    global _own
    if _own is None:
        iv = sorted((lo, hi) for a_, sz_, n_, st_ in funcs for lo, hi in (franges.get(a_) or [(a_, a_ + sz_)])); _own = ([l for l, h in iv], [h for l, h in iv])
    k = _bs.bisect_right(_own[0], t) - 1
    while k >= 0 and k > _bs.bisect_right(_own[0], t) - 40:
        if _own[0][k] <= t < _own[1][k]: return True
        k -= 1
    return False
def count_range(rng):
    c = collections.Counter()
    for lo, hi in rng:
        i = bisect.bisect_left(saddr, lo); j = bisect.bisect_left(saddr, hi)
        for _, op, rest in srows[i:j]:
            if op == 'bctrl': c['<indirect>'] += 1; continue
            if op in ('bl', 'b'):
                m = re.match(r'0x([0-9a-f]+)(?:\s*;\s*symbol stub for:\s*(\S+))?', rest)
                if not m:
                    # symbolised target (an unstripped binary): `bl _name` / `b _name`
                    ms = re.match(r'([A-Za-z_\$][\w\$\.]*)', rest)
                    if ms and not re.match(r'^L\d', ms.group(1)):
                        t_ = ms.group(1)
                        if t_ in label_addr and label_addr[t_] in starts: t_ = starts[label_addr[t_]]   # a mangled symbol -> the ledger's (demangled) name for that address
                        if op == 'bl' or not any(norm(t_) == norm(starts.get(l2, '')) for l2, h2 in rng): c[norm(t_)] += 1
                    continue
                t = int(m.group(1), 16)
                if m.group(2) or int(m.group(1), 16) in stubname:
                    sn_ = m.group(2) or stubname[int(m.group(1), 16)]
                    if sn_ in label_addr and label_addr[sn_] in starts: sn_ = starts[label_addr[sn_]]   # a symbol this binary defines, called through its own PIC stub
                    c[norm(sn_)] += 1
                elif t not in starts and not in_owned(t): c['func_0x%08x' % t] += 1   # a call to an unnamed stub/import address (outside all function bodies)
                elif t in starts and not is_millicode(t):
                    if op == 'bl' or not any(l2 <= t < h2 for l2, h2 in rng): c[norm(starts[t])] += 1
    return c
ours = {}; cur = None; lastsym = None; idx_since = 99
fnames = {norm(n) for a, sz, n, st in funcs}
for l in open(odis):
    if re.match(r'^\S+:$', l.strip()) and not l.startswith(('\t', '(')) and not l[0].isdigit() and not l.startswith('part_'):
        cur = norm(l.strip()[:-1]); ours[cur] = collections.Counter(); lastsym = None; continue
    m = ins.match(l)
    if m and cur:
        op, rest = m.group(2), m.group(3)
        if op == 'bl' or op == 'b':
            am = re.search(r'symbol stub for:\s*(\S+)', rest)
            t = rest.split(',')[0].split()[0]
            if am: ours[cur][norm(am.group(1))] += 1
            elif not t.startswith('0x') and not re.match(r'^L\d', t): ours[cur][norm(t)] += 1
        elif op == 'bctrl':
            if lastsym and idx_since <= 8: ours[cur][lastsym] += 1     # ((int (*)())FUN)(...) : address materialised then bctrl
            else: ours[cur]['<indirect>'] += 1
            lastsym = None
        else:
            sm = re.search(r'(?:ha16|lo16)\(_?([A-Za-z_]\w*)', rest)   # (a bare  displacement is otool symbolising a 0 offset, not an address)
            g = sm.group(1) if sm else None
            if g and (g.startswith(('FUN_', 'part_')) or norm(g) in fnames): lastsym = norm(g); idx_since = 0
            else: idx_since += 1
HELPERS = {'vectorPermute','vectorConditionalSelect','dataCacheBlockClearToZero','dataCacheBlockAllocate','fixunssfdi','fixunsdfdi','fixsfdi','cmpdi2','ucmpdi2','floatdidf','floatundidf','fixdfdi','fixunsdfdi','ashldi3','lshrdi3','ashrdi3','muldi3','divdi3','udivdi3','moddi3','umoddi3','floatdisf','fixsfdi','storeWordConditionalIndexed','Unwind_Resume','builtin_strncpy','bzero','memmove'}
ALIAS = {'bzero': 'memset', 'memmove': 'memcpy', 'ZdlPv': 'operator_delete', 'ZdaPv': 'operator_delete__', 'Znwm': 'operator_new', 'Znam': 'operator_new__', 'ZdlPvRKSt9nothrow_t': 'operator_delete', 'ZnwmRKSt9nothrow_t': 'operator_new'}
mill_names = {norm(n) for a, sz, n, st in funcs if is_millicode(a)}   # register save/restore millicode: Ghidra shows the prologue helper as a call, the stock compiler inlines it
def is_stub(a, sz):
    """a dyld/picsymbol stub: <= 0x40 bytes, ends in an indirect branch, no direct call - Ghidra models it as a call to the import."""
    if sz > 0x40: return False
    i = bisect.bisect_left(saddr, a); j = bisect.bisect_left(saddr, a + sz); ops = [op for _, op, r in srows[i:j]]
    return 'bctr' in ops and not any(o in ('bl', 'bctrl') for o in ops)
def clean(c, self_n):
    r = collections.Counter()
    for k, v in c.items():
        if k in ('cmpdi2','ucmpdi2','floatdidf','floatundidf','fixdfdi','fixunsdfdi','ashldi3','lshrdi3','ashrdi3','muldi3','divdi3','udivdi3','moddi3','umoddi3','floatdisf','fixsfdi','Unwind_Resume') or k == self_n or k in HELPERS: continue
        if k == '<indirect>' or k in mill_names or re.match(r'^(?:saveFP|restFP|savef|restf)_0x[0-9a-f]+$', k): continue   # the recompile's own register save/restore millicode calls
        mm_ = re.match(r'func_0x([0-9a-f]+)$', k)
        if mm_:   # an entry into the middle of register save/restore millicode
            t_ = int(mm_.group(1), 16); k_ = bisect.bisect_right(fstarts, t_) - 1
            if k_ >= 0 and is_millicode(fstarts[k_]): continue
        k2 = ALIAS.get(k, k)
        r[loose(k2) if LOOSE_NAMES else k2] += v
    return r
fstarts = sorted(starts)
def region_of(t):
    """the stock code a jump to `t` runs into: the whole function if `t` is a function start, otherwise from `t` to the end of the function containing it"""
    for d_ in (4, 8):   # a jump to the instruction(s) just before a function start: the entry Ghidra clipped (mfcr/mflr saved before the recorded start)
        if t not in starts and t + d_ in starts and not any(t <= s < t + d_ for s in fstarts): t = t + d_; break
    if t in starts: return franges.get(t) or [(t, t + fsize.get(t, 4))]
    k = bisect.bisect_right(fstarts, t) - 1
    if k < 0: return []
    f = fstarts[k]; rs = franges.get(f) or [(f, f + fsize.get(f, 4))]
    r = [(max(lo, t), hi) for lo, hi in rs if hi > t]
    if r: return r
    # code no Ghidra function owns (a shared tail placed between functions): from `t` up to the next function start
    nx = fstarts[k + 1] if k + 1 < len(fstarts) else t
    return [(t, nx)] if nx > t else []
def jump_targets(rng):
    out = set()
    for lo, hi in rng:
        i = bisect.bisect_left(saddr, lo); j = bisect.bisect_left(saddr, hi)
        for _, op, rest in srows[i:j]:
            if op == 'b':
                m = re.match(r'0x([0-9a-f]+)', rest); t = None
                if m: t = int(m.group(1), 16)
                else:
                    ms = re.match(r'([A-Za-z_\$][\w\$\.]*)', rest)
                    if ms and ms.group(1) in label_addr: t = label_addr[ms.group(1)]
                if t is not None and not any(l2 <= t < h2 for l2, h2 in rng) and t not in stubname: out.add(t)
        if j > i and srows[j - 1][1] not in ('b', 'blr', 'bctr', 'trap', 'tw', 'twi') and not any(l2 <= hi < h2 for l2, h2 in rng): out.add(hi)   # falls through into the next code
    return out
fsize = {a: sz for a, sz, n, st in funcs}
owned = sorted((lo, hi) for a_, sz_, n_, st_ in funcs for lo, hi in (franges.get(a_) or [(a_, a_ + sz_)]))
def unowned_between(lo, hi):
    """pieces of [lo, hi) that no Ghidra function claims (switch-case blocks reached through a recovered jump table)"""
    out = []; cur = lo
    for l2, h2 in owned:
        if h2 <= cur: continue
        if l2 >= hi: break
        if l2 > cur: out.append((cur, l2))
        cur = max(cur, h2)
    if cur < hi: out.append((cur, hi))
    return out
def has_jumptable(rng):
    for lo, hi in rng:
        i = bisect.bisect_left(saddr, lo); j = bisect.bisect_left(saddr, hi)
        if any(op == 'bctr' for _, op, _r in srows[i:j]): return True
    return False
def closure(a, depth=int(os.environ.get("CLOSURE_DEPTH", "4"))):
    """callees of the function plus, recursively, of all code it jumps into with a plain `b` (Ghidra attributes shared tails to either owner)"""
    rng0 = franges.get(a) or [(a, a + fsize.get(a, 4))]
    allc = collections.Counter(count_range(rng0)); names = set(); seen = set(); todo = [rng0]; d = 0
    if has_jumptable(rng0):   # case blocks that no function claims, inside the function's own span
        for g in unowned_between(min(l for l, h in rng0), max(h for l, h in rng0)): allc.update(count_range([g]))
    while todo and d < depth:
        nxt = []
        for rng in todo:
            for t in jump_targets(rng):
                if t in seen: continue
                seen.add(t)
                if t in starts: names.add(norm(starts[t]))
                r2 = region_of(t)
                if r2: allc.update(count_range(r2)); nxt.append(r2)
        todo = nxt; d += 1
    return allc, names
benign = []
_gapall = None
def gap_callees():
    """callees made from code no function owns anywhere in the binary (case blocks / landing pads): an extra callee in ours that lives only there is real code"""
    global _gapall
    if _gapall is None:
        c = collections.Counter(); lo_ = min(l for l, h in owned); hi_ = max(h for l, h in owned)
        for g in unowned_between(lo_, hi_): c.update(count_range([g]))
        _gapall = set(clean(c, ''))
    return _gapall
rows = []; skipped = 0
for a, sz, name, st in funcs:
    if st.startswith('DECOMPILE-ONLY') or sz == 0: skipped += 1; continue
    n = norm(name)
    if n not in ours: continue
    if is_stub(a, sz): skipped += 1; continue
    cs = clean(stock_callees(a, sz), n); co = clean(ours[n], n)
    # -O0 introduces no direct-call differences for direct calls; indirect calls may come from PIC/data-pointer idioms
    only_s = {k: v for k, v in cs.items() if k not in co}; only_o = {k: v for k, v in co.items() if k not in cs}
    if only_s or only_o:
        ext, tnames = closure(a); ext = clean(ext, n)
        if LOOSE_NAMES: tnames = {loose(x) for x in tnames}
        # shared code: ours may call MORE (it inlines the tail/case blocks Ghidra attributes to this function) as long as every extra callee is
        # called somewhere in the code stock reaches from here; stock calling something ours never does is only acceptable for the tail-call
        # edge itself (`b sibling`), never for a real callee - that would be a dropped call
        if not [k for k in only_s if k not in tnames] and all(k in ext or k in gap_callees() for k in only_o):
            benign.append((name, only_s, only_o)); continue
        rows.append((len(only_s) + len(only_o), name, only_s, only_o))
# second, stricter view (informational): a callee the stock function calls MORE often than the recompiled decompile does can mean a dropped
# branch/switch body (the decompiler's recovered flow lost it); ours calling more is normal (shared tails, duplicated code)
low = []
for a_, sz_, name_, st_ in funcs:
    n_ = norm(name_)
    if st_.startswith('DECOMPILE-ONLY') or sz_ == 0 or n_ not in ours or is_stub(a_, sz_): continue
    ext_, _t = closure(a_); cs_ = clean(ext_, n_); co_ = clean(ours[n_], n_)
    d_ = {k: (v, co_.get(k, 0)) for k, v in stock_callees(a_, sz_).items() if k in clean(stock_callees(a_, sz_), n_) and v > co_.get(k, 0) and cs_.get(k, 0) > co_.get(k, 0)}
    if d_: low.append((name_, d_))
# third view: switch-case blocks that no function owns, sitting inside a jump-table function's own span. They are transcribed only if the
# decompiler recovered the switch; a callee found there that the recompile never calls is a lost case body
gapmiss = []
for a_, sz_, name_, st_ in funcs:
    n_ = norm(name_)
    if st_.startswith('DECOMPILE-ONLY') or sz_ == 0 or n_ not in ours or is_stub(a_, sz_): continue
    rng_ = franges.get(a_) or [(a_, a_ + sz_)]
    if not has_jumptable(rng_): continue
    gc = collections.Counter()
    for g in unowned_between(min(l for l, h in rng_), max(h for l, h in rng_)):
        cg = count_range([g])
        if 'Unwind_Resume' in cg: continue   # a C++ exception landing pad: reachable only through the unwinder, no decompile can contain it
        # a cleanup pad that runs a destructor and then branches to the shared `_Unwind_Resume` sequence (GLDriver FUN_000f94dc: `bl dtor; b 0xf9924`,
        # 0xf9924 = `or r3,r27,r27; bl _Unwind_Resume`) - transcribed as a landing-pad companion function, not a case
        i_ = bisect.bisect_left(saddr, g[1]) - 1
        mb_ = re.match(r'0x([0-9a-f]+)', srows[i_][2]) if 0 <= i_ < len(srows) and srows[i_][1] == 'b' else None
        if mb_ and 'Unwind_Resume' in count_range([(int(mb_.group(1), 16), int(mb_.group(1), 16) + 16)]): continue
        gc.update(cg)
    gc = clean(gc, n_); co_ = clean(ours[n_], n_)
    miss = {k: v for k, v in gc.items() if k not in co_ and not k.startswith('func_0x')}   # func_0x..: a `bl` from one unowned block into another, not a named callee
    if miss: gapmiss.append((name_, miss))
print('SWITCH-GAPS: %d jump-table functions with a callee in their unowned case blocks that the recompile never calls' % len(gapmiss))
for nm_, m_ in gapmiss[:int(os.environ.get('GAPN', '40'))]: print('  ', nm_, dict(list(m_.items())[:8]))
if os.environ.get('SHOWLOW') or True:
    print('LOWCOUNT: %d functions where stock calls some callee more often than the recompile (info)' % len(low))
    for nm_, d_ in low[:int(os.environ.get('LOWN', '0'))]: print('  ', nm_, d_)
rows.sort(reverse=True)
print('%d functions compared, %d with functions whose callee SETS differ (%d skipped; %d more differ only through shared tail code)' % (len(funcs) - skipped, len(rows), skipped, len(benign)))
for r in rows[:400]: print(r[0], r[1], 'STOCK-ONLY', r[2], 'OURS-ONLY', r[3])
