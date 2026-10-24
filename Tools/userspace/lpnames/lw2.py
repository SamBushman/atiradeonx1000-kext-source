#!/usr/bin/env python3
"""lw2.py DIR FN : placeholder variables of FN with their webs; each web shows how the CURRENT text names it: PLAIN (the Ghidra name still there) or the alias(es) a previous row gave it"""
import sys,os,re
sys.path.insert(0,os.path.join(os.path.dirname(os.path.abspath(__file__)),'..'))
import find_webs as F
d,fn=sys.argv[1],sys.argv[2]
body,brace=F.load(d,fn)        # normalised (Ghidra) text; F.CURRENT = current text lines
cur=F.CURRENT
PH=re.compile(r'\b([a-z]{0,3}Var\d+|p+[A-Za-z]*Var\d+|p[A-Z]\w*Var?\d*|[a-z]?Stack_[0-9a-f]+|auStack_[0-9a-f]+|local_[0-9a-f]+|param_\d+|in_[a-z0-9]+|extraout_\w+|this_\d+|a[0-5](?:_\d+)?|unaff_\w+|[a-z]{1,3}Stack_[0-9a-f]+)\b')
names=[]
for l in body[brace+1:]:
    for m in PH.findall(l):
        if m not in names: names.append(m)
nodes,entry=F.build_cfg(body,brace)
IDENT=re.compile(r'[A-Za-z_]\w*')
for v in names:
    try: ws=F.webs(nodes,entry,v)[0]
    except (Exception, SystemExit) as e: print('== %s: %s'%(v,str(e)[:60])); continue
    print('== %s: %d webs'%(v,len(ws)))
    for i,w in enumerate(ws):
        ls=sorted(w)
        plain=0; alias={}
        for l in ls:
            if not re.search(r'\b%s\b'%re.escape(v),body[l]): continue
            if re.search(r'\b%s\b'%re.escape(v),cur[l]): plain+=1
            else:
                # alias = identifier in cur[l] not in body[l]
                b=set(IDENT.findall(body[l])); c=IDENT.findall(cur[l])
                for t in c:
                    if t not in b: alias[t]=alias.get(t,0)+1
        defs=[l for l in ls if re.search(r'\b%s\b\s*(=|\+=|-=|\|=|&=)[^=]'%re.escape(v),body[l])][:1]
        txt=body[defs[0]].strip()[:60] if defs else body[ls[0]].strip()[:60]
        st='PLAIN' if not alias else ('MIXED(%d plain)'%plain if plain else 'ALIAS')
        print('  w%d lines %d-%d %s %s: %s'%(i,ls[0],ls[-1],st,','.join(sorted(alias,key=lambda k:-alias[k])[:2]),txt))
