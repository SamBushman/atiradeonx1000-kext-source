import re,sys,os
# uses.py bin part cname name... : print C lines (trimmed) mentioning each name inside the function
b,part,cn=sys.argv[1:4];names=sys.argv[4:]
d=os.path.expanduser(f'~/wt/r19/Userspace/{b}/ppc')
t=open(f'{d}/{part}.c',errors='replace').read()
for m in re.finditer(r'(?:^|\n)/\* (\S+) @ (0x[0-9a-f]+) \((\d+) bytes\) \*/\n',t):
    if m.group(1)==cn:
        e=t.find('\n/* ',m.end());code=t[m.end():e if e>0 else None];break
for n in names:
    print('--',n)
    for l in code.split('\n'):
        if re.search(r'(?<![A-Za-z0-9_])'+re.escape(n)+r'(?![A-Za-z0-9_])',l) and not re.match(r'\s*[A-Za-z_ ]+\s*\**\s*'+re.escape(n)+r'\s*(\[\d+\])?;',l):
            print('   ',l.strip()[:230])
