#!/usr/bin/env python3
"""stackarg_calls.py KEY SLICE DUMP_DIR - call sites that pass fewer arguments than the stock stores (Stage B3 step 19).

For every `bl` (decoded from the Mach-O slice, so two static functions with the same name are not confused) whose target has 9 or more parameters in the
dump, count the contiguous outgoing stack words the caller stores at 0x38(r1), 0x3c(r1)... before the call (higher offsets are the caller's own locals) and
compare 8 + that count with the argument counts of the calls to the callee in the caller's decompile. A call whose decompile passes fewer arguments has lost
argument words: `_glpWriteTextureOperand` printed `_glpWriteSourceOperand(..., 1)` without its stack argument (0), so the swizzle text came out wrong.
Prints one line per suspect site; the callers go to RedumpContaining.java. (A callee that reads fewer parameters than the stock passes, FUN_000f6d14, is harmless.)"""
import re,glob,struct,os,sys,collections
key,slice_,dump=sys.argv[1:4]
d=open(slice_,'rb').read()
nc=struct.unpack('>I',d[16:20])[0];p=28;secs=[]
for _ in range(nc):
    c,cs=struct.unpack('>II',d[p:p+8])
    if c==1:
        ns=struct.unpack('>I',d[p+48:p+52])[0];q=p+56
        for _ in range(ns):
            a,sz,off=struct.unpack('>3I',d[q+32:q+44]);secs.append((a,sz,off));q+=68
    p+=cs
def word(x):
    for sa,sz,off in secs:
        if sa<=x<sa+sz and off: return struct.unpack('>I',d[off+x-sa:off+x-sa+4])[0]
names={};nparams={}
for f in glob.glob(dump+'/0x*.txt'):
    with open(f,errors='replace') as fh: head=[fh.readline() for _ in range(3)]
    m=re.match(r'// Function: (\S+) @ ',head[0]); a=int(os.path.basename(f)[2:-4],16)
    if m: names[a]=m.group(1)
    m=re.search(r'// Signature: .*?\((.*)\)\s*$',head[1])
    if m: nparams[a]=len([x for x in m.group(1).split(',') if x.strip() and x.strip()!='void'])
fns={}
for l in open(dump+'/RANGES.tsv'):
    f=l.rstrip('\n').split('\t')
    if len(f)>3 and f[0].startswith('0x') and f[2]=='fn': fns[int(f[0],16)]=[tuple(int(x,16) for x in r.split('-')) for r in f[3].split(';') if r]
def calls_in(text,short):
    out=[]
    for m in re.finditer(r'(?<![\w])'+re.escape(short)+r'\s*\(',text):
        i=m.end();dd=1;j=i;n=0;seen=False
        while j<len(text) and dd:
            ch=text[j]
            if ch in '([': dd+=1
            elif ch in ')]': dd-=1
            elif ch==',' and dd==1: n+=1
            elif not ch.isspace(): seen=True
            j+=1
        out.append((n+1) if seen else 0)
    return out
bad=0
for ent,rs in sorted(fns.items()):
    sites=[]   # (bl addr, target, nstack)
    for lo,hi in rs:
        stores=set()
        for x in range(lo,hi,4):
            w=word(x)
            if w is None: continue
            op=w>>26
            if op in (36,37,38,39,44,45,52,53,54,55,32+0) and False: pass
            # stores relative to r1 with offset >= 0x38: stw(36) stwu(37) stb(38) stbu(39) sth(44) sthu(45) stfs(52) stfsu(53) stfd(54) stfdu(55)
            if op in (36,38,44,52,54) and ((w>>16)&31)==1:
                off=w&0xffff
                if 0x38<=off<0x100: stores.add(off)
            if (w>>26)==18 and (w&1) and not (w&2):
                off=w&0x03fffffc
                if off&0x02000000: off-=0x04000000
                t=(x+off)&0xffffffff
                if t in nparams and nparams[t]>=9:
                    nst=0
                    while (0x38+4*nst) in stores: nst+=1      # the outgoing words are contiguous from 0x38; higher stores are the caller's own locals
                    sites.append((x,t,nst))
                stores=set()
            elif op==16 or (op==18 and not (w&1)) or w==0x4e800020:
                pass
    if not sites: continue
    txt=open(dump+'/0x%x.txt'%ent,errors='replace').read()
    for x,t,nst in sites:
        nm=names.get(t); 
        if not nm: continue
        short=nm.split('::')[-1] if '::' in nm else nm
        cl=calls_in(txt,short)
        want=8+nst if nst else None
        maxargs=max(cl) if cl else 0
        if nst and not any(c>=8+nst for c in cl):
            bad+=1; print('%s %x (%s) bl@%x -> %s: stock stores %d stack words (>= %d args), C calls pass %s'%(key,ent,names.get(ent),x,nm,nst,8+nst,cl))
print(key,'suspect call sites:',bad)
