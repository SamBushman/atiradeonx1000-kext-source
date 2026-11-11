#!/usr/bin/env python3
"""apply_fcmp_hunks.py UNPATCHED_DUMP PATCHED_DUMP CORPUS_FILE NAME [--write]

Class #23 (NaN-unsound float compare flip, Tools/userspace/ghidra_patches/): the committed corpora of GLDriver / libGLProgrammability / VADriver were generated from dumps
made by the UNPATCHED decompiler (it prints `!(a < b)` as `b <= a`). A re-dump of the same function with the PATCHED decompiler differs from the unpatched dump in the
compare lines (and in variable numbering). This tool carries the compare-only hunks over to the corpus text, which has since been renamed / edited by hand:
  1. the unpatched dump and the corpus function body are aligned line by line on a NORMALISED form (identifiers -> V, numbers kept);
  2. every hunk (unpatched line -> patched line) whose two sides have the same skeleton once the compare operators, `!` and parentheses are removed (a compare-only change)
     is mapped to the aligned corpus line; the identifiers of the patched line are replaced by the corpus line's identifiers (position-wise through the unpatched line);
  3. the corpus line is rewritten with its own indentation (only with --write; the default prints the before/after of every hunk).
Hunks that are not compare-only (other differences between the two dumps: variable numbering, inlined constants) are listed as SKIP; hunks whose unpatched line has no aligned
corpus line are listed as UNMAPPED and need a manual edit. Exit status 0 always; the summary line gives the counts."""
import re, sys, difflib

KW = set('if else while return goto do for switch case break continue sizeof int uint float double char short long unsigned signed void byte undefined undefined1 undefined2 undefined4 undefined8 ushort ulonglong longlong code bool NULL'.split())
TOK = re.compile(r'(?:\(double\)|\(float\))?(?:FLOAT|DOUBLE)_[0-9a-fA-F]+|[A-Za-z_]\w*|0[xX][0-9a-fA-F]+|\d+\.\d*(?:[eE][-+]?\d+)?|\d+|<=|>=|==|!=|&&|\|\||<<|>>|->|[^\s\w]')

TOKRE = TOK
def toks(s): return TOK.findall(s)
def isconst(t): return re.fullmatch(r'(?:\(double\)|\(float\))?(?:FLOAT|DOUBLE)_[0-9a-fA-F]+|\d+\.\d*(?:[eE][-+]?\d+)?', t) is not None
def isid(t): return re.fullmatch(r'[A-Za-z_]\w*', t) is not None and t not in KW and not isconst(t)

def norm(s):
    out = []
    ts = toks(s)
    for t in ts:
        out.append('V' if isid(t) else ('N' if isconst(t) else t))
    r = ' '.join(out)
    return r.replace('( double )', '').replace('( float )', '').replace('  ', ' ')

def skel(s):
    out = []
    for t in toks(s):
        if t in ('<', '<=', '>', '>=', '!', '(', ')'): continue
        out.append('V' if isid(t) else ('N' if isconst(t) else t))
    return sorted(x for x in out if x not in ('double', 'float'))


CMP = ('<=', '>=', '<', '>')
def strip_parens(t):
    t = t.strip()
    while t.startswith('(') and t.endswith(')'):
        d = 0; ok = True
        for k, ch in enumerate(t):
            d += ch == '('; d -= ch == ')'
            if d == 0 and k < len(t) - 1: ok = False; break
        if not ok: break
        t = t[1:-1].strip()
    return t

def split_top(t, seps):
    """split at depth-0 occurrences of any of seps; returns (parts, connectives)"""
    parts = []; cons = []; d = 0; cur = ''; k = 0
    while k < len(t):
        ch = t[k]
        if ch == '(': d += 1
        elif ch == ')': d -= 1
        hit = None
        if d == 0:
            for sp in seps:
                if t.startswith(sp, k): hit = sp; break
        if hit: parts.append(cur); cons.append(hit); cur = ''; k += len(hit); continue
        cur += ch; k += 1
    parts.append(cur)
    return parts, cons

