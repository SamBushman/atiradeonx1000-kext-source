#!/bin/sh
# Tools/ga_probe/build.sh - issue #141, user-authorized raw-MMIO probe (see Tests/idct_engine_findings.md section 9u).
#
# Builds GAProbe.kext: a small, SEPARATE, read-only diagnostic kext (not part of the rebuilt driver under Sources/ -
# it never matches or competes for the GPU; it locates the already-running stock ATIRadeonX1000 service by name and
# reads its register BAR). Exists because GA_IDLE (0x425c) / GA_SOFT_RESET (0x429c) - the registers AMD's own documented
# hang-recovery procedure (R5xx_Acceleration_v1.5.pdf 10.1.9) needs beyond RBBM_SOFTRESET (0x00f0, already reachable
# through the stock kext's existing read_regs/write_regs) - are outside that mechanism's `& 0x1ffc` mask, and /dev/mem
# is blocked by kern.securelevel=1 (confirmed; there is no startup script to patch - the kernel raises it once during
# the single-user to multi-user transition, and single-user mode has no network to drive this from, see section 9u).
#
# Run ON the Tiger G5 from the repo root. ALWAYS stage to ~/rung3 (persistent), never /tmp (wiped on every reboot -
# this bit a probe session once already, see the "standing rule" this project now follows for the same reason the
# T3/va_capture tooling stages there: Tests/destructive and Tools/userspace/va_capture both already do this).
#
#   sh Tools/ga_probe/build.sh
#   sudo kextload ~/rung3/gaprobe/GAProbe.kext        # see dmesg / tail -f /var/log/system.log for the IOLog output
#   sudo kextunload -b com.sambushman.GAProbe
#
# -mlongcall is required: a 24-bit `bl` from this tiny kext to kernel code overflows once the kernel's automatic
# kext-address allocator places it far from /mach_kernel (confirmed - first load attempt without this flag failed
# with "relocation overflow"); -mlongcall uses indirect branches instead, immune to placement distance.
# Dry-run first with Tools/link_check.sh's technique (kextload -n -s) before ever loading for real.
set -e
OUT=${OUT:-$HOME/rung3/gaprobe}
SRC=$(cd "$(dirname "$0")" && pwd)
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
COMMON="-arch ppc -static -fno-common -mlongcall -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

mkdir -p "$OUT"
g++ $CXXFLAGS -c "$SRC/GAProbe.cpp" -o "$OUT/GAProbe.o"
gcc $COMMON -c "$SRC/kmod_info.c" -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/GAProbe" "$OUT/kmod_info.o" "$OUT/GAProbe.o" -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

mkdir -p "$OUT/GAProbe.kext/Contents/MacOS"
cp "$SRC/Info.plist" "$OUT/GAProbe.kext/Contents/Info.plist"
cp "$OUT/GAProbe" "$OUT/GAProbe.kext/Contents/MacOS/GAProbe"
sudo chown -R root:wheel "$OUT/GAProbe.kext"
sudo chmod -R go-w "$OUT/GAProbe.kext"
echo "bundle: $OUT/GAProbe.kext"
