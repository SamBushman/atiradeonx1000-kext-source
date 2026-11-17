import re,sys,glob,os
root=os.path.expanduser(sys.argv[1] if len(sys.argv)>1 else '~/atiradeonx1000-kext-source/Userspace/GLEngine/ppc')
def split_args(s):
    out=[];d=0;cur=''
    for ch in s:
        if ch in '([': d+=1
        if ch in ')]': d-=1
        if ch==',' and d==0: out.append(cur.strip());cur=''
        else: cur+=ch
    if cur.strip(): out.append(cur.strip())
    return out
files=sorted(glob.glob(root+'/part_*.c'))+sorted(glob.glob(root+'/hand/*.c'))
srcs={f:open(f).read() for f in files}
defs={}
# definition: line starting at col0 with type + name( ... ) followed by newline and '{' or K&R decls
for f,src in srcs.items():
    for m in re.finditer(r'^(?:[A-Za-z_][\w \*]*?[ \*])(_?\w+)\(([^)]*)\)\s*\n(?=\{|\s+\w)',src,re.M):
        name=m.group(1); a=m.group(2).strip()
        if name in('if','while','for','switch','return'): continue
        ps=[] if a in('','void') else split_args(a)
        defs[name]=ps
rows=[]
for f,src in srcs.items():
    for m in re.finditer(r'(?<![\w])(_\w+|FUN_\w+)\)?\s*\(',src):
        name=m.group(1)
        if name not in defs: continue
        # skip definition lines
        ls=src.rfind('\n',0,m.start())+1
        if m.start()==ls: continue
        i=m.end(); d=1; j=i
        while d and j<len(src):
            if src[j]=='(': d+=1
            elif src[j]==')': d-=1
            j+=1
        args=split_args(src[i:j-1])
        ps=defs[name]
        if len(args)<len(ps):
            fp=[p for p in ps if re.search(r'\b(double|float)\b',p)]
            rows.append((os.path.basename(f),src.count('\n',0,m.start())+1,name,len(args),len(ps),len(fp)))
for r in rows: print('%s:%d %s called %d declared %d fp %d'%r)
print(len(defs),'defs',len(rows),'rows',file=sys.stderr)
