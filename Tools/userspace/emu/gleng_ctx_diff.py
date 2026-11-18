#!/usr/bin/env python3
"""GLEngine differential on a REAL context: build the engine context with the image's own `_gliCreateContext` (stock and rebuilt, Unicorn), then call one function of the engine
with the context as argument and compare with trace_diff.compare.  The random inputs of the census make most context-taking functions fault at once (no valid context); here the context
is the one both images build themselves.  The renderer plugin the engine expects is a stand-in object (a linked-list node whose id is 0x400 and whose dispatch table slots are
call-outs that return 0: every call the engine makes into the plugin is recorded and compared), the pixel-format list has one node, and the two context-creation parameters are zeroed arena objects.
Every target gets a FRESH context (state reset, context rebuilt) so destructive functions (_gleFree*, _gleTerminateContext) do not disturb the next row.

usage: gleng_ctx_diff.py STOCK REBUILT PLAIN_LEDGER --symmap F --nm F --funcs F --nargs F --names F|name,name [--out DIR] [--arg2 N] [--limit N]
Env as trace_diff (TD_ENTRYARGS=1 TD_HEAP=1 TD_BIND_SELF=1).  Prints one line per target: verdict, return class, events, and writes DIR/<name>.stock.cov when --out is given."""
import sys, os, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import trace_diff as t

PREINIT = ('_glePreInitGlobals', '_glePreInitTOC', '_glePreInitVectorTOC', '_glePreInitNormalize', '_glePreInitProjectionTransformFunc', '_glePreInitModelviewTransformFunc', '_glePreInitNormalTransformFunc', '_glePreInitVertexSubmitFunc')

