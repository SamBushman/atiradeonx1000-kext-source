#!/bin/sh
# quickcheck.sh - fast version of Tools/verify_identical_build.sh for a few source files: compile just those files with the build's flags from the committed tree
# (BASE_REV, default HEAD) and from the working tree, in the SAME directory (the anonymous-namespace hashes embed the path), and compare the objects with those hashes
# masked. Seconds instead of minutes: use it to bisect a `use` row that changes gcc's register allocation, then confirm with verify_identical_build.sh.
# Usage: sh Tools/renames/quickcheck.sh [-b BASE_REV] [-h host] Sources/File.cpp [Sources/File2.cpp ...]       (run from the repository root)
# Exit 0 = every object identical, 1 = some differ (named), 2 = a compile failed.
BASE=HEAD; H=G5
while getopts b:h: o; do case $o in b) BASE=$OPTARG;; h) H=$OPTARG;; esac; done; shift $((OPTIND-1))
[ $# -gt 0 ] || { sed -n 2,9p "$0"; exit 2; }
WORK=${WORK:-rung3/quickcheck}; T=$(mktemp -d); mkdir "$T/base"
git archive "$BASE" Headers Sources | tar -x -C "$T/base"
tar czf "$T/base.tgz" -C "$T/base" Headers Sources
tar czf "$T/cand.tgz" Headers Sources
ssh $H "mkdir -p $WORK" && scp -q "$T/base.tgz" "$T/cand.tgz" $H:$WORK/ || exit 2
FILES="$*"
ssh $H "cd $WORK && rm -rf out && mkdir out && for side in base cand; do rm -rf tree && mkdir tree && cd tree && tar xzf ../\$side.tgz && for f in $FILES; do b=\`basename \$f .cpp\`; g++ ${OPT--Os} -mlongcall -arch ppc -static -fno-common -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I/System/Library/Frameworks/Kernel.framework/Headers -w -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 '-Dstatic_assert(a,b)=' -c \$f -o ../out/\$side.\$b.o 2> ../out/\$side.\$b.err || echo COMPILEFAIL \$side \$f; done; cd ..; done" | grep COMPILEFAIL && { rm -rf "$T"; exit 2; }
rc=0
for f in $FILES; do b=$(basename $f .cpp)
  scp -q $H:$WORK/out/base.$b.o "$T/base.$b.o"; scp -q $H:$WORK/out/cand.$b.o "$T/cand.$b.o"
  if python3 - "$T/base.$b.o" "$T/cand.$b.o" <<'PY'
import re, sys
pat = re.compile(rb'(_GLOBAL__N_[A-Za-z0-9_.]+_00000000_)[0-9A-F]{8}')
m = lambda p: pat.sub(lambda x: x.group(1) + b'XXXXXXXX', open(p, 'rb').read())
sys.exit(0 if m(sys.argv[1]) == m(sys.argv[2]) else 1)
PY
  then echo "identical  $f"; else echo "DIFFERENT  $f"; rc=1; fi
done
rm -rf "$T"; exit $rc
