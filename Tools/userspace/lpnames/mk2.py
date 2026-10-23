#!/usr/bin/env python3
"""mk2.py SPEC OUT.tsv DIR : like mk.py but `local` rows whose function already has a row for that variable (same Ghidra old, or old == applied new) are applied
as a rename of the existing row (rn.py ren) instead of a duplicate; `use` rows are kept."""
import sys,glob,os,subprocess
spec,out,d=sys.argv[1:4]
rn=os.path.join(os.path.dirname(os.path.abspath(__file__)),'rn.py')
tabs=[t for t in sorted(glob.glob(os.path.join(d,'names*.tsv'))) if os.path.abspath(t)!=os.path.abspath(out)]
ex=[]
for t in tabs:
    for l in open(t,errors='surrogateescape'):
        c=l.rstrip('\n').split('\t')
        if len(c)>=6 and c[0] in('local','use'): ex.append((t,c))
rows=[];ren=[]
for l in open(spec):
    l=l.rstrip('\n')
    if not l.strip() or l.startswith('#'): continue
    p=[x.strip() for x in l.split(' | ')]
    q=[]
    for x in p:
        if x.startswith('| '): q+=['',x[2:].strip()]
        else: q.append(x)
    p=q
    if len(p)<6: sys.exit('bad row: '+l)
    if p[0]=='local':
        func,old,new,ev=p[1],p[2],p[3],p[5]
        hit=[c for t,c in ex if c[0]=='local' and c[1]==func and (c[2]==old or c[3]==old)]
        if hit:
            cur=hit[0][3]
            if cur!=new: ren.append((func,cur,new,ev))
            continue
        # an existing use-row split of the same variable cannot be mixed with a local row
        if any(c[0]=='use' and c[1]==func and c[2]==old for t,c in ex): print('NOTE: use rows exist for',func,old,file=sys.stderr)
    rows.append('\t'.join(p))
open(out,'w').write('\n'.join(rows)+('\n' if rows else ''))
for func,cur,new,ev in ren:
    r=subprocess.run([sys.executable,'-I',rn,d,'ren',func,cur,new,ev],capture_output=True,text=True)
    print('ren',func,cur,'->',new,r.stdout.strip(),r.stderr.strip())
