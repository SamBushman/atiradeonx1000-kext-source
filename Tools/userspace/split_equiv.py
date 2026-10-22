#!/usr/bin/env python3
"""split_equiv.py BASE.dis CAND.dis BASE.warn CAND.warn - gate for per-use splits (`use` rows), where gcc -O0 gives the new locals other stack slots.

Passes when, function by function:
  1. the instruction streams are identical once frame displacements `N(r30)` / `N(r1)` are masked (same code, only slot numbers moved);
  2. the slot renumbering is a function from candidate slot to base slot (several candidate slots may map to one base slot: that is a split; a candidate
     slot standing for two base slots would be a merge, which is a bug);
  3. the -O1 -Wuninitialized warnings of the candidate are no more numerous per function than the base's (a use left reading the old variable, after the
     value went into the new one, shows up as 'may be used uninitialized').
Exit 0 = pass. Usage inside verify_names.sh; the .dis files are `otool -arch ppc -tV` output, the .warn files are gcc stderr."""
import re, sys
FR = re.compile(r'([^\s,()]+)\((r30|r1)\)|(?<=,r30,)([^\s,]+)|(?<=,r1,)([^\s,]+)')   # otool prints a displacement equal to a symbol address as that symbol


def funcs(path):
    out = {}; cur = None
    for l in open(path, errors='replace'):
        l = l.rstrip('\n')
        if re.match(r'^[A-Za-z_$][^\s]*:$', l): cur = l; out[cur] = []
        elif cur and re.match(r'^[0-9a-f]{8}\t', l): out[cur].append(l.split('\t', 1)[1])
    return out


def warns(path):
    d = {}
    fn = None
    for l in open(path, errors='replace'):
        m = re.search(r"In function '([^']+)'", l)
        if m: fn = m.group(1)
        if 'uninitialized' in l and 'warning' in l: d[fn] = d.get(fn, 0) + 1
    return d


def main():
    bd, cd, bw, cw = sys.argv[1:5]
    B, C = funcs(bd), funcs(cd); bad = 0
    for name in B:
        if name not in C: print('MISSING', name); bad += 1; continue
        b, c = B[name], C[name]
        if len(b) != len(c): print('LENGTH', name); bad += 1; continue
        m = {}; ok = True
        for x, y in zip(b, c):
            if FR.sub('<F>', x) != FR.sub('<F>', y): print('CODE', name, x, '|', y); ok = False; break
            for fx, fy in zip(FR.finditer(x), FR.finditer(y)):
                kx = fx.group(1) or fx.group(3) or fx.group(4); ky = fy.group(1) or fy.group(3) or fy.group(4)
                if m.setdefault(ky, kx) != kx:
                    print('MERGE', name, 'candidate slot', ky, 'stands for', m[ky], 'and', kx); ok = False
        bad += not ok
    wb_, wc = warns(bw), warns(cw)
    for k, v in wc.items():
        if v > wb_.get(k, 0): print('UNINIT', k, wb_.get(k, 0), '->', v); bad += 1
    print('%d functions compared, %d problems' % (len(B), bad))
    sys.exit(1 if bad else 0)


main()
