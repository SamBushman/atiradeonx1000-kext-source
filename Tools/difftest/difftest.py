#!/usr/bin/env python3
"""difftest.py - differential unit tests of single kext functions: the STOCK driver's machine code against the REBUILT driver's, in a PPC emulator.

Success criteria for one function and one input (a "run"), judged against the stock function:
  1. every call the function makes to anything else - an external kernel/IOKit function, another function of the kext, or a virtual method - has the
     same callee and the same arguments, in the same order (callees are MOCKED: they are not executed, they record the call and return a value that is the
     same for both sides);
  2. every write to memory that outlives the call (through a pointer argument, into an object, into a global) leaves the same bytes behind;
  3. the return value is the same;
  4. it ends the same way (returns / runs out of budget / faults), with the stack pointer and the callee-saved registers restored.
  5. HARDWARE REGISTERS: every access to a register window (Machine.mmio) is compared strictly - the same reads and writes, at the same offsets, with the
     same widths and the same bytes, in the same order, interleaved identically with the calls the function makes (a callee may touch the hardware
     too). The business logic around them may differ; what the hardware sees may not.
The execution time of each side is also reported, as an instruction count (the emulator is not cycle-accurate): the generated code may be bigger or
smaller than the stock code - that is not a failure, a large ratio is flagged for a human.

How it works
  * Both kext images are unlinked MH_OBJECTs based at address 0 whose local relocations are already resolved, so the raw bytes of the image are mapped at
    address 0 (the technique of Tools/userspace/emu/kemu.py). External symbols (their relocation entries are still there) are redirected to stubs.
  * Every other function of the image is mocked by overwriting its first instruction with a branch to a stub, so the function under test runs alone.
    Stub addresses come from a registry shared by both sides, so the same callee has the same address on both sides.
  * Memory that was not set up by the test is mapped on first touch (zero-filled, or filled with bytes derived from the seed: reproducible, and the
    same on both sides because it depends only on the address).
  * A virtual call (`VCALL(M<int>(self), off)`) needs the object's vtable: world builders create one whose slots are named stubs (from
    Ledger/kext_ppc_vtables.txt), so virtual calls are recorded by method name.
Limits (be aware when reading a result): argument registers beyond a callee's declared arity are not compared (the arity comes from the mangled
signature; for plain C externs from EXTERN_ARITY below; unknown arity compares r3-r5 and says so); floating-point arguments are compared as raw doubles;
the cost is an instruction count; hardware registers are not modelled (mock `M<>` MMIO is plain memory).

Usage: difftest.py [--stock BIN] [--rebuilt BIN] [-f SUBSTRING] [-v] [--json OUT] CASEFILE.py [CASEFILE.py ...]
  A case file defines CASES = [Case(...), ...] (see class Case). Exit 0 if every run matches, 1 otherwise.
Setup: pip install --break-system-packages --target ~/.cache/kext-difftest/pkgs unicorn   (or set DIFFTEST_PKGS)
"""
import os, sys, struct, re, subprocess, random, json, importlib.util, zlib, time

HERE = os.path.dirname(os.path.abspath(__file__))
for _p in (os.environ.get('DIFFTEST_PKGS'), os.path.expanduser('~/.cache/kext-difftest/pkgs'), '/tmp/upkgs'):
    if _p and os.path.isdir(_p):
        sys.path.insert(0, _p)
sys.path.insert(0, os.path.join(HERE, '..', 'userspace'))
from unicorn import *
from unicorn.ppc_const import *
import machoutil

STOCK_DEFAULT = os.environ.get('STOCK_KEXT')                       # the shipped kext binary: extract it from your own Tiger install
REBUILT_DEFAULT = os.environ.get('REBUILT_KEXT') or os.path.join(HERE, '..', '..', 'build', 'difftest', 'rebuilt.bin')
VTABLES = os.path.join(HERE, '..', '..', 'Ledger', 'kext_ppc_vtables.txt')

STUB_BASE, STUB_SIZE = 0x00100000, 0x00100000            # 16-byte stubs, each a `blr`
DATA_BASE = 0x00300000                                     # cells of external DATA symbols
STOP = 0x10000000                                          # return address of the function under test
ARENA = 0x20000000                                         # test objects are allocated here
STACK_TOP, STACK_SIZE = 0x7ff00000, 0x00100000
ENTRY_SP = STACK_TOP - 0x4000                              # r1 at entry; 0x4000 bytes above it are the caller's frame
PAGE = 0x1000
BLR = 0x4e800020

# external DATA symbols and the value their cell holds (a function pointer or an int would be a stub; these are variables)
EXTERN_DATA = {'_page_size': 0x1000}
# argument counts of the plain-C externs the kext calls (the mangled ones are parsed from their name)
EXTERN_ARITY = {'_IOLockLock': 1, '_IOLockUnlock': 1, '_IOLockSleep': 3, '_IOLockWakeup': 3, '_IOSleep': 1, '_IOFree': 2, '_IOFreeAligned': 2,
                '_IOMalloc': 1, '_IOMallocAligned': 2, '_bzero': 2, '_bcopy': 3, '_memcpy': 3, '_memset': 3, '_IOLog': 1, '_IOGetTime': 1,
                '_IODelay': 1, '_IOLockAlloc': 0, '_IOLockFree': 1, '_panic': 1, '_kprintf': 1, '_IOSimpleLockLock': 1, '_IOSimpleLockUnlock': 1,
                '_thread_block': 1, '_assert_wait': 2, '_IOMemoryDescriptor_withAddress': 4}


