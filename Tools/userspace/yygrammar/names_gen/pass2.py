import vt

# ---- pass 2: classes, $k loads, virtual calls, allocation, error checks --------------------------------------------------------------------------
CLS = {}                                   # W -> class name
def recv_class(var, ln, ptr=False):
    w = web_at(var, ln)
    return CLS.get(w) if w else None
def run_pass2():
    changed = True; rounds = 0
    while changed and rounds < 6:
        changed = False; rounds += 1
        for w in WS:
            # allocation class
            if w not in CLS:
                cl, sz = r1.alloc_class(w)
                if cl: CLS[w] = cl; changed = True
                if cl and r1.NEWNAME.get(cl) and w.name is None:
                    setname(w, r1.NEWNAME[cl], 'INFERRED', 'allocated from the pool (TPoolAllocator__allocate %s bytes) and its first word stored with the %s vtable (%s)' % (sz, cl, 'resolved from the dylib symbol table'))
            # $k stack loads
            sl = r1.yyvsp_load(w)
            if sl:
                k, F, sym, lhs = sl
                fname = r1.FIELD.get(F, (None,))[0]
                if F == 4 and sym.isupper(): fname = {'IDENTIFIER': 'String', 'TYPE_NAME': 'String', 'FIELD_SELECTION': 'String', 'INTCONSTANT': 'Int', 'FLOATCONSTANT': 'Float', 'BOOLCONSTANT': 'Bool'}.get(sym, 'Value')
                if fname and w.name is None:
                    base = r1.camel(sym)
                    nm = base + fname
                    setname(w, nm, 'INFERRED', 'copy of the value-stack slot of $%d (%s) of rule %d (%s : %s), field +0x%x; stack entry layout 0x2c, see notes_ttype_layout.md' % (k, sym, w.case(), lhs, ' '.join(r1_rhs(w.case())), F))
                if F == 8 and r1.TYPED_SYMS.match(sym) and w not in CLS: CLS[w] = 'TIntermTyped'; changed = True
            # virtual-call results: every definition of the web must be the same method on a receiver of known class
            if w.name is None and w.deflines:
                roles = set(); recv_cls = set(); ok = True
                for ln in w.deflines:
                    rhs = y.rhs_of(w.v, ln)
                    recv = None; off = None
                    m = rhs and r1.VCALL_A.match(rhs)
                    if m:
                        off = int(m.group(2), 0); recv = recv_class(m.group(1), ln)
                    else:
                        m = rhs and r1.VCALL_B.match(rhs)
                        if m:
                            yo = int(m.group(1), 0) if m.group(1) else 0
                            off = int(m.group(2), 0)
                            c = w.case()
                            if isinstance(c, int) and all(y.pure[l] for l in w.lines):
                                sr = r1.slot_ref(yo, c)
                                if sr and sr[1] == 8 and r1.TYPED_SYMS.match(sr[2]): recv = 'TIntermTyped'
                    mo = r1.method_of(recv, off) if (recv and off is not None) else None
                    if not mo: ok = False; break
                    roles.add((mo[0], mo[1], off, recv))
                if ok and len({r[1] for r in roles}) == 1:
                    cls_, meth, off, recv = sorted(roles)[0]
                    role = r1.ROLE.get(meth)
                    if meth in r1.GETAS_CLASS and CLS.get(w) != r1.GETAS_CLASS[meth]: CLS[w] = r1.GETAS_CLASS[meth]; changed = True
                    if role:
                        setname(w, role, 'CONFIRMED', 'result of the virtual call %s::%s (vtable slot at +0x%x of the receiver, receiver class %s, names from the dylib symbol table)' % (cls_, meth, off, recv))
                        changed = True
            # ErrorCheck callees (all definitions)
            if w.name is None and w.deflines:
                ms = set()
                for ln in w.deflines:
                    rhs = y.rhs_of(w.v, ln)
                    m = rhs and re.match(r'(?:\(\w+\))?\s*TParseContext__(\w+?)ErrorCheck\(', rhs)
                    ms.add(m.group(1) if m else None)
                if len(ms) == 1 and None not in ms:
                    m1 = next(iter(ms))
                    setname(w, m1 + 'Error', 'INFERRED', 'result of TParseContext::%sErrorCheck: nonzero means an error was reported (the action then calls TParseContext::recover)' % m1)
