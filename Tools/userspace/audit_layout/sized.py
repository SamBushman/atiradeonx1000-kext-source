import re,sys,glob,os
# sized.py ppcdir : flag calls writing/reading a counted byte length through &local where length > declared local size
d=sys.argv[1]
tn={'undefined1':1,'undefined2':2,'undefined4':4,'undefined8':8,'char':1,'byte':1,'bool':1,'short':2,'ushort':2,'int':4,'uint':4,'float':4,'dword':4,'double':8,'undefined':1,'long':4,'ulong':4,'longlong':8,'ulonglong':8}
files=sorted(glob.glob(d+'/part_*.c')+glob.glob(d+'/unowned_code/part_*.c'))
calls=r'_?(?:memcpy|memset|bzero|memmove|__memcpy|__memset|__bzero)'
tot=0
for fp in files:
    t=open(fp,errors='replace').read()
    for m in re.finditer(r'(?:^|\n)/\* (\S+) @ (0x[0-9a-f]+) \((\d+) bytes\) \*/\n',t):
        e=t.find('\n/* ',m.end());b=t[m.end():e if e>0 else None];i=b.find('{')
        if i<0: continue
        code=b[i:];decl={}
        for dm in re.finditer(r'^\s*([A-Za-z_][A-Za-z0-9_ ]*?)\s*(\*?)\s*([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[(\d+)\])?\s*;',code,re.M):
            ty,ptr,nm,sz=dm.groups();el=4 if ptr else tn.get(ty.strip(),None)
            if el: decl[nm]=el*(int(sz) if sz else 1)
        for cm in re.finditer(r'\b'+calls+r'\s*\(\s*&?\s*([A-Za-z_][A-Za-z0-9_]*)\s*,[^;]*?,\s*(0x[0-9a-fA-F]+|\d+)\s*\)',code):
            nm,n=cm.group(1),int(cm.group(2),0)
            # only when first arg is &local (scalar) or an array name
            first=code[cm.start():cm.start()+60]
            amp='&' in first.split(',')[0]
            if nm in decl and (amp or any(m2.group(0) for m2 in [re.search(r'\b'+re.escape(nm)+r'\s*\[\d+\]\s*;',code)] if m2)):
                sz=decl[nm]
                if n>sz: print(f'{os.path.basename(fp)} {m.group(1)} {m.group(2)}: mem* on {nm} size {sz} len {n}');tot+=1
        for cm in re.finditer(r'(_io_connect_method_\w+|_IOConnect\w+)\s*\(([^;]*)\);',code):
            tot+=0
print('TOTAL',tot)
