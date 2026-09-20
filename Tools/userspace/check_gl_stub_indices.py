#!/usr/bin/env python3
"""check_gl_stub_indices.py STOCK_DIS PART_DIR... - for every libGL dispatch stub, compare the context-table index the corpus/link build uses (`puVar2[N]` in the
call) with the displacement the stock machine code loads into the branch register (`lwz rX,DISP(...)` ... `mtspr ctr,rX`; N == DISP/4).
STOCK_DIS is `otool -arch ppc -tV libGL.dylib`."""
import re, sys, glob
dis = open(sys.argv[1]).read().split('\n')
funcs = {}
cur = None
for ln in dis:
    m = re.match(r'^(\w[^\s:]*):$', ln)
    if m:
        cur = m.group(1)
        funcs[cur] = []
    elif cur:
        funcs[cur].append(ln)
stock = {}
for name, lines in funcs.items():
    if not name.startswith('_gl'):
        continue
    for i, ln in enumerate(lines):
        m = re.search(r'mtspr\tctr,(r\d+)', ln)
        if m:
            reg = m.group(1)
            for j in range(i - 1, -1, -1):
                m2 = re.search(r'lwz\t%s,(0x[0-9a-f]+)\((r\d+)\)' % reg, lines[j])
                if m2:
                    stock[name] = int(m2.group(1), 16) // 4
                    break
            break
ours = {}
for d in sys.argv[2:]:
    for f in sorted(glob.glob(d + '/part_*.c')):
        t = open(f).read()
        for m in re.finditer(r'index (0x[0-9a-f]+|\d+) = ctx offset[^\n]*\n(?:[^\n]*\n){0,12}?', t):
            pass
        for m in re.finditer(r'^\w[\w \*]* (gl\w+)\([^\n]*\)\n\{\n  /\* dispatch stub, template derived from the stock machine code \(index (0x[0-9a-f]+|\d+) =', t, re.M):
            ours['_' + m.group(1)] = int(m.group(2), 0)
bad = [(n, ours[n], stock.get(n)) for n in ours if stock.get(n) != ours[n]]
missing = [n for n in stock if n not in ours]
print('%d stubs in the link build, %d in the stock with a table call: %d index mismatches, %d stock stubs not templated' % (len(ours), len(stock), len(bad), len(missing)))
for b in bad[:20]:
    print('  MISMATCH', b)
for n in missing[:10]:
    print('  not templated:', n)
sys.exit(1 if bad else 0)
