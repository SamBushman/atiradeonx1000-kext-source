#!/usr/bin/env python3
"""width_audit.py STOCK_DIS OURS_DIS CORPUS_DIR [--show N] [--only NAME] - issue #235: find rebuilt functions whose memory accesses are NARROWER than the stock's.

Why: a global or field declared with the wrong width in the decompiled source (a word pointer declared `unsigned char *`, a word declared `unsigned char`) recompiles to an
lbz/stb where the stock has an lwz/stw. Callee and constant comparisons do not see it and the code still "looks" right. access_compare.py (issues #68/#70) compares the
SET of (width, displacement) pairs per function but only reports functions where a stock pair is MISSING; a function whose rebuilt code still contains the word pair somewhere
else (as _gldDestroyContext did: lwz 0(r9) once, lbz 0(r2) at the unlink test) reports nothing. This tool compares per-width COUNTS and lists, per function, the byte/half
loads and stores the rebuilt code has MORE of than the stock, together with the matching deficit of word accesses.

Function pairing: every `/* name @ 0xADDR (N bytes) */` header in CORPUS_DIR/part_*.c gives a stock address range; the stock instructions are the lines of STOCK_DIS inside it
(otool -arch ppc -tV), the rebuilt instructions are the lines of OURS_DIS under the label `name` or `_name` (otool -tV of the linked image).
Accesses counted: every load/store (the WIDTH table of access_compare.py) whose base register is not the stack frame; width classes b, h, w, fs, fd.
Report: a function is FLAGGED when  ours_b + ours_h > stock_b + stock_h  AND  ours_w < stock_w  (a narrower access replaced a wider one), which is the signature of a width
error; functions where only one of the two holds are counted in the summary. This is a heuristic (different compilers differ in bit-field and structure-copy code): every flagged
function needs a look at the instructions, nothing here proves a defect."""
import re, sys, collections, glob, os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from access_compare import WIDTH, INSN, LABEL, MEM   # noqa: E402

HDR = re.compile(r'^/\*\s+(\S+)\s+@\s+0x([0-9a-f]+)\s+\((\d+)\s+bytes\)')


def corpus_functions(d):
    out = []
    for f in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        for line in open(f, errors='replace'):
            m = HDR.match(line)
            if m:
                out.append((m.group(1), int(m.group(2), 16), int(m.group(3)), os.path.basename(f)))
    return out


def load_stock(path):
    ins = []
    for line in open(path, errors='replace'):
        m = INSN.match(line.rstrip('\n'))
        if m:
            ins.append((int(m.group(1), 16), m.group(2), m.group(3).split(';')[0].strip()))
    ins.sort()
    return ins


def load_ours(path):
    funcs = collections.OrderedDict(); cur = None
    for line in open(path, errors='replace'):
        line = line.rstrip('\n')
        m = LABEL.match(line)
        if m:
            cur = m.group(1); funcs.setdefault(cur, []); continue
        m = INSN.match(line)
        if m and cur is not None:
            funcs[cur].append((int(m.group(1), 16), m.group(2), m.group(3).split(';')[0].strip()))
    return funcs


def counts(insns):
    """{width class: count} of loads/stores not based on the stack frame."""
    stack = {'r1'}
    for _, mn, ops in insns[:8]:
        if mn == 'or' and ops.replace(' ', '') == 'r30,r1,r1': stack.add('r30')
    c = collections.Counter()
    for _, mn, ops in insns:
        if mn in WIDTH:
            m = MEM.match(ops.replace(' ', ''))
            if m and m.group(4) not in stack:
                c[WIDTH[mn]] += 1
    return c


def pair_counts(insns):
    """{(width class, displacement): count} of loads/stores not based on the stack frame (the same filter as counts())."""
    stack = {'r1'}
    for _, mn, ops in insns[:8]:
        if mn == 'or' and ops.replace(' ', '') == 'r30,r1,r1': stack.add('r30')
    c = collections.Counter()
    for _, mn, ops in insns:
        if mn in WIDTH:
            m = MEM.match(ops.replace(' ', ''))
            if m and m.group(4) not in stack: c[(WIDTH[mn], m.group(2) if m.group(2) is not None else (m.group(3) or ''))] += 1
    return c