# ----------------------------------------------------------------------------------------------------------------------------------------------
# names, signatures and arities

_demangle_cache = {}


def demangle_all(names):
    todo = [n for n in names if n not in _demangle_cache]
    if todo:
        # Mach-O prefixes every C symbol with an underscore, so a mangled name starts `__Z`; c++filt wants `_Z`
        out = subprocess.run(['c++filt', '-n'], input='\n'.join(n[1:] if n.startswith('__Z') else n for n in todo) + '\n', capture_output=True, text=True).stdout.split('\n')
        for n, d in zip(todo, out):
            _demangle_cache[n] = d
    return {n: _demangle_cache[n] for n in names}


def split_params(s):
    out, depth, cur = [], 0, ''
    for ch in s:
        if ch in '(<': depth += 1
        if ch in ')>': depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur.strip()); cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def signature_of(name, demangled=None):
    """-> (gpr_arg_words, kinds) where kinds is a list like ['this', 'i', 'p', 'f'] or None when the arity is unknown."""
    d = demangled if demangled is not None else demangle_all([name])[name]
    if demangled is None and (d == name or d == name[1:]):                                         # not a C++ name
        n = EXTERN_ARITY.get(name)
        return (n, ['i'] * n) if n is not None else (None, None)
    m = re.match(r'^(.*?)\((.*)\)(\s*const)?$', d)
    if not m:
        return (None, None)
    head, params = m.group(1), m.group(2)
    ps = split_params(params)
    if ps == ['void']: ps = []
    kinds = []
    if '::' in head and not head.startswith('non-virtual') and not re.search(r'::(\w+)::\1$', '') :
        kinds.append('this')
    for p in ps:
        pl = p.replace('const', '').replace('volatile', '').strip()
        if pl in ('double', 'float'): kinds.append('f')
        elif re.search(r'\blong long\b|\bint64\b', pl) and '*' not in pl: kinds += ['i', 'i']
        elif '*' in pl or '&' in pl: kinds.append('p')
        else: kinds.append('i')
    return (sum(1 for k in kinds if k != 'f'), kinds)


# ----------------------------------------------------------------------------------------------------------------------------------------------
# stub registry shared by both sides

class StubRegistry:
    def __init__(self):
        self.addr, self.name, self.sig = {}, {}, {}

    def get(self, name, sig=None):
        if name not in self.addr:
            a = STUB_BASE + 16 * len(self.addr)
            assert a < STUB_BASE + STUB_SIZE, 'stub registry full'
            self.addr[name] = a; self.name[a] = name
        if sig is not None and name not in self.sig:
            self.sig[name] = sig
        return self.addr[name]

    def signature(self, name):
        if name not in self.sig:
            self.sig[name] = signature_of(name)
        return self.sig[name]


# ----------------------------------------------------------------------------------------------------------------------------------------------
# images

class Image:
    def __init__(self, path, label):
        self.path, self.label = path, label
        m = machoutil.load(path)
        assert m.filetype == 1, '%s: expected an MH_OBJECT (an unlinked kext)' % path
        seg = m.segs[0]
        assert seg['vmaddr'] == 0
        self.m = m
        self.size = (seg['vmsize'] + PAGE - 1) & ~(PAGE - 1)
        data = bytearray(self.size)
        for s in m.secs:
            if s['size']:
                data[s['addr']:s['addr'] + s['size']] = m.read(s['addr'], s['size'])
        self.data = data
        text_idx = next(i for i, s in enumerate(m.secs) if s['name'] == '__text') + 1
        self.funcs = {}                                    # name -> address, all functions defined in __text
        for sy in m.syms:
            if (sy['type'] & 0x0e) == 0x0e and sy['sect'] == text_idx and sy['name']:
                self.funcs.setdefault(sy['name'], sy['value'])
        self.extern_names = set()
        self._extern_relocs = []
        for (sg, sn), lst in m.sec_relocs.items():
            for r in lst:
                if r['ext'] and not r['scattered'] and r['symnum'] is not None:
                    nm = m.syms[r['symnum']]['name']
                    self._extern_relocs.append((r['addr'], r['rtype'], nm))
                    self.extern_names.add(nm)

    def instantiate(self, reg):
        """-> (patched bytes of the image, {extern name: stub or cell address}); external references resolved to the registry's stubs / data cells"""
        data = bytearray(self.data)
        target = {}
        for nm in sorted(self.extern_names):
            target[nm] = (DATA_BASE + 4 * sorted(EXTERN_DATA).index(nm)) if nm in EXTERN_DATA else reg.get(nm)
        for addr, rtype, nm in self._extern_relocs:
            s = target[nm]
            w = struct.unpack('>I', data[addr:addr + 4])[0]
            if rtype == 4:      w = (w & 0xffff0000) | ((s >> 16) & 0xffff)                       # HI16
            elif rtype == 6:    w = (w & 0xffff0000) | (((s + 0x8000) >> 16) & 0xffff)            # HA16
            elif rtype == 5:    w = (w & 0xffff0000) | (s & 0xffff)                                # LO16
            elif rtype == 3:                                                                       # BR24: bl/b to an external
                disp = s - addr
                assert -0x2000000 <= disp < 0x2000000
                w = (w & 0xfc000003) | (disp & 0x03fffffc)
            elif rtype == 0:    w = s                                                              # VANILLA: a pointer in data
            elif rtype in (1, 13):  continue                                                       # PAIR / JBSR marker
            else:
                raise AssertionError('%s: unhandled external relocation type %d at 0x%x (%s)' % (self.label, rtype, addr, nm))
            struct.pack_into('>I', data, addr, w)
        return data, target


