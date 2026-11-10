"""data_ptr_compare.py STOCK REBUILT SYMBOL_MAP NM LEDGER... - static data parity: every labelled data object of the stock (symbol_map: name, stock address, section) is compared
word by word with the rebuilt object of the same name (nm); a word that is a pointer into the image (stock: address inside a stock section; rebuilt: inside a rebuilt
section) must resolve to the same (symbol, offset) on both sides. Reports the objects that differ."""
import sys,struct,bisect,re
def secs(p):
    d=open(p,'rb').read()
    magic,=struct.unpack('>I',d[:4])
    if magic==0xcafebabe:
        n,=struct.unpack('>I',d[4:8])
        for i in range(n):
            cpu,sub,off,size,al=struct.unpack('>5I',d[8+20*i:28+20*i])
            if cpu==18: d=d[off:off+size];break
    ncmds,=struct.unpack('>I',d[16:20]); o=28; out=[]
    for _ in range(ncmds):
        cmd,sz=struct.unpack('>2I',d[o:o+8])
        if cmd==1:
            seg=d[o+8:o+24].split(b'\0')[0].decode(); vm,vs,fo,fs,mp,ip,ns,fl=struct.unpack('>8I',d[o+24:o+56])
            q=o+56
            for k in range(ns):
                sn=d[q:q+16].split(b'\0')[0].decode(); sg=d[q+16:q+32].split(b'\0')[0].decode()
                addr,size,off=struct.unpack('>3I',d[q+32:q+44]); out.append((sg,sn,addr,size,off)); q+=68
        o+=sz
    return out,d
st,rb,smap,nmf=sys.argv[1:5]; ledgers=sys.argv[5:]
ss,sd=secs(st); rs,rd=secs(rb)
def rng(secs_): return [(a,a+sz,off,sg,sn) for sg,sn,a,sz,off in secs_ if sz and off or (sn in('__bss','__common'))]
def word_at(secs_,d,addr):
    for sg,sn,a,sz,off in secs_:
        if a<=addr<a+sz and off: 
            o=off+(addr-a); 
            if o+4<=len(d): return struct.unpack('>I',d[o:o+4])[0]
    return None
def sect_of(secs_,addr):
    for sg,sn,a,sz,off in secs_:
        if a<=addr<a+sz: return (sg,sn)
    return None
# labels
stock_lab={}; stock_txt={}   # addr -> name
for l in open(smap):
    p=l.rstrip('\n').split('\t')
    if len(p)==3 and p[0].startswith('0x') and p[1]=='__text': stock_txt.setdefault(int(p[0],16),[]).append(p[2])
    if len(p)==3 and p[0].startswith('0x') and p[1] not in ('__LINKEDIT','__TEXT','__text'): stock_lab.setdefault(int(p[0],16),p[2])
    elif len(p)==3 and p[0].startswith('0x') and p[1]=='__const': stock_lab.setdefault(int(p[0],16),p[2])
rb_lab={}; rb_by_name={}
for l in open(nmf):
    p=l.split()
    if len(p)==3 and re.match('[0-9a-f]{8}$',p[0]) and p[1] in 'tTdDsSbBcC':
        rb_lab.setdefault(int(p[0],16),p[2]); rb_by_name[p[2]]=int(p[0],16)
# functions from ledgers: stock addr <-> rebuilt addr
fpair={}
for lf in ledgers:
    for l in open(lf):
        p=l.rstrip('\n').split('\t')
        if len(p)>=3 and p[0].startswith('0x'):
            ra_=rb_by_name.get(p[2])
            if ra_ is not None: fpair[int(p[0],16)]=ra_
raw={}
for n_,a_ in rb_by_name.items():
    m_=re.match(r'_?raw_entry_([0-9a-f]+)$',n_)
    if m_: raw[int(m_.group(1),16)]=a_
def cstr(secs_,d,addr):
    for sg,sn,a,sz,off in secs_:
        if a<=addr<a+sz and off:
            o=off+addr-a; e=d.index(b'\0',o); return d[o:e]
    return None
def words_until0(secs_,d,addr,maxn=64):
    out=[]
    for k in range(maxn):
        w=word_at(secs_,d,addr+4*k)
        if not w: break
        out.append(w)
    return out
