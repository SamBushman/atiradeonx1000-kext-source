#!/usr/bin/env python3
"""sem_equiv.py BASE.dis CAND.dis [FUNCTION ...] [-v]

Tier-2 semantic equivalence checker for the userspace naming gate (tier 1 is split_equiv.py, which stays the primary gate). Both files are `gcc -arch ppc -S`
text (-O0, PIC). For every function present in both it decides whether CAND does the same thing as BASE as seen from OUTSIDE the function:

  * the same inputs are consumed: argument registers at calls, the incoming stack arguments, the registers/slots a later block reads are proven equal;
  * the same externally observable events happen in the same ORDER with the same values: every access to non-private memory (a store, and also a load,
    because a device-register read has side effects), every call (target, r3..r10, f1..f13, outgoing stack words) and the return (r3, r4, f1 and the
    callee-saved registers);
  * the same control flow (identical block graph, identical branch conditions).

The function's own stack frame is private: its slots are forwarded symbolically, so a split variable (one slot -> two, other frame offsets, a bigger frame,
a different commutative operand order, other register names for temporaries inside a block) is accepted, because values - not slot numbers - are compared.
Method: lock-step per-basic-block symbolic execution with hash-consed terms (uninterpreted functions for every operation), then a simulation relation
between the two programs' block-entry state is inferred and checked on every CFG edge (a slot of CAND may stand for a slot of BASE at the entry of a block;
the pairs are found by unifying the terms of the observable events and are then proven on every incoming edge, to a fixpoint).

Verdict per function: EQUIVALENT (proven) | IDENTICAL-CODE (same instructions) | UNINIT-PAIRED (equivalent except that a slot is read on a path that never wrote it, in both programs: needs a look) | DIFFERENT (a definite observable difference: other event kind/count, other constant, other control flow) |
INCONCLUSIVE (the checker could not prove it: reason printed; never counts as equivalent). Exit status 0 only when every compared function is EQUIVALENT.

Limits (all lead to INCONCLUSIVE, never to EQUIVALENT): address-taken frame slots (`addi rX,r30,K` / `la`) - the object may be reached through the pointer, so
a layout shift is not provable; partial overlaps of frame accesses; instructions it does not model that touch memory; unequal block graphs; a register
live across a block edge that is renamed."""
import re, sys, os

# --------------------------------------------------------------------------------------------- parsing
LABEL = re.compile(r'^("?[A-Za-z_$.][^\s"]*"?):$')
PBNUM = re.compile(r'"L\d+\$(s?pb)"')


class Inconclusive(Exception): pass
class Different(Exception): pass


class Ins:
    __slots__ = ('mn', 'ops', 'text', 'labels')

    def __init__(self, mn, ops, text): self.mn = mn; self.ops = ops; self.text = text; self.labels = []


def split_ops(s):
    out, d, cur = [], 0, ''
    for ch in s:
        if ch == '(': d += 1
        elif ch == ')': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur.strip())
    return out


def parse_funcs(path):
    """-> {name: Func}; Func.ins = [Ins], Func.labels = {label: index}, Func.tables = {bctr index: [labels]}"""
    funcs = {}; cur = None; pend = []; lastb = None
    for l in open(path, errors='replace'):
        l = l.rstrip('\n')
        m = re.match(r'^(_[A-Za-z0-9_$.]*):$', l)
        if m:
            cur = Func(m.group(1)); funcs[cur.name] = cur; pend = []; lastb = None; continue
        if re.match(r'^L_[A-Za-z0-9_$.]*\$stub:$', l): cur = None; continue
        if cur is None: continue
        m = LABEL.match(l)
        if m: pend.append(m.group(1).strip('"')); continue
        m = re.match(r'^\t\.long\s+(\S+)-(\S+)$', l)
        if m and lastb is not None: cur.tables.setdefault(lastb, []).append(m.group(1)); continue
        m = re.match(r'^\t([a-z][a-z0-9.+-]*)(?:\s+(.*))?$', l)
        if m:
            txt = PBNUM.sub(r'"L$\1"', m.group(2) or '')
            ins = Ins(m.group(1), split_ops(txt), l.strip())
            for lab in pend: cur.labels[lab] = len(cur.ins)
            pend = []
            cur.ins.append(ins)
            lastb = len(cur.ins) - 1 if m.group(1) == 'bctr' else None
    return funcs


class Func:
    def __init__(self, name): self.name = name; self.ins = []; self.labels = {}; self.tables = {}; self.lab_order = {}


# --------------------------------------------------------------------------------------------- terms
_intern = {}


def T(*a):
    return _intern.setdefault(a, a)


def C(n): return T('c', n & 0xffffffff if n >= 0 else n & 0xffffffff)


def sgn(n):
    n &= 0xffffffff
    return n - (1 << 32) if n & 0x80000000 else n


COMM = {'add', 'mullw', 'mulhw', 'mulhwu', 'and', 'or', 'xor', 'nor', 'nand', 'eqv', 'fadd', 'fadds', 'fmul', 'fmuls'}


