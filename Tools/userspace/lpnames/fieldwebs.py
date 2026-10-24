#!/usr/bin/env python3
"""fieldwebs.py DIR FN VAR BASE ADJ FIELDS.tsv [SPECOUT]

Name the def-use webs of VAR (Ghidra's original name) in FN after the structure field they load, for temporaries of the form
    VAR = *(T *)(BASE + OFF);      or      VAR = *(T *)(0x0000OFF + BASE);
where BASE is a parameter/local holding a pointer to (ctx + ADJ): the field is looked up at OFF+ADJ in FIELDS.tsv (fields_gld.tsv style
lines `field<TAB>STRUCT<TAB>0xOFFSET<TAB>name<TAB>tier<TAB>evidence`).  A web is named only when EVERY definition of it loads the same
offset; webs with other definitions are listed and left to the caller.  Names are camelCase of the field name; an offset with no field row
is named  w<hex of OFF+ADJ>  (the absolute offset).  Names are made unique across the variables of FN by a numeric suffix on collision with
a DIFFERENT variable (the same name on several webs of one variable is fine: it stays one variable).
With SPECOUT, appends `VAR<TAB>webs<TAB>NAME<TAB>INFERRED<TAB>EVIDENCE` lines for emit_webs.py.
"""
import sys, os, re
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F

d, fn, var, base, adj, fields = sys.argv[1:7]
out = sys.argv[7] if len(sys.argv) > 7 else None
REGJSON = os.environ.get('REGMAP')   # json {"0xADDR": ["NAME", ...]} from the R3xx/R5xx register PDFs
import json
regmap = {int(k, 16): v for k, v in json.load(open(REGJSON)).items()} if REGJSON else {}
adj = int(adj, 0)
names = {}
for l in open(fields):
    c = l.rstrip('\n').split('\t')
    if len(c) >= 4 and c[0] == 'field':
        names[int(c[2], 0)] = (c[3], c[4] if len(c) > 4 else '')


def camel(s):
    if s.isupper() or s.islower() or '_' in s: s = s.lower()
    p = re.split(r'[_\W]+', s)
    return p[0][:1].lower() + p[0][1:] + ''.join(x[:1].upper() + x[1:] for x in p[1:])


body, brace = F.load(d, fn)
nodes, entry = F.build_cfg(body, brace)
CONST = re.compile(r'^\s*(\w+)\[(0x[0-9a-f]+|\d+)\] = (?:\(\(unsigned char \*\)(0x[0-9a-f]+)U?\)|(0x[0-9a-f]+|\d+));')
CONST0 = re.compile(r'^\s*\*(\w+) = (?:\(\(unsigned char \*\)(0x[0-9a-f]+)U?\)|(0x[0-9a-f]+|\d+));')
consts = {}   # (ptrvar) -> list of (line, idx, value)
for x, t in enumerate(body):
    m = CONST.match(t)
    if m: consts.setdefault(m.group(1), []).append((x, int(m.group(2), 0), int(m.group(3) or m.group(4), 0)))
    m = CONST0.match(t)
    if m: consts.setdefault(m.group(1), []).append((x, 0, int(m.group(2) or m.group(3), 0)))
USEP = re.compile(r'^\s*(\w+)\[(0x[0-9a-f]+|\d+)\] = %s;' % re.escape(var))


import bisect
segs = {}
for x, t in enumerate(body):
    m = re.match(r'^\s*(\w+) = ', t)
    if m: segs.setdefault(m.group(1), []).append(x)


def seg(pv, x):
    return bisect.bisect_right(segs.get(pv, []), x)


def reg_for_use(x):
    m = USEP.match(body[x])
    if not m: return None
    pv, i = m.group(1), int(m.group(2), 0)
    best = None
    for (lx, j, v) in consts.get(pv, []):
        if j >= i or seg(pv, lx) != seg(pv, x): continue
        n = (v >> 16) + 1 if v >> 16 else 1
        if i <= j + n and 0x800 <= (v & 0xffff) < 0x4000:
            k = i - j - 1
            key = (-j, abs(lx - x))      # nearest preceding index first; among re-uses of the same index, nearest in the text
            if best is None or key < best[0]: best = (key, (v & 0xffff) * 4 + 4 * k)
    return best[1] if best else None

