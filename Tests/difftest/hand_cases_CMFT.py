"""Hand-written worlds for clientMemoryForType in the three contexts (2D, DVD, GL): the generic soup world reaches 6-15% of them.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_CMFT.py   (needs STOCK_KEXT)

Each world builds the objects the function walks (accelerator with its command-buffer ring, a bound surface with its allocation masks, the context's own
command-buffer descriptors) and the mock drives the callees that decide the paths: alloc_surfaces' status, the accelerator's wait/stamp virtuals, the
descriptor the removeTransferFromGART-slot call fills in."""
import os, sys, struct, zlib
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from common import word, object_with_vtable, accelerator_with_registers
from hand_cases_D import (new_mock, REL, clean_word, clean_fill, obj, plain, accel, ctx2d, dvd, bound_surface, slot_signatures)
from unicorn.ppc_const import UC_PPC_REG_3, UC_PPC_REG_4, UC_PPC_REG_5


REL2 = {'vtable slot +0x14': [1, 2], 'vtable slot +0x12c': [2], 'vtable slot +0x18': [1, 2]}      # retain()/release() on an object of an unnamed class: the extra argument registers hold leftovers


def clean_word_k(m, k, salt):
    return [0, 1, 0x20, 0x100, 0x7ff][pick(m, k, 5, salt)]


def plain_k(m):
    o = m.alloc(0x400)
    m.w32(o, m.vtable('IOATIR500Shared', 0x800))
    return o


def pick(m, k, n, salt=0):
    return zlib.crc32(b'%d/%d/%d' % (m.seed, k, salt)) % n


def cmft_mock(m, name, k):
    """status of alloc_surfaces, the lock-sleep that finally sees the hardware alive, the accelerator's wait/stamp virtuals"""
    if 'alloc_surfaces' in name:
        return [0, 0, 2, 1, 0xe00002bc][pick(m, k, 5)]
    if 'sleep_blocked' in name:                                                      # the surface stops being blocked while the caller sleeps
        a = m.uc.reg_read(UC_PPC_REG_3)
        if a > 0x1000 and pick(m, k, 3):
            m.w8(a + 0xbf6, 0)
        return 0
    if 'IOLockSleep' in name:
        a = m.uc.reg_read(UC_PPC_REG_4)
        if a > 0x1000:
            m.w8(a + 0x80, 1)
        return 0
    if name.endswith('vtable slot +0x554') or 'vtable slot +0x554' in name:        # accelerator: is this stamp complete?
        return pick(m, k, 2)
    if name.endswith('+0x558') or name.endswith('+0x560') or name.endswith('+0x54c'):   # wait for stamp / stamp from descriptor / wait: small counts
        return [0, 1, 2, 5, 0x40][pick(m, k, 5)]
    if 'allocCommandBuffer' in name:                                                # fills the 7-word VendorCommandBuffer (r4) when it succeeds
        p = m.uc.reg_read(UC_PPC_REG_4)
        if p > 0x1000 and pick(m, k, 3):
            m.uc.mem_write(p, struct.pack('>7I', m.alloc(0x400), clean_word_k(m, k, 1), plain_k(m), 0x10000, clean_word_k(m, k, 2), m.alloc(0x100), 0x1000))
            return 1
        return 0
    if 'allocMoreCommandBuffers' in name:
        return pick(m, k, 2)
    if name.endswith('+0x5ac') or 'removeTransferFromGART' in name:                # fills the 16-byte descriptor (r4); word 2 is read
        p = m.uc.reg_read(UC_PPC_REG_4)
        if p > 0x1000:
            m.uc.mem_write(p, struct.pack('>4I', 0, 0, [0, 0, 3, 0x20][pick(m, k, 4, 1)], 0))
        return pick(m, k, 2)
    return new_mock(m, name, k)


