"""Hand-written worlds (fork H5 of the hand-world push): the GL / 2D / DVD context functions whose best difftest case reached under 90% coverage.
Each world lays out the objects a function works on from the stock disassembly so that every branch of the function is reachable; field offsets are in each
builder's docstring. Run: python3 Tools/difftest/difftest.py [-f NAME] Tests/difftest/hand_cases_H5.py   (needs STOCK_KEXT; see Tools/difftest/README.md)"""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from common import word, fill_words, make_pool, accelerator_object, soup_words, object_with_vtable, R500Registers
import hand_cases_C as C
import hand_cases_D as D
from hand_cases_C import gl_context, chain, scripted_mock, script, texture_obj, vobj

CASES = []


def small_words(rng, n=1):
    return rng.choice([0, 0, 1, 2, 3, 4, 8, 0x10, 0x20, 0x40, 0x100, 0x3ff, 0x400, 0xffff])


def w_2d_get_buffer_info(m, rng):
    """ATIR5002DContext::get_buffer_info(this, surface, index, info, infoSize): this+0x94 the accelerator (entries of 0x78 bytes from +0x12c: width +0x148,
    height +0x14a, +0x134 packed word, divisors +0x144/+0x142); surface+0xb70 the attachment record, surface+0xbe4/+0xbe6 the region; infoSize must point at 0x30"""
    this = m.alloc(0x200); fill_words(m, this, 0x200, rng)
    accel = m.alloc(0x400); fill_words(m, accel, 0x400, rng)
    m.w32(this + 0x94, accel)
    for i in range(3):                                   # three accelerator entries: divisors zero / nonzero, second divisor zero / nonzero
        e = accel + i * 0x78
        m.uc.mem_write(e + 0x142, struct.pack('>HH', rng.choice([0, 1, 2, 3, 7]), rng.choice([0, 1, 2, 5, 16])))
        m.uc.mem_write(e + 0x148, struct.pack('>HH', small_words(rng), small_words(rng)))
        m.w32(e + 0x134, rng.choice([0, 0x7, 0x3ff, 0x400, 0x12345, 0xffffffff, word(rng)]))
    surf = 0
    if rng.random() < 0.5:
        surf = m.alloc(0xc00); fill_words(m, surf, 0xc00, rng)
        rec = m.alloc(0x100); fill_words(m, rec, 0x100, rng)
        m.uc.mem_write(rec + 0x14, struct.pack('>HH', small_words(rng), rng.choice([0, 1, 2, 3, 0x100])))
        m.w32(surf + 0xb70, rec)
        m.uc.mem_write(surf + 0xbe4, struct.pack('>hh', rng.choice([0, 5, -3, 0x7fff, -0x8000]), rng.choice([0, 9, -1, 0x1234])))
    info = m.alloc(0x40)
    size = m.alloc(8); m.w32(size, rng.choice([0x30, 0x30, 0x30, 0x2f, 0, 0x31]))
    return [this, surf, rng.choice([0, 1, 2]), info, size]



def h5_mock(m, name, k):
    """scripted callee returns (hand_cases_C.script) first, then the hand_cases_D mock (allocations, IOKit virtuals), then the harness default; plus the
    side effects the worlds below need: IOLockSleep wakes the accelerator (sets its 'hardware alive' byte), wait-for-stamp style virtuals can fail with -1"""
    if 'IOLockSleep' in name and getattr(m, 'h5_accel', 0):
        m.w8(m.h5_accel + 0x80, 1)
        return 0
    if 'surface_buffer_idx_mask' in name:                  # (surface, index, UInt32 *mask): the callee fills in the mask word
        from unicorn.ppc_const import UC_PPC_REG_5
        out = m.uc.reg_read(UC_PPC_REG_5)
        if out > 0x1000:
            m.w32(out, [0, 1, 0x7fffff, 0x20000000, 0x1234, 0x40000][(m.seed + k) % 6])
        return 0
    for key, q in getattr(m, 'script', {}).items():
        if key in name:
            n = m.script_n.setdefault(key, 0); m.script_n[key] = n + 1
            if n < len(q): return q[n](m) if callable(q[n]) else q[n]
    return D.new_mock(m, name, k)


def surf2d(m, rng, A):
    """the surface a 2D context is bound to (ATIR500Surface, 0x1000 bytes): +0xa4 pending count, +0xb70 the buffer record (+0x1c width, +0x16 bytes per pixel,
    +0x24 backing object whose +8 is a memory object and +0x59 a flag byte), +0xbd2 lock count, +0xbe8 mode bits, +0xbf4 has-memory, +0xbf8/+0xc1c state bits,
    +0xbfc stamp, +0xc00 the backing IOMemoryDescriptor"""
    S = D.obj(m, rng, 'ATIR500Surface', 0x1000)
    rec = D.obj(m, rng, 'ATIR500Surface', 0x100)
    owner = D.plain(m, rng, 0x100)
    m.w32(rec + 0x24, rng.choice([0, owner, owner]))
    m.w32(owner + 8, D.plain(m, rng, 0x100))
    m.w16(rec + 0x1c, rng.choice([0, 64, 640])); m.w16(rec + 0x16, rng.choice([1, 2, 4]))
    m.w32(S + 0xb70, rec)
    m.w32(S + 0xa4, rng.choice([0, 1, 0xff, 0x100, 0x200]))
    m.w32(S + 0xbf8, rng.choice([0, 0x1, 0x20000000, 0x20000001, 0x10000000]))
    m.w32(S + 0xc1c, rng.choice([0, 1, 0x20000000]))
    m.w32(S + 0xbfc, rng.choice([0, 1, 2, 3, 0x1234]))
    m.w32(S + 0xbe8, rng.choice([0, 1, 0xf, 0x803f]))
    m.w8(S + 0xbf4, rng.choice([0, 1, 1]))
    m.w16(S + 0xbd2, rng.choice([0, 1, 2]))
    m.w32(S + 0xc00, D.plain(m, rng, 0x100))
    return S


