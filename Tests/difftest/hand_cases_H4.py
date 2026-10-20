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
    if '+0x570' in name or '0x570' in name:
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
    if '+0xd0' in name or '+0x1cc' in name:      # an address of a mapped region (kernel mappings get stored into and indexed)
        return m.alloc(0x2100)
    if '+0x128' in name:
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
    if '+0x554' in name:
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
         ignore_args={'vtable slot +0x18': [1, 2], '+0x554': [2], '+0x524': [2], '+0x5ac': [2]}),
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
    if '+0x1cc' in name:
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
    if '+0x5ac' in name:
        return 0 if m.seed % 4 == 3 else 1
    if any(x in name for x in ('remove_dvd_context', 'prune_buffers', 'reset_req_bits', 'set_dvd_context', '+0x5a8')):
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
    Case('ATIR500DVDContext::doIDCT', w_dvd_idct, ret='u32', seeds=120, mock=idct_mock, plain_words=True, ignore_args={'+0x54c': [2]}),
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
    Case('ATIR500DVDContext::clientMemoryForType', w_dvd_cmft, ret='u32', seeds=80, mock=new_mock, plain_words=True, ignore_args={'+0x5ec': [2], '+0x14': [1, 2]}),
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


# ---- IOATIR500Accelerator ---------------------------------------------------------------------------------------------------------------------
def w_alloc_cmdbuf(m, rng):
    a = accel(m, rng, mmio=False)
    m.w32(a + 0x82c, rng.choice([0, 0x100]))
    return [a, m.alloc(0x40), rng.choice([0x1000, 0x80000])]


def cmdbuf_mock(m, name, k):
    if 'withOptions' in name:
        return 0 if m.seed % 4 == 0 else plain(m, random_for(m, k), 0x40)
    if '+0x1cc' in name:
        return m.alloc(0x100)
    if 'init_command_buffer_header' in name:
        return 0
    return new_mock(m, name, k)