ws, er = F.webs(nodes, entry, var)
B = re.escape(base)
DEF = re.compile(r'(?<![\w.>])%s\s*=(?!=)\s*(.*)' % re.escape(var))
LD = [re.compile(r'\*\([^)]*\*\)\(%s \+ (0x[0-9a-f]+|\d+)\)' % B),
      re.compile(r'\*\([^)]*\*\)\((0x[0-9a-f]+|\d+) \+ %s\)' % B)]
OPEN = re.compile(r'\b%s\b' % re.escape(var))
by = {}; bad = []; evid = {}; used = {}
EXTRA = {0x1930: ('registerDirty', 'register-dirty word: every gldValidate* ORs a bit into it (notes_gld_functions.md section 3)'),
         0x4: ('glState', '*(glContext + 4): the GL state object; (glState)->+0x10 is the GL state block read by the gldValidate* translators'),
         0x38: ('dirtyWord0', 'first dirty word tested by gldValidateState (notes_gld_functions.md section 3)'),
         0x3c: ('dirtyWord1', 'second dirty word tested by gldValidateState (notes_gld_functions.md section 3)')}
for k, ls in enumerate(ws):
    if not any(OPEN.search(F.CURRENT[x]) for x in ls): continue
    offs = set(); ok = True; n = 0; regs = set()
    for x in ls:
        for m in DEF.finditer(body[x]):
            n += 1
            t = m.group(1)
            hit = None
            for rx in LD:
                mm = rx.fullmatch(t.rstrip(';').strip()) or (rx.match(t) if t.count('*(') == 1 else None)
                if mm: hit = int(mm.group(1), 0); break
            if hit is None: ok = False
            else:
                offs.add(hit)
                for u in ls:
                    r = reg_for_use(u)
                    if r is not None: regs.add(r)
    if n and ok and len(offs) == 1:
        o = offs.pop() + adj
        if o in names and len(regs) == 1 and regmap.get(next(iter(regs))) and os.environ.get('AUDIT'): print('AUDIT %s field=%s pair=%s %s' % ('OK ' if camel(regmap[next(iter(regs))][0]) == camel(names[o][0]) else 'BAD', names[o][0], regmap[next(iter(regs))][0], hex(o)))
        if o in names: nm = camel(names[o][0])
        elif len(regs) == 1 and regmap.get(next(iter(regs))): nm = camel(regmap[next(iter(regs))][0])
        elif (o - adj) in EXTRA: nm = EXTRA[o - adj][0]
        else: nm = '%sWord%x' % (os.environ.get('BASENAME', base), o - adj)
        if nm in used and used[nm] != o:     # same name for a different field: keep the first, qualify the later one with its offset
            nm = nm + '%x' % o
        used[nm] = o
        by.setdefault(nm, []).append(k)
        evid[nm] = ('field %s of the GLD context (ctx+0x%x)' % (names[o][0], o)) if o in names else (('register %s (0x%x) of the R3xx/R5xx register PDFs, paired with this value in the state packet; shadow at ctx+0x%x' % (regmap[next(iter(regs))][0], next(iter(regs)), o)) if (len(regs) == 1 and regmap.get(next(iter(regs)))) else (EXTRA[o - adj][1] if (o - adj) in EXTRA else 'load of %s+0x%x (no field row, no register pairing): positional name' % (os.environ.get('BASENAME', base), o - adj)))
        print('web %3d  %-24s off 0x%x%s regs %s' % (k, nm, o, '' if o in names else '  (no field row)', [hex(r) for r in regs]))
    else:
        bad.append(k)
        print('web %3d  UNHANDLED (%d defs)  %s' % (k, n, ' || '.join(body[x].strip()[:60] for x in ls[:2])))
if out:
    with open(out, 'a') as f:
        for nm, l in by.items():
            f.write('%s\t%s\t%s\tINFERRED\t%s\n' % (var, ','.join(map(str, l)), nm, evid[nm]))
print('unhandled webs:', bad)
