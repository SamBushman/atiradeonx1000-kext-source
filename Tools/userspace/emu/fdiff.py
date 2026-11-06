#!/usr/bin/env python3
"""fdiff.py - per-function differential emulation of the stock GLDriver vs a rebuilt (renamed) image, no dispatch table needed.

  PYTHONPATH=<dir with unicorn> python3 fdiff.py STOCK.bin REBUILT.bin REBUILT.nm FUNCS.tsv SEEDS NAME [NAME ...]
  PYTHONPATH=... python3 fdiff.py STOCK.bin REBUILT.bin REBUILT.nm FUNCS.tsv SEEDS @namefile        (one name per line; '#' comments)

FUNCS.tsv = "<stock offset hex>\\t<name>\\t<nparams>" (Tools/userspace/emu/funcs_from_corpus.py writes it). Each seed runs the stock function and the rebuilt one of the SAME name on identical
random memory (ctx, A, heap, a stack scratch buffer) with identical random register arguments, then compares the return value, every word of the snapshotted memory and the order of the
dispatch/stub calls. Arguments are drawn from values that matter to the lane/select-word helpers (bytes 0..4, small ints, pointers into the scratch buffer / heap).
Output: one line per function (compared / same) and, for each distinct divergence kind, the first example. A run is skipped when either side faults, times out or reads its own code
(a pointer argument that is not a pointer). Void functions leave garbage in r3: such a 'ret' divergence on its own is NOT a defect (check the declaration).
"""
import sys, os, struct, random, collections, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import emu
from emu import *

stock_bin, reb_bin, reb_nm, funcs_tsv, seeds = sys.argv[1:6]; seeds = int(seeds)
names = []
for a in sys.argv[6:]:
    if a.startswith('@'):
        names += [l.split('#')[0].strip() for l in open(a[1:]) if l.split('#')[0].strip()]
    else:
        names.append(a)
funcs = {}
for l in open(funcs_tsv):
    p = l.rstrip('\n').split('\t')
    if len(p) >= 2: funcs[p[1]] = (int(p[0], 16), int(p[2]) if len(p) > 2 else 4)
rsym = {}
for l in open(reb_nm):
    p = l.split()
    if len(p) == 3: rsym[p[2]] = int(p[0], 16)
