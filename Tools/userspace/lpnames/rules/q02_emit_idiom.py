import re, os, sys
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'translator token-buffer emit idiom: translator[9] error code, [0xa] token data pointer, [0xb] token count, [0xc] capacity, malloc/realloc growth, write cursor and word pointers'
VARS = []
def whole(var): return None
def _any(ds, pat): return any(re.search(pat, d) for d in ds)
def name(var, k, defs, lines, ctx):
    if not any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines): return None
    ds = [d.strip().rstrip(';') for d in defs]
    if not ds: return None
    if _any(ds, r'^\(\w+ ?\*+\)\(param_1 \+ 0x28\)$') or _any(ds, r'^param_1 \+ 10$'): return 'tokenDataPtrAddr'
    if _any(ds, r'^\(undefined4 \*\)\(\w+ \* 4 \+ \*\w+\)$'): return 'tokenWritePtr'
    if var.startswith('pdVar'):
        for n, pats in ((1, (r'^\w+ \+ 1$', r'\(0x4\)$|0x4\)$')), (2, (r'^\w+ \+ 2$', r'0x8\)$')), (3, (r'^\w+ \+ 3$', r'0xc\)$')), (4, (r'^\w+ \+ 4$', r'0x10\)$'))):
            if _any(ds, pats[0]) or _any(ds, pats[1]): return 'tokenWord%dPtr' % n
    if all(re.match(r'^(?:\(\w+ ?\*?\))?_(?:malloc|realloc)\(', d) for d in ds): return 'allocation'
    if _any(ds, r'^\*\(int \*\)\(param_1 \+ 0x2c\)$|^param_1\[0xb\]$'): return 'tokenCount'
    if _any(ds, r'^\*\(uint \*\)\(param_1 \+ 0x30\)$|^param_1\[0xc\]$'): return 'tokenCapacity'
    if _any(ds, r'^\*\(int \*\)\(param_1 \+ 0x24\)$|^param_1\[9\]$'): return 'translatorError'
    return None
