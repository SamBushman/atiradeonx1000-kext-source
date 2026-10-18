#!/bin/sh
# quick_verify.sh - fast gate for rename tables: compile ONLY the Sources/*.cpp that differ from a base revision, once as in the working tree and once as in
# the base revision (base Headers too), at the same path with build_kext.sh's flags, and compare the object files (gcc's per-compile anonymous-namespace
# hash masked, as in Tools/verify_identical_build.sh). Seconds per file instead of a whole-kext build; the whole-kext check stays the final word.
#   sh Tools/renames/quick_verify.sh [ssh-host] [BASE_REV]          (default G5, HEAD; run from the repository root)  env: WORK=rung3/quick_verify OPT=-Os
# Exit 0 = every changed file compiles to the same object, 1 = a file differs (named), 2 = a compile failed or a changed file is new.
H=${1:-G5}; BASE=${2:-HEAD}; WORK=${WORK:-rung3/quick_verify}
FILES=$(git diff --name-only "$BASE" -- Sources | grep '\.cpp$')
[ -n "$FILES" ] || { echo "no changed Sources/*.cpp"; exit 0; }
for f in $FILES; do git cat-file -e "$BASE:$f" 2>/dev/null || { echo "$f is new (not in $BASE): compare by hand"; exit 2; }; done
T=$(mktemp -d)
tar czf "$T/cand.tgz" --exclude=Tools/userspace --exclude=__pycache__ Headers Sources Tools Resources
git archive "$BASE" Headers $FILES | gzip > "$T/base.tgz"
ssh "$H" "mkdir -p $WORK" && scp -q "$T/cand.tgz" "$T/base.tgz" "$H:$WORK/" || { rm -rf "$T"; exit 2; }
echo "$FILES" | ssh "$H" "cat > $WORK/files.txt"
ssh "$H" "cd $WORK && rm -rf tree objc objb && mkdir tree objc objb && cd tree && tar xzf ../cand.tgz && OPT='${OPT--Os}'
KFW=/System/Library/Frameworks/Kernel.framework/Headers
COMMON=\"\$OPT -mlongcall -arch ppc -static -fno-common -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I\$KFW -w\"
CXXFLAGS=\"\$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)=\"
fail=0
for f in \$(cat ../files.txt); do b=\$(basename \$f .cpp); g++ \$CXXFLAGS -c \$f -o ../objc/\$b.o 2>../objc/\$b.err || { echo COMPILE-FAIL cand \$f; fail=1; }; done
rm -rf Headers && tar xzf ../base.tgz
for f in \$(cat ../files.txt); do b=\$(basename \$f .cpp); g++ \$CXXFLAGS -c \$f -o ../objb/\$b.o 2>../objb/\$b.err || { echo COMPILE-FAIL base \$f; fail=1; }; done
exit \$fail" || { echo "a compile failed"; rm -rf "$T"; exit 2; }
mkdir -p "$T/c" "$T/b"; scp -q "$H:$WORK/objc/*.o" "$T/c/"; scp -q "$H:$WORK/objb/*.o" "$T/b/"
python3 - "$T" <<'PY'
import os, re, sys
t = sys.argv[1]
pat = re.compile(rb'(_GLOBAL__N_[A-Za-z0-9_.]+_00000000_)[0-9A-F]{8}')
mask = lambda b: pat.sub(lambda m: m.group(1) + b'XXXXXXXX', b)
bad = [n for n in sorted(os.listdir(t + '/c')) if mask(open(t + '/c/' + n, 'rb').read()) != mask(open(t + '/b/' + n, 'rb').read())]
if bad: print('DIFFERENT objects:', ' '.join(bad)); sys.exit(1)
print('IDENTICAL: %d object files compile to the same bytes as in the base revision' % len(os.listdir(t + '/c')))
PY
rc=$?; rm -rf "$T"; exit $rc
