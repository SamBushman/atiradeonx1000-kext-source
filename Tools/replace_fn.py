#!/usr/bin/env python3
"""replace_fn.py ADDR [ADDR ...]  - re-port ledger methods mechanically from the Ghidra decompile ($SCRATCH/work/0xADDR.txt) and
replace the earlier hand-written body: the old definition is cut out of its source file (wherever it lives) and the new one is
written to Sources/<Class>_<name>_Port.cpp (created/appended). Declaration is taken from the class header + the demangled symbol.
Extra port_fn options can be given as  ADDR:opt1:opt2 (e.g. 0x9a30:this=param_1)."""
import sys, re, subprocess, os, glob, collections
HERE = os.path.dirname(os.path.abspath(__file__)); ROOT = os.path.dirname(HERE)
SP = os.environ.get('SCRATCH', '/tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad')
led = {}
for l in open(ROOT + '/Ledger/kext_ppc_ledger.tsv'):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 6 and f[2] == 'method': led[int(f[0], 16)] = (f[4], f[5])
TY = [('unsigned long', 'UInt32'), ('unsigned short', 'UInt16'), ('unsigned char', 'UInt8'), ('long', 'SInt32')]   # `unsigned int` / `int` stay: UInt32 is `unsigned long` here, so they mangle differently
def project_type(t):
    t = t.strip()
    t = re.sub(r'(?<!unsigned )\blong\b', 'SInt32', t) if False else t
    for a, b in TY:
        t = re.sub(r'(?<![\w])%s(?![\w])' % a, b, t)
    return t
def demangle(sym):
    return subprocess.run(['c++filt', sym[1:] if sym.startswith('__Z') else sym], capture_output=True, text=True).stdout.strip()
def split_params(s):
    out, d, cur = [], 0, ''
    for ch in s:
        if ch in '(<': d += 1
        if ch in ')>': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur.strip())
    return out
def find_ret(cls, name, nparams):
    best = None
    hs = sorted(glob.glob(ROOT + '/Headers/*.h'))
    hs.sort(key=lambda h: 0 if os.path.basename(h) == cls + '.h' else 1)
    for h in hs:
        for line in open(h):
            if re.match(r'\s*(/\*|\*|//)', line): continue
            m = re.match(r'\s*(?:virtual\s+|static\s+)?((?:const\s+)?[\w:<>]+(?:\s*\*+)?)\s*\*?\s*(%s)\s*\(([^)]*)\)' % re.escape(name), line)
            if m:
                ps = split_params(m.group(3)) if m.group(3).strip() not in ('', 'void') else []
                if len(ps) == nparams: return m.group(1).strip() + (' ' if m.group(1).strip().endswith('*') is False else '')
                if best is None and os.path.basename(h) == cls + '.h': best = m.group(1).strip() + ' '
    return best
def cut_old(cls, name):
    for f in sorted(glob.glob(ROOT + '/Sources/*.cpp')):
        s = open(f).read()
        pat = re.compile(r'(?m)^(?:[\w:<>\*&]+[ \t]+)+\**' + re.escape((cls + '::' if cls else '') + name) + r'\s*\(')
        for m in pat.finditer(s):
            # only a definition (has a body): find '{' before ';'
            i = m.end(); depth = 1
            while depth and i < len(s):
                depth += {'(': 1, ')': -1}.get(s[i], 0); i += 1
            j = i
            while s[j] in ' \t\n\r': j += 1
            if s[j] != '{': continue
            k = j; d = 0
            while True:
                if s[k] == '{': d += 1
                elif s[k] == '}':
                    d -= 1
                    if d == 0: break
                k += 1
            # include a directly preceding block comment (real addr marker) if any
            start = m.start()
            open(f, 'w').write(s[:start] + '/* (re-ported mechanically: see %s_%s_Port.cpp) */\n' % (cls, name) + s[k+1:])
            return f
    return None
