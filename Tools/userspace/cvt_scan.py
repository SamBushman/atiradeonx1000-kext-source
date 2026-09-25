#!/usr/bin/env python3
# cvt_scan.py DIS DUMPDIR - functions whose decompile converts between int and float with a plain cast: `(int)fVarN` / `(uint)fVarN` (a real
# conversion needs fctiw/fctiwz in the stock code) and `(float)iVarN` / `(float)(int expr)` (32-bit PPC has no int->float instruction; the real
# conversion is the 0x43300000 magic-double sequence, printed as CONCAT44). Rows: entry, name, casts, whether the stock function has fctiw*.
import sys,re,glob,os
dis,D=sys.argv[1:3]
ins={}
for l in open(dis,errors='replace'):
    m=re.match(r'([0-9a-f]{8})\t(\S+)',l)
    if m: ins[int(m.group(1),16)]=m.group(2)
rows={}
for l in open(D+'/RANGES.tsv'):
    p=l.rstrip('\n').split('\t')
    if len(p)>3 and p[0].startswith('0x') and p[2]=='fn': rows[int(p[0],16)]=[tuple(int(x,16) for x in r.split('-')) for r in p[3].strip(';').split(';') if r]
F2I=re.compile(r'\((?:u?int|uint|short|ushort|char|uchar|byte)\)\s*(?:[fd]Var\d+|local_\w+|pfVar\d+\[)')
I2F=re.compile(r'\(float\)\s*(?:[iu]Var\d+\b|\(\s*(?:u?int|uint)\)|-?\*\((?:u?int|uint|undefined4) \*\)|\([iu]Var\d+\s*[-+*/^|&]|\((?:uint)\)\()')
tot=0
for f in sorted(glob.glob(D+'/*.txt')):
    t=open(f).read(); m=re.search(r'// Function: (.*) @ (\S+)',t)
    if not m: continue
    e=int(m.group(2),16)
    body=t[t.find('\n{\n'):]
    a=len(F2I.findall(body)); b=len(I2F.findall(body))
    if not (a or b): continue
    has=any(ins.get(x,'').startswith('fctiw') for lo,hi in rows.get(e,[]) for x in range(lo,hi,4))
    tot+=1
    print('%x\t%s\tf2i=%d\ti2f=%d\tfctiw=%s'%(e,m.group(1)[:60],a,b,has))
print('functions:',tot,file=sys.stderr)
