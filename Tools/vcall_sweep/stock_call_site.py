import sys,subprocess,re,os
R=os.path.expanduser('~/atiradeonx1000-kext-source'); S=os.path.dirname(os.path.abspath(__file__))+'/'
BIN=os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/ATIRadeonX1000.kext.bin')
name=sys.argv[1]; off=int(sys.argv[2],16); ctx=int(sys.argv[3]) if len(sys.argv)>3 else 16
led=[l.rstrip('\n').split('\t') for l in open(R+'/Ledger/kext_ppc_ledger.tsv')]
hit=[f for f in led if len(f)>=5 and f[4]==name]
if not hit: print("no ledger entry for",name); sys.exit(1)
pat=re.compile(r'lwz r\d+, 0x%x\(r\d+\)'%off)
n=0
for h in hit:
  a=int(h[0],16); sz=int(h[1])
  if sz==0: continue
  out=subprocess.run(['python3',S+'ppcdisasm.py',BIN,'%x'%a,'%x'%(a+sz)],capture_output=True,text=True).stdout.splitlines()
  for i,l in enumerate(out):
    if pat.search(l):
        n+=1
        print("--- %s fn@%x call@%s  (site %d)"%(name,a,l.split(':')[0],n))
        print("\n".join(out[max(0,i-ctx):i+5]))
if not n: print("no lwz ...0x%x( in %s"%(off,name))
