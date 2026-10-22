#!/usr/bin/env python3
"""split_equiv.py BASE.dis BASE.raw CAND.dis CAND.raw BASE.warn CAND.warn - gate for per-use splits (`use` rows), where gcc -O0 gives the new locals other stack slots.

Passes when, function by function:
  1. the instruction words are identical once the displacement of every D-form instruction based on r1/r30 is masked (same code, only slot numbers moved);
  2. the slot renumbering is a function from candidate slot to base slot (several candidate slots may map to one base slot: that is a split; a candidate
     slot standing for two base slots would be a merge, which is a bug);
  3. the -O1 -Wuninitialized warnings of the candidate are no more numerous per function than the base's (a use left reading the old variable, after the
     value went into the new one, shows up as 'may be used uninitialized').
Exit 0 = pass. Usage inside verify_names.sh; the .dis files are `otool -arch ppc -tV` output, the .raw files `otool -arch ppc -t`, the .warn files are gcc stderr."""
import re, sys

DFORM = set([14, 15] + list(range(32, 56)))      # addi/addis and the D-form loads/stores: the immediate is a frame displacement when rA is r1/r30


def funcs(dis, raw):
    """{function label: [instruction word, ...]} from `otool -tV` (labels, addresses) and `otool -t` (raw words)."""
    words = {}
    for l in open(raw, errors='replace'):
        m = re.match(r'^([0-9a-f]{8})[ \t](.*)$', l.rstrip('\n'))
        if m:
            a = int(m.group(1), 16)
            for k, w in enumerate(m.group(2).split()): words[a + 4 * k] = int(w, 16)
    out = {}; cur = None
    for l in open(dis, errors='replace'):
        l = l.rstrip('\n')
        if re.match(r'^[A-Za-z_$][^\s]*:$', l): cur = l; out[cur] = []
        else:
            m = re.match(r'^([0-9a-f]{8})\t', l)
            if cur and m: out[cur].append(words[int(m.group(1), 16)])
    return out


def frame(w):
    """-> (masked word, displacement or None): displacement of a D-form instruction whose rA is r1 or r30."""
    op = w >> 26; ra = (w >> 16) & 31
    if op in DFORM and ra in (1, 30) and not (op in (14, 15) and ra == 0):
        return w & ~0xffff, w & 0xffff
    return w, None


def warns(path):
    d = {}
    fn = None
    for l in open(path, errors='replace'):
        m = re.search(r"In function '([^']+)'", l)
        if m: fn = m.group(1)
        if 'uninitialized' in l and 'warning' in l: d[fn] = d.get(fn, 0) + 1
    return d


def main():
    bd, br, cd, cr, bw, cw = sys.argv[1:7]
    B, C = funcs(bd, br), funcs(cd, cr); bad = 0
    for name in B:
        if name not in C: print('MISSING', name); bad += 1; continue
        b, c = B[name], C[name]
        if len(b) != len(c): print('LENGTH', name); bad += 1; continue
        m = {}; ok = True
        for k, (x, y) in enumerate(zip(b, c)):
            mx, dx = frame(x); my, dy = frame(y)
            if mx != my: print('CODE', name, 'instruction', k, '%08x | %08x' % (x, y)); ok = False; break
            if dx is not None and m.setdefault(dy, dx) != dx:
                print('MERGE', name, 'candidate slot 0x%x stands for 0x%x and 0x%x' % (dy, m[dy], dx)); ok = False
        bad += not ok
    wb_, wc = warns(bw), warns(cw)
    for k, v in wc.items():
        if v > wb_.get(k, 0): print('UNINIT', k, wb_.get(k, 0), '->', v); bad += 1
    print('%d functions compared, %d problems' % (len(B), bad))
    sys.exit(1 if bad else 0)


main()
