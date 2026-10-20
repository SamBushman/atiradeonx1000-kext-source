"""Hand-written worlds (hand-world push, fork H3): the functions of ATIR500Memory, ATIR500Surface and IOATIR500Surface whose generic cases left most of the code unexecuted.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_H3.py   (needs STOCK_KEXT; DT_UNCOV=1 prints the instruction ranges no run reached)
Each world builds the object graph the function really works on (a pool list with free and used nodes, a surface with buffers, lists and an accelerator) so the
branches behind the first validity checks run; names say what the case adds (the generic case of the same function stays in all_classes_cases.py)."""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from difftest import Case, default_mock
from common import word, fill_words
from hand_cases_D import new_mock, plain, obj, clean_word, surf, accel, REL
from unicorn.ppc_const import UC_PPC_REG_3, UC_PPC_REG_4, UC_PPC_REG_5, UC_PPC_REG_6, UC_PPC_REG_7

CASES = []
PAGE = 0x1000


# ---------------------------------------------------------------- ATIR500Memory: alloc / alloc(5 args) / reserve
# The pool is a list of nodes {next, prev, offset, flags}: this+8 -> holder -> head -> first node; a node with a negative flags word is a free range that
# ends where the next node starts; the last node (next == 0) only marks the end. Spare nodes hang on a stack at this+0xc (linked through word 0).
def pool(m, rng, nfree_nodes=None):
    this = obj(m, rng, 'ATIR500Memory', 0x40)
    n = rng.randrange(3, 9)
    nodes = [m.alloc(0x20) for _ in range(n)]
    off = rng.choice([0, 0, PAGE])
    free = []
    for i, nd in enumerate(nodes):
        m.w32(nd, nodes[i + 1] if i + 1 < n else 0)
        m.w32(nd + 4, nodes[i - 1] if i else 0)
        m.w32(nd + 8, off)
        isfree = 0 < i and i + 1 < n and rng.random() < 0.6          # the first node is a boundary: a free node always has a predecessor
        m.w32(nd + 0xc, 0x80000000 if isfree else rng.choice([0, 1, 0x7fffffff]))
        if isfree: free.append(i)
        off += PAGE * rng.randrange(1, 9) + rng.choice([0, 0, 0, 0x10, 0x100, 0x230])
    head = m.alloc(0x10); m.w32(head, nodes[0] if rng.random() > 0.08 else 0)           # now and then an empty pool
    holder = m.alloc(0x10); m.w32(holder, head)
    m.w32(this + 8, holder)
    spare = 0
    for _ in range(rng.choice([0, 1, 2, 3])):               # the spare-node stack
        s = m.alloc(0x20); m.w32(s, spare); spare = s
    m.w32(this + 0xc, spare)
    return this, nodes, free


def mem_mock(m, name, k):
    if 'add_to_stack' in name:                               # refills the spare stack (the mock cannot): fails now and then
        return 0 if (m.seed + k) % 3 else 0
    return default_mock(m, name, k)


def pick_free(rng, nodes, free):
    i = rng.choice(free)
    return nodes[i], nodes[i + 1], i


def w_alloc3(m, rng):
    this, nodes, free = pool(m, rng)
    elem = m.alloc(0x20)
    if free and rng.random() < 0.9:
        f, nx, _ = pick_free(rng, nodes, free)
        lo, hi = m.r32(f + 8), m.r32(nx + 8)
        align = rng.choice([0, 0x1000, 0x1000, 0x100, 0x10, 1])
        mask = (align - 1) if align else 0
        start = (lo + mask) & ~mask & 0xffffffff
        if rng.random() < 0.4: size = hi - lo                              # the whole range (start fits only when aligned)
        elif rng.random() < 0.5: size = max(1, hi - start)                 # up to its end
        else: size = rng.choice([0x10, 0x800, 0x1000, 0x2000])
    else:
        align = rng.choice([0, PAGE]); size = rng.choice([0x1000, 0x100000, 0xffffff00])
    if os.environ.get("H3DBG"): print("ARGS", [hex(x) for x in (this, elem, size, align)])
    return [this, elem, size, align]


