import os,re,sys,glob
sys.path.insert(0,os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace'))
import fn_norm_diff as f, capstone
MD=capstone.Cs(capstone.CS_ARCH_PPC,capstone.CS_MODE_32|capstone.CS_MODE_BIG_ENDIAN); MD.skipdata=True
S=os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin')
D=os.path.expanduser('~/atiradeonx1000-kext-source/Userspace/ATIRadeonX1000GLDriver/ppc/')
hdr=re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/')
fns={}
for p in sorted(glob.glob(D+'part_*.c')):
    for ln in open(p):
        m=hdr.match(ln)
        if m: fns[m.group(1)]=(int(m.group(2),16),int(m.group(3)))
SRC=re.compile(r'^(stf|fcmp)')
def fprread(name):
    """FPR args (f1..f13) read before written in the stock callee's first 60 insns (straight-line scan)"""
    a,n=fns[name]; ins=list(MD.disasm(f.code(S,a,min(n,240)),a)); written=set(); rd=set()
    for x in ins:
        ops=[o.strip() for o in x.op_str.split(',')]
        fr=lambda o: re.match(r'^f(\d+)$',o) and int(o[1:])
        m=x.mnemonic
        if m.startswith('b') and m not in('bdnzl','bdnz') : 
            if m in ('blr','bctr','bctrl') or m.startswith('bl') : break
        for i,o in enumerate(ops):
            k=fr(o)
            if k is None: continue
            isdst = (i==0) and not SRC.match(m)
            if isdst: written.add(k)
            elif 1<=k<=13 and k not in written: rd.add(k)
    return rd
cache={}
cur=None; insns=[]; res=[]
def scan(insns,cur):
    for i,(a,mn,op) in enumerate(insns):
        if mn=='bl' and op in fns:
            win=insns[max(0,i-14):i]; defs=set()
            for (a2,m2,o2) in win:
                if m2 in('bl','blr','bctrl'): defs=set()
                mm=re.match(r'^f(\d+),',o2)
                if mm and 1<=int(mm.group(1))<=13 and not re.match(r'^(stf|fcmp)',m2): defs.add(int(mm.group(1)))
            if op not in cache: cache[op]=fprread(op)
            if defs and not (defs & cache[op]):
                res.append((cur,a,op,sorted(defs),sorted(cache[op])))
for ln in open(os.path.expanduser('~/g5logs/fnf_237/otool_b62d.txt')):
    ln=ln.rstrip('\n')
    m=re.match(r'^([A-Za-z_][\w$.]*):$',ln)
    if m:
        if cur: scan(insns,cur)
        cur=m.group(1); insns=[]; continue
    m=re.match(r'^([0-9a-f]{8})\s+(\S+)\s*(.*)$',ln)
    if m and cur: insns.append((m.group(1),m.group(2),m.group(3).strip()))
if cur: scan(insns,cur)
for r in res: print('%-44s %s bl %-40s caller FPR %s callee reads %s'%r)
print(len(res),'candidate sites')
