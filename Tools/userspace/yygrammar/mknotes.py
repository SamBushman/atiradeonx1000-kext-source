import re, json, sys, collections
exec(open('gl.py').read().replace('print(len(TOK))',''))
exec(open('rules.py').read())
G2=[]
for l,rhs in G:
    for x in rhs:
        if x.startswith('@'): G2.append((x,[]))
    G2.append((l,rhs))
G=G2
T=json.load(open('tables.json')); r1=T['_yyr1']
NT0=95
nt_name={}
for i,(l,rhs) in enumerate(G,1): nt_name.setdefault(r1[i],l)
P='../../../Userspace/libGLProgrammability/ppc/part_006.c'
L=open(P).read().split('\n')
start=next(i for i,l in enumerate(L) if l.startswith('/* yyparse @'))
cases=collections.OrderedDict()
cur=[]
for i in range(start,len(L)):
    m=re.match(r'^  case (0x[0-9a-f]+|\d+):$',L[i])
    if m: cases.setdefault(int(m.group(1),0),i+1)
    if L[i].startswith('/* ') and i>start+5 and '@' in L[i]: break
out=[]
out.append("# yyparse grammar (libGLProgrammability, Tiger PPC) - recovered from the binary's bison tables\n")
out.append("""**How this was recovered (all of it checkable):**
- The bison tables `yytranslate, yyr1, yyr2, yydefact, yydefgoto, yypact, yypgoto, yytable, yycheck` sit in `__TEXT,__const` (symbols `_yytranslate` 0x97c3576c ... `_yycheck` 0x97c36c6a; read with `Tools/userspace/machoutil.py`). Dimensions: 95 internal tokens (`YYNTOKENS`), 74 nonterminals, 215 rules (+ rule 0), 334 states, `YYLAST` 1263, 350 external token codes.
- `yyr2[r]` (rule length) and `yyr1[r]` (LHS number) for all 215 rules reproduce, rule for rule, the GLSL grammar of the 3Dlabs `glslang.y` front end (the ATI compiler descends from it): 215/215 lengths and a consistent LHS numbering (same LHS -> same number, different LHS -> different number). The ATI build differs from stock 3Dlabs in two extra sampler tokens (`sampler2DRect`, `sampler2DRectShadow`, internal tokens 42 and 43, +2 `type_specifier` rules) which the table counts (95 tokens, 26 `type_specifier` alternatives) force.
- The right-hand sides were then checked against the LALR automaton rebuilt from the tables (shift/goto edges from `yypact/yytable/yycheck`, `yypgoto/yydefgoto`): for each rule the last RHS symbol equals the accessing symbol of every state that reduces it, and where explicit predecessor edges exist (110 rules) the whole RHS path exists; 0 of 215 rules fail. 105 rules reach only their last symbol because their predecessors are default-goto states. (Scripts: `Tools/userspace/yygrammar/` in this branch.)
- Token and nonterminal NAMES are the 3Dlabs names, not read from the binary (this build has no `yytname`); the tier is INFERRED for names, CONFIRMED for the rule shapes.
- Mid-rule actions are the empty rules 177/178 (compound_statement scope open/close), 193 (while), 195 (do), 197 (for), 214 (function body); bison numbers them before the rule that contains them.
- yyparse's action switch is `switch(rule)`: `case N` is rule N (`case 0xbb` etc. are the hex rule numbers, shared tails `switchD_97ba39c8_caseD_*` are the default action `$$ = $1`).

## Rule table: rule | production | `case` line in part_006.c
""")
out.append("| rule | production | case line (part_006.c) | string literals in the action (evidence) |\n|---|---|---|---|\n")
order=sorted(cases.items(), key=lambda kv: kv[1])
span={}
for k,(c,ln) in enumerate(order):
    end=order[k+1][1] if k+1<len(order) else ln+400
    span[c]=(ln,end)
def lits(c):
    if c not in span: return ''
    a,b=span[c]; t='\n'.join(L[a-1:b-1])
    xs=[]
    for m in re.finditer(r'"((?:\\.|[^"\\])*)"',t):
        v=m.group(1)
        if v and v not in xs and len(v)>1 and not v.startswith('__Z'): xs.append(v)
    return '; '.join('`%s`'%x.replace('|','\\|')[:60] for x in xs[:4])
for i,(l,rhs) in enumerate(G,1):
    names=[]
    for x in rhs:
        names.append(x)
    ln=cases.get(i,'(default action `$$ = $1`)' if len(rhs)>=1 else '(no `case`: empty action)')
    out.append("| %d | `%s : %s` | %s | %s |\n"%(i,l,' '.join(names) if names else '/* empty */',ln,lits(i)))
open('../../../Userspace/libGLProgrammability/ppc/notes_yyparse_grammar.md','w').write(''.join(out))
print(len(cases))
