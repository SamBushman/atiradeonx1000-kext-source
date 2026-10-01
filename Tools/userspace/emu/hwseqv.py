#!/usr/bin/env python3
"""hwseqv.py LISTFILE STOPFUN: like hwseq.py but logs r3..r8 at every entry; pointers (>=0x1000000) masked -> first divergence of (function, small-valued args)"""
import sys,re,subprocess,os
RB=os.environ.get('RBUILD'); H='/Volumes/Test HD/claude_bugwf/h79'
fns=[l.strip() for l in open(sys.argv[1]) if l.strip()]; stop=sys.argv[2]
pre="break NSLinkModule\nrun\nfinish\ncontinue\nfinish\ncontinue\nfinish\ndelete 1\n"
def script(stock):
    s=pre+(("break *0x%x\n"%(0x1008000+int(stop.split('_')[1],16))) if stock else "break *%s\n"%stop)
    for i,f in enumerate(fns):
        s+=("break *0x%x\n"%(0x1008000+int(f.split('_')[1],16))) if stock else "break *%s\n"%f
        s+='commands %d\nsilent\nprintf "H %d %%x %%x %%x %%x %%x %%x\\n", $r3,$r4,$r5,$r6,$r7,$r8\ncontinue\nend\n'%(i+3,i)
    return s+"continue\nquit\n"
def run(stock):
    open('/tmp/hv_%d.txt'%stock,'w').write(script(stock)); subprocess.run(['scp','-q','/tmp/hv_%d.txt'%stock,'G5:/tmp/'])
    env="" if stock else "export DYLD_INSERT_LIBRARIES='%s/gld_redirect.dylib' GLD_REDIRECT_FROM=/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle GLD_REDIRECT_TO='%s'; "%(H,RB)
    out=subprocess.run(['ssh','G5',"cd '%s'; %s cat /tmp/hv_%d.txt | gdb ./cgl_probe 2>&1"%(H,env,stock)],capture_output=True,text=True).stdout
    open('/tmp/emu/hv_out_%d.txt'%stock,'w').write(out)
    res=[]
    for m in re.finditer(r'^H (\d+) (\w+) (\w+) (\w+) (\w+) (\w+) (\w+)$',out,re.M):
        args=tuple('P' if int(v,16)>=0x1000000 else v for v in m.groups()[1:])
        res.append((fns[int(m.group(1))],args))
    return res
a=run(1); b=run(0)
open('/tmp/emu/hv_a.txt','w').write('\n'.join('%s %s'%x for x in a)); open('/tmp/emu/hv_b.txt','w').write('\n'.join('%s %s'%x for x in b))
print(len(a),len(b))
for i,(x,y) in enumerate(zip(a,b)):
    if x!=y: print('first divergence at',i,'stock',x,'rebuilt',y); print('ctx stock',a[max(0,i-4):i+3]); print('ctx rebuilt',b[max(0,i-4):i+3]); break
else: print('no divergence')
