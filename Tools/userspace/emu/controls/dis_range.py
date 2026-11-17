import sys
sys.path.insert(0,'/home/sam/atiradeonx1000-kext-source/Tools/userspace/emu')
import trace_diff as t
from capstone import *
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
path, lo, hi = sys.argv[1], int(sys.argv[2],16), int(sys.argv[3],16)
m = t.macho(path)
segs = next(x for x in m if isinstance(x, list) and x and isinstance(x[0], tuple) and len(x[0]) == 4 and isinstance(x[0][3], (bytes, bytearray)))
for name, vm, vs, data in segs:
    if vm <= lo < vm + vs:
        for i in md.disasm(bytes(data[lo-vm:hi-vm]), lo): print('%x %s %s' % (i.address, i.mnemonic, i.op_str))
