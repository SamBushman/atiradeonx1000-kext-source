import sys, os, struct
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
from unicorn import UC_HOOK_CODE
from unicorn.ppc_const import *
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/')
img=sys.argv[1]; led=G+'/'+img+'/ledger_emu_gld.tsv'
t._init(G+'/stockbins/gld_ATIRadeonX1000GLDriver', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed', K+'Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed.nm', led, K+'Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv', G+'/gld_nargs.tsv', 150, None)
S, R = t._G['sims'][list(t._G['sims'])[0]]
for name in sys.argv[2:]:
    row = t.load_row(led, name)
    arena = bytearray(t.ARENA_SIZE)
    C, SW, P = 0x2000, 0x2100, 0x3000
    for i in range(4): struct.pack_into('>I', arena, C+4*i, 0x3f800000)
    struct.pack_into('>I', arena, SW, 0x00010203)
    ia=[t.ARENA+0x100, t.ARENA+P, t.ARENA+C, t.ARENA+SW]+[0]*4; da=[0]*13; sw=[0]*16
    res=[]
    crow = t.load_row(led, 'Program__findOrCreateConstInst')
    for nm_, sim, ent, cent in (('stock',S,row['stock'],crow['stock']),('rebuilt',R,row['reb'],crow['reb'])):
        got = []
        def h(uc, a, sz, ud, got=got, sim=sim, cent=cent):
            if a - sim.slide == cent and not got:
                r4 = uc.reg_read(UC_PPC_REG_4); r5 = uc.reg_read(UC_PPC_REG_5)
                got.append((r5, bytes(uc.mem_read(r4, 16)).hex()))
        hk = sim.uc.hook_add(UC_HOOK_CODE, h)
        st, ev, regs, cov = sim.run(ent, ia, da, sw, bytes(arena)); sim.uc.hook_del(hk)
        res.append((st, ev)); print('  ', nm_, 'callee findOrCreateConstInst args(r5, vec16):', [(hex(x[0]), x[1]) for x in got])
    print(name, 'stock', res[0][0], len(res[0][1]), 'rebuilt', res[1][0], len(res[1][1]))
    for (a,b) in zip(res[0][1], res[1][1]):
        if a!=b: print('  first diff:', a, '|', b); break
    else: print('  events equal prefix; lens', len(res[0][1]), len(res[1][1]))
