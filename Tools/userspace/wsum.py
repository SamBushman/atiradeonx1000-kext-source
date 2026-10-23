#!/usr/bin/env python3
"""wsum.py DIR FUNCTION [VAR ...] - compact web summary of the remaining placeholder locals of a userspace corpus function (uses find_webs).
Per variable: number of webs, and per web the line span, an idiom tag (COPYIDX = string-copy loop index, NCPY = result of a _ncpy digit writer,
LOOPIDX = counted loop index) and the first defining line. Used to decide names for the webs; see emit_webs.py for turning a spec into rows."""
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import find_webs as F
PH = re.compile(r'\b([a-z]{0,3}Var\d+|local_[0-9a-f]+|param_\d+|in_[a-z0-9]+|[a-z]?Stack_[0-9a-f]+)\b')

def main():
    d, fn = sys.argv[1:3]
    body, brace = F.load(d, fn)
    vars_ = sys.argv[3:]
    if not vars_:
        seen = []
        for l in F.CURRENT[brace + 1:]:
            for v in PH.findall(l):
                if v not in seen: seen.append(v)
        vars_ = seen
    nodes, entry = F.build_cfg(body, brace)
    for v in vars_:
        try:
            w, ent = F.webs(nodes, entry, v)
        except SystemExit as e:
            print('== %s: %s' % (v, e)); continue
        print('== %s: %d webs%s' % (v, len(w), ' (+ENTRY)' if ent else ''))
        for k in range(len(w)):
            ls = w[k]
            txt = [body[x].strip() for x in ls]
            tag = ''
            if any(re.match(r'^%s = 0;$' % v, t) for t in txt) and any(re.search(r'\b%s\b.*= cVar\d+;$' % v, t) for t in txt): tag = 'COPYIDX'
            elif txt and '_ncpy' in txt[0]: tag = 'NCPY'
            elif txt and (lambda m: m and any(t == '%s = %s;' % (m.group(1), v) for t in txt))(re.match(r'^%s = (\w+) \+ 1;$' % v, txt[0])): tag = 'NEXTIDX'
            show = [t for t in txt[:2]]
            print('  web %d [%s] %s: %s' % (k, tag, ','.join('%d-%d' % r for r in F.runs(ls)) if len(ls) < 12 else '%d..%d(%d)' % (ls[0], ls[-1], len(ls)), ' | '.join(s[:70] for s in show)))
main()
