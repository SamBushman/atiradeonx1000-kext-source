#!/usr/bin/env python3
"""trace_diff.py - ordered external-behaviour trace differential of ONE function, stock vs rebuilt, under unicorn (PPC32 big-endian).   (Nov 15, prototype)

Why: the hardware fnfuzz compares return value + an arena digest.  The user's criterion is stricter: externally observable behaviour = return values, values written to
registers, external read/write ORDERING (dead loads count: a read can have hardware side effects), the arguments of calls out.  This tool records, for the same inputs run through
each image:  every data read (address, size, value, in order), every write (address, size, value, in order), every call out of the image (import name + r3..r10 + f1..f4 + stack
words), a fault (kind + address) if the run ends in one, the return registers (r3 r4 f1) and the callee-saved registers / stack pointer, and the set of executed instructions.
Then it compares the two traces exactly, after one normalisation: an address (or a 4-byte value read from / written to a place that holds an image pointer) inside either image is
replaced by (symbol, offset) so a different data layout is not a difference.  Accesses to the function's own stack frame (below the entry SP, and the 0x38-byte linkage area) are
not recorded: how a compiler lays out its frame is not external.

    trace_diff.py STOCK REBUILT LEDGER NAME [TRIALS] [options]
        --symmap F      stock symbol_map.tsv (name by address)      --nm F    rebuilt nm output
        -v              print the first differing trial in full
"""
import sys, os, struct, zlib, bisect, random, re, math
FLOAT_EXACT = os.environ.get('TD_FLOATEXACT') == '1'
ENTRYARGS = os.environ.get('TD_ENTRYARGS') == '1'      # TD_ENTRYARGS=1: at every call of an in-image function (a ledger entry) the words the caller itself wrote into its own frame at the pointer arguments r3..r10 are recorded and compared per callee name (stock vs rebuilt): the content of a stack record handed to a callee, which the ordinary event stream never shows when the callee faults / returns before reading it
FLOAT_EDGE = os.environ.get('TD_FLOATEDGE') == '1'       # TD_FLOATEDGE=1: the double-argument pool also holds values around 2^23..2^26 (where a single-precision add/sub differs from a double one before an integer conversion) and their halves
EDGE_VALS = (8388608.0, 8388609.0, -8388608.0, -8388609.0, 16777215.0, 16777216.0, -16777216.0, -16777217.0, 33554432.0, -33554432.0, 67108864.0, -67108864.0, 12345678.5)
sys.path.insert(0, os.path.expanduser('~/g5logs/fnf_237/pypkgs'))
from unicorn import *
from unicorn.ppc_const import *

ARENA = 0x50000000; ARENA_SIZE = 0x80000
STACK = 0x7f000000; STACK_SIZE = 0x100000
STOP = 0x70000000
CALLOUT = 0x60000000
RING = 0x58000000; RING_SIZE = 0x10000       # the stand-in for the kernel-mapped command ring: its contents are what the hardware is programmed by (packets: register offsets + values)
IMGMAX = 0x400000            # both images are mapped below this; values in [0x1000, IMGMAX) are treated as image pointers by the normaliser, so the generator never makes such values
NULLPAGE = 0x1000
HEAP = 0x5c000000; HEAP_SIZE = 0x200000      # TD_HEAP=1: malloc/calloc/realloc/valloc return zeroed 16-byte-aligned blocks of this region (a bump allocator reset per run), the same sequence in both images; free is a no-op.  Without it an allocator returns a small hash value, so every function that uses its result faults
HEAP_ON = os.environ.get('TD_HEAP', '0') == '1'
# TD_STOCK_HOOKS=ADDR:NAME,...  (stock-image-relative address in hex): a statically linked library function of the STOCK binary that the rebuilt corpus calls as the library import of the same name
# (GLDriver: the stock's own copy of `atexit` at 0x2748, built on keymgr, against the rebuilt's libSystem `atexit`): the stock function is run as a call-out of that name instead, so both images record the same call
STOCK_HOOKS = {int(a, 16): n for a, n in (x.split(':') for x in os.environ.get('TD_STOCK_HOOKS', '').split(',') if x)}
SLIDE2 = 0x20000000         # the control run of the stock at a second slide: a trial whose behaviour changes with the slide depends on where the image happens to sit (an input that is an address inside the image window)
SLIDE = 0x10000000          # both images are placed here (a multiple of 0x10000): everything below it is unmapped, as on the real machine

# ---------------------------------------------------------------- Mach-O
def macho(path):
    d = open(path, 'rb').read()
    if d[:4] == bytes.fromhex('cafebabe'):
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            ct, cs, o, sz, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if ct == 18: d = d[o:o+sz]; break
    magic, ct, cs, ft, ncmds, socm, flags = struct.unpack('>7I', d[:28])
    p = 28; segs = []; secs = []; symtab = None; indirect = None; locrel = []; wbase = None
    for i in range(ncmds):
        cmd, size = struct.unpack('>2I', d[p:p+8])
        if cmd == 1:
            name = d[p+8:p+24].rstrip(b'\0').decode(); vm, vs, fo, fs, mp, ip, ns, fl = struct.unpack('>8I', d[p+24:p+56])
            q = p + 56
            for j in range(ns):
                sn = d[q:q+16].rstrip(b'\0').decode(); a, s, o, al, ro, nr, f, r1 = struct.unpack('>8I', d[q+32:q+64])
                secs.append((name, sn, a, s, f & 0xff, r1)); q += 68
            if name != '__LINKEDIT': segs.append((name, vm, vs, d[fo:fo+fs]))
            if ip & 2 and wbase is None and name != '__LINKEDIT': wbase = vm
        elif cmd == 2: symtab = struct.unpack('>4I', d[p+8:p+24])
        elif cmd == 11:
            indirect = struct.unpack('>2I', d[p+56:p+64]); lo, nl = struct.unpack('>2I', d[p+72:p+80])
            for k in range(nl):
                w0, w1 = struct.unpack('>II', d[lo + 8 * k:lo + 8 * k + 8])
                if not (w0 & 0x80000000): locrel.append((w0, w1 & 0xf, (w1 >> 5) & 3))
        p += size
    base = min((vm for n, vm, vs, b in segs), default=0); bal = base if not any(rt in (4, 6) for ra, rt, rl in locrel) else base & ~0xffff       # a dylib linked at a preferred address (glprog 0x97b7b000): addresses are kept relative to a 64K-aligned base, so every image is placed at the same slide
    if bal:
        segs = [(n, vm - bal, vs, b) for n, vm, vs, b in segs]; secs = [(g, sn, a - bal, s_, f, r1) for (g, sn, a, s_, f, r1) in secs]
    rb = (wbase if (flags & 0x20) and wbase is not None else base)           # r_address is relative to the first segment (the first writable one in a split-segment image, e.g. glprog)
    locrel = [(ra + rb - bal, rt, rl) for ra, rt, rl in locrel]
    return d, segs, secs, symtab, indirect, locrel, bal, rb - bal

class V:
    """a value seen in the trace: the raw number and, when it is a 4-byte word that points into the image, its stock-space canonical form.  Two values are equal when the raw numbers
    are equal (a plain integer, equal in both images) or when both are image pointers to the same stock-space place (a layout difference only) - decided per PAIR, so an integer that
    merely looks like an address (4096) is never forced onto a symbol."""
    __slots__ = ('raw', 'canon')
    def __init__(self, raw, canon=None): self.raw = raw; self.canon = canon
    def __eq__(self, o):
        if not isinstance(o, V): return False
        return self.raw == o.raw or (self.canon is not None and self.canon == o.canon)
    def __hash__(self): return 0
    def __repr__(self): return repr(self.raw) if self.canon is None else '%s~%r' % (hex(self.raw) if isinstance(self.raw, int) else self.raw, self.canon)

def extrels(d, symtab, roff=0):
    """external relocations of a linked image (dysymtab extrel): [(address of the word, imported symbol name)].  dyld stores the symbol's address (+ the word's own addend) there."""
    out = []
    ncmds = struct.unpack('>I', d[16:20])[0]; p = 28
    for i in range(ncmds):
        cmd, size = struct.unpack('>2I', d[p:p+8])
        if cmd == 11 and symtab:
            eo, ne = struct.unpack('>2I', d[p+64:p+72]); so, ns_, stro, ssz = symtab
            for k in range(ne):
                ra, w = struct.unpack('>2I', d[eo + 8 * k:eo + 8 * k + 8])
                if (w >> 4) & 1:      # r_extern (big-endian bitfield: symbolnum:24 pcrel:1 length:2 extern:1 type:4): symbolnum indexes the symbol table
                    idx = w >> 8; strx = struct.unpack('>I', d[so + 12 * idx:so + 12 * idx + 4])[0]
                    out.append((ra + roff, d[stro + strx:d.index(b'\0', stro + strx)].decode()))
        p += size
    return out

