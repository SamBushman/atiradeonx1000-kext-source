#!/usr/bin/env python3
"""show_order.py STOCK REBUILT LEDGER FUNCS SYMMAP NM NARGS NAME...: first non-identical trial of each NAME with both ordered external traces side by side."""
import sys, os
sys.path.insert(0, os.path.dirname(__file__)); sys.path.insert(0, os.path.expanduser('~/g5logs/fnf_237/pypkgs'))
import trace_diff as T
a = sys.argv[1:8]; T._init(a[0], a[1], a[4], a[5], a[2], a[3], a[6]); ss, sr = T._G['sims']['A']
ext = lambda ev: [e for e in ev if not (e[0] == 'R' and isinstance(e[1], tuple))]
for name in sys.argv[8:]:
    row = T.load_row(a[2], name)
    for t in range(8):
        g = T.Gen(row['id'] * 100003 + t); arena = g.arena(); ia, da, sw = g.call(row['pc'], valid=(t % 2 == 1)); arena = T.prime_ring(arena, ia, row['pc'])
        x = ss.run(row['stock'], ia, da, sw, arena); y = sr.run(row['reb'], ia, da, sw, arena); v, det = T.compare(x, y, row['rc'])
        if v in ('REORDERED', 'READ_SET', 'FAULT_SITE', 'EFFECTS'):
            print('==', name, 'trial', t, v, x[0], y[0]); p, q = ext(x[1]), ext(y[1])
            for i in range(max(len(p), len(q))): print('  S %-58s R %s' % (str(p[i])[:56] if i < len(p) else '', str(q[i])[:56] if i < len(q) else ''))
            break
