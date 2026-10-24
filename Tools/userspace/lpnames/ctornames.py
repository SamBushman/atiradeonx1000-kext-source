#!/usr/bin/env python3
"""ctornames.py DIR PARTLO PARTHI OUT.spec : gspec lines for the IR class constructors / allocators of the GLDriver compiler.
A constructor stores `PTR_DAT_<nl_symbol_ptr entry> + 8` at *this; the nl_symbol_ptr entry holds the class's vtable address, and the vtable ->
class map is read from notes_compiler_ir.md (section 1.1). Emits: F rows for FUN_ functions (Class__ctor_<addr>, Class__new_<addr> for the
0x168-byte arena allocators that call a constructor), P rows for still-unnamed parameters (this/opcode/compiler by the base constructor call), L rows
for the vtable local."""
import sys, os, re, glob
d, lo, hi, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
vt = {}
for l in open(os.path.join(d, 'notes_compiler_ir.md')):
    m = re.match(r'\s*- `(\w+)` \(vtable `0x([0-9a-f]+)`', l)
    if m: vt[int(m.group(2), 16)] = m.group(1)
nl = {}
txt = open(os.path.join(d, 'data/DATA___nl_symbol_ptr.c')).read()
vals = re.findall(r'0x([0-9a-f]{8}), /\* -> (\S+) \*/', txt)
for i, (v, _) in enumerate(vals): nl[0x1e88a4 + 4 * i] = int(v, 16)
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
funcs = {}; order = []
for p in range(lo, hi + 1):
    cur = None
    for l in open(os.path.join(d, 'part_%03d.c' % p), errors='replace'):
        m = H.match(l)
        if m: cur = m.group(1); funcs[cur] = [m.group(2), []]; order.append(cur); continue
        if cur: funcs[cur][1].append(l.rstrip('\n'))
cls = {}   # function -> class (constructors)
CALL = re.compile(r'\(\(int \(\*\)\(\)\)(\w+)\)\(([^;]*)\);|\b(\w+)\(([^;]*)\);')
rows = []
def ctor_class(body):
    t = '\n'.join(body)
    m = re.search(r'(\w+) = PTR_DAT_([0-9a-f]+);', t)
    mm = re.search(r'\*(\w+) = PTR_DAT_([0-9a-f]+) \+ 8;', t)
    a = None
    if m and re.search(r'\*\w+ = %s \+ 8;' % m.group(1), t): a = int(m.group(2), 16)
    elif mm: a = int(mm.group(2), 16)
    if a is None:
        # `v = PTR_DAT_x + 8; ... *this = v;`  or  `*this = &PTR_FUN_y;` (y = vtable + 8)
        m3 = re.search(r'(\w+) = PTR_DAT_([0-9a-f]+) \+ 8;', t)
        if m3 and re.search(r'\*\w+ = %s;' % m3.group(1), t): return vt.get(nl.get(int(m3.group(2), 16))), m3.group(1)
        m4 = re.search(r'\*\w+ = &PTR_FUN_([0-9a-f]+);', t)
        if m4: return vt.get(int(m4.group(1), 16) - 8), None
        return None, None
    return vt.get(nl.get(a)), (m.group(1) if m else None)
for fn in order:
    addr, body = funcs[fn]
    c, vtvar = ctor_class(body)
    if c: cls[fn] = c
for fn in order:
    addr, body = funcs[fn]; t = '\n'.join(body)
    c = cls.get(fn)
    if c:
        if fn.startswith('FUN_'): rows.append('F|%s|%s__ctor_%s|constructor: stores the %s vtable (PTR_DAT -> nl_symbol_ptr -> vtable) at *this|INFERRED' % (fn, c, addr, c))
        m = re.search(r'(\w+) = PTR_DAT_[0-9a-f]+(?: \+ 8)?;', t)
        if m and re.match(r'(puVar|pcVar|uVar)\d+$', m.group(1)): rows.append('L|%s|%s|vtable|PTR_DAT_ entry holding the %s vtable address' % (fn, m.group(1), c))
        # roles from the base constructor call
        mc = re.search(r'(?:\(\(int \(\*\)\(\)\))?(\w+)\)?\((\w+),([^,)]+),(\w+)\);', t)
        if mc and ('ctor' in mc.group(1) or mc.group(1).startswith(('FUN_', 'IRInst__reinit', 'IRPseudo', 'IRAlu', 'IRFetch', 'IRUnary', 'IRExport'))):
            a1, a2, a3 = mc.group(2), mc.group(3), mc.group(4)
            for a, role in ((a1, 'this'), (a2, 'opcode'), (a3, 'compiler')):
                if re.match(r'param_\d+$', a): rows.append('L|%s|%s|%s|argument %s of the base constructor call' % (fn, a, role, role))
        continue
    # allocator: arena alloc 0x168 + constructor call
    if re.search(r'Arena__alloc\(\w+,0x168\)', t):
        mc = re.search(r'\(\(int \(\*\)\(\)\)(\w+)\)\(allocation \+ 1,([^)]*)\)|\b(\w+)\(allocation \+ 1,([^)]*)\)', t)
        if mc:
            callee = mc.group(1) or mc.group(3); args = (mc.group(2) or mc.group(4)).split(',')
            k = cls.get(callee)
            if k is None:
                mk = re.match(r'(\w+?)__(?:ctor|new|reinit)', callee)
                k = mk.group(1) if mk else None
            if k and fn.startswith('FUN_'):
                rows.append('F|%s|%s__new_%s|allocates 0x168 bytes from arena A and runs %s|INFERRED' % (fn, k, addr, callee))
            if args and re.match(r'param_\d+$', args[0].strip()): rows.append('L|%s|%s|opcode|first constructor argument after the object|INFERRED' % (fn, args[0].strip()))
open(out, 'w').write('\n'.join(rows) + '\n'); print(len(rows), 'rows')
