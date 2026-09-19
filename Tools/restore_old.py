#!/usr/bin/env python3
"""restore_old.py PORT_FILE... - undo replace_fn.py for the named Sources/*_Port*.cpp files: put the previous (committed, hand-verified) body back
where replace_fn left its `(re-ported mechanically: see X_Port.cpp)` marker, and delete the port file. For functions whose Ghidra decompile is degenerate
(tail-forwarders whose register arguments the decompiler dropped)."""
import sys, re, subprocess, os
def brace_end(s, i):
    d = 0; k = s.index('{', i)
    while True:
        if s[k] == '{': d += 1
        elif s[k] == '}':
            d -= 1
            if d == 0: return k
        k += 1
for pf in sys.argv[1:]:
    pf = os.path.basename(pf); marker = '/* (re-ported mechanically: see %s) */' % pf
    files = subprocess.run(['git', 'grep', '-l', '-F', marker, 'HEAD', '--', 'Sources'], capture_output=True, text=True).stdout.split()
    cur = [f for f in os.listdir('Sources') if marker in open('Sources/' + f).read()]
    if len(cur) != 1: print('SKIP', pf, 'marker found in', cur); continue
    f = 'Sources/' + cur[0]; s = open(f).read()
    m = re.match(r'^(.*)_Port(?:_[0-9a-f]+)?\.cpp$', pf); base = m.group(1)
    # the committed version of the old file: find the definition whose Class::name matches the port file's Class_name
    old = subprocess.run(['git', 'show', 'HEAD:' + f], capture_output=True, text=True).stdout
    cls, _, name = base.partition('_')
    pat = re.compile(r'(?m)^(?:[\w:<>\*&\s]+?[\s\*&])?%s::%s\s*\(' % (re.escape(cls), re.escape(name)))
    ms = list(pat.finditer(old))
    if len(ms) != 1: 
        # free functions / operators: try the bare name
        pat2 = re.compile(r'(?m)^(?:extern "C"\s+)?[\w:<>\*&\s]+?[\s\*&]%s\s*\(' % re.escape(base)); ms = list(pat2.finditer(old))
    if len(ms) != 1: print('SKIP', pf, 'old definition matches', len(ms)); continue
    st = ms[0].start(); en = brace_end(old, st) + 1
    # include a directly preceding /* ... */ comment block
    pre = old.rfind('*/', 0, st)
    if pre >= 0 and old[pre + 2:st].strip() == '':
        b = old.rfind('/*', 0, pre)
        if b >= 0: st = b
    body = old[st:en]
    open(f, 'w').write(s.replace(marker, body))
    os.remove('Sources/' + pf); print('restored', pf, '->', f)
