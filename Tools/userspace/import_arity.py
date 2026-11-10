#!/usr/bin/env python3
"""import_arity.py OUT.tsv LIB... - how many integer argument registers (r3..r10) each library function READS before writing them, from the library's own code (Capstone), for
the import-interposer mode of Tests/userspace/fnfuzz.c (FNFUZZ_IMPORT_NARGS=OUT.tsv). The decompile's argument lists cannot be used for this: Ghidra lists registers that are merely live at the
call (`_glgProcessPixels(a,b,c,d,e,f,0,g)` where the callee reads two), and the stock leaves the dead ones as leftovers the rebuilt code sets differently. A call whose argument registers are dead in the
callee must not make two images look different.
Analysis: linear scan of the function (to the next exported symbol); an instruction reading r3..r10 that no earlier instruction of the function wrote counts as an argument read; a `bl` to a function
of the same library adds that function's argument count for the registers not yet written (pass-through); every other `bl` clobbers r3..r12. Linear order ignores control flow (a register written on one
path only counts as written): the count can be too LOW for a register conditionally written - the validation is the run itself (a pair that still differs on a dead-looking register is looked at by hand).
Libc / CoreFoundation / dyld calls the libraries do not define come from the table of known prototypes below."""
import sys, struct, capstone
from capstone import ppc
KNOWN = {'pthread_mutex_lock': 1, 'pthread_mutex_unlock': 1, 'pthread_mutex_init': 2, 'pthread_mutex_destroy': 1, 'mach_host_self': 0, 'host_info': 4, 'mach_port_deallocate': 2, 'sysctl': 6, 'scandir': 4,
         'CFRelease': 1, 'CFStringGetCString': 4, 'CFStringGetCStringPtr': 2, 'CFStringGetLength': 1, 'IORegistryEntryCreateCFProperty': 4, 'NSAddressOfSymbol': 1, 'NSCreateObjectFileImageFromFile': 2,
         'NSDestroyObjectFileImage': 1, 'NSLinkModule': 3, 'NSLookupSymbolInModule': 2, 'NSUnLinkModule': 2}
out = sys.argv[1]; res = {}
md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN); md.detail = True
def load(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
            if cpu == 18: d = d[off:off + size]; break
    nc = struct.unpack('>I', d[16:20])[0]; p = 28; text = None; sym = None
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[p:p + 8])
        if c == 1:
            ns = struct.unpack('>I', d[p + 48:p + 52])[0]; q = p + 56
            for _ in range(ns):
                sn = d[q:q + 16].split(b'\0')[0].decode(); a, sz, off = struct.unpack('>3I', d[q + 32:q + 44])
                if sn == '__text': text = (a, sz, off)
                q += 68
        if c == 2: sym = struct.unpack('>4I', d[p + 8:p + 24])
        p += cs
    symoff, nsyms, stroff, _ = sym; syms = {}
    for i in range(nsyms):
        strx, ty, sect, desc, val = struct.unpack('>IBBhI', d[symoff + 12 * i:symoff + 12 * i + 12])
        if (ty & 0x0e) == 0x0e and sect and not (ty & 0xe0):
            e = d.index(b'\0', stroff + strx); syms[d[stroff + strx:e].decode().lstrip('_')] = val
    return d, text, syms
libs = []
for path in sys.argv[2:]:
    d, text, syms = load(path); ta, ts, to = text
    addrs = sorted(set(v for v in syms.values() if ta <= v < ta + ts)) + [ta + ts]
    libs.append((d, ta, to, syms, addrs))
def access(ins):
    """(GPRs read, GPRs written) of one PowerPC instruction, from its operands and mnemonic (Capstone gives no access flags for PPC)"""
    m = ins.mnemonic.rstrip('.'); regs = []; mems = []
    for o in ins.operands:
        if o.type == capstone.ppc.PPC_OP_REG:
            n = regnum(ins.reg_name(o.reg))
            if n is not None: regs.append(n)
        elif o.type == capstone.ppc.PPC_OP_MEM:
            b = regnum(ins.reg_name(o.mem.base)) if o.mem.base else None
            if b is not None and not (b == 0 and m.startswith(('l', 'st'))): mems.append(b)   # (RA|0) forms are not used with r0 as a base here
    if m in ('blr', 'bctr', 'b', 'bl', 'bla', 'bctrl', 'blrl', 'sync', 'isync', 'eieio', 'nop') or m.startswith(('bc', 'cr', 'mtcr', 'mcrf')) and m not in ('mtcrf',): return set(), set()
    if m in ('mtctr', 'mtlr', 'mtspr', 'mtcrf'): return set(regs[-1:]), set()
    if m in ('mflr', 'mfctr', 'mfcr', 'mfspr', 'mftb'): return set(), set(regs[:1])
    if m.startswith('cmp') or m.startswith('fcmp'): return set(regs) | set(mems), set()
    if m.startswith('stm'): return set(range(regs[0], 32)) | set(mems), set()
    if m.startswith('lm'): return set(mems), set(range(regs[0], 32))
    if m.startswith('st'):   # stores: source register, base (and index) read; the update forms (stwu) write the base
        r = set(regs) | set(mems); w = set(mems) if m.endswith('u') or m.endswith('ux') else set()
        return r, w
    if m.startswith(('l',)) and m[1:2] in ('w', 'h', 'b', 'f', 'd', 'a') and not m.startswith(('li', 'lis')):   # loads
        r = set(regs[1:]) | set(mems); w = set(regs[:1])
        if m.endswith('u') or m.endswith('ux'): w |= set(mems)
        return r, w
    if m == 'rlwimi': return set(regs), set(regs[:1])
    if not regs: return set(), set()
    return set(regs[1:]) | set(mems), set(regs[:1])
memo = {}
def regnum(n):
    if n and n.startswith('r') and n[1:].isdigit(): return int(n[1:])
    return None
def arity(lib, name, depth=0):
    d, ta, to, syms, addrs = lib
    key = (id(lib), name)
    if key in memo: return memo[key]
    memo[key] = 0
    start = syms[name]; import bisect
    end = addrs[bisect.bisect_right(addrs, start)]
    code = d[to + (start - ta): to + (end - ta)]
    written = set(); reads = set(); bynum = {v: k for k, v in syms.items()}
    for ins in md.disasm(code, start):
        rr, rw = access(ins)
        for n in rr:
            if 3 <= n <= 10 and n not in written: reads.add(n)
        if ins.mnemonic in ('bl', 'bla', 'bctrl', 'blrl'):
            tgt = None
            if ins.mnemonic == 'bl':
                try: tgt = int(ins.op_str, 0)
                except ValueError: pass
            if tgt is not None and tgt in bynum and depth < 6:
                sub = arity(lib, bynum[tgt], depth + 1)
                for n in range(3, 3 + sub):
                    if n not in written: reads.add(n)
            written |= set(range(3, 13))
        else: written |= rw
    a = (max(reads) - 2) if reads else 0
    memo[key] = a; return a
names = [l.split('\t')[0] for l in open('/dev/stdin')] if not sys.stdin.isatty() else []
for nm in names:
    if nm in KNOWN: res[nm] = KNOWN[nm]; continue
    for lib in libs:
        if nm in lib[3]: res[nm] = arity(lib, nm); break
    else: print('no definition of', nm, file=sys.stderr)
with open(out, 'w') as o:
    for k in sorted(res): o.write('%s\t%d\n' % (k, res[k]))
print('%d imports' % len(res), file=sys.stderr)
