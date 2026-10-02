#!/usr/bin/env python3
"""call_args_compare.py STOCK_DIS OURS_DIS   (#85 static audit; `otool -arch ppc -tV` output)

The #80 TODO ("audit other 'literal N' dropped-argument fixes"): per call site, the argument registers r4-r10 whose value is a LITERAL (`li`, or `lis`+`ori`) in the
straight line before the call. For every method the multiset of (callee, literal arguments) of the shipped body is compared with the rebuilt body. Reported: a
literal-argument tuple the shipped code passes to a callee and the rebuild never does (a wrong or dropped constant argument), only for callees both sides call.
Literals that the compiler may legitimately fold, reorder or share between call sites make some hits benign; each hit is read against the disassembly."""
import sys, re, bisect, collections
sdis, odis = sys.argv[1], sys.argv[2]
INS = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
led = [l.rstrip('\n').split('\t') for l in open('Ledger/kext_ppc_ledger.tsv')]
a2s = {int(f[0], 16): (f[5].lstrip('_') if len(f) >= 6 and f[5] else f[4]) for f in led if len(f) >= 5}
ledaddrs = sorted(a2s)
meth = [(f[4], int(f[0], 16), int(f[1]), f[5]) for f in led if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE']
srows = []
for l in open(sdis):
    m = INS.match(l)
    if m: srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
saddr = [r[0] for r in srows]
ofun = {}; cur = None
for l in open(odis):
    s = l.strip()
    if s.endswith(':') and not l.startswith('\t') and not re.match(r'^[0-9a-f]{8}\t', l): cur = s[:-1]; ofun[cur] = []; continue
    m = INS.match(l)
    if m and cur is not None: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
def num(x):
    try: return int(x, 0)
    except ValueError: return None
def literals(rows, k):
    """registers r4..r10 holding a literal at the call at index k (look back up to 16 instructions, stop at a branch target-ish instruction)"""
    val = {}; killed = set()
    for j in range(k - 1, max(-1, k - 17), -1):
        a, op, rest = rows[j]
        ops = [x.strip() for x in rest.split(',')] if rest else []
        if op in ('bl', 'bla', 'jbsr', 'bctrl', 'blr') or (op.startswith('b') and op not in ('bl',)): break
        if not ops or not ops[0].startswith('r'): continue
        r = ops[0]
        if not re.match(r'^r(4|5|6|7|8|9|10)$', r) or r in val or r in killed: continue
        if op == 'li':
            v = num(ops[1]); 
            if v is not None: val[r] = v & 0xffffffff
            else: killed.add(r)            # symbolised literal: unknown
        elif op == 'ori' and len(ops) == 3 and ops[1] == r:
            lo = num(ops[2])
            # find the lis
            hi = None
            for t in range(j - 1, max(-1, j - 8), -1):
                a2, op2, rest2 = rows[t]; o2 = [x.strip() for x in rest2.split(',')] if rest2 else []
                if op2 == 'lis' and o2 and o2[0] == r: hi = num(o2[1]); break
            if lo is not None and hi is not None: val[r] = ((hi << 16) | lo) & 0xffffffff
            else: killed.add(r)
        elif op in ('lis',) or True: killed.add(r)
    return tuple(sorted((r, v) for r, v in val.items()))
def calls(rows, lo=None, hi=None):
    out = collections.Counter()
    for k, (a, op, rest) in enumerate(rows):
        name = None
        if op == 'jbsr': name = rest.split(',')[0].lstrip('_')
        elif op in ('bl', 'bla'):
            t = rest.split()[0] if rest else ''
            name = a2s.get(int(t, 16), t) if t.startswith('0x') else t.lstrip('_')
        if name: out[(name, literals(rows, k))] += 1
    return out
bad = 0; n = 0
for name, a, sz, sym in sorted(meth, key=lambda x: x[1]):
    if sym not in ofun: continue
    nxt = ledaddrs[bisect.bisect_right(ledaddrs, a)] if bisect.bisect_right(ledaddrs, a) < len(ledaddrs) else a + sz
    hi = a + max(sz, nxt - a)
    cs = calls(srows[bisect.bisect_left(saddr, a):bisect.bisect_left(saddr, hi)], a, hi); co = calls(ofun[sym])
    n += 1
    onames = {c for c, _ in co}
    msgs = []
    for (c, lit), cnt in cs.items():
        if not lit or c not in onames: continue
        if co[(c, lit)] == 0:
            # the rebuild passes some literal tuple to this callee, but not this one
            mine = [l for (cc, l), x in co.items() if cc == c]
            msgs.append('%s stock literals %s | rebuilt %s' % (c[:44], ','.join('%s=%d' % (r, v) for r, v in lit), ' / '.join(','.join('%s=%d' % (r, v) for r, v in l) or '-' for l in mine)[:90]))
    if msgs:
        bad += 1; print('%s\n    %s' % (name, '\n    '.join(msgs[:6])))
print('call_args_compare: %d methods compared, %d with a literal argument tuple of the shipped body missing from the rebuild' % (n, bad))
