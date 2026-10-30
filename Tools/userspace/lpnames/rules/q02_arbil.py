import re, os, sys
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'ARB IL emitter family (arbEmitIl*): destination write mask [3] (w) component, token buffer growth through the emitter allocator object'
VARS = []
def whole(var): return None
def name(var, k, defs, lines, ctx):
    if not any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines): return None
    ds = [d.strip().rstrip(';').strip() for d in defs]
    if not ds: return None
    if all(re.search(r'ARB_allocator', d) for d in ds): return 'allocator'
    if all(re.match(r'^\w+\[3\]$', d) or d == '0' for d in ds) and any(re.match(r'^\w+\[3\]$', d) for d in ds): return 'dstMaskW'
    return None
