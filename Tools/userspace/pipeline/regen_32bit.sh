#!/bin/sh
# regen_32bit.sh KEY SLICE PROGRAM USERDIR  - rebuild a corpus from a 32-bit PowerPC Ghidra import (issue #61).
#
# libGL, ATIRadeonX1000GA and ATIRadeonX1000VADriver were first imported as `PowerPC:BE:64:VLE-32addr`: every integer register became an 8-byte
# `undefined8`/`longlong` in the decompile, so the corpus returned and took 64-bit values (two registers each) where the stock code uses 32-bit ones
# (a linked GA returned 0 from _window_mode_to_ati_format because the value came back in r4). GLDriver and libGLProgrammability were always
# `PowerPC:BE:32:default`. This re-imports the slice with -processor PowerPC:BE:32:default into ghidra-projects/rest32-proj and redoes the corpus.
#   KEY       ga | va | libgl                (names the scratch dump dir n32_<key> and the archived n_<key>)
#   SLICE     thin ppc slice (Tools/userspace/pipeline/extract_slices.py)      PROGRAM  the name the slice imports under
#   USERDIR   Userspace/<Binary>            SCR   scratch directory (default: $TMPDIR-ish path below)
set -e
KEY=$1; SLICE=$2; PROG=$3; UD=$4
REPO=$(cd "$(dirname "$0")/../../.." && pwd)
SCR=${SCR:-/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad}
GH=${GHIDRA:-$HOME/ghidra_12.1.3_PUBLIC}
PROJ=${PROJDIR:-$HOME/Documents/ATI-X1900-Decomp/ghidra-projects}/rest32-proj
G=$REPO/Tools/userspace/gs
mkdir -p $PROJ; cd $REPO
if [ -z "$SKIP_GHIDRA" ]; then
  $GH/support/analyzeHeadless $PROJ Rest32Project -import $SLICE -processor PowerPC:BE:32:default -overwrite -scriptPath $G -postScript FindMoreFuncs.java > $SCR/imp32_$KEY.log 2>&1
  rm -rf $SCR/n32_$KEY; mkdir -p $SCR/n32_$KEY
  $GH/support/analyzeHeadless $PROJ Rest32Project -process $PROG -noanalysis -readOnly -scriptPath $G -postScript DecompAll.java $SCR/n32_$KEY > $SCR/n32_$KEY.log 2>&1
  $GH/support/analyzeHeadless $PROJ Rest32Project -process $PROG -noanalysis -readOnly -scriptPath $G -postScript DumpRanges.java $SCR/n32_$KEY/RANGES.tsv > /dev/null 2>&1
fi
D=$SCR/n32_$KEY; O=$UD/ppc
echo "== corpus"; python3 Tools/userspace/build_corpus.py $SLICE ppc $D $O 2>&1 | grep -E "functions,|failing|2nd pass"
echo "== callee check"; EXTRA=$O/extra_decls.h sh Tools/userspace/verify_corpus.sh v32_$KEY $SLICE $D > /tmp/verify_v32_$KEY.log 2>&1 || true
cp /tmp/verify_v32_$KEY/report.txt $O/verify_callees.txt; head -4 /tmp/verify_v32_$KEY/report.txt | cut -c1-200
python3 Tools/userspace/unowned_blocks.py /tmp/verify_v32_$KEY/stock.dis $D/RANGES.tsv $O/ledger.tsv $O/unowned_blocks.tsv
python3 Tools/userspace/coverage.py $SLICE $D/RANGES.tsv 5 > $O/coverage.txt 2>&1
echo "== raw blocks"
python3 Tools/userspace/raw_blocks.py /tmp/verify_v32_$KEY/stock.dis $D/RANGES.tsv $SCR/raw32_$KEY
python3 Tools/userspace/raw_emit.py $SLICE /tmp/verify_v32_$KEY/stock.dis $SCR/raw32_$KEY $O/raw
python3 Tools/userspace/text_complete.py $SLICE $D/RANGES.tsv $O/text_accounting.txt $O/raw/code_extents.tsv $O/raw/data_extents.tsv
echo "== data sections"
python3 Tools/userspace/data_sections.py $SLICE $O/data $O/ledger.tsv > /dev/null
echo "== archive dump"
rm -rf $SCR/arch32; mkdir -p $SCR/arch32; cp -r $D $SCR/arch32/n_$KEY; tar cJf $O/ghidra/decompile_dump.tar.xz -C $SCR/arch32 n_$KEY
echo DONE $KEY
