#!/bin/sh
# Tools/issue154_probe/build.sh - issue #154, user-authorized read-only probe of the live rebuilt
# ATIRadeonX1000 instance (same safety pattern as Tools/issue147_probe/Issue147Probe.cpp).
#
# Run ON the Tiger G5 from the repo root:
#   sh Tools/issue154_probe/build.sh
#   sudo kextload ~/rung3/issue154probe/Issue154Probe.kext   # see tail -f /var/log/system.log
#   sudo kextunload -b com.sambushman.Issue154Probe
set -e
OUT=${OUT:-$HOME/rung3/issue154probe}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
COMMON="-arch ppc -static -fno-common -mlongcall -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/Issue154Probe.cpp" -o "$OUT/Issue154Probe.o"
gcc $COMMON -c "$SRC/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/Issue154Probe" "$OUT/kmod_info.o" "$OUT/Issue154Probe.o" -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

mkdir -p "$OUT/Issue154Probe.kext/Contents/MacOS"
cp "$SRC/Info.plist" "$OUT/Issue154Probe.kext/Contents/Info.plist"
cp "$OUT/Issue154Probe" "$OUT/Issue154Probe.kext/Contents/MacOS/Issue154Probe"
sudo chown -R root:wheel "$OUT/Issue154Probe.kext"
sudo chmod -R go-w "$OUT/Issue154Probe.kext"
echo "bundle: $OUT/Issue154Probe.kext"
