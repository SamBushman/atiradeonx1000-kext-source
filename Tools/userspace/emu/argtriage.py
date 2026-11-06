#!/usr/bin/env python3
"""argtriage.py STOCK.bin FUNCS.tsv REBUILT.bin REBUILT.nm [NAME ...]   (issue #201)

Finds call sites where the stock code sets an argument register (r4..r10) before a call but the rebuilt code leaves it unset on some path, and
decides whether the callee reads it.  (calldiff.py's ARGS list pairs the n-th indirect call of each image, which is wrong as soon as the compiler
reorders blocks; this pairs the n-th call to the same callee / the n-th virtual call through the same vtable slot.)

  stock side    register written in the straight-line window between the previous call and this one
  rebuilt side  a backward walk over the CFG from the paired call: register not written on SOME path before a call / the function entry
                (entry is fine for an incoming parameter) = the argument is garbage on that path
  callees       direct call: the stock function at the target.  Virtual call (`lwz rX,OFF(rY); mtctr; bctrl` with rY loaded by `lwz rY,0(..)`):
                every function at slot OFF/4 of the compiler's vtables (runs of text pointers anchored by their Class__vslotN names)
Rows: CHECK  some callee reads the register (the rebuilt call omits a real argument)   BENIGN  no callee reads it
      UNKNOWN callee set unresolved (call through a context function pointer)           MISSING  stock call without a counterpart
Needs the emu module (only emu.load is used; `unicorn` can be an empty stub package)."""
import sys, re, bisect, struct, collections, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import capstone, emu

stock_bin, funcs_tsv = sys.argv[1:3]
reb_bin = reb_nm = None
args_ = sys.argv[3:]
if len(args_) >= 2 and args_[0].endswith('.bin'): reb_bin, reb_nm = args_[0], args_[1]; args_ = args_[2:]
only = set(args_)
funcs = {}; nparams_of = {}
for l in open(funcs_tsv):
    p = l.rstrip('\n').split('\t')
    if len(p) >= 2: funcs[p[1]] = int(p[0], 16); nparams_of[p[1]] = int(p[2]) if len(p) > 2 and p[2].isdigit() else 4
by_addr = {a: n for n, a in funcs.items()}
starts = sorted(by_addr)

segs, stubs, zero, fill, textr = emu.load(stock_bin)
mem = {}
for name, vm, vs, data in segs: mem[(vm, vm + len(data))] = data
def rd(a, n):
    for (lo, hi), d in mem.items():
        if lo <= a and a + n <= hi: return d[a - lo:a - lo + n]
    return b''
md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
TLO = min(lo for lo, hi in ([textr] if isinstance(textr, tuple) else textr)) if textr else 0
def in_text(a):
    for lo, hi in ([textr] if isinstance(textr, tuple) else textr):
        if lo <= a < hi: return True
    return False
def fsize(a):
    i = bisect.bisect_right(starts, a)
    return (starts[i] if i < len(starts) else a + 0x400) - a

_dc = {}
def decode(a, n):
    key = (a, n)
    if key not in _dc:
        d = rd(a, n); out = []
        for o in range(0, len(d) - 3, 4):
            x = list(md.disasm(d[o:o + 4], a + o)); out.append(x[0] if x else None)
        _dc[key] = out
    return _dc[key]

NOWRITE = re.compile(r'^(st|cmp|mt|b|tw|dcb|sync|isync|eieio|nop|icbi|lwarx|stwcx|cr|mcrf|sc)')
REG = re.compile(r'\br(\d{1,2})\b')
def rw(ins):
    """(reads, write) register sets of one instruction (r0..r31); approximate but conservative for reads."""
    m = ins.mnemonic; regs = [int(x) for x in REG.findall(ins.op_str)]
    if NOWRITE.match(m) and not m.startswith('stwcx'):
        return set(regs), None        # stores / compares / branches / mt*: every named register is read
    if not regs: return set(), None
    d = regs[0]; rd_ = set(regs[1:])
    if m in ('li', 'lis'): rd_ = set()
    if m.startswith('lm') or m.startswith('stm'): return set(range(d, 32)), None
    # `addi rA,0,..` / lwz rA,off(r0): r0 in an address field means 0 - harmless to count as read, r0 is never an argument register
    return rd_, d

