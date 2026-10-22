#!/usr/bin/env python3
"""find_webs.py - the real roles (def-use webs) of a reused local in a userspace corpus function, as `use` rows for apply_names.py.

    find_webs.py DIR FUNCTION VAR [VAR ...]            list the webs of each VAR (Ghidra's name) with their lines
    find_webs.py DIR FUNCTION --emit SPEC.tsv          write rows: SPEC lines are `VAR<TAB>WEB#<TAB>newname<TAB>tier<TAB>evidence`
                                                       (several WEB# per new name allowed: comma separated) to stdout

A web is a set of definitions that reach a common use (plus the uses), found on a statement-level CFG built from Ghidra's structured C
(if/else, do/while, while, for, goto/labels, return, break). Statements that touch two webs of the same variable (`x = f(x)`) merge them, because a
row renames whole lines. A variable whose address is taken (`&x`) is refused: its uses are not visible. Lines are taken as Ghidra wrote them
(every rename of the function is taken back first), the rows anchor on the exact line text (`@N` for the Nth equal line) and run `+K` lines.
Reaching an use from function entry (no definition) is reported as `ENTRY`; such a web keeps the variable's own name unless you name it.
"""
import re, sys, os, glob
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import apply_names as A

CURRENT = []
ASSIGN_OPS = r'(?:=|\+=|-=|\|=|&=|\^=|<<=|>>=|\*=|/=)'


def load(d, fn):
    rows = A.load_rows(d)
    back = {}
    for r in rows:
        if r[2] == fn: back[r[4]] = r[3]
    for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        text = open(pf).read(); lines, fns = A.split_functions(text)
        for name, s, e in fns:
            if name == fn:
                body = lines[s:e]
                brace = next(i for i, l in enumerate(body) if l == '{')
                norm = (lambda l: A.IDENT.sub(lambda m: back.get(m.group(0), m.group(0)), l)) if back else (lambda l: l)
                global CURRENT
                CURRENT = body
                return [norm(l) for l in body], brace
    sys.exit('function %s not found' % fn)


class Node:
    __slots__ = ('id', 'lines', 'text', 'succ', 'kind')

    def __init__(self, i, lines, text, kind='stmt'):
        self.id = i; self.lines = lines; self.text = text; self.succ = []; self.kind = kind


