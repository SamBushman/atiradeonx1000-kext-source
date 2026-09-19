#!/usr/bin/env python3
"""callee_compare_c.py STOCK_DIS OURS_DIS LEDGER_TSV - per function, compare the multiset of direct callees (functions by name via the
ledger address map, dyld stubs by imported name) and the number of indirect calls (bctrl) between the stock PPC binary and the
corpus compiled -O0. Tail calls (b to another function/stub) in stock count as calls."""
import sys, re, bisect, collections
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
def norm(n):
    n = re.sub(r'^thunk_', '', n); n = re.sub(r'^L?_*', '', n); n = re.sub(r'\$(stub|non_lazy_ptr|lazy_ptr)$', '', n); return re.sub(r'[^A-Za-z0-9_]', '_', n)
ins = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
srows = []
for l in open(sdis):
    m = ins.match(l)
    if m: srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
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
    _mc[t] = res; return res
def stock_callees(a, sz):
    c = collections.Counter()
    rng = franges.get(a) or [(a, a + sz)]
    for lo, hi in rng:
        i = bisect.bisect_left(saddr, lo); j = bisect.bisect_left(saddr, hi)
        for _, op, rest in srows[i:j]:
            if op == 'bctrl': c['<indirect>'] += 1; continue
            if op in ('bl', 'b'):
                m = re.match(r'0x([0-9a-f]+)(?:\s*;\s*symbol stub for:\s*(\S+))?', rest)
                if not m: continue
                t = int(m.group(1), 16)
                if m.group(2) or int(m.group(1), 16) in stubname: c[norm(m.group(2) or stubname[int(m.group(1), 16)])] += 1
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
            sm = re.search(r'(?:ha16|lo16)\(_?([A-Za-z_]\w*)|,_?(FUN_[0-9a-f]{8}|[A-Za-z]\w*)\(r\d+\)', rest)
            g = (sm.group(1) or sm.group(2)) if sm else None
            if g and (g.startswith(('FUN_', 'part_')) or norm(g) in fnames): lastsym = norm(g); idx_since = 0
            else: idx_since += 1
HELPERS = {'cmpdi2','ucmpdi2','floatdidf','floatundidf','fixdfdi','fixunsdfdi','ashldi3','lshrdi3','ashrdi3','muldi3','divdi3','udivdi3','moddi3','umoddi3','floatdisf','fixsfdi','storeWordConditionalIndexed','Unwind_Resume','builtin_strncpy','bzero','memmove'}
ALIAS = {'bzero': 'memset', 'memmove': 'memcpy', 'ZdlPv': 'operator_delete', 'ZdaPv': 'operator_delete__', 'Znwm': 'operator_new', 'Znam': 'operator_new__', 'ZdlPvRKSt9nothrow_t': 'operator_delete', 'ZnwmRKSt9nothrow_t': 'operator_new'}
def clean(c, self_n):
    r = collections.Counter()
    for k, v in c.items():
        if k in ('cmpdi2','ucmpdi2','floatdidf','floatundidf','fixdfdi','fixunsdfdi','ashldi3','lshrdi3','ashrdi3','muldi3','divdi3','udivdi3','moddi3','umoddi3','floatdisf','fixsfdi','Unwind_Resume') or k == self_n or k in HELPERS: continue
        if k == '<indirect>': continue
        r[ALIAS.get(k, k)] += v
    return r
rows = []; skipped = 0
for a, sz, name, st in funcs:
    if st.startswith('DECOMPILE-ONLY') or sz == 0: skipped += 1; continue
    n = norm(name)
    if n not in ours: continue
    cs = clean(stock_callees(a, sz), n); co = clean(ours[n], n)
    # -O0 introduces no direct-call differences for direct calls; indirect calls may come from PIC/data-pointer idioms
    only_s = {k: v for k, v in cs.items() if k not in co}; only_o = {k: v for k, v in co.items() if k not in cs}
    if only_s or only_o: rows.append((len(only_s) + len(only_o), name, only_s, only_o))
rows.sort(reverse=True)
print('%d functions compared, %d with functions whose callee SETS differ (%d skipped)' % (len(funcs) - skipped, len(rows), skipped))
for r in rows[:400]: print(r[0], r[1], 'STOCK-ONLY', r[2], 'OURS-ONLY', r[3])
