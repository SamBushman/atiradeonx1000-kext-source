#!/usr/bin/env python3
"""gen_defrole.py DIR OUT.tsv [FUNCTION ...] - `use` rows naming def-use webs by what their definitions call: every definition of the web is
`X = callee(...)` and the callee is a known API (strlen -> length, malloc -> allocation, ...) or a getter (`T__GetFoo` -> foo, `...IsFoo` -> isFoo)."""
import re, sys, os, glob, collections, time
sys.argv_saved = sys.argv
src = open(os.path.expanduser('~/wt/D6/Tools/userspace/apply_names.py')).read().replace('\nmain()\n', '\n').replace('if __name__ == "__main__":\n    main()', '')
exec(src)
sys.path.insert(0, os.path.expanduser('~/wt/D6/Tools/userspace'))
import webs
d, outp = sys.argv_saved[1:3]
only = set(sys.argv_saved[3:])
rows = load_rows(d)
byfn = collections.defaultdict(dict)
for r in rows: byfn[r[2]][r[4]] = r[3]
GV = re.compile(r'^[a-z]{0,4}Var\d+$')
DECL = r'\s+(?!return\b)[\w ]+?[ *]([A-Za-z_]\w*)(\[\w+\])?;$'
KNOWN = {'_strlen': 'length', '_memcmp': 'compareResult', '_strcmp': 'compareResult', '_strncmp': 'compareResult', '_malloc': 'allocation',
         '_calloc': 'allocation', '_realloc': 'allocation', 'operator_new': 'allocation', 'operator_new__': 'allocation',
         'TPoolAllocator__allocate': 'allocation', 'GetGlobalPoolAllocator': 'poolAllocator', '_PPStreamChunkCreateWithType': 'chunk',
         '_PPStreamChunkCreateFromChunk': 'chunk', '_PPParserGetPart': 'part', 'GetPPStreamTypeForGLType': 'streamType',
         'storeWordConditionalIndexed': 'atomicStore', '_floor': 'floorResult', '_sqrt': 'sqrtResult', '_log2': 'log2Result', '_exp2': 'exp2Result',
         '_pow': 'powResult', '_trunc': 'truncResult', '_cos': 'cosResult', '_sin': 'sinResult', '_ceil': 'ceilResult', '_tan': 'tanResult',
         '_asin': 'asinResult', '_acos': 'acosResult', '_atan': 'atanResult', 'GH_U2F': 'floatValue',
         '_glpRTCAddAChunk_97be1c2c': 'chunkIndex', '_glpRTCAddAChunk_97bd7cbc': 'chunkIndex',
         '_glpWriteSourceOperand_97bf30b8': 'outCursor', '_glpWriteDestinationOperand_97bf3658': 'outCursor',
         '_ncpy_97be5f58': 'copyEnd', '_ncpy_97bf2850': 'copyEnd', 'scpy': 'copyEnd', 'ncpy': 'copyEnd',
         'ParseOperand__GetLogicalSize': 'logicalSize', '_read_uleb128_97c1a3ec': 'lebValue', 'TType__setStructSize': 'structSize',
         'Binding__GetLocation': 'location', 'Binding__GetBindingSlots': 'slotCount', 'Binding__GetHash': 'bindingHash',
         'Binding__GetOpenGLType': 'glType', 'Binding__IsBuiltIn': 'isBuiltIn', 'GetScalerWidthForType': 'scalarWidth',
         'GetVec4sForType': 'vec4Count', 'GetShaderStringForType': 'typeString', 'FunctionTable__getFunctionName': 'functionName',
         'FunctionTable__getFirstOp': 'firstOp', '_PPStreamChunkListCreate': 'chunkList', '_PPStreamChunkListChunkAtIndex': 'chunk',
         '_PPStreamChunkListCompare': 'listCompare', '_PPParserParseArray': 'arrayResult', '_PPEmulatorFramebufferFormat': 'framebufferFormat',
         '_GetBlock': 'block', '_lReadByte': 'byteValue', '_BitSetGetEquals': 'bitSetEquals', '_InterpreterTestCR': 'conditionResult',
         '_base_from_object': 'baseAddress', 'ParseOperand__IsMatrix': 'isMatrix'}
SKIPNAMES = {'hash', 'equals'}


CKW = {'auto','break','case','char','const','continue','default','do','double','else','enum','extern','float','for','goto','if','inline','int','long','register','restrict','return','short','signed','sizeof','static','struct','switch','typedef','union','unsigned','void','volatile','while','class','new','delete','this','template','operator','bool','true','false','namespace','index','string','time','exp','log','div','abs','round','free','select','remove','read','write','open','close','signal','link','pipe','abort','exit','system','stat','rand','random','swab','strtod','basename','dirname','y0','y1','j0','j1','gamma','block','chunk'}


def role_of(callee):
    r = role_of0(callee)
    return r + 'Value' if r in CKW and r not in ('block', 'chunk') else r


