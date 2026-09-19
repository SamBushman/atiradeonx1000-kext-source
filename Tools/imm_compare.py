#!/usr/bin/env python3
"""imm_compare.py STOCK_DIS OURS_DIS [N]  - fidelity check on data flow: for every ledger method compare the SET of
structure-field displacements (lwz/stw/lbz/... d(rN), N != r1) and compare immediates (cmpwi/cmplwi) used by the shipped
code against the rebuild. A field the shipped code touches that the rebuild never touches (or a constant it never tests)
marks a missing/altered statement. Ours should be built -O0 (every access materialised)."""
import sys, re, bisect, collections
sdis, odis = sys.argv[1], sys.argv[2]
top = int(sys.argv[3]) if len(sys.argv) > 3 else 60
ins = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
LS = re.compile(r'^(lwz|lwzu|stw|stwu|lbz|lbzu|stb|stbu|lhz|lhzu|lha|sth|sthu|lfs|lfd|stfs|stfd)$')
CMP = re.compile(r'^(cmpwi|cmplwi)$')
def s32(v):
    v &= 0xffff
    return v - 0x10000 if v & 0x8000 else v
def feats(rows):
    disp = collections.Counter(); cmpi = collections.Counter()
    for a, op, rest in rows:
        if LS.match(op):
            m = re.match(r'^\S+,(0x[0-9a-f]+|-?\d+)\((r\d+)\)', rest)
            if m and m.group(2) != 'r1':
                d = s32(int(m.group(1), 0)) if m.group(1).startswith('0x') else int(m.group(1))
                disp[d] += 1
        elif CMP.match(op):
            m = re.match(r'^cr\d,r\d+,(0x[0-9a-f]+|-?\d+)$', rest)
            if m:
                v = int(m.group(1), 0)
                if op == 'cmpwi': v = s32(v)
                cmpi[v] += 1
    return disp, cmpi
led = {}
for l in open('Ledger/kext_ppc_ledger.tsv'):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE': led[f[5]] = (int(f[0], 16), int(f[1]), f[4])
srows = []
for l in open(sdis):
    m = ins.match(l)
    if m: srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
saddr = [r[0] for r in srows]
ofun = {}; cur = None
for l in open(odis):
    if re.match(r'^_\S+:$', l.strip()) and not l.startswith('\t') and not l[0].isdigit():
        cur = l.strip()[:-1]; ofun[cur] = []; continue
    m = ins.match(l)
    if m and cur: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
# fold helper functions (no ledger entry) into their callers by name: collect callee names
def called(rows):
    out = []
    for a, op, rest in rows:
        if op in ('jbsr', 'bl'):
            out.append(rest.split(',')[0].split()[0].lstrip('_'))
    return out
ledn = {k.lstrip('_') for k in led}
oidx = {k.lstrip('_'): v for k, v in ofun.items()}
def ours_feats(sym, seen=()):
    rows = oidx[sym.lstrip('_')]
    d, c = feats(rows)
    for callee in called(rows):
        if callee in oidx and callee not in ledn and callee not in seen and not callee.startswith('Z1M'):
            d2, c2 = ours_feats(callee, seen + (sym,)); d += d2; c += c2
    return d, c
res = []
for sym, (a, n, name) in led.items():
    if sym.lstrip('_') not in oidx: continue
    i = bisect.bisect_left(saddr, a); j = bisect.bisect_left(saddr, a + n)
    sd, sc = feats(srows[i:j]); od, oc = ours_feats(sym)
    md = sorted(set(sd) - set(od)); mc = sorted(set(sc) - set(oc))
    if md or mc: res.append((len(md) + len(mc), name, md, mc, len(set(sd)), len(set(sc))))
res.sort(reverse=True)
print(len(res), 'methods with stock-only displacements/compare-immediates (of', len(led), ')')
for k, name, md, mc, nd, nc in res[:top]:
    print(k, name, 'disp-missing', [hex(x) if x >= 0 else x for x in md][:14], 'of', nd, '| cmp-missing', [hex(x) if x >= 0 else x for x in mc][:10], 'of', nc)
