#!/bin/sh
# one2.sh PREFIX ROWFILTER IMG TRIAL : #273 single-trial repro (Nov 13). Runs ONE trial of ONE row in a fresh process through the normal forked path (repair loop, then stock child, then rebuilt child), UDP breadcrumbs incl. every import call (FNFUZZ_BCIMP). IMG = 4966|b62d.
cd ~/rung3/fnf_237
export FNFUZZ_PRECALL=Compiler__initStaticLocals FNFUZZ_STACKFILL=0 FNFUZZ_NANCANON=1 FNFUZZ_FLOATARGS=0 FNFUZZ_LISTUNINF=1 FNFUZZ_INTERPOSE=1 FNFUZZ_IMPORT_NARGS=gld_nargs.tsv FNFUZZ_VT=1 FNFUZZ_PROFILE=graph FNFUZZ_GRAPHSPEC=$1_spec.txt FNFUZZ_DATA=vt_4966.tsv FNFUZZ_REPAIR=1 FNFUZZ_BREADCRUMB=192.168.5.213:9998 FNFUZZ_BCIMP=1 FNFUZZ_PCSAMPLE=10
export FNFUZZ_PREDUMP=${5:-pre1} FNFUZZ_RETDUMP=${5:-ret1} FNFUZZ_WATCHDUMP=1 FNFUZZ_RECDUMP=1 FNFUZZ_ONE=S:$4 FNFUZZ_ONERUN=1
S=/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver
I=`ls -d $HOME/rung3/gld_*$3*/gld_link/ATIRadeonX1000GLDriver_renamed | head -1`
echo "ONE START $1 $2 img=$3 trial=$4 $(date +%H:%M:%S) $(uptime | sed 's/,.*//')" | nc -u -w1 192.168.5.213 9998 2>/dev/null
sh ksnap.sh 2 > /dev/null 2>&1 &
KP=$!
../gleng_fz/fnfuzz_gs78 $1_$3.tsv $S $I 1 $2 > $1_oneb_$4.out 2>&1
kill $KP 2>/dev/null
echo "ONE END $1 $(date +%H:%M:%S)" | nc -u -w1 192.168.5.213 9998 2>/dev/null
echo ONEDONE >> $1_oneb_$4.out
