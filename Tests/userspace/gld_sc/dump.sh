#!/bin/sh
# dump.sh SPECPREFIX ROW TRIALS OUTPREFIX [IMG=4966] : run one row with the whole stock/rebuilt arena of the first differing trial dumped (FNFUZZ_DUMPARENA), guard on. Binary gs70.
cd ~/rung3/fnf_237
export FNFUZZ_PRECALL=Compiler__initStaticLocals FNFUZZ_STACKFILL=0 FNFUZZ_NANCANON=1 FNFUZZ_FLOATARGS=0 FNFUZZ_LISTUNINF=1 FNFUZZ_INTERPOSE=1 FNFUZZ_IMPORT_NARGS=gld_nargs.tsv FNFUZZ_VT=1 FNFUZZ_PROFILE=graph FNFUZZ_GRAPHSPEC=$1_spec.txt FNFUZZ_DATA=vt_4966.tsv FNFUZZ_REPAIR=1 FNFUZZ_VERBOSE=1 FNFUZZ_DUMPARENA=$4
S=/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver
K=${5:-4966}
I=`ls -d $HOME/rung3/gld_*$K*/gld_link/ATIRadeonX1000GLDriver_renamed | head -1`
../gleng_fz/fnfuzz_gs80 $1_$K.tsv $S $I $3 $2 > $4.out 2>&1
egrep -a "^(DIFF|RUN|UNINF|fnfuzz|arena)" $4.out | cut -c1-400
