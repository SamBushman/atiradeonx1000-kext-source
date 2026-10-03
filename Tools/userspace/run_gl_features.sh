#!/bin/sh
# run_gl_features.sh - issue #42: run Tests/userspace/glcov.c one feature per process under Tools/userspace/opcode_recorder.dylib. Runs ON the G5.
#   sh run_gl_features.sh OUTDIR FEATURE [FEATURE ...]       (glcov, glwin and opcode_recorder.dylib in the current directory)
#   a FEATURE of the form stress:SEED,ITERS runs the seeded random-state stress of glstress.h in a pbuffer (GLSTRESS_NO=letters skips state categories, default v)
#   a FEATURE of the form win:SAMPLES,FRAMES,STENCIL,DEPTHBITS,MODE runs the windowed workload glwin instead (e.g. win:4,60,1,24,basic)
# Each feature gets its own log OUTDIR/<feature>.tsv and output OUTDIR/<feature>.out, a 90 s kill, and a check for new crashdump processes afterwards. STOPS at the first
# feature that exits non-zero, is killed, or leaves a crashdump: a driver problem in one feature must not cascade into the next.
O=${1:?usage: sh run_gl_features.sh OUTDIR FEATURE...}; shift; mkdir -p "$O"; P="`pwd`"; : >> "$O/summary.txt"
cd0=`ps auxww | grep "[c]rashdump" | grep -v " Z " | wc -l`
for f in "$@"; do
  case "$f" in
    win:*) a=`echo "${f#win:}" | tr , ' '`; f=`echo "$f" | tr ':,' '__'`; cmd="./glwin $a" ;;      # win:SAMPLES,FRAMES,STENCIL,DEPTHBITS,MODE  -> the windowed workload glwin
    stress:*) sd=`echo "${f#stress:}" | cut -d, -f1`; it=`echo "${f#stress:}" | cut -d, -f2`; f=`echo "$f" | tr ':,' '__'`; cmd="env GLSTRESS_SEED=$sd GLSTRESS_ITERS=$it GLSTRESS_NO=${GLSTRESS_NO:-v} ./glcov stress" ;;   # stress:SEED,ITERS (ARB vertex programs skipped by default: see Tests/pm4_opcode_usage.md)
    *) cmd="./glcov $f" ;;
  esac
  DYLD_INSERT_LIBRARIES="$P/opcode_recorder.dylib" OPCODE_LOG="$O/$f.tsv" $cmd > "$O/$f.out" 2>&1 &
  pid=$!; i=0
  while kill -0 $pid 2>/dev/null && [ $i -lt 90 ]; do sleep 1; i=`expr $i + 1`; done
  if kill -0 $pid 2>/dev/null; then kill $pid; sleep 2; kill -9 $pid 2>/dev/null; echo "$f: KILLED after 90 s" >> "$O/summary.txt"; echo "STOP: $f killed"; cat "$O/summary.txt"; exit 3; fi
  wait $pid; rc=$?; cd1=`ps auxww | grep "[c]rashdump" | grep -v " Z " | wc -l`
  echo "$f: exit $rc ; `grep -c '^FLUSH' "$O/$f.tsv" 2>/dev/null` flushes ; `tail -1 "$O/$f.out" | cut -c1-70`" >> "$O/summary.txt"
  case "$cmd" in *glcov*) grep -q "glcov done" "$O/$f.out" || echo "$f: INCOMPLETE (the GL stack ended the process early, e.g. exit() inside a GL call: see the .out; the tally up to then is still in the log)" >> "$O/summary.txt" ;; esac
  if [ $rc -ne 0 ] || [ "$cd1" -gt "$cd0" ]; then echo "STOP: $f exit $rc crashdump $cd0 -> $cd1"; cat "$O/summary.txt"; exit 4; fi
done
cat "$O/summary.txt"
