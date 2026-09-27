#!/usr/bin/env python3
"""test_coverage.py KEY - which C functions of a rebuilt image were entered by ANY test (issue #65 criterion 1).
The images are rebuilt with COVERAGE=1 (link_corpus.py: -finstrument-functions + a hook that appends the image offset of every function the first time a process enters it to $COV_FILE);
the whole differential suite runs against them (Tools: work-bugwf/cov_suite.sh: load / export tests, fnfuzz, GLSL 141 + 403, noise, constants, atomic, patch sites, atexit, libGL dispatch ...).
Writes Userspace/<bin>/ppc/test_coverage.tsv: one row per function of the corpus - entered by a test (yes / no), and for the ones no test entered the reason a static look at the stock
code gives (an indirect call through a context / vtable = needs live driver state; atomics / hardware instructions; imports; a fragment of a caller's frame; ...).
  test_coverage.py KEY DIS RANGES.tsv NM_REBUILT COV.bin LINK_TREE UNIVERSE_DIR"""
import sys, re, os, struct, bisect, collections
key, dis, ranges, nmf, covf, link, uni = sys.argv[1:8]
data = open(covf, 'rb').read()
cov = set(struct.unpack('>I', data[i:i + 4])[0] for i in range(0, len(data) - 3, 4))      # the hook wrote native (big-endian) words
asm = {}
for l in open(os.path.join(link, 'decls.h')):
    m = re.match(r'extern (?:[\w \*]+?) (\w+)\(.*?\)(?: asm\("([^"]+)"\))?;', l)
    if m and m.group(2): asm[m.group(1)] = m.group(2)
R = {}
for l in open(nmf):
    p = l.split()
    if len(p) == 3 and p[1] in 'Tt': R.setdefault(p[2], int(p[0], 16))
seq = {}
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l)
    if m: seq[int(m.group(1), 16)] = (m.group(2), m.group(3))
WL = set('memcpy memset bcopy memmove memcmp strlen strcmp strncmp strcpy strncpy strcat strchr strrchr bzero sqrt sqrtf pow powf exp exp2 log log2 log10 sin cos tan atan atan2 asin acos floor ceil fabs fmod modf frexp ldexp abs labs'.split())
def reason(rs):
    why = collections.Counter()
    for lo, hi in rs:
        for a in range(lo, hi, 4):
            if a not in seq: continue
            op, arg = seq[a]
            if op in ('bctrl', 'blrl'): why['indirect call (driver context / vtable / callback)'] += 1
            elif op in ('lwarx', 'stwcx.', 'sync', 'eieio', 'isync', 'dcbz', 'dcbf', 'dcbst', 'icbi'): why['atomic / cache / barrier instruction'] += 1
            elif op == 'sc': why['system call'] += 1
            elif op in ('bl', 'bl+'):
                mm = re.search(r'symbol stub for: (\S+)', arg)
                if mm and mm.group(1).lstrip('_') not in WL: why['calls an import (' + mm.group(1).lstrip('_') + ')'] += 1
    return sorted(why)
fns = []
for l in open(ranges):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3 and f[0].startswith('0x') and f[2] == 'fn': fns.append((int(f[0], 16), f[1], [tuple(int(x, 16) for x in r.split('-')) for r in f[3].split(';') if r]))
out = []; n = collections.Counter(); rc = collections.Counter()
for ent, name, rs in sorted(fns):
    sym = asm.get(name) or ('_' + name if not name.startswith(('FUN_', '_')) else name)
    a = R.get(sym) if sym in R else (R.get('_' + name) or R.get(name))
    size = sum(h - l_ for l_, h in rs)
    if a is None: out.append((ent, name, size, 'not a C function of the rebuilt image', '')); n['asm / toolchain / clipped (not instrumented)'] += 1; continue
    if a in cov: out.append((ent, name, size, 'yes', '')); n['entered by a test'] += 1; continue
    why = reason(rs)
    if re.match(r'^_*(dyld|initialize_?Cplusplus|stub_)', name.lstrip('_')) or name.lstrip('_').startswith(('dyld', 'initialize')): why = ['toolchain crt code (runs under dyld: lazy binding / image initialisation)'] + why
    why_s = '; '.join(why[:3]) or ('tiny (%d bytes) crt / thunk fragment: reached only through a caller no test exercises' % size if size <= 48 else 'no static blocker: a test could reach it (needs arguments / state no test builds)')
    out.append((ent, name, size, 'no', why_s)); n['NOT entered by any test'] += 1
    for w in (why or ['no static blocker']): rc[re.sub(r'\(.*', '(...)', w)] += 1
with open(uni, 'w') as f:
    f.write('# stock entry\tname\tsize\tentered by a test of the differential suite\tif not: static reason\n')
    for e, nm, sz, c, w in out: f.write('0x%x\t%s\t%d\t%s\t%s\n' % (e, nm, sz, c, w))
print(key, dict(n)); print('  reasons of the uncovered (a function may have several):', dict(rc))
