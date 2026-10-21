#!/usr/bin/env python3
"""trace_case.py CASEFILE.py FILTER SEED [OUTPREFIX] - the instructions each side executes (in the function under test only) for one seed, as
OUTPREFIX.stock.txt / OUTPREFIX.rebuilt.txt (offset from the function's entry, capstone text), and a register-blind diff (only mnemonics and
immediates/displacements are compared) that shows where the rebuilt code executes extra instructions. Run from the repository root with
$STOCK_KEXT and $REBUILT_KEXT set."""
import sys, os, re, random, zlib, struct, difflib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__))); sys.path.insert(0, 'Tests/difftest')
import difftest as d
import capstone
from unicorn import UC_HOOK_CODE
md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 + capstone.CS_MODE_BIG_ENDIAN)


def trace(case, img, other, reg, seed):
    sym = d.find_symbol(img, case.function, case.signature); entry = img.funcs[sym]
    m = d.Machine(img, reg, seed, lazy=case.lazy, mock_policy=case.mock, limit=case.limit, stack_args=case.stack_args, transparent=case.transparent)
    m.ignore_args = case.ignore_args; m.out_extents = case.out_extents; m.plain_words = case.plain_words
    m.exclusive = (set(img.funcs) - set(other.funcs))
    rng = random.Random(seed * 7919 + zlib.crc32(case.name.encode()))
    kinds = d.signature_of(sym)[1] or []
    args = case.world(m, rng, kinds) if getattr(case.world, '__code__', None) and case.world.__code__.co_argcount >= 3 else case.world(m, rng)
    out = []
    def hk(uc, addr, size, ud):
        if m.own[0] <= addr < m.own[1]:
            w = bytes(uc.mem_read(addr, 4))
            for i in md.disasm(w, addr):
                out.append((addr - entry, '%s %s' % (i.mnemonic, i.op_str)))
    m.uc.hook_add(UC_HOOK_CODE, hk)
    m.call(sym, args)
    return out


def norm(t):
    mn, ops = t.split(' ', 1) if ' ' in t else (t, '')
    ops = re.sub(r'\br\d+\b|\bcr\d\b', 'R', ops)
    return mn + ' ' + ops


def main():
    cf, flt, seed = sys.argv[1], sys.argv[2], int(sys.argv[3]); pre = sys.argv[4] if len(sys.argv) > 4 else 'trace'
    stock = d.Image(os.environ['STOCK_KEXT'], 'stock'); rebuilt = d.Image(os.environ.get('REBUILT_KEXT', 'build/difftest/rebuilt.bin'), 'rebuilt'); reg = d.StubRegistry()
    case = next(c for c in d.load_cases(cf) if flt in c.name)
    ts, tr = trace(case, stock, rebuilt, reg, seed), trace(case, rebuilt, stock, reg, seed)
    for n, t in (('stock', ts), ('rebuilt', tr)):
        open('%s.%s.txt' % (pre, n), 'w').write(''.join('%x\t%s\n' % x for x in t))
    a, b = [norm(t) for _, t in ts], [norm(t) for _, t in tr]
    print('%s seed %d: stock %d insns, rebuilt %d insns' % (case.name, seed, len(a), len(b)))
    if len(a) + len(b) > 6000:                       # too long for a sequence diff: compare the multisets of (register-blind) instructions instead
        import collections
        ca, cb = collections.Counter(a), collections.Counter(b)
        delta = sorted(((cb[k] - ca[k], k) for k in set(ca) | set(cb)), reverse=True)
        print('instruction multiset difference (rebuilt - stock), largest first:')
        for n, k in delta[:int(os.environ.get('TOP', '25'))]: print('  %+6d  %s' % (n, k))
        print('...and the largest decreases:')
        for n, k in delta[-int(os.environ.get('TOP', '25')):]: print('  %+6d  %s' % (n, k))
        return
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    agg = {}
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal': continue
        key = (tuple(ts[i1:i2][:12]), tuple(tr[j1:j2][:12]), (i2 - i1, j2 - j1))
        agg.setdefault((tuple(x[0] for x in ts[i1:i2][:1]), tuple(x[0] for x in tr[j1:j2][:1])), []).append((key, i2 - i1, j2 - j1))
    print('hunks grouped by first offsets (stock/rebuilt), with repeat count and net extra instructions in the rebuilt trace:')
    rows = sorted(agg.items(), key=lambda kv: -sum(j - i for _, i, j in kv[1]))
    for (so, ro), lst in rows[:int(os.environ.get('TOP', '25'))]:
        key = lst[0][0]
        print('--- x%d  net %+d insns  stock@%s rebuilt@%s' % (len(lst), sum(j - i for _, i, j in lst), ['%x' % o for o in so], ['%x' % o for o in ro]))
        for x in key[0]: print('  - %x\t%s' % x)
        for x in key[1]: print('  + %x\t%s' % x)


if __name__ == '__main__':
    main()
