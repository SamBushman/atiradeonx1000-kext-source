#!/usr/bin/env python3
"""switch_ranges.py STOCK_DIS RANGES_TSV UNOWNED_BLOCKS_TSV SLICE  - widen the RANGES rows of every function that owns `switch-code` blocks (case code
reached only through an embedded jump table: Ghidra's decompiler recovers the table and transcribes the cases, but the listing's function body -
which RANGES records - stops at the `bctr`). For each owner, every `bctr` inside its current ranges that is followed by a `.long` table is treated
as a branch to each table target (base = the table address), and the code reachable from the entry is added (flow_ranges.py's walk; targets
outside [entry, next function) are ignored). Prints the widened rows (entry TAB ranges) and, on stderr, the instructions of switch-code blocks still not covered (table words excluded): DEAD-CASE = reachable only through an entry a
constant-index table (`lwz r0,K(base)`) never uses, NOT COVERED = anything else."""
import sys, re, bisect
dis, rng_f, ub_f, slice_f = sys.argv[1:5]
import struct
_d = open(slice_f, 'rb').read(); _secs = []
_nc = struct.unpack('>I', _d[16:20])[0]; _p = 28
for _ in range(_nc):
    _c, _cs = struct.unpack('>II', _d[_p:_p + 8])
    if _c == 1:
        _ns = struct.unpack('>I', _d[_p + 48:_p + 52])[0]; _q = _p + 56
        for _ in range(_ns):
            _a, _sz, _off = struct.unpack('>3I', _d[_q + 32:_q + 44]); _secs.append((_a, _sz, _off)); _q += 68
    _p += _cs
def word(a):
    for sa, sz, off in _secs:
        if sa <= a < sa + sz and off: return struct.unpack('>I', _d[off + a - sa:off + a - sa + 4])[0]
    return None
def is_call(op):
    return op in ('bl', 'bl+', 'bl-', 'bla', 'bctrl', 'blrl')
ins = {}
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l.rstrip())
    if m: ins[int(m.group(1), 16)] = (m.group(2), m.group(3))
rows = {}
for l in open(rng_f):
    p = l.rstrip('\n').split('\t')
    if len(p) < 4 or not p[0].startswith('0x'): continue
    rows[int(p[0], 16)] = [tuple(int(x, 16) for x in r.split('-')) for r in p[3].strip(';').split(';') if r]
entries = sorted(rows)
ENTRIES = set(entries)
def next_entry(a):
    i = bisect.bisect_right(entries, a); return entries[i] if i < len(entries) else 1 << 32
owners = {}
TABLEW = set()
for l in open(ub_f):
    p = l.rstrip('\n').split('\t')
    if len(p) > 3 and p[2] == 'switch-code':
        owners.setdefault(p[3], []).append((int(p[0], 16), int(p[1], 16)))
name2ent = {}
for l in open(rng_f):
    p = l.split('\t')
    if len(p) > 2 and p[0].startswith('0x') and (p[2] == 'fn' or p[1] not in name2ent): name2ent[p[1]] = int(p[0], 16)   # a PIC-stub thunk shares the name
