#!/usr/bin/env python3
"""extvs_family.py DIR OUTROWS FN...

The extvsEmit* instruction emitters (EXT_vertex_shader -> hardware program) share one inlined 'reserve a hardware instruction slot' block.  For each FN
(signature (ctx, shader, instRecord)) this names param_1/2/3, and runs chainsplit.py for every placeholder variable with the shared role rules
(hwProgram, instCount -> instSlot chain, newInstArray, bank-conflict result, temp register index, source operand pointers).  Variables with a definition
that matches no role are left alone and listed.  Rows are appended to OUTROWS."""
import sys, os, re, subprocess, tempfile
here = os.path.dirname(os.path.abspath(__file__))
d, out = sys.argv[1:3]
PH = re.compile(r'^(?:[a-z]{0,3}Var\d+|p+_?[A-Za-z]*Var\d+)$')
ROLES = [
 ('conflict', r'FUN_00057af0', 'result of the bank-conflict test (extvsOperandsConflictInBank) of two source operands: non-zero when both read the same register bank'),
 ('hwProgram', r'\*\*\(int \*\*\)\(\*\(int \*\)\(\(\(unsigned char \*\)0x0000118c\)', 'the shader\'s hardware program record, **(int**)(*(ctx+0x118c)*4 + *shader): +0x18 instruction count, +0x1c instruction array, +0x20 capacity in bytes'),
 ('instSlot', r'\* 0x10 \+ \*\(int \*\)\(\w+ \+ 0x1c\)', 'instCount*0x10 + hwProgram[+0x1c]: the 16-byte slot (4 words) of the next hardware instruction'),
 ('instCount', r'^\*\(int \*\)\(\w+ \+ 0x18\)$', 'hwProgram +0x18: number of hardware instruction slots used'),
 ('newInstArray', r'\(\*\*\(code \*\*\)\(param_1 \+ 0xc\)\)', 'result of the ctx allocator callback (+0xc): the grown hardware instruction array that replaces hwProgram[+0x1c]'),
 ('tempIndex', r'FUN_00057b80', 'index of a freshly allocated temporary register (extvsAllocTempSlot)'),
 ('src0Operand', r'^param_3 \+ 0x20$', 'instRecord + 0x20: first source operand of the instruction record'),
 ('src1Operand', r'^\(undefined4 \*\)\(param_3 \+ 0x3c\)$|^param_3 \+ 0x3c$', 'instRecord + 0x3c: second source operand of the instruction record'),
 ('src2Operand', r'^param_3 \+ 0x58$', 'instRecord + 0x58: third source operand of the instruction record'),
 ('symbolList', r'^param_2 \+ 7$', 'shader + 7 words (shader[7]): the shader symbol list'),
]
rf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False)
for n, rx, ev in ROLES: rf.write('%s\t%s\t%s\n' % (n, rx, ev))
rf.close()
for fn in sys.argv[3:]:
    ph = subprocess.run([sys.executable, os.path.join(here, 'ph.py'), d, fn], capture_output=True, text=True).stdout
    vs = []
    for l in ph.splitlines():
        if l.startswith(fn + ':'):
            vs = [t.rsplit('*', 1)[0] for t in l.split(':', 1)[1].split()]
    spec = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); spec.close()
    used = {}
    left = []
    for v in vs:
        if not PH.match(v): left.append(v); continue
        r = subprocess.run([sys.executable, os.path.join(here, 'chainsplit.py'), d, fn, v, rf.name, spec.name], capture_output=True, text=True)
        if 'NOT written' in r.stdout or r.returncode: left.append(v)
    rows = subprocess.run([sys.executable, os.path.join(here, 'rng.py'), d, fn, spec.name], capture_output=True, text=True).stdout
    # the same role name on different variables of one function would collide: keep the first variable per role
    seen = {}; keep = []
    for row in rows.splitlines():
        c = row.split('\t')
        if len(c) < 4: continue
        role = c[3]; var = c[2]
        if role in seen and seen[role] != var: left.append(var + '(dup role ' + role + ')'); continue
        seen[role] = var; keep.append(row)
    base = ['local\t%s\tparam_1\tctx\tINFERRED\tfirst argument of the extvs* instruction emitters: the GL context (+0x118c indexes the shader table, +0xc/+0x18 allocator callbacks)' % fn,
            'local\t%s\tparam_2\tshader\tINFERRED\tEXT_vertex_shader object: *shader is the program table, shader[7] the symbol list' % fn,
            'local\t%s\tparam_3\tinstRecord\tINFERRED\tEXT_vertex_shader IL instruction record: destination operand at +4, source operands at +0x20/+0x3c/+0x58' % fn]
    open(out, 'a').write('\n'.join(base + keep) + '\n')
    print(fn, 'rows', len(keep) + 3, 'left', left)
