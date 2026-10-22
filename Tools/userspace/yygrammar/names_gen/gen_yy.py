import sys, re, collections
sys.path.insert(0, '/home/sam/g5logs/R1b')
import yyinfo as y
lines = y.lines
WS = y.all_webs()
idx = {}                                   # (var, line) -> W
for w in WS:
    for l in w.lines: idx[(w.v, l)] = w
def web_at(v, ln): return idx.get((v, ln))
def setname(w, name, tier, ev):
    if w is None: return False
    if w.name is None: w.name, w.tier, w.ev = name, tier, ev; return True
    return False
STAT = collections.Counter()

# ---- idiom 1: std::string rep refcount release (lwarx/stwcx decrement of the refcount word at string data - 4) ---------------------------------
def idiom_refcount():
    cand = collections.defaultdict(lambda: collections.defaultdict(set))     # W -> role -> idiom def lines
    EV = 'std::string COW release idiom: P = string data pointer - 4 (the _Rep refcount word), old = *P, then lwarx/stwcx decrement via storeWordConditionalIndexed(old - 1, 0, P)'
    for i, l in enumerate(lines):
        m = re.match(r'\s*(\w+) = (\w+) \+ -4;$', l)
        if not m: continue
        P = m.group(1)
        for j in range(i + 1, min(i + 14, len(lines))):
            mm = re.search(r'(\w+) = \(?[\w ]*\*?\)?storeWordConditionalIndexed\(.*?,0,%s\)' % re.escape(P), lines[j])
            if mm:
                N = mm.group(1); O = None
                for k in range(i + 1, j):
                    m3 = re.match(r'\s*(\w+) = \*\(\w[\w ]*\*+\)%s;$' % re.escape(P), lines[k])
                    if m3: O = m3.group(1); break
                for (v, ln, role) in ((P, i, 'refCountPtr'), (O, k if O else None, 'oldRefCount'), (N, j, 'newRefCount')):
                    if v and ln is not None:
                        w = web_at(v, ln)
                        if w: cand[w][role].add(ln)
                break
    for w, roles in cand.items():
        if len(roles) != 1: continue
        role, dl = next(iter(roles.items()))
        if set(w.deflines) <= dl:
            STAT['refcount'] += setname(w, role, 'INFERRED', EV)
idiom_refcount()
import rules1 as r1
exec(open('/home/sam/g5logs/R1b/pass2.py').read())
if __name__ == '__main__':
    done = [w for w in WS if w.name]
    print('named webs', len(done), 'occurrences', sum(y.web_size(w) for w in done), 'of', sum(y.web_size(w) for w in WS))
    print(STAT)
