"""Hand-written worlds (fork C of #183): the GL contexts (IOATIR500GLContext / ATIR500GLContext). The generic "pointer soup" world (all_classes_cases.py)
does not finish for these because the functions wait on flags the soup leaves clear, walk lists that must end, or index tables with a random word.
Here the objects a function works on are laid out by hand from the stock disassembly (field offsets in each builder's docstring).

Run: python3 Tools/difftest/difftest.py [--rebuilt build/difftest/rebuilt_C.bin] [-f NAME] Tests/difftest/hand_cases_C.py"""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from unicorn.ppc_const import UC_PPC_REG_4
from common import word, fill_words, make_pool, accelerator_object, soup_words, object_with_vtable, R500Registers


def gl_context(m, rng, cls='ATIR500GLContext', alive=True):
    """a GL context `this` (size 0x690) over a pointer-soup pool, with the fields the IOATIR500GLContext methods rely on pinned:
    +0xc8 the accelerator (vtable 'ATIRadeonX1000', +0x80 'hardware alive' flag, +0x840 its lock, data-buffer free list head +0x5cc / tail +0x5d0 / count +0x5d4),
    +0x290 the bound surface, +0x88 the shared texture table (+0x10 array of VendorTextureBuffer*, +0x14 count), +0x8c the bound-panel mask.
    returns (this, pool, accel)"""
    pool = make_pool(m, rng)
    accel = accelerator_object(m, rng, pool)
    m.w8(accel + 0x80, 1 if alive else rng.choice([0, 1]))
    this = m.alloc(0x1000)
    m.uc.mem_write(this, soup_words(rng, 0x690 // 4, pool))
    m.w32(this, m.vtable(cls))
    m.w32(this + 0xc8, accel)
    return this, pool, accel


def chain(m, rng, n, link, size=0x100, fill=True, cls=None):
    """n objects linked through the word at `link`, returns (head, [objs])"""
    objs = [m.alloc(size) for _ in range(n)]
    for i, o in enumerate(objs):
        if fill: fill_words(m, o, size, rng)
        m.w32(o + link, objs[i + 1] if i + 1 < n else 0)
        if cls: m.w32(o, m.vtable(cls))
    return (objs[0] if objs else 0), objs


CASES = []


def scripted_mock(machine, name, k):
    """a mocked callee returns, in order, the values the world queued for it on the machine (`machine.script[<substring of the callee name>]`); anything
    not queued (or once the queue is empty) falls back to the default seeded mock"""
    for key, q in getattr(machine, 'script', {}).items():
        if key in name:
            n = machine.script_n.setdefault(key, 0); machine.script_n[key] = n + 1
            if n < len(q): return q[n](machine) if callable(q[n]) else q[n]
    return default_mock(machine, name, k)


def script(m, key, values):
    if not hasattr(m, 'script'): m.script, m.script_n = {}, {}
    m.script[key] = list(values)


def surface_obj(m, rng, pool):
    s = m.alloc(0x1000)
    m.uc.mem_write(s, soup_words(rng, 0x1000 // 4, pool))
    m.w32(s + 0xa4, rng.choice([0, 1, 0x100, 0x1ff, 0x200, 0xffff]))
    m.w32(s + 0xbf8, rng.choice([0, 0x20000000, 0x20000001, 0x1, rng.getrandbits(32)]))
    return s


def w_wait_for_stamp(m, rng):
    this, pool, accel = gl_context(m, rng)
    return [this, rng.choice([0, 1, 0x7fffffff, 0xffffffff, word(rng)])]


def w_finish(m, rng):
    this, pool, accel = gl_context(m, rng)
    return [this]


def w_get_status(m, rng):
    this, pool, accel = gl_context(m, rng)
    m.w32(this + 0x290, rng.choice([0, 0, surface_obj(m, rng, pool)]))
    m.w32(this + 0x8c, rng.choice([0, 1, 2, 0x7fffff, 0x400000, 0x5, word(rng) & 0x7fffff]))
    return [this, m.alloc(0x10)]


def w_get_config(m, rng):
    this, pool, accel = gl_context(m, rng)
    m.w32(this + 0x290, rng.choice([0, 0, surface_obj(m, rng, pool)]))
    m.w32(this + 0x8c, rng.choice([0, 1, 2, 0x7fffff, 0x400000, 0x5, word(rng) & 0x7fffff]))
    return [this, m.alloc(0x10), m.alloc(0x10), m.alloc(0x10)]


def texture_obj(m, rng, pool, kind=None):
    """a VendorTextureBuffer: +0x14 header (+0x14 flag byte, +0x28..+0x32 u16s), +0x24/+0x28 ring links (a ring of itself), +0x48 backing, +0x20 kind"""
    t = m.alloc(0x100); m.uc.mem_write(t, soup_words(rng, 0x40, pool))
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
    ring = m.alloc(0x40); fill_words(m, ring, 0x40, rng)
    m.w32(t + 0x24, ring); m.w32(t + 0x28, ring)
    m.w32(ring + 0x24, t); m.w32(ring + 0x28, t)
    m.w32(t + 0x48, rng.choice([0, 0, 1, 0x1000]))
    return t


def w_purge_texture(m, rng):
    this, pool, accel = gl_context(m, rng)
    tab = m.alloc(0x40)                         # the shared texture table: +0x10 -> array of texture pointers, +0x14 -> count
    arr = m.alloc(0x40); n = rng.choice([1, 2, 4])
    for i in range(n):
        m.w32(arr + 4 * i, rng.choice([0, texture_obj(m, rng, pool)]))
    m.w32(tab + 0x10, arr); m.w32(tab + 0x14, n)
    m.w32(this + 0x88, tab)
    return [this, rng.choice([0, 1, 2, 3, n, n + 1, word(rng)])]


def vobj(m, rng, vt, size=0x100):
    """a kernel-side object (memory descriptor / map): its first word is a vtable of named stubs so virtual calls on it are recorded, not run"""
    o = m.alloc(size); fill_words(m, o, size, rng); m.w32(o, vt)
    return o


def data_buffer(m, rng, vt, nxt=0, ring=True):
    """a VendorTextureBuffer used as a DATA buffer: +0x3c next in its list, +0x54 in-use byte, +0x10 / +8 memory objects (or none), +0x4 flag, +0x48 gart offset,
    +0x50 size, +0x5c stamp, +0x24/+0x28 ring links (a ring of itself)"""
    b = m.alloc(0x100); fill_words(m, b, 0x100, rng)
    m.w32(b + 0x3c, nxt)
    m.w8(b + 0x54, rng.choice([0, 1]))
    m.w32(b + 0x10, rng.choice([0, vobj(m, rng, vt)]))
    m.w32(b + 8, rng.choice([0, vobj(m, rng, vt)]))
    m.w32(b + 4, rng.choice([0, 1]))
    m.w32(b + 0x48, rng.choice([0, 0, 0x1000]))
    m.w32(b + 0x50, rng.choice([0, 0x10000, 0x20000, 0x4000, 0x80000]))
    m.w32(b + 0x24, b); m.w32(b + 0x28, b)
    return b


def blist(m, rng, vt, n):
    """n data buffers linked through +0x3c; returns (head, tail)"""
    head = tail = 0
    for _ in range(n):
        b = data_buffer(m, rng, vt, 0)
        if tail: m.w32(tail + 0x3c, b)
        else: head = b
        tail = b
    return head, tail


def w_reclaim_resources(m, rng):
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    h, t = blist(m, rng, vt, rng.choice([0, 1, 3]))
    m.w32(this + 0xe8, h); m.w32(this + 0xec, t)
    fh, ft = blist(m, rng, vt, 20)                         # the accelerator's free list (+0x5cc head, +0x5d0 tail, +0x5d4 count)
    cnt = rng.choice([0, 3, 0xe, 0xf, 0x10, 0x12])
    m.w32(accel + 0x5d4, cnt); m.w32(accel + 0x5cc, rng.choice([fh, 0]) if cnt == 0 else fh); m.w32(accel + 0x5d0, ft if cnt else 0)
    return [this]


CASES += [
    Case('IOATIR500GLContext::reclaim_resources', w_reclaim_resources, ret='u32', seeds=40),
    Case('IOATIR500GLContext::wait_for_stamp', w_wait_for_stamp, ret='u32', seeds=20),
    Case('IOATIR500GLContext::finish', w_finish, ret='u32', seeds=20),
    Case('IOATIR500GLContext::get_status', w_get_status, ret='u32', seeds=40),
    Case('IOATIR500GLContext::get_config', w_get_config, ret='u32', seeds=40),
    Case('IOATIR500GLContext::purge_texture', w_purge_texture, ret='u32', seeds=40),
]


def w_map_transfer(m, rng):
    this, pool, accel = gl_context(m, rng)
    return [this, rng.choice(pool)]


def w_free_all_context_buffers(m, rng):
    """16 context-buffer slots at +0x10c (stride 0x18: +0 va, +4 flag, +8 memory object, +0xc/+0xe u16s, +0x10/+0x14 words), the slot index +0x28c,
    the context-buffer header object +0xfc"""
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    m.w32(this + 0x28c, rng.randrange(16))
    for i in range(16):
        base = this + 0x10c + 0x18 * i
        m.w32(base + 4, rng.choice([0, 1, 0x100]))
        m.w32(base + 8, vobj(m, rng, vt))
    m.w32(this + 0xfc, vobj(m, rng, vt))
    return [this]


def tex_chain_buffer(m, rng, pool, vt, depth=0):
    """a VendorTextureBuffer for remove_texture_from_stream: +0x20 kind (6 = surface texture -> +0x54 owner; 0 = plain -> +0x50 memory object; 1 = wrapper -> +0x50 inner
    texture; 8 = data), +0x14 header (+8 stamp, +0xe), +0x48, +0x5c"""
    t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
    kind = rng.choice([6, 0, 1, 8, 3]) if depth < 3 else rng.choice([6, 0, 8, 3])
    m.w8(t + 0x20, kind)
    if kind == 6: m.w32(t + 0x54, tex_chain_buffer(m, rng, pool, vt, depth + 1) if depth < 1 else t)
    elif kind == 0: m.w32(t + 0x50, rng.choice([0, vobj(m, rng, vt)]))
    elif kind == 1: m.w32(t + 0x50, tex_chain_buffer(m, rng, pool, vt, depth + 1))
    m.w32(t + 0x48, rng.choice([0, 0x1000]))
    return t


def w_remove_texture(m, rng):
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    return [this, tex_chain_buffer(m, rng, pool, vt)]


CASES += [
    Case('IOATIR500GLContext::map_transfer_to_GART', w_map_transfer, ret='void', seeds=20),
    Case('IOATIR500GLContext::freeAllContextBuffers', w_free_all_context_buffers, ret='void', seeds=20),
    Case('IOATIR500GLContext::remove_texture_from_stream', w_remove_texture, ret='void', seeds=60),
]


def w_get_data_buffer(m, rng):
    """the accelerator's data-buffer cache (head +0x5cc, tail +0x5d0, count +0x5d4, wanted size +0x5d8) and this context's list of buffers in use (+0xe8 head,
    +0xec tail, +0xf0 count), the current command header (+0x108) and the context's sizing word +0xb4"""
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    m.w32(accel + 0xdc, vobj(m, rng, vt))
    m.w32(accel + 0x5d8, rng.choice([0x10000, 0x10000, 0x20000, 0x4000]))
    h, t = blist(m, rng, vt, rng.choice([0, 1, 2, 3]))
    m.w32(accel + 0x5cc, h); m.w32(accel + 0x5d0, t); m.w32(accel + 0x5d4, rng.choice([1, 2, 3, 0xf]))
    m.w32(accel + 0x600, rng.choice([0, accel + 0x5dc, h or accel]))
    uh, ut = blist(m, rng, vt, rng.choice([0, 1, 2]))
    m.w32(this + 0xe8, uh); m.w32(this + 0xec, ut)
    m.w32(this + 0xb4, rng.choice([0x10000, 0x20000, 0x7ffff, 0x80000, 0x8000]))
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(hdr + 0xc, rng.choice([0, 0x100, 0x4000, 0x10000]))
    m.w32(this + 0x108, hdr)
    m.w32(this + 0x78, rng.choice([0, 1, 0x1000]))
    # what the accelerator's allocators hand back: real data buffers (the stock code goes on to use them), sometimes nothing
    script(m, 'allocOneDataBuffer', [rng.choice([0, data_buffer(m, rng, vt), data_buffer(m, rng, vt)]) for _ in range(3)])
    spare = [vobj(m, rng, vt) for _ in range(4)]

    def backing(ok):            # allocDataBufferBacking(buffer): on success the accelerator has attached a memory object to buffer+8
        def f(mach):
            if ok:
                buf = mach.uc.reg_read(UC_PPC_REG_4)
                mach.w32(buf + 8, spare.pop(0))
            return int(ok)
        return f

    def atex(ok):               # allocate_texture(buffer): on success the buffer has a GART offset (+0x48)
        def f(mach):
            if ok: mach.w32(mach.uc.reg_read(UC_PPC_REG_4) + 0x48, 0x1000)
            return int(ok)
        return f
    script(m, 'allocate_texture', [atex(rng.choice([0, 1, 1])) for _ in range(3)])
    script(m, 'allocDataBufferBacking', [backing(rng.choice([0, 1, 1])) for _ in range(3)])
    script(m, 'slot +0x14c', [rng.choice([0, vobj(m, rng, vt), vobj(m, rng, vt)])])      # the new mapping of the buffer's memory
    return [this, m.alloc(0x10), m.alloc(0x10)]


CASES += [
    Case('IOATIR500GLContext::get_data_buffer', w_get_data_buffer, ret='u32', seeds=120, mock=scripted_mock),
]


def w_stop(m, rng):
    """stop(IOService*): unlinks this context from the accelerator's context list (head +0x60, linked through +0x80; +0x68 a second list head), drops its
    data buffers (+0xe8 list) into the accelerator's free list (+0x5cc/+0x5d0/+0x5d4), releases command/context buffers (+0xd4, +0xfc), the memory object +0xb8,
    the bound surface (+0x290) and the shared texture table (+0x88) with its 42 texture slots at +0x2a4"""
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    others = [m.alloc(0x100) for _ in range(2)]
    for o in others: fill_words(m, o, 0x100, rng)
    order = others[:]
    if rng.random() < 0.7: order.insert(rng.randrange(len(order) + 1), this)
    nxt = 0
    for o in reversed(order):                       # singly linked through +0x80
        m.w32(o + 0x80, nxt); nxt = o
    m.w32(accel + 0x60, nxt if order else 0)
    m.w32(accel + 0x68, rng.choice([0, 0, 1]))
    m.w32(accel + 0x738, 5)
    m.w32(accel + 0x78, rng.choice([this, 0, others[0]]))
    fh, ft = blist(m, rng, vt, 20)
    cnt = rng.choice([0, 5, 0xf, 0x10, 0x12])
    m.w32(accel + 0x5d4, cnt); m.w32(accel + 0x5cc, fh if cnt else rng.choice([0, fh])); m.w32(accel + 0x5d0, ft if cnt else 0)
    # the context's own buffers
    h, t = blist(m, rng, vt, rng.choice([0, 1, 3]))
    m.w32(this + 0xe8, h); m.w32(this + 0xec, t)
    m.w32(this + 0xfc, rng.choice([0, vobj(m, rng, vt)]))
    m.w32(this + 0xd4, rng.choice([0, 1]))
    m.w32(this + 0xb8, rng.choice([0, vobj(m, rng, vt)]))
    m.w32(this + 0x78, rng.choice([0, 1, 5]))
    surf = rng.choice([0, 0, m.alloc(0x1000)])
    m.w32(this + 0x290, surf)
    # data buffers on the accelerator's cache that still hold a mapping of this task
    # the shared texture table and the context's texture slots (+0x2a4..): each slot a texture whose header (+0x14) holds a reference count at +0x10
    if rng.random() < 0.7:
        m.w32(this + 0x88, vobj(m, rng, vt))
    else:
        m.w32(this + 0x88, 0)
    for i in range(42):
        if rng.random() < 0.3:
            t_ = m.alloc(0x40); fill_words(m, t_, 0x40, rng)
            hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t_ + 0x14, hdr)
            m.w32(this + 0x2a4 + 4 * i, t_)
        else:
            m.w32(this + 0x2a4 + 4 * i, 0)
    return [this, m.alloc(0x100)]


CASES += [
    Case('IOATIR500GLContext::stop', w_stop, ret='void', seeds=80),
]


def w_get_query_offset(m, rng):
    this, pool, accel = gl_context(m, rng)
    tex = m.alloc(0x100); fill_words(m, tex, 0x100, rng)
    owner = m.alloc(0x40); fill_words(m, owner, 0x40, rng); m.w32(tex + 0x54, owner)
    return [this, tex, rng.choice([0, 1, 2, 7, 0x10, word(rng) & 0xffff]), rng.choice([0, 0, 1, 5])]


def w_write_texture_offset(m, rng):
    """WriteTextureOffset(index, out[], at, texture): follows kind-1 wrapper textures (+0x20 == 1, inner at +0x50) to the real one, whose header (+0x14) has the
    format byte at +0x15 and whose +0x68 holds the tiling bits"""
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    def tex(inner=None):
        t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
        if inner: m.w8(t + 0x20, 1); m.w32(t + 0x50, inner)
        else: m.w8(t + 0x20, rng.choice([0, 6, 8]))
        m.w32(t + 0x68, rng.choice([0, 0x40000000, 0x80000000, 0xc0000000, 0x7fffff, 0xc03fffff, word(rng)]))
        return t
    t = tex()
    for _ in range(rng.choice([0, 0, 1, 2])): t = tex(t)
    if rng.random() < 0.1:
        t2 = m.alloc(0x100); fill_words(m, t2, 0x100, rng); m.w8(t2 + 0x20, 1); m.w32(t2 + 0x50, 0); t = t2
    return [this, rng.choice([0, 1, 7, 8, 9, 15, 16]), m.alloc(0x100), rng.randrange(8), t]


CASES += [
    Case('ATIR500GLContext::GetQueryOffset', w_get_query_offset, ret='u32', seeds=30),
    Case('ATIR500GLContext::WriteTextureOffset', w_write_texture_offset, ret='u32', seeds=60),
]


def w_get_texture(m, rng):
    """get_texture(cmd, texture, &wordsUsed, &wordsPending, &x, regState): `cmd` points into a command buffer (its previous word, cmd[-1], holds the byte count
    of the pending packet), the texture's header (+0x14) has the 'needs load' byte at +0x14 and the refcount at +0x10, and its +0x48 gart offset decides whether
    it is moved to the accelerator's LRU ring (+0x600/+0x5dc)"""
    this, pool, accel = gl_context(m, rng)
    buf = m.alloc(0x400); fill_words(m, buf, 0x400, rng)
    cmd = buf + 0x100
    m.w32(cmd - 4, rng.choice([0, 4, 8, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x30]))
    t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
    m.w8(hdr + 0x14, rng.choice([0, 1, 1]))
    ring = m.alloc(0x40); fill_words(m, ring, 0x40, rng); ring2 = m.alloc(0x40); fill_words(m, ring2, 0x40, rng)
    m.w32(t + 0x24, ring); m.w32(t + 0x28, ring2); m.w32(ring + 0x28, t); m.w32(ring2 + 0x24, t)
    m.w32(t + 0x48, rng.choice([0, 0, 0x1000]))
    m.w32(accel + 0x600, rng.choice([ring, ring2])); m.w32(accel + 0xb90, rng.choice([0, 1]))
    m.w32(this + 0xd0, rng.choice([0, 0x1000])); m.w32(this + 0xe0, m.alloc(0x100))
    w3, w4, w5 = m.alloc(0x10), m.alloc(0x10), m.alloc(0x10)
    m.w32(w3, rng.choice([0, 4, 0x100, 0x203])); m.w32(w4, rng.choice([0, 0, 1, 4, 9]))
    return [this, cmd, t, w3, w4, w5, m.alloc(0x200)]


CASES += [
    Case('ATIR500GLContext::get_texture', w_get_texture, ret='void', seeds=80),
]


def context_slots(m, rng, this, accel, vt):
    """the 16 context-buffer slots at +0x10c (stride 0x18): +4 GART offset of the buffer (0 = not mapped yet), +0x10 stamp, +0x14 -> the buffer (count word at
    +0x14, packets from +0x20), the current slot index +0x28c, and the header being built (+0x108: 8 words, word 5 = number of payload words, payload at +0x20)"""
    m.w32(this + 0x28c, rng.randrange(16))
    for i in range(16):
        base = this + 0x10c + 0x18 * i
        m.w32(base + 4, rng.choice([0, 0, 0x2000]))
        m.w32(base + 8, vobj(m, rng, vt))
        b = m.alloc(0x2000); fill_words(m, b, 0x2000, rng); m.w32(base + 0x14, b)
    hdr = m.alloc(0x400); fill_words(m, hdr, 0x400, rng)
    m.w32(hdr + 0x14, rng.choice([0, 1, 4, 8, 0x10, 0x20]))
    m.w32(hdr + 0x1c, rng.choice([0, 1, 1, 0xfffffffe, 0xff]))
    m.w32(this + 0x108, hdr)
    return hdr


def small_returns(rng, n=60, lo=0, hi=6):
    return [rng.randrange(lo, hi + 1) for _ in range(n)]


def w_submit_context_buffer(m, rng):
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    context_slots(m, rng, this, accel, vt)
    ring = m.alloc(0x40); fill_words(m, ring, 0x40, rng)
    m.w32(accel + 0x600, ring); m.w32(ring + 0x28, ring)
    for i in range(42):
        if rng.random() < 0.3:
            t_ = m.alloc(0x100); fill_words(m, t_, 0x100, rng)
            hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t_ + 0x14, hdr)
            m.w8(hdr + 0x14, rng.choice([0, 1]))
            r1 = m.alloc(0x40); r2 = m.alloc(0x40); fill_words(m, r1, 0x40, rng); fill_words(m, r2, 0x40, rng)
            m.w32(t_ + 0x24, r1); m.w32(t_ + 0x28, r2); m.w32(r1 + 0x28, t_); m.w32(r2 + 0x24, t_)
            m.w32(t_ + 0x48, rng.choice([0, 0x1000]))
            m.w32(this + 0x2a4 + 4 * i, t_)
        else:
            m.w32(this + 0x2a4 + 4 * i, 0)
    script(m, 'write_kernel_context_buffer_regs', small_returns(rng, 4, 10, 60))
    script(m, 'WriteTextureOffset', small_returns(rng, 60, 0, 4))
    script(m, 'WriteVertexArrayOffset', small_returns(rng, 4, 0, 8))
    return [this]


def w_restore_state(m, rng):
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    context_slots(m, rng, this, accel, vt)
    st = m.alloc(0x200); fill_words(m, st, 0x200, rng)
    for off in (0x134, 0x138, 0x13c, 0x140):
        m.w32(st + off, m.alloc(0x40))
    script(m, 'write_r500_3d_blit_state_packet', [0])
    return [this, st]


CASES += [
    Case('ATIR500GLContext::submit_context_buffer', w_submit_context_buffer, ret='void', seeds=60, mock=scripted_mock),
    Case('ATIR500GLContext::restore_state_destroyed_by_pageoff', w_restore_state, ret='void', seeds=30, mock=scripted_mock),
]


def norm_buf(m, rng, b):
    """make a 0x78-byte surface-buffer record usable by the packet writers: u16 dimensions, a non-zero sample/cell divisor, a format index inside the 48-entry
    format table (+0x3a), 4 mip offsets at +0x40.."""
    fill_words(m, b, 0x78, rng)
    for off in (0x14, 0x1c, 0x1e, 0x20):
        m.w16(b + off, rng.choice([0, 1, 2, 4, 16, 64, 100, 256, 1024, 2048]))
    m.w16(b + 0x16, rng.choice([1, 2, 4, 8, 16]))
    m.w8(b + 0x38, rng.getrandbits(8)); m.w8(b + 0x39, rng.getrandbits(8)); m.w8(b + 0x3a, rng.randrange(48)); m.w8(b + 0x36, rng.choice([0, 1]))
    m.w32(b + 0x3c, (rng.getrandbits(32) & ~0xf00000) | (rng.choice([0, 1, 2, 4, 8, 15]) << 20))
    m.w32(b + 0x28, rng.choice([0x3ff00000, 0, 0x1000, 0x20000000, word(rng)]))
    for k in range(4): m.w32(b + 0x40 + 4 * k, rng.choice([0x1000000, 0x2000000, 0x4000000, 0x80000000, word(rng) | 0x01000000]))
    m.w32(b + 8, rng.choice([0x10000000, 0x20000000, word(rng) | 0x01000000]))


def gl_surface_state(m, rng, pool, this, accel):
    """the bound surface (+0x290: 23 buffer records at +0xa8 stride 0x78 and a 23-slot table of them at +0xb70) and the context's own drawing state: current
    level +0x29c, +0x298, buffer slots +0xac / +0xae, the alternate (embedded) buffers at +0x3c0 used when +0x3bc != 0, the attachment list +0x3a8 (count) / +0x3aa /
    +0x3b2 (u16 indexes)"""
    s = m.alloc(0x1000); m.uc.mem_write(s, soup_words(rng, 0x400, pool))
    for i in range(23):
        norm_buf(m, rng, s + 0xa8 + 0x78 * i)
        m.w32(s + 0xb70 + 4 * i, s + 0xa8 + 0x78 * rng.randrange(23))
    m.w32(s + 0xbe8, rng.choice([0, 0x700000, 0x100000, word(rng)]))
    m.w32(this + 0x290, s)
    for i in range(23): norm_buf(m, rng, this + 0x3c0 + 0x78 * i)
    m.w32(this + 0x3bc, rng.choice([0, 0, 1]))
    m.w32(this + 0x29c, rng.randrange(3)); m.w32(this + 0x298, rng.choice([0, 1, 2, 5]))
    m.w16(this + 0xac, rng.choice([9, 9, rng.randrange(23)])); m.w16(this + 0xae, rng.randrange(23))
    cnt = rng.randrange(1, 5)
    m.w16(this + 0x3a8, cnt)
    for k in range(4):
        m.w16(this + 0x3aa + 2 * k, rng.randrange(23)); m.w16(this + 0x3b2 + 2 * k, rng.randrange(23))
    m.w32(accel + 0xb98, rng.choice([4, 4, 1, 2, 0])); m.w32(accel + 0xb74, word(rng))
    m.w16(this + 0xac, rng.choice([9, 9, rng.randrange(23)]))
    return s


def w_wkcbr(m, rng):
    this, pool, accel = gl_context(m, rng)
    gl_surface_state(m, rng, pool, this, accel)
    out = m.alloc(0x400); fill_words(m, out, 0x400, rng)
    return [this, out, rng.choice([0, 1, 8, 20]), word(rng), word(rng)]


def w_blit_state_packet(m, rng):
    this, pool, accel = gl_context(m, rng)
    gl_surface_state(m, rng, pool, this, accel)
    tex = m.alloc(0x100); fill_words(m, tex, 0x100, rng)
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(tex + 0x14, hdr)
    m.w32(this + 0x2a4, rng.choice([0, tex]))
    st = m.alloc(0x300); fill_words(m, st, 0x300, rng)
    return [this, st]


def w_fast_clear(m, rng):
    this, pool, accel = gl_context(m, rng)
    gl_surface_state(m, rng, pool, this, accel)
    out = m.alloc(0x400); fill_words(m, out, 0x400, rng)
    m.w32(out + 4, rng.choice([8, 9, 12, 20, 30]))
    return [this, out]


CASES += [
    Case('ATIR500GLContext::write_kernel_context_buffer_regs', w_wkcbr, ret='u32', seeds=80, mock=scripted_mock, plain_words=True),
    Case('ATIR500GLContext::write_r500_3d_blit_state_packet', w_blit_state_packet, ret='void', seeds=80, mock=scripted_mock, plain_words=True),
    Case('ATIR500GLContext::process_kATIGLStreamFastClearColor', w_fast_clear, ret='void', seeds=60, plain_words=True),
]


def backing_surface(m, rng, pool):
    """a surface a texture is backed by (compact_current_textures): vtable, per-panel flag +0xc14, 23 buffer records at +0xa8 (stride 0x78, +8 = backing store
    address), the current buffer table at +0xb70, flags +0xbd0 / +0xd48"""
    s = m.alloc(0x1000); m.uc.mem_write(s, soup_words(rng, 0x400, pool))
    m.w32(s, m.vtable('ATIR500Surface'))
    m.w32(s + 0xc14, rng.choice([0xffff, 0xffff, 0, 1]))
    for i in range(23):
        m.w32(s + 0xa8 + 0x78 * i + 8, rng.choice([0, 0x1000]))
        m.w32(s + 0xb70 + 4 * i, s + 0xa8 + 0x78 * rng.randrange(23))
    m.w32(s + 0xbd0, rng.choice([0, 0x10000, 0xffff0000, 5]))
    m.w32(s + 0xd48, rng.choice([0, 1]))
    return s


def w_compact_current_textures(m, rng):
    this, pool, accel = gl_context(m, rng)
    vt = m.vtable('ATIR500Memory')
    context_slots(m, rng, this, accel, vt)

    def tex(kind):
        t = m.alloc(0x100); fill_words(m, t, 0x100, rng)
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
        m.w8(t + 0x20, kind); m.w8(hdr + 0x14, rng.choice([0, 1]))
        r1 = m.alloc(0x40); r2 = m.alloc(0x40); fill_words(m, r1, 0x40, rng); fill_words(m, r2, 0x40, rng)
        m.w32(t + 0x24, r1); m.w32(t + 0x28, r2); m.w32(r1 + 0x28, t); m.w32(r2 + 0x24, t)
        m.w32(t + 0x48, rng.choice([0, 0, 0x1000]))
        m.w32(t + 0x50, backing_surface(m, rng, pool)); m.w32(t + 0x58, rng.randrange(23))
        return t
    for i in range(42):
        m.w32(this + 0x2a4 + 4 * i, tex(rng.choice([0, 0, 3, 7, 1, 6])) if rng.random() < 0.25 else 0)
    ring = m.alloc(0x40); fill_words(m, ring, 0x40, rng); m.w32(accel + 0x600, ring); m.w32(ring + 0x28, ring)
    target = tex(rng.choice([0, 0, 3, 1]))
    script(m, 'WriteTextureOffset', small_returns(rng, 60, 0, 4))
    script(m, 'WriteVertexArrayOffset', small_returns(rng, 4, 0, 8))
    script(m, 'surface_buffer_idx_mask', small_returns(rng, 60, 0, 20))
    script(m, '[vcall +0x5d0]', small_returns(rng, 60, 0, 1))
    script(m, 'copy_buffer_from_backing_store', small_returns(rng, 60, 0, 1))
    return [this, target]


CASES += [
    Case('ATIR500GLContext::compact_current_textures', w_compact_current_textures, ret='u32', seeds=80, mock=scripted_mock),
]


# ---- process_command_buffer ---------------------------------------------------------------------------------------------------------------------
# The command-stream interpreter: walks the packets the user-space driver put in this context's command buffer (this+0xe0 -> buffer, packets from +0x1c; each
# packet header = opcode << 24 | length in words, a header with length 0 ends the stream), rewrites them in place (texture/vertex array offsets, surface
# addresses, fast-clear values) and submits finished chunks. The world below lays out everything the handlers touch: the shared texture table (+0x88), the
# surface state (as for the packet writers), the context-buffer slots and a stream of packets.

KNOWN_OPCODES = [0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,
                 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3d, 0x3f,
                 0x00, 0x01, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x3c, 0x3e, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0xff]


def pcb_textures(m, rng, pool, this, accel, n=8):
    """the shared texture table (+0x88: array at +0x10, count at +0x14) of n textures of mixed kinds, each with a header whose refcount (+0x10) is 2"""
    vt = m.vtable('ATIR500Memory')
    tab = vobj(m, rng, m.vtable('IOATIR500Shared'), 0x40)
    arr = m.alloc(0x100)
    texs = []
    for i in range(n):
        t = m.alloc(0x100); m.uc.mem_write(t, soup_words(rng, 0x40, pool))
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(t + 0x14, hdr)
        m.w32(hdr + 0x10, rng.choice([1, 2, 0x10001, 3])); m.w8(hdr + 0x14, rng.choice([0, 0, 1])); m.w8(hdr + 0x15, rng.getrandbits(8))
        kind = rng.choice([0, 1, 6, 7, 8, 3])
        m.w8(t + 0x20, kind)
        r1 = m.alloc(0x40); r2 = m.alloc(0x40); fill_words(m, r1, 0x40, rng); fill_words(m, r2, 0x40, rng)
        m.w32(t + 0x24, r1); m.w32(t + 0x28, r2); m.w32(r1 + 0x28, t); m.w32(r2 + 0x24, t)
        m.w32(t + 0x48, rng.choice([0, 0x1000, 0x20000]))
        m.w32(t + 0x50, backing_surface(m, rng, pool)); m.w32(t + 0x54, backing_surface(m, rng, pool)); m.w32(t + 0x58, rng.randrange(23))
        m.w32(t + 0x68, word(rng)); m.w32(t + 0x64, word(rng))
        m.w32(m.alloc(8), 0)
        m.w32(arr + 4 * i, t); texs.append(t)
    m.w32(tab + 0x10, arr); m.w32(tab + 0x14, n)
    m.w32(this + 0x88, tab)
    return texs


def pcb_packet(rng, op, nwords=None):
    """one packet: header word and random operand words (mostly small, as indexes/counts are)"""
    n = nwords if nwords is not None else rng.choice([4, 6, 8, 12, 16, 24])
    body = [rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 0x10, 0x20, rng.getrandbits(8), word(rng)]) for _ in range(n - 1)]
    return [(op << 24) | n] + body


