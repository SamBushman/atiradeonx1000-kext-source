import re,subprocess,sys,glob,json
D='Userspace/ATIRadeonX1000GLDriver/ppc/'
H=re.compile(r'^/\* (\S+) @ (0x[0-9a-f]+) \(',re.M)
def amap(rev):
    m={}
    for i in range(68):
        p=f'{D}part_{i:03d}.c'
        t=subprocess.run(['git','show',f'{rev}:{p}'],capture_output=True,text=True).stdout
        for n,a in H.findall(t): m[a]=n
    return m
base,ours,theirs=amap(sys.argv[1]),amap('HEAD'),amap(sys.argv[2])
o={base[a]:ours[a] for a in base if a in ours and ours[a]!=base[a]}
t={base[a]:theirs[a] for a in base if a in theirs and theirs[a]!=base[a]}
both=[k for k in o if k in t and o[k]!=t[k]]
print(len(o),len(t),'both-differ',both,file=sys.stderr)
json.dump({'ours':o,'theirs':t},open(sys.argv[3],'w'))
