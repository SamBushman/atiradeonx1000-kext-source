#!/usr/bin/env python3
"""ghidra2c.py DECOMP_DIR OUT_DIR [PART_SIZE] - turn a DecompAll.java dump (one .txt per function + INDEX.tsv) into a compilable C
corpus: OUT_DIR/decls.h (prototypes + data/import declarations), OUT_DIR/part_NNN.c (PART_SIZE functions each, default 60),
OUT_DIR/ledger.tsv (address, size, name, part, status). The function text is unchanged apart from: (1) class/struct-typed
pointer types Ghidra invented become `unsigned char *` (byte arithmetic, as Ghidra models them); (2) comment header removed."""
import sys, os, re, collections
src, out = sys.argv[1], sys.argv[2]
part = int(sys.argv[3]) if len(sys.argv) > 3 else 60
text_ranges = []   # (lo, hi) of code sections: DAT_/LAB_/UNK_ addresses inside them are numeric constants Ghidra mislabels
for arg in sys.argv[4:]:
    lo, hi = arg.split('-'); text_ranges.append((int(lo, 16), int(hi, 16)))
def in_text(hexaddr): return any(lo <= int(hexaddr, 16) < hi for lo, hi in text_ranges)
os.makedirs(out, exist_ok=True)
idx = []
for l in open(os.path.join(src, 'INDEX.tsv')):
    a, sz, name = l.rstrip('\n').split('\t'); idx.append((a, int(sz), name))
idx.sort(key=lambda r: int(r[0], 16))
kw = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'do', 'else', 'case', 'goto', 'const', 'struct', 'union', 'enum', 'typedef', 'extern', 'static'}
PRIM = set('pthread_mutex_t pthread_cond_t pthread_t pthread_key_t pthread_once_t pid_t dword time_t off_t mode_t uid_t gid_t int3 uint3 MACH_HEADER_t undefined undefined1 undefined2 undefined3 undefined4 undefined8 uint ulong ushort uchar byte bool longlong ulonglong char short int long unsigned signed void float double code size_t'.split())
bodies = {}; defined = {}
for a, sz, name in idx:
    t = open(os.path.join(src, a + '.txt')).read()
    lines = t.split('\n')
    body = '\n'.join(l for l in lines if not l.startswith('//'))
    body = re.sub(r'/\*.*?\*/', lambda m: '', body, flags=re.S)
    if '!! decompile failed' in body: bodies[a] = None; continue
    bodies[a] = body.strip('\n') + '\n'
# collect referenced tokens
defined_names = {name for a, sz, name in idx}
allbody = '\n'.join(b for b in bodies.values() if b)
data_syms = sorted(set(re.findall(r'(?<![A-Za-z0-9])_?(?:DAT|UNK|PTR|EXT)_[0-9a-f]{8}\b|\b(?:PTR_)?(?:s|u|PTR)_[A-Za-z_0-9]*_[0-9a-f]{8}\b|\bPTR_[A-Za-z_0-9]+_[0-9a-f]{8}\b', allbody)))
data_syms = [d for d in data_syms if not (re.search(r'_([0-9a-f]{8})$', d) and in_text(re.search(r'_([0-9a-f]{8})$', d).group(1)) and not d.startswith('PTR_'))]
calls = set(re.findall(r'\b([A-Za-z_][A-Za-z_0-9]*)\s*\(', allbody))
imports = sorted(c for c in calls if c not in kw and c not in defined_names and c not in PRIM and not re.match(r'^(CONCAT|SUB|ZEXT|SEXT|sync|instructionSynchronize|dataCache|enforce|trap|halt)', c) and c not in data_syms)
# return types of defined functions: text before the name on its definition line(s)
def ret_type(body, name):
    m = re.search(r'^(.*?)\b' + re.escape(name) + r'\s*\(', body, flags=re.M | re.S)
    return (m.group(1).strip() if m else 'int') or 'int'