def main():
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    only = sys.argv[sys.argv.index('--only') + 1] if '--only' in sys.argv else None
    if only: a.remove(only)
    show = 40
    if '--show' in sys.argv:
        show = int(sys.argv[sys.argv.index('--show') + 1]); a.remove(sys.argv[sys.argv.index('--show') + 1])
    stock = load_stock(a[0]); ours = load_ours(a[1]); fns = corpus_functions(a[2])
    addrs = [x[0] for x in stock]
    import bisect
    flagged = []; wider = []; compared = nomatch = narrower = fewerword = 0
    for name, addr, size, part in fns:
        if only and name != only: continue
        o = ours.get(name) or ours.get('_' + name) or ours.get(name.lstrip('_'))
        if o is None or not o:
            nomatch += 1; continue
        lo = bisect.bisect_left(addrs, addr); hi = bisect.bisect_left(addrs, addr + size)
        s = stock[lo:hi]
        if len(s) < 4: nomatch += 1; continue
        compared += 1
        cs, co = counts(s), counts(o)
        sn = cs['b'] + cs['h']; on = co['b'] + co['h']
        nar = on > sn; few = co['w'] < cs['w']
        narrower += nar; fewerword += few
        if nar and few:
            flagged.append((on - sn, cs['w'] - co['w'], name, part, cs, co))
        if '--wider' in sys.argv and co['w'] > cs['w'] and on < sn:   # the opposite error (a halfword field read as a word: gld_getTextureFormatInfo, #262)
            wider.append((sn - on, co['w'] - cs['w'], name, part, cs, co))
    flagged.sort(key=lambda r: (-r[0], -r[1], r[2]))
    for dn, dw, name, part, cs, co in flagged[:show]:
        print('%-4s +%d byte/half, -%d word   %-40s stock b%d h%d w%d   ours b%d h%d w%d' % (part[5:9], dn, dw, name, cs['b'], cs['h'], cs['w'], co['b'], co['h'], co['w']))
    if '--pairs' in sys.argv:   # per displacement: more byte/half accesses at d than the stock AND fewer word accesses at d (a `lwz 0(r9)` that became `lbz 0(r9)` is invisible to the totals when the function has other word loads)
        n = 0
        for name, addr, size, part in fns:
            if only and name != only: continue
            o = ours.get(name) or ours.get('_' + name) or ours.get(name.lstrip('_'))
            if not o: continue
            lo = bisect.bisect_left(addrs, addr); hi = bisect.bisect_left(addrs, addr + size); s_ = stock[lo:hi]
            if len(s_) < 4: continue
            ps, po = pair_counts(s_), pair_counts(o)
            for d in sorted(set(k[1] for k in list(ps) + list(po))):
                bs = ps[('b', d)] + ps[('h', d)]; bo = po[('b', d)] + po[('h', d)]; ws = ps[('w', d)]; wo = po[('w', d)]
                if '--wider' in sys.argv and bo < bs and wo > ws: print('WIDERPAIR %-4s %-40s disp %-8s stock b/h %d w %d   ours b/h %d w %d' % (part[5:9], name, d, bs, ws, bo, wo))
                if bo > bs and wo < ws: n += 1; print('PAIR %-4s %-40s disp %-8s stock b/h %d w %d   ours b/h %d w %d' % (part[5:9], name, d, bs, ws, bo, wo))
        print('PAIRS: %d (function, displacement) pairs with a byte/half excess and a word deficit' % n)
    for dn, dw, name, part, cs, co in sorted(wider, key=lambda r: (-r[0], -r[1], r[2]))[:show]:
        print('WIDER %-4s -%d byte/half, +%d word   %-40s stock b%d h%d w%d   ours b%d h%d w%d' % (part[5:9], dn, dw, name, cs['b'], cs['h'], cs['w'], co['b'], co['h'], co['w']))
    print('WIDTH-AUDIT: %d functions compared, %d not matched, %d have more byte/half accesses, %d fewer word accesses, %d FLAGGED (both)' % (compared, nomatch, narrower, fewerword, len(flagged)))


if __name__ == '__main__':
    main()
