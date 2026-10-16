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
