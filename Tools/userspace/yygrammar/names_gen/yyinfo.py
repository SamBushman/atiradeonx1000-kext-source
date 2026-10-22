"""yyinfo.py - shared analysis of yyparse (libGLProgrammability part_006.c) for the R1b generators: lines, webs, case regions, grammar rules."""
import sys, re, collections
ROOT = '/home/sam/wt/R1b'
sys.path.insert(0, ROOT + '/Tools/userspace'); sys.path.insert(0, ROOT + '/Tools/userspace/yygrammar')
import webs
exec(open(ROOT + '/Tools/userspace/yygrammar/rules.py').read())      # G = [(lhs, [rhs symbols])], rule N = G[N-1]
PART = ROOT + '/Userspace/libGLProgrammability/ppc/part_006.c'
PH = re.compile(r'^(param_[0-9]+|[a-zA-Z]{0,4}Var[0-9]+|local_[0-9a-f]+|[a-z]Stack_?[0-9a-f]+)$')

def load():
    L = open(PART).read().split('\n')
    s = next(i for i, l in enumerate(L) if l.startswith('/* yyparse @'))
    e = next(i for i in range(s + 1, len(L)) if L[i].startswith('/* '))
    lines = L[s:e]
    while lines[-1].strip() == '': lines.pop()
    brace = next(i for i, l in enumerate(lines) if l == '{')
    DECL = re.compile(r'\s+(?!return\b)[\w ]+?[ *]+([A-Za-z_]\w*)( ?\[\w+\])?;$')
    d1 = brace + 1
    while DECL.match(lines[d1]) or not lines[d1].strip() or re.match(r'\s*(/\*|\*)', lines[d1]): d1 += 1
    vs = [DECL.match(l).group(1) for l in lines[brace + 1:d1] if DECL.match(l)]
    return lines, brace, d1, vs

lines, brace, d1, vs = load()
fn = webs.Function(lines, d1, len(lines) - 1, vs)
assert fn.ok, fn.err
region = [None] * len(lines); cur = None
for i, l in enumerate(lines):
    m = re.match(r'\s*case (0x[0-9a-f]+|\d+):', l)
    if m: cur = int(m.group(1), 0)
    if re.match(r'\s*default:', l): cur = 'default'
    region[i] = cur
CASE_LINE = {}
for i, l in enumerate(lines):
    m = re.match(r'\s*case (0x[0-9a-f]+|\d+):', l)
    if m: CASE_LINE.setdefault(int(m.group(1), 0), i)

RULES = []                              # bison numbering: a mid-rule action `@x` is an empty rule numbered just before the rule that contains it
for lhs, rhs in G:
    for sym in rhs:
        if sym.startswith('@'): RULES.append((sym, []))
    RULES.append((lhs, rhs))
def rule(n): return RULES[n - 1]          # (lhs, [rhs symbols])

class W:
    """one web: variable, ordered index, units, def lines"""
    def __init__(self, v, k, w):
        self.v, self.k, self.w = v, k, w
        self.lines = sorted({u[0] for u in w.units})
        self.deflines = sorted({u[0] for u in w.defunits})
        self.cases = {region[l] for l in self.lines}
        self.name = None; self.tier = None; self.ev = None
    def case(self):
        c = self.cases
        return next(iter(c)) if len(c) == 1 else None
    def rhs(self, ln):
        m = re.match(r'.*?(?<![\w.])%s = (.*)$' % re.escape(self.v), lines[ln].strip())
        return m.group(1) if m else None

def all_webs(only_ph=True):
    out = []
    for v in vs:
        if only_ph and not PH.match(v): continue
        ws = sorted(fn.webs.get(v, []), key=lambda w: min(u[0] for u in w.units))
        for k, w in enumerate(ws): out.append(W(v, k, w))
    return out

def occ(v, text):
    return len(re.findall(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(v), text))
def web_size(w):
    return sum(occ(w.v, lines[l]) for l in w.lines)

def stmt_at(ln):
    """the full statement text starting at line ln (continuation lines joined until the statement's ';' / '{')"""
    t = lines[ln].strip(); k = ln
    while not re.search(r'[;{}]\s*$', t) and k + 1 < len(lines):
        k += 1; t += ' ' + lines[k].strip()
    return t

def rhs_of(v, ln):
    t = stmt_at(ln)
    m = re.search(r'(?<![\w.>])%s = ' % re.escape(v), t)
    if not m: return None
    i = m.end(); d = 0; j = i
    while j < len(t):
        ch = t[j]
        if ch in '([': d += 1
        elif ch in ')]':
            d -= 1
            if d < 0: break
        elif ch in ',;' and d == 0: break
        elif ch == '"':
            j += 1
            while j < len(t) and t[j] != '"':
                if t[j] == '\\': j += 1
                j += 1
        j += 1
    return t[i:j].strip()


# case purity: lines whose only way in is the `case N:` label above them (no LAB_/switchD label between, no stacked case labels sharing the body)
LABEL = re.compile(r'^(LAB_\w+|switchD_\w+):\s*$')
pure = [False] * len(lines)
_last = None; _clean = False
for i, l in enumerate(lines):
    m = re.match(r'\s*case (0x[0-9a-f]+|\d+):', l)
    if m:
        # stacked labels: the next non-blank line is another case label -> shared body
        j = i + 1
        while j < len(lines) and not lines[j].strip(): j += 1
        stacked = bool(re.match(r'\s*case ', lines[j])) or (i > 0 and bool(re.match(r'\s*case ', lines[i - 1])))
        _clean = not stacked
        continue
    if LABEL.match(l): _clean = False
    if re.match(r'\s*default:', l): _clean = False
    pure[i] = _clean
