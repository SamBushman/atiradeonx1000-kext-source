import sys,collections,re,glob
# uniq.py SPEC [DIR] : make each new name unique inside its function: not an identifier already in the function's current text (applied earlier), and one name per original variable
D=sys.argv[2] if len(sys.argv)>2 else 'Userspace/ATIRadeonX1000GLDriver/ppc'
lines=[l.rstrip('\n').split('\t') for l in open(sys.argv[1]) if l.strip() and not l.startswith('#')]
H=re.compile(r'^/\* (\S+) @ 0x')
idents={}
want=set(c[0] for c in lines)
for f in sorted(glob.glob(D+'/part_*.c')):
    cur=None;buf=[]
    for l in open(f,errors='replace'):
        m=H.match(l)
        if m:
            if cur in want: idents[cur]=set(re.findall(r'[A-Za-z_]\w*',''.join(buf)))
            cur=m.group(1);buf=[];continue
        buf.append(l)
    if cur in want: idents[cur]=set(re.findall(r'[A-Za-z_]\w*',''.join(buf)))
final={}            # (fn,var,name) -> final
owner={}            # (fn,final) -> var
out=[]
for c in lines:
    key=(c[0],c[1],c[2])
    if key not in final:
        nm=c[2];k=1
        while (nm in idents.get(c[0],set())) or (owner.get((c[0],nm),c[1])!=c[1]):
            k+=1;nm=c[2]+str(k)
        final[key]=nm;owner[(c[0],nm)]=c[1]
    c[2]=final[key]
    out.append('\t'.join(c))
open(sys.argv[1],'w').write('\n'.join(out)+'\n')
