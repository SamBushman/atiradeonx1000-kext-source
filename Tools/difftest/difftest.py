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
the cost is an instruction count; a register window is plain memory unless the test supplies a device model, so device behaviour (status bits that
change, side effects of a read) exists only as far as the model makes it.

Usage: difftest.py [--stock BIN] [--rebuilt BIN] [-f SUBSTRING] [-v] [--json OUT] CASEFILE.py [CASEFILE.py ...]
  A case file defines CASES = [Case(...), ...] (see class Case). Exit 0 if every run matches, 1 otherwise.
Setup: pip install --break-system-packages --target ~/.cache/kext-difftest/pkgs unicorn   (or set DIFFTEST_PKGS)
"""
import bisect, os, sys, struct, re, subprocess, random, json, importlib.util, zlib, time

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
STACKPTR_MARK = b'\x7f\xff\xff\xf0'
CALLER_SCRATCH = 0x100                                      # bytes above the entry SP that belong to the callee: LR/CR slots and the home area of the register arguments
BLR = 0x4e800020

VTEXT_BASE, VTEXT_SIZE = 0x00500000, 0x00001000          # vtables of classes outside the kext (IOService, OSObject, ...): data with named-stub slots
VTEXT_SLOTS = {'__ZTV9IOService': {0x48: '__ZN8OSObject4initEv', 0x4c: '__ZN9IOService4freeEv'}}    # known slots of those vtables; the rest are named by symbol and offset
IOKIT_FAMILY_VTABLES = {'__ZTV8OSObject', '__ZTV15IORegistryEntry', '__ZTV9IOService', '__ZTV12IOUserClient'}   # one hierarchy: slot +0xNN is the same method in each
COMMON_BASE, COMMON_SIZE = 0x00400000, 0x00010000        # storage of the rebuilt kext's `.comm` symbols (the kext linker allocates them at load time)
DATA_OBJ = DATA_BASE + 0x1000                              # a page of stand-in kernel objects the external data symbols point at
# external DATA symbols and what their cell holds: variables (the page size) and pointers to kernel objects (OSBoolean true, the kernel task, ...)
EXTERN_DATA = {'_page_size': 0x1000, '_page_shift': 12, '_kOSBooleanTrue': DATA_OBJ + 0x00, '_kernel_task': DATA_OBJ + 0x40,
               '_gIODTPlane': DATA_OBJ + 0x80, '_gIOServicePlane': DATA_OBJ + 0xc0}
# argument counts of the plain-C externs the kext imports (the mangled ones are parsed from their name). Variadic functions list the registers compared.
EXTERN_ARITY = {'_IODelay': 1, '_IOFree': 2, '_IOFreeAligned': 2, '_IOFreeContiguous': 2, '_IOFreePageable': 2, '_IOGetTime': 1, '_IOLockAlloc': 0,
                '_IOLockFree': 1, '_IOLockLock': 1, '_IOLockSleep': 3, '_IOLockUnlock': 1, '_IOLockWakeup': 3, '_IOLog': 6, '_IOMalloc': 1,
                '_IOMallocAligned': 2, '_IOMallocContiguous': 3, '_IOMallocPageable': 2, '_IOPanic': 1, '_IOSleep': 1, '_OSAddAtomic': 2,
                '_OSDecrementAtomic': 1, '_OSIncrementAtomic': 1, '_OSRuntimeFinalizeCPP': 0, '_OSRuntimeInitializeCPP': 0, '___cxa_pure_virtual': 0,
                '_absolutetime_to_nanoseconds': 3, '_assert_wait_timeout': 3, '_bzero': 2, '_clock_get_uptime': 1, '_kprintf': 6, '_memcpy': 3,
                '_memset': 3, '_panic': 6, '_sscanf': 6, '_sysctlbyname': 6, '_thread_block': 1, '_bcopy': 3, '_assert_wait': 2}
# which arguments of the plain-C externs are pointers (a pointer into the kext's own image is compared by name, not by address)
EXTERN_PTR_ARGS = {'_IOLog': [0], '_kprintf': [0], '_panic': [0], '_IOPanic': [0], '_sscanf': [0, 1], '_memcpy': [0, 1], '_bcopy': [0, 1], '_memset': [0], '_bzero': [0],
                   '_assert_wait_timeout': [0], '_assert_wait': [0], '_sysctlbyname': [0, 1, 2, 3], '_IOFree': [0], '_IOFreeAligned': [0], '_IOFreeContiguous': [0],
                   '_IOFreePageable': [0], '_IOLockFree': [0], '_IOLockLock': [0], '_IOLockUnlock': [0], '_IOLockSleep': [0, 1], '_IOLockWakeup': [0, 1],
                   '_clock_get_uptime': [0], '_absolutetime_to_nanoseconds': [2], '_OSAddAtomic': [1], '_OSDecrementAtomic': [0], '_OSIncrementAtomic': [0],
                   '_IOGetTime': [0], '_IOMallocContiguous': [2]}
# static member functions of classes outside the kext (no `this`): the mangled name does not say
STATIC_METHODS = {'withCapacity', 'withOptions', 'withAddress', 'withObjects', 'withCString', 'withString', 'withBytes', 'withData', 'withArray', 'withDictionary', 'withNumber',
                  'withPhysicalAddress', 'withRange', 'withTask', 'withCapacityAndSize', 'getMetaClass', 'metaClass', 'nameMatching', 'serviceMatching', 'getMatchingServices',
                  'checkResource', 'waitForService', 'getPlatform', 'getServiceRoot', 'fromPath', 'getLockedServiceName', 'registerService', 'getUserClient'}
# what a mocked plain-C extern returns: 'void', 'ptr' (a fresh object), 'arg0' (its first argument), 'int'
EXTERN_RET = {'_IODelay': 'void', '_IOFree': 'void', '_IOFreeAligned': 'void', '_IOFreeContiguous': 'void', '_IOFreePageable': 'void',
              '_IOGetTime': 'void', '_IOLockAlloc': 'ptr', '_IOLockFree': 'void', '_IOLockLock': 'void', '_IOLockSleep': 'int',
              '_IOLockUnlock': 'void', '_IOLockWakeup': 'void', '_IOLog': 'void', '_IOMalloc': 'ptr', '_IOMallocAligned': 'ptr',
              '_IOMallocContiguous': 'ptr', '_IOMallocPageable': 'ptr', '_IOPanic': 'void', '_IOSleep': 'void', '_OSAddAtomic': 'int',
              '_OSDecrementAtomic': 'int', '_OSIncrementAtomic': 'int', '_absolutetime_to_nanoseconds': 'void', '_assert_wait_timeout': 'int',
              '_bzero': 'void', '_clock_get_uptime': 'void', '_kprintf': 'int', '_memcpy': 'arg0', '_memset': 'arg0', '_panic': 'void',
              '_sscanf': 'int', '_sysctlbyname': 'int', '_thread_block': 'int', '_bcopy': 'void', '_assert_wait': 'int'}


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
        if n is None:
            return (None, None)
        return (n, ['p' if i in EXTERN_PTR_ARGS.get(name, ()) else 'i' for i in range(n)])
    m = re.match(r'^(.*?)\((.*)\)(\s*const)?$', d)
    if not m:
        return (None, None)
    head, params = m.group(1), m.group(2)
    ps = split_params(params)
    if ps == ['void']: ps = []
    kinds = []
    if '::' in head and not head.startswith('non-virtual') and head.split('::')[-1] not in STATIC_METHODS:
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
        if sig is not None and (name not in self.sig or self.sig[name] == (None, None)):   # an explicit declaration replaces an "unknown" derived one
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
        self._canon_cache = {}
        self.addr2func = {}
        self.commons = {sy['name']: sy['value'] for sy in m.syms if (sy['type'] & 0x0e) == 0 and (sy['type'] & 1) and sy['value'] > 0 and sy['name']}
        data_secs = {i + 1 for i, x in enumerate(m.secs) if x['seg'] == '__DATA'}
        self.datasyms = sorted((sy['value'], sy['name']) for sy in m.syms if (sy['type'] & 0x0e) == 0x0e and sy['sect'] in data_secs and sy['name'])
        self.data_ranges = [(x['addr'], x['addr'] + x['size']) for x in m.secs if x['seg'] == '__DATA' and x['size']]
        for n, a in self.funcs.items():
            self.addr2func.setdefault(a, n)
        self.extern_names = set()
        self._extern_relocs = []
        for (sg, sn), lst in m.sec_relocs.items():
            for i, r in enumerate(lst):
                if r['ext'] and not r['scattered'] and r['symnum'] is not None:
                    nm = m.syms[r['symnum']]['name']
                    pair = lst[i + 1]['symnum'] & 0xffff if r['rtype'] in (4, 5, 6) and i + 1 < len(lst) and lst[i + 1]['rtype'] == 1 else 0
                    self._extern_relocs.append((r['addr'], r['rtype'], nm, pair))
                    self.extern_names.add(nm)

    def instantiate(self, reg):
        """-> (patched bytes of the image, {extern name: stub or cell address}); external references resolved to the registry's stubs / data cells"""
        data = bytearray(self.data)
        target = {}
        self.common_cells, off = {}, 0
        for nm in sorted(self.commons):
            self.common_cells[nm] = (COMMON_BASE + off, self.commons[nm]); off += (self.commons[nm] + 15) & ~15
        self.vtable_externs = {}
        for nm in sorted(self.extern_names):
            if nm in self.common_cells:
                target[nm] = self.common_cells[nm][0]
            elif nm in EXTERN_DATA:
                target[nm] = DATA_BASE + 4 * sorted(EXTERN_DATA).index(nm)
            elif nm.startswith('__ZTV'):                 # a vtable of a class outside the kext: data whose slots are stubs
                self.vtable_externs[nm] = VTEXT_BASE + len(self.vtable_externs) * VTEXT_SIZE
                target[nm] = self.vtable_externs[nm]
            else:
                target[nm] = reg.get(nm)
        word = lambda a: struct.unpack('>I', bytes(self.data[a:a + 4]))[0]      # the ORIGINAL words: the low half may already be patched when its high half is handled
        los = {}                                           # symbol -> addresses of its LO16 instructions (the baked low half is the addend)
        for addr, rtype, nm, pair in self._extern_relocs:
            if rtype == 5: los.setdefault(nm, []).append(addr)
        for addr, rtype, nm, pair in self._extern_relocs:
            s = target[nm]
            w = word(addr)
            def low_addend(signed):
                near = [a for a in los.get(nm, []) if addr < a <= addr + 0x20]
                v = (word(min(near)) & 0xffff) if near else 0
                return (v - 0x10000 if signed and v >= 0x8000 else v)
            if rtype == 4:                                                                         # HI16 (paired with an unsigned low half, e.g. ori)
                add = ((w & 0xffff) << 16) + low_addend(False)
                w = (w & 0xffff0000) | (((s + add) >> 16) & 0xffff)
            elif rtype == 6:                                                                       # HA16 (paired with a signed low half, e.g. lwz/addi)
                add = ((w & 0xffff) << 16) + low_addend(True)
                w = (w & 0xffff0000) | (((s + add + 0x8000) >> 16) & 0xffff)
            elif rtype == 5:                                                                       # LO16: only its own baked half is the addend
                w = (w & 0xffff0000) | ((s + (w & 0xffff)) & 0xffff)
            elif rtype == 3:                                                                       # BR24: bl/b to an external
                disp = s - addr
                assert -0x2000000 <= disp < 0x2000000
                w = (w & 0xfc000003) | (disp & 0x03fffffc)
            elif rtype == 0:    w = (s + w) & 0xffffffff                                           # VANILLA: a pointer in data (+ addend)
            elif rtype in (1, 13):  continue                                                       # PAIR / JBSR marker
            else:
                raise AssertionError('%s: unhandled external relocation type %d at 0x%x (%s)' % (self.label, rtype, addr, nm))
            struct.pack_into('>I', data, addr, w)
        return data, target

    def canon(self, addr):
        c = self._canon_cache.get(addr)
        if c is None:
            c = self._canon_cache[addr] = self._canon(addr)
        return c

    def canon_ptr(self, v):
        """a pointer argument into the kext's own image, named so the two builds compare: a C string by its text, a global by (symbol, offset)"""
        if v in self.addr2func and v >= 0x200:
            return ('fn', self.addr2func[v])
        if not (0x1000 <= v < self.size):
            return v
        for x in self.m.secs:
            if x['size'] and x['addr'] <= v < x['addr'] + x['size']:
                if x['name'] == '__text':
                    nm = self.addr2func.get(v)
                    return ('fn', nm) if nm else v
                if x['name'] == '__cstring':
                    d = bytes(self.data[v:v + 200]).split(b'\0')[0]
                    return ('str', d.decode('latin1'))
                if x['seg'] == '__DATA':
                    return self.canon(v)
                for sy in self.m.syms:                    # a named table / vtable in __const
                    pass
                return self._const_name(v, x)
        return v

    def _const_name(self, v, sec):
        if not hasattr(self, '_consts'):
            ids = {i + 1 for i, x in enumerate(self.m.secs) if x['seg'] == '__TEXT' and x['name'] != '__text'}
            self._consts = sorted((sy['value'], sy['name']) for sy in self.m.syms if (sy['type'] & 0x0e) == 0x0e and sy['sect'] in ids and sy['name'])
        import bisect
        i = bisect.bisect_right(self._consts, (v, '\uffff')) - 1
        if i >= 0 and self._consts[i][0] >= sec['addr']:
            return ('g', self._consts[i][1], v - self._consts[i][0])
        return v

    def _canon(self, addr):
        """a stable name for an address that is a global variable of the kext, so that the two builds (which lay their data out differently) can be
        compared: ('g', symbol, offset); any other address is returned unchanged"""
        for nm, (a, n) in getattr(self, 'common_cells', {}).items():
            if a <= addr < a + n:
                return ('g', nm, addr - a)
        if any(a <= addr < b for a, b in self.data_ranges):
            import bisect
            i = bisect.bisect_right(self.datasyms, (addr, '\uffff')) - 1
            if i >= 0:
                return ('g', self.datasyms[i][1], addr - self.datasyms[i][0])
        return addr


