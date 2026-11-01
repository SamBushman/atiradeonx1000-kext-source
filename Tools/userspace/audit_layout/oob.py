import sys,re,glob,os
# oob.py ppcdir : find, in every function, local-array subscripts that are out of declared bounds (negative / >= size) and byte-overlay arithmetic on &local
d=sys.argv[1]
tn={'undefined1':1,'undefined2':2,'undefined4':4,'undefined8':8,'char':1,'byte':1,'bool':1,'short':2,'ushort':2,'int':4,'uint':4,'float':4,'dword':4,'double':8,'undefined':1,'long':4,'ulong':4}
files=sorted(glob.glob(d+'/part_*.c')+glob.glob(d+'/unowned_code/part_*.c'))
n=0
for fp in files:
    t=open(fp,errors='replace').read()
    for m in re.finditer(r'/\* (\S+) @ (0x[0-9a-f]+) \((\d+) bytes\) \*/\n',t):
        e=t.find('\n/* ',m.end());b=t[m.end():e if e>0 else None]
        i=b.find('{')
        if i<0: continue
        code=b[i:]
        decl={}
        for dm in re.finditer(r'^\s*([A-Za-z_][A-Za-z0-9_ ]*?)\s*(\*?)\s*([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[(\d+)\])?\s*;',code,re.M):
            ty,ptr,nm,sz=dm.groups();decl[nm]=(ty.strip()+('*' if ptr else ''),int(sz) if sz else None)
        body=code
        for nm,(ty,sz) in decl.items():
            for sm in re.finditer(r'(?<![A-Za-z0-9_.>])'+re.escape(nm)+r'\s*\[([^\]]*)\]',body):
                ctx=body[max(0,sm.start()-25):sm.start()]
                if re.search(r'(undefined\d?|char|uint|int|float|byte|dword|bool|short|ushort)\s*\**\s*$',ctx): continue
                ix=sm.group(1).strip()
                if sz is None: continue
                if re.fullmatch(r'-?(0x[0-9a-f]+|\d+)',ix):
                    v=int(ix,0)
                    if v<0 or v>=sz: print(f'{os.path.basename(fp)} {m.group(1)} {m.group(2)}: {nm}[{sz}] idx {ix}');n+=1
                elif re.search(r'-\s*\d|\+\s*-',ix): print(f'{os.path.basename(fp)} {m.group(1)} {m.group(2)}: {nm}[{sz}] idx expr [{ix}]');n+=1
            for sm in re.finditer(r'\(\s*(?:int|uint|undefined4)\s*\)\s*&\s*'+re.escape(nm)+r'\s*\+',body):
                print(f'{os.path.basename(fp)} {m.group(1)} {m.group(2)}: (int)&{nm} + ...  {body[sm.start():sm.start()+70]!r}');n+=1
print('TOTAL',n)
