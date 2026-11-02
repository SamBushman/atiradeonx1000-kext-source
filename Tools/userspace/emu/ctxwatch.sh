#!/bin/sh
# ctxwatch.sh TAG IMAGE|stock PROG OFFSET_HEX [BREAKFN=glReadPixels]  (ON the G5) - hardware-watch ONE word of the GL driver context (ctx = the 11160-byte malloc of _gldCreateContext) from the moment the
# context is allocated until the first BREAKFN hit: old/new value + 8-frame backtrace at every write. ZEROCTX=1 as in bufdump_prog.sh. Output ring/cw_TAG.out
TAG=$1; IMG=$2; PROG=$3; OFF=$4; BF=${5:-glReadPixels}
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"; unset GLD_REDIRECT_FROM GLD_REDIRECT_TO
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_cw_$TAG.tsv
Z=; [ -n "$ZEROCTX" ] && Z='set *(int*)($r3+0x1d4) = 0'
cat > $W/cwx_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break malloc if \$r3 == 11160
continue
finish
set \$ctx = \$r3
$Z
set \$a = \$ctx + 0x$OFF
printf "WATCH %x old=%x\n", \$a, *(int*)\$a
delete
watch *(int*)\$a
commands
bt 8
continue
end
break $BF
continue
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/cwx_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/cw_$TAG.out
grep -c '^Old value\|(gdb) Old value' $W/cw_$TAG.out
