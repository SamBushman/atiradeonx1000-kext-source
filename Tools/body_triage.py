#!/usr/bin/env python3
"""body_triage.py STOCK_DIS OURS_DIS NM_N_TXT [MANUAL_TSV]  > Tests/body_triage.tsv   (#85)

One row per method that callee_compare.py reports (callee-multiset difference) or size_compare.py reports (< 0.8x the shipped size), with a
verdict and the evidence behind it, so no outlier is left "unchecked":
  verdict  BENIGN  with a named reason, from rules over the ORDERED call sequence of the shipped body and the rebuilt body (tail calls,
                   lazy-binding stubs and vtable tail jumps resolved), the callee multisets and imm_compare.py's displacement/immediate sets:
             SAME-SEQUENCE  identical ordered callees (a forwarder: the rebuild tail-calls, the shipped code wraps the call in a frame)
             SAME-MULTISET  same callees, different order (basic-block layout / switch ordering)
             CTOR-INLINED   the shipped body calls `X::X()`/the metaclass ctor, the rebuild inlines the identical compiler-generated constructor
             FP-MILLICODE   the rebuild saves/restores FPRs through saveFP/restFP
             SAME-SET       the same distinct callees, a different NUMBER of call sites (merged/duplicated error tails); immediates equal
           DEFECT / REVIEW come only from MANUAL_TSV (method<TAB>verdict<TAB>reason) - the script never invents them.
Rows that fit no rule are written as UNCLASSIFIED and make the exit status 1."""
import sys, re, bisect, collections, subprocess, os
sdis, odis, nm = sys.argv[1:4]
manual = {}
if len(sys.argv) > 4 and os.path.exists(sys.argv[4]):
    for l in open(sys.argv[4]):
        f = l.rstrip('\n').split('\t')
        if len(f) >= 3 and not l.startswith('#'): manual[f[0]] = (f[1], f[2])
HERE = os.path.dirname(os.path.abspath(__file__))
def run(*a): return subprocess.run(['python3'] + list(a), capture_output=True, text=True).stdout
cc = {}
for l in run(HERE + '/callee_compare.py', sdis, odis, '1', '10000').split('\n')[1:]:
    m = re.match(r'^(\d+) (\S+) (SAME-SET|SET-DIFF) STOCK-ONLY (\{.*?\}) OURS-ONLY (\{.*\})$', l)
    if m: cc[m.group(2)] = (m.group(3), m.group(4), m.group(5))
size = {}
for l in run(HERE + '/size_compare.py', nm, '1000').split('\n')[3:]:
    m = re.match(r'^([\d.]+) stock=(\d+) ours=(\d+) (\S+)$', l)
    if m and float(m.group(1)) < 0.8: size[m.group(4)] = (int(m.group(2)), int(m.group(3)))
imm = {}
for l in run(HERE + '/imm_compare.py', sdis, odis, '1', '10000').split('\n')[1:]:
    m = re.match(r'^\d+ (\S+) disp-missing', l)
    if m: imm[m.group(1)] = l
# ordered call sequences (same extraction as callee_compare.py)
led = [l.rstrip('\n').split('\t') for l in open('Ledger/kext_ppc_ledger.tsv')]
a2s = {int(f[0], 16): (f[5].lstrip('_') if len(f) >= 6 and f[5] else f[4]) for f in led if len(f) >= 5}
ledaddrs = sorted(a2s)
INS = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
srows = []; stub = {}
for l in open(sdis):
    m = INS.match(l)
    if m:
        srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
        if m.group(2) == 'jbsr' and ',' in m.group(3): nmn, st = m.group(3).split(',', 1); stub[int(st, 16)] = nmn.lstrip('_')
saddr = [r[0] for r in srows]
ofun = {}; cur = None
for l in open(odis):
    s = l.strip()
    if s.endswith(':') and not l.startswith('\t') and not re.match(r'^[0-9a-f]{8}\t', l): cur = s[:-1]; ofun[cur] = []; continue
    m = INS.match(l)
    if m and cur is not None: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
