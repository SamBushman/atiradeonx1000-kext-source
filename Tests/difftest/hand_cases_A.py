"""Hand-written worlds (fork A of #183): ATIRadeonX1000 (GART, factories, submit, stop, texture paging), IOATIR500Shared and ATIR500Memory.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_A.py   (needs STOCK_KEXT; see Tools/difftest/README.md)

Common idea: every pointer a function reaches is a real object (right vtable, so virtual calls are recorded by method name), every list ends and every
table index is in range - the generic 'pointer soup' world gets none of that right for code that walks object graphs."""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from common import word, fill_words, object_with_vtable, accelerator_with_registers, R500Registers, FlipFlopRegisters


def new_mock(m, name, k):
    """OSObject::operator new returns a real (zeroed) block of the requested size - or null on every third seed (the allocation failed) - everything
    else the harness default"""
    if 'operator new' in name or 'nwEm' in name:
        from unicorn.ppc_const import UC_PPC_REG_3
        if m.seed % 3 == 2:
            return 0
        return m.alloc(max(m.uc.reg_read(UC_PPC_REG_3), 0x10))
    return default_mock(m, name, k)


def obj(m, rng, cls, size=0x400):
    return object_with_vtable(m, rng, cls, size)


def accel(m, rng, mmio=True):
    """an accelerator: vtable, hardware flag, command lock, optional register window"""
    a = accelerator_with_registers(m, rng) if mmio else obj(m, rng, 'ATIRadeonX1000', 0x1000)
    m.w32(a, m.vtable('ATIRadeonX1000'))
    m.w32(a + 0xcc, rng.choice([0, 1, 2]))
    m.w32(a + 0x840, a + 0x900)
    return a


def accel_r500(m, rng):
    """an accelerator whose register window is the register file of an idle R5xx (or, on some seeds, a flip-flop device), hardware flag set"""
    a = accel(m, rng, mmio=False)
    m.w8(a + 0x80, rng.choice([1, 1, 1, 0]))
    m.w32(a + 0x860, m.mmio(0x20000, rng.choice([R500Registers, FlipFlopRegisters])(rng)))
    return a


def w_gpu_sensor(m, rng):
    """GPUSensorFunc(this, timer): +0x90c/+0x910 locate a word in plain memory that must equal +0x914; +0x9a8 is a timer event source (slot 300 re-arms)"""
    a = accel_r500(m, rng)
    base = m.alloc(0x100); fill_words(m, base, 0x100, rng)
    m.w32(a + 0x90c, base); m.w32(a + 0x910, 4 * rng.randrange(0, 8))
    word_at = struct.unpack('<I', m.uc.mem_read(base + struct.unpack('>I', m.uc.mem_read(a + 0x910, 4))[0], 4))[0]    # what lwbrx will read
    m.w32(a + 0x914, rng.choice([word_at, word_at, word_at, word(rng)]))
    timer = obj(m, rng, 'ATIRadeonX1000', 0x100)           # any object with a vtable: slot 300 is recorded by offset
    m.w32(timer, m.vtable('IOATIR500Shared', 0x800))
    m.w32(a + 0x9a8, timer); m.w32(a + 0x998, rng.choice([1, 100, 1000]))
    return [a, 0]


def w_factory(m, rng):
    return [accel(m, rng, mmio=False)]


def plain(m, rng, size=0x400, vt_size=0x800):
    """an object of a class this kext does not define (IOKit/libkern): word soup, and a vtable whose slots are named by offset"""
    o = m.alloc(size)
    fill_words(m, o, size, rng)
    m.w32(o, m.vtable('IOATIR500Shared', vt_size))
    return o


PAGE = 0x1000


