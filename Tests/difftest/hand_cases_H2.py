"""Hand-written worlds (hand-world push H2): ATIRadeonX1000 free functions whose generic world reaches little of the code
(startupPCIeGART, the page-off texture functions, DumpASICHangState, the promo4/xdct engines, the speed-change and timestamp helpers, ...).
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_H2.py   (needs STOCK_KEXT; DIFFTEST_UNCOVERED=1 prints what no run executed)

Field offsets are read from Headers/FieldOffsets.h by name, so a world says what it sets (`F('hwCapabilityBits')`), not a bare number."""
import os, sys, re, struct
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from common import RegisterFile, word, fill_words
from hand_cases_D import new_mock, obj, plain
from unicorn.ppc_const import UC_PPC_REG_3, UC_PPC_REG_4, UC_PPC_REG_5, UC_PPC_REG_6, UC_PPC_REG_7

_OFF = {}
for _ln in open(os.path.join(HERE, '..', '..', 'Headers', 'FieldOffsets.h')):
    _m = re.match(r'static const int k(\w+?)_(\w+) = (0x[0-9a-f]+|\d+);', _ln)
    if _m:
        _OFF[(_m.group(1), _m.group(2))] = int(_m.group(3), 0)


def F(name, cls='IOATIR500Accelerator'):
    """offset of a named field of `cls` (Headers/FieldOffsets.h)"""
    return _OFF[(cls, name)]


def regfile(rng, table=None, default=None):
    """a register file whose registers in `table` (offset -> value as the CPU reads it through lwbrx) hold those values; the rest answer a per-offset constant"""
    t = table or {}
    def d(off):
        if off in t:
            return int.from_bytes(struct.pack('<I', t[off] & 0xffffffff), 'big')
        return default(off) if default else (off * 2654435761 + 0x1234567) & 0xffffffff
    return RegisterFile(rng, d)


def accel(m, rng, table=None, regs=None, size=0xc60):
    """an accelerator object: random words, its vtable, the hardware-alive flag, the command lock and a register window"""
    a = m.alloc(size); fill_words(m, a, size, rng)
    m.w32(a, m.vtable('ATIRadeonX1000'))
    m.w8(a + 0x80, 1)
    m.w32(a + 0x840, a + 0x900)
    m.w32(a + F('mmioBase'), m.mmio(0x20000, regs or regfile(rng, table)))
    return a


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# startupPCIeGART: sets up the GART table (in VRAM, or a main-memory table for the old-style path), programs the GART registers

def w_gart(m, rng):
    size = rng.choice([0, 0x10000, 0x20000, 0x8000, 0x1000, 0x1800, 0x4000])
    vram = size + rng.choice([0, 0x1000, 0x10000, 0x8000000])        # the VRAM size register: the table sits in its top `size` bytes (clamped to 128 MB)
    a = accel(m, rng, {0xf8: vram})
    m.w32(a + F('hwCapabilityBits'), rng.choice([0xf00000, 0x100000, 0x80 | 0x100000, 0x300000 | 0x80, 0]))
    m.w32(a + F('gartTableCpuAddress'), 0)
    m.w32(a + F('pcieGartTable'), rng.choice([0, 0, 0, plain(m, rng)]))
    m.w32(a + F('gartSizeKB'), size)
    # the VRAM aperture: table CPU address = aperture + (vram - size), so it must be a block big enough to hold the table at that offset
    m.w32(a + F('vramApertureBase'), rng.choice([0, m.alloc(0x40000)]) if vram - size < 0x20000 else 0)
    m.w32(a + F('gartEmptyEntry'), word(rng))
    pci = m.alloc(0x100)
    m.w32(pci, m.vtable('IOATIR500Shared', 0x800))          # an object of a class outside the kext: virtual calls are recorded by slot offset
    m.w32(a + F('pciDevice'), pci)
    return [a]


def mock_gart(m, name, k):
    if 'IOMallocAligned' in name:
        n = m.uc.reg_read(UC_PPC_REG_3)
        if (m.seed + k) % 6 == 5:
            return 0
        return m.alloc(max(min(n, 0x100000), 0x10))
    if vs(name, 0x568):          # findPCICapability
        return (m.seed + k) % 3
    return default_mock(m, name, k)


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# page-off texture functions: pageoff_linear_buffer, pageoff_dirty_texture_with_gpu, prepare_texture_for_pageoff_with_cpu, pageoff_dirty_texture.
# The arguments are a VendorTextureBuffer (type byte +0x20: 3 = plain, 7 = sub-buffer of the one at +0x58; +4 GART offset; +0x14 the header with the
# mip/face counts; +0x48 VRAM offset; +0x50 size) and an ATITextureBufferHeader (a block of command words at +0xa00, per-face/level tile records at
# +0x40 + face*0x1a0 + level*0x20, flags at +0x20). Everything is small and in range so the loops end; the choices decide which branch runs.

def vs(name, off):
    """is `name` the virtual call through vtable slot +off (the harness names it 'vtable slot +0x..' or, when the vtable listing knows the method, '... [vcall +0x..]')"""
    return name.endswith('vtable slot +0x%x' % off) or name.endswith('[vcall +0x%x]' % off)


def pow2(rng, lo=0, hi=9):
    return 1 << rng.randrange(lo, hi)


def hw_info(m, rng):
    h = m.alloc(0x4000)
    m.w32(h + 0, rng.randrange(0, 9)); m.w32(h + 4, rng.randrange(0, 5)); m.w32(h + 8, rng.randrange(0, 9))
    m.w32(h + 0xc, pow2(rng)); m.w32(h + 0x10, pow2(rng)); m.w16(h + 0x16, pow2(rng))
    m.w8(h + 0x1a, rng.randrange(0, 6)); m.w8(h + 0x1b, rng.randrange(0, 4))
    m.w32(h + 0x20, rng.choice([0, 0x20000000, 0x40000000, 0x60000000, 0x10000000, 0x40000000]))
    for f in range(6):
        for l in range(13):
            t = h + 0x40 + f * 0x1a0 + l * 0x20
            m.w16(t + 2, rng.randrange(0, 4))
            for off in (4, 8, 0xc, 0x10):
                m.w32(t + off, rng.choice([0, 0x20, 0x100, 0x1000]))
            m.w16(t + 0x18, rng.randrange(0, 9))
    return h


def tex_header(m, rng):
    hd = m.alloc(0x80)
    m.w32(hd + 0xc, rng.randrange(0, 100))
    m.w8(hd + 0x15, rng.getrandbits(8)); m.w8(hd + 0x17, rng.randrange(0, 3))
    m.w16(hd + 0x1c, rng.getrandbits(16)); m.w16(hd + 0x28, rng.getrandbits(16)); m.w16(hd + 0x2a, rng.getrandbits(16))
    m.w8(hd + 0x34, rng.choice([0, 1, 1, 2, 3, 6])); m.w8(hd + 0x35, rng.randrange(1, 5))      # 0 levels with base level 0 would loop 2^32 times in both builds
    m.w16(hd + 0x36, rng.choice([0, 0, 1]))
    return hd


