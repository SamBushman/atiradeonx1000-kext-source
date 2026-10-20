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


def slot(name, off):
    """does this mocked call go through vtable slot `off` (named `X::m() [vcall +0xNNN]` when the vtable listing names it, `vtable slot +0xNNN` when not)"""
    return name.endswith('[vcall +0x%x]' % off) or name.endswith('vtable slot +0x%x' % off)
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
    if slot(name, 0x540):                      # accelerator: allocate a transfer region
        return (m.seed + k) % 3 != 0
    if slot(name, 0x5dc):                      # surface: is the panel record already active?
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
    if slot(name, 0xdc):                       # IOMemoryDescriptor state query: (state in, out state)
        out = m.uc.reg_read(UC_PPC_REG_5)
        if out > 0x1000: m.w32(out, [2, 4, 4, 1][(m.seed + k) % 4])
        return 0 if r < 8 else 0xe00002bc
    if slot(name, 0x558):                      # accelerator: how many stamps retired / a count
        return r
    if slot(name, 0xd0):
        return 0x10000000
    return new_mock(m, name, k)


CASES += [
    Case('IOATIR500Surface::surface_lock_options', w_lock_options, ret='u32', name='IOATIR500Surface::surface_lock_options states H3', seeds=450, mock=lock_mock, plain_words=True,
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
    if slot(name, 0x5d0):                                         # alloc_surface_buffer through the vtable
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
    if 'copy_from_buffer' in name or slot(name, 0x5e8):
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
    Case('IOATIR500Surface::surface_read', w_surface_read, ret='u32', name='IOATIR500Surface::surface_read ranges H3', seeds=250, mock=read_mock, plain_words=True,
         ignore_args=REL, out_extents={'vtable slot +0xdc': {2: 4}, 'copy_from_buffer': {9: [(4, 4), (0xe, 2)]}, 'vtable slot +0x5e8': {9: [(4, 4), (0xe, 2)]}}),
]


# ---------------------------------------------------------------- IOATIR500Surface::surface_buffer_idx_mask, reset_access
def w_idx_mask(m, rng):
    S, A = surf(m, rng)
    for off in (0xb70, 0xb74, 0xb80, 0xb84):                                          # attachment table entries: the primary buffer record or the second one
        m.w32(S + off, rng.choice([S + 0xa8, S + 0x120, S + 0x300, S + 0x288]))
    m.w32(S + 0xc18, rng.choice([0, 1, 2, 3]))
    out = m.alloc(0x10)
    return [S, rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 0xb, 0x11, 0x12, 0x20]), out]


def reset_access_mock(m, name, k):
    if slot(name, 0x604):                                           # (re)computes the access descriptor
        this = m.uc.reg_read(UC_PPC_REG_3)
        if (m.seed + k) % 3:
            m.w32(this + 0xc00, plain(m, rng_for(m, k), 0x400, 0x800))
        return 0
    if slot(name, 0x150) or slot(name, 0x14c):    # createMappingInTask / map: a mapping object or nothing
        return plain(m, rng_for(m, k), 0x400, 0x800) if (m.seed + k) % 4 != 3 else 0
    if slot(name, 0xd0):
        return 0x10000000 + k
    return new_mock(m, name, k)


def w_reset_access(m, rng):
    S, A = surf(m, rng)
    m.w32(S + 0xc00, rng.choice([0, plain(m, rng, 0x400, 0x800)]))                       # access descriptor before the call
    m.w32(S + 0xd84, rng.choice([0, plain(m, rng, 0x400, 0x800)]))                       # user mapping
    m.w32(S + 0xd88, rng.choice([0, plain(m, rng, 0x400, 0x800)]))                       # kernel mapping
    m.w8(S + 0xbf4, rng.choice([0, 1, 1]))
    m.w32(S + 0x78, rng.choice([0, 0x40000000]))
    return [S]


CASES += [
    Case('IOATIR500Surface::surface_buffer_idx_mask', w_idx_mask, ret='u32', name='IOATIR500Surface::surface_buffer_idx_mask types H3', seeds=300, mock=new_mock, ignore_args=REL),
    Case('IOATIR500Surface::reset_access', w_reset_access, ret='void', name='IOATIR500Surface::reset_access mappings H3', seeds=200, mock=reset_access_mock, plain_words=True, ignore_args=REL),
]


# ---------------------------------------------------------------- IOATIR500Surface::alloc_surfaces_retry / alloc_surfaces_pageq
def w_retry(m, rng):
    S, A = surf(m, rng)
    m.w8(A + 0x80, rng.choice([0, 1, 1, 1]))
    m.w8(S + 0xbd0, rng.choice([0, 0, 1])); m.w8(S + 0xbd1, rng.choice([0, 0, 1]))
    m.w32(S + 0xbf8, rng.choice([0, 1, 2, 3, 3, 0x20000000, 0x20000003]))
    m.w32(S + 0xc1c, rng.choice([0, 1, 2, 3]))
    return [S, rng.choice([0, 1, 2, 3, 3]), rng.choice([0, 1, 2, 2])]


