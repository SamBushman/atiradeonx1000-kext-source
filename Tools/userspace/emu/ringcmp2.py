import re,sys
def load(f):
    sec=[]; cur=False
    for l in open(f,errors='replace'):
        if '=====M2' in l: cur=True
        if '=====M4' in l: cur=False
        m=re.match(r'^(?:\(gdb\) )*0x[0-9a-f]+[^:]*:\s*(.*)$',l)
        if m and cur: sec+= [int(x,16) for x in re.findall(r'0x([0-9a-f]+)',m.group(1))]
    return sec
A=load('/tmp/emu/ring_%s.out'%sys.argv[1]); B=load('/tmp/emu/ring_%s.out'%sys.argv[2])
print(len(A),len(B),'nonzero',sum(1 for v in A if v),sum(1 for v in B if v))
d=[i for i in range(min(len(A),len(B))) if A[i]!=B[i]]
print(len(d),'differing words:',d[:80])
if len(sys.argv)>3:
    for i in d[:int(sys.argv[3])]: print('%4d 0x%04x stock %08x new %08x'%(i,i*4,A[i],B[i]))
