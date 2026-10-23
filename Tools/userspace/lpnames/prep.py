#!/usr/bin/env python3
"""prep.py DIR FN VAR... : undo every existing row (local and use) of the Ghidra variables VAR of FN, so that web rows from emit_webs.py can replace them"""
import sys,glob,os,subprocess
d,fn=sys.argv[1],sys.argv[2]; vars_=sys.argv[3:]
rn=os.path.join(os.path.dirname(os.path.abspath(__file__)),'rn.py')
loc={};use={}
for t in sorted(glob.glob(os.path.join(d,'names*.tsv'))):
    for l in open(t,errors='surrogateescape'):
        c=l.rstrip('\n').split('\t')
        if len(c)>=6 and c[1]==fn and c[2] in vars_:
            if c[0]=='local': loc.setdefault(c[2],set()).add(c[3])
            elif c[0]=='use': use.setdefault(c[2],set()).add(c[3])
for v in vars_:
    for n in sorted(loc.get(v,())):
        r=subprocess.run([sys.executable,'-I',rn,d,'revert',fn,n],capture_output=True,text=True); print(v,'local',n,r.stdout.strip(),r.stderr.strip()[:100])
    if use.get(v):
        r=subprocess.run([sys.executable,'-I',rn,d,'revert-use',fn,v,','.join(sorted(use[v]))],capture_output=True,text=True); print(v,'use',sorted(use[v]),r.stdout.strip(),r.stderr.strip()[:100])