def fix_types(s):
    """class/struct-typed pointer types Ghidra invented -> unsigned char * (only in type positions: casts, declarations, params)"""
    def isty(t): return t not in PRIM and t not in kw
    s = re.sub(r'\(\s*(?:const\s+)?([A-Za-z_]\w*)((?: \*)+)\s*\)', lambda m: '(unsigned char' + m.group(2) + ')' if isty(m.group(1)) else m.group(0), s)
    s = re.sub(r'(?m)^(\s*)(?:const\s+)?([A-Za-z_]\w*)((?: \*)+)([A-Za-z_]\w*)', lambda m: m.group(1) + 'unsigned char' + m.group(3) + m.group(4) if isty(m.group(2)) else m.group(0), s)
    s = re.sub(r'([(,]\s*)(?:const\s+)?([A-Za-z_]\w*)((?: \*)+)([A-Za-z_]\w*)(?=\s*[,)\[])', lambda m: m.group(1) + 'unsigned char' + m.group(3) + m.group(4) if isty(m.group(2)) else m.group(0), s)
    return s
SMALL = re.compile(r'\b(byte|uchar|char|short|ushort|bool|undefined1|undefined2|undefined)\b(?!\s*\*)')
def split_header(body, name):
    i = body.index('{')
    head = body[:i]
    m = re.search(r'^(.*?)\b' + re.escape(name) + r'\s*\((.*)\)\s*$', head.strip(), flags=re.S)
    if not m: return None
    return m.group(1).strip(), m.group(2).strip()
def split_params(sp):
    out, d, cur = [], 0, ''
    for ch in sp:
        if ch in '([': d += 1
        if ch in ')]': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur.strip())
    return out
proto = {}
for a, sz, name in idx:
    b = bodies.get(a)
    if not b: continue
    h = split_header(b, name)
    if not h: continue
    rt, params = h
    exact = bool(re.search(r'\b(float|double)\b(?!\s*\*)', rt + ' ' + params))
    if exact: proto[a] = (fix_types(rt + ' ').strip(), fix_types(params + ' ').strip(), True)
    else:
        nrt = 'int' if not re.search(r'\b(longlong|ulonglong|undefined8)\b(?!\s*\*)', rt) else fix_types(rt + ' ').strip()
        nparams = SMALL.sub('int', params)
        proto[a] = (nrt, fix_types(nparams + ' ').strip(), False)
        # rewrite the definition header
        i = b.index('{')
        pl = [] if nparams in ('void', '') else split_params(fix_types(nparams + ' ').strip())
        names = []; decl = []
        for p_ in pl:
            mm = re.match(r'^(.*?)(\w+)((?:\s*\[[^\]]*\])*)$', p_.strip())
            if not mm: names = None; break
            names.append(mm.group(2)); decl.append('  %s%s%s;' % (mm.group(1), mm.group(2), mm.group(3)) if not mm.group(1).strip().endswith('*') else '  %s%s%s;' % (mm.group(1), mm.group(2), mm.group(3)))
        if names is None: bodies[a] = nrt + ' ' + name + '(' + fix_types(nparams + ' ').strip() + ')\n\n' + b[i:]
        else: bodies[a] = nrt + ' ' + name + '(' + ', '.join(names) + ')\n' + '\n'.join(decl) + ('\n' if decl else '') + b[i:]
decls = ['#include "ghidra_c.h"', '']
exact_fns = {name: a for a, (rt, params, exact) in [(a, proto[a]) for a in proto] for a2, sz2, name in idx if a2 == a and exact}
for a, sz, name in idx:
    if a in proto:
        rt, params, exact = proto[a]
        decls.append('extern %s %s(%s);' % (rt, name, params) if exact else 'extern %s %s();' % (rt, name))
for n in imports: decls.append('extern int %s();' % n)
called_data = set(re.findall(r'\(\s*\*\s*\(?\s*(?:\(code \*\))?\s*([A-Za-z_]\w*)\s*\)\s*\)?\s*\(', allbody))
deref = set(re.findall(r'(?<![\w)\]])\*\s*\(?\s*([A-Za-z_]\w*)\b', allbody)) | set(re.findall(r'\b([A-Za-z_]\w*)\s*\[', allbody)) | set(re.findall(r'\(\s*[\w ]+\*+\s*\)\s*\*\s*([A-Za-z_]\w*)', allbody))
tables = set(re.findall(r'\(&\s*([A-Za-z_]\w*)\s*\)\s*\[', allbody))
for d in data_syms:
    if d in tables: decls.append('extern unsigned char *%s[];' % d)
    elif d in called_data: decls.append('extern int (*%s)();' % d)
    elif d in deref: decls.append('extern unsigned char *%s;' % d)
    else: decls.append('extern unsigned char %s;' % d)
