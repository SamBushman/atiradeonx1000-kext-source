#!/usr/bin/env python3
"""frame_layout.py CORPUS_DIR [--apply]      (issue #83: stack locals that a callee reaches through a pointer)

Ghidra splits a stack frame into separately named variables (`undefined1 auStack_a8 [4]; undefined4 local_a4; undefined1 auStack_a0 [32];`) but the code passes
`auStack_a8` to a callee that writes 40 bytes starting there (a descriptor: word 0 = kind, word 1 = index, words 2..9 = a table). gcc lays the separate
variables out in an order and with gaps of its own, so `local_a4` was never written: emulating the stock and the rebuilt FUN_00099e50 on the same context gave
r5 = 1 (stock) and 0 (rebuilt) for the first dispatch call.

For every function that takes the address of a stack variable or has an `auStack_` array, all its stack variables (`local_XX`, `uStack_XX`, `auStack_XX`, ...
named by their offset below the entry stack pointer) move into ONE `frame_` array in that exact relative layout:
    address(XX) = frame_ + SIZE - XX          (SIZE = the largest offset, rounded up to 16; frame_ is 16-byte aligned like the stock's frame)
A scalar `local_a4` is then `(*(undefined4 *)((char *)frame_ + OFF))`, an array `auStack_a8` is `((undefined1 *)((char *)frame_ + OFF))`.
Variables above the entry stack pointer (`uStack0000002c`: the caller's outgoing-argument area) stay ordinary locals."""
import re, sys, glob, os

SIZES = {'undefined4': 4, 'int': 4, 'uint': 4, 'float': 4, 'undefined1': 1, 'char': 1, 'byte': 1, 'bool': 1, 'undefined2': 2, 'short': 2, 'ushort': 2,
         'undefined8': 8, 'longlong': 8, 'ulonglong': 8, 'double': 8, 'undefined': 1, 'code': 4, 'long': 4, 'ulong': 4, 'uchar': 1, 'undefined3': 3, 'undefined5': 5,
         'undefined6': 6, 'undefined7': 7, 'sbyte': 1, 'unsigned': 4, 'size_t': 4}
NAME = re.compile(r'^(?:\w*?Stack|local)_([0-9a-f]+)$')
DECL = re.compile(r'^  (.+?[ *])(\w+)(?: \[(\d+)\])?;$')

def transform(body):
    lines = body.split('\n')
    try: start = lines.index('{') + 1
    except ValueError: return None
    end = start
    while end < len(lines) and lines[end].strip() != '': end += 1        # the declarations end at the first blank line
    vars_ = []
    for i in range(start, end):
        m = DECL.match(lines[i])
        if not m: continue
        ty, name, n = m.group(1).strip(), m.group(2), int(m.group(3)) if m.group(3) else None
        nm = NAME.match(name)
        if not nm: continue
        xx = int(nm.group(1), 16)
        esz = 4 if ty.endswith('*') else SIZES.get(ty.split()[-1])
        if esz is None: continue
        vars_.append((name, ty, n, esz, xx, i))
    if not vars_: return None
    rest = '\n'.join(lines[end:])
    if not any(re.search(r'&\s*%s\b' % re.escape(v[0]), rest) or v[2] is not None for v in vars_): return None
    size = (max(v[4] for v in vars_) + 15) & ~15
    reps = {}
    for name, ty, n, esz, xx, i in vars_:
        off = size - xx
        reps[name] = ('((%s *)((char *)frame_ + %d))' if n is not None else '(*(%s *)((char *)frame_ + %d))') % (ty, off)
    pat = re.compile(r'\b(?:' + '|'.join(re.escape(k) for k in sorted(reps, key=len, reverse=True)) + r')\b')
    gone = {v[5] for v in vars_}
    arrs = [re.escape(v[0]) for v in vars_ if v[2] is not None]
    def _fix(l):
        # `&auStack_a8` / `&(auStack_a8)` (a unary &) is the array's address: the array expression already is; a binary `x & auStack_a8[0]` stays
        def one(m):
            before = l[:m.start()].rstrip()
            if before and (before[-1].isalnum() or before[-1] in '_)]') and not re.search(r'\(\s*(?:unsigned |signed |const )?\w+(?:\s+\w+)*\s*\*+\s*\)$', before): return m.group(0)
            return m.group(1) or m.group(2)
        return re.sub(r'&\s*\(\s*(%s)\s*\)|&\s*(%s)\b' % ('|'.join(arrs), '|'.join(arrs)), one, l)
    fix = _fix if arrs else (lambda l: l)
    sub = lambda l: pat.sub(lambda m: reps[m.group(0)], fix(l))
    out = lines[:start] + [sub(lines[i]) for i in range(start, end) if i not in gone] + ['  unsigned int frame_[%d] __attribute__((aligned(16)));' % (size // 4)] + [sub(l) for l in lines[end:]]
    return '\n'.join(out), len(vars_), size

def main(corpus, apply_):
    total = 0; nfun = 0
    for f in sorted(glob.glob(os.path.join(corpus, 'part_*.c'))):
        s = open(f).read(); out = []; pos = 0; changed = False
        for m in re.finditer(r'(?m)^/\* (FUN_\w+) @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n', s):
            e = s.find('\n}\n', m.end())
            if e < 0: continue
            e += 2
            body = s[m.end():e]
            r = transform(body)
            if r is None: continue
            out.append(s[pos:m.end()]); out.append(r[0]); pos = e; changed = True; total += r[1]; nfun += 1
        out.append(s[pos:])
        if changed and apply_: open(f, 'w').write(''.join(out))
    print(nfun, 'functions,', total, 'stack variables moved into frame_')

if __name__ == '__main__': main(sys.argv[1], '--apply' in sys.argv)
