#!/usr/bin/env python3
"""fpr_livein.py STOCK_TEXT_DUMP.txt RANGES.tsv > livein.json - which of f1..f13 each stock function reads before writing (incoming FP argument registers).

STOCK_TEXT_DUMP.txt is `otool -tV` of the stock binary (lines `addr<TAB>mnemonic<TAB>operands`); RANGES.tsv has `name<TAB>offset<TAB>size` rows (hex, no 0x). Backward dataflow over each function's CFG:
a call (bl) clobbers f0..f13 and reads the callee's live-in set; an indirect call (bctrl) clobbers and reads nothing; an indirect tail jump (bctr) or a tail branch to an unknown address
reads everything in a tiny (<= 0x30 bytes) thunk (it forwards the caller's registers) and nothing in a real function; blr ends the function. Interprocedural fixpoint over the direct-call graph."""
import re, sys, json, bisect
dump, ranges = sys.argv[1], sys.argv[2]
ins = {}                                   # addr -> (mn, ops)
for l in open(dump):
    t = l.rstrip('\n').split('\t')
    if len(t) >= 2 and re.fullmatch(r'[0-9a-f]{8}', t[0]):
        ins[int(t[0], 16)] = (t[1].strip(), t[2].strip() if len(t) > 2 else '')
funcs = {}
for l in open(ranges):
    n, o, s = l.split()
    funcs[n] = (int(o, 16), int(s, 16))
starts = sorted((o, n) for n, (o, s) in funcs.items())
fstart = {o: n for o, n in starts}
def fpr(op):
    m = re.fullmatch(r'f(\d+)', op.strip()); return int(m.group(1)) if m else None
STORE = {'stfs', 'stfd', 'stfsx', 'stfdx', 'stfiwx', 'stfsu', 'stfdu'}
LOAD = {'lfs', 'lfd', 'lfsx', 'lfdx', 'lfsu', 'lfdu'}
CMP = {'fcmpu', 'fcmpo'}
COND = re.compile(r'^(beq|bne|blt|ble|bgt|bge|bnl|bng|bns|bso|bun|bnu|bdnz|bdz|bdnzt|bdnzf|bdzt|bdzf|bc)(\+|-)?$')
def defuse(mn, ops):
    """return (defs, uses) restricted to f0..f31 numbers"""
    parts = [p.strip() for p in ops.split(',')] if ops else []
    d, u = set(), set()
    if mn in LOAD:
        r = fpr(parts[0]);  d.add(r) if r is not None else None
    elif mn in STORE:
        r = fpr(parts[0]);  u.add(r) if r is not None else None
    elif mn in CMP:
        for p in parts[1:3]:
            r = fpr(p);  u.add(r) if r is not None else None
    elif mn == 'mtfsf':
        r = fpr(parts[-1]);  u.add(r) if r is not None else None
    elif mn.startswith('f') or mn == 'mffs':
        r = fpr(parts[0]) if parts else None
        if r is not None: d.add(r)
        for p in parts[1:]:
            r = fpr(p);  u.add(r) if r is not None else None
    return d, u
CLOB = set(range(0, 14))
TINY = 0x30
livein = {n: set() for n in funcs}
ALL = set(range(1, 14))
def analyse_func(n):
    lo, sz = funcs[n]; hi = lo + sz
    addrs = [a for a in range(lo, hi, 4) if a in ins]
    idx = {a: i for i, a in enumerate(addrs)}
    succ = {}; kill = {}; use = {}
    for a in addrs:
        mn, ops = ins[a]; s = []; d, u = defuse(mn, ops); nxt = a + 4
        if mn == 'bl':
            tgt = int(ops.split(',')[-1], 16) if ops.startswith('0x') or ',' not in ops else int(ops.split(',')[-1], 16)
            d = d | CLOB; cal = fstart.get(tgt)
            if cal: u = u | livein[cal]
            if nxt in idx: s.append(nxt)
        elif mn == 'bcl':
            if nxt in idx: s.append(nxt)
        elif mn == 'bctrl':
            d = d | CLOB
            if nxt in idx: s.append(nxt)
        elif mn == 'bctr':
            if sz <= TINY: u = u | ALL           # a thunk forwards every register; a real function's indirect tail call passes what it set up itself
        elif mn == 'blr':
            pass
        elif mn == 'b':
            tgt = int(ops, 16)
            if lo <= tgt < hi: s.append(tgt)
            else:
                cal = fstart.get(tgt)
                u = u | (livein[cal] if cal else (ALL if sz <= TINY else set()))
        elif COND.match(mn):
            tgt = int(ops.split(',')[-1], 16)
            if lo <= tgt < hi: s.append(tgt)
            else:
                cal = fstart.get(tgt); u = u | (livein[cal] if cal else (ALL if sz <= TINY else set()))
            if nxt in idx: s.append(nxt)
        elif mn.endswith('lr') and mn.startswith('b'):      # conditional return
            if nxt in idx: s.append(nxt)
        else:
            if nxt in idx: s.append(nxt)
        succ[a] = s; kill[a] = d; use[a] = u
    li = {a: set() for a in addrs}
    ch = True
    while ch:
        ch = False
        for a in reversed(addrs):
            out = set()
            for s in succ[a]: out |= li[s]
            new = (out - kill[a]) | use[a]
            if new != li[a]: li[a] = new; ch = True
    return (li[addrs[0]] & ALL) if addrs else set()
ch = True; it = 0
while ch and it < 30:
    ch = False; it += 1
    for n in funcs:
        v = analyse_func(n)
        if v != livein[n]: livein[n] = v; ch = True
json.dump({n: sorted(v) for n, v in livein.items()}, sys.stdout)