if re.search(r'\bMACH_HEADER\b', allbody): decls.append('extern MACH_HEADER_t MACH_HEADER;')
ftab = set(re.findall(r'\(\s*((?:FLOAT|DOUBLE)_[0-9a-f]{8})\s*\)\s*\[', allbody)) | set(re.findall(r'\b((?:FLOAT|DOUBLE)_[0-9a-f]{8})\s*\[', allbody)) | tables
for f in sorted(set(re.findall(r'\bFLOAT_[0-9a-f]{8}\b', allbody))): decls.append('extern float %s%s;' % (f, '[]' if f in ftab else ''))
for f in sorted(set(re.findall(r'\bDOUBLE_[0-9a-f]{8}\b', allbody))): decls.append('extern double %s%s;' % (f, '[]' if f in ftab else ''))
open(os.path.join(out, 'decls.h'), 'w').write('\n'.join(decls) + '\n')
def fix_arrays(b):
    """Ghidra declares stack pieces as arrays but the code treats them as scalars, indexes past the declared bound (the array runs
    over the following stack variables), or stores 4-byte pieces into byte arrays."""
    # (0) arrays indexed past their declared bound: absorb the contiguous run of stack variables that follows them
    decl_rx = r'(?m)^\s*([A-Za-z_][\w ]*?)[\s*]+(\w*(?:local|Stack)_([0-9a-f]+))\s*(?:\[\s*(\d+)\s*\])?;'
    for m in list(re.finditer(decl_rx, b)):
        if m.group(4) is None: continue
        nm, off, cnt = m.group(2), int(m.group(3), 16), int(m.group(4))
        ty = m.group(1).strip()
        if ty not in ('undefined4', 'uint', 'int', 'ulong', 'long', 'undefined *', 'undefined **', 'code *', 'float', 'unsigned int'): continue
        rest = b[:m.start()] + b[m.end():]
        ix = re.findall(r'(?<![&\w.])\(?\s*%s\s*\)?\s*\[\s*([^\]]+)\]' % re.escape(nm), rest)
        lit_over = any(re.fullmatch(r'\d+|0x[0-9a-f]+', i.strip()) and int(i.strip(), 0) >= cnt for i in ix)
        var_idx = any(not re.fullmatch(r'\d+|0x[0-9a-f]+', i.strip()) for i in ix)
        if not ix or not (lit_over or (var_idx and cnt == 1)): continue
        total = cnt
        while True:
            cand = off - 4 * total
            m2 = None
            for mm in re.finditer(decl_rx, b):
                if int(mm.group(3), 16) == cand and mm.group(2) != nm: m2 = mm; break
            if not m2: break
            n2 = m2.group(2); c2 = int(m2.group(4)) if m2.group(4) else None
            if m2.group(1).strip() not in ('undefined4', 'uint', 'int', 'ulong', 'long', 'float', 'undefined *', 'unsigned int', 'code *'): break
            span = c2 if c2 else 1
            # drop the absorbed declaration first, then rename its uses
            b = b.replace(m2.group(0), '', 1)
            if c2:
                b = re.sub(r'(?<![\w.])%s\s*\[\s*(\d+)\s*\]' % re.escape(n2), lambda z: '%s[%d]' % (nm, total + int(z.group(1))), b)
                b = re.sub(r'(?<![\w.])%s\s*\[' % re.escape(n2), '(%s + %d)[' % (nm, total), b)
                b = re.sub(r'(?<![\w.&])%s\b(?!\s*\[)' % re.escape(n2), '(%s + %d)' % (nm, total), b)
            else:
                b = re.sub(r'(?<![\w.])%s\b(?!\s*\[)' % re.escape(n2), '%s[%d]' % (nm, total), b)
            total += span
        if total != cnt:
            b = re.sub(r'(?m)^(\s*)([A-Za-z_][\w ]*?)([\s*]+)%s\s*\[\s*%d\s*\];' % (re.escape(nm), cnt), lambda z: '%s%s%s%s[%d];' % (z.group(1), z.group(2), z.group(3), nm, total), b, count=1)
        # scalar uses of the array name -> element 0
        b = re.sub(r'&\s*\(\s*%s\s*\)' % re.escape(nm), '&(%s[0])' % nm, b)
        b = re.sub(r'(?<![&\w.])%s\b(?!\s*\[)(?!\s*\)\s*\[)' % re.escape(nm), '%s[0]' % nm, b)
    # (1) one-element arrays used as scalars
    for um in list(re.finditer(r'(?m)^\s*([A-Za-z_][\w ]*?)[\s*]+(\w+)\s*\[\s*1\s*\];', b)):
        nm = um.group(2)
        if re.search(r'(?<![&\w.])%s\s*\)?\s*\[\s*[^0\]]' % re.escape(nm), b[:um.start()] + b[um.end():]): continue   # genuinely indexed beyond element 0
        m2 = re.search(r'(?m)^\s*([A-Za-z_][\w ]*?)[\s*]+%s\s*\[\s*1\s*\];' % re.escape(nm), b)
        if not m2: continue
        ty = m2.group(1).strip()
        b = b.replace(m2.group(0), '  %s %s;' % (ty, nm), 1)
        b = re.sub(r'(?<![\w.])%s\s*\[\s*0\s*\]' % re.escape(nm), nm, b)
        b = re.sub(r'\(%s\)\s*\[\s*0\s*\]' % re.escape(nm), nm, b)
    # (2) byte-array locals that are stored to as 4-byte pieces: `NAME = (unsigned int)(...)` -> `*(unsigned int *)NAME = ...`
    for am in list(re.finditer(r'(?m)^\s*(?:char|byte|undefined1?|uchar)\s+([A-Za-z_]\w*)\s*\[\s*\d+\s*\];', b)):
        nm = am.group(1)
        b = re.sub(r'(?m)^(\s*)%s\s*=\s*\((unsigned int|unsigned short)\)' % re.escape(nm), lambda m: '%s*(%s *)%s = (%s)' % (m.group(1), m.group(2), nm, m.group(2)), b)
        b = re.sub(r'(?m)^(\s*)%s\s*=\s*(\(\*\((?:unsigned int|unsigned short) \*\))' % re.escape(nm), lambda m: '%s*(unsigned int *)%s = %s' % (m.group(1), nm, m.group(2)), b)
    b = re.sub(r'(?m)^(\s*p\w+ = (?:\(\w+ \*\))?)((?:local|\w*Stack)_[0-9a-f]+)\[0\];', r'\1\2;', b)   # array decay (pointer to the buffer), not element 0
    return b