OVR = {}
if os.path.exists('/tmp/spec/overrides.tsv'):
    for l in open('/tmp/spec/overrides.tsv'):
        f = l.rstrip('\n').split('\t')
        if len(f) >= 2: OVR[int(f[0], 16)] = (f[1], f[2] if len(f) > 2 else '')
for arg in sys.argv[1:]:
    parts = arg.split(':'); a = int(parts[0], 16); asicall = [p[8:] for p in parts[1:] if p.startswith('asicall=')]; opts = ' '.join(p for p in parts[1:] if not p.startswith('asicall='))
    name, sym = led[a]
    dm = demangle(sym)
    m = re.match(r'^(\w+)::(~?\w+)\((.*)\)( const)?$', dm)
    if not m: print('skip (free function?)', dm); cls, fn, plist = '', dm.split('(')[0], dm[dm.index('(')+1:-1]
    else: cls, fn, plist = m.group(1), m.group(2), m.group(3)
    params = split_params(plist) if plist.strip() not in ('', 'void') else []
    ret = find_ret(cls, fn, len(params)) if cls else 'UInt32 '
    if ret is None: print('NO HEADER DECL', dm); ret = 'UInt32 '
    prim_ptr = re.compile(r'^(?:const\s+)?(?:unsigned int|int|long|UInt8|UInt16|UInt32|SInt8|SInt16|SInt32|char|void|float|IOMemoryDescriptor)\s*\*+$')
    dp = []; cast_opts = []
    for i, p in enumerate(params):
        t = project_type(p)
        if t.endswith('*') and not prim_ptr.match(t) and t.count('*') == 1:
            dp.append('%s *real_param_%d' % (t.rstrip('* ').strip(), i + 1)); cast_opts.append('cast:param_%d' % (i + 1))
        else:
            dp.append('%s%sparam_%d' % (t, '' if t.endswith('*') else ' ', i + 1))
    decl_params = ', '.join(dp)
    base_opts = opts
    opts = (opts + ('' if os.environ.get('NOEXACT') else ' exact ') + ' '.join(cast_opts)).strip()
    qual = (cls + '::' if cls else '') + fn
    decl = '%s%s(%s)' % (ret, qual, decl_params)
    if a in OVR:
        decl = OVR[a][0]; opts = (base_opts + ' exact ' + OVR[a][1]).strip()
    spec = '%s\t%s\t%s cls=%s\n' % (hex(a), decl, opts, cls)
    tsv = '/tmp/spec/rf_%x.tsv' % a; out = '/tmp/spec/rf_%x.cpp' % a
    open(tsv, 'w').write(spec)
    r = subprocess.run(['python3', HERE + '/port_fn.py', tsv, out], capture_output=True, text=True)
    old = cut_old(cls, fn) if (r.returncode == 0 and os.path.exists(out)) else None
    print(hex(a), decl, '| old body cut from', old, '|', r.stdout.strip() or r.stderr.strip()[-200:])

    # assemble the port into its own source file (common fixes applied)
    if r.returncode == 0 and os.path.exists(out):
        src = open(out).read()
        if asicall: src = src.replace('_ASICSupportsAGP', asicall[0])
        pre, *funcs = re.split(r'(?m)^(?=/\* real addr )', src)
        names = set()
        for h in ['ATIRadeonX1000.h', 'IOATIR500Accelerator.h', 'IOATIR500GLContext.h', 'IOATIR5002DContext.h', 'IOATIR500DVDContext.h', 'IOATIR500Surface.h', 'IOATIR500Shared.h', 'ATIR500Surface.h', 'ATIR500GLContext.h', 'ATIR5002DContext.h', 'ATIR500DVDContext.h', 'ATIR500Memory.h']:
            for l in open(ROOT + '/Headers/' + h):
                mm = re.match(r'\s+(?:virtual\s+|static\s+)?[\w\s\*:<>]+?[\s\*&](\w+)\s*\(', l)
                if mm and not l.strip().startswith(('//', '*', '/*')): names.add(mm.group(1))
        names -= {'if', 'while', 'return', 'sizeof', 'switch', 'for'}
        body = funcs[0]
        for n in names:
            body = re.sub(r'(?<![\w>.:])%s\s*\(self\)' % n, 'this->' + n + '()', body)
            body = re.sub(r'(?<![\w>.:])%s\s*\(\s*(?:\(UInt8 \*\))?self,\s*' % n, 'this->' + n + '(', body)
        body = body.replace('sync(0);', 'ppcSync();')
        KC = ['ATIR500Memory', 'IOATIR500Shared', 'IOATIR500Surface', 'IOATIR500Accelerator', 'ATIRadeonX1000', 'IOATIR500GLContext', 'IOATIR5002DContext', 'IOATIR500DVDContext', 'ATIR500Surface', 'ATIR500GLContext', 'ATIR5002DContext', 'ATIR500DVDContext']
        def conv_static(txt):
            pat = re.compile(r'\b(' + '|'.join(KC) + r')::(\w+)\s*\(')
            pos = 0
            while True:
                m = pat.search(txt, pos)
                if not m: return txt
                i = m.end(); d = 1; j = i; args = []; cur = i
                while d:
                    c = txt[j]
                    if c in '([<': d += 1 if c != '<' else 0
                    if c == '(' : pass
                    if c in ')]':
                        d -= 1
                    if c == ',' and d == 1:
                        args.append(txt[cur:j]); cur = j + 1
                    j += 1
                args.append(txt[cur:j-1])
                if m.group(2) == m.group(1) or (len(args) and args[0].strip() == '' ):
                    pos = m.end(); continue
                first = args[0].strip()
                if first in ('self', 'this'):
                    pos = m.end(); continue
                rest = ','.join(args[1:]).strip()
                new = '((%s *)(%s))->%s(%s)' % (m.group(1), first, m.group(2), rest)
                txt = txt[:m.start()] + new + txt[j:]
                pos = m.start() + len(new)
        _k = body.index('{\n') + 2
        body = body[:_k] + conv_static(body[_k:])
        SIG = collections.defaultdict(list)
        for h in glob.glob(ROOT + '/Headers/*.h'):
            txt = open(h).read()
            txt = re.sub(r'/\*.*?\*/', ' ', txt, flags=re.S); txt = re.sub(r'//[^\n]*', ' ', txt)
            for mm in re.finditer(r'(?:virtual\s+|static\s+)?(?:const\s+)?[\w:<>]+(?:\s*\*+)?\s*\*?\s*(\w+)\s*\(([^()]*)\)\s*(?:const\s*)?(?:override\s*)?(?:;|\{)', txt):
                if mm.group(1) in ('if', 'while', 'return', 'sizeof', 'switch'): continue
                plist = ' '.join(mm.group(2).split())
                ps = split_params(plist) if plist not in ('', 'void') else []
                SIG[(mm.group(1), len(ps))].append([re.sub(r'\s*\b\w+$', '', p) if re.search(r'\w\s+\**\w+$', p) else p for p in ps])
        def castable(t):
            t = t.strip()
            return (t.endswith('*') and t not in ('UInt8 *', 'void *', 'char *', 'UInt8*', 'void*', 'char*')) or re.match(r'^e[A-Z]\w+$', t)
        def cast_args(txt):
            pat = re.compile(r'(?:->|\bthis->)(\w+)\s*\(')
            pos = 0
            while True:
                mm = pat.search(txt, pos)
                if not mm: return txt
                i = mm.end(); d = 1; j = i; args = []; cur = i
                while d:
                    c = txt[j]
                    if c == '(': d += 1
                    elif c == ')': d -= 1
                    elif c == ',' and d == 1: args.append(txt[cur:j]); cur = j + 1
                    j += 1
                args.append(txt[cur:j-1])
                key = (mm.group(1), len(args) if any(a.strip() for a in args) else 0)
                sigs = SIG.get(key)
                if sigs and len(args) > 0:
                    new = []
                    for idx, a in enumerate(args):
                        st = a.strip()
                        cts = {sg[idx].strip() for sg in sigs if idx < len(sg) and castable(sg[idx])}
                        alls = {sg[idx].strip() for sg in sigs if idx < len(sg)}
                        ptrlike = re.match(r'^p[A-Za-z]+\d*$|^this_\d+$|^M<UInt8 \*>\(|^param_\d+$|^local_\w+$|^\(UInt8 \*\)', st) is not None
                        if len(cts) == 1 and (len(alls) == 1 or ptrlike) and (st not in ('0', '0x0', 'nullptr') or re.match(r'^e[A-Z]', list(cts)[0])) and not st.startswith('(' + list(cts)[0]):
                            new.append(a.replace(st, '(%s)(%s)' % (list(cts)[0], st)) if st else a)
                        else: new.append(a)
                    rep = mm.group(0) + ','.join(new) + ')'
                    txt = txt[:mm.start()] + rep + txt[j:]
                    pos = mm.start() + len(rep)
                else:
                    pos = mm.end()
        body = body[:_k] + cast_args(body[_k:])
        _k2 = body.index('{\n') + 2
        def cast_first(txt, pat, typ):
            rx = re.compile(pat)
            pos = 0
            while True:
                mm = rx.search(txt, pos)
                if not mm: return txt
                i = mm.end(); d = 1; j = i
                while d:
                    c = txt[j]
                    if c == '(': d += 1
                    elif c == ')': d -= 1
                    j += 1
                inner = txt[i:j-1]
                # first top-level argument
                dd = 0; k = 0
                while k < len(inner):
                    if inner[k] in '(<': dd += 1
                    elif inner[k] in ')>': dd -= 1
                    elif inner[k] == ',' and dd == 0: break
                    k += 1
                first = inner[:k].strip(); rest = inner[k:]
                if first.startswith('(' + typ) or first in ('0',):
                    pos = mm.end(); continue
                new = mm.group(0) + '(%s)(%s)' % (typ, first) + rest + ')'
                txt = txt[:mm.start()] + new + txt[j:]
                pos = mm.start() + len(new)
        body = body[:_k2] + cast_first(body[_k2:], r'\bHZMEM_\w+\s*\(', '_HZDATA *')
        rt = ret.strip()
        if rt.endswith('*'):
            body = re.sub(r'\breturn (?!0;|\(%s\)|0x0;)([^;]+);' % re.escape(rt), lambda mm: 'return (%s)(%s);' % (rt, mm.group(1)), body)
        body = re.sub(r'\bATIR500Memory::(\w+)\s*\(\s*(M<UInt8 \*>\(self \+ 0x[0-9a-f]+\))\s*,\s*', lambda mm: '((ATIR500Memory *)(%s))->%s(' % (mm.group(2), mm.group(1)), body)
        body = body.replace('_gl_assert_wait_timeout_event', 'gl_assert_wait_timeout_event')
        pre = pre.replace('#include "../Headers/GhidraCompat.h"\n', '')
        hdr = ''.join('#include "../Headers/%s"\n' % h for h in ['ATIRadeonX1000.h', 'IOATIR500Accelerator.h', 'IOATIR500GLContext.h', 'IOATIR5002DContext.h', 'IOATIR500DVDContext.h', 'IOATIR500Surface.h', 'IOATIR500Shared.h', 'ATIR500Surface.h', 'ATIR500GLContext.h', 'ATIR5002DContext.h', 'ATIR500DVDContext.h', 'ATIR500Memory.h', 'ATIRadeonX1000PPCIntrinsics.h', 'ATIRadeonX1000Registers.h', 'GhidraExterns.h', 'GhidraCompat.h'])
        dst = ROOT + '/Sources/%s_Port.cpp' % (qual.replace('::', '_'))
        doc = '/*\n * %s\n *\n * %s (real addr %s, %s bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /\n * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had\n * dropped or simplified parts of the original.\n */\n\n' % (os.path.basename(dst), qual, hex(a), dm.count('') and str(next((sz for aa, sz in [(0, 0)]), 0)))
        open(dst, 'w').write(doc + hdr + pre + '\n' + body)
        print('   ->', os.path.basename(dst))
