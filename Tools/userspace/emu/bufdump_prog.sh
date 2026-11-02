#!/bin/sh
# bufdump_prog.sh TAG IMAGE|stock PROG   (ON the G5; PROG relative to ~/rung3/src_575ad528/Tests)
# Also dumps every sel=10 kernel allocation ([start,end) returned by structureI_structureO = a CPU-mapped GPU buffer: texture backing / program memory) as kbuf_TAG_<n>.bin.
# Dumps every IOKit memType=1 mapping (the DMA/data buffers: texture data, vertex data) at the first glReadPixels as raw files OUT/buf_TAG_<n>.bin, stock or via gld_redirect with the rebuilt IMAGE.
# The ring (ringdump_prog.sh) only holds commands; when two rings are identical but the pixels differ, compare these with cmp / bufcmp.py.
TAG=$1; IMG=$2; PROG=$3
# ZEROCTX=1: zero ctx+0x1d4 (GLD_currentVertexArray) right after the 11160-byte context malloc. The stock leaves it uninitialised and gets 0 from the heap's history; under gld_redirect the rebuilt image gets a dirty block
# (0xa1b1c1d3 pattern) and gld_updateCurrentVertexArray then closes the first packet early. Set it for BOTH sides to compare the real differences.
# AFTER=1: dump after glReadPixels RETURNS (the readback path itself may be what differs, the stream before it being identical)
AFT=; [ -n "$AFTER" ] && AFT=finish
ZPRE=; [ -n "$ZEROCTX" ] && ZPRE='break malloc if $r3 == 11160\ncontinue\nfinish\nset *(int*)($r3+0x1d4) = 0\ndelete'
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_b$TAG.tsv; rm -f $W/io_b$TAG.tsv $W/buf_${TAG}_*.bin $W/kbuf_${TAG}_*.bin
printf "$ZPRE\n" > $W/zpre_$TAG.gdb
cat > $W/bd_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
source $W/zpre_$TAG.gdb
break glReadPixels
continue
$AFT
shell grep -a memType=1 $W/io_b$TAG.tsv | sed 's|.*addr=\(0x[0-9a-f]*\).*size=\(0x[0-9a-f]*\).*|dump binary memory $W/buf_${TAG}_\1.bin \1 (\1+\2)|' > $W/dumpcmds_$TAG.gdb
source $W/dumpcmds_$TAG.gdb
shell grep -a 'structureI_structureO' $W/io_b$TAG.tsv | grep -a 'sel=10' | awk -F'\t' '{ s=substr(\$NF,1,8); e=substr(\$NF,9,8); if (length(s)==8 && length(e)==8) printf "dump binary memory $W/kbuf_${TAG}_%d.bin 0x%s 0x%s\n", NR, s, e }' > $W/dumpk_$TAG.gdb
source $W/dumpk_$TAG.gdb
kill
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/bd_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/bd_$TAG.out
ls -l $W/buf_${TAG}_*.bin
