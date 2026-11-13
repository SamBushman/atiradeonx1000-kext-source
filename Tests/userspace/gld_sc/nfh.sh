# nfh.sh SPEC LEDGER NAME TRIAL SECS : like nf.sh but for a spinning function: SIGINT the inferior after SECS and show where it is
cd ~/rung3/fnf_237
export FNFUZZ_PRECALL=Compiler__initStaticLocals FNFUZZ_GRAPHSPEC=$1 FNFUZZ_DATA=vt_4966.tsv FNFUZZ_STACKFILL=0 FNFUZZ_NANCANON=1 FNFUZZ_FLOATARGS=0 FNFUZZ_INTERPOSE=1 FNFUZZ_IMPORT_NARGS=gld_nargs.tsv FNFUZZ_VT=1 FNFUZZ_PROFILE=graph FNFUZZ_ONE=R:$4
printf "run\nbt 10\nx/6i \$pc-8\nquit\n" | gdb --args ../gleng_fz/fnfuzz_gs55 $2 /Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver $HOME/rung3/gld_49663019/gld_link/ATIRadeonX1000GLDriver_renamed 20 $3 > nfh.out 2>&1 &
i=0; while [ $i -lt ${5:-15} ] && ps auxww | grep -q "[f]nfuzz_gs55 $2"; do sleep 1; i=`expr $i + 1`; done
P=`ps auxww | grep "[f]nfuzz_gs55 $2" | grep -v gdb | awk '{print $2}' | head -1`
kill -INT $P 2>/dev/null
sleep 2
killall -9 fnfuzz_gs55 2>/dev/null; killall gdb-powerpc-apple-darwin 2>/dev/null
egrep -a "^(Program|Reason|#|0x[0-9a-f]+ <)" nfh.out | head -${HEADN:-20}
