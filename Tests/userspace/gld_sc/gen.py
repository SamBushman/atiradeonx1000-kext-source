import re,glob,sys,os
D=os.path.expanduser('~/atiradeonx1000-kext-source/Userspace/ATIRadeonX1000GLDriver/ppc/')
fam=re.compile(sys.argv[1]); names=[l.strip() for l in open(os.path.expanduser('~/g5logs/fnf_237/gs/uninf_obj.txt')) if fam.match(l.strip())]
sig={}
for p in sorted(glob.glob(D+'part_*.c')):
    L=open(p).read().split('\n')
    for i,l in enumerate(L):
        m=re.match(r'^/\* (\S+) @ 0x',l)
        if m and m.group(1) in names:
            h=L[i+1]; mm=re.match(r'^\w[\w \*]*? \**(\w+)\((.*)\)\s*$',h)
            sig[m.group(1)]=[a.strip() for a in mm.group(2).split(',')] if mm and mm.group(2).strip() else []
out=open(sys.argv[2],'w')
out.write(open(sys.argv[3]).read())
OVR={}
for n in names:
    if re.match(r'^(BreakBlock|ContinueBlock|IfFooterStatic|IfHeaderStatic)__ctor_',n): OVR[n]={1:'ptr BLOCK'}   # copy constructors: arg 1 is the SOURCE block (the corpus names it compiler)
OVR['PostLoopFooter__ctor_eb3c8']={1:'int 0 8',3:'int 0 1'}
for n in names:
    out.write('\nfunc %s\n'%n)
    for i,a in enumerate(sig.get(n,[])):
        if i in OVR.get(n,{}): out.write('  arg %d %s\n'%(i,OVR[n][i]))
        elif a=='compiler': out.write('  arg %d ptr COMPILER\n'%i)
        elif i==0: out.write('  arg 0 ptr BLOCK\n')
        else: out.write('  arg %d ptr BLOCK\n'%i)
print(len(names),'funcs',sum(1 for n in names if n not in sig),'without sig')
