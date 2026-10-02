#!/usr/bin/env python3
"""result_use_compare.py STOCK_DIS OURS_DIS   (#85 static audit; `otool -arch ppc -tV` output)

Finds DROPPED CALL RESULTS (the class behind #80 and the DVD clientMemoryForType omission): for every call in a shipped body and in the rebuilt body
(jbsr/bl, bctrl, tail b/bctr) it records whether the call's result register r3 is READ before it is overwritten (compare, copy, store, arithmetic, or returned
straight through a blr), then compares per method the multiset of (callee, result-used). A call whose result the shipped code uses and the rebuild ignores
(stock R=1, rebuilt R=0) is a candidate lost statement - typically a Ghidra signature that typed the callee `void`.
Reports only differences of that kind; extra uses on the rebuilt side are ignored (the compiler may copy results it does not need)."""
import sys, re, bisect, collections
sdis, odis = sys.argv[1], sys.argv[2]
INS = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
led = [l.rstrip('\n').split('\t') for l in open('Ledger/kext_ppc_ledger.tsv')]
a2s = {int(f[0], 16): (f[5].lstrip('_') if len(f) >= 6 and f[5] else f[4]) for f in led if len(f) >= 5}
ledaddrs = sorted(a2s)
meth = [(f[4], int(f[0], 16), int(f[1]), f[5]) for f in led if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE']
srows = []; stub = {}
for l in open(sdis):
    m = INS.match(l)
    if m:
        srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
        if m.group(2) == 'jbsr' and ',' in m.group(3): nm, st = m.group(3).split(',', 1); stub[int(st, 16)] = nm.lstrip('_')
saddr = [r[0] for r in srows]
ofun = {}; cur = None
for l in open(odis):
    s = l.strip()
    if s.endswith(':') and not l.startswith('\t') and not re.match(r'^[0-9a-f]{8}\t', l): cur = s[:-1]; ofun[cur] = []; continue
    m = INS.match(l)
    if m and cur is not None: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
STORE_DEST = ('stw', 'stb', 'sth', 'stwx', 'stwu', 'stbx', 'sthx')
def regs_read(op, ops):
    """registers read by the instruction (approximation sufficient for r3)"""
    if not ops: return set()
    names = set(re.findall(r'\br(\d+)\b', ' '.join(ops)))
    if op in STORE_DEST: return names                           # source and base both read
    if op.startswith('cmp') or op in ('mtspr', 'mtctr', 'mtlr'): return names
    if op in ('lwz', 'lbz', 'lhz', 'lha', 'lwzu', 'lbzu', 'lhzu', 'lfs', 'lfd', 'lwzx', 'lbzx', 'lhzx'): return set(re.findall(r'\((r\d+)\)', ops[-1])) | (names - {re.match(r'r(\d+)', ops[0]).group(1)} if ops[0].startswith('r') and 'x' in op else set())
    if op in ('li', 'lis'): return set()
    return names - ({re.match(r'r(\d+)', ops[0]).group(1)} if ops[0].startswith('r') else set()) | (set(re.findall(r'\br(\d+)\b', ' '.join(ops[1:]))) if ops and ops[0].startswith('r') else set())
def writes(op, ops):
    if not ops or not ops[0].startswith('r') or op in STORE_DEST or op.startswith('cmp') or op.startswith('b') or op in ('mtspr', 'mtctr', 'mtlr', 'sync', 'isync', 'nop'): return None
    return re.match(r'r(\d+)', ops[0]).group(1)
def uses(rows, k):
    """True if r3 (the call result) is read before it is overwritten, within the next 8 instructions of the straight line"""
    for j in range(k + 1, min(k + 9, len(rows))):
        a, op, rest = rows[j]
        ops = [x.strip() for x in rest.split(',')] if rest else []
        if op in ('blr', 'beqlr', 'bnelr', 'bltlr', 'bgtlr'): return True          # returned
        if op in ('b', 'bctr'): return False        # unconditional jump: the straight line ends here (a conditional branch falls through and is followed)
        rd = regs_read(op, ops)
        if '3' in rd: return True
        w = writes(op, ops)
        if w == '3': return False
        if op in ('bl', 'bla', 'jbsr', 'bctrl'): return False
    return False
def calls(rows, lo=None, hi=None):
    out = collections.Counter()
    for k, (a, op, rest) in enumerate(rows):
        name = None
        if op == 'jbsr': name = rest.split(',')[0].lstrip('_')
        elif op in ('bl', 'bla'):
            t = rest.split()[0] if rest else ''
            name = a2s.get(int(t, 16), t) if t.startswith('0x') else t.lstrip('_')
        elif op == 'bctrl': name = '<vtable>'
        elif op == 'b' and rest:
            t = rest.split()[0]
            if not t.startswith('0x'): out[(t.lstrip('_'), True)] += 1; continue      # tail call: result is the function's result
            if lo is not None and not (lo <= int(t, 16) < hi) and (int(t, 16) in a2s or int(t, 16) in stub):
                out[(a2s.get(int(t, 16)) or stub[int(t, 16)], True)] += 1
            continue
        if name: out[(name, uses(rows, k))] += 1
    return out
bad = 0; n = 0
for name, a, sz, sym in sorted(meth, key=lambda x: x[1]):
    if sym not in ofun: continue
    nxt = ledaddrs[bisect.bisect_right(ledaddrs, a)] if bisect.bisect_right(ledaddrs, a) < len(ledaddrs) else a + sz
    hi = a + max(sz, nxt - a)
    srng = srows[bisect.bisect_left(saddr, a):bisect.bisect_left(saddr, hi)]
    cs, co = calls(srng, a, hi), calls(ofun[sym])
    n += 1
    # per callee: how many call sites use the result in stock vs rebuilt
    names = {c for c, _ in cs} | {c for c, _ in co}
    msgs = []
    for c in sorted(names):
        su, ou = cs[(c, True)], co[(c, True)]
        st, ot = su + cs[(c, False)], ou + co[(c, False)]
        if ot < st: continue          # rebuilt merges call sites: judged by callee_compare, not here
        if su > ou: msgs.append('%s: result used %dx in stock, %dx in rebuild (calls %d/%d)' % (c[:48], su, ou, st, ot))
    if msgs:
        bad += 1; print('%s\n    %s' % (name, '\n    '.join(msgs)))
print('result_use_compare: %d methods compared, %d with a call result used in the shipped body but not in the rebuild' % (n, bad))