def mk_add(a, b):
    """sums are kept flat: ('add', const, sorted non-constant terms...)"""
    if a[0] == 'rgn' and b[0] == 'c': return T('rgn', a[1] + sgn(b[1]))
    if b[0] == 'rgn' and a[0] == 'c': return T('rgn', b[1] + sgn(a[1]))
    if a[0] == 'sp' and b[0] == 'c': return T('sp', a[1] + sgn(b[1]))
    if b[0] == 'sp' and a[0] == 'c': return T('sp', b[1] + sgn(a[1]))
    parts, k = [], 0
    for x in (a, b):
        if x[0] == 'c': k += sgn(x[1])
        elif x[0] == 'add':
            k += sgn(x[1][1]) if x[1][0] == 'c' else 0
            parts.extend(x[2:])
        else: parts.append(x)
    parts.sort(key=repr)
    if not parts: return C(k)
    if k == 0 and len(parts) == 1: return parts[0]
    return T('add', C(k), *parts)


def mk_op(mn, *args):
    if mn in COMM: args = tuple(sorted(args, key=repr))
    return T('op', mn, *args)


def spoff(t):
    """('sp', a) -> a  (address = entry stack pointer + a); None for anything else"""
    return t[1] if t[0] == 'sp' else None


def sp_add(t, k):
    if t[0] == 'sp': return T('sp', t[1] + k)
    return None


# --------------------------------------------------------------------------------------------- per-block evaluation
REG = re.compile(r'^(r\d+|f\d+|v\d+)$')
CRF = re.compile(r'^cr(\d)$')
MEMOP = re.compile(r'^(.*)\((r\d+)\)$')
LOAD1 = {'lwz': 4, 'lwzu': 4, 'lbz': 1, 'lbzu': 1, 'lhz': 2, 'lhzu': 2, 'lha': 2, 'lhau': 2, 'lfs': 4, 'lfsu': 4, 'lfd': 8, 'lfdu': 8}
STORE1 = {'stw': 4, 'stwu': 4, 'stb': 1, 'stbu': 1, 'sth': 2, 'sthu': 2, 'stfs': 4, 'stfsu': 4, 'stfd': 8, 'stfdu': 8}
LOADX = {'lwzx': 4, 'lbzx': 1, 'lhzx': 2, 'lhax': 2, 'lfsx': 4, 'lfdx': 8, 'lvx': 16, 'lwbrx': 4, 'lhbrx': 2, 'lvewx': 4, 'lvebx': 1, 'lvehx': 2, 'lvxl': 16}
STOREX = {'stwx': 4, 'stbx': 1, 'sthx': 2, 'stfsx': 4, 'stfdx': 8, 'stvx': 16, 'stwbrx': 4, 'sthbrx': 2, 'stvewx': 4, 'stvebx': 1, 'stvehx': 2, 'stvxl': 16}
CALLEE_SAVED = ['r%d' % i for i in range(13, 32)] + ['f%d' % i for i in range(14, 32)]
ARGS = ['r%d' % i for i in range(3, 11)] + ['f%d' % i for i in range(1, 14)]
CLOBBER = ['r0', 'r2', 'r3', 'r4', 'r5', 'r6', 'r7', 'r8', 'r9', 'r10', 'r11', 'r12'] + ['f%d' % i for i in range(0, 14)] + ['v%d' % i for i in range(0, 20)] + ['ctr', 'ca', 'cr0', 'cr1', 'cr5', 'cr6', 'cr7']
BRANCH_COND = re.compile(r'^b(eq|ne|lt|gt|le|ge|so|ns|dnz|dz|dnzt|dnzf|dzt|dzf|c)[+-]?$')


class Block:
    def __init__(self, k, lo, hi): self.k = k; self.lo = lo; self.hi = hi; self.succ = []; self.kind = None


def build_blocks(f):
    ins = f.ins; n = len(ins)
    tgt = lambda x: f.labels.get(x.strip('"'))
    leaders = {0}
    for i, x in enumerate(ins):
        mn = x.mn
        if mn == 'b' or BRANCH_COND.match(mn) and mn not in ('bl',) or mn in ('blr', 'bctr', 'bctrl') and False:
            if mn not in ('bl', 'bctrl', 'bcl'):
                t = tgt(x.ops[-1]) if x.ops else None
                if t is not None: leaders.add(t)
                if i + 1 < n: leaders.add(i + 1)
        if mn in ('blr', 'bctr'):
            if i + 1 < n: leaders.add(i + 1)
        if mn == 'bctr':
            for lab in f.tables.get(i, []):
                t = tgt(lab)
                if t is not None: leaders.add(t)
    ls = sorted(l for l in leaders if l < n)
    blocks = [Block(k, l, (ls[k + 1] if k + 1 < len(ls) else n)) for k, l in enumerate(ls)]
    at = {b.lo: b.k for b in blocks}
    for b in blocks:
        last = ins[b.hi - 1]; mn = last.mn
        if mn == 'b':
            t = tgt(last.ops[-1]); b.kind = 'b'; b.succ = [at[t]] if t is not None else []
            if t is None: raise Inconclusive('branch to unknown label %s' % last.ops[-1])
        elif mn == 'blr': b.kind = 'ret'; b.succ = []
        elif mn == 'bctr':
            b.kind = 'switch'; b.succ = [at[tgt(x)] for x in f.tables.get(b.hi - 1, []) if tgt(x) in at]
            if not f.tables.get(b.hi - 1): raise Inconclusive('bctr without jump table')
        elif BRANCH_COND.match(mn) and mn not in ('bl',) and mn not in ('bctrl',):
            t = tgt(last.ops[-1]); b.kind = 'bc'
            if t is None: raise Inconclusive('conditional branch to unknown label')
            b.succ = [at[t]] + ([b.k + 1] if b.k + 1 < len(blocks) else [])
        else:
            b.kind = 'fall'; b.succ = [b.k + 1] if b.k + 1 < len(blocks) else []
    return blocks