def w_alloc5(m, rng):
    this, nodes, free = pool(m, rng)
    elem = m.alloc(0x20)
    if free:
        f, nx, _ = pick_free(rng, nodes, free)
        lo, hi = m.r32(f + 8), m.r32(nx + 8)
    else:
        lo, hi = 0, 0x100000
    align = rng.choice([0, 0x1000, 0x100, 0x10, 1])
    mask = (align - 1) if align else 0
    rstart = rng.choice([0, lo, lo + 0x800, lo + PAGE, lo - 0x100 if lo > 0x100 else 0, hi, 0xffff0000])
    start = lo if rstart <= lo else rstart
    start = (start + mask) & ~mask & 0xffffffff
    size = rng.choice([hi - lo, max(1, hi - start), 0x800, 0x1000, 0x2000])
    rsize = rng.choice([0xffffffff, 0x100000, size, size - 1 if size > 1 else 1, 0x1000, 0])
    return [this, elem, size, align, rstart, rsize & 0xffffffff]


def w_reserve(m, rng):
    this, nodes, free = pool(m, rng)
    elem = m.alloc(0x20)
    if free and rng.random() < 0.9:
        f, nx, _ = pick_free(rng, nodes, free)
        lo, hi = m.r32(f + 8), m.r32(nx + 8)
        offset = rng.choice([lo, lo, lo + PAGE, lo + 0x800, lo - PAGE if lo >= PAGE else lo])
        size = rng.choice([hi - lo, hi - offset if hi > offset else 0x100, hi - offset - 0x100 if hi > offset + 0x100 else 0x80, 0x100, PAGE])
    else:
        offset, size = rng.choice([0, PAGE, 0xfffff000]), rng.choice([0x100, PAGE, 0x100000])
    return [this, elem, offset, size & 0xffffffff]


CASES += [
    Case('ATIR500Memory::alloc', w_alloc3, ret='u32', signature='(GLKMemoryElement*, unsigned long, unsigned long)', name='ATIR500Memory::alloc(3 args) pool H3', seeds=300, mock=mem_mock, plain_words=True),
    Case('ATIR500Memory::alloc', w_alloc5, ret='u32', signature='unsigned long, unsigned long, unsigned long, unsigned long)', name='ATIR500Memory::alloc(5 args) pool H3', seeds=300, mock=mem_mock, plain_words=True),
    Case('ATIR500Memory::reserve', w_reserve, ret='u32', name='ATIR500Memory::reserve pool H3', seeds=300, mock=mem_mock, plain_words=True),
]


# ---------------------------------------------------------------- IOATIR500Surface::set_id_mode
LEGAL_LOW = [0, 1, 2, 3, 4, 0xb, 0xc, 0xd, 5]
KIND_FOR = {3: 2, 4: 4, 0xb: 8, 0xc: 8, 0xd: 0x10}


def mode_bits(rng):
    b = rng.choice(LEGAL_LOW) | rng.choice([0, 0, 0x10, 0x20, 0x30]) | rng.choice([0, 0x8000, 0x8000])
    if rng.random() < 0.06: b |= rng.choice([0x40, 0x100, 0x10000])                 # outside the accepted mask: rejected
    return b


