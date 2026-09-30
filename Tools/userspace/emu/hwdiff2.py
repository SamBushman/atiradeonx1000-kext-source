#!/usr/bin/env python3
"""hwdiff2.py LISTFILE STOPFUN: hit counts of every function in LISTFILE up to the first entry of STOPFUN, stock vs rebuilt (G5 gdb)"""
import sys,re,subprocess,os
RB=os.environ.get('RBUILD','/Volumes/Test HD/claude_bugwf/gld_r6/out_r6'); H='/Volumes/Test HD/claude_bugwf/h79'
fns=[l.strip() for l in open(sys.argv[1]) if l.strip()]; stop=sys.argv[2]
pre="break NSLinkModule\nrun\nfinish\ncontinue\nfinish\ncontinue\nfinish\ndelete 1\n"
def script(stock):
    s=pre+(("break *0x%x\n"%(0x1008000+int(stop.split('_')[1],16))) if stock else "break *%s\n"%stop)
    for f in fns: s+=("break *0x%x\n"%(0x1008000+int(f.split('_')[1],16))) if stock else "break *%s\n"%f
    for i in range(len(fns)): s+="ignore %d 1000000\n"%(i+3)
    return s+"continue\ninfo breakpoints\nquit\n"
def run(stock):
    open('/tmp/hd2_%d.txt'%stock,'w').write(script(stock)); subprocess.run(['scp','-q','/tmp/hd2_%d.txt'%stock,'G5:/tmp/'])
    env="" if stock else "export DYLD_INSERT_LIBRARIES='%s/gld_redirect.dylib' GLD_REDIRECT_FROM=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle GLD_REDIRECT_TO='%s'; "%(H,RB)
    out=subprocess.run(['ssh','G5',"cd '%s'; %s cat /tmp/hd2_%d.txt | gdb ./cgl_probe > /tmp/hd2_%d.out 2>&1; cat /tmp/hd2_%d.out"%(H,env,stock,stock,stock)],capture_output=True,text=True).stdout
    hits={};cur=None
    for l in out.split('\n'):
        m=re.match(r'^(\d+)\s+breakpoint\s+keep\s+y',l)
        if m: cur=int(m.group(1)); hits[cur]=0; continue
        m=re.search(r'already hit (\d+) time',l)
        if m and cur is not None: hits[cur]=int(m.group(1))
    return hits,out
hs,os_=run(1); hr,or_=run(0)
print('stop hits: stock',hs.get(2),'rebuilt',hr.get(2))
for i,f in enumerate(fns):
    a,b=hs.get(i+3,0),hr.get(i+3,0)
    print(f,'stock',a,'rebuilt',b,'' if a==b else '<==')
