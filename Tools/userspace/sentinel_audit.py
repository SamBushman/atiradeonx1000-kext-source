import os,re,sys,glob
sys.path.insert(0,os.path.expanduser('~/atiradeonx1000-kext-source/Tools/userspace'))
import fn_norm_diff as f, capstone
MD=capstone.Cs(capstone.CS_ARCH_PPC,capstone.CS_MODE_32|capstone.CS_MODE_BIG_ENDIAN); MD.skipdata=True
S=os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin')
D=os.path.expanduser('~/atiradeonx1000-kext-source/Userspace/')
hdr=re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/')
def scan(files,S):
  out=[]
  for p in files:
    L=open(p).read().split('\n'); cur=None; body=[]
    def flush():
        if not cur: return
        txt='\n'.join(body); cs=re.findall(r'0x7fff0000U|0x7ffffffeU|0x7ffffffe\b|0x7fff[0-9a-f]{4}U?',txt)
        if not any(c.startswith('0x7fff0000') or c.startswith('0x7ffffffe') for c in cs): return
        ins=list(MD.disasm(f.code(S,cur[1],cur[2]),cur[1])); st=[]
        for i,x in enumerate(ins):
            if x.mnemonic=='lis' and x.op_str.endswith('0x7fff'):
                reg=x.op_str.split(',')[0]; v='7fff0000'
                for y in ins[i+1:i+12]:
                    if y.op_str.startswith(reg+', '+reg+', ') and y.mnemonic in('ori','addi'):
                        v='7ffffffe' if y.op_str.endswith(('0xfffe','-2')) else 'other:'+y.op_str; break
                    if y.op_str.startswith(reg+',') and y.mnemonic not in ('stw','stwx','cmpw','cmplw'): break
                st.append(v)
        co=[c.rstrip('U').replace('0x','') for c in cs]
        out.append((cur[0],cur[1],co,st))
    for ln in L:
        m=hdr.match(ln)
        if m: flush(); cur=(m.group(1),int(m.group(2),16),int(m.group(3))); body=[]
        else: body.append(ln)
    flush()
  return out
if __name__=='__main__':
  corp=sys.argv[1]; stock=sys.argv[2]
  for n,a,co,st in scan(sorted(glob.glob(D+corp+'/ppc/part_*.c')),os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/'+stock)):
    ok = set(co)==set(st)
    print('%s %-46s %x corpus %s | stock %s'%('ok ' if ok else 'DIF',n,a,' '.join(co),' '.join(st)))
