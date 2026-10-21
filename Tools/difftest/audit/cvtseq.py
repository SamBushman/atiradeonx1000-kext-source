#!/usr/bin/env python3
"""cvtseq.py DIS: per function, the ordered sequence of int->double conversions as S (signed: low word flipped with xoris/addis 0x8000) or U (unsigned), found as lfd-from-stack + fsub sites
usage: cvtseq.py STOCK.dis REBUILT.dis -> functions where the S/U sequences differ"""
import sys,re
def scan(path):
    funcs={};cur=None;ins=[]
    for ln in open(path,errors='replace'):
        s=ln.rstrip()
        if re.match(r'^_\S+:$',s):
            if cur: funcs[cur]=ins
            cur=s[:-1]; ins=[]; continue
        m=re.match(r'^[0-9a-f]{8}\s+(\S+)\s*(.*)$',s)
        if m: ins.append((m.group(1),m.group(2)))
    if cur: funcs[cur]=ins
    out={}
    for f,ins in funcs.items():
        seq=[]
        for i,(op,a) in enumerate(ins):
            if op=='fsub':
                # find the lfd of the conversion operand within 6 before: lfd fN,off(r1)
                for j in range(i-1,max(-1,i-8),-1):
                    if ins[j][0]=='lfd':
                        m=re.match(r'f\d+,(0x[0-9a-f]+|\d+)\(r1\)',ins[j][1])
                        if m:
                            off=m.group(1)
                            # the stw of the low word at off+4 (or off) earlier
                            low=None
                            for k in range(j-1,max(-1,j-25),-1):
                                mm=re.match(r'r(\d+),(0x[0-9a-f]+|\d+)\(r1\)',ins[k][1]) if ins[k][0]=='stw' else None
                                if mm and int(mm.group(2),16)==int(off,16)+4:
                                    reg=mm.group(1); low=(k,reg); break
                            if low:
                                k,reg=low; kind='U'
                                for q in range(k-1,max(-1,k-10),-1):
                                    mq=re.match(r'r(\d+),r\d+,-?(?:0x8000|32768)$',ins[q][1]) if ins[q][0] in ('xoris','addis','subis') else None
                                    if mq and mq.group(1)==reg: kind='S'; break
                                seq.append(kind)
                            break
        out[f]=''.join(seq)
    return out
a,b=scan(sys.argv[1]),scan(sys.argv[2])
n=0
for f in sorted(set(a)&set(b)):
    if (a[f] or b[f]):
        n+=1
        flag='' if sorted(a[f])==sorted(b[f]) else '   <== DIFF'
        if flag or '-v' in sys.argv: print('%s stock=%s rebuilt=%s%s'%(f[:100],a[f],b[f],flag))
print(n,'functions with conversions')
