#!/usr/bin/env python3
"""fpr_out_audit.py STOCK_DIS  - stock call sites (`bl ... ; symbol stub for: _X`) whose floating-point argument registers f1..f13 are loaded or computed in the straight-line code just before the call.

The decompile (and the rebuilt C) of an UNPROTOTYPED import shows only the integer arguments, so a float argument (`_glgPixelCenters(count, f1, f2, f3)`, #285) is silently dropped: the rebuilt call
passes whatever the compiler left in f1..f3. A site is listed when one of f1..f13 is written within WINDOW instructions before the `bl` (no branch / label in between) and not read by a store
or compare right after being written (pure address arithmetic does not use FPRs); libm imports with known prototypes are skipped (the decompile passes their float arguments).
Output: one row per site: import, call address, the FPRs written in the window. Group by import: an import listed at EVERY site with the same registers takes float arguments."""
import re, sys, collections
WINDOW = 24
LIBM = set('sin cos tan asin acos atan atan2 sinf cosf tanf sqrt sqrtf pow powf exp expf log logf log2 log10 fabs fabsf floor floorf ceil ceilf fmod fmodf ldexp frexp modf lround rint nearbyint trunc round exp2 log2f ldexpf atanf'.split())
KNOWN = LIBM | {'printf', 'sprintf', 'snprintf', 'fprintf', 'strtod', 'atof', 'frexp'}
rows = []; win = []
FDEST = re.compile(r'^(lfs|lfd|lfsx|lfdx|fmr|fadds?|fsubs?|fmuls?|fdivs?|fmadds?|fmsubs?|fnmadds?|fnmsubs?|frsp|fneg|fabs|fsel|fctiwz?|fctid|fcfid|fsqrts?|fres|frsqrte|lfsu|lfdu)\.?$')
for l in open(sys.argv[1], errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l.rstrip('\n'))
    if not m:
        if l.rstrip().endswith(':') and not l.startswith(('\t', '(')): win = []
        continue
    a, op, args = m.group(1), m.group(2), m.group(3)
    if op in ('bl', 'bla') and 'symbol stub for:' in args:
        sym = args.split('symbol stub for:')[1].strip().lstrip('_')
        if sym not in KNOWN:
            w = set()
            for (wa, wop, wargs) in win:
                if FDEST.match(wop):
                    d = wargs.split(',')[0].strip()
                    mm = re.match(r'f(\d+)$', d)
                    if mm and 1 <= int(mm.group(1)) <= 13: w.add(int(mm.group(1)))
            if w: rows.append((sym, a, sorted(w)))
        win = []
        continue
    if op.startswith('b') or op in ('blr', 'bctr', 'bctrl') or op.startswith('bl'):
        win = []; continue
    win.append((a, op, args)); win = win[-WINDOW:]
by = collections.defaultdict(list)
for sym, a, w in rows: by[sym].append((a, w))
for sym in sorted(by):
    print('%-34s %3d sites, e.g. %s f%s' % (sym, len(by[sym]), by[sym][0][0], ','.join(map(str, by[sym][0][1]))))
