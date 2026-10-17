"""Hand-written worlds for the IOATIR500Surface panel-record code (converted from raw offsets to PanelRecord/SwapBufferEntry access): allocMasterSwapBuffer,
freeAllSwapBuffers, freeToAllocGART (allocAllSlaveSwapBuffers has its case in hand_cases_D.py).
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_P1.py   (needs STOCK_KEXT).

The surface holds two 0x94-byte panel records at +0xc20, each five 0x1c-byte entries (master, then four submit slots) plus state. The shipped code walks the
four submit slots from entries[u + 1] for the u-th buffer of the panel, so with more than one buffer per panel it reaches into the next record; on the
second panel two buffers would reach the accelerator pointer at +0xd50 (the shipped code would corrupt it), so the second panel gets at most one buffer."""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from difftest import Case, default_mock
from hand_cases_D import surf, plain, new_mock, REL, clean_word, fill_words


def counts(m, rng, A):
    c0, c1 = rng.choice([0, 1, 1, 2]), rng.choice([0, 1, 1])
    m.w32(A + 0x114, c0); m.w32(A + 0x118, c1)
    m.w32(A + 0xcc, rng.choice([1, 2, 2]))
    return c0, c1


def fill_panels(m, rng, S):
    """both panel records: every entry gets a descriptor object (or none), a GART offset (or none), a header word, a stamp"""
    for p in range(2):
        base = S + 0xc20 + p * 0x94
        for e in range(5):
            r = base + e * 0x1c
            m.w32(r + 0x00, clean_word(rng))
            m.w32(r + 0x04, rng.choice([0, 0, 0x1000, 0x2000]))
            m.w32(r + 0x08, rng.choice([0, plain(m, rng, 0x100, 0x800)]))
            m.w16(r + 0x0c, rng.choice([0, 2, 3])); m.w16(r + 0x0e, rng.choice([0, 1]))
            m.w32(r + 0x10, clean_word(rng))
            m.w32(r + 0x14, rng.choice([0, 0x10000000]))
            m.w32(r + 0x18, clean_word(rng))
        m.w8(base + 0x8c, rng.choice([0, 1])); m.w8(base + 0x8d, rng.choice([0, 1, 2]))
        m.w16(base + 0x8e, rng.randrange(4))
        m.w32(base + 0x90, rng.choice([0, 0x1000, 0x10000]))


def w_alloc_master(m, rng):
    S, A = surf(m, rng)
    counts(m, rng, A)
    m.w32(A + 0x82c, rng.choice([0, 0x100]))
    fill_panels(m, rng, S)
    return [S, rng.choice([0, 1]), rng.choice([0x1000, 0x2000, 0x10000])]


def w_free_all(m, rng):
    S, A = surf(m, rng)
    counts(m, rng, A)
    m.w32(A + 0x788, clean_word(rng))
    fill_panels(m, rng, S)
    return [S, rng.choice([0, 1])]


def p1_mock(m, name, k):
    if 'freeTransferToAllocGART' in name:               # bool: success now and then, so the early returns are taken
        return 1 if (m.seed * 7 + k * 3) % 11 == 10 else 0
    return new_mock(m, name, k)


def w_free_to_alloc(m, rng):
    S, A = surf(m, rng)
    counts(m, rng, A)
    fill_panels(m, rng, S)
    for n in range(23):                                   # the surface-buffer array at +0xa8, stride 0x78; +0xcc of each: a transfer buffer record or none
        if rng.random() < 0.6:
            rec = m.alloc(0x40); fill_words(m, rec, 0x40, rng)
            hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng)
            m.w32(rec + 0x14, hdr)
            m.w32(S + 0xcc + n * 0x78, rec)
        else:
            m.w32(S + 0xcc + n * 0x78, 0)
    need = m.alloc(0x40); fill_words(m, need, 0x40, rng)
    return [S, need, rng.choice([0, 1])]


CASES = [
    Case('IOATIR500Surface::allocMasterSwapBuffer', w_alloc_master, ret='bool', seeds=60, mock=new_mock, ignore_args=REL),
    Case('IOATIR500Surface::freeAllSwapBuffers', w_free_all, ret='void', seeds=60, mock=new_mock, ignore_args=REL, plain_words=True),
    Case('IOATIR500Surface::freeToAllocGART', w_free_to_alloc, ret='bool', seeds=80, mock=p1_mock, ignore_args=REL, plain_words=True),
]
