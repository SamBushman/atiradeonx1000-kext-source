#!/usr/bin/env python3
"""vecidiom.py DIR FN|ALL OUT.tsv [PARTLO PARTHI] [--show] : name the webs of the inline Vector idiom Ghidra expands everywhere.

The compiler's Vector template (header words: [0] capacity, [1] filled count, [2] data pointer) is inlined as
    if (idx < *V) { if (cnt <= idx) { _memset(...); V[1] = idx + 1; } E = (T)(idx * 4 + V[2]); } else E = (T)Vector__elementRefGrow(V, idx);
so a function that walks vectors carries 4 placeholders per walk:  V (the vector), cnt (`cnt = V[1]`), idx (`idx = 0 .. idx + 1`),
E (the element reference) and the element (`elem = (T)*E`).  Roles are decided per def-use web from the shape of the definitions only
(no semantics), and names are derived from the vector: `<base>VectorAt<hex>` for a vector loaded from a field of an object, or the name
the vector already has.  Output: emit_webs rows (use rows) appended to OUT.tsv.  --show prints the classification instead."""
import sys, os, re, glob, collections, tempfile, subprocess
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F

d, fnarg, out = sys.argv[1:4]
lo = int(sys.argv[4]) if len(sys.argv) > 4 and sys.argv[4].isdigit() else 0
hi = int(sys.argv[5]) if len(sys.argv) > 5 and sys.argv[5].isdigit() else 999
SHOW = '--show' in sys.argv
H = re.compile(r'^/\* (\S+) @ 0x')
PHRE = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_[a-z]+\d*)$')
IDENT = re.compile(r'[A-Za-z_]\w*')
CAST = r'(?:\([\w ]+\*{0,3}\))?'


def functions():
    r = []
    for pf in sorted(glob.glob(d + '/part_*.c')):
        pn = int(re.search(r'part_(\d+)', pf).group(1))
        if not lo <= pn <= hi: continue
        for l in open(pf, errors='replace'):
            m = H.match(l)
            if m: r.append(m.group(1))
    return r


def analyse(fn):
    body, brace = F.load(d, fn)
    cur = F.CURRENT
    nodes, entry = F.build_cfg(body, brace)
    n = len(body)
    # current name of every ghidra identifier occurrence: tokens line by line
    tok = {}
    for i in range(brace + 1, n):
        a = [m for m in IDENT.finditer(body[i])]; b = [m for m in IDENT.finditer(cur[i])]
        if len(a) == len(b):
            for x, y in zip(a, b): tok[(i, x.group(0))] = y.group(0)
    names = sorted({m for i in range(brace + 1, n) for m in IDENT.findall(body[i]) if PHRE.match(m)})
    webs = {}; web_of = {}
    for v in names:
        try: ws, er = F.webs(nodes, entry, v)
        except BaseException: continue
        webs[v] = ws
        for k, ls in enumerate(ws):
            for x in ls: web_of[(v, x)] = k
    return body, cur, brace, tok, webs, web_of


