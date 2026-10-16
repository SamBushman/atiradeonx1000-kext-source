"""Hand-written worlds for IOATIR500Accelerator methods whose generic world (all_classes_cases.py) never finished (fork B of #183).

Every method here runs on the concrete accelerator (ATIRadeonX1000) object; fields are those documented in Sources/IOATIR500Accelerator_*.cpp.
Objects of classes outside the kext (IOMemoryDescriptor, IOTimerEventSource, the AGP provider ...) are `foreign()` objects: their virtual calls are
mocked stubs named after the class and slot, so every virtual call is compared by slot and arguments. Run:
python3 Tools/difftest/difftest.py --rebuilt build/difftest/rebuilt_B.bin Tests/difftest/hand_cases_B.py

Notes on what these worlds do and do not cover:
* free_gart_wirings: the IOPanic branches (a node that is poorly linked is exercised once, but a node that is not on the GART, or not a texture transfer
  buffer) are not entered: on the machine IOPanic never returns, here the mocked panic returns and the loop would not end.
* configureAGP: the 6th register of sysctlbyname (a 5-parameter function) holds leftover contents in each build and is not compared.
* Virtual calls on foreign objects carry a declared argument list only where it matters (slot +0x18 is release(): `this` only); an undeclared slot is
  compared as three integer registers.
* Mocks that need state keep it on the machine (m.desc_size, m.castable, m.iters ...): the world sets it, the mock reads it; both sides see the same.
"""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case, default_mock
from unicorn.ppc_const import UC_PPC_REG_3, UC_PPC_REG_4
from common import fill_words, word, small, object_with_vtable


def foreign(m, rng, name, size=0x200, vsize=0x800, sigs=None):
    """an object of a class outside the kext: random words, and a vtable whose slot at +0xNN is the stub '<name> [vcall +0xNN]'.
    sigs {slot offset: argument kinds} declares a virtual's arguments ('this', 'p' pointer: compared by text/symbol when it points into the kext image,
    'i' integer); an undeclared slot is compared as three integer registers."""
    o = m.alloc(size); fill_words(m, o, size, rng)
    vt = m.alloc(vsize)
    sigs = {**{0x18: ['this']}, **(sigs or {})}           # slot +0x18 of every OSObject is release()
    for off in range(0, vsize, 4):
        k = sigs.get(off)
        m.w32(vt + off, m.reg.get('%s [vcall +0x%x]' % (name, off), (sum(1 for x in k if x != 'f'), k) if k else None))
    m.w32(o, vt)
    return o


def accel(m, rng, size=0x1000):
    """the accelerator: random words, the ATIRadeonX1000 vtable, the command lock (+0x840) and the usual counts"""
    a = m.alloc(size); fill_words(m, a, size, rng)
    m.w32(a, m.vtable('ATIRadeonX1000'))
    m.reg.sig['vtable slot +0x5e4'] = (1, ['this'])      # ASICSupportsAGP(): the ledger does not name this slot of the concrete class
    m.w32(a + 0x840, foreign(m, rng, 'IOLock', 0x40))
    return a


# ---- the two timer callbacks: owner+0xbc / +0xc4 is an event source whose vtable +0x130 is invoked ------------------------------------------
def w_timer(off):
    def w(m, rng):
        a = accel(m, rng)
        m.w32(a + off, foreign(m, rng, 'IOInterruptEventSource'))
        return [a, foreign(m, rng, 'IOTimerEventSource')]
    return w


# ---- commitAGPMemory / releaseAGPMemory: tail calls into the AGP provider (this+0x74) -----------------------------------------------------
def w_agp_call(m, rng):
    a = accel(m, rng)
    m.w32(a + 0x74, foreign(m, rng, 'IOAGPProvider'))
    return [a, foreign(m, rng, 'IOMemoryDescriptor'), word(rng), word(rng)]


def arg(m, i):
    return m.uc.reg_read(UC_PPC_REG_3 + i)


