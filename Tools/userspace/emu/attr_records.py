#!/usr/bin/env python3
"""attr_records.py RUN1 RUN2 [-- REBUILT...] [--bufs N]   (issue #210 criterion 2)

Compares the current-vertex-attribute records (`06 8 00000001 00000000 c0031000 f0 f1 f2 00000014` lines of the opcode_recorder_rec dump)
of the first N (default 1500) command buffers of the same UT2004 timedemo across runs.  RUN1 RUN2 RUN3 are three STOCK runs: the noise floor is the number of distinct records of RUN3 that appear in neither RUN1 nor RUN2;
each REBUILT file is compared the same way (records in neither RUN1 nor RUN2).  Criterion: rebuilt-only records <= stock-vs-stock noise.  Prints the counts and the first few differing records.
"""
import sys, re
args = sys.argv[1:]
nb = 1500
if '--bufs' in args:
    i = args.index('--bufs'); nb = int(args[i + 1]); del args[i:i + 2]
if '--' in args:
    i = args.index('--'); stock, reb = args[:i], args[i + 1:]
else:
    stock, reb = args[:3], args[3:]
HDR = re.compile(r'^c0([0-9a-f]{2})1000$')

def load(fn):
    """records `06 8 00000001 00000000 c0031000 f0 f1 f2 00000014` of the first nb buffers -> set of (f0, f1, f2)"""
    s = set(); buf = -1; n = 0
    for l in open(fn, errors='replace'):
        if l.startswith('BUF'):
            buf += 1
            if buf >= nb: break
            continue
        if l.startswith('06 8 '):
            w = l.split()
            if len(w) == 9 and w[4] == 'c0031000': s.add(tuple(w[5:8])); n += 1
    return s, n

S1, n1 = load(stock[0]); S2, n2 = load(stock[1]); S3, n3 = load(stock[2])
print('stock runs: %d / %d / %d records (%d / %d / %d distinct)' % (n1, n2, n3, len(S1), len(S2), len(S3)))
noise = S3 - S1 - S2
print('NOISE FLOOR  distinct records of stock run3 in neither stock run1 nor run2: %d' % len(noise))
for f in reb:
    R, nr = load(f)
    only = R - S1 - S2
    print('%s: %d records (%d distinct); in neither stock run1 nor run2: %d  => %s' % (f, nr, len(R), len(only), 'PASS' if len(only) <= len(noise) else 'FAIL'))
    for r in sorted(only)[:6]: print('   ', ' '.join(r))
