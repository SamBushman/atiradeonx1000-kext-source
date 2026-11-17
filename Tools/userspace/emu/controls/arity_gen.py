"""arity_gen.py [CORPUS_DIR] > arity.tsv - integer-register arity of every corpus definition (non-float/double parameters, at most 8) for functions whose body has no in_rN /
in_stack / param_9+ read (so Ghidra's parameter list is complete); use with TD_ARITY_FILE=arity.tsv for ENTRYARGS runs whose ledger rows have no parameter classes."""
import re, sys, glob, os
root = os.path.expanduser(sys.argv[1] if len(sys.argv) > 1 else '~/atiradeonx1000-kext-source/Userspace/GLEngine/ppc')
for f in sorted(glob.glob(root + '/part_*.c')):
    src = open(f).read()
    for m in re.finditer(r'^(?:[A-Za-z_][\w \*]*?[ \*])(_?\w+)\(([^)]*)\)\s*\n((?:[ \t]+[^\n]*;\n)*)\{', src, re.M):
        name = m.group(1); params = [p.strip() for p in m.group(2).split(',') if p.strip() and p.strip() != 'void']
        e = src.find('\n}\n', m.end())
        body = src[m.end():e]
        if re.search(r'\bin_r\d+\b|\bin_stack|\bparam_(?:9|\d\d)\b', body): continue
        decl = m.group(3)
        types = {}
        for dl in decl.split('\n'):
            dm = re.match(r'\s*(.*?)\s*\b(\w+);', dl)
            if dm: types[dm.group(2)] = dm.group(1)
        n = 0
        for p in params:
            t = types.get(p, p)
            if re.search(r'\b(double|float)\b', t) and '*' not in t: continue
            n += 1
        print('%s\t%d' % (name, min(n, 8)))
