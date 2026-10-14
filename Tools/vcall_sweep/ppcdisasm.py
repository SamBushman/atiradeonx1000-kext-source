import struct,sys,capstone
data=open(sys.argv[1],'rb').read()
start=int(sys.argv[2],16); end=int(sys.argv[3],16)
n=struct.unpack('>I',data[4:8])[0]
off=None
for i in range(n):
    ct,cs,o,sz,al=struct.unpack('>5I',data[8+i*20:28+i*20])
    if ct==18: off=o
m=data[off:]
assert struct.unpack('>I',m[:4])[0]==0xfeedface
nc=struct.unpack('>I',m[16:20])[0]; p=28; segs=[]
for _ in range(nc):
    cmd,sz=struct.unpack('>II',m[p:p+8])
    if cmd==1:
        name=m[p+8:p+24].rstrip(b'\0');vm,vs,fo,fs=struct.unpack('>4I',m[p+24:p+40]); segs.append((vm,vs,fo,fs))
    p+=sz
def f(a):
    for vm,vs,fo,fs in segs:
        if vm<=a<vm+vs: return fo+a-vm
md=capstone.Cs(capstone.CS_ARCH_PPC,capstone.CS_MODE_32+capstone.CS_MODE_BIG_ENDIAN)
fo=f(start)
for a in range(start,end,4):
    w=m[fo+a-start:fo+a-start+4]
    r=list(md.disasm(w,a))
    if r: print("%x: %s %s"%(r[0].address,r[0].mnemonic,r[0].op_str))
    else: print("%x: .word 0x%s"%(a,w.hex()))
