#!/bin/sh
# verify_object.sh - quick form of verify_identical_build.sh for a few source files: compile ONLY the named files from a baseline revision and from the working tree
# on the Tiger machine (same flags as Tools/build_kext.sh, same directory) and compare the object files byte for byte (gcc's per-compile anonymous-namespace hash masked).
# A rename or a variable split must leave every object identical. Seconds instead of the ~6 minutes of a whole-kext build; run the whole-kext check before committing.
#
# Usage: sh Tools/verify_object.sh [-H ssh-host] [-b BASE_REV] Sources/File.cpp [Sources/File2.cpp ...]       (from the repository root; default host G5, base HEAD)
# Env: OPT (default -Os), WORK (build directory on the Tiger machine, default rung3/verify_object), EVIDENCE (local dump directory, default ~/g5logs/verify_object)
# Exit 0 = all objects identical, 1 = some differ (first differing disassembly lines printed), 2 = a compile failed.
H=G5; BASE=HEAD
while [ $# -gt 0 ]; do case "$1" in -H) H=$2; shift 2;; -b) BASE=$2; shift 2;; *) break;; esac; done
[ $# -gt 0 ] || { echo "usage: $0 [-H host] [-b base] Sources/File.cpp ..."; exit 2; }
WORK=${WORK:-rung3/verify_object}; EV=${EVIDENCE:-$HOME/g5logs/verify_object}; OPT=${OPT--Os}
mkdir -p "$EV"; T=$(mktemp -d); mkdir "$T/base"
git archive "$BASE" Headers Sources Resources | tar -x -C "$T/base"
tar czf "$T/cand.tgz" Headers Sources Resources; tar czf "$T/base.tgz" -C "$T/base" Headers Sources Resources
ssh $H "mkdir -p $WORK" && scp -q "$T/cand.tgz" "$T/base.tgz" $H:$WORK/ || exit 2
FILES="$*"
for side in base cand; do
  ssh $H "cd $WORK && rm -rf tree && mkdir tree && cd tree && tar xzf ../$side.tgz && mkdir -p ../o_$side && \
    KFW=/System/Library/Frameworks/Kernel.framework/Headers; rc=0; \
    for f in $FILES; do b=\`basename \$f .cpp\`; \
      g++ $OPT -mlongcall -arch ppc -static -fno-common -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I\$KFW -w -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 '-Dstatic_assert(a,b)=' -c \$f -o ../o_$side/\$b.o 2>../o_$side/\$b.err || { echo FAIL \$f; head -5 ../o_$side/\$b.err; rc=1; }; \
      otool -arch ppc -tV ../o_$side/\$b.o > ../o_$side/\$b.dis; done; exit \$rc" || { rm -rf "$T"; exit 2; }
  mkdir -p "$EV/$side"; scp -q "$H:$WORK/o_$side/*.o" "$H:$WORK/o_$side/*.dis" "$EV/$side/"
done
rm -rf "$T"
python3 - "$EV" $FILES <<'PY'
import re, sys, os, subprocess
ev = sys.argv[1]; files = [os.path.basename(f)[:-4] for f in sys.argv[2:]]
pat = re.compile(rb'(_GLOBAL__N_[A-Za-z0-9_.]+_00000000_)[0-9A-F]{8}')
mask = lambda b: pat.sub(lambda m: m.group(1) + b'XXXXXXXX', b)
bad = 0
for b in files:
    x, y = (mask(open('%s/%s/%s.o' % (ev, s, b), 'rb').read()) for s in ('base', 'cand'))
    if x == y: print('IDENTICAL  %s' % b); continue
    bad += 1; print('DIFFERENT  %s' % b)
    dx, dy = (mask(open('%s/%s/%s.dis' % (ev, s, b), 'rb').read()).decode('latin1').split('\n') for s in ('base', 'cand'))
    n = 0
    for i, (p, q) in enumerate(zip(dx, dy)):
        if p != q:
            print('  base: %s\n  cand: %s' % (p, q)); n += 1
            if n >= 6: break
    if len(dx) != len(dy): print('  (%d vs %d disassembly lines)' % (len(dx), len(dy)))
sys.exit(1 if bad else 0)
PY
