#!/usr/bin/env python3
"""diag_attrib.py CENSUS.tsv STOCK REBUILT LEDGER FUNCS SYMMAP NM NARGS OUT.tsv: for every census row whose worst verdict is EFFECTS with a differing write value, find the first differing write in the first
EFFECTS trial and name the function (corpus ledger) that contains the writing instruction in each image. Aggregating by function shows how many rows share one root cause."""
import sys, os, bisect, multiprocessing as mp
sys.path.insert(0, os.path.dirname(__file__)); sys.path.insert(0, os.path.expanduser('~/g5logs/fnf_237/pypkgs'))
import trace_diff as T
census, stock, reb, ledger, funcs, symmap, nm, nargs, out = sys.argv[1:10]
def init():
    T._init(stock, reb, symmap, nm, ledger, funcs, nargs)
    G = T._G
    G['fl'] = sorted((int(l.split('\t')[0], 16), l.split('\t')[2]) for l in open(funcs) if l.startswith('0x'))
    G['fla'] = [x[0] for x in G['fl']]
    G['rl'] = sorted((a, n) for a, n in G['R'].syms); G['rla'] = [x[0] for x in G['rl']]
def fn_of(lst, la, a):
    i = bisect.bisect_right(la, a) - 1
    return lst[i][1] if i >= 0 else '?'
def work(name):
    G = T._G; row = T.load_row(ledger, name); ss, sr = G['sims']['A']
    for t in range(8):
        g = T.Gen(row['id'] * 100003 + t); arena = g.arena(); ia, da, sw = g.call(row['pc'], valid=(t % 2 == 1))
        a = ss.run(row['stock'], ia, da, sw, arena); pa = dict(ss.evpc); b = sr.run(row['reb'], ia, da, sw, arena); pb = dict(sr.evpc)
        v, det = T.compare(a, b, row['rc'])
        if v != 'EFFECTS' or 'write (' not in det: continue
        wa = {}; wb = {}
        for i, e in enumerate(a[1]):
            if e[0] == 'W': wa.setdefault((e[1], e[2]), []).append((e[3], i))
        for i, e in enumerate(b[1]):
            if e[0] == 'W': wb.setdefault((e[1], e[2]), []).append((e[3], i))
        for k in sorted(set(wa) & set(wb), key=repr):
            for (x, i), (y, j) in zip(wa[k], wb[k]):
                if x != y: return name, fn_of(G['fl'], G['fla'], pa[i]), fn_of(G['rl'], G['rla'], pb[j]), t
    return name, '?', '?', -1
if __name__ == '__main__':
    names = []
    for l in open(census):
        p = l.rstrip('\n').split('\t')
        if len(p) >= 20 and p[19].startswith('EFFECTS') and 'write (' in p[19]: names.append(p[1])
    import collections; c = collections.Counter()
    with mp.Pool(28, initializer=init) as pool, open(out, 'w') as f:
        for name, sf, rf, t in pool.imap_unordered(work, names):
            f.write('%s\t%s\t%s\t%d\n' % (name, sf, rf, t)); c[(sf, rf)] += 1
    for (sf, rf), n in c.most_common(25): print(n, sf, '|', rf)
