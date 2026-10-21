"""Hand-written worlds for the HiZ memory allocator (HZMEM_Alloc, HZMEM_Free, HZMEM_InitMemResource): free functions, so the generic worlds do not reach them.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_N6.py   (needs STOCK_KEXT; see Tools/difftest/README.md)

hizData: +0 mode, +4 / +8 the units tileDim and size must be multiples of, +0xc number of pools (3), +0x10 / +0x14 / +0x18 pool descriptors (0x1014 bytes):
pool[0] blocks in the usage map, [1] bytes per block, [2] limit in bytes, [3] usage map (one byte per block, 1 = in use), [4] slots in use, then 0x100 slots of
four words from pool+5 (in use, offset, request bytes, size)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from unicorn.ppc_const import UC_PPC_REG_3


def hiz_world(m, rng, kinds=3, fill_map=True):
    hz = m.alloc(0x20)
    m.w32(hz, rng.choice([1, 2, 3]))
    m.w32(hz + 4, rng.choice([2, 4, 4, 8]))
    m.w32(hz + 8, rng.choice([2, 4, 4, 8]))
    m.w32(hz + 0xc, 3)
    pools = []
    for k in range(kinds):
        pool = m.alloc(0x1014)
        nblocks = rng.choice([0x20, 0x40, 0x100, 0x400])
        bsize = rng.choice([0x10, 0x10, 0x40, 0x100])
        mp = m.alloc(nblocks + 8)
        if fill_map:
            run = 0
            for i in range(nblocks):
                if run == 0:
                    run = rng.randrange(1, 12)
                    cur = rng.choice([0, 0, 1])
                m.w8(mp + i, cur)
                run -= 1
        m.w32(pool, nblocks)
        m.w32(pool + 4, bsize)
        m.w32(pool + 8, rng.choice([nblocks * bsize, nblocks * bsize // 2, nblocks * bsize * 2, 0x7fff0]))
        m.w32(pool + 12, mp if rng.randrange(12) else 0)
        m.w32(pool + 16, rng.choice([0, 3, 0x20, 0x100, 0xff]))
        for s in range(0x100):
            if rng.randrange(4) == 0:
                m.w32(pool + 20 + 16 * s, 1)
                m.w32(pool + 24 + 16 * s, rng.randrange(nblocks) * bsize)
                m.w32(pool + 28 + 16 * s, rng.randrange(1, 8) * bsize)
                m.w32(pool + 32 + 16 * s, rng.randrange(1, 8) * bsize)
        m.w32(hz + 0x10 + 4 * k, pool if rng.randrange(20) else 0)
        pools.append((pool, nblocks, bsize))
    return hz, pools


def w_alloc(m, rng):
    hz, pools = hiz_world(m, rng)
    unit_w, unit_h = m.r32(hz + 4), m.r32(hz + 8)
    kind = rng.choice([0, 1, 2, 0, 1, 2, 3])
    field = rng.choice([0xffffffff, 0, rng.getrandbits(32), rng.getrandbits(32) & 0x3ff])
    tile = unit_w * rng.randrange(1, 40) + (rng.choice([0, 0, 0, 1]))
    size = unit_h * rng.randrange(1, 40) + (rng.choice([0, 0, 0, 1]))
    return [hz, field, kind, tile, size]


def w_free(m, rng):
    hz, pools = hiz_world(m, rng)
    kind = rng.choice([0, 1, 2, 0, 1, 2, 3])
    slot = rng.choice([rng.randrange(0x100), rng.randrange(0x100), 0x3ff])
    field = rng.getrandbits(32) & ~0x3fffffff
    if kind == 0: field |= slot | (rng.getrandbits(10) << 10)
    elif kind == 1: field |= (slot << 10) | rng.getrandbits(10)
    else: field |= (slot << 20) | rng.getrandbits(10)
    return [hz, field, kind]


def w_init(m, rng):
    hz = m.alloc(0x20)
    return [hz, rng.choice([0, 1, 1, 2, 3, 3]), rng.choice([1, 2, 4, 6]), rng.choice([1, 2, 4])]


def init_mock(m, name, k):
    """IOMallocPageable: a real block of the requested size (the third and fourth calls fail on some seeds); the free calls return nothing"""
    if 'IOMallocPageable' in name:
        if rng_fail(m, k): return 0
        return m.alloc(max(m.uc.reg_read(UC_PPC_REG_3), 0x10))
    return 0


def rng_fail(m, k):
    return ((m.seed * 7 + k * 3) % 5) == 0


STORE_REGS = [0x1004, 0x1005, 0x1006, 0x101d, 0x1041, 0x1080, 0x1081, 0x1082, 0x1087, 0x1095, 0x109e, 0x10ae, 0x10af, 0x10c1, 0x10c2, 0x10c8, 0x10ea, 0x10f8, 0x10f9, 0x10fa,
              0x1110, 0x1130, 0x1150, 0x1181, 0x118c, 0x118d, 0x118e, 0x11aa, 0x11ab, 0x11ac, 0x12f5, 0x1381, 0x1386, 0x138e, 0x138f, 0x13c0, 0x13c1, 0x825, 0x82d, 0x854, 0x887]


def w_store_reg(m, rng):
    """store_reg(tracked_register_set *state, UInt32 regIndex, UInt32 value): the register shadow of the PM4 stream tracker. Register 0x1095 fills a small ring
    (state +0xfc: bit 16 locks it, low 9 bits = slot; +0x100 = values stored in the slot so far); the others store into fixed fields."""
    state = m.alloc(0x400)
    m.w32(state + 0xfc, rng.choice([0, 1, 2, 5, 0x10000, 0x10001, 0x1ff, 0x123, rng.getrandbits(32)]))
    m.w32(state + 0x100, rng.choice([0, 1, 2, 3, 4, 5, 6, 7]))
    reg = rng.choice(STORE_REGS + [r + d for r in STORE_REGS for d in (-1, 1)] + [rng.randrange(0x2000)])
    return [state, reg, rng.getrandbits(32)]


CASES = [
    Case('__Z11HZMEM_AllocP7_HZDATAmmmm', w_alloc, ret='u32', seeds=300, plain_words=True),
    Case('__Z10HZMEM_FreeP7_HZDATAmm', w_free, ret='u32', seeds=300),
    Case('__Z9store_regP20tracked_register_setmm', w_store_reg, ret='void', seeds=500, plain_words=True),
    Case('__Z21HZMEM_InitMemResourceP7_HZDATAmmm', w_init, ret='u32', seeds=120, mock=init_mock, plain_words=True),
]
