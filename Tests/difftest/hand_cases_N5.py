"""Hand worlds for the GL context functions whose locals were named by the relaxed-gate naming push (N5): ATIR500GLContext::load_texture.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_N5.py   (needs STOCK_KEXT; see Tools/difftest/README.md)

load_texture(texture) walks the faces and mip levels of a texture whose dirty bits (header +0x1c) are not yet in the loaded bits (+0x28), maps the texture's
memory descriptor to get the hardware info block (hwInfo), and builds a PM4 packet in hwInfo's record array in one of two layouts: the linear one (hwInfo[8]
negative: one 0x80000000 / 0xc0101000 record per slice and an address packet from the bound colour buffer) or the tiled one (a 0x1d-word packet per slice).
The world builds real objects for everything the function reaches: header, hwInfo with level records, list nodes, the colour buffer."""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from common import word, fill_words
from hand_cases_D import obj, plain, accel, bound_surface, clean_word, new_mock, REL

HW_SIZE = 0x8000          # hwInfo block: 0x40 header bytes, 78 level records of 0x20 bytes from +0x40, the record array from +0xa00


def mock(m, name, k):
    if name.endswith('vtable slot +0xd0'):              # IOMemoryMap::getVirtualAddress(): the test's hwInfo block
        return m.n5_hwinfo
    return new_mock(m, name, k)


def list_node(m, rng):
    n = m.alloc(0x80); fill_words(m, n, 0x80, rng)
    m.w32(n + 0x34, n); m.w32(n + 0x38, n)
    return n


def w_load_texture(m, rng):
    c = obj(m, rng, 'ATIR500GLContext', 0x800)
    A = accel(m, rng, mmio=False)
    m.w32(c + 0xc8, A)
    m.w32(A + 0x6d0, list_node(m, rng))
    for off in (0x82c, 0x8a4, 0xb74, 0x704, 0x71c, 0x754):
        m.w32(A + off, clean_word(rng))
    m.w32(c + 0x29c, rng.randrange(4)); m.w32(c + 0x298, rng.randrange(4))
    # colour buffer: through the bound surface, or the context's own attachment records when rendering to a texture
    r2t = rng.choice([0, 0, 1])
    m.w32(c + 0x3bc, r2t)
    S = bound_surface(m, rng, c)
    m.w32(c + 0x290, S)
    m.w16(c + 0xac, rng.randrange(23)); m.w16(c + 0x3b2, rng.randrange(6))
    for i in range(6):
        r = c + 0x3c0 + 0x78 * i
        m.w16(r + 0x16, rng.choice([1, 2, 4, 8])); m.w16(r + 0x14, rng.choice([64, 128, 640])); m.w16(r + 0x20, rng.choice([1, 2, 4]))
    for i in range(23):
        r = S + 0xa8 + 0x78 * i
        m.w16(r + 0x14, rng.choice([64, 128, 640])); m.w16(r + 0x20, rng.choice([1, 2, 4]))
        m.w8(r + 0x38, rng.choice([0, 1, 2, 3])); m.w8(r + 0x39, rng.choice([0, 1, 2, 3]))
        m.w32(r + 0x3c, rng.choice([0, 0x100000, 0x200000, 0x400000]))
        for k in range(8):
            m.w32(r + 0x40 + 4 * k, clean_word(rng) & 0xffff)
    # the texture
    faces, first, levels = rng.randrange(1, 4), rng.randrange(3), rng.randrange(1, 5)
    H = m.alloc(0x80); fill_words(m, H, 0x80, rng)
    m.w8(H + 0x34, faces); m.w8(H + 0x17, first); m.w8(H + 0x35, levels)
    m.w8(H + 0x15, rng.randrange(256)); m.w8(H + 0x14, rng.choice([0, 1]))
    m.w32(H + 0xc, clean_word(rng))
    m.w32(H + 0x10, clean_word(rng))
    for f in range(6):
        m.w16(H + 0x1c + 2 * f, rng.choice([0, 0xffff, rng.randrange(0x10000), rng.randrange(0x10000)]))
        m.w16(H + 0x28 + 2 * f, rng.choice([0, 0, 0xffff, rng.randrange(0x10000)]))
    T = m.alloc(0x100); fill_words(m, T, 0x100, rng)
    m.w32(T + 0x14, H)
    m.w32(T + 8, plain(m, rng))
    ttype = rng.choice([3, 7, 7, 0, 5])
    m.w8(T + 0x20, ttype)
    m.w32(T + 4, rng.choice([0, clean_word(rng) | 1]))
    m.w32(T + 0x34, list_node(m, rng)); m.w32(T + 0x38, list_node(m, rng))
    m.w32(T + 0x48, clean_word(rng)); m.w32(T + 0x50, clean_word(rng)); m.w32(T + 0x64, rng.choice([0, 2, 4, 4]))
    inner = m.alloc(0x80); fill_words(m, inner, 0x80, rng)
    m.w32(inner + 4, rng.choice([0, 0, clean_word(rng) | 1]))
    m.w32(inner + 0x14, m.alloc(0x20)); m.w32(inner + 0x34, list_node(m, rng)); m.w32(inner + 0x38, list_node(m, rng))
    m.w16(inner + 0xe, rng.randrange(4))
    m.w32(T + 0x58, inner)
    # hwInfo
    HW = m.alloc(HW_SIZE)
    m.n5_hwinfo = HW
    linear = rng.choice([0, 1])
    m.w32(HW + 0, rng.randrange(0, 0x40)); m.w32(HW + 4, rng.randrange(0, 0x40)); m.w32(HW + 8, rng.randrange(0x10, 0x100))
    m.w32(HW + 0xc, rng.choice([1, 2, 8, 16, 64, 256])); m.w32(HW + 0x10, rng.choice([1, 2, 8, 16, 64, 256]))
    m.w32(HW + 0x20, 0x80000000 if linear else rng.choice([0, 1, 0x7fffffff]))
    m.w16(HW + 0x16, rng.choice([1, 2, 8, 16, 64, 256]))
    m.w8(HW + 0x1a, rng.choice([0, 0, 1, 2, 3, 4, 5]))
    m.w8(HW + 0x1b, rng.randrange(256))
    for i in range(78):
        L = HW + 0x40 + 0x20 * i
        m.w16(L + 0x0, i * 0x40); m.w16(L + 0x2, rng.choice([0, 1, 2, 3]))
        m.w32(L + 4, clean_word(rng) & 0xffffff); m.w32(L + 8, clean_word(rng) & 0xffffff)
        m.w32(L + 0xc, rng.choice([0, 0x100, 0x1000])); m.w32(L + 0x10, rng.choice([0, 0x100, 0x1000]))
        m.w16(L + 0x18, i * 0x60)
    return [c, T]


CASES = [
    Case('ATIR500GLContext::load_texture', w_load_texture, ret='void', seeds=400, mock=mock, ignore_args=REL, plain_words=True, limit=400000,
         name='load_texture (hand world)'),
]
