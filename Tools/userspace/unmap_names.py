#!/usr/bin/env python3
"""unmap_names.py MAP FILE... - rewrite FILE in place, replacing every function name of MAP (`new<TAB>old` lines, see funcmap.py) by its old name.
Works on `gcc -S` text and gcc diagnostics: a name may appear bare, with the C leading underscore (`_new`) or as a stub label (`L_new$stub`, `L_new$non_lazy_ptr`)."""
import re, sys
TOKEN = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')
m = dict(l.rstrip('\n').split('\t') for l in open(sys.argv[1]) if '\t' in l)


def sub(t):
    t = t.group(0)
    if t in m: return m[t]
    if t[:1] == '_' and t[1:] in m: return '_' + m[t[1:]]
    if t[:2] == 'L_' and t[2:] in m: return 'L_' + m[t[2:]]
    return t


for f in sys.argv[2:]:
    s = open(f, errors='surrogateescape').read()
    open(f, 'w', errors='surrogateescape').write(TOKEN.sub(sub, s))
