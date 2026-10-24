#!/usr/bin/env python3
"""lanesplit.py DIR FN VAR SELNAME FLAGNAME : split a variable that is read as a select word and then re-used as a 0/1 flag on ONE condition line
(`if (((V & 0xff) != 4) || (V = 1, (W & 0xff) != 4)) { V = 0; }`), the way Ghidra writes an inlined `flag = a == 4 && b == 4`.
For every such line: row 1 names the select-word web (from its definition `V = *(uint *)(X + 0x10);` to the condition line, `last=o1`: only the first occurrence of V on the
condition line; `+N` = N full lines, then the `last` part of line N+1), row 2 names the flag web (condition line with `first=o1`: after row 1 only the flag occurrence is left to the last line that reads the flag). FN is the Ghidra (table) name or the current name.
Rows go to stdout (apply_names.py `use` rows)."""
import sys, re, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, fn, var, sel, flag = sys.argv[1:6]
body, brace = F.load(d, fn)
V = re.escape(var)
cond = [i for i in range(brace + 1, len(body)) if re.search(r'\|\| \(%s = 1,' % V, body[i])]
def anchor(i):
    txt = body[i].strip()
    eq = [j for j in range(brace + 1, len(body)) if body[j].strip() == txt]
    nth = eq.index(i) + 1
    return '^\\s*' + re.escape(txt) + '$' + ('@%d' % nth if nth > 1 else '')
rows = []
for c in cond:
    d0 = max(j for j in range(brace + 1, c) if re.match(r'^\s*%s = \*\(uint \*\)\(\w+ \+ 0x10\);$' % V, body[j]))
    use = min(j for j in range(c + 1, len(body)) if re.search(r'(?<![\w])%s(?![\w])' % V, body[j]) and not re.match(r'^\s*%s = 0;$' % V, body[j]))
    rows.append('use\t%s\t%s\t%s\tINFERRED\tselect word of a source operand, compared lane by lane with select code 4\t%s\t+%d\tall\to1' % (fn, var, sel, anchor(d0), c - d0))
    rows.append('use\t%s\t%s\t%s\tINFERRED\t1 when both source select words have select code 4 in lane 0 (low byte), else 0; read when the flags are packed into inst+0x9c\t%s\t+%d\to1\tall' % (fn, var, flag, anchor(c), use - c))
print('\n'.join(rows))
