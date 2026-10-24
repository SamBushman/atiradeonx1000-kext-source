import re
EVIDENCE = 'role read off the web definitions: matrix element index = (field offset - matrix base)/4 in row-major r,c; constant-upload state-parameter loader (FUN_0009f0b0)'
WHOLE = {
 'param_1': 'ctx', 'param_2': 'program', 'piVar45': 'paramList', 'iVar31': 'ctxState', 'iVar18': 'paramMap', 'iVar36': 'constantBuffer',
 'iVar35': 'stateBlock', 'iVar33': 'paramMapEntries', 'uVar32': 'paramIndex', 'iVar34': 'paramOffset', 'uVar44': 'elementIndex',
 'uVar16': 'texGenComponent', 'puVar26': 'texGenPlane',
 'local_168': 'stateVecX', 'fStack_164': 'stateVecY', 'local_160': 'stateVecZ', 'uStack_15c': 'stateVecW',
 'local_118': 'intToDoubleHiA', 'uStack_114': 'intToDoubleLoA', 'local_110': 'intToDoubleHiB', 'uStack_10c': 'intToDoubleLoB',
 'local_108': 'minor1', 'local_100': 'cofactor20', 'local_104': 'cofactor30', 'local_fc': 'cofactor10', 'local_f8': 'cofactor00',
 'local_f4': 'determinant', 'local_f0': 'minorProduct', 'uVar46': 'valueXY', 'uVar56': 'valueZW',
}
for i in range(3, 9): WHOLE['param_%d' % i] = 'unusedArg%d' % i
for i in range(2, 14): WHOLE['fparam_%d' % i] = 'unusedFloatArg%d' % i
WHOLE['fparam_1'] = 'scratchProduct'
RES = {'158': 0, '148': 1, '138': 2, '128': 3, '154': 4, '144': 5, '134': 6, '124': 7, '150': 8, '140': 9, '130': 10, '120': 11, '14c': 12, '13c': 13, '12c': 14, '11c': 15}
for h, i in RES.items(): WHOLE['local_' + h] = 'result%d%d' % (i // 4, i % 4)
def whole(var): return WHOLE.get(var)

MINOR = {('fVar15', 1): 'minor2', ('fVar1', 1): 'minor3', ('fVar2', 1): 'minor4', ('fVar3', 1): 'minor5', ('fVar4', 4): 'minor6',
         ('dVar48', 1): 'minor7', ('dVar49', 1): 'minor8', ('dVar55', 0): 'minor9', ('dVar53', 0): 'minor10', ('dVar51', 0): 'minor11',
         ('dVar54', 0): 'minor12', ('dVar52', 4): 'minor13', ('fVar8', 2): 'invDeterminant'}
LOAD = re.compile(r'^(?:\(double\))?\*\((?:float|undefined4) \*\)\((\w+) \+ (0x[0-9a-f]+|\d+)U?\)')
def off(s): return int(s, 16) if s.startswith('0x') else int(s)
def name(var, k, defs, lines, ctx):
    if (var, k) in MINOR: return MINOR[(var, k)]
    d = defs[0] if defs else ''
    c = ctx.case_of(lines[0])
    m = LOAD.match(d)
    if m:
        base, o = m.group(1), off(m.group(2))
        if base == 'iVar35' and 0x1920 <= o < 0x1960:
            i = (o - 0x1920) // 4
            pre = {0: 'mvp', 3: 'mvpCopy'}.get(c)
            if pre: return '%s%d%d' % (pre, i // 4, i % 4)
        if base in ('iVar25', 'iVar28') and 0x100 <= o < 0x140:
            i = (o - 0x100) // 4
            pre = {0: 'mulSlot', 1: 'copySlot', 2: 'invSrc'}.get(c)
            if pre: return '%s%d%d' % (pre, i // 4, i % 4)
        if base == 'iVar28' and 0x400 <= o < 0x440 and c == 4:
            i = (o - 0x400) // 4
            return 'slotAlt%d%d' % (i // 4, i % 4)
        if base == 'iVar35' and o == 0x24a4: return 'stateF24a4'
    if var == 'iVar25':
        if re.search(r'iVar35 \+ 0x1860', d): return 'slotMatrix'
        if re.search(r'iVar35 \+ 0x24c0', d): return 'lightState'
        if re.search(r'uVar27 \* 0xcc', d): return 'texUnitState'
        if re.search(r'param_1', d): return 'ctxVec4Entry'
        if '* 0x10' in d: return 'constDest' if any('iVar36 + iVar25' in x for x in defs) else 'constOffset'
        if re.search(r'^\*\(int \*\)', d): return 'constIndex'
    if var == 'iVar28':
        return 'slotMatrixCopy' if c == 1 else 'slotMatrixAlt'
    if var == 'iVar30':
        if 'iVar36 + iVar25' in d: return 'constAddr'
        if 'param_1 + uVar44 * 0x6c' in d: return 'ctxUnitState'
        if 'iVar35 + 0x24c0' in d: return 'lightState2'
        if '0x240' in d: return 'materialState'
    if var == 'uVar27': return 'paramCount' if k == 0 else 'texUnit'
    return None
