"""Hand fixes for the few functions whose Ghidra text the mechanical rewrites cannot make compile. Each entry maps a function name to
f(raw, converted) -> final text; `raw` is Ghidra's (K&R-converted) text, `converted` is the mechanical result."""
import re

def _raw_with(subs):
    def f(raw, conv):
        t = raw
        for a, b in subs: t = t.replace(a, b)
        return t
    return f

def _conv_with(subs):
    def f(raw, conv):
        t = conv
        for a, b in subs: t = t.replace(a, b)
        return t
    return f


def _yyparse_fix(conv):
    ins = 'std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux'
    # first site: `if (pos == end) insert_aux(vec, pos, &value); else { if (pos != 0) { x = *(*(int *)(P[4] + 4) + I + 4) ...`: the value is at *(P[4] + 4) + I
    # (r5 = lwz 4(lwz 0x10(r24)) + r25); P (r24) and I (r25) are named differently on every decompile
    m = re.search(ins + r'\(\);\n\s*\}\n\s*else \{\n\s*if \((\w+) != \(undefined4 \*\)0x0\) \{\n\s*\w+ = \*\(undefined4 \*\)\(\*\(int \*\)\((\w+)\[4\] \+ 4\) \+ (\w+) \+ 4\);', conv)
    assert m, 'yyparse first insert_aux site not found'
    pos, P, I = m.group(1), m.group(2), m.group(3)
    conv = conv.replace(m.group(0), m.group(0).replace(ins + '();', ins + '(local_870,%s,*(int *)(%s[4] + 4) + %s);' % (pos, P, I), 1), 1)
    # second site: vector = local_870, position = *(local_870 + 8) (named per decompile), value = &P[4]
    conv, n = re.subn(r'(local_870 = \w+;\s*(\w+) = \*\([\w ]+\*\*\)\(local_870 \+ 8\);\s*if \(\2 == [^\n]*\n\s*)' + ins + r'\(\);',
                  lambda m2: m2.group(1) + ins + '(local_870,%s,%s + 4);' % (m2.group(2), P), conv)
    assert n == 1, 'yyparse second insert_aux site not found'
    return conv


