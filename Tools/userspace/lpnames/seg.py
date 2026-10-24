#!/usr/bin/env python3
"""seg.py DIR SPEC : `use` rows for segments given as FILE-LINE ranges with optional partial first/last lines.
SPEC lines (tab separated, '#' comment): FN VAR NEW START END [FIRST [LAST]] TIER EVIDENCE   -- wait, use the named columns below:
    FN<TAB>VAR<TAB>NEW<TAB>START-END[:first=lhs|rhs][:last=lhs|rhs]<TAB>TIER<TAB>EVIDENCE
VAR is the GHIDRA name. START/END are line numbers of the CURRENT tree (as printed by fshow.py). The segment renames VAR in lines START..END; with
first=P only part P (lhs/rhs of the first plain `=`) of line START, with last=P only part P of line END. Prints rows for apply_names.py."""
import sys, os, re, glob
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, spec = sys.argv[1:3]
cache = {}
def info(fn):
    if fn in cache: return cache[fn]
    body, brace = F.load(d, fn)
    first = None
    for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        for i, l in enumerate(open(pf).read().split('\n')):
            m = re.match(r'^/\* (\S+) @ 0x', l)
            if m and m.group(1) == fn: first = i + 1
        if first: break
    cache[fn] = (body, brace, first); return cache[fn]
def anchor(body, brace, i, start):
    """regex for line i; @N = Nth equal line counted from the function start (from-rows) -> returns (regex, nth)"""
    txt = body[i].strip()
    eq = [k for k in range(brace + 1, len(body)) if body[k].strip() == txt]
    return '^\\s*' + re.escape(txt) + '$', eq.index(i) + 1
for l in open(spec):
    if not l.strip() or l.startswith('#'): continue
    fn, var, new, rg, tier, ev = l.rstrip('\n').split('\t')[:6]
    body, brace, first = info(fn)
    for rgi in rg.split(','):
        parts = rgi.split(':'); a, _, b = parts[0].partition('-'); a = int(a); b = int(b) if b else a
        fp = lp = 'all'
        for p in parts[1:]:
            k, v = p.split('='); 
            if k == 'first': fp = v
            elif k == 'last': lp = v
        ia, ib = a - first, b - first
        for k in (ia, ib):
            if not (brace < k < len(body)): sys.exit('line out of body: %s %s' % (fn, rgi))
        rx, nth = anchor(body, brace, ia, ia)
        frm = rx + ('@%d' % nth if nth > 1 else '')
        # end: if the last line is taken whole, `to` = the next line (taken not at all); with a partial last line, `to` = the last line itself
        if lp == 'all':
            k = ib + 1
            while k < len(body) and not body[k].strip(): k += 1
            if k >= len(body) or body[k].strip() == '}' and k == len(body) - 1 or k >= len(body): to = ''; lastp = 'none'
            else: to = anchor(body, brace, k, ia)[0]; lastp = 'none'
        else:
            to = anchor(body, brace, ib, ia)[0]; lastp = lp
        if to:
            rxto = re.compile(to)
            hit = next((k for k in range(ia + 1 if lp != 'all' or True else ia, len(body)) if rxto.match(body[k])), None)
            want = ib if lp != 'all' else ib + 1
            if hit is None or (hit != want and not (lp == 'all' and hit > ib)): print('# WARN to-anchor of %s %s matches line %s not %s' % (fn, rg, hit and hit + first, want + first), file=sys.stderr)
        print('\t'.join(['use', fn, var, new, tier, ev, frm, to, fp if fp != 'all' else 'all', lastp]))
