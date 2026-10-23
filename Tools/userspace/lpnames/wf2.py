#!/usr/bin/env python3
"""wf2.py DIR SPEC OUT : apply a workflow-2 spec: `ren FN old new ev` renames an existing (HEAD) row's new name; `web VAR WEBS new tier ev` goes to emit_webs (function = the ren rows' FN or given with FN= first line)"""
import sys,subprocess,os,tempfile
d,spec,out=sys.argv[1:4]
S=os.path.dirname(os.path.abspath(__file__))
fn=None; webs=[]
for l in open(spec):
    c=l.rstrip('\n').split('\t')
    if c[0]=='ren':
        fn=c[1]
        r=subprocess.run([sys.executable,'-I',S+'/rn.py',d,'ren',c[1],c[2],c[3],c[4]],capture_output=True,text=True); print('ren',c[2],'->',c[3],r.stdout.strip(),r.stderr.strip()[:80])
    elif c[0]=='fn': fn=c[1]
    elif c[0]=='web': webs.append(c[1:])
tf=tempfile.NamedTemporaryFile('w',suffix='.tsv',delete=False); tf.write('\n'.join('\t'.join(w) for w in webs)+'\n'); tf.close()
r=subprocess.run([sys.executable,'-I','Tools/userspace/emit_webs.py',d,fn,tf.name],capture_output=True,text=True)
if r.returncode: print('EMIT FAILED',r.stderr[-300:]); sys.exit(1)
open(out,'a').write(r.stdout)
