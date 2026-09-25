#!/usr/bin/env python3
"""access_compare.py STOCK_DIS OURS_DIS [--min N] [--names FILE] - compare, per function, the memory accesses the stock machine code makes
with the accesses the recompiled function makes (issues #68, #70).

The callee comparison cannot see a Ghidra typing error that leaves the call graph alone: a word pointer declared as a byte pointer reads
`lbz 4(r11)` where the stock reads `lwz 0x10(r11)`. Both disassemblies (`otool -tV`) are reduced, function by function, to the set of
(access width class, displacement) pairs of every load/store whose displacement is a plain constant and whose base is not the stack frame
(r1, and r30 when the prologue copies r1 into it - the -O0 frame pointer) or a PIC/`addis` anchor. A pair the stock makes and the recompile
never makes is a candidate defect: a wrong access width or offset (the -O2 stock folds field offsets into displacements exactly as the -O0
recompile does, so genuine differences are rare; array-indexing accesses have displacement 0 and are not compared).

  MISSING  (width,disp) in the stock function, absent from the recompile      <- the interesting side
  EXTRA    (width,disp) in the recompile, absent from the stock                <- usually the wrong-width partner of a MISSING entry

Output: one line per function with at least --min missing pairs, most missing first, then a summary. Functions are matched by symbol name."""
import re, sys, collections

WIDTH = {'lbz': 'b', 'lbzu': 'b', 'stb': 'b', 'stbu': 'b', 'lhz': 'h', 'lhzu': 'h', 'lha': 'h', 'lhau': 'h', 'sth': 'h', 'sthu': 'h',
         'lwz': 'w', 'lwzu': 'w', 'stw': 'w', 'stwu': 'w', 'lfs': 'fs', 'lfsu': 'fs', 'stfs': 'fs', 'stfsu': 'fs', 'lfd': 'fd', 'lfdu': 'fd', 'stfd': 'fd', 'stfdu': 'fd'}
INSN = re.compile(r'^([0-9a-f]{8})\t(\S+)\t?(.*)$')
LABEL = re.compile(r'^([A-Za-z_$][^\s:]*):\s*$')
MEM = re.compile(r'^(r\d+),(?:(0x[0-9a-f]+|-?\d+)|([^(,]*))\((r\d+)\)')


def parse(path):
    """-> {function name: [(mnemonic, operands, address)]}"""
    funcs = collections.OrderedDict(); cur = None
    for line in open(path, errors='replace'):
        line = line.rstrip('\n')
        m = LABEL.match(line)
        if m:
            cur = m.group(1); funcs.setdefault(cur, []); continue
        m = INSN.match(line)
        if m and cur is not None:
            funcs[cur].append((m.group(2), m.group(3).split(';')[0].strip(), int(m.group(1), 16)))
    return funcs


STORES = {'stb', 'stbu', 'sth', 'sthu', 'stw', 'stwu', 'stfs', 'stfsu', 'stfd', 'stfdu', 'stmw', 'stbx', 'sthx', 'stwx', 'stfsx', 'stfdx', 'stwcx.', 'stwbrx', 'sthbrx', 'stvx', 'stswi', 'dcbz', 'dcbf', 'dcbst', 'dcbt', 'dcbtst', 'icbi'}
NODEST = {'cmpw', 'cmplw', 'cmpwi', 'cmplwi', 'cmpd', 'cmpld', 'cmpdi', 'cmpldi', 'mtspr', 'mtcrf', 'mtfsf', 'mtfsb0', 'mtfsb1', 'crxor', 'cror', 'crand', 'crnor', 'creqv', 'isync', 'sync', 'eieio', 'nop', 'trap', 'tw', 'twi', 'fcmpu', 'fcmpo'}
BRANCH = re.compile(r'^(b|bl|bc|bctr|bctrl|blr|blrl|b[a-z]{1,3}[+-]?|bdnz|bdz|bl[a-z]?)$')


