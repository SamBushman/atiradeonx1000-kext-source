"""R1b rule set 1: vtable-resolved allocation classes, $k stack loads, virtual-method results"""
import sys, re, struct
sys.path.insert(0, '/home/sam/g5logs/R1b')
import yyinfo as y, vt
lines = y.lines
# ---- vtable resolution -------------------------------------------------------------------------------------------------------------------------
def nlsym(addr):
    m = vt.m
    for s in m.secs:
        if s['addr'] <= addr < s['addr'] + s['size'] and (s['flags'] & 0xff) in (6, 7):
            idx = m.indirect[s['r1'] + (addr - s['addr']) // 4]
            return m.syms[idx]['name'] if isinstance(idx, int) and idx < len(m.syms) else None
    return None
CURLINE = [None]
def vtable_class(expr):
    """class named by a vtable expression of the corpus text: &PTR_X_a7b7NNNN (object's own vtable symbol at NNNN-8) | PTR_vtable_a7b7NNNN + 8 (imported __ZTV symbol)"""
    m = re.search(r'&PTR_\w*?_(a7b[0-9a-f]{5})\b', expr)
    if m:
        a = int(m.group(1), 16); s = vt.byaddr.get(a - 8)
        if s and s.startswith('__ZTV'): return re.sub(r'^__ZTV\d+', '', s) if False else vt_cls(s)
    m = re.search(r'\bpicBase\d* \+ (-?0x[0-9a-f]+)', expr)
    if m:
        a = 0xa7b8374c + int(m.group(1), 0); s = vt.byaddr.get(a - 8)
        if s and s.startswith('__ZTV'): return vt_cls(s)
    m = re.search(r'\b(local_[0-9a-f]+) \+ (-0x610c)', expr)
    if m and CURLINE[0] is not None:
        v = m.group(1)
        if any(re.match(r'\s*%s = \(unsigned char \*\)0xa7b8374c;$' % v, lines[k]) for k in range(max(CURLINE[0] - 120, 0), CURLINE[0])):
            s = vt.byaddr.get(0xa7b8374c - 0x610c - 8)
            if s and s.startswith('__ZTV'): return vt_cls(s)
    m = re.search(r'PTR_vtable_(a7b[0-9a-f]{5})', expr)
    if m:
        s = nlsym(int(m.group(1), 16))
        if s and s.startswith('__ZTV'): return vt_cls(s)
    return None
def vt_cls(sym):
    m = re.match(r'__ZTV(\d+)', sym)
    n = int(m.group(1)); return sym[m.end():m.end() + n]

VT_NAME2CLS = {'typeVtable': 'TType', 'symbolVtable': 'TSymbol', 'variableVtable': 'TVariable', 'functionVtable': 'TFunction', 'intermAggregateVtable': 'TIntermAggregate', 'intermTypedVtable': 'TIntermTyped'}
NEWNAME = {'TType': 'newType', 'TFunction': 'newFunction', 'TVariable': 'newVariable', 'TSymbol': 'newSymbol', 'TIntermAggregate': 'newAggregate',
           'TIntermTyped': 'newTypedNode'}
def resolve_vtable_var(v, ln):
    """value of vtable-holding variable v at line ln: nearest preceding `v = <expr>` within 60 lines"""
    for k in range(ln - 1, max(ln - 160, 0), -1):
        m = re.match(r'\s*%s = (.*);$' % re.escape(v), lines[k])
        if m: return m.group(1)
    return None
def alloc_class(w):
    """class of an allocation web: the last vtable store `*X = <vtable>` in the web's lines"""
    cls = None; size = None
    sizes = set()
    for ln in w.deflines:
        rhs = y.rhs_of(w.v, ln)
        m = rhs and re.search(r'allocate\(poolAllocator,(0x[0-9a-f]+|\d+)\)', rhs)
        sizes.add(int(m.group(1), 0) if m else None)
    if len(sizes) != 1 or None in sizes: return None, None      # every definition must be the same pool allocation
    size = next(iter(sizes))
    for ln in w.lines:
        m = re.match(r'\s*\*(?:\([^;=]*\))?\s*%s = (.*);$' % re.escape(w.v), lines[ln])
        if not m: continue
        e = m.group(1)
        CURLINE[0] = ln
        c = vtable_class(e)
        mv = re.search(r'(\w+Vtable)\s*$', e.strip())
        if c is None and mv: c = VT_NAME2CLS.get(mv.group(1))
        if c is None and re.fullmatch(r'\(?[\w *]*\)?(\w+)', e.strip()):
            vv = re.search(r'(\w+)$', e.strip()).group(1)
            rv = resolve_vtable_var(vv, ln)
            if rv: c = vtable_class(rv)
        if c: cls = c
    return cls, size

# ---- $k stack loads -------------------------------------------------------------------------------------------------------------------------
FIELD = {0: ('Line', 'uint'), 4: ('Op', None), 8: ('Node', None), 0xc: ('Node2', None), 0x10: ('TypeOrFunction', None), 0x14: ('QualifierOrParamType', None),
         0x18: ('Size', None), 0x1c: ('Matrix', None), 0x20: ('Array', None), 0x24: ('UserDef', None), 0x28: ('TypeLine', None)}
def camel(sym):
    parts = sym.lstrip('@').lower().split('_')
    return parts[0] + ''.join(p.capitalize() for p in parts[1:])
def slot_ref(off, case):
    """yyvsp + off in the action of rule `case` -> (k, field offset, symbol)"""
    lhs, rhs = y.rule(case); n = len(rhs)
    q = off // 0x2c; F = off - q * 0x2c; k = n + q
    if not (1 <= k <= n): return None
    return k, F, rhs[k - 1], lhs
def yyvsp_load(w):
    """-> (k, F, sym) when every definition of w is a plain load of the same yyvsp slot"""
    c = w.case()
    if not isinstance(c, int) or c < 1 or c > 215: return None
    if not all(y.pure[l] for l in w.lines): return None
    got = None
    for ln in w.deflines:
        r = y.rhs_of(w.v, ln)
        if not r: return None
        m = re.fullmatch(r'(?:\([\w *]+\)\s*)?\*\([\w *]+\)\(yyvsp(?: \+ (-?0x[0-9a-f]+|-?\d+))?\)', r.strip()) or re.fullmatch(r'(?:\([\w *]+\)\s*)?\*\([\w *]+\)yyvsp', r.strip())
        if not m: return None
        off = int(m.group(1), 0) if m.lastindex else 0
        s = slot_ref(off, c)
        if not s: return None
        if got is None: got = s
        elif got[:3] != s[:3]: return None
    return got

# ---- virtual calls on TIntermTyped (slot = vtable offset / 4; the object's vptr points at vtable + 8, so slot k is at vptr + 4k) -----------------
TT_SLOTS = {k: s for k, s in vt.slots(0xa7b7cf88, 40)}
def vcall_name(off):
    s = TT_SLOTS.get(off // 4)
    if not s: return None
    m = re.match(r'__ZN?K?\d+(\w+?)\d*(?:[A-Z]\w*)?$', s)
    mm = re.match(r'__ZNK?\d+\w+?(\d+)(\w+?)(E|ERK|EP|Ei|Ev)', s)
    return s

# ---- class-aware virtual call naming ---------------------------------------------------------------------------------------------------------------
VT_ADDR = {'TIntermTyped': 0xa7b7cf88, 'TIntermNode': 0xa7b7d038, 'TIntermAggregate': 0xa7b7d1b0, 'TIntermBinary': 0xa7b7d2a8, 'TIntermSymbol': 0xa7b7d388,
           'TIntermUnary': 0xa7b7d238, 'TIntermConstantUnion': 0xa7b7d320, 'TIntermSelection': 0xa7b7d140, 'TIntermBranch': 0xa7b7d0c0, 'TIntermLoop': 0xa7b7d100,
           'TFunction': 0xa7b7d510, 'TSymbol': 0xa7b7d560, 'TVariable': 0xa7b7d538, 'TType': 0xa7b7d638}
SLOTS = {c: dict(vt.slots(a, 60)) for c, a in VT_ADDR.items()}
def method_of(cls, off):
    s = SLOTS.get(cls, {}).get(off // 4)
    if not s or s.startswith('___cxa'): return None
    m = re.match(r'__ZN?K?(\d+)', s)
    n = int(m.group(1)); rest = s[m.end() + n:]
    mm = re.match(r'(\d+)', rest)
    if not mm: return None
    k = int(mm.group(1)); return s[m.end():m.end() + n], rest[mm.end():mm.end() + k]
ROLE = {'getBasicType': 'basicType', 'getQualifier': 'qualifier', 'getNominalSize': 'nominalSize', 'getSize': 'size', 'isMatrix': 'isMatrix', 'isArray': 'isArray',
        'isVector': 'isVector', 'getAsAggregate': 'aggregate', 'getAsBinaryNode': 'binaryNode', 'getAsSelectionNode': 'selectionNode', 'getAsSymbolNode': 'symbolNode',
        'getAsConstantUnion': 'constantUnion', 'getAsTyped': 'typedNode', 'getType': 'nodeType', 'getTypePointer': 'typePointer', 'getSequence': 'sequence',
        'getName': 'name', 'getId': 'symbolId', 'getSymbol': 'symbol', 'getLeft': 'leftNode', 'getRight': 'rightNode', 'isUserDefined': 'isUserDefined',
        'getMangledName': 'mangledName', 'isFunction': 'isFunction', 'isVariable': 'isVariable', 'getLine': 'nodeLine'}
GETAS_CLASS = {'getAsAggregate': 'TIntermAggregate', 'getAsBinaryNode': 'TIntermBinary', 'getAsSelectionNode': 'TIntermSelection', 'getAsSymbolNode': 'TIntermSymbol',
               'getAsConstantUnion': 'TIntermConstantUnion', 'getAsTyped': 'TIntermTyped'}
TYPED_SYMS = re.compile(r'(.*_expression|variable_identifier|function_call(_generic)?|primary_expression|initializer|assignment_expression|integer_expression|expression_statement)$')
VCALL_A = re.compile(r'\(\*\*\(code \*\*\)\(\*(?:\([\w ]+\*+\))?(\w+) \+ (0x[0-9a-f]+|\d+)\)\)\(')
VCALL_B = re.compile(r'\(\*\*\(code \*\*\)\(\*\*\(int \*\*\)\(yyvsp(?: \+ (-?0x[0-9a-f]+|-?\d+))?\) \+ (0x[0-9a-f]+|\d+)\)\)\(')