def disp_mock(m, name, k):
    if 'IncrementAtomic' in name:
        return m.seed % 2
    if 'DecrementAtomic' in name:
        return 1 if (m.seed // 2) % 2 else 2
    if '+0x5b4' in name or '+0x5b8' in name:
        return 0 if (m.seed // 3) % 2 else 1
    if 'getVRAMDescriptor' in name or '+0x5' in name:
        return 0
    return new_mock(m, name, k)


def w_display_change(m, rng):
    a = accel(m, rng, mmio=False)
    return [a, 0x1234, plain(m, rng, 0x40), rng.choice([1, 2, 3, 4, 5, 9, 10, 11, 0, -1]), rng.choice([0, 0, 1, 0x10])]


def orphan_mock(m, name, k):
    if 'free_texvert' in name:                       # unlink the record from the orphan list, as the real one does
        r = m.uc.reg_read(UC_PPC_REG_4)
        p, n = m.r32(r + 0x24), m.r32(r + 0x28)
        m.w32(p + 0x28, n); m.w32(n + 0x24, p)
        return 0
    if '+0x554' in name:
        return 1 if (m.seed % 3) else 0
    if '+0x54c' in name:
        return 5 + m.seed % 3
    return new_mock(m, name, k)


def w_free_orphan(m, rng):
    a = accel(m, rng, mmio=False)
    m.w32(a + 0xb8, plain(m, rng, 0x40)); m.w8(a + 0x82, rng.choice([0, 1]))
    sentinel = a + 0x63c
    nodes = [rec(m, rng, rng.choice([3, 4, 5, 7, 3, 4, 2, 6])) for _ in range(rng.randrange(0, 5))]
    chain = [sentinel] + nodes + [sentinel]
    for i in range(1, len(chain) - 1):
        m.w32(chain[i] + 0x24, chain[i - 1]); m.w32(chain[i] + 0x28, chain[i + 1])
    m.w32(sentinel + 0x28, nodes[0] if nodes else sentinel); m.w32(sentinel + 0x24, nodes[-1] if nodes else sentinel)
    return [a, rng.choice([0, 1])]


CASES += [
    Case('IOATIR500Accelerator::allocCommandBuffer', w_alloc_cmdbuf, ret='bool', seeds=40, mock=cmdbuf_mock, plain_words=True),
    Case('IOATIR500Accelerator::display_change_handler', w_display_change, ret='u32', seeds=120, mock=disp_mock, plain_words=True,
         ignore_args={'getVRAMDescriptor': [2], '+0x5': [1, 2]}),
    Case('IOATIR500Accelerator::freeOrphanTexture', w_free_orphan, ret='void', seeds=120, mock=orphan_mock, plain_words=True,
         ignore_args={'+0x554': [2], '+0x54c': [2], '+300': [2], 'free_texvert': [2]}),
]


def stop_mock(m, name, k):
    """freeWaitToAllocGART & friends: every "did that free enough?" callee says no until the Nth one (N by seed), which says yes; seeds beyond the number
    of callees say no throughout"""
    if any(x in name for x in ('freeToAllocGART', 'freeTransferToAllocGART', '+0x5a8')):
        n = getattr(m, 'nfree', 0); m.nfree = n + 1
        return 1 if n == m.seed % 24 else 0
    if 'freeOrphanTexture' in name:
        return 0
    return new_mock(m, name, k)


def live_ctx(m, rng, cls, link, shared_off, n):
    nodes = []
    for _ in range(n):
        c = obj(m, rng, cls, 0x400)
        m.w32(c + link, 0)
        if shared_off:
            m.w32(c + shared_off, rng.choice([0, obj(m, rng, 'IOATIR500Shared', 0x100)]))
        nodes.append(c)
    for i in range(len(nodes) - 1): m.w32(nodes[i] + link, nodes[i + 1])
    return nodes


def w_free_wait(m, rng):
    a = accel(m, rng, mmio=False)
    sentinel = a + 0x63c
    m.w32(a + 0x664, rng.choice([sentinel, sentinel, a + 0x700]))
    c2 = live_ctx(m, rng, 'ATIR5002DContext', 0x80, 0x88, rng.choice([0, 1, 2]))
    cd = live_ctx(m, rng, 'ATIR500DVDContext', 0x80, 0x84, rng.choice([0, 1, 2]))
    cg = live_ctx(m, rng, 'ATIR500GLContext', 0x80, 0x88, rng.choice([0, 1, 2]))
    m.w32(a + 0x64, c2[0] if c2 else 0); m.w32(a + 0x68, cd[0] if cd else 0); m.w32(a + 0x60, cg[0] if cg else 0)
    ss = [obj(m, rng, 'IOATIR500Surface', 0xd00) for _ in range(rng.choice([0, 1, 2, 3]))]
    for i, s_ in enumerate(ss): m.w32(s_ + 0xa0, ss[(i + 1) % len(ss)])
    m.w32(a + 0x5c, ss[0] if ss else 0)
    m.w16(a + 0x402, rng.choice([0, 2, 4])); m.w16(a + 0x400, rng.randrange(0, 8))
    m.w16(a + 0x5c6, rng.choice([0, 2, 4])); m.w16(a + 0x5c4, rng.randrange(0, 8))
    prev = 0
    for _ in range(rng.choice([0, 1, 2])):
        d = m.alloc(0x100); m.w32(d + 0x3c, prev); m.w32(d + 0x5c, rng.getrandbits(8)); prev = d
    m.w32(a + 0x5cc, prev)
    sh = obj(m, rng, 'IOATIR500Shared', 0x100)
    ex2 = rng.choice([0, 0, c2[0] if c2 else 0, obj(m, rng, 'ATIR5002DContext', 0x400)])
    exd = rng.choice([0, 0, cd[0] if cd else 0, obj(m, rng, 'ATIR500DVDContext', 0x400)])
    exg = rng.choice([0, 0, cg[0] if cg else 0, obj(m, rng, 'ATIR500GLContext', 0x400)])
    exs = rng.choice([0, 0, ss[0] if ss else 0, obj(m, rng, 'IOATIR500Surface', 0xd00)])
    return [a, ex2, exd, exg, exs, rng.choice([0, 0, sh]), plain(m, rng, 0x40), rng.choice([0, 1])]


def w_free_transfer(m, rng):
    a = accel(m, rng, mmio=False)
    cand = m.alloc(0x80); fill_words(m, cand, 0x80, rng)
    m.w32(cand + 4, rng.choice([0, 0x1000])); m.w16(cand + 0xe, rng.choice([0, 0, 1]))
    return [a, cand, plain(m, rng, 0x40), rng.getrandbits(16), rng.choice([0, 1])]


def tmock(m, name, k):
    if '+0x554' in name:
        return m.seed % 2
    if '+0x54c' in name:
        return 3
    if '+0x5a8' in name:
        return (m.seed // 2) % 2
    return new_mock(m, name, k)


def w_remove_transfer(m, rng):
    a = accel(m, rng, mmio=False)
    if rng.random() < 0.15: return [a, 0]
    b = m.alloc(0x80); fill_words(m, b, 0x80, rng)
    m.w16(b + 0xc, rng.choice([4, 4, 2]))
    p, n = m.alloc(0x80), m.alloc(0x80)
    m.w32(b + 0x34, rng.choice([p, b])); m.w32(b + 0x38, rng.choice([n, b]))
    m.w32(b + 4, rng.choice([0, 0x2000])); m.w32(b + 8, rng.getrandbits(16))
    return [a, b]


CASES += [
    Case('IOATIR500Accelerator::freeWaitToAllocGART', w_free_wait, ret='bool', seeds=200, mock=stop_mock, plain_words=True, limit=300000,
         ignore_args={'+0x5a8': [2], 'freeTransferToAllocGART': [4]}),
    Case('IOATIR500Accelerator::freeTransferToAllocGART', w_free_transfer, ret='bool', seeds=60, mock=tmock, plain_words=True,
         ignore_args={'+0x554': [2], '+0x54c': [2], '+0x5ac': [2], '+0x5a8': [2]}),
    Case('IOATIR500Accelerator::removeTransferFromGART', w_remove_transfer, ret='void', seeds=40, mock=new_mock, plain_words=True),
]


def w_xfer_type(m, rng):
    a = accel(m, rng, mmio=False)
    b = m.alloc(0x80); fill_words(m, b, 0x80, rng)
    m.w16(b + 0xc, rng.choice([0, 1, 2, 3, 4, 5, 9]))
    return [a, b]


def fb_mock(m, name, k):
    if 'addFramebufferNotification' in name:
        return 0 if m.seed % 7 == 1 else 0x20000000 + m.seed
    if '+0x188' in name:
        return plain(m, random_for(m, k), 0x40)
    if '+0x218' in name:
        return 0 if m.seed % 7 == 2 else 1
    if 'getVRAMDescriptor' in name or '+0x160' in name or '+0x164' in name or '+0x16c' in name:
        return 0
    return new_mock(m, name, k)


def declare(m, slots):
    """argument kinds of virtual slots the ledger does not name ('this', 'p' pointer: compared by text/symbol when it points into the kext image, 'i' integer)"""
    for off, kinds in slots.items():
        m.reg.sig['vtable slot +0x%x' % off] = (len(kinds), kinds)


def w_found_fb(m, rng):
    declare(m, {0x160: ['this', 'p', 'p'], 0x164: ['this', 'p', 'p'], 0x16c: ['this', 'p', 'i', 'i', 'i'], 0x188: ['this', 'p'], 0x218: ['this', 'p', 'p', 'p']})
    a = accel(m, rng, mmio=False)
    n = rng.choice([0, 1, 2, 2])
    m.w32(a + 0xcc, n)
    known = [plain(m, rng, 0x400) for _ in range(2)]
    for i in range(2): m.w32(a + 0xd4 + 0x20 * i, known[i])
    fb = rng.choice([known[0], known[1], plain(m, rng, 0x400), plain(m, rng, 0x400)])
    return [a, fb]


def vram_mock(m, name, k):
    if '+0x5d0' in name:
        return 0 if m.seed % 5 == 1 else plain(m, random_for(m, k), 0x40)
    if '+0x150' in name:
        return 0 if m.seed % 5 == 2 else plain(m, random_for(m, k), 0x40)
    if '+0xd0' in name:
        return 0x40000000 + 0x1000 * (m.seed % 5)
    return new_mock(m, name, k)


def w_get_vram(m, rng):
    a = accel(m, rng, mmio=False)
    for i in range(2):
        m.w32(a + 0xd4 + 0x20 * i, plain(m, rng, 0x400)); m.w32(a + 0xdc + 0x20 * i, rng.choice([0, 0, plain(m, rng, 0x40)]))
    return [a, rng.choice([0, 1])]


CASES += [
    Case('IOATIR500Accelerator::mapVendorTransferBuffer', w_xfer_type, ret='bool', seeds=40, mock=new_mock, plain_words=True),
    Case('IOATIR500Accelerator::unmapVendorTransferBuffer', w_xfer_type, ret='void', seeds=40, mock=new_mock, plain_words=True),
    Case('IOATIR500Accelerator::foundFramebuffer', w_found_fb, ret='bool', seeds=120, mock=fb_mock, plain_words=True,
         ignore_args={'getVRAMDescriptor': [2], 'addFramebufferNotification': [3]}),
    Case('IOATIR500Accelerator::getVRAMDescriptor', w_get_vram, ret='u32', seeds=80, mock=vram_mock, plain_words=True,
         ignore_args={'+0x5d0': [1, 2], '+0x150': [2], '+0x18': [1, 2]}),
]


def vram_list_mock(m, name, k):
    """+0x528 (allocate texture VRAM for `needed`) says yes on its Nth call (N by seed); +0x554 (stamp retired?) alternates; tossSurfacesForVRAM frees
    nothing (0) or something (1); +0x524 pages a texture out"""
    if name.endswith('[vcall +0x528]') or '+0x528' in name:
        n = getattr(m, 'nvr', 0); m.nvr = n + 1
        return 1 if n == m.seed % 9 - 2 else 0
    if '+0x554' in name:
        n = getattr(m, 'nst', 0); m.nst = n + 1
        return (m.seed + n // 2) % 2
    if 'tossSurfacesForVRAM' in name:
        return 1 if m.seed % 11 == 4 else 0
    if '+0x524' in name:
        return 0
    return new_mock(m, name, k)


def vram_node(m, rng, a):
    n = m.alloc(0x80); fill_words(m, n, 0x80, rng)
    h = m.alloc(0x40); fill_words(m, h, 0x40, rng)
    m.w32(n + 0x14, rng.choice([h, h, h, 0]))
    m.w32(n + 0x48, rng.choice([0, 0x100, 0x100])); m.w8(h + 0x34, rng.choice([0, 1, 2, 3])); m.w8(h + 0x14, 0)
    m.w32(h + 8, rng.randrange(0, 0x400)); m.w32(h + 0xc, rng.getrandbits(8))
    for i in range(8):
        m.w16(h + 0x1c + 2 * i, rng.choice([0, 0xffff, 0x00ff, 0xff00])); m.w16(h + 0x28 + 2 * i, rng.choice([0, 0, 0xffff, 0x00ff, 0xff00]))
    return n


def w_free_tex_vram(m, rng):
    a = accel(m, rng, mmio=False)
    sentinel = a + 0x5dc
    nodes = [vram_node(m, rng, a) for _ in range(rng.randrange(0, 6))]
    chain = [sentinel] + nodes + [sentinel]
    for i in range(1, len(chain) - 1):
        m.w32(chain[i] + 0x24, chain[i - 1]); m.w32(chain[i] + 0x28, chain[i + 1])
    m.w32(sentinel + 0x28, nodes[0] if nodes else sentinel); m.w32(sentinel + 0x24, nodes[-1] if nodes else sentinel)
    m.w32(a + 0x21c, rng.choice([0, 0, 2]))
    surf = rng.choice([0, 0, obj(m, rng, 'IOATIR500Surface', 0xd00)])
    if surf: m.w32(surf + 0x84, rng.randrange(0, 0x800))
    ex = m.alloc(0x20)
    cnt = rng.choice([0, 0, 1, 2, 3])
    pool = nodes + [sentinel]
    for i in range(3): m.w32(ex + 4 * i, rng.choice(pool) if rng.random() < 0.6 else m.alloc(0x40))
    needed = m.alloc(0x80); m.w32(needed + 0x48, rng.choice([0, 0, 0x100]))
    return [a, surf, ex, cnt, needed]


CASES += [
    Case('IOATIR500Accelerator::freeToAllocTextureVRAM', w_free_tex_vram, ret='u32', seeds=600, mock=vram_list_mock, plain_words=True, limit=400000,
         ignore_args={'+0x528': [2], '+0x554': [2], '+0x524': [2], 'tossSurfacesForVRAM': [5]}),
]


def toss_mock(m, name, k):
    if '+0x528' in name:                       # allocating the needed texture's VRAM succeeded now: needed+0x48 becomes non-zero on some seeds
        n = getattr(m, 'ntoss', 0); m.ntoss = n + 1
        if n == m.seed % 7 - 1 and m.seed % 7 != 0: m.w32(m.needed + 0x48, 0x100)
        return 0
    if 'move_buffer_to_backing_store' in name or '+0x5cc' in name:
        return 0
    return new_mock(m, name, k)


def w_toss(m, rng):
    a = accel(m, rng, mmio=False)
    ss = []
    for _ in range(rng.choice([0, 1, 2, 3])):
        s_ = obj(m, rng, 'IOATIR500Surface', 0xd80)
        m.w32(s_ + 0xd48, rng.choice([0, 0, 1])); m.w32(s_ + 0xc14, rng.choice([0xffff, 0xffff, 3]))
        m.w32(s_ + 0xbcc, rng.choice([0, 0, 1])); m.w32(s_ + 0xbd0, rng.choice([0, 0, 0x10000]))
        m.w32(s_ + 0xb70, s_ + 0xa8 + 0x78 * rng.choice([0, 3, 9]))
        for i in range(23): m.w32(s_ + 0xa8 + 0x78 * i + 8, rng.choice([0, 0, 0x100]))
        ss.append(s_)
    for i, s_ in enumerate(ss): m.w32(s_ + 0xa0, ss[(i + 1) % len(ss)])
    m.w32(a + 0x5c, ss[0] if ss else 0)
    needed = m.alloc(0x80); m.w32(needed + 0x48, rng.choice([0, 0, 0, 0x100])); m.needed = needed
    ex = m.alloc(0x20)
    cnt = rng.choice([0, 1, 2, 3])
    for i in range(3):
        t = m.alloc(0x80); fill_words(m, t, 0x80, rng); m.w8(t + 0x20, rng.choice([0, 0, 1])); m.w32(t + 0x50, rng.choice(ss + [0]) if ss else 0)
        m.w32(ex + 4 * i, rng.choice([t, t, 0]))
    return [a, rng.choice([0] + ss + [obj(m, rng, 'IOATIR500Surface', 0x400)]), ex, cnt, needed, rng.choice([0, 1])]


CASES += [
    Case('IOATIR500Accelerator::tossSurfacesForVRAM', w_toss, ret='u32', seeds=300, mock=toss_mock, plain_words=True,
         ignore_args={'+0x528': [2], '+0x5cc': [2], 'move_buffer_to_backing_store': [2]}),
]


def uc_mock(m, name, k):
    if 'withCapacity' in name:
        return 0 if m.seed % 8 == 1 else plain(m, random_for(m, k), 0x40)
    if any(x in name for x in ('+0x5d4', '+0x5dc', '+0x5d8', '+0x5e0', 'vtable function')):
        return 0 if m.seed % 8 == 2 else m.client
    if '+0x150' in name:
        return 0 if m.seed % 8 == 3 else 1
    if '+0x3a4' in name:
        return 0 if m.seed % 8 == 4 else 1
    if '+0x348' in name:
        return 0 if m.seed % 8 == 5 else 1
    return new_mock(m, name, k)


def w_new_user_client(m, rng):
    declare(m, {0x5d4: ['this'], 0x5d8: ['this'], 0x5dc: ['this'], 0x5e0: ['this'], 0x150: ['this', 'p'], 0x3a4: ['this', 'p'], 0x348: ['this', 'p'], 0x3a8: ['this', 'p'], 300: ['this', 'p', 'p']})
    a = accel(m, rng, mmio=False)
    m.client = plain(m, rng, 0x100)
    return [a, plain(m, rng, 0x40), plain(m, rng, 0x40), rng.choice([0, 1, 2, 3, 3, 4, 9]), m.alloc(0x10)]


def stereo_mock(m, name, k):
    if '+0x56c' in name or '+0x5cc' in name:
        return 0 if (m.seed + k) % 3 else 1
    if 'freeToAllocSurfaceVRAM' in name:
        return 0 if m.seed % 4 == 1 else 1
    if 'dealloc' in name or 'freeAllSwapBuffers' in name or 'allocMasterSwapBuffer' in name or 'allocAllSlaveSwapBuffers' in name or '+0x54c' in name:
        return 0
    return new_mock(m, name, k)


def w_setup_stereo(m, rng):
    a = accel(m, rng, mmio=False)
    m.w8(a + 0x81, rng.choice([0, 0, 0, 1]))
    for p in range(2):
        m.w32(a + 0x11c + 4 * p, rng.choice([0, 1, 2, 3])); m.w32(a + 0x114 + 4 * p, rng.choice([1, 2])); m.w32(a + 0x1ac + 0x78 * p, rng.choice([0, 0, 0x1000]))
    ss = [obj(m, rng, 'IOATIR500Surface', 0x400) for _ in range(rng.choice([0, 1, 2]))]
    for i, s_ in enumerate(ss): m.w32(s_ + 0x9c, ss[(i + 1) % len(ss)])
    m.w32(a + 0x5c, ss[0] if ss else 0); m.w32(a + 0x7c, obj(m, rng, 'ATIR500Memory', 0x40))
    return [a, rng.choice([0, 1]), rng.choice([0, 1, 2, 3])]


CASES += [
    Case('IOATIR500Accelerator::newUserClient', w_new_user_client, ret='u32', seeds=120, mock=uc_mock, plain_words=True,
         ignore_args={'vtable slot +0x18': [1, 2], '+0x5': [1, 2], '+0x150': [2], '+0x3a4': [2], '+0x348': [2], '+0x3a8': [2], 'withCapacity': [1]}),
    Case('IOATIR500Accelerator::setup_stereo', w_setup_stereo, ret='u32', seeds=150, mock=stereo_mock, plain_words=True,
         ignore_args={'+0x56c': [2], '+0x54c': [2], '+0x5cc': [3], 'memcpy': [3]}),
]


def w_reserve_gart(m, rng):
    a = accel(m, rng, mmio=False)
    tbl = m.alloc(0x4100); fill_words(m, tbl, 0x4100, rng)
    empty = rng.choice([0, 0x0badf00d, 0xdead0000])
    m.w32(a + 0x83c, tbl); m.w32(a + 0x844, empty); m.w32(a + 0x848, rng.choice([1, 2]))
    idx = rng.randrange(0, 0x100)
    if rng.random() < 0.5: m.w32(tbl + 4 * idx, empty)
    return [a, idx << 12 | rng.choice([0, 0x234])]


def collector_mock(m, name, k):
    if 'free_gart_wirings' in name or '+300' in name:
        return 0
    return new_mock(m, name, k)


def w_gart_collector(m, rng):
    a = accel(m, rng, mmio=False)
    m.w32(a + 200, rng.choice([0, 0, 0, 1]))
    m.w32(a + 0xa0, rng.choice([0x1000, 0x100000])); m.w32(a + 0xa4, rng.choice([0, 0x800, 0x200000]))
    m.w8(a + 0x88, rng.choice([0, 1])); m.w8(a + 0x89, rng.choice([0, 1, 1]))
    m.w32(a + 0xc0, plain(m, rng, 0x40)); m.w32(a + 0x8c, rng.getrandbits(8))
    return [a, plain(m, rng, 0x40), 0]


def w_teardown_agp(m, rng):
    a = accel(m, rng, mmio=False)
    m.w32(a + 0x83c, rng.choice([0, m.alloc(0x40)])); m.w32(a + 0x830, rng.choice([0x1000, 0x4000]))
    m.w32(a + 0x7fc, rng.randrange(0x10000, 0x100000))
    m.w32(a + 0x74, rng.choice([0, plain(m, rng, 0x40)])); m.w32(a + 0x98, rng.choice([0, 2, 3, 1]))
    return [a, plain(m, rng, 0x40)]


def ser_mock(m, name, k):
    if 'safeMetaCast' in name:
        return 0 if m.seed % 4 == 0 else m.uc.reg_read(UC_PPC_REG_3)
    if 'withCapacity' in name:
        return 0 if m.seed % 4 == 1 else plain(m, random_for(m, k), 0x40)
    if '+0x1c' in name:
        return m.seed % 2
    return new_mock(m, name, k)


def w_serialize(m, rng):
    declare(m, {0x568: ['this', 'p']})
    a = accel(m, rng, mmio=False)
    return [a, a, 0, plain(m, rng, 0x40)]


CASES += [
    Case('IOATIR500Accelerator::reserveInGART', w_reserve_gart, ret='bool', seeds=60, mock=new_mock, plain_words=True),
    Case('IOATIR500Accelerator::gart_collector', w_gart_collector, ret='void', seeds=60, mock=collector_mock, plain_words=True,
         ignore_args={'+300': [2], 'free_gart_wirings': [1]}),
    Case('IOATIR500Accelerator::teardownAGP', w_teardown_agp, ret='void', seeds=60, mock=new_mock, plain_words=True,
         ignore_args={'+0x5e0': [1, 2], 'IOFreeContiguous': []}),
    Case('IOATIR500Accelerator::serializePerformanceStats', w_serialize, ret='bool', seeds=60, mock=ser_mock, plain_words=True,
         ignore_args={'+0x1c': [2], '+0x18': [1, 2], 'withCapacity': [1]}),
]


def accel_start_mock(m, name, k):
    """IOATIR500Accelerator::start: the fatal steps (IOAccelerator::start, workLoop, the PCI cast, IOLockAlloc, slot 0x580, the memory manager's init, the
    command buffer, findFramebuffers) are numbered in call order and the N-th one fails (N = seed % 14, so seeds 0-10 each break a different step and the
    rest run to the end); the non-fatal ones (event sources, properties, registry strings) vary with the seed"""
    r3, r4, r5, r6 = (m.uc.reg_read(r) for r in (UC_PPC_REG_3, UC_PPC_REG_4, UC_PPC_REG_5, UC_PPC_REG_6))
    def fatal():
        n = getattr(m, 'nfatal', 0); m.nfatal = n + 1
        return n == m.seed % 14
    obj_ = lambda: plain(m, random_for(m, k), 0x100)
    if 'IOAccelerator5start' in name or 'IOAccelerator::start' in name:
        return 0 if fatal() else 1
    if 'sysctlbyname' in name:
        if m.seed % 5 == 3: return 1
        m.uc.mem_write(r4, bytes([0, 0, 0, 0, 0, 0, 0, 0x80 if m.seed % 2 else 0x20])); return 0
    if 'IOWorkLoop' in name:
        return 0 if fatal() else obj_()
    if 'interruptEventSource' in name or 'timerEventSource' in name:
        return 0 if (m.seed + k) % 5 == 0 else obj_()
    if 'safeMetaCast' in name:
        if 'IOPCIDevice' in name or True:
            n = getattr(m, 'ncast', 0); m.ncast = n + 1
            if n == 3: return 0 if fatal() else r3                  # the provider cast to IOPCIDevice
            return 0 if (m.seed + n) % 4 == 0 else r3
    if 'IOLockAlloc' in name:
        return 0 if fatal() else m.alloc(0x40)
    if '+0x580' in name:
        if m.seed % 3 == 0: m.w32(m.accel + 0x98, 1)             # hardware capability bit 0: the GART warm-up loop
        return 0 if fatal() else 1
    if '+0x188' in name:
        return 0 if (m.seed + k) % 3 == 0 else obj_()
    if '+0xe8' in name:
        return 1500 + 7 * m.seed
    if '+0x48' in name:
        return 0 if fatal() else 1
    if 'allocCommandBuffer' in name:                          # fills the VendorCommandBuffer at r4: its descriptor (+8) is used by the GART warm-up loop
        if fatal(): return 0
        m.w32(r4 + 8, obj_()); return 1
    if 'findFramebuffers' in name:
        return 0 if fatal() else 1
    if 'forTarget' in name:
        return 0 if m.seed % 6 == 2 else obj_()
    if 'getRegistryRoot' in name:
        return 0 if m.seed % 7 == 4 else obj_()
    if 'sscanf' in name:
        m.w32(r5, 5 if m.seed % 3 else 9); m.w32(r6, 2); return 2 if m.seed % 8 else 1
    if '+0x100' in name:
        w = m.alloc(0x10); m.w32(w, 0x10 if m.seed % 2 else 0); return w
    if 'operator new' in name or 'nwEm' in name:
        return 0 if m.seed % 9 == 7 else m.alloc(0x20)
    return new_mock(m, name, k)


def w_accel_start(m, rng):
    declare(m, {0x188: ['this', 'p'], 0x160: ['this', 'p', 'p'], 0x16c: ['this', 'p', 'i', 'i', 'i'], 0x588: ['this', 'p', 'i', 'i'], 0x144: ['this', 'i'],
                0x55c: ['this', 'i'], 0x564: ['this', 'i'], 0xe4: ['this', 'p'], 0xec: ['this']})
    a = accel(m, rng, mmio=False)
    m.accel = a
    m.w32(a + 0x83c, 0); m.w32(a + 0x830, rng.choice([0, 0x10, 0x4000]))
    m.w32(a + 0x8b0, plain(m, rng, 0x40)); m.w32(a + 0x22c, plain(m, rng, 0x40))
    return [a, plain(m, rng, 0x100)]


CASES += [
    Case('IOATIR500Accelerator::start', w_accel_start, ret='bool', seeds=200, mock=accel_start_mock, plain_words=False, limit=600000,
         ignore_args={'sysctlbyname': [], 'IOWorkLoop': [], 'interruptEventSource': [], 'timerEventSource': [], 'sscanf': [3, 4, 5], 'vtable slot +0x18': [1, 2],
                      '+0xe4': [2], '+0xec': [1, 2], '+0x580': [2], '+0x48': [1, 2], 'stop': [1]}),
]


def finish_mock(m, name, k):
    if '+0x55c' in name:                          # waitForTimeStamp: -1 = failed, else the time waited
        return 0xffffffff if m.seed % 3 == 0 else m.seed * 5
    return new_mock(m, name, k)


def w_dvd_finish(m, rng):
    c, a = dvdctx(m, rng)
    m.w32(c + 0x7c, rng.getrandbits(16)); m.w32(a + 0x7ac, rng.randrange(0, 1000))
    return [c]


CASES += [
    Case('IOATIR500DVDContext::finish', w_dvd_finish, ret='u32', seeds=30, mock=finish_mock, plain_words=True, ignore_args={'+0x55c': [2]}),
]