def parse_atom(a):
    """-> (neg, L, op, R) or None;  a: one conjunct, e.g. `(!(x < 0.0))` / `0.0 <= x`"""
    a = strip_parens(a); neg = False
    while a.startswith('!'):
        neg = not neg; a = strip_parens(a[1:])
    # find the depth-0 compare operator
    d = 0; k = 0; found = None
    while k < len(a):
        ch = a[k]
        if ch == '(': d += 1
        elif ch == ')': d -= 1
        elif d == 0:
            for op in CMP:
                if a.startswith(op, k):
                    # not part of <<, >>, ->, <<=
                    prev = a[k - 1] if k else ''; nxt = a[k + len(op)] if k + len(op) < len(a) else ''
                    if op in ('<', '>') and (nxt in '<>=' or prev in '<>-'): continue
                    if found is not None: return None
                    found = (k, op); k += len(op) - 1; break
        k += 1
    if not found: return None
    k, op = found
    return (neg, a[:k].strip(), op, a[k + len(op):].strip())

def find_atoms(line):
    """every compare atom of a line: (start, end, neg, L, op, R); a negated atom `!(L op R)` spans the `!(` ... `)`"""
    atoms = []; k = 0
    while k < len(line):
        op = None
        for o in CMP:
            if line.startswith(o, k):
                prev = line[k - 1] if k else ''; nxt = line[k + len(o)] if k + len(o) < len(line) else ''
                if o in ('<', '>') and (nxt in '<>=' or prev in '<>-='): continue
                if o in ('<=', '>=') and prev in '<>': continue
                op = o; break
        if not op: k += 1; continue
        # left operand
        d = 0; i = k - 1
        while i >= 0:
            ch = line[i]
            if ch == ')': d += 1
            elif ch == '(':
                if d == 0: break
                d -= 1
            elif d == 0 and (line[max(0, i - 1):i + 1] in ('&&', '||') or ch in ',?:;{}' or (ch == '=' and line[i - 1:i] not in ('<', '>', '=', '!') and line[i + 1:i + 2] != '=')):
                break
            i -= 1
        ls = i + 1
        # right operand
        d = 0; j = k + len(op)
        while j < len(line):
            ch = line[j]
            if ch == '(': d += 1
            elif ch == ')':
                if d == 0: break
                d -= 1
            elif d == 0 and (line[j:j + 2] in ('&&', '||') or ch in ',?:;{}'):
                break
            j += 1
        L = line[ls:k].strip(); R = line[k + len(op):j].strip()
        start, end, neg = ls, j, False
        if i >= 1 and line[i] == '(' and line[i - 1] == '!' and j < len(line) and line[j] == ')':
            start, end, neg = i - 1, j + 1, True
        atoms.append((start, end, neg, L, op, R)); k = j if j > k else k + len(op)
    return atoms

FLIP = {'<': '<=', '<=': '<', '>': '>=', '>=': '>'}
def rewrite(c, u, p):
    """c, u, p: corpus / unpatched / patched lines. returns (newline, note) or (None, why)"""
    ac, au, ap = find_atoms(c), find_atoms(u), find_atoms(p)
    if not (len(ac) == len(au) == len(ap)) or not ac: return None, 'atom count differs c%d u%d p%d' % (len(ac), len(au), len(ap))
    edits = []
    for a_c, a_u, a_p in zip(ac, au, ap):
        _, _, nu, Lu, opu, Ru = a_u; _, _, np_, Lp, opp, Rp = a_p
        if (nu, Lu, opu, Ru) == (np_, Lp, opp, Rp): continue
        if nu: return None, 'unpatched atom negated'
        if (Lp, opp, Rp) in ((Ru, FLIP[opu], Lu), (Lu, opu, Ru)) or (np_ and (Lp, opp, Rp) == (Lu, opu, Ru)):
            st, en, nc, Lc, opc, Rc = a_c
            if nc: return None, 'corpus atom already negated'
            edits.append((st, en, '!(%s %s %s)' % (Rc, FLIP[opc], Lc)))
        else:
            return None, 'patched atom is not the flip of the unpatched one'
    if not edits: return None, 'nothing to change'
    out = c
    for st, en, txt in sorted(edits, reverse=True):
        # an atom that was the whole content of its own parentheses keeps them: only the atom text is replaced
        out = out[:st] + txt + out[en:]
    return out, 'ok'