def ctx2d_bound(m, rng, bound=0.9):
    c, A = D.ctx2d(m, rng, 'IOATIR5002DContext' if False else 'ATIR5002DContext')
    m.h5_accel = A
    m.w8(A + 0x80, rng.choice([1, 1, 1, 0]))
    S = surf2d(m, rng, A) if rng.random() < bound else 0
    m.w32(c + 0x100, S)
    m.w32(c + 0x8c, rng.choice([0, 1, 0x20000000, 0x20000001]))
    return c, A, S


def alloc_script(m, rng):
    """what IOATIR500Surface::alloc_surfaces returns over a run: success at once, hard failure (2), retry then success, or 1000+ retries (the retry loops end at
    tries==1000 with one last alloc_surfaces(1, true))"""
    k = rng.randrange(6)
    q = [[0], [2], [1, 0], [1, 1, 1, 0], [1] * 1001 + [0], [1] * 1001 + [1]][k]
    script(m, 'alloc_surfaces', q)


def w_2d_swap_surface(m, rng):
    c, A, S = ctx2d_bound(m, rng)
    alloc_script(m, rng)
    return [c, rng.choice([0, 1, 0x80000000]), m.alloc(8)]


def w_2d_lock_memory(m, rng):
    c, A, S = ctx2d_bound(m, rng)
    alloc_script(m, rng)
    if S:
        m.w32(c + 0x118, rng.choice([0, D.plain(m, rng), D.plain(m, rng)]))
        m.w32(c + 0x104, rng.choice([0, m.r32(S + 0xc00), m.r32(S + 0xc00), 0x1234]))
    m.w32(c + 0x11c, rng.choice([0, 0x100, 0x2000]))
    out = m.alloc(0x40)
    return [c, rng.choice([0, 1, 2]), out, out + 0x20]


def w_2d_unlock_memory(m, rng):
    c, A, S = ctx2d_bound(m, rng, bound=0.8)
    alloc_script(m, rng)
    return [c, rng.choice([0, 1, 0x80000000, 0x80000001]), m.alloc(8)]


def w_2d_create_transfer(m, rng):
    c, A, S = ctx2d_bound(m, rng, bound=0.7)
    sh = D.obj(m, rng, 'IOATIR500Shared', 0x400)
    m.w32(c + 0x88, rng.choice([0, sh, sh]))
    script(m, 'new_agp_texture', [rng.choice([0, 0, D.plain(m, rng, 0x100)])])
    tex = D.plain(m, rng, 0x100)
    m.w32(tex + 8, D.plain(m, rng, 0x100))
    script(m, 'new_agp_texture', [rng.choice([0, tex, tex])])
    script(m, 'create_shared', [rng.choice([0, 1, 1])])
    return [c, rng.choice([0, 1, 0xf, 0x10, 0x803f]), rng.choice([0, 0x100, 0x2000, 0x10]), m.alloc(8), m.alloc(8)]


def shared_table(m, rng, n=4):
    """an IOATIR500Shared as delete_image sees it: +0x14 handle capacity, +0x10 the handle table of VendorTextureBuffer pointers (+8 memory object)"""
    sh = D.obj(m, rng, 'IOATIR500Shared', 0x400)
    arr = m.alloc(0x40)
    texs = []
    for i in range(n):
        t = D.plain(m, rng, 0x100)
        texs.append(t)
        m.w32(arr + 4 * i, rng.choice([0, t, t]))
    m.w32(sh + 0x10, arr); m.w32(sh + 0x14, n)
    return sh, arr, texs


def w_2d_declare_image(m, rng):
    c, A = D.ctx2d(m, rng)
    m.w32(c + 0x88, rng.choice([0, D.obj(m, rng, 'IOATIR500Shared', 0x400), D.obj(m, rng, 'IOATIR500Shared', 0x400)]))
    script(m, 'create_shared', [rng.choice([0, 1])])
    script(m, 'new_agp_texture', [rng.choice([0, D.plain(m, rng, 0x100)])])
    return [c, rng.choice([0, 1]), rng.choice([0, 0x1000, 0x2000]), rng.choice([0, 0, 0x100000, 0x200000]), m.alloc(8)]


def w_2d_delete_image(m, rng):
    c, A, S = ctx2d_bound(m, rng, bound=0.7)
    sh, arr, texs = shared_table(m, rng)
    m.w32(c + 0x88, rng.choice([0, sh, sh, sh]))
    tid = rng.choice([0, 1, 2, 3, 4, 5, 0xffffffff])
    m.w32(c + 0x114, rng.choice([0, texs[tid] if tid < 4 else 0, texs[0]]))
    if S:
        rec = m.r32(S + 0xb70)
        back = m.r32(rec + 0x24)
        if back and tid < 4 and rng.random() < 0.7:
            m.w32(back + 8, m.r32(texs[tid] + 8))        # the buffer's backing is this texture's memory
    return [c, tid]


def w_2d_finish(m, rng):
    c, A = D.ctx2d(m, rng)
    m.w32(A + 0x50, rng.choice([0, 1, 5]))
    script(m, 'sleepForTimeStamp', [rng.choice([0xffffffff, 0, 7, 0xffffffff])])
    return [c, rng.choice([0, 1, 2, 3, 0xffffffff])]


