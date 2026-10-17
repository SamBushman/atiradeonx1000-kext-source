"""Hand-written worlds for the ATIRadeonX1000 bring-up code (parity round of the naming work): set_display_mode_and_vram and start.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_U4P.py   (needs STOCK_KEXT; see Tools/difftest/README.md)
The generic world returns early (a pool method that fails, a framebuffer that reports nothing); here the pool methods succeed, the framebuffers report real modes,
and the register file answers with the bit patterns the mode decode tests, so the code behind those checks runs."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from common import RegisterFile
from hand_cases_D import new_mock, plain, obj, fill_words, clean_word, slot_signatures
from unicorn.ppc_const import UC_PPC_REG_3, UC_PPC_REG_4, UC_PPC_REG_5, UC_PPC_REG_7

MODES = [(640, 480), (800, 600), (1024, 768), (1280, 1024), (1920, 1080), (1920, 1200), (0, 0)]


def display_regs(rng):
    """a register file whose mode-decode registers hold plausible values: bit 0 of 0x6080 (controller enabled), the format fields of 0x6104 / 0x6904 (bits 0-1, 8-10,
    20, 21), the memory size at 0xf8, the aperture bases at 0x6110 / 0x6910, and a few flag registers; everything else answers a per-offset constant"""
    t = {0xf8: rng.choice([0, 0x4000000, 0x8000000, 0x10000000, 0x20000000]),
         0x6080: rng.choice([0, 1, 1, 1]), 0x6880: rng.choice([0, 1, 1]), 0x6088: rng.choice([0, 1]), 0x6888: rng.choice([0, 1]),
         0x6104: rng.choice([0, 1, 2, 3]) | (rng.choice([0, 1, 2]) << 8) | (rng.choice([0, 1]) << 20) | (rng.choice([0, 1]) << 21),
         0x6904: rng.choice([0, 1, 2, 3]) | (rng.choice([0, 1, 2]) << 8) | (rng.choice([0, 1]) << 20) | (rng.choice([0, 1]) << 21),
         0x16c4: rng.choice([0, 0x10, 0x30, 0x1230]), 0x6110: rng.choice([0, 0x1000, 0x2000000]), 0x6120: rng.choice([0, 0x800000, 0x3000000]),
         0x6910: rng.choice([0, 0x1000, 0x2000000]), 0x6920: rng.choice([0, 0x800000, 0x3000000]), 0x130: rng.choice([0, 0x800000])}
    def default(off):
        if off in t:
            return int.from_bytes(struct.pack('<I', t[off]), 'big')          # the registers are little-endian: lwbrx of these four bytes gives the value
        return (off * 2654435761 + 0x1234567) & 0xffffffff
    return RegisterFile(rng, default)


def display_mock(m, name, k):
    if 'ATIR500Memory' in name and ('init_pool' in name or 'reserve' in name):
        return 1                                                            # the pool methods succeed
    if name.endswith('vtable slot +0x5f0'):                                 # getCurrentDisplayMode(&a, &b): a mode id and a depth index
        a, b = m.uc.reg_read(UC_PPC_REG_4), m.uc.reg_read(UC_PPC_REG_5)
        if a > 0x1000: m.w32(a, 0x100 + (m.seed + k) % 4)
        if b > 0x1000: m.w32(b, (m.seed + k) % 3)
        return 0 if (m.seed + k) % 9 != 8 else 0xe00002bc
    if name.endswith('vtable slot +0x5ec'):                                 # getPixelInformation(mode, depth, aperture, &pix): pix and the two words after it
        pix = m.uc.reg_read(UC_PPC_REG_7)
        if pix > 0x1000:
            w, h = MODES[(m.seed * 7 + k) % len(MODES)]
            m.w32(pix, w * 4); m.w32(pix + 0x9c, w); m.w32(pix + 0xa0, h)
        return 0 if (m.seed + k) % 9 != 7 else 0xe00002bc
    return new_mock(m, name, k)


def w_set_display(m, rng):
    this = m.alloc(0xc60); fill_words(m, this, 0xc60, rng); m.w32(this, m.vtable('ATIRadeonX1000'))
    m.w32(this + 0x860, m.mmio(0x20000, display_regs(rng)))
    m.w32(this + 0x7c, obj(m, rng, 'ATIR500Memory', 0x40)); m.w32(this + 0x93c, obj(m, rng, 'ATIR500Memory', 0x40))
    m.w32(this + 0xd4, plain(m, rng)); m.w32(this + 0xf4, plain(m, rng))
    m.w32(this + 0x98, rng.choice([0, 0x10000, 0x80000, 0x90000, 0x410000, 0x110000]))
    m.w32(this + 0xcc, rng.choice([0, 1, 2, 2]))
    m.w32(this + 0xe4, rng.choice([0, 1]))
    m.w32(this + 0xbb4, rng.choice([0, 0, 0x100000])); m.w32(this + 0xbac, rng.choice([0, 0x1000]))
    m.w32(this + 0xb6c, rng.choice([0, 0x1000])); m.w32(this + 0xb70, rng.choice([0, 0x1000]))
    return [this]


CHIPS = [0x7140, 0x7142, 0x7157, 0x71c0, 0x71c2, 0x71d2, 0x71de, 0x7240, 0x724e, 0x7260, 0x7100, 0x7143, 0x714e, 0x7150, 0x715e, 0x71ce, 0x1234]


def start_regs(rng):
    """the register file start() probes: bytes +8..+0xf are the write-strobe / chip-id / chip-revision block (+0xc/+0xd the chip id, +0xf the revision)"""
    chip = rng.choice(CHIPS)
    t = {0xc: chip | (rng.choice([0, 1, 2, 3, 0xc]) << 24), 0x8: 0x12345678, 0xf8: rng.choice([0, 0x8000000, 0x10000000])}
    def default(off):
        if off in t:
            return int.from_bytes(struct.pack('<I', t[off]), 'big')
        return (off * 2654435761 + 0x1234567) & 0xffffffff
    return RegisterFile(rng, default)


STEP_OK = ('startupPCIeGART', 'allocCommandBuffer', 'initialize_hardware', 'enable_GPUSensor')


def start_mock(m, name, k):
    if 'IOATIR500Accelerator' in name and 'start' in name:
        return 1                                                            # the base class started
    if 'ATIR500Memory' in name and ('init_pool' in name or 'reserve' in name):
        return 1
    if name.endswith('vtable slot +0x578'):
        return 1
    if name.endswith('vtable slot +0x57c'):
        o = m.alloc(0x400); m.w32(o, m.vtable('IOATIR500Shared', 0x800)); return o
    if name.endswith('vtable slot +0xd0'):
        return m.regwin
    if 'IOMallocAligned' in name:                                           # a real buffer of the requested size (the ring words are filled in afterwards)
        return m.alloc(max(m.uc.reg_read(UC_PPC_REG_3), 0x10))
    if 'HZMEM_Init' in name:
        return 0 if (m.seed + k) % 6 else 1
    return display_mock(m, name, k)


def w_start(m, rng):
    this = m.alloc(0xc60); fill_words(m, this, 0xc60, rng); m.w32(this, m.vtable('ATIRadeonX1000'))
    m.regwin = m.mmio(0x20000, start_regs(rng))
    m.w32(this + 0x74, plain(m, rng)); m.w32(this + 0xb4, plain(m, rng))
    m.w32(this + 0x7c, obj(m, rng, 'ATIR500Memory', 0x40))
    m.w32(this + 0x98, rng.choice([0, 0x80, 0x80000, 0x80080]))
    m.w8(this + 0x84, rng.choice([32, 32, 128]))                           # the cache line size the flush loop steps by (a zero would never end)
    m.w32(this + 0xcc, rng.choice([0, 1, 2])); m.w32(this + 0xe4, rng.choice([0, 1]))
    return [this, plain(m, rng)]


CASES = [
    Case('ATIRadeonX1000::set_display_mode_and_vram', w_set_display, ret='bool', seeds=200, mock=display_mock, plain_words=True, ignore_args={'IOLog': [2, 3, 4, 5, 6, 7, 8]}),
]

# start(): matches stock since the #184 fix (chip-id strobe block uses word accesses). Before it, the rebuilt code did byte accesses.
START_CASES = [
    Case('ATIRadeonX1000::start', w_start, ret='bool', seeds=100, mock=start_mock, ignore_args={'IOLog': [2, 3, 4, 5, 6, 7, 8], 'vtable slot +0x164': [1, 2]}),
]
CASES = CASES + START_CASES      # #184 fixed: start() now matches stock (the +0x164 string args are image addresses, ignored; image pointers stored are compared by name)