def retry_mock(m, name, k):
    if 'alloc_surfaces_pageq' in name:                 # 0 allocated, 1 busy (retry), 2 failed; mostly settles after a few busy answers; now and then stays busy for ever
        if m.seed % 23 == 5:
            return 1 if k < 1100 else 0
        return [1, 1, 0, 2, 0][(m.seed + (k if k < 3 else 4)) % 5] if k < 3 else (0 if (m.seed % 2) else 2)
    return default_mock(m, name, k)


def w_pageq(m, rng):
    S, A = surf(m, rng)
    m.w32(S + 0xbf8, rng.choice([0, 1, 3, 5, 0x7fffff, 0x20000003, 0x400001]))
    # the other surfaces on the accelerator's circular list (head A+0x5c, linked through +0x9c): some locked
    n = rng.choice([0, 1, 2, 3])
    others = [obj(m, rng, 'ATIR500Surface', 0xe00) for _ in range(n)]
    ring = [S] + others
    for i, o in enumerate(ring):
        m.w32(o + 0x9c, ring[(i + 1) % len(ring)])
        m.w32(o + 0xbd0, rng.choice([0, 0, 0, 1, 3]))
    m.w32(A + 0x5c, rng.choice([S, ring[-1], 0]))
    for i in range(23):
        m.w32(S + 0xb0 + 0x78 * i, rng.choice([0, 0, 0x1000]))
    return [S, rng.choice([1, 3, 0x7fffff, 4, 0]), rng.choice([0, 1, 0x7fffff]), rng.choice([0, 1])]


def pageq_mock(m, name, k):
    if slot(name, 0x5f4):                              # allocate buffer `index`: succeeds mostly
        return 1 if (m.seed * 13 + k * 3) % 10 < 6 else 0
    return default_mock(m, name, k)


CASES += [
    Case('IOATIR500Surface::alloc_surfaces_retry', w_retry, ret='u32', name='IOATIR500Surface::alloc_surfaces_retry states H3', seeds=300, mock=retry_mock, plain_words=True, limit=400000),
    Case('IOATIR500Surface::alloc_surfaces_pageq', w_pageq, ret='u32', name='IOATIR500Surface::alloc_surfaces_pageq lists H3', seeds=300, mock=pageq_mock, plain_words=True),
]


