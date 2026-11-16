#!/usr/bin/env python3
"""libgl_stub_check.py STOCK REBUILT LEDGER SYMMAP NM FUNCS NARGS [name-filter]  -  the libGL entry stubs (`ctx = *current_ctx_cell; if thread-marker mismatch: fetch; tail-jump through ctx[slot]`).
With a NULL context every stub faults at once, in both images, so the generic census (random arena) proves nothing beyond the crash.  Here the current-context cell is found per image (the last 4-byte
zero read before the fault), made to point at a context in the arena whose thread marker (+0xab0) matches the stack and whose dispatch slots are distinct call-out stubs, and the stub is run with distinct
integer and floating arguments: both images must tail-call the SAME slot with the same argument registers (r3 = ctx[0] and the arguments shifted as the stock does), the same f1..f13, and return alike.
Prints one line per differing stub and a summary; the compared record is (slot call-out name, r3..r10 as received, f1..f13)."""
import sys, struct
import trace_diff as t
from unicorn import UC_HOOK_MEM_READ
from unicorn.ppc_const import *
stock, reb, ledger, symmap, nm, funcs, nargs = sys.argv[1:8]; filt = sys.argv[8] if len(sys.argv) > 8 else None
t._init(stock, reb, symmap, nm, ledger, funcs, nargs, 0, None)
S, R = t._G['sims']['A']
base_names = len(S.names); NSLOT = 0x300      # call-out names for ctx words 1..0x2ff (ctx words up to 0x3ff exist; a stub using a slot beyond 0x2ff would show as a differing or failing record)
S.names.extend('SLOT_%d' % j for j in range(NSLOT))
assert R.names is S.names or R.names.extend('SLOT_%d' % j for j in range(NSLOT)) is None
ids = S.ids
SP0 = t.STACK + t.STACK_SIZE - 0x2000
reads = []
def hook(uc, access, addr, size, value, ud): reads.append((addr, size))
for sim in (S, R): sim.uc.hook_add(UC_HOOK_MEM_READ, hook)
ZERO = bytes(t.ARENA_SIZE)
def find_cell(sim, entry):
    reads.clear(); sim.run(entry, [0x1001, 0x1002, 0x1003, 0x1004, 0x1005, 0x1006, 0x1007, 0x1008], [], [], ZERO)
    for a, s in reversed(reads):
        if s == 4 and sim.img.lo <= a - sim.slide < 0x7fffffff and not (sim.img.lo <= a - sim.slide < sim.img.end and False):
            try:
                if int.from_bytes(bytes(sim.uc.mem_read(a, 4)), 'big') == 0 and a >= 0x1000 and a not in (t.ARENA,): return a
            except Exception: pass
    return None
def ctxarena():
    a = bytearray(t.ARENA_SIZE); c = 0x1000
    a[c:c + 4] = struct.pack('>I', 0x7a7a7a7a)
    for j in range(1, 0x400):
        if j * 4 == 0xab0: continue
        a[c + 4 * j:c + 4 * j + 4] = struct.pack('>I', t.CALLOUT + 16 * (ids_len + j) if (ids_len + j) < 4096 else 0)
    a[c + 0xab0:c + 0xab4] = struct.pack('>I', SP0 - 0x100)
    return bytes(a)
# call-out index = len(names before extension) + j: slot j's name is 'SLOT_<j-?>'
ids_len = base_names - 1          # names[ids_len + j] == SLOT_(j-1)
ARENA_CTX = t.ARENA + 0x1000
def run(sim, entry):
    cell = find_cell(sim, entry)
    if cell is None: return None
    sim.snap.append((cell, struct.pack('>I', ARENA_CTX)))
    try:
        st, ev, regs, cov = sim.run(entry, [0x1001, 0x1002, 0x1003, 0x1004, 0x1005, 0x1006, 0x1007, 0x1008], [struct.unpack('>Q', struct.pack('>d', 1.5 + k))[0] for k in range(13)], [0x2001 + k for k in range(16)], ctxarena())
    finally: sim.snap.pop()
    rec = [(e[0], e[1], tuple(x.raw if hasattr(x, 'raw') else x for x in e[2])) for e in ev if e[0] == 'C']
    return st, rec, regs['f1'], regs['r1'], [e for e in ev if e[0] == 'F']
rows = t.read_ledger(ledger, t.macho(stock)[6], t.macho(reb)[6]); rows = [r for r in rows if r['name'].startswith('_gl') or r['name'].startswith('gl') or r['name'].startswith('_CGL')]
if filt: rows = [r for r in rows if r['name'] == filt]
INPUTS = {0x1001 + k for k in range(8)} | {0x7a7a7a7a}
def equiv(a, b):
    """the stock's tail-call record is the reference: a register it passes on (an input value or the context word) must arrive identically from the rebuilt stub; a register the stock itself clobbers (a scratch value
    such as the result of its thread-marker test) is not an argument and is ignored"""
    if a is None or b is None or a[0] != b[0] or a[2:] != b[2:] or len(a[1]) != len(b[1]): return False
    for (ka, na_, ra), (kb, nb_, rb) in zip(a[1], b[1]):
        if na_ != nb_ or len(ra) != len(rb): return False
        for x, y in zip(ra, rb):
            if x in INPUTS and x != y: return False
    return True
import os
CONTROL = bool(os.environ.get('CONTROL'))      # mismatch control: pair each stock stub with the NEXT stub of the rebuilt image; every pair must differ
n = ok = nocell = 0; slots = set()
for i, r in enumerate(rows):
    a = run(S, r['stock']); b = run(R, rows[(i + 1) % len(rows)]['reb'] if CONTROL else r['reb']); n += 1
    if a and a[1]: slots.add(a[1][0][1])
    if a is None or b is None: nocell += 1; print('NOCELL', r['name'], 'stock' if a is None else '', 'rebuilt' if b is None else ''); continue
    if equiv(a, b) and a[0] == 'RET' and a[1]: ok += 1
    else: print('DIFF' if not equiv(a, b) else 'NOCALL', r['name'], a, '|', b)
print('distinct slots reached (stock): %d' % len(slots))
print('stubs %d, identical tail-call records %d, no cell/other %d' % (n, ok, n - ok))
