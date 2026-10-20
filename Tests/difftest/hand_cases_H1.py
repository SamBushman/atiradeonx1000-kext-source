"""Hand-written worlds that raise the UNION coverage of the three process_command_buffer functions (judge them with Tools/difftest/union_coverage.py on a
`--json` report: the per-opcode cases each show only their own slice).
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_H1.py   (needs STOCK_KEXT)."""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from difftest import Case
from hand_cases_C import (pcb_world_with, pcb_special, scripted_mock, PCB_TRACK_READS, KNOWN_OPCODES)

CASES = []


def big_surfaces(inner, widths=(0x1001, 0x1400, 0x2000, 0x2800), heights=(0x1001, 0x1800, 0x2000, 0x3000, 64, 1024)):
    """run the inner pcb world, then give the bound surface's buffer records (23 at surface+0xa8, stride 0x78, and the embedded ones at this+0x3c0) a width and/or
    height above 0x1000: the blit/clear packet writers then take the tiled path (several 4096x4096 chunks) instead of the single-rectangle one"""
    def world(m, rng):
        args = inner(m, rng)
        this = args[0]
        s = m.r32(this + 0x290)
        bufs = [s + 0xa8 + 0x78 * i for i in range(23)] + [this + 0x3c0 + 0x78 * i for i in range(23)]
        for b in bufs:
            if rng.random() < 0.7:
                m.w16(b + 0x1c, rng.choice(widths)); m.w16(b + 0x1e, rng.choice(heights))
        return args
    return world


for _op in (0x2d, 0x2e, 0x31, 0x32, 0x45, 0x30):
    CASES.append(Case('ATIR500GLContext::process_command_buffer', big_surfaces(pcb_world_with(lambda rng, _op=_op: _op, (1, 2), special=pcb_special)), ret='u32',
                      seeds=(40 if _op == 0x31 else 120), mock=scripted_mock, plain_words=True, stack_args=PCB_TRACK_READS, limit=2000000,
                      name='process_command_buffer (H1 big surfaces, opcode 0x%02x)' % _op))


def hi_word(rng):
    """operands with the high-bit fields the handlers decode: 2-bit mode in 31:30, format byte in 29:22, 24-bit sizes, plus the usual small indexes/counts"""
    k = rng.randrange(10)
    if k < 3: return rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0x10, 0x20])
    if k == 3: return (rng.randrange(4) << 30) | rng.getrandbits(22)
    if k == 4: return (rng.randrange(4) << 30) | (rng.randrange(0x40) << 22) | rng.choice([0, 1, 0x40, 0x100, 0x1000, rng.getrandbits(16)])
    if k == 5: return (rng.randrange(0x100) << 16) | rng.randrange(0x100)
    if k == 6: return rng.choice([0x1000, 0x2000, 0x10000, 0xffffff, 0x7fff, 0xffff, 0x80000000, 0xc0000000, 0x40000000])
    if k == 7: return (rng.randrange(0x2000) << 16) | rng.randrange(0x2000)
    return rng.getrandbits(32)


def hi_special(m, rng, op, texs):
    pk = pcb_special(m, rng, op, texs)
    if pk: return pk
    n = rng.choice([4, 6, 8, 12, 16, 24, 40])
    w = [(op << 24) | n] + [hi_word(rng) for _ in range(n - 1)]
    if len(w) > 3 and (w[3] >> 24) >= 48:        # the top byte of operand 3 is a format-table index (48 entries): past the table the two builds' data differ, which is not a defect
        w[3] = (w[3] & 0xffffff) | (rng.randrange(48) << 24)
    return w


for _op in KNOWN_OPCODES:
    CASES.append(Case('ATIR500GLContext::process_command_buffer', pcb_world_with(lambda rng, _op=_op: _op, (1, 2), special=hi_special), ret='u32', seeds=(40 if _op in (0x31, 0x38) else 150), mock=scripted_mock,
                      plain_words=True, stack_args=PCB_TRACK_READS, limit=600000, name='process_command_buffer (H1 high-bit operands, opcode 0x%02x)' % _op))


# ---- ATIR500DVDContext::process_command_buffer ---------------------------------------------------------------------------------------------------
from hand_cases_D import dvd, dvd_surface_big, obj, clean_word, new_mock, REL, word, STREAM_OPS

DVD_OPS = sorted(set(STREAM_OPS) | {0x10, 0x11, 0x00, 0x01, 0x03, 0x45, 0x40, 0x41})


def dvd_world(op, hi):
    """the DVD pcb world of hand_cases_D.w_dvd_pcb with a stream of ONE opcode: per-opcode cases so that each handler is reached with its own operands. hi=True: operands with
    the high-bit fields (modes, format index < 48, sizes) and some buffer records above 4096 in either dimension"""
    def world(m, rng):
        c, A = dvd(m, rng)
        S = dvd_surface_big(m, rng)
        if hi:
            for i in range(23):
                r = S + 0xa8 + 0x78 * i
                if rng.random() < 0.5:
                    m.w16(r + 0x1c, rng.choice([0x1001, 0x1800, 0x2000, 64, 640])); m.w16(r + 0x1e, rng.choice([0x1001, 0x1800, 0x2000, 64, 480]))
                m.w8(r + 0x3a, rng.randrange(48))
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
        if hi:
            a = buf + 0x1c
            for _ in range(rng.choice([1, 2, 3])):
                n = rng.choice([4, 6, 8, 12, 16, 24])
                m.w32(a, (op << 24) | n)
                for j in range(1, n): m.w32(a + 4 * j, hi_word(rng))
                a += 4 * n
            m.w32(a, 0)
        else:
            stream(m, rng, buf + 0x1c, rng.choice([1, 2, 3]), ops=[op])
        m.w32(c + 0xa4, buf); m.w32(c + 0x94, rng.choice([0, 0x10, 0x100]))
        m.w32(c + 0x154, word(rng)); m.w32(c + 0x158, word(rng)); m.w32(c + 0x15c, word(rng))
        return [c, m.alloc(0x40)]
    return world


from hand_cases_D import stream, fill_words
for _op in DVD_OPS:
    for _hi in (False, True):
        CASES.append(Case('ATIR500DVDContext::process_command_buffer', dvd_world(_op, _hi), ret='u32', seeds=(60 if _hi else 80), mock=new_mock, ignore_args=REL, limit=300000,
                          plain_words=True, name='process_command_buffer (H1 DVD %s, opcode 0x%02x)' % ('high-bit operands' if _hi else 'stream', _op)))
