import sys,os,re
sys.path.insert(0,os.path.expanduser('~/wt/r20/Tools/userspace'))
import machoutil as M
from capstone import *
BIN={'gld':'ATIRadeonX1000GLDriver','glp':'libGLProgrammability'}
def load(b):
    p=os.path.expanduser(f'~/Documents/ATI-X1900-Decomp/tiger-hd-pull/'+('libGLProgrammability.dylib' if b=='glp' else f'{BIN[b]}.bundle.bin'))
    return M.load(p)
def dis(m,addr,n):
    md=Cs(CS_ARCH_PPC,CS_MODE_32|CS_MODE_BIG_ENDIAN)
    md.skipdata=True
    return list(md.disasm(m.read(addr,n),addr))
if __name__=='__main__':
    b,addr,n=sys.argv[1],int(sys.argv[2],16),int(sys.argv[3])
    m=load(b);I=dis(m,addr,n)
    fs=None
    esc={}
    acc={}
    for i in I:
        if i.mnemonic=='stwu' and 'r1' in i.op_str and fs is None:
            mm=re.search(r'-(0x[0-9a-f]+|\d+)\(',i.op_str);fs=int(mm.group(1),0)
        mm=re.match(r'(r\d+), r1, (-?(?:0x)?[0-9a-f]+)$',i.op_str)
        if i.mnemonic=='addi' and mm: esc.setdefault(int(mm.group(2),0),[]).append(i.address)
        mm=re.match(r'[rf]\d+, (-?(?:0x)?[0-9a-f]+)\(r1\)$',i.op_str)
        if mm and i.mnemonic not in('stwu','stw') or (mm and i.mnemonic=='stw'): acc.setdefault(int(mm.group(1),0),[]).append((i.address,i.mnemonic))
    print('frame',hex(fs or 0))
    print('addr-taken sp offsets:',sorted(hex(k) for k in esc))
