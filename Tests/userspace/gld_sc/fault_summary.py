#!/usr/bin/env python3
"""fault_summary.py LOG [START_MARKER] [IMG_BASE] : per row, where did the STOCK children's trials end? Parses the fnfuzz UDP breadcrumb log (W fault / W wild branch / W signal lines),
maps stock pcs (minus the stock image load base, default 0x151d000) to the corpus function that contains them, and prints the top (kind, faulting function, caller function) triples per row.
Used to decide which object / vtable / table each uninformative row still needs in the graph spec (#273 follow-up)."""
import re,sys,glob,os,collections,bisect
log=sys.argv[1]; marker=sys.argv[2] if len(sys.argv)>2 else 'LRUN START'; base=int(sys.argv[3],16) if len(sys.argv)>3 else 0x151d000
D=os.path.expanduser('~/atiradeonx1000-kext-source/Userspace/ATIRadeonX1000GLDriver/ppc/')
fn=[]
for p in glob.glob(D+'part_*.c'):
    for m in re.finditer(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\)',open(p,errors='replace').read(),re.M): fn.append((int(m.group(2),16),int(m.group(3)),m.group(1)))
fn.sort(); starts=[f[0] for f in fn]
def name(pc):
    a=pc-base; k=bisect.bisect_right(starts,a)-1
    if k>=0 and a<fn[k][0]+max(fn[k][1],4): return '%s+%x'%(fn[k][2],a-fn[k][0])
    return '%x'%pc
L=open(log,errors='replace').read().split('\n')
st=max([i for i,l in enumerate(L) if marker in l] or [0])
row=None; img={}; res=collections.defaultdict(collections.Counter); status=collections.defaultdict(collections.Counter)
for l in L[st:]:
    m=re.search(r' p(\d+) ROW id \d+ (\S+)',l)
    if m: row=m.group(2); continue
    m=re.search(r' p(\d+) C id \d+ img (\S)',l)
    if m: img[m.group(1)]=m.group(2); continue
    m=re.search(r' p(\d+) W (.*)',l)
    if not m or row is None or img.get(m.group(1))!='S': continue
    w=m.group(2)
    mm=re.match(r'status (\d+)',w)
    if mm: status[row][mm.group(1)]+=1; continue
    mm=re.match(r'fault (\d+) pc (\S+) ba (\S+) bt (\S+) (\S+) (\S+)',w)
    if mm: res[row][('fault'+mm.group(1),name(int(mm.group(2),16)),name(int(mm.group(4),16)),name(int(mm.group(6),16)))]+=1; continue
    mm=re.match(r'wild branch to (\S+) at pc (\S+)',w)
    if mm: res[row][('wild '+mm.group(1),name(int(mm.group(2),16)),'','')]+=1; continue
    mm=re.match(r'signal (\d+) pc (\S+) lr (\S+)',w)
    if mm: res[row][('sig'+mm.group(1),mm.group(2),mm.group(3),'')]+=1
for r in res:
    print('%s  status %s'%(r,dict(status[r])))
    for k,v in res[r].most_common(int(os.environ.get('TOP','4'))): print('    %3d  %s'%(v,' | '.join(x for x in k if x)))
