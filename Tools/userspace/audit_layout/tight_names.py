import re,subprocess,os,sys
L=open(os.path.expanduser('~/wt/r19/Userspace/ATIRadeonX1000GLDriver/ppc/notes_r18_audit.md')).read().split('## 28 TIGHT')[1].split('## Counts')[0]
led={}
for l in open(os.path.expanduser('~/wt/r19/Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv')):
    f=l.rstrip('\n').split('\t')
    if len(f)>3: led[f[0].lower().replace('0x','').lstrip('0')]=f[2]
for l in L.strip().split('\n')[1:]:
    m=re.match(r'(\S+) (part_\d+) (\S+) TIGHT\', \[\((\d+), (\d+), (\d+), (\d+)\)\]',l)
    if not m: continue
    b,p,f,b1,b2,c1,c2=m.groups();b1,b2,c1,c2=map(int,(b1,b2,c1,c2))
    cn=f[1:] if b!='ATIRadeonX1000GLDriver' else led.get(f.split('_')[-1].lstrip('0'),f)
    if b=='ATIRadeonX1000GLDriver' and not f.startswith('_FUN_'): cn=f[1:]
    out=subprocess.run(['python3',os.path.expanduser('~/g5logs/tmp_r19/locmap.py'),b,p,cn],capture_output=True,text=True).stdout.split('\n')
    def find(o):
        best=None
        for x in out:
            mm=re.match(r'\s*(\d+) (\S+) (\S+) size=(\S+)',x)
            if mm and int(mm.group(1))<=o and (int(mm.group(1))==o or True): 
                if int(mm.group(1))==o: return x.strip()
        return f'?@{o}'
    print(f'{b[-8:]} {p} {cn} base({b1},{b2} gap {b2-b1}) cand({c1},{c2} gap {c2-c1})\n    A: {find(c1)}\n    B: {find(c2)}')