def body_of(corpus_lines, addr):
    start = None
    for i, l in enumerate(corpus_lines):
        if re.match(r'/\* \S+ @ 0x%s \(' % re.escape(addr), l): start = i; break
    if start is None: return None
    end = len(corpus_lines)
    for j in range(start + 1, len(corpus_lines)):
        if re.match(r'/\* \S+ @ 0x[0-9a-f]+ \(', corpus_lines[j]): end = j; break
    return start + 1, end

def main():
    unp, pat, corp, name = sys.argv[1:5]; write = '--write' in sys.argv
    U = open(unp).read().split('\n'); P = open(pat).read().split('\n'); C = open(corp).read().split('\n')
    addr = re.sub(r'^0x', '', name.split('/')[-1].replace('.txt', '')).lower()
    b = body_of(C, addr)
    if b is None: print('%s: function not found in %s' % (name, corp)); return
    lo, hi = b
    cb = C[lo:hi]
    un = [norm(x) for x in U]; cn = [norm(x) for x in cb]
    sm = difflib.SequenceMatcher(None, un, cn, autojunk=False)
    umap = {}
    for blk in sm.get_matching_blocks():
        for k in range(blk.size): umap[blk.a + k] = blk.b + k
    hunks = []
    sp = difflib.SequenceMatcher(None, U, P, autojunk=False)
    for tag, i1, i2, j1, j2 in sp.get_opcodes():
        if tag != 'replace' or (i2 - i1) != (j2 - j1):
            if tag != 'equal': hunks.append(('NONLINE', i1, i2, j1, j2, None))
            continue
        for k in range(i2 - i1): hunks.append(('LINE', i1 + k, i1 + k + 1, j1 + k, j1 + k + 1, None))
    nap = nun = nsk = 0; edits = {}
    for h in hunks:
        if h[0] == 'NONLINE':
            nsk += 1; print('SKIP-structure  %s unp lines %d-%d' % (name, h[1] + 1, h[2])); continue
        _, i, _, j, _, _ = h
        u, p = U[i], P[j]
        if norm(u) == norm(p): continue            # variable numbering only
        if skel(u) != skel(p):
            nsk += 1; print('SKIP-noncompare %s:\n   unp %s\n   pat %s' % (name, u.strip(), p.strip())); continue
        if i not in umap:
            # fallback: the k-th line of this normalised form in the dump <-> the k-th in the corpus function, when both occur equally often
            nu_ = [x for x in range(len(U)) if un[x] == un[i]]; nc_ = [x for x in range(len(cb)) if cn[x] == un[i]]
            if len(nu_) == len(nc_) and nc_: umap[i] = nc_[nu_.index(i)]
        if i not in umap:
            nun += 1; print('UNMAPPED        %s:\n   unp %s\n   pat %s' % (name, u.strip(), p.strip())); continue
        ci = umap[i]; c = cb[ci]
        newline, why = rewrite(c, u, p)
        if newline is None:
            nun += 1; print('MANUAL(%s) %s:\n   unp  %s\n   pat  %s\n   corp %s' % (why, name, u.strip(), p.strip(), c.strip())); continue
        if newline == c: continue
        nap += 1; edits[lo + ci] = newline
        print('APPLY %s line %d:\n   - %s\n   + %s' % (name, lo + ci + 1, c.strip(), newline.strip()))
    if write and edits:
        for ln, t in edits.items(): C[ln] = t
        open(corp, 'w').write('\n'.join(C))
    print('SUMMARY %s applied %d unmapped %d skipped %d' % (name, nap, nun, nsk))

def manual():
    # apply_fcmp_hunks.py --manual CORPUS_FILE LINENO UNPATCHED_LINE PATCHED_LINE   (LINENO is 1-based; rewrites that line with the same atom rule)
    f, ln, u, p = sys.argv[2], int(sys.argv[3]), sys.argv[4], sys.argv[5]
    C = open(f).read().split('\n'); c = C[ln - 1]
    new, why = rewrite(c, u, p)
    if new is None: print('MANUAL-FAIL %s:%d (%s)\n   corp %s' % (f, ln, why, c.strip())); return
    print('MANUAL-APPLY %s:%d\n   - %s\n   + %s' % (f, ln, c.strip(), new.strip()))
    if '--write' in sys.argv: C[ln - 1] = new; open(f, 'w').write('\n'.join(C))

if len(sys.argv) > 1 and sys.argv[1] == '--manual': manual()
else: main()
