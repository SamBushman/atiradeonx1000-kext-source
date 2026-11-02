#!/usr/bin/env python3
"""fix_il_inst_blocks.py PART_006.c - the IL instruction records (ilInstA / ilInstB / ilInst) of the fragment-program translator are 9-word (0x24 byte) stack structs in the stock binary
(Opcode, Dst, DstMask, Src0..2, Swz0..2): the code memset()s / memcpy()s / hands them to fpilEmitInstruction as ONE block. The Ghidra-derived corpus declared the fields as separate locals,
so the compiler may lay them out in any order (the translated source token and swizzle of an instruction landed outside the block that was emitted: the emitted IL had 0 where the source operand
belongs, and the driver's own IL rewriter then hit its out-of-range-opcode _exit(0)). Replace the declarations by one real array per record and map the old field names onto it with macros."""
import re, sys
path = sys.argv[1]
L = open(path).read().split('\n')
heads = [i for i, l in enumerate(L) if re.match(r'/\* \w+ @ 0x', l)]
def rng(name):
    for k, i in enumerate(heads):
        if L[i].startswith('/* ' + name + ' @'): return i, (heads[k + 1] if k + 1 < len(heads) else len(L))
    raise SystemExit('no function ' + name)
W = lambda b, i, t: '(*(%s *)&%s_blk[%d])' % (t, b, i)
SPECS = {
 'fragmentTranslateTrig': [('ilInst', 9, {'ilInstOpcode': 'ilInst_blk[0]', 'ilInstDst': 'ilInst_blk[1]', 'ilInstDstMask': 'ilInst_blk[2]', 'ilInstSrc0': 'ilInst_blk[3]', 'ilInstSwz0': 'ilInst_blk[6]'})],
 'fragmentTranslateMod': [('ilInstA', 9, {'ilInstAOpcode': 'ilInstA_blk[0]', 'ilInstADst': 'ilInstA_blk[1]', 'ilInstADstMask': 'ilInstA_blk[2]', 'ilInstASrc': '(&ilInstA_blk[3])',
                          'ilInstASwz0': W('ilInstA', 6, 'undefined *'), 'ilInstASwz1': 'ilInstA_blk[7]', 'ilInstASwz2': 'ilInstA_blk[8]'})],
 'fragmentTranslateArithmetic': [('ilInstA', 16, {'ilInstAOpcode': 'ilInstA_blk[0]', 'ilInstADst': 'ilInstA_blk[1]', 'ilInstADstMask': 'ilInstA_blk[2]', 'ilInstASrc0': 'ilInstA_blk[3]',
                          'ilInstASrc1': '((undefined1 *)&ilInstA_blk[4])', 'ilInstASrc1Hi': '(*(short *)((char *)&ilInstA_blk[4] + 2))', 'ilInstASrc2': 'ilInstA_blk[5]',
                          'ilInstASwz0': 'ilInstA_blk[6]', 'ilInstASwz1': '((undefined1 *)&ilInstA_blk[7])'})],
 'fragmentInstructionToIL': [('ilInstA', 9, {'ilInstAOpcode': 'ilInstA_blk[0]', 'ilInstADst': 'ilInstA_blk[1]', 'ilInstADstMask': 'ilInstA_blk[2]', 'ilInstASrc': '(&ilInstA_blk[3])',
                          'ilInstASwz': '((undefined **)(ilInstA_blk + 6))'}),
                         ('ilInstB', 9, {'ilInstBOpcode': 'ilInstB_blk[0]', 'ilInstBDst': 'ilInstB_blk[1]', 'ilInstBDstMask': 'ilInstB_blk[2]', 'ilInstBSrc': '(&ilInstB_blk[3])',
                          'ilInstBSwz0': W('ilInstB', 6, 'undefined *'), 'ilInstBSwz12': '((undefined **)(ilInstB_blk + 7))'})],
 'fragmentProgramToIL': [('ilInstA', 16, {'ilInstAOpcode': 'ilInstA_blk[0]', 'ilInstADst': 'ilInstA_blk[1]', 'ilInstADstMask': 'ilInstA_blk[2]', 'ilInstASrc': '(&ilInstA_blk[3])',
                          'ilInstASwzWords': '((undefined **)(ilInstA_blk + 6))'})],
}
DECL = re.compile(r'^\s+[\w\s\*]+?\b(ilInst[AB]?(?:Opcode|Dst|DstMask|Src\d?(?:Hi)?|Swz\w*))\s*(?:\[\d+\])?;\s*$')
for fn, recs in SPECS.items():
    a, b = rng(fn)
    if any(L[i] and '_blk' in L[i] for i in range(a, b)): raise SystemExit(fn + ': already converted')
    for base, size, fields in recs:
        # declarations of this record's fields
        idx = [i for i in range(a, b) if L[i] is not None and DECL.match(L[i]) and DECL.match(L[i]).group(1) in fields]
        assert idx, (fn, base)
        first = idx[0]
        for i in idx[1:]: L[i] = None
        L[first] = '  undefined4 %s_blk[%d];   /* one real 0x24-byte IL instruction record (see Tools/userspace/fix_il_inst_blocks.py) */\n' % (base, size) + \
                   '\n'.join('#define %s %s' % kv for kv in fields.items())
    # undefine after the function's closing brace
    end = max(i for i in range(a, b) if L[i] is not None and L[i] == '}')
    L[end] = '}\n' + '\n'.join('#undef %s' % k for base, size, fields in recs for k in fields)
    # fields used before their declaration line do not occur (all in locals)
open(path, 'w').write('\n'.join(l for l in L if l is not None))
print('ok')
