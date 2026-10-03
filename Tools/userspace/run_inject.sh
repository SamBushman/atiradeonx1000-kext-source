#!/bin/sh
# run_inject.sh - issue #42: run ONE glcov feature / glwin variant under the recorder with hand-built records spliced into one flush (OPCODE_INJECT_WORDS). Runs ON the G5.
#   sh run_inject.sh OUTDIR NAME "WORDS" FLUSH "PROGRAM ARGS"      e.g. sh run_inject.sh /tmp/inj op2b 0x2b000001 3 "./glcov clear"
O=${1:?}; N=${2:?}; W=${3:?}; F=${4:?}; cmd=${5:?}; mkdir -p "$O"; P="`pwd`"
cd0=`ps auxww | grep "[c]rashdump" | grep -v " Z " | wc -l`
DYLD_INSERT_LIBRARIES="$P/opcode_recorder.dylib" OPCODE_LOG="$O/$N.tsv" OPCODE_INJECT_WORDS="$W" OPCODE_INJECT_FLUSH=$F $cmd > "$O/$N.out" 2>&1 &
pid=$!; i=0
while kill -0 $pid 2>/dev/null && [ $i -lt 60 ]; do sleep 1; i=`expr $i + 1`; done
if kill -0 $pid 2>/dev/null; then echo "$N: STILL RUNNING after 60 s (pid $pid, left alone)"; exit 3; fi
wait $pid; rc=$?; cd1=`ps auxww | grep "[c]rashdump" | grep -v " Z " | wc -l`
echo "$N: exit $rc ; crashdump $cd0 -> $cd1 ; `grep -c '^FLUSH' "$O/$N.tsv"` flushes ; `grep -a '^INJECT' "$O/$N.tsv" | head -1`"; tail -2 "$O/$N.out" | cut -c1-100
grep -a "ANOMALY\|^TAIL" "$O/$N.tsv" | head -3