def entry_reads(addr, reg, depth=0, seen=None):
    """Does the function at addr read `reg` (4..10) before writing it on some path? -> ('READ', insn) | ('PASS', callee name) | None"""
    if seen is None: seen = set()
    if (addr, reg) in seen or depth > 2: return None
    seen.add((addr, reg))
    size = fsize(addr); end = addr + size
    insns = {i.address: i for i in decode(addr, size) if i is not None}
    work = [addr]; vis = set(); res = None
    while work:
        a = work.pop()
        while a in insns and a not in vis:
            vis.add(a); i = insns[a]; m = i.mnemonic
            r, w = rw(i)
            if reg in r:
                return ('READ', '%x: %s %s' % (a, m, i.op_str))
            if w == reg: break
            if m in ('bl',) or m.startswith('bla'):
                try: t = int(i.op_str.replace('0x', ''), 16)
                except ValueError: break
                if t != a + 4:
                    nm = by_addr.get(t)
                    if nm is not None:
                        sub = entry_reads(t, reg, depth + 1, seen)
                        if sub: return ('PASS', nm + ' -> ' + sub[1])
                    # reg is argument-clobbered by the call afterwards
                    break
                a += 4; continue
            if m in ('bctrl', 'blrl'): break
            if m == 'blr': break
            if m == 'b':
                try: t = int(i.op_str.replace('0x', ''), 16)
                except ValueError: break
                if addr <= t < end: a = t; continue
                nm = by_addr.get(t)
                if nm is not None:
                    sub = entry_reads(t, reg, depth + 1, seen)
                    if sub: return ('PASS', nm + ' -> ' + sub[1])
                break
            if m == 'bctr': break
            if m.startswith('b') and m not in ('bl', 'blr', 'bctr'):      # conditional branch: follow both
                t = None
                mm = re.search(r'(0x[0-9a-f]+)\s*$', i.op_str)
                if mm: t = int(mm.group(1), 16)
                if t is not None and addr <= t < end: work.append(t)
            a += 4
    return res

# ---- vtable-like runs in the data segments: consecutive text pointers
runs = []
for (lo, hi), d in mem.items():
    if in_text(lo): continue
    cur = []
    for o in range(0, len(d) - 3, 4):
        w = struct.unpack('>I', d[o:o + 4])[0]
        if in_text(w) and w % 4 == 0:
            cur.append(w)
        else:
            if len(cur) >= 4: runs.append(cur)
            cur = []
    if len(cur) >= 4: runs.append(cur)
