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
MF=`dirname "$0"`/fnfuzz_manifest.sh
FNFUZZ_PAR_SCRIPT=$0; export FNFUZZ_PAR_SCRIPT
FNFUZZ_MANIFEST_LAYOUT="rows $N chunks $NCH per $PER"; export FNFUZZ_MANIFEST_LAYOUT
mfwrite() { sh "$MF" write "$1" "$FZ" "$LEDGER" "$STOCK" "$REB" "$TRIALS"; }
stamp() { date '+%Y-%m-%dT%H:%M:%S'; }
lastres() { tail -1 "$1" 2>/dev/null | grep '^RESULT: ' > /dev/null; }
sumof() { if command -v md5sum >/dev/null 2>&1; then md5sum "$1" | awk '{print $1}'; else md5 -q "$1"; fi; }

# Resume (FNFUZZ_RESUME=1): keep chunk outputs from an earlier invocation ONLY if (a) the state manifest of that invocation equals the current one (checksums of harness, images,
# ledger, scripts, FNFUZZ_* env, chunk layout) and (b) the chunk output ends in a RESULT line and its md5 equals the one recorded in OUT.chunks when it finished. Anything else
# is a fresh start from row 0 (never a partial trust). Without FNFUZZ_RESUME the old outputs are always discarded.
RESUMED=""; KEEP=" "
rm -f "$OUT.merged.done" "$OUT.full" "$OUT.manifest.end" "$OUT.manifest.diff" "$OUT.resume.log"
if [ -n "$FNFUZZ_RESUME" ] && [ -f "$OUT.manifest" ] && [ -f "$OUT.chunks" ]; then
  mfwrite "$OUT.manifest.now"
  if sh "$MF" cmp "$OUT.manifest" "$OUT.manifest.now" > "$OUT.resume.log" 2>&1; then
    K=0
    while [ $K -lt $NCH ]; do
      f="$OUT.c$K.full"
      REC=`grep "^chunk $K .* md5 " "$OUT.chunks" | tail -1 | sed 's/.* md5 \([0-9a-f]*\).*/\1/'`
      if [ -f "$f" ] && lastres "$f" && [ -n "$REC" ] && [ "`sumof "$f"`" = "$REC" ]; then KEEP="$KEEP$K "; RESUMED="$RESUMED $K"; echo "chunk $K kept (resumed: RESULT line present, md5 $REC matches record, manifest identical) at `stamp`" >> "$OUT.chunks"
      else rm -f "$f"; fi
      K=`expr $K + 1`
    done
    echo "resume: manifest identical; kept chunks:${RESUMED:- none}" >> "$OUT.resume.log"
  else
    echo "resume REFUSED: manifest differs from the saved one (diff above); starting over from row 0" >> "$OUT.resume.log"
    rm -f "$OUT.pids" "$OUT".c*.full "$OUT.chunks" "$OUT.manifest"
  fi
  rm -f "$OUT.manifest.now"; cat "$OUT.resume.log" >&2
else
  rm -f "$OUT.pids" "$OUT".c*.full "$OUT.chunks" "$OUT.manifest"
fi
[ -f "$OUT.manifest" ] || mfwrite "$OUT.manifest" || echo "fnfuzz_par: WARNING manifest could not be written" >&2
echo "fnfuzz_par: $N rows, $NCH chunks of up to $PER, $NJ at a time, $TRIALS trials, outputs $OUT.c<k>.full${RESUMED:+; resumed chunks:$RESUMED}" >&2

PIDS=""; K=0; MFOK=1; LAUNCH=""; DONEL=" "
live() { n=0; for p in $PIDS; do kill -0 $p 2>/dev/null && n=`expr $n + 1`; done; echo $n; }
# record per-chunk facts the moment a chunk has finished (so a later kill of this script cannot lose them): rows, pid, start, exit status, last write time, size, md5, RESULT line present
reap() {
  for e in $LAUNCH; do
    k=`echo $e | cut -d: -f1`; p=`echo $e | cut -d: -f2`; st=`echo $e | cut -d: -f3-`
    case "$DONEL" in *" $k "*) continue ;; esac
    if [ "$1" = final ] || ! kill -0 $p 2>/dev/null; then
      wait $p; rc=$?; DONEL="$DONEL$k "
      f="$OUT.c$k.full"; res=no; lastres "$f" && res=yes
      echo "chunk $k pid $p started $st rc $rc output-last-written `ls -l "$f" | awk '{print $6, $7, $8}'` bytes `wc -c < "$f" | tr -d ' '` result-line $res md5 `sumof "$f"`" >> "$OUT.chunks"
    fi
  done
}
while [ $K -lt $NCH ]; do
  FIRST=`expr $K \* $PER`; [ $FIRST -ge $N ] && break
  case "$KEEP" in *" $K "*) K=`expr $K + 1`; continue ;; esac
  CNT=$PER; [ `expr $FIRST + $CNT` -gt $N ] && CNT=`expr $N - $FIRST`
  while [ `live` -ge $NJ ]; do sleep 5; reap; done
  reap
  # state check at every chunk launch (catches a change made after the run began); on a change no further chunk starts and the merge is NO RESULT
  mfwrite "$OUT.manifest.now"
  if ! sh "$MF" cmp "$OUT.manifest" "$OUT.manifest.now" > "$OUT.manifest.diff" 2>&1; then MFOK=0; echo "fnfuzz_par: state changed before chunk $K; no further chunks launched" >&2; break; fi
  rm -f "$OUT.manifest.now"
  "$FZ" "$LEDGER" "$STOCK" "$REB" "$TRIALS" "@$FIRST,$CNT" > "$OUT.c$K.full" 2>&1 < /dev/null &
  P=$!; PIDS="$PIDS $P"; LAUNCH="$LAUNCH $K:$P:`stamp`"; echo "chunk $K rows $FIRST..`expr $FIRST + $CNT - 1` pid $P" >> "$OUT.pids"
  K=`expr $K + 1`
done
while [ `live` -gt 0 ]; do sleep 2; reap; done
reap final
rm -f "$OUT.manifest.now"
mfwrite "$OUT.manifest.end"
if [ $MFOK = 1 ]; then sh "$MF" cmp "$OUT.manifest" "$OUT.manifest.end" > "$OUT.manifest.diff" 2>&1 || MFOK=0; fi
[ $MFOK = 1 ] && rm -f "$OUT.manifest.diff"

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
if [ $MFOK = 1 ]; then echo "manifest: start == end (harness `grep '^file harness ' "$OUT.manifest" | awk '{print $3}'`, stock `grep '^file stock ' "$OUT.manifest" | awk '{print $3}'`, rebuilt `grep '^file rebuilt ' "$OUT.manifest" | awk '{print $3}'`, ledger `grep '^file ledger ' "$OUT.manifest" | awk '{print $3}'`); full list in $OUT.manifest${RESUMED:+; chunks kept from an earlier invocation with an identical manifest:$RESUMED}; per-chunk record $OUT.chunks" >> "$OUT.full"
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
