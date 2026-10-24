#!/usr/bin/env python3
"""bulk_fieldcopy.py DIR PARTFROM PARTTO OUTROWS [--dry] : for every function of part_PARTFROM..PARTTO whose param_1 is the GLDContext
(>=3 distinct-use offsets >=0x100 through param_1, >=70% of them known fields in fields_gld.tsv), (a) name param_1 `ctx` (gl*_impl: `glContext`)
unless already named, and (b) name every placeholder variable web that is a plain load of a known ctx field after the field (fieldcopy.py).
Rows are appended to OUTROWS; prints one line per function."""
import sys, os, re, subprocess, tempfile
d, a, b, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
dry = '--dry' in sys.argv
S = os.path.dirname(os.path.abspath(__file__))
FLD = set()
for l in open(os.path.join(d, 'fields_gld.tsv')):
    c = l.split('\t')
    if len(c) > 5 and c[0] == 'field' and c[1] == 'GLD': FLD.add(int(c[2], 16))
H = re.compile(r'^/\* (\S+) @ 0x')
tot = 0
for p in range(a, b + 1):
    f = os.path.join(d, 'part_%03d.c' % p)
    funcs = {}; cur = None
    for l in open(f, errors='replace'):
        m = H.match(l)
        if m: cur = m.group(1); funcs[cur] = []; continue
        if cur: funcs[cur].append(l)
    for fn, ls in funcs.items():
        t = ''.join(ls)
        offs = [int(o, 16) for o in re.findall(r'\bparam_1 \+ (0x[0-9a-f]+)', t)]
        big = [o for o in offs if o >= 0x100]
        hit = [o for o in big if o in FLD]
        if not (len(big) >= 3 and len(hit) / len(big) >= 0.7): continue
        rows = []
        pname = 'glContext' if re.search(r'^gl[A-Z]\w*_impl$', fn) else 'ctx'
        if re.search(r'\bparam_1\b', t) and not re.search(r'\b%s\b' % pname, t):
            rows.append('local\t%s\tparam_1\t%s\tINFERRED\tGLDContext: %d of %d uses through it at offsets >= 0x100 are known GLDContext fields (fields_gld.tsv)' % (fn, pname, len(hit), len(big)))
        r = subprocess.run([sys.executable, '-I', os.path.join(S, 'fieldcopy.py'), d, fn], capture_output=True, text=True)
        spec = r.stdout
        n_f = 0
        if spec.strip():
            sf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); sf.write(spec); sf.close()
            r2 = subprocess.run([sys.executable, '-I', os.path.join(os.path.dirname(S), 'emit_webs.py'), d, fn, sf.name], capture_output=True, text=True)
            if r2.returncode == 0: rows.append(r2.stdout.rstrip('\n')); n_f = r2.stdout.count('\n')
        print('%-34s ctx-like (%d/%d) param_1:%s fieldcopy rows:%d%s' % (fn, len(hit), len(big), 'yes' if rows and rows[0].startswith('local') else 'no', n_f, ' ERR ' + r.stderr[-80:] if r.returncode else ''))
        tot += len(rows)
        if rows and not dry: open(out, 'a').write('\n'.join(rows) + '\n')
print('total row groups', tot)