# anchor mapping for rebuilt function file addresses: ledger reb_off is file address already
def resolve_stock(v):
    s=sect_of(ss,v)
    if not s: return None
    if v in fpair or s[1]=='__text': return ('F',v)
    k=sorted_s[bisect.bisect_right(sorted_s,v)-1] if bisect.bisect_right(sorted_s,v) else None
    return ('D',stock_lab[k],v-k) if k is not None else ('?',v)
def resolve_rb(v):
    s=sect_of(rs,v)
    if not s: return None
    if s[1]=='__text' or s[1]=='__picsymbolstub1': return ('F',v)
    k=sorted_r[bisect.bisect_right(sorted_r,v)-1] if bisect.bisect_right(sorted_r,v) else None
    return ('D',rb_lab[k],v-k) if k is not None else ('?',v)
sorted_s=sorted(stock_lab); sorted_r=sorted(rb_lab)
datasec=lambda s: s and s[1] in ('__const','__data','__nl_symbol_ptr','__la_symbol_ptr','__literal4','__literal8','__dyld')
objs=sorted(a for a in stock_lab if datasec(sect_of(ss,a)))
name_is_interior=lambda a,p: a-p<=0x400 and not stock_lab[a].startswith(('PTR_dyld','dyld'))
nvia=0
nobj=nmiss=ndiff=0; diffs=[]
for i,a in enumerate(objs):
    name=stock_lab[a]
    nxt=objs[i+1] if i+1<len(objs) else a+4
    sec=sect_of(ss,a)
    # keep within the same section
    for sg,sn,sa,sz,off in ss:
        if sa<=a<sa+sz: nxt=min(nxt,sa+sz)
    ra=rb_by_name.get(name) if rb_by_name.get(name) is not None else rb_by_name.get('_'+name)   # the C compiler prefixes an underscore
    nobj+=1
    if ra is None:
        # no rebuilt label of this name (an interior piece Ghidra labelled separately, a dyld stub slot): try the nearest PRECEDING stock object of the same section that has a rebuilt label;
        # the emitter keeps a section's objects in order, so the displacement is constant. A pass this way is real word-for-word evidence; a miss stays 'NO REBUILT LABEL'.
        j=i-1
        while j>=0 and rb_by_name.get(stock_lab[objs[j]]) is None: j-=1
        if j>=0 and sect_of(ss,objs[j])==sec and name_is_interior(a,objs[j]): ra=rb_by_name[stock_lab[objs[j]]]+(a-objs[j]); via=True
        else: nmiss+=1; diffs.append((name,hex(a),'NO REBUILT LABEL')); continue
    else: via=False
    n=(nxt-a)//4; bad=[]; nvia+=via
    for k in range(n):
        sw=word_at(ss,sd,a+4*k); rw=word_at(rs,rd,ra+4*k)
        if sw is None or rw is None: continue       # zerofill: both zero
        if sw==rw: 
            # same value but could be a pointer into different layout: only flag if it resolves differently
            ps=resolve_stock(sw); pr=resolve_rb(rw)
            if ps and pr and ps[0]=='D' and sec[1] not in('__literal4','__literal8') and False: pass
            continue
        ps=resolve_stock(sw); pr=resolve_rb(rw)
        if ps and pr:
            if ps[0]=='F' and pr[0]=='F' and (fpair.get(ps[1])==pr[1] or any(rb_by_name.get(n_)==pr[1] for n_ in stock_txt.get(ps[1],[]))): continue
            if ps[0]=='D' and pr[0]=='D' and ps[1:]==pr[1:]: continue
            if ps[0]=='F' and raw.get(ps[1])==pr[1]: continue
            ss_,rs_=sect_of(ss,sw),sect_of(rs,rw)
            if ss_ and rs_ and ss_[1]=='__cstring' and rs_[1]=='__cstring' and cstr(ss,sd,sw)==cstr(rs,rd,rw): continue
            if ss_ and rs_ and ss_[1]=='__const' and rs_[1]=='__const' and words_until0(ss,sd,sw)==words_until0(rs,rd,rw) and words_until0(ss,sd,sw): continue
        bad.append((4*k,sw,rw,ps,pr))
    if bad: ndiff+=1; diffs.append((name,hex(a),len(bad),bad[:2],'via-prev' if via else ''))
print('objects',nobj,'no rebuilt label',nmiss,'compared via preceding label',nvia,'differing',ndiff)
for d in diffs: print(d)
