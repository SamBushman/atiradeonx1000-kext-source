#!/bin/sh
# Tools/issue147_minstart/build.sh - issue #147 isolation test (user-requested, 2026-10-07).
#
# Builds a MINIMAL real IOService kext, under the EXACT same IOPCIMatch/IOProviderClass/IOClass
# ("ATIRadeonX1000") as the real driver, whose start() does only: call the base IOService::start,
# map BAR2 (register 0x18) on the real IOPCIDevice provider, and IOLog the raw chip-ID bytes - then
# return false. No object-pool allocation, no workloop/event sources, no AGP/GART setup, none of the
# ~380 lines of real driver initialization that happen before the equivalent read in the real driver.
#
# Run ON the Tiger G5 from the repo root:
#   sh Tools/issue147_minstart/build.sh
#   (then: unload whichever kext currently owns ATIRadeonX1000, kextload the .kext this produces,
#    read /var/log/system.log, then reload the real accelerator)
#
# Uses the SAME toolchain/flags as Tools/build_kext.sh (Apple's own gcc 4.0.1, -fapple-kext,
# -mlongcall) since this is a real OSObject/IOService subclass (needs the libkmodc++ _start/_stop
# constructor-running entry points, not a plain C kmod like Tools/ga_probe or issue147_probe).
set -e
OUT=${OUT:-/tmp/minstart_build}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
OPT=${OPT:-}
COMMON="$OPT -mlongcall -arch ppc -static -fno-common -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext"

rm -rf "$OUT"; mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/MinStart.cpp" -o "$OUT/MinStart.o"
gcc $COMMON -DKEXT_ID=com.example.ATIRadeonX1000.minstart "-DKEXT_VERSION=\"1.0.0\"" \
    -c "$(dirname "$SRC")/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/MinStart" "$OUT/kmod_info.o" "$OUT/MinStart.o" \
    -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

B="$OUT/MinStart.kext"
mkdir -p "$B/Contents/MacOS"
cp "$SRC/Info.plist" "$B/Contents/Info.plist"
cp "$OUT/MinStart" "$B/Contents/MacOS/MinStart"
echo "bundle: $B"
