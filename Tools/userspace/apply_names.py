#!/usr/bin/env python3
"""apply_names.py - give the Ghidra placeholder names in the userspace corpus real names, from a table.

Usage: apply_names.py [--check] [--root DIR] Userspace/<Binary>/<arch>      (applies <dir>/names.tsv and <dir>/names_*.tsv to <dir>/part_*.c)

Table rows (tab separated, '#' starts a comment line):
    local<TAB>FUNCTION<TAB>old<TAB>new<TAB>tier<TAB>evidence     rename parameter/local `old` to `new` inside FUNCTION (whole function)
FUNCTION is the name in the `/* NAME @ 0xADDR (N bytes) */` header comment that opens each function (FUN_xxxx names work too).
tier is CONFIRMED (the binary shows it: a string, a called API's documented argument, a struct field the code both writes and reads in a
named way), INFERRED (the role is clear from use, nothing names it) or UNKNOWN (kept as a descriptive guess).

    use<TAB>FUNCTION<TAB>old<TAB>new<TAB>tier<TAB>evidence<TAB>from<TAB>to   rename `old` to `new` only in one segment of FUNCTION (splits a local reused for several roles)
`from`/`to` are regexes over the function's lines AS GHIDRA WROTE THEM (lines are matched with every rename of the function taken back, so a table
stays valid after it was applied). `from` may end in @N (Nth matching line, default 1); the segment starts at that line and runs up to, not
including, the first later line matching `to` (empty `to` = end of function). One `new` name belongs to one `old` per function; a function with
`use` rows for a variable must not also have a `local` row for it. The declaration of `new` is added next to old's (same type); old's declaration is
dropped when nothing uses it any more. Only locals (declared after the `{`) can be split.

Idempotent: a row whose `old` is gone and whose `new` is present is "already applied". An `old` that is absent and a `new` that is absent
is an error. A `new` that is already used in the function (as another variable, or as a global/function declared in decls.h) is refused.
Renames never change generated code at -O0: Tools/userspace/verify_names.sh compiles the corpus before and after and demands identical objects.
"""
import re, sys, os, glob

IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')
HDR = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/$')


def split_functions(text):
    """-> list of (name, start_line, end_line) over text.split('\n'); a function runs from its header comment to the next header (or EOF)."""
    lines = text.split('\n'); marks = []
    for i, l in enumerate(lines):
        m = HDR.match(l)
        if m: marks.append((m.group(1), i))
    out = []
    for k, (n, i) in enumerate(marks):
        out.append((n, i, marks[k + 1][1] if k + 1 < len(marks) else len(lines)))
    return lines, out


def strip_strings(s):
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S)      # words in comments are not identifiers
    return re.sub(r'"(\\.|[^"\\])*"', lambda m: '"' + 'x' * (len(m.group(0)) - 2) + '"', s)


def load_rows(d):
    rows = []
    for f in sorted(glob.glob(os.path.join(d, 'names.tsv')) + glob.glob(os.path.join(d, 'names_*.tsv'))):
        for n, l in enumerate(open(f), 1):
            if not l.strip() or l.startswith('#'): continue
            c = l.rstrip('\n').split('\t')
            if len(c) < 5 or c[0] not in ('local', 'use') or (c[0] == 'use' and len(c) < 7):
                print('%s:%d: bad row' % (f, n)); sys.exit(1)
            rows.append((f, n, c[1], c[2], c[3], c[4]) if c[0] == 'local' else (f, n, c[1], c[2], c[3], c[4], c[6], c[7] if len(c) > 7 else '', c[8] if len(c) > 8 and c[8] else 'all', c[9] if len(c) > 9 and c[9] else 'none'))
    return rows


def wb(x):
    return r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(x)


def split_assign(l):
    """index of the first plain assignment `=` of a line (not ==, !=, <=, >=, +=, ...), or -1"""
    for i, ch in enumerate(l):
        if ch == '=' and (i == 0 or l[i - 1] not in '=!<>+-*/&|^%') and l[i + 1:i + 2] != '=': return i
    return -1


