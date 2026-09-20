"""fix_gl_stubs.py - give libGL's dispatch stubs their real prototypes (used by link_corpus.py, config key "gl_headers").

libGL's 870 `_gl*` entry points are 20-instruction dispatch stubs: `ctx = current context; ctx->table[N](ctx->object, args...)`. Ghidra typed every argument
`undefined8`, and the corpus renders them as K&R `unsigned long long` parameters, which occupy two integer registers each; a `float`/`double` argument (which
the stock code receives in f1..f13 and forwards untouched) is not forwarded at all. The corpus compiles and makes the same calls, but a linked image renders
nothing (glClearColor's colour is lost). The machine code is a plain register-forwarding tail call, so the real prototype - which the OpenGL headers give
by name - is the faithful C. This module rewrites each stub's header to the ANSI prototype from <OpenGL/gl.h> / <OpenGL/glext.h> (so gcc also checks our
definition against Apple's declaration) and extends the forwarded call to the true argument list; the stack-argument shuffling Ghidra shows (`local_48 =
param_8`) is what the C compiler does for a call with more than 8 integer arguments. The 148 stubs that take floating-point arguments are garbled in the
decompile (the FPR-saving millicode call shows up as a value, the arguments come out in the wrong order), so every stub body is written from one template
whose only per-function fact is the dispatch index N; N is checked against the stock disassembly by `check_gl_stub_indices.py`.
"""
import re


def parse_prototypes(paths):
    protos = {}
    for p in paths:
        t = open(p, errors='replace').read()
        t = re.sub(r'/\*.*?\*/', ' ', t, flags=re.S)
        t = re.sub(r'//[^\n]*', ' ', t)
        for m in re.finditer(r'^\s*extern\s+([^;()]*?)\b(gl\w+)\s*\(([^;]*?)\)\s*(?:AVAILABLE_\w+(?:\([^)]*\))?\s*)?;', t, re.M):
            ret, name, params = m.group(1).strip(), m.group(2), m.group(3).strip()
            if name.endswith('ProcPtr') or 'typedef' in ret:
                continue
            protos.setdefault(name, (ret, params))
    return protos


def split_params(params):
    """-> list of C parameter types (names stripped); [] for (void)"""
    if params in ('', 'void'):
        return []
    out = []
    for p in params.split(','):
        p = p.strip()
        mm = re.match(r'^((?:const\s+)?[A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)?\s*(?:\*\s*(?:const\s*)?)*)\s*([A-Za-z_]\w*)?\s*(\[\s*\d*\s*\])?$', p)
        if not mm:
            return None
        base, name, arr = mm.groups()
        # "GLenum target" -> base "GLenum", name "target"; "GLenum" -> base GLenum, no name; "const GLvoid *" -> base only
        toks = base.split()
        if name is None and len(toks) >= 2 and not base.rstrip().endswith('*') and toks[-1] not in ('int', 'long', 'char', 'short', 'double', 'float', 'unsigned'):
            if toks[0] != 'const' or len(toks) > 2:
                name = toks[-1]
                base = ' '.join(toks[:-1])
        out.append(base.strip() + (' *' if arr else ''))
    return out


CALL = re.compile(r'\(\*\(code \*\)puVar\d+\[(0x[0-9a-f]+|\d+)\]\)\(')

TEMPLATE = """{
  /* dispatch stub, template derived from the stock machine code (index %(idx)s = ctx offset 0x%(off)x): current context, refreshed from the thread's
     pthread key when this stack page is not the one the context last ran on, then a tail call of the context's entry with the context object
     prepended; every other argument register (r3..r10 shifted by one, f1..f13, the stack words) is forwarded by the C call itself. */
  unsigned int *puVar2 = (unsigned int *)_gll_cc;
  unsigned int stackTag = (unsigned int)__builtin_frame_address(0);
  if (((puVar2[0x2ac] ^ stackTag) & 0xfffff000) != 0) {
    puVar2 = (unsigned int *)_pthread_getspecific(_gll_pkey);
    _gll_cc = (unsigned int)puVar2;
    puVar2[0x2ac] = stackTag;
  }
  %(call)s
}"""


def patch_function(chunk, name, protos):
    """chunk = one function (comment line + K&R header + decls + body). Returns (new_chunk, status)."""
    cname = name[1:] if name.startswith('_') else name
    if cname not in protos:
        return chunk, 'no prototype'
    ret, params = protos[cname]
    types = split_params(params)
    if types is None:
        return chunk, 'unparsed prototype: %s' % params
    lines = chunk.split('\n')
    try:
        hi = next(i for i, l in enumerate(lines) if re.match(r'^\w[\w \*]*\b%s\(' % re.escape(name), l))
    except StopIteration:
        return chunk, 'unrecognised layout'
    mm = CALL.search(chunk)
    if not mm:
        return chunk, 'no dispatch call'
    idx = mm.group(1)
    args = ''.join(', param_%d' % (k + 1) for k in range(len(types)))
    rt = ret.strip()
    fnc = '((%s (*)())puVar2[%s])(puVar2[0]%s);' % (rt, idx, args)
    call = fnc if rt == 'void' else 'return ' + fnc
    sig = '%s %s(%s)' % (rt, cname, ', '.join('%s param_%d' % (ty, k + 1) for k, ty in enumerate(types)) if types else 'void')
    body = TEMPLATE % dict(idx=idx, off=int(idx, 16) * 4 if idx.startswith('0x') else int(idx) * 4, call=call)
    return '\n'.join(lines[:hi]) + ('\n' if hi else '') + sig + '\n' + body + '\n', 'ok'
