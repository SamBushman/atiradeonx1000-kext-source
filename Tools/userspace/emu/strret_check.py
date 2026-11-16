# Compare what a function returns by ADDRESS (a string/table in the image: every trial is layout-dependent in census_summary) by CONTENT: a C string for k in -2..299, or the first bytes of the returned table.
# usage: PYTHONPATH=Tools/userspace/emu python3 strret_check.py NAME...   (paths below are the Nov 15-16 session directories; edit G/V)
import sys, trace_diff as t
G='/home/sam/g5logs/fnf_237'; V=G+'/v11'
t._init(G+'/v6/glprog_stock', V+'/glprog_rebuilt', G+'/v9/glprog_link/symbol_map.tsv', V+'/glprog_rebuilt.nm', V+'/ledger_emu.tsv', 'Userspace/libGLProgrammability/ppc/ledger.tsv', G+'/v6/glprog_nargs_all.tsv', 0, None)
S, R = t._G['sims']['A']
ar = bytes(t.ARENA_SIZE)
def cstr(sim, a):
    try: return bytes(sim.uc.mem_read(a, 80)).split(b'\0')[0]
    except Exception: return None
for name in sys.argv[1:]:
    row = t.load_row(V + '/ledger_emu.tsv', name); bad = 0; n = 0; first = None
    for k in range(-2, 300):
        res = []
        for sim, ent in ((S, row['stock']), (R, row['reb'])):
            st, ev, regs, cov = sim.run(ent, [k, 0, 0, 0], [], [], ar)
            r3 = regs['r3']; res.append((st, cstr(sim, r3) if st == 'RET' and r3 > 0x1000 else None, r3 if st != 'RET' or r3 <= 0x1000 else None))
        n += 1
        if res[0][:2] != res[1][:2] or (res[0][1] is None and res[0][2] != res[1][2]): bad += 1; first = first or (k, res)
    print(name, 'pc', row['pc'], 'inputs', n, 'differ', bad, first)
    ex = []
    for k in range(0, 12):
        st, ev, regs, cov = S.run(row['stock'], [k, 0, 0, 0], [], [], ar); ex.append(cstr(S, regs['r3']))
    print('  stock samples', ex[:6])
print('--- full content')
import struct
for name in ('GetPreprocessorBuiltinString','GetResources'):
    row = t.load_row(V + '/ledger_emu.tsv', name); out = []
    for sim, ent in ((S, row['stock']), (R, row['reb'])):
        st, ev, regs, cov = sim.run(ent, [0, 0, 0, 0], [], [], ar); a = regs['r3']
        b = bytes(sim.uc.mem_read(a, 128 if name == "GetResources" else 2000)); out.append((st, b if name == 'GetResources' else b.split(b'\0')[0], regs['r3']))
    print(name, 'status', out[0][0], out[1][0], 'len', len(out[0][1]), len(out[1][1]), 'equal', out[0][1] == out[1][1])
    if name == 'GetResources': print('  r3 stock/rebuilt', hex(out[0][2]), hex(out[1][2]), 'first 128 B', out[0][1][:128].hex())
