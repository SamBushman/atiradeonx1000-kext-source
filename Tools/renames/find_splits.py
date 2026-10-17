#!/usr/bin/env python3
"""find_splits.py - help choose the `use` rows of Tools/renames/*.tsv (see Tools/apply_renames.py): list every assignment and read of one variable in one
function, with its line number, brace depth and the line itself, and mark the assignments that END the previous value (the right-hand side does not
mention the variable and the assignment is at the depth of the function's first statements), the natural start of a new segment.

Usage: find_splits.py Class::method[@0xADDR] VARIABLE        (run from the repository root; reads Sources/*.cpp)
Output columns: line  depth  kind  text      kind: W = assignment, R = read, RW = both on one line (x = x + 1, x++), D = declaration
A segment boundary is only valid when no value of the variable crosses it (no read before a new assignment on any path, including loop back-edges
and gotos): the compiled kext staying byte-identical (Tools/verify_identical_build.sh) is the check; this tool only lists candidates.
"""
import os, re, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import apply_renames as ar


def main():
    if len(sys.argv) != 3: sys.exit(__doc__)
    root = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..')
    cls, meth, addr, nth = ar.parse_target(sys.argv[1]); var = sys.argv[2]
    read = lambda f: open(f).read()
    spans = ar.find_defs(root, cls, meth, addr, read)
    if len(spans) != 1: sys.exit('%d matches for %s' % (len(spans), sys.argv[1]))
    f, st, en = spans[0]; s = read(f); scope = s[st:en]
    first_line = s[:st].count('\n') + 1
    depth = 0; out = []
    asg = re.compile(r'(?<![\w.>])%s\s*(?:=(?!=)|\+=|-=|\*=|/=|\|=|&=|<<=|>>=|\^=)' % re.escape(var))
    for i, l in enumerate(scope.split('\n')):
        code = re.sub(r'//.*|/\*.*?\*/', '', l)
        code = re.sub(r'"(?:\\.|[^"\\])*"', '""', code)
        d_here = depth
        depth += code.count('{') - code.count('}')
        if not re.search(r'\b%s\b' % re.escape(var), code): continue
        if re.match(ar.DECL_RE % re.escape(var), l): kind = 'D'
        else:
            m = asg.search(code)
            rhs = code[m.end():] if m else ''
            reads_before = bool(re.search(r'\b%s\b' % re.escape(var), code[:m.start()] if m else code))
            reads_after = bool(re.search(r'\b%s\b' % re.escape(var), rhs)) or bool(m and code[m.start():m.end()].strip()[len(var):].strip() not in ('=',))
            kind = ('RW' if (reads_after or reads_before) else 'W') if m else 'R'
        mark = '  <- starts a value' if kind == 'W' else ''
        print('%5d  %2d  %-2s  %s%s' % (first_line + i, d_here, kind, l.strip()[:110], mark))


if __name__ == '__main__':
    main()
