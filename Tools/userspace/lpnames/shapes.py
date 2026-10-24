import sys,re,collections
sys.path.insert(0,'Tools/userspace')
import find_webs as F
fn=sys.argv[1]
body,brace=F.load('Userspace/ATIRadeonX1000GLDriver/ppc',fn)
names=[]
PH=re.compile(r'\b([a-z]{0,3}Var\d+|p+[A-Za-z]*Var\d+|in_r\d+|local_[0-9a-f]+|param_\d+|[a-z]?Stack_[0-9a-f]+)\b')
for l in body[brace+1:]:
    for m in PH.findall(l):
        if m not in names: names.append(m)
nodes,entry=F.build_cfg(body,brace)
for v in names:
    DEF=re.compile(r'(?<![\w.>*])%s\s*=(?!=)\s*(.*)'%re.escape(v))
    c=collections.OrderedDict()
    for i in range(brace+1,len(body)):
        m=DEF.search(body[i])
        if m: c.setdefault(m.group(1)[:100],[]).append(i)
    try: nw=len(F.webs(nodes,entry,v)[0])
    except (Exception,SystemExit): nw='addr'
    print('==',v,'webs',nw)
    for t,ls in c.items(): print('  %2d %s'%(len(ls),t))
