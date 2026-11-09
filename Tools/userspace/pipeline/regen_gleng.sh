#!/bin/bash
# regen_gleng.sh - call-accurate Ghidra dump of the Tiger GLEngine (the 6th userspace corpus), Stage B2 of pipeline/README.md applied to a plain-C image.
#   Input : ghidra-projects/gleng-proj (GlengProject, program GLEngine.tiger.ppc = the thin ppc Mach-O imported as PowerPC:BE:32:default + FindMoreFuncs.java)
#           $SCR/n_gleng = the first plain DecompAll dump of that project (only used to pick the functions CommitLiveSigs commits)
#   Output: $SCR/nl_gleng (DecompAll dump with RANGES.tsv) - feed it to Tools/userspace/build_corpus.py
# Steps (each on a COPY of the project, the stock file is never touched):
#   NopMillicode 879c 87e7   the stfd f14..f31 register-save chain (entry 0x879c, ends with stw r0,8(r1)/blr); the decompiler models a bl into it as a call that
#                            clobbers r3..r10 (the restore side, 0x8b30.., is entered by tail jumps, not bl, so it is not listed)
#   CommitLiveSigs OLD, EXTEND   signatures from the machine code's register liveness
#   UniqueNames              GLEngine has many same-named C statics (_gleRTCBuildABranch, _gleRTCAddAChunk, ... one per source file): <name>_<addr>
#   CopySigToStubs           PIC stubs of in-image functions take the real function's signature
set -e
SCR=${SCR:-$HOME/g5logs/gleng-corpus}
G=${G:-$(cd "$(dirname "$0")/.." && pwd)/gs}
AH=${GHIDRA:-$HOME/ghidra_12.1.3_PUBLIC}/support/analyzeHeadless
PD=${PROJDIR:-$HOME/Documents/ATI-X1900-Decomp/ghidra-projects}
PROG=GLEngine.tiger.ppc
cd $PD && rm -rf gleng-sigs && cp -r gleng-proj gleng-sigs
run() { $AH $PD/gleng-sigs GlengProject -process $PROG -noanalysis -scriptPath $G -postScript "$@"; }
run NopMillicode.java 879c 87e7 2>&1 | grep NOPMILLI
run CommitLiveSigs.java $SCR/n_gleng > $SCR/cl_gleng.log 2>&1; grep COMMITLIVE $SCR/cl_gleng.log
run CommitLiveSigs.java EXTEND > $SCR/cl_gleng_ext.log 2>&1; grep COMMITLIVE $SCR/cl_gleng_ext.log
for s in UniqueNames CopySigToStubs; do run $s.java 2>&1 | grep "UNIQUENAMES\|COPYSIG" | cut -c1-200; done
rm -rf $SCR/nl_gleng
$AH $PD/gleng-sigs GlengProject -process $PROG -noanalysis -readOnly -scriptPath $G -postScript DecompAll.java $SCR/nl_gleng > $SCR/dl_gleng.log 2>&1
grep DECOMPALL $SCR/dl_gleng.log
$AH $PD/gleng-sigs GlengProject -process $PROG -noanalysis -readOnly -scriptPath $G -postScript DumpRanges.java $SCR/nl_gleng/RANGES.tsv > /dev/null 2>&1
wc -l $SCR/nl_gleng/RANGES.tsv
echo GLENG_REGEN_DONE
