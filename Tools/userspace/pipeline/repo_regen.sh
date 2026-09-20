#!/bin/bash
# repo_regen.sh glprog|gld
SCR=/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad
K=$1
cd ~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source
P=Tools/userspace/pipeline
case $K in
 glprog) SL=../tiger-hd-pull/libGLProgrammability.dylib; UD=libGLProgrammability; LOOSE=0; N=$SCR/n_gp4; O=$SCR/o_gp4; PP=$SCR/p_gp4; SH=glprog; NAME=glprog;;
 gld) SL=/tmp/spec/slices/ATIRadeonX1000GLDriver.bundle.bin.ppc; UD=ATIRadeonX1000GLDriver; LOOSE=0; N=$SCR/n_gld5; O=$SCR/o_gld4; PP=$SCR/p_gld4; SH=gld; NAME=gld;;
esac
R=Userspace/$UD/ppc
echo "== $K main build"; python3 Tools/userspace/build_corpus.py $SL ppc $N $R 2>&1 | grep -E "functions,|failing|^\('"
echo "== verify"; LOOSE_NAMES=$LOOSE EXTRA=$R/extra_decls.h sh Tools/userspace/verify_corpus.sh $NAME $SL $N > /tmp/verify_$NAME.log 2>&1
cp /tmp/verify_$NAME/report.txt $R/verify_callees.txt; head -4 /tmp/verify_$NAME/report.txt | cut -c1-200
python3 Tools/userspace/unowned_blocks.py /tmp/verify_$NAME/stock.dis $N/RANGES.tsv $R/ledger.tsv $R/unowned_blocks.tsv
python3 Tools/userspace/coverage.py $SL $N/RANGES.tsv 5 > $R/coverage.txt 2>&1
echo "== orphans"; python3 Tools/userspace/build_corpus.py $SL ppc $O $R/unowned_code 2>&1 | grep -E "functions,|failing|^\('"
cp $N/RANGES.tsv /tmp/ranges_${SH}_ocomb.tsv
awk -F'\t' '{printf "0x%s\torph_%s\tfn\t%s-%s;\n",$1,$1,$1,$2}' $P/orph_$SH.tsv >> /tmp/ranges_${SH}_ocomb.tsv
LOOSE_NAMES=$LOOSE EXTRA=$R/unowned_code/extra_decls.h sh Tools/userspace/verify_corpus.sh ${NAME}orph $SL $O > /tmp/verify_${NAME}orph.log 2>&1
cat $R/ledger.tsv /tmp/verify_${NAME}orph/corp/ledger.tsv > /tmp/${NAME}_all_ledger.tsv
LOOSE_NAMES=$LOOSE LOWN=50 GAPN=0 python3 Tools/userspace/callee_compare_c.py /tmp/verify_${NAME}orph/stock.dis /tmp/verify_${NAME}orph/ours.dis /tmp/${NAME}_all_ledger.tsv /tmp/ranges_${SH}_ocomb.tsv > $R/unowned_code/verify_callees.txt
cp $P/orph_$SH.tsv $R/unowned_code/code_extents.tsv; cp $O/PADOWNERS.tsv $R/unowned_code/code_owners.tsv
grep "functions compared\|LOWCOUNT" $R/unowned_code/verify_callees.txt | cut -c1-200
echo "== pads"; python3 Tools/userspace/build_corpus.py $SL ppc $PP $R/landing_pads 2>&1 | grep -E "functions,|failing|^\('"
cp $N/RANGES.tsv /tmp/ranges_${SH}_comb.tsv
awk -F'\t' '{printf "0x%s\teh_pad_%s\tfn\t%s-%s;\n",$1,$1,$1,$2}' $P/pads_$SH.tsv >> /tmp/ranges_${SH}_comb.tsv
LOOSE_NAMES=$LOOSE EXTRA=$R/landing_pads/extra_decls.h sh Tools/userspace/verify_corpus.sh ${NAME}pads $SL $PP > /tmp/verify_${NAME}pads.log 2>&1
cat $R/ledger.tsv /tmp/verify_${NAME}pads/corp/ledger.tsv > /tmp/${NAME}_all_ledger.tsv
LOOSE_NAMES=$LOOSE LOWN=50 GAPN=0 python3 Tools/userspace/callee_compare_c.py /tmp/verify_${NAME}pads/stock.dis /tmp/verify_${NAME}pads/ours.dis /tmp/${NAME}_all_ledger.tsv /tmp/ranges_${SH}_comb.tsv > $R/landing_pads/verify_callees.txt
cp $P/pads_$SH.tsv $R/landing_pads/pad_extents.tsv; cp $PP/PADOWNERS.tsv $R/landing_pads/pad_owners.tsv
grep "functions compared\|LOWCOUNT" $R/landing_pads/verify_callees.txt | cut -c1-200
echo "== archive"; rm -rf $SCR/archx; mkdir -p $SCR/archx; cp -r $N $SCR/archx/n_$SH; cp -r $O $SCR/archx/o_$SH; cp -r $PP $SCR/archx/p_$SH
tar cJf $R/ghidra/decompile_dump.tar.xz -C $SCR/archx n_$SH o_$SH p_$SH
echo REPO_REGEN_DONE $K
