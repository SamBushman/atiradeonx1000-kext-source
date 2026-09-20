#!/usr/bin/env python3
"""check_import_binding.py STOCK_DIS OURS_DIS LEDGER_TSV - per function, compare the multiset of dyld-stub (import) calls by MANGLED name between the
stock image and the rebuilt one. Ghidra prints overloads and template instances under one demangled name, so the corpus can bind a call to a same-named
function of another class/instance (`std::string::_M_replace_safe` vs the pool_allocator basic_string's); callee_compare_c.py has to compare such names
loosely. The mangled symbol in the stub comment is exact. DIS files are `otool -tV` (+ `-s __TEXT __textcoal_nt -v`) of each image.
Rows: FUNCTION <name> stock-only: {...} ours-only: {...}."""
import sys, re, collections, bisect
sdis, odis, ledger = sys.argv[1:4]
ins = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
funcs = []
for l in open(ledger):
    f = l.rstrip('\n').split('\t')
    funcs.append((int(f[0], 16), int(f[1]), f[2], f[4]))
funcs.sort()
srows = []
for l in open(sdis):
    m = ins.match(l)
    if m: srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
srows.sort()
saddr = [r[0] for r in srows]
stubs = collections.Counter
names_at = {a: n for a, sz, n, st in funcs}
with open(ledger) as _f: pass
def own_names(a, sz): return set()
stock = {}
for a, sz, n, st in funcs:
    i = bisect.bisect_left(saddr, a); j = bisect.bisect_left(saddr, a + sz)
    c = stubs()
    for _, op, rest in srows[i:j]:
        if op in ('bl', 'b'):
            m = re.search(r'symbol stub for:\s*(\S+)', rest)
            if m: c[m.group(1)] += 1
            else:
                mt = re.match(r'0x([0-9a-f]+)', rest); ms = re.match(r'([A-Za-z_\$][\w\$\.]*)', rest)
                if mt: tgt = names_at.get(int(mt.group(1), 16))
                elif ms and not re.match(r'^L\d', ms.group(1)): tgt = ms.group(1)
                else: tgt = None
                if tgt and tgt != n and not (op == 'b' and tgt in own_names(a, sz)): c[tgt] += 1
    stock[n] = c
ours = {}; cur = None
for l in open(odis):
    s = l.strip()
    if re.match(r'^[^\s:]+:$', s) and not l[0].isdigit() and not l.startswith(('\t', '(')):
        cur = s[:-1]; ours[cur] = stubs(); continue
    m = ins.match(l)
    if m and cur and m.group(2) in ('bl', 'b'):
        mm = re.search(r'symbol stub for:\s*(\S+)', m.group(3))
        if mm: ours[cur][mm.group(1)] += 1
        else:
            ms = re.match(r'([A-Za-z_\$][\w\$\.]*)', m.group(3))
            if ms and not re.match(r'^L\d', ms.group(1)) and ms.group(1) != cur and not (m.group(2) == 'b'): ours[cur][ms.group(1)] += 1
bad = 0
for a, sz, n, st in funcs:
    if n not in ours: continue
    s, o = stock[n], ours[n]
    so = s - o; os_ = o - s
    # a stock call that is a tail call to a stub counts once in both; extra calls in ours are compiler helpers
    so = collections.Counter({k: v for k, v in so.items() if not k.startswith(('__ZN9__gnu_cxx', 'restFP', 'saveFP'))})
    if so or os_:
        bad += 1; print('FUNCTION', n, hex(a), 'stock-only:', dict(so), 'ours-only:', dict(os_))
print('functions compared: %d, differing: %d' % (sum(1 for a, sz, n, st in funcs if n in ours), bad))
