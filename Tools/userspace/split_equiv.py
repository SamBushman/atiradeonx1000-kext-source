#!/usr/bin/env python3
"""split_equiv.py BASE.dis CAND.dis BASE.warn CAND.warn - gate for per-use splits (`use` rows), where gcc -O0 gives the new locals other stack slots.

Passes when, function by function:
  1. the instruction streams are identical once frame displacements `N(r30)` / `N(r1)` are masked (same code, only slot numbers moved);
  2. the slot renumbering is a function from candidate slot to base slot (several candidate slots may map to one base slot: that is a split; a candidate
     slot standing for two base slots would be a merge, which is a bug);
  3. the -O1 -Wuninitialized warnings of the candidate are no more numerous per function than the base's (a use left reading the old variable, after the
     value went into the new one, shows up as 'may be used uninitialized').
Exit 0 = pass. Usage inside verify_names.sh; the .dis files are `gcc -arch ppc -S` output, the .warn files are gcc stderr."""
import re, sys
FR = re.compile(r'(-?0x[0-9a-f]+|-?\d+)\((r30|r1)\)|(?<=,r30,)(-?0x[0-9a-f]+|-?\d+)|(?<=,r1,)(-?0x[0-9a-f]+|-?\d+)')


COMM = re.compile(r'^(add|and|or|xor|nand|nor|eqv|mullw|mulhw|mulhwu|fadd|fadds|fmul|fmuls)(\.?)\t(r\d+|f\d+),(r\d+|f\d+),(r\d+|f\d+)$')


def canon(x):
    """commutative register ops: gcc orders the two source operands by declaration order, which a split changes - sort them"""
    m = COMM.match(x)
    if not m: return x
    a, b = sorted((m.group(4), m.group(5)))
    return '%s%s\t%s,%s,%s' % (m.group(1), m.group(2), m.group(3), a, b)


LOADS = re.compile(r'^(lwz|lbz|lhz|lha|lfs|lfd)\t(\S+),(-?0x[0-9a-f]+|-?\d+)\(r30\)$')


def windowat(ins, i):
    a, b_ = LOADS.match(ins[i]), LOADS.match(ins[i + 1])
    if not (a and b_) or a.group(2) == b_.group(2): return False
    m = COMM.match(ins[i + 2])
    return bool(m) and {m.group(4), m.group(5)} == {a.group(2), b_.group(2)}


def funcs(path):
    """gcc -S text -> {function label: [instructions as 'mnemonic<TAB>operands']}; META[label] = (label -> instruction index, {bctr index: [target labels]})"""
    out = {}; cur = None; META.clear(); pend = []; lastb = None
    for l in open(path, errors='replace'):
        l = l.rstrip('\n')
        m = re.match(r'^(_[A-Za-z0-9_$.]*):$', l)
        if m: cur = m.group(1); out[cur] = []; META[cur] = ({}, {}); pend = []; lastb = None; continue
        if cur is None: continue
        m = re.match(r'^("?[A-Za-z_$.][^\s"]*"?):$', l)
        if m: pend.append(m.group(1).strip('"')); continue
        m = re.match(r'^\t\.long\s+(\S+)-(\S+)$', l)
        if m and lastb is not None: META[cur][1].setdefault(lastb, []).append(m.group(1)); continue
        m = re.match(r'^\t([a-z][a-z0-9.+-]*)(?:\s+(.*))?$', l)
        if m:
            for lab in pend: META[cur][0][lab] = len(out[cur])
            pend = []
            ins = m.group(1) + ('\t' + m.group(2).replace(' ', '') if m.group(2) else '')
            out[cur].append(ins)
            lastb = len(out[cur]) - 1 if m.group(1) == 'bctr' else None
        elif l.startswith('\t.') and not l.startswith('\t.long'): pass
    return out


META = {}
SLOT = re.compile(r'^(?:lwz|lbz|lhz|lha|lfs|lfd|stw|stb|sth|stfs|stfd)\t\S+,(-?0x[0-9a-f]+|-?\d+)\(r30\)$')
STORE = re.compile(r'^(?:stw|stb|sth|stfs|stfd)\t')
COND = re.compile(r'^(b(?:eq|ne|lt|gt|le|ge|so|ns|dnz|dz|dnzt|dnzf|dzt|dzf|c)[+-]?)\t')


