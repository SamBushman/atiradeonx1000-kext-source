#!/bin/bash
# ringdump.sh NAME|stock : dump memType 2 (8192 words) at glReadPixels, address taken from the same run's recorder log -> /tmp/emu/ring_NAME.out
N=$1
if [ "$N" = stock ]; then ENVR="export DYLD_INSERT_LIBRARIES=\$PWD/iokit_record.dylib"; else
ENVR="export DYLD_INSERT_LIBRARIES=\$PWD/iokit_record.dylib:\$PWD/gld_redirect.dylib GLD_REDIRECT_FROM=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle GLD_REDIRECT_TO='/Volumes/Test HD/claude_bugwf/gld_$N/out_$N'"; fi
cat > /tmp/emu/rd_$N.gdb <<EOG
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
shell grep -a memType=2 /tmp/io_rd.tsv | tail -1 | sed 's/.*addr=\(0x[0-9a-f]*\).*/set \$ring=\1/' > /tmp/setring.gdb
source /tmp/setring.gdb
printf "RING %x\n", \$ring
printf "=====M2\n"
x/8192xw \$ring
printf "=====M4\n"
kill
quit
EOG
scp -q /tmp/emu/rd_$N.gdb G5:/tmp/
ssh G5 "cd '/Volumes/Test HD/claude_bugwf/h79'; $ENVR; rm -f /tmp/io_rd.tsv; export IOKIT_RECORD_LOG=/tmp/io_rd.tsv; cat /tmp/rd_$N.gdb | gdb ./cgl_probe > /tmp/ring_$N.out 2>&1"; scp -q G5:/tmp/ring_$N.out /tmp/emu/ring_$N.out; grep -a 'RING' /tmp/emu/ring_$N.out
