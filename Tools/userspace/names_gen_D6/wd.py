#!/usr/bin/env python3
"""wd.py FUNCTION [VAR...] - compact web dump: one line per web (first definition line + a use sample)."""
import re,sys,os,glob,subprocess
fn=sys.argv[1]; D='/tmp/d6pristine/ppc'
vars_=sys.argv[2:]
if not vars_:
    P=re.compile(r'\b(param_[0-9]+|[a-zA-Z]{0,4}Var[0-9]+|local_[0-9a-f]+|[a-z]Stack_?[0-9a-f]+|fparam_[0-9]+|in_[A-Za-z0-9]+)\b')
    seen={}
    for pf in sorted(glob.glob(D+'/part_*.c')):
        on=False
        for l in open(pf).read().split('\n'):
            m=re.match(r'^/\* (\S+) @',l)
            if m: on=(m.group(1)==fn)
            elif on and not re.match(r'\s*(/\*|\*|//)',l):
                for x in P.findall(l): seen[x]=seen.get(x,0)+1
    vars_=[v for v,c in sorted(seen.items(), key=lambda x:-x[1])]
out=''
for v in vars_:
    r=subprocess.run(['python3','Tools/userspace/find_webs.py',D,fn,v],capture_output=True,text=True)
    out+=r.stdout+(('== %s: ADDRESS-TAKEN/UNPARSEABLE %s\n'%(v,(r.stderr.strip().split(chr(10))[-1])[:60])) if r.returncode else '')
cur=None
for l in out.split('\n'):
    m=re.match(r'== (\S+): (\d+) webs',l)
    if m: print(l); continue
    m=re.match(r'\s+web (\d+): lines (.*)',l)
    if m: wl=m.group(2); first=True; wn=m.group(1); continue
    m=re.match(r'\s+(\d+)\s+(.*)',l)
    if m and first:
        print('  w%s [%s] %s'%(wn,wl[:30],m.group(2).strip()[:110])); first=False
    elif l.strip().startswith('address taken') or 'address taken' in l: print(l)
