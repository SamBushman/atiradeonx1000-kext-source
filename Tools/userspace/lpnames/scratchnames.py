#!/usr/bin/env python3
"""scratchnames.py DIR OUT.tsv FN [FN ...] : whole-function `local` rows that give every remaining Ghidra local of the named giant functions an
honest label: `scratch<Kind><N>`.

For the giant functions (thousands of placeholder uses, ~100 locals) almost every local is a register-allocation artifact that Ghidra kept as ONE
variable although it holds many unrelated temporaries (lw2.py: 16 webs for one iVar).  Such a variable has no single role, so it gets the one accurate
name there is: a scratch variable of that C type, numbered like the Ghidra original so the mapping stays stable.  Kind comes from Ghidra's prefix:
iVar int, uVar uint, sVar short, bVar flag/byte, cVar char, fVar float, dVar double, p..Var pointer, local_XXX / *Stack_XXX stack slot.
Parameters are not touched (they have callers to name them).  Variables that were given a real name earlier are not placeholders any more and are
skipped.  Every such function must be listed in notes_unsplittable_q01.md."""
import sys, re, glob
d, out = sys.argv[1], sys.argv[2]
fns = set(sys.argv[3:])
H = re.compile(r'^/\* (\S+) @ 0x')
PAT = re.compile(r'\b(pp?p?[a-z]?Var\d+|[iusbcfdl]Var\d+|local_[0-9a-f]+|[a-z]+Stack_[0-9a-f]+|[a-z]Stack[0-9a-f]{8})\b')
KIND = [('iVar', 'Int'), ('uVar', 'Uint'), ('sVar', 'Short'), ('bVar', 'Flag'), ('cVar', 'Char'), ('fVar', 'Float'), ('dVar', 'Double'), ('lVar', 'Long')]
def newname(t):
    m = re.fullmatch(r'(p+)([a-z]?)Var(\d+)', t)
    if m: return 'scratchPtr' + m.group(3)
    m = re.fullmatch(r'([a-z])Var(\d+)', t)
    if m:
        for k, v in KIND:
            if t.startswith(k[0] + 'Var'): return 'scratch%s%s' % (v, m.group(2))
    m = re.fullmatch(r'local_([0-9a-f]+)', t)
    if m: return 'scratchStack' + m.group(1)
    m = re.fullmatch(r'([a-z]+)Stack_([0-9a-f]+)', t)
    if m: return 'scratchStack%s%s' % ('Arr' if m.group(1) in ('au', 'ai', 'apc', 'aus') else '', m.group(2))
    m = re.fullmatch(r'[a-z]Stack([0-9a-f]{8})', t)
    if m: return 'scratchIncoming' + m.group(1)
    return None
rows = []
for pf in sorted(glob.glob(d + '/part_*.c')):
    cur = None; buf = []
    def flush():
        if not cur or cur not in fns: return
        text = '\n'.join(buf)
        idents = set(re.findall(r'[A-Za-z_]\w*', text))
        params = set()
        seen = []
        for t in PAT.findall(text):
            if t not in seen: seen.append(t)
        for t in seen:
            nm = newname(t)
            if not nm: continue
            n2 = nm; k = 1
            while n2 in idents: k += 1; n2 = nm + '_' + str(k)
            idents.add(n2)
            rows.append('local\t%s\t%s\t%s\tINFERRED\tregister-allocation scratch: Ghidra kept several unrelated temporaries in one variable, so it has no single role (see notes_unsplittable_q01.md)' % (cur, t, n2))
    for l in open(pf, errors='replace').read().split('\n'):
        m = H.match(l)
        if m: flush(); cur = m.group(1); buf = []; continue
        buf.append(l)
    flush()
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(len(rows), 'rows', file=sys.stderr)
