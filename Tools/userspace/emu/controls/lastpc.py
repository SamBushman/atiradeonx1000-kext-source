import sys, pickle, os, struct, collections
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
from unicorn import UC_HOOK_CODE
from unicorn.ppc_const import *
from capstone import *
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/'); img='v20'
led=G+'/'+img+'/ledger_emu_gld.tsv'
t._init(G+'/stockbins/gld_ATIRadeonX1000GLDriver', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed', K+'Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed.nm', led, K+'Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv', G+'/gld_nargs.tsv', 150, None)
row = t.load_row(led, sys.argv[2])
ia, da, sw, arena = pickle.load(open(sys.argv[1], 'rb'))
print(list(t._G['sims'])); S, R = t._G['sims'][list(t._G['sims'])[0]]
for nm, sim, ent in (('stock', S, row['stock']), ('rebuilt', R, row['reb'])):
    last = collections.deque(maxlen=14)
    def h(uc, a, s, ud, last=last, sim=sim):
        last.append((a - sim.slide, bytes(uc.mem_read(a, 4)), [uc.reg_read(r) for r in (UC_PPC_REG_0, UC_PPC_REG_2, UC_PPC_REG_3, UC_PPC_REG_9, UC_PPC_REG_10, UC_PPC_REG_11)]))
    hk = sim.uc.hook_add(UC_HOOK_CODE, h)
    st, ev, regs, cov = sim.run(ent, ia, da, sw, arena); sim.uc.hook_del(hk)
    print(nm, st, ev[-1])
    for a, w, r in last:
        i = list(md.disasm(w, a)); print('   %x %-26s r0=%x r2=%x r3=%x r9=%x r10=%x r11=%x' % ((a,) + ((i[0].mnemonic + ' ' + i[0].op_str) if i else '?',) + tuple(r)))
