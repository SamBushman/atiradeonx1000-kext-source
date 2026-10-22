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
            rows.append((f, n, c[1], c[2], c[3], c[4]) if c[0] == 'local' else (f, n, c[1], c[2], c[3], c[4], c[6], c[7] if len(c) > 7 else ''))
    return rows


def wb(x):
    return r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(x)


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
        while i < len(lines) and (re.match(DECL, lines[i]) or not lines[i].strip() or re.match(r'\s*(/\*|\*)', lines[i]) or re.match(r'\s+[\w ]+ \w+\[\d+\] = \{.*\};', lines[i])): i += 1
        return brace + 1, i
    N = [norm(l) for l in lines]               # renames are taken back, so N only changes when a declaration line is inserted
    for (f, n, fn, old, new, tier, frm, to) in uses:
        m = re.match(r'(.*)@(\d+)$', frm); pat, k = (m.group(1), int(m.group(2))) if m else (frm, 1)
        hits = [i for i in range(brace + 1, e) if re.search(pat, N[i])]
        if len(hits) < k: print('%s:%d: %s: anchor %r not found' % (f, n, fn, frm)); nerr += 1; continue
        a = hits[k - 1]; z = e
        if to:
            tz = [i for i in range(a + 1, e) if re.search(to, N[i])]
            if not tz: print('%s:%d: %s: end anchor %r not found' % (f, n, fn, to)); nerr += 1; continue
            z = tz[0]
        seg = lines[a:z]
        has_old = any(re.search(wb(old), strip_strings(l)) for l in seg)
        has_new = any(re.search(wb(new), strip_strings(l)) for l in seg)
        if not has_old and not has_new:
            print('%s:%d: %s: neither %s nor %s in the segment' % (f, n, fn, old, new)); nerr += 1; continue
        if has_old and new in declset:
            print('%s:%d: %s: new name %s collides with a declaration' % (f, n, fn, new)); nerr += 1; continue
        # declaration of new, beside old's (checked BEFORE any line is touched, so an error leaves the text as it was; also repairs a missing one)
        d0, d1 = declblock()
        if not any(re.match(r'\s+[\w ]+[ *]%s;$' % re.escape(new), l) for l in lines[d0:d1]):
            m = None
            di = next((i for i in range(d0, d1) if (m := re.match(r'(\s+)([\w ]+?[ *])%s;$' % re.escape(old), lines[i]))), None)
            if di is None: print('%s:%d: %s: no simple declaration of %s' % (f, n, fn, old)); nerr += 1; continue
            at = di + 1
            if os.environ.get('USE_DECL', 'end') == 'end':    # after the last simple declaration: gcc allocates -O0 slots in declaration order
                at = max(i for i in range(d0, d1) if re.match(DECL, lines[i])) + 1
            lines.insert(at, '%s%s%s;' % (m.group(1), m.group(2), new)); N.insert(at, norm(lines[at])); e += 1
            if at <= a: a += 1; z += 1
            npend += 1
        if not has_old:
            napp += 1; continue
        for i in range(a, z): lines[i] = re.sub(wb(old), new, lines[i])
        npend += 1
    # drop old declarations nothing uses any more
    for old in {r[3] for r in uses}:
        d0, d1 = declblock()
        di = next((i for i in range(d0, d1) if re.match(r'\s+[\w ]+?[ *]%s;$' % re.escape(old), lines[i])), None)
        if di is not None and not any(re.search(wb(old), strip_strings(lines[i])) for i in range(brace + 1, e) if i != di):
            del lines[di]; del N[di]; e -= 1
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
            uses = [r for r in rws if len(r) == 8]
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
                sub = lines[s:e]
                a2, p2, e2 = apply_uses(sub, 0, len(sub), name, uses, rws, decl)
                lines[s:e] = sub
                applied += a2; pending += p2; errors += e2; changed = changed or p2 > 0
        if changed and not check:
            open(pf, 'w').write('\n'.join(lines))
    for fn, rs in byfn.items():
        for r in rs: print('%s:%d: function %s not found' % (r[0], r[1], fn)); errors += 1
    print('%d renames %s, %d already applied, %d errors' % (pending, 'pending' if check else 'applied', applied, errors))
    sys.exit(1 if errors or (check and pending) else 0)


main()
