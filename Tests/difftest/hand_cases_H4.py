"""Hand-written worlds (fork H4 of the hand-world push): the IOATIR500Accelerator, IOATIR500Shared, IOATIR500DVDContext and ATIR500DVDContext
methods whose generic/earlier worlds left large parts of the function unexecuted (coverage < 90%).
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_H4.py   (needs STOCK_KEXT; see Tools/difftest/README.md)

Each world builds the real object graph the function walks (right vtables, lists that end, tables in range) and steers the callee results the
branches depend on; the header comment of each case says which paths it reaches and which it cannot."""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from difftest import Case, default_mock
from unicorn.ppc_const import UC_PPC_REG_3, UC_PPC_REG_4, UC_PPC_REG_5, UC_PPC_REG_6
from common import word, fill_words, object_with_vtable, accelerator_with_registers, R500Registers, FlipFlopRegisters
from hand_cases_A import new_mock, obj, accel, accel_r500, plain, gart_accel, PAGE

CASES = []


def shared(m, rng, acct=True):
    """an IOATIR500Shared (+0xc accelerator whose +0x808 is the byte counter the allocators maintain)"""
    s = obj(m, rng, 'IOATIR500Shared', 0x100)
    a = accel(m, rng, mmio=False)
    m.w32(s + 0xc, a if acct else 0)
    m.w32(s + 0x20, 0); m.w32(s + 0x24, 0)                 # no client-shared chunks, no textures yet (the worlds add them)
    m.w32(a + 0x808, rng.randrange(0, 100000))
    return s, a


# ---- handle table: alloc_buf_handle / free_buf_handle ---------------------------------------------------------------------------------------------
def handle_table(m, rng, s, words):
    """handle table (+0x10, capacity*4 bytes), capacity (+0x14), bitmap (+0x18, capacity/8 bytes), hint (+0x1c): `words` bitmap words, some full"""
    cap = 32 * words
    tbl = m.alloc(4 * cap + 0x10); fill_words(m, tbl, 4 * cap, rng)
    bm = m.alloc(4 * words + 0x10)
    for i in range(words):
        m.w32(bm + 4 * i, rng.choice([0xffffffff, 0xffffffff, 0, 0x0000ffff, 0xfffffffe, 0x7fffffff, word(rng)]))
    m.w32(s + 0x10, tbl); m.w32(s + 0x14, cap); m.w32(s + 0x18, bm)
    m.w32(s + 0x1c, rng.choice([0, 0, 5, 33, 32 * words - 1, 32 * words + 3, 40 * words]))
    return tbl, bm, cap


