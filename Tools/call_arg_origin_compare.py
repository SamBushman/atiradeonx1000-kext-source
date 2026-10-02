#!/usr/bin/env python3
"""call_arg_origin_compare.py STOCK_DIS OURS_DIS   (#85 static audit; `otool -arch ppc -tV` output)

Shifted / swapped call arguments (the alloc_surfaces_retry bug: the decompile passed `this` as a leading argument, so the callee got `this` as its mask and the
real mask as its second argument). For every call the argument registers r3-r8 are traced back to the function's INCOMING arguments through register copies
(`or rX,rY,rY`, `mr`, saved in r13-r31 in the prologue). Per method and callee the multiset of "which incoming argument feeds which outgoing register" is
compared; a pattern of the shipped body that the rebuild never uses (while both call the callee) is reported. Arguments computed from memory are ignored."""
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
def reg(x):
    m = re.match(r'^r(\d+)$', x.strip()); return int(m.group(1)) if m else None
def prologue_alias(rows):
    """nonvolatile reg -> incoming arg (3..10) for `or rN,rA,rA` executed before the first call/branch, if rN is not rewritten before the first call"""
    al = {}
    for a, op, rest in rows[:40]:
        ops = [x.strip() for x in rest.split(',')] if rest else []
        if op in ('bl', 'bla', 'jbsr', 'bctrl') or (op.startswith('b') and op != 'bl'): break
        if op in ('or', 'mr') and len(ops) >= 2:
            d, s = reg(ops[0]), reg(ops[1])
            if d is not None and s is not None and (op == 'mr' or len(ops) < 3 or ops[1] == ops[2]):
                if s in range(3, 11) and d >= 13: al[d] = s
                elif s in al and d >= 13: al[d] = al[s]
    return al
def origins(rows, k, al):
    out = {}
    for tgt in (3, 4, 5, 6, 7, 8):
        r = tgt
        for j in range(k - 1, max(-1, k - 14), -1):
            a, op, rest = rows[j]
            ops = [x.strip() for x in rest.split(',')] if rest else []
            if op in ('bl', 'bla', 'jbsr', 'bctrl') or (op.startswith('b') and op != 'bl'): r = None; break
            if not ops or reg(ops[0]) != r: continue
            if op in ('or', 'mr') and len(ops) >= 2 and reg(ops[1]) is not None and (op == 'mr' or len(ops) < 3 or ops[1] == ops[2]):
                r = reg(ops[1])
                if r in al: break                    # reached a prologue-saved incoming argument
                continue                             # follow the copy
            r = None; break                           # defined by something else
        if r is None: continue
        if r in al: out[tgt] = al[r]
        elif 3 <= r <= 10 and not any(rows[j][2].split(',')[0].strip() == 'r%d' % r and rows[j][1] not in ('cmpwi', 'cmplwi', 'cmpw', 'cmplw') and not rows[j][1].startswith('st') for j in range(0, k)): out[tgt] = r
    return tuple(sorted(out.items()))
def calls(rows):
    al = prologue_alias(rows); out = collections.Counter()
    for k, (a, op, rest) in enumerate(rows):
        name = None
        if op == 'jbsr': name = rest.split(',')[0].lstrip('_')
        elif op in ('bl', 'bla'):
            t = rest.split()[0] if rest else ''
            name = a2s.get(int(t, 16), t) if t.startswith('0x') else t.lstrip('_')
        elif op == 'bctrl': name = '<vtable>'
        if name:
            o = origins(rows, k, al)
            if o: out[(name, o)] += 1
    return out
bad = 0; n = 0
for name, a, sz, sym in sorted(meth, key=lambda x: x[1]):
    if sym not in ofun: continue
    nxt = ledaddrs[bisect.bisect_right(ledaddrs, a)] if bisect.bisect_right(ledaddrs, a) < len(ledaddrs) else a + sz
    hi = a + max(sz, nxt - a)
    cs = calls(srows[bisect.bisect_left(saddr, a):bisect.bisect_left(saddr, hi)]); co = calls(ofun[sym]); n += 1
    msgs = []
    onames = {c for c, _ in co}
    for (c, o), cnt in cs.items():
        if c not in onames or co[(c, o)] > 0: continue
        mine = [x for (cc, x), y in co.items() if cc == c]
        msgs.append('%s stock args %s | rebuilt %s' % (c[:40], ' '.join('r%d<-a%d' % kv for kv in o), ' / '.join(' '.join('r%d<-a%d' % kv for kv in x) for x in mine)[:80]))
    if msgs: bad += 1; print('%s\n    %s' % (name, '\n    '.join(msgs[:5])))
print('call_arg_origin_compare: %d methods compared, %d with an argument-origin pattern of the shipped body missing from the rebuild' % (n, bad))
