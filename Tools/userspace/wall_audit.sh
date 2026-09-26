#!/bin/sh
# wall_audit.sh TREE OUT MODE - compiler-warning audit of a linked image's sources on the Tiger G5 (issue #68, criterion 2). Run ON the G5 (scp the link tree there).
#   MODE gcc4   Apple gcc 4.0.1 `-O1 -Wall`: the compiler the images are built with (uninitialised use needs -O1; -O0 does not analyse data flow)
#   MODE gcc14  Tigerbrew gcc-14 `-fsyntax-only` with the front-end conversion diagnostics gcc 4.0.1 does not have: -Wfloat-conversion (a float VALUE converted into an integer
#               word - the stock stores its bits), -Wtype-limits, -Wsequence-point, -Wshift-*, -Wtautological-compare ...
# One <part>.warn per part in OUT (DONE when finished). Triage: `cat OUT/part_*.warn | grep warning: | sed ... | sort | uniq -c` - see Userspace/README.md, "Compiler-warning audit".
T="$1"; O="$2"; M="${3:-gcc4}"
cd "$T" || exit 1
rm -rf "$O"; mkdir -p "$O"
for f in part_*.c x_*part_*.c; do [ -f $f ] || continue
  case $M in
    gcc4)  gcc -arch ppc -fPIC -fno-common -force_cpusubtype_ALL -O1 -Wall -c $f -o /dev/null 2> "$O/${f%.c}.warn";;
    gcc14) /usr/local/bin/gcc-14 -std=gnu89 -Wno-all -Wno-implicit-function-declaration -Wno-int-conversion -Wno-incompatible-pointer-types -Wno-builtin-declaration-mismatch \
             -Wfloat-conversion -Woverflow -Wtype-limits -Wsequence-point -Wshift-count-overflow -Wshift-negative-value -Wdiv-by-zero -Wtautological-compare -Wint-in-bool-context \
             -fsyntax-only $f 2> "$O/${f%.c}.warn";;
  esac
done
echo DONE > "$O/DONE"
