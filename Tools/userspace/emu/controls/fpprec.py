import sys, os, re, collections, struct
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
from capstone import *
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN); md.skipdata = True
stock, reb, ledger, nm = sys.argv[1:5]
SINGLE = {'fadds','fsubs','fmuls','fdivs','fmadds','fmsubs','fnmadds','fnmsubs','fsqrts','fres'}
DOUBLE = {'fadd','fsub','fmul','fdiv','fmadd','fmsub','fnmadd','fnmsub','fsqrt'}
def load(path):
    im = t.Img(path); return im
S = load(stock); R = load(reb)
def code(im, a, n):
    for nm_, vm, vs, b in im.segs:
        if vm <= a < vm + len(b): return b[a - vm:a - vm + n]
def counts(im, a, n):
    c = collections.Counter()
    for i in md.disasm(code(im, a, n) or b'', a):
        if i.mnemonic in SINGLE: c['s'] += 1
        elif i.mnemonic in DOUBLE: c['d'] += 1
        elif i.mnemonic == 'frsp': c['r'] += 1
    return c
syms = []
for l in open(nm):
    p = l.split()
    if len(p) == 3 and re.match('[0-9a-f]{8}$', p[0]) and p[1] in 'tT': syms.append((int(p[0], 16) - R.bal, p[2]))
syms.sort(); addrs = [a for a, n in syms]
import bisect
def rsize(a):
    i = bisect.bisect_right(addrs, a); return (addrs[i] - a) if i < len(addrs) else 0x400
rows = []
for l in open(ledger):
    if l.startswith('#'): continue
    p = l.rstrip('\n').split('\t')
    if len(p) < 6: continue
    sa, ra, sz = int(p[2], 16), int(p[3], 16), int(p[4])
    cs = counts(S, sa, sz); cr = counts(R, ra, min(rsize(ra), 8 * sz + 64))
    rows.append((p[1], cs, cr))
bad = [(n, cs, cr) for n, cs, cr in rows if cs['s'] != cr['s'] or cs['d'] != cr['d']]
print(len(rows), 'functions;', len(bad), 'with a different single/double FP arithmetic count')
for n, cs, cr in bad: print('%-50s stock s=%d d=%d | rebuilt s=%d d=%d' % (n, cs['s'], cs['d'], cr['s'], cr['d']))
