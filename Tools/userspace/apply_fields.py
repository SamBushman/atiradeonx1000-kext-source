#!/usr/bin/env python3
"""apply_fields.py - give the structure-field offsets of a context object real names in the userspace corpus.

Usage: apply_fields.py [--check] Userspace/<Binary>/<arch>

Reads <dir>/fields_*.tsv. Rows (tab separated, '#' starts a comment):
    field<TAB>STRUCT<TAB>0xOFFSET<TAB>name<TAB>tier<TAB>evidence
STRUCT is a short prefix (GLD, ARB, PROG, COMP). The functions the table applies to are listed in <dir>/<struct lower>_scope.txt (one name per line, '#' comments;
a line `NAME var` names the variable that holds the object in that function when it is not `ctx`, e.g. `pass_loop_trans program`): inside them that variable is the object.
For PROG the nested spelling `*(T *)(program + PROG_compiler) + 0x374` is also rewritten with the COMP table (the Compiler is `*(program + 8)`). Writes <dir>/<struct lower>_ctx_fields.h, an `enum { STRUCT_name = 0xOFFSET, ... };` (an enumerator is a
true integer constant, so the generated code does not change), makes decls.h include it, and rewrites the numeric offsets in the scoped functions:

    ctx + 0x1dc                      ->  ctx + GLD_writeCursor              (ctx an integer)
    *(T *)(ctx + 0x1dc)              ->  *(T *)(ctx + GLD_writeCursor)
    ctx + 0xf, ctx[0xf]              ->  ctx + GLD_x / 4, ctx[GLD_x / 4]    (ctx a word pointer: the offset is in words)
    (int)ctx + 0x141                 ->  (int)ctx + GLD_x
    ((unsigned char *)0x2b7e)[ctx]   ->  ((unsigned char *)GLD_x)[ctx]      (also `(0x26c8 + ctx)`, `(((unsigned char *)0x..) + ctx)`)

Offsets that are not in the table stay numeric. Idempotent. --check exits 1 when a rewrite is still pending. tier is CONFIRMED / INFERRED / UNKNOWN.
Gate: Tools/userspace/verify_names.sh must say IDENTICAL (the object code is unchanged)."""
import re, sys, os, glob

HDR = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/$')
NUM = r'(0x[0-9a-f]+|\d+)'


def load(d):
    out = {}
    for f in sorted(glob.glob(os.path.join(d, 'fields_*.tsv'))):
        for n, l in enumerate(open(f), 1):
            if not l.strip() or l.startswith('#'): continue
            c = l.rstrip('\n').split('\t')
            if len(c) < 6 or c[0] != 'field' or not c[5].strip():
                print('%s:%d: bad row (needs evidence)' % (f, n)); sys.exit(1)
            out.setdefault(c[1], {})
            off = int(c[2], 0)
            if off in out[c[1]]: print('%s:%d: offset %#x given twice' % (f, n, off)); sys.exit(1)
            out[c[1]][off] = (c[3], c[4])
    return out


def ctxtype(body, V='ctx'):
    """-> True when `ctx` is a word pointer (int *ctx / uint *ctx), False for an integer or a byte-addressed type."""
    for l in body[1:40]:
        m = re.match(r'\s+((?:unsigned )?\w+(?: \w+)*?)\s*(\*?)\s*' + re.escape(V) + ';', l)
        if m: return bool(m.group(2))
        m = re.match(r'(?:\S+ )?\S+\((.*?)\)', l)
        if m and l.startswith(('int ', 'uint ', 'void ', 'undefined')) and '(' in l:
            first = m.group(1).split(',')[0].strip()
            w = first.split()
            if len(w) > 1 and w[-1].lstrip('*') == V: return first.find('*') >= 0      # ANSI header; a K&R header lists the bare name and the type follows
    return False