def role_of0(callee):
    if callee in KNOWN: return KNOWN[callee]
    m = re.search(r'Get([A-Z]\w*)$', callee) or re.search(r'get([A-Z]\w*)$', callee)
    if m and not callee.startswith('GetGlobal'):
        n = m.group(1); n = n[0].lower() + n[1:]
        return n if n not in SKIPNAMES else None
    m = re.search(r'(?:__|^_?)(Is|is|Has|has)([A-Z]\w*)$', callee)
    if m: return m.group(1).lower() + m.group(2)
    m = re.search(r'__(?:new|create|make|generate|find|lookup|build|alloc)([A-Z]\w*)$', callee)
    if m:
        n = m.group(1); return n[0].lower() + n[1:]
    return None


def split_units(l):
    k = split_assign(l)
    return [(0, l[:k]), (1, l[k + 1:])] if k >= 0 else [(1, l)]


out = open(outp, 'w')
out.write('# use\tFUNCTION\told\tnew\ttier\tevidence\tfrom\tto\tfirst\tlast   (machine-written: webs named by the API their definitions call; #L = lines after the declarations, +N = lines to the end line)\n')
total = 0; nfun = 0; t0 = time.time()
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    text = open(pf).read(); lines, fns = split_functions(text)
    for fn, s, e in fns:
        if only and fn not in only: continue
        F = lines[s:e]
        back = byfn.get(fn, {})
        norm = (lambda l: re.sub('|'.join(wb(k) for k in back), lambda m: back[m.group(0)], l)) if back else (lambda l: l)
        N = [norm(l) for l in F]
        if '{' not in N: continue
        brace = N.index('{'); i = brace + 1
        while i < len(N) and (re.match(DECL, N[i]) or not N[i].strip() or re.match(r'\s*(/\*|\*)', N[i])): i += 1
        D1 = i
        decls = [re.match(DECL, N[k]).group(1) for k in range(brace + 1, D1) if re.match(DECL, N[k])]
        gvars = [v for v in decls if GV.match(v)]
        if not gvars: continue
        end = len(N) - 1
        while end > 0 and N[end].strip() != '}': end -= 1
        FN = webs.Function(N, D1, end, gvars)
        if not FN.ok: continue
        nfun += 1
        idents = set(re.findall(r'[A-Za-z_]\w*', '\n'.join(F)))
        wrole = {}
        for v, ws in FN.webs.items():
            for w in ws:
                if not w.defunits: continue
                roles = set()
                for (ln, p) in w.defunits:
                    m = re.match(r'\s*(\w+) = (?:\([^()]*\)\s*)?([A-Za-z_]\w*)\(', N[ln]) or re.match(r'\s*(\w+) = \(\((?:[^()]|\(\*\)\(\))*\)([A-Za-z_]\w*)\)\(', N[ln])
                    roles.add(role_of(m.group(2)) if m and m.group(1) == v else None)
                if len(roles) == 1 and None not in roles: wrole[id(w)] = next(iter(roles))
        if not wrole: continue
        names = {}; taken = set(idents)
        cnt = collections.Counter()
        for v, ws in FN.webs.items():
            for w in ws:
                if id(w) in wrole: cnt[(v, wrole[id(w)])] += len(w.units)
        for (v, role), c in cnt.most_common():
            nm = role; k = 1
            while nm in taken or nm in names.values(): k += 1; nm = role + str(k)
            names[(v, role)] = nm; taken.add(nm)
        for var, ws in sorted(FN.webs.items()):
            allocc = sorted({u for w in ws for u in w.units})
            urole = {}
            for w in ws:
                if id(w) in wrole:
                    for u in w.units: urole[u] = wrole[id(w)]
            runs = []
            for u in allocc:
                r = urole.get(u)
                if r is None: runs.append(None); continue
                if runs and runs[-1] and runs[-1][0] == r: runs[-1][2] = u
                else: runs.append([r, u, u])
            for run in runs:
                if not run: continue
                role, (a, pa), (z, pz) = run
                def parts_of(k): return [p for p, t in split_units(N[k]) if re.search(wb(var), strip_strings(t))]
                pa_all, pz_all = parts_of(a), parts_of(z)
                if a == z:
                    sel = [p for p in pa_all if pa <= p <= pz]
                    side = 'all' if sel == pa_all else ('lhs' if sel == [0] else 'rhs'); first = last = side
                else:
                    sa = [p for p in pa_all if p >= pa]; first = 'all' if sa == pa_all else ('lhs' if sa == [0] else 'rhs')
                    sz = [p for p in pz_all if p <= pz]; last = 'all' if sz == pz_all else ('lhs' if sz == [0] else 'rhs')
                out.write('use\t%s\t%s\t%s\tINFERRED\tevery definition is the result of a call whose name says it returns this\t#%d\t+%d\t%s\t%s\n' % (fn, var, names[(var, role)], a - D1, z - a, first, last))
                total += 1
out.close()
print('%d functions parsed, %d rows, %.0fs' % (nfun, total, time.time() - t0), file=sys.stderr)
