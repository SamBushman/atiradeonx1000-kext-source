#!/bin/sh
# ringwatch.sh TAG IMAGE|stock PROG ADDR  (ON the G5) - hardware-watch one ring word (IOKit memType 2 maps at 0xd8000; word N = 0xd8000 + 4N) from the end of driver load to the first
# glReadPixels; prints every write with the old/new value and the backtrace. Output: ~/rung3/final_eval/nov1/ring/watch_TAG.out
TAG=$1; IMG=$2; PROG=$3; ADDR=$4
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_w_$TAG.tsv; rm -f $W/io_w_$TAG.tsv
cat > $W/w_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break glTexImage2D
continue
delete 2
watch *(int*)$ADDR
break glReadPixels
commands
bt 6
continue
end
continue
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/w_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/watch_$TAG.out
grep -c "Hardware watchpoint" $W/watch_$TAG.out
