import sys, os, struct
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
G='/home/sam/g5logs/fnf_237'; K=os.path.expanduser('~/atiradeonx1000-kext-source/')
img=sys.argv[1]
t._init(G+'/stockbins/gld_ATIRadeonX1000GLDriver', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed', K+'Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv', G+'/'+img+'/ATIRadeonX1000GLDriver_renamed.nm', G+'/'+img+'/ledger_emu_gld.tsv', K+'Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv', G+'/gld_nargs.tsv', 150, None)
row = t.load_row(G+'/'+img+'/ledger_emu_gld.tsv', 'gld_quantizePointSizeInt')
S, R = t._G['sims'][list(t._G['sims'])[0]]
for v in (-33554432.0, 33554432.0, 8388609.0, 16777215.0, -16777217.0, 100.0, 0.25):
    arena = bytearray(t.ARENA_SIZE)
    ctx = 0x2000
    struct.pack_into('>i', arena, ctx+0x13e0, -2**31); struct.pack_into('>i', arena, ctx+0x13e4, 2**31-1)
    ia=[t.ARENA+ctx]+[0]*7; da=[struct.unpack('>Q', struct.pack('>d', v))[0]]+[0]*12; sw=[0]*16
    out=[]
    for sim, ent in ((S,row['stock']),(R,row['reb'])):
        st, ev, regs, cov = sim.run(ent, ia, da, sw, bytes(arena))
        out.append((st, regs.get('r3') if isinstance(regs, dict) else regs))
    print(v, out)
