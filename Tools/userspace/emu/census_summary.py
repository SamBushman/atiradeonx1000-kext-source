#!/usr/bin/env python3
"""census_summary.py CENSUS.tsv - summarise a trace_diff.py census: rows per worst verdict, rows never reaching a normal return, coverage."""
import sys, collections
rows = []
for l in open(sys.argv[1]):
    if l.startswith('#'): continue
    p = l.rstrip('\n').split('\t')
    if len(p) < 20: continue
    rows.append(dict(id=p[0], name=p[1], rc=p[2], size=int(p[4]), scov=int(p[5]) if p[5].isdigit() else -1, rcov=int(p[6]) if p[6].isdigit() else -1, runs=int(p[7] or 0),
                     ident=int(p[8] or 0), reo=int(p[9] or 0), rset=int(p[10] or 0), fsite=int(p[11] or 0), fmis=int(p[12] or 0), eff=int(p[13] or 0), emu=int(p[14] or 0), tmo=int(p[15] or 0), ur=int(p[16] or 0), uo=int(p[17] or 0), states=p[18], first=p[19], lay=int(p[20]) if len(p) > 20 and p[20].isdigit() else 0, pvd=int(p[21]) if len(p) > 21 and p[21].isdigit() else 0, idd=int(p[22]) if len(p) > 22 and p[22].isdigit() else 0))
def worst(r):
    if r['runs'] == 0: return 'EXC'
    if r['ur']: return 'UNINIT_REBUILT'
    if r['eff']: return 'EFFECTS'
    if r['idd']: return 'IMAGE_DATA_DEP'
    if r['pvd']: return 'PTR_VALUE_DEP'
    if r['fmis']: return 'FAULT_MISMATCH'
    if r['rset']: return 'READ_SET'
    if r['fsite']: return 'FAULT_SITE'
    if r['reo']: return 'REORDERED'
    if r['lay'] == r['runs']: return 'LAYOUT_ALL'
    if r['emu'] == r['runs']: return 'EMUERR_ALL'
    if r['tmo'] == r['runs']: return 'TIMEOUT_ALL'
    return 'IDENTICAL'
# FAULT_MISMATCH rows resolved by hand from the disassembly of both images (EVIDENCE_trace_diff.md, "The 9 one-sided FAULT_MISMATCH rows", Nov 15):
# name -> (class, gate). Only applied while the row's worst verdict is FAULT_MISMATCH; a row that gets any worse verdict still reports it.
EXPLAINED = {'ffvpPrepareFogExp': ('STOCK_HOISTED_LOAD', 'PASS'), 'ffvpPrepareFogExp2': ('STOCK_HOISTED_LOAD', 'PASS'), 'ffvpPrepareFogLinear': ('STOCK_HOISTED_LOAD', 'PASS'),
             'R300MachineAssembler__vslot65_declareNodeRegisters': ('STOCK_DEAD_ARG_LOAD', 'PASS'), 'R520MachineAssembler__vslot65_declareNodeRegisters': ('STOCK_DEAD_ARG_LOAD', 'PASS'),
             'opcodeInfoRgbHwOpcode': ('OOB_TABLE_INDEX', 'OUT-OF-CONTRACT'), 'gld_applyAnisotropyOverride': ('OOB_TABLE_INDEX', 'OUT-OF-CONTRACT'),
             'IRInst__scaleByOutputScale': ('OOB_TABLE_INDEX', 'OUT-OF-CONTRACT'), 'Program__laneKindOfIlType': ('OOB_TABLE_INDEX', 'OUT-OF-CONTRACT'),
             'Program__assignOutputExportSlots': ('STOCK_BUG_284', 'PASS'), 'Program__assignSharedExportSlots': ('STOCK_BUG_284', 'PASS'),
             # GLEngine (Userspace/GLEngine/ppc/EVIDENCE_trace_diff.md, "The 8 one-sided FAULT_MISMATCH rows"): a load the stock performs early / unconditionally whose result the rebuilt reads later or not at all
             '_glActiveStencilFace_ListExec': ('STOCK_HOISTED_LOAD', 'PASS'), '_glSamplePass_ListExec': ('STOCK_HOISTED_LOAD', 'PASS'), '_glGetPixelMapuiv_Exec': ('STOCK_HOISTED_LOAD', 'PASS'),
             '_glGetPixelMapusv_Exec': ('STOCK_HOISTED_LOAD', 'PASS'), '_gleLookUpTexture1D': ('STOCK_HOISTED_LOAD', 'PASS'), '_gleLookUpTexture3D': ('STOCK_HOISTED_LOAD', 'PASS'),
             '_gleLookUpNonProxyTexture1D': ('STOCK_HOISTED_LOAD', 'PASS'), '_gleLookUpNonProxyTexture3D': ('STOCK_HOISTED_LOAD', 'PASS'),
             # libGLProgrammability extended census (EVIDENCE_trace_diff.md): #225 deliberate guard of a stock out-of-table write; a dead argument load of the stock (`lwz r0,0(r4); stw r0,-0x20(r1); blr`)
             'std____default_alloc_template_true_0____S_refill': ('STOCK_BUG_225', 'PASS'),
             '__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_': ('STOCK_DEAD_ARG_LOAD', 'PASS'),
             # GLDriver extended census (Nov 16): stock loads this+0xa4 and never uses it; the rebuilt inlined callees do not
             'R300MachineAssembler__classifyAluOperation': ('STOCK_DEAD_ARG_LOAD', 'PASS'),
             # pointer-repair census (Nov 16): stock loads `*(*(builder+0x3f0)+0xc)` (stock 0x9b4f8) before the `noLights` test although only the noLights == 0 path uses it; the rebuilt loads it in that path only (all 10 trials: stock fault pc 0x9b4f8, rebuilt returns)
             'ffvpEmitColorOutputs': ('STOCK_HOISTED_LOAD', 'PASS'),
             # the callee Program__assignOutputExportSlots: stock stores through the unchecked export-slot index into its 53-word frame table (stwx at stock 0x10fd44, all 6 trials), the rebuilt has the deliberate #284 guard
             'KhanVs__vslot88_assignOutputBindings': ('STOCK_BUG_284', 'PASS')}
