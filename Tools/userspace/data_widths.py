#!/usr/bin/env python3
"""data_widths.py STOCK_DIS RANGES_TSV DUMP_DIR OUT_JSON      (issue #82)
For every load / store in the stock whose effective address is a resolvable PIC address (stackargs_indirect.py's pic_abs), record the access width:
{"0xADDR": {"1|2|4|8": count}}. data_types.py uses it to decide how wide a scalar `DAT_x` really is."""
import sys, re, collections, json
dis, rng, dump, out = sys.argv[1:5]
here = __file__.rsplit('/', 1)[0]
sys.argv = ['x', dis, rng, dump, '.', '0x12e4:4']
src = open(here + '/stackargs_indirect.py').read()
pre = src.split("report = []; edits = {}")[0]
ns = {'__file__': here + '/stackargs_indirect.py'}
exec(pre, ns)
ins, owner, pic_abs = ns['ins'], ns['owner'], ns['pic_abs']
W_OF = {'lbz': 1, 'lbzx': 1, 'stb': 1, 'stbx': 1, 'lhz': 2, 'lha': 2, 'lhzx': 2, 'sth': 2, 'sthx': 2, 'lwz': 4, 'stw': 4, 'lwzx': 4, 'stwx': 4, 'lfs': 4, 'stfs': 4, 'lfd': 8, 'stfd': 8}
acc = collections.defaultdict(collections.Counter)
for a, (op, arg) in ins.items():
    w = W_OF.get(op)
    if not w or a not in owner: continue
    m = re.match(r'r\d+,\s*(-?(?:0x)?[0-9a-f]+)\(r(\d+)\)', arg.split(';')[0].strip())
    if not m or int(m.group(2)) in (0, 1): continue
    disp = int(m.group(1), 16) if '0x' in m.group(1) else int(m.group(1))
    if disp >= 0x8000: disp -= 0x10000
    try: ab = pic_abs(owner[a], a, int(m.group(2)))
    except Exception: ab = None
    if ab is not None: acc[(ab + disp) & 0xffffffff][w] += 1
json.dump({hex(k): dict(v) for k, v in sorted(acc.items())}, open(out, 'w'), indent=0)
print(len(acc), 'addresses')
