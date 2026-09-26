#!/usr/bin/env python3
"""format_check.py LINKED_TREE  - audit every printf-family call of a linked corpus against its format string (Stage B3 step 18).

LINKED_TREE is a directory written by link_corpus.py (part_*.c and data.s). For each `_sprintf` / `_printf` / `_fprintf` / `_snprintf` call the format is taken
from the literal or, for a global pointer variable (`DAT_a7b7bd8c`), from the string the initialised pointer in data.s refers to; the number of conversions
(`%d`, `%s`, `%*d`, ...) is compared with the number of variadic arguments the C passes. Prints one line per mismatch, `UNRESOLVED fmt` for a format that is
computed (those need a manual look), and nothing else. A mismatch is a dropped or surplus register argument (`sprintf(buf, "%s.%s")`) that the decompile printed
without its variadic arguments."""
import re, glob, sys
d = sys.argv[1]
data=open(d+'/data.s',errors='replace').read().split('\n')
# label -> next directive lines
lab={}
for i,l in enumerate(data):
    m=re.match(r'^([A-Za-z_][\w$]*):',l)
    if m: lab.setdefault(m.group(1),i)
def cstr(name,depth=0):
    i=lab.get(name)
    if i is None: return None
    s='';j=i+1
    while j<len(data):
        l=data[j]
        m=re.match(r'\s*\.ascii "(.*)"$',l)
        if m: s+=m.group(1).encode().decode('unicode_escape'); j+=1; continue
        m=re.match(r'\s*\.byte 0',l)
        if m: return s
        if re.match(r'\s*\.(globl|long|space)|^\w',l) and not l.startswith(' '): 
            if l.startswith('.globl') : j+=1; continue
        break
    return s if s else None
def ptr(name):
    i=lab.get(name)
    if i is None: return None
    for j in range(i+1,i+4):
        m=re.match(r'\s*\.long (LD_[0-9a-f]+)',data[j])
        if m: return cstr(m.group(1))
    return None
CONV=re.compile(r'%(?!%)[-+ #0]*(\*|\d*)(?:\.(\*|\d+))?(hh|h|ll|l|L|q|z|j|t)?([diouxXeEfgGcspn])')
def split_args(s):
    out=[];d=0;cur='';q=None
    for ch in s:
        if q:
            cur+=ch
            if ch==q: q=None
            continue
        if ch in '"\'': q=ch;cur+=ch;continue
        if ch in '([': d+=1
        if ch in ')]': d-=1
        if ch==',' and d==0: out.append(cur.strip());cur=''
        else: cur+=ch
    if cur.strip(): out.append(cur.strip())
    return out
for f in sorted(glob.glob(d+'/part_*.c')):
    txt=open(f).read()
    fn=None
    for m in re.finditer(r'(?m)^/\* (\S+) @ (\S+)|\b_(sprintf|printf|fprintf|snprintf)\s*\(',txt):
        if m.group(1): fn=m.group(1);continue
        # parse call args
        i=m.end();dd=1;j=i;q=None
        while dd and j<len(txt):
            ch=txt[j]
            if q:
                if ch==q and txt[j-1]!='\\': q=None
            elif ch in '"\'': q=ch
            elif ch=='(': dd+=1
            elif ch==')': dd-=1
            j+=1
        args=split_args(txt[i:j-1]); kind=m.group(3)
        fi={'sprintf':1,'printf':0,'fprintf':1,'snprintf':2}[kind]
        if len(args)<=fi: print(f[-10:],fn,'NOFMT',args);continue
        fa=args[fi]
        if fa.startswith('"'): 
            s=fa[1:fa.rindex('"')].encode().decode('unicode_escape')
        else:
            mm=re.match(r'^(?:\(\w[\w ]*\*?\))?\s*(\w+)$',fa)
            s=ptr(mm.group(1)) if mm else None
            if s is None: print(f[-10:],fn,kind,'UNRESOLVED fmt',fa,'nargs',len(args)-fi-1);continue
        need=0
        for c in CONV.finditer(s):
            need+= (c.group(1)=='*')+(c.group(2)=='*')+1
        have=len(args)-fi-1
        if have!=need: print(f[-10:],fn,kind,repr(s),'need',need,'have',have,'|',args[fi:])