def frame_size(f):
    for x in f.ins[:12]:
        m = re.match(r'^-(\d+)\(r1\)$', x.ops[1]) if x.mn == 'stwu' and len(x.ops) == 2 and x.ops[0] == 'r1' else None
        if m: return int(m.group(1))
    return None


def address_taken(f):
    """frame offsets whose address escapes: `addi rX,r30,K`, `la rX,K(r30)`, and the same through r1"""
    s = set()
    for x in f.ins:
        if x.mn == 'addi' and len(x.ops) == 3 and x.ops[1] in ('r30', 'r1'): s.add(x.ops[2])
        if x.mn == 'la' and len(x.ops) == 2:
            m = MEMOP.match(x.ops[1])
            if m and m.group(2) in ('r30', 'r1'): s.add(m.group(1))
    return s


def taken_min(f, N):
    """lowest frame address (relative to the entry stack pointer) whose address is taken via r30, or None"""
    best = None
    for x in f.ins:
        k = None
        if x.mn == 'addi' and len(x.ops) == 3 and x.ops[1] == 'r30': k = x.ops[2]
        if x.mn == 'la' and len(x.ops) == 2:
            m = MEMOP.match(x.ops[1])
            if m and m.group(2) == 'r30': k = m.group(1)
        if k is not None:
            try: a = int(k, 0) - N
            except ValueError: raise Inconclusive('symbolic frame address ' + x.text)
            best = a if best is None else min(best, a)
        if x.mn in ('addi', 'la') and any(o.endswith('(r1)') or o == 'r1' for o in x.ops[1:]) and x.ops[0] != 'r30' and not (x.mn == 'addi' and x.ops[0] == 'r30'):
            if not (x.mn == 'addi' and x.ops[1] == 'r1' and x.ops[0] == 'r30'): raise Inconclusive('address of the outgoing area is taken (%s)' % x.text)
    return best