def pcb_world_with(opcodes_fn, npackets=(1, 4), special=None):
    """special(m, rng, op, texs) -> the words of one packet of opcode `op` (operands that are pointers / table indexes), or None for the random operands"""
    def world(m, rng):
        this, pool, accel = gl_context(m, rng)
        vt = m.vtable('ATIR500Memory')
        gl_surface_state(m, rng, pool, this, accel)
        context_slots(m, rng, this, accel, vt)
        texs = pcb_textures(m, rng, pool, this, accel)
        for i in range(42):                                  # the bound-texture slots: empty, or one of the shared textures
            m.w32(this + 0x2a4 + 4 * i, rng.choice(texs) if rng.random() < 0.25 else 0)
        R = m.alloc(0x6000); fill_words(m, R, 0x6000, rng)
        m.w32(this + 0xe0, R + 0x100)
        m.w32(this + 0xd0, rng.choice([0, 0x1000]))
        hdr = m.w32 and m.r32(this + 0x108)
        m.w32(hdr + 0x14, rng.choice([0, 2, 4]))
        words = []
        for _ in range(rng.randrange(npackets[0], npackets[1] + 1)):
            op = opcodes_fn(rng)
            pk = special(m, rng, op, texs) if special else None
            words += pk if pk else pcb_packet(rng, op)
        words += [0]                                   # the terminator: a header with length 0
        for i, w in enumerate(words): m.w32(R + 0x100 + 0x1c + 4 * i, w)
        ring = m.alloc(0x40); fill_words(m, ring, 0x40, rng); m.w32(accel + 0x600, ring); m.w32(ring + 0x28, ring)
        script(m, 'WriteTextureOffset', small_returns(rng, 60, 0, 4))
        script(m, 'GetVertexArrayOffset', small_returns(rng, 60, 0, 0x1000))
        script(m, 'surface_buffer_idx_mask', small_returns(rng, 60, 0, 20))
        return [this, m.alloc(0x40)]
    return world


