#!/bin/sh
# Self-test of Tests/userspace/fnfuzz.c and fnfuzz_par.sh on the dev box: the REAL harness source, built for Linux/PPC (big-endian, 32-bit) and run under qemu-ppc
# against two tiny ELF "images" (selftest_fns.c built plain = "stock" and -DREBUILT = "rebuilt"). Nov 14 (no G5 needed).
#   needs: powerpc-linux-gnu-gcc, powerpc-linux-gnu-nm, qemu-ppc, /usr/powerpc-linux-gnu (libc), python3
# What it proves: (1) FNFUZZ_LAZYSTOCK2=1 gives the same DIFF / UNINF rows as the default, with and without FNFUZZ_RUNINIT, and fewer forks;
# (2) fnfuzz_par.sh's merged output equals one direct run, and a killed chunk makes the merge end in `NO RESULT` (never a RESULT line).
# Not covered: Mach-O loading, the interposer, the wild-branch guard (FNFUZZ_GUARD=0), Darwin ABI details - the build shims only the signal-context fields,
# vm_read_overwrite, image_ranges (ELF program headers) and the Mach headers; nothing in the trial loop is changed.
set -e
HERE=`cd \`dirname $0\` && pwd`; SRC=$HERE/../fnfuzz.c; PAR=$HERE/../fnfuzz_par.sh
W=${1:-/tmp/fnfuzz_qemu_selftest}; mkdir -p $W/par; cd $W
python3 - "$SRC" <<'PY'
import sys
src=open(sys.argv[1]).read()
m={'srr0':'32','lr':'36','r1':'1','ctr':'35','r0':'0','srr1':'33','cr':'38'}
for k,v in m.items(): src=src.replace('uc_mcontext->ss.'+k,'uc_mcontext.uc_regs->gregs['+v+']')
src=src.replace('static void image_ranges(const struct mach_header *mh) {','static void image_ranges_macho(const struct mach_header *mh) {',1)
i=src.index('static void image_ranges_macho'); j=src.index('\n}\n',i)+3
elf='''
static void image_ranges(const struct mach_header *mh) {   /* test build: the image is an ELF shared object */
    const Elf32_Ehdr *eh = (const Elf32_Ehdr *)mh; const Elf32_Phdr *ph = (const Elf32_Phdr *)((const char *)mh + eh->e_phoff);
    for (int i = 0; i < eh->e_phnum && nrng < 16; i++) if (ph[i].p_type == PT_LOAD && ph[i].p_memsz) { rng_lo[nrng] = (unsigned)mh + ph[i].p_vaddr; rng_hi[nrng] = (unsigned)mh + ph[i].p_vaddr + ph[i].p_memsz; nrng++; }
}
'''
open('fnfuzz_linux.c','w').write(src[:j]+elf+src[j:])
PY
powerpc-linux-gnu-gcc -std=gnu99 -O1 -w -I$HERE/shim -include $HERE/shim/fnfuzz_linux_shim.h -D_GNU_SOURCE -o fnfuzz_linux fnfuzz_linux.c -ldl -lm
for v in stock rebuilt; do D=; [ $v = rebuilt ] && D=-DREBUILT; powerpc-linux-gnu-gcc -O0 -fPIC -shared $D -o $v.so $HERE/selftest_fns.c; done
python3 - <<'PY'
import subprocess
def syms(f):
    o=subprocess.check_output(['powerpc-linux-gnu-nm',f]).decode()
    return {l.split()[2]:int(l.split()[0],16) for l in o.splitlines() if len(l.split())==3 and l.split()[1] in 'Tt'}
S=syms('stock.so'); R=syms('rebuilt.so')
names=['t_same','t_diff','t_bothres','t_rebres','t_crash','t_stockres_diff','t_same2','t_diff2']
with open('selftest.tsv','w') as f:
    f.write('#anchor\tanchor_fn\t%x\t%x\n'%(S['anchor_fn'],R['anchor_fn']))
    for i,n in enumerate(names): f.write('%d\t%s\t%x\t%x\t64\tnn\ti\n'%(i,n,S[n],R[n]))
