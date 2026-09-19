#!/usr/bin/env python3
"""ghidra2cpp.py DECOMPILE.txt [options] > body.cpp

Mechanical port of a Ghidra PPC decompile (from Tools' DecompAt2 dumps) to compilable C++ that keeps the decompile's
exact arithmetic and control flow. The output is the function BODY (declarations + statements, without the braces)
written against the helpers in Headers/GhidraCompat.h:
    M<T>(addr)                 *(T *)addr                       (typed memory access at a byte address)
    VCALL(vtable, off)(args)   (**(code **)(vtable + off))(args) (raw vtable dispatch)
    CONCAT44d(hi, lo)          the double whose bits are hi:lo   (the shipped int/uint -> double idiom)
    FBITS(f)                   the 32 bits of a float            (a float stored into an undefined4 slot)
Class-typed pointers become UInt8 * (Ghidra models the classes as 1-byte objects, so `p + 0x10` is byte arithmetic);
qualified member calls `Class::m(obj, ...)` become `((Class *)(obj))->m(...)`.

Options:
  --self NAME       the decompile's name for `this` (default: this); it is renamed to `self`
  --members a,b     unqualified own-class method names (`name(this, ...)` -> `((Cls *)this)->name(...)`)
  --class CLS       the own class for --members
  --fun FUN_0001=expr  replace `FUN_0001(` by `expr(`   (repeatable)
  --sym FROM=TO     plain textual replacement (repeatable)
"""
import re, sys, argparse

ap = argparse.ArgumentParser()
ap.add_argument('src')
ap.add_argument('--self', dest='selfname', default='this')
ap.add_argument('--members', default='')
ap.add_argument('--class', dest='cls', default='')
ap.add_argument('--fun', action='append', default=[])
ap.add_argument('--sym', action='append', default=[])
ap.add_argument('--keep-header', action='store_true')
ap.add_argument('--exact-types', action='store_true', help='Ghidra uint -> unsigned int, int -> int (they mangle differently from UInt32/SInt32 = unsigned long/long here)')
ap.add_argument('--asic', default='', help='comma list: replacements for successive `_ASICSupportsAGP` occurrences (Ghidra labels every zero-immediate data reloc that way)')
args = ap.parse_args()

# PPC lwarx/stwcx. loops: Ghidra prints them as a do/while around storeWordConditionalIndexed - rewrite to the intrinsic
_A = re.compile(r"do \{\s*(?P<x>\w+) = \*(?P<p>\w+);\s*if \(in_RESERVE != '\\0'\) \{\s*(?P<y>\w+) = storeWordConditionalIndexed\((?P=x) \+ (?P<k>-?(?:0x[0-9a-f]+|\d+)),0,(?P=p)\);\s*\*(?P=p) = (?P=y);\s*in_cr0 = 2;\s*\}\s*\} while \(!\(bool\)\(in_cr0 >> 1 & 1\)\);")
_B = re.compile(r"do \{\s*if \(in_RESERVE != '\\0'\) \{\s*(?P<y>\w+) = storeWordConditionalIndexed\(\*(?P<p>\w+) \+ (?P<k>-?(?:0x[0-9a-f]+|\d+)),0,(?P=p)\);\s*\*(?P=p) = (?P=y);\s*in_cr0 = 2;\s*\}\s*\} while \(!\(bool\)\(in_cr0 >> 1 & 1\)\);")
def _atom_a(m): return '%s = atomicAddReturningOld((SInt32 *)%s, %s);' % (m.group('x'), m.group('p'), m.group('k'))
def _atom_b(m): return 'atomicAddReturningOld((SInt32 *)%s, %s);' % (m.group('p'), m.group('k'))
text = open(args.src).read()
text = _A.sub(_atom_a, text)
text = _B.sub(_atom_b, text)
assert 'storeWordConditionalIndexed' not in text, 'unhandled lwarx/stwcx. idiom in ' + args.src
# strip comments and the dump header
text = re.sub(r'/\*.*?\*/', '', text, flags=re.S)
text = '\n'.join(l for l in text.split('\n') if not l.startswith('//'))
# body = between the first '{' after the signature and the last '}'
first = text.index('{')
last = text.rindex('}')
sig = text[:first]
body = text[first+1:last]

PRIM = {'undefined8': 'UInt64', 'undefined4': 'UInt32', 'undefined2': 'UInt16', 'undefined1': 'UInt8', 'undefined': 'UInt8',
        'uint': 'UInt32', 'ushort': 'UInt16', 'ulong': 'UInt32', 'byte': 'UInt8', 'longlong': 'SInt64', 'ulonglong': 'UInt64',
        'uchar': 'UInt8', 'undefined3': 'UInt32', 'int': 'SInt32', 'short': 'SInt16', 'code': 'code'}

