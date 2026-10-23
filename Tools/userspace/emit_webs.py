#!/usr/bin/env python3
"""emit_webs.py DIR FUNCTION SPEC.tsv - like `find_webs.py DIR FUNCTION --emit SPEC`, with web filters.

SPEC lines (tab separated, `#` comments): VAR<TAB>WEBS<TAB>newname<TAB>tier<TAB>evidence
  WEBS  = `*` (whole function: a `local` row) or a comma list of web numbers as printed by `find_webs.py DIR FUNCTION VAR`;
          an item may carry a line filter `N<L` / `N>=L`... written `3<200` (lines of web 3 below body line 200) or `3>200` (lines >= 200),
          for a web that joins two roles through an assignment inside a condition (find_webs merges them; the filter splits the lines again -
          only valid when the two parts have no def-use connection).
Prints the rows for apply_names.py. Web numbers depend on the current text of FUNCTION (renames are taken back to Ghidra's text first)."""
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import find_webs as F


def main():
    d, fn, spec = sys.argv[1:4]
    body, brace = F.load(d, fn)
    nodes, entry = F.build_cfg(body, brace)
    rows = []; cache = {}
    for l in open(spec):
        if not l.strip() or l.startswith('#'): continue
        var, wl, new, tier, ev = l.rstrip('\n').split('\t')[:5]
        if wl == '*':
            rows.append('local\t%s\t%s\t%s\t%s\t%s' % (fn, var, new, tier, ev)); continue
        if var not in cache: cache[var] = F.webs(nodes, entry, var)[0]
        for w in wl.split(','):
            m = re.match(r'^(\d+)(?:([<>])(\d+))?$', w)
            lines = cache[var][int(m.group(1))]
            if m.group(2) == '<': lines = [x for x in lines if x < int(m.group(3))]
            if m.group(2) == '>': lines = [x for x in lines if x >= int(m.group(3))]
            for (x, y) in F.runs(lines):
                txt = body[x].strip()
                eq = [i for i in range(brace + 1, len(body)) if body[i].strip() == txt]
                nth = eq.index(x) + 1
                frm = '^\\s*' + re.escape(txt) + '$' + ('@%d' % nth if nth > 1 else '')
                rows.append('use\t%s\t%s\t%s\t%s\t%s\t%s\t+%d' % (fn, var, new, tier, ev, frm, y - x + 1))
    print('\n'.join(rows))


if __name__ == '__main__':
    main()