def r1_rhs(n): return y.rule(n)[1]
run_pass2()
STAT['classes'] = len(CLS)

# ---- pass 3: skeleton, copies of yyvalNode, allocator temporaries, TType bit-field parts, PIC-relative vtable addresses -------------------------------
def by_def(w):
    return [(ln, y.rhs_of(w.v, ln)) for ln in w.deflines]
SKEL = {   # (var, def line text prefix) -> (name, tier, evidence)
 ('pTVar3', 'pTVar3 = yyvs;'): ('yyvsBase', 'CONFIRMED', 'bison skeleton: value stack base, re-pointed at the alloca copy when the stacks grow (yyvs = pTVar3 afterwards)'),
 ('pTVar7', 'pTVar7 = yyss;'): ('yyssBase', 'CONFIRMED', 'bison skeleton: state stack base, re-pointed at the alloca copy when the stacks grow (yyss = pTVar7 afterwards)'),
 ('iVar55', 'iVar55 = ((int)yyssp - (int)yyss >> 1) + 1;'): ('yysize', 'CONFIRMED', 'bison skeleton: yysize = yyssp - yyss + 1 (number of states on the stack), used to size the memcpy of both stacks'),
 ('iVar54', 'iVar54 = iVar55 * 2;'): ('yyssCopyBytes', 'CONFIRMED', 'bison skeleton: byte count of the state stack copied into the bigger alloca area (2 bytes per short)'),
 ('iVar55', 'iVar55 = yystateOrYylen * 2;'): ('yystateByteOffset', 'CONFIRMED', 'bison skeleton: byte offset of the current state into the short tables yypact/yydefact/yycheck/yytable (state * 2)'),
 ('uVar63', 'uVar63 = CONCAT44(yychar,scratchR4);'): ('yylexResult', 'INFERRED', 'r3:r4 pair holding the token yylex returns: (yychar, scratchR4); re-split into yychar / scratchR4 right after the call'),
 ('local_6c', 'local_6c = uVar57 * 2;'): ('yyruleByteOffset', 'CONFIRMED', 'bison skeleton: byte offset of rule yyn into the short tables yyr1/yyr2 (yyn * 2)'),
 ('uVar57', 'uVar57 = (uint)*(short *)(&_yydefact + iVar55);'): ('yyn', 'CONFIRMED', 'bison skeleton: yyn = yydefact[state] / yypact[state] + 1 / -yytable: the action number later switched on'),
}
for w in WS:
    if w.name or not w.deflines: continue
    first = y.lines[w.deflines[0]].strip()
    nm = SKEL.get((w.v, first))
    if nm: setname(w, *nm)
    # copies of yyvalNode: the register copy of the reduction's node value
    if all(r and r.strip() == 'yyvalNode' for ln, r in by_def(w)) and w.v == 'pTVar3':
        setname(w, 'resultNode', 'INFERRED', 'register copy of yyvalNode (interm.node, the $$ node of the rule): loaded at every action start, stored back to yyvalNode after the switch')
# local_X[0] = GetGlobalPoolAllocator(): the pool_allocator temporary passed by reference to a basic_string constructor
alloc_args = [w for w in WS if not w.name and w.v.startswith('local_') and w.deflines and all(r and r.strip() == 'GetGlobalPoolAllocator()' for ln, r in by_def(w))]
alloc_args.sort(key=lambda w: w.deflines[0])
for i, w in enumerate(alloc_args, 1):
    setname(w, 'allocatorArg%d' % i, 'INFERRED', 'array-element temporary holding GetGlobalPoolAllocator(), passed by address as the pool_allocator argument of a std::basic_string constructor/operator call')
