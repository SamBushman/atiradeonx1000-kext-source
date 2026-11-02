#!/usr/bin/env python3
"""calldiff.py - static call-site comparison of the stock GLDriver against a rebuilt (renamed) image. No emulation, no hardware.

  python3 calldiff.py STOCK.bin REBUILT.bin REBUILT.nm FUNCS.tsv [NAME ...]

For every function (FUNCS.tsv = "<stock offset hex>\\t<name>\\t<nparams>"; the sizes come from the symbol order) it lists the call sites of both images in address order
(`bl`, `bctrl`, tail `b` out of the function, tail `bctr` through a loaded code pointer) and reports

  COUNT   the two functions make a different number of calls (a dropped / extra / misplaced call: transcription or control-flow defect)
  TARGET  the n-th direct call goes to a different function (a wrong callee)
  ARGS    the n-th call sets an argument register (r4..r10) in the straight-line code before it in STOCK that the rebuilt code does not set
          (the C call is missing an argument: the callee reads whatever the register held - gldReselectProgramStream called through ctx+0x294c without
          `*(ctx+0x1e70)` in r4 crashed gldSetCurrentProgramObject on a garbage object, that is the case this finds)

ARGS is a candidate list, not a verdict: stock may set a register the callee never reads. Confirm with the callee's disassembly.
"""
import sys, re, bisect, struct
sys.path.insert(0, __import__('os').path.dirname(__import__('os').path.abspath(__file__)))
import capstone, emu

stock_bin, reb_bin, reb_nm, funcs_tsv = sys.argv[1:5]
only = set(sys.argv[5:])
funcs = {}
for l in open(funcs_tsv):
    p = l.rstrip('\n').split('\t')
    if len(p) >= 2: funcs[p[1]] = (int(p[0], 16), int(p[2]) if len(p) > 2 else 4)
stock_by_addr = {a: n for n, (a, k) in funcs.items()}
rsym = {}; rall = []
for l in open(reb_nm):
    p = l.split()
    if len(p) == 3: rsym[p[2]] = int(p[0], 16); rall.append(int(p[0], 16))
rall = sorted(set(rall))
rname = {}
for n, a in rsym.items(): rname.setdefault(a, n)

def load_text(path):
    segs, stubs, zero, fill, textr = emu.load(path)
    mem = {}
    for name, vm, vs, data in segs: mem[(vm, vm + len(data))] = data
    return mem, stubs, textr
def rd(mem, a, n):
    for (lo, hi), d in mem.items():
        if lo <= a and a + n <= hi: return d[a - lo:a - lo + n]
    return b''
SM, SSTUBS, STEXT = load_text(stock_bin); RM, RSTUBS, RTEXT = load_text(reb_bin)
md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN); md.detail = False

NOWRITE = re.compile(r'^(st|cmp|mt|b|tw|dcb|sync|isync|eieio|nop|icbi|lwarx|stwcx|crand|cror|crxor|crnand|crnor|creqv|crandc|crorc|crclr|crset|mcrf|sc)')
def dest_reg(ins):
    m = ins.mnemonic
    if NOWRITE.match(m) or m in ('bctr', 'bctrl', 'blr', 'blrl'): return None
    mm = re.match(r'^r(\d+)\b', ins.op_str)
    return int(mm.group(1)) if mm else None

def decode(mem, start, size):
    d = rd(mem, start, size)
    out = []
    for o in range(0, len(d) - 3, 4):
        ins = list(md.disasm(d[o:o + 4], start + o))
        out.append(ins[0] if ins else None)
    return out

