#!/bin/sh
# kregion_prog.sh TAG IMAGE|stock PROG [BREAKFN=glReadPixels]  (ON the G5) - at the first BREAKFN hit dump the CPU-visible page(s) of every `sel=10` kernel allocation (structureI_structureO out = start,end) plus the next page,
# as OUT/kreg_TAG_<n>.bin. The region holds the surface/texture descriptors AND the texel data (stock: descriptor at +0x10.., texel image at +0xd80). Use `od -A x -t x4`.
TAG=$1; IMG=$2; PROG=$3; BF=${4:-glReadPixels}
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"; unset GLD_REDIRECT_FROM GLD_REDIRECT_TO
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_kr_$TAG.tsv; rm -f $W/io_kr_$TAG.tsv $W/kreg_${TAG}_*.bin
cat > $W/kr_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break $BF
continue
shell grep -a 'sel=10' $W/io_kr_$TAG.tsv | awk -F'\t' '{ s=substr(\$NF,1,8); printf "dump binary memory $W/kreg_${TAG}_%d.bin 0x%s (0x%s+0x2000)\n", NR, s, s }' > $W/dumpkr_$TAG.gdb
source $W/dumpkr_$TAG.gdb
kill
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/kr_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/kr_$TAG.out
ls -l $W/kreg_${TAG}_*.bin 2>&1 | head
