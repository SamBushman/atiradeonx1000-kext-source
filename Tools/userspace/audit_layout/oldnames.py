import sys,re,glob
fn=sys.argv[1].split('|')
rows=[]
for f in glob.glob('names_*.tsv'):
    for l in open(f,errors='replace'):
        p=l.rstrip('\n').split('\t')
        if len(p)>=4 and p[0]=='local' and p[1] in fn: rows.append((p[2],p[3]))
for o,n in sorted(set(rows)):
    m=re.match(r'(?:local|auStack|uStack|iStack|cStack|bStack|sStack|fStack|dStack|puStack|pcStack|pfStack)_([0-9a-f]+)$',o)
    print(f'{("-0x"+m.group(1)) if m else "      ":>7} {o:14} -> {n}')
