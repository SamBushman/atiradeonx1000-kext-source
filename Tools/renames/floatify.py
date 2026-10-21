#!/usr/bin/env python3
"""floatify.py FILE [FILE...] - make the float arithmetic of a Ghidra port compile like the shipped code.

Ghidra renders every single-precision PowerPC FP instruction (fadds, fmuls, fsubs, int->float via xoris/fsubs ...) as `(double)(float)(a op b)` over variables it declares `double`.
gcc 4.0.1 compiles that literally: a DOUBLE add followed by frsp (and fmr copies of the widened value) - 2-3x the instructions of the one `fadds` the shipped code has.
The same value computed in `float` arithmetic is bit-identical (double rounding of + - * / from 53 to 24 bits is innocuous, p >= 2q+2), so:
  * `double NAME;` declarations whose every assignment is float-valued become `float NAME;`; the int->float bias constants (signedIntBias, intToFloatBias...) go away,
  * `(double)(float)(E)` -> `(E)`, `(double)FLOAT_xxxx` -> `FLOAT_xxxx`, `(double)floatVar` -> `floatVar`,
  * `(double)CONCAT44d(0x43300000, E ^ 0x80000000) - BIAS` (the signed int->double idiom) -> `(double)(SInt32)(E)`, and `(float)(that)` -> `(float)(SInt32)(E)`.
The difftest (exact bit comparison of every stored float) is the gate; run it, then compare fadds/fmuls/fsubs/frsp counts with the shipped disassembly.
Usage: floatify.py [--keep NAME,NAME] FILE...   (--keep: variables that must stay double)
"""
import re, sys

def find_close(s, i):                       # s[i] == '(' -> index of the matching ')'
    d = 0
    for j in range(i, len(s)):
        if s[j] == '(': d += 1
        elif s[j] == ')':
            d -= 1
            if d == 0: return j
    raise ValueError('unbalanced at %d' % i)

def unwrap_double_float(s):
    """(double)(float)(X) -> (X) ; (double)(float)ident -> ident"""
    pat = '(double)(float)'
    while True:
        i = s.find(pat)
        if i < 0: return s
        j = i + len(pat)
        if s[j] == '(':
            k = find_close(s, j); s = s[:i] + s[j:k + 1] + s[k + 1:]
        else:
            m = re.match(r'[\w\.]+', s[j:]); s = s[:i] + m.group(0) + s[j + len(m.group(0)):]

SBIAS_VALUES = {'DOUBLE_0004c3a8', '4503601774854144.0'}      # 2^52 + 2^31: signed idiom
UBIAS_VALUES = {'DOUBLE_0004c3b0', '4503599627370496.0'}      # 2^52: unsigned idiom
CAT = re.compile(r'\(\s*double\)\s*CONCAT44d\(')
def bias_kinds(s):
    """name -> 'S'/'U' for the literals/DOUBLE_ names themselves, plus (list of (pos, kind)) for every variable the file assigns a bias constant to"""
    k = {v: 'S' for v in SBIAS_VALUES}; k.update({v: 'U' for v in UBIAS_VALUES})
    asg = {}
    for m in re.finditer(r'\b(\w+) = (DOUBLE_[0-9a-f]+|4503601774854144\.0|4503599627370496\.0);', s):
        if m.group(2) in k: asg.setdefault(m.group(1), []).append((m.start(), k[m.group(2)]))
    return k, asg
def kind_at(kinds, name, pos):
    k, asg = kinds
    if name in k: return k[name]
    best = None
    for p, kd in asg.get(name, []):
        if p < pos: best = kd
    return best if best else (asg[name][0][1] if name in asg else None)