def tex_buffer(m, rng, typ=None, depth=0):
    t = m.alloc(0x100)
    m.w32(t + 4, rng.choice([0, 0, 0x1000, 0x2000]))
    back = m.alloc(0x100); m.w32(back, m.vtable('IOATIR500Shared', 0x800)); m.w32(t + 8, back)
    m.w32(t + 0x14, tex_header(m, rng))
    m.w8(t + 0x20, typ if typ is not None else rng.choice([3, 3, 7, 7, 3, 1, 0]))
    m.w32(t + 0x48, rng.choice([0, 0x1000, 0x40000, 0x2000000, 0x8000000]))
    m.w32(t + 0x50, rng.choice([0x1000, 0x10000]))
    if depth == 0:
        m.w32(t + 0x58, tex_buffer(m, rng, 3, 1))
    m.w16(t + 0xe, rng.randrange(0, 4))
    return t


def tex_accel(m, rng):
    a = accel(m, rng)
    m.w32(a + F('usableVramSize'), rng.choice([0, 0x10000, 0x1000000, 0x4000000]))
    m.w32(a + F('vramSizeProgrammed'), rng.choice([0, 0x100000]))
    m.w32(a + F('vramPool'), obj(m, rng, 'ATIR500Memory', 0x40))
    m.w32(a + F('gbTileConfig'), word(rng))
    m.w32(a + F('commandGLBytesPerSample'), rng.randrange(0, 1000))
    return a


def mock_tex(m, name, k):
    r = (m.seed * 7 + k * 3) % 5
    if vs(name, 0x5a8):                       # map the buffer into the GART: succeeds or not
        return 1 if r in (0, 3) else 0
    if 'freeToAllocGART' in name or 'freeToAllocTextureCPUVisibleVRAM' in name:
        return 1 if r in (1, 4) else 0
    if 'ATIR500Memory' in name and 'alloc' in name and 'dealloc' not in name:
        return 0 if r == 2 else 1
    if vs(name, 0x14c):                       # IOMemoryDescriptor::map -> an IOMemoryMap whose getVirtualAddress is the header block
        if r == 4:
            return 0
        o = m.alloc(0x100); m.w32(o, m.vtable('IOATIR500Shared', 0x800)); return o
    if vs(name, 0xd0):
        return m.hw_block
    if 'submit_buffer' in name:
        return 0x1000 + (m.seed + k) % 7
    return default_mock(m, name, k)


def w_linear(m, rng):
    a = tex_accel(m, rng)
    t = tex_buffer(m, rng, rng.choice([3, 7, 3, 7, 5]))
    return [a, t, hw_info(m, rng)]


def w_with_gpu(m, rng):
    return w_linear(m, rng)


def w_prepare_cpu(m, rng):
    a = tex_accel(m, rng)
    t = tex_buffer(m, rng, rng.choice([3, 7, 3, 7, 5]))
    m.w32(t + 0x48, rng.choice([0x1000, 0x2000000, 0x8000000, 0x40000, 0x10000000]))     # >= usableVramSize on most seeds, so the move runs
    return [a, t, hw_info(m, rng)]


def w_dirty(m, rng):
    a = tex_accel(m, rng)
    t = tex_buffer(m, rng, rng.choice([3, 7, 3, 7, 5]))
    m.hw_block = hw_info(m, rng)
    return [a, t, rng.randrange(0, 4), rng.randrange(0, 4)]


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# declarative accelerator worlds: `spec` maps a field name (or a raw offset) to a list of choices; a choice is an int, ('blk', size) for a fresh zeroed
# block, ('obj', class, size) for an object with that class's vtable, ('ext', size) for an object of a class outside the kext (virtual calls recorded by slot)

def put(m, rng, base, key, choices, cls='IOATIR500Accelerator'):
    off = key if isinstance(key, int) else F(key, cls)
    c = rng.choice(choices)
    if isinstance(c, tuple):
        if c[0] == 'blk':
            c = m.alloc(c[1])
        elif c[0] == 'obj':
            c = obj(m, rng, c[1], c[2] if len(c) > 2 else 0x100)
        elif c[0] == 'ext':
            c = m.alloc(c[1]); m.w32(c, m.vtable('IOATIR500Shared', 0x800))
        elif c[0] == 'u8':
            m.w8(base + off, c[1]); return
        elif c[0] == 'u16':
            m.w16(base + off, c[1]); return
        else:
            raise ValueError(c)
    m.w32(base + off, c)


def spec_accel(m, rng, spec, regs=None, table=None):
    a = accel(m, rng, table, regs)
    for k, ch in spec.items():
        put(m, rng, a, k, ch)
    return a


class SeqRegisters(RegisterFile):
    """a device model with scripted registers: `script` maps a register offset to a list of values (as the CPU reads them through lwbrx); each read of that
    register returns the next value and the last one repeats. Every other register is a plain remember-what-was-written register file."""
    def __init__(self, rng, script=None, default=None):
        RegisterFile.__init__(self, rng, default)
        self.script, self.pos = script or {}, {}

    def __call__(self, kind, off, size, data):
        base = off & ~3
        if kind == 'R' and base in self.script:
            seq = self.script[base]
            k = self.pos.get(base, 0); self.pos[base] = k + 1
            v = seq[min(k, len(seq) - 1)] & 0xffffffff
            return bytes((v >> (8 * ((off + i) & 3))) & 0xff for i in range(size))
        return RegisterFile.__call__(self, kind, off, size, data)


def scripted(rng, **script):
    return SeqRegisters(rng, {int(k[1:], 16): v for k, v in script.items()})


def flip_regs(rng):
    from common import FlipFlopRegisters
    return FlipFlopRegisters(rng)


def mock_pm(m, name, k):
    r = (m.seed * 5 + k * 3) % 4
    if 'OSIncrementAtomic' in name or 'OSDecrementAtomic' in name:
        return [0, 1, 0, 2][r]
    if 'getPeriodValue' in name:
        if r == 3:
            return 0
        o = m.alloc(0x20); m.w32(o, rng_word(m, 1, 5)); m.w32(o + 4, rng_word(m, 0, 4) * 1000000); return o
    return default_mock(m, name, k)


def rng_word(m, lo, hi):
    return lo + (m.seed * 2654435761 >> 7) % (hi - lo + 1)


def spec_world(spec, regs=False, nargs=0, table=None):
    def world(m, rng):
        a = spec_accel(m, rng, spec, flip_regs(rng) if regs else None, table)
        return [a] + [0] * nargs
    return world


# power management: system_will_change_speed (quiesce the GPU: ring packets, wait for the xdct engine) and system_did_change_speed (re-read the periods)
WILL = {'displayChangeDepth': [0], 'commandLock': [('blk', 0x40)], 'gpuSensorProvider': [0, ('ext', 0x100)], 'gpuSensorTimer': [0, ('ext', 0x100)],
        'ringIndex': [0, 5, 0x7fd, 0x7fe, 0x7ff], 'mainRingMemory': [('blk', 0x2000)], 'submitStamp': [1, 0x7fffffff, 0xffffffff],
        'xdctEngineRunning': [0, 1, 1], 'idctSubmitBaseCounter': [0, 5], 0x80: [('u8', 0), ('u8', 1), ('u8', 1), ('u8', 1)]}
