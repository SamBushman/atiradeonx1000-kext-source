#!/usr/bin/env python3
"""apply_fcmp_atoms.py UNPATCHED_DUMP PATCHED_DUMP CORPUS_FILE ADDR [--write]

Class #23 companion of apply_fcmp_hunks.py for functions whose dumps differ by more than compare lines (swapped then/else bodies, restructured else-if chains, variable
renumbering): works on the SEQUENCE OF COMPARE ATOMS instead of lines.
  1. every compare atom `L op R` (op in < <= > >=; a negated atom `!(L op R)` counts as one) of the unpatched dump, the patched dump and the corpus function body is listed in
     source order; the key of an atom is its SHAPE (identifiers -> V, float constants and FLOAT_ / DOUBLE_ labels -> N, casts dropped, operand order and < / > orientation ignored);
  2. unpatched <-> patched are aligned on the keys (difflib); an unpatched atom is FLIPPED when the aligned patched atom, stripped of its `!`, is the flip of it
     (`L < R` -> `R <= L`, `L <= R` -> `R < L`: the decompiler printed `!(R <= L)` as `L < R`) - these are the sites whose NaN behaviour the unpatched decompiler got wrong;
  3. unpatched <-> corpus are aligned the same way and every flipped atom is rewritten in the corpus as `!(R op' L)` with the corpus's own operands (a corpus atom that is
     already negated is left alone: it was done before). Unaligned atoms are listed for a manual edit (`apply_fcmp_hunks.py --manual`).
Only the compare atom's text changes, never the surrounding statements: the then/else bodies of the corpus keep their order, the new condition is the exact NaN-correct form of
the old one (it differs from the old condition only for an unordered operand)."""
import sys, re, difflib
src = open(__file__.replace('apply_fcmp_atoms.py', 'apply_fcmp_hunks.py')).read().replace("if len(sys.argv) > 1 and sys.argv[1] == '--manual': manual()\nelse: main()\n", "")
ns = {}; exec(compile(src, 'afh', 'exec'), ns)
find_atoms, FLIP, body_of, norm = ns['find_atoms'], ns['FLIP'], ns['body_of'], ns['norm']

BIN = None; MACHO = None
def constval(t):
    t = re.sub(r'^\((?:double|float)\)', '', t)
    m = re.fullmatch(r'(FLOAT|DOUBLE)_([0-9a-fA-F]+)', t)
    if m:
        if MACHO is None: return 'L' + t
        v = MACHO.val(MACHO.d, MACHO.segs, int(m.group(2), 16), 'f' if m.group(1) == 'FLOAT' else 'd')
        return '%.5g' % v if v is not None else 'L' + t
    try: return '%.5g' % float(t)
    except ValueError: return t
def shape(s):
    ts = ns['toks'](s); out = []; k = 0
    while k < len(ts):
        if ts[k] == '(' and k + 2 < len(ts) and ts[k + 1] in ('double', 'float') and ts[k + 2] == ')': k += 3; continue
        t = ts[k]; k += 1
        if ns['isconst'](t): out.append('N' + constval(t))
        elif ns['isid'](t): out.append('V')
        else: out.append(t)
    return ''.join(out)
def key(a):
    _, _, neg, L, op, R = a
    return tuple(sorted((shape(L), shape(R))))

def atoms_of(lines, first=0):
    out = []
    for i, l in enumerate(lines):
        for a in find_atoms(l): out.append((i + first,) + a)   # (line index, start, end, neg, L, op, R)
    return out

def main():
    global MACHO
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    unp, pat, corp, addr = args[:4]; write = '--write' in sys.argv
    for a in sys.argv:
        if a.startswith('--bin='):
            import importlib.util, os
            sp = importlib.util.spec_from_file_location('macho_const', os.path.join(os.path.dirname(os.path.abspath(__file__)), 'macho_const.py'))
            MACHO = importlib.util.module_from_spec(sp); sp.loader.exec_module(MACHO); MACHO.d, MACHO.segs = MACHO.load(a[6:])
    addr = addr.lower().replace('0x', '')
    U = atoms_of(open(unp).read().split('\n')); P = atoms_of(open(pat).read().split('\n'))
    C_lines = open(corp).read().split('\n'); b = body_of(C_lines, addr)
    if b is None: print('%s: function not found' % addr); return
    lo, hi = b; C = atoms_of(C_lines[lo:hi], lo)
    ku = [key(a[1:]) for a in U]; kp = [key(a[1:]) for a in P]; kc = [key(a[1:]) for a in C]
    # unpatched <-> patched
    flipped = set(); odd = []
    for blk in difflib.SequenceMatcher(None, ku, kp, autojunk=False).get_matching_blocks():
        for k in range(blk.size):
            ua = U[blk.a + k]; pa = P[blk.b + k]
            _, _, _, nu, Lu, opu, Ru = ua; _, _, _, np_, Lp, opp, Rp = pa
            same = (nu, shape(Lu), opu, shape(Ru)) == (np_, shape(Lp), opp, shape(Rp))
            flip = (shape(Lp), opp, shape(Rp)) == (shape(Ru), FLIP[opu], shape(Lu))
            if flip: flipped.add(blk.a + k)
            elif not same: odd.append((ua, pa))
    # unpatched <-> corpus
    cmap = {}
    if '--positional' in sys.argv:
        # for functions where variables hold constants: map atom i <-> atom i, require equal counts and the same operator (up to mirroring)
        MIRROR = {'<': '>', '<=': '>=', '>': '<', '>=': '<='}
        if len(U) != len(C): print('%s: --positional needs equal atom counts (unp %d corpus %d)' % (addr, len(U), len(C))); return
        for i, (ua, ca) in enumerate(zip(U, C)):
            if not ca[3] and ua[5] not in (ca[5], MIRROR[ca[5]]): print('%s: positional op mismatch at atom %d: unp %s corpus %s' % (addr, i, ua[5], ca[5])); return
            cmap[i] = i
    else:
      for blk in difflib.SequenceMatcher(None, ku, kc, autojunk=False).get_matching_blocks():
        for k in range(blk.size): cmap[blk.a + k] = blk.b + k
    unmapped = [i for i in flipped if i not in cmap]
    edits = {}; done = 0
    for i in sorted(flipped):
        if i not in cmap: continue
        ca = C[cmap[i]]; ln, st, en, nc, Lc, opc, Rc = ca
        if nc: done += 1; continue
        edits.setdefault(ln, []).append((st, en, '!(%s %s %s)' % (Rc, FLIP[opc], Lc), C_lines[ln].strip(), U[i]))
    napplied = 0
    for ln, es in edits.items():
        line = C_lines[ln]
        for st, en, txt, old, ua in sorted(es, reverse=True):
            line = line[:st] + txt + line[en:]
            napplied += 1
        print('APPLY %s line %d:\n   - %s\n   + %s' % (addr, ln + 1, C_lines[ln].strip(), line.strip()))
        C_lines[ln] = line
    for i in unmapped:
        a = U[i]; print('UNMAPPED %s: dump %s %s %s' % (addr, a[4], a[5], a[6]))
    for ua, pa in odd[:6]: print('ODD %s: unp %s %s %s | pat %s%s %s %s' % (addr, ua[4], ua[5], ua[6], '!' if pa[3] else '', pa[4], pa[5], pa[6]))
    print('SUMMARY %s flipped %d applied %d already %d unmapped %d  (atoms: unp %d pat %d corpus %d)' % (addr, len(flipped), napplied, done, len(unmapped), len(U), len(P), len(C)))
    if write and napplied: open(corp, 'w').write('\n'.join(C_lines))

main()
