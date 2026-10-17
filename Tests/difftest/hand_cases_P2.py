"""Hand worlds for the functions whose panel-record loops were rewritten with named PanelRecord/SwapBufferEntry access (the generic worlds reach too little
of the panel code). Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_P2.py"""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from common import surface_world, word, fill_words
from hand_cases_D import surf, swap_header, clean_word, sane_record, obj, plain, new_mock, REL


def w_flush_surface(m, rng):
    """flush_surface(panelMask, swapArg): the loop walks the accelerator's panels (count at accelerator+0xcc), submitting those whose bit is set in the mask
    and whose record is active (+0x8c of the 0x94-byte record at +0xc20)"""
    SELF, ACCEL = surface_world(m, rng, 'IOATIR500Surface')
    m.w8(SELF + 0xbed, rng.choice([0, 1]))
    m.w32(SELF + 0xbf8, rng.choice([0, 0x10000000, 0x307fffff]))
    m.w32(SELF + 0xc1c, rng.choice([0, 0x10000000, 0x20000000]))
    for p in range(2):
        m.w8(SELF + 0xc20 + p * 0x94 + 0x8c, rng.choice([0, 1, 1]))
    return [SELF, rng.choice([0, 1, 2, 3, 0xffffffff]), word(rng)]


def w_submit_flip(m, rng):
    """submit_flip_buffer(panel, IOATIR500GLContext *, flag): the panel record's pending batch and submit slots as for submit_swap_buffer; the context selects one
    of the surface's attachment records (index at +0xac, table at surface+0xb70) and holds the vsync flag at +0x98"""
    S, A = surf(m, rng)
    panel = rng.choice([0, 1])
    ctx = rng.choice([0, obj(m, rng, 'IOATIR500GLContext', 0x200)])
    if ctx:
        m.w16(ctx + 0x98, rng.choice([0, 1, 2])); m.w16(ctx + 0xac, rng.randrange(6))
    flag = rng.choice([0, 1])
    m.w32(S + 0xd54, rng.choice([0, ctx, ctx]))
    m.w16(S + 0xdb4, rng.choice([0, 1]))
    m.w8(S + 0xdb6, rng.choice([0, 1]))
    for i in range(6):
        r = S + 0xa8 + 0x78 * i
        sane_record(m, rng, r); m.w32(S + 0xb70 + 4 * i, r)
    base = S + 0x94 * panel
    m.w8(base + 0xcad, rng.choice([0, 1, 2]))
    m.w32(base + 0xc34, swap_header(m, rng, rng.choice([0, 2, 6, 12])))
    m.w16(base + 0xcae, rng.randrange(4)); m.w32(base + 0xcb0, 0x10000)
    for e in range(4):
        r = base + 0xc3c + 0x1c * e
        m.w32(r + 8, rng.choice([0, plain(m, rng)]))
        m.w32(r + 4, rng.choice([0, 0x2000000]))
        m.w32(r + 0x14, swap_header(m, rng, rng.choice([0, 4, 8])))
    m.w32(A + 0xb70, 0); m.w32(A + 0xb78, clean_word(rng)); m.w32(A + 0xb7c, clean_word(rng)); m.w32(A + 0xb80, clean_word(rng)); m.w32(A + 0xb84, clean_word(rng))
    m.w32(A + 0xb88, clean_word(rng)); m.w32(A + 0xb8c, clean_word(rng))
    m.w8(A + 0x9b0, rng.choice([0, 1, 1])); m.w32(A + 0x894, rng.choice([0, 1]))
    m.w32(A + 0x710, clean_word(rng))
    return [S, panel, ctx, flag]


def w_dealloc_surface(m, rng):
    """ATIR500Surface::dealloc_surface(id): ids 6..8 take the depth-buffer path (a buffer record at +0xa8+id*0x78 with its +8 field set, accelerator flag at
    +0xb94), which flushes through the panel-0 submit slot"""
    S, A = surf(m, rng)
    ident = rng.choice([6, 7, 8, 3, 9])
    m.w32(S + 0xb0 + 0x78 * ident, rng.choice([0, 0, 0x1000]))
    m.w32(A + 0x2e5 * 4, rng.choice([0, 1, 1]))
    m.w32(A + 0x7c8, rng.choice([0, 1]))
    base = S
    m.w16(base + 0xcae, rng.randrange(4)); m.w32(base + 0xcb0, 0x10000)
    m.w32(base + 0xc34, swap_header(m, rng, rng.choice([0, 2, 6])))
    for e in range(4):
        r = base + 0xc3c + 0x1c * e
        m.w32(r + 8, rng.choice([0, plain(m, rng)]))
        m.w32(r + 4, rng.choice([0, 0x2000000]))
        m.w32(r + 0x14, swap_header(m, rng, rng.choice([0, 4, 8])))
    m.w32(S + 0xd0 + 0x78 * ident, rng.choice([0x3ff, 0x1234567, 0x10000000 | 0x3ff]))
    return [S, ident]


CASES = [
    Case('ATIR500Surface::dealloc_surface', w_dealloc_surface, ret='void', seeds=80, mock=new_mock, plain_words=True, ignore_args=REL),
    Case('ATIR500Surface::submit_flip_buffer', w_submit_flip, ret='void', seeds=120, mock=new_mock, plain_words=True, ignore_args=REL),
    Case('IOATIR500Surface::flush_surface', w_flush_surface, ret='void', seeds=40),
]
