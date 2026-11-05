#!/usr/bin/env python3
"""sim_chain_patch.py - issue #142: show what the two chain loops of the 0x12 branch of ATIR500DVDContext::process_command_buffer do to the REAL composite record
captured in captures/comp/g11/g11.tsv.mem, with the shipped behaviour (the loop re-reads entry word [1] AFTER overwriting it with the 0x80000000 filler, so the
offset is always 0) and with the fix (offset read first), then PM4-frames the patched stream. Shipped: the 0x1393 (RB3D_DSTCACHE_CTLSTAT) headers are destroyed and
66-dword bogus type-0 packets appear; fixed: the headers survive and the stream frames cleanly. Run from Tools/userspace/va_capture. The destination address/pitch are
representative values (the real ones come from the bound surface)."""
import sys
sys.path.insert(0,'.')
from decode_composite_record import snaps

def frame(words, start, end):
    """walk PM4 packets from start; return (list of (pos,hdr,len)), overrun?"""
    p=start; out=[]
    while p<end:
        h=words[p]; t=h>>30
        if t==2: n=1
        elif t==1: n=3
        else: n=((h>>16)&0x3fff)+2
        out.append((p,h,n))
        p+=n
    return out,p

def patch(words, rec_i, fixed):
    w=list(words)
    rec=w[rec_i:rec_i+16]
    dest_plane=0x00400000; dest_pitch=0x1e00            # representative values: real ones come from the surface record
    tiling=(0)|(0)<<0x11
    for off in (rec[6],rec[7]):
        b=rec_i+off
        cur=b+16
        link=w[cur]
        while link!=0:
            n1_orig=w[cur+1]
            w[cur]=0x80000000; w[cur+1]=0x80000000
            n1 = n1_orig if fixed else w[cur+1]          # stock re-reads cursor[1] AFTER the store -> 0x80000000
            tgt = cur + ((n1<<2)&0xffffffff)//4 + 2 if not fixed else cur+n1+2
            if not fixed: tgt = cur+2                    # (0x80000000<<2)==0 mod 2^32
            flag = w[tgt]
            addr = dest_plane + (dest_pitch if flag else 0)
            w[tgt] = addr & 0xffffffe0
            w[tgt+1] = (w[tgt+1] & 0x3ffe) | 0x1200000
            cur = cur+link+2
            link = w[cur]
    return w

path='captures/comp/g11/g11.tsv.mem'
for s in snaps(path):
    w=s['words']
    idx=[i for i,x in enumerate(w) if (x&0xffff0000)==0x12000000]
    for i in idx:
        rec=w[i:i+16]
        if rec[6]>len(w) or rec[7]>len(w): continue
        # region of the stream this record covers: from record header to end of second chain (+0x5d past second block)
        end=i+rec[7]+0x10+0x4d+2+1
        for name,fixed in (('STOCK (re-reads cursor[1] after store)',False),('FIXED (reads offset first)',True)):
            pw=patch(w,i,fixed)
            # the kernel turns the 14 header words into a NOP packet 0xc00c1000
            pw[i]=0xc00c1000
            pk,endp=frame(pw,i,end)
            bad=[(p,h,n) for p,h,n in pk if (h>>30)==0 and ((h>>16)&0x3fff)>0x40 or (h>>30)==1]
            print(f'--- {name}: packets={len(pk)} framing ends at {endp-i:#x} vs expected region end {end-i:#x} (overrun {endp-end} words)')
            for p,h,n in pk:
                if p>=i+rec[6]+16-0 and n>0x20: print(f'    oversized packet @+{p-i:#x} hdr={h:08x} len={n}')
            hits=[(p-i,h) for p,h,n in pk if h==0x1393]
            print('    DSTCACHE_CTLSTAT(0x1393) headers still intact in region:',len(hits))
        raise SystemExit
