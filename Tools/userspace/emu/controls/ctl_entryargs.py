import sys, os, struct
os.environ['TD_ENTRYARGS']='1'
sys.path.insert(0, os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace/emu'))
import trace_diff as t
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
    a = S.run(row['stock'], ia, da, sw, bytes(arena)); b = R.run(row['reb'], ia, da, sw, bytes(arena))
    print(name, a[0], b[0], 'ent S', a[2].get('ent'), 'R', b[2].get('ent'))
    print('  compare ->', t.compare(a, b, row.get('rc', 'v') if isinstance(row, dict) else 'v'))
