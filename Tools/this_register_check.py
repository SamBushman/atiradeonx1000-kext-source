#!/usr/bin/env python3
"""this_register_check.py STOCK_DIS OURS_DIS [--allow FILE] [--depth N]  (#86)

Catches the "first real argument dereferenced as `this`" defect class of the mechanical Ghidra port, which size_compare.py,
callee_compare.py, function_coverage.py, the vtable diff and the build all miss (same size, same callees, same symbols).
For every DONE ledger method it finds, in the first 60 instructions of the shipped body and of the rebuilt body, the
*incoming argument registers* (r3..r10, followed through `or rX,rY,rY` copies and `addi rX,rY,imm` offset copies) used as the base of a load/store, in
order of first use, and compares the two sets (the first register of each body must occur in the other body's set; --depth is only
how many registers are printed). A mismatch means the rebuilt body reads through a
different incoming argument than the shipped one (e.g. through `attribute` in r4 instead of `this` in r3).
A call (bl/jbsr/bctrl) drops the tracking of volatile registers but keeps copies held in r13-r31; the scan ends at the first blr/b.

STOCK_DIS/OURS_DIS: `otool -arch ppc -tV` output (stock has no labels, ours does). Run from the repo root (reads
Ledger/kext_ppc_ledger.tsv). A second pass compares the whole bodies' register SETS (so a body whose first access happens to be `this` in both, but whose later
accesses go through a shifted argument, is caught too). Allow-list lines: `<symbol> <reason>`; allow-listed methods are reported as ALLOWED, not failures.
Exit status 1 if any non-allowed mismatch remains."""
import sys, re, bisect

args = [a for a in sys.argv[1:]]
allow_file = None; depth = 2
if '--allow' in args:
    i = args.index('--allow'); allow_file = args[i + 1]; del args[i:i + 2]
if '--depth' in args:
    i = args.index('--depth'); depth = int(args[i + 1]); del args[i:i + 2]
sdis, odis = args[0], args[1]
allow = {}
if allow_file:
    for l in open(allow_file):
        l = l.strip()
        if l and not l.startswith('#'):
            p = l.split(None, 1); allow[p[0]] = p[1] if len(p) > 1 else ''

INS = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
LOADSTORE = re.compile(r'^(l|st)(b|h|ha|w|wz|bz|hz|d|fs|fd|mw|swbrx|wbrx)(u?)(x?)$')
CALLS = ('bl', 'bla', 'jbsr', 'bctrl', 'blr', 'bctr', 'b')
NODEST = ('cmp', 'cmpw', 'cmpwi', 'cmpl', 'cmplw', 'cmplwi', 'cmpi', 'cmpli', 'mtlr', 'mtctr', 'mtcrf', 'mtspr', 'nop', 'sync', 'isync')

def bases(rows, limit=60):
    """ordered list of incoming-arg registers (3..10) used as load/store base within the first `limit` instructions"""
    alias = {r: r for r in range(3, 11)}
    seen = []
    for k, (a, op, rest) in enumerate(rows[:limit]):
        if op in CALLS:
            if op in ('blr', 'b') and limit < 1000: break      # return / tail jump: end of the straight-line prologue (whole-function mode scans on)
            alias = {k: v for k, v in alias.items() if k >= 13}      # a call clobbers the volatile registers, keeps r13-r31 copies
            continue
        ops = [x.strip() for x in rest.split(',')] if rest else []
        # otool prints small displacements as symbols (`lwz r2,__ZN...(r3)`), so accept any displacement text
        m = re.match(r'^[^(]*\((r\d+)\)$', ops[-1]) if ops else None
        if (op.startswith('l') or op.startswith('st')) and m and not op.startswith('lis') and not op.startswith('li'):
            b = int(m.group(1)[1:])
            o = alias.get(b)
            if o is not None and o not in seen:
                seen.append(o)
        # register copies / clobbers
        if op in ('or', 'mr') and len(ops) >= 2:
            d = int(ops[0][1:]) if ops[0].startswith('r') else None
            s = int(ops[1][1:]) if ops[1].startswith('r') else None
            if d is not None and s is not None and (op == 'mr' or ops[1] == ops[2]):
                if s in alias: alias[d] = alias[s]
                else: alias.pop(d, None)
                continue
        if op == 'addi' and len(ops) == 3 and ops[1] in ('r%d' % k for k in range(3, 32)):
            # `addi rD,rS,imm`: rD is an offset copy of rS (the compiler folds `this+0xc8` into the register)
            d = int(ops[0][1:]); sr = int(ops[1][1:])
            if sr in alias: alias[d] = alias[sr]
            else: alias.pop(d, None)
            continue
        if ops and ops[0].startswith('r') and not op.startswith('st') and op not in NODEST and not op.startswith('b'):
            alias.pop(int(ops[0][1:]), None)
        if op.startswith('lwzu') or op.startswith('stwu'):
            pass
    return seen

led = []
for l in open('Ledger/kext_ppc_ledger.tsv'):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE':
        led.append((int(f[0], 16), int(f[1]), f[4], f[5]))

srows = [(int(m.group(1), 16), m.group(2), m.group(3)) for m in map(INS.match, open(sdis)) if m]
saddr = [r[0] for r in srows]
ofun = {}; cur = None
for l in open(odis):
    s = l.strip()
    if s.endswith(':') and not l.startswith('\t') and not re.match(r'^[0-9a-f]{8}\t', l):
        cur = s[:-1]; ofun[cur] = []; continue
    m = INS.match(l)
    if m and cur is not None: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))

bad = []; allowed = []; n = 0; skipped = 0; inconclusive = 0
for addr, size, name, sym in led:
    o = ofun.get(sym)
    if o is None:
        skipped += 1; continue
    i = bisect.bisect_left(saddr, addr)
    j = bisect.bisect_left(saddr, addr + max(size, 4))
    sb = bases(srows[i:j]); ob = bases(o)
    sfull = bases(srows[i:j], 10**6); ofull = bases(o, 10**6)
    n += 1
    # pass 2 (whole function): the SET of incoming-argument registers used as load/store bases must be the same. Noisier than
    # pass 1 (spills to the stack, ledger-size cut-offs of the shipped body, path-insensitive tracking), so every hit is read by
    # hand and recorded in the allow-list with the reason.
    if sfull and ofull and set(sfull) != set(ofull):
        (allowed if sym in allow else bad).append((sym, name + ' [pass 2, whole function]', sfull, ofull))
    if not sb or not ob:
        inconclusive += 1; continue
    # defect = the rebuilt body's first base register is not among the shipped body's (or vice versa): compiler scheduling may
    # reorder or add accesses, but it cannot make the body read through a different incoming argument.
    if ob[0] not in sb or sb[0] not in ob:
        row = (sym, name, sb[:depth], ob[:depth])
        (allowed if sym in allow else bad).append(row)

def r(x): return ','.join('r%d' % v for v in x) or '-'
for sym, name, sb, ob in allowed:
    print('ALLOWED  %-60s stock[%s] rebuilt[%s]  %s' % (name, r(sb), r(ob), allow[sym]))
for sym, name, sb, ob in bad:
    print('MISMATCH %-60s stock[%s] rebuilt[%s]' % (name, r(sb), r(ob)))
print('this_register_check: %d methods compared (%d without a rebuilt body, %d inconclusive: no base register seen in the prologue in one of the two bodies), %d mismatches, %d allow-listed' % (n, skipped, inconclusive, len(bad), len(allowed)))
sys.exit(1 if bad else 0)
