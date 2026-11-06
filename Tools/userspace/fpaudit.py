#!/usr/bin/env python3
"""fpaudit.py REBUILT_OTOOL_TV.txt STOCK_OTOOL_TV.txt [N]   (issue #210)

Per-function count of double-precision FP instructions (fmul/fadd/fsub/fdiv/fmadd../frsp/fsqrt) in the rebuilt image vs the stock image, from `otool -tV` text of both
(stock: the ppc slice of the stock GLDriver; rebuilt: the _renamed image from build_gld_image.sh). Functions are matched through funcmap.py (new name -> stock address).
Darwin embedded jump tables are data words inside the function body; otool decodes the negative entries (0xffffXXXX) as opcode-63 FP instructions with frD=frA=f31, so any
instruction whose first two operands are both f31 is skipped (none of the driver's real FP code does that). Prints the functions whose double-FP count differs.
"""
import re,subprocess,sys,bisect,os
from collections import defaultdict
fm={}
for l in subprocess.check_output(['python3',os.path.join(os.path.dirname(os.path.abspath(__file__)),'funcmap.py'),os.path.join(os.path.dirname(os.path.abspath(__file__)),'..','..','Userspace','ATIRadeonX1000GLDriver','ppc')],text=True).split('\n'):
    if '\t' in l:
        n,o=l.split('\t'); m=re.match(r'(?:FUN_|LD_)?([0-9a-fA-F]{6,8})$',o)
        if m: fm[n]=int(m.group(1),16)
DBL={'fmul','fadd','fsub','fdiv','fmadd','fmsub','fnmadd','fnmsub','frsp','fsqrt'}
SGL={'fmuls','fadds','fsubs','fdivs','fmadds','fmsubs','fnmadds','fnmsubs','fsqrts'}
PAIRABLE={'fadd','fsub','fmul','fdiv'}
class Counter:
    """Counts DBL/SGL ops into table[key].  A pairable double op (fadd/fsub/fmul/fdiv fR,..) whose result is next consumed by `frsp fD,fR` is a single-precision operation spelled
    in two instructions (gcc 7 emits fsub+frsp for int->float, gcc 4 emitted fsubs): for float operands a double op rounded once to float is bit-identical to the single op (53 >= 2*24+2),
    so such a pair is not counted on either side."""
    def __init__(self,table): self.t=table; self.pend={}; self.key=None
    def feed(self,key,op,ops):
        if key!=self.key: self.key=key; self.pend={}
        r=ops[0] if ops else None
        if op=='frsp' and len(ops)>1 and self.pend.get(ops[1]) is not None:
            self.t[self.pend.pop(ops[1])][0]-=1; self.pend.pop(ops[0],None); return      # cancel the pairable op counted earlier, and do not count this frsp
        if r and r.startswith('f'):
            self.pend.pop(r,None)
        if op in DBL: self.t[key][0]+=1; 
        elif op in SGL: self.t[key][1]+=1
        if op in PAIRABLE and len(ops)>1: self.pend[ops[0]]=key
rb=defaultdict(lambda:[0,0]); cur=None; rbc=Counter(rb)
for l in open(sys.argv[1]):
    m=re.match(r'^([A-Za-z_][\w$.]*):',l)
    if m: cur=m.group(1); continue
    t=l.split('\t')
    if len(t)>1 and cur:
        op=t[1].strip()
        if len(t)>2 and t[2].startswith('f31,f31,'): continue
        rbc.feed(cur,op,t[2].strip().split(',') if len(t)>2 else [])
# Stock side: attribute each address to the nearest mapped function start at or below it (the corpus `@ 0xADDR (N bytes)` sizes are not reliable: glAccum_impl says 88 bytes
# but its body runs for ~16 KiB).
offs=sorted(set(fm.values())); st=defaultdict(lambda:[0,0])
def owner(a):
    i=bisect.bisect_right(offs,a)-1
    return offs[i] if i>=0 else None
stc=Counter(st)
for l in open(sys.argv[2]):
    t=l.split('\t')
    if len(t)>1 and re.match(r'^[0-9a-f]{8}$',t[0]):
        a=int(t[0],16); op=t[1].strip()
        if len(t)>2 and t[2].startswith('f31,f31,'): continue
        k=owner(a)
        if k is not None: stc.feed(k,op,t[2].strip().split(',') if len(t)>2 else [])
# The stock `otool -tV` dump only covers __text; the C++ shader-compiler functions (Ir*__fold, FudoPs__*, ...) live in __textcoal_nt, so disassemble that section of the
# stock image too (STOCK_IMAGE env, default <repo>/../tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin), otherwise they read as "stock has no FP code".
img=os.environ.get('STOCK_IMAGE') or os.path.join(os.path.dirname(os.path.abspath(__file__)),'..','..','..','tiger-hd-pull','ATIRadeonX1000GLDriver.bundle.bin')
if os.path.exists(img):
    sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
    import machoutil, capstone, struct
    mo=machoutil.load(img)
    md=capstone.Cs(capstone.CS_ARCH_PPC,capstone.CS_MODE_32|capstone.CS_MODE_BIG_ENDIAN)
    for sec in mo.secs:
        if sec['name']!='__textcoal_nt': continue
        data=mo.read(sec['addr'],sec['size'])
        for o in range(0,len(data)-3,4):
            a=sec['addr']+o
            for ins in md.disasm(data[o:o+4],a):
                if ins.op_str.replace(' ','').startswith('f31,f31,'): continue
                k=owner(a)
                if k is not None: stc.feed(k,ins.mnemonic,[x.strip() for x in ins.op_str.split(',')])
else: print('WARNING: stock image not found; __textcoal_nt functions not audited (set STOCK_IMAGE)')
rows=[]
for n,(d,s_) in rb.items():
    o=fm.get(n)
    if o is None: continue
    sd,ss=st.get(o,[0,0])
    if d!=sd: rows.append((d-sd,n,d,s_,sd,ss))
if os.environ.get('FPAUDIT_DUMP'):   # name <tab> rebuilt dbl <tab> stock dbl, for every mapped function (used to chase the callers of a retyped function)
    with open(os.environ['FPAUDIT_DUMP'],'w') as f:
        for n,(d,s_) in sorted(rb.items()):
            o=fm.get(n)
            if o is not None: f.write('%s\t%d\t%d\n'%(n,d,st.get(o,[0,0])[0]))
rows.sort(reverse=True)
print('functions with differing double-FP count:',len(rows),' extra(+) total',sum(r[0] for r in rows if r[0]>0),' fewer(-) total',sum(r[0] for r in rows if r[0]<0))
for r in rows[:int(sys.argv[3]) if len(sys.argv)>3 else 25]: print('%-40s %+d  rebuilt dbl=%d sgl=%d | stock dbl=%d sgl=%d'%(r[1],r[0],r[2],r[3],r[4],r[5]))
print('--- most negative:')
for r in rows[-8:]: print('%-40s %+d  rebuilt dbl=%d sgl=%d | stock dbl=%d sgl=%d'%(r[1],r[0],r[2],r[3],r[4],r[5]))
