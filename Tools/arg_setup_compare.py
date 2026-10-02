#!/usr/bin/env python3
"""arg_setup_compare.py STOCK_DIS OURS_DIS [--max-size N]  (#85)
For small DONE methods, compares which argument registers (r3..r10) are WRITTEN before the first call / tail jump in the shipped and the rebuilt body.
An argument the shipped code leaves untouched (implicitly forwarded r4, `or r3,r4,r4` returns) but the rebuilt body overwrites - or the reverse - is the
Ghidra "dropped argument / dropped result" class. Inputs: `otool -arch ppc -tV` output; run from the repo root. Hits are candidates, read each against the asm."""
import sys, re, bisect
a = sys.argv[1:]; mx = 160
if '--max-size' in a:
    i = a.index('--max-size'); mx = int(a[i + 1]); del a[i:i + 2]
INS = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
STOP = ('bl', 'bla', 'jbsr', 'bctrl', 'blr', 'bctr', 'b')   # conditional branches (bne, beqlr...) do not end the scan: both paths are summed
NODEST = ('cmp', 'cmpw', 'cmpwi', 'cmpl', 'cmplw', 'cmplwi', 'mtlr', 'mtctr', 'mtcrf', 'nop', 'sync', 'isync')
def written(rows):
    w = set()
    lo = rows[0][0] if rows else 0; hi = rows[-1][0] if rows else 0
    for _, op, rest in rows:
        if op == 'b' and re.match(r'^0x[0-9a-f]+$', rest.strip()) and lo <= int(rest.strip(), 16) <= hi: continue   # local jump: stay in the body
        if op in STOP: break
        ops = [x.strip() for x in rest.split(',')] if rest else []
        if ops and re.match(r'^r(\d+)$', ops[0]) and not op.startswith('st') and op not in NODEST and not op.startswith('b') and op != 'mfcr':
            n = int(ops[0][1:])
            if 3 <= n <= 10: w.add(n)
    return w
led = []
for l in open('Ledger/kext_ppc_ledger.tsv'):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE' and int(f[1]) <= mx:
        led.append((int(f[0], 16), int(f[1]), f[4], f[5]))
srows = [(int(m.group(1), 16), m.group(2), m.group(3)) for m in map(INS.match, open(a[0])) if m]
saddr = [r[0] for r in srows]
ofun = {}; cur = None
for l in open(a[1]):
    s = l.strip()
    if s.endswith(':') and not re.match(r'^[0-9a-f]{8}\t', l): cur = s[:-1]; ofun[cur] = []; continue
    m = INS.match(l)
    if m and cur: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
n = bad = 0
for addr, size, name, sym in led:
    o = ofun.get(sym)
    if not o: continue
    i = bisect.bisect_left(saddr, addr)
    j = bisect.bisect_left(saddr, addr + max(size, 4)); sw = written(srows[i:j]); ow = written(o); n += 1
    if sw != ow:
        bad += 1; print('DIFF %-60s stock-writes %s rebuilt-writes %s' % (name, sorted(sw), sorted(ow)))
print('arg_setup_compare: %d methods, %d differ' % (n, bad))
