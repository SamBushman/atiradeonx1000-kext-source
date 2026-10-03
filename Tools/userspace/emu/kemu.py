#!/usr/bin/env python3
"""kemu.py - issue #42: run the STOCK KEXT's real PPC machine code of a process_command_buffer dispatcher (GL/2D/DVD) in a PPC emulator (unicorn), with a
hand-built "self" context and command buffer, so an opcode that hung the live 2D test (t3_2d_inject, G5 unresponsive 2026-10-03) can be tried with ZERO
risk to real hardware: the emulator's own sandboxed memory is the only thing that can be corrupted.

Why this works without any Mach-O relocation of the kext (an unlinked MH_OBJECT, 11622 relocations in __text alone): the kext's __TEXT/__DATA segment has
vmaddr 0 in the raw .bin (confirmed: the symbol value for ATIR5002DContext::process_command_buffer is 0x326d0, exactly the "real addr" the Ghidra decompile
headers already use) - loading the image's raw bytes at Unicorn address 0 makes every PC-relative branch AND every already-baked long-branch trampoline
(`lis r12,HI16; ori r12,r12,LO16; mtctr r12; bctr` - this binary's calling convention for calls outside +-32MB, confirmed via PPC_RELOC_JBSR entries: an
intra-kext trampoline's hi/lo already encode the correct 0-based target, e.g. target 0xbb40 for a call to ATIR5002DContext::start found by direct symbol lookup)
resolve correctly with NO slide and NO relocation pass. A genuinely EXTERNAL symbol's trampoline (checked: _IOGetTime, an undefined kernel API) is left
UNRELOCATED by the static linker (hi=lo=0 in the raw bytes), so it naturally lands at address 0 - which this harness maps as "stub: return 0 to the caller",
the same convention Tools/userspace/emu/emu.py already uses for dyld stubs. Caveat: an external call whose leftover bytes are NOT exactly (0,0) could wrongly
land somewhere else; this harness reports (not silently ignores) any STATUS other than RET, and the code hook flags a jump outside the kext's own mapped range.

Sandbox memory layout (well above the ~0x4e000 kext image, no collision): STACK=0x7f000000, SELF=0x20000000 (the context object), BUF=0x30000000 (the
command buffer: the stream starts at BUF+0x1c, matching Tools/userspace/opcode_recorder.c's g_start=0x1c), STUBLO=0x10 (every code-hook target < 0x1000 or
outside the kext's mapped ranges auto-returns 0 to LR, covering externals and any vtable slot we point there).

Usage: kemu.py {gl|2d|dvd} RECORDS [--self k=v,...] [--dump N]
  RECORDS is a comma-separated list of hex words (the raw stream written at BUF+0x1c, same shape as Tools/userspace/run_inject.sh's OPCODE_INJECT_WORDS); a
  terminator word (0) is appended if the list doesn't already end in one.
  --self k=v sets a field in the fake context before the call (e.g. ac=0x30000000 for 2D's "current buffer" pointer, already the default).
Prints: emulator STATUS, instruction count, and the stream bytes read back from BUF - the same observable INJECT-POST comparison used live.
"""
import sys, struct, os
sys.path.insert(0, '/tmp/upkgs')
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'userspace'))
from unicorn import *
from unicorn.ppc_const import *
import machoutil

