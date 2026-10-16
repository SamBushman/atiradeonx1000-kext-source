"""Hand-written worlds (fork D of #183): the 2D and DVD contexts, ATIR500Surface/IOATIR500Surface teardown and swap code.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_D.py   (needs STOCK_KEXT; see Tools/difftest/README.md)

Common idea: every pointer the function reaches is a real object (an object with the right vtable, so virtual calls are recorded by method name), every
list ends, every table index is in range - the generic 'pointer soup' world gets none of that right for code that walks object graphs."""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from common import word, object_with_vtable, surface_world, accelerator_with_registers


REL = {'vtable slot +0x18': [1, 2]}        # release() on an object of a class the vtable listing does not name: its extra argument registers hold leftovers


def new_mock(m, name, k):
    """OSObject::operator new returns a real (zeroed) block of the requested size; everything else the harness default"""
    if name.startswith('__ZN8OSObjectnw') or 'operator new' in name:
        if (m.seed * 2654435761 + k) % 7 == 3:
            return 0                                    # allocation failure
        return m.alloc(max(m.uc.reg_read(__import__('unicorn.ppc_const', fromlist=['x']).UC_PPC_REG_3), 0x10))
    if 'buffer_map_offset' in name:                        # (buffer, x, y, long*, long*, long* out): the third out pointer receives the row pitch
        from unicorn.ppc_const import UC_PPC_REG_9
        out = m.uc.reg_read(UC_PPC_REG_9)
        if out > 0x1000:
            m.w32(out, [64, 640, 1920, 2560][(m.seed + k) % 4])
        return [0, 0x100, 0x1000, 0x20000][(m.seed * 3 + k) % 4]
    if name.endswith('vtable slot +0x14c'):                # IOMemoryDescriptor::map(...): a mapping object, or nothing
        if (m.seed + k) % 5 == 4:
            return 0
        o = m.alloc(0x400)
        m.w32(o, m.vtable('IOATIR500Shared', 0x800))
        return o
    if name.endswith('vtable slot +0xd0'):                 # IOMemoryMap::getVirtualAddress()
        return 0x10000000
    if 'copy_to_buffer' in name:                          # fills in the VendorTransferBuffer (the caller's local, 10th argument) the caller reads afterwards
        from unicorn.ppc_const import UC_PPC_REG_1
        sp = m.uc.reg_read(UC_PPC_REG_1)
        ptr = m.r32(sp + 0x3c)
        if ptr > 0x1000:
            m.w32(ptr + 4, (m.seed + k) % 2)
        return 0
    if 'withOptions' in name:                              # IOBufferMemoryDescriptor::withOptions: a descriptor, or a failed allocation now and then
        # (the shipped allocAllSlaveSwapBuffers loops for ever in its failure clean-up - see its case - so a failure ends a run only at the budget)
        if (m.seed + k) % 12 == 11:
            return 0
        o = m.alloc(0x400)
        m.w32(o, m.vtable('IOATIR500Shared', 0x800))
        return o
    if name.endswith('vtable slot +0x188'):                # IOService::getProperty(const char*): an OSData-like object or nothing
        if (m.seed + k) % 4 == 3:
            return 0
        o = m.alloc(0x400)
        m.w32(o, m.vtable('IOATIR500Shared', 0x800))
        return o
    if name.endswith('vtable slot +0x100'):                # OSData::getBytesNoCopy(): the bytes
        o = m.alloc(0x40)
        m.w32(o, [8, 8, 0x18, 3, 0x28][(m.seed + k) % 5])
        return o
    if 'withAddress' in name or 'withPhysicalAddress' in name or 'removeMappingForDescriptor' in name:      # IOMemoryDescriptor factories: a releasable descriptor (or a failed allocation)
        if (m.seed + k) % 6 == 5:
            return 0
        o = m.alloc(0x400)
        m.w32(o, m.vtable('IOATIR500Shared', 0x800))
        return o
    if 'safeMetaCast' in name:                              # a successful cast hands the object back, a failed one (only when the object is null) returns 0
        from unicorn.ppc_const import UC_PPC_REG_3
        return m.uc.reg_read(UC_PPC_REG_3)
    return default_mock(m, name, k)


def clean_word(rng):
    """like common.word, but a 32-bit value whose zero-extended halves and whole stay clear of [0x1000, 0x100000): the harness reads a stored word that
    lands inside the kext image as a pointer to the kext's own data and compares it by NAME, which differs between the two builds for a value that is
    really just a number (0xffff & ~0x1f ...). The halves are below 0x1000 (or the high half is 0 / at least 0x10), so masks and shifts of 16-bit fields stay clear too."""
    r = rng.random()
    if r < 0.5:
        return rng.choice([0, 0, 0, 1, 1, 2, 3, 4, 8, 0x10, 0x20, 0xff, 0x7ff, 0xfff])
    hi = rng.choice([0, 0x10, 0x100, 0x800, 0xfff, rng.randrange(0x10, 0x1000)])
    lo = rng.choice([0, 1, 0x20, 0x100, 0x7ff, rng.randrange(0x1000)])
    return (hi << 16) | lo