class Eval:
    """symbolic state of one block of one program (side 'b' or 'c')"""

    def __init__(self, side, f, N, blk, first, amin=None, absmode=False):
        self.amin = amin; self.rbase = 0 if absmode else (amin or 0)
        self.side = side; self.f = f; self.N = N; self.blk = blk
        self.regs = {}; self.slots = {}; self.events = []; self.entry_slots = {}; self.entry_regs = set()
        self.fp = T('sp', -N) if N is not None else None
        if first:
            self.regs['r1'] = T('sp', 0)
        else:
            if N is not None: self.regs['r1'] = self.fp; self.regs['r30'] = self.fp
        self.lastcall = None
        self.term = None

    # registers
    def get(self, r):
        if r == 'r0lit': return C(0)
        if r not in self.regs:
            self.regs[r] = T('E', r); self.entry_regs.add(r)
        return self.regs[r]

    def put(self, r, v): self.regs[r] = v

    def val(self, o):
        if REG.match(o) or o in ('ctr', 'lr', 'ca'): return self.get(o)
        m = CRF.match(o)
        if m: return self.get(o)
        return self.imm(o)

    def imm(self, o):
        try: return C(int(o, 0))
        except ValueError: pass
        o = o.strip()
        m = re.match(r'^(ha16|lo16)\((.*)\)$', o)
        if m:
            inner = re.sub(r'\bL(\d+)\b', lambda q: 'L#%d' % self.f.lab_order.setdefault(q.group(1), len(self.f.lab_order)), m.group(2))      # local labels (jump tables): numbered by first reference, not by name
            return T('sym', m.group(1), inner)
        return T('sym', 'raw', o)

    def ea(self, op):
        m = MEMOP.match(op)
        if not m: raise Inconclusive('odd memory operand ' + op)
        d, ra = m.group(1), m.group(2)
        base = C(0) if ra == 'r0' else self.get(ra)
        try: dv = int(d, 0); return mk_add(base, C(dv)), ra, dv
        except ValueError: return mk_add(base, self.imm(d)), ra, None

    # memory
    def classify(self, addr, basereg, disp, size):
        """-> ('slot', key) private frame slot | ('ext', None)"""
        a = spoff(addr)
        if a is None and addr[0] == 'add' and any(p[0] == 'sp' for p in addr[2:]):        # sp + non-constant: an indexed frame access (array element)
            raise Inconclusive('indexed access into the frame')
        if a is None and addr[0] == 'rgn': return ('ext', None)
        if a is None: return ('ext', None)
        if a >= 0: return ('ext', None)           # caller frame: incoming stack arguments, saved LR
        if self.amin is not None and a >= self.amin and basereg == 'r30':
            return ('rgn', T('rgn', a - self.rbase))      # the object whose address escaped (and everything above it): an externally observable region, addressed relative to its lowest escaped byte
        if self.N is not None and basereg == 'r1' and self.regs.get('r1') == self.fp and disp is not None and 0 <= disp < 0x70: return ('slot', ('out', disp, size))
        return ('slot', ('a', a, size))

    def slot_read(self, key):
        if key in self.slots: return self.slots[key]
        # partial overlap with a different-size store?
        for k in self.slots:
            if k[0] == key[0] and k[1] < key[1] + key[2] and key[1] < k[1] + k[2]: raise Inconclusive('partial overlap of frame accesses at %r' % (key,))
        s = T('S', self.side, key)
        self.entry_slots[key] = s
        return s

    def slot_write(self, key, v):
        for k in list(self.slots):
            if k != key and k[0] == key[0] and k[1] < key[1] + key[2] and key[1] < k[1] + k[2]: raise Inconclusive('partial overlap of frame accesses at %r' % (key,))
        self.slots[key] = v

    def ext_event(self, kind, size, addr, val=None):
        n = len(self.events)
        self.events.append((kind, size, addr, val))
        return n

    def do_load(self, dest, size, addr, basereg, disp, mn):
        kind, key = self.classify(addr, basereg, disp, size)
        if kind == 'rgn': addr = key; kind = 'ext'
        if kind == 'slot':
            if mn in ('lha', 'lhax', 'lhau'): v = mk_op('exts16', self.slot_read(key))
            else: v = self.slot_read(key)
            self.put(dest, v)
        else:
            n = self.ext_event('ld', size, addr)
            self.put(dest, T('ld', mn, n, size, addr))

    def do_store(self, srcterm, size, addr, basereg, disp):
        kind, key = self.classify(addr, basereg, disp, size)
        if kind == 'rgn': addr = key; kind = 'ext'
        if kind == 'slot': self.slot_write(key, srcterm)
        else: self.ext_event('st', size, addr, srcterm)

    # instruction
    def step(self, x, taken):
        mn, o = x.mn, x.ops
        rc = mn.endswith('.') and mn[:-1] or None
        base = rc or mn
        if mn in LOAD1 or mn in STORE1:
            size = LOAD1.get(mn) or STORE1[mn]
            ea, ra, disp = self.ea(o[1])
            if ra in ('r30', 'r1') and ea[0] != 'sp' and self.regs.get(ra) is None and False: pass
            if mn in LOAD1: self.do_load(o[0], size, ea, ra, disp, mn)
            else: self.do_store(self.get(o[0]), size, ea, ra, disp)
            if mn.endswith('u') and mn not in ('stb', 'stbu') or mn in ('lbzu', 'stbu', 'lhzu', 'lhau', 'sthu', 'lfsu', 'lfdu', 'stfsu', 'stfdu'):
                if mn.endswith('u'): self.put(ra, ea)
            if mn == 'lwz' and o[0] == 'r1' and o[1] == '0(r1)': self.put('r1', T('sp', 0))    # epilogue: r1 <- backchain
            return
        if mn in LOADX or mn in STOREX:
            ra, rb = o[1], o[2]
            ea = mk_add(C(0) if ra == 'r0' else self.get(ra), self.get(rb))
            if ea[0] == 'sp': pass
            size = LOADX.get(mn) or STOREX[mn]
            if mn in LOADX:
                kind, key = ('ext', None) if ea[0] != 'sp' and not (ea[0] == 'add') else self.classify(ea, None, None, size)
                if ea[0] == 'sp' or ea[0] == 'add' and any(p[0] == 'sp' for p in ea[2:]): raise Inconclusive('indexed access into the frame')
                n = self.ext_event('ld', size, ea); self.put(o[0], T('ld', mn, n, size, ea))
            else:
                if ea[0] == 'sp' or ea[0] == 'add' and any(p[0] == 'sp' for p in ea[2:]): raise Inconclusive('indexed access into the frame')
                self.ext_event('st', size, ea, self.get(o[0]))
            return
        if mn in ('stmw', 'lmw'):
            ea, ra, disp = self.ea(o[1]); first = int(o[0][1:])
            for i, r in enumerate(range(first, 32)):
                a = mk_add(ea, C(4 * i))
                if mn == 'stmw': self.do_store(self.get('r%d' % r), 4, a, ra, None if disp is None else disp + 4 * i)
                else: self.do_load('r%d' % r, 4, a, ra, None if disp is None else disp + 4 * i, 'lwz')
            return
        if mn in ('lswi', 'stswi', 'lswx', 'stswx', 'lwarx', 'stwcx.', 'dcbz', 'dcbt', 'dcbtst', 'dcbf', 'dcbi', 'dcbst', 'icbi', 'sync', 'isync', 'eieio', 'lscbx'):
            if mn in ('sync', 'isync', 'eieio'): self.ext_event('barrier', 0, T('sym', 'raw', mn)); return
            raise Inconclusive('unmodelled memory instruction ' + mn)
        # ---- moves, ALU
        if mn == 'mr': self.put(o[0], self.get(o[1])); return
        if mn in ('li', 'lis'):
            v = self.imm(o[1])
            if v[0] == 'c' and mn == 'lis': v = C(v[1] << 16)
            elif v[0] == 'sym' and mn == 'lis': v = T('op', 'lis', v)
            self.put(o[0], v); return
        if mn == 'addi' or mn == 'la':
            if mn == 'la': m = MEMOP.match(o[1]); d, ra = m.group(1), m.group(2)
            else: ra, d = o[1], o[2]
            b = C(0) if (ra == 'r0' and mn == 'addi') else self.get(ra)
            dv = self.imm(d)
            if (mn == 'addi' and o[1] == 'r30' or mn == 'la' and ra == 'r30') and self.amin is not None and dv[0] == 'c':
                self.put(o[0], T('rgn', sgn(dv[1]) - self.N - self.rbase)); return
            if mn == 'addi' and o[1] in ('r30', 'r1') or mn == 'la' and ra in ('r30', 'r1'): raise Inconclusive('address of a frame slot is taken (%s)' % x.text)
            self.put(o[0], mk_add(b, dv)); return
        if mn == 'addis':
            b = C(0) if o[1] == 'r0' else self.get(o[1]); dv = self.imm(o[2])
            if dv[0] == 'c': dv = C(dv[1] << 16)
            else: dv = T('op', 'shl16', dv)
            self.put(o[0], mk_add(b, dv)); return
        if mn == 'add': self.put(o[0], mk_add(self.get(o[1]), self.get(o[2]))); return
        if mn == 'subf':
            a, b = self.get(o[1]), self.get(o[2])
            if a[0] == 'c': self.put(o[0], mk_add(b, C(-sgn(a[1])))); return
            self.put(o[0], T('op', 'subf', a, b)); return
        if mn in ('mtlr', 'mtctr'): self.put(mn[2:], self.get(o[0])); return
        if mn in ('mflr', 'mfctr'): self.put(o[0], self.get(mn[2:])); return
        if mn == 'bcl':
            self.put('lr', T('pic')); return
        if mn == 'mfcr':
            self.put(o[0], T('op', 'mfcr', *[self.get('cr%d' % i) for i in range(8)])); return
        if mn in ('mtcrf', 'mtcr'): raise Inconclusive('mtcrf')
        m = re.match(r'^(cmp|cmpl|fcmpu|fcmpo|cmpw|cmplw|cmpwi|cmplwi)$', mn)
        if m:
            if mn.startswith('fcmp'): crf, a, b = o[0], o[1], o[2]; kind = 'f'
            else:
                if CRF.match(o[0]): crf, a, b = o[0], o[1], o[2]
                else: crf, a, b = 'cr0', o[0], o[1]
                kind = 'u' if mn in ('cmpl', 'cmplw', 'cmplwi') else 's'
            self.put(crf, T('cmp', kind, self.val(a), self.val(b))); return
        if mn in ('crnot', 'crxor', 'cror', 'crand', 'crnor', 'creqv', 'crandc', 'crorc', 'crset', 'crclr', 'crmove', 'mcrf', 'crnand'):
            srcs = tuple(self.get('cr%d' % i) for i in range(8))
            for i in range(8): self.put('cr%d' % i, T('crop', mn, tuple(o), i, srcs))
            return
        if mn in ('b', 'blr', 'bctr') or BRANCH_COND.match(mn) and mn != 'bl' or mn in ('bl', 'bctrl'):
            self.branch(x, taken); return
        # generic pure operation: dest = op(sources); first operand is the destination when it is a register
        if o and REG.match(o[0]):
            srcs = []
            for s in o[1:]:
                if REG.match(s) or CRF.match(s): srcs.append(self.get(s))
                else: srcs.append(self.imm(s))
            if base in ('adde', 'addc', 'subfc', 'subfe', 'addze', 'addme', 'subfze', 'subfme', 'subfic', 'addic', 'addic.'):
                ca = self.get('ca'); self.put('ca', T('op', 'ca_' + base, *srcs, ca))
                self.put(o[0], T('op', base, *srcs, ca)); return
            if base in ('rlwimi',): srcs = [self.get(o[0])] + srcs
            # simple constant folding
            if base in ('slwi', 'srwi') and srcs[0][0] == 'c' and srcs[1][0] == 'c':
                v = srcs[0][1]; s = srcs[1][1]
                self.put(o[0], C((v << s) if base == 'slwi' else (v >> s))); return
            v = mk_op(base, *srcs)
            self.put(o[0], v)
            if rc is not None: self.put('cr0', T('rc', v))
            return
        raise Inconclusive('unmodelled instruction ' + x.text)

    def branch(self, x, taken):
        mn = x.mn
        if mn == 'b': self.term = ('b',); return
        if mn == 'blr':
            self.term = ('ret',)
            vals = tuple((r, self.get(r)) for r in ['r3', 'r4', 'f1'] + CALLEE_SAVED)
            self.events.append(('ret', 0, None, vals)); return
        if mn == 'bctr': self.term = ('switch', self.get('ctr')); return
        if mn in ('bl', 'bctrl'):
            target = T('sym', 'call', x.ops[0]) if mn == 'bl' else self.get('ctr')
            args = tuple(self.get(r) for r in ARGS)
            outs = tuple(sorted((k, v) for k, v in self.slots.items() if k[0] == 'out'))
            n = len(self.events)
            self.events.append(('call', 0, target, (args, outs)))
            for r in CLOBBER:
                if r.startswith('cr') or r == 'ctr' or r == 'ca': self.put(r, T('cl', n, r))
                else: self.put(r, T('ret', n, r))
            # callee may modify any external memory; private slots are unaffected (no frame address escaped)
            self.put('lr', T('E', 'lr'))
            return
        # conditional branch
        crf = None
        for s in x.ops[:-1]:
            if CRF.match(s): crf = s
        if mn.startswith('bdnz') or mn.startswith('bdz'):
            self.put('ctr', mk_add(self.get('ctr'), C(-1)))
            self.term = ('bc', mn, self.get('ctr'))
        elif mn == 'bc' or mn.startswith('bc') and mn != 'bcl':
            self.term = ('bc', mn, tuple(x.ops[:-1]), tuple(self.get(s) for s in x.ops[:-1] if CRF.match(s)))
        else:
            self.term = ('bc', mn, self.get(crf or 'cr0'))


