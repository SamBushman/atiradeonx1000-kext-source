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

PATCHES = {
    # a computed call whose base Ghidra printed as a function name: the sum is an address, call through it
    'case_7f8f8': _conv_with([('(*(FUN_00001b34 + *(int *)(FUN_00001b34 + (iVar21 - 0x87d5U) * 4 + unaff_r31) + unaff_r31))();', '((int (*)())((unsigned char *)FUN_00001b34 + *(int *)((unsigned char *)FUN_00001b34 + (iVar21 - 0x87d5U) * 4 + unaff_r31) + unaff_r31))();')]),
    # the handler argument is a function pointer Ghidra typed as a plain byte pointer
    '__cxxabiv1____terminate': _conv_with([('(*param_1)();', '((int (*)())param_1)();')]),
    '__cxxabiv1____unexpected': _conv_with([('(*param_1)();', '((int (*)())param_1)();')]),
    # `operator=` on a long templated class: the sanitizer keeps the `=`, so the call reads as an assignment to a variable (the call is lost)
    'TIntermAggregate__addToPragmaTable': lambda raw, conv: re.sub(r'\b(std___Rb_tree_\w+_operator)=\(', r'\1_(', conv),
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
