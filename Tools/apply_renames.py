#!/usr/bin/env python3
"""apply_renames.py - give the placeholder names of the mechanically ported sources (param_3, uVar7, local_38 ...) real names, from a remap table.

The *_Port.cpp files are generated from the Ghidra decompile (Tools/replace_fn.py, Tools/port_fn.py), so names are NOT edited in them by hand: they live in
a remap table, `Tools/renames/<Class>.tsv`, and this tool applies the table. Run it after any re-port and the names come back; it is idempotent.

Usage: apply_renames.py [--check] [--root DIR] [TABLE.tsv ...]      (default: every Tools/renames/*.tsv)
  --check   change nothing; exit 1 if any row or patch is not yet applied or cannot be applied

After the renames, every Tools/renames/patches/*.patch is applied (unified diffs, -p1 from the repository root, one per source file, made against the
RENAMED text). They carry the structural edits that need more than a rename - such as expressing `self + panel * 0x94 + 0xcad` as
`panels[panel].swapMode` - so that a re-port from the Ghidra decompile followed by this tool reproduces the same source. A patch that is already
applied is skipped; one that applies neither way is an error (the re-ported text differs: redo the edit and regenerate the patch).

Table format (tab separated, '#' starts a comment line):
    #!use-decl: end|beside      (a line of its own in a table, before its `use` rows; default end)
    kind  target  old  new  tier  evidence  [from  to  [occ]]
  kind    def   rename an identifier inside one function DEFINITION in Sources/*.cpp (signature included)
          decl  rename a parameter name inside one function DECLARATION in Headers/<Class>.h
          use   rename ONE USE of a variable that the decompile reuses for several unrelated roles: only the lines from the first line matching the
                regex `from` up to (not including) the first following line matching the regex `to` (empty or '-' = to the end of the function;
                `from` '-' = from the first line after the declarations). `new` is declared (same type as `old`) at the END of the function's declaration block (the table directive `#!use-decl: beside` instead puts it right after the declaration of `old`, which is how the first tables were verified):
                gcc 4.0.1 numbers pseudo-registers in declaration order, so any other position changes the allocation of the existing variables - so the
                variable is split in two. The optional 9th column `occ` (comma list of 1-based indices) renames only those occurrences of the variable
                inside the segment - for a line like `x = f(x)` whose two sides play different roles; the indices count, in text order, every code
                occurrence (comments and string literals excluded) of `old` or of any `new` name that a use row gives the same `old`, so they stay stable
                as rows are applied. Rows of one function are applied in table order and may split the same `old` several times.
  target  Class::method, optionally Class::method@0xADDR (several definitions with that name: the one whose "real addr" comment matches)
          or Class::method#N (decl only: the N-th declaration, 1-based). A FREE function (no class) is written with an empty class: `::pcl_CopyPix`
          (def rows only; a decl row needs a class header)
  old/new identifiers. A rename applies to the whole function scope, comments included, string literals excluded.
  tier    CONFIRMED (the meaning is established by a caller, a test or a disassembly) | INFERRED (consistent with every use seen) | UNKNOWN (a
          placeholder with a readable shape, e.g. unknown_0x84)
  evidence  one line: where the meaning comes from (not interpreted by the tool)

  kind    field  CLASS[,CLASS...]  0xOFFSET  name  tier  evidence   (columns: kind classes offset name tier evidence)
          name the direct object-field accesses `self + 0xOFFSET` (or `param_1 + 0xOFFSET`, the same pointer under Ghidra's name) in every method of the
          class(es): the literal becomes the constant `k<FirstClass>_<name>`, declared in the generated Headers/FieldOffsets.h
          (`static const int`, so the compiled code is identical). Only the object's OWN fields: `M<T>(M<int>(self + 0x8c) + 0x50)` names +0x8c but
          the +0x50 field belongs to another object's class. Several classes (a base and its derived class) share the one constant.

Anchors (`from`/`to`) are Python regexes (a trailing `#N` selects the N-th matching line instead of the first) matched against a line in which every `use` rename of the function has been taken back (so an anchor
may be written with the old names and keeps matching after the table was applied). A `use` row is applied once its segment no longer contains `old`; several rows may give disjoint segments of one variable the same `new` name
(the first one declares it).
A split is only valid when no value of `old` flows from one segment into another: the tool cannot see that, so Tools/verify_identical_build.sh
(the compiled kext must stay byte-identical) is the gate for every `use` row; Tools/renames/find_splits.py lists the assignments and reads of a
variable to help choose the anchors.

The tool refuses a rename whose new name already occurs in the function scope, that is a C++ keyword, or whose old name does not occur (unless the new
name is already there, which counts as applied). Renames never change the compiled code: Tools/verify_identical_build.sh proves it.
"""
import argparse, glob, os, re, sys

