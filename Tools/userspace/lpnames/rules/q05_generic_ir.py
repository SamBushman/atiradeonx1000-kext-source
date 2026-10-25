import re, sys, os
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'role read off the defining call: operand record lookups, virtual register creation, fresh temporary index, r4 residuals'
VARS = ['extraout_r4', 'extraout_r4_00', 'extraout_r4_01', 'extraout_r4_02', 'extraout_r4_03', 'extraout_r4_04', 'extraout_r4_05', 'extraout_r4_06', 'extraout_r4_07', 'extraout_r4_08', 'extraout_r4_09', 'extraout_r4_10', 'extraout_r4_11', 'extraout_r4_12', 'extraout_r4_13', 'extraout_r4_14', 'extraout_r4_15', 'extraout_r4_16', 'extraout_r4_17']
def live(var, lines):
    return any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines)
def name(var, k, defs, lines, ctx):
    if not live(var, lines): return None
    ds = [d.strip().rstrip(';') for d in defs]
    if var.startswith('extraout_r4'):
        d = re.sub(r'\D', '', var.replace('extraout_r4', ''))
        return 'callResidualR4_' + (d.lstrip('0') or '0')
    if ds and all(re.match(r'^FUN_001054ec\(', d) for d in ds): return 'operandRecord'
    if ds and all(re.match(r'^FUN_00127608\(', d) for d in ds): return 'virtualRegister'
    if ds and all(re.match(r'^\*\(int \*\)\(\*\(int \*\)\(param_1 \+ 8\) \+ 0x3ac\) \+ -1$', d) for d in ds): return 'newTempIndex'
    return None
