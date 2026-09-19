#!/usr/bin/env python3
"""build_corpus.py SLICE_FILE ARCH(ppc|i386) DECOMP_DIR OUT_DIR  - run ghidra2c on a DecompAll dump (code-section ranges taken from the
Mach-O file), compile every part on the Tiger G5 (`gcc -arch ARCH`), print failing functions (they are the to-do list) and write
OUT_DIR/compile_status.txt."""
import sys, os, struct, subprocess, re, shutil, glob
slice_f, arch, dd, out = sys.argv[1:5]
d = open(slice_f, 'rb').read()
be = struct.unpack('>I', d[:4])[0] == 0xfeedface
e = '>' if be else '<'
ncmds = struct.unpack(e + 'I', d[16:20])[0]; p = 28; rng = []
for _ in range(ncmds):
    c, cs = struct.unpack(e + 'II', d[p:p + 8])
    if c == 1:
        ns = struct.unpack(e + 'I', d[p + 48:p + 52])[0]; q = p + 56
        for _ in range(ns):
            name = d[q:q + 16].rstrip(b'\0').decode(); a, sz = struct.unpack(e + '2I', d[q + 32:q + 40]); q += 68
            if name in ('__text', '__picsymbol_stub', '__picsymbolstub1', '__symbol_stub', '__symbol_stub1', '__textcoal_nt', '__StaticInit'):
                rng.append('%x-%x' % (a, a + sz))
    p += cs
first = min(int(r.split('-')[0], 16) for r in rng)
rng = ['0-%x' % first] + rng if first else rng
here = os.path.dirname(os.path.abspath(__file__))
subprocess.run(['python3', here + '/ghidra2c.py', dd, out, '60'] + rng, check=True)
shutil.copy(here + '/ghidra_c.h', out)
name = os.path.basename(out.rstrip('/'))
tmp = '/tmp/bc_%s_%s' % (name, arch)
subprocess.run('rm -rf %s && mkdir -p %s && cp -r %s %s/corpus' % (tmp, tmp, out, tmp), shell=True, check=True)
subprocess.run('tar czf %s.tgz -C %s corpus && scp -q %s.tgz G5:/tmp/bc.tgz' % (tmp, tmp, tmp), shell=True, check=True)
script = 'rm -rf /tmp/bc; mkdir /tmp/bc; cd /tmp/bc && tar xzf /tmp/bc.tgz && cd corpus && for f in part_*.c; do b=${f%%.c}; gcc -arch ' + arch + ' -w -c $f -o $b.o 2> $b.err || echo FAIL $b; done; ls *.o | wc -l'
r = subprocess.run(['ssh', 'G5', script], capture_output=True, text=True)
print(r.stdout.strip())
def collect_undeclared():
    subprocess.run('rm -rf %s_e0; mkdir %s_e0; scp -q G5:/tmp/bc/corpus/part_*.err %s_e0/ 2>/dev/null' % (tmp, tmp, tmp), shell=True)
    names = set()
    for ef in glob.glob(tmp + '_e0/part_*.err'):
        for l in open(ef):
            m = re.search(r"error: '([^']+)' undeclared", l)
            if m and not m.group(1).startswith(('LAB_', 'switchD_')): names.add(m.group(1))
    return names
und = collect_undeclared()
if und:
    with open(os.path.join(out, 'extra_decls.h'), 'w') as f:
        allsrc = ''.join(open(x).read() for x in glob.glob(out + '/part_*.c'))
        for n in sorted(und):
            if re.search(r'\(\s*\*\s*%s\s*\)\s*\(' % re.escape(n), allsrc): f.write('extern int (*%s)();\n' % n)
            elif re.search(r'(?:\*\s*|\b)%s\s*\[' % re.escape(n), allsrc): f.write('extern unsigned char *%s;\n' % n)
            else: f.write('extern unsigned int %s;\n' % n)
    with open(os.path.join(out, 'decls.h'), 'a') as f: f.write('#include "extra_decls.h"\n')
    subprocess.run('rm -rf %s/corpus && cp -r %s %s/corpus && tar czf %s.tgz -C %s corpus && scp -q %s.tgz G5:/tmp/bc.tgz' % (tmp, out, tmp, tmp, tmp, tmp), shell=True, check=True)
    r = subprocess.run(['ssh', 'G5', script], capture_output=True, text=True); print('2nd pass:', r.stdout.strip())
errdir = tmp + '_err'
subprocess.run('rm -rf %s; mkdir %s; scp -q G5:/tmp/bc/corpus/part_*.err %s/ 2>/dev/null' % (errdir, errdir, errdir), shell=True)
fail = {}
for ef in sorted(glob.glob(errdir + '/part_*.err')):
    part = os.path.basename(ef)[:-4]
    src = open('%s/%s.c' % (out, part)).read().split('\n')
    starts = [(i + 1, re.match(r'/\* (\S+) @ (\S+)', l).group(1)) for i, l in enumerate(src) if l.startswith('/* ') and ' @ ' in l]
    for l in open(ef):
        m = re.match(r'^\S+:(\d+): error: (.*)', l)
        if m:
            ln = int(m.group(1)); fn = [n for s_, n in starts if s_ <= ln][-1] if starts else '?'
            fail.setdefault((part, fn), []).append((ln, m.group(2)[:90], src[ln - 1].strip()[:110] if ln <= len(src) else ''))
with open(os.path.join(out, 'compile_status.txt'), 'w') as f:
    f.write('%d failing functions\n' % len(fail))
    for k, v in fail.items(): f.write('%s %s %d %s | %s\n' % (k[0], k[1], len(v), v[0][1], v[0][2]))
print(len(fail), 'failing functions'); 
for k, v in list(fail.items())[:60]: print(k, len(v), v[0][1], '|', v[0][2])
