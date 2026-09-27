#!/usr/bin/env python3
"""fix_passthrough_ret.py PARTS_DIR ROWS.tsv - apply the TAIL rows from passthrough_ret.py (issue #65/#68, defect class 25): a stock function whose
last executed instruction before `blr` is the `bl`/`bctrl` of a call itself passed through unaltered, decompiled as `<call>(...); return;` in an `int`
function. On a plain -O0 build this happens to work (nothing generated between the call and the bare `return;` touches r3), but it is register luck,
not a stated fact of the C: an instrumented build (-finstrument-functions) inserts __cyg_profile_func_exit right there and clobbers r3 - this is exactly
how glprog's coverage build crashed in TParseContext::executeInitializer (_ShConstructCompiler dropped ConstructCompiler's TCompiler* return, 2026-09-26).
Rewrites `  <call-statement>;\n  return;\n}` to `  return <call-statement>;\n}`, but ONLY when that last statement is itself a call (no top-level `=`
outside parens - excludes plain field-store functions, which are correctly void) with no other statement following it before the closing return.
Edits part_*.c files in place. Prints one line per function actually rewritten, and one per row it left alone with the reason (stderr)."""
import sys, re, glob, os

parts_dir, rows_file = sys.argv[1:3]
want = {}
for l in open(rows_file):
    f = l.rstrip('\n').split('\t')
    if not f or f[0] != 'TAIL': continue
    want[f[1]] = f[2]

CONTROL_KW = ('if', 'else', 'while', 'do', 'for', 'switch', 'case', 'default', 'return', 'break', 'continue', 'goto')
def is_call_stmt(stmt):
    s = stmt.strip()
    # reject anything that isn't a plain expression statement: a brace anywhere means the "last statement" scan actually swallowed a control-flow
    # construct's closing brace (e.g. a do{...}while(cond) tail with no explicit `return;` of its own - found live, glprog TGenericLinker's C-tors:
    # the outer \A(.*\);) match is DOTALL and grabbed "} while (...);" as if it were a call, since it too ends in ");"). A real call statement never
    # contains `{` or `}`, and never starts with a control-flow keyword.
    if '{' in s or '}' in s: return False
    if re.match(r'^(?:%s)\b' % '|'.join(CONTROL_KW), s): return False
    depth = 0
    for i, c in enumerate(s):
        if c == '(': depth += 1
        elif c == ')': depth -= 1
        elif c == '=' and depth == 0:
            if s[i - 1:i] in ('=', '!', '<', '>') or s[i + 1:i + 2] == '=': continue
            return False
    # must end with a balanced, closed call's `)` - not e.g. a bare "while (cond)" condition left dangling, and not a statement whose top-level form
    # isn't "<primary>(<args>)" at all (depth returned to exactly 0 at the very last character, and that character is ')')
    return depth == 0 and s.endswith(')')

fixed = 0
for p in sorted(glob.glob(os.path.join(parts_dir, 'part_*.c'))):
    txt = open(p, errors='replace').read()
    ms = list(re.finditer(r'^/\* .* @ (0x[0-9a-f]+) \(\d+ bytes\) \*/\n', txt, re.M))
    edits = []     # (start, end, replacement), applied back-to-front
    for i, m in enumerate(ms):
        addr = m.group(1)
        if addr not in want: continue
        end = ms[i + 1].start() if i + 1 < len(ms) else len(txt)
        fbody = txt[m.end():end]
        decl_line = fbody.split('\n', 1)[0]
        if re.match(r'^\s*void\b', decl_line):
            print('SKIP\t%s\t%s\tfunction is declared void - no caller reads a return value, fix unnecessary' % (addr, want[addr]), file=sys.stderr); continue
        if not re.match(r'^\s*int\b', decl_line):
            # r3-forwarding only makes sense when the function is declared `int` (ghidra2c's default): a `double`/`float`-declared owner returns
            # through f1, not r3, and `return <int-typed-call>;` there would insert a real int->double conversion - a deterministic but WRONG value,
            # worse than the pre-existing garbage. (Found live: GLDriver FUN_000520c0, declared `double`, tail-calls an `(int (*)())`-cast FUN_0004f550.)
            print('SKIP\t%s\t%s\tfunction is declared %r, not int - r3 is not its return register, leaving alone' % (addr, want[addr], decl_line.split()[0]), file=sys.stderr); continue
        mm = re.search(r'\A(.*\);)\n  return;\n\}(\s*)\Z', fbody, re.S)
        if not mm:
            print('SKIP\t%s\t%s\tno matching call;return;} tail' % (addr, want[addr]), file=sys.stderr); continue
        pre = mm.group(1)
        lines = pre.split('\n')
        k = len(lines) - 1
        while k > 0 and not re.match(r'^  \S', lines[k]): k -= 1
        stmt_lines = lines[k:]
        stmt_lines[-1] = stmt_lines[-1][:-1]              # drop the trailing ';'
        stmt_lines[0] = stmt_lines[0][2:]                 # drop the statement's own leading "  " (the "return " takes its place)
        stmt = '\n'.join(stmt_lines)
        if not is_call_stmt(stmt.replace('\n', ' ')):
            print('SKIP\t%s\t%s\tlast statement has a top-level = (not a plain call)' % (addr, want[addr]), file=sys.stderr); continue
        abs_s = m.end() + mm.start(); abs_e = m.end() + mm.end()
        new_pre = '\n'.join(lines[:k]) + ('\n' if k else '') + '  return %s;' % stmt
        new_tail = '%s\n}%s' % (new_pre, mm.group(2))
        edits.append((abs_s, abs_e, new_tail))
        print('FIX\t%s\t%s' % (addr, want[addr]))
        fixed += 1
    if edits:
        for s, e, r in sorted(edits, reverse=True):
            txt = txt[:s] + r + txt[e:]
        open(p, 'w').write(txt)
print('# %d functions rewritten' % fixed, file=sys.stderr)