class Img:
    def __init__(self, path, symfile=None, nmfile=None):
        d, self.segs, self.secs, symtab, indirect, self.locrel, self.bal, roff = macho(path)
        self.extrel = extrels(d, symtab, roff)
        self.path = path
        self.zero = [(a, s) for (g, sn, a, s, f, r1) in self.secs if f in (1, 0xc, 0x12)]
        self.stubs = [(a, a + s) for (g, sn, a, s, f, r1) in self.secs if 'stub' in sn]
        self.text = [(a, a + s) for (g, sn, a, s, f, r1) in self.secs if sn == '__text']
        self.end = max(vm + vs for n, vm, vs, b in self.segs)
        self.lo = min(a for (g, sn, a, sz, f, r1) in self.secs if sz)       # first byte of any section: values from here up are image addresses
        self.cells = {}                       # symbol-pointer cell address -> import name
        self.local_ptrs = []; self.def_ptrs = {}
        if symtab and indirect:
            symoff, nsyms, stroff, strsize = symtab; ioff, ni = indirect
            for (g, sn, a, s, f, r1) in self.secs:
                if f not in (6, 7): continue
                for k in range(s // 4):
                    idx = struct.unpack('>I', d[ioff + 4 * (r1 + k):ioff + 4 * (r1 + k) + 4])[0]
                    if idx & 0x80000000 and not idx & 0x40000000: self.local_ptrs.append(a + 4 * k); continue      # INDIRECT_SYMBOL_LOCAL: dyld adds the slide to the stored word
                    if idx >= 0x40000000 or idx >= nsyms: continue
                    nt, ns_, ndesc, nval = struct.unpack('>BBHI', d[symoff + 12 * idx + 4:symoff + 12 * idx + 12])
                    if (nt & 0x0e) == 0x0e and nval: self.def_ptrs[a + 4 * k] = nval - self.bal        # bound to a symbol this image defines
                    if (nt & 0x0e) in (0, 0x0c):      # an import (N_UNDF, or N_PBUD: a prebound image, e.g. the stock glprog, records the library address in n_value)
                        strx = struct.unpack('>I', d[symoff + 12 * idx:symoff + 12 * idx + 4])[0]
                        self.cells[a + 4 * k] = d[stroff + strx:d.index(b'\0', stroff + strx)].decode()
        self.syms = []                        # (addr, name) sorted
        if symfile:
            for l in open(symfile):
                p = l.rstrip('\n').split('\t')
                if len(p) >= 3 and p[1].startswith('0x') and p[2] not in ('__LINKEDIT', '?'): self.syms.append((int(p[1], 16) - self.bal, p[0]))
                elif len(p) == 3 and p[0].startswith('0x') and p[1] not in ('__LINKEDIT', '__TEXT'): self.syms.append((int(p[0], 16) - self.bal, p[2]))
        if nmfile:
            for l in open(nmfile):
                p = l.split()
                if len(p) == 3 and re.match('[0-9a-f]{8}$', p[0]) and p[1] in 'tTdDsSbBcC': self.syms.append((int(p[0], 16) - self.bal, p[2]))
        self.syms.sort(); self.symaddrs = [a for a, n in self.syms]
    is_stock = False; to_stock = None
    def unwrap(self, a):
        """the address of a one-instruction `b target` text entry (a wrapper the stock keeps as a separate entry, e.g. the _gli*DispatchTable slots 0x82f48 = `b 0x7f3e0`) is the address of its final target: the
        slot holds the same code either way (a tail jump), and the stock names only some of these wrappers"""
        for _ in range(4):
            if not any(lo <= a < hi for lo, hi in self.text) or a & 3: break
            w = None
            for nm_, vm, vs, data in self.segs:
                if vm <= a < vm + len(data) - 3: w = struct.unpack('>I', data[a - vm:a - vm + 4])[0]; break
            if w is None or w >> 26 != 18 or w & 3: break
            t = (a + (((w & 0x3fffffc) ^ 0x2000000) - 0x2000000)) & 0xffffffff
            a = t
        return a
    stock_secs = None
    def canon(self, a):
        """image address -> ('IMG', stock-space address).  Identity for the stock.  For the rebuilt image: its data sections mirror the stock's layout up to one constant shift per section
        (checked: every labelled object of __data/__bss/__const/__literal*/__common has the same rebuilt-minus-stock delta), so an address inside a rebuilt section maps to the same
        offset inside the stock's section of that name; text (functions) and anything else goes through the symbol name (stock map, ledger, or the hex suffix of a name)."""
        for (g, sn, sa, ss, f, r1) in self.secs:             # a pointer into the C-string pool: the layout of the pool differs between the images, so the string itself is the identity
            if sn == '__cstring' and sa <= a < sa + ss:
                for nm_, vm, vs, data in self.segs:
                    if vm <= a < vm + len(data):
                        o = a - vm; e = data.find(b'\0', o); return ('STR', bytes(data[o:e if e >= 0 else o + 64]))
        a = self.unwrap(a)
        if self.is_stock: return ('IMG', a)
        for (g, sn, sa, ss, f, r1) in self.secs:
            if sa <= a < sa + ss and sn not in ('__text', '__cstring', '__eh_frame') and self.stock_secs and (g, sn) in self.stock_secs:
                st_a, st_s = self.stock_secs[(g, sn)]
                if st_s >= ss: return ('IMG', st_a + (a - sa))
        name, off = self.sym(a); sa = self.to_stock.get(name) if self.to_stock else None
        return ('IMG', sa + off) if sa is not None else ('IMGR', name, off)
    def sym(self, addr):
        i = bisect.bisect_right(self.symaddrs, addr) - 1
        if i < 0: return ('?', addr)
        a, n = self.syms[i]
        # symbol offsets beyond a section end are meaningless; keep (name, off)
        return (n, addr - a)

def callout_ids(imgs):
    names = sorted(set(n for im in imgs for n in list(im.cells.values()) + [nm for _, nm in im.extrel]) | {'vcb'})      # 'vcb': the stand-in for a virtual method / callback the input memory points at (see repair_step)
    return {n: i for i, n in enumerate(names)}, names

# ---------------------------------------------------------------- one image under emulation
class Sim:
    nargs = None
    MATHF = {'sqrt': 0, 'sqrtf': 0, 'sin': 0, 'cos': 0, 'pow': 0, 'floor': 0, 'ceil': 0, 'log': 0, 'logf': 0, 'exp': 0, 'round': 0, 'roundf': 0, 'frexp': 1, 'exp2': 0, 'log2': 0, 'acos': 0, 'asin': 0, 'atan': 0, 'tan': 0, 'trunc': 0, 'atan2f': 0, 'isnanf': 0}      # double arguments travel in f1..f2, not in GPRs
    LIBC = {'io_connect_method_scalarI_scalarO': 6, 'io_connect_method_scalarI_structureO': 6, 'io_connect_method_scalarI_structureI': 6, 'io_connect_method_structureI_structureO': 6, 'memcpy': 3, 'memset': 3, 'memmove': 3, 'memcmp': 3, 'bzero': 2, 'strlen': 1, 'strcpy': 2, 'strcmp': 2, 'strncmp': 3, 'strncpy': 3, 'strlcpy': 3, 'strcat': 2, 'strchr': 2, 'strrchr': 2, 'malloc': 1, 'calloc': 2, 'realloc': 2, 'free': 1, 'valloc': 1, 'vfree': 1, 'Unwind_Resume': 1, 'cxa_atexit': 3, 'cxa_guard_acquire': 1, 'cxa_guard_release': 1, 'dlopen': 2, 'dlsym': 2, 'exit': 1, 'fclose': 1, 'fgets': 3, 'fopen': 2, 'fread': 4, 'fwrite': 4, 'getenv': 1, 'getpid': 0, 'index': 2, 'rindex': 2, 'pclose': 1, 'popen': 2, 'puts': 1, 'usleep': 1, 'pthread_mutexattr_init': 1, 'pthread_mutexattr_settype': 2, 'keymgr_get_and_lock_processwide_ptr': 1, 'keymgr_set_and_unlock_processwide_ptr': 2, 'atexit': 1, 'ZdlPv': 1, 'ZdaPv': 1, 'Znwm': 1, 'Znwj': 1, 'Znam': 1, 'Znaj': 1, 'setjmp': 1, 'longjmp': 2, '_setjmp': 1, '_longjmp': 2, 'ecvt': 3, 'fcvt': 3}
    FLOATARGS = set()       # further callees taking double arguments (none known among the GLDriver imports)
    FPRN = {'sqrt': 1, 'sqrtf': 1, 'sin': 1, 'cos': 1, 'pow': 2, 'floor': 1, 'ceil': 1, 'log': 1, 'logf': 1, 'exp': 1, 'round': 1, 'roundf': 1, 'frexp': 1, 'ecvt': 1, 'fcvt': 1, 'exp2': 1, 'log2': 1, 'acos': 1, 'asin': 1, 'atan': 1, 'tan': 1, 'trunc': 1, 'atan2f': 2, 'isnanf': 1}      # double arguments per callee (the other FPRs are leftovers)
    DBLFIRST = {'ecvt', 'fcvt'}      # (double, int, int*, int*): the double travels in f1 (its GPR shadow is not an argument), the three others in r5..r7
    def __init__(self, img, ids, names, stackfill=0, slide=SLIDE):
        self.slide = slide; self.img = img; self.ids = ids; self.names = names
        uc = Uc(UC_ARCH_PPC, UC_MODE_PPC32 | UC_MODE_BIG_ENDIAN); self.uc = uc
        try: uc.ctl_set_cpu_model(UC_CPU_PPC32_7457_V1_2)
        except Exception: pass
        dl = (slide - img.bal) & 0xffffffff       # dyld's slide of the stored absolute values
        for name, vm, vs, data in img.segs:
            data = bytearray(data)
            for (ra, rt, rl) in img.locrel:                 # dyld's slide: a pointer word moves by the slide; an lis/ha16 immediate by slide>>16 (the slide is a multiple of 0x10000, so lo16 halves stay)
                if vm <= ra < vm + len(data):
                    o = ra - vm
                    if rt == 0 and rl == 2: data[o:o+4] = struct.pack('>I', (struct.unpack('>I', data[o:o+4])[0] + dl) & 0xffffffff)
                    elif rt in (4, 6): data[o+2:o+4] = struct.pack('>H', (struct.unpack('>H', data[o+2:o+4])[0] + (dl >> 16)) & 0xffff)
            uc.mem_map(vm + slide, (vs + 0xfff) & ~0xfff); uc.mem_write(vm + slide, bytes(data))
        for za, zs in img.zero: uc.mem_write(za + slide, bytes(zs))
        for ca in img.local_ptrs: uc.mem_write(ca + slide, struct.pack('>I', (struct.unpack('>I', bytes(uc.mem_read(ca + slide, 4)))[0] + dl) & 0xffffffff))
        for ca, nv_ in img.def_ptrs.items(): uc.mem_write(ca + slide, struct.pack('>I', (nv_ + slide) & 0xffffffff))   # nv_ is already image-relative
        for ca, nm in img.cells.items(): uc.mem_write(ca + slide, struct.pack('>I', CALLOUT + 16 * ids[nm]))
        for ca, nm in img.extrel: uc.mem_write(ca + slide, struct.pack('>I', CALLOUT + 16 * ids[nm]))      # words dyld binds through an external relocation
        self.snap = [(vm + slide, bytes(uc.mem_read(vm + slide, len(data)))) for name, vm, vs, data in img.segs if name != '__TEXT']
        self.tx = [(vm + slide, vm + slide + vs) for name, vm, vs, data in img.segs if name == '__TEXT']        # __TEXT is r-x in a real process: a wild store into it faults (and cannot corrupt the next run, which restores only the other segments)
        for vm, vs in [(vm + slide, (vs + 0xfff) & ~0xfff) for name, vm, vs, data in img.segs if name == '__TEXT']: uc.mem_protect(vm, vs, UC_PROT_READ | UC_PROT_EXEC)
        uc.mem_map(ARENA, ARENA_SIZE); uc.mem_map(HEAP, HEAP_SIZE); self.heap_used = 0; uc.mem_map(RING, RING_SIZE); uc.mem_map(STACK, STACK_SIZE); uc.mem_map(STOP, 0x1000); uc.mem_map(CALLOUT, 0x10000)
        uc.hook_add(UC_HOOK_CODE, self.on_code)
        uc.hook_add(UC_HOOK_MEM_READ, self.on_read)
        uc.hook_add(UC_HOOK_MEM_WRITE, self.on_write)
        uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED | UC_HOOK_MEM_FETCH_UNMAPPED, self.on_unmapped)
        self.stackfill = stackfill
        uc.reg_write(UC_PPC_REG_MSR, uc.reg_read(UC_PPC_REG_MSR) | 0x2000 | 0x2000000 | 0x8000)   # FP available, AltiVec available, (EE)

    # ---- normalisation: image addresses/values -> (symbol, offset)
    def na(self, a):
        u = a - self.slide
        if self.img.lo <= u < self.img.end:
            if u in self.img.cells: return ('IMPORT', self.img.cells[u])
            return self.img.canon(u)
        return a
    def nv(self, v, size):
        if size == 4 and isinstance(v, int):
            if self.img.lo <= v - self.slide < self.img.end: return V(v, self.img.canon(v - self.slide))
            if self.sp0 - 0x40000 <= v < self.sp0: return V(v, ('OWNFRAME',))        # the address of one of the function's own locals (an out parameter): the frame layout is the compiler's
        return V(v)

    entries = {}
    def snap_entry(self, uc, name):
        r1 = uc.reg_read(UC_PPC_REG_1); items = []
        for i in range(3, 11):
            p = uc.reg_read(UC_PPC_REG_0 + i)
            if not (r1 <= p < self.sp0 and p & 3 == 0): continue
            ws = []
            for k in range(16):
                q = p + 4 * k
                if q + 4 > self.sp0 or not all(b in self.fwb for b in range(q, q + 4)): break
                w = int.from_bytes(uc.mem_read(q, 4), 'big')
                if (w >> 23) & 0xff == 0xff and w & 0x7fffff: w = 0x7fc00000        # NaN payloads are one class (see the stores)
                ws.append(self.nv(w, 4))
            if ws: items.append((i - 3, tuple(ws)))
        if items: self.ent.append((name, tuple(items)))

    def own_frame(self, a): return STACK <= a < self.sp0 + 0x38 + 4 * getattr(self, 'nstack', 0)      # incl. the incoming stack-parameter words (9th+ arguments): the callee owns them; everything below sp0 down to the stack's end is this call's frames, alloca included (gld_uploadParamConstants allocas count*16 bytes of a random count: more than the 0x40000 window the first census used) (PowerPC ABI), a store there is not an external effect

    def flush(self):
        for a, s, wpc, old in self.pw:
            self.evpc[len(self.ev)] = wpc - self.slide
            try: v = int.from_bytes(self.uc.mem_read(a, s), 'big') if s <= 8 else bytes(self.uc.mem_read(a, s)).hex()
            except Exception: continue        # the store faulted (unmapped): it never happened, the fault event says so
            if old is not None and s <= 8 and v == int.from_bytes(old, 'big'): continue        # a silent store (the word already held that value) changes nothing: not an effect
            if s in (4, 8) and isinstance(v, int) and self.is_fpstore(wpc):      # the payload of a NaN written by an FP store is not observable behaviour (fnfuzz NANCANON precedent): canonical quiet NaN
                if s == 4 and (v >> 23) & 0xff == 0xff and v & 0x7fffff: v = 0x7fc00000
                elif s == 8 and (v >> 52) & 0x7ff == 0x7ff and v & ((1 << 52) - 1) and v not in self.rd8: v = 0x7ff8000000000000      # (an 8-byte word that was read from memory is a copy, e.g. two floats moved with lfd/stfd: bit-exact on hardware)
            if old is not None and s == 4 and isinstance(v, int) and (v >> 23) & 0xff == 0xff and v & 0x7fffff:      # a NaN word overwritten by another NaN word: one class (see bytes_of), so not an observable change
                o = int.from_bytes(old, 'big')
                if (o >> 23) & 0xff == 0xff and o & 0x7fffff: continue
            nanw = s == 4 and isinstance(v, int) and (v >> 23) & 0xff == 0xff and v & 0x7fffff
            if old is not None and s <= 8:      # bytes of a wider store that already held their value are not effects either (the other image may have stored only the changed part)
                ob = bytes(old); nb = v.to_bytes(s, 'big')
                sil = tuple(k for k in range(s) if ob[k] == nb[k])
                if sil: self.ev.append(('WS', self.na(a), sil))
            self.ev.append(('W', self.na(a), s, self.nv(v, s)))
        self.pw = []

    def is_fpstore(self, pc):
        try: w = int.from_bytes(self.uc.mem_read(pc, 4), 'big')
        except Exception: return False
        op = w >> 26
        return op in (52, 53, 54, 55) or (op == 31 and ((w >> 1) & 0x3ff) in (663, 695, 727, 759))      # stfs stfsu stfd stfdu / stfsx stfsux stfdx stfdux

    def on_code(self, uc, addr, size, ud):
        self.flush(); self.pc = addr
        self.cov.add(addr - self.slide); self.n += 1
        if self.n > self.limit: self.status = 'TIMEOUT'; uc.emu_stop(); return
        if addr == STOP: self.status = 'RET'; uc.emu_stop(); return
        if not (CALLOUT <= addr < CALLOUT + 0x10000) and not (self.img.lo <= addr - self.slide < self.img.end) and NULLPAGE <= addr:       # a wild branch into non-code (arena / stack data): whatever executes there is arbitrary, so the run ends at the fetch
            self.ev.append(('F', 'wild', self.na(addr))); self.fpc = self.pc - self.slide; self.status = 'FAULT'; uc.emu_stop(); return
        if ENTRYARGS and self.n > 1 and (addr - self.slide) in self.entries: self.snap_entry(uc, self.entries[addr - self.slide])
        hook = STOCK_HOOKS.get(addr - self.slide) if self.img.is_stock else None
        if CALLOUT <= addr < CALLOUT + 0x10000 or hook:
            if hook:
                nm = hook
                if nm.lstrip('_') == 'cxa_atexit': uc.reg_write(UC_PPC_REG_0 + 4, 0); uc.reg_write(UC_PPC_REG_0 + 5, self.slide)      # the stock's own atexit(f) is __cxa_atexit(f, 0, __dso_handle) (it reads the handle = the image base, then registers through keymgr)
            else: idx = (addr - CALLOUT) // 16; nm = self.names[idx]
            sp = uc.reg_read(UC_PPC_REG_1)
            na = (self.nargs or {}).get(nm.lstrip('_'), self.LIBC.get(nm.lstrip('_'), 8))
            if nm.lstrip('_') in self.MATHF: na = self.MATHF[nm.lstrip('_')]
            nf_fmt = 0
            if nm.lstrip('_') in ('sprintf', 'printf', 'snprintf', 'fprintf'): na, nf_fmt = self.printf_args(uc, nm.lstrip('_'), na)
            r0 = 5 if nm.lstrip('_') in self.DBLFIRST else 3
            r = [uc.reg_read(UC_PPC_REG_0 + i) for i in range(r0, r0 + min(na, 8))]
            f = [uc.reg_read(UC_PPC_REG_FPR0 + i) for i in range(1, 1 + (nf_fmt or self.FPRN.get(nm.lstrip('_'), 4)))] if (nm.lstrip('_') in self.MATHF or nm.lstrip('_') in self.DBLFIRST or nm.lstrip('_') in self.FLOATARGS or nf_fmt) else []      # f1.. are arguments only of the callees that take doubles; elsewhere they are leftovers
            f = [0x7ff8000000000000 if (x >> 52) & 0x7ff == 0x7ff and x & ((1 << 52) - 1) else x for x in f]      # a NaN double argument: its payload / sign is not behaviour (same rule as the NaN stores)
            r = [self.nv(x, 4) if not isinstance(x, V) else x for x in r]
            if hook and nm.lstrip('_') == 'cxa_atexit' and len(r) > 2: r[2] = V(self.slide, ('IMG', 0))      # __dso_handle is the image base: an image address, not a slide-dependent number
            if nm.lstrip('_') in self.VPRINTF: r = self.va_canon(uc, nm.lstrip('_'), r)
            if nm.lstrip('_') in self.IOIN: r = self.io_canon(nm.lstrip('_'), r)
            st = [self.nv(int.from_bytes(uc.mem_read(sp + 0x38 + 4 * i, 4), 'big'), 4) for i in range(max(0, na - 8))]
            if nm.lstrip('_') in self.EFFECTS and self.libc(uc, nm.lstrip('_'), [uc.reg_read(UC_PPC_REG_0 + i) for i in range(3, 6)]): return
            self.ev.append(('C', nm, tuple(r), tuple(f), tuple(st)))
            self.ncalls += 1
            if nm.lstrip('_') in ('abort', 'exit', 'cxa_rethrow'): self.ev.append(('F', 'noreturn', nm)); self.fpc = self.pc - self.slide; self.status = 'FAULT'; uc.emu_stop(); return       # the callee never returns: nothing after the call is behaviour
            if HEAP_ON and nm.lstrip('_') in ('malloc', 'calloc', 'realloc', 'valloc', 'free'):
                base = nm.lstrip('_'); rv = [x.raw if isinstance(x, V) else x for x in r]
                if base == 'free': uc.reg_write(UC_PPC_REG_3, 0)
                else:
                    n = (rv[0] * rv[1] if base == 'calloc' else rv[1] if base == 'realloc' else rv[0]) & 0xffffffff
                    if n > 0x100000 or self.heap_used + ((n + 15) & ~15) + 16 > HEAP_SIZE: p = 0
                    else:
                        p = HEAP + self.heap_used; self.heap_used += max(16, (n + 15) & ~15)
                        if base == 'realloc' and rv[0]:
                            old = self.heap_sizes.get(rv[0], 0); k = min(n, old)
                            if k and HEAP <= rv[0] < HEAP + HEAP_SIZE: uc.mem_write(p, bytes(uc.mem_read(rv[0], k)))
                        self.heap_sizes[p] = n
                    uc.reg_write(UC_PPC_REG_3, p)
                uc.reg_write(UC_PPC_REG_PC, uc.reg_read(UC_PPC_REG_LR)); return
            h = zlib.crc32(('%s/%d' % (nm, self.ncalls)).encode())      # a deterministic, name-keyed return value (the same in both images)
            uc.reg_write(UC_PPC_REG_3, (h & 0x3f) if nm.lstrip('_') in ('sprintf', 'snprintf', 'vsprintf', 'vsnprintf', 'fprintf', 'printf', 'vfprintf', 'vprintf') else h & 0xffff); uc.reg_write(UC_PPC_REG_4, 0)      # a printf's result is a byte count: small, so `buf += sprintf(buf, ..)` stays inside the buffer
            uc.reg_write(UC_PPC_REG_PC, uc.reg_read(UC_PPC_REG_LR))
            # do not leave a stale write pending; a call out also clobbers nothing else by contract

    EFFECTS = {'memcpy', 'memmove', 'memset', 'bzero', 'strlen', 'strcpy', 'strncpy', 'strcat', 'strcmp', 'strncmp', 'memcmp'}
    class _Fault(Exception): pass
    def _rd(self, a, n):
        if n == 0: return b''
        if a < NULLPAGE or n > (1 << 20): raise Sim._Fault(a)
        try: return bytes(self.uc.mem_read(a, n))
        except UcError:
            for p in range(a, a + n):
                try: self.uc.mem_read(p, 1)
                except UcError: raise Sim._Fault(p)
            raise Sim._Fault(a)
    VPRINTF = {'vsnprintf': (2, 3), 'vsprintf': (1, 2), 'vfprintf': (1, 2), 'vprintf': (0, 1)}      # name: (format argument index, va_list argument index)
    IOIN = {'io_connect_method_scalarI_scalarO': ((2, 3, 4),), 'io_connect_method_scalarI_structureO': ((2, 3, 4),), 'io_connect_method_scalarI_structureI': ((2, 3, 4), (4, 5, 1)), 'io_connect_method_structureI_structureO': ((2, 3, 1),)}
    def io_canon(self, bn, r):
        """IOKit method call-outs: what the kernel receives is the CONTENT of the input buffers (scalar words, or bytes for a structure), not the caller's address of them (the stock spills an argument into its caller's
        parameter area where the rebuilt corpus uses a local: different addresses, same bytes), so each input pointer is replaced by the bytes it points at (arguments: pointer index, count index, bytes per count unit)."""
        r = list(r)
        for pi, ci, unit in self.IOIN[bn]:
            if len(r) <= ci: continue
            try:
                n = r[ci].raw if isinstance(r[ci], V) else r[ci]; ap = r[pi].raw if isinstance(r[pi], V) else r[pi]
                d = self._rd(ap, min(n * unit, 4096)); r[pi] = V(('IN', bytes(d)), ('IN', bytes(d)))
            except Exception: pass
        return r
    def va_canon(self, uc, bn, r):
        """v*printf callout: the va_list argument is a pointer into the caller's frame (the stock spills r8..r10 into its caller's parameter area, the rebuilt corpus into a local array: different
        addresses, same words).  What the callee can observe through it is the words the format consumes (integer conversions one word, `ll` and doubles two, `*` one more), so those words
        replace the pointer in the call record; an unreadable format means the callee faults on the format first and the va_list is not read."""
        fi, ai = self.VPRINTF[bn]
        if len(r) <= ai: return r
        try:
            fv = r[fi].raw if isinstance(r[fi], V) else r[fi]; fmt = self._cstr(fv, 4096).decode('latin1')
        except Exception: return r[:ai] + [V(0)] + r[ai + 1:]
        words = 0
        for m in re.finditer(r'%(?:[-+ #0]*)(\*|\d+)?(?:\.(\*|\d+))?(hh|h|ll|l|L|q|j|z|t)?([diouxXcspnfFeEgGaA%])', fmt):
            if m.group(4) == '%': continue
            words += (m.group(1) == '*') + (m.group(2) == '*')
            words += 2 if (m.group(4) in 'fFeEgGaA' or m.group(3) in ('ll', 'q')) else 1
        ap = r[ai].raw if isinstance(r[ai], V) else r[ai]
        try: vals = tuple(self.nv(int.from_bytes(uc.mem_read(ap + 4 * k, 4), 'big'), 4) for k in range(min(words, 16)))
        except Exception: return r
        return r[:ai] + [V(('VA',) + tuple(x.raw if isinstance(x, V) else x for x in vals), ('VA',) + tuple((x.canon if isinstance(x, V) and x.canon is not None else (x.raw if isinstance(x, V) else x)) for x in vals))] + r[ai + 1:]
    def printf_args(self, uc, bn, default):
        """printf-family callout: the fixed arguments plus the ones the format string consumes (integer-class conversions take a GPR each, `ll` two, `*` one more; floating conversions take an FPR):
        the other argument registers are leftovers of the caller and differ between compilers without being behaviour."""
        fi = {'printf': 0, 'sprintf': 1, 'snprintf': 2, 'fprintf': 1}[bn]
        try: fmt = self._cstr(uc.reg_read(UC_PPC_REG_0 + 3 + fi), 4096).decode('latin1')
        except Exception: return fi + 1, 0      # an unreadable format: the callee faults on it, so only the fixed arguments (stream/buffer, size, format) are behaviour
        gpr = fi + 1; fpr = 0
        for m in re.finditer(r'%(?:[-+ #0]*)(\*|\d+)?(?:\.(\*|\d+))?(hh|h|ll|l|L|q|j|z|t)?([diouxXcspnfFeEgGaA%])', fmt):
            if m.group(4) == '%': continue
            gpr += (m.group(1) == '*') + (m.group(2) == '*')
            if m.group(4) in 'fFeEgGaA': fpr += 1
            else: gpr += 2 if m.group(3) in ('ll', 'q') else 1
        return min(gpr, 8), fpr
    def _cstr(self, a, cap=1 << 16):
        out = b''
        while len(out) < cap:
            try: c = self._rd(a + len(out), 1)
            except Sim._Fault as e: raise
            if c == b'\0': return out
            out += c
        return out
    def _wr(self, a, b):
        if not b: return
        if a < NULLPAGE or len(b) > (1 << 20): raise Sim._Fault(a)
        try: self.uc.mem_write(a, b)
        except UcError:
            for p in range(a, a + len(b)):
                try: self.uc.mem_write(p, b[p - a:p - a + 1])
                except UcError: raise Sim._Fault(p)
    def _log(self, kind, a, b):
        if not b or self.in_stub() or self.own_frame(a): return
        self.ev.append((kind, self.na(a), bytes(b)))
    def libc(self, uc, nm, r):
        """perform a libc call's memory effect and record it as reads / writes (kinds 'RB' / 'WB' = bytes), not as a call: an inlined struct copy in one image and a memcpy call in the other are the same behaviour"""
        a, b, c = r; ret = a
        try:
            if nm in ('memcpy', 'memmove'): d = self._rd(b, c); self._log('RB', b, d); self._wr(a, d); self._log('WB', a, d)
            elif nm == 'memset': d = bytes([b & 0xff]) * c if c <= (1 << 20) else None; self._wr(a, d if d is not None else b''); self._log('WB', a, d or b'')
            elif nm == 'bzero': self._wr(a, bytes(b) if b <= (1 << 20) else b''); self._log('WB', a, bytes(b) if b <= (1 << 20) else b''); ret = 0
            elif nm == 'strlen': d = self._cstr(a); self._log('RB', a, d + b'\0'); ret = len(d)
            elif nm == 'strcpy': d = self._cstr(b) + b'\0'; self._log('RB', b, d); self._wr(a, d); self._log('WB', a, d)
            elif nm == 'strcat': e = self._cstr(a); d = self._cstr(b) + b'\0'; self._log('RB', a, e + b'\0'); self._log('RB', b, d); self._wr(a + len(e), d); self._log('WB', a + len(e), d)
            elif nm == 'strncpy':
                d = self._cstr(b, c) if c else b''; d = (d + b'\0' * c)[:c]; self._log('RB', b, d[:len(d.rstrip(b"\0")) + 1] if c else b''); self._wr(a, d); self._log('WB', a, d)
            elif nm in ('strcmp', 'strncmp'):
                x = self._cstr(a, c if nm == 'strncmp' else 1 << 16); y = self._cstr(b, c if nm == 'strncmp' else 1 << 16)
                self._log('RB', a, x); self._log('RB', b, y); ret = (x > y) - (x < y)
            elif nm == 'memcmp': x = self._rd(a, c); y = self._rd(b, c); self._log('RB', a, x); self._log('RB', b, y); ret = (x > y) - (x < y)
        except Sim._Fault as e:
            self.ev.append(('F', 'read' if nm not in ('memset', 'bzero') else 'write', self.na(e.args[0]))); self.status = 'FAULT'; uc.emu_stop(); return True
        uc.reg_write(UC_PPC_REG_3, ret & 0xffffffff); uc.reg_write(UC_PPC_REG_PC, uc.reg_read(UC_PPC_REG_LR)); self.ncalls += 1
        return True

    def in_stub(self): return any(lo <= self.pc - self.slide < hi for lo, hi in self.img.stubs)

    def on_read(self, uc, access, addr, size, value, ud):
        if addr < NULLPAGE: self.ev.append(('F', 'read', addr)); self.fpc = self.pc - self.slide; self.status = 'FAULT'; self.fa = addr; uc.emu_stop(); return
        if self.in_stub() or self.own_frame(addr): return
        try: v = int.from_bytes(uc.mem_read(addr, size), 'big') if size <= 8 else bytes(uc.mem_read(addr, size)).hex()
        except Exception: v = None
        self.evpc[len(self.ev)] = self.pc - self.slide
        self.ev.append(('R', self.na(addr), size, self.nv(v, size)))
        if size == 8 and isinstance(v, int): self.rd8.add(v)

    def on_write(self, uc, access, addr, size, value, ud):
        if any(lo <= addr < hi for lo, hi in self.tx): self.ev.append(('F', 'write', self.na(addr))); self.fpc = self.pc - self.slide; self.status = 'FAULT'; self.fa = None; uc.emu_stop(); return
        if addr < NULLPAGE: self.ev.append(('F', 'write', addr)); self.fpc = self.pc - self.slide; self.status = 'FAULT'; self.fa = addr; uc.emu_stop(); return
        if ENTRYARGS and not self.in_stub() and self.own_frame(addr):
            r1 = uc.reg_read(UC_PPC_REG_1)
            if size == 4 and (value & 0xffffffff) == r1 and addr < r1 and r1 - addr < 0x100000:       # stwu r1,-N(r1): a new frame starts here - whatever an earlier call left in these bytes is stale residue, not a value this function wrote (it differs between the images with the frame sizes)
                self.fwb = {b for b in self.fwb if not addr <= b < r1}
            self.fwb.update(range(addr, addr + size))
        if self.in_stub() or self.own_frame(addr): return
        try: old = bytes(uc.mem_read(addr, size)) if size <= 8 and not (STACK <= addr < STACK + STACK_SIZE) else None       # silent-store detection only against input-defined memory (the stack holds the fill pattern, which differs between the two control fills)
        except Exception: old = None
        self.pw.append((addr, size, self.pc, old))

    def on_unmapped(self, uc, access, addr, size, value, ud):
        k = {UC_MEM_READ_UNMAPPED: 'read', UC_MEM_WRITE_UNMAPPED: 'write', UC_MEM_FETCH_UNMAPPED: 'fetch'}.get(access, '?')
        self.ev.append(('F', k, self.na(addr))); self.fpc = self.pc - self.slide; self.status = 'FAULT'; self.fa = addr if k != 'fetch' else None; return False

    # ---- one run
    def run(self, entry, args, dargs, stackwords, arena, limit=400000):
        uc = self.uc
        for vm, b in self.snap: uc.mem_write(vm, b)
        for za, zs in self.img.zero: uc.mem_write(za + self.slide, bytes(zs))
        if self.heap_used: uc.mem_write(HEAP, bytes(self.heap_used))
        self.heap_used = 0; self.heap_sizes = {}
        uc.mem_write(ARENA, arena); uc.mem_write(RING, bytes(RING_SIZE)); uc.mem_write(RING + 0x10, struct.pack('>I', RING_SIZE // 4))
        uc.mem_write(STACK, bytes([self.stackfill & 0xff]) * STACK_SIZE) if self.stackfill < 256 else uc.mem_write(STACK, struct.pack('>I', self.stackfill) * (STACK_SIZE // 4))
        self.sp0 = STACK + STACK_SIZE - 0x2000
        self.nstack = len(stackwords)
        for i, w in enumerate(stackwords): uc.mem_write(self.sp0 + 0x38 + 4 * i, struct.pack('>I', w))
        for i in range(32): uc.reg_write(UC_PPC_REG_0 + i, 0x11110000 + i)       # defined garbage in every register the call does not define
        for i in range(32): uc.reg_write(UC_PPC_REG_FPR0 + i, 0x3ff0000000000000 + i)
        for i, a in enumerate(args[:8]): uc.reg_write(UC_PPC_REG_0 + 3 + i, a)
        for i, b in enumerate(dargs[:13]): uc.reg_write(UC_PPC_REG_FPR1 + i, b)
        uc.reg_write(UC_PPC_REG_1, self.sp0); uc.reg_write(UC_PPC_REG_LR, STOP)
        self.entry_nv = [uc.reg_read(UC_PPC_REG_0 + i) for i in range(14, 32)]
        self.fpc = None; self.fa = None; self.ev = []; self.evpc = {}; self.fwb = set(); self.ent = []; self.pw = []; self.rd8 = set(); self.cov = set(); self.n = 0; self.limit = limit; self.status = '?'; self.ncalls = 0; self.pc = entry + self.slide
        try: uc.emu_start(entry + self.slide, STOP, count=limit + 10)
        except UcError as e:
            if self.status == '?':
                self.status = 'UCERR'
                try:
                    pcx = uc.reg_read(UC_PPC_REG_PC); wx = struct.unpack('>I', bytes(uc.mem_read(pcx, 4)))[0]
                    wp = struct.unpack('>I', bytes(uc.mem_read(pcx - 4, 4)))[0]
                    if wp >> 26 == 31 and ((wp >> 1) & 0x3ff) in (20, 84): wx = wp; pcx -= 4      # unicorn reports the pc after the lwarx/ldarx that raised
                    xo = (wx >> 1) & 0x3ff
                    if wx >> 26 == 31 and xo in (20, 150, 84, 214):      # lwarx / stwcx. / ldarx / stdcx. at an address that is not 4-aligned: the real CPU takes an alignment exception (SIGBUS); the emulator raises UC_ERR_EXCEPTION
                        ra = (wx >> 16) & 31; ea = ((uc.reg_read(UC_PPC_REG_0 + ra) if ra else 0) + uc.reg_read(UC_PPC_REG_0 + ((wx >> 11) & 31))) & 0xffffffff
                        self.status = 'FAULT'; self.fa = None; self.fpc = pcx - self.slide; self.ev.append(('F', 'read' if xo in (20, 84) else 'write', self.na(ea)))
                    else: self.status = 'UCERR'; self.ev.append(('F', 'uc', '%s at pc %#x word %#010x' % (e, pcx - self.slide, wx)))
                except Exception: self.status = 'UCERR'; self.ev.append(('F', 'uc', str(e)))
        self.flush()
        if self.status == '?':
            pcn = uc.reg_read(UC_PPC_REG_PC)
            if pcn == STOP: self.status = 'RET'
            else: self.status = 'FAULT'; self.ev.append(('F', 'fetch', self.na(pcn)))
        regs = {'r3': uc.reg_read(UC_PPC_REG_3), 'r4': uc.reg_read(UC_PPC_REG_4), 'f1': uc.reg_read(UC_PPC_REG_FPR1), 'r1': uc.reg_read(UC_PPC_REG_1) - self.sp0,
                'nv': tuple(uc.reg_read(UC_PPC_REG_0 + i) for i in range(14, 32)), 'fnv': tuple(uc.reg_read(UC_PPC_REG_FPR0 + i) for i in range(14, 32)),
                'cr': uc.reg_read(UC_PPC_REG_CR) & 0x00fff000, 'fpc': getattr(self, 'fpc', None) if self.status == 'FAULT' else None}
        if ENTRYARGS: regs['ent'] = self.ent
        return self.status, self.ev, regs, self.cov

# ---------------------------------------------------------------- inputs
def prime_ring(arena, ia, pc):
    """make the first argument (when it is a pointer into the arena) a context whose command-stream fields point at the ring, so that packet-emitting code really writes packets: ctx+0x1d8 last header, +0x1dc write cursor,
    +0x1e0 ring limit, +0x1e4 ring map (gld_ctx_fields.h: GLD_lastHeader / GLD_writeCursor / GLD_ringLimit / GLD_ringMap); the same patched arena goes to both images"""
    if not pc or pc[0] != 'p': return arena
    off = ia[0] - ARENA
    if not (0 <= off <= len(arena) - 0x1f0): return arena
    a = bytearray(arena)
    for k, v in ((0x1d8, RING + 0x1c), (0x1dc, RING + 0x20), (0x1e0, RING + RING_SIZE - 0x400), (0x1e4, RING)): a[off + k:off + k + 4] = struct.pack('>I', v)
    return bytes(a)

class Gen:
    def __init__(self, seed): self.r = random.Random(seed)
    def ptr(self): return ARENA + 0x1000 + (self.r.randrange(ARENA_SIZE - 0x3000) & ~3)
    def safe(self, v):                       # the normaliser treats [0x1000, IMGMAX) as image pointers
        return v if not (SLIDE <= v < SLIDE + IMGMAX) else (v | 0x80000000)
    def int_(self):
        r = self.r; k = r.randrange(20)
        if k < 5: v = 0
        elif k < 9: v = 1 + r.randrange(16)
        elif k < 11: v = 1 << r.randrange(32)
        elif k < 12: v = (1 << r.randrange(32)) - 1
        elif k < 15: v = r.getrandbits(32)
        elif k < 17: v = self.ptr()
        elif k < 19: v = (-(1 + r.randrange(16))) & 0xffffffff
        else: v = r.randrange(4096)
        return self.safe(v)
    def dbl(self):
        r = self.r; k = r.randrange(12)
        v = [0.0, 1.0, -1.0, 0.5, 2.0, r.uniform(-4, 4), r.uniform(-1000, 1000), r.uniform(0, 1), 1e-3, 65536.0, r.uniform(-1e6, 1e6), -0.0][k]
        if FLOAT_EDGE and r.randrange(4) == 0: v = r.choice(EDGE_VALS)
        if FLOAT_EXACT: v = struct.unpack('>f', struct.pack('>f', v))[0]       # TD_FLOATEXACT=1: every double argument is exactly representable as a single (what a caller of a prototyped `float` parameter passes)
        return struct.unpack('>Q', struct.pack('>d', v))[0]
    def arena(self):
        r = self.r; out = bytearray()
        for i in range(ARENA_SIZE // 4):
            k = r.randrange(10)
            w = 0 if k < 2 else r.randrange(64) if k < 4 else self.ptr() if k < 7 else self.safe(r.getrandbits(32))
            out += struct.pack('>I', w)
        return bytes(out)
    def call(self, pc, valid=False):
        ia = []; da = []
        for ch in pc.split('-')[0]:
            if ch == 'p': ia.append(self.ptr())
            elif ch == 'i': ia.append(self.ptr() if (valid or (not ia and self.r.randrange(3) == 0)) else self.int_())
            elif ch == 'n':
                v = self.int_()
                while ARENA <= v < ARENA + ARENA_SIZE: v = self.int_()
                ia.append(v)
            elif ch == 'L': ia += [self.int_(), self.int_()]
            elif ch == 'f': da.append(self.dbl()); ia.append(self.int_())
            elif ch == 'd': da.append(self.dbl()); ia += [self.int_(), self.int_()]
        ia = (ia + [self.int_() for _ in range(8)])[:8]
        da = (da + [self.dbl() for _ in range(13)])[:13]
        sw = [(0 if (k := self.r.randrange(4)) == 0 else self.ptr() if k < 3 else self.int_()) for _ in range(16)]
        return ia, da, sw

# ---------------------------------------------------------------- comparison
def is_img_read(e): return e[0] == 'R' and isinstance(e[1], tuple)

class Tk:
    """one byte of a stored image pointer: equal to another byte when the raw bytes are equal, or when both are the same byte of the same stock-space pointer (cf. V)"""
    __slots__ = ('raw', 'canon', 'sil')
    def __init__(self, raw, canon, sil=False): self.raw = raw; self.canon = canon; self.sil = sil       # sil: the byte already held this value (a store of it changes nothing)
    def __eq__(self, o):
        if isinstance(o, Tk): return self.raw == o.raw or self.canon == o.canon
        return self.raw == o
    def __hash__(self): return 0
    def __repr__(self): return 'Tk(%r,%r)' % (self.raw, self.canon)

def segments(ev):
    """split the trace at the calls out of the image: [(call, writes, external reads)] with writes {(addr,size): [V...] in order} and reads {(addr,size): [V...]}.  Inside one segment the
    order of independent plain-memory accesses is not observable by anything but a fault, so a segment is summarised per address."""
    segs = []; w = {}; r = {}; wb = {}; rb = set(); call = None; fault = None
    def bytes_of(a, size, v, sil=()):
        # a store as byte tokens: raw bytes, or (canon, k) tokens when the value is a normalised image pointer
        iv = v.raw if isinstance(v, V) else v
        # a NaN bit pattern: the emulator's lfs/stfs pair canonicalises NaN payloads while an integer lwz/stw copy keeps them (real hardware keeps a quiet NaN's bits either way), so NaN words compare as one class
        if isinstance(iv, int) and size == 4 and 0 <= iv < 1 << 32 and (iv >> 23) & 0xff == 0xff and iv & 0x7fffff:
            return [Tk(iv.to_bytes(4, 'big')[k], ('NAN32', k), k in sil) for k in range(4)]
        if isinstance(v, V) and v.canon is not None and isinstance(iv, int) and size == 4:
            return [Tk(iv.to_bytes(4, 'big')[k], (v.canon, k)) for k in range(size)]      # same equality as V: equal raw bytes, or the same stock-space pointer
        if isinstance(iv, int) and size <= 8: return list(iv.to_bytes(size, 'big'))
        return [('?', repr(v), k) for k in range(size)]
    silent = ()
    for e in ev:
        if e[0] == 'C': segs.append((call, w, r, wb, rb)); call = e; w = {}; r = {}; wb = {}; rb = set()
        elif e[0] == 'WS': silent = e[2]
        elif e[0] == 'W':
            w.setdefault((e[1], e[2]), []).append(e[3])
            if isinstance(e[1], int):
                for k, t in enumerate(bytes_of(e[1], e[2], e[3], silent)):
                    if k not in silent or isinstance(t, Tk): wb[e[1] + k] = t
            silent = ()
        elif e[0] == 'R':
            if not is_img_read(e):
                r.setdefault((e[1], e[2]), []).append(e[3])
                if isinstance(e[1], int):
                    for k in range(e[2]): rb.add(e[1] + k)
        elif e[0] == 'WB':
            if isinstance(e[1], int):
                for k, t in enumerate(e[2]): wb[e[1] + k] = t
        elif e[0] == 'RB':
            if isinstance(e[1], int):
                for k in range(len(e[2])): rb.add(e[1] + k)
        elif e[0] == 'F': fault = e
    segs.append((call, w, r, wb, rb))
    return segs, fault

def uniq(vs):
    out = []
    for v in vs:
        if not any(v == o for o in out): out.append(v)
    return out

def collapse(vs):
    """drop consecutive repeats of the same stored value: a repeated store of an unchanged value to RAM is not observable (the userspace maps only RAM)"""
    out = []
    for v in vs:
        if not out or not (out[-1] == v): out.append(v)
    return out

def wbeq(x, y):
    """final per-byte state of two segments equal?  A byte only one image stored is equal when that store was silent (the byte already held the value)"""
    for k in set(x) | set(y):
        a = x.get(k, wbeq); b = y.get(k, wbeq)
        if a is wbeq: 
            if not (isinstance(b, Tk) and b.sil): return False
        elif b is wbeq:
            if not (isinstance(a, Tk) and a.sil): return False
        elif a != b: return False
    return True

def wdiff(x, y):
    """None if the two write maps agree, else a description of the first difference"""
    for k in sorted(set(x) | set(y), key=repr):
        if k not in y: return 'only stock writes %r = %r' % (k, x[k])
        if k not in x: return 'only rebuilt writes %r = %r' % (k, y[k])
        if collapse(x[k]) != collapse(y[k]): return 'write %r: stock %r vs rebuilt %r' % (k, x[k], y[k])
    return None

def rdiff(x, y):
    for k in sorted(set(x) | set(y), key=repr):
        if k not in y: return 'only stock reads %r' % (k,)
        if k not in x: return 'only rebuilt reads %r' % (k,)
        ux = uniq(x[k]); uy = uniq(y[k])
        if len(ux) != len(uy) or any(v not in uy for v in ux): return 'read %r: stock values %r vs rebuilt %r' % (k, ux, uy)
    return None

def ptr_value_read(ea, eb):
    """True if both traces read an image pointer (equal canonical form, different raw address) from external memory: the raw bits of such a value depend on where each image's data sits, so a test of its bits
    (a flag mask applied to a table slot that holds a pointer, i.e. an out-of-range index) cannot agree between two layouts"""
    ra = [e[3] for e in ea if e[0] == 'R' and isinstance(e[3], V) and e[3].canon is not None]
    rb = [e[3] for e in eb if e[0] == 'R' and isinstance(e[3], V) and e[3].canon is not None]
    return bool(ra) and bool(rb) and any(x.raw != y.raw for x in ra for y in rb)       # an image pointer was read in both (even if its canonical form is spelled differently, e.g. a function address vs a data cell)

def ptr_partial_read(ea, eb):
    """True if, in both traces, an image pointer is stored to external memory and a later read overlaps those four bytes without being the same word (an unaligned or narrower access to part of a pointer): the bytes read
    are bits of an address, which depend on where each image's code or data sits"""
    def hit(ev):
        ptrs = []
        for e in ev:
            if e[0] == 'W' and e[2] == 4 and isinstance(e[1], int) and isinstance(e[3], V) and e[3].canon is not None: ptrs.append(e[1])
            elif e[0] == 'R' and isinstance(e[1], int) and any(a != e[1] and a < e[1] + e[2] and e[1] < a + 4 for a in ptrs): return True
        return False
    return hit(ea) and hit(eb)

def image_data_diff(ea, eb):
    """image-own data both traces read at the same canonical address whose plain (non-pointer) values differ: [(address, stock value, rebuilt value)].  Either the access is outside the object it was meant for
    (an unchecked table index reads the neighbour, and the neighbours differ between two layouts) or the rebuilt data really differs - the caller reports the addresses so that one can tell which."""
    def reads(ev):
        d = {}
        for e in ev:
            if e[0] == 'R' and isinstance(e[1], tuple) and isinstance(e[3], V) and e[3].canon is None: d.setdefault((e[1], e[2]), e[3].raw)
        return d
    x = reads(ea); y = reads(eb)
    return [(k[0], x[k], y[k]) for k in sorted(set(x) & set(y), key=repr) if x[k] != y[k]]

def image_addr_diff(ea, eb):
    """image-own data read in one trace at a canonical address the other never reads: [(only-stock keys), (only-rebuilt keys)].  Reads of the rebuilt's own constant-pool cells (IMGR) are not counted."""
    def keys(ev): return {e[1] for e in ev if e[0] == 'R' and isinstance(e[1], tuple) and e[1][0] == 'IMG'}
    x = keys(ea); y = keys(eb)
    return sorted(x - y), sorted(y - x)

def classify_effect(ea, eb, det):
    """a return value / store differs: attribute it to a read that cannot agree between the two layouts when there is one"""
    dd = image_data_diff(ea, eb)
    if dd: return 'IMAGE_DATA_DEP', '; '.join(det) + ' | image data read differs at ' + ', '.join('%r stock %r rebuilt %r' % x for x in dd[:3])
    ox, oy = image_addr_diff(ea, eb)
    if ox and oy: return 'IMAGE_ADDR_DEP', '; '.join(det) + ' | image data read only by stock %r, only by rebuilt %r' % (ox[:2], oy[:2])
    if ptr_value_read(ea, eb) or ptr_partial_read(ea, eb): return 'PTR_VALUE_DEP', '; '.join(det)
    return 'EFFECTS', '; '.join(det)

VARARG_CALLEES = ('printf', 'sprintf', 'snprintf', 'fprintf', 'vprintf', 'vsprintf', 'vsnprintf', 'vfprintf', 'sscanf', 'scanf')

def ent_match(x, y):
    """two recorded argument sets agree: for every argument index recorded in both, the words agree over the shorter of the two runs (the words after the end of the buffer belong to a neighbouring local whose place is the compiler's choice; an argument register that holds a stale frame pointer in only one image is not an argument)"""
    dy = dict(y)
    for i, ws in x:
        if i in dy:
            n = min(len(ws), len(dy[i]))
            if ws[:n] != dy[i][:n]: return False
    return True

def ent_diff(ea, eb):
    """per callee name present in both images' run with the same number of calls: every stock argument record has a matching rebuilt record (a callee one image inlined, or a different number of calls, is not comparable and is skipped)"""
    if not ea or not eb: return ''
    na = {}; nb = {}
    for n, it in ea: na.setdefault(n, []).append(it)
    for n, it in eb: nb.setdefault(n, []).append(it)
    for n in sorted(set(na) & set(nb)):
        if len(na[n]) != len(nb[n]) or n.lstrip('_').startswith(VARARG_CALLEES): continue       # a varargs callee's pointer argument is the register save area: the words after the real arguments are stale volatile registers (r9/r10), not values the function wrote
        rest = list(nb[n])
        for it in na[n]:
            j = next((j for j, o in enumerate(rest) if ent_match(it, o)), None)
            if j is None: return '%s: stock record %r has no matching rebuilt record (rebuilt %r)' % (n, it, rest[0] if rest else None)
            rest.pop(j)
    return ''

def compare(a, b, ret_kind):
    v, det = _compare(a, b, ret_kind)
    if ENTRYARGS and v in ('IDENTICAL', 'REORDERED', 'READ_SET', 'FAULT_SITE', 'FAULT_PARTIAL'):
        d = ent_diff(a[2].get('ent'), b[2].get('ent'))
        if d: return 'EFFECTS', 'callee argument record differs: ' + d[:400]
    return v, det

def _compare(a, b, ret_kind):
    """a, b = (status, ev, regs, cov).  Returns (verdict, detail), strongest first:
       IDENTICAL       the full ordered trace (reads, writes, calls, fault) and the return / callee-saved registers are equal
       REORDERED       same calls out (order + arguments), same multiset of writes and same set of external reads between consecutive calls, same fault outcome, same return value;
                       only the order of the accesses inside a call-to-call segment (or reads of the image's own memory) differs
       READ_SET        as REORDERED but one image reads external memory the other does not (a dead / extra / hoisted load)
       FAULT_SITE      both end in the same kind of fault on an invalid address, at different addresses (an instruction-order effect on an input that crashes either way)
       FAULT_MISMATCH  one image returns where the other faults on the same input (error handling or a hoisted load differs)
       EFFECTS         a write, a call out, a return value differs"""
    sa, ea, ra, ca = a; sb, eb, rb, cb = b
    # `vcb` (a virtual method / callback slot the input memory points at) has no known arity or argument kinds: the call-out records r3..r10, but r4.. may be leftover registers of the caller or the GPR shadow words of
    # floating-point arguments (the rebuilt's K&R-style call passes a double in f1 AND r4/r5, the stock leaves r4/r5 alone).  Only the first VCB_ARGS words are compared (default 1: the receiver / context);
    # the 59 L-prefixed GLDriver functions were also run with 6 (r3..r8): 25 rows differed at a vcb call only in r9 / r10; the 26th (LoopHeader__verify) differs in r5.. at a call that sets only r3 (rebuilt `mr r3,r31 ; bctrl` at 0xfac60): residue.
    nv_ = int(os.environ.get('TD_VCB_ARGS', '1'))
    cut = lambda ev: [(e[0], e[1], e[2][:nv_]) + tuple(e[3:]) if e[0] == 'C' and e[1] == 'vcb' else e for e in ev]
    ea, eb = cut(ea), cut(eb)
    if sa == 'TIMEOUT' or sb == 'TIMEOUT': return 'TIMEOUT', ''
    if sa == 'UCERR' and sb == 'UCERR':
        fx = lambda ev: [e for e in ev if e[0] == 'F']
        if fx(ea) == fx(eb) and fx(ea) and ea == eb: return 'IDENTICAL', 'full ordered trace equal; both end in the same unemulated exception at the same pc (wild branch into non-code)'
    if sa == 'UCERR' or sb == 'UCERR': return 'EMUERR', 'stock %s %r | rebuilt %s %r' % (sa, [e for e in ea if e[0] == 'F'], sb, [e for e in eb if e[0] == 'F'])
    if sa != sb:
        ox, oy = image_addr_diff(ea, eb)
        if ox and oy: return 'IMAGE_ADDR_DEP', 'stock %s | rebuilt %s | image data read only by stock %r, only by rebuilt %r' % (sa, sb, ox[:2], oy[:2])
        fe = next((e for e in (ea if sa == 'FAULT' else eb) if e[0] == 'F'), None)
        if fe and isinstance(fe[2], int) and {sa, sb} == {'FAULT', 'RET'} and 'S' in _G:
            lo_end, hi_end = sorted((_G['S'].end, _G['R'].end))
            if lo_end + SLIDE <= fe[2] < hi_end + SLIDE:        # the same wild address (garbage input) is outside the smaller image and inside the larger one
                return 'PTR_VALUE_DEP', 'wild %s at %#x (from unvalidated input) is unmapped in the smaller image (ends %#x) but inside the larger (ends %#x): %s' % (fe[1], fe[2], lo_end + SLIDE, hi_end + SLIDE, 'stock faults, rebuilt completes' if sa == 'FAULT' else 'rebuilt faults, stock completes')
        if ptr_partial_read(ea, eb): return 'PTR_VALUE_DEP', 'stock %s %r | rebuilt %s %r, after reading part of a stored image pointer (the accessed address is built from those address bits)' % (sa, [e[1:] for e in ea if e[0] == 'F'], sb, [e[1:] for e in eb if e[0] == 'F'])
        return 'FAULT_MISMATCH', 'stock %s %r | rebuilt %s %r' % (sa, [e[1:] for e in ea if e[0] == 'F'], sb, [e[1:] for e in eb if e[0] == 'F'])
    det = []; ret_ok = True
    if sa == 'RET':
        keys = ['r1', 'nv', 'fnv'] + {'i': ['r3'], 'd': ['f1'], 'L': ['r3', 'r4']}.get(ret_kind, [])
        for k in keys:
            if ra[k] != rb[k]: ret_ok = False; det.append('reg %s: %r vs %r' % (k, ra[k], rb[k]))
    ext = lambda ev: [e for e in ev if not (e[0] == 'R' and isinstance(e[1], tuple))]        # reads of the image's own constants / pointer cells are not external behaviour
    if ret_ok and ext(ea) == ext(eb) and ea != eb: return 'IDENTICAL', 'external trace equal; own-image constant reads differ'
    if ea == eb and ret_ok:
        if ret_kind == 'v' and sa == 'RET' and (ra['r3'] != rb['r3'] or ra['f1'] != rb['f1']): return 'IDENTICAL', 'void: r3/f1 leftovers differ (%x/%x)' % (ra['r3'], rb['r3'])
        return 'IDENTICAL', ''
    sga, fa = segments(ea); sgb, fb = segments(eb)
    if sa == 'FAULT' and fa != fb:
        if fa and fb and fa[1] == fb[1]: return 'FAULT_SITE', 'stock %r vs rebuilt %r' % (fa[1:], fb[1:])
        noeff = lambda ev: not any(e[0] in ('W', 'WB', 'C') for e in ev)
        if fa and fb and noeff(ea) and noeff(eb):      # both crash before any store or call completed: the same observable outcome, only the first invalid access (kind/address) differs
            return 'FAULT_SITE', 'stock %r vs rebuilt %r (different access kind; no store or call completed in either image)' % (fa[1:], fb[1:])
        eff = lambda ev: [e for e in ev if e[0] in ('W', 'WB', 'C')]
        if fa and fb and eff(ea) == eff(eb):       # both crash after the same ordered stores and calls (arguments included): only the first invalid access (kind/address) differs
            return 'FAULT_SITE', 'stock %r vs rebuilt %r (identical ordered stores%s before the fault)' % (fa[1:], fb[1:], ' and calls' if any(e[0] == 'C' for e in ea) else ', no call in either image')
        if ptr_partial_read(ea, eb): return 'PTR_VALUE_DEP', 'both fault, but at different places after reading part of a stored image pointer: stock %r vs rebuilt %r' % (fa, fb)
        return 'FAULT_MISMATCH', 'stock %r vs rebuilt %r' % (fa, fb)
    if len(sga) != len(sgb) or any(x[0] != y[0] for x, y in zip(sga, sgb)):
        i = next((i for i, (x, y) in enumerate(zip(sga, sgb)) if x[0] != y[0]), min(len(sga), len(sgb)))
        det.append('calls differ at #%d: stock %r vs rebuilt %r' % (i, sga[i][0] if i < len(sga) else None, sgb[i][0] if i < len(sgb) else None)); return 'EFFECTS', '; '.join(det)
    partial = False
    for i, (x, y) in enumerate(zip(sga, sgb)):
        d = wdiff(x[1], y[1])
        if d and not wbeq(x[3], y[3]):
            if sa == 'FAULT' and i == len(sga) - 1 and fa == fb: partial = d; continue       # the segment cut short by the same fault: which stores had happened before it differs (instruction order)
            if any(isinstance(k, int) and RING <= k < RING + RING_SIZE and x[3].get(k) != y[3].get(k) for k in set(x[3]) | set(y[3])): det.append('segment %d: command-ring contents differ: %s' % (i, d)); return 'HW_STREAM', '; '.join(det)
            det.append('segment %d: %s' % (i, d)); return classify_effect(ea, eb, det)
    if not ret_ok: return classify_effect(ea, eb, det)
    if partial: return 'FAULT_PARTIAL', 'same fault %r; stores completed before it differ: %s' % (fa[1:] if fa else None, partial)
    for i, (x, y) in enumerate(zip(sga, sgb)):
        d = rdiff(x[2], y[2])
        if d and x[4] != y[4]:
            if sa == 'FAULT' and i == len(sga) - 1 and fa == fb: partial = partial or ('reads: ' + d); continue
            return 'READ_SET', 'segment %d: %s' % (i, d)
    if partial: return 'FAULT_PARTIAL', 'same fault %r; accesses completed before it differ: %s' % (fa[1:] if fa else None, partial)
    return 'REORDERED', 'same writes/reads per segment; order differs'

def load_row(ledger, name):
    for l in open(ledger):
        p = l.rstrip('\n').split('\t')
        if len(p) >= 7 and p[0].isdigit() and p[1] == name:
            return dict(id=int(p[0]), name=p[1], stock=int(p[2], 16) - (_G['S'].bal if 'S' in _G else 0), reb=int(p[3], 16) - (_G['R'].bal if 'R' in _G else 0), size=int(p[4]), pc=p[5], rc=p[6])
    raise SystemExit('row %s not in %s' % (name, ledger))

def same_run(x, y):
    """is run x indistinguishable from run y (same status, events, return registers)?  Used to detect a dependence on uninitialised stack: the two stack fills must give the same run."""
    if x[0] != y[0] or x[1] != y[1]: return False
    if x[0] == 'RET': return all(x[2][k] == y[2][k] for k in ('r1', 'nv', 'fnv', 'r3', 'f1'))
    return True

def single_exact(v):
    """a double bit pattern rounded to the nearest single (kept as double bits): what an ABI-conforming caller leaves in an FPR that carries a C float"""
    d = struct.unpack('>d', v.to_bytes(8, 'big'))[0]
    try: f = struct.unpack('>f', struct.pack('>f', d))[0]
    except OverflowError: f = math.copysign(math.inf, d)
    return int.from_bytes(struct.pack('>d', f), 'big')

SINGLE_FP = re.compile(r'^_?gl[A-Za-z0-9]*[0-9]?f[v]?_[A-Za-z]+$|^_?gl[A-Za-z0-9]*f[v]?$')   # GL entry points taking C floats (glRotatef_Exec, glMaterialfv ...): stock uses single-precision ops on them

def eval_input(row, ia, da, sw, arena, sims, ctl, full=False):
    """one input -> (verdict, detail, stock run A, rebuilt run A).  The cheap path runs fill A only; a run that is not clean is re-run under the second fill and the slide control to classify it
    (UNINIT_* / LAYOUT_DEP).  full=True always runs the controls."""
    (ssA, srA), (ssB, srB) = sims['A'], sims['B']
    if SINGLE_FP.match(row['name']): da = [single_exact(v) for v in da]       # a float parameter never holds a non-single value in an ABI-conforming call: such inputs are out of contract (the corpus declares the params double; rebuilt rounds at call boundaries, stock does not)
    aA = ssA.run(row['stock'], ia, da, sw, arena); bA = srA.run(row['reb'], ia, da, sw, arena)
    v, det = compare(aA, bA, row['rc'])
    if v == 'IDENTICAL' and not full: return v, det, aA, bA
    aB = ssB.run(row['stock'], ia, da, sw, arena); bB = srB.run(row['reb'], ia, da, sw, arena)
    us = not same_run(aA, aB); ur = not same_run(bA, bB)
    cA = ctl.run(row['stock'], ia, da, sw, arena) if ctl else None
    if aA[0] in ('TIMEOUT', 'UCERR') or bA[0] in ('TIMEOUT', 'UCERR'): v, det = compare(aA, bA, row['rc'])
    elif cA is not None and not same_run(aA, cA): v, det = 'LAYOUT_DEP', 'the stock itself behaves differently at a second slide (%s vs %s)' % (aA[0], cA[0])
    elif us and ur: v, det = 'UNINIT_BOTH', ''
    elif ur: v, det = 'UNINIT_REBUILT', 'rebuilt differs between stack fills: ' + str(compare(bA, bB, row['rc'])[1])[:200]
    elif us: v, det = 'UNINIT_STOCK', ''
    return v, det, aA, bA

def run_row(row, trials, S, R, sims, keep=False, ctl=None):
    """per trial: stock and rebuilt under two stack fills (A = 0, B = 0x5a5a5a5a) with identical inputs.  A run that differs between the fills read uninitialised stack:
         UNINIT_REBUILT   only the rebuilt does  -> a rebuilt defect (corpus reads a local nothing wrote)
         UNINIT_STOCK     only the stock does    -> a stock property; the trial says nothing about the rebuilt
         UNINIT_BOTH      both do                -> not comparable
       otherwise the verdict of compare()."""
    res = {}; first = {}; stat = {}; cov = [set(), set()]
    for t in range(trials):
        g = Gen(row['id'] * 100003 + t)
        arena = g.arena(); ia, da, sw = g.call(row['pc'], valid=(t % 2 == 1)); arena = prime_ring(arena, ia, row['pc'])
        v, det, aA, bA = eval_input(row, ia, da, sw, arena, sims, ctl, full=True)
        stat[(aA[0], bA[0])] = stat.get((aA[0], bA[0]), 0) + 1
        res.setdefault(v, []).append(('A', t)); first.setdefault(v, ('A', t, det, aA if keep else (aA[0], aA[1][:40], aA[2], None), bA if keep else (bA[0], bA[1][:40], bA[2], None)))
        cov[0] |= aA[3]; cov[1] |= bA[3]
    inf = lambda c, lo, n: len([x for x in c if lo <= x < lo + n])
    return res, first, stat, (inf(cov[0], row['stock'], row['size']), inf(cov[1], row['reb'], row['size']))

# ---------------------------------------------------------------- coverage-guided inputs
INTERESTING = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16, 0x1f, 0x20, 0x40, 0x7f, 0x80, 0xff, 0x100, 0x1ff, 0x400, 0xffff, 0x10000, 0x7fffffff, 0x80000000, 0xffffffff, 0xfffffffe]

def mutate(rng, ia, da, sw, arena, reads):
    """a mutated copy of an input: set words the function READ (so a compare / mask / switch on them can go the other way), set arguments, zero a window around a pointer argument"""
    ia = list(ia); da = list(da); sw = list(sw); a = bytearray(arena)
    def pool():
        k = rng.randrange(8)
        if k < 5: return rng.choice(INTERESTING)
        if k == 5: return ARENA + 0x1000 + (rng.randrange(ARENA_SIZE - 0x3000) & ~3)
        if k == 6: return rng.getrandbits(32)
        return 1 << rng.randrange(32)
    for _ in range(rng.choice((1, 1, 2, 3))):
        r = rng.randrange(100)
        if r < 55 and reads:
            addr, size = rng.choice(reads); o = (addr - ARENA) & ~3
            if 0 <= o <= len(a) - 4:
                v = pool()
                if size == 1: v = (v & 0xff) << (8 * (3 - ((addr - ARENA) & 3))) | (int.from_bytes(a[o:o+4], 'big') & ~(0xff << (8 * (3 - ((addr - ARENA) & 3)))) & 0xffffffff)
                elif size == 2: sh = 8 * (2 - ((addr - ARENA) & 2)); v = (v & 0xffff) << sh | (int.from_bytes(a[o:o+4], 'big') & ~(0xffff << sh) & 0xffffffff)
                a[o:o+4] = struct.pack('>I', v & 0xffffffff)
        elif r < 75: i = rng.randrange(8); ia[i] = pool()
        elif r < 85:
            p = ia[rng.randrange(8)] - ARENA
            if 0 <= p <= len(a) - 0x200: n = rng.choice((0x40, 0x100, 0x200)); a[p:p+n] = bytes(n)
        elif r < 92:
            v = rng.choice((0.0, 1.0, -1.0, 0.5, 255.0, 1e30, -1e30, float('nan'), float('inf')) + (EDGE_VALS if FLOAT_EDGE else ()))
            if FLOAT_EXACT: v = struct.unpack('>f', struct.pack('>f', v))[0]
            da[rng.randrange(len(da))] = struct.unpack('>Q', struct.pack('>d', v))[0]
        else: sw[rng.randrange(16)] = pool()
    return ia, da, sw, bytes(a)

def repair_step(sim, ia, sw, arena, rng):
    """pointer repair (lazy object-graph materialisation).  The run just made on `sim` ended in a fault at an address that is unmapped or in the null page: the cause is almost always a pointer
    the function loaded from the input memory (or took from an argument / stack word) that the random input did not make valid.  Find that source (the latest 4-byte read from the arena whose value is
    within 0x8000 below the faulting address, else an argument / stack word of the same kind), point it at a fresh stretch of arena (the same distance below, so the access lands inside it) and return
    the patched input; the sub-object's content is the arena's existing random words, so deeper pointers are repaired by the next step.  None when no source is found (the fault is a computed wild address)."""
    if sim.status == 'FAULT' and sim.ev and sim.ev[-1][:2] == ('F', 'wild') and isinstance(sim.ev[-1][2], int) and ARENA <= sim.ev[-1][2] < ARENA + ARENA_SIZE:
        # a call / branch through a function pointer the input memory holds (a vtable slot): point that slot at the `vcb` call-out (a recorded call with a deterministic result, the same in both images)
        tgt = sim.ev[-1][2]
        for e in reversed(sim.ev):
            if e[0] == 'R' and e[2] == 4 and isinstance(e[1], int) and ARENA <= e[1] < ARENA + ARENA_SIZE and e[3].raw == tgt and not e[1] & 3:
                a = bytearray(arena); a[e[1] - ARENA:e[1] - ARENA + 4] = struct.pack('>I', CALLOUT + 16 * sim.ids['vcb']); return ia, sw, bytes(a)
        return None
    fa = sim.fa
    if fa is None or sim.status != 'FAULT': return None
    ptr = lambda: ARENA + 0x1000 + (rng.randrange(ARENA_SIZE - 0x3000) & ~0xf) + 0x100
    for e in reversed(sim.ev):
        if e[0] != 'R' or e[2] != 4 or not isinstance(e[1], int) or not (ARENA <= e[1] < ARENA + ARENA_SIZE): continue
        v = e[3].raw
        if not isinstance(v, int) or not (0 <= fa - v < 0x8000 or 0 <= v - fa < 0x1000 and fa < NULLPAGE): continue
        o = e[1] - ARENA
        if o & 3: continue
        a = bytearray(arena); a[o:o + 4] = struct.pack('>I', (ptr() - (fa - v)) & 0xffffffff)
        return ia, sw, bytes(a)
    for i, v in enumerate(ia):
        if 0 <= fa - v < 0x8000 and not (ARENA <= v < ARENA + ARENA_SIZE):
            ia = list(ia); ia[i] = ptr() - (fa - v); return ia, sw, arena
    for i, v in enumerate(sw):
        if 0 <= fa - v < 0x8000 and not (ARENA <= v < ARENA + ARENA_SIZE):
            sw = list(sw); sw[i] = ptr() - (fa - v); return ia, sw, arena
    return None

def fuzz_row(row, budget, S, R, sims, ctl, seed_trials=4):
    """coverage-guided exploration: start from `seed_trials` generated inputs, keep every input that reaches an instruction (in either image) nothing before reached, derive new inputs from kept ones by mutating the
    words the function read.  Every execution is compared.  Returns (verdict counts, first example per verdict, end-state counts, (stock cov, rebuilt cov), executions)."""
    import random
    rng = random.Random(row['id'] * 7919 + 13)
    res = {}; first = {}; stat = {}; seen = [set(), set()]; corpus = []
    def execute(ia, da, sw, arena, depth=0):
        v, det, aA, bA = eval_input(row, ia, da, sw, arena, sims, ctl)
        stat[(aA[0], bA[0])] = stat.get((aA[0], bA[0]), 0) + 1
        res.setdefault(v, []).append(1)
        if v not in first:
            first[v] = ('F', len(first), det, (aA[0], aA[1][:40], aA[2], None), (bA[0], bA[1][:40], bA[2], None))
            if _G.get('repro') and v not in ('IDENTICAL', 'REORDERED', 'READ_SET', 'FAULT_SITE', 'LAYOUT_DEP', 'UNINIT_STOCK', 'UNINIT_BOTH'):
                import pickle; os.makedirs(_G['repro'], exist_ok=True)
                pickle.dump((ia, da, sw, arena), open(os.path.join(_G['repro'], '%s.%s.pkl' % (row['name'], v)), 'wb'))
        new = (len(aA[3] - seen[0]) > 0) or (len(bA[3] - seen[1]) > 0)
        seen[0] |= aA[3]; seen[1] |= bA[3]
        reads = [(e[1], e[2]) for e in aA[1] if e[0] == 'R' and isinstance(e[1], int) and ARENA <= e[1] < ARENA + ARENA_SIZE]
        if _G.get('repair') and depth < _G['repair'] and aA[0] == 'FAULT' and bA[0] == 'FAULT':
            rp = repair_step(sims['A'][0], ia, sw, arena, rng)
            if rp:
                n2, r2, ia2, sw2, ar2 = execute(rp[0], da, rp[1], rp[2], depth + 1)
                if n2: corpus.append((ia2, da, sw2, ar2, r2))
                new = new or n2
        return new, reads, ia, sw, arena
    for t in range(seed_trials):
        g = Gen(row['id'] * 100003 + t); arena = g.arena(); ia, da, sw = g.call(row['pc'], valid=(t % 2 == 1)); arena = prime_ring(arena, ia, row['pc'])
        new, reads = execute(ia, da, sw, arena)[:2]; corpus.append((ia, da, sw, arena, reads))
    for _ in range(max(0, budget - seed_trials)):
        ia, da, sw, arena, reads = corpus[rng.randrange(len(corpus))]
        ia2, da2, sw2, arena2 = mutate(rng, ia, da, sw, arena, reads); arena2 = prime_ring(arena2, ia2, row['pc'])
        new, reads2 = execute(ia2, da2, sw2, arena2)[:2]
        if new: corpus.append((ia2, da2, sw2, arena2, reads2))
    inf = lambda c, lo, n: len([x for x in c if lo <= x < lo + n])
    return res, first, stat, (inf(seen[0], row['stock'], row['size']), inf(seen[1], row['reb'], row['size']))

_G = {}
def _init(stock, reb, symmap, nm, ledger=None, funcs=None, nargs=None, fuzz=0, repro=None):
    S = Img(stock, symfile=symmap); R = Img(reb, nmfile=nm); ids, names = callout_ids([S, R]); S.is_stock = True
    ts = {n: a for a, n in S.syms}
    for r in (read_ledger(ledger, S.bal, R.bal) if ledger else []): ts.setdefault(r['name'], r['stock'])
    for l in (open(funcs) if funcs else []):                       # the corpus ledger: every function of the stock, 'addr<TAB>size<TAB>name<TAB>part<TAB>status'
        p = l.rstrip('\n').split('\t')
        if len(p) >= 3 and p[0].startswith('0x'): ts.setdefault(p[2], int(p[0], 16) - S.bal); ts.setdefault('_' + p[2], int(p[0], 16) - S.bal)
    class _TS(dict):
        def get(self, k, d=None):
            v = dict.get(self, k)
            if v is not None: return v
            m = re.search(r'_([0-9a-f]{5,8})$', k)
            return (int(m.group(1), 16) - S.bal) if m else d      # a name that carries its stock address (e.g. _read_sleb128_97c1c44c) holds the absolute address
    # one-instruction wrapper entries (`b target`) that the stock names only by an alias four bytes before the target (e.g. _glCallList_Exec stock 0x43e18 = `b 0x43e1c`): the stock has no symbol for them, so
    # map the rebuilt wrapper to (stock address of its target) - 4 when the stock holds a `b .+4` there
    def _word(img, a):
        for nm_, vm, vs, data in img.segs:
            if vm <= a < vm + len(data) - 3: return struct.unpack('>I', data[a - vm:a - vm + 4])[0]
    _named = set(ts.values()); _stock_branches = {}
    for nm_, vm, vs, data in S.segs:
        if nm_ == '__TEXT':
            for lo, hi in S.text:
                for a in range(lo, min(hi, vm + len(data)) - 3, 4):
                    w = struct.unpack('>I', data[a - vm:a - vm + 4])[0]
                    if w >> 26 == 18 and not w & 3: _stock_branches.setdefault((a + (((w & 0x3fffffc) ^ 0x2000000) - 0x2000000)) & 0xffffffff, []).append(a)
    for ra, rn in R.syms:
        if rn in ts or rn.startswith(('DAT_', 'PTR_', 's_', 'lbl_', '_raw_entry')): continue
        w = _word(R, ra)
        if w is None or w >> 26 != 18 or w & 3: continue
        tgt = (ra + (((w & 0x3fffffc) ^ 0x2000000) - 0x2000000)) & 0xffffffff
        tn = R.sym(tgt)
        if tn[1] != 0 or tn[0] not in ts: continue
        sw = _word(S, ts[tn[0]] - 4)
        if sw is not None and sw == 0x48000004: ts[rn] = ts[tn[0]] - 4; continue
        # otherwise: the one unnamed stock `b <stock address of the target>` that is not a named function entry
        cand = [a for a in _stock_branches.get(ts[tn[0]], []) if a not in _named]
        if len(cand) == 1: ts[rn] = cand[0]
    R.to_stock = _TS(ts); R.stock_secs = {(g, sn): (a, sz) for (g, sn, a, sz, f, r1) in S.secs}
    if nargs:
        Sim.nargs = {}
        for l in open(nargs):
            p = l.rstrip('\n').split('\t')
            if len(p) >= 2 and p[1].isdigit(): Sim.nargs[p[0].lstrip('_')] = int(p[1])
    _sims = {f: (Sim(S, ids, names, fv), Sim(R, ids, names, fv)) for f, fv in (('A', 0), ('B', 0x5a5a5a5a))}
    if ENTRYARGS and ledger:
        _rows = [r for r in read_ledger(ledger, S.bal, R.bal) if 'stub' not in r['name'].lower()]       # a library stub's argument is whatever the real callee would read: only calls into image code are compared
        for ss, sr in _sims.values():
            ss.entries = {r['stock']: r['name'] for r in _rows}; sr.entries = {r['reb']: r['name'] for r in _rows}
    _G.update(repair=int(os.environ.get('TD_REPAIR', '0')), fuzz=fuzz, repro=repro, S=S, R=R, sims=_sims, ctl=Sim(S, ids, names, 0, slide=SLIDE2))
def _work(job):
    row, trials = job
    try:
        if _G.get('fuzz'): res, first, stat, cov = fuzz_row(row, _G['fuzz'], _G['S'], _G['R'], _G['sims'], _G.get('ctl'))
        else: res, first, stat, cov = run_row(row, trials, _G['S'], _G['R'], _G['sims'], ctl=_G.get('ctl'))
    except Exception as e: return row, None, 'EXC %r' % (e,), None, None
    return row, res, first, stat, cov

def read_ledger(ledger, sb=0, rb=0):
    rows = []
    for l in open(ledger):
        p = l.rstrip('\n').split('\t')
        if len(p) >= 7 and p[0].isdigit(): rows.append(dict(id=int(p[0]), name=p[1], stock=int(p[2], 16) - sb, reb=int(p[3], 16) - rb, size=int(p[4]), pc=p[5], rc=p[6]))
    return rows

def census(stock, reb, ledger, trials, procs, out, symmap, nm, names=None, funcs=None, nargs=None, fuzz=0, repro=None):
    import multiprocessing as mp
    rows = read_ledger(ledger, macho(stock)[6], macho(reb)[6])
    if names: rows = [r for r in rows if r['name'] in names]
    with mp.Pool(procs, initializer=_init, initargs=(stock, reb, symmap, nm, ledger, funcs, nargs, fuzz, repro)) as pool, open(out, 'w') as f:
        f.write('#id\tname\trc\tpc\tsize\tstock_cov\treb_cov\truns\tIDENTICAL\tREORDERED\tREAD_SET\tFAULT_SITE\tFAULT_MISMATCH\tEFFECTS\tEMUERR\tTIMEOUT\tUNINIT_REBUILT\tUNINIT_OTHER\tend_states\tfirst_nonidentical\tLAYOUT_DEP\tPTR_VALUE_DEP\tIMAGE_DATA_DEP\n')
        for row, res, first, stat, cov in pool.imap_unordered(_work, [(r, trials) for r in rows], chunksize=1):
            if res is None: f.write('%d\t%s\t%s\t%s\t%d\t-\t-\t0\t\t\t\t\t\t\t\t\t\t\t\t%s\n' % (row['id'], row['name'], row['rc'], row['pc'], row['size'], first)); f.flush(); continue
            n = sum(len(v) for v in res.values()); c = lambda k: len(res.get(k, []))
            worst = next((k for k in ('UNINIT_REBUILT', 'HW_STREAM', 'EFFECTS', 'IMAGE_ADDR_DEP', 'IMAGE_DATA_DEP', 'PTR_VALUE_DEP', 'FAULT_MISMATCH', 'FAULT_PARTIAL', 'READ_SET', 'FAULT_SITE', 'REORDERED', 'EMUERR') if k in res), '')
            f.write('%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%d\t%d\n' % (row['id'], row['name'], row['rc'], row['pc'], row['size'], cov[0], cov[1], n, c('IDENTICAL'), c('REORDERED'), c('READ_SET'), c('FAULT_SITE') + c('FAULT_PARTIAL'), c('FAULT_MISMATCH'), c('EFFECTS') + c('HW_STREAM'), c('EMUERR'), c('TIMEOUT'), c('UNINIT_REBUILT'), c('UNINIT_STOCK') + c('UNINIT_BOTH'),
                ','.join('%s/%s:%d' % (k[0], k[1], v) for k, v in sorted(stat.items())), ('%s: %s' % (worst, first[worst][2][:300])) if worst else '', c('LAYOUT_DEP'), c('PTR_VALUE_DEP'), c('IMAGE_DATA_DEP') + c('IMAGE_ADDR_DEP')))
            f.flush()

def main(argv):
    opts = {'--symmap': None, '--nm': None, '--procs': '8', '--out': None, '--names': None, '--funcs': None, '--nargs': None, '--fuzz': '0', '--repro': None}; pos = []; verbose = False; i = 0
    while i < len(argv):
        if argv[i] in opts: opts[argv[i]] = argv[i + 1]; i += 2
        elif argv[i] == '-v': verbose = True; i += 1
        else: pos.append(argv[i]); i += 1
    if pos[3] == '--all' or opts['--out']:
        stock, reb, ledger = pos[:3]; trials = int(pos[4]) if len(pos) > 4 else 10
        census(stock, reb, ledger, trials, int(opts['--procs']), opts['--out'], opts['--symmap'], opts['--nm'], set(opts['--names'].split(',')) if opts['--names'] else None, opts['--funcs'], opts['--nargs'], int(opts['--fuzz']), opts['--repro']); return
    stock, reb, ledger, name = pos[:4]; trials = int(pos[4]) if len(pos) > 4 else 50
    _init(stock, reb, opts['--symmap'], opts['--nm'], ledger, opts['--funcs'], opts['--nargs'], int(opts['--fuzz']), opts['--repro']); row = load_row(ledger, name)
    res, first, stat, cov = fuzz_row(row, int(opts['--fuzz']), _G['S'], _G['R'], _G['sims'], _G['ctl']) if int(opts['--fuzz']) else run_row(row, trials, _G['S'], _G['R'], _G['sims'], keep=True, ctl=_G['ctl'])
    n = sum(len(x) for x in res.values())
    print('%s (rc %s, pc %s): %d runs: %s; function instructions covered: stock %d rebuilt %d of ~%d' % (name, row['rc'], row['pc'], n, ', '.join('%s %d' % (k, len(v)) for k, v in sorted(res.items())), cov[0], cov[1], row['size'] // 4))
    print('  end states (stock,rebuilt): ' + ', '.join('%s/%s %d' % (k[0], k[1], v) for k, v in sorted(stat.items())))
    for k, (fn, t, det, a, b) in first.items():
        if k == 'IDENTICAL' and not verbose: continue
        print('  first %s: fill %s trial %d  %s' % (k, fn, t, det))
        print('     stock status %s, %d events | rebuilt status %s, %d events' % (a[0], len(a[1]), b[0], len(b[1])))
        if verbose:
            for x in a[1][:40]: print('     S', x)
            for x in b[1][:40]: print('     R', x)

if __name__ == '__main__': main(sys.argv[1:])