def build_cfg(body, brace):
    """-> nodes, entry. Statement-level CFG of the function body (lines after the `{` up to the closing `}`)."""
    end = len(body)
    while end > 0 and body[end - 1].strip() == '': end -= 1
    if body[end - 1].strip() == '}': end -= 1
    units = []; i = brace + 1
    DECL = re.compile(r'\s+(?!return\b)[\w ]+?[ *][A-Za-z_]\w*\s*(\[\w+\])?;$')
    while i < end and (DECL.match(body[i]) or not body[i].strip() or re.match(r'\s*(/\*|\*)', body[i])): i += 1
    while i < end:                                  # join continuation lines of one statement
        s = body[i]
        if not s.strip(): i += 1; continue
        j = i; t = s; depth = t.count('(') - t.count(')')
        while depth > 0 and j + 1 < end:
            j += 1; t += '\n' + body[j]; depth = t.count('(') - t.count(')')
        units.append((list(range(i, j + 1)), ' '.join(x.strip() for x in t.split('\n'))))
        i = j + 1
    nodes = []; labels = {}; pending_gotos = []

    def new(lines, text, kind='stmt'):
        n = Node(len(nodes), lines, text, kind); nodes.append(n); return n

    pos = [0]

    def link(frm, to):
        for f in frm: f.succ.append(to)

    def block(loopstack):
        """parse statements until the matching '}' (consumed) -> (entry, exits)"""
        entry = None; exits = []
        while pos[0] < len(units):
            lines, t = units[pos[0]]
            if t == '}':
                pos[0] += 1; break
            ent, ex = stmt(loopstack)
            if entry is None: entry = ent
            else: link(exits, ent)
            exits = ex
        return entry, exits

    def cond_then(t):
        """-> (cond text, rest after ')' ) for `if (...) rest`"""
        d = 0
        for k, ch in enumerate(t):
            if ch == '(': d += 1
            elif ch == ')':
                d -= 1
                if d == 0: return t[:k + 1], t[k + 1:].strip()
        return t, ''

    def stmt(loopstack):
        lines, t = units[pos[0]]; pos[0] += 1
        m = re.match(r'^(LAB_\w+):$', t)
        if m:
            n = new(lines, t, 'label'); labels[m.group(1)] = n; return n, [n]
        if t.startswith('return'):
            n = new(lines, t, 'return'); return n, []
        if t.startswith('goto '):
            n = new(lines, t, 'goto'); pending_gotos.append((n, t.split()[1].rstrip(';'))); return n, []
        if t.startswith('break;') and loopstack:
            n = new(lines, t, 'break'); loopstack[-1][1].append(n); return n, []
        if t.startswith('continue;') and loopstack:
            n = new(lines, t, 'continue'); loopstack[-1][2].append(n); return n, []
        if t == 'do {':
            ls = (None, [], [])
            head = new(lines, 'do', 'join'); entry, exits = block(loopstack + [ls])
            link([head], entry) if entry else None
            mm = units[pos[0]]; pos[0] += 1                # `while (cond);` follows the closing brace? Ghidra: `} while (cond);` is one unit
            raise SystemExit('unexpected do layout')
        if t.startswith('} while'):
            raise SystemExit('stray while')
        if t.startswith('if'):
            c, rest = cond_then(t[2:].strip())
            cn = new(lines, c, 'cond')
            if rest == '{':
                te, tx = block(loopstack)
                if te: cn.succ.append(te)
                else: tx = [cn]
                exits = list(tx)
                if pos[0] < len(units) and units[pos[0]][1].startswith('else'):
                    el, et = units[pos[0]]; pos[0] += 1
                    if el and et.startswith('else if'):
                        # else if (cond) { ... }: re-queue as an `if` unit
                        units.insert(pos[0], (el, et[5:].strip()))
                        ee, ex = stmt(loopstack)
                        cn.succ.append(ee); exits += ex
                    else:
                        ee, ex = block(loopstack)
                        if ee: cn.succ.append(ee); exits += ex
                        else: exits.append(cn)
                else:
                    exits.append(cn)
                return cn, exits
            if rest.startswith('goto '):
                pending_gotos.append((cn, rest.split()[1].rstrip(';'))); return cn, [cn]
            if rest.startswith('return'):
                return cn, [cn]
            if rest.startswith('break') and loopstack:
                loopstack[-1][1].append(cn); return cn, [cn]
            raise SystemExit('unhandled if form: ' + t)
        if t.startswith('while') or t.startswith('for'):
            kw = t.split('(')[0].strip()
            c, rest = cond_then(t[len(kw):].strip())
            if rest != '{': raise SystemExit('unhandled loop form: ' + t)
            ls = (None, [], [])
            if kw == 'for':
                init, cnd, inc = [x.strip() for x in c[1:-1].split(';')]
                ni = new(lines, init, 'stmt'); nc = new(lines, cnd, 'cond'); link([ni], nc)
                be, bx = block(loopstack + [ls]); nn = new(lines, inc, 'stmt')
                if be: nc.succ.append(be); link(bx, nn)
                else: nc.succ.append(nn)
                link(ls[2], nn); nn.succ.append(nc)
                return ni, [nc] + ls[1]
            nc = new(lines, c, 'cond'); be, bx = block(loopstack + [ls])
            if be: nc.succ.append(be); link(bx, nc)
            link(ls[2], nc)
            return nc, [nc] + ls[1]
        n = new(lines, t, 'stmt'); return n, [n]

    # do { ... } while (c);  is the one construct needing lookahead: handle by preprocessing the unit list
    ul = []
    for u in units:
        ul.append(u)
    units[:] = ul
    # custom loop for `do {`
    old_stmt = stmt

    def stmt2(loopstack):
        lines, t = units[pos[0]]
        if t == 'do {':
            pos[0] += 1; ls = (None, [], [])
            head = new(lines, 'do', 'join')
            # parse the body until the unit `} while (...);`
            entry = None; exits = []
            while pos[0] < len(units):
                l2, t2 = units[pos[0]]
                if t2.startswith('} while'):
                    pos[0] += 1; cn = new(l2, t2[1:].strip().rstrip(';').strip()[5:].strip(), 'cond'); break
                ent, ex = stmt2(loopstack + [ls])
                if entry is None: entry = ent
                else: link(exits, ent)
                exits = ex
            else:
                raise SystemExit('do without while')
            if entry is None: entry = cn
            else: link(exits, cn)
            head.succ.append(entry); link(ls[2], cn)
            cn.succ.append(head if False else entry)      # loop back to the body start
            return head, [cn] + ls[1]
        return old_stmt(loopstack)

    globals_ = None
    # rebind stmt so recursive calls use stmt2
    stmt_ref = {'f': stmt2}

    def stmt(loopstack):                            # noqa: F811  (dispatch through stmt2 for `do`)
        return stmt2(loopstack)

    entry = None; exits = []
    while pos[0] < len(units):
        ent, ex = stmt(loopstack=[])
        if entry is None: entry = ent
        else: link(exits, ent)
        exits = ex
    for n, lab in pending_gotos:
        if lab in labels: n.succ.append(labels[lab])
    return nodes, entry


