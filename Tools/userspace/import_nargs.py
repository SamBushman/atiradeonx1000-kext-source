#!/usr/bin/env python3
"""import_nargs.py CORPUS_DIR [OUT.tsv] - how many arguments the corpus passes to every library import, for the import-interposer mode of Tests/userspace/fnfuzz.c
(FNFUZZ_INTERPOSE=1, FNFUZZ_IMPORT_NARGS=OUT.tsv): the stubs hash only those argument registers. A call site's argument list is the Ghidra decompile's (parameters the callee
never reads are not passed there), so the counts of all call sites of one import are listed and the LARGEST one is written (the decompile under-reports an argument
of an unprototyped import more often than it invents one: `_PPEmulatorProgramFree()` at 3 sites, `(x)` at the 4th); imports whose call sites disagree are printed on stderr."""
import re, sys, glob, collections
d = sys.argv[1]; out = sys.argv[2] if len(sys.argv) > 2 else None
cnt = collections.defaultdict(collections.Counter)
names = set()
for f in glob.glob(d + '/decls.h'):
    for m in re.finditer(r'extern\s+[\w\s\*]+?\b_?((?:Sh|PP|glg|glp|NS|CF|IO|host_|mach_|sysctl|scandir|pthread_mutex_)\w*)\s*\(', open(f, errors='replace').read()): names.add(m.group(1))
def split_args(s):
    depth = 0; n = 0; cur = ''
    for ch in s:
        if ch in '([{': depth += 1
        elif ch in ')]}': depth -= 1
        if ch == ',' and depth == 0: n += 1; cur = ''
        else: cur += ch
    return n + 1 if s.strip() else 0
for f in sorted(glob.glob(d + '/part_*.c') + glob.glob(d + '/hand/*.c')):
    t = open(f, errors='replace').read()
    for nm in names:
        for m in re.finditer(r'(?<![\w])_?' + re.escape(nm) + r'\s*\(', t):
            i = m.end(); depth = 1; j = i
            while j < len(t) and depth:
                if t[j] == '(': depth += 1
                elif t[j] == ')': depth -= 1
                j += 1
            cnt[nm][split_args(t[i:j - 1])] += 1
# OVERRIDES: <corpus dir>/nargs_override.tsv (name<TAB>count<TAB>reason) - an import whose real arity is known from the stock call sites (the registers set before the `bl`), where the decompile passes
# dead-register residue as arguments (Darwin PPC: a float argument shadows GPR slots the caller never sets). GLDriver: glgConvertType 4 (r3..r6), glgPixelCenters 1 (r3, floats in f1..), glgProcessPixels 2 (r3, r4).
import os
over = {}
ofile = os.path.join(d, 'nargs_override.tsv')
if os.path.exists(ofile):
    for l in open(ofile):
        p = l.rstrip('\n').split('\t')
        if len(p) >= 2 and not l.startswith('#'): over[p[0]] = int(p[1])
rows = []
for nm in sorted(cnt):
    c = cnt[nm]; best = over.get(nm, max(c)); rows.append((nm, best))
    if len(c) > 1: print('%s: %s' % (nm, dict(c)), file=sys.stderr)
if out:
    with open(out, 'w') as o:
        for nm, n in rows: o.write('%s\t%d\n' % (nm, n))
print('%d imports with call sites' % len(rows), file=sys.stderr)
