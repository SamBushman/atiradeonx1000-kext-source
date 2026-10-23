#!/usr/bin/env python3
"""chk.py DIR PART : compare each function's Ghidra-normalised text between HEAD and the working tree, ignoring declaration lines; print functions with differing statements"""
import sys,re,subprocess,os,glob,tempfile
d,part=sys.argv[1],sys.argv[2]
S=os.path.dirname(os.path.abspath(__file__))
tmp=tempfile.mkdtemp(dir=S)
subprocess.run('git archive HEAD %s | tar -x -C %s'%(d,tmp),shell=True,check=True)
H=re.compile(r'^/\* (\S+) @ 0x')
names=[H.match(l).group(1) for l in open(os.path.join(d,part),errors='replace') if H.match(l)]
DECL=re.compile(r'^  [\w ]+?[ *]+[A-Za-z_]\w*( ?\[\w+\])?;$')
def norm(dd,fn):
    r=subprocess.run([sys.executable,'-I',os.path.join(S,'orig.py'),dd,fn],capture_output=True,text=True,errors='replace').stdout.split('\n')
    return [re.sub(r'^\d+:','',l) for l in r if not DECL.match(re.sub(r'^\d+:','',l)) or re.match(r'^  return',re.sub(r'^\d+:','',l))]
bad=0
for fn in names:
    a=norm(os.path.join(tmp,d),fn); b=norm(d,fn)
    if a!=b:
        bad+=1; print('DIFF',fn)
print('functions differing:',bad)
