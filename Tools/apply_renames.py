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
    kind  target  old  new  tier  evidence  [from  to]
  kind    def   rename an identifier inside one function DEFINITION in Sources/*.cpp (signature included)
          decl  rename a parameter name inside one function DECLARATION in Headers/<Class>.h
          use   rename ONE USE of a variable that the decompile reuses for several unrelated roles: only the lines from the first line matching the
                regex `from` up to (not including) the first following line matching the regex `to` (empty or '-' = to the end of the function;
                `from` '-' = from the first line after the declarations). `new` is declared next to the declaration of `old` (same type), so the
                variable is split in two. Rows of one function are applied in table order and may split the same `old` several times.
  target  Class::method, optionally Class::method@0xADDR (several definitions with that name: the one whose "real addr" comment matches)
          or Class::method#N (decl only: the N-th declaration, 1-based). A FREE function (no class) is written with an empty class: `::pcl_CopyPix`
          (def rows only; a decl row needs a class header)
  old/new identifiers. A rename applies to the whole function scope, comments included, string literals excluded.
  tier    CONFIRMED (the meaning is established by a caller, a test or a disassembly) | INFERRED (consistent with every use seen) | UNKNOWN (a
          placeholder with a readable shape, e.g. unknown_0x84)
  evidence  one line: where the meaning comes from (not interpreted by the tool)

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


def nth_match(pattern, norm, start):
    """index of the first line at or after `start` matching the regex; a trailing `#N` on the pattern selects the N-th match instead"""
    m = re.match(r'^(.*)#(\d+)$', pattern)
    pat, n = (m.group(1), int(m.group(2))) if m else (pattern, 1)
    for i in range(start, len(norm)):
        if re.search(pat, norm[i]):
            n -= 1
            if n == 0: return i
    return None


DECL_RE = r'^(\s*)((?:[A-Za-z_][\w:<>]*\s+)*[A-Za-z_][\w:<>]*(?:\s*\*+\s*|\s+))%s\s*;\s*$'


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
            if revert.get(r[4], r[3]) != r[3]: errors.append('%s:%d: %s is the new name of two different variables in %s' % (r[0], r[1], r[4], target))
            revert[r[4]] = r[3]
        for (t, n, _, old, new, frm, to) in rs:
            where = '%s:%d: %s' % (t, n, target)
            have = idents_in(scope)
            lines = scope.split('\n')
            if not IDENT.fullmatch(new) or new in KEYWORDS: errors.append('%s: %r is not a usable identifier' % (where, new)); continue
            declared = any(re.match(DECL_RE % re.escape(new), l) for l in lines)
            if new in have and not declared: errors.append('%s: %s already occurs in the function and is not a variable declared by a use row' % (where, new)); continue
            norm = [rename_in(l, revert) for l in lines]
            decl_i = next((i for i, l in enumerate(lines) if re.match(DECL_RE % re.escape(old), l)), None)
            if decl_i is None: errors.append('%s: no declaration of %s to copy the type from' % (where, old)); continue
            j = decl_i + 1                                          # the first line after the declarations
            while j < len(lines) and (re.match(DECL_RE % r'\w+', lines[j]) or not lines[j].strip()): j += 1
            body0 = j
            if frm in ('', '-'): a = body0
            else:
                a = nth_match(frm, norm, body0)
                if a is None: errors.append('%s: no line matches from=%r' % (where, frm)); continue
            if to in ('', '-'): b = len(lines)
            else:
                b = nth_match(to, norm, a + 1)
                if b is None: errors.append('%s: no line after the from-line matches to=%r' % (where, to)); continue
            seg = '\n'.join(lines[a:b])
            if old not in idents_in(seg, comments=False):
                if declared: applied += 1
                else: errors.append('%s: %s does not occur in lines %d-%d' % (where, old, a + 1, b))
                continue
            lines[a:b] = rename_in(seg, {old: new}).split('\n')
            if not declared:
                m = re.match(DECL_RE % re.escape(old), lines[decl_i])
                lines.insert(decl_i + 1, '%s%s%s;' % (m.group(1), m.group(2), new))
            scope = '\n'.join(lines)
            pending += 1
        files[f] = s[:st] + scope + s[en:]
    return pending, applied


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--check', action='store_true'); ap.add_argument('--root', default=os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
    ap.add_argument('tables', nargs='*')
    a = ap.parse_args()
    tables = a.tables or sorted(glob.glob(os.path.join(a.root, 'Tools', 'renames', '*.tsv')))
    rows, use_rows = [], []
    for t in tables:
        for n, l in enumerate(open(t), 1):
            if l.startswith('#') or not l.strip(): continue
            f = l.rstrip('\n').split('\t')
            if len(f) < 5 or f[0] not in ('def', 'decl', 'use') or f[4] not in ('CONFIRMED', 'INFERRED', 'UNKNOWN'):
                sys.exit('%s:%d: bad row (kind target old new tier [evidence [from to]])' % (t, n))
            if f[0] == 'use':
                f += [''] * (8 - len(f))
                use_rows.append((t, n, f[1], f[2], f[3], f[6], f[7]))
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
    up, ua = apply_uses(use_rows, a.root, read, files, errors)
    pending += up; applied += ua
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
