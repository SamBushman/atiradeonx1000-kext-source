import sys, pickle, os
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/'); img='v22'
led=G+'/'+img+'/ledger_emu_gld.tsv'
t._init(G+'/stockbins/gld_ATIRadeonX1000GLDriver', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed', K+'Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed.nm', led, K+'Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv', G+'/gld_nargs.tsv', 150, None)
row = t.load_row(led, sys.argv[2])
ia, da, sw, arena = pickle.load(open(sys.argv[1], 'rb'))
S, R = t._G['sims']['A'][0], t._G['sims']['A'][1]
a = S.run(row['stock'], ia, da, sw, arena); b = R.run(row['reb'], ia, da, sw, arena)
print(sys.argv[2], 'stock', a[0], len(a[1]), 'rebuilt', b[0], len(b[1]), 'compare', t.compare(a, b, row['rc'])[:2])