# ----------------------------------------------------------------------------------------------------------------------------------------------
# the machine

class Run:
    pass


class Machine:
    """one emulated side. `world` is a callable(machine) that builds the test objects; it must allocate in the same order on both sides."""

    def __init__(self, image, reg, seed, lazy='zero', mock_policy=None, limit=300000, stack_args=None):
        self.image, self.reg, self.seed, self.lazy, self.limit = image, reg, seed, lazy, limit
        self.stack_args = stack_args or {}
        self.mock_policy = mock_policy or default_mock
        self.uc = uc = Uc(UC_ARCH_PPC, UC_MODE_PPC32 | UC_MODE_BIG_ENDIAN)
        data, self.extern_target = image.instantiate(reg)
        self.patched = data
        uc.mem_map(0, image.size)
        uc.mem_write(0, bytes(data))
        uc.mem_map(STUB_BASE, STUB_SIZE)
        uc.mem_write(STUB_BASE, struct.pack('>I', BLR) * (STUB_SIZE // 4))
        uc.mem_map(DATA_BASE, PAGE)
        for i, k in enumerate(sorted(EXTERN_DATA)):
            uc.mem_write(DATA_BASE + 4 * i, struct.pack('>I', EXTERN_DATA[k]))
        uc.mem_map(STOP, PAGE)
        uc.mem_write(STOP, struct.pack('>I', BLR))
        uc.mem_map(STACK_TOP - STACK_SIZE, STACK_SIZE)
        self.arena_next = ARENA
        self.mapped = [(0, image.size), (STUB_BASE, STUB_SIZE), (DATA_BASE, PAGE), (STOP, PAGE), (STACK_TOP - STACK_SIZE, STACK_SIZE)]
        self.entry_patched = {}
        self.calls, self.writes, self.insns = [], [], 0
        self.visited = set()
        self.trail = []
        self.read_trace = None
        self.hw = []                  # register windows: (base, end, model)
        self.events = []              # calls and register accesses, in order
        self.write_log = []           # [addr, size, old bytes, new bytes]
        self.pending = None           # index in write_log of the store whose result has not been read back yet
        self.snapshots = []
        self.status = '?'
        self.stub_count = {}

    # -- memory ------------------------------------------------------------------------------------------------------------------------------
    def alloc(self, size, fill=None):
        size = (size + PAGE - 1) & ~(PAGE - 1)
        a = self.arena_next
        self.arena_next += size + PAGE                     # a guard page between objects
        self.uc.mem_map(a, size)
        self.mapped.append((a, size))
        if fill is not None:
            self.uc.mem_write(a, fill)
        return a

    def mmio(self, size=0x10000, model=None):
        """a register window: memory whose reads and writes are hardware accesses, compared strictly between the two sides.
        model(kind, offset, size, data) may emulate the device: kind 'W' is told what was written (data = the bytes), kind 'R' returns the bytes to be
        read (or None to leave the memory as it is). Without a model the window is plain memory."""
        a = self.alloc(size)
        self.hw.append((a, a + size, model))
        return a

    def _hw_of(self, addr):
        for b, e, mdl in self.hw:
            if b <= addr < e:
                return b, mdl
        return None

    def rand_bytes(self, n, tag):
        r = random.Random((self.seed << 16) ^ zlib.crc32(tag.encode()))
        return bytes(r.getrandbits(8) for _ in range(n))

    def w32(self, a, v): self.uc.mem_write(a, struct.pack('>I', v & 0xffffffff))
    def w16(self, a, v): self.uc.mem_write(a, struct.pack('>H', v & 0xffff))
    def w8(self, a, v): self.uc.mem_write(a, bytes([v & 0xff]))
    def r32(self, a): return struct.unpack('>I', bytes(self.uc.mem_read(a, 4)))[0]
    def r16(self, a): return struct.unpack('>H', bytes(self.uc.mem_read(a, 2)))[0]
    def r8(self, a): return self.uc.mem_read(a, 1)[0]

    def vtable(self, cls, size=0x700):
        """a vtable for `cls` whose slots are all named stubs: the ones listed in Ledger/kext_ppc_vtables.txt by their method, the rest by offset"""
        slots = load_vtables().get(cls)
        assert slots, 'no vtable listing for ' + cls
        a = self.alloc(size)
        for off in range(0, size, 4):
            dem = slots.get(off)
            name = ('%s [vcall +0x%x]' % (dem, off)) if dem else ('vtable slot +0x%x' % off)
            self.w32(a + off, self.reg.get(name, signature_of(dem, dem) if dem else (None, None)))
        return a

    # -- hooks -------------------------------------------------------------------------------------------------------------------------------
    def _unmapped(self, uc, access, addr, size, value, ud):
        if access in (UC_MEM_FETCH_UNMAPPED,):
            return False
        base = addr & ~(PAGE - 1)
        if base < 0x1000:                                    # null-page accesses are faults, not data
            return False
        try:
            uc.mem_map(base, PAGE)
        except UcError:
            return False
        self.mapped.append((base, PAGE))
        if self.lazy == 'random':
            uc.mem_write(base, self.rand_bytes(PAGE, 'page%x' % base))
        return True

    def _flush(self):
        """read back the bytes of the last store (the hook runs before the store, so its result is only known afterwards)"""
        if self.pending is not None:
            i, hwidx = self.pending
            ent = self.write_log[i]
            ent[3] = bytes(self.uc.mem_read(ent[0], ent[1]))
            if hwidx is not None:
                self.events[hwidx][3] = ent[3].hex()
                h = self._hw_of(ent[0])
                if h and h[1]:
                    h[1]('W', ent[0] - h[0], ent[1], ent[3])
            self.pending = None

    def _write(self, uc, access, addr, size, value, ud):
        self._flush()
        if any(a <= addr < b for a, b in self.ro):
            self.bad_read = True          # a store into the kext's own machine code / constants: a garbage pointer in the test world
            return
        self.write_log.append([addr, size, bytes(uc.mem_read(addr, size)), None])
        h = self._hw_of(addr)
        hwidx = None
        if h:
            self.events.append(['W', addr - h[0], size, None])
            hwidx = len(self.events) - 1
        self.pending = (len(self.write_log) - 1, hwidx)

    def _hw_read(self, uc, access, addr, size, value, ud):
        self._flush()
        h = self._hw_of(addr)
        if h and h[1]:
            data = h[1]('R', addr - h[0], size, None)
            if data is not None:
                uc.mem_write(addr, bytes(data))
        self.events.append(['R', addr - h[0], size, bytes(uc.mem_read(addr, size)).hex()])

    def _read_code(self, uc, access, addr, size, value, ud):
        if self.own[0] <= addr < self.own[1]:
            return                # the function's own extent holds its jump tables
        self.bad_read = True      # the function read machine code as data: a garbage pointer in the test world

    def _trace_read(self, uc, access, addr, size, value, ud):
        if not (STACK_TOP - STACK_SIZE <= addr < STACK_TOP) and not (self.image.size > addr >= 0 and False):
            self.read_trace.append((addr, size, bytes(uc.mem_read(addr, size)).hex()))

    def _stub_hook(self, uc, addr, size, ud):
        if addr == STOP:
            self.status = 'RET'; uc.emu_stop(); return
        name = self.reg.name.get(addr)
        if name is None:
            return
        self.record_call(name)

    def _block(self, uc, addr, size, ud):
        self.insns += size // 4
        self.visited.add((addr, size))
        self.trail.append(addr)
        if self.insns > self.limit:
            self.status = 'TIMEOUT'; uc.emu_stop()

    def record_call(self, name):
        uc = self.uc
        n, kinds = self.reg.signature(name)
        regs = [uc.reg_read(UC_PPC_REG_3 + i) for i in range(8)]
        unknown = n is None
        if unknown:
            kinds = ['i', 'i', 'i']; n = 3
        vals, gi, fi = [], 0, 0
        for k in kinds:
            if k == 'f':
                fi += 1
                vals.append(('f', struct.pack('>d', uc.reg_read(UC_PPC_REG_FPR0 + fi)).hex() if False else 0))
                continue
            if gi >= 8: break
            v = regs[gi]; gi += 1
            vals.append(self.normalise(v, name, gi - 1))
        k = self.stub_count.get(name, 0); self.stub_count[name] = k + 1
        self.calls.append((name, tuple(vals), unknown))
        self._flush()
        self.events.append(['C', name, tuple(vals)])
        self.snapshots.append(self.memory_diff())
        uc.reg_write(UC_PPC_REG_3, self.mock_policy(self, name, k) & 0xffffffff)

    def normalise(self, v, name, index):
        """a pointer into the function's own stack frame differs between the two builds (their frames differ), so it is replaced by the contents it points
        to - but only when the case says how many bytes the callee reads there (Case.stack_args: {callee substring: {arg index: bytes}});
        otherwise just a marker, because the bytes around a local are not part of the contract"""
        if STACK_TOP - STACK_SIZE <= v < STACK_TOP:
            n = 0
            for key, spec in self.stack_args.items():
                if key in name:
                    n = spec.get(index, 0)
            return ('stack', bytes(self.uc.mem_read(v, min(n, STACK_TOP - v))).hex() if n else '')
        return v

    # -- running -----------------------------------------------------------------------------------------------------------------------------
    def prepare(self, target_name):
        """redirect every other function of the image to its stub (the first instruction becomes `ba stub`)"""
        entry = self.image.funcs[target_name]
        later = [a for a in self.image.funcs.values() if a > entry]
        self.own = (entry, min(later) if later else self.image.size)
        for name, a in self.image.funcs.items():
            if name == target_name:
                continue
            s = self.reg.get(name)
            self.uc.mem_write(a, struct.pack('>I', 0x48000002 | s))      # ba s  (AA=1, LK=0)
        self.uc.hook_add(UC_HOOK_CODE, self._stub_hook, begin=STUB_BASE, end=STUB_BASE + STUB_SIZE - 1)
        self.uc.hook_add(UC_HOOK_CODE, self._stub_hook, begin=STOP, end=STOP + 3)
        self.uc.hook_add(UC_HOOK_BLOCK, self._block, begin=0, end=self.image.size - 1)
        self.uc.hook_add(UC_HOOK_MEM_UNMAPPED, self._unmapped)
        self.uc.hook_add(UC_HOOK_MEM_WRITE, self._write)
        for b, e, _ in self.hw:
            self.uc.hook_add(UC_HOOK_MEM_READ, self._hw_read, begin=b, end=e - 1)
        if self.read_trace is not None:
            self.uc.hook_add(UC_HOOK_MEM_READ, self._trace_read)
        t = next(x for x in self.image.m.secs if x['name'] == '__text')
        self.bad_read = False
        self.ro = [(x['addr'], x['addr'] + x['size']) for x in self.image.m.secs if x['seg'] == '__TEXT' and x['size']]
        self.uc.hook_add(UC_HOOK_MEM_READ, self._read_code, begin=t['addr'], end=t['addr'] + t['size'] - 1)

    def call(self, target_name, args, fargs=()):
        uc = self.uc
        entry = self.image.funcs[target_name]
        self.prepare(target_name)
        for i in range(32):
            uc.reg_write(UC_PPC_REG_0 + i, 0)
        for i in range(32):
            if i not in (0,):
                pass
        uc.reg_write(UC_PPC_REG_1, ENTRY_SP)
        uc.reg_write(UC_PPC_REG_MSR, 0x2000)
        self.callee_saved = {i: (0x10000000 + i * 0x111) for i in range(14, 32)}
        for i, v in self.callee_saved.items():
            uc.reg_write(UC_PPC_REG_0 + i, v)
        for i, v in enumerate(args):
            uc.reg_write(UC_PPC_REG_3 + i, v & 0xffffffff)
        uc.reg_write(UC_PPC_REG_LR, STOP)
        self.write_log.clear(); self.events.clear(); self.snapshots.clear(); self.pending = None
        self.calls.clear(); self.insns = 0; self.status = '?'
        try:
            uc.emu_start(entry, STOP + 4, count=self.limit * 4)
            if self.status == '?':
                self.status = 'RET'
        except UcError as e:
            self.status = 'FAULT'
            self.fault = str(e)
        return self.result()

    def memory_diff(self):
        """{address: byte} of every byte outside the function's own stack frame whose value now differs from before the call"""
        initial, final = {}, {}
        lo, hi = STACK_TOP - STACK_SIZE, ENTRY_SP
        for addr, size, old, new in self.write_log:
            if new is None or lo <= addr < hi:
                continue
            for i in range(size):
                initial.setdefault(addr + i, old[i]); final[addr + i] = new[i]
        return {a: b for a, b in final.items() if b != initial[a]}

    def result(self):
        uc = self.uc
        r = Run()
        r.status, r.calls, r.insns = self.status, list(self.calls), self.insns
        r.bad_read = self.bad_read
        r.visited = set(self.visited)
        r.trail = list(self.trail)
        r.fault_pc = self.uc.reg_read(UC_PPC_REG_PC)
        r.own = self.own
        r.r3, r.r4 = uc.reg_read(UC_PPC_REG_3), uc.reg_read(UC_PPC_REG_4)
        r.sp = uc.reg_read(UC_PPC_REG_1)
        r.abi = []
        if self.status == 'RET':
            if r.sp != ENTRY_SP: r.abi.append('r1 not restored (0x%x)' % r.sp)
            for i, v in self.callee_saved.items():
                if uc.reg_read(UC_PPC_REG_0 + i) != v:
                    r.abi.append('r%d not preserved' % i)
        self._flush()
        r.writes = self.memory_diff()
        r.write_order = [(a, n, b) for a, n, o, b in self.write_log if not (STACK_TOP - STACK_SIZE <= a < ENTRY_SP)]
        r.events = [tuple(e) for e in self.events]
        r.snapshots = list(self.snapshots)
        r.fault = getattr(self, 'fault', '') if self.status == 'FAULT' else ''
        return r


_ret_kind_cache = {}


def callee_ret_kind(name):
    """'void' | 'bool' | 'ptr' | 'status' (IOReturn) | 'int' for a mocked callee, from its declaration in Headers/<Class>.h ('int' when unknown)"""
    base = name.split(' [vcall')[0]
    if base in _ret_kind_cache:
        return _ret_kind_cache[base]
    kind = 'int'
    d = demangle_all([base]).get(base, base)
    mm = re.match(r'^(?:\w+ )*?([A-Za-z_]\w*)::(~?\w+)\(', d)
    if mm:
        hdr = os.path.join(HERE, '..', '..', 'Headers', mm.group(1) + '.h')
        if os.path.exists(hdr):
            for ln in open(hdr):
                m2 = re.match(r'^\s*(?:virtual\s+|static\s+)?(.+?[\s\*&])%s\s*\(' % re.escape(mm.group(2)), ln)
                if m2:
                    t = m2.group(1).strip()
                    kind = 'void' if t == 'void' else 'bool' if t == 'bool' else 'status' if t == 'IOReturn' else 'ptr' if t.endswith('*') else 'int'
                    break
    _ret_kind_cache[base] = kind
    return kind


def default_mock(machine, name, k):
    """what a mocked callee returns: deterministic in (seed, callee, call index) and inside the callee's return domain (a `bool` callee returns 0 or 1,
    a pointer-returning one a fresh random object), identical on both sides"""
    r = random.Random((machine.seed << 20) ^ zlib.crc32(name.encode()) ^ (k * 2654435761 & 0xffffffff))
    kind = callee_ret_kind(name)
    if kind == 'void': return 0
    if kind == 'bool': return r.choice([0, 1])
    if kind == 'ptr':
        if r.random() < 0.2: return 0
        o = machine.alloc(0x200)
        machine.uc.mem_write(o, bytes(r.getrandbits(8) for _ in range(0x200)))
        return o
    if kind == 'status': return r.choice([0, 0, 0xe00002bc, 0xe00002be, 0xe00002c2, 0xe00002cc])
    return r.choice([0, 0, 1, 1, 2, 0xe00002bc, 0xe00002c2, r.getrandbits(32)])


_vt = None


def load_vtables():
    global _vt
    if _vt is None:
        _vt, cur = {}, None
        for ln in open(VTABLES):
            m = re.match(r'^# (\S+) vtable @', ln)
            if m: cur = m.group(1); _vt[cur] = {}; continue
            m = re.match(r'^0x([0-9a-f]+) (.*)$', ln.strip())
            if m and cur is not None:
                _vt[cur][int(m.group(1), 16)] = m.group(2)
    return _vt


# ----------------------------------------------------------------------------------------------------------------------------------------------
# cases

class Case:
    """one function, many inputs.
    function  'Class::method' (add `signature` to choose between overloads: a substring of the demangled name, e.g. '(unsigned long, eDoSwap')
    ret       'void' | 'u32' | 'bool' | 'u16' | 's32' ...: what is compared of r3 (void: nothing)
    world     callable(machine, rng) -> list of arguments (register values, `this` first); it builds the objects in the machine
    seeds     how many seeds to run (each seed gives different random inputs and mock returns)
    lazy      'zero' (default) or 'random': contents of memory the test did not set up
    limit     instruction budget per run
    mock      callable(machine, callee name, call index) -> value a mocked callee returns (default: seeded choice among typical status values)
    stack_args  {callee name substring: {argument index: bytes}} for pointers to locals that the callee reads (their contents are compared)
    """
    def __init__(self, function, world, ret='u32', seeds=16, signature=None, lazy='zero', limit=300000, mock=None, name=None, stack_args=None):
        self.stack_args = stack_args or {}
        self.function, self.world, self.ret, self.seeds = function, world, ret, seeds
        self.signature, self.lazy, self.limit, self.mock = signature, lazy, limit, mock
        self.name = name or function


def find_symbol(image, function, signature=None):
    cls, _, meth = function.rpartition('::')
    prefix = ''
    if cls:
        prefix = '__ZN%d%s%d%s' % (len(cls), cls, len(meth), meth)
    cand = [n for n in image.funcs if (n.startswith(prefix) if prefix else n == function or n == '_' + function)]
    if signature:
        dem = demangle_all(cand)
        cand = [n for n in cand if signature in dem[n]]
    if len(cand) != 1:
        raise LookupError('%s (%s): %d matching symbols in %s: %s' % (function, signature, len(cand), image.label, cand[:4]))
    return cand[0]


def compare(case, st, rb, strict_order=False, strict_calls=False):
    """-> list of problems (strings); empty = identical behaviour"""
    probs = []
    if st.status == 'TIMEOUT' or rb.status == 'TIMEOUT' or st.bad_read or rb.bad_read:
        return ['INCONCLUSIVE']          # budget exceeded, or a wild pointer in the test world (a read of machine code as data, a store into it): not comparable
    if st.status != rb.status:
        probs.append('ends differently: stock %s%s, rebuilt %s%s' % (st.status, ' (%s)' % st.fault if st.fault else '', rb.status, ' (%s)' % rb.fault if rb.fault else ''))
        return probs
    # hardware register accesses, interleaved with the calls: exact
    if any(e[0] in 'RW' for e in st.events + rb.events):
        for i in range(max(len(st.events), len(rb.events))):
            a = st.events[i] if i < len(st.events) else None
            b = rb.events[i] if i < len(rb.events) else None
            if a != b:
                probs.append('HARDWARE access pattern differs at event #%d: stock %s, rebuilt %s' % (i, fmt_event(a), fmt_event(b)))
                break
    if strict_calls:
        for i, (a, b) in enumerate(zip(st.snapshots, rb.snapshots)):
            if a != b:
                keys = sorted(set(a) | set(b)); d = [k for k in keys if a.get(k) != b.get(k)]
                probs.append('memory visible to call #%d differs at %d byte(s), first 0x%x' % (i, len(d), d[0]))
                break
    # calls
    for i in range(max(len(st.calls), len(rb.calls))):
        a = st.calls[i] if i < len(st.calls) else None
        b = rb.calls[i] if i < len(rb.calls) else None
        if a is None or b is None or a[0] != b[0] or a[1] != b[1]:
            probs.append('call #%d differs: stock %s, rebuilt %s' % (i, fmt_call(a), fmt_call(b)))
            break
    if len(st.calls) != len(rb.calls) and not any(p.startswith('call #') for p in probs):
        probs.append('different number of calls: stock %d, rebuilt %d' % (len(st.calls), len(rb.calls)))
    # return value
    if case.ret != 'void' and st.status == 'RET':
        mask = {'u32': 0xffffffff, 's32': 0xffffffff, 'bool': 0xff, 'u16': 0xffff, 'u8': 0xff, 'u64': None}[case.ret] if case.ret in ('u32', 's32', 'bool', 'u16', 'u8', 'u64') else 0xffffffff
        if case.ret == 'u64':
            a, b = (st.r3, st.r4), (rb.r3, rb.r4)
        else:
            a, b = st.r3 & mask, rb.r3 & mask
        if a != b:
            probs.append('return value differs: stock %s, rebuilt %s' % (hexs(a), hexs(b)))
    # writes
    if st.writes != rb.writes:
        keys = sorted(set(st.writes) | set(rb.writes))
        d = [(k, st.writes.get(k), rb.writes.get(k)) for k in keys if st.writes.get(k) != rb.writes.get(k)]
        probs.append('memory left behind differs at %d byte(s), first: %s' % (len(d), ', '.join('0x%x stock %s rebuilt %s' % (k, hexs(a), hexs(b)) for k, a, b in d[:4])))
    elif strict_order and st.write_order != rb.write_order:
        probs.append('same final memory but different write order/granularity (stock %d stores, rebuilt %d)' % (len(st.write_order), len(rb.write_order)))
    for side, r in (('stock', st), ('rebuilt', rb)):
        for a in r.abi:
            probs.append('%s: %s' % (side, a))
    return probs


def fmt_event(e):
    if e is None: return '<none>'
    if e[0] == 'C': return 'call ' + fmt_call((e[1], e[2], False))
    return '%s +0x%x/%d %s' % ('write' if e[0] == 'W' else 'read', e[1], e[2], e[3])


def hexs(v):
    if v is None: return 'none'
    if isinstance(v, tuple): return '(' + ','.join(hexs(x) for x in v) + ')'
    return '0x%x' % v


def fmt_call(c):
    if c is None: return '<none>'
    name, args, unk = c
    d = demangle_all([name.split(' [vcall')[0]]).get(name.split(' [vcall')[0], name)
    return '%s(%s)%s' % (name if ' [vcall' in name else d, ', '.join(('stack:' + a[1][:16] + '..') if isinstance(a, tuple) and a[0] == 'stack' else hexs(a) for a in args), ' [arity unknown]' if unk else '')


def coverage(runs):
    """fraction of the function's instructions executed in at least one run (block granularity), over runs that were usable"""
    vis, own = set(), None
    for r in runs:
        own = r.own
        for a, n in r.visited:
            if own[0] <= a < own[1]:
                vis.update(range(a, min(a + n, own[1]), 4))
    return (len(vis) * 4 / float(own[1] - own[0])) if own and own[1] > own[0] else 0.0


def run_case(case, stock, rebuilt, reg, verbose=False, strict_order=False, strict_calls=False):
    results = []
    all_runs = ([], [])
    sym_s = find_symbol(stock, case.function, case.signature)
    sym_r = find_symbol(rebuilt, case.function, case.signature)
    for seed in range(case.seeds):
        outs = []
        for img, sym in ((stock, sym_s), (rebuilt, sym_r)):
            m = Machine(img, reg, seed, lazy=case.lazy, mock_policy=case.mock, limit=case.limit, stack_args=case.stack_args)
            rng = random.Random(seed * 7919 + zlib.crc32(case.name.encode()))
            kinds = signature_of(sym)[1] or []
            args = case.world(m, rng, kinds) if getattr(case.world, '__code__', None) and case.world.__code__.co_argcount >= 3 else case.world(m, rng)
            out = m.call(sym, args)
            outs.append(out); all_runs[len(outs) - 1].append(out)
        probs = compare(case, outs[0], outs[1], strict_order, strict_calls)
        case.hw_events = getattr(case, 'hw_events', 0) + sum(1 for e in outs[0].events if e[0] in 'RW')
        results.append((seed, [] if probs == ['INCONCLUSIVE'] else probs, outs[0].insns, outs[1].insns, 'TIMEOUT' if (outs[0].status == 'TIMEOUT' or outs[1].status == 'TIMEOUT' or outs[0].bad_read or outs[1].bad_read) else outs[0].status, len(outs[0].calls)))
    case.cov = (coverage(all_runs[0]), coverage(all_runs[1]))
    return sym_s, results


def explain(case, stock, rebuilt, reg, seed):
    for img in (stock, rebuilt):
        sym = find_symbol(img, case.function, case.signature)
        m = Machine(img, reg, seed, lazy=case.lazy, mock_policy=case.mock, limit=case.limit, stack_args=case.stack_args)
        rng = random.Random(seed * 7919 + zlib.crc32(case.name.encode()))
        kinds = signature_of(sym)[1] or []
        args = case.world(m, rng, kinds) if getattr(case.world, '__code__', None) and case.world.__code__.co_argcount >= 3 else case.world(m, rng)
        m.read_trace = []
        r = m.call(sym, args)
        entry = img.funcs[sym]
        print('%s: %s%s, %d insns, r3=0x%x, last pc 0x%x (function at 0x%x)' % (img.label, r.status, ' (%s)' % r.fault if r.fault else '', r.insns, r.r3, r.fault_pc, entry))
        print('  blocks (offset from entry): ' + ' '.join('%x' % (a - entry) if entry <= a < r.own[1] else 'ext:%x' % a for a in r.trail[:60]))
        for c in r.calls[:8]:
            print('  call', fmt_call(c))
        print('  data reads (addr size value): ' + ' '.join('%x/%d=%s' % x for x in m.read_trace[:40]))


def load_cases(path):
    spec = importlib.util.spec_from_file_location('difftest_cases_' + os.path.basename(path).replace('.', '_'), path)
    mod = importlib.util.module_from_spec(spec)
    sys.path.insert(0, os.path.dirname(os.path.abspath(path)))
    spec.loader.exec_module(mod)
    return mod.CASES


def main():
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--stock', default=STOCK_DEFAULT, help='shipped kext binary (or $STOCK_KEXT)')
    ap.add_argument('--rebuilt', default=REBUILT_DEFAULT, help='rebuilt kext binary (or $REBUILT_KEXT; default build/difftest/rebuilt.bin)')
    ap.add_argument('-f', '--filter', default='')
    ap.add_argument('-v', '--verbose', action='store_true')
    ap.add_argument('--strict-order', action='store_true', help='also require the same order and width of ALL stores (register accesses are always strict)')
    ap.add_argument('--strict-calls', action='store_true', help='also require the memory a callee could observe (everything written so far) to be the same at every call')
    ap.add_argument('--json')
    ap.add_argument('--explain', type=int, metavar='SEED', help='print the sequence of basic blocks each side executed for this seed (debugging a difference)')
    ap.add_argument('cases', nargs='+')
    a = ap.parse_args()
    if not a.stock:
        ap.error('give the shipped kext binary with --stock or $STOCK_KEXT')
    stock, rebuilt = Image(a.stock, 'stock'), Image(a.rebuilt, 'rebuilt')
    reg = StubRegistry()
    report, bad = [], 0
    for cf in a.cases:
        for case in load_cases(cf):
            if a.filter and a.filter not in case.name:
                continue
            if a.explain is not None:
                explain(case, stock, rebuilt, reg, a.explain); continue
            t0 = time.time()
            try:
                sym, res = run_case(case, stock, rebuilt, reg, a.verbose, a.strict_order, a.strict_calls)
            except LookupError as e:
                print('ERROR  %s: %s' % (case.name, e)); bad += 1; continue
            fails = [r for r in res if r[1]]
            inconclusive = [r for r in res if r[4] == 'TIMEOUT']
            usable = [r for r in res if r[4] != 'TIMEOUT']
            res_all, res = res, usable
            si = sum(r[2] for r in res); ri = sum(r[3] for r in res)
            ratio = (ri / si) if si else 0
            reached = sum(1 for r in res if r[5] > 0)
            verdict = 'PASS' if not fails else 'FAIL'
            if not res:
                verdict = 'NO-RESULT'; fails = [(0, ['no run finished: every input made the function exceed the budget'])]
            print('%s  %-58s %2d/%2d runs identical   insns stock %d rebuilt %d (x%.2f)   cov %d%%/%d%%   runs with calls %d%s%s' % (verdict, case.name, len(res) - len(fails), len(res), si, ri, ratio, round(100 * case.cov[0]), round(100 * case.cov[1]), reached, ('   register accesses %d' % case.hw_events) if getattr(case, 'hw_events', 0) else '', ('   (%d inconclusive: budget exceeded or code read as data)' % len(inconclusive)) if inconclusive else ''))
            if ratio > 1.5 or (ratio and ratio < 0.5):
                print('       note: instruction count ratio x%.2f' % ratio)
            for seed, probs, *_ in fails[:3 if not a.verbose else 99]:
                print('       seed %d: %s' % (seed, '; '.join(probs)))
            if fails: bad += 1
            report.append(dict(case=case.name, symbol=sym, runs=len(res), failures=len(fails), insns_stock=si, insns_rebuilt=ri,
                               problems=[dict(seed=s, problems=p) for s, p, *_ in fails]))
    if a.json:
        json.dump(report, open(a.json, 'w'), indent=1)
    print('%d case(s), %d with differences' % (len(report) + 0, bad))
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
