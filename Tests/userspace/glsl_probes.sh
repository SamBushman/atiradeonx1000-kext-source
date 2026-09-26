#!/bin/sh
# glsl_probes.sh STOCK_DYLIB REBUILT_DYLIB [SHADER...]  (on the G5, in the directory holding glsl_probe and the shaders)
# Compiles each shader with both libGLProgrammability images and compares the whole output (ARB program, info log) byte for byte, ignoring only
# the two heap-pointer lines. Temp files and cmp: Tiger's bash 2.05b makes `diff <(a) <(b)` exit 0 whatever the contents (a false pass that
# hid the vector constant-folding bug until 2026-09-25).
S=$1; R=$2; shift 2
[ $# -gt 0 ] || set -- glsl_intfold.vert glsl_intfold2.vert glsl_libm.vert glsl_constmat.vert
rc=0
for sh in "$@"; do
    ./glsl_probe "$S" 1 0 3 "$sh" 2>&1 | grep -v '^mk=\|^pp=' > /tmp/glslp_s.$$
    ./glsl_probe "$R" 1 0 3 "$sh" 2>&1 | grep -v '^mk=\|^pp=' > /tmp/glslp_r.$$
    if cmp -s /tmp/glslp_s.$$ /tmp/glslp_r.$$; then echo "$sh: identical ($(wc -l < /tmp/glslp_s.$$ | tr -d ' ') lines)"
    else echo "$sh: DIFFERS"; diff /tmp/glslp_s.$$ /tmp/glslp_r.$$ | head -10; rc=1; fi
done
rm -f /tmp/glslp_s.$$ /tmp/glslp_r.$$
exit $rc