def surface_for_2d(m, rng):
    S = obj(m, rng, 'ATIR500Surface', 0x1000)
    m.w32(S + 0xa4, rng.choice([0, 0x10, 0xff, 0x100, 0x1000]))
    m.w8(S + 0xbf6, rng.choice([0, 0, 0, 1]))
    m.w32(S + 0xbfc, clean_word(rng))
    m.w32(S + 0xbec, rng.choice([0, 0x1000000, 0x10, 0x7fffff]))
    m.w8(S + 0xbd0, rng.choice([0, 1, 1]))
    m.w32(S + 0xbf8, rng.choice([0, 0x20000000, 0x10000000, 0x30000000, 0x7fffff, 0x1, 0x3, 0x10000001]))
    m.w32(S + 0xc1c, rng.choice([0, 1, 0x10000000, 0x7fffff, 0x20000000]))
    m.w32(S + 0x7c, clean_word(rng)); m.w32(S + 0x80, clean_word(rng)); m.w32(S + 0x84, clean_word(rng))
    rec = obj(m, rng, 'ATIR500Surface', 0x100)
    tgt = m.alloc(0x100); clean_fill(m, tgt, 0x100, rng)
    m.w32(rec + 0x24, tgt)
    m.w32(S + 0xb70, rec)
    for i in range(2):
        m.w8(S + 0xcac + 0x94 * i, rng.choice([0, 1]))
    return S


def link_surface(m, rng, S, A):
    """the accelerator's surface list (head +0x5c) is doubly linked through +0x9c / +0xa0"""
    head = obj(m, rng, 'ATIR500Surface', 0x1000)
    nxt = obj(m, rng, 'ATIR500Surface', 0x1000)
    m.w32(head + 0x9c, nxt); m.w32(head + 0xa0, nxt); m.w32(nxt + 0x9c, head); m.w32(nxt + 0xa0, head)
    others = [head, S] if rng.random() < 0.5 else [head, head]
    m.w32(A + 0x5c, others[0])
    m.w32(S + 0x9c, nxt); m.w32(S + 0xa0, nxt)


def ring(m, rng, A):
    cnt = rng.choice([1, 2, 4, 8, 8])
    m.w16(A + 0x5c6, cnt); m.w16(A + 0x5c4, rng.randrange(cnt))
    for i in range(8):
        s = A + 0x404 + 0x1c * i
        m.w32(s, m.alloc(0x400)); m.w32(s + 4, clean_word(rng)); m.w32(s + 8, plain(m, rng)); m.w32(s + 0xc, clean_word(rng))
        m.w32(s + 0x10, clean_word(rng)); m.w32(s + 0x14, m.alloc(0x100)); m.w32(s + 0x18, rng.choice([0x1000, 0x2000]))


