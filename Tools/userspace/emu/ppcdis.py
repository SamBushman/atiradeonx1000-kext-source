#!/usr/bin/env python3
"""ppcdis.py ADDR_HEX LEN  - disassemble LEN bytes of the STOCK image at virtual address ADDR (capstone, big-endian PPC32).
Image: $IMG, default <repo>/../tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin (set IMG=...libGLProgrammability.dylib etc. for the other images).
(Do not name a script dis.py: it shadows the stdlib module capstone imports.)"""
import os, sys, struct
here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(here, '..'))
import machoutil, capstone
img = os.environ.get('IMG') or os.path.join(here, '..', '..', '..', '..', 'tiger-hd-pull', 'ATIRadeonX1000GLDriver.bundle.bin')
m = machoutil.load(img)
a = int(sys.argv[1], 16); n = int(sys.argv[2], 0)
md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
data = m.read(a, n)
for o in range(0, len(data) - 3, 4):          # word by word: one undecodable word must not end the listing
    ins = list(md.disasm(data[o:o + 4], a + o))
    print('%x: %s' % (a + o, ('%s %s' % (ins[0].mnemonic, ins[0].op_str)) if ins else '.long 0x%08x' % struct.unpack('>I', data[o:o + 4])[0]))
