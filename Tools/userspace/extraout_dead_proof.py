#!/usr/bin/env python3
"""Static proof that the 12 DOCUMENTED extraout_* reads of the GLEngine corpus (#296) are dead.

Reads the STOCK GLEngine Mach-O (thin ppc, __TEXT at vmaddr 0 / fileoff 0) and the corpus ledger
(addr size name ...), disassembles every function with capstone and computes:

 1. FPR live-in (f1..f13) of every function: an FPR is live-in when some path from the entry reads it
    before any write.  Direct calls use the callee's live-in; every call clobbers f0..f13.  Indirect
    calls (bctrl) are NOT counted as readers (see 3).  Jump tables (bctr) reach every instruction.
 2. For the sites whose extraout_f1 feeds a call: every direct callee reached from the site's function
    (transitive closure) must have f1 not live-in.
 3. Indirect call sites (hooks) in that closure: the stock compiler loads every FP argument right
    before the call, so a hook receives f1 only where an FPR is defined in the argument window.
 4. For the 'leftover r3' sites (ledger ret v): every direct caller of the stock-void function is
    checked for a read of r3 after the call before r3 is redefined; tail callers must be void too.

usage: extraout_dead_proof.py STOCK_GLEngine LEDGER.tsv [FPRLEDGER_with_ret_types.tsv]
"""
import re, struct, sys
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN

F1_SITES = ['_gleUpdateState', '_glCheckFramebufferStatusEXT_Exec', '_glCopyConvolutionFilter1D_Exec',
            '_glCopyConvolutionFilter2D_Exec', '_glMultiDrawElementArrayAPPLE_Exec',
            '_gleInitDrawPixelsShareObject', '_gleDrawPixelsSaveState', '_gleDrawPixelsRestoreState']
R3_FUNCS = ['_gleUpdateTextureParams', '_gleFreeOrphans', '_gleExecuteClippedVertexArray']
FR = re.compile(r'\bf(\d+)\b'); RE3 = re.compile(r'\br3\b'); ALLF = set(range(1, 14))
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)

def usedef(i):
    m = i.mnemonic.rstrip('.'); ops = [o.strip() for o in i.op_str.split(',')]
    regs = [[int(x) for x in FR.findall(o)] for o in ops]; use = set(); df = set()
    if not any(regs): return use, df
    if m.startswith('lf'): df |= set(regs[0])
    elif m.startswith('stf'): use |= set(regs[0])
    elif m in ('fcmpu', 'fcmpo'):
        for r in regs[1:]: use |= set(r)
    elif m == 'mffs': df |= set(regs[0])
    elif m == 'mtfsf': use |= set(regs[1]) if len(regs) > 1 else set()
    elif m == 'mtfsfi': pass
    else:
        df |= set(regs[0])
        for r in regs[1:]: use |= set(r)
    return use, df

def r3use(i):
    m = i.mnemonic; ops = [o.strip() for o in i.op_str.split(',')]
    if not RE3.search(i.op_str): return None
    if m.startswith('st'): return 'read'
    if m in ('bctr', 'bctrl', 'blr'): return 'read'
    rest = ','.join(ops[1:])
    if ops[0] == 'r3' and m not in ('cmpwi', 'cmplwi', 'cmpw', 'cmplw', 'mtctr', 'mtlr'):
        return 'read' if RE3.search(rest) else 'def'
    return 'read'

