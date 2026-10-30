import sys,glob,os
D='Userspace/ATIRadeonX1000GLDriver/ppc'
m={}
for t in glob.glob(D+'/names*.tsv'):
    for l in open(t,errors='surrogateescape'):
        c=l.rstrip('\n').split('\t')
        if len(c)>3 and c[0]=='func': m[c[2]]=c[1]
for l in sys.stdin:
    c=l.rstrip('\n').split('\t')
    if len(c)>2 and c[0] in('local','use') and c[1] in m: c[1]=m[c[1]]
    print('\t'.join(c))
