#!/usr/bin/env python3
"""extraout_scan.py CORPUS_DIR  - functions that READ a Ghidra `extraout_f<N>` variable (the value a callee left in f<N>) that is never assigned in the C.

Ghidra prints `extraout_f1` for "f1 as the callee returned it" when the callee's prototype has no FP return. The corpus declares the variable and never assigns it, so the
compiled code reads whatever register the allocator picked (issue #296). Output: name<TAB>var<TAB>number of uses (stdout) and a summary line (stderr)."""
import re, glob, sys, os, collections
d = sys.argv[1]
bad = []
for f in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    s = open(f).read()
    for m in re.finditer(r'(?ms)^/\* (\S+) @ 0x[0-9a-f]+ \((\d+) bytes\) \*/\n(.*?)(?=^/\* \S+ @ 0x|\Z)', s):
        name, body = m.group(1), m.group(3)
        for v in sorted(set(re.findall(r'\bextraout_f\d+(?:_\d+)?\b', body))):
            asg = len(re.findall(r'\b%s\s*=[^=]' % v, body)); occ = len(re.findall(r'\b%s\b' % v, body))
            decl = len(re.findall(r'(?m)^\s*(?:double|float)\s+%s;' % v, body))
            if occ - asg - decl > 0 and asg == 0: bad.append((name, v, occ - asg - decl))
for n, v, k in bad: print('%s\t%s\t%d' % (n, v, k))
print('%d unassigned reads in %d functions' % (len(bad), len({n for n, _, _ in bad})), file=sys.stderr)
