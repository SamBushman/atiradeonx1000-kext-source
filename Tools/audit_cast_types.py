#!/usr/bin/env python3
"""audit_cast_types.py - for every mechanical port that aliases a parameter as `UInt8 *param_N = (UInt8*)real_param_N`,
check the raw Ghidra decompile types that parameter as a multi-byte scalar pointer (int*, uint*, ...): then pointer
arithmetic/indexing in the body (`param_N[4]`, `param_N + 2`) would silently change scale (Ghidra scales by the pointee size)."""
import re, glob, os, sys
SCR = os.environ.get('SCRATCH', '/tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad')
bad = 0
for f in sorted(glob.glob('Sources/*_Port*.cpp')):
    s = open(f).read()
    for m in re.finditer(r'/\* real addr (0x[0-9a-f]+) \*/', s):
        a = m.group(1); raw = '%s/work/%s.txt' % (SCR, a)
        if not os.path.exists(raw): continue
        body_end = s.find('/* real addr', m.end()); body = s[m.end(): body_end if body_end > 0 else len(s)]
        casts = re.findall(r'UInt8 \*(param_\d+) = reinterpret_cast<UInt8 \*>\((?:real_param_\d+|this)\);', body)
        if not casts: continue
        rt = open(raw).read()
        # the real definition's parameter list: first `(` after the qualified name at a line start
        i = rt.find('\n{')
        head = rt[:i] if i > 0 else rt
        j = head.rfind('(', 0, len(head)); k = head.rfind('::')
        pl = head[head.find('(', k):]
        mm = re.match(r'\(([^)]*)\)', pl.replace('\n', ' '))
        if not mm: continue
        plist = mm.group(1).replace('\n', ' ')
        for p in casts:
            pm = re.search(r'([\w ]+?)\s*(\*+)\s*%s\b' % p, plist)
            if not pm: continue
            t = pm.group(1).strip()
            if t.split()[-1] in ('int', 'uint', 'ulong', 'short', 'ushort', 'long', 'undefined2', 'undefined4', 'undefined8', 'float', 'code', 'longlong', 'ulonglong') or t.endswith('*'):
                uses = len(re.findall(r'\b%s\s*(\[|\+ )' % p, body)) + len(re.findall(r'\*%s\b' % p, body))
                print('%-62s %s  %s %s*  (indexed/arith uses: %d)' % (f[8:], a, t, '*' * (len(pm.group(2)) - 1), uses)); bad += 1
print(bad, 'flagged')