def gart_accel(m, rng, entries=0x400, shadow=None):
    """an accelerator with a register window and a PCIe GART: the table (+0xc4c, `entries` 4-byte entries), an optional shadow copy (+3000), the
    'unmapped entry' value (+0x844), the table size in bytes (+0x830) and the OR-ed-in flags word (+0xbc0)"""
    a = accel(m, rng)
    tbl = m.alloc(4 * entries + 0x10); fill_words(m, tbl, 4 * entries, rng)
    m.w32(a + 0xc4c, tbl)
    if shadow is None:
        shadow = rng.choice([0, 1])
    m.w32(a + 3000, m.alloc(4 * entries + 0x10) if shadow else 0)
    m.w32(a + 0x844, rng.choice([0, 0x0badf00d, 0x1000, 0xdead0000]))
    m.w32(a + 0x830, 4 * entries)
    m.w32(a + 0xbc0, rng.choice([0, 0xa0000000, 0x1]))
    m.w32(a + 0xa0, rng.choice([0, 0x100000, 0x7fffffff]))
    return a, tbl


def w_clear_in_gart(m, rng):
    a, tbl = gart_accel(m, rng)
    return [a, PAGE * rng.randrange(0, 0x400) + rng.choice([0, 0, 0x234])]


def sized_mock(m, name, k):
    """a memory descriptor's length (vtable slot 0x128) is a few pages; segments (0x13c) end after a few; everything else the harness default"""
    if '0x128' in name:
        return PAGE * (1 + (m.seed + k) % 5)
    return default_mock(m, name, k)


