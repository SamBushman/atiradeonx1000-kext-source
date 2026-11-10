#!/usr/bin/env python3
"""narrow_float_ops.py CORPUS_DIR  - single-precision arithmetic that Ghidra prints as double arithmetic goes back to float arithmetic (GLEngine corpus step 15).

Ghidra models every PowerPC single-precision instruction in double precision: `fsubs f9,f9,f13` is `(float)((double)a - (double)b)` and `fmadds f11,f1,f9,f13` is
`(float)(f1 * (double)(float)(..) + (double)c)`. gcc compiles that literally - a double operation followed by `frsp` (and, for the fused form, `fmadd` + `frsp`) where the stock has one
`fsubs` / `fmadds`: 1885 extra frsp in 228 functions of the first GLEngine image (the stock has ~no frsp at all).

Two rewrites, both value-preserving:
 B. `(float)(R)` where R is a tree over float-VALUED operands with one of the shapes
        X op Y                        op in + - * /      (a double operation on two floats rounded once to float is exactly the float operation: a double
                                                          has more than 2*24+2 bits - the classic innocuous-double-rounding result for + - * / )
        (X * Y) +/- Z, Z +/- (X * Y)                    (the fmadds / fmsubs family: one rounding of the exact product sum; as a float expression gcc contracts it to the same fused
                                                          instruction - the stock's own, and EXACTER than the double-then-float rounding it replaces)
        -(one of the above)                              (fnmadds / fnmsubs)
    becomes the float expression with the `(double)` casts removed. Float-valued = type float, `(double)<float>` or a double literal that is exactly a float.
    Innermost spans first, so `(double)(float)(a - b)` (a rounded intermediate) becomes `(double)(a - b)`.
 A. A `double dVarN` local whose every assignment is float-valued is declared `float`; its uses become `(double)dVarN` (so the arithmetic around them stays double until rule B
    narrows it - a float*float product would otherwise round where the double product did not).
Anything the small expression parser does not recognise is left untouched. Only the GLEngine corpus (stock code has no frsp) is processed."""
import re, sys, glob, os

TYPEW = set('float double int uint unsigned signed char short long byte undefined undefined1 undefined2 undefined3 undefined4 undefined8 void ulong ushort uchar bool code dword word longlong ulonglong'.split())
TOK = re.compile(r'\s*(0[xX][0-9a-fA-F]+[uUlL]*|\d+\.\d*(?:[eE][-+]?\d+)?[fF]?|\.\d+(?:[eE][-+]?\d+)?[fF]?|\d+[eE][-+]?\d+[fF]?|\d+[uUlL]*|[A-Za-z_]\w*|->|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%!~&|^<>?:=(),.\[\];])')

class Node:
    __slots__ = ('k', 'op', 'a', 'b', 's', 'e')
    def __init__(s_, k, op=None, a=None, b=None, s=0, e=0): s_.k = k; s_.op = op; s_.a = a; s_.b = b; s_.s = s; s_.e = e

class Fail(Exception): pass

def tokenize(t):
    out = []; i = 0
    while i < len(t):
        if t[i:].strip() == '': break
        m = TOK.match(t, i)
        if not m: raise Fail('tok')
        out.append((m.group(1), m.start(1), m.end(1))); i = m.end()
    return out