def w_set_id_mode(m, rng):
    S, A = surf(m, rng)
    npanels = rng.choice([1, 2, 2])
    m.w32(A + 0xcc, npanels)
    for p in range(2):
        m.w32(A + 0xe8 + 0x20 * p, rng.choice([0, 0, S, plain(m, rng, 0x40)]))               # panel owner
        m.w32(A + 0x140 + 0x78 * p, 0)
    bits = mode_bits(rng)
    kind = KIND_FOR.get(bits & 0xf, 0)
    for p in range(2):                                                                       # the panel's kind halfword at +0x142: usually the one the mode needs
        m.w16(A + 0x142 + 0x78 * p, kind if rng.random() < 0.8 else rng.choice([0, 2, 4, 8, 0x10]))
        m.w16(A + 0x148 + 0x78 * p, rng.choice([640, 1024, 1920])); m.w16(A + 0x14a + 0x78 * p, rng.choice([480, 768, 1080]))
    m.w32(A + 0x804, rng.choice([0, 0x10000, 0x40000]))
    # state of the surface
    m.w32(S + 0xbd0, rng.choice([0, 0, 0, 0, 0x10000, 1]))                                   # lockFlags (upper half set: locked, rejected)
    bound = rng.random() < 0.35
    m.w32(S + 0x90, obj(m, rng, 'ATIR500DVDContext', 0x400) if bound and rng.random() < 0.5 else 0)
    m.w32(S + 0x88, obj(m, rng, 'ATIR500GLContext', 0x400) if bound and rng.random() < 0.5 else 0)
    m.w32(S + 0x8c, obj(m, rng, 'ATIR5002DContext', 0x400) if bound and rng.random() < 0.5 else 0)
    old = bits if rng.random() < 0.6 else mode_bits(rng)
    m.w32(S + 0xbe8, old)
    m.w32(S + 0xc14, rng.choice([0xffff, 0, 1, 1]))
    for p in range(2):
        m.w32(S + 0xd60 + 8 * p, rng.choice([0, plain(m, rng, 0x40)]))
        m.w32(S + 0xd64 + 8 * p, rng.choice([0, 0xc, 0xc, 0x20]))
    m.w32(S + 0xb8, rng.choice([0, 0x1000])); m.w32(S + 0x130, rng.choice([0, 0x1000]))
    m.w32(S + 0xbf8, rng.choice([0, 0x20000000, 0x10000000]))
    mode = rng.choice([0, 1, 1, 0, 2, 0xffff, 0x10])
    return [S, mode, bits]


def sid_mock(m, name, k):
    if 'IOMallocAligned' in name:
        return m.alloc(0x40) if (m.seed + k) % 5 != 4 else 0
    if 'reset_req_bits' in name:                                 # sets the buffer-request bits the tail of set_id_mode tests (bit 0: buffer 0, bit 1: buffer 1)
        this = m.uc.reg_read(UC_PPC_REG_3)
        m.w32(this + 0xc1c, m.r32(this + 0xc1c) | ((m.seed + k) % 4))
        return 0
    if name.endswith('vtable slot +0x540'):                      # accelerator: allocate a transfer region
        return (m.seed + k) % 3 != 0
    if name.endswith('vtable slot +0x5dc'):                      # surface: is the panel record already active?
        return (m.seed + k) % 2
    return new_mock(m, name, k)


CASES += [
    Case('IOATIR500Surface::set_id_mode', w_set_id_mode, ret='u32', name='IOATIR500Surface::set_id_mode panels H3', seeds=300, mock=sid_mock, plain_words=True, ignore_args=REL,
         stack_args={'vtable slot +0x540': {1: 16}, 'vtable slot +0x544': {1: 16}}),
]


