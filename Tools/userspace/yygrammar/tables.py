import sys, struct, json
sys.path.insert(0,'../')
import machoutil
m=machoutil.load('' + __import__('os').environ.get('GLPROG_DYLIB', 'libGLProgrammability.dylib') + '')
S={s['name']:s['value'] for s in m.syms}
order=['_yytranslate','_yyr1','_yyr2','_yydefact','_yydefgoto','_yypact','_yypgoto','_yytable','_yycheck']
addr=[S[n] for n in order]
ends=addr[1:]+[None]
T={}
for n,a,e in zip(order,addr,ends):
    if n=='_yytranslate':
        sz=e-a; T[n]=[x if x<128 else x-256 for x in m.read(a,sz)]
    elif e is None:
        T[n]=None
    else:
        sz=e-a; T[n]=list(struct.unpack('>%dh'%(sz//2), m.read(a,sz)))
# yycheck end: find section end
sec=m.sec_at(S['_yycheck']); 
print({k:(len(v) if v else None) for k,v in T.items()}, hex(sec['addr']+sec['size']-S['_yycheck']))
sz=sec['addr']+sec['size']-S['_yycheck']
T['_yycheck']=list(struct.unpack('>%dh'%(sz//2), m.read(S['_yycheck'],sz)))
print(len(T['_yycheck']))
json.dump(T,open('tables.json','w'))