class P:
    def __init__(s_, t): s_.t = t; s_.tk = tokenize(t); s_.i = 0
    def peek(s_): return s_.tk[s_.i][0] if s_.i < len(s_.tk) else None
    def nxt(s_): v = s_.tk[s_.i]; s_.i += 1; return v
    def pos(s_): return s_.tk[s_.i][1] if s_.i < len(s_.tk) else len(s_.t)
    def prevend(s_): return s_.tk[s_.i - 1][2]
    def expect(s_, x):
        if s_.peek() != x: raise Fail('expect ' + x)
        return s_.nxt()
    PREC = {'||': 1, '&&': 2, '|': 3, '^': 4, '&': 5, '==': 6, '!=': 6, '<': 7, '>': 7, '<=': 7, '>=': 7, '<<': 8, '>>': 8, '+': 9, '-': 9, '*': 10, '/': 10, '%': 10}
    def expr(s_, minp=0):
        l = s_.unary()
        while True:
            op = s_.peek()
            if op == '?' and minp == 0:       # ternary: opaque
                s_.nxt(); a = s_.expr(0); s_.expect(':'); b = s_.expr(0)
                l = Node('other', s=l.s, e=s_.prevend()); continue
            pr = s_.PREC.get(op)
            if pr is None or pr <= minp - 1 or pr < minp: break
            s_.nxt(); r = s_.expr(pr + 1)
            l = Node('bin', op, l, r, l.s, r.e)
        return l
    START = re.compile(r'[A-Za-z_\d.(\-*&!~]')
    def is_cast(s_):
        """`(` type-words and `*` `)` followed by the start of an operand"""
        j = s_.i + 1; words = 0; named = 0; star = 0
        while j < len(s_.tk) and s_.tk[j][0] != ')':
            w = s_.tk[j][0]
            if w == '*': star += 1
            elif w in TYPEW: words += 1
            elif re.fullmatch(r'[A-Za-z_]\w*', w) and not words and not named: named = 1     # a named struct type: only with a `*`
            else: return False
            j += 1
        if j >= len(s_.tk) or j + 1 >= len(s_.tk): return False
        if not (words or (named and star)): return False
        return bool(s_.START.match(s_.tk[j + 1][0]))
    def unary(s_):
        v = s_.peek()
        if v is None: raise Fail('eof')
        st = s_.pos()
        if v in ('-', '+', '!', '~', '*', '&'):
            s_.nxt(); o = s_.unary(); return Node('un', v, o, None, st, o.e)
        if v == '(':
            if s_.is_cast():
                j = s_.i + 1; ty = []
                while s_.tk[j][0] != ')': ty.append(s_.tk[j][0]); j += 1
                s_.i = j + 1
                o = s_.unary()
                return Node('cast', ' '.join(ty), o, None, st, o.e)
            s_.nxt(); inner = s_.expr(0); s_.expect(')')
            n = Node('paren', None, inner, None, st, s_.prevend())
            return s_.postfix(n)
        return s_.postfix(s_.primary())
    def primary(s_):
        v = s_.peek(); st = s_.pos()
        if v is None: raise Fail('eof')
        if re.match(r'[A-Za-z_]\w*$', v):
            s_.nxt(); return Node('id', v, None, None, st, s_.prevend())
        if re.match(r'[\d.]', v):
            s_.nxt(); return Node('num', v, None, None, st, s_.prevend())
        raise Fail('primary ' + v)
    def postfix(s_, n):
        while True:
            v = s_.peek()
            if v == '[':
                s_.nxt(); ix = s_.expr(0); s_.expect(']'); n = Node('idx', None, n, ix, n.s, s_.prevend())
            elif v == '(':
                s_.nxt()
                if s_.peek() != ')':
                    s_.expr(0)
                    while s_.peek() == ',': s_.nxt(); s_.expr(0)
                s_.expect(')'); n = Node('call', None, n, None, n.s, s_.prevend())
            elif v in ('.', '->'):
                s_.nxt()
                if not s_.peek() or not re.match(r'[A-Za-z_]', s_.peek()): raise Fail('member')
                s_.nxt(); n = Node('other', None, n, None, n.s, s_.prevend())
            else: return n

def parse(t):
    p = P(t); n = p.expr(0)
    if p.i != len(p.tk): raise Fail('trailing')
    return n

def numval(tok):
    s = tok.rstrip('fFuUlL') if not tok.lower().startswith('0x') else tok.rstrip('uUlL')
    return float(int(s, 16)) if tok.lower().startswith('0x') else float(s)

import struct
def is_float_exact(x):
    try: return struct.unpack('>f', struct.pack('>f', x))[0] == x
    except OverflowError: return False