def facts(nodes, var):
    """per node: (defs?, uses?) of var"""
    out = {}
    pd = re.compile(r'(?<![\w.>\]\)*&])%s\s*%s(?!=)' % (re.escape(var), ASSIGN_OPS))
    pa = re.compile(r'&\s*%s\b' % re.escape(var))
    ident = re.compile(r'(?<![\w])%s(?![\w])' % re.escape(var))
    for n in nodes:
        t = A.strip_strings(n.text)
        if pa.search(t): raise SystemExit('%s: address taken in "%s"' % (var, n.text))
        occ = [m.start() for m in ident.finditer(t)]
        defpos = [m.start() for m in pd.finditer(t) if t[m.start():m.start() + len(var)] == var]
        compound = [p for p in defpos if re.match(r'%s\s*(?:\+|-|\||&|\^|<<|>>|\*|/)=' % re.escape(var), t[p:])]
        isdef = bool(defpos)
        # uses: occurrences that are not the plain `=` target (compound assignment targets are uses too)
        plain = [p for p in defpos if p not in compound]
        isuse = any(p not in plain for p in occ)
        out[n.id] = (isdef, isuse, bool(compound))
    return out


def webs(nodes, entry, var):
    f = facts(nodes, var)
    preds = {n.id: [] for n in nodes}
    for n in nodes:
        for s in n.succ: preds[s.id].append(n.id)
    # reaching definitions: sets of def node ids; -1 = ENTRY
    IN = {n.id: set() for n in nodes}; OUT = {n.id: set() for n in nodes}
    IN[entry.id] = {-1}
    ch = True
    while ch:
        ch = False
        for n in nodes:
            i = n.id
            inn = set(IN[i]) if i == entry.id else set()
            for p in preds[i]: inn |= OUT[p]
            if i == entry.id: inn |= {-1}
            out = ({i} if f[i][0] else inn) if not (f[i][0] and f[i][2]) else {i}
            if f[i][0] and f[i][2]: out = {i}
            if inn != IN[i] or out != OUT[i]: IN[i], OUT[i] = inn, out; ch = True
    parent = {}

    def find(x):
        parent.setdefault(x, x)
        while parent[x] != x: parent[x] = parent[parent[x]]; x = parent[x]
        return x

    def union(a, b): parent[find(a)] = find(b)
    nodeset = {}                                      # node id -> web key (rep def)
    for n in nodes:
        i = n.id; isdef, isuse, comp = f[i]
        if isuse:
            ds = sorted(IN[i])
            for d in ds[1:]: union(ds[0], d)
            if comp and isdef: union(ds[0], i)
            if ds: find(ds[0])
        if isdef: find(i)
    # line-sharing merges
    linewebs = {}
    for n in nodes:
        i = n.id; isdef, isuse, comp = f[i]
        if not (isdef or isuse): continue
        keys = set()
        if isdef: keys.add(find(i))
        if isuse:
            for d in IN[i]: keys.add(find(d))
        for k in keys: pass
        for ln in n.lines:
            for k in keys:
                if ln in linewebs: union(linewebs[ln], k)
                else: linewebs[ln] = k
        ks = list(keys)
        for k in ks[1:]: union(ks[0], k)
    res = {}
    for n in nodes:
        i = n.id; isdef, isuse, comp = f[i]
        if not (isdef or isuse): continue
        k = None
        if isdef: k = find(i)
        elif IN[i]: k = find(sorted(IN[i])[0])
        res.setdefault(find(k), set()).update(n.lines)
    out = []
    for k, ls in res.items(): out.append(sorted(ls))
    out.sort(key=lambda l: l[0])
    return out, (-1 in {d for n in nodes if f[n.id][1] for d in IN[n.id]})