# TType bit-field parts (qualifier 31-25, basic type 24-19, size 18-11: notes_ttype_layout.md)
for w in WS:
    if w.name or not w.deflines: continue
    rh = [r.strip() for ln, r in by_def(w) if r]
    if len(rh) != len(w.deflines): continue
    def all_match(pat): return all(re.search(pat, r) for r in rh)
    if all_match(r'& 0xfe000000$'):
        setname(w, 'qualifierBits', 'INFERRED', 'TType bit-field word masked with 0xfe000000: bits 31-25 are the qualifier (notes_ttype_layout.md)')
    elif all_match(r'>> 0x13 & 0x3f\) << 0x13$') or all_match(r'^\(\(uint\)\w+ & 0x3f\) << 0x13$'):
        setname(w, 'basicTypeBits', 'INFERRED', 'TType bit-field word: bits 24-19 are the basic type, kept in place (>> 0x13 & 0x3f) << 0x13 (notes_ttype_layout.md)')
    elif all_match(r'>> 0xb & 0xff\) << 0xb$') or all_match(r'^\(\(uint\)\w+ & 0xff\) << 0xb$'):
        setname(w, 'sizeBits', 'INFERRED', 'TType bit-field word: bits 18-11 are the nominal size, kept in place (>> 0xb & 0xff) << 0xb (notes_ttype_layout.md)')
# PIC base constant and addresses formed from it
PIC = {}
for w in WS:
    if w.deflines and all(r and re.fullmatch(r'\(unsigned char \*\)0xa7b8374c', r.strip()) for ln, r in by_def(w)):
        setname(w, 'picBase', 'CONFIRMED', 'constant 0xa7b8374c: the base the PIC-style code adds fixed offsets to (0xa7b8374c - 0x610c = 0xa7b7d640 is the TType vtable symbol address)'); PIC[w] = 0xa7b8374c
for w in WS:
    if w.name or not w.deflines: continue
    adds = set()
    for ln, r in by_def(w):
        m = r and re.fullmatch(r'(?:\(unsigned char \*\))?\(?(\w+) \+ (-?0x[0-9a-f]+|-?\d+)\)?', r.strip())
        if m and m.group(1) == 'local_5c':
            adds.add(0xa7b8374c + int(m.group(2), 0))
        else: adds = None; break
    if adds and len(adds) == 1:
        a = adds.pop(); s = vt.byaddr.get(a - 8)
        if s and s.startswith('__ZTV'):
            cls = r1.vt_cls(s)
            setname(w, (cls[1:2].lower() + cls[2:] if cls.startswith('T') and cls[1:2].isupper() else cls[0].lower() + cls[1:]) + 'Vtable', 'CONFIRMED', 'picBase %#x + %d = %#x: the address of the %s vtable symbol + 8 (vptr value stored into new %s objects)' % (0xa7b8374c, a - 0xa7b8374c, a, s, cls))



