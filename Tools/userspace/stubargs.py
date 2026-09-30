#!/usr/bin/env python3
"""stubargs.py IMAGE_BIN CORPUS_DIR [NAME_FILTER]  - argument-count check for calls that go through a dyld stub (`bl` into __picsymbolstub1), the calls the
`.dis`-based tools (inreg_liveness.py, callarg_check.py's callee follow) cannot see (project note: picsymbolstub gap). The callee's arity is unknown, so the
evidence is the caller's own basic block: an argument register r4..r10 that is WRITTEN in the block before the `bl` and whose value nobody reads before the
call (a temporary that feeds a later instruction is not an argument) was set up for the callee. Every stock call site needs at least (highest such register - 2)
arguments; the corpus C of that function must have a call to the same callee with that many. Sites are paired with the C calls greedily, largest first.
Prints `NEED n HAVE m` rows (a dropped argument: the rebuilt callee reads whatever the register held) and a summary. Heuristic - candidates, not proof:
a register set for a second call sharing the block and left live is the usual false positive.
Frame-size pairing note: chunks of 16 bytes or less (Ghidra's split entry `FUN_00029290 @ 4 bytes`) are merged with the chunk that follows them, because
Ghidra printed the whole function under the short one."""
import sys, re, glob, struct, os, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import machoutil, capstone
from capstone.ppc import *