PY
printf '#!/bin/sh\nexec qemu-ppc -L /usr/powerpc-linux-gnu %s/fnfuzz_linux "$@"\n' $W > fz_wrap.sh; chmod +x fz_wrap.sh
printf '#!/bin/sh\nfor a in "$@"; do case "$a" in @4,*) sleep 1; kill -9 $$;; esac; done\nexec qemu-ppc -L /usr/powerpc-linux-gnu %s/fnfuzz_linux "$@"\n' $W > fz_wrap_kill.sh; chmod +x fz_wrap_kill.sh
export FNFUZZ_GUARD=0 FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512
FAIL=0
for MODE in runinit plain; do
  X=; [ $MODE = runinit ] && X=1
  ( [ -n "$X" ] && export FNFUZZ_RUNINIT=1; ./fz_wrap.sh selftest.tsv ./stock.so ./rebuilt.so 100 > def_$MODE.txt 2>&1
    export FNFUZZ_LAZYSTOCK2=1; ./fz_wrap.sh selftest.tsv ./stock.so ./rebuilt.so 100 > lazy_$MODE.txt 2>&1 )
  grep -a '^DIFF\|^UNINF' def_$MODE.txt | cut -c1-120 > r_def; grep -a '^DIFF\|^UNINF' lazy_$MODE.txt | cut -c1-120 > r_lazy
  if cmp -s r_def r_lazy; then echo "PASS lazy==default verdict rows ($MODE): `grep -c . r_def` rows; `grep -a lazystock2 lazy_$MODE.txt | cut -c1-60`"; else echo "FAIL lazy rows differ ($MODE)"; FAIL=1; fi
done
# FNFUZZ_LISTDIFFS=2 (Nov 15): per-trial DT/AT lines; the number of DT lines of a row must equal its "N differ", the AT lines its "M agree", and the verdict rows must not change
( export FNFUZZ_RUNINIT=1; ./fz_wrap.sh selftest.tsv ./stock.so ./rebuilt.so 40 > ld_off.txt 2>&1; export FNFUZZ_LISTDIFFS=2; ./fz_wrap.sh selftest.tsv ./stock.so ./rebuilt.so 40 > ld_on.txt 2>&1 )
grep -a '^DIFF\|^UNINF' ld_off.txt | cut -c1-95 > ld_r0; grep -a '^DIFF\|^UNINF' ld_on.txt | cut -c1-95 > ld_r1
BADLD=`awk '/^DIFF/ { n=$2; for (i=1;i<=NF;i++) { if ($i=="differ,") d[n]=$(i-1); if ($i=="agree)") a[n]=$(i-1) } } /^DT / { dt[$2]++ } /^AT / { at[$2]++ } END { for (n in d) { if (dt[n]+0 != d[n]+0) print "DT", n, dt[n]+0, d[n]; if (at[n]+0 != a[n]+0) print "AT", n, at[n]+0, a[n] } }' ld_on.txt`
if cmp -s ld_r0 ld_r1 && [ -z "$BADLD" ] && grep -aq '^DT ' ld_on.txt && grep -aq '^AT ' ld_on.txt; then echo "PASS LISTDIFFS: per-trial DT/AT counts match the DIFF rows; verdict rows unchanged"; else echo "FAIL LISTDIFFS $BADLD"; FAIL=1; fi
( export FNFUZZ_RUNINIT=1 FNFUZZ_LAZYSTOCK2=1
  ./fz_wrap.sh selftest.tsv ./stock.so ./rebuilt.so 60 > direct.txt 2>&1
  sh $PAR ./fz_wrap.sh selftest.tsv ./stock.so ./rebuilt.so 60 4 2 par/ok > /dev/null 2>&1
  sh $PAR ./fz_wrap_kill.sh selftest.tsv ./stock.so ./rebuilt.so 60 4 2 par/bad > /dev/null 2>&1 )
grep -a '^DIFF\|^UNINF' direct.txt | cut -c1-95 | sort > r_d; grep -a '^DIFF\|^UNINF' par/ok.full | cut -c1-95 | sort > r_m
if cmp -s r_d r_m && [ -f par/ok.merged.done ] && tail -1 par/ok.full | grep -q '^RESULT: '; then echo "PASS chunked+merged == direct run"; else echo "FAIL chunked merge"; FAIL=1; fi
if tail -1 par/bad.full | grep -q '^NO RESULT: ' && [ ! -f par/bad.merged.done ]; then echo "PASS killed chunk -> NO RESULT, no .done"; else echo "FAIL killed-chunk handling"; FAIL=1; fi
exit $FAIL
