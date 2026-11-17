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
    shaders = {'v': b'uniform mat4 mvp; attribute vec4 pos; attribute vec2 uv; varying vec2 vuv; void main() { gl_Position = mvp * pos; vuv = uv; }',
               'f': b'uniform sampler2D tex; uniform vec4 tint; varying vec2 vuv; void main() { gl_FragColor = texture2D(tex, vuv) * tint; }'}
    if opt['--shader']: shaders['v'] = open(opt['--shader'], 'rb').read()
    # arena layout (persistent across the session): 0x1000.. pointer tables, 0x2000 vertex text, 0x3000 fragment text, 0x4000 names, 0x5000 out words, 0x6000 out buffer
    arena = bytearray(t.ARENA_SIZE); A = t.ARENA
    def put(off, b): arena[off:off + len(b)] = b
    put(0x2000, shaders['v'] + b'\0'); put(0x3000, shaders['f'] + b'\0'); put(0x4000, b'mvp\0'); put(0x4010, b'tex\0'); put(0x4020, b'pos\0'); put(0x4030, b'tint\0')
    put(0x1000, struct.pack('>I', A + 0x2000)); put(0x1010, struct.pack('>I', A + 0x3000))
    limit = int(opt['--limit'])
    st = {}; OPT = int(os.environ.get('PD_OPT', '1'))
    sh = lambda k: st[k]
    # (label, row, args)   args are ints or callables(state); the result r3 of a step is stored under `save`
    steps = [('ShInitialize', 'ShInitialize', lambda: [], None),
             ('ShConstructCompiler.v', 'ShConstructCompiler', lambda: [0, 0], 'hv'),
             ('ShCompile.v', 'ShCompile', lambda: [st['hv'], A + 0x1000, 1, OPT, 0], None),
             ('ShConstructCompiler.f', 'ShConstructCompiler', lambda: [1, 0], 'hf'),
             ('ShCompile.f', 'ShCompile', lambda: [st['hf'], A + 0x1010, 1, OPT, 0], None),
             ('ConstructLinker', 'ConstructLinker', lambda: [0], 'hl'),
             ('ShLink', 'ShLink', lambda: [st['hl'], A + 0x1020, 2, 0, 0], None),
             ('ShGetInfoLog.l', 'ShGetInfoLog', lambda: [st['hl']], None),
             ('ShGetInfoLog.v', 'ShGetInfoLog', lambda: [st['hv']], None),
             ('ShGetPPStream.v', 'ShGetPPStream', lambda: [st['hv']], None),
             ('ShGetNumActiveAttributes', 'ShGetNumActiveAttributes', lambda: [st['hl']], None),
             ('ShGetNumActiveUniforms', 'ShGetNumActiveUniforms', lambda: [st['hl']], None),
             ('ShGetActiveUniform.0', 'ShGetActiveUniform', lambda: [st['hl'], 0, 64, A + 0x5000, A + 0x5004, A + 0x5008, A + 0x6000], None),
             ('ShGetActiveUniform.1', 'ShGetActiveUniform', lambda: [st['hl'], 1, 64, A + 0x5000, A + 0x5004, A + 0x5008, A + 0x6000], None),
             ('ShGetUniformLocation.mvp', 'ShGetUniformLocation', lambda: [st['hl'], A + 0x4000], None),
             ('ShGetUniformLocation.tex', 'ShGetUniformLocation', lambda: [st['hl'], A + 0x4010], None),
             ('ShGetAttribLocation.pos', 'ShGetAttribLocation', lambda: [st['hl'], A + 0x4020], None),
             ('ShGetLinkerBindingTable', 'ShGetLinkerBindingTable', lambda: [st['hl']], None),
             ('ShGetLinkerPPStream', 'ShGetLinkerPPStream', lambda: [st['hl']], None),
             ('ShGetCompilerPPStream.v', 'ShGetCompilerPPStream', lambda: [st['hv']], None)]
    # PD_SCEN=1: further sessions in the same process state (after ShInitialize): richer valid shaders (structs, arrays, loops, functions, built-ins, preprocessor, cube/projective texture,
    # gl_FragData, matrices, discard), a shader with syntax/semantic errors (info-log text) and a link error (varying type mismatch).  (tag, vertex source, fragment source, link?)
    SCEN = [('s1', b'struct Light { vec3 dir; vec4 color; };\nuniform Light lights[2]; uniform mat4 mvp; uniform mat3 nm; attribute vec4 pos; attribute vec3 nrm; attribute vec2 uv; varying vec4 col; varying vec2 vuv;\n'
                   b'vec4 shade(vec3 n) { vec4 c = vec4(0.0); for (int i = 0; i < 2; i++) { float d = max(dot(n, lights[i].dir), 0.0); c += lights[i].color * d; } return c; }\n'
                   b'void main() { vec3 n = normalize(nm * nrm); col = shade(n); vuv = uv * 2.0 - 1.0; gl_Position = mvp * pos; }',
             b'uniform sampler2D tex; uniform float k; varying vec4 col; varying vec2 vuv;\nvoid main() { vec4 t = texture2D(tex, vuv); if (t.a < 0.5) discard; float s = pow(clamp(dot(vuv, vuv), 0.0, 1.0), k); gl_FragColor = mix(t, col, s) * (vuv.x > 0.0 ? 1.0 : 0.5); }', True),
            ('s2', b'#define N 3\n#ifdef GL_ES\n#error no\n#endif\nuniform vec4 c[N]; uniform mat4 m; attribute vec4 pos; attribute vec3 d; varying vec3 dir; varying vec4 pj;\n'
                   b'void main() { vec4 s = vec4(0.0); for (int i = 0; i < N; i++) s += c[i]; s.xy = s.yx; dir = d; pj = m[1] + s; gl_Position = m * pos + vec4(s.w); }',
             b'uniform sampler2D a; uniform samplerCube b; uniform vec4 c; varying vec3 dir; varying vec4 pj;\n'
             b'void main() { vec4 x = texture2DProj(a, pj); vec4 y = textureCube(b, dir); bvec2 m = lessThan(x.xy, y.xy); vec2 z = mix(x.zw, y.zw, vec2(m)); mat2 r = mat2(cos(z.x), sin(z.x), -sin(z.x), cos(z.x)); gl_FragData[0] = vec4(r * z, gl_FragCoord.z, length(c.xyz) > 1.0 ? 1.0 : c.w); }', True),
            ('s3', b'uniform mat4 mvp; attribute vec4 pos; void main() { gl_Position = foo(mvp * pos; float x = ; }',
             b'void main() { gl_FragColor = vec4(undeclared, 1, 2); int i = 1.5; }', False),
            ('s4', b'attribute vec4 pos; varying vec2 q; void main() { q = pos.xy; gl_Position = pos; }',
             b'varying vec3 q; void main() { gl_FragColor = vec4(q, 1.0); }', True),
            # s5: valid preprocessor directives (#version, #pragma, #extension, #line, #define with arguments, #undef, #if/#elif/#else, defined()); s6: erroring directives (active #error, unknown #extension, #if without #endif)
            ('s5', b'#version 110\n#pragma optimize(on)\n#pragma debug(off)\n#extension all : warn\n#line 20\n#define SC(x) ((x) * 2.0)\n#define K 3\n#undef K\n#define K 4\n'
                   b'#if defined(K) && (K + 1 == 5)\nuniform float u;\n#elif K == 2\nuniform float v;\n#else\nuniform float w;\n#endif\nattribute vec4 pos; varying float f;\n'
                   b'void main() { f = SC(u); gl_Position = pos; }',
             b'#extension GL_ARB_texture_rectangle : enable\n#ifdef GL_ARB_texture_rectangle\nuniform vec4 c;\n#endif\nvarying float f; void main() { gl_FragColor = c * f; }', True),
            ('s6', b'#define Q\n#ifdef Q\n#error vertex stop\n#endif\n#extension GL_NOT_REAL : require\nattribute vec4 pos; void main() { gl_Position = pos; }\n#if 1\n',
             b'#line 0\n#pragma unknown(on)\n#extension GL_NOT_REAL : enable\n#if 1 +\n#endif\n#elif\n#else\n#endif\nvoid main() { gl_FragColor = vec4(1.0); }', False),
            # s7: constant folding (matrix/vector constants, constructors, comma, conversions, constant-index, unary/binary on constants), prototypes
            ('s7', b'const mat2 M = mat2(1.0, 2.0, 3.0, 4.0); const vec3 V = vec3(1.0) + vec3(2.0, 3.0, 4.0); const float F = 2.0 * 3.0 - 1.0; const int I = int(2.5) + 3; const bool B = !true || (I > 2);\n'
                   b'const vec4 W = vec4(M[0], V.xy * F); const mat3 D = mat3(2.0); const mat4 E = mat4(vec4(1.0), vec4(2.0), vec4(3.0), vec4(4.0));\n'
                   b'float f2(float a, float b); float f2(vec2 a, float b);\nfloat f2(float a, float b) { return a * b; }\nfloat f2(vec2 a, float b) { return a.x * b; }\n'
                   b'uniform float u; attribute vec4 pos; varying vec4 col;\n'
                   b'void main() { float c = (u, 1.0); vec3 q = -V; float z = B ? F : float(I); mat2 N = M * M; col = W + vec4(D[1], E[2][1]) + vec4(f2(u, z), f2(q.xy, c), N[1]); gl_Position = pos * E; }',
             b'const mat3 R = mat3(vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0)); const vec2 K = vec2(0.5) * vec2(2.0, 4.0);\nvarying vec4 col; void main() { vec3 t = R * col.xyz; gl_FragColor = vec4(t, K.y) + vec4(float(true), float(3), 0.0, 1.0); }', True),
            # s8: built-in matrices/ftransform, dynamic indexing (indirect addressing), diagonal matrix constructors from a non-constant scalar, struct constructors, comments, dead code / unused expressions
            ('s8', b'/* block comment */ // line comment\nstruct Lt { vec3 d; vec4 c; };\nuniform vec4 arr[8]; uniform float u; uniform Lt lt; uniform mat4 pm[2]; attribute float idx; attribute vec4 a0; varying vec4 vc; varying vec3 vd;\n'
                   b'void main() { int i = int(idx); vec4 x = arr[i] + arr[i + 1]; mat3 m3 = mat3(u); mat4 m4 = mat4(u); mat2 m2 = mat2(u); Lt l2 = Lt(vec3(u), vec4(0.5)); 1.0; if (false) { x = vec4(9.0); }\n'
                   b'  vc = x * m4[1] + l2.c + lt.c + vec4(m3[2], m2[1].x) + pm[i] * a0; vd = gl_NormalMatrix * gl_Normal; gl_Position = ftransform() + gl_ModelViewProjectionMatrix * gl_Vertex; gl_FrontColor = gl_Color; }',
             b'uniform float u; uniform vec2 w; varying vec4 vc; varying vec3 vd;\nvoid main() { mat2 r = mat2(u); vec2 q = r * w + dFdx(w) + dFdy(w) * fwidth(u); float d = dot(normalize(vd), vec3(0.0, 0.0, 1.0)); vec4 c = vc; c.xy += q; c.z = max(c.z, min(d, 1.0)); c.w = clamp(abs(sign(d)) + floor(u) - fract(u) + step(0.5, u) + smoothstep(0.0, 1.0, d), 0.0, 1.0) + mod(u, 2.0) + sqrt(d * d) + exp(d) + log(abs(d) + 1.0) + exp2(u) + inversesqrt(u * u + 1.0); gl_FragColor = c * gl_Color; }', True)]
    if os.environ.get('PD_SCEN') == '1':
        for si, (tg, vs_, fs_, lk) in enumerate(SCEN):
            vo, fo, to = 0x7000 + si * 0x800, 0x7400 + si * 0x800, 0x1100 + si * 0x40
            put(vo, vs_ + b'\0'); put(fo, fs_ + b'\0'); put(to, struct.pack('>I', A + vo)); put(to + 0x10, struct.pack('>I', A + fo)); put(to + 0x20, bytes(8))
            hv, hf, hl = 'hv_' + tg, 'hf_' + tg, 'hl_' + tg
            steps += [('ShConstructCompiler.v.' + tg, 'ShConstructCompiler', lambda: [0, 0], hv),
                      ('ShCompile.v.' + tg, 'ShCompile', lambda hv=hv, to=to: [st[hv], A + to, 1, OPT, 0], None),
                      ('ShGetInfoLog.v.' + tg, 'ShGetInfoLog', lambda hv=hv: [st[hv]], None),
                      ('ShConstructCompiler.f.' + tg, 'ShConstructCompiler', lambda: [1, 0], hf),
                      ('ShCompile.f.' + tg, 'ShCompile', lambda hf=hf, to=to: [st[hf], A + to + 0x10, 1, OPT, 0], None),
                      ('ShGetInfoLog.f.' + tg, 'ShGetInfoLog', lambda hf=hf: [st[hf]], None)]
            if lk:
                steps += [('ConstructLinker.' + tg, 'ConstructLinker', lambda: [0], hl),
                          ('ShLink.' + tg, 'ShLink', lambda hl=hl, to=to: [st[hl], A + to + 0x20, 2, 0, 0], None),
                          ('ShGetInfoLog.l.' + tg, 'ShGetInfoLog', lambda hl=hl: [st[hl]], None),
                          ('ShGetNumActiveAttributes.' + tg, 'ShGetNumActiveAttributes', lambda hl=hl: [st[hl]], None),
                          ('ShGetNumActiveUniforms.' + tg, 'ShGetNumActiveUniforms', lambda hl=hl: [st[hl]], None),
                          ('ShGetActiveUniform.0.' + tg, 'ShGetActiveUniform', lambda hl=hl: [st[hl], 0, 64, A + 0x5000, A + 0x5004, A + 0x5008, A + 0x6000], None),
                          ('ShGetActiveUniform.1.' + tg, 'ShGetActiveUniform', lambda hl=hl: [st[hl], 1, 64, A + 0x5000, A + 0x5004, A + 0x5008, A + 0x6000], None),
                          ('ShGetLinkerBindingTable.' + tg, 'ShGetLinkerBindingTable', lambda hl=hl: [st[hl]], None),
                          ('ShGetLinkerPPStream.' + tg, 'ShGetLinkerPPStream', lambda hl=hl: [st[hl]], None),
                          ('ShGetCompilerPPStream.v.' + tg, 'ShGetCompilerPPStream', lambda hv=hv: [st[hv]], None)]
    link_tab = {('ShLink.' + tg): (A + 0x1100 + si * 0x40 + 0x20, 'hv_' + tg, 'hf_' + tg) for si, (tg, _a, _b, _c) in enumerate(SCEN)}
    cov = set(); allv = []
    arena = bytes(arena)
    for k_, (name, rowname, argf, save) in enumerate(steps):
        reset = (k_ == 0); r = rows[rowname]; args = argf()
        if name == 'ShLink':
            for sim in (ss, sr): sim.uc.mem_write(A + 0x1020, struct.pack('>II', st['hv'], st['hf']))
        if name in link_tab:
            for sim in (ss, sr): sim.uc.mem_write(link_tab[name][0], struct.pack('>II', st[link_tab[name][1]], st[link_tab[name][2]]))
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
                if d and not t.wbeq(x[3], y[3]) and not t.wb_waived(x, y):
                    ks = sorted((q for q in set(x[3]) | set(y[3]) if x[3].get(q) != y[3].get(q)), key=repr)
                    print('  SEGDIFF', name, i, 'call', (x[0] or ('start',))[:2], 'differing final bytes', [(q, x[3].get(q), y[3].get(q)) for q in ks[:6]], 'nbytes', len(ks), flush=True)
                    k += 1
                    if k >= int(os.environ['PD_SEGDIFF']): break
        if os.environ.get('PD_WATCHABS') and os.environ.get('PD_WATCHSTEP', 'ShInitialize') in (name, '*'):
            wa = int(os.environ['PD_WATCHABS'])
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                if os.environ.get('PD_WATCHSTEP') == '*' and not any(e[0] in 'RW' and isinstance(e[1], int) and e[1] <= wa < e[1] + e[2] for e in run[1]): continue
                print('  WABS', name, tag, [(i, hex(sim.evpc.get(i, -1)), e[0], e[2], e[3] if e[0] != 'C' else None) for i, e in enumerate(run[1]) if e[0] in 'RW' and isinstance(e[1], int) and e[1] <= wa < e[1] + e[2]][:40], flush=True)
        if os.environ.get('PD_EVCTX') and name == os.environ.get('PD_WATCHSTEP', 'ShInitialize'):      # PD_EVCTX=stock_event_index,rebuilt_event_index: the 24 events before each with their pcs
            for (tag, run, sim), ix in zip((('stock', a, ss), ('rebuilt', b, sr)), os.environ['PD_EVCTX'].split(',')):
                if ix.startswith('@'): ix = next(i + 12 for i, e in enumerate(run[1]) if e[0] in 'RW' and e[1] == int(ix[1:]))      # '@ADDR': 12 events after the first access of that address
                for i in range(int(ix) - int(os.environ.get('PD_EVWIN', '24')), int(ix) + 3): print('  EVC', tag, i, hex(sim.evpc.get(i, -1)), str(run[1][i])[:150], flush=True)
        if v == 'READ_SET' and os.environ.get('PD_RDDIFF'):      # every read the one image makes in the differing segment that the other does not, with the other image's overlapping reads
            import re as _re
            sg = int(_re.search(r'segment (\d+)', det).group(1)); sga, _f1 = t.segments(a[1]); sgb, _f2 = t.segments(b[1])
            xr, yr = sga[sg][2], sgb[sg][2]
            def ov(r, k): return [q for q in r if isinstance(q[0], int) and isinstance(k[0], int) and q[0] < k[0] + k[1] and k[0] < q[0] + q[1]]
            for tag, r1, r2 in (('stock-only', xr, yr), ('rebuilt-only', yr, xr)):
                for k in sorted((q for q in r1 if q not in r2), key=repr)[:12]:
                    print('  RD', name, tag, k, 'values', [getattr(w, 'raw', w) for w in r1[k]][:3], 'other image overlapping', [(q, [getattr(w, 'raw', w) for w in r2[q]][:2]) for q in ov(r2, k)], flush=True)
        if v == 'IMAGE_DATA_DEP' and os.environ.get('PD_IDDIFF'):      # PD_IDDIFF=1: for an IMAGE_DATA_DEP step, the pcs/values of the first reads of each differing image-data key in both images, and every event with the segment's differing store address
            ik = [x[0] for x in t.image_data_diff(a[1], b[1])][:6]
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                print('  ID', name, tag, [(k, [(i, hex(sim.evpc.get(i, -1)), run[1][i][2], getattr(run[1][i][3], 'raw', run[1][i][3])) for i, e in enumerate(run[1]) if e[0] == 'R' and e[1] == k][:4]) for k in ik], flush=True)
        if os.environ.get('PD_SEGSHOW') and name == os.environ.get('PD_WATCHSTEP', 'ShInitialize'):      # PD_SEGSHOW=n: segment n of both images (opening call-out, writes, reads)
            sga, _f1 = t.segments(a[1]); sgb, _f2 = t.segments(b[1]); n_ = int(os.environ['PD_SEGSHOW'])
            for tag, sg in (('stock', sga), ('rebuilt', sgb)):
                x = sg[n_]; print('  SEG', tag, n_, 'call', str(x[0])[:200], 'writes', str(x[1])[:900], 'final', str(x[3])[:600], flush=True)
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
        if os.environ.get('PD_CALLCTX') and name == os.environ['PD_CALLCTX'].split(':')[0]:
            ci = int(os.environ['PD_CALLCTX'].split(':')[1])
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                cidx = [i for i, e in enumerate(run[1]) if e[0] == 'C'][ci]
                print('  CALLCTX', tag, 'call', ci, run[1][cidx][1:3], flush=True)
                for i in range(max(0, cidx - 14), cidx + 1): print('     ', i, hex(sim.evpc.get(i, -1)), str(run[1][i])[:120], flush=True)
        if os.environ.get('PD_FUNSEQ') and name == os.environ['PD_FUNSEQ'].split(':')[0]:
            c0 = int(os.environ['PD_FUNSEQ'].split(':')[1]); c1 = int(os.environ['PD_FUNSEQ'].split(':')[2])
            import bisect
            fl = sorted((int(l.split('\t')[0], 16) - S.bal, l.split('\t')[2]) for l in open(opt['--funcs']) if l.startswith('0x')); fk = [x[0] for x in fl]
            def fname(tag, pc):
                if tag == 'stock':
                    i = bisect.bisect_right(fk, pc) - 1; return fl[i][1] if i >= 0 else '?'
                nmn, off = R.sym(pc); sa = R.to_stock.get(nmn) if R.to_stock else None
                if sa is not None:
                    i = bisect.bisect_right(fk, sa) - 1; return fl[i][1]
                return nmn
            for tag, run, sim in (('stock', a, ss), ('rebuilt', b, sr)):
                ci = 0; seq = []
                for i, e in enumerate(run[1]):
                    if e[0] == 'C': ci += 1; seq.append('CALL %s%s' % (e[1], tuple(getattr(x, 'raw', x) for x in e[2][:2]))); continue
                    if c0 <= ci <= c1 and e[0] in 'RW':
                        pc = sim.evpc.get(i)
                        if pc is None or pc < 0: continue
                        nn = fname(tag, pc)
                        if not seq or seq[-1] != nn: seq.append(nn)
                with open(os.path.join(os.environ['PD_DUMP'], 'funseq.%s' % tag), 'w') as f: f.write('\n'.join(seq) + '\n')
        if os.environ.get('PD_SPRINTF') and name == os.environ['PD_SPRINTF']:
            for tag, run in (('stock', a), ('rebuilt', b)):
                ev = run[1]; k = 0
                for i, e in enumerate(ev):
                    if e[0] == 'C' and e[1] == '_sprintf':
                        k += 1
                        if k > 40: break
                        print('  SPF', tag, k, [getattr(x, 'raw', x) if not hasattr(x, 'canon') else (hex(x.raw), x.canon) for x in e[2][:6]], '| next', str(ev[i + 1])[:140] if i + 1 < len(ev) else None, flush=True)
        if os.environ.get('PD_MEMAT'):
            for ma in os.environ['PD_MEMAT'].split(','):
                ma = int(ma)
                print('  MEMAT', name, ma, 'stock', bytes(ss.uc.mem_read(ma & ~15, 16)).hex(), 'rebuilt', bytes(sr.uc.mem_read(ma & ~15, 16)).hex(), flush=True)
        print('%-22s stock %s r3=%#x  rebuilt %s r3=%#x  events %d/%d  verdict %s %s' % (name, a[0], a[2]['r3'], b[0], b[2]['r3'], len(a[1]), len(b[1]), v, det[:300]), flush=True)
        if save: st[save] = a[2]['r3']
        if name.startswith('ShGetCompilerPPStream.v'): print('  COV after', name, len(cov), flush=True)
        if name.startswith('ShGetInfoLog') and a[2]['r3']:
            for tag, sim in (('stock', ss), ('rebuilt', sr)):
                try: print('  INFOLOG', name, tag, bytes(sim.uc.mem_read(a[2]['r3'] if tag == 'stock' else b[2]['r3'], 300)).split(b'\0')[0][:240], flush=True)
                except Exception as e: print('  INFOLOG', name, tag, 'unreadable', e)
        if a[0] != 'RET' or b[0] != 'RET': break
        if name == os.environ.get('PD_STOPAFTER'): break
    os.makedirs(opt['--out'], exist_ok=True)
    base = os.path.splitext(os.path.basename(opt['--shader'] or 'default'))[0]
    with open(os.path.join(opt['--out'], base + '.stock.cov'), 'w') as f: f.write('\n'.join('%x' % x for x in sorted(cov)) + '\n')
    print('stock instructions covered: %d' % len(cov))

if __name__ == '__main__': main(sys.argv[1:])
