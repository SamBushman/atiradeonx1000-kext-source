#!/bin/sh
# fnfuzz_par.sh - run ONE fnfuzz ledger as several contiguous chunks (`@first,count`), a few at a time, and merge the outputs (Nov 14, user-approved plan: option 1).
#
#   fnfuzz_par.sh FNFUZZ LEDGER STOCK REBUILT TRIALS NCHUNKS NJOBS OUTPREFIX
#
# Environment (FNFUZZ_*, FNFUZZ_LAZYSTOCK2, ...) is inherited by every chunk. Each chunk writes OUTPREFIX.c<k>.full; the merge writes OUTPREFIX.full:
# every chunk line except the chunks' own `fnfuzz:` summary and `RESULT:` lines, then ONE summary line and ONE `RESULT:` line - but only if EVERY chunk ended in a
# `RESULT:` line. A chunk that did not (killed, crashed) makes the merged file end in `NO RESULT: chunk(s) ... incomplete` instead, so a partial run can never read as a pass,
# and OUTPREFIX.merged.done is written only for a complete merge. A checksum manifest (fnfuzz_manifest.sh: harness, ledger, both images, scripts, FNFUZZ_* env) is written to OUTPREFIX.manifest before the run and OUTPREFIX.manifest.end after it; if they differ the merge is NO RESULT. The script never kills anything; to stop a run, kill the script's PID and the PIDs listed in OUTPREFIX.pids
# (by PID, never by name: other sweeps share the binary name). Portable sh/awk (Tiger bash 2.05b, BSD awk).
#
# Why chunks: one fnfuzz parent uses about one core; the ledger rows are independent, so K parents give up to K times the throughput (keep NJOBS <= 3 on the G5).
# More chunks than jobs (e.g. 24 chunks, 3 jobs) balances rows of very different cost.

[ $# -eq 8 ] || { echo "usage: $0 FNFUZZ LEDGER STOCK REBUILT TRIALS NCHUNKS NJOBS OUTPREFIX" >&2; exit 2; }
FZ=$1; LEDGER=$2; STOCK=$3; REB=$4; TRIALS=$5; NCH=$6; NJ=$7; OUT=$8
N=`awk -F'\t' 'NF >= 7 && $1 ~ /^[0-9]+$/' "$LEDGER" | wc -l | tr -d ' '`
[ "$N" -gt 0 ] || { echo "no candidate rows in $LEDGER" >&2; exit 2; }
[ "$NCH" -gt "$N" ] && NCH=$N
PER=`expr \( $N + $NCH - 1 \) / $NCH`
rm -f "$OUT.merged.done" "$OUT.full" "$OUT.pids" "$OUT".c*.full "$OUT.manifest" "$OUT.manifest.end"
# state manifest (checksums of harness, images, ledger, scripts + FNFUZZ_* env), written before the first chunk and again after the last; a difference makes the merge NO RESULT
MF=`dirname "$0"`/fnfuzz_manifest.sh
FNFUZZ_PAR_SCRIPT=$0; export FNFUZZ_PAR_SCRIPT
sh "$MF" write "$OUT.manifest" "$FZ" "$LEDGER" "$STOCK" "$REB" "$TRIALS" || echo "fnfuzz_par: WARNING manifest could not be written" >&2
echo "fnfuzz_par: $N rows, $NCH chunks of up to $PER, $NJ at a time, $TRIALS trials, outputs $OUT.c<k>.full" >&2

PIDS=""; K=0
live() { n=0; for p in $PIDS; do kill -0 $p 2>/dev/null && n=`expr $n + 1`; done; echo $n; }
while [ $K -lt $NCH ]; do
  FIRST=`expr $K \* $PER`; [ $FIRST -ge $N ] && break
  CNT=$PER; [ `expr $FIRST + $CNT` -gt $N ] && CNT=`expr $N - $FIRST`
  while [ `live` -ge $NJ ]; do sleep 5; done
  "$FZ" "$LEDGER" "$STOCK" "$REB" "$TRIALS" "@$FIRST,$CNT" > "$OUT.c$K.full" 2>&1 < /dev/null &
  P=$!; PIDS="$PIDS $P"; echo "chunk $K rows $FIRST..`expr $FIRST + $CNT - 1` pid $P" >> "$OUT.pids"
  K=`expr $K + 1`
done
for p in $PIDS; do wait $p; done
sh "$MF" write "$OUT.manifest.end" "$FZ" "$LEDGER" "$STOCK" "$REB" "$TRIALS"
MFOK=1; sh "$MF" cmp "$OUT.manifest" "$OUT.manifest.end" > "$OUT.manifest.diff" 2>&1 || MFOK=0

# merge
BAD=""; K=0
while [ $K -lt $NCH ]; do
  f="$OUT.c$K.full"; [ -f "$f" ] || { K=`expr $K + 1`; continue; }
  tail -1 "$f" | grep '^RESULT: ' > /dev/null || BAD="$BAD $K"
  K=`expr $K + 1`
done
: > "$OUT.full"
cat "$OUT".c*.full | grep -v '^RESULT: ' | grep -v '^fnfuzz: [0-9]* functions' >> "$OUT.full"
cat "$OUT".c*.full | grep '^fnfuzz: [0-9]* functions' | awk '
  { for (i = 2; i <= NF; i++) {
      if ($i == "functions,") f += $(i-1); else if ($i == "trials") t += $(i-1); else if ($i == "differ,") d += $(i-1);
      else if ($i == "uninformative") u += $(i-1); else if ($i == "nondeterministic") n += $(i-1); } }
  END { printf "fnfuzz: %d functions, %d trials (each: stock twice + rebuilt; merged from chunks); %d differ, %d uninformative (always the same signal), %d nondeterministic in the stock\n", f, t, d, u, n; print (d == 0 ? "RESULT: PASS" : "RESULT: FAIL") }' > "$OUT.sum"
if [ $MFOK = 1 ]; then echo "manifest: start == end (harness `grep '^file harness ' "$OUT.manifest" | awk '{print $3}'`, stock `grep '^file stock ' "$OUT.manifest" | awk '{print $3}'`, rebuilt `grep '^file rebuilt ' "$OUT.manifest" | awk '{print $3}'`, ledger `grep '^file ledger ' "$OUT.manifest" | awk '{print $3}'`); full list in $OUT.manifest" >> "$OUT.full"
else echo "manifest: CHANGED DURING THE RUN (see $OUT.manifest.diff)" >> "$OUT.full"; fi
if [ -z "$BAD" ] && [ $MFOK = 1 ]; then
  cat "$OUT.sum" >> "$OUT.full"
  echo done > "$OUT.merged.done"
elif [ -z "$BAD" ]; then
  echo "NO RESULT: harness/image/ledger/script/env checksums changed while the run was in progress (see $OUT.manifest.diff); results must not be trusted" >> "$OUT.full"
else
  echo "NO RESULT: chunk(s)$BAD incomplete (no RESULT line); merged counts are partial and must not be trusted" >> "$OUT.full"
fi
rm -f "$OUT.sum"
tail -2 "$OUT.full"