KEYWORDS = set("""alignas alignof and asm auto bool break case catch char class const constexpr continue default delete do double else enum explicit
extern false float for friend goto if inline int long mutable namespace new nullptr operator or private protected public register return short signed sizeof
static struct switch template this throw true try typedef typename union unsigned using virtual void volatile while override""".split())
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')


def lex_skip(s, i):
    """If a comment or literal starts at s[i], return (end index, kind); else None. kind: 'comment' | 'literal'."""
    if s.startswith('//', i):
        j = s.find('\n', i)
        return (len(s) if j < 0 else j, 'comment')
    if s.startswith('/*', i):
        j = s.find('*/', i + 2)
        return (len(s) if j < 0 else j + 2, 'comment')
    if s[i] in '"\'':
        q, j = s[i], i + 1
        while j < len(s) and s[j] != q:
            j += 2 if s[j] == '\\' else 1
        return (j + 1, 'literal')
    return None


def find_body_end(s, start):
    """Index just past the '}' closing the first '{' at or after start (comments and literals skipped)."""
    i, depth, seen = start, 0, False
    while i < len(s):
        sk = lex_skip(s, i)
        if sk:
            i = sk[0]; continue
        c = s[i]
        if c == '{': depth += 1; seen = True
        elif c == '}':
            depth -= 1
            if seen and depth == 0: return i + 1
        i += 1
    raise ValueError('unterminated function body')


def idents_in(s, comments=True):
    """Set of identifiers in s outside literals (comments included unless comments=False)."""
    out, i = set(), 0
    while i < len(s):
        sk = lex_skip(s, i)
        if sk and sk[1] == 'literal':
            i = sk[0]; continue
        if sk:                                     # comment: scan its words
            if comments: out.update(IDENT.findall(s[i:sk[0]]))
            i = sk[0]; continue
        m = IDENT.match(s, i)
        if m: out.add(m.group()); i = m.end()
        else: i += 1
    return out


def rename_in(s, mapping):
    """Replace whole identifiers per mapping, outside string/char literals."""
    out, i = [], 0
    while i < len(s):
        sk = lex_skip(s, i)
        if sk and sk[1] == 'literal':
            out.append(s[i:sk[0]]); i = sk[0]; continue
        if sk:                                     # comment: rename inside it
            out.append(IDENT.sub(lambda m: mapping.get(m.group(), m.group()), s[i:sk[0]])); i = sk[0]; continue
        m = IDENT.match(s, i)
        if m:
            out.append(mapping.get(m.group(), m.group())); i = m.end()
        else:
            out.append(s[i]); i += 1
    return ''.join(out)


def parse_target(t):
    m = re.match(r'^([A-Za-z0-9_]*)::([A-Za-z0-9_~]+)(?:@(0x[0-9a-fA-F]+)|#(\d+))?$', t)
    if not m: raise ValueError('bad target %r' % t)
    return m.group(1), m.group(2), (m.group(3) or '').lower(), int(m.group(4) or 0)