def descriptor_mock(m, name, k):
    """an IOMemoryDescriptor of 1-6 pages (by seed): length (slot 0x128), prepare (0x144, fails on every 7th seed), physical segments (0x13c: the
    segment at `offset` is 1-3 pages, none past the end); everything else the harness default"""
    from unicorn.ppc_const import UC_PPC_REG_4, UC_PPC_REG_5
    total = PAGE * (1 + m.seed % 6)
    if '0x128' in name:
        return total
    if '0x144' in name:
        return 0xe00002bc if m.seed % 7 == 6 else 0
    if '0x13c' in name:
        off = m.uc.reg_read(UC_PPC_REG_4); lenp = m.uc.reg_read(UC_PPC_REG_5)
        if off >= total:
            return 0
        n = min(total - off, PAGE * (1 + (off // PAGE) % 3))
        m.w32(lenp, n)
        return 0x20000000 + off
    return default_mock(m, name, k)


def w_add_to_gart(m, rng):
    a, tbl = gart_accel(m, rng, entries=0x40)
    inv = struct.unpack('>I', m.uc.mem_read(a + 0x844, 4))[0]
    swapped = struct.pack('<I', inv)
    # the free-run search compares each entry (read byte-reversed) with the 'unmapped' value: mostly unmapped, sometimes a few mapped entries
    for i in range(0x40):
        if rng.random() < 0.85:
            m.uc.mem_write(tbl + 4 * i, swapped)
    md = plain(m, rng)
    out = m.alloc(0x10)
    return [a, rng.choice([0, md, md, md, md]), rng.choice([0, out, out, out, out]), 0, 0]


def w_remove_from_gart(m, rng):
    a, tbl = gart_accel(m, rng)
    md = plain(m, rng)
    return [a, rng.choice([0, md, md, md]), PAGE * rng.randrange(0, 0x300)]


CASES = [
    Case('ATIRadeonX1000::new_surface', w_factory, ret='u32', seeds=10, mock=new_mock),
    Case('ATIRadeonX1000::new_2d_context', w_factory, ret='u32', seeds=10, mock=new_mock),
    Case('ATIRadeonX1000::new_gl_context', w_factory, ret='u32', seeds=10, mock=new_mock),
    Case('ATIRadeonX1000::new_dvd_context', w_factory, ret='u32', seeds=10, mock=new_mock),
]

CASES += [
    Case('ATIRadeonX1000::clearInGART', w_clear_in_gart, ret='void', seeds=20),
    Case('ATIRadeonX1000::removeFromPCIeGART', w_remove_from_gart, ret='void', seeds=20, mock=sized_mock),
    Case('ATIRadeonX1000::addToPCIeGART', w_add_to_gart, ret='u32', seeds=30, mock=descriptor_mock, ignore_args={'+0x144': [2]}),
]

CASES += [
    Case('ATIRadeonX1000::GPUSensorFunc', w_gpu_sensor, ret='void', seeds=30),
]


def w_submit_buffer(m, rng):
    """submit_buffer(this, commands, bus address, dword count): the ring (+0x900, 2048 dwords) has its write index at +0x914 and the hardware read
    index in a plain word at +0x90c+0x910; free space is judged from the two, so the read index is placed to give plenty of room, none, or just enough"""
    a = accel_r500(m, rng)
    ring = m.alloc(0x2000 + 0x20); fill_words(m, ring, 0x2000, rng); m.w32(a + 0x900, ring)
    base = m.alloc(0x40); m.w32(a + 0x90c, base); m.w32(a + 0x910, 4 * rng.randrange(0, 4))
    wptr = rng.randrange(0, 0x800); m.w32(a + 0x914, wptr)
    rptr = (wptr + rng.choice([1, 6, 8, 12, 100, 0x400, 0x7f0])) & 0x7ff        # distance wptr -> rptr; small values leave no room
    m.uc.mem_write(base + struct.unpack('>I', m.uc.mem_read(a + 0x910, 4))[0], struct.pack('<I', rptr))
    m.w32(a + 0x50, rng.randrange(0, 1000)); m.w32(a + 0x6fc, rng.randrange(0, 1000))
    m.w32(a + 0x84 - (0x84 & 3), 0)
    m.w8(a + 0x84, rng.choice([32, 32, 128])); m.w32(a + 0x98, rng.choice([0, 0x80, 0x80]))
    m.w32(a + 0x8a0, rng.choice([0, 1])); m.w32(a + 0x8a4, rng.choice([0, 0x20, 0x1000]))
    m.w32(a + 0x8d0, rng.choice([0, 0, obj(m, rng, 'ATIRadeonX1000', 0x100)]))
    cmds = m.alloc(0x400); fill_words(m, cmds, 0x400, rng)
    return [a, cmds, 0x30000000 + 4 * rng.randrange(0, 0x1000), rng.choice([0, 1, 5, 8, 11, 16, 0x20, 0x31])]


CASES += [
    Case('ATIRadeonX1000::submit_buffer', w_submit_buffer, ret='u32', seeds=40, ignore_args={'IOLog': [4, 5]}),
]


def texture_list(m, rng, a, sentinel_off, n):
    """a circular doubly linked list (next at +0x28, previous at +0x24) of n texture records closed by the sentinel at accelerator+sentinel_off; each
    record has a header (+0x14) of up to four 16-bit mask pairs (+0x1c/+0x28, count at +0x34)"""
    sent = a + sentinel_off
    nodes = []
    for _ in range(n):
        r = m.alloc(0x100); fill_words(m, r, 0x100, rng)
        nodes.append(r)
        if rng.random() < 0.15:
            m.w32(r + 0x14, 0)
        else:
            h = m.alloc(0x80); fill_words(m, h, 0x80, rng); m.w32(r + 0x14, h)
            c = rng.randrange(0, 5); m.w8(h + 0x34, c)
            for i in range(4):
                mask = rng.getrandbits(16)
                m.w16(h + 0x1c + 2 * i, mask)
                m.w16(h + 0x28 + 2 * i, mask & rng.getrandbits(16))     # a header whose entries do NOT fit makes the shipped loop spin on the same record forever (identical in both builds): not tested
        m.w32(r + 0x48, rng.choice([0, 0x800, 0x1000, 0x2000, 0xffff0000]))
    ring = [sent] + nodes
    for i, node in enumerate(ring):
        m.w32(node + 0x28, ring[(i + 1) % len(ring)])
        m.w32(node + 0x24, ring[i - 1])
    return nodes


def alloc_ok_mock(m, name, k):
    """ATIR500Memory::alloc succeeds on the first call and fails on others only while another record is left to try: a failure on the last record makes
    the shipped loop spin on the record it has just unlinked (it points at itself), which is the stock behaviour and no test"""
    if 'ATIR500Memory5alloc' in name or 'ATIR500Memory::alloc' in name:
        return 1 if k >= 1 or m.seed % 2 else 0
    return default_mock(m, name, k)


def w_free_to_alloc_texture(m, rng):
    a = accel(m, rng)
    memory = obj(m, rng, 'ATIRadeonX1000', 0x100); m.w32(a + 0x7c, memory)
    m.w32(a + 0x84c, rng.choice([0x1000, 0x1800]))
    m.w32(a + 0x50, rng.randrange(1, 100)); m.w32(a + 0x7e0, rng.randrange(0, 50))
    texture_list(m, rng, a, 0x5dc, rng.randrange(0, 5))
    # the texture whose backing is being allocated: its memory element is embedded at +0x40
    tex = m.alloc(0x100); fill_words(m, tex, 0x100, rng)
    return [a, tex, PAGE * rng.randrange(1, 64)]


CASES += [
    Case('ATIRadeonX1000::freeToAllocTextureCPUVisibleVRAM', w_free_to_alloc_texture, ret='u32', seeds=40, mock=alloc_ok_mock),
]


def w_stop(m, rng):
    """ATIRadeonX1000::stop(provider): the teardown of everything start() built. A fresh zeroed accelerator with a vtable and a register window; each
    resource is present or absent at random, every present one is a real object (event sources, the work loop, the memory pool, ring/DMA buffers)"""
    a = m.alloc(0x1000)
    m.w32(a, m.vtable('ATIRadeonX1000'))
    m.w32(a + 0x860, m.mmio(0x20000, rng.choice([R500Registers, FlipFlopRegisters])(rng)))
    some = lambda: rng.choice([0, 1])
    m.w32(a + 0x74, plain(m, rng)); m.w32(a + 0xb4, plain(m, rng)); m.w32(a + 0x7c, plain(m, rng, 0x100))
    m.w32(a + 0x50, rng.randrange(1, 100))
    for off in (0x9a8, 0x9b8, 0x9ac, 0x934, 0x93c):
        m.w32(a + off, plain(m, rng) if some() else 0)
    for i in range(2):                                  # two 0x78-byte memory elements at +0x9bc and two at +0x12c: (pointer, size) words
        m.w32(a + 0x9bc + 0x78 * i, some()); m.w32(a + 0x9c0 + 0x78 * i, some())
        m.w32(a + 0x12c + 0x78 * i, some()); m.w32(a + 0x130 + 0x78 * i, some())
    for off in (0xae8, 0x8e0, 0x8dc, 0x8f0, 0x8ec, 0x8bc, 0xac):
        m.w32(a + off, some())
    for off in (0xb10, 0xb28):                          # saved-register pairs restored into the hardware
        m.w32(a + off, some()); m.w32(a + off - 8, word(rng)); m.w32(a + off - 4, word(rng))
    if some():                                          # the cursor/scratch DMA block
        m.w32(a + 0x8d0, 0x20000000 + PAGE); m.w32(a + 0x8d8, plain(m, rng)); m.w32(a + 0x8d4, word(rng))
    if some():                                          # the ring buffer
        m.w32(a + 0x900, 0x30000000); m.w32(a + 0xba0, PAGE * rng.randrange(0, 4)); m.w32(a + 0x904, PAGE * rng.randrange(0, 8)); m.w32(a + 0x908, plain(m, rng))
    if some():
        m.w32(a + 0x91c, 0x31000000); m.w32(a + 0x920, PAGE * rng.randrange(0, 8)); m.w32(a + 0x924, plain(m, rng))
    if some():
        m.w32(a + 0x938, 1); m.w32(a + 0x8c8, some()); m.w8(a + 0x8cc, rng.randrange(0, 5)); m.w32(a + 0x228, word(rng)); m.w32(a + 0x22c, plain(m, rng))
    m.w32(a + 3000, some()); m.w32(a + 0xc4c, 0x32000000 if some() else 0); m.w32(a + 0x830, 4 * 0x400)
    if some():
        m.w32(a + 0x8b8, 0x33000000)
    return [a, plain(m, rng)]


CASES += [
    # the removeProperty("ATIFEDSInfo") call goes through an unnamed vtable slot, so the harness compares its string argument as a raw address (the two builds put
    # the literal at different places): that one argument is ignored here; the literal's text is the same in both builds (checked in the source / disassembly)
    Case('ATIRadeonX1000::stop', w_stop, ret='void', seeds=40, ignore_args={'+0x17c': [1]}),
]


def w_total_free(m, rng):
    """ATIR500Memory::total_free(): the pool is a list of blocks (+8 -> a header whose first word is the first block); each block is {next, ?, offset,
    flags}, the list ends with next == 0; a block with a negative flags word (+0xc) is free and counts the distance to the next block's offset"""
    this = obj(m, rng, 'ATIR500Memory', 0x40)
    n = rng.randrange(1, 8)
    blocks = [m.alloc(0x20) for _ in range(n)]
    off = 0
    for i, b in enumerate(blocks):
        m.w32(b, blocks[i + 1] if i + 1 < n else 0)
        m.w32(b + 8, off); off += PAGE * rng.randrange(1, 9)
        m.w32(b + 0xc, rng.choice([0, 1, 0x80000000, 0xffffffff, 0x80000001]))
    head = m.alloc(0x10); m.w32(head, blocks[0])
    holder = m.alloc(0x10); m.w32(holder, head)
    m.w32(this + 8, holder)
    return [this]


CASES += [
    Case('ATIR500Memory::total_free', w_total_free, ret='s32', seeds=30),
]


def texture_record(m, rng, owner=None):
    """a texture record in a circular list of its own (+0x24 previous / +0x28 next point at neighbours or itself), with a header (+0x14), a backing object
    (+8), an owner (+0x1c) and a type byte (+0x20)"""
    r = m.alloc(0x100); fill_words(m, r, 0x100, rng)
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng)
    m.w32(r + 0x14, hdr)
    m.w32(r + 4, rng.choice([0, 1]))
    m.w32(r + 8, plain(m, rng) if rng.random() < 0.7 else 0)
    m.w8(r + 0x20, rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8]))
    m.w32(r + 0x1c, owner if (owner and rng.random() < 0.7) else 0)
    return r


