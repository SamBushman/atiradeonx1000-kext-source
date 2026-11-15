#!/usr/bin/env python3
"""ring_coverage.py STOCK REBUILT LEDGER FUNCS SYMMAP NM NARGS [TRIALS]: how many functions / trials of the ledger write into the command ring (stock side), and how many dwords."""
import sys, os, multiprocessing as mp
sys.path.insert(0, os.path.dirname(__file__)); sys.path.insert(0, os.path.expanduser('~/g5logs/fnf_237/pypkgs'))
import trace_diff as T
a = sys.argv[1:8]; trials = int(sys.argv[8]) if len(sys.argv) > 8 else 8
def work(row):
    ss, sr = T._G['sims']['A']; n = 0; dw = 0
    for t in range(trials):
        g = T.Gen(row['id'] * 100003 + t); arena = g.arena(); ia, da, sw = g.call(row['pc'], valid=(t % 2 == 1)); arena = T.prime_ring(arena, ia, row['pc'])
        x = ss.run(row['stock'], ia, da, sw, arena)
        w = sum(e[2] for e in x[1] if e[0] == 'W' and isinstance(e[1], int) and T.RING <= e[1] < T.RING + T.RING_SIZE) + sum(len(e[2]) for e in x[1] if e[0] == 'WB' and isinstance(e[1], int) and T.RING <= e[1] < T.RING + T.RING_SIZE)
        if w: n += 1; dw += w // 4
    return row['name'], n, dw
if __name__ == '__main__':
    rows = T.read_ledger(a[2])
    with mp.Pool(28, initializer=T._init, initargs=(a[0], a[1], a[4], a[5], a[2], a[3], a[6])) as pool: res = pool.map(work, rows, chunksize=4)
    em = [r for r in res if r[1]]
    print('%d / %d functions wrote to the ring in at least one of %d trials; trials with ring writes %d of %d; dwords %d' % (len(em), len(rows), trials, sum(r[1] for r in em), trials * len(rows), sum(r[2] for r in em)))
    print('top:', sorted(em, key=lambda r: -r[2])[:8])
