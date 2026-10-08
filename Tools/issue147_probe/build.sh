#!/bin/sh
# Tools/issue147_probe/build.sh - issue #147, user-authorized read-only probe of the live stock
# ATIRadeonX1000 instance (same safety pattern as Tools/ga_probe/GAProbe.cpp).
#
# Run ON the Tiger G5 from the repo root:
#   sh Tools/issue147_probe/build.sh
#   sudo kextload ~/rung3/issue147probe/Issue147Probe.kext   # see tail -f /var/log/system.log
#   sudo kextunload -b com.sambushman.Issue147Probe
set -e
OUT=${OUT:-$HOME/rung3/issue147probe}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
COMMON="-arch ppc -static -fno-common -mlongcall -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/Issue147Probe.cpp" -o "$OUT/Issue147Probe.o"
gcc $COMMON -c "$SRC/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/Issue147Probe" "$OUT/kmod_info.o" "$OUT/Issue147Probe.o" -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

mkdir -p "$OUT/Issue147Probe.kext/Contents/MacOS"
cp "$SRC/Info.plist" "$OUT/Issue147Probe.kext/Contents/Info.plist"
cp "$OUT/Issue147Probe" "$OUT/Issue147Probe.kext/Contents/MacOS/Issue147Probe"
sudo chown -R root:wheel "$OUT/Issue147Probe.kext"
sudo chmod -R go-w "$OUT/Issue147Probe.kext"
echo "bundle: $OUT/Issue147Probe.kext"
