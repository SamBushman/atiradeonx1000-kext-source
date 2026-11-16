import sys, pickle, os, collections
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.ppc_const import *
from capstone import *
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/'); img='v20'
led=G+'/'+img+'/ledger_emu_gld.tsv'
t._init(G+'/stockbins/gld_ATIRadeonX1000GLDriver', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed', K+'Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed.nm', led, K+'Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv', G+'/gld_nargs.tsv', 150, None)
row = t.load_row(led, sys.argv[2]); target = int(sys.argv[3]); N = int(sys.argv[4]) if len(sys.argv) > 4 else 30
ia, da, sw, arena = pickle.load(open(sys.argv[1], 'rb'))
S, R = t._G['sims'][list(t._G['sims'])[0]]
for nm, sim, ent in (('stock', S, row['stock']), ('rebuilt', R, row['reb'])):
    last = collections.deque(maxlen=N); dump = []
    def h(uc, a, s, ud, last=last, sim=sim):
        last.append((a - sim.slide, bytes(uc.mem_read(a, 4)), [uc.reg_read(r) for r in range(UC_PPC_REG_0, UC_PPC_REG_0 + 32)]))
    def w(uc, acc, a, sz, val, ud, last=last, dump=dump):
        if a == target + 0 and not dump: dump.extend(last)
    hk = sim.uc.hook_add(UC_HOOK_CODE, h); hw = sim.uc.hook_add(UC_HOOK_MEM_WRITE, w)
    st, ev, regs, cov = sim.run(ent, ia, da, sw, arena); sim.uc.hook_del(hk); sim.uc.hook_del(hw)
    print(nm, st)
    for a, wd, r in dump:
        i = list(md.disasm(wd, a)); print('   %x %-26s' % (a, (i[0].mnemonic + ' ' + i[0].op_str) if i else '?'), ' '.join('r%d=%x' % (k, r[k]) for k in (0,3,4,5,6,7,8,9,10,11,12)))