def find_defs(root, cls, meth, addr, read):
    """-> [(file, start, end)] of the matching definitions."""
    found = []
    if cls:
        pat = re.compile(r'^[^\s#/*][^\n]*\b%s::%s\s*\(' % (re.escape(cls), re.escape(meth)), re.M)
        needle = cls + '::' + meth
    else:                                                      # a free function: its name at the start of a line's declarator, not preceded by `::` or `.`/`->`
        pat = re.compile(r'^[^\s#/*][^\n]*?(?<![:\w.>])%s\s*\(' % re.escape(meth), re.M)
        needle = meth
    for f in sorted(glob.glob(os.path.join(root, 'Sources', '*.cpp'))):
        s = read(f)
        if needle not in s: continue
        for m in pat.finditer(s):
            start = m.start()
            if addr:
                prev = s[max(0, start - 120):start]
                a = re.findall(r'real addr (0x[0-9a-fA-F]+)', prev)
                if not a or a[-1].lower() != addr: continue
            # must be a definition (a '{' before the next ';' at depth 0 after the parameter list)
            j = m.end(); depth = 1
            while j < len(s) and depth:
                depth += (s[j] == '(') - (s[j] == ')'); j += 1
            k = j
            while k < len(s) and s[k] not in '{;': k += 1
            if k < len(s) and s[k] == '{':
                found.append((f, start, find_body_end(s, k)))
    return found


def find_decls(root, cls, meth, nth, read):
    f = os.path.join(root, 'Headers', cls + '.h')
    s = read(f)
    found, i = [], 0
    pat = re.compile(r'(?<![A-Za-z0-9_:])%s\s*\(' % re.escape(meth))
    while True:
        m = pat.search(s, i)
        if not m: break
        i = m.end()
        # skip matches inside comments
        ls = s.rfind('\n', 0, m.start()) + 1
        before = s[ls:m.start()]
        if '//' in before or before.lstrip().startswith(('*', '/*')): continue
        if s.rfind('/*', 0, m.start()) > s.rfind('*/', 0, m.start()): continue
        j, depth = m.end(), 1
        while j < len(s) and depth:
            depth += (s[j] == '(') - (s[j] == ')'); j += 1
        k = j
        while k < len(s) and s[k] not in ';{': k += 1
        # parameter list only (the trailing comment is not renamed)
        found.append((f, m.start(), j))
    if nth: found = found[nth - 1:nth]
    return found


def code_idents(s, names):
    """[(start, end, name)] of every identifier of `names` in s, outside comments and string/char literals, in text order"""
    out, i = [], 0
    while i < len(s):
        sk = lex_skip(s, i)
        if sk: i = sk[0]; continue
        m = IDENT.match(s, i)
        if m:
            if m.group() in names: out.append((m.start(), m.end(), m.group()))
            i = m.end()
        else: i += 1
    return out


def nth_match(pattern, norm, start):
    """index of the line an anchor designates: the first line at or after `start` matching the regex; a trailing `#N` selects the N-th match, a further
    trailing `@K` / `@-K` moves the result K lines down / up from the matching line (an anchor can thus sit on a line that no `use` row renames).
    norm[i] is the list of variants of line i (see line_variants); the line matches when any variant does"""
    m = re.match(r'^(.*?)(?:#(\d+))?(?:@(-?\d+))?$', pattern)
    pat, n, off = m.group(1), int(m.group(2) or 1), int(m.group(3) or 0)
    for i in range(start, len(norm)):
        if any(re.search(pat, v) for v in (norm[i] if isinstance(norm[i], list) else [norm[i]])):
            n -= 1
            if n == 0:
                j = i + off
                return j if 0 <= j < len(norm) else None
    return None


DECL_RE = r'^(\s*)((?:[A-Za-z_][\w:<>]*\s+)*[A-Za-z_][\w:<>]*(?:\s*\*+\s*|\s+))%s\s*;\s*$'