def w_2d(m, rng):
    c, A = ctx2d(m, rng, 'ATIR5002DContext')
    m.w8(A + 0x80, rng.choice([1, 1, 1, 0]))
    m.w32(A + 0xcc, rng.choice([0, 1, 2]))
    m.w32(A + 0xac, rng.choice([0, plain(m, rng)]))
    m.w32(A + 0xc0, plain(m, rng)); m.w8(A + 0x88, rng.choice([0, 1])); m.w32(A + 0x8c, clean_word(rng))
    m.w32(A + 0x78, rng.choice([0, c, c, plain(m, rng)]))
    m.w32(A + 0x744, clean_word(rng)); m.w32(A + 0x74c, clean_word(rng)); m.w32(A + 0x50, rng.choice([0, 5, 0x100]))
    m.w32(A + 0x700, clean_word(rng)); m.w32(A + 0x76c, clean_word(rng)); m.w32(A + 0x794, clean_word(rng))
    for i in range(2):
        m.w32(A + 0xec + 0x20 * i, 0)
    ring(m, rng, A)
    S = 0
    if rng.random() < 0.85:
        S = surface_for_2d(m, rng)
        link_surface(m, rng, S, A)
    m.w32(c + 0x100, S)
    m.w32(c + 0x8c, rng.choice([0, 1, 0x10000000, 0x7fffff, 0x20000000]))
    m.w32(c + 0x110, rng.choice([0, 1, 0xffff, 0xffff]))
    m.w32(c + 0xa0, plain(m, rng)); m.w32(c + 0xbc, plain(m, rng))
    m.w32(c + 0xac, m.alloc(0x100)); m.w32(c + 0xc8, m.alloc(0x100)); m.w32(c + 0x9c, rng.choice([0, 0x1000]))
    t = 0
    if rng.random() < 0.5:
        t = m.alloc(0x100); clean_fill(m, t, 0x100, rng)
        hdr = m.alloc(0x40); clean_fill(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
    m.w32(c + 0x114, t)
    m.w8(c + 0x92, rng.choice([0, 1]))
    out_opt, out_mem = m.alloc(0x10), m.alloc(0x10)
    return [c, rng.choice([0, 0, 0, 0, 0, 1, 2, 3]), out_opt, out_mem]


def ring_at(m, rng, A, base, idx_off, cnt_choices=(1, 2, 4, 8, 16)):
    cnt = rng.choice(cnt_choices)
    m.w16(A + idx_off + 2, cnt); m.w16(A + idx_off, rng.randrange(cnt))
    for i in range(16):
        s = A + base + 0x1c * i
        m.w32(s, m.alloc(0x400)); m.w32(s + 4, clean_word(rng)); m.w32(s + 8, plain(m, rng)); m.w32(s + 0xc, clean_word(rng))
        m.w32(s + 0x10, clean_word(rng)); m.w32(s + 0x14, m.alloc(0x100)); m.w32(s + 0x18, rng.choice([0x1000, 0x2000]))


def w_dvd_cmft(m, rng):
    c, A = dvd(m, rng)
    m.w8(A + 0x80, rng.choice([1, 1, 1, 0]))
    m.w32(A + 0xcc, rng.choice([0, 1, 2]))
    m.w32(A + 0xac, rng.choice([0, plain(m, rng)])); m.w32(A + 0xb0, rng.choice([0, plain(m, rng)]))
    m.w32(A + 0x78, rng.choice([0, c, c, plain(m, rng)]))
    m.w32(A + 0x748, clean_word(rng)); m.w32(A + 0x74c, clean_word(rng)); m.w32(A + 0x50, rng.choice([0, 5, 0x100]))
    m.w32(A + 0x708, clean_word(rng)); m.w32(A + 0x774, clean_word(rng)); m.w32(A + 0x79c, clean_word(rng))
    ring_at(m, rng, A, 0x240, 0x400)
    m.w32(A + 0x5c8, rng.choice([0x1000, 0x2000, 0x80000]))
    m.w32(A + 4 * 0x172, rng.choice([0, 0x1000, 0x80000, 0x100000]))
    S = 0
    if rng.random() < 0.9:
        S = surface_for_2d(m, rng)
        link_surface(m, rng, S, A)
    m.w32(c + 0xf8, S)
    m.w32(c + 0x88, rng.choice([0, 1, 0x10000000, 0x7fffff, 0x20000000]))
    m.w32(c + 0x98, plain(m, rng)); m.w32(c + 0xb4, plain(m, rng))
    m.w32(c + 0xa4, m.alloc(0x100)); m.w32(c + 0xc0, m.alloc(0x100)); m.w32(c + 0x94, rng.choice([0, 0x1000]))
    m.w32(c + 0xa8, rng.choice([0x1000, 0x2000, 0x80000]))
    for i in range(17):
        m.w32(c + 0x104 + 4 * i, rng.choice([0, 0, m.alloc(0x100)]))
    return [c, rng.choice([1, 1, 1, 1, 1, 0, 2, 3, 4]), m.alloc(0x10), m.alloc(0x10)]


def surface_for_gl(m, rng):
    S = surface_for_2d(m, rng)
    m.w32(S + 0xbe8, rng.choice([0, 0x20, 0x20, 0x1]))
    m.w32(S + 0xcc, rng.choice([0, 1])); m.w32(S + 0x144, rng.choice([0, 1]))
    m.w32(S + 0xc14, rng.choice([0, 1, 2, 5]))
    m.w32(S + 0xb74, clean_word(rng)); m.w32(S + 0xb70, clean_word(rng)); m.w32(S + 0xb80, clean_word(rng)); m.w32(S + 0xb84, clean_word(rng))
    m.w32(S + 0xbf8, rng.choice([0, 0x20000000, 0x10000000, 0x30000000, 0x7fffff, 0x1, 0x3, 0x23, 0x10000001]))
    return S


def data_buffer_list(m, rng, c):
    """singly linked through +0x3c; head/tail at self+0xe8/+0xec (head == tail means empty)"""
    n = rng.choice([0, 0, 1, 2, 3])
    nodes = [m.alloc(0x80) for _ in range(n + 1)]
    for a, b in zip(nodes, nodes[1:]):
        m.w32(a + 0x3c, b)
    m.w32(c + 0xe8, nodes[0]); m.w32(c + 0xec, nodes[-1])


def w_gl_cmft(m, rng):
    c = obj(m, rng, 'ATIR500GLContext', 0x400)
    A = accel(m, rng)
    m.w32(c + 0xc8, A)
    m.w8(A + 0x80, rng.choice([1, 1, 1, 0]))
    m.w32(A + 0xcc, rng.choice([0, 1, 2]))
    m.w32(A + 0xac, rng.choice([0, plain(m, rng)])); m.w32(A + 0xb0, rng.choice([0, plain(m, rng)]))
    m.w32(A + 0x78, rng.choice([0, c, c, plain(m, rng)]))
    for off in (0x740, 0x74c, 0x704, 0x770, 0x798, 0x5d4):
        m.w32(A + off, clean_word(rng))
    m.w32(A + 0x50, rng.choice([0, 5, 0x100])); m.w32(A + 0xd0, rng.choice([0, 0xffffffff, 0x3, 0x10]))
    m.w32(A + 0x5cc, rng.choice([0, plain(m, rng)])); m.w32(A + 0x5d0, rng.choice([0, plain(m, rng)]))
    m.w32(A + 0xc0, plain(m, rng)); m.w8(A + 0x88, rng.choice([0, 1])); m.w32(A + 0x8c, clean_word(rng))
    m.w32(A + 0x5c8, rng.choice([0x1000, 0x2000, 0x8000]))
    ring_at(m, rng, A, 0x240, 0x400)
    m.w32(A + 4 * 0x172, rng.choice([0, 0x1000, 0x80000, 0x100000]))
    S = 0
    if rng.random() < 0.9:
        S = surface_for_gl(m, rng)
        link_surface(m, rng, S, A)
    m.w32(c + 0x290, S)
    m.w32(c + 0x8c, rng.choice([0, 1, 0x10000000, 0x7fffff, 0x20000000]))
    m.w16(c + 0x98, rng.choice([0, 1])); m.w16(c + 0x9a, rng.choice([0, 1]))
    m.w32(c + 0xa8, rng.randrange(3))
    m.w32(c + 0xb0, rng.choice([0x1000, 0x10000, 0x80000, 0x40000]))
    m.w32(c + 0xd4, plain(m, rng)); m.w32(c + 0xfc, plain(m, rng)); m.w32(c + 0xd0, rng.choice([0, 0x1000]))
    hdr = m.alloc(0x100); clean_fill(m, hdr, 0x100, rng); m.w32(hdr + 0x10, rng.choice([0x100, 0x400, 0x1000]))
    m.w32(c + 0xe0, hdr); m.w32(c + 0x108, m.alloc(0x100))
    m.w32(c + 0xe4, rng.choice([0x1000, 0x2000, 0x8000]))
    data_buffer_list(m, rng, c)
    for i in range(42):
        m.w32(c + 0x2a4 + 4 * i, rng.choice([0, 0, m.alloc(0x100)]))
    m.w32(c + 0xb8, rng.choice([0, plain(m, rng)])); m.w32(c + 0xbc, rng.choice([0x1000, 0x2000])); m.w32(c + 0xc0, m.alloc(0x2000))
    return [c, rng.choice([1, 1, 1, 1, 1, 0, 2, 3, 4, 4, 5]), m.alloc(0x10), m.alloc(0x10)]


CASES = [
    Case('IOATIR5002DContext::clientMemoryForType', w_2d, ret='u32', seeds=200, mock=cmft_mock, ignore_args=REL2, limit=200000, plain_words=True, name='clientMemoryForType (2D hand world)'),
    Case('IOATIR500DVDContext::clientMemoryForType', w_dvd_cmft, ret='u32', seeds=200, mock=cmft_mock, ignore_args=REL2, limit=200000, plain_words=True, name='clientMemoryForType (DVD hand world)'),
    Case('IOATIR500GLContext::clientMemoryForType', w_gl_cmft, ret='u32', seeds=200, mock=cmft_mock, ignore_args=REL2, limit=200000, plain_words=True, name='clientMemoryForType (GL hand world)'),
]
