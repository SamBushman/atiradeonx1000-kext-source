#!/usr/bin/env python3
"""rn.py DIR ren FUNC OLDAPPLIED NEW [EVIDENCE]  - change the applied new name of a row (table + part file)
   rn.py DIR revert FUNC NEWAPPLIED            - undo a whole-function `local` row: restore the old name in the file, delete the row"""
import sys,re,glob,os
d=sys.argv[1]; cmd=sys.argv[2]; fn=sys.argv[3]
HDR=re.compile(r'^/\* (\S+) @ 0x')
def func_range(lines,name):
    s=None
    for i,l in enumerate(lines):
        m=HDR.match(l)
        if m:
            if s is not None: return s,i
            if m.group(1)==name: s=i
    return (s,len(lines)) if s is not None else None
def find_part():
    for f in sorted(glob.glob(os.path.join(d,'part_*.c'))):
        L=open(f,errors='surrogateescape').read().split('\n')
        r=func_range(L,fn)
        if r: return f,L,r
    sys.exit('function not found: '+fn)
def sub(L,r,a,b):
    rx=re.compile(r'\b%s\b'%re.escape(a)); n=0
    for i in range(r[0],r[1]):
        if rx.search(L[i]): L[i]=rx.sub(b,L[i]); n+=1
    return n
tabs=sorted(glob.glob(os.path.join(d,'names*.tsv')))
if cmd=='ren':
    old,new=sys.argv[4],sys.argv[5]; ev=sys.argv[6] if len(sys.argv)>6 else None
    hit=0
    for t in tabs:
        rows=open(t,errors='surrogateescape').read().split('\n'); ch=False
        for i,l in enumerate(rows):
            c=l.split('\t')
            if len(c)>=6 and c[0] in('local','use') and c[1]==fn and c[4-1]==old:
                c[3]=new
                if ev and c[0]=='local': c[5]=ev
                rows[i]='\t'.join(c); ch=True; hit+=1
        if ch: open(t,'w',errors='surrogateescape').write('\n'.join(rows))
    f,L,r=find_part(); n=sub(L,r,old,new)
    open(f,'w',errors='surrogateescape').write('\n'.join(L))
    print('rows',hit,'lines',n)
elif cmd=='revert':
    new=sys.argv[4]; hit=None
    for t in tabs:
        rows=open(t,errors='surrogateescape').read().split('\n'); keep=[]
        for l in rows:
            c=l.split('\t')
            if len(c)>=6 and c[0]=='local' and c[1]==fn and c[3]==new:
                hit=c[2]; continue
            keep.append(l)
        if hit and len(keep)!=len(rows): open(t,'w',errors='surrogateescape').write('\n'.join(keep)); break
    if not hit: sys.exit('no local row')
    f,L,r=find_part(); n=sub(L,r,new,hit)
    open(f,'w',errors='surrogateescape').write('\n'.join(L))
    print('restored',new,'->',hit,'lines',n)
if cmd=='revert-use':
    # rn.py DIR revert-use FUNC OLD NEW1,NEW2,...  : undo the `use` rows of OLD whose new names are in the list
    old=sys.argv[4]; news=sys.argv[5].split(',')
    n=0
    for t in tabs:
        rows=open(t,errors='surrogateescape').read().split('\n'); keep=[]
        for l in rows:
            c=l.split('\t')
            if len(c)>=8 and c[0]=='use' and c[1]==fn and c[2]==old and c[3] in news: n+=1; continue
            keep.append(l)
        if len(keep)!=len(rows): open(t,'w',errors='surrogateescape').write('\n'.join(keep))
    f,L,r=find_part()
    first=True
    out=[]
    for i,l in enumerate(L):
        if r[0]<=i<r[1]:
            m=None
            for nw in news:
                m=None if l.lstrip().startswith(('return','goto','break','continue')) else re.match(r'(\s+[\w ]+?[ *]+)%s;$'%re.escape(nw),l)
                if m: break
            if m:
                if first: out.append('%s%s;'%(m.group(1),old)); first=False
                continue
            for nw in news: l=re.sub(r'\b%s\b'%re.escape(nw),old,l)
        out.append(l)
    open(f,'w',errors='surrogateescape').write('\n'.join(out))
    print('rows removed',n)
