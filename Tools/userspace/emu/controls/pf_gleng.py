import sys, pickle, os
os.environ['TD_ENTRYARGS']='1'
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
from unicorn import UC_HOOK_CODE
from unicorn.ppc_const import *
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/'); img='v20'
led=G+'/v17/ledger_i296a.tsv'
t._init(G+'/gleng_bins/GLEngine_stock', G+'/v17/GLEngine_rebuilt_i296a', G+'/v3/GLEngine_stock.syms', G+'/v17/GLEngine_rebuilt_i296a.nm', G+'/v17/ledger_i296a.tsv', K+'Userspace/GLEngine/ppc/ledger.tsv', G+'/gleng_nargs.tsv', 150, None)
row = t.load_row(led, sys.argv[2])
ia, da, sw, arena = pickle.load(open(sys.argv[1], 'rb'))
print('ia', [hex(x) for x in ia])
S, R = t._G['sims'][list(t._G['sims'])[0]]
for nm, sim, ent in (('stock', S, row['stock']), ('rebuilt', R, row['reb'])):
    def h(uc, a, s, ud, sim=sim, nm=nm):
        if (a - sim.slide) in sim.entries and sim.n > 1:
            r = [uc.reg_read(UC_PPC_REG_0 + i) for i in range(32)]
            print(nm, sim.entries[a - sim.slide], 'bc=%x' % int.from_bytes(uc.mem_read(uc.reg_read(UC_PPC_REG_1),4),'big'), 'lr=%x' % (uc.reg_read(UC_PPC_REG_LR) - sim.slide), 'r1=%x' % r[1], ' '.join('r%d=%x' % (i, r[i]) for i in range(3, 9)))
            for i in range(3, 9):
                if r[1] <= r[i] < sim.sp0:
                    print('    ptr r%d: ' % i, [hex(int.from_bytes(uc.mem_read(r[i] + 4 * k, 4), 'big')) for k in range(8)], 'written:', [all(b in sim.fwb for b in range(r[i] + 4 * k, r[i] + 4 * k + 4)) for k in range(8)])
    hk = sim.uc.hook_add(UC_HOOK_CODE, h)
    st, ev, regs, cov = sim.run(ent, ia, da, sw, arena); sim.uc.hook_del(hk)
    print(nm, st)