def run(fn):
    body, cur, brace, tok, webs, web_of = analyse(fn)
    prop = {}                                     # (var, web) -> (name, role)
    used = {}                                     # new name -> var

    def nm(v, line):
        """current or proposed name of ghidra identifier v at body line"""
        t = tok.get((line, v), v)
        if not PHRE.match(t): return t
        k = web_of.get((v, line))
        if k is not None and (v, k) in prop: return prop[(v, k)][0]
        return None

    def alldefs_ok(v, k):
        """every line of the web that assigns v is a simple `v = rhs;` line"""
        for x in webs[v][k]:
            if re.search(r'(?<![\w])%s\s*(?:=|\+=|-=)(?!=)' % re.escape(v), body[x]) and not re.match(r'^\s*%s = .*;$' % re.escape(v), body[x]):
                return False
        return True

    def give(v, k, name, role):
        if (v, k) in prop: return
        base = name; j = 1
        while name in used and used[name] != v:
            j += 1; name = base + (chr(ord('A') + j - 1) if role == 'vec' else str(j))
        used[name] = v; prop[(v, k)] = (name, role)

    allvars = [(v, k) for v in webs for k in range(len(webs[v]))]
    allv = lambda v, k: any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(v), cur[x]) for x in webs[v][k])   # web still carries the placeholder
    for rnd in range(6):
        before = len(prop)
        for v, k in allvars:
            if (v, k) in prop or not allv(v, k) or not alldefs_ok(v, k): continue
            ls = webs[v][k]
            dl = [(x, re.match(r'^\s*%s = (.*);$' % re.escape(v), body[x]).group(1)) for x in ls if re.match(r'^\s*%s = (.*);$' % re.escape(v), body[x])]
            if not dl: continue
            V = re.escape(v)
            usetxt = '\n'.join(body[x] for x in ls)
            # --- vector pointer: loaded from an object field and used as a vector
            if all(re.match(r'^%s\*\((?:uint|undefined4|int) \*\*\)\((\w+) \+ (0x[0-9a-f]+)\)$' % CAST, r) for _, r in dl) and \
               re.search(r'\*%s\b(?! =)|(?<![\w])%s\[[12]\]|(?:FUN_0019401c|FUN_0019423c|Vector__\w+)\(%s,' % (V, V, V), usetxt):
                nn = set()
                for x, r in dl:
                    m = re.match(r'^%s\*\((?:uint|undefined4|int) \*\*\)\((\w+) \+ (0x[0-9a-f]+)\)$' % CAST, r)
                    b = nm(m.group(1), x)
                    if b is None: nn = None; break
                    nn.add((b, m.group(2)[2:]))
                if nn and len(nn) == 1:
                    b, off = next(iter(nn))
                    give(v, k, ('vectorAt' + off) if b in ('program', 'this') else (b + 'VectorAt' + off), 'vec'); continue
            # --- vector pointer copied from an already named vector
            if all(re.match(r'^%s(\w+)$' % CAST, r) for _, r in dl) and re.search(r'\*%s\b(?! =)|(?<![\w])%s\[[12]\]|(?:FUN_0019401c|FUN_0019423c|Vector__\w+)\(%s,' % (V, V, V), usetxt):
                nn = {nm(re.match(r'^%s(\w+)$' % CAST, r).group(1), x) for x, r in dl}
                if None not in nn and len(nn) == 1:
                    s = next(iter(nn))
                    if s in vecnames(prop) or s in ('vector',) : give(v, k, s, 'vec'); continue
            # --- count: v = P[1] (P a vector)
            ps = set(); ok = True
            for x, r in dl:
                m = re.match(r'^%s(\w+)\[1\]$' % CAST, r)
                if m:
                    p = nm(m.group(1), x)
                    if p is None or not isvec(p, prop): ok = False; break
                    ps.add(p); continue
                m = re.match(r'^(\w+) \+ 1$', r)
                if m and web_of.get((m.group(1), x)) is not None and prop.get((m.group(1), web_of[(m.group(1), x)]), ('', ''))[1] == 'idx':
                    ps.add(prop[(m.group(1), web_of[(m.group(1), x)])][0][:-5]); continue
                ok = False; break
            if ok and len(ps) == 1: give(v, k, next(iter(ps)) + 'Count', 'cnt'); continue
            # --- index: 0 / v + 1 / v - 1, used against a vector
            if all(r in ('0', '%s + 1' % v, '%s - 1' % v, '%s + -1' % v) for _, r in dl) and any(r == '0' for _, r in dl):
                ps = set()
                for x in ls:
                    for m in re.finditer(r'(?<![\w])%s < \*(\w+)|%s \* 4 \+ (\w+)\[2\]|(?:FUN_0019423c|Vector__elementRefGrow)\((\w+),%s\)' % (V, V, V), body[x]):
                        p = nm([g for g in m.groups() if g][0], x)
                        ps.add(p)
                if len(ps) == 1 and None not in ps and isvec(next(iter(ps)), prop):
                    give(v, k, next(iter(ps)) + 'Index', 'idx'); continue
            # --- element reference
            ps = set(); ok = True
            for x, r in dl:
                m = re.match(r'^%s\((\w+) \* 4 \+ (\w+)\[2\]\)$' % CAST, r) or re.match(r'^%s(\w+) \* 4 \+ (\w+)\[2\]$' % CAST, r)
                if m: p = nm(m.group(2), x); ps.add(p); ok = ok and p is not None; continue
                m = re.match(r'^%s(?:FUN_0019423c|Vector__elementRefGrow)\((\w+),(\w+)\)$' % CAST, r)
                if m: p = nm(m.group(1), x); ps.add(p); ok = ok and p is not None; continue
                ok = False; break
            if ok and len(ps) == 1 and isvec(next(iter(ps)), prop):
                give(v, k, next(iter(ps)) + 'ElementRef', 'ref'); continue
            # --- element: *ref
            ps = set(); ok = True
            for x, r in dl:
                m = re.match(r'^%s\*(\w+)$' % CAST, r)
                if m:
                    e = nm(m.group(1), x)
                    if e and e.endswith('ElementRef') and isvec(e[:-10], prop): ps.add(e[:-10]); continue
                ok = False; break
            if ok and len(ps) == 1: give(v, k, next(iter(ps)) + 'Element', 'elem'); continue
        if len(prop) == before: break
    return prop, webs, body


def vecnames(prop): return {n for n, r in prop.values() if r == 'vec'}


def isvec(p, prop): return p in vecnames(prop) or p == 'vector' or p.endswith(('VectorAt',)) or bool(re.search(r'VectorAt[0-9a-f]+$', p))


def main():
    fns = functions() if fnarg == 'ALL' else [fnarg]
    tot = collections.Counter(); rows = []
    for fn in fns:
        try: prop, webs, body = run(fn)
        except BaseException as e:
            tot['err'] += 1; continue
        if not prop: continue
        if SHOW:
            print('==', fn)
            for (v, k), (n, r) in sorted(prop.items()): print('  %s w%d -> %s (%s)' % (v, k, n, r))
            continue
        spec = collections.OrderedDict()
        for (v, k), (n, r) in prop.items(): spec.setdefault((v, n), []).append(k)
        lines = ['%s\t%s\t%s\tINFERRED\tinline Vector idiom (%s): role from the shape of the definitions, vector named by the object field it is loaded from' % (v, ','.join(map(str, sorted(ks))), n, prop[(v, ks[0])][1]) for (v, n), ks in spec.items()]
        tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(lines) + '\n'); tf.close()
        r = subprocess.run([sys.executable, '-I', 'Tools/userspace/emit_webs.py', d, fn, tf.name], capture_output=True, text=True)
        os.unlink(tf.name)
        if r.returncode: tot['emitfail'] += 1; print('emit failed', fn, r.stderr[-200:], file=sys.stderr); continue
        rows.append(r.stdout.rstrip('\n')); tot['fn'] += 1; tot['webs'] += len(prop)
    print(dict(tot), file=sys.stderr)
    if not SHOW and rows: open(out, 'a').write('\n'.join(x for x in rows if x.strip()) + '\n')


main()
