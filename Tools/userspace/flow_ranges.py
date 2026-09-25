#!/usr/bin/env python3
"""flow_ranges.py DIS LEDGER entry:bctr=target... - the code a function reaches from its entry (conditional and unconditional branches followed,
calls not, `bctr` at the given addresses treated as `b target`), stopping at blr / a tail branch to another ledger function's entry. Prints RANGES rows."""
import sys, re
dis, ledger = sys.argv[1], sys.argv[2]
ins = {}
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l.rstrip())
    if m: ins[int(m.group(1), 16)] = (m.group(2), m.group(3))
entries = {int(l.split('\t')[0], 16) for l in open(ledger)}
for spec in sys.argv[3:]:
    ent, *pat = spec.split(',')
    ent = int(ent, 16); patch = {int(a, 16): int(b, 16) for a, b in (p.split('=') for p in pat)}
    seen, todo = set(), [ent]
    while todo:
        a = todo.pop()
        while a in ins and a not in seen:
            if a != ent and a in entries: break          # ran into another function: a tail/fall-through edge, not this body
            seen.add(a); op, arg = ins[a]
            if a in patch: todo.append(patch[a]); break
            tgt = re.search(r'0x([0-9a-f]+)\s*$', arg)
            if op in ('blr', 'bctr') or op.startswith('blr'):
                if op in ('blr', 'bctr'): break
                a += 4; continue
            if op in ('b', 'b+', 'b-'):
                if tgt: todo.append(int(tgt.group(1), 16))
                break
            if (op.startswith('b') and not op.startswith(('bl', 'bctrl')) and tgt):
                todo.append(int(tgt.group(1), 16))
            a += 4
    s = sorted(seen); rg = []; lo = prev = s[0]
    for x in s[1:]:
        if x != prev + 4: rg.append((lo, prev + 4)); lo = x
        prev = x
    rg.append((lo, prev + 4))
    print('0x%x\t%s' % (ent, ''.join('%x-%x;' % r for r in rg)))
