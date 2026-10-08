#!/bin/sh
# Tools/issue153_ctxprobe/build.sh - issue #153 follow-up, tests whether being inside a real
# IOServiceOpen->newUserClient call chain (thread/lock/preemption context) alone triggers the
# OSDictionary::setObject crash, using a throwaway software-only IOService attached under
# IOResources - no hardware, no relation to ATIRadeonX1000.
#
# Run ON the Tiger G5 from the repo root:
#   sh Tools/issue153_ctxprobe/build.sh
#   sudo kextload ~/rung3/issue153ctxprobe/Issue153CtxProbe.kext   # see tail -f /var/log/system.log
#   <then run the Tests/issue153_ctx_main host program to actually trigger newUserClient>
#   sudo kextunload -b com.sambushman.Issue153CtxProbe
set -e
OUT=${OUT:-$HOME/rung3/issue153ctxprobe}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
COMMON="-arch ppc -static -fno-common -mlongcall -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/Issue153CtxProbe.cpp" -o "$OUT/Issue153CtxProbe.o"
gcc $COMMON -c "$SRC/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/Issue153CtxProbe" "$OUT/kmod_info.o" "$OUT/Issue153CtxProbe.o" -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

mkdir -p "$OUT/Issue153CtxProbe.kext/Contents/MacOS"
cp "$SRC/Info.plist" "$OUT/Issue153CtxProbe.kext/Contents/Info.plist"
cp "$OUT/Issue153CtxProbe" "$OUT/Issue153CtxProbe.kext/Contents/MacOS/Issue153CtxProbe"
sudo chown -R root:wheel "$OUT/Issue153CtxProbe.kext"
sudo chmod -R go-w "$OUT/Issue153CtxProbe.kext"
echo "bundle: $OUT/Issue153CtxProbe.kext"
