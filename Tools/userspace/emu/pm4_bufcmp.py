#!/usr/bin/env python3
"""pm4_bufcmp.py STOCK_RECS RB_RECS [N_DETAIL]

Compare two opcode_recorder_rec dumps (OPCODE_RECS=<nbuf>, per-buffer 'BUF i' header then one line per record:
'<op> <nwords> [payload words]'; records of >40 words carry only the header) of the same UT2004 timedemo (stock vs rebuilt GLDriver).

Reports: how many buffers are structurally identical (same (op,n) sequence), the first structural diffs, and, for the
buffers that are structurally identical, how many differ only in payload words (addresses/handles are expected to differ;
the per-record diff is summarised by opcode so a systematic payload difference stands out).
"""
import sys, collections

def load(f):
    bufs = []
    cur = None
    for l in open(f, errors='replace'):
        if l.startswith('BUF'):
            cur = []
            bufs.append(cur)
        elif cur is not None:
            cur.append(l.rstrip('\n'))
    return bufs

def sig(b):
    return [tuple(r.split()[:2]) for r in b]

A = load(sys.argv[1]); B = load(sys.argv[2])
nd = int(sys.argv[3]) if len(sys.argv) > 3 else 10
n = min(len(A), len(B))
print('buffers', len(A), len(B))
sd = [i for i in range(n) if sig(A[i]) != sig(B[i])]
print('structurally different buffers: %d / %d' % (len(sd), n), 'first', sd[:20])
opd = collections.Counter(); opn = collections.Counter(); pay_bufs = 0
for i in range(n):
    if i in set(sd[:0]): continue
    sa, sb = sig(A[i]), sig(B[i])
    if sa != sb: continue
    dif = False
    for ra, rb in zip(A[i], B[i]):
        opn[ra.split()[0]] += 1
        if ra != rb:
            opd[ra.split()[0]] += 1; dif = True
    pay_bufs += dif
print('structurally-identical buffers with payload diffs: %d' % pay_bufs)
print('payload-differing records by opcode (op: diff/total):', ', '.join('%s:%d/%d' % (o, c, opn[o]) for o, c in opd.most_common(15)))
for i in sd[:nd]:
    sa, sb = sig(A[i]), sig(B[i])
    j = next((k for k in range(min(len(sa), len(sb))) if sa[k] != sb[k]), min(len(sa), len(sb)))
    print('buf %d: stock %d recs, rebuilt %d recs, first diff at rec %d: stock %s rebuilt %s' % (i, len(sa), len(sb), j, sa[j:j+3], sb[j:j+3]))
