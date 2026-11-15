#!/usr/bin/env python3
"""analyze46.py: per-row summary of diag46_{real,self,real2}.full (fnfuzz_gs85 FNFUZZ_LISTDIFFS=2) for the stage-1 DIFF rows.
For each row: differing/agreeing trial counts per run, repeatability (real vs real2), the self-control result (stock vs byte copy of itself),
who faulted (status codes) in the differing trials, and for single-index lookups the index range of differing vs agreeing trials."""
import re, sys, collections
D = sys.argv[1] if len(sys.argv) > 1 else '.'
pat = re.compile(r'^(DT|AT) (\S+)\s+trial (\d+) mode (\d+)( RUNINIT)?: stock st=(-?\d+) r3=([0-9a-f]+) dg=([0-9a-f]+) \| rebuilt st=(-?\d+) r3=([0-9a-f]+) dg=([0-9a-f]+) \| args ([0-9a-f]+) ([0-9a-f]+) ([0-9a-f]+) ([0-9a-f]+) ([0-9a-f]+)')
def load(p):
    rows = collections.OrderedDict()
    for l in open(p, 'rb'):
        l = l.decode('latin1')
        i = l.find('DT ') if 'DT ' in l and not l.startswith(('DT', 'AT')) else 0
        m = pat.match(l[i:]) or pat.match(l[l.find('AT '):] if 'AT ' in l else '')
        if not m: continue
        k, n, t, mode, ru, sst, sr3, sdg, rst, rr3, rdg = m.groups()[:11]
        args = [int(x, 16) for x in m.groups()[11:]]
        rows.setdefault(n, {})[int(t)] = dict(kind=k, ru=bool(ru), sst=int(sst), rst=int(rst), sr3=sr3, rr3=rr3, sdg=sdg, rdg=rdg, args=args)
    return rows
real, self_, real2 = (load('%s/diag46_%s.full' % (D, x)) for x in ('real', 'self', 'real2'))
def dset(r, n): return {t for t, v in r.get(n, {}).items() if v['kind'] == 'DT'}
out = []
for n in real:
    a, s, b = real[n], self_.get(n, {}), real2.get(n, {})
    dr, ds, d2 = dset(real, n), dset(self_, n), dset(real2, n)
    ag = [t for t, v in a.items() if v['kind'] == 'AT']
    sts = collections.Counter((a[t]['sst'], a[t]['rst']) for t in dr)
    ru = sum(1 for t in dr if a[t]['ru'])
    line = '%-48s real %2d diff/%2d agree | self-ctl %2d diff | repeat(real2) %s | st(stock,reb) %s | RUNINIT-flagged %d' % (n, len(dr), len(ag), len(ds), 'same' if dr == d2 else 'differs %s vs %s' % (sorted(dr), sorted(d2)), dict(sts), ru)
    # 1-arg index analysis: which arg varies most? report min/max of each arg among differing vs agreeing
    if dr and ag:
        for k in range(5):
            dv = [a[t]['args'][k] for t in dr]; av = [a[t]['args'][k] for t in ag]
            sd = lambda x: x - (1 << 32) if x >= (1 << 31) else x
            dmin, dmax = min(map(sd, dv)), max(map(sd, dv)); amin, amax = min(map(sd, av)), max(map(sd, av))
            if dmax < amin or dmin > amax:   # clean separation on this arg
                line += '\n      arg%d separates: differing [%d..%d] (0x%x..0x%x) vs agreeing [%d..%d]' % (k + 1, dmin, dmax, dmin & 0xffffffff, dmax & 0xffffffff, amin, amax)
    out.append(line)
print('\n'.join(out))