# Rows resolved by hand whose worst verdict is not FAULT_MISMATCH: name -> (verdict it applies to, class, gate)
EXPLAINED_ANY = {'Compiler__getOrCreateLoadConstN': ('UNINIT_REBUILT', 'OOB_LOCAL_INDEX', 'OUT-OF-CONTRACT'),      # constCount > 4 indexes the 5-word local lookupKeyWords unchecked in both images (stock 0xf50dc-0xf50e8 `lwz r3,0x34(r1+4*n)`, rebuilt 0x1091d4-0x1091e0): decision 3
    '_PPCRuntimeCompilerGetOffsetInRegister': ('UNINIT_REBUILT', 'OOB_LOCAL_INDEX', 'OUT-OF-CONTRACT'),
    # extended glprog census, EVIDENCE_trace_diff.md: the random format pointer 0x20000000 is the START OF THE STOCK's __DATA segment (offset 0x10000000 from its text; the rebuilt image has __DATA right after its text), so only the stock can read the string; same _vsprintf buffer/format values in both calls
    # GLDriver extended census: documented deliberate #64 clamp of the ILReader opcode index
    'ILReader__currentOpcode': ('EFFECTS', 'DELIBERATE_64_CLAMP', 'PASS'),
    'TPPStreamCompiler__warning': ('EFFECTS', 'INPUT_IN_IMAGE_WINDOW', 'PASS'),
    # NO-INFO rows that return the address of an image-resident string/table (every trial layout-dependent): contents compared with Tools/userspace/emu/strret_check.py, EVIDENCE_trace_diff.md
    'GetPreprocessorBuiltinString': ('LAYOUT_ALL', 'RETURNS_IMAGE_CONTENT_VERIFIED', 'PASS'),
    'GetResources': ('LAYOUT_ALL', 'RETURNS_IMAGE_CONTENT_VERIFIED', 'PASS'),
    'GetGLStringForType': ('LAYOUT_ALL', 'RETURNS_IMAGE_CONTENT_VERIFIED', 'PASS'),
    'getQualifierString': ('LAYOUT_ALL', 'RETURNS_IMAGE_CONTENT_VERIFIED', 'PASS')}      # libGLProgrammability EVIDENCE_trace_diff.md: both images index a 0x24-byte local copy with an unchecked record field
def worst2(r):
    w = worst(r)
    if r['name'] in EXPLAINED_ANY and EXPLAINED_ANY[r['name']][0] == w: return EXPLAINED_ANY[r['name']][1]
    return EXPLAINED[r['name']][0] if w == 'FAULT_MISMATCH' and r['name'] in EXPLAINED else w
c = collections.Counter(worst2(r) for r in rows)
GATE = {'UNINIT_REBUILT': 'FAIL', 'EFFECTS': 'FAIL', 'HW_STREAM': 'FAIL', 'FAULT_MISMATCH': 'REVIEW', 'IMAGE_DATA_DEP': 'OUT-OF-CONTRACT', 'PTR_VALUE_DEP': 'OUT-OF-CONTRACT', 'LAYOUT_ALL': 'NO-INFO', 'EMUERR_ALL': 'NO-INFO', 'TIMEOUT_ALL': 'NO-INFO', 'EXC': 'NO-INFO'}
def gate(r):
    w = worst(r)
    if r['name'] in EXPLAINED_ANY and EXPLAINED_ANY[r['name']][0] == w: return EXPLAINED_ANY[r['name']][2]
    return EXPLAINED[r['name']][1] if w == 'FAULT_MISMATCH' and r['name'] in EXPLAINED else GATE.get(w, 'PASS')
g = collections.Counter(gate(r) for r in rows)
print('GATE (relaxed memory order, strict calls/returns/final stores/command ring; unchecked out-of-range table index = out of contract, user Nov 15): ' + ', '.join('%s %d' % kv for kv in sorted(g.items())))
print('%d rows; trials excluded as layout-dependent (the stock itself differs at a second slide): %d of %d' % (len(rows), sum(r['lay'] for r in rows), sum(r['runs'] for r in rows))); [print('  %-16s %d' % (k, v)) for k, v in sorted(c.items(), key=lambda x: -x[1])]
def normal(r): return any(s.split(':')[0] == 'RET/RET' for s in r['states'].split(','))
print('rows with at least one run where BOTH images returned normally: %d / %d' % (sum(1 for r in rows if normal(r)), len(rows)))
print('rows where no run returned normally in both (faults only): %d' % sum(1 for r in rows if not normal(r)))
print('rows whose rebuilt image covered fewer instructions of the function than the stock: %d; stock fewer: %d' % (sum(1 for r in rows if 0 <= r['rcov'] < r['scov']), sum(1 for r in rows if 0 <= r['scov'] < r['rcov'])))
if len(sys.argv) > 2:
    k = sys.argv[2]
    for r in rows:
        if worst2(r) == k: print('%s\t%s\t%s\t%s' % (r['id'], r['name'], r['states'], r['first'][:200]))