led = []
funcs = [(a, sz, name) for a, sz, name in idx]
for pi in range(0, len(funcs), part):
    chunk = funcs[pi:pi + part]; pn = 'part_%03d' % (pi // part)
    samepart = [n for a_, sz_, n in chunk if bodies.get(a_)]
    with open(os.path.join(out, pn + '.c'), 'w') as f:
        f.write('#include "decls.h"\n\n')
        for a, sz, name in chunk:
            b = bodies.get(a)
            if b is None: led.append((a, sz, name, pn, 'DECOMPILE-FAILED')); continue
            f.write('/* %s @ %s (%d bytes) */\n' % (name, a, sz))
            labels = set(re.findall(r'^\s*(LAB_[0-9a-f]+):', b, flags=re.M)) | set(re.findall(r'^(switchD_\w+):', b, flags=re.M))
            def fixgoto(m):
                return m.group(0) if m.group(1) in labels else 'return ((int (*)())0x%s)();   /* Ghidra: jump to a label inside another function */' % m.group(1)[4:].lstrip('0').rjust(1, '0') if m.group(1).startswith('LAB_') else m.group(0)
            b = re.sub(r'\bgoto (LAB_[0-9a-f]+|switchD_\w+);', fixgoto, b)
            b = re.sub(r'(?m)^(\s*(?:LAB_[0-9a-f]+|switchD_\w+):)(\s*\n\s*\})', r'\1 ;\2', b)
            b = re.sub(r'(?m)^(\s*(?:case [^:\n]+|default):)(\s*\n\s*\})', r'\1 ;\2', b)
            b = re.sub(r'\(code\)', '(code *)', b)
            for tn in ftab: b = re.sub(r'(?<![\w&])%s\b(?!\s*\[)(?!\s*\)\s*\[)' % tn, '%s[0]' % tn, b)
            b = re.sub(r'(?m)^(\s*)char (ac\w+)\s*\[\s*\d+\s*\];(?=(?:.|\n)*^\s*\2 = (?:ac|&)\w+;)', r'\1char *\2;', b)
            b = re.sub(r'\b_(local_[0-9a-f]+)\b', r'\1', b)
            # array-declared locals that Ghidra assigns as scalars/pointers
            for am in re.finditer(r'(?m)^\s*(?:char|byte|undefined1?|uchar|short|ushort)\s+([A-Za-z_]\w*)\s*\[\s*\d+\s*\];', b):
                nm = am.group(1)
                if re.search(r'(?m)^\s*%s\s*=\s*(?:&?[A-Za-z_(]|\()' % re.escape(nm), b) and not re.search(r'\b%s\s*\[' % re.escape(nm), b):
                    b = re.sub(r'(?m)^(\s*)(?:char|byte|undefined1?|uchar|short|ushort)\s+%s\s*\[\s*\d+\s*\];' % re.escape(nm), r'\1unsigned char *%s;' % nm, b)
            # scalar-declared locals used as arrays -> arrays sized to the gap to the next stack variable
            offs = {}
            for om in re.finditer(r'\b(\w*?(?:local|Stack)_?)([0-9a-f]{1,8})\b', b):
                pass
            for sm in re.finditer(r'(?m)^\s*(unsigned char|char|byte|undefined1|undefined2|undefined4|undefined8|uint|int|ushort|short|ulong|long|float|double|longlong|ulonglong|undefined)\s+(\w*(?:local|Stack)_([0-9a-f]+))\s*;', b):
                nm = sm.group(2)
                if re.search(r'(?<![\w.])\(?\s*%s\s*\)?\s*\[' % re.escape(nm), b):
                    o = int(sm.group(3), 16)
                    others = [int(x, 16) for x in re.findall(r'\b\w*(?:local|Stack)_([0-9a-f]+)\b', b) if int(x, 16) < o]
                    gap = (o - max(others)) if others else 64
                    esz = {'char': 1, 'byte': 1, 'undefined1': 1, 'unsigned char': 1, 'undefined': 1, 'short': 2, 'ushort': 2, 'undefined2': 2, 'double': 8, 'longlong': 8, 'ulonglong': 8, 'undefined8': 8}.get(sm.group(1), 4)
                    cnt = max(1, gap // esz)
                    b = re.sub(r'(?m)^(\s*)%s\s+%s\s*;' % (re.escape(sm.group(1)), re.escape(nm)), r'\1%s %s[%d];' % (sm.group(1), nm, cnt), b, count=1)
            b = re.sub(r'\(\s*(?:undefined1|char|byte|undefined|uchar)\s+\[(\d)\]\s*\)', lambda m: '(%s)' % {'1': 'unsigned char', '2': 'unsigned short', '4': 'unsigned int', '8': 'unsigned long long'}.get(m.group(1), 'unsigned int'), b)
            b = re.sub(r'\(&\s*([A-Za-z_]\w*)\s*\)\s*\[', lambda m: '(%s)[' % m.group(1) if m.group(1) in tables else m.group(0), b)
            b = re.sub(r'\b([a-z]{1,2})Ram([0-9a-f]{8})\b', lambda m: '(*(%s *)0x%s)' % ({'u': 'unsigned int', 'i': 'int', 'b': 'unsigned char', 'c': 'char', 's': 'short', 'us': 'unsigned short', 'p': 'unsigned char *', 'd': 'double', 'f': 'float', 'l': 'long long', 'ul': 'unsigned long long'}.get(m.group(1), 'unsigned int'), m.group(2)), b)
            b = re.sub(r'\bregister0x[0-9a-f]{8}\b', '((unsigned int)__builtin_frame_address(0))', b)
            b = re.sub(r'&\s*(?:LAB|DAT|UNK)_([0-9a-f]{8})\b', lambda m: '((unsigned char *)0x%s)' % m.group(1) if in_text(m.group(1)) else m.group(0), b)
            b = re.sub(r'\(\s*(?:DAT|UNK)_([0-9a-f]{8})\s*\)\s*\[', lambda m: ('((unsigned char *)0x%s)[' % m.group(1)) if in_text(m.group(1)) else m.group(0), b)
            b = re.sub(r'\(float\)\(\(unsigned char \*\)(0x[0-9a-f]+)\)', r'(float)\1', b)
            b = re.sub(r'\b(?:DAT|UNK)_([0-9a-f]{8})\s*\[', lambda m: ('((unsigned char *)0x%s)[' % m.group(1)) if in_text(m.group(1)) else m.group(0), b)
            b = re.sub(r'\b(?:LAB|DAT|UNK)_([0-9a-f]{8})\b', lambda m: '(*(unsigned char *)0x%s)' % m.group(1) if in_text(m.group(1)) and m.group(0).startswith(('DAT', 'UNK')) else m.group(0), b)
            b = re.sub(r'(?<![\w.>])(%s)\s*\[' % '|'.join(re.escape(n) for n in defined_names) if defined_names else 'x^', lambda m: '((code **)%s)[' % m.group(1), b)
            declared_ = set(re.findall(r'(?m)^\s*[A-Za-z_][\w ]*?[\s*]+(\w+)\s*(?:\[[^\]]*\])?\s*;', b))
            b = re.sub(r'\b_?([a-z]{1,2})Stack([0-9a-f]{8})\b', lambda m: m.group(0) if m.group(0) in declared_ else '(*(%s *)(*(unsigned int *)__builtin_frame_address(0) + 0x%s))' % ({'b': 'unsigned char', 'c': 'char', 'u': 'unsigned int', 'i': 'int', 's': 'short', 'us': 'unsigned short', 'p': 'unsigned char *', 'd': 'double', 'f': 'float', 'l': 'long long'}.get(m.group(1), 'unsigned int'), m.group(2).lstrip('0') or '0'), b)
            b = re.sub(r'\bstack0x([0-9a-f]{8})\b', lambda m: m.group(0) if m.group(0) in declared_ else 'STACKARG(0x%s)' % m.group(1).lstrip('0').rjust(1, '0'), b)
            b = re.sub(r'\((STACKARG\(0x[0-9a-f]+\))\)\s*\[', r'((unsigned int *)\1)[', b)
            b = re.sub(r'\b([A-Za-z_]\w*(?:\[[^\]]*\])?(?:\.[A-Za-z_]\w*)*)\._(\d+)_(\d+)_', lambda m: '(*(%s *)((unsigned char *)&(%s) + %s))' % ({'1': 'unsigned char', '2': 'unsigned short', '4': 'unsigned int', '8': 'unsigned long long'}.get(m.group(3), 'unsigned int'), m.group(1), m.group(2)), b)
            k_ = b.index('{'); head_, rest_ = b[:k_], b[k_:]
            for nm in exact_fns:
                if nm in rest_: rest_ = re.sub(r'(?<![\w.>])%s\s*\(' % re.escape(nm), '((%s (*)())%s)(' % (proto[exact_fns[nm]][0], nm), rest_)
            for nm in samepart:
                if nm in rest_: rest_ = re.sub(r'(?<![\w.>])%s\s*\(' % re.escape(nm), '((int (*)())%s)(' % nm, rest_)
            b = head_ + rest_
            f.write(fix_arrays(fix_types(b)) + '\n')
            led.append((a, sz, name, pn, 'converted'))
with open(os.path.join(out, 'ledger.tsv'), 'w') as f:
    for r in led: f.write('\t'.join(map(str, r)) + '\n')
print(len(funcs), 'functions,', len(imports), 'imports,', len(data_syms), 'data symbols,', (len(funcs) + part - 1) // part, 'parts')
