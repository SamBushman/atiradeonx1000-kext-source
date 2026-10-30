import re
EVIDENCE = ('role read off the web definitions in extvsPrepareHardwareProgram; the tag names the symbol operand and the allocation path: '
            'Src0/Src1/Src2 = operand records at +0x20/+0x3c/+0x58 of the 0x74-byte symbol record, Inv = GL_INVARIANT_EXT (0x87c2) pass, '
            'Lc = GL_LOCAL_CONSTANT_EXT (0x87c3) pass, Direct = the symbol itself, Elem = the elements of an array symbol, '
            'Scalar/Vector/Matrix = GL_SCALAR_EXT/GL_VECTOR_EXT/GL_MATRIX_EXT (0x87be/0x87bf/0x87c0); slot entries are the 0x28-byte hardware '
            'register slots at programState+0x54 (count at +0x58)')
START = re.compile(r'\+ 0x(20|3c|58)\) == 2\) \{$')
ELEM = re.compile(r'\+ 0x34\) != 0\) \{$')
TYPE = re.compile(r'== 0x87(bf|c0|be)\) \{$')
TN = {'bf': 'Vector', 'c0': 'Matrix', 'be': 'Scalar'}
_cache = {}


def info(ctx):
    k = id(ctx.body)
    if k in _cache: return _cache[k]
    b = ctx.body
    marks = [i for i, l in enumerate(b) if START.search(l)][:6]
    ev = [i for i, l in enumerate(b) if ELEM.search(l)]
    ty = [(i, TN[TYPE.search(l).group(1)]) for i, l in enumerate(b) if TYPE.search(l)]
    _cache[k] = (marks, ev, ty)
    return _cache[k]


def tag(ctx, line):
    marks, ev, ty = info(ctx)
    if not marks or line < marks[0]: return None
    n = max(j for j, i in enumerate(marks) if i <= line)
    start = marks[n]
    end = marks[n + 1] if n + 1 < len(marks) else 10 ** 9
    t = 'Src%d%s' % (n % 3, 'Inv' if n < 3 else 'Lc')
    es = [i for i in ev if start <= i < end and i <= line]
    elem = bool(es)
    t += 'Elem' if elem else 'Direct'
    lo = es[-1] if es else start
    tys = [nm for i, nm in ty if lo <= i <= line]
    if tys: t += tys[-1]
    return t


def name(var, k, defs, lines, ctx):
    ds = [d.strip().rstrip(';') for d in defs]
    s = set(ds)
    if s == {'param_2[6]'}: return 'symbolRecords'
    if s == {'param_2[8]'}: return 'symbolList'
    t = tag(ctx, lines[0])
    if not t: return None
    if len(ds) == 2:
        a, b = ds
        if b == '%s + 0x28' % var:
            if a == '0': return 'scanOffset' + t
            if re.fullmatch(r'\w+ \* 0x28', a): return 'matrixSlotOffset' + t
        if b == '%s + -1' % var and a == '4': return 'rowsLeft' + t
        if b == '%s + 0x54' % var and re.fullmatch(r'iVar\d+', a): return 'listEntryOffset' + t
    if len(ds) == 1:
        d = ds[0]
        if re.fullmatch(r'\*\(int \*\)\(\w+ \+ 0x24\)', d): return 'symbolDataType' + t
        if d == '*(int *)(param_3 + 0x58)': return 'oldSlotCount' + t
    return None