slot_targets = collections.defaultdict(set)
VS = re.compile(r'vslot(\d+)')
for run in runs:
    # the compiler's vtables: a run is anchored by its members named Class__vslotN... (N = byte offset / 4 from the address point)
    votes = collections.Counter()
    for k, w in enumerate(run):
        mm = VS.search(by_addr.get(w, ''))
        if mm: votes[int(mm.group(1)) - k] += 1
    if not votes: continue
    base, nv = votes.most_common(1)[0]
    if nv < max(1, len([w for w in run if VS.search(by_addr.get(w, ''))]) // 2): continue
    for k, w in enumerate(run):
        if w in by_addr: slot_targets[base + k].add(w)
for a_, n_ in by_addr.items():
    mm = VS.search(n_)
    if mm: slot_targets[int(mm.group(1))].add(a_)

# ---- call sites: (addr, kind, slot|callee, virt, window-written regs) of one function body given a decoded {addr: insn} map
rins_ref = [None]
def sites_of(ins, a0, size, tgtname):
    addrs = sorted(ins); res = []; last = a0
    seq = [ins[a] for a in addrs]
    for idx, a in enumerate(addrs):
        i = ins[a]; m = i.mnemonic; kind = None; tgt = None
        if m == 'bl' or m.startswith('bla'):
            try: tgt = int(i.op_str.replace('0x', ''), 16)
            except ValueError: continue
            if tgt == a + 4: last = a + 4; continue
            if ins is rins_ref[0] and is_helper(tgt): continue
            kind = 'bl'
        elif m == 'bctrl': kind = 'bctrl'
        elif m == 'b':
            try: tgt = int(i.op_str.replace('0x', ''), 16)
            except ValueError: continue
            if a0 <= tgt < a0 + size: continue
            if ins is rins_ref[0] and is_helper(tgt): continue
            kind = 'bl'                       # tail call out of the function
        elif m == 'bctr':
            back = [ins[x] for x in addrs[max(0, idx - 6):idx]]
            if any(x.mnemonic == 'mtctr' for x in back) and any(re.match(r'lwz r\d+, -?(0x)?[0-9a-f]+\(r\d+\)', x.mnemonic + ' ' + x.op_str) for x in back) \
               and not any(x.mnemonic.startswith('lwzx') for x in back): kind = 'tailctr'
        if kind is None: continue
        win = set(); lastw = {}
        wl = [x for x in addrs if last <= x < a]
        for pos, x in enumerate(wl):
            _r, w = rw(ins[x])
            if w is not None and 4 <= w <= 10: lastw[w] = pos
        for w, pos in lastw.items():
            # an argument setup is the register's last write in the window and nothing in the window reads it afterwards
            # (a read means the register was a scratch temporary: `add r4,r4,r3; addi r30,r4,0xb4; ...; bctrl`)
            if not any(w in rw(ins[x])[0] for x in wl[pos + 1:]): win.add(w)
        last = a + 4
        slot = None; virt = False
        if kind != 'bl':
            j = idx - 1
            while j >= 0 and seq[j].mnemonic != 'mtctr': j -= 1
            if j >= 0:
                rx = int(REG.findall(seq[j].op_str)[0]); k = j - 1
                while k >= 0:
                    x = seq[k]
                    if x.mnemonic == 'lwz':
                        mm = re.match(r'r(\d+), (-?(?:0x)?[0-9a-f]+)\(r(\d+)\)', x.op_str)
                        if mm and int(mm.group(1)) == rx:
                            off = int(mm.group(2), 16) if 'x' in mm.group(2) else int(mm.group(2)); ry = int(mm.group(3)); q = k - 1
                            while q >= 0:
                                y = seq[q]
                                if y.mnemonic == 'lwz':
                                    m2 = re.match(r'r(\d+), (-?(?:0x)?[0-9a-f]+)\(r(\d+)\)', y.op_str)
                                    if m2 and int(m2.group(1)) == ry:
                                        o2 = int(m2.group(2), 16) if 'x' in m2.group(2) else int(m2.group(2)); virt = (o2 == 0); break
                                q -= 1
                            slot = off; break
                    if x.mnemonic in ('addi', 'li', 'mr', 'or') and int(REG.findall(x.op_str)[0]) == rx: break
                    k -= 1
        res.append((a, kind, tgtname(tgt) if tgt is not None else None, slot, virt, win))
    return res

def regs_unset_on_some_path(ins, a0, site, reg, nparams):
    preds = collections.defaultdict(list)
    for addr, i in ins.items():
        m = i.mnemonic; nxt = addr + 4
        if m not in ('blr', 'bctr', 'b') and nxt in ins: preds[nxt].append(addr)
        if m.startswith('b') and m not in ('blr', 'bctr', 'bctrl', 'blrl', 'bl'):
            mm = re.search(r'(0x[0-9a-f]+)\s*$', i.op_str)
            if mm:
                t = int(mm.group(1), 16)
                if t in ins: preds[t].append(addr)
    bad = []; seen = set(); work = [site]; entry = False
    while work:
        a = work.pop()
        for p in preds.get(a, []):
            if p in seen: continue
            seen.add(p); i = ins[p]
            if i.mnemonic in ('bl', 'bctrl', 'blrl') or i.mnemonic.startswith('bla'):
                tg_ = int(i.op_str.replace('0x', ''), 16) if i.mnemonic == 'bl' else None
                if not (tg_ is not None and (tg_ == p + 4 or is_helper(tg_))):
                    bad.append('call@%x' % p); continue
            _r, w = rw(i)
            if w == reg: continue
            if p == a0: entry = True
            work.append(p)
    if entry and reg - 3 >= nparams: bad.append('entry')
    return bad

def stock_tgt(t):
    if any(lo <= t < hi for lo, hi in stubs): return 'stub'
    return by_addr.get(t, '?%x' % t)

rsegs, rstubs, _z, _f, rtextr = emu.load(reb_bin)
RM = {}
for name, vm, vs, data in rsegs: RM[(vm, vm + len(data))] = data
rsym = {}; rall = []
for l in open(reb_nm):
    p_ = l.split()
    if len(p_) == 3: rsym[p_[2]] = int(p_[0], 16); rall.append(int(p_[0], 16))
rall = sorted(set(rall)); raddr_name = {}
for n_, a_ in rsym.items(): raddr_name.setdefault(a_, n_[4:] if n_.startswith('lbl_') else n_)
def rrd(a, n):
    for (lo, hi), d in RM.items():
        if lo <= a and a + n <= hi: return d[a - lo:a - lo + n]
    return b''
HELPER = re.compile(r'^(saveFP|restFP|saveGPR|restGPR|_save|_rest|_GH_)')
helper_rng = []
_rs = sorted(set(rsym.values()))
for n_, a_ in rsym.items():
    if HELPER.match(n_[4:] if n_.startswith('lbl_') else n_):
        j_ = bisect.bisect_right(_rs, a_); helper_rng.append((a_, _rs[j_] if j_ < len(_rs) else a_ + 0x100))
def is_helper(t): return any(lo <= t < hi for lo, hi in helper_rng)
def reb_tgt(t):
    if any(lo <= t < hi for lo, hi in rstubs): return 'stub'
    return raddr_name.get(t, '?%x' % t)
def body(read, a, sz):
    d = read(a, sz); out = {}
    for o in range(0, len(d) - 3, 4):
        x = list(md.disasm(d[o:o + 4], a + o))
        if x: out[a + o] = x[0]
    return out

HELP = re.compile(r'^(_save|_rest|_GH_|__|_vec_)')
cnt = collections.Counter(); rowsout = []
for fn in sorted(funcs, key=lambda n: funcs[n]):
    if only and fn not in only: continue
    rn = fn if fn in rsym else 'lbl_' + fn
    if rn not in rsym: continue
    sa = funcs[fn]; ssz = fsize(sa); ra = rsym[rn]
    i_ = bisect.bisect_right(rall, ra); rsz = (rall[i_] if i_ < len(rall) else ra + 0x400) - ra
    if ssz < 8 or rsz < 8 or ssz > 0x8000 or rsz > 0x20000: continue
    sins = body(rd, sa, ssz); rins = body(rrd, ra, rsz)
    ss = sites_of(sins, sa, ssz, stock_tgt); rins_ref[0] = rins; rs = sites_of(rins, ra, rsz, reb_tgt); rins_ref[0] = None
    # pair by (virtual slot | callee name), n-th occurrence of each
    def key(x):
        if x[1] == 'bl': return ('d', x[2]) if x[2] and not x[2].startswith('?') and x[2] != 'stub' and not HELP.match(x[2]) else None
        return ('v', x[3]) if x[4] and x[3] is not None else ('x', x[3])
    sg = collections.defaultdict(list); rg = collections.defaultdict(list)
    for x in ss:
        k = key(x)
        if k: sg[k].append(x)
    for x in rs:
        k = key(x)
        if k: rg[k].append(x)
    for k, lst in sg.items():
        rx_all = list(rg.get(k, [])); used = set()
        def sset(sx):
            return [r_ for r_ in sorted(sx[5]) if not regs_unset_on_some_path(sins, sa, sx[0], r_, nparams_of.get(fn, 4))]
        def unset_of(rsx, regs): return {r_: regs_unset_on_some_path(rins, ra, rsx[0], r_, nparams_of.get(fn, 4)) for r_ in regs}
        # a stock call is matched to a rebuilt call of the same callee / slot that sets every register the stock call sets (the compiler reorders
        # blocks, so the n-th call of one image is not the n-th of the other); leftovers are reported against the best remaining candidate
        pend = []
        order_ = sorted(((n, sx, sset(sx)) for n, sx in enumerate(lst)), key=lambda t: -len(t[2]))      # widest argument lists first
        for n, sx, regs in order_:
            hit = None; best = None
            for j, rsx in enumerate(rx_all):
                if j in used or any(unset_of(rsx, regs).values()): continue
                if best is None or len(rsx[5]) < best: hit, best = j, len(rsx[5])
            if hit is not None: used.add(hit)
            else: pend.append((n, sx, regs))
        for n, sx, regs in pend:
            cand = [(j, rsx) for j, rsx in enumerate(rx_all) if j not in used]
            if not cand:
                rowsout.append(('MISSING', fn, k, n, '', 'stock call %x of %s has no unused counterpart (rebuilt makes %d)' % (sx[0], k, len(rx_all)))); cnt['MISSING'] += 1; continue
            j, rsx = min(cand, key=lambda c: sum(1 for v in unset_of(c[1], regs).values() if v)); used.add(j)
            for reg, bad in unset_of(rsx, regs).items():
                if not bad: continue
                if k[0] == 'd': cands = [funcs[k[1]]] if k[1] in funcs else []
                elif k[0] == 'v': cands = sorted(slot_targets.get(k[1] // 4, ()))
                else: cands = []
                if not cands:
                    cnt['UNKNOWN'] += 1
                    rowsout.append(('UNKNOWN', fn, k, n, 'r%d' % reg, 'stock %x rebuilt %x: no callee set (%s)' % (sx[0], rsx[0], bad[:2]))); continue
                hits = []
                for c in cands:
                    r = entry_reads(c, reg)
                    if r: hits.append('%s: %s %s' % (by_addr.get(c, hex(c)), r[0], r[1]))
                if hits:
                    cnt['CHECK'] += 1
                    rowsout.append(('CHECK', fn, k, n, 'r%d' % reg, 'stock %x rebuilt %x unset on %s | %d/%d callees read it: %s' % (sx[0], rsx[0], ','.join(sorted(set(bad))[:3]), len(hits), len(cands), '; '.join(hits[:3]))))
                else:
                    cnt['BENIGN'] += 1
                    rowsout.append(('BENIGN', fn, k, n, 'r%d' % reg, 'stock %x rebuilt %x: none of %d callees reads it' % (sx[0], rsx[0], len(cands))))
for r in rowsout: print('\t'.join(str(x) for x in r))
print('SUMMARY', dict(cnt), file=sys.stderr)
