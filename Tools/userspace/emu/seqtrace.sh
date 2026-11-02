#!/bin/sh
# seqtrace.sh TAG IMAGE|stock PROG FUNCLIST.tsv STOPSPEC NSTOP  (ON the G5) - log "H name r3..r6" at every entry of the functions in FUNCLIST.tsv (hex stock offset <TAB> name; rebuilt: by symbol,
# names the image lacks are skipped) until the NSTOP-th entry of STOPSPEC (stock `*0x1008000+off`, rebuilt `*symbol`). Output ring/sq_TAG.out. Compare with seqcmp.py.
TAG=$1; IMG=$2; PROG=$3; LST=$4; STOP=$5; NSTOP=$6
# VAL (env, optional) = a gdb expression (e.g. '*(int*)0x3540a4') printed as v=%x at every entry; it must be readable at every hit (an unmapped address aborts the breakpoint commands)
VAL=${VAL:-0}
W=$HOME/rung3/final_eval/nov1/ring; mkdir -p $W
H79="/Volumes/Test HD/claude_bugwf/h79"
if [ "$IMG" = stock ]; then export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib"
else export DYLD_INSERT_LIBRARIES="$H79/iokit_record.dylib:$H79/gld_redirect.dylib" GLD_REDIRECT_FROM=ATIRadeonX1000GLDriver GLD_REDIRECT_TO="$IMG"
     nm -arch ppc "$IMG" | awk '{print $3}' | sed 's/^_//' | sort -u > $W/syms_$TAG.txt; fi
export IOKIT_RECORD_LOG=$W/io_sq_$TAG.tsv; rm -f $W/io_sq_$TAG.tsv
{
echo "break NSLinkModule"; echo run; echo finish; echo continue; echo finish; echo continue; echo finish; echo "delete 1"
[ -n "$PRE" ] && printf "$PRE\n"      # PRE (env) = gdb lines run first (e.g. stop at the 5th entry of some function and `delete` it before the function breakpoints are defined)
SN=2; [ -n "$PRE" ] && SN=${PRESN:-3}      # PRESN = number of the stop breakpoint after PRE (PRE bps count)
echo "break $STOP"; echo "ignore $SN `expr $NSTOP - 1`"
while read a n; do
    if [ "$IMG" = stock ]; then SPEC="*0x`printf %x $((0x1008000 + 0x$a))`"; else grep -qx "$n" $W/syms_$TAG.txt || continue; SPEC="*$n"; fi
    echo "break $SPEC"; echo commands; echo silent
    echo "printf \"H $n r3=%x r4=%x r5=%x r6=%x v=%x\\n\", \$r3, \$r4, \$r5, \$r6, $VAL"; echo continue; echo end
done < $LST
echo continue; echo 'printf "STOPPED\n"'; echo kill; echo quit
} > $W/sq_$TAG.gdb
cd $HOME/rung3/src_575ad528/Tests && cat $W/sq_$TAG.gdb | gdb $PROG 2>&1 | cat > $W/sq_$TAG.out
grep -c "H " $W/sq_$TAG.out