def mocker(**rules):
    """a mock policy: the first rule whose key is a substring of the callee name answers (fn(machine, name, callIndex)); anything else is default_mock"""
    def mock(m, name, k):
        for key, fn in rules.items():
            if key in name:
                return fn(m, name, k)
        return default_mock(m, name, k)
    return mock


def make_object(m, cls, size=0x200, sigs=None):
    """a deterministic foreign object created INSIDE a mock (no rng): zero words and a vtable of named stubs (sigs as for foreign())"""
    o = m.alloc(size); vt = m.alloc(0x800)
    sigs = {**{0x18: ['this']}, **(sigs or {})}
    for off in range(0, 0x800, 4):
        k = sigs.get(off)
        m.w32(vt + off, m.reg.get('%s [vcall +0x%x]' % (cls, off), (sum(1 for x in k if x != 'f'), k) if k else None))
    m.w32(o, vt)
    return o


# ---- descriptors: size (vcall +0x128) and physical segments (vcall +0x13c(offset, &length) -> address, 0 at the end) ------------------------------
def desc_size(m, name, k): return m.desc_size


def desc_segment(m, name, k):
    off = arg(m, 1)
    if off >= m.desc_size:
        return 0
    n = min(m.desc_size - off, 0x1000 * (1 + (off >> 12) % 3))
    m.w32(arg(m, 2), n)
    return 0x10000000 + off


