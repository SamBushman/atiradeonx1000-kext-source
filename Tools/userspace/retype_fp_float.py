#!/usr/bin/env python3
"""retype_fp_float.py [--apply] FUNC...   (issue #210 / #209)

Ghidra types the FPR temporaries of single-precision code as `double` and re-creates the rounding with (double)/(float) casts, so gcc emits double-precision
fmul/fadd/frsp where stock has fmuls/fmadds/fmsubs (extra instructions, 1-2 ULP value differences).  For the named functions this rewrites the body so
the arithmetic is really single precision: every local `double NAME` declaration becomes `float NAME` and every `(double)` / `(float)` value cast is deleted
(pointer casts like `(float *)` are untouched).  Only apply it to functions the FP audit (g5logs/nov2_209/fpaudit.py) shows to be single precision in stock
(stock dbl=0): integer<->float conversions inside such a body must be re-checked by hand (a deleted `(float)` of an int division would change meaning).
"""
import re, sys, glob, os
HERE = os.path.dirname(os.path.abspath(__file__))
CORPUS = os.path.join(HERE, '..', '..', 'Userspace', 'ATIRadeonX1000GLDriver', 'ppc')
apply_ = '--apply' in sys.argv
names = [a for a in sys.argv[1:] if not a.startswith('--')]
for name in names:
    done = False
    for p in sorted(glob.glob(os.path.join(CORPUS, '**', 'part_*.c'), recursive=True)):
        s = open(p).read()
        m = re.search(r'^[A-Za-z_][^\n;{]*\b%s\([^\n]*\n(?:[^\n]*\n)*?\{\n' % re.escape(name), s, re.M)
        if not m: continue
        end = s.index('\n}\n', m.end())
        body = s[m.end():end]
        nl = len(re.findall(r'^  double \w+( = [^;]+)?;', body, re.M))
        nb = len(re.findall(r'\((?:double|float)\)', body))
        nb2 = re.sub(r'^  double (\w+)', r'  float \1', body, flags=re.M)
        nb2 = re.sub(r'\((?:double|float)\)', '', nb2)
        print('%-32s %s: %d local decls -> float, %d casts removed' % (name, os.path.basename(p), nl, nb))
        if apply_: open(p, 'w').write(s[:m.end()] + nb2 + s[end:])
        done = True
        break
    if not done: print('NOT FOUND', name)