def reaching(ins, meta):
    """-> {instruction index of a load from a r30 frame slot: frozenset of the store instructions that can reach it}, plus the set of address-taken offsets.
    Slots whose address is taken (addi rX,r30,N) are left out: calls and pointer stores may write them."""
    n = len(ins); at = meta[0]; tables = meta[1]
    taken = set()
    for x in ins:
        m = re.match(r'addi\t\S+,r30,(-?0x[0-9a-f]+|-?\d+)$', x) or re.match(r'la\t\S+,(-?0x[0-9a-f]+|-?\d+)\(r30\)$', x)
        if m: taken.add(int(m.group(1), 0))
    succ = [[] for _ in range(n)]; uncond_after = set(); targets = set(); indirect = []
    for i, x in enumerate(ins):
        mn = x.split('\t')[0]
        tgt = None
        mt = re.search(r'([A-Za-z_$.][^,\s]*)$', x.split('\t', 1)[1]) if '\t' in x else None
        if mt and mt.group(1).strip('"') in at and (mn == 'b' or COND.match(x)): tgt = at[mt.group(1).strip('"')]
        if mn == 'b':
            if tgt is not None: succ[i].append(tgt); targets.add(tgt)
            uncond_after.add(i + 1)
        elif mn in ('blr', 'bctr'):
            uncond_after.add(i + 1)
            if mn == 'bctr': indirect.append(i)
        elif COND.match(x):
            if tgt is not None: succ[i].append(tgt); targets.add(tgt)
            if i + 1 < n: succ[i].append(i + 1)
        elif i + 1 < n: succ[i].append(i + 1)
    labels = sorted((targets | uncond_after) & set(range(n)))
    for i in indirect:
        tl = tables.get(i)
        succ[i] = sorted({at[t] for t in tl if t in at}) if tl else list(labels)
        targets.update(succ[i])
    off = lambda x: int(SLOT.match(x).group(1), 0)
    leaders = sorted({0} | set(labels) | {j for i in range(n) for j in succ[i] if j != i + 1} | {i + 1 for i in range(n) if len(succ[i]) != 1 or succ[i][0] != i + 1})
    leaders = [l for l in leaders if l < n]; bi = {l: k for k, l in enumerate(leaders)}
    ends = leaders[1:] + [n]
    gen = []
    for k, l in enumerate(leaders):
        g = {}
        for i in range(l, ends[k]):
            if STORE.match(ins[i]) and SLOT.match(ins[i]) and off(ins[i]) not in taken: g[off(ins[i])] = i
        gen.append(g)
    bsucc = []
    for k, l in enumerate(leaders):
        last = ends[k] - 1; bsucc.append(sorted({bi[j] for j in succ[last] if j in bi}))
    IN = [dict() for _ in leaders]; work = list(range(len(leaders))); inq = set(work)
    while work:
        k = work.pop(); inq.discard(k)
        out = dict(IN[k])
        for o, i in gen[k].items(): out[o] = frozenset([i])
        for t in bsucc[k]:
            ch = False
            for o, v in out.items():
                cur = IN[t].get(o, frozenset())
                if not v <= cur: IN[t][o] = cur | v; ch = True
            if ch and t not in inq: work.append(t); inq.add(t)
    res = {}
    for k, l in enumerate(leaders):
        st = dict(IN[k])
        for i in range(l, ends[k]):
            x = ins[i]
            if SLOT.match(x) and off(x) not in taken:
                if STORE.match(x): st[off(x)] = frozenset([i])
                else: res[i] = st.get(off(x), frozenset())
    return res, taken


def warns(path):
    d = {}
    fn = None
    for l in open(path, errors='replace'):
        m = re.search(r"In function '([^']+)'", l)
        if m: fn = m.group(1)
        if 'uninitialized' in l and 'warning' in l: d[fn] = d.get(fn, 0) + 1
    return d


IDXREF = re.compile(r'^(lbz|lwz|lhz|lha|stb|sth|stw|lfs|lfd|stfs|stfd)\t(\S+),(-?\d+)\((r\d+)\)$')


