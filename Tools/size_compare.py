#!/usr/bin/env python3
"""size_compare.py NM_N_TXT [N]  - fidelity heuristic: per-method size of the rebuild vs the shipped kext.
NM_N_TXT is `nm -n build | awk '$2=="T"||$2=="t"{print $1,$3}'` from the Tiger box. Built with -Os the same Apple gcc 4.0.1
that produced the shipped kext, a faithful transcription lands within a few percent of the shipped function size; large
shortfalls point at simplified bodies."""
import sys
ours = sorted((int(a, 16), n) for a, n in (l.split() for l in open(sys.argv[1])))
size = {n: (ours[i+1][0] if i+1 < len(ours) else a) - a for i, (a, n) in enumerate(ours)}
rows = []
for l in open('Ledger/kext_ppc_ledger.tsv'):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE' and f[5] in size:
        st = int(f[1]); rows.append((size[f[5]] / st, st, size[f[5]], f[4]))
rows.sort()
lim = int(sys.argv[2]) if len(sys.argv) > 2 else 60
tot_s = sum(r[1] for r in rows); tot_o = sum(r[2] for r in rows)
print('%d methods, stock %d bytes, ours %d bytes (%.2f)' % (len(rows), tot_s, tot_o, tot_o / tot_s))
import collections
b = collections.Counter(min(int(r[0] * 10), 20) for r in rows)
print('ratio histogram (x0.1):', sorted(b.items()))
for r in rows[:lim]: print('%.2f stock=%d ours=%d %s' % r)
