#!/usr/bin/env python3
"""indirect_args.py STOCK_DIS DUMP_DIR > b3/indirect_args_X.txt  - the argument registers each indirect call (`bctrl`) in the stock code is given
(issue #70). An indirect call has no signature: Ghidra prints the arguments it can prove, and OverrideIndirectCalls.java only widened calls printed
with none. A call printed with some kept only those: glprog `TIntermediate::changeAggrToTempConst` printed its first virtual `getType` as
`(**(code **)(*param_2 + 0x38))(local_60)` - the stock passes the object in r4 (the caller's own untouched r4, its param_2), so the rebuilt call
built the type of a garbage object, the constant's array was allocated too small and the next pool allocation overwrote it (every folded vector
constant came out wrong: Tests/userspace/glsl_intfold2.vert).
For each bctrl: the highest argument register r4..r10 that is written in the call's basic block (the caller sets it up; the call target in r12 and
the CTR move do not count), or that still holds the caller's incoming parameter (no call, no write, no branch target between the entry and the
call, and the register is one of the caller's declared parameters). Prints `<callAddr>:<argCount>` for each call, `# function` comments. An
over-count is harmless (an extra argument the callee does not read); ExtendIndirectCalls.java widens only overrides that pass fewer."""
import sys, re, os
dis, dump = sys.argv[1:3]
ins = {}; order = []
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l.rstrip())
    if m: a = int(m.group(1), 16); ins[a] = (m.group(2), m.group(3)); order.append(a)
idx = {a: i for i, a in enumerate(order)}
BT = set()
for a, (op, arg) in ins.items():
    m = re.match(r'(?:cr\d,)?0x([0-9a-f]+)', arg)
    if op.startswith('b') and op != 'bcl' and m: BT.add(int(m.group(1), 16))   # not the PIC base's `bcl 20,31,next`
rows = {}
for l in open(os.path.join(dump, 'RANGES.tsv')):
    p = l.rstrip('\n').split('\t')
    if len(p) > 3 and p[0].startswith('0x') and p[2] == 'fn':
        rows[int(p[0], 16)] = (p[1], [tuple(int(x, 16) for x in r.split('-')) for r in p[3].strip(';').split(';') if r])
def nparams(ent):
    f = os.path.join(dump, '0x%x.txt' % ent)
    if not os.path.exists(f): return 0
    m = re.search(r'// Signature: [^(]*\((.*)\)', open(f).read(3000))
    if not m or m.group(1).strip() in ('', 'void'): return 0
    ps = [x for x in m.group(1).split(',') if x.strip()]
    n = 0
    for x in ps:   # GPR words only (a double parameter shadows two GPRs, a float one: Darwin)
        n += 2 if re.search(r'\bdouble\b(?!\s*\*)', x) else 0 if re.search(r'\bfparam', x) else 1
    return n
def written(op, arg):
    p = [x.strip() for x in arg.split(';')[0].split(',')]
    if not p or not re.match(r'r\d+$', p[0]) or op.startswith(('st', 'cmp', 'b', 'tw', 'mt', 'dcb', 'icb')): return None
    return int(p[0][1:])
total = 0
for ent, (name, rng) in sorted(rows.items()):
    np_ = nparams(ent)
    lines = []
    for lo, hi in rng:
        for a in range(lo, hi, 4):
            if ins.get(a, ('',))[0] != 'bctrl': continue
            need = 1
            # the basic block before the call
            # (walking backwards: `reads_after` = the registers read by the instructions between a write and the call; a register whose value
            # only serves as the base of the load of the call target - `lwz r9,0(r3); lwz r0,0xf0(r9); mtctr r0` - is not an argument)
            i = idx[a] - 1; later = []
            while i >= 0:
                b = order[i]; op, arg = ins[b]
                if op.startswith('b'): break
                r = written(op, arg)
                if r is not None and 4 <= r <= 10:
                    uses = [(o, g) for o, g in later if re.search(r'\br%d\b' % r, g.split(',', 1)[1] if ',' in g else '')]
                    target_only = uses and all(o.startswith('l') and written(o, g) in (0, 2, 11, 12) and re.search(r'\(r%d\)' % r, g) for o, g in uses)
                    if not target_only: need = max(need, r - 2)
                if r is not None: later = [(o, g) for o, g in later]   # (reads before a later redefinition still count: conservative)
                later.append((op, arg))
                if b in BT or b == ent: break
                i -= 1
            # untouched incoming parameters: a straight path from the entry (in address order) with no call, no branch target and no write
            if lo <= ent < hi and ent < a:
                clob = set(); ok = True
                for b in range(ent, a, 4):
                    if b not in ins: ok = False; break
                    op, arg = ins[b]
                    if op in ('bl', 'bctrl', 'bctr') or (b in BT and b != ent) or (op.startswith('b') and op not in ('bcl',)): ok = False; break
                    r = written(op, arg)
                    if r is not None: clob.add(r)
                if ok:
                    for r in range(4, 3 + np_ if np_ <= 8 else 11):
                        if r not in clob: need = max(need, r - 2)
            lines.append('0x%x:%d' % (a, need)); total += 1
    if lines: print('# %s @ 0x%x' % (name, ent)); print('\n'.join(lines))
print('# %d indirect calls' % total, file=sys.stderr)
