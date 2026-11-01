import sys,re
# showfn.py ppcdir addr : print the C of the function at address (from ledger)
d,addr=sys.argv[1],sys.argv[2].lower().lstrip('0x')
name=part=None
for l in open(d+'/ledger.tsv'):
    f=l.rstrip('\n').split('\t')
    if len(f)>3 and f[0].lower().replace('0x','').lstrip('0')==addr.lstrip('0'): name,part=f[2],f[3];break
if not name: print('NOT IN LEDGER',addr);sys.exit()
t=open(f'{d}/{part}.c',errors='replace').read()
m=re.search(r'/\* '+re.escape(name)+r' @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n',t)
s=m.start();e=t.find('\n/* ',m.end())
print('//',name,part);print(t[s:e if e>0 else None])
