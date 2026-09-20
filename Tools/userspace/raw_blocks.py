#!/usr/bin/env python3
"""raw_blocks.py STOCK_DIS RANGES.tsv EXTRA_EXTENTS.tsv... OUTPREFIX - split every run of stock text that no function owns into sub-runs and classify them:
  data      .long words / nops (switch offset tables, alignment padding)        -> OUTPREFIX.data.tsv  (start end kind)
  millicode register save/restore entry code (<=48 instrs, only save/restore ops) -> OUTPREFIX.mill.tsv
  code      everything else (case bodies after a table, leaf entries)             -> OUTPREFIX.code.tsv (start end), segmented at each unconditional transfer"""
import sys, re, bisect
dis, rng = sys.argv[1], sys.argv[2]; extras = sys.argv[3:-1]; out = sys.argv[-1]
rows = []
for l in open(dis):
    m = re.match(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$', l)
    if m: rows.append((int(m.group(1), 16), m.group(2), m.group(3)))
rows.sort()
own = []
for l in open(rng):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3 and f[2] == 'fn':
        for r in f[3].split(';'):
            if r: a, b = r.split('-'); own.append([int(a, 16), int(b, 16)])
for e in extras:
    for l in open(e):
        a, b = l.split('\t')[:2]; own.append([int(a, 16), int(b, 16)])
own.sort(); mg = []
for a, b in own:
    if mg and a <= mg[-1][1]: mg[-1][1] = max(mg[-1][1], b)
    else: mg.append([a, b])
mi = [m[0] for m in mg]
unc = []
for a, op, rest in rows:
    k = bisect.bisect_right(mi, a) - 1
    if k >= 0 and mg[k][0] <= a < mg[k][1]: continue
    unc.append((a, op, rest))
def isdata(op, rest): return op in ('.long', 'nop', 'attn')   # `attn` = an offset word that happens to decode as opcode 0
runs = []; cur = []
for x in unc:
    if cur and (x[0] - cur[-1][0] > 4 or isdata(x[1], x[2]) != isdata(cur[-1][1], cur[-1][2])): runs.append(cur); cur = []
    cur.append(x)
if cur: runs.append(cur)
SAVE = ('stfd', 'lfd', 'stw', 'lwz', 'stmw', 'lmw', 'blr', 'b', 'mfcr', 'mtcrf', 'mtocrf', 'mfspr', 'mtspr', 'addi', 'stfs', 'lfs', 'or', 'li', 'nop')
dat = open(out + '.data.tsv', 'w'); mil = open(out + '.mill.tsv', 'w'); cod = open(out + '.code.tsv', 'w'); cnt = {'data': 0, 'mill': 0, 'code': 0}
NR = ('Unwind_Resume', '_abort', '__cxa_throw', '__cxa_rethrow', '__throw')
def emit(s, e, ins):
    ops = [ins[a][1] for a in range(s, e, 4)]; calls = any(o in ('bl', 'bctrl') for o in ops)
    savey = sum(o in ('stfd', 'lfd', 'stfs', 'lfs', 'stw', 'lwz', 'stmw', 'lmw') for o in ops) >= len(ops) / 2
    if not calls and (len(ops) < 6 or (savey and len(ops) <= 48)):
        mil.write('%x\t%x\n' % (s, e)); cnt['mill'] += 1
    else:
        cod.write('%x\t%x\n' % (s, e)); cnt['code'] += 1
for r in runs:
    s = r[0][0]; e = r[-1][0] + 4
    if isdata(r[0][1], r[0][2]):
        kind = 'padding' if all(o == 'nop' or x.strip() in ('0x00000000', '') and o != 'attn' for _, o, x in r) else 'table'
        dat.write('%x\t%x\t%s\n' % (s, e, kind)); cnt['data'] += 1
    else:
        a = s; start = s; far = s; ins = {x[0]: x for x in r}
        while a < e:
            op, rest = ins[a][1], ins[a][2]; m = re.match(r'0x([0-9a-f]+)', rest)
            if op.startswith('b') and op not in ('b', 'bl', 'blr', 'bctr', 'bctrl', 'blrl') and m: far = max(far, int(m.group(1), 16))
            term = op in ('b', 'blr', 'bctr') or (op == 'bl' and any(x in rest for x in NR))
            a += 4
            if term and a > far:
                emit(start, a, ins); start = a; far = a
        if start < e: emit(start, e, ins)
print(cnt)
