#!/bin/sh
# Tools/vram_peek/build.sh - issue #92 follow-up. Same pattern as Tools/ga_probe/build.sh: a small, SEPARATE, read-only diagnostic kext, staged to
# the persistent ~/rung3 scratch area (never /tmp - wiped on reboot).
#
#   sh Tools/vram_peek/build.sh                          # walks accel->dvdCtx->surface->buffer record live, no address to supply
#   TARGET_SLOT=15 sh Tools/vram_peek/build.sh           # optional: pick a different surface buffer slot (default 16)
#   sudo kextload ~/rung3/vrampeek/VRAMPeek.kext        # see system.log for the IOLog output
#   sudo kextunload -b com.sambushman.VRAMPeek
#
# -mlongcall required for the same reason as GAProbe (24-bit bl overflow once the kernel's kext-address allocator places this far from /mach_kernel).
set -e
OUT=${OUT:-$HOME/rung3/vrampeek}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
EXTRA_DEFS=""
if [ -n "$TARGET_SLOT" ]; then EXTRA_DEFS="$EXTRA_DEFS -DTARGET_SLOT=$TARGET_SLOT"; fi
if [ -n "$TARGET_LEN" ]; then EXTRA_DEFS="$EXTRA_DEFS -DTARGET_LEN=$TARGET_LEN"; fi
COMMON="-arch ppc -static -fno-common -mlongcall -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE $EXTRA_DEFS -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/VRAMPeek.cpp" -o "$OUT/VRAMPeek.o"
gcc $COMMON -c "$SRC/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/VRAMPeek" "$OUT/kmod_info.o" "$OUT/VRAMPeek.o" -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

mkdir -p "$OUT/VRAMPeek.kext/Contents/MacOS"
cp "$SRC/Info.plist" "$OUT/VRAMPeek.kext/Contents/Info.plist"
cp "$OUT/VRAMPeek" "$OUT/VRAMPeek.kext/Contents/MacOS/VRAMPeek"
sudo chown -R root:wheel "$OUT/VRAMPeek.kext"
sudo chmod -R go-w "$OUT/VRAMPeek.kext"
echo "bundle: $OUT/VRAMPeek.kext"
