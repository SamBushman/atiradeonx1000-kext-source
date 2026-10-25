#!/usr/bin/env python3
"""anchorfix_any.py (anchorfix.py that also matches rows keyed by the Ghidra FUN_<addr> name of a renamed function) DIR FN [FN ...] : turn the machine-written `#L` line anchors (L lines after the declaration block) of the `use` rows of FN into regex anchors over the
Ghidra text, so the rows survive new declarations being inserted by later rows (a `#L` anchor counts from the end of the declaration block and is shifted by every
`T x;` a split adds -> the second apply_names run fails).  Run it BEFORE adding rows that declare new names in FN; it reads the function from the committed tree (git HEAD),
so run it while the working tree still matches HEAD for FN."""
import re, sys, os, glob, subprocess, tempfile
D = sys.argv[1]; fns = set(sys.argv[2:])
root = subprocess.run(['git', 'rev-parse', '--show-toplevel'], capture_output=True, text=True).stdout.strip()
tmp = tempfile.mkdtemp()
subprocess.run('git -C %s archive HEAD %s | tar -x -C %s' % (root, D, tmp), shell=True, check=True)
HERE = os.path.dirname(os.path.abspath(__file__))
DECL = r'\s+(?!return\b)[\w ]+?[ *]([A-Za-z_]\w*)(\[\w+\])?;$'
parts = {}
for pf in sorted(glob.glob(os.path.join(tmp, D, 'part_*.c'))):
    parts[pf] = open(pf, errors='replace').read().split('\n')
def locate(fn):
    for pf, L in parts.items():
        for i, l in enumerate(L):
            m = re.match(r'^/\* (\S+) @ 0x', l)
            if m and m.group(1) == fn: return pf, L, i
    return None
changed = 0
for fn in fns:
    loc = locate(fn)
    if not loc: print('no function', fn); continue
    pf, cur, s = loc
    out = subprocess.run([sys.executable, os.path.join(HERE, 'orig.py'), D, fn], capture_output=True, text=True, cwd=tmp).stdout.split('\n')
    orig = {}
    for l in out:
        m = re.match(r'(\d+):(.*)$', l)
        if m: orig[int(m.group(1))] = m.group(2)
    brace = next(i for i in range(s, len(cur)) if cur[i] == '{')
    e = next((i for i in range(s + 1, len(cur)) if cur[i].startswith('/* ') and re.match(r'^/\* \S+ @ 0x', cur[i])), len(cur))
    i = brace + 1
    while i < len(cur) and (re.match(DECL, cur[i]) or not cur[i].strip() or re.match(r'\s*(/\*|\*)', cur[i])): i += 1
    d1 = i
    for t in sorted(glob.glob(os.path.join(D, 'names*.tsv'))):
        rows = open(t).read().split('\n'); ch = False
        for k, r in enumerate(rows):
            c = r.split('\t')
            if len(c) >= 8 and c[0] == 'use' and c[1] in (fn, 'FUN_%08x' % int(re.match(r'^/\* \S+ @ 0x([0-9a-f]+)', cur[s]).group(1), 16)) and re.fullmatch(r'#\d+', c[6]):
                a = d1 + int(c[6][1:])
                txt = orig[a + 1].strip()
                eq = [q for q in range(brace + 1, e) if orig.get(q + 1, '').strip() == txt]
                nth = eq.index(a) + 1
                c[6] = '^\\s*' + re.escape(txt) + '$' + ('@%d' % nth if nth > 1 else '')
                rows[k] = '\t'.join(c); ch = True; changed += 1
        if ch: open(t, 'w').write('\n'.join(rows))
print('converted', changed, 'rows')