def w_free_texvert(m, rng):
    a = accel(m, rng, mmio=False)
    shared = obj(m, rng, 'IOATIR500Shared', 0x100)
    rec = texture_record(m, rng, shared)
    a_prev = m.alloc(0x100); a_next = m.alloc(0x100)
    m.w32(rec + 0x24, a_prev); m.w32(rec + 0x28, a_next)       # unlinked from between the two neighbours
    m.w32(a_prev + 0x28, rec); m.w32(a_next + 0x24, rec)
    return [a, rec]            # a static member: (accelerator, record)


CASES += [
    Case('IOATIR500Shared::free_texvert', w_free_texvert, ret='void', seeds=40),
]


def delete_pops_mock(m, name, k):
    """delete_texture(record) removes the record from the shared object's list (head pointer at +0x24, next link at record+0x3c): a mock that does nothing
    would leave `while (list head) delete(head)` spinning, so this one pops the head when it is the record deleted"""
    if 'delete_texture' in name:
        from unicorn.ppc_const import UC_PPC_REG_3, UC_PPC_REG_4
        this, rec = m.uc.reg_read(UC_PPC_REG_3), m.uc.reg_read(UC_PPC_REG_4)
        if m.r32(this + 0x24) == rec:
            m.w32(this + 0x24, m.r32(rec + 0x3c))
        return 0
    return default_mock(m, name, k)


