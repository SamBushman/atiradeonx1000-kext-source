#!/bin/sh
# fnfuzz_chunk.sh - the REMOTE half of fnfuzz_dist.py (Nov 15): run ONE chunk (`@first,count`) of a ledger on this machine, detached from the caller, with the same
# checksum discipline as fnfuzz_par.sh. Portable sh (Tiger bash 2.05b / BSD tools). The FNFUZZ_* environment is inherited from the caller (`env A=b ... sh fnfuzz_chunk.sh ...`).
#
#   fnfuzz_chunk.sh start DIR FZ STOCK REBUILT TRIALS            write DIR/manifest.start (harness, ledger.tsv, both images, scripts, FNFUZZ_* env)
#   fnfuzz_chunk.sh chunk DIR K FIRST COUNT FZ STOCK REBUILT TRIALS   run chunk K: refuse (marker rc 99) if the state manifest differs from manifest.start, else run fnfuzz, then write
#                                                                 DIR/out.cK.done = `chunk K rc N host H start S end E bytes B md5 M result yes|no manifest same|CHANGED`
#   fnfuzz_chunk.sh end DIR FZ STOCK REBUILT TRIALS              write DIR/manifest.end and print `same` or `CHANGED` (compared with manifest.start)
# DIR holds ledger.tsv (copied there by the caller) and fnfuzz_manifest.sh. The chunk's pid is in DIR/out.cK.pid (the caller polls it to tell a running chunk from a dead one).
sumof() { if command -v md5sum >/dev/null 2>&1; then md5sum "$1" | awk '{print $1}'; else md5 -q "$1"; fi; }
mode=$1
case "$mode" in
start)
  DIR=$2; FZ=$3; ST=$4; RB=$5; TR=$6; cd "$DIR" || exit 2
  sh ./fnfuzz_manifest.sh write manifest.start "$FZ" ledger.tsv "$ST" "$RB" "$TR" ;;
end)
  DIR=$2; FZ=$3; ST=$4; RB=$5; TR=$6; cd "$DIR" || exit 2
  sh ./fnfuzz_manifest.sh write manifest.end "$FZ" ledger.tsv "$ST" "$RB" "$TR"
  if sh ./fnfuzz_manifest.sh cmp manifest.start manifest.end > manifest.diff 2>&1; then rm -f manifest.diff; echo same; else echo CHANGED; fi ;;
chunk)
  DIR=$2; K=$3; FIRST=$4; CNT=$5; FZ=$6; ST=$7; RB=$8; TR=$9; cd "$DIR" || exit 2
  rm -f out.c$K.done out.c$K.full out.c$K.pid
  echo $$ > out.c$K.pid
  s=`date +%s`; mf=same
  sh ./fnfuzz_manifest.sh write manifest.now.$K "$FZ" ledger.tsv "$ST" "$RB" "$TR"
  if ! sh ./fnfuzz_manifest.sh cmp manifest.start manifest.now.$K > manifest.diff.$K 2>&1; then
    mf=CHANGED; rc=99; : > out.c$K.full
  else
    rm -f manifest.diff.$K
    "$FZ" ledger.tsv "$ST" "$RB" "$TR" "@$FIRST,$CNT" > out.c$K.full 2>&1 < /dev/null; rc=$?
  fi
  rm -f manifest.now.$K
  e=`date +%s`; res=no; tail -1 out.c$K.full | grep '^RESULT: ' > /dev/null && res=yes
  echo "chunk $K rc $rc host `uname -n` start $s end $e bytes `wc -c < out.c$K.full | tr -d ' '` md5 `sumof out.c$K.full` result $res manifest $mf" > out.c$K.done.tmp
  mv out.c$K.done.tmp out.c$K.done ;;
*) echo "usage: $0 start|chunk|end ..." >&2; exit 2 ;;
esac
