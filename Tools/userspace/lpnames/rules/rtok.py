import re
EVIDENCE = ('role read off the definitions: inline growth of the translator IL token vector (translator+0x28 data, +0x2c count, +0x30 capacity, +0x24 error word; '
            'fpilReserveTokens 0x3ef50 is the out-of-line copy of the same code)')
P = r'param_1'
def tv(off):
    h = '0x%x' % off
    return r'(?:\(int \*\)\(%s \+ %s\)|%s \+ %d)' % (P, h, P, off // 4)
VEC = re.compile(r'^(?:\(int \*\)\(%s \+ 0x28\)|%s \+ 10)$' % (P, P))
CNT = re.compile(r'^(?:\*\(int \*\)\(%s \+ 0x2c\)|%s\[0xb\])$' % (P, P))
CAP = re.compile(r'^(?:\*\(uint \*\)\(%s \+ 0x30\)|%s\[0xc\])$' % (P, P))
ERR = re.compile(r'^(?:\*\(int \*\)\(%s \+ 0x24\)|%s\[9\])$' % (P, P))
PTR = re.compile(r'^\(undefined4 \*\)\((\w+) \* 4 \+ \*(\w+)\)$')
PTRU = re.compile(r'^\(uint \*\)\((\w+) \* 4 \+ \*(\w+)\)$')
NEED = re.compile(r'^(\w+) \+ (\w+)$')
GROW = re.compile(r'^(\w+) << 1$|^0x10$')


def name(var, k, defs, lines, ctx):
    ds = [d.rstrip(';').strip() for d in defs]
    d0 = ds[0] if ds else ''
    if any(VEC.match(d) for d in ds): return 'tokenDataPtrAddr'
    if any(CNT.match(d) for d in ds): return 'tokenCount'
    if any(CAP.match(d) for d in ds): return 'tokenCapacity'
    if any(ERR.match(d) for d in ds): return 'translatorError'
    if any(PTR.match(d) or PTRU.match(d) for d in ds): return 'tokenWritePtr'
    return None