PATCHES = {
    # vector<TIntermNode*>::erase(&result, this, position) and ::_M_insert_aux(this, pos, &value): the third argument is a register still holding a value the
    # decompiler used elsewhere (erase: r5 = the position just stored through param_5; insert_aux: r5 = *(iVar3 + 4), the element the else branch copies)
    '__ZN13TIntermediate15removeChildNodeER7TVectorIP11TIntermNodeER5TTypeRiRN9__gnu_cxx17__normal_iteratorIPS2_St6vectorIS2_14pool_allocatorIS2_EEEEP16TIntermAggregate': _conv_with([('TIntermNode_____erase(&local_50,param_2);', 'TIntermNode_____erase(&local_50,param_2,*(undefined4 *)param_5);')]),
    '__ZN13TIntermediate15removeChildNodeEP12TIntermTypedP5TTypeP16TIntermAggregate': _conv_with([('TIntermNode______M_insert_aux(pTVar5,puVar1);', 'TIntermNode______M_insert_aux(pTVar5,puVar1,*(int *)(iVar3 + 4));')]),
    # the case values 4 and 5 of a switch on a pointer-typed selector: Ghidra printed them as the (empty) strings at those addresses; the code range-checks the selector against 5
    'FUN_000cea6c': lambda raw, conv: conv.replace('case "":', 'case 4:', 1).replace('case "":', 'case 5:', 1),
    # Ghidra fitted the Mach-O `dylib_command` type onto a constant address in the image header: this is the word at 0x7f4 + 8 (dylib) + 4 (timestamp)
    'FUN_0007c760': _conv_with([('&(*(GhidraMachOCommand *)0x000007f4).dylib.timestamp', '(unsigned int *)0x800')]),
    # GLDriver: calls Ghidra printed without arguments although the registers still hold the caller's values (read from the machine code at each `bl`)
    'FUN_00092570': _conv_with([('(((int (*)())FUN_00092350)(), ', '(((int (*)())FUN_00092350)(param_1), ')]),
    'FUN_000934f0': _conv_with([('(FUN_00092350(), ', '(FUN_00092350(param_1), ')]),
    'FUN_00168468': _conv_with([('((int (*)())FUN_00164df4)(), iVar4 == 0)) goto LAB_00168b48;', '((int (*)())FUN_00164df4)(piVar3), iVar4 == 0)) goto LAB_00168b48;')]),
    'FUN_0014700c': _conv_with([('((int (*)())FUN_00146edc)()', '((int (*)())FUN_00146edc)(param_1,param_2)')]),
    'FUN_00135334': _conv_with([('((int (*)())FUN_00134ba4)()', '((int (*)())FUN_00134ba4)(param_1,param_2,param_3)')]),
    # Calls Ghidra printed without arguments: the callee is an import whose demangled signature takes struct/iterator objects by value, so the decompiler
    # left every argument out. The arguments below are the registers at the call (r3..r8) read from the machine code.
    'yyparse': lambda raw, conv: _yyparse_fix(conv),
    # `s + t` on pool-allocator strings: append = replace(end(), end(), s, s + strlen(s)). The decompiler passed the pool allocator (uVar6) as the object of the
    # two replace calls; the machine code (`or r3,r27,r27` before each) passes the string being built, param_1
    '__ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_EPKS4_RKS7_': _conv_with([
        ('_SC_St18input_iterator_tag)(uVar6,psVar7 + uVar4,', '_SC_St18input_iterator_tag)(param_1,psVar7 + uVar4,'),
        ('iteratorIPcS3_EESB_T_SC_)(uVar6,psVar7 + uVar4,', 'iteratorIPcS3_EESB_T_SC_)(param_1,psVar7 + uVar4,')]),
    # 4-byte constructor aliases (`b <C4 ctor>`): the object and the constructor's own arguments are passed through untouched
    '__ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE': _conv_with([
        ('int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE()\n{', 'int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPcSsEEEET_S4_RKSaIcE(this, param_2, param_3, param_4)\n  void *this;\n  undefined4 param_2;\n  undefined4 param_3;\n  unsigned char * param_4;\n{'),
        ('SsEEEET_S4_RKSaIcE)();', 'SsEEEET_S4_RKSaIcE)(this,param_2,param_3,param_4);')]),
    '__ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE': _conv_with([
        ('int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE()\n{', 'int __ZNSsC2IN9__gnu_cxx17__normal_iteratorIPKcSsEEEET_S5_RKSaIcE(this, param_2, param_3, param_4)\n  void *this;\n  undefined4 param_2;\n  undefined4 param_3;\n  unsigned char * param_4;\n{'),
        ('SsEEEET_S5_RKSaIcE)();', 'SsEEEET_S5_RKSaIcE)(this,param_2,param_3,param_4);')]),
    '_RegisterCanMerge': _conv_with([('((int (*)())_RegisterIsMergeable)()', '((int (*)())_RegisterIsMergeable)(param_1)')]),
    # a computed call whose base Ghidra printed as a function name: the sum is an address, call through it
    'case_7f8f8': _conv_with([('(*(FUN_00001b34 + *(int *)(FUN_00001b34 + (iVar21 - 0x87d5U) * 4 + unaff_r31) + unaff_r31))();', '((int (*)())((unsigned char *)FUN_00001b34 + *(int *)((unsigned char *)FUN_00001b34 + (iVar21 - 0x87d5U) * 4 + unaff_r31) + unaff_r31))();')]),
    # the handler argument is a function pointer Ghidra typed as a plain byte pointer
    '__cxxabiv1____terminate': _conv_with([('(*param_1)();', '((int (*)())param_1)();')]),
    '__cxxabiv1____unexpected': _conv_with([('(*param_1)();', '((int (*)())param_1)();')]),
    # `operator=` on a long templated class: the sanitizer keeps the `=`, so the call reads as an assignment to a variable (the call is lost)
    'TIntermAggregate__addToPragmaTable': lambda raw, conv: re.sub(r'\b(std___Rb_tree_\w+_operator)=\(', r'\1_(', conv),
    # __dyld_func_lookup's out-parameter is now a plain word (committed signature): call through it
    '___initialize_Cplusplus': _conv_with([('(*uStack_28)(', '((int (*)())uStack_28)('), ('uStack_28 != (code *)0x0', '(void *)uStack_28 != (void *)0')]),
    # a switch on a value the committed signature now types as a pointer / enum-like pointer: switch on its integer value
    '_DumpTokenStream': lambda raw, conv: re.sub(r'case \([\w ]+\*+\)(0x[0-9a-f]+|\d+):', r'case \1:', re.sub(r'switch\((pcVar1)\)', r'switch((int)\1)', conv)),
    'TParseContext__constructBuiltIn': lambda raw, conv: re.sub(r'case \([\w ]+\*+\)(0x[0-9a-f]+|\d+):', r'case \1:', re.sub(r'switch\((param_3)\)', r'switch((int)\1)', conv)),
    # SUB42 of a pointer argument: GBITS's (dead) float branch cannot type-check a pointer
    'FUN_000c6470': _conv_with([('SUB42(param_3,0)', 'SUB42((unsigned long)param_3,0)')]),
    # local_28 is a pointer to a record (indexed as local_28[0x26]); Ghidra declared it as a one-element array of undefined4
    'FUN_001984c6': _raw_with([('undefined4 local_28[1];', 'int *local_28;')]),
    # 128-bit register shift left by 32 bits (pslldq 4): bytes move up by four, low dword becomes zero
    'FUN_000b50a3': lambda raw, conv: re.sub(r'(auVar\d+) = (auVar\d+) << 0x20;', r'{ unsigned char t_[16]; _memset(t_, 0, 16); _memcpy(t_ + 4, \2, 12); _memcpy(\1, t_, 16); }', conv),
}

# functions whose text is complete except for stated, understood gaps (recorded in the ledger status column)
NOTES = {
    '_ShCompile': 'converted (four constant-selector switch `bctr` sites rewritten as direct `b` in the analysed copy so the decompiler follows them; see gs/PatchConstSwitch.java)',
}
