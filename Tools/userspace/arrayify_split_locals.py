#!/usr/bin/env python3
"""arrayify_split_locals.py DIR [--apply] - find GLDriver corpus locals declared as separate scalars NAME0..NAMEn-1 (same type) of which `&NAME0` is taken: the stock
frame holds them as one contiguous array (the callee reads/writes NAME[1..n-1] through the pointer), but separate C locals may be laid out in any order by the
compiler. With --apply each group becomes `TYPE NAME[n];` and every NAMEk becomes NAME[k]. Groups whose bare NAME is already an identifier in the function are skipped (reported)."""
import re, sys, glob, os
d = sys.argv[1]; apply = '--apply' in sys.argv
tot = 0
for f in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    t = open(f).read()
    parts = re.split(r'(?m)^(?=/\* [A-Za-z_0-9]+ @ 0x)', t)
    out = []; changed = False
    for fn in parts:
        for m in sorted(set(re.findall(r'&(\w+?)0\b', fn))):
            base = m
            decls = {}
            for k in range(0, 8):
                mm = re.search(r'(?m)^[ \t]+([A-Za-z_][\w ]*?[ \*]+)%s%d;[ \t]*\n' % (re.escape(base), k), fn)
                if not mm: break
                decls[k] = mm
            n = len(decls)
            if n < 2: continue
            types = set(x.group(1).strip() for x in decls.values())
            INTS = {'int', 'uint', 'undefined4'}
            if len(types) != 1 and not types <= INTS: print('SKIP(type mix)', f, base, types); continue
            if re.search(r'\b%s\b(?!\d)' % re.escape(base), fn): print('SKIP(name used)', f, base); continue
            hdr = fn.split('\n', 1)[0]
            ty0 = decls[0].group(1)
            print('%s %s: %s %s[%d]%s' % (os.path.basename(f), hdr[3:40], ty0.strip(), base, n, ' (mixed %s)' % sorted(types) if len(types) > 1 else '')); tot += 1
            if apply:
                ty = ty0
                for k in range(n):
                    fn = fn.replace(decls[k].group(0), '__KEEP0__' if k == 0 else '', 1)
                fn = fn.replace('__KEEP0__', '  %s%s[%d];\n' % (ty, base, n))
                fn = re.sub(r'\b%s([0-%d])\b' % (re.escape(base), n - 1), lambda x: '%s[%s]' % (base, x.group(1)), fn)
                changed = True
        out.append(fn)
    if apply and changed: open(f, 'w').write(''.join(out))
print('groups', tot)
