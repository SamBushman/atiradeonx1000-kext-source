#!/usr/bin/env python3
"""pm4_walk.py - #214: walk the raw PM4 stream in a command-buffer dump (iokit_record map*/cb*.bin, big-endian words) and print
type-0 register writes / type-3 packets in order, so two cb dumps (wedge vs normal) can be diffed structurally.
usage: pm4_walk.py FILE [--start WORDIDX] [--end WORDIDX] [--draws-only]"""
import struct, sys, argparse
T3 = {0x10:'NOP?',0x13:'3D_DRAW_VBUF',0x28:'CNTL_BITBLT?',0x2d:'3D_DRAW_VBUF_2',0x2e:'3D_DRAW_IMMD_2',0x34:'3D_DRAW_INDX',0x35:'3D_DRAW_INDX_2',
      0x36:'3D_DRAW_INDX_2(imm?)',0x37:'3D_DRAW_INDX_2',0x3c:'WAIT_FOR_IDLE?',0x39:'LOAD_VBPNTR',0x3e:'3D_CLEAR_ZMASK',0x25:'NEXT_CHAR',0x46:'EVENT_WRITE',
      0x1d:'CP_INDIRECT?',0x21:'SET_SCISSORS?',0x10:'PACKET3_0x10',0x00:'NOP'}
def rn(reg):
    k = {0x1da0:'VPORT_XSCALE?',0x4e04:'RB3D_BLENDCNTL',0x4e10:'RB3D_COLORPITCH?',0x4f00:'ZB_CNTL',0x4f14:'ZB_ZSTENCILCNTL?',0x4200:'GA_POINT_S0',
         0x20c4:'VAP_ARRAY_PTR',0x2090:'VAP_CNTL_STATUS',0x2180:'VAP_PVS_CODE?',0x1150:'TX_OFFSET0',0x4540:'TX_OFFSET0?'}
    return k.get(reg, '0x%04x' % reg)
def main():
    ap = argparse.ArgumentParser(); ap.add_argument('f'); ap.add_argument('--start', type=lambda x:int(x,0), default=8); ap.add_argument('--end', type=lambda x:int(x,0), default=0)
    ap.add_argument('--draws-only', action='store_true'); a = ap.parse_args()
    d = open(a.f,'rb').read(); w = struct.unpack('>%dI'%(len(d)//4), d)
    last = max((i for i,x in enumerate(w) if x), default=0)
    end = a.end or last+1
    i = a.start
    while i < end:
        h = w[i]; t = h >> 30
        if t == 0:
            n = ((h >> 16) & 0x3fff) + 1; reg = (h & 0x7fff) << 2; one = (h >> 15) & 1
            if not a.draws_only:
                body = ' '.join('%x' % x for x in w[i+1:i+1+min(n,12)]) + (' ...' if n > 12 else '')
                print('%05x T0 %s reg=%s n=%d%s : %s' % (i*4, 'ONE' if one else '   ', rn(reg), n, '', body))
            i += 1 + n
        elif t == 3:
            n = ((h >> 16) & 0x3fff) + 1; op = (h >> 8) & 0xff
            print('%05x T3 op=0x%02x %-18s n=%d%s' % (i*4, op, T3.get(op,'?'), n, ' <-- DRAW' if op in (0x36,0x35,0x34,0x2d,0x2e,0x13,0x37) else ''))
            if not a.draws_only and n <= 16: print('       ' + ' '.join('%x' % x for x in w[i+1:i+1+n]))
            i += 1 + n
        else:
            print('%05x ?? T%d %08x' % (i*4, t, h)); i += 1
if __name__ == '__main__': main()
