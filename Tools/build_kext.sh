#!/bin/sh
# build_kext.sh - build a loadable ATIRadeonX1000.kext bundle (PPC) with Apple's
# own gcc 4.0.1, the way Xcode 2.x does for a Tiger C++ kext.
#
# Run ON a Tiger PPC machine (e.g. the G5) from the repo root:
#     sh Tools/build_kext.sh
# Env: OUT (build dir, default /tmp/kext_build), KEXT_ID, KEXT_VERSION (must match
# the bundle's Info.plist; use a different KEXT_ID for a dry-run copy).
#
# Notes:
#  * A Tiger kext is an MH_OBJECT: the link is `-static -nostdlib -r` against
#    libkmodc++/libkmod/libcc_kext, NOT `-kext` (that flag is Xcode 3+/ld64).
#    The kernel loader (kxld/kextload) does the final relocation.
#  * Objects MUST be compiled `-static -fno-common` (otherwise gcc emits PIC
#    symbol stubs and the link fails with "unsupported section picsymbolstub1").
#  * Three shims let the 2005-era compiler accept this project's C++11-isms:
#    -Doverride=  -Dnullptr=0  "-Dstatic_assert(a,b)="  (static_assert is thus
#    only enforced by a modern gcc, e.g. Tigerbrew gcc-7 -std=gnu++11).
#  * Expected symbols left undefined after /mach_kernel's own nm output (all imported
#    by the shipped kext too, resolved from the KPI symbol sets / dependency kexts):
#    IOLockLock, IOLockUnlock, IOUserClient::init (x2), IONDRVFramebuffer::metaClass.
#  * Use the KPI names the shipped kext imports (IOLockLock/IOLockUnlock), not the
#    kernel-internal mutex_unlock_rwcmb/lck_mtx_unlock: those are not in the kernel's
#    exported symbol sets and kld rejects them.
#  * Follow with Tools/link_check.sh to prove it links (without loading).
set -e
OUT=${OUT:-/tmp/kext_build}
KEXT_ID=${KEXT_ID:-com.apple.ATIRadeonX1000}
KEXT_VERSION=${KEXT_VERSION:-4.1.9}
KFW=/System/Library/Frameworks/Kernel.framework/Headers
GCCLIB=/usr/lib/gcc/powerpc-apple-darwin8/4.0.1
COMMON="$OPT -arch ppc -static -fno-common -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -I$KFW -w"
CXXFLAGS="$COMMON -fno-rtti -fno-exceptions -fapple-kext -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)="

rm -rf "$OUT"; mkdir -p "$OUT/obj"
fail=0
for f in Sources/*.cpp; do
    b=$(basename "$f" .cpp)
    g++ $CXXFLAGS -c "$f" -o "$OUT/obj/$b.o" 2>"$OUT/obj/$b.err" || { echo "FAIL $f"; head -5 "$OUT/obj/$b.err"; fail=1; }
done
[ $fail -eq 0 ] || exit 1

gcc $COMMON -DKEXT_ID=$KEXT_ID "-DKEXT_VERSION=\"$KEXT_VERSION\"" -c Tools/kmod_info.c -o "$OUT/kmod_info.o"
g++ -arch ppc -nostdlib -static -r -o "$OUT/ATIRadeonX1000" "$OUT/kmod_info.o" "$OUT"/obj/*.o \
    -L$GCCLIB -lkmodc++ -lkmod -lcc_kext

nm -u "$OUT/ATIRadeonX1000" | sed 's/^ *//' | sort -u > "$OUT/undef.txt"
nm /mach_kernel | awk '{print $3}' | sort -u > "$OUT/kernel_exports.txt"
echo "objects: $(ls "$OUT"/obj/*.o | wc -l); undefined: $(wc -l < "$OUT/undef.txt")"
echo "not in /mach_kernel nm (expected: IOLockLock, IOLockUnlock, IOUserClient::init x2, IONDRVFramebuffer::metaClass):"
comm -23 "$OUT/undef.txt" "$OUT/kernel_exports.txt"

B="$OUT/ATIRadeonX1000.kext"
mkdir -p "$B/Contents/MacOS"
sed -e "s|<string>com.apple.ATIRadeonX1000</string>|<string>$KEXT_ID</string>|" Resources/Info.plist > "$B/Contents/Info.plist"
cp "$OUT/ATIRadeonX1000" "$B/Contents/MacOS/ATIRadeonX1000"
echo "bundle: $B"
