# gen2.py NAMESFILE OUT COMMON [OVERRIDES.py]: like gen.py but takes the row names from a file and types arguments by name:
#   compiler -> COMPILER, program -> PROGRAM, *block* -> BLOCK, index/count/mask/kind/flag/slot/cycle/level/reg/size/... -> int, anything else -> OBJ
import re,glob,sys,os
D=os.path.expanduser('~/atiradeonx1000-kext-source/Userspace/ATIRadeonX1000GLDriver/ppc/')
names=[l.strip() for l in open(sys.argv[1]) if l.strip()]
sig={}
for p in sorted(glob.glob(D+'part_*.c')):
    L=open(p).read().split('\n')
    for i,l in enumerate(L):
        m=re.match(r'^/\* (\S+) @ 0x',l)
        if m and m.group(1) in names:
            h=L[i+1]; mm=re.match(r'^\w[\w \*]*? \**(\w+)\((.*)\)\s*$',h)
            sig[m.group(1)]=[a.strip() for a in mm.group(2).split(',')] if mm and mm.group(2).strip() else []
OVR={}
if len(sys.argv)>4: exec(open(sys.argv[4]).read())
INT=re.compile(r'index|count|mask|kind|flag|slot|cycle|level|reg|size|stale|used|offset|num|width|opcode|id$|type',re.I)
def kind(a):
    if a=='compiler' or a.endswith('Compiler'): return 'ptr COMPILER'
    if a=='program' or a.endswith('Program'): return 'ptr PROGRAM'
    if re.search('block',a,re.I): return 'ptr BLOCK'
    if INT.search(a): return 'int 0 8'
    return 'ptr OBJ'
out=open(sys.argv[2],'w'); out.write(open(sys.argv[3]).read())
for n in names:
    if n not in sig: print('no sig',n); continue
    out.write('\nfunc %s\n'%n)
    for i,a in enumerate(sig[n]):
        out.write('  arg %d %s\n'%(i,OVR.get(n,{}).get(i,kind(a))))
print(len(names),'funcs')
