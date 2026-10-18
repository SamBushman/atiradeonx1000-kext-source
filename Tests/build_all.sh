#!/bin/sh
# Tests/build_all.sh - build EVERY test program in Tests/ on the Tiger machine (run from Tests/, on the G5), into ./bin-free in-place binaries
# (the binary sits next to its .c, as the runbooks expect), and fail if any source is neither built nor listed in build_exclude.tsv.
#   sh build_all.sh [GROUP...]      GROUP = harness | tools | destructive | userspace   (default: all four)
# Every *.c / *.cpp / *.m found is considered automatically, so a new test cannot be forgotten: it is either built here, built by a
# special rule below, or must be named (with a reason) in build_exclude.tsv, otherwise this script exits 1.
# Exit: 0 everything built, 1 a build failed or a source is unaccounted for.  Output: one line per file; summary last; failures in build_all.err.
cd "$(dirname "$0")" || exit 2
TESTS_DIR=$(pwd)
GROUPS_WANTED=${*:-harness tools destructive userspace}
ERR=build_all.err; : > "$ERR"
built=0; failed=0; excluded=0; unaccounted=0
CC=${CC:-gcc}
PY=${PY:-/usr/local/bin/python3}   # Tigerbrew python (the one in /opt/local is a Leopard build and traps on Tiger)

excluded_reason() { awk -F'\t' -v f="$1" '$1 !~ /^#/ && $1 == f { print $2; exit }' "$TESTS_DIR/build_exclude.tsv"; }

# frameworks from the includes of one source (plus any extra it pulls in through "common.h"/"glstress.h")
fw_for() {
    f=$1; inc="$f"
    [ -f common.h ] && grep -q '"common.h"' "$f" && inc="$inc common.h"
    [ -f userspace/glstress.h ] && grep -q '"glstress.h"' "$f" && inc="$inc userspace/glstress.h"
    gl=0; io=0; app=0; cf=0
    grep -qE '<OpenGL/|<GLUT/|<AGL/' $inc 2>/dev/null && gl=1
    grep -qE '<IOKit/' $inc 2>/dev/null && io=1
    grep -qE '<ApplicationServices/|<CoreGraphics/|<Carbon/' $inc 2>/dev/null && app=1
    grep -qE '<CoreFoundation/' $inc 2>/dev/null && cf=1
    [ $gl = 1 ] && { app=1; echo "-framework OpenGL"; }
    [ $io = 1 ] && { cf=1; echo "-framework IOKit"; }
    [ $app = 1 ] && echo "-framework ApplicationServices"
    [ $cf = 1 ] && echo "-framework CoreFoundation"
}

try() {   # try SRC OUT [extra link inputs...] : compile with the detected frameworks, retrying without -std=gnu99
    src=$1; out=$2; shift 2
    fw=$(fw_for "$src" | tr "\n" " ")
    if $CC -arch ppc -std=gnu99 -w -I. -o "$out" "$src" "$@" $fw >> "$ERR" 2>&1; then return 0; fi
    $CC -arch ppc -w -I. -o "$out" "$src" "$@" $fw >> "$ERR" 2>&1
}

report() {   # report SRC STATUS
    case $2 in
        ok) built=`expr $built + 1`; echo "built     $1";;
        fail) failed=`expr $failed + 1`; echo "FAILED    $1";;
        excl) excluded=`expr $excluded + 1`; echo "excluded  $1  ($(excluded_reason "$1"))";;
        none) unaccounted=`expr $unaccounted + 1`; echo "UNACCOUNTED $1  (not built by any rule and not in build_exclude.tsv)";;
    esac
}

want() { for g in $GROUPS_WANTED; do [ "$g" = "$1" ] && return 0; done; return 1; }

# --- harness: the parity suite (Makefile) -------------------------------------------------------------------------------------------------
if want harness; then
    if make >> "$ERR" 2>&1; then report "parity_test_harness (Makefile: main.c test_*_context.c test_deep_t*.c)" ok; else report "parity_test_harness" fail; fi
    # sources the Makefile already compiled into the harness
    HARNESS_SRCS=$(sed -n 's/^SRCS *= *//p' Makefile)
fi