def line_variants(line, revert, limit=64):
    """the line with every use-renamed identifier taken back to its old name; a new name shared by several old variables gives one variant per choice"""
    keys = sorted({m.group() for m in IDENT.finditer(line) if m.group() in revert})
    variants = [{}]
    for k in keys:
        variants = [dict(v, **{k: o}) for v in variants for o in revert[k]][:limit]
    return [rename_in(line, v) for v in variants]


def is_decl_line(l):
    """a local-variable declaration line of a decompiled function: `type name;` / `type name [n];`, no call or initialiser"""
    t = l.strip()
    return bool(t) and t.endswith(';') and '(' not in t and '=' not in t and re.match(r'^[A-Za-z_][\w:<>]*(\s+[\w:<>]+|\s*\*+)*\s*\**\s*\w+\s*(\[[^\]]*\]\s*)*;$', t) is not None


def decl_block(lines, decl_i):
    """(end of the declarations after line decl_i, index of the first statement): the new variable of a `use` row is declared LAST in the block - gcc 4.0.1
    numbers pseudo-registers in declaration order, so declaring it beside the old one (earlier) changes register and stack-slot allocation of the old ones"""
    j = decl_i
    while j + 1 < len(lines) and is_decl_line(lines[j + 1]): j += 1
    k = j + 1
    while k < len(lines) and not lines[k].strip(): k += 1
    return j + 1, k


def apply_uses(use_rows, root, read, files, errors):
    """-> (pending, applied) for the `use` rows (see the module docstring); edits go into `files`."""
    pending = applied = 0
    groups = {}
    for r in use_rows: groups.setdefault(r[2], []).append(r)
    for target, rs in groups.items():
        try:
            cls, meth, addr, nth = parse_target(target)
            spans = find_defs(root, cls, meth, addr, read)
        except Exception as e:
            errors.append('%s: %s' % (target, e)); continue
        if len(spans) != 1:
            errors.append('%s (use): %d matches%s' % (target, len(spans), ' - add @0xADDR' if spans else '')); continue
        f, st, en = spans[0]
        s = read(f); scope = s[st:en]
        revert = {}
        for r in rs:
            if r[3] not in revert.setdefault(r[4], []): revert[r[4]].append(r[3])
        for (t, n, _, old, new, frm, to, occ, dmode) in rs:
            where = '%s:%d: %s' % (t, n, target)
            have = idents_in(scope)
            lines = scope.split('\n')
            if not IDENT.fullmatch(new) or new in KEYWORDS: errors.append('%s: %r is not a usable identifier' % (where, new)); continue
            declared = any(re.match(DECL_RE % re.escape(new), l) for l in lines)
            if declared:
                dn = next(re.match(DECL_RE % re.escape(new), l) for l in lines if re.match(DECL_RE % re.escape(new), l))
                do = next((re.match(DECL_RE % re.escape(old), l) for l in lines if re.match(DECL_RE % re.escape(old), l)), None)
                if do is not None and dn.group(2).split() != do.group(2).split():
                    print('WARNING %s: %s is declared as %r but %s as %r (a shared new name should have the same type; the byte-identical build is the check)' % (where, new, dn.group(2).strip(), old, do.group(2).strip()), file=sys.stderr)
            if new in have and not declared: errors.append('%s: %s already occurs in the function and is not a variable declared by a use row' % (where, new)); continue
            norm = [line_variants(l, revert) for l in lines]
            decl_i = next((i for i, l in enumerate(lines) if re.match(DECL_RE % re.escape(old), l)), None)
            if decl_i is None: errors.append('%s: no declaration of %s to copy the type from' % (where, old)); continue
            decl_end, body0 = decl_block(lines, decl_i)
            if frm in ('', '-'): a = body0
            else:
                a = nth_match(frm, norm, body0)
                if a is None: errors.append('%s: no line matches from=%r' % (where, frm)); continue
            if to in ('', '-'): b = len(lines)
            else:
                b = nth_match(to, norm, a + 1)
                if b is None or b <= a: errors.append('%s: no line after the from-line matches to=%r' % (where, to)); continue
            seg = '\n'.join(lines[a:b])
            if not occ.strip():
                if old not in idents_in(seg, comments=False):
                    if declared: applied += 1
                    else: errors.append('%s: %s does not occur in lines %d-%d' % (where, old, a + 1, b))
                    continue
                lines[a:b] = rename_in(seg, {old: new}).split('\n')
            else:
                try: want = sorted({int(x) for x in occ.split(',')})
                except ValueError: errors.append('%s: bad occ %r' % (where, occ)); continue
                family = {old} | {r[4] for r in rs if r[3] == old}
                hits = code_idents(seg, family)
                if want[-1] > len(hits): errors.append('%s: occ %d but only %d occurrences of %s in lines %d-%d' % (where, want[-1], len(hits), old, a + 1, b)); continue
                todo = [hits[k - 1] for k in want]
                bad = [h for h in todo if h[2] not in (old, new)]
                if bad: errors.append('%s: occurrence at %d is already named %s' % (where, bad[0][0], bad[0][2])); continue
                todo = [h for h in todo if h[2] == old]
                if not todo:
                    if declared: applied += 1
                    else: errors.append('%s: nothing to rename (occurrences already %s but %s is not declared)' % (where, new, new))
                    continue
                for (i, j, _) in sorted(todo, reverse=True): seg = seg[:i] + new + seg[j:]
                lines[a:b] = seg.split('\n')
            if not declared:
                m = re.match(DECL_RE % re.escape(old), lines[decl_i])
                lines.insert(decl_end if dmode == 'end' else decl_i + 1, '%s%s%s;' % (m.group(1), m.group(2), new))
            scope = '\n'.join(lines)
            pending += 1
        files[f] = s[:st] + scope + s[en:]
    return pending, applied