def w_shared_free(m, rng):
    """IOATIR500Shared::free(): every texture record still on the list (+0x24, linked by +0x3c; type byte at +0x20, header at +0x14) is deleted, the
    accelerator (+0xc) forgets this object (+0x6c/+0x70) and frees orphans, the client-shared nodes (+0x20, 0x1c bytes: next + three objects) are
    released and the accelerator's byte counter (+0x808) reduced"""
    this = obj(m, rng, 'IOATIR500Shared', 0x100)
    a = accel(m, rng, mmio=False)
    m.w32(this + 0xc, rng.choice([a, a, a]))
    m.w32(a + 0x6c, rng.choice([this, 0, word(rng)])); m.w32(a + 0x70, word(rng)); m.w32(a + 0x808, rng.randrange(0, 1000))
    recs = []
    for _ in range(rng.randrange(0, 6)):
        r = m.alloc(0x80); fill_words(m, r, 0x80, rng)
        h = m.alloc(0x40); fill_words(m, h, 0x40, rng); m.w32(r + 0x14, h)
        m.w8(r + 0x20, rng.choice([0, 1, 2, 3, 4, 4, 5]))
        recs.append(r)
    for i, r in enumerate(recs):
        m.w32(r + 0x3c, recs[i + 1] if i + 1 < len(recs) else 0)
    m.w32(this + 0x24, recs[0] if recs else 0)
    nodes = [m.alloc(0x20) for _ in range(rng.randrange(0, 4))]
    for i, nd in enumerate(nodes):
        m.w32(nd, nodes[i + 1] if i + 1 < len(nodes) else 0)
        for off in (4, 8, 0xc):
            m.w32(nd + off, plain(m, rng))
    m.w32(this + 0x20, nodes[0] if nodes else 0)
    return [this]


