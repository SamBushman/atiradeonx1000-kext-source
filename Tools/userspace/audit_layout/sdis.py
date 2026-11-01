import sys,os
sys.path.insert(0,os.path.expanduser('~/wt/r19/Tools/userspace'))
import machoutil as M
from capstone import *
path=os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin')
m=M.load(path)
addr=int(sys.argv[1],16);n=int(sys.argv[2])
data=m.read(addr,n)
md=Cs(CS_ARCH_PPC,CS_MODE_32|CS_MODE_BIG_ENDIAN)
for i in md.disasm(data,addr): print(f'{i.address:08x} {i.mnemonic} {i.op_str}')