# rebuilt data/function symbols that have a stock-address suffix, for normalising image pointers (function entries by name)
rfun = sorted((rsym[n if n in rsym else 'lbl_' + n], funcs[n][0]) for n in funcs if n in rsym or 'lbl_' + n in rsym)
rfk = [a for a, _ in rfun]
sfun = set(a for a, _ in funcs.values())
import bisect
def norm(which, w):
    if w >= 0xfffff000: return ('const', w)
    if HEAP <= w < HEAP + HEAP_SIZE: return ('heap', w - HEAP)
    if STACK <= w < STACK + STACK_SIZE: return ('stk',)
    if CTXA <= w < CTXA + CTX_SIZE: return ('ctx', w - CTXA)
    if AA <= w < AA + A_SIZE: return ('A', w - AA)
    if HOOK <= w < HOOK + 0x1000: return ('hook', (w - HOOK) // 16)
    if which == 's': return ('img', w) if w in sfun else ('int', w)
    i = bisect.bisect_left(rfk, w)
    if i < len(rfk) and rfk[i] == w: return ('img', rfun[i][1])     # a function entry, named by its stock address; any other address in an image is compared as the plain integer
    return ('int', w)

BUF = STACK + 0x8000
POOL = [0, 1, 2, 3, 4, 5, 7, 0x10, 0xff, 0xffffffff, 0x00010203, 0x04010203, 0x00040203, 0x00010403, 0x00010204, 0x04040404, 0x03020100, 0x01020304,
        0x04030201, 0x00000004, 0x04000000, 0x00040000, 0x00000400, 0x01010101, 0x02020202, 0x03030303]
def rand_arg(rng):
    x = rng.random()
    if x < 0.40: return rng.choice(POOL)
    if x < 0.55: return sum(rng.randrange(0, 5) << (8 * i) for i in range(4))            # four lanes, each 0..4
    if x < 0.65: return BUF + 16 * rng.randrange(0, 8)
    if x < 0.75: return HEAP + 0x100 + 16 * rng.randrange(0, 64)
    if x < 0.80: return rng.randrange(0, 0x100)
    return rng.getrandbits(32)

REGIONS = ((CTXA, CTX_SIZE, 'c'), (AA, A_SIZE, 'a'), (HEAP, 0x8000, 'h'), (BUF, 0x200, 'b'))
def rawsnap(rn):
    return [bytes(rn.uc.mem_read(base, size)) for base, size, tag in REGIONS]

def memdiff(w_s, w_r, rs, rr):
    """words that differ between the two raw snapshots in value AND in normalised form"""
    out = []
    for (base, size, tag), x, y in zip(REGIONS, rs, rr):
        if x == y: continue
        for i in range(0, size, 4):
            u = struct.unpack('>I', x[i:i + 4])[0]; v = struct.unpack('>I', y[i:i + 4])[0]
            if u != v and norm('s', u) != norm('r', v) and not (isdata(DS, u) and isdata(DR, v)): out.append(((tag, i), norm('s', u), norm('r', v)))
    return out

# Stack-passed words (args 9+) of the function-table dispatch calls: the number of words each slot reads (0x12e4/0x12ec/... 4, 0x12f4/... 8). Comparing them catches a wrong
# 9th..16th argument (#201: the ffvp blended-position loops passed glCtx where stock passes the selector-derived register).
NSTK = {0x12e4: 4, 0x12ec: 4, 0x12f0: 4, 0x1300: 4, 0x1304: 4, 0x1308: 4, 0x130c: 4, 0x1324: 4, 0x1328: 4, 0x12f4: 8, 0x12f8: 8, 0x12fc: 8, 0x132c: 8}
def normlog(w, rn):
    return [(c[0], tuple(('poison',) if (x & 0xfffff000) == POISON else norm(w, x) for x in list(c[1]) + list(c[2][:NSTK.get(c[0], 0)]))) for c in rn.log]

def logsame(ls, lr):
    if len(ls) != len(lr): return False
    for a, b in zip(ls, lr):
        if a[0] != b[0]: return False
        for x, y in zip(a[1], b[1]):
            if x != y and x != ('poison',) and not (x[0] == 'int' and y[0] == 'int' and isdata(DS, x[1]) and isdata(DR, y[1])): return False
    return True

def callp(rn, entry, args, nreal):
    """Runner.call with every argument register the function does not take set to a poison value, so a call whose argument the rebuilt code leaves stale is visible"""
    uc = rn.uc; rn.log = []; rn.n = 0; rn.limit = 60000; rn.status = '?'; rn.bad_read = False
    for i in range(32): uc.reg_write(UC_PPC_REG_0 + i, 0)
    for i in range(3 + nreal, 13): uc.reg_write(UC_PPC_REG_0 + i, POISON + i)
    uc.reg_write(UC_PPC_REG_1, STACK + STACK_SIZE - 0x1000)
    for i, a in enumerate(args): uc.reg_write(UC_PPC_REG_0 + 3 + i, a)
    uc.reg_write(UC_PPC_REG_LR, emu.STOP)
    try:
        uc.emu_start(entry, emu.STOP, count=rn.limit + 10)
        if rn.status == '?': rn.status = 'RET'
    except UcError as ex_:
        rn.status = 'ERR:%s' % ex_
    return rn.status, uc.reg_read(UC_PPC_REG_3)

S = Runner(Image(stock_bin, None)); R = Runner(Image(reb_bin, None))
def _dataranges(img):
    return [(vm, vm + vs) for name, vm, vs, data in img.segs if name != '__TEXT'] + [(a, a + (b - a)) for a, b in []]
DS, DR = _dataranges(S.img), _dataranges(R.img)
def isdata(rn_ranges, v): return any(lo <= v < hi for lo, hi in rn_ranges)
CTXSLOTS = [0x748, 0x74c, 0x2754, 0x2758, 0x275c, 0x294c, 0x2998, 0x299c]      # code pointers stored in the GL context (`(**(code **)(glContext + off))(...)` in the corpus)
BASE_SLOTS = list(emu.SLOTS); EXTRA_SLOTS = [0x10000 + o for o in CTXSLOTS]
emu.SLOTS[:] = BASE_SLOTS + EXTRA_SLOTS
MEM = {}
def seedmem(seed):
    if seed not in MEM:
        emu.SLOTS[:] = BASE_SLOTS                      # mkmem lays the A-block dispatch table out from SLOTS
        ctx, heap, a = mkmem(random.Random(seed), {})
        emu.SLOTS[:] = BASE_SLOTS + EXTRA_SLOTS
        ctx = bytearray(ctx)
        for k, o in enumerate(CTXSLOTS): struct.pack_into('>I', ctx, o, HOOK + 16 * (len(BASE_SLOTS) + k))
        MEM[seed] = (bytes(ctx), heap, a)
    return MEM[seed]
POISON = 0xBAD00000
tot_bad = 0
for fn in names:
    if fn not in funcs: print(fn, 'NOT IN FUNCS'); continue
    rn_ = fn if fn in rsym else 'lbl_' + fn
    if rn_ not in rsym: print(fn, 'NOT IN REBUILT'); continue
    es, nargs = funcs[fn]; er = rsym[rn_]
    bad = collections.Counter(); ex = {}; tot = same = 0
    for seed in range(seeds):
        rng = random.Random(seed * 7919 + __import__("zlib").crc32(fn.encode()) % 1000)
        ctx, heap, a = seedmem(seed % 12)
        args = [rand_arg(rng) for _ in range(max(1, min(nargs, 8)))]
        if rng.random() < 0.5: args[0] = rng.choice([CTXA, BUF, BUF, HEAP + 0x200]) if nargs else args[0]
        buf = bytes(rng.randrange(0, 5) if rng.random() < 0.7 else rng.getrandbits(8) for _ in range(0x200))
        if os.environ.get('FDIFF_EXHAUST'): args = [seed] + [0] * (len(args) - 1)
        res = []
        for rn, e, w in ((S, es, 's'), (R, er, 'r')):
            rn.reset(ctx, heap, a); rn.uc.mem_write(BUF, buf)
            try: st, rv = callp(rn, e, list(args), len(args))
            except Exception as ex_: st, rv = 'EXC', 0
            res.append((st, norm(w, rv), rawsnap(rn), normlog(w, rn), rn.bad_read))
        if res[0][0] != 'RET' or res[1][0] != 'RET' or res[0][4] or res[1][4]: continue
        tot += 1
        d = memdiff('s', 'r', res[0][2], res[1][2])
        rs_, rr_ = res[0][1], res[1][1]
        retdiff = rs_ != rr_ and not (rs_[0] == 'int' and rr_[0] == 'int' and isdata(DS, rs_[1]) and isdata(DR, rr_[1]))
        if not retdiff and not d and logsame(res[0][3], res[1][3]): same += 1; continue
        key = ('ret' if retdiff else '') + (' mem:' + d[0][0][0] if d else '') + (' calls' if not logsame(res[0][3], res[1][3]) else '')
        bad[key] += 1
        if os.environ.get('FDIFF_VERBOSE') and 'calls' in key and key not in ex: print('  stock calls:', res[0][3][:6], '\n  new   calls:', res[1][3][:6])
        ex.setdefault(key, (seed, [hex(x) for x in args], res[0][1], res[1][1], d[:3]))
    flag = '' if tot == same else '  <== DIFFERS'
    print('%-52s compared %3d same %3d%s' % (fn, tot, same, flag))
    for k, v in bad.most_common(4): print('     %d x %s  e.g. %s' % (v, k, ex[k]))
    if tot != same: tot_bad += 1
print('functions with divergences:', tot_bad)
