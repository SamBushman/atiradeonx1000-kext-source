#!/usr/bin/env python3
"""tmpoperands.py DIR OUTROWS FN...

Stack copies of the 7-word EXT_vertex_shader source operand record {kind, index, comp[4], flag(byte)} that extvsEmit* functions build and pass by address to
extvsEncodeSourceOperand (3rd argument) / extvsEncodeSourceSwizzle (3rd argument): the struct start is the stack variable whose address is passed, the
following six slots (4 bytes apart, the last one a byte) are its fields.  Names: tmpOperand<N><Field>, N counting the structs of the function by ascending
stack address.  Only fields that exist as declared variables of the function are named.  Rows (local) are appended to OUTROWS."""
import sys, os, re, subprocess
d, out = sys.argv[1:3]
FIELDS = ['Kind', 'Index', 'Comp0', 'Comp1', 'Comp2', 'Comp3', 'Flag']
ST = re.compile(r'^(?:[a-z]{1,2})?(?:Stack|local)_([0-9a-f]+)$')
H = re.compile(r'^/\* (\S+) @ 0x')
here = os.path.dirname(os.path.abspath(__file__))
for fn in sys.argv[3:]:
    txt = None; cur = None; lines = []
    import glob
    for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
        L = open(pf, errors='replace').read().split('\n')
        for i, l in enumerate(L):
            m = H.match(l)
            if m and m.group(1) == fn:
                j = i + 1
                while j < len(L) and not L[j].startswith('/* '): j += 1
                lines = L[i:j]; break
        if lines: break
    body = '\n'.join(lines)
    # orig.py gives Ghidra names; the current text may already carry renames, so read the placeholders from the pristine text
    orig = subprocess.run([sys.executable, os.path.join(here, 'orig.py'), d, fn], capture_output=True, text=True).stdout
    names = {}
    for m in re.finditer(r'\b((?:[a-z]{1,2})?(?:Stack|local)_([0-9a-f]+))\b', orig): names[int(m.group(2), 16)] = m.group(1)
    starts = set()
    for m in re.finditer(r'extvsEncodeSourceOperand\)\([^,]+,[^,]+,&((?:[a-z]{1,2})?(?:Stack|local)_([0-9a-f]+))', orig): starts.add(int(m.group(2), 16))
    for m in re.finditer(r'extvsEncodeSourceSwizzle\)\([^,]+,[^,]+,&((?:[a-z]{1,2})?(?:Stack|local)_([0-9a-f]+))', orig): starts.add(int(m.group(2), 16))
    rows = []
    # stack offsets are negative-going names: uStack_98 is at sp-0x98, word k of a struct is at (start - 4k) in NAME space (address ascends as the name shrinks)
    for n, s in enumerate(sorted(starts, reverse=True)):
        for k in range(7):
            o = s - 4 * k
            if o in names:
                rows.append('local\t%s\t%s\ttmpOperand%d%s\tINFERRED\tstack copy %d of the 7-word source operand record {kind, index, comp[4], flag} passed by address to extvsEncodeSourceOperand/Swizzle; word %d' % (fn, names[o], n, FIELDS[k], n, k))
    open(out, 'a').write('\n'.join(rows) + ('\n' if rows else ''))
    print(fn, len(starts), 'structs', len(rows), 'rows')
