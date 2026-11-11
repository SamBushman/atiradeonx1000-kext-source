#!/usr/bin/env python3
"""indirect_setup_compare.py STOCK_DIS REBUILT_DIS [--all] - candidate finder for indirect calls / indirect tail calls whose argument registers differ between the stock
and the rebuilt function (`otool -tV` dumps of both images, GLEngine; the pipeline's indirect_args.py only knows `bctrl`, an indirect TAIL call (`mtctr; bctr`) was never checked).

For every function name present in both dumps and every indirect transfer (`bctrl`; `bctr` whose target register was loaded with `lwz rN,off(rM)`, i.e. a slot read, not a switch table)
the argument registers written in the basic block that ends at the transfer are collected: r4..r10 and f1..f13, in order of the sites. The k-th site of the stock is compared with the k-th of the
rebuilt; a register written in one and not in the other is printed. This is a CANDIDATE FILTER: the rebuilt compiler may place the same write in a different block (a join), so every row is
checked by hand / by the recording-callback fuzz (fnfuzz `fnrecv` slots) before anything is changed. A site count that differs between the two is printed as COUNT.
Rows: function, site-index, kind(bctrl|bctr), stock-regs, rebuilt-regs, only-stock, only-rebuilt."""
import re, sys

def parse(path):
    funcs = {}; cur = None; pend = None; order = []
    for l in open(path, errors='replace'):
        l = l.rstrip('\n')
        m = re.match(r'^([A-Za-z_$.][^\s:]*):\s*$', l)
        if m:
            cur = m.group(1); funcs.setdefault(cur, []); order.append(cur); continue
        t = l.split('\t')
        if cur is not None and len(t) >= 2 and re.fullmatch(r'[0-9a-f]{8}', t[0]):
            funcs[cur].append((int(t[0], 16), t[1].strip(), t[2].strip() if len(t) > 2 else ''))
    return funcs

def dest(op, arg):
    p = [x.strip() for x in arg.split(';')[0].split(',')]
    if not p: return None
    if op.startswith(('st', 'cmp', 'fcmp', 'b', 'tw', 'mt', 'dcb', 'icb', 'sync', 'isync', 'eieio', 'cr', 'nop', 'dst')): return None
    if op.startswith('lmw'): return None
    m = re.fullmatch(r'([rf])(\d+)', p[0])
    return (m.group(1), int(m.group(2))) if m else None

def sites(ins):
    targets = set()
    for a, op, arg in ins:
        if op.startswith('b') and op not in ('bctr', 'bctrl', 'blr', 'blrl', 'bclr', 'bclrl', 'bcl'):
            m = re.search(r'0x([0-9a-f]+)', arg)
            if m: targets.add(int(m.group(1), 16))
    out = []
    for i, (a, op, arg) in enumerate(ins):
        if op not in ('bctr', 'bctrl'): continue
        # the register moved into ctr and how it was loaded
        tgt = None; kind_ok = op == 'bctrl'
        j = i - 1
        while j >= 0 and j > i - 60:
            o2, a2 = ins[j][1], ins[j][2]
            if o2 == 'mtspr' and a2.startswith('ctr,'): tgt = a2.split(',')[1].strip(); break
            j -= 1
        if tgt is None: continue
        if op == 'bctr':
            # a slot read: lwz tgt,off(rM) (not lwzx / add: a switch table)
            ok = False
            for k in range(j - 1, max(-1, j - 60), -1):
                o3, a3 = ins[k][1], ins[k][2]
                d = dest(o3, a3)
                if d and d == ('r', int(tgt[1:])):
                    ok = o3 == 'lwz' or (o3 in ('or', 'mr') and True)
                    break
            if not ok: continue
        wr = set()
        k = i - 1
        while k >= 0:
            ak, ok_, argk = ins[k]
            if ok_.startswith('b') and ok_ not in ('bctr', 'bctrl'): break
            d = dest(ok_, argk)
            if d and ((d[0] == 'r' and 4 <= d[1] <= 10) or (d[0] == 'f' and 1 <= d[1] <= 13)) and not (d == ('r', int(tgt[1:]))):
                wr.add('%s%d' % d)
            if ak in targets and k != i - 1: break
            k -= 1
        out.append((a, op, wr))
    return out

def main():
    s = parse(sys.argv[1]); r = parse(sys.argv[2])
    nrows = 0; ncount = 0; nsites = 0
    for name in s:
        if name not in r: continue
        a = sites(s[name]); b = sites(r[name])
        nsites += len(a)
        if len(a) != len(b):
            print('COUNT\t%s\tstock %d\trebuilt %d' % (name, len(a), len(b))); ncount += 1; continue
        for k, ((sa, so, sw), (ra, ro, rw)) in enumerate(zip(a, b)):
            if sw != rw:
                key = lambda x: (x[0], int(x[1:]))
                print('DIFF\t%s\t#%d\t%s/%s\t%s\t%s\tonly-stock %s\tonly-rebuilt %s' % (name, k, so, ro, ' '.join(sorted(sw, key=key)), ' '.join(sorted(rw, key=key)),
                      ' '.join(sorted(sw - rw, key=key)) or '-', ' '.join(sorted(rw - sw, key=key)) or '-'))
                nrows += 1
    print('# %d indirect sites in stock functions present in both images, %d differing, %d functions with a different site count' % (nsites, nrows, ncount), file=sys.stderr)

main()
