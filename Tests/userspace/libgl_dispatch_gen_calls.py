#!/usr/bin/env python3
"""libgl_dispatch_gen_calls.py GL_HEADER... > dsp_calls.c - one typed call per gl* prototype found in the headers (`extern RET glName (PARAMS);`), each with sentinel arguments that
depend on the parameter's position and type and on a SEED (libgl_dispatch_test.c): the table `dsp_table` = {name, caller(void *fn, int seed)}."""
import sys, re
protos = {}
for h in sys.argv[1:]:
    t = re.sub(r'/\*.*?\*/', '', open(h, errors='replace').read(), flags=re.S)
    for m in re.finditer(r'\bextern\s+([\w\s\*]+?)\s*\b(gl\w+)\s*\(([^;{}]*)\)\s*;', t):
        ret, name, params = m.group(1).strip(), m.group(2), m.group(3).strip()
        if name.endswith('ProcPtr') or 'Proc' in name and name.endswith('Ptr'): continue
        protos.setdefault(name, (ret, params))
FLOAT = ('GLfloat', 'GLclampf'); DOUBLE = ('GLdouble', 'GLclampd'); BYTE = ('GLboolean', 'GLbyte', 'GLubyte'); SHORT = ('GLshort', 'GLushort')
import json
print('#include <OpenGL/gl.h>\n#include <OpenGL/glext.h>\n#include <string.h>\ntypedef struct { const char *name; void (*call)(void *, const int *, const double *); } dsp_entry;')
names = []; PROTO = {}
for name, (ret, params) in sorted(protos.items()):
    ps = [] if params in ('void', '') else [p.strip() for p in re.split(r',(?![^(]*\))', params)]
    types = []; args = []; classes = []
    for k, p in enumerate(ps):
        if '(' in p: types = None; break                       # a function-pointer parameter: not generated
        if p == '...': types = None; break
        m = re.match(r'^(.*?)(\w+)?$', p.strip()); decl = p
        base = re.sub(r'\b(const|struct)\b', '', re.sub(r'\[.*?\]', '*', p))
        is_ptr = '*' in base or '[' in p
        tname = re.sub(r'\bconst\b', '', p.replace('*', ' ')).split()
        tn = next((w for w in tname if w.startswith('GL') or w in ('void', 'int', 'unsigned', 'char', 'float', 'double', 'long')), 'GLint')
        # the type text without the parameter name: strip a trailing identifier that is not a type keyword
        tt = re.sub(r'\s*\b\w+\s*(\[.*?\])?\s*$', '', p) if re.search(r'\b\w+\s*(\[.*?\])?\s*$', p) and len(p.split()) > 1 and not re.match(r'^(const\s+)?\w+\s*\*+\s*$', p) else p
        if p.strip() in ('void',): tt = 'void'
        if '[' in p: tt = re.sub(r'\s*\b\w+\s*\[.*?\]\s*$', '', p) + ' *'
        if is_ptr: a = '(%s)I[%d]' % (tt, k + 32)
        elif tn in FLOAT: a = '(%s)D[%d]' % (tt, k)
        elif tn in DOUBLE: a = '(%s)D[%d]' % (tt, k + 32)
        elif tn in BYTE: a = '(%s)I[%d]' % (tt, k + 64)
        elif tn in SHORT: a = '(%s)I[%d]' % (tt, k + 96)
        else: a = '(%s)I[%d]' % (tt, k)
        types.append(tt); args.append(a); classes.append('p' if is_ptr else 'f' if tn in FLOAT else 'd' if tn in DOUBLE else 'i')
    if types is None: continue
    names.append(name); PROTO[name] = ''.join(classes)
    print('static void call_%s(void *f, const int *I, const double *D) { ((%s (*)(%s))f)(%s); }' % (name, ret, ', '.join(types) or 'void', ', '.join(args)))
print('dsp_entry dsp_table[] = {')
for n in names: print('  { "%s", call_%s },' % (n, n))
print('  { 0, 0 } };')

if len(sys.argv) > 0: open('dsp_protos.json', 'w').write(json.dumps(PROTO))
