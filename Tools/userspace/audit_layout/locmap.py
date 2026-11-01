import re,sys,os
# locmap.py bin part func : cand frame map (stabs offset -> name,size from C) for a function in the current corpus
b,part,fn=sys.argv[1:4]
fn=fn.lstrip('_') if False else fn
d=os.path.expanduser(f'~/wt/r19/Userspace/{b}/ppc')
s=open(os.path.expanduser(f'~/g5logs/tmp_r19/stabs_{b}/p{part.split("_")[1]}.s'),errors='replace').read().split('\n')
tn={'undefined1':1,'undefined2':2,'undefined4':4,'undefined8':8,'char':1,'byte':1,'bool':1,'short':2,'ushort':2,'int':4,'uint':4,'float':4,'dword':4,'double':8,'undefined':1,'long':4,'ulong':4,'longlong':8,'ulonglong':8}
name=fn.lstrip('_')
locs=[];on=False
for l in s:
    m=re.match(r'\s*\.stabs\s+"([^"]*)",(\d+),\d+,\d+,(.*)',l)
    if not m: continue
    nm,ty,val=m.groups()
    if ty=='36':
        fnm=nm.split(':')[0]
        on=(fnm==name or fnm==fn)
        continue
    if on and ty=='128' and ':' in nm:
        locs.append((int(val),nm.split(':')[0]))
# sizes from C
t=open(f'{d}/{part}.c',errors='replace').read()
mm=re.search(r'/\* ([^\s]*) @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n[^\n]*\b'+re.escape(name)+r'\(',t)
decl={}
for m in re.finditer(r'(?:^|\n)/\* (\S+) @ (0x[0-9a-f]+) \((\d+) bytes\) \*/\n',t):
    if m.group(1)==name or m.group(1)==fn:
        e=t.find('\n/* ',m.end());code=t[m.end():e if e>0 else None];i=code.find('{');code=code[i:]
        for dm in re.finditer(r'^\s*([A-Za-z_][A-Za-z0-9_ ]*?)\s*(\*?)\s*([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[(\d+)\])?\s*;',code,re.M):
            ty,ptr,nm,sz=dm.groups()
            el=4 if ptr else tn.get(ty.strip(),4)
            decl[nm]=(el*(int(sz) if sz else 1),ty.strip()+('*' if ptr else '')+(f'[{sz}]' if sz else ''))
        break
for off,nm in sorted(locs):
    sz,ty=decl.get(nm,(None,'?'))
    print(f'{off:5d} {nm} {ty} size={sz}')
