#!/usr/bin/env python3
"""posweb.py DIR OUT.tsv PARTLO PARTHI [--dry] [FN ...] : positional names for placeholder webs that only ever hold a value loaded from BASE+OFFSET.

For every function of DIR/part_LO..HI.c (or the listed FNs) and every placeholder variable (not parameters), take its def-use webs (find_webs.py).
A web is named when every definition is  VAR = *(T *)(BASE + OFF)  /  VAR = *(T *)(((unsigned char *)OFF) + BASE)  /  VAR = ((unsigned char *)OFF)[BASE]
/ VAR = BASE[IDX] (4-byte element types only)  with ONE (BASE, OFF) and BASE already a real (non-placeholder) name, or a self-update  VAR = VAR op ...
of such a load.  Name = <BASE><Kind><hex OFF>  (Kind = Ptr | Float | Byte | Short | Word; negative offsets Neg<hex>), the convention of glContextWord1e5c.
Run it repeatedly (apply_names.py between runs): names found in one pass become BASEs of the next.  Rows are `use` rows from emit_webs.py."""
import sys, re, os, collections, subprocess, tempfile, glob
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
dry = '--dry' in sys.argv
only = [a for a in sys.argv[5:] if not a.startswith('--')]
PHV = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_\w+|fparam_\d+|extraout_\w+|unaff_\w+|\w*Stack_[0-9a-f]+|iVarS\w*|FUN_[0-9a-f]+|DAT_\w+|PTR_\w+)$')
VAR = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+)$')
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
funcs = collections.OrderedDict()
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m and (not only or m.group(1) in only): funcs[m.group(1)] = int(m.group(2), 16)
def kind(t):
    t = t.strip(); t = t[:-1].strip() if t.endswith('*') else t   # the cast is a pointer TO the loaded type
    if '*' in t: return 'Ptr'
    if 'float' in t or 'double' in t: return 'Float'
    if re.search(r'byte|char|bool', t): return 'Byte'
    if 'short' in t: return 'Short'
    return 'Word'
def offs(o):
    o = o.strip()
    if o.startswith('-'): return 'Neg%x' % int(o[1:], 0)
    return '%x' % int(o, 0)
PATS = [
 re.compile(r'^\*\(([\w ]+\**) ?\*?\)\((\w+) \+ (-?(?:0x[0-9a-f]+|\d+))\)$'),
 re.compile(r'^\*\(([\w ]+\**) ?\*?\)\(\(\(unsigned char \*\)(0x[0-9a-f]+)\) \+ (?:\(int\))?(\w+)\)$'),
 re.compile(r'^\(([\w ]+\**)\)?\(\(unsigned char \*\)(0x[0-9a-f]+)\)\[(?:\(int\))?(\w+)\]$'),
 re.compile(r'^\(?(?:[\w ]+\**\)\s*)?\(\(unsigned char \*\)(0x[0-9a-f]+)\)\[(?:\(int\))?(\w+)\]$'),
]
def key(rhs, var, decl):
    r = rhs.strip().rstrip(';').strip()
    r = re.sub(r'^\((?:[\w ]+\*?)\)\s*', '', r) if not r.startswith('*(') else r
    m = PATS[0].match(r)
    if m: return m.group(2), offs(m.group(3)), kind(m.group(1))
    m = PATS[1].match(r)
    if m: return m.group(3), offs(m.group(2)), kind(m.group(1))
    m = PATS[3].match(r)
    if m: return m.group(2), offs(m.group(1)), 'Byte'
    m = re.match(r'^(\w+)\[(0x[0-9a-f]+|\d+)\]$', r)
    if m and m.group(1) in decl and decl[m.group(1)] == 4:
        return m.group(1), offs(str(int(m.group(2), 0) * 4)), 'Word'
    return None
POSN = re.compile(r'(?:Word|Ptr|Float|Byte|Short)(?:Neg)?[0-9a-f]+(?:_\d+)?$')   # names made by this tool are never bases (no chains)
rows = []; stat = collections.Counter()
for fn, addr in funcs.items():
    try:
        body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException:
        stat['noload'] += 1; continue
    cur = F.CURRENT
    text = '\n'.join(cur)
    idents = set(re.findall(r'[A-Za-z_]\w*', text))
    # element sizes of pointer parameters/locals
    decl = {}
    for l in cur[:brace + 40]:
        for m in re.finditer(r'\b(u?int|uint|undefined4|float|ulong|long)\s*\*+\s*(\w+)', l): decl[m.group(2)] = 4
    first = next((i for i in range(brace + 1, len(cur)) if cur[i].strip() and not re.match(r'^\s*[\w ]+[\s\*]+\w+(\[\d+\])?;$', cur[i])), brace + 1)
    names = sorted({m for i in range(brace + 1, len(cur)) for m in re.findall(r'\b([A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+)\b', cur[i]) if VAR.match(m)})
    spec = []; used = collections.Counter(); owner = {}
    for var in names:
        if any(re.search(r'&\s*%s\b' % re.escape(var), c) for c in cur): stat['addr'] += 1; continue
        if sum(1 for i in range(brace + 1, first) if re.match(r'^\s*[\w ]+[\s\*]+%s;$' % re.escape(var), cur[i])) != 1: stat['nodecl'] += 1; continue
        try: ws, er = F.webs(nodes, entry, var)
        except BaseException: stat['refused'] += 1; continue
        for k, ls in enumerate(ws):
            ks = set(); ok = True; nload = 0
            for x in ls:
                if x < first: continue
                l = cur[x]
                m = re.search(r'(?:^|[\(\s,])%s = ([^;]*);' % re.escape(var), l)
                if not m: continue
                rhs = m.group(1)
                if re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), rhs): continue   # self-update
                kk = key(rhs, var, decl)
                if kk is None or PHV.match(kk[0]) or POSN.search(kk[0]): ok = False; break
                ks.add(kk); nload += 1
            if not ok or len(ks) != 1 or not nload: continue
            b, o, kd = next(iter(ks))
            if any(re.search(r'\(%s \+ |\(int\)%s\)|\(unsigned char \*\)\w+\)?\[%s\]|\b%s\[' % ((re.escape(var),)*4), cur[x]) for x in ls): kd = 'Ptr'   # used as an address
            nm = '%s%s%s' % (b, kd, o)
            if owner.get(nm, var) != var or nm in idents - {var}:
                b0 = nm; used[b0] += 1; nm = '%s_%d' % (b0, used[b0] + 1)
                while nm in idents or owner.get(nm, var) != var: used[b0] += 1; nm = '%s_%d' % (b0, used[b0] + 1)
            owner[nm] = var
            spec.append('%s\t%d%s\t%s\tINFERRED\tevery definition of this web is a load from %s+0x%s (positional name; no field row)' % (var, k, '>%d' % first if k == 0 else '', nm, b, o.replace('Neg', '-')))
            stat['web'] += 1
    if spec and not dry:
        tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(spec) + '\n'); tf.close()
        r = subprocess.run([sys.executable, '-I', 'Tools/userspace/emit_webs.py', d, fn, tf.name], capture_output=True, text=True)
        os.unlink(tf.name)
        if r.returncode: print('emit failed', fn, r.stderr[-150:], file=sys.stderr); stat['emitfail'] += 1; continue
        rows.append(r.stdout.rstrip('\n').replace('\t%s\t' % fn, '\tFUN_%08x\t' % addr if fn.startswith('FUN_') else '\t%s\t' % fn))
if not dry: open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(dict(stat), file=sys.stderr)
