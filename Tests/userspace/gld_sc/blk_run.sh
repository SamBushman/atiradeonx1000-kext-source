# usage: sh blk_run.sh NAME(prefix e.g. blk1) TRIALS [filter]   (runs new image and control image)
cd ~/rung3/fnf_237
export FNFUZZ_PRECALL=Compiler__initStaticLocals FNFUZZ_STACKFILL=0 FNFUZZ_NANCANON=1 FNFUZZ_FLOATARGS=0 FNFUZZ_LISTUNINF=1 FNFUZZ_INTERPOSE=1 FNFUZZ_IMPORT_NARGS=gld_nargs.tsv FNFUZZ_VT=1 FNFUZZ_PROFILE=graph FNFUZZ_GRAPHSPEC=$1_spec.txt FNFUZZ_DATA=vt_4966.tsv FNFUZZ_REPAIR=1
S=/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver
for k in 4966 b62d; do
  I=`ls -d $HOME/rung3/gld_*$k*/gld_link/ATIRadeonX1000GLDriver_renamed | head -1`
  echo "== $k"; ../gleng_fz/fnfuzz_gs55 $1_$k.tsv $S $I ${2:-40} $3 2>&1 | egrep "^(DIFF|RUN|UNINF|fnfuzz|RESULT|anchor|dlopen)" | cut -c1-300
done
echo ALLDONE