def handles_mock(m, name, k):
    """alloc_handles(): grows the table to twice the capacity (as the real one does: copies the old words), or fails on some seeds"""
    if 'alloc_handles' in name:
        s = m.uc.reg_read(UC_PPC_REG_3)
        if m.seed % 5 == 4:
            return 0
        cap = m.r32(s + 0x14); ncap = 2 * cap if cap else 0x400
        old, oldbm = m.r32(s + 0x10), m.r32(s + 0x18)
        tbl = m.alloc(4 * ncap + 0x10); bm = m.alloc(ncap // 8 + 0x10)
        for i in range(cap // 8 * 2 if cap else 0):
            pass
        if cap:
            m.uc.mem_write(tbl, bytes(m.uc.mem_read(old, 4 * cap)))
            m.uc.mem_write(bm, bytes(m.uc.mem_read(oldbm, cap // 8)))
        m.w32(s + 0x10, tbl); m.w32(s + 0x14, ncap); m.w32(s + 0x18, bm)
        return 1
    return new_mock(m, name, k)


def w_alloc_buf_handle(m, rng):
    s, a = shared(m, rng)
    if rng.random() < 0.15:
        m.w32(s + 0x10, 0); m.w32(s + 0x14, 0); m.w32(s + 0x18, 0); m.w32(s + 0x1c, 0)       # no table yet: alloc_handles creates the first one
    else:
        handle_table(m, rng, s, rng.choice([1, 2, 3, 4]))
    out = m.alloc(0x10)
    return [s, plain(m, rng, 0x40), out]


def w_free_buf_handle(m, rng):
    s, a = shared(m, rng)
    tbl, bm, cap = handle_table(m, rng, s, rng.choice([1, 2, 3]))
    h = rng.choice([0, 1, 31, 32, cap - 1, cap, cap + 5, rng.randrange(0, cap)])
    rec = plain(m, rng, 0x40)
    if h < cap:
        m.w32(tbl + 4 * h, rec if rng.random() < 0.75 else word(rng))
        m.w32(bm + 4 * (h >> 5), word(rng) | (1 << (h & 31)))
    return [s, rec, h]


CASES += [
    Case('IOATIR500Shared::alloc_buf_handle', w_alloc_buf_handle, ret='bool', seeds=80, mock=handles_mock, plain_words=True),
    Case('IOATIR500Shared::free_buf_handle', w_free_buf_handle, ret='void', seeds=80, plain_words=True),
]


# ---- texture creation: new_texture / new_agp_texture / new_agpref_texture / new_global_texture / new_surface_texture ----------------------------------
def rec(m, rng, typ=None, hdr=True):
    """a texture record (0x100 bytes of noise): header at +0x14 (own noise), type byte +0x20, links +0x24/+0x28 (self-circular), no next"""
    r = m.alloc(0x100); fill_words(m, r, 0x100, rng)
    h = m.alloc(0x80); fill_words(m, h, 0x80, rng)
    if hdr: m.w32(r + 0x14, h)
    m.w32(r + 0x24, r); m.w32(r + 0x28, r); m.w32(r + 0x3c, 0)
    if typ is not None: m.w8(r + 0x20, typ)
    return r


def fail_at(m, k, period):
    """True on one call index of `period` per seed: spreads failures of a callee over the seeds"""
    return (m.seed + 3 * k) % period == 0


def tex_mock(m, name, k):
    """callee results of the texture-creation functions. The accelerator's slot 0x570 allocates a texture record (fails now and then), alloc_buf_handle /
    alloc_client_shared succeed (writing their out parameters) except on some seeds, new_agp_texture returns a record whose header holds a refcount,
    IOBufferMemoryDescriptor::inTaskWithOptions / IOMemoryDescriptor::withAddress return a descriptor object (a null on some seeds)."""
    r3, r4, r5, r6 = (m.uc.reg_read(r) for r in (UC_PPC_REG_3, UC_PPC_REG_4, UC_PPC_REG_5, UC_PPC_REG_6))
    if 'vtable slot +0x570' in name or '0x570' in name:
        if fail_at(m, k, 9): return 0
        t = m.alloc(0x100); m.w32(t + 0x24, t); m.w32(t + 0x28, t)
        return t
    if 'alloc_buf_handle' in name:
        if fail_at(m, k, 7): return 0
        m.w32(r5, 1 + (m.seed % 40)); return 1
    if 'alloc_client_shared' in name:
        if fail_at(m, k, 5): return 0
        blk = m.alloc(0x40); m.w32(r5, blk); m.w32(r6, 0x30000000 + 0x40 * (m.seed % 50)); return 1
    if 'new_agp_texture' in name:
        if fail_at(m, k, 6): return 0
        t = rec(m, random_for(m, k), 4); m.w32(t + 0x58, 0x5000 + 0x1000 * (m.seed % 4))
        m.w32(m.r32(t + 0x14) + 0x10, m.seed % 3)           # the header's reference count: 0 = nobody else uses it, the failure paths delete it
        m.w32(r6, 0x31000000); return t
    if 'withPersistentMemoryDescriptor' in name:          # a persistent descriptor: the very same object (reuse), none, or another one
        c = m.seed % 3
        return r3 if c == 0 else (0 if c == 1 else plain(m, random_for(m, k), 0x40))
    if 'inTaskWithOptions' in name or 'withAddress' in name:
        if fail_at(m, k, 8) or (m.seed % 4 == 1 and k >= 1): return 0
        return plain(m, random_for(m, k), 0x40)
    if '0x14c' in name:                      # IOMemoryDescriptor::map(): a memory map object or null
        if fail_at(m, k, 6): return 0
        return plain(m, random_for(m, k), 0x40)
    if name.startswith('IOMalloc') or name.startswith('_IOMalloc'):
        return 0 if m.seed % 7 == 3 else m.alloc(0x40)
    if 'vtable slot +0xd0' in name or 'vtable slot +0x1cc' in name:      # an address of a mapped region (kernel mappings get stored into and indexed)
        return m.alloc(0x2100)
    if 'vtable slot +0x128' in name:
        return PAGE * (1 + m.seed % 3)
    if 'delete_texture' in name or 'free_buf_handle' in name or 'reset_req_bits' in name or 'prune_buffers' in name:
        return 0
    if 'find_surface_for_id' in name:
        return 0 if fail_at(m, k, 6) else m.surf_obj
    return new_mock(m, name, k)


def random_for(m, k):
    import random
    return random.Random(m.seed * 131 + k)


def sh_accel(m, rng):
    s, a = shared(m, rng)
    m.w32(a + 0x830, rng.choice([0x400, 0x4000, 0x100]))        # GART size in entries: roundedLength <= entries*0xc00/4
    m.w32(a + 0x82c, rng.choice([0, 0x100]))
    m.w32(a + 0x830, rng.choice([0x10, 0x1000, 0x4000]))
    m.w32(a + 0x20c * 4, rng.choice([8, 0x100, 0x4000]))
    gs = obj(m, rng, 'IOATIR500Shared', 0x100)
    return s, a, gs


def w_new_global(m, rng):
    s, a, gs = sh_accel(m, rng)
    m.w32(a + 0x6c, rng.choice([gs, gs, gs, 0, s]))
    ids = [rng.choice([5, 6, 7]) for _ in range(rng.randrange(0, 4))]
    prev = 0
    for i in ids[::-1]:
        t = rec(m, rng, 0); m.w32(m.r32(t + 0x14) + 4, i); m.w32(t + 0x3c, prev); prev = t
    m.w32(gs + 0x24, prev)
    return [s, rng.choice([0, 5, 6, 7, 8]), m.alloc(0x10)]


def w_new_surface(m, rng):
    s, a, gs = sh_accel(m, rng)
    m.w32(a + 0x6c, rng.choice([s, s, gs]))
    m.w32(a + 0x70, rng.randrange(0, 50))
    m.surf_obj = obj(m, rng, 'IOATIR500Surface', 0xd00)
    return [s, rng.randrange(1, 9), rng.randrange(0, 5), rng.randrange(0, 5), m.alloc(0x10)]


def w_new_agpref(m, rng):
    s, a, gs = sh_accel(m, rng)
    m.w32(a + 0x6c, rng.choice([s, s, gs]))
    m.w32(a + 0x70, rng.randrange(0, 50))
    return [s, rng.choice([0, 0x5000 + 0x20, 0x9000]), 0x5000 + 0x100 * rng.randrange(0, 4), 0x2000, m.alloc(0x10)]


def w_new_texture(m, rng):
    s, a, gs = sh_accel(m, rng)
    m.w32(a + 0x6c, rng.choice([s, s, gs]))
    m.w32(a + 0x70, rng.randrange(0, 50))
    agp = 0x8000 if m.seed % 2 == 1 else rng.choice([0, 0, 0x8000])      # odd seeds always take the AGP route (the inTaskWithOptions failure path needs it)
    ln = (0x2000 if m.seed % 2 == 1 else rng.choice([0, 0x2000])) if agp else 0
    if m.seed % 4 == 1: m.w32(a + 0x20c * 4, 0x4000)                    # room for the allocation, so the descriptor allocation is reached
    return [s, rng.choice([0x1000, 0x20000, 0x400000]), rng.choice([0, 0, 0x77]), agp, ln, m.alloc(0x10), m.alloc(0x10)]


def w_new_agp(m, rng):
    s, a, gs = sh_accel(m, rng)
    m.w32(a + 0x6c, rng.choice([s, s, gs]))
    m.w32(a + 0x70, rng.randrange(0, 50))
    addr = rng.choice([0, 0, 0x5000 + 0x20, 0x5000, 0x7000])
    ln = rng.choice([0x1000, 0x2000, 0x100000])
    prev = 0
    for _ in range(rng.randrange(0, 4)):                   # an existing AGP texture the request may match
        t = rec(m, rng, 4 if rng.random() < 0.8 else 5)
        m.w32(t + 8, plain(m, rng, 0x40)); m.w32(t + 0x54, rng.choice([0, 0, 1]))
        m.w32(t + 0x50, addr & 0xfff if rng.random() < 0.8 else 0x40); m.w32(t + 0x58, addr & ~0xfff if rng.random() < 0.8 else 0x9000)
        m.w32(t + 0x5c, 0x1000 * ((ln + (addr & 0xfff) + 0xfff) // 0x1000) if rng.random() < 0.8 else 0x1000); m.w32(t + 0x3c, prev); prev = t
    m.w32(s + 0x24, prev)
    return [s, addr, ln, m.alloc(0x10)]


CASES += [
    Case('IOATIR500Shared::new_global_texture', w_new_global, ret='u32', seeds=120, mock=tex_mock, plain_words=True),
    Case('IOATIR500Shared::new_surface_texture', w_new_surface, ret='u32', seeds=120, mock=tex_mock, plain_words=True),
    Case('IOATIR500Shared::new_agpref_texture', w_new_agpref, ret='u32', seeds=120, mock=tex_mock, plain_words=True),
    Case('IOATIR500Shared::new_texture', w_new_texture, ret='u32', seeds=400, mock=tex_mock, plain_words=True),
    Case('IOATIR500Shared::new_agp_texture', w_new_agp, ret='u32', seeds=200, mock=tex_mock, plain_words=True, ignore_args={'withPersistentMemoryDescriptor': [1], 'vtable slot +0x18': [1, 2]}),
]


def w_alloc_client_shared(m, rng):
    """chunks of 0x80 records (kernel address chunk[4], user address chunk[5], count chunk[6]); an index past all chunks makes a new one (IOMalloc,
    descriptor, two maps)"""
    s, a = shared(m, rng)
    prev = 0
    for _ in range(rng.randrange(0, 4)):
        c = m.alloc(0x40)
        m.w32(c, 0); m.w32(c + 4, plain(m, rng, 0x40)); m.w32(c + 8, plain(m, rng, 0x40)); m.w32(c + 0xc, plain(m, rng, 0x40))
        m.w32(c + 0x10, m.alloc(0x2100)); m.w32(c + 0x14, 0x40000000 + 0x2000 * rng.randrange(0, 8)); m.w32(c + 0x18, rng.choice([0x80, 0x80, 4]))
        if prev: m.w32(prev, c)
        else: m.w32(s + 0x20, c)
        prev = c
    return [s, rng.choice([0, 3, 4, 5, 0x7f, 0x80, 0x81, 0x100, 0x1ff, 0x200]), m.alloc(0x10), m.alloc(0x10)]


CASES += [
    Case('IOATIR500Shared::alloc_client_shared', w_alloc_client_shared, ret='bool', seeds=200, mock=tex_mock, plain_words=True,
         ignore_args={'vtable slot +0x18': [1, 2]}),
]


def del_mock(m, name, k):
    """delete_texture's callees: the accelerator's stamp test (slot 0x554: the orphan path when it says no), OSDecrementAtomic (old value 1 = last
    reference: the nested delete), everything else harmless"""
    if 'vtable slot +0x554' in name:
        return 1 if (m.seed + k) % 3 else 0
    if 'DecrementAtomic' in name:
        return 1 if (m.seed + k) % 2 else 2
    if any(x in name for x in ('addOrphanTexture', 'delete_texture', 'free_buf_handle', 'reset_req_bits', 'prune_buffers')):
        return 0
    return new_mock(m, name, k)


def w_delete_texture(m, rng):
    """the record's type byte (+0x20) picks the cleanup: 0 surface texture (unlinked from the surface's list at +0xbcc, link +0x54), 1 global (source record
    at +0x50 with a refcount in its header), 2/3 buffers (3: clears the face table of the header, slot 0x524 when +0x48), 4 AGP, 6/7 reference
    textures (source at +0x54 / +0x58); the shared object's own list (+0x24, link +0x3c) must contain the record"""
    s, a, gs = sh_accel(m, rng)
    m.w32(a + 0x6c, rng.choice([gs, gs, s]))
    m.w32(a + 0x72c, rng.randrange(1, 9))
    typ = rng.choice([0, 1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8])
    t = rec(m, rng, typ)
    hdr = m.r32(t + 0x14)
    m.w8(hdr + 0x34, rng.choice([0, 1, 4])); m.w32(t + 0x48, rng.choice([0, 0x100])); m.w32(t + 4, rng.choice([0, 7]))
    m.w32(t + 8, rng.choice([0, plain(m, rng, 0x40)])); m.w32(t + 0x10, rng.choice([0, plain(m, rng, 0x40)]))
    other = rec(m, rng, 2)
    m.w32(t + 0x24, rng.choice([t, other])); m.w32(t + 0x28, rng.choice([t, other]))
    if m.r32(t + 0x24) == other: m.w32(other + 0x24, other); m.w32(other + 0x28, other)
    src = rec(m, rng, rng.choice([2, 3, 4]))
    m.w32(m.r32(src + 0x14) + 0x10, rng.choice([1, 2])); m.w32(src + 0x3c, 0)
    if typ == 0:
        surf = obj(m, rng, 'IOATIR500Surface', 0xd00)
        m.w32(t + 0x50, rng.choice([0, surf]))
        o2 = rec(m, rng, 0)
        m.w32(surf + 0xbcc, rng.choice([t, o2])); m.w32(o2 + 0x54, rng.choice([t, 0])); m.w32(t + 0x54, rng.choice([0, o2]))
        if m.r32(surf + 0xbcc) == t: m.w32(t + 0x54, rng.choice([0, o2]))
    elif typ == 1:
        m.w32(t + 0x50, rng.choice([0, src]))
    elif typ == 6:
        m.w32(t + 0x54, src)
    elif typ == 7:
        m.w32(t + 0x58, src)
    # the shared object's list: before the record, the record, after
    pre = rec(m, rng, 2); post = rec(m, rng, 2)
    layout = rng.choice(['head', 'second', 'absent', 'empty'])
    m.w32(t + 0x3c, post if rng.random() < 0.5 else 0); m.w32(post + 0x3c, 0); m.w32(pre + 0x3c, 0)
    if layout == 'head': m.w32(s + 0x24, t)
    elif layout == 'second': m.w32(pre + 0x3c, t); m.w32(s + 0x24, pre)
    elif layout == 'absent': m.w32(s + 0x24, pre)
    else: m.w32(s + 0x24, 0)
    return [s, t]


CASES += [
    Case('IOATIR500Shared::delete_texture', w_delete_texture, ret='u32', seeds=400, mock=del_mock, plain_words=True,
         ignore_args={'vtable slot +0x18': [1, 2], 'vtable slot +0x554': [2], 'vtable slot +0x524': [2], 'vtable slot +0x5ac': [2]}),
]


def fta_mock(m, name, k):
    if 'freeTransferToAllocGART' in name:                 # bool: a buffer was freed, now and then (ends the walk)
        return 1 if (m.seed + 2 * k) % 4 == 3 else 0
    return new_mock(m, name, k)


def w_shared_free_to_alloc(m, rng):
    s, a, gs = sh_accel(m, rng)
    prev = 0
    for _ in range(rng.randrange(0, 6)):
        t = rec(m, rng, rng.choice([0, 1, 2, 3, 4, 4, 5, 6, 7, 7])); m.w32(t + 0x3c, prev); prev = t
    m.w32(s + 0x24, prev)
    needed = plain(m, rng, 0x40)
    return [s, needed, rng.choice([0, 1])]


CASES += [
    Case('IOATIR500Shared::freeToAllocGART', w_shared_free_to_alloc, ret='bool', seeds=100, mock=fta_mock, plain_words=True),
]


# ---- IOATIR500DVDContext ----------------------------------------------------------------------------------------------------------------------
def dvdctx(m, rng, cls='ATIR500DVDContext', size=0x400):
    """a DVD context (+0x8c accelerator, +0xf8 bound surface), no bound surface yet"""
    c = obj(m, rng, cls, size)
    a = accel(m, rng, mmio=False)
    m.w32(c + 0x8c, a); m.w32(c + 0xf8, 0); m.w32(c + 0x88, rng.choice([0, 0x400, 0x7ffc00, 0x20000400]))
    m.w32(a + 0x78, rng.choice([c, 0, word(rng)]))
    return c, a


def alloc_ctx_mock(m, name, k):
    """withOptions: the Nth allocation fails (N by seed: 0 = first, 1 = second, 2 = third, otherwise none); slot 0x1cc gives a header block"""
    if 'withOptions' in name:
        n = getattr(m, 'nopts', 0); m.nopts = n + 1
        if m.seed % 5 == n: return 0
        return plain(m, random_for(m, k), 0x40)
    if 'vtable slot +0x1cc' in name:
        return m.alloc(0x400)
    if 'init_context_buffer_header' in name:
        return 0
    return new_mock(m, name, k)


def w_alloc_all_ctx(m, rng):
    c, a = dvdctx(m, rng)
    return [c, rng.choice([0x1000, 0x2000, 0x10000])]


def surf_dvd(m, rng, c, bound=True):
    """a surface the DVD context may bind: state bits (+0xbf8), attachment buffer table (+0xb70 + 4*n -> records with +8 / +0x18 / +0x10 / +0x24 / +0x1c / +0x1e)"""
    sf = obj(m, rng, 'IOATIR500Surface', 0xd00)
    for n in range(0x20):
        r = m.alloc(0x40); fill_words(m, r, 0x40, rng)
        m.w32(r + 0x10, rng.choice([0, 0x1000])); m.w32(r + 0x24, rng.choice([0, 0])); m.w16(r + 0x1c, rng.choice([16, 64, 200])); m.w16(r + 0x1e, rng.choice([16, 64, 100])); m.w16(r + 0x16, rng.choice([1, 2, 4]))
        m.w32(sf + 0xb70 + 4 * n, r)
    m.w32(sf + 0xbf8, rng.choice([0, 0x400, 0x20000400, 0x7ffc00, 0x10000400]))
    m.w32(sf + 0x90, rng.choice([0, 0, c]))
    m.w32(sf + 0x88, rng.choice([0, 0, 1])); m.w32(sf + 0x8c, rng.choice([0, 0, 1]))
    m.w32(sf + 0xbe8, rng.getrandbits(16))
    if bound: m.w32(c + 0xf8, sf)
    return sf


def lock_mock(m, name, k):
    """alloc_surfaces(mask, aggressive): per-seed script - 0 now (success), 2 (give up), 1 (busy) a few times and then success, 1 for ever (the 1000-try
    path, whose aggressive retry then succeeds or fails)"""
    if 'alloc_surfaces' in name:
        n = getattr(m, 'nalloc', 0); m.nalloc = n + 1
        mode = m.seed % 6
        agg = m.uc.reg_read(UC_PPC_REG_5) & 0xff
        if mode == 0: return 0
        if mode == 1: return 2
        if mode == 2: return 1 if n < 3 else 0
        if mode == 3: return (0 if agg and m.seed % 12 == 3 else 1) if True else 0
        if mode == 4: return 1 if n < 1 else 2
        return 1
    return new_mock(m, name, k)


def w_lock_all(m, rng):
    c, a = dvdctx(m, rng)
    if rng.random() > 0.15: surf_dvd(m, rng, c)
    return [c, 0, m.alloc(0x80)]


def surf_mock(m, name, k):
    """set_surface: find_surface_for_id returns the surface object or none; slot 0x5ac (mode-bits acceptance) answers yes/no by seed"""
    if 'find_surface_for_id' in name:
        return 0 if m.seed % 5 == 0 else m.surf_new
    if 'vtable slot +0x5ac' in name:
        return 0 if m.seed % 4 == 3 else 1
    if any(x in name for x in ('remove_dvd_context', 'prune_buffers', 'reset_req_bits', 'set_dvd_context', 'vtable slot +0x5a8')):
        return 0
    return new_mock(m, name, k)


def w_dvd_set_surface(m, rng):
    c, a = dvdctx(m, rng)
    old = surf_dvd(m, rng, c, bound=rng.random() < 0.6)
    m.surf_new = old if rng.random() < 0.3 and m.r32(c + 0xf8) else surf_dvd(m, rng, c, bound=False)
    if rng.random() < 0.3: m.w32(m.surf_new + 0x90, obj(m, rng, 'ATIR500DVDContext', 0x100))          # owned by another DVD context
    return [c, rng.choice([0, 1, 2, 3]), rng.choice([0x1, 0x40, 0x4000, 0x803f]), rng.choice([0, 1, 3, 6])]


CASES += [
    Case('IOATIR500DVDContext::allocAllContextBuffers', w_alloc_all_ctx, ret='bool', seeds=60, mock=alloc_ctx_mock, plain_words=True,
         ignore_args={'vtable slot +0x18': [1, 2]}),
    Case('IOATIR500DVDContext::lock_all_buffers', w_lock_all, ret='u32', seeds=90, mock=lock_mock, plain_words=True, limit=800000),
    Case('IOATIR500DVDContext::set_surface', w_dvd_set_surface, ret='u32', seeds=120, mock=surf_mock, plain_words=True),
]


# ---- ATIR500DVDContext ------------------------------------------------------------------------------------------------------------------------
def w_dvd_read_regs(m, rng):
    c = obj(m, rng, 'ATIR500DVDContext', 0x400)
    a = accel_r500(m, rng)
    m.w32(c + 0x8c, a)
    n = rng.choice([0, 1, 2, 5])
    offs = m.alloc(0x40); outv = m.alloc(0x40); cnt = m.alloc(0x10)
    for i in range(8): m.w32(offs + 4 * i, rng.choice([0, 0x1720, 0xe40, 0x3ffc, 0x1fff, word(rng)]))
    bc = 4 * n if rng.random() < 0.8 else rng.choice([4 * n + 2, 4 * n + 4, 1])
    m.w32(cnt, 4 * n if rng.random() < 0.8 else rng.choice([4 * n + 1, 4 * n + 4]))
    return [c, offs, outv, bc, cnt]


def w_dvd_subpicture(m, rng):
    c, a = dvdctx(m, rng)
    m.w8(a + 0x80, rng.choice([0, 1, 1]))
    if rng.random() < 0.7: m.w32(c + 0xf8, obj(m, rng, 'ATIR500Surface', 0x400))
    return [c, rng.randrange(0, 100), rng.randrange(0, 100), rng.randrange(0, 100), rng.randrange(0, 100)]


def idct_mock(m, name, k):
    if 'submit_idct_buffer_consumed' in name:
        return rng_stamp(m, k)
    return new_mock(m, name, k)


def rng_stamp(m, k):
    return (0x100 if m.seed % 3 else 0x7fffffff) + (m.seed % 7)


def w_dvd_idct(m, rng):
    c, a = dvdctx(m, rng)
    m.w32(a + 0x8bc, rng.choice([0, 1, 1, 1])); m.w8(a + 0x80, rng.choice([1, 1, 1, 0])); m.w32(a + 0x854, rng.choice([0x10, 0x100, 0x7ffffff0]))
    if rng.random() < 0.85:
        sf = obj(m, rng, 'ATIR500Surface', 0x1000)
        m.w16(sf + 0x9a, rng.randrange(8, 64)); m.w16(sf + 0x94, rng.randrange(0, 8))
        for off in [0x558 + 0x78 * i for i in range(4)] + [0x8a0]:
            m.w32(off + sf + 8, m.alloc(0x1000)); m.w16(off + sf + 0x18, rng.choice([16, 32, 64]))
        m.w32(c + 0xf8, sf)
    for slot in (0x168, 0x184, 0x1a4, 0x1c0):                      # the four IDCT buffers: GART offset at +4, header pointer at +0x14
        m.w32(c + slot + 4, rng.choice([0, 0x1000])); m.w32(c + slot + 0x14, m.alloc(0x100))
    m.w32(c + 0x164, rng.choice([0, 1])); m.w32(c + 0x1a0, rng.choice([0, 1]))
    info = m.alloc(0x80)
    m.w32(info, rng.choice([0, 1])); m.w32(info + 4, rng.choice([0, 1])); m.w32(info + 8, rng.randrange(0, 3)); m.w32(info + 0xc, rng.choice([0, 0, 1, 1, 2]))
    return [c, info, 0x80]


def discard_mock(m, name, k):
    if 'DecrementAtomic' in name:
        return 1 if (m.seed + k) % 2 else 2
    if 'delete_texture' in name or 'AddAtomic' in name:
        return 0
    return new_mock(m, name, k)


def w_dvd_discard(m, rng):
    """the command buffer's record stream (header +0xa4, records from +0x1c: opcode byte, 24-bit length, a handle index): opcodes 0x19-0x2a attach the
    shared allocator's texture to a slot (+0x104 + 4*n), 0x2b-0x3c detach, others are skipped; a length of 0 ends the stream"""
    c, a = dvdctx(m, rng)
    sh = obj(m, rng, 'IOATIR500Shared', 0x100)
    cap = rng.choice([4, 16])
    tbl = m.alloc(4 * cap + 0x10)
    for i in range(cap):
        t = rng.choice([0, 0, rec(m, rng, 4)])
        if t: m.w32(m.r32(t + 0x14) + 0x10, rng.choice([1, 2, 3]))
        m.w32(tbl + 4 * i, t)
    m.w32(sh + 0x10, tbl); m.w32(sh + 0x14, cap); m.w32(c + 0x84, sh)
    for i in range(0x48 // 4): m.w32(c + 0x104 + 4 * i, rng.choice([0, 0, rec(m, rng, 4)]))
    hdr = m.alloc(0x400); fill_words(m, hdr, 0x400, rng); m.w32(c + 0xa4, hdr)
    ops = list(range(0x19, 0x3d)) + [0x00, 0x18, 0x3d, 0x40, 0xff]
    p = hdr + 0x1c
    for _ in range(rng.randrange(1, 14)):
        ln = rng.choice([1, 2, 2, 3])
        m.w32(p, (rng.choice(ops) << 24) | ln); m.w32(p + 4, rng.choice([0, 1, 2, cap - 1, cap, cap + 3]))
        p += 4 * ln
    m.w32(p, 0)
    return [c]


def start_mock(m, name, k):
    if 'IOATIR500DVDContext' in name and 'start' in name:
        return 0 if m.seed % 6 == 0 else 1
    if 'allocCommandBuffer' in name:                               # the Nth of the four IDCT buffers fails (N by seed), or none
        n = getattr(m, 'nalloc', 0); m.nalloc = n + 1
        return 0 if m.seed % 6 - 1 == n else 1
    if 'safeMetaCast' in name:
        return 0x20001230
    return new_mock(m, name, k)


def w_dvd_start(m, rng):
    c, a = dvdctx(m, rng)
    m.w32(c + 0xa4, m.alloc(0x100)); m.w32(a + 0xd4, m.alloc(0x40))
    return [c, a]


CASES += [
    Case('ATIR500DVDContext::read_regs', w_dvd_read_regs, ret='u32', seeds=80, plain_words=True),
    Case('ATIR500DVDContext::dvd_setup_subpicture', w_dvd_subpicture, ret='u32', seeds=40, mock=new_mock, plain_words=True),
    Case('ATIR500DVDContext::doIDCT', w_dvd_idct, ret='u32', seeds=120, mock=idct_mock, plain_words=True, ignore_args={'vtable slot +0x54c': [2]}),
    Case('ATIR500DVDContext::discard_command_buffer', w_dvd_discard, ret='void', seeds=150, mock=discard_mock, plain_words=True),
    Case('ATIR500DVDContext::start', w_dvd_start, ret='bool', seeds=60, mock=start_mock),
]


def w_dvd_cmft(m, rng):
    """types 0-3 go to the base class (mocked), 4/5 hand out one of two luma/chroma IDCT buffers and flip the toggle, anything else is refused"""
    c, a = dvdctx(m, rng)
    for tog in (0x164, 0x1a0): m.w32(c + tog, rng.choice([0, 1]))
    for base in (0x168, 0x184, 0x1a4, 0x1c0):
        m.w32(c + base + 8, plain(m, rng, 0x40)); m.w32(c + base + 0x10, rng.getrandbits(16))
        m.w32(c + base + 0x14, m.alloc(0x100)); m.w32(c + base + 0x18, rng.choice([0x1000, 0x80000]))
    m.w32(c + 0x150, rng.getrandbits(16))
    return [c, rng.choice([0, 1, 2, 3, 4, 4, 5, 5, 6, 9]), m.alloc(0x10), m.alloc(0x10)]


CASES += [
    Case('ATIR500DVDContext::clientMemoryForType', w_dvd_cmft, ret='u32', seeds=80, mock=new_mock, plain_words=True, ignore_args={'vtable slot +0x5ec': [2], 'vtable slot +0x14': [1, 2]}),
]


def io_start_mock(m, name, k):
    """IOUserClient::start (fails on some seeds), setup3D, getVRAMDescriptors, allocCommandBuffer, allocAllContextBuffers: each fails on its own seeds"""
    if 'IOUserClient5start' in name or 'IOUserClient::start' in name:
        return 0 if m.seed % 9 == 0 else 1
    if 'setup3D' in name:
        return 0 if m.seed % 9 == 1 else 1
    if 'getVRAMDescriptors' in name:
        return 0 if m.seed % 9 == 2 else 1
    if 'allocCommandBuffer' in name:
        return 0 if m.seed % 9 == 3 else 1
    if 'allocAllContextBuffers' in name:
        return 0 if m.seed % 9 == 4 else 1
    return new_mock(m, name, k)


def w_io_dvd_start(m, rng):
    c = obj(m, rng, 'ATIR500DVDContext', 0x400)
    a = accel(m, rng, mmio=False)
    m.w32(a + 0x68, rng.choice([0, 0, c])); m.w32(a + 0x60, rng.choice([0, 0, c])); m.w32(a + 0x73c, rng.randrange(0, 5))
    return [c, a]


CASES += [
    Case('IOATIR500DVDContext::start', w_io_dvd_start, ret='bool', seeds=90, mock=io_start_mock),
]