def main(argv):
    pos = []; opt = {'--symmap': None, '--nm': None, '--funcs': None, '--nargs': None, '--names': None, '--out': None, '--limit': '30000000', '--ctxsetup': None}; i = 0
    while i < len(argv):
        if argv[i] in opt: opt[argv[i]] = argv[i + 1]; i += 2
        else: pos.append(argv[i]); i += 1
    stock, reb, ledger = pos
    t._init(stock, reb, opt['--symmap'], opt['--nm'], ledger, opt['--funcs'], opt['--nargs'], 0, None)
    ss, sr = t._G['sims']['A']; S, R = t._G['S'], t._G['R']
    nm = {}
    for l in open(opt['--nm']):
        p = l.split()
        if len(p) == 3 and p[1] in 'tT': nm.setdefault(p[2], int(p[0], 16))
    fl = {}
    for l in open(opt['--funcs']):
        p = l.rstrip('\n').split('\t')
        if len(p) > 3 and p[0].startswith('0x'): fl[p[2]] = (int(p[0], 16) - S.bal, int(p[1]))
    gl = {}
    for sim_, im in ((ss, S), (sr, R)):
        gl[id(sim_)] = {n: a for a, n in im.syms if n in ('_glep_plugin_head', '_gl_list')}
    nargs = {}
    for l in open(opt['--nargs']):
        p = l.split()
        if len(p) >= 2 and p[1].isdigit(): nargs[p[0].lstrip('_')] = int(p[1])
    names = [n for n in (open(opt['--names']).read().split() if os.path.exists(opt['--names']) else opt['--names'].split(','))]
    A = t.ARENA; PL = 0x1000; PF = 0x2000; OUT = 0x2400; P4 = 0x3000; P5 = 0x3400
    FREE = t.CALLOUT + 16 * ss.ids['_free']
    arena = bytearray(t.ARENA_SIZE)
    def put(off, b): arena[off:off + len(b)] = b
    put(PL + 0x104, struct.pack('>I', 0x400))
    for o in range(0x114, 0x114 + 0xf4, 4): put(PL + o, struct.pack('>I', FREE))
    put(PF, struct.pack('>III', 0, 0x00020400, 0x40))
    if os.environ.get('GC_PTRFILL'):      # GC_PTRFILL=1: every word of the six argument objects (A+0x4000+0x800*k) points at the next argument object, so a NULL field read from one is a valid object
        for k in range(6):
            for o in range(0, 0x800, 4): put(0x4000 + 0x800 * k + o, struct.pack('>I', A + 0x4000 + 0x800 * ((k + 1) % 6) + (o & 0x3f0)))
    arena = bytes(arena)
    limit = int(opt['--limit'])
    def run2(name, args, reset, sw=()):
        s = fl[name][0]; r = nm[name]
        return ss.run(s, args, [], list(sw), arena, limit=limit, reset=reset), sr.run(r, args, [], list(sw), arena, limit=limit, reset=reset)
    for name in names:
        if name not in fl or name not in nm: print('%-40s MISSING stock=%s rebuilt=%s' % (name, name in fl, name in nm), flush=True); continue
        a, b = run2('_gleDCBFree', [0], True)                                        # state reset (trivial call)
        for sim, im in ((ss, S), (sr, R)):
            g = gl[id(sim)]
            sim.uc.mem_write(g['_glep_plugin_head'] + sim.slide, struct.pack('>I', A + PL)); sim.uc.mem_write(g['_gl_list'] + sim.slide, bytes(4))
        for pf in PREINIT:                                                           # the engine's own module initialisation (the first part of the function that returns the version words): fills the global dispatch/transform tables
            if pf in fl and pf in nm:
                a, b = run2(pf, [0], False); vp, dp = t.compare(a, b, 'i')
                if vp not in ('IDENTICAL', 'REORDERED'): print('    preinit %s %s %s' % (pf, vp, dp[:160]), flush=True)
        a, b = run2('_gliCreateContext', [A + OUT, A + PF, 0, A + P4, A + P5, 0, 0, 0], False)
        v0, _d = t.compare(a, b, 'i')
        ctx = int.from_bytes(ss.uc.mem_read(A + OUT, 4), 'big'); ctx_r = int.from_bytes(sr.uc.mem_read(A + OUT, 4), 'big')
        if not ctx or ctx != ctx_r: print('%-40s NOCTX stock=%x rebuilt=%x (%s)' % (name, ctx, ctx_r, v0), flush=True); continue
        n = nargs.get(name.lstrip('_'), 1)
        if os.environ.get('GC_PTRARGS'): n = 8 if os.environ['GC_PTRARGS'] == '2' else max(n, 3)      # GC_PTRARGS=2: all eight argument registers      # GC_PTRARGS=1: arguments 2.. are zeroed arena objects (functions taking a second struct pointer fault on a junk value otherwise)
        args = [ctx] + [(A + 0x4000 + 0x800 * k) if os.environ.get('GC_PTRARGS') else 0 for k in range(max(0, min(n, 8) - 1))]
        if os.environ.get('GC_SMALL') and any(x in name for x in os.environ['GC_SMALL'].split(',')): args = [ctx, 10, 20, 30, 40, 50, 60, 70]      # GC_SMALL=sub,sub: rows whose scalar arguments are bytes/small counts (an arena address as a GLubyte is out of contract)
        for spec in os.environ.get('GC_ROWARGS', '').split(';'):      # GC_ROWARGS='name=P,1,2;name2=...': explicit arguments after the context (P/Q/R = zeroed argument objects, otherwise decimal)
            if spec.startswith(name + '='): args = [ctx] + [{'P': A + 0x4000, 'Q': A + 0x4800, 'R': A + 0x5000}.get(x, None) if x in 'PQR' else int(x) for x in spec.split('=', 1)[1].split(',')]
        sw = ()
        for spec in os.environ.get('GC_ROWSTACK', '').split(';'):      # GC_ROWSTACK='name=P,0;...': the stack words (9th argument on) of a row
            if spec.startswith(name + '='): sw = tuple({'P': A + 0x4000, 'Q': A + 0x4800, 'R': A + 0x5000}[x] if x in 'PQR' else int(x) for x in spec.split('=', 1)[1].split(','))
        a, b = run2(name, args, False, sw)
        v, det = t.compare(a, b, 'i')
        print('%-40s %-14s stock %s rebuilt %s events %d/%d cov %d  %s' % (name, v, a[0] if not isinstance(a[0], int) else hex(a[0]), b[0] if not isinstance(b[0], int) else hex(b[0]), len(a[1]), len(b[1]), len(a[3]), det[:200]), flush=True)
        if os.environ.get('GC_RDDIFF') and v in ('READ_SET', 'FAULT_PARTIAL'):      # GC_RDDIFF=1: every one-sided read of each segment, in the format rd_check.py classifies (load-width class)
            sga, _f1 = t.segments(a[1]); sgb, _f2 = t.segments(b[1])
            for sg in range(min(len(sga), len(sgb))):
                xr, yr = sga[sg][2], sgb[sg][2]
                def ov(r, k): return [q for q in r if isinstance(q[0], int) and isinstance(k[0], int) and q[0] < k[0] + k[1] and k[0] < q[0] + q[1]]
                for tag, r1, r2 in (('stock-only', xr, yr), ('rebuilt-only', yr, xr)):
                    for k in sorted((q for q in r1 if q not in r2), key=repr)[:12]:
                        print('  RD', name, tag, k, 'values', [getattr(w, 'raw', w) for w in r1[k]][:3], 'other image overlapping', [(q, [getattr(w, 'raw', w) for w in r2[q]][:2]) for q in ov(r2, k)], flush=True)
        if os.environ.get('GC_EVCTX'):      # GC_EVCTX=name:ADDR (decimal): the events around every access of ADDR in both images, with pcs (stock pcs are image offsets, rebuilt pcs are image addresses)
            nn, ad = os.environ['GC_EVCTX'].split(':'); ad = int(ad)
            if nn == name and ad == -1:      # ADDR -1: the last 14 events of both images with pcs (fault sites)
                for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                    for j in range(max(0, len(run[1]) - 14), len(run[1])): print('  EVC', tag, j, hex(sim.evpc.get(j, -1)), str(run[1][j])[:140], flush=True)
            elif nn == name:
                for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                    for i, e in enumerate(run[1]):
                        if e[0] in 'RW' and isinstance(e[1], int) and e[1] <= ad < e[1] + e[2]:
                            for j in range(max(0, i - 6), min(len(run[1]), i + 4)): print('  EVC', tag, j, hex(sim.evpc.get(j, -1)), str(run[1][j])[:140], flush=True)
                            print('  EVC ----', flush=True)
        if a[0] == 'FAULT' or b[0] == 'FAULT': print('    fault stock %s rebuilt %s; last stock events %s' % ([e for e in a[1] if e[0] == 'F'][:1], [e for e in b[1] if e[0] == 'F'][:1], [(hex(ss.evpc.get(i, -1)), str(e)[:70]) for i, e in enumerate(a[1]) if i >= len(a[1]) - 3]), flush=True)
        if opt['--out']:
            os.makedirs(opt['--out'], exist_ok=True)
            open(os.path.join(opt['--out'], name + '.stock.cov'), 'w').write('\n'.join('%x' % x for x in sorted(a[3])) + '\n')

if __name__ == '__main__': main(sys.argv[1:])
