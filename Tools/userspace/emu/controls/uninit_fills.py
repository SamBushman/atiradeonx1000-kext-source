import sys, pickle, os
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/'); img='v20'
led=G+'/'+img+'/ledger_emu_gld.tsv'
t._init(G+'/stockbins/gld_ATIRadeonX1000GLDriver', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed', K+'Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed.nm', led, K+'Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv', G+'/gld_nargs.tsv', 150, None)
row = t.load_row(led, sys.argv[2])
ia, da, sw, arena = pickle.load(open(sys.argv[1], 'rb'))
(ssA, srA), (ssB, srB) = t._G['sims']['A'], t._G['sims']['B']
bA = srA.run(row['reb'], ia, da, sw, arena); bB = srB.run(row['reb'], ia, da, sw, arena)
print(bA[0], bB[0], len(bA[1]), len(bB[1]), 'same_run', t.same_run(bA,bB), 'compare', t.compare(bA,bB,row['rc'])[:2])
for k,(x,y) in enumerate(zip(bA[1],bB[1])):
    if x!=y: print(k,x,'|',y)
import inspect; print(inspect.getsource(t.same_run))
