import sys, os
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/'); img='v20'
led=G+'/'+img+'/ledger_emu_gld.tsv'
t._init(G+'/stockbins/gld_ATIRadeonX1000GLDriver', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed', K+'Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed.nm', led, K+'Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv', G+'/gld_nargs.tsv', 150, None)
S, R = t._G['sims']['A']; ar = bytes(t.ARENA_SIZE)
def cstr(sim, a):
    try: return bytes(sim.uc.mem_read(a, 80)).split(b'\0')[0]
    except Exception: return None
for name in sys.argv[1:]:
    row = t.load_row(led, name); bad = 0; n = 0; first = None; samples = []
    for k in range(-2, 300):
        res = []
        for sim, ent in ((S, row['stock']), (R, row['reb'])):
            st, ev, regs, cov = sim.run(ent, [k, 0, 0, 0], [], [], ar); r3 = regs['r3']
            res.append((st, cstr(sim, r3) if st == 'RET' and r3 > 0x1000 else None, r3 if st != 'RET' or r3 <= 0x1000 else None))
        n += 1
        if len(samples) < 6 and res[0][0]=='RET': samples.append((k, res[0][1]))
        if res[0][:2] != res[1][:2] or (res[0][1] is None and res[0][2] != res[1][2]): bad += 1; first = first or (k, res)
    print(name, 'pc', row['pc'], 'inputs', n, 'differ', bad, first, 'samples', samples)
