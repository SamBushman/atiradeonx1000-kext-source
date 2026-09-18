#!/bin/sh
# compile_check.sh - compile every Sources/*.cpp with Apple's real gcc 4.0.1
# (-fapple-kext, so vtable layout matches the original) and check the result
# links: no undefined symbols other than the kernel's exports, the real kext's
# own kext-dependency imports, and toolchain support.
#
# Run ON a Tiger PPC machine (e.g. the G5) from the repo root:  sh Tools/compile_check.sh
#
# Three tiny shims let the 2005-era compiler accept this project's C++11-isms:
#   -Doverride=  -Dnullptr=0  "-Dstatic_assert(a,b)="
# (static_assert is dropped, so sizeof checks are only enforced by a modern gcc:
#  use gcc-7 from Tigerbrew with -std=gnu++11 if you want them enforced.)
#
# Expected undefined-after-kernel list (all legitimate, all imported by the
# real kext too): __ZN12IOUserClient4initEP12OSDictionary, __ZN12IOUserClient4initEv,
# __ZN17IONDRVFramebuffer9metaClassE (IONDRVSupport kext), dyld_stub_binding_helper
# (linker-provided).
set -e
OUT=${OUT:-/tmp/kext_compile_check}
rm -rf "$OUT"; mkdir -p "$OUT/obj"
KFW=/System/Library/Frameworks/Kernel.framework/Headers
FLAGS="-arch ppc -fno-rtti -fno-exceptions -fapple-kext -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -Doverride= -Dnullptr=0 -Dstatic_assert(a,b)= -I$KFW -w"
fail=0
for f in Sources/*.cpp; do
    b=$(basename "$f" .cpp)
    g++ $FLAGS -c "$f" -o "$OUT/obj/$b.o" 2>"$OUT/obj/$b.err" || { echo "FAIL $f"; head -5 "$OUT/obj/$b.err"; fail=1; }
done
[ $fail -eq 0 ] || exit 1
ld -r -arch ppc "$OUT"/obj/*.o -o "$OUT/all.o"
nm -u "$OUT/all.o" | sed 's/^ *//' | sort -u > "$OUT/undef.txt"
nm /mach_kernel | awk '{print $3}' | sort -u > "$OUT/kernel_exports.txt"
echo "objects: $(ls "$OUT"/obj/*.o | wc -l); undefined symbols: $(wc -l < "$OUT/undef.txt")"
echo "not exported by /mach_kernel:"
comm -23 "$OUT/undef.txt" "$OUT/kernel_exports.txt"
