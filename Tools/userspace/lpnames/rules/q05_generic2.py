import re, sys, os
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'role read off the defining expressions of the web (loop counter, compiler option query, operand record lookup, virtual register, fresh temporary index)'
def live(var, lines):
    return any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines)
def name(var, k, defs, lines, ctx):
    if not var or var.startswith(('param_', 'in_', 'extraout', 'local_', 'auStack', 'fparam')): return None
    if not live(var, lines) or not defs: return None
    ds = [d.strip().rstrip(';') for d in defs]
    # loop counter: every definition is a small constant or the variable plus/minus a constant
    if len(ds) >= 2 and all(re.match(r'^-?\d+$|^-?0x[0-9a-f]+$|^%s [+-] (?:0x)?[0-9a-f]+$|^%s \+ -\d+$' % (re.escape(var), re.escape(var)), d) for d in ds) and any(var in d for d in ds):
        return 'loopCounter'
    if all(re.match(r'^FUN_000e07dc\(\*\(undefined4 \*\)\(param_1 \+ 8\),\d+\)$', d) for d in ds): return 'optionEnabled'
    if all(re.match(r'^FUN_001054ec\(', d) for d in ds): return 'operandRecord'
    if all(re.match(r'^FUN_00127608\(', d) for d in ds): return 'virtualRegister'
    if all(re.match(r'^\*\(int \*\)\(\*\(int \*\)\(param_1 \+ 8\) \+ 0x3ac\) \+ -1$', d) for d in ds): return 'newTempIndex'
    if all(re.match(r'^\*\(undefined4 \*\)\(\*\(int \*\)\(param_1 \+ 8\) \+ 0x374\)$', d) for d in ds): return 'arenaA'
    if all(re.match(r'^\*\(undefined4 \*\)\(\*\(int \*\)\(param_1 \+ 8\) \+ 0x378\)$', d) for d in ds): return 'arenaB'
    if all(re.match(r'^FUN_000ec208\(', d) for d in ds): return 'registerFile'
    return None