def prep(ins):
    """-> (masked text, frame keys) per instruction. Frame displacements are masked; an element of a local array addressed as
    `addi rA,r30,K / add rX,rA,rB / lbz rD,N(rX)` is the frame offset K+N (key 'A<K+N>')."""
    masked, keys = [], []
    for i, x in enumerate(ins):
        mx = IDXREF.match(x)
        if mx and i >= 2 and re.match(r'add\t%s,' % mx.group(4), ins[i - 1]) and re.match(r'addi\t\S+,r30,(\d+)$', ins[i - 2]):
            K = int(re.match(r'addi\t\S+,r30,(\d+)$', ins[i - 2]).group(1))
            masked.append(canon('%s\t%s,<F>(%s)' % (mx.group(1), mx.group(2), mx.group(4)))); keys.append(['A%d' % (K + int(mx.group(3)))])
        else:
            masked.append(canon(FR.sub('<F>', x))); keys.append([fx.group(1) or fx.group(3) or fx.group(4) for fx in FR.finditer(x)])
    return masked, keys


def main():
    bd, cd, bw, cw = sys.argv[1:5]
    B = funcs(bd); METAB = dict(META); C = funcs(cd); METAC = dict(META); bad = 0
    for name in B:
        if not B[name]: continue
        if name not in C: print('MISSING', name); bad += 1; continue
        b, c = B[name], C[name]
        if len(b) != len(c): print('LENGTH', name); bad += 1; continue
        ok = True
        mb, kb = prep(b); mc, kc = prep(c)
        for x, y, x0, y0 in zip(mb, mc, b, c):
            if x != y: print('CODE', name, x0, '|', y0); ok = False; break
        m = {}
        if ok:
            # `x = y + x` becomes `x' = y + x''` when x is split, and gcc loads the operands of a commutative op in another order then: such a
            # window (two frame loads feeding one commutative op) is paired after everything else, by consistency with the slot map
            win = lambda ins: {i for i in range(len(ins) - 2) if windowat(ins, i)}
            wb_set = win(b); wc_set = win(c)
            if wb_set != wc_set: print('WINDOWS differ', name); ok = False
            amb = set()
            for i in wb_set: amb.update((i, i + 1))
            for k in range(len(b)):
                if k in amb: continue
                for kx, ky in zip(kb[k], kc[k]):
                    if m.setdefault(ky, kx) != kx:
                        print('MERGE', name, 'candidate slot', ky, 'stands for', m[ky], 'and', kx); ok = False
            for i in sorted(wb_set):
                (x1, x2), (y1, y2) = (kb[i][0], kb[i + 1][0]), (kc[i][0], kc[i + 1][0])
                for (p1, p2) in (((x1, y1), (x2, y2)), ((x1, y2), (x2, y1))):
                    if all(m.get(ky, kx) == kx for kx, ky in (p1, p2)):
                        for kx, ky in (p1, p2): m[ky] = kx
                        break
                else:
                    print('MERGE', name, 'window at', i, 'fits no pairing'); ok = False
        if ok:
            rb, tb = reaching(b, METAB[name]); rc, tc = reaching(c, METAC[name])
            diffs = [k for k in rb if k not in amb and rb[k] != rc.get(k)]
            diffs += [i for i in wb_set if sorted(map(sorted, [rb.get(i, frozenset()), rb.get(i + 1, frozenset())])) != sorted(map(sorted, [rc.get(i, frozenset()), rc.get(i + 1, frozenset())]))]
            if diffs: print('DATAFLOW', name, len(diffs), 'loads reached by different stores; first at', diffs[0], b[diffs[0]], '|', c[diffs[0]]); ok = False
            # a split slot must not have its address taken
            groups = {}
            for ky, kx in m.items(): groups.setdefault(kx, set()).add(ky)
            for kx, ks in groups.items():
                if len(ks) > 1 and any((not k.startswith('A')) and int(k, 0) in tc for k in ks): print('ADDRESS-TAKEN split', name, kx); ok = False
        bad += not ok
    wb_, wc = warns(bw), warns(cw)
    for k, v in wc.items():
        if v > wb_.get(k, 0): print('UNINIT', k, wb_.get(k, 0), '->', v); bad += 1
    print('%d functions compared, %d problems' % (len(B), bad))
    sys.exit(1 if bad else 0)


main()