class Ctx:
    def __init__(s_, env, t): s_.env = env; s_.t = t
    def txt(s_, n): return s_.t[n.s:n.e]
    def ty(s_, n):
        k = n.k
        if k == 'num':
            if n.op[-1] in 'fF' and not n.op.lower().startswith('0x'): return 'float'
            return 'double' if re.search(r'[.eE]', n.op) and not n.op.lower().startswith('0x') else 'int'
        if k == 'id':
            if n.op.startswith('FLOAT_'): return 'float'
            if n.op.startswith('DOUBLE_'): return 'double'
            return s_.env.get(n.op, 'other')
        if k == 'paren': return s_.ty(n.a)
        if k == 'cast':
            t = n.op
            if t == 'float': return 'float'
            if t == 'double': return 'double'
            if t in ('int', 'uint', 'unsigned int'): return 'int'
            if t.replace(' ', '') in ('float*',): return 'float*'
            if t.replace(' ', '') in ('double*',): return 'double*'
            return 'other'
        if k == 'un':
            if n.op == '-': return s_.ty(n.a)
            if n.op == '*':
                a = n.a
                t = s_.ty(a)
                if t == 'float*': return 'float'
                if t == 'double*': return 'double'
                return 'other'
            return 'other'
        if k == 'idx':
            t = s_.ty(n.a)
            if t in ('float*', 'float[]'): return 'float'
            if t in ('double*', 'double[]'): return 'double'
            return 'other'
        if k == 'bin':
            if n.op not in ('+', '-', '*', '/'): return 'other'
            a, b = s_.ty(n.a), s_.ty(n.b)
            if a not in ('float', 'double', 'int') or b not in ('float', 'double', 'int'): return 'other'
            if 'double' in (a, b): return 'double'
            if 'float' in (a, b): return 'float'
            return 'int'
        return 'other'
    def fv(s_, n):
        """float-valued: type float, (double)<float>, or a double literal that is exactly a float"""
        t = s_.ty(n)
        if t == 'float': return True
        if n.k == 'paren': return s_.fv(n.a)
        if n.k == 'cast' and n.op == 'double': return s_.ty(n.a) == 'float'
        if n.k == 'num' and t == 'double': return is_float_exact(numval(n.op))
        if n.k == 'un' and n.op == '-': return s_.fv(n.a)
        return False
    def flt(s_, n):
        """text of the float expression equal to float-valued n"""
        if n.k == 'paren': return '(' + s_.flt(n.a) + ')'
        if n.k == 'cast' and n.op == 'double' and s_.ty(n.a) == 'float': return s_.txt(n.a)
        if n.k == 'num' and s_.ty(n) == 'double': return s_.txt(n) + 'f'
        if n.k == 'un' and n.op == '-' and s_.ty(n) != 'float': return '-' + s_.flt(n.a)
        return s_.txt(n)
    def prod(s_, n):
        m = n
        while m.k == 'paren': m = m.a
        return m if (m.k == 'bin' and m.op == '*' and s_.fv(m.a) and s_.fv(m.b)) else None
    def narrow(s_, n):
        """float expression text for double expression n, or None"""
        while n.k == 'paren': n = n.a
        if n.k == 'un' and n.op == '-':
            r = s_.narrow(n.a)
            return None if r is None else '-(' + r + ')'
        if n.k == 'bin' and n.op in ('+', '-', '*', '/'):
            if s_.fv(n.a) and s_.fv(n.b): return s_.flt(n.a) + ' ' + n.op + ' ' + s_.flt(n.b)
            if n.op in ('+', '-'):
                for pn, other, left in ((s_.prod(n.a), n.b, True), (s_.prod(n.b), n.a, False)):
                    if pn is not None and s_.fv(other):
                        pt = s_.flt(pn.a) + ' * ' + s_.flt(pn.b)
                        return (pt + ' ' + n.op + ' ' + s_.flt(other)) if left else (s_.flt(other) + ' ' + n.op + ' ' + pt)
        return None

def match_close(t, i):
    d = 0
    for j in range(i, len(t)):
        if t[j] == '(': d += 1
        elif t[j] == ')':
            d -= 1
            if d == 0: return j
    return -1

FLT_CAST = re.compile(r'\(float\)\s*\(')
def process(t, env, stats):
    out = []; i = 0
    while True:
        m = FLT_CAST.search(t, i)
        if not m: out.append(t[i:]); break
        op = m.end() - 1; cl = match_close(t, op)
        if cl < 0: out.append(t[i:m.end()]); i = m.end(); continue
        inner = process(t[op + 1:cl], env, stats)
        new = None
        try:
            ctx = Ctx(env, inner); node = parse(inner)
            new = ctx.narrow(node)
        except Fail:
            new = None
        out.append(t[i:m.start()])
        if new is not None:
            out.append('(' + new + ')'); stats['narrowed'] += 1
        else:
            out.append('(float)(' + inner + ')'); stats['kept'] += 1
        i = cl + 1
    return ''.join(out)

DECL = re.compile(r'(?m)^[ \t]*((?:const )?(?:unsigned )?[A-Za-z_]\w*)\s*(\*+)?\s*(\w+)\s*(\[[^\]]*\])?\s*;')
def build_env(chunk):
    env = {}
    k = chunk.find('{')
    head = chunk[:k] if k >= 0 else ''
    body = chunk[k:] if k >= 0 else chunk
    # ANSI parameters and K&R declarations
    for m in re.finditer(r'(?:^|[,(])\s*(float|double)\s*(\*+)?\s*(\w+)', head):
        env[m.group(3)] = m.group(1) + ('*' if m.group(2) else '')
    for m in DECL.finditer(chunk):
        base, star, name, arr = m.groups()
        if base in ('float', 'double'):
            env[name] = base + ('*' if star else ('[]' if arr else ''))
        elif name in env and False: pass
    return env, k

