import re
EVIDENCE = ('role read off the definitions: the variable holds the return code of one fpil* helper (0 = ok, otherwise the translator error word) '
            'and is only tested against zero / returned')
CALL = re.compile(r'^\(\(int \(\*\)\(\)\)(\w+)\)\(')
STATUS = {
    'FUN_0003fbf0': 'emitStatus',        # fpilEmitInstruction
    'FUN_0003f750': 'dstStatus',         # fpilTranslateDestination
    'FUN_0003f1c0': 'srcStatus',         # fpilTranslateSource
    'FUN_0003ef50': 'reserveStatus',     # fpilReserveTokens
    'FUN_0003f050': 'constStatus',       # constant-register lookup
    'FUN_00046a30': 'arithStatus',       # fragmentTranslateArithmetic
    'FUN_000467a0': 'anyStatus',
    'FUN_00046180': 'allStatus',
    'FUN_000457f0': 'selStatus',
    'FUN_00044c90': 'dslStatus',
}
VARS = ['iVar6', 'iVar23', 'iVar24', 'iVar14']


def name(var, k, defs, lines, ctx):
    names = set()
    for d in defs:
        m = CALL.match(d.strip())
        if not m: return None
        n = STATUS.get(m.group(1))
        if not n: return None
        names.add(n)
    if len(names) == 1: return names.pop()
    return 'callStatus' if names else None
