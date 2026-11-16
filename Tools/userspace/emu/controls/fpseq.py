import sys, os, re, bisect
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
from capstone import *
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN); md.skipdata = True
stock, reb, ledger, nm = sys.argv[1:5]
S = t.Img(stock); R = t.Img(reb)
syms = []
for l in open(nm):
    p = l.split()
    if len(p) == 3 and re.match('[0-9a-f]{8}$', p[0]) and p[1] in 'tT': syms.append((int(p[0], 16) - R.bal, p[2]))
syms.sort(); addrs = [a for a, n in syms]
def rsize(a):
    i = bisect.bisect_right(addrs, a); return (addrs[i] - a) if i < len(addrs) else 0x400
def code(im, a, n):
    for nm_, vm, vs, b in im.segs:
        if vm <= a < vm + len(b): return b[a - vm:a - vm + n]
FP = re.compile(r'^(f[a-z]+s?|lfs|lfd|stfs|stfd|lfsx|lfdx|frsp)$')
def seq(im, a, n): return [i.mnemonic for i in md.disasm(code(im, a, n) or b'', a) if i.mnemonic.startswith('f') or i.mnemonic in ('lfs','lfd','stfs','stfd','lfsx','lfdx','stfsx','stfdx')]
want = set(sys.argv[5:])
for l in open(ledger):
    p = l.rstrip('\n').split('\t')
    if len(p) < 6 or p[1] not in want: continue
    sa, ra, sz = int(p[2], 16), int(p[3], 16), int(p[4])
    print(p[1], 'stock %x rebuilt %x size %d rsize %d' % (sa, ra, sz, rsize(ra)))
    print('  S', ' '.join(seq(S, sa, sz))); print('  R', ' '.join(seq(R, ra, min(rsize(ra), 8 * sz + 64))))
