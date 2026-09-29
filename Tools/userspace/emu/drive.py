#!/usr/bin/env python3
import sys, re, bisect, random, collections
sys.path.insert(0, '/tmp/emu')
from emu import *

nm = [l.split() for l in open(__import__('os').environ.get('RNM','/tmp/emu/rebuilt.nm')) if len(l.split()) == 3]
rsyms = {n.lstrip('_'): int(a, 16) for a, t, n in nm}
entries_r = {n: a for n, a in rsyms.items() if n.startswith('FUN_')}
# normalisation tables: (image address, name, stock address)
def table(which):
    t = []
    for n, a in rsyms.items():
        m = re.match(r'(?:DAT|FUN|PTR_DAT|PTR_FUN|s_|switchD)\w*?_?([0-9a-f]{8})$', n)
        if m and n.startswith(('DAT_', 'PTR_DAT_')):
            t.append((a if which == 'r' else int(m.group(1), 16), n))
    t.sort(); return t
TAB = {'s': table('s'), 'r': table('r')}
KEYS = {k: [a for a, n in v] for k, v in TAB.items()}
IMG = {'s': (0, 0x200000), 'r': (0, 0x800000)}

def norm(which, w, snaps=None):
    if w is None: return None
    if w >= 0xfffff000: return ('const', w)
    if HEAP <= w < HEAP + HEAP_SIZE: return ('heap', w - HEAP)
    if STACK <= w < STACK + STACK_SIZE: return ('stk',)
    if CTXA <= w < CTXA + CTX_SIZE: return ('ctx', w - CTXA)
    if AA <= w < AA + A_SIZE: return ('A', w - AA)
    if HOOK <= w < HOOK + 0x1000: return ('hook', (w - HOOK) // 16)
    lo, hi = IMG[which]
    if 0x1000 <= w < hi:
        i = bisect.bisect_right(KEYS[which], w) - 1
        if i >= 0 and w - KEYS[which][i] < 0x2000:
            a, n = TAB[which][i]; return ('sym', n, w - a)
        return ('img?', )
    return ('int', w)

NW = {0x12e4:4,0x12ec:4,0x12f0:4,0x1300:4,0x1304:4,0x1308:4,0x130c:4,0x1324:4,0x1328:4,0x12f4:8,0x12f8:8,0x12fc:8,0x132c:8}
def normcall(which, c):
    slot, r, st, sn = c[:4]
    out = [slot]
    nw = NW.get(slot, 0)
    st = st[:nw] + [0] * (8 - nw); sn = list(sn[:8 + nw]) + [None] * (8 - nw)
    words = r + st
    for k, w in enumerate(words):
        n = norm(which, w)
        if n == ('stk',) and sn[k] is not None and not __import__('os').environ.get('NOSTK'): n = ('stk', tuple(norm(which, x) for x in sn[k]))
        out.append(n)
    return tuple(out)

def run(fn, nargs, seeds, extra_arg=None):
    s = Runner(Image('/tmp/emu/stock.bin', None)); r = Runner(Image(__import__('os').environ.get('RBIN','/tmp/emu/rebuilt.bin'), None))
    es = int(fn.split('_')[1], 16); er = entries_r[fn]
    diffs = collections.Counter(); ex = {}; reached = 0; both_ok = 0
    for seed in range(seeds):
        rng = random.Random(seed)
        ctx, heap, a = mkmem(rng, {})
        args = [CTXA] + [rng.choice([0, 1, 2, 3, 4, 5, 7, 9, 0xffffffff, HEAP + 0x100]) for _ in range(nargs - 1)]
        res = []
        for rn, e in ((s, es), (r, er)):
            rn.reset(ctx, heap, a)
            st, rv = rn.call(e, list(args))
            res.append((st, rv, [normcall('s' if rn is s else 'r', c) for c in rn.log]))
        (st1, rv1, l1), (st2, rv2, l2) = res
        if l1 or l2: reached += 1
        m = min(len(l1), len(l2))
        if l1 or l2:
            for i in range(m):
                a1, a2 = l1[i], l2[i]
                if a1 != a2:
                    for k in range(len(a1)):
                        if a1[k] != a2[k]:
                            key = (a1[0], 'call%d' % i, ('arg%d' % k) if k <= 8 else ('word%d' % (k - 9)))
                            diffs[key] += 1; ex.setdefault(key, (seed, a1[k], a2[k]))
            if len(l1) != len(l2): diffs[('CALLCOUNT', len(l1), len(l2))] += 1; ex.setdefault(('CALLCOUNT', len(l1), len(l2)), (seed, st1, st2))
        if l1 and l1 == l2: both_ok += 1
    return reached, both_ok, diffs, ex

if __name__ == '__main__':
    fn = sys.argv[1]; nargs = int(sys.argv[2]); seeds = int(sys.argv[3])
    reached, ok, diffs, ex = run(fn, nargs, seeds)
    print(fn, 'runs reaching a hook:', reached, 'identical logs:', ok)
    for k, c in sorted(diffs.items(), key=lambda x: -x[1])[:40]: print(c, k, ex[k])
