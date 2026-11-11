import struct,sys
def load(path):
    d=open(path,'rb').read(); off=0
    magic=struct.unpack('>I',d[:4])[0]
    if magic==0xcafebabe:
        n=struct.unpack('>I',d[4:8])[0]
        for i in range(n):
            ct,cs,o,sz,al=struct.unpack('>IIIII',d[8+i*20:28+i*20])
            if ct==18: off=o;break
        d=d[off:off+sz]
    assert struct.unpack('>I',d[:4])[0]==0xfeedface
    ncmds=struct.unpack('>I',d[16:20])[0]; p=28; segs=[]
    for _ in range(ncmds):
        cmd,size=struct.unpack('>II',d[p:p+8])
        if cmd==1:
            nsects=struct.unpack('>I',d[p+48:p+52])[0]
            q=p+56
            for s in range(nsects):
                addr,sz,fo=struct.unpack('>III',d[q+32:q+44]); segs.append((addr,sz,fo)); q+=68
        p+=size
    return d,segs
def val(d,segs,addr,kind):
    for a,sz,fo in segs:
        if a<=addr<a+sz and fo:
            o=fo+addr-a
            return struct.unpack('>f' if kind=='f' else '>d',d[o:o+(4 if kind=='f' else 8)])[0]
if __name__=='__main__':
    d,segs=load(sys.argv[1])
    for a in sys.argv[2:]: print(a, val(d,segs,int(a,16),'d' if len(a)>0 and False else 'f'))