def retype_double_locals(chunk, env):
    """rule A: returns (new_chunk, n)"""
    k = chunk.find('{')
    if k < 0: return chunk, 0
    head, body = chunk[:k], chunk[k:]
    cands = set(m.group(1) for m in re.finditer(r'(?m)^[ \t]*double[ \t]+(dVar\d+);', body))
    if not cands: return chunk, 0
    # every assignment to a candidate (`name = rhs;`), any other write form disqualifies
    asg = {c: [] for c in cands}
    bad = set()
    for c in list(cands):
        for m in re.finditer(r'(?<![\w.])%s\b' % re.escape(c), body):
            pre = body[max(0, m.start() - 3):m.start()]
            post = body[m.end():m.end() + 4]
            if re.match(r'^[ \t]*double[ \t]+$', body[max(0, m.start() - 8):m.start()]): continue          # the declaration
            if re.match(r'\s*=(?!=)', post):
                ls = body.rfind('\n', 0, m.start()) + 1; lead = body[ls:m.start()]
                if lead.strip() and not re.search(r'(\)|\belse|[;{}])\s*$', lead): bad.add(c); break
                q = body.index('=', m.end()); e = body.find(';', q)
                asg[c].append(body[q + 1:e]); continue
            if re.match(r'\s*(\+\+|--|[-+*/]=)', post) or re.search(r'&\s*$', pre): bad.add(c); break
    cands -= bad
    changed = True
    while changed:
        changed = False
        e2 = dict(env)
        for c in cands: e2[c] = 'float'
        for c in list(cands):
            ok = True
            for rhs in asg[c]:
                try:
                    ctx = Ctx(e2, rhs); n = parse(rhs.strip())
                    ctx = Ctx(e2, rhs.strip())
                    if not ctx.fv(n): ok = False; break
                except Fail: ok = False; break
            if not ok: cands.discard(c); changed = True
    cands = {c for c in cands if asg[c]}
    if not cands: return chunk, 0
    for c in sorted(cands):
        body = re.sub(r'(?m)^([ \t]*)double([ \t]+)%s;' % re.escape(c), r'\1float\2%s;' % c, body)
        # uses (not the assignment target) read as double
        def use(m):
            post = body[m.end():m.end() + 4]
            if re.match(r'\s*=(?!=)', post) and re.search(r'(?:^|[;{}\n])[ \t]*$', body[max(0, m.start() - 40):m.start()]) : return m.group(0)
            if re.match(r'^[ \t]*float[ \t]+$', body[max(0, m.start() - 8):m.start()]): return m.group(0)
            return '(double)' + c
        body = re.sub(r'(?<![\w.])%s\b' % re.escape(c), use, body)
    return head + body, len(cands)

def process_function(chunk, stats):
    for _ in range(4):
        env, k = build_env(chunk)
        before = chunk
        if k >= 0:
            chunk = chunk[:k] + process(chunk[k:], env, stats)
        env, k = build_env(chunk)
        chunk, nl = retype_double_locals(chunk, env)
        stats['locals'] += nl
        if chunk == before: break
    return chunk

FUNC_MARK = re.compile(r'(?m)^/\* [^\n]*? @ 0x[0-9a-f]+ \(\d+ bytes\) \*/$')
def process_file(text, stats):
    marks = [m.start() for m in FUNC_MARK.finditer(text)]
    if not marks: return text
    out = [text[:marks[0]]]
    for i, s in enumerate(marks):
        e = marks[i + 1] if i + 1 < len(marks) else len(text)
        chunk = text[s:e]
        try: out.append(process_function(chunk, stats))
        except RecursionError: out.append(chunk)
    return ''.join(out)

if __name__ == '__main__':
    d = sys.argv[1]; stats = {'narrowed': 0, 'kept': 0, 'locals': 0}
    for f in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        t = open(f).read(); t2 = process_file(t, stats)
        if t2 != t: open(f, 'w').write(t2)
    print('narrow_float_ops: %(narrowed)d (float)(..) spans narrowed to float arithmetic, %(kept)d left, %(locals)d double locals retyped float' % stats)
