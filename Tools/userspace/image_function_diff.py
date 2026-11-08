#!/usr/bin/env python3
"""image_function_diff.py OLD_DIS NEW_DIS [--show N] - which functions differ between two builds of the same userspace image?

OLD_DIS / NEW_DIS are `otool -tV <image>` dumps. A rebuilt image whose data layout moved (a retyped global, one more symbol) differs in almost every byte, so a raw diff or cmp says
nothing. This tool pairs functions by label and compares the instruction sequence after masking
  * hex numbers of three or more digits and decimal numbers of four or more digits (addresses, large displacements, stub offsets),
  * every symbolic name in an operand other than a register (otool prints a displacement or immediate as a symbol name when the value equals a symbol address in that layout),
so what is listed is a change of mnemonic, register or small constant, i.e. a real code change. Used for #235: GLDriver ku233 -> fad22b1d differs in exactly _gldDestroyContext and
psnReportError; GA in _createTextureBuffer, _createOffscreenBuffer, _radeonCopy, _radeonCopyRegionBody, _radeonFill, _radeonHighlight; libGL, libGLProgrammability and VA are byte-identical.
Prints the differing function names and the first --show (default 4) differing instruction pairs of each."""
import re, sys, os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from width_audit import load_ours   # noqa: E402

NUM = re.compile(r'0x[0-9a-f]{3,}|[0-9]{4,}')
SYM = re.compile(r'\b(?!r\d+\b|cr\d\b|lr\b|ctr\b|xer\b)[A-Za-z_][A-Za-z_0-9.$]*')


def norm_ops(o):
    return SYM.sub('N', NUM.sub('N', o))


def main():
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    show = 4
    if '--show' in sys.argv:
        show = int(sys.argv[sys.argv.index('--show') + 1]); a.remove(sys.argv[sys.argv.index('--show') + 1])
    old = load_ours(a[0]); new = load_ours(a[1])
    only_old = [k for k in old if k not in new]; only_new = [k for k in new if k not in old]
    diff = [k for k in old if k in new and [(m, norm_ops(o)) for _, m, o in old[k]] != [(m, norm_ops(o)) for _, m, o in new[k]]]
    print('functions: old %d, new %d, only in old %d, only in new %d, instruction sequence differs in %d' % (len(old), len(new), len(only_old), len(only_new), len(diff)))
    for k in diff:
        print('  ' + k)
        n = 0
        for (_, m1, o1), (_, m2, o2) in zip(old[k], new[k]):
            if (m1, norm_ops(o1)) != (m2, norm_ops(o2)):
                print('      %s %s   ->   %s %s' % (m1, o1, m2, o2)); n += 1
                if n >= show: break
    for k in only_old[:20]: print('  only in old: ' + k)
    for k in only_new[:20]: print('  only in new: ' + k)


if __name__ == '__main__':
    main()