CASES += [
    Case('IOATIR500Shared::free', w_shared_free, ret='void', seeds=40, mock=delete_pops_mock, signature='::free()'),
]


def w_pageoff_cpu(m, rng):
    """pageoff_dirty_texture_with_cpu(this, texture, header): copies each mip level of a texture header (ATITextureBufferHeader: up to 3 levels of up
    to 13 sub-entries of 0x20 bytes from +0x42, each {count, source offset, destination offset, stride, ...}) into VRAM through three DMA-window
    registers it saves and restores. Sizes are kept small so the copy loops end inside the budget; a texture of type 7 (backed by a kernel memory
    descriptor, two more virtual calls through unnamed slots) is not exercised"""
    a = accel_r500(m, rng)
    m.w8(a + 0x990, rng.choice([0, 1, 2, 4])); m.w32(a + 0x890, rng.getrandbits(8))
    m.w32(a + 0x50, rng.randrange(1, 100)); m.w32(a + 0xe4, 0x40000000 + 0x1000 * rng.randrange(0, 8))   # the VRAM aperture base: far above the kext image, so copy addresses are not mistaken for pointers into it; m.w32(a + 0x720, rng.randrange(0, 100))
    m.w32(a + 0x98, rng.choice([0, 0x80])); m.w8(a + 0x84, rng.choice([32, 128]))
    tex = m.alloc(0x100); fill_words(m, tex, 0x100, rng)
    hdr = m.alloc(0x60); fill_words(m, hdr, 0x60, rng); m.w32(tex + 0x14, hdr)
    levels = rng.randrange(0, 3); first = rng.randrange(0, 3)
    m.w8(hdr + 0x34, levels); m.w8(hdr + 0x17, first); m.w8(hdr + 0x35, rng.randrange(1, 4)); m.w8(hdr + 0x15, rng.getrandbits(8))
    m.w8(tex + 0x20, rng.choice([0, 1, 2, 6])); m.w32(tex + 0x48, 0x100 * rng.randrange(0, 8))
    ph = m.alloc(0x42 + 0x20 * 0xd * 3 + 0x200); fill_words(m, ph, 0x42 + 0x20 * 0xd * 3 + 0x200, rng)
    for off, lo, hi in ((0x14, 1, 16), (0x16, 1, 16), (0x18, 1, 16)):
        m.w16(ph + off, rng.randrange(lo, hi))
    m.w32(ph + 0xc, rng.choice([8, 16, 64, 256])); m.w32(ph + 0x10, rng.choice([8, 16, 32, 64])); m.w8(ph + 0x1a, rng.randrange(0, 5)); m.w8(ph + 0x1b, rng.getrandbits(8))
    for lv in range(3):
        for n in range(0xd):
            e = ph + 0x42 + (lv * 0xd + n) * 0x20
            m.w16(e, rng.choice([0, 1, 1, 2, 3]))
            m.w32(e + 2, 0x20 * rng.randrange(1, 16)); m.w32(e + 6, 0x40 * rng.randrange(0, 8))
            m.w32(e + 10, 0x10 * rng.randrange(0, 4)); m.w32(e + 14, 0x40 * rng.randrange(0, 4))
    return [a, tex, ph]


CASES += [
    Case('ATIRadeonX1000::pageoff_dirty_texture_with_cpu', w_pageoff_cpu, ret='void', seeds=40,
         plain_words=True)    # the words stored are register values (VRAM offsets), not pointers: a value like 0x50000 would be 'named' as a pointer into one build's image only,
]