def pcb_special(m, rng, op, texs):
    if op == 0x36:        # [hdr, transfer buffer pointer, index count, base offset, ..., (index pairs) ...]
        buf = m.alloc(0x100); fill_words(m, buf, 0x100, rng)
        m.w32(buf + 0x48, rng.choice([0, 0, 0x1000])); m.w32(buf + 4, rng.choice([0, 0x2000]))
        cnt = rng.choice([0, 1, 2, 3]); n = 6 + 3 * max(cnt, 1)
        body = [rng.choice([0, 1, 4, 8]) for _ in range(n - 4)]
        return [(op << 24) | n, buf, cnt * 2 - rng.choice([0, 1]) if cnt else 0, rng.choice([0, 0x100, 0x1000])] + body
    return None


# the 0x144-byte tracking block (trackBlk) on process_command_buffer's stack is read by restore_state_destroyed_by_pageoff / get_texture; compare what they see
PCB_TRACK_READS = {'restore_state_destroyed_by_pageoff': {1: 0x144}, 'get_texture': {6: 0x144}}

CASES += [
    Case('ATIR500GLContext::process_command_buffer', pcb_world_with(lambda rng: rng.choice(KNOWN_OPCODES), (2, 6), special=pcb_special), ret='u32', seeds=450, mock=scripted_mock, plain_words=True, stack_args=PCB_TRACK_READS, name='process_command_buffer (random streams)'),
]


