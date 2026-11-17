#!/usr/bin/env python3
"""Whole-pipeline differential for glprog: drive the REAL entry points (ShInitialize, ShConstructCompiler, ShCompile, ...) on a real shader text through the stock and the rebuilt image in the
Unicorn emulator, keeping the process state between the calls, and compare every step with trace_diff.compare (ordered call-outs / stores / reads, return values, callee-entry argument records
under TD_ENTRYARGS).  Every in-image function the pipeline reaches is thereby exercised on a valid object graph the real code built itself - the rows whose random inputs fault in every run.

usage: pipeline_diff.py STOCK REBUILT LEDGER --symmap F --nm F --funcs F --nargs F [--shader FILE] [--lang N] [--out DIR]
Env as trace_diff (TD_ENTRYARGS=1 TD_HEAP=1 TD_ARITY_FILE=...).  Writes DIR/<shader>.stock.cov (executed stock addresses, image-relative) and prints one verdict line per step."""
import sys, os, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import trace_diff as t

def main(argv):
    pos = []; opt = {'--symmap': None, '--nm': None, '--funcs': None, '--nargs': None, '--shader': None, '--lang': '0', '--out': '.', '--limit': '60000000'}; i = 0
    while i < len(argv):
        if argv[i] in opt: opt[argv[i]] = argv[i + 1]; i += 2
        else: pos.append(argv[i]); i += 1
    stock, reb, ledger = pos
    t._init(stock, reb, opt['--symmap'], opt['--nm'], ledger, opt['--funcs'], opt['--nargs'], 0, None)
    ss, sr = t._G['sims']['A']; S, R = t._G['S'], t._G['R']
    rows = {r['name'].lstrip('_'): r for r in t.read_ledger(ledger, S.bal, R.bal)}
    src = open(opt['--shader'], 'rb').read() + b'\0' if opt['--shader'] else b'void main() { gl_Position = ftransform(); }\0'
    arena = bytearray(t.ARENA_SIZE)
    SP, STR = t.ARENA + 0x1000, t.ARENA + 0x1100
    arena[0x1000:0x1004] = struct.pack('>I', STR); arena[0x1100:0x1100 + len(src)] = src
    arena = bytes(arena); limit = int(opt['--limit'])
    state = {}
    steps = [('ShInitialize', lambda: [], True),
             ('ShConstructCompiler', lambda: [int(opt['--lang']), 0], False),
             ('ShCompile', lambda: [state['h'], SP, 1, 0, 0], False)]
    cov = set(); allv = []
    for name, argf, reset in steps:
        r = rows[name]; args = argf()
        a = ss.run(r['stock'], args, [], [], arena, limit=limit, reset=reset)
        b = sr.run(r['reb'], args, [], [], arena, limit=limit, reset=reset)
        v, det = t.compare(a, b, 'i'); cov |= a[3]
        if os.environ.get('PD_DUMP'):
            for tag, run in (('stock', a), ('rebuilt', b)):
                with open(os.path.join(os.environ['PD_DUMP'], '%s.%s.calls' % (name, tag)), 'w') as f:
                    for k, e in enumerate(x for x in run[1] if x[0] == 'C'): f.write('%d\t%s\t%s\n' % (k, e[1], ','.join('%x' % (y.raw if hasattr(y, 'raw') else y) if isinstance(y if not hasattr(y, 'raw') else y.raw, int) else str(y) for y in e[2])))
        if os.environ.get('PD_WATCH'):
            wa = int(os.environ['PD_WATCH'])
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                print('  WATCH', name, tag, [(hex(sim.evpc.get(i, -1)) if hasattr(sim, 'evpc') else '?', e[0], e[3] if len(e) > 3 else None) for i, e in enumerate(run[1]) if e[0] in 'RW' and e[1] == ('IMG', wa)][:40], flush=True)
        if os.environ.get('PD_WATCH') and os.environ.get('PD_CTX') and name == 'ShInitialize':
            wa = int(os.environ['PD_WATCH']); n = int(os.environ['PD_CTX'])
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                idx = [i for i, e in enumerate(run[1]) if e[0] in 'RW' and e[1] == ('IMG', wa)]
                with open(os.path.join(os.environ['PD_DUMP'], 'ctx.%s' % tag), 'w') as f:
                    for i in range(idx[0] - 40, idx[min(n, len(idx) - 1)] + 6):
                        e = run[1][i]; f.write('%d %s %s\n' % (i, hex(sim.evpc.get(i, -1)), repr(e)[:160]))
        if os.environ.get('PD_SEGDIFF'):
            sga, _f1 = t.segments(a[1]); sgb, _f2 = t.segments(b[1]); k = 0
            print('  SEGDIFF', name, 'segments', len(sga), len(sgb), flush=True)
            for i, (x, y) in enumerate(zip(sga, sgb)):
                d = t.wdiff(x[1], y[1])
                if d and not t.wbeq(x[3], y[3]):
                    ks = sorted((q for q in set(x[3]) | set(y[3]) if x[3].get(q) != y[3].get(q)), key=repr)
                    print('  SEGDIFF', name, i, 'call', (x[0] or ('start',))[:2], 'differing final bytes', [(q, x[3].get(q), y[3].get(q)) for q in ks[:6]], 'nbytes', len(ks), flush=True)
                    k += 1
                    if k >= int(os.environ['PD_SEGDIFF']): break
        if os.environ.get('PD_WATCHABS') and name == 'ShInitialize':
            wa = int(os.environ['PD_WATCHABS'])
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                print('  WABS', tag, [(i, hex(sim.evpc.get(i, -1)), e[0], e[2], e[3] if e[0] != 'C' else None) for i, e in enumerate(run[1]) if e[0] in 'RW' and isinstance(e[1], int) and e[1] <= wa < e[1] + e[2]][:40], flush=True)
        if os.environ.get('PD_WATCHVAL') and name == 'ShInitialize':
            vals = {int(x) for x in os.environ['PD_WATCHVAL'].split(',')}
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                print('  WVAL', tag, [(i, hex(sim.evpc.get(i, -1)), e[0], e[1], e[2], e[3]) for i, e in enumerate(run[1]) if e[0] in 'RW' and len(e) > 3 and (e[3].raw if hasattr(e[3], 'raw') else e[3]) in vals][:30], flush=True)
        if os.environ.get('PD_FOLLOW') and name == 'ShInitialize':
            val = int(os.environ['PD_FOLLOW'])
            addr = next(e[1] for e in a[1] if e[0] == 'W' and len(e) > 3 and isinstance(e[1], int) and (e[3].raw if hasattr(e[3], 'raw') else e[3]) == val)
            print('  FOLLOW addr', addr, flush=True)
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                print('  FOL', tag, [(i, hex(sim.evpc.get(i, -1)), e[0], e[2], hex(e[3].raw if hasattr(e[3], 'raw') else e[3])) for i, e in enumerate(run[1]) if e[0] in 'RW' and isinstance(e[1], int) and e[1] <= addr < e[1] + e[2] and isinstance(e[3] if not hasattr(e[3],'raw') else e[3].raw, int)][:40], flush=True)
        if os.environ.get('PD_ENT'):
            cn = os.environ['PD_ENT']
            def lrs(sim, run):
                out = []; k = 0
                for n_, it in sim.ent:
                    for i_, ws_, tr_, cap_ in it:
                        out.append((n_, i_, ws_, tr_[1] - sim.slide, tr_[0])); k += 1
                return [o for o in out if o[0] == cn]
            la, lb = lrs(ss, a), lrs(sr, b)
            print('  ENT', name, cn, 'stock', len(la), 'rebuilt', len(lb), flush=True)
            for k_, (x, y) in enumerate(zip(la, lb)):
                if x[2] != y[2]:
                    print('  ENTDIFF', k_, 'stock lr', hex(x[3]), 'rebuilt lr', hex(y[3]), 'p', x[4], y[4], 'stock', [getattr(w, 'raw', w) for w in x[2]], 'rebuilt', [getattr(w, 'raw', w) for w in y[2]], flush=True)
                    break
        if os.environ.get('TD_SWATCH') and name == 'ShInitialize':
            flt = {'stock': int(os.environ.get('PD_SWS', 0)), 'rebuilt': int(os.environ.get('PD_SWR', 0))}
            for tag, sim in (('stock', ss), ('rebuilt', sr)):
                L = [x for x in sim.sw if x[1] <= flt[tag] < x[1] + abs(x[2])]
                tgt = int(os.environ.get('PD_SWV' + tag[0], 0)); k0 = next((i for i, x in enumerate(L) if x[3] == tgt and x[2] == 4), len(L))
                print('  SW', tag, 'n', len(L), 'first-target-idx', k0, [(hex(x[0]), hex(x[1]), x[2], hex(x[3]), x[4]) for x in L[max(0, k0 - 8):k0 + 3]], flush=True)
        if a[0] != 'RET' or b[0] != 'RET': print('  FAULTPC stock', hex(ss.fpc or 0), 'rebuilt', hex(sr.fpc or 0), flush=True)
        if os.environ.get('PD_ENTALL'):
            def recs(sim):
                d = {}
                for n_, it in sim.ent:
                    d.setdefault(n_, []).append(it)
                return d
            lrmap = lambda sim: {}
            def flat(sim):
                out = {}; k = 0
                for n_, it in sim.ent:
                    items = tuple((i_, ws_, (tr_[2] + 3) // 4, cap_) for i_, ws_, tr_, cap_ in it)
                    out.setdefault(n_, []).append((items, it[0][2][1] - sim.slide if it else 0))
                return out
            fa, fb = flat(ss), flat(sr); summ = {}; skipped = 0
            for n_ in sorted(set(fa) & set(fb)):
                if len(fa[n_]) != len(fb[n_]) or n_.lstrip('_').startswith(t.VARARG_CALLEES): skipped += 1; continue
                rest = list(fb[n_])
                for items, lr in fa[n_]:
                    j = next((j for j, (o, _l) in enumerate(rest) if t.ent_match(items, o)), None)
                    if j is None:
                        o, lr2 = rest[0] if rest else ((), 0)
                        dy = {i_: ws_ for i_, ws_, e_, c_ in o}
                        idx = [(i_, [q for q in range(min(len(ws_), len(dy.get(i_, ())))) if ws_[q] != dy[i_][q]][:4]) for i_, ws_, e_, c_ in items if i_ in dy]
                        wd = [(i_, [(q, str(ws_[q]), str(dy[i_][q])) for q in range(min(len(ws_), len(dy.get(i_, ())))) if ws_[q] != dy[i_][q]][:4]) for i_, ws_, e_, c_ in items if i_ in dy]
                        key = (n_, hex(lr), hex(lr2), str(idx) if n_ != 'TIntermAggregate__traverse' else str(wd)); summ[key] = summ.get(key, 0) + 1
                    else: rest.pop(j)
            print('  ENTALL', name, 'callees', len(set(fa) & set(fb)), 'skipped(count differs/varargs)', skipped, 'distinct mismatches', len(summ), flush=True)
            for k_, v_ in sorted(summ.items(), key=lambda x: -x[1])[:60]: print('  ENTALLROW', v_, k_, flush=True)
        print('%-22s stock %s r3=%#x  rebuilt %s r3=%#x  events %d/%d  verdict %s %s' % (name, a[0], a[2]['r3'], b[0], b[2]['r3'], len(a[1]), len(b[1]), v, det[:300]), flush=True)
        if name == 'ShConstructCompiler': state['h'] = a[2]['r3']
        if a[0] != 'RET' or b[0] != 'RET': break
    os.makedirs(opt['--out'], exist_ok=True)
    base = os.path.splitext(os.path.basename(opt['--shader'] or 'default'))[0]
    with open(os.path.join(opt['--out'], base + '.stock.cov'), 'w') as f: f.write('\n'.join('%x' % x for x in sorted(cov)) + '\n')
    print('stock instructions covered: %d' % len(cov))

if __name__ == '__main__': main(sys.argv[1:])
