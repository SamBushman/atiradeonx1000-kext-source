#!/usr/bin/env python3
"""port_fn.py SPEC.tsv OUTPUT.cpp  - batch-port Ghidra decompiles into one C++ source file.

SPEC lines (tab separated, '#' comments):  ADDR <tab> DECL <tab> OPTIONS
  ADDR     hex address of the function (decompile at $SCRATCH/work/0xADDR.txt)
  DECL     the C++ definition head, e.g. `void IOATIR500Accelerator::teardown2D()`; parameters are named as the decompile
           names them (param_1...). For `__thiscall` decompiles `this` is renamed `self` (a UInt8 *).
  OPTIONS  space separated: this=NAME  (the decompile calls `this` NAME; emitted as `UInt8 *NAME = (UInt8 *)this;`)
                            cast:NAME  (parameter NAME is a class pointer the body uses as bytes: `UInt8 *NAME = (UInt8*)real_NAME`)
                            fun:FUN_xxx=name  extra stub renames   sym:A=>B  textual replacements   members=a,b,c  cls=Class
Stub calls `FUN_0000xxxx(` are resolved through the kext relocation table (Tools/stub_target.py logic) and emitted as calls to
`GH_<symbol>` variadic extern "C" functions carrying the real (mangled) symbol as their asm label.
"""
import sys, re, subprocess, struct, os
HERE = os.path.dirname(os.path.abspath(__file__))
SP = os.environ.get('SCRATCH', '/tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad')
K = os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000.kext.bin')

def load_stub_map():
    d = open(K, 'rb').read()
    n = struct.unpack('>I', d[4:8])[0]
    for i in range(n):
        cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
        if cpu == 18: d = d[off:off+size]; break
    nc = struct.unpack('>I', d[16:20])[0]; p = 28
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[p:p+8])
        if c == 1:
            ns = struct.unpack('>I', d[p+48:p+52])[0]; q = p+56
            for _ in range(ns):
                name = d[q:q+16].rstrip(b'\0').decode()
                a, s, o, al, ro, nr = struct.unpack('>6I', d[q+32:q+56])
                if name == '__text': tro, tnr = ro, nr
                q += 68
        elif c == 2: symoff, nsyms, stroff, strsize = struct.unpack('>4I', d[p+8:p+24])
        p += cs
    syms = []
    for i in range(nsyms):
        strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff+12*i:symoff+12*i+12])
        syms.append(d[stroff+strx:d.index(b'\0', stroff+strx)].decode('latin1'))
    hi = {}
    for i in range(tnr):
        w0, w1 = struct.unpack('>II', d[tro+8*i:tro+8*i+8])
        if not (w0 & 0x80000000) and (w1 >> 4) & 1 and (w1 & 0xf) in (4, 6): hi[w0] = syms[w1 >> 8]
    return hi
HI = load_stub_map()

def stub_symbol(addr):
    return HI.get(addr)

spec = [l.rstrip('\n').split('\t') for l in open(sys.argv[1]) if l.strip() and not l.startswith('#')]
externs = {}
bodies = []
for row in spec:
    addr, decl = row[0], row[1]
    import shlex
    opts = shlex.split(row[2]) if len(row) > 2 else []
    a_norm = addr.lower()
    if a_norm.startswith('0x'):
        a_norm = a_norm[2:]
    a_norm = a_norm.lstrip('0') or '0'
    path = '%s/work/0x%s.txt' % (SP, a_norm)
    cmd = ['python3', HERE + '/ghidra2cpp.py', path]
    thisname = 'this'
    cls = ''
    members = ''
    pre = ''
    for o in opts:
        if o.startswith('this='):
            thisname = o[5:]
        elif o.startswith('cls='):
            cls = o[4:]
        elif o.startswith('members='):
            members = o[8:]
        elif o.startswith('fun:'):
            cmd += ['--fun', o[4:]]
        elif o.startswith('sym:'):
            cmd += ['--sym', o[4:]]
        elif o.startswith('asic:'):
            cmd += ['--asic', o[5:]]
        elif o.startswith('cast:'):
            n = o[5:]
            pre += '    UInt8 *%s = reinterpret_cast<UInt8 *>(real_%s);\n' % (n, n)
    body = open(path).read()
    # stub calls
    funs = sorted(set(re.findall(r'FUN_([0-9a-f]{8})\(', body)))
    for f in funs:
        a = int(f, 16)
        sym = stub_symbol(a)
        key = 'FUN_' + f
        if sym is None:
            continue
        ident = 'GH_' + re.sub(r'[^A-Za-z0-9_]', '_', sym.lstrip('_'))[:60]
        externs[ident] = sym
        cmd += ['--fun', '%s=%s' % (key, ident)]
    cmd += ['--self', thisname]
    if cls:
        cmd += ['--class', cls]
    if members:
        cmd += ['--members', members]
    out = subprocess.run(cmd, capture_output=True, text=True)
    if out.returncode != 0:
        sys.stderr.write('FAILED %s\n%s\n' % (addr, out.stderr)); sys.exit(1)
    head = decl + ' {\n'
    if not decl.startswith('static ') and '::' in decl.split('(')[0] and 'static' not in opts:
        head += '    UInt8 *self = reinterpret_cast<UInt8 *>(this);\n'
    if thisname != 'this':
        head += '    UInt8 *%s = reinterpret_cast<UInt8 *>(this);\n' % thisname
    bodies.append('/* real addr %s */\n%s%s%s}\n' % (('0x' + a_norm), head, pre, out.stdout))
pre = ['#include "../Headers/GhidraCompat.h"', '#include "../Headers/GhidraLiterals.h"', '']
for ident, sym in sorted(externs.items()):
    pre.append('extern "C" UInt32 %s(...) asm("%s");' % (ident, sym))
open(sys.argv[2], 'w').write('\n'.join(pre) + '\n\n' + '\n'.join(bodies))
print('wrote', sys.argv[2], len(bodies), 'functions,', len(externs), 'stub externs')