# ---------------------------------------------------------------- IOATIR500Surface::copy_buffer_from_backing_store / copy_buffer_to_backing_store / connect_buffer_backing_store
def backed_buffer(m, rng, S, with_bs=True):
    """a surface buffer record with its backing-store record (+0x24: descriptor +8, GART state +4, header +0x14, stamp +0x54, flag +0x58) and level counts (+0x20/+0x22)"""
    buf = S + 0xa8 + 0x78 * rng.randrange(0, 6)
    stamp = m.r32(S + 0x7c)
    m.w32(buf + 0x10, rng.choice([0x1000, 0x4000]))
    m.w16(buf + 0x20, rng.choice([0, 1, 2])); m.w16(buf + 0x22, rng.choice([0, 1, 3]))
    m.w16(buf + 0x1e, rng.choice([16, 480]))
    if with_bs:
        bs = m.alloc(0x80); fill_words(m, bs, 0x80, rng)
        m.w32(bs + 0x04, rng.choice([0, 1])); m.w32(bs + 0x08, rng.choice([0, plain(m, rng, 0x400, 0x800)]))
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(bs + 0x14, hdr)
        m.w32(bs + 0x54, rng.choice([stamp, stamp, stamp - 1, 7])); m.w8(bs + 0x58, rng.choice([0, 1, 1]))
        m.w32(buf + 0x24, bs)
        # other buffer records point at backing stores too (the loop retargets those whose stamp matched)
        for i in range(23):
            if rng.random() < 0.3:
                o = m.alloc(0x80); fill_words(m, o, 0x80, rng); m.w32(o + 0x54, rng.choice([stamp - 1, stamp, 7]))
                m.w32(S + 0xcc + 0x78 * i, o)
            else:
                m.w32(S + 0xcc + 0x78 * i, 0)
        m.w32(S + 0xcc + 0x78 * ((buf - S - 0xa8) // 0x78), bs)
    else:
        m.w32(buf + 0x24, 0)
    return buf


def w_copy_backing(m, rng):
    S, A = surf(m, rng)
    m.w32(S + 0x7c, rng.choice([5, 0x1234]))
    buf = backed_buffer(m, rng, S, with_bs=rng.random() < 0.9)
    for off in (0xc08, 0xc09, 0xbf7):
        m.w8(S + off, rng.choice([0, 0, 1]))
    m.w8(S + 0xbf7, rng.choice([0, 1, 1]))
    m.w32(S + 0xbd0, rng.choice([0, 0, 0x10000]))
    m.w32(A + 0x50, rng.randrange(1, 50)); m.w32(A + 0x724, rng.randrange(0, 100)); m.w32(A + 0x728, rng.randrange(0, 100)); m.w32(A + 0x7b4, rng.randrange(0, 100))
    return [S, buf]


def backing_mock(m, name, k):
    r = (m.seed * 29 + k * 11) % 10
    if 'buffer_map_offset' in name:                                  # (buffer, index, level, &width, &height, 0): the mip level's size
        w, h = m.uc.reg_read(UC_PPC_REG_7), m.uc.reg_read(UC_PPC_REG_8)
        if w > 0x1000: m.w32(w, [16, 64, 256][(m.seed + k) % 3])
        if h > 0x1000: m.w32(h, [16, 64, 128][(m.seed + k * 2) % 3])
        return 0
    if slot(name, 0x5e4) or 'alloc_buffer_backing_store' in name:       # alloc_buffer_backing_store(buffer): installs the record (+0x24) or fails
        buf = m.uc.reg_read(UC_PPC_REG_4)
        if r < 7:
            bs = m.alloc(0x80)
            m.w32(bs + 0x14, m.alloc(0x40)); m.w32(bs + 0x08, plain(m, rng_for(m, k), 0x400, 0x800) if r < 4 else 0)
            m.w32(buf + 0x24, bs)
            return 1
        return 0
    if 'copy_to_buffer' in name or 'copy_from_buffer' in name or slot(name, 0x5e8) or slot(name, 0x5ec):
        return 0
    if slot(name, 0x55c):
        return r
    return lock_mock(m, name, k)


from unicorn.ppc_const import UC_PPC_REG_8

BACKING_EXT = {'buffer_map_offset': {4: 4, 5: 4}, 'vtable slot +0xdc': {2: 4}}

CASES += [
    Case('IOATIR500Surface::copy_buffer_from_backing_store', w_copy_backing, ret='u32', name='IOATIR500Surface::copy_buffer_from_backing_store H3', seeds=300, mock=backing_mock, plain_words=True,
         ignore_args=REL, out_extents=BACKING_EXT),
    Case('IOATIR500Surface::copy_buffer_to_backing_store', w_copy_backing, ret='bool', name='IOATIR500Surface::copy_buffer_to_backing_store H3', seeds=300, mock=backing_mock, plain_words=True,
         ignore_args=REL, out_extents=BACKING_EXT),
]


def w_connect(m, rng):
    S, A = surf(m, rng)
    buf = backed_buffer(m, rng, S, with_bs=True)
    m.w32(S + 0xd4c, rng.choice([0, 0, 0x8000]))
    m.w32(S + 0x78, rng.choice([0, 0x40000000]))
    return [S, buf, rng.choice([0x40000000, 0x40000123, 0x40001000]), rng.choice([64, 640, 2560])]


def connect_mock(m, name, k):
    if 'withAddress' in name:
        return plain(m, rng_for(m, k), 0x400, 0x800) if (m.seed + k) % 5 != 4 else 0
    return backing_mock(m, name, k)


CASES += [
    Case('IOATIR500Surface::connect_buffer_backing_store', w_connect, ret='bool', name='IOATIR500Surface::connect_buffer_backing_store H3', seeds=120, mock=connect_mock, plain_words=True,
         ignore_args=REL, out_extents=BACKING_EXT),
]


# ---------------------------------------------------------------- IOATIR500Surface: alloc_surface(_keep), prune_buffers, resetFullScreen, reset_req_bits, remove_*_context(_from_list), free_buffer_backing_orphans
def buffers_state(m, rng, S, p_storage=0.6):
    """the 23 buffer records: storage bytes (+0x10), GPU base (+8), backing store (+0x24) set or clear"""
    for i in range(23):
        r = S + 0xa8 + 0x78 * i
        m.w32(r + 0x10, rng.choice([0, 0x1000]) if rng.random() < p_storage else 0)
        m.w32(r + 0x08, rng.choice([0, 0, 0x2000]))
        m.w32(r + 0x24, rng.choice([0, 0, plain(m, rng, 0x40)]))


def w_alloc_surface(m, rng):
    S, A = surf(m, rng)
    buffers_state(m, rng, S)
    m.w32(S + 0xbf8, rng.choice([0, 0xffffffff, 0x1, 0x3f]))
    return [S, rng.choice([0, 1, 2, 5, 22]), rng.choice([0, 1])]


def w_alloc_surface_keep(m, rng):
    S, A = surf(m, rng)
    buffers_state(m, rng, S)
    m.w32(S + 0xbf8, rng.choice([0, 0xffffffff, 0x1, 0x3f]))
    other = obj(m, rng, 'ATIR500Surface', 0xe00)
    tex = m.alloc(0x40)
    return [S, other, tex, rng.choice([0, 1, 3]), rng.choice([0, 1, 2, 5, 22])]


def surf_mock(m, name, k):
    r = (m.seed * 19 + k * 7) % 10
    if slot(name, 0x5d0) or 'alloc_surface_buffer' in name:         # vtable alloc_surface_buffer(buffer)
        return 1 if r < 4 else 0
    if 'freeToAllocSurfaceVRAM' in name:
        return 1 if r < 7 else 0
    if 'surface_buffer_idx_mask' in name:                          # (type, &mask): the mask word
        out = m.uc.reg_read(UC_PPC_REG_5)
        if out > 0x1000: m.w32(out, [1, 2, 4, 0x10, 0x30][(m.seed + k) % 5])
        return (m.seed + k) % 8
    if slot(name, 0x5dc):                                            # is_flip_allowed
        return r % 2
    return new_mock(m, name, k)


def w_prune(m, rng):
    S, A = surf(m, rng)
    buffers_state(m, rng, S)
    m.w32(S + 0xbe8, rng.choice([0, 0x20, 0x30, 0x10, 0x8000, 0x8020]))
    m.w32(S + 0xc18, rng.choice([0, 1, 2, 3, 0x11, 0x13, 0x30, 0x20, 0x10, 0x7fffff]))
    m.w32(S + 0xbf8, rng.choice([0, 1, 2, 3, 0x20000000]))
    m.w32(S + 0xc1c, rng.choice([0, 1, 2, 0x30000000]))
    panel = rng.choice([0, 1, 0xffff]); m.w32(S + 0xc14, panel)
    for p in range(2):
        m.w32(A + 0xe8 + 0x20 * p, rng.choice([0, S]))                              # panel owner: this surface or not
    for off in (0xb70, 0xb74, 0xb80, 0xb84):
        m.w32(S + off, rng.choice([S + 0xa8, S + 0x120, S + 0x288, S + 0x300]))
    return [S]


def w_reset_full_screen(m, rng):
    S, A = surf(m, rng)
    m.w32(S + 0xb70, rng.choice([S + 0x120, S + 0xa8]))
    m.w32(S + 0xc14, rng.choice([0, 1]))
    m.w32(A + 0xd0, rng.choice([0, 1, 2, 3]))
    m.w32(A + 0x74c, rng.randrange(0, 5))
    return [S]


def ctx_chain(m, rng, cls, bits_off=0x8c):
    head = 0
    for _ in range(rng.choice([0, 1, 2, 3])):
        n = obj(m, rng, cls, 0x400); m.w32(n + 0x84, head); m.w32(n + bits_off, rng.choice([0, 1, 2, 0x10, 0x100])); head = n
    return head


def w_reset_req_bits(m, rng):
    S, A = surf(m, rng)
    m.w32(S + 0xc1c, rng.choice([0, 1, 0x30000020, 0x7fffffff]))
    m.w32(S + 0x88, ctx_chain(m, rng, 'ATIR500GLContext')); m.w32(S + 0x8c, ctx_chain(m, rng, 'ATIR5002DContext'))
    dvd = obj(m, rng, 'ATIR500DVDContext', 0x400); m.w32(dvd + 0x88, rng.choice([0, 4, 0x40]))
    m.w32(S + 0x90, rng.choice([0, dvd]))
    m.w32(S + 0xbf8, rng.choice([0, 1, 2, 3]))
    m.w32(S + 0x144, rng.choice([0, 0x5000])); m.w32(S + 0xcc, rng.choice([0, 0x5000]))
    head = 0
    for _ in range(rng.choice([0, 1, 2, 3])):                            # list of buffer descriptors (+0xbcc, linked through +0x54), type word at +0x58
        n = m.alloc(0x80); m.w32(n + 0x58, rng.choice([0x11, 0x11, 1, 2, 3, 4, 7]))
        m.w32(n + 0x54, head); head = n
    m.w32(S + 0xbcc, head)
    return [S]


def w_remove_dvd(m, rng):
    S, A = surf(m, rng)
    dvd = obj(m, rng, 'ATIR500DVDContext', 0x400)
    m.w32(S + 0x90, rng.choice([dvd, dvd, 0, obj(m, rng, 'ATIR500DVDContext', 0x400)]))
    return [S, dvd]


def w_remove_ctx_list(cls, off):
    def w(m, rng):
        S, A = surf(m, rng)
        chain = [obj(m, rng, cls, 0x400) for _ in range(rng.choice([1, 2, 3, 4]))]
        for i, c in enumerate(chain):
            m.w32(c + 0x84, chain[i + 1] if i + 1 < len(chain) else 0)
        m.w32(S + off, chain[0])
        victim = rng.choice(chain + [obj(m, rng, cls, 0x400)])                # in the list at any position, or not in it
        return [S, victim]
    return w


def w_orphans(m, rng):
    S, A = surf(m, rng)
    o = m.alloc(0x80); fill_words(m, o, 0x80, rng); m.w32(o + 0x10, rng.choice([0, plain(m, rng, 0x40)]))
    m.w32(S + 0xd8c, o)
    return [S]


CASES += [
    Case('IOATIR500Surface::alloc_surface', w_alloc_surface, ret='bool', name='IOATIR500Surface::alloc_surface buffers H3', seeds=300, mock=surf_mock, plain_words=True, ignore_args=REL),
    Case('IOATIR500Surface::alloc_surface_keep', w_alloc_surface_keep, ret='bool', name='IOATIR500Surface::alloc_surface_keep buffers H3', seeds=300, mock=surf_mock, plain_words=True, ignore_args=REL),
    Case('IOATIR500Surface::prune_buffers', w_prune, ret='void', name='IOATIR500Surface::prune_buffers modes H3', seeds=300, mock=surf_mock, plain_words=True, ignore_args=REL),
    Case('IOATIR500Surface::resetFullScreen', w_reset_full_screen, ret='void', name='IOATIR500Surface::resetFullScreen H3', seeds=120, mock=surf_mock, plain_words=True, ignore_args=REL),
    Case('IOATIR500Surface::reset_req_bits', w_reset_req_bits, ret='void', name='IOATIR500Surface::reset_req_bits lists H3', seeds=200, mock=surf_mock, plain_words=True, ignore_args=REL,
         out_extents={'surface_buffer_idx_mask': {2: 4}}),
    Case('IOATIR500Surface::remove_dvd_context', w_remove_dvd, ret='void', name='IOATIR500Surface::remove_dvd_context H3', seeds=40, mock=surf_mock, ignore_args=REL),
    Case('IOATIR500Surface::remove_2d_context_from_list', w_remove_ctx_list('ATIR5002DContext', 0x8c), ret='void', name='IOATIR500Surface::remove_2d_context_from_list H3', seeds=60, mock=surf_mock, ignore_args=REL),
    Case('IOATIR500Surface::remove_gl_context_from_list', w_remove_ctx_list('ATIR500GLContext', 0x88), ret='void', name='IOATIR500Surface::remove_gl_context_from_list H3', seeds=60, mock=surf_mock, ignore_args=REL),
    Case('IOATIR500Surface::free_buffer_backing_orphans', w_orphans, ret='void', name='IOATIR500Surface::free_buffer_backing_orphans H3', seeds=60, mock=surf_mock, ignore_args=REL),
]


# ---------------------------------------------------------------- IOATIR500Surface::set_shape_backing_length_ext
def w_shape_ext(m, rng):
    S, A = surf(m, rng)
    n = rng.choice([0, 1, 1, 2, 3])
    region = m.alloc(0x80); fill_words(m, region, 0x80, rng)
    m.w32(region, n)
    m.w32(region + 4, rng.choice([0, 1, 0x100]))
    m.w32(region + 8, 0)
    w, h = rng.choice([0, 640, 1024]), rng.choice([0, 480, 768])
    if rng.random() < 0.05: w = 0xfff0                                           # negative as a signed halfword: rejected
    m.w16(region + 8, w); m.w16(region + 10, h)
    for i in range(3):
        m.w32(region + 0xc + 8 * i, rng.choice([0, 8, 16])); m.w32(region + 0x10 + 8 * i, rng.choice([0, 1, 640]))
    m.w16(region + 0x10, rng.choice([0, 0, 320, 640])); m.w16(region + 0x12, rng.choice([0, 0, 200, 480]))
    npanels = rng.choice([1, 2, 2])
    m.w32(A + 0xcc, npanels)
    m.w8(A + 0x80, rng.choice([0, 1, 1]))
    m.w32(A + 0xd0, rng.choice([0, 1, 2, 3]))
    m.w32(A + 0x804, rng.choice([0, 0x10000]))
    exact = n * 8 + 0xc
    rsize = rng.choice([0, exact, exact, exact + 4])
    shape = rng.choice([0, 1, 4, 0x80, 0x20, 0x10, 8, 4 | 0x20, 0x3d, 0xb5, 0xff]) 
    m.w32(S + 0xbd0, rng.choice([0, 0, 0, 0x10000]))
    m.w32(S + 0xbe8, rng.choice([0x20, 0x20, 0x20, 0]))
    m.w8(S + 0xbec, rng.choice([0, 0, 1]))
    m.w16(S + 0xbee, rng.choice([0, 0, 1]))
    m.w32(S + 0xd70, rng.choice([0, 2, 3]))
    m.w32(S + 0xbf8, rng.choice([0, 0x20000000, 3]))
    for p in range(2):
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(hdr + 8, rng.choice([m.r32(region + 8), 0x1234]))
        m.w32(S + 0xd60 + 8 * p, rng.choice([0, hdr])); m.w32(S + 0xd64 + 8 * p, rng.choice([0, 0x100, exact, exact + 0x100, 0x2000]))
    buf = S + 0xa8 + 0x78 * rng.randrange(0, 2)
    m.w32(S + 0xb70, buf); m.w32(buf + 0x10, rng.choice([0, 0x1000])); m.w32(buf + 0x24, rng.choice([0, plain(m, rng, 0x40)]))
    m.w32(S + 0x7c, rng.choice([5, 9])); m.w32(S + 0x80, rng.choice([5, 9]))
    m.w32(A + 0x7c0, rng.randrange(0, 5))
    return [S, shape, rng.choice([0, 1, 1, 2]), rng.choice([0, 0x40000000, 0x40000000]), rng.choice([0, 640, 0xffffffff, 0xffffffff]), region, rsize, rng.choice([0, 0x8000])]


def shape_ext_mock(m, name, k):
    r = (m.seed * 23 + k * 5) % 10
    if 'IOLockSleep' in name:                                         # the hardware comes up while this thread sleeps
        acc = m.uc.reg_read(UC_PPC_REG_4)
        m.w8(acc + 0x80, 1)
        return 0
    if slot(name, 0x5b0) or 'is_surface_size_supported' in name:      # is the size supported
        return 1 if r < 7 else 0
    if 'connect_buffer_backing_store' in name:
        return 1 if r < 6 else 0
    if slot(name, 0x540):
        return 1 if r < 7 else 0
    return sid_mock(m, name, k) if ('IOMallocAligned' in name or slot(name, 0x544) or slot(name, 0x5dc)) else surf_mock(m, name, k)


CASES += [
    Case('IOATIR500Surface::set_shape_backing_length_ext', w_shape_ext, ret='u32', name='IOATIR500Surface::set_shape_backing_length_ext regions H3', seeds=400, mock=shape_ext_mock, plain_words=True,
         ignore_args=REL, stack_args={'vtable slot +0x540': {1: 16}, 'vtable slot +0x544': {1: 16}}),
]


def w_cmft_surface(m, rng):
    S, A = surf(m, rng)
    m.w32(A + 0xcc, rng.choice([1, 2, 2]))
    for p in range(2):                                           # panel records: entries[0] = (memory descriptor, header), then the swap buffer size
        base = S + 0xc20 + p * 0x94
        m.w32(base, plain(m, rng, 0x400, 0x800)); m.w32(base + 0x08, rng.choice([0, plain(m, rng, 0x100)]))
        m.w32(base + 0x90, rng.choice([0, 0x1000, 0x10000]))
    return [S, rng.choice([0, 1, 1, 2, 5]), m.alloc(0x10), m.alloc(0x10)]


CASES += [
    Case('IOATIR500Surface::clientMemoryForType', w_cmft_surface, ret='u32', name='IOATIR500Surface::clientMemoryForType panels H3', seeds=80, mock=surf_mock, plain_words=True, ignore_args=REL),
]


# ---------------------------------------------------------------- ATIR500Surface::prepare_vram / complete_vram
def vram_world(m, rng, prepare):
    S, A = surf(m, rng)
    m.w8(A + 0x990, rng.choice([0, 1, 4, 8, 32]))                       # number of VRAM-lock slots
    m.w32(A + 0x890, rng.choice([0, 1, 3, 0xff, 0xffffffff, 5, 0x55]))   # slot-in-use mask
    m.w8(A + 0x80, rng.choice([0, 1, 1]))                               # hardware up
    pk = m.alloc(0x200); fill_words(m, pk, 0x200, rng)
    m.w32(A + 0x238, pk); m.w32(A + 0x234, word(rng))
    m.w32(A + 0x228, rng.choice([0, 0x1000]))
    buf = S + 0xa8 + 0x78 * rng.randrange(0, 6)
    m.w8(buf + 0x3c, rng.choice([0, 1, 2, 0xff]) if prepare else rng.choice([0, 1, 1, 2]))
    m.w8(buf + 0x37, rng.choice([0, 3, 7, 0xff]))
    m.w8(buf + 0x38, rng.choice([0, 1, 2, 3, 4, 5, 9]))
    m.w8(buf + 0x39, rng.choice([0, 1, 2, 3]))
    m.w8(buf + 0x3d, rng.choice([0, 0x00, 0x10, 0x20, 0xf0]))                  # bits 20..23 of the word at +0x3c (the byte at +0x3c is its top byte)
    m.w8(buf + 0x3e, rng.choice([0, 0x08]))                                    # bit 0x800: depth buffer needing a decompress
    m.w32(buf + 0x08, rng.choice([0, 0x1000, 0x20000])); m.w32(buf + 0x10, rng.choice([0, 0x1000, 0x2000]))
    m.w16(buf + 0x18, rng.choice([0, 64, 640]))
    return [S, buf]


def vram_mock(m, name, k):
    if 'decompress_and_flush_depth_buffer' in name:
        return [0, 6, 10, 11][(m.seed + k) % 4]
    if 'submit_buffer' in name:
        return m.seed * 3 + k
    return surf_mock(m, name, k)


CASES += [
    Case('ATIR500Surface::prepare_vram', lambda m, r: vram_world(m, r, True), ret='u32', name='ATIR500Surface::prepare_vram slots H3', seeds=300, mock=vram_mock, plain_words=True, ignore_args=REL),
    Case('ATIR500Surface::complete_vram', lambda m, r: vram_world(m, r, False), ret='u32', name='ATIR500Surface::complete_vram slots H3', seeds=200, mock=vram_mock, plain_words=True, ignore_args=REL),
]


# ---------------------------------------------------------------- ATIR500Surface: real_to_hex, calc_h_inc_step_by, is_surface_size_supported, buffer_map_offset
FLOAT_VALUES = [3.0e9, 2147483648.0, 4294967295.0, 5.0e9, -5.0e9, 1e30, float("inf"), float("-inf"), float("nan"), -3000.0, -2047.5, -10.0, -8.5, 0.0, 1.0, -1.0, 0.5, -0.25, 1.5, 3.999, -3.999, 7.9, -7.9, 100.0, 1000.0, -1000.0, 2047.5, 0.3333, -0.7, 1e-6, 33.3, 65535.0]


def w_real_to_hex(m, rng):
    m.fargs = [rng.choice(FLOAT_VALUES) + rng.choice([0.0, 0.001, 0.123])]
    S = obj(m, rng, 'ATIR500Surface', 0x100)
    return [S, rng.choice([0, 1, 1, 0, 2])]


def w_calc_h_inc(m, rng):
    S = obj(m, rng, 'ATIR500Surface', 0x100)
    m.fargs = [rng.choice([0.25, 0.5, 0.75, 1.0, 1.5, 2.0, 3.0, 4.0, 0.1, 8.0, 1e-4, 1e-9, 64.0, 1000.0, 0.0, 1e7, 1e9, 3e12])]
    outs = [m.alloc(0x10) for _ in range(9)]
    mode = rng.choice([3, 4, 6, 9, 10, 0xb, 0xc, 0xd, 0xe, 0, 5, 7])
    return [S, mode, 0, rng.randrange(0, 12), rng.randrange(0, 12), rng.choice([0, 1, 1, 2])] + outs      # the float `scale` (f1) takes the r5 slot; o6/o7 in r9/r10, o8..o14 on the stack


def w_size_supported(m, rng):
    S, A = surf(m, rng)
    m.w16(A + 0xa8, rng.choice([0, 1024, 0x1000, 0x2000])); m.w16(A + 0xaa, rng.choice([0, 768, 0x1000, 0x2000]))
    sx = lambda v: v & 0xffffffff
    return [S, sx(rng.choice([-1, 0, 4, 640, 1024, 0x1000, 0x1001, 0x2000])), sx(rng.choice([-1, 0, 4, 480, 768, 0x1000, 0x1001, 0x2000]))]


def w_map_offset2(m, rng):
    S = obj(m, rng, 'ATIR500Surface', 0x100)
    buf = m.alloc(0x80); fill_words(m, buf, 0x80, rng)
    m.w32(buf + 0x3c, rng.choice([0, 0x100000, 0x200000, 0x400000, 0x300000 | 0x800, 0xf00000]))
    m.w16(buf + 0x1c, rng.choice([0, 7, 64, 640])); m.w16(buf + 0x1e, rng.choice([0, 1, 48, 480]))
    m.w16(buf + 0x14, rng.choice([0, 64, 640])); m.w16(buf + 0x16, rng.choice([0, 2, 4])); m.w16(buf + 0x20, rng.choice([0, 1, 6]))
    outs = [m.alloc(0x10) if rng.random() < 0.8 else 0 for _ in range(3)]
    return [S, buf, rng.choice([0, 1, 2, 3]), rng.choice([0, 1, 2, 4, 9])] + outs


CASES += [
    Case('ATIR500Surface::real_to_hex', w_real_to_hex, ret='u32', name='ATIR500Surface::real_to_hex values H3', seeds=300, plain_words=True),
    Case('ATIR500Surface::calc_h_inc_step_by', w_calc_h_inc, ret='u32', name='ATIR500Surface::calc_h_inc_step_by modes H3', seeds=800, plain_words=True),
    Case('ATIR500Surface::is_surface_size_supported', w_size_supported, ret='s32', name='ATIR500Surface::is_surface_size_supported H3', seeds=80, mock=surf_mock, plain_words=True, ignore_args=REL),
    Case('IOATIR500Surface::is_surface_size_supported', w_size_supported, ret='s32', name='IOATIR500Surface::is_surface_size_supported H3', seeds=80, mock=surf_mock, plain_words=True, ignore_args=REL),
    Case('ATIR500Surface::buffer_map_offset', w_map_offset2, ret='s32', name='ATIR500Surface::buffer_map_offset H3', seeds=150, plain_words=True),
]


def fbits(f):
    return struct.unpack('>I', struct.pack('>f', f))[0]


def w_surf_desc(m, rng):
    S = obj(m, rng, 'ATIR500Surface', 0xe00)
    info = m.alloc(0x100); fill_words(m, info, 0x100, rng)
    m.w32(info + 0x3c, rng.choice([9, 10, 3, 4, 6, 0xb, 0xd, 0]))
    m.w32(info + 0x40, rng.choice([0, 64, 1280, 4096]))
    m.w32(info + 0xe0, rng.choice([0, 0, 1, 2]))
    for off in (0xd4, 0xd8, 0xdc):                                             # chroma plane sizes: positive, negative, multiples of 16 or not
        m.w32(info + off, rng.choice([0, 16, 100, 0x7fffffff & 0x1000, (-48) & 0xffffffff, (-5) & 0xffffffff, 7]))
    m.w32(info + 0x10, rng.choice([0, 7, 640, (-16) & 0xffffffff])); m.w32(info + 0x14, rng.choice([0, 5, 480, (-9) & 0xffffffff]))
    m.w32(info + 0x30, fbits(rng.choice([0.0, 0.5, 1.0, 2.0, 1e10, -3.0]))); m.w32(info + 0x34, fbits(rng.choice([0.0, 1.0, 0.25, 4.0, 1e12])))
    m.w32(info + 0x4c, rng.choice([1, 2, 3, 16])); m.w32(info + 0x50, rng.choice([1, 2, 4, 7]))
    m.w32(info + 0x54, rng.choice([0, 0x3f, 0x15, 0x2a, 1]))
    m.w32(info + 0x44, rng.choice([0, 3, 640, 70000])); m.w32(info + 0x48, rng.choice([0, 3, 480, 70000]))
    m.w32(S + 0x128, rng.choice([0, 0x1000, 0x40000]))                                              # buffer1GpuBase
    idx = rng.choice([0, 1, 2])
    m.w32(S + 0xd90, idx)                                                                           # currentBufferIndex
    for i in range(3):
        m.w32(S + 0x560 + 0x78 * i, rng.choice([0, 0x2000, 0x80000]))
    out = m.alloc(0x20)
    return [S, info, out]


CASES += [
    Case('ATIR500Surface::get_surf_desc_regs', w_surf_desc, ret='void', name='ATIR500Surface::get_surf_desc_regs modes H3', seeds=400, plain_words=True),
]


def w_load_3d_blit(m, rng):
    S, A = surf(m, rng)
    dest = m.alloc(0x300)
    buf = m.alloc(0x80); fill_words(m, buf, 0x80, rng)
    m.w32(buf + 0x3c, (rng.choice([0, 1, 2, 3, 4, 6, 8, 15]) << 20) | rng.choice([0, 0x800, 0x3000]) | (rng.randrange(4) << 24))
    for off in (0x38, 0x39, 0x3a):
        m.w8(buf + off, rng.choice([0, 1, 2, 3, 6, 0x10, 0x30, 0xff]))
    m.w32(buf + 0x08, rng.choice([0, 0x1000, 0x3000000]))
    m.w16(buf + 0x14, rng.choice([0, 1, 64, 640, 1000])); m.w16(buf + 0x16, rng.choice([1, 2, 4, 8, 16]))
    m.w16(buf + 0x1c, rng.choice([0, 64, 640, 1023])); m.w16(buf + 0x1e, rng.choice([1, 48, 480]))
    m.w32(A + 0xb74, word(rng))
    m.w32(A + 0xb98, rng.choice([1, 2, 4, 6, 8, 12, 0]))                                         # number of pipes
    return [S, dest, buf]


CASES += [
    Case('ATIR500Surface::load_3d_blit', w_load_3d_blit, ret='u32', name='ATIR500Surface::load_3d_blit formats H3', seeds=300, plain_words=True, ignore_args=REL),
]


def w_atir500_stop(m, rng):
    S, A = surf(m, rng)
    for i in range(23):
        m.w8(S + 0xa8 + 0x78 * i + 0x37, rng.choice([0xff, 0xff, 0xff, 3, 0]))
    m.w8(A + 0x80, rng.choice([0, 1, 1]))
    panel = rng.choice([0, 1, 0xffff]); m.w32(S + 0xc14, panel)
    for p in range(2):
        m.w32(A + 0xe8 + 0x20 * p, rng.choice([S, S, 0]))
    pk = m.alloc(0x200); fill_words(m, pk, 0x200, rng)
    m.w32(A + 0x238, pk); m.w32(A + 0x234, word(rng)); m.w32(A + 0x228, rng.choice([0, 0x1000]))
    for p in range(2):
        m.w32(A + 0x134 + 0x78 * p, word(rng))
    m.w32(S + 0xdb8, rng.choice([0, 1]))
    m.w32(S + 0xb74, rng.choice([S + 0x120, S + 0xa8]))
    m.w8(S + 0xbf0, rng.choice([0, 1]))
    m.w32(A + 0x8b8, rng.choice([0, 1])); m.w32(A + 0x8b0, plain(m, rng, 0x100, 0x800))
    return [S, A]


def stop_mock(m, name, k):
    if 'submit_buffer' in name:
        return m.seed + k
    return surf_mock(m, name, k)


CASES += [
    Case('ATIR500Surface::stop', w_atir500_stop, ret='void', name='ATIR500Surface::stop teardown H3', seeds=250, mock=stop_mock, plain_words=True, ignore_args=REL),
]