# --------------------------------------------------------------------------------------------- unification
def kids_shape(t):
    """-> (shape atoms, ordered kids, unordered kids) of a term"""
    tag = t[0]
    if tag == 'op': return (tag, t[1], len(t) - 2), list(t[2:]), None
    if tag == 'add': return (tag, t[1]), None, list(t[2:])
    if tag == 'ld': return (tag, t[1], t[2], t[3]), [t[4]], None
    if tag in ('rc',): return (tag,), [t[1]], None
    if tag == 'cmp': return (tag, t[1]), [t[2], t[3]], None
    if tag == 'crop': return (tag, t[1], t[2], t[3]), list(t[4]), None
    return t, [], None             # atoms: c sym E sp pic rgn ret cl


COMMUTATIVE_OPS = COMM
SEARCH = [0]
HINT = {}


def ua(c, b, bind):
    """all extensions of BIND (cand slot key -> base slot key) under which cand term C equals base term B; generator of fresh dicts"""
    SEARCH[0] += 1
    if SEARCH[0] > 400000: raise Inconclusive('unification search budget exhausted')
    if c[0] == 'S' and c[1] == 'c':
        if b[0] != 'S' or b[1] != 'b': return
        ck, bk = c[2], b[2]
        if ck[0] != bk[0] or ck[2] != bk[2]: return
        if ck in bind:
            if bind[ck] == bk: yield bind
            return
        nb = dict(bind); nb[ck] = bk; yield nb; return
    if b[0] == 'S': return
    if c is b: yield bind; return
    if c[0] != b[0]: return
    sc, kc, uc = kids_shape(c); sb, kb, ub = kids_shape(b)
    if sc != sb: return
    if kc is not None and ub is None:
        if len(kc) != len(kb): return
        pairs = list(zip(kc, kb))
        if c[0] == 'op' and c[1] in COMMUTATIVE_OPS and len(kc) == 2:
            for (p, q) in ((pairs[0], pairs[1]), ((kc[0], kb[1]), (kc[1], kb[0]))):
                yield from seq([p, q], bind)
            return
        yield from seq(pairs, bind); return
    if uc is not None:
        if len(uc) != len(ub): return
        yield from unordered(uc, ub, bind); return
    yield bind


