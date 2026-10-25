import re
EVIDENCE = 'IL token reader state machine (FUN_000e5e70): stack vectors of the reader object and the inlined Vector push/pop idioms; role read off the ilReader field the web is loaded from'
VECS = {0xf: 'ifResultStack', 0x10: 'scopeStack', 0x11: 'savedStateStack', 0x22: 'replayStack'}
SCAL = {0x1d: 'cursor', 0xb: 'streamBase', 0x1f: 'readState', 0x20: 'skipMode', 0x12: 'ifNesting', 0x13: 'loopNesting', 0x14: 'savedFlag',
        0x15: 'saveDepth', 0x24: 'tokenWord1', 0x25: 'tokenWord2', 0x23: 'tokenWord0'}
def vec_in(text):
    m = re.search(r'param_1\[(0x[0-9a-f]+)\]', text)
    return VECS.get(int(m.group(1), 16)) if m else None
def vec_of(ctx, var, line):
    # nearest earlier line that loads var (or a pointer var) from param_1[K] in VECS
    for i in range(line, max(line - 40, 0), -1):
        m = re.match(r'\s*%s = (?:\(\w+ \*\))?param_1\[(0x[0-9a-f]+)\];' % re.escape(var), ctx.body[i])
        if m and int(m.group(1), 16) in VECS: return VECS[int(m.group(1), 16)]
    return None
OVR = {('bVar18',0):'comparisonResult',('iVar4',0):'segmentStart',('iVar4',1):'writeCursor',('iVar4',2):'tokenReadOk',('iVar4',9):'firstDestToken',
       ('iVar4',10):'labelValue',('iVar7',4):'extraOperandB',('iVar17',0):'extraOperandA',('iVar13',0):'ifSkipDepth',('iVar14',0):'replaySkipDepth',
       ('iVar13',1):'optionEnabled',('iVar14',1):'optionEnabled',('iVar13',2):'constantRegister',('uVar12',0):'waitLabel',('uVar12',1):'destRegisterFile',
       ('piVar16',2):'scope',('puVar9',8):'newScope',('uVar8',0):'dispatchOpcode',('uVar3',13):'loopCounter',('uVar5',0):'secondOperandToken',('uVar11',0):'firstRegisterFile',('uVar2',2):'skipCount'}
def name(var, k, defs, lines, ctx):
    n = name0(var, k, defs, lines, ctx)
    if not n: return n
    if var == 'uVar2' and n == 'opcode': n = 'opcode16'
    if var in ('puVar9', 'puVar10') and n.endswith(('Slot', 'Top')): n += 'Entry'
    if var.startswith('iVar') and n in VECS.values(): n += 'Vec'
    if var in ('uVar6', 'uVar12') and n.endswith('Count'): n = n[:-5] + 'Size'
    if var in ('iVar7', 'iVar17', 'uVar8') and n == 'poppedValue': n = {'iVar7': 'poppedState', 'iVar17': 'restoredValue', 'uVar8': 'closedScope'}[var]
    return n
def name0(var, k, defs, lines, ctx):
    if (var,k) in OVR: return OVR[(var,k)]
    if len(defs) > 1 and any(re.match(r'^\(\w+ \*\)0x0;?$', x.strip()) for x in defs):
        t = ' '.join(defs)
        mm = re.search(r'param_1\[(0x[0-9a-f]+)\]', t)
        if mm and int(mm.group(1), 16) in VECS: return VECS[int(mm.group(1), 16)] + 'Top'
        mv = re.search(r'\*\(int \*\)\((iVar\d+) \+ 8\)', t)
        if mv:
            n = vec_of(ctx, mv.group(1), min(lines))
            if n: return n + 'Top'
    rs = {name1(var, k, [x], lines, ctx) for x in defs} - {None} if defs else set()
    if len(rs) != 1:
        import os
        if os.environ.get('DBG'): print('MIX', var, k, rs, defs)
        return None
    return rs.pop()
def name1(var, k, defs, lines, ctx):
    d = defs[0].strip().rstrip(';') if defs else ''
    first = lines[0]
    m = re.match(r'^\(uint \*\)param_1\[(0x[0-9a-f]+)\]$', d)
    if m and int(m.group(1), 16) in VECS: return VECS[int(m.group(1), 16)]
    m = re.match(r'^param_1\[(0x[0-9a-f]+)\]$', d)
    if m:
        v = int(m.group(1), 16)
        if v in VECS and var.startswith('iVar'): return VECS[v]
        if v in SCAL: return SCAL[v] + 'Snapshot' if var.startswith(('iVar','uVar')) else None
    # count of a pushed vector: pointerVar[1]
    m = re.match(r'^(puVar15)\[1\]$', d)
    if m:
        n = vec_of(ctx, 'puVar15', min(lines))
        return n + 'Count' if n else None
    m = re.match(r'^\(\w+ \*\)\(\w+ \* 4 \+ (puVar15)\[2\]\)$', d)
    if m or 'Vector__elementRefGrow' in ' '.join(defs) or 'FUN_0019423c' in ' '.join(defs):
        n = vec_of(ctx, 'puVar15', min(lines))
        return n + 'Slot' if n else None
    # pop idiom: slot = top element
    if re.match(r'^\(\w+ \*\)0x0$', d) and len(defs) > 1:
        t = ' '.join(defs)
        mm = re.search(r'param_1\[(0x[0-9a-f]+)\]', t)
        if mm and int(mm.group(1), 16) in VECS: return VECS[int(mm.group(1), 16)] + 'Top'
        mv = re.search(r'\*\(int \*\)\((iVar\d+) \+ 8\)', t)
        if mv:
            n = vec_of(ctx, mv.group(1), min(lines))
            if n: return n + 'Top'
    m = re.match(r'^\*\(uint \*\)\((?:param_1\[(0x[0-9a-f]+)\]|(iVar\d+)) \+ 4\)(?: - 1)?$', d)
    if m:
        n = VECS.get(int(m.group(1), 16)) if m.group(1) else vec_of(ctx, m.group(2), min(lines))
        if n: return n + 'Count'
    m = re.match(r'^(uVar\d+) - 1$', d)
    if m: return 'topIndex'
    if d == '*piVar16' or d == '*puVar9': return 'poppedValue'
    if re.match(r'^\(ushort\)|^\(uint\)\*\(ushort \*\)\(\(int\)param_1 \+ 0x8e\)$', d) or re.match(r'^\*\(ushort \*\)\(\(int\)param_1 \+ 0x8e\)$', d): return 'opcode'
    if re.match(r'^\(uint\)uVar2$', d): return 'opcode'
    if re.match(r'^\*\(short \*\)\(\(int\)param_1 \+ 0x92\)$', d) or re.match(r'^\*\(ushort \*\)\(\(int\)param_1 \+ 0x92\)$', d): return 'operandRegister'
    return None