for _op in KNOWN_OPCODES:
    CASES.append(Case('ATIR500GLContext::process_command_buffer', pcb_world_with(lambda rng, _op=_op: _op, (1, 3), special=pcb_special), ret='u32', seeds=60, mock=scripted_mock,
                      plain_words=True, stack_args=PCB_TRACK_READS, name='process_command_buffer (opcode 0x%02x)' % _op))


def pcb_bind_special(m, rng, op, texs):
    """texture bind (opcodes 0x06-0x15) in the mode that derives the texture size field from the format table: [hdr, texture index, mode 1 << 30 | bits, format id << 24 | size]
    - the shift applied to the size is (format table entry >> 12) & 7, so the format id (hence the table entry; ati_format_info_table has 48 entries) must vary and the mode must be 1"""
    return [(op << 24) | 4, rng.randrange(len(texs)), (1 << 30) | rng.getrandbits(12), (rng.randrange(48) << 24) | rng.getrandbits(20)]


CASES.append(Case('ATIR500GLContext::process_command_buffer', pcb_world_with(lambda rng: rng.randrange(6, 0x16), (1, 3), special=pcb_bind_special), ret='u32', seeds=120,
                  mock=scripted_mock, plain_words=True, stack_args=PCB_TRACK_READS, name='process_command_buffer (texture bind, format-table size shift)'))
