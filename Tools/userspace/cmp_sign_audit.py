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
BOUNDED = re.compile(r'^(lbz|lhz|lbzx|lhzx|lbzu|lhzu|andi\.|clrlwi|rlwinm|rlwimi|srwi|extrwi|li|lis|mr)')
BR = re.compile(r'^(b|bl|blr|bctr|bctrl|beq|bne|blt|bgt|ble|bge|bnl|bng|bdnz|bdz)')
def regs(i): return [x.strip() for x in i.op_str.split(',')]
def bounded(ins, k, reg):
    """True if register `reg` as compared at ins[k] was defined in the same block by an instruction whose result is provably in [0, 2^31): zero-extending loads, masks (clrlwi/andi./rlwinm with mb>0),
    logical right shifts (srwi n>0), small non-negative immediates. Then signed and unsigned compare agree and the difference is not a defect."""
    for j in range(k - 1, max(-1, k - 12), -1):
        i = ins[j]; m = i.mnemonic.rstrip('+-')
        if BR.match(m) and not m.startswith('cmp'): return False
        r = regs(i)
        if r and r[0] == reg and not m.startswith(('cmp', 'st', 'b')):
            if m.startswith(('lbz', 'lhz', 'andi.')): return True
            if m in ('clrlwi', 'srwi') : return True
            if m == 'rlwinm':
                try: return int(r[3], 0) > 0 or int(r[2],0) == 0 and False
                except Exception: return False
            if m == 'li':
                try: return int(r[1], 0) >= 0
                except Exception: return False
            if m == 'mr': return bounded(ins, j, r[1])
            return False
    return False
def counts(img, a, n):
    """(signed, unsigned) ordering compares whose operands are NOT provably non-negative (sign-neutral compares are skipped)."""
    sgn = uns = 0; ins = [i for i in md.disasm(code(img, a, n), a) if i.mnemonic != '.long']
    for k, i in enumerate(ins):
        m = i.mnemonic
        if m.startswith('cmp') and not m.startswith('cmpd'):
            nxt = [j.mnemonic for j in ins[k + 1:k + 4]]
            if any(ORD.match(x.rstrip('+-')) for x in nxt[:3]):
                r = regs(i)
                if len(r) < 3: continue
                ops = [r[1]]
                if not m.endswith('i'): ops.append(r[2])
                elif m == 'cmpwi' and int(r[2], 0) < 0: ops = [None]
                if all(o is not None and bounded(ins, k, o) for o in ops): continue
                if m.startswith('cmpl'): uns += 1
                else: sgn += 1
    return sgn, uns
def rpairs(img, a, n):
    """(unsigned, signed) range-check pairs: `addi/subi/addic rD,rS,imm` then `cmplwi/cmpwi cr,rD,N` on the same register within 2 instructions and an ordering branch after it.
    The shape of `x - C < N` (class: lost unsigned compare). Stock unsigned vs rebuilt signed at the same function is the lead; sign-neutral compares are not filtered here."""
    ins = [i for i in md.disasm(code(img, a, n), a) if i.mnemonic != '.long']; u = sg = 0
    for k, i in enumerate(ins):
        if i.mnemonic in ('addi', 'subi', 'addic', 'addic.', 'subic') and ins[k].op_str.count(',') == 2:
            d = regs(i)[0]
            for j in ins[k + 1:k + 3]:
                if j.mnemonic in ('cmplwi', 'cmpwi') and regs(j)[1] == d and any(ORD.match(x.mnemonic.rstrip('+-')) for x in ins[ins.index(j) + 1:ins.index(j) + 3]):
                    if j.mnemonic == 'cmplwi': u += 1
                    else: sg += 1
                    break
    return u, sg
rsyms = {n: a for a, n in R.syms}; raddrs = sorted(a for a, n in R.syms)
bal = S.bal
bad = []; pairs = []; n = 0
for l in open(ledger):
    p = l.rstrip('\n').split('\t')
    if len(p) < 3 or not p[0].startswith('0x'): continue
    sa = int(p[0], 16) - bal; size = int(p[1]); name = p[2]
    ra = rsyms.get(name) or rsyms.get('_' + name)
    if ra is None: continue
    i = bisect.bisect_right(raddrs, ra); rsize = (raddrs[i] - ra) if i < len(raddrs) else size
    n += 1; a = counts(S, sa, size); b = counts(R, ra, rsize)
    if a != b: bad.append((name, a, b))
    pa = rpairs(S, sa, size); pb = rpairs(R, ra, rsize)
    if pa[0] > pb[0] or pb[1] > pa[1]: pairs.append((name, pa, pb))
print('%d functions compared, %d differ in (signed,unsigned) ordering-compare counts' % (n, len(bad)))
for name, a, b in bad: print('%-50s stock s/u %s rebuilt s/u %s' % (name, a, b))
print('\nrange-check pairs (addi+cmpli/cmpi) where stock has more unsigned or rebuilt has more signed: %d functions   [unsigned,signed]' % len(pairs))
for name, a, b in pairs: print('%-50s stock %s rebuilt %s' % (name, a, b))
