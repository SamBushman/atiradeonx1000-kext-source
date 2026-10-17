#!/bin/sh
# build_rebuilt.sh - build the kext from the working tree on a Tiger PPC machine (same flags as the real build) and fetch the binary for difftest.py.
# Usage: sh Tools/difftest/build_rebuilt.sh [ssh-host]     (default G5)   Output: $REBUILT_KEXT or build/difftest/rebuilt.bin
H=${1:-G5}; WORK=${WORK:-rung3/difftest_build}; OUT=${REBUILT_KEXT:-build/difftest/rebuilt.bin}
mkdir -p "$(dirname "$OUT")"; T=$(mktemp -d)
tar czf "$T/src.tgz" Headers Sources Tools Resources
ssh $H "mkdir -p $WORK" && scp -q "$T/src.tgz" $H:$WORK/ || exit 2
ssh $H "cd $WORK && rm -rf tree && mkdir tree && cd tree && tar xzf ../src.tgz && OPT='${OPT--Os}' WARN='${WARN--w}' OUT=\$HOME/$WORK/tree/out KEXT_ID=com.example.ATIRadeonX1000.difftest sh Tools/build_kext.sh > ../build.log 2>&1; echo \$? > ../build.rc"
[ "$(ssh $H "cat $WORK/build.rc")" = 0 ] || { echo "build failed:"; ssh $H "tail -20 $WORK/build.log"; rm -rf "$T"; exit 2; }
scp -q $H:$WORK/build.log "${OUT%.bin}.log"; scp -q $H:$WORK/tree/out/ATIRadeonX1000 "$OUT" && echo "rebuilt kext: $OUT ($(wc -c < "$OUT") bytes)"
ssh $H "otool -arch ppc -tV \$HOME/$WORK/tree/out/ATIRadeonX1000" > "${OUT%.bin}.dis" && echo "disassembly: ${OUT%.bin}.dis"
rm -rf "$T"