def find_close(s, i):
    """s[i] == '(' -> index of the matching ')'"""
    d = 0
    for j in range(i, len(s)):
        if s[j] == '(':
            d += 1
        elif s[j] == ')':
            d -= 1
            if d == 0:
                return j
    raise ValueError('unbalanced at %d: %r' % (i, s[i:i+60]))

def split_args(s):
    out, d, cur = [], 0, ''
    for ch in s:
        if ch in '([':
            d += 1
        elif ch in ')]':
            d -= 1
        if ch == ',' and d == 0:
            out.append(cur.strip()); cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out

# 1. vtable calls: (**(code **)(VT + OFF))(args)  ->  VCALL(VT, OFF)(args)
def conv_vcalls(s):
    key = '(**(code **)('
    i = 0
    while True:
        i = s.find(key, i)
        if i < 0:
            return s
        inner_open = i + len(key) - 1                 # the '(' opening "(VT + OFF)"
        inner_close = find_close(s, inner_open)
        inner = s[inner_open+1:inner_close]
        m = re.match(r'(.*) \+ (0x[0-9a-fA-F]+|\d+)$', inner, flags=re.S)
        after = inner_close + 1                       # the ')' closing "(**(code **)(...))"
        if not m or s[after] != ')':
            i += 1
            continue
        vt, off = m.group(1), m.group(2)
        rest = s[after+1:]
        if rest.startswith('()'):
            # Ghidra prints no arguments for an indirect call whose prototype it does not know; the callee still gets the
            # object (whose vtable was read) in r3, so pass it explicitly
            if vt.startswith('**('):
                obj = vt[1:]
            elif vt.startswith('*(int *)'):
                obj = vt[len('*(int *)'):]
            elif re.match(r'^\*[A-Za-z_]\w*$', vt):
                obj = vt[1:]
            else:
                obj = None
            if obj is not None:
                rest = '(' + obj + ')' + rest[2:]
        s = s[:i] + 'VCALL(%s, %s)' % (vt, off) + rest
        i += 1

# 2. *(T *)(EXPR) / *(T *)name -> M<T *>(EXPR)
TYPE = r'[A-Za-z_][\w:]*(?: [A-Za-z_]\w*)*'
def conv_mem(s):
    pat = re.compile(r'\*\((' + TYPE + r')( \*+)\)')
    pos = 0
    while True:
        m = pat.search(s, pos)
        if not m:
            return s
        # must be a dereference (not multiplication): previous non-space char is not an operand char
        j = m.start() - 1
        while j >= 0 and s[j] == ' ':
            j -= 1
        is_cast_close = False
        if j >= 0 and s[j] == ')':
            d = 0
            for q in range(j, -1, -1):
                if s[q] == ')':
                    d += 1
                elif s[q] == '(':
                    d -= 1
                    if d == 0:
                        inner = s[q+1:j]
                        is_cast_close = re.match(r'^[A-Za-z_][\w ]*[ *]*$', inner) is not None and not re.match(r'^(if|while|for|switch)$', inner.strip())
                        break
        if j >= 0 and (s[j].isalnum() or s[j] in ')]_') and not is_cast_close:
            # `a * (T *)x`: a multiplication by a cast (Ghidra writes derefs after operators, casts and '(' only)
            pos = m.start() + 1
            continue
        k = m.end()
        if k < len(s) and s[k] == '(':
            e = find_close(s, k)
            expr = s[k+1:e]
            end = e + 1
        else:
            m2 = re.match(r'[A-Za-z_]\w*', s[k:])
            if not m2:
                pos = m.start() + 1
                continue
            expr = m2.group(0)
            end = k + len(expr)
        t = (m.group(1).strip() + m.group(2)[:-1]).rstrip()     # `*(T *)x` reads a T; each further star is a pointer-typed read
        s = s[:m.start()] + 'M<%s>(%s)' % (t, expr) + s[end:]
        pos = m.start() + 2

