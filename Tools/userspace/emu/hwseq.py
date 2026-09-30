#!/usr/bin/env python3
"""hwseq.py LISTFILE STOPFUN: the ORDER of entries of the listed functions until the first entry of STOPFUN, stock vs rebuilt (gdb commands blocks)"""
import sys,re,subprocess,os
RB=os.environ.get('RBUILD','/Volumes/Test HD/claude_bugwf/gld_r6/out_r6'); H='/Volumes/Test HD/claude_bugwf/h79'
fns=[l.strip() for l in open(sys.argv[1]) if l.strip()]; stop=sys.argv[2]
pre="break NSLinkModule\nrun\nfinish\ncontinue\nfinish\ncontinue\nfinish\ndelete 1\n"
def script(stock):
    s=pre+(("break *0x%x\n"%(0x1008000+int(stop.split('_')[1],16))) if stock else "break *%s\n"%stop)
    for i,f in enumerate(fns):
        s+=("break *0x%x\n"%(0x1008000+int(f.split('_')[1],16))) if stock else "break *%s\n"%f
        s+="commands %d\nsilent\nprintf \"H %d\\n\"\ncontinue\nend\n"%(i+3,i)
    return s+"continue\nquit\n"
def run(stock):
    open('/tmp/hs_%d.txt'%stock,'w').write(script(stock)); subprocess.run(['scp','-q','/tmp/hs_%d.txt'%stock,'G5:/tmp/'])
    env="" if stock else "export DYLD_INSERT_LIBRARIES='%s/gld_redirect.dylib' GLD_REDIRECT_FROM=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle GLD_REDIRECT_TO='%s'; "%(H,RB)
    out=subprocess.run(['ssh','G5',"cd '%s'; %s cat /tmp/hs_%d.txt | gdb ./cgl_probe 2>&1"%(H,env,stock)],capture_output=True,text=True).stdout
    open('/tmp/emu/hs_out_%d.txt'%stock,'w').write(out)
    return [fns[int(m.group(1))] for m in re.finditer(r'^H (\d+)$',out,re.M)]
a=run(1); b=run(0)
print(len(a),len(b))
n=0
for i,(x,y) in enumerate(zip(a,b)):
    if x!=y:
        print('first divergence at event',i,'stock',x,'rebuilt',y); print('context stock',a[max(0,i-5):i+5]); print('context rebuilt',b[max(0,i-5):i+5]); break
else: print('no divergence in common prefix',min(len(a),len(b)))
open('/tmp/emu/hs_a.txt','w').write('\n'.join(a)); open('/tmp/emu/hs_b.txt','w').write('\n'.join(b))
