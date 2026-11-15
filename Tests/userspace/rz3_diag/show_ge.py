import sys, capstone
sys.path.insert(0, '/home/sam/atiradeonx1000-kext-source/Tools/userspace')
import fn_norm_diff as f
def dis(path, addr, size):
    md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
    return ["%x: %s %s" % (i.address, i.mnemonic, i.op_str) for i in md.disasm(f.code(path, addr, size), addr)]
name = sys.argv[1]
for l in open('/home/sam/g5logs/fnf_237/rz3/p27_other18.tsv'):
    p = l.rstrip('\n').split('\t')
    if len(p) > 4 and p[1] == name:
        sa, ra, sz = int(p[2], 16), int(p[3], 16), int(p[4])
        print("== STOCK", name, hex(sa)); print("\n".join(dis('/home/sam/g5logs/fnf_237/gleng_bins/GLEngine_stock', sa, sz)))
        print("== REBUILT", hex(ra)); print("\n".join(dis('/home/sam/g5logs/fnf_237/gleng_bins/GLEngine_1ec1', ra, int(sys.argv[2]) if len(sys.argv) > 2 else sz)))