# ---- pass 4 (batch 2): symbol table pointer, c_str data pointers, loop counters ----------------------------------------------------------------------
for w in WS:
    if w.name or not w.deflines: continue
    rh = [r.strip() for ln, r in by_def(w) if r]
    if len(rh) != len(w.deflines): continue
    # TParseContext layout: +0 TIntermediate &, +4 TSymbolTable &  (the vector begin/end of its level table at +0/+4 is sized with >> 2, +0xc is the unique id counter)
    if all(re.fullmatch(r'\*\(\w[\w ]*\*+\)\(\(int\)parseContext \+ 4\)', r) for r in rh):
        setname(w, 'symbolTable', 'INFERRED', 'TParseContext+4: the TSymbolTable (3Dlabs TParseContext { TIntermediate &intermediate; TSymbolTable &symbolTable; ... }): its +0/+4 vector of levels is sized with (end - begin) >> 2 and +0xc (nextId) is incremented to make unique ids')
        continue
    # std::string::c_str(): S+4 is the data pointer _M_p; the NUL terminator is stored at data[length] with length at data - 0xc
    if all(re.fullmatch(r'\*\(int \*\)\((\w+) \+ 4\)', r) for r in rh):
        v = w.v
        if any(re.search(r'\(\*\(int \*\)\(%s \+ -0xc\) \+ \(int\)%s\)|\(int\)%s \+ \*\(int \*\)\(%s \+ -0xc\)|\(%s \+ \*\(int \*\)\(%s \+ -0xc\)\)' % ((v,) * 6), y.lines[l]) or ('%s + -0xc' % v) in y.lines[l] for l in w.lines):
            setname(w, 'stringData', 'INFERRED', 'std::string data pointer (_M_p at +4 of the pool basic_string object); the code stores a NUL at data[length] (length at data - 0xc): the c_str() idiom')
            continue
    # loop counters: defined as 0 and v + 1, used in a < comparison
    if set(rh) <= {'0', '%s + 1' % w.v} and len(rh) >= 2 and '0' in rh and ('%s + 1' % w.v) in rh:
        setname(w, 'loopIndex', 'INFERRED', 'counter initialised to 0 and stepped by 1 (for-loop header)')

# ---- pass 5 (batch 2): TType word updates, pool-allocated strings / TType copies --------------------------------------------------------------------
for w in WS:
    if w.name or not w.deflines: continue
    rh = [r.strip() for ln, r in by_def(w) if r]
    if len(rh) != len(w.deflines): continue
    # `qualifier << 0x19`: the qualifier moved into bits 31-25 of the TType word
    if all(re.search(r'<< 0x19$', r) for r in rh):
        setname(w, 'qualifierBits', 'INFERRED', 'qualifier value shifted left by 0x19: bits 31-25 of the TType bit-field word are the qualifier (notes_ttype_layout.md)'); continue
    # the old TType word, merged back with its low bits: ... | X & 0x1ffffff / & 0x7ffff / & 0x1ff
    if all(re.fullmatch(r'(\*\(uint \*\)\(\w+ \+ 0x[0-9a-f]+\)|\w+\[0xc\]|\*\(unsigned char \*\*\)\(\w+ \+ 0x[0-9a-f]+\))', r) for r in rh):
        uses = [l for l in w.lines if l not in w.deflines]
        if uses and all(re.search(r'(?<![\w])%s\)? & 0x(1ffffff|7ffff|7ff|1ff|9ff)\b' % re.escape(w.v), y.lines[l]) for l in uses):
            setname(w, 'oldTypeWord', 'INFERRED', 'TType bit-field word read before it is rewritten: the preserved low bits are kept with & 0x1ffffff / & 0x7ffff (qualifier / basic type / size fields are replaced)'); continue
# allocations: the object is identified by what is constructed in it
for w in WS:
    if w.name or not w.deflines: continue
    sz = None
    for ln, r in by_def(w):
        m = r and re.search(r'TPoolAllocator__allocate\(poolAllocator,(0x[0-9a-f]+|\d+)\)', r)
        if m: sz = int(m.group(1), 0)
    if sz is None or len(w.deflines) != 1: continue
    body = ' '.join(y.lines[l] for l in w.lines)
    if sz == 8 and re.search(r'__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1E\w*\(\(?(?:unsigned char \*\))?%s\b' % re.escape(w.v), body):
        setname(w, 'newString', 'INFERRED', 'pool allocation of 8 bytes (std::basic_string with pool_allocator is {allocator, _M_p}) on which the basic_string constructor C1 is run')
    elif sz == 0x28 and re.search(r'\(\*\*\(code \*\*\)\(\*\*\(int \*\*\)\(yyvsp(?: \+ -?0x[0-9a-f]+)?\) \+ 0x38\)\)\(%s,' % re.escape(w.v), body):
        setname(w, 'newType', 'INFERRED', 'pool allocation of 0x28 bytes (sizeof TType, as at every vtable-resolved TType allocation) filled by TIntermTyped::getType (vtable +0x38, hidden return pointer = this variable): a copy of the node type')
