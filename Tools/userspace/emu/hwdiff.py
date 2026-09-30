#!/usr/bin/env python3
"""hwdiff.py FUN_x [FUN_y ...]: hit counts of the direct callees of each function, stock vs rebuilt, on the G5 (gdb breakpoints)"""
import sys,re,subprocess,os
DIS='/home/sam/Documents/ATI-X1900-Decomp/work-bugwf/link/gld_full.dis'
RB=os.environ.get('RBUILD','/Volumes/Test HD/claude_bugwf/gld_r6/out_r6')
H='/Volumes/Test HD/claude_bugwf/h79'
ranges={}
for l in open('/home/sam/Documents/ATI-X1900-Decomp/work-bugwf/dumps/ATIRadeonX1000GLDriver/p_gld/RANGES.tsv'):
    f=l.split('\t'); ranges[f[1]]=(int(f[0],16),f[3])
ins=[]
for l in open(DIS):
    p=l.rstrip('\n').split('\t')
    if len(p)>=3 and p[1]=='bl': ins.append((int(p[0],16),p[2].split(';')[0].strip()))
def callees(fn):
    a=int(fn.split('_')[1],16)
    # function extent from ledger size
    sz=None
    for l in open('/home/sam/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv'):
        f=l.split('\t')
        if f[2]==fn: sz=int(f[1])
    tg=set()
    for ad,t in ins:
        if a<=ad<a+sz and t.startswith('0x'): tg.add(int(t,16))
    return sorted(tg)
fns=sys.argv[1:]
allt=sorted(set(t for f in fns for t in callees(f))|set(int(f.split('_')[1],16) for f in fns))
pre="break NSLinkModule\nrun\nfinish\ncontinue\nfinish\ncontinue\nfinish\ndelete 1\n"
def script(stock):
    s=pre
    for t in allt: s+=("break *0x%x\n"%(0x1008000+t)) if stock else ("break FUN_%08x\n"%t)
    for i in range(len(allt)): s+="ignore %d 1000000\n"%(i+2)
    s+="continue\n"+"info breakpoints\nquit\n"
    return s
def run(stock):
    open('/tmp/hd_%d.txt'%stock,'w').write(script(stock)); subprocess.run(['scp','-q','/tmp/hd_%d.txt'%stock,'G5:/tmp/'])
    env="" if stock else "export DYLD_INSERT_LIBRARIES='%s/gld_redirect.dylib' GLD_REDIRECT_FROM=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle GLD_REDIRECT_TO='%s'; "%(H,RB)
    out=subprocess.run(['ssh','G5',"cd '%s'; %s cat /tmp/hd_%d.txt | gdb ./cgl_probe 2>&1"%(H,env,stock)],capture_output=True,text=True).stdout
    hits={}
    for m in re.finditer(r'^(\d+)\s+breakpoint.*?\n(?:.*\n)*?\s+breakpoint already hit (\d+) time',out,re.M): pass
    cur=None
    for l in out.split('\n'):
        m=re.match(r'^(\d+)\s+breakpoint\s+keep\s+y\s+0x[0-9a-f]+\s*(.*)',l)
        if m: cur=int(m.group(1)); hits[cur]=0; continue
        m=re.search(r'already hit (\d+) time',l)
        if m and cur is not None: hits[cur]=int(m.group(1))
    return hits
hs,hr=run(1),run(0)
for i,t in enumerate(allt):
    a,b=hs.get(i+2,0),hr.get(i+2,0)
    print('FUN_%08x stock %d rebuilt %d %s'%(t,a,b,'' if a==b else '<== DIFF'))
