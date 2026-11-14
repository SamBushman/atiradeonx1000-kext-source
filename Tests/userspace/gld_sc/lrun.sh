# lrun.sh PREFIX TRIALS [NAMEFILTER]: blk_run.sh with the #273 logging: UDP breadcrumbs (FNFUZZ_BREADCRUMB) per row/trial/child, ksnap.sh sampler (2 s), fuzz output written straight to a file (never through a pipe), image order: new, control.
cd ~/rung3/fnf_237
export FNFUZZ_PRECALL=Compiler__initStaticLocals FNFUZZ_STACKFILL=0 FNFUZZ_NANCANON=1 FNFUZZ_FLOATARGS=0 FNFUZZ_LISTUNINF=1 FNFUZZ_INTERPOSE=1 FNFUZZ_IMPORT_NARGS=gld_nargs.tsv FNFUZZ_VT=1 FNFUZZ_PROFILE=graph FNFUZZ_GRAPHSPEC=$1_spec.txt FNFUZZ_DATA=vt_4966.tsv FNFUZZ_REPAIR=1 FNFUZZ_BREADCRUMB=192.168.5.213:9998 FNFUZZ_BCIMP=1
S=/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver
echo "LRUN START $1 trials=$2 $(date +%H:%M:%S) $(uptime | sed 's/,.*//')" | nc -u -w1 192.168.5.213 9998 2>/dev/null
sh ksnap.sh 2 > /dev/null 2>&1 &
KP=$!
for k in 4966 b62d; do
  I=`ls -d $HOME/rung3/gld_*$k*/gld_link/ATIRadeonX1000GLDriver_renamed | head -1`
  echo "== $k" >> $1_gs70.log
  ../gleng_fz/fnfuzz_gs74 $1_$k.tsv $S $I ${2:-40} $3 >> $1_gs70_$k.full 2>&1
  egrep -a "^(DIFF|RUN|UNINF|fnfuzz|RESULT|anchor|dlopen)" $1_gs70_$k.full | cut -c1-300 >> $1_gs70.log
done
kill $KP 2>/dev/null
echo "LRUN END $1 $(date +%H:%M:%S)" | nc -u -w1 192.168.5.213 9998 2>/dev/null
echo ALLDONE >> $1_gs70.log