def gart_table(m, rng, a, pages=0x400):
    """the accelerator's GART shadow table (+0x83c, +0x830 = size field, +0x844 = the 'empty' entry, +0x848 = the 'reserved' entry)"""
    empty = rng.choice([0, 0x5a5a5a5a, 0xffffffff])
    t = m.alloc(4 * pages)
    for i in range(pages):
        m.w32(t + 4 * i, empty if rng.random() < 0.7 else rng.getrandbits(32))
    m.w32(a + 0x83c, t); m.w32(a + 0x830, pages // 4 * 4 if pages >= 4 else 4)
    m.w32(a + 0x844, empty); m.w32(a + 0x848, empty ^ 0x1234)
    return t


def w_remove_gart(m, rng):
    a = accel(m, rng); gart_table(m, rng, a)
    m.desc_size = rng.choice([0, 0x1000, 0x1800, 0x3000, 0x8000, 0x10000])
    m.w32(a + 0x98, rng.choice([0, 2, 3, 1])); m.w32(a + 0xa0, 0x100000); m.w32(a + 0x718, 0)
    return [a, rng.choice([0, foreign(m, rng, 'IOMemoryDescriptor')]), rng.randrange(0, 0x40) * 0x1000]


def w_add_minmax(m, rng):
    a = accel(m, rng); gart_table(m, rng, a)
    m.desc_size = rng.choice([0x1000, 0x1800, 0x2000, 0x5000, 0x8000, 0])
    m.w32(a + 0x98, rng.choice([0, 2, 3, 1])); m.w32(a + 0xa0, 0x1000); m.w32(a + 0x714, 0)
    out = m.alloc(0x40)
    lo = rng.randrange(0, 0x30) * 0x1000; hi = rng.choice([lo + 0x20000, 0xff000, 0x1000, 0x400000, 0xffffffff, 0x10])
    return [a, foreign(m, rng, 'IOMemoryDescriptor'), out, lo, hi]


def w_perf_stats(m, rng):
    a = accel(m, rng)
    for off in range(0x6fc, 0x7c4, 4):
        m.w32(a + off, word(rng))
    m.w32(a + 0x830, rng.choice([0, 0x100, 0x4000]))
    return [a, foreign(m, rng, 'OSDictionary', sigs={0x12c: ['this', 'p', 'p']})]


DESC_MOCK = dict(**{'IOMemoryDescriptor [vcall +0x128]': desc_size, 'IOMemoryDescriptor [vcall +0x13c]': desc_segment})
GART_MOCK = mocker(**{'IOMemoryDescriptor [vcall +0x128]': desc_size, 'IOMemoryDescriptor [vcall +0x13c]': desc_segment,
                      'IOMemoryDescriptor [vcall +0x144]': lambda m, n, k: (k % 3 == 2) and 0xe00002bc or 0})
STATS_MOCK = mocker(withNumber=lambda m, n, k: 0 if k % 7 == 3 else make_object(m, 'OSNumber', sigs={0x18: ['this']}))


def ring(m, sentinel, nodes, next_off, prev_off):
    """a circular doubly linked list: sentinel -> nodes... -> sentinel"""
    seq = [sentinel] + list(nodes)
    for i, x in enumerate(seq):
        m.w32(x + next_off, seq[(i + 1) % len(seq)])
        m.w32(x + prev_off, seq[i - 1])


def surface_ring(m, rng, a, head_off=0x5c, link_off=0x9c, n=None):
    """the accelerator's live-surface list: +0x5c points at the first surface, each surface's +0x9c at the next, the last back at the first (0 = empty)"""
    n = rng.choice([0, 1, 2, 3]) if n is None else n
    surfs = [object_with_vtable(m, rng, 'ATIR500Surface', 0xe00) for _ in range(n)]
    for i, x in enumerate(surfs):
        m.w32(x + link_off, surfs[(i + 1) % n])
    m.w32(a + head_off, surfs[0] if surfs else 0)
    return surfs


def w_free_all_cmd(m, rng):
    a = accel(m, rng)
    idx = rng.choice([0, 1, 2])
    m.w16(a + idx * 0x1c4 + 0x402, rng.choice([0, 1, 2, 5]))
    return [a, idx]


def w_disp_did(m, rng):
    a = accel(m, rng)
    surfaces = surface_ring(m, rng, a)
    m.w32(a + 0xcc, rng.choice([0, 1, 2, 2])); m.w32(a + 0xd0, rng.choice([0, 1, 2, 3]))
    for i in range(2):
        m.w32(a + 0xe8 + 0x20 * i, rng.choice([0, 0] + surfaces) if surfaces else 0)
        m.w32(a + 0x124 + 4 * i, rng.choice([0, 0, 3]))
    return [a]


def w_disp_will(m, rng):
    a = accel(m, rng)
    m.w8(a + 0x80, rng.choice([1, 1, 1, 0])); m.w8(a + 0x88, rng.choice([0, 1]))
    m.w32(a + 0xc0, foreign(m, rng, 'IOTimerEventSource'))
    surfaces = surface_ring(m, rng, a)
    m.w32(a + 0xcc, rng.choice([0, 1, 2, 2]))
    for i in range(2):
        m.w32(a + 0xe8 + 0x20 * i, rng.choice([0, 0] + surfaces) if surfaces else 0)
        m.w32(a + 0x11c + 4 * i, rng.choice([0, 0, 2]))
    def node(sz=0x60):
        n = m.alloc(sz); fill_words(m, n, sz, rng)
        hdr = m.alloc(0x80); fill_words(m, hdr, 0x80, rng); m.w32(n + 0x14, hdr)
        return n
    ring(m, a + 0x5dc, [node() for _ in range(rng.choice([0, 1, 2, 3]))], 0x28, 0x24)
    ring(m, a + 0x63c, [node() for _ in range(rng.choice([0, 1, 2]))], 0x28, 0x24)
    return [a, rng.choice([0, 1, 2, 3, 3])]


def w_find_fb(m, rng):
    """the IORegistry walk: provider(+0x74)->vcall 0x1bc / 0x3c0 hand out iterators (in m.iters order), an iterator's vcall 0xd8 pops its queue, safeMetaCast
    succeeds for the objects in m.castable, the provider's vcall 0x444 returns one of m.fbs"""
    a = accel(m, rng)
    m.provider = foreign(m, rng, 'IOService'); m.w32(a + 0x74, m.provider)
    objs = [foreign(m, rng, 'IOService') for _ in range(6)]
    m.fbs = [rng.choice(objs + [0]) for _ in range(3)]
    m.castable = set(o for o in objs if rng.random() < 0.6)
    m.iters, m.queue = [], {}
    for _ in range(rng.choice([2, 3, 4, 5])):
        it = foreign(m, rng, 'OSIterator')
        m.iters.append(it)
        m.queue[it] = [rng.choice(objs) for _ in range(rng.choice([0, 1, 2, 3]))]
    m.iters = [0 if rng.random() < 0.15 else x for x in m.iters]
    return [a]


def _pop_iter(m, name, k):
    """the provider may fail to produce an iterator (0); a child object always produces one (an empty one when the queue ran dry)"""
    it = m.iters.pop(0) if m.iters else None
    if arg(m, 0) == m.provider:
        return it or 0
    return it or make_object(m, 'OSIterator')


def _next(m, name, k):
    q = m.queue.get(arg(m, 0))
    return q.pop(0) if q else 0


FIND_FB_MOCK = mocker(**{'IOService [vcall +0x1bc]': _pop_iter, 'IOService [vcall +0x3c0]': _pop_iter, 'OSIterator [vcall +0xd8]': _next,
                         'safeMetaCast': lambda m, n, k: arg(m, 0) if arg(m, 0) in m.castable else 0,
                         'IOService [vcall +0x444]': lambda m, n, k: m.fbs[k % len(m.fbs)],
                         'withCString': lambda m, n, k: 0 if k % 5 == 4 else make_object(m, 'OSSymbol')})


def w_free_cmd_buf(m, rng):
    a = accel(m, rng)
    b = m.alloc(0x40); fill_words(m, b, 0x40, rng)
    m.w32(b + 8, foreign(m, rng, 'IOBufferMemoryDescriptor'))
    m.w32(b + 4, rng.choice([0, 0, 1, 0x20000000]))
    return [a, b]


def w_free_data_buf(m, rng):
    a = accel(m, rng)
    b = m.alloc(0x100); fill_words(m, b, 0x100, rng)
    other = m.alloc(0x100)
    ring(m, other, [b], 0x28, 0x24)                      # a texture buffer sits on a circular list (+0x24 previous, +0x28 next)
    m.w32(b + 0x48, rng.choice([0, 0, 1, 0x1000]))
    m.w32(b + 4, rng.choice([0, 1, 0x1000]))
    m.w32(b + 0x10, rng.choice([0, foreign(m, rng, 'IOMemoryDescriptor')]))
    m.w32(b + 8, rng.choice([0, foreign(m, rng, 'IOBufferMemoryDescriptor'), foreign(m, rng, 'IOBufferMemoryDescriptor')]))
    m.w32(a + 0x750, rng.choice([0, 1, 7]))
    return [a, b]


def tex_node(m, rng, size=0x100):
    n = m.alloc(size); fill_words(m, n, size, rng)
    return n


def w_add_orphan(m, rng):
    a = accel(m, rng)
    ring(m, a + 0x63c, [tex_node(m, rng) for _ in range(rng.choice([0, 1, 3]))], 0x28, 0x24)     # the orphan list (sentinel +0x63c, tail at +0x660)
    other = tex_node(m, rng); t = tex_node(m, rng)
    ring(m, other, [t] + ([tex_node(m, rng)] if rng.random() < 0.5 else []), 0x28, 0x24)        # the texture is on some other circular list
    m.w32(a + 0xb8, foreign(m, rng, 'IOTimerEventSource'))
    m.w8(a + 0x82, rng.choice([0, 1]))
    return [a, t]


def w_page_off(m, rng):
    a = accel(m, rng)
    b = tex_node(m, rng)
    ring(m, tex_node(m, rng), [b], 0x28, 0x24)
    src = m.alloc(0x2000); fill_words(m, src, 0x2000, rng); m.w32(a + 0xe4, src)
    m.w32(b + 0x48, rng.choice([0, 0x10, 0x100])); m.w32(b + 0x50, rng.choice([0, 4, 0x40, 0x100, 0x7]))
    m.w32(b + 0x10, rng.choice([0, foreign(m, rng, 'IOMemoryDescriptor')]))
    m.w32(b + 8, foreign(m, rng, 'IOMemoryDescriptor'))
    m.dest = m.alloc(0x1000)
    return [a, b]


PAGEOFF_MOCK = mocker(**{'IOMemoryDescriptor [vcall +0x14c]': lambda m, n, k: 0 if k % 4 == 3 else make_object(m, 'IOMemoryMap', sigs={0x18: ['this'], 0xd0: ['this']}),
                         'IOMemoryMap [vcall +0xd0]': lambda m, n, k: m.dest})


def _iogettime(m, name, k):
    """IOGetTime(mach_timespec*): the 'now' the world chose"""
    p = arg(m, 0)
    m.w32(p, m.now[0]); m.w32(p + 4, m.now[1])
    return 0


def _unlink_transfer(m, name, k):
    """removeTransferFromGART(node): take the node off the circular list (+0x34 previous, +0x38 next) like the real method does (type 4 only)"""
    n = arg(m, 1)
    if n and m.r16(n + 0xc) == 4:
        prv, nxt = m.r32(n + 0x34), m.r32(n + 0x38)
        m.w32(prv + 0x38, nxt); m.w32(nxt + 0x34, prv); m.w32(n + 0x38, n); m.w32(n + 0x34, n)
    return 0


def w_free_gart_wirings(m, rng):
    a = accel(m, rng)
    S = a + 0x69c
    nodes = []
    for _ in range(rng.choice([0, 1, 2, 3, 4])):
        n = m.alloc(0x80); fill_words(m, n, 0x80, rng)
        hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(n + 0x14, hdr)
        m.w32(n + 4, rng.choice([1, 1, 1, 0x1000])); m.w16(n + 0xc, 4)       # (a panic never returns on the machine, here it would loop: no panicking nodes)
        m.w8(n + 0x20, rng.choice([2, 3, 4, 5, 7, 7, 6])); m.w16(n + 0xe, rng.choice([0, 0, 0, 1]))
        m.w32(n + 0x2c, rng.choice([0, 3, 5, 9, 12])); m.w32(n + 0x30, rng.choice([0, 400000000, 900000000]))
        nodes.append(n)
    ring(m, S, nodes, 0x38, 0x34)
    if rng.random() < 0.1 and nodes:
        m.w32(nodes[0] + 0x34, nodes[0])              # 'poorly linked'
    m.w32(a + 0x90, rng.choice([0, 1, 3])); m.w32(a + 0x94, rng.choice([0, 500000000]))
    m.now = (rng.choice([5, 10, 13]), rng.choice([0, 300000000, 950000000]))
    return [a]


GARTWIRE_MOCK = mocker(IOGetTime=_iogettime, removeTransferFromGART=_unlink_transfer)


def w_free_surface_vram(m, rng):
    a = accel(m, rng)
    orphans = []
    for _ in range(rng.choice([0, 1, 2, 4])):
        n = tex_node(m, rng, 0x100)
        hdr = m.alloc(0x80); fill_words(m, hdr, 0x80, rng); m.w8(hdr + 0x34, rng.choice([0, 1, 2, 3]))
        if rng.random() < 0.5:                               # make the 'all flagged words are in the mask' test pass for the first words
            for off in range(0x28, 0x40, 2): m.w16(hdr + off, 0)
        m.w32(n + 0x14, hdr if rng.random() < 0.9 else 0); m.w32(n + 0x48, rng.choice([0, 0, 1]))
        orphans.append(n)
    ring(m, a + 0x5dc, orphans, 0x28, 0x24)
    surfs = surface_ring(m, rng, a, 0x5c, 0xa0, n=rng.choice([0, 1, 2, 3]))
    for x in surfs:
        m.w32(x + 0xc14, rng.choice([0xffff, 0, 1])); m.w32(x + 0xb70, x + 0xa8 + 0x78 * rng.randrange(23))
    excl = [rng.choice(orphans + [tex_node(m, rng)]) if orphans else tex_node(m, rng) for _ in range(3)]
    for x in excl[:1]:
        m.w8(x + 0x20, 0); m.w32(x + 0x50, rng.choice(surfs + [0]) if surfs else 0)
    arr = m.alloc(0x40)
    for i, x in enumerate(excl): m.w32(arr + 4 * i, x)
    buf = m.alloc(0x100); fill_words(m, buf, 0x100, rng)
    p1 = rng.choice([0] + surfs[:1]) if surfs else 0
    p2 = rng.choice([0] + surfs[-1:]) if surfs else 0
    return [a, p1, p2, arr, rng.choice([0, 1, 2, 3]), buf]


def _cstring(m, addr):
    return bytes(m.uc.mem_read(addr, 24)).split(b'\0')[0].decode('latin1')


def _get_property(m, name, k):
    """provider->getProperty(const char*): the world decides per property name"""
    return m.props.get(_cstring(m, arg(m, 1)), 0)


def _sysctl(m, name, k):
    """sysctlbyname("hw.memsize", &value64, &len, 0, 0)"""
    if m.memsize is None:
        return 2
    m.w32(arg(m, 1), m.memsize >> 32); m.w32(arg(m, 1) + 4, m.memsize & 0xffffffff)
    return 0


def _create_agp_space(m, name, k):
    """provider->createAGPSpace(0, &this->0x838, &size): may fail, may shrink the size"""
    if m.agp_fail:
        return 0xe00002bc
    m.w32(arg(m, 2), 0x40000000)
    m.w32(arg(m, 3), m.agp_size)
    return 0


def _malloc_contig(m, name, k):
    """IOMallocContiguous(size, align, &phys): a zeroed region of that size, or NULL"""
    if m.no_table:
        return 0
    m.w32(arg(m, 2), 0x30000000)
    return m.alloc(arg(m, 0))


def _value64(m, name, k):
    m.uc.reg_write(UC_PPC_REG_4, m.value64 & 0xffffffff)
    return m.value64 >> 32


CONFIGURE_AGP_MOCK = mocker(**{'safeMetaCast': lambda m, n, k: arg(m, 0) if arg(m, 0) in m.castable else 0,
                               'IOAGPDevice [vcall +0x188]': _get_property, 'sysctlbyname': _sysctl,
                               'IOAGPDevice [vcall +0x5dc]': _create_agp_space, 'IOMallocContiguous': _malloc_contig,
                               'OSNumber [vcall +0xe8]': lambda m, n, k: m.flags, 'OSNumber [vcall +0xec]': _value64})


def w_configure_agp(m, rng):
    a = accel(m, rng, 0x1000)
    m.w32(a + 0x98, rng.choice([0, 0, 0x100]))
    prov = foreign(m, rng, 'IOAGPDevice', sigs={0x188: ['this', 'p'], 0x5dc: ['this', 'i', 'p', 'p']}); m.w32(a + 0x74, prov)
    num = foreign(m, rng, 'OSNumber', sigs={0xe8: ['this'], 0xec: ['this']}); other = foreign(m, rng, 'OSObject')
    m.castable = set(x for x in (prov, num) if rng.random() < 0.8)
    m.props = {'IOAGPFlags': rng.choice([num, num, other, 0]), 'IOPCIExpressLinkStatus': rng.choice([0, other])}
    m.flags = rng.choice([0, 2, 4, 6, 0x20, 0x26])
    m.value64 = rng.choice([0, 1, 0x100000001, 0x200000000, 3])
    m.memsize = rng.choice([None, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x100000000, 0x1f0000000, 0x8010000])
    m.agp_fail = rng.random() < 0.2
    m.agp_size = rng.choice([0x1000000, 0x2000000, 0x20000000, 0x8000000, 0x1ffc00, 0x400])
    m.no_table = rng.random() < 0.15
    return [a, prov]


def w_stop(m, rng):
    a = accel(m, rng)
    m.w32(a + 0xb4, foreign(m, rng, 'IOWorkLoop', sigs={0xe8: ['this', 'p']}))
    for off in (0xb8, 0xbc, 0xc0, 0xc4):
        m.w32(a + off, rng.choice([0, foreign(m, rng, 'IOEventSource')]))
    if rng.random() < 0.15:                                   # no workloop (so no event sources either: removeEventSource would dereference it)
        m.w32(a + 0xb4, 0)
        for off in (0xb8, 0xbc, 0xc0, 0xc4): m.w32(a + off, 0)
    ring(m, a + 0x63c, [tex_node(m, rng) for _ in range(rng.choice([0, 1, 3]))], 0x28, 0x24)
    m.w32(a + 0x98, rng.choice([0, 1, 1, 2]))
    m.w32(a + 0x22c, rng.choice([0, foreign(m, rng, 'IOBufferMemoryDescriptor')]))
    m.w32(a + 0xcc, rng.choice([0, 1, 2]))
    for i in range(2):
        for off in (0xd8, 0xdc, 0xe0):
            m.w32(a + off + 0x20 * i, rng.choice([0, foreign(m, rng, 'IOMemoryDescriptor')]))
    m.w32(a + 0x7c, rng.choice([0, foreign(m, rng, 'IONotifier')]))
    if rng.random() < 0.15: m.w32(a + 0x840, 0)
    return [a, foreign(m, rng, 'IOService')]


CASES = [
    Case('IOATIR500Accelerator::garbage_collector_timer', w_timer(0xbc), ret='void', seeds=8),
    Case('IOATIR500Accelerator::gart_collector_timer', w_timer(0xc4), ret='void', seeds=8),
    Case('IOATIR500Accelerator::commitAGPMemory', w_agp_call, ret='u32', seeds=12),
    Case('IOATIR500Accelerator::releaseAGPMemory', w_agp_call, ret='u32', seeds=12),
    Case('IOATIR500Accelerator::removeFromGART', w_remove_gart, ret='void', seeds=24, mock=GART_MOCK),
    Case('IOATIR500Accelerator::addToMinMaxGART', w_add_minmax, ret='u32', seeds=40, mock=GART_MOCK),
    Case('IOATIR500Accelerator::writePerformanceStats', w_perf_stats, ret='void', seeds=8, mock=STATS_MOCK),
    Case('IOATIR500Accelerator::freeAllCommandBuffers', w_free_all_cmd, ret='void', seeds=12),
    Case('IOATIR500Accelerator::disp_mode_did_change', w_disp_did, ret='bool', seeds=30),
    Case('IOATIR500Accelerator::disp_mode_will_change', w_disp_will, ret='bool', seeds=40),
    Case('IOATIR500Accelerator::findFramebuffers', w_find_fb, ret='bool', seeds=40, mock=FIND_FB_MOCK),
    Case('IOATIR500Accelerator::freeCommandBuffer', w_free_cmd_buf, ret='void', seeds=20),
    Case('IOATIR500Accelerator::freeOneDataBuffer', w_free_data_buf, ret='void', seeds=30),
    Case('IOATIR500Accelerator::addOrphanTexture', w_add_orphan, ret='void', seeds=24),
    Case('IOATIR500Accelerator::pageOffDataBuffer', w_page_off, ret='void', seeds=40, mock=PAGEOFF_MOCK),
    Case('IOATIR500Accelerator::free_gart_wirings', w_free_gart_wirings, ret='void', seeds=60, mock=GARTWIRE_MOCK),
    Case('IOATIR500Accelerator::freeToAllocSurfaceVRAM', w_free_surface_vram, ret='u32', seeds=60),
    Case('IOATIR500Accelerator::configureAGP', w_configure_agp, ret='bool', seeds=60, mock=CONFIGURE_AGP_MOCK, limit=1500000, ignore_args={'sysctlbyname': [5]}),
    Case('IOATIR500Accelerator::stop', w_stop, ret='void', seeds=60),
]