def clean_fill(m, addr, nbytes, rng):
    m.uc.mem_write(addr, b''.join(struct.pack('>I', clean_word(rng)) for _ in range(nbytes // 4)))


fill_words = clean_fill          # every world of this file fills memory with numbers that cannot be mistaken for pointers into the kext


def obj(m, rng, cls, size=0x400):
    slot_signatures(m)
    o = m.alloc(size)
    fill_words(m, o, size, rng)
    m.w32(o, m.vtable(cls))
    return o


def slot_signatures(m):
    """vtable slots the listing does not name are registered by offset only, with an unknown arity; the ones this file's worlds call are IOKit virtuals"""
    m.reg.get('vtable slot +0x188', (2, ['this', 'p']))         # IOService::getProperty(const char *): the argument is a C string, compared by its text
    m.reg.get('vtable slot +0x100', (1, ['this']))              # OSData::getBytesNoCopy()
    m.reg.get('vtable slot +0x18', (1, ['this']))               # release()


def plain(m, rng, size=0x400, vt_size=0x800):
    """an object of a class this kext does not define (IOKit/libkern): word soup, and a vtable whose slots are named by offset"""
    slot_signatures(m)
    o = m.alloc(size)
    fill_words(m, o, size, rng)
    m.w32(o, m.vtable('IOATIR500Shared', vt_size))
    return o


def accel(m, rng, mmio=True):
    slot_signatures(m)
    """an accelerator with a vtable, hardware flag, command lock, optional register window, panel count"""
    a = accelerator_with_registers(m, rng) if mmio else obj(m, rng, 'ATIRadeonX1000', 0x1000)
    m.w32(a, m.vtable('ATIRadeonX1000'))
    m.w32(a + 0xcc, rng.choice([0, 1, 2]))
    m.w32(a + 0x840, a + 0x900)
    return a


def ctx2d(m, rng, cls='ATIR5002DContext'):
    """a 2D context: +0x94 accelerator, +0x88 shared, +0x80 next 2D context, +0xbc buffer, +0xa0 command buffer, +0xcc/+0xe4 two 0x18-byte panel records"""
    c = obj(m, rng, cls, 0x1000)
    A = accel(m, rng)
    m.w32(c + 0x94, A)
    return c, A


def w_2d_create_shared(m, rng):
    c, A = ctx2d(m, rng, 'ATIR5002DContext')
    return [c]


def w_2d_set_macrovision(m, rng):
    c, A = ctx2d(m, rng)
    # IOATIR5002DContext keeps `accelerator` as a member; the accelerator's per-panel framebuffer pointers are at +0xd4 + 0x20*i
    for i in range(2):
        m.w32(A + 0xd4 + 0x20 * i, rng.choice([0, plain(m, rng, 0x800)]))
    return [c, rng.choice([0, 1, 2, 3])]


def w_2d_free_all(m, rng):
    c, A = ctx2d(m, rng)
    m.w32(c + 0xfc, rng.choice([0, 1]))                         # the current panel record
    for i in range(2):
        m.w32(c + 0xd0 + 0x18 * i, rng.choice([0, 1, 2]))
        m.w32(c + 0xd4 + 0x18 * i, plain(m, rng))              # a releasable object
    m.w32(c + 0xbc, plain(m, rng))
    return [c]


def w_2d_stop(m, rng):
    c, A = ctx2d(m, rng, 'ATIR5002DContext')
    others = [obj(m, rng, 'ATIR5002DContext', 0x400) for _ in range(rng.choice([0, 1, 2]))]
    order = others[:]
    if rng.random() < 0.85:
        order.insert(rng.randrange(len(order) + 1), c)           # `c` is on the accelerator's list (nearly always)
    for a, b in zip(order, order[1:] + [0]):
        m.w32(a + 0x80, b)
    m.w32(A + 0x64, order[0] if order else 0)
    m.w32(A + 0x734, rng.choice([1, 2, 5]))
    m.w32(A + 0x78, rng.choice([0, c, others[0] if others else 0]))
    m.w32(c + 0x118, rng.choice([0, plain(m, rng)]))
    m.w32(c + 0x88, rng.choice([0, plain(m, rng)]))
    m.w32(c + 0xa0, rng.choice([0, plain(m, rng)]))
    m.w32(c + 0xbc, rng.choice([0, plain(m, rng)]))
    m.w32(c + 0xd4, plain(m, rng)); m.w32(c + 0xec, plain(m, rng))
    m.w32(c + 0xd0, rng.choice([0, 1])); m.w32(c + 0xe8, rng.choice([0, 1]))
    m.w32(c + 0xfc, rng.choice([0, 1]))
    m.w32(c + 0x100, rng.choice([0, obj(m, rng, 'ATIR500Surface', 0x1000)]))
    return [c, plain(m, rng)]


def surface_buffer_record(m, rng):
    """what the 2D submit code reads of a surface buffer record (ATIR500SurfaceBuffer, 0x78 bytes): size halves, pitch, format bytes"""
    r = m.alloc(0x100); fill_words(m, r, 0x100, rng)
    m.w32(r + 8, rng.choice([0, 0x20, 0x7ff, 0xfff, 0x20000000, 0x80000000, 0xfffffffe, 0xdeadbee0]))     # (a value in the image's address range would be read by the harness as a pointer to kext data)
    m.w16(r + 0x1c, rng.choice([0, 16, 640, 1920])); m.w16(r + 0x1e, rng.choice([0, 16, 480, 1080]))
    m.w8(r + 0x38, rng.randrange(4)); m.w8(r + 0x39, rng.randrange(4)); m.w8(r + 0x3b, rng.randrange(16))
    return r


def cmd_buffer(m, rng, words):
    """a context command buffer descriptor: +0x14 length in words, +0x1c flags, +0x20 the words"""
    b = m.alloc(0x400); fill_words(m, b, 0x400, rng)
    m.w32(b + 0x14, words)
    return b


def w_2d_submit(m, rng):
    c, A = ctx2d(m, rng, 'ATIR5002DContext')
    m.w32(A + 0xb74, clean_word(rng)); m.w32(A + 0x700, clean_word(rng))
    m.w32(A + 0x600, obj(m, rng, 'ATIR5002DContext', 0x100))             # head of the accelerator's texture list (a real node: the code links the texture buffer behind it)
    m.w32(A + 0x77c, clean_word(rng))
    src = cmd_buffer(m, rng, rng.choice([0, 1, 3, 8]))
    m.w32(src + 0x1c, rng.choice([0, 1, 1, 3]))                     # bit 0: the buffer was modified, copy it into the panel record's shadow
    m.w32(c + 0xc8, src)
    m.w32(c + 0xfc, rng.choice([0, 1]))
    for i in range(2):
        m.w32(c + 0xd0 + 0x18 * i, rng.choice([0, 0x100, 0x1000]))        # mapped size: 0 -> map_transfer_to_GART
        m.w32(c + 0xdc + 0x18 * i, word(rng))
        m.w32(c + 0xe0 + 0x18 * i, m.alloc(0x400))                       # the panel record's shadow command buffer
    t = 0
    if rng.random() < 0.7:
        t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w8(hdr + 0x14, rng.choice([0, 1]))
        m.w32(t + 0x14, hdr)
        for off in (0x24, 0x28):
            m.w32(t + off, obj(m, rng, 'ATIR5002DContext', 0x100))       # list neighbours (anything writable)
        m.w32(t + 0x48, rng.choice([0, 1]))
    m.w32(c + 0x114, t)
    s = obj(m, rng, 'ATIR500Surface', 0x1000)
    if rng.random() < 0.5:
        m.w32(c + 0x100, s)
        m.uc.mem_write(s + 0xa8, bytes(m.uc.mem_read(surface_buffer_record(m, rng), 0x78)))
    else:
        m.w32(c + 0x100, 0); m.w32(c + 0x110, rng.choice([0, 1]))
        m.uc.mem_write(A + 0x12c + 0x78 * (0 if m.r32(c + 0x110) == 0 else 1), bytes(m.uc.mem_read(surface_buffer_record(m, rng), 0x78)))
    return [c]


def dvd(m, rng):
    """a DVD context: +0x8c accelerator, +0x84 shared, +0x98 command-buffer descriptor, +0xf8 bound surface"""
    c = obj(m, rng, 'ATIR500DVDContext', 0x400)
    A = accel(m, rng)
    m.w32(c + 0x8c, A)
    return c, A


def bound_surface(m, rng, c, ctx_mask_bits=0x7fffff):
    """an ATIR500Surface as the DVD context sees it: 23 buffer records (0x78 bytes each, +0xa8), the per-attachment pointer table (+0xb70) pointing
    into them, the attachment-present mask (+0xbf8) and the ledger the context's own +0x88 mask is tested against"""
    S = obj(m, rng, 'ATIR500Surface', 0x1000)
    for i in range(23):
        r = S + 0xa8 + 0x78 * i
        m.w16(r + 0x1c, rng.choice([0, 640, 640, 1920, 1920])); m.w16(r + 0x1e, rng.choice([0, 480, 480, 1080, 1080])); m.w16(r + 0x16, rng.choice([64, 640, 1920]))
        m.w32(r + 0x10, rng.choice([0, 1, 0x1000, 0x1000]))
        owner = m.alloc(0x100); fill_words(m, owner, 0x100, rng); m.w8(owner + 0x58, rng.choice([0, 0, 1]))
        m.w32(r + 0x24, rng.choice([0, owner, owner, owner]))
    for i in range(34):
        m.w32(S + 0xb70 + 4 * i, S + 0xa8 + 0x78 * rng.randrange(23))
    m.w32(S + 0xbf8, rng.choice([0, 0x20000000, 0x7fffff, 0x7fffff, word(rng) & 0x7fffff]))
    return S


def w_dvd_get_surface_size(m, rng):
    c, A = dvd(m, rng)
    m.w32(c + 0xf8, rng.choice([0, bound_surface(m, rng, c)]))
    return [c, m.alloc(0x10), m.alloc(0x10)]


def w_dvd_free_all(m, rng):
    c, A = dvd(m, rng)
    m.w32(c + 0xf4, rng.choice([0, 1]))
    for i in range(2):
        m.w32(c + 0xc8 + 0x18 * i, rng.choice([0, 1, 2]))
        m.w32(c + 0xcc + 0x18 * i, plain(m, rng))
    m.w32(c + 0xb4, plain(m, rng))
    return [c]


def w_dvd_stop(m, rng):
    c, A = dvd(m, rng)
    others = [obj(m, rng, 'ATIR500DVDContext', 0x400) for _ in range(rng.choice([0, 1, 2]))]
    order = others[:]
    if rng.random() < 0.85:
        order.insert(rng.randrange(len(order) + 1), c)
    for a, b in zip(order, order[1:] + [0]):
        m.w32(a + 0x80, b)
        m.w32(a + 0xb0, rng.choice([0, 0x10000, 0x90000]))
    m.w32(A + 0x68, order[0] if order else 0)
    # the other list the accelerator keeps (+0x60): 2D/GL contexts that also map the descriptor
    l2 = [obj(m, rng, 'ATIR5002DContext', 0x400) for _ in range(rng.choice([0, 0, 1, 2]))]
    for a, b in zip(l2, l2[1:] + [0]):
        m.w32(a + 0x80, b); m.w32(a + 0xb0, rng.choice([0, 0x10000, 0x90000]))
    m.w32(A + 0x60, l2[0] if l2 else 0)
    m.w32(A + 0x5c8, rng.choice([0, 0x20000, 0x90000]))
    m.w32(A + 0x73c, rng.choice([1, 2, 7]))
    m.w32(A + 0x78, rng.choice([0, c]))
    m.w32(c + 0x98, rng.choice([0, plain(m, rng)]))
    m.w32(c + 0xb4, rng.choice([0, plain(m, rng)]))
    m.w32(c + 0xc8, rng.choice([0, 1])); m.w32(c + 0xe0, rng.choice([0, 1]))
    m.w32(c + 0xcc, plain(m, rng)); m.w32(c + 0xe4, plain(m, rng))
    m.w32(c + 0xf8, rng.choice([0, obj(m, rng, 'ATIR500Surface', 0x1000)]))
    shared = rng.choice([0, obj(m, rng, 'IOATIR500Shared', 0x100)])
    m.w32(c + 0x84, shared)
    for i in range(18):                                                  # the context's texture slots (+0x104..): buffer records or 0
        t = 0
        if rng.random() < 0.5:
            t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
            hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
        m.w32(c + 0x104 + 4 * i, t)
    m.w32(c + 0xfc, rng.choice([0, 1]))
    return [c, plain(m, rng)]


def w_dvd_write_buffer(m, rng):
    c, A = dvd(m, rng)
    S = bound_surface(m, rng, c)
    m.w32(c + 0xf8, rng.choice([S, S, S, 0]))
    m.w32(c + 0x88, rng.choice([0x7fffff, 0x7fffff, word(rng) & 0x7fffff]))
    m.w8(A + 0x80, rng.choice([0, 1, 1]))
    m.w32(A + 0x50, rng.choice([1, 2, 3]))
    m.w32(c + 0x78, plain(m, rng))                                           # the task
    p = m.alloc(0x40)
    big = lambda: rng.choice([-5, -1, 0, 1, 16, 100, 100, 300, 640, 1920])
    for off in (0, 4):
        m.w32(p + off, big() & 0xffffffff)
    for off in (8, 0xc):
        m.w32(p + off, rng.choice([1, 16, 100, 300, 640, 4000, 0x7ffffff0]) & 0xffffffff)
    m.w32(p + 0x10, rng.choice([0, 1])); m.w32(p + 0x14, rng.choice([0x10000000, 0x10000123, 0x2000000]))
    m.w32(p + 0x18, rng.choice([64, 640 * 4, 4096]))
    return [c, p, word(rng)]


def w_dvd_submit(m, rng):
    c, A = dvd(m, rng)
    m.w32(A + 0xb74, clean_word(rng)); m.w32(A + 0x708, clean_word(rng)); m.w32(A + 0x784, clean_word(rng))
    m.w32(A + 0x600, obj(m, rng, 'ATIR500DVDContext', 0x100))          # heads of the accelerator's texture lists (real nodes)
    m.w32(A + 0x6d0, obj(m, rng, 'ATIR500DVDContext', 0x100))
    src = cmd_buffer(m, rng, rng.choice([0, 1, 3, 8]))
    m.w32(src + 0x1c, rng.choice([0, 1, 1, 3]))
    m.w32(c + 0xc0, src)
    m.w32(c + 0xf4, rng.choice([0, 1]))
    for i in range(2):
        m.w32(c + 0xc8 + 0x18 * i, rng.choice([0, 0x100, 0x1000]))
        m.w32(c + 0xd4 + 0x18 * i, word(rng))
        m.w32(c + 0xd8 + 0x18 * i, m.alloc(0x400))
    for i in range(18):
        t = 0
        if rng.random() < 0.3:
            t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
            hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w8(hdr + 0x14, rng.choice([0, 1])); m.w32(t + 0x14, hdr)
            m.w32(t + 4, rng.choice([0, 1]))
            for off in (0x24, 0x28, 0x34, 0x38):
                m.w32(t + off, obj(m, rng, 'ATIR500DVDContext', 0x100))
            m.w32(t + 0x48, rng.choice([0, 1]))
        m.w32(c + 0x104 + 4 * i, t)
    return [c]


# command-stream opcodes (top byte of the first word of a command) the 2D/DVD/GL command-buffer interpreters switch on
STREAM_OPS = [0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
              0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
              0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x42, 0x43, 0x44, 0x46, 0x47, 0x02, 0x04, 0xe7, 0xff]


def stream(m, rng, base, ncmds, max_len=0x20, ops=STREAM_OPS, idx_hi=17):
    """write a command stream at `base`: ncmds commands [opcode<<24 | length][length-1 argument words], then a zero-length terminator. Arguments are mostly
    small indices (texture slots, buffer numbers) and small sizes, because the interpreters use them to index tables; a few are arbitrary words."""
    a = base
    for _ in range(ncmds):
        n = rng.randrange(1, max_len)
        m.w32(a, (rng.choice(ops) << 24) | n)
        for j in range(1, n):
            r = rng.random()
            v = rng.randrange(0, idx_hi + 1) if r < 0.45 else rng.choice([0, 1, 2, 3, 4, 8, 16, 32, 0x40, 0x100, 0x800]) if r < 0.85 else (clean_word(rng) & 0x0fffffff or 1)
            m.w32(a + 4 * j, v)
        a += 4 * n
    m.w32(a, 0)
    return a + 4


def dvd_surface_big(m, rng):
    """the bound surface as the DVD/GL interpreters read it: a big word-soup object with sane 16-bit geometry fields"""
    S = obj(m, rng, 'ATIR500Surface', 0x1100)
    for off in range(0, 0x1100, 2):
        pass
    for i in range(23):
        r = S + 0xa8 + 0x78 * i
        for off in (0x16, 0x1c, 0x1e):
            m.w16(r + off, rng.choice([1, 2, 16, 64, 640]))
    for off in (0x94, 0x96, 0x98, 0x9a, 0x136, 0x134, 0x8b8, 0x92c, 0x136):
        m.w16(S + off, rng.choice([1, 2, 16, 64, 480]))
    return S


def w_dvd_pcb(m, rng):
    c, A = dvd(m, rng)
    S = dvd_surface_big(m, rng)
    m.w32(c + 0xf8, S)
    m.w32(A + 0x8bc, rng.choice([0, 1, 1, 1]))
    m.w32(A + 0x8a4, clean_word(rng) & 0xfffff000)
    m.w32(A + 0x6d0, obj(m, rng, 'ATIR500DVDContext', 0x100))
    for i in range(18):
        t = 0
        if rng.random() < 0.9:
            t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
            hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
            m.w32(t + 4, rng.choice([0, 0x10000000, 0x20000000]))
            for off in (0x34, 0x38):
                m.w32(t + off, obj(m, rng, 'ATIR500DVDContext', 0x100))
            m.w32(t + 0x50, rng.choice([0, 0x100]))
        m.w32(c + 0x104 + 4 * i, t)
    m.w32(c + 0x84, obj(m, rng, 'IOATIR500Shared', 0x100))
    buf = m.alloc(0x2000)
    end = stream(m, rng, buf + 0x1c, rng.choice([1, 2, 3, 5]))
    m.w32(c + 0xa4, buf); m.w32(c + 0x94, rng.choice([0, 0x10, 0x100]))
    m.w32(c + 0x154, word(rng)); m.w32(c + 0x158, word(rng)); m.w32(c + 0x15c, word(rng))
    out = m.alloc(0x40)
    return [c, out]


def surf(m, rng):
    """an ATIR500Surface (this) with its accelerator at +0xd50"""
    S = obj(m, rng, 'ATIR500Surface', 0xe00)
    A = accel(m, rng)
    m.w32(S + 0xd50, A)
    return S, A


def w_bad_panel(m, rng):
    S, A = surf(m, rng)
    m.w32(A + 0x74, plain(m, rng, 0x400, 0x800))
    return [S]


def w_invalidate_contexts(m, rng):
    S, A = surf(m, rng)
    def chain(cls):
        head = 0
        for _ in range(rng.choice([0, 1, 2, 3])):
            n = obj(m, rng, cls, 0x400)
            m.w32(n + 0x84, head)
            head = n
        return head
    m.w32(S + 0x88, chain('ATIR500GLContext'))
    m.w32(S + 0x8c, chain('ATIR5002DContext'))
    m.w32(S + 0x90, rng.choice([0, obj(m, rng, 'ATIR500DVDContext', 0x400)]))
    m.w32(A + 0x78, rng.choice([0, 1, S]))
    return [S]


def w_alloc_all_slave(m, rng):
    S, A = surf(m, rng)
    for i in range(2):
        m.w32(A + 0x114 + 4 * i, rng.choice([0, 1, 2, 4]))
    m.w32(A + 0x82c, rng.choice([0, 0x100]))
    for p_ in range(2):                                    # the panel records: 5 entries of 0x1c bytes, the first at +0xc30 + panel*0x94
        for e in range(5):
            r = S + 0xc30 + p_ * 0x94 + e * 0x1c
            m.w32(r + 0x14, rng.choice([0, plain(m, rng)]))      # an existing buffer descriptor (released when the set is torn down)
    return [S, rng.choice([0, 1]), rng.choice([0x1000, 0x2000, 0x10000])]


def w_surface_stop(m, rng):
    S, A = surf(m, rng)
    # the accelerator's circular list of surfaces (head at +0x5c), linked through each surface's +0x9c (prev) / +0xa0 (next)
    other = obj(m, rng, 'ATIR500Surface', 0x1000)
    if rng.random() < 0.5:
        m.w32(S + 0x9c, S); m.w32(S + 0xa0, S)                       # alone on the list
    else:
        m.w32(S + 0x9c, other); m.w32(S + 0xa0, other); m.w32(other + 0x9c, S); m.w32(other + 0xa0, S)
    m.w32(A + 0x5c, rng.choice([S, S, other, 0]))
    m.w32(A + 0x730, rng.choice([1, 2, 5]))
    m.w32(S + 0xd48, rng.choice([0, 1])); m.w32(A + 0x21c, rng.choice([0, 1, 4]))
    # the list of buffer descriptors (+0xbcc, linked through +0x54, header at +0x14)
    head = 0
    for _ in range(rng.choice([0, 1, 2])):
        n = m.alloc(0x100); fill_words(m, n, 0x100, rng)
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(n + 0x14, hdr)
        m.w32(n + 0x54, head); head = n
    m.w32(S + 0xbcc, head)
    idx = rng.choice([0, 1, 0xffff])                                # the panel this surface is on
    m.w32(S + 0xc14, idx)
    for i in range(2):
        m.w32(A + 0xe8 + 0x20 * i, rng.choice([S, 0, other]))
    m.w8(S + 0xbd0, rng.choice([0, 1, 3]))
    tab = m.alloc(0x100); fill_words(m, tab, 0x100, rng)
    owner = m.alloc(0x40); fill_words(m, owner, 0x40, rng); m.w32(owner + 0x10, rng.choice([0, plain(m, rng)]))
    m.w32(tab + 0x24, rng.choice([0, owner]))
    m.w32(S + 0xb70, tab)
    m.w32(S + 0xd8c, rng.choice([0, 1]))
    m.w32(S + 0xd84, rng.choice([0, plain(m, rng)])); m.w32(S + 0xd88, rng.choice([0, plain(m, rng)]))
    def chain(cls):
        h = 0
        for _ in range(rng.choice([0, 1, 2])):
            n = obj(m, rng, cls, 0x400); m.w32(n + 0x84, h); h = n
        return h
    m.w32(S + 0x88, chain('ATIR500GLContext')); m.w32(S + 0x8c, chain('ATIR5002DContext'))
    m.w32(S + 0x90, rng.choice([0, obj(m, rng, 'ATIR500DVDContext', 0x400)]))
    for i in range(23):                                             # buffer records: +0xcc of each 0x78-byte record is a texture buffer or 0
        m.w32(S + 0xcc + 0x78 * i - 0x78 * 0, rng.choice([0, 0, plain(m, rng)]))
    m.w32(A + 0xcc, rng.choice([0, 1, 2]))
    for i in range(2):
        m.w32(S + 0xc28 + 0x94 * i, rng.choice([0, 1]))
        m.w32(S + 0xd60 + 8 * i, rng.choice([0, 0x20000000]))
        m.w32(S + 0xd64 + 8 * i, rng.choice([0x1000, 0x2000]))
    m.w32(A + 0x804, rng.choice([0x10000, 0x40000]))
    return [S, plain(m, rng)]


def surf_buf(m, rng):
    """an ATIR500SurfaceBuffer as the blit/resolve packet builders read it: base/pitch/size halves, format index (in range of the 48-entry table), flags"""
    r = m.alloc(0x100); fill_words(m, r, 0x100, rng)
    m.w32(r + 8, rng.choice([0, 0x1000000, 0x20000000, 0x30000020]))
    for off, vals in ((0x14, [16, 64, 640, 1920]), (0x16, [1, 2, 4, 8]), (0x1c, [0, 16, 640, 1920]), (0x1e, [0, 16, 480, 1080]), (0x20, [0, 1, 2])):
        m.w16(r + off, rng.choice(vals))
    m.w32(r + 0x28, rng.choice([0, 0x3ff00000, 0x10000000, 0x40000, 0x00200000]))
    m.w32(r + 0x30, rng.choice([0, 0x1000, 0x20000]))
    m.w8(r + 0x36, rng.choice([0, 1])); m.w8(r + 0x38, rng.randrange(4)); m.w8(r + 0x39, rng.randrange(4)); m.w8(r + 0x3a, rng.randrange(48))
    m.w32(r + 0x3c, rng.choice([0, 0x111000, 0x00400000, 0x00900000, 0x00f00000, 0x00200003]))
    m.w32(r + 0x40, rng.choice([0, 0x100, 0x2000]))
    return r


def w_resolve_fsaa(m, rng):
    S, A = surf(m, rng)
    tab = [surf_buf(m, rng) for _ in range(4)]
    for i in range(4):
        m.w32(S + 0xb70 + 4 * i, tab[i])
    m.w32(S + 0xb94, rng.choice(tab))
    m.w32(S + 0xbe8, rng.choice([0, 0, 0x100000, 0x300000, 0x700000]))
    m.w32(A + 0xb74, clean_word(rng)); m.w32(A + 0xb98, rng.choice([4, 4, 2, 1]))
    out = m.alloc(0x1000)
    sz = lambda: rng.choice([-8, 0, 1, 16, 64, 640, 480])
    return [S, rng.choice([9, 9, 1, 8]), rng.choice([0, 1, 2, 3]), out, rng.choice([0, 1]), sz() & 0xffffffff, sz() & 0xffffffff, sz() & 0xffffffff, sz() & 0xffffffff]   # (the 9th word is passed on the stack)


def w_copy_buffer_dma(m, rng):
    S, A = surf(m, rng)
    m.w8(A + 0x80, rng.choice([1] * 9 + [0]))
    m.w32(A + 0x98, rng.choice([0, 0x80, 0x8, 0x88, 0x88, 0x80, 0x8, 0x20000, 0x20088]))
    m.w32(A + 0x8a4, 0x1000000); m.w32(A + 0x82c, rng.choice([0, 0x20])); m.w32(A + 0x788, clean_word(rng))
    m.w32(S + 0xbe8, rng.choice([0, 0, 0, 0, 0x40000, 0x700000, 0x70000000, 0x10000000]))
    m.w32(S + 0xdac, rng.choice([0, 1]))
    m.w16(S + 0xbd6, rng.choice([480, 1080])); m.w16(S + 0xbda, rng.choice([480, 1080]))
    # swap-buffer ring (4 entries of 0x1c bytes from +0xc3c): +0xc44 backing, +0xc40 mapped, +0xc4c stamp, +0xc50 header (the packet buffer)
    m.w16(S + 0xcae, rng.randrange(4)); m.w32(S + 0xcb0, 0x10000)
    m.w32(S + 0xc34, m.alloc(0x100))
    for e in range(4):
        r = S + 0xc3c + 0x1c * e
        m.w32(r + 8, rng.choice([0, plain(m, rng)]))
        m.w32(r + 4, rng.choice([0, 0x2000000]))
        m.w32(r + 0x14, m.alloc(0x2000))
    # the source/dest buffer record: inside the surface's own buffer array (+0x558..0x738) or an outside one
    if rng.random() < 0.5:
        buf = S + 0x558 + 0x78 * rng.randrange(0, 3)
    else:
        buf = m.alloc(0x100)
    fill_words(m, buf, 0x78, rng)
    m.w32(buf + 8, rng.choice([0x1000000, 0x20000000]))
    for off, vals in ((0x14, [64, 640, 1920]), (0x16, [1, 2, 4]), (0x1e, [16, 33, 480])):
        m.w16(buf + off, rng.choice(vals))
    m.w8(buf + 0x38, rng.randrange(4)); m.w8(buf + 0x39, rng.randrange(4)); m.w8(buf + 0x3a, rng.randrange(48))
    m.w32(buf + 0x3c, rng.choice([0, 0x800, 0x111000, 0x00100800]))
    owner = m.alloc(0x100); fill_words(m, owner, 0x100, rng); m.w8(owner + 0x58, rng.choice([0, 1]))
    m.w32(buf + 0x24, rng.choice([0, owner]))
    xfer = m.alloc(0x100); fill_words(m, xfer, 0x100, rng)
    m.w32(xfer + 4, rng.choice([0, 0x3000000]))
    m.w32(xfer + 8, plain(m, rng)); m.w16(xfer + 0xe, rng.randrange(4)); m.w32(xfer + 0x14, m.alloc(0x40))
    small = lambda: rng.choice([0, 1, 7, 16, 33, 100]) 
    # copy_buffer_using_DMA(x, y, w, h, u, v, buffer, transfer, offset, pitch, direction, flags)
    return [S, small(), small(), small() + 1, small() + 1, small(), small(), buf, xfer, rng.choice([0, 0x100]), rng.choice([64, 256, 4096]),
            rng.choice([0, 1, 2, 2, 1]), rng.choice([0, 1, 2, 3])]


def w_calc_h_scaler_blank(m, rng):
    """calc_h_scaler_blank(info, bandwidth, p3, p4, float f5, float f6, ulong *o7, ulong *o8, ulong *o9): the floats arrive in f1/f2"""
    S, A = surf(m, rng)
    info = m.alloc(0x100); fill_words(m, info, 0x100, rng)
    m.w32(info + 0x18, rng.choice([0, 100, 640, 1920])); m.w32(info + 0x14, rng.choice([0, 8, 16, 100, 1000]))
    m.w32(info + 0x3c, rng.choice([3, 4, 6, 9, 10, 0xb, 0xc, 0xd, 0xe, 1, 0x20]))
    bw = m.alloc(0x100); fill_words(m, bw, 0x100, rng)
    m.w32(bw + 0x2c, rng.choice([0, 1, 2, 3, 4, 5, 7])); m.w32(bw + 0x38, rng.choice([0, 1, 2, 3])); m.w32(bw + 0x24, rng.choice([0, 3, 100]))
    m.fargs = [rng.choice([0.0, 1.0, 2.0, 0.5, 3.25, 100.0, -1.0]), rng.choice([0.0, 1.0, 0.75, 8.0, 2048.0, 1.5])]
    # (in the Darwin PPC ABI each floating-point argument also reserves its general-purpose slot: r8 and r9 stay unused, o7 is in r10, o8/o9 on the stack)
    return [S, info, bw, rng.choice([0, 8, 100, 4000, 0xffffffff]), rng.choice([0, 16, 100, 4000]), 0, 0, m.alloc(0x10), m.alloc(0x10), m.alloc(0x10)]


def swap_header(m, rng, nwords):
    """a swap buffer header as the swap code reads it: +0x14 length (words), +0x18 the length of the first half, +0x1c flags, +0x20 the words"""
    h = m.alloc(0x1000); fill_words(m, h, 0x1000, rng)
    m.w32(h + 0x14, nwords); m.w32(h + 0x18, rng.choice([0, nwords // 2, nwords])); m.w32(h + 0x1c, rng.choice([0, 1, 1, 3]))
    return h


def w_submit_swap(m, rng):
    """submit_swap_buffer(panel, eDoSwap, IOATIR500GLContext *): panel 0/1, doSwap 0 (both halves) / 1 (first) / 2 (second)"""
    S, A = surf(m, rng)
    panel = rng.choice([0, 1])
    m.w16(S + 0xdb4, rng.choice([0, 1]))
    ctx = rng.choice([0, obj(m, rng, 'ATIR500GLContext', 0x200)])
    if ctx:
        for off, vals in ((0x98, [0, 1, 2]), (0x94, [0, 16, 640]), (0x90, [-4, 0, 8]), (0x92, [-4, 0, 8]), (0x96, [0, 16, 480])):
            m.w16(ctx + off, rng.choice(vals) & 0xffff)
    m.w32(S + 0xd54, rng.choice([0, ctx, ctx]))
    base = S + 0x94 * panel
    m.w8(base + 0xcad, rng.choice([0, 1, 2]))
    m.w32(base + 0xc34, swap_header(m, rng, rng.choice([0, 2, 6, 12])))
    m.w16(base + 0xcae, rng.randrange(4)); m.w32(base + 0xcb0, 0x10000)
    for e in range(4):
        r = base + 0xc3c + 0x1c * e
        m.w32(r + 8, rng.choice([0, plain(m, rng)]))
        m.w32(r + 4, rng.choice([0, 0x2000000]))
        m.w32(r + 0x14, swap_header(m, rng, rng.choice([0, 4, 8])))
    rec = m.alloc(0x40)
    for off, vals in ((4, [0, 8]), (6, [0, 8]), (8, [100, 640]), (10, [100, 480])):
        m.w16(rec + off, rng.choice(vals))
    m.w32(S + 0xd60 + 8 * panel, rec)
    m.w8(A + 0x9b0, rng.choice([0, 1, 1])); m.w32(A + 0x894, rng.choice([0, 1]))
    m.w32(A + 0x898, clean_word(rng)); m.w32(A + 0x89c, clean_word(rng))
    for p_ in range(2):
        m.w32(A + 0xb10 + 0x18 * p_, rng.choice([0, 1]))
        m.w16(A + 0x14a + 0x78 * p_, word(rng) & 0xfff)
        m.w32(A + 0x134 + 0x78 * p_, rng.choice([0, 0x41, 0x105, 0x3ff]))
        m.w16(A + 0x144 + 0x78 * p_, rng.choice([0, 1, 4])); m.w16(A + 0x142 + 0x78 * p_, rng.choice([0, 1, 3]))
    m.w8(S + 0xbed, rng.choice([0, 1]))
    m.w32(A + 0x710, clean_word(rng))
    return [S, panel, rng.choice([0, 1, 2]), ctx]


def sane_record(m, rng, r):
    """make the 0x78-byte surface buffer record at `r` plausible: geometry halves, pitch, format index (in the 48-entry table), sample bits"""
    m.w32(r + 8, rng.choice([0, 0x1000000, 0x20000000, 0x30000020]))
    for off, vals in ((0x14, [16, 64, 640, 1920]), (0x16, [1, 2, 4, 8]), (0x1c, [0, 16, 640, 1920]), (0x1e, [0, 16, 480, 1080]), (0x20, [0, 1, 2])):
        m.w16(r + off, rng.choice(vals))
    m.w8(r + 0x38, rng.randrange(4)); m.w8(r + 0x39, rng.randrange(4)); m.w8(r + 0x3a, rng.randrange(48))
    m.w32(r + 0x3c, rng.choice([0, 0x111000, 0x00400000, 0x00900000, 0x00f00000, 0x00200003]))
    m.w32(r + 0x40, rng.choice([0, 0x100, 0x2000]))


def w_build_swap(m, rng):
    S, A = surf(m, rng)
    npanels = rng.choice([1, 2, 2])
    m.w32(A + 0xcc, npanels)
    m.w8(A + 0x9b0, rng.choice([0, 1, 1])); m.w32(A + 0x894, rng.choice([0, 1])); m.w32(A + 0x898, clean_word(rng)); m.w32(A + 0x89c, clean_word(rng))
    m.w32(A + 0x8c4, rng.choice([0, 1])); m.w32(A + 0xb74, clean_word(rng))
    for p_ in range(2):
        sane_record(m, rng, A + 0x12c + 0x78 * p_)
        m.w32(A + 0xb10 + 0x18 * p_, rng.choice([0, 1]))
    for i in range(23):
        sane_record(m, rng, S + 0xa8 + 0x78 * i)
    for i in range(4):                       # sizes beyond 4096 too: the packet builder splits such a buffer into pieces
        m.w16(S + 0xa8 + 0x78 * i + 0x1c, rng.choice([0, 3, 16, 640, 640, 5000, 8192])); m.w16(S + 0xa8 + 0x78 * i + 0x1e, rng.choice([0, 3, 16, 480, 480, 4097, 6000]))
    m.w32(S + 0xb70, S + 0xa8 + 0x78 * rng.randrange(4)); m.w32(S + 0xb74, S + 0xa8 + 0x78 * rng.randrange(4))
    m.w32(S + 0xbe8, rng.choice([0, 0x20, 0x20, 0x100, 0x7000000]))
    m.w8(S + 0xbf1, rng.choice([0x10, 0x20, 0x30]))
    for off in (0xbe0, 0xbe2, 0xbe4, 0xbe6, 0xbdc, 0xbde, 0xbd4, 0xbd6):
        m.w16(S + off, rng.choice([0, 1, 16, 100, 480, 640]))
    m.w32(S + 0x90, rng.choice([0, 1])); m.w32(S + 0xda4, rng.choice([0, 1]))
    m.w8(S + 0xcac, rng.choice([0, 1, 1])); m.w8(S + 0xbed, rng.choice([0, 1]))
    for p_ in range(2):
        base = S + 0x94 * p_
        h = m.alloc(0x4000); fill_words(m, h, 0x4000, rng)
        m.w32(base + 0xc34, h)
        rec = m.alloc(0x40)
        m.w32(rec, rng.choice([0, 1]))
        for off, vals in ((4, [0, 8, -4]), (6, [0, 8, -4]), (8, [100, 640, 0]), (10, [100, 480, 0])):
            m.w16(rec + off, rng.choice(vals) & 0xffff)
        m.w32(S + 0xd60 + 8 * p_, rec)
    return [S]


def w_3dtexquad(m, rng):
    """write_3dtexquad_cmds_for_copy_buffer_using_DMA(accelerator, cmds, offset, ... 25 arguments): the copy's source/destination description (addresses, sizes,
    format shifts 0-4 that index the function's own tables, byte flags) and the rectangle (four signed coordinates and two sizes)"""
    A = accel(m, rng, mmio=False)
    m.w32(A + 0xb74, clean_word(rng))
    cmds = m.alloc(0x4000)
    rect = lambda: rng.choice([-16, -1, 0, 1, 3, 16, 33, 100, 640, 4000])
    size = lambda: rng.choice([0, 1, 2, 16, 64, 640, 1000, 4096, 5000])
    addr = lambda: rng.choice([0x1000000, 0x20000000, 0x30000020, 0x12345600])
    args = [A, cmds, rng.choice([0, 2, 8]), rng.randrange(8), addr(), rng.choice([64, 640, 2560]), size() + 1, size() + 1, rng.randrange(8),
            rng.randrange(5), rng.randrange(4), rng.choice([0, 1, 2]), addr(), rng.choice([64, 640, 2560]), rng.choice([64, 640]), rng.randrange(8),
            rng.randrange(5), rng.randrange(4), rect() & 0xffffffff, rect() & 0xffffffff, rect() & 0xffffffff, rect() & 0xffffffff, size(), size(), rng.choice([0, 1])]
    return args


def fbits(f): return struct.unpack('>I', struct.pack('>f', f))[0]


def w_pcl_copypix(m, rng):
    """pcl_CopyPix(UInt32 *packet, pcl_ParamsR500_t *params, bool flipX, bool flipY): the parameter block holds the register values to copy (+0..+0x28), the source/destination
    scale factors as floats (+0x6c, +0x70), the rectangle as floats (+0x54..+0x60) and a pointer to four 16-bit window coordinates (+0x50)"""
    out = m.alloc(0x2000)
    prm = m.alloc(0x100); fill_words(m, prm, 0x100, rng)
    for off in range(0, 0x2c, 4):
        m.w32(prm + off, clean_word(rng))
    for off in range(0x2c, 0x40):                  # format indexes into the 48-entry format table (the rebuilt kext calls its own lookup function for these, the shipped code reads the table inline)
        m.w8(prm + off, rng.randrange(48))
    win = m.alloc(0x20)
    for i in range(4):
        m.w16(win + 2 * i, rng.choice([0, 1, 16, 100, 640, 1000, 0xfff0]) )
    m.w32(prm + 0x50, win)
    big = lambda: rng.choice([0.0, 1.0, 2.0, 16.0, 640.0, 4000.0, 4096.0, 5000.0, 8192.0, 70000.0])
    pos = lambda: rng.choice([-5.0, 0.0, 1.0, 16.5, 100.0, 640.0, 700.25])
    m.w32(prm + 0x6c, fbits(big())); m.w32(prm + 0x70, fbits(big()))
    for off in (0x54, 0x58, 0x5c, 0x60):
        m.w32(prm + off, fbits(pos()))
    m.w32(prm + 0x88, rng.choice([0, 1]))
    return [out, prm, rng.choice([0, 1]), rng.choice([0, 1])]


CASES = [
    Case('IOATIR5002DContext::create_shared', w_2d_create_shared, ret='bool', seeds=20, mock=new_mock),
    Case('IOATIR5002DContext::set_macrovision', w_2d_set_macrovision, ret='u32', seeds=20, mock=new_mock),
    Case('IOATIR5002DContext::freeAllContextBuffers', w_2d_free_all, ret='void', seeds=20, mock=new_mock),
    Case('IOATIR5002DContext::stop', w_2d_stop, ret='void', seeds=30, mock=new_mock, ignore_args=REL),
    Case('ATIR5002DContext::submit_context_buffer', w_2d_submit, ret='void', seeds=30, mock=new_mock),
    Case('IOATIR500DVDContext::get_surface_size', w_dvd_get_surface_size, ret='u32', seeds=20, mock=new_mock),
    Case('IOATIR500DVDContext::freeAllContextBuffers', w_dvd_free_all, ret='void', seeds=20, mock=new_mock),
    Case('IOATIR500DVDContext::stop', w_dvd_stop, ret='void', seeds=40, mock=new_mock, ignore_args=REL),
    Case('IOATIR500DVDContext::write_buffer', w_dvd_write_buffer, ret='u32', seeds=300, mock=new_mock, ignore_args=REL),
    Case('IOATIR500DVDContext::create_shared', lambda m, rng: [dvd(m, rng)[0]], ret='bool', seeds=20, mock=new_mock),
    Case('ATIR500DVDContext::submit_context_buffer', w_dvd_submit, ret='void', seeds=80, mock=new_mock),
    Case('ATIR500DVDContext::process_command_buffer', w_dvd_pcb, ret='u32', seeds=400, mock=new_mock, ignore_args=REL, limit=400000, plain_words=True),
    Case('ATIR500Surface::bad_panel', w_bad_panel, ret='u32', seeds=20, mock=new_mock),
    Case('IOATIR500Surface::invalidate_contexts', w_invalidate_contexts, ret='void', seeds=20, mock=new_mock),
    Case('IOATIR500Surface::allocAllSlaveSwapBuffers', w_alloc_all_slave, ret='u32', seeds=60, mock=new_mock, ignore_args=REL),
    Case('IOATIR500Surface::stop', w_surface_stop, ret='void', seeds=60, mock=new_mock, ignore_args=REL, plain_words=True),
    Case('ATIR500Surface::resolve_fsaa_buffer', w_resolve_fsaa, ret='u32', seeds=80, mock=new_mock, plain_words=True),
    Case('ATIR500Surface::copy_buffer_using_DMA', w_copy_buffer_dma, ret='u32', seeds=100, mock=new_mock, plain_words=True, ignore_args=REL),
    Case('ATIR500Surface::calc_h_scaler_blank', w_calc_h_scaler_blank, ret='void', seeds=80, mock=new_mock, plain_words=True),
    Case('ATIR500Surface::submit_swap_buffer', w_submit_swap, ret='void', signature='(unsigned long, eDoSwap, IOATIR500GLContext*)', seeds=150, mock=new_mock, plain_words=True, ignore_args=REL),
    Case('ATIR500Surface::build_swap', w_build_swap, ret='void', seeds=400, mock=new_mock, plain_words=True, ignore_args=REL, limit=600000),
    Case('__Z46write_3dtexquad_cmds_for_copy_buffer_using_DMAP14ATIRadeonX1000Pmmmmmmmmmhmmmmmmhllllmmb', w_3dtexquad, ret='u32', seeds=300, mock=new_mock, plain_words=True),
    Case('__Z11pcl_CopyPixPmP16pcl_ParamsR500_tbb', w_pcl_copypix, ret='u32', seeds=400, mock=new_mock, plain_words=True),
]
