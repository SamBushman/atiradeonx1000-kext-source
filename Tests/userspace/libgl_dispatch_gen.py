#!/usr/bin/env python3
"""libgl_dispatch_gen.py N > thunks.s - N dispatch thunks for libgl_dispatch_test.c: thunk i = `li r12,i; b _dsp_record` (8 bytes), and the recording routine."""
import sys
n = int(sys.argv[1]) if len(sys.argv) > 1 else 4096
print('.text\n.globl _dsp_thunks\n.align 2\n_dsp_thunks:')
for i in range(n): print('\tli r12,%d\n\tb _dsp_record' % i)
print('''.globl _dsp_clear
.align 2
_dsp_clear:
\tli r0,0\n\tstw r0,-8(r1)\n\tstw r0,-4(r1)\n\tlfd f0,-8(r1)
'''+''.join('\tfmr f%d,f0\n' % k for k in range(1, 14))+'''\tli r3,0\n\tli r4,0\n\tli r5,0\n\tli r6,0\n\tli r7,0\n\tli r8,0\n\tli r9,0\n\tli r10,0
\tblr
.globl _dsp_record
.align 2
_dsp_record:
\tlis r2,ha16(_dsp_pos)
\tlwz r11,lo16(_dsp_pos)(r2)
\tstw r12,0(r11)
\tstw r3,4(r11)\n\tstw r4,8(r11)\n\tstw r5,12(r11)\n\tstw r6,16(r11)\n\tstw r7,20(r11)\n\tstw r8,24(r11)\n\tstw r9,28(r11)\n\tstw r10,32(r11)''')
for k in range(13): print('\tstfd f%d,%d(r11)' % (k + 1, 40 + 8 * k))
for k in range(24): print('\tlwz r0,%d(r1)\n\tstw r0,%d(r11)' % (0x38 + 4 * k, 144 + 4 * k))
print('''\taddi r11,r11,240
\tstw r11,lo16(_dsp_pos)(r2)
\tli r3,0x5a5a
\tblr''')
