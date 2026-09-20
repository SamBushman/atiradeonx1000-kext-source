#!/usr/bin/env python3
"""detect_dropped_args.py CORPUS_DIR [CORPUS_DIR...] - calls printed without arguments (`f();`, `((int (*)())f)()`) to a function whose definition takes parameters:
the Ghidra rendering that drops register arguments (issue #61). Prints the counts and the most frequent callees."""
import re, glob, sys, collections
tot = 0
for d in sys.argv[1:]:
    text = ''.join(open(f).read() for f in sorted(glob.glob(d + '/part_*.c')))
    nparams = {}
    for m in re.finditer(r'(?m)^[A-Za-z_][\w \*]*?[ \*](\w+)\(([\w, ]*)\)\s*$', text):
        nparams.setdefault(m.group(1), len([a for a in m.group(2).split(',') if a.strip()]))
    for m in re.finditer(r'(?m)^[A-Za-z_][\w \*]*?[ \*](\w+)\(([^)]*)\)\s*$', text):
        nparams.setdefault(m.group(1), len([a for a in m.group(2).split(',') if a.strip() and a.strip() != 'void']))
    c = collections.Counter()
    for m in re.finditer(r'\(\(int \(\*\)\(\)\)(\w+)\)\(\)|(?<![\w.>])(\w+)\(\);', text):
        n = m.group(1) or m.group(2)
        if nparams.get(n, 0) > 0:
            c[n] += 1
    print('%s: %d argument-less calls to functions that take parameters (%d callees) %s' % (d, sum(c.values()), len(c), c.most_common(5)))
    tot += sum(c.values())