def runs(lines):
    r = []; a = lines[0]; p = a
    for x in lines[1:]:
        if x == p + 1: p = x
        else: r.append((a, p)); a = p = x
    r.append((a, p)); return r


def main():
    a = sys.argv[1:]
    d, fn = a[0], a[1]
    body, brace = load(d, fn)
    nodes, entry = build_cfg(body, brace)
    if a[2] == '--emit':
        rows = []; cache = {}
        for l in open(a[3]):
            if not l.strip() or l.startswith('#'): continue
            var, wl, new, tier, ev = l.rstrip('\n').split('\t')[:5]
            if wl == '*':                                    # whole-function rename (one role, or address taken)
                rows.append('local\t%s\t%s\t%s\t%s\t%s' % (fn, var, new, tier, ev)); continue
            if var not in cache: cache[var] = webs(nodes, entry, var)[0]
            for w in wl.split(','):
                lines = cache[var][int(w)]
                for (x, y) in runs(lines):
                    # exact line text anchor with @N among equal lines after the brace
                    txt = body[x].strip()
                    eq = [i for i in range(brace + 1, len(body)) if body[i].strip() == txt]
                    nth = eq.index(x) + 1
                    frm = '^\\s*' + re.escape(txt) + '$' + ('@%d' % nth if nth > 1 else '')
                    rows.append('use\t%s\t%s\t%s\t%s\t%s\t%s\t+%d' % (fn, var, new, tier, ev, frm, y - x + 1))
        print('\n'.join(rows))
        return
    if a[2] == '--all':                              # every placeholder variable still present, one line per web
        P = re.compile(r'\b(param_[0-9]+|[a-zA-Z]{0,4}Var[0-9]+|local_[0-9a-f]+|[a-z]Stack_?[0-9a-f]+|fparam_[0-9]+|in_[A-Za-z0-9]+|extraout_\w+)\b')
        names = sorted({m for l in CURRENT[brace + 1:] if not re.match(r'\s*(/\*|\*|//)', l) for m in P.findall(l)})
        for var in names:
            try: ws, er = webs(nodes, entry, var)
            except SystemExit as ex: print('== %s: %s' % (var, ex)); continue
            print('== %s (%d webs)' % (var, len(ws)))
            for k, ls in enumerate(ws):
                first = [x for x in ls if re.search(r'(?<![\w])%s\s*=(?!=)' % re.escape(var), body[x])]
                x = first[0] if first else ls[0]
                print('  %d: %d lines, %d..%d  %s' % (k, len(ls), ls[0], ls[-1], ' '.join(body[x].split())[:100]))
        return
    for var in a[2:]:
        ws, entry_reach = webs(nodes, entry, var)
        print('== %s: %d webs%s' % (var, len(ws), '  (some use reached from ENTRY)' if entry_reach else ''))
        for k, ls in enumerate(ws):
            print('  web %d: lines %s' % (k, ','.join('%d-%d' % r if r[0] != r[1] else str(r[0]) for r in runs(ls))))
            for x in ls[:3]: print('      %4d  %s' % (x, body[x].strip()[:110]))
            if len(ls) > 3: print('      ...')


main()
