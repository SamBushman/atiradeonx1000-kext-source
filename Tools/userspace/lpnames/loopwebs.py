#!/usr/bin/env python3
"""loopwebs.py DIR OUT.tsv PARTLO PARTHI [--dry] [--show] : role names for induction webs.
A web (find_webs) of an integer placeholder whose definitions are only constants and self-increments `x = x + K` (K>0) -> loopIndex;
only constants and self-decrements `x = x - K` / `x + -K` -> remaining; a pointer web (declared with `*`) whose definitions are an
initial value and self-increments `p = p + K` / `p++` style -> cursor.  Webs that also have another kind of definition are left alone.
Names are unique per function (suffix 2, 3 ...)."""
import sys, re, os, collections, subprocess, tempfile, glob
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
dry = '--dry' in sys.argv
VAR = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+)$')
H = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
funcs = collections.OrderedDict()
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m: funcs[m.group(1)] = int(m.group(2), 16)
CONST = re.compile(r'^\(?(?:[\w ]+\*?\))?\s*(?:0x[0-9a-f]+|-?\d+)\)?$')
rows = []; stat = collections.Counter()
for fn, addr in funcs.items():
    try: body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException: stat['noload'] += 1; continue
    cur = F.CURRENT; idents = set(re.findall(r'[A-Za-z_]\w*', '\n'.join(cur))); used = collections.Counter()
    first = next((i for i in range(brace + 1, len(cur)) if cur[i].strip() and not re.match(r'^\s*[\w ]+[\s\*]+\w+ ?(\[\w+\])?;$', cur[i])), brace + 1)
    names = sorted({m for i in range(brace + 1, len(cur)) for m in re.findall(r'\b([A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+)\b', cur[i]) if VAR.match(m)})
    spec = []
    for var in names:
        dl = [i for i in range(brace + 1, first) if re.match(r'^\s*[\w ]+[\s\*]+%s;$' % re.escape(var), cur[i])]
        if len(dl) != 1 or any(re.search(r'(?<![&\w])&%s\b' % re.escape(var), c) for c in cur): continue   # address-taken variables cannot be split
        isptr = '*' in cur[dl[0]].split(var)[0]
        try: ws, er = F.webs(nodes, entry, var)
        except BaseException: continue
        for k, ls in enumerate(ws):
            kinds = set(); ok = True
            for x in ls:
                if x < first: continue
                l = cur[x]
                for m in re.finditer(r'(?:^|[\(\s,])%s = ([^;,]*?)(?:[;,]|\)\s*[;{)&|]|$)' % re.escape(var), l):
                    rhs = m.group(1).strip()
                    if re.fullmatch(r'\(?(?:[\w ]+\*?\))?\s*\(?%s\)? \+ (?:0x[0-9a-f]+|\d+)\)?' % re.escape(var), rhs) or re.fullmatch(r'\(?\(?[\w ]+\*+\)?\(?%s\)? \+ (?:0x[0-9a-f]+|\d+)\)?' % re.escape(var), rhs): kinds.add('inc')
                    elif re.fullmatch(r'\(?%s\)? (?:- (?:0x[0-9a-f]+|\d+)|\+ -(?:0x[0-9a-f]+|\d+))' % re.escape(var), rhs): kinds.add('dec')
                    elif CONST.match(rhs) and not isptr: kinds.add('const')
                    elif isptr and not re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), rhs) and '(' not in rhs: kinds.add('init')
                    else: ok = False
            if not ok: continue
            if isptr and kinds <= {'init', 'inc'} and 'inc' in kinds and 'init' in kinds: base = 'cursor'
            elif not isptr and kinds <= {'const', 'inc'} and 'inc' in kinds: base = 'loopIndex'
            elif not isptr and kinds <= {'const', 'dec'} and 'dec' in kinds: base = 'remaining'
            else: continue
            nm = base
            while nm in idents: used[base] += 1; nm = '%s%d' % (base, used[base] + 1)
            idents.add(nm)
            spec.append('%s\t%d%s\t%s\tINFERRED\tonly ever set to a start value and stepped (%s)' % (var, k, '>%d' % first if k == 0 else '', nm, base)); stat[base] += 1
    if spec and not dry:
        tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(spec) + '\n'); tf.close()
        r = subprocess.run([sys.executable, '-I', 'Tools/userspace/emit_webs.py', d, fn, tf.name], capture_output=True, text=True); os.unlink(tf.name)
        if r.returncode: stat['emitfail'] += 1; continue
        rows.append(r.stdout.rstrip('\n').replace('\t%s\t' % fn, '\tFUN_%08x\t' % addr if fn.startswith('FUN_') else '\t%s\t' % fn))
if not dry: open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(dict(stat), file=sys.stderr)
