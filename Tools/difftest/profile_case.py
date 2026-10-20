#!/usr/bin/env python3
"""profile_case.py CASEFILE.py FILTER [SEEDS] - where do the estimated cycles of a difftest case go, stock against rebuilt?

For each side: the executed instructions by class (loads, stores, multiplies, divides, branches, everything else) summed over SEEDS seeds
(default 20) of the first case whose name contains FILTER, and the instruction-class difference. A rebuilt side with more loads is re-reading
memory the stock code reads once; more divides means a division the stock code does not do, and so on. Needs $STOCK_KEXT and the rebuilt
image ($REBUILT_KEXT, default build/difftest/rebuilt.bin). Run from the repository root."""
import sys, os, random, zlib, struct, collections
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)))); sys.path.insert(0, 'Tests/difftest')
import difftest as d


def klass(w):
    op = w >> 26
    if op in (32, 33, 34, 35, 40, 41, 42, 43, 46, 48, 49, 50, 51): return 'load'
    if op in (36, 37, 38, 39, 44, 45, 47, 52, 53, 54, 55): return 'store'
    if op == 31:
        xo = (w >> 1) & 0x3ff
        if xo in (23, 87, 279, 343, 534, 535, 599, 55, 119, 311, 375): return 'load'
        if xo in (151, 215, 407, 662, 663, 727, 247, 183, 439): return 'store'
        if xo in (491, 459, 395, 363): return 'div'
        if xo in (235, 75, 11): return 'mul'
    if op == 7: return 'mul'
    if op in (16, 18, 19): return 'branch'
    if op == 24 and w == 0x60000000: return 'nop'
    if op in (59, 63): return 'fp'
    return 'other'


def run(case, img, other, reg, seeds):
    sym = d.find_symbol(img, case.function, case.signature)
    tot = collections.Counter(); cyc = 0
    for seed in range(seeds):
        m = d.Machine(img, reg, seed, lazy=case.lazy, mock_policy=case.mock, limit=case.limit, stack_args=case.stack_args, transparent=case.transparent)
        m.ignore_args = case.ignore_args; m.out_extents = case.out_extents; m.plain_words = case.plain_words
        m.exclusive = (set(img.funcs) - set(other.funcs))
        rng = random.Random(seed * 7919 + zlib.crc32(case.name.encode()))
        kinds = d.signature_of(sym)[1] or []
        args = case.world(m, rng, kinds) if getattr(case.world, '__code__', None) and case.world.__code__.co_argcount >= 3 else case.world(m, rng)
        r = m.call(sym, args)
        if r.status != 'RET': continue
        own = r.own
        for (a, n), cnt in r.visited.items():
            for x in range(a, a + n, 4):
                if own[0] <= x < own[1]:
                    w = struct.unpack('>I', bytes(m.patched[x:x + 4]))[0]
                    tot[klass(w)] += cnt; cyc += cnt * d.insn_cost(w)
    return tot, cyc


def main():
    cf, flt = sys.argv[1], sys.argv[2]; seeds = int(sys.argv[3]) if len(sys.argv) > 3 else 20
    stock = d.Image(os.environ['STOCK_KEXT'], 'stock'); rebuilt = d.Image(os.environ.get('REBUILT_KEXT', 'build/difftest/rebuilt.bin'), 'rebuilt'); reg = d.StubRegistry()
    case = next(c for c in d.load_cases(cf) if flt in c.name)
    (ts, cs), (tr, cr) = run(case, stock, rebuilt, reg, seeds), run(case, rebuilt, stock, reg, seeds)
    print('%s: cycles (own code only) stock %d rebuilt %d (x%.2f)' % (case.name, cs, cr, cr / max(cs, 1)))
    for k in ('load', 'store', 'mul', 'div', 'fp', 'branch', 'nop', 'other'):
        print('  %-7s stock %7d rebuilt %7d  (%+d)' % (k, ts[k], tr[k], tr[k] - ts[k]))


if __name__ == '__main__':
    main()