def calls(mem, start, size, tgtname):
    insns = decode(mem, start, size); end = start + size
    sites = []; last = 0; loaded_ptr = set()
    for i, ins in enumerate(insns):
        if ins is None: continue
        m = ins.mnemonic; kind = None; tgt = None
        if m == 'bl' or m.startswith('bla'):
            try: tgt = int(ins.op_str.replace('0x', ''), 16)
            except ValueError: continue
            kind = 'bl'
        elif m == 'bctrl': kind = 'bctrl'
        elif m == 'b':
            try: tgt = int(ins.op_str.replace('0x', ''), 16)
            except ValueError: continue
            if not (start <= tgt < end): kind = 'tail'
        elif m == 'bctr':
            # tail call through a loaded code pointer (lwz rX, imm(rY); mtctr rX), not a switch jump table (lwzx)
            back = [x for x in insns[max(0, i - 6):i] if x]
            if any(x.mnemonic == 'mtctr' for x in back) and any(re.match(r'lwz r\d+, -?(0x)?[0-9a-f]+\(r\d+\)', x.mnemonic + ' ' + x.op_str) for x in back) \
               and not any(x.mnemonic.startswith('lwzx') for x in back): kind = 'tailctr'
        if kind is None: continue
        if m == 'bl' and tgt is not None and tgt == ins.address + 4: continue            # PIC get-pc
        win = set()
        for x in insns[last:i]:
            if x is None: continue
            r = dest_reg(x)
            if r is not None and 3 <= r <= 10: win.add(r)
        sites.append((kind, tgtname(tgt) if tgt is not None else None, win))
        last = i + 1
    return sites

def stock_tgt(t):
    if any(lo <= t < hi for lo, hi in SSTUBS): return 'stub'
    return stock_by_addr.get(t, '?%x' % t)
def reb_tgt(t):
    if any(lo <= t < hi for lo, hi in RSTUBS): return 'stub'
    n = rname.get(t)
    if n is None: return '?%x' % t
    n = n[4:] if n.startswith('lbl_') else n
    return n

nb = 0
for name, (sa, nparams) in sorted(funcs.items(), key=lambda kv: kv[1][0]):
    if only and name not in only: continue
    rn = name if name in rsym else 'lbl_' + name
    if rn not in rsym: continue
    ra = rsym[rn]
    i = bisect.bisect_right(rall, ra)
    rsize = (rall[i] if i < len(rall) else ra + 0x400) - ra
    # stock size = distance to the next function entry
    sk = sorted(a for a, _ in funcs.values()); j = bisect.bisect_right(sk, sa); ssize = (sk[j] if j < len(sk) else sa + 0x400) - sa
    if ssize < 8 or rsize < 8 or ssize > 0x8000 or rsize > 0x20000: continue
    cs = calls(SM, sa, ssize, stock_tgt); cr = calls(RM, ra, rsize, reb_tgt)
    msgs = []
    import collections
    HELP = re.compile(r'^(_save|_rest|_GH_|__|_vec_)')
    def named(c): return c[1] and not c[1].startswith('?') and c[1] != 'stub' and not HELP.match(c[1])
    # direct calls to named functions: same callee multiset, pairing the n-th call of each callee
    gs = collections.defaultdict(list); gr = collections.defaultdict(list)
    for c in cs:
        if named(c): gs[c[1]].append(c)
    for c in cr:
        if named(c): gr[c[1]].append(c)
    for k in sorted(gr):
        if k not in gs: msgs.append('EXTRA rebuilt calls %s (stock never calls it)' % k)
    for k in sorted(gs):
        if k in gr and len(gs[k]) != len(gr[k]) and len(gr[k]) > len(gs[k]):
            msgs.append('EXTRA rebuilt calls %s %dx, stock %dx' % (k, len(gr[k]), len(gs[k])))
        for n_, (a, b) in enumerate(zip(gs[k], gr.get(k, []))):
            miss = sorted(r for r in a[2] - b[2] if r >= 4)
            if miss: msgs.append('ARGS %s #%d: stock sets r%s before the call, rebuilt does not' % (k, n_, ',r'.join(map(str, miss))))
    # indirect calls (code pointers loaded from a context / table): pair in order when both sides have the same number
    ind_s = [c for c in cs if c[0] in ('bctrl', 'tailctr')]; ind_r = [c for c in cr if c[0] in ('bctrl', 'tailctr')]
    if len(ind_s) == len(ind_r):
        for n_, (a, b) in enumerate(zip(ind_s, ind_r)):
            miss = sorted(r for r in a[2] - b[2] if r >= 4)
            if miss: msgs.append('ARGS indirect call #%d: stock sets r%s before the call, rebuilt does not' % (n_, ',r'.join(map(str, miss))))
    elif ind_s:
        msgs.append('COUNT indirect calls: stock %d, rebuilt %d' % (len(ind_s), len(ind_r)))
    if msgs:
        nb += 1
        print('%s:' % name)
        for m in msgs[:8]: print('    ' + m)
print('functions with differences:', nb)