CASES += [
    Case('IOATIR5002DContext::swap_surface', w_2d_swap_surface, ret='u32', seeds=150, mock=h5_mock, plain_words=True, limit=600000, ignore_args=D.REL, name='swap_surface (hand world)'),
    Case('IOATIR5002DContext::lock_memory', w_2d_lock_memory, ret='u32', seeds=150, mock=h5_mock, plain_words=True, limit=600000, ignore_args=D.REL, name='lock_memory (H5 hand world)'),
    Case('IOATIR5002DContext::unlock_memory', w_2d_unlock_memory, ret='u32', seeds=80, mock=h5_mock, plain_words=True, limit=600000, ignore_args=D.REL),
    Case('IOATIR5002DContext::create_transfer', w_2d_create_transfer, ret='u32', seeds=100, mock=h5_mock, plain_words=True, ignore_args=D.REL),
    Case('IOATIR5002DContext::declare_image', w_2d_declare_image, ret='u32', seeds=60, mock=h5_mock, plain_words=True, ignore_args=D.REL),
    Case('IOATIR5002DContext::delete_image', w_2d_delete_image, ret='u32', seeds=100, mock=h5_mock, plain_words=True, ignore_args=D.REL),
    Case('IOATIR5002DContext::finish', w_2d_finish, ret='u32', seeds=60, mock=h5_mock, plain_words=True, ignore_args=D.REL),
]