def part_text(l, part):
    """the part of a line a `first`/`last` flag talks about: all | lhs (left of the first assignment) | rhs (right of it, or the whole line when it has no assignment)"""
    if part == 'all': return l
    i = split_assign(l)
    if part == 'lhs': return l[:i] if i >= 0 else ''
    return l[i + 1:] if i >= 0 else l


def sub_part(l, part, old, new):
    if part == 'all': return re.sub(wb(old), new, l)
    i = split_assign(l)
    if part == 'lhs': return re.sub(wb(old), new, l[:i]) + l[i:] if i >= 0 else l
    return (l[:i + 1] + re.sub(wb(old), new, l[i + 1:])) if i >= 0 else re.sub(wb(old), new, l)


def apply_uses(lines, s, e, name, uses, allrows, declset):
    """Apply the `use` rows of one function in place (lines[s:e]); -> (already applied, newly applied, errors)."""
    back = {}                                  # every new name of the function -> its old name, to normalise lines back to Ghidra's text
    for r in allrows:
        back[r[4]] = r[3]
    olds = {}
    for r in uses:
        o = olds.setdefault(r[4], r[3])
        if o != r[3]:
            print('%s:%d: %s: new name %s is used for both %s and %s' % (r[0], r[1], name, r[4], o, r[3])); return 0, 0, 1
    brace = next((i for i in range(s, e) if lines[i] == '{'), None)
    if brace is None: print('%s: no body' % name); return 0, 0, 1
    norm = lambda l: re.sub('|'.join(wb(k) for k in back), lambda m: back[m.group(0)], l) if back else l
    napp = npend = nerr = 0
    DECL = r'\s+(?!return\b)[\w ]+?[ *]([A-Za-z_]\w*)(\[\w+\])?;$'
    def declblock():                           # (first, last+1) line of the declarations right after the `{`
        i = brace + 1
        while i < len(lines) and (re.match(DECL, lines[i]) or not lines[i].strip() or re.match(r'\s*(/\*|\*)', lines[i])): i += 1
        return brace + 1, i
    Ncache = None; created = {}
    for (f, n, fn, old, new, tier, frm, to, first, last) in uses:
        if Ncache is None or len(Ncache) != len(lines): Ncache = [norm(l) for l in lines]    # renames do not change normalised text
        N = Ncache
        d0, d1 = declblock()
        if frm.startswith('#'):                # '#L': L lines after the end of the declarations (machine-written rows); '+N' as `to`: N lines after `from`
            a = d1 + int(frm[1:])
            if a >= e: print('%s:%d: %s: line anchor %s beyond the function' % (f, n, fn, frm)); nerr += 1; continue
        else:
            m = re.match(r'(.*)@(\d+)$', frm); pat, k = (m.group(1), int(m.group(2))) if m else (frm, 1)
            hits = [i for i in range(brace + 1, e) if re.search(pat, N[i])]
            if len(hits) < k: print('%s:%d: %s: anchor %r not found' % (f, n, fn, frm)); nerr += 1; continue
            a = hits[k - 1]
        z = e
        if to.startswith('+'): z = min(a + int(to[1:]), e)
        elif to:
            tz = [i for i in range(a + 1, e) if re.search(to, N[i])]
            if not tz: print('%s:%d: %s: end anchor %r not found' % (f, n, fn, to)); nerr += 1; continue
            z = tz[0]
        todo = [(i, first if i == a else 'all') for i in range(a, z)] + ([(z, last)] if to and last != 'none' and z < e else [])
        seg = [part_text(lines[i], pt) for i, pt in todo]
        has_old = any(re.search(wb(old), strip_strings(l)) for l in seg)
        has_new = any(re.search(wb(new), strip_strings(l)) for l in seg)
        if not has_old:
            if has_new: napp += 1
            else: print('%s:%d: %s: neither %s nor %s in the segment' % (f, n, fn, old, new)); nerr += 1
            continue
        if new in declset: print('%s:%d: %s: new name %s collides with a declaration' % (f, n, fn, new)); nerr += 1; continue
        if new not in {x for v_ in created.values() for x in v_} and any(re.search(wb(new), strip_strings(l)) for l in lines[s:e]):
            print('%s:%d: %s: new name %s is already used in the function' % (f, n, fn, new)); nerr += 1; continue
        for i, pt in todo: lines[i] = sub_part(lines[i], pt, old, new)
        npend += 1
        # declaration of new, beside old's
        d0, d1 = declblock()
        if not any(re.match(r'\s+[\w ]+[ *]%s;$' % re.escape(new), l) for l in lines[d0:d1]):
            di = next((i for i in range(d0, d1) if re.match(r'(\s+)([\w ]+?[ *])%s;$' % re.escape(old), lines[i])), None)
            if di is None: print('%s:%d: %s: no simple declaration of %s' % (f, n, fn, old)); nerr += 1; continue
            m = re.match(r'(\s+)([\w ]+?[ *])%s;$' % re.escape(old), lines[di])
            at = di + 1
            if os.environ.get('USE_DECL', 'first') == 'first':     # frame offsets count from the bottom: declarations placed first sit at the top and move nothing else
                at = d0
            elif os.environ.get('USE_DECL', 'first') == 'end':    # after the last simple declaration: gcc allocates -O0 slots in declaration order
                at = max(i for i in range(d0, d1) if re.match(DECL, lines[i])) + 1
            lines.insert(at, '%s%s%s;' % (m.group(1), m.group(2), new)); e += 1
            created.setdefault(old, []).append(new)
    # when nothing uses `old` any more, its first new name takes over old's declaration slot (gcc -O0 orders commutative operands, and allocates frame
    # slots, by declaration order: keeping the order keeps the object code); otherwise old stays declared
    for old in sorted({r[3] for r in uses}):
        d0, d1 = declblock()
        di = next((i for i in range(d0, d1) if re.match(r'\s+[\w ]+?[ *]%s;$' % re.escape(old), lines[i])), None)
        if di is None or any(re.search(wb(old), strip_strings(lines[i])) for i in range(brace + 1, e) if i != di): continue
        nn = created.get(old)
        if nn:
            dj = next((i for i in range(d0, d1) if re.match(r'\s+[\w ]+?[ *]%s;$' % re.escape(nn[0]), lines[i])), None)
            if dj is not None and dj != di:
                lines[di] = lines[dj]; del lines[dj]; e -= 1
                continue
        del lines[di]; e -= 1
    return napp, npend, nerr