# ---------------------------------------------------------------- IOATIR500Surface::surface_lock_options / surface_unlock_options / surface_query_lock
def lock_surface(m, rng):
    """a surface ready to be locked: attachment buffer 0 (+0xb70) is one of the buffer records, with an optional backing-store record (+0x24: stamp +0x54, flag +0x58,
    memory descriptor +8, user mapping +0x10, offset/pitch halfwords +0x50/+0x52, flag +0x59)"""
    S, A = surf(m, rng)
    stamp = rng.choice([0, 5, 0x1234])
    m.w32(S + 0x7c, stamp)
    buf = S + 0xa8 + 0x78 * rng.randrange(0, 6)
    m.w32(S + 0xb70, buf)
    m.w32(buf + 0x10, rng.choice([0, plain(m, rng, 0x40), plain(m, rng, 0x40)]))
    m.w32(buf + 0x08, rng.choice([0, 0x100, 0x2000]))
    m.w16(buf + 0x18, rng.choice([0, 64, 640])); m.w16(buf + 0x1c, rng.choice([0, 64, 640])); m.w16(buf + 0x1e, rng.choice([0, 48, 480]))
    if rng.random() < 0.85:
        bs = m.alloc(0x80); fill_words(m, bs, 0x80, rng)
        m.w32(bs + 0x54, stamp if rng.random() < 0.85 else stamp + 1)
        m.w8(bs + 0x58, rng.choice([0, 0, 0, 1])); m.w8(bs + 0x59, rng.choice([0, 0, 1]))
        m.w32(bs + 0x08, rng.choice([0, plain(m, rng, 0x400, 0x800), plain(m, rng, 0x400, 0x800)]))
        m.w32(bs + 0x10, rng.choice([0, 0, plain(m, rng, 0x400, 0x800)]))
        m.w16(bs + 0x50, rng.choice([0, 0x40, 0x100])); m.w16(bs + 0x52, rng.choice([0, 640, 2560]))
        m.w32(buf + 0x24, bs)
    else:
        m.w32(buf + 0x24, 0)
    m.w8(S + 0xbd0, rng.choice([0, 0, 0, 0, 1, 3])); m.w8(S + 0xbd1, rng.choice([0, 0, 0, 0, 1, 3]))
    m.w32(S + 0xbf8, rng.choice([0, 0, 0, 1, 2, 3, 0x20000000, 0x20000003]))
    m.w32(S + 0xc1c, rng.choice([0, 1, 2, 3, 3]))
    m.w32(S + 0xc18, rng.choice([0, 0, 0x400, 0x7ffc00, 0x800000]))
    m.w32(S + 0x90, rng.choice([0, 0, obj(m, rng, 'ATIR500DVDContext', 0x400)]))
    for off in (0xbf0, 0xbf4, 0xbf7, 0xc08, 0xc09):
        m.w8(S + off, rng.choice([0, 1, 1]))
    m.w32(S + 0xc0c, rng.choice([0, 0x30000000])); m.w32(S + 0x78, rng.choice([0, 0x40000000]))
    m.w32(S + 0xbe8, rng.choice([0, 1, 6, 9, 10, 0xb, 0x30]))
    for off in (0xd70, 0xd74, 0xd78, 0xd7c, 0xd80):
        m.w32(S + off, word(rng))
    m.w32(A + 0x50, rng.randrange(1, 100)); m.w32(A + 0x7b8, rng.randrange(0, 5)); m.w32(A + 0x7bc, rng.randrange(0, 5))
    return S, A, buf


def w_lock_options(m, rng):
    S, A, buf = lock_surface(m, rng)
    data = m.alloc(0x60); fill_words(m, data, 0x60, rng)
    return [S, rng.choice([1, 2, 2, 1, 3]), rng.choice([0, 1, 2, 3, 1, 2, 7]), data, 0x44]


def lock_mock(m, name, k):
    r = (m.seed * 31 + k * 7) % 10
    if 'alloc_surfaces_retry' in name:
        return 0 if r < 7 else 0xe00002be
    if 'copy_buffer_to_backing_store' in name or 'move_buffer_to_backing_store' in name:
        return 1 if r < 7 else 0
    if name.endswith('vtable slot +0xdc'):                       # IOMemoryDescriptor state query: (state in, out state)
        out = m.uc.reg_read(UC_PPC_REG_5)
        if out > 0x1000: m.w32(out, [2, 4, 4, 1][(m.seed + k) % 4])
        return 0 if r < 8 else 0xe00002bc
    if name.endswith('vtable slot +0x558'):                      # accelerator: how many stamps retired / a count
        return r
    if name.endswith('vtable slot +0xd0'):
        return 0x10000000
    return new_mock(m, name, k)


CASES += [
    Case('IOATIR500Surface::surface_lock_options', w_lock_options, ret='u32', name='IOATIR500Surface::surface_lock_options states H3', seeds=1200, mock=lock_mock, plain_words=True,
         ignore_args=REL, out_extents={'vtable slot +0xdc': {2: 4}}),
]


def w_unlock_options(m, rng):
    S, A, buf = lock_surface(m, rng)
    m.w32(S + 0xd8c, rng.choice([0, 0, plain(m, rng, 0x40)]))                      # orphaned backing stores
    m.w8(S + 0xbd0, rng.choice([0, 1, 3])); m.w8(S + 0xbd1, rng.choice([0, 1, 3]))
    return [S, rng.choice([1, 2, 2]), rng.choice([0, 1])]


