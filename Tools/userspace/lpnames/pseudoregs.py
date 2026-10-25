#!/usr/bin/env python3
"""pseudoregs.py DIR OUT.tsv PARTLO PARTHI : whole-function `local` rows for Ghidra's pseudo-register variables.

Ghidra invents these for registers the function reads without writing (stale incoming/outgoing argument registers forwarded by an
indirect call, condition-register fields, the XER summary-overflow bit, the reservation bit of a lwarx/stwcx. loop, the second return
register after a call).  They have no source-level role, so the names only say which register they stand for:
    fparam_N -> staleFprArgN     in_fN -> staleFprN          in_rN -> staleArgRN        in_stack_XXXXXXXX -> staleStackArg_XXXXXXXX
    in_crN -> crFieldN           unaff_crN -> calleeSavedCrFieldN                        in_xer_so -> xerSummaryOverflow
    in_RESERVE -> reservation    extraout_r4[_NN] -> r4AfterCall[NN+2]                   extraout_f1[_NN] -> f1AfterCall[NN+2]
A name already used in the function gets a numeric suffix."""
import sys, re, glob
d, out, lo, hi = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
H = re.compile(r'^/\* (\S+) @ 0x')
TOK = re.compile(r'\b(fparam_\d+|in_f\d+|in_r\d+|in_stack_[0-9a-f]+|in_cr\d|unaff_cr\d|in_xer_so|in_RESERVE|extraout_[rf]\d+(?:_\d+)?)\b')
def newname(t):
    m = re.fullmatch(r'fparam_(\d+)', t)
    if m: return 'staleFprArg' + m.group(1)
    m = re.fullmatch(r'in_f(\d+)', t)
    if m: return 'staleFpr' + m.group(1)
    m = re.fullmatch(r'in_r(\d+)', t)
    if m: return 'staleArgR' + m.group(1)
    m = re.fullmatch(r'in_stack_([0-9a-f]+)', t)
    if m: return 'staleStackArg_' + m.group(1)
    m = re.fullmatch(r'in_cr(\d)', t)
    if m: return 'crField' + m.group(1)
    m = re.fullmatch(r'unaff_cr(\d)', t)
    if m: return 'calleeSavedCrField' + m.group(1)
    if t == 'in_xer_so': return 'xerSummaryOverflow'
    if t == 'in_RESERVE': return 'reservation'
    m = re.fullmatch(r'extraout_([rf])(\d+)(?:_(\d+))?', t)
    if m: return '%s%sAfterCall%s' % (m.group(1), m.group(2), '' if m.group(3) is None else str(int(m.group(3)) + 2))
    return None
rows = []
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    cur = None; buf = []
    def flush():
        if not cur: return
        text = '\n'.join(buf)
        idents = set(re.findall(r'[A-Za-z_]\w*', text))
        seen = []
        for t in TOK.findall(text):
            if t not in seen: seen.append(t)
        for t in seen:
            nm = newname(t)
            if not nm: continue
            n2 = nm; k = 1
            while n2 in idents: k += 1; n2 = nm + str(k)
            idents.add(n2)
            rows.append('local\t%s\t%s\t%s\tINFERRED\tGhidra pseudo-register: %s (a register the function reads without having written it; no source-level role)' % (cur, t, n2, t))
    for l in open(pf, errors='replace').read().split('\n'):
        m = H.match(l)
        if m: flush(); cur = m.group(1); buf = []; continue
        buf.append(l)
    flush()
open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
print(len(rows), 'rows', file=sys.stderr)