KEXT = os.environ.get('KEXT_BIN', os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000.kext.bin'))
STACK, STACK_SIZE = 0x7f000000, 0x100000
SELF, SELF_SIZE = 0x20000000, 0x4000
BUF, BUF_SIZE = 0x30000000, 0x40000
ACCEL, ACCEL_SIZE = 0x21000000, 0x4000     # fake accelerator object (self+0x94 for 2D, self+0x200 for GL point here)
STUB = 0x10                                 # every sub-0x1000 / out-of-image call target returns 0 to LR here

DISPATCH = {
    'gl':  ('__ZN16ATIR500GLContext22process_command_bufferEP23VendorCommandDescriptor', dict(bufoff=0xe0, accoff=0x290, accoff2=0x200)),
    '2d':  ('__ZN16ATIR5002DContext22process_command_bufferEP23VendorCommandDescriptor', dict(bufoff=0xac, accoff=0x94, accoff2=0x94)),
    'dvd': ('__ZN17ATIR500DVDContext22process_command_bufferEP23VendorCommandDescriptor', dict(bufoff=0xa4, accoff=0x8c, accoff2=0xf8)),  # 0xa4 buffer (verified: puVar40 = M<SInt32>(self+0xa4)+0x1c), 0x8c accelerator, 0xf8 bound surface (both read-only stand-ins here)
}


def load_kext():
    m = machoutil.load(KEXT)
    assert m.filetype == 1, 'expected an MH_OBJECT (unlinked kext)'
    seg = m.segs[0]
    assert seg['vmaddr'] == 0, 'expected the kext image to be based at vmaddr 0 (see module docstring)'
    return m, seg


def addr_of(m, name):
    for s in m.syms:
        if s['name'] == name:
            return s['value']
    raise KeyError(name)


class Runner:
    def __init__(self):
        self.m, seg = load_kext()
        data = seg['data'] if 'data' in seg else None
        self.uc = uc = Uc(UC_ARCH_PPC, UC_MODE_PPC32 | UC_MODE_BIG_ENDIAN)
        vs = seg['vmsize']
        pad = (vs + 0xfff) & ~0xfff
        uc.mem_map(0, pad)
        if data is None:
            data = self.m.d[seg['fileoff']:seg['fileoff'] + seg['filesize']]
        uc.mem_write(0, data)
        self.image_end = vs
        for base, size in ((STACK, STACK_SIZE), (SELF, SELF_SIZE), (BUF, BUF_SIZE), (ACCEL, ACCEL_SIZE)):
            uc.mem_map(base, size)
        self.autopages = []
        self.outside_calls = []
        uc.hook_add(UC_HOOK_CODE, self._code_hook)
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self._unmapped)
        self.n = 0; self.limit = 400000; self.status = '?'

    def _unmapped(self, uc, access, addr, size, value, ud):
        base = addr & ~0xfff
        try:
            uc.mem_map(base, 0x1000)
        except Exception:
            return False
        self.autopages.append(base)
        return True

    def _code_hook(self, uc, addr, size, ud):
        self.n += 1
        if self.n > self.limit:
            self.status = 'TIMEOUT'; uc.emu_stop(); return
        if addr == STOP:
            self.status = 'RET'; uc.emu_stop(); return
        if addr < 0x1000 or addr >= self.image_end:
            # a genuinely-external call (unrelocated trampoline landing at/near 0) or a vtable slot we deliberately pointed below 0x1000: stub it
            if addr >= 0x1000:
                self.outside_calls.append(addr)
            uc.reg_write(UC_PPC_REG_3, 0)
            uc.reg_write(UC_PPC_REG_PC, uc.reg_read(UC_PPC_REG_LR)); return

    def word(self, a):
        return struct.unpack('>I', bytes(self.uc.mem_read(a, 4)))[0]

    def call(self, entry, r3, r4, limit=400000):
        uc = self.uc; self.n = 0; self.limit = limit; self.status = '?'; self.outside_calls = []
        for i in range(32):
            uc.reg_write(UC_PPC_REG_0 + i, 0)
        uc.reg_write(UC_PPC_REG_1, STACK + STACK_SIZE - 0x2000)
        uc.reg_write(UC_PPC_REG_MSR, 0x2000)   # MSR_FP: several dispatchers save/restore FPRs (stfd) in their prologue/epilogue; unset FP traps on the first one
        uc.reg_write(UC_PPC_REG_3, r3); uc.reg_write(UC_PPC_REG_4, r4)
        uc.reg_write(UC_PPC_REG_LR, STOP)
        try:
            uc.emu_start(entry, STOP, count=limit + 10)
            if self.status == '?':
                self.status = 'RET'
        except UcError as e:
            self.status = 'ERR:%s' % e
        return self.status