img, corp = sys.argv[1:3]
flt = sys.argv[3] if len(sys.argv) > 3 else None
m = machoutil.load(img)
md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
md.detail = True
# stub address -> symbol name
stubs = {}
for s in m.secs:
    if s['name'] in ('__picsymbolstub1', '__symbol_stub1', '__jump_table') and s['r2']:
        for k in range(s['size'] // s['r2']):
            si = m.indirect[s['r1'] + k]
            if si < len(m.syms):
                stubs[s['addr'] + k * s['r2']] = m.syms[si]['name']
text = [s for s in m.secs if s['name'] == '__text'][0]
code = m.read(text['addr'], text['size']); base = text['addr']
words = struct.unpack('>%dI' % (len(code) // 4), code)
# branch targets (basic-block starts)
targets = set()
for i, w in enumerate(words):
    a = base + 4 * i; op = w >> 26
    if op == 18 and not (w & 1):
        d = w & 0x03fffffc
        if d & 0x2000000: d -= 0x4000000
        targets.add((0 if w & 2 else a) + d & 0xffffffff)
    elif op == 16:
        d = w & 0xfffc
        if d & 0x8000: d -= 0x10000
        targets.add((0 if w & 2 else a) + d & 0xffffffff)

def reg_num(r):
    n = md.reg_name(r)
    mm = re.match(r'r(\d+)$', n or '')
    return int(mm.group(1)) if mm else None

def block_args(a):
    """{reg: pos} of argument registers r4..r10 written and not consumed in the basic block ending at the call at a; walking backwards"""
    written = {}; read_later = set()
    j = (a - base) // 4 - 1
    n = 0
    while j >= 0 and n < 60:
        pa = base + 4 * j; w = words[j]
        op = w >> 26
        if op in (16, 18) or (op == 19 and (w >> 1) & 0x3ff not in (150, 0)):   # a branch (incl. blr/bctr/bctrl) ends the block; isync/mcrf do not
            break
        for i in md.disasm(struct.pack('>I', w), pa):
            wr, rd = set(), set()
            regs = []
            for o in i.operands:
                if o.type == PPC_OP_REG: regs.append(('r', reg_num(o.reg)))
                elif o.type == PPC_OP_MEM: regs.append(('m', reg_num(o.mem.base)))
            mn = i.mnemonic.rstrip('.')
            no_dest = mn.startswith(('st', 'cmp', 'mt', 'tw', 'dcb', 'icb', 'sync', 'eieio', 'cr')) or mn in ('nop',)
            for k, (kind, r) in enumerate(regs):
                if r is None: continue
                if kind == 'm': rd.add(r)
                elif k == 0 and not no_dest:
                    wr.add(r)
                    if mn in ('rlwimi',): rd.add(r)
                else: rd.add(r)
            for r in rd: read_later.add(r)
            for r in wr:
                if 3 <= r <= 10 and r not in written and r not in read_later:
                    written[r] = pa
        if pa in targets: break
        j -= 1; n += 1
    return written

def split_args(s):
    out = []; d = 0; cur = ''; q = None; esc = False
    for ch in s:
        if q:
            cur += ch
            if esc: esc = False
            elif ch == '\\': esc = True
            elif ch == q: q = None
            continue
        if ch in '"\'': q = ch; cur += ch
        elif ch in '([{': d += 1; cur += ch
        elif ch in ')]}': d -= 1; cur += ch
        elif ch == ',' and d == 0: out.append(cur); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur)
    return out

# corpus chunks
chunks = []   # (name, addr, size, text)
for p in sorted(glob.glob(os.path.join(corp, 'part_*.c'))):
    t = open(p, errors='replace').read()
    hs = list(re.finditer(r'(?m)^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\)', t))
    for i, h in enumerate(hs):
        e = hs[i + 1].start() if i + 1 < len(hs) else len(t)
        chunks.append([h.group(1), int(h.group(2), 16), int(h.group(3)), t[h.start():e]])
chunks.sort(key=lambda c: c[1])
merged = []
i = 0
while i < len(chunks):
    c = chunks[i]
    if c[2] <= 16 and i + 1 < len(chunks) and chunks[i + 1][1] <= c[1] + 16:
        n = chunks[i + 1]
        merged.append([c[0], c[1], n[1] + n[2] - c[1], [c[3], n[3]]]); i += 2
    else:
        merged.append(c[:3] + [[c[3]]]); i += 1
starts = [c[1] for c in merged]
import bisect
def chunk_of(a):
    k = bisect.bisect_right(starts, a) - 1
    if k >= 0 and a < merged[k][1] + merged[k][2]: return merged[k]
    return None

import subprocess, functools
@functools.lru_cache(None)
def spellings(callee):
    """the names the corpus may print for a stub symbol: itself, and for a mangled C++ name the demangled `A::b` written `A__b` (templates and parameter list dropped)"""
    out = [callee]
    if callee.startswith('__Z'):
        d = subprocess.run(['c++filt', callee[1:]], capture_output=True, text=True).stdout.strip()
        d = re.sub(r'\([^()]*\)( const)?$', '', d)
        prev = None
        while prev != d:
            prev = d; d = re.sub(r'<[^<>]*>', '', d)
        parts = d.split('::')
        for k in range(len(parts)):
            out.append('__'.join(parts[k:]))
            out.append('_' + '__'.join(parts[k:]))
    return out

def c_calls(text, callee):
    out = []
    for nm in spellings(callee):
        out += c_calls1(text, nm)
        if out: break
    return out

def c_calls1(text, callee):
    out = []
    for mm in re.finditer(r'(?<![\w])(?:\(\s*\(\s*int\s*\(\s*\*\s*\)\s*\(\s*\)\s*\)\s*)?%s\s*\)?\s*\(' % re.escape(callee), text):
        k = mm.end(); d = 1; q = None; esc = False; s = k
        while k < len(text) and d:
            ch = text[k]
            if q:
                if esc: esc = False
                elif ch == '\\': esc = True
                elif ch == q: q = None
            elif ch in '"\'': q = ch
            elif ch == '(': d += 1
            elif ch == ')': d -= 1
            k += 1
        out.append(len(split_args(text[s:k - 1])))
    return out

need = collections.defaultdict(list)   # (chunk name, callee) -> [(need, addr)]
for i, w in enumerate(words):
    if w >> 26 == 18 and w & 1:
        a = base + 4 * i
        d = w & 0x03fffffc
        if d & 0x2000000: d -= 0x4000000
        t = (a + d) & 0xffffffff
        if t not in stubs: continue
        ch = chunk_of(a)
        if not ch: continue
        if flt and flt not in ch[0] and flt not in stubs[t]: continue
        wr = block_args(a)
        hi = max([r for r in wr if r >= 3] + [2])
        need[(ch[0], stubs[t])].append((hi - 2, a))
bad = 0; total = 0
byname = {c[0]: c for c in merged}
for (fn, callee), lst in sorted(need.items()):
    nd = sorted(lst, reverse=True)
    for txt in byname[fn][3]:      # a merged (split-entry) chunk: every printed copy of the function must carry the arguments
        have = sorted(c_calls(txt, callee), reverse=True)
        for k, (n, a) in enumerate(nd):
            h = have[k] if k < len(have) else None
            if h is None and len(byname[fn][3]) > 1: continue      # this copy is only the tail without that call
            if h is None:
                print('%s %s@%x NEED %d HAVE none' % (fn, callee, a, n)); bad += 1
            elif h < n:
                print('%s %s@%x NEED %d HAVE %d' % (fn, callee, a, n, h)); bad += 1
    total += len(nd)
print('stub call sites %d, candidates short of arguments %d' % (total, bad))