def int_idiom(s):
    """(double)CONCAT44d(0x43300000, E ^ 0x80000000) - SBIAS  ->  (double)(SInt32)(E)
       (double)CONCAT44d(0x43300000, E) - SBIAS               ->  (double)(SInt32)(E ^ 0x80000000)   (E was biased by the caller)
       (double)CONCAT44d(0x43300000, E) - UBIAS               ->  (double)(UInt32)(E)                [E may contain parentheses, the text may wrap lines]"""
    kinds = bias_kinds(s)
    out = ''; pos = 0
    while True:
        m0 = CAT.search(s, pos)
        if not m0: return out + s[pos:]
        op = m0.end() - 1
        cl = find_close(s, op)
        inner = s[op + 1:cl]
        rest = s[cl + 1:]
        mi = re.match(r'\s*0x43300000,\s*(.*?)\s*$', inner, re.S)
        mb = re.match(r'\s*-\s*([\w\.]+)', rest)
        kind = kind_at(kinds, mb.group(1), m0.start()) if mb else None
        if not mi or not kind:
            out += s[pos:cl + 1]; pos = cl + 1; continue
        e = mi.group(1); end = mb.end()
        mx = re.match(r'(.*?)\s*\^\s*0x80000000$', e, re.S)
        if mx: kind = 'S'                      # the xor is the signed idiom whatever Ghidra's register reuse says the bias variable holds
        if kind == 'S' and mx: e, ty = mx.group(1), 'SInt32'
        elif kind == 'S': e, ty = '%s ^ 0x80000000' % e, 'SInt32'
        elif kind == 'U' and not mx: ty = 'UInt32'
        else:
            out += s[pos:cl + 1]; pos = cl + 1; continue
        e = re.sub(r'\s+', ' ', e)
        out += s[pos:m0.start()] + '(double)(%s)(%s)' % (ty, e)
        pos = cl + 1 + end

def float_of_int(s):
    """(float)((double)(SInt32)(E)) -> (float)(SInt32)(E)   (balanced)"""
    pos = 0
    while True:
        m = re.compile(r'\(float\)\(\(double\)\((SInt32|UInt32)\)\(').search(s, pos)
        if not m: return s
        p = m.start() + len('(float)')            # '(' of the outer group
        cl = find_close(s, p)
        inner = s[p + 1:cl]                        # (double)(T)(E)
        mm = re.match(r'\(double\)\((SInt32|UInt32)\)(\(.*\))$', inner, re.S)
        if mm:
            try: ok = find_close(inner, inner.index(')(') + 1) == len(inner) - 1 if False else find_close(mm.group(2), 0) == len(mm.group(2)) - 1
            except ValueError: ok = False
            if ok:
                s = s[:m.start()] + '(float)(%s)%s' % (mm.group(1), mm.group(2)) + s[cl + 1:]
                pos = m.start() + 1; continue
        pos = m.end()

def run(path, keep):
    s = open(path).read()
    decl = re.findall(r'^\s*double (\w+);', s, re.M)
    floats = [v for v in decl if v not in keep and v not in bias_kinds(s)[1]]
    kinds0 = bias_kinds(s)
    bias = [v for v in decl if v in kinds0[1]]
    s = int_idiom(s)
    s = float_of_int(s)
    s = unwrap_double_float(s)
    s = re.sub(r'\(double\)(FLOAT_\w+)', r'\1', s)
    for v in floats:
        s = re.sub(r'^(\s*)double %s;' % v, r'\1float %s;' % v, s, flags=re.M)
        s = re.sub(r'\(double\)%s\b' % v, v, s)
    allf = set(floats) | set(re.findall(r'^\s*float (\w+);', s, re.M))
    for v in allf:
        s = re.sub(r'\(double\)%s\b' % v, v, s)
    for v in bias:
        s = re.sub(r'^\s*double %s;\n' % v, '', s, flags=re.M)
        s = re.sub(r'^\s*%s = (?:DOUBLE_\w+|[\d.]+);\n' % v, '', s, flags=re.M)
    # (double)floatVar for float variables not declared via a plain decl (members, params) is left alone
    open(path, 'w').write(s)
    left = len(re.findall(r'CONCAT44d|\(double\)\(float\)', s))
    print(path, 'floats:', len(floats), 'bias dropped:', len(bias), 'idiom leftovers:', left)

if __name__ == '__main__':
    a = sys.argv[1:]; keep = set()
    if a and a[0] == '--keep': keep = set(a[1].split(',')); a = a[2:]
    for p in a: run(p, keep)
