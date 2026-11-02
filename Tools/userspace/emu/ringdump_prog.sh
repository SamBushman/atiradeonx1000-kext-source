#!/bin/sh
# ringdump_prog.sh TAG IMAGE|stock PROG   (ON the G5; PROG relative to ~/rung3/src_575ad528/Tests, e.g. userspace/gl_feature_abgr_bgra_test)
# Dumps the GPU command ring (IOKit memType 2, 8192 words) at the first glReadPixels, stock or through gld_redirect with the rebuilt IMAGE.
# Output: ~/rung3/final_eval/nov1/ring/ring_TAG.out (+ io_TAG.tsv, the IOKit call log). Diff two with ringcmp.py. Generalises ringdump.sh (cgl_probe only, /tmp).
TAG=$1; IMG=$2; PROG=$3
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_$TAG.tsv; rm -f $W/io_$TAG.tsv
cat > $W/rd_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break glReadPixels
continue
shell grep -a memType=2 $W/io_$TAG.tsv | tail -1 | sed 's/.*addr=\(0x[0-9a-f]*\).*/set \$ring=\1/' > $W/setring_$TAG.gdb
source $W/setring_$TAG.gdb
printf "RING %x\n", \$ring
printf "=====M2\n"
x/8192xw \$ring
printf "=====M4\n"
kill
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/rd_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/ring_$TAG.out
grep -c "^0x" $W/ring_$TAG.out
