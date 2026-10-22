#!/usr/bin/env python3
"""split_equiv.py BASE.dis CAND.dis BASE.warn CAND.warn - gate for per-use splits (`use` rows), where gcc -O0 gives the new locals other stack slots.

Passes when, function by function:
  1. the instruction streams are identical once frame displacements `N(r30)` / `N(r1)` are masked (same code, only slot numbers moved);
  2. the slot renumbering is a function from candidate slot to base slot (several candidate slots may map to one base slot: that is a split; a candidate
     slot standing for two base slots would be a merge, which is a bug);
  3. the -O1 -Wuninitialized warnings of the candidate are no more numerous per function than the base's (a use left reading the old variable, after the
     value went into the new one, shows up as 'may be used uninitialized').
Exit 0 = pass. Usage inside verify_names.sh; the .dis files are `otool -arch ppc -tV` output, the .warn files are gcc stderr."""
import re, sys
FR = re.compile(r'(-?0x[0-9a-f]+|-?\d+)\((r30|r1)\)|(?<=,r30,)(0x[0-9a-f]+)|(?<=,r1,)(0x[0-9a-f]+)')


def funcs(path):
    out = {}; cur = None
    for l in open(path, errors='replace'):
        l = l.rstrip('\n')
        if re.match(r'^[A-Za-z_$][^\s]*:$', l): cur = l; out[cur] = []
        elif cur and re.match(r'^[0-9a-f]{8}\t', l):
            a, rest = l.split('\t', 1); out[cur].append(rest); ADDR.setdefault(cur, []).append(int(a, 16))
    return out


ADDR = {}          # function label -> instruction addresses (of the file read last)
SLOT = re.compile(r'^(?:lwz|lbz|lhz|lha|lfs|lfd|stw|stb|sth|stfs|stfd)\t\S+,(-?0x[0-9a-f]+|-?\d+)\(r30\)$')
STORE = re.compile(r'^(?:stw|stb|sth|stfs|stfd)\t')
COND = re.compile(r'^(b(?:eq|ne|lt|gt|le|ge|so|ns|dnz|dz|dnzt|dnzf|dzt|dzf|c)[+-]?)\t')


def reaching(ins, addrs):
    """-> {instruction index of a load from a r30 frame slot: frozenset of the store instructions that can reach it}, plus the set of address-taken offsets.
    Slots whose address is taken (addi rX,r30,N) are left out: calls and pointer stores may write them."""
    n = len(ins); at = {a: i for i, a in enumerate(addrs)}
    taken = set()
    for x in ins:
        m = re.match(r'addi\t\S+,r30,(0x[0-9a-f]+)$', x)
        if m: taken.add(int(m.group(1), 16))
    succ = [[] for _ in range(n)]; uncond_after = set(); targets = set(); indirect = []
    for i, x in enumerate(ins):
        mn = x.split('\t')[0]
        tgt = None
        mt = re.search(r'(0x[0-9a-f]+)$', x)
        if mt and int(mt.group(1), 16) in at and (mn == 'b' or COND.match(x)): tgt = at[int(mt.group(1), 16)]
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
    for i in indirect: succ[i] = list(labels)
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


def main():
    bd, cd, bw, cw = sys.argv[1:5]
    B = funcs(bd); ADDRB = dict(ADDR); ADDR.clear(); C = funcs(cd); ADDRC = dict(ADDR); bad = 0
    for name in B:
        if not B[name]: continue
        if name not in C: print('MISSING', name); bad += 1; continue
        b, c = B[name], C[name]
        if len(b) != len(c): print('LENGTH', name); bad += 1; continue
        m = {}; ok = True
        for x, y in zip(b, c):
            if FR.sub('<F>', x) != FR.sub('<F>', y): print('CODE', name, x, '|', y); ok = False; break
            for fx, fy in zip(FR.finditer(x), FR.finditer(y)):
                kx = fx.group(1) or fx.group(3) or fx.group(4); ky = fy.group(1) or fy.group(3) or fy.group(4)
                if m.setdefault(ky, kx) != kx:
                    print('MERGE', name, 'candidate slot', ky, 'stands for', m[ky], 'and', kx); ok = False
        if ok:
            rb, tb = reaching(b, ADDRB[name]); rc, tc = reaching(c, ADDRC[name])
            diffs = [i for i in rb if rb[i] != rc.get(i)]
            if diffs: print('DATAFLOW', name, len(diffs), 'loads reached by different stores; first at', hex(ADDRB[name][diffs[0]]), b[diffs[0]], '|', c[diffs[0]]); ok = False
            # a split slot must not have its address taken
            groups = {}
            for ky, kx in m.items(): groups.setdefault(kx, set()).add(ky)
            for kx, ks in groups.items():
                if len(ks) > 1 and any(int(k, 0) in tc for k in ks if k.startswith('0x')): print('ADDRESS-TAKEN split', name, kx); ok = False
        bad += not ok
    wb_, wc = warns(bw), warns(cw)
    for k, v in wc.items():
        if v > wb_.get(k, 0): print('UNINIT', k, wb_.get(k, 0), '->', v); bad += 1
    print('%d functions compared, %d problems' % (len(B), bad))
    sys.exit(1 if bad else 0)


main()