def make_alloc_all_world(cls, accel_off, nbuf):
    """allocAllContextBuffers(size) of the 2D (2 buffers), DVD (2) and GL (16) context: IOBufferMemoryDescriptor::withOptions is scripted to succeed for the
    context-buffer descriptor and then for `k` of the per-buffer descriptors before one fails (k == nbuf: all succeed; -1: the very first fails)"""
    def world(m, rng):
        c = D.obj(m, rng, cls, 0x1000)
        A = D.accel(m, rng, mmio=False)
        m.w32(c + accel_off, A)
        m.w32(A + 0x82c, rng.choice([0, 0x400, 0x1000]))
        k = rng.choice([-1, 0, 1, nbuf - 1, nbuf, nbuf // 2, nbuf])
        k = min(k, nbuf)
        q = [] if k < 0 else [D.plain(m, rng, 0x100)]
        if k >= 0:
            q += [D.plain(m, rng, 0x100) for _ in range(k)]
            if k < nbuf: q.append(0)
        else: q = [0]
        script(m, 'withOptions', q)
        return [c, rng.choice([0x1000, 0x2000, 0x10000])]
    return world


def w_2d_alloc_and_load_image(m, rng):
    """ATIR5002DContext::alloc_and_load_image(texture): texture +0x20 kind (3 = image, 4 = other), +4 GART offset (0 -> map_transfer_to_GART first, scripted to
    set it), +0x2c time stamp, +0x34/+0x38 list links (a ring of itself), +0x48 VRAM offset, +0x14 header (+0x14 flag byte); accelerator +0x6d0 / +0x69c
    list, freeToAllocTextureVRAM / vtable +0x528 results scripted"""
    c, A = D.ctx2d(m, rng, 'ATIR5002DContext')
    m.w32(c + 0x100, rng.choice([0, D.obj(m, rng, 'ATIR500Surface', 0x1000)]))
    t = D.plain(m, rng, 0x100)
    m.w8(t + 0x20, rng.choice([3, 3, 4, 4, 1, 0]))
    m.w32(t + 4, rng.choice([0, 0x1000]))
    m.w32(t + 0x48, rng.choice([0, 0, 0x2000]))
    hdr = D.plain(m, rng, 0x40); m.w32(t + 0x14, hdr)
    m.w32(t + 0x34, t); m.w32(t + 0x38, t)
    ring = D.plain(m, rng, 0x100)
    m.w32(A + 0x6d0, ring); m.w32(ring + 0x38, ring); m.w32(ring + 0x34, ring)
    script(m, 'freeToAllocTextureVRAM', [rng.choice([0, 1])])
    script(m, 'vtable slot +0x528', [rng.choice([0, 1])])
    return [c, t]



CASES += [
    Case('IOATIR5002DContext::allocAllContextBuffers', make_alloc_all_world('IOATIR5002DContext', 0x94, 2), ret='bool', seeds=60, mock=h5_mock, plain_words=True, ignore_args=D.REL),
    Case('IOATIR500GLContext::allocAllContextBuffers', make_alloc_all_world('IOATIR500GLContext', 0xc8, 16), ret='bool', seeds=100, mock=h5_mock, plain_words=True, ignore_args=D.REL),
    Case('IOATIR500DVDContext::allocAllContextBuffers', make_alloc_all_world('IOATIR500DVDContext', 0x8c, 2), ret='bool', seeds=60, mock=h5_mock, plain_words=True, ignore_args=D.REL),
    Case('ATIR5002DContext::alloc_and_load_image', w_2d_alloc_and_load_image, ret='void', seeds=100, mock=h5_mock, plain_words=True, ignore_args=D.REL),
]


STOP_REAL = D.DEFAULT_TRANSPARENT if hasattr(D, 'DEFAULT_TRANSPARENT') else r'(C[12]E|D[012]E)'


def w_start_common(cls, list_head_off, count_off, extra=None, accel_gl_list=False):
    """start(provider): IOUserClient::start result, the accelerator's live-context list head (an existing context skips the first-context setup), the
    setup2D/setup3D result and the three allocation results are scripted so every exit of the function is taken; the clean-up path calls stop(), which the
    case runs for real on both sides (the rebuilt start() inlines it)"""
    def world(m, rng):
        c = D.obj(m, rng, cls, 0x1000)
        A = D.accel(m, rng, mmio=False)
        m.h5_accel = A
        m.w32(A + list_head_off, rng.choice([0, 0, D.obj(m, rng, cls, 0x400)]))
        if accel_gl_list: m.w32(A + 0x60, rng.choice([0, 0, D.obj(m, rng, 'IOATIR500GLContext', 0x400)]))
        m.w32(A + count_off, rng.choice([0, 1, 3]))
        script(m, 'IOUserClient5start', [rng.choice([1, 1, 1, 1, 0])])
        script(m, 'setup2D', [rng.choice([1, 1, 0])]); script(m, 'setup3D', [rng.choice([1, 1, 0])])
        script(m, 'getVRAMDescriptors', [rng.choice([1, 1, 0])])
        script(m, 'allocCommandBuffer', [rng.choice([1, 1, 0])])
        script(m, 'allocAllContextBuffers', [rng.choice([1, 1, 0])])
        if extra: extra(m, rng, c, A)
        return [c, A]
    return world


def w_dvd_idct_start(m, rng):
    """ATIR500DVDContext::start(provider): provider (the accelerator) +0x840 the lock, +0xd4 the first framebuffer (safeMetaCast result), IOATIR500DVDContext::start
    and the four IDCT command-buffer allocations scripted"""
    c = D.obj(m, rng, 'ATIR500DVDContext', 0x1000)
    A = D.accel(m, rng, mmio=False)
    m.w32(c + 0x8c, A)
    m.w32(c + 0xf4, 0)
    hdr = D.plain(m, rng, 0x100); m.w32(c + 0xac, hdr) if False else None
    script(m, 'IOATIR500DVDContext5start', [rng.choice([1, 1, 1, 0])])
    script(m, 'allocCommandBuffer', [rng.choice([1, 1, 1, 0])] + [rng.choice([1, 1, 0]) for _ in range(3)])
    m.w32(A + 0xd4, rng.choice([0, D.plain(m, rng, 0x100)]))
    return [c, A]


CASES += [
    Case('IOATIR5002DContext::start', w_start_common('IOATIR5002DContext', 0x64, 0x734), ret='bool', seeds=120, mock=h5_mock, ignore_args=D.REL,
         transparent=r'(C[12]E|D[012]E|IOATIR5002DContext4stop)', name='IOATIR5002DContext::start (hand world)'),
    Case('IOATIR500DVDContext::start', w_start_common('IOATIR500DVDContext', 0x68, 0x73c, accel_gl_list=True), ret='bool', seeds=120, mock=h5_mock, ignore_args=D.REL,
         transparent=r'(C[12]E|D[012]E|IOATIR500DVDContext4stop)', name='IOATIR500DVDContext::start (hand world)'),
    Case('ATIR500DVDContext::start', w_dvd_idct_start, ret='bool', seeds=80, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='ATIR500DVDContext::start (hand world)'),
]


def stream_texture(m, rng, with_map=True):
    """a VendorTextureBuffer as a command-buffer discard walk touches it: +0x14 header (+0x10 outstanding count, +0x14 flag byte), +0xe use count, +0x20 kind
    byte, +0x48 VRAM offset, +0x54 a record whose +8 is an IOMemoryDescriptor (map() gives a mapping object), +0x64 a word"""
    t = D.plain(m, rng, 0x100)
    hdr = D.plain(m, rng, 0x40)
    m.w32(hdr + 0x10, rng.choice([1, 1, 2, 0x10001, 0xffff, 5]))
    m.w32(t + 0x14, hdr)
    m.w16(t + 0xe, rng.choice([0, 1, 5]))
    m.w8(t + 0x20, rng.choice([7, 7, 3, 1]))
    m.w32(t + 0x48, rng.choice([0, 0, 0x1000]))
    m.w32(t + 0x64, rng.choice([0, 1, 0x20]))
    rec = D.plain(m, rng, 0x40)
    m.w32(rec + 8, D.plain(m, rng, 0x100))
    m.w32(t + 0x54, rec if with_map or rng.random() < 0.8 else 0)
    return t


def packets(m, rng, ops, make, n_packets=(1, 6), words=12):
    """a command-buffer stream of `words`-word packets: header = opcode<<24 | words, the operands filled by make(m, rng, op, base_address); ends with an empty
    header (the walk stops when a packet has no length)"""
    k = rng.randint(*n_packets)
    buf = m.alloc((k + 2) * words * 4 + 0x40)
    fill_words(m, buf, (k + 2) * words * 4 + 0x40, rng)
    for i in range(k):
        base = buf + 0x1c + i * words * 4
        op = rng.choice(ops)
        m.w32(base, (op << 24) | words)
        make(m, rng, op, base)
    m.w32(buf + 0x1c + k * words * 4, rng.choice([0, 0x01000000, 0x40000000]))
    return buf


GL_DISCARD_OPS = list(range(6, 0x16)) + list(range(0x16, 0x25)) + [0x26, 0x27, 0x29, 0x36, 0x39, 0x3a, 0x3b, 0x3d, 0x01, 0x40]


def w_gl_discard(m, rng):
    """ATIR500GLContext::discard_command_buffer(): this+0xe0 the command-buffer header (+0x1c the packet stream), this+0x88 the shared texture table, this+0x2a4.. the
    bound-texture slots, +0x32c / +0x334 streamed / pinned textures, +0x290 bound surface, +0x8c surface flags"""
    this, pool, accel = gl_context(m, rng)
    sh = D.obj(m, rng, 'IOATIR500Shared', 0x400)
    arr = m.alloc(0x80); n = 6
    texs = [stream_texture(m, rng) for _ in range(n)]
    for i, t in enumerate(texs): m.w32(arr + 4 * i, rng.choice([t, t, t, 0]))
    m.w32(sh + 0x10, arr); m.w32(sh + 0x14, n)
    m.w32(this + 0x88, sh)
    m.uc.mem_write(this + 0x2a4, bytes(0x90))
    for off in range(0x2a4, 0x330, 4):
        if rng.random() < 0.4: m.w32(this + off, rng.choice(texs))
    m.w32(this + 0x32c, rng.choice([0, texs[0], texs[1]])); m.w32(this + 0x334, rng.choice([0, texs[2], texs[3]]))
    m.w32(this + 0x328, 0)
    m.w32(this + 0x290, rng.choice([0, D.obj(m, rng, 'ATIR500Surface', 0x1000)]))
    m.w32(this + 0x8c, rng.choice([0, 0x80, 0x1, 0x81]))

    def make(m, rng, op, base):
        if op == 0x29:
            for i in range(1, 6): m.w32(base + 4 * i, rng.choice([0, 1, 2, 3, 7, 8, 0x10, 0x11, 9]))
            if rng.random() < 0.4: m.w32(base + 20, 0x10)
        elif op == 0x39:
            m.w32(base + 4, rng.choice([0, 1, 2, 3])); m.w32(base + 8, rng.choice([0, 1])); m.w32(base + 12, rng.choice([0, 1]))
            m.w32(base + 16, rng.choice([0, 1, 0x1234]))
            for i in range(4): m.w32(base + 0x20 + 4 * i, rng.choice([0, 1, 2, 3, 4, 5, 9]))
        elif op == 0x3a: m.w32(base + 4, rng.choice([0, 1]))
        elif op == 0x3d: m.w32(base + 4, rng.choice([0x132, 0x132, 5])); m.w32(base + 8, rng.choice([0, 1, 2]))
        elif op == 0x36: m.w32(base + 4, rng.choice(texs))
        elif op == 0x3b: m.w32(base + 4, rng.choice([0, 1, 2, 3, 9])); m.w32(base + 12, rng.choice([0, 1, 2]))
        else: m.w32(base + 4, rng.choice([0, 1, 2, 3, 4, 5, 9]))
    stream = packets(m, rng, GL_DISCARD_OPS, make)
    hdr = m.alloc(0x40); m.w32(this + 0xe0, stream)
    return [this]


CASES += [
    Case('ATIR500GLContext::discard_command_buffer', w_gl_discard, ret='void', seeds=400, mock=h5_mock, plain_words=True, ignore_args=D.REL, limit=400000, name='ATIR500GLContext::discard_command_buffer (hand world)'),
]


DVD_DISCARD_OPS = list(range(0x19, 0x2b)) + list(range(0x2b, 0x3d)) + [0x01, 0x3f, 0x40]


def w_dvd_discard(m, rng):
    """ATIR500DVDContext::discard_command_buffer(): this+0xa4 the command-buffer header (+0x1c the packet stream), this+0x84 the shared texture table (+0x10 array,
    +0x14 count), this+0x104.. the 18 bound-texture slots"""
    c = D.obj(m, rng, 'ATIR500DVDContext', 0x400)
    sh = D.obj(m, rng, 'IOATIR500Shared', 0x400)
    arr = m.alloc(0x80); n = 6
    texs = [stream_texture(m, rng) for _ in range(n)]
    for i, t in enumerate(texs): m.w32(arr + 4 * i, rng.choice([t, t, t, 0]))
    m.w32(sh + 0x10, arr); m.w32(sh + 0x14, n)
    m.w32(c + 0x84, sh)
    for off in range(0x104, 0x14c, 4):
        m.w32(c + off, rng.choice([0, 0, texs[rng.randrange(n)]]))

    def make(m, rng, op, base):
        m.w32(base + 4, rng.choice([0, 1, 2, 3, 4, 5, 9]))
    m.w32(c + 0xa4, packets(m, rng, DVD_DISCARD_OPS, make))
    return [c]


CASES += [
    Case('ATIR500DVDContext::discard_command_buffer', w_dvd_discard, ret='void', seeds=300, mock=h5_mock, plain_words=True, ignore_args=D.REL, limit=400000, name='ATIR500DVDContext::discard_command_buffer (hand world)'),
]


def link_texture(m, rng, kind=None):
    """a VendorTextureBuffer for alloc_and_load_texture: +4 GART offset, +8 memory, +0x14 header (+0x14 flag byte), +0x20 kind, +0x24/+0x28 ring links, +0x34/+0x38
    list links (real writable neighbours), +0x48 VRAM offset, +0x50 owner (texture or surface), +0x54 linked texture / surface list link, +0x58/+0x5c ids"""
    t = D.plain(m, rng, 0x100)
    hdr = D.plain(m, rng, 0x40); m.w8(hdr + 0x14, rng.choice([0, 1, 2, 3]))
    m.w32(t + 0x14, hdr)
    m.w8(t + 0x20, kind if kind is not None else rng.choice([0, 1, 2, 3, 6, 7, 8, 9, 4]))
    m.w32(t + 4, rng.choice([0, 0x1000])); m.w32(t + 8, rng.choice([0, D.plain(m, rng, 0x100)]))
    m.w32(t + 0x48, rng.choice([0, 0, 0x2000]))
    m.w32(t + 0x24, D.plain(m, rng, 0x100)); m.w32(t + 0x28, D.plain(m, rng, 0x100))
    n1, n2 = D.plain(m, rng, 0x100), D.plain(m, rng, 0x100)
    m.w32(t + 0x34, n1); m.w32(t + 0x38, n2)
    m.w32(t + 0x5c, rng.choice([0, 1, 7])); m.w32(t + 0x58, rng.choice([0, 1, 5]))
    return t


def w_gl_alloc_and_load_texture(m, rng):
    this, pool, accel = gl_context(m, rng)
    m.w32(accel + 0x6d0, D.plain(m, rng, 0x100))
    S = D.obj(m, rng, 'ATIR500Surface', 0x1000)
    m.w32(S + 0xbf8, rng.choice([0, 0x20000000, 0x1, 0x7fffff])); m.w32(S + 0xc18, rng.choice([0, 0x1, 0x7fffff, 0x20000000]))
    m.w32(this + 0x290, rng.choice([0, S]))
    t = link_texture(m, rng)
    kind = m.r32(t + 0x20) & 0xff if False else None
    owner = link_texture(m, rng, rng.choice([0, 1, 2, 3, 7]))
    m.w32(t + 0x50, rng.choice([0, 0, S, owner]))
    m.w32(t + 0x54, rng.choice([0, link_texture(m, rng, 2), link_texture(m, rng, 2), S]))
    script(m, 'find_surface_for_id', [rng.choice([0, S, S])])
    script(m, 'freeToAllocTextureVRAM', [rng.choice([0, 0, 1])]); script(m, 'compact_current_textures', [rng.choice([0, 0, 1])])
    script(m, 'alloc_surfaces_keep', [rng.choice([0, 1, 1])])
    script(m, 'allocate_texture', [rng.choice([0, 0, 1])])
    script(m, 'vtable slot +0x528', [rng.choice([0, 0, 1])]); script(m, 'vtable slot +0x524', [0])
    return [this, t]


CASES += [
    Case('ATIR500GLContext::alloc_and_load_texture', w_gl_alloc_and_load_texture, ret='void', seeds=400, mock=h5_mock, plain_words=True, ignore_args=D.REL, limit=300000, out_extents={'surface_buffer_idx_mask': {2: 4}}, name='ATIR500GLContext::alloc_and_load_texture (hand world)'),
]


def w_dvd_idct_cmft(m, rng):
    """ATIR500DVDContext::clientMemoryForType(type, options, memory): types 0-3 go to the base class (mocked), 4 / 5 hand out the luma / chroma IDCT buffers
    alternating (toggles at +0x164 / +0x1a0), each buffer's descriptor (+0x170/+0x18c/+0x1ac/+0x1c8), stamp, header and size fields"""
    c = D.obj(m, rng, 'ATIR500DVDContext', 0x400)
    A = D.accel(m, rng, mmio=False)
    m.w32(c + 0x8c, A)
    for off in (0x164, 0x1a0): m.w32(c + off, rng.choice([0, 1]))
    for base in (0x170, 0x18c, 0x1ac, 0x1c8):
        m.w32(c + base, D.plain(m, rng, 0x100)); m.w32(c + base + 8, rng.choice([0, 0x1234]))
        m.w32(c + base + 0xc, D.plain(m, rng, 0x100)); m.w32(c + base + 0x10, rng.choice([0x1000, 0x2000]))
    m.w32(c + 0x150, rng.choice([0, 5, 0x1000]))
    return [c, rng.choice([0, 1, 2, 3, 4, 4, 5, 5, 6]), m.alloc(8), m.alloc(8)]


def w_dvd_do_idct(m, rng):
    """ATIR500DVDContext::doIDCT(info, size): info +0 / +4 / +8 / +0xc select field, chroma and buffer, the bound surface (+0xf8) holds the plane records
    (+0x558 + 0x78*i luma, +0x8a0 chroma: +8 base, +0x18 pitch), the accelerator's +0x80 live flag, +0x8bc, +0x854 stamp threshold"""
    c = D.obj(m, rng, 'ATIR500DVDContext', 0x400)
    A = D.accel(m, rng, mmio=False)
    m.w32(c + 0x8c, A)
    m.w8(A + 0x80, rng.choice([1, 1, 1, 0])); m.w32(A + 0x8bc, rng.choice([0, 1, 1])); m.w32(A + 0x854, rng.choice([0, 5, 0x100]))
    S = D.obj(m, rng, 'ATIR500Surface', 0x1000)
    m.w32(c + 0xf8, rng.choice([0, S, S, S]))
    m.uc.mem_write(S + 0x94, struct.pack('>h', rng.choice([0, 16, 0x10])))
    m.uc.mem_write(S + 0x9a, struct.pack('>h', rng.choice([0, 32, 64, 0x40])))
    for rec in [S + 0x558 + 0x78 * i for i in range(4)] + [S + 0x8a0]:
        m.w32(rec + 8, rng.choice([0, 0x100000, 0x200000])); m.w16(rec + 0x18, rng.choice([0, 64, 128]))
    for off in (0x164, 0x1a0): m.w32(c + off, rng.choice([0, 1]))
    for base in (0x168, 0x184, 0x1a4, 0x1c0):
        m.w32(c + base + 4, rng.choice([0, 0x1000])); m.w32(c + base + 0x14, D.plain(m, rng, 0x100))
    info = m.alloc(0x40); fill_words(m, info, 0x40, rng)
    m.w32(info, rng.choice([0, 1])); m.w32(info + 4, rng.choice([0, 1])); m.w32(info + 8, rng.choice([0, 1, 2, 3])); m.w32(info + 0xc, rng.choice([0, 0, 1, 1, 2]))
    script(m, 'submit_idct_buffer_consumed', [rng.choice([0, 3, 0x100, 0x1000])])
    return [c, info, 0x40]


CASES += [
    Case('ATIR500DVDContext::clientMemoryForType', w_dvd_idct_cmft, ret='u32', seeds=120, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='ATIR500DVDContext::clientMemoryForType (IDCT hand world)'),
    Case('ATIR500DVDContext::doIDCT', w_dvd_do_idct, ret='u32', seeds=300, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='doIDCT (hand world)'),
]


def with_hw_state(world, alive_choices=(0, 1)):
    """run a hand_cases_C world with the accelerator's 'hardware alive' byte (+0x80) random instead of always 1 (C.gl_context pins it when alive=True)"""
    def w(m, rng):
        orig = C.gl_context
        def patched(m2, rng2, cls='ATIR500GLContext', alive=True):
            r = orig(m2, rng2, cls, alive=True)
            m2.w8(r[2] + 0x80, rng2.choice(alive_choices)); m2.h5_accel = r[2]
            return r
        C.gl_context = patched
        try:
            args = world(m, rng)
        finally:
            C.gl_context = orig
        if getattr(world, '__name__', '') == 'w_get_data_buffer':
            this = args[0]                                   # IOMemoryMap::getTask() (vtable +0xdc) answers this context's task or another one
            script(m, 'slot +0xdc', [m.r32(this + 0x78) if rng.random() < 0.5 else 0x5555 for _ in range(4)])
            vt = m.vtable('ATIR500Memory')
            bufs = []
            for _ in range(3):                               # buffers from allocOneDataBuffer in every combination of memory (+8), mapping (+0x10), GART offset (+0x48)
                b = C.data_buffer(m, rng, vt)
                m.w32(b + 8, rng.choice([0, 0, vobj(m, rng, vt)])); m.w32(b + 0x10, rng.choice([0, vobj(m, rng, vt)]))
                m.w32(b + 0x48, rng.choice([0, 0x1000])); m.w32(b + 4, rng.choice([0, 1])); m.w32(b + 0x50, rng.choice([m.r32(m.r32(this + 0xc8) + 0x5d8)] * 3 + [0x10000, 0x20000, 0x7ffff]))
                bufs.append(rng.choice([0, b, b, b]))
            script(m, 'allocOneDataBuffer', bufs)
            node, seen = m.r32(args[0] + 0xc8) and m.r32(m.r32(args[0] + 0xc8) + 0x5cc), 0        # the accelerator's cached free buffers get the same variety
            while node and seen < 4:
                m.w32(node + 8, rng.choice([0, 0, vobj(m, rng, vt)])); m.w32(node + 0x10, rng.choice([0, vobj(m, rng, vt)]))
                m.w32(node + 0x48, rng.choice([0, 0x1000])); m.w32(node + 4, rng.choice([0, 1])); m.w32(node + 0x50, rng.choice([m.r32(m.r32(this + 0xc8) + 0x5d8)] * 3 + [0x10000, 0x20000, 0x7ffff]))
                node, seen = m.r32(node + 0x3c), seen + 1
        return args
    return w


CASES += [
    Case('IOATIR500GLContext::get_data_buffer', with_hw_state(C.w_get_data_buffer), ret='u32', seeds=600, mock=scripted_mock, plain_words=True, name='get_data_buffer (hardware-state hand world)'),
]


MODE_BITS = [0x400, 0x800, 0x40, 0x1000, 0x100, 0x200, 0x2000, 0x10, 0x4, 0x8000, 0x4000, 0x1]


def mode_word(rng):
    w = 0
    for b in MODE_BITS:
        if rng.random() < 0.35: w |= b
    return w | rng.choice([0, 0, 0x3f, 0x20])


def w_gl_set_surface(m, rng):
    """IOATIR500GLContext::set_surface(surfaceID, modeBits, index, mipLevel): this+0xc8 the accelerator (+0x840 lock, +0x78 current context), this+0x290 the bound
    surface, this+0x84 next context; the surface found by find_surface_for_id: +0x88 first bound context, +0x8c / +0x90 other context lists, +0xbe8 mode bits,
    +0xc18 required bits; virtual calls (compatible-mode check +0x5ac, +0x5bc, +0x5a8, the surface's +0x5ac) scripted"""
    this, pool, accel = gl_context(m, rng)
    other = D.obj(m, rng, 'ATIR500GLContext', 0x400)
    S = D.obj(m, rng, 'ATIR500Surface', 0x1000)
    m.w32(S + 0x88, rng.choice([0, this, other])); m.w32(S + 0x8c, rng.choice([0, 0, other])); m.w32(S + 0x90, rng.choice([0, 0, other]))
    m.w32(S + 0xbe8, rng.choice([0, 0x10, 0xffff, 0x803f])); m.w32(S + 0xc18, rng.choice([0, 4, 0x84, 0x80, 4]))
    m.w32(this + 0x84, rng.choice([0, 0, other]))
    m.w32(this + 0x290, rng.choice([0, S, S, D.obj(m, rng, 'ATIR500Surface', 0x1000)]))
    m.w32(accel + 0x78, rng.choice([0, this, other]))
    script(m, 'find_surface_for_id', [rng.choice([0, S, S, S])])
    script(m, 'setCompatibleSurfaceMode', [rng.choice([0, 1, 1])])
    script(m, 'slot +0x5ac', [rng.choice([0, 1, 0x20, 0x20000001])])
    return [this, rng.choice([0, 1, 2, 7]), mode_word(rng), rng.choice([0, 3, 0x12]), rng.choice([0, 1, 5])]


CASES += [
    Case('IOATIR500GLContext::set_surface', w_gl_set_surface, ret='u32', seeds=300, mock=h5_mock, plain_words=True, ignore_args={'setCompatibleSurfaceMode': [3]}, name='IOATIR500GLContext::set_surface (hand world)'),
]


def w_dvd_set_surface(m, rng):
    """IOATIR500DVDContext::set_surface(surfaceID, modeBits, flagCount): this+0x8c accelerator (+0x78 current context), this+0xf8 bound surface, this+0x88
    context flag bits; the surface found by find_surface_for_id (+0x90 its DVD context, +0x88 / +0x8c other lists, +0xbe8 mode bits); compatibility virtual +0x5ac"""
    c, A = D.dvd(m, rng)
    other = D.obj(m, rng, 'ATIR500DVDContext', 0x400)
    S = D.obj(m, rng, 'ATIR500Surface', 0x1000)
    m.w32(S + 0x90, rng.choice([0, 0, c, other])); m.w32(S + 0x88, rng.choice([0, 0, other])); m.w32(S + 0x8c, rng.choice([0, 0, other]))
    m.w32(S + 0xbe8, rng.choice([0, 0x10, 0xffff, 0x803f]))
    m.w32(c + 0xf8, rng.choice([0, S, S, D.obj(m, rng, 'ATIR500Surface', 0x1000)]))
    m.w32(c + 0x88, rng.choice([0, 0x400, 0x20000000]))
    m.w32(A + 0x78, rng.choice([0, c, other]))
    script(m, 'find_surface_for_id', [rng.choice([0, S, S, S])])
    script(m, 'slot +0x5ac', [rng.choice([0, 1, 1])])
    return [c, rng.choice([0, 1, 2]), rng.choice([0, 0x4000, 0x1234, 0xffff]), rng.choice([0, 1, 2, 3, 70, -1 & 0xffffffff])]


def w_dvd_lock_all_buffers(m, rng):
    """IOATIR500DVDContext::lock_all_buffers(unused, out): the bound surface (+0xf8: state bits +0xbf8, buffer table +0xb70, lock count +0xbd2) and the context's
    flag bits (+0x88); alloc_surfaces results scripted (0 ok, 2 fail, retry counts up to 1000)"""
    c, A = D.dvd(m, rng)
    S = D.bound_surface(m, rng, c)
    m.w32(S + 0xbf8, rng.choice([0, 0x400, 0x20000000, 0x7ffc00, 0x207ffc00]))
    m.w32(c + 0xf8, rng.choice([0, S, S, S]))
    m.w32(c + 0x88, rng.choice([0, 0x400, 0x20000400, 0x207ffc00]))
    alloc_script(m, rng)
    m.h5_accel = A
    return [c, 0, m.alloc(0x100)]


def w_gl_add_texture_to_stream(m, rng):
    """IOATIR500GLContext::add_texture_to_stream(texture): texture +0x20 kind (6 linked texture at +0x54, 0 surface at +0x50 whose virtual +0x5b8 is called, 1 source
    texture at +0x50, 8 plain), +0xe use count, +0x14 header flag byte, +4 GART offset; accelerator +0x6d0 / +0x69c the active list"""
    this, pool, accel = gl_context(m, rng)
    m.w32(accel + 0x6d0, D.plain(m, rng, 0x100))

    def tex(kind, depth=0):
        t = link_texture(m, rng, kind)
        if kind == 6: m.w32(t + 0x54, tex(rng.choice([2, 3]), depth + 1))
        elif kind == 0: m.w32(t + 0x50, rng.choice([0, D.obj(m, rng, 'ATIR500Surface', 0x1000)]))
        elif kind == 1: m.w32(t + 0x50, rng.choice([0, tex(rng.choice([0, 6, 2]), depth + 1)] if depth < 2 else [0]))
        return t
    return [this, tex(rng.choice([6, 6, 0, 1, 8, 2, 3]))]


CASES += [
    Case('IOATIR500DVDContext::set_surface', w_dvd_set_surface, ret='u32', seeds=300, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='IOATIR500DVDContext::set_surface (hand world)'),
    Case('IOATIR500DVDContext::lock_all_buffers', w_dvd_lock_all_buffers, ret='u32', seeds=200, mock=h5_mock, plain_words=True, ignore_args=D.REL, limit=600000, name='IOATIR500DVDContext::lock_all_buffers (hand world)'),
    Case('IOATIR500GLContext::add_texture_to_stream', w_gl_add_texture_to_stream, ret='void', seeds=200, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='IOATIR500GLContext::add_texture_to_stream (hand world)'),
]


def w_gl_new_texture(m, rng):
    """IOATIR500GLContext::new_texture(data, returnData, size, sizeOut): data +0 selects the IOATIR500Shared factory (+0x88 the shared allocator), whose result
    (texture or none) is scripted; case 6's result must carry a record at +0x54 with an id at +0x58"""
    this, pool, accel = gl_context(m, rng)
    sh = D.obj(m, rng, 'IOATIR500Shared', 0x400)
    m.w32(this + 0x88, sh)
    t = D.plain(m, rng, 0x100)
    m.w32(t + 0x54, D.plain(m, rng, 0x100))
    for key in ('new_surface_texture', 'new_global_texture', 'new_agpref_texture', 'IOATIR500Shared11new_texture'):
        script(m, key, [rng.choice([0, t, t])])
    data = m.alloc(0x40); fill_words(m, data, 0x40, rng)
    m.w32(data, rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 0xffffffff]))
    return [this, data, m.alloc(0x10), rng.choice([0x20, 0x40]), m.alloc(8)]


