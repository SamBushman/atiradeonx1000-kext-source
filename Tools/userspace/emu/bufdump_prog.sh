#!/bin/sh
# bufdump_prog.sh TAG IMAGE|stock PROG   (ON the G5; PROG relative to ~/rung3/src_575ad528/Tests)
# Dumps every IOKit memType=1 mapping (the DMA/data buffers: texture data, vertex data) at the first glReadPixels as raw files OUT/buf_TAG_<n>.bin, stock or via gld_redirect with the rebuilt IMAGE.
# The ring (ringdump_prog.sh) only holds commands; when two rings are identical but the pixels differ, compare these with cmp / bufcmp.py.
TAG=$1; IMG=$2; PROG=$3
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_b$TAG.tsv; rm -f $W/io_b$TAG.tsv $W/buf_${TAG}_*.bin
cat > $W/bd_$TAG.gdb <<EOG
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
shell grep -a memType=1 $W/io_b$TAG.tsv | sed 's|.*addr=\(0x[0-9a-f]*\).*size=\(0x[0-9a-f]*\).*|dump binary memory $W/buf_${TAG}_\1.bin \1 (\1+\2)|' > $W/dumpcmds_$TAG.gdb
source $W/dumpcmds_$TAG.gdb
kill
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/bd_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/bd_$TAG.out
ls -l $W/buf_${TAG}_*.bin
