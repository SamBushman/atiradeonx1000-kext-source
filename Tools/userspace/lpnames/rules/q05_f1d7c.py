import re, sys, os
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'MOV chain walk of FUN_000f1d7c: four stack vectors (walk instructions / operand indices, fix-up instructions / operand indices) kept in local fake-struct headers; role read off the vector header word the web is loaded from'
HDR = {'local_58': 'walkInst', 'local_54': 'walkInst', 'local_50': 'walkInst', 'local_88': 'walkIndex', 'local_84': 'walkIndex', 'local_80': 'walkIndex',
       'local_78': 'fixupInst', 'local_74': 'fixupInst', 'local_70': 'fixupInst', 'local_68': 'fixupIndex', 'local_64': 'fixupIndex', 'local_60': 'fixupIndex'}
def vec(text):
    m = re.search(r'local_(?:58|54|50|88|84|80|78|74|70|68|64|60)', text)
    return HDR[m.group(0)] if m else None
def live(var, lines):
    return any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines)
OVR = {('piVar3',0):'node', ('piVar3',2):'node', ('piVar12',0):'fixupConsumer', ('bVar1',0):'walking', ('bVar1',1):'hasNode',
       ('dVar10',0):'destRegister', ('pdVar11',0):'destRegisterOffset'}
def name(var, k, defs, lines, ctx):
    if not live(var, lines): return None
    if (var, k) in OVR: return OVR[(var, k)]
    ds = [d.strip().rstrip(';') for d in defs]
    d = ds[0] if ds else ''
    t = ' '.join(ds)
    if var in ('iVar4', 'iVar5') and re.match(r'^local_\w+ \* 4$', d): return vec(d) + 'ByteOffset'
    if var == 'puVar2' or var in ('piVar12', 'piVar3'):
        if 'FUN_0019423c' in t or re.search(r'\* 4 \+ local_', t):
            v = vec(t)
            if v and re.search(r'\(uVar\d+ \* 4 \+ local_', t) and not 'FUN_0019423c' in t: return v + 'Top'
            if v: return v + 'Slot'
    if var in ('uVar8', 'uVar9'):
        m = re.match(r'^(local_\w+)$', d)
        if m and m.group(1) in HDR: return HDR[m.group(1)] + 'Count'
        m = re.match(r'^(local_\w+) - 1$', d)
        if m and m.group(1) in HDR: return HDR[m.group(1)] + 'TopIndex'
        if d == 'piVar3[3]': return 'readMask'
        if d.startswith('~*(uint *)'): return 'unusedMask'
        if re.match(r'^local_40 & \*\(uint \*\)', d): return 'maskedUse'
    return None
