#!/usr/bin/env python3
"""fn_norm_diff.py - normalised instruction diff of one function, stock image vs rebuilt image.

  fn_norm_diff.py STOCK_MACHO STOCK_ADDR REBUILT_MACHO REBUILT_ADDR SIZE[/REBUILT_SIZE] [--keep-regs] [--lh]

Both images are read with the file offset taken from the segment table (a fat file's ppc slice is used), disassembled with
Capstone (PPC big-endian) and normalised: nops dropped, registers replaced by 'r' / 'f' (--keep-regs keeps them), immediates
that look like branch targets or relocations dropped, `lha`/`lhz`/`lhax`/`lhzx` folded together unless --lh (so a pure
signedness difference is reported separately, as the count printed at the end). Output = unified diff of the two mnemonic
streams, which finds codegen divergences (a hoisted load, a lost switch case, another stack layout) without caring about
register allocation. A function whose streams are equal can still differ in register allocation or in the data it reads: this
is a finding aid, not a proof of parity (the proof is the fuzz result).
"""
import struct, sys, re, difflib
import capstone

def thin(path):
    d = open(path, 'rb').read()
    magic = struct.unpack('>I', d[:4])[0]
    if magic == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>IIIII', d[8 + 20 * i: 28 + 20 * i])
            if cpu == 18:  # CPU_TYPE_POWERPC
                return d[off:off + size]
        raise SystemExit('%s: no ppc slice' % path)
    return d

def segments(d):
    assert struct.unpack('>I', d[:4])[0] == 0xfeedface, 'not a 32-bit big-endian Mach-O'
    ncmds = struct.unpack('>I', d[16:20])[0]
    off = 28
    segs = []
    for _ in range(ncmds):
        cmd, size = struct.unpack('>II', d[off:off + 8])
        if cmd == 1:  # LC_SEGMENT
            name = d[off + 8: off + 24].rstrip(b'\0').decode()
            vmaddr, vmsize, fileoff, filesize = struct.unpack('>IIII', d[off + 24: off + 40])
            segs.append((name, vmaddr, vmsize, fileoff, filesize))
        off += size
    return segs

def code(path, addr, size):
    d = thin(path)
    for name, vm, vs, fo, fs in segments(d):
        if vm <= addr < vm + vs and name != '__PAGEZERO':
            o = fo + addr - vm
            return d[o:o + size]
    raise SystemExit('%s: address 0x%x not in any segment' % (path, addr))

def stream(raw, base, keep_regs, lh):
    md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
    out = []
    for i in md.disasm(raw, base):
        m, o = i.mnemonic, i.op_str
        if m == 'nop' or (m == 'ori' and o == '0, 0, 0'):
            continue
        if not lh:
            m = {'lha': 'lh?', 'lhz': 'lh?', 'lhax': 'lh?x', 'lhzx': 'lh?x'}.get(m, m)
        if m in ('b', 'bl', 'bc', 'bdnz', 'beq', 'bne', 'blt', 'bgt', 'ble', 'bge', 'bdz'):
            o = ''
        elif not keep_regs:
            o = re.sub(r'\b[rf]\d+\b', lambda x: x.group(0)[0], o)
            o = re.sub(r'\bcr\d\b', 'cr', o)
        out.append((m + ' ' + o).strip())
    return out

def main():
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    keep = '--keep-regs' in sys.argv
    lh = '--lh' in sys.argv
    sp, sa, rp, ra = a[0], int(a[1], 16), a[2], int(a[3], 16)
    sz, rz = (int(x, 0) for x in (a[4].split('/') + [a[4]])[:2])
    s = stream(code(sp, sa, sz), sa, keep, lh)
    r = stream(code(rp, ra, rz), ra, keep, lh)
    n = 0
    for l in difflib.unified_diff(s, r, 'stock', 'rebuilt', lineterm='', n=2):
        print(l)
        n += 1
    sl = sum(1 for x in stream(code(sp, sa, sz), sa, True, True) if x.startswith(('lha', 'lhz')))
    rl = sum(1 for x in stream(code(rp, ra, rz), ra, True, True) if x.startswith(('lha', 'lhz')))
    print('# stock insns %d rebuilt insns %d diff lines %d; halfword loads (lha*/lhz*): stock %d rebuilt %d' % (len(s), len(r), n, sl, rl))

if __name__ == '__main__':
    main()
