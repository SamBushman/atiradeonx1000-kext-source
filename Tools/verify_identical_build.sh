#!/bin/sh
# verify_identical_build.sh - prove a source change (a rename, a comment edit) did not change the compiled kext.
#
# Builds the kext from a baseline tree and from the working tree on a Tiger PPC machine with the same flags and compares the two kext binaries
# byte for byte, plus their disassembly (otool -arch ppc -tV) so a difference can be located.
#
# Usage: sh Tools/verify_identical_build.sh [ssh-host] [BASE_REV]
#   ssh-host  the Tiger machine (default G5)
#   BASE_REV  git revision of the baseline (default HEAD, i.e. the last commit); the working tree is the candidate
# Env: OPT (default -Os, as build_kext.sh; OPT= for the unoptimised build), WORK (build directory on the Tiger machine, default ~/rung3/ident_check),
#      EVIDENCE (local directory for the dumps, default ~/g5logs/ident_check)
# Exit 0 = identical, 1 = differ (first differing disassembly lines printed), 2 = a build failed.
H=${1:-G5}; BASE=${2:-HEAD}
WORK=${WORK:-rung3/ident_check}; EV=${EVIDENCE:-$HOME/g5logs/ident_check}
mkdir -p "$EV"; T=$(mktemp -d)
mkdir "$T/base"; git archive "$BASE" Headers Sources Tools Resources | tar -x -C "$T/base"
tar czf "$T/cand.tgz" Headers Sources Tools Resources
tar czf "$T/base.tgz" -C "$T/base" Headers Sources Tools Resources
ssh $H "mkdir -p $WORK" && scp -q "$T/cand.tgz" "$T/base.tgz" $H:$WORK/ || exit 2
BASE_SHA=$(git rev-parse "$BASE")
sides='base cand'
# the baseline build is reused when the evidence directory already holds a build of the same revision with the same flags
if [ -f "$EV/base.key" ] && [ "$(cat "$EV/base.key")" = "$BASE_SHA ${OPT--Os}" ] && [ -f "$EV/base.bin" ]; then sides='cand'; echo "reusing the baseline build of $BASE_SHA"; fi
for side in $sides; do
  # both sides build in the SAME directory: anonymous-namespace symbols embed a hash of the source path
  ssh $H "cd $WORK && rm -rf tree && mkdir tree && cd tree && tar xzf ../$side.tgz && OPT='${OPT--Os}' OUT=\$HOME/$WORK/tree/out KEXT_ID=com.example.ATIRadeonX1000.identcheck sh Tools/build_kext.sh > ../$side.log 2>&1; echo \$? > ../$side.rc"
  [ "$(ssh $H "cat $WORK/$side.rc")" = 0 ] || { echo "build of $side failed:"; ssh $H "tail -20 $WORK/$side.log"; rm -rf "$T"; exit 2; }
  scp -q $H:$WORK/tree/out/ATIRadeonX1000 "$EV/$side.bin"
  ssh $H "otool -arch ppc -tV $WORK/tree/out/ATIRadeonX1000" > "$EV/$side.dis"
done
rm -rf "$T"
echo "$BASE_SHA ${OPT--Os}" > "$EV/base.key"
# gcc 4.0.1 puts a per-compile hash into anonymous-namespace symbol names (_GLOBAL__N_<file>_00000000_<8 hex>): it differs between two builds of the SAME
# tree, so it is masked in both binaries (and the disassembly) before comparing. Nothing else is masked.
python3 - "$EV" <<'PY'
import re, sys
ev = sys.argv[1]
pat = re.compile(rb'(_GLOBAL__N_[A-Za-z0-9_.]+_00000000_)[0-9A-F]{8}')
mask = lambda b: pat.sub(lambda m: m.group(1) + b'XXXXXXXX', b)
for side in ('base', 'cand'):
    for ext in ('bin', 'dis'):
        open('%s/%s.masked.%s' % (ev, side, ext), 'wb').write(mask(open('%s/%s.%s' % (ev, side, ext), 'rb').read()))
PY
if cmp -s "$EV/base.masked.bin" "$EV/cand.masked.bin"; then
  echo "IDENTICAL: kext binaries match byte for byte apart from gcc's per-build anonymous-namespace hashes ($(wc -c < "$EV/cand.bin") bytes, masked md5 $(md5sum < "$EV/cand.masked.bin" | cut -d' ' -f1))"; exit 0
fi
echo "DIFFERENT: binaries differ"
if cmp -s "$EV/base.masked.dis" "$EV/cand.masked.dis"; then echo "(disassembly identical: only data or symbol sections differ)"; else diff "$EV/base.masked.dis" "$EV/cand.masked.dis" | head -30; fi
exit 1
