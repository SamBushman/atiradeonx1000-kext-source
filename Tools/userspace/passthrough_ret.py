#!/usr/bin/env python3
"""passthrough_ret.py DIS LEDGER PARTS_DIR - stock functions that return a callee's result without touching r3 (issue #65/#68).

A stock function whose `blr` is reached straight from a `bl` / `bctrl` (only epilogue instructions in between, none writing r3) returns whatever the
callee returned. ghidra2c declares every function `int`, but when the decompiler believed the callee void it emitted `call(...); return;` - the rebuilt
function then returns whatever r3 happens to hold, which is the callee's result only by register luck: an instrumented (-finstrument-functions) build calls
__cyg_profile_func_exit before returning and clobbers it (glprog _ShConstructCompiler, found that way, 2026-09-26). ret_used.py only audits callees that a
STOCK caller in the same image reads, so exported entry points called from outside the image are invisible to it; this tool looks at the returning side.

Output, one row per stock function with such a path:
  TAIL   the C function ends `call(...); return;` (valueless) - a defect: the C must `return call(...);`
  ANY    the C function has a valueless `return;` somewhere but does not end in one - listed for review
  OK     every `return` in the C carries a value
JOIN paths (the blr is a branch target, several r3 sources) are counted, not analysed."""
import sys, re, os, glob

dis, ledger, parts = sys.argv[1:4]
ins = []      # (addr, op, args)
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l)
    if m: ins.append((int(m.group(1), 16), m.group(2), m.group(3).split(';')[0].strip()))
idx = {a: i for i, (a, _, _) in enumerate(ins)}
funcs = []
for l in open(ledger):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 5 and f[4] == 'converted': funcs.append((int(f[0], 16), int(f[1]), f[2], f[3]))

# C bodies by the `@ 0xADDR (N bytes)` comment
body = {}
for p in sorted(glob.glob(os.path.join(parts, 'part_*.c'))):
    txt = open(p, errors='replace').read()
    ms = list(re.finditer(r'^/\* .* @ 0x([0-9a-f]+) \(\d+ bytes\) \*/\n', txt, re.M))
    for k, m in enumerate(ms):
        body[int(m.group(1), 16)] = txt[m.end(): ms[k + 1].start() if k + 1 < len(ms) else len(txt)]

BR_UNCOND = ('b', 'ba', 'bctr', 'blr')
NOWRITE = ('st', 'cmp', 'fcmp', 'mt', 'dcb', 'icb', 'sync', 'isync', 'eieio', 'b', 'tw', 'lf', 'fmr', 'mcrf', 'cr')
def writes_r3(op, args):
    if op == 'mfcr': return args.split(',')[0].strip() == 'r3'
    if op.startswith(NOWRITE): return False
    a = args.split(',')
    if op == 'lmw': return int(re.sub(r'\D', '', a[0]) or 99) <= 3
    return a[0].strip() == 'r3'

def is_call(op): return op in ('bl', 'bl+', 'bl-', 'bctrl', 'blrl', 'bla')

rows = []; joins = 0
for a, size, name, part in funcs:
    if a not in idx: continue
    i0 = idx[a]; n = size // 4; seq = ins[i0:i0 + n]
    targets = set()
    for (x, op, args) in seq:
        if is_call(op): continue
        if op.startswith('b') and op not in ('blr', 'bctr'):
            m = re.search(r'0x([0-9a-f]+)', args)
            if m: targets.add(int(m.group(1), 16))
    passes = 0; joinp = 0
    for j, (x, op, args) in enumerate(seq):
        if op != 'blr': continue
        if x in targets: joinp += 1; continue
        k = j - 1; res = None
        while k >= 0:
            xa, op2, a2 = seq[k]
            if seq[k + 1][0] in targets: res = 'join'; break
            if is_call(op2): res = 'pass'; break
            if writes_r3(op2, a2): res = 'writes'; break
            if op2.startswith('b'): res = 'join'; break     # reached through a branch: several sources
            k -= 1
        if res == 'pass': passes += 1
        elif res == 'join': joinp += 1
    joins += joinp
    if not passes: continue
    c = body.get(a, '')
    ret_void = len(re.findall(r'^\s*return\s*;', c, re.M))
    tail = re.search(r';\n\s*return\s*;\n\}\s*$', c.rstrip() + '\n') is not None
    cls = 'TAIL' if tail else ('ANY' if ret_void else 'OK')
    rows.append((cls, hex(a), name, part, passes, ret_void))
for r in sorted(rows, key=lambda r: (r[0], r[1])): print('%s\t%s\t%s\t%s\tpass-blr=%d\tvoid-returns=%d' % r)
c = {}
for r in rows: c[r[0]] = c.get(r[0], 0) + 1
print('# %d functions with a clean call->blr path; %s; %d blr reached through joins (not analysed)' % (len(rows), ' '.join('%s=%d' % kv for kv in sorted(c.items())), joins), file=sys.stderr)
