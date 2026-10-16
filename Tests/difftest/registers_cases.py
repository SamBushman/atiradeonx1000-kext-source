"""Differential cases for code that reads and writes the GPU's registers (ATIR5002DContext::read_regs / write_regs / write_2_regs): the register
window is a hardware window, so the reads and writes - offset, width, bytes, order - must be exactly those of the stock function."""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from common import fill_words, word, accelerator_with_registers


def context(m, rng):
    SELF = m.alloc(0x400)
    fill_words(m, SELF, 0x400, rng)
    ACCEL = accelerator_with_registers(m, rng)
    m.w32(SELF, m.vtable('ATIR5002DContext'))
    m.w32(SELF + 0x94, ACCEL)
    return SELF


def offsets(rng, n):
    return [rng.choice([0xf8, 0xe40, 0x15f4, 0x770, 0x1ffc, 0x2000, 0x1234, rng.getrandbits(14) & ~3]) for _ in range(n)]


def w_read_regs(m, rng):
    SELF = context(m, rng)
    n = rng.choice([0, 1, 2, 5])
    offs = m.alloc(0x100); outv = m.alloc(0x100); actual = m.alloc(0x10)
    for i, o in enumerate(offsets(rng, n)):
        m.w32(offs + 4 * i, o)
    cnt = rng.choice([4 * n, 4 * n, 4 * n + 4, 4 * n + 1])
    m.w32(actual, 4 * n)
    return [SELF, offs, outv, cnt, actual]


def w_write_regs(m, rng):
    SELF = context(m, rng)
    n = rng.choice([0, 1, 2, 4])
    buf = m.alloc(0x100)
    for i, o in enumerate(offsets(rng, n)):
        m.w32(buf + 8 * i, o); m.w32(buf + 8 * i + 4, word(rng))
    return [SELF, buf, rng.choice([8 * n, 8 * n, 8 * n + 4])]


def w_write_2_regs(m, rng):
    SELF = context(m, rng)
    n = rng.choice([0, 1, 2, 3])
    buf = m.alloc(0x100)
    for i in range(2 * n):
        m.w32(buf + 4 * i, word(rng))
    a, b = offsets(rng, 2)
    return [SELF, a, b, buf, rng.choice([8 * n, 8 * n, 8 * n + 4])]


CASES = [
    Case('ATIR5002DContext::read_regs', w_read_regs, ret='u32', seeds=24),
    Case('ATIR5002DContext::write_regs', w_write_regs, ret='u32', seeds=24),
    Case('ATIR5002DContext::write_2_regs', w_write_2_regs, ret='u32', seeds=24),
]