STOP = 0x50000000


def build_stream(words):
    if not words or words[-1] != 0:
        words = words + [0]
    return b''.join(struct.pack('>I', w) for w in words)


def main():
    ctx, recwords = sys.argv[1], sys.argv[2]
    words = [int(x, 0) for x in recwords.split(',')]
    symname, off = DISPATCH[ctx]
    r = Runner()
    uc = r.uc
    uc.mem_map(STOP & ~0xfff, 0x1000)
    entry = addr_of(r.m, symname)

    # fake "self": the buffer pointer field (bufoff) holds BUF directly for every context - the scan pointer is always "buffer base" + 0x1c
    # (`M<SInt32>(self+0xac/0xe0/0xe8) + 0x1c`), matching where the stream is written below (BUF+0x1c). An earlier version of this harness
    # subtracted 0x20 for GL/DVD on a misreading of a SEPARATE local (`local_1c0 = base + 0x20`, unrelated to the scan pointer) - that bug made
    # the GL/DVD dispatcher read 4 bytes before the real stream (into an auto-zero-filled unmapped page), so it never saw the injected opcode
    # at all and silently fell into the texture-slot fast path instead - caught by cross-checking against the real compare-site address
    # from Tools/opcode_inventory.py's analyser, not by a crash (see pm4_opcode_gaps.md, 0x36 session).
    self_bytes = bytearray(SELF_SIZE)
    if ctx in ('2d', 'dvd'):
        struct.pack_into('>I', self_bytes, off['bufoff'], BUF)                 # puVar18/40 = M<SInt32>(self+0xac/0xa4) + 0x1c -> BUF + 0x1c
        struct.pack_into('>I', self_bytes, off['accoff'], ACCEL)               # accelerator ptr (self+0x94 for 2D, self+0x8c for DVD)
        if ctx == 'dvd':
            struct.pack_into('>I', self_bytes, off['accoff2'], ACCEL)          # self+0xf8: DVD's bound-surface pointer (zeroed stand-in - every surface-field read comes back 0)
    else:
        struct.pack_into('>I', self_bytes, off['bufoff'], BUF)                 # puVar65 = (UInt32*)(M<SInt32>(self+0xe0) + 0x1c) -> BUF + 0x1c
        struct.pack_into('>I', self_bytes, off['accoff'], ACCEL)
        struct.pack_into('>I', self_bytes, off['accoff2'], ACCEL)
        struct.pack_into('>I', self_bytes, 0x108, ACCEL + 0x100)               # puVar69 = M<UInt32*>(self+0x108): read as 6 words by the GL prologue (compute_sc_hyperz_en/compute_zb_bw_cntl args)
    uc.mem_write(SELF, bytes(self_bytes))
    uc.mem_write(ACCEL, bytes(ACCEL_SIZE))                                     # zeroed accelerator: table counts (+0x14) are 0, every texture/surface lookup goes out-of-range (safe no-op path)

    stream = build_stream(words)
    buf_bytes = bytearray(BUF_SIZE)
    buf_bytes[0x1c:0x1c + len(stream)] = stream
    uc.mem_write(BUF, bytes(buf_bytes))

    desc_addr = STACK + STACK_SIZE - 0x1000
    status = r.call(entry, SELF, desc_addr)
    print('status=%s insns=%d outside_calls=%s' % (status, r.n, [hex(a) for a in r.outside_calls[:10]]))
    nwords = len(words) + 4
    before = [struct.unpack('>I', stream[i:i+4])[0] if i + 4 <= len(stream) else 0 for i in range(0, nwords * 4, 4)]
    after = [r.word(BUF + 0x1c + 4 * i) for i in range(nwords)]
    print('before:', ' '.join('%08x' % w for w in before))
    print('after: ', ' '.join('%08x' % w for w in after))
    desc = [r.word(desc_addr + 4 * i) for i in range(4)]
    print('descriptor out {addr, size, nextSize, cur}: %08x %08x %08x %08x' % tuple(desc))


if __name__ == '__main__':
    main()
