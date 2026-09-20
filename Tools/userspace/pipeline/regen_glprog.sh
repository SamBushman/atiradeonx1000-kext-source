#!/bin/bash
SCR=/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad
G=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/gs
AH=~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects && rm -rf glprog-sigs glprog-un && cp -r glprog-proj glprog-sigs
$AH $PWD/glprog-sigs GLProgProject -process libGLProgrammability.dylib -noanalysis -scriptPath $G -postScript NopMillicode.java 97c1a1fc 97c1a26f 2>&1 | grep NOPMILLI
$AH $PWD/glprog-sigs GLProgProject -process libGLProgrammability.dylib -noanalysis -scriptPath $G -postScript CommitLiveSigs.java $SCR/arch_gp/n_glprog 2>&1 | grep COMMITLIVE
$AH $PWD/glprog-sigs GLProgProject -process libGLProgrammability.dylib -noanalysis -scriptPath $G -postScript CommitLiveSigs.java EXTEND 2>&1 | grep COMMITLIVE
cp -r glprog-sigs glprog-un
timeout 590 ~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless $PWD/glprog-un GLProgProject -process libGLProgrammability.dylib -noanalysis -scriptPath $G -postScript RemoveExtras.java $SCR/arch_gp/n_glprog 2>&1 | grep REMOVEEXTRAS
for s in UniqueNames ThisToStdcall CopySigToStubs; do timeout 590 ~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless $PWD/glprog-un GLProgProject -process libGLProgrammability.dylib -noanalysis -scriptPath $G -postScript $s.java 2>&1 | grep "UNIQUENAMES\|THISTO\|COPYSIG" | cut -c1-200; done
rm -rf $SCR/nl_gp_un; timeout 590 ~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless $PWD/glprog-un GLProgProject -process libGLProgrammability.dylib -noanalysis -readOnly -scriptPath $G -postScript DecompAll.java $SCR/nl_gp_un 2>&1 | grep DECOMPALL
cd $SCR; rm -rf n_gp4 corp_gp4; python3 mk_n.py arch_gp/n_glprog nl_gp_un n_gp4
python3 - <<'PY'
SCR='/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad'
names={l.split('\t')[0]:l.rstrip('\n').split('\t')[2] for l in open(SCR+'/n_gp4/INDEX.tsv')}
out=[]
for l in open(SCR+'/arch_gp/n_glprog/RANGES.tsv'):
    f=l.rstrip('\n').split('\t')
    if f[0] in names and len(f)>2: f[1]=names[f[0]]
    out.append('\t'.join(f))
open(SCR+'/n_gp4/RANGES.tsv','w').write('\n'.join(out)+'\n')
PY
cd ~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source && python3 Tools/userspace/build_corpus.py ../tiger-hd-pull/libGLProgrammability.dylib ppc $SCR/n_gp4 $SCR/corp_gp4 2>&1 | tail -2; python3 Tools/userspace/detect_dropped_args.py $SCR/corp_gp4 | cut -c1-400
