#!/usr/bin/env python3
"""patch_sites.py - issue #71 criterion 3: run patch_sites_test on the stock and the rebuilt libGLProgrammability / GLDriver (on the G5, over ssh) and diff the outputs.
  patch_sites.py NM_STOCK_GLPROG NM_REB_GLPROG NM_STOCK_GLD NM_REB_GLD REB_GLPROG REB_GLD   (nm files are local; the test binary must exist in $G/tests on the G5)"""
import sys, re, subprocess
G = '/Volumes/Test HD/claude_bugwf'
SYS = '/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLProgrammability.dylib'
GLD = '/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver'
def nm(p):
    d = {}
    for l in open(p):
        m = re.match(r'([0-9a-f]{8}) \w (\S+)', l)
        if m: d.setdefault(m.group(2), int(m.group(1), 16))
    return d
def keys(n, anchor, table):
    out = []
    for k, cands in table.items():
        a = next((n[c] for c in cands if c in n), None)
        if a is not None: out.append('%s=%d' % (k, a - n[anchor]))
        else: print('missing', k, cands)
    return out
GP = {'yfa': ['__Z13yy_flex_allocj'], 'yfr': ['__Z15yy_flex_reallocPvj'], 'yff': ['__Z12yy_flex_freePv'], 'ung': ['_str_ungetch'], 'unl': ['_unlinkScope'], 'cppv': ['_cpp'], 'scopev': ['_ScopeList'],
      'dcba': ['_glpDCBAlloc'], 'dcbr': ['_glpDCBRealloc'], 'dcbf': ['_glpDCBFree'], 'trav': ['__ZN13TIntermSymbol8traverseEP16TIntermTraverser']}
GD = {'cal': ['FUN_000a6f70'], 'cos': ['FUN_001d05b0'], 'sin': ['FUN_001d0794'], 'rsq': ['FUN_001d06ec']}
sp, rp, sd, rd, rgp, rgd = sys.argv[1:7]
def run(image, anchor, ks):
    r = subprocess.run(['ssh', 'G5', 'cd "%s/tests" && ./patch_sites_test "%s" %s %s 2>&1' % (G, image, anchor, ' '.join(ks))], capture_output=True, text=True); return r.stdout
res = {}
nsp, nrp, nsd, nrd = nm(sp), nm(rp), nm(sd), nm(rd)
# stock nm lacks some local symbols: the stock addresses are taken from the ledger names known from the corpus
for k, v in {'_str_ungetch': 0x97b88a8c, '_unlinkScope': 0x97b89f00, '__ZN13TIntermSymbol8traverseEP16TIntermTraverser': 0x97b97d40}.items(): nsp.setdefault(k, v)
for k, v in {'FUN_000a6f70': 0xa6f70, 'FUN_001d05b0': 0x1d05b0, 'FUN_001d0794': 0x1d0794, 'FUN_001d06ec': 0x1d06ec}.items(): nsd.setdefault(k, v)
out = {}
out['glprog stock'] = run(SYS, 'glpDCBAlloc', keys(nsp, '_glpDCBAlloc', GP)); out['glprog rebuilt'] = run(rgp, 'glpDCBAlloc', keys(nrp, '_glpDCBAlloc', GP))
out['gld stock'] = run(GLD, 'gldGetString', keys(nsd, '_gldGetString', GD)); out['gld rebuilt'] = run(rgd, 'gldGetString', keys(nrd, '_gldGetString', GD))
bad = 0
for k in ('glprog', 'gld'):
    a, b = out[k + ' stock'], out[k + ' rebuilt']
    print('== %s: %d lines, %s' % (k, len(a.splitlines()), 'IDENTICAL' if a == b else 'DIFFERENT'))
    if a != b:
        bad += 1
        for x, y in zip(a.splitlines(), b.splitlines()):
            if x != y: print('  stock  ', x); print('  rebuilt', y)
    else: print(a)
print('RESULT:', 'PASS' if not bad else 'FAIL')
