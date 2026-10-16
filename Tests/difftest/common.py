"""Shared world builders for the differential function tests (see Tools/difftest/difftest.py).

A world builder allocates the objects a function works on inside the emulated machine and returns the register arguments. It must make the same
allocations in the same order on both sides, and take every random choice from the `rng` it is given."""
import struct


def word(rng):
    """a 32-bit value with the distribution that makes both sides of typical branches reachable"""
    return rng.choice([0, 0, 0, 1, 1, 2, 3, 4, 0x10, 0x20, 0xff, 0xffff, 0x1000, 0x10000, 0xffffffff, 0x80000000, rng.getrandbits(32)])


def small(rng, hi=4):
    return rng.randrange(hi + 1)


def fill_words(m, addr, nbytes, rng):
    m.uc.mem_write(addr, b''.join(struct.pack('>I', word(rng)) for _ in range(nbytes // 4)))


def surface_world(m, rng, surface_class='ATIR500Surface'):
    """a surface object (`this`) with a vtable, an accelerator and the per-panel counts in a sane range; everything else random.
    returns (SELF, ACCEL)"""
    SELF = m.alloc(0xe00)
    ACCEL = m.alloc(0x1000)
    fill_words(m, SELF, 0xe00, rng)
    fill_words(m, ACCEL, 0x1000, rng)
    m.w32(SELF, m.vtable(surface_class))
    m.w32(SELF + 0xd50, ACCEL)                       # the accelerator
    m.w32(ACCEL, m.vtable('ATIRadeonX1000'))         # virtual calls on it are recorded by name
    m.w32(ACCEL + 0xcc, rng.choice([0, 1, 2, 2]))    # panel count
    for i in range(2):
        m.w32(ACCEL + 0x114 + 4 * i, rng.choice([0, 1, 1]))   # buffers per panel
    m.w32(ACCEL + 0x840, ACCEL + 0x900)              # the command lock
    m.w32(SELF + 0xc14, rng.choice([0, 1, 0xffff]))  # the panel this surface is on
    # the per-attachment buffer table (+0xb70, indexed by format code) points into the surface's own 23-entry buffer array (+0xa8, stride 0x78)
    for i in range(0, 0x28, 4):
        m.w32(SELF + 0xb70 + i, SELF + 0xa8 + 0x78 * rng.randrange(6))
    m.w32(SELF + 0xb94, SELF + 0xa8 + 0x78 * rng.randrange(6))
    # the accelerator's list of surfaces (head at ACCEL+0x5c) is doubly linked through each surface's +0x9c (prev) / +0xa0 (next)
    nodes = [m.alloc(0x100) for _ in range(3)]
    for n in nodes:
        fill_words(m, n, 0x100, rng)
    m.w32(SELF + 0x9c, rng.choice(nodes)); m.w32(SELF + 0xa0, rng.choice(nodes))
    m.w32(ACCEL + 0x5c, rng.choice([SELF, nodes[0], nodes[1]]))
    for n in nodes:
        m.w32(n + 0x9c, rng.choice(nodes + [SELF])); m.w32(n + 0xa0, rng.choice(nodes + [SELF]))
    return SELF, ACCEL


def auto_args(m, rng, kinds, this):
    """arguments for a call from its parameter kinds (difftest.signature_of): 'p' -> null or a fresh random object, 'i' -> a typical integer"""
    args = [this]
    for k in kinds[1:]:
        if k == 'p':
            o = m.alloc(0x200); fill_words(m, o, 0x200, rng); args.append(o)   # never null: null handling is tested by hand where a function checks for it
        elif k == 'f':
            args.append(0)
        else:
            args.append(rng.choice([0, 0, 1, 2, 3, 4, 8, 0x10, 0x44, 0x100, 0xffff, word(rng), word(rng)]))
    return args


def auto_surface(m, rng, kinds):
    SELF, ACCEL = surface_world(m, rng)
    return auto_args(m, rng, kinds, SELF)


def return_kind(header_path, method):
    """'void' | 'bool' | 'u32' from the declaration of `method` in a class header"""
    import re
    for ln in open(header_path):
        mm = re.match(r'^\s*(?:virtual\s+)?((?:unsigned\s+)?[A-Za-z_][\w:]*[\s\*]+)%s\s*\(' % re.escape(method), ln)
        if mm:
            t = mm.group(1).strip()
            return 'void' if t == 'void' else ('bool' if t == 'bool' else 'u32')
    return 'u32'


def object_with_vtable(m, rng, cls, size=0x400):
    o = m.alloc(size)
    fill_words(m, o, size, rng)
    m.w32(o, m.vtable(cls))
    return o


def context_lists(m, rng, SELF):
    """the surface's bound-context lists: GL (+0x88) and 2D (+0x8c) contexts linked through +0x84 (requirement bits at +0x8c), and the DVD context
    (+0x90). Which list holds which class is not established (see IOATIR500Surface.h); the vtable only decides the names of virtual calls."""
    def chain(cls):
        head = 0
        for _ in range(rng.choice([0, 1, 2, 3])):
            n = object_with_vtable(m, rng, cls)
            m.w32(n + 0x84, head)
            m.w32(n + 0x8c, rng.choice([0, 1, 2, 4, 0x20, 0x30000000]))
            head = n
        return head
    m.w32(SELF + 0x88, chain('ATIR500GLContext'))
    m.w32(SELF + 0x8c, chain('ATIR5002DContext'))
    dvd = 0
    if rng.random() < 0.5:
        dvd = object_with_vtable(m, rng, 'ATIR500DVDContext')
    m.w32(SELF + 0x90, dvd)
    # +0xbcc: a list of buffer descriptors linked through +0x54 with a type code at +0x58
    head = 0
    for _ in range(rng.choice([0, 1, 2])):
        n = m.alloc(0x100); fill_words(m, n, 0x100, rng)
        m.w32(n + 0x54, head); m.w32(n + 0x58, rng.choice([1, 2, 3, 4, 7, 8, 0xa, 0xb, 0x11]))
        head = n
    m.w32(SELF + 0xbcc, head)


def surface_with_contexts(m, rng, kinds):
    SELF, ACCEL = surface_world(m, rng)
    context_lists(m, rng, SELF)
    return auto_args(m, rng, kinds, SELF)


def texture_buffer(m, rng, SELF):
    """a buffer record as delete_buffer_backing sees it: +4 flag, +8 backing object, +0x14 header, +0x24/+0x28 ring links"""
    b = m.alloc(0xc0); fill_words(m, b, 0xc0, rng)
    m.w32(b + 4, rng.choice([0, 1, 0x1000]))
    m.w32(b + 8, object_with_vtable(m, rng, 'IOATIR500Surface', 0x100))
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(b + 0x14, hdr)
    ring = m.alloc(0x40); fill_words(m, ring, 0x40, rng)
    m.w32(b + 0x24, ring); m.w32(b + 0x28, ring)
    return b


class RegisterFile:
    """a minimal device model for a register window: remembers what was written (by the bytes at that offset) and returns it on a read; offsets never
    written read as `default(offset)`. Both sides get an identical one, so it only decides what the code under test sees."""
    def __init__(self, rng, default=None):
        self.rng, self.mem = rng, {}
        self.default = default or (lambda off: (off * 2654435761 + 0x1234567) & 0xffffffff)

    def __call__(self, kind, off, size, data):
        if kind == 'W':
            for i in range(size):
                self.mem[off + i] = data[i]
            return None
        out = bytearray()
        for i in range(size):
            if off + i in self.mem:
                out.append(self.mem[off + i])
            else:
                out.append((self.default(off & ~3) >> (8 * (3 - ((off + i) & 3)))) & 0xff)
        return bytes(out)


def accelerator_with_registers(m, rng, window=0x20000):
    """an accelerator object whose register window pointer (+0x860) is a register file; also +0x80 'hardware alive' flag and the command lock"""
    ACCEL = m.alloc(0x1000)
    fill_words(m, ACCEL, 0x1000, rng)
    m.w32(ACCEL, m.vtable('ATIRadeonX1000'))
    m.w8(ACCEL + 0x80, rng.choice([1, 1, 1, 0]))
    m.w32(ACCEL + 0x840, ACCEL + 0x900)
    m.w32(ACCEL + 0x860, m.mmio(window, RegisterFile(rng)))
    return ACCEL


# ---- generic worlds: a "pointer soup" -----------------------------------------------------------------------------------------------------------
# For code whose object layout is not documented, every field the code might dereference must still point at valid memory. The soup is a pool of
# objects whose words are mostly small integers, some zero, some typical values, and some pointers to LATER objects of the pool (so pointer chains are
# valid and end, and linked-list walks terminate). It is reproducible from the rng, hence identical on both sides.

OBJECT_SIZES = {'ATIRadeonX1000': 0xc60, 'ATIR500GLContext': 0x690, 'ATIR5002DContext': 0x12c, 'ATIR500DVDContext': 0x1e0, 'ATIR500Surface': 0xdbc,
                'ATIR500Memory': 0x14, 'IOATIR500Shared': 0x28}
CONCRETE = {'IOATIR500Accelerator': 'ATIRadeonX1000', 'IOATIR500GLContext': 'ATIR500GLContext', 'IOATIR5002DContext': 'ATIR5002DContext',
            'IOATIR500DVDContext': 'ATIR500DVDContext', 'IOATIR500Surface': 'ATIR500Surface'}
ACCEL_OFFSET = {'ATIR5002DContext': 0x94, 'ATIR500DVDContext': 0x8c, 'ATIR500Surface': 0xd50}     # where a context keeps its accelerator pointer


def soup_words(rng, n, pool, index=None):
    out = []
    for _ in range(n):
        r = rng.random()
        if r < 0.45: v = rng.randrange(0, 9)
        elif r < 0.60: v = 0
        elif r < 0.68: v = word(rng)
        else:
            later = pool if index is None else pool[index + 1:]
            v = (rng.choice(later) + 4 * rng.randrange(0, 8)) if later else rng.randrange(0, 9)
        out.append(v)
    return struct.pack('>%dI' % n, *out)


def make_pool(m, rng, n=10, size=0x400):
    pool = [m.alloc(size) for _ in range(n)]
    for i, o in enumerate(pool):
        m.uc.mem_write(o, soup_words(rng, size // 4, pool, i))
    return pool


def accelerator_object(m, rng, pool):
    """the accelerator: a soup object with its vtable, the hardware-alive flag, the command lock and a register window (device model: flip-flop)"""
    a = m.alloc(0x1000)
    m.uc.mem_write(a, soup_words(rng, 0x400, pool))
    m.w32(a, m.vtable('ATIRadeonX1000'))
    m.w8(a + 0x80, 1)
    m.w32(a + 0xcc, rng.choice([1, 2, 2]))
    for i in range(2): m.w32(a + 0x114 + 4 * i, rng.choice([0, 1, 1]))
    m.w32(a + 0x840, rng.choice(pool))
    m.w32(a + 0x860, m.mmio(0x20000, FlipFlopRegisters(rng)))
    return a


def generic_this(m, rng, cls):
    """returns (this, pool) for a method of `cls` (or of its base): a soup object of the concrete class with a vtable and, where known, an accelerator"""
    cls = CONCRETE.get(cls, cls)
    pool = make_pool(m, rng)
    if cls == 'ATIRadeonX1000':
        this = accelerator_object(m, rng, pool)
        m.alloc(0x200)                       # keep allocation parity with the other classes
        return this, pool
    size = (OBJECT_SIZES.get(cls, 0x400) + 0xfff) & ~0xfff
    this = m.alloc(size)
    m.uc.mem_write(this, soup_words(rng, OBJECT_SIZES.get(cls, 0x400) // 4, pool))
    m.w32(this, m.vtable(cls))
    if cls in ACCEL_OFFSET:
        m.w32(this + ACCEL_OFFSET[cls], accelerator_object(m, rng, pool))
    return this, pool


def soup_args(m, rng, kinds, this, pool):
    args = [this]
    for k in kinds[1:]:
        if k == 'p': args.append(rng.choice(pool))
        elif k == 'f': args.append(0)
        else: args.append(rng.choice([0, 0, 1, 2, 3, 4, 8, 0x10, 0x44, 0x100, 0xffff, word(rng)]))
    return args


def make_generic_world(cls):
    def world(m, rng, kinds):
        this, pool = generic_this(m, rng, cls)
        return soup_args(m, rng, kinds, this, pool)
    return world


class FlipFlopRegisters:
    """a device model that lets polling loops end: a register that has been written reads back what was written; one that has not been written
    answers its first read with a fixed per-offset value and later reads with a rotation of 0, all-ones, the top bit, 1 - so a wait for a bit to
    clear and a wait for a bit to set both terminate. Identical on both sides, so it only decides what the code under test sees."""
    SEQ = (None, 0, 0xffffffff, 0x80000000, 1, 0x1)

    def __init__(self, rng):
        self.written, self.count = {}, {}

    def __call__(self, kind, off, size, data):
        if kind == 'W':
            for i in range(size):
                self.written[off + i] = data[i]
            return None
        if all((off + i) in self.written for i in range(size)):
            return bytes(self.written[off + i] for i in range(size))
        k = self.count.get(off & ~3, 0); self.count[off & ~3] = k + 1
        seq = self.SEQ[k % len(self.SEQ)]
        base = (((off & ~3) * 2654435761) + 0x1234567) & 0xffffffff
        v = base if seq is None else seq
        return bytes((v >> (8 * (3 - ((off + i) & 3)))) & 0xff for i in range(size))
