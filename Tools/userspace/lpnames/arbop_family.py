#!/usr/bin/env python3
"""arbop_family.py DIR OUTROWS FN...

arbEmitIl* functions (ARB program instruction -> IL token stream) take (ctx, dstFile, dstIndex, dstMask, srcKFile, srcKIndex, srcKSelect|Words, srcKNegate|Flags ...)
and build  token = (file & 0x3f) << 0x10 | index & 0xffff  plus a packed select/negate word per operand, then append the words to the token buffer.
Rules derived from the signature (position k of a pointer parameter <p>): a placeholder web defined as  param_k[c]  /  *param_k  is named <p><X|Y|Z|W>;
a web defined as (param_F & 0x3f) << 0x10 | param_I & 0xffff is <x>Token (x = the File parameter's prefix); the word appended right after a Token word
in the token-buffer store sequence is <x>Packed (dst: dstMaskWord).  Rows (use/local) are appended to OUTROWS."""
import sys, os, re, subprocess, tempfile, glob
here = os.path.dirname(os.path.abspath(__file__))
d, out = sys.argv[1:3]
H = re.compile(r'^/\* (\S+) @ 0x')
for fn in sys.argv[3:]:
    sig = None
    for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        t = open(pf, errors='replace').read()
        m = re.search(r'/\* %s @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\nint %s\(([^)]*)\)' % (fn, fn), t)
        if m: sig = [x.strip() for x in m.group(1).split(',')]; break
    if not sig: print(fn, 'no signature'); continue
    pos = {n: i + 1 for i, n in enumerate(sig)}      # position -> Ghidra name param_k
    rules = []; tok = {}
    for n, k in pos.items():
        if re.search(r'(Select|Negate|Words|Flags|Mask)$', n):
            for c, comp in enumerate('XYZW'):
                rx = (r'^\*param_%d;?$' % k) if c == 0 else (r'^param_%d\[%d\];?$' % (k, c))
                rules.append((n + comp, rx, 'component %d of the 4-word array parameter %s' % (c, n)))
        mm = re.match(r'(dst|src\d)File$', n)
        if mm:
            x = mm.group(1); fi = pos.get(x + 'Index')
            if fi: rules.append((x + 'Token', r'\(param_%d & 0x3f\) << 0x10 \| param_%d & 0xffff' % (k, fi), 'token word (file & 0x3f) << 16 | index & 0xffff of operand %s' % x))
    rf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False)
    for n, rx, ev in rules: rf.write('%s\t%s\t%s\n' % (n, rx, ev))
    rf.close()
    orig = subprocess.run([sys.executable, os.path.join(here, 'orig.py'), d, fn], capture_output=True, text=True).stdout
    # token-buffer store sequence
    seq = re.findall(r'ARB_tokenBuffer\)\) = (\w+);', orig)
    ph = subprocess.run([sys.executable, os.path.join(here, 'ph.py'), d, fn], capture_output=True, text=True).stdout
    vs = []; sys.stderr.write('PH %r\n' % ph[:80])
    for l in ph.splitlines():
        if l.startswith(fn + ':'): vs = [t.rsplit('*', 1)[0] for t in l.split(':', 1)[1].split()]
    spec = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); spec.close()
    for v in vs:
        if v.startswith('param_') or v.startswith('FUN_'): continue
        r = subprocess.run([sys.executable, os.path.join(here, 'classwebs.py'), d, fn, v, rf.name, spec.name], capture_output=True, text=True, env=dict(os.environ, CW_FIRSTDEF='1'))
        if os.environ.get('DBG') and v == 'uVar1': sys.stderr.write(r.stdout[:400] + r.stderr[-400:])
    er = subprocess.run([sys.executable, os.path.join(here, '..', 'emit_webs.py'), d, fn, spec.name], capture_output=True, text=True)
    rows = er.stdout.splitlines()
    if os.environ.get('DBG'): sys.stderr.write('SPEC %d lines; emit err %s\n' % (len(open(spec.name).read().splitlines()), er.stderr[-200:]))
    # which variable became which token?
    tokvar = {}
    for line in open(spec.name):
        c = line.rstrip('\n').split('\t')
        if len(c) > 2 and c[2].endswith('Token'): tokvar[c[0]] = c[2][:-5]
    packed = {}
    for i, v in enumerate(seq[:-1]):
        if v in tokvar and seq[i + 1] not in tokvar and seq[i + 1] in vs:
            x = tokvar[v]; packed[seq[i + 1]] = 'dstMaskWord' if x == 'dst' else x + 'Packed'
    extra = ['local\t%s\t%s\t%s\tINFERRED\tpacked select/negate word appended right after the %s token in the token buffer' % (fn, v, n, n[:-6] if n.endswith('Packed') else 'dst') for v, n in packed.items()]
    names = set(); keep = []
    for r in rows + extra:
        c = r.split('\t'); nm = c[3]
        # one name per original variable only
        keep.append(r)
    open(out, 'a').write('\n'.join(keep) + '\n')
    print(fn, 'rows', len(keep), 'tokvars', tokvar, 'packed', packed)
