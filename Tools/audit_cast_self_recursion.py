#!/usr/bin/env python3
"""audit_cast_self_recursion.py - source audit for the #155/#177/#178 bug class.

Under -fapple-kext a call written `((IOATIR500X *)self)->method(...)` is a VIRTUAL call. Inside a derived class `ATIR500X` that also overrides `method`, it dispatches back to the
derived override (unbounded recursion if it is the same function, the wrong body otherwise); the shipped kext calls the base body directly. The fix is the qualified form
`IOATIR500X::method(...)`. Run from the repo root: `python3 -I Tools/audit_cast_self_recursion.py`; exit status 1 if any hit remains (for build_kext.sh / CI)."""
import re, glob, sys
pairs = {'ATIR500DVDContext': 'IOATIR500DVDContext', 'ATIR500GLContext': 'IOATIR500GLContext', 'ATIR5002DContext': 'IOATIR5002DContext',
         'ATIR500Surface': 'IOATIR500Surface', 'ATIRadeonX1000': 'IOATIR500Accelerator'}
decl = {d: set(re.findall(r'virtual\s+[\w\s\*:<>,&]*?\b(\w+)\s*\(', open('Headers/%s.h' % d, errors='replace').read())) for d in pairs}
bad = []
for f in sorted(glob.glob('Sources/*.cpp')):
    s = open(f, errors='replace').read()
    s = re.sub(r'/\*.*?\*/', lambda m: re.sub(r'[^\n]', ' ', m.group(0)), s, flags=re.S)   # comments may quote the bad form
    s = re.sub(r'//[^\n]*', '', s)
    for d, b in pairs.items():
        for m in re.finditer(r'\(\(\s*' + b + r'\s*\*\s*\)[^;]*?\)->(\w+)\s*\(', s):
            if m.group(1) in decl[d]:
                bad.append((f, s.count('\n', 0, m.start()) + 1, b, m.group(1)))
for x in bad: print('%s:%d: ((%s *)..)->%s(...) is a virtual call to an overridden method; use %s::%s(...)' % (x[0], x[1], x[2], x[3], x[2], x[3]))
print(len(bad), 'hit(s)')
sys.exit(1 if bad else 0)
