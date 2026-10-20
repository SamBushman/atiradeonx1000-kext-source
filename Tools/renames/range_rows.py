#!/usr/bin/env python3
"""range_rows.py - write `use` rows for a per-role rename from LINE RANGES instead of hand-written anchor regexes.

Usage: range_rows.py SPEC.txt >> Tools/renames/<Table>.tsv      (run from the repository root, on a tree where the table is NOT yet applied for this function)
SPEC.txt, one directive per line ('#' comments and blank lines ignored):
    @ <source file under Sources/>  <Class::method@0xADDR>      selects the function (line numbers below are 1-based lines of that file as committed in HEAD)
    <old> <new> <first-line> <last-line> <CONFIRMED|INFERRED|UNKNOWN> <evidence...>
          rename `old` to `new` on the lines first..last inclusive (last-line may be '-' = to the end of the function)
    <old> <new> * * <tier> <evidence...>   catch-all for whatever is left (emitted LAST, from the first line after the declarations to the end)
    <old> <new> <a> <b> <tier> <evidence> | occ=1,3                       (optional) only those 1-based occurrences of `old` inside the range
For every range the `from`/`to` anchors are regexes of the exact HEAD text of the first line and of the line after the last, with the `#N` suffix that picks the
right one among identical lines, so the rows keep working while other rows of the table rename names on those lines (the applier takes use-renames back).
Do not mix with `def` rows of the same function: a def changes the text the anchors have to match.
"""
import glob, re, subprocess, sys


def head_lines(path):
    return subprocess.run(['git', 'show', 'HEAD:' + path], capture_output=True, text=True, check=True).stdout.split('\n')


IDENT = re.compile(r'[A-Za-z_]\w*')


def renamed_names(target):
    """every identifier that some `use` row of the function (any table) can rename or has produced: the applier matches anchors against the line with those taken
    back (and `field` constants taken back to literals), so an anchor may not rely on their spelling: they become wildcards"""
    names = set()
    for p in sorted(glob.glob('Tools/renames/*.tsv')):
        for ln in open(p):
            f = ln.rstrip('\n').split('\t')
            if len(f) > 4 and f[0] == 'use' and f[1] == target:
                names.add(f[2]); names.add(f[3])
    return names


def pattern_of(text, names):
    out, pos = [], 0
    for m in IDENT.finditer(text):
        out.append(re.escape(text[pos:m.start()]).replace('\\ ', r'\s+'))
        tok = m.group(0)
        out.append(r'\w+' if (tok in names or re.fullmatch(r'k[A-Z]\w*_\w+', tok)) else re.escape(tok))
        pos = m.end()
    out.append(re.escape(text[pos:]).replace('\\ ', r'\s+'))
    return '^\\s*' + ''.join(out) + '$'


def anchor(lines, idx, lo, names):
    """regex (with #N) designating line idx (0-based) as the N-th line, counted from line lo (0-based), that the regex matches"""
    rx = pattern_of(lines[idx].strip(), names)
    n = sum(1 for j in range(lo, idx + 1) if re.search(rx, lines[j].strip()))
    return rx + ('#%d' % n if n > 1 else '')


def main():
    spec = open(sys.argv[1]).read().split('\n')
    path = target = lines = None
    fn_lo = fn_hi = 0
    rows, tail = [], []
    for raw in spec:
        s = raw.strip()
        if not s or s.startswith('#'):
            continue
        if s.startswith('@'):
            _, f, target = s.split(None, 2)
            path = 'Sources/' + f
            lines = head_lines(path)
            m = re.search(r'@0x([0-9a-f]+)', target)
            addr = m.group(1) if m else None
            meth = target.split('@')[0].split('::')[-1]
            start = None
            for i, l in enumerate(lines):
                if (addr and ('real addr 0x' + addr) in l) or (not addr and re.search(r'\b' + meth + r'\(', l)):
                    start = i
                    break
            if start is None:
                sys.exit('function not found: ' + target)
            fn_lo = start
            names = renamed_names(target)
            # the function ends at the first line that is exactly "}" after start
            fn_hi = next(i for i in range(start, len(lines)) if lines[i] == '}')
            continue
        opt = ''
        if '|' in s:
            s, opt = [x.strip() for x in s.rsplit('|', 1)]
        f = s.split(None, 5)
        old, new, a, b, tier = f[:5]
        ev = f[5] if len(f) > 5 else ''
        occ = opt.split('=')[1] if opt.startswith('occ=') else ''
        if a == '*':
            tail.append('\t'.join(['use', target, old, new, tier, ev, '-', '-']))
            continue
        a, ia = int(a), None
        ia = a - 1
        if b == '-':
            to = '-'
        else:
            ib = int(b)  # last line inclusive; the `to` line is the next one
            if ib >= fn_hi:
                to = '-'
            else:
                to = anchor(lines, ib, ia + 1, names)  # 0-based index of line (b+1); counted after the from-line
        fr = anchor(lines, ia, fn_lo, names)
        rows.append('\t'.join(['use', target, old, new, tier, ev, fr, to] + ([occ] if occ else [])))
    sys.stdout.write('\n'.join(rows + tail) + '\n')


if __name__ == '__main__':
    main()
