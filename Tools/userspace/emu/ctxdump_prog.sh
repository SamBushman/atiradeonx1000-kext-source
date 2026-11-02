#!/bin/sh
# ctxdump_prog.sh TAG IMAGE|stock PROG [BREAKFN=glReadPixels]  (ON the G5) - dump the whole GL driver context (the 11160-byte malloc of _gldCreateContext, 2790 words) at the first BREAKFN hit.
# ZEROCTX=1 zeroes ctx+0x1d4 first (see bufdump_prog.sh). Output ring/ctx_TAG.out ("x/2790xw"); diff two with ctxcmp.py (pointers normalised by offset-from-ctx / heap-vs-image class).
TAG=$1; IMG=$2; PROG=$3; BF=${4:-glReadPixels}
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"; unset GLD_REDIRECT_FROM GLD_REDIRECT_TO
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"; fi
export IOKIT_RECORD_LOG=$W/io_cx_$TAG.tsv
Z=; [ -n "$ZEROCTX" ] && Z='set *(int*)($r3+0x1d4) = 0'
cat > $W/cx_$TAG.gdb <<EOG
break NSLinkModule
run
finish
continue
finish
continue
finish
delete 1
break malloc if \$r3 == 11160
continue
finish
set \$ctx = \$r3
$Z
delete
break $BF
continue
printf "CTX %x\n", \$ctx
x/2790xw \$ctx
set \$tex = *(int*)(\$ctx+0x18c)
printf "TEX %x\n", \$tex
x/54xw \$tex
set \$res = *(int*)(\$tex+0x34)
printf "RES %x\n", \$res
x/64xw \$res
set \$fmt = *(int*)(\$tex+0x30)
printf "FMT %x\n", \$fmt
x/48xw \$fmt
set \$caps = *(int*)(\$ctx+0x14)
printf "CAPS %x\n", \$caps
x/80xw \$caps
quit
EOG
cd $HOME/rung3/src_575ad528/Tests && cat $W/cx_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/ctx_$TAG.out
grep -c '^0x' $W/ctx_$TAG.out
