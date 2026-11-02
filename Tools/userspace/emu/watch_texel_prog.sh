#!/bin/sh
# tw2.sh TAG IMG|stock PROG BASE - after gld_ensureTextureBackingSized2 returns, hardware-watch BASE+0xd80
TAG=$1; IMG=$2; PROG=$3; BASE=$4
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"; unset GLD_REDIRECT_FROM GLD_REDIRECT_TO; A='*(0x1008000+0xacb0)'
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; A='*gld_ensureTextureBackingSized2'; fi
export IOKIT_RECORD_LOG=$W/io_tw2_$TAG.tsv; rm -f $W/io_tw2_$TAG.tsv
cat > $W/tw2_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break $A
continue
finish
set \$wa = $BASE + 0xd80
x/w \$wa
watch *(int*)\$wa
commands
silent
printf "WATCH pc=%x lr=%x val=%x\n", \$pc, \$lr, *(int*)\$wa
bt 5
continue
end
continue
EOG
cd $HOME/rung3/src_575ad528/Tests && (cat $W/tw2_$TAG.gdb; echo; sleep 50; echo quit) | gdb $PROG 2>&1 | cat > $W/tw2_$TAG.out
