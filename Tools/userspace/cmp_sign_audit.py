#!/usr/bin/env python3
"""cmp_sign_audit.py STOCK REBUILT STOCK_LEDGER(corpus ledger.tsv) REBUILT_NM [SYMMAP] - per function, how many compares are signed (cmpw/cmpwi) and unsigned (cmplw/cmplwi) when the result
feeds an ORDERING branch (blt/bgt/ble/bge/bnl/bng, i.e. not just ==/!=), stock vs rebuilt. A function whose unsigned/signed counts differ is a candidate for a lost `(unsigned)` cast / a wrong
declared signedness (class: `x - 0x2e < 2` compiled signed; _idstr). The compiler differs between the images, so a difference is a lead, not proof: read both disassemblies."""
import sys, re, bisect
sys.path.insert(0, __file__.rsplit('/', 1)[0] + '/emu')
import trace_diff as T
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN
st, rb, ledger, nm = sys.argv[1:5]
S = T.Img(st); R = T.Img(rb, nmfile=nm)
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN); md.skipdata = True
def code(img, a, n):
    for nmx, vm, vs, data in img.segs:
        if vm <= a < vm + len(data): return data[a - vm:a - vm + n]
    return b''
ORD = re.compile(r'^(blt|bgt|ble|bge|bnl|bng)')
def counts(img, a, n):
    sgn = uns = 0; ins = [i for i in md.disasm(code(img, a, n), a) if i.mnemonic != '.long']
    for k, i in enumerate(ins):
        m = i.mnemonic
        if m.startswith('cmp') and not m.startswith('cmpd'):
            nxt = [j.mnemonic for j in ins[k + 1:k + 4]]
            if any(ORD.match(x.rstrip('+-')) for x in nxt[:3]):
                if m.startswith('cmpl'): uns += 1
                else: sgn += 1
    return sgn, uns
rsyms = {n: a for a, n in R.syms}; raddrs = sorted(a for a, n in R.syms)
bal = S.bal
bad = []; n = 0
for l in open(ledger):
    p = l.rstrip('\n').split('\t')
    if len(p) < 3 or not p[0].startswith('0x'): continue
    sa = int(p[0], 16) - bal; size = int(p[1]); name = p[2]
    ra = rsyms.get(name) or rsyms.get('_' + name)
    if ra is None: continue
    i = bisect.bisect_right(raddrs, ra); rsize = (raddrs[i] - ra) if i < len(raddrs) else size
    n += 1; a = counts(S, sa, size); b = counts(R, ra, rsize)
    if a != b: bad.append((name, a, b))
print('%d functions compared, %d differ in (signed,unsigned) ordering-compare counts' % (n, len(bad)))
for name, a, b in bad: print('%-50s stock s/u %s rebuilt s/u %s' % (name, a, b))