# --- tools: stand-alone programs directly in Tests/ -----------------------------------------------------------------------------------------
if want tools; then
    for f in *.c; do
        [ -f "$f" ] || continue
        case " $HARNESS_SRCS " in *" $f "*) continue;; esac
        b=${f%.c}
        if [ -n "$(excluded_reason "$f")" ]; then report "$f" excl; continue; fi
        case $f in
            surface_only_main.c) if try "$f" "$b" test_surface_context.o; then report "$f" ok; else report "$f" fail; fi;;
            *) if try "$f" "$b"; then report "$f" ok; else report "$f" fail; fi;;
        esac
    done
fi

# --- destructive: one binary per destructive test (never part of the parity suite; see destructive/README.md) ---------------------------------
if want destructive; then
    ( cd destructive || exit 1
      for f in *.c; do
          [ -f "$f" ] || continue
          b=${f%.c}
          case $f in dtest.c) continue;; esac                     # library linked into the t3_* / selftest binaries
          if [ -n "$(excluded_reason "destructive/$f")" ]; then echo "excl destructive/$f"; continue; fi
          if grep -q 'int g_testsRun' "$f"; then                    # standalone binary (defines its own counters): no dtest.c
              $CC -w -I.. -o "$b" "$f" -framework IOKit -framework CoreFoundation >> ../"$ERR" 2>&1 && echo "ok destructive/$f" || echo "FAIL destructive/$f"
          elif grep -qE 'dtest.h|t3common.h' "$f"; then                         # framework test: the Makefile rule links dtest.c
              make "destructive-$b" >> ../"$ERR" 2>&1 && echo "ok destructive/$f" || echo "FAIL destructive/$f"
          else                                                      # plain C program (e.g. mmio_probe)
              $CC -w -I.. -o "$b" "$f" >> ../"$ERR" 2>&1 && echo "ok destructive/$f" || echo "FAIL destructive/$f"
          fi
      done ) > build_all.destructive.tmp
    while read st f; do
        case $st in ok) report "$f" ok;; FAIL) report "$f" fail;; excl) report "$f" excl;; esac
    done < build_all.destructive.tmp; rm -f build_all.destructive.tmp
fi

# --- userspace: the GL feature / diag / perf / probe programs -------------------------------------------------------------------------------
if want userspace; then
    for f in userspace/*.c userspace/*.cpp userspace/*.m; do
        [ -f "$f" ] || continue
        case $f in userspace/glwin.m) continue;; esac           # helper compiled into the gl_feature_* tests through glstress.h
        b=${f%.*}
        if [ -n "$(excluded_reason "$f")" ]; then report "$f" excl; continue; fi
        case $f in
            userspace/fnfuzz.c) if try "$f" userspace/fnfuzz_test; then report "$f" ok; else report "$f" fail; fi;;      # userspace/fnfuzz is a directory
            userspace/libgl_dispatch_test.c)                       # needs the generated thunk table and call stubs (header comment of the file)
                D=userspace/.libgl_dispatch_build; mkdir -p $D
                if ( cd userspace && $PY libgl_dispatch_gen.py 4096 > .libgl_dispatch_build/thunks.s && $PY libgl_dispatch_gen_calls.py /System/Library/Frameworks/OpenGL.framework/Headers/gl.h /System/Library/Frameworks/OpenGL.framework/Headers/glext.h > .libgl_dispatch_build/dsp_calls.c ) >> "$ERR" 2>&1 \
                   && $CC -arch ppc -w -std=gnu99 -o userspace/libgl_dispatch_test "$f" $D/dsp_calls.c $D/thunks.s >> "$ERR" 2>&1; then report "$f" ok; else report "$f" fail; fi;;
            *.cpp) if g++ -arch ppc -w -I. -o "$b" "$f" >> "$ERR" 2>&1; then report "$f" ok; else report "$f" fail; fi;;
            *) if try "$f" "$b"; then report "$f" ok; else report "$f" fail; fi;;
        esac
    done
fi

echo "build_all: $built built, $failed failed, $excluded excluded, $unaccounted unaccounted   (errors: Tests/$ERR)"
[ "$failed" -eq 0 ] && [ "$unaccounted" -eq 0 ]