def w_query_lock(m, rng):
    S, A, buf = lock_surface(m, rng)
    m.w32(S + 0xbd0, rng.choice([0, 0, 0, 0x10000]))
    for i in range(2):                                                              # buffer records 0 and 1: storage bytes (+0x10 of the record) and GPU base (+8)
        m.w32(S + 0xa8 + 0x78 * i + 0x10, rng.choice([0, 0x1000]))
        m.w32(S + 0xa8 + 0x78 * i + 0x08, rng.choice([0, 0, 0x2000]))
    m.w32(S + 0xbf8, rng.choice([0, 1, 2, 3, 3, 0x20000003])); m.w32(S + 0xc1c, rng.choice([0, 1, 2, 3, 3]))
    return [S]


def q_mock(m, name, k):
    if name.endswith('vtable slot +0x5d0'):                                         # alloc_surface_buffer through the vtable
        return (m.seed + k) % 3 != 0
    return new_mock(m, name, k)


CASES += [
    Case('IOATIR500Surface::surface_unlock_options', w_unlock_options, ret='u32', name='IOATIR500Surface::surface_unlock_options states H3', seeds=200, mock=lock_mock, plain_words=True, ignore_args=REL),
    Case('IOATIR500Surface::surface_query_lock', w_query_lock, ret='u32', name='IOATIR500Surface::surface_query_lock states H3', seeds=300, mock=q_mock, plain_words=True, ignore_args=REL),
]


# ---------------------------------------------------------------- IOATIR500Surface::surface_read
def w_surface_read(m, rng):
    S, A, buf = lock_surface(m, rng)
    m.w16(S + 0xbd4, rng.choice([64, 640, 1024])); m.w16(S + 0xbd6, rng.choice([48, 480, 768]))
    m.w16(buf + 0x16, rng.choice([2, 4, 4]))
    m.w32(S + 0xbd0, 0)
    w, h = m.r16(S + 0xbd4), m.r16(S + 0xbd6)
    rd = m.alloc(0x40); fill_words(m, rd, 0x40, rng)
    x = rng.choice([0, 0, 8, -4 & 0xffffffff, w - 4, w + 5, 0xfffffff0])
    y = rng.choice([0, 0, 8, -4 & 0xffffffff, h - 4, h + 5, 0xfffffff0])
    m.w32(rd, x); m.w32(rd + 4, y)
    m.w32(rd + 8, rng.choice([1, 16, 32, 100, 2000])); m.w32(rd + 0xc, rng.choice([1, 8, 32, 100, 1000]))
    m.w32(rd + 0x10, rng.choice([0x40000000, 0x40000123, 0x40001000]))               # destination address
    m.w32(rd + 0x14, rng.choice([64, 256, 4096]))                                    # destination pitch
    m.w32(A + 0x7b4, rng.randrange(0, 5))
    m.w8(S + 0xbf7, rng.choice([0, 1, 1]))
    return [S, rd, 0x18]


def read_mock(m, name, k):
    r = (m.seed * 17 + k * 5) % 10
    if 'withAddress' in name:                                    # IOMemoryDescriptor::withAddress: a descriptor or nothing
        return plain(m, rng_for(m, k), 0x400, 0x800) if r != 9 else 0
    if 'copy_from_buffer' in name or name.endswith('vtable slot +0x5e8'):
        from unicorn.ppc_const import UC_PPC_REG_1
        sp = m.uc.reg_read(UC_PPC_REG_1)
        ptr = m.r32(sp + 0x3c)
        if ptr > 0x1000:
            m.w32(ptr + 4, r % 2)                                # the transfer record's GART field: set now and then
        return 0
    return lock_mock(m, name, k)


def rng_for(m, k):
    import random
    return random.Random(m.seed * 1000 + k)


CASES += [
    Case('IOATIR500Surface::surface_read', w_surface_read, ret='u32', name='IOATIR500Surface::surface_read ranges H3', seeds=500, mock=read_mock, plain_words=True,
         ignore_args=REL, out_extents={'vtable slot +0xdc': {2: 4}, 'copy_from_buffer': {9: [(4, 4), (0xe, 2)]}, 'vtable slot +0x5e8': {9: [(4, 4), (0xe, 2)]}}),
]
