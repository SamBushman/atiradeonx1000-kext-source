#!/bin/sh
W=$HOME/rung3/final_eval/nov1/ring; H79="/Volumes/Test HD/claude_bugwf/h79"
export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib" IOKIT_RECORD_LOG=$W/io_src.tsv
cat > $W/src_stock.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break *0x10543f4 if \$r3 == 0xd83c0
continue
printf "SRC r2=%x r9=%x r10=%x r7=%x src=%x val=%x\n", \$r2, \$r9, \$r10, \$r7, \$r2+\$r9, *(int*)(\$r2+\$r9)
x/8xw \$r2+\$r9-16
kill
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/src_stock.gdb | gdb userspace/gl_feature_abgr_bgra_test 2>&1 | cat | grep -A4 "^SRC\|Breakpoint 2"
