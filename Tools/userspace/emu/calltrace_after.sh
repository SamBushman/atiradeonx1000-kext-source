#!/bin/sh
# calltrace_after.sh TAG IMAGE|stock PROG BREAKFN "name:hexoff name:hexoff ..."  (ON the G5) - from the first BREAKFN (default glReadPixels) hit until the program ends, log every ENTRY of the listed driver functions
# (stock: *0x1008000+off, rebuilt: *name) with the caller (lr). Output ring/ct_TAG.out; `grep '^CT '`. ZEROCTX=1 as in bufdump_prog.sh. Use it to see WHICH driver path emits commands/state that the other image does not.
TAG=$1; IMG=$2; PROG=$3; BF=${4:-glReadPixels}; FNS=$5
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_ct_$TAG.tsv; rm -f $W/io_ct_$TAG.tsv
ZPRE=; [ -n "$ZEROCTX" ] && ZPRE='break malloc if $r3 == 11160\ncontinue\nfinish\nset *(int*)($r3+0x1d4) = 0\ndelete'
{
printf 'break NSLinkModule\nrun\nfinish\ncontinue\nfinish\ncontinue\nfinish\ndelete 1\n'
[ -n "$ZPRE" ] && printf "$ZPRE\n"
printf 'break %s\ncontinue\ndelete\n' "$BF"
for f in $FNS; do
  n=${f%%:*}; o=${f#*:}
  if [ "$IMG" = stock ]; then a="*(0x1008000+0x$o)"; else a="*$n"; fi
  printf 'break %s\ncommands\nsilent\nprintf "CT %s lr=%%x r3=%%x r4=%%x\\n", $lr, $r3, $r4\ncontinue\nend\n' "$a" "$n"
done
printf 'continue\nquit\n'
} > $W/ct_$TAG.gdb
cd $HOME/rung3/src_575ad528/Tests && cat $W/ct_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/ct_$TAG.out
grep -c '^CT \|(gdb) CT ' $W/ct_$TAG.out
