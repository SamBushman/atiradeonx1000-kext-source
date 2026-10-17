#!/usr/bin/env python3
"""gen_param_rows.py - print remap-table rows (Tools/apply_renames.py format) that name the placeholder PARAMETERS of a class's ported definitions
(param_1, real_param_1 ...) after the parameter names of the same method's declaration in the class header.

Usage: gen_param_rows.py CLASS            e.g. IOATIR500GLContext      (run from the repository root; reads Sources/<CLASS>_*.cpp and Headers/<CLASS>.h)
Only definitions whose parameter count equals the declaration's are handled; a header name that is itself a placeholder (param3 ...) or missing is
skipped and reported on stderr so the name can be chosen by reading the body. A typed parameter that the port also aliases as an untyped byte pointer
(`real_param_1` + `UInt8 *param_1 = reinterpret_cast...`) gets both rows: `name` and `nameBytes`, the pattern of Tools/renames/IOATIR500Surface.tsv.
"""
import glob, re, sys

cls = sys.argv[1]
hdr = open('Headers/%s.h' % cls).read()
hdr_nc = re.sub(r'/\*.*?\*/', lambda m: ' ' * len(m.group()), hdr, flags=re.S)       # keep offsets, blank comments
hdr_nc = re.sub(r'//[^\n]*', lambda m: ' ' * len(m.group()), hdr_nc)


def split_params(s):
    out, depth, cur = [], 0, ''
    for ch in s:
        if ch in '(<': depth += 1
        if ch in ')>': depth -= 1
        if ch == ',' and depth == 0: out.append(cur.strip()); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur.strip())
    return [p for p in out if p != 'void']


def pname(p):
    m = re.search(r'([A-Za-z_]\w*)\s*(\[\d*\])?\s*$', p)
    return m.group(1) if m else None


def decls(meth):
    res = []
    for m in re.finditer(r'(?<![\w:])%s\s*\(' % re.escape(meth), hdr_nc):
        j, d = m.end(), 1
        while j < len(hdr_nc) and d:
            d += (hdr_nc[j] == '(') - (hdr_nc[j] == ')'); j += 1
        res.append(split_params(hdr_nc[m.end():j - 1]))
    return res


for f in sorted(glob.glob('Sources/%s_*.cpp' % cls)):
    s = open(f).read()
    for m in re.finditer(r'/\* real addr (0x[0-9a-fA-F]+)[^*]*\*/\s*\n[^\n]*?\b%s::(\w+)\s*\(([^)]*)\)\s*(?:const)?\s*\{' % cls, s):
        addr, meth, params = m.group(1), m.group(2), split_params(m.group(3))
        names = [pname(p) for p in params]
        if not any(n and re.match(r'(real_)?param_\d+$', n) for n in names):
            continue
        cands = [d for d in decls(meth) if len(d) == len(params)]
        if not cands:
            print('# NO DECL MATCH %s::%s@%s (%s) params=%s' % (cls, meth, addr, f, names), file=sys.stderr); continue
        hn = [pname(p) for p in cands[0]]
        for n, h in zip(names, hn):
            if not (n and re.match(r'(real_)?param_\d+$', n)): continue
            if not h or re.match(r'(param|arg|p)\d*$', h) or h in ('out0', ) and False:
                print('# SKIP placeholder header name %s::%s@%s %s -> %r' % (cls, meth, addr, n, h), file=sys.stderr); continue
            tgt = '%s::%s@%s' % (cls, meth, addr)
            print('def\t%s\t%s\t%s\tINFERRED\tname from the class header declaration' % (tgt, n, h))
            if n.startswith('real_') and re.search(r'\b%s\s*=\s*reinterpret_cast' % re.escape(n[5:]), s[m.end():m.end() + 400]):
                print('def\t%s\t%s\t%sBytes\tINFERRED\tuntyped alias of the typed parameter named from the class header' % (tgt, n[5:], h))