CASES += [
    Case('IOATIR500GLContext::new_texture', w_gl_new_texture, ret='u32', seeds=150, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='IOATIR500GLContext::new_texture (hand world)'),
]


def w_gl_connect_client(m, rng):
    """IOATIR500GLContext::connectClient(client): the client's task (+0x78) must equal this context's (+0x78); this+0x88 the shared allocator (released), the
    client's +0x88 the shared allocator it takes (retained)"""
    this, pool, accel = gl_context(m, rng)
    m.w32(this + 0x88, D.obj(m, rng, 'IOATIR500Shared', 0x400))
    client = D.obj(m, rng, 'IOATIR500GLContext', 0x400)
    m.w32(client + 0x88, D.obj(m, rng, 'IOATIR500Shared', 0x400))
    task = rng.choice([0, 1, 0x1234])
    m.w32(this + 0x78, task); m.w32(client + 0x78, task if rng.random() < 0.7 else task + 1)
    return [this, client]


def w_gl_become_global_shared(m, rng):
    """IOATIR500GLContext::become_global_shared(makeShared): this+0x88 the shared allocator (its +0x24 a flag), the accelerator's global shared slot (+0x6c) and its
    'active' word (+0x70)"""
    this, pool, accel = gl_context(m, rng)
    sh = D.obj(m, rng, 'IOATIR500Shared', 0x400)
    m.w32(sh + 0x24, rng.choice([0, 0, 1]))
    m.w32(this + 0x88, sh)
    m.w32(accel + 0x6c, rng.choice([0, sh, sh, D.obj(m, rng, 'IOATIR500Shared', 0x400)])); m.w32(accel + 0x70, rng.choice([0, 1]))
    return [this, rng.choice([0, 1, 1, 2])]


CASES += [
    Case('IOATIR500GLContext::connectClient', w_gl_connect_client, ret='u32', seeds=60, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='IOATIR500GLContext::connectClient (hand world)'),
    Case('IOATIR500GLContext::become_global_shared', w_gl_become_global_shared, ret='u32', seeds=100, mock=h5_mock, plain_words=True, ignore_args=D.REL, name='IOATIR500GLContext::become_global_shared (hand world)'),
    Case('IOATIR500GLContext::get_status', with_hw_state(C.w_get_status), ret='u32', seeds=100, mock=h5_mock, plain_words=True, name='get_status (hardware-state hand world)'),
    Case('IOATIR500GLContext::get_config', with_hw_state(C.w_get_config), ret='u32', seeds=100, mock=h5_mock, plain_words=True, name='get_config (hardware-state hand world)'),
]

CASES += [
    Case('ATIR5002DContext::get_buffer_info', w_2d_get_buffer_info, ret='u32', seeds=120, plain_words=True, name='get_buffer_info (hand world)'),
]