def rewrite(line, tbl, S, isptr, V='ctx'):
    """returns (new line, number of rewrites)"""
    n = 0
    EV = re.escape(V)

    def nm(off):
        return '%s_%s' % (S, tbl[off][0])

    def sub_int(m):
        nonlocal n
        v = int(m.group(1), 0)
        if v in tbl: n += 1; return V + ' + %s' % nm(v)
        return m.group(0)

    def sub_word(m):
        nonlocal n
        v = int(m.group(1), 0) * 4
        if v in tbl: n += 1; return V + ' + %s / 4' % nm(v)
        return m.group(0)

    def sub_cast(m):
        nonlocal n
        v = int(m.group(1), 0)
        if v in tbl: n += 1; return '(int)' + V + ' + %s' % nm(v)
        return m.group(0)

    def sub_idx(m):
        nonlocal n
        v = int(m.group(1), 0) * 4
        if v in tbl: n += 1; return V + '[%s / 4]' % nm(v)
        return m.group(0)

    def sub_hoist(rx_prefix):
        def f(m):
            nonlocal n
            v = int(m.group(1), 0)
            if v in tbl: n += 1; return m.group(0).replace(m.group(1), nm(v), 1)
            return m.group(0)
        return f

    # (int)ctx + N is byte-addressed whatever the type of ctx
    line = re.sub(r'\(int\)' + EV + r' \+ ' + NUM + r'\b', sub_cast, line)
    parts = re.split(r'(\(int\)' + EV + r' \+ \w+)', line)          # protect the already-handled cast spelling from the plain rule
    for i in range(0, len(parts), 2):
        p = parts[i]
        p = re.sub(r'\b' + EV + r' \+ ' + NUM + r'\b', sub_word if isptr else sub_int, p)
        if isptr: p = re.sub(r'\b' + EV + r'\[' + NUM + r'\]', sub_idx, p)
        parts[i] = p
    line = ''.join(parts)
    line = re.sub(r'\(\(unsigned char \*\)(0x[0-9a-f]+)U?\)\[' + EV + r'\]', sub_hoist(None), line)
    line = re.sub(r'\(\(\(unsigned char \*\)(0x[0-9a-f]+)U?\) \+ ' + EV + r'\)', sub_hoist(None), line)
    line = re.sub(r'\((0x[0-9a-f]+) \+ ' + EV + r'\)', sub_hoist(None), line)
    return line, n


def main():
    a = sys.argv[1:]; check = '--check' in a; a = [x for x in a if x != '--check']
    d = a[0]
    tables = load(d)
    pending = 0
    for S, tbl in tables.items():
        scope = {}
        for l in open(os.path.join(d, S.lower() + '_scope.txt')):
            if l.strip() and not l.startswith('#'):
                w = l.split('#')[0].split()
                scope[w[0]] = w[1] if len(w) > 1 else 'ctx'
        hdr = os.path.join(d, S.lower() + '_ctx_fields.h')
        text = '/* generated by Tools/userspace/apply_fields.py from fields_*.tsv: byte offsets of the %s context object */\nenum {\n' % S
        for off in sorted(tbl): text += '  %s_%s = 0x%x,   /* %s */\n' % (S, tbl[off][0], off, tbl[off][1])
        text += '};\n'
        if not os.path.exists(hdr) or open(hdr).read() != text:
            if not check: open(hdr, 'w').write(text)
            pending += 1
        dh = os.path.join(d, 'decls.h'); dt = open(dh).read()
        inc = '#include "%s_ctx_fields.h"' % S.lower()
        if inc not in dt:
            if not check: open(dh, 'w').write(dt.rstrip('\n') + '\n' + inc + '\n')
            pending += 1
        for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
            lines = open(pf).read().split('\n'); changed = False; cur = None; start = 0
            marks = [(i, HDR.match(l).group(1)) for i, l in enumerate(lines) if HDR.match(l)] + [(len(lines), None)]
            for (i, name), (j, _) in zip(marks, marks[1:]):
                if name not in scope: continue
                V = scope[name]; body = lines[i:j]; isptr = ctxtype(body, V)
                for k in range(i, j):
                    l = lines[k]
                    if re.match(r'\s*(/\*|\*/|\* |\*$|//)', l): continue
                    nl, n = rewrite(l, tbl, S, isptr, V)
                    if S == 'PROG' and 'COMP' in tables and 0x8 in tbl:     # the Compiler is `*(program + 8)`: `*(T *)(program + PROG_compiler) + 0x374` names its field
                        ctbl = tables['COMP']; pn = 'PROG_' + tbl[0x8][0]
                        def sub_comp(m, ctbl=ctbl):
                            v = int(m.group(2), 0)
                            return m.group(1) + 'COMP_' + ctbl[v][0] + ')' if v in ctbl else m.group(0)
                        nl2 = re.sub(r'(\*\((?:\w+ )*\w+ \*\)\(' + re.escape(V) + r' \+ ' + pn + r'\) \+ )' + NUM + r'\)', sub_comp, nl)
                        if nl2 != nl: n += 1; nl = nl2
                    if n: lines[k] = nl; changed = True; pending += n
            if changed and not check: open(pf, 'w').write('\n'.join(lines))
    print('%d rewrites %s' % (pending, 'pending' if check else 'applied'))
    sys.exit(1 if check and pending else 0)


if __name__ == '__main__':
    main()
