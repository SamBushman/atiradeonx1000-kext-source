#!/usr/bin/env python3
"""apply_names.py - give the Ghidra placeholder names in the userspace corpus real names, from a table.

Usage: apply_names.py [--check] [--root DIR] Userspace/<Binary>/<arch>      (applies <dir>/names.tsv and <dir>/names_*.tsv to <dir>/part_*.c)

Table rows (tab separated, '#' starts a comment line):
    local<TAB>FUNCTION<TAB>old<TAB>new<TAB>tier<TAB>evidence     rename parameter/local `old` to `new` inside FUNCTION (whole function)
FUNCTION is the name in the `/* NAME @ 0xADDR (N bytes) */` header comment that opens each function (FUN_xxxx names work too).
tier is CONFIRMED (the binary shows it: a string, a called API's documented argument, a struct field the code both writes and reads in a
named way), INFERRED (the role is clear from use, nothing names it) or UNKNOWN (kept as a descriptive guess).

Idempotent: a row whose `old` is gone and whose `new` is present is "already applied". An `old` that is absent and a `new` that is absent
is an error. A `new` that is already used in the function (as another variable, or as a global/function declared in decls.h) is refused.
Renames never change generated code at -O0: Tools/userspace/verify_names.sh compiles the corpus before and after and demands identical objects.
"""
import re, sys, os, glob

IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')
HDR = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/$')


def split_functions(text):
    """-> list of (name, start_line, end_line) over text.split('\n'); a function runs from its header comment to the next header (or EOF)."""
    lines = text.split('\n'); marks = []
    for i, l in enumerate(lines):
        m = HDR.match(l)
        if m: marks.append((m.group(1), i))
    out = []
    for k, (n, i) in enumerate(marks):
        out.append((n, i, marks[k + 1][1] if k + 1 < len(marks) else len(lines)))
    return lines, out


def strip_strings(s):
    return re.sub(r'"(\\.|[^"\\])*"', lambda m: '"' + 'x' * (len(m.group(0)) - 2) + '"', s)


def load_rows(d):
    rows = []
    for f in sorted(glob.glob(os.path.join(d, 'names.tsv')) + glob.glob(os.path.join(d, 'names_*.tsv'))):
        for n, l in enumerate(open(f), 1):
            if not l.strip() or l.startswith('#'): continue
            c = l.rstrip('\n').split('\t')
            if len(c) < 5 or c[0] != 'local':
                print('%s:%d: bad row' % (f, n)); sys.exit(1)
            rows.append((f, n, c[1], c[2], c[3], c[4]))
    return rows


def main():
    a = sys.argv[1:]; check = '--check' in a; a = [x for x in a if x != '--check']
    d = a[0]
    rows = load_rows(d)
    decl = set(IDENT.findall(re.sub(r'/\*.*?\*/|//[^\n]*', ' ', open(os.path.join(d, 'decls.h')).read(), flags=re.S)))   # identifiers only, not words in comments
    byfn = {}
    for r in rows: byfn.setdefault(r[2], []).append(r)
    pending = applied = errors = 0
    for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        text = open(pf).read(); lines, fns = split_functions(text); changed = False
        for name, s, e in fns:
            if name not in byfn: continue
            body = '\n'.join(lines[s:e])
            for (f, n, fn, old, new, tier) in byfn.pop(name):
                code = strip_strings(body)
                ids = set(IDENT.findall(code))
                if old not in ids:
                    if new in ids: applied += 1; continue
                    print('%s:%d: %s: neither %s nor %s present' % (f, n, fn, old, new)); errors += 1; continue
                if new in ids or new in decl:
                    print('%s:%d: %s: new name %s collides' % (f, n, fn, new)); errors += 1; continue
                body = re.sub(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(old), new, body)
                pending += 1; changed = True
            lines[s:e] = body.split('\n')
        if changed and not check:
            open(pf, 'w').write('\n'.join(lines))
    for fn, rs in byfn.items():
        for r in rs: print('%s:%d: function %s not found' % (r[0], r[1], fn)); errors += 1
    print('%d renames %s, %d already applied, %d errors' % (pending, 'pending' if check else 'applied', applied, errors))
    sys.exit(1 if errors or (check and pending) else 0)


main()