def seq(pairs, bind):
    if not pairs: yield bind; return
    for nb in ua(pairs[0][0], pairs[0][1], bind):
        yield from seq(pairs[1:], nb)


def unordered(cs, bs, bind):
    if not cs: yield bind; return
    c0 = cs[0]
    order = sorted(range(len(bs)), key=lambda i: 0 if hint_ok(c0, bs[i]) else 1)
    for i in order:
        for nb in ua(c0, bs[i], bind):
            yield from unordered(cs[1:], bs[:i] + bs[i + 1:], nb)


def hint_ok(c, b):
    """does the positional hint pair the slot symbols of C and B? (only a search-order preference, never a constraint)"""
    if c[0] == 'S' and b[0] == 'S': return HINT.get(c[2]) == b[2]
    return True


def solve(pairs, bind):
    for nb in seq(pairs, bind): return nb
    return None


def unify(c, b, bind):
    r = solve([(c, b)], bind)
    if r is None: return False
    bind.clear(); bind.update(r); return True


def event_pairs(ec, eb):
    """structural comparison of two events; -> list of (cand term, base term) obligations or None when the events differ in kind/size/shape"""
    if ec[0] != eb[0] or ec[1] != eb[1]: return None
    k = ec[0]
    if k in ('ld', 'barrier'): return [(ec[2], eb[2])]
    if k == 'st': return [(ec[2], eb[2]), (ec[3], eb[3])]
    if k == 'call':
        (ac, oc), (ab, ob) = ec[3], eb[3]
        if [k_ for k_, _ in oc] != [k_ for k_, _ in ob]: return None
        return [(ec[2], eb[2])] + list(zip(ac, ab)) + [(x[1], y[1]) for x, y in zip(oc, ob)]
    if k == 'ret':
        if [r for r, _ in ec[3]] != [r for r, _ in eb[3]]: return None
        return [(v1, v2) for (_, v1), (_, v2) in zip(ec[3], eb[3])]
    return None


