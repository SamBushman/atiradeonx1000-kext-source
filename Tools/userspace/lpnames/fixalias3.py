#!/usr/bin/env python3
"""fixalias3.py DIR PARTLO PARTHI OUT.tsv [--apply] [--only FN]
Fixes the whole-function `arena` / `allocation` rows (names_W5.tsv) of variables that hold other things in some webs.
Per mixed variable: delete the row, restore Ghidra's name in the function text, then write per-web `use` rows to OUT:
  * a web whose definitions are all the arena (compiler+0x374/0x378 / COMP_arena*) -> `arena`; all bump-allocator results -> `allocation`
  * the vector-construction web `X = <arena>; ... X = FUN_00193e18(X,n); ...uses of X` (def 1 arena, def 2 allocator call with X as argument, no other defs)
    is split at the second definition with the first/last = lhs/rhs columns: before it and on its right-hand side `arena`, from its left-hand side on `vectorData`
  * every other web returns to the Ghidra placeholder (to be named for what it is)
Without --apply it only lists what it would do. The FUNCTION field of the new rows is the current function name."""
import sys, os, re, glob, collections
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
import apply_names as A
d, lo, hi, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
apply = '--apply' in sys.argv
only = sys.argv[sys.argv.index('--only') + 1] if '--only' in sys.argv else None
H = re.compile(r'^/\* (\S+) @ 0x')
cur_name = {}      # root/old name -> current header name
parts = {}
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    p = int(re.search(r'part_(\d+)', pf).group(1))
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m: parts[m.group(1)] = p
roots = A.func_roots(A.load_funcs(d))
for n in parts: cur_name[roots.get(n, n)] = n
mine = {n for n, p in parts.items() if lo <= p <= hi}
ARENA = re.compile(r'COMP_arena[AB]|\+ 0x37[48]\)'); ALLOC = re.compile(r'FUN_00193e18\(|Arena__alloc\(')
rowsby = collections.defaultdict(list)
for f in sorted(glob.glob(d + '/names*.tsv')):
    for ln, l in enumerate(open(f, errors='surrogateescape')):
        c = l.rstrip('\n').split('\t')
        if c[0] == 'local' and len(c) >= 6 and c[3] in ('arena', 'allocation') and cur_name.get(roots.get(c[1], c[1])) in mine:
            rowsby[cur_name[roots.get(c[1], c[1])]].append((f, c))
newrows = []; touched = set(); delrows = []
def defs_of(body, ls, var):
    return [l for l in ls if re.search(r'(?<![\w.>*\]])%s\s*=(?!=)' % re.escape(var), body[l])]
for fn, rs in sorted(rowsby.items()):
    if only and fn != only: continue
    try: body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException as e: print('SKIP', fn, str(e)[:60]); continue
    for f, c in rs:
        old, new = c[2], c[3]
        try: ws, er = F.webs(nodes, entry, old)
        except BaseException as e: print('SKIP', fn, old, str(e)[:60]); continue
        plan = []; mixed = False
        for k, w in enumerate(ws):
            ls = sorted(w); df = defs_of(body, ls, old)
            rhs = [body[l].split('=', 1)[1] for l in df]
            if df and all((ARENA if new == 'arena' else ALLOC).search(r) for r in rhs): plan.append(('A', k, ls, None))
            elif new == 'arena' and len(df) == 2 and ARENA.search(rhs[0]) and re.search(r'FUN_00193e18\(%s,' % re.escape(old), rhs[1]) \
                    and all(l not in df for l in ls if l > df[1]):
                plan.append(('AB', k, ls, df[1]))
            else: plan.append(('X', k, ls, None)); mixed = True
        if not mixed: continue
        print('%s %s->%s: %s' % (fn, old, new, ' '.join('%s%d' % (t, k) for t, k, _, _ in plan)))
        if not apply: continue
        touched.add(parts[fn]); delrows.append((f, tuple(c[:4])))
        def anchor(x):
            txt = body[x].strip(); eq = [i for i in range(brace + 1, len(body)) if body[i].strip() == txt]; nth = eq.index(x) + 1
            return '^\\s*' + re.escape(txt) + '$' + ('@%d' % nth if nth > 1 else '')
        def emit(nm, lines, first='', ev=c[5]):
            for (x, y) in F.runs(lines):
                newrows.append('use\t%s\t%s\t%s\tINFERRED\t%s\t%s\t+%d%s' % (fn, old, nm, ev, anchor(x), y - x + 1, ('\t' + first) if first and x == lines[0] else ''))
        for t, k, ls, l2 in plan:
            if t == 'A': emit(new, ls)
            elif t == 'AB':
                emit('arena', [l for l in ls if l < l2], ev='compiler arena (before the allocation)')
                newrows.append('use\t%s\t%s\tarena\tINFERRED\tarena argument of the data-buffer allocation\t%s\t+1\trhs' % (fn, old, anchor(l2)))
                newrows.append('use\t%s\t%s\tvectorData\tINFERRED\tresult of the 8-byte bump allocation: data pointer of the new vector\t%s\t+%d\tlhs' % (fn, old, anchor(l2), max(ls) - l2 + 1))
if apply:
    for f, key in set(delrows):
        L = open(f, errors='surrogateescape').read().split('\n')
        L = [l for l in L if tuple(l.split('\t')[:4]) != key]
        open(f, 'w', errors='surrogateescape').write('\n'.join(L))
    # restore Ghidra's name in the function text
    for fn, rs in rowsby.items():
        if only and fn != only: continue
        for f, c in rs:
            if (f, tuple(c[:4])) not in set(delrows): continue
            for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
                L = open(pf, errors='surrogateescape').read().split('\n'); on = False; ch = False
                for i, l in enumerate(L):
                    m = H.match(l)
                    if m: on = (m.group(1) == fn); continue
                    if on:
                        n2 = re.sub(r'\b%s\b' % re.escape(c[3]), c[2], l)
                        if n2 != l: L[i] = n2; ch = True
                if ch: open(pf, 'w', errors='surrogateescape').write('\n'.join(L))
    open(out, 'a').write('\n'.join(newrows) + '\n')
    print('rows written', len(newrows), 'parts touched', sorted(touched))
