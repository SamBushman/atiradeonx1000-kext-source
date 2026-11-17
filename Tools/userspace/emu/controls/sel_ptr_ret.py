"""sel_ptr_ret.py NAME [P1LIST P2LIST] - GLEngine functions that RETURN a pointer-table value (a function address, which differs per image):
run both images over a grid of two integer arguments and compare the NAME of the function each returned address belongs to (nearest preceding symbol).
Default grid: the GL pixel formats x types of _gleSelectPixelExtractFunc. Paths point at the session's scratch layout (v17 image i296a)."""
import sys, os, bisect
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/'); V=G+'/v17'
IMG = os.environ.get('IMG', 'GLEngine_rebuilt_i296a'); LED = os.environ.get('LED', V + '/ledger_i296a.tsv')
t._init(G+'/gleng_bins/GLEngine_stock', V+'/'+IMG, G+'/v3/GLEngine_stock.syms', V+'/'+IMG+'.nm', LED, K+'Userspace/GLEngine/ppc/ledger.tsv', G+'/gleng_nargs.tsv', 150, None)
S, R = t._G['sims'][list(t._G['sims'])[0]]
name = sys.argv[1]
row = t.load_row(LED, name)
def table(sim):
    m = []
    if sim is S:
        for l in open(K + 'Userspace/GLEngine/ppc/ledger.tsv'):
            p = l.rstrip('\n').split('\t')
            if len(p) >= 3 and p[0].startswith('0x'): m.append((int(p[0], 16), p[2]))
    else:
        for l in open(V + '/' + IMG + '.nm'):
            p = l.split()
            if len(p) == 3 and p[1] in 'tT': m.append((int(p[0], 16), p[2]))
    m.sort()
    return [a for a, _ in m], [n for _, n in m]
def sym(sim, tab, v):
    a = v - sim.slide
    i = bisect.bisect_right(tab[0], a) - 1
    return (tab[1][i], a - tab[0][i]) if i >= 0 else ('?', a)
tS, tR = table(S), table(R)
fmts = [0x1900 + i for i in range(0, 16)] + [0x80e0, 0x80e1, 0x8032, 0x8033, 0x8034, 0x8035, 0x8036, 0x8362, 0x8363, 0x1ff, 0, 1]
typs = [0x1400 + i for i in range(0, 12)] + [0x8032, 0x8033, 0x8034, 0x8035, 0x8036, 0x8362, 0x8363, 0x8364, 0x8365, 0x8366, 0x8367, 0x8368, 0, 1]
if len(sys.argv) > 3: fmts = [int(x, 0) for x in sys.argv[2].split(',')]; typs = [int(x, 0) for x in sys.argv[3].split(',')]
arena = bytes(t.ARENA_SIZE); bad = 0; n = 0; seen = {}
for p1 in fmts:
    for p2 in typs:
        ia = [p1, p2] + [0] * 6
        a = S.run(row['stock'], ia, [0] * 13, [0] * 16, arena); b = R.run(row['reb'], ia, [0] * 13, [0] * 16, arena)
        n += 1
        if a[0] != b[0]: bad += 1; print('STATUS differs', hex(p1), hex(p2), a[0], b[0]); continue
        if a[0] != 'RET': continue
        ra, rb = a[2]['r3'], b[2]['r3']
        sa, sb = (sym(S, tS, ra) if ra else ('0', 0)), (sym(R, tR, rb) if rb else ('0', 0))
        seen[sa[0]] = seen.get(sa[0], 0) + 1
        if sa != sb: bad += 1; print('DIFF', hex(p1), hex(p2), sa, sb)
print('%d combinations, %d differ; distinct returned functions %d: %s' % (n, bad, len(seen), sorted(seen)[:60]))
