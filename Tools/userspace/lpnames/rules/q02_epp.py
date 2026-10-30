import re, os, sys
sys.path.insert(0, os.path.join(os.getcwd(), 'Tools/userspace'))
import find_webs as F
EVIDENCE = 'extvsPrepareHardwareProgram register-slot allocation macro: scans the program state slot array (programState+0x54, 0x28-byte slots, count at +0x58, in-use byte at +0x10) for 1 (scalar/vector) or 4 (matrix) free slots, growing the array by 0x10 slots through the ctx allocator when none is free'
VARS = ['in_r8', 'in_r7']
def whole(var): return None
def live(var, lines):
    return any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), F.CURRENT[x]) for x in lines)
def name(var, k, defs, lines, ctx):
    if not live(var, lines): return None
    ds = sorted(set(d.strip().rstrip(';').strip() for d in defs))
    v = re.escape(var)
    inc = lambda s: set(ds) <= {'0', '%s + %s' % (var, s)} and ('%s + %s' % (var, s)) in ds
    if inc('0x28'): return 'slotScanOffset'
    if set(ds) <= {'4', '%s + -1' % var} and '%s + -1' % var in ds: return 'rowsLeft'
    if set(ds) <= {'8', '%s + -1' % var} and '%s + -1' % var in ds: return 'unitsLeft'
    if inc('1'):
        return 'slotScanIndex' if var.startswith('uVar') and var != 'uVar14' else 'rowIndex'
    if ds and all(re.match(r'^\*\(int \*\)\(uVar23 \+ 0x58\)$', d) for d in ds): return 'slotCount'
    if ds and all(re.match(r'^\*\(int \*\)\(uVar23 \+ 0x54\) \+ \w+$|^\w+ \+ \*\(int \*\)\(uVar23 \+ 0x54\)$', d) for d in ds): return 'slotEntry'
    if ds and all(re.match(r'^\w+ \* 0x28$', d) for d in ds): return 'slotOffset'
    if ds and all(d == 'param_2[8]' for d in ds): return 'symbolRecords'
    if ds and all(d == 'param_2[6]' for d in ds): return 'instrRecords'
    return None
