#!/usr/bin/env python3
"""unowned_blocks.py STOCK_DIS RANGES.tsv LEDGER.tsv OUT.tsv - every run of stock instructions that no Ghidra function body claims, classified and
attributed to the function whose own span contains it (or the nearest preceding function):
  padding      nops / zero words between functions
  table        .long words only (embedded switch offset tables)
  eh-pad       C++ exception landing pad (ends in _Unwind_Resume; reachable only through the unwinder, so no decompile can show it)
  millicode    register save/restore helper entry (mfcr / stfd/lfd runs)
  switch-code  case code following a switch table (in a decompile only if the switch was recovered)
  other        anything else
Columns: start, end, kind, owner function, instruction count, calls made (names)."""
import sys, re, bisect
dis, rng, led, out = sys.argv[1:5]
extra = sys.argv[5] if len(sys.argv) > 5 else None   # pad_extents.tsv: landing pads transcribed as companion functions
rows = []
for l in open(dis):
    m = re.match(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$', l)
    if m: rows.append((int(m.group(1), 16), m.group(2), m.group(3)))
rows.sort()
own = []; names = {}
for l in open(rng):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3 and f[2] == 'fn':
        names[f[0]] = f[1]
        for r in f[3].split(';'):
            if r: a, b = r.split('-'); own.append((int(a, 16), int(b, 16), f[1]))
if extra:
    for l in open(extra):
        a_, b_ = l.split('\t')[:2]; own.append((int(a_, 16), int(b_, 16), 'extra'))
own.sort(); merged = []
for a, b, n in own:
    if merged and a <= merged[-1][1]: merged[-1][1] = max(merged[-1][1], b)
    else: merged.append([a, b])
mi = [m[0] for m in merged]
spans = []; fn_ranges = {}
for a, b, n in own: fn_ranges.setdefault(n, []).append((a, b))
for n, rs in fn_ranges.items(): spans.append((min(a for a, b in rs), max(b for a, b in rs), n))
spans.sort(); sstarts = [s[0] for s in spans]
def owner(a):
    best = None
    for k in range(bisect.bisect_right(sstarts, a) - 1, max(-1, bisect.bisect_right(sstarts, a) - 40), -1):
        lo, hi, n = spans[k]
        if lo <= a < hi: return n          # inside a function's own span
        if best is None: best = n
    return best or '?'
unc = []
for a, op, rest in rows:
    k = bisect.bisect_right(mi, a) - 1
    if k >= 0 and merged[k][0] <= a < merged[k][1]: continue
    unc.append((a, op, rest))
blocks = []; cur = []
for x in unc:
    if cur and x[0] - cur[-1][0] > 4: blocks.append(cur); cur = []
    cur.append(x)
if cur: blocks.append(cur)
cnt = {}
with open(out, 'w') as f:
    f.write('start\tend\tkind\towner\tinstructions\tcalls\n')
    for b in blocks:
        ops = [o for _, o, _ in b]; txt = ' '.join(r for _, _, r in b)
        calls = ','.join(sorted({re.sub(r'^.*for:\s*', '', r) if 'symbol stub for:' in r else r.split()[0] for _, o, r in b if o == 'bl'}))
        if all(o == 'nop' or (o == '.long' and r.strip() == '0x00000000') for _, o, r in b): k = 'padding'
        elif all(o == '.long' for o in ops): k = 'table'
        elif 'Unwind_Resume' in txt: k = 'eh-pad'
        elif len(b) <= 40 and all(o in ('stfd', 'lfd', 'stw', 'lwz', 'stmw', 'lmw', 'blr', 'b', 'mfcr', 'mtcrf', 'mtocrf', 'mfspr', 'mtspr', 'nop') for o in ops): k = 'millicode'
        elif '.long' in ops[:8]: k = 'switch-code'
        else: k = 'other'
        cnt[k] = cnt.get(k, 0) + 1
        f.write('%x\t%x\t%s\t%s\t%d\t%s\n' % (b[0][0], b[-1][0] + 4, k, owner(b[0][0]), len(b), calls))
print(cnt)
