import re
EVIDENCE = 'temp register allocator (FUN_00090ca0): staged value of a DAT_ selector constant that is stored into the result operand word named; loop/flag cursors read off the definitions'
WHOLE = {'param_1': 'allocState', 'param_2': 'componentCount', 'param_3': 'resultOperand'}
def whole(v): return WHOLE.get(v)
def name(var, k, defs, lines, ctx):
    d = defs[0].strip().rstrip(';') if defs else ''
    if re.match(r'^DAT_\w+$', d):
        for x in lines:
            m = re.search(r'param_3\[(\d+)\] = %s;' % re.escape(var), ctx.body[x])
            if m: return 'resultWord%sStaged' % m.group(1)
    if re.match(r'^\w+ \* 4 \+ param_1$', d): return 'regFlags'
    if d == 'param_1' or re.match(r'^%s \+ 4$' % re.escape(var), d): return 'flagCursor'
    if re.match(r'^\*\(int \*\)\(param_1 \+ 1000\)$', d): return 'regCountdown'
    return None
