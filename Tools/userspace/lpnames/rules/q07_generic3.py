import re, sys, os
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'role read off the defining expressions of the web (counter, operand record / source lookup, operand count vcall, compiler target / arena field)'
def live(var, lines):
    return any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines)
ID = r'[A-Za-z_]\w*'
def name(var, k, defs, lines, ctx):
    if not var or var.startswith(('param_', 'in_', 'extraout', 'local_', 'auStack', 'fparam', 'uStack', 'cStack')): return None
    if not live(var, lines) or not defs: return None
    ds = [d.strip().rstrip(';') for d in defs]
    V = re.escape(var)
    if len(ds) >= 2 and all(re.match(r'^-?\d+$|^%s \+ -?\d+$' % V, d) for d in ds) and any(var in d for d in ds):
        steps = [int(re.sub(r'.*\+ ', '', d)) for d in ds if var in d]
        starts = [int(d) for d in ds if var not in d]
        if steps and all(s == -1 for s in steps) and starts: return 'countdown'
        if steps and all(s == 1 for s in steps) and starts and all(s == 0 for s in starts): return 'loopIndex'
        return None
    if all(re.match(r'^[A-Za-z_]\w*\[1\]$', d) for d in ds): return 'vectorFilledCount'
    if all(re.match(r'^\*\(u?int\d* ?\*?\)\(\w+ \+ 0x10\)$|^\*\(undefined4 \*\)\(\w+ \+ 0x10\)$', d) for d in ds): return 'operandSelect'
    fs = set()
    for d in ds:
        m = re.match(r'^\*\((?:undefined4|int|uint) \*\)\(\(int\)param_1 \+ (0x[0-9a-f]+)\)$', d)
        if m and m.group(1) != '0x10': fs.add(m.group(1)[2:])
        else: fs = None; break
    if fs and len(fs) == 1: return 'savedField' + fs.pop()
    if all(re.match(r'^FUN_001054ec\(', d) for d in ds): return 'operandRecord'
    if all(re.match(r'^FUN_00105594\(', d) for d in ds): return 'operandVReg' if var.startswith('p') else 'sourceDef'
    if all(re.match(r'^\(\*\*\(code \*\*\)\(\*%s \+ 0x14\)\)\(%s\)$' % (ID, ID), d) for d in ds): return 'operandCount'
    if all(re.match(r'^\*\(int \*\*\)\(\*\(int \*\)\(%s \+ 8\) \+ 0x30c\)$' % ID, d) for d in ds): return 'target'
    if all(re.match(r'^\*\(undefined4 \*\)\(\*\(int \*\)\(%s \+ 8\) \+ 0x378\)$' % ID, d) for d in ds): return 'arenaB'
    if all(re.match(r'^\*\(undefined4 \*\)\(\*\(int \*\)\(%s \+ 8\) \+ 0x374\)$' % ID, d) for d in ds): return 'arenaA'
    if all(re.match(r'^FUN_00127608\(', d) for d in ds): return 'virtualRegister'
    cs = set()
    for d in ds:
        v = re.match(r'^\(\*\*\(code \*\*\)\(.*? \+ (0x[0-9a-f]+|\d+)\)\)\(', d)
        m = re.match(r'^(?:\(\w[\w \*]*\))?\(*(?:\w[\w \*]*\(\*\)\(\)\))?\)?\(*([A-Za-z_]\w*)\)?\(', d)
        if v: cs.add('vcall%sResult' % (v.group(1)[2:] if v.group(1).startswith('0x') else '%x' % int(v.group(1))))
        elif m and m.group(1) not in ('code', 'int', 'uint', 'char', 'byte', 'float', 'double', 'bool', 'undefined4', 'undefined1', 'undefined'):
            c = m.group(1)
            c = globals().get('FUNCMAP', {}).get(c, c)
            if c.startswith('FUN_'): cs.add('callResult')
            else:
                b = c.split('__')[-1]
                cs.add(b[0].lower() + b[1:] + 'Result')
        else: return None
    if len(cs) == 1: return cs.pop()
    return None
