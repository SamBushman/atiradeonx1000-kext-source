#!/bin/sh
# Tools/issue153_probe/build.sh - issue #153 follow-up, generic OSDictionary::setObject isolation
# probe. Entirely self-contained: builds its own OSDictionary, touches no real accelerator/surface
# object, no hardware access. Same safety pattern as Tools/issue147_probe.
#
# Run ON the Tiger G5 from the repo root:
#   sh Tools/issue153_probe/build.sh
#   sudo kextload ~/rung3/issue153probe/Issue153Probe.kext   # see tail -f /var/log/system.log
#   sudo kextunload -b com.sambushman.Issue153Probe
set -e
OUT=${OUT:-$HOME/rung3/issue153probe}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
COMMON="-arch ppc -static -fno-common -mlongcall -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/Issue153Probe.cpp" -o "$OUT/Issue153Probe.o"
gcc $COMMON -c "$SRC/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/Issue153Probe" "$OUT/kmod_info.o" "$OUT/Issue153Probe.o" -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

mkdir -p "$OUT/Issue153Probe.kext/Contents/MacOS"
cp "$SRC/Info.plist" "$OUT/Issue153Probe.kext/Contents/Info.plist"
cp "$OUT/Issue153Probe" "$OUT/Issue153Probe.kext/Contents/MacOS/Issue153Probe"
sudo chown -R root:wheel "$OUT/Issue153Probe.kext"
sudo chmod -R go-w "$OUT/Issue153Probe.kext"
echo "bundle: $OUT/Issue153Probe.kext"