# 3. qualified member calls  Class::m(obj, rest)  and unqualified own-class calls
CLASSES = set('ATIR500SurfaceBuffer ATITextureBufferHeader IOAccelSurfaceReadData sIOGLNewTextureData sIOGLNewTextureReturnData GLKMemoryElement OSObject IOService IOFramebuffer IOMemoryDescriptor IOInterruptEventSource IOTimerEventSource IOWorkLoop OSDictionary OSSerialize IOMemoryMap OSSymbol OSString OSNumber OSData IOBufferMemoryDescriptor IOEventSource IOCommandGate IOPCIDevice IORegistryEntry IOUserClient IOTextureBuffer VendorCommandBuffer VendorTextureBuffer ATIR500Memory pcl_ParamsR500_t _HZDATA ATIRadeonX1000 IOATIR500Accelerator IOATIR500Surface ATIR500Surface IOATIR500Shared IOATIR5002DContext ATIR5002DContext IOATIR500DVDContext ATIR500DVDContext IOATIR500GLContext ATIR500GLContext ATIR500Memory VendorTransferBuffer'.split())
def conv_calls(s):
    pat = re.compile(r'\b(' + '|'.join(sorted(CLASSES, key=len, reverse=True)) + r')::(\w+)\(')
    pos = 0
    while True:
        m = pat.search(s, pos)
        if not m:
            break
        o = m.end() - 1
        e = find_close(s, o)
        a = split_args(s[o+1:e])
        if not a:
            pos = m.end(); continue
        obj, rest = a[0], a[1:]
        obj = re.sub(r'^\(\s*\w+\s*\*\)\s*', '', obj)
        s = s[:m.start()] + '((%s *)(%s))->%s(%s)' % (m.group(1), obj, m.group(2), ', '.join(rest)) + s[e+1:]
        pos = m.start() + 1
    if args.members:
        for name in args.members.split(','):
            pat2 = re.compile(r'(?<![\w>.:])' + re.escape(name) + r'\(')
            pos = 0
            while True:
                m = pat2.search(s, pos)
                if not m:
                    break
                o = m.end() - 1
                e = find_close(s, o)
                a = split_args(s[o+1:e])
                if not a:
                    pos = m.end(); continue
                obj, rest = a[0], a[1:]
                obj = re.sub(r'^\(\s*\w+\s*\*\)\s*', '', obj)
                s = s[:m.start()] + '((%s *)(%s))->%s(%s)' % (args.cls, obj, name, ', '.join(rest)) + s[e+1:]
                pos = m.start() + 1
    return s

# 0. FUN_/sym substitutions first
for f in args.fun:
    a, b = f.split('=>', 1) if '=>' in f else f.split('=', 1)
    body = re.sub(r'\b' + re.escape(a) + r'\(', b + '(', body)
for f in args.sym:
    a, b = f.split('=>', 1) if '=>' in f else f.split('=', 1)
    body = body.replace(a, b)

if args.asic:
    reps = args.asic.split(',')
    parts = body.split('_ASICSupportsAGP')
    assert len(parts) - 1 == len(reps), 'asic occurrences %d vs %d given' % (len(parts) - 1, len(reps))
    body = parts[0] + ''.join(reps[i] + parts[i + 1] for i in range(len(reps)))
body = conv_vcalls(body)

# class-typed pointers -> UInt8 *, class casts on literals dropped
cls_alt = '|'.join(sorted(CLASSES, key=len, reverse=True))
body = re.sub(r'(?<![\w:])(' + cls_alt + r')( \*)', r'UInt8\2', body)
body = re.sub(r'\(\s*(?:' + cls_alt + r')\s*\)\s*(?=0x|\d|\w|\()', '', body)
body = re.sub(r'(?<![\w:])(?:' + cls_alt + r') (\w+);', r'UInt8 \1;', body)   # `ATIR500Surface AVar5;` (a byte-sized object)
body = conv_calls(body)
body = conv_mem(body)
# primitive type names in declarations and casts
def prim(m):
    if args.exact_types and m.group(0) == 'uint': return 'unsigned int'
    return PRIM[m.group(0)]
body = re.sub(r'\b(undefined8|undefined3|undefined4|undefined2|undefined1|undefined|uint|ushort|ulong|byte|longlong|ulonglong|uchar)\b', prim, body)
if not args.exact_types:
    body = re.sub(r'(?<![\w])int(?![\w])(?!\s*\()', 'SInt32', body)            # int -> SInt32 (not `int(`)
body = re.sub(r'(?<![\w])short(?![\w])', 'SInt16', body)
# the decompile's `this`
body = re.sub(r'(?<![\w])' + re.escape(args.selfname) + r'(?![\w])', 'self', body)
# float stores into raw slots: LHS = (float)...;  ->  LHS = FBITS(...)
def fstore(m):
    lhs, rhs = m.group(1), m.group(2)
    if re.match(r'^\s*(fVar|dVar|local_\w+\s*$)', lhs) and '[' not in lhs and 'M<' not in lhs:
        return m.group(0)
    return '%s= FBITS(%s);' % (lhs, rhs)
body = re.sub(r'([^\n;{}=<>!]*?(?:\[[^\]]*\]|M<[^;=]*?>\([^;=]*?\)|\*\w+))\s*=\s*(\(float\)[^;]*);', lambda m: m.group(1) + ' = FBITS(' + m.group(2) + ');', body)
for dat in ('d2d8', 'd2dc', 'd2e0', 'd2e4'):
    body = re.sub(r'M<(?:UInt32|unsigned int)>\(&DAT_0004%s \+ ' % dat, 'FormatTableLookup_0x0004%s(' % dat, body)
body = re.sub(r'CONCAT31\(in_register_\w+,\s*(\w+)\)', r'((UInt32)\1)', body)
body = body.replace('CONCAT44(', 'CONCAT44d(').replace('SUB41(', 'SUB41m(')
body = re.sub(r'(LAB_\w+:)(\s*\})', r'\1 ;\2', body)   # a label must be followed by a statement
sys.stdout.write(body)
