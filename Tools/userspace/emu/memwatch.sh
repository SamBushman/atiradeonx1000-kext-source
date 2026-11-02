#!/bin/sh
# memwatch.sh TAG IMAGE|stock PROG ADDR [BREAKFN=glTexImage2D]  (ON the G5) - hardware-watch one heap/static word from the first BREAKFN call to the first glReadPixels, printing old/new value and
# a 8-frame backtrace at every write. Heap addresses repeat from run to run for the same program/driver, so take ADDR from a breakpoint run (see src_stock.sh pattern). Output: ring/mw_TAG.out
TAG=$1; IMG=$2; PROG=$3; ADDR=$4; BF=${5:-glTexImage2D}
# PRE (env) = gdb lines that run before the watch is armed; default: stop at BREAKFN. For an IOKit-mapped buffer: PRE="break IOConnectMapMemory if \$r4 == 1\nignore 2 1\ncontinue\nfinish\ndelete 2"
[ -n "$PRE" ] || PRE="break $BF\ncontinue\ndelete 2"
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_mw_$TAG.tsv; rm -f $W/io_mw_$TAG.tsv
printf "$PRE\n" > $W/pre_$TAG.gdb
cat > $W/mw_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
source $W/pre_$TAG.gdb
watch *(int*)$ADDR
commands
bt 8
continue
end
break glReadPixels
continue
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/mw_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/mw_$TAG.out
grep -c "^Old value" $W/mw_$TAG.out