DID = {'displayChangeDepth': [1, 1, 2, 0], 'commandLock': [('blk', 0x40)], 'gpuSensorProvider': [0, ('ext', 0x100)], 'gpuSensorTimer': [0, ('ext', 0x100)],
       'gpuSensorPeriodMs': [0, 10], 'swdsPeriodMsA': [0, 10]}
SENSOR = {'gpuSensorTimer': [0, ('ext', 0x100)], 'gpuSensorPeriodMs': [0, 10, 100], 'gpuSensorSampleCount': [5, 0], 'gpuSensorBusyCount': [3, 0]}


def w_will(m, rng):
    a = spec_accel(m, rng, WILL, scripted(rng, r1fb4=rng.choice([[0x80000000], [0, 0x80000000], [0] * 6 + [0x80000000], [0], [0x80000000, 0]])))
    return [a]


def w_did(m, rng):
    return [spec_accel(m, rng, DID)]


def w_sensor(m, rng):
    return [spec_accel(m, rng, SENSOR)]


def w_period(m, rng):
    a = spec_accel(m, rng, {'gpuSensorProvider': [0, ('ext', 0x100), ('ext', 0x100)]})
    return [a, m.alloc(0x40)]


def mock_period(m, name, k):
    # the provider's getProperty (slot +0x188) yields an OSData-like object (its slot +0x100 returns the bytes) or nothing
    if vs(name, 0x188) or 'safeMetaCast' in name:
        r = (m.seed + k) % 4
        if r == 3:
            return 0
        o = m.alloc(0x100); m.w32(o, m.vtable('IOATIR500Shared', 0x800)); return o
    if vs(name, 0x100):
        return m.alloc(0x20)
    return default_mock(m, name, k)


def w_platform(m, rng):
    a = spec_accel(m, rng, {'gpuSensorProvider': [0, ('ext', 0x100), ('ext', 0x100)], 'gpuSensorSampleCount': [0, 7, 100], 'gpuSensorBusyCount': [0, 3, 50],
                            'gpuSensorTimer': [0, ('ext', 0x100)], 0x80: [('u8', 0), ('u8', 1), ('u8', 1)]})
    fn = m.alloc(0x20)
    m.w32(a + F('gpuSensorFunction'), fn if rng.random() < 0.7 else m.alloc(0x20))
    return [a, fn, rng.randrange(0, 2), m.alloc(0x10), m.alloc(0x10), m.alloc(0x10), m.alloc(0x10)]


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# engines: xdct (IDCT) start/stop, submit_ring_data, setupR520Pipes

def idle_gpu(rng, **extra):
    """an idle R5xx: RBBM_STATUS (0xe40) not busy, 0x1720 ready; `extra` = register offsets (rXXXX=...) scripted as lists of values read in turn"""
    script = {0xe40: [0], 0x1720: [0x30000]}
    script.update({int(k[1:], 16): v for k, v in extra.items()})
    return SeqRegisters(rng, script)


def w_xdct_start(m, rng):
    # the engine's read pointer (0x1f9c) is polled until it reaches the write pointer (0x1fa0): immediately, after a few reads, or never (10000 retries)
    behind = rng.choice([[9], [1, 1, 9], [1] * 40 + [9], [1] * 20000, [1, 9]])
    a = spec_accel(m, rng, {'idctRingCursor': [0, 5, 0x100], 'vramSizeProgrammed': [0, 0x100000], 'scratchBufferGartOffset': [0, 0x1000],
                            'idctPointerBase': [0x2000, 0x3000], 'scratchHeader': [0x1000, 0x2000], 'idctRingGartOffset': [0, 0x4000],
                            'idctSubmitBaseCounter': [0, 3]}, idle_gpu(rng, r1f9c=behind, r1fa0=[5]))
    return [a]


def w_xdct_stop(m, rng):
    return w_xdct_start(m, rng)


def w_ring(m, rng):
    a = spec_accel(m, rng, {'ringIndex': [0, 3, 8, 0x7fe, 0x7ff, 0x400, 0x13], 'mainRingCursor': [0, 0, 5, 0x10, 0x7f8, 0x400, 0x13, 0x7ff],
                            'hwCapabilityBits': [0, 0x80, 0x80, 0x80 | 0x100000], 'mainRingMemory': [('blk', 0x2000)], 0x84: [('u8', 32), ('u8', 128), ('u8', 64)]})
    return [a]


def w_pipes(m, rng):
    chip = rng.choice([0, 0x10000000, 0x20000000, 0x30000000, 0x40000000]) | rng.choice([0, 0x1000000])
    a = spec_accel(m, rng, {'hwCapabilityBits': [0, 0x200000, 0x200000, 0x200000], 'chipRev': [0, 3, 4, 9]},
                   idle_gpu(rng, r402c=[rng.choice([0, 0x1000, 0x2000, 0x3000]) | rng.getrandbits(8)], r8=[0x12345678], rc=[chip]))
    return [a]


# promo4 (PM4 microcode engine) and hardware bring-up
BUSY = lambda rng: rng.choice([[0], [0x80000000, 0], [0x80000000] * 6 + [0], [0x10200] * 4 + [0], [0x60000, 0x380000, 0]])


def w_stop_promo4(m, rng):
    # idle-wait loops: 0xe40 busy (bit 31 / 0x60000 / 0x380000) for a while, 0x1720 ready bits missing for a while; some seeds never get idle (1000 retries)
    e40 = rng.choice([[0], [0x80000000, 0], [0x80000000] * 40 + [0], [0x60000] * 3 + [0], [0x380000] * 5 + [0], [0x80000000]])
    r1720 = rng.choice([[0x30000], [0, 0x30000], [0x10000] * 4 + [0x30000], [0x20000] * 3 + [0x30000], [0]])
    a = spec_accel(m, rng, {}, SeqRegisters(rng, {0xe40: e40, 0x1720: r1720}))
    if rng.random() < 0.15:
        m.w32(a + F('mmioBase'), 0)
    return [a]


def w_start_promo4(m, rng):
    e40 = rng.choice([[0], [0x10000, 0], [0x200, 0x10000, 0], [0x10200] * 5 + [0]])
    a = spec_accel(m, rng, {'hwCapabilityBits': [0, 0x80000, 0x80000, 0x200000], 'ringPointerBase': [('blk', 0x100)], 'ringWritePointerOffset': [0, 8, 0x10],
                            'vramSizeProgrammed': [0, 0x100000], 'scratchBufferGartOffset': [0, 0x1000], 'scratchHeader': [0x1000], 0xe4: [0, 0, 7], 0x104: [0, 9]},
                   SeqRegisters(rng, {0xe40: e40, 0x710: [rng.choice([0, 5, 0x7ff, 0x1234, 0xffff])]}))
    m.w8(a + 0x80, 0)
    return [a, rng.choice([4, 4, 4, 4, 3, 0])]


