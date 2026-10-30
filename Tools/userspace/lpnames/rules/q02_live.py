import re, os, sys
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
VARS=['in_r8','in_r7']
def name(var,k,defs,lines,ctx):
    if any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines): return 'LIVE'
    return None