FIELDS_HEADER = 'Headers/FieldOffsets.h'


def class_spans(root, cls, read):
    """-> [(file, start, end)] of every function definition `... Cls::name(...) {...}` in Sources/*.cpp"""
    found = []
    pat = re.compile(r'^[^\s#/*][^\n]*\b%s::~?[A-Za-z0-9_]+\s*\(' % re.escape(cls), re.M)
    for f in sorted(glob.glob(os.path.join(root, 'Sources', '*.cpp'))):
        s = read(f)
        if cls + '::' not in s: continue
        for m in pat.finditer(s):
            j = m.end(); depth = 1
            while j < len(s) and depth:
                depth += (s[j] == '(') - (s[j] == ')'); j += 1
            k = j
            while k < len(s) and s[k] not in '{;': k += 1
            if k < len(s) and s[k] == '{':
                found.append((f, m.start(), find_body_end(s, k)))
    return found


def apply_fields(field_rows, root, read, files, errors):
    """-> (pending, applied); writes the generated constants header into `files`"""
    pending = applied = 0
    consts = {}                                              # constant name -> (offset, tier, evidence)
    by_off = {}
    for (t, n, classes, off, name, tier) in field_rows:
        if not IDENT.fullmatch(name) or name in KEYWORDS: errors.append('%s:%d: %r is not a usable identifier' % (t, n, name)); continue
        cname = 'k%s_%s' % (classes[0], name)
        if cname in consts and consts[cname] != off: errors.append('%s:%d: %s is already the constant for %s' % (t, n, cname, consts[cname])); continue
        consts[cname] = off
        for c in classes:
            if (c, off) in by_off and by_off[(c, off)] != cname: errors.append('%s:%d: %s +%s is already named %s' % (t, n, c, off, by_off[(c, off)])); continue
            by_off[(c, off)] = cname
    spans = {}
    for c in {c for (c, _) in by_off}:
        spans[c] = class_spans(root, c, read)
        if not spans[c]: errors.append('field rows: no method of %s found' % c)
    allsrc = ''.join(read(f) for f in glob.glob(os.path.join(root, 'Sources', '*.cpp')))        # constants already in the sources = applied
    applied = sum(len(re.findall(r'\b%s\b' % re.escape(c), allsrc)) for c in consts)
    edits = {}                                               # file -> [(start, end, replacement scope)]
    for c, sp in spans.items():
        offs = {int(o, 16): n for (cc, o), n in by_off.items() if cc == c}
        pat = re.compile(r'\b(self|param_1)(\s*\+\s*)(0x[0-9a-fA-F]+|[0-9]+)\b(?!\s*[\]\*])')       # Ghidra prints some offsets in decimal (self + 200 = 0xc8)
        for (f, st, en) in sp:
            s = read(f); scope = s[st:en]; out, i, ch = [], 0, False
            for m in pat.finditer(scope):
                o = int(m.group(3), 0 if m.group(3).lower().startswith('0x') else 10)
                if o not in offs: continue
                sk = None
                # leave comments and string literals alone
                ls = scope.rfind('\n', 0, m.start()) + 1
                if '//' in scope[ls:m.start()]: continue
                if scope.rfind('/*', 0, m.start()) > scope.rfind('*/', 0, m.start()): continue
                out.append((m.start(3), m.end(3), offs[o])); ch = True
            if ch:
                new = scope
                for (a, b, r) in sorted(out, reverse=True): new = new[:a] + r + new[b:]
                pending += len(out)
                edits.setdefault(f, []).append((st, en, new))
    for f, es in edits.items():                              # apply from the end so the spans stay valid
        s = read(f)
        for (st, en, new) in sorted(es, reverse=True): s = s[:st] + new + s[en:]
        files[f] = s
    lines = ['/* FieldOffsets.h - GENERATED by Tools/apply_renames.py from the `field` rows of Tools/renames/*.tsv. Do not edit by hand.',
             ' * Named byte offsets of the object fields that the ported sources reach as `self + 0xOFFSET`. static const int: the compiled code is the same as with the literal. */',
             '#ifndef FIELD_OFFSETS_H', '#define FIELD_OFFSETS_H', '']
    meta = {(t, off, nm): (tier) for (t, n, cl, off, nm, tier) in field_rows}
    for cname in sorted(consts, key=lambda c: (c.split('_')[0], int(consts[c], 16), c)):
        lines.append('static const int %s = %s;' % (cname, consts[cname]))
    lines += ['', '#endif', '']
    files[os.path.join(root, FIELDS_HEADER)] = '\n'.join(lines)
    return pending, applied


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--check', action='store_true'); ap.add_argument('--no-use', action='store_true', help='ignore the `use` rows (to see the text the anchors of the use rows are matched against)'); ap.add_argument('--root', default=os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
    ap.add_argument('tables', nargs='*')
    a = ap.parse_args()
    tables = a.tables or sorted(glob.glob(os.path.join(a.root, 'Tools', 'renames', '*.tsv')))
    rows, use_rows, field_rows = [], [], []
    for t in tables:
        dmode = 'end'                                   # where the new variable of this table's `use` rows is declared (see `#!use-decl:` in the module docstring)
        for n, l in enumerate(open(t), 1):
            if l.startswith('#!use-decl:'):
                dmode = l.split(':', 1)[1].strip()
                if dmode not in ('end', 'beside'): sys.exit('%s:%d: #!use-decl must be end or beside' % (t, n))
                continue
            if l.startswith('#') or not l.strip(): continue
            f = l.rstrip('\n').split('\t')
            if f[0] == 'field':                         # field CLASSES OFFSET NAME TIER EVIDENCE
                if len(f) < 5 or f[4] not in ('CONFIRMED', 'INFERRED', 'UNKNOWN') or not re.fullmatch(r'0x[0-9a-fA-F]+', f[2]):
                    sys.exit('%s:%d: bad field row (field CLASSES 0xOFFSET name tier [evidence])' % (t, n))
                field_rows.append((t, n, f[1].split(','), f[2].lower(), f[3], f[4]))
                continue
            if len(f) < 5 or f[0] not in ('def', 'decl', 'use') or f[4] not in ('CONFIRMED', 'INFERRED', 'UNKNOWN'):
                sys.exit('%s:%d: bad row (kind target old new tier [evidence [from to]])' % (t, n))
            if f[0] == 'use':
                f += [''] * (9 - len(f))
                use_rows.append((t, n, f[1], f[2], f[3], f[6], f[7], f[8], dmode))
                continue
            rows.append((t, n, f[0], f[1], f[2], f[3]))
    # group rows by (kind, target) so one scope gets all its renames at once
    groups = {}
    for r in rows: groups.setdefault((r[2], r[3]), []).append(r)
    files, errors, pending, applied = {}, [], 0, 0
    read = lambda f: files[f] if f in files else open(f).read()
    for (kind, target), rs in groups.items():
        try:
            cls, meth, addr, nth = parse_target(target)
            spans = find_defs(a.root, cls, meth, addr, read) if kind == 'def' else find_decls(a.root, cls, meth, nth, read)
        except Exception as e:
            errors.append('%s: %s' % (target, e)); continue
        if len(spans) != 1:
            errors.append('%s (%s): %d matches%s' % (target, kind, len(spans), ' - add @0xADDR' if kind == 'def' and spans else '')); continue
        f, st, en = spans[0]
        s = read(f)
        scope = s[st:en]
        have = idents_in(scope)
        code = idents_in(scope, comments=False)     # a new name may repeat a word in a comment, never a code identifier
        mapping = {}
        for t, n, _, _, old, new, in [(r[0], r[1], r[2], r[3], r[4], r[5]) for r in rs]:
            if not IDENT.fullmatch(new) or new in KEYWORDS:
                errors.append('%s:%d: %r is not a usable identifier' % (t, n, new)); continue
            if old not in have:
                if new in have: applied += 1; continue
                errors.append('%s:%d: %s: neither %s nor %s occurs' % (t, n, target, old, new)); continue
            if new in code and new != old:
                errors.append('%s:%d: %s: %s already occurs in the function' % (t, n, target, new)); continue
            if new in mapping.values():
                errors.append('%s:%d: %s: two renames to %s' % (t, n, target, new)); continue
            mapping[old] = new
        if not mapping: continue
        pending += len(mapping)
        files[f] = s[:st] + rename_in(scope, mapping) + s[en:]
    up, ua = apply_uses([] if a.no_use else use_rows, a.root, read, files, errors)
    pending += up; applied += ua
    if field_rows:
        fp, fa = apply_fields(field_rows, a.root, read, files, errors)
        pending += fp; applied += fa
    for e in errors: print('ERROR', e, file=sys.stderr)
    if not a.check and not errors:
        for f, s in files.items(): open(f, 'w').write(s)
    # structural patches (after the renames)
    import subprocess
    def run_patch(pf, *flags):
        with open(pf) as fh:
            return subprocess.call(['patch', '-p1', '-s', '-d', a.root] + list(flags), stdin=fh, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL) == 0
    p_pending = p_done = 0
    for pf in sorted(glob.glob(os.path.join(a.root, 'Tools', 'renames', 'patches', '*.patch'))):
        if run_patch(pf, '--dry-run', '-R'): p_done += 1; continue
        if not run_patch(pf, '--dry-run'):
            errors.append('%s: applies neither forward nor in reverse (the source text differs from what the patch was made against)' % os.path.basename(pf)); print('ERROR', errors[-1], file=sys.stderr); continue
        p_pending += 1
        if not a.check and not errors: run_patch(pf)
    if a.check:
        print('%d renames pending, %d already applied, %d patches pending, %d patches applied, %d errors' % (pending, applied, p_pending, p_done, len(errors)))
        sys.exit(1 if pending or p_pending or errors else 0)
    if errors: sys.exit(1)
    print('applied %d renames in %d files (%d already applied), %d patches (%d already applied)' % (pending, len(files), applied, p_pending, p_done))


if __name__ == '__main__':
    main()
