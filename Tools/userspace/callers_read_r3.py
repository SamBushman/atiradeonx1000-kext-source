"""callers_read_r3.py NAME... : for every DIRECT stock call site (`bl <function>`) of the named GLDriver functions, does the code after the call read r3 before redefining it?
   Reads the stock Mach-O (env STOCK, default ~/g5logs/fnf_237/stockbins/gld_ATIRadeonX1000GLDriver, fat, ppc slice at 0x1000) and the corpus headers (`/* name @ 0xADDR`).
   Per call site: R = r3 read after the call (the return value is used: the function is NOT void), N = r3 not read in the straight-line code up to the next branch/blr/bl (void is consistent),
   ? = the straight line ended at a conditional branch before r3 was read or written (follow-up by hand).  Indirect callers (vtable slots, function pointers) are NOT covered: 'not established' for those."""
import re,glob,sys,os,struct
import capstone
import re as _re
S=os.environ.get('STOCK',os.path.expanduser('~/g5logs/fnf_237/stockbins/gld_ATIRadeonX1000GLDriver'))
raw=open(S,'rb').read()
off=0
if struct.unpack('>I',raw[:4])[0]==0xcafebabe:
    for i in range(struct.unpack('>I',raw[4:8])[0]):
        cpu,sub,o,sz,al=struct.unpack('>5I',raw[8+20*i:28+20*i])
        if cpu==18: off=o
t=raw[off:]
MD=capstone.Cs(capstone.CS_ARCH_PPC,capstone.CS_MODE_32|capstone.CS_MODE_BIG_ENDIAN); MD.detail=True
D=os.path.expanduser('~/atiradeonx1000-kext-source/Userspace/ATIRadeonX1000GLDriver/ppc/')
addr={}
for p in glob.glob(D+'part_*.c'):
    for m in re.finditer(r'^/\* (\S+) @ 0x([0-9a-f]+) ',open(p,errors='replace').read(),re.M): addr[m.group(1)]=int(m.group(2),16)
TEXT_END=0x1d9000
words=struct.unpack('>%dI'%(TEXT_END//4),t[:TEXT_END])
NOWRITE=('st','cmp','mt','b','tw','td','dcb','icb','sync','isync','eieio','cr','mcrf')
def regs(i):
    ops=[o.strip() for o in i.op_str.split(',')] if i.op_str else []
    rd=set(); wr=set()
    def rr(o):
        return [int(x) for x in _re.findall(r'\br(\d+)\b',o)]
    m=i.mnemonic
    if not ops: return rd,wr
    dest_first=not m.startswith(NOWRITE) or m.startswith(('mtc','mtl')) and False
    if m.startswith('mt') or m.startswith('st') or m.startswith('cmp') or m.startswith('b') or m.startswith(('tw','td','dcb','icb')):
        for o in ops: rd.update(rr(o))
        if m.startswith('stwu') or m.startswith('stbu') or m.startswith('sthu'): wr.update(rr(ops[-1]))
    else:
        wr.update(rr(ops[0]))
        for o in ops[1:]: rd.update(rr(o))
        if m.endswith('u') and m.startswith('l') or m.startswith('lwzu'):
            wr.update(rr(ops[-1]))
        if m in('rlwimi',): rd.update(rr(ops[0]))
        if m.startswith('addic') or m=='addi': pass
    return rd,wr
def decode(a):
    return next(MD.disasm(t[a:a+4],a),None)
for n in sys.argv[1:]:
    if n not in addr: print(n,'unknown'); continue
    tgt=addr[n]; sites=[]
    for k,w in enumerate(words):
        if (w&0xfc000003)==0x48000001:
            d=w&0x03fffffc; d=d-0x4000000 if d&0x2000000 else d
            if (k*4+d)&0xffffffff==tgt: sites.append(k*4)
    def walk(a,depth,seen):
        """R = some path reads r3 before writing it, T = a path returns (blr) with r3 untouched (the caller's caller sees it), N = every path overwrites r3 or calls out first, ? = depth limit"""
        out=set()
        for _ in range(60):
            if a in seen: return out
            seen.add(a)
            i=decode(a)
            if i is None: return out|{'?'}
            rd,wr=regs(i); m=i.mnemonic
            if m=='blr': return out|{'T'}
            if m.startswith('b') and m not in('bl','bctrl','blrl'):
                if m in('bctr',): return out|{'?'}
                # conditional or unconditional direct branch: follow the target (and the fall-through for conditionals)
                try: tg=int(i.op_str.split(',')[-1].strip(),16)
                except Exception: return out|{'?'}
                if depth>0: out|=walk(tg,depth-1,set(seen))
                else: out.add('?')
                if m=='b': return out
                a+=4; continue
            if 3 in rd: return out|{'R'}
            if m in('bl','bctrl','blrl'): return out|{'N'}
            if 3 in wr: return out|{'N'}
            a+=4
        return out|{'?'}
    res=[(s,''.join(sorted(walk(s+4,6,set())))) for s in sites]
    print(n,hex(tgt),len(sites),'sites:',' '.join('%x:%s'%x for x in res))