def subterms(t, acc):
    acc.append(t)
    sh, ordered, unord = kids_shape(t)
    for x in (ordered or []) + (unord or []): subterms(x, acc)
    return acc


def term_regs(t, acc):
    for x in subterms(t, []):
        if x[0] == 'E': acc.add(x[1])
    return acc


def event_terms(ev):
    k = ev[0]
    if k in ('ld', 'barrier'): return [ev[2]]
    if k == 'st': return [ev[2], ev[3]]
    if k == 'call':
        (a, o) = ev[3]
        return [ev[2]] + list(a) + [v for _, v in o]
    if k == 'ret': return [v for _, v in ev[3]]
    return []


def term_obligations(tb, tc):
    """branch / switch terminators -> obligation pairs, or None when they differ structurally"""
    if tb[0] != tc[0]: return None
    if tb[0] == 'bc':
        if tb[1] != tc[1]: return None
        if len(tb) == 3: return [(tc[2], tb[2])]
        if tb[2] != tc[2] or len(tb[3]) != len(tc[3]): return None
        return list(zip(tc[3], tb[3]))
    if tb[0] == 'switch': return [(tc[1], tb[1])]
    return []


def term_terms(tm):
    if tm is None: return []
    if tm[0] == 'bc': return [tm[2]] if len(tm) == 3 else list(tm[3])
    if tm[0] == 'switch': return [tm[1]]
    return []


def norm_text(f):
    lab = {}
    for name, i in f.labels.items(): lab.setdefault(i, len(lab))
    out = []
    for i, x in enumerate(f.ins):
        ops = []
        for o in x.ops:
            ops.append(re.sub(r'^L\d+$', lambda m: 'L<%s>' % lab.get(f.labels.get(m.group(0)), '?'), o))
        out.append((x.mn, tuple(ops)))
    return out


def identical(fb, fc): return norm_text(fb) == norm_text(fc)


def positional_hints(eb_blk, ec_blk, fb, fc, Nb, Nc, amb, amc):
    """for a block pair with the same mnemonic sequence: cand slot key -> base slot key from the frame accesses at equal positions"""
    h = {}
    ib = fb.ins[eb_blk.lo:eb_blk.hi]; ic = fc.ins[ec_blk.lo:ec_blk.hi]
    if len(ib) != len(ic) or any(x.mn != y.mn for x, y in zip(ib, ic)): return h
    for x, y in zip(ib, ic):
        mx, my = (MEMOP.match(x.ops[-1]) if x.ops else None), (MEMOP.match(y.ops[-1]) if y.ops else None)
        if mx and my and mx.group(2) == 'r30' and my.group(2) == 'r30':
            try: ob, oc = int(mx.group(1)), int(my.group(1))
            except ValueError: continue
            if ob - Nb < 0 and oc - Nc < 0:
                sz = LOAD1.get(x.mn) or STORE1.get(x.mn)
                if sz: h[('a', oc - Nc, sz)] = ('a', ob - Nb, sz)
    return h


def check_function(fb, fc, verbose=False):
    """escaped-frame region layout: first as offsets relative to the lowest escaped address (survives a new local below the region), then as absolute
    distances from the entry stack pointer (survives a new local below everything); either one proves the layout the pointee can reach is unchanged"""
    try: return check_function1(fb, fc, verbose, False)
    except (Different, Inconclusive) as e1:
        try: return check_function1(fb, fc, verbose, True)
        except (Different, Inconclusive): raise e1