def tables_in(iv, lo, hi, all_entries=False):
    out = {}
    for a0, a1 in iv:
        for a in range(a0, a1, 4):
            if ins.get(a, ('',))[0] == 'bctr' and '.long' in (ins.get(a + 4, ('',))[0], ins.get(a + 8, ('',))[0]):   # a negative first entry shows as an FP op
                base = a + 4; t = []; k = 0
                # a constant-index table (`lwz r0,K(rBase); add r0,r0,rBase; mtctr r0; bctr`): only entry K/4 is reachable, the other cases are dead
                const = None; add_ = None
                for b in range(a - 4, a - 96, -4):
                    op_, arg_ = ins.get(b, ('', ''))
                    if op_ == 'add' and add_ is None:
                        ra = arg_.split(','); add_ = (ra[0], ra[2] if ra[1] == ra[0] else ra[1]); continue
                    if add_ and op_ == 'lwzx' and arg_.startswith(add_[0] + ','): break
                    mc = re.match(r'(r\d+),(0x[0-9a-f]+|\d+)\((r\d+)\)$', arg_)
                    if add_ and op_ == 'lwz' and mc and mc.group(1) == add_[0] and mc.group(3) == add_[1]: const = int(mc.group(2), 0) // 4; break
                if const is not None and not all_entries and word(base + 4 * const) is not None:
                    out[a] = [(base + word(base + 4 * const)) & 0xffffffff]; continue
                mx = None
                for b in range(a - 4, a - 128, -4):
                    op_, arg_ = ins.get(b, ('', ''))
                    mg = re.match(r'cr\d,r\d+,(0x[0-9a-f]+|\d+)$', arg_)
                    if op_ == 'cmplwi' and mg: mx = int(mg.group(1), 0); break
                n = mx + 1 if mx is not None and mx < 1024 else None
                while (k < n) if n is not None else ins.get(base + 4 * k, ('',))[0] == '.long':
                    w = word(base + 4 * k)
                    if w is None: break
                    tgt = (base + w) & 0xffffffff
                    if lo <= tgt < hi and tgt % 4 == 0: t.append(tgt)
                    k += 1
                out[a] = t; TABLEW.update(range(base, base + 4 * k, 4))
    return out
def walk(ent, patch, hi):
    seen, todo = set(), [ent] + [t for ts in patch.values() for t in ts]   # tables already inside the ranges: their targets too
    while todo:
        a = todo.pop()
        while a in ins and a not in seen and ent <= a < hi:
            if a != ent and a in ENTRIES: break          # a tail branch into another function, not this body
            seen.add(a); op, arg = ins[a]
            if op == '.long' or a in TABLEW: break
            if a in patch: todo.extend(patch[a]); break
            tgt = re.search(r'0x([0-9a-f]+)\s*$', arg)
            if op in ('blr', 'bctr'): break
            if op in ('b', 'b+', 'b-'):
                if tgt: todo.append(int(tgt.group(1), 16))
                break
            if op.startswith('b') and not is_call(op) and tgt:
                todo.append(int(tgt.group(1), 16))
            a += 4
    return seen
def merge(iv):
    iv = sorted(iv); out = [list(iv[0])]
    for a, b in iv[1:]:
        if a <= out[-1][1]: out[-1][1] = max(out[-1][1], b)
        else: out.append([a, b])
    return out
# every guarded embedded table of the binary: its words are data even where otool shows a negative offset as an FP instruction
for a_, (op_, _) in list(ins.items()):
    if op_ == 'bctr':
        tables_in([(a_, a_ + 4)], 0, 1 << 32)
for owner, blocks in sorted(owners.items()):
    ent = name2ent.get(owner)
    if ent is None: print('no RANGES row for', owner, file=sys.stderr); continue
    hi = next_entry(ent); iv = list(rows[ent])
    for _ in range(4):   # cases can hold further tables
        patch = tables_in(iv, ent, hi)
        seen = walk(ent, patch, hi)
        for a0, a1 in iv: seen |= set(range(a0, a1, 4))
        s = sorted(seen); new = []; lo = prev = s[0]
        for x in s[1:]:
            if x != prev + 4: new.append((lo, prev + 4)); lo = x
            prev = x
        new.append((lo, prev + 4)); new = [tuple(r) for r in merge(new)]
        if new == iv: break
        iv = new
    rows[ent] = iv
    print('0x%x\t%s\t%s' % (ent, owner, ''.join('%x-%x;' % r for r in iv)))
    every = walk(ent, tables_in(iv, ent, hi, True), hi)   # every table entry followed: what a constant-index table could reach but never does
    for b0, b1 in blocks:
        left = [a for a in range(b0, b1, 4) if ins.get(a, ('.long',))[0] != '.long' and a not in TABLEW and not any(a0 <= a < a1 for a0, a1 in iv)]
        dead = [a for a in left if a in every]; left = [a for a in left if a not in every]
        if dead:
            print('DEAD-CASE %s %x-%x: %d instructions behind unused entries of a constant-index table' % (owner, b0, b1, len(dead)), file=sys.stderr)
        if left:
            print('NOT COVERED %s %x-%x: %d instructions, first %s' % (owner, b0, b1, len(left), ' '.join('%x:%s' % (a, ins[a][0]) for a in left[:40])), file=sys.stderr)
