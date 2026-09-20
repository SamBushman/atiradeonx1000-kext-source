import sys,shutil,os
SCR='/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad'
old,new,out=sys.argv[1:4]
keep={l.split('\t')[0] for l in open(old+'/INDEX.tsv')}
os.makedirs(out,exist_ok=True)
rows=[l for l in open(new+'/INDEX.tsv') if l.split('\t')[0] in keep]
open(out+'/INDEX.tsv','w').write(''.join(rows))
for l in rows: a=l.split('\t')[0]; shutil.copy(new+'/'+a+'.txt',out+'/'+a+'.txt')
pass
print(len(rows),len(keep))
names={l.split('\t')[0]:l.rstrip('\n').split('\t')[2] for l in rows_} if False else None