def w_start_promo4_timeout(m, rng):
    a = spec_accel(m, rng, {'ringPointerBase': [('blk', 0x100)], 'ringWritePointerOffset': [0]}, SeqRegisters(rng, {0xe40: [0x10000]}))
    return [a, 4]


def w_init_hw(m, rng):
    a = spec_accel(m, rng, {'hwCapabilityBits': [0, 0x100000, 0x200000, 0x400000, 0x600000, 0x800000, 0xa00000, 0xf00000], 'submitStamp': [1, 7],
                            'retiredStampCounter': [0, 4], 'gartTableCpuAddress': [0, 0x1000], 'ringIndex': [0, 0x7ff, 5], 'mainRingMemory': [('blk', 0x2000)],
                            0x85: [('u8', 0), ('u8', 1)]}, idle_gpu(rng))
    return [a]


def mock_init_hw(m, name, k):
    if 'start_promo4_engine' in name:
        return 0 if (m.seed % 5) == 4 else 1
    if 'set_display_mode_and_vram' in name:
        return 0 if (m.seed % 7) == 6 else 1
    return default_mock(m, name, k)


def w_dump(m, rng):
    # the hang detector: register 0x7f8 must stay the same for 100001 polls, otherwise the function returns early
    script = {0x7f8: rng.choice([[0x1234], [0x1234] * 3 + [0x4321], [0x77]])}
    a = spec_accel(m, rng, {'hwCapabilityBits': [0, 0x400000], 'gpuSensorTimer': [0, ('ext', 0x100)]}, SeqRegisters(rng, script))
    return [a]


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# state-heavy accelerator functions (software display scaler, scanout): the object is filled with words built from two halfwords drawn from a small set that
# makes the usual tests (non-zero, equal, above 0x1000, a bit set) go both ways; the spec then fixes the pointers and flags the function needs.
RICH = [0, 0, 0, 1, 1, 2, 3, 4, 0x10, 0x20, 0x100, 0x300, 0x400, 0x1000, 0x1001, 0x2000, 0x8000, 0xffff]


def rich_word(rng):
    return (rng.choice(RICH) << 16) | rng.choice(RICH)


