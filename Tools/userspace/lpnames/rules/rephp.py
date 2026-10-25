import re
EVIDENCE = ('role read off the web definitions in extvsPrepareHardwareProgram: shader[6] = symbol records (0x74 bytes), shader[8] = symbol list entries (0x54 bytes), '
            'programState+0x54/+0x58 = array and count of the 0x28-byte hardware register slots (slot flag at +0x10)')
VARS = ['bVar2']
SLOTARR = r'\*\(int \*\)\(uVar23 \+ 0x54\)'
SLOTCNT = r'\*\(int \*\)\(uVar23 \+ 0x58\)'


def name(var, k, defs, lines, ctx):
    ds = [d.strip().rstrip(';') for d in defs]
    s = set(ds)
    if s <= {'true', 'false'} and s: return 'slotSearching'
    if s == {'param_2[6]'}: return 'shaderSymbols'
    if s == {'param_2[8]'}: return 'symbolList'
    if s == {'*(int *)(uVar23 + 0x58)'}: return 'slotCount'
    if s == {'*(int *)(uVar23 + 0x18)'}: return 'hwInstCount'
    if s == {'0', 'iVar%s + 0x28' % ''} : pass
    # loop cursors written as `X = a; X = X + step`
    if len(ds) == 2:
        a, b = ds
        if b == '%s + 0x28' % var and re.fullmatch(r'0|\w+ \* 0x28', a): return 'slotByteOffset'
        if b == '%s + 0x74' % var and a == '0': return 'symbolOffset'
        if b == '%s + 0x54' % var and a == '0': return 'listEntryOffset'
        if b == '%s + 1' % var and a == '0': return 'loopCounter'
        if b == '%s + -1' % var and re.fullmatch(r'4|8', a): return 'rowsLeft'
        if b == '%s + 4' % var: return 'matrixRowOffset'
    # slot / symbol addressing
    if len(ds) == 1:
        d = ds[0]
        if re.fullmatch(SLOTARR + r' \+ \w+|\w+ \+ ' + SLOTARR, d): return 'slotAddr'
        if re.fullmatch(r'\w+ \+ \w+', d) and 'slotAddr' == '': return None
        if re.fullmatch(r'\*\(int \*\)\(\w+ \+ 0x24\)', d): return 'symbolKind'
        if re.fullmatch(r'\w+ \* 0x74 \+ param_2\[6\]', d): return 'symbolRecord'
    if len(ds) == 2:
        a, b = ds
        if re.fullmatch(r'\*\(int \*\)\(\w+ \+ \w+ \+ 0x(?:24|40)\) \* 0x54', a): return 'listEntryOffset'
        if b == '%s + 0x54' % var: return 'listEntryOffset'
    return None