def check_function1(fb, fc, verbose=False, absmode=False):
    if fb.name != fc.name: raise Inconclusive('name mismatch')
    if identical(fb, fc) and not NOSHORT: return 'IDENTICAL'
    Nb, Nc = frame_size(fb), frame_size(fc)
    if Nb is None or Nc is None: raise Inconclusive('no stack frame prologue')
    amb, amc = taken_min(fb, Nb), taken_min(fc, Nc)
    if (amb is None) != (amc is None): raise Inconclusive('address-taken frame slots on one side only')
    Bb, Bc = build_blocks(fb), build_blocks(fc)
    if len(Bb) != len(Bc): raise Different('block count %d vs %d' % (len(Bb), len(Bc)))
    for x, y in zip(Bb, Bc):
        if x.kind != y.kind or x.succ != y.succ: raise Different('block %d shape differs (%s %s vs %s %s)' % (x.k, x.kind, x.succ, y.kind, y.succ))
    EB, EC = [], []
    for x, y in zip(Bb, Bc):
        eb = Eval('b', fb, Nb, x, x.k == 0, amb, absmode); ec = Eval('c', fc, Nc, y, y.k == 0, amc, absmode)
        for i in range(x.lo, x.hi): eb.step(fb.ins[i], False)
        for i in range(y.lo, y.hi): ec.step(fc.ins[i], False)
        EB.append(eb); EC.append(ec)
    n = len(Bb)
    hints = [positional_hints(Bb[k], Bc[k], fb, fc, Nb, Nc, amb, amc) for k in range(n)]
    # per block obligations: (cand term, base term) pairs that must be equal under one slot binding
    base_pairs = [[] for _ in range(n)]
    for k in range(n):
        eb, ec = EB[k], EC[k]
        if len(eb.events) != len(ec.events): raise Different('block %d: %d vs %d observable events' % (k, len(eb.events), len(ec.events)))
        for i, (xb, xc) in enumerate(zip(eb.events, ec.events)):
            ps = event_pairs(xc, xb)
            if ps is None: raise Different('block %d event %d: %s differs in kind/size (base %s | cand %s)' % (k, i, xb[0], brief(xb), brief(xc)))
            base_pairs[k] += ps
        tb, tc = eb.term, ec.term
        if (tb is None) != (tc is None): raise Different('block %d terminator' % k)
        if tb is not None:
            ps = term_obligations(tb, tc)
            if ps is None: raise Different('block %d: terminator differs (%s vs %s)' % (k, tb[:2], tc[:2]))
            base_pairs[k] += ps
    exit_reg = lambda e, r: e.regs.get(r) or T('E', r)
    exit_slot = lambda e, key: e.slots.get(key) or T('S', e.side, key)
    bind = [dict() for _ in range(n)]
    extra = [[] for _ in range(n)]            # edge obligations added so far, per block
    req = [set() for _ in range(n)]
    for k in range(n):
        for (c_, b_) in base_pairs[k]: term_regs(c_, req[k])
    # an entry register used by the base side but not the cand side (or vice versa) would show up as a unification failure of the E symbol / term shape
    for it in range(60):
        changed = False
        for k in range(n):
            HINT.clear(); HINT.update(hints[k])
            SEARCH[0] = 0
            sol = solve(base_pairs[k] + extra[k], {})
            if sol is None:
                # which obligation fails? report the first event pair that cannot be unified on its own
                for (c_, b_) in base_pairs[k]:
                    if solve([(c_, b_)], {}) is None:
                        raise Different('block %d: observable value differs: base %s | cand %s' % (k, brief_t(b_), brief_t(c_)))
                raise Inconclusive('block %d: no consistent slot correspondence for the events%s' % (k, ' and the values its successors need' if extra[k] else ''))
            if sol != bind[k]: bind[k] = sol; changed = True
        for k in range(n):
            ex = []
            for j in Bb[k].succ:
                for r in sorted(req[j]):
                    ex.append((exit_reg(EC[k], r), exit_reg(EB[k], r)))
                for ck, bk in sorted(bind[j].items(), key=repr):
                    ex.append((exit_slot(EC[k], ck), exit_slot(EB[k], bk)))
            if ex != extra[k]: extra[k] = ex; changed = True
            acc = set()
            for (c_, b_) in ex: term_regs(c_, acc)
            if not acc <= req[k]: req[k] |= acc; changed = True
        if not changed: break
    else:
        raise Inconclusive('simulation relation did not converge')
    if bind[0]:
        if verbose: print('  uninit pairs:', sorted(bind[0].items(), key=repr))
        return 'UNINIT'     # a slot is read on some path that never wrote it (in BASE as well): equal only if the stack garbage is equal
    return 'EQUIVALENT'


def brief_t(t, depth=0):
    if depth > 3: return '..'
    if not isinstance(t, tuple): return repr(t)
    return '(' + ' '.join(brief_t(x, depth + 1) for x in t) + ')'


def brief(e):
    return '%s %s' % (e[0], ' '.join(brief_t(x) for x in e[2:]))[:240]


NOSHORT = False


def main():
    global NOSHORT
    NOSHORT = '--no-shortcut' in sys.argv
    a = [x for x in sys.argv[1:] if not x.startswith('-')]; verbose = '-v' in sys.argv
    B = parse_funcs(a[0]); C_ = parse_funcs(a[1]); only = set(a[2:])
    res = {'EQUIVALENT': 0, 'IDENTICAL': 0, 'UNINIT': 0, 'DIFFERENT': 0, 'INCONCLUSIVE': 0}; bad = 0
    for name, fb in B.items():
        if only and name not in only: continue
        if not fb.ins: continue
        fc = C_.get(name)
        if fc is None: print('MISSING', name); res['DIFFERENT'] += 1; continue
        try:
            v = check_function(fb, fc, verbose); res[v] += 1
            if verbose or v == 'UNINIT': print(v, name)
        except Different as e: res['DIFFERENT'] += 1; print('DIFFERENT', name, '-', e)
        except Inconclusive as e: res['INCONCLUSIVE'] += 1; print('INCONCLUSIVE', name, '-', e)
    print('sem_equiv: %d EQUIVALENT, %d IDENTICAL-CODE, %d UNINIT-PAIRED, %d DIFFERENT, %d INCONCLUSIVE' % (res['EQUIVALENT'], res['IDENTICAL'], res['UNINIT'], res['DIFFERENT'], res['INCONCLUSIVE']))
    sys.stdout.flush()
    os._exit(0 if res['DIFFERENT'] == 0 and res['INCONCLUSIVE'] == 0 and res['UNINIT'] == 0 else 1)


if __name__ == '__main__':
    import threading
    sys.setrecursionlimit(200000); threading.stack_size(1 << 29)
    t = threading.Thread(target=main); t.start(); t.join()