def rich_fill(m, base, lo, hi, rng, words=None):
    m.uc.mem_write(base + lo, b''.join(struct.pack('>I', rng.choice(words) if words else rich_word(rng)) for _ in range((hi - lo) // 4)))


def rich_accel(m, rng, spec, regs=None, lo=0x84, hi=0xc60, words=None):
    a = accel(m, rng, None, regs)
    window = m.r32(a + F('mmioBase'))
    rich_fill(m, a, lo, hi, rng, words)
    m.w8(a + 0x80, 1); m.w32(a + 0x840, a + 0x900); m.w32(a + F('mmioBase'), window)
    for k, ch in spec.items():
        put(m, rng, a, k, ch)
    for off in (0x166, 0x1de, 0x9f6, 0xa6e, 0x1df, 0xa6f, 0x1db, 0x1dc, 0x1dd, 0xa6b, 0xa6c, 0xa6d):
        m.w8(a + off, rng.choice([0, 1, 3, 4, 5, 6, 9, 10, 15, 47]))      # format-table indices: the shipped table has 48 entries (a larger index reads other data, laid out differently per build)
    return a


def mock_swds(m, name, k):
    r = (m.seed * 3 + k * 7) % 5
    if vs(name, 0x554):                       # checkForTimeStamp(stamp)
        return 0 if r in (0, 3) else 1
    if 'SWDSWriteBlitToCmdBuf' in name:
        return r + 2
    if 'pcl_CopyPix' in name:
        return m.uc.reg_read(UC_PPC_REG_3) + 4 * (r + 3)
    if 'submit_buffer' in name:
        return 0x2000 + (m.seed + k) % 5
    if 'ATIR500Memory' in name and ('reserve' in name or 'alloc' in name) and 'dealloc' not in name:
        return 0 if r == 2 else 1
    if 'safeMetaCast' in name:
        return m.uc.reg_read(UC_PPC_REG_3) if r != 1 else 0
    return default_mock(m, name, k)


def swds_common():
    return {'hwCapabilityBits': [0, 0x10000, 0x10000], 'vramPool': [('obj', 'ATIR500Memory', 0x40)], 'vramPoolB': [('obj', 'ATIR500Memory', 0x40)],
            'usableVramSize': [0x4000000, 0x8000000], 'vramSize': [0x4000000, 0x8000000, 0x10000000], 'swdsEntryIndex': [0, 1],
            'scanoutOverlapsVram': [0, 1, 1], 'swdsTimer': [0, ('ext', 0x100)]}


def w_swds_blit(m, rng):
    sp = swds_common()
    sp.update({0xb5c: [0, 0x5a, 0xb4, 0x10e, 0xb4], 0xb60: [0, 0x5a, 0xb4, 0x10e, 0xb4]})
    for base in (0x148, 0x1c0):                                     # the source rectangle of each panel: a tall one (> 0x1000 rows) takes the pcl_CopyPix route
        sp[base] = [('u16', 0x100), ('u16', 0x800), ('u16', 0x1001), ('u16', 0x2000)]
        sp[base + 2] = [('u16', 0x20), ('u16', 0x400), ('u16', 0x1001)]
    for base in (0x9d8, 0xa50):
        sp[base] = [('u16', 0x100), ('u16', 0x800), ('u16', 0x20)]
        sp[base + 2] = [('u16', 0x20), ('u16', 0x400), ('u16', 0)]
    a = rich_accel(m, rng, sp, SeqRegisters(rng, {}))
    return [a, m.alloc(0x4000), rng.choice([0, 1, 4, 20]), rng.choice([0, 1]), rng.choice([0, 1])]


def w_swds_init(m, rng):
    sp = swds_common()
    sp.update({0xaf4: [('blk', 0x400)], 0xb10 + 4: [0, 1], 0xb2c: [0, 1, 2], 0xb30: [0, 1, 2], 0xb34: [0, 1, 2], 0xb38: [0, 640, 1024, 2], 0xb3c: [0, 1, 2], 0xb40: [0, 480, 768, 2],
               0xb60: [0, 1], 0xb48: [0, 1, 2], 0xb50: [0, 640], 0xb58: [0, 480], 0xb78: [0, 1], 0x1ba: [('u16', 2), ('u16', 4), ('u16', 0)], 0x1c0: [('u16', 640), ('u16', 1024), ('u16', 0)],
               0x1c2: [('u16', 480), ('u16', 768), ('u16', 0)]})
    a = rich_accel(m, rng, sp, SeqRegisters(rng, {}))
    return [a]


def w_swds_func(m, rng):
    sp = swds_common()
    sp.update({0x9b0: [('u8', 0), ('u8', 1), ('u8', 1), ('u8', 1)], 0xb10: [0, 1], 0xb28: [0, 1], 0xacc: [0, 5], 0xad0: [0, 7], 0xad4: [0, 3], 0xad8: [0, 3], 0x894: [0, 1, 1],
               0xec: [0, 9], 0x10c: [0, 4], 0x9b8: [('ext', 0x100)], 0xaf4: [('blk', 0x400)], 0xb10 + 0x0: [0, 1], 0xadc: [0, 1], 0xae4: [0, 0x100], 0xb00: [0, 0x100],
               0xb14: [('blk', 0x400)], 0xb2c: [0, 1]})
    a = rich_accel(m, rng, sp, SeqRegisters(rng, {0xbf8: [rng.choice([0, 0x80, 0x40, 0xc0])]}))
    return [a, 0, 0]


def w_swds_clut(m, rng):
    a = rich_accel(m, rng, {0xb2c: [0, 2, 3, 1], 0xb30: [0, 2], 0xd4: [('ext', 0x800), 0], 0xf4: [('ext', 0x800), 0]}, SeqRegisters(rng, {}))
    return [a, rng.choice([0, 1, 0, 1, 2])]


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# time stamps: waitForTimeStampNoLock / sleepForTimeStampNoLock poll a stamp the GPU writes into a page; the device is modelled by the thread_block mock
# (the CPU waits there), which "retires" the stamp on a chosen call. clock_get_uptime / absolutetime_to_nanoseconds fill their 8-byte out arguments.

CLOCK_EXTENTS = {'clock_get_uptime': {0: 8}, 'absolutetime_to_nanoseconds': {2: 8}}


def stamp_world(release, field='checkedStampOffset'):
    def world(m, rng):
        a = spec_accel(m, rng, {'stampPageBase': [('blk', 0x1000)], 'retiredStampOffset': [0, 8, 0x20], 'checkedStampOffset': [0, 4, 0x10],
                                'hardwareWaitTime': [0, 100], 'lastReadStamp': [5, 100, 0xfffffffe], 'lastRetiredStamp': [5, 100, 0xfffffffe],
                                'lastConsumedIDCTStamp': [5, 100], 'mmioBase': [0]}, None)
        m.w32(a + F('mmioBase'), m.mmio(0x20000, SeqRegisters(rng, {0x1fa8: [0x10] if release else [0x10]})))
        last = m.r32(a + F('lastReadStamp'))
        tag = (last + rng.choice([-2, 0, 1, 3, 10])) & 0xffffffff
        base = m.r32(a + F('stampPageBase'))
        which = F(field)
        addr = base + m.r32(a + which)
        cur = (tag + rng.choice([-5, -1, 0, 4])) & 0xffffffff               # what the GPU has written so far (stored little-endian)
        m.uc.mem_write(addr, struct.pack('<I', cur))
        m.stamp_addr, m.release_value, m.release_at = addr, tag, rng.choice([0, 1, 2, 5]) if release else 10 ** 9
        m.w32(a + F('lastRetiredStamp'), last); m.w32(a + F('lastConsumedIDCTStamp'), last)
        return [a, tag]
    return world


def mock_stamp(m, name, k):
    if 'thread_block' in name:
        n = getattr(m, 'tb_calls', 0); m.tb_calls = n + 1
        if n >= getattr(m, 'release_at', 10 ** 9):
            m.uc.mem_write(m.stamp_addr, struct.pack('<I', m.release_value))
        return 0
    if 'clock_get_uptime' in name:
        p = m.uc.reg_read(UC_PPC_REG_3); n = getattr(m, 'clk', 0); m.clk = n + 1
        m.w32(p, 0); m.w32(p + 4, 1000 + 7000 * n + (m.seed % 3) * 5)
        return 0
    if 'absolutetime_to_nanoseconds' in name:
        p = m.uc.reg_read(UC_PPC_REG_5)
        m.w32(p, 0); m.w32(p + 4, (m.uc.reg_read(UC_PPC_REG_4) * 3) & 0xffffffff)
        return 0
    return default_mock(m, name, k)


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# GART entry, texture memory and ring-submit functions

def w_reserve_gart(m, rng):
    a = spec_accel(m, rng, {'pcieGartTable': [('blk', 0x4000)], 'gartTableCpuAddress': [0, ('blk', 0x4000)], 'gartEmptyEntry': [0, 0x12345678, 1],
                            'gartReservedEntry': [0x777, 0xabc], 'gartFlushScratch': [0]}, None)
    base = m.r32(a + F('pcieGartTable'))
    off = rng.choice([0, 0x1000, 0x2000, 0x3000, 0x5000]) if True else 0
    # the entry the call looks at is empty (the usual case) or already used
    empty = m.r32(a + F('gartEmptyEntry'))
    entry = (off >> 12) * 4
    val = empty if rng.random() < 0.6 else (empty ^ 0x55)
    m.uc.mem_write(base + entry, struct.pack('<I', val))
    return [a, off]


def mock_gart_entry(m, name, k):
    if 'reserveInGART' in name:                                   # the base class's reserve: succeeds or fails
        return 0 if (m.seed % 4) == 3 else 1
    return default_mock(m, name, k)


def w_dealloc_tex(m, rng):
    a = spec_accel(m, rng, {'hzmem': [0], 'vramPool': [('obj', 'ATIR500Memory', 0x40)]}, None)
    t = tex_buffer(m, rng, rng.choice([3, 7, 8, 8, 5]), 1)
    hd = m.r32(t + 0x14)
    faces = rng.choice([0, 1, 2, 3, 6])
    m.w8(hd + 0x34, faces)
    for i in range(0, 14, 2):                                      # per-face dirty bitmaps: all clean (+0x1c .. covered by +0x28 ..) or not
        full = rng.choice([0, 0xffff, 0x00ff])
        m.w16(hd + 0x1c + i, rng.choice([full, 0xffff, 0])); m.w16(hd + 0x28 + i, rng.choice([full, 0, 0xffff]))
    m.w8(t + 0x54, rng.choice([0, 1]))
    m.w32(t + 0x10, rng.choice([0, ('x')]) if False else rng.choice([0, m.alloc(0x100)]))
    if m.r32(t + 0x10):
        m.w32(m.r32(t + 0x10), m.vtable('IOATIR500Shared', 0x800))
    m.w32(t + 0x6c, rng.choice([0xffffffff, 0x3ff, 0xffc00, 0x00100005, 0x00000400, 0xfffff3ff]))
    return [a, t]


def w_alloc_tex(m, rng):
    a = spec_accel(m, rng, {'usableVramSize': [0x4000000, 0x8000000], 'vramSize': [0x4000000, 0x8000000, 0x10000000], 'displayConfigBits': [0, 1],
                            'vramPool': [('obj', 'ATIR500Memory', 0x40)]}, None)
    t = tex_buffer(m, rng, rng.choice([3, 7, 8, 5, 3]), 1)
    return [a, t]


def mock_alloc_tex(m, name, k):
    r = (m.seed * 3 + k) % 4
    if 'ATIR500Memory' in name and 'alloc' in name and 'dealloc' not in name:
        return 0 if r == 1 else 1
    if vs(name, 0x14c):
        if r == 2:
            return 0
        o = m.alloc(0x100); m.w32(o, m.vtable('IOATIR500Shared', 0x800)); return o
    if vs(name, 0xd0):
        h = m.alloc(0x100); m.w32(h + 0x20, rng_bits(m)); return h
    return default_mock(m, name, k)


def rng_bits(m):
    return [0x40000000, 0, 0x60000000, 0x40000001][(m.seed // 2) % 4]


def w_buffer_retired(overflow=False):
    def world(m, rng):
        wi = rng.choice([0, 5, 0x7f8, 0x400])
        window = m.mmio(0x1000, None)
        good = (wi + 0x100) & 0x7ff
        if overflow:
            seq = [(wi + 10) & 0x7ff]
        else:
            seq = rng.choice([[good], [(wi + 10) & 0x7ff, good], [(wi + 12) & 0x7ff] * 5 + [good]])
        a = spec_accel(m, rng, {'ringIndex': [wi], 'mainRingMemory': [('blk', 0x2000)], 'hwCapabilityBits': [0, 0x80, 0x80], 'vramSizeProgrammed': [0, 0x100000],
                                'retiredStampCounter': [5, 0x7fffffff], 'commandBytesPerSample': [0, 100], 0x84: [('u8', 32), ('u8', 128)]}, None)
        regs = SeqRegisters(rng, {0x100: seq, 0xe40: [0]})
        mm = m.mmio(0x20000, regs)
        m.w32(a + F('mmioBase'), mm)
        m.w32(a + F('ringPointerBase'), mm); m.w32(a + F('ringWritePointerOffset'), 0x100)
        return [a, m.alloc(0x400), rng.choice([0, 0x1000, 0x2000]), rng.choice([1, 8, 40, 0x100])]
    return world


def w_idct_consumed(overflow=False):
    def world(m, rng):
        wi = rng.choice([0, 5, 0x7f0, 0x400])
        good = (wi + 0x100) & 0x7ff
        seq = [(wi + 2) & 0x7ff] if overflow else rng.choice([[good], [(wi + 3) & 0x7ff, good], [(wi + 1) & 0x7ff] * 5 + [good]])
        a = spec_accel(m, rng, {'idctRingCursor': [wi], 'idctRingMemory': [('blk', 0x2000)], 'hwCapabilityBits': [0, 0x80, 0x80], 'vramSizeProgrammed': [0, 0x100000],
                                'xdctEngineRunning': [0, 1, 1, 1], 'transferMappedFlag': [0, 1], 'idctSubmitBaseCounter': [3, 9], 0x84: [('u8', 32), ('u8', 128)]}, None)
        mm = m.mmio(0x20000, SeqRegisters(rng, {0x200: seq, 0xe40: [0], 0x1720: [0x30000]}))
        m.w32(a + F('mmioBase'), mm)
        m.w32(a + F('idctPointerBase'), mm); m.w32(a + F('idctPointerOffset'), 0x200)
        info = m.alloc(0x100); rich_fill(m, info, 0, 0x100, rng, [1, 2, 3, 0x10, 0x20, 0x100, 0xffff])
        return [a, m.alloc(0x400), rng.choice([0, 0x1000]), info]
    return world


def scripted0(rng):
    return None


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# ATIRadeonX1000::start: a chain of ~40 fallible steps (pools, PCI maps, ring memory, descriptors, HZMEM, timers, the sensor provider). The mock lets each step
# succeed with high probability and fail now and then, so a run goes deep and every failure exit is taken by some seed.
from hand_cases_U4P import start_regs, w_start as _w_start_u4p

def _ok(m, name, k, p_fail=0.12):
    return ((m.seed * 2654435761 + k * 40503 + sum(map(ord, name))) % 1000) / 1000.0 >= p_fail


def mock_start_deep(m, name, k):
    if 'IOATIR500Accelerator' in name and name.endswith('start') or ('IOATIR500Accelerator' in name and 'start' in name and 'Command' not in name):
        return 1 if _ok(m, name, k, 0.05) else 0
    if 'ATIR500Memory' in name and 'init_pool' in name:
        return 1 if _ok(m, name, k, 0.08) else 0
    if 'safeMetaCast' in name:
        r3 = m.uc.reg_read(UC_PPC_REG_3)
        return r3 if (r3 and _ok(m, name, k, 0.08)) else 0
    if vs(name, 0x188) or vs(name, 0x138):        # getProperty / array getObject: an object (the array ends after two elements)
        if name.endswith('+0x138') and k > 6:
            return 0
        o = m.alloc(0x400); m.w32(o, m.vtable('IOATIR500Shared', 0x800)); return o
    if vs(name, 0x578):
        return 1 if _ok(m, name, k, 0.05) else 0
    if vs(name, 0x57c):
        if not _ok(m, name, k, 0.05): return 0
        o = m.alloc(0x400); m.w32(o, m.vtable('IOATIR500Shared', 0x800)); return o
    if vs(name, 0xd0):
        return m.regwin
    if 'IOMallocAligned' in name or 'operator new' in name or name.startswith('__ZN8OSObjectnw') or 'withAddress' in name or 'timerEventSource' in name:
        if not _ok(m, name, k, 0.08): return 0
        o = m.alloc(max(min(m.uc.reg_read(UC_PPC_REG_3), 0x4000), 0x400))
        m.w32(o, m.vtable('IOATIR500Shared', 0x800))
        return o
    if vs(name, 0x590):                       # the GART mapper reports how many pages the scratch buffer spans (+0x8cc) and whether it needs a second set (+0x8c8)
        this = m.uc.reg_read(UC_PPC_REG_3)
        m.w8(this + 0x8cc, [0, 2, 3, 1][(m.seed + k) % 4]); m.w32(this + 0x8c8, [0, 1, 0, 1][(m.seed // 3 + k) % 4])
        return 1 if _ok(m, name, k, 0.25) else 0
    if vs(name, 0x5a0) or vs(name, 0xe4) or vs(name, 0x150) or vs(name, 0x1d8):
        return 1 if _ok(m, name, k, 0.08) else 0
    if 'HZMEM_Init' in name:
        return 0 if _ok(m, name, k, 0.1) else 1
    if 'startupPCIeGART' in name:
        return 0xffffffff if not _ok(m, name, k, 0.08) else 0
    if 'allocCommandBuffer' in name or 'initialize_hardware' in name:
        return 1 if _ok(m, name, k, 0.08) else 0
    if 'getPeriodValue' in name:
        o = m.alloc(0x20); m.w32(o, 3); m.w32(o + 4, 5000000); return o if _ok(m, name, k, 0.2) else 0
    return start_mock_base(m, name, k)


from hand_cases_U4P import start_mock as start_mock_base


def w_start_deep(m, rng):
    this = _w_start_u4p(m, rng)[0]
    m.w32(this + F('displayCount'), rng.choice([0, 1, 2]))
    m.w32(this + F('vramApertureBase'), rng.choice([0, 0x1000]))
    m.w32(this + F('hwCapabilityBits'), rng.choice([0, 0x80, 0x80000, 0x80 | 0x80000]))
    m.w32(this + F('workLoop'), m.alloc(0x100)); m.w32(m.r32(this + F('workLoop')), m.vtable('IOATIR500Shared', 0x800))
    m.w32(this + F('gpuSensorProvider'), 0)
    m.w8(this + 0x84, rng.choice([32, 64, 128]))
    return [this, m.alloc(0x100)]


# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# the DMA-copy quad writer and pcl_CopyPix: the existing hand worlds (hand_cases_D.py) draw sizes from a short list; here the sizes, scales and flags come from wider
# ranges, so the strip-splitting (large or scaled copies) and the flip/format branches run as well.
from hand_cases_D import clean_word, accel as d_accel, fill_words as d_fill

def w_3dtexquad_wide(m, rng):
    A = d_accel(m, rng, mmio=False)
    m.w32(A + 0xb74, clean_word(rng))
    cmds = m.alloc(0x20000)
    pick = lambda *v: rng.choice(v)
    big = lambda: pick(0, 1, 2, 3, 7, 16, 31, 32, 33, 64, 100, 255, 256, 640, 1000, 2047, 2048, 2049, 4095, 4096, 4097, 5000, 8193)
    rect = lambda: pick(-16, -1, 0, 1, 3, 16, 33, 100, 640, 2047, 2048, 4000, 4096, 5000)
    addr = lambda: pick(0x1000000, 0x20000000, 0x30000020, 0x12345600, 0x40, 0x7fffffe0)
    w, h = big(), big()
    if rng.random() < 0.5:          # huge copies: the strip counters (bytes) can multiply out to 0 - the code's wrap-around corner
        w, h = rng.randrange(1, 65536), rng.randrange(1, 65536)
    return [A, cmds, pick(0, 2, 8, 20), rng.randrange(8), addr(), pick(64, 640, 2560, 5120), big() + 1, big() + 1, rng.randrange(8), rng.randrange(5), rng.randrange(4),
            pick(0, 1, 2), addr(), pick(64, 640, 2560), pick(64, 640, 1280, 4096, 8192), rng.randrange(8), rng.randrange(5), rng.randrange(4),
            rect() & 0xffffffff, rect() & 0xffffffff, rect() & 0xffffffff, rect() & 0xffffffff, w, h, pick(0, 1)]


from hand_cases_D import fbits


def w_pcl_wide(m, rng):
    out = m.alloc(0x4000)
    prm = m.alloc(0x100); d_fill(m, prm, 0x100, rng)
    for off in range(0, 0x2c, 4):
        m.w32(prm + off, clean_word(rng))
    for off in range(0x2c, 0x40):
        m.w8(prm + off, rng.randrange(48))
    win = m.alloc(0x20)
    for i in range(4):
        m.w16(win + 2 * i, rng.choice([0, 1, 2, 16, 100, 640, 1000, 2047, 2048, 4095, 4096, 0xfff0, 0xffff, rng.getrandbits(16)]))
    m.w32(prm + 0x50, win)
    big = lambda: rng.choice([0.0, 0.5, 1.0, 2.0, 3.0, 16.0, 640.0, 2047.0, 2048.0, 4000.0, 4096.0, 4097.0, 5000.0, 8192.0, 70000.0, 1e9, -1.0, -4096.0])
    pos = lambda: rng.choice([-5000.0, -5.0, -0.5, 0.0, 0.5, 1.0, 16.5, 100.0, 640.0, 700.25, 2048.0, 4096.0, 9000.0, 65536.0])
    m.w32(prm + 0x6c, fbits(big())); m.w32(prm + 0x70, fbits(big()))
    for off in (0x54, 0x58, 0x5c, 0x60):
        m.w32(prm + off, fbits(pos()))
    for off in range(0x40, 0x50, 4):
        m.w32(prm + off, rng.choice([0, 1, 0x100, rng.getrandbits(32)]))
    for off in (0x64, 0x68, 0x74, 0x78, 0x7c, 0x80, 0x84, 0x88):
        m.w32(prm + off, rng.choice([0, 1, 2, 0x3f800000, 0x40000000, 0xbf800000, fbits(pos()), rng.getrandbits(32)]) if off != 0x88 else rng.choice([0, 1]))
    return [out, prm, rng.choice([0, 1]), rng.choice([0, 1])]


CASES = [
    Case('ATIRadeonX1000::startupPCIeGART', w_gart, ret='s32', seeds=120, mock=mock_gart, plain_words=True, name='ATIRadeonX1000::startupPCIeGART [hand H2]'),
    Case('ATIRadeonX1000::pageoff_linear_buffer', w_linear, ret='u32', seeds=200, mock=mock_tex, plain_words=True, name='ATIRadeonX1000::pageoff_linear_buffer [hand H2]'),
    Case('ATIRadeonX1000::pageoff_dirty_texture_with_gpu', w_with_gpu, ret='u32', seeds=200, mock=mock_tex, plain_words=True, name='ATIRadeonX1000::pageoff_dirty_texture_with_gpu [hand H2]'),
    Case('ATIRadeonX1000::prepare_texture_for_pageoff_with_cpu', w_prepare_cpu, ret='u32', seeds=200, mock=mock_tex, plain_words=True, name='ATIRadeonX1000::prepare_texture_for_pageoff_with_cpu [hand H2]'),
    Case('ATIRadeonX1000::pageoff_dirty_texture', w_dirty, ret='void', seeds=200, mock=mock_tex, plain_words=True, name='ATIRadeonX1000::pageoff_dirty_texture [hand H2]'),
    Case('ATIRadeonX1000::system_will_change_speed', w_will, ret='void', seeds=200, mock=mock_pm, plain_words=True, name='ATIRadeonX1000::system_will_change_speed [hand H2]'),
    Case('ATIRadeonX1000::system_did_change_speed', w_did, ret='void', seeds=120, mock=mock_pm, plain_words=True, name='ATIRadeonX1000::system_did_change_speed [hand H2]'),
    Case('ATIRadeonX1000::enable_GPUSensor', w_sensor, ret='void', seeds=60, plain_words=True, name='ATIRadeonX1000::enable_GPUSensor [hand H2]'),
    Case('ATIRadeonX1000::disable_GPUSensor', w_sensor, ret='void', seeds=60, plain_words=True, name='ATIRadeonX1000::disable_GPUSensor [hand H2]'),
    Case('ATIRadeonX1000::getPeriodValue', w_period, ret='u32', seeds=60, mock=mock_period, plain_words=True, name='ATIRadeonX1000::getPeriodValue [hand H2]'),
    Case('ATIRadeonX1000::callPlatformFunction', w_platform, ret='u32', seeds=120, plain_words=True, name='ATIRadeonX1000::callPlatformFunction [hand H2]'),
    Case('ATIRadeonX1000::start_xdct_engine', w_xdct_start, ret='bool', seeds=100, limit=1500000, seconds=900, plain_words=True, name='ATIRadeonX1000::start_xdct_engine [hand H2]'),
    Case('ATIRadeonX1000::stop_xdct_engine', w_xdct_stop, ret='bool', seeds=100, limit=1500000, seconds=900, plain_words=True, name='ATIRadeonX1000::stop_xdct_engine [hand H2]'),
    Case('ATIRadeonX1000::submit_ring_data', w_ring, ret='void', seeds=150, plain_words=True, name='ATIRadeonX1000::submit_ring_data [hand H2]'),
    Case('ATIRadeonX1000::setupR520Pipes', w_pipes, ret='void', seeds=100, plain_words=True, name='ATIRadeonX1000::setupR520Pipes [hand H2]'),
    Case('ATIRadeonX1000::stop_promo4_engine', w_stop_promo4, ret='bool', seeds=100, limit=800000, plain_words=True, name='ATIRadeonX1000::stop_promo4_engine [hand H2]'),
    Case('ATIRadeonX1000::start_promo4_engine', w_start_promo4, ret='bool', seeds=100, limit=800000, plain_words=True, name='ATIRadeonX1000::start_promo4_engine [hand H2]'),
    Case('ATIRadeonX1000::start_promo4_engine', w_start_promo4_timeout, ret='bool', seeds=1, limit=60000000, seconds=1500, plain_words=True, name='ATIRadeonX1000::start_promo4_engine [hand H2 timeout]'),
    Case('ATIRadeonX1000::initialize_hardware', w_init_hw, ret='bool', seeds=120, mock=mock_init_hw, plain_words=True, name='ATIRadeonX1000::initialize_hardware [hand H2]'),
    Case('ATIRadeonX1000::DumpASICHangState', w_dump, ret='void', seeds=4, limit=8000000, seconds=1500, plain_words=True, name='ATIRadeonX1000::DumpASICHangState [hand H2]'),
    Case('ATIRadeonX1000::SWDSWriteBlitToCmdBuf', w_swds_blit, ret='u32', seeds=300, mock=mock_swds, plain_words=True, name='ATIRadeonX1000::SWDSWriteBlitToCmdBuf [hand H2]'),
    Case('ATIRadeonX1000::SWDSInit', w_swds_init, ret='bool', seeds=300, mock=mock_swds, plain_words=True, ignore_args={'vtable slot +0x12c': [2], 'vtable slot +0xec': [1, 2]}, name='ATIRadeonX1000::SWDSInit [hand H2]'),
    Case('ATIRadeonX1000::SWDSFunc', w_swds_func, ret='void', seeds=300, mock=mock_swds, plain_words=True, ignore_args={'vtable slot +0x12c': [2], 'vtable slot +0xec': [1, 2]}, name='ATIRadeonX1000::SWDSFunc [hand H2]'),
    Case('ATIRadeonX1000::SWDSEnableCLUT', w_swds_clut, ret='bool', seeds=100, mock=mock_swds, plain_words=True, name='ATIRadeonX1000::SWDSEnableCLUT [hand H2]'),
    Case('ATIRadeonX1000::waitForTimeStampNoLock', stamp_world(True), ret='u32', seeds=120, mock=mock_stamp, limit=400000, out_extents=CLOCK_EXTENTS, plain_words=True, name='ATIRadeonX1000::waitForTimeStampNoLock [hand H2]'),
    Case('ATIRadeonX1000::sleepForTimeStampNoLock', stamp_world(True), ret='u32', seeds=120, mock=mock_stamp, limit=400000, out_extents=CLOCK_EXTENTS, plain_words=True, name='ATIRadeonX1000::sleepForTimeStampNoLock [hand H2]'),
    Case('ATIRadeonX1000::waitForTimeStampNoLock', stamp_world(False), ret='u32', seeds=2, mock=mock_stamp, limit=8000000, seconds=1500, out_extents=CLOCK_EXTENTS, plain_words=True, name='ATIRadeonX1000::waitForTimeStampNoLock [hand H2 never retires]'),
    Case('ATIRadeonX1000::sleepForTimeStampNoLock', stamp_world(False), ret='u32', seeds=2, mock=mock_stamp, limit=8000000, seconds=1500, out_extents=CLOCK_EXTENTS, plain_words=True, name='ATIRadeonX1000::sleepForTimeStampNoLock [hand H2 never retires]'),
    Case('ATIRadeonX1000::reserveInGART', w_reserve_gart, ret='bool', seeds=100, mock=mock_gart_entry, plain_words=True, name='ATIRadeonX1000::reserveInGART [hand H2]'),
    Case('ATIRadeonX1000::deallocate_texture', w_dealloc_tex, ret='void', seeds=200, plain_words=True, name='ATIRadeonX1000::deallocate_texture [hand H2]'),
    Case('ATIRadeonX1000::allocate_texture', w_alloc_tex, ret='u32', seeds=200, mock=mock_alloc_tex, plain_words=True, name='ATIRadeonX1000::allocate_texture [hand H2]'),
    Case('ATIRadeonX1000::submit_buffer_retired', w_buffer_retired(False), ret='u32', seeds=150, plain_words=True, name='ATIRadeonX1000::submit_buffer_retired [hand H2]'),
    Case('ATIRadeonX1000::submit_buffer_retired', w_buffer_retired(True), ret='u32', seeds=1, limit=200000000, seconds=1700, plain_words=True, ignore_args={'IOLog': [4, 5, 6, 7, 8]}, name='ATIRadeonX1000::submit_buffer_retired [hand H2 fifo overflow]'),
    Case('ATIRadeonX1000::submit_idct_buffer_consumed', w_idct_consumed(False), ret='u32', seeds=150, plain_words=True, name='ATIRadeonX1000::submit_idct_buffer_consumed [hand H2]'),
    Case('ATIRadeonX1000::submit_idct_buffer_consumed', w_idct_consumed(True), ret='u32', seeds=1, limit=200000000, seconds=1700, plain_words=True, name='ATIRadeonX1000::submit_idct_buffer_consumed [hand H2 fifo overflow]'),
    Case('ATIRadeonX1000::start', w_start_deep, ret='bool', seeds=300, mock=mock_start_deep, limit=300000, ignore_args={'IOLog': [2, 3, 4, 5, 6, 7, 8], 'vtable slot +0x164': [1, 2], 'vtable slot +0x16c': [1], 'vtable slot +0x170': [1], 'vtable slot +0x188': [1], 'getPeriodValue': [1]}, name='ATIRadeonX1000::start [hand H2]'),
    Case('__Z46write_3dtexquad_cmds_for_copy_buffer_using_DMAP14ATIRadeonX1000Pmmmmmmmmmhmmmmmmhllllmmb', w_3dtexquad_wide, ret='u32', seeds=600, mock=new_mock, plain_words=True, limit=400000, seconds=900, name='write_3dtexquad_cmds_for_copy_buffer_using_DMA [hand H2]'),
    Case('__Z11pcl_CopyPixPmP16pcl_ParamsR500_tbb', w_pcl_wide, ret='u32', seeds=800, mock=new_mock, plain_words=True, name='pcl_CopyPix [hand H2]'),
]
