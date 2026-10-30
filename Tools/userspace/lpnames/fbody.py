#!/usr/bin/env python3
"""fbody.py DIR FN... : compact view -- signature, body lines (declarations dropped) with part-file line numbers, and the PLAIN webs (var wN lines a-b: first def) of each function"""
import sys, os, re, glob, subprocess
d = sys.argv[1]
S = os.path.dirname(os.path.abspath(__file__))
for fn in sys.argv[2:]:
    out = subprocess.run([sys.executable, os.path.join(S, 'fshow.py'), d, fn], capture_output=True, text=True).stdout.split('\n')
    print('=' * 8, fn)
    infn = False; ind = 0
    for l in out:
        m = re.match(r'^(\d+):(.*)$', l)
        if not m: continue
        t = m.group(2)
        if re.match(r'^  (unsigned int ghidra_home|\S[^=(]*;)\s*(/\*.*)?$', t) and not re.search(r'[=(]', t): continue
        if re.match(r'^  [A-Za-z_][\w \*]*\s+\**\w+(\s*\[[^\]]*\])?;$', t): continue
        if t.strip() == '': continue
        print('%s:%s' % (m.group(1), t[:170]))
    lw = subprocess.run([sys.executable, os.path.join(S, 'lw2.py'), d, fn], capture_output=True, text=True).stdout.split('\n')
    v = None
    for l in lw:
        if l.startswith('== '): v = l[3:].split(':')[0]; continue
        if 'PLAIN' in l and not re.search(r'lines (\d+)-\1 PLAIN', l): print('   PLAIN %s %s' % (v, l.strip()[:110]))
