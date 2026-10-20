"""Hand-written world for ATIR5002DContext::process_command_buffer (the generic pointer-soup case reaches ~10% of it).
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_N4.py   (needs STOCK_KEXT; see Tools/difftest/README.md)

The 2D interpreter walks a stream of records [opcode << 24 | length-in-words][arguments] at commandBufferHeader + 0x1c. Opcodes 0x03/0x04/0x07/0x08/0x10/0x13
bind a texture from the shared allocator's table (record word 1 = slot), 0x09..0x0e and 0x11/0x12 read a buffer record of the accelerator (+0x12c, 0x78 bytes each)
or of the bound surface (+0xb70 attachment table, +0xa8 records), and 0x0b/0x0c look a surface up by id through the accelerator. So the world gives every pointer a real
object, keeps every table index in range, and makes find_surface_for_id return the bound surface (or nothing)."""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from difftest import Case
from hand_cases_D import ctx2d, obj, plain, new_mock as base_mock, REL, clean_word, fill_words, bound_surface

OPS_2D = [0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x10, 0x11, 0x12, 0x13, 0x14, 0x03, 0x04, 0x07, 0x08, 0x10, 0x13, 0x0b, 0x0c]


def small_stream(m, rng, base, ncmds, ops):
    """like hand_cases_D.stream, but every argument is a small index or size: the 2D interpreter multiplies record words by 0x78 to reach buffer records and a
    large word would walk out of the objects (into the register window, where the order of independent loads is compared)"""
    a = base
    for _ in range(ncmds):
        n = rng.randrange(8, 14)
        m.w32(a, (rng.choice(ops) << 24) | n)
        for j in range(1, n):
            m.w32(a + 4 * j, rng.choice([0, 1, 2, 3, 4, 5, 8, 16, 17]) if rng.random() < 0.5 else rng.randrange(0, 18))
        a += 4 * n
    m.w32(a, 0)
    return a + 4


def pcb_mock(m, name, k):
    if 'find_surface_for_id' in name:
        return getattr(m, 'pcb_surface', 0) if (m.seed + k) % 4 != 3 else 0
    return base_mock(m, name, k)


def texture(m, rng):
    """a texture buffer as the interpreter touches it: +4 gart address, +0x14 header (its +0x14 byte is the not-yet-loaded flag, +0x15 layout bits, +8 stamp),
    list links +0x24/+0x28 and +0x34/+0x38 (real nodes), +0x48 the VRAM address"""
    t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w8(hdr + 0x14, rng.choice([0, 1])); m.w8(hdr + 0x15, rng.randrange(256)); m.w32(t + 0x14, hdr)
    m.w32(t + 4, rng.choice([0, 0x1000, 0x10000000, 0x20000000]))
    for off in (0x24, 0x28, 0x34, 0x38):
        m.w32(t + off, obj(m, rng, 'ATIR5002DContext', 0x100))
    m.w32(t + 0x48, rng.choice([0, 0x100, 0x12345000]))
    m.w32(t + 0x50, rng.choice([0, 0x100]))
    return t


def w_2d_pcb(m, rng):
    c, A = ctx2d(m, rng, 'ATIR5002DContext')
    S = bound_surface(m, rng, c)
    m.pcb_surface = S
    for off in (0x94, 0x96, 0x98, 0x9a):
        m.w16(S + off, rng.choice([1, 2, 16, 64, 480]))
    m.w8(S + 0xbf6, rng.choice([0, 0, 0, 1]))
    m.w32(S + 0xc18, rng.choice([0, 3, 0x7fffff, clean_word(rng) & 0x7fffff]))
    m.w32(S + 0xbf8, rng.choice([0, 0x20000000, 0x7fffff, 3, clean_word(rng) & 0x7fffff]))
    m.w32(c + 0x100, rng.choice([S, S, 0]))                       # boundSurface
    m.w32(c + 0x110, rng.choice([0, 1]))                          # panelIndex
    m.w32(A + 0xcc, rng.choice([1, 2, 3]))                        # accelerator buffer count
    m.w32(A + 0x50, rng.choice([1, 2, 3]))
    m.w32(A + 0x600, obj(m, rng, 'ATIR5002DContext', 0x100))
    m.w32(A + 0x6d0, obj(m, rng, 'ATIR5002DContext', 0x100))
    m.w32(A + 0x700, clean_word(rng))
    m.w32(A + 0x8a4, clean_word(rng) & 0xfffff000)
    for i in range(18):                                           # the accelerator's own buffer array (0x78-byte records from +0x12c)
        r = A + 0x12c + 0x78 * i
        for off in (0x14, 0x16, 0x18, 0x1c, 0x1e):
            m.w16(r + off, rng.choice([1, 2, 16, 64, 640]))
    shared = obj(m, rng, 'IOATIR500Shared', 0x100)
    tab = m.alloc(0x100)
    for i in range(18):
        m.w32(tab + 4 * i, 0 if rng.random() < 0.2 else texture(m, rng))
    m.w32(shared + 0x10, tab); m.w32(shared + 0x14, rng.choice([18, 18, 18, 4]))
    m.w32(c + 0x88, shared)
    m.w32(c + 0x114, rng.choice([0, texture(m, rng)]))            # lastBoundTexture
    m.w32(c + 0x9c, rng.choice([0, 0x1000]))                      # commandBufferGartOffset: 0 -> map_transfer_to_GART
    hdr = m.alloc(0x400); fill_words(m, hdr, 0x400, rng)
    m.w32(c + 0xc8, hdr)                                          # contextBufferHeader (flag word at +0x1c is OR-ed)
    buf = m.alloc(0x2000)
    small_stream(m, rng, buf + 0x1c, rng.choice([1, 2, 3, 4, 6]), OPS_2D)
    m.w32(c + 0xac, buf)
    return [c, m.alloc(0x40)]


CASES = [
    Case('ATIR5002DContext::process_command_buffer', w_2d_pcb, ret='u32', seeds=400, mock=pcb_mock, ignore_args=REL, limit=400000, plain_words=True,
         name='ATIR5002DContext::process_command_buffer (hand world)'),
]
