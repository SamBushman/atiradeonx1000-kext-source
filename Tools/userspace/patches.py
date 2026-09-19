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
    # local_28 is a pointer to a record (indexed as local_28[0x26]); Ghidra declared it as a one-element array of undefined4
    'FUN_001984c6': _raw_with([('undefined4 local_28[1];', 'int *local_28;')]),
    # 128-bit register shift left by 32 bits (pslldq 4): bytes move up by four, low dword becomes zero
    'FUN_000b50a3': lambda raw, conv: re.sub(r'(auVar\d+) = (auVar\d+) << 0x20;', r'{ unsigned char t_[16]; _memset(t_, 0, 16); _memcpy(t_ + 4, \2, 12); _memcpy(\1, t_, 16); }', conv),
}
