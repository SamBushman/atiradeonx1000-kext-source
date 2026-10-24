#!/usr/bin/env python3
"""autoweb.py DIR FN RULES.py OUT [--show]

Rule-driven per-web naming. For every placeholder variable of FN (regex PH below, or the vars RULES.VARS lists) and every def-use web (find_webs), calls
    RULES.name(var, k, defs, lines, ctx)  ->  new name or None
defs = right-hand-side texts of the `var = ...` statements in the web (Ghidra's original text), lines = body line numbers of the web, ctx = object with
.body (list of original lines) and .case_of(line) (number of the enclosing `case N:` label of the function's main switch, or None).
Webs of one variable that get the same name are grouped. Writes `VAR<TAB>webs<TAB>name<TAB>INFERRED<TAB>evidence` lines for emit_webs.py (names made
unique across variables by appending B, C, ... - a name on two different Ghidra variables is an apply_names error) to OUT (appended); with --show prints
the classification instead of writing. Webs for which RULES.name returns None are listed (must be handled by hand).
RULES may define EVIDENCE (str) and `whole(var)` -> name for variables that are one role over the whole function (emitted as webs `*`)."""
import sys, os, re, importlib.util
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F

PH = re.compile(r'\b(?:[a-z]{0,3}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|[a-z]?Stack_[0-9a-f]+|param_\d+|fparam_\d+|in_stack_\w+|in_[a-z]+\d+)\b')
CASE = re.compile(r'^\s*case (0x[0-9a-f]+|\d+):')

class Ctx:
    def __init__(self, body):
        self.body = body
        self.cases = []
        for i, l in enumerate(body):
            m = CASE.match(l)
            if m: self.cases.append((i, int(m.group(1), 0)))
    def case_of(self, line):
        c = None
        for i, n in self.cases:
            if i <= line: c = n
            else: break
        return c

def main():
    d, fn, rules, out = sys.argv[1:5]
    show = '--show' in sys.argv
    spec = importlib.util.spec_from_file_location('rules', rules); R = importlib.util.module_from_spec(spec); spec.loader.exec_module(R)
    body, brace = F.load(d, fn)
    nodes, entry = F.build_cfg(body, brace)
    ctx = Ctx(body)
    vars_ = sorted({m.group(0) for l in body[brace:] for m in PH.finditer(l)} | set(getattr(R, 'VARS', [])), key=lambda v: (re.sub(r'\d+$', '', v), int(re.sub(r'\D', '', v) or 0) if not v.startswith('local_') else int(v[6:], 16)))
    ev = getattr(R, 'EVIDENCE', 'role read off the web definitions')
    rows = []; unhandled = []
    for var in vars_:
        w = getattr(R, 'whole', lambda v: None)(var)
        if w:
            rows.append((var, '*', w)); continue
        ws, er = F.webs(nodes, entry, var)
        DEF = re.compile(r'(?<![\w.>])%s\s*=(?!=)\s*(.*)' % re.escape(var))
        by = {}
        for k, ls in enumerate(ws):
            defs = [m.group(1) for x in ls for m in DEF.finditer(body[x])]
            nm = R.name(var, k, defs, sorted(ls), ctx)
            if show: print('%-9s w%-2d %-24s lines %s | %s' % (var, k, nm, '%d-%d' % (min(ls), max(ls)), ' || '.join(t[:46] for t in defs[:2])))
            if nm: by.setdefault(nm, []).append(k)
            else: unhandled.append((var, k, min(ls), max(ls)))
        for nm, ks in by.items(): rows.append((var, ','.join(map(str, ks)), nm))
    owner = {}; res = []
    for var, wl, nm in rows:
        base = nm; j = 0
        while nm in owner and owner[nm] != var:
            j += 1; nm = base + chr(ord('A') + j)
        owner[nm] = var; res.append('%s\t%s\t%s\tINFERRED\t%s' % (var, wl, nm, ev))
    if show:
        print('UNHANDLED', unhandled); return
    with open(out, 'a') as f: f.write('\n'.join(res) + '\n')
    print('rows', len(res), 'unhandled', unhandled)
main()
