#!/bin/sh
set -e
OUT=${OUT:-$HOME/rung3/issue155probe}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
COMMON="-arch ppc -static -fno-common -mlongcall -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/Issue155Probe.cpp" -o "$OUT/Issue155Probe.o"
gcc $COMMON -c "$SRC/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/Issue155Probe" "$OUT/kmod_info.o" "$OUT/Issue155Probe.o" -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

mkdir -p "$OUT/Issue155Probe.kext/Contents/MacOS"
cp "$SRC/Info.plist" "$OUT/Issue155Probe.kext/Contents/Info.plist"
cp "$OUT/Issue155Probe" "$OUT/Issue155Probe.kext/Contents/MacOS/Issue155Probe"
sudo chown -R root:wheel "$OUT/Issue155Probe.kext"
sudo chmod -R go-w "$OUT/Issue155Probe.kext"
echo "bundle: $OUT/Issue155Probe.kext"