def seq(rows, lo=None, hi=None):
    out = []
    for k, (a, op, rest) in enumerate(rows):
        if op == 'jbsr': out.append(rest.split(',')[0].lstrip('_'))
        elif op in ('bl', 'bla'):
            t = rest.split()[0] if rest else ''
            out.append(a2s.get(int(t, 16), t) if t.startswith('0x') else t.lstrip('_'))
        elif op == 'bctrl' or (op == 'bctr' and not (k + 1 < len(rows) and rows[k + 1][1] == '.long')): out.append('<ind>')
        elif op == 'b' and rest:
            t = rest.split()[0]
            if t.startswith('0x'):
                if lo is not None and not (lo <= int(t, 16) < hi):
                    if int(t, 16) in a2s: out.append(a2s[int(t, 16)])
                    elif int(t, 16) in stub: out.append(stub[int(t, 16)])
            else: out.append(t.lstrip('_'))
    return out
names = sorted(set(cc) | set(size))
meth = [(f[4], int(f[0], 16), int(f[1]), f[5]) for f in led if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE']   # overloads/duplicates: one row per symbol
print('method\tflagged_by\tstock_B\tours_B\tverdict\treason\tevidence')
bad = 0
for n, a, sz, sym in sorted(meth, key=lambda x: (x[0], x[1])):
    if n not in names: continue
    nxt = ledaddrs[bisect.bisect_right(ledaddrs, a)] if bisect.bisect_right(ledaddrs, a) < len(ledaddrs) else a + sz
    hi = a + max(sz, nxt - a)
    ss = seq(srows[bisect.bisect_left(saddr, a):bisect.bisect_left(saddr, hi)], a, hi)
    oo = seq(ofun.get(sym, []))
    why = []
    if n in cc: why.append('callee')
    if n in size: why.append('size')
    sb = max(sz, 0); ob = len(ofun.get(sym, [])) * 4
    kind = cc[n][0] if n in cc else None
    if (n + ' @0x%x' % a) in manual: v, r = manual[n + ' @0x%x' % a]
    elif n in manual: v, r = manual[n]
    elif ss == oo: v, r = 'BENIGN', 'SAME-SEQUENCE: identical ordered callees; stock wraps the call in a frame, the rebuild tail-calls (forwarder)'
    elif collections.Counter(ss) == collections.Counter(oo): v, r = 'BENIGN', 'SAME-MULTISET: same callees, different block order'
    elif any(x.endswith('C1Ev') or 'MetaClassC' in x or 'MetaClass9MetaClass' in x for x in ss) and any('instanceConstructed' in x or 'OSMetaClassC2' in x or 'OSObjectC2' in x for x in oo):
        v, r = 'BENIGN', 'CTOR-INLINED: the shipped body calls the class constructor, the rebuild inlines the identical compiler-generated one (ctor bodies compared for ATIR500Surface: same instruction sequence)'
    elif any('saveFP' in x or 'restFP' in x for x in oo) and set(ss) <= set(oo) | {'saveFP', 'restFP'}: v, r = 'BENIGN', 'FP-MILLICODE: the rebuild saves/restores FPRs through saveFP/restFP'
    elif kind == 'SAME-SET' and n not in imm: v, r = 'BENIGN', 'SAME-SET: every distinct callee on both sides, call-site count differs (merged/duplicated tails); displacement and immediate sets equal'
    elif not oo and n in size and not ss: v, r = 'BENIGN', 'no calls on either side (size only)'
    else: v, r = 'UNCLASSIFIED', ''; bad += 1
    # a body of real size that is far smaller than the shipped one is never accepted on call evidence alone (the hand-written submit_swap_buffer
    # bodies had the same callees and 0.59x/0.71x the size: large parts were simply missing, found only by block comparison)
    if v == 'BENIGN' and n not in manual and (n + ' @0x%x' % a) not in manual and sb >= 100 and ob < 0.8 * sb and not r.startswith('SAME-SEQUENCE'):
        v, r = 'UNCLASSIFIED', 'size %d < 0.8x %d: needs a block-by-block comparison' % (ob, sb); bad += 1
    ev = 'stock=' + ','.join(re.sub(r'^ZN?\d*', '', x)[:28] for x in ss)[:200] + ' | ours=' + ','.join(re.sub(r'^ZN?\d*', '', x)[:28] for x in oo)[:200]
    print('\t'.join([n + ' @0x%x' % a, '+'.join(why), str(sb), str(ob), v, r, ev]))
sys.stderr.write('body_triage: %d rows, %d unclassified\n' % (len(names), bad))
sys.exit(1 if bad else 0)
