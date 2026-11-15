#!/usr/bin/env python3
"""reorder_kinds.py STOCK REBUILT LEDGER FUNCS SYMMAP NM NARGS CENSUS [TRIALS]: for every row of CENSUS whose worst verdict is REORDERED, classify the first difference between the two ordered external traces
(kind pair of the first differing events, and whether it is only a store-form difference: same bytes written in other granularity)."""
import sys, os, collections, multiprocessing as mp
sys.path.insert(0, os.path.dirname(__file__)); sys.path.insert(0, os.path.expanduser('~/g5logs/fnf_237/pypkgs'))
import trace_diff as T
a = sys.argv[1:9]; trials = int(sys.argv[9]) if len(sys.argv) > 9 else 8
def ext(ev): return [e for e in ev if not (e[0] == 'R' and isinstance(e[1], tuple))]
def kind(ea, eb):
    x, y = ext(ea), ext(eb)
    i = next((i for i, (p, q) in enumerate(zip(x, y)) if p != q), None)
    if i is None: return 'length only (%d vs %d)' % (len(x), len(y))
    p, q = x[i], y[i]
    if p[0] in ('W', 'WB') and q[0] in ('W', 'WB'):
        sa, _ = T.segments(x); sb, _ = T.segments(y)
        return 'store form (granularity / libc inline)' if all(u[3] == v[3] for u, v in zip(sa, sb)) and ('WB' in (p[0], q[0]) or p[2:3] != q[2:3] or p[1] == q[1]) else 'W/W order'
    return '%s/%s order' % (p[0], q[0])
def work(row):
    S, R = T._G['S'], T._G['R']; ss, sr = T._G['sims']['A']; out = collections.Counter()
    for t in range(trials):
        g = T.Gen(row['id'] * 100003 + t); arena = g.arena(); ia, da, sw = g.call(row['pc'], valid=(t % 2 == 1)); arena = T.prime_ring(arena, ia, row['pc'])
        x = ss.run(row['stock'], ia, da, sw, arena); y = sr.run(row['reb'], ia, da, sw, arena)
        v, det = T.compare(x, y, row['rc'])
        if v == 'REORDERED': out[kind(x[1], y[1])] += 1
    return row['name'], out
if __name__ == '__main__':
    names = set()
    for l in open(a[7]):
        p = l.split('\t')
        if len(p) > 10 and p[0].isdigit() and int(p[9] or 0) and not any(int(p[i] or 0) for i in (10, 11, 12, 13, 16)): names.add(p[1])
    rows = [r for r in T.read_ledger(a[2]) if r['name'] in names]
    with mp.Pool(28, initializer=T._init, initargs=(a[0], a[1], a[4], a[5], a[2], a[3], a[6])) as pool:
        tot = collections.Counter(); per = collections.Counter()
        for n, c in pool.imap_unordered(work, rows):
            tot.update(c)
            if c: per[max(c, key=c.get)] += 1
    print(len(rows), 'REORDERED-only rows; trials by first-difference kind:'); [print('  %6d %s' % (v, k)) for k, v in tot.most_common()]
    print('rows by dominant kind:'); [print('  %6d %s' % (v, k)) for k, v in per.most_common()]
