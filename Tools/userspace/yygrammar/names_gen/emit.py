"""emit.py - write Userspace/libGLProgrammability/ppc/names_R1b.tsv from the webs named by gen_yy.py"""
import sys, re, os, collections
sys.path.insert(0, '/home/sam/g5logs/R1b'); sys.path.insert(0, '/home/sam/wt/R1b/Tools/userspace')
import gen_yy as g, yyinfo as y
import apply_names as an
D = '/home/sam/wt/R1b/Userspace/libGLProgrammability/ppc'
OUT = D + sys.argv[1] if len(sys.argv)>1 else D + '/names_R1b.tsv'
lines = y.lines
# normalised text (renames taken back) exactly as apply_names does it: all rows of the function, local and use
rows = [r for r in an.load_rows(D) if r[2] == 'yyparse' and not r[0].endswith(OUT.split('/')[-1])]
back = {r[4]: r[3] for r in rows}
def norm(l):
    return re.sub('|'.join(an.wb(k) for k in back), lambda m: back[m.group(0)], l) if back else l
N = [norm(l) for l in lines]
# candidate names, made unique per old variable
declset = set(re.findall(r'[A-Za-z_]\w*', re.sub(r'/\*.*?\*/|//[^\n]*', ' ', open(D + '/decls.h').read(), flags=re.S)))
used_ident = set(re.findall(r'[A-Za-z_]\w*', '\n'.join(lines)))
owner = {}                                   # new name -> old variable
final = {}
named = [w for w in g.WS if w.name]
named.sort(key=lambda w: (w.lines[0], w.v))
for w in named:
    base = re.sub(r'[^A-Za-z0-9_]', '', w.name) or 'x'
    nm = base; i = 1
    while True:
        o = owner.get(nm)
        free = (o is None or o == w.v) and (nm not in declset) and (nm not in used_ident or o == w.v)
        if free: break
        i += 1; nm = base + str(i)
    owner[nm] = w.v; final[id(w)] = nm
# row per (web, line)
def unit_flag(w, ln):
    parts = {u[1] for u in w.w.units if u[0] == ln}
    t = lines[ln]
    if an.split_assign(t) < 0: return 'all'
    return 'all' if parts == {0, 1} else ('lhs' if parts == {0} else 'rhs')
body0 = y.brace + 1
def anchor(ln):
    pat = '^\\s*' + re.escape(N[ln].strip()) + '\\s*$'
    hits = [i for i in range(y.brace + 1, len(lines)) if re.search(pat, N[i])]
    k = hits.index(ln) + 1
    return pat + ('@%d' % k if k > 1 else '')
out = ['# use\tFUNCTION\told\tnew\ttier\tevidence\tfrom\tto\tfirst\tlast   (R1b: webs of yyparse named from the recovered grammar, the dylib symbol table (vtables, method names) and bison/TType idioms; anchors are the exact Ghidra text of each line, @N = Nth identical line)']
n = 0
for w in named:
    nm = final[id(w)]
    for ln in sorted({u[0] for u in w.w.units}):
        out.append('\t'.join(['use', 'yyparse', w.v, nm, w.tier, w.ev.replace('\t', ' '), anchor(ln), '+1', unit_flag(w, ln), 'none'])); n += 1
open(OUT, 'w').write('\n'.join(out) + '\n')
print('webs', len(named), 'rows', n, 'distinct names', len(owner))