def accesses(insns, addrs):
    """set of (width, effective displacement): the displacement of a load/store plus the constant the base register was advanced by (`addi`,
    register copies, tracked within a basic block), so an -O0 `addi r2,r2,16; lwz r0,0(r2)` and an -O2 `lwz r0,16(r2)` both give (w, 16).
    Accesses off the stack frame (r1, r30 as -O0 frame pointer) or a PIC anchor (`addis`) are skipped."""
    frame = 'r1', 'r30'
    stackreg = {'r1'}
    for mn, ops in insns[:8]:
        if mn == 'or' and ops.replace(' ', '') == 'r30,r1,r1': stackreg.add('r30')
    targets = set()
    for (mn, ops), ad in zip(insns, addrs):
        if mn.startswith('b') and mn not in ('blr', 'blrl', 'bctr', 'bctrl'):
            m = re.search(r'0x([0-9a-f]+)\s*$', ops)
            if m: targets.add(int(m.group(1), 16))
    pic = set()     # registers holding the PIC base (`mfspr rX,lr` after `bcl 20,31`) or a copy of it
    off = {}        # register -> constant offset from an unknown base value
    kind = {}       # register -> 'stack' | 'anchor'
    out = set()
    for (mn, ops), ad in zip(insns, addrs):
        if ad in targets: off.clear(); kind.clear()
        parts = [x.strip() for x in ops.split(',')] if ops else []
        if mn in WIDTH:
            m = MEM.match(ops.replace(' ', ''))
            if m:
                base = m.group(4)
                if m.group(2) is not None:
                    d = int(m.group(2), 0)
                    if d >= 0x8000: d -= 0x10000
                    sym = False
                else:
                    d = 0; sym = m.group(3).startswith(('lo16', 'ha16'))
                k = 'stack' if base in stackreg and base not in kind else kind.get(base)
                if base in stackreg: k = 'stack'
                if not sym and k is None and abs(d + off.get(base, 0)) < 0x4000 and base not in pic:
                    out.add((WIDTH[mn], d + off.get(base, 0)))
            if mn not in STORES and parts:
                dst = parts[0]; off.pop(dst, None); kind.pop(dst, None)
                if mn.endswith('u') and m: pass
            continue
        if mn in STORES or mn in NODEST: continue
        if mn.startswith('b') and BRANCH.match(mn):
            if mn in ('bl', 'bctrl', 'blrl') or mn.startswith('bl') and mn != 'ble' and mn != 'blt' and mn != 'blr':
                for r in ('r0', 'r2', 'r3', 'r4', 'r5', 'r6', 'r7', 'r8', 'r9', 'r10', 'r11', 'r12'): off.pop(r, None); kind.pop(r, None)
            continue
        if not parts: continue
        dst = parts[0]
        if mn == 'mfspr' and len(parts) == 2 and parts[1] == 'lr':
            pic.add(dst); off.pop(dst, None); kind.pop(dst, None); continue
        if mn == 'or' and len(parts) == 3 and parts[1] == parts[2] and parts[1] in pic:
            pic.add(dst); continue
        if dst in pic and mn not in STORES: pic.discard(dst)
        if mn == 'addis':
            off.pop(dst, None); kind[dst] = 'anchor'
        elif mn == 'addi' and len(parts) == 3:
            src = parts[1]
            try: imm = int(parts[2], 0)
            except ValueError: imm = 0
            if imm >= 0x8000: imm -= 0x10000
            k = 'stack' if src in stackreg and src not in kind else kind.get(src)
            if src in stackreg: k = 'stack'
            if k: kind[dst] = k; off.pop(dst, None)
            else: off[dst] = off.get(src, 0) + imm; kind.pop(dst, None)
        elif mn == 'or' and len(parts) == 3 and parts[1] == parts[2]:
            src = parts[1]
            k = 'stack' if src in stackreg else kind.get(src)
            if k: kind[dst] = k; off.pop(dst, None)
            else: off[dst] = off.get(src, 0); kind.pop(dst, None)
        else:
            off.pop(dst, None); kind.pop(dst, None)
    return out


def main():
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    mn = int(sys.argv[sys.argv.index('--min') + 1]) if '--min' in sys.argv else 1
    if '--min' in sys.argv: a.remove(sys.argv[sys.argv.index('--min') + 1])
    stock = parse(a[0]); ours = parse(a[1])
    only = None
    if '--names' in sys.argv:
        only = set(l.split('\t')[2] if '\t' in l else l.strip() for l in open(sys.argv[sys.argv.index('--names') + 1]))
    rows = []; compared = 0
    for name, ins in stock.items():
        if only is not None and name not in only: continue
        o = ours.get(name) or ours.get('_' + name) or ours.get(name.lstrip('_'))
        if o is None or len(ins) < 4: continue
        compared += 1
        sa = accesses([(x[0], x[1]) for x in ins], [x[2] for x in ins]); oa = accesses([(x[0], x[1]) for x in o], [x[2] for x in o])
        miss = sorted(sa - oa); extra = sorted(oa - sa)
        if len(miss) >= mn: rows.append((len(miss), name, miss, extra))
    rows.sort(key=lambda r: (-r[0], r[1]))
    for n, name, miss, extra in rows:
        f = lambda s: ' '.join('%s%+#x' % (w, d) for w, d in s[:12]) + (' ...' if len(s) > 12 else '')
        print('%3d %s\n      MISSING %s\n      EXTRA   %s' % (n, name, f(miss), f(extra)))
    print('ACCESS-COMPARE: %d functions compared, %d with >= %d missing (width,disp) pairs' % (compared, len(rows), mn))


if __name__ == '__main__':
    main()
