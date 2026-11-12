#!/usr/bin/env python3
"""frame_slot_audit.py - find functions whose address-taken stack slots are laid out differently from the stock (class #269).

  frame_slot_audit.py STOCK_MACHO REBUILT_MACHO LEDGER.tsv NM_REBUILT.txt [--gap N] [--all]

A callee that is given the address of a local often reads the NEIGHBOURING words (a struct passed as &first_member). The stock
keeps such blocks contiguous; the corpus declares separate locals and gcc places them in another order. Every `addi rD,r1,K`
(the address of frame slot K, 8 <= K < 0x1000) names a slot whose address is passed on or stored. For each function the audit takes
the sorted distinct K of the stock and of the rebuilt image (the rebuilt window is capped at 1.5x the stock size + 64 bytes) and compares the 'adjacency signature': the list of gaps between
consecutive K that are <= --gap bytes (default 16: blocks of up to four words), sorted. Equal signatures = same block structure
(the absolute frame offsets may differ); different signatures = a block the stock has contiguous is split or reordered in the
rebuilt image (or a block was created): the function is listed for a manual look (which callee reads past the address?).

LEDGER.tsv: fnfuzz ledger (`id name stockaddr rebaddr size ...`, hex addresses); the stock address and size come from it,
the rebuilt address from NM_REBUILT (`nm` of the rebuilt image, `addr type name`) and the rebuilt size from the next text symbol.
Findings are candidates, not proofs: the proof is that the function's fuzz row passes (or that the callee reads only its own word).
"""
import struct, sys, re, collections
import capstone
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from fn_norm_diff import thin, segments  # noqa

def loader(path):
    d = thin(path)
    segs = [s for s in segments(d) if s[0] != '__PAGEZERO']
    def get(addr, size):
        for name, vm, vs, fo, fs in segs:
            if vm <= addr < vm + vs:
                o = fo + addr - vm
                return d[o:o + size]
        return b''
    return get

MD = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)

def slots(raw, base):
    ks = set()
    for i in MD.disasm(raw, base):
        if i.mnemonic == 'addi':
            m = re.match(r'r\d+, r1, (-?(?:0x)?[0-9a-f]+)$', i.op_str)
            if m:
                k = int(m.group(1), 0)
                if 8 <= k < 0x1000:
                    ks.add(k)
    return sorted(ks)

def signature(ks, gap):
    return tuple(sorted(b - a for a, b in zip(ks, ks[1:]) if b - a <= gap))

def stock_starts(ledger):
    """sorted start addresses of every stock function of the ledger (the ledger's size can run past the real end: a window must stop at the next function)"""
    s = set()
    for l in open(ledger):
        p = l.rstrip('\n').split('\t')
        if len(p) >= 5 and not p[0].startswith('#'):
            s.add(int(p[2], 16))
    return sorted(s)

def next_start(starts, a):
    import bisect
    i = bisect.bisect_right(starts, a)
    return starts[i] if i < len(starts) else a + 0x10000

def rows(stock, reb, ledger, nm):
    """yield (name, stock_addr, stock_size, rebuilt_addr, rebuilt_size, stock_loader, rebuilt_loader) for every ledger function whose name is unique in nm"""
    sget, rget = loader(stock), loader(reb)
    syms = []
    for l in open(nm):
        p = l.split()
        if len(p) == 3 and p[1] in 'tT':
            syms.append((int(p[0], 16), p[2]))
    syms.sort()
    byname = collections.defaultdict(list)
    for i, (a, n) in enumerate(syms):
        end = syms[i + 1][0] if i + 1 < len(syms) else a
        byname[n].append((a, end - a))
    seen = set()
    starts = stock_starts(ledger)
    for l in open(ledger):
        p = l.rstrip('\n').split('\t')
        if len(p) < 5 or p[0].startswith('#'):
            continue
        name, sa, ssz = p[1], int(p[2], 16), min(int(p[4]), next_start(starts, int(p[2], 16)) - int(p[2], 16))
        if name in seen:
            continue
        seen.add(name)
        if len(byname.get(name, ())) != 1:
            yield name, None, None, None, None, None, None
            continue
        ra, rsz = byname[name][0]
        # static helpers have no nm entry, so the gap to the next symbol can include other functions: cap the window
        rsz = min(rsz, ssz * 3 // 2 + 64)
        yield name, sa, ssz, ra, rsz, sget, rget

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    gap = 16
    if '--gap' in sys.argv:
        gap = int(sys.argv[sys.argv.index('--gap') + 1])
        args = [a for a in args if a != str(gap)]
    nrows = nflag = nskip = 0
    for name, sa, ssz, ra, rsz, sget, rget in rows(*args[:4]):
        if sa is None:
            nskip += 1
            continue
        nrows += 1
        ks, kr = slots(sget(sa, ssz), sa), slots(rget(ra, rsz), ra)
        ss, sr = signature(ks, gap), signature(kr, gap)
        if (ss and ss != sr) or '--all' in sys.argv:  # only a block the STOCK has contiguous can be split
            nflag += 1
            print('%-48s stock %x/%d slots %s sig %s | rebuilt %x/%d slots %s sig %s' % (
                name, sa, ssz, [hex(k) for k in ks], list(ss), ra, rsz, [hex(k) for k in kr], list(sr)))
    print('# %d functions compared, %d with a different adjacency signature, %d skipped (name not unique in nm)' % (nrows, nflag, nskip), file=sys.stderr)

if __name__ == '__main__':
    main()