def main():
    d = open(sys.argv[1], 'rb').read(); fn = {}; byaddr = {}
    for l in open(sys.argv[2]):
        p = l.rstrip('\n').split('\t')
        if len(p) >= 3 and p[0].startswith('0x'): fn[p[2]] = (int(p[0], 16), int(p[1])); byaddr[int(p[0], 16)] = p[2]
    cache = {}
    def dis(n):
        if n not in cache:
            a, sz = fn[n]; cache[n] = list(md.disasm(d[a:a + sz], a))
        return cache[n]
    def tgt(i):
        s = i.op_str.split(',')[-1].strip()
        return int(s, 16) if re.fullmatch(r'0x[0-9a-f]+', s) else None
    live = {n: set() for n in fn}
    def analyze(n):
        ins = dis(n); idx = {i.address: k for k, i in enumerate(ins)}; nn = len(ins); info = []
        for k, i in enumerate(ins):
            m = i.mnemonic; u, df = usedef(i); t = tgt(i) if m.startswith('b') else None
            if m in ('bl', 'bla'):
                cn = byaddr.get(t); u = u | (live.get(cn, set()) if cn else set())
                df = df | set(range(14)); s = [k + 1]
            elif m in ('bctrl', 'blrl'): df = df | set(range(14)); s = [k + 1]
            elif m == 'b':
                if t in idx: s = [idx[t]]
                else:
                    cn = byaddr.get(t); u = u | (live.get(cn, set()) if cn else set()); s = []
            elif m in ('blr',): s = []
            elif m.startswith('bctr') or m.startswith('bcctr'): s = list(range(nn))
            elif m.startswith('b'):
                s = [k + 1] + ([idx[t]] if t in idx else [])
            else: s = [k + 1]
            info.append((u, df, s))
        L = [set() for _ in range(nn)]; ch = True
        while ch:
            ch = False
            for k in range(nn - 1, -1, -1):
                u, df, s = info[k]; o = set()
                for x in s:
                    if x < nn: o |= L[x]
                v = u | (o - df)
                if v != L[k]: L[k] = v; ch = True
        return (L[0] & ALLF) if nn else set()
    while True:
        ch = False
        for n in fn:
            l = analyze(n)
            if l != live[n]: live[n] = l; ch = True
        if not ch: break
    print('functions analysed: %d; with any FPR live-in: %d; with f1 live-in: %d' %
          (len(fn), sum(1 for v in live.values() if v), sum(1 for v in live.values() if 1 in v)))
    def callees(f):
        r = set()
        for i in dis(f):
            if i.mnemonic in ('bl', 'b'):
                n = byaddr.get(tgt(i))
                if n and n != f: r.add(n)
        return r
    clos = {}; todo = set()
    for f in F1_SITES: todo |= callees(f)
    while todo:
        n = todo.pop()
        if n in clos: continue
        clos[n] = callees(n); todo |= {c for c in clos[n] if c not in clos}
    print('\n== f1 sites: closure of direct callees: %d functions' % len(clos))
    for f in F1_SITES:
        print('  %-40s own f1 live-in: %s' % (f, 1 in live[f]))
    readers = sorted(n for n in clos if live[n])
    print('  callee-closure functions with any FPR live-in:', readers)
    ind = []
    for n in sorted(clos):
        ins = dis(n)
        for k, i in enumerate(ins):
            if i.mnemonic in ('bctrl', 'blrl'):
                j = k - 1; fp = []
                while j >= 0 and k - j <= 40:
                    q = ins[j]
                    if q.mnemonic.startswith('b'): break
                    u, df = usedef(q)
                    if u or df: fp.append('%x %s %s' % (q.address, q.mnemonic, q.op_str))
                    j -= 1
                ind.append((n, i.address, fp))
    print('  indirect (hook) call sites in the closure: %d; with FP instructions in the argument window: %d'
          % (len(ind), sum(1 for x in ind if x[2])))
    for n, a, fp in ind:
        if fp: print('     %s 0x%x: %s' % (n, a, fp[:4]))
    print('\n== r3 (stock-void) functions: direct callers')
    tg = {fn[t][0]: t for t in R3_FUNCS}
    for nm in fn:
        ins = dis(nm)
        for k, i in enumerate(ins):
            if i.mnemonic in ('bl', 'b') and tgt(i) in tg:
                if i.mnemonic == 'b': res = 'tail call (caller must be void)'
                else:
                    res = 'no r3 use in next 12 instrs'
                    for j in ins[k + 1:k + 12]:
                        u = r3use(j)
                        if u: res = '%s @%x %s %s' % (u, j.address, j.mnemonic, j.op_str); break
                        if j.mnemonic in ('bl', 'blr', 'b', 'bctr', 'bctrl'): res = 'next control transfer %s without r3 use' % j.mnemonic; break
                print('  %-28s <- %-40s 0x%x : %s' % (tg[tgt(i)], nm, i.address, res))
    for t in R3_FUNCS:
        a = struct.pack('>I', fn[t][0]); p = d.find(a); hits = []
        while p >= 0: hits.append(p); p = d.find(a, p + 1)
        print('  raw 4-byte references to %s in the file: %s (__DATA is 0x110000..0x114000)' % (t, [hex(x) for x in hits]))
main()