def main():
    a = sys.argv[1:]; check = '--check' in a; a = [x for x in a if x != '--check']
    d = a[0]
    rows = load_rows(d)
    dtext = re.sub(r'/\*.*?\*/|//[^\n]*', ' ', open(os.path.join(d, 'decls.h')).read(), flags=re.S)   # identifiers declared, not words in comments
    decl = set(IDENT.findall(dtext))
    byfn = {}
    for r in rows: byfn.setdefault(r[2], []).append(r)
    pending = applied = errors = 0
    for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        text = open(pf).read(); lines, fns = split_functions(text); changed = False
        for name, s, e in reversed(fns):
            if name not in byfn: continue
            body = '\n'.join(lines[s:e])
            rws = byfn.pop(name)
            uses = [r for r in rws if len(r) == 10]
            for (f, n, fn, old, new, tier) in [r for r in rws if len(r) == 6]:
                code = strip_strings(body)
                ids = set(IDENT.findall(code))
                if old not in ids:
                    if new in ids: applied += 1; continue
                    print('%s:%d: %s: neither %s nor %s present' % (f, n, fn, old, new)); errors += 1; continue
                if new in ids or new in decl:
                    print('%s:%d: %s: new name %s collides' % (f, n, fn, new)); errors += 1; continue
                body = re.sub(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(old), new, body)
                pending += 1; changed = True
            lines[s:e] = body.split('\n')
            if uses:
                a2, p2, e2 = apply_uses(lines, s, e, name, uses, rws, decl)
                applied += a2; pending += p2; errors += e2; changed = changed or p2 > 0
        if changed and not check:
            open(pf, 'w').write('\n'.join(lines))
    for fn, rs in byfn.items():
        for r in rs: print('%s:%d: function %s not found' % (r[0], r[1], fn)); errors += 1
    print('%d renames %s, %d already applied, %d errors' % (pending, 'pending' if check else 'applied', applied, errors))
    sys.exit(1 if errors or (check and pending) else 0)


main()