# ----------------------------------------------------------------------------------------------------------------------------------------------
# the machine

class Run:
    pass


class Machine:
    """one emulated side. `world` is a callable(machine) that builds the test objects; it must allocate in the same order on both sides."""

    def __init__(self, image, reg, seed, lazy='zero', mock_policy=None, limit=300000, stack_args=None, transparent=None):
        self.image, self.reg, self.seed, self.lazy, self.limit = image, reg, seed, lazy, limit
        self.transparent = re.compile(transparent) if transparent else None
        self.ignore_args = {}
        self.out_extents = {}       # Case.out_extents
        self.exclusive = set()      # functions that exist only in this image: the other build inlined them, so they run for real here
        self.stack_args = stack_args or {}
        self.mock_policy = mock_policy or default_mock
        self.uc = uc = Uc(UC_ARCH_PPC, UC_MODE_PPC32 | UC_MODE_BIG_ENDIAN)
        data, self.extern_target = image.instantiate(reg)
        self.patched = data
        uc.mem_map(0, image.size)
        uc.mem_write(0, bytes(data))
        uc.mem_map(STUB_BASE, STUB_SIZE)
        uc.mem_write(STUB_BASE, struct.pack('>I', BLR) * (STUB_SIZE // 4))
        uc.mem_map(DATA_BASE, 2 * PAGE)
        uc.mem_map(COMMON_BASE, COMMON_SIZE)
        for nm, base in image.vtable_externs.items():
            uc.mem_map(base, VTEXT_SIZE)
            for off in range(0, VTEXT_SIZE, 4):
                fam = nm in IOKIT_FAMILY_VTABLES
                slot = VTEXT_SLOTS.get(nm if not fam else '__ZTV9IOService', {}).get(off) or (('inherited IOService virtual +0x%x' % off) if fam else ('%s slot +0x%x' % (nm, off)))
                uc.mem_write(base + off, struct.pack('>I', reg.get(slot)))
        for i, k in enumerate(sorted(EXTERN_DATA)):
            uc.mem_write(DATA_BASE + 4 * i, struct.pack('>I', EXTERN_DATA[k]))
        uc.mem_map(STOP, PAGE)
        uc.mem_write(STOP, struct.pack('>I', BLR))
        uc.mem_map(STACK_TOP - STACK_SIZE, STACK_SIZE)
        self.arena_next = ARENA
        self.mapped = [(0, image.size), (STUB_BASE, STUB_SIZE), (DATA_BASE, 2 * PAGE), (COMMON_BASE, COMMON_SIZE), (STOP, PAGE), (STACK_TOP - STACK_SIZE, STACK_SIZE)]
        self.entry_patched = {}
        self.calls, self.writes, self.insns = [], [], 0
        self.visited = {}
        self.trail = []
        self.read_trace = None
        self.plain_words = False      # Case.plain_words
        self.want_snapshots = False   # --strict-calls: keep the memory visible at every call
        self.replay_reads = None      # register read results recorded from the other side, handed back in order
        self.replay_pos = 0
        self.hw = []                  # register windows: (base, end, model)
        self.events = []              # calls and register accesses, in order
        self.write_log = []           # [addr, size, old bytes, new bytes]
        self.raw_new = {}             # write_log index -> the new bytes before address-looking words are canonicalised (see _flush)
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
        if len(self.mapped) > 2000:                          # a loop sweeping through address space: a wild pointer, not a test
            if os.environ.get('DT_WILD'): print('WILD %s %s %x/%d pc=%x' % (self.image.label, 'map-sweep', addr, size, uc.reg_read(UC_PPC_REG_PC)), file=sys.stderr)
            self.bad_read = True
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
            self.raw_new[i] = ent[3]            # the bytes as stored, before a word that looks like an address into the image is replaced by the name of what it points at
            if ent[1] == 4 and STACK_TOP - STACK_SIZE <= struct.unpack('>I', ent[3])[0] < STACK_TOP and not (STACK_TOP - STACK_SIZE <= ent[0] < STACK_TOP):
                ent[3] = STACKPTR_MARK         # the address of a local of the function: differs between builds by construction
            elif ent[1] == 4 and not self.plain_words:
                v = struct.unpack('>I', ent[3])[0]
                if 0x1000 <= v < self.image.size:
                    c = self.image.canon_ptr(v)
                    if isinstance(c, tuple):   # the address of one of the kext's own globals / functions / strings: named, so the two layouts compare
                        ent[3] = struct.pack('>I', 0xfe000000 | (zlib.crc32(repr(c).encode()) & 0xffffff))
            if hwidx is not None:
                self.events[hwidx][3] = ent[3].hex()
                h = self._hw_of(ent[0])
                if h and h[1]:
                    h[1]('W', ent[0] - h[0], ent[1], ent[3])
            self.pending = None

    def _write(self, uc, access, addr, size, value, ud):
        self._flush()
        if any(a <= addr < b for a, b in self.ro):
            if os.environ.get('DT_WILD'): print('WILD %s %s %x/%d pc=%x' % (self.image.label, 'store-into-code', addr, size, uc.reg_read(UC_PPC_REG_PC)), file=sys.stderr)
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
        if self.replay_reads is not None and self.replay_pos < len(self.replay_reads) and len(self.replay_reads[self.replay_pos]) == size:
            uc.mem_write(addr, self.replay_reads[self.replay_pos])      # the device answers as it answered the stock function
        elif h and h[1]:
            data = h[1]('R', addr - h[0], size, None)
            if data is not None:
                uc.mem_write(addr, bytes(data))
        self.replay_pos += 1
        self.events.append(['R', addr - h[0], size, bytes(uc.mem_read(addr, size)).hex()])

    def _null_call(self, uc, addr, size, ud):
        if os.environ.get('DT_WILD'): print('WILD %s %s %x/%d pc=%x' % (self.image.label, 'null-call', addr, size, uc.reg_read(UC_PPC_REG_PC)), file=sys.stderr)
        self.bad_read = True              # a call through a null function pointer: a hole in the test world, not behaviour
        self.status = 'NULLCALL'; uc.emu_stop()

    def _barrier(self, uc, addr, size, ud):
        self._flush()
        self.events.append(['B', ud])

    def _read_code(self, uc, access, addr, size, value, ud):
        if self.own[0] <= addr < self.own[1]:
            return                # the function's own extent holds its jump tables
        if os.environ.get('DT_WILD'): print('WILD %s read %x/%d pc=%x' % (self.image.label, addr, size, uc.reg_read(UC_PPC_REG_PC)), file=sys.stderr)
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

    def _mid_function(self, addr):
        if not hasattr(self, '_fn_list'):
            self._fn_list = sorted((a, n) for n, a in self.image.funcs.items())
            self._fn_addrs = [a for a, n in self._fn_list]
        if self.own[0] <= addr < self.own[1] or addr >= self._fn_addrs[-1]:
            return False                  # the function itself (jump tables, local labels), or code past the last function (stub islands)
        i = bisect.bisect_right(self._fn_addrs, addr) - 1
        if i < 0 or self._fn_addrs[i] == addr:
            return False
        name = self._fn_list[i][1]
        if (self.transparent and self.transparent.search(name)) or name in self.exclusive:
            return False                  # a function that runs for real (not stubbed): its own blocks start mid-function
        return True

    def _block(self, uc, addr, size, ud):

        if addr & 3 or self._mid_function(addr):      # a soup value used as a function pointer (unaligned, or into the middle of ANOTHER function, whose bytes differ between the two images): a hole in the test world, not behaviour
            self.bad_read = True; self.status = 'NULLCALL'; uc.emu_stop(); return
        self.insns += size // 4
        self.visited[(addr, size)] = self.visited.get((addr, size), 0) + 1
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
        sp = uc.reg_read(UC_PPC_REG_1)
        vals, gi, fi = [], 0, 0
        for k in kinds:
            if k == 'f':
                fi += 1
                vals.append(('f', '%016x' % uc.reg_read(UC_PPC_REG_FPR0 + fi)))     # raw bits of the double in f<fi>
                continue
            if gi < 8:
                v = regs[gi]
            else:                                   # the 9th word and later are passed in the caller's frame, after the 56-byte linkage and home area
                v = struct.unpack('>I', bytes(uc.mem_read(sp + 0x38 + 4 * (gi - 8), 4)))[0]
            gi += 1
            if any(key in name and (gi - 1) in idx for key, idx in self.ignore_args.items()):
                vals.append('ignored'); continue
            vals.append(self.normalise(v, name, gi - 1, k))
        k = self.stub_count.get(name, 0); self.stub_count[name] = k + 1
        self.calls.append((name, tuple(vals), unknown))
        self._flush()
        self.events.append(['C', name, tuple(vals)])
        if self.want_snapshots:
            self.snapshots.append(self.memory_diff())
        for key, spec in self.out_extents.items():
            if key in name:
                for idx, n in spec.items():       # the callee's real output extent: fill it with a pattern first, so a caller whose local object is shorter is corrupted visibly
                    a = regs[idx] if idx < 8 else struct.unpack('>I', bytes(uc.mem_read(sp + 0x38 + 4 * (idx - 8), 4)))[0]
                    if 0x1000 <= a < 0xf0000000:
                        for off, ln in ([(0, n)] if isinstance(n, int) else n):       # n: bytes from the pointer, or [(offset, length), ...] for a callee that writes only parts of its record
                            uc.mem_write(a + off, bytes(((self.seed * 31 + 0x5a + 7 * (off + i)) & 0xff) | 1 for i in range(ln)))
        uc.reg_write(UC_PPC_REG_3, self.mock_policy(self, name, k) & 0xffffffff)

    def normalise(self, v, name, index, kind='p'):
        """a pointer into the function's own stack frame differs between the two builds (their frames differ), so it is replaced by the contents it points
        to - but only when the case says how many bytes the callee reads there (Case.stack_args: {callee substring: {arg index: bytes}});
        otherwise just a marker, because the bytes around a local are not part of the contract"""
        if STACK_TOP - STACK_SIZE <= v < STACK_TOP:
            n = 0
            for key, spec in self.stack_args.items():
                if key in name:
                    n = spec.get(index, 0)
            return ('stack', bytes(self.uc.mem_read(v, min(n, STACK_TOP - v))).hex() if n else '')
        return self.image.canon_ptr(v) if kind in ('p', 'this') else v      # an integer argument that happens to equal an address is just an integer

    # -- running -----------------------------------------------------------------------------------------------------------------------------
    def prepare(self, target_name):
        """redirect every other function of the image to its stub (the first instruction becomes `ba stub`)"""
        entry = self.image.funcs[target_name]
        later = [a for a in self.image.funcs.values() if a > entry]
        self.own = (entry, min(later) if later else self.image.size)
        for name, a in self.image.funcs.items():
            if name == target_name or (self.transparent and self.transparent.search(name)) or name in self.exclusive:
                continue
            s = self.reg.get(name)
            self.uc.mem_write(a, struct.pack('>I', 0x48000002 | s))      # ba s  (AA=1, LK=0)
        self.uc.hook_add(UC_HOOK_CODE, self._stub_hook, begin=STUB_BASE, end=STUB_BASE + STUB_SIZE - 1)
        self.uc.hook_add(UC_HOOK_CODE, self._stub_hook, begin=STOP, end=STOP + 3)
        if self.own[0] != 0:
            self.uc.hook_add(UC_HOOK_CODE, self._null_call, begin=0, end=3)
        for a in range(self.own[0], self.own[1], 4):      # barriers inside the function: eieio / sync / lwsync / isync
            w = struct.unpack('>I', self.patched[a:a + 4])[0]
            kind = {0x7c0006ac: 'eieio', 0x7c0004ac: 'sync', 0x7c2004ac: 'lwsync', 0x4c00012c: 'isync'}.get(w)
            if kind:
                self.uc.hook_add(UC_HOOK_CODE, self._barrier, begin=a, end=a + 3, user_data=kind)
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
            if i < 8:
                uc.reg_write(UC_PPC_REG_3 + i, v & 0xffffffff)
            else:                                   # the 9th word and later are passed in the caller's frame, after the 56-byte linkage and home area
                self.w32(ENTRY_SP + 0x38 + 4 * (i - 8), v)
        for i, v in enumerate(fargs or getattr(self, 'fargs', ())):       # floating-point arguments (a world sets `m.fargs = [1.0, 2.5]`): f1, f2, ... as doubles
            uc.reg_write(UC_PPC_REG_FPR1 + i, struct.unpack('>Q', struct.pack('>d', v))[0])
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
        lo, hi = STACK_TOP - STACK_SIZE, ENTRY_SP + CALLER_SCRATCH
        self.final_raw = {}
        for n, (addr, size, old, new) in enumerate(self.write_log):
            if new is None or lo <= addr < hi:
                continue
            raw = self.raw_new.get(n, new)
            for i in range(size):
                k = self.image.canon(addr + i)
                initial.setdefault(k, old[i]); final[k] = new[i]; self.final_raw[k] = raw[i]
        return {a: b for a, b in final.items() if b != initial[a]}

    def result(self):
        uc = self.uc
        r = Run()
        r.status, r.calls, r.insns = self.status, list(self.calls), self.insns
        r.bad_read = self.bad_read
        r.visited = dict(self.visited)
        r.cycles = sum(cnt * block_cost(self.patched, a, n) for (a, n), cnt in self.visited.items())
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
        r.writes_raw = dict(self.final_raw)
        r.write_order = [(self.image.canon(a), n, b) for a, n, o, b in self.write_log if not (STACK_TOP - STACK_SIZE <= a < ENTRY_SP + CALLER_SCRATCH)]
        r.events = [tuple(e) for e in self.events]
        r.snapshots = list(self.snapshots)
        r.fault = getattr(self, 'fault', '') if self.status == 'FAULT' else ''
        return r


_cost_cache = {}


def insn_cost(w):
    """a coarse PowerPC 970 (G5) cost in cycles of one instruction word, by its opcode class: not a measurement, a weighting that makes
    'ten more adds' and 'ten more divides' differ. Loads 3, stores 1, multiplies 4, divides 20, FP arithmetic 6 (divide 30), atomics 8, sync 30,
    eieio 10, SPR moves 3, everything else 1."""
    op = w >> 26
    if op in (32, 33, 34, 35, 40, 41, 42, 43, 46, 48, 49, 50, 51): return 3
    if op in (36, 37, 38, 39, 44, 45, 47, 52, 53, 54, 55): return 1
    if op == 7: return 4
    if op in (59, 63):
        xo = (w >> 1) & 0x1f
        return 30 if xo == 18 else 6
    if op == 31:
        xo = (w >> 1) & 0x3ff
        if xo in (23, 87, 279, 343, 534, 535, 599, 20, 103, 55, 119, 311, 375, 311): return 3 if xo != 20 else 8
        if xo in (151, 215, 407, 662, 663, 727, 247, 183, 439): return 1
        if xo == 150: return 8
        if xo in (235, 75, 11): return 4
        if xo in (491, 459, 395, 363): return 20
        if xo == 598: return 30
        if xo == 854: return 10
        if xo in (339, 467, 144, 19): return 3
    return 1


def block_cost(image_bytes, addr, size):
    key = (id(image_bytes), addr, size)
    if key not in _cost_cache:
        _cost_cache[key] = sum(insn_cost(struct.unpack('>I', bytes(image_bytes[a:a + 4]))[0]) for a in range(addr, addr + size, 4))
    return _cost_cache[key]


_ret_kind_cache = {}
BOOL_METHODS = {'init', 'start', 'attach', 'open', 'isOpen', 'initWithTask', 'initWithOptions', 'matchPropertyTable', 'isInactive', 'isParent', 'inPlane',
                'setProperty', 'serializeProperties', 'handleOpen', 'handleIsOpen', 'terminate', 'requestTerminate', 'willTerminate', 'didTerminate'}


def callee_ret_kind(name):
    """'void' | 'bool' | 'ptr' | 'status' (IOReturn) | 'int' for a mocked callee, from its declaration in Headers/<Class>.h ('int' when unknown)"""
    base = name.split(' [vcall')[0]
    if base in EXTERN_RET:
        return EXTERN_RET[base]
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
    if kind == 'int' and mm and mm.group(2) in BOOL_METHODS:      # IOKit / libkern virtuals declared outside the kext's headers
        kind = 'bool'
    _ret_kind_cache[base] = kind
    return kind


def default_mock(machine, name, k):
    """what a mocked callee returns: deterministic in (seed, callee, call index) and inside the callee's return domain (a `bool` callee returns 0 or 1,
    a pointer-returning one a fresh random object), identical on both sides"""
    r = random.Random((machine.seed << 20) ^ zlib.crc32(name.encode()) ^ (k * 2654435761 & 0xffffffff))
    kind = callee_ret_kind(name)
    if kind == 'void': return 0
    if kind == 'arg0': return machine.uc.reg_read(UC_PPC_REG_3)
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

# functions that are NOT mocked but run for real on both sides: one build may inline them and the other call them, which a mock cannot tell apart from a
# difference. Constructors and destructors are the usual case (`new T` expands the constructor inline in the stock code).
DEFAULT_TRANSPARENT = r'(C[12]E|D[012]E)'

class Case:
    """one function, many inputs.
    function  'Class::method' (add `signature` to choose between overloads: a substring of the demangled name, e.g. '(unsigned long, eDoSwap')
    ret       'void' | 'u32' | 'bool' | 'u16' | 's32' ...: what is compared of r3 (void: nothing)
    world     callable(machine, rng) -> list of arguments (register values, `this` first); it builds the objects in the machine
    seeds     how many seeds to run (each seed gives different random inputs and mock returns)
    lazy      'zero' (default) or 'random': contents of memory the test did not set up
    limit     instruction budget per run
    mock      callable(machine, callee name, call index) -> value a mocked callee returns (default: seeded choice among typical status values)
    replay    True: the register reads the stock function received are handed back, in order, to the rebuilt one (so a device that answers differently
              from the plain-memory window - a status bit that changes - cannot make the two sides differ; a different read PATTERN still fails)
    ignore_args {callee name substring: [argument indexes]} not compared: the call site never sets that register (the callee's declared parameter is unused, so
              the register holds whatever was left in it)
    stack_args  {callee name substring: {argument index: bytes}} for pointers to locals that the callee reads (their contents are compared)
    out_extents {callee name substring: {argument index: bytes | [(offset, length), ...]}} the REAL bytes the callee writes through that pointer argument (index 8 and up = stack-passed). Before the (mocked) callee runs,
              that range is filled with a pattern, so a caller whose local object is shorter than the callee's real output corrupts its neighbours - which, unlike
              the mock's own writes, depends on the compiler's stack layout and shows up as a stock/rebuilt difference (2026-10-17 hot-swap panic: IOPixelInformation).
              Declare it for every callee that fills a caller-local struct.
    plain_words True: a stored word that falls inside the kext image's address range is a NUMBER (a size, an offset, a packet word), not a pointer to the
              kext's own data, and is compared as such (default: such words are compared by the name of what they point at, because the two builds lay
              their data out differently)
    """
    def __init__(self, function, world, ret='u32', seeds=16, signature=None, lazy='zero', limit=150000, mock=None, name=None, stack_args=None, replay=False, transparent=DEFAULT_TRANSPARENT, ignore_args=None, plain_words=False, out_extents=None, seconds=None):
        self.seconds = seconds        # wall-clock allowance for this case (default --case-seconds): a polling loop of 100000 iterations is slow in the emulator
        self.ignore_args = ignore_args or {}
        self.out_extents = out_extents or {}
        self.plain_words = plain_words
        self.transparent = transparent
        self.replay = replay
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
    if st.status == 'TIMEOUT' and rb.status == 'TIMEOUT' and not (st.bad_read or rb.bad_read):
        for i in range(min(len(st.events), len(rb.events))):         # both ran out of budget: the observable part so far must still agree
            if st.events[i] != rb.events[i]:
                return ['before the budget ran out, event #%d differs: stock %s, rebuilt %s' % (i, fmt_event(st.events[i]), fmt_event(rb.events[i]))]
    inc = lambda o: o.status in ('TIMEOUT', 'NULLCALL') or o.bad_read
    if inc(st) != inc(rb):                    # one side completes, the other runs away or reads a wild pointer: that is a divergence, not an unusable input
        return ['only %s finished: stock %s%s, rebuilt %s%s' % ('rebuilt' if inc(st) else 'stock', st.status, ' (wild read)' if st.bad_read else '', rb.status, ' (wild read)' if rb.bad_read else '')]
    if inc(st) or inc(rb):
        return ['INCONCLUSIVE']          # budget exceeded, or a wild pointer in the test world (a read of machine code as data, a store into it): not comparable
    if st.status == 'FAULT' and rb.status == 'FAULT':
        # both dereferenced a wild pointer the test world handed them: the state they leave behind is not a result, but what they did BEFORE it
        # (calls and register accesses, which are the observable part) still must agree up to the point where the shorter one stopped
        for i in range(min(len(st.events), len(rb.events))):
            if st.events[i] != rb.events[i]:
                return ['before the fault, event #%d differs: stock %s, rebuilt %s' % (i, fmt_event(st.events[i]), fmt_event(rb.events[i]))]
        return ['INCONCLUSIVE']
    if st.status != rb.status:
        probs.append('ends differently: stock %s%s, rebuilt %s%s' % (st.status, ' (%s)' % st.fault if st.fault else '', rb.status, ' (%s)' % rb.fault if rb.fault else ''))
        return probs
    # hardware register accesses, interleaved with the calls: exact
    if any(e[0] in 'RWB' for e in st.events + rb.events):
        for i in range(max(len(st.events), len(rb.events))):
            a = st.events[i] if i < len(st.events) else None
            b = rb.events[i] if i < len(rb.events) else None
            if a != b:
                probs.append('HARDWARE access pattern differs at event #%d: stock %s, rebuilt %s' % (i, fmt_event(a), fmt_event(b)))
                break
    if strict_calls:
        for i, (a, b) in enumerate(zip(st.snapshots, rb.snapshots)):
            if a != b:
                keys = sorted(set(a) | set(b), key=str); d = [k for k in keys if a.get(k) != b.get(k)]
                probs.append('memory visible to call #%d differs at %d byte(s), first %s' % (i, len(d), fmt_key(d[0])))
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
    # a word that is an address into one kext image is compared by the name of its target; a plain number that happens to equal an address in ONE of the two
    # layouts is then named on that side only. Such a byte is not a difference when both sides stored the same raw bytes.
    d = [(k, st.writes.get(k), rb.writes.get(k)) for k in sorted(set(st.writes) | set(rb.writes), key=str) if st.writes.get(k) != rb.writes.get(k)]
    d = [x for x in d if st.writes_raw.get(x[0]) != rb.writes_raw.get(x[0])]
    if d:
        probs.append('memory left behind differs at %d byte(s), first: %s' % (len(d), ', '.join('%s stock %s rebuilt %s' % (fmt_key(k), hexs(a), hexs(b)) for k, a, b in d[:4])))
    elif strict_order and st.write_order != rb.write_order:
        probs.append('same final memory but different write order/granularity (stock %d stores, rebuilt %d)' % (len(st.write_order), len(rb.write_order)))
    for a in rb.abi:
        if a not in st.abi:
            probs.append('rebuilt: %s (the stock function does not)' % a)
    return probs


def fmt_key(k):
    return '%s+0x%x' % (k[1], k[2]) if isinstance(k, tuple) else '0x%x' % k


def fmt_event(e):
    if e is None: return '<none>'
    if e[0] == 'C': return 'call ' + fmt_call((e[1], e[2], False))
    if e[0] == 'B': return 'barrier ' + str(e[1])
    return '%s +0x%x/%d %s' % ('write' if e[0] == 'W' else 'read', e[1], e[2], e[3])


def hexs(v):
    if v is None: return 'none'
    if isinstance(v, str): return v
    if isinstance(v, tuple) and v and v[0] == 'f': return 'float:' + v[1]
    if isinstance(v, tuple): return '(' + ','.join(hexs(x) for x in v) + ')'
    return '0x%x' % v


def fmt_call(c):
    if c is None: return '<none>'
    name, args, unk = c
    d = demangle_all([name.split(' [vcall')[0]]).get(name.split(' [vcall')[0], name)
    return '%s(%s)%s' % (name if ' [vcall' in name else d, ', '.join(('stack:' + a[1][:16] + '..') if isinstance(a, tuple) and a[0] == 'stack' else hexs(a) for a in args), ' [arity unknown]' if unk else '')


def uncovered_ranges(runs):
    """[start, end) byte offsets from the function's entry of the instruction runs no run executed (block granularity)"""
    vis, own, entry = set(), None, None
    for r in runs:
        own = r.own; entry = getattr(r, 'entry', None) or own[0]
        for a, n in r.visited:
            if own[0] <= a < own[1]:
                vis.update(range(a, min(a + n, own[1]), 4))
    if not own: return []
    out, cur = [], None
    for a in range(own[0], own[1], 4):
        if a in vis:
            if cur: out.append(cur); cur = None
        elif cur: cur[1] = a + 4 - own[0]
        else: cur = [a - own[0], a + 4 - own[0]]
    if cur: out.append(cur)
    return out


def coverage(runs):
    """fraction of the function's instructions executed in at least one run (block granularity), over runs that were usable"""
    vis, own = set(), None
    for r in runs:
        own = r.own
        for a, n in r.visited:
            if own[0] <= a < own[1]:
                vis.update(x - own[0] for x in range(a, min(a + n, own[1]), 4))
    return vis, ((own[1] - own[0]) if own else 0)


def coverage(runs):
    """fraction of the function's instructions executed in at least one run (block granularity), over runs that were usable"""
    vis, size = coverage_set(runs)
    return (len(vis) * 4 / float(size)) if size else 0.0


def ranges_of(offsets):
    out = []
    for o in sorted(offsets):
        if out and o == out[-1][1]: out[-1][1] = o + 4
        else: out.append([o, o + 4])
    return out


def coverage_set(runs):
    """(set of executed instruction offsets from the function entry, function size in bytes)"""
    vis, own = set(), None
    for r in runs:
        own = r.own
        for a, n in r.visited:
            if own[0] <= a < own[1]:
                vis.update(x - own[0] for x in range(a, min(a + n, own[1]), 4))
    return vis, ((own[1] - own[0]) if own else 0)


def ranges_of(offsets):
    out = []
    for o in sorted(offsets):
        if out and o == out[-1][1]: out[-1][1] = o + 4
        else: out.append([o, o + 4])
    return out


def uncovered(runs):
    """the instruction ranges [(first, last_exclusive), ...] of the function (offsets from its start) that no usable run executed - for hand-world work"""
    vis, own = set(), None
    for r in runs:
        own = r.own
        for a, n in r.visited:
            if own[0] <= a < own[1]:
                vis.update(range(a, min(a + n, own[1]), 4))
    if not own: return []
    out, cur = [], None
    for a in range(own[0], own[1], 4):
        if a in vis:
            if cur: out.append((cur[0] - own[0], a - own[0])); cur = None
        elif cur is None: cur = [a]
    if cur: out.append((cur[0] - own[0], own[1] - own[0]))
    return out


def print_uncovered(case, runs, img, sym):
    """DIFFTEST_UNCOVERED=1: the instruction ranges (offsets from the entry of the stock function) no run executed, to see what a hand world still has to reach"""
    vis, own = set(), None
    for r in runs:
        own = r.own
        for a, n in r.visited:
            if own[0] <= a < own[1]:
                vis.update(range(a, min(a + n, own[1]), 4))
    if not own: return
    entry, miss, cur = img.funcs[sym], [], None
    for a in range(own[0], own[1], 4):
        if a in vis:
            if cur: miss.append(cur); cur = None
        elif cur: cur[1] = a
        else: cur = [a, a]
    if cur: miss.append(cur)
    sys.stderr.write('UNCOVERED %s (stock, offsets from entry): %s\n' % (case.name, ' '.join('%x-%x' % (a - entry, b - entry) for a, b in miss)))
    sys.stderr.flush()



def run_case(case, stock, rebuilt, reg, verbose=False, strict_order=False, strict_calls=False):
    results = []
    cyc = [0, 0]
    all_runs = ([], [])
    sym_s = find_symbol(stock, case.function, case.signature)
    sym_r = find_symbol(rebuilt, case.function, case.signature)
    for seed in range(case.seeds):
        outs = []
        for img, sym in ((stock, sym_s), (rebuilt, sym_r)):
            m = Machine(img, reg, seed, lazy=case.lazy, mock_policy=case.mock, limit=case.limit, stack_args=case.stack_args, transparent=case.transparent)
            m.ignore_args = case.ignore_args
            m.out_extents = case.out_extents
            m.plain_words = case.plain_words
            m.want_snapshots = strict_calls
            m.exclusive = (set(stock.funcs) - set(rebuilt.funcs)) if img is stock else (set(rebuilt.funcs) - set(stock.funcs))
            if case.replay and outs:
                m.replay_reads = [bytes.fromhex(e[3]) for e in outs[0].events if e[0] == 'R']
            rng = random.Random(seed * 7919 + zlib.crc32(case.name.encode()))
            kinds = signature_of(sym)[1] or []
            args = case.world(m, rng, kinds) if getattr(case.world, '__code__', None) and case.world.__code__.co_argcount >= 3 else case.world(m, rng)
            out = m.call(sym, args)
            outs.append(out); all_runs[len(outs) - 1].append(out)
        probs = compare(case, outs[0], outs[1], strict_order, strict_calls)
        case.hw_events = getattr(case, 'hw_events', 0) + sum(1 for e in outs[0].events if e[0] in 'RW')
        if probs != ['INCONCLUSIVE'] and outs[0].status == 'RET' and outs[1].status == 'RET':
            cyc[0] += outs[0].cycles; cyc[1] += outs[1].cycles      # only runs both sides finished: the two sums are comparable
        results.append((seed, [] if probs == ['INCONCLUSIVE'] else probs, outs[0].insns, outs[1].insns, 'TIMEOUT' if ((probs == ['INCONCLUSIVE'] and (outs[0].status in ('TIMEOUT', 'NULLCALL') or outs[1].status in ('TIMEOUT', 'NULLCALL') or outs[0].bad_read or outs[1].bad_read)) or (outs[0].status == 'FAULT' and outs[1].status == 'FAULT' and probs == ['INCONCLUSIVE'])) else outs[0].status, len(outs[0].calls)))
    case.cov = (coverage(all_runs[0]), coverage(all_runs[1]))
    case.uncov = (uncovered_ranges(all_runs[0]), uncovered_ranges(all_runs[1]))
    case.vis = [coverage_set(all_runs[0]), coverage_set(all_runs[1])]
    case.cycles = (cyc[0], cyc[1])
    if os.environ.get('DIFFTEST_UNCOVERED'):
        print_uncovered(case, all_runs[0], stock, sym_s)
    return sym_s, results


def explain(case, stock, rebuilt, reg, seed):
    for img in (stock, rebuilt):
        sym = find_symbol(img, case.function, case.signature)
        m = Machine(img, reg, seed, lazy=case.lazy, mock_policy=case.mock, limit=case.limit, stack_args=case.stack_args, transparent=case.transparent)
        m.ignore_args = case.ignore_args
        m.out_extents = case.out_extents
        m.plain_words = case.plain_words
        m.exclusive = (set(stock.funcs) - set(rebuilt.funcs)) if img is stock else (set(rebuilt.funcs) - set(stock.funcs))
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
        print('  stores: ' + ' '.join('%x/%d=%s' % (a, n, (b or b'').hex()) for a, n, o, b in m.write_log if not (STACK_TOP - STACK_SIZE <= a < STACK_TOP))[:1500])


def load_cases(path):
    spec = importlib.util.spec_from_file_location('difftest_cases_' + os.path.basename(path).replace('.', '_'), path)
    mod = importlib.util.module_from_spec(spec)
    sys.path.insert(0, os.path.dirname(os.path.abspath(path)))
    spec.loader.exec_module(mod)
    return mod.CASES


def evaluate(case, stock, rebuilt, reg, verbose, strict_order, strict_calls):
    """run one case and return (verdict, report lines, report dict)"""
    try:
        sym, res = run_case(case, stock, rebuilt, reg, verbose, strict_order, strict_calls)
    except LookupError as e:
        return 'ERROR', ['ERROR  %s: %s' % (case.name, e)], None
    fails = [r for r in res if r[1]]
    inconclusive = [r for r in res if r[4] == 'TIMEOUT' and not r[1]]
    res = [r for r in res if not (r[4] == 'TIMEOUT' and not r[1])]
    si = sum(r[2] for r in res); ri = sum(r[3] for r in res)
    cs, cr = case.cycles
    ratio = (cr / cs) if cs else ((ri / si) if si else 0)
    reached = sum(1 for r in res if r[5] > 0)
    verdict = 'PASS' if not fails else 'FAIL'
    if not res:
        verdict = 'NO-RESULT'; fails = [(0, ['no run finished: every input made the function exceed the budget or touch a wild pointer'])]
    lines = ['%s  %-58s %2d/%2d runs identical   est. cycles stock %d rebuilt %d (x%.2f)   cov %d%%/%d%%   runs with calls %d%s%s' % (
        verdict, case.name, len(res) - len(fails), len(res), cs, cr, ratio, round(100 * case.cov[0]), round(100 * case.cov[1]), reached,
        ('   register accesses %d' % case.hw_events) if getattr(case, 'hw_events', 0) else '',
        ('   (%d inconclusive: budget exceeded or wild pointer)' % len(inconclusive)) if inconclusive else '')]
    if os.environ.get('DT_UNCOV'):
        for lab, u in zip(('stock', 'rebuilt'), case.uncov):
            lines.append('       uncovered %s: %s' % (lab, ' '.join('%x-%x' % r for r in u)))
    if ratio > 1.5 or (ratio and ratio < 0.5):
        lines.append('       note: estimated-cycle ratio x%.2f' % ratio)
    for seed, probs, *_ in fails[:3 if not verbose else 99]:
        lines.append('       seed %d: %s' % (seed, '; '.join(probs)))
    rep = dict(case=case.name, symbol=sym, verdict=verdict, runs=len(res), failures=len(fails), inconclusive=len(inconclusive),
               insns_stock=si, insns_rebuilt=ri, cycles_stock=cs, cycles_rebuilt=cr, coverage_stock=case.cov[0], coverage_rebuilt=case.cov[1],
               register_accesses=getattr(case, 'hw_events', 0), function=case.function, size_stock=case.vis[0][1], size_rebuilt=case.vis[1][1], visited_stock=ranges_of(case.vis[0][0]), visited_rebuilt=ranges_of(case.vis[1][0]), uncovered_stock=getattr(case, 'uncov', ([], []))[0], uncovered_rebuilt=getattr(case, 'uncov', ([], []))[1], problems=[dict(seed=sd, problems=pb) for sd, pb, *_ in fails])
    return verdict, lines, rep


_G = {}


class CaseTimeout(Exception):
    pass


def _work(i):
    import signal
    case = _G['cases'][i]
    def on_alarm(sig, frm):
        raise CaseTimeout()
    signal.signal(signal.SIGALRM, on_alarm)
    signal.alarm(case.seconds or _G['case_seconds'])
    try:
        return i, evaluate(case, _G['stock'], _G['rebuilt'], _G['reg'], *_G['opts'])
    except CaseTimeout:
        return i, ('NO-RESULT', ['NO-RESULT  %-58s the harness gave up after %ds (a run is too slow: lower Case.limit or fix the world)' % (case.name, case.seconds or _G['case_seconds'])], None)
    finally:
        signal.alarm(0)


def main():
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--stock', default=STOCK_DEFAULT, help='shipped kext binary (or $STOCK_KEXT)')
    ap.add_argument('--rebuilt', default=REBUILT_DEFAULT, help='rebuilt kext binary (or $REBUILT_KEXT; default build/difftest/rebuilt.bin)')
    ap.add_argument('-f', '--filter', default='')
    ap.add_argument('-v', '--verbose', action='store_true')
    ap.add_argument('-j', '--jobs', type=int, default=1, help='run cases in this many processes')
    ap.add_argument('--strict-order', action='store_true', help='also require the same order and width of ALL stores (register accesses are always strict)')
    ap.add_argument('--strict-calls', action='store_true', help='also require the memory a callee could observe (everything written so far) to be the same at every call')
    ap.add_argument('--case-seconds', type=int, default=120, help='give up on a case that takes longer than this (wall clock)')
    ap.add_argument('--json')
    ap.add_argument('--explain', type=int, metavar='SEED', help='print the sequence of basic blocks each side executed for this seed (debugging a difference)')
    ap.add_argument('cases', nargs='+')
    a = ap.parse_args()
    if not a.stock:
        ap.error('give the shipped kext binary with --stock or $STOCK_KEXT')
    stock, rebuilt = Image(a.stock, 'stock'), Image(a.rebuilt, 'rebuilt')
    reg = StubRegistry()
    cases = [c for cf in a.cases for c in load_cases(cf) if not a.filter or a.filter in c.name]
    if a.explain is not None:
        for c in cases:
            explain(c, stock, rebuilt, reg, a.explain)
        return 0
    opts = (a.verbose, a.strict_order, a.strict_calls)
    _G.update(cases=cases, stock=stock, rebuilt=rebuilt, reg=reg, opts=opts, case_seconds=a.case_seconds)
    if a.jobs > 1:
        import multiprocessing
        with multiprocessing.get_context('fork').Pool(a.jobs) as pool:
            results = dict(pool.imap_unordered(_work, range(len(cases))))
    else:
        results = dict(_work(i) for i in range(len(cases)))
    report, bad, counts = [], 0, {}
    for i in range(len(cases)):
        verdict, lines, rep = results[i]
        print('\n'.join(lines))
        counts[verdict] = counts.get(verdict, 0) + 1
        if verdict != 'PASS': bad += 1
        if rep: report.append(rep)
    if a.json:
        json.dump(report, open(a.json, 'w'), indent=1)
    print('%d case(s): %s' % (len(cases), ', '.join('%d %s' % (v, k) for k, v in sorted(counts.items()))))
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
