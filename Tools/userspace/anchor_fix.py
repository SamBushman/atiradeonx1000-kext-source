#!/usr/bin/env python3
"""anchor_fix.py CORPUS_DIR      (issue #84)
The stock builds a data pointer as `anchor + offset` where the anchor is a raw address near the start of __data (Ghidra prints it `local_60 = FUN_001d8514;` or
`local_58 = 0x1d6d90;`, and `0x3800 + local_60` reaches DAT_001dbd14). In the rebuilt image __data sits elsewhere (one constant displacement for the whole blob), so the
raw address points nowhere. Every such assignment whose value lies in [0x1cc164, 0x1e8740) (just below / in the stock's __data) becomes ANCH(value) =
address of DAT_001dbd14 + (value - 0x1dbd14): the same displacement the linker applied to the data blob. Anchors that lie in __TEXT (0x19f634 ...) are NOT touched here."""
import re, sys, glob, os
LO, HI = 0x1cc164, 0x1e8740
def main(corpus):
    n = 0
    for f in sorted(glob.glob(os.path.join(corpus, 'part_*.c'))):
        s = open(f).read()
        def sub(m):
            v = m.group(2)
            x = int(v[4:], 16) if v.startswith('FUN_') else int(v, 16)
            if not (LO <= x < HI): return m.group(0)
            if v.startswith('FUN_') and re.search(r'@ 0x%x ' % x, s) and False: return m.group(0)
            return '%s= ANCH(0x%x);' % (m.group(1), x)
        t = re.sub(r'(?m)^(\s*(?:\([^;=]*\)\s*)?[^;=\n]*?)= (?:\(\w+ \*?\))?(FUN_001[0-9a-f]{5}|0x0*1[0-9a-f]{5});', lambda m: sub(m) if (lambda g: True)(m) else m.group(0), s)
        k = len(re.findall(r'ANCH\(', t)) - len(re.findall(r'ANCH\(', s))
        n += k
        if k: open(f, 'w').write(t)
    for hf in ('decls.h',):
        p = os.path.join(corpus, hf); h = open(p).read()
        if '#define ANCH(' not in h:
            if not re.search(r'\bDAT_001dbd14\b', h): h += 'extern unsigned char DAT_001dbd14;\n'
            open(p, 'w').write(h + '#define ANCH(v) ((int)&DAT_001dbd14 + ((v) - 0x1dbd14))\n')
    print(n, 'anchor assignments rewritten')
if __name__ == '__main__': main(sys.argv[1])
