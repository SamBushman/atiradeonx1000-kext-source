#!/usr/bin/env python3
"""jumptable_audit.py - find functions whose switch tables differ between the stock and the rebuilt image (class #267).

  jumptable_audit.py STOCK_MACHO REBUILT_MACHO LEDGER.tsv NM_REBUILT.txt

Ghidra recovers a jump table's cases from the table itself; when several cases share a target it can fold them into the default.
The rebuilt switch then has fewer cases than the stock. For every function the audit lists the bounds of its indirect `bctr`
dispatches: the immediate of the nearest preceding `cmplwi` (case count - 1) for each `bctr` that is not a call (`bctrl` is a call)
nor a tail call through a loaded pointer (`lwz r12,..; mtctr; bctr` after an epilogue is excluded by requiring a `cmplwi` within
24 instructions). The sorted bounds of the stock and the rebuilt function are compared; a different list (a smaller bound, a lost
dispatch, a dispatch the compiler turned into a compare chain) is printed. Candidates, not proofs: the compiler may legitimately
choose a compare chain for a small switch. The check for a candidate is the stock's table contents (the target words behind the
table address) against the rebuilt case labels, then the fnfuzz row.
"""
import sys, struct
sys.path.insert(0, __file__.rsplit('/', 1)[0])
import capstone
from frame_slot_audit import rows

MD = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
MD.skipdata = True  # a function holds its own jump tables: without this the disassembly stops at the first table
NOWRITE = ('st', 'cmp', 'b', 'mtctr', 'mtlr', 'mtcr', 'sync', 'isync', 'dcb', 'icbi', 'eieio', 'tw', 'nop', 'mtmsr', 'mtspr', 'fcmp')

def sx(v):
    return v - 0x10000 if v & 0x8000 else v

def tables(raw, base, get, detail=None):
    """for every table dispatch (cmplwi N; bgt; ... lwzx; [add]; mtctr; bctr) -> (bound, partition of case indices 0..bound by target);
    detail (a list) receives, per dispatch, (index of the cmplwi, its register, the instruction list) for switch_case_audit.py"""
    ins = list(MD.disasm(raw, base))
    regs, lr, last, out, cmpinfo = {}, None, None, [], None
    for n, i in enumerate(ins):
        m, o = i.mnemonic, [x.strip() for x in i.op_str.split(',')]
        def val(r):
            return regs.get(r)
        if m in ('bl', 'bcl', 'bdnzl') and o[-1] == '0x%x' % (i.address + 4):  # `bcl 20,31,$+4` (capstone prints bdnzl): the PIC base
            lr = i.address + 4
        elif m == 'mflr':
            regs[o[0]] = lr
        elif m == 'lis':
            regs[o[0]] = (int(o[1], 0) << 16) & 0xffffffff
        elif m == 'addis' and val(o[1]) is not None:
            regs[o[0]] = (val(o[1]) + (sx(int(o[2], 0) & 0xffff) << 16)) & 0xffffffff
        elif m == 'addis' and o[1] in ('0',):
            regs[o[0]] = (int(o[2], 0) << 16) & 0xffffffff
        elif m == 'addi' and val(o[1]) is not None:
            regs[o[0]] = (val(o[1]) + sx(int(o[2], 0) & 0xffff)) & 0xffffffff
        elif m == 'ori' and val(o[1]) is not None:
            regs[o[0]] = val(o[1]) | int(o[2], 0)
        elif m in ('mr',) and val(o[1]) is not None:
            regs[o[0]] = val(o[1])
        elif m == 'cmplwi':
            cmpinfo = (n, o[1] if len(o) > 2 else o[0])
            try:
                last = (n, int(o[-1], 0))
            except ValueError:
                pass
            dflt = None
            for nxt in ins[n + 1:n + 8]:  # the bound check's branch (the stock's PIC sequence puts mflr/mtlr in between)
                if nxt.mnemonic in ('bgt', 'bhi', 'bge'):
                    try:
                        dflt = int(nxt.op_str.split(',')[-1], 0)
                    except ValueError:
                        dflt = None
                    break
            if last is not None and last[0] == n:
                last = (n, last[1], dflt)
        elif m == 'bctr':
            nobound = not (last and n - last[0] <= 24)
            if nobound:
                last = (n, None, None)  # bound unknown (checked earlier): the table is as long as its entries are in-function addresses
            w = ins[max(0, n - 6):n]
            lw = [x for x in w if x.mnemonic == 'lwzx']
            if lw:
                rb = [x.strip() for x in lw[-1].op_str.split(',')]
                # the table base is the register of the lwzx that is not the (scaled) index: the one with a known constant
                tb = next((val(r) for r in rb[1:] if val(r) is not None), None)
                relative = any(x.mnemonic == 'add' for x in w)
                if tb is not None:
                    part = {}
                    bound = last[1] if last[1] is not None else 255
                    for k in range(bound + 1):
                        word = get(tb + 4 * k, 4)
                        if len(word) < 4:
                            break
                        e = struct.unpack('>i', word)[0]
                        if last[1] is None and not (relative and e % 4 == 0 and base <= tb + e < base + len(raw)):
                            break
                        part.setdefault((tb + e) & 0xffffffff if relative else e & 0xffffffff, []).append(k)
                    # the group that goes to the default label (the branch after the bound check) is not a case
                    part = {k: v for k, v in part.items() if k != last[2]}
                    out.append((last[1] if last[1] is not None else max(sum(part.values(), []), default=0), tb, tuple(sorted(tuple(v) for v in part.values()))))
                else:
                    out.append((last[1], None, None))
            if detail is not None:
                detail.append((cmpinfo, ins))
            last = None
        elif not m.startswith(NOWRITE) and not m.startswith('.') and o and o[0].startswith('r'):
            regs.pop(o[0], None)
    return out

def main():
    nrows = nflag = 0
    for name, sa, ssz, ra, rsz, sget, rget in rows(*sys.argv[1:5]):
        if sa is None:
            continue
        nrows += 1
        ts, tr = tables(sget(sa, ssz), sa, sget), tables(rget(ra, rsz), ra, rget)
        # every stock dispatch must have an identical rebuilt counterpart (same case-index partition, the default group removed);
        # the order of the dispatches may differ, and the rebuilt window may contain a neighbour's switches (extra rebuilt ones are ignored)
        import collections
        have = collections.Counter(p for b, tb, p in tr if p)
        missing = []
        for b, tb, p in ts:
            if not p:
                continue
            if have[p] > 0:
                have[p] -= 1
            else:
                missing.append((b, p))
        if missing:
            nflag += 1
            print('%-44s stock %x/%d rebuilt %x/%d: %d of %d stock dispatches have no identical rebuilt table' % (name, sa, ssz, ra, rsz, len(missing), len(ts)))
            for b, p in missing:
                print('      stock bound %d, %d cases: %s' % (b, len(p), str(p)[:200]))
            print('      rebuilt tables: %s' % [(b, len(p)) for b, tb, p in tr if p])
    print('# %d functions compared, %d with a stock dispatch lacking an identical rebuilt table' % (nrows, nflag), file=sys.stderr)

if __name__ == '__main__':
    main()
