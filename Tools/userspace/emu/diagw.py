#!/usr/bin/env python3
"""diagw.py STOCK REBUILT LEDGER FUNCS SYMMAP NM NARGS ROW [fill A|B]: for the first trial of ROW whose summaries differ, show the first write whose value differs, with the pc of the writing
instruction in each image, the function containing it (corpus ledger) and a disassembly window."""
import sys, os, bisect
sys.path.insert(0, os.path.dirname(__file__)); sys.path.insert(0, os.path.expanduser('~/g5logs/fnf_237/pypkgs'))
import trace_diff as T
from capstone import *
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
stock, reb, ledger, funcs, symmap, nm, nargs, name = sys.argv[1:9]
T._init(stock, reb, symmap, nm, ledger, funcs, nargs)
S, R = T._G['S'], T._G['R']; row = T.load_row(ledger, name)
fl = sorted((int(l.split('\t')[0], 16), l.split('\t')[2]) for l in open(funcs) if l.startswith('0x'))
rl = sorted((a, n) for a, n in R.syms)
def fn_of(lst, a):
    i = bisect.bisect_right([x[0] for x in lst], a) - 1
    return lst[i] if i >= 0 else None
def code(img, addr, n):
    for nm_, vm, vs, data in img.segs:
        if vm <= addr < vm + len(data): return data[addr - vm:addr - vm + n]
def show(img, pc, lst, lab):
    f = fn_of(lst, pc); print('  %s pc %x in %s (+%x)' % (lab, pc, f[1] if f else '?', pc - f[0] if f else 0))
    for i in md.disasm(code(img, pc - 24, 56), pc - 24): print('      %s%x %s %s' % ('>' if i.address == pc else ' ', i.address, i.mnemonic, i.op_str))
for fillname in ('A',):
    ss, sr = T._G['sims'][fillname]
    for t in range(40):
        g = T.Gen(row['id'] * 100003 + t); arena = g.arena(); ia, da, sw = g.call(row['pc'], valid=(t % 2 == 1))
        a = ss.run(row['stock'], ia, da, sw, arena); pa = dict(ss.evpc); b = sr.run(row['reb'], ia, da, sw, arena); pb = dict(sr.evpc)
        v, det = T.compare(a, b, row['rc'])
        if v not in ('EFFECTS', 'PTR_VALUE_DEP', 'IMAGE_DATA_DEP', 'IMAGE_ADDR_DEP'): continue
        print('trial', t, v, det[:300]); 
        wa = {}; wb = {}
        for i, e in enumerate(a[1]):
            if e[0] == 'W': wa.setdefault((e[1], e[2]), []).append((e[3], i))
        for i, e in enumerate(b[1]):
            if e[0] == 'W': wb.setdefault((e[1], e[2]), []).append((e[3], i))
        for k in sorted(set(wa) & set(wb), key=repr):
            xs = [x[0] for x in wa[k]]; ys = [y[0] for y in wb[k]]
            if xs != ys:
                for (x, i), (y, j) in zip(wa[k], wb[k]):
                    if x != y: print('write', k, 'stock', x, 'rebuilt', y); show(S, pa[i], fl, 'stock'); show(R, pb[j], rl, 'rebuilt'); break
                break
        break
