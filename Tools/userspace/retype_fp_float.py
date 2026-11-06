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
vars_ = '--vars' in sys.argv   # per-variable mode for functions where stock keeps some double math: see retype_vars() below
strip_ = '--strip' in sys.argv   # drop `(double)` in front of float constants / float loads / (float) values (never in front of CONCAT44 magic conversions)
keep_ = [a[7:].split(',') for a in sys.argv if a.startswith('--keep=')]
keep_ = set(keep_[0]) if keep_ else set()
sig_ = '--sig' in sys.argv     # also retype `double` params / return type in the signature to float, and call retyped callees directly
names = [a for a in sys.argv[1:] if not a.startswith('--')]

def retype_vars(hdr, body):
    """--vars: for functions whose stock code mixes single and double math.  Every `double` parameter/local that is never involved in a line using DOUBLE_xxx / CONCAT44 (magic-number
    int<->double conversions and real double constants) becomes `float` (--keep=a,b leaves named variables double); `(double)` in front of FLOAT_xxx constants and in front of the
    retyped variables is dropped, so the arithmetic around them is single precision (fmuls/fmadds like stock) instead of double + frsp.  Everything else is left alone."""
    lines = (hdr + body).split('\n')
    cand = set(re.findall(r'\bdouble (\w+)', hdr + body)) - set(names)   # (`double fname(` is a return type, left alone)
    bad = set(keep_)
    for l in lines:
        if 'DOUBLE_' in l or 'CONCAT44' in l:
            for v in cand:
                if not re.search(r'\b%s\b' % v, l): continue
                assigned = re.match(r'\s*(?:\w+ )?%s = ' % v, l)
                # a variable assigned from a real double constant or used as the bias of a magic-number int->double conversion must stay double;
                # a variable that merely RECEIVES the result of such an expression (or is compared against a DOUBLE_ constant) holds a float value
                if (assigned and 'DOUBLE_' in l.split('=', 1)[1] and 'CONCAT44' not in l) or (not assigned and 'CONCAT44' in l): bad.add(v)
    good = sorted(cand - bad)
    for v in good:
        hdr = re.sub(r'\bdouble %s\b' % v, 'float ' + v, hdr)
        body = re.sub(r'(?m)^(\s+)double %s\b' % v, r'\1float ' + v, body)
        body = re.sub(r'\(double\)%s\b' % v, v, body)
    body = re.sub(r'\(double\)(?=FLOAT_)', '', body)
    hdr = re.sub(r'\(double\)(?=FLOAT_)', '', hdr)
    return hdr, body, good, sorted(bad & cand)

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
        if strip_:
            b2 = re.sub(r'\(double\)(?=FLOAT_|\*\(float \*\)|\(float\))', '', body)
            print('%-32s %s: %d (double) casts dropped' % (name, os.path.basename(p), len(body) - len(b2) and (body.count('(double)') - b2.count('(double)'))))
            if apply_: open(p, 'w').write(s[:m.end()] + b2 + s[end:])
            done = True
            break
        if vars_:
            h2, b2, good, kept = retype_vars(s[m.start():m.end()], body)
            print('%-32s %s: float: %s | kept double: %s' % (name, os.path.basename(p), ' '.join(good), ' '.join(kept)))
            if apply_: open(p, 'w').write(s[:m.start()] + h2 + b2 + s[end:])
            done = True
            break
        nb2 = re.sub(r'^  double (\w+)', r'  float \1', body, flags=re.M)
        nb2 = re.sub(r'\((?:double|float)\)', '', nb2)
        if sig_:
            hdr = re.sub(r'\bdouble\b', 'float', s[m.start():m.end()])
            nb2 = re.sub(r'\(\(float \(\*\)\(\)\)(\w+)\)\(|\(\(double \(\*\)\(\)\)(\w+)\)\(',
                         lambda mm: ((mm.group(1) or mm.group(2)) + '(') if (mm.group(1) or mm.group(2)) in names else mm.group(0), nb2)
            print('%-32s %s: signature retyped, %d local decls, %d casts' % (name, os.path.basename(p), nl, nb))
            if apply_: open(p, 'w').write(s[:m.start()] + hdr + nb2 + s[end:])
            done = True
            break
        print('%-32s %s: %d local decls -> float, %d casts removed' % (name, os.path.basename(p), nl, nb))
        if apply_: open(p, 'w').write(s[:m.end()] + nb2 + s[end:])
        done = True
        break
    if not done: print('NOT FOUND', name)
