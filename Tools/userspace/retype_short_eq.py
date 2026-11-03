#!/usr/bin/env python3
"""retype_short_eq.py [--apply]   (issue #209)

Ghidra types 16-bit loads as signed `short`; stock zero-extends them (lhz) and compares unsigned, so the rebuilt image gets `lha` (cracked, slow on the
PPC970) where stock has `lhz`.  For an EQUALITY / INEQUALITY test the signedness is unobservable, so these forms are rewritten to `ushort`:
    *(short *)(P) ==|!= <literal in -0x8000..0x7fff>   ->   *(ushort *)(P) ==|!= <literal & 0xffff>
    *(short *)(P) ==|!= *(short *)(Q)                  ->   both sides ushort
Nothing else is touched (ordered comparisons / arithmetic keep their signedness).  Dry run unless --apply.
"""
import re, sys, glob, os
HERE = os.path.dirname(os.path.abspath(__file__))
CORPUS = os.path.join(HERE, '..', '..', 'Userspace', 'ATIRadeonX1000GLDriver', 'ppc')
apply_ = '--apply' in sys.argv
PFX = '*(short *)'
LIT = re.compile(r'\s*(==|!=)\s*(-?(?:0x[0-9a-fA-F]+|\d+))(?![\w.(\[])')
OP = re.compile(r'\s*(==|!=)\s*')

def operand_end(s, i):
    """end index of the operand starting at s[i] (balanced paren group, or a simple lvalue token)"""
    if s[i] == '(':
        d = 0
        for j in range(i, len(s)):
            if s[j] == '(': d += 1
            elif s[j] == ')':
                d -= 1
                if d == 0: return j + 1
        return None
    m = re.match(r'[\w]+(?:(?:->|\.)\w+|\[[^\]]*\])*', s[i:])
    return i + m.end() if m else None

def process(s):
    out = []; i = 0; n_lit = n_pair = 0
    while True:
        k = s.find(PFX, i)
        if k < 0: out.append(s[i:]); break
        a = k + len(PFX)
        e = operand_end(s, a)
        out.append(s[i:k]); i = k
        if e is None: out.append(PFX); i = a; continue
        # not a store target / not already part of a larger *(short*) expression we mis-handle: require preceding char to be a delimiter
        pre = s[max(0, k - 1):k]
        m = LIT.match(s, e)
        if m and pre in ('(', ' ', '!', '&', '|'):
            v = int(m.group(2), 0)
            if -0x8000 <= v <= 0x7fff:
                out.append('*(ushort *)' + s[a:e] + ' ' + m.group(1) + ' 0x%x' % (v & 0xffff)); i = m.end(); n_lit += 1; continue
        m = OP.match(s, e)
        if m and s.startswith(PFX, m.end()) and pre in ('(', ' ', '!', '&', '|'):
            a2 = m.end() + len(PFX); e2 = operand_end(s, a2)
            if e2 is not None and not re.match(r'\s*(?:[-+*/%<>&|^?]|\[)', s[e2:e2 + 3]):
                out.append('*(ushort *)' + s[a:e] + ' ' + m.group(1) + ' *(ushort *)' + s[a2:e2]); i = e2; n_pair += 1; continue
        out.append(PFX); i = a
    return ''.join(out), n_lit, n_pair

tl = tp = 0
for p in sorted(glob.glob(os.path.join(CORPUS, '**', 'part_*.c'), recursive=True)):
    s = open(p).read()
    t, nl, np_ = process(s)
    if nl or np_:
        print('%s: %d literal compares, %d pair compares' % (os.path.basename(p), nl, np_))
        tl += nl; tp += np_
        if apply_: open(p, 'w').write(t)
print('total: %d literal, %d pair%s' % (tl, tp, '' if apply_ else '  (dry run)'))
