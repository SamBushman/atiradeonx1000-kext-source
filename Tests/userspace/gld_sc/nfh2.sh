#!/bin/sh
# nfh2.sh SPEC LEDGER NAME S|R TRIAL SECS [IMGID] : gdb ONE-mode run of one trial (no handlers, no alarm), SIGINT after SECS, show pc/lr/regs/backtrace/code at the stop. Binary fnfuzz_gs61, image dir by IMGID (default 4966).
cd ~/rung3/fnf_237
K=${7:-4966}
export FNFUZZ_PRECALL=Compiler__initStaticLocals FNFUZZ_GRAPHSPEC=$1 FNFUZZ_DATA=vt_4966.tsv FNFUZZ_STACKFILL=0 FNFUZZ_NANCANON=1 FNFUZZ_FLOATARGS=0 FNFUZZ_INTERPOSE=1 FNFUZZ_IMPORT_NARGS=gld_nargs.tsv FNFUZZ_VT=1 FNFUZZ_PROFILE=graph FNFUZZ_ONE=$4:$5
I=`ls -d $HOME/rung3/gld_*$K*/gld_link/ATIRadeonX1000GLDriver_renamed | head -1`
printf "run\nbt 12\ninfo registers pc lr ctr r1 r3 r4 r5 r30 r31\nx/10i \$pc-24\nquit\n" | gdb --args ../gleng_fz/fnfuzz_gs61 $2 /Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver $I 20 $3 > nfh2.out 2>&1 &
i=0; while [ $i -lt ${6:-8} ] && ps auxww | grep -q "[f]nfuzz_gs58 $2"; do sleep 1; i=`expr $i + 1`; done
P=`ps auxww | grep "[f]nfuzz_gs58 $2" | grep -v gdb | awk '{print $2}' | head -1`
kill -INT $P 2>/dev/null
sleep 3
killall -9 fnfuzz_gs61 2>/dev/null; killall gdb-powerpc-apple-darwin 2>/dev/null
egrep -a "^(Program|Reason|#|0x[0-9a-f]+ <|pc |lr |ctr |r[0-9]+ |stock |rebuilt )" nfh2.out | head -${HEADN:-40}
