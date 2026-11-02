#!/bin/sh
# fndump.sh TAG IMAGE|stock PROG ENTRYSPEC [NHITS=2] [DUMP="x/90xw \$r3"]  (ON the G5) - break at a function ENTRY (stock: *0x1008000+off; rebuilt: *symbol), on each of the first NHITS hits
# print r3..r8 and DUMP, run to the function's return (`finish`) and DUMP again ($p = r3 at entry). Output: ring/fd_TAG.out. Driver loads at 0x1008000; rebuilt symbols are visible once the redirected image is linked.
TAG=$1; IMG=$2; PROG=$3; ENT=$4; N=${5:-2}; DUMP=${6:-'x/90xw $p'}; PEXPR=${7:-'$r3'}
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_fd_$TAG.tsv; rm -f $W/io_fd_$TAG.tsv
{
cat <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break $ENT
EOG
i=1; while [ $i -le $N ]; do
cat <<EOG
continue
printf "ENTRY hit $i r3=%x r4=%x r5=%x r6=%x\n", \$r3, \$r4, \$r5, \$r6
set \$p = $PEXPR
$DUMP
finish
printf "RETURN hit $i rv=%x\n", \$r3
$DUMP
EOG
i=`expr $i + 1`; done
echo kill; echo quit
} > $W/fd_$TAG.gdb
cd $HOME/rung3/src_575ad528/Tests && cat $W/fd_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/fd_$TAG.out
grep -c "^ENTRY" $W/fd_$TAG.out
