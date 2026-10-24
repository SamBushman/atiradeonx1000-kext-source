import re
EVIDENCE = 'EXT_vertex_shader instruction record (0x74 bytes): three 0x1c-byte source slots at +0x20/+0x3c/+0x58, each type, index, four swizzle selector words (X,Y,Z,W) at slot+8..+0x14 (notes_gld_functions_b.md)'
LOAD = re.compile(r'^\*\(undefined4 \*\)\((iVar13|iVar32) \+ (0x[0-9a-f]+|\d+)\)')
def off(s): return int(s, 16) if s.startswith('0x') else int(s)
def name(var, k, defs, lines, ctx):
    d = defs[0] if defs else ''
    if var == 'uVar9':
        m = LOAD.match(d)
        if m:
            o = off(m.group(2)); s = (o - 0x20) // 0x1c; c = (o - 0x20 - s * 0x1c - 8) // 4
            if 0 <= s <= 2 and 0 <= c <= 3:
                return '%sSrc%dSelector%s' % ('writer' if m.group(1) == 'iVar13' else 'candidate', s, 'XYZW'[c])
    flags = {'bVar33': (1, 'xIsOne'), 'bVar34': (1, 'yIsOne'), 'bVar35': (1, 'wIsOne'), 
             'bVar38': (1, 'yIsZero'), 'bVar39': (1, 'wIsZero')}
    if var in flags and k == flags[var][0]: return flags[var][1]
    if var == 'puVar17': return 'selectorBase'
    return None
